mod postprocess;
mod preprocess;

use std::{
    borrow::Cow,
    ffi::OsString,
    fmt::Display,
    fs::{self, File},
    io::Write,
    path::{Path, PathBuf},
    process::{exit, Command},
    str::FromStr,
};

use anyhow::Result;
use argp::{EarlyExit, FromArgs, HelpStyle};
use encoding_rs::EUC_JP;
use enum_map::{Enum, EnumMap};
use temp_dir::TempDir;

use postprocess::fixup_objfile;
use preprocess::parse_source;

#[derive(Copy, Clone, Eq, PartialEq, Debug, Enum)]
enum OutputSection {
    Text,
    Data,
    Rodata,
    Bss,
}

impl OutputSection {
    fn as_str(&self) -> &'static str {
        match self {
            OutputSection::Text => ".text",
            OutputSection::Data => ".data",
            OutputSection::Rodata => ".rodata",
            OutputSection::Bss => ".bss",
        }
    }
}

impl Display for OutputSection {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.as_str())
    }
}

#[derive(Clone, Debug)]
struct Function {
    text_glabels: Vec<String>,
    asm_conts: Vec<String>,
    late_rodata_dummy_bytes: Vec<[u8; 4]>,
    jtbl_rodata_size: usize,
    late_rodata_asm_conts: Vec<String>,
    fn_desc: String,
    data: EnumMap<OutputSection, (Option<String>, usize)>,
}

#[derive(Clone, Copy, Debug)]
enum Encoding {
    Latin1,
    Custom(&'static encoding_rs::Encoding),
}

impl Encoding {
    fn encode<'a>(&self, s: &'a str) -> Result<Cow<'a, [u8]>> {
        match self {
            Encoding::Latin1 => {
                if encoding_rs::mem::is_str_latin1(s) {
                    return Ok(encoding_rs::mem::encode_latin1_lossy(s));
                }
            }
            Encoding::Custom(enc) => {
                if *enc == EUC_JP {
                    let s = s.replace("〜", "～");
                    let (ret, _, failed) = enc.encode(&s);
                    if !failed {
                        return Ok(Cow::Owned(ret.into_owned()));
                    }
                } else {
                    let (ret, _, failed) = enc.encode(s);
                    if !failed {
                        return Ok(ret);
                    }
                }
            }
        }
        Err(anyhow::anyhow!("Failed to encode string: {}", s))
    }

    fn decode<'a>(&self, bytes: &'a [u8]) -> Result<Cow<'a, str>> {
        match self {
            Encoding::Latin1 => Ok(encoding_rs::mem::decode_latin1(bytes)),
            Encoding::Custom(enc) => {
                let (ret, _, failed) = enc.decode(bytes);
                if !failed {
                    Ok(ret)
                } else {
                    Err(anyhow::anyhow!("Failed to decode string: {}", ret))
                }
            }
        }
    }
}

impl FromStr for Encoding {
    type Err = String;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        if s == "latin1" {
            Ok(Encoding::Latin1)
        } else {
            match encoding_rs::Encoding::for_label(s.as_bytes()) {
                Some(enc) => Ok(Encoding::Custom(enc)),
                None => Err(format!("Unsupported encoding: {}", s)),
            }
        }
    }
}

#[derive(Copy, Clone, Debug, PartialEq)]
enum ConvertStatics {
    No,
    Local,
    Global,
    GlobalWithFilename,
}

impl FromStr for ConvertStatics {
    type Err = String;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        Ok(match s {
            "no" => ConvertStatics::No,
            "local" => ConvertStatics::Local,
            "global" => ConvertStatics::Global,
            "global-with-filename" => ConvertStatics::GlobalWithFilename,
            _ => return Err("invalid value for symbol visibility".into()),
        })
    }
}

#[derive(Clone, Copy, Debug, PartialEq)]
enum OptLevel {
    O0,
    O1,
    O2,
    G,
    G3,
}

/// Pre-process .c files and post-process .o files to enable embedding MIPS assembly into IDO-compiled C.
#[derive(FromArgs)]
struct AsmProcArgs {
    /// Path to a file containing a prelude to the assembly file (with .set and .macro directives, e.g.)
    #[argp(option, arg_name = "FILE")]
    asm_prelude: Option<PathBuf>,

    /// Input encoding (default: latin1)
    #[argp(
        option,
        default = "Encoding::Latin1",
        from_str_fn(FromStr::from_str),
        arg_name = "ENCODING"
    )]
    input_enc: Encoding,

    /// Output encoding (default: latin1)
    #[argp(
        option,
        default = "Encoding::Latin1",
        from_str_fn(FromStr::from_str),
        arg_name = "ENCODING"
    )]
    output_enc: Encoding,

    /// Drop mdebug and gptab sections
    #[argp(switch)]
    drop_mdebug_gptab: bool,

    /// Change symbol visibility for static variables. Mode must be one of:
    /// no, local, global, global-with-filename (default: local)
    #[argp(
        option,
        default = "ConvertStatics::Local",
        from_str_fn(FromStr::from_str),
        arg_name = "MODE"
    )]
    convert_statics: ConvertStatics,

    /// Force processing of files without GLOBAL_ASM blocks
    #[argp(switch)]
    force: bool,

    /// Emit temporary files to this directory
    #[argp(option, arg_name = "DIR")]
    keep_preprocessed: Option<PathBuf>,

    /// Replace floats with their encoded hexadecimal representation in CutsceneData data
    #[argp(switch)]
    encode_cutscene_data_floats: bool,

    /// Don't generate a .d make dependency file
    #[argp(switch)]
    no_dep_file: bool,

    #[argp(positional, greedy)]
    rest: Vec<String>,
}

struct CompileOpts {
    opt: OptLevel,
    framepointer: bool,
    mips1: bool,
    kpic: bool,
    pascal: bool,
}

fn extract_compiler_input_output(
    compile_args: &[String],
) -> Result<(PathBuf, PathBuf, Vec<String>), &'static str> {
    let mut compile_args: Vec<String> = compile_args.to_vec();
    let out_ind = compile_args
        .iter()
        .position(|arg| arg == "-o")
        .ok_or("missing -o argument")?;
    let out_filename = compile_args
        .get(out_ind + 1)
        .ok_or("missing argument after -o")?
        .clone();
    compile_args.remove(out_ind + 1);
    compile_args.remove(out_ind);

    let in_file_str = compile_args
        .last()
        .ok_or("missing input file argument")?
        .clone();
    compile_args.pop();

    let out_file: PathBuf = out_filename.into();
    let in_file: PathBuf = in_file_str.into();

    Ok((in_file, out_file, compile_args))
}

fn parse_compile_args(
    compile_args: &[String],
    in_file: &Path,
) -> Result<CompileOpts, &'static str> {
    let mut opt_flags = vec![];
    for x in compile_args {
        opt_flags.push(match x.as_str() {
            "-g" => OptLevel::G,
            "-O0" => OptLevel::O0,
            "-O1" => OptLevel::O1,
            "-O2" => OptLevel::O2,
            _ => continue,
        });
    }

    if opt_flags.len() != 1 {
        return Err("exactly one of -g/-O0/-O1/-O2 must be passed");
    }
    let mut opt = opt_flags[0];

    let mips1 = !compile_args.contains(&"-mips2".to_string());
    let framepointer = compile_args.contains(&"-framepointer".to_string());
    let kpic = compile_args.contains(&"-KPIC".to_string());
    if compile_args.contains(&"-g3".to_string()) {
        if opt != OptLevel::O2 {
            return Err("-g3 is only supported together with -O2");
        }
        opt = OptLevel::G3;
    }

    if mips1 && (!matches!(opt, OptLevel::O1 | OptLevel::O2) || framepointer) {
        return Err("-mips1 is only supported together with -O1 or -O2");
    }

    let in_file_str = in_file.to_string_lossy();
    let pascal = in_file_str.ends_with(".p")
        || in_file_str.ends_with(".pas")
        || in_file_str.ends_with(".pp");

    if pascal && !matches!(opt, OptLevel::O1 | OptLevel::O2 | OptLevel::G3) {
        return Err("Pascal is only supported together with -O1, -O2 or -O2 -g3");
    }

    Ok(CompileOpts {
        opt,
        framepointer,
        mips1,
        kpic,
        pascal,
    })
}

fn parse_rest(rest: &[String]) -> Option<(&[String], &[String], &[String])> {
    let mut iter = rest.splitn(3, |x| *x == "--");
    let compiler = iter.next()?;
    let assembler = iter.next()?;
    let compile_args = iter.next()?;
    assert!(iter.next().is_none());
    Some((compiler, assembler, compile_args))
}

struct ParsedArgs {
    args: AsmProcArgs,
    compiler: Vec<String>,
    assembler: Vec<String>,
    compile_args: Vec<String>,
    in_file: PathBuf,
    out_file: PathBuf,
    opts: CompileOpts,
}

/// Parse command line arguments while allowing --a=b syntax.
///
/// This provides backward compatibility with Python argparse.
fn from_args_allow_eq(progname: &[&str], args: &[OsString]) -> Result<AsmProcArgs, EarlyExit> {
    let base_res = AsmProcArgs::from_args(progname, args);
    if base_res.is_ok() {
        return base_res;
    }

    // Try splitting up = chars successively, until we get a valid parse.
    // This ensures we don't impact the compiler/assembler parts.
    //
    // Technically this might end up splitting --a --b=c into --a --b c even
    // where --a is a flag that takes an argument --b=c, but this seems unlikely
    // with our use case.
    let mut i = 0;
    let mut args = args.to_vec();
    while i < args.len() {
        let arg = args[i].as_encoded_bytes();
        if arg.starts_with(b"--") {
            if let Some(eq) = arg.iter().position(|&x| x == b'=') {
                // SAFETY: splitting on ASCII still results in valid encoded bytes
                let before = unsafe { OsString::from_encoded_bytes_unchecked(arg[0..eq].into()) };
                let after = unsafe { OsString::from_encoded_bytes_unchecked(arg[eq + 1..].into()) };
                args.splice(i..i + 1, [before, after]);
                let new_res = AsmProcArgs::from_args(progname, &args);
                if new_res.is_ok() {
                    return new_res;
                }
                i += 1;
            }
        }
        i += 1;
    }

    base_res
}

fn parse_args_or_exit() -> ParsedArgs {
    let argv: Vec<_> = std::env::args_os().collect();
    let help_style = HelpStyle {
        short_usage: true,
        ..HelpStyle::default()
    };
    let progname = argv[0].to_string_lossy();

    let args = from_args_allow_eq(&[&progname], &argv[1..]).unwrap_or_else(|early_exit| {
        exit(match early_exit {
            EarlyExit::Help(help) => {
                println!(
                    "{}",
                    help.generate(&help_style).replace(
                        "[rest...]",
                        "<compiler...> -- <assembler...> -- <compiler flags...>"
                    )
                );
                0
            }
            EarlyExit::Err(err) => {
                eprintln!("{}\nRun {} --help for more information.", err, progname);
                1
            }
        })
    });

    let Some((compiler, assembler, compile_args)) = parse_rest(&args.rest) else {
        eprintln!(
            "Usage: {} [options] <compiler...> -- <assembler...> -- <compiler flags...>",
            progname
        );
        eprintln!("Run {} --help for more information.", progname);
        exit(1);
    };

    let (in_file, out_file, compile_args) = extract_compiler_input_output(compile_args)
        .unwrap_or_else(|err| {
            eprintln!("Failed to parse compiler flags: {}", err);
            exit(1);
        });

    let opts = parse_compile_args(&compile_args, &in_file).unwrap_or_else(|err| {
        eprintln!("Unsupported compiler flags: {}", err);
        exit(1);
    });

    let compiler = compiler.into();
    let assembler = assembler.into();

    ParsedArgs {
        args,
        compiler,
        assembler,
        compile_args,
        in_file,
        out_file,
        opts,
    }
}

fn main() -> Result<()> {
    let ParsedArgs {
        args,
        compiler,
        assembler,
        compile_args,
        in_file,
        out_file,
        opts,
    } = parse_args_or_exit();

    let assembler_sh = assembler
        .iter()
        .map(|s| shlex::try_quote(s).unwrap().into_owned())
        .collect::<Vec<String>>()
        .join(" ");

    let in_dir = fs::canonicalize(in_file.parent().unwrap().join("."))?;

    let temp_dir = TempDir::with_prefix("asm_processor")?;
    let preprocessed_filename = format!(
        "preprocessed_{}",
        in_file.file_name().unwrap().to_str().unwrap()
    );
    let preprocessed_path = temp_dir.path().join(&preprocessed_filename);
    let mut preprocessed_file = File::create(&preprocessed_path)?;

    let res = parse_source(&in_file, &args, &opts, true)?;
    preprocessed_file.write_all(&res.output)?;

    if let Some(keep_output_dir) = &args.keep_preprocessed {
        fs::create_dir_all(keep_output_dir)?;
        fs::copy(
            &preprocessed_path,
            keep_output_dir.join(&preprocessed_filename),
        )?;
    }

    // Run compiler
    let mut compile_command = Command::new(&compiler[0]);
    compile_command
        .args(&compile_args)
        .arg("-I")
        .arg(in_dir)
        .arg("-o")
        .arg(&out_file)
        .arg(&preprocessed_path);

    match compile_command.status() {
        Ok(status) if status.success() => {}
        _ => {
            return Err(anyhow::anyhow!(
                "Failed to compile file {}. Command line:\n\n{:?}\n",
                in_file.display(),
                compile_command
            ));
        }
    }

    if !res.functions.is_empty() || args.force {
        let prelude_str;
        let asm_prelude = match &args.asm_prelude {
            Some(prelude) => {
                if let Ok(res) = fs::read_to_string(prelude) {
                    prelude_str = res;
                    &prelude_str
                } else {
                    return Err(anyhow::anyhow!("Failed to read asm prelude"));
                }
            }
            None => include_str!("../../prelude.inc"),
        };

        fixup_objfile(
            &out_file,
            &res.functions,
            asm_prelude,
            &assembler_sh,
            &args.output_enc,
            args.drop_mdebug_gptab,
            args.convert_statics,
        )?;
    }

    if !res.deps.is_empty() && !args.no_dep_file {
        let deps_file = out_file.with_extension("asmproc.d");
        let mut deps_file = File::create(&deps_file)?;

        writeln!(
            deps_file,
            "{}: {}",
            out_file.to_str().unwrap(),
            res.deps.join(" \\\n    ")
        )?;

        for dep in res.deps {
            writeln!(deps_file, "\n{dep}:")?;
        }
    }

    Ok(())
}

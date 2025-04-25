use std::{fs, io::Write, iter, path::Path, sync::OnceLock};

use anyhow::Result;
use enum_map::{Enum, EnumMap};
use regex_lite::Regex;

use crate::{AsmProcArgs, CompileOpts, Encoding, Function, OptLevel, OutputSection};

#[derive(Copy, Clone, Eq, PartialEq, Debug, Enum)]
enum InputSection {
    Text,
    Data,
    Rodata,
    LateRodata,
    Bss,
}

impl InputSection {
    fn from_str(name: &str) -> Option<InputSection> {
        match name {
            ".text" => Some(InputSection::Text),
            ".data" => Some(InputSection::Data),
            ".rodata" => Some(InputSection::Rodata),
            ".late_rodata" => Some(InputSection::LateRodata),
            ".bss" => Some(InputSection::Bss),
            _ => None,
        }
    }
}

#[derive(Clone, Debug)]
struct GlobalState {
    late_rodata_hex: u32,
    valuectr: usize,
    namectr: usize,
    min_instr_count: usize,
    skip_instr_count: usize,
    use_jtbl_for_rodata: bool,
    prelude_if_late_rodata: usize,
    mips1: bool,
    pascal: bool,
}

impl GlobalState {
    fn new(
        min_instr_count: usize,
        skip_instr_count: usize,
        use_jtbl_for_rodata: bool,
        prelude_if_late_rodata: usize,
        mips1: bool,
        pascal: bool,
    ) -> Self {
        Self {
            // A value that hopefully never appears as a 32-bit rodata constant (or we
            // miscompile late rodata). Increases by 1 in each step.
            late_rodata_hex: 0xE0123456,
            valuectr: 0,
            namectr: 0,
            min_instr_count,
            skip_instr_count,
            use_jtbl_for_rodata,
            prelude_if_late_rodata,
            mips1,
            pascal,
        }
    }

    fn next_late_rodata_hex(&mut self) -> [u8; 4] {
        let dummy_bytes = self.late_rodata_hex.to_be_bytes();
        if (self.late_rodata_hex & 0xffff) == 0 {
            // Avoid lui
            self.late_rodata_hex += 1;
        }
        self.late_rodata_hex += 1;
        dummy_bytes
    }

    fn make_name(&mut self, cat: &str) -> String {
        self.namectr += 1;
        format!("_asmpp_{}{}", cat, self.namectr)
    }

    fn func_prologue(&self, name: &str) -> String {
        if self.pascal {
            [
                &format!("procedure {}();", name),
                "type",
                " pi = ^integer;",
                " pf = ^single;",
                " pd = ^double;",
                "var",
                " vi: pi;",
                " vf: pf;",
                " vd: pd;",
                "begin",
                " vi := vi;",
                " vf := vf;",
                " vd := vd;",
            ]
            .join(" ")
        } else {
            format!("void {}(void) {{", name)
        }
    }

    fn func_epilogue(&self) -> String {
        if self.pascal {
            "end;".to_string()
        } else {
            '}'.to_string()
        }
    }

    fn pascal_assignment_float(&mut self, val: f32) -> String {
        self.valuectr += 1;
        let address = (8 * self.valuectr) & 0x7FFF;
        format!("vf := pf({}); vf^ := {:?};", address, val)
    }

    fn pascal_assignment_double(&mut self, val: f64) -> String {
        self.valuectr += 1;
        let address = (8 * self.valuectr) & 0x7FFF;
        format!("vd := pd({}); vd^ := {:?};", address, val)
    }

    fn pascal_assignment_int(&mut self, val: i32) -> String {
        self.valuectr += 1;
        let address = (8 * self.valuectr) & 0x7FFF;
        format!("vi := pi({}); vi^ := {};", address, val)
    }
}

#[derive(Clone, Debug)]
struct GlobalAsmBlock {
    fn_desc: String,
    cur_section: InputSection,
    asm_conts: Vec<String>,
    late_rodata_asm_conts: Vec<String>,
    late_rodata_alignment: usize,
    late_rodata_alignment_from_context: bool,
    text_glabels: Vec<String>,
    fn_section_sizes: EnumMap<InputSection, usize>,
    fn_ins_inds: Vec<(usize, usize)>,
    glued_line: String,
    num_lines: usize,
}

impl GlobalAsmBlock {
    fn new(fn_desc: String) -> Self {
        Self {
            fn_desc,
            cur_section: InputSection::Text,
            asm_conts: vec![],
            late_rodata_asm_conts: vec![],
            late_rodata_alignment: 0,
            late_rodata_alignment_from_context: false,
            text_glabels: vec![],
            fn_section_sizes: EnumMap::default(),
            fn_ins_inds: vec![],
            glued_line: String::new(),
            num_lines: 0,
        }
    }

    fn fail_without_line<T>(&self, msg: &str) -> Result<T> {
        Err(anyhow::anyhow!("{}\nwithin {}", msg, self.fn_desc))
    }

    fn fail_at_line<T>(&self, msg: &str, line: &str) -> Result<T> {
        Err(anyhow::anyhow!(
            "{}\nwithin {} at line {}",
            msg,
            self.fn_desc,
            line
        ))
    }

    fn count_quoted_size(
        &self,
        line: &str,
        z: bool,
        real_line: &str,
        output_enc: &Encoding,
    ) -> Result<usize> {
        let line = output_enc.encode(line)?;

        let mut in_quote = false;
        let mut has_comma = true;
        let mut num_parts = 0;
        let mut ret = 0;
        let mut i = 0;
        let digits = b"0123456789"; // 0-7 would be more sane, but this matches GNU as
        let hexdigits = b"0123456789abcdefABCDEF";

        while i < line.len() {
            let c = line[i];
            i += 1;
            if !in_quote {
                if c == b'"' {
                    in_quote = true;
                    if z && !has_comma {
                        return self.fail_at_line(".asciiz with glued strings is not supported due to GNU as version diffs", real_line);
                    }
                    num_parts += 1;
                } else if c == b',' {
                    has_comma = true;
                }
            } else {
                if c == b'"' {
                    in_quote = false;
                    has_comma = false;
                    continue;
                }
                ret += 1;
                if c != b'\\' {
                    continue;
                }
                if i == line.len() {
                    return self.fail_at_line("backslash at end of line not supported", real_line);
                }
                let c = line[i];
                i += 1;
                // (if c is in "bfnrtv", we have a real escaped literal)
                if c == b'x' {
                    // hex literal, consume any number of hex chars, possibly none
                    while i < line.len() && hexdigits.contains(&line[i]) {
                        i += 1;
                    }
                } else if digits.contains(&c) {
                    // octal literal, consume up to two more digits
                    let mut it = 0;
                    while i < line.len() && digits.contains(&line[i]) && it < 2 {
                        i += 1;
                        it += 1;
                    }
                }
            }
        }

        if in_quote {
            return self.fail_at_line("unterminated string literal", real_line);
        }
        if num_parts == 0 {
            return self.fail_at_line(".ascii with no string", real_line);
        }
        Ok(ret + if z { num_parts } else { 0 })
    }

    fn align(&mut self, n: usize) {
        let size = &mut self.fn_section_sizes[self.cur_section];
        while *size % n != 0 {
            *size += 1;
        }
    }

    fn add_sized(&mut self, size: isize, line: &str) -> Result<()> {
        if (self.cur_section == InputSection::Text || self.cur_section == InputSection::LateRodata)
            && size % 4 != 0
        {
            return self.fail_at_line("size must be a multiple of 4", line);
        }

        if size < 0 {
            return self.fail_at_line("size cannot be negative", line);
        }

        self.fn_section_sizes[self.cur_section] += size as usize;

        if self.cur_section == InputSection::Text {
            if self.text_glabels.is_empty() {
                return self.fail_at_line(".text block without an initial glabel", line);
            }
            self.fn_ins_inds
                .push((self.num_lines - 1, size as usize / 4));
        }

        Ok(())
    }

    fn process_line(&mut self, line: &str, output_enc: &Encoding) -> Result<()> {
        self.num_lines += 1;
        if let Some(stripped) = line.strip_suffix("\\") {
            self.glued_line = format!("{}{}", self.glued_line, stripped);
            return Ok(());
        }
        let mut line = self.glued_line.clone() + line;
        self.glued_line = String::new();

        static CACHE: OnceLock<(Regex, Regex)> = OnceLock::new();
        let (re_comment_or_string, re_label) = CACHE.get_or_init(|| {
            (
                Regex::new(r#"#.*|/\*.*?\*/|"(?:\\.|[^\\"])*""#).unwrap(),
                Regex::new(r"^[a-zA-Z0-9_]+:\s*").unwrap(),
            )
        });

        fn re_comment_replacer(caps: &regex_lite::Captures) -> String {
            let s = caps[0].to_string();
            if s.starts_with("/") || s.starts_with("#") {
                " ".to_owned()
            } else {
                s
            }
        }

        let real_line = line.clone();
        line = re_comment_or_string
            .replace_all(&line, re_comment_replacer)
            .into_owned();
        line = line.trim().to_string();
        line = re_label.replace_all(&line, "").into_owned();
        let mut changed_section = false;
        let mut emitting_double = false;

        if (line.starts_with("glabel ") || line.starts_with("jlabel "))
            && self.cur_section == InputSection::Text
        {
            self.text_glabels
                .push(line.split_whitespace().nth(1).unwrap().to_string());
        }
        if line.is_empty() {
            // empty line
        } else if line.starts_with("glabel ")
            || line.starts_with("dlabel ")
            || line.starts_with("jlabel ")
            || line.starts_with("endlabel ")
            || (!line.contains(" ") && line.ends_with(":"))
        {
            // label
        } else if line.starts_with(".section")
            || matches!(
                line.as_str(),
                ".text" | ".data" | ".rdata" | ".rodata" | ".bss" | ".late_rodata"
            )
        {
            // section change
            self.cur_section = if line == ".rdata" {
                InputSection::Rodata
            } else {
                let first_arg = line.split(',').next().unwrap().to_string();
                let name = first_arg.split_whitespace().last().unwrap();
                match InputSection::from_str(name) {
                    Some(s) => s,
                    None => {
                        return self.fail_at_line("unrecognized .section directive", &real_line)
                    }
                }
            };

            changed_section = true;
        } else if line.starts_with(".late_rodata_alignment") {
            if self.cur_section != InputSection::LateRodata {
                return self.fail_at_line(
                    ".late_rodata_alignment must occur within .late_rodata section",
                    &real_line,
                );
            }

            let value = line.split_whitespace().nth(1).unwrap().parse::<usize>()?;
            if value != 4 && value != 8 {
                return self
                    .fail_at_line(".late_rodata_alignment argument must be 4 or 8", &real_line);
            }
            if self.late_rodata_alignment != 0 && self.late_rodata_alignment != value {
                return self.fail_without_line(
                    ".late_rodata_alignment alignment assumption conflicts with earlier .double directive. Make sure to provide explicit alignment padding."
                );
            }
            self.late_rodata_alignment = value;
            changed_section = true;
        } else if line.starts_with(".incbin") {
            let size = line.split(',').last().unwrap().trim().parse::<isize>()?;
            self.add_sized(size, &real_line)?;
        } else if line.starts_with(".word")
            || line.starts_with(".gpword")
            || line.starts_with(".float")
        {
            self.align(4);

            self.add_sized(4 * line.split(',').count() as isize, &real_line)?;
        } else if line.starts_with(".double") {
            self.align(4);

            if self.cur_section == InputSection::LateRodata {
                let align8 = self.fn_section_sizes[self.cur_section] % 8;
                // Automatically set late_rodata_alignment, so the generated C code uses doubles.
                // This gives us correct alignment for the transferred doubles even when the
                // late_rodata_alignment is wrong, e.g. for non-matching compilation.
                if self.late_rodata_alignment == 0 {
                    self.late_rodata_alignment = 8 - align8;
                    self.late_rodata_alignment_from_context = true;
                } else if self.late_rodata_alignment != 8 - align8 {
                    if self.late_rodata_alignment_from_context {
                        return self.fail_at_line(
                            "found two .double directives with different start addresses mod 8. Make sure to provide explicit alignment padding.",
                            &real_line
                        );
                    } else {
                        return self.fail_at_line(
                            ".double at address that is not 0 mod 8 (based on .late_rodata_alignment assumption). Make sure to provide explicit alignment padding.\n{}",
                            &real_line
                        );
                    }
                }

                self.add_sized(8 * line.split(',').count() as isize, &real_line)?;
                emitting_double = true;
            }
        } else if line.starts_with(".space") {
            let size = line.split_whitespace().nth(1).unwrap().parse::<isize>()?;
            self.add_sized(size, &real_line)?;
        } else if line.starts_with(".balign") {
            let align = line.split_whitespace().nth(1).unwrap().parse::<isize>()?;
            if align != 4 {
                return self.fail_at_line("only .balign 4 is supported", &real_line);
            }
            self.align(4);
        } else if line.starts_with(".align") {
            let align = line.split_whitespace().nth(1).unwrap().parse::<isize>()?;
            if align != 2 {
                return self.fail_at_line("only .align 2 is supported", &real_line);
            }
            self.align(4);
        } else if line.starts_with(".asci") {
            let z = line.starts_with(".asciz") || line.starts_with(".asciiz");
            self.add_sized(
                self.count_quoted_size(&line, z, &real_line, output_enc)? as isize,
                &real_line,
            )?;
        } else if line.starts_with(".byte") {
            self.add_sized(line.split(',').count() as isize, &real_line)?;
        } else if line.starts_with(".half")
            || line.starts_with(".hword")
            || line.starts_with(".short")
        {
            self.align(2);
            self.add_sized(2 * line.split(',').count() as isize, &real_line)?;
        } else if line.starts_with(".size") {
        } else if line.starts_with('.') {
            return self.fail_at_line("asm directive not supported", &real_line);
        } else {
            // Unfortunately, macros are hard to support for .rodata --
            // we don't know how how space they will expand to before
            // running the assembler, but we need that information to
            // construct the C code. So if we need that we'll either
            // need to run the assembler twice (at least in some rare
            // cases), or change how this program is invoked.
            // Similarly, we can't currently deal with pseudo-instructions
            // that expand to several real instructions.
            if self.cur_section != InputSection::Text {
                return self.fail_at_line(
                    "instruction or macro call in non-.text section? not supported",
                    &real_line,
                );
            }
            self.add_sized(4, &real_line)?;
        }

        if self.cur_section == InputSection::LateRodata {
            if !changed_section {
                if emitting_double {
                    self.late_rodata_asm_conts.push(".align 0".to_string());
                }
                self.late_rodata_asm_conts.push(real_line.clone());
                if emitting_double {
                    self.late_rodata_asm_conts.push(".align 2".to_string());
                }
            }
        } else {
            self.asm_conts.push(real_line.clone());
        }

        Ok(())
    }

    const MAX_FN_SIZE: usize = 100;

    fn finish(&self, state: &mut GlobalState) -> Result<(Vec<String>, Function)> {
        let mut src = vec!["".to_owned(); self.num_lines + 1];
        let mut late_rodata_dummy_bytes = vec![];
        let mut jtbl_rodata_size = 0;
        let mut late_rodata_fn_output = vec![];

        let num_instr = self.fn_section_sizes[InputSection::Text] / 4;

        if self.fn_section_sizes[InputSection::LateRodata] > 0 {
            // Generate late rodata by emitting unique float constants.
            // This requires 3 instructions for each 4 bytes of rodata.
            // If we know alignment, we can use doubles, which give 3
            // instructions for 8 bytes of rodata.
            let size = self.fn_section_sizes[InputSection::LateRodata] / 4;
            let mut skip_next = false;
            let mut needs_double = self.late_rodata_alignment != 0;
            let mut extra_mips1_nop = false;
            let (jtbl_size, jtbl_min_rodata_size) = match (state.pascal, state.mips1) {
                (true, true) => (9, 2),
                (true, false) => (8, 2),
                (false, true) => (11, 5),
                (false, false) => (9, 5),
            };

            for i in 0..size {
                if skip_next {
                    skip_next = false;
                    continue;
                }
                // Jump tables give 9 instructions (11 with -mips1) for >= 5 words of rodata,
                // and should be emitted when:
                // - -O2 or -O2 -g3 are used, which give the right codegen
                // - we have emitted our first .float/.double (to ensure that we find the
                //   created rodata in the binary)
                // - we have emitted our first .double, if any (to ensure alignment of doubles
                //   in shifted rodata sections)
                // - we have at least 5 words of rodata left to emit (otherwise IDO does not
                //   generate a jump table)
                // - we have at least 10 more instructions to go in this function (otherwise our
                //   function size computation will be wrong since the delay slot goes unused)
                if !needs_double
                    && state.use_jtbl_for_rodata
                    && i >= 1
                    && size - i >= jtbl_min_rodata_size
                    && num_instr - late_rodata_fn_output.len() >= jtbl_size + 1
                {
                    let line = if state.pascal {
                        let cases: String = (0..(size - i))
                            .map(|case| format!("{}: ;", case))
                            .collect::<Vec<String>>()
                            .join("\n");
                        format!("case 0 of {} otherwise end;", cases)
                    } else {
                        let cases: String = (0..(size - i))
                            .map(|case| format!("case {}:", case))
                            .collect::<Vec<String>>()
                            .join(" ");
                        format!("switch (*(volatile int*)0) {{ {} ; }}", cases)
                    };
                    late_rodata_fn_output.push(line);
                    late_rodata_fn_output.extend(iter::repeat("".to_owned()).take(jtbl_size - 1));
                    jtbl_rodata_size = (size - i) * 4;
                    extra_mips1_nop = i != 2;
                    break;
                }

                let dummy_bytes = state.next_late_rodata_hex();
                late_rodata_dummy_bytes.push(dummy_bytes);
                if self.late_rodata_alignment == 4 * ((i + 1) % 2 + 1) && i + 1 < size {
                    let dummy_bytes2 = state.next_late_rodata_hex();
                    late_rodata_dummy_bytes.push(dummy_bytes2);
                    let combined = [dummy_bytes, dummy_bytes2].concat().try_into().unwrap();
                    let fval = f64::from_be_bytes(combined);
                    let line = if state.pascal {
                        state.pascal_assignment_double(fval)
                    } else {
                        format!("*(volatile double*)0 = {:?};", fval)
                    };
                    late_rodata_fn_output.push(line);
                    skip_next = true;
                    needs_double = false;
                    if state.mips1 {
                        // mips1 does not have ldc1/sdc1
                        late_rodata_fn_output.push("".to_owned());
                        late_rodata_fn_output.push("".to_owned());
                    }
                    extra_mips1_nop = false;
                } else {
                    let fval = f32::from_be_bytes(dummy_bytes);
                    let line = if state.pascal {
                        state.pascal_assignment_float(fval)
                    } else {
                        format!("*(volatile float*)0 = {:?}f;", fval)
                    };
                    late_rodata_fn_output.push(line);
                    extra_mips1_nop = true;
                }
                late_rodata_fn_output.push("".to_owned());
                late_rodata_fn_output.push("".to_owned());
            }

            if state.mips1 && extra_mips1_nop {
                late_rodata_fn_output.push("".to_owned());
            }
        }

        let mut text_name = None;
        if self.fn_section_sizes[InputSection::Text] > 0 || !late_rodata_fn_output.is_empty() {
            let new_name = state.make_name("func");
            src[0] = state.func_prologue(&new_name);
            text_name = Some(new_name);
            src[self.num_lines] = state.func_epilogue();
            let instr_count = self.fn_section_sizes[InputSection::Text] / 4;
            if instr_count < state.min_instr_count {
                return self.fail_without_line("too short .text block");
            }
            let mut tot_emitted = 0;
            let mut tot_skipped = 0;
            let mut fn_emitted = 0;
            let mut fn_skipped = 0;
            let mut skipping = true;
            let mut rodata_stack: Vec<String> = late_rodata_fn_output.clone();
            rodata_stack.reverse();

            for &(line, count) in &self.fn_ins_inds {
                for _ in 0..count {
                    if fn_emitted > Self::MAX_FN_SIZE
                        && instr_count - tot_emitted > state.min_instr_count
                        && (rodata_stack.is_empty() || !rodata_stack.last().unwrap().is_empty())
                    {
                        // Don't let functions become too large. When a function reaches 284
                        // instructions, and -O2 -framepointer flags are passed, the IRIX
                        // compiler decides it is a great idea to start optimizing more.
                        // Also, Pascal cannot handle too large functions before it runs out
                        // of unique statements to write.
                        fn_emitted = 0;
                        fn_skipped = 0;
                        skipping = true;
                        let large_func_name = state.make_name("large_func");
                        src[line] += &format!(
                            " {} {} ",
                            state.func_epilogue(),
                            state.func_prologue(&large_func_name)
                        );
                    }

                    let skip_for_late_rodata = if !rodata_stack.is_empty() {
                        state.prelude_if_late_rodata
                    } else {
                        0
                    };
                    if skipping && fn_skipped < state.skip_instr_count + skip_for_late_rodata {
                        fn_skipped += 1;
                        tot_skipped += 1;
                    } else {
                        skipping = false;
                        if let Some(entry) = rodata_stack.pop() {
                            src[line] += &entry;
                        } else if state.pascal {
                            src[line] += &state.pascal_assignment_int(0);
                        } else {
                            src[line] += "*(volatile int*)0 = 0;";
                        }
                    }
                    tot_emitted += 1;
                    fn_emitted += 1;
                }
            }

            if !rodata_stack.is_empty() {
                let size = late_rodata_fn_output.len() / 3;
                let available = instr_count - tot_skipped;
                return self.fail_without_line(&format!(
                    "late rodata to text ratio is too high: {} / {} must be <= 1/3\n
                    add .late_rodata_alignment (4|8) to the .late_rodata block
                    to double the allowed ratio.",
                    size, available
                ));
            }
        }

        let mut rodata_name = None;
        if self.fn_section_sizes[InputSection::Rodata] > 0 {
            if state.pascal {
                return self.fail_without_line(".rodata isn't supported with Pascal for now");
            }
            let new_name = state.make_name("rodata");
            src[self.num_lines] += &format!(
                " const char {}[{}] = {{1}};",
                new_name,
                self.fn_section_sizes[InputSection::Rodata]
            );
            rodata_name = Some(new_name);
        }

        let mut data_name = None;
        if self.fn_section_sizes[InputSection::Data] > 0 {
            let new_name = state.make_name("data");
            let line = if state.pascal {
                format!(
                    " var {}: packed array[1..{}] of char := [otherwise: 0];",
                    new_name,
                    self.fn_section_sizes[InputSection::Data]
                )
            } else {
                format!(
                    " char {}[{}] = {{1}};",
                    new_name,
                    self.fn_section_sizes[InputSection::Data]
                )
            };
            src[self.num_lines] += &line;
            data_name = Some(new_name);
        }

        let mut bss_name = None;
        if self.fn_section_sizes[InputSection::Bss] > 0 {
            let new_name = state.make_name("bss");
            if state.pascal {
                return self.fail_without_line(".bss isn't supported with Pascal for now");
            }
            src[self.num_lines] += &format!(
                " char {}[{}];",
                new_name,
                self.fn_section_sizes[InputSection::Bss]
            );
            bss_name = Some(new_name);
        }

        let mut data = EnumMap::default();
        data[OutputSection::Text] = (text_name, self.fn_section_sizes[InputSection::Text]);
        data[OutputSection::Data] = (data_name, self.fn_section_sizes[InputSection::Data]);
        data[OutputSection::Rodata] = (rodata_name, self.fn_section_sizes[InputSection::Rodata]);
        data[OutputSection::Bss] = (bss_name, self.fn_section_sizes[InputSection::Bss]);
        let ret_fn = Function {
            text_glabels: self.text_glabels.clone(),
            asm_conts: self.asm_conts.clone(),
            late_rodata_dummy_bytes,
            jtbl_rodata_size,
            late_rodata_asm_conts: self.late_rodata_asm_conts.clone(),
            fn_desc: self.fn_desc.clone(),
            data,
        };

        Ok((src, ret_fn))
    }
}

/// Convert a float string to its hexadecimal representation
fn repl_float_hex(cap: &regex_lite::Captures) -> String {
    let float_str = cap[0].trim().trim_end_matches('f');
    let float_val = float_str.parse::<f32>().unwrap();
    let hex_val = f32::to_be_bytes(float_val);
    format!("{}", u32::from_be_bytes(hex_val))
}

pub(crate) struct ParseSourceResult {
    pub functions: Vec<Function>,
    pub deps: Vec<String>,
    pub output: Vec<u8>,
}

pub(crate) fn parse_source(
    infile_path: &Path,
    args: &AsmProcArgs,
    opts: &CompileOpts,
    encode: bool,
) -> Result<ParseSourceResult> {
    let (mut min_instr_count, mut skip_instr_count) = match opts.opt {
        OptLevel::O0 => match opts.framepointer {
            true => (8, 8),
            false => (4, 4),
        },
        OptLevel::O1 | OptLevel::O2 => match opts.framepointer {
            true => (6, 5),
            false => (2, 1),
        },
        OptLevel::G => match opts.framepointer {
            true => (7, 7),
            false => (4, 4),
        },
        OptLevel::G3 => match opts.framepointer {
            true => (4, 4),
            false => (2, 2),
        },
    };

    let mut prelude_if_late_rodata = 0;
    if opts.kpic {
        // Without optimizations, the PIC prelude always takes up 3 instructions.
        // With optimizations, the prelude is optimized out if there's no late rodata.
        if matches!(opts.opt, OptLevel::O2 | OptLevel::G3) {
            prelude_if_late_rodata = 3;
        } else {
            min_instr_count += 3;
            skip_instr_count += 3;
        }
    }

    let use_jtbl_for_rodata =
        matches!(opts.opt, OptLevel::O2 | OptLevel::G3) && !opts.framepointer && !opts.kpic;

    let mut state = GlobalState::new(
        min_instr_count,
        skip_instr_count,
        use_jtbl_for_rodata,
        prelude_if_late_rodata,
        opts.mips1,
        opts.pascal,
    );
    let input_enc = &args.input_enc;
    let output_enc = &args.output_enc;
    let mut global_asm: Option<(GlobalAsmBlock, usize)> = None;
    let mut asm_functions: Vec<Function> = vec![];
    let mut output_lines: Vec<String> = vec![format!("#line 1 \"{}\"", infile_path.display())];
    let mut deps: Vec<String> = vec![];

    let mut is_cutscene_data = false;
    let mut is_early_include = false;

    let cutscene_re = Regex::new(r"CutsceneData (.|\n)*\[\] = \{")?;
    let float_re = Regex::new(r"[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?f")?;

    let file_contents = fs::read(infile_path)?;
    for (line_no, line) in input_enc.decode(&file_contents)?.lines().enumerate() {
        let line_no = line_no + 1;
        let mut raw_line = line.trim().to_owned();
        let line = raw_line.trim_start();

        // Print exactly one output line per source line, to make compiler
        // errors have correct line numbers. These will be overridden with
        // reasonable content further down.
        output_lines.push("".to_owned());

        if let Some((ref mut gasm, start_index)) = global_asm {
            if line.starts_with(')') {
                let (mut src, fun) = gasm.finish(&mut state)?;
                if state.pascal {
                    // Pascal has a 1600-character line length limit, so some
                    // of the lines we emit may be broken up. Correct for that
                    // using a #line directive.
                    *src.last_mut().unwrap() += &format!("\n#line {}", line_no + 1);
                }
                for (i, line2) in src.iter().enumerate() {
                    output_lines[start_index + i] = line2.clone();
                }
                asm_functions.push(fun);
                global_asm = None;
            } else {
                gasm.process_line(&raw_line, output_enc)?;
            }
        } else if line == "GLOBAL_ASM(" || line == "#pragma GLOBAL_ASM(" {
            global_asm = Some((
                GlobalAsmBlock::new(format!("GLOBAL_ASM block at line {}", &line_no.to_string())),
                output_lines.len(),
            ));
        } else if ((line.starts_with("GLOBAL_ASM(\"") || line.starts_with("#pragma GLOBAL_ASM(\""))
            && line.ends_with("\")"))
            || ((line.starts_with("INCLUDE_ASM(\"") || line.starts_with("INCLUDE_RODATA(\""))
                && line.contains("\",")
                && line.ends_with(");"))
        {
            let (prologue, fname) = if line.starts_with("INCLUDE_") {
                // INCLUDE_ASM("path/to", functionname);
                let (before, after) = line.split_once("\",").unwrap();
                let fname = format!(
                    "{}/{}.s",
                    before[before.find('(').unwrap() + 2..].to_owned(),
                    after.trim()[..after.len() - 3].trim()
                );

                if line.starts_with("INCLUDE_RODATA") {
                    (vec![".section .rodata".to_string()], fname)
                } else {
                    (vec![], fname)
                }
            } else {
                // GLOBAL_ASM("path/to/file.s")
                let fname = line[line.find('(').unwrap() + 2..line.len() - 2].to_string();
                (vec![], fname)
            };

            let mut gasm = GlobalAsmBlock::new(fname.clone());
            for line2 in prologue {
                gasm.process_line(line2.trim_end(), output_enc)?;
            }

            if !Path::new(&fname).exists() {
                // The GLOBAL_ASM block might be surrounded by an ifdef, so it's
                // not clear whether a missing file actually represents a compile
                // error. Pass the responsibility for determining that on to the
                // compiler by emitting a bad include directive. (IDO treats
                // #error as a warning for some reason.)
                let output_lines_len = output_lines.len();
                output_lines[output_lines_len - 1] = format!("#include \"GLOBAL_ASM:{}\"", fname);
                continue;
            }

            let file_contents = fs::read(&fname)?;
            for line2 in input_enc.decode(&file_contents)?.lines() {
                gasm.process_line(line2.trim_end(), output_enc)?;
            }

            let (mut src, fun) = gasm.finish(&mut state)?;
            let output_lines_len = output_lines.len();
            if state.pascal {
                // Pascal has a 1600-character line length limit, so avoid putting
                // everything on the same line.
                src.push(format!("#line {}", line_no + 1));
                output_lines[output_lines_len - 1] = src.join("\n");
            } else {
                output_lines[output_lines_len - 1] = src.join("");
            }
            asm_functions.push(fun);
            deps.push(fname);
        } else if line == "#pragma asmproc recurse" {
            // C includes qualified as
            // #pragma asmproc recurse
            // #include "file.c"
            // will be processed recursively when encountered
            is_early_include = true;
        } else if is_early_include {
            // Previous line was a #pragma asmproc recurse
            is_early_include = false;
            if !line.starts_with("#include ") {
                return Err(anyhow::anyhow!(
                    "#pragma asmproc recurse must be followed by an #include "
                ));
            }
            let fpath = infile_path.parent().unwrap();
            let fname = fpath.join(line[line.find(' ').unwrap() + 2..].trim());
            deps.push(fname.to_str().unwrap().to_string());
            let mut res = parse_source(&fname, args, opts, false)?;
            deps.append(&mut res.deps);
            let res_str = format!(
                "{}#line {} \"{}\"",
                String::from_utf8(res.output).expect("nested calls generate utf-8"),
                line_no + 1,
                infile_path.file_name().unwrap().to_str().unwrap()
            );

            let output_lines_len = output_lines.len();
            output_lines[output_lines_len - 1] = res_str;
        } else {
            if args.encode_cutscene_data_floats {
                // This is a hack to replace all floating-point numbers in an array of a particular type
                // (in this case CutsceneData) with their corresponding IEEE-754 hexadecimal representation
                if cutscene_re.is_match(line) {
                    is_cutscene_data = true;
                } else if line.ends_with("};") {
                    is_cutscene_data = false;
                }

                if is_cutscene_data {
                    raw_line = float_re.replace_all(&raw_line, repl_float_hex).into_owned();
                }
            }
            let output_lines_len = output_lines.len();
            output_lines[output_lines_len - 1] = raw_line.to_owned();
        }
    }

    let out_data = if encode {
        let newline_encoded = output_enc.encode("\n")?;

        let mut data = vec![];
        for line in output_lines {
            let line_encoded = output_enc.encode(&line)?;
            data.write_all(&line_encoded)?;
            data.write_all(&newline_encoded)?;
        }
        data
    } else {
        let str = format!("{}\n", output_lines.join("\n"));

        str.as_bytes().to_vec()
    };

    Ok(ParseSourceResult {
        functions: asm_functions,
        deps,
        output: out_data,
    })
}

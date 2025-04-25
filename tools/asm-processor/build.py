#!/usr/bin/env python3
import sys
from pathlib import Path
import shlex
import subprocess
import tempfile
import uuid
import asm_processor

# Preprocessed files are temporary. For debugging purposes, you can set this
# variable or pass --keep-preprocessed path/to/dir/ to keep a copy.
keep_output_dir = None
# keep_output_dir = Path("./asm_processor_preprocessed")

progname = sys.argv[0]
all_args = sys.argv[1:]

i = 0
asmproc_flags = []
while i < len(all_args):
    arg = all_args[i]
    if arg == "--":
        i += 1
        break
    if not arg.startswith("-"):
        break
    i += 1
    asmproc_flags.append(arg)
    if arg in ("--input-enc", "--output-enc", "--asm-prelude", "--convert-statics", "--keep-preprocessed", "--no-dep-file") and i < len(all_args):
        asmproc_flags.append(all_args[i])
        i += 1

sep0 = i
try:
    sep1 = all_args.index("--", sep0)
    sep2 = all_args.index("--", sep1 + 1)
except ValueError:
    print(f"Usage: {progname} [options] <compiler...> -- <assembler...> -- <compiler flags...>")
    sys.exit(1)

compiler = all_args[sep0:sep1]
assembler_args = all_args[sep1 + 1 : sep2]
compile_args = all_args[sep2 + 1 :]

assembler_sh = " ".join(shlex.quote(x) for x in assembler_args)


def fail_parse(msg):
    print(f"Failed to parse compiler flags: {msg}")
    sys.exit(1)

try:
    out_ind = compile_args.index("-o")
except ValueError:
    fail_parse("missing -o argument")

try:
    out_file = Path(compile_args[out_ind + 1])
except IndexError:
    fail_parse("missing argument after -o")

del compile_args[out_ind + 1]
del compile_args[out_ind]

try:
    in_file = Path(compile_args[-1])
except IndexError:
    fail_parse("missing input file argument")

del compile_args[-1]


in_dir = in_file.resolve().parent
opt_flags = [
    x for x in compile_args if x in {"-g3", "-g", "-O0", "-O1", "-O2", "-framepointer", "-KPIC"}
]
if "-mips2" not in compile_args:
    opt_flags.append("-mips1")

asmproc_flags += opt_flags + [str(in_file)]

# Drop .mdebug and .gptab sections from resulting binaries. This makes
# resulting .o files much smaller and speeds up builds, but loses line
# number debug data.
# asmproc_flags += ["--drop-mdebug-gptab"]

# Convert encoding before compiling.
# asmproc_flags += ["--input-enc", "utf-8", "--output-enc", "euc-jp"]

with tempfile.TemporaryDirectory(prefix="asm_processor") as tmpdirname:
    tmpdir_path = Path(tmpdirname)
    preprocessed_filename = "preprocessed_" + uuid.uuid4().hex + in_file.suffix
    preprocessed_path = tmpdir_path / preprocessed_filename

    with preprocessed_path.open("wb") as outfile:
        functions, deps, keep_output_dir2 = asm_processor.run(asmproc_flags, outfile=outfile)

    keep_output_dir = keep_output_dir or keep_output_dir2
    if keep_output_dir:
        import shutil

        keep_output_dir.mkdir(parents=True, exist_ok=True)

        shutil.copy(
            preprocessed_path,
            keep_output_dir / (in_file.stem + "_" + preprocessed_filename),
        )

    compile_cmdline = (
        compiler
        + compile_args
        + ["-I", str(in_dir), "-o", str(out_file), str(preprocessed_path)]
    )

    try:
        subprocess.check_call(compile_cmdline)
    except subprocess.CalledProcessError as e:
        print("Failed to compile file " + str(in_file) + ". Command line:")
        print()
        print(" ".join(shlex.quote(x) for x in compile_cmdline))
        print()
        sys.exit(55)

    asm_processor.run(
        asmproc_flags
        + [
            "--post-process",
            str(out_file),
            "--assembler",
            assembler_sh,
        ],
        functions=functions,
    )

    deps_file = out_file.with_suffix(".asmproc.d")
    if deps and "--no-dep-file" not in asmproc_flags:
        with deps_file.open("w") as f:
            f.write(str(out_file) + ": " + " \\\n    ".join(deps) + "\n")
            for dep in deps:
                f.write("\n" + dep + ":\n")
    else:
        try:
            deps_file.unlink()
        except OSError:
            pass

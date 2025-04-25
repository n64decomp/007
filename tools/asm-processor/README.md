# asm-processor

Pre-process .c files and post-process .o files to enable embedding MIPS assembly into IDO-compiled C.

This repository contains both the original Python implementation and rewrite in Rust that is designed to be 1:1 behavorially equivalent with the existing Python version, but faster.

## Installation

Most projects traditionally have included the `asm-processor` repo as a [submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules),  [subrepo](https://github.com/ingydotnet/git-subrepo), or plain copy inside their project.
This is recommended, as it ensures consistency for all project users.

### Rust
After vendoring this repo into your repository, you will want to add a step to your project setup procedure that builds the asm-processor binary with the [Rust toolchain](https://www.rust-lang.org/tools/install).
Presuming this repo is available at `tools/asm-processor/`, the following command can be run to build the project:

```
cargo build --release --manifest-path tools/asm-processor/rust/Cargo.toml
```

This will generate the executable at `tools/asm-processor/rust/target/release/asm-processor`. The build system for your project can then be configured to run `asm-processor` from this location.

If you prefer not to build the project yourself or require downstream users to do so, we also provide release binaries that can either be downloaded at build time or included directly in your project's repo.

### Python
Simply vendor this repo into your repository as described above and use `build.py`.


## Usage

The Python `build.py` script and Rust `asm-processor` binary accept the same syntax and command line flags. If using the Rust implementation, substitute `build.py` with `asm-processor` in the below guide.

Let's say you have a file compiled with `-g` on the IDO compiler, that looks like this:
```c
float func4(void) {
    "func4";
    return 0.2f;
}
```

This script enables replacing it by:
```asm
GLOBAL_ASM(
.rdata
.word 0x66756e63 # func
.word 0x34000000 # 4\0\0\0

.late_rodata
glabel rv
.word 0x3e4ccccd # 0.2f

.text
glabel func4
lui     $at, %hi(rv)
jr      $ra
lwc1    $f0, %lo(rv)($at)
jr      $ra
nop
jr      $ra
nop
)
```

To compile the file, run `build.py $CC -- $AS $ASFLAGS -- $CFLAGS -o out.o in.c`, where $CC points to an IDO binary (5.3/7.1 and recomp/qemu all supported), $AS is e.g. `mips-linux-gnu-as`, $ASFLAGS e.g. `-march=vr4300 -mabi=32` and $CFLAGS e.g. `-Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -g`.

In addition to an .o file, asm-processor also generates a .d file with Makefile dependencies for .s files referenced by the input .c file.
This functionality can be disabled by passing the `--no-dep-file` flag.

Reading assembly from file is also supported, by either `GLOBAL_ASM("file.s")` or `#pragma GLOBAL_ASM("file.s")`.

For compatibility with common GCC macros, `INCLUDE_ASM("folder", functionname);` and `INCLUDE_RODATA("folder", functionname);` are also allowed, and equivalent to `GLOBAL_ASM("folder/functionname.s")`.

### What is supported?

`.text`, `.data`, `.bss` and `.rodata` sections, `.word`/`.incbin`, `.ascii`/`.asciz`, and `-g`, `-g3`, `-O1`, `-O2`, `-framepointer` and `-mips1`/`-mips2` flags to the IDO compiler.

### What is not supported?

* complicated assembly (.ifdef, macro declarations/calls other than `glabel`, pseudo-instructions that expand to several real instructions)
* non-IDO compilers
* `-O3` (due to function reordering)

C `#ifdef`s only work outside of `GLOBAL_ASM` calls, but is otherwise able to replace `.ifdef`.

### What's up with "late rodata"?

The IDO compiler emits rodata in two passes: first array/string contents, then large literals/switch jump tables.

Data declared within `.rdata`/`.section .rodata` will end up in the first half, and `.late_rodata`/`.section .late_rodata` in the second half.

### How does it work?

It's a bit of a hack!
The basic idea is replace `GLOBAL_ASM` blocks with dummy C functions/global vars of the same sections sizes as the assembly.
Then the C file gets compiled, and the dummy contents overwritten with the injected assembly.

To accomplish this, asm-processor has logic for guessing the size of assembly contents
(which assumes the assembly isn't too complicated, e.g. no macros),
and for emitting C code of exact sizes for a bunch of different IDO compiler flags.

The assembler code is padded with nops to line it up with its correct position in the C;
this allows C and asm ELF files to be merged easily without having to fix up e.g. symbol addresses.

The most difficult part is `late_rodata`, which is hard to create programmatically.
asm-processor does that by emitting code that uses dummy float literals/double literals/jump tables,
assembles the late_rodata at another location of the .rodata section, then overwrites the dummy rodata.
This does require some movement of symbols and relocations, and quite a bit of care in what code to
emit and how to preserve .double alignment.

It's worth noting some alternative ways in which asm-processor would have been implemented:
- One idea to get rid of the C/asm size estimations is to emit arbitrary code, and then move code,
symbols and relocations to the correct place after the sizes are known.
Given the machinery for `late_rodata` this wouldn't have been too difficult, and it would have the upside of improved portability.
There is a big downside, however: using dummy code of incorrect size throws off alignment and can introduce unintended padding.
Fixing this would require running multiple passes of asm-processor, with one compile per `ASM_GLOBAL`.
- Another idea is to run the compiler with -S to emit assembly, modify the emitted assembly, then run the assembler
(which in IDO's case may perform additional instruction reordering etc.).
This option has not been investigated in much detail, and would perhaps be superior to the current implementation.
It does have a few unknowns to it, e.g. instruction encoding differences between GNU `as` and IDO's assembler,
how to avoid reordering the injected assembly, and how .rodata/.late_rodata are implemented.

### Testing

There are a few tests to ensure you don't break anything when hacking on asm-processor: `./run-tests.sh` should exit without output if they pass, or else output a diff from previous to new version.

Tests need the environment variable `MIPS_CC` set to point to the IDO 7.1 compiler, with Pascal support enabled.

For example if asm-processor is cloned in the same directory as [ido static recomp](https://github.com/decompals/ido-static-recomp) and the working directory is asm-processor, tests can be run using:

```sh
MIPS_CC=../ido-static-recomp/build/7.1/out/cc ./run-tests.sh
```

Or using qemu-irix (don't forget `chmod u+x qemu-irix`) to emulate IDO:

```sh
MIPS_CC='./qemu-irix -silent -L ../ido-static-recomp/ido/7.1/ ../ido-static-recomp/ido/7.1/usr/bin/cc' ./run-tests.sh
```

To skip running Pascal tests, remove the `tests/*.p` glob from `run-tests.sh`.

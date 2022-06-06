# Build Readme

This file explains the details of the build process.

# Requirements

It is required that `qemu-irix` be installed and available.

# Environment

The build uses the `US` version by default. Available options are `US`, `EU`, and `JP`. For example

    make clean VERSION=JP
    make VERSION=JP

# C Compiler

The c compiler can be found in `tools/irix/root/usr/bin/cc`. This splits the compilation process into several steps.  

- cfe: compiler front end
- uopt: ?
- ugen: ?

# Assembly Preprocessor

There is a (much forked) preprocessor used by many N64 projects, found in `tools/asmpreproc/asm-processor.py`. This searches for a line
beginning with `GLOBAL_ASM(` and a subsequent line beginning with `)` and treats everything in between as assembly. This is bundled with any
c code in the file and sent to the compiler.

# Code build process

`src` and `src/game`: .c and .s files are compiled into .o files  

`src/libultra`: .c and .s files are compiled into .o files  

# Asset/data build process

Before compilation begins, assets are converted into .c files. This file is then compiled using the c compiler in the usual manner.
Once an .o file exists, it is converted to an .elf file using the toolchain `-ld` program, and a .ld file specification explaining
where the ELF sections should arranged in the file (and also which sections to exclude). The toolchain `-objcopy` program is
then used to dump the data in the .elf file into a similar .bin file.

The .bin file is then compressed using the standard compression program to produce a .rz file.

For compilation, having a .c file is not necessary as long the correct .bin file is available. This can be created from the extract script.

Each obseg asset category has it's own `Makefile` in the obseg folder.

Once the .rz files exist for an asset category, they can be bundled together into an .o file. All obseg assets are bundled
in `assets/obseg/ob_seg.s` and music is bundled in `assets/music/music.s`.

# Building the final ROM

Once all code and assets are compiled into .o files, these are combined into one .elf file. The layout of the object files
is given by the `ge007.*.ld` files in the root of the project. For a list of individual methods, assets, and files see
the map file in `build/ge007.*.map` (where `*` is the country code, `u`, `e`, or `j`).

The toolchain `-objcopy` program is then used to create the bundled .bin of the entire ROM.

The final step is to run the `tools/n64cksum` program on the .bin file to create the final .z64.
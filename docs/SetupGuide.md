# Setup Guide

<!-- TOC -->
* [Setup Guide](#setup-guide)
  * [Prerequisites](#prerequisites)
  * [Install dependencies](#install-dependencies)
    * [A. Linux / WSL / VM](#a-linux--wsl--vm)
    * [B. Docker](#b-docker)
    * [C. Docker Compose](#c-docker-compose)
  * [Usage](#usage)
    * [Recompile IDO](#recompile-ido)
    * [Extract assets from base rom(s)](#extract-assets-from-base-roms)
    * [Build the ROM](#build-the-rom)
  * [In-depth build process](#in-depth-build-process)
    * [Requirements](#requirements)
    * [Environment](#environment)
    * [C Compiler](#c-compiler)
    * [Assembly Preprocessor](#assembly-preprocessor)
    * [Code build process](#code-build-process)
    * [Asset/data build process](#assetdata-build-process)
    * [Building the final ROM](#building-the-final-rom)
<!-- TOC -->

## Prerequisites

* clone this repository to a directory of your choosing
* place an unmodified copy of your existing NTSC (US) ROM inside the root of this repository with the name `baserom.u.z64`
  * optionally: if you want to extract assets from NTSC (JP) or PAL (EU), **additionally** place `baserom.j.z64` and `baserom.e.z64` into the root dir

## Install dependencies

You can choose one of the following installation methods to get all needed dependencies.

### A. Linux / WSL / VM

**Install build dependencies**

The requirements for Debian / Ubuntu should be:

```bash
sudo apt-get update
sudo apt-get install binutils-mips-linux-gnu make git python3
```

If you don't have host development tools already installed then you will also need to install `build-essential`:

```bash
sudo apt-get install build-essential
```

> **Note:** `libcapstone-dev`/`pkg-config` are **no longer required**. Older
> versions of this repo's recompiled IDO toolchain (`tools/ido5.3_recomp`,
> see [Recompile IDO](#recompile-ido) below) linked against the system
> `libcapstone` library for MIPS disassembly. The current toolchain vendors
> its own disassembly library (`rabbitizer`) instead, so there's nothing
> extra to install for it beyond the compiler already covered by
> `build-essential` above.

Additionally, [qemu-irix](https://github.com/n64decomp/qemu-irix/releases) is needed. Download the package to a desired location and install with:

```bash
sudo dpkg -i qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb
```

### B. Docker

* change directory to the cloned repo
* build the docker image: `docker build -t goldeneye .`
* connect to the container: `docker run --rm -it -v $(pwd):/home/dev goldeneye` (alternatively, replace `$(pwd)` with the absolute path of your directory)

### C. Docker Compose

* run and connect to shell in project root: `docker-compose run ge007 bash`
* on an arm64 host (e.g. Apple Silicon), create a `.env` file in the project root containing
  `GE007_PLATFORM=linux/arm64` to build a native image instead of emulating amd64. It is several times faster and
  builds the same ROM. `IDO_RECOMP=NO` is not available there, because qemu-irix is only published for amd64.

Alternatively, you can start the container with `docker compose up` and connect to the container in e.g. docker desktop

## Usage

### Recompile IDO

This project can compile the ROM's C code in one of two ways, controlled by the `IDO_RECOMP` build option (see
[Build the ROM](#build-the-rom)):

* `IDO_RECOMP=YES` (the default) — uses `tools/ido5.3_recomp/cc`, a copy of the original SGI IRIX 5.3 IDO compiler
  that has been *statically recompiled* into a native x86-64 Linux program. Since it runs directly on your machine
  instead of under an emulator, it's noticeably faster to compile with — this is why the setup step below exists.
* `IDO_RECOMP=NO` — runs the original, unmodified IRIX IDO binaries (`tools/irix/root/usr/bin/cc` etc.) under the
  [qemu-irix](https://github.com/n64decomp/qemu-irix/releases) user-mode emulator instead. Slower, but useful as a
  lower-risk reference if you ever suspect the recompiled toolchain is misbehaving.

The recompiled toolchain isn't checked into git — it's generated locally the first time it's needed, from the
original IDO binaries in `tools/irix/root`. A plain `make` from the repo root builds it automatically if it's
missing (wired up via `tools/Makefile`), so most people never need to run this step by hand. To build it explicitly
(e.g. to watch its own build output, or force a rebuild after changing it):

```bash
cd tools/ido5.3_recomp
make
```

For what this toolchain actually *is*, where it comes from upstream, and how to update it to a newer version, see
[`tools/ido5.3_recomp/README.md`](../tools/ido5.3_recomp/README.md).

The tools under `tools/` are native binaries for the machine that built them. If you switch the same checkout to a
different operating system or CPU architecture (for example between the amd64 and arm64 Docker images),
`scripts/make/build_tools.sh` notices from `tools/.toolchain-arch` and rebuilds them on the next `make`.

There may be a "dubious ownership" error from Git, and it may say it fails to detect the Git repository.
Run `git status` to see how to fix it.

### Extract assets from base rom(s)

* to have the files in correct location, see [prerequisites](#prerequisites)

To extract the NTSC (US) base rom assets run the following from root directory:

```bash
./scripts/extract_baserom.u.sh
```

> **Extracting NTSC (US) base rom assets is mandatory before extracting NTSC (JP) or PAL (EU) assets.**

To extract the NTSC (JP) base rom assets run the following from root directory:

```bash
./scripts/extract_baserom.u.sh && ./scripts/extract_diff.j.sh
```

To extract the PAL (EU) base rom assets run the following from root directory:

```bash
./scripts/extract_baserom.u.sh && ./scripts/extract_diff.e.sh
```

Other options to extract base rom assets or extract diff:

```bash
./scripts/extract_baserom.u.sh /path_to/rom.n64 # ROM in another directory
./scripts/extract_baserom.u.sh /mnt/e/Goldeneye.n64 # ROM located on EverDrive
./scripts/extract_baserom.u.sh files # Extract files only
./scripts/extract_baserom.u.sh images # Extract images only
```

**Note: If you are upgrading from an old repository, run:**

```bash
./scripts/clean_baserom.sh && ./scripts/extract_baserom.u.sh && make clean
```

### Build the ROM

Run `make` from root directory to build the ROM (defaults to `VERSION=US`).

```bash
make
```

If all goes well, resulting artifacts can be found in the `build` directory and the following text should be printed:

```bash
build/u/ge007.u.z64: OK
```

Other examples:

```bash
make VERSION=JP -j4       # build NTSC (JP) version instead with 4 jobs
make VERSION=EU COMPARE=0 # build PAL (EU) version but do not compare ROM hashes
```

The full list of configurable variables are listed below, **with the default being the first listed**:

* ``VERSION``: ``US``, ``JP``, ``EU``
* ``COMPARE``: ``1`` (compare ROM hash), ``0`` (do not compare ROM hash)
* ``IDO_RECOMP``: ``YES`` (build with IDO recomp), ``NO`` (build using [qemu-irix](https://github.com/n64decomp/qemu-irix/releases))
* ``FINAL``: ``YES`` (builds final version with -O2 optimization), ``NO`` (debug)
* ``VERBOSE``: ``0`` (quiet), ``1``

Additional documentation of the build process can be found in the next section.

## In-depth build process

This section explains the details of the build process.

### Requirements

It is required that `qemu-irix` be installed and available.

### Environment

The build uses the `US` version by default. Available options are `US`, `EU`, and `JP`. For example

    make clean VERSION=JP
    make VERSION=JP

### C Compiler

The c compiler can be found in `tools/irix/root/usr/bin/cc`. This splits the compilation process into several steps.

- cfe: compiler front end
- uopt: ?
- ugen: ?

### Assembly Preprocessor

`GLOBAL_ASM` is retired in this repository, so no asm preprocessor step is used during normal builds.
Source `.c` files are compiled directly by the IRIX compiler.

### Code build process

`src` and `src/game`: .c and .s files are compiled into .o files

`src/libultra`: .c and .s files are compiled into .o files

### Asset/data build process

Before compilation begins, assets are converted into .c files. This file is then compiled using the c compiler in the usual manner.
Once an .o file exists, it is converted to an .elf file using the toolchain `-ld` program, and a .ld file specification explaining
where the ELF sections should be arranged in the file (and also which sections to exclude). The toolchain `-objcopy` program is
then used to dump the data in the .elf file into a similar .bin file.

The .bin file is then compressed using the standard compression program to produce a .rz file.

For compilation, having a .c file is not necessary as long the correct .bin file is available. This can be created from the extract script.

Each obseg asset category has its own `Makefile` in the obseg folder.

Once the .rz files exist for an asset category, they can be bundled together into an .o file. All obseg assets are bundled
in `assets/obseg/ob_seg.s` and music is bundled in `assets/music/music.s`.

### Building the final ROM

Once all code and assets are compiled into .o files, these are combined into one .elf file. The layout of the object files
is given by the `ge007.*.ld` files in the root of the project. For a list of individual methods, assets, and files see
the map file in `build/[uje]/ge007.*.map` (where `*` is the country code, `u`, `e`, or `j`).

The toolchain `-objcopy` program is then used to create the bundled .bin of the entire ROM.

The final step is to run the `tools/n64cksum` program on the .bin file to create the final .z64.

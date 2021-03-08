This is a working Goldeneye 007 decompilation! 

[![NTSC-Status](https://github.com/kholdfuzion/goldeneye_src/workflows/NTSC-Status/badge.svg)](https://kholdfuzion.github.io/goldeneyestatus/)
[![JP-Status](https://github.com/kholdfuzion/goldeneye_src/workflows/JP-Status/badge.svg)](https://kholdfuzion.github.io/goldeneyestatus/JPN.htm)

This repo builds a matching USA. JPN or PAL ROM.

This repo does not include all assets necessary for compiling the ROMs. A prior copy of the game is required to extract the assets.

## Setup
The only requirements for Ubuntu 16.04+ should be
```bash
sudo apt install binutils-mips-linux-gnu make
```

If you don't have host development tools already installed then you will also need
```bash
sudo apt install build-essential
```

Additionally [qemu-irix](https://github.com/n64decomp/qemu-irix/releases) is needed

Install the package after download:
```bash
sudo dpkg -i qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb
```

Make sure you cloned the repo with git otherwise it won't build!!

Place an unmodified USA rom in project root named 
```bash
baserom.u.z64
```
followed by
```bash
./extract_baserom.u.sh && make
```
or
```bash
./extract_baserom.u.sh /path_to/rom.n64 && make
# Example (Rom located on EverDrive):
    ./extract_baserom.u.sh /mnt/e/Goldeneye.n64 && make
```
For J support also place a baserom.j.z64 in root and run:
```bash
./extract_baserom.u.sh && ./extract_diff.j.sh && make VERSION=JP
```

If you are upgrading from an old repo, run:
```bash
./clean_baserom.sh && ./extract_baserom.u.sh && make clean && make
```

The extract and clean scripts support switches:
```bash
name_baserom.sh files
name_baserom.sh images
```
to do just one or the other, default is both

## Build the ROM
Run make to build the ROM (defaults to VERSION=us). Other examples:
```bash
make VERSION=jp -j4       # build (J) version instead with 4 jobs
make VERSION=eu COMPARE=0 # build (EU) version but do not compare ROM hashes
```


Resulting artifacts can be found in the build directory.


The full list of configurable variables are listed below, with the default being the first listed:

VERSION: us, jp, eu

## Project Structure

```
goldeneye_src
|-- Workflows: GitHub use only
├── assets: game assets
│   ├── font: font data
│   ├── images: image data
│   │   └── split: split image data
│   ├── music: music data
│   ├── obseg: animation data
│   │   ├── bg: bg data
│   │   ├── brief: briefing data
│   │   ├── chr: c model data
│   │   ├── gun: g model data
│   │   ├── prop: p model data
│   │   ├── setup: setup data
│   │   ├── stan: stan data
│   │   └── text: text data
│   └── ramrom: demo data
├── bin: files that haven't been touched
├── build: output directory
├── include: header files
├── rsp: Custom GBI code (Assembly) (C0 and 4Tri)
├── src: C source code for game
│   ├── game: core ge specific code 0x7f000000 range
│   ├── libultra: currently used libultra.s
│   └── inflate: statically linked initial decompression code
└── tools: build tools
```

Documentation has been moved to https://github.com/kholdfuzion/goldeneye_docs/tree/master/notes

Style Guide is https://github.com/kholdfuzion/goldeneye_docs/tree/master/notes/StyleGuide.txt

This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

GE and PD documentation made by Zoinkity

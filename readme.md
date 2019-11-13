This is a working Goldeneye 007 decompilation! 

## Setup
The only requirements for Ubuntu 16.04 and 18.04 should be 
```
sudo apt install binutils-mips-linux-gnu make
```
Place a USA rom in project root named 
```
baserom.u.z64
```
followed by
```
./extract_baserom.u.sh && make
```
For J support also place a baserom.j.z64 in root and run:
```
./extract_baserom.u.sh && ./extract_diff.j.sh && make VERSION=JP
```

If you are upgrading from an old repo, run:
```
./clean_baserom.sh && ./extract_baserom.u.sh && make clean && make
```

The extract and clean scripts support switches:
```
name_baserom.sh files
name_baserom.sh images
```
to do just one or the other, default is both

## Project Structure

```
goldeneye_src
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
├── ge007_libultra: to be merged with libreultra
├── include: header files
├── lib: SDK library code
├── notes: documentation
├── src: C source code for game
│   ├── game: core ge specific code 0x7f000000 range
│   ├── libultra: currently used libultra.s
│   └── rarezip: statically linked initial decompression code
└── tools: build tools
```

This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

GE and PD documentation made by Zoinkity

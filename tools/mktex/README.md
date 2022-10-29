# pd-tex

A C library and programs for converting Perfect Dark and GoldenEye textures between their binary formats and PNG. Currently only the binary to PNG conversion is implemented.

## What's Inside

* `libpdtex` - The core library for working with the binary format. It presents textures to the caller as a `struct pd_tex`.
* `tex2png` - A C program that converts a single texture to multiple PNG images (multiple levels of detail), using libpdtex and your OS's libpng.

## Requirements

* `libpng`
* `make`

## Compiling

Run `make`.

## tex2png

Example invocation:

    ./tex2png path/to/texture.bin output/

...where the file at `path/to/texture.bin` is the texture data sliced from the ROM, and `output/` is an existing directory where the PNGs will be created.

A PNG image will be created for each level of detail within the texture. Each PNG's filename is generated using the base filename of the texture and the level of detail. For example, using the texture name `foo.bin`, the PNG images will be named `foo-0.png`, `foo-1.png` and so on. All textures have a 0 level of detail, but the other levels may not exist.

Where possible, the pixel format used in the PNGs will be the same as the one in the binary texture. Some formats used by textures aren't available in PNG which means it may need to be converted. For example, textures allow RGBA16 (5/5/5/1) which requires a conversion to RGBA32 (8/8/8/8) for the PNG.

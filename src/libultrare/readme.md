This directory contains libultra files that have been modified by Rare.

Only the required files will be compiled and linked against. The file list is given by the makefile in the libultrare folder.

It is perhaps a bit awkward, but (unmodified) `#include`s should refer back to the original libultra folder.

Things to note (see makefile for latest):

- Some of the original assembly files were compiled with optimization, but currently all asm is `-O1`  
- Preprocessor `_FINALROM` is defined to correctly build a matching ROM; this only applies to `os/` files.
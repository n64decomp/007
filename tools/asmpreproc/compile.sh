#!/bin/bash
set -e
INPUT="$1"
OUTPUT="${INPUT%.c}.o"
INCLUDE="-I include -I include/libultra"

if [ "$IDO_RECOMP" == "YES" ]
then
    CC="$IRIX_ROOT/cc"
else
    CC="$QEMU_IRIX -silent -L $IRIX_ROOT $IRIX_ROOT/usr/bin/cc"
fi

CFLAGS="-Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -fullwarn -wlint -woff 819,820,852,821 -signed $INCLUDE -mips2 $LCDEFS"
AS="mips-linux-gnu-as"
ASFLAGS="-march=vr4300 -mabi=32 $INCLUDE"

python3 tools/asmpreproc/asm-processor.py -O2 "$INPUT" | $CC -c $CFLAGS tools/asmpreproc/include-stdin.c -o "$OUTPUT" -O2
python3 tools/asmpreproc/asm-processor.py -O2 "$INPUT" --post-process "$OUTPUT" --assembler "$AS $ASFLAGS" --asm-prelude tools/asmpreproc/prelude.s

mv $OUTPUT ${OUTPUT/src/build}

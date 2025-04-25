#!/bin/bash
set -o pipefail
INPUT=$(readlink -f "$1")

cd -- "$(dirname -- "${BASH_SOURCE[0]}")"
WD=$(pwd)
INPUT=${INPUT#"$WD"/}

OUTPUT="${INPUT%.*}.o"
rm -f "$OUTPUT"

CC="$MIPS_CC"  # ido 7.1 via recomp or qemu-irix
AS="mips-linux-gnu-as"
ASFLAGS="-march=vr4300 -mabi=32"
OPTFLAGS=$(grep 'COMPILE-FLAGS: ' $INPUT | sed 's#^.*COMPILE-FLAGS: ##' | sed 's#}$##')
ASMPFLAGS=$(grep 'ASMP-FLAGS: ' $INPUT | sed 's#^.*ASMP-FLAGS: ##' | sed 's#}$##')
ISET=$(grep 'COMPILE-ISET: ' $INPUT | sed 's#^.*COMPILE-ISET: ##' | sed 's#}$##')
if [[ -z "$OPTFLAGS" ]]; then
    OPTFLAGS="-g"
fi
CFLAGS="-Wab,-r4300_mul -G 0 -Xcpluscomm -fullwarn -wlint -woff 819,820,852,821 -signed -c"
if [[ -z "$ISET" ]]; then
    CFLAGS="$CFLAGS -mips2"
fi
if [[ "$OPTFLAGS" != *-KPIC* ]]; then
	CFLAGS="$CFLAGS -non_shared"
fi

set -e

if [[ "$2" == "python" ]]; then
    PROG="python3 ./build.py"
elif [[ "$2" == "rust-release" ]]; then
    PROG="./rust/target/release/asm-processor"
elif [[ "$2" == "rust-debug" ]]; then
    PROG="./rust/target/debug/asm-processor"
else
	echo "Usage: $0 input.c (python|rust-release|rust-debug)"
fi

$PROG --drop-mdebug-gptab $ASMPFLAGS $CC -- $AS $ASFLAGS -- $CFLAGS $OPTFLAGS $ISET -o "$OUTPUT" "$INPUT"

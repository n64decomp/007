#!/usr/bin/env bash
WD=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)

for A in "$@"; do
    OBJDUMPFLAGS="-srt"
    "$WD/compile-test.sh" "$A" python && mips-linux-gnu-objdump $OBJDUMPFLAGS "${A%.*}.o" > "${A%.*}.objdump"
done

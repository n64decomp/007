#!/bin/bash
if [ ! -f header.tmp ]; then
    echo -n -e \\x11\\x72 > header.tmp
fi
cat $1| tools/gzip --no-name --best | tail --bytes=+11 | head --bytes=-8 > $1.tmp
cat header.tmp $1.tmp > $2
rm $1.tmp

#!/bin/bash
echo -n -e \\x11\\x72 > header.tmp
cat $1| gzip --no-name --best | tail --bytes=+11 | head --bytes=-8 > $1.tmp
cat header.tmp $1.tmp > $1.rz
rm header.tmp $1.tmp

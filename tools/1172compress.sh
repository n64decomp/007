#!/bin/bash

usage()
{
    echo "Rare 1172 compression script"
    echo "Usage: $0 input output" 1>&2;
    exit 1;
}

if [ -z "$1" ]; then
    usage
fi;

if [ -z "$2" ]; then
    usage
fi;

# input file to compress
INPUT_FILE="$1"
# output file result
OUTPUT_FILE="$2"
# gzip command.
GZ=${GZ:-'gzipsrc/gzip'}

# check for decomp gzip, then fall back to system
if [ ! -f "${GZ}" ]; then
    # maybe user specified shell variable but it's not resolved as a file
    if ! command -v "${GZ}" &> /dev/null
    then
        # nope, maybe we're in the root directory
        if [ ! -f 'tools/gzipsrc/gzip' ]; then
            # nope, fallback to system gzip
            echo "decomp gzip bin not found, falling back to system gzip"
            GZ="gzip"
            if ! command -v "${GZ}" &> /dev/null
            then
                echo "can not find system gzip"
                exit 2
            fi
        else
            GZ='tools/gzipsrc/gzip'
        fi
    fi
fi

# make sure input file exists
if [ ! -f "${INPUT_FILE}" ]; then
    echo "can not read input file"
    usage
fi

# create
echo -n -e \\x11\\x72 > "${OUTPUT_FILE}"
cat "${INPUT_FILE}" | $GZ --no-name --best | tail --bytes=+11 | head --bytes=-8 >> "${OUTPUT_FILE}"

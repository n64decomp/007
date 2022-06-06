#!/bin/bash

usage()
{
    echo "Rare 1172 decompression script"
    echo "Usage: $0 input output" 1>&2;
    exit 1;
}

if [ -z "$1" ]; then
    usage
fi;

if [ -z "$2" ]; then
    usage
fi;

# input file to decompress
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
    echo "can not read input file: ${INPUT_FILE}"
    usage
fi

# explanation of commands:
# use process substitution to cat contents together to send to gzip.
# the first cat argument supplies the standard gzip header
# the next cat argument prints the input file, and chops the "1172" prefix
# this is sent to the gzip command for decompression, and the expected "unexpected end of file" error is filtered out

cat <(echo -n -e \\x1F\\x8B\\x08\\x00\\x00\\x00\\x00\\x00\\x02\\x03) <(cat "${INPUT_FILE}" | tail --bytes=+3) | $GZ --decompress 2> >(sed '/gzip: stdin: unexpected end of file/d' >&2) > "${OUTPUT_FILE}"
echo "Successfully Decompressed ${INPUT_FILE}"
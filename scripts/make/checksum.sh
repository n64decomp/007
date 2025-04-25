#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ -f "$SCRIPT_DIR"/local/checksum.sh ]; then
    "$SCRIPT_DIR"/local/checksum.sh "$1" "$2" "$3"
else
    "$SCRIPT_DIR"/default/checksum.sh "$1" "$2"
fi

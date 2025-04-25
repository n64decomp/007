#!/bin/bash

# arg1: make command passthrough, per make user manual.

MAKECMD=$1

if [ -z ${MAKECMD} ]; then echo "$0: missing argument: MAKECMD"; exit 1; fi

$MAKECMD -s -C tools >&2

retVal=$?
if [ $retVal -ne 0 ]; then
    echo "Failed to build tools"
fi
exit $retVal
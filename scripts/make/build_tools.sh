#!/bin/bash

# arg1: make command passthrough, per make user manual.

MAKECMD=$1

if [ -z "${MAKECMD}" ]; then echo "$0: missing argument: MAKECMD"; exit 1; fi

# Everything built under tools/ is native to the machine that built it. If the
# same checkout is then built on a different OS or CPU (e.g. switching the
# Docker image between amd64 and arm64, or building on the host after building
# in a container), the old binaries cannot run: the first compile fails with an
# exec error, and the next `make` reports success while compiling nothing,
# because no object is older than its source.
#
# So record the platform the tools were built for, and rebuild them when it no
# longer matches. `uname -sm` rather than `uname -m`, because macOS and Linux on
# Apple Silicon both report aarch64.
ARCH_STAMP=tools/.toolchain-arch
CUR_ARCH=$(uname -sm)

if [ -f ${ARCH_STAMP} ] && [ "$(cat ${ARCH_STAMP})" != "${CUR_ARCH}" ]; then
    echo "tools/ was built for '$(cat ${ARCH_STAMP})' but this machine is '${CUR_ARCH}' -- rebuilding tools" >&2
    rm -f tools/armips tools/n64cksum
    $MAKECMD -s -C tools/gzipsrc clean >&2
    $MAKECMD -s -C tools/ido5.3_recomp clean >&2
    # Not built by tools/Makefile, but just as architecture-specific.
    $MAKECMD -s -C tools/extractor clean >/dev/null 2>&1
    $MAKECMD -s -C tools/aaa_rip clean >/dev/null 2>&1
fi

$MAKECMD -s -C tools >&2

retVal=$?
if [ $retVal -ne 0 ]; then
    echo "Failed to build tools"
    exit $retVal
fi

echo "${CUR_ARCH}" > ${ARCH_STAMP}
exit 0

#!/bin/bash

# Print which toolchain is building this ROM, and keep a copy in BUILD_DIR.
#
# The Dockerfile pins its base image by digest, but `apt install` still resolves
# against the live archive, so two images built from the same Dockerfile can
# carry different compilers. This records the pinned base and the exact package
# versions that put bytes in the ROM, so "the ROM changed" and "the container
# changed" can be told apart after the fact.
#
# arg1: BUILD_DIR

BUILD_DIR=$1

if [ -z "${BUILD_DIR}" ]; then echo "$0: missing argument: BUILD_DIR"; exit 1; fi

manifest() {
    local base
    base=$(awk 'toupper($1) == "FROM" { print $2; exit }' Dockerfile 2>/dev/null)
    case "${base}" in
        "")          base='?' ;;
        *@sha256:*)  ;;
        *)           base="${base} (not pinned by digest)" ;;
    esac
    echo "base=${base}"
    echo "os=$(. /etc/os-release 2>/dev/null; echo "${PRETTY_NAME:-?}")"
    echo "kernel=$(uname -sm)"

    if ! command -v dpkg-query >/dev/null 2>&1; then
        echo "pkg=? (no dpkg)"
        return
    fi
    for p in gcc g++ binutils-mips-linux-gnu make python3 libc6; do
        v=$(dpkg-query -W -f='${Version}' "${p}" 2>/dev/null)
        echo "pkg:${p}=${v:-<not installed>}"
    done
}

mkdir -p "${BUILD_DIR}"
manifest | tee "${BUILD_DIR}/toolchain.txt"
exit 0

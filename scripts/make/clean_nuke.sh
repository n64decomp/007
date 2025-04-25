#!/bin/bash

# this is a partial extension of "make clean".
# this should be invoked along with regular make clean.
#
# arg 1: ALLOWED_COUNTRYCODE; this should be a string of country codes separated by space.
# arg 2: BUILD_DIR_BASE

ALLOWED_COUNTRYCODE=$1
BUILD_DIR_BASE=$2

# quote to allow space characters
if [ -z "${ALLOWED_COUNTRYCODE}" ]; then echo "$0: missing argument: ALLOWED_COUNTRYCODE"; exit 1; fi
if [ -z "${BUILD_DIR_BASE}" ]; then echo "$0: missing argument: BUILD_DIR_BASE"; exit 1; fi

echo "deleting build folders and files"

# dont quote to split on space characters
for cc in ${ALLOWED_COUNTRYCODE[@]}; do
    rm -r -f -d "${BUILD_DIR_BASE}/${cc}"
done

echo "deleting bin / rsp / asp"
rm -r -f -d bin/
rm -r -f -d assets/images/split/

# delete binary files according to current source control directory structure.
# fixes issues if directory structure changes ...
echo "deleting assets"
rm -r -f "assets/music/*.bin" "assets/obseg/bg/*.bin" "assets/obseg/brief/*.bin" "assets/obseg/chr/*.bin" "assets/obseg/gun/*.bin" "assets/obseg/prop/*.bin" "assets/obseg/setup/*.bin" "assets/obseg/setup/e/*.bin" "assets/obseg/setup/u/*.bin" "assets/obseg/setup/j/*.bin" "assets/obseg/stan/*.bin" "assets/obseg/text/*.bin" "assets/obseg/text/e/*.bin" "assets/obseg/text/u/*.bin" "assets/obseg/text/j/*.bin" "assets/ramrom/*.bin" "assets/ramrom/e/*.bin" "assets/ramrom/u/*.bin" "assets/ramrom/j/*.bin"
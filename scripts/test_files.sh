#!/bin/bash

# execute from the root source control directory.
result=$(basename "$PWD")
if [ $result = "scripts" ] ; then
    cd ..
fi

SRC=
CONTINUE_ON_ERROR=0
VERBOSE=0

usage() {
    echo "checks md5s generated from make/build_hashtable.sh"
    echo ""
    echo "This script should execute from root source control directory."
    echo ""
    echo "$0 usage:"
    echo ""
    echo "    $0 -i file [-c]"
    echo ""
    echo "    -c                       continue on error"
    exit 0;
}

[ $# -eq 0 ] && usage
while getopts "i:chv" arg; do
  case $arg in
    i)
        SRC="${OPTARG}"
      ;;
    c)
        CONTINUE_ON_ERROR=1
      ;;
    v)
        VERBOSE=1
      ;;
    h | *) # Display help.
      usage
      exit 0
      ;;
  esac
done

if [ "${SRC}" = "" ] ; then
    usage
fi

if [ ! -f "${SRC}" ]; then
    echo "File not found: ${SRC}"
    exit 1
fi

OLDIFS=$IFS
IFS=","
TMP=$(mktemp /tmp/ge_test_files.XXXXXX)
TMP2=$(mktemp /tmp/ge_test_files.XXXXXX)

while read MD5 SECTION FILE
do
    if [ ! -f "${SRC}" ]; then
        echo "File not found: ${SRC}"
        continue
    fi
    if [ -f $FILE ]; then
        mips-linux-gnu-objcopy -j "${SECTION}" -O binary "${FILE}" "${TMP}"
        ACTUAL=$(md5sum -b "${TMP}" | cut -c -32 | tr '[:upper:]' '[:lower:]')
        EXPECTED=$(echo "${MD5}" | tr '[:upper:]' '[:lower:]')
        FILENAME=$(echo $FILE | sed -E -e 's/build\/[uje]\/src\//src\//g;');
        VERSION=$(echo $FILE | sed -E -e 's/build\/([uje])\/.*/\1/g;');

        if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
            #if [ "${SECTION}" == ".data" ] || [ "${SECTION}" == ".rodata" ] ; then
            #    echo -e "\033[93m\033[1A";
            #fi
            echo "checksums differ, section'${SECTION}', file: '${FILE}'."
            echo "Comparing Files..."
            echo "Original                              | New"
            if [ -f "build/${VERSION}-match/${FILENAME}" ]; then
                mips-linux-gnu-objcopy -j "${SECTION}" -O binary "build/${VERSION}-match/${FILENAME}" "${TMP2}"
                (diff -y -W 80 --suppress-common-lines <(xxd -c8 $TMP2) <(xxd -c8 $TMP) && echo -e "\033[92mFiles Identical!") || \
                (\
                    echo -e "\033[91mDifference Found, Dumping assembly! (${FILE}New.mips)" && touch "${FILE}New.mips" &&  touch "${FILE}Match.mips" &&  \
                    mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents --line-numbers "build/${VERSION}-match/${FILENAME}" > "${FILE}Match.mips" && \
                    mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents --line-numbers "${FILE}" > "${FILE}New.mips" \
                );
            else
                echo -e "\033[93mNo Previously matching files to compare... Please run this test again on a matching build to generate."
            fi

            if [ ${CONTINUE_ON_ERROR} -eq 0 ] ; then
                IFS=$OLDIFS
                rm -f "${TMP}"
                rm -f "${TMP2}"
                exit 1
            fi
        else
            if [ ${VERBOSE} -eq 1 ]; then
                echo -e "\033[92mpass: section'${SECTION}' ${FILE}"
            fi
        fi
        echo -e -n "\033[m"
    fi
done < "${SRC}"

IFS=$OLDIFS
rm -f "${TMP}"
rm -f "${TMP2}"

exit 0

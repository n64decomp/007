#!/bin/bash

SRC=
CONTINUE_ON_ERROR=0
VERBOSE=0

usage() {
    echo "checks md5s generated from make_test_files_basis.sh"
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
    
        if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
            if [ $VERBOSE -eq 1 ]; then
                echo "checksums differ, section'${SECTION}', file: '${FILE}'. Actual=[${ACTUAL}], expected=[${EXPECTED}]"
            else
                echo -e "Mis-Match in $(echo $FILE | sed -E -e 's/build\/[uje]\/src\//src\//g;' -e 's/\.o/\.c/g')"
            fi
        
            if [ ${CONTINUE_ON_ERROR} -eq 0 ] ; then
                IFS=$OLDIFS
                rm -f "${TMP}"
                exit 1
            fi
        else
            if [ ${VERBOSE} -eq 1 ]; then
                echo "pass: section'${SECTION}' ${FILE}"
            fi
        fi
    fi
done < "${SRC}"

IFS=$OLDIFS
rm -f "${TMP}"

exit 0

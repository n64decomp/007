#!/bin/bash

ARG_VERSION=""
COUNTRY_CODE=""
LD_FILE=""
SECTION_START_LINE=
SECTION_END_LINE=

trap "exit 0" PIPE

usage() {
    echo "$0 usage:"
    echo ""
    echo "    -v        version. Supported options are: US,u, JP,j, EU,e"
    echo ""
    exit 0;
}
[ $# -eq 0 ] && usage
while getopts "hv:" arg; do
  case $arg in
    v) # version
        if [ "${OPTARG,,}" = "us" ]; then
            COUNTRY_CODE="u"
        elif [ "${OPTARG,,}" = "u" ]; then
            COUNTRY_CODE="u"
        elif [ "${OPTARG,,}" = "jp" ]; then
            COUNTRY_CODE="j"
        elif [ "${OPTARG,,}" = "j" ]; then
            COUNTRY_CODE="j"
        elif [ "${OPTARG,,}" = "eu" ]; then
            COUNTRY_CODE="e"
        elif [ "${OPTARG,,}" = "e" ]; then
            COUNTRY_CODE="e"
        fi
        
        ARG_VERSION="${OPTARG}"
      ;;
    h | *) # Display help.
      usage
      exit 0
      ;;
  esac
done

if [ "${COUNTRY_CODE}" = "" ] ; then 
    echo "version not supported: ${ARG_VERSION}"
    echo ""
    usage
fi

LD_FILE="ge007.${COUNTRY_CODE}.ld"

if [ ! -f "${LD_FILE}" ]; then
    echo "File not found: ${LD_FILE}"
    exit 1
fi

SECTION_START_LINE=$(grep -n -e '^\s*_bssSegmentStart\s*=' "${LD_FILE}" | cut -d: -f1)
SECTION_END_LINE=$(grep -n -e '^\s*_bssSegmentEnd\s*=' "${LD_FILE}" | cut -d: -f1)

digits_re='^[0-9]+$'
if ! [[ ${SECTION_START_LINE} =~ $digits_re ]] ; then
   echo "error: could not find start of .bss section in ld file" >&2; exit 1
fi
if ! [[ ${SECTION_END_LINE} =~ $digits_re ]] ; then
   echo "error: could not find end of .bss section in ld file" >&2; exit 1
fi

echo "reading lines ${SECTION_START_LINE}-${SECTION_END_LINE} in ${LD_FILE} ... "

echo "file" "size" "offset" | awk '{ printf "%-49s %-14s %-12s\n", $1, $2, $3}'

TOTAL_OFFSET=0

while read in; do {
    #echo "while: $in"
    
    # extract first .bss section size
    FILE_SECTION_SIZE=$(mips-linux-gnu-objdump -h "${in}" | grep '\.bss' | head -1 | cut -c 19-28)
    
    # if there's no .bss, set size to zero
    if [ -z "${FILE_SECTION_SIZE}" ] ; then
        FILE_SECTION_SIZE=0
    fi
    
    # strip out leading zeroes or bash gets confused when converting from hex
    FILE_SECTION_SIZE=$(echo ${FILE_SECTION_SIZE} | sed -E 's/^(0)*([0-9a-fA-F]+)/\2/')
    
    # convert from hex to decimal
    FILE_SECTION_SIZE=$((16#${FILE_SECTION_SIZE}))

    #echo "size: ${FILE_SECTION_SIZE}"
    FILE_SECTION_START_OFFSET=${TOTAL_OFFSET}

    TOTAL_OFFSET=$((${TOTAL_OFFSET} + ${FILE_SECTION_SIZE}))

    echo "${in}" ${FILE_SECTION_SIZE} ${FILE_SECTION_START_OFFSET} | awk '{ printf "%-49s 0x%-12x 0x%-12x\n", $1, $2, $3}'
    
    # exit if pipe is broken, e.g., command was run through `head`
    if [ $? -ne 0 ] ; then exit 0 ; fi

# subprocess:
# read ld file, from start line to end line
# pipe each line through sed and only accept (uncommented) lines starting with "build" path
# pipe through sed again and strip out everything except the path
# iterate on each line in the above while loop
} done < <(tail -n "+${SECTION_START_LINE}" "${LD_FILE}" | head -n "$((${SECTION_END_LINE}-${SECTION_START_LINE}+1))" | sed -n -E '/^\s+build/p' | sed -E 's/^\s*(build[^ ]+).*$/\1/')


echo "total" "-" ${TOTAL_OFFSET} | awk '{ printf "%-49s %-14s 0x%-12x\n", $1, $2, $3}'
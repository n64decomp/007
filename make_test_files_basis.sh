#!/bin/bash

COUNTRY_CODE=""
OUTFILE=""

usage() {
    echo "$0 usage:"
    echo ""
    echo "$0 -v u [-o results_file]"
    echo ""
    echo "    -o        output filename. Optional. Defaults to make_test_files_basis_out"
    echo "    -v        version. Supported options are: US,u, JP,j, EU,e"
    echo ""
    exit 0;
}

[ $# -eq 0 ] && usage
while getopts "o:hv:" arg; do
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
    o) # out file
        OUTFILE="${OPTARG}"
      ;;
    h | *) # Display help.
      usage
      exit 0
      ;;
  esac
done

if ! command -v "mips-linux-gnu-objcopy" &> /dev/null
then
    echo "command mips-linux-gnu-objcopy not found"
    exit 1
fi

if [ "${OUTFILE}" = "" ] ; then 
    OUTFILE="make_test_files_basis_out"
fi

TMP=$(mktemp /tmp/ge_test_files.XXXXXX)

rm -f "${OUTFILE}"

touch "${OUTFILE}"

# output format is simple csv, one entry per line
# 32 character md5, name of section extracted from ELF binary, and path to file relative from repo root (where this script is)
#
# escaped csv, quotes or commas in filenames are not supported.

for FILE in build/${COUNTRY_CODE}/src/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .text -O binary "${FILE}" "${TMP}"
    printf "%s,.text,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .code -O binary "${FILE}" "${TMP}"
    printf "%s,.code,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/src/game/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .text -O binary "${FILE}" "${TMP}"
    printf "%s,.text,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .code -O binary "${FILE}" "${TMP}"
    printf "%s,.code,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/assets/obseg/bg/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/assets/obseg/brief/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/assets/obseg/setup/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/assets/obseg/stan/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

for FILE in build/${COUNTRY_CODE}/assets/obseg/text/*.o
do
    echo "adding ${FILE}"
    
    mips-linux-gnu-objcopy -j .bss -O binary "${FILE}" "${TMP}"
    printf "%s,.bss,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .data -O binary "${FILE}" "${TMP}"
    printf "%s,.data,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
    
    mips-linux-gnu-objcopy -j .rodata -O binary "${FILE}" "${TMP}"
    printf "%s,.rodata,%s\n" $(md5sum -b "${TMP}" | cut -c -32) "${FILE}" >> "${OUTFILE}"
done

rm -f "${TMP}"
#!/bin/bash

SHA1SUM=$1
OUTCODE=$2

# quote to allow space
if [ -z "${SHA1SUM}" ]; then echo "$0: missing argument: SHA1SUM"; exit 1; fi
if [ -z "${OUTCODE}" ]; then echo "$0: missing argument: OUTCODE"; exit 1; fi

# no quotes on SHA1SUM to allow padding command line arguments from parent
${SHA1SUM} -c ge007.${OUTCODE}.sha1

retVal=$?
if [ $retVal -ne 0 ]; then
    echo -e "\n\n    ERROR: NOT MATCH!\n\n"
else
    echo -e "\n\n    MATCH!\n\n"
fi
exit $retVal
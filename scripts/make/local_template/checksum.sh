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
    echo -e "\n\n\033[1;41;37m"
    echo -e "                                                                                "
    echo -e "                                ERROR: NOT MATCH!                               "
    echo -e "                                                                                \033[m"
    echo -e "\n\n"

    RESPONSE=0
    read -t 5 -p "Do you want to check Source Files (y/n)? " choice
    case "$choice" in
    y|Y ) RESPONSE=1; ;;
    n|N ) RESPONSE=2; ;;
    * ) RESPONSE=3; ;;
    esac

    echo ""

    if [ $RESPONSE -eq 1 ]; then
        echo "Please wait while we determine which files are affected..."
        # scripts file relative to root source control directory
        ./scripts/test_files.sh -c -i scripts/ge007.${OUTCODE}-test_basis.csv
        echo "Dumping map diff..."
        diff --suppress-common-lines build/${OUTCODE}-match/ge007.${OUTCODE}.map build/${OUTCODE}/ge007.${OUTCODE}.map
    fi

else
    echo -e "\n\n\033[1;42;37m"
    echo -e "                                                                                "
    echo -e "                                     MATCH!                                     "
    echo -e "                                                                                \033[m"
    echo -e "\n\n"

    RESPONSE=0
    read -t 5 -p "Do you want to update the matching hashtable (recommended but slow) (y/n)?" choice
    case "$choice" in
    y|Y ) RESPONSE=1; ;;
    n|N ) RESPONSE=2; ;;
    * ) RESPONSE=3; ;;
    esac

    echo ""

    if [ $RESPONSE -eq 1 ]; then
        echo "Please wait while we rebuild the hashtable..."
        cp -r build/${OUTCODE}/* build/${OUTCODE}-match
        # cp build/${OUTCODE}/ge007.${OUTCODE}.map build/${OUTCODE}-match/ge007.$(OUTCODE).map
        # scripts file relative to root source control directory
        ./scripts/make/build_hashtable.sh -v ${OUTCODE} -o scripts/ge007.${OUTCODE}-test_basis.csv
    fi
fi

exit $retVal

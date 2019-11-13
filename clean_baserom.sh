#!/bin/bash
if [ -z "$1" ]; then
    DOALL="1"
    echo "Processing Everything"
fi

true="1"
if [ "$DOALL" == "1" ] || [ $1 == 'files' ]; then
    while IFS=, read -r offset size name compressed extract
    do
        echo "removing $name"
        rm -f $name
    done < filelist.u.csv
    while IFS=, read -r offset size name compressed extract
    do
        echo "removing $name"
        rm -f $name
    done < filediff.j.csv
fi

if [ "$DOALL" == "1" ] || [ $1 == 'images' ]; then
    while IFS=, read -r offset size name
    do
        echo "removing $name"
        rm -f $name
    done < imagelist.u.csv
fi

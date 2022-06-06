#!/bin/bash
if [ -z "$1" ]; then
    DOALL="1"
    echo "Processing Everything"
fi

true="1"
mkdir -p assets assets/font assets/images assets/images/split assets/music assets/ramrom assets/obseg assets/obseg/bg assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop assets/obseg/setup assets/obseg/setup/j assets/obseg/stan assets/obseg/text assets/obseg/text/j

if [ "$DOALL" == "1" ] || [ $1 == 'files' ]; then
    echo "Processing Files"
    while IFS=, read -r offset size name compressed extract
    do
        if [ "$extract" == "$true" ]; then
            if [ "$compressed" == "$true" ]; then
                echo "Extracting compressed $name, $size bytes..."
                dd bs=1 skip=$offset count=$size if=baserom.j.z64 of="${name}.temp" status=none
    	        GZ=gzip tools/1172inflate.sh "${name}.temp" "${name}"
                rm "${name}.temp"
            else
                echo "Extracting uncompressed $name, $size bytes..."
                dd bs=1 skip=$offset count=$size if=baserom.j.z64 of=$name status=none
                echo "Successfully Extracted $name"
            fi
        else
            echo "skip $name"
        fi
    done < filediff.j.csv
    #filediff.j.csv should follow pattern of:
    #offset,size,name,compressed,extract
    #formatting matters, no comments, no extra lines, unix line endings only
    #and always end with a newline
fi


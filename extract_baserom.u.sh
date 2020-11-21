#!/bin/bash
if [ -z "$1" ]; then
    DOALL="1"
    echo "Processing Everything"
fi

true="1"
mkdir assets assets/font assets/images assets/images/split assets/music assets/ramrom assets/obseg assets/obseg/bg assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop assets/obseg/setup assets/obseg/setup/u assets/obseg/stan assets/obseg/text assets/obseg/text/u

if [ "$DOALL" == "1" ] || [ $1 == 'files' ]; then
    echo "Processing Files"
    while IFS=, read -r offset size name compressed extract
    do
        if [ "$extract" == "$true" ]; then
            if [ "$compressed" == "$true" ]; then
                echo "Extracting compressed $name, $size bytes..."
                dd bs=1 skip=$offset count=$size if=baserom.u.z64 of=$name status=none
    	         # Add the gZip Header to a new file using the name given in command
    	        echo -n -e \\x1F\\x8B\\x08\\x00\\x00\\x00\\x00\\x00\\x02\\x03 > $name.temp
    	         # Add the contents of the compressed file minus the 1172 to the new file
    	        cat $name | tail --bytes=+3 >> $name.temp
    	         # copy the new file over the old compressed file
    	        cat $name.temp > $name.zip
    	         # decompress the Z file to the filename given in the command
    	        cat $name.zip | gzip --quiet --decompress > $name.bin
    	         # remove the compressed Z file
    	        rm $name.temp $name.zip $name
    	        echo "Successfully Decompressed $name"
            else
                echo "Extracting uncompressed $name, $size bytes..."
                dd bs=1 skip=$offset count=$size if=baserom.u.z64 of=$name status=none
                echo "Successfully Extracted $name"
            fi
        else
            echo "skip $name"
        fi
    done < filelist.u.csv
    #filelist.u.csv should follow pattern of:
    #offset,size,name,compressed,extract
    #formatting matters, no comments, no extra lines, unix line endings only
    #and always end with a newline
fi

if [ "$DOALL" == "1" ] || [ $1 == 'images' ]; then
    echo "Processing Imagess"
    while IFS=, read -r offset size name
    do
        echo "Extracting $name, $size bytes..."
        dd bs=1 skip=$offset count=$size if=baserom.u.z64 of=$name status=none
        echo "Successfully Extracted $name"
    done < imagelist.u.csv
    #imageslist.u.csv should follow pattern of:
    #offset,size,name
    #formatting matters, no comments, no extra lines, unix line endings only
    #and always end with a newline
fi

for file in assets/font/*.bmp
do
    #add the BMP header to the raw font image data
    sed -i -e '1 e cat font_bmp_header.bin' $file
    #extract the width and height from the filename
    width=$((10#$(echo ${file: (( ${#file} - 11)) :2})))
    height=$((10#$(echo ${file: (( ${#file} - 6)) :2})))
    #invert the height, as the fonts are upside-down
    height=$((256 - $height))
    #convert the width and height from decimal to hexadecimal
    printf -v width "%X" "$width"
    printf -v height "%X" "$height"
    #write the width and height values to the BMP header
    echo -n -e \\x$width | dd conv=notrunc bs=1 seek=18 of=$file
    echo -n -e \\x$height | dd conv=notrunc bs=1 seek=22 of=$file
    echo -n -e \\xFF\\xFF\\xFF | dd conv=notrunc bs=1 seek=23 of=$file
done

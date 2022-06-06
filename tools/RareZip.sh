#!/bin/bash
if [ $1 == '--decompress' ]
then
	 # Add the gZip Header to a new file using the name given in command
	echo -n -e \\x1F\\x8B\\x08\\x00\\x00\\x00\\x00\\x00\\x02\\x03 > $2
	 # Add the contents of the compressed file minus the 1172 to the new file
	cat $2Z | tail --bytes=+3 >> $2
	 # copy the new file over the old compressed file
	cat $2 > $2Z
	 # decompress the Z file to the filename given in the command
	cat $2Z | gzip --decompress > $2
	 # remove the compressed Z file
	rm $2Z
	echo Successfully Decompressed $2

elif [ $1 == '-?' ] || [ $1 == '-help' ]
then
	echo Compress File and remove extra Data
	echo Usage:
	echo -e "\t RareZip [--decompress] File"
	echo -e "\t Example:"
	echo -e "\t\t RareZip Pppk"
	echo -e "\t Output:"
	echo -e "\t\t PppkZ (compressed)"
	echo -e "\t Example:"
	echo -e "\t\t RareZip --decompress Pppk"
	echo -e "\t Output:"
	echo -e "\t\t Pppk (uncompressed)"
else
	 # Add 1172 header to new Z file
	echo -n -e \\x11\\x72 > $1Z
	 # Compress file given in command and trim then append to 1172 Z file
	gzip --no-name -c $1 | tail --bytes=+11 | head --bytes=-8 >> $1Z
	 # Remove original file, can be recovered using decompress
	rm $1
	echo Successfully Compressed $1
fi

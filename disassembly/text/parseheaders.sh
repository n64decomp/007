#!/bin/bash
#FILENAME="LtraE"
for FILENAME in *.asm ; do
	echo "parsing $FILENAME"
	FILENAME=$(echo "$FILENAME" | cut -d "." -f1)
	bass -sym $FILENAME.sym $FILENAME.asm
	#compressfile here to $FILENAME.rz


	rm $FILENAME.inc
	declare -i LINENUM=1
	while read CURRENTLINE ; do
		let "LINENUM  += 1"
		OFFSET=$(echo "$CURRENTLINE" | cut -d " " -f1)
		NAME=$(echo "$CURRENTLINE" | cut -d " " -f2)
		echo "define "$NAME"($"$OFFSET")" >> $FILENAME.inc
	done <"$FILENAME.sym"
done

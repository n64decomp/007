#!/bin/bash
declare -i LINENUM=1
	rm -rf out
	mkdir out
	mkdir out/bg
	mkdir out/ob
	mkdir out/m
	mkdir out/chr
	mkdir out/props
	mkdir out/g_view
	mkdir out/ramrom
	mkdir out/text
	mkdir out/font
	mkdir out/unk
	mkdir out/images
while read CURRENTLINE ; do
	let "LINENUM  += 1"
	NEXTLINE="`sed -n "$LINENUM"p filelist.txt`"
	STARTOFFSET=$(echo "$CURRENTLINE" | cut -d " " -f1)
	ENDOFFSET=$(echo "$NEXTLINE" | cut -d " " -f1)
	FILENAME=$(echo "$CURRENTLINE" | cut -d " " -f2)
	#echo "line="$LINENUM" soffset="$STARTOFFSET" eoffset="$ENDOFFSET" filename="$FILENAME
	echo "filename="$FILENAME
	#sleep 1
	D_SOFFSET=$(printf "%d\n" $STARTOFFSET)
	D_EOFFSET=$(printf "%d\n" $ENDOFFSET)
	let "D_FLENGTH= D_EOFFSET-D_SOFFSET"
	#echo $D_SOFFSET $D_EOFFSET $D_FLENGTH
	dd if=GoldenEye.rom bs=4096 skip=$D_SOFFSET count=$D_FLENGTH iflag=skip_bytes,count_bytes of=out/$FILENAME
done <filelist.txt
bass -sym rodata.sym rodata.asm
cat rodata.bin| gzip --no-name --best | tail --bytes=+11 | head --bytes=-8 > rodata.rz
#vbindiff rodata.rz 021990.rz
rm rodata.inc

#declare -i LINENUM=1
while read CURRENTLINE ; do
	#let "LINENUM  += 1"
	OFFSET=$(echo "$CURRENTLINE" | cut -d " " -f1)
	NAME=$(echo "$CURRENTLINE" | cut -d " " -f2)
	echo "constant "$NAME"($"$OFFSET")" >> rodata.inc
done <"rodata.sym"

#echo "include \"rodata.inc\"" >>$DIRNAME.inc

rm rodata.sym
#rm rodata.bin

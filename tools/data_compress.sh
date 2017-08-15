#!/bin/bash
echo "patching $1"
echo "extract data segment"
echo "one byte at a time is slow, sorry"
echo "if you changed size of data segment, change count here"
dd skip=12582912 count=247120 if=$1 of=data_seg bs=1

echo "truncate $1 to 0xC00000"
cat $1 | head --bytes=12582912 > $1.tmp

echo "compress data segment"
tools/1172compress.sh data_seg data_seg.rz


echo "inject data segment"
RZSIZE=$(stat -c%s "data_seg.rz")
echo "size=$RZSIZE"

echo "one byte at a time is slow, sorry"
dd if=data_seg.rz of=$1.tmp obs=1 seek=137616 conv=notrunc
rm data_seg data_seg.rz

mv $1.tmp $1


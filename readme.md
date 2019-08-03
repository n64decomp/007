This is a working Goldeneye 007 decompilation! 


The only requirements for Ubuntu 16.04 and 18.04 should be 
```
sudo apt install binutils-mips-linux-gnu make
```
Place a USA rom in project root named 
```
baserom.u.z64
```
followed by
```
./extract_baserom.sh && make
```

DO NOT USE make -j# it will break things!!!!!!!!!

If you are upgrading from an old repo, run
```
./clean_baserom.sh && ./extract_baserom.sh && make clean && make
```

The extract and clean scripts support switches:
```
name_baserom.sh files
name_baserom.sh images
```
to do just one or the other, default is both


This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

GE and PD documentation made by Zoinkity

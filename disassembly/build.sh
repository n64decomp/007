#make and compress resources
cd ob
./make_text_rz.sh
cd ../

#build and compress rodata
cd rodata
./make_rodata_rz.sh
cd ../ 

#third package the rom
bass -sym GE007.sym GE007.rom.asm

vbindiff ./GE007.n64 ~/n64/007\ -\ GoldenEye.z64


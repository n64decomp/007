//arch n64.cpu
//endian msb
//output "rodata.bin", create
base origin()
rodata_rom_offset:

base $80020D90
rodata_start:
//insert rsp.bin, "rsp.bin"

//compressed binary for now
//will probably have to make rodata itself a project 
//then have a tool to parse symtable into rodata.inc and matching rodata.rz
insert rodata_rz, "021990.rz"

base $8005D2E0
rodata_end:



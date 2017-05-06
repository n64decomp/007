//arch n64.cpu
//endian msb
//output "rodata.bin", create
base $80020D90
rodata_start:
//insert rsp.bin, "rsp.bin"

//compressed binary for now
insert rodata_rz, "021990.rz"

base $8005D2E0
rodata_end:



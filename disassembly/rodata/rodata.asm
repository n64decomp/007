arch n64.cpu
endian msb
output "rodata.bin", create
base $80020D90
insert rsp.bin, "rsp.bin"

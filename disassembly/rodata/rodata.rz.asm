base origin()
seg_rodata_rom_start:

include "rodata.inc"
//insert rodata_rz, "021990.rz"
dh $1172;insert rodata_rz, "rodata.rz"

align(0x33590)
//insert padding,"pad_to_33590"

base origin()
seg_rodata_rom_end:


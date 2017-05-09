base origin()
seg_rodata_rom_start:

include "rodata.inc"
insert rodata_rz, "021990.rz"

insert padding,"pad_to_33590"

base origin()
seg_rodata_rom_end:

variable seg_rodata_rom_size(seg_rodata_rom_end-seg_rodata_rom_start)

arch n64.cpu
endian msb
output "GE007.n64", create
include "lib/N64.INC"
include "lib/GE007.inc"
define romsize($C00000)
fill {romsize}, $FF
origin $00000000;rom_file_start:;rom_start:
include "code/bss.inc"
include "code/stack.inc"
include "rom/romheader.asm"
include "code/boot.asm"
include "rodata/rodata.rz.asm"
include "code/rarezip.asm"
include "code/tlb_code.asm"
include "unk/unknown.asm"
include "ramrom/ramrom.asm"
include "font/fonts.asm"
include "m/music.asm"
include "ob/seg_ob.asm"

include "images/images.asm"

rom_end:;base {romsize};rom_file_end:






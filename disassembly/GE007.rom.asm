arch n64.cpu
endian msb
output "GE007.n64", create
include "lib/N64.INC"
define romsize($C00000)
fill {romsize}, $FF
origin $00000000;rom_file_start:;rom_start:
include "code/bss.asm"
include "code/stack.asm"
include "rom/romheader.asm"
include "code/boot.asm"
include "rodata/rodata.rz.asm"
include "code/rarezip.asm"
include "code/tlb_code.asm"
include "unk/unknown.asm"
include "ramrom/ramrom.asm"
include "font/fonts.asm"
include "m/music.asm"
include "bg/bg.asm"
include "chr/chr.asm"
include "g_view/g_items.asm"
include "props/props.asm"
include "bg/Tbg.asm"
include "brief/brief.asm"
include "bg/setup.asm"
include "text/text.asm"

ob_end:
insert ob_end.seg, "ob/ob_end.seg", (origin() - $008f7de0)

include "images/images.asm"

rom_end:;base {romsize};rom_file_end:






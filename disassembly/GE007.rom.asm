arch n64.cpu
endian msb
output "GE007.n64", create
fill $00c00000, $FF
include "lib/N64.INC"
origin $00000000

include "rom/romheader.asm"
include "code/boot.asm"
include "rodata/rodata.inc"
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

include "code/bss.asm"
include "code/80300000.asm"



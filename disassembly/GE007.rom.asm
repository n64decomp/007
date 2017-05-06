arch n64.cpu
endian msb
output "GE007.n64", create
include "lib/N64.INC"
origin $00000000

include "rom/romheader.asm"
include "code/boot.asm"
include "rodata/rodata.asm"
include "code/rarezip.asm"
include "code/tlb_code.asm"
include "unk/unknown.asm"
include "ramrom/ramrom.asm"

include "bss/bss.asm"
include "bss/80300000.asm"

insert retailrom_raw, "GoldenEye007.z64", origin()


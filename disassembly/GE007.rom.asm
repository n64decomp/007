arch n64.cpu
endian msb
output "GE007.n64", create
include "N64.INC"
origin $00000000

include "rom/romheader.asm"
include "boot.asm"

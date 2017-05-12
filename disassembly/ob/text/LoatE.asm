arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LoatE.bin", create

base $00000000
seg_LoatE_start:
seg_LoatE_header_start:

ptr_seg_LoatE_start:
 dw seg_LoatE_start

seg_LoatE_header_end:
seg_LoatE_strings_start:

seg_LoatE_strings_end:
seg_LoatE_end:
align(32)

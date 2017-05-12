arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LashE.bin", create

base $00000000
seg_LashE_start:
seg_LashE_header_start:

ptr_seg_LashE_start:
 dw seg_LashE_start

seg_LashE_header_end:
seg_LashE_strings_start:

seg_LashE_strings_end:
seg_LashE_end:
align(32)

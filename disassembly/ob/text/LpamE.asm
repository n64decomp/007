arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LpamE.bin", create

base $00000000
seg_LpamE_start:
seg_LpamE_header_start:

ptr_seg_LpamE_start:
 dw seg_LpamE_start

seg_LpamE_header_end:
seg_LpamE_strings_start:

seg_LpamE_strings_end:
seg_LpamE_end:
align(32)

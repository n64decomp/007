arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LeldE.bin", create

base $00000000
seg_LeldE_start:
seg_LeldE_header_start:

ptr_seg_LeldE_start:
 dw seg_LeldE_start

seg_LeldE_header_end:
seg_LeldE_strings_start:

seg_LeldE_strings_end:
seg_LeldE_end:
align(32)

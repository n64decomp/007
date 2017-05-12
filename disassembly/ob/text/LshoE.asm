arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LshoE.bin", create

base $00000000
seg_LshoE_start:
seg_LshoE_header_start:

ptr_seg_LshoE_start:
 dw seg_LshoE_start

seg_LshoE_header_end:
seg_LshoE_strings_start:

seg_LshoE_strings_end:
seg_LshoE_end:
align(32)

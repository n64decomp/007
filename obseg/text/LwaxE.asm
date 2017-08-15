arch n64.cpu
endian msb
include "../BASS.INC"
output "LwaxE.bin", create

base $00000000
seg_LwaxE_start:
seg_LwaxE_header_start:

ptr_seg_LwaxE_start:
 dw seg_LwaxE_start

seg_LwaxE_header_end:
seg_LwaxE_strings_start:

seg_LwaxE_strings_end:
seg_LwaxE_end:
align(32)

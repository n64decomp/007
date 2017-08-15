arch n64.cpu
endian msb
include "../BASS.INC"
output "LleeE.bin", create

base $00000000
seg_LleeE_start:
seg_LleeE_header_start:

ptr_seg_LleeE_start:
 dw seg_LleeE_start

seg_LleeE_header_end:
seg_LleeE_strings_start:

seg_LleeE_strings_end:
seg_LleeE_end:
align(32)

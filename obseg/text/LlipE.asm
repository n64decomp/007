arch n64.cpu
endian msb
include "../BASS.INC"
output "LlipE.bin", create

base $00000000
seg_LlipE_start:
seg_LlipE_header_start:

ptr_seg_LlipE_start:
 dw seg_LlipE_start

seg_LlipE_header_end:
seg_LlipE_strings_start:

seg_LlipE_strings_end:
seg_LlipE_end:
align(32)

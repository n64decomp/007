arch n64.cpu
endian msb
include "../BASS.INC"
output "LlueE.bin", create

base $00000000
seg_LlueE_start:
seg_LlueE_header_start:

ptr_seg_LlueE_start:
 dw seg_LlueE_start

seg_LlueE_header_end:
seg_LlueE_strings_start:

seg_LlueE_strings_end:
seg_LlueE_end:
align(32)

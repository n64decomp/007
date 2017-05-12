arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LearE.bin", create

base $00000000
seg_LearE_start:
seg_LearE_header_start:

ptr_seg_LearE_start:
 dw seg_LearE_start

seg_LearE_header_end:
seg_LearE_strings_start:

seg_LearE_strings_end:
seg_LearE_end:
align(32)

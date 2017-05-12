arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LameE.bin", create

base $00000000
seg_LameE_start:
seg_LameE_header_start:

ptr_seg_LameE_start:
 dw seg_LameE_start

seg_LameE_header_end:
seg_LameE_strings_start:

seg_LameE_strings_end:
seg_LameE_end:
align(32)

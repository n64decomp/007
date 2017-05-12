arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LlenE.bin", create

base $00000000
seg_LlenE_start:
seg_LlenE_header_start:

ptr_seg_LlenE_start:
 dw seg_LlenE_start

seg_LlenE_header_end:
seg_LlenE_strings_start:

seg_LlenE_strings_end:
seg_LlenE_end:
align(32)

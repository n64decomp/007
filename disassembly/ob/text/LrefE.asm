arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LrefE.bin", create

base $00000000
seg_LrefE_start:
seg_LrefE_header_start:

ptr_seg_LrefE_start:
 dw seg_LrefE_start

seg_LrefE_header_end:
seg_LrefE_strings_start:

seg_LrefE_strings_end:
seg_LrefE_end:
align(32)

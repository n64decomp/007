arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LdishE.bin", create

base $00000000
seg_LdishE_start:
seg_LdishE_header_start:

ptr_seg_LdishE_start:
 dw seg_LdishE_start

seg_LdishE_header_end:
seg_LdishE_strings_start:

seg_LdishE_strings_end:
seg_LdishE_end:
align(32)


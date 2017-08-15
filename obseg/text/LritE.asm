arch n64.cpu
endian msb
include "../BASS.INC"
output "LritE.bin", create

base $00000000
seg_LritE_start:
seg_LritE_header_start:

ptr_seg_LritE_start:
 dw seg_LritE_start

seg_LritE_header_end:
seg_LritE_strings_start:

seg_LritE_strings_end:
seg_LritE_end:
align(32)

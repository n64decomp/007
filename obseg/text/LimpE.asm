arch n64.cpu
endian msb
include "../BASS.INC"
output "LimpE.bin", create

base $00000000
seg_LimpE_start:
seg_LimpE_header_start:

ptr_seg_LimpE_start:
 dw seg_LimpE_start

seg_LimpE_header_end:
seg_LimpE_strings_start:

seg_LimpE_strings_end:
seg_LimpE_end:
align(32)

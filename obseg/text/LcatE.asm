arch n64.cpu
endian msb
include "../BASS.INC"
output "LcatE.bin", create

base $00000000
seg_LcatE_start:
seg_LcatE_header_start:

ptr_seg_LcatE_start:
 dw seg_LcatE_start

seg_LcatE_header_end:
seg_LcatE_strings_start:

seg_LcatE_strings_end:
seg_LcatE_end:
align(32)

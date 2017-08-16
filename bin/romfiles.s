.section .romfiles, "a"

.global unknown
unknown:
.incbin "bin/ge007.u.117880.unknown.bin"
unknown_end:

.global Globalimagetable
Globalimagetable:
.incbin "bin/ge007.u.29D160.Globalimagetable.bin"
Globalimagetable_end:

.global Globalimagetable_commandblock
Globalimagetable_commandblock:
.incbin "bin/ge007.u.29E560.Globalimagetable_commandblock.bin"
Globalimagetable_commandblock_end:

.global unknown1
unknown1:
.incbin "bin/ge007.u.2A0560.unknown1.bin"
unknown1_end:

.global unknown2
unknown2:
.incbin "bin/ge007.u.2A4D50.unknown2.bin"
unknown2_end:

.global unknown3
unknown3:
.incbin "bin/ge007.u.2AE280.unknown3.bin"
unknown3_end:

.section .romfiles, "a"

.global unknown
unknown:
.incbin "bin/ge007.u.117880.unknown.bin"
unknown_end:

.global unknown117940
unknown117940:
.incbin "bin/ge007.u.117940.unknown.bin"
unknown117940_end:

.global unknown123040
unknown123040:
.incbin "bin/ge007.u.123040.unknown.bin"
unknown123040_end:

.global animation_table
animation_table:
.incbin "bin/animationtable_entries.bin"
animation_table_end:

.global animation_data
animation_data:
.incbin "bin/animationtable_data.bin"
animation_data_end:

.global Globalimagetable
Globalimagetable:
.incbin "bin/ge007.u.29D160.Globalimagetable.bin"
Globalimagetable_end:

.global Globalimagetable_commandblock
Globalimagetable_commandblock:
.incbin "bin/ge007.u.29E560.Globalimagetable_commandblock.bin"
Globalimagetable_commandblock_end:

.global unknown2
unknown2:
.incbin "bin/ge007.u.2A4D50.unknown2.bin"
unknown2_end:

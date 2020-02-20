.section .romfiles, "a"
.global _GlobalimagetableSegmentRomEnd
_GlobalimagetableSegmentRomEnd:

.global _GlobalimagetablecmdblkSegmentRomStart
_GlobalimagetablecmdblkSegmentRomStart:
.incbin "assets/ge007.u.29E560.Globalimagetable_commandblock.bin"
.global _GlobalimagetablecmdblkSegmentRomEnd
_GlobalimagetablecmdblkSegmentRomEnd:

.global unknown2
unknown2:
.incbin "assets/ge007.u.2A4D50.usedby7F008DE4.bin"
.global unknown2_end
unknown2_end:

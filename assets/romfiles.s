.section .romfiles, "a"

.global _jfontdlSegmentStart
_jfontdlSegmentStart:
.incbin "assets/ge007.u.117880.jfont_dl.bin"
.global _jfontdlSegmentEnd
_jfontdlSegmentEnd:

.global _jfontcharSegmentStart
_jfontcharSegmentStart:
.ifdef VERSION_US
.incbin "assets/ge007.u.117940.jfont_chardata.bin"
.endif
.ifdef VERSION_JP
.incbin "assets/ge007.j.118660.jfont_chardata.bin"
.endif
.global _jfontcharSegmentEnd
_jfontcharSegmentEnd:

.global _efontcharSegmentStart
_efontcharSegmentStart:
.incbin "assets/ge007.u.123040.efont_chardata.bin"
.global _efontcharSegmentEnd
_efontcharSegmentEnd:

.global _animation_tableSegmentRomStart
_animation_tableSegmentRomStart:
.incbin "assets/animationtable_entries.bin"
.global _animation_tableSegmentRomEnd
_animation_tableSegmentRomEnd:

.global _animation_dataSegmentRomStart
_animation_dataSegmentRomStart:
.incbin "assets/animationtable_data.bin"
.global _animation_dataSegmentRomEnd
_animation_dataSegmentRomEnd:
.global _GlobalimagetableSegmentRomStart
_GlobalimagetableSegmentRomStart:

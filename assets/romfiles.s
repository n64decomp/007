.section .romfiles, "a"

.global _jfontdlSegmentStart
_jfontdlSegmentStart:
.incbin "assets/ge007.u.117880.jfont_dl.bin"
.global _jfontdlSegmentEnd
_jfontdlSegmentEnd:

.global _jfontcharSegmentStart
_jfontcharSegmentStart:
.incbin "assets/ge007.u.117940.jfont_chardata.bin"
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

 # enum	image_format, mappedto_2
.set rgba, 0
.set yuv, 1
.set ci, 2
.set ia, 3
.set i, 4

 # ---------------------------------------------------------------------------

 # enum	image_bitdepth,	mappedto_3
.set D_4BIT, 0
.set D_8BIT, 1
.set D_16BIT, 2
.set D_32BIT, 3

 # ---------------------------------------------------------------------------

 # enum	cm_flags, mappedto_4
.set clamp, 1
.set mirror, 2

.macro texture_entry index, width, height, level, format, depth, flagsS, flagsT, pad
.word \index
.byte \width
.byte \height
.byte \level
.byte \format
.byte \depth
.byte \flagsS
.byte \flagsT
.byte \pad
.endm


.global _GlobalimagetableSegmentRomStart
_GlobalimagetableSegmentRomStart:
.incbin "assets/ge007.u.29D160.Globalimagetable.bin"
texture_entry 0x858, 0x36, 0x36, 3, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x879, 0x40, 0x20, 7, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x87A, 0x40, 0x40, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0xCE, 0x40, 0x20, 7, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x87B, 0x20, 0x20, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x87C, 0x20, 0x20, 0, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x5C3, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x87D, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x5C4, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x87E, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x87F, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x5C6, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x5C7, 0x20, 0x20, 6, rgba, D_16BIT, mirror, mirror, 0
texture_entry 0x87A, 0x40, 0x40, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x878, 0x30, 0x30, 6, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x880, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x881, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x882, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x883, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x884, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x885, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x886, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x887, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x888, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x889, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x88A, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x8B5, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x8B6, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x850, 0x10, 0x20, 6, rgba, D_32BIT, 0, 0, 0
texture_entry 0x857, 0x10, 0x20, 6, rgba, D_32BIT, 0, 0, 0
texture_entry 0x856, 0x20, 0x20, 0, rgba, D_32BIT, 0, 0, 0
texture_entry 0x8B7, 5, 0xC, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x8B8, 5, 0x1C, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x877, 6, 0x14, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x876, 6, 0x18, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x875, 8, 0x15, 0, rgba, D_32BIT, 0, mirror, 0
texture_entry 0x871, 7, 0x16, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x872, 0xE, 0xE, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x873, 0xE, 0x12, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x874, 5, 0xF, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x8B9, 5, 0xC, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x8BA, 0xE, 0xE, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x8BE, 0xE, 0xE, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x8BB, 0xE, 0xE, 0, rgba, D_32BIT, mirror, mirror, 0
texture_entry 0x9A0, 7, 0x16, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x8BC, 0x20, 0x20, 0, rgba, D_32BIT, 0, 0, 0
texture_entry 0x8BD, 0x20, 0x20, 0, rgba, D_32BIT, 0, 0, 0
texture_entry 0x292, 0x20, 1, 6, ia, D_8BIT, 0, 0, 0
texture_entry 0x28E, 0x36, 0x36, 3, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x88B, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x88C, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x88D, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x88E, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x88F, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x890, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x891, 0x80, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x892, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x893, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x894, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x895, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x4A1, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x896, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x897, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x4A2, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x4A3, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x898, 0x10, 0x10, 5, i, D_8BIT, 0, 0, 0
texture_entry 0x246, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x247, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x248, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x899, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x89A, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x89B, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x89C, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x245, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x89D, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x89E, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x8B3, 0x40, 0x40, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AF, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8B0, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8B1, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8B2, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AB, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AC, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AD, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AE, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8AA, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x89F, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8A0, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8A1, 0x20, 0x20, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x8A2, 0x20, 0x20, 6, i, D_8BIT, 0, 0, 0
texture_entry 0x8A3, 0x20, 0x20, 6, i, D_8BIT, 0, 0, 0
texture_entry 0x8A4, 0x20, 0x20, 6, i, D_8BIT, 0, 0, 0
texture_entry 0x8A5, 0x20, 0x20, 6, i, D_8BIT, 0, 0, 0
texture_entry 0x8A6, 0x80, 0x30, 0, i, D_8BIT, 0, mirror, 0
texture_entry 0x8A7, 0x10, 0x10, 5, i, D_8BIT, 0, 0, 0
texture_entry 0x8A8, 0x10, 0x10, 5, i, D_8BIT, 0, 0, 0
texture_entry 0x8A9, 0x10, 0x10, 5, i, D_8BIT, 0, 0, 0
texture_entry 0x8D7, 0x36, 0x36, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0x345, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0x8B4, 0x40, 0x40, 0, ia, D_8BIT, 0, 0, 0
texture_entry 0x5E4, 0x40, 0x40, 0, i, D_8BIT, 0, 0, 0
texture_entry 0x5E5, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0, 0x20, 0x1C, 0, rgba, D_32BIT, 0, mirror, 0
texture_entry 2, 0x20, 0x1C, 0, rgba, D_32BIT, 0, mirror, 0
texture_entry 3, 0x7A, 0x12, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 1, 0xF, 0xF, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 4, 0x14, 0x14, 0, ia, D_8BIT, mirror, mirror, 0
texture_entry 0xA47, 0x10, 0x10, 0, i, D_8BIT, 0, 0, 0
texture_entry 0xC8, 0x20, 0x20, 6, rgba, D_16BIT, 0, 0, 0
texture_entry 0xA2A, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA2B, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA2C, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA2D, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA32, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA33, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA34, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA35, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA36, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA37, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA38, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA39, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA2E, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA2F, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA30, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA31, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA48, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA49, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4A, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4B, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4C, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4D, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4E, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA4F, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA50, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA51, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA52, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA53, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA54, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA55, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA56, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA57, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA58, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA59, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5A, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5B, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5C, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5D, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5E, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA5F, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA60, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA61, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA62, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA63, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA64, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA65, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA66, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA67, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA68, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA69, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6A, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6B, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6C, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6D, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6E, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA6F, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA7A, 0x41, 0x43, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA7B, 0x41, 0x43, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA7C, 0x41, 0x43, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA7D, 0x41, 0x43, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA86, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA85, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA83, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA84, 0x41, 0x41, 7, i, D_4BIT, mirror, mirror, 0
texture_entry 0xA20, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA16, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA12, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA19, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA14, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA1E, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA1B, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA24, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA17, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA15, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA18, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA1A, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA7E, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA7F, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA80, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA81, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
texture_entry 0xA87, 0x44, 0x2C, 0, i, D_8BIT, mirror, mirror, 0
.word 0
.word 0
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

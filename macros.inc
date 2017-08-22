






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

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .music

.global _sfxctlSegmentRomStart
_sfxctlSegmentRomStart:
 .incbin "assets/music/sfx.ctl"
.global _sfxctlSegmentRomEnd
_sfxctlSegmentRomEnd:

.global _sfxtblSegmentRomStart
_sfxtblSegmentRomStart:
 .incbin "assets/music/sfx.tbl"
.global _sfxtblSegmentRomEnd
_sfxtblSegmentRomEnd:

.global _instrumentsctlSegmentRomStart
_instrumentsctlSegmentRomStart:
 .incbin "assets/music/instruments.ctl"
.global _instrumentsctlSegmentRomEnd
_instrumentsctlSegmentRomEnd:

.global _instrumentstblSegmentRomStart
_instrumentstblSegmentRomStart:
 .incbin "assets/music/instruments.tbl"
.global _instrumentstblSegmentRomEnd
_instrumentstblSegmentRomEnd:

.global _musicsampletblSegmentRomStart
_musicsampletblSegmentRomStart:
.global number_music_samples
number_music_samples:
 .half (table_music_data_end - number_music_samples)/8
 .half 0x0000
number_music_samples_end:


.macro music_table_entry name sized
 .word \name - number_music_samples
 .half end_d_\name - d_\name
 .half end_\name - \name
.endm

.global table_music_data
table_music_data:
 music_table_entry Mno_music
 music_table_entry Msolo_death_abrev
 music_table_entry Mintro_eye
 music_table_entry Mtrain
 music_table_entry Mdepot
 music_table_entry Mjungle_unused
 music_table_entry Mcitadel
 music_table_entry Mfacility
 music_table_entry Mcontrol
 music_table_entry Mdam
 music_table_entry Mfrigate
 music_table_entry Marchives
 music_table_entry Msilo
 music_table_entry Mjungle_perimeter_unused
 music_table_entry Mstreets
 music_table_entry Mbunker1
 music_table_entry Mbunker2
 music_table_entry Mstatue
 music_table_entry Melevator_control
 music_table_entry Mcradle
 music_table_entry Mnull1
 music_table_entry Melevator_wc
 music_table_entry Megyptian
 music_table_entry Mfolders
 music_table_entry Mwatchmusic
 music_table_entry Maztec
 music_table_entry Mwatercaverns
 music_table_entry Mdeathsolo
 music_table_entry Msurface2
 music_table_entry Mtrainx
 music_table_entry Mnull2
 music_table_entry Mfacilityx
 music_table_entry Mdepotx
 music_table_entry Mcontrolx
 music_table_entry Mwatercavernsx
 music_table_entry Mdamx
 music_table_entry Mfrigatex
 music_table_entry Marchivesx
 music_table_entry Msilox
 music_table_entry Mnull3
 music_table_entry Mstreetsx
 music_table_entry Mbunker1x
 music_table_entry Mbunker2x
 music_table_entry Mjunglex
 music_table_entry Mnint_rare_logo
 music_table_entry Mstatuex
 music_table_entry Maztecx
 music_table_entry Megyptianx
 music_table_entry Mcradlex
 music_table_entry Mcuba
 music_table_entry Mrunway
 music_table_entry Mrunway_plane
 music_table_entry Msurface2x
 music_table_entry Mwindblowing
 music_table_entry Mmultideath_alt
 music_table_entry Mjungle
 music_table_entry Mrunwayx
 music_table_entry Msurface1
 music_table_entry Mmultiplayerdeath
 music_table_entry Msurface1x
 music_table_entry Msurface2_ending
 music_table_entry Mstatue_ending
 music_table_entry Mfrigate_outro
table_music_data_end:
.global _musicsampletblSegmentRomEnd
_musicsampletblSegmentRomEnd:

.macro music_file name
  .section .musiccompressed
  .global \name
  \name:
  .ifdef VERSION_US
    .incbin "build\/u\/assets\/music\/\name\.rz"
  .endif
  .ifdef VERSION_JP
    .incbin "build\/j\/assets\/music\/\name\.rz"
  .endif
  .ifdef VERSION_EU
    .incbin "build\/e\/assets\/music\/\name\.rz"
  .endif
  end_\name:

  .section .musicdecompressed
  d_\name:
    .incbin "assets\/music\/\name\.bin"
  end_d_\name:
.endm


/*
music_fileA is used for the entries that end with A....the A doesn't seem to be from compression
*/

.macro music_fileA name
  .section .musiccompressed
  .global \name
  \name:
  .ifdef VERSION_US
    .incbin "build\/u\/assets\/music\/\name\.rz"
  .endif
  .ifdef VERSION_JP
    .incbin "build\/j\/assets\/music\/\name\.rz"
  .endif
  .ifdef VERSION_EU
    .incbin "build\/e\/assets\/music\/\name\.rz"
  .endif
    .byte 0xA
  end_\name:

  .section .musicdecompressed
  d_\name:
    .incbin "assets\/music\/\name\.bin"
  end_d_\name:
.endm

music_file Mno_music
music_fileA Msolo_death_abrev
music_file Mintro_eye
music_fileA Mtrain
music_fileA Mdepot
music_file Mjungle_unused
music_fileA Mcitadel
music_file Mfacility
music_file Mcontrol
music_fileA Mdam
music_file Mfrigate
music_file Marchives
music_file Msilo
music_fileA Mjungle_perimeter_unused
music_fileA Mstreets
music_fileA Mbunker1
music_fileA Mbunker2
music_file Mstatue
music_fileA Melevator_control
music_fileA Mcradle
music_fileA Mnull1
music_fileA Melevator_wc
music_file Megyptian
music_file Mfolders
music_fileA Mwatchmusic
music_file Maztec
music_fileA Mwatercaverns
music_fileA Mdeathsolo
music_fileA Msurface2
music_fileA Mtrainx
music_fileA Mnull2
music_file Mfacilityx
music_file Mdepotx
music_file Mcontrolx
music_file Mwatercavernsx
music_fileA Mdamx
music_file Mfrigatex
music_fileA Marchivesx
music_file Msilox
music_fileA Mnull3
music_file Mstreetsx
music_file Mbunker1x
music_fileA Mbunker2x
music_fileA Mjunglex
music_file Mnint_rare_logo
music_fileA Mstatuex
music_file Maztecx
music_file Megyptianx
music_fileA Mcradlex
music_fileA Mcuba
music_file Mrunway
music_file Mrunway_plane
music_file Msurface2x
music_fileA Mwindblowing
music_file Mmultideath_alt
music_file Mjungle
music_file Mrunwayx
music_fileA Msurface1
music_file Mmultiplayerdeath
music_file Msurface1x
music_fileA Msurface2_ending
music_file Mstatue_ending
music_fileA Mfrigate_outro

.section .musiccompressed
.half 0
.word 0



# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .data

.global _sfxctlSegmentRomStart
_sfxctlSegmentRomStart:
 .incbin "assets/music/sfx.ctl"
.global _sfxctlSegmentRomEnd
_sfxctlSegmentRomEnd:


# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .data

.global _instrumentsctlSegmentRomStart
_instrumentsctlSegmentRomStart:
 .incbin "assets/music/instruments.ctl"
.global _instrumentsctlSegmentRomEnd
_instrumentsctlSegmentRomEnd:


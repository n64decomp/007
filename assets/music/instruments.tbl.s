# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .data

.global _instrumentstblSegmentRomStart
_instrumentstblSegmentRomStart:
 .incbin "assets/music/instruments.tbl"
.global _instrumentstblSegmentRomEnd
_instrumentstblSegmentRomEnd:

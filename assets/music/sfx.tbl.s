# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .data

.global _sfxtblSegmentRomStart
_sfxtblSegmentRomStart:
 .incbin "assets/music/sfx.tbl"
.global _sfxtblSegmentRomEnd
_sfxtblSegmentRomEnd:

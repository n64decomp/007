# Goldeneye 007 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
.section .data
glabel osViModeNtscLan1
.word  0x2000000,    0x311E,     0x140, 0x3E52239
.word      0x20D,     0xC15, 0xC150C15,  0x6C02EC
.word      0x200,         0,     0x280,     0x400
.word   0x2501FF,   0xE0204,         2,     0x280
.word      0x400,  0x2501FF,   0xE0204,         2

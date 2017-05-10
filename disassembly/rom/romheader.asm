//============
// N64 Header
//============
// PI_BSB_DOM1
  db $80 // Initial PI_BSB_DOM1_LAT_REG Value
  db $37 // Initial PI_BSB_DOM1_PGS_REG Value
  db $12 // Initial PI_BSB_DOM1_PWD_REG Value
  db $40 // Initial PI_BSB_DOM1_PGS_REG Value

// CLOCK RATE
  dw $000F // Initial Clock Rate

// VECTOR
  dw boot.start // Boot Address Offset
  dw $1447 // Release Offset

// COMPLEMENT CHECK & CHECKSUM
// hardcode so i know if something changes
  dw $DCBC50D1 // CRC1: COMPLEMENT CHECK
  dw $09FD1AA3 // CRC2: CHECKSUM

  dd 0 // UNUSED

// PROGRAM TITLE (27 Byte ASCII String, Use Spaces For Unused Bytes)
  db "GOLDENEYE           "
//   "123456789012345678901234567"
  db $00,$00,$00,$00,$00,$00,$00
// DEVELOPER ID CODE 
  db "N" // "N" = Nintendo

// CARTRIDGE ID CODE
  db "GE" // UNUSED

// COUNTRY CODE 
  db "E" // "D" = Germany, "E" = USA, "J" = Japan, "P" = Europe, "U" = Australia

  db $0 // UNUSED

insert "Code_boot_A4000040"
insert "Code_boot_remap_80000000"

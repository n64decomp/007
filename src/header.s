.section .header, "a"
.byte  0x80, 0x37, 0x12, 0x40 # PI BSD Domain 1 register
.word  0x0000000F # clock rate setting
.word  0x80000400 # entry point
.word  0x00001447 # release
.word  0xDCBC50D1 # checksum1
.word  0x09FD1AA3 # checksum2
.word  0x00000000 # unknown
.word  0x00000000 # unknown
.ascii "GOLDENEYE           " # ROM name: 20 bytes
.word  0x00000000 # unknown
.word  0x0000004E # cartridge
.ascii "GE"       # cartridge ID
.ascii "E"        # country
.byte  0x00       # version

boot:
.incbin "bin/ge007.u.000040.boot.bin"
boot_end:




arch n64.cpu
endian msb
output "GE007.elf", create
origin $00000000

include "N64.INC"
include "elf/ELF.INC"

include "elf/elf_header.asm"
include "elf/program_header.asm"
include "elf/program_sections.asm"
include "elf/shstrtab.asm"
include "elf/section_header.asm"

//Not for awhile, but doing this may be a necessary evil to deal with compressed
//vs non compressed data in address space. Files are copied with little to no 
//changes from my ootmqd disassembly which was copied from experiment's with a certain sdk based roms, so don't expect anything here to work at all.

arch n64.cpu
endian msb
output "OOTMQ_D.ELF", create
//fill 67108864
include "../N64.INC"
include "ELF.INC"

include "elf_header.asm"
include "program_header.asm"
include "program_sections.asm"
include "shstrtab.asm"
include "section_header.asm"

origin $00000000;	
elf_header_start:
dw $7F454C46 //EI_MAG
db $01       //EI_CLASS 
db $02       //EI_DATA 
dw $01000000 //EI_VERSION
dw $00000000 //PAD
dh $0000     //PAD
dh ET_EXEC          //e_type ET_EXEC 
dh EM_MIPS          //e_machine EM_MIPS
dw EV_CURRENT      //e_version EV_CURRENT
dw $00000000      //e_entry
dw program_header_start //e_phoff
dw section_header_start      //e_shoff
dw $00000000      //e_flags
dh elf_header_end - elf_header_start          //e_ehsize
dh E_PHENTSIZE          //e_phentsize
dh E_PHNUM          //e_phnum
dh E_SHENTSIZE          //e_shentsize
dh E_SHNUM          //e_shnum
dh $000C         //e_shstrndx
elf_header_end:

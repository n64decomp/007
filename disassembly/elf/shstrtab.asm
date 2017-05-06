shstrtab_start:
db $00

name_symtab:
db ".symtab"
db $00

name_strtab:
db ".strtab"
db $00

name_shstrtab:
db ".shstrtab"
db $00

name_boot:
db "..boot"
db $00

name_boot_bss:
db "..boot.bss"
db $00

name_code:
db "..code"
db $00

name_code_bss:
db "..code.bss"
db $00

name_cfb:
db "..cfb"
db $00

name_cfb_bss:
db "..cfb.bss"
db $00

name_rsp_cfb:
db "..rsp_cfb"
db $00

name_rsp_cfb_bss:
db "..rsp_cfb.bss"
db $00

name_kbuffer:
db "..kbuffer"
db $00

name_kbuffer_bss:
db "..kbuffer.bss"
db $00

name_reginfo:
db ".reginfo"
db $00

name_debug:
db ".debug"
db $00

name_debug_srcinfo:
db ".debug_srcinfo"
db $00

name_debug_aranges:
db ".debug_aranges"
db $00

name_debug_pubnames:
db ".debug_pubnames"
db $00

name_debug_sfnames:
db ".debug_sfnames"
db $00

name_line:
db ".line"
db $00

name_comment:
db ".comment"
db $00

name_mdebug:
db ".mdebug"
db $00

shstrtab_end:
db $00, $00, $00


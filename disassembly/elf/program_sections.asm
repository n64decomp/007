origin $00010000;
program_reginfo_start:
dw $FFFFFFFE 
dw $00000000
dw $57555757
dw $00000000 
dw $00000000 
dw $00000000
program_reginfo_end:

origin $00020000;
program_rsp_cfb_start:
dw $00
program_rsp_cfb_end:

origin $00020460;
program_boot_start:
insert "boot.zdata"
program_boot_end:

origin $0003CE60;
program_code_start:
//insert "code.zdata"
dw $00
program_code_end:

origin $00060000;
program_dmadata_start:
insert "dmadata.zdata"
program_dmadata_end:

origin $00070000;
program_cfb_start:
dw $00
program_cfb_end:

origin $0007B000;
program_kbuffer_start:
insert "kbuffer.bin"
program_kbuffer_end:



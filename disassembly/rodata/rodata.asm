arch n64.cpu
endian msb
output "rodata.bin", create
base origin()
include "code.inc"
base $80020D90
rodata_start:

rspcode_start:
insert rsp.bin, "rsp.bin"
rspcode_end:

dword_80023040:
dw $00

dword_80023044:
dw $02

cart_hw_address:
dw $10000000

debug_handler_table:
dw sp_boot, aBoot
dw sp_rmon, aRmon
dw sp_idle, aIdle
dw sp_shed, aShed
dw sp_main, aMain
dw sp_audi, aAudi

insert rodata.bin_filler, "021990.bin", origin(), ($800283D0 - $8002307C)

base $800283D0
aBoot:
 db "boot"
 dw $00

//base $800283D8
aRmon:
 db "rmon"
 dw $00

//base $800283E0
aIdle:
 db "idle"
 dw $00

//base $800283E8
aShed:
 db "shed"
 dw $00

//base $800283F0
aMain:
 db "main"
 dw $00

//base $800283F8
aAudi:
 db "audi"
 dw $00

insert rodata.bin_raw, "021990.bin", origin()

base $8005D2E0
rodata_end:


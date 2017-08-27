.section .data

stderr.enable:
#referenced by set_stderr_enable, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

stderr.activated:
#referenced by set_stderr_activated, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

stderr.permitted:
#referenced by set_stderr_permitted, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

user.compare:
#referenced by set_user_compare, testtodisplaystderrorevery16thframe
.word 0x02AEA540

currentcount:
#referenced by testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe, storecurrentcount
.word 0x00000000

setby_DPCfill_0:
#referenced by DPCfill
.word 0x00000000

setby_DPCfill_1:
#referenced by DPCfill
.word 0x00000000

dword_800230B0:
.float 0.0
.float 1.0
.float 1.0

flt_800230BC:
.float 1.0
.float 1.0
.float 0.0

.word 0x00000000

dword_800230CC:
.word 0x00000001



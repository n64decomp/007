.macro get_value name, value
.global get_\name
get_\name:
 lui   $v0, %hi(\value)
 jr    $ra
 addiu $v0, $v0, %lo(\value)
.endm

.macro jump_via_reg location, register=$a3
.global jump_\location
jump_\location:
 lui   \register, %hi(\location)
 addiu \register, \register, %lo(\location)
 jr    \register
 nop
.endm


.macro debug_handler_table_entry sp, string
.word \sp
.word \string
.endm

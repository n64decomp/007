# Assembly Macros

.macro glabel label
    .global \label
    .balign 4
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    .global \label
    .type \label, @function
    \label:
.endm

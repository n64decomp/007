.include "macros.inc"

.section .text

.balign 16
glabel rspF3DBootStart
    .incbin "lib/F3D_boot.bin"
glabel rspF3DBootEnd

# Both of these ucode bins are 0x1000/0x800 respectively as defined in their
# ucode initializations, but there's extra data afterwards. However, it's not the
# RSP data as that is pointed to below in the rodata section. TODO: What are these
# extra bins?

.balign 16
glabel rspF3DStart
    .incbin "lib/F3D.bin"
    .incbin "lib/F3D_unk.bin"
glabel rspF3DEnd

.balign 16
glabel rspF3DAudioStart
    .incbin "lib/F3D_audio.bin"
    .incbin "lib/F3D_audio_unk.bin"
glabel rspF3DAudioEnd

.section .rodata

.balign 16
glabel rspF3DDataStart
    .incbin "lib/F3D_data.bin"
glabel rspF3DDataEnd

.balign 16
glabel rspF3DAudioDataStart
    .incbin "lib/F3D_audio_data.bin"
glabel rspF3DAudioDataEnd

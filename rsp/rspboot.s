.rsp

.create CODE_FILE, 0x04001000

// rspboot microcode by SGI
// this initalizes the RSP and gets it ready to load the next microcode.

    j     rdpcheck
     addi  at, zero, 0x0fc0
ucodeload:
    lw    v0, 0x0010(at)
    addi  v1, zero, 0x0f7f
    addi  a3, zero, 0x1080
    mtc0  a3, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
ucodeloadloop:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, ucodeloadloop
     nop
    jal   checkyield
     nop
    jr    a3
     mtc0  zero, SP_SEMAPHORE
checkyield:
    mfc0  t0, SP_STATUS
    andi  t0, t0, 0x0080
    bne   t0, zero, Yield
     nop
    jr    ra
Yield:
     mtc0  zero, SP_SEMAPHORE
    ori   t0, zero, 0x5200
    mtc0  t0, SP_STATUS
    break
    nop
rdpcheck:
    lw    v0, 0x0004(at)
    andi  v0, v0, 0x0002
    beq   v0, zero, rdpwait
     nop
    jal   checkyield
     nop
    mfc0  v0, DPC_STATUS
    andi  v0, v0, 0x0100
    bgtz  v0, checkyield
     nop
rdpwait:
    lw    v0, 0x0018(at)
    lw    v1, 0x001c(at)
    addi  v1, v1, -0x0001
DMEMLoad:
    mfc0  s8, SP_DMA_FULL
    bne   s8, zero, DMEMLoad
     nop
    mtc0  zero, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
dmaloop:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, dmaloop
     nop
    jal   checkyield
     nop
    j     ucodeload
     nop
    nop

.close // CODE_FILE

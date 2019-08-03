#include "libultra_internal.h"
#include "libaudio_internal.h"
#define PATCH(SRC, BASE, TYPE) SRC = (TYPE)((u32)SRC + (u32)BASE)


void alSeqFileNew(ALSeqFile *f, u8 *base)
{
    int i;
    //  lh    $t6, 2($a0)
    //  move  $v0, $zero
    //  move  $v1, $a0
    //  blez  $t6, .L80324DE0
    //   nop
    for (i = 0; i < f->seqCount; i++)
    {
        //  lw    $t7, 4($v1)
        //.L80324DC0:
        //  addiu $v0, $v0, 1
        //  addiu $v1, $v1, 8
        //  addu  $t8, $t7, $a1
        //  sw    $t8, -4($v1)
        f->seqArray[i].offset = (u32)(f->seqArray[i].offset) + base;
        //  lh    $t9, 2($a0)
        //  slt   $at, $v0, $t9
        //  bnezl $at, .L80324DC0
        //   lw    $t7, 4($v1)
    }
    //.L80324DE0:
    //  jr    $ra
    //   nop

    //  nop
    //  nop
}
static void _bnkfPatchBank(ALInstrument *f, ALBankFile *a1, u8 *a3)
{
    int i;
    ALSound *sound;
    ALWaveTable *wavetable;
    u8 *a3_2;
    //  lbu   $t6, 3($a0)
    //  bnez  $t6, .L80324C94
    //   nop
    if (f->flags)
        return;

    //  lh    $t7, 0xe($a0)
    //  li    $t1, 1
    //  sb    $t1, 3($a0)
    f->flags = 1;
    //  blez  $t7, .L80324C94
    //   move  $v0, $zero
    for (i = 0; i < f->soundCount; i++)
    {
        //  move  $v1, $a0
        //  li    $t2, 1
        //  lw    $t8, 0x10($v1)
        //.L80324BDC:
        //  addu  $t9, $t8, $a1
        //  sw    $t9, 0x10($v1)
        PATCH(f->soundArray[i], a1, ALSound *);
        sound = f->soundArray[i];

        //  lbu   $t6, 0xe($t9)
        //  move  $a2, $t9
        //  bnezl $t6, .L80324C80
        if (sound->flags)
            continue;
        a3_2 = a3;

        //   lh    $t8, 0xe($a0)
        //  lw    $t7, ($t9)
        //  sb    $t1, 0xe($t9)

        sound->flags = 1;
        //  addu  $t8, $t7, $a1
        //  sw    $t8, ($t9)
        PATCH(sound->envelope, a1, ALEnvelope *);
        //sound->envelope = (u32)sound->envelope + (u32)f;
        //  lw    $t9, 4($t9)
        //  lw    $t7, 8($a2)
        //  addu  $t6, $t9, $a1
        //  addu  $t8, $t7, $a1
        //  sw    $t6, 4($a2)
        PATCH(sound->keyMap, a1, ALKeyMap *);
        //  sw    $t8, 8($a2)
        PATCH(sound->wavetable, a1, ALWaveTable *);
        //  lbu   $t9, 9($t8)
        //  move  $t0, $t8
        wavetable = sound->wavetable;
        //  bnezl $t9, .L80324C80
        //   lh    $t8, 0xe($a0)
        if (wavetable->flags)
            continue;

        //  lw    $t6, ($t8)
        //  lbu   $a2, 8($t8)
        //  sb    $t1, 9($t8)
        //  addu  $t7, $t6, $a3
        wavetable->flags = 1;
        //  bnez  $a2, .L80324C64
        //   sw    $t7, ($t8)
        PATCH(wavetable->base, a3_2, u8 *);
        if (wavetable->type == 0)
        {
            //  lw    $t8, 0x10($t8)
            //  lw    $a2, 0xc($t0)
            //  addu  $t9, $t8, $a1
            //  beqz  $a2, .L80324C7C
            //   sw    $t9, 0x10($t0)
            PATCH(wavetable->waveInfo.adpcmWave.book, a1, ALADPCMBook *);
            if (wavetable->waveInfo.adpcmWave.loop != NULL)
                PATCH(wavetable->waveInfo.adpcmWave.loop, a1, ALADPCMloop *);
            //  addu  $t6, $a2, $a1
            //  b     .L80324C7C
            //   sw    $t6, 0xc($t0)
        }
        else if (wavetable->type == 1)
        {
            //.L80324C64:
            //  bnel  $t2, $a2, .L80324C80
            //   lh    $t8, 0xe($a0)
            //  lw    $a2, 0xc($t0)
            //  beqz  $a2, .L80324C7C
            if (wavetable->waveInfo.rawWave.loop != NULL)
                //   addu  $t7, $a2, $a1
                //  sw    $t7, 0xc($t0)
                PATCH(wavetable->waveInfo.rawWave.loop, a1, ALRawLoop *);
            //.L80324C7C:
            //  lh    $t8, 0xe($a0)
        }

        //.L80324C80:
        //  addiu $v0, $v0, 1
        //  addiu $v1, $v1, 4
        //  slt   $at, $v0, $t8
        //  bnezl $at, .L80324BDC
        //   lw    $t8, 0x10($v1)
    }

    //.L80324C94:
    //  jr    $ra
    //   nop
}
//force adding another jr $ra.  has to be called or it doesn't get put in the right place
static void unused()
{
    //  jr    $ra
    //   nop
}

//glabel alBnkfNew
void alBnkfNew(ALBankFile *f, u8 *table)
{
    //ALInstrument *_inst;
    ALBank *bank;
    int i;
    int j;
    unused();
    //  addiu $sp, $sp, -0x30
    //  sw    $ra, 0x2c($sp)
    //  sw    $s4, 0x28($sp)
    //  sw    $s3, 0x24($sp)
    //  sw    $s2, 0x20($sp)
    //  sw    $s1, 0x1c($sp)
    //  sw    $s0, 0x18($sp)
    //  lh    $t6, ($a0)
    //  li    $at, 16945
    //  move  $s0, $a0
    //  bne   $t6, $at, .L80324D88
    //   move  $s1, $a1
    if (f->revision != AL_BANK_VERSION)
        return;

    //  lh    $t7, 2($a0)
    //  move  $s3, $zero
    //  move  $s2, $a0
    //  blez  $t7, .L80324D88
    //   li    $s4, 1
    for (i = 0; i < f->bankCount; i++)
    {
        //  lw    $t8, 4($s2)
        //.L80324CEC:
        //  addu  $t9, $t8, f
        //  beqz  $t9, .L80324D70
        //   sw    $t9, 4($s2)
        PATCH(f->bankArray[i], f, ALBank *);
        if (f->bankArray[i] == NULL)
            continue;

        //  lbu   $t6, 2($t9)
        //  move  $t5, $t9
        bank = f->bankArray[i];
        //  bnezl $t6, .L80324D74
        //   lh    $t8, 2(f)
        if (bank->flags == 0)
        {
            //  lw    $v0, 8($t9)
            //  sb    $s4, 2($t9)
            bank->flags = 1;
            //  move  $t4, $zero
            //  beqz  $v0, .L80324D2C
            //   addu  $a0, $v0, f
            if (bank->percussion != NULL)
            {
                //  sw    $a0, 8($t9)
                PATCH(bank->percussion, f, ALInstrument *);
                //  move  $a1, f
                //  jal   _bnkfPatchBank
                //   move  $a3, $s1
                _bnkfPatchBank(bank->percussion, f, table);
            }
            //.L80324D2C:
            //  lh    $t8, ($t5)
            //  move  $t3, $t5
            //  blezl $t8, .L80324D74
            //   lh    $t8, 2(f)
            for (j = 0; j < bank->instCount; j++)
            {
                //  lw    $t9, 0xc($t3)
                //.L80324D40:
                //  move  $a1, f
                //  addu  $a0, $t9, f
                //  beqz  $a0, .L80324D58
                //   sw    $a0, 0xc($t3)
                PATCH(bank->instArray[j], f, ALInstrument *);
                //inst = bank->instArray[j];
                if (bank->instArray[j] != NULL)
                {

                    //  jal   _bnkfPatchBank
                    //   move  $a3, $s1
                    _bnkfPatchBank(bank->instArray[j], f, table);
                }
                //.L80324D58:
                //  lh    $t7, ($t5)
                //  addiu $t4, $t4, 1
                //  addiu $t3, $t3, 4
                //  slt   $at, $t4, $t7
                //  bnezl $at, .L80324D40
                //   lw    $t9, 0xc($t3)
            }
        }

        //.L80324D70:
        //  lh    $t8, 2(f)
        //.L80324D74:
        //  addiu $s3, $s3, 1
        //  addiu $s2, $s2, 4
        //  slt   $at, $s3, $t8
        //  bnezl $at, .L80324CEC
        //   lw    $t8, 4($s2)
    }
    //.L80324D88:
    //  lw    $ra, 0x2c($sp)
    //  lw    $s0, 0x18($sp)
    //  lw    $s1, 0x1c($sp)
    //  lw    $s2, 0x20($sp)
    //  lw    $s3, 0x24($sp)
    //  lw    $s4, 0x28($sp)
    //  jr    $ra
    //   addiu $sp, $sp, 0x30
}

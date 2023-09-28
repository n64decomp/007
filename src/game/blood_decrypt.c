#include "blood_decrypt.h"

// address 0x7F01CAE0 NTSC
u8 *decrypt_bleeding_animation_data(u8 *arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4)
{
    u8 var_a2;
    u8 var_a3;
    u8 temp_v0;
    u8 var_v1;
    u8 next;

    temp_v0 = *arg0++;
    *arg4 = temp_v0;

    do
    {
        s32 unused;
        var_v1 = *arg0++;
        unused = var_v1;
        
        var_a2 = 0xFF;

        if (var_v1 == 0xFF)
        {
            var_a3 = 0;
            for (var_v1 = *arg0++; var_v1 != 0xFF; var_a2 ^= 0xff, var_v1 = *arg0++ )
            {
                var_a3 += var_v1;

                while (var_v1-- > 0)
                {
                    *arg3++ = var_a2;
                }
            }
            
            while (var_a3++ < arg1)
            {
                *arg3++ = var_a2;
            }
            
            arg2--;
        }
        else
        {
            var_a3 = temp_v0 + (var_v1 & 0x1f);
            var_v1 = (var_v1 >> 5) + 1;
            arg2 -= var_v1;
            
            do
            {
                var_a2 = var_a3;
                while (var_a2-- > 0)
                {
                    *arg3++ = 0xff;
                }
                
                var_a2 = arg1 - var_a3;
                while (var_a2-- > 0)
                {
                    *arg3++ = 0;
                }
            } while (--var_v1 > 0);
        }
    } while (arg2 > 0);
    
    return arg0;
}




void sub_GAME_7F01CC94(u8* arg0, u16 arg1, u8* arg2)
{
    while (arg1-- > 0)
    {
        *arg2++ = (arg0[0] & 0xF0) | (arg0[1] >> 4);
        arg0 += 2;
    }
}

// Address 0x7F01CCEC NTSC
void sub_GAME_7F01CCEC(u8 *arg0, u8 arg1, u8 arg2, u8 *arg3, u8 arg4)
{
    s16 i;
    s16 j;

    u32 var_t0;
    u32 var_t1;
    
    s16 var_t5;

    s16 var_s4;

    u8 tempt9;

    for (i = 0; i < arg2; i++)
    {
        for (j = 0; j < arg1; j++)
        {
            var_t0 = 0;
            var_t1 = 0;
            
            var_t5 = ((i - arg4) < 0) ? 0 : (i - arg4);

            while ((((arg2 - 1) < (i + arg4)) ? (arg2 - 1) : (i + arg4)) >= var_t5)
            {
                var_s4 = ((j - arg4) < 0) ? 0 : (j - arg4);
                
                while ((((arg1 - 1) < (j + arg4)) ? (arg1 - 1) : (j + arg4)) >= var_s4)
                {
                    var_t1 += arg0[var_s4 + (var_t5 * arg1)];
                    
                    var_s4 += 1;
                    var_t0 += 1;
                }

                var_t5 += 1;
            }

            tempt9  = (u8) ((u32) ((var_t0 >> 1) + var_t1) / var_t0);
            arg3[j + (i * arg1)] = tempt9;
        }
    }
}



// Averages 4 pixel data, ending on "second" row.
// Address 0x7F01CEEC NTSC
void sub_GAME_7F01CEEC(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 i;
    s32 j;

    arg0 += 0x61;
    arg2 += 0x61;

    for (i = 1; i < arg1 - 1; i++, arg2 += 2, arg0 += 2) {
        for (j = 1; j < 0x5f; j++, arg2++, arg0++) {
            *arg2 = (arg0[-1] + arg0[0] + arg0[-0x61] + arg0[-0x60] + 2) >> 2;
        }
    }
}



// Averages 4 pixel data, ending on "first" row.
// Address 0x7F01D02C NTSC
void sub_GAME_7F01D02C(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 i;
    s32 j;

    arg0 += 0x61;
    arg2 += 0x61;

    for (i = 1; i < arg1 - 1; i++, arg2 += 2, arg0 += 2) {
        for (j = 1; j < 0x5f; j++, arg2++, arg0++) {
            *arg2 = (arg0[1] + arg0[0] + arg0[0x61] + arg0[0x60] + 2) >> 2;
        }
    }
}

// Address 0x7F01D16C NTSC
void sub_GAME_7F01D16C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    s32 temp_lo;
    u32 temp_a0;
    u32 var_t2;
    u8 *var_t0;
    u8 *var_v1;
    u32 t1;

    temp_lo = arg1 * arg2;
    var_v1 = arg0;
    var_t0 = arg3;
    t1 = arg0 + temp_lo;
    var_t2 = arg0 + arg1;

    do
    {
        temp_a0 = var_t2;

        do
        {
            *var_t0 = *var_v1++;
            var_t2 += 1;
            var_t0 += arg2;
            
        } while ((u32) var_v1 < temp_a0);

        var_t0 = (var_t0 - (temp_lo)) + 1;
        
    } while ((u32) var_v1 < (u32) t1);
}



#ifdef NONMATCHING
// Unreferenced.
// Address 0x7F01D1C0 NTSC.
u8 *sub_GAME_7F01D1C0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    // mips2c output makes this look like `decrypt_bleeding_animation_data`, but without
    // u8 variables, and without arg4. But I can't get it to generate anything
    // close to matching.

    // https://decomp.me/scratch/ptG72 0%
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D1C0
/* 051CF0 7F01D1C0 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 051CF4 7F01D1C4 240C00FF */  li    $t4, 255
/* 051CF8 7F01D1C8 90880000 */  lbu   $t0, ($a0)
/* 051CFC 7F01D1CC 24840001 */  addiu $a0, $a0, 1
.L7F01D1D0:
/* 051D00 7F01D1D0 90890000 */  lbu   $t1, ($a0)
/* 051D04 7F01D1D4 24840001 */  addiu $a0, $a0, 1
/* 051D08 7F01D1D8 152C001A */  bne   $t1, $t4, .L7F01D244
/* 051D0C 7F01D1DC 240B00FF */   li    $t3, 255
/* 051D10 7F01D1E0 90890000 */  lbu   $t1, ($a0)
/* 051D14 7F01D1E4 240A0000 */  li    $t2, 0
/* 051D18 7F01D1E8 112C000C */  beq   $t1, $t4, .L7F01D21C
/* 051D1C 7F01D1EC 24840001 */   addiu $a0, $a0, 1
.L7F01D1F0:
/* 051D20 7F01D1F0 01495021 */  addu  $t2, $t2, $t1
/* 051D24 7F01D1F4 19200005 */  blez  $t1, .L7F01D20C
/* 051D28 7F01D1F8 2529FFFF */   addiu $t1, $t1, -1
.L7F01D1FC:
/* 051D2C 7F01D1FC A0EB0000 */  sb    $t3, ($a3)
/* 051D30 7F01D200 24E70001 */  addiu $a3, $a3, 1
/* 051D34 7F01D204 1D20FFFD */  bgtz  $t1, .L7F01D1FC
/* 051D38 7F01D208 2529FFFF */   addiu $t1, $t1, -1
.L7F01D20C:
/* 051D3C 7F01D20C 90890000 */  lbu   $t1, ($a0)
/* 051D40 7F01D210 396B00FF */  xori  $t3, $t3, 0xff
/* 051D44 7F01D214 152CFFF6 */  bne   $t1, $t4, .L7F01D1F0
/* 051D48 7F01D218 24840001 */   addiu $a0, $a0, 1
.L7F01D21C:
/* 051D4C 7F01D21C 0145082A */  slt   $at, $t2, $a1
/* 051D50 7F01D220 10200006 */  beqz  $at, .L7F01D23C
/* 051D54 7F01D224 254A0001 */   addiu $t2, $t2, 1
.L7F01D228:
/* 051D58 7F01D228 A0EB0000 */  sb    $t3, ($a3)
/* 051D5C 7F01D22C 24E70001 */  addiu $a3, $a3, 1
/* 051D60 7F01D230 0145082A */  slt   $at, $t2, $a1
/* 051D64 7F01D234 1420FFFC */  bnez  $at, .L7F01D228
/* 051D68 7F01D238 254A0001 */   addiu $t2, $t2, 1
.L7F01D23C:
/* 051D6C 7F01D23C 0BC074A7 */  j     .L7F01D29C
/* 051D70 7F01D240 24C6FFFF */   addiu $a2, $a2, -1

.L7F01D244:
/* 051D74 7F01D244 312A001F */  andi  $t2, $t1, 0x1f
/* 051D78 7F01D248 01485021 */  addu  $t2, $t2, $t0
/* 051D7C 7F01D24C 00094942 */  srl   $t1, $t1, 5
/* 051D80 7F01D250 25290001 */  addiu $t1, $t1, 1
/* 051D84 7F01D254 00C93023 */  subu  $a2, $a2, $t1
.L7F01D258:
/* 051D88 7F01D258 01405825 */  move  $t3, $t2
/* 051D8C 7F01D25C 19600005 */  blez  $t3, .L7F01D274
/* 051D90 7F01D260 256BFFFF */   addiu $t3, $t3, -1
.L7F01D264:
/* 051D94 7F01D264 A0EC0000 */  sb    $t4, ($a3)
/* 051D98 7F01D268 24E70001 */  addiu $a3, $a3, 1
/* 051D9C 7F01D26C 1D60FFFD */  bgtz  $t3, .L7F01D264
/* 051DA0 7F01D270 256BFFFF */   addiu $t3, $t3, -1
.L7F01D274:
/* 051DA4 7F01D274 00AA5823 */  subu  $t3, $a1, $t2
/* 051DA8 7F01D278 19600005 */  blez  $t3, .L7F01D290
/* 051DAC 7F01D27C 256BFFFF */   addiu $t3, $t3, -1
.L7F01D280:
/* 051DB0 7F01D280 A0E00000 */  sb    $zero, ($a3)
/* 051DB4 7F01D284 24E70001 */  addiu $a3, $a3, 1
/* 051DB8 7F01D288 1D60FFFD */  bgtz  $t3, .L7F01D280
/* 051DBC 7F01D28C 256BFFFF */   addiu $t3, $t3, -1
.L7F01D290:
/* 051DC0 7F01D290 2529FFFF */  addiu $t1, $t1, -1
/* 051DC4 7F01D294 1D20FFF0 */  bgtz  $t1, .L7F01D258
/* 051DC8 7F01D298 00000000 */   nop   
.L7F01D29C:
/* 051DCC 7F01D29C 1CC0FFCC */  bgtz  $a2, .L7F01D1D0
/* 051DD0 7F01D2A0 00801025 */   move  $v0, $a0
/* 051DD4 7F01D2A4 03E00008 */  jr    $ra
/* 051DD8 7F01D2A8 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif



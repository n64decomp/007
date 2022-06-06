#include <ultra64.h>
#include <PR/os.h>
#include <bondgame.h>
#include "tlb_manage.h"
#include "deb_print.h"
#include "ramrom.h"
#include <PR/R4300.h>
#include "thread_config.h"

/**
 * @file deb_video.c
 * This file contains code to handle tlb paging. 
 * 
 * Additionally, it contains unused/removed debug code, and code for indy.
 * The function addresses seem to indicate these methods are all in the same file ...
 */

/**
 * Size in bytes.
 */
#define g_indyReadBuffer_LEN 0x60

/**
 * Copied from n64devkit\ultra\usr\src\pr\demos\fault\fault.c
 */
#define MSG_FAULT    0x10

#define TLB_MESSAGE_QUEUE_SIZE      1

/*
-----------------------------------------------------------------
| ADDIU     | ADD Immediate Unsigned word                       |
|-----------|---------------------------------------------------|
|001001 (9) |   rs    |   rt    |          immediate            |
------6----------5---------5-------------------16----------------
 Format:  ADDIU rt, rs, immediate
 Purpose: To add a constant to a 32-bit integer.
 Descrip: rt = rs + immediate

-----------------------------------------------------------------
| SW        | Store Word                                        |
|-----------|---------------------------------------------------|
|101011 (43)|  base   |   rt    |             offset            |
------6----------5---------5-------------------16----------------
 Format:  SW rt, offset(base)
 Purpose: To store a word to memory.
 Descrip: word[base+offset] = rt

-----------------------------------------------------------------
| JR        | Jump Register                                     |
|-----------|---------------------------------------------------|
|  000000   |   rs    |     0000 0000 0000 000      |001000 (8) |
------6----------5------------------15--------------------6------
 Format:  JR rs
 Purpose: To branch to an instruction address in a register.
*/

/**
 * Add immediate unsigned word. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_ADDIU 0x09

/**
 * Store word. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_SW 0x2b

/**
 * Jump to register. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_JR 0x00

/**
 * Five bits defining register source or destination, for stack pointer register.
 */
#define MIPS_REG_SOURCE_BITS_SP 0x1d

/**
 * Five bits defining register source or destination, for return address register.
 */
#define MIPS_REG_SOURCE_BITS_RA 0x1f

/**
 * Builds 32 bit word to perform ADDIU.
 * 
 * No error checking or input size validation are performed here.
 * 
 * @param source_r: source register number (5 bits).
 * @param dest_r: destination register number (5 bits).
 * @param imm: 16 bit immediate value to add.
 */
#define MIPS_INSTR_ADDIU(source_r, dest_r, imm) ((MIPS_OP_BITS_ADDIU << 26) | (source_r << 21) | (dest_r << 16) | imm)

/**
 * Builds 32 bit word to perform SW.
 * 
 * No error checking or input size validation are performed here.
 * 
 * @param val_r: source register holding value to store (5 bits).
 * @param dest_r: register holding destination base address (5 bits).
 * @param offset: 16 bit offset from base address to store value at.
 */
#define MIPS_INSTR_SW(val_r, dest_r, offset) ((MIPS_OP_BITS_SW << 26) | (dest_r << 21) | (val_r << 16) | offset)

/**
 * Builds 32 bit word to perform SW.
 * 
 * No error checking or input size validation are performed here.
 * 
 * Note: lower 6 bits of JR instruction are always 0x08.
 * 
 * @param dest_r: register holding destination address (5 bits).
 */
#define MIPS_INSTR_JR(dest_r) ((MIPS_OP_BITS_JR << 26) | (dest_r << 21) | 8)

/**
 * Any MIPS 32-bit instruction matching $sp increment
 * 
 * 0x27BD0000 = # addiu $sp, $sp <any_immediate>
 */
#define MIPS_ADDIU_SP_SP_ANY        MIPS_INSTR_ADDIU(MIPS_REG_SOURCE_BITS_SP, MIPS_REG_SOURCE_BITS_SP, 0)
#define MIPS_ADDIU_SP_SP_ANY_MASK   0xFFFF0000

/**
 * Any MIPS 32-bit instruction matching sw into $sp
 * 
 * 0xAFA00000 = sw <any_register>, 0x[any_offset]($sp)
 */
#define MIPS_SW_SP_ANY       MIPS_INSTR_SW(0, MIPS_REG_SOURCE_BITS_SP, 0)
#define MIPS_SW_SP_ANY_MASK  0xFFE00000

/**
 * Any MIPS 32-bit instruction (should only be one...) matching jump to return address.
 * 
 * 0x03E00008 = jr ra
 */
#define MIPS_JR_RA MIPS_INSTR_JR(MIPS_REG_SOURCE_BITS_RA)

// bss - TLB section

OSThread g_tlbThread;
u8 g_tlbUnused[0x500];
char g_tlbStack[0x2300];
OSMesgQueue g_faultMesgQ;
OSMesg *g_faultMesgBuf;






// forward declarations

void faultMain(void* arg0);

// end forward declarations

/**
 * 5AE0    70004EE0
 */
void faultInit(void)
{
    deboutInitBuffers();
    osCreateMesgQueue(&g_faultMesgQ, (OSMesg *)&g_faultMesgBuf, TLB_MESSAGE_QUEUE_SIZE);
    osCreateThread(&g_tlbThread, TLB_THREAD_ID, &faultMain, NULL, &g_tlbStack, TLB_THREAD_PRIORITY);
    osStartThread(&g_tlbThread);
}

/**
 * 5B54    70004F54
 * 
 * @param arg0 Unused.
 */
extern OSThread *__osRunQueue;
void faultMain(void* arg0)
{
    OSMesg msg = 0;
    OSIntMask mask;
    static OSThread *curr;
    static OSThread *last;
    /**
     * Target generates 5 separate dereferences of g_faultedThreadPtr,
     * only way I can get that to happen is with a pointer to a pointer.
     */
    //OSThread **ppfaultedThread = &g_faultedThreadPtr;

    osSetEventMesg(OS_EVENT_FAULT, &g_faultMesgQ, (OSMesg)MSG_FAULT);
    last = 0;

    while (1)
    {
        osRecvMesg(&g_faultMesgQ, &msg, OS_MESG_BLOCK);
        mask = osSetIntMask(OS_IM_NONE);
        curr = __osGetCurrFaultedThread();
        //*ppfaultedThread = curr;

        if (curr == NULL)
        {
            continue;
        }

        else if (((curr->context.cause & 0x7c) == 8) && ((curr->context.badvaddr & 0xFFC00000) == (u32)0x7F000000))
        {
            tlbmanageTranslateLoadRomFromTlbAddress(curr->context.badvaddr);
            curr->state = (u16)0xA;
            curr->flags = (u16)0;

            __osEnqueueThread(&__osRunQueue, curr);
            osSetIntMask(mask);
            osYieldThread();
        }
        else
        {
            break;
        }
    }

    osSetIntMask(mask);

    // infinite loop
    while (1) {}

}


/**
 * Given a pointer to an instruction and a stack frame pointer, attempt to find
 * the calling function. Return the address of the caller's stack frame and
 * populate regs with stack addresses where that register was saved. This can be
 * used to retrieve the RA value and invoke crashGetParentStackFrame again to
 * build a backtrace.
 *
 * @param origptr is a pointer to an instruction. This should be either the value of
 *     the PC register of the faulted thread, or an RA register if searching a
 *     parent.
 * @param minaddr is the memory address of the start of the code segment,
 *     ie. 0x70001050. This is used to prevent the function from walking out of
 *     the code segment.
 * @param origsp is the address of the stack frame for the given origptr.
 * @param regs is a pointer to an array of 32 words.
 *
 * The function works by walking backwards one instruction at a time, looking
 * for stack frame adjustments and stores of $ra to the stack. Once both of
 * these are are found, the function returns with this information.
 *
 * @returns The function will return 0 if it can't reliably find the caller. This will
 * happen if the function being analysed didn't adjust the stack pointer or
 * store $ra in the stack. It can also fail if the function being analysed uses
 * returns within branches.
 * 
 * note: name copied from PD.
 */
const u32 *crashGetParentStackFrame(const u32 *origptr, const u32 *minaddr, const u32 *origsp, u32 *regs)
{
    const u32 *sp = origsp;
    const u32 *addr;
    u32 sp_found = 0; // v0
    u32 ra_found = 0; // t0
    s32 sw_reg;
    
    // Holds value of address while iterating, but also reused
    // to iterate while loop at start of method.
    u32 addrval;
    s16 value;    
    
    // Do not remove the following trailing backslash. The while condition
    // needs to be on the same line as previous, otherwise the build breaks.
    // Search for WHILE_ONE_LINE to see other places in code like this.
    //
    // Note: this also occurs in PD:
    // src/game/game_0b69d0.c (bd15d298664e1a22cd31886cf87bfc40ab6842e9)
    // line 382:    p = i; while (sllen < 4) {
    addrval = 0; \
    while(addrval < 32)
    {
        regs[addrval++] = 0;
    }

    // Walk backwards through the instructions
    for (addr = origptr; addr >= minaddr; addr--)
    {
        // no validation on pointer
        addrval = *addr;
        value = addrval & 0xffff;

        if ((addrval & MIPS_ADDIU_SP_SP_ANY_MASK) == MIPS_ADDIU_SP_SP_ANY)
        {
            // Found an addiu $sp, $sp, <amount> instruction, which adjusts the
			// stack pointer. These can exist near the start and end of any
			// function. The "add" at the start is done with a negative value
			// which increases the size of the stack, as the stack expands to
			// the left. This function is interested in these negative adds,
			// because it needs to reverse it and move the sp variable forward
			// to the next stack frame (the frame of the caller).
            sp_found = 1;

            if (value > 0)
            {
                // Found the addiu sp at the end of the function. It's pretty
				// rare to crash (or jump elsewhere) after restoring the sp,
				// so this situation is not supported by this function.

                break;
            }

            // Change sp to point to the caller's stack frame
            sp -= (value >> 2);

            if (ra_found)
            {
                break;
            }
        }
        else if ((addrval & MIPS_SW_SP_ANY_MASK) == MIPS_SW_SP_ANY)
        {
            // This looks for a store from $ra to the stack, so the value can
			// be read from the stack and used to find the caller's address.
            sw_reg = (addrval >> 16) & 0x1F;
            regs[sw_reg] = (u32)(sp + (value >> 2));

            if (sw_reg == MIPS_REG_SOURCE_BITS_RA)
            {
                ra_found = 1;
            }

            if (sp_found && ra_found)
            {
                // Found a jr $ra statement, which is a return. This will happen if
                // this loop has walked out of the current function and into the one
                // prior to it, so bail.

                // It can also happen if the function has return statements within
                // branches, but handling these correctly would involve a lot of
                // complexity so that's unsupported. Because of this, this function
                // can end the backtrace prematurely if it encounters a function
                // that does this.

                break;
            }
        }
        else if (addrval == MIPS_JR_RA)
        {
            break;
        }
    }

    if (sp_found && ra_found)
    {
        return sp;
    }

    return 0;
}

/**
 * 5DE0    700051E0
 *     V0=TRUE if opcode that set RA A0 was a JAL or JALR type within bounds (70000450,70020D90)
 *     accepts: A0=p->70-mapped TLB function, presumably from RA
 */
s32 crashIsReturnAddress(u32 *instruction)
{
    u32 prevop;

    if ((((s32) instruction & 3) == 0) && ((u32) instruction >= (u32) &_codeSegmentStart) && ((u32) &_codeSegmentEnd >= (u32) instruction))
    {
        prevop = instruction[-2];
        if ((prevop & 0xFC00003C) == 9)
        {
            return 1;
        }
        if ((prevop & 0xFC000000) == 0xC000000)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * 5E58    70005258
 *     V0= strlen(A0); used exclusively for scanning ind.rea.buf
 *     accepts: A0=p->string
 * 
 * Max length returned is 256.
 */
s32 indyStrlen(u8 *arg0)
{
    s32 count = 0;
    u8 c;

    for (c = *arg0++; c != '\0'; c = *arg0++)
    {
        count++;
        if (count > 255)
        {
            break;
        }
    }

    return count;
}


// bss - indy/debug section
u32 *g_indyCurrentReadBufferResourceId;
u8 *g_indyReadBufferString1;
u8 *g_indyReadBufferString2;
char g_indyReadBuffer[g_indyReadBuffer_LEN];

/**
 * 5E94    70005294
 *     V0= total size of one word, two strings at hardware A0
 *     accepts: A0=hardware address
 */
u8 *indyFileGetAddressSubsequentData(u8 *arg0)
{
    u32 returnAddress;

    romCopy(&g_indyReadBuffer, arg0, g_indyReadBuffer_LEN);
    
    g_indyCurrentReadBufferResourceId = (u32*)(*(s32*) &g_indyReadBuffer);
    g_indyReadBufferString1 = (u8*)&g_indyReadBuffer[4];
    g_indyReadBufferString2 = (u8 *) (
        indyStrlen(g_indyReadBufferString1)
        + (u32)g_indyReadBufferString1
        + 1);
    
    returnAddress = 
        indyStrlen(g_indyReadBufferString1) 
        + ((u32)arg0 + indyStrlen(g_indyReadBufferString2))
        + 6;

    if (returnAddress & 3)
    {
        returnAddress = ((returnAddress | 3) + 1);
    }

    return (u8 *)returnAddress;
}

/**
 * 5F40    70005340
 *     scan for and load resourceID A0 from indy.read.buf
 *     accepts: A0=resourceID
 */
s32 indyScanLoadResourceIdFromBuffer(u32 arg0)
{
    u32 *temp_v1;
    u8 *phi_s0 = (u8 *)0xE00004;
    u8 *v0;
    u32 a0 = arg0;
    u8 *phi_s3;

    phi_s3 = phi_s0;

    while (1)
    {
        v0 = indyFileGetAddressSubsequentData(phi_s0);

        temp_v1 = g_indyCurrentReadBufferResourceId;

        if (a0 < (u32)temp_v1)
        {
            break;
        }

        phi_s3 = phi_s0;

        if (temp_v1 == NULL)
        {
            return 0;
        }

        phi_s0 = v0;
    }

    indyFileGetAddressSubsequentData(phi_s3);

    return 1;
}

/**
 * 5FC8    700053C8
 *     V0= TRUE if valid indy.read.buf.resourceID    [matches 826475BE]
 */
u32 indyIsValidReadBufferResourceId(void)
{
    indyFileGetAddressSubsequentData((u8*)0xe00000);
    return ((u32)g_indyCurrentReadBufferResourceId ^ 0x826475be) == 0;
}

/**
 * 5FFC    700053FC
 *     unconditional return
 */
void indyRemoved01(void)
{
    return;
}

/**
 * 6004    70005404
 *     unconditional return
 */
void indyRemoved02(void)
{
    return;
}

/**
 * 600C    7000540C
 *     unconditional return
 */
void indyPrintReadBufferResourceId(void)
{
    #ifdef DEBUG
    osSyncPrintf("%08x",_g_indyCurrentReadBufferResourceId); //from pd beta
    #endif
    return;
}

/**
 * 6014    70005414
 *     V0= indy.read.buf.resourceID    [80063664]
 */
u32 * indyGetReadBufferResourceId(void)
{
    return g_indyCurrentReadBufferResourceId;
}

/**
 * 6020    70005420
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If sp is above 0x80000000U and tid is valid, returns g_StackPtrs2 entry.
 * Otherwise, if tid is valid, returns sp & 0xF0000000, bitwise OR'd
 * with the difference from g_StackPtrs2 entry (pointer value) to 
 * g_StackPtrs1 entry (pointer value).
 * Otherwise, returns null.
 * 
 * @param sp: address / address space
 * @param tid: index into g_StackPtrs2/3. Must be (1 <= tid <= STACK_POINTER_COUNT).
 */
void * crashGetStackEnd(u32 sp, u32 tid)
{
    void *localStackPointers1[STACK_POINTER_COUNT] = g_StackPtrs1;
    void *localStackPointers2[STACK_POINTER_COUNT] = g_StackPtrs2;
    void *p2;
    void *p1;

    if ((s32)tid <= (s32)0 || (u32)tid > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p1 = localStackPointers1[tid];
    p2 = localStackPointers2[tid];
    
    if (sp >= 0x80000000U)
    {
        return p2;
    }
    
    p2 = (void*)(
        (sp & 0xF0000000) | ((u32)p2 - (u32)p1)
        );
    return p2;
}

/**
 * 60E4    700054E4
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If sp is above 0x80000000U and tid is valid, returns g_StackPtrs3 entry.
 * Otherwise, if tid is valid, returns sp & 0xF0000000.
 * Otherwise, returns null.
 * 
 * @param sp: address / address space
 * @param tid: index into g_StackPtrs3. Must be (1 <= tid <= STACK_POINTER_COUNT).
 */
void * crashGetStackStart(u32 sp, u32 tid)
{
    void *localStackPointers3[STACK_POINTER_COUNT] = g_StackPtrs3;
    void *p;

    if ((s32)tid <= (s32)0 || (u32)tid > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p = localStackPointers3[tid];

    if (sp >= 0x80000000U)
    {
        return p;
    }

    p = (void*)(sp & 0xF0000000);
    return p;
}


#define IEEE_FLOAT_FRACTION_BITMASK   0x7FFFFF
#define IEEE_FLOAT_FRACTION_BIT_COUNT       23
#define IEEE_FLOAT_EXPONENT_BITMASK 0x7F800000
#define IEEE_FLOAT_EXPONENT_BIT_COUNT        8
#define IEEE_FLOAT_SIGN_BITMASK     0x80000000
#define IEEE_FLOAT_SIGN_BIT_COUNT            1


/**
 * 6160	70005560
 *     V0= TRUE if F12 a normal single precision float
 *     accepts: F12= single-precision float
 */
s32 crashIsDouble(f32 value)
{
    u32 bits = *(u32*)&value;
    u32 fraction = bits & IEEE_FLOAT_FRACTION_BITMASK;
    u8 exponent = (u8)(bits >> IEEE_FLOAT_FRACTION_BIT_COUNT);
    
    return (fraction == 0) || (exponent != 0 && (exponent != 0xff));
}

/**
 * 61A4	700055A4
 *     V0= TRUE if A1 a normal single precision float; would have set result as short at A0
 *     accepts: A0=(unused) p->target, A1=single-precision float
 */
s32 crashPrintFloat(s32 index, f32 value)
{
    return crashIsDouble(value);
}

/**
 * 61C8	700055C8
 *     removed: set normality of single-precision floats A1, A2, A3, SP+10 in table at A0
 */
void crashPrint4Floats(s32 index, f32 value1, f32 value2, f32 value3, f32 value4)
{
    crashPrintFloat(index, value1);
    crashPrintFloat((index + 2), value2);
    crashPrintFloat((index + 4), value3);
    crashPrintFloat((index + 6), value4);

    return;
}

/**
 * 6228	70005628
 *     unconditional return
 */
void crashRender(void) {
    return;
}


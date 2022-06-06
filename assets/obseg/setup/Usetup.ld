/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
    _UsetupDataStart = ADDR(.data);
    _UsetupDataRomStart = 0x0000;
    .data 0x00000000 : AT(0x0000) {
        * (.data);
    }
    _UsetupDataEnd = ADDR(.data) + SIZEOF(.data);
    _UsetupDataRomEnd = 0x0000 + SIZEOF(.data);

    _UsetupXRODataStart = ADDR(.rodata);
    _UsetupXRODataRomStart = _UsetupDataRomEnd;
    .rodata : AT(_UsetupDataRomEnd) {
        * (.rodata);
    }
    _UsetupXRODataEnd = ADDR( .rodata) + SIZEOF( .rodata);
    _UsetupXRODataRomEnd = _UsetupDataRomEnd + SIZEOF( .rodata);


    /DISCARD/ : {
        * (.MIPS.abiflags);
        * (.options);
        * (.gnu.attributes);
        * (.pdr);
        * (.mdebug);
        * (.gptab.bss);
        * (.gptab.data);
        * (.reginfo);
    }
}
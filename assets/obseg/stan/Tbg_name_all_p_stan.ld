/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
    _UstanDataStart = ADDR(.data);
    _UstanDataRomStart = 0x0000;
    .data 0x00000000 : AT(0x0000) {
        * (.data);
    }
    _UstanDataEnd = ADDR(.data) + SIZEOF(.data);
    _UstanDataRomEnd = 0x0000 + SIZEOF(.data);

    _UstanXRODataStart = ADDR(.rodata);
    _UstanXRODataRomStart = _UstanDataRomEnd;
    .rodata : AT(_UstanDataRomEnd) {
        * (.rodata);
    }
    _UstanXRODataEnd = ADDR( .rodata) + SIZEOF( .rodata);
    _UstanXRODataRomEnd = _UstanDataRomEnd + SIZEOF( .rodata);


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
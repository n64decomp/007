/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _UchrDataStart = ADDR(.data);
   _UchrDataRomStart = 0x0000;
   .data 0x00000000 : AT(0x0000) {
      * (.data);
   }
   _UchrDataEnd = ADDR(.data) + SIZEOF(.data);
   _UchrDataRomEnd = 0x0000 + SIZEOF(.data);


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
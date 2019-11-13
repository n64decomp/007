/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _UbriefDataStart = ADDR(.data);
   _UbriefDataRomStart = 0x0000;
   .data 0x00000000 : AT(0x0000) {
      * (.data);
   }
   _UbriefDataEnd = ADDR(.data) + SIZEOF(.data);
   _UbriefDataRomEnd = 0x0000 + SIZEOF(.data);


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

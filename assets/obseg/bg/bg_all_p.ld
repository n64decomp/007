/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _UbgDataStart = ADDR(.data);
   _UbgDataRomStart = 0x0000;
   .data 0x0F000000 : AT(0x0000) {
      build/assets/obseg/bg/bg_all_p.o (.data);
   }
   _UbgDataEnd = ADDR(.data) + SIZEOF(.data);
   _UbgDataRomEnd = 0x0000 + SIZEOF(.data);


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
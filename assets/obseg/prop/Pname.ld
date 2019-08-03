/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _UpropDataStart = ADDR(.data);
   _UpropDataRomStart = 0x0000;
   .data 0x00000000 : AT(0x0000) {
      build/assets/obseg/prop/Pname.o (.data);
   }
   _UpropDataEnd = ADDR(.data) + SIZEOF(.data);
   _UpropDataRomEnd = 0x0000 + SIZEOF(.data);


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
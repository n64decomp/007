#define BEGIN_SEG(name, rompos, rampos) \
	_##name##SegmentStart = ADDR(.name); \
	_##name##SegmentRomStart = rompos; \
	.name rampos : AT(rompos)

#define END_SEG(name) \
	_##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
	_##name##SegmentRomEnd = _##name##SegmentRomStart + SIZEOF(.name);

/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   
	osTvType = 0x80000300;
	osRomType = 0x80000304;
	osRomBase = 0x80000308;
	osResetType = 0x8000030c;
	osCicId = 0x80000310;
	osVersion = 0x80000314;
	osMemSize = 0x80000318;
	osAppNMIBuffer = 0x8000031c;

	_romSegmentStart = 0;
   /* header */
   BEGIN_SEG(header, _romSegmentStart, 0x04000000)
   {
      build/OUTCODE/src/rom_header.o(.data);
   }
   END_SEG(header)



   /* boot */
   BEGIN_SEG(boot, _headerSegmentRomEnd, 0x04000040)
   {
      build/OUTCODE/src/bootcode.o(.text);
   }
   END_SEG(boot)




   /* 0x80000400, 0x80000450 */
   BEGIN_SEG(start, _bootSegmentRomEnd, 0x80000400)
   {
      build/OUTCODE/src/_start.o (.text);
   }
   END_SEG(start)


   _alt_startSegmentRomStart = _startSegmentRomStart + 0x100000;
   _alt_startSegmentStart = _startSegmentStart - 0x10000000 + 0x100000;
   

   /* 0x70000450, 0x70020D90 001050-021990 */
   BEGIN_SEG(code, _startSegmentRomEnd, (_startSegmentEnd - 0x10000000)) SUBALIGN(16)
   {
#include "ld/lib.text.ld.inc"
   }
   END_SEG(code)


   BEGIN_SEG(cdata, _codeSegmentRomEnd, _codeSegmentRomEnd)
   {
      build/OUTCODE/src/c_data_filler.o (.data);
   }
   END_SEG(cdata)



   /* (0x70200000, 0x702029BC, 0x701CCA70), // 033590-035F4D [29BD] */
   BEGIN_SEG(inflate, _cdataSegmentRomEnd, 0x70200000)
   {
      build/OUTCODE/src/inflate/inflate.o (.text);
      build/OUTCODE/src/inflate/inflate.o (.data);
   }
   END_SEG(inflate)





   /* (0x7F000000, 0x7F0E2D50, 0x7EFCB4D0), // 034B30-117881 [E2D51] */
   BEGIN_SEG(game, _inflateSegmentRomEnd, 0x7F000000)
   {
#include "ld/game.text.ld.inc"
   }
   END_SEG(game)


   BEGIN_SEG(fontdl, _gameSegmentRomEnd, 0x01000000)
   {
      build/OUTCODE/assets/font_dl.o (.data);
   }
   END_SEG(fontdl)

   BEGIN_SEG(jfontchardata, _fontdlSegmentRomEnd, 0x00000000)
   {
      build/OUTCODE/assets/font_chardataj.o (.data);
   }
   END_SEG(jfontchardata)

   BEGIN_SEG(efontchardata, _jfontchardataSegmentRomEnd, 0x00000000)
   {
      build/OUTCODE/assets/font_chardatae.o (.data);
   }
   END_SEG(efontchardata)
   
   BEGIN_SEG(animation_entries, _efontchardataSegmentRomEnd, 0x00000000)
   {
      build/OUTCODE/assets/animationtable_entries.o(.data);
   }
   END_SEG(animation_entries)

   BEGIN_SEG(animation_data, _animation_entriesSegmentRomEnd, 0x00000000)
   {
      build/OUTCODE/assets/animationtable_data.o(.data);
   }
   END_SEG(animation_data)

   BEGIN_SEG(Globalimagetable, _animation_dataSegmentRomEnd, 0x02000000)
   {
      build/OUTCODE/assets/GlobalImageTable.o (.data);
   }
   END_SEG(Globalimagetable)

   BEGIN_SEG(rarewarelogo, _GlobalimagetableSegmentRomEnd, 0x02000000)
   {
      build/OUTCODE/assets/rarewarelogo.o (.data);
   }
   END_SEG(rarewarelogo)

   BEGIN_SEG(romfiles2, _rarewarelogoSegmentRomEnd, _romfiles2SegmentRomStart)
   {
      build/OUTCODE/assets/romfiles2.o (.data);
   }
   END_SEG(romfiles2)

   BEGIN_SEG(ramromfiles, _romfiles2SegmentRomEnd, _ramromfilesSegmentRomStart)
   {
      build/OUTCODE/assets/ramrom/ramrom.o (.data);
   }
   END_SEG(ramromfiles)


   BEGIN_SEG(fontbankgothic, _ramromfilesSegmentRomEnd, 0)
   {
      build/OUTCODE/assets/font/fontBankGothic.o (.data);
   }
   END_SEG(fontbankgothic)

   BEGIN_SEG(fontzurichbold, _fontbankgothicSegmentRomEnd, 0)
   {
      build/OUTCODE/assets/font/fontZurichBold.o (.data);
   }
   END_SEG(fontzurichbold)



   BEGIN_SEG(musicfiles, _fontzurichboldSegmentRomEnd, _musicfilesSegmentRomStart)
   {
      build/OUTCODE/assets/music/sfx.ctl.o (.data);
      build/OUTCODE/assets/music/sfx.tbl.o (.data);
      build/OUTCODE/assets/music/instruments.ctl.o (.data);
      build/OUTCODE/assets/music/instruments.tbl.o (.data);
      build/OUTCODE/assets/music/music.o (.music);
      build/OUTCODE/assets/music/music.o (.musiccompressed);
   }
   END_SEG(musicfiles)



   BEGIN_SEG(obseg, _musicfilesSegmentRomEnd, _obsegSegmentRomStart)
   {
      build/OUTCODE/assets/obseg/ob_seg.o (.data);
   }
   END_SEG(obseg)



   BEGIN_SEG(images, _obsegSegmentRomEnd, _imagesSegmentRomStart)
   {
#include "ld/images.ld.inc"
   }
   END_SEG(images)



	_romSegmentEnd = _imagesSegmentRomEnd;



   __csegtempPos = 0xC00000;
   __dataSegmentVaddrStart = _codeSegmentEnd + 0x10000000;

   BEGIN_SEG(csegment, __csegtempPos, __dataSegmentVaddrStart)
   {
      build/OUTCODE/src/rspboot.o (.text);
      build/OUTCODE/src/gspboot.o (.text);
      build/OUTCODE/src/aspboot.o (.text);
#include "ld/lib.data.ld.inc"
#include "ld/lib.rodata.ld.inc"
#include "ld/game.data.ld.inc"
#include "ld/game.rodata.ld.inc"
      build/OUTCODE/src/gspboot.o (.data);
      build/OUTCODE/src/aspboot.o (.data);
   }
   END_SEG(csegment)

   _dataSegmentVaddrEnd = _csegmentSegmentRomEnd;



   _bssSegmentStart = ADDR(.bss);
   .bss (NOLOAD) :
   {
#include "ld/lib.bss.ld.inc"
#include "ld/game.bss.ld.inc"
   }
   _bssSegmentEnd = ADDR(.bss) + SIZEOF(.bss);
   _bssSegmentSize = SIZEOF(.bss);

   _stacksSegmentStart = ADDR(.stacks);
#if defined(VERSION_EU)
   .stacks 0x803A1AB0 : 
#else
   .stacks 0x803AB400 :
#endif
   {
      build/OUTCODE/src/stacks.o (.bss);
   }
   _stacksSegmentEnd = ADDR(.stacks) + SIZEOF(.stacks);

   _cfbSegmentStart = ADDR(.cfb);
   .cfb (NOLOAD) :
   {
      build/OUTCODE/src/cfb.o (.bss);
   }
   _cfbSegmentEnd = ADDR(.cfb) + SIZEOF(.cfb);

   /*move em to end, out of the way*/
   /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.musicdecompressed);
      * (.options);
      * (.gnu.attributes);
      * (.pdr);
      * (.mdebug);
      * (.gptab.bss);
      * (.gptab.data);
      * (.reginfo);
   }
}

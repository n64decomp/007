/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

#define BEGIN_SEG(name, addr) \
    _##name##SegmentStart = ADDR(.name); \
    _##name##SegmentRomStart = __romPos; \
    .name addr : AT(__romPos)

#define END_SEG(name) \
    _##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
    _##name##SegmentRomEnd = __romPos + SIZEOF(.name); \
    __romPos += SIZEOF(.name);

#define BEGIN_NOLOAD(name) \
    _##name##SegmentNoloadStart = ADDR(.name.noload); \
    .name.noload (NOLOAD) :

#define END_NOLOAD(name) \
    _##name##SegmentNoloadEnd = ADDR(.name.noload) + SIZEOF(.name.noload);

SECTIONS
{
    __romPos = 0;

   BEGIN_SEG(boot, 0x04000000)
   {
      build/rom_header.o(.text);
      build/bootcode.o(.text);
   }
   END_SEG(boot)

   __ramPos = 400;
   BEGIN_SEG(code, 0x80000400)
   {
      build/_start.o (.text);
      build/boot.o (.text);
      build/init.o (.text);
      build/sched.o (.text);
      build/osMapTLB.o (.text);
      build/tlb_manage.o (.text);
      build/tlb_random.o (.text);
      build/tlb_resolve.o (.text);
      build/audi.o (.text);
      build/speed_graph.o (.text);
      build/video.o (.text);
      build/deb.o (.text);
      build/debug_getlastRA.o (.text);
      build/ramrom.o (.text);
      build/boss.o (.text);
      build/music.o (.text);
      build/sfx.o (.text);
      build/memp.o (.text);
      build/mema.o (.text);
      build/random.o (.text);
      build/token.o (.text);
      build/stringhandler.o (.text);
      build/sprintf.o (.text);
      build/pi.o (.text);
      build/vi.o (.text);
      build/debugmenu.o (.text);
      build/joy.o (.text);
      build/joy_rumble.o (.text);
      build/rmon.o (.text);
      build/libultra/libultra.o (.text);
   }
   END_SEG(code)
   __ramPos += SIZEOF(.code);

   .c_data_dummy __romPos : AT(__romPos) {
      * (.c_data_dummy);
   }
   __romPos += SIZEOF(.c_data_dummy);
   
   /* (0x70200000, 0x702029BC, 0x701CCA70), // 033590-035F4D [29BD] */
   BEGIN_SEG(rarezip, 0x70200000)
   {
      build/rarezip/rarezip.o (.text);
      build/rarezip/rarezip.o (.data);
   }
   END_SEG(rarezip)

  
   /* (0x7F000000, 0x7F0E2D50, 0x7EFCB4D0), // 034B30-117881 [E2D51] */
   BEGIN_SEG(game, 0x7F000000)
   {
      build/game/initgamedata.o (.text);
      build/game/initweaponanigroups.o (.text);
      build/game/initactorpropstuff.o (.text);
      build/game/initnull_0009D0.o (.text);
      build/game/initunk_0009E0.o (.text);
      build/game/initanitable.o (.text);
      build/game/initunk_000B60.o (.text);
      build/game/setguscale.o (.text);
      build/game/initnull_000BC0.o (.text);
      build/game/initimages.o (.text);
      build/game/initintromatrices.o (.text);
      build/game/initmenus.o (.text);
      build/game/initguards.o (.text);
      build/game/deb_loadallmodels.o (.text);
      build/game/initobjects.o (.text);
      build/game/prop.o (.text);
      build/game/objective.o (.text);
      build/game/ejectedcartridges.o (.text);
      build/game/initBondDATA.o (.text);
      build/game/initunk_005450.o (.text);
      build/game/initunk_005520.o (.text);
      build/game/initcameraandthrown.o (.text);
      build/game/inititemslots.o (.text);
      build/game/initBondDATAdefaults.o (.text);
      build/game/initpathtablesomething.o (.text);
      build/game/initpathtablelinks.o (.text);
      build/game/initexplosioncasing.o (.text);
      build/game/initunk_007180.o (.text);
      build/game/initunk_007290.o (.text);
      build/game/initunk_0072B0.o (.text);
      build/game/initmttex.o (.text);
      build/game/initunk_0073B0.o (.text);
      build/game/initunk_007460.o (.text);
      build/game/cleanup_alarms.o (.text);
      build/game/cleanup_objects.o (.text);
      build/game/cleanup_objectives.o (.text);
      build/game/cleanupSFXRelated.o (.text);
      build/game/playerstats_007770.o (.text);
      build/game/unk_007800.o (.text);
      build/game/unk_007920.o (.text);
      build/game/null_007970.o (.text);
      build/game/unk_007980.o (.text);
      build/game/intro_logos.o (.text);
      build/game/mainmenu.o (.text);
      build/game/blood_animation.o (.text);
      build/game/blood_decrypt.o (.text);
      build/game/eeprom.o (.text);
      build/game/actor.o (.text);
      build/game/actionblock.o (.text);
      build/game/loadobjectmodel.o (.text);
      build/game/objective_status.o (.text);
      build/game/sin.o (.text);
      build/game/unk_057FD0.o (.text);
      build/game/unk_05A9E0.o (.text);
      build/game/convertangleusinginverse.o (.text);
      build/game/unk_05AB70.o (.text);
      build/game/unk_05ACB0.o (.text);
      build/game/unk_05AE00.o (.text);
      build/game/unk_05B1E0.o (.text);
      build/game/truncf.o (.text);
      build/game/unk_05C440.o (.text);
      build/game/bondview.o (.text);
      build/game/objecthandler.o (.text);
      build/game/othermodemicrocode.o (.text);
      build/game/bond.o (.text);
      build/game/unk_08DBB0.o (.text);
      build/game/debugmenu_08FE00.o (.text);
      build/game/unk_091080.o (.text);
      build/game/cheat_buttons_objectrelated.o (.text);
      build/game/unk_092890.o (.text);
      build/game/unk_092E50.o (.text);
      build/game/unk_093880.o (.text);
      build/game/unk_09B600.o (.text);
      build/game/unk_09B740.o (.text);
      build/game/unk_09B7A0.o (.text);
      build/game/unk_09C250.o (.text);
      build/game/unk_0A1DA0.o (.text);
      build/game/watch.o (.text);
      build/game/textrelated.o (.text);
      build/game/stan.o (.text);
      build/game/unk_0B3200.o (.text);
      build/game/bg.o (.text);
      build/game/fog.o (.text);
      build/game/lightfixture.o (.text);
      build/game/unk_0BC530.o (.text);
      build/game/ob.o (.text);
      build/game/dyn.o (.text);
      build/game/lvl.o (.text);
      build/game/unk_0C0A70.o (.text);
      build/game/mp_music.o (.text);
      build/game/lvl_text.o (.text);
      build/game/mp_watch.o (.text);
      build/game/radar.o (.text);
      build/game/mp_weapon.o (.text);
      build/game/image.o (.text);
      build/game/image_bank.o (.text);
      build/game/unk_0CC4C0.o (.text);
      build/game/decompress.o (.text);
      build/game/zlib.o (.text);
      build/game/rsp.o (.text);
      build/game/indy_comms.o (.text);
      build/game/indy_0D0180.o (.text);
      build/game/game_debug.o (.text);
      build/game/compiletime.o (.text);
      build/game/unk_0D1AC0.o (.text);
      build/game/viewport.o (.text);
      build/game/music_0D2720.o (.text);
      build/game/spectrum.o (.text);
   }
   END_SEG(GAME)
   
   .romfiles 0x117880 : AT(__romPos) {
      * (.romfiles);

      * (.ramrom);

      * (.font);

      * (.music);
      
      * (.musiccompressed);
   }
   __romPos += SIZEOF(.romfiles);

   .ob_seg 0x438660 : AT(__romPos) {
      * (.ob_seg);
   }
   __romPos += SIZEOF(.ob_seg);

   .images : AT(__romPos) {
      * (.images);
   }
   __romPos += SIZEOF(.ob_seg);

   __csegtempPos = 0xC00000;
   __ramPos += 0x80000000;
   .csegment __ramPos : AT(__csegtempPos){
      build/rspboot.o (.text);
      build/gspboot.o (.text);
      build/aspboot.o (.text);
      build/boot.o (.data);
      build/init.o (.data);
      build/sched.o (.data);
      build/osMapTLB.o (.data);
      build/tlb_manage.o (.data);
      build/tlb_random.o (.data);
      build/tlb_resolve.o (.data);
      build/audi.o (.data);
      build/speed_graph.o (.data);
      build/video.o (.data);
      build/deb.o (.data);
      build/debug_getlastRA.o (.data);
      build/ramrom.o (.data);
      build/boss.o (.data);
      build/music.o (.data);
      build/sfx.o (.data);
      build/memp.o (.data);
      build/mema.o (.data);
      build/random.o (.data);
      build/token.o (.data);
      build/stringhandler.o (.data);
      build/sprintf.o (.data);
      build/pi.o (.data);
      build/vi.o (.data);
      build/debugmenu.o (.data);
      build/joy.o (.data);
      build/joy_rumble.o (.data);
      build/rmon.o (.data);
      build/libultra/libultra.o (.data);
      build/boot.o (.rodata);
      build/init.o (.rodata);
      build/sched.o (.rodata);
      build/osMapTLB.o (.rodata);
      build/tlb_manage.o (.rodata);
      build/tlb_random.o (.rodata);
      build/tlb_resolve.o (.rodata);
      build/audi.o (.rodata);
      build/speed_graph.o (.rodata);
      build/video.o (.rodata);
      build/deb.o (.rodata);
      build/debug_getlastRA.o (.rodata);
      build/ramrom.o (.rodata);
      build/boss.o (.rodata);
      build/music.o (.rodata);
      build/sfx.o (.rodata);
      build/memp.o (.rodata);
      build/mema.o (.rodata);
      build/random.o (.rodata);
      build/token.o (.rodata);
      build/stringhandler.o (.rodata);
      build/sprintf.o (.rodata);
      build/pi.o (.rodata);
      build/vi.o (.rodata);
      build/debugmenu.o (.rodata);
      build/joy.o (.rodata);
      build/joy_rumble.o (.rodata);
      build/rmon.o (.rodata);
      build/libultra/libultra.o (.rodata);
      build/game/initgamedata.o (.data);
      build/game/initweaponanigroups.o (.data);
      build/game/initactorpropstuff.o (.data);
      build/game/initnull_0009D0.o (.data);
      build/game/initunk_0009E0.o (.data);
      build/game/initanitable.o (.data);
      build/game/initunk_000B60.o (.data);
      build/game/setguscale.o (.data);
      build/game/initnull_000BC0.o (.data);
      build/game/initimages.o (.data);
      build/game/initintromatrices.o (.data);
      build/game/initmenus.o (.data);
      build/game/initguards.o (.data);
      build/game/deb_loadallmodels.o (.data);
      build/game/initobjects.o (.data);
      build/game/prop.o (.data);
      build/game/objective.o (.data);
      build/game/ejectedcartridges.o (.data);
      build/game/initBondDATA.o (.data);
      build/game/initunk_005450.o (.data);
      build/game/initunk_005520.o (.data);
      build/game/initcameraandthrown.o (.data);
      build/game/inititemslots.o (.data);
      build/game/initBondDATAdefaults.o (.data);
      build/game/initpathtablesomething.o (.data);
      build/game/initpathtablelinks.o (.data);
      build/game/initexplosioncasing.o (.data);
      build/game/initunk_007180.o (.data);
      build/game/initunk_007290.o (.data);
      build/game/initunk_0072B0.o (.data);
      build/game/initmttex.o (.data);
      build/game/initunk_0073B0.o (.data);
      build/game/initunk_007460.o (.data);
      build/game/cleanup_alarms.o (.data);
      build/game/cleanup_objects.o (.data);
      build/game/cleanup_objectives.o (.data);
      build/game/cleanupSFXRelated.o (.data);
      build/game/playerstats_007770.o (.data);
      build/game/unk_007800.o (.data);
      build/game/unk_007920.o (.data);
      build/game/null_007970.o (.data);
      build/game/unk_007980.o (.data);
      build/game/intro_logos.o (.data);
      build/game/mainmenu.o (.data);
      build/game/blood_animation.o (.data);
      build/game/blood_decrypt.o (.data);
      build/game/eeprom.o (.data);
      build/game/actor.o (.data);
      build/game/actionblock.o (.data);
      build/game/loadobjectmodel.o (.data);
      build/game/objective_status.o (.data);
      build/game/sin.o (.data);
      build/game/unk_057FD0.o (.data);
      build/game/unk_05A9E0.o (.data);
      build/game/convertangleusinginverse.o (.data);
      build/game/unk_05AB70.o (.data);
      build/game/unk_05ACB0.o (.data);
      build/game/unk_05AE00.o (.data);
      build/game/unk_05B1E0.o (.data);
      build/game/truncf.o (.data);
      build/game/unk_05C440.o (.data);
      build/game/bondview.o (.data);
      build/game/objecthandler.o (.data);
      build/game/othermodemicrocode.o (.data);
      build/game/bond.o (.data);
      build/game/unk_08DBB0.o (.data);
      build/game/debugmenu_08FE00.o (.data);
      build/game/unk_091080.o (.data);
      build/game/cheat_buttons_objectrelated.o (.data);
      build/game/unk_092890.o (.data);
      build/game/unk_092E50.o (.data);
      build/game/unk_093880.o (.data);
      build/game/unk_09B600.o (.data);
      build/game/unk_09B740.o (.data);
      build/game/unk_09B7A0.o (.data);
      build/game/unk_09C250.o (.data);
      build/game/unk_0A1DA0.o (.data);
      build/game/watch.o (.data);
      build/game/textrelated.o (.data);
      build/game/stan.o (.data);
      build/game/unk_0B3200.o (.data);
      build/game/bg.o (.data);
      build/game/fog.o (.data);
      build/game/lightfixture.o (.data);
      build/game/unk_0BC530.o (.data);
      build/game/ob.o (.data);
      build/game/dyn.o (.data);
      build/game/lvl.o (.data);
      build/game/unk_0C0A70.o (.data);
      build/game/mp_music.o (.data);
      build/game/lvl_text.o (.data);
      build/game/mp_watch.o (.data);
      build/game/radar.o (.data);
      build/game/mp_weapon.o (.data);
      build/game/image.o (.data);
      build/game/image_bank.o (.data);
      build/game/unk_0CC4C0.o (.data);
      build/game/decompress.o (.data);
      build/game/zlib.o (.data);
      build/game/rsp.o (.data);
      build/game/indy_comms.o (.data);
      build/game/indy_0D0180.o (.data);
      build/game/game_debug.o (.data);
      build/game/compiletime.o (.data);
      build/game/unk_0D1AC0.o (.data);
      build/game/viewport.o (.data);
      build/game/music_0D2720.o (.data);
      build/game/spectrum.o (.data);
      build/game/initgamedata.o (.rodata);
      build/game/initweaponanigroups.o (.rodata);
      build/game/initactorpropstuff.o (.rodata);
      build/game/initnull_0009D0.o (.rodata);
      build/game/initunk_0009E0.o (.rodata);
      build/game/initanitable.o (.rodata);
      build/game/initunk_000B60.o (.rodata);
      build/game/setguscale.o (.rodata);
      build/game/initnull_000BC0.o (.rodata);
      build/game/initimages.o (.rodata);
      build/game/initintromatrices.o (.rodata);
      build/game/initmenus.o (.rodata);
      build/game/initguards.o (.rodata);
      build/game/deb_loadallmodels.o (.rodata);
      build/game/initobjects.o (.rodata);
      build/game/prop.o (.rodata);
      build/game/objective.o (.rodata);
      build/game/ejectedcartridges.o (.rodata);
      build/game/initBondDATA.o (.rodata);
      build/game/initunk_005450.o (.rodata);
      build/game/initunk_005520.o (.rodata);
      build/game/initcameraandthrown.o (.rodata);
      build/game/inititemslots.o (.rodata);
      build/game/initBondDATAdefaults.o (.rodata);
      build/game/initpathtablesomething.o (.rodata);
      build/game/initpathtablelinks.o (.rodata);
      build/game/initexplosioncasing.o (.rodata);
      build/game/initunk_007180.o (.rodata);
      build/game/initunk_007290.o (.rodata);
      build/game/initunk_0072B0.o (.rodata);
      build/game/initmttex.o (.rodata);
      build/game/initunk_0073B0.o (.rodata);
      build/game/initunk_007460.o (.rodata);
      build/game/cleanup_alarms.o (.rodata);
      build/game/cleanup_objects.o (.rodata);
      build/game/cleanup_objectives.o (.rodata);
      build/game/cleanupSFXRelated.o (.rodata);
      build/game/playerstats_007770.o (.rodata);
      build/game/unk_007800.o (.rodata);
      build/game/unk_007920.o (.rodata);
      build/game/null_007970.o (.rodata);
      build/game/unk_007980.o (.rodata);
      build/game/intro_logos.o (.rodata);
      build/game/mainmenu.o (.rodata);
      build/game/blood_animation.o (.rodata);
      build/game/blood_decrypt.o (.rodata);
      build/game/eeprom.o (.rodata);
      build/game/actor.o (.rodata);
      build/game/actionblock.o (.rodata);
      build/game/loadobjectmodel.o (.rodata);
      build/game/objective_status.o (.rodata);
      build/game/sin.o (.rodata);
      build/game/unk_057FD0.o (.rodata);
      build/game/unk_05A9E0.o (.rodata);
      build/game/convertangleusinginverse.o (.rodata);
      build/game/unk_05AB70.o (.rodata);
      build/game/unk_05ACB0.o (.rodata);
      build/game/unk_05AE00.o (.rodata);
      build/game/unk_05B1E0.o (.rodata);
      build/game/truncf.o (.rodata);
      build/game/unk_05C440.o (.rodata);
      build/game/bondview.o (.rodata);
      build/game/objecthandler.o (.rodata);
      build/game/othermodemicrocode.o (.rodata);
      build/game/bond.o (.rodata);
      build/game/unk_08DBB0.o (.rodata);
      build/game/debugmenu_08FE00.o (.rodata);
      build/game/unk_091080.o (.rodata);
      build/game/cheat_buttons_objectrelated.o (.rodata);
      build/game/unk_092890.o (.rodata);
      build/game/unk_092E50.o (.rodata);
      build/game/unk_093880.o (.rodata);
      build/game/unk_09B600.o (.rodata);
      build/game/unk_09B740.o (.rodata);
      build/game/unk_09B7A0.o (.rodata);
      build/game/unk_09C250.o (.rodata);
      build/game/unk_0A1DA0.o (.rodata);
      build/game/watch.o (.rodata);
      build/game/textrelated.o (.rodata);
      build/game/stan.o (.rodata);
      build/game/unk_0B3200.o (.rodata);
      build/game/bg.o (.rodata);
      build/game/fog.o (.rodata);
      build/game/lightfixture.o (.rodata);
      build/game/unk_0BC530.o (.rodata);
      build/game/ob.o (.rodata);
      build/game/dyn.o (.rodata);
      build/game/lvl.o (.rodata);
      build/game/unk_0C0A70.o (.rodata);
      build/game/mp_music.o (.rodata);
      build/game/lvl_text.o (.rodata);
      build/game/mp_watch.o (.rodata);
      build/game/radar.o (.rodata);
      build/game/mp_weapon.o (.rodata);
      build/game/image.o (.rodata);
      build/game/image_bank.o (.rodata);
      build/game/unk_0CC4C0.o (.rodata);
      build/game/decompress.o (.rodata);
      build/game/zlib.o (.rodata);
      build/game/rsp.o (.rodata);
      build/game/indy_comms.o (.rodata);
      build/game/indy_0D0180.o (.rodata);
      build/game/game_debug.o (.rodata);
      build/game/compiletime.o (.rodata);
      build/game/unk_0D1AC0.o (.rodata);
      build/game/viewport.o (.rodata);
      build/game/music_0D2720.o (.rodata);
      build/game/spectrum.o (.rodata);
      build/gspboot.o (.data);
      build/aspboot.o (.data);
   }
   __ramPos += SIZEOF(.csegment);
   __csegtempPos += SIZEOF(.csegment);
   .bss __ramPos : AT(__csegtempPos){
      build/boot.o (.bss);
      build/init.o (.bss);
      build/sched.o (.bss);
      build/osMapTLB.o (.bss);
      build/tlb_manage.o (.bss);
      build/tlb_random.o (.bss);
      build/tlb_resolve.o (.bss);
      build/audi.o (.bss);
      build/speed_graph.o (.bss);
      build/video.o (.bss);
      build/deb.o (.bss);
      build/debug_getlastRA.o (.bss);
      build/ramrom.o (.bss);
      build/boss.o (.bss);
      build/music.o (.bss);
      build/sfx.o (.bss);
      build/memp.o (.bss);
      build/mema.o (.bss);
      build/random.o (.bss);
      build/token.o (.bss);
      build/stringhandler.o (.bss);
      build/sprintf.o (.bss);
      build/pi.o (.bss);
      build/vi.o (.bss);
      build/debugmenu.o (.bss);
      build/joy.o (.bss);
      build/joy_rumble.o (.bss);
      build/rmon.o (.bss);
      build/libultra/libultra.o (.bss);
      build/game/initgamedata.o (.bss);
      build/game/initweaponanigroups.o (.bss);
      build/game/initactorpropstuff.o (.bss);
      build/game/initnull_0009D0.o (.bss);
      build/game/initunk_0009E0.o (.bss);
      build/game/initanitable.o (.bss);
      build/game/initunk_000B60.o (.bss);
      build/game/setguscale.o (.bss);
      build/game/initnull_000BC0.o (.bss);
      build/game/initimages.o (.bss);
      build/game/initintromatrices.o (.bss);
      build/game/initmenus.o (.bss);
      build/game/initguards.o (.bss);
      build/game/deb_loadallmodels.o (.bss);
      build/game/initobjects.o (.bss);
      build/game/prop.o (.bss);
      build/game/objective.o (.bss);
      build/game/ejectedcartridges.o (.bss);
      build/game/initBondDATA.o (.bss);
      build/game/initunk_005450.o (.bss);
      build/game/initunk_005520.o (.bss);
      build/game/initcameraandthrown.o (.bss);
      build/game/inititemslots.o (.bss);
      build/game/initBondDATAdefaults.o (.bss);
      build/game/initpathtablesomething.o (.bss);
      build/game/initpathtablelinks.o (.bss);
      build/game/initexplosioncasing.o (.bss);
      build/game/initunk_007180.o (.bss);
      build/game/initunk_007290.o (.bss);
      build/game/initunk_0072B0.o (.bss);
      build/game/initmttex.o (.bss);
      build/game/initunk_0073B0.o (.bss);
      build/game/initunk_007460.o (.bss);
      build/game/cleanup_alarms.o (.bss);
      build/game/cleanup_objects.o (.bss);
      build/game/cleanup_objectives.o (.bss);
      build/game/cleanupSFXRelated.o (.bss);
      build/game/playerstats_007770.o (.bss);
      build/game/unk_007800.o (.bss);
      build/game/unk_007920.o (.bss);
      build/game/null_007970.o (.bss);
      build/game/unk_007980.o (.bss);
      build/game/intro_logos.o (.bss);
      build/game/mainmenu.o (.bss);
      build/game/blood_animation.o (.bss);
      build/game/blood_decrypt.o (.bss);
      build/game/eeprom.o (.bss);
      build/game/actor.o (.bss);
      build/game/actionblock.o (.bss);
      build/game/loadobjectmodel.o (.bss);
      build/game/objective_status.o (.bss);
      build/game/sin.o (.bss);
      build/game/unk_057FD0.o (.bss);
      build/game/unk_05A9E0.o (.bss);
      build/game/convertangleusinginverse.o (.bss);
      build/game/unk_05AB70.o (.bss);
      build/game/unk_05ACB0.o (.bss);
      build/game/unk_05AE00.o (.bss);
      build/game/unk_05B1E0.o (.bss);
      build/game/truncf.o (.bss);
      build/game/unk_05C440.o (.bss);
      build/game/bondview.o (.bss);
      build/game/objecthandler.o (.bss);
      build/game/othermodemicrocode.o (.bss);
      build/game/bond.o (.bss);
      build/game/unk_08DBB0.o (.bss);
      build/game/debugmenu_08FE00.o (.bss);
      build/game/unk_091080.o (.bss);
      build/game/cheat_buttons_objectrelated.o (.bss);
      build/game/unk_092890.o (.bss);
      build/game/unk_092E50.o (.bss);
      build/game/unk_093880.o (.bss);
      build/game/unk_09B600.o (.bss);
      build/game/unk_09B740.o (.bss);
      build/game/unk_09B7A0.o (.bss);
      build/game/unk_09C250.o (.bss);
      build/game/unk_0A1DA0.o (.bss);
      build/game/watch.o (.bss);
      build/game/textrelated.o (.bss);
      build/game/stan.o (.bss);
      build/game/unk_0B3200.o (.bss);
      build/game/bg.o (.bss);
      build/game/fog.o (.bss);
      build/game/lightfixture.o (.bss);
      build/game/unk_0BC530.o (.bss);
      build/game/ob.o (.bss);
      build/game/dyn.o (.bss);
      build/game/lvl.o (.bss);
      build/game/unk_0C0A70.o (.bss);
      build/game/mp_music.o (.bss);
      build/game/lvl_text.o (.bss);
      build/game/mp_watch.o (.bss);
      build/game/radar.o (.bss);
      build/game/mp_weapon.o (.bss);
      build/game/image.o (.bss);
      build/game/image_bank.o (.bss);
      build/game/unk_0CC4C0.o (.bss);
      build/game/decompress.o (.bss);
      build/game/zlib.o (.bss);
      build/game/rsp.o (.bss);
      build/game/indy_comms.o (.bss);
      build/game/indy_0D0180.o (.bss);
      build/game/game_debug.o (.bss);
      build/game/compiletime.o (.bss);
      build/game/unk_0D1AC0.o (.bss);
      build/game/viewport.o (.bss);
      build/game/music_0D2720.o (.bss);
      build/game/spectrum.o (.bss);
   }   
   __ramPos += SIZEOF(.csegment);
   __csegtempPos += SIZEOF(.csegment);


   /*move em to end, out of the way*/
   /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.musicdecompressed);
   }
}

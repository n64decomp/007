      build/OUTCODE/src/boot.o (.bss);
      build/OUTCODE/src/init.o (.bss);
      build/OUTCODE/src/sched.o (.bss);
      build/OUTCODE/src/osMapTLB.o (.bss);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.bss);
      build/OUTCODE/src/libultrare/io/pimgr.o (.bss);
#endif
      build/OUTCODE/src/tlb_manage.o (.bss);
      build/OUTCODE/src/tlb_random.o (.bss);
      build/OUTCODE/src/tlb_resolve.o (.bss);
      build/OUTCODE/src/audi.o (.bss);
      build/OUTCODE/src/speed_graph.o (.bss);
      build/OUTCODE/src/fr.o (.bss);
      build/OUTCODE/src/deb.o (.bss);
      build/OUTCODE/src/crash.o (.bss);
      /*deb_print may be part of fault per pd beta (.bss);*/
      /*build/OUTCODE/src/deb_print.o (.bss);*/
      build/OUTCODE/src/getra.o (.bss);
      build/OUTCODE/src/ramrom.o (.bss);
      build/OUTCODE/src/boss.o (.bss);
      build/OUTCODE/src/music.o (.bss);
      build/OUTCODE/src/snd.o (.bss);
      build/OUTCODE/src/memp.o (.bss);
      build/OUTCODE/src/mema.o (.bss);
      build/OUTCODE/src/random.o (.bss);
      build/OUTCODE/src/token.o (.bss);
      build/OUTCODE/src/str.o (.bss);
      build/OUTCODE/src/sprintf.o (.bss);
      build/OUTCODE/src/pi.o (.bss);
      build/OUTCODE/src/vi.o (.bss);
      build/OUTCODE/src/debugmenu.o (.bss);
      build/OUTCODE/src/joy.o (.bss);
      build/OUTCODE/src/motor.o (.bss);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.bss);
#endif
      build/OUTCODE/src/rmon.o (.bss);
#ifdef ENABLE_USB
      build/OUTCODE/src/usb.o (.bss);
#endif
      /*build/OUTCODE/src/libultra/osPiRawStartDma.o (.bss);*/
      build/OUTCODE/src/libultra/io/pirawdma.o (.bss);
      build/OUTCODE/src/libultra/io/pigetstat.o (.bss);
      build/OUTCODE/src/libultrare/os/initialize.o (.bss);
      build/OUTCODE/src/libultra/os/writebackdcacheall.o (.bss);
      build/OUTCODE/src/libultra/os/invalicache.o (.bss);
      build/OUTCODE/src/libultra/os/unmaptlb.o (.bss);
      build/OUTCODE/src/libultra/os/getfpccsr.o (.bss);
      build/OUTCODE/src/libultra/os/setfpccsr.o (.bss);
      build/OUTCODE/src/libultra/os/createthread.o (.bss);
      build/OUTCODE/src/libultra/os/startthread.o (.bss);
      build/OUTCODE/src/libultra/os/createmesgqueue.o (.bss);
      build/OUTCODE/src/libultra/os/parameters.o (.bss);
      build/OUTCODE/src/libultra/os/stopthread.o (.bss);
      build/OUTCODE/src/libultra/os/setthreadpri.o (.bss);
      build/OUTCODE/src/libultra/os/getcount.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.bss);
#endif
      build/OUTCODE/src/libultrare/io/vitbl.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/os/seteventmesg.o (.bss);
      build/OUTCODE/src/libultra/io/visetevent.o (.bss);
      build/OUTCODE/src/libultra/os/setintmask.o (.bss);
      build/OUTCODE/src/libultra/os/recvmesg.o (.bss);
      build/OUTCODE/src/libultra/os/sendmesg.o (.bss);
      build/OUTCODE/src/libultra/io/visetmode.o (.bss);
      build/OUTCODE/src/libultra/io/visetxscale.o (.bss);
      build/OUTCODE/src/libultra/io/visetyscale.o (.bss);
      build/OUTCODE/src/libultra/io/virepeatline.o (.bss);
      build/OUTCODE/src/libultra/io/viblack.o (.bss);
      build/OUTCODE/src/libultra/io/sptaskyielded.o (.bss);
      build/OUTCODE/src/libultra/io/dpctr.o (.bss);
      build/OUTCODE/src/libultra/io/vigetcurrframebuf.o (.bss);
      build/OUTCODE/src/libultra/io/vigetnextframebuf.o (.bss);
      build/OUTCODE/src/libultra/io/viswapbuf.o (.bss);
      build/OUTCODE/src/libultra/io/dpsetstat.o (.bss);
      build/OUTCODE/src/libultrare/io/sptask.o (.bss);
      build/OUTCODE/src/libultra/io/dpsetnextbuf.o (.bss);
      build/OUTCODE/src/libultra/io/sptaskyield.o (.bss);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/timerintr.o (.bss);
      build/OUTCODE/src/libultra/os/getthreadpri.o (.bss);
      build/OUTCODE/src/libultra/os/interrupt.o (.bss);
      build/OUTCODE/src/libultrare/io/vi.o (.bss);
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.bss);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.bss);
      build/OUTCODE/src/libultra/io/piacs.o (.bss);
      build/OUTCODE/src/libultrare/io/epirawdma.o (.bss);
      build/OUTCODE/src/libultrare/io/devmgr.o (.bss);
#endif
      build/OUTCODE/src/libultra/os/gettlbhi.o (.bss);
      build/OUTCODE/src/libultra/os/virtualtophysical.o (.bss);
      build/OUTCODE/src/libultra/io/aisetfreq.o (.bss);
      build/OUTCODE/src/libultra/audio/sl.o (.bss);
      build/OUTCODE/src/libultra/audio/heapalloc.o (.bss);
      build/OUTCODE/src/libultra/os/gettime.o (.bss);
      build/OUTCODE/src/libultra/libc/ll.o (.bss); /*edited*/
      build/OUTCODE/src/libultrare/io/aisetnextbuf.o (.bss);
      build/OUTCODE/src/libultra/io/aigetlen.o (.bss);
      build/OUTCODE/src/libultra/audio/synthesizer.o (.bss);
      build/OUTCODE/src/libultra/io/pidma.o (.bss);
      build/OUTCODE/src/libultra/io/visetspecial.o (.bss);
      build/OUTCODE/src/libultra/libc/bcopy.o (.bss);
      build/OUTCODE/src/libultra/gu/perspective.o (.bss);
      build/OUTCODE/src/libultra/gu/mtxutil.o (.bss);
      build/OUTCODE/src/libultra/os/getcurrfaultthread.o (.bss);
      build/OUTCODE/src/libultra/os/exception.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/os/thread.o (.bss);
      build/OUTCODE/src/libultra/os/yieldthread.o (.bss);
      build/OUTCODE/src/libultra/os/invaldcache.o (.bss);
      build/OUTCODE/src/libultra/os/writebackdcache.o (.bss);
      build/OUTCODE/src/libultra/os/settimer.o (.bss);
      build/OUTCODE/src/libultra/audio/heapinit.o (.bss);
      build/OUTCODE/src/libultra/audio/bnkf.o (.bss);
      build/OUTCODE/src/libultra/audio/csplayer.o (.bss);
      build/OUTCODE/src/libultra/audio/seqpsetbank.o (.bss);
      build/OUTCODE/src/libultra/audio/cspgetstate.o (.bss);
      build/OUTCODE/src/libultra/audio/cseq.o (.bss);
      build/OUTCODE/src/libultra/audio/cspsetseq.o (.bss);
      build/OUTCODE/src/libultra/audio/cspplay.o (.bss);
      build/OUTCODE/src/libultra/audio/cspstop.o (.bss);
      build/OUTCODE/src/libultra/audio/cspsetvol.o (.bss);
      build/OUTCODE/src/libultra/audio/event.o (.bss);
      build/OUTCODE/src/libultra/audio/synaddplayer.o (.bss);
      build/OUTCODE/src/libultra/audio/synallocvoice.o (.bss);
      build/OUTCODE/src/libultra/audio/synsetvol.o (.bss);
      build/OUTCODE/src/libultra/audio/synstartvoice.o (.bss);
      build/OUTCODE/src/libultra/audio/synsetpan.o (.bss);
      build/OUTCODE/src/libultra/audio/synsetpitch.o (.bss);
      build/OUTCODE/src/libultra/audio/synsetfxmix.o (.bss);
      build/OUTCODE/src/libultra/audio/synstopvoice.o (.bss);
      build/OUTCODE/src/libultra/audio/synfreevoice.o (.bss);
      build/OUTCODE/src/libultra/audio/cents2ratio.o (.bss);
      build/OUTCODE/src/libultra/io/piread.o (.bss);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/piwrite.o (.bss);
#endif
      build/OUTCODE/src/libultra/libc/string.o (.bss);
      build/OUTCODE/src/libultrare/libc/xprintf.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/pimgr.o (.bss);
#endif
      build/OUTCODE/src/libultrare/io/pfsinit.o (.bss);
      build/OUTCODE/src/libultrare/io/controller.o (.bss);
      build/OUTCODE/src/libultra/io/contquery.o (.bss);
      build/OUTCODE/src/libultrare/io/contreaddata.o (.bss);
      build/OUTCODE/src/libultrare/io/conteepprobe.o (.bss);
      build/OUTCODE/src/libultrare/io/conteepread.o (.bss);
      build/OUTCODE/src/libultrare/io/conteepwrite.o (.bss);
      build/OUTCODE/src/libultrare/io/conteeplongread.o (.bss);
      build/OUTCODE/src/libultrare/io/conteeplongwrite.o (.bss);
      build/OUTCODE/src/libultrare/io/pfsisplug.o (.bss);
      build/OUTCODE/src/libultra/io/siacs.o (.bss);
      build/OUTCODE/src/libultra/io/sirawdma.o (.bss);
      build/OUTCODE/src/libultra/io/crc.o (.bss);
      build/OUTCODE/src/libultrare/io/contramwrite.o (.bss);
      build/OUTCODE/src/libultrare/io/contramread.o (.bss);
      build/OUTCODE/src/libultra/gu/align.o (.bss);
      build/OUTCODE/src/libultra/gu/ortho.o (.bss);
      build/OUTCODE/src/libultra/gu/coss.o (.bss);
      build/OUTCODE/src/libultra/gu/sins.o (.bss);
      build/OUTCODE/src/libultra/gu/translate.o (.bss);
      build/OUTCODE/src/libultra/libc/bcmp.o (.bss);
      build/OUTCODE/src/libultra/gu/scale.o (.bss);
      build/OUTCODE/src/libultra/gu/lookatref.o (.bss);
      build/OUTCODE/src/libultra/gu/lookat.o (.bss);
      build/OUTCODE/src/libultra/gu/rotate.o (.bss);
      build/OUTCODE/src/libultra/libc/llcvt.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/os/setsr.o (.bss);
      build/OUTCODE/src/libultra/os/getsr.o (.bss);
      build/OUTCODE/src/libultra/io/sirawread.o (.bss);
      build/OUTCODE/src/libultra/io/sirawwrite.o (.bss);
      build/OUTCODE/src/libultra/io/pirawread.o (.bss);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/pirawwrite.o (.bss);
#endif
      build/OUTCODE/src/libultra/libc/bzero.o (.bss);
      build/OUTCODE/src/libultra/os/sethwinterrupt.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.bss);
      build/OUTCODE/src/libultra/os/interrupt.o (.bss);
      build/OUTCODE/src/libultra/os/timerintr.o (.bss);
#endif
      build/OUTCODE/src/libultra/os/kdebugserver.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/getthreadpri.o (.bss);
      build/OUTCODE/src/libultrare/io/vi.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.bss);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.bss);
#endif
      build/OUTCODE/src/libultra/io/spgetstat.o (.bss);
      build/OUTCODE/src/libultra/io/spsetstat.o (.bss);
      build/OUTCODE/src/libultra/io/spsetpc.o (.bss);
      build/OUTCODE/src/libultra/io/sprawdma.o (.bss);
      build/OUTCODE/src/libultra/io/sp.o (.bss);
      build/OUTCODE/src/libultra/io/dp.o (.bss);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/setcompare.o (.bss);
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.bss);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.bss);
#endif      
      build/OUTCODE/src/libultra/os/probetlb.o (.bss);
      build/OUTCODE/src/libultra/audio/syndelete.o (.bss);
      build/OUTCODE/src/libultra/io/ai.o (.bss);
      build/OUTCODE/src/libultrare/audio/drvrNew.o (.bss);
      build/OUTCODE/src/libultra/audio/synallocfx.o (.bss);
      build/OUTCODE/src/libultra/audio/mainbus.o (.bss);
      build/OUTCODE/src/libultra/audio/load.o (.bss);
      build/OUTCODE/src/libultra/audio/resample.o (.bss);
      build/OUTCODE/src/libultrare/audio/env.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/audio/auxbus.o (.bss);
      build/OUTCODE/src/libultra/audio/save.o (.bss);
      build/OUTCODE/src/libultra/os/jammesg.o (.bss);
      build/OUTCODE/src/libultra/io/pigetcmdq.o (.bss);
      build/OUTCODE/src/libultra/gu/cosf.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/gu/sinf.o (.bss); /*edited*/
      build/OUTCODE/src/libultrare/os/destroythread.o (.bss);
      build/OUTCODE/src/libultra/audio/seqplayer.o (.bss);
      build/OUTCODE/src/libultra/audio/synstartvoiceparam.o (.bss);
      build/OUTCODE/src/libultra/audio/copy.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/io/piacs.o (.bss);
#endif
      build/OUTCODE/src/libultra/libc/xlitob.o (.bss);
      build/OUTCODE/src/libultra/libc/xldtob.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/epirawdma.o (.bss);
      build/OUTCODE/src/libultrare/io/devmgr.o (.bss);
#endif
      build/OUTCODE/src/libultra/io/contpfs.o (.bss);
      build/OUTCODE/src/libultra/io/si.o (.bss);
      build/OUTCODE/src/libultra/gu/normalize.o (.bss);
      build/OUTCODE/src/libultra/gu/sqrtf.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leodiskinit.o (.bss);
      build/OUTCODE/src/libultra/os/setcompare.o (.bss);
#endif
      build/OUTCODE/src/libultra/audio/filter.o (.bss);
      build/OUTCODE/src/libultrare/audio/reverb.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/gu/libm_vals.o (.bss); /*edited*/
      build/OUTCODE/src/libultra/audio/seq.o (.bss);
      build/OUTCODE/src/libultra/audio/synsetpriority.o (.bss);
      build/OUTCODE/src/libultra/libc/ldiv.o (.bss);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.bss);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.bss);
#endif
      build/OUTCODE/src/libultra/io/vimodentsclan1.o (.bss);
      build/OUTCODE/src/libultrare/io/vimodepallan1.o (.bss);
      build/OUTCODE/src/libultrare/ultra80069080.o (.bss); /*edited*/
      /*build/OUTCODE/src/libultra/libultra.a:libultra.o (.bss);*/

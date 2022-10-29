      build/OUTCODE/src/aspboot.o (.rodata);
      build/OUTCODE/src/boot.o (.rodata);
      build/OUTCODE/src/init.o (.rodata);
      build/OUTCODE/src/sched.o (.rodata);
      build/OUTCODE/src/osMapTLB.o (.rodata);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.rodata);
      build/OUTCODE/src/libultrare/io/pimgr.o (.rodata);
#endif
      build/OUTCODE/src/tlb_manage.o (.rodata);
      build/OUTCODE/src/tlb_random.o (.rodata);
      build/OUTCODE/src/tlb_resolve.o (.rodata);
      build/OUTCODE/src/tlb_hardwire.o (.rodata);
      build/OUTCODE/src/audi.o (.rodata);
      build/OUTCODE/src/speed_graph.o (.rodata);
      build/OUTCODE/src/fr.o (.rodata);
      build/OUTCODE/src/deb.o (.rodata);
      build/OUTCODE/src/crash.o (.rodata);
      /*deb_print may be part of fault per pd beta (.rodata);*/
      /*build/OUTCODE/src/deb_print.o (.rodata);*/
      build/OUTCODE/src/getra.o (.rodata);
      build/OUTCODE/src/ramrom.o (.rodata);
      build/OUTCODE/src/boss.o (.rodata);
      build/OUTCODE/src/music.o (.rodata);
      build/OUTCODE/src/snd.o (.rodata);
      build/OUTCODE/src/memp.o (.rodata);
      build/OUTCODE/src/mema.o (.rodata);
      build/OUTCODE/src/random.o (.rodata);
      build/OUTCODE/src/token.o (.rodata);
      build/OUTCODE/src/str.o (.rodata);
      build/OUTCODE/src/sprintf.o (.rodata);
      build/OUTCODE/src/pi.o (.rodata);
      build/OUTCODE/src/vi.o (.rodata);
      build/OUTCODE/src/debugmenu.o (.rodata);
      build/OUTCODE/src/joy.o (.rodata);
      build/OUTCODE/src/motor.o (.rodata);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.rodata);
#endif
      build/OUTCODE/src/rmon.o (.rodata);
#ifdef ENABLE_USB
      build/OUTCODE/src/usb.o (.rodata);
#endif
      /*build/OUTCODE/src/libultra/osPiRawStartDma.o (.rodata);*/
      build/OUTCODE/src/libultra/io/pirawdma.o (.rodata);
      build/OUTCODE/src/libultra/io/pigetstat.o (.rodata);
      build/OUTCODE/src/libultrare/os/initialize.o (.rodata);
      build/OUTCODE/src/libultra/os/writebackdcacheall.o (.rodata);
      build/OUTCODE/src/libultra/os/invalicache.o (.rodata);
      build/OUTCODE/src/libultra/os/unmaptlb.o (.rodata);
      build/OUTCODE/src/libultra/os/getfpccsr.o (.rodata);
      build/OUTCODE/src/libultra/os/setfpccsr.o (.rodata);
      build/OUTCODE/src/libultra/os/createthread.o (.rodata);
      build/OUTCODE/src/libultra/os/startthread.o (.rodata);
      build/OUTCODE/src/libultra/os/createmesgqueue.o (.rodata);
      build/OUTCODE/src/libultra/os/parameters.o (.rodata);
      build/OUTCODE/src/libultra/os/stopthread.o (.rodata);
      build/OUTCODE/src/libultra/os/setthreadpri.o (.rodata);
      build/OUTCODE/src/libultra/os/getcount.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.rodata);
#endif
      build/OUTCODE/src/libultrare/io/vitbl.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/os/seteventmesg.o (.rodata);
      build/OUTCODE/src/libultra/io/visetevent.o (.rodata);
      build/OUTCODE/src/libultra/os/setintmask.o (.rodata);
      build/OUTCODE/src/libultra/os/recvmesg.o (.rodata);
      build/OUTCODE/src/libultra/os/sendmesg.o (.rodata);
      build/OUTCODE/src/libultra/io/visetmode.o (.rodata);
      build/OUTCODE/src/libultra/io/visetxscale.o (.rodata);
      build/OUTCODE/src/libultra/io/visetyscale.o (.rodata);
      build/OUTCODE/src/libultra/io/virepeatline.o (.rodata);
      build/OUTCODE/src/libultra/io/viblack.o (.rodata);
      build/OUTCODE/src/libultra/io/sptaskyielded.o (.rodata);
      build/OUTCODE/src/libultra/io/dpctr.o (.rodata);
      build/OUTCODE/src/libultra/io/vigetcurrframebuf.o (.rodata);
      build/OUTCODE/src/libultra/io/vigetnextframebuf.o (.rodata);
      build/OUTCODE/src/libultra/io/viswapbuf.o (.rodata);
      build/OUTCODE/src/libultra/io/dpsetstat.o (.rodata);
      build/OUTCODE/src/libultrare/io/sptask.o (.rodata);
      build/OUTCODE/src/libultra/io/dpsetnextbuf.o (.rodata);
      build/OUTCODE/src/libultra/io/sptaskyield.o (.rodata);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/timerintr.o (.rodata);
      build/OUTCODE/src/libultra/os/getthreadpri.o (.rodata);
      build/OUTCODE/src/libultra/os/interrupt.o (.rodata);
      build/OUTCODE/src/libultrare/io/vi.o (.rodata);
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.rodata);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.rodata);
      build/OUTCODE/src/libultra/io/piacs.o (.rodata);
      build/OUTCODE/src/libultrare/io/epirawdma.o (.rodata);
      build/OUTCODE/src/libultrare/io/devmgr.o (.rodata);
#endif
      build/OUTCODE/src/libultra/os/gettlbhi.o (.rodata);
      build/OUTCODE/src/libultra/os/virtualtophysical.o (.rodata);
      build/OUTCODE/src/libultra/io/aisetfreq.o (.rodata);
      build/OUTCODE/src/libultra/audio/sl.o (.rodata);
      build/OUTCODE/src/libultra/audio/heapalloc.o (.rodata);
      build/OUTCODE/src/libultra/os/gettime.o (.rodata);
      build/OUTCODE/src/libultra/libc/ll.o (.rodata); /*edited*/
      build/OUTCODE/src/libultrare/io/aisetnextbuf.o (.rodata);
      build/OUTCODE/src/libultra/io/aigetlen.o (.rodata);
      build/OUTCODE/src/libultra/audio/synthesizer.o (.rodata);
      build/OUTCODE/src/libultra/io/pidma.o (.rodata);
      build/OUTCODE/src/libultra/io/visetspecial.o (.rodata);
      build/OUTCODE/src/libultra/libc/bcopy.o (.rodata);
      build/OUTCODE/src/libultra/gu/perspective.o (.rodata);
      build/OUTCODE/src/libultra/gu/mtxutil.o (.rodata);
      build/OUTCODE/src/libultra/os/getcurrfaultthread.o (.rodata);
      build/OUTCODE/src/libultra/os/exception.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/os/thread.o (.rodata);
      build/OUTCODE/src/libultra/os/yieldthread.o (.rodata);
      build/OUTCODE/src/libultra/os/invaldcache.o (.rodata);
      build/OUTCODE/src/libultra/os/writebackdcache.o (.rodata);
      build/OUTCODE/src/libultra/os/settimer.o (.rodata);
      build/OUTCODE/src/libultra/audio/heapinit.o (.rodata);
      build/OUTCODE/src/libultra/audio/bnkf.o (.rodata);
      build/OUTCODE/src/libultra/audio/csplayer.o (.rodata);
      build/OUTCODE/src/libultra/audio/seqpsetbank.o (.rodata);
      build/OUTCODE/src/libultra/audio/cspgetstate.o (.rodata);
      build/OUTCODE/src/libultra/audio/cseq.o (.rodata);
      build/OUTCODE/src/libultra/audio/cspsetseq.o (.rodata);
      build/OUTCODE/src/libultra/audio/cspplay.o (.rodata);
      build/OUTCODE/src/libultra/audio/cspstop.o (.rodata);
      build/OUTCODE/src/libultra/audio/cspsetvol.o (.rodata);
      build/OUTCODE/src/libultra/audio/event.o (.rodata);
      build/OUTCODE/src/libultra/audio/synaddplayer.o (.rodata);
      build/OUTCODE/src/libultra/audio/synallocvoice.o (.rodata);
      build/OUTCODE/src/libultra/audio/synsetvol.o (.rodata);
      build/OUTCODE/src/libultra/audio/synstartvoice.o (.rodata);
      build/OUTCODE/src/libultra/audio/synsetpan.o (.rodata);
      build/OUTCODE/src/libultra/audio/synsetpitch.o (.rodata);
      build/OUTCODE/src/libultra/audio/synsetfxmix.o (.rodata);
      build/OUTCODE/src/libultra/audio/synstopvoice.o (.rodata);
      build/OUTCODE/src/libultra/audio/synfreevoice.o (.rodata);
      build/OUTCODE/src/libultra/audio/cents2ratio.o (.rodata);
      build/OUTCODE/src/libultra/io/piread.o (.rodata);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/piwrite.o (.rodata);
#endif
      build/OUTCODE/src/libultra/libc/string.o (.rodata);
      build/OUTCODE/src/libultrare/libc/xprintf.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/pimgr.o (.rodata);
#endif
      build/OUTCODE/src/libultrare/io/pfsinit.o (.rodata);
      build/OUTCODE/src/libultrare/io/controller.o (.rodata);
      build/OUTCODE/src/libultra/io/contquery.o (.rodata);
      build/OUTCODE/src/libultrare/io/contreaddata.o (.rodata);
      build/OUTCODE/src/libultrare/io/conteepprobe.o (.rodata);
      build/OUTCODE/src/libultrare/io/conteepread.o (.rodata);
      build/OUTCODE/src/libultrare/io/conteepwrite.o (.rodata);
      build/OUTCODE/src/libultrare/io/conteeplongread.o (.rodata);
      build/OUTCODE/src/libultrare/io/conteeplongwrite.o (.rodata);
      build/OUTCODE/src/libultrare/io/pfsisplug.o (.rodata);
      build/OUTCODE/src/libultra/io/siacs.o (.rodata);
      build/OUTCODE/src/libultra/io/sirawdma.o (.rodata);
      build/OUTCODE/src/libultra/io/crc.o (.rodata);
      build/OUTCODE/src/libultrare/io/contramwrite.o (.rodata);
      build/OUTCODE/src/libultrare/io/contramread.o (.rodata);
      build/OUTCODE/src/libultra/gu/align.o (.rodata);
      build/OUTCODE/src/libultra/gu/ortho.o (.rodata);
      build/OUTCODE/src/libultra/gu/coss.o (.rodata);
      build/OUTCODE/src/libultra/gu/sins.o (.rodata);
      build/OUTCODE/src/libultra/gu/translate.o (.rodata);
      build/OUTCODE/src/libultra/libc/bcmp.o (.rodata);
      build/OUTCODE/src/libultra/gu/scale.o (.rodata);
      build/OUTCODE/src/libultra/gu/lookatref.o (.rodata);
      build/OUTCODE/src/libultra/gu/lookat.o (.rodata);
      build/OUTCODE/src/libultra/gu/rotate.o (.rodata);
      build/OUTCODE/src/libultra/libc/llcvt.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/os/setsr.o (.rodata);
      build/OUTCODE/src/libultra/os/getsr.o (.rodata);
      build/OUTCODE/src/libultra/io/sirawread.o (.rodata);
      build/OUTCODE/src/libultra/io/sirawwrite.o (.rodata);
      build/OUTCODE/src/libultra/io/pirawread.o (.rodata);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/pirawwrite.o (.rodata);
#endif
      build/OUTCODE/src/libultra/libc/bzero.o (.rodata);
      build/OUTCODE/src/libultra/os/sethwinterrupt.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.rodata);
      build/OUTCODE/src/libultra/os/interrupt.o (.rodata);
      build/OUTCODE/src/libultra/os/timerintr.o (.rodata);
#endif
      build/OUTCODE/src/libultra/os/kdebugserver.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/getthreadpri.o (.rodata);
      build/OUTCODE/src/libultrare/io/vi.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.rodata);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.rodata);
#endif
      build/OUTCODE/src/libultra/io/spgetstat.o (.rodata);
      build/OUTCODE/src/libultra/io/spsetstat.o (.rodata);
      build/OUTCODE/src/libultra/io/spsetpc.o (.rodata);
      build/OUTCODE/src/libultra/io/sprawdma.o (.rodata);
      build/OUTCODE/src/libultra/io/sp.o (.rodata);
      build/OUTCODE/src/libultra/io/dp.o (.rodata);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/setcompare.o (.rodata);
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.rodata);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.rodata);
#endif
      build/OUTCODE/src/libultra/os/probetlb.o (.rodata);
      build/OUTCODE/src/libultra/audio/syndelete.o (.rodata);
      build/OUTCODE/src/libultra/io/ai.o (.rodata);
      build/OUTCODE/src/libultrare/audio/drvrNew.o (.rodata);
      build/OUTCODE/src/libultra/audio/synallocfx.o (.rodata);
      build/OUTCODE/src/libultra/audio/mainbus.o (.rodata);
      build/OUTCODE/src/libultra/audio/load.o (.rodata);
      build/OUTCODE/src/libultra/audio/resample.o (.rodata);
      build/OUTCODE/src/libultrare/audio/env.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/audio/auxbus.o (.rodata);
      build/OUTCODE/src/libultra/audio/save.o (.rodata);
      build/OUTCODE/src/libultra/os/jammesg.o (.rodata);
      build/OUTCODE/src/libultra/io/pigetcmdq.o (.rodata);
      build/OUTCODE/src/libultra/gu/cosf.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/gu/sinf.o (.rodata); /*edited*/
      build/OUTCODE/src/libultrare/os/destroythread.o (.rodata);
      build/OUTCODE/src/libultra/audio/seqplayer.o (.rodata);
      build/OUTCODE/src/libultra/audio/synstartvoiceparam.o (.rodata);
      build/OUTCODE/src/libultra/audio/copy.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/io/piacs.o (.rodata);
#endif
      build/OUTCODE/src/libultra/libc/xlitob.o (.rodata);
      build/OUTCODE/src/libultra/libc/xldtob.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/epirawdma.o (.rodata);
      build/OUTCODE/src/libultrare/io/devmgr.o (.rodata);
#endif
      build/OUTCODE/src/libultra/io/contpfs.o (.rodata);
      build/OUTCODE/src/libultra/io/si.o (.rodata);
      build/OUTCODE/src/libultra/gu/normalize.o (.rodata);
      build/OUTCODE/src/libultra/gu/sqrtf.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leodiskinit.o (.rodata);
      build/OUTCODE/src/libultra/os/setcompare.o (.rodata);
#endif
      build/OUTCODE/src/libultra/audio/filter.o (.rodata);
      build/OUTCODE/src/libultrare/audio/reverb.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/gu/libm_vals.o (.rodata); /*edited*/
      build/OUTCODE/src/libultra/audio/seq.o (.rodata);
      build/OUTCODE/src/libultra/audio/synsetpriority.o (.rodata);
      build/OUTCODE/src/libultra/libc/ldiv.o (.rodata);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.rodata);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.rodata);
#endif
      build/OUTCODE/src/libultra/io/vimodentsclan1.o (.rodata);
      build/OUTCODE/src/libultrare/io/vimodepallan1.o (.rodata);
      build/OUTCODE/src/libultrare/ultra80069080.o (.rodata); /*edited*/
      /*build/OUTCODE/src/libultra/libultra.a:libultra.o (.rodata);*/

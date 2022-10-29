      build/OUTCODE/src/boot.o (.data);
      build/OUTCODE/src/init.o (.data);
      build/OUTCODE/src/sched.o (.data);
      build/OUTCODE/src/osMapTLB.o (.data);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.data);
      build/OUTCODE/src/libultrare/io/pimgr.o (.data);
#endif
      build/OUTCODE/src/tlb_manage.o (.data);
      build/OUTCODE/src/tlb_random.o (.data);
      build/OUTCODE/src/tlb_resolve.o (.data);
      build/OUTCODE/src/tlb_hardwire.o (.data);
      build/OUTCODE/src/audi.o (.data);
      build/OUTCODE/src/speed_graph.o (.data);
      build/OUTCODE/src/fr.o (.data);
      build/OUTCODE/src/deb.o (.data);
      build/OUTCODE/src/crash.o (.data);
      /*deb_print may be part of fault per pd beta (.data);*/
      /*build/OUTCODE/src/deb_print.o (.data);*/
      build/OUTCODE/src/getra.o (.data);
      build/OUTCODE/src/ramrom.o (.data);
      build/OUTCODE/src/boss.o (.data);
      build/OUTCODE/src/music.o (.data);
      build/OUTCODE/src/snd.o (.data);
      build/OUTCODE/src/memp.o (.data);
      build/OUTCODE/src/mema.o (.data);
      build/OUTCODE/src/random.o (.data);
      build/OUTCODE/src/token.o (.data);
      build/OUTCODE/src/str.o (.data);
      build/OUTCODE/src/sprintf.o (.data);
      build/OUTCODE/src/pi.o (.data);
      build/OUTCODE/src/vi.o (.data);
      build/OUTCODE/src/debugmenu.o (.data);
      build/OUTCODE/src/joy.o (.data);
      build/OUTCODE/src/motor.o (.data);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.data);
#endif
      build/OUTCODE/src/rmon.o (.data);
#ifdef ENABLE_USB
      build/OUTCODE/src/usb.o (.data);
#endif
      build/OUTCODE/src/libultra/io/pirawdma.o (.data);
      build/OUTCODE/src/libultra/io/pigetstat.o (.data);
      build/OUTCODE/src/libultrare/os/initialize.o (.data);
      build/OUTCODE/src/libultra/os/writebackdcacheall.o (.data);
      build/OUTCODE/src/libultra/os/invalicache.o (.data);
      build/OUTCODE/src/libultra/os/unmaptlb.o (.data);
      build/OUTCODE/src/libultra/os/getfpccsr.o (.data);
      build/OUTCODE/src/libultra/os/setfpccsr.o (.data);
      build/OUTCODE/src/libultra/os/createthread.o (.data);
      build/OUTCODE/src/libultra/os/startthread.o (.data);
      build/OUTCODE/src/libultra/os/createmesgqueue.o (.data);
      build/OUTCODE/src/libultra/os/parameters.o (.data);
      build/OUTCODE/src/libultra/os/stopthread.o (.data);
      build/OUTCODE/src/libultra/os/setthreadpri.o (.data);
      build/OUTCODE/src/libultra/os/getcount.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.data);
#endif
      build/OUTCODE/src/libultrare/io/vitbl.o (.data); /*edited*/
      build/OUTCODE/src/libultra/os/seteventmesg.o (.data);
      build/OUTCODE/src/libultra/io/visetevent.o (.data);
      build/OUTCODE/src/libultra/os/setintmask.o (.data);
      build/OUTCODE/src/libultra/os/recvmesg.o (.data);
      build/OUTCODE/src/libultra/os/sendmesg.o (.data);
      build/OUTCODE/src/libultra/io/visetmode.o (.data);
      build/OUTCODE/src/libultra/io/visetxscale.o (.data);
      build/OUTCODE/src/libultra/io/visetyscale.o (.data);
      build/OUTCODE/src/libultra/io/virepeatline.o (.data);
      build/OUTCODE/src/libultra/io/viblack.o (.data);
      build/OUTCODE/src/libultra/io/sptaskyielded.o (.data);
      build/OUTCODE/src/libultra/io/dpctr.o (.data);
      build/OUTCODE/src/libultra/io/vigetcurrframebuf.o (.data);
      build/OUTCODE/src/libultra/io/vigetnextframebuf.o (.data);
      build/OUTCODE/src/libultra/io/viswapbuf.o (.data);
      build/OUTCODE/src/libultra/io/dpsetstat.o (.data);
      build/OUTCODE/src/libultrare/io/sptask.o (.data);
      build/OUTCODE/src/libultra/io/dpsetnextbuf.o (.data);
      build/OUTCODE/src/libultra/io/sptaskyield.o (.data);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/timerintr.o (.data);
      build/OUTCODE/src/libultra/os/getthreadpri.o (.data);
      build/OUTCODE/src/libultra/os/interrupt.o (.data);
      build/OUTCODE/src/libultrare/io/vi.o (.data);
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.data);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.data);
      build/OUTCODE/src/libultra/io/piacs.o (.data);
      build/OUTCODE/src/libultrare/io/epirawdma.o (.data);
      build/OUTCODE/src/libultrare/io/devmgr.o (.data);
#endif
      build/OUTCODE/src/libultra/os/gettlbhi.o (.data);
      build/OUTCODE/src/libultra/os/virtualtophysical.o (.data);
      build/OUTCODE/src/libultra/io/aisetfreq.o (.data);
      build/OUTCODE/src/libultra/audio/sl.o (.data);
      build/OUTCODE/src/libultra/audio/heapalloc.o (.data);
      build/OUTCODE/src/libultra/os/gettime.o (.data);
      build/OUTCODE/src/libultra/libc/ll.o (.data); /*edited*/
      build/OUTCODE/src/libultrare/io/aisetnextbuf.o (.data);
      build/OUTCODE/src/libultra/io/aigetlen.o (.data);
      build/OUTCODE/src/libultra/audio/synthesizer.o (.data);
      build/OUTCODE/src/libultra/io/pidma.o (.data);
      build/OUTCODE/src/libultra/io/visetspecial.o (.data);
      build/OUTCODE/src/libultra/libc/bcopy.o (.data);
      build/OUTCODE/src/libultra/gu/perspective.o (.data);
      build/OUTCODE/src/libultra/gu/mtxutil.o (.data);
      build/OUTCODE/src/libultra/os/getcurrfaultthread.o (.data);
      build/OUTCODE/src/libultra/os/exception.o (.data); /*edited*/
      build/OUTCODE/src/libultra/os/thread.o (.data);
      build/OUTCODE/src/libultra/os/yieldthread.o (.data);
      build/OUTCODE/src/libultra/os/invaldcache.o (.data);
      build/OUTCODE/src/libultra/os/writebackdcache.o (.data);
      build/OUTCODE/src/libultra/os/settimer.o (.data);
      build/OUTCODE/src/libultra/audio/heapinit.o (.data);
      build/OUTCODE/src/libultra/audio/bnkf.o (.data);
      build/OUTCODE/src/libultra/audio/csplayer.o (.data);
      build/OUTCODE/src/libultra/audio/seqpsetbank.o (.data);
      build/OUTCODE/src/libultra/audio/cspgetstate.o (.data);
      build/OUTCODE/src/libultra/audio/cseq.o (.data);
      build/OUTCODE/src/libultra/audio/cspsetseq.o (.data);
      build/OUTCODE/src/libultra/audio/cspplay.o (.data);
      build/OUTCODE/src/libultra/audio/cspstop.o (.data);
      build/OUTCODE/src/libultra/audio/cspsetvol.o (.data);
      build/OUTCODE/src/libultra/audio/event.o (.data);
      build/OUTCODE/src/libultra/audio/synaddplayer.o (.data);
      build/OUTCODE/src/libultra/audio/synallocvoice.o (.data);
      build/OUTCODE/src/libultra/audio/synsetvol.o (.data);
      build/OUTCODE/src/libultra/audio/synstartvoice.o (.data);
      build/OUTCODE/src/libultra/audio/synsetpan.o (.data);
      build/OUTCODE/src/libultra/audio/synsetpitch.o (.data);
      build/OUTCODE/src/libultra/audio/synsetfxmix.o (.data);
      build/OUTCODE/src/libultra/audio/synstopvoice.o (.data);
      build/OUTCODE/src/libultra/audio/synfreevoice.o (.data);
      build/OUTCODE/src/libultra/audio/cents2ratio.o (.data);
      build/OUTCODE/src/libultra/io/piread.o (.data);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/piwrite.o (.data);
#endif
      build/OUTCODE/src/libultra/libc/string.o (.data);
      build/OUTCODE/src/libultrare/libc/xprintf.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/pimgr.o (.data);
#endif
      build/OUTCODE/src/libultrare/io/pfsinit.o (.data);
      build/OUTCODE/src/libultrare/io/controller.o (.data);
      build/OUTCODE/src/libultra/io/contquery.o (.data);
      build/OUTCODE/src/libultrare/io/contreaddata.o (.data);
      build/OUTCODE/src/libultrare/io/conteepprobe.o (.data);
      build/OUTCODE/src/libultrare/io/conteepread.o (.data);
      build/OUTCODE/src/libultrare/io/conteepwrite.o (.data);
      build/OUTCODE/src/libultrare/io/conteeplongread.o (.data);
      build/OUTCODE/src/libultrare/io/conteeplongwrite.o (.data);
      build/OUTCODE/src/libultrare/io/pfsisplug.o (.data);
      build/OUTCODE/src/libultra/io/siacs.o (.data);
      build/OUTCODE/src/libultra/io/sirawdma.o (.data);
      build/OUTCODE/src/libultra/io/crc.o (.data);
      build/OUTCODE/src/libultrare/io/contramwrite.o (.data);
      build/OUTCODE/src/libultrare/io/contramread.o (.data);
      build/OUTCODE/src/libultra/gu/align.o (.data);
      build/OUTCODE/src/libultra/gu/ortho.o (.data);
      build/OUTCODE/src/libultra/gu/coss.o (.data);
      build/OUTCODE/src/libultra/gu/sins.o (.data);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/io/vimodentsclan1.o (.data);
      build/OUTCODE/src/libultrare/io/vimodepallan1.o (.data);
#endif
      build/OUTCODE/src/libultra/gu/translate.o (.data);
      build/OUTCODE/src/libultra/libc/bcmp.o (.data);
      build/OUTCODE/src/libultra/gu/scale.o (.data);
      build/OUTCODE/src/libultra/gu/lookatref.o (.data);
      build/OUTCODE/src/libultra/gu/lookat.o (.data);
      build/OUTCODE/src/libultra/gu/rotate.o (.data);
      build/OUTCODE/src/libultra/libc/llcvt.o (.data); /*edited*/
      build/OUTCODE/src/libultra/os/setsr.o (.data);
      build/OUTCODE/src/libultra/os/getsr.o (.data);
      build/OUTCODE/src/libultra/io/sirawread.o (.data);
      build/OUTCODE/src/libultra/io/sirawwrite.o (.data);
      build/OUTCODE/src/libultra/io/pirawread.o (.data);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/pirawwrite.o (.data);
#endif
      build/OUTCODE/src/libultra/libc/bzero.o (.data);
      build/OUTCODE/src/libultra/os/sethwinterrupt.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.data);
      build/OUTCODE/src/libultra/os/interrupt.o (.data);
      build/OUTCODE/src/libultra/os/timerintr.o (.data);
#endif
      build/OUTCODE/src/libultra/os/kdebugserver.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/getthreadpri.o (.data);
      build/OUTCODE/src/libultrare/io/vi.o (.data); /*edited*/
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.data);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.data);
#endif
      build/OUTCODE/src/libultra/io/spgetstat.o (.data);
      build/OUTCODE/src/libultra/io/spsetstat.o (.data);
      build/OUTCODE/src/libultra/io/spsetpc.o (.data);
      build/OUTCODE/src/libultra/io/sprawdma.o (.data);
      build/OUTCODE/src/libultra/io/sp.o (.data);
      build/OUTCODE/src/libultra/io/dp.o (.data);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/setcompare.o (.data);
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.data);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.data);
#endif
      build/OUTCODE/src/libultra/os/probetlb.o (.data);
      build/OUTCODE/src/libultra/audio/syndelete.o (.data);
      build/OUTCODE/src/libultra/io/ai.o (.data);
      build/OUTCODE/src/libultrare/audio/drvrNew.o (.data);
      build/OUTCODE/src/libultra/audio/synallocfx.o (.data);
      build/OUTCODE/src/libultra/audio/mainbus.o (.data);
      build/OUTCODE/src/libultra/audio/load.o (.data);
      build/OUTCODE/src/libultra/audio/resample.o (.data);
      build/OUTCODE/src/libultrare/audio/env.o (.data); /*edited*/
      build/OUTCODE/src/libultra/audio/auxbus.o (.data);
      build/OUTCODE/src/libultra/audio/save.o (.data);
      build/OUTCODE/src/libultra/os/jammesg.o (.data);
      build/OUTCODE/src/libultra/io/pigetcmdq.o (.data);
      build/OUTCODE/src/libultra/gu/cosf.o (.data); /*edited*/
      build/OUTCODE/src/libultra/gu/sinf.o (.data); /*edited*/
      build/OUTCODE/src/libultrare/os/destroythread.o (.data);
      build/OUTCODE/src/libultra/audio/seqplayer.o (.data);
      build/OUTCODE/src/libultra/audio/synstartvoiceparam.o (.data);
      build/OUTCODE/src/libultra/audio/copy.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/io/piacs.o (.data);
#endif
      build/OUTCODE/src/libultra/libc/xlitob.o (.data);
      build/OUTCODE/src/libultra/libc/xldtob.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/epirawdma.o (.data);
      build/OUTCODE/src/libultrare/io/devmgr.o (.data);
#endif
      build/OUTCODE/src/libultra/io/contpfs.o (.data);
      build/OUTCODE/src/libultra/io/si.o (.data);
      build/OUTCODE/src/libultra/gu/normalize.o (.data);
      build/OUTCODE/src/libultra/gu/sqrtf.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leodiskinit.o (.data);
      build/OUTCODE/src/libultra/os/setcompare.o (.data);
#endif
      build/OUTCODE/src/libultra/audio/filter.o (.data);
      build/OUTCODE/src/libultrare/audio/reverb.o (.data); /*edited*/
      build/OUTCODE/src/libultra/gu/libm_vals.o (.data); /*edited*/
      build/OUTCODE/src/libultra/audio/seq.o (.data);
      build/OUTCODE/src/libultra/audio/synsetpriority.o (.data);
      build/OUTCODE/src/libultra/libc/ldiv.o (.data);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.data);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.data);
      build/OUTCODE/src/libultra/io/vimodentsclan1.o (.data);
      build/OUTCODE/src/libultrare/io/vimodepallan1.o (.data);
#endif
      build/OUTCODE/src/libultrare/ultra80069080.o (.data); /*edited*/
      /*build/OUTCODE/src/libultra/libultra.a:libultra.o (.data);*/

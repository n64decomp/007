      build/OUTCODE/src/boot.o (.text);
      build/OUTCODE/src/init.o (.text);
      build/OUTCODE/src/sched.o (.text);
      build/OUTCODE/src/osMapTLB.o (.text);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.text);
      build/OUTCODE/src/libultrare/io/pimgr.o (.text);
#endif
      build/OUTCODE/src/tlb_manage.o (.text);
      build/OUTCODE/src/tlb_random.o (.text);
      build/OUTCODE/src/tlb_resolve.o (.text);
      build/OUTCODE/src/tlb_hardwire.o (.text);
      build/OUTCODE/src/audi.o (.text);
      build/OUTCODE/src/speed_graph.o (.text);
      build/OUTCODE/src/fr.o (.text);
      build/OUTCODE/src/deb.o (.text);
      build/OUTCODE/src/crash.o (.text);
      /*deb_print may be part of fault per pd beta (.text);*/
      /*build/OUTCODE/src/deb_print.o (.text);*/
      build/OUTCODE/src/getra.o (.text);
      build/OUTCODE/src/ramrom.o (.text);
      build/OUTCODE/src/boss.o (.text);
      build/OUTCODE/src/music.o (.text);
      build/OUTCODE/src/snd.o (.text);
      build/OUTCODE/src/memp.o (.text);
      build/OUTCODE/src/mema.o (.text);
      build/OUTCODE/src/random.o (.text);
      build/OUTCODE/src/token.o (.text);
      build/OUTCODE/src/str.o (.text);
      build/OUTCODE/src/sprintf.o (.text);
      build/OUTCODE/src/pi.o (.text);
      build/OUTCODE/src/vi.o (.text);
      build/OUTCODE/src/debugmenu.o (.text);
      build/OUTCODE/src/joy.o (.text);
      build/OUTCODE/src/motor.o (.text);
#ifdef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.text);
#endif
      build/OUTCODE/src/rmon.o (.text);
#ifdef ENABLE_USB
      build/OUTCODE/src/usb.o (.text);
#endif
      /*build/OUTCODE/src/libultra/osPiRawStartDma.o (.text);*/
      build/OUTCODE/src/libultra/io/pirawdma.o (.text);
      build/OUTCODE/src/libultra/io/pigetstat.o (.text);
      build/OUTCODE/src/libultrare/os/initialize.o (.text);
      build/OUTCODE/src/libultra/os/writebackdcacheall.o (.text);
      build/OUTCODE/src/libultra/os/invalicache.o (.text);
      build/OUTCODE/src/libultra/os/unmaptlb.o (.text);
      build/OUTCODE/src/libultra/os/getfpccsr.o (.text);
      build/OUTCODE/src/libultra/os/setfpccsr.o (.text);
      build/OUTCODE/src/libultra/os/createthread.o (.text);
      build/OUTCODE/src/libultra/os/startthread.o (.text);
      build/OUTCODE/src/libultra/os/createmesgqueue.o (.text);
      build/OUTCODE/src/libultra/os/parameters.o (.text);
      build/OUTCODE/src/libultra/os/stopthread.o (.text);
      build/OUTCODE/src/libultra/os/setthreadpri.o (.text);
      build/OUTCODE/src/libultra/os/getcount.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/vimgr.o (.text);
#endif
      build/OUTCODE/src/libultrare/io/vitbl.o (.text); /*edited*/
      build/OUTCODE/src/libultra/os/seteventmesg.o (.text);
      build/OUTCODE/src/libultra/io/visetevent.o (.text);
      build/OUTCODE/src/libultra/os/setintmask.o (.text);
      build/OUTCODE/src/libultra/os/recvmesg.o (.text);
      build/OUTCODE/src/libultra/os/sendmesg.o (.text);
      build/OUTCODE/src/libultra/io/visetmode.o (.text);
      build/OUTCODE/src/libultra/io/visetxscale.o (.text);
      build/OUTCODE/src/libultra/io/visetyscale.o (.text);
      build/OUTCODE/src/libultra/io/virepeatline.o (.text);
      build/OUTCODE/src/libultra/io/viblack.o (.text);
      build/OUTCODE/src/libultra/io/sptaskyielded.o (.text);
      build/OUTCODE/src/libultra/io/dpctr.o (.text);
      build/OUTCODE/src/libultra/io/vigetcurrframebuf.o (.text);
      build/OUTCODE/src/libultra/io/vigetnextframebuf.o (.text);
      build/OUTCODE/src/libultra/io/viswapbuf.o (.text);
      build/OUTCODE/src/libultra/io/dpsetstat.o (.text);
      build/OUTCODE/src/libultrare/io/sptask.o (.text);
      build/OUTCODE/src/libultra/io/dpsetnextbuf.o (.text);
      build/OUTCODE/src/libultra/io/sptaskyield.o (.text);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/timerintr.o (.text);
      build/OUTCODE/src/libultra/os/getthreadpri.o (.text);
      build/OUTCODE/src/libultra/os/interrupt.o (.text);
      build/OUTCODE/src/libultrare/io/vi.o (.text);
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.text);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.text);
      build/OUTCODE/src/libultra/io/piacs.o (.text);
      build/OUTCODE/src/libultrare/io/epirawdma.o (.text);
      build/OUTCODE/src/libultrare/io/devmgr.o (.text);
#endif
      build/OUTCODE/src/libultra/os/gettlbhi.o (.text);
      build/OUTCODE/src/libultra/os/virtualtophysical.o (.text);
      build/OUTCODE/src/libultra/io/aisetfreq.o (.text);
      build/OUTCODE/src/libultra/audio/sl.o (.text);
      build/OUTCODE/src/libultra/audio/heapalloc.o (.text);
      build/OUTCODE/src/libultra/os/gettime.o (.text);
      build/OUTCODE/src/libultra/libc/ll.o (.text); /*edited*/
      build/OUTCODE/src/libultrare/io/aisetnextbuf.o (.text);
      build/OUTCODE/src/libultra/io/aigetlen.o (.text);
      build/OUTCODE/src/libultra/audio/synthesizer.o (.text);
      build/OUTCODE/src/libultra/io/pidma.o (.text);
      build/OUTCODE/src/libultra/io/visetspecial.o (.text);
      build/OUTCODE/src/libultra/libc/bcopy.o (.text);
      build/OUTCODE/src/libultra/gu/perspective.o (.text);
      build/OUTCODE/src/libultra/gu/mtxutil.o (.text);
      build/OUTCODE/src/libultra/os/getcurrfaultthread.o (.text);
      build/OUTCODE/src/libultra/os/exception.o (.text); /*edited*/
      build/OUTCODE/src/libultra/os/thread.o (.text);
      build/OUTCODE/src/libultra/os/yieldthread.o (.text);
      build/OUTCODE/src/libultra/os/invaldcache.o (.text);
      build/OUTCODE/src/libultra/os/writebackdcache.o (.text);
      build/OUTCODE/src/libultra/os/settimer.o (.text);
      build/OUTCODE/src/libultra/audio/heapinit.o (.text);
      build/OUTCODE/src/libultra/audio/bnkf.o (.text);
      build/OUTCODE/src/libultra/audio/csplayer.o (.text);
      build/OUTCODE/src/libultra/audio/seqpsetbank.o (.text);
      build/OUTCODE/src/libultra/audio/cspgetstate.o (.text);
      build/OUTCODE/src/libultra/audio/cseq.o (.text);
      build/OUTCODE/src/libultra/audio/cspsetseq.o (.text);
      build/OUTCODE/src/libultra/audio/cspplay.o (.text);
      build/OUTCODE/src/libultra/audio/cspstop.o (.text);
      build/OUTCODE/src/libultra/audio/cspsetvol.o (.text);
      build/OUTCODE/src/libultra/audio/event.o (.text);
      build/OUTCODE/src/libultra/audio/synaddplayer.o (.text);
      build/OUTCODE/src/libultra/audio/synallocvoice.o (.text);
      build/OUTCODE/src/libultra/audio/synsetvol.o (.text);
      build/OUTCODE/src/libultra/audio/synstartvoice.o (.text);
      build/OUTCODE/src/libultra/audio/synsetpan.o (.text);
      build/OUTCODE/src/libultra/audio/synsetpitch.o (.text);
      build/OUTCODE/src/libultra/audio/synsetfxmix.o (.text);
      build/OUTCODE/src/libultra/audio/synstopvoice.o (.text);
      build/OUTCODE/src/libultra/audio/synfreevoice.o (.text);
      build/OUTCODE/src/libultra/audio/cents2ratio.o (.text);
      build/OUTCODE/src/libultra/io/piread.o (.text);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/piwrite.o (.text);
#endif
      build/OUTCODE/src/libultra/libc/string.o (.text);
      build/OUTCODE/src/libultrare/libc/xprintf.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/pimgr.o (.text);
#endif
      build/OUTCODE/src/libultrare/io/pfsinit.o (.text);
      build/OUTCODE/src/libultrare/io/controller.o (.text);
      build/OUTCODE/src/libultra/io/contquery.o (.text);
      build/OUTCODE/src/libultrare/io/contreaddata.o (.text);
      build/OUTCODE/src/libultrare/io/conteepprobe.o (.text);
      build/OUTCODE/src/libultrare/io/conteepread.o (.text);
      build/OUTCODE/src/libultrare/io/conteepwrite.o (.text);
      build/OUTCODE/src/libultrare/io/conteeplongread.o (.text);
      build/OUTCODE/src/libultrare/io/conteeplongwrite.o (.text);
      build/OUTCODE/src/libultrare/io/pfsisplug.o (.text);
      build/OUTCODE/src/libultra/io/siacs.o (.text);
      build/OUTCODE/src/libultra/io/sirawdma.o (.text);
      build/OUTCODE/src/libultra/io/crc.o (.text);
      build/OUTCODE/src/libultrare/io/contramwrite.o (.text);
      build/OUTCODE/src/libultrare/io/contramread.o (.text);
      build/OUTCODE/src/libultra/gu/align.o (.text);
      build/OUTCODE/src/libultra/gu/ortho.o (.text);
      build/OUTCODE/src/libultra/gu/coss.o (.text);
      build/OUTCODE/src/libultra/gu/sins.o (.text);
      build/OUTCODE/src/libultra/gu/translate.o (.text);
      build/OUTCODE/src/libultra/libc/bcmp.o (.text);
      build/OUTCODE/src/libultra/gu/scale.o (.text);
      build/OUTCODE/src/libultra/gu/lookatref.o (.text);
      build/OUTCODE/src/libultra/gu/lookat.o (.text);
      build/OUTCODE/src/libultra/gu/rotate.o (.text);
      build/OUTCODE/src/libultra/libc/llcvt.o (.text); /*edited*/
      build/OUTCODE/src/libultra/os/setsr.o (.text);
      build/OUTCODE/src/libultra/os/getsr.o (.text);
      build/OUTCODE/src/libultra/io/sirawread.o (.text);
      build/OUTCODE/src/libultra/io/sirawwrite.o (.text);
      build/OUTCODE/src/libultra/io/pirawread.o (.text);
#ifdef ENABLE_USB
      build/OUTCODE/src/libultra/io/pirawwrite.o (.text);
#endif
      build/OUTCODE/src/libultra/libc/bzero.o (.text);
      build/OUTCODE/src/libultra/os/sethwinterrupt.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leointerrupt.o (.text);
      build/OUTCODE/src/libultra/os/interrupt.o (.text);
      build/OUTCODE/src/libultra/os/timerintr.o (.text);
#endif
      build/OUTCODE/src/libultra/os/kdebugserver.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/getthreadpri.o (.text);
      build/OUTCODE/src/libultrare/io/vi.o (.text); /*edited*/
      build/OUTCODE/src/libultra/io/vigetcurrcontext.o (.text);
      build/OUTCODE/src/libultra/io/viswapcontext.o (.text);
#endif
      build/OUTCODE/src/libultra/io/spgetstat.o (.text);
      build/OUTCODE/src/libultra/io/spsetstat.o (.text);
      build/OUTCODE/src/libultra/io/spsetpc.o (.text);
      build/OUTCODE/src/libultra/io/sprawdma.o (.text);
      build/OUTCODE/src/libultra/io/sp.o (.text);
      build/OUTCODE/src/libultra/io/dp.o (.text);
#ifdef VERSION_EU
      build/OUTCODE/src/libultra/os/setcompare.o (.text);
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.text);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.text);
#endif
      build/OUTCODE/src/libultra/os/probetlb.o (.text);
      build/OUTCODE/src/libultra/audio/syndelete.o (.text);
      build/OUTCODE/src/libultra/io/ai.o (.text);
      build/OUTCODE/src/libultrare/audio/drvrNew.o (.text);
      build/OUTCODE/src/libultra/audio/synallocfx.o (.text);
      build/OUTCODE/src/libultra/audio/mainbus.o (.text);
      build/OUTCODE/src/libultra/audio/load.o (.text);
      build/OUTCODE/src/libultra/audio/resample.o (.text);
      build/OUTCODE/src/libultrare/audio/env.o (.text); /*edited*/
      build/OUTCODE/src/libultra/audio/auxbus.o (.text);
      build/OUTCODE/src/libultra/audio/save.o (.text);
      build/OUTCODE/src/libultra/os/jammesg.o (.text);
      build/OUTCODE/src/libultra/io/pigetcmdq.o (.text);
      build/OUTCODE/src/libultra/gu/cosf.o (.text); /*edited*/
      build/OUTCODE/src/libultra/gu/sinf.o (.text); /*edited*/
      build/OUTCODE/src/libultrare/os/destroythread.o (.text);
      build/OUTCODE/src/libultra/audio/seqplayer.o (.text);
      build/OUTCODE/src/libultra/audio/synstartvoiceparam.o (.text);
      build/OUTCODE/src/libultra/audio/copy.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/io/piacs.o (.text);
#endif
      build/OUTCODE/src/libultra/libc/xlitob.o (.text);
      build/OUTCODE/src/libultra/libc/xldtob.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/epirawdma.o (.text);
      build/OUTCODE/src/libultrare/io/devmgr.o (.text);
#endif
      build/OUTCODE/src/libultra/io/contpfs.o (.text);
      build/OUTCODE/src/libultra/io/si.o (.text);
      build/OUTCODE/src/libultra/gu/normalize.o (.text);
      build/OUTCODE/src/libultra/gu/sqrtf.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultrare/io/leodiskinit.o (.text);
      build/OUTCODE/src/libultra/os/setcompare.o (.text);
#endif
      build/OUTCODE/src/libultra/audio/filter.o (.text);
      build/OUTCODE/src/libultrare/audio/reverb.o (.text); /*edited*/
      build/OUTCODE/src/libultra/gu/libm_vals.o (.text); /*edited*/
      build/OUTCODE/src/libultra/audio/seq.o (.text);
      build/OUTCODE/src/libultra/audio/synsetpriority.o (.text);
      build/OUTCODE/src/libultra/libc/ldiv.o (.text);
#ifndef VERSION_EU
      build/OUTCODE/src/libultra/os/resetglobalintmask.o (.text);
      build/OUTCODE/src/libultrare/io/epirawwrite.o (.text);
#endif
      build/OUTCODE/src/libultra/io/vimodentsclan1.o (.text);
      build/OUTCODE/src/libultrare/io/vimodepallan1.o (.text);
      build/OUTCODE/src/libultrare/ultra80069080.o (.text); /*edited*/
      /*build/OUTCODE/src/libultra/libultra.a:libultra.o (.text);*/

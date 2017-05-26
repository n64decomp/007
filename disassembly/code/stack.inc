
constant seg_sp_start($80300000)

constant decompression_buffer(seg_sp_start+$0)

constant sp_init(seg_sp_start+$AB3D0)
scope sp_init {
define sp_init_s0($1C)
define sp_init_s1($20)
define sp_init_ra($24)
define rarezip_pos($28)
define rodata_pos($34)
}

constant sp_boot(seg_sp_start+$AB400)


constant sp_rmon(sp_boot+$10) //$ab410


constant sp_idle(sp_rmon+$300) //$ab710


constant sp_shed(sp_idle+$40) //$ab750


constant sp_main(sp_shed+$200) //$ab950


constant sp_audi(sp_main+$8000) //$b3950


constant sp_unknown(sp_audi+$1000) //$b4950

//seg_sp_end:

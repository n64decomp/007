base origin()
unknown_rom_start:

//vaddr is unknow
//base $vaddr
unknown_start:

unknown1_start:
insert binaryunknown1, "117880_24EB30.bin", (origin() - $117880)
unknown2_start:
insert binaryunknown2, "24EB30_296565.bin", (origin() - $24EB30)
unknown3_start:
insert binaryunknown3, "296565_298587.rz", (origin() - $296565)
unknown4_start:
insert binaryunknown4, "298587_2bf2d0.bin", (origin() - $298587)
unknown_end:

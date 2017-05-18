variable seg_boot_rom_size(seg_boot_rom_end-seg_boot_rom_start)
variable seg_rarezip_rom_size(seg_rarezip_rom_end-seg_rarezip_rom_start)
variable seg_bss_size(seg_bss_end-seg_bss_start)
variable seg_tlbcode_rom_size(seg_tlbcode_rom_end-seg_tlbcode_rom_start)
variable seg_rodata_rom_size(seg_rodata_rom_end-seg_rodata_rom_start)
variable seg_sp_start(seg_sp_end-seg_sp_start)

macro getaddresstoregister(address, reg) {
 define return({reg}) //what register to return in

 lui {return}, ({address} >> 16) //address upper
 jr ra
 addiu {return}, {return}, {address} //address lower
}

macro jumpaddressviaregister(address,reg) {
 define jumptarget({reg})

 lui {jumptarget},({address} >> 16)
 addiu {jumptarget}, {jumptarget}, {address}
 jr {jumptarget}
}





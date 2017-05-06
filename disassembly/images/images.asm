base origin()
images_rom_start:

//vaddr is unknown
//base $vaddr
//images_vaddr:

insert images, "images", (origin() - $008f7df0)

images_rom_end:

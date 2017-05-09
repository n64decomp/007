base origin()
seg_rarezip_rom_start:
base $70200000
seg_rarezip_vaddr_start:

base $7020141C
decompressfile:

insert binaryrarezipcode, "rarezip.bin", (origin() - $033590)

seg_rarezip_vaddr_end:
base origin()
seg_rarezip_rom_end:

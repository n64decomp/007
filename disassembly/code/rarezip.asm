base origin()
rarezip_rom_start:

base $70200000
RareZip_vaddr:

base $7020141C
decompressfile:

insert binaryrarezipcode, "rarezip.bin", (origin() - $033590)
base origin()
rarezip_rom_end:

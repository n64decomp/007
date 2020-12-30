# Makefile to rebuild Goldeneye 007

### Default target ###
default: all

### Build Options ###
# Version of the game to build
FINAL := YES
VERSION := US
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE := 1



TOOLCHAIN := mips-linux-gnu-
QEMU_IRIX := tools/irix/qemu-irix
IRIX_ROOT := tools/irix/root
# other tools
TOOLS_DIR := tools
DATASEG_COMP := $(TOOLS_DIR)/data_compress.sh
RZ_COMP := $(TOOLS_DIR)/1172compress.sh
N64CKSUM := $(TOOLS_DIR)/n64cksum
MAKEBG := $(TOOLS_DIR)/makebg.sh
SHA1SUM = sha1sum

ifeq ($(FINAL), YES)
 OPTIMIZATION := -O2
 LCDEFS :=
 CFLAGWARNING :=
else
 OPTIMIZATION := -g
 LCDEFS := -DDEBUG
 CFLAGWARNING :=-fullwarn -wlint
endif

ifeq ($(VERSION), US)
COUNTRYCODE := u
LCDEFS := -DVERSION_US
ASMDEFS := --defsym VERSION_US=1
endif

ifeq ($(VERSION), EU)
COUNTRYCODE := e
LCDEFS := -DVERSION_EU
ASMDEFS := --defsym VERSION_EU=1
endif

ifeq ($(VERSION), JP)
COUNTRYCODE := j
LCDEFS := -DVERSION_JP
ASMDEFS := --defsym VERSION_JP=1
endif

BUILD_DIR := build/$(COUNTRYCODE)
include assets/Makefile.obseg
include assets/Makefile.music
BUILD_SUB_DIRS := \
	rsp src src/game src/inflate src/libultra assets assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop \
	assets/obseg/text assets/obseg/bg assets/obseg/setup assets/obseg/stan \
	assets/music assets/ramrom assets/images assets/images/split assets/font
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach subdir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(subdir)))







APPELF := ge007.$(COUNTRYCODE).elf
APPROM := ge007.$(COUNTRYCODE).z64
APPBIN := ge007.$(COUNTRYCODE).bin

HEADERFILES := $(foreach dir,src,$(wildcard $(dir)/*.s))
HEADEROBJECTS := $(foreach file,$(HEADERFILES),$(BUILD_DIR)/$(file:.s=.o))

RSPCODE := $(foreach dir,rsp,$(wildcard $(dir)/*.s))
RSPOBJECTS := $(foreach file,$(RSPCODE),$(BUILD_DIR)/$(file:.s=.bin))

CODEFILES := $(foreach dir,src,$(wildcard $(dir)/*.c))
CODEOBJECTS := $(foreach file,$(CODEFILES),$(BUILD_DIR)/$(file:.c=.o))

LIBULTRA := lib/libultra_rom.a
ULTRAFILES_S := $(foreach dir,src/libultra,$(wildcard $(dir)/*.s))
ULTRAFILES_C := $(foreach dir,src/libultra,$(wildcard $(dir)/*.c))
ULTRAOBJECTS := $(foreach file,$(ULTRAFILES_S),$(BUILD_DIR)/$(file:.s=.o)) \
				$(foreach file,$(ULTRAFILES_C),$(BUILD_DIR)/$(file:.c=.o))

GAMEFILES := $(foreach dir,src/game,$(wildcard $(dir)/*.c))
GAMEOBJECTS := $(foreach file,$(GAMEFILES),$(BUILD_DIR)/$(file:.c=.o))

ROMFILES := assets/romfiles.s
ROMOBJECTS := $(BUILD_DIR)/assets/romfiles.o

GLOBALIMAGETABLEFILES := assets/GlobalImageTable.c
GLOBALIMAGETABLEOBJECTS := $(BUILD_DIR)/assets/GlobalImageTable.o

ROMFILES2 := assets/romfiles2.s
ROMOBJECTS2 := $(BUILD_DIR)/assets/romfiles2.o

RAMROM_FILES := assets/ramrom/ramrom.s
RAMROM_OBJECTS := $(BUILD_DIR)/assets/ramrom/ramrom.o

FONT_FILES := assets/font/font.s
FONT_OBJECTS := $(BUILD_DIR)/assets/font/font.o

MUSIC_FILES := assets/music/music.s
MUSIC_OBJECTS := $(BUILD_DIR)/assets/music/music.o

OBSEG_FILES := assets/obseg/ob_seg.s
OBSEG_OBJECTS := $(BUILD_DIR)/assets/obseg/ob_seg.o
OBSEG_RZ := $(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) $(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES)

IMAGE_BINS := $(foreach dir,assets/images/split,$(wildcard $(dir)/*.bin))
IMAGE_OBJS := $(foreach file,$(IMAGE_BINS),$(BUILD_DIR)/$(file:.bin=.o))

RZFILES := inflate/inflate.c
RZOBJECTS := $(foreach file,$(RZFILES),$(BUILD_DIR)/src/$(file:.c=.o))

OBJECTS := $(RSPOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(OBSEGMENT) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS)



INCLUDE := -I . -I include -I include/ultra64 -I src -I src/game -I src/inflate

CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CFLAGS := 0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838 -signed $(INCLUDE) -mips2 $(LCDEFS) -DTARGET_N64
CFLAGS_LIBULTRA := 0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838 -signed $(INCLUDE) -mips2 $(LCDEFS) -DTARGET_N64

LD := $(TOOLCHAIN)ld
LD_SCRIPT := ge007.$(COUNTRYCODE).ld
LDFLAGS := -T undefined_syms.txt -T $(LD_SCRIPT) -Map build/ge007.$(COUNTRYCODE).map

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE) $(ASMDEFS)
ARMIPS	:= $(TOOLS_DIR)/armips
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

all: $(APPROM)
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c ge007.$(COUNTRYCODE).sha1
endif


codeclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)

dataclean: 
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES)

clean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) $(RSPOBJECTS)

$(BUILD_DIR)/src/libultra/%.o: src/libultra/%.c
	$(CC) -c $(CFLAGS_LIBULTRA) -o $@ $<

$(BUILD_DIR)/rsp/%.bin: rsp/*.s
	$(ARMIPS) -sym $@.sym -strequ CODE_FILE $(BUILD_DIR)/rsp/$*.bin -strequ DATA_FILE $(BUILD_DIR)/rsp/$*_data.bin $<

$(BUILD_DIR)/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/src/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/%.o: assets/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

$(BUILD_DIR)/assets/%.o: assets/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/src/rspboot.o: $(BUILD_DIR)/rsp/rspboot.bin 

$(BUILD_DIR)/assets/ramrom/%.o: assets/ramrom/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/font/%.o: assets/font/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/obseg/%.o: assets/obseg/%.s $(OBSEG_RZ)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/images/split/%.o: assets/images/split/%.bin
	$(LD) -r -b binary $< -o $@

$(BUILD_DIR)/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

$(BUILD_DIR)/src/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

$(BUILD_DIR)/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGE_OBJS)
	

$(APPELF): $(RSPOBJECTS) $(ULTRAOBJECTS) $(HEADEROBJECTS) $(OBSEG_RZ) $(BUILD_DIR)/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(GLOBALIMAGETABLEOBJECTS) $(ROMOBJECTS2) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ 

$(APPBIN): $(APPELF)
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff
	
$(APPROM):	$(APPBIN)
	$(DATASEG_COMP) $< $(COUNTRYCODE)
	$(N64CKSUM) $< $@
	rm header.tmp

.PHONY: all default codeclean dataclean clean




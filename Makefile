# Makefile to build Goldeneye 007

### Default target ###
default: all

### Default Build Options ###
# Version of the game to build
FINAL := YES
VERSION := US
IDO_RECOMP := YES
VERBOSE := 2
# If COMPARE is 1, check the output sha1sum when building 'all', and if fail to match
# then compare ELF sections to known md5 checksums.
COMPARE := 1

# Include Terminal Codes for colourising text.
include include/make/VT100Codes.make
include include/make/Gui.make

# set tooolchain based on current OS
ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips64-linux-gnu-
else
  TOOLCHAIN := mips64-elf-
endif

# Use IDO Recomp UNLESS specified otherwise
ifeq ($(IDO_RECOMP), NO)
  QEMU_IRIX := $(shell which qemu-irix 2>/dev/null)
  ifeq (, $(QEMU_IRIX))
    $(error Using the IDO compiler requires qemu-irix. Please install qemu-irix package or set the QEMU_IRIX environment variable to the full qemu-irix binary path)
  endif
  IRIX_ROOT := tools/irix/root
else
  IRIX_ROOT := tools/ido5.3_recomp
endif

# other tools
TOOLS_DIR := tools
DATASEG_COMP := $(TOOLS_DIR)/data_compress.sh
RZ_COMP := $(TOOLS_DIR)/1172compress.sh
N64CKSUM := $(TOOLS_DIR)/n64cksum

ifeq ($(VERBOSE), 1)
 SHA1SUM = sha1sum
else
 SHA1SUM = sha1sum --quiet
endif

# Convert AI Print commands from readable strings to byte arrays automatically.
ConvertAIPRINT = sed -E -e ':loop s/PRINT\("(..*?)(.)"/PRINT\("\1",\x27\2\x27/g; tloop; \
                s/(PRINT\(.*?)\x27\\\x27,\x27(.)\x27(.*)\)/\1\x27\\\2\x27\3\)/g; \
                s/(PRINT\()"(.)"(.*)\)/\1\x27\2\x27\3\)/g; \
                s/PRINT\((.*)\)/PRINT\(\1,\x27\\0\x27\,)/g; \
                s/PRINT\((.*)\)/AI_PRINT,\1/g'

# per VERSION flags
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
 OUTCODE := $(COUNTRYCODE)
 LANG := US
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0 -DBYTEMATCH
 ASMDEFS := --defsym VERSION_US=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1 --defsym BYTEMATCH=1
 LDFILEOPTS := -DVERSION_$(LANG) -DOUTCODE=$(OUTCODE)
endif

ifeq ($(VERSION), EU)
 COUNTRYCODE := e
 OUTCODE := $(COUNTRYCODE)
 LANG := EU
 LCDEFS := -DVERSION_EU -DLANG_EU -DREFRESH_PAL -DBUGFIX_R1 -DBUGFIX_R2 -DBYTEMATCH
 ASMDEFS := --defsym VERSION_EU=1 --defsym LANG_EU=1 --defsym REFRESH_PAL=1 --defsym BUGFIX_R1=1 --defsym BUGFIX_R2=1 --defsym BYTEMATCH=1
 LDFILEOPTS := -DVERSION_$(LANG) -DOUTCODE=$(OUTCODE)
endif

ifeq ($(VERSION), JP)
 COUNTRYCODE := j
 OUTCODE := $(COUNTRYCODE)
 LANG := JP
 LCDEFS := -DVERSION_JP -DLANG_JP -DREFRESH_NTSC -DBUGFIX_R1 -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBYTEMATCH
 ASMDEFS := --defsym VERSION_JP=1 --defsym LANG_JP=1 --defsym REFRESH_NTSC=1 --defsym BUGFIX_R1=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BYTEMATCH=1
 LDFILEOPTS := -DVERSION_$(LANG) -DOUTCODE=$(OUTCODE)
endif

ifeq ($(VERSION), DEBUG)
 COUNTRYCODE := u
 OUTCODE := d
 LANG := US
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0 -DDEBUGMENU -DVERSION_DEBUG
 ASMDEFS := --defsym VERSION_DEBUG=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1 --defsym DEBUGMENU=1
 COMPARE := 0
 LDFILEOPTS := -DVERSION_$(LANG) -DOUTCODE=$(OUTCODE)
endif

ifeq ($(VERSION), USB)
 COUNTRYCODE := u
 OUTCODE := usb
 LANG := US
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0 -DDEBUGMENU -DENABLE_USB
 ASMDEFS := --defsym VERSION_US=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1 --defsym DEBUGMENU=1 --defsym ENABLE_USB=1
 COMPARE := 0
 LDFILEOPTS := -DVERSION_$(LANG) -DOUTCODE=$(OUTCODE) -DENABLE_USB
endif

ALLOWED_VERSIONS := US EU JP DEBUG USB
ALLOWED_COUNTRYCODE := u e j

BUILD_DIR_BASE := build
# BUILD_DIR is the location where all build artefacts are placed
BUILD_DIR      := $(BUILD_DIR_BASE)/$(OUTCODE)

# this file references variables defined above: BUILD_DIR, RZ_COMP
# this file defines and builds $(MUSIC_RZ_FILES)
include assets/Makefile.obseg
# this file references variables defined above: BUILD_DIR, RZ_COMP, COUNTRYCODE, LD, CC, CFLAGS, OBJCOPY, ConvertAIPRINT, OPTIMIZATION
# this file defines and builds OBSEGMENT, BG_SEG_FILES, BRIEF_RZ_FILES, CHR_RZ_FILES, GUN_RZ_FILES, PROP_RZ_FILES, ,SETUP_BUILD_FILES, STAN_BUILD_FILES, TEXT_RZ_FILES
include assets/Makefile.music

## Collect Objects ##

APPELF := $(BUILD_DIR)/ge007.$(OUTCODE).elf
APPROM := $(BUILD_DIR)/ge007.$(OUTCODE).z64
APPBIN := $(BUILD_DIR)/ge007.$(OUTCODE).bin

HEADERFILES := $(foreach dir,src,$(wildcard $(dir)/*.s))
HEADEROBJECTS := $(foreach file,$(HEADERFILES),$(BUILD_DIR)/$(file:.s=.o))

RSPCODE := $(foreach dir,rsp,$(wildcard $(dir)/*.s))
RSPOBJECTS := $(foreach file,$(RSPCODE),$(BUILD_DIR)/$(file:.s=.bin))

CODEFILES := $(foreach dir,src,$(wildcard $(dir)/*.c))
CODEOBJECTS := $(foreach file,$(CODEFILES),$(BUILD_DIR)/$(file:.c=.o))

GAMEFILES_C := $(foreach dir,src/game,$(wildcard $(dir)/*.c))
GAMEFILES_S := $(foreach dir,src/game,$(wildcard $(dir)/*.s))
GAMEOBJECTS := $(foreach file,$(GAMEFILES_S),$(BUILD_DIR)/$(file:.s=.o)) \
				$(foreach file,$(GAMEFILES_C),$(BUILD_DIR)/$(file:.c=.o))


ASSET_DATAFILES := assets/GlobalImageTable.c assets/animationtable_data.c assets/animationtable_entries.c assets/font_dl.c assets/font_chardataj.c assets/font_chardatae.c assets/rarewarelogo.c
ASSET_DATAOBJECTS := $(foreach file,$(ASSET_DATAFILES),$(BUILD_DIR)/$(file:.c=.o))

ROMFILES2 := assets/romfiles2.s
ROMOBJECTS2 := $(BUILD_DIR)/assets/romfiles2.o

RAMROM_FILES := assets/ramrom/ramrom.s
RAMROM_OBJECTS := $(BUILD_DIR)/assets/ramrom/ramrom.o


FONTFILES_C := $(foreach dir,assets/font,$(wildcard $(dir)/*.c))
FONTOBJECTS := $(foreach file,$(FONTFILES_C),$(BUILD_DIR)/$(file:.c=.o))


MUSIC_FILES := $(foreach dir,assets/music,$(wildcard $(dir)/*.s))
MUSIC_OBJECTS := $(foreach file,$(MUSIC_FILES),$(BUILD_DIR)/$(file:.s=.o))

OBSEG_FILES := assets/obseg/ob_seg.s
OBSEG_OBJECTS := $(BUILD_DIR)/assets/obseg/ob_seg.o
OBSEG_RZ := $(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) $(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES)

IMAGE_BINS := $(foreach dir,assets/images/split,$(wildcard $(dir)/*.bin))
IMAGE_OBJS := $(foreach file,$(IMAGE_BINS),$(BUILD_DIR)/$(file:.bin=.o))

RZFILES := inflate/inflate.c
RZOBJECTS := $(foreach file,$(RZFILES),$(BUILD_DIR)/src/$(file:.c=.o))

OBJECTS := $(RSPOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(OBSEGMENT) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS)

## Command Line args for builders ##

MIPSISET := -mips2 -32

INCLUDE := -I . -I include -I include/ultra64 -I include/PR -I src -I src/game -I src/inflate

# ignore warnings:
# 609 : The number of arguments in the macro invocation does not match the definition - disabled because CPPLib uses "VarArgs" which wasnt invented till c99
# 649 : Missing member name in structure / union                                      - used for "Inheritance"
# 709 : Incompatible pointer type assignment                                          - could be fixed by casting, but implicit is fine.
# 712 : illegal combination of pointer and integer                                    - could be fixed by casting, but implicit is fine.
# 807 : member cannot be of function or incomplete type                               - Variable length structs
# 838 : Microsoft extension (unnamed structs)                                         - used for "Inheritance" and member/array call swapping
# 763 : Max Float
WOFF :=  -woff 609,649,709,712,807,838,763

ifeq ($(IDO_RECOMP), NO)
  CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
else
  CC := $(IRIX_ROOT)/cc
endif

CFLAGS := -Wab,-r4300_mul -non_shared -Olimit 2000 -G 0 -Xcpluscomm $(CFLAGWARNING) $(WOFF) $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64

LD := $(TOOLCHAIN)ld
LD_SCRIPT := $(BUILD_DIR)/ge007.$(OUTCODE).ld

# --no-warn-mismatch is needed to link -mips3 object files (some libultra math) with the regular files compiled with -mips2
LDFLAGS := -T $(LD_SCRIPT) -Map $(BUILD_DIR)/ge007.$(OUTCODE).map --no-warn-mismatch

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE) $(ASMDEFS) 
# Use the system installed armips if available. Otherwise use the one provided with this repository.
ifneq (,$(shell which armips 2>/dev/null))
  ARMIPS              := armips
else
  ARMIPS              := $(TOOLS_DIR)/armips
endif
ASM_PROCESSOR_DIR := tools/asm-processor
ASM_PREPROC := python3 $(ASM_PROCESSOR_DIR)/asm_processor.py

OBJCOPY := $(TOOLCHAIN)objcopy












## Build Recipes ##

# Dont delete intermediate files from these targets on make completion.
.SECONDARY:
	$(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES)

# Dont delete these intermediate targets on make cancelation.
.PRECIOUS: %.bin  %.o

# Run the following targets sequentialy in this order (unnamed targets will still run in parallel)
.NOTPARALLEL: print_info create_directories $(APPROM) checksum

# Phony Recipes - These targets are not files, Get Make to do something
.PHONY: print_info create_directories build_tools prerequisites checksum all_p1 all default commonclean setupclean stanclean dataclean libultraclean codeclean clean nuke help cmdbuidler test  context extractassets textures 


# this file references variables defined above: BUILD_DIR, CFLAGWARNING, INCLUDE, LCDEFS
# this file defines and builds $(ULTRAOBJECTS)
include src/libultrare/Makefile.libultrare

# Build RSP
$(BUILD_DIR)/rsp/%.bin: rsp/*.s
	$(ARMIPS) -sym $@.sym -strequ CODE_FILE $(BUILD_DIR)/rsp/$*.bin -strequ DATA_FILE $(BUILD_DIR)/rsp/$*_data.bin $<

$(BUILD_DIR)/src/rspboot.o: $(BUILD_DIR)/rsp/rspboot.bin

#Build asm files in root
$(BUILD_DIR)/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

#Build asm files in src/
$(BUILD_DIR)/src/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

#Build Images
$(BUILD_DIR)/assets/images/split/%.o: assets/images/split/%.bin
	$(LD) -r -b binary $< -o $@


#Compress Obseg
$(BUILD_DIR)/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGE_OBJS)


#Build C files in src/
# convert AI_PRINT commands from readable to byte-array
$(BUILD_DIR)/src/%.o: src/%.c
	@if grep -q 'GLOBAL_ASM(' $<; then \
		$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) $(ASM_PROCESSOR_DIR)/include-stdin.c -o $@ $(OPTIMIZATION); \
		$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.inc; \
	elif [ "$$(basename $<)" = "chraidata.c" ]; then \
		$(ConvertAIPRINT) $< | $(CC) -c $(CFLAGS) $(ASM_PROCESSOR_DIR)/include-stdin.c -o $@ $(OPTIMIZATION); \
	else \
		$(CC) -c $(CFLAGS) -o $@ $(OPTIMIZATION) $<; \
	fi


#Build RamRom
$(BUILD_DIR)/assets/ramrom/%.o: assets/ramrom/%.s
	$(AS) $(ASFLAGS) -o $@ $<

#Build fonts
$(BUILD_DIR)/assets/font/%.o: assets/font/%.c
	$(CC) -c $(CFLAGS) -o $@ $(OPTIMIZATION) $<

#Build asm files in assets/
$(BUILD_DIR)/assets/%.o: assets/%.s
	$(AS) $(ASFLAGS) -o $@ $<

#Build Obseg
$(BUILD_DIR)/assets/obseg/%.o: assets/obseg/%.s $(OBSEG_RZ)
	$(AS) $(ASFLAGS) -o $@ $<

#Build C files in assets/
$(BUILD_DIR)/assets/%.o: assets/%.c
ifeq ($(filter-out %setup%,$<),)
	$(ConvertAIPRINT) $< | $(CC) -c $(CFLAGS) $(ASM_PROCESSOR_DIR)/include-stdin.c -o $@ $(OPTIMIZATION)
else
	$(CC) -c $(CFLAGS) -o $@ $(OPTIMIZATION) $<
endif

#$(BUILD_DIR)/src/random.o: OPTIMIZATION := -O3
#$(BUILD_DIR)/src/random.o: INCLUDE := -I . -I include -I include/PR
#$(BUILD_DIR)/src/random.o: MIPSISET := -mips3 -o32
#$(BUILD_DIR)/src/random.o: src/random.c
#	$(CC) -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838,649 -signed $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64 $(OPTIMIZATION) -o $@ $<

#Link Files
$(APPELF): $(RSPOBJECTS) $(ULTRAOBJECTS) $(HEADEROBJECTS) $(OBSEG_RZ) $(BUILD_DIR)/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(ASSET_DATAOBJECTS) $(ROMOBJECTS2) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS) ge007.ld
	cpp $(LDFILEOPTS) -P ge007.ld -o $(BUILD_DIR)/ge007.$(OUTCODE).ld
	@echo "Linking Files into ELF"
	$(LD) $(LDFLAGS) -o $@

$(APPBIN): $(APPELF)
	@echo "Building ROM"
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff

$(APPROM):	$(APPBIN)
	@echo "Compressing ROM"
	$(DATASEG_COMP) $< $(OUTCODE)
	@echo "Finalizing ROM"
	$(N64CKSUM) $< $@


## Phony Recipes below - Get Make to do something ##

print_info:
	$(info VERSION=$(VERSION))
	$(info Building $(VERSION) ROM...)

create_directories:
	scripts/make/create_directories.sh "$(BUILD_DIR)" "$(COUNTRYCODE)"

build_tools:
	$(info Building tools...)
	scripts/make/build_tools.sh "$(MAKE)"

prerequisites: print_info create_directories build_tools extractassets

checksum: $(APPROM)
ifeq ($(COMPARE), 1)
	scripts/make/checksum.sh "$(SHA1SUM)" "$(OUTCODE)" "$(BUILD_DIR)"
endif

all_p1: prerequisites
all: all_p1 $(APPROM) checksum
	@echo "Rom File Generated in Build Directory."

commonclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map

setupclean: commonclean
	rm -f $(SETUP_BUILD_FILES)

stanclean: commonclean
	rm -f $(STAN_BUILD_FILES)

dataclean: commonclean stanclean setupclean
	rm -f $(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES)

libultraclean: commonclean
	rm -f $(ULTRAOBJECTS)

codeclean: commonclean libultraclean
	rm -f $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)

clean: codeclean dataclean
	@echo "\nAll Code and Asset Binaries Cleared! Make will Re-Build these next time.\n"

nuke: clean
	scripts/make/clean_nuke.sh "$(ALLOWED_COUNTRYCODE)" "$(BUILD_DIR_BASE)"

help:
	@echo "mmakefile help"
	@echo ""
	@echo "  supported targets:"
	@echo ""
	@echo "    all                            Build all (default)"
	@echo "    clean                          Delete all known build artifacts"
	@echo "    nuke                           Delete all files explicitly listed in Makefile (same as make clean),"
	@echo "                                    all build output for all versions, any .bin file in assets folders,"
	@echo "                                    and asp/rsp bin."
	@echo "    dataclean                      Delete only asset build artifacts"
	@echo "    codeclean                      Delete only code (asm, .c) build artifacts"
	@echo "    libultraclean                  Delete only code (asm, .c) build artifacts "
	@echo "                                    from Rare's libultra files"
	@echo "    stanclean                      Delete only stan build artifacts"
	@echo "    setupclean                     Delete only setup build artifacts"
	@echo "    cmdbuidler                     BuildAI Commands"
	@echo "    context [file]                 BuildContext File from [file]"
	@echo "                                    eg make context src/game/chrai.c"
	@echo "    test                            Re-Run Data Verification "
	@echo ""
	@echo ""
	@echo "  options:"
	@echo ""
	@echo "    VERSION=v                       Region version. (US is default)"
	@echo "                                    Supported values: ${ALLOWED_VERSIONS}\n"

include include/make/cmd.make


test: checksum


ifneq ($(filter-out context,$(MAKECMDGOALS)),)
 CONTEXTFILE := $(filter-out context ,$(MAKECMDGOALS))
else
 CONTEXTFILE := build/ctx.c
endif
context:
	@clear
	@echo Building Context File [ctx.h] from $(CONTEXTFILE)
	@echo "#define TRUE 1" > build/ctx.h
	@echo "#define FALSE 0" >> build/ctx.h
ifeq ($(CONTEXTFILE),build/ctx.c)
	@echo "#include <bondtypes.h>" > build/ctx.c
endif
	@sed -n -E ':x /\\$$/ { N; s/\\\n//g ; bx };''/(^\s*#define)|(\\$$)/p; /(\\$$)/p;' src/bondconstants.h src/bondtypes.h $(CONTEXTFILE) >> build/ctx.h
	@$(CC) -c $(CFLAGS) $(CONTEXTFILE) -E > build/ctx2.h 2> /dev/null || (rm build/ctx2.h && exit 1)
	@sed -E '/^\s*$$/d' build/ctx2.h >> build/ctx.h
	@rm build/ctx.c build/ctx2.h || exit 0
	@echo You can find it in Build [build/ctx.h].

extractassets: extract_u extract_e extract_j

extract_u:
	@if [ ! -f assets/obseg/ob__ob_end.seg ]; then \
		echo "Extracting assets for u..."; \
		if [ -f baserom.u.z64 ]; then \
			scripts/extract_baserom.u.sh; \
		else \
			echo "Error: baserom.u.z64 not found."; \
		fi \
	else \
		echo "Assets for u already extracted."; \
	fi

extract_e:
	@if [ ! -f assets/obseg/text/e/LwaxP.bin ]; then \
		echo "Extracting assets for e..."; \
		if [ -f baserom.e.z64 ]; then \
			scripts/extract_diff.e.sh; \
		else \
			echo "Error: baserom.e.z64 not found."; \
		fi \
	else \
		echo "Assets for e already extracted."; \
	fi

extract_j:
	@if [ ! -f assets/obseg/text/j/LstatJ.bin ]; then \
		echo "Extracting assets for j..."; \
		if [ -f baserom.j.z64 ]; then \
			scripts/extract_diff.j.sh; \
		else \
			echo "Error: baserom.j.z64 not found."; \
		fi \
	else \
		echo "Assets for j already extracted."; \
	fi

extract_rsp:
	@if [ ! -f build/u/rsp/rspboot.bin ]; then \
		echo "Extracting rsp assets..."; \
		if [ -f baserom.u.z64 ]; then \
			scripts/extract_asp_gsp_rsp.sh; \
		else \
			echo "Error: baserom.u.z64 not found."; \
		fi \
	else \
		echo "RSP assets for already extracted."; \
	fi

textures: tools/mktex/build/tex2png
	@echo "Processing textures..."
	mkdir -p assets/images/out
	$(foreach x,$(IMAGE_BINS),tools/mktex/build/tex2png $(x) assets/images/out ${\n})


tools/mktex/build/tex2png:
	@if [ ! -f tools/mktex/build/tex2png ]; then \
		echo "Building tex2png..."; \
		cd tools/mktex && $(MAKE); \
	fi
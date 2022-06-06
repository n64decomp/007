# Makefile to rebuild Goldeneye 007

### Default target ###
default: colour

### Default Build Options ###
# Version of the game to build
FINAL := YES
VERSION := US
IDO_RECOMP := YES
VERBOSE := 0
# If COMPARE is 1, check the output sha1sum when building 'all', and if fail to match
# then compare ELF sections to known md5 checksums.
# If compare is 2, it will just compare the sha1sum.
COMPARE := 1


## VT100 Codes ##
SAVECURSOR := \0337\033[s
RESTORECURSOR := \0338\033[u
SET_SCROLLREGION = \033[$(1);$(2)r
RESTORESCROLLREGION := \033[r
CURSOR_GOTO = \033[$(1);$(2)H
SET_TEXTATTRIB = \033[$(1)$(if $(2),;$(2))$(if $(3),;$(3))m
BELL := \007

#Attributes
RESTORECOLOUR := \033[m
BOLD := 1
DIM := 2
UNDERSCORE := 4
BLINK := 5
INVERT := 7
HIDDEN := 8

#Colours
FG_BLACK:= 30
FG_MAROON:= 31
FG_GREEN:= 32
FG_OLIVE:= 33
FG_NAVY:= 34
FG_PURPLE:= 35
FG_TEAL:= 36
FG_SILVER:= 37
FG_GRAY:= 90
FG_RED:= 91
FG_LIME:= 92
FG_YELLOW:= 93
FG_BLUE:= 94
FG_VIOLET:= 95
FG_CYAN:= 96
FG_WHITE:= 97

BG_BLACK:= 40
BG_MAROON:= 41
BG_GREEN:= 42
BG_OLIVE:= 43
BG_NAVY:= 44
BG_PURPLE:= 45
BG_TEAL:= 46
BG_SILVER:= 47
BG_GRAY:= 100
BG_RED:= 101
BG_LIME:= 102
BG_YELLOW:= 103
BG_BLUE:= 104
BG_VIOLET:= 105
BG_CYAN:= 106
BG_WHITE:= 107

### Build Functions ###
# Common build print status function
PRINT_STATUS = @echo "$(call SET_TEXTATTRIB,$(FG_GREEN))$(1) $(call SET_TEXTATTRIB,$(FG_OLIVE))$(2)$(call SET_TEXTATTRIB,$(FG_GRAY)) $(if $3, -> $(call SET_TEXTATTRIB,$(FG_NAVY))$(3))$(RESTORECOLOUR)"

# Seperate "constant" drawing from variable drawing to speed up PBar rendering
# draws a box and fills it grey ready for blue bar
SetupProgressBar =                                                                                           \
	{                                                                                                        \
		str="$(SAVECURSOR)$(call SET_SCROLLREGION,4,0)$(call CURSOR_GOTO,2,999)\033[1J$(call CURSOR_GOTO,1)";\
		str=$$str"\033(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk";   \
		str=$$str"\nx$(call SET_TEXTATTRIB,$(BG_GRAY))%78s$(RESTORECOLOUR)x\n";                              \
		str=$$str"mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\033(B";   \
		str=$$str"$(RESTORECURSOR)";                                                                         \
		printf $$str "";                                                                                     \
	}

#(call DrawProgressBar,Percent)
# OR
#(call DrawProgressBar,NumberOfItemsDone,TotalNumberOfItems)
# If second param is given, use it to work out a percentage.
# divide the percentage into a 80 char long bar
# paint the whole bar grey
# paint the first half, then text, then second half.
# clear colour codes 
DrawProgressBar =                                       \
	{                                                   \
		$(if $(2),                                      \
			if [ "$(1)" -ne "$(2)" ];                   \
			then                                        \
				_pdone=`expr 100 / $(2) \* $(1)`;       \
			else                                        \
				_pdone=100;                             \
			fi                                          \
			,_pdone=$(1)                                \
		);                                              \
		pdone=`expr $$_pdone \* 74 / 100`;              \
		pdoneb=0;                                       \
		str="$(SAVECURSOR)$(call CURSOR_GOTO,2,2)";\
		str=$$str"$(call SET_TEXTATTRIB,$(BOLD),$(FG_WHITE),$(BG_NAVY))" ;    \
		                                                \
		if [ "$$pdone" -lt "36" ];                      \
		then                                            \
			str=$$str"%$${pdone}s";                     \
			str=$$str"$(call SET_TEXTATTRIB,$(BG_GRAY))";\
			pdoneb=`expr 36 - $$pdone`;                 \
			str=$$str"%$${pdoneb}s%3d%%";               \
		else                                            \
			pdoneb=`expr $$pdone - 36`;                 \
			str=$$str"%1s%35s%3d%%%$${pdoneb}s";        \
		fi;                                             \
		str=$$str"$(RESTORECURSOR)$(RESTORECOLOUR)";    \
		printf $$str "" "" $$_pdone;                 \
	}

# Increment Progress Bar From percentage (1), and increase by 1 every (2) seconds.
# Continue doing so until calling process ends
IncrementProgressBarFromAtRate =         \
	{                                    \
		i=$(1);                          \
		while [ -d /proc/$$! ] && [ $$i -le 100 ]; do       \
			$(call DrawProgressBar,$$i); \
			i=$$((i+1));                 \
			sleep $(2);                  \
		done;                            \
	}

# Ask to continue
# (1) Prompt, (2) Do if Yes,
# (3) Do if No [can be blank],
# (4) Do if anything else [can be blank]
# (5) Timeout [can be blank]
ContinuePrompt =                                    \
	{                                               \
		echo "$1 [y/n]";                            \
		$(if $(5), readchr(){ old=$$(stty -g);  stty raw -echo min 0 time 30; printf '%s' $$(dd bs=1 count=1 2>/dev/null); stty $$old;}; REPLY=$$(readchr) ,read REPLY ); \
		echo $$REPLY; case $$REPLY in                             \
			y|Y) $2;;                               \
			n|N) $3;;                               \
			*) $4;;                                 \
		esac;                                       \
	}

# Convert AI Print commands from readable strings to byte arrays automatically.
ConvertAIPRINT = sed -E -e ':loop s/PRINT\("(..*?)(.)"/PRINT\("\1",\x27\2\x27/g; tloop; \
                s/(PRINT\(.*?)\x27\\\x27,\x27(.)\x27(.*)\)/\1\x27\\\2\x27\3\)/g; \
                s/(PRINT\()"(.)"(.*)\)/\1\x27\2\x27\3\)/g; \
                s/PRINT\((.*)\)/PRINT\(\1,\x27\\0\x27\,)/g; \
                s/PRINT\((.*)\)/AI_PRINT,\1/g'

## More Build Variables (Auto) ##

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips64-linux-gnu-
else
  TOOLCHAIN := mips64-elf-
endif

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
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0
 ASMDEFS := --defsym VERSION_US=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1
endif

ifeq ($(VERSION), EU)
 COUNTRYCODE := e
 OUTCODE := $(COUNTRYCODE)
 LCDEFS := -DVERSION_EU -DLANG_EU -DREFRESH_PAL -DBUGFIX_R1 -DBUGFIX_R2 
 ASMDEFS := --defsym VERSION_EU=1 --defsym LANG_EU=1 --defsym REFRESH_PAL=1 --defsym BUGFIX_R1=1 --defsym BUGFIX_R2=1
endif

ifeq ($(VERSION), JP)
 COUNTRYCODE := j
 OUTCODE := $(COUNTRYCODE)
 LCDEFS := -DVERSION_JP -DLANG_JP -DREFRESH_NTSC -DBUGFIX_R1 -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM
 ASMDEFS := --defsym VERSION_JP=1 --defsym LANG_JP=1 --defsym REFRESH_NTSC=1 --defsym BUGFIX_R1=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1
endif

ifeq ($(VERSION), DEBUG)
 COUNTRYCODE := u
 OUTCODE := d
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0 -DDEBUGMENU
 ASMDEFS := --defsym VERSION_DEBUG=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1 --defsym DEBUGMENU=1
 COMPARE := 0
endif

ALLOWED_VERSIONS := US EU JP DEBUG

BUILD_DIR_BASE := build
# BUILD_DIR is the location where all build artifacts are placed
BUILD_DIR      := $(BUILD_DIR_BASE)/$(OUTCODE)
include assets/Makefile.obseg
include assets/Makefile.music
BUILD_SUB_DIRS := \
	rsp src src/game src/inflate \
	src/libultra src/libultra/audio src/libultra/gt src/libultra/gu src/libultra/io \
	src/libultra/libc src/libultra/os src/libultra/rg src/libultra/sched src/libultra/sp \
	src/libultrare src/libultrare/audio src/libultrare/gt src/libultrare/gu src/libultrare/io \
	src/libultrare/libc src/libultrare/os src/libultrare/rg src/libultrare/sched src/libultrare/sp \
	assets assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop \
	assets/obseg/text assets/obseg/bg assets/obseg/setup assets/obseg/setup/$(COUNTRYCODE) assets/obseg/stan \
	assets/music assets/ramrom assets/images assets/images/split assets/font \
	assets/embedded assets/embedded/skeletons assets/embedded/player_gait_object
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach subdir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(subdir)))

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


ASSET_DATAFILES := assets/GlobalImageTable.c assets/animationtable_data.c assets/animationtable_entries.c assets/font_dl.c assets/font_chardataj.c assets/font_chardatae.c assets/Globalimagetable_commandblock.c
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
WOFF :=  -woff 609,649,709,712,807,838

ifeq ($(IDO_RECOMP), NO)
  CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
else
  CC := $(IRIX_ROOT)/cc
endif

CFLAGS := -Wab,-r4300_mul -non_shared -Olimit 2000 -G 0 -Xcpluscomm $(CFLAGWARNING) $(WOFF) -signed $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64

LD := $(TOOLCHAIN)ld
LD_SCRIPT := ge007.$(OUTCODE).ld

# --no-warn-mismatch is needed to link -mips3 object files (some libultra math) with the regular files compiled with -mips2
LDFLAGS := -T $(LD_SCRIPT) -Map build/ge007.$(OUTCODE).map --no-warn-mismatch

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE) $(ASMDEFS)
# Use the system installed armips if available. Otherwise use the one provided with this repository.
ifneq (,$(shell which armips 2>/dev/null)) 
  ARMIPS              := armips
else
  ARMIPS              := $(TOOLS_DIR)/armips
endif
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

#Now using cursor commands for better look  original was //"\033[5;42;97m%80s\r\n%43s%37s\r\n%80s\007\033[0;0m\n"
#                        Rsrv   Up 3                                                        80  Dn 1 Return      Dn 1 Ret 80ch                  
#                        Lines Lines                                                        ch  Line SoL midway  Line SoL      Bell 
PRINTNOMATCH := printf "\n\n\033[3A$(call SET_TEXTATTRIB,$(BLINK),$(BG_MAROON),$(FG_WHITE))%80s\033[1B\r%45s%35s\033[1B\r%80s$(BELL)$(RESTORECOLOUR)$(call SET_TEXTATTRIB,$(FG_RED))\n\n\n" "" "NOT MATCH!" "" ""
PRINTMATCH := printf "\n\n\n\033[3A$(call SET_TEXTATTRIB,$(BLINK),$(BG_GREEN),$(FG_WHITE))%80s\033[1B\r%43s%37s\033[1B\r%80s$(BELL)$(RESTORECOLOUR)\n" "" "MATCH!" "" "" 

## Build Recipies ##

# this file references variables defined above: BUILD_DIR, CFLAGWARNING, INCLUDE, LCDEFS
# this file defines $(ULTRAOBJECTS)
include src/libultrare/Makefile.libultrare

all: $(APPROM)
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,100)
endif
ifeq ($(COMPARE),1)

	@echo "\n"
#   Calculate Checksum                      if fail                                         Allow overspill                                    Which File failed                       Quick Check (data)                    Slow Check (extract .text binary)
	@$(SHA1SUM) -c ge007.$(OUTCODE).sha1 || ($(PRINTNOMATCH) && echo "$(SAVECURSOR)$(RESTORESCROLLREGION)$(RESTORECURSOR)\033[2D " && $(call ContinuePrompt,"Do you want to check Source Files?",echo "Please wait while we determine which files are affected..." && $(SHA1SUM) --quiet -c checksums.txt && ./test_files.sh -c -i ge007.$(OUTCODE)-test_basis.csv,,,3) && exit 1)
#   Else complete 
	@$(PRINTMATCH)
endif
ifeq ($(COMPARE),2)
	@$(SHA1SUM) -c ge007.$(COUNTRYCODE).sha1
endif
	@echo "\n Rom File Generated in Build Directory. \n\n"

.SECONDARY:
	$(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) 

ifeq ($(filter clean dataclean help codeclean context cmdbuilder test stanclean setupclean colour print-%,$(MAKECMDGOALS)),)
# Dont print version on "default" since it will be spat out twice
    ifneq ($(filter $(VERSION),$(ALLOWED_VERSIONS)),)
      #$(info VERSION=$(VERSION))
    else
      $(error VERSION "$(VERSION)" not supported")
    endif
    # Make tools if out of date
    $(info Building tools...)
    DUMMY != make -s -C tools >&2 || echo FAIL
    ifeq ($(DUMMY),FAIL)
      $(error Failed to build tools)
    endif
    $(info Building $(VERSION) ROM...)

endif

# Build RSP
$(BUILD_DIR)/rsp/%.bin: rsp/*.s pb1
	$(call PRINT_STATUS,Assembling1:,$<,$@)
	$(ARMIPS) -sym $@.sym -strequ CODE_FILE $(BUILD_DIR)/rsp/$*.bin -strequ DATA_FILE $(BUILD_DIR)/rsp/$*_data.bin $<

$(BUILD_DIR)/src/rspboot.o: $(BUILD_DIR)/rsp/rspboot.bin 

#Build asm files in root
$(BUILD_DIR)/%.o: src/%.s pb2
	$(call PRINT_STATUS,Assembling2:,$<,$@)
	$(AS) $(ASFLAGS) -o $@ $<

#Build asm files in src/
$(BUILD_DIR)/src/%.o: src/%.s pb3
	$(call PRINT_STATUS,Assembling3:,$<,$@)
	$(AS) $(ASFLAGS) -o $@ $<

#Build Images
$(BUILD_DIR)/assets/images/split/%.o: assets/images/split/%.bin pb5
	$(call PRINT_STATUS,Compiling5:,$<,$@)
	$(LD) -r -b binary $< -o $@ 


#Compress Obseg
$(BUILD_DIR)/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGE_OBJS) pb6
	$(call PRINT_STATUS,Compressing6:,$<,$@)

#Build C files in root/
$(BUILD_DIR)/%.o: src/%.c pb7
	$(call PRINT_STATUS,Compiling7:,$<,$@)
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s


#Build C files in src/
$(BUILD_DIR)/src/%.o: src/%.c pb8
	$(call PRINT_STATUS,Compiling8:,$<,$@)
    # convert AI_PRINT commands from readable to byte-array
    #	echo $<
    #	echo filter =  $(filter-out %chraidata.c,$<)
    # for some reason, normal ifeq doesnt work, so has to be single line...
	$(if $(filter %chraidata.c,$<), $(ConvertAIPRINT) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION), $(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION); $(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s)


#Build RamRom
$(BUILD_DIR)/assets/ramrom/%.o: assets/ramrom/%.s pb9
	$(call PRINT_STATUS,Assembling9:,$<,$@)
	$(AS) $(ASFLAGS) -o $@ $<

#Build fonts
$(BUILD_DIR)/assets/font/%.o: assets/font/%.c pb10
	$(call PRINT_STATUS,Compiling10:,$<,$@)
	$(CC) -c $(CFLAGS) -o $@ $(OPTIMIZATION) $<

#Build asm files in assets/
$(BUILD_DIR)/assets/%.o: assets/%.s pb11
	$(call PRINT_STATUS,Assembling11:,$<,$@)
	$(AS) $(ASFLAGS) -o $@ $<

#Build Obseg
$(BUILD_DIR)/assets/obseg/%.o: assets/obseg/%.s $(OBSEG_RZ) pb12
	$(call PRINT_STATUS,Assembling12:,$<,$@)
	$(AS) $(ASFLAGS) -o $@ $<

#Build C files in assets/
$(BUILD_DIR)/assets/%.o: assets/%.c pb4
	$(call PRINT_STATUS,Compiling4:,$<,$@)
ifeq ($(filter-out %setup%,$<),)
	$(ConvertAIPRINT) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION) 
else
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s
endif

#$(BUILD_DIR)/src/random.o: OPTIMIZATION := -O3
#$(BUILD_DIR)/src/random.o: INCLUDE := -I . -I include -I include/PR
#$(BUILD_DIR)/src/random.o: MIPSISET := -mips3 -o32
#$(BUILD_DIR)/src/random.o: src/random.c
#	$(CC) -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838,649 -signed $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64 $(OPTIMIZATION) -o $@ $<

#Link Files
$(APPELF): $(RSPOBJECTS) $(ULTRAOBJECTS) $(HEADEROBJECTS) $(OBSEG_RZ) $(BUILD_DIR)/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(ASSET_DATAOBJECTS) $(ROMOBJECTS2) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS) pb14
	@echo "Linking Files into ELF" 
	$(LD) $(LDFLAGS) -o $@  & $(call IncrementProgressBarFromAtRate,87,1.5)

$(APPBIN): $(APPELF)
  ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,98)
  endif
	@echo "Building ROM"
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff
	
$(APPROM):	$(APPBIN)
  ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,100)
  endif
	@echo "Compressing ROM"
	$(DATASEG_COMP) $< $(OUTCODE)
	@echo "Finalizing ROM"
	$(N64CKSUM) $< $@

.PRECIOUS: %.bin  %.o




## Phony Recipies - Get Make to do something ##


.PHONY: all default codeclean dataclean clean cmdbuidler test help colour
# Dont declare as phony otherwise make will re-evaluate every build including the recipies assosiated with them - just make sure no file is ever called pbx
# pb1 pb2 pb3 pb4 pb5 pb6 pb7 pb8 pb9 pb10 pb11 pb12 pb13 pb14

setupclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(SETUP_BUILD_FILES)

stanclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(STAN_BUILD_FILES)

libultraclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(ULTRAOBJECTS)


codeclean:
ifeq ($(VERBOSE),1)
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)
else
	@clear
	$(call SetupProgressBar)
	@echo "\n\nDeleting All Code Binaries Only [Assets will be left from previous compile]"
	@rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map
	@$(call DrawProgressBar,50)
	@rm -f $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)
	@$(call DrawProgressBar,100)
endif
	@echo "\033[1J$(RESTORESCROLLREGION)\nCode Binaries Cleared! Make will Re-Build these next time.\n"

dataclean: 
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) \
	$(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)

clean:
ifeq ($(VERBOSE),1)
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) $(RSPOBJECTS) \
	$(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)
else
	@clear
	@echo "\n\nDeleting All Code and Asset Binaries"
	$(call SetupProgressBar)
	@$(call DrawProgressBar,0)
	@rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map
	@$(call DrawProgressBar,1,4)
	@rm -f $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS)
	@$(call DrawProgressBar,2,4)
	@rm -f $(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS)
	@$(call DrawProgressBar,3,4)
	@rm -f $(IMAGE_OBJS) $(MUSIC_RZ_FILES) $(RSPOBJECTS) $(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)
	@$(call DrawProgressBar,100)
endif
	@echo "\033[1J$(RESTORESCROLLREGION)\nAll Code and Asset Binaries Cleared! Make will Re-Build these next time.\n"


#         0    4                             35                                            80             80(with colour codes)
help:
	@echo "\n\033[1;4mmakefile help$(RESTORECOLOUR)"
	@echo ""
	@echo "  supported targets:"
	@echo ""
	@echo "    all                            $(call SET_TEXTATTRIB,$(FG_LIME)) Build$(RESTORECOLOUR) all (default)"
	@echo "    clean                          $(call SET_TEXTATTRIB,$(FG_RED)) Delete all$(RESTORECOLOUR) build artifacts"
	@echo "    dataclean                      $(call SET_TEXTATTRIB,$(FG_RED)) Delete$(RESTORECOLOUR) only asset build artifacts"
	@echo "    codeclean                      $(call SET_TEXTATTRIB,$(FG_RED)) Delete$(RESTORECOLOUR) only code (asm, .c) build artifacts"
	@echo "    libultraclean                  $(call SET_TEXTATTRIB,$(FG_RED)) Delete$(RESTORECOLOUR) only code (asm, .c) build artifacts "
	@echo "                                    from Rare's libultra files"
	@echo "    stanclean                      $(call SET_TEXTATTRIB,$(FG_RED)) Delete$(RESTORECOLOUR) only stan build artifacts"
	@echo "    setupclean                     $(call SET_TEXTATTRIB,$(FG_RED)) Delete$(RESTORECOLOUR) only setup build artifacts"
	@echo "    cmdbuidler                     $(call SET_TEXTATTRIB,$(FG_LIME)) Build$(RESTORECOLOUR) AI Commands"
	@echo "    context [file]                 $(call SET_TEXTATTRIB,$(FG_LIME)) Build$(RESTORECOLOUR) Context File from [file]"
	@echo "                                    eg make context src/game/chrai.c"
	@echo "    test                            Re-Run Data Verification "
	@echo ""
	@echo ""
	@echo "  options:"
	@echo ""
	@echo "    VERSION=v                       Region version. (US is default)"
	@echo "                                    Supported values: ${ALLOWED_VERSIONS}\n"

#CMD Builder tools
AI_CMD_BUILDER := $(TOOLS_DIR)/cmdbuilder.c
AI_CMD_LIST_DEFINITIONS := src/aicommands.def
AI_CMD_LIST_TEMP := $(BUILD_DIR)/aicommands.temp
AI_CMD_LIST_H2 := src/aicommands2.h
#Pre-Format encoding newlines and tags
AI_CMD_BUILDER_PRECONVERT := sed -E
AI_CMD_BUILDER_PRECONVERT += -e 's/\x27\\n\x27/\x27\/n\x27/g;' #                     encode '\n' as '/n' (TEXT PRINT command)
AI_CMD_BUILDER_PRECONVERT += -e '/^\s*\*/ s/\x27/\?\?x27/g;' #                       encode DocBlock(/**...**/) quotes '' as x27
AI_CMD_BUILDER_PRECONVERT += -e '/\/\*\*/ , /\*\// s/([^/])$$/\1 \\n\\/g;' #         encode DocBlock(/**...**/) Newlines as \n\ .
#AI_CMD_BUILDER_PRECONVERT += -e '/^\s*\*/ s/([^\/])$$/\1 \\n\\/g;' #                encode DocBlock(/**...**/) Newlines as \n\ .
AI_CMD_BUILDER_PRECONVERT += -e 's/[^/\*\S]\*$$/\\n\\/g; s/^(\s*)\*[^/\*]/\1  /g;' # remove DocBlock sides (causes problems with tooltips) fixed to check for ordinary comment
#AI_CMD_BUILDER_PRECONVERT += -e '/^_AI_CMD_POLYMORPH\(CMDNAME,\n(.|\n)*?\s{19}DESCRIPTION(\)| DESCRIPTION2\))/ s/[^,]\n/\\n\\/g;' #      Newlines in POLYMORPHS 
AI_CMD_BUILDER_PRECONVERT += -e 's/\/\*\*/\?\?\\\*\(\*\*/g;' #                       encode /** as ??\*(**
AI_CMD_BUILDER_PRECONVERT += -e 's/\*\*\//\*\*\)\*\?\?\\ /g;' #                      encode **/ as **)*??\ 
#Format Newlines and Comment tags
AI_CMD_BUILDER_CONVERT := sed -E
AI_CMD_BUILDER_CONVERT += -e 's/\\n/\n/g;' #                add newlines
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}\=/\#/g;' #            replace ??= with hash for defines
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}\\/\//g;' #            replace ??\ with /
AI_CMD_BUILDER_CONVERT += -e 's/DEFINE([^D])/\#define\1/g;' #       replace DEFINE with #define
AI_CMD_BUILDER_CONVERT += -e 's/\\.*/\\/g;' #               replace \... with \ (line continuation)
AI_CMD_BUILDER_CONVERT += -e 's/\*\(\*/\*/g;' #             replace *(* with *
AI_CMD_BUILDER_CONVERT += -e 's/\*\)\*/\*/g;' #             replace *)* with *
AI_CMD_BUILDER_CONVERT += -e 's/MAKE_EXPAND\(([^\n]*)MAKE_EXPAND_END\)/\1/g;' #replace MAKE_EXPAND(CONTENTS) with CONTENTS
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}x27/\x27/g;' #         replace ??x27 with '
AI_CMD_BUILDER_CONVERT += -e 's/\x27\/n\x27/\x27\\n\x27/g;' # replace '/n' with '\n'
AI_CMD_BUILDER_CONVERT += -e 's/AI_EndList\s*,/AI_EndList/g;' # replace AI_EndList , with AI_EndList
AI_CMD_BUILDER_CONVERT += -e '/^ *$$/d'

AI_CMD_LIST_H2_HEADER := \
"/******************************************************************************\n\
*                                                                            *\n\
*                                                                            *\n\
*  Do not edit this file.  It was automatically generated by \"cmdbuilder\"    *\n\
*  from the file \"$(AI_CMD_LIST_DEFINITIONS)\".                                       *\n\
*  To Add/Remove/Modify AI Commands please edit \"$(AI_CMD_LIST_DEFINITIONS)\"         *\n\
*  and then run                                                              *\n\
*     make cmdbuilder                                                        *\n\
*                                                                            *\n\
*                                                                            *\n\
*****************************************************************************/\n\n"


cmdbuilder:
	@clear
	@echo
	@echo Building AI Command Macros...
	@echo
	@$(call SetupProgressBar)
	@$(call DrawProgressBar,0)
	@ # copy command definitions to temp
	@cp $(AI_CMD_LIST_DEFINITIONS) $(AI_CMD_LIST_TEMP)
	@$(call DrawProgressBar,5)
	@ # Preformat Definitions for builder (encode documentation tags)
	@$(call PRINT_STATUS,"Pre Formatting",$(AI_CMD_LIST_DEFINITIONS))
	@$(AI_CMD_BUILDER_PRECONVERT) $(AI_CMD_LIST_TEMP) > $(AI_CMD_LIST_DEFINITIONS)
	@$(call DrawProgressBar,10)
	@ # Print Header
	@echo $(AI_CMD_LIST_H2_HEADER) > $(AI_CMD_LIST_H2)
	@$(call DrawProgressBar,11)
	@ # Execute Builder and format (re-add newlines, documentation tags etc) -C keeps /**/ comments
	@$(call PRINT_STATUS,"Processing",$(AI_CMD_LIST_DEFINITIONS))
	@echo This might take some time...
	@$(CC) -Xcpluscomm -c $(AI_CMD_BUILDER) $(INCLUDE) -w 581 -E | $(AI_CMD_BUILDER_CONVERT) >> $(AI_CMD_LIST_H2) & $(call IncrementProgressBarFromAtRate,12,0.5)
	@$(call DrawProgressBar,98)
	@ # restore command def from temp (no encoding)
	@cp $(AI_CMD_LIST_TEMP) $(AI_CMD_LIST_DEFINITIONS)
	@$(call DrawProgressBar,99)
	@rm $(AI_CMD_LIST_TEMP)
	@$(call DrawProgressBar,100)
	@echo
	@echo Done!
	@echo
	@echo Rebuild AI Command Macros whenever changing aicommands.def.
	@echo "\n$(BELL)$(SAVECURSOR)$(RESTORESCROLLREGION)$(RESTORECURSOR)\033[1A"

test:
	@$(SHA1SUM) --quiet -c checksums.txt
	@printf "\033[1;92m All Checked Files Match\033[0m\n\n"
#	@$(SHA1SUM) $(BG__SEG_FILES) $(BRIEF_RZ_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) \
	$(PROP_RZ_FILES) $(SETUP_BIN_FILES) $(STAN_RZ_FILES) $(TEXT_RZ_FILES) > checksums.txt


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

testPB:
	$(call SetupProgressBar)
	$(call IncrementProgressBarFromAtRate,0,0.125)

colour:
	@echo "\033[3A"
  ifeq ($(VERBOSE),0)
#	@clear
	@$(call SetupProgressBar)
	@$(call DrawProgressBar,0)
  endif
	@$(MAKE) --no-print-directory all 2>&1 | sed -E \
	-e 's/\(\(\x27E\x27\,\x27R\x27\,\x27R\x27\,\x27O\x27\,\x27R\x27,\s?((\x27?,?\s?\x27.)*)\x27,\s?\x27([^x27])\x27\)/((\x27ERROR\x27,\1\3\x27\)/g; :loop s/\(\((\x27ERROR)((\x27?,?\s?\x27.)*),?\s?\x27(.)\x27([^x27]*)\x27\)/((\1\2\5\x27\)/g; tloop; ' \
	-e "s/(ERROR:[^\x27]*?\x27)|(^.*[Ee]rror.*)|(Mis-Match in)|(:\sFAILED)/$$(echo "$(call SET_TEXTATTRIB,$(FG_RED))")&$$(echo "$(RESTORECOLOUR)")/g" \
	-e "s/^.*[Ww]arning.*/$$(echo "$(call SET_TEXTATTRIB,$(FG_YELLOW))")&$$(echo "$(RESTORECOLOUR)")/g" \
	-e "s/^.*(([Bb]uilding)|(:\sOK)|([Ll]inkin)).*/$$(echo "$(call SET_TEXTATTRIB,$(FG_LIME))")&$$(echo "$(RESTORECOLOUR)")/g" \
	-e "s/((([^\/]*([^s][^t][^d][^i][^n])\.c)|([^\/]*\.o))\s)/$$(echo "$(call SET_TEXTATTRIB,$(FG_WHITE))")&$$(echo "$(RESTORECOLOUR)")/g" 
	@echo "$(SAVECURSOR)$(RESTORESCROLLREGION)$(RESTORECURSOR)\033[1A"

ifeq ($(VERBOSE),0)
.SILENT:
endif


## Progress Bar status - call once ##
pb1:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,1,15)
endif
pb2:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,2,15)
endif
pb3:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,3,15)
endif
pb4:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,4,15)
endif
pb5:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,5,15)
endif
pb6:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,6,15)
endif
pb7:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,7,15)
endif
pb8:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,8,15)
endif
pb9:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,9,15)
endif
pb10:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,10,15)
endif
pb11:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,11,15)
endif
pb12:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,12,15)
endif
pb13:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,13,15)
endif
pb14:
ifeq ($(VERBOSE),0)
	@$(call DrawProgressBar,14,15)
endif




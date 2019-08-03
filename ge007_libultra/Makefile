### Default target ###

default: all

### Build Options ###
# Version of the game to build
VERSION ?= sgi
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE ?= 1
FINAL ?= YES

ifeq ($(VERSION),gcc)
  VERSION_CFLAGS := -DVERSION_GCC=1
  VERSION_ASFLAGS := --defsym VERSION_GCC=1
  TARGET := libgultra
else
  VERSION_CFLAGS := -DVERSION_SGI=1
  VERSION_ASFLAGS := --defsym VERSION_SGI=1
  TARGET := libultra
endif

ifeq ($(FINAL),YES)
  FINAL_CFLAGS := -DFINAL=1
  FINAL_ASFLAGS := --defsym FINAL=1
  TARGET_TYPE := _rom
else
  FINAL_CFLAGS := -DDEBUG=1
  FINAL_ASFLAGS := --defsym DEBUG=1
  TARGET_TYPE := 
endif

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR_BASE := ../build/libultra
BUILD_DIR := $(BUILD_DIR_BASE)/$(VERSION)


LIBULTRA := ../lib/$(TARGET)$(TARGET_TYPE).a


# Directories containing source files
ULTRA_SRC_DIRS := lib/src lib/src/math
ULTRA_ASM_DIRS := lib/asm

MIPSISET := -mips2 -32
OPT_FLAGS := -O2


# Source code files
ULTRA_C_FILES := $(foreach dir,$(ULTRA_SRC_DIRS),$(wildcard $(dir)/*.c))
ULTRA_S_FILES := $(foreach dir,$(ULTRA_ASM_DIRS),$(wildcard $(dir)/*.s))


# Object files
ULTRA_O_FILES := $(foreach file,$(ULTRA_S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
                 $(foreach file,$(ULTRA_C_FILES),$(BUILD_DIR)/$(file:.c=.o))		   
		   
IRIX_ROOT := ../tools/irix/root
QEMU_IRIX := ../tools/irix/qemu-irix
CROSS := mips-linux-gnu-
AS        := $(CROSS)as
CC        := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CPP       := cpp -P
LD        := $(CROSS)ld
AR        := $(CROSS)ar
OBJDUMP   := $(CROSS)objdump
OBJCOPY   := $(CROSS)objcopy


ASFLAGS := -march=vr4300 -mabi=32 -I include -I $(BUILD_DIR) $(VERSION_ASFLAGS)
CFLAGS = -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(OPT_FLAGS) -signed -I include -I include/ultra64 $(VERSION_CFLAGS) $(MIPSISET)


####################### Other Tools #########################

# N64 tools
TOOLS_DIR = tools

###################### Dependency Check #####################

BINUTILS_VER_MAJOR := $(shell $(LD) --version | grep ^GNU | sed 's/^.* //; s/\..*//g')
BINUTILS_VER_MINOR := $(shell $(LD) --version | grep ^GNU | sed 's/^[^.]*\.//; s/\..*//g')
BINUTILS_DEPEND := $(shell expr $(BINUTILS_VER_MAJOR) \>= 2 \& $(BINUTILS_VER_MINOR) \>= 27)
ifeq ($(BINUTILS_DEPEND),0)
$(error binutils version 2.27 required, version $(BINUTILS_VER_MAJOR).$(BINUTILS_VER_MINOR) detected)
endif

ifndef QEMU_IRIX
$(error env variable QEMU_IRIX should point to the qemu-mips binary)
endif

######################## Targets #############################

all: tools/patch_libultra_math libultra 

clean:
	$(RM) -r $(LIBULTRA) $(BUILD_DIR_BASE) tools/patch_libultra_math

libultra: $(LIBULTRA)


# Make sure build directory exists before compiling objects
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(ULTRA_SRC_DIRS) $(ULTRA_ASM_DIRS))

$(ULTRA_O_FILES): | $(BUILD_DIR)

# Source code
$(BUILD_DIR)/lib/src/%.o: OPT_FLAGS :=
$(BUILD_DIR)/lib/src/math/ll%.o: MIPSISET := -mips3 -32
$(BUILD_DIR)/lib/src/math/%.o: OPT_FLAGS := -O2
$(BUILD_DIR)/lib/src/math/ll%.o: OPT_FLAGS :=
$(BUILD_DIR)/lib/src/ldiv.o: OPT_FLAGS := -O2
$(BUILD_DIR)/lib/src/string.o: OPT_FLAGS := -O2
$(BUILD_DIR)/lib/src/gu%.o: OPT_FLAGS := -O3
$(BUILD_DIR)/lib/src/al%.o: OPT_FLAGS := -O3

tools/patch_libultra_math:
	make -C tools

$(BUILD_DIR)/lib/src/math/%.o: lib/src/math/%.c
	$(CC) -c $(CFLAGS) -o $@ $<
	tools/patch_libultra_math $@ || rm $@

$(BUILD_DIR)/%.o: %.c 
	$(CC) -c $(CFLAGS) -o $@ $<


$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -MD $(BUILD_DIR)/$*.d -o $@ $<

$(LIBULTRA): $(ULTRA_O_FILES) 
	$(AR) rcs -o $@ $(ULTRA_O_FILES)

.PHONY: all clean libultra


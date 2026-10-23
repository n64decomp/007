# stan

# Compose full stan names (with pattern Tbg_*_all_p_stanZ)
STAN_NAMES := $(foreach stan,$(STANNAMELIST),Tbg_$(stan)_all_p_stanZ)

# Pattern rules for building .rz files from .bin files
$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.rz: $(OBSEG_DIR)/stan/%.bin
	$(RZ_COMP) $< $@

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.rz: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.bin
	$(RZ_COMP) $< $@

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.bin: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.elf: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.o
	$(LD) -T assets/obseg/stan/Tbg_name_all_p_stan.ld -o $@ $<

# suppress warning 807 for variable length array declarations
$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.o: $(OBSEG_DIR)/stan/%.c
	$(CC) -c $(CFLAGS) -woff 807 -o $@ -O2 $<

# Generate all file targets
STAN_O_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).o)
STAN_BIN_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).bin)
STAN_ELF_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).elf)
STAN_RZ_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).rz)

STAN_BUILD_FILES := $(STAN_O_FILES) $(STAN_BIN_FILES) $(STAN_ELF_FILES) $(STAN_RZ_FILES)

.PHONY: all
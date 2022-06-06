#stan
$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.rz: $(OBSEG_DIR)/stan/%.bin
	$(RZ_COMP) $< $@

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.rz: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.bin
	$(RZ_COMP) $< $@

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.bin: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.elf: $(BUILD_DIR)/$(OBSEG_DIR)/stan/%.o
	$(LD) -T assets/obseg/stan/Tbg_name_all_p_stan.ld -o $@ $<

# suppress warning 807 for variable length array declarations
# cfe: Warning 807: src/game/stan.h, line 136: member cannot be of function or incomplete type.
$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.o: $(OBSEG_DIR)/stan/%.c
	$(CC) -c $(CFLAGS) -woff 807 -o $@ -O2 $<

STAN_NAMES := \
    Tbg_ame_all_p_stanZ \
    Tbg_arch_all_p_stanZ \
    Tbg_arec_all_p_stanZ \
    Tbg_ark_all_p_stanZ \
    Tbg_ash_all_p_stanZ \
    Tbg_azt_all_p_stanZ \
    Tbg_cat_all_p_stanZ \
    Tbg_cave_all_p_stanZ \
    Tbg_crad_all_p_stanZ \
    Tbg_cryp_all_p_stanZ \
    Tbg_dam_all_p_stanZ \
    Tbg_depo_all_p_stanZ \
    Tbg_dest_all_p_stanZ \
    Tbg_dish_all_p_stanZ \
    Tbg_imp_all_p_stanZ \
    Tbg_jun_all_p_stanZ \
    Tbg_len_all_p_stanZ \
    Tbg_oat_all_p_stanZ \
    Tbg_pete_all_p_stanZ \
    Tbg_ref_all_p_stanZ \
    Tbg_run_all_p_stanZ \
    Tbg_sev_all_p_stanZ \
    Tbg_sevb_all_p_stanZ \
    Tbg_sevx_all_p_stanZ \
    Tbg_silo_all_p_stanZ \
    Tbg_stat_all_p_stanZ \
    Tbg_tra_all_p_stanZ

STAN_O_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).o)
STAN_BIN_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).bin)
STAN_ELF_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).elf)
STAN_RZ_FILES := $(foreach name,$(STAN_NAMES),$(BUILD_DIR)/$(OBSEG_DIR)/stan/$(name).rz)

STAN_BUILD_FILES := $(STAN_O_FILES) $(STAN_BIN_FILES) $(STAN_ELF_FILES) $(STAN_RZ_FILES)

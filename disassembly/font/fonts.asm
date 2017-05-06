base origin()
font_rom_start:

//vaddr is unknown
//base $vaddr
//font_vaddr:

insert font_table1_controller_small, "first_font_table_controller_small", (origin() - $002E63F0)
insert font_table2_controller_small, "second_font_table_controller_small", (origin() - $002E6694)
insert font_table1_controller_large, "first_font_table_controller_large", (origin() - $002E88A0)
insert font_table2_controller_large, "second_font_table_controller_large", (origin() - $002E8B44)


font_rom_end:

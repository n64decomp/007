#include "ultra64.h"
#include "game/intro_logos.h"

void alloc_intro_matrices(void) {
    D_8002A7D0 = 0;
    matrix_buffer_rarelogo_0 = allocate_bytes_in_bank(0x80, 4);
    matrix_buffer_gunbarrel_0 = allocate_bytes_in_bank(0x40, 4);
    matrix_buffer_rarelogo_1 = allocate_bytes_in_bank(0x80, 4);
    matrix_buffer_rarelogo_2 = allocate_bytes_in_bank(0x80, 4);
    matrix_buffer_gunbarrel_1 = allocate_bytes_in_bank(0x80, 4);
    matrix_buffer_intro_backdrop = allocate_bytes_in_bank(0x80, 4);
    matrix_buffer_intro_bond = allocate_bytes_in_bank(0x80, 4);
}



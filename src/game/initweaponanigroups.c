#include "ultra64.h"

//uncomment when actor is worked on
//#include "actor.h"
extern s32 get_ptr_allocated_block_for_vertices;

void init_weapon_animation_groups_maybe(void) {
    set_8003608C(&get_ptr_allocated_block_for_vertices);
    somethingwith_weapon_animation_groups();
}

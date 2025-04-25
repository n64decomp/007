#ifndef _OBJECTIVE_H_
#define _OBJECTIVE_H_
#include <ultra64.h>

void something_with_stage_objectives(void);

void set_parent_cur_tag_entry(struct TagObjectRecord *arg0);
void setup_briefing_text_entry_parent(struct setup_objective_text *arg0);
void set_parent_cur_obj_enter_room(struct criteria_roomentered *arg0);
void set_parent_cur_obj_deposited_in_room(struct criteria_deposit *arg0);
void set_parent_cur_obj_photograph(struct criteria_picture *arg0);

#endif

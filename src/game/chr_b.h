#ifndef __CHR_B_H__
#define __CHR_B_H__

#include <ultra64.h>
#include <bondtypes.h>

s32 load_body_head_if_not_loaded(s32 model);
Model *makeonebody(int body, int head, ModelFileHeader *bodyheader, ModelFileHeader *headheader, int sunglasses, Model *model);
Model *setup_chr_instance(int body, int head, ModelFileHeader *body_header, ModelFileHeader *head_header, int sunglasses);

#endif

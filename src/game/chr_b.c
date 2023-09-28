#include <ultra64.h>
#include <bondtypes.h>
#include "cheat_buttons.h"
#include "chr.h"
#include "chr_b.h"
#include "chrobjdata.h"
#include "objecthandler.h"

s32 load_body_head_if_not_loaded(s32 model)
{
    if (c_item_entries[model].header->RootNode == 0)
    {
        fileLoad(c_item_entries[model].header, c_item_entries[model].filename);
        return 1;
    }
    return 0;
}


/**
 * Address 0x7F0232E8 (VERSION_US)
 * Address 0x7F0235D8 (other version)
 * Not a very descriptive name for a function. What it does is load Bond's model or those
 * for spawning guards. It is not used for guards that spawn at level loading.
*/
struct Model *makeonebody(s32 body, s32 head, struct ModelFileHeader *bodyHeader, struct ModelFileHeader *headHeader, s32 sunglasses, struct Model *model)
{
    f32 scale;
    f32 pov;
    s32 opcode;
    struct ModelRoData_HeaderRecord *node;

    scale = c_item_entries[body].scale * 0.10000001f;
    opcode = 0;
    pov = c_item_entries[body].pov;

    if (
#ifdef BUGFIX_R1
    cheatIsActive(CHEAT_DK_MODE) && not_in_us_7F0209EC(body, head)
#else
    cheatIsActive(CHEAT_DK_MODE)
#endif
    )
    {
        scale *= 0.8f;
    }

    if (bodyHeader->RootNode == 0)
    {
        fileLoad(bodyHeader, c_item_entries[body].filename);
    }

    modelCalculateRwDataLen(bodyHeader);

    if ((c_item_entries[body].hasHead == 0) && (head >= 0))
    {
        opcode = &bodyHeader->Switches[4]->Opcode;
        if (opcode != 0)
        {
            if (headHeader->RootNode == 0)
            {
                fileLoad(headHeader, c_item_entries[head].filename);
#ifdef XBLADEBUG
    #error fix XBLADEBUG
      //sprintf("makeonebody: no head attachment for body number %d!\n",lVar3);
#endif
            }

            modelCalculateRwDataLen(headHeader);

            bodyHeader->numRecords += headHeader->numRecords;
        }
    }

    if (model == 0)
    {
        model = get_aircraft_obj_instance_controller(bodyHeader);
    }

#ifdef XBLADEBUG
    #error fix XBLADEBUG
  //
  //        if (*&pMStack0000003c->field_0x2 < pMStack00000024->numRecords) {
  //        assertPrint_8291E690
  //                  (".\\ported\\chrlv.cpp",0xc4,
  //                   "Assertion failed: chrsub->inst.savesize>=bodyobj->savesize");
  //        }
  //
  //
#endif

    if (model != 0)
    {
        modelSetScale(model, scale);
        sub_GAME_7F06CE84(model, pov);

        if ((headHeader != 0) && (c_item_entries[body].hasHead == 0))
        {
            bodyHeader->numRecords -= headHeader->numRecords;
            modelAttachHead(model, opcode, headHeader);

            if ((sunglasses == 0) && ((s32) headHeader->numSwitches > 0))
            {
                if (headHeader->Switches[0] != 0)
                {
                    node = modelGetNodeRwData(model, headHeader->Switches[0]);
                    node->ModelType = 0;
                }
            }
        }
    }

    return model;
}

//sub_GAME_7F0234A8
Model *setup_chr_instance(int body,int head,ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses)
{
  return makeonebody(body,head,body_header,head_header,sunglasses,0x0);
}

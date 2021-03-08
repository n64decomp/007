#include "ultra64.h"
#include "game/indy_commands.h"
#include "game/indy_comms.h"

s32 init_indy_if_not_ready(void) {
    if (indy_ready != 1)
    {
        indy_ready = 1;
        init_indy_if_ready();
    }
}

void nullsub_48(void) {
    return;
}

void init_indy_if_ready(void) {
    if (indy_ready)
    {
        post_indy__res_cmd_initialize_seq();
    }
}

void load_resource_on_indy(u8 *filename, u8 *targetloc)
{
    u8 response1 [8];
    u8 response2 [4];
    u32 size;
  
    if (indy_ready)
    {
        post_indyrescmd_req_filename_size(filename,0x400000);
        response_indyrescmd_1_8_2(response1,response2,(u32)&size,targetloc);
    }
    return;
}

void indy_send_capture_data(u8 *filename, u8 *data, u32 size)
{
    u8 auStack4 [4];
  
    if (indy_ready) 
    {
        post_indyrescmd_send_capture_data(filename, size, (struct indy_resource_entry *)data);
        response_indyrescmd_1_A_2(auStack4);
    }
    return;
}

void indy_load_ramrom_file(u8 *filename, u8 *target, s32 size)
{
    u32 uStack4;
    u32 uStack8;
    u32 uStack12;
  
    if (indy_ready)
    {
        post_indyrescmd_request_ramrom_file(filename,target,size);
        response_indyrescmd_1_10_2(&uStack4,&uStack8,&uStack12);
    }
    return;
}

void check_file_exported(u8 *filename, s32 size, u8 * data)
{
    u8 auStack4 [4];
  
    if (indy_ready)
    {
        post_indyrescmd_game_prof_sendfile(filename,data,size);
        response_indyrescmd_1_E_2(auStack4);
    }
}

u8 * check_file_found_on_indy(u8 *name, s32 *size)
{
    u8 *response;  
    if (!indy_ready) {
        return NULL;
    } else {
        post_indyrescmd_game_printf_send(name);
        response_indyrescmd_1_6_2(&response,size);
    }
    return response;
}

u8 *send_command_string(u8 *cmdstr)
{
    u8 *local_4;  
    if (!indy_ready) {
        return NULL;
    }
    else {
        post_indyrescmd_1_B_2(cmdstr);
        response_indyrescmd_1_C_2(&local_4);
    }
    return local_4;
}

void sub_GAME_7F0D0124(void) {
    if (indy_ready)
    {
        rmon7000CEB0();
    }
}

void send_indy_close_port_cmd(void) {
    send_command_string("sleep 5; /etc/killall ghost gload");
}

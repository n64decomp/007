//D:8003C580
ModelNode player_gait_hdr = {1, &player_gait_obj, 0, 0, 0, &player_gait_pos_hdr_1};
//D:8003C598
ModelNode player_gait_pos_hdr_1 = {2,&player_gait_pos_1, &player_gait_hdr, 0, 0, &player_gait_pos_hdr_2};
//D:8003C5B0
ModelNode player_gait_pos_hdr_2 = {2, &player_gait_pos_2, &player_gait_pos_hdr_1, 0, 0, &player_gait_pos_hdr_3};
//D:8003C5C8
ModelNode player_gait_pos_hdr_3 = {2, &player_gait_pos_3, &player_gait_pos_hdr_2, 0, 0, 0};
//D:8003C5E0
ModelNode_HeaderRecord player_gait_obj = {1, &player_gait_pos_hdr_1, 0, 0, 0, 0};
//D:8003C5F0
ModelNode_GroupRecord player_gait_pos_1 = {{0.0, 0.0, 0.0}, 0x0001, 0x0002, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_2, 0};
//D:8003C60C
ModelNode_GroupRecord player_gait_pos_2 = {{1.177982, 41.14437, 0.0}, 0x0002, 0x0003, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_3, 0};
//D:8003C628
ModelNode_GroupRecord player_gait_pos_3 = {{-2.576027, 480.42902, 0.0}, 0x0003, 0x0000, 0xFFFF, 0xFFFF, NULL, 0};

//FIXME File split likely
//D:8003C644
s32 PAD_8003C644 = 0;
//D:8003C648
s32 PAD_8003C648 = 0;
//D:8003C64C
s32 PAD_8003C64C = 0;

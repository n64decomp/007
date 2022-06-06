#ifdef DEBUG
char* weapon_gun_revolver_JointNames[] = {
    "SKEL_TOP",
    "SKEL_MUZZLE",
    "SKEL_FLASH",
    "SKEL_DRUM",
    "SKEL_HAMMER",
    "SKEL_FINGER",
    ""};
#endif

//D:8003C740
ModelJoint JOINTLIST(gun_revolver)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};

//D:8003C76C
MODELSKELETON(gun_revolver, 7, 21)

//D:8003C778
s32 PAD_8003C778 = 0;
//D:8003C77C
s32 PAD_8003C77C = 0;

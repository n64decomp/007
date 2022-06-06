#ifdef DEBUG
char* player_gait_object_JointNames[] = {
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_BACK",
    "SKEL_LF_HIP",
    "SKEL_RT_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_SHOULDER",
    "SKEL_NECK",
    "SKEL_RT_KNEE",
    "SKEL_RT_SHOULDER",
    "SKEL_LF_ANKLE",
    "SKEL_LF_ELBOW",
    "SKEL_RT_ANKLE",
    "SKEL_RT_ELBOW",
    "SKEL_LF_WRIST",
    "SKEL_RT_WRIST"
};
#endif
//D:8003C510
ModelJoint JOINTLIST(player_gait_object)[] = {
    {0x0401, 0x0000, 0x0000}, //"SKEL_POSITION"
    {0x0002, 0x0000, 0x0000}, //"SKEL_BASE"
    {0x0002, 0x0003, 0x0003}, //"SKEL_BACK"
    {0x0002, 0x0006, 0x0006}, //"SKEL_LF_HIP"
    {0x0002, 0x0009, 0x000C}, //"SKEL_RT_HIP"
    {0x0002, 0x000C, 0x0009}, //"SKEL_LF_KNEE"
    {0x0002, 0x000F, 0x0012}, //"SKEL_LF_SHOULDER"
    {0x0002, 0x0012, 0x000F}, //"SKEL_NECK"
    {0x0002, 0x0015, 0x0018}, //"SKEL_RT_KNEE"
    {0x0002, 0x0018, 0x0015}, //"SKEL_RT_SHOULDER"
    {0x0002, 0x001B, 0x001E}, //"SKEL_LF_ANKLE"
    {0x0002, 0x001E, 0x001B}, //"SKEL_LF_ELBOW"
    {0x0002, 0x0021, 0x0024}, //"SKEL_RT_ANKLE"
    {0x0002, 0x0024, 0x0021}, //"SKEL_RT_ELBOW"
    {0x0002, 0x0027, 0x002A}, //"SKEL_LF_WRIST"
    {0x0002, 0x002A, 0x0027}  //"SKEL_RT_WRIST"
};
//D:8003C570
MODELSKELETON(player_gait_object, 16, 45)

//FIXME File split likely
//D:8003C57C
s32 PAD_8003C57C = 0;

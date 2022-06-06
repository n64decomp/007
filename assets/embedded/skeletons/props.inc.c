#ifdef DEBUG
char* prop_cctv_related_JointNames[] = {
    "SKEL_TOP",
    "SKEL_CAM" };
#endif
//D:8003A050
ModelJoint JOINTLIST(cctv)[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
MODELSKELETON(cctv, 2, 6)


//No Joint Nmaes
//D:8003A068
ModelJoint JOINTLIST(console_one_screen)[1] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A070
MODELSKELETON(console_one_screen, 1, 3)


//No Joint Nmaes
//D:8003A07C
ModelJoint JOINTLIST(console_four_screen)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A084
MODELSKELETON(console_four_screen, 1, 3)

#ifdef DEBUG
char* prop_tv_holder_related_JointNames[] = {
    "SKEL_TOP",
    "SKEL_TV1",
    "SKEL_TV2",
    "SKEL_TV3",
    "SKEL_TV4" };
#endif
//D:8003A090
ModelJoint JOINTLIST(tv_holder)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0B0
MODELSKELETON(tv_holder, 5, 0xF)


#ifdef DEBUG
char* prop_rotating_stuff_related_JointNames[] = {
    "SKEL_TOP",
    "SKEL_YROT",
    "SKEL_XROT",
    "SKEL_BARREL",
    "SKEL_CARTRIDGE",
    NULL };
#endif
#if 0
char* GroundGun_JointNames[] = {
    "SKEL_TOP",
    "SKEL_YROT",
    "SKEL_XROT",
    "SKEL_BARREL",
    "SKEL_BAR2",
    NULL };
#endif
//D:8003A0BC
ModelJoint JOINTLIST(rotating_stuff)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
MODELSKELETON(rotating_stuff, 6, 0x12)


#ifdef DEBUG
char* prop_eyelid_door_related_JointNames[] = {
    "SKEL_TOP",
    "SKEL_UPPER",
    "SKEL_LOWER" };
#endif
//D:8003A0EC
ModelJoint JOINTLIST(eyelid_door)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
MODELSKELETON(eyelid_door, 3, 9)


#ifdef DEBUG
char* prop_iris_door_related_JointNames[] = {
    "SKEL_TOP",
    "SKEL_OUT1",
    "SKEL_IN1",
    "SKEL_OUT2",
    "SKEL_IN2",
    "SKEL_OUT3",
    "SKEL_IN3",
    "SKEL_OUT4",
    "SKEL_IN4",
    "SKEL_OUT5",
    "SKEL_IN5",
    "SKEL_OUT6",
    "SKEL_IN6" };
#endif
//D:8003A10C
ModelJoint JOINTLIST(iris_door)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012},
    {0x0002, 0x0015, 0x0015},
    {0x0002, 0x0018, 0x0018},
    {0x0002, 0x001B, 0x001B},
    {0x0002, 0x001E, 0x001E},
    {0x0002, 0x0021, 0x0021},
    {0x0002, 0x0024, 0x0024}
};
//D:8003A15C
MODELSKELETON(iris_door, 0xD, 0x27)


//NoJointNames
//D:8003A168
ModelJoint JOINTLIST(walletbond)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A170
MODELSKELETON(walletbond, 1, 3)


#ifdef DEBUG
char* prop_car_related_JointNames[] = {
    "base",
    "wheel1",
    "wheel2",
    "wheel3",
    "wheel4" };
#endif
//D:8003A17C
ModelJoint JOINTLIST(car)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
MODELSKELETON(car, 5, 0xF)

#ifdef DEBUG
char* prop_flying_related_JointNames[] = {
    "SKEL_POSITION",
    "SKEL_TOP",
    "SKEL_ROTOR",
    "SKEL_TAILROTOR",
    "SKEL_GUN" };
#endif
//D:8003A1A8
ModelJoint JOINTLIST(flying)[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C8
MODELSKELETON(flying, 5, 3)


//No Joint Names
//D:8003A1D4
ModelJoint JOINTLIST(door)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DC
MODELSKELETON(door, 1, 3)


#ifdef DEBUG
char* TankSkeleton_JointNames[] = {
    "SKEL_TOP",
    "SKEL_TURRET",
    "SKEL_HATCH",
    "SKEL_GUN",
    "SKEL_MUZZLE" };
#endif
//D:8003A1E8
ModelJoint JOINTLIST(tank)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A208
MODELSKELETON(tank, 5, 0xF)


//No Joint Names
//D:8003A214
ModelJoint JOINTLIST(hat)[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21C
MODELSKELETON(hat, 1, 0)

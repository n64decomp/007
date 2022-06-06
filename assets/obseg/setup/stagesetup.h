// #ifndef _STAGESETUP_H_
// #define _STAGESETUP_H_

// #include <bondtypes.h>

// #define PAD3D_START 10000
// #define PADADV(PAD) (PAD + PAD3D_START)

// typedef u16 PAD;
// typedef u16 PAD3D;


// struct bbox
// {
//     float xmin;
//     float xmax;
//     float ymin;
//     float ymax;
//     float zmin;
//     float zmax;
// };

// struct pad
// {
//     coord3d pos;
//     coord3d up;
//     coord3d look;
//     char *plink;
//     int unk;
// };

// struct pad3d
// {
//     coord3d pos;
//     coord3d up;
//     coord3d look;
//     char *plink;
//     int unk;
//     struct bbox bbox;
// };

// struct s_pathTbl {
//     s16 pathtbl;
//     s16 field_0x2;
//     u32 *field_0x4; //
//     s16 field_0x8;
//     s16 field_0xa;
//     s16 field_0xc;
//     s16 field_0xe;
// };

// struct s_pathLink {
//     void *pathlink;
//     void *field_0x4;
//     void *field_0x8;
// };

// struct s_pathSet {
//     void *field_0x0;
//     u8 field_0x4;
//     u8 field_0x5;
//     u8 field_0x6;
//     u8 field_0x7;
// };

// struct ailist {
//     u32 (*script)[];
//     s32 id;
// };

// struct stagesetup {
//     struct s_pathTbl *pathtbl;
//     struct s_pathLink *pathlink;
//     s32 *intro;
//     s32 *objlist;
//     struct s_pathSet *paths;
//     struct ailist *ailists;
//     struct pad *padlist;
//     struct pad3d *pad3dlist;
//     char *padnames;
//     char *pad3dnames;
// };

// #define _mkshort(a, b) ((a << 8) | (b & 0xff))
// #define _mkword(a, b) ((a << 16) | (b & 0xffff))

// #define _generic_object(scale, state, type, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _mkword(scale, _mkshort(state, type)), \
//     _mkword(objectID, presetID), \
//     flags1, flags2, \
//     ptrPOSData, ptrObjInstanceController, \
//     u18, u1c, u20, u24, \
//     u28, u2c, u30, u34, \
//     u38, u3c, u40, u44, \
//     u48, u4c, u50, u54, \
//     xPOS, yPOS, zPOS, bitflags, \
//     ptrCollisionblock, u6c, u70, \
//     _mkword(health, maxhealth), \
//     u78, u7c

// #define door(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, linkedtodoor, travel_distance, walkthrough_distance, acceleration, rate, maxspeed, opentechnique_a, opentechnique_b, u9c, u9d, u9e, locked, time_open, sound, ua8, uac, ub0, ub4, ub8, ubc, uc0, uc4, uc8, ptr_doorNotClearVtxBuffer, ud0, ud4, ud8, udc, ue0, ue4, ue8, uec, uf0, uf4, uf8, ufc) \
//     _generic_object(scale, state, 0x01, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     linkedtodoor, \
//     travel_distance, walkthrough_distance, \
//     acceleration, rate, maxspeed, \
//     _mkword(opentechnique_a, opentechnique_b), \
//     _mkword(_mkshort(u9c, u9d), _mkshort(u9e, locked)), \
//     time_open, sound, \
//     ua8, uac, ub0, ub4, \
//     ub8, ubc, uc0, uc4, \
//     uc8, ptr_doorNotClearVtxBuffer, ud0, ud4, \
//     ud8, udc, ue0, ue4, \
//     ue8, uec, uf0, uf4, \
//     uf8, ufc,

// #define door_scale(modifier) \
//     0x2, modifier,

// #define standard(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _generic_object(scale, state, 0x3, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c),

// #define key(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, key) \
//     _generic_object(scale, state, 0x4, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     key,

// #define alarm(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _generic_object(scale, state, 0x5, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c),

// #define surveillencecam() \
//     _TODO(0x6)

// #define ammoclip(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, ammotype) \
//     _generic_object(scale, state, 0x7, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     ammotype,

// #define weapon(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, gun_pickup, linked_item, timer, ptr_linkeditem) \
//     _generic_object(scale, state, 0x8, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     _mkword(_mkshort(gun_pickup, linked_item), timer), \
//     ptr_linkeditem,

// #define guard(scale, state, type, ID, spawnpreset, bodyID, action_path_assignment, preset_to_trigger, u10, health, reactiontime, head, ptr_runtimeguarddata) \
//     _mkword(scale, _mkshort(state, 0x9), \
//     _mkword(ID, spawnpreset), \
//     _mkword(bodyID, action_path_assignment), \
//     preset_to_trigger, \
//     _mkword(u10, health), \
//     _mkword(reactiontime, head), \
//     ptr_runtimeguarddata,


// #define single_monitor(size, state, u4, u8, uc, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, health, maxhealth, u78, ptrAniRoutine, curNumCMDSfromStartRotation, loopcounteer, imgnum_or_ptrheader, rotation, curHZoom, curHZoomTime, finalHZoomTime, initialHZoom, finalHZoom, curVZoom, curVZoomTime, finalVZoomTime, initialVZoom, finalVZoom, curHPos, curHScrollTime, finalHScrollTime, initialHPos, finalHPos, curVPos, curVScrollTime, finalVScrollTime, initialVPos, finalVPos, curRed, initialRed, finalRed, curGreen, initialGreen, finalGreen, curBlue, initialBlue, finalBlue, curAlpha, initialAlpha, finalAlpha, curColorTransitionTime, finalColorTransitionTime, backwardMonLink, forwardMonLink, animationnum) \
//     _mkword(size, _mkshort(state, 0xA)), \
//     u4, u8, uc, u10, \
//     u14, u18, u1c, u20, \
//     u24, u28, u2c, u30, \
//     u34, u38, u3c, u40, \
//     u44, u48, u4c, u50, \
//     u54, u58, u5c, u60, \
//     u64, u68, u6c, u70, \
//     _mkword(health, maxhealth), \
//     u78, ptrAniRoutine, \
//     curNumCMDSfromStartRotation, loopcounteer, \
//     imgnum_or_ptrheader, rotation, \
//     curHZoom, curHZoomTime, finalHZoomTime, initialHZoom, finalHZoom, \
//     curVZoom, curVZoomTime, finalVZoomTime, initialVZoom, finalVZoom, \
//     curHPos, curHScrollTime, finalHScrollTime, initialHPos, finalHPos, \
//     curVPos, curVScrollTime, finalVScrollTime, initialVPos, finalVPos, \
//     _mkword(_mkshort(curRed, initialRed), _mkshort(finalRed, curGreen)), \
//     _mkword(_mkshort(initialGreen, finalGreen), _mkshort(curBlue, initialBlue)), \
//     _mkword(_mkshort(finalBlue, curAlpha), _mkshort(initialAlpha, finalAlpha)), \
//     curColorTransitionTime, finalColorTransitionTime, \
//     backwardMonLink, forwardMonLink, \
//     animationnum,

// #define multi_monitor() \
//     _TODO(0xB)

// #define hanging_monitor() \
//     _TODO(0xC)

// #define autogun() \
//     _TODO(0xD)

// #define linkpickups() \
//     _TODO(0xE)

// #define unknownF() \
//     _TODO(0xF)

// #define unknown10() \
//     _TODO(0x10)

// #define hat(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _generic_object(scale, state, 0x11, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c),

// #define setguardattribute(guardID, attribute) \
//     0x12, guardID, attribute,

// #define switch(numAwayForControlling, numAwayForControlled, field_0xc) \
//     0x13, numAwayForControlling, numAwayForControlled, field_0xc,

// #define ammobox(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, ammo_9mm, ammo_9mm_2, ammo_rifle, ammo_shotgun, ammo_hgrenade, ammo_rockets, ammo_remote, ammo_prox, ammo_timed, ammo_throwing, ammo_glaunch, ammo_magnum, ammo_golden) \
//     _generic_object(scale, state, 0x14, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     ammo_9mm, ammo_9mm_2, ammo_rifle, ammo_shotgun, ammo_hgrenade, ammo_rockets, ammo_remote, ammo_prox, ammo_timed, ammo_throwing, ammo_glaunch, ammo_magnum, ammo_golden,

// #define bodyarmor(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, armor_strength, armor_percent) \
//     _generic_object(scale, state, 0x15, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     armor_strength, armor_percent,

// #define tag(IDnum, numobjects_away, field_0x8, field_0xc) \
//     0x16, IDnum, numobjects_away, field_0x8, field_0xc,

// #define mission_objective(objectivenum, textID, mindifficulty) \
//     0x17, objectivenum, textID, mindifficulty,

// #define endobjective() \
//     0x18,

// #define destroyobject(objectID) \
//     0x19, objectID,

// #define completeIfTrue(testval) \
//     0x1A, testval,

// #define failIfTrue(testval) \
//     0x1B, testVal,

// #define    collectobject(objecttagID) \
//     0x1C, objecttagID,

// #define    depositobject(objecttagID) \
//     0x1D, objecttagID,

// #define photographobject(objecttagID) \
//     0x1E, objecttagID, 0x0, 0x0,

// #define null() \
//     0x1F,

// #define enterroom(presetinroom) \
//     0x20, presetinroom, 0x0, 0x0,

// #define    depositobjectinroom(itemID,presetinroom) \
//     0x21, itemID, presetinroom, 0x0, 0x0,

// #define    copy_item() \
//     0x22,

// #define watch_objective(menuOption, textID) \
//     0x23, menuOption, textID, 0x0,

// #define gas(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _generic_object(scale, state, 0x24, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c),

// #define renamefunction(numtargetobjectsaway, invValToAlter, watchMainTop, watchMainBottom, invSelName, onDefaultPickup, interactTextID, field_0x20, field_0x24) \
//     0x25, numtargetobjectsaway, invValToAlter, watchMainTop, watchMainBottom, invSelName, onDefaultPickup, interactTextID, field_0x20, field_0x24,

// #define    lock_door(lockedptr, lockptr) \
//     0x26, lockedptr, lockptr, 0x0,

// #define wheeledvehicle() \
//     _TODO(0x27),

// #define aircraft() \
//     _TODO(0x28),

// #define unknown29() \
//     0x29,

// #define glass(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c) \
//     _generic_object(scale, state, 0x2A, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c),

// #define safe() \
//     _TODO(0x2B),

// #define safeitem(objectptr, safeptr, safedoorptr) \
//     0x2C, objectptr, safeptr, safedoorptr, 0x0,

// #define tank() \
//     _TODO(0x2D),

// #define cutscene_coord(xcoord, ycoord, zcoord, latrot, vertrot, illum_preset) \
//     0x2E, xcoord, ycoord, zcoord, latrot, vertrot, illum_preset,

// #define tintedglass(scale, state, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c, dist_fullillum, dist_vis, field_0x88, field_0x8c, field_0x90) \
//     _generic_object(scale, state, 0x2A, objectID, presetID, flags1, flags2, ptrPOSData, ptrObjInstanceController, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, xPOS, yPOS, zPOS, bitflags, ptrCollisionblock, u6c, u70, health, maxhealth, u78, u7c), \
//     dist_fullillum, dist_vis, field_0x88, field_0x8c, field_0x90,

// #define endprops() \
//     0x30,
// //endprops

// //introblock
// #define spawnpoint(u4, u8) \
//     0x0, u4, u8,

// #define startweapon(rightgun, leftgun, setnum) \
//     0x1, rightgun, leftgun, setnum,

// #define startammo(type, qty, set) \
//     0x2, type, qty, set,

// #define swirlintrocam(u1, x, y, z, l, r, u2) \
//     0x3, u1, x, y, z, l, r, u2,

// #define introcam(aniNum) \
//     0x4, aniNum,

// #define cuff(cuffID) \
//     0x5, cuffID,

// #define fixedcam(x, y, z, l, v, u1, t1, t2, c) \
//     0x6, x, y, z, l, v, u1, t1, t2, c,

// #define watchtime(h, m) \
//     0x7, h, m,

// #define credits() \
//     0x8,

// #define endintro() \
//     0x9
// //endintroblock



// #endif

#ifdef DEBUG
char* weapon_gun_kf7_SwitchNames[] = {
    "CARTRIDGE",
    "SW_FLASH",
    "FLASH",
    "MUZZLE",
    "EXTRAFLASH" };
#endif
#ifdef DEBUG
char* weapon_gun_revolver_SwitchNames[] = {
    "CARTRIDGE",
    "SW_FLASH",
    "FLASH",
    "MUZZLE",
    "DRUM",
    "HAMMER",
    "FINGER",
    "SLIDE",
    "SW_HANDOFF1",
    "SW_HANDOFF2",
    "SW_HANDOFF3",
    "SW_HANDOFF4",
    "SW_HANDOFF5",
    "SW_HANDOFF6",
    "SW_GUNOFF1",
    "SW_GUNOFF2",
    "GFXHIT_SCREEN",
    "SW_SCREEN",
    "SW_cart1",
    "SW_cart2",
    "SW_cart3",
    "SW_cart4",
    "SW_cart5",
    "SW_case1",
    "SW_case2",
    "SW_case3",
    "SW_case4",
    "SW_case5",
    "2PT_FINGER",
    "SW_BOILER",
    "SW_DINNER",
    "SW_CONNERY",
    "SW_SUIT",
    "SW_TIMBER",
    "SW_SNOW",
    "SW_HANDOFF7" };
#endif
//D:8003C7C0 
//tank
//token
MODELFILEHEADER(wppk, 0, &SKELETON(standard_gun), 0, 0x24, 6, 293.60767, 0, 0xC)
MODELFILEHEADER(wppksil, 0, &SKELETON(standard_gun), 0, 0x24, 6, 438.66476, 0, 0xC)
MODELFILEHEADER(tt33, 0, &SKELETON(standard_gun), 0, 0x24, 6, 438.16788, 0, 0xF)
MODELFILEHEADER(skorpion, 0, &SKELETON(standard_gun), 0, 0x24, 4, 390.40039, 0, 0xC)
MODELFILEHEADER(ak47, 0, &SKELETON(standard_gun), 0, 0x24, 4, 941.9339, 0, 0x12)
MODELFILEHEADER(uzi, 0, &SKELETON(gun_kf7), 0, 0x24, 5, 436.95404, 0, 0xC)
MODELFILEHEADER(mp5k, 0, &SKELETON(standard_gun), 0, 0x24, 4, 499.24536, 0, 9)
MODELFILEHEADER(mp5ksil, 0, &SKELETON(standard_gun), 0, 0x24, 4, 655.97717, 0, 9)
MODELFILEHEADER(m16, 0, &SKELETON(standard_gun), 0, 0x24, 4, 1096.2413, 0, 8)
MODELFILEHEADER(fnp90, 0, &SKELETON(standard_gun), 0, 0x24, 4, 460.81909, 0, 0xA)
MODELFILEHEADER(G8003C900, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 238.62167, 0, 4)
MODELFILEHEADER(ruger, 0, &SKELETON(gun_revolver), 0, 0x24, 6, 553.44312, 0, 0xE)
MODELFILEHEADER(goldengun, 0, &SKELETON(standard_gun), 0, 0x24, 5, 384.92172, 0, 0xB)
MODELFILEHEADER(shotgun, 0, &SKELETON(standard_gun), 0, 0x1C, 4, 919.33038, 0, 0xD)
MODELFILEHEADER(autoshot, 0, &SKELETON(standard_gun), 0, 0x24, 4, 840.15125, 0, 0x10)
MODELFILEHEADER(grenadelaunch, 0, &SKELETON(gun_revolver), 0, 0x24, 5, 768.33496, 0, 0xF)
MODELFILEHEADER(spectre, 0, &SKELETON(standard_gun), 0, 0x24, 4, 598.42865, 0, 0xB)
MODELFILEHEADER(laser, 0, &SKELETON(standard_gun), 0, 0x24, 3, 442.81848, 0, 0xD)
MODELFILEHEADER(rocketlaunch, 0, &SKELETON(standard_gun), 0, 0x24, 3, 566.51208, 0, 0xA)
#include <assets/obseg/gun/knife/modelFileHeader.inc.c>
MODELFILEHEADER(throwknife, 0, &SKELETON(standard_gun), 0, 0x24, 3, 373.31387, 0, 9)
MODELFILEHEADER(taser, 0, &SKELETON(standard_gun), 0, 0x23, 3, 182.78622, 0, 0x11)
MODELFILEHEADER(remotemine, 0, &SKELETON(standard_gun), 0, 0x23, 3, 50.999378, 0, 3)
MODELFILEHEADER(proximitymine, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 51.00029, 0, 3)
MODELFILEHEADER(timedmine, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 49.368877, 0, 4)
MODELFILEHEADER(trigger, 0, &SKELETON(standard_gun), 0, 0x24, 4, 283.9006, 0, 0x16)
MODELFILEHEADER(grenade, 0, &SKELETON(standard_gun), 0, 0x24, 3, 427.27081, 0, 5)
#include <assets/obseg/gun/fist/modelFileHeader.inc.c>
MODELFILEHEADER(sniperrifle, 0, &SKELETON(standard_gun), 0, 0x24, 4, 808.03253, 0, 7)
MODELFILEHEADER(cartridge, 0, &SKELETON(gun_unassigned), 0, 0, 1, 14.128822, 0, 2)
MODELFILEHEADER(cartrifle, 0, &SKELETON(gun_unassigned), 0, 0, 1, 30.122747, 0, 2)
MODELFILEHEADER(cartblue, 0, &SKELETON(gun_unassigned), 0, 0, 1, 30.122747, 0, 2)
MODELFILEHEADER(cartshell, 0, &SKELETON(gun_unassigned), 0, 0, 1, 29.8451, 0, 2)
MODELFILEHEADER(joypad, 0, &SKELETON(g_weapon), 0, 0xE, 0xD, 523.96826, 0, 4)
MODELFILEHEADER(G8003CC00, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(G8003CC20, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(bombcase, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 116.11074, 0, 6)
MODELFILEHEADER(flarepistol, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(pitongun, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(G8003CCA0, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(silverwppk, 0, &SKELETON(standard_gun), 0, 0x24, 6, 293.60767, 0, 0xB)
MODELFILEHEADER(goldwppk, 0, &SKELETON(standard_gun), 0, 0x24, 6, 293.60767, 0, 0xB)
MODELFILEHEADER(G8003CD00, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(bungee, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(doordecoder, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 60.850407, 0, 0x10)
MODELFILEHEADER(bombdefuser, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 84.370705, 0, 0xC)
MODELFILEHEADER(bugdetector, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(safecrackercase, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 116.11074, 0, 6)
MODELFILEHEADER(camera, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 52.775627, 0, 0xB)
MODELFILEHEADER(lockexploder, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(doorexploder, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(keyanalysercase, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 116.11074, 0, 6)
MODELFILEHEADER(weaponcase, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 116.11074, 0, 6)
MODELFILEHEADER(keycard, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 123.088844, 0, 2)
MODELFILEHEADER(keyyale, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 414.25156, 0, 1)
MODELFILEHEADER(keybolt, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 759.26581, 0, 1)
MODELFILEHEADER(bug, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 106.2163, 0, 6)
MODELFILEHEADER(microcamera, 0, &SKELETON(standard_gun), 0, 0x23, 3, 70.039436, 0, 7)
MODELFILEHEADER(explosivefloppy, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 60.902443, 0, 5)
MODELFILEHEADER(goldeneyekey, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 98.987083, 0, 5)
MODELFILEHEADER(polarizedglasses, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 53.776386, 0, 2)
MODELFILEHEADER(creditcard, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(darkglasses, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(watchidentifier, 0, &SKELETON(standard_gun), 0, 0x23, 3, 384.9288, 0, 9)
MODELFILEHEADER(watchcommunicator, 0, &SKELETON(standard_gun), 0, 0x23, 3, 384.9288, 0, 9)
MODELFILEHEADER(watchlaser, 0, &SKELETON(standard_gun), 0, 0x24, 4, 283.9006, 0, 0x16)
MODELFILEHEADER(watchgeigercounter, 0, &SKELETON(standard_gun), 0, 0x23, 3, 384.9288, 0, 9)
MODELFILEHEADER(watchmagnetrepel, 0, &SKELETON(standard_gun), 0, 0x23, 3, 384.9288, 0, 9)
MODELFILEHEADER(watchmagnetattract, 0, &SKELETON(standard_gun), 0, 0x1D, 3, 384.9288, 0, 9)
MODELFILEHEADER(gaskeyring, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 111.59859, 0, 9)
MODELFILEHEADER(datathief, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 119.78231, 0, 3)
MODELFILEHEADER(briefcase, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 116.11074, 0, 6)
MODELFILEHEADER(blackbox, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 128.31796, 0, 5)
MODELFILEHEADER(plastique, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 255.35242, 0, 3)
MODELFILEHEADER(videotape, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 122.69632, 0, 9)
MODELFILEHEADER(clipboard, 0, &SKELETON(standard_gun), 0, 0x23, 3, 190.41742, 0, 3)
MODELFILEHEADER(stafflist, 0, &SKELETON(standard_gun), 0, 0x23, 3, 215.17534, 0, 4)
MODELFILEHEADER(dossierred, 0, &SKELETON(standard_gun), 0, 0x23, 3, 183.54231, 0, 4)
MODELFILEHEADER(audiotape, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 97.531075, 0, 9)
MODELFILEHEADER(dattape, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 79.868584, 0, 4)
MODELFILEHEADER(plans, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 81.950996, 0, 5)
MODELFILEHEADER(spyfile, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(blueprints, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 125.3834, 0, 4)
MODELFILEHEADER(circuitboard, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 138.90285, 0, 3)
MODELFILEHEADER(map, 0, &SKELETON(standard_gun), 0, 0x23, 3, 125.3834, 0, 4)
MODELFILEHEADER(spooltape, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(microfilm, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(microcode, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(lectre, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(money, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(goldbar, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)
MODELFILEHEADER(heroin, 0, &SKELETON(standard_gun), 0, 0x1C, 3, 134.8334, 0, 2)

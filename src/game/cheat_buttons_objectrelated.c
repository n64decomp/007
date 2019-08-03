#include "ultra64.h"
#include "game/cheat_buttons_objectrelated.h"
// bss
char off_CODE_bss_80079E30[0x4C];

// data
//D:80037070
u32 dword_D_80037070[] = {0x14002100, 0x10201, 0x3010104};
//D:8003707C
u32 dword_D_8003707C[] = {0x2110301, 0x11040000};
//D:80037084
u32 dword_D_80037084[] = {
    0x2010330, 0xFD112F06, 0x1010206, 0x32073E0D, 0x3F0E4610, 0x3A0D3B0D, 0xB033335, 0x1030600,
    0x205FD00, 0x3020301, 0x1021033, 0x357F0706, 0x205FD, 0xA0207, 0x6000205, 0xFD000602, 0xD060002,
    0x5FD0008, 0x20E0600, 0x205FD00, 0xB021105, 0xFD000104
};
//D:800370DC
u32 dword_D_800370DC[] = {
    0x33353203, 0x0A009A00, 0x0000C118, 0x10000202, 0x03356403, 0x0A009B00, 0x00012618,
    0x10000202, 0x03359603, 0x0A009C00, 0x0000B718, 0x10000202, 0x0335C803, 0x0A009D00,
    0x00007B18, 0x10000202, 0x0335FA03, 0x0A009E00, 0x00003818, 0x10000202, 0x030A009F,
    0x00000089, 0x18100002, 0x02020704
};
//D:8003713C
u32 dword_D_8003713C[] = {
    0x33353C03, 0xA00AC00, 0x4500, 0x10000202, 0x3357803, 0xA00AD00, 0x4A00,
    0x10000202, 0x335B403, 0xA00AE00, 0x4F00, 0x10000202, 0x30A00AF, 0x59,
    0x100002, 0x2020704
};
//D:8003717C
u32 dword_D_8003717C[] = {
    0x201032F, 0x6010102, 0x632073E, 0xD46103A, 0xD3B0D01, 0x1021033, 0x357F0706,
    0x205FD, 0xA0207, 0x6000205, 0xFD000602, 0xD060002, 0x5FD0008, 0x4000000
};
//D:800371B4
u32 dword_D_800371B4[] = {
    0x96010333, 0x3520030C, 0x94010702, 0x394011A, 0x2020333, 0x350A0313,
    0x2020333, 0x350A030F, 0x2020333, 0x3519030E, 0x2020333, 0x35320310,
    0x2020333, 0x35400311, 0x2020335, 0x7F031202, 0x2033335, 0x7F0B1400,
    0x1000002, 0x20B1500, 0x1000002, 0x2020704
};
//D:8003720C
u32 dword_D_8003720C[] = {
    0x94012801, 0x7020103, 0x2F063207, 0x1010207, 0x5FD0006, 0x2060704
};
//D:80037224
u32 dword_D_80037224[] = {
    0x9401410E, 0x5FD0008, 0x20E31F9, 0xE05FD00, 0x2020EC1, 0xFD000C03, 0x5FD0008,
    0x20305FD, 0x20400
};
//D:80037248
u32 dword_D_80037248[] = {0x6000205, 0xFD000804};
//D:80037250
u32 dword_D_80037250[] = {
    0x2010332, 0x73E0D3F, 0xD460D3A, 0xD3B0D01, 0x1020706, 0x205FD, 0x6020D,
    0x6000205, 0xFD000802, 0xE060002, 0x5FD000B, 0x4000000
};
//D:80037280
u32 dword_D_80037280[] = {
    0x201032F, 0x6010102, 0x6320F7B, 0x103F10, 0x3A103B10, 0x1010210, 0x79000F0D,
    0x204032F, 0xF010402, 0xF1C2328, 0x203032F, 0x2010302, 0x24EFD00, 0xA232802,
    0x24232805, 0x20205, 0x32F0201, 0x5020206, 0x205FD, 0x80400
};
//D:800372D0
u32 dword_D_800372D0[] = {
    0xD020103, 0x2F020101, 0x20205FD, 0x80400
};
//D:800372E0
u32 dword_D_800372E0[] = {
    0x228281B, 0xAD6E6F20, 0x676F210A, 0x21B03, 0x3C062F02, 0x11B0201, 0x378062D,
    0x9F000000, 0x102F022D, 0x2F064C00, 0xC8030101, 0x2030128, 0x2063C03,
    0x20224, 0x34B0032, 0x32F0301, 0x2802039F, 0x10, 0x2F022B33, 0x350A031A,
    0x2020335, 0x32030E02, 0x203353C, 0x3130202, 0x3355003, 0x13020203, 0x35640311,
    0x2020335, 0x96031202, 0x20335C8, 0x3140001, 0x202, 0x3150001, 0x202,
    0x23C0300, 0x1B021B03, 0x3335A003, 0x1C0203, 0x3010102, 0x1CAE281D, 0x21D032F,
    0x3B40000, 0x3C03011D, 0x20308AD, 0x77616974, 0xA009504, 0x3335A003,
    0x94040203, 0xAE021E03, 0x3C034603, 0x3B30002, 0x58049604, 0x5012802,
    0x5011C02, 0x4011E02, 0x3010102, 0x2F780603, 0x9E000000, 0x10020301,
    0x2B040000
};
//D:800373D0
u32 dword_D_800373D0[] = {0xAE021B03, 0xB400003C, 0x3011B02, 0x3070400};
//D:800373E0
u32 dword_D_800373E0[] = {0xD205FD00, 0x1040000};
//D:800373E8
u32 dword_D_800373E8[] = {
    0x91289332, 0x2031700, 0x1000003, 0x203AE02, 0x1B03B400, 0x140301, 0x1B02030A,
    0x420000, 0x140410, 0x21C032F, 0x3011C02, 0x3BF00CD, 0x6000000, 0x30203,
    0x14002100, 0x30203, 0x16000100, 0x30203, 0x21E032F, 0x3011E02, 0x3060002,
    0x5FD0008, 0x4000000
};

//D:80037444
u32 dword_D_80037444[] = {0x23FD05FD, 0x10400};

//D:8003744C
struct struct_13 D_8003744C[] = {
    {dword_D_80037070, 0},
    {dword_D_8003707C, 1},
    {dword_D_80037084, 2},
    {dword_D_800370DC, 3},
    {dword_D_8003713C, 4},
    {dword_D_8003717C, 5},
    {dword_D_800371B4, 6},
    {dword_D_80037250, 7},
    {dword_D_8003720C, 8},
    {dword_D_80037280, 9},
    {dword_D_800372D0, 0xA},
    {dword_D_80037224, 0xB},
    {dword_D_80037248, 0xC},
    {dword_D_800372E0, 0xD},
    {dword_D_800373D0, 0xE},
    {dword_D_800373E0, 0xF},
    {dword_D_800373E8, 0x10},
    {dword_D_80037444, 0x11}
};
//D:800374DC
u32 D_800374DC[] = {0,0};

//D:800374E4
char * setup_text_pointers[] = {0,0,0,0,0,0,0,0,0,"UsetupsevbunkerZ",0,0,0,0,0,0,0,0,0,0,"UsetupsiloZ",
    "UsetupsevbunkerZ","UsetupstatueZ","UsetupcontrolZ","UsetuparchZ","UsetuptraZ",
    "UsetupdestZ","UsetupsevbZ","UsetupaztZ","UsetuppeteZ","UsetupdepoZ","UsetuprefZ",
    "UsetupcrypZ","UsetupdamZ","UsetuparkZ","UsetuprunZ","UsetupsevxZ","UsetupjunZ",
    "UsetupdishZ","UsetupcaveZ","UsetupcatZ","UsetupcradZ","UsetupshoZ","UsetupsevxbZ",
    "UsetupeldZ","UsetupimpZ","UsetupashZ","UsetuplueZ","UsetupameZ","UsetupritZ",
    "UsetupoatZ","UsetupearZ","UsetupleeZ","UsetuplipZ","UsetuplenZ","UsetupwaxZ",
    "UsetuppamZ",0,0
};


//D:800375D0
struct PitemZ_header Palarm1z_header = {0, &model_object_standard_object, 0, 0, 1, 304.6402, 2, 0, 0};
//D:800375F0
struct PitemZ_header Palarm2Z_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 3, 0, 0};
//D:80037610
struct PitemZ_header PexplosionbitZ_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 0, 0};
//D:80037630
struct PitemZ_header Pammo_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 3, 0, 0};
//D:80037650
struct PitemZ_header Pammo_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 4, 0, 0};
//D:80037670
struct PitemZ_header Pammo_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 4, 0, 0};
//D:80037690
struct PitemZ_header Pammo_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 5, 0, 0};
//D:800376B0
struct PitemZ_header Pammo_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 5, 0, 0};
//D:800376D0
struct PitemZ_header Pbin1Z_header = {0, &model_object_standard_object, 0, 0, 1, 3027.6262, 2, 0};
//D:800376F0
struct PitemZ_header Pblotter1Z_header = {0, &model_object_standard_object, 0, 0, 1, 432.46707, 1, 0, 0};
//D:80037710
struct PitemZ_header Pbook1Z_header = {0, &model_object_standard_object, 0, 0, 1, 171.37482, 2, 0, };
//D:80037730
struct PitemZ_header Pbookshelf1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1166.7578, 0xD, 0, 0};
//D:80037750
struct PitemZ_header Pbridge_console1aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:80037770
struct PitemZ_header Pbridge_console1bZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 788.03992, 0x10, 0, 0};
//D:80037790
struct PitemZ_header Pbridge_console2aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:800377B0
struct PitemZ_header Pbridge_console2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 788.03992, 0xF, 0, 0};
//D:800377D0
struct PitemZ_header Pbridge_console3aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:800377F0
struct PitemZ_header Pbridge_console3bZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0x10, 0, 0};
//D:80037810
struct PitemZ_header Pcard_box1Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 5, 0, 0};
//D:80037830
struct PitemZ_header Pcard_box2Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 6, 0, 0};
//D:80037850
struct PitemZ_header Pcard_box3Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 5, 0, 0};
//D:80037870
struct PitemZ_header Pcard_box4_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 4, 0, 0};
//D:80037890
struct PitemZ_header Pcard_box5_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 5, 0, 0};
//D:800378B0
struct PitemZ_header Pcard_box6_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 5, 0, 0};
//D:800378D0
struct PitemZ_header PcctvZ_header = {0, &prop_cctv_related, 0, 0, 0x40002, 558.90094, 6, 0};
//D:800378F0
struct PitemZ_header Pconsole1Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037910
struct PitemZ_header Pconsole2Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037930
struct PitemZ_header Pconsole3Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037950
struct PitemZ_header Pconsole_sevaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xE, 0, 0};
//D:80037970
struct PitemZ_header Pconsole_sevbZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xB, 0, 0};
//D:80037990
struct PitemZ_header Pconsole_sevcZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xF, 0, 0};
//D:800379B0
struct PitemZ_header Pconsole_sevdZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:800379D0
struct PitemZ_header Pconsole_sev2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:800379F0
struct PitemZ_header Pconsole_sev2bZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xD, 0, 0};
//D:80037A10
struct PitemZ_header Pconsole_sev2cZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xF, 0, 0};
//D:80037A30
struct PitemZ_header Pconsole_sev2dZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A50
struct PitemZ_header Pconsole_sev_GEaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A70
struct PitemZ_header Pconsole_sev_GEbZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A90
struct PitemZ_header Pdesk1Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 3, 0, };
//D:80037AB0
struct PitemZ_header Pdesk2Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 3, 0, };
//D:80037AD0
struct PitemZ_header Pdesk_lamp2Z_header = {0, &model_object_standard_object, 0, 0, 1, 804.59833, 4, 0, 0};
//D:80037AF0
struct PitemZ_header Pdisc_readerZ_header = {0, &model_object_standard_object, 0, 0, 1, 214.33035, 6, 0, 0};
//D:80037B10
struct PitemZ_header Pdisk_drive1Z_header = {0, &model_object_standard_object, 0, 0, 1, 191.85779, 4, 0, 0};
//D:80037B30
struct PitemZ_header Pfiling_cabinet1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1055.5693, 2, 0, 0};
//D:80037B50
struct PitemZ_header Pjerry_can1Z_header = {0, &model_object_standard_object, 0, 0, 1, 366.61932, 4, 0, 0};
//D:80037B70
struct PitemZ_header Pkeyboard1Z_header = {0, &model_object_standard_object, 0, 0, 1, 278.23227, 2, 0, 0};
//D:80037B90
struct PitemZ_header Pkit_units1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1661.4763, 4, 0, 0};
//D:80037BB0
struct PitemZ_header Pletter_tray1Z_header = {0, &model_object_standard_object, 0, 0, 1, 252.06836, 1, 0, 0};
//D:80037BD0
struct PitemZ_header Pmainframe1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 7, 0, 0};
//D:80037BF0
struct PitemZ_header Pmainframe2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 7, 0, 0};
//D:80037C10
struct PitemZ_header Pmetal_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 639.18097, 2, 0, 0};
//D:80037C30
struct PitemZ_header Pmetal_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037C50
struct PitemZ_header Pmetal_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037C70
struct PitemZ_header Pmetal_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 2, 0, 0};
//D:80037C90
struct PitemZ_header Pmetal_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037CB0
struct PitemZ_header Pmissile_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 964.16296, 4, 0, 0};
//D:80037CD0
struct PitemZ_header Pmissile_rack2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1148.4724, 4, 0, 0};
//D:80037CF0
struct PitemZ_header Poil_drum1Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 2, 0, 0};
//D:80037D10
struct PitemZ_header Poil_drum2Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037D30
struct PitemZ_header Poil_drum3Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037D50
struct PitemZ_header Poil_drum5Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 3, 0, 0};
//D:80037D70
struct PitemZ_header Poil_drum6Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 3, 0, 0};
//D:80037D90
struct PitemZ_header Poil_drum7Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037DB0
struct PitemZ_header PpadlockZ_header = {0, &model_object_standard_object, 0, 0, 1, 225.64145, 4, 0, 0};
//D:80037DD0
struct PitemZ_header Pphone1Z_header = {0, &model_object_standard_object, 0, 0, 1, 166.03481, 2, 0, 0};
//D:80037DF0
struct PitemZ_header Pradio_unit1Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E10
struct PitemZ_header Pradio_unit2Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E30
struct PitemZ_header Pradio_unit3Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E50
struct PitemZ_header Pradio_unit4Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E70
struct PitemZ_header Psat1_reflectZ_header = {0, &model_object_standard_object, 0, 0, 1, 5185.9409, 0xD, 0, 0};
//D:80037E90
struct PitemZ_header PsatdishZ_header = {0, &model_object_standard_object, 0, 0, 1, 2437.468, 2, 0, 0};
//D:80037EB0
struct PitemZ_header PsatboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 89.935875, 1, 0, 0};
//D:80037ED0
struct PitemZ_header Pstool1Z_header = {0, &model_object_standard_object, 0, 0, 1, 353.11398, 2, 0, 0};
//D:80037EF0
struct PitemZ_header Pswivel_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 581.16394, 3, 0, 0};
//D:80037F10
struct PitemZ_header Ptorpedo_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 765.61725, 3, 0, 0};
//D:80037F30
struct PitemZ_header Ptv1Z_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 347.0235, 5, 0};
//D:80037F50
struct PitemZ_header Ptv_holderZ_header = {0, &prop_tv_holder_related, 0, 0, 0x40005, 1352.4841, 2, 0, 0};
//D:80037F70
struct PitemZ_header PtvscreenZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 211.74477, 1, 0, 0};
//D:80037F90
struct PitemZ_header Ptv4screenZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 211.74477, 1, 0, 0};
//D:80037FB0
struct PitemZ_header Pwood_lg_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037FD0
struct PitemZ_header Pwood_lg_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 2, 0, 0};
//D:80037FF0
struct PitemZ_header Pwood_md_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 909.32666, 2, 0, 0};
//D:80038010
struct PitemZ_header Pwood_sm_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 3, 0, 0};
//D:80038030
struct PitemZ_header Pwood_sm_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 4, 0, 0};
//D:80038050
struct PitemZ_header Pwood_sm_crate6Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 4, 0, 0};
//D:80038070
struct PitemZ_header Pwooden_table1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1095.1365, 2, 0, 0};
//D:80038090
struct PitemZ_header Pswipe_card2Z_header = {0, &model_object_standard_object, 0, 0, 1, 123.088844, 2, 0, 0};
//D:800380B0
struct PitemZ_header Pborg_crateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 1, 0, 0};
//D:800380D0
struct PitemZ_header Pboxes4x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2424.8711, 7, 0, 0};
//D:800380F0
struct PitemZ_header Pboxes3x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2241.0935, 6, 0, 0};
//D:80038110
struct PitemZ_header Pboxes2x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2100.0, 6, 0, 0};
//D:80038130
struct PitemZ_header Psec_panelZ_header = {0, &model_object_standard_object, 0, 0, 1, 1567.2454, 3, 0, 0};
//D:80038150
struct PitemZ_header PICBM_noseZ_header = {0, &model_object_standard_object, 0, 0, 1, 2782.7126, 8, 0, 0};
//D:80038170
struct PitemZ_header PICBMZ_header = {0, &model_object_standard_object, 0, 0, 1, 14790.535, 0xE, 0};
//D:80038190
struct PitemZ_header Ptuning_console1Z_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 1139.5872, 0xE, 0, 0};
//D:800381B0
struct PitemZ_header Pdesk_arecibo1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1829.1477, 3, 0, 0};
//D:800381D0
struct PitemZ_header Plocker3Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 3, 0, 0};
//D:800381F0
struct PitemZ_header Plocker4Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 3, 0, 0};
//D:80038210
struct PitemZ_header ProofgunZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 1910.908, 0xE, 0, 0};
//D:80038230
struct PitemZ_header Pdest_engineZ_header = {0, &model_object_standard_object, 0, 0, 1, 6459.439, 0xA, 0, 0};
//D:80038250
struct PitemZ_header Pdest_exocetZ_header = {0, &model_object_standard_object, 0, 0, 1, 1644.8435, 8, 0, 0};
//D:80038270
struct PitemZ_header Pdest_gunZ_header = {0, &model_object_standard_object, 0, 0, 1, 2124.0735, 5, 0, 0};
//D:80038290
struct PitemZ_header Pdest_harpoonZ_header = {0, &model_object_standard_object, 0, 0, 1, 1798.7655, 5, 0, 0};
//D:800382B0
struct PitemZ_header Pdest_seawolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 2282.0623, 0xA, 0, 0};
//D:800382D0
struct PitemZ_header PwindowZ_header = {0, &model_object_standard_object, 0, 0, 1, 423.48956, 1, 0, 0};
//D:800382F0
struct PitemZ_header Pwindow_lib_lg1Z_header = {0, &model_object_standard_object, 0, 0, 1, 835.20624, 1, 0, 0};
//D:80038310
struct PitemZ_header Pwindow_lib_sm1Z_header = {0, &model_object_standard_object, 0, 0, 1, 601.28625, 1, 0, 0};
//D:80038330
struct PitemZ_header Pwindow_cor11Z_header = {0, &model_object_standard_object, 0, 0, 1, 414.53622, 1, 0, 0};
//D:80038350
struct PitemZ_header Pjungle3_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 28729.467, 5, 0, 0};
//D:80038370
struct PitemZ_header PpalmZ_header = {0, &model_object_standard_object, 0, 0, 1, 15501.406, 3, 0};
//D:80038390
struct PitemZ_header PpalmtreeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1781.4542, 2, 0, 0};
//D:800383B0
struct PitemZ_header Pplant2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1252.9539, 2, 0, 0};
//D:800383D0
struct PitemZ_header PlabbenchZ_header = {0, &model_object_standard_object, 0, 0, 1, 844.09717, 4, 0, 0};
//D:800383F0
struct PitemZ_header PgasbarrelZ_header = {0, &model_object_standard_object, 0, 0, 1, 725.94379, 2, 0, 0};
//D:80038410
struct PitemZ_header PgasbarrelsZ_header = {0, &model_object_standard_object, 0, 0, 1, 1174.1927, 2, 0, 0};
//D:80038430
struct PitemZ_header PbodyarmourZ_header = {0, &model_object_standard_object, 0, 0, 1, 246.94099, 7, 0, 0};
//D:80038450
struct PitemZ_header PbodyarmourvestZ_header = {0, &model_object_standard_object, 0, 0, 1, 241.82211, 2, 0, 0};
//D:80038470
struct PitemZ_header PgastankZ_header = {0, &model_object_standard_object, 0, 0, 1, 1130.0691, 5, 0, 0};
//D:80038490
struct PitemZ_header Pglassware1Z_header = {0, &model_object_standard_object, 0, 0, 1, 72.111031, 1, 0, 0};
//D:800384B0
struct PitemZ_header PhatchboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 2236.0679, 1, 0, 0};
//D:800384D0
struct PitemZ_header PbrakeunitZ_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 4, 0, 0};
//D:800384F0
struct PitemZ_header Pak47magZ_header = {0, &model_object_standard_object, 0, 0, 1, 107.11019, 2, 0, 0};
//D:80038510
struct PitemZ_header Pm16magZ_header = {0, &model_object_standard_object, 0, 0, 1, 87.934891, 2, 0, 0};
//D:80038530
struct PitemZ_header Pmp5kmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.547295, 2, 0, 0};
//D:80038550
struct PitemZ_header PskorpionmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 58.428444, 2, 0, 0};
//D:80038570
struct PitemZ_header PspectremagZ_header = {0, &model_object_standard_object, 0, 0, 1, 99.01432, 2, 0, 0};
//D:80038590
struct PitemZ_header PuzimagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:800385B0
struct PitemZ_header PsilencerZ_header = {0, &model_object_standard_object, 0, 0, 1, 63.915436, 3, 0, 0};
//D:800385D0
struct PitemZ_header PchrextinguisherZ_header = {0, &model_object_standard_object, 0, 0, 1, 425.50903, 2, 0, 0};
//D:800385F0
struct PitemZ_header PboxcartridgesZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038610
struct PitemZ_header Pfnp90magZ_header = {0, &model_object_standard_object, 0, 0, 1, 176.28201, 2, 0, 0};
//D:80038630
struct PitemZ_header PgoldenshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038650
struct PitemZ_header PmagnumshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038670
struct PitemZ_header PwppkmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:80038690
struct PitemZ_header Ptt33magZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:800386B0
struct PitemZ_header Psev_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.7695, 3, 0, 0};
//D:800386D0
struct PitemZ_header Psev_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 6, 0, 0};
//D:800386F0
struct PitemZ_header Psev_door3_windZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 5, 0, 0};
//D:80038710
struct PitemZ_header Psev_door4_windZ_header = {0, &prop_door_related, 0, 0, 0x40001, 1143.5603, 8, 0, 0};
//D:80038730
struct PitemZ_header Psev_trislideZ_header = {0, &prop_door_related, 0, 0, 0x40001, 950.54327, 2, 0, 0};
//D:80038750
struct PitemZ_header Psev_door_v1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 6, 0, 0};
//D:80038770
struct PitemZ_header Psteel_door1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 4, 0, 0};
//D:80038790
struct PitemZ_header Psteel_door2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:800387B0
struct PitemZ_header Psteel_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:800387D0
struct PitemZ_header Psilo_lift_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 600.71082, 4, 0, 0};
//D:800387F0
struct PitemZ_header Psteel_door2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:80038810
struct PitemZ_header Pdoor_roller1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038830
struct PitemZ_header Pdoor_roller2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038850
struct PitemZ_header Pdoor_roller3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038870
struct PitemZ_header Pdoor_roller4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038890
struct PitemZ_header Pdoor_st_arec1Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 3, 0, 0};
//D:800388B0
struct PitemZ_header Pdoor_st_arec2Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 3, 0, 0};
//D:800388D0
struct PitemZ_header Pdoor_dest1Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 3, 0, 0};
//D:800388F0
struct PitemZ_header Pdoor_dest2Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 5, 0, 0};
//D:80038910
struct PitemZ_header Pgas_plant_sw_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.29706, 4, 0, 0};
//D:80038930
struct PitemZ_header Pgas_plant_sw2_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 2, 0, 0};
//D:80038950
struct PitemZ_header Pgas_plant_sw3_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 2, 0, 0};
//D:80038970
struct PitemZ_header Pgas_plant_sw4_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 1, 0, 0};
//D:80038990
struct PitemZ_header Pgas_plant_met1_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 5, 0, 0};
//D:800389B0
struct PitemZ_header Pgas_plant_wc_cub1Z_header = {0, &model_object_standard_object, 0, 0, 1, 783.8501, 3, 0, 0};
//D:800389D0
struct PitemZ_header Pgasplant_clear_doorZ_header = {0, &prop_door_related, 0, 0, 0x40001, 1025.0952, 2, 0, 0};
//D:800389F0
struct PitemZ_header Ptrain_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 456.99615, 3, 0, 0};
//D:80038A10
struct PitemZ_header Ptrain_door2Z_header = {0, &prop_door_related, 0, 0, 0x40001, 445.98541, 3, 0, 0};
//D:80038A30
struct PitemZ_header Ptrain_door3Z_header = {0, &prop_door_related, 0, 0, 0x40001, 445.98541, 4, 0, 0};
//D:80038A50
struct PitemZ_header Pdoor_eyelidZ_header = {0, &prop_eyelid_door_related, 0, 0, 0x30003, 3165.4348, 3, 0, 0};
//D:80038A70
struct PitemZ_header Pdoor_irisZ_header = {0, &prop_iris_door_related, 0, 0, 0xD000D, 1621.3601, 5, 0, 0};
//D:80038A90
struct PitemZ_header PsevdoorwoodZ_header = {0, &prop_door_related, 0, 0, 0x40001, 851.62671, 3, 0, 0};
//D:80038AB0
struct PitemZ_header PsevdoorwindZ_header = {0, &prop_door_related, 0, 0, 0x40001, 851.62671, 5, 0, 0};
//D:80038AD0
struct PitemZ_header PsevdoornowindZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.03766, 2, 0, 0};
//D:80038AF0
struct PitemZ_header PsevdoormetslideZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.74707, 2, 0, 0};
//D:80038B10
struct PitemZ_header Pcryptdoor1aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 2, 0, 0};
//D:80038B30
struct PitemZ_header Pcryptdoor1bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 2, 0, 0};
//D:80038B50
struct PitemZ_header Pcryptdoor2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 2, 0, 0};
//D:80038B70
struct PitemZ_header Pcryptdoor2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 2, 0, 0};
//D:80038B90
struct PitemZ_header Pcryptdoor3Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 3, 0, 0};
//D:80038BB0
struct PitemZ_header Pcryptdoor4Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 1, 0, 0};
//D:80038BD0
struct PitemZ_header PvertdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1997.2246, 5, 0, 0};
//D:80038BF0
struct PitemZ_header PhatchdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 192.1653, 1, 0, 0};
//D:80038C10
struct PitemZ_header PdamgatedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 308.36456, 3, 0, 0};
//D:80038C30
struct PitemZ_header PdamtundoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 127.89996, 4, 0, 0};
//D:80038C50
struct PitemZ_header PdamchaindoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 171.36655, 2, 0, 0};
//D:80038C70
struct PitemZ_header PsilotopdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 2675.3958, 5, 0, 0};
//D:80038C90
struct PitemZ_header Pdoorprison1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1062.0833, 1, 0, 0};
//D:80038CB0
struct PitemZ_header PdoorstatgateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1503.9503, 3, 0, 0};
//D:80038CD0
struct PitemZ_header PchrkalashZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 403.53766, 8, 0, 0};
//D:80038CF0
struct PitemZ_header PchrgrenadelaunchZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 422.48355, 7, 0, 0};
//D:80038D10
struct PitemZ_header PchrknifeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 245.14619, 2, 0, 0};
//D:80038D30
struct PitemZ_header PchrlaserZ_header = {0, &prop_weapon_related, 0, 0, 0x30002, 444.66241, 8, 0, 0};
//D:80038D50
struct PitemZ_header Pchrm16Z_header = {0, &prop_weapon_related, 0, 0, 0x30002, 964.01367, 6, 0, 0};
//D:80038D70
struct PitemZ_header Pchrmp5kZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 277.32227, 9, 0, 0};
//D:80038D90
struct PitemZ_header PchrrugerZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 246.72643, 5, 0, 0};
//D:80038DB0
struct PitemZ_header PchrwppkZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 125.79879, 5, 0, 0};
//D:80038DD0
struct PitemZ_header PchrshotgunZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 488.88385, 8, 0, 0};
//D:80038DF0
struct PitemZ_header PchrskorpionZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 183.37708, 7, 0, 0};
//D:80038E10
struct PitemZ_header PchrspectreZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 351.26923, 6, 0, 0};
//D:80038E30
struct PitemZ_header PchruziZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 265.11813, 7, 0, 0};
//D:80038E50
struct PitemZ_header PchrgrenadeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 118.18749, 2, 0, 0};
//D:80038E70
struct PitemZ_header Pchrfnp90Z_header = {0, &prop_weapon_related, 0, 0, 0x30002, 470.04633, 7, 0, 0};
//D:80038E90
struct PitemZ_header PchrbriefcaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80038EB0
struct PitemZ_header PchrremotemineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.434036, 2, 0, 0};
//D:80038ED0
struct PitemZ_header PchrproximitymineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.196609, 2, 0, 0};
//D:80038EF0
struct PitemZ_header PchrtimedmineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.245888, 3, 0, 0};
//D:80038F10
struct PitemZ_header PchrrocketZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.8634, 3, 0, 0};
//D:80038F30
struct PitemZ_header PchrgrenaderoundZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 96.976593, 1, 0, 0};
//D:80038F50
struct PitemZ_header PchrwppksilZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 219.44571, 6, 0, 0};
//D:80038F70
struct PitemZ_header Pchrtt33Z_header = {0, &prop_weapon_related, 0, 0, 0x30001, 142.11539, 5, 0, 0};
//D:80038F90
struct PitemZ_header Pchrmp5ksilZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 406.18033, 0xA, 0, 0};
//D:80038FB0
struct PitemZ_header PchrautoshotZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 375.50247, 8, 0, 0};
//D:80038FD0
struct PitemZ_header PchrgoldenZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 157.98299, 2, 0, 0};
//D:80038FF0
struct PitemZ_header PchrthrowknifeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 217.61888, 2, 0, 0};
//D:80039010
struct PitemZ_header PchrsniperrifleZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 616.93939, 5, 0, 0};
//D:80039030
struct PitemZ_header PchrrocketlaunchZ_header = {0, &prop_weapon_related, 0, 0, 0x30002, 501.55179, 6, 0, 0};
//D:80039050
struct PitemZ_header PhatfurryZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:80039070
struct PitemZ_header PhatfurrybrownZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:80039090
struct PitemZ_header PhatfurryblackZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:800390B0
struct PitemZ_header PhattbirdZ_header = {0, &item_hat_related, 0, 0, 1, 114.45274, 1, 0, 0};
//D:800390D0
struct PitemZ_header PhattbirdbrownZ_header = {0, &item_hat_related, 0, 0, 1, 122.7013, 1, 0, 0};
//D:800390F0
struct PitemZ_header PhathelmetZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 1, 0, 0};
//D:80039110
struct PitemZ_header PhathelmetgreyZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 1, 0, 0};
//D:80039130
struct PitemZ_header PhatmoonZ_header = {0, &item_hat_related, 0, 0, 1, 138.25751, 2, 0, 0};
//D:80039150
struct PitemZ_header PhatberetZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 1, 0, 0};
//D:80039170
struct PitemZ_header PhatberetblueZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 2, 0, 0};
//D:80039190
struct PitemZ_header PhatberetredZ_header = {0, &item_hat_related, 0, 0, 1, 115.46455, 2, 0, 0};
//D:800391B0
struct PitemZ_header PhatpeakedZ_header = {0, &item_hat_related, 0, 0, 1, 148.39027, 1, 0, 0};
//D:800391D0
struct PitemZ_header PchrwristdartZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800391F0
struct PitemZ_header PchrexplosivepenZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039210
struct PitemZ_header PchrbombcaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039230
struct PitemZ_header PchrflarepistolZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039250
struct PitemZ_header PchrpitongunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039270
struct PitemZ_header PchrfingergunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039290
struct PitemZ_header PchrsilverwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392B0
struct PitemZ_header PchrgoldwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392D0
struct PitemZ_header PchrdynamiteZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392F0
struct PitemZ_header PchrbungeeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039310
struct PitemZ_header PchrdoordecoderZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 180.27969, 0x10, 0, 0};
//D:80039330
struct PitemZ_header PchrbombdefuserZ_header = {0, &model_object_standard_object, 0, 0, 1, 84.370705, 0xC, 0, 0};
//D:80039350
struct PitemZ_header PchrbugdetectorZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039370
struct PitemZ_header PchrsafecrackercaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039390
struct PitemZ_header PchrcameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 52.775627, 0xB, 0, 0};
//D:800393B0
struct PitemZ_header PchrlockexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800393D0
struct PitemZ_header PchrdoorexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800393F0
struct PitemZ_header PchrkeyanalysercaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039410
struct PitemZ_header PchrweaponcaseZ_header = {0, &model_object_standard_object, 0, 0, 1, 274.2905, 5, 0, 0};
//D:80039430
struct PitemZ_header PchrkeyyaleZ_header = {0, &model_object_standard_object, 0, 0, 1, 82.850311, 1, 0, 0};
//D:80039450
struct PitemZ_header PchrkeyboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 151.85315, 1, 0, 0};
//D:80039470
struct PitemZ_header PchrbugZ_header = {0, &model_object_standard_object, 0, 0, 1, 104.7203, 6, 0, 0};
//D:80039490
struct PitemZ_header PchrmicrocameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 126.49728, 7, 0, 0};
//D:800394B0
struct PitemZ_header PfloppyZ_header = {0, &model_object_standard_object, 0, 0, 1, 60.902443, 5, 0, 0};
//D:800394D0
struct PitemZ_header PchrgoldeneyekeyZ_header = {0, &model_object_standard_object, 0, 0, 1, 98.987083, 5, 0, 0};
//D:800394F0
struct PitemZ_header PchrpolarizedglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 53.776386, 2, 0, 0};
//D:80039510
struct PitemZ_header PchrcreditcardZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039530
struct PitemZ_header PchrdarkglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039550
struct PitemZ_header PchrgaskeyringZ_header = {0, &model_object_standard_object, 0, 0, 1, 111.59859, 9, 0, 0};
//D:80039570
struct PitemZ_header PchrdatathiefZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.78231, 3, 0, 0};
//D:80039590
struct PitemZ_header PsafeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1011.18744, 3, 0};
//D:800395B0
struct PitemZ_header PbombZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0};
//D:800395D0
struct PitemZ_header PchrplansZ_header = {0, &model_object_standard_object, 0, 0, 1, 384.74649, 5, 0, 0};
//D:800395F0
struct PitemZ_header PchrspyfileZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039610
struct PitemZ_header PchrblueprintsZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 4, 0, 0};
//D:80039630
struct PitemZ_header PchrcircuitboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 138.90285, 3, 0, 0};
//D:80039650
struct PitemZ_header PchrmapZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 4, 0, 0};
//D:80039670
struct PitemZ_header PchrspooltapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039690
struct PitemZ_header PchraudiotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 97.531075, 9, 0, 0};
//D:800396B0
struct PitemZ_header PchrmicrofilmZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800396D0
struct PitemZ_header PchrmicrocodeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800396F0
struct PitemZ_header PchrlectreZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039710
struct PitemZ_header PchrmoneyZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039730
struct PitemZ_header PchrgoldbarZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039750
struct PitemZ_header PchrheroinZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039770
struct PitemZ_header PchrclipboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 190.41742, 3, 0, 0};
//D:80039790
struct PitemZ_header PchrdossierredZ_header = {0, &model_object_standard_object, 0, 0, 1, 183.54231, 4, 0, 0};
//D:800397B0
struct PitemZ_header PchrstafflistZ_header = {0, &model_object_standard_object, 0, 0, 1, 215.17534, 4, 0, 0};
//D:800397D0
struct PitemZ_header PchrdattapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 79.868584, 4, 0, 0};
//D:800397F0
struct PitemZ_header PchrplastiqueZ_header = {0, &model_object_standard_object, 0, 0, 1, 143.86052, 3, 0, 0};
//D:80039810
struct PitemZ_header PchrblackboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 128.31796, 5, 0, 0};
//D:80039830
struct PitemZ_header PchrvideotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 122.69632, 9, 0, 0};
//D:80039850
struct PitemZ_header PnintendologoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1868.335, 1, 0, 0};
//D:80039870
struct PitemZ_header PgoldeneyelogoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1287.1866, 2, 0, 0};
//D:80039890
struct PitemZ_header PwalletbondZ_header = {0, &prop_walletbond_related, 0, 0, 0x2B0001, 3504.53, 0x54, 0, 0};
//D:800398B0
struct PitemZ_header PmiltruckZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 4589.7188, 0x16, 0, 0};
//D:800398D0
struct PitemZ_header PjeepZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 2107.8105, 0x10, 0};
//D:800398F0
struct PitemZ_header ParticZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 2678.5667, 0x11, 0, };
//D:80039910
struct PitemZ_header PhelicopterZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 4955.271, 0x18, 0, 0};
//D:80039930
struct PitemZ_header PtigerZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 4072.0291, 0xE, 0, };
//D:80039950
struct PitemZ_header PmilcopterZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 5316.9155, 0xF, 0, 0};
//D:80039970
struct PitemZ_header PhindZ_header = {0, &prop_flying_related, 0, 0, 0x60005, 5315.314, 0xB, 0};
//D:80039990
struct PitemZ_header PartictrailerZ_header = {0, &model_object_standard_object, 0, 0, 1, 4014.6265, 0xB, 0, 0};
//D:800399B0
struct PitemZ_header PmotorbikeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1610.8706, 6, 0, 0};
//D:800399D0
struct PitemZ_header PtankZ_header = {0, &item_tank_related, 0, 0, 0x90005, 6290.8398, 0x18, 0};
//D:800399F0
struct PitemZ_header PapcZ_header = {0, &model_object_standard_object, 0, 0, 1, 3611.1035, 0xE, 0};
//D:80039A10
struct PitemZ_header PspeedboatZ_header = {0, &model_object_standard_object, 0, 0, 1, 1799.4586, 0xD, 0, 0};
//D:80039A30
struct PitemZ_header PplaneZ_header = {0, &prop_flying_related, 0, 0, 0x60003, 9285.4492, 0x1C, 0, };
//D:80039A50
struct PitemZ_header Pgun_runway1Z_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 1927.5205, 6, 0, 0};
//D:80039A70
struct PitemZ_header PsafedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 714.14612, 4, 0, 0};
//D:80039A90
struct PitemZ_header Pkey_holderZ_header = {0, &model_object_standard_object, 0, 0, 1, 223.87097, 7, 0, 0};
//D:80039AB0
struct PitemZ_header PhatchsevxZ_header = {0, &model_object_standard_object, 0, 0, 1, 1224.7664, 2, 0, 0};
//D:80039AD0
struct PitemZ_header PsevdishZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80003, 14350.1, 7, 0, 0};
//D:80039AF0
struct PitemZ_header Parchsecdoor1Z_header = {0, &model_object_standard_object, 0, 0, 1, 455.81409, 3, 0, 0};
//D:80039B10
struct PitemZ_header Parchsecdoor2Z_header = {0, &model_object_standard_object, 0, 0, 1, 496.99292, 3, 0, 0};
//D:80039B30
struct PitemZ_header PgroundgunZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 2182.6472, 4, 0, 0};
//D:80039B50
struct PitemZ_header PtrainextdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 587.70111, 5, 0, 0};
//D:80039B70
struct PitemZ_header PcarbmwZ_header = {0, &model_object_standard_object, 0, 0, 1, 553.08728, 0xB, 0, 0};
//D:80039B90
struct PitemZ_header PcarescortZ_header = {0, &model_object_standard_object, 0, 0, 1, 1110.5665, 9, 0, 0};
//D:80039BB0
struct PitemZ_header PcargolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 1121.6409, 0xA, 0, 0};
//D:80039BD0
struct PitemZ_header PcarweirdZ_header = {0, &model_object_standard_object, 0, 0, 1, 984.03931, 0xD, 0, 0};
//D:80039BF0
struct PitemZ_header PcarzilZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 1044.5764, 0xD, 0, 0};
//D:80039C10
struct PitemZ_header Pshuttle_door_lZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 7, 0, 0};
//D:80039C30
struct PitemZ_header Pshuttle_door_rZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 8, 0, 0};
//D:80039C50
struct PitemZ_header Pdepot_gate_entryZ_header = {0, &model_object_standard_object, 0, 0, 1, 811.28949, 3, 0, 0};
//D:80039C70
struct PitemZ_header Pdepot_door_steelZ_header = {0, &model_object_standard_object, 0, 0, 1, 574.79651, 3, 0, 0};
//D:80039C90
struct PitemZ_header Pglassware2Z_header = {0, &model_object_standard_object, 0, 0, 1, 98.488579, 3, 0, 0};
//D:80039CB0
struct PitemZ_header Pglassware3Z_header = {0, &model_object_standard_object, 0, 0, 1, 137.92715, 1, 0, 0};
//D:80039CD0
struct PitemZ_header Pglassware4Z_header = {0, &model_object_standard_object, 0, 0, 1, 177.48241, 2, 0, 0};
//D:80039CF0
struct PitemZ_header PlandmineZ_header = {0, &model_object_standard_object, 0, 0, 1, 440.03009, 2, 0, 0};
//D:80039D10
struct PitemZ_header Pplant1Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 1, 0, 0};
//D:80039D30
struct PitemZ_header Pplant11Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 1, 0, 0};
//D:80039D50
struct PitemZ_header Pplant2Z_header = {0, &model_object_standard_object, 0, 0, 1, 3416.248, 2, 0, 0};
//D:80039D70
struct PitemZ_header Pplant3Z_header = {0, &model_object_standard_object, 0, 0, 1, 2986.0405, 1, 0, 0};
//D:80039D90
struct PitemZ_header Pjungle5_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 3277.6123, 4, 0, 0};
//D:80039DB0
struct PitemZ_header PlegalpageZ_header = {0, &model_object_standard_object, 0, 0, 1, 2711.7573, 5, 0, 0};
//D:80039DD0
struct PitemZ_header Pst_pete_room_1iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8437.5137, 0x17, 0, 0};
//D:80039DF0
struct PitemZ_header Pst_pete_room_2iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8515.8164, 0x19, 0, 0};
//D:80039E10
struct PitemZ_header Pst_pete_room_3tZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0x1B, 0, 0};
//D:80039E30
struct PitemZ_header Pst_pete_room_5cZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0x19, 0, 0};
//D:80039E50
struct PitemZ_header Pst_pete_room_6cZ_header = {0, &model_object_standard_object, 0, 0, 1, 5006.2896, 0x17, 0, 0};
//D:80039E70
struct PitemZ_header Pdoor_rollertrainZ_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 2, 0, 0};
//D:80039E90
struct PitemZ_header Pdoor_winZ_header = {0, &model_object_standard_object, 0, 0, 1, 211.90215, 1, 0, 0};
//D:80039EB0
struct PitemZ_header Pdoor_aztecZ_header = {0, &model_object_standard_object, 0, 0, 1, 632.48639, 1, 0, 0};
//D:80039ED0
struct PitemZ_header PshuttleZ_header = {0, &model_object_standard_object, 0, 0, 1, 4475.1494, 9, 0, 0};
//D:80039EF0
struct PitemZ_header Pdoor_azt_deskZ_header = {0, &model_object_standard_object, 0, 0, 1, 860.41669, 2, 0, 0};
//D:80039F10
struct PitemZ_header Pdoor_azt_desk_topZ_header = {0, &model_object_standard_object, 0, 0, 1, 565.93268, 3, 0, 0};
//D:80039F30
struct PitemZ_header Pdoor_azt_chairZ_header = {0, &model_object_standard_object, 0, 0, 1, 94.510803, 3, 0, 0};
//D:80039F50
struct PitemZ_header Pdoor_mfZ_header = {0, &model_object_standard_object, 0, 0, 1, 559.70367, 7, 0, 0};
//D:80039F70
struct PitemZ_header PflagZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 862.30865, 2, 0};
//D:80039F90
struct PitemZ_header PbarricadeZ_header = {0, &model_object_standard_object, 0, 0, 1, 2047.3016, 2, 0, 0};
//D:80039FB0
struct PitemZ_header PmodemboxZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 338.28839, 4, 0, 0};
//D:80039FD0
struct PitemZ_header PdoorpanelZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 338.28839, 4, 0, 0};
//D:80039FF0
struct PitemZ_header PdoorconsoleZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xD, 0, 0};
//D:8003A010
struct PitemZ_header PchrtesttubeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 136.25925, 2, 0, 0};
//D:8003A030
struct PitemZ_header Pbollardz_header = {0, &model_object_standard_object, 0, 0, 1, 628.78754, 1, 0, 0};

//D:8003A050
struct prop_pos_data word_D_8003A050[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
struct item_related prop_cctv_related = {2, 0, word_D_8003A050, 6, 0};

//D:8003A068
struct prop_pos_data word_D_8003A068[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A06E                     .half 0

//D:8003A070
struct item_related prop_console_one_screen_related = {1, 0, word_D_8003A068, 3, 0};

//D:8003A07C
struct prop_pos_data word_D_8003A07C[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A082                     .half 0

//D:8003A084
struct item_related prop_console_four_screen_related = {1, 0, word_D_8003A07C, 3, 0};

//D:8003A090
struct prop_pos_data word_D_8003A090[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0AE                     .half 0

//D:8003A0B0
struct item_related prop_tv_holder_related = {5, 0, word_D_8003A090, 0xF, 0};

//D:8003A0BC
struct prop_pos_data word_D_8003A0BC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
struct item_related prop_rotating_stuff_related = {6, 0, word_D_8003A0BC, 0x12, 0};

//D:8003A0EC
struct prop_pos_data word_D_8003A0EC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A0FE                     .half 0
//D:8003A100
struct item_related prop_eyelid_door_related = {3, 0, word_D_8003A0EC, 9, 0};

//D:8003A10C
struct prop_pos_data word_D_8003A10C[] = {
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
struct item_related prop_iris_door_related = {0xD, 0, word_D_8003A10C, 0x27, 0};

//D:8003A168
struct prop_pos_data word_D_8003A168[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A16E                     .half 0
//D:8003A170
struct item_related prop_walletbond_related = {1, 0, word_D_8003A168, 3, 0};

//D:8003A17C
struct prop_pos_data word_D_8003A17C[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
struct item_related prop_car_related = {5, 0, word_D_8003A17C, 0xF, 0};

//D:8003A1A8
struct prop_pos_data word_D_8003A1A8[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C6                     .half 0
//D:8003A1C8
struct item_related prop_flying_related = {5, 0, word_D_8003A1A8, 3, 0};

//D:8003A1D4
struct prop_pos_data word_D_8003A1D4[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DA                     .half 0
//D:8003A1DC
struct item_related prop_door_related = {1, 0, word_D_8003A1D4, 3, 0};

//D:8003A1E8
struct prop_pos_data word_D_8003A1E8[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A206                     .half 0
//D:8003A208
struct item_related item_tank_related = {5, 0, word_D_8003A1E8, 0xF, 0};

//D:8003A214
struct prop_pos_data word_D_8003A214[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21A                     .half 0
//D:8003A21C
struct item_related item_hat_related = {1, 0, word_D_8003A214, 0, 0};
const u8 spacer_string[] = "\00\00\00\00\00\00\00\00";
//D:8003A228                     .globl PitemZ_entries
struct p_itementry PitemZ_entries[] = {
    {&Palarm1z_header, "Palarm1Z", 0.1},
    {&Palarm2Z_header, "Palarm2Z", 0.1},
    {&PexplosionbitZ_header, "PexplosionbitZ", 0.1},
    {&Pammo_crate1Z_header, "Pammo_crate1Z", 0.1},
    {&Pammo_crate2Z_header, "Pammo_crate2Z", 0.1},
    {&Pammo_crate3Z_header, "Pammo_crate3Z", 0.1},
    {&Pammo_crate4Z_header, "Pammo_crate4Z", 0.1},
    {&Pammo_crate5Z_header, "Pammo_crate5Z", 0.1},
    {&Pbin1Z_header, "Pbin1Z", 0.1},
    {&Pblotter1Z_header, "Pblotter1Z", 0.1},
    {&Pbook1Z_header, "Pbook1Z", 0.1},
    {&Pbookshelf1Z_header, "Pbookshelf1Z", 0.1},
    {&Pbridge_console1aZ_header, "Pbridge_console1aZ", 0.1},
    {&Pbridge_console1bZ_header, "Pbridge_console1bZ", 0.1},
    {&Pbridge_console2aZ_header, "Pbridge_console2aZ", 0.1},
    {&Pbridge_console2bZ_header, "Pbridge_console2bZ", 0.1},
    {&Pbridge_console3aZ_header, "Pbridge_console3aZ", 0.1},
    {&Pbridge_console3bZ_header, "Pbridge_console3bZ", 0.1},
    {&Pcard_box1Z_header, "Pcard_box1Z", 0.1},
    {&Pcard_box2Z_header, "Pcard_box2Z", 0.1},
    {&Pcard_box3Z_header, "Pcard_box3Z", 0.1},
    {&Pcard_box4_lgZ_header, "Pcard_box4_lgZ", 0.1},
    {&Pcard_box5_lgZ_header, "Pcard_box5_lgZ", 0.1},
    {&Pcard_box6_lgZ_header, "Pcard_box6_lgZ", 0.1},
    {&PcctvZ_header, "PcctvZ", 0.1},
    {&Pconsole1Z_header, "Pconsole1Z", 0.1},
    {&Pconsole2Z_header, "Pconsole2Z", 0.1},
    {&Pconsole3Z_header, "Pconsole3Z", 0.1},
    {&Pconsole_sevaZ_header, "Pconsole_sevaZ", 0.1},
    {&Pconsole_sevbZ_header, "Pconsole_sevbZ", 0.1},
    {&Pconsole_sevcZ_header, "Pconsole_sevcZ", 0.1},
    {&Pconsole_sevdZ_header, "Pconsole_sevdZ", 0.1},
    {&Pconsole_sev2aZ_header, "Pconsole_sev2aZ", 0.1},
    {&Pconsole_sev2bZ_header, "Pconsole_sev2bZ", 0.1},
    {&Pconsole_sev2cZ_header, "Pconsole_sev2cZ", 0.1},
    {&Pconsole_sev2dZ_header, "Pconsole_sev2dZ", 0.1},
    {&Pconsole_sev_GEaZ_header, "Pconsole_sev_GEaZ", 0.1},
    {&Pconsole_sev_GEbZ_header, "Pconsole_sev_GEbZ", 0.1},
    {&Pdesk1Z_header, "Pdesk1Z", 0.1},
    {&Pdesk2Z_header, "Pdesk2Z", 0.1},
    {&Pdesk_lamp2Z_header, "Pdesk_lamp2Z", 0.1},
    {&Pdisc_readerZ_header, "Pdisc_readerZ", 0.1},
    {&Pdisk_drive1Z_header, "Pdisk_drive1Z", 0.1},
    {&Pfiling_cabinet1Z_header, "Pfiling_cabinet1Z", 0.1},
    {&Pjerry_can1Z_header, "Pjerry_can1Z", 0.1},
    {&Pkeyboard1Z_header, "Pkeyboard1Z", 0.1},
    {&Pkit_units1Z_header, "Pkit_units1Z", 0.1},
    {&Pletter_tray1Z_header, "Pletter_tray1Z", 0.1},
    {&Pmainframe1Z_header, "Pmainframe1Z", 0.1},
    {&Pmainframe2Z_header, "Pmainframe2Z", 0.1},
    {&Pmetal_chair1Z_header, "Pmetal_chair1Z", 0.1},
    {&Pmetal_crate1Z_header, "Pmetal_crate1Z", 0.1},
    {&Pmetal_crate2Z_header, "Pmetal_crate2Z", 0.1},
    {&Pmetal_crate3Z_header, "Pmetal_crate3Z", 0.1},
    {&Pmetal_crate4Z_header, "Pmetal_crate4Z", 0.1},
    {&Pmissile_rackZ_header, "Pmissile_rackZ", 0.1},
    {&Pmissile_rack2Z_header, "Pmissile_rack2Z", 0.1},
    {&Poil_drum1Z_header, "Poil_drum1Z", 0.1},
    {&Poil_drum2Z_header, "Poil_drum2Z", 0.1},
    {&Poil_drum3Z_header, "Poil_drum3Z", 0.1},
    {&Poil_drum5Z_header, "Poil_drum5Z", 0.1},
    {&Poil_drum6Z_header, "Poil_drum6Z", 0.1},
    {&Poil_drum7Z_header, "Poil_drum7Z", 0.1},
    {&PpadlockZ_header, "PpadlockZ", 0.1},
    {&Pphone1Z_header, "Pphone1Z", 0.1},
    {&Pradio_unit1Z_header, "Pradio_unit1Z", 0.1},
    {&Pradio_unit2Z_header, "Pradio_unit2Z", 0.1},
    {&Pradio_unit3Z_header, "Pradio_unit3Z", 0.1},
    {&Pradio_unit4Z_header, "Pradio_unit4Z", 0.1},
    {&Psat1_reflectZ_header, "Psat1_reflectZ", 0.1},
    {&PsatdishZ_header, "PsatdishZ", 0.1},
    {&PsatboxZ_header, "PsatboxZ", 0.1},
    {&Pstool1Z_header, "Pstool1Z", 0.1},
    {&Pswivel_chair1Z_header, "Pswivel_chair1Z", 0.1},
    {&Ptorpedo_rackZ_header, "Ptorpedo_rackZ", 0.1},
    {&Ptv1Z_header, "Ptv1Z", 0.1},
    {&Ptv_holderZ_header, "Ptv_holderZ", 0.1},
    {&PtvscreenZ_header, "PtvscreenZ", 0.1},
    {&Ptv4screenZ_header, "Ptv4screenZ", 0.1},
    {&Pwood_lg_crate1Z_header, "Pwood_lg_crate1Z", 0.1},
    {&Pwood_lg_crate2Z_header, "Pwood_lg_crate2Z", 0.1},
    {&Pwood_md_crate3Z_header, "Pwood_md_crate3Z", 0.1},
    {&Pwood_sm_crate4Z_header, "Pwood_sm_crate4Z", 0.1},
    {&Pwood_sm_crate5Z_header, "Pwood_sm_crate5Z", 0.1},
    {&Pwood_sm_crate6Z_header, "Pwood_sm_crate6Z", 0.1},
    {&Pwooden_table1Z_header, "Pwooden_table1Z", 0.1},
    {&Pswipe_card2Z_header, "Pswipe_card2Z", 0.1},
    {&Pborg_crateZ_header, "Pborg_crateZ", 0.1},
    {&Pboxes4x4Z_header, "Pboxes4x4Z", 0.1},
    {&Pboxes3x4Z_header, "Pboxes3x4Z", 0.1},
    {&Pboxes2x4Z_header, "Pboxes2x4Z", 0.1},
    {&Psec_panelZ_header, "Psec_panelZ", 0.1},
    {&PICBM_noseZ_header, "PICBM_noseZ", 0.1},
    {&PICBMZ_header, "PICBMZ", 0.1},
    {&Ptuning_console1Z_header, "Ptuning_console1Z", 0.1},
    {&Pdesk_arecibo1Z_header, "Pdesk_arecibo1Z", 0.1},
    {&Plocker3Z_header, "Plocker3Z", 0.1},
    {&Plocker4Z_header, "Plocker4Z", 0.1},
    {&ProofgunZ_header, "ProofgunZ", 0.1},
    {&Pdest_engineZ_header, "Pdest_engineZ", 0.1},
    {&Pdest_exocetZ_header, "Pdest_exocetZ", 0.1},
    {&Pdest_gunZ_header, "Pdest_gunZ", 0.1},
    {&Pdest_harpoonZ_header, "Pdest_harpoonZ", 0.1},
    {&Pdest_seawolfZ_header, "Pdest_seawolfZ", 0.1},
    {&PwindowZ_header, "PwindowZ", 0.1},
    {&Pwindow_lib_lg1Z_header, "Pwindow_lib_lg1Z", 0.1},
    {&Pwindow_lib_sm1Z_header, "Pwindow_lib_sm1Z", 0.1},
    {&Pwindow_cor11Z_header, "Pwindow_cor11Z", 0.1},
    {&Pjungle3_treeZ_header, "Pjungle3_treeZ", 0.1},
    {&PpalmZ_header, "PpalmZ", 0.1},
    {&PpalmtreeZ_header, "PpalmtreeZ", 0.1},
    {&Pplant2bZ_header, "Pplant2bZ", 0.1},
    {&PlabbenchZ_header, "PlabbenchZ", 0.1},
    {&PgasbarrelZ_header, "PgasbarrelZ", 0.1},
    {&PgasbarrelsZ_header, "PgasbarrelsZ", 0.1},
    {&PbodyarmourZ_header, "PbodyarmourZ", 0.1},
    {&PbodyarmourvestZ_header, "PbodyarmourvestZ", 0.1},
    {&PgastankZ_header, "PgastankZ", 0.1},
    {&Pglassware1Z_header, "Pglassware1Z", 0.1},
    {&PhatchboltZ_header, "PhatchboltZ", 0.1},
    {&PbrakeunitZ_header, "PbrakeunitZ", 0.1},
    {&Pak47magZ_header, "Pak47magZ", 0.1},
    {&Pm16magZ_header, "Pm16magZ", 0.1},
    {&Pmp5kmagZ_header, "Pmp5kmagZ", 0.1},
    {&PskorpionmagZ_header, "PskorpionmagZ", 0.1},
    {&PspectremagZ_header, "PspectremagZ", 0.1},
    {&PuzimagZ_header, "PuzimagZ", 0.1},
    {&PsilencerZ_header, "PsilencerZ", 0.1},
    {&PchrextinguisherZ_header, "PchrextinguisherZ", 0.1},
    {&PboxcartridgesZ_header, "PboxcartridgesZ", 0.1},
    {&Pfnp90magZ_header, "Pfnp90magZ", 0.1},
    {&PgoldenshellsZ_header, "PgoldenshellsZ", 0.1},
    {&PmagnumshellsZ_header, "PmagnumshellsZ", 0.1},
    {&PwppkmagZ_header, "PwppkmagZ", 0.1},
    {&Ptt33magZ_header, "Ptt33magZ", 0.1},
    {&Psev_doorZ_header, "Psev_doorZ", 1.0},
    {&Psev_door3Z_header, "Psev_door3Z", 1.0},
    {&Psev_door3_windZ_header, "Psev_door3_windZ", 1.0},
    {&Psev_door4_windZ_header, "Psev_door4_windZ", 1.0},
    {&Psev_trislideZ_header, "Psev_trislideZ", 1.0},
    {&Psev_door_v1Z_header, "Psev_door_v1Z", 1.0},
    {&Psteel_door1Z_header, "Psteel_door1Z", 1.0},
    {&Psteel_door2Z_header, "Psteel_door2Z", 1.0},
    {&Psteel_door3Z_header, "Psteel_door3Z", 1.0},
    {&Psilo_lift_doorZ_header, "Psilo_lift_doorZ", 1.0},
    {&Psteel_door2bZ_header, "Psteel_door2bZ", 1.0},
    {&Pdoor_roller1Z_header, "Pdoor_roller1Z", 1.0},
    {&Pdoor_roller2Z_header, "Pdoor_roller2Z", 1.0},
    {&Pdoor_roller3Z_header, "Pdoor_roller3Z", 1.0},
    {&Pdoor_roller4Z_header, "Pdoor_roller4Z", 1.0},
    {&Pdoor_st_arec1Z_header, "Pdoor_st_arec1Z", 1.0},
    {&Pdoor_st_arec2Z_header, "Pdoor_st_arec2Z", 1.0},
    {&Pdoor_dest1Z_header, "Pdoor_dest1Z", 1.0},
    {&Pdoor_dest2Z_header, "Pdoor_dest2Z", 1.0},
    {&Pgas_plant_sw_do1Z_header, "Pgas_plant_sw_do1Z", 1.0},
    {&Pgas_plant_sw2_do1Z_header, "Pgas_plant_sw2_do1Z", 1.0},
    {&Pgas_plant_sw3_do1Z_header, "Pgas_plant_sw3_do1Z", 1.0},
    {&Pgas_plant_sw4_do1Z_header, "Pgas_plant_sw4_do1Z", 1.0},
    {&Pgas_plant_met1_do1Z_header, "Pgas_plant_met1_do1Z", 1.0},
    {&Pgas_plant_wc_cub1Z_header, "Pgas_plant_wc_cub1Z", 1.0},
    {&Pgasplant_clear_doorZ_header, "Pgasplant_clear_doorZ", 1.0},
    {&Ptrain_doorZ_header, "Ptrain_doorZ", 1.0},
    {&Ptrain_door2Z_header, "Ptrain_door2Z", 1.0},
    {&Ptrain_door3Z_header, "Ptrain_door3Z", 1.0},
    {&Pdoor_eyelidZ_header, "Pdoor_eyelidZ", 1.0},
    {&Pdoor_irisZ_header, "Pdoor_irisZ", 1.0},
    {&PsevdoorwoodZ_header, "PsevdoorwoodZ", 1.0},
    {&PsevdoorwindZ_header, "PsevdoorwindZ", 1.0},
    {&PsevdoornowindZ_header, "PsevdoornowindZ", 1.0},
    {&PsevdoormetslideZ_header, "PsevdoormetslideZ", 1.0},
    {&Pcryptdoor1aZ_header, "Pcryptdoor1aZ", 1.0},
    {&Pcryptdoor1bZ_header, "Pcryptdoor1bZ", 1.0},
    {&Pcryptdoor2aZ_header, "Pcryptdoor2aZ", 1.0},
    {&Pcryptdoor2bZ_header, "Pcryptdoor2bZ", 1.0},
    {&Pcryptdoor3Z_header, "Pcryptdoor3Z", 1.0},
    {&Pcryptdoor4Z_header, "Pcryptdoor4Z", 1.0},
    {&PvertdoorZ_header, "PvertdoorZ", 1.0},
    {&PhatchdoorZ_header, "PhatchdoorZ", 1.0},
    {&PdamgatedoorZ_header, "PdamgatedoorZ", 1.0},
    {&PdamtundoorZ_header, "PdamtundoorZ", 1.0},
    {&PdamchaindoorZ_header, "PdamchaindoorZ", 1.0},
    {&PsilotopdoorZ_header, "PsilotopdoorZ", 1.0},
    {&Pdoorprison1Z_header, "Pdoorprison1Z", 1.0},
    {&PdoorstatgateZ_header, "PdoorstatgateZ", 1.0},
    {&PchrkalashZ_header, "PchrkalashZ", 0.1},
    {&PchrgrenadelaunchZ_header, "PchrgrenadelaunchZ", 0.1},
    {&PchrknifeZ_header, "PchrknifeZ", 0.1},
    {&PchrlaserZ_header, "PchrlaserZ", 0.1},
    {&Pchrm16Z_header, "Pchrm16Z", 0.1},
    {&Pchrmp5kZ_header, "Pchrmp5kZ", 0.1},
    {&PchrrugerZ_header, "PchrrugerZ", 0.1},
    {&PchrwppkZ_header, "PchrwppkZ", 0.1},
    {&PchrshotgunZ_header, "PchrshotgunZ", 0.1},
    {&PchrskorpionZ_header, "PchrskorpionZ", 0.1},
    {&PchrspectreZ_header, "PchrspectreZ", 0.1},
    {&PchruziZ_header, "PchruziZ", 0.1},
    {&PchrgrenadeZ_header, "PchrgrenadeZ", 0.1},
    {&Pchrfnp90Z_header, "Pchrfnp90Z", 0.1},
    {&PchrbriefcaseZ_header, "PchrbriefcaseZ", 0.1},
    {&PchrremotemineZ_header, "PchrremotemineZ", 0.1},
    {&PchrproximitymineZ_header, "PchrproximitymineZ", 0.1},
    {&PchrtimedmineZ_header, "PchrtimedmineZ", 0.1},
    {&PchrrocketZ_header, "PchrrocketZ", 0.1},
    {&PchrgrenaderoundZ_header, "PchrgrenaderoundZ", 0.1},
    {&PchrwppksilZ_header, "PchrwppksilZ", 0.1},
    {&Pchrtt33Z_header, "Pchrtt33Z", 0.1},
    {&Pchrmp5ksilZ_header, "Pchrmp5ksilZ", 0.1},
    {&PchrautoshotZ_header, "PchrautoshotZ", 0.1},
    {&PchrgoldenZ_header, "PchrgoldenZ", 0.1},
    {&PchrthrowknifeZ_header, "PchrthrowknifeZ", 0.1},
    {&PchrsniperrifleZ_header, "PchrsniperrifleZ", 0.1},
    {&PchrrocketlaunchZ_header, "PchrrocketlaunchZ", 0.1},
    {&PhatfurryZ_header, "PhatfurryZ", 0.1},
    {&PhatfurrybrownZ_header, "PhatfurrybrownZ", 0.1},
    {&PhatfurryblackZ_header, "PhatfurryblackZ", 0.1},
    {&PhattbirdZ_header, "PhattbirdZ", 0.1},
    {&PhattbirdbrownZ_header, "PhattbirdbrownZ", 0.1},
    {&PhathelmetZ_header, "PhathelmetZ", 0.1},
    {&PhathelmetgreyZ_header, "PhathelmetgreyZ", 0.1},
    {&PhatmoonZ_header, "PhatmoonZ", 0.1},
    {&PhatberetZ_header, "PhatberetZ", 0.1},
    {&PhatberetblueZ_header, "PhatberetblueZ", 0.1},
    {&PhatberetredZ_header, "PhatberetredZ", 0.1},
    {&PhatpeakedZ_header, "PhatpeakedZ", 0.1},
    {&PchrwristdartZ_header, "PchrwristdartZ", 0.1},
    {&PchrexplosivepenZ_header, "PchrexplosivepenZ", 0.1},
    {&PchrbombcaseZ_header, "PchrbombcaseZ", 0.1},
    {&PchrflarepistolZ_header, "PchrflarepistolZ", 0.1},
    {&PchrpitongunZ_header, "PchrpitongunZ", 0.1},
    {&PchrfingergunZ_header, "PchrfingergunZ", 0.1},
    {&PchrsilverwppkZ_header, "PchrsilverwppkZ", 0.1},
    {&PchrgoldwppkZ_header, "PchrgoldwppkZ", 0.1},
    {&PchrdynamiteZ_header, "PchrdynamiteZ", 0.1},
    {&PchrbungeeZ_header, "PchrbungeeZ", 0.1},
    {&PchrdoordecoderZ_header, "PchrdoordecoderZ", 0.1},
    {&PchrbombdefuserZ_header, "PchrbombdefuserZ", 0.1},
    {&PchrbugdetectorZ_header, "PchrbugdetectorZ", 0.1},
    {&PchrsafecrackercaseZ_header, "PchrsafecrackercaseZ", 0.1},
    {&PchrcameraZ_header, "PchrcameraZ", 0.1},
    {&PchrlockexploderZ_header, "PchrlockexploderZ", 0.1},
    {&PchrdoorexploderZ_header, "PchrdoorexploderZ", 0.1},
    {&PchrkeyanalysercaseZ_header, "PchrkeyanalysercaseZ", 0.1},
    {&PchrweaponcaseZ_header, "PchrweaponcaseZ", 0.1},
    {&PchrkeyyaleZ_header, "PchrkeyyaleZ", 0.1},
    {&PchrkeyboltZ_header, "PchrkeyboltZ", 0.1},
    {&PchrbugZ_header, "PchrbugZ", 0.1},
    {&PchrmicrocameraZ_header, "PchrmicrocameraZ", 0.1},
    {&PfloppyZ_header, "PfloppyZ", 0.1},
    {&PchrgoldeneyekeyZ_header, "PchrgoldeneyekeyZ", 0.1},
    {&PchrpolarizedglassesZ_header, "PchrpolarizedglassesZ", 0.1},
    {&PchrcreditcardZ_header, "PchrcreditcardZ", 0.1},
    {&PchrdarkglassesZ_header, "PchrdarkglassesZ", 0.1},
    {&PchrgaskeyringZ_header, "PchrgaskeyringZ", 0.1},
    {&PchrdatathiefZ_header, "PchrdatathiefZ", 0.1},
    {&PsafeZ_header, "PsafeZ", 0.1},
    {&PbombZ_header, "PbombZ", 0.1},
    {&PchrplansZ_header, "PchrplansZ", 0.1},
    {&PchrspyfileZ_header, "PchrspyfileZ", 0.1},
    {&PchrblueprintsZ_header, "PchrblueprintsZ", 0.1},
    {&PchrcircuitboardZ_header, "PchrcircuitboardZ", 0.1},
    {&PchrmapZ_header, "PchrmapZ", 0.1},
    {&PchrspooltapeZ_header, "PchrspooltapeZ", 0.1},
    {&PchraudiotapeZ_header, "PchraudiotapeZ", 0.1},
    {&PchrmicrofilmZ_header, "PchrmicrofilmZ", 0.1},
    {&PchrmicrocodeZ_header, "PchrmicrocodeZ", 0.1},
    {&PchrlectreZ_header, "PchrlectreZ", 0.1},
    {&PchrmoneyZ_header, "PchrmoneyZ", 0.1},
    {&PchrgoldbarZ_header, "PchrgoldbarZ", 0.1},
    {&PchrheroinZ_header, "PchrheroinZ", 0.1},
    {&PchrclipboardZ_header, "PchrclipboardZ", 0.1},
    {&PchrdossierredZ_header, "PchrdossierredZ", 0.1},
    {&PchrstafflistZ_header, "PchrstafflistZ", 0.1},
    {&PchrdattapeZ_header, "PchrdattapeZ", 0.1},
    {&PchrplastiqueZ_header, "PchrplastiqueZ", 0.1},
    {&PchrblackboxZ_header, "PchrblackboxZ", 0.1},
    {&PchrvideotapeZ_header, "PchrvideotapeZ", 0.1},
    {&PnintendologoZ_header, "PnintendologoZ", 0.1},
    {&PgoldeneyelogoZ_header, "PgoldeneyelogoZ", 0.1},
    {&PwalletbondZ_header, "PwalletbondZ", 0.1},
    {&PmiltruckZ_header, "PmiltruckZ", 0.1},
    {&PjeepZ_header, "PjeepZ", 0.1},
    {&ParticZ_header, "ParticZ", 0.1},
    {&PhelicopterZ_header, "PhelicopterZ", 0.1},
    {&PtigerZ_header, "PtigerZ", 0.1},
    {&PmilcopterZ_header, "PmilcopterZ", 0.1},
    {&PhindZ_header, "PhindZ", 0.1},
    {&PartictrailerZ_header, "PartictrailerZ", 0.1},
    {&PmotorbikeZ_header, "PmotorbikeZ", 0.1},
    {&PtankZ_header, "PtankZ", 0.1},
    {&PapcZ_header, "PapcZ", 0.1},
    {&PspeedboatZ_header, "PspeedboatZ", 0.1},
    {&PplaneZ_header, "PplaneZ", 0.1},
    {&Pgun_runway1Z_header, "Pgun_runway1Z", 0.1},
    {&PsafedoorZ_header, "PsafedoorZ", 1.0},
    {&Pkey_holderZ_header, "Pkey_holderZ", 1.0},
    {&PhatchsevxZ_header, "PhatchsevxZ", 1.0},
    {&PsevdishZ_header, "PsevdishZ", 1.0},
    {&Parchsecdoor1Z_header, "Parchsecdoor1Z", 1.0},
    {&Parchsecdoor2Z_header, "Parchsecdoor2Z", 1.0},
    {&PgroundgunZ_header, "PgroundgunZ", 0.1},
    {&PtrainextdoorZ_header, "PtrainextdoorZ", 1.0},
    {&PcarbmwZ_header, "PcarbmwZ", 0.1},
    {&PcarescortZ_header, "PcarescortZ", 0.1},
    {&PcargolfZ_header, "PcargolfZ", 0.1},
    {&PcarweirdZ_header, "PcarweirdZ", 0.1},
    {&PcarzilZ_header, "PcarzilZ", 0.1},
    {&Pshuttle_door_lZ_header, "Pshuttle_door_lZ", 1.0},
    {&Pshuttle_door_rZ_header, "Pshuttle_door_rZ", 1.0},
    {&Pdepot_gate_entryZ_header, "Pdepot_gate_entryZ", 0.1},
    {&Pdepot_door_steelZ_header, "Pdepot_door_steelZ", 0.1},
    {&Pglassware2Z_header, "Pglassware2Z", 0.1},
    {&Pglassware3Z_header, "Pglassware3Z", 0.1},
    {&Pglassware4Z_header, "Pglassware4Z", 0.1},
    {&PlandmineZ_header, "PlandmineZ", 0.1},
    {&Pplant1Z_header, "Pplant1Z", 0.1},
    {&Pplant11Z_header, "Pplant11Z", 0.1},
    {&Pplant2Z_header, "Pplant2Z", 0.1},
    {&Pplant3Z_header, "Pplant3Z", 0.1},
    {&Pjungle5_treeZ_header, "Pjungle5_treeZ", 0.1},
    {&PlegalpageZ_header, "PlegalpageZ", 0.1},
    {&Pst_pete_room_1iZ_header, "Pst_pete_room_1iZ", 0.1},
    {&Pst_pete_room_2iZ_header, "Pst_pete_room_2iZ", 0.1},
    {&Pst_pete_room_3tZ_header, "Pst_pete_room_3tZ", 0.1},
    {&Pst_pete_room_5cZ_header, "Pst_pete_room_5cZ", 0.1},
    {&Pst_pete_room_6cZ_header, "Pst_pete_room_6cZ", 0.1},
    {&Pdoor_rollertrainZ_header, "Pdoor_rollertrainZ", 1.0},
    {&Pdoor_winZ_header, "Pdoor_winZ", 1.0},
    {&Pdoor_aztecZ_header, "Pdoor_aztecZ", 1.0},
    {&PshuttleZ_header, "PshuttleZ", 0.1},
    {&Pdoor_azt_deskZ_header, "Pdoor_azt_deskZ", 1.0},
    {&Pdoor_azt_desk_topZ_header, "Pdoor_azt_desk_topZ", 1.0},
    {&Pdoor_azt_chairZ_header, "Pdoor_azt_chairZ", 1.0},
    {&Pdoor_mfZ_header, "Pdoor_mfZ", 1.0},
    {&PflagZ_header, "PflagZ", 0.1},
    {&PbarricadeZ_header, "PbarricadeZ", 0.1},
    {&PmodemboxZ_header, "PmodemboxZ", 0.1},
    {&PdoorpanelZ_header, "PdoorpanelZ", 0.1},
    {&PdoorconsoleZ_header, "PdoorconsoleZ", 0.1},
    {&PchrtesttubeZ_header, "PchrtesttubeZ", 0.1},
    {&Pbollardz_header, "PbollardZ", 0.1},
    {0, "", 1.0}
};

//D:8003b224
u32 object_explosion_details[] = {
    0x0006315c, 0x7b6cdbff, 0x5126fb59, 0x7ca70006,
    0x2afecb3e, 0x73f4278f, 0x6d3a44c8, 0x00050000,
    0x00000000, 0x00000000, 0x0000000b, 0xb9b03eba,
    0xad6275c8, 0xb70ff06e, 0x000b17d9, 0xdfcc57cd,
    0x82547345, 0xe011000b, 0x3779ed72, 0x688df67b,
    0x37e54f89, 0x000be277, 0x0474dd1e, 0x0c48486c,
    0xf87d000b, 0x7c3f16bc, 0x44a91a58, 0xe4129297,
    0x00003dc2, 0x16b6e30d, 0xbcabc592, 0xf9b50002,
    0x719c7024, 0x9ee0c175, 0xa5ddc933, 0x00028e16,
    0xbbca05c0, 0x1a7381be, 0xf8210000, 0x00000000,
    0x00000000, 0x00000000, 0x00082716, 0xf5440d35,
    0xc20e83d7, 0x7d730008, 0x81a1b772, 0x1b57437a,
    0x85fab6c1, 0x000827eb, 0x5a7abd1a, 0x27eb5a7a,
    0xbd1a0008, 0x98de8c36, 0xddd5f74b, 0x4f0a1f14,
    0x000834f5, 0xf199a9f2, 0x3d27c707, 0xb9ad0008,
    0x678fdb91, 0x2a2e8d91, 0x6eee925e, 0x0004d82f,
    0xf4d7546f, 0xd6c787d9, 0x01430004, 0x100eadf2,
    0x1fdd45f1, 0x4772f8c6, 0x0004ef0b, 0x71bbb7f7,
    0xbfa303b8, 0xe44e0004, 0xdfd1676a, 0x8597e8ac,
    0xe2109a4d, 0x0004ab48, 0xdd9b4343, 0x04b80dcc,
    0x3b3d0004, 0x836b6bbf, 0x9dbb3db7, 0x59577341,
    0x00070000, 0x00000000, 0x00000000, 0x00000009,
    0xb1cc19e2, 0x0ea5b1cc, 0x19e20ea5, 0x0009f093,
    0xb2df1409, 0x271ee0b3, 0x418a0009, 0x3ac20102,
    0xbf013ac2, 0x0102bf01, 0x00093ac6, 0xe449a56e,
    0xa4cfeda0, 0x17190009, 0x9bcfc333, 0x63844298,
    0xd4557bfa, 0x0009839e, 0x0ba71466, 0xdb6dd1b3,
    0x12330009, 0x3f677a70, 0x83de7052, 0x07d236ff,
    0x0009a409, 0x692de286, 0xc63c82d0, 0x5d070009,
    0xd6ca1866, 0x839cbc6a, 0x86ad4dc6, 0x000996fc,
    0xa1efa9e6, 0xb9d2a3c5, 0xa0450009, 0x7d2be7dc,
    0x55db378e, 0x4765b09c, 0x0009e2af, 0x2d4371fe,
    0xe39093b3, 0x57e30009, 0x9367098a, 0x3b68d6f8,
    0x4eaf7b83, 0x000f0000, 0x00000000, 0x00000000,
    0x0000000f, 0x00000000, 0x00000000, 0x00000000,
    0x0007993d, 0xa2b25028, 0x825e25b8, 0xd8ef0006,
    0x6553024d, 0xfd22d469, 0x18e432f6, 0x0006f742,
    0x0cb58ed2, 0x60216ad5, 0xaa880004, 0x06d882ef,
    0x5b194147, 0x5ae1374e, 0x0004284d, 0x3e7c9330,
    0xcf1e013f, 0x4e290006, 0xe339c0b6, 0xe5fc7054,
    0x83a8c118, 0x0004b49f, 0x00024ef6, 0x88490002,
    0x070b0002, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x000979b2, 0xbc78b9b9, 0xc76a97a1, 0x3da30009,
    0x3292ddc3, 0x926512a6, 0xe935b9bc, 0x000304db,
    0x3cfddb5c, 0x3b2950b7, 0x83d10004, 0xbe6408ad,
    0x150d6aed, 0x542e63b3, 0x0004d7e5, 0x13695acc,
    0x535a2105, 0x1bf70004, 0x72223cee, 0x1a15122a,
    0xadec5ef3, 0x0004927f, 0x10b05125, 0x7f4ebbc5,
    0x8088000b, 0xe89d7502, 0x9003469d, 0x19f0a5e6,
    0x000b3771, 0xc00280ff, 0xdbf61705, 0x497a000e,
    0xa954afde, 0xbb6cd4a6, 0x9883fa27, 0x000ede9f,
    0xcef06346, 0x80fba382, 0x14d1000e, 0x448ed4cc,
    0xc1b5442f, 0xc1d1ee05, 0x000ec7c0, 0xf918095e,
    0xece206d4, 0xc64d000e, 0xc49116ec, 0xdea75a19,
    0x9de7ff28, 0x000ee889, 0x2da62775, 0x153cbae6,
    0xcb1b0000, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x0006e5e6, 0x8fb7d5fe, 0xe959d656, 0xfb820007,
    0x58763a4f, 0xd115a10d, 0x265d2c02, 0x0007787e,
    0xc128d96a, 0x60c918e7, 0x99ad0007, 0x879a90e4,
    0xc20f35fe, 0xc80791d8, 0x000740ae, 0x62b6d240,
    0xac8d47c5, 0x17d10000, 0x00000000, 0x00000000,
    0x00000000, 0x000715c6, 0xb37d118a, 0x4e615d02,
    0x7d500006, 0x15c6b37d, 0x118a4e61, 0x5d027d50,
    0x00030000, 0x00000000, 0x00000000, 0x00000003,
    0x24698ae5, 0x524fe5f6, 0xbe4ac865, 0x00052957,
    0x1b2227c7, 0x96630ddf, 0x411f0007, 0x15c6b37d,
    0x118a4e61, 0x5d027d50, 0x00040000, 0x00000000,
    0x00000000, 0x00000006, 0xf8f4f1e0, 0x473f41dd,
    0xa510c9c6, 0x00080000, 0x00000000, 0x00000000,
    0x00000004, 0x7a512382, 0x9b3629e5, 0x5921017a,
    0x00048666, 0x3dd9e619, 0x6134cc94, 0x1a5c0004,
    0x7f3931c5, 0x9ac370ab, 0x0551b069, 0x0003d727,
    0x7ab2786b, 0xf5ad3fc4, 0xd6ce0003, 0x4548d59e,
    0x1edce88d, 0xe9e4af76, 0x0003262f, 0x491bfd57,
    0x6715e7ed, 0x2626000f, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0xbcae0bd1, 0x0ff73a30, 0x724083b7,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0xb2c6170a,
    0x0a236bbe, 0xb59382db, 0x0005275b, 0x8ad3002c,
    0x27b58ad3, 0x002c0005, 0x00000000, 0x00000000,
    0x00000000, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360004, 0x8c0678fc, 0x8f9a4df5, 0x4d5322f9,
    0x000399e9, 0x0107ef5e, 0x0560e6df, 0x4b360003,
    0x31e70023, 0xb2aea2d7, 0xe54090b2, 0x00080000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x000833a1, 0x8a014d42,
    0xd9cbb865, 0xb3360008, 0x33a18a01, 0x4d42d9cb,
    0xb865b336, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360008, 0x33a18a01, 0x4d42d9cb, 0xb865b336,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000c0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00030000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000006, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000004, 0x00000000, 0x00000000,
    0x00000000, 0x00040000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x00040000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000007, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000d, 0x00000000, 0x00000000,
    0x00000000, 0x000d0000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000006, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000009,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000ffff, 0xffffffff,
    0xffffffff, 0xffff0000, 0x00000000
};


//D:8003C4D0
struct prop_pos_data word_D_8003C4D0[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D6                     .half 0
//D:8003C4D8
struct item_related model_object_standard_object = {1, 0, word_D_8003C4D0, 3, 0};
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
struct prop_pos_data word_D_8003C4F0[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
struct item_related prop_weapon_related = {2, 0, word_D_8003C4F0, 0, 0};
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
struct prop_pos_data dword_D_8003C510[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027}
};


//item_related struct
//D:8003C570
struct item_related dword_D_8003C570 = {0x10, 0x0000, dword_D_8003C510, 0x2D, 0x0000};

//D:8003C57C
s32 D_8003C57C = 0;


//D:8003C580
struct player_gait_header player_gait_hdr = {0, 1, 0, &player_gait_obj, NULL, 0, 0, &player_gait_pos_hdr_1};
//D:8003C598
struct player_gait_pos_header player_gait_pos_hdr_1 = {0, 2, 0, &player_gait_pos_1, (struct player_gait_pos_header *)&player_gait_hdr, 0, 0, &player_gait_pos_hdr_2};
//D:8003C5B0
struct player_gait_pos_header player_gait_pos_hdr_2 = {0, 2, 0, &player_gait_pos_2, &player_gait_pos_hdr_1, 0, 0, &player_gait_pos_hdr_3};
//D:8003C5C8
struct player_gait_pos_header player_gait_pos_hdr_3 = {0, 2, 0, &player_gait_pos_3, &player_gait_pos_hdr_2, 0, 0, 0};
//D:8003C5E0
struct player_gait_object_entry player_gait_obj = {1, &player_gait_pos_hdr_1, 0, 0};
//D:8003C5F0
struct player_gait_position_entry player_gait_pos_1 = {0.0, 0.0, 0.0, 0x0001, 0x0002, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_2, 0};
//D:8003C60C
struct player_gait_position_entry player_gait_pos_2 = {1.177982, 41.14437, 0, 0x0002, 0x0003, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_3, 0};
//D:8003C628
struct player_gait_position_entry player_gait_pos_3 = {-2.576027, 480.42902, 0, 0x0003, 0x0000, 0xFFFF, 0xFFFF, NULL, 0};


//D:8003C644
s32 D_8003C644 = 0;
//D:8003C648
s32 D_8003C648 = 0;
//D:8003C64C
s32 D_8003C64C = 0;


//D:8003C650
struct object_header player_gait_object = {0, &dword_D_8003C570,0,0, 4, 41.16123,0,0,0,0};


//D:8003C670
struct prop_pos_data dword_D_8003C670[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027},
    {0x0015, 0x002D, 0x002D},
    {0x0015, 0x002E, 0x002E},
    {0x0015, 0x002F, 0x002F},
};

//D:8003C6E4
struct item_related model_suit_lf_hand = {0x13, 0x0000, dword_D_8003C670, 0x2D, 0x0000};

//D:8003C6F0
struct prop_pos_data dword_D_8003C6F0[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
struct item_related weapon_gun_standard_gun = {0x6, 0x0000, dword_D_8003C6F0, 0xF, 0x0000};

//D:8003C720
struct prop_pos_data dword_D_8003C720[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
struct item_related weapon_gun_unassigned = {0x1, 0x0000, dword_D_8003C720, 0x3, 0x0000};

//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
struct prop_pos_data dword_D_8003C740[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
struct item_related weapon_gun_revolver = {0x7, 0x0000, dword_D_8003C740, 0x15, 0x0000};

//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
struct prop_pos_data dword_D_8003C780[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
struct item_related weapon_gun_kf7 = {0x7, 0x0000, dword_D_8003C780, 0x12, 0x0000};

//D:8003C7B8
s32 D_8003C7B8 = 0;
//D:8003C7BC
s32 D_8003C7BC = 0;

//D:8003C7C0
struct Gitemheader GwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xC, 0, 0};
//D:8003C7E0
struct Gitemheader GwppksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.66476, 0, 0xC, 0, 0};
//D:8003C800
struct Gitemheader Gtt33Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.16788, 0, 0xF, 0, 0};
//D:8003C820
struct Gitemheader GskorpianZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 390.40039, 0, 0xC, 0, 0};
//D:8003C840
struct Gitemheader Gak47Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 941.9339, 0, 0x12, 0, 0};
//D:8003C860
struct Gitemheader GuziZ_struct = {0, &weapon_gun_kf7, 0, 0x24, 5, 436.95404, 0, 0xC, 0, 0};
//D:8003C880
struct Gitemheader Gmp5kZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 499.24536, 0, 9, 0, 0};
//D:8003C8A0
struct Gitemheader Gmp5ksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 655.97717, 0, 9, 0, 0};
//D:8003C8C0
struct Gitemheader Gm16Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 1096.2413, 0, 8, 0, 0};
//D:8003C8E0
struct Gitemheader Gfnp90Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 460.81909, 0, 0xA, 0, 0};
//D:8003C900
struct Gitemheader G8003C900_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 238.62167, 0, 4, 0, 0};
//D:8003C920
struct Gitemheader GrugerZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 6, 553.44312, 0, 0xE, 0, 0};
//D:8003C940
struct Gitemheader GgoldengunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 5, 384.92172, 0, 0xB, 0, 0};
//D:8003C960
struct Gitemheader GshotgunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 4, 919.33038, 0, 0xD, 0, 0};
//D:8003C980
struct Gitemheader GautoshotZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 840.15125, 0, 0x10, 0, 0};
//D:8003C9A0
struct Gitemheader GgrenadelaunchZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 5, 768.33496, 0, 0xF, 0, 0};
//D:8003C9C0
struct Gitemheader GspectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 598.42865, 0, 0xB, 0, 0};
//D:8003C9E0
struct Gitemheader GlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 442.81848, 0, 0xD, 0, 0};
//D:8003CA00
struct Gitemheader GrocketlaunchZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 566.51208, 0, 0xA, 0, 0};
//D:8003CA20
struct Gitemheader GknifeZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 376.97263, 0, 9, 0, 0};
//D:8003CA40
struct Gitemheader GthrowknifeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 373.31387, 0, 9, 0, 0};
//D:8003CA60
struct Gitemheader GtaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 182.78622, 0, 0x11, 0, 0};
//D:8003CA80
struct Gitemheader GremotemineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 50.999378, 0, 3, 0, 0};
//D:8003CAA0
struct Gitemheader GproximitymineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 51.00029, 0, 3, 0, 0};
//D:8003CAC0
struct Gitemheader GtimedmineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 49.368877, 0, 4, 0, 0};
//D:8003CAE0
struct Gitemheader GtriggerZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003CB00
struct Gitemheader GgrenadeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 427.27081, 0, 5, 0, 0};
//D:8003CB20
struct Gitemheader GfistZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 243.84764, 0, 0xE, 0, 0};
//D:8003CB40
struct Gitemheader GsniperrifleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 808.03253, 0, 7, 0, 0};
//D:8003CB60
struct Gitemheader GcartridgeZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 14.128822, 0, 2, 0, 0};
//D:8003CB80
struct Gitemheader GcartrifleZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBA0
struct Gitemheader GcartblueZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBC0
struct Gitemheader GcartshellZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 29.8451, 0, 2, 0, 0};
//D:8003CBE0
struct Gitemheader GjoypadZ_struct = {0, &weapon_gun_controller, 0, 0xE, 0xD, 523.96826, 0, 4, 0, 0};
//D:8003CC00
struct Gitemheader G8003CC00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC20
struct Gitemheader G8003CC20_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC40
struct Gitemheader GbombcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CC60
struct Gitemheader GflarepistolZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC80
struct Gitemheader GpitongunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCA0
struct Gitemheader G8003CCA0_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCC0
struct Gitemheader GsilverwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CCE0
struct Gitemheader GgoldwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CD00
struct Gitemheader G8003CD00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD20
struct Gitemheader GbungeeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD40
struct Gitemheader GdoordecoderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.850407, 0, 0x10, 0, 0};
//D:8003CD60
struct Gitemheader GbombdefuserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 84.370705, 0, 0xC, 0, 0};
//D:8003CD80
struct Gitemheader GbugdetectorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CDA0
struct Gitemheader GsafecrackercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CDC0
struct Gitemheader GcameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 52.775627, 0, 0xB, 0, 0};
//D:8003CDE0
struct Gitemheader GlockexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE00
struct Gitemheader GdoorexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE20
struct Gitemheader GkeyanalysercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE40
struct Gitemheader GweaponcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE60
struct Gitemheader GkeycardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 123.088844, 0, 2, 0, 0};
//D:8003CE80
struct Gitemheader GkeyyaleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 414.25156, 0, 1, 0, 0};
//D:8003CEA0
struct Gitemheader GkeyboltZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 759.26581, 0, 1, 0, 0};
//D:8003CEC0
struct Gitemheader GbugZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 106.2163, 0, 6, 0, 0};
//D:8003CEE0
struct Gitemheader GmicrocameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 70.039436, 0, 7, 0, 0};
//D:8003CF00
struct Gitemheader GexplosivefloppyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.902443, 0, 5, 0, 0};
//D:8003CF20
struct Gitemheader GgoldeneyekeyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 98.987083, 0, 5, 0, 0};
//D:8003CF40
struct Gitemheader GpolarizedglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 53.776386, 0, 2, 0, 0};
//D:8003CF60
struct Gitemheader GcreditcardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CF80
struct Gitemheader GdarkglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CFA0
struct Gitemheader GwatchidentifierZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFC0
struct Gitemheader GwatchcommunicatorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFE0
struct Gitemheader GwatchlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003D000
struct Gitemheader GwatchgeigercounterZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D020
struct Gitemheader GwatchmagnetrepelZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D040
struct Gitemheader GwatchmagnetattractZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1D, 3, 384.9288, 0, 9, 0, 0};
//D:8003D060
struct Gitemheader GgaskeyringZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 111.59859, 0, 9, 0, 0};
//D:8003D080
struct Gitemheader GdatathiefZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 119.78231, 0, 3, 0, 0};
//D:8003D0A0
struct Gitemheader GbriefcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003D0C0
struct Gitemheader GblackboxZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 128.31796, 0, 5, 0, 0};
//D:8003D0E0
struct Gitemheader GplastiqueZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 255.35242, 0, 3, 0, 0};
//D:8003D100
struct Gitemheader GvideotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 122.69632, 0, 9, 0, 0};
//D:8003D120
struct Gitemheader GclipboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 190.41742, 0, 3, 0, 0};
//D:8003D140
struct Gitemheader GstafflistZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 215.17534, 0, 4, 0, 0};
//D:8003D160
struct Gitemheader GdossierredZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 183.54231, 0, 4, 0, 0};
//D:8003D180
struct Gitemheader GaudiotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 97.531075, 0, 9, 0, 0};
//D:8003D1A0
struct Gitemheader GdattapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 79.868584, 0, 4, 0, 0};
//D:8003D1C0
struct Gitemheader GplansZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 81.950996, 0, 5, 0, 0};
//D:8003D1E0
struct Gitemheader GspyfileZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D200
struct Gitemheader GblueprintsZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 125.3834, 0, 4, 0, 0};
//D:8003D220
struct Gitemheader GcircuitboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 138.90285, 0, 3, 0, 0};
//D:8003D240
struct Gitemheader GmapZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 125.3834, 0, 4, 0, 0};
//D:8003D260
struct Gitemheader GspooltapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D280
struct Gitemheader GmicrofilmZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2A0
struct Gitemheader GmicrocodeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2C0
struct Gitemheader GlectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2E0
struct Gitemheader GmoneyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D300
struct Gitemheader GgoldbarZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D320
struct Gitemheader GheroinZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};

//D:8003D340
u32 dword_D_8003D340[] = {0x20000,         2,   0x30003,   0x20006,
                          0x60002,   0x90009,   0x2000C,   0xC0002,
                          0xF000F,   0x20012,  0x120002,  0x150015,
                          0x20018,  0x180002,  0x1B001B,   0x2001E,
                          0x1E0002,  0x210021,   0x20024,  0x240000};

//D:8003D390
struct model_data weapon_gun_controller = {0xD0000, dword_D_8003D340, 0x270000};
//D:8003D39C
s32 D_8003D39C = 0;

u32 dword_D_8003D3A0[] = {0x4010000,         2,         0,   0x20003,
                          0x30002,   0x60006,   0x20009,   0xC0002,
                          0xC0009,   0x2000F,  0x120002,  0x12000F,
                          0x20015,  0x180002,  0x180015,   0x2001B,
                          0x1E0002,  0x1E001B,   0x20021,  0x240002,
                          0x240021,   0x20027,  0x2A0002,  0x2A0027};


//D:8003D400
     struct model_data model_guard_character = {0x100000, dword_D_8003D3A0, 0x2D0000};
//D:8003D40C
s32 D_8003D40C = 0;

//D:8003D410
struct object_header CcamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D430
struct object_header CgreyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xD, 0, 0};
//D:8003D450
struct object_header ColiveguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0x10, 0, 0};
//D:8003D470
struct object_header CrusguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xD, 0, 0};
//D:8003D490
struct object_header CtrevguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x12, 0, 0};
//D:8003D4B0
struct object_header CborisZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1223.1553, 0, 0x15, 0, 0};
//D:8003D4D0
struct object_header CorumovZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1347.004, 0, 0x15, 0, 0};
//D:8003D4F0
struct object_header CtrevelyanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D510
struct object_header CboilertrevZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D530
struct object_header CvalentinZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1208.6277, 0, 0x10, 0, 0};
//D:8003D550
struct object_header CxeniaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.4487, 0, 0x13, 0, 0};
//D:8003D570
struct object_header CbaronsamediZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.5995, 0, 0x19, 0, 0};
//D:8003D590
struct object_header CjawsZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1550.059, 0, 0x14, 0, 0};
//D:8003D5B0
struct object_header CmaydayZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.657, 0, 0x10, 0, 0};
//D:8003D5D0
struct object_header CoddjobZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1082.4603, 0, 0x12, 0, 0};
//D:8003D5F0
struct object_header CnatalyaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1226.1493, 0, 0x10, 0, 0};
//D:8003D610
struct object_header CarmourguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x11, 0, 0};
//D:8003D630
struct object_header CcommguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D650
struct object_header CgreatguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0xB, 0, 0};
//D:8003D670
struct object_header CnavyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D690
struct object_header CsnowguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1261.1731, 0, 0x11, 0, 0};
//D:8003D6B0
struct object_header CbluewomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1148.2167, 0, 0xD, 0, 0};
//D:8003D6D0
struct object_header CfattechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1149.4025, 0, 0xC, 0, 0};
//D:8003D6F0
struct object_header CtechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1158.2109, 0, 0xC, 0, 0};
//D:8003D710
struct object_header CjeanwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xF, 0, 0};
//D:8003D730
struct object_header CgreymanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1293.0195, 0, 0xF, 0, 0};
//D:8003D750
struct object_header CbluemanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D770
struct object_header CredmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D790
struct object_header CcardimanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xE, 0, 0};
//D:8003D7B0
struct object_header CcheckmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0x10, 0, 0};
//D:8003D7D0
struct object_header CtechmanZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xC, 0, 0};
//D:8003D7F0
struct object_header CpilotZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x18, 0, 0};
//D:8003D810
struct object_header Cgreatguard2Z_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0x10, 0, 0};
//D:8003D830
struct object_header CbluecamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D850
struct object_header CmoonguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0xD, 0, 0};
//D:8003D870
struct object_header CmoonfemaleZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xB, 0, 0};
//D:8003D890
struct object_header CboilerbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1273.6262, 0, 0xD, 0, 0};
//D:8003D8B0
struct object_header CsuitbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.3391, 0, 0xE, 0, 0};
//D:8003D8D0
struct object_header CtimberbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1282.7715, 0, 0x10, 0, 0};
//D:8003D8F0
struct object_header CsnowbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1299.1359, 0, 0xE, 0, 0};
//D:8003D910
struct object_header CdjbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.0543, 0, 0xD, 0, 0};
//D:8003D930
struct object_header Csuit_lf_handz_struct = {0, &model_suit_lf_hand, 0, 0xA, 9, 12231.949, 0, 0x16, 0, 0};
//D:8003D950
struct object_header CheadkarlZ_struct = {0, NULL, 0, 2, 1, 218.15375, 0, 6, 0, 0};
//D:8003D970
struct object_header CheadalanZ_struct = {0, NULL, 0, 2, 1, 215.03685, 0, 4, 0, 0};
//D:8003D990
struct object_header CheadpeteZ_struct = {0, NULL, 0, 2, 1, 216.28949, 0, 4, 0, 0};
//D:8003D9B0
struct object_header CheadmartinZ_struct = {0, NULL, 0, 2, 1, 222.34796, 0, 6, 0, 0};
//D:8003D9D0
struct object_header stru_D_8003D9D0 = {0, NULL, 0, 2, 1, 220.2446, 0, 5, 0, 0};
//D:8003D9F0
struct object_header stru_D_8003D9F0 = {0, NULL, 0, 2, 1, 201.51955, 0, 5, 0, 0};
//D:8003DA10
struct object_header stru_D_8003DA10 = {0, NULL, 0, 2, 1, 212.62949, 0, 5, 0, 0};
//D:8003DA30
struct object_header stru_D_8003DA30 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA50
struct object_header stru_D_8003DA50 = {0, NULL, 0, 2, 1, 192.53412, 0, 4, 0, 0};
//D:8003DA70
struct object_header stru_D_8003DA70 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA90
struct object_header stru_D_8003DA90 = {0, NULL, 0, 2, 1, 227.52234, 0, 4, 0, 0};
//D:8003DAB0
struct object_header stru_D_8003DAB0 = {0, NULL, 0, 2, 1, 228.29831, 0, 4, 0, 0};
//D:8003DAD0
struct object_header stru_D_8003DAD0 = {0, NULL, 0, 2, 1, 235.64778, 0, 6, 0, 0};
//D:8003DAF0
struct object_header stru_D_8003DAF0 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DB10
struct object_header stru_D_8003DB10 = {0, NULL, 0, 2, 1, 240.50017, 0, 4, 0, 0};
//D:8003DB30
struct object_header stru_D_8003DB30 = {0, NULL, 0, 2, 1, 234.83342, 0, 4, 0, 0};
//D:8003DB50
struct object_header stru_D_8003DB50 = {0, NULL, 0, 2, 1, 228.24614, 0, 4, 0, 0};
//D:8003DB70
struct object_header stru_D_8003DB70 = {0, NULL, 0, 2, 1, 228.55029, 0, 4, 0, 0};
//D:8003DB90
struct object_header stru_D_8003DB90 = {0, NULL, 0, 2, 1, 212.62949, 0, 2, 0, 0};
//D:8003DBB0
struct object_header stru_D_8003DBB0 = {0, NULL, 0, 2, 1, 219.82707, 0, 6, 0, 0};
//D:8003DBD0
struct object_header stru_D_8003DBD0 = {0, NULL, 0, 2, 1, 193.20615, 0, 5, 0, 0};
//D:8003DBF0
struct object_header stru_D_8003DBF0 = {0, NULL, 0, 2, 1, 235.64778, 0, 4, 0, 0};
//D:8003DC10
struct object_header stru_D_8003DC10 = {0, NULL, 0, 2, 1, 223.18559, 0, 4, 0, 0};
//D:8003DC30
struct object_header stru_D_8003DC30 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DC50
struct object_header stru_D_8003DC50 = {0, NULL, 0, 2, 1, 193.20615, 0, 4, 0, 0};
//D:8003DC70
struct object_header stru_D_8003DC70 = {0, NULL, 0, 2, 1, 235.64778, 0, 5, 0, 0};
//D:8003DC90
struct object_header stru_D_8003DC90 = {0, NULL, 0, 2, 1, 193.20615, 0, 3, 0, 0};
//D:8003DCB0
struct object_header stru_D_8003DCB0 = {0, NULL, 0, 2, 1, 224.83139, 0, 3, 0, 0};
//D:8003DCD0
struct object_header stru_D_8003DCD0 = {0, NULL, 0, 2, 1, 219.97256, 0, 3, 0, 0};
//D:8003DCF0
struct object_header stru_D_8003DCF0 = {0, NULL, 0, 2, 1, 203.44904, 0, 3, 0, 0};
//D:8003DD10
struct object_header stru_D_8003DD10 = {0, NULL, 0, 2, 1, 196.83067, 0, 3, 0, 0};
//D:8003DD30
struct object_header stru_D_8003DD30 = {0, NULL, 0, 2, 1, 176.67717, 0, 1, 0, 0};
//D:8003DD50
struct object_header stru_D_8003DD50 = {0, NULL, 0, 2, 1, 190.61967, 0, 4, 0, 0};
//D:8003DD70
struct object_header CheadbrosnansuitZ_struct = {0, NULL, 0, 2, 1, 212.45657, 0, 5, 0, 0};
//D:8003DD90
struct object_header CheadbrosnantimberZ_struct = {0, NULL, 0, 2, 1, 179.28358, 0, 4, 0, 0};
//D:8003DDB0
struct object_header CheadbrosnansnowZ_struct = {0, NULL, 0, 2, 1, 225.0605, 0, 6, 0, 0};
//D:8003DDD0
struct object_header CheadbrosnanZ_struct = {0, NULL, 0, 2, 1, 189.48112, 0, 5, 0, 0};
//D:8003DDF0
struct object_header CspicebondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1208.6448, 0, 0x11, 0, 0};
const char padding_chars_for_strings[] = "\00\00\00\00\00\00\00\00\00\00\00";
struct c_itementry c_item_entries[] = {
    {&CcamguardZ_struct, "CcamguardZ", 1.0, 1.0, 0x1000000},
    {&CgreyguardZ_struct, "CgreyguardZ", 1.0, 1.0, 0x1000000},
    {&ColiveguardZ_struct, "ColiveguardZ", 1.0, 1.0, 0x1000000},
    {&CrusguardZ_struct, "CrusguardZ", 1.0, 1.0, 0x1000000},
    {&CtrevguardZ_struct, "CtrevguardZ", 1.0, 1.0, 0x1000000},
    {&CdjbondZ_struct, "CdjbondZ", 1.0, 1.0446, 0x1000000},
    {&CborisZ_struct, "CborisZ", 1.0, 0.9702, 0x1010000},
    {&CorumovZ_struct, "CorumovZ", 1.0, 1.0778, 0x1010000},
    {&CtrevelyanZ_struct, "CtrevelyanZ", 1.0, 1.0, 0x1010000},
    {&CboilertrevZ_struct, "CboilertrevZ", 1.0, 1.0, 0x1010000},
    {&CvalentinZ_struct, "CvalentinZ", 1.0, 0.93239999, 0x1010000},
    {&CxeniaZ_struct, "CxeniaZ", 1.0, 1.0, 0x10000},
    {&CbaronsamediZ_struct, "CbaronsamediZ", 1.0, 1.0, 0x1010000},
    {&CjawsZ_struct, "CjawsZ", 1.0, 1.199, 0x1010000},
    {&CmaydayZ_struct, "CmaydayZ", 1.0, 1.0, 0x10000},
    {&CoddjobZ_struct, "CoddjobZ", 1.0, 0.78780001, 0x1010000},
    {&CnatalyaZ_struct, "CnatalyaZ", 1.0, 0.96609998, 0x10000},
    {&CarmourguardZ_struct, "CarmourguardZ", 1.0, 1.0, 0x1000000},
    {&CcommguardZ_struct, "CcommguardZ", 1.0, 1.0, 0x1000000},
    {&CgreatguardZ_struct, "CgreatguardZ", 1.0, 1.0, 0x1000000},
    {&CnavyguardZ_struct, "CnavyguardZ", 1.0, 1.0, 0x1000000},
    {&CsnowguardZ_struct, "CsnowguardZ", 1.0, 1.0, 0x1010000},
    {&CboilerbondZ_struct, "CboilerbondZ", 1.0, 1.0403, 0x1000000},
    {&CsuitbondZ_struct, "CsuitbondZ", 1.0, 1.058, 0x1000000},
    {&CtimberbondZ_struct, "CtimberbondZ", 1.0, 1.0438, 0x1000000},
    {&CsnowbondZ_struct, "CsnowbondZ", 1.0, 1.0438, 0x1000000},
    {&CbluewomanZ_struct, "CbluewomanZ", 1.0, 0.88529998, 0},
    {&CfattechwomanZ_struct, "CfattechwomanZ", 1.0, 0.88529998, 0},
    {&CtechwomanZ_struct, "CtechwomanZ", 1.0, 0.91600001, 0},
    {&CjeanwomanZ_struct, "CjeanwomanZ", 1.0, 0.88529998, 0},
    {&CgreymanZ_struct, "CgreymanZ", 1.0, 1.0, 0x1000000},
    {&CbluemanZ_struct, "CbluemanZ", 1.0, 1.0, 0x1000000},
    {&CredmanZ_struct, "CredmanZ", 1.0, 1.0, 0x1000000},
    {&CcardimanZ_struct, "CcardimanZ", 1.0, 1.0, 0x1000000},
    {&CcheckmanZ_struct, "CcheckmanZ", 1.0, 1.0, 0x1000000},
    {&CtechmanZ_struct, "CtechmanZ", 1.0, 1.0, 0x1000000},
    {&CpilotZ_struct, "CpilotZ", 1.0, 1.0, 0x1010000},
    {&Cgreatguard2Z_struct, "Cgreatguard2Z", 1.0, 1.0, 0x1000000},
    {&CbluecamguardZ_struct, "CbluecamguardZ", 1.0, 1.0, 0x1000000},
    {&CmoonguardZ_struct, "CmoonguardZ", 1.0, 1.0, 0x1000000},
    {&CmoonfemaleZ_struct, "CmoonfemaleZ", 1.0, 0.88529998, 0},
    {&Csuit_lf_handz_struct, "Csuit_lf_handZ", 0.1, 1.0, 0x1000000},
    {&CheadkarlZ_struct, "CheadkarlZ", 1.0, 1.0, 0x1010000},
    {&CheadalanZ_struct, "CheadalanZ", 1.0, 1.0, 0x1010000},
    {&CheadpeteZ_struct, "CheadpeteZ", 1.0, 1.0, 0x1010000},
    {&CheadmartinZ_struct, "CheadmartinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003D9D0, "CheadmarkZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003D9F0, "CheadduncanZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA30, "CheadshaunZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA50, "CheaddwayneZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA10, "CheadbZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA70, "CheaddaveZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA90, "CheadgrantZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAB0, "CheaddesZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAD0, "CheadchrisZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAF0, "CheadleeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB10, "CheadneilZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB30, "CheadjimZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB50, "CheadrobinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB70, "CheadstevehZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB90, "CheadbalaclavaZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBB0, "CheadbikeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBD0, "CheadgrahamZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBF0, "CheadsteveeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC10, "CheadjoelZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC30, "CheadscottZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC50, "CheadjoeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC70, "CheadkenZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC90, "Cheadjoe2Z", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DCB0, "CheadmishkinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DCD0, "CheadsallyZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DCF0, "CheadmarionZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD10, "CheadmandyZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD30, "CheadvivienZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD50, "CheadbrosnanboilerZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnansuitZ_struct, "CheadbrosnansuitZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnantimberZ_struct, "CheadbrosnantimberZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnansnowZ_struct, "CheadbrosnansnowZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnanZ_struct, "CheadbrosnanZ", 1.0, 1.0, 0x1010000},
    {&CspicebondZ_struct, "CspicebondZ", 0.94999999, 0.96609998, 0x10000},
};


//D:8003E450
u32 D_8003E450 = 0;
u32 D_8003E454 = 0;
//D:8003E458
f32 D_8003E458 = 1.0;
//D:8003E45C
u32 D_8003E45C = 0;
//D:8003E460
u32 D_8003E460 = 0;

//D:8003E464
f32 D_8003E464[] = {
    -0.076300003, 0.77999997,-1.2696    , 1.1694109,
     1.120654  , 1.05959   ,-0.25760001,-0.47319999,
    -1.5686001 , 1.132916  , 1.0       , 1.080207,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.039999999, 0.74000001,
    -0.63999999, 1.132795  , 1.167207  , 1.035167,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.033500001, 0.24959999,
     0.16599999, 1.115045  , 0.94169998, 1.042492,
    -0.070299998, 0.4919    ,-0.83359998, 1.072812,
     1.088326  , 0.926121  ,-0.1       , 0.42750001,
    -0.48249999, 1.033368  , 0.96552098, 0.929905,
     0.18000001, 0.0       , 0.0       , 1.072214,
     1.0       , 1.0       , 0.237     , 0.977,
    -0.44      , 1.178463  , 1.14061   , 1.143465,
    -0.090300001, 0.23190001, 0.12639999, 0.99080002,
     1.02      , 0.8466    , 0.0       , 0.1485,
     0.3793    , 1.1548001 , 0.99190003, 0.95139998,
    -0.14820001, 0.44100001, 0.1727    , 1.050034,
     1.0       , 1.05445   ,-0.4941    ,-0.26409999,
    -0.18000001, 0.90368301, 0.72551203, 1.001314,
     0.1318    , 0.30100101, 1.572699  , 0.98799503,
     1.0       , 1.05445   , 0.0       , 0.73019999,
     0.71740001, 1.1923    , 1.1834    , 1.091924,
    -0.0942    ,-0.74190003, 0.94260001, 0.98659998,
     0.91689998, 0.94760001, 0.0535    , 0.61510003,
     1.076     , 1.05092   , 0.90002   , 1.122508,
    -0.079999998, 0.1085    ,-0.56629997, 1.192598,
     1.079134  , 1.199971  ,-0.35640001,-0.28709999,
    -0.36950001, 1.035176  , 0.838543  , 1.121092,
     0.065300003,-0.4664    , 0.72000003, 1.050106,
     1.0       , 1.11042   ,-0.079999998, 0.4885,
     0.093699999, 1.158567  , 1.2356189 , 1.194388,
    -0.0942    ,-0.3017    , 0.59450001, 1.0671999,
     1.0218    , 1.0174    , 0.12      ,-0.1515,
     0.95370001, 1.124017  , 0.966048  , 1.206121,
    -0.19310001, 0.2334    ,-0.64850003, 1.1800359,
     1.0401829 , 1.154537  ,-0.36230001,-0.133,
    -0.486     , 1.0536211 , 1.0       , 1.1495841,
     0.0955    , 0.68099999, 0.78799999, 1.0152,
     1.1926    , 1.1308    ,-0.0823    , 0.36700001,
     0.37400001, 1.311748  , 1.115972  , 1.166244,
    -0.0942    , 0.1768    , 0.5248    , 1.0470001,
     1.0218    , 0.99800003, 0.0       ,-0.0964,
     0.82999998, 1.1109999 , 0.85180199, 1.180503,
    -0.1832    , 0.32120001,-1.2381001 , 1.125683,
     1.091681  , 0.98079097,-0.55049998,-0.60839999,
    -1.189499  , 1.023566  , 0.8326    , 1.0637,
     0.076800004, 0.32120001,-0.118101  , 1.059677,
     1.091681  , 1.000479  , 0.0       , 0.29890001,
    -0.67299998, 1.1367    , 1.0526    , 0.99227399,
    -0.0942    , 0.032000002,-0.29699999, 1.0402,
     0.92860001, 0.88690001, 0.0       , 0.26879999,
     0.057399999, 1.041842  , 0.81959999, 0.99637401,
     0.079700001, 0.3511    , 0.0       , 1.0,
     1.0       , 1.0835    , 0.14      , 0.1965,
    -0.058398999, 1.012674  , 0.96799999, 1.098917,
     0.1629    , 0.78799999, 1.0746    , 0.92205501,
     1.0688    , 1.055297  ,-0.074500002, 0.8477,
     0.71810001, 1.154819  , 1.177258  , 1.031684,
    -0.0145    , 0.047699999, 0.89810002, 1.0404,
     1.0       , 0.94309998, 0.32550001, 0.36770001,
     0.93809998, 1.044217  , 0.97841102, 1.127771,
    -0.1832    ,-0.058800001,-1.5781    , 1.095929,
     0.96300697, 0.92348999,-0.4411    ,-0.64840001,
    -1.839099  , 1.059271  , 0.8326    , 0.96849501,
     0.19679999,-0.3188    ,-0.43810099, 1.070675,
     1.053777  , 0.88628101, 0.0       , 0.29890001,
    -0.83139998, 1.1154    , 1.0328    , 1.0036,
    -0.0942    ,-0.1275    ,-0.52109998, 1.0402,
     0.92180002, 0.8617    , 0.079999998,-0.2383,
    -0.22940101, 1.063022  , 0.80879998, 0.90789998,
     0.1165    , 0.58780003,-1.3096    , 1.136481,
     1.0409    , 1.065612  ,-0.070600003, 0.0152,
    -1.2391    , 1.002256  , 0.76669598, 1.029659,
     0.2218    , 0.0       , 0.0       , 1.0852,
     1.0       , 1.0       , 0.063000001, 0.7561,
    -0.45269999, 1.2085    , 1.1014    , 1.0664001,
     0.065499999,-0.1097    ,-0.3497    , 1.0404,
     0.90915602, 0.94940001, 0.0       , 0.336,
     0.082999997, 1.150862  , 0.94169998, 1.0,
    -0.054200001, 0.27079999,-0.082099997, 1.0367,
     1.0367    , 1.0367    , 0.34119999,-0.55879998,
    -0.3044    , 1.113436  , 0.96799999, 1.076647,
     0.0495    , 0.63980001, 1.2178    , 0.95099998,
     1.1126    , 1.0413001 , 0.0       , 0.53640002,
     0.75220001, 1.1976    , 1.1463    , 1.1374,
    -0.0145    ,-0.64749998, 1.0477999 , 0.95289999,
     0.92180002, 0.90579998, 0.16      , 0.61830002,
     1.128299  , 1.083438  , 0.91670603, 1.0666929,
    -0.2586    , 0.93580002,-0.2463    , 1.1057,
     1.0116    , 1.0927    ,-0.1788    ,-0.31310001,
    -0.55299997, 1.1071    , 1.0       , 1.071945,
     0.0955    , 0.16230001, 0.50150001, 1.0506001,
     1.0       , 1.1032    , 0.081200004, 0.2269,
     0.50700003, 1.1071    , 1.178908  , 1.189239,
    -0.0145    ,-0.68440002, 0.54070002, 1.0470001,
     0.92699999, 1.027078  , 0.0       ,-0.0164,
     0.66399997, 1.2108999 , 1.0       , 1.0729001,
    -0.1487    , 0.88779998,-0.41060001, 1.110018,
     0.98460901, 1.110518  , 0.0012000001,-0.61879998,
    -0.34439901, 1.099178  , 0.916071  , 1.054984,
     0.0429    , 0.2149    , 0.4298    , 1.0455,
     1.0688    , 1.1514    , 0.0012000001,-0.0188,
     0.65560102, 1.1957231 , 1.079964  , 1.200996,
    -0.0145    ,-0.48769999, 0.44909999, 1.003074,
     1.0       , 0.98259997, 0.0       , 0.396,
     0.8362    , 1.1622    , 0.91339999, 1.066853,
    -0.29030001, 1.0714999 ,-0.3504    , 1.125893,
     1.127159  , 1.177758  , 0.0       ,-0.079999998,
    -0.373     , 1.099718  , 1.0       , 1.0947551,
     0.0       , 0.78799999, 0.64469999, 1.0,
     1.0       , 1.0963    ,-0.074699998, 1.5436,
     0.1979    , 1.1497999 , 1.1835999 , 1.0791,
    -0.090300001,-0.1085    , 0.68959999, 1.024099,
     1.0       , 0.98965299, 0.0       , 0.63230002,
     0.7913    , 1.1081001 , 0.93440002, 1.0779999,
     0.12      , 0.40000001, 0.039999999, 1.022947,
     0.92226201, 1.004824  , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0429    , 0.75889999, 1.2895    , 0.94440001,
     1.0       , 1.0551    , 0.0       , 0.546,
     0.79729998, 1.1483001 , 1.1267999 , 1.1388,
     0.065099999,-0.54320002, 1.1224999 , 0.93949997,
     0.92699999, 0.93040001, 0.1265    , 0.36359999,
     1.079     , 1.1109999 , 1.0       , 1.1166,
    -0.278     , 1.272301  ,-0.55269998, 1.24701,
     1.0737129 , 1.118222  ,-0.23639999, 0.58200002,
    -0.30950001, 1.225595  , 1.077682  , 1.066005,
    -0.0845    , 0.68099999, 0.64469999, 1.1204081,
     1.1927    , 1.1308    ,-0.1364    , 1.021999,
     0.5905    , 1.153587  , 1.226897  , 1.2252491,
    -0.2534    , 0.57560003, 0.3856    , 1.0405,
     1.0405    , 1.0585999 ,-0.1265    , 0.6081,
     0.71200001, 1.222     , 1.0       , 1.111666,
    -0.4637    , 1.3971    ,-0.49270001, 1.1752,
     1.0116    , 1.1762    ,-0.2976    ,-0.1049,
    -0.49649999, 1.2345999 , 0.86470801, 1.077117,
    -0.1151    , 0.7353    , 0.57309997, 1.0759,
     1.0       , 1.1308    ,-0.189     , 0.99910003,
     0.2396    , 1.2269    , 1.2039    , 1.1698999,
    -0.2534    ,-0.0647    , 0.30070001, 1.0470001,
     0.92699999, 1.0124    ,-0.1265    , 0.61260003,
     0.76700002, 1.2108999 , 1.0       , 1.096216,
    -0.51429999, 1.0894001 ,-0.082099997, 1.1003,
     1.0316    , 1.0278    ,-0.53280002,-0.13060001,
    -0.25999999, 1.080464  , 1.0       , 1.019003,
    -0.1969    , 0.45930001, 0.64469999, 0.96219999,
     1.0       , 1.0895    ,-0.32690001, 1.1438,
     0.46720001, 1.1339    , 1.1339    , 1.0436,
    -0.29879999, 0.0       , 0.41429999, 0.96219999,
     1.0       , 0.95630002,-0.17640001, 0.39500001,
     0.86699998, 1.0972    , 0.94625998, 1.0529979,
     0.02      , 0.56910002,-0.25299999, 1.1205291,
     0.999475  , 1.072994  ,-0.0823    ,-0.3784,
    -0.38249999, 1.077682  , 1.0       , 1.066239,
     0.02      ,-0.1909    , 0.90700001, 1.049657,
     0.999475  , 1.072994  , 0.0       , 0.60549998,
     0.47510001, 1.1236    , 1.1236    , 1.1236,
    -0.0942    , 0.077600002, 0.5248    , 1.0403,
     0.95950001, 0.98580003, 0.0       , 0.20550001,
     0.8951    , 1.1519721 , 0.92378497, 1.0316401,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0836    ,-0.66259998, 0.14210001, 0.95139998,
     1.090098  , 0.92760003, 0.1141    ,-1.1931,
    -0.25400001, 0.98102301, 0.83667898, 0.88798702,
     0.1481    ,-0.15360001, 1.1461999 , 0.91399997,
     1.0       , 0.94489998, 0.0       ,-0.53250003,
     0.3563    , 1.0727    , 1.0526    , 1.0228,
    -0.0942    ,-0.6857    , 1.1224999 , 0.95959997,
     0.92860001, 0.88690001, 0.079999998,-0.7396,
     0.963     , 1.1032    , 0.875673  , 0.97771698,
    -0.29030001, 1.0714999 ,-0.3504    , 1.125893,
     1.127159  , 1.177758  , 0.0       ,-0.079999998,
    -0.373     , 1.099718  , 1.0       , 1.0947551,
     0.0       , 0.78799999, 0.64469999, 1.0,
     1.0       , 1.0963    ,-0.074699998, 1.5436,
     0.1979    , 1.1497999 , 1.1835999 , 1.0791,
    -0.090300001,-0.1085    , 0.68959999, 1.024099,
     1.0       , 0.98965299, 0.0       , 0.63230002,
     0.7913    , 1.1081001 , 0.93440002, 1.0779999,
    -0.13699999, 0.286001  ,-0.32229999, 1.142894,
     0.89638299, 1.15      ,-0.16680001,-0.1365,
    -0.43650001, 1.1452    , 1.0       , 1.061306,
     0.1376    , 0.0       , 0.71600002, 1.05312,
     1.0       , 1.0687751 ,-0.074699998, 0.9393,
     0.2658    , 1.1815    , 1.1216    , 1.0822999,
    -0.103     ,-0.2269    , 0.5722    , 0.99080002,
     1.02      , 1.0034    , 0.0       , 0.1373,
     0.79430002, 1.1813999 , 0.86186302, 1.0998,
     0.12      , 0.40000001, 0.039999999, 1.022947,
     0.92226201, 1.004824  , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0429    , 0.75889999, 1.2895    , 0.94440001,
     1.0       , 1.0551    , 0.0       , 0.546,
     0.79729998, 1.1483001 , 1.1267999 , 1.1388,
     0.065099999,-0.54320002, 1.1224999 , 0.93949997,
     0.92699999, 0.93040001, 0.1265    , 0.36359999,
     1.079     , 1.1109999 , 1.0       , 1.1166,
     0.0836    ,-0.66259998, 0.14210001, 0.95139998,
     1.090098  , 0.92760003, 0.1141    ,-1.1931,
    -0.25400001, 0.98102301, 0.83667898, 0.88798702,
     0.1481    ,-0.15360001, 1.1461999 , 0.91399997,
     1.0       , 0.94489998, 0.0       ,-0.53250003,
     0.3563    , 1.0727    , 1.0526    , 1.0228,
    -0.0942    ,-0.6857    , 1.1224999 , 0.95959997,
     0.92860001, 0.88690001, 0.079999998,-0.7396,
     0.963     , 1.1032    , 0.875673  , 0.97771698,
    -0.29030001, 1.0714999 ,-0.3504    , 1.125893,
     1.127159  , 1.177758  , 0.0       ,-0.079999998,
    -0.373     , 1.099718  , 1.0       , 1.0947551,
     0.0       , 0.78799999, 0.64469999, 1.0,
     1.0       , 1.0963    ,-0.074699998, 1.5436,
     0.1979    , 1.1497999 , 1.1835999 , 1.0791,
    -0.090300001,-0.1085    , 0.68959999, 1.024099,
     1.0       , 0.98965299, 0.0       , 0.63230002,
     0.7913    , 1.1081001 , 0.93440002, 1.0779999,
     0.0836    ,-0.66259998, 0.14210001, 0.95139998,
     1.090098  , 0.92760003, 0.1141    ,-1.1931,
    -0.25400001, 0.98102301, 0.83667898, 0.88798702,
     0.1481    ,-0.15360001, 1.1461999 , 0.91399997,
     1.0       , 0.94489998, 0.0       ,-0.53250003,
     0.3563    , 1.0727    , 1.0526    , 1.0228,
    -0.0942    ,-0.6857    , 1.1224999 , 0.95959997,
     0.92860001, 0.88690001, 0.079999998,-0.7396,
     0.963     , 1.1032    , 0.875673  , 0.97771698,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0       , 1.0,
     1.0       , 1.0       , 0.0       , 0.0,
     0.0       , 1.0       , 1.0       , 1.0,
     0.0       , 0.0       , 0.0
};

//D:8003F430
u32 dword_D_8003F430[] = {0x320028, 0x2300120, 0x4100032, 0x280130, 0x340420};
//D:8003F444
u32 dword_D_8003F444[] = {0x4200011, 0x180120, 0x240018, 0x1200410, 0x2200031};
//D:8003F458
u32 dword_D_8003F458[] = {0x4300022, 0x210032, 0x4200024, 0x120031, 0x8100022};
//D:8003F46C
u32 dword_D_8003F46C[] = {0x310810, 0x4100410, 0x310230, 0x4100810, 0x310210};
//D:8003F480
u32 dword_D_8003F480[] = {0x8200011, 0x140032, 0x2300130, 0x4100018, 0x110430};
//D:8003F494
u32 dword_D_8003F494[] = {0x1100220, 0x2200810, 0x4200014, 0x220031, 0x4200028};
//D:8003F4A8
u32 dword_D_8003F4A8[] = {0x140430, 0x1200018, 0x310810, 0x4200120, 0x120018};
//D:8003F4BC
u32 dword_D_8003F4BC[] = {0x120038, 0x2300830, 0x8100022, 0x180024, 0x2300110};
//D:8003F4D0
u32 dword_D_8003F4D0[] = {0x280032, 0x8100021, 0x120120, 0x320021, 0x8200034};
//D:8003F4E4
u32 dword_D_8003F4E4[] = {0x380210, 0x140024, 0x8100420, 0x110120, 0x1300014};
//D:8003F4F8
u32 dword_D_8003F4F8[] = {0x380012, 0x2200018, 0x2200014, 0x210110, 0x380120};
//D:8003F50C
u32 dword_D_8003F50C[] = {0x2300210, 0x280220, 0x180014, 0x110110, 0x4200012};
//D:8003F520
u32 dword_D_8003F520[] = {0x120038, 0x2200810, 0x2100820, 0x140120, 0x210430};
//D:8003F534
u32 dword_D_8003F534[] = {0x240110, 0x210012, 0x240230, 0x210830, 0x110820};
//D:8003F548
u32 dword_D_8003F548[] = {0x8200014, 0x2200410, 0x220031, 0x280110, 0x1100011};
//D:8003F55C
u32 dword_D_8003F55C[] = {0x180420, 0x110220, 0x8300034, 0x110810, 0x340810};
//D:8003F570
u32 dword_D_8003F570[] = {0x240031, 0x110018, 0x120120, 0x380028, 0x4300021};
//D:8003F584
u32 dword_D_8003F584[] = {0x4200410, 0x380220, 0x1300022, 0x1100028, 0x2200024};
//D:8003F598
u32 dword_D_8003F598[] = {0x340034, 0x1200230, 0x2100011, 0x2300018, 0x140110};
//D:8003F5AC
u32 dword_D_8003F5AC[] = {0x2100830, 0x340210, 0x310220, 0x1300034, 0x8200014};
//D:8003F5C0
u32 dword_D_8003F5C0[] = {0x320021, 0x8200034, 0x110014, 0x2100014, 0x180420};
//D:8003F5D4
u32 dword_D_8003F5D4[] = {0x4200420, 0x140021, 0x1300012, 0x4200022, 0x210820};
//D:8003F5E8
u32 dword_D_8003F5E8[] = {0x2100014, 0x110230, 0x1200014, 0x2200032, 0x8200028};
//D:8003F5FC
u32 dword_D_8003F5FC[] = {0x140210, 0x8300110, 0x4100410, 0x8100012, 0x180230};
//D:8003F610
u32 dword_D_8003F610[] = {0x240410, 0x1200011, 0x140210, 0x2100018, 0x2100038};
//D:8003F624
u32 dword_D_8003F624[] = {0x4200014, 0x8300120, 0x180012, 0x8100022, 0x8200012};
//D:8003F638
u32 dword_D_8003F638[] = {0x380220, 0x4100420, 0x280420, 0x1100018, 0x220110};
//D:8003F64C
u32 dword_D_8003F64C[] = {0x140210, 0x1200031, 0x4200038, 0x2200038, 0x1300022};
//D:8003F660
u32 dword_D_8003F660[] = {0x8300031, 0x4200110, 0x8100420, 0x2200021, 0x310220, 0x80304030, 0x80304030};
//D:8003F67C
u32 dword_D_8003F67C[] = {0x8200008, 0x1100032, 0x8200014, 0x240034, 0x8300024};
//D:8003F690
u32 dword_D_8003F690[] = {0x2100420, 0x2000800, 0x4000012, 0x220230, 0x1300022};
//D:8003F6A4
u32 dword_D_8003F6A4[] = {0x8300001, 0x2100810, 0x8000110, 0x8000034, 0x4300032};
//D:8003F6B8
u32 dword_D_8003F6B8[] = {0x4100810, 0x1000034, 0x1200210, 0x2000400, 0x8000014};
//D:8003F6CC
u32 dword_D_8003F6CC[] = {0x1100820, 0x4000400, 0x140220, 0x220810, 0x4100012};
//D:8003F6E0
u32 dword_D_8003F6E0[] = {0x4200024, 0x8300014, 0x2000410, 0x240800, 0x4100120};
//D:8003F6F4
u32 dword_D_8003F6F4[] = {0x8100004, 0x20008, 0x4200810, 0x20100, 0x2100110};
//D:8003F708
u32 dword_D_8003F708[] = {0x4300410, 0x240200, 0x120034, 0x1000400, 0x140110};
//D:8003F71C
u32 dword_D_8003F71C[] = {0x120220, 0x8000130, 0x1000032, 0x320410, 0x2100012};
//D:8003F730
u32 dword_D_8003F730[] = {0x240022, 0x40001, 0x20130, 0x10830, 0x120220};
//D:8003F744
u32 dword_D_8003F744[] = {0x320034, 0x220012, 0x1100230, 0x1200200, 0x320420};
//D:8003F758
u32 dword_D_8003F758[] = {0x340002, 0x140004, 0x40034, 0x8300004, 0x8100820};
//D:8003F76C
u32 dword_D_8003F76C[] = {0x2300230, 0x4300230, 0x10430, 0x4300420, 0x20008};
//D:8003F780
u32 dword_D_8003F780[] = {0x2200830, 0x1200830, 0x320230, 0x4300004, 0x1300230};
//D:8003F794
u32 dword_D_8003F794[] = {0x140120, 0x120110, 0x1300830, 0x4200210, 0x1200022};
//D:8003F7A8
u32 dword_D_8003F7A8[] = {0x220130, 0x10002, 0x2100024, 0x2300034, 0x8200001};
//D:8003F7BC
u32 dword_D_8003F7BC[] = {0x8000100, 0x2200410, 0x8200022, 0x2200001, 0x80430};
//D:8003F7D0
u32 dword_D_8003F7D0[] = {0x1300430, 0x8200430, 0x80810, 0x1300220, 0x4000024};
//D:8003F7E4
u32 dword_D_8003F7E4[] = {0x1200032, 0x4200210, 0x4100120, 0x80100, 0x1100830};
//D:8003F7F8
u32 dword_D_8003F7F8[] = {0x4000200, 0x80100, 0x4200220};

//D:8003F804
u32 D_8003F804 = 0x8200002;
//D:8003F808
u32 D_8003F808 = 0x2000004;

//D:8003F80C
struct struct_15 D_8003F80C[] = {
    {1, 0xA, 0, 0, dword_D_8003F430, 0, 0x31},
    {2, 0xA, 0, 0, dword_D_8003F444, 0xB0000000, 6},
    {3, 0xA, 0, 0, dword_D_8003F458, 0xB0010000, 2},
    {4, 0xA, 0, 0, dword_D_8003F46C, 0, 0x16},
    {5, 0xA, 0, 0, dword_D_8003F480, 0, 0x16},
    {6, 0xA, 0, 0, dword_D_8003F494, 0, 0x34},
    {7, 0xA, 0, 0, dword_D_8003F4A8, 0xB0370000, 0x66},
    {8, 0, 0, 0, 0, 0, 0x16},
    {9, 0, 0, 0, 0, 0, 0x16},
    {0xA, 0xA, 0, 0, dword_D_8003F4BC, 0xB0040000, 0x62},
    {0xB, 0, 0, 0, 0, 0xB0060000, 0x66},
    {0xC, 0, 0, 0, 0, 0xB0070000, 0x26},
    {0xD, 0, 0, 0, 0, 0, 0x12},
    {0xE, 0, 0, 0, 0, 0xB0080000, 2},
    {0xF, 0, 0, 0, 0, 0xB0380000, 0x66},
    {0x10, 0, 0, 0, 0, 0, 0x16},
    {0x11, 0, 0, 0, 0, 0xB00A0000, 0x12},
    {0x12, 0, 0, 0, 0, 0xB00B0000, 0x12},
    {0x13, 0, 0, 0, 0, 0xB00C0000, 0x12},
    {0x14, 0, 0, 0, 0, 0xB00D0000, 0x12},
    {0x15, 0, 0, 0, 0, 0xB00E0000, 0x12},
    {0x16, 0xA, 0, 0, dword_D_8003F4D0, 0, 4},
    {0x17, 0, 0, 0, 0, 0xB0430000, 0x64},
    {0x18, 0, 0, 0, 0, 0xB0400000, 0x66},
    {0x19, 0, 0, 0, 0, 0, 0x20},
    {0x1A, 0, 0, 0, 0, 0xB0410000, 0x72},
    {0x1B, 0, 0, 0, 0, 0xB0420000, 0x72},
    {0x1C, 0, 0, 0, 0, 0xB0390000, 1},
    {0x1D, 0, 0, 0, 0, 0xB03A0000, 0x12},
    {0x1E, 0, 0, 0, 0, 0xB03B0000, 0x12},
    {0x1F, 0, 0, 0, 0, 0xB03C0000, 0x12},
    {0x20, 0, 0, 0, 0, 0xB03D0000, 0x12},
    {0x21, 0, 0, 0, 0, 0xB03E0000, 0x12},
    {0x22, 0, 0, 0, 0, 0xB03F0000, 0x12},
    {0x23, 0xA, 0, 0, dword_D_8003F67C, 0, 0x11},
    {0x24, 0xA, 0, 0, dword_D_8003F690, 0, 0x11},
    {0x25, 0xA, 0, 0, dword_D_8003F6A4, 0, 0x11},
    {0x26, 0xA, 0, 0, dword_D_8003F6B8, 0, 0x11},
    {0x27, 0xA, 0, 0, dword_D_8003F6CC, 0, 0x11},
    {0x28, 0xA, 0, 0, dword_D_8003F6E0, 0, 0x11},
    {0x29, 0xA, 0, 0, dword_D_8003F6F4, 0, 0x11},
    {0x2A, 0xA, 0, 0, dword_D_8003F708, 0, 0x11},
    {0x2B, 0xA, 0, 0, dword_D_8003F71C, 0, 0x11},
    {0x2C, 0xA, 0, 0, dword_D_8003F730, 0, 0x11},
    {0x2D, 0xA, 0, 0, dword_D_8003F744, 0, 0x11},
    {0x2E, 0xA, 0, 0, dword_D_8003F758, 0, 0x11},
    {0x2F, 0xA, 0, 0, dword_D_8003F76C, 0, 0x11},
    {0x30, 0xA, 0, 0, dword_D_8003F780, 0, 0x11},
    {0x31, 0xA, 0, 0, dword_D_8003F794, 0, 0x11},
    {0x32, 0xA, 0, 0, dword_D_8003F7A8, 0, 0x11},
    {0x33, 0xA, 0, 0, dword_D_8003F7BC, 0, 0x11},
    {0x34, 0xA, 0, 0, dword_D_8003F7D0, 0, 0x11},
    {0x35, 0xA, 0, 0, dword_D_8003F7E4, 0, 0x11},
    {0x36, 0xA, 0, 0, dword_D_8003F7F8, 0, 0x11},
    {0x37, 0xA, 0, 0, dword_D_8003F4E4, 0, 0x11},
    {0x38, 0xA, 0, 0, dword_D_8003F4F8, 0, 0x11},
    {0x39, 0xA, 0, 0, dword_D_8003F50C, 0, 0x11},
    {0x3A, 0xA, 0, 0, dword_D_8003F520, 0, 0x11},
    {0x3B, 0xA, 0, 0, dword_D_8003F534, 0, 0x11},
    {0x3C, 0xA, 0, 0, dword_D_8003F548, 0, 0x11},
    {0x3D, 0xA, 0, 0, dword_D_8003F55C, 0, 0x11},
    {0x3E, 0xA, 0, 0, dword_D_8003F570, 0, 0x11},
    {0x3F, 0xA, 0, 0, dword_D_8003F584, 0, 0x11},
    {0x40, 0xA, 0, 0, dword_D_8003F598, 0, 0x11},
    {0x41, 0xA, 0, 0, dword_D_8003F5AC, 0, 0x11},
    {0x42, 0xA, 0, 0, dword_D_8003F5C0, 0, 0x11},
    {0x43, 0xA, 0, 0, dword_D_8003F5D4, 0, 0x11},
    {0x44, 0xA, 0, 0, dword_D_8003F5E8, 0, 0x11},
    {0x45, 0xA, 0, 0, dword_D_8003F5FC, 0, 0x11},
    {0x46, 0xA, 0, 0, dword_D_8003F610, 0, 0x11},
    {0x47, 0xA, 0, 0, dword_D_8003F624, 0, 0x11},
    {0x48, 0xA, 0, 0, dword_D_8003F638, 0, 0x11},
    {0x49, 0xA, 0, 0, dword_D_8003F64C, 0, 0x11},
    {0x4A, 0xA, 0, 0, dword_D_8003F660, 0, 0x11},
    {0}
};

//D:8003FCBC
//u32 D_8003FCBC = 0;




// rodata







#ifdef NONMATCHING
void sub_GAME_7F091740(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091740
/* 0C6270 7F091740 AFA40000 */  sw    $a0, ($sp)
/* 0C6274 7F091744 308EFFFF */  andi  $t6, $a0, 0xffff
/* 0C6278 7F091748 01C02025 */  move  $a0, $t6
/* 0C627C 7F09174C 11C00009 */  beqz  $t6, .L7F091774
/* 0C6280 7F091750 00001825 */   move  $v1, $zero
.L7F091754:
/* 0C6284 7F091754 308F0001 */  andi  $t7, $a0, 1
/* 0C6288 7F091758 11E00002 */  beqz  $t7, .L7F091764
/* 0C628C 7F09175C 00801025 */   move  $v0, $a0
/* 0C6290 7F091760 24630001 */  addiu $v1, $v1, 1
.L7F091764:
/* 0C6294 7F091764 00022042 */  srl   $a0, $v0, 1
/* 0C6298 7F091768 3098FFFF */  andi  $t8, $a0, 0xffff
/* 0C629C 7F09176C 1700FFF9 */  bnez  $t8, .L7F091754
/* 0C62A0 7F091770 03002025 */   move  $a0, $t8
.L7F091774:
/* 0C62A4 7F091774 03E00008 */  jr    $ra
/* 0C62A8 7F091778 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09177C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09177C
/* 0C62AC 7F09177C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C62B0 7F091780 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C62B4 7F091784 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C62B8 7F091788 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C62BC 7F09178C 3C118004 */  lui   $s1, %hi(D_8003F80C) # $s1, 0x8004
/* 0C62C0 7F091790 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C62C4 7F091794 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C62C8 7F091798 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C62CC 7F09179C 2631F80C */  addiu $s1, %lo(D_8003F80C) # addiu $s1, $s1, -0x7f4
/* 0C62D0 7F0917A0 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 0C62D4 7F0917A4 0000A025 */   move  $s4, $zero
/* 0C62D8 7F0917A8 2401005A */  li    $at, 90
/* 0C62DC 7F0917AC 14410003 */  bne   $v0, $at, .L7F0917BC
/* 0C62E0 7F0917B0 00000000 */   nop   
/* 0C62E4 7F0917B4 10000008 */  b     .L7F0917D8
/* 0C62E8 7F0917B8 24130001 */   li    $s3, 1
.L7F0917BC:
/* 0C62EC 7F0917BC 0FC26919 */  jal   get_num_players
/* 0C62F0 7F0917C0 00000000 */   nop   
/* 0C62F4 7F0917C4 24010001 */  li    $at, 1
/* 0C62F8 7F0917C8 14410003 */  bne   $v0, $at, .L7F0917D8
/* 0C62FC 7F0917CC 24130004 */   li    $s3, 4
/* 0C6300 7F0917D0 10000001 */  b     .L7F0917D8
/* 0C6304 7F0917D4 24130002 */   li    $s3, 2
.L7F0917D8:
/* 0C6308 7F0917D8 3C0E8004 */  lui   $t6, %hi(D_8003F80C) # $t6, 0x8004
/* 0C630C 7F0917DC 91CEF80C */  lbu   $t6, %lo(D_8003F80C)($t6)
/* 0C6310 7F0917E0 3C128008 */  lui   $s2, %hi(ptr_BONDdata) # $s2, 0x8008
/* 0C6314 7F0917E4 2652A0B0 */  addiu $s2, %lo(ptr_BONDdata) # addiu $s2, $s2, -0x5f50
/* 0C6318 7F0917E8 11C0004C */  beqz  $t6, .L7F09191C
/* 0C631C 7F0917EC 24100014 */   li    $s0, 20
/* 0C6320 7F0917F0 92250001 */  lbu   $a1, 1($s1)
.L7F0917F4:
/* 0C6324 7F0917F4 58A00044 */  blezl $a1, .L7F091908
/* 0C6328 7F0917F8 92280010 */   lbu   $t0, 0x10($s1)
/* 0C632C 7F0917FC 8E460000 */  lw    $a2, ($s2)
/* 0C6330 7F091800 90CF12B5 */  lbu   $t7, 0x12b5($a2)
/* 0C6334 7F091804 01E5082A */  slt   $at, $t7, $a1
/* 0C6338 7F091808 5420003F */  bnezl $at, .L7F091908
/* 0C633C 7F09180C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6340 7F091810 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6344 7F091814 0313C824 */  and   $t9, $t8, $s3
/* 0C6348 7F091818 5320003B */  beql  $t9, $zero, .L7F091908
/* 0C634C 7F09181C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6350 7F091820 90C812B4 */  lbu   $t0, 0x12b4($a2)
/* 0C6354 7F091824 00002025 */  move  $a0, $zero
/* 0C6358 7F091828 01054823 */  subu  $t1, $t0, $a1
/* 0C635C 7F09182C 252A0014 */  addiu $t2, $t1, 0x14
/* 0C6360 7F091830 0150001A */  div   $zero, $t2, $s0
/* 0C6364 7F091834 00001010 */  mfhi  $v0
/* 0C6368 7F091838 16000002 */  bnez  $s0, .L7F091844
/* 0C636C 7F09183C 00000000 */   nop   
/* 0C6370 7F091840 0007000D */  break 7
.L7F091844:
/* 0C6374 7F091844 2401FFFF */  li    $at, -1
/* 0C6378 7F091848 16010004 */  bne   $s0, $at, .L7F09185C
/* 0C637C 7F09184C 3C018000 */   lui   $at, 0x8000
/* 0C6380 7F091850 15410002 */  bne   $t2, $at, .L7F09185C
/* 0C6384 7F091854 00000000 */   nop   
/* 0C6388 7F091858 0006000D */  break 6
.L7F09185C:
/* 0C638C 7F09185C 18A00018 */  blez  $a1, .L7F0918C0
/* 0C6390 7F091860 00000000 */   nop   
/* 0C6394 7F091864 8E230004 */  lw    $v1, 4($s1)
.L7F091868:
/* 0C6398 7F091868 00025840 */  sll   $t3, $v0, 1
/* 0C639C 7F09186C 00CB6021 */  addu  $t4, $a2, $t3
/* 0C63A0 7F091870 958D128C */  lhu   $t5, 0x128c($t4)
/* 0C63A4 7F091874 946E0000 */  lhu   $t6, ($v1)
/* 0C63A8 7F091878 244F0001 */  addiu $t7, $v0, 1
/* 0C63AC 7F09187C 15AE0010 */  bne   $t5, $t6, .L7F0918C0
/* 0C63B0 7F091880 00000000 */   nop   
/* 0C63B4 7F091884 01F0001A */  div   $zero, $t7, $s0
/* 0C63B8 7F091888 16000002 */  bnez  $s0, .L7F091894
/* 0C63BC 7F09188C 00000000 */   nop   
/* 0C63C0 7F091890 0007000D */  break 7
.L7F091894:
/* 0C63C4 7F091894 2401FFFF */  li    $at, -1
/* 0C63C8 7F091898 16010004 */  bne   $s0, $at, .L7F0918AC
/* 0C63CC 7F09189C 3C018000 */   lui   $at, 0x8000
/* 0C63D0 7F0918A0 15E10002 */  bne   $t7, $at, .L7F0918AC
/* 0C63D4 7F0918A4 00000000 */   nop   
/* 0C63D8 7F0918A8 0006000D */  break 6
.L7F0918AC:
/* 0C63DC 7F0918AC 24840001 */  addiu $a0, $a0, 1
/* 0C63E0 7F0918B0 00001010 */  mfhi  $v0
/* 0C63E4 7F0918B4 0085082A */  slt   $at, $a0, $a1
/* 0C63E8 7F0918B8 1420FFEB */  bnez  $at, .L7F091868
/* 0C63EC 7F0918BC 24630002 */   addiu $v1, $v1, 2
.L7F0918C0:
/* 0C63F0 7F0918C0 54850011 */  bnel  $a0, $a1, .L7F091908
/* 0C63F4 7F0918C4 92280010 */   lbu   $t0, 0x10($s1)
/* 0C63F8 7F0918C8 A0C012B5 */  sb    $zero, 0x12b5($a2)
/* 0C63FC 7F0918CC 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0C6400 7F0918D0 92240000 */   lbu   $a0, ($s1)
/* 0C6404 7F0918D4 10400005 */  beqz  $v0, .L7F0918EC
/* 0C6408 7F0918D8 00000000 */   nop   
/* 0C640C 7F0918DC 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6410 7F0918E0 33190010 */  andi  $t9, $t8, 0x10
/* 0C6414 7F0918E4 13200005 */  beqz  $t9, .L7F0918FC
/* 0C6418 7F0918E8 00000000 */   nop   
.L7F0918EC:
/* 0C641C 7F0918EC 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6420 7F0918F0 92240000 */   lbu   $a0, ($s1)
/* 0C6424 7F0918F4 10000004 */  b     .L7F091908
/* 0C6428 7F0918F8 92280010 */   lbu   $t0, 0x10($s1)
.L7F0918FC:
/* 0C642C 7F0918FC 0FC2490E */  jal   sub_GAME_7F092438
/* 0C6430 7F091900 92240000 */   lbu   $a0, ($s1)
/* 0C6434 7F091904 92280010 */  lbu   $t0, 0x10($s1)
.L7F091908:
/* 0C6438 7F091908 26310010 */  addiu $s1, $s1, 0x10
/* 0C643C 7F09190C 51000004 */  beql  $t0, $zero, .L7F091920
/* 0C6440 7F091910 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0C6444 7F091914 5280FFB7 */  beql  $s4, $zero, .L7F0917F4
/* 0C6448 7F091918 92250001 */   lbu   $a1, 1($s1)
.L7F09191C:
/* 0C644C 7F09191C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F091920:
/* 0C6450 7F091920 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6454 7F091924 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6458 7F091928 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C645C 7F09192C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C6460 7F091930 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C6464 7F091934 03E00008 */  jr    $ra
/* 0C6468 7F091938 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09193C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09193C
/* 0C646C 7F09193C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C6470 7F091940 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6474 7F091944 0FC26C54 */  jal   get_cur_playernum
/* 0C6478 7F091948 00000000 */   nop   
/* 0C647C 7F09194C 00022600 */  sll   $a0, $v0, 0x18
/* 0C6480 7F091950 00047603 */  sra   $t6, $a0, 0x18
/* 0C6484 7F091954 01C02025 */  move  $a0, $t6
/* 0C6488 7F091958 0C0030C3 */  jal   get_controller_buttons_held
/* 0C648C 7F09195C 3405FFFF */   li    $a1, 65535
/* 0C6490 7F091960 0FC26C54 */  jal   get_cur_playernum
/* 0C6494 7F091964 A7A20026 */   sh    $v0, 0x26($sp)
/* 0C6498 7F091968 00022600 */  sll   $a0, $v0, 0x18
/* 0C649C 7F09196C 00047E03 */  sra   $t7, $a0, 0x18
/* 0C64A0 7F091970 01E02025 */  move  $a0, $t7
/* 0C64A4 7F091974 0C0030EB */  jal   get_controller_buttons_pressed
/* 0C64A8 7F091978 3405FFFF */   li    $a1, 65535
/* 0C64AC 7F09197C 97A30026 */  lhu   $v1, 0x26($sp)
/* 0C64B0 7F091980 30780030 */  andi  $t8, $v1, 0x30
/* 0C64B4 7F091984 3306FFFF */  andi  $a2, $t8, 0xffff
/* 0C64B8 7F091988 00C04827 */  not   $t1, $a2
/* 0C64BC 7F09198C 0300C827 */  not   $t9, $t8
/* 0C64C0 7F091990 00492824 */  and   $a1, $v0, $t1
/* 0C64C4 7F091994 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0C64C8 7F091998 00794024 */  and   $t0, $v1, $t9
/* 0C64CC 7F09199C A7A80026 */  sh    $t0, 0x26($sp)
/* 0C64D0 7F0919A0 11400028 */  beqz  $t2, .L7F091A44
/* 0C64D4 7F0919A4 A7A50024 */   sh    $a1, 0x24($sp)
/* 0C64D8 7F0919A8 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0C64DC 7F0919AC 0FC245D0 */  jal   sub_GAME_7F091740
/* 0C64E0 7F0919B0 AFA60018 */   sw    $a2, 0x18($sp)
/* 0C64E4 7F0919B4 24010001 */  li    $at, 1
/* 0C64E8 7F0919B8 1441001E */  bne   $v0, $at, .L7F091A34
/* 0C64EC 7F0919BC 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C64F0 7F0919C0 97A40026 */  lhu   $a0, 0x26($sp)
/* 0C64F4 7F0919C4 0FC245D0 */  jal   sub_GAME_7F091740
/* 0C64F8 7F0919C8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C64FC 7F0919CC 24010001 */  li    $at, 1
/* 0C6500 7F0919D0 14410018 */  bne   $v0, $at, .L7F091A34
/* 0C6504 7F0919D4 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C6508 7F0919D8 3C048008 */  lui   $a0, %hi(ptr_BONDdata) # $a0, 0x8008
/* 0C650C 7F0919DC 2484A0B0 */  addiu $a0, %lo(ptr_BONDdata) # addiu $a0, $a0, -0x5f50
/* 0C6510 7F0919E0 8C820000 */  lw    $v0, ($a0)
/* 0C6514 7F0919E4 97AB0024 */  lhu   $t3, 0x24($sp)
/* 0C6518 7F0919E8 24010014 */  li    $at, 20
/* 0C651C 7F0919EC 904D12B4 */  lbu   $t5, 0x12b4($v0)
/* 0C6520 7F0919F0 01676025 */  or    $t4, $t3, $a3
/* 0C6524 7F0919F4 000D7040 */  sll   $t6, $t5, 1
/* 0C6528 7F0919F8 004E7821 */  addu  $t7, $v0, $t6
/* 0C652C 7F0919FC A5EC128C */  sh    $t4, 0x128c($t7)
/* 0C6530 7F091A00 8C820000 */  lw    $v0, ($a0)
/* 0C6534 7F091A04 905812B4 */  lbu   $t8, 0x12b4($v0)
/* 0C6538 7F091A08 27190001 */  addiu $t9, $t8, 1
/* 0C653C 7F091A0C 0321001A */  div   $zero, $t9, $at
/* 0C6540 7F091A10 00004010 */  mfhi  $t0
/* 0C6544 7F091A14 A04812B4 */  sb    $t0, 0x12b4($v0)
/* 0C6548 7F091A18 8C820000 */  lw    $v0, ($a0)
/* 0C654C 7F091A1C 904312B5 */  lbu   $v1, 0x12b5($v0)
/* 0C6550 7F091A20 28610014 */  slti  $at, $v1, 0x14
/* 0C6554 7F091A24 10200007 */  beqz  $at, .L7F091A44
/* 0C6558 7F091A28 24690001 */   addiu $t1, $v1, 1
/* 0C655C 7F091A2C 10000005 */  b     .L7F091A44
/* 0C6560 7F091A30 A04912B5 */   sb    $t1, 0x12b5($v0)
.L7F091A34:
/* 0C6564 7F091A34 3C048008 */  lui   $a0, %hi(ptr_BONDdata) # $a0, 0x8008
/* 0C6568 7F091A38 2484A0B0 */  addiu $a0, %lo(ptr_BONDdata) # addiu $a0, $a0, -0x5f50
/* 0C656C 7F091A3C 8C8A0000 */  lw    $t2, ($a0)
/* 0C6570 7F091A40 A14012B5 */  sb    $zero, 0x12b5($t2)
.L7F091A44:
/* 0C6574 7F091A44 0FC245DF */  jal   sub_GAME_7F09177C
/* 0C6578 7F091A48 00000000 */   nop   
/* 0C657C 7F091A4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C6580 7F091A50 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C6584 7F091A54 03E00008 */  jr    $ra
/* 0C6588 7F091A58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091A5C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091A5C
/* 0C658C 7F091A5C 2401001C */  li    $at, 28
/* 0C6590 7F091A60 14810003 */  bne   $a0, $at, .L7F091A70
/* 0C6594 7F091A64 00001025 */   move  $v0, $zero
/* 0C6598 7F091A68 03E00008 */  jr    $ra
/* 0C659C 7F091A6C 24020001 */   li    $v0, 1

.L7F091A70:
/* 0C65A0 7F091A70 03E00008 */  jr    $ra
/* 0C65A4 7F091A74 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091A78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091A78
/* 0C65A8 7F091A78 00047100 */  sll   $t6, $a0, 4
/* 0C65AC 7F091A7C 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C65B0 7F091A80 01EE7821 */  addu  $t7, $t7, $t6
/* 0C65B4 7F091A84 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C65B8 7F091A88 24010004 */  li    $at, 4
/* 0C65BC 7F091A8C 00001025 */  move  $v0, $zero
/* 0C65C0 7F091A90 31F80004 */  andi  $t8, $t7, 4
/* 0C65C4 7F091A94 17010003 */  bne   $t8, $at, .L7F091AA4
/* 0C65C8 7F091A98 00000000 */   nop   
/* 0C65CC 7F091A9C 03E00008 */  jr    $ra
/* 0C65D0 7F091AA0 24020001 */   li    $v0, 1

.L7F091AA4:
/* 0C65D4 7F091AA4 03E00008 */  jr    $ra
/* 0C65D8 7F091AA8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091AAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091AAC
/* 0C65DC 7F091AAC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C65E0 7F091AB0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C65E4 7F091AB4 3C108004 */  lui   $s0, %hi(D_8003F808)
/* 0C65E8 7F091AB8 00047100 */  sll   $t6, $a0, 4
/* 0C65EC 7F091ABC AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C65F0 7F091AC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C65F4 7F091AC4 020E8021 */  addu  $s0, $s0, $t6
/* 0C65F8 7F091AC8 00809025 */  move  $s2, $a0
/* 0C65FC 7F091ACC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C6600 7F091AD0 0FC26C54 */  jal   get_cur_playernum
/* 0C6604 7F091AD4 8E10F808 */   lw    $s0, %lo(D_8003F808)($s0)
/* 0C6608 7F091AD8 0FC26919 */  jal   get_num_players
/* 0C660C 7F091ADC AFA20028 */   sw    $v0, 0x28($sp)
/* 0C6610 7F091AE0 24010001 */  li    $at, 1
/* 0C6614 7F091AE4 14410005 */  bne   $v0, $at, .L7F091AFC
/* 0C6618 7F091AE8 00408825 */   move  $s1, $v0
/* 0C661C 7F091AEC 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6620 7F091AF0 02402025 */   move  $a0, $s2
/* 0C6624 7F091AF4 10000016 */  b     .L7F091B50
/* 0C6628 7F091AF8 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091AFC:
/* 0C662C 7F091AFC 320F0004 */  andi  $t7, $s0, 4
/* 0C6630 7F091B00 11E00012 */  beqz  $t7, .L7F091B4C
/* 0C6634 7F091B04 32180020 */   andi  $t8, $s0, 0x20
/* 0C6638 7F091B08 13000005 */  beqz  $t8, .L7F091B20
/* 0C663C 7F091B0C 00000000 */   nop   
/* 0C6640 7F091B10 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6644 7F091B14 02402025 */   move  $a0, $s2
/* 0C6648 7F091B18 1000000D */  b     .L7F091B50
/* 0C664C 7F091B1C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091B20:
/* 0C6650 7F091B20 18400008 */  blez  $v0, .L7F091B44
/* 0C6654 7F091B24 00008025 */   move  $s0, $zero
.L7F091B28:
/* 0C6658 7F091B28 0FC26C43 */  jal   set_cur_player
/* 0C665C 7F091B2C 02002025 */   move  $a0, $s0
/* 0C6660 7F091B30 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6664 7F091B34 02402025 */   move  $a0, $s2
/* 0C6668 7F091B38 26100001 */  addiu $s0, $s0, 1
/* 0C666C 7F091B3C 1611FFFA */  bne   $s0, $s1, .L7F091B28
/* 0C6670 7F091B40 00000000 */   nop   
.L7F091B44:
/* 0C6674 7F091B44 0FC26C43 */  jal   set_cur_player
/* 0C6678 7F091B48 8FA40028 */   lw    $a0, 0x28($sp)
.L7F091B4C:
/* 0C667C 7F091B4C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F091B50:
/* 0C6680 7F091B50 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6684 7F091B54 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6688 7F091B58 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C668C 7F091B5C 03E00008 */  jr    $ra
/* 0C6690 7F091B60 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091B64(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel PADDINGHACKS
.word 0,0
/*D:800572B0*/
glabel jpt_cheats_cheat
.word cheats_cheat_extra_mp_chars
.word cheats_cheat_invincibility
.word cheats_cheat_allguns
.word cheats_cheat_max_ammo
.word cheats_debug_return_saved_ra
.word cheats_cheat_deactivate_invincibility
.word cheats_cheat_linemode
.word cheats_cheat_2x_health
.word cheats_cheat_2x_armor
.word cheats_cheat_invisibility
.word cheats_cheat_infinite_ammo
.word cheats_cheat_dk_mode
.word cheats_cheat_extra_weapons
.word cheats_cheat_tiny_bond
.word cheats_cheat_paintball
.word cheats_cheat_10x_health
.word cheats_cheat_magnum
.word cheats_cheat_laser
.word cheats_cheat_goldengun
.word cheats_cheat_silverpp7
.word cheats_cheat_goldpp7
.word cheats_cheat_invisibility_mp
.word cheats_debug_return_saved_ra
.word cheats_cheat_fast
.word cheats_debug_pos
.word cheats_debug_fast_ani
.word cheats_debug_slow_ani
.word cheats_debug_return_saved_ra
.word cheats_debug_2x_rockets
.word cheats_debug_2x_grenade_launch
.word cheats_debug_2x_rcp90
.word cheats_debug_2x_throwing_knife
.word cheats_debug_2x_hunting_knife
.word cheats_debug_2x_laser
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel

/*800573D8*/
glabel finalamount
.word 0x3d4ccccd /*0.050000001*/
.text
glabel sub_GAME_7F091B64
/* 0C6694 7F091B64 00047100 */  sll   $t6, $a0, 4
/* 0C6698 7F091B68 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C669C 7F091B6C 01EE7821 */  addu  $t7, $t7, $t6
/* 0C66A0 7F091B70 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C66A4 7F091B74 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C66A8 7F091B78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C66AC 7F091B7C AFA40040 */  sw    $a0, 0x40($sp)
/* 0C66B0 7F091B80 0FC26C54 */  jal   get_cur_playernum
/* 0C66B4 7F091B84 AFAF003C */   sw    $t7, 0x3c($sp)
/* 0C66B8 7F091B88 0FC26919 */  jal   get_num_players
/* 0C66BC 7F091B8C AFA20038 */   sw    $v0, 0x38($sp)
/* 0C66C0 7F091B90 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C66C4 7F091B94 8FA60040 */  lw    $a2, 0x40($sp)
/* 0C66C8 7F091B98 AFA20034 */  sw    $v0, 0x34($sp)
/* 0C66CC 7F091B9C 30780010 */  andi  $t8, $v1, 0x10
/* 0C66D0 7F091BA0 17000012 */  bnez  $t8, .L7F091BEC
/* 0C66D4 7F091BA4 30790020 */   andi  $t9, $v1, 0x20
/* 0C66D8 7F091BA8 1720000A */  bnez  $t9, .L7F091BD4
/* 0C66DC 7F091BAC 8FA50038 */   lw    $a1, 0x38($sp)
/* 0C66E0 7F091BB0 3C098008 */  lui   $t1, %hi(off_CODE_bss_80079E30) # $t1, 0x8008
/* 0C66E4 7F091BB4 25299E30 */  addiu $t1, %lo(off_CODE_bss_80079E30) # addiu $t1, $t1, -0x61d0
/* 0C66E8 7F091BB8 00C91821 */  addu  $v1, $a2, $t1
/* 0C66EC 7F091BBC 906A0000 */  lbu   $t2, ($v1)
/* 0C66F0 7F091BC0 240B0001 */  li    $t3, 1
/* 0C66F4 7F091BC4 00AB6004 */  sllv  $t4, $t3, $a1
/* 0C66F8 7F091BC8 014C6825 */  or    $t5, $t2, $t4
/* 0C66FC 7F091BCC 10000007 */  b     .L7F091BEC
/* 0C6700 7F091BD0 A06D0000 */   sb    $t5, ($v1)
.L7F091BD4:
/* 0C6704 7F091BD4 240E0001 */  li    $t6, 1
/* 0C6708 7F091BD8 004E7804 */  sllv  $t7, $t6, $v0
/* 0C670C 7F091BDC 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C6710 7F091BE0 00260821 */  addu  $at, $at, $a2
/* 0C6714 7F091BE4 25F8FFFF */  addiu $t8, $t7, -1
/* 0C6718 7F091BE8 A0389E30 */  sb    $t8, %lo(off_CODE_bss_80079E30)($at)
.L7F091BEC:
/* 0C671C 7F091BEC 24D9FFFF */  addiu $t9, $a2, -1
/* 0C6720 7F091BF0 2F21004A */  sltiu $at, $t9, 0x4a
/* 0C6724 7F091BF4 1020020C */  beqz  $at, .L7F092428
/* 0C6728 7F091BF8 0019C880 */   sll   $t9, $t9, 2
/* 0C672C 7F091BFC 3C018005 */  lui   $at, %hi(jpt_cheats_cheat)
/* 0C6730 7F091C00 00390821 */  addu  $at, $at, $t9
/* 0C6734 7F091C04 8C3972B0 */  lw    $t9, %lo(jpt_cheats_cheat)($at)
/* 0C6738 7F091C08 03200008 */  jr    $t9
/* 0C673C 7F091C0C 00000000 */   nop   
cheats_cheat_extra_mp_chars:
/* 0C6740 7F091C10 0FC040A0 */  jal   unlock_all_mp_chars
/* 0C6744 7F091C14 00000000 */   nop   
/* 0C6748 7F091C18 10000204 */  b     .L7F09242C
/* 0C674C 7F091C1C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invincibility:
/* 0C6750 7F091C20 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6754 7F091C24 00000000 */   nop   
/* 0C6758 7F091C28 54400200 */  bnezl $v0, .L7F09242C
/* 0C675C 7F091C2C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6760 7F091C30 0FC30776 */  jal   get_textptr_for_textID
/* 0C6764 7F091C34 3404B00F */   li    $a0, 45071
/* 0C6768 7F091C38 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C676C 7F091C3C 00402025 */   move  $a0, $v0
/* 0C6770 7F091C40 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6774 7F091C44 24040001 */   li    $a0, 1
/* 0C6778 7F091C48 100001F8 */  b     .L7F09242C
/* 0C677C 7F091C4C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_allguns:
/* 0C6780 7F091C50 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C6784 7F091C54 00000000 */   nop   
/* 0C6788 7F091C58 544001F4 */  bnezl $v0, .L7F09242C
/* 0C678C 7F091C5C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6790 7F091C60 0FC30776 */  jal   get_textptr_for_textID
/* 0C6794 7F091C64 3404B010 */   li    $a0, 45072
/* 0C6798 7F091C68 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C679C 7F091C6C 00402025 */   move  $a0, $v0
/* 0C67A0 7F091C70 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C67A4 7F091C74 24040001 */   li    $a0, 1
/* 0C67A8 7F091C78 100001EC */  b     .L7F09242C
/* 0C67AC 7F091C7C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_max_ammo:
/* 0C67B0 7F091C80 0FC30776 */  jal   get_textptr_for_textID
/* 0C67B4 7F091C84 3404B011 */   li    $a0, 45073
/* 0C67B8 7F091C88 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C67BC 7F091C8C 00402025 */   move  $a0, $v0
/* 0C67C0 7F091C90 0FC1A4BC */  jal   set_max_ammo_for_cur_player
/* 0C67C4 7F091C94 00000000 */   nop   
/* 0C67C8 7F091C98 100001E4 */  b     .L7F09242C
/* 0C67CC 7F091C9C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_deactivate_invincibility:
/* 0C67D0 7F091CA0 28410002 */  slti  $at, $v0, 2
/* 0C67D4 7F091CA4 142001E0 */  bnez  $at, .L7F092428
/* 0C67D8 7F091CA8 AFA0002C */   sw    $zero, 0x2c($sp)
/* 0C67DC 7F091CAC 18400015 */  blez  $v0, .L7F091D04
/* 0C67E0 7F091CB0 AFA00030 */   sw    $zero, 0x30($sp)
.L7F091CB4:
/* 0C67E4 7F091CB4 8FA50038 */  lw    $a1, 0x38($sp)
/* 0C67E8 7F091CB8 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C67EC 7F091CBC 1125000A */  beq   $t1, $a1, .L7F091CE8
/* 0C67F0 7F091CC0 00000000 */   nop   
/* 0C67F4 7F091CC4 0FC26C43 */  jal   set_cur_player
/* 0C67F8 7F091CC8 01202025 */   move  $a0, $t1
/* 0C67FC 7F091CCC 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6800 7F091CD0 00000000 */   nop   
/* 0C6804 7F091CD4 10400004 */  beqz  $v0, .L7F091CE8
/* 0C6808 7F091CD8 00002025 */   move  $a0, $zero
/* 0C680C 7F091CDC 240B0001 */  li    $t3, 1
/* 0C6810 7F091CE0 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6814 7F091CE4 AFAB002C */   sw    $t3, 0x2c($sp)
.L7F091CE8:
/* 0C6818 7F091CE8 0FC26C43 */  jal   set_cur_player
/* 0C681C 7F091CEC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0C6820 7F091CF0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0C6824 7F091CF4 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0C6828 7F091CF8 254C0001 */  addiu $t4, $t2, 1
/* 0C682C 7F091CFC 158DFFED */  bne   $t4, $t5, .L7F091CB4
/* 0C6830 7F091D00 AFAC0030 */   sw    $t4, 0x30($sp)
.L7F091D04:
/* 0C6834 7F091D04 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C6838 7F091D08 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C683C 7F091D0C 2405009F */  li    $a1, 159
/* 0C6840 7F091D10 11C001C5 */  beqz  $t6, .L7F092428
/* 0C6844 7F091D14 00003025 */   move  $a2, $zero
/* 0C6848 7F091D18 0C002382 */  jal   play_sfx_a1
/* 0C684C 7F091D1C 8C843720 */   lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6850 7F091D20 100001C2 */  b     .L7F09242C
/* 0C6854 7F091D24 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_linemode:
/* 0C6858 7F091D28 0FC243FA */  jal   set_linemode_flag
/* 0C685C 7F091D2C 24040001 */   li    $a0, 1
/* 0C6860 7F091D30 100001BE */  b     .L7F09242C
/* 0C6864 7F091D34 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_2x_health:
/* 0C6868 7F091D38 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C686C 7F091D3C 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C6870 7F091D40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6874 7F091D44 44812000 */  mtc1  $at, $f4
/* 0C6878 7F091D48 C4462A3C */  lwc1  $f6, 0x2a3c($v0)
/* 0C687C 7F091D4C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6880 7F091D50 46062032 */  c.eq.s $f4, $f6
/* 0C6884 7F091D54 00000000 */  nop   
/* 0C6888 7F091D58 45010008 */  bc1t  .L7F091D7C
/* 0C688C 7F091D5C 00000000 */   nop   
/* 0C6890 7F091D60 C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0C6894 7F091D64 44815000 */  mtc1  $at, $f10
/* 0C6898 7F091D68 00000000 */  nop   
/* 0C689C 7F091D6C 460A403C */  c.lt.s $f8, $f10
/* 0C68A0 7F091D70 00000000 */  nop   
/* 0C68A4 7F091D74 450201AD */  bc1fl .L7F09242C
/* 0C68A8 7F091D78 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091D7C:
/* 0C68AC 7F091D7C 0FC30776 */  jal   get_textptr_for_textID
/* 0C68B0 7F091D80 3404B012 */   li    $a0, 45074
/* 0C68B4 7F091D84 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C68B8 7F091D88 00402025 */   move  $a0, $v0
/* 0C68BC 7F091D8C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68C0 7F091D90 3C0F8008 */  lui   $t7, %hi(ptr_BONDdata) # $t7, 0x8008
/* 0C68C4 7F091D94 8DEFA0B0 */  lw    $t7, %lo(ptr_BONDdata)($t7)
/* 0C68C8 7F091D98 44818000 */  mtc1  $at, $f16
/* 0C68CC 7F091D9C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C68D0 7F091DA0 3C188008 */  lui   $t8, %hi(ptr_BONDdata) # $t8, 0x8008
/* 0C68D4 7F091DA4 E5F000DC */  swc1  $f16, 0xdc($t7)
/* 0C68D8 7F091DA8 8F18A0B0 */  lw    $t8, %lo(ptr_BONDdata)($t8)
/* 0C68DC 7F091DAC 44819000 */  mtc1  $at, $f18
/* 0C68E0 7F091DB0 1000019D */  b     .L7F092428
/* 0C68E4 7F091DB4 E7122A3C */   swc1  $f18, 0x2a3c($t8)
cheats_cheat_2x_armor:
/* 0C68E8 7F091DB8 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C68EC 7F091DBC 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C68F0 7F091DC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68F4 7F091DC4 44810000 */  mtc1  $at, $f0
/* 0C68F8 7F091DC8 C4442A40 */  lwc1  $f4, 0x2a40($v0)
/* 0C68FC 7F091DCC 46040032 */  c.eq.s $f0, $f4
/* 0C6900 7F091DD0 00000000 */  nop   
/* 0C6904 7F091DD4 45010006 */  bc1t  .L7F091DF0
/* 0C6908 7F091DD8 00000000 */   nop   
/* 0C690C 7F091DDC C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0C6910 7F091DE0 4600303C */  c.lt.s $f6, $f0
/* 0C6914 7F091DE4 00000000 */  nop   
/* 0C6918 7F091DE8 45020190 */  bc1fl .L7F09242C
/* 0C691C 7F091DEC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091DF0:
/* 0C6920 7F091DF0 0FC30776 */  jal   get_textptr_for_textID
/* 0C6924 7F091DF4 3404B013 */   li    $a0, 45075
/* 0C6928 7F091DF8 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C692C 7F091DFC 00402025 */   move  $a0, $v0
/* 0C6930 7F091E00 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6934 7F091E04 2442A0B0 */  addiu $v0, %lo(ptr_BONDdata) # addiu $v0, $v0, -0x5f50
/* 0C6938 7F091E08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C693C 7F091E0C 44814000 */  mtc1  $at, $f8
/* 0C6940 7F091E10 8C590000 */  lw    $t9, ($v0)
/* 0C6944 7F091E14 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C6948 7F091E18 44815000 */  mtc1  $at, $f10
/* 0C694C 7F091E1C E72800E0 */  swc1  $f8, 0xe0($t9)
/* 0C6950 7F091E20 8C490000 */  lw    $t1, ($v0)
/* 0C6954 7F091E24 10000180 */  b     .L7F092428
/* 0C6958 7F091E28 E52A2A40 */   swc1  $f10, 0x2a40($t1)
cheats_cheat_invisibility:
/* 0C695C 7F091E2C 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C6960 7F091E30 00000000 */   nop   
/* 0C6964 7F091E34 5040017D */  beql  $v0, $zero, .L7F09242C
/* 0C6968 7F091E38 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C696C 7F091E3C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6970 7F091E40 3404B014 */   li    $a0, 45076
/* 0C6974 7F091E44 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6978 7F091E48 00402025 */   move  $a0, $v0
/* 0C697C 7F091E4C 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C6980 7F091E50 00002025 */   move  $a0, $zero
/* 0C6984 7F091E54 10000175 */  b     .L7F09242C
/* 0C6988 7F091E58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_infinite_ammo:
/* 0C698C 7F091E5C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6990 7F091E60 3404B016 */   li    $a0, 45078
/* 0C6994 7F091E64 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6998 7F091E68 00402025 */   move  $a0, $v0
/* 0C699C 7F091E6C 1000016F */  b     .L7F09242C
/* 0C69A0 7F091E70 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_dk_mode:
/* 0C69A4 7F091E74 0FC30776 */  jal   get_textptr_for_textID
/* 0C69A8 7F091E78 3404B017 */   li    $a0, 45079
/* 0C69AC 7F091E7C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C69B0 7F091E80 00402025 */   move  $a0, $v0
/* 0C69B4 7F091E84 0FC249FD */  jal   sub_GAME_7F0927F4
/* 0C69B8 7F091E88 24040001 */   li    $a0, 1
/* 0C69BC 7F091E8C 10000167 */  b     .L7F09242C
/* 0C69C0 7F091E90 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_extra_weapons:
/* 0C69C4 7F091E94 24010001 */  li    $at, 1
/* 0C69C8 7F091E98 54410164 */  bnel  $v0, $at, .L7F09242C
/* 0C69CC 7F091E9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C69D0 7F091EA0 0FC23122 */  jal   add_item_to_inventory
/* 0C69D4 7F091EA4 24040012 */   li    $a0, 18
/* 0C69D8 7F091EA8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0C69DC 7F091EAC 0FC23122 */  jal   add_item_to_inventory
/* 0C69E0 7F091EB0 24040016 */   li    $a0, 22
/* 0C69E4 7F091EB4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C69E8 7F091EB8 24040013 */  li    $a0, 19
/* 0C69EC 7F091EBC 01625021 */  addu  $t2, $t3, $v0
/* 0C69F0 7F091EC0 0FC23122 */  jal   add_item_to_inventory
/* 0C69F4 7F091EC4 AFAA0028 */   sw    $t2, 0x28($sp)
/* 0C69F8 7F091EC8 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C69FC 7F091ECC 24040014 */  li    $a0, 20
/* 0C6A00 7F091ED0 01826821 */  addu  $t5, $t4, $v0
/* 0C6A04 7F091ED4 0FC23122 */  jal   add_item_to_inventory
/* 0C6A08 7F091ED8 AFAD0028 */   sw    $t5, 0x28($sp)
/* 0C6A0C 7F091EDC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C6A10 7F091EE0 24040015 */  li    $a0, 21
/* 0C6A14 7F091EE4 01C27821 */  addu  $t7, $t6, $v0
/* 0C6A18 7F091EE8 0FC23122 */  jal   add_item_to_inventory
/* 0C6A1C 7F091EEC AFAF0028 */   sw    $t7, 0x28($sp)
/* 0C6A20 7F091EF0 8FB80028 */  lw    $t8, 0x28($sp)
/* 0C6A24 7F091EF4 2404000C */  li    $a0, 12
/* 0C6A28 7F091EF8 0302C821 */  addu  $t9, $t8, $v0
/* 0C6A2C 7F091EFC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A30 7F091F00 AFB90028 */   sw    $t9, 0x28($sp)
/* 0C6A34 7F091F04 2404000C */  li    $a0, 12
/* 0C6A38 7F091F08 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A3C 7F091F0C 00402825 */   move  $a1, $v0
/* 0C6A40 7F091F10 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A44 7F091F14 2404000D */   li    $a0, 13
/* 0C6A48 7F091F18 2404000D */  li    $a0, 13
/* 0C6A4C 7F091F1C 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A50 7F091F20 00402825 */   move  $a1, $v0
/* 0C6A54 7F091F24 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A58 7F091F28 24040001 */   li    $a0, 1
/* 0C6A5C 7F091F2C 24040001 */  li    $a0, 1
/* 0C6A60 7F091F30 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A64 7F091F34 00402825 */   move  $a1, $v0
/* 0C6A68 7F091F38 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C6A6C 7F091F3C 5920013B */  blezl $t1, .L7F09242C
/* 0C6A70 7F091F40 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6A74 7F091F44 0FC30776 */  jal   get_textptr_for_textID
/* 0C6A78 7F091F48 3404B018 */   li    $a0, 45080
/* 0C6A7C 7F091F4C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6A80 7F091F50 00402025 */   move  $a0, $v0
/* 0C6A84 7F091F54 10000135 */  b     .L7F09242C
/* 0C6A88 7F091F58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_tiny_bond:
/* 0C6A8C 7F091F5C 24010001 */  li    $at, 1
/* 0C6A90 7F091F60 14410131 */  bne   $v0, $at, .L7F092428
/* 0C6A94 7F091F64 3C0B8008 */   lui   $t3, %hi(cur_player_stat_ptr) # $t3, 0x8008
/* 0C6A98 7F091F68 8D6BA0B4 */  lw    $t3, %lo(cur_player_stat_ptr)($t3)
/* 0C6A9C 7F091F6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6AA0 7F091F70 44818000 */  mtc1  $at, $f16
/* 0C6AA4 7F091F74 C5720064 */  lwc1  $f18, 0x64($t3)
/* 0C6AA8 7F091F78 46128032 */  c.eq.s $f16, $f18
/* 0C6AAC 7F091F7C 00000000 */  nop   
/* 0C6AB0 7F091F80 4502012A */  bc1fl .L7F09242C
/* 0C6AB4 7F091F84 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AB8 7F091F88 0FC30776 */  jal   get_textptr_for_textID
/* 0C6ABC 7F091F8C 3404B019 */   li    $a0, 45081
/* 0C6AC0 7F091F90 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6AC4 7F091F94 00402025 */   move  $a0, $v0
/* 0C6AC8 7F091F98 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C6ACC 7F091F9C 3C0A8008 */  lui   $t2, %hi(cur_player_stat_ptr) # $t2, 0x8008
/* 0C6AD0 7F091FA0 44810000 */  mtc1  $at, $f0
/* 0C6AD4 7F091FA4 8D4AA0B4 */  lw    $t2, %lo(cur_player_stat_ptr)($t2)
/* 0C6AD8 7F091FA8 3C0C8008 */  lui   $t4, %hi(ptr_BONDdata) # $t4, 0x8008
/* 0C6ADC 7F091FAC E5400064 */  swc1  $f0, 0x64($t2)
/* 0C6AE0 7F091FB0 8D8CA0B0 */  lw    $t4, %lo(ptr_BONDdata)($t4)
/* 0C6AE4 7F091FB4 8D8400D4 */  lw    $a0, 0xd4($t4)
/* 0C6AE8 7F091FB8 5080011C */  beql  $a0, $zero, .L7F09242C
/* 0C6AEC 7F091FBC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AF0 7F091FC0 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C6AF4 7F091FC4 46002182 */  mul.s $f6, $f4, $f0
/* 0C6AF8 7F091FC8 44053000 */  mfc1  $a1, $f6
/* 0C6AFC 7F091FCC 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C6B00 7F091FD0 00000000 */   nop   
/* 0C6B04 7F091FD4 10000115 */  b     .L7F09242C
/* 0C6B08 7F091FD8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_paintball:
/* 0C6B0C 7F091FDC 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B10 7F091FE0 3404B01A */   li    $a0, 45082
/* 0C6B14 7F091FE4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B18 7F091FE8 00402025 */   move  $a0, $v0
/* 0C6B1C 7F091FEC 1000010F */  b     .L7F09242C
/* 0C6B20 7F091FF0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_10x_health:
/* 0C6B24 7F091FF4 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6B28 7F091FF8 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C6B2C 7F091FFC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B30 7F092000 44810000 */  mtc1  $at, $f0
/* 0C6B34 7F092004 C4482A3C */  lwc1  $f8, 0x2a3c($v0)
/* 0C6B38 7F092008 46080032 */  c.eq.s $f0, $f8
/* 0C6B3C 7F09200C 00000000 */  nop   
/* 0C6B40 7F092010 45010006 */  bc1t  .L7F09202C
/* 0C6B44 7F092014 00000000 */   nop   
/* 0C6B48 7F092018 C44A00DC */  lwc1  $f10, 0xdc($v0)
/* 0C6B4C 7F09201C 4600503C */  c.lt.s $f10, $f0
/* 0C6B50 7F092020 00000000 */  nop   
/* 0C6B54 7F092024 45020101 */  bc1fl .L7F09242C
/* 0C6B58 7F092028 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F09202C:
/* 0C6B5C 7F09202C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B60 7F092030 3404B01B */   li    $a0, 45083
/* 0C6B64 7F092034 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B68 7F092038 00402025 */   move  $a0, $v0
/* 0C6B6C 7F09203C 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6B70 7F092040 2442A0B0 */  addiu $v0, %lo(ptr_BONDdata) # addiu $v0, $v0, -0x5f50
/* 0C6B74 7F092044 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B78 7F092048 44818000 */  mtc1  $at, $f16
/* 0C6B7C 7F09204C 8C4D0000 */  lw    $t5, ($v0)
/* 0C6B80 7F092050 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C6B84 7F092054 44819000 */  mtc1  $at, $f18
/* 0C6B88 7F092058 E5B000DC */  swc1  $f16, 0xdc($t5)
/* 0C6B8C 7F09205C 8C4E0000 */  lw    $t6, ($v0)
/* 0C6B90 7F092060 100000F1 */  b     .L7F092428
/* 0C6B94 7F092064 E5D22A3C */   swc1  $f18, 0x2a3c($t6)
cheats_cheat_magnum:
/* 0C6B98 7F092068 24010001 */  li    $at, 1
/* 0C6B9C 7F09206C 544100EF */  bnel  $v0, $at, .L7F09242C
/* 0C6BA0 7F092070 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BA4 7F092074 0FC23122 */  jal   add_item_to_inventory
/* 0C6BA8 7F092078 24040012 */   li    $a0, 18
/* 0C6BAC 7F09207C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BB0 7F092080 2404000C */   li    $a0, 12
/* 0C6BB4 7F092084 2404000C */  li    $a0, 12
/* 0C6BB8 7F092088 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6BBC 7F09208C 00402825 */   move  $a1, $v0
/* 0C6BC0 7F092090 100000E6 */  b     .L7F09242C
/* 0C6BC4 7F092094 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_laser:
/* 0C6BC8 7F092098 24010001 */  li    $at, 1
/* 0C6BCC 7F09209C 544100E3 */  bnel  $v0, $at, .L7F09242C
/* 0C6BD0 7F0920A0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BD4 7F0920A4 0FC23122 */  jal   add_item_to_inventory
/* 0C6BD8 7F0920A8 24040016 */   li    $a0, 22
/* 0C6BDC 7F0920AC 100000DF */  b     .L7F09242C
/* 0C6BE0 7F0920B0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldengun:
/* 0C6BE4 7F0920B4 24010001 */  li    $at, 1
/* 0C6BE8 7F0920B8 544100DC */  bnel  $v0, $at, .L7F09242C
/* 0C6BEC 7F0920BC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BF0 7F0920C0 0FC23122 */  jal   add_item_to_inventory
/* 0C6BF4 7F0920C4 24040013 */   li    $a0, 19
/* 0C6BF8 7F0920C8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BFC 7F0920CC 2404000D */   li    $a0, 13
/* 0C6C00 7F0920D0 2404000D */  li    $a0, 13
/* 0C6C04 7F0920D4 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C08 7F0920D8 00402825 */   move  $a1, $v0
/* 0C6C0C 7F0920DC 100000D3 */  b     .L7F09242C
/* 0C6C10 7F0920E0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_silverpp7:
/* 0C6C14 7F0920E4 24010001 */  li    $at, 1
/* 0C6C18 7F0920E8 544100D0 */  bnel  $v0, $at, .L7F09242C
/* 0C6C1C 7F0920EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C20 7F0920F0 0FC23122 */  jal   add_item_to_inventory
/* 0C6C24 7F0920F4 24040014 */   li    $a0, 20
/* 0C6C28 7F0920F8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C2C 7F0920FC 24040001 */   li    $a0, 1
/* 0C6C30 7F092100 24040001 */  li    $a0, 1
/* 0C6C34 7F092104 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C38 7F092108 00402825 */   move  $a1, $v0
/* 0C6C3C 7F09210C 100000C7 */  b     .L7F09242C
/* 0C6C40 7F092110 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldpp7:
/* 0C6C44 7F092114 24010001 */  li    $at, 1
/* 0C6C48 7F092118 544100C4 */  bnel  $v0, $at, .L7F09242C
/* 0C6C4C 7F09211C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C50 7F092120 0FC23122 */  jal   add_item_to_inventory
/* 0C6C54 7F092124 24040015 */   li    $a0, 21
/* 0C6C58 7F092128 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C5C 7F09212C 24040001 */   li    $a0, 1
/* 0C6C60 7F092130 24040001 */  li    $a0, 1
/* 0C6C64 7F092134 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C68 7F092138 00402825 */   move  $a1, $v0
/* 0C6C6C 7F09213C 100000BB */  b     .L7F09242C
/* 0C6C70 7F092140 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invisibility_mp:
/* 0C6C74 7F092144 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C6C78 7F092148 44816000 */  mtc1  $at, $f12
/* 0C6C7C 7F09214C 3C018005 */  lui   $at, %hi(finalamount) # $at, 0x8005
/* 0C6C80 7F092150 0FC20284 */  jal   set_curplayer_fade
/* 0C6C84 7F092154 C42E73D8 */   lwc1  $f14, %lo(finalamount)($at)
/* 0C6C88 7F092158 100000B4 */  b     .L7F09242C
/* 0C6C8C 7F09215C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_fast:
/* 0C6C90 7F092160 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C6C94 7F092164 00000000 */   nop   
/* 0C6C98 7F092168 544000B0 */  bnezl $v0, .L7F09242C
/* 0C6C9C 7F09216C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CA0 7F092170 0FC30776 */  jal   get_textptr_for_textID
/* 0C6CA4 7F092174 3404B01D */   li    $a0, 45085
/* 0C6CA8 7F092178 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6CAC 7F09217C 00402025 */   move  $a0, $v0
/* 0C6CB0 7F092180 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C6CB4 7F092184 24040001 */   li    $a0, 1
/* 0C6CB8 7F092188 100000A8 */  b     .L7F09242C
/* 0C6CBC 7F09218C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_pos:
/* 0C6CC0 7F092190 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C6CC4 7F092194 00000000 */   nop   
/* 0C6CC8 7F092198 544000A4 */  bnezl $v0, .L7F09242C
/* 0C6CCC 7F09219C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CD0 7F0921A0 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C6CD4 7F0921A4 24040001 */   li    $a0, 1
/* 0C6CD8 7F0921A8 100000A0 */  b     .L7F09242C
/* 0C6CDC 7F0921AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_fast_ani:
/* 0C6CE0 7F0921B0 0FC08179 */  jal   get_animation_rate
/* 0C6CE4 7F0921B4 00000000 */   nop   
/* 0C6CE8 7F0921B8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6CEC 7F0921BC 44812000 */  mtc1  $at, $f4
/* 0C6CF0 7F0921C0 00000000 */  nop   
/* 0C6CF4 7F0921C4 4604003C */  c.lt.s $f0, $f4
/* 0C6CF8 7F0921C8 00000000 */  nop   
/* 0C6CFC 7F0921CC 45020097 */  bc1fl .L7F09242C
/* 0C6D00 7F0921D0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D04 7F0921D4 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D08 7F0921D8 3404B034 */   li    $a0, 45108
/* 0C6D0C 7F0921DC 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D10 7F0921E0 00402025 */   move  $a0, $v0
/* 0C6D14 7F0921E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6D18 7F0921E8 44816000 */  mtc1  $at, $f12
/* 0C6D1C 7F0921EC 0FC08150 */  jal   animation_speed_related
/* 0C6D20 7F0921F0 00000000 */   nop   
/* 0C6D24 7F0921F4 1000008D */  b     .L7F09242C
/* 0C6D28 7F0921F8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_slow_ani:
/* 0C6D2C 7F0921FC 0FC08179 */  jal   get_animation_rate
/* 0C6D30 7F092200 00000000 */   nop   
/* 0C6D34 7F092204 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D38 7F092208 44813000 */  mtc1  $at, $f6
/* 0C6D3C 7F09220C 00000000 */  nop   
/* 0C6D40 7F092210 4600303C */  c.lt.s $f6, $f0
/* 0C6D44 7F092214 00000000 */  nop   
/* 0C6D48 7F092218 45020084 */  bc1fl .L7F09242C
/* 0C6D4C 7F09221C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D50 7F092220 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D54 7F092224 3404B032 */   li    $a0, 45106
/* 0C6D58 7F092228 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D5C 7F09222C 00402025 */   move  $a0, $v0
/* 0C6D60 7F092230 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D64 7F092234 44816000 */  mtc1  $at, $f12
/* 0C6D68 7F092238 0FC08150 */  jal   animation_speed_related
/* 0C6D6C 7F09223C 00000000 */   nop   
/* 0C6D70 7F092240 1000007A */  b     .L7F09242C
/* 0C6D74 7F092244 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rockets:
/* 0C6D78 7F092248 24010001 */  li    $at, 1
/* 0C6D7C 7F09224C 14410076 */  bne   $v0, $at, .L7F092428
/* 0C6D80 7F092250 24040019 */   li    $a0, 25
/* 0C6D84 7F092254 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6D88 7F092258 24050019 */   li    $a1, 25
/* 0C6D8C 7F09225C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6D90 7F092260 24040006 */   li    $a0, 6
/* 0C6D94 7F092264 24040006 */  li    $a0, 6
/* 0C6D98 7F092268 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6D9C 7F09226C 00402825 */   move  $a1, $v0
/* 0C6DA0 7F092270 1000006E */  b     .L7F09242C
/* 0C6DA4 7F092274 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_grenade_launch:
/* 0C6DA8 7F092278 24010001 */  li    $at, 1
/* 0C6DAC 7F09227C 1441006A */  bne   $v0, $at, .L7F092428
/* 0C6DB0 7F092280 24040018 */   li    $a0, 24
/* 0C6DB4 7F092284 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DB8 7F092288 24050018 */   li    $a1, 24
/* 0C6DBC 7F09228C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DC0 7F092290 2404000B */   li    $a0, 11
/* 0C6DC4 7F092294 2404000B */  li    $a0, 11
/* 0C6DC8 7F092298 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DCC 7F09229C 00402825 */   move  $a1, $v0
/* 0C6DD0 7F0922A0 10000062 */  b     .L7F09242C
/* 0C6DD4 7F0922A4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rcp90:
/* 0C6DD8 7F0922A8 24010001 */  li    $at, 1
/* 0C6DDC 7F0922AC 1441005E */  bne   $v0, $at, .L7F092428
/* 0C6DE0 7F0922B0 2404000E */   li    $a0, 14
/* 0C6DE4 7F0922B4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DE8 7F0922B8 2405000E */   li    $a1, 14
/* 0C6DEC 7F0922BC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DF0 7F0922C0 24040001 */   li    $a0, 1
/* 0C6DF4 7F0922C4 24040001 */  li    $a0, 1
/* 0C6DF8 7F0922C8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DFC 7F0922CC 00402825 */   move  $a1, $v0
/* 0C6E00 7F0922D0 10000056 */  b     .L7F09242C
/* 0C6E04 7F0922D4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_throwing_knife:
/* 0C6E08 7F0922D8 24010001 */  li    $at, 1
/* 0C6E0C 7F0922DC 14410052 */  bne   $v0, $at, .L7F092428
/* 0C6E10 7F0922E0 24040003 */   li    $a0, 3
/* 0C6E14 7F0922E4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E18 7F0922E8 24050003 */   li    $a1, 3
/* 0C6E1C 7F0922EC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6E20 7F0922F0 2404000A */   li    $a0, 10
/* 0C6E24 7F0922F4 2404000A */  li    $a0, 10
/* 0C6E28 7F0922F8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6E2C 7F0922FC 00402825 */   move  $a1, $v0
/* 0C6E30 7F092300 1000004A */  b     .L7F09242C
/* 0C6E34 7F092304 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_hunting_knife:
/* 0C6E38 7F092308 24010001 */  li    $at, 1
/* 0C6E3C 7F09230C 14410046 */  bne   $v0, $at, .L7F092428
/* 0C6E40 7F092310 24040002 */   li    $a0, 2
/* 0C6E44 7F092314 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E48 7F092318 24050002 */   li    $a1, 2
/* 0C6E4C 7F09231C 10000043 */  b     .L7F09242C
/* 0C6E50 7F092320 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_laser:
/* 0C6E54 7F092324 24010001 */  li    $at, 1
/* 0C6E58 7F092328 1441003F */  bne   $v0, $at, .L7F092428
/* 0C6E5C 7F09232C 24040016 */   li    $a0, 22
/* 0C6E60 7F092330 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E64 7F092334 24050016 */   li    $a1, 22
/* 0C6E68 7F092338 1000003C */  b     .L7F09242C
/* 0C6E6C 7F09233C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlockcheat:
/* 0C6E70 7F092340 3C048003 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 0C6E74 7F092344 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0C6E78 7F092348 24C5FFDD */  addiu $a1, $a2, -0x23
/* 0C6E7C 7F09234C 04800036 */  bltz  $a0, .L7F092428
/* 0C6E80 7F092350 28810004 */   slti  $at, $a0, 4
/* 0C6E84 7F092354 50200035 */  beql  $at, $zero, .L7F09242C
/* 0C6E88 7F092358 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6E8C 7F09235C 0FC079D8 */  jal   sub_GAME_7F01E760
/* 0C6E90 7F092360 00000000 */   nop   
/* 0C6E94 7F092364 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C6E98 7F092368 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6E9C 7F09236C 2405009F */  li    $a1, 159
/* 0C6EA0 7F092370 0C002382 */  jal   play_sfx_a1
/* 0C6EA4 7F092374 00003025 */   move  $a2, $zero
/* 0C6EA8 7F092378 1000002C */  b     .L7F09242C
/* 0C6EAC 7F09237C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlocklevel:
/* 0C6EB0 7F092380 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6EB4 7F092384 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EB8 7F092388 8C440000 */  lw    $a0, ($v0)
/* 0C6EBC 7F09238C 24C8FFC9 */  addiu $t0, $a2, -0x37
/* 0C6EC0 7F092390 04800025 */  bltz  $a0, .L7F092428
/* 0C6EC4 7F092394 28810004 */   slti  $at, $a0, 4
/* 0C6EC8 7F092398 10200023 */  beqz  $at, .L7F092428
/* 0C6ECC 7F09239C 00001825 */   move  $v1, $zero
/* 0C6ED0 7F0923A0 19000014 */  blez  $t0, .L7F0923F4
/* 0C6ED4 7F0923A4 00002825 */   move  $a1, $zero
.L7F0923A8:
/* 0C6ED8 7F0923A8 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6EDC 7F0923AC 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EE0 7F0923B0 8C440000 */  lw    $a0, ($v0)
/* 0C6EE4 7F0923B4 00003025 */  move  $a2, $zero
/* 0C6EE8 7F0923B8 AFA30018 */  sw    $v1, 0x18($sp)
/* 0C6EEC 7F0923BC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C6EF0 7F0923C0 0FC078B0 */  jal   doesFolderHaveStageUnlockedAtDifficulty
/* 0C6EF4 7F0923C4 AFA80020 */   sw    $t0, 0x20($sp)
/* 0C6EF8 7F0923C8 24010003 */  li    $at, 3
/* 0C6EFC 7F0923CC 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C6F00 7F0923D0 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0C6F04 7F0923D4 14410002 */  bne   $v0, $at, .L7F0923E0
/* 0C6F08 7F0923D8 8FA80020 */   lw    $t0, 0x20($sp)
/* 0C6F0C 7F0923DC 24630001 */  addiu $v1, $v1, 1
.L7F0923E0:
/* 0C6F10 7F0923E0 24A50001 */  addiu $a1, $a1, 1
/* 0C6F14 7F0923E4 14A8FFF0 */  bne   $a1, $t0, .L7F0923A8
/* 0C6F18 7F0923E8 00000000 */   nop   
/* 0C6F1C 7F0923EC 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6F20 7F0923F0 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
.L7F0923F4:
/* 0C6F24 7F0923F4 246F0001 */  addiu $t7, $v1, 1
/* 0C6F28 7F0923F8 150F000B */  bne   $t0, $t7, .L7F092428
/* 0C6F2C 7F0923FC 2505FFFF */   addiu $a1, $t0, -1
/* 0C6F30 7F092400 3C0705F5 */  lui   $a3, (0x05F5E0FF >> 16) # lui $a3, 0x5f5
/* 0C6F34 7F092404 34E7E0FF */  ori   $a3, (0x05F5E0FF & 0xFFFF) # ori $a3, $a3, 0xe0ff
/* 0C6F38 7F092408 8C440000 */  lw    $a0, ($v0)
/* 0C6F3C 7F09240C 0FC0797E */  jal   unlock_stage_in_folder_on_difficulty
/* 0C6F40 7F092410 00003025 */   move  $a2, $zero
/* 0C6F44 7F092414 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C6F48 7F092418 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6F4C 7F09241C 2405009F */  li    $a1, 159
/* 0C6F50 7F092420 0C002382 */  jal   play_sfx_a1
/* 0C6F54 7F092424 00003025 */   move  $a2, $zero
cheats_debug_return_saved_ra:
.L7F092428:
/* 0C6F58 7F092428 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09242C:
/* 0C6F5C 7F09242C 27BD0040 */  addiu $sp, $sp, 0x40
/* 0C6F60 7F092430 03E00008 */  jr    $ra
/* 0C6F64 7F092434 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F092438(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:800573DC*/
glabel jpt_800573DC
.word cheat_button_default
.word cheat_button_invincibility
.word cheat_button_all_guns
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_line_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_unknown
.word cheat_button_infinite_ammo
.word cheat_button_dkmode
.word cheat_button_default
.word cheat_button_unknown_0
.word cheat_button_paintball
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_mp_invis
.word cheat_button_default
.word cheat_button_fast_mode
.word cheat_button_debug_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/

.text
glabel sub_GAME_7F092438
/* 0C6F68 7F092438 00047100 */  sll   $t6, $a0, 4
/* 0C6F6C 7F09243C 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C6F70 7F092440 01EE7821 */  addu  $t7, $t7, $t6
/* 0C6F74 7F092444 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C6F78 7F092448 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C6F7C 7F09244C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6F80 7F092450 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C6F84 7F092454 0FC26C54 */  jal   get_cur_playernum
/* 0C6F88 7F092458 AFAF001C */   sw    $t7, 0x1c($sp)
/* 0C6F8C 7F09245C 0FC26919 */  jal   get_num_players
/* 0C6F90 7F092460 AFA20018 */   sw    $v0, 0x18($sp)
/* 0C6F94 7F092464 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0C6F98 7F092468 8FA40020 */  lw    $a0, 0x20($sp)
/* 0C6F9C 7F09246C 30780010 */  andi  $t8, $v1, 0x10
/* 0C6FA0 7F092470 17000010 */  bnez  $t8, .L7F0924B4
/* 0C6FA4 7F092474 30790020 */   andi  $t9, $v1, 0x20
/* 0C6FA8 7F092478 1720000B */  bnez  $t9, .L7F0924A8
/* 0C6FAC 7F09247C 3C088008 */   lui   $t0, %hi(off_CODE_bss_80079E30) # $t0, 0x8008
/* 0C6FB0 7F092480 8FAA0018 */  lw    $t2, 0x18($sp)
/* 0C6FB4 7F092484 25089E30 */  addiu $t0, %lo(off_CODE_bss_80079E30) # addiu $t0, $t0, -0x61d0
/* 0C6FB8 7F092488 00881821 */  addu  $v1, $a0, $t0
/* 0C6FBC 7F09248C 90690000 */  lbu   $t1, ($v1)
/* 0C6FC0 7F092490 240B0001 */  li    $t3, 1
/* 0C6FC4 7F092494 014B6004 */  sllv  $t4, $t3, $t2
/* 0C6FC8 7F092498 01806827 */  not   $t5, $t4
/* 0C6FCC 7F09249C 012D7024 */  and   $t6, $t1, $t5
/* 0C6FD0 7F0924A0 10000004 */  b     .L7F0924B4
/* 0C6FD4 7F0924A4 A06E0000 */   sb    $t6, ($v1)
.L7F0924A8:
/* 0C6FD8 7F0924A8 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C6FDC 7F0924AC 00240821 */  addu  $at, $at, $a0
/* 0C6FE0 7F0924B0 A0209E30 */  sb    $zero, %lo(off_CODE_bss_80079E30)($at)
.L7F0924B4:
/* 0C6FE4 7F0924B4 248FFFFF */  addiu $t7, $a0, -1
/* 0C6FE8 7F0924B8 2DE1004A */  sltiu $at, $t7, 0x4a
/* 0C6FEC 7F0924BC 1020007C */  beqz  $at, .L7F0926B0
/* 0C6FF0 7F0924C0 000F7880 */   sll   $t7, $t7, 2
/* 0C6FF4 7F0924C4 3C018005 */  lui   $at, %hi(jpt_800573DC)
/* 0C6FF8 7F0924C8 002F0821 */  addu  $at, $at, $t7
/* 0C6FFC 7F0924CC 8C2F73DC */  lw    $t7, %lo(jpt_800573DC)($at)
/* 0C7000 7F0924D0 01E00008 */  jr    $t7
/* 0C7004 7F0924D4 00000000 */   nop   
cheat_button_invincibility:
/* 0C7008 7F0924D8 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C700C 7F0924DC 00000000 */   nop   
/* 0C7010 7F0924E0 50400074 */  beql  $v0, $zero, .L7F0926B4
/* 0C7014 7F0924E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7018 7F0924E8 0FC30776 */  jal   get_textptr_for_textID
/* 0C701C 7F0924EC 3404B01E */   li    $a0, 45086
/* 0C7020 7F0924F0 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7024 7F0924F4 00402025 */   move  $a0, $v0
/* 0C7028 7F0924F8 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C702C 7F0924FC 00002025 */   move  $a0, $zero
/* 0C7030 7F092500 1000006C */  b     .L7F0926B4
/* 0C7034 7F092504 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_all_guns:
/* 0C7038 7F092508 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C703C 7F09250C 00000000 */   nop   
/* 0C7040 7F092510 50400068 */  beql  $v0, $zero, .L7F0926B4
/* 0C7044 7F092514 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7048 7F092518 0FC30776 */  jal   get_textptr_for_textID
/* 0C704C 7F09251C 3404B01F */   li    $a0, 45087
/* 0C7050 7F092520 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7054 7F092524 00402025 */   move  $a0, $v0
/* 0C7058 7F092528 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C705C 7F09252C 00002025 */   move  $a0, $zero
/* 0C7060 7F092530 10000060 */  b     .L7F0926B4
/* 0C7064 7F092534 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_line_mode:
/* 0C7068 7F092538 0FC243FA */  jal   set_linemode_flag
/* 0C706C 7F09253C 00002025 */   move  $a0, $zero
/* 0C7070 7F092540 1000005C */  b     .L7F0926B4
/* 0C7074 7F092544 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown:
/* 0C7078 7F092548 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C707C 7F09254C 00000000 */   nop   
/* 0C7080 7F092550 54400058 */  bnezl $v0, .L7F0926B4
/* 0C7084 7F092554 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7088 7F092558 0FC30776 */  jal   get_textptr_for_textID
/* 0C708C 7F09255C 3404B020 */   li    $a0, 45088
/* 0C7090 7F092560 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7094 7F092564 00402025 */   move  $a0, $v0
/* 0C7098 7F092568 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C709C 7F09256C 24040001 */   li    $a0, 1
/* 0C70A0 7F092570 10000050 */  b     .L7F0926B4
/* 0C70A4 7F092574 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_infinite_ammo:
/* 0C70A8 7F092578 0FC30776 */  jal   get_textptr_for_textID
/* 0C70AC 7F09257C 3404B022 */   li    $a0, 45090
/* 0C70B0 7F092580 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70B4 7F092584 00402025 */   move  $a0, $v0
/* 0C70B8 7F092588 1000004A */  b     .L7F0926B4
/* 0C70BC 7F09258C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_dkmode:
/* 0C70C0 7F092590 0FC30776 */  jal   get_textptr_for_textID
/* 0C70C4 7F092594 3404B023 */   li    $a0, 45091
/* 0C70C8 7F092598 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70CC 7F09259C 00402025 */   move  $a0, $v0
/* 0C70D0 7F0925A0 0FC249FD */  jal   sub_GAME_7F0927F4
/* 0C70D4 7F0925A4 00002025 */   move  $a0, $zero
/* 0C70D8 7F0925A8 10000042 */  b     .L7F0926B4
/* 0C70DC 7F0925AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown_0:
/* 0C70E0 7F0925B0 24010001 */  li    $at, 1
/* 0C70E4 7F0925B4 1441003E */  bne   $v0, $at, .L7F0926B0
/* 0C70E8 7F0925B8 3C188008 */   lui   $t8, %hi(cur_player_stat_ptr) # $t8, 0x8008
/* 0C70EC 7F0925BC 8F18A0B4 */  lw    $t8, %lo(cur_player_stat_ptr)($t8)
/* 0C70F0 7F0925C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C70F4 7F0925C4 44812000 */  mtc1  $at, $f4
/* 0C70F8 7F0925C8 C7060064 */  lwc1  $f6, 0x64($t8)
/* 0C70FC 7F0925CC 46062032 */  c.eq.s $f4, $f6
/* 0C7100 7F0925D0 00000000 */  nop   
/* 0C7104 7F0925D4 45030037 */  bc1tl .L7F0926B4
/* 0C7108 7F0925D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C710C 7F0925DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C7110 7F0925E0 3404B024 */   li    $a0, 45092
/* 0C7114 7F0925E4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7118 7F0925E8 00402025 */   move  $a0, $v0
/* 0C711C 7F0925EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7120 7F0925F0 3C198008 */  lui   $t9, %hi(cur_player_stat_ptr) # $t9, 0x8008
/* 0C7124 7F0925F4 8F39A0B4 */  lw    $t9, %lo(cur_player_stat_ptr)($t9)
/* 0C7128 7F0925F8 44814000 */  mtc1  $at, $f8
/* 0C712C 7F0925FC 3C088008 */  lui   $t0, %hi(ptr_BONDdata) # $t0, 0x8008
/* 0C7130 7F092600 E7280064 */  swc1  $f8, 0x64($t9)
/* 0C7134 7F092604 8D08A0B0 */  lw    $t0, %lo(ptr_BONDdata)($t0)
/* 0C7138 7F092608 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C713C 7F09260C 50800029 */  beql  $a0, $zero, .L7F0926B4
/* 0C7140 7F092610 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7144 7F092614 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0C7148 7F092618 46000280 */  add.s $f10, $f0, $f0
/* 0C714C 7F09261C 44055000 */  mfc1  $a1, $f10
/* 0C7150 7F092620 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7154 7F092624 00000000 */   nop   
/* 0C7158 7F092628 10000022 */  b     .L7F0926B4
/* 0C715C 7F09262C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_paintball:
/* 0C7160 7F092630 0FC30776 */  jal   get_textptr_for_textID
/* 0C7164 7F092634 3404B025 */   li    $a0, 45093
/* 0C7168 7F092638 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C716C 7F09263C 00402025 */   move  $a0, $v0
/* 0C7170 7F092640 1000001C */  b     .L7F0926B4
/* 0C7174 7F092644 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_mp_invis:
/* 0C7178 7F092648 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C717C 7F09264C 44816000 */  mtc1  $at, $f12
/* 0C7180 7F092650 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7184 7F092654 44817000 */  mtc1  $at, $f14
/* 0C7188 7F092658 0FC20284 */  jal   set_curplayer_fade
/* 0C718C 7F09265C 00000000 */   nop   
/* 0C7190 7F092660 10000014 */  b     .L7F0926B4
/* 0C7194 7F092664 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_fast_mode:
/* 0C7198 7F092668 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C719C 7F09266C 00000000 */   nop   
/* 0C71A0 7F092670 50400010 */  beql  $v0, $zero, .L7F0926B4
/* 0C71A4 7F092674 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71A8 7F092678 0FC30776 */  jal   get_textptr_for_textID
/* 0C71AC 7F09267C 3404B027 */   li    $a0, 45095
/* 0C71B0 7F092680 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C71B4 7F092684 00402025 */   move  $a0, $v0
/* 0C71B8 7F092688 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C71BC 7F09268C 00002025 */   move  $a0, $zero
/* 0C71C0 7F092690 10000008 */  b     .L7F0926B4
/* 0C71C4 7F092694 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_debug_mode:
/* 0C71C8 7F092698 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C71CC 7F09269C 00000000 */   nop   
/* 0C71D0 7F0926A0 50400004 */  beql  $v0, $zero, .L7F0926B4
/* 0C71D4 7F0926A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71D8 7F0926A8 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C71DC 7F0926AC 00002025 */   move  $a0, $zero
cheat_button_default:
.L7F0926B0:
/* 0C71E0 7F0926B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0926B4:
/* 0C71E4 7F0926B4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C71E8 7F0926B8 03E00008 */  jr    $ra
/* 0C71EC 7F0926BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0926C0(void) {
    s32 sp30;
    s32 temp_s4;
    s32 temp_s0;
    s32 temp_s3;
    s32 phi_s3;
    void *phi_s1;
    s32 phi_s0;

    // Node 0
    temp_s4 = get_num_players();
    sp30 = get_cur_playernum();
    if (temp_s4 > 0)
    {
        // Node 1
        phi_s3 = 0;
loop_2:
        // Node 2
        set_cur_player(phi_s3);
        phi_s1 = &D_8003F80C+0x10;
        phi_s0 = 1;
loop_3:
        // Node 3
        if ((phi_s1->unk-4 & 0x40) != 0)
        {
            // Node 4
            if (sub_GAME_7F0927BC(phi_s0) != 0)
            {
                // Node 5
                sub_GAME_7F092438(phi_s0);
            }
        }
        // Node 6
        temp_s0 = (phi_s0 + 1);
        phi_s1 = (phi_s1 + 0x10);
        phi_s0 = temp_s0;
        if (temp_s0 != 0x4b)
        {
            goto loop_3;
        }
        // Node 7
        temp_s3 = (phi_s3 + 1);
        phi_s3 = temp_s3;
        if (temp_s3 != temp_s4)
        {
            goto loop_2;
        }
    }
    // Node 8
    return set_cur_player(sp30);
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
.text
glabel sub_GAME_7F0926C0
/* 0C71F0 7F0926C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C71F4 7F0926C4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C71F8 7F0926C8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C71FC 7F0926CC AFB30024 */  sw    $s3, 0x24($sp)
/* 0C7200 7F0926D0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C7204 7F0926D4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C7208 7F0926D8 0FC26919 */  jal   get_num_players
/* 0C720C 7F0926DC AFB00018 */   sw    $s0, 0x18($sp)
/* 0C7210 7F0926E0 0FC26C54 */  jal   get_cur_playernum
/* 0C7214 7F0926E4 0040A025 */   move  $s4, $v0
/* 0C7218 7F0926E8 AFA20030 */  sw    $v0, 0x30($sp)
/* 0C721C 7F0926EC 1A800017 */  blez  $s4, .L7F09274C
/* 0C7220 7F0926F0 00009825 */   move  $s3, $zero
/* 0C7224 7F0926F4 2412004B */  li    $s2, 75
.L7F0926F8:
/* 0C7228 7F0926F8 0FC26C43 */  jal   set_cur_player
/* 0C722C 7F0926FC 02602025 */   move  $a0, $s3
/* 0C7230 7F092700 3C118004 */  lui   $s1, %hi(D_8003F80C+0x10) # $s1, 0x8004
/* 0C7234 7F092704 2631F81C */  addiu $s1, %lo(D_8003F80C+0x10) # addiu $s1, $s1, -0x7e4
/* 0C7238 7F092708 24100001 */  li    $s0, 1
.L7F09270C:
/* 0C723C 7F09270C 8E2EFFFC */  lw    $t6, -4($s1)
/* 0C7240 7F092710 31CF0040 */  andi  $t7, $t6, 0x40
/* 0C7244 7F092714 51E00008 */  beql  $t7, $zero, .L7F092738
/* 0C7248 7F092718 26100001 */   addiu $s0, $s0, 1
/* 0C724C 7F09271C 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0C7250 7F092720 02002025 */   move  $a0, $s0
/* 0C7254 7F092724 50400004 */  beql  $v0, $zero, .L7F092738
/* 0C7258 7F092728 26100001 */   addiu $s0, $s0, 1
/* 0C725C 7F09272C 0FC2490E */  jal   sub_GAME_7F092438
/* 0C7260 7F092730 02002025 */   move  $a0, $s0
/* 0C7264 7F092734 26100001 */  addiu $s0, $s0, 1
.L7F092738:
/* 0C7268 7F092738 1612FFF4 */  bne   $s0, $s2, .L7F09270C
/* 0C726C 7F09273C 26310010 */   addiu $s1, $s1, 0x10
/* 0C7270 7F092740 26730001 */  addiu $s3, $s3, 1
/* 0C7274 7F092744 1674FFEC */  bne   $s3, $s4, .L7F0926F8
/* 0C7278 7F092748 00000000 */   nop   
.L7F09274C:
/* 0C727C 7F09274C 0FC26C43 */  jal   set_cur_player
/* 0C7280 7F092750 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C7284 7F092754 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C7288 7F092758 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C728C 7F09275C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C7290 7F092760 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C7294 7F092764 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C7298 7F092768 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C729C 7F09276C 03E00008 */  jr    $ra
/* 0C72A0 7F092770 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F092774(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
.text
glabel sub_GAME_7F092774
/* 0C72A4 7F092774 00047100 */  sll   $t6, $a0, 4
/* 0C72A8 7F092778 3C028004 */  lui   $v0, %hi(D_8003F804)
/* 0C72AC 7F09277C 004E1021 */  addu  $v0, $v0, $t6
/* 0C72B0 7F092780 9442F804 */  lhu   $v0, %lo(D_8003F804)($v0)
/* 0C72B4 7F092784 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72B8 7F092788 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72BC 7F09278C 10400005 */  beqz  $v0, .L7F0927A4
/* 0C72C0 7F092790 00000000 */   nop   
/* 0C72C4 7F092794 0FC30776 */  jal   get_textptr_for_textID
/* 0C72C8 7F092798 00402025 */   move  $a0, $v0
/* 0C72CC 7F09279C 10000004 */  b     .L7F0927B0
/* 0C72D0 7F0927A0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0927A4:
/* 0C72D4 7F0927A4 0FC30776 */  jal   get_textptr_for_textID
/* 0C72D8 7F0927A8 3404B028 */   li    $a0, 45096
/* 0C72DC 7F0927AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0927B0:
/* 0C72E0 7F0927B0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C72E4 7F0927B4 03E00008 */  jr    $ra
/* 0C72E8 7F0927B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0927BC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*ugh hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default

.text
glabel sub_GAME_7F0927BC
/* 0C72EC 7F0927BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72F0 7F0927C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72F4 7F0927C4 0FC26C54 */  jal   get_cur_playernum
/* 0C72F8 7F0927C8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C72FC 7F0927CC 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0C7300 7F0927D0 3C0F8008 */  lui   $t7, %hi(off_CODE_bss_80079E30)
/* 0C7304 7F0927D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C7308 7F0927D8 01EE7821 */  addu  $t7, $t7, $t6
/* 0C730C 7F0927DC 91EF9E30 */  lbu   $t7, %lo(off_CODE_bss_80079E30)($t7)
/* 0C7310 7F0927E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C7314 7F0927E4 004F1007 */  srav  $v0, $t7, $v0
/* 0C7318 7F0927E8 30580001 */  andi  $t8, $v0, 1
/* 0C731C 7F0927EC 03E00008 */  jr    $ra
/* 0C7320 7F0927F0 03001025 */   move  $v0, $t8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0927F4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057504
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F0927F4
/* 0C7324 7F0927F4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C7328 7F0927F8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C732C 7F0927FC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C7330 7F092800 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C7334 7F092804 3C118003 */  lui   $s1, %hi(ptr_guard_data) # $s1, 0x8003
/* 0C7338 7F092808 00808025 */  move  $s0, $a0
/* 0C733C 7F09280C AFB20028 */  sw    $s2, 0x28($sp)
/* 0C7340 7F092810 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C7344 7F092814 0FC07D4C */  jal   get_numguards
/* 0C7348 7F092818 8E31CC64 */   lw    $s1, %lo(ptr_guard_data)($s1)
/* 0C734C 7F09281C 12000004 */  beqz  $s0, .L7F092830
/* 0C7350 7F092820 00409025 */   move  $s2, $v0
/* 0C7354 7F092824 3C018005 */  lui   $at, %hi(D_80057504) # $at, 0x8005
/* 0C7358 7F092828 10000004 */  b     .L7F09283C
/* 0C735C 7F09282C C4347504 */   lwc1  $f20, %lo(D_80057504)($at)
.L7F092830:
/* 0C7360 7F092830 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0C7364 7F092834 4481A000 */  mtc1  $at, $f20
/* 0C7368 7F092838 00000000 */  nop   
.L7F09283C:
/* 0C736C 7F09283C 1840000C */  blez  $v0, .L7F092870
/* 0C7370 7F092840 00008025 */   move  $s0, $zero
.L7F092844:
/* 0C7374 7F092844 8E24001C */  lw    $a0, 0x1c($s1)
/* 0C7378 7F092848 50800007 */  beql  $a0, $zero, .L7F092868
/* 0C737C 7F09284C 26100001 */   addiu $s0, $s0, 1
/* 0C7380 7F092850 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C7384 7F092854 46142182 */  mul.s $f6, $f4, $f20
/* 0C7388 7F092858 44053000 */  mfc1  $a1, $f6
/* 0C738C 7F09285C 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7390 7F092860 00000000 */   nop   
/* 0C7394 7F092864 26100001 */  addiu $s0, $s0, 1
.L7F092868:
/* 0C7398 7F092868 1612FFF6 */  bne   $s0, $s2, .L7F092844
/* 0C739C 7F09286C 263101DC */   addiu $s1, $s1, 0x1dc
.L7F092870:
/* 0C73A0 7F092870 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C73A4 7F092874 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0C73A8 7F092878 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C73AC 7F09287C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0C73B0 7F092880 8FB20028 */  lw    $s2, 0x28($sp)
/* 0C73B4 7F092884 03E00008 */  jr    $ra
/* 0C73B8 7F092888 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



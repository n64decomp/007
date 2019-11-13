#include "ultra64.h"
#include "game/ob.h"
#include "assets/obseg/obseg.h"

//bss
//800888b0
u8 ptr_resource_data[0x13];
//800888c4
u32 ptr_res_data_next;
//800888c8
u8 dword_CODE_bss_800888c8[0x10];
u8 dword_CODE_bss_800888D8[0x3958];

// data
//D:80046050
s32 D_80046050 = 0;

struct fileentry file_resource_table[] = {
    {0, "", 0},
    {1, "bg/bg_sev_all_p.seg", &bg_sev_all_p_seg},
    {2, "bg/bg_silo_all_p.seg", &bg_silo_all_p_seg},
    {3, "bg/bg_stat_all_p.seg", &bg_stat_all_p_seg},
    {4, "bg/bg_arec_all_p.seg", &bg_arec_all_p_seg},
    {5, "bg/bg_arch_all_p.seg", &bg_arch_all_p_seg},
    {6, "bg/bg_tra_all_p.seg", &bg_tra_all_p_seg},
    {7, "bg/bg_dest_all_p.seg", &bg_dest_all_p_seg},
    {8, "bg/bg_sevb_all_p.seg", &bg_sevb_all_p_seg},
    {9, "bg/bg_azt_all_p.seg", &bg_azt_all_p_seg},
    {0xA, "bg/bg_pete_all_p.seg", &bg_pete_all_p_seg},
    {0xB, "bg/bg_depo_all_p.seg", &bg_depo_all_p_seg},
    {0xC, "bg/bg_ref_all_p.seg", &bg_ref_all_p_seg},
    {0xD, "bg/bg_cryp_all_p.seg", &bg_cryp_all_p_seg},
    {0xE, "bg/bg_dam_all_p.seg", &bg_dam_all_p_seg},
    {0xF, "bg/bg_ark_all_p.seg", &bg_ark_all_p_seg},
    {0x10, "bg/bg_run_all_p.seg", &bg_run_all_p_seg},
    {0x11, "bg/bg_sevx_all_p.seg", &bg_sevx_all_p_seg},
    {0x12, "bg/bg_jun_all_p.seg", &bg_jun_all_p_seg},
    {0x13, "bg/bg_dish_all_p.seg", &bg_dish_all_p_seg},
    {0x14, "bg/bg_cave_all_p.seg", &bg_cave_all_p_seg},
    {0x15, "bg/bg_cat_all_p.seg", &bg_cat_all_p_seg},
    {0x16, "bg/bg_crad_all_p.seg", &bg_crad_all_p_seg},
    {0x17, "bg/bg_sho_all_p.seg", &bg_sho_all_p_seg},
    {0x18, "bg/bg_eld_all_p.seg", &bg_imp_all_p_seg},
    {0x19, "bg/bg_imp_all_p.seg", &bg_imp_all_p_seg},
    {0x1A, "bg/bg_ash_all_p.seg", &bg_imp_all_p_seg},
    {0x1B, "bg/bg_lue_all_p.seg", &bg_imp_all_p_seg},
    {0x1C, "bg/bg_ame_all_p.seg", &bg_imp_all_p_seg},
    {0x1D, "bg/bg_rit_all_p.seg", &bg_rit_all_p_seg},
    {0x1E, "bg/bg_oat_all_p.seg", &bg_oat_all_p_seg},
    {0x1F, "bg/bg_ear_all_p.seg", &bg_ear_all_p_seg},
    {0x20, "bg/bg_lee_all_p.seg", &bg_lee_all_p_seg},
    {0x21, "bg/bg_lip_all_p.seg", &bg_lip_all_p_seg},
    {0x22, "bg/bg_len_all_p.seg", &bg_len_all_p_seg},
    {0x23, "bg/bg_wax_all_p.seg", &bg_wax_all_p_seg},
    {0x24, "bg/bg_pam_all_p.seg", &bg_pam_all_p_seg},
    {0x25, "CarmourguardZ", &CarmourguardZ},
    {0x26, "CbaronsamediZ", &CbaronsamediZ},
    {0x27, "CbluecamguardZ", &CbluecamguardZ},
    {0x28, "CbluemanZ", &CbluemanZ},
    {0x29, "CbluewomanZ", &CbluewomanZ},
    {0x2A, "CboilerbondZ", &CboilerbondZ},
    {0x2B, "CboilertrevZ", &CboilertrevZ},
    {0x2C, "CborisZ", &CborisZ},
    {0x2D, "CcamguardZ", &CcamguardZ},
    {0x2E, "CcardimanZ", &CcardimanZ},
    {0x2F, "CcheckmanZ", &CcheckmanZ},
    {0x30, "CcommguardZ", &CcommguardZ},
    {0x31, "CdjbondZ", &CdjbondZ},
    {0x32, "CfattechwomanZ", &CfattechwomanZ},
    {0x33, "Cgreatguard2Z", &Cgreatguard2Z},
    {0x34, "CgreatguardZ", &CgreatguardZ},
    {0x35, "CgreyguardZ", &CgreyguardZ},
    {0x36, "CgreymanZ", &CgreymanZ},
    {0x37, "CheadalanZ", &CheadalanZ},
    {0x38, "CheadbZ", &CheadbZ},
    {0x39, "CheadbalaclavaZ", &CheadbalaclavaZ},
    {0x3A, "CheadbikeZ", &CheadbikeZ},
    {0x3B, "CheadbrosnanZ", &CheadbrosnanZ},
    {0x3C, "CheadbrosnanboilerZ", &CheadbrosnanboilerZ},
    {0x3D, "CheadbrosnansnowZ", &CheadbrosnansnowZ},
    {0x3E, "CheadbrosnansuitZ", &CheadbrosnansuitZ},
    {0x3F, "CheadbrosnantimberZ", &CheadbrosnantimberZ},
    {0x40, "CheadchrisZ", &CheadchrisZ},
    {0x41, "CheaddaveZ", &CheaddaveZ},
    {0x42, "CheaddesZ", &CheaddesZ},
    {0x43, "CheadduncanZ", &CheadduncanZ},
    {0x44, "CheaddwayneZ", &CheaddwayneZ},
    {0x45, "CheadgrahamZ", &CheadgrahamZ},
    {0x46, "CheadgrantZ", &CheadgrantZ},
    {0x47, "CheadjimZ", &CheadjimZ},
    {0x48, "Cheadjoe2Z", &Cheadjoe2Z},
    {0x49, "CheadjoeZ", &CheadjoeZ},
    {0x4A, "CheadjoelZ", &CheadjoelZ},
    {0x4B, "CheadkarlZ", &CheadkarlZ},
    {0x4C, "CheadkenZ", &CheadkenZ},
    {0x4D, "CheadleeZ", &CheadleeZ},
    {0x4E, "CheadmandyZ", &CheadmandyZ},
    {0x4F, "CheadmarionZ", &CheadmarionZ},
    {0x50, "CheadmarkZ", &CheadmarkZ},
    {0x51, "CheadmartinZ", &CheadmartinZ},
    {0x52, "CheadmishkinZ", &CheadmishkinZ},
    {0x53, "CheadneilZ", &CheadneilZ},
    {0x54, "CheadpeteZ", &CheadpeteZ},
    {0x55, "CheadrobinZ", &CheadrobinZ},
    {0x56, "CheadsallyZ", &CheadsallyZ},
    {0x57, "CheadscottZ", &CheadscottZ},
    {0x58, "CheadshaunZ", &CheadshaunZ},
    {0x59, "CheadsteveeZ", &CheadsteveeZ},
    {0x5A, "CheadstevehZ", &CheadstevehZ},
    {0x5B, "CheadvivienZ", &CheadvivienZ},
    {0x5C, "CjawsZ", &CjawsZ},
    {0x5D, "CjeanwomanZ", &CjeanwomanZ},
    {0x5E, "CmaydayZ", &CmaydayZ},
    {0x5F, "CmoonfemaleZ", &CmoonfemaleZ},
    {0x60, "CmoonguardZ", &CmoonguardZ},
    {0x61, "CnatalyaZ", &CnatalyaZ},
    {0x62, "CnavyguardZ", &CnavyguardZ},
    {0x63, "CoddjobZ", &CoddjobZ},
    {0x64, "ColiveguardZ", &ColiveguardZ},
    {0x65, "CorumovZ", &CorumovZ},
    {0x66, "CpilotZ", &CpilotZ},
    {0x67, "CredmanZ", &CredmanZ},
    {0x68, "CrusguardZ", &CrusguardZ},
    {0x69, "CsnowbondZ", &CsnowbondZ},
    {0x6A, "CsnowguardZ", &CsnowguardZ},
    {0x6B, "CspicebondZ", &CspicebondZ},
    {0x6C, "Csuit_lf_handZ", &Csuit_lf_handZ},
    {0x6D, "CsuitbondZ", &CsuitbondZ},
    {0x6E, "CtechmanZ", &CtechmanZ},
    {0x6F, "CtechwomanZ", &CtechwomanZ},
    {0x70, "CtimberbondZ", &CtimberbondZ},
    {0x71, "CtrevelyanZ", &CtrevelyanZ},
    {0x72, "CtrevguardZ", &CtrevguardZ},
    {0x73, "CvalentinZ", &CvalentinZ},
    {0x74, "CxeniaZ", &CxeniaZ},
    {0x75, "Gak47Z", &Gak47Z},
    {0x76, "GaudiotapeZ", &GaudiotapeZ},
    {0x77, "GautoshotZ", &GautoshotZ},
    {0x78, "GblackboxZ", &GblackboxZ},
    {0x79, "GblueprintsZ", &GblueprintsZ},
    {0x7A, "GbombcaseZ", &GbombcaseZ},
    {0x7B, "GbombdefuserZ", &GbombdefuserZ},
    {0x7C, "GbriefcaseZ", &GbriefcaseZ},
    {0x7D, "GbugZ", &GbugZ},
    {0x7E, "GbugdetectorZ", &GbugdetectorZ},
    {0x7F, "GbungeeZ", &GbungeeZ},
    {0x80, "GcameraZ", &GcameraZ},
    {0x81, "GcartblueZ", &GcartblueZ},
    {0x82, "GcartridgeZ", &GcartridgeZ},
    {0x83, "GcartrifleZ", &GcartrifleZ},
    {0x84, "GcartshellZ", &GcartshellZ},
    {0x85, "GcircuitboardZ", &GcircuitboardZ},
    {0x86, "GclipboardZ", &GclipboardZ},
    {0x87, "GcreditcardZ", &GcreditcardZ},
    {0x88, "GdarkglassesZ", &GdarkglassesZ},
    {0x89, "GdatathiefZ", &GdatathiefZ},
    {0x8A, "GdattapeZ", &GdattapeZ},
    {0x8B, "GdoordecoderZ", &GdoordecoderZ},
    {0x8C, "GdoorexploderZ", &GdoorexploderZ},
    {0x8D, "GdossierredZ", &GdossierredZ},
    {0x8E, "GdynamiteZ", &GdynamiteZ},
    {0x8F, "GexplosivefloppyZ", &GexplosivefloppyZ},
    {0x90, "GexplosivepenZ", &GexplosivepenZ},
    {0x91, "GextinguisherZ", &GextinguisherZ},
    {0x92, "GfingergunZ", &GfingergunZ},
    {0x93, "GfistZ", &GfistZ},
    {0x94, "GflarepistolZ", &GflarepistolZ},
    {0x95, "Gfnp90Z", &Gfnp90Z},
    {0x96, "GgaskeyringZ", &GgaskeyringZ},
    {0x97, "GgoldbarZ", &GgoldbarZ},
    {0x98, "GgoldeneyekeyZ", &GgoldeneyekeyZ},
    {0x99, "GgoldengunZ", &GgoldengunZ},
    {0x9A, "GgoldwppkZ", &GgoldwppkZ},
    {0x9B, "GgrenadeZ", &GgrenadeZ},
    {0x9C, "GgrenadelaunchZ", &GgrenadelaunchZ},
    {0x9D, "GheroinZ", &GheroinZ},
    {0x9E, "GjoypadZ", &GjoypadZ},
    {0x9F, "GkeyanalysercaseZ", &GkeyanalysercaseZ},
    {0xA0, "GkeyboltZ", &GkeyboltZ},
    {0xA1, "GkeycardZ", &GkeycardZ},
    {0xA2, "GkeyyaleZ", &GkeyyaleZ},
    {0xA3, "GknifeZ", &GknifeZ},
    {0xA4, "GlaserZ", &GlaserZ},
    {0xA5, "GlectreZ", &GlectreZ},
    {0xA6, "GlockexploderZ", &GlockexploderZ},
    {0xA7, "Gm16Z", &Gm16Z},
    {0xA8, "GmapZ", &GmapZ},
    {0xA9, "GmicrocameraZ", &GmicrocameraZ},
    {0xAA, "GmicrocodeZ", &GmicrocodeZ},
    {0xAB, "GmicrofilmZ", &GmicrofilmZ},
    {0xAC, "GmoneyZ", &GmoneyZ},
    {0xAD, "Gmp5kZ", &Gmp5kZ},
    {0xAE, "Gmp5ksilZ", &Gmp5ksilZ},
    {0xAF, "GpitongunZ", &GpitongunZ},
    {0xB0, "GplansZ", &GplansZ},
    {0xB1, "GplastiqueZ", &GplastiqueZ},
    {0xB2, "GpolarizedglassesZ", &GpolarizedglassesZ},
    {0xB3, "GproximitymineZ", &GproximitymineZ},
    {0xB4, "GremotemineZ", &GremotemineZ},
    {0xB5, "GrocketlaunchZ", &GrocketlaunchZ},
    {0xB6, "GrugerZ", &GrugerZ},
    {0xB7, "GsafecrackercaseZ", &GsafecrackercaseZ},
    {0xB8, "GshotgunZ", &GshotgunZ},
    {0xB9, "GsilverwppkZ", &GsilverwppkZ},
    {0xBA, "GskorpionZ", &GskorpionZ},
    {0xBB, "GsniperrifleZ", &GsniperrifleZ},
    {0xBC, "GspectreZ", &GspectreZ},
    {0xBD, "GspooltapeZ", &GspooltapeZ},
    {0xBE, "GspyfileZ", &GspyfileZ},
    {0xBF, "GstafflistZ", &GstafflistZ},
    {0xC0, "GtaserZ", &GtaserZ},
    {0xC1, "GthrowknifeZ", &GthrowknifeZ},
    {0xC2, "GtimedmineZ", &GtimedmineZ},
    {0xC3, "GtriggerZ", &GtriggerZ},
    {0xC4, "Gtt33Z", &Gtt33Z},
    {0xC5, "GuziZ", &GuziZ},
    {0xC6, "GvideotapeZ", &GvideotapeZ},
    {0xC7, "GwatchcommunicatorZ", &GwatchcommunicatorZ},
    {0xC8, "GwatchgeigercounterZ", &GwatchgeigercounterZ},
    {0xC9, "GwatchidentifierZ", &GwatchidentifierZ},
    {0xCA, "GwatchlaserZ", &GwatchlaserZ},
    {0xCB, "GwatchmagnetattractZ", &GwatchmagnetattractZ},
    {0xCC, "GwatchmagnetrepelZ", &GwatchmagnetrepelZ},
    {0xCD, "GweaponcaseZ", &GweaponcaseZ},
    {0xCE, "GwppkZ", &GwppkZ},
    {0xCF, "GwppksilZ", &GwppksilZ},
    {0xD0, "GwristdartZ", &GwristdartZ},
    {0xD1, "PICBMZ", &PICBMZ},
    {0xD2, "PICBM_noseZ", &PICBM_noseZ},
    {0xD3, "Pak47magZ", &Pak47magZ},
    {0xD4, "Palarm1Z", &Palarm1Z},
    {0xD5, "Palarm2Z", &Palarm2Z},
    {0xD6, "Pammo_crate1Z", &Pammo_crate1Z},
    {0xD7, "Pammo_crate2Z", &Pammo_crate2Z},
    {0xD8, "Pammo_crate3Z", &Pammo_crate3Z},
    {0xD9, "Pammo_crate4Z", &Pammo_crate4Z},
    {0xDA, "Pammo_crate5Z", &Pammo_crate5Z},
    {0xDB, "PapcZ", &PapcZ},
    {0xDC, "Parchsecdoor1Z", &Parchsecdoor1Z},
    {0xDD, "Parchsecdoor2Z", &Parchsecdoor2Z},
    {0xDE, "ParticZ", &ParticZ},
    {0xDF, "PartictrailerZ", &PartictrailerZ},
    {0xE0, "PbarricadeZ", &PbarricadeZ},
    {0xE1, "Pbin1Z", &Pbin1Z},
    {0xE2, "Pblotter1Z", &Pblotter1Z},
    {0xE3, "PbodyarmourZ", &PbodyarmourZ},
    {0xE4, "PbodyarmourvestZ", &PbodyarmourvestZ},
    {0xE5, "PbollardZ", &PbollardZ},
    {0xE6, "PbombZ", &PbombZ},
    {0xE7, "Pbook1Z", &Pbook1Z},
    {0xE8, "Pbookshelf1Z", &Pbookshelf1Z},
    {0xE9, "Pborg_crateZ", &Pborg_crateZ},
    {0xEA, "PboxcartridgesZ", &PboxcartridgesZ},
    {0xEB, "Pboxes2x4Z", &Pboxes2x4Z},
    {0xEC, "Pboxes3x4Z", &Pboxes3x4Z},
    {0xED, "Pboxes4x4Z", &Pboxes4x4Z},
    {0xEE, "PbrakeunitZ", &PbrakeunitZ},
    {0xEF, "Pbridge_console1aZ", &Pbridge_console1aZ},
    {0xF0, "Pbridge_console1bZ", &Pbridge_console1bZ},
    {0xF1, "Pbridge_console2aZ", &Pbridge_console2aZ},
    {0xF2, "Pbridge_console2bZ", &Pbridge_console2bZ},
    {0xF3, "Pbridge_console3aZ", &Pbridge_console3aZ},
    {0xF4, "Pbridge_console3bZ", &Pbridge_console3bZ},
    {0xF5, "PcarbmwZ", &PcarbmwZ},
    {0xF6, "Pcard_box1Z", &Pcard_box1Z},
    {0xF7, "Pcard_box2Z", &Pcard_box2Z},
    {0xF8, "Pcard_box3Z", &Pcard_box3Z},
    {0xF9, "Pcard_box4_lgZ", &Pcard_box4Z},
    {0xFA, "Pcard_box5_lgZ", &Pcard_box5Z},
    {0xFB, "Pcard_box6_lgZ", &Pcard_box6Z},
    {0xFC, "PcarescortZ", &PcarescortZ},
    {0xFD, "PcargolfZ", &PcargolfZ},
    {0xFE, "PcarweirdZ", &PcarweirdZ},
    {0xFF, "PcarzilZ", &PcarzilZ},
    {0x100, "PcctvZ", &PcctvZ},
    {0x101, "PchraudiotapeZ", &PchraudiotapeZ},
    {0x102, "PchrautoshotZ", &PchrautoshotZ},
    {0x103, "PchrblackboxZ", &PchrblackboxZ},
    {0x104, "PchrblueprintsZ", &PchrblueprintsZ},
    {0x105, "PchrbombcaseZ", &PchrbombcaseZ},
    {0x106, "PchrbombdefuserZ", &PchrbombdefuserZ},
    {0x107, "PchrbriefcaseZ", &PchrbriefcaseZ},
    {0x108, "PchrbugZ", &PchrbugZ},
    {0x109, "PchrbugdetectorZ", &PchrbugdetectorZ},
    {0x10A, "PchrbungeeZ", &PchrbungeeZ},
    {0x10B, "PchrcameraZ", &PchrcameraZ},
    {0x10C, "PchrcircuitboardZ", &PchrcircuitboardZ},
    {0x10D, "PchrclipboardZ", &PchrclipboardZ},
    {0x10E, "PchrcreditcardZ", &PchrcreditcardZ},
    {0x10F, "PchrdarkglassesZ", &PchrdarkglassesZ},
    {0x110, "PchrdatathiefZ", &PchrdatathiefZ},
    {0x111, "PchrdattapeZ", &PchrdattapeZ},
    {0x112, "PchrdoordecoderZ", &PchrdoordecoderZ},
    {0x113, "PchrdoorexploderZ", &PchrdoorexploderZ},
    {0x114, "PchrdossierredZ", &PchrdossierredZ},
    {0x115, "PchrdynamiteZ", &PchrdynamiteZ},
    {0x116, "PchrexplosivepenZ", &PchrexplosivepenZ},
    {0x117, "PchrextinguisherZ", &PchrextinguisherZ},
    {0x118, "PchrfingergunZ", &PchrfingergunZ},
    {0x119, "PchrflarepistolZ", &PchrflarepistolZ},
    {0x11A, "Pchrfnp90Z", &Pchrfnp90Z},
    {0x11B, "PchrgaskeyringZ", &PchrgaskeyringZ},
    {0x11C, "PchrgoldbarZ", &PchrgoldbarZ},
    {0x11D, "PchrgoldenZ", &PchrgoldenZ},
    {0x11E, "PchrgoldeneyekeyZ", &PchrgoldeneyekeyZ},
    {0x11F, "PchrgoldwppkZ", &PchrgoldwppkZ},
    {0x120, "PchrgrenadeZ", &PchrgrenadeZ},
    {0x121, "PchrgrenadelaunchZ", &PchrgrenadelaunchZ},
    {0x122, "PchrgrenaderoundZ", &PchrgrenaderoundZ},
    {0x123, "PchrheroinZ", &PchrheroinZ},
    {0x124, "PchrkalashZ", &PchrkalashZ},
    {0x125, "PchrkeyanalysercaseZ", &PchrkeyanalysercaseZ},
    {0x126, "PchrkeyboltZ", &PchrkeyboltZ},
    {0x127, "PchrkeyyaleZ", &PchrkeyyaleZ},
    {0x128, "PchrknifeZ", &PchrknifeZ},
    {0x129, "PchrlaserZ", &PchrlaserZ},
    {0x12A, "PchrlectreZ", &PchrlectreZ},
    {0x12B, "PchrlockexploderZ", &PchrlockexploderZ},
    {0x12C, "Pchrm16Z", &Pchrm16Z},
    {0x12D, "PchrmapZ", &PchrmapZ},
    {0x12E, "PchrmicrocameraZ", &PchrmicrocameraZ},
    {0x12F, "PchrmicrocodeZ", &PchrmicrocodeZ},
    {0x130, "PchrmicrofilmZ", &PchrmicrofilmZ},
    {0x131, "PchrmoneyZ", &PchrmoneyZ},
    {0x132, "Pchrmp5kZ", &Pchrmp5kZ},
    {0x133, "Pchrmp5ksilZ", &Pchrmp5ksilZ},
    {0x134, "PchrpitongunZ", &PchrpitongunZ},
    {0x135, "PchrplansZ", &PchrplansZ},
    {0x136, "PchrplastiqueZ", &PchrplastiqueZ},
    {0x137, "PchrpolarizedglassesZ", &PchrpolarizedglassesZ},
    {0x138, "PchrproximitymineZ", &PchrproximitymineZ},
    {0x139, "PchrremotemineZ", &PchrremotemineZ},
    {0x13A, "PchrrocketZ", &PchrrocketZ},
    {0x13B, "PchrrocketlaunchZ", &PchrrocketlaunchZ},
    {0x13C, "PchrrugerZ", &PchrrugerZ},
    {0x13D, "PchrsafecrackercaseZ", &PchrsafecrackercaseZ},
    {0x13E, "PchrshotgunZ", &PchrshotgunZ},
    {0x13F, "PchrsilverwppkZ", &PchrsilverwppkZ},
    {0x140, "PchrskorpionZ", &PchrskorpionZ},
    {0x141, "PchrsniperrifleZ", &PchrsniperrifleZ},
    {0x142, "PchrspectreZ", &PchrspectreZ},
    {0x143, "PchrspooltapeZ", &PchrspooltapeZ},
    {0x144, "PchrspyfileZ", &PchrspyfileZ},
    {0x145, "PchrstafflistZ", &PchrstafflistZ},
    {0x146, "PchrtesttubeZ", &PchrtesttubeZ},
    {0x147, "PchrthrowknifeZ", &PchrthrowknifeZ},
    {0x148, "PchrtimedmineZ", &PchrtimedmineZ},
    {0x149, "Pchrtt33Z", &Pchrtt33Z},
    {0x14A, "PchruziZ", &PchruziZ},
    {0x14B, "PchrvideotapeZ", &PchrvideotapeZ},
    {0x14C, "PchrweaponcaseZ", &PchrweaponcaseZ},
    {0x14D, "PchrwppkZ", &PchrwppkZ},
    {0x14E, "PchrwppksilZ", &PchrwppksilZ},
    {0x14F, "PchrwristdartZ", &PchrwristdartZ},
    {0x150, "Pconsole1Z", &Pconsole1Z},
    {0x151, "Pconsole2Z", &Pconsole2Z},
    {0x152, "Pconsole3Z", &Pconsole3Z},
    {0x153, "Pconsole_sev2aZ", &Pconsole_sev2aZ},
    {0x154, "Pconsole_sev2bZ", &Pconsole_sev2bZ},
    {0x155, "Pconsole_sev2cZ", &Pconsole_sev2cZ},
    {0x156, "Pconsole_sev2dZ", &Pconsole_sev2dZ},
    {0x157, "Pconsole_sev_GEaZ", &Pconsole_sev_GEaZ},
    {0x158, "Pconsole_sev_GEbZ", &Pconsole_sev_GEbZ},
    {0x159, "Pconsole_sevaZ", &Pconsole_sevaZ},
    {0x15A, "Pconsole_sevbZ", &Pconsole_sevbZ},
    {0x15B, "Pconsole_sevcZ", &Pconsole_sevcZ},
    {0x15C, "Pconsole_sevdZ", &Pconsole_sevdZ},
    {0x15D, "Pcryptdoor1aZ", &Pcryptdoor1aZ},
    {0x15E, "Pcryptdoor1bZ", &Pcryptdoor1bZ},
    {0x15F, "Pcryptdoor2aZ", &Pcryptdoor2aZ},
    {0x160, "Pcryptdoor2bZ", &Pcryptdoor2bZ},
    {0x161, "Pcryptdoor3Z", &Pcryptdoor3Z},
    {0x162, "Pcryptdoor4Z", &Pcryptdoor4Z},
    {0x163, "PdamchaindoorZ", &PdamchaindoorZ},
    {0x164, "PdamgatedoorZ", &PdamgatedoorZ},
    {0x165, "PdamtundoorZ", &PdamtundoorZ},
    {0x166, "Pdepot_door_steelZ", &Pdepot_door_steelZ},
    {0x167, "Pdepot_gate_entryZ", &Pdepot_gate_entryZ},
    {0x168, "Pdesk1Z", &Pdesk1Z},
    {0x169, "Pdesk2Z", &Pdesk2Z},
    {0x16A, "Pdesk_arecibo1Z", &Pdesk_arecibo1Z},
    {0x16B, "Pdesk_lamp2Z", &Pdesk_lamp2Z},
    {0x16C, "Pdest_engineZ", &Pdest_engineZ},
    {0x16D, "Pdest_exocetZ", &Pdest_exocetZ},
    {0x16E, "Pdest_gunZ", &Pdest_gunZ},
    {0x16F, "Pdest_harpoonZ", &Pdest_harpoonZ},
    {0x170, "Pdest_seawolfZ", &Pdest_seawolfZ},
    {0x171, "Pdisc_readerZ", &Pdisc_readerZ},
    {0x172, "Pdisk_drive1Z", &Pdisk_drive1Z},
    {0x173, "Pdoor_azt_chairZ", &Pdoor_azt_chairZ},
    {0x174, "Pdoor_azt_deskZ", &Pdoor_azt_deskZ},
    {0x175, "Pdoor_azt_desk_topZ", &Pdoor_azt_desk_topZ},
    {0x176, "Pdoor_aztecZ", &Pdoor_aztecZ},
    {0x177, "Pdoor_dest1Z", &Pdoor_dest1Z},
    {0x178, "Pdoor_dest2Z", &Pdoor_dest2Z},
    {0x179, "Pdoor_eyelidZ", &Pdoor_eyelidZ},
    {0x17A, "Pdoor_irisZ", &Pdoor_irisZ},
    {0x17B, "Pdoor_mfZ", &Pdoor_mfZ},
    {0x17C, "Pdoor_roller1Z", &Pdoor_roller1Z},
    {0x17D, "Pdoor_roller2Z", &Pdoor_roller2Z},
    {0x17E, "Pdoor_roller3Z", &Pdoor_roller3Z},
    {0x17F, "Pdoor_roller4Z", &Pdoor_roller4Z},
    {0x180, "Pdoor_rollertrainZ", &Pdoor_rollertrainZ},
    {0x181, "Pdoor_st_arec1Z", &Pdoor_st_arec1Z},
    {0x182, "Pdoor_st_arec2Z", &Pdoor_st_arec2Z},
    {0x183, "Pdoor_winZ", &Pdoor_winZ},
    {0x184, "PdoorconsoleZ", &PdoorconsoleZ},
    {0x185, "PdoorpanelZ", &PdoorpanelZ},
    {0x186, "Pdoorprison1Z", &Pdoorprison1Z},
    {0x187, "PdoorstatgateZ", &PdoorstatgateZ},
    {0x188, "PexplosionbitZ", &PexplosionbitZ},
    {0x189, "Pfiling_cabinet1Z", &Pfiling_cabinet1Z},
    {0x18A, "PflagZ", &PflagZ},
    {0x18B, "PfloppyZ", &PfloppyZ},
    {0x18C, "Pfnp90magZ", &Pfnp90magZ},
    {0x18D, "Pgas_plant_met1_do1Z", &Pgas_plant_met1_do1Z},
    {0x18E, "Pgas_plant_sw2_do1Z", &Pgas_plant_sw2_do1Z},
    {0x18F, "Pgas_plant_sw3_do1Z", &Pgas_plant_sw3_do1Z},
    {0x190, "Pgas_plant_sw4_do1Z", &Pgas_plant_sw4_do1Z},
    {0x191, "Pgas_plant_sw_do1Z", &Pgas_plant_sw_do1Z},
    {0x192, "Pgas_plant_wc_cub1Z", &Pgas_plant_wc_cub1Z},
    {0x193, "PgasbarrelZ", &PgasbarrelZ},
    {0x194, "PgasbarrelsZ", &PgasbarrelsZ},
    {0x195, "Pgasplant_clear_doorZ", &Pgasplant_clear_doorZ},
    {0x196, "PgastankZ", &PgastankZ},
    {0x197, "Pglassware1Z", &Pglassware1Z},
    {0x198, "Pglassware2Z", &Pglassware2Z},
    {0x199, "Pglassware3Z", &Pglassware3Z},
    {0x19A, "Pglassware4Z", &Pglassware4Z},
    {0x19B, "PgoldeneyelogoZ", &PgoldeneyelogoZ},
    {0x19C, "PgoldenshellsZ", &PgoldenshellsZ},
    {0x19D, "PgroundgunZ", &PgroundgunZ},
    {0x19E, "Pgun_runway1Z", &Pgun_runway1Z},
    {0x19F, "PhatberetZ", &PhatberetZ},
    {0x1A0, "PhatberetblueZ", &PhatberetblueZ},
    {0x1A1, "PhatberetredZ", &PhatberetredZ},
    {0x1A2, "PhatchboltZ", &PhatchboltZ},
    {0x1A3, "PhatchdoorZ", &PhatchdoorZ},
    {0x1A4, "PhatchsevxZ", &PhatchsevxZ},
    {0x1A5, "PhatfurryZ", &PhatfurryZ},
    {0x1A6, "PhatfurryblackZ", &PhatfurryblackZ},
    {0x1A7, "PhatfurrybrownZ", &PhatfurrybrownZ},
    {0x1A8, "PhathelmetZ", &PhathelmetZ},
    {0x1A9, "PhathelmetgreyZ", &PhathelmetgreyZ},
    {0x1AA, "PhatmoonZ", &PhatmoonZ},
    {0x1AB, "PhatpeakedZ", &PhatpeakedZ},
    {0x1AC, "PhattbirdZ", &PhattbirdZ},
    {0x1AD, "PhattbirdbrownZ", &PhattbirdbrownZ},
    {0x1AE, "PhelicopterZ", &PhelicopterZ},
    {0x1AF, "PhindZ", &PhindZ},
    {0x1B0, "PjeepZ", &PjeepZ},
    {0x1B1, "Pjerry_can1Z", &Pjerry_can1Z},
    {0x1B2, "Pjungle3_treeZ", &Pjungle3_treeZ},
    {0x1B3, "Pjungle5_treeZ", &Pjungle5_treeZ},
    {0x1B4, "Pkey_holderZ", &Pkey_holderZ},
    {0x1B5, "Pkeyboard1Z", &Pkeyboard1Z},
    {0x1B6, "Pkit_units1Z", &Pkit_units1Z},
    {0x1B7, "PlabbenchZ", &PlabbenchZ},
    {0x1B8, "PlandmineZ", &PlandmineZ},
    {0x1B9, "PlegalpageZ", &PlegalpageZ},
    {0x1BA, "Pletter_tray1Z", &Pletter_tray1Z},
    {0x1BB, "Plocker3Z", &Plocker3Z},
    {0x1BC, "Plocker4Z", &Plocker4Z},
    {0x1BD, "Pm16magZ", &Pm16magZ},
    {0x1BE, "PmagnumshellsZ", &PmagnumshellsZ},
    {0x1BF, "Pmainframe1Z", &Pmainframe1Z},
    {0x1C0, "Pmainframe2Z", &Pmainframe2Z},
    {0x1C1, "Pmetal_chair1Z", &Pmetal_chair1Z},
    {0x1C2, "Pmetal_crate1Z", &Pmetal_crate1Z},
    {0x1C3, "Pmetal_crate2Z", &Pmetal_crate2Z},
    {0x1C4, "Pmetal_crate3Z", &Pmetal_crate3Z},
    {0x1C5, "Pmetal_crate4Z", &Pmetal_crate4Z},
    {0x1C6, "PmilcopterZ", &PmilcopterZ},
    {0x1C7, "PmiltruckZ", &PmiltruckZ},
    {0x1C8, "Pmissile_rack2Z", &Pmissile_rack2Z},
    {0x1C9, "Pmissile_rackZ", &Pmissile_rackZ},
    {0x1CA, "PmodemboxZ", &PmodemboxZ},
    {0x1CB, "PmotorbikeZ", &PmotorbikeZ},
    {0x1CC, "Pmp5kmagZ", &Pmp5kmagZ},
    {0x1CD, "PnintendologoZ", &PnintendologoZ},
    {0x1CE, "Poil_drum1Z", &Poil_drum1Z},
    {0x1CF, "Poil_drum2Z", &Poil_drum2Z},
    {0x1D0, "Poil_drum3Z", &Poil_drum3Z},
    {0x1D1, "Poil_drum5Z", &Poil_drum5Z},
    {0x1D2, "Poil_drum6Z", &Poil_drum6Z},
    {0x1D3, "Poil_drum7Z", &Poil_drum7Z},
    {0x1D4, "PpadlockZ", &PpadlockZ},
    {0x1D5, "PpalmZ", &PpalmZ},
    {0x1D6, "PpalmtreeZ", &PpalmtreeZ},
    {0x1D7, "Pphone1Z", &Pphone1Z},
    {0x1D8, "PplaneZ", &PplaneZ},
    {0x1D9, "Pplant11Z", &Pplant11Z},
    {0x1DA, "Pplant1Z", &Pplant1Z},
    {0x1DB, "Pplant2Z", &Pplant2Z},
    {0x1DC, "Pplant2bZ", &Pplant2bZ},
    {0x1DD, "Pplant3Z", &Pplant3Z},
    {0x1DE, "Pradio_unit1Z", &Pradio_unit1Z},
    {0x1DF, "Pradio_unit2Z", &Pradio_unit2Z},
    {0x1E0, "Pradio_unit3Z", &Pradio_unit3Z},
    {0x1E1, "Pradio_unit4Z", &Pradio_unit4Z},
    {0x1E2, "ProofgunZ", &ProofgunZ},
    {0x1E3, "PsafeZ", &PsafeZ},
    {0x1E4, "PsafedoorZ", &PsafedoorZ},
    {0x1E5, "Psat1_reflectZ", &Psat1_reflectZ},
    {0x1E6, "PsatboxZ", &PsatboxZ},
    {0x1E7, "PsatdishZ", &PsatdishZ},
    {0x1E8, "Psec_panelZ", &Psec_panelZ},
    {0x1E9, "Psev_door3Z", &Psev_door3Z},
    {0x1EA, "Psev_door3_windZ", &Psev_door3_windZ},
    {0x1EB, "Psev_door4_windZ", &Psev_door4_windZ},
    {0x1EC, "Psev_doorZ", &Psev_doorZ},
    {0x1ED, "Psev_door_v1Z", &Psev_door_v1Z},
    {0x1EE, "Psev_trislideZ", &Psev_trislideZ},
    {0x1EF, "PsevdishZ", &PsevdishZ},
    {0x1F0, "PsevdoormetslideZ", &PsevdoormetslideZ},
    {0x1F1, "PsevdoornowindZ", &PsevdoornowindZ},
    {0x1F2, "PsevdoorwindZ", &PsevdoorwindZ},
    {0x1F3, "PsevdoorwoodZ", &PsevdoorwoodZ},
    {0x1F4, "PshuttleZ", &PshuttleZ},
    {0x1F5, "Pshuttle_door_lZ", &Pshuttle_door_lZ},
    {0x1F6, "Pshuttle_door_rZ", &Pshuttle_door_rZ},
    {0x1F7, "PsilencerZ", &PsilencerZ},
    {0x1F8, "Psilo_lift_doorZ", &Psilo_lift_doorZ},
    {0x1F9, "PsilotopdoorZ", &PsilotopdoorZ},
    {0x1FA, "PskorpionmagZ", &PskorpionmagZ},
    {0x1FB, "PspectremagZ", &PspectremagZ},
    {0x1FC, "PspeedboatZ", &PspeedboatZ},
    {0x1FD, "Pst_pete_room_1iZ", &Pst_pete_room_1iZ},
    {0x1FE, "Pst_pete_room_2iZ", &Pst_pete_room_2iZ},
    {0x1FF, "Pst_pete_room_3tZ", &Pst_pete_room_3tZ},
    {0x200, "Pst_pete_room_5cZ", &Pst_pete_room_5cZ},
    {0x201, "Pst_pete_room_6cZ", &Pst_pete_room_6cZ},
    {0x202, "Psteel_door1Z", &Psteel_door1Z},
    {0x203, "Psteel_door2Z", &Psteel_door2Z},
    {0x204, "Psteel_door2bZ", &Psteel_door2bZ},
    {0x205, "Psteel_door3Z", &Psteel_door3Z},
    {0x206, "Pstool1Z", &Pstool1Z},
    {0x207, "Pswipe_card2Z", &Pswipe_card2Z},
    {0x208, "Pswivel_chair1Z", &Pswivel_chair1Z},
    {0x209, "PtankZ", &PtankZ},
    {0x20A, "PtigerZ", &PtigerZ},
    {0x20B, "Ptorpedo_rackZ", &Ptorpedo_rackZ},
    {0x20C, "Ptrain_door2Z", &Ptrain_door2Z},
    {0x20D, "Ptrain_door3Z", &Ptrain_door3Z},
    {0x20E, "Ptrain_doorZ", &Ptrain_doorZ},
    {0x20F, "PtrainextdoorZ", &PtrainextdoorZ},
    {0x210, "Ptt33magZ", &Ptt33magZ},
    {0x211, "Ptuning_console1Z", &Ptuning_console1Z},
    {0x212, "Ptv1Z", &Ptv1Z},
    {0x213, "Ptv4screenZ", &Ptv4screenZ},
    {0x214, "Ptv_holderZ", &Ptv_holderZ},
    {0x215, "PtvscreenZ", &PtvscreenZ},
    {0x216, "PuzimagZ", &PuzimagZ},
    {0x217, "PvertdoorZ", &PvertdoorZ},
    {0x218, "PwalletbondZ", &PwalletbondZ},
    {0x219, "PwindowZ", &PwindowZ},
    {0x21A, "Pwindow_cor11Z", &Pwindow_cor11Z},
    {0x21B, "Pwindow_lib_lg1Z", &Pwindow_lib_lg1Z},
    {0x21C, "Pwindow_lib_sm1Z", &Pwindow_lib_sm1Z},
    {0x21D, "Pwood_lg_crate1Z", &Pwood_lg_crate1Z},
    {0x21E, "Pwood_lg_crate2Z", &Pwood_lg_crate2Z},
    {0x21F, "Pwood_md_crate3Z", &Pwood_md_crate3Z},
    {0x220, "Pwood_sm_crate4Z", &Pwood_sm_crate4Z},
    {0x221, "Pwood_sm_crate5Z", &Pwood_sm_crate5Z},
    {0x222, "Pwood_sm_crate6Z", &Pwood_sm_crate6Z},
    {0x223, "Pwooden_table1Z", &Pwooden_table1Z},
    {0x224, "PwppkmagZ", &PwppkmagZ},

    {0x225, "Tbg_ame_all_p_stanZ", &Tbg_ame_all_p_stanZ},
    {0x226, "Tbg_arch_all_p_stanZ", &Tbg_arch_all_p_stanZ},
    {0x227, "Tbg_arec_all_p_stanZ", &Tbg_arec_all_p_stanZ},
    {0x228, "Tbg_ark_all_p_stanZ", &Tbg_ark_all_p_stanZ},
    {0x229, "Tbg_ash_all_p_stanZ", &Tbg_ash_all_p_stanZ},
    {0x22A, "Tbg_azt_all_p_stanZ", &Tbg_azt_all_p_stanZ},
    {0x22B, "Tbg_cat_all_p_stanZ", &Tbg_cat_all_p_stanZ},
    {0x22C, "Tbg_cave_all_p_stanZ", &Tbg_cave_all_p_stanZ},
    {0x22D, "Tbg_crad_all_p_stanZ", &Tbg_crad_all_p_stanZ},
    {0x22E, "Tbg_cryp_all_p_stanZ", &Tbg_cryp_all_p_stanZ},
    {0x22F, "Tbg_dam_all_p_stanZ", &Tbg_dam_all_p_stanZ},
    {0x230, "Tbg_depo_all_p_stanZ", &Tbg_depo_all_p_stanZ},
    {0x231, "Tbg_dest_all_p_stanZ", &Tbg_dest_all_p_stanZ},
    {0x232, "Tbg_dish_all_p_stanZ", &Tbg_dish_all_p_stanZ},
    {0x233, "Tbg_ear_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x234, "Tbg_eld_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x235, "Tbg_imp_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x236, "Tbg_jun_all_p_stanZ", &Tbg_jun_all_p_stanZ},
    {0x237, "Tbg_lee_all_p_stanZ", &Tbg_len_all_p_stanZ},
    {0x238, "Tbg_len_all_p_stanZ", &Tbg_len_all_p_stanZ},
    {0x239, "Tbg_lip_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23A, "Tbg_lue_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23B, "Tbg_oat_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23C, "Tbg_pam_all_p_stanZ", &Tbg_pete_all_p_stanZ},
    {0x23D, "Tbg_pete_all_p_stanZ", &Tbg_pete_all_p_stanZ},
    {0x23E, "Tbg_ref_all_p_stanZ", &Tbg_ref_all_p_stanZ},
    {0x23F, "Tbg_rit_all_p_stanZ", &Tbg_run_all_p_stanZ},
    {0x240, "Tbg_run_all_p_stanZ", &Tbg_run_all_p_stanZ},
    {0x241, "Tbg_sev_all_p_stanZ", &Tbg_sev_all_p_stanZ},
    {0x242, "Tbg_sevb_all_p_stanZ", &Tbg_sevb_all_p_stanZ},
    {0x243, "Tbg_sevx_all_p_stanZ", &Tbg_sevx_all_p_stanZ},
    {0x244, "Tbg_silo_all_p_stanZ", &Tbg_silo_all_p_stanZ},
    {0x245, "Tbg_stat_all_p_stanZ", &Tbg_stat_all_p_stanZ},
    {0x246, "Tbg_tra_all_p_stanZ", &Tbg_tra_all_p_stanZ},
    {0x247, "Tbg_wax_all_p_stanZ", &UbriefarchZ},
    {0x248, "UbriefarchZ", &UbriefarchZ},
    {0x249, "UbriefarkZ", &UbriefarkZ},
    {0x24A, "UbriefaztZ", &UbriefaztZ},
    {0x24B, "UbriefcaveZ", &UbriefcaveZ},
    {0x24C, "UbriefcontrolZ", &UbriefcontrolZ},
    {0x24D, "UbriefcradZ", &UbriefcradZ},
    {0x24E, "UbriefcrypZ", &UbriefcrypZ},
    {0x24F, "UbriefdamZ", &UbriefdamZ},
    {0x250, "UbriefdepoZ", &UbriefdepoZ},
    {0x251, "UbriefdestZ", &UbriefdestZ},
    {0x252, "UbriefjunZ", &UbriefjunZ},
    {0x253, "UbriefpeteZ", &UbriefpeteZ},
    {0x254, "UbriefrunZ", &UbriefrunZ},
    {0x255, "UbriefsevbZ", &UbriefsevbZ},
    {0x256, "UbriefsevbunkerZ", &UbriefsevbunkerZ},
    {0x257, "UbriefsevxZ", &UbriefsevxZ},
    {0x258, "UbriefsevxbZ", &UbriefsevxbZ},
    {0x259, "UbriefsiloZ", &UbriefsiloZ},
    {0x25A, "UbriefstatueZ", &UbriefstatueZ},
    {0x25B, "UbrieftraZ", &UbrieftraZ},
    {0x25C, "Ump_setupameZ", &Ump_setupameZ},
    {0x25D, "Ump_setuparchZ", &Ump_setuparchZ},
    {0x25E, "Ump_setuparkZ", &Ump_setuparkZ},
    {0x25F, "Ump_setupashZ", &Ump_setupashZ},
    {0x260, "Ump_setupcaveZ", &Ump_setupcaveZ},
    {0x261, "Ump_setupcradZ", &Ump_setupcradZ},
    {0x262, "Ump_setupcrypZ", &Ump_setupcrypZ},
    {0x263, "Ump_setupdishZ", &Ump_setupdishZ},
    {0x264, "Ump_setupimpZ", &Ump_setupimpZ},
    {0x265, "Ump_setupoatZ", &Ump_setupoatZ},
    {0x266, "Ump_setuprefZ", &Ump_setuprefZ},
    {0x267, "Ump_setupsevbZ", &Ump_setupsevbZ},
    {0x268, "Ump_setupstatueZ", &Ump_setupstatueZ},
    {0x269, "UsetuparchZ", &UsetuparchZ},
    {0x26A, "UsetuparkZ", &UsetuparkZ},
    {0x26B, "UsetupaztZ", &UsetupaztZ},
    {0x26C, "UsetupcaveZ", &UsetupcaveZ},
    {0x26D, "UsetupcontrolZ", &UsetupcontrolZ},
    {0x26E, "UsetupcradZ", &UsetupcradZ},
    {0x26F, "UsetupcrypZ", &UsetupcrypZ},
    {0x270, "UsetupdamZ", &UsetupdamZ},
    {0x271, "UsetupdepoZ", &UsetupdepoZ},
    {0x272, "UsetupdestZ", &UsetupdestZ},
    {0x273, "UsetupjunZ", &UsetupjunZ},
    {0x274, "UsetuplenZ", &UsetuplenZ},
    {0x275, "UsetuppeteZ", &UsetuppeteZ},
    {0x276, "UsetuprunZ", &UsetuprunZ},
    {0x277, "UsetupsevbZ", &UsetupsevbZ},
    {0x278, "UsetupsevbunkerZ", &UsetupsevbunkerZ},
    {0x279, "UsetupsevxZ", &UsetupsevxZ},
    {0x27A, "UsetupsevxbZ", &UsetupsevxbZ},
    {0x27B, "UsetupsiloZ", &UsetupsiloZ},
    {0x27C, "UsetupstatueZ", &UsetupstatueZ},
    {0x27D, "UsetuptraZ", &UsetuptraZ},
    {0x27E, "LameE", &LameE},
    {0x27F, "LameJ", &LameJ},
    {0x280, "LarchE", &LarchE},
    {0x281, "LarchJ", &LarchJ},
    {0x282, "LarecE", &LarecE},
    {0x283, "LarecJ", &LarecJ},
    {0x284, "LarkE", &LarkE},
    {0x285, "LarkJ", &LarkJ},
    {0x286, "LashE", &LashE},
    {0x287, "LashJ", &LashJ},
    {0x288, "LaztE", &LaztE},
    {0x289, "LaztJ", &LaztJ},
    {0x28A, "LcatE", &LcatE},
    {0x28B, "LcatJ", &LcatJ},
    {0x28C, "LcaveE", &LcaveE},
    {0x28D, "LcaveJ", &LcaveJ},
    {0x28E, "LcradE", &LcradE},
    {0x28F, "LcradJ", &LcradJ},
    {0x290, "LcrypE", &LcrypE},
    {0x291, "LcrypJ", &LcrypJ},
    {0x292, "LdamE", &LdamE},
    {0x293, "LdamJ", &LdamJ},
    {0x294, "LdepoE", &LdepoE},
    {0x295, "LdepoJ", &LdepoJ},
    {0x296, "LdestE", &LdestE},
    {0x297, "LdestJ", &LdestJ},
    {0x298, "LdishE", &LdishE},
    {0x299, "LdishJ", &LdishJ},
    {0x29A, "LearE", &LearE},
    {0x29B, "LearJ", &LearJ},
    {0x29C, "LeldE", &LeldE},
    {0x29D, "LeldJ", &LeldJ},
    {0x29E, "LgunE", &LgunE},
    {0x29F, "LgunJ", &LgunJ},
    {0x2A0, "LimpE", &LimpE},
    {0x2A1, "LimpJ", &LimpJ},
    {0x2A2, "LjunE", &LjunE},
    {0x2A3, "LjunJ", &LjunJ},
    {0x2A4, "LleeE", &LleeE},
    {0x2A5, "LleeJ", &LleeJ},
    {0x2A6, "LlenE", &LlenE},
    {0x2A7, "LlenJ", &LlenJ},
    {0x2A8, "LlipE", &LlipE},
    {0x2A9, "LlipJ", &LlipJ},
    {0x2AA, "LlueE", &LlueE},
    {0x2AB, "LlueJ", &LlueJ},
    {0x2AC, "LmiscE", &LmiscE},
    {0x2AD, "LmiscJ", &LmiscJ},
    {0x2AE, "LmpmenuE", &LmpmenuE},
    {0x2AF, "LmpmenuJ", &LmpmenuJ},
    {0x2B0, "LmpweaponsE", &LmpweaponsE},
    {0x2B1, "LmpweaponsJ", &LmpweaponsJ},
    {0x2B2, "LoatE", &LoatE},
    {0x2B3, "LoatJ", &LoatJ},
    {0x2B4, "LoptionsE", &LoptionsE},
    {0x2B5, "LoptionsJ", &LoptionsJ},
    {0x2B6, "LpamE", &LpamE},
    {0x2B7, "LpamJ", &LpamJ},
    {0x2B8, "LpeteE", &LpeteE},
    {0x2B9, "LpeteJ", &LpeteJ},
    {0x2BA, "LpropobjE", &LpropobjE},
    {0x2BB, "LpropobjJ", &LpropobjJ},
    {0x2BC, "LrefE", &LrefE},
    {0x2BD, "LrefJ", &LrefJ},
    {0x2BE, "LritE", &LritE},
    {0x2BF, "LritJ", &LritJ},
    {0x2C0, "LrunE", &LrunE},
    {0x2C1, "LrunJ", &LrunJ},
    {0x2C2, "LsevE", &LsevE},
    {0x2C3, "LsevJ", &LsevJ},
    {0x2C4, "LsevbE", &LsevbE},
    {0x2C5, "LsevbJ", &LsevbJ},
    {0x2C6, "LsevxE", &LsevxE},
    {0x2C7, "LsevxJ", &LsevxJ},
    {0x2C8, "LsevxbE", &LsevxbE},
    {0x2C9, "LsevxbJ", &LsevxbJ},
    {0x2CA, "LshoE", &LshoE},
    {0x2CB, "LshoJ", &LshoJ},
    {0x2CC, "LsiloE", &LsiloE},
    {0x2CD, "LsiloJ", &LsiloJ},
    {0x2CE, "LstatE", &LstatE},
    {0x2CF, "LstatJ", &LstatJ},
    {0x2D0, "LtitleE", &LtitleE},
    {0x2D1, "LtitleJ", &LtitleJ},
    {0x2D2, "LtraE", &LtraE},
    {0x2D3, "LtraJ", &LtraJ},
    {0x2D4, "LwaxE", &LwaxE},
    {0x2D5, "LwaxJ", &LwaxJ},
    {0x2D6, "ob/ob_end.seg", &ob__ob_end_seg},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0}
};

//D:800482D4
s32 file_entry_max = 0x2D7;


// rodata


#ifdef NONMATCHING
void load_resource(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_resource
/* 0F15D0 7F0BCAA0 27BDDED8 */  addiu $sp, $sp, -0x2128
/* 0F15D4 7F0BCAA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F15D8 7F0BCAA8 AFA42128 */  sw    $a0, 0x2128($sp)
/* 0F15DC 7F0BCAAC 14A00006 */  bnez  $a1, .L7F0BCAC8
/* 0F15E0 7F0BCAB0 AFA62130 */   sw    $a2, 0x2130($sp)
/* 0F15E4 7F0BCAB4 8CC50008 */  lw    $a1, 8($a2)
/* 0F15E8 7F0BCAB8 0C001707 */  jal   romCopy
/* 0F15EC 7F0BCABC 8CE60000 */   lw    $a2, ($a3)
/* 0F15F0 7F0BCAC0 10000019 */  b     .L7F0BCB28
/* 0F15F4 7F0BCAC4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BCAC8:
/* 0F15F8 7F0BCAC8 8CE60000 */  lw    $a2, ($a3)
/* 0F15FC 7F0BCACC 8FAF2128 */  lw    $t7, 0x2128($sp)
/* 0F1600 7F0BCAD0 2401FFF8 */  li    $at, -8
/* 0F1604 7F0BCAD4 24D90007 */  addiu $t9, $a2, 7
/* 0F1608 7F0BCAD8 03214024 */  and   $t0, $t9, $at
/* 0F160C 7F0BCADC 01E5C021 */  addu  $t8, $t7, $a1
/* 0F1610 7F0BCAE0 03082023 */  subu  $a0, $t8, $t0
/* 0F1614 7F0BCAE4 008F4823 */  subu  $t1, $a0, $t7
/* 0F1618 7F0BCAE8 2D210008 */  sltiu $at, $t1, 8
/* 0F161C 7F0BCAEC 10200003 */  beqz  $at, .L7F0BCAFC
/* 0F1620 7F0BCAF0 8FAA2130 */   lw    $t2, 0x2130($sp)
/* 0F1624 7F0BCAF4 1000000B */  b     .L7F0BCB24
/* 0F1628 7F0BCAF8 ACE00004 */   sw    $zero, 4($a3)
.L7F0BCAFC:
/* 0F162C 7F0BCAFC 8D450008 */  lw    $a1, 8($t2)
/* 0F1630 7F0BCB00 AFA72134 */  sw    $a3, 0x2134($sp)
/* 0F1634 7F0BCB04 0C001707 */  jal   romCopy
/* 0F1638 7F0BCB08 AFA42124 */   sw    $a0, 0x2124($sp)
/* 0F163C 7F0BCB0C 8FA42124 */  lw    $a0, 0x2124($sp)
/* 0F1640 7F0BCB10 8FA52128 */  lw    $a1, 0x2128($sp)
/* 0F1644 7F0BCB14 0FC339FC */  jal   decompressdata
/* 0F1648 7F0BCB18 27A60024 */   addiu $a2, $sp, 0x24
/* 0F164C 7F0BCB1C 8FA72134 */  lw    $a3, 0x2134($sp)
/* 0F1650 7F0BCB20 ACE20004 */  sw    $v0, 4($a3)
.L7F0BCB24:
/* 0F1654 7F0BCB24 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BCB28:
/* 0F1658 7F0BCB28 27BD2128 */  addiu $sp, $sp, 0x2128
/* 0F165C 7F0BCB2C 03E00008 */  jr    $ra
/* 0F1660 7F0BCB30 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void resource_load_from_indy(void) {

}
#else
GLOBAL_ASM(
.rdata
/*8005b66c*/
glabel rz_header_1
.word 0x11720000
/*8005b670*/
glabel rz_header_2
.word 0x11720000
.text
glabel resource_load_from_indy
/* 0F1664 7F0BCB34 27BDDED8 */  addiu $sp, $sp, -0x2128
/* 0F1668 7F0BCB38 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F166C 7F0BCB3C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1670 7F0BCB40 00808025 */  move  $s0, $a0
/* 0F1674 7F0BCB44 00E08825 */  move  $s1, $a3
/* 0F1678 7F0BCB48 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F167C 7F0BCB4C 14A00006 */  bnez  $a1, .L7F0BCB68
/* 0F1680 7F0BCB50 AFA5212C */   sw    $a1, 0x212c($sp)
/* 0F1684 7F0BCB54 8CC40004 */  lw    $a0, 4($a2)
/* 0F1688 7F0BCB58 0FC33FE7 */  jal   load_resource_on_indy
/* 0F168C 7F0BCB5C 02002825 */   move  $a1, $s0
/* 0F1690 7F0BCB60 1000002D */  b     .L7F0BCC18
/* 0F1694 7F0BCB64 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCB68:
/* 0F1698 7F0BCB68 8CC40004 */  lw    $a0, 4($a2)
/* 0F169C 7F0BCB6C AFA62130 */  sw    $a2, 0x2130($sp)
/* 0F16A0 7F0BCB70 0FC34026 */  jal   check_file_found_on_indy
/* 0F16A4 7F0BCB74 26250008 */   addiu $a1, $s1, 8
/* 0F16A8 7F0BCB78 8E390008 */  lw    $t9, 8($s1)
/* 0F16AC 7F0BCB7C 8FAF212C */  lw    $t7, 0x212c($sp)
/* 0F16B0 7F0BCB80 2401FFF8 */  li    $at, -8
/* 0F16B4 7F0BCB84 27280007 */  addiu $t0, $t9, 7
/* 0F16B8 7F0BCB88 01014824 */  and   $t1, $t0, $at
/* 0F16BC 7F0BCB8C 020FC021 */  addu  $t8, $s0, $t7
/* 0F16C0 7F0BCB90 03093823 */  subu  $a3, $t8, $t1
/* 0F16C4 7F0BCB94 00F05023 */  subu  $t2, $a3, $s0
/* 0F16C8 7F0BCB98 2D410008 */  sltiu $at, $t2, 8
/* 0F16CC 7F0BCB9C 10200003 */  beqz  $at, .L7F0BCBAC
/* 0F16D0 7F0BCBA0 8FA62130 */   lw    $a2, 0x2130($sp)
/* 0F16D4 7F0BCBA4 1000001B */  b     .L7F0BCC14
/* 0F16D8 7F0BCBA8 AE200004 */   sw    $zero, 4($s1)
.L7F0BCBAC:
/* 0F16DC 7F0BCBAC 8CC40004 */  lw    $a0, 4($a2)
/* 0F16E0 7F0BCBB0 AFA72124 */  sw    $a3, 0x2124($sp)
/* 0F16E4 7F0BCBB4 0FC33FE7 */  jal   load_resource_on_indy
/* 0F16E8 7F0BCBB8 00E02825 */   move  $a1, $a3
/* 0F16EC 7F0BCBBC 8FA72124 */  lw    $a3, 0x2124($sp)
/* 0F16F0 7F0BCBC0 3C0C8006 */  lui   $t4, %hi(rz_header_1) 
/* 0F16F4 7F0BCBC4 918CB66C */  lbu   $t4, %lo(rz_header_1)($t4)
/* 0F16F8 7F0BCBC8 90EB0000 */  lbu   $t3, ($a3)
/* 0F16FC 7F0BCBCC 3C0E8006 */  lui   $t6, %hi(rz_header_2 + 0x1) 
/* 0F1700 7F0BCBD0 02002825 */  move  $a1, $s0
/* 0F1704 7F0BCBD4 156C000B */  bne   $t3, $t4, .L7F0BCC04
/* 0F1708 7F0BCBD8 00E02025 */   move  $a0, $a3
/* 0F170C 7F0BCBDC 90ED0001 */  lbu   $t5, 1($a3)
/* 0F1710 7F0BCBE0 91CEB671 */  lbu   $t6, %lo(rz_header_2 + 0x1)($t6)
/* 0F1714 7F0BCBE4 27A60024 */  addiu $a2, $sp, 0x24
/* 0F1718 7F0BCBE8 15AE0006 */  bne   $t5, $t6, .L7F0BCC04
/* 0F171C 7F0BCBEC 00000000 */   nop   
/* 0F1720 7F0BCBF0 00E02025 */  move  $a0, $a3
/* 0F1724 7F0BCBF4 0FC339FC */  jal   decompressdata
/* 0F1728 7F0BCBF8 02002825 */   move  $a1, $s0
/* 0F172C 7F0BCBFC 10000004 */  b     .L7F0BCC10
/* 0F1730 7F0BCC00 00401825 */   move  $v1, $v0
.L7F0BCC04:
/* 0F1734 7F0BCC04 0C003E5C */  jal   _bcopy
/* 0F1738 7F0BCC08 8E260008 */   lw    $a2, 8($s1)
/* 0F173C 7F0BCC0C 8E230008 */  lw    $v1, 8($s1)
.L7F0BCC10:
/* 0F1740 7F0BCC10 AE230004 */  sw    $v1, 4($s1)
.L7F0BCC14:
/* 0F1744 7F0BCC14 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCC18:
/* 0F1748 7F0BCC18 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F174C 7F0BCC1C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1750 7F0BCC20 03E00008 */  jr    $ra
/* 0F1754 7F0BCC24 27BD2128 */   addiu $sp, $sp, 0x2128
)
#endif





#ifdef NONMATCHING
void *ob_c_debug_setup(void) {
    s32 temp_v1;
    u32 temp_v0;
    void *phi_a0;
    u32 phi_v0;

    // Node 0
    get_ptr_debug_notice_list_entry(&D_80046050, &aOb_c_debug);
    temp_v1 = (file_entry_max + -1);
    if (temp_v1 >= 2)
    {
        // Node 1
        phi_a0 = (void *) (file_resource_table + 0xc);
        phi_v0 = &ptr_res_data_next;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 0x14);
        temp_v0->unk-14 = (s32) (phi_a0->unk14 - phi_a0->unk8);
        temp_v0->unk-10 = 0;
        temp_v0->unk-C = 0;
        temp_v0->unk-8 = 0;
        phi_a0 = (phi_a0 + 0xc);
        phi_v0 = temp_v0;
        if (temp_v0 < (u32) ((temp_v1 * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 3
    return &ptr_res_data_next;
}
#else
GLOBAL_ASM(
.rdata
/*D:8005B674*/
glabel aOb_c_debug
/*"ob_c_debug"*/
.word 0x6F625F63, 0x5F646562, 0x75670000
.text
glabel ob_c_debug_setup
/* 0F1758 7F0BCC28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F175C 7F0BCC2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1760 7F0BCC30 3C048004 */  lui   $a0, %hi(D_80046050)
/* 0F1764 7F0BCC34 3C058006 */  lui   $a1, %hi(aOb_c_debug)
/* 0F1768 7F0BCC38 24A5B674 */  addiu $a1, %lo(aOb_c_debug) # addiu $a1, $a1, -0x498c
/* 0F176C 7F0BCC3C 0C001398 */  jal   get_ptr_debug_notice_list_entry
/* 0F1770 7F0BCC40 24846050 */   addiu $a0, %lo(D_80046050) # addiu $a0, $a0, 0x6050
/* 0F1774 7F0BCC44 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1778 7F0BCC48 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F177C 7F0BCC4C 3C048004 */  lui   $a0, %hi(file_resource_table + 0xC)
/* 0F1780 7F0BCC50 24846060 */  addiu $a0, %lo(file_resource_table + 0xC) # addiu $a0, $a0, 0x6060
/* 0F1784 7F0BCC54 2463FFFF */  addiu $v1, $v1, -1
/* 0F1788 7F0BCC58 28610002 */  slti  $at, $v1, 2
/* 0F178C 7F0BCC5C 14200013 */  bnez  $at, .L7F0BCCAC
/* 0F1790 7F0BCC60 3C028009 */   lui   $v0, %hi(ptr_res_data_next)
/* 0F1794 7F0BCC64 00037080 */  sll   $t6, $v1, 2
/* 0F1798 7F0BCC68 01C37021 */  addu  $t6, $t6, $v1
/* 0F179C 7F0BCC6C 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) 
/* 0F17A0 7F0BCC70 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F17A4 7F0BCC74 000E7080 */  sll   $t6, $t6, 2
/* 0F17A8 7F0BCC78 01CF2821 */  addu  $a1, $t6, $t7
/* 0F17AC 7F0BCC7C 244288C4 */  addiu $v0, %lo(ptr_res_data_next) # addiu $v0, $v0, -0x773c
.L7F0BCC80:
/* 0F17B0 7F0BCC80 8C980014 */  lw    $t8, 0x14($a0)
/* 0F17B4 7F0BCC84 8C990008 */  lw    $t9, 8($a0)
/* 0F17B8 7F0BCC88 24420014 */  addiu $v0, $v0, 0x14
/* 0F17BC 7F0BCC8C 0045082B */  sltu  $at, $v0, $a1
/* 0F17C0 7F0BCC90 03191823 */  subu  $v1, $t8, $t9
/* 0F17C4 7F0BCC94 2484000C */  addiu $a0, $a0, 0xc
/* 0F17C8 7F0BCC98 AC43FFEC */  sw    $v1, -0x14($v0)
/* 0F17CC 7F0BCC9C AC40FFF0 */  sw    $zero, -0x10($v0)
/* 0F17D0 7F0BCCA0 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F17D4 7F0BCCA4 1420FFF6 */  bnez  $at, .L7F0BCC80
/* 0F17D8 7F0BCCA8 AC40FFF8 */   sw    $zero, -8($v0)
.L7F0BCCAC:
/* 0F17DC 7F0BCCAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F17E0 7F0BCCB0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F17E4 7F0BCCB4 03E00008 */  jr    $ra
/* 0F17E8 7F0BCCB8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_rom_index_to_membank(s32 arg3) {
    load_rom_resource_index_to_membank((arg3 & 0xff));
}

#else
GLOBAL_ASM(
.text
glabel _load_rom_index_to_membank
/* 0F17EC 7F0BCCBC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F17F0 7F0BCCC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F17F4 7F0BCCC4 AFA70024 */  sw    $a3, 0x24($sp)
/* 0F17F8 7F0BCCC8 30EE00FF */  andi  $t6, $a3, 0xff
/* 0F17FC 7F0BCCCC 0FC2F383 */  jal   load_rom_resource_index_to_membank
/* 0F1800 7F0BCCD0 01C03825 */   move  $a3, $t6
/* 0F1804 7F0BCCD4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1808 7F0BCCD8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F180C 7F0BCCDC 03E00008 */  jr    $ra
/* 0F1810 7F0BCCE0 00000000 */   nop   
)
#endif





void _load_resource_index_to_membank(void) {
    load_resource_index_to_buffer();
}






#ifdef NONMATCHING
void _load_resource_named_to_membank(s32 arg1, ? arg2, ? arg3, ? arg_unalignedF) {
    // Node 0
    return load_rom_resource_index_to_membank(get_index_num_of_named_resource(), arg1, arg2, arg_unalignedF);
}
#else
GLOBAL_ASM(
.text
glabel _load_resource_named_to_membank
/* 0F1834 7F0BCD04 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1838 7F0BCD08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F183C 7F0BCD0C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F1840 7F0BCD10 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F1844 7F0BCD14 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1848 7F0BCD18 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F184C 7F0BCD1C 00402025 */  move  $a0, $v0
/* 0F1850 7F0BCD20 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0F1854 7F0BCD24 8FA60020 */  lw    $a2, 0x20($sp)
/* 0F1858 7F0BCD28 0FC2F383 */  jal   load_rom_resource_index_to_membank
/* 0F185C 7F0BCD2C 93A70027 */   lbu   $a3, 0x27($sp)
/* 0F1860 7F0BCD30 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1864 7F0BCD34 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1868 7F0BCD38 03E00008 */  jr    $ra
/* 0F186C 7F0BCD3C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_resource_named_to_buffer(s32 arg1, ? arg2, ? arg3) {
    load_resource_index_to_buffer(get_index_num_of_named_resource(), arg1, arg2, arg3);
}

#else
GLOBAL_ASM(
.text
glabel _load_resource_named_to_buffer
/* 0F1870 7F0BCD40 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1874 7F0BCD44 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1878 7F0BCD48 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F187C 7F0BCD4C AFA60020 */  sw    $a2, 0x20($sp)
/* 0F1880 7F0BCD50 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1884 7F0BCD54 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F1888 7F0BCD58 00402025 */  move  $a0, $v0
/* 0F188C 7F0BCD5C 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0F1890 7F0BCD60 8FA60020 */  lw    $a2, 0x20($sp)
/* 0F1894 7F0BCD64 0FC2F3F8 */  jal   load_resource_index_to_buffer
/* 0F1898 7F0BCD68 8FA70024 */   lw    $a3, 0x24($sp)
/* 0F189C 7F0BCD6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F18A0 7F0BCD70 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F18A4 7F0BCD74 03E00008 */  jr    $ra
/* 0F18A8 7F0BCD78 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_bg_bytes_at_offset_to_membank(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_bg_bytes_at_offset_to_membank
/* 0F18AC 7F0BCD7C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F18B0 7F0BCD80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F18B4 7F0BCD84 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F18B8 7F0BCD88 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F18BC 7F0BCD8C 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F18C0 7F0BCD90 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F18C4 7F0BCD94 0002C080 */  sll   $t8, $v0, 2
/* 0F18C8 7F0BCD98 0302C021 */  addu  $t8, $t8, $v0
/* 0F18CC 7F0BCD9C 0018C080 */  sll   $t8, $t8, 2
/* 0F18D0 7F0BCDA0 3C038009 */  lui   $v1, %hi(ptr_resource_data)
/* 0F18D4 7F0BCDA4 00781821 */  addu  $v1, $v1, $t8
/* 0F18D8 7F0BCDA8 8C6388B0 */  lw    $v1, %lo(ptr_resource_data)($v1)
/* 0F18DC 7F0BCDAC 00027080 */  sll   $t6, $v0, 2
/* 0F18E0 7F0BCDB0 01C27023 */  subu  $t6, $t6, $v0
/* 0F18E4 7F0BCDB4 3C0F8004 */  lui   $t7, %hi(file_resource_table) 
/* 0F18E8 7F0BCDB8 25EF6054 */  addiu $t7, %lo(file_resource_table) # addiu $t7, $t7, 0x6054
/* 0F18EC 7F0BCDBC 000E7080 */  sll   $t6, $t6, 2
/* 0F18F0 7F0BCDC0 8FA60024 */  lw    $a2, 0x24($sp)
/* 0F18F4 7F0BCDC4 8FA80020 */  lw    $t0, 0x20($sp)
/* 0F18F8 7F0BCDC8 1060000C */  beqz  $v1, .L7F0BCDFC
/* 0F18FC 7F0BCDCC 01CF3821 */   addu  $a3, $t6, $t7
/* 0F1900 7F0BCDD0 0106C821 */  addu  $t9, $t0, $a2
/* 0F1904 7F0BCDD4 2469000F */  addiu $t1, $v1, 0xf
/* 0F1908 7F0BCDD8 0139082B */  sltu  $at, $t1, $t9
/* 0F190C 7F0BCDDC 50200004 */  beql  $at, $zero, .L7F0BCDF0
/* 0F1910 7F0BCDE0 8CEA0008 */   lw    $t2, 8($a3)
.L7F0BCDE4:
/* 0F1914 7F0BCDE4 1000FFFF */  b     .L7F0BCDE4
/* 0F1918 7F0BCDE8 00000000 */   nop   
/* 0F191C 7F0BCDEC 8CEA0008 */  lw    $t2, 8($a3)
.L7F0BCDF0:
/* 0F1920 7F0BCDF0 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F1924 7F0BCDF4 0C001707 */  jal   romCopy
/* 0F1928 7F0BCDF8 01482821 */   addu  $a1, $t2, $t0
.L7F0BCDFC:
/* 0F192C 7F0BCDFC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1930 7F0BCE00 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1934 7F0BCE04 03E00008 */  jr    $ra
/* 0F1938 7F0BCE08 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_rom_resource_index_to_membank(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_rom_resource_index_to_membank
/* 0F193C 7F0BCE0C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1940 7F0BCE10 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1944 7F0BCE14 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1948 7F0BCE18 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F194C 7F0BCE1C AFA40030 */  sw    $a0, 0x30($sp)
/* 0F1950 7F0BCE20 AFA50034 */  sw    $a1, 0x34($sp)
/* 0F1954 7F0BCE24 AFA60038 */  sw    $a2, 0x38($sp)
/* 0F1958 7F0BCE28 10A00006 */  beqz  $a1, .L7F0BCE44
/* 0F195C 7F0BCE2C AFA7003C */   sw    $a3, 0x3c($sp)
/* 0F1960 7F0BCE30 24010001 */  li    $at, 1
/* 0F1964 7F0BCE34 10A10003 */  beq   $a1, $at, .L7F0BCE44
/* 0F1968 7F0BCE38 24010002 */   li    $at, 2
/* 0F196C 7F0BCE3C 14A10033 */  bne   $a1, $at, .L7F0BCF0C
/* 0F1970 7F0BCE40 8FAD0030 */   lw    $t5, 0x30($sp)
.L7F0BCE44:
/* 0F1974 7F0BCE44 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0F1978 7F0BCE48 3C198009 */  lui   $t9, %hi(ptr_resource_data) 
/* 0F197C 7F0BCE4C 273988B0 */  addiu $t9, %lo(ptr_resource_data) # addiu $t9, $t9, -0x7750
/* 0F1980 7F0BCE50 000FC080 */  sll   $t8, $t7, 2
/* 0F1984 7F0BCE54 030FC021 */  addu  $t8, $t8, $t7
/* 0F1988 7F0BCE58 0018C080 */  sll   $t8, $t8, 2
/* 0F198C 7F0BCE5C 03198821 */  addu  $s1, $t8, $t9
/* 0F1990 7F0BCE60 8E300004 */  lw    $s0, 4($s1)
/* 0F1994 7F0BCE64 56000006 */  bnezl $s0, .L7F0BCE80
/* 0F1998 7F0BCE68 02002025 */   move  $a0, $s0
/* 0F199C 7F0BCE6C 0C002644 */  jal   memp_related_3
/* 0F19A0 7F0BCE70 93A4003F */   lbu   $a0, 0x3f($sp)
/* 0F19A4 7F0BCE74 AE220004 */  sw    $v0, 4($s1)
/* 0F19A8 7F0BCE78 00408025 */  move  $s0, $v0
/* 0F19AC 7F0BCE7C 02002025 */  move  $a0, $s0
.L7F0BCE80:
/* 0F19B0 7F0BCE80 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F19B4 7F0BCE84 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F19B8 7F0BCE88 8E300004 */  lw    $s0, 4($s1)
/* 0F19BC 7F0BCE8C 3C0A8004 */  lui   $t2, %hi(file_resource_table) 
/* 0F19C0 7F0BCE90 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F19C4 7F0BCE94 AE30000C */  sw    $s0, 0xc($s1)
/* 0F19C8 7F0BCE98 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F19CC 7F0BCE9C 00402025 */  move  $a0, $v0
/* 0F19D0 7F0BCEA0 02203825 */  move  $a3, $s1
/* 0F19D4 7F0BCEA4 00084880 */  sll   $t1, $t0, 2
/* 0F19D8 7F0BCEA8 01284823 */  subu  $t1, $t1, $t0
/* 0F19DC 7F0BCEAC 00094880 */  sll   $t1, $t1, 2
/* 0F19E0 7F0BCEB0 012A3021 */  addu  $a2, $t1, $t2
/* 0F19E4 7F0BCEB4 8CCB0008 */  lw    $t3, 8($a2)
/* 0F19E8 7F0BCEB8 02002825 */  move  $a1, $s0
/* 0F19EC 7F0BCEBC 15600007 */  bnez  $t3, .L7F0BCEDC
/* 0F19F0 7F0BCEC0 00000000 */   nop   
/* 0F19F4 7F0BCEC4 02002825 */  move  $a1, $s0
/* 0F19F8 7F0BCEC8 02203825 */  move  $a3, $s1
/* 0F19FC 7F0BCECC 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1A00 7F0BCED0 AFA20024 */   sw    $v0, 0x24($sp)
/* 0F1A04 7F0BCED4 10000004 */  b     .L7F0BCEE8
/* 0F1A08 7F0BCED8 8FB00024 */   lw    $s0, 0x24($sp)
.L7F0BCEDC:
/* 0F1A0C 7F0BCEDC 0FC2F2A8 */  jal   load_resource
/* 0F1A10 7F0BCEE0 AFA40024 */   sw    $a0, 0x24($sp)
/* 0F1A14 7F0BCEE4 8FB00024 */  lw    $s0, 0x24($sp)
.L7F0BCEE8:
/* 0F1A18 7F0BCEE8 8FAC0034 */  lw    $t4, 0x34($sp)
/* 0F1A1C 7F0BCEEC 02002025 */  move  $a0, $s0
/* 0F1A20 7F0BCEF0 93A6003F */  lbu   $a2, 0x3f($sp)
/* 0F1A24 7F0BCEF4 51800035 */  beql  $t4, $zero, .L7F0BCFCC
/* 0F1A28 7F0BCEF8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1A2C 7F0BCEFC 0C002601 */  jal   memp_related_1
/* 0F1A30 7F0BCF00 8E250004 */   lw    $a1, 4($s1)
/* 0F1A34 7F0BCF04 10000031 */  b     .L7F0BCFCC
/* 0F1A38 7F0BCF08 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCF0C:
/* 0F1A3C 7F0BCF0C 000D7080 */  sll   $t6, $t5, 2
/* 0F1A40 7F0BCF10 01CD7021 */  addu  $t6, $t6, $t5
/* 0F1A44 7F0BCF14 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) 
/* 0F1A48 7F0BCF18 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1A4C 7F0BCF1C 000E7080 */  sll   $t6, $t6, 2
/* 0F1A50 7F0BCF20 01CF8821 */  addu  $s1, $t6, $t7
/* 0F1A54 7F0BCF24 8E300004 */  lw    $s0, 4($s1)
/* 0F1A58 7F0BCF28 56000009 */  bnezl $s0, .L7F0BCF50
/* 0F1A5C 7F0BCF2C 02002025 */   move  $a0, $s0
/* 0F1A60 7F0BCF30 8E220000 */  lw    $v0, ($s1)
/* 0F1A64 7F0BCF34 10400003 */  beqz  $v0, .L7F0BCF44
/* 0F1A68 7F0BCF38 00408025 */   move  $s0, $v0
/* 0F1A6C 7F0BCF3C 10000003 */  b     .L7F0BCF4C
/* 0F1A70 7F0BCF40 AE220004 */   sw    $v0, 4($s1)
.L7F0BCF44:
/* 0F1A74 7F0BCF44 8E300008 */  lw    $s0, 8($s1)
/* 0F1A78 7F0BCF48 AE300004 */  sw    $s0, 4($s1)
.L7F0BCF4C:
/* 0F1A7C 7F0BCF4C 02002025 */  move  $a0, $s0
.L7F0BCF50:
/* 0F1A80 7F0BCF50 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F1A84 7F0BCF54 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F1A88 7F0BCF58 8E390004 */  lw    $t9, 4($s1)
/* 0F1A8C 7F0BCF5C 3C0A8004 */  lui   $t2, %hi(file_resource_table) 
/* 0F1A90 7F0BCF60 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F1A94 7F0BCF64 AE39000C */  sw    $t9, 0xc($s1)
/* 0F1A98 7F0BCF68 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F1A9C 7F0BCF6C 00408025 */  move  $s0, $v0
/* 0F1AA0 7F0BCF70 02203825 */  move  $a3, $s1
/* 0F1AA4 7F0BCF74 00084880 */  sll   $t1, $t0, 2
/* 0F1AA8 7F0BCF78 01284823 */  subu  $t1, $t1, $t0
/* 0F1AAC 7F0BCF7C 00094880 */  sll   $t1, $t1, 2
/* 0F1AB0 7F0BCF80 012A3021 */  addu  $a2, $t1, $t2
/* 0F1AB4 7F0BCF84 8CCB0008 */  lw    $t3, 8($a2)
/* 0F1AB8 7F0BCF88 02002025 */  move  $a0, $s0
/* 0F1ABC 7F0BCF8C 00002825 */  move  $a1, $zero
/* 0F1AC0 7F0BCF90 15600006 */  bnez  $t3, .L7F0BCFAC
/* 0F1AC4 7F0BCF94 00000000 */   nop   
/* 0F1AC8 7F0BCF98 00402025 */  move  $a0, $v0
/* 0F1ACC 7F0BCF9C 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1AD0 7F0BCFA0 00002825 */   move  $a1, $zero
/* 0F1AD4 7F0BCFA4 10000004 */  b     .L7F0BCFB8
/* 0F1AD8 7F0BCFA8 8FAC0038 */   lw    $t4, 0x38($sp)
.L7F0BCFAC:
/* 0F1ADC 7F0BCFAC 0FC2F2A8 */  jal   load_resource
/* 0F1AE0 7F0BCFB0 02203825 */   move  $a3, $s1
/* 0F1AE4 7F0BCFB4 8FAC0038 */  lw    $t4, 0x38($sp)
.L7F0BCFB8:
/* 0F1AE8 7F0BCFB8 93AD003F */  lbu   $t5, 0x3f($sp)
/* 0F1AEC 7F0BCFBC 55800003 */  bnezl $t4, .L7F0BCFCC
/* 0F1AF0 7F0BCFC0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1AF4 7F0BCFC4 A22D0010 */  sb    $t5, 0x10($s1)
/* 0F1AF8 7F0BCFC8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCFCC:
/* 0F1AFC 7F0BCFCC 02001025 */  move  $v0, $s0
/* 0F1B00 7F0BCFD0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1B04 7F0BCFD4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1B08 7F0BCFD8 03E00008 */  jr    $ra
/* 0F1B0C 7F0BCFDC 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void load_resource_index_to_buffer(s32 arg0, s32 arg1, ? arg2, ?32 arg3) {
    void *temp_s0;
    void *temp_a2;
    void *temp_a2_2;

    // Node 0
    temp_s0 = ((arg0 * 0x14) + &ptr_resource_data);
    if (temp_s0->unk4 == 0)
    {
        // Node 1
        if (*temp_s0 != 0)
        {
            // Node 2
            temp_s0->unk4 = (s32) *temp_s0;
        }
        else
        {
            // Node 3
            temp_s0->unk4 = (s32) temp_s0->unk8;
        }
    }
    // Node 4
    if (((arg1 == 0) || (arg1 == 2)) || (arg1 == 2))
    {
        // Node 7
        temp_a2_2 = ((arg0 * 0xc) + &file_resource_table);
        if (temp_a2_2->unk8 == 0)
        {
            // Node 8
            temp_s0->unkC = arg3;
            resource_load_from_indy(arg2, arg3, temp_a2_2, temp_s0);
        }
        else
        {
            // Node 9
            temp_s0->unkC = arg3;
            load_resource(arg2, arg3, temp_a2_2, temp_s0);
        }
    }
    else
    {
        // Node 10
        temp_a2 = ((arg0 * 0xc) + &file_resource_table);
        if (temp_a2->unk8 == 0)
        {
            // Node 11
            resource_load_from_indy(arg2, 0, temp_a2, temp_s0);
        }
        else
        {
            // Node 12
            load_resource(arg2, 0, temp_a2, temp_s0);
        }
    }
    // Node 13
    return arg2;
}
#else
GLOBAL_ASM(
.text
glabel load_resource_index_to_buffer
/* 0F1B10 7F0BCFE0 00047080 */  sll   $t6, $a0, 2
/* 0F1B14 7F0BCFE4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1B18 7F0BCFE8 01C47021 */  addu  $t6, $t6, $a0
/* 0F1B1C 7F0BCFEC 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) 
/* 0F1B20 7F0BCFF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F1B24 7F0BCFF4 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1B28 7F0BCFF8 000E7080 */  sll   $t6, $t6, 2
/* 0F1B2C 7F0BCFFC 01CF8021 */  addu  $s0, $t6, $t7
/* 0F1B30 7F0BD000 8E180004 */  lw    $t8, 4($s0)
/* 0F1B34 7F0BD004 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1B38 7F0BD008 AFA60028 */  sw    $a2, 0x28($sp)
/* 0F1B3C 7F0BD00C 17000008 */  bnez  $t8, .L7F0BD030
/* 0F1B40 7F0BD010 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F1B44 7F0BD014 8E020000 */  lw    $v0, ($s0)
/* 0F1B48 7F0BD018 50400004 */  beql  $v0, $zero, .L7F0BD02C
/* 0F1B4C 7F0BD01C 8E190008 */   lw    $t9, 8($s0)
/* 0F1B50 7F0BD020 10000003 */  b     .L7F0BD030
/* 0F1B54 7F0BD024 AE020004 */   sw    $v0, 4($s0)
/* 0F1B58 7F0BD028 8E190008 */  lw    $t9, 8($s0)
.L7F0BD02C:
/* 0F1B5C 7F0BD02C AE190004 */  sw    $t9, 4($s0)
.L7F0BD030:
/* 0F1B60 7F0BD030 10A00005 */  beqz  $a1, .L7F0BD048
/* 0F1B64 7F0BD034 24010001 */   li    $at, 1
/* 0F1B68 7F0BD038 10A10003 */  beq   $a1, $at, .L7F0BD048
/* 0F1B6C 7F0BD03C 24010002 */   li    $at, 2
/* 0F1B70 7F0BD040 14A10019 */  bne   $a1, $at, .L7F0BD0A8
/* 0F1B74 7F0BD044 00046880 */   sll   $t5, $a0, 2
.L7F0BD048:
/* 0F1B78 7F0BD048 00044080 */  sll   $t0, $a0, 2
/* 0F1B7C 7F0BD04C 01044023 */  subu  $t0, $t0, $a0
/* 0F1B80 7F0BD050 3C098004 */  lui   $t1, %hi(file_resource_table) 
/* 0F1B84 7F0BD054 25296054 */  addiu $t1, %lo(file_resource_table) # addiu $t1, $t1, 0x6054
/* 0F1B88 7F0BD058 00084080 */  sll   $t0, $t0, 2
/* 0F1B8C 7F0BD05C 01093021 */  addu  $a2, $t0, $t1
/* 0F1B90 7F0BD060 8CCA0008 */  lw    $t2, 8($a2)
/* 0F1B94 7F0BD064 8FAB002C */  lw    $t3, 0x2c($sp)
/* 0F1B98 7F0BD068 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0F1B9C 7F0BD06C 15400008 */  bnez  $t2, .L7F0BD090
/* 0F1BA0 7F0BD070 02003825 */   move  $a3, $s0
/* 0F1BA4 7F0BD074 AE0B000C */  sw    $t3, 0xc($s0)
/* 0F1BA8 7F0BD078 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BAC 7F0BD07C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BB0 7F0BD080 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1BB4 7F0BD084 02003825 */   move  $a3, $s0
/* 0F1BB8 7F0BD088 10000019 */  b     .L7F0BD0F0
/* 0F1BBC 7F0BD08C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD090:
/* 0F1BC0 7F0BD090 AE0C000C */  sw    $t4, 0xc($s0)
/* 0F1BC4 7F0BD094 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BC8 7F0BD098 0FC2F2A8 */  jal   load_resource
/* 0F1BCC 7F0BD09C 8FA40028 */   lw    $a0, 0x28($sp)
/* 0F1BD0 7F0BD0A0 10000013 */  b     .L7F0BD0F0
/* 0F1BD4 7F0BD0A4 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0A8:
/* 0F1BD8 7F0BD0A8 01A46823 */  subu  $t5, $t5, $a0
/* 0F1BDC 7F0BD0AC 3C0E8004 */  lui   $t6, %hi(file_resource_table) 
/* 0F1BE0 7F0BD0B0 25CE6054 */  addiu $t6, %lo(file_resource_table) # addiu $t6, $t6, 0x6054
/* 0F1BE4 7F0BD0B4 000D6880 */  sll   $t5, $t5, 2
/* 0F1BE8 7F0BD0B8 01AE3021 */  addu  $a2, $t5, $t6
/* 0F1BEC 7F0BD0BC 8CCF0008 */  lw    $t7, 8($a2)
/* 0F1BF0 7F0BD0C0 02003825 */  move  $a3, $s0
/* 0F1BF4 7F0BD0C4 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BF8 7F0BD0C8 15E00006 */  bnez  $t7, .L7F0BD0E4
/* 0F1BFC 7F0BD0CC 00002825 */   move  $a1, $zero
/* 0F1C00 7F0BD0D0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1C04 7F0BD0D4 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1C08 7F0BD0D8 00002825 */   move  $a1, $zero
/* 0F1C0C 7F0BD0DC 10000004 */  b     .L7F0BD0F0
/* 0F1C10 7F0BD0E0 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0E4:
/* 0F1C14 7F0BD0E4 0FC2F2A8 */  jal   load_resource
/* 0F1C18 7F0BD0E8 02003825 */   move  $a3, $s0
/* 0F1C1C 7F0BD0EC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BD0F0:
/* 0F1C20 7F0BD0F0 8FA20028 */  lw    $v0, 0x28($sp)
/* 0F1C24 7F0BD0F4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F1C28 7F0BD0F8 03E00008 */  jr    $ra
/* 0F1C2C 7F0BD0FC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void get_temp_remaining_buffer_for_index(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_temp_remaining_buffer_for_index
/* 0F1C30 7F0BD100 00047080 */  sll   $t6, $a0, 2
/* 0F1C34 7F0BD104 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C38 7F0BD108 000E7080 */  sll   $t6, $t6, 2
/* 0F1C3C 7F0BD10C 3C028009 */  lui   $v0, %hi(ptr_resource_data+4)
/* 0F1C40 7F0BD110 004E1021 */  addu  $v0, $v0, $t6
/* 0F1C44 7F0BD114 03E00008 */  jr    $ra
/* 0F1C48 7F0BD118 8C4288B4 */   lw    $v0, %lo(ptr_resource_data+4)($v0)
)
#endif





#ifdef NONMATCHING
void get_remaining_buffer_for_index(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_remaining_buffer_for_index
/* 0F1C4C 7F0BD11C 00047080 */  sll   $t6, $a0, 2
/* 0F1C50 7F0BD120 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C54 7F0BD124 000E7080 */  sll   $t6, $t6, 2
/* 0F1C58 7F0BD128 3C028009 */  lui   $v0, %hi(ptr_resource_data+12)
/* 0F1C5C 7F0BD12C 004E1021 */  addu  $v0, $v0, $t6
/* 0F1C60 7F0BD130 03E00008 */  jr    $ra
/* 0F1C64 7F0BD134 8C4288BC */   lw    $v0, %lo(ptr_resource_data+12)($v0)
)
#endif





#ifdef NONMATCHING
void *sub_GAME_7F0BD138(s32 arg0, s32 arg1, ?32 arg2, s32 arg3) {
    void *temp_v0;

    // Node 0
    temp_v0 = ((arg0 * 0x14) + &ptr_resource_data);
    temp_v0->unk4 = arg2;
    temp_v0->unkC = arg2;
    if (arg3 != 0)
    {
        // Node 1
        memp_related_1(arg1, arg2, 4);
        return;
        // (possible return value: memp_related_1(arg1, arg2, 4))
    }
    // (possible return value: temp_v0)
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD138
/* 0F1C68 7F0BD138 00047080 */  sll   $t6, $a0, 2
/* 0F1C6C 7F0BD13C 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C70 7F0BD140 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) 
/* 0F1C74 7F0BD144 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1C78 7F0BD148 000E7080 */  sll   $t6, $t6, 2
/* 0F1C7C 7F0BD14C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1C80 7F0BD150 01CF1021 */  addu  $v0, $t6, $t7
/* 0F1C84 7F0BD154 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1C88 7F0BD158 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F1C8C 7F0BD15C AC460004 */  sw    $a2, 4($v0)
/* 0F1C90 7F0BD160 10E00005 */  beqz  $a3, .L7F0BD178
/* 0F1C94 7F0BD164 AC46000C */   sw    $a2, 0xc($v0)
/* 0F1C98 7F0BD168 00A02025 */  move  $a0, $a1
/* 0F1C9C 7F0BD16C 00C02825 */  move  $a1, $a2
/* 0F1CA0 7F0BD170 0C002601 */  jal   memp_related_1
/* 0F1CA4 7F0BD174 24060004 */   li    $a2, 4
.L7F0BD178:
/* 0F1CA8 7F0BD178 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1CAC 7F0BD17C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1CB0 7F0BD180 03E00008 */  jr    $ra
/* 0F1CB4 7F0BD184 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD188(void) {
    // Node 0
    get_index_num_of_named_resource();
    return;
    // (possible return value: *((ptr_resource_data + 4) + (((get_index_num_of_named_resource() * 4) + get_index_num_of_named_resource()) * 4)))
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD188
/* 0F1CB8 7F0BD188 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1CBC 7F0BD18C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1CC0 7F0BD190 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1CC4 7F0BD194 00000000 */   nop   
/* 0F1CC8 7F0BD198 00027080 */  sll   $t6, $v0, 2
/* 0F1CCC 7F0BD19C 01C27021 */  addu  $t6, $t6, $v0
/* 0F1CD0 7F0BD1A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1CD4 7F0BD1A4 000E7080 */  sll   $t6, $t6, 2
/* 0F1CD8 7F0BD1A8 3C028009 */  lui   $v0, %hi(ptr_resource_data+4)
/* 0F1CDC 7F0BD1AC 004E1021 */  addu  $v0, $v0, $t6
/* 0F1CE0 7F0BD1B0 8C4288B4 */  lw    $v0, %lo(ptr_resource_data+4)($v0)
/* 0F1CE4 7F0BD1B4 03E00008 */  jr    $ra
/* 0F1CE8 7F0BD1B8 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
s32 something_mem_bank_a0(s32 arg0) {
    s32 temp_t6;
    u32 temp_a1;
    void *phi_a1;

    // Node 0
    temp_t6 = (arg0 & 0xff);
    if (file_entry_max >= 2)
    {
        // Node 1
        phi_a1 = &ptr_res_data_next;
        // Node 2
        if (temp_t6 >= phi_a1->unk10)
        {
            // Node 3
            phi_a1->unk10 = (u8)0;
        }
        // Node 4
        if (4 == temp_t6)
        {
            // Node 5
            phi_a1->unk4 = 0;
        }
        // Node 6
        temp_a1 = (phi_a1 + 0x14);
        phi_a1 = temp_a1;
        if (temp_a1 < (u32) ((file_entry_max * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 7
    return temp_t6;
}
#else
GLOBAL_ASM(
.text
glabel something_mem_bank_a0
/* 0F1CEC 7F0BD1BC 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1CF0 7F0BD1C0 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1CF4 7F0BD1C4 308E00FF */  andi  $t6, $a0, 0xff
/* 0F1CF8 7F0BD1C8 AFA40000 */  sw    $a0, ($sp)
/* 0F1CFC 7F0BD1CC 28610002 */  slti  $at, $v1, 2
/* 0F1D00 7F0BD1D0 14200016 */  bnez  $at, .L7F0BD22C
/* 0F1D04 7F0BD1D4 01C01025 */   move  $v0, $t6
/* 0F1D08 7F0BD1D8 00037880 */  sll   $t7, $v1, 2
/* 0F1D0C 7F0BD1DC 01E37821 */  addu  $t7, $t7, $v1
/* 0F1D10 7F0BD1E0 3C188009 */  lui   $t8, %hi(ptr_resource_data) 
/* 0F1D14 7F0BD1E4 271888B0 */  addiu $t8, %lo(ptr_resource_data) # addiu $t8, $t8, -0x7750
/* 0F1D18 7F0BD1E8 000F7880 */  sll   $t7, $t7, 2
/* 0F1D1C 7F0BD1EC 3C058009 */  lui   $a1, %hi(ptr_res_data_next)
/* 0F1D20 7F0BD1F0 24A588C4 */  addiu $a1, %lo(ptr_res_data_next) # addiu $a1, $a1, -0x773c
/* 0F1D24 7F0BD1F4 01F83021 */  addu  $a2, $t7, $t8
/* 0F1D28 7F0BD1F8 24030004 */  li    $v1, 4
/* 0F1D2C 7F0BD1FC 90B90010 */  lbu   $t9, 0x10($a1)
.L7F0BD200:
/* 0F1D30 7F0BD200 0059082A */  slt   $at, $v0, $t9
/* 0F1D34 7F0BD204 14200002 */  bnez  $at, .L7F0BD210
/* 0F1D38 7F0BD208 00000000 */   nop   
/* 0F1D3C 7F0BD20C A0A00010 */  sb    $zero, 0x10($a1)
.L7F0BD210:
/* 0F1D40 7F0BD210 54620003 */  bnel  $v1, $v0, .L7F0BD220
/* 0F1D44 7F0BD214 24A50014 */   addiu $a1, $a1, 0x14
/* 0F1D48 7F0BD218 ACA00004 */  sw    $zero, 4($a1)
/* 0F1D4C 7F0BD21C 24A50014 */  addiu $a1, $a1, 0x14
.L7F0BD220:
/* 0F1D50 7F0BD220 00A6082B */  sltu  $at, $a1, $a2
/* 0F1D54 7F0BD224 5420FFF6 */  bnezl $at, .L7F0BD200
/* 0F1D58 7F0BD228 90B90010 */   lbu   $t9, 0x10($a1)
.L7F0BD22C:
/* 0F1D5C 7F0BD22C 03E00008 */  jr    $ra
/* 0F1D60 7F0BD230 00000000 */   nop   
)
#endif





void sub_GAME_7F0BD234(void) {
  something_mem_bank_a0(5);
}





#ifdef NONMATCHING
void get_index_num_of_named_resource(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_index_num_of_named_resource
/* 0F1D84 7F0BD254 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F1D88 7F0BD258 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F1D8C 7F0BD25C 3C128005 */  lui   $s2, %hi(file_entry_max)
/* 0F1D90 7F0BD260 265282D4 */  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, -0x7d2c
/* 0F1D94 7F0BD264 8E420000 */  lw    $v0, ($s2)
/* 0F1D98 7F0BD268 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1D9C 7F0BD26C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1DA0 7F0BD270 28410002 */  slti  $at, $v0, 2
/* 0F1DA4 7F0BD274 00809825 */  move  $s3, $a0
/* 0F1DA8 7F0BD278 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1DAC 7F0BD27C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1DB0 7F0BD280 14200012 */  bnez  $at, .L7F0BD2CC
/* 0F1DB4 7F0BD284 24110001 */   li    $s1, 1
/* 0F1DB8 7F0BD288 3C108004 */  lui   $s0, %hi(file_resource_table + 0xC)
/* 0F1DBC 7F0BD28C 26106060 */  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, 0x6060
/* 0F1DC0 7F0BD290 8E050004 */  lw    $a1, 4($s0)
.L7F0BD294:
/* 0F1DC4 7F0BD294 50A00008 */  beql  $a1, $zero, .L7F0BD2B8
/* 0F1DC8 7F0BD298 8E420000 */   lw    $v0, ($s2)
/* 0F1DCC 7F0BD29C 0C002A13 */  jal   something_with_strings_0
/* 0F1DD0 7F0BD2A0 02602025 */   move  $a0, $s3
/* 0F1DD4 7F0BD2A4 54400004 */  bnezl $v0, .L7F0BD2B8
/* 0F1DD8 7F0BD2A8 8E420000 */   lw    $v0, ($s2)
/* 0F1DDC 7F0BD2AC 1000002E */  b     .L7F0BD368
/* 0F1DE0 7F0BD2B0 02201025 */   move  $v0, $s1
/* 0F1DE4 7F0BD2B4 8E420000 */  lw    $v0, ($s2)
.L7F0BD2B8:
/* 0F1DE8 7F0BD2B8 26310001 */  addiu $s1, $s1, 1
/* 0F1DEC 7F0BD2BC 2610000C */  addiu $s0, $s0, 0xc
/* 0F1DF0 7F0BD2C0 0222082A */  slt   $at, $s1, $v0
/* 0F1DF4 7F0BD2C4 5420FFF3 */  bnezl $at, .L7F0BD294
/* 0F1DF8 7F0BD2C8 8E050004 */   lw    $a1, 4($s0)
.L7F0BD2CC:
/* 0F1DFC 7F0BD2CC 284102E0 */  slti  $at, $v0, 0x2e0
/* 0F1E00 7F0BD2D0 14200003 */  bnez  $at, .L7F0BD2E0
/* 0F1E04 7F0BD2D4 00408825 */   move  $s1, $v0
/* 0F1E08 7F0BD2D8 10000023 */  b     .L7F0BD368
/* 0F1E0C 7F0BD2DC 00001025 */   move  $v0, $zero
.L7F0BD2E0:
/* 0F1E10 7F0BD2E0 244E0001 */  addiu $t6, $v0, 1
/* 0F1E14 7F0BD2E4 AE4E0000 */  sw    $t6, ($s2)
/* 0F1E18 7F0BD2E8 02602025 */  move  $a0, $s3
/* 0F1E1C 7F0BD2EC 0FC34026 */  jal   check_file_found_on_indy
/* 0F1E20 7F0BD2F0 27A50034 */   addiu $a1, $sp, 0x34
/* 0F1E24 7F0BD2F4 14400003 */  bnez  $v0, .L7F0BD304
/* 0F1E28 7F0BD2F8 00117880 */   sll   $t7, $s1, 2
/* 0F1E2C 7F0BD2FC 1000001A */  b     .L7F0BD368
/* 0F1E30 7F0BD300 00001025 */   move  $v0, $zero
.L7F0BD304:
/* 0F1E34 7F0BD304 01F17823 */  subu  $t7, $t7, $s1
/* 0F1E38 7F0BD308 3C188004 */  lui   $t8, %hi(file_resource_table) 
/* 0F1E3C 7F0BD30C 27186054 */  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, 0x6054
/* 0F1E40 7F0BD310 000F7880 */  sll   $t7, $t7, 2
/* 0F1E44 7F0BD314 0011C880 */  sll   $t9, $s1, 2
/* 0F1E48 7F0BD318 01F88021 */  addu  $s0, $t7, $t8
/* 0F1E4C 7F0BD31C 0331C821 */  addu  $t9, $t9, $s1
/* 0F1E50 7F0BD320 3C088009 */  lui   $t0, %hi(ptr_resource_data) 
/* 0F1E54 7F0BD324 250888B0 */  addiu $t0, %lo(ptr_resource_data) # addiu $t0, $t0, -0x7750
/* 0F1E58 7F0BD328 0019C880 */  sll   $t9, $t9, 2
/* 0F1E5C 7F0BD32C AE110000 */  sw    $s1, ($s0)
/* 0F1E60 7F0BD330 AE130004 */  sw    $s3, 4($s0)
/* 0F1E64 7F0BD334 03281821 */  addu  $v1, $t9, $t0
/* 0F1E68 7F0BD338 A0600011 */  sb    $zero, 0x11($v1)
/* 0F1E6C 7F0BD33C AE000008 */  sw    $zero, 8($s0)
/* 0F1E70 7F0BD340 AC600000 */  sw    $zero, ($v1)
/* 0F1E74 7F0BD344 AC600004 */  sw    $zero, 4($v1)
/* 0F1E78 7F0BD348 8FA90034 */  lw    $t1, 0x34($sp)
/* 0F1E7C 7F0BD34C AC60000C */  sw    $zero, 0xc($v1)
/* 0F1E80 7F0BD350 A0600010 */  sb    $zero, 0x10($v1)
/* 0F1E84 7F0BD354 252A000F */  addiu $t2, $t1, 0xf
/* 0F1E88 7F0BD358 354B000F */  ori   $t3, $t2, 0xf
/* 0F1E8C 7F0BD35C 396C000F */  xori  $t4, $t3, 0xf
/* 0F1E90 7F0BD360 AC6C0008 */  sw    $t4, 8($v1)
/* 0F1E94 7F0BD364 02201025 */  move  $v0, $s1
.L7F0BD368:
/* 0F1E98 7F0BD368 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1E9C 7F0BD36C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1EA0 7F0BD370 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1EA4 7F0BD374 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1EA8 7F0BD378 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1EAC 7F0BD37C 03E00008 */  jr    $ra
/* 0F1EB0 7F0BD380 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





void sub_GAME_7F0BD384(u32 param_1)
{
  return;
}





#ifdef NONMATCHING
void sub_GAME_7F0BD38C(void) {
    s32 temp_s0;
    s32 phi_s0;

    // Node 0
    phi_s0 = 1;
    if (file_entry_max >= 2)
    {
loop_1:
        // Node 1
        sub_GAME_7F0BD384(phi_s0);
        temp_s0 = (phi_s0 + 1);
        phi_s0 = temp_s0;
        if (temp_s0 < file_entry_max)
        {
            goto loop_1;
        }
    }
    // Node 2
    return;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD38C
/* 0F1EBC 7F0BD38C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1EC0 7F0BD390 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1EC4 7F0BD394 3C118005 */  lui   $s1, %hi(file_entry_max)
/* 0F1EC8 7F0BD398 263182D4 */  addiu $s1, %lo(file_entry_max) # addiu $s1, $s1, -0x7d2c
/* 0F1ECC 7F0BD39C 8E2E0000 */  lw    $t6, ($s1)
/* 0F1ED0 7F0BD3A0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1ED4 7F0BD3A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1ED8 7F0BD3A8 29C10002 */  slti  $at, $t6, 2
/* 0F1EDC 7F0BD3AC 14200008 */  bnez  $at, .L7F0BD3D0
/* 0F1EE0 7F0BD3B0 24100001 */   li    $s0, 1
.L7F0BD3B4:
/* 0F1EE4 7F0BD3B4 0FC2F4E1 */  jal   sub_GAME_7F0BD384
/* 0F1EE8 7F0BD3B8 02002025 */   move  $a0, $s0
/* 0F1EEC 7F0BD3BC 8E2F0000 */  lw    $t7, ($s1)
/* 0F1EF0 7F0BD3C0 26100001 */  addiu $s0, $s0, 1
/* 0F1EF4 7F0BD3C4 020F082A */  slt   $at, $s0, $t7
/* 0F1EF8 7F0BD3C8 1420FFFA */  bnez  $at, .L7F0BD3B4
/* 0F1EFC 7F0BD3CC 00000000 */   nop   
.L7F0BD3D0:
/* 0F1F00 7F0BD3D0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1F04 7F0BD3D4 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1F08 7F0BD3D8 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1F0C 7F0BD3DC 03E00008 */  jr    $ra
/* 0F1F10 7F0BD3E0 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD3E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD3E4
/* 0F1F14 7F0BD3E4 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1F18 7F0BD3E8 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F1C 7F0BD3EC 24020001 */  li    $v0, 1
/* 0F1F20 7F0BD3F0 28610002 */  slti  $at, $v1, 2
/* 0F1F24 7F0BD3F4 14200004 */  bnez  $at, .L7F0BD408
/* 0F1F28 7F0BD3F8 24420001 */   addiu $v0, $v0, 1
.L7F0BD3FC:
/* 0F1F2C 7F0BD3FC 0043082A */  slt   $at, $v0, $v1
/* 0F1F30 7F0BD400 5420FFFE */  bnezl $at, .L7F0BD3FC
/* 0F1F34 7F0BD404 24420001 */   addiu $v0, $v0, 1
.L7F0BD408:
/* 0F1F38 7F0BD408 03E00008 */  jr    $ra
/* 0F1F3C 7F0BD40C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void *sub_GAME_7F0BD410(void) {
    u32 temp_v0;
    u32 phi_v0;

    // Node 0
    if (file_entry_max >= 2)
    {
        // Node 1
        phi_v0 = &ptr_res_data_next;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 0x14);
        phi_v0 = temp_v0;
        if (temp_v0 < (u32) ((file_entry_max * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 3
    return &ptr_res_data_next;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD410
/* 0F1F40 7F0BD410 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1F44 7F0BD414 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F48 7F0BD418 3C028009 */  lui   $v0, %hi(ptr_res_data_next)
/* 0F1F4C 7F0BD41C 244288C4 */  addiu $v0, %lo(ptr_res_data_next) # addiu $v0, $v0, -0x773c
/* 0F1F50 7F0BD420 28610002 */  slti  $at, $v1, 2
/* 0F1F54 7F0BD424 1420000A */  bnez  $at, .L7F0BD450
/* 0F1F58 7F0BD428 00037080 */   sll   $t6, $v1, 2
/* 0F1F5C 7F0BD42C 01C37021 */  addu  $t6, $t6, $v1
/* 0F1F60 7F0BD430 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) 
/* 0F1F64 7F0BD434 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1F68 7F0BD438 000E7080 */  sll   $t6, $t6, 2
/* 0F1F6C 7F0BD43C 01CF2021 */  addu  $a0, $t6, $t7
/* 0F1F70 7F0BD440 24420014 */  addiu $v0, $v0, 0x14
.L7F0BD444:
/* 0F1F74 7F0BD444 0044082B */  sltu  $at, $v0, $a0
/* 0F1F78 7F0BD448 5420FFFE */  bnezl $at, .L7F0BD444
/* 0F1F7C 7F0BD44C 24420014 */   addiu $v0, $v0, 0x14
.L7F0BD450:
/* 0F1F80 7F0BD450 03E00008 */  jr    $ra
/* 0F1F84 7F0BD454 00000000 */   nop   
)
#endif


 

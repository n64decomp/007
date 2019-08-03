.section .ob_seg, "a"

.macro obseg_file_rz path name
  .global \name
  \name:
    .incbin "build\/assets\/obseg\/\path\/\name\.rz"
    .balign 16
  end_\name:
.endm

.macro obseg_file_Z path name
  .global \name
  \name:
    .incbin "build\/assets\/obseg\/\path\/\name\.rz"
    .balign 16
  end_\name:
.endm

.global bg_sev_all_p_seg
bg_sev_all_p_seg:
.incbin "build/assets/obseg/bg/bg_sev_all_p.seg"
.balign 16
bg_sev_all_p.seg_end:

.global bg_silo_all_p_seg
bg_silo_all_p_seg:
.incbin "build/assets/obseg/bg/bg_silo_all_p.seg"
bg_silo_all_p.seg_end:

.global bg_stat_all_p_seg
bg_stat_all_p_seg:
.incbin "build/assets/obseg/bg/bg_stat_all_p.seg"
bg_stat_all_p.seg_end:

.global bg_arec_all_p_seg
bg_arec_all_p_seg:
.incbin "build/assets/obseg/bg/bg_arec_all_p.seg"
bg_arec_all_p.seg_end:

.global bg_arch_all_p_seg
bg_arch_all_p_seg:
.incbin "build/assets/obseg/bg/bg_arch_all_p.seg"
bg_arch_all_p.seg_end:

.global bg_tra_all_p_seg
bg_tra_all_p_seg:
.incbin "build/assets/obseg/bg/bg_tra_all_p.seg"
bg_tra_all_p.seg_end:

.global bg_dest_all_p_seg
bg_dest_all_p_seg:
.incbin "build/assets/obseg/bg/bg_dest_all_p.seg"
bg_dest_all_p.seg_end:

.global bg_sevb_all_p_seg
bg_sevb_all_p_seg:
.incbin "build/assets/obseg/bg/bg_sevb_all_p.seg"
bg_sevb_all_p.seg_end:

.global bg_azt_all_p_seg
bg_azt_all_p_seg:
.incbin "build/assets/obseg/bg/bg_azt_all_p.seg"
bg_azt_all_p.seg_end:

.global bg_pete_all_p_seg
bg_pete_all_p_seg:
.incbin "build/assets/obseg/bg/bg_pete_all_p.seg"
bg_pete_all_p.seg_end:

.global bg_depo_all_p_seg
bg_depo_all_p_seg:
.incbin "build/assets/obseg/bg/bg_depo_all_p.seg"
bg_depo_all_p.seg_end:

.global bg_ref_all_p_seg
bg_ref_all_p_seg:
.incbin "build/assets/obseg/bg/bg_ref_all_p.seg"
bg_ref_all_p.seg_end:

.global bg_cryp_all_p_seg
bg_cryp_all_p_seg:
.incbin "build/assets/obseg/bg/bg_cryp_all_p.seg"
bg_cryp_all_p.seg_end:

.global bg_dam_all_p_seg
bg_dam_all_p_seg:
.incbin "build/assets/obseg/bg/bg_dam_all_p.seg"
bg_dam_all_p.seg_end:

.global bg_ark_all_p_seg
bg_ark_all_p_seg:
.incbin "build/assets/obseg/bg/bg_ark_all_p.seg"
bg_ark_all_p.seg_end:

.global bg_run_all_p_seg
bg_run_all_p_seg:
.incbin "build/assets/obseg/bg/bg_run_all_p.seg"
bg_run_all_p.seg_end:

.global bg_sevx_all_p_seg
bg_sevx_all_p_seg:
.incbin "build/assets/obseg/bg/bg_sevx_all_p.seg"
bg_sevx_all_p.seg_end:

.global bg_jun_all_p_seg
bg_jun_all_p_seg:
.incbin "build/assets/obseg/bg/bg_jun_all_p.seg"
bg_jun_all_p.seg_end:

.global bg_dish_all_p_seg
bg_dish_all_p_seg:
.incbin "build/assets/obseg/bg/bg_dish_all_p.seg"
bg_dish_all_p.seg_end:

.global bg_cave_all_p_seg
bg_cave_all_p_seg:
.incbin "build/assets/obseg/bg/bg_cave_all_p.seg"
bg_cave_all_p.seg_end:

.global bg_cat_all_p_seg
bg_cat_all_p_seg:
.incbin "build/assets/obseg/bg/bg_cat_all_p.seg"
bg_cat_all_p.seg_end:

.global bg_crad_all_p_seg
bg_crad_all_p_seg:
.incbin "build/assets/obseg/bg/bg_crad_all_p.seg"
bg_crad_all_p.seg_end:

.global bg_imp_all_p_seg
bg_imp_all_p_seg:
.incbin "build/assets/obseg/bg/bg_imp_all_p.seg"
bg_imp_all_p.seg_end:

.global bg_ash_all_p_seg
bg_ash_all_p_seg:
.incbin "build/assets/obseg/bg/bg_ash_all_p.seg"
bg_ash_all_p.seg_end:

.global bg_sho_all_p_seg
bg_sho_all_p_seg:
.incbin "build/assets/obseg/bg/bg_sho_all_p.seg"
bg_sho_all_p.seg_end:

.global bg_ame_all_p_seg
bg_ame_all_p_seg:
.incbin "build/assets/obseg/bg/bg_ame_all_p.seg"
bg_ame_all_p.seg_end:

.global bg_oat_all_p_seg
bg_oat_all_p_seg:
.incbin "build/assets/obseg/bg/bg_oat_all_p.seg"
bg_oat_all_p.seg_end:

.global bg_rit_all_p_seg
bg_rit_all_p_seg:
.incbin "build/assets/obseg/bg/bg_rit_all_p.seg"
bg_rit_all_p.seg_end:

.global bg_len_all_p_seg
bg_len_all_p_seg:
.incbin "build/assets/obseg/bg/bg_len_all_p.seg"
bg_len_all_p.seg_end:

.global bg_lee_all_p_seg
bg_lee_all_p_seg:
.incbin "build/assets/obseg/bg/bg_lee_all_p.seg"
bg_lee_all_p.seg_end:

.global bg_ear_all_p_seg
bg_ear_all_p_seg:
.incbin "build/assets/obseg/bg/bg_ear_all_p.seg"
bg_ear_all_p.seg_end:

.global bg_lip_all_p_seg
bg_lip_all_p_seg:
.incbin "build/assets/obseg/bg/bg_lip_all_p.seg"
bg_lip_all_p.seg_end:

.global bg_pam_all_p_seg
bg_pam_all_p_seg:
.incbin "build/assets/obseg/bg/bg_pam_all_p.seg"
bg_pam_all_p.seg_end:

.global bg_wax_all_p_seg
bg_wax_all_p_seg:
.incbin "build/assets/obseg/bg/bg_wax_all_p.seg"
bg_wax_all_p.seg_end:

obseg_file_rz chr, CarmourguardZ
obseg_file_rz chr, CbaronsamediZ
obseg_file_rz chr, CbluecamguardZ
obseg_file_rz chr, CbluemanZ
obseg_file_rz chr, CbluewomanZ
obseg_file_rz chr, CboilerbondZ
obseg_file_rz chr, CboilertrevZ
obseg_file_rz chr, CborisZ
obseg_file_rz chr, CcamguardZ
obseg_file_rz chr, CcardimanZ
obseg_file_rz chr, CcheckmanZ
obseg_file_rz chr, CcommguardZ
obseg_file_rz chr, CdjbondZ
obseg_file_rz chr, CfattechwomanZ
obseg_file_rz chr, Cgreatguard2Z
obseg_file_rz chr, CgreatguardZ
obseg_file_rz chr, CgreyguardZ
obseg_file_rz chr, CgreymanZ
obseg_file_rz chr, CheadalanZ
obseg_file_rz chr, CheadbZ
obseg_file_rz chr, CheadbalaclavaZ
obseg_file_rz chr, CheadbikeZ
obseg_file_rz chr, CheadbrosnanZ
obseg_file_rz chr, CheadbrosnanboilerZ
obseg_file_rz chr, CheadbrosnansnowZ
obseg_file_rz chr, CheadbrosnansuitZ
obseg_file_rz chr, CheadbrosnantimberZ
obseg_file_rz chr, CheadchrisZ
obseg_file_rz chr, CheaddaveZ
obseg_file_rz chr, CheaddesZ
obseg_file_rz chr, CheadduncanZ
obseg_file_rz chr, CheaddwayneZ
obseg_file_rz chr, CheadgrahamZ
obseg_file_rz chr, CheadgrantZ
obseg_file_rz chr, CheadjimZ
obseg_file_rz chr, Cheadjoe2Z
obseg_file_rz chr, CheadjoeZ
obseg_file_rz chr, CheadjoelZ
obseg_file_rz chr, CheadkarlZ
obseg_file_rz chr, CheadkenZ
obseg_file_rz chr, CheadleeZ
obseg_file_rz chr, CheadmandyZ
obseg_file_rz chr, CheadmarionZ
obseg_file_rz chr, CheadmarkZ
obseg_file_rz chr, CheadmartinZ
obseg_file_rz chr, CheadmishkinZ
obseg_file_rz chr, CheadneilZ
obseg_file_rz chr, CheadpeteZ
obseg_file_rz chr, CheadrobinZ
obseg_file_rz chr, CheadsallyZ
obseg_file_rz chr, CheadscottZ
obseg_file_rz chr, CheadshaunZ
obseg_file_rz chr, CheadsteveeZ
obseg_file_rz chr, CheadstevehZ
obseg_file_rz chr, CheadvivienZ
obseg_file_rz chr, CjawsZ
obseg_file_rz chr, CjeanwomanZ
obseg_file_rz chr, CmaydayZ
obseg_file_rz chr, CmoonfemaleZ
obseg_file_rz chr, CmoonguardZ
obseg_file_rz chr, CnatalyaZ
obseg_file_rz chr, CnavyguardZ
obseg_file_rz chr, CoddjobZ
obseg_file_rz chr, ColiveguardZ
obseg_file_rz chr, CorumovZ
obseg_file_rz chr, CpilotZ
obseg_file_rz chr, CredmanZ
obseg_file_rz chr, CrusguardZ
obseg_file_rz chr, CsnowbondZ
obseg_file_rz chr, CsnowguardZ
obseg_file_rz chr, CspicebondZ
obseg_file_rz chr, Csuit_lf_handZ
obseg_file_rz chr, CsuitbondZ
obseg_file_rz chr, CtechmanZ
obseg_file_rz chr, CtechwomanZ
obseg_file_rz chr, CtimberbondZ
obseg_file_rz chr, CtrevelyanZ
obseg_file_rz chr, CtrevguardZ
obseg_file_rz chr, CvalentinZ
obseg_file_rz chr, CxeniaZ


obseg_file_rz gun, Gak47Z
obseg_file_rz gun, GaudiotapeZ
obseg_file_rz gun, GautoshotZ
obseg_file_rz gun, GblackboxZ
obseg_file_rz gun, GblueprintsZ
obseg_file_rz gun, GbombcaseZ
obseg_file_rz gun, GbombdefuserZ
obseg_file_rz gun, GbriefcaseZ
obseg_file_rz gun, GbugZ
obseg_file_rz gun, GbugdetectorZ
obseg_file_rz gun, GbungeeZ
obseg_file_rz gun, GcameraZ
obseg_file_rz gun, GcartblueZ
obseg_file_rz gun, GcartridgeZ
obseg_file_rz gun, GcartrifleZ
obseg_file_rz gun, GcartshellZ
obseg_file_rz gun, GcircuitboardZ
obseg_file_rz gun, GclipboardZ
obseg_file_rz gun, GcreditcardZ
obseg_file_rz gun, GdarkglassesZ
obseg_file_rz gun, GdatathiefZ
obseg_file_rz gun, GdattapeZ
obseg_file_rz gun, GdoordecoderZ
obseg_file_rz gun, GdoorexploderZ
obseg_file_rz gun, GdossierredZ
obseg_file_rz gun, GdynamiteZ
obseg_file_rz gun, GexplosivefloppyZ
obseg_file_rz gun, GexplosivepenZ
obseg_file_rz gun, GextinguisherZ
obseg_file_rz gun, GfingergunZ
obseg_file_rz gun, GfistZ
obseg_file_rz gun, GflarepistolZ
obseg_file_rz gun, Gfnp90Z
obseg_file_rz gun, GgaskeyringZ
obseg_file_rz gun, GgoldbarZ
obseg_file_rz gun, GgoldeneyekeyZ
obseg_file_rz gun, GgoldengunZ
obseg_file_rz gun, GgoldwppkZ
obseg_file_rz gun, GgrenadeZ
obseg_file_rz gun, GgrenadelaunchZ
obseg_file_rz gun, GheroinZ
obseg_file_rz gun, GjoypadZ
obseg_file_rz gun, GkeyanalysercaseZ
obseg_file_rz gun, GkeyboltZ
obseg_file_rz gun, GkeycardZ
obseg_file_rz gun, GkeyyaleZ
obseg_file_rz gun, GknifeZ
obseg_file_rz gun, GlaserZ
obseg_file_rz gun, GlectreZ
obseg_file_rz gun, GlockexploderZ
obseg_file_rz gun, Gm16Z
obseg_file_rz gun, GmapZ
obseg_file_rz gun, GmicrocameraZ
obseg_file_rz gun, GmicrocodeZ
obseg_file_rz gun, GmicrofilmZ
obseg_file_rz gun, GmoneyZ
obseg_file_rz gun, Gmp5kZ
obseg_file_rz gun, Gmp5ksilZ
obseg_file_rz gun, GpitongunZ
obseg_file_rz gun, GplansZ
obseg_file_rz gun, GplastiqueZ
obseg_file_rz gun, GpolarizedglassesZ
obseg_file_rz gun, GproximitymineZ
obseg_file_rz gun, GremotemineZ
obseg_file_rz gun, GrocketlaunchZ
obseg_file_rz gun, GrugerZ
obseg_file_rz gun, GsafecrackercaseZ
obseg_file_rz gun, GshotgunZ
obseg_file_rz gun, GsilverwppkZ
obseg_file_rz gun, GskorpionZ
obseg_file_rz gun, GsniperrifleZ
obseg_file_rz gun, GspectreZ
obseg_file_rz gun, GspooltapeZ
obseg_file_rz gun, GspyfileZ
obseg_file_rz gun, GstafflistZ
obseg_file_rz gun, GtaserZ
obseg_file_rz gun, GthrowknifeZ
obseg_file_rz gun, GtimedmineZ
obseg_file_rz gun, GtriggerZ
obseg_file_rz gun, Gtt33Z
obseg_file_rz gun, GuziZ
obseg_file_rz gun, GvideotapeZ
obseg_file_rz gun, GwatchcommunicatorZ
obseg_file_rz gun, GwatchgeigercounterZ
obseg_file_rz gun, GwatchidentifierZ
obseg_file_rz gun, GwatchlaserZ
obseg_file_rz gun, GwatchmagnetattractZ
obseg_file_rz gun, GwatchmagnetrepelZ
obseg_file_rz gun, GweaponcaseZ
obseg_file_rz gun, GwppkZ
obseg_file_rz gun, GwppksilZ
obseg_file_rz gun, GwristdartZ


obseg_file_rz prop, PICBMZ
obseg_file_rz prop, PICBM_noseZ
obseg_file_rz prop, Pak47magZ
obseg_file_rz prop, Palarm1Z
obseg_file_rz prop, Palarm2Z
obseg_file_rz prop, Pammo_crate1Z
obseg_file_rz prop, Pammo_crate2Z
obseg_file_rz prop, Pammo_crate3Z
obseg_file_rz prop, Pammo_crate4Z
obseg_file_rz prop, Pammo_crate5Z
obseg_file_rz prop, PapcZ
obseg_file_rz prop, Parchsecdoor1Z
obseg_file_rz prop, Parchsecdoor2Z
obseg_file_rz prop, ParticZ
obseg_file_rz prop, PartictrailerZ
obseg_file_rz prop, PbarricadeZ
obseg_file_rz prop, Pbin1Z
obseg_file_rz prop, Pblotter1Z
obseg_file_rz prop, PbodyarmourZ
obseg_file_rz prop, PbodyarmourvestZ
obseg_file_rz prop, PbollardZ
obseg_file_rz prop, PbombZ
obseg_file_rz prop, Pbook1Z
obseg_file_rz prop, Pbookshelf1Z
obseg_file_rz prop, Pborg_crateZ
obseg_file_rz prop, PboxcartridgesZ
obseg_file_rz prop, Pboxes2x4Z
obseg_file_rz prop, Pboxes3x4Z
obseg_file_rz prop, Pboxes4x4Z
obseg_file_rz prop, PbrakeunitZ
obseg_file_rz prop, Pbridge_console1aZ
obseg_file_rz prop, Pbridge_console1bZ
obseg_file_rz prop, Pbridge_console2aZ
obseg_file_rz prop, Pbridge_console2bZ
obseg_file_rz prop, Pbridge_console3aZ
obseg_file_rz prop, Pbridge_console3bZ
obseg_file_rz prop, PcarbmwZ
obseg_file_rz prop, Pcard_box1Z
obseg_file_rz prop, Pcard_box2Z
obseg_file_rz prop, Pcard_box3Z
obseg_file_rz prop, Pcard_box4Z
obseg_file_rz prop, Pcard_box5Z
obseg_file_rz prop, Pcard_box6Z
obseg_file_rz prop, PcarescortZ
obseg_file_rz prop, PcargolfZ
obseg_file_rz prop, PcarweirdZ
obseg_file_rz prop, PcarzilZ
obseg_file_rz prop, PcctvZ
obseg_file_rz prop, PchraudiotapeZ
obseg_file_rz prop, PchrautoshotZ
obseg_file_rz prop, PchrblackboxZ
obseg_file_rz prop, PchrblueprintsZ
obseg_file_rz prop, PchrbombcaseZ
obseg_file_rz prop, PchrbombdefuserZ
obseg_file_rz prop, PchrbriefcaseZ
obseg_file_rz prop, PchrbugZ
obseg_file_rz prop, PchrbugdetectorZ
obseg_file_rz prop, PchrbungeeZ
obseg_file_rz prop, PchrcameraZ
obseg_file_rz prop, PchrcircuitboardZ
obseg_file_rz prop, PchrclipboardZ
obseg_file_rz prop, PchrcreditcardZ
obseg_file_rz prop, PchrdarkglassesZ
obseg_file_rz prop, PchrdatathiefZ
obseg_file_rz prop, PchrdattapeZ
obseg_file_rz prop, PchrdoordecoderZ
obseg_file_rz prop, PchrdoorexploderZ
obseg_file_rz prop, PchrdossierredZ
obseg_file_rz prop, PchrdynamiteZ
obseg_file_rz prop, PchrexplosivepenZ
obseg_file_rz prop, PchrextinguisherZ
obseg_file_rz prop, PchrfingergunZ
obseg_file_rz prop, PchrflarepistolZ
obseg_file_rz prop, Pchrfnp90Z
obseg_file_rz prop, PchrgaskeyringZ
obseg_file_rz prop, PchrgoldbarZ
obseg_file_rz prop, PchrgoldenZ
obseg_file_rz prop, PchrgoldeneyekeyZ
obseg_file_rz prop, PchrgoldwppkZ
obseg_file_rz prop, PchrgrenadeZ
obseg_file_rz prop, PchrgrenadelaunchZ
obseg_file_rz prop, PchrgrenaderoundZ
obseg_file_rz prop, PchrheroinZ
obseg_file_rz prop, PchrkalashZ
obseg_file_rz prop, PchrkeyanalysercaseZ
obseg_file_rz prop, PchrkeyboltZ
obseg_file_rz prop, PchrkeyyaleZ
obseg_file_rz prop, PchrknifeZ
obseg_file_rz prop, PchrlaserZ
obseg_file_rz prop, PchrlectreZ
obseg_file_rz prop, PchrlockexploderZ
obseg_file_rz prop, Pchrm16Z
obseg_file_rz prop, PchrmapZ
obseg_file_rz prop, PchrmicrocameraZ
obseg_file_rz prop, PchrmicrocodeZ
obseg_file_rz prop, PchrmicrofilmZ
obseg_file_rz prop, PchrmoneyZ
obseg_file_rz prop, Pchrmp5kZ
obseg_file_rz prop, Pchrmp5ksilZ
obseg_file_rz prop, PchrpitongunZ
obseg_file_rz prop, PchrplansZ
obseg_file_rz prop, PchrplastiqueZ
obseg_file_rz prop, PchrpolarizedglassesZ
obseg_file_rz prop, PchrproximitymineZ
obseg_file_rz prop, PchrremotemineZ
obseg_file_rz prop, PchrrocketZ
obseg_file_rz prop, PchrrocketlaunchZ
obseg_file_rz prop, PchrrugerZ
obseg_file_rz prop, PchrsafecrackercaseZ
obseg_file_rz prop, PchrshotgunZ
obseg_file_rz prop, PchrsilverwppkZ
obseg_file_rz prop, PchrskorpionZ
obseg_file_rz prop, PchrsniperrifleZ
obseg_file_rz prop, PchrspectreZ
obseg_file_rz prop, PchrspooltapeZ
obseg_file_rz prop, PchrspyfileZ
obseg_file_rz prop, PchrstafflistZ
obseg_file_rz prop, PchrtesttubeZ
obseg_file_rz prop, PchrthrowknifeZ
obseg_file_rz prop, PchrtimedmineZ
obseg_file_rz prop, Pchrtt33Z
obseg_file_rz prop, PchruziZ
obseg_file_rz prop, PchrvideotapeZ
obseg_file_rz prop, PchrweaponcaseZ
obseg_file_rz prop, PchrwppkZ
obseg_file_rz prop, PchrwppksilZ
obseg_file_rz prop, PchrwristdartZ
obseg_file_rz prop, Pconsole1Z
obseg_file_rz prop, Pconsole2Z
obseg_file_rz prop, Pconsole3Z
obseg_file_rz prop, Pconsole_sev2aZ
obseg_file_rz prop, Pconsole_sev2bZ
obseg_file_rz prop, Pconsole_sev2cZ
obseg_file_rz prop, Pconsole_sev2dZ
obseg_file_rz prop, Pconsole_sev_GEaZ
obseg_file_rz prop, Pconsole_sev_GEbZ
obseg_file_rz prop, Pconsole_sevaZ
obseg_file_rz prop, Pconsole_sevbZ
obseg_file_rz prop, Pconsole_sevcZ
obseg_file_rz prop, Pconsole_sevdZ
obseg_file_rz prop, Pcryptdoor1aZ
obseg_file_rz prop, Pcryptdoor1bZ
obseg_file_rz prop, Pcryptdoor2aZ
obseg_file_rz prop, Pcryptdoor2bZ
obseg_file_rz prop, Pcryptdoor3Z
obseg_file_rz prop, Pcryptdoor4Z
obseg_file_rz prop, PdamchaindoorZ
obseg_file_rz prop, PdamgatedoorZ
obseg_file_rz prop, PdamtundoorZ
obseg_file_rz prop, Pdepot_door_steelZ
obseg_file_rz prop, Pdepot_gate_entryZ
obseg_file_rz prop, Pdesk1Z
obseg_file_rz prop, Pdesk2Z
obseg_file_rz prop, Pdesk_arecibo1Z
obseg_file_rz prop, Pdesk_lamp2Z
obseg_file_rz prop, Pdest_engineZ
obseg_file_rz prop, Pdest_exocetZ
obseg_file_rz prop, Pdest_gunZ
obseg_file_rz prop, Pdest_harpoonZ
obseg_file_rz prop, Pdest_seawolfZ
obseg_file_rz prop, Pdisc_readerZ
obseg_file_rz prop, Pdisk_drive1Z
obseg_file_rz prop, Pdoor_azt_chairZ
obseg_file_rz prop, Pdoor_azt_deskZ
obseg_file_rz prop, Pdoor_azt_desk_topZ
obseg_file_rz prop, Pdoor_aztecZ
obseg_file_rz prop, Pdoor_dest1Z
obseg_file_rz prop, Pdoor_dest2Z
obseg_file_rz prop, Pdoor_eyelidZ
obseg_file_rz prop, Pdoor_irisZ
obseg_file_rz prop, Pdoor_mfZ
obseg_file_rz prop, Pdoor_roller1Z
obseg_file_rz prop, Pdoor_roller2Z
obseg_file_rz prop, Pdoor_roller3Z
obseg_file_rz prop, Pdoor_roller4Z
obseg_file_rz prop, Pdoor_rollertrainZ
obseg_file_rz prop, Pdoor_st_arec1Z
obseg_file_rz prop, Pdoor_st_arec2Z
obseg_file_rz prop, Pdoor_winZ
obseg_file_rz prop, PdoorconsoleZ
obseg_file_rz prop, PdoorpanelZ
obseg_file_rz prop, Pdoorprison1Z
obseg_file_rz prop, PdoorstatgateZ
obseg_file_rz prop, PexplosionbitZ
obseg_file_rz prop, Pfiling_cabinet1Z
obseg_file_rz prop, PflagZ
obseg_file_rz prop, PfloppyZ
obseg_file_rz prop, Pfnp90magZ
obseg_file_rz prop, Pgas_plant_met1_do1Z
obseg_file_rz prop, Pgas_plant_sw2_do1Z
obseg_file_rz prop, Pgas_plant_sw3_do1Z
obseg_file_rz prop, Pgas_plant_sw4_do1Z
obseg_file_rz prop, Pgas_plant_sw_do1Z
obseg_file_rz prop, Pgas_plant_wc_cub1Z
obseg_file_rz prop, PgasbarrelZ
obseg_file_rz prop, PgasbarrelsZ
obseg_file_rz prop, Pgasplant_clear_doorZ
obseg_file_rz prop, PgastankZ
obseg_file_rz prop, Pglassware1Z
obseg_file_rz prop, Pglassware2Z
obseg_file_rz prop, Pglassware3Z
obseg_file_rz prop, Pglassware4Z
obseg_file_rz prop, PgoldeneyelogoZ
obseg_file_rz prop, PgoldenshellsZ
obseg_file_rz prop, PgroundgunZ
obseg_file_rz prop, Pgun_runway1Z
obseg_file_rz prop, PhatberetZ
obseg_file_rz prop, PhatberetblueZ
obseg_file_rz prop, PhatberetredZ
obseg_file_rz prop, PhatchboltZ
obseg_file_rz prop, PhatchdoorZ
obseg_file_rz prop, PhatchsevxZ
obseg_file_rz prop, PhatfurryZ
obseg_file_rz prop, PhatfurryblackZ
obseg_file_rz prop, PhatfurrybrownZ
obseg_file_rz prop, PhathelmetZ
obseg_file_rz prop, PhathelmetgreyZ
obseg_file_rz prop, PhatmoonZ
obseg_file_rz prop, PhatpeakedZ
obseg_file_rz prop, PhattbirdZ
obseg_file_rz prop, PhattbirdbrownZ
obseg_file_rz prop, PhelicopterZ
obseg_file_rz prop, PhindZ
obseg_file_rz prop, PjeepZ
obseg_file_rz prop, Pjerry_can1Z
obseg_file_rz prop, Pjungle3_treeZ
obseg_file_rz prop, Pjungle5_treeZ
obseg_file_rz prop, Pkey_holderZ
obseg_file_rz prop, Pkeyboard1Z
obseg_file_rz prop, Pkit_units1Z
obseg_file_rz prop, PlabbenchZ
obseg_file_rz prop, PlandmineZ
obseg_file_rz prop, PlegalpageZ
obseg_file_rz prop, Pletter_tray1Z
obseg_file_rz prop, Plocker3Z
obseg_file_rz prop, Plocker4Z
obseg_file_rz prop, Pm16magZ
obseg_file_rz prop, PmagnumshellsZ
obseg_file_rz prop, Pmainframe1Z
obseg_file_rz prop, Pmainframe2Z
obseg_file_rz prop, Pmetal_chair1Z
obseg_file_rz prop, Pmetal_crate1Z
obseg_file_rz prop, Pmetal_crate2Z
obseg_file_rz prop, Pmetal_crate3Z
obseg_file_rz prop, Pmetal_crate4Z
obseg_file_rz prop, PmilcopterZ
obseg_file_rz prop, PmiltruckZ
obseg_file_rz prop, Pmissile_rack2Z
obseg_file_rz prop, Pmissile_rackZ
obseg_file_rz prop, PmodemboxZ
obseg_file_rz prop, PmotorbikeZ
obseg_file_rz prop, Pmp5kmagZ
obseg_file_rz prop, PnintendologoZ
obseg_file_rz prop, Poil_drum1Z
obseg_file_rz prop, Poil_drum2Z
obseg_file_rz prop, Poil_drum3Z
obseg_file_rz prop, Poil_drum5Z
obseg_file_rz prop, Poil_drum6Z
obseg_file_rz prop, Poil_drum7Z
obseg_file_rz prop, PpadlockZ
obseg_file_rz prop, PpalmZ
obseg_file_rz prop, PpalmtreeZ
obseg_file_rz prop, Pphone1Z
obseg_file_rz prop, PplaneZ
obseg_file_rz prop, Pplant11Z
obseg_file_rz prop, Pplant1Z
obseg_file_rz prop, Pplant2Z
obseg_file_rz prop, Pplant2bZ
obseg_file_rz prop, Pplant3Z
obseg_file_rz prop, Pradio_unit1Z
obseg_file_rz prop, Pradio_unit2Z
obseg_file_rz prop, Pradio_unit3Z
obseg_file_rz prop, Pradio_unit4Z
obseg_file_rz prop, ProofgunZ
obseg_file_rz prop, PsafeZ
obseg_file_rz prop, PsafedoorZ
obseg_file_rz prop, Psat1_reflectZ
obseg_file_rz prop, PsatboxZ
obseg_file_rz prop, PsatdishZ
obseg_file_rz prop, Psec_panelZ
obseg_file_rz prop, Psev_door3Z
obseg_file_rz prop, Psev_door3_windZ
obseg_file_rz prop, Psev_door4_windZ
obseg_file_rz prop, Psev_doorZ
obseg_file_rz prop, Psev_door_v1Z
obseg_file_rz prop, Psev_trislideZ
obseg_file_rz prop, PsevdishZ
obseg_file_rz prop, PsevdoormetslideZ
obseg_file_rz prop, PsevdoornowindZ
obseg_file_rz prop, PsevdoorwindZ
obseg_file_rz prop, PsevdoorwoodZ
obseg_file_rz prop, PshuttleZ
obseg_file_rz prop, Pshuttle_door_lZ
obseg_file_rz prop, Pshuttle_door_rZ
obseg_file_rz prop, PsilencerZ
obseg_file_rz prop, Psilo_lift_doorZ
obseg_file_rz prop, PsilotopdoorZ
obseg_file_rz prop, PskorpionmagZ
obseg_file_rz prop, PspectremagZ
obseg_file_rz prop, PspeedboatZ
obseg_file_rz prop, Pst_pete_room_1iZ
obseg_file_rz prop, Pst_pete_room_2iZ
obseg_file_rz prop, Pst_pete_room_3tZ
obseg_file_rz prop, Pst_pete_room_5cZ
obseg_file_rz prop, Pst_pete_room_6cZ
obseg_file_rz prop, Psteel_door1Z
obseg_file_rz prop, Psteel_door2Z
obseg_file_rz prop, Psteel_door2bZ
obseg_file_rz prop, Psteel_door3Z
obseg_file_rz prop, Pstool1Z
obseg_file_rz prop, Pswipe_card2Z
obseg_file_rz prop, Pswivel_chair1Z
obseg_file_rz prop, PtankZ
obseg_file_rz prop, PtigerZ
obseg_file_rz prop, Ptorpedo_rackZ
obseg_file_rz prop, Ptrain_door2Z
obseg_file_rz prop, Ptrain_door3Z
obseg_file_rz prop, Ptrain_doorZ
obseg_file_rz prop, PtrainextdoorZ
obseg_file_rz prop, Ptt33magZ
obseg_file_rz prop, Ptuning_console1Z
obseg_file_rz prop, Ptv1Z
obseg_file_rz prop, Ptv4screenZ
obseg_file_rz prop, Ptv_holderZ
obseg_file_rz prop, PtvscreenZ
obseg_file_rz prop, PuzimagZ
obseg_file_rz prop, PvertdoorZ
obseg_file_rz prop, PwalletbondZ
obseg_file_rz prop, PwindowZ
obseg_file_rz prop, Pwindow_cor11Z
obseg_file_rz prop, Pwindow_lib_lg1Z
obseg_file_rz prop, Pwindow_lib_sm1Z
obseg_file_rz prop, Pwood_lg_crate1Z
obseg_file_rz prop, Pwood_lg_crate2Z
obseg_file_rz prop, Pwood_md_crate3Z
obseg_file_rz prop, Pwood_sm_crate4Z
obseg_file_rz prop, Pwood_sm_crate5Z
obseg_file_rz prop, Pwood_sm_crate6Z
obseg_file_rz prop, Pwooden_table1Z
obseg_file_rz prop, PwppkmagZ


obseg_file_Z stan, Tbg_ame_all_p_stanZ
obseg_file_Z stan, Tbg_arch_all_p_stanZ
obseg_file_Z stan, Tbg_arec_all_p_stanZ
obseg_file_Z stan, Tbg_ark_all_p_stanZ
obseg_file_Z stan, Tbg_ash_all_p_stanZ
obseg_file_Z stan, Tbg_azt_all_p_stanZ
obseg_file_Z stan, Tbg_cat_all_p_stanZ
obseg_file_Z stan, Tbg_cave_all_p_stanZ
obseg_file_Z stan, Tbg_crad_all_p_stanZ
obseg_file_Z stan, Tbg_cryp_all_p_stanZ
obseg_file_Z stan, Tbg_dam_all_p_stanZ
obseg_file_Z stan, Tbg_depo_all_p_stanZ
obseg_file_Z stan, Tbg_dest_all_p_stanZ
obseg_file_Z stan, Tbg_dish_all_p_stanZ
obseg_file_Z stan, Tbg_imp_all_p_stanZ
obseg_file_Z stan, Tbg_jun_all_p_stanZ
obseg_file_Z stan, Tbg_len_all_p_stanZ
obseg_file_Z stan, Tbg_oat_all_p_stanZ
obseg_file_Z stan, Tbg_pete_all_p_stanZ
obseg_file_Z stan, Tbg_ref_all_p_stanZ
obseg_file_Z stan, Tbg_run_all_p_stanZ
obseg_file_Z stan, Tbg_sev_all_p_stanZ
obseg_file_Z stan, Tbg_sevb_all_p_stanZ
obseg_file_Z stan, Tbg_sevx_all_p_stanZ
obseg_file_Z stan, Tbg_silo_all_p_stanZ
obseg_file_Z stan, Tbg_stat_all_p_stanZ
obseg_file_Z stan, Tbg_tra_all_p_stanZ


obseg_file_rz brief, UbriefarchZ
obseg_file_rz brief, UbriefarkZ
obseg_file_rz brief, UbriefaztZ
obseg_file_rz brief, UbriefcaveZ
obseg_file_rz brief, UbriefcontrolZ
obseg_file_rz brief, UbriefcradZ
obseg_file_rz brief, UbriefcrypZ
obseg_file_rz brief, UbriefdamZ
obseg_file_rz brief, UbriefdepoZ
obseg_file_rz brief, UbriefdestZ
obseg_file_rz brief, UbriefjunZ
obseg_file_rz brief, UbriefpeteZ
obseg_file_rz brief, UbriefrunZ
obseg_file_rz brief, UbriefsevbZ
obseg_file_rz brief, UbriefsevbunkerZ
obseg_file_rz brief, UbriefsevxZ
obseg_file_rz brief, UbriefsevxbZ
obseg_file_rz brief, UbriefsiloZ
obseg_file_rz brief, UbriefstatueZ
obseg_file_rz brief, UbrieftraZ


obseg_file_Z setup, Ump_setupameZ
obseg_file_Z setup, Ump_setuparchZ
obseg_file_Z setup, Ump_setuparkZ
obseg_file_Z setup, Ump_setupashZ
obseg_file_Z setup, Ump_setupcaveZ
obseg_file_Z setup, Ump_setupcradZ
obseg_file_Z setup, Ump_setupcrypZ
obseg_file_Z setup, Ump_setupdishZ
obseg_file_Z setup, Ump_setupimpZ
obseg_file_Z setup, Ump_setupoatZ
obseg_file_Z setup, Ump_setuprefZ
obseg_file_Z setup, Ump_setupsevbZ
obseg_file_Z setup, Ump_setupstatueZ
obseg_file_Z setup, UsetuparchZ
obseg_file_Z setup, UsetuparkZ
obseg_file_Z setup, UsetupaztZ
obseg_file_Z setup, UsetupcaveZ
obseg_file_Z setup, UsetupcontrolZ
obseg_file_Z setup, UsetupcradZ
obseg_file_Z setup, UsetupcrypZ
obseg_file_Z setup, UsetupdamZ
obseg_file_Z setup, UsetupdepoZ
obseg_file_Z setup, UsetupdestZ
obseg_file_Z setup, UsetupjunZ
obseg_file_Z setup, UsetuplenZ
obseg_file_Z setup, UsetuppeteZ
obseg_file_Z setup, UsetuprunZ
obseg_file_Z setup, UsetupsevbZ
obseg_file_Z setup, UsetupsevbunkerZ
obseg_file_Z setup, UsetupsevxZ
obseg_file_Z setup, UsetupsevxbZ
obseg_file_Z setup, UsetupsiloZ
obseg_file_Z setup, UsetupstatueZ
obseg_file_Z setup, UsetuptraZ


obseg_file_rz text, LameE
obseg_file_rz text, LameJ
obseg_file_rz text, LarchE
obseg_file_rz text, LarchJ
obseg_file_rz text, LarecE
obseg_file_rz text, LarecJ
obseg_file_rz text, LarkE
obseg_file_rz text, LarkJ
obseg_file_rz text, LashE
obseg_file_rz text, LashJ
obseg_file_rz text, LaztE
obseg_file_rz text, LaztJ
obseg_file_rz text, LcatE
obseg_file_rz text, LcatJ
obseg_file_rz text, LcaveE
obseg_file_rz text, LcaveJ
obseg_file_rz text, LcradE
obseg_file_rz text, LcradJ
obseg_file_rz text, LcrypE
obseg_file_rz text, LcrypJ
obseg_file_rz text, LdamE
obseg_file_rz text, LdamJ
obseg_file_rz text, LdepoE
obseg_file_rz text, LdepoJ
obseg_file_rz text, LdestE
obseg_file_rz text, LdestJ
obseg_file_rz text, LdishE
obseg_file_rz text, LdishJ
obseg_file_rz text, LearE
obseg_file_rz text, LearJ
obseg_file_rz text, LeldE
obseg_file_rz text, LeldJ
obseg_file_rz text, LgunE
obseg_file_rz text, LgunJ
obseg_file_rz text, LimpE
obseg_file_rz text, LimpJ
obseg_file_rz text, LjunE
obseg_file_rz text, LjunJ
obseg_file_rz text, LleeE
obseg_file_rz text, LleeJ
obseg_file_rz text, LlenE
obseg_file_rz text, LlenJ
obseg_file_rz text, LlipE
obseg_file_rz text, LlipJ
obseg_file_rz text, LlueE
obseg_file_rz text, LlueJ
obseg_file_rz text, LmiscE
obseg_file_rz text, LmiscJ
obseg_file_rz text, LmpmenuE
obseg_file_rz text, LmpmenuJ
obseg_file_rz text, LmpweaponsE
obseg_file_rz text, LmpweaponsJ
obseg_file_rz text, LoatE
obseg_file_rz text, LoatJ
obseg_file_rz text, LoptionsE
obseg_file_rz text, LoptionsJ
obseg_file_rz text, LpamE
obseg_file_rz text, LpamJ
obseg_file_rz text, LpeteE
obseg_file_rz text, LpeteJ
obseg_file_rz text, LpropobjE
obseg_file_rz text, LpropobjJ
obseg_file_rz text, LrefE
obseg_file_rz text, LrefJ
obseg_file_rz text, LritE
obseg_file_rz text, LritJ
obseg_file_rz text, LrunE
obseg_file_rz text, LrunJ
obseg_file_rz text, LsevE
obseg_file_rz text, LsevJ
obseg_file_rz text, LsevbE
obseg_file_rz text, LsevbJ
obseg_file_rz text, LsevxE
obseg_file_rz text, LsevxJ
obseg_file_rz text, LsevxbE
obseg_file_rz text, LsevxbJ
obseg_file_rz text, LshoE
obseg_file_rz text, LshoJ
obseg_file_rz text, LsiloE
obseg_file_rz text, LsiloJ
obseg_file_rz text, LstatE
obseg_file_rz text, LstatJ
obseg_file_rz text, LtitleE
obseg_file_rz text, LtitleJ
obseg_file_rz text, LtraE
obseg_file_rz text, LtraJ
obseg_file_rz text, LwaxE
obseg_file_rz text, LwaxJ

.global ob__ob_end_seg
ob__ob_end_seg:
.incbin "assets/obseg/ob__ob_end.seg"
ob__ob_end.seg_end:

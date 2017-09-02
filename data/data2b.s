@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2


gUnknown_082FECFC:: @ 82FECFC
	.incbin "baserom.gba", 0x2fecfc, 0x40

gUnknown_082FED3C:: @ 82FED3C
	.incbin "baserom.gba", 0x2fed3c, 0x1b4

gUnknown_082FEEF0:: @ 82FEEF0
	.incbin "baserom.gba", 0x2feef0, 0x128

gUnknown_082FF018:: @ 82FF018
	.incbin "baserom.gba", 0x2ff018, 0x2

gUnknown_082FF01A:: @ 82FF01A
	.incbin "baserom.gba", 0x2ff01a, 0xe

gUnknown_082FF028:: @ 82FF028
	.incbin "baserom.gba", 0x2ff028, 0x10

gUnknown_082FF038:: @ 82FF038
	.incbin "baserom.gba", 0x2ff038, 0x10

gUnknown_082FF048:: @ 82FF048
	.incbin "baserom.gba", 0x2ff048, 0x28

gUnknown_082FF070:: @ 82FF070
	.incbin "baserom.gba", 0x2ff070, 0x10

gUnknown_082FF080:: @ 82FF080
	.incbin "baserom.gba", 0x2ff080, 0x8

gUnknown_082FF088:: @ 82FF088
	.incbin "baserom.gba", 0x2ff088, 0x18

gUnknown_082FF0A0:: @ 82FF0A0
	.incbin "baserom.gba", 0x2ff0a0, 0x20

gUnknown_082FF0C0:: @ 82FF0C0
	.incbin "baserom.gba", 0x2ff0c0, 0x20

gUnknown_082FF0E0:: @ 82FF0E0
	.incbin "baserom.gba", 0x2ff0e0, 0x3

gUnknown_082FF0E3:: @ 82FF0E3
	.incbin "baserom.gba", 0x2ff0e3, 0x5

gUnknown_082FF0E8:: @ 82FF0E8
	.incbin "baserom.gba", 0x2ff0e8, 0x8

gUnknown_082FF0F0:: @ 82FF0F0
	.incbin "baserom.gba", 0x2ff0f0, 0x4

gUnknown_082FF0F4:: @ 82FF0F4
	.incbin "baserom.gba", 0x2ff0f4, 0x20

gUnknown_082FF114:: @ 82FF114
	.incbin "baserom.gba", 0x2ff114, 0x4

gUnknown_082FF118:: @ 82FF118
	.incbin "baserom.gba", 0x2ff118, 0x10

gUnknown_082FF128:: @ 82FF128
	.incbin "baserom.gba", 0x2ff128, 0x50

gUnknown_082FF178:: @ 82FF178
	.incbin "baserom.gba", 0x2ff178, 0x50

gUnknown_082FF1C8:: @ 82FF1C8
	.incbin "baserom.gba", 0x2ff1c8, 0x450

gUnknown_082FF618:: @ 82FF618
	.incbin "baserom.gba", 0x2ff618, 0x7c

gUnknown_082FF694:: @ 82FF694
	.incbin "baserom.gba", 0x2ff694, 0x2c

gUnknown_082FF6C0:: @ 82FF6C0
	.incbin "baserom.gba", 0x2ff6c0, 0x4c

gUnknown_082FF70C:: @ 82FF70C
	.incbin "baserom.gba", 0x2ff70c, 0x162c

gUnknown_08300D38:: @ 8300D38
	.incbin "baserom.gba", 0x300d38, 0x6e0

@ 8301418
	.include "data/graphics/pokemon/mon_still_front_pic_table.inc"

gUnknown_083021D8:: @ 83021D8
	.incbin "baserom.gba", 0x3021d8, 0x6e0

@ 83028B8
	.include "data/graphics/pokemon/mon_back_pic_table.inc"

@ 8303678
	.include "data/graphics/pokemon/mon_palette_table.inc"

@ 8304438
	.include "data/graphics/pokemon/mon_shiny_palette_table.inc"

@ 83051F8
	.incbin "baserom.gba", 0x3051f8, 0x174

gUnknown_0830536C:: @ 830536C
	.incbin "baserom.gba", 0x30536c, 0x174

gUnknown_083054E0:: @ 83054E0
	.incbin "baserom.gba", 0x3054e0, 0x174

@ 8305654
	.include "data/graphics/trainers/trainer_front_pic_table.inc"

@ 830593C
	.include "data/graphics/trainers/trainer_front_pic_palette_table.inc"

@ 8305C24
	.incbin "baserom.gba", 0x305c24, 0xe8

gUnknown_08305D0C:: @ 8305D0C
	.incbin "baserom.gba", 0x305d0c, 0x20

gUnknown_08305D2C:: @ 8305D2C
	.incbin "baserom.gba", 0x305d2c, 0x20

@ 8305D4C
	.include "data/graphics/trainers/trainer_back_pic_table.inc"

@ 8305D8C
	.include "data/graphics/trainers/trainer_back_pic_palette_table.inc"

gUnknown_08305DCC:: @ 8305DCC
	.incbin "baserom.gba", 0x305dcc, 0x3ce0

gUnknown_08309AAC:: @ 8309AAC
	.incbin "baserom.gba", 0x309aac, 0x6e0

@ 830A18C
	.include "data/graphics/pokemon/mon_front_pic_table.inc"

@ 830AF4C
	.incbin "baserom.gba", 0x30af4c, 0x6e0

@ 830B62C
	.include "data/trainer_parties.inc"

@ 830FCD4
	.include "data/text/trainer_class_names.inc"

@ 8310030
	.include "data/trainers.inc"

@ 83185C8
	.include "data/text/species_names.inc"

@ 831977C
	.include "data/text/move_names.inc"

	.incbin "baserom.gba", 0x31a983, 0x4d

gUnknown_0831A9D0:: @ 831A9D0
	.incbin "baserom.gba", 0x31a9d0, 0x18

gUnknown_0831A9E8:: @ 831A9E8
	.incbin "baserom.gba", 0x31a9e8, 0x18

gUnknown_0831AA00:: @ 831AA00
	.incbin "baserom.gba", 0x31aa00, 0x8

gUnknown_0831AA08:: @ 831AA08
	.incbin "baserom.gba", 0x31aa08, 0x198

gUnknown_0831ABA0:: @ 831ABA0
	.incbin "baserom.gba", 0x31aba0, 0x8

gUnknown_0831ABA8:: @ 831ABA8
	.incbin "baserom.gba", 0x31aba8, 0xc8

gUnknown_0831AC70:: @ 831AC70
	.incbin "baserom.gba", 0x31ac70, 0x18

gUnknown_0831AC88:: @ 831AC88
	.incbin "baserom.gba", 0x31ac88, 0x18

gUnknown_0831ACA0:: @ 831ACA0
	.incbin "baserom.gba", 0x31aca0, 0x40

gUnknown_0831ACE0:: @ 831ACE0
	.incbin "baserom.gba", 0x31ace0, 0x8

gUnknown_0831ACE8:: @ 831ACE8
	.incbin "baserom.gba", 0x31ace8, 0x150

@ 831AE38
	.include "data/text/type_names.inc"

	.align 2
gUnknown_0831AEB8:: @ 831AEB8
	.incbin "baserom.gba", 0x31aeb8, 0xe0

@ 831AF98
	.include "data/text/ability_descriptions.inc"

@ 831B6DB
	.include "data/text/ability_names.inc"

@ 831BAD4
	.include "data/text/ability_description_pointers.inc"

gUnknown_0831BC0C:: @ 831BC0C
	.incbin "baserom.gba", 0x31bc0c, 0x38

gUnknown_0831BC44:: @ 831BC44
	.incbin "baserom.gba", 0x31bc44, 0x2c

gUnknown_0831BC70:: @ 831BC70
	.incbin "baserom.gba", 0x31bc70, 0x8

gUnknown_0831BC78:: @ 831BC78
	.incbin "baserom.gba", 0x31bc78, 0x8

gUnknown_0831BC80:: @ 831BC80
	.incbin "baserom.gba", 0x31bc80, 0x8

gUnknown_0831BC88:: @ 831BC88
	.incbin "baserom.gba", 0x31bc88, 0x8

gUnknown_0831BC90:: @ 831BC90
	.incbin "baserom.gba", 0x31bc90, 0x8

gUnknown_0831BC98:: @ 831BC98
	.incbin "baserom.gba", 0x31bc98, 0x8

gUnknown_0831BCA0:: @ 831BCA0
	.incbin "baserom.gba", 0x31bca0, 0x8

gUnknown_0831BCA8:: @ 831BCA8
	.incbin "baserom.gba", 0x31bca8, 0x38

gUnknown_0831BCE0:: @ 831BCE0
	.incbin "baserom.gba", 0x31bce0, 0xf

gUnknown_0831BCEF:: @ 831BCEF
	.incbin "baserom.gba", 0x31bcef, 0x4

gUnknown_0831BCF3:: @ 831BCF3
	.incbin "baserom.gba", 0x31bcf3, 0x5

gUnknown_0831BCF8:: @ 831BCF8
	.incbin "baserom.gba", 0x31bcf8, 0x18

	.align 2, 0
gBattleScriptingCommandsTable:: @ 831BD10
	.4byte atk00_attackcanceler
	.4byte atk01_accuracycheck
	.4byte atk02_attackstring
	.4byte atk03_ppreduce
	.4byte atk04_critcalc
	.4byte atk05_cmd5
	.4byte sub_8047038
	.4byte atk07_cmd7
	.4byte atk08_cmd8
	.4byte atk09_attackanimation
	.4byte sub_8047DC8
	.4byte atk0B_graphicalhpupdate
	.4byte atk0C_datahpupdate
	.4byte atk0D_critmessage
	.4byte atk0E_missmessage
	.4byte atk0F_resultmessage
	.4byte atk10_printstring
	.4byte atk11_printstring2
	.4byte atk12_waitmessage
	.4byte atk13_printfromtable
	.4byte atk14_printfromtable2
	.4byte atk15_seteffectwithchancetarget
	.4byte sub_8049AC0
	.4byte sub_8049AD0
	.4byte sub_8049AE0
	.4byte atk19_faintpokemon
	.4byte sub_8049E40
	.4byte sub_8049E7C
	.4byte atk1C_jumpifstatus
	.4byte atk1D_jumpifsecondarystatus
	.4byte atk1E_jumpifability
	.4byte sub_804A0DC
	.4byte sub_804A154
	.4byte atk21_jumpifspecialstatusflag
	.4byte sub_804A2D0
	.4byte sub_804A32C
	.4byte sub_804ACD0
	.4byte atk25_cmd25
	.4byte atk26_80225F0_storebyteforjump
	.4byte atk27_cmd27
	.4byte atk28_goto
	.4byte atk29_jumpifbyte
	.4byte sub_804B0A8
	.4byte sub_804B150
	.4byte sub_804B204
	.4byte sub_804B28C
	.4byte sub_804B310
	.4byte sub_804B338
	.4byte sub_804B364
	.4byte atk31_copyarray
	.4byte atk32_memcpy_with_offset
	.4byte atk33_orbyte
	.4byte atk34_orhalfword
	.4byte atk35_orword
	.4byte atk36_bicbyte
	.4byte atk37_bichalfword
	.4byte atk38_bicword
	.4byte atk39_pause
	.4byte sub_804B5E0
	.4byte atk3B_8022C68
	.4byte atk3C_return
	.4byte sub_804B664
	.4byte atk3E_end2
	.4byte atk3F_end3
	.4byte atk40_801DBA0
	.4byte atk41_call
	.4byte atk42_jumpiftype2
	.4byte sub_804B784
	.4byte sub_804B7D0
	.4byte atk46_cmd46
	.4byte sub_804B8B0
	.4byte sub_804B97C
	.4byte atk48_playstatchangeanimation
	.4byte sub_804BBCC
	.4byte atk4A_damagecalc2
	.4byte atk4B_cmd4b
	.4byte atk4C_switch1
	.4byte sub_804C904
	.4byte atk4E_switch3
	.4byte atk4F_jumpifcannotswitch
	.4byte atk50_openpartyscreen
	.4byte atk51_cmd51
	.4byte atk52_cmd52
	.4byte sub_804DDA8
	.4byte atk54_802511C
	.4byte sub_804DE14
	.4byte atk56_8025194
	.4byte atk57_80251C4_flee
	.4byte atk58_cmd58
	.4byte atk59_8025230
	.4byte sub_804E038
	.4byte atk5B_80256E0
	.4byte atk5C_cmd5c
	.4byte sub_804E6D8
	.4byte atk5E_8025A70
	.4byte atk5F_8025B24
	.4byte atk60_cmd60
	.4byte atk61_8025BA4
	.4byte atk62_08025C6C
	.4byte atk63_jumptoattack
	.4byte atk64_statusanimation
	.4byte atk65_8025D90
	.4byte atk66_8025E38
	.4byte atk67_8025ECC
	.4byte sub_804ECA4
	.4byte atk69_8025FE0
	.4byte atk6A_stash_item_for_side
	.4byte atk6B_end_battle_80261CC
	.4byte atk6C_8026208
	.4byte sub_804F4D4
	.4byte atk6E_state0_side_becomes_attacker
	.4byte atk6F_8026810
	.4byte atk70_record_ability_usage_of_side
	.4byte atk71_80268A0
	.4byte atk72_flee
	.4byte atk73_cmd73
	.4byte atk74_hp_tresholds_2
	.4byte atk75_8026A58
	.4byte sub_804F7AC
	.4byte atk77_setprotect
	.4byte atk78_faintifabilitynotdamp
	.4byte atk79_setuserhptozero
	.4byte sub_8050044
	.4byte sub_80500E8
	.4byte sub_8050164
	.4byte sub_80502C8
	.4byte atk7E_setreflect
	.4byte sub_80503E8
	.4byte atk80_manipulatedamage
	.4byte atk81_setrest
	.4byte atk82_jumpifnotfirstturn
	.4byte sub_8050640
	.4byte sub_80506EC
	.4byte sub_8050768
	.4byte atk86_stockpiletobasedamage
	.4byte atk87_stockpiletohprecovery
	.4byte atk88_negativedamage
	.4byte atk89_statbuffchange
	.4byte atk8A_normalisebuffs
	.4byte atk8B_setbide
	.4byte atk8C_confuseifrepeatingattackends
	.4byte atk8D_setloopcounter
	.4byte atk8E_cmd8e
	.4byte sub_805112C
	.4byte sub_8051424
	.4byte atk91_givemoney
	.4byte atk92_setlightscreen
	.4byte atk93_ko_move
	.4byte atk94_gethalfcurrentenemyhp
	.4byte sub_8051AC0
	.4byte sub_8051B18
	.4byte atk97_tryinfatuatetarget
	.4byte sub_8051E48
	.4byte atk99_setmisteffect
	.4byte atk9A_setincreasedcriticalchance
	.4byte atk9B_transformdataexecution
	.4byte sub_80521FC
	.4byte atk9D_copyattack
	.4byte sub_80524DC
	.4byte atk9F_nightshadedamageeffect
	.4byte atkA0_psywavedamageeffect
	.4byte atkA1_counterdamagecalculator
	.4byte atkA2_mirrorcoatdamagecalculator
	.4byte atkA3_disablelastusedattack
	.4byte atkA4_setencore
	.4byte sub_8052A70
	.4byte atkA6_settypetorandomresistance
	.4byte atkA7_setalwayshitflag
	.4byte atkA8_copymovepermanently
	.4byte sub_8053018
	.4byte atkAA_destinybondeffect
	.4byte atkAB_802A458
	.4byte atkAC_remaininghptopower
	.4byte atkAD_reducepprandom
	.4byte atkAE_clearstatusifnotsoundproofed
	.4byte atkAF_cursetarget
	.4byte atkB0_setspikes
	.4byte atkB1_setforesight
	.4byte atkB2_setperishsong
	.4byte atkB3_rolloutdamagecalculation
	.4byte atkB4_jumpifconfusedandattackmaxed
	.4byte sub_8053AF8
	.4byte atkB6_happinesstodamagecalculation
	.4byte atkB7_presentdamagecalculation
	.4byte atkB8_setsafeguard
	.4byte atkB9_magnitudedamagecalculation
	.4byte atkBA_802B140
	.4byte sub_805405C
	.4byte atkBC_maxattackhalvehp
	.4byte atkBD_copyfoestats
	.4byte atkBE_breakfree
	.4byte atkBF_setcurled
	.4byte atkC0_recoverbasedonsunlight
	.4byte sub_8054400
	.4byte atkC2_selectnexttarget
	.4byte atkC3_setfutureattack
	.4byte atkC4_802B910
	.4byte atkC5_hidepreattack
	.4byte atkC6_unhidepostattack
	.4byte atkC7_setminimize
	.4byte sub_8054A48
	.4byte atkC9_jumpifattackandspecialattackcannotfall
	.4byte atkCA_setforcedtarget
	.4byte atkCB_setcharge
	.4byte atkCC_callterrainattack
	.4byte atkCD_cureifburnedparalysedorpoisoned
	.4byte atkCE_settorment
	.4byte atkCF_jumpifnodamage
	.4byte atkD0_settaunt
	.4byte atkD1_sethelpinghand
	.4byte sub_8054EB4
	.4byte sub_8055148
	.4byte atkD4_802C408
	.4byte sub_8055294
	.4byte atkD6_doubledamagedealtifdamaged
	.4byte sub_805534C
	.4byte atkD8_setdamagetohealthdifference
	.4byte atkD9_scaledamagebyhealthratio
	.4byte atkDA_abilityswap
	.4byte atkDB_imprisoneffect
	.4byte atkDC_setgrudge
	.4byte atkDD_weightdamagecalculation
	.4byte atkDE_asistattackselect
	.4byte atkDF_setmagiccoat
	.4byte atkE0_setstealstatchange
	.4byte atkE1_802CBE4
	.4byte atkE2_cmde2
	.4byte atkE3_jumpiffainted
	.4byte sub_8055B48
	.4byte atkE5_pickupitemcalculation
	.4byte atkE6_castform_transform
	.4byte atkE7_castform_switch
	.4byte atkE8_settypebasedhalvers
	.4byte atkE9_seteffectbyweather
	.4byte atkEA_recycleitem
	.4byte atkEB_settypetoterrain
	.4byte atkEC_802D2A0
	.4byte atkED_802D364
	.4byte atkEE_removereflectlightscreen
	.4byte sub_8056300
	.4byte atkF0_catch_pokemon
	.4byte atkF1_802D95C
	.4byte sub_80568CC
	.4byte atkF3_receive_new_pokemon_maybe
	.4byte sub_8056E78
	.4byte atkF5_reset_attacker_bd_x4C
	.4byte sub_8056ED0
	.4byte sub_8056EDC
	.4byte sub_8056EF8

gUnknown_0831C0F4:: @ 831C0F4
	.incbin "baserom.gba", 0x31c0f4, 0x34

gUnknown_0831C128:: @ 831C128
	.incbin "baserom.gba", 0x31c128, 0xc

gUnknown_0831C134:: @ 831C134
	.incbin "baserom.gba", 0x31c134, 0xf0

gUnknown_0831C224:: @ 831C224
	.incbin "baserom.gba", 0x31c224, 0xa4

gUnknown_0831C2C8:: @ 831C2C8
	.incbin "baserom.gba", 0x31c2c8, 0x20

gUnknown_0831C2E8:: @ 831C2E8
	.incbin "baserom.gba", 0x31c2e8, 0xd8

gUnknown_0831C3C0:: @ 831C3C0
	.incbin "baserom.gba", 0x31c3c0, 0x18

gUnknown_0831C3D8:: @ 831C3D8
	.incbin "baserom.gba", 0x31c3d8, 0x8

gUnknown_0831C3E0:: @ 831C3E0
	.incbin "baserom.gba", 0x31c3e0, 0x28

gUnknown_0831C408:: @ 831C408
	.incbin "baserom.gba", 0x31c408, 0xc

gUnknown_0831C414:: @ 831C414
	.incbin "baserom.gba", 0x31c414, 0x14

gUnknown_0831C428:: @ 831C428
	.incbin "baserom.gba", 0x31c428, 0x18

@ 831C440
	.include "data/pickup_items.inc"

gUnknown_0831C483:: @ 831C483
	.incbin "baserom.gba", 0x31c483, 0xa

gUnknown_0831C48D:: @ 831C48D
	.incbin "baserom.gba", 0x31c48d, 0x7

gUnknown_0831C494:: @ 831C494
	.incbin "baserom.gba", 0x31c494, 0x64

gUnknown_0831C4F8:: @ 831C4F8
	.incbin "baserom.gba", 0x31c4f8, 0x1c

gPlayerBufferCommands:: @ 831C514
	.incbin "baserom.gba", 0x31c514, 0xe4

gUnknown_0831C5F8:: @ 831C5F8
	.incbin "baserom.gba", 0x31c5f8, 0xc

gUnknown_0831C604:: @ 831C604
	.incbin "baserom.gba", 0x31c604, 0x1c

gUnknown_0831C620:: @ 831C620
	.incbin "baserom.gba", 0x31c620, 0x8

gUnknown_0831C628:: @ 831C628
	.incbin "baserom.gba", 0x31c628, 0x60

gUnknown_0831C688:: @ 831C688
	.incbin "baserom.gba", 0x31c688, 0x18

gUnknown_0831C6A0:: @ 831C6A0
	.incbin "baserom.gba", 0x31c6a0, 0x10

gUnknown_0831C6B0:: @ 831C6B0
	.incbin "baserom.gba", 0x31c6b0, 0x18

gUnknown_0831C6C8:: @ 831C6C8
	.incbin "baserom.gba", 0x31c6c8, 0xec

gUnknown_0831C7B4:: @ 831C7B4
	.incbin "baserom.gba", 0x31c7b4, 0xe4

@ 831C898
	.include "data/battle_moves.inc"

	.incbin "baserom.gba", 0x31d93c, 0x10

@ 831D94C
	.include "data/pokedex_order.inc"

@ 831E2F0
	.include "data/spinda_spot_graphics.inc"

@ 831E380
	.include "data/item_effect_info.inc"

@ 831E818
	.include "data/nature_stat_table.inc"

@ 831E898
	.include "data/tm_hm_learnsets.inc"

@ 831F578
	.include "data/trainer_pic_indices.inc"

@ 831F5CA
	.include "data/trainer_class_name_indices.inc"

@ 831F61C
	.include "data/cry_id_table.inc"

@ 831F72C
	.include "data/experience_tables.inc"

@ 83203CC
	.include "data/base_stats.inc"

@ 83230DC
	.include "data/level_up_learnsets.inc"

@ 832531C
	.include "data/evolution_table.inc"

@ 832937C
	.include "data/level_up_learnset_pointers.inc"

gUnknown_083299EC:: @ 83299EC
	.incbin "baserom.gba", 0x3299ec, 0x19b

gUnknown_08329B87:: @ 8329B87
	.incbin "baserom.gba", 0x329b87, 0x19b

gUnknown_08329D22:: @ 8329D22
	.incbin "baserom.gba", 0x329d22, 0x4

gUnknown_08329D26:: @ 8329D26
	.incbin "baserom.gba", 0x329d26, 0x4

gUnknown_08329D2A:: @ 8329D2A
	.incbin "baserom.gba", 0x329d2a, 0x4

gUnknown_08329D2E:: @ 8329D2E
	.incbin "baserom.gba", 0x329d2e, 0x1a

gUnknown_08329D48:: @ 8329D48
	.incbin "baserom.gba", 0x329d48, 0xc

gUnknown_08329D54:: @ 8329D54
	.incbin "baserom.gba", 0x329d54, 0x20

gHoldEffectToType:: @ 8329D74
	.incbin "baserom.gba", 0x329d74, 0x24

gUnknown_08329D98:: @ 8329D98
	.incbin "baserom.gba", 0x329d98, 0x60

gUnknown_08329DF8:: @ 8329DF8
	.incbin "baserom.gba", 0x329df8, 0xc0

gUnknown_08329EB8:: @ 8329EB8
	.incbin "baserom.gba", 0x329eb8, 0xa

gUnknown_08329EC2:: @ 8329EC2
	.incbin "baserom.gba", 0x329ec2, 0x6

gUnknown_08329EC8:: @ 8329EC8
	.incbin "baserom.gba", 0x329ec8, 0x6

gUnknown_08329ECE:: @ 8329ECE
	.incbin "baserom.gba", 0x329ece, 0x1c

gUnknown_08329EEA:: @ 8329EEA
	.incbin "baserom.gba", 0x329eea, 0x12

gUnknown_08329EFC:: @ 8329EFC
	.incbin "baserom.gba", 0x329efc, 0x2

gUnknown_08329EFE:: @ 8329EFE
	.incbin "baserom.gba", 0x329efe, 0x2a

gUnknown_08329F28:: @ 8329F28
	.incbin "baserom.gba", 0x329f28, 0x18

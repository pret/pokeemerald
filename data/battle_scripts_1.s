	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

gBattleScriptsForMoveEffects:: @ 82D86A8
	.incbin "baserom.gba", 0x2d86a8, 0x388

BattleScript_PresentDamageTarget:: @ 82D8A30
	.incbin "baserom.gba", 0x2d8a30, 0x1e

BattleScript_MoveEnd:: @ 82D8A4E
	.incbin "baserom.gba", 0x2d8a4e, 0x12

BattleScript_PauseEffectivenessSoundResultMsgEndMove:: @ 82D8A60
	.incbin "baserom.gba", 0x2d8a60, 0x274

BattleScript_StatUp:: @ 82D8CD4
	.incbin "baserom.gba", 0x2d8cd4, 0x91

BattleScript_StatDown:: @ 82D8D65
	.incbin "baserom.gba", 0x2d8d65, 0x6fd

BattleScript_MoveUsedMustRecharge:: @ 82D9462
	.incbin "baserom.gba", 0x2d9462, 0xa7f

BattleScript_PresentHealTarget:: @ 82D9EE1
	.incbin "baserom.gba", 0x2d9ee1, 0x1a

BattleScript_AlreadyAtFullHp:: @ 82D9EFB
	.incbin "baserom.gba", 0x2d9efb, 0x21

BattleScript_ButItFailed:: @ 82D9F1C
	.incbin "baserom.gba", 0x2d9f1c, 0x88e

BattleScript_FaintAttacker:: @ 82DA7AA
	.incbin "baserom.gba", 0x2da7aa, 0xd

BattleScript_FaintTarget:: @ 82DA7B7
	.incbin "baserom.gba", 0x2da7b7, 0xd

gUnknown_082DA7C4:: @ 82DA7C4
	.incbin "baserom.gba", 0x2da7c4, 0x9

gUnknown_082DA7CD:: @ 82DA7CD
	.incbin "baserom.gba", 0x2da7cd, 0x160

gUnknown_082DA92D:: @ 82DA92D
	.incbin "baserom.gba", 0x2da92d, 0x3d

gUnknown_082DA96A:: @ 82DA96A
	.incbin "baserom.gba", 0x2da96a, 0x3

gUnknown_082DA96D:: @ 82DA96D
	.incbin "baserom.gba", 0x2da96d, 0x9e

gUnknown_082DAA0B:: @ 82DAA0B
	.incbin "baserom.gba", 0x2daa0b, 0x2a

gUnknown_082DAA35:: @ 82DAA35
	.incbin "baserom.gba", 0x2daa35, 0x52

gUnknown_082DAA87:: @ 82DAA87
	.incbin "baserom.gba", 0x2daa87, 0x54

gUnknown_082DAADB:: @ 82DAADB
	.incbin "baserom.gba", 0x2daadb, 0xe

gUnknown_082DAAE9:: @ 82DAAE9
	.incbin "baserom.gba", 0x2daae9, 0x7

gUnknown_082DAAF0:: @ 82DAAF0
	.incbin "baserom.gba", 0x2daaf0, 0x7

gUnknown_082DAAF7:: @ 82DAAF7
	.incbin "baserom.gba", 0x2daaf7, 0x7

gUnknown_082DAAFE:: @ 82DAAFE
	.incbin "baserom.gba", 0x2daafe, 0x4

gUnknown_082DAB02:: @ 82DAB02
	.incbin "baserom.gba", 0x2dab02, 0x9

gUnknown_082DAB0B:: @ 82DAB0B
	.incbin "baserom.gba", 0x2dab0b, 0x6

gUnknown_082DAB11:: @ 82DAB11
	.incbin "baserom.gba", 0x2dab11, 0x4

gUnknown_082DAB15:: @ 82DAB15
	.incbin "baserom.gba", 0x2dab15, 0xa4

BattleScript_Pausex20:: @ 82DABB9
	.incbin "baserom.gba", 0x2dabb9, 0x4

BattleScript_LevelUp:: @ 82DABBD
	.incbin "baserom.gba", 0x2dabbd, 0x6f

gUnknown_082DAC2C:: @ 82DAC2C
	.incbin "baserom.gba", 0x2dac2c, 0x1b

gUnknown_082DAC47:: @ 82DAC47
	.incbin "baserom.gba", 0x2dac47, 0x82

gUnknown_082DACC9:: @ 82DACC9
	.incbin "baserom.gba", 0x2dacc9, 0x9

gUnknown_082DACD2:: @ 82DACD2
	.incbin "baserom.gba", 0x2dacd2, 0xe

gUnknown_082DACE0:: @ 82DACE0
	.incbin "baserom.gba", 0x2dace0, 0x7

gUnknown_082DACE7:: @ 82DACE7
	.incbin "baserom.gba", 0x2dace7, 0x13

gUnknown_082DACFA:: @ 82DACFA
	.incbin "baserom.gba", 0x2dacfa, 0x11

gUnknown_082DAD0B:: @ 82DAD0B
	.incbin "baserom.gba", 0x2dad0b, 0xa

BattleScript_LeechSeedTurnDrain:: @ 82DAD15
	.incbin "baserom.gba", 0x2dad15, 0x5c

BattleScript_BideStoringEnergy:: @ 82DAD71
	.incbin "baserom.gba", 0x2dad71, 0xb

BattleScript_BideAttack:: @ 82DAD7C
	.incbin "baserom.gba", 0x2dad7c, 0x48

BattleScript_BideNoEnergyToAttack:: @ 82DADC4
	.incbin "baserom.gba", 0x2dadc4, 0x14

gUnknown_082DADD8:: @ 82DADD8
	.incbin "baserom.gba", 0x2dadd8, 0x2b

BattleScript_MistProtected:: @ 82DAE03
	.incbin "baserom.gba", 0x2dae03, 0xa

BattleScript_RageIsBuilding:: @ 82DAE0D
	.incbin "baserom.gba", 0x2dae0d, 0x7

BattleScript_MoveUsedIsDisabled:: @ 82DAE14
	.incbin "baserom.gba", 0x2dae14, 0xb

gUnknown_082DAE1F:: @ 82DAE1F
	.incbin "baserom.gba", 0x2dae1f, 0x4

BattleScript_DisabledNoMore:: @ 82DAE23
	.incbin "baserom.gba", 0x2dae23, 0x7

gUnknown_082DAE2A:: @ 82DAE2A
	.incbin "baserom.gba", 0x2dae2a, 0xd

BattleScript_EncoredNoMore:: @ 82DAE37
	.incbin "baserom.gba", 0x2dae37, 0x7

BattleScript_DestinyBondTakesLife:: @ 82DAE3E
	.incbin "baserom.gba", 0x2dae3e, 0x1b

gUnknown_082DAE59:: @ 82DAE59
	.incbin "baserom.gba", 0x2dae59, 0x37

gUnknown_082DAE90:: @ 82DAE90
	.incbin "baserom.gba", 0x2dae90, 0x37

gUnknown_082DAEC7:: @ 82DAEC7
	.incbin "baserom.gba", 0x2daec7, 0x3e

gUnknown_082DAF05:: @ 82DAF05
	.incbin "baserom.gba", 0x2daf05, 0x1b

gUnknown_082DAF20:: @ 82DAF20
	.incbin "baserom.gba", 0x2daf20, 0x7

BattleScript_AllStatsUp:: @ 82DAF27
	.incbin "baserom.gba", 0x2daf27, 0x9c

BattleScript_RapidSpinAway:: @ 82DAFC3
	.incbin "baserom.gba", 0x2dafc3, 0x2

BattleScript_WrapFree:: @ 82DAFC5
	.incbin "baserom.gba", 0x2dafc5, 0x11

BattleScript_LeechSeedFree:: @ 82DAFD6
	.incbin "baserom.gba", 0x2dafd6, 0x7

BattleScript_SpikesFree:: @ 82DAFDD
	.incbin "baserom.gba", 0x2dafdd, 0x7

gUnknown_082DAFE4:: @ 82DAFE4
	.incbin "baserom.gba", 0x2dafe4, 0x8e

BattleScript_NoMovesLeft:: @ 82DB072
	.incbin "baserom.gba", 0x2db072, 0x4

gUnknown_082DB076:: @ 82DB076
	.incbin "baserom.gba", 0x2db076, 0x4

BattleScript_NoPPForMove:: @ 82DB07A
	.incbin "baserom.gba", 0x2db07a, 0xf

gUnknown_082DB089:: @ 82DB089
	.incbin "baserom.gba", 0x2db089, 0xf

gUnknown_082DB098:: @ 82DB098
	.incbin "baserom.gba", 0x2db098, 0x8

gUnknown_082DB0A0:: @ 82DB0A0
	.incbin "baserom.gba", 0x2db0a0, 0x4

BattleScript_MoveUsedIsTaunted:: @ 82DB0A4
	.incbin "baserom.gba", 0x2db0a4, 0xb

gUnknown_082DB0AF:: @ 82DB0AF
	.incbin "baserom.gba", 0x2db0af, 0x8

BattleScript_WishComesTrue:: @ 82DB0B7
	.incbin "baserom.gba", 0x2db0b7, 0x37

BattleScript_IngrainTurnHeal:: @ 82DB0EE
	.incbin "baserom.gba", 0x2db0ee, 0x29

BattleScript_AtkDefDown:: @ 82DB117
	.incbin "baserom.gba", 0x2db117, 0x51

BattleScript_KnockedOff:: @ 82DB168
	.incbin "baserom.gba", 0x2db168, 0xe

BattleScript_MoveUsedIsImprisoned:: @ 82DB176
	.incbin "baserom.gba", 0x2db176, 0xb

gUnknown_082DB181:: @ 82DB181
	.incbin "baserom.gba", 0x2db181, 0x4

gUnknown_082DB185:: @ 82DB185
	.incbin "baserom.gba", 0x2db185, 0x8

BattleScript_GrudgeTakesPp:: @ 82DB18D
	.incbin "baserom.gba", 0x2db18d, 0x7

BattleScript_MagicCoatBounce:: @ 82DB194
	.incbin "baserom.gba", 0x2db194, 0x18

BattleScript_SnatchedMove:: @ 82DB1AC
	.incbin "baserom.gba", 0x2db1ac, 0x1b

BattleScript_EnduredMsg:: @ 82DB1C7
	.incbin "baserom.gba", 0x2db1c7, 0x7

BattleScript_OneHitKOMsg:: @ 82DB1CE
	.incbin "baserom.gba", 0x2db1ce, 0x7

BattleScript_SAtkDown2:: @ 82DB1D5
	.incbin "baserom.gba", 0x2db1d5, 0x2a

gUnknown_082DB1FF:: @ 82DB1FF
	.incbin "baserom.gba", 0x2db1ff, 0x14

BattleScript_MoveUsedIsAsleep:: @ 82DB213
	.incbin "baserom.gba", 0x2db213, 0xd

BattleScript_MoveUsedWokeUp:: @ 82DB220
	.incbin "baserom.gba", 0x2db220, 0x14

gUnknown_082DB234:: @ 82DB234
	.incbin "baserom.gba", 0x2db234, 0x9

BattleScript_PoisonTurnDmg:: @ 82DB23D
	.incbin "baserom.gba", 0x2db23d, 0x22

BattleScript_BurnTurnDmg:: @ 82DB25F
	.incbin "baserom.gba", 0x2db25f, 0xb

BattleScript_MoveUsedIsFrozen:: @ 82DB26A
	.incbin "baserom.gba", 0x2db26a, 0xd

BattleScript_MoveUsedUnfroze:: @ 82DB277
	.incbin "baserom.gba", 0x2db277, 0xb

BattleScript_DefrostedViaFireMove:: @ 82DB282
	.incbin "baserom.gba", 0x2db282, 0x9

BattleScript_MoveUsedIsParalyzed:: @ 82DB28B
	.incbin "baserom.gba", 0x2db28b, 0x10

BattleScript_MoveUsedFlinched:: @ 82DB29B
	.incbin "baserom.gba", 0x2db29b, 0xb

gUnknown_082DB2A6:: @ 82DB2A6
	.incbin "baserom.gba", 0x2db2a6, 0x9

BattleScript_ThrashConfuses:: @ 82DB2AF
	.incbin "baserom.gba", 0x2db2af, 0xe

BattleScript_MoveUsedIsConfused:: @ 82DB2BD
	.incbin "baserom.gba", 0x2db2bd, 0x43

BattleScript_MoveUsedIsConfusedNoMore:: @ 82DB300
	.incbin "baserom.gba", 0x2db300, 0x7

BattleScript_PrintPayDayMoneyString:: @ 82DB307
	.incbin "baserom.gba", 0x2db307, 0x7

BattleScript_WrapTurnDmg:: @ 82DB30E
	.incbin "baserom.gba", 0x2db30e, 0x12

BattleScript_WrapEnds:: @ 82DB320
	.incbin "baserom.gba", 0x2db320, 0x7

BattleScript_MoveUsedIsInLove:: @ 82DB327
	.incbin "baserom.gba", 0x2db327, 0xd

BattleScript_MoveUsedIsParalyzedCantAttack:: @ 82DB334
	.incbin "baserom.gba", 0x2db334, 0xb

BattleScript_NightmareTurnDmg:: @ 82DB33F
	.incbin "baserom.gba", 0x2db33f, 0x11

BattleScript_CurseTurnDmg:: @ 82DB350
	.incbin "baserom.gba", 0x2db350, 0x11

BattleScript_TargetPRLZHeal:: @ 82DB361
	.incbin "baserom.gba", 0x2db361, 0x9

BattleScript_MoveEffectSleep:: @ 82DB36A
	.incbin "baserom.gba", 0x2db36A, 0xE

BattleScript_YawnMakesAsleep:: @ 82DB378
	.incbin "baserom.gba", 0x2db378, 0xE

BattleScript_MoveEffectPoison:: @ 82DB386
	.incbin "baserom.gba", 0x2db386, 0xF

BattleScript_MoveEffectBurn:: @ 82DB395
	.incbin "baserom.gba", 0x2db395, 0xF

BattleScript_MoveEffectFreeze:: @ 82DB3A4
	.incbin "baserom.gba", 0x2db3A4, 0xF

BattleScript_MoveEffectParalysis:: @ 82DB3B3
	.incbin "baserom.gba", 0x2db3B3, 0xF

BattleScript_MoveEffectUproar:: @ 82DB3C2
	.incbin "baserom.gba", 0x2db3C2, 0x7

BattleScript_MoveEffectToxic:: @ 82DB3C9
	.incbin "baserom.gba", 0x2db3C9, 0xD

BattleScript_MoveEffectPayDay:: @ 82DB3D6
	.incbin "baserom.gba", 0x2db3D6, 0x7

BattleScript_MoveEffectWrap:: @ 82DB3DD
	.incbin "baserom.gba", 0x2db3DD, 0x9

BattleScript_MoveEffectConfusion:: @ 82DB3E6
	.incbin "baserom.gba", 0x2db3E6, 0xE

BattleScript_MoveEffectRecoil33:: @ 82DB3F4
	.incbin "baserom.gba", 0x2db3F4, 0x2e

BattleScript_ItemSteal:: @ 82DB422
	.incbin "baserom.gba", 0x2db422, 0xe

BattleScript_DrizzleActivates:: @ 82DB430
	.incbin "baserom.gba", 0x2db430, 0x14

BattleScript_SpeedBoostActivates:: @ 82DB444
	.incbin "baserom.gba", 0x2db444, 0xe

BattleScript_TraceActivates:: @ 82DB452
	.incbin "baserom.gba", 0x2db452, 0xa

BattleScript_RainDishActivates:: @ 82DB45C
	.incbin "baserom.gba", 0x2db45c, 0x14

BattleScript_SandstreamActivates:: @ 82DB470
	.incbin "baserom.gba", 0x2db470, 0x14

BattleScript_ShedSkinActivates:: @ 82DB484
	.incbin "baserom.gba", 0x2db484, 0x25

BattleScript_CastformChange:: @ 82DB4A9
	.incbin "baserom.gba", 0x2db4a9, 0xf

gUnknown_082DB4B8:: @ 82DB4B8
	.incbin "baserom.gba", 0x2db4b8, 0x9

gUnknown_082DB4C1:: @ 82DB4C1
	.incbin "baserom.gba", 0x2db4c1, 0x69

BattleScript_DroughtActivates:: @ 82DB52A
	.incbin "baserom.gba", 0x2db52a, 0x14

BattleScript_TookAttack:: @ 82DB53E
	.incbin "baserom.gba", 0x2db53e, 0x14

BattleScript_SturdyPreventsOHKO:: @ 82DB552
	.incbin "baserom.gba", 0x2db552, 0xe

BattleScript_DampStopsExplosion:: @ 82DB560
	.incbin "baserom.gba", 0x2db560, 0xe

BattleScript_MoveHPDrain_PPLoss:: @ 82DB56E
	.incbin "baserom.gba", 0x2db56e, 0x1

BattleScript_MoveHPDrain:: @ 82DB56F
	.incbin "baserom.gba", 0x2db56f, 0x22

gUnknown_082DB591:: @ 82DB591
	.incbin "baserom.gba", 0x2db591, 0x1

gUnknown_082DB592:: @ 82DB592
	.incbin "baserom.gba", 0x2db592, 0x15

BattleScript_FlashFireBoost_PPLoss:: @ 82DB5A7
	.incbin "baserom.gba", 0x2db5a7, 0x1

BattleScript_FlashFireBoost:: @ 82DB5A8
	.incbin "baserom.gba", 0x2db5a8, 0x1f

BattleScript_AbilityNoStatLoss:: @ 82DB5C7
	.incbin "baserom.gba", 0x2db5c7, 0xa

BattleScript_BRNPrevention:: @ 82DB5D1
	.incbin "baserom.gba", 0x2db5d1, 0xc

BattleScript_PRLZPrevention:: @ 82DB5DD
	.incbin "baserom.gba", 0x2db5dd, 0xc

BattleScript_PSNPrevention:: @ 82DB5E9
	.incbin "baserom.gba", 0x2db5e9, 0xc

BattleScript_ObliviousPreventsAttraction:: @ 82DB5F5
	.incbin "baserom.gba", 0x2db5f5, 0xe

BattleScript_FlinchPrevention:: @ 82DB603
	.incbin "baserom.gba", 0x2db603, 0x1c

BattleScript_SoundproofProtected:: @ 82DB61F
	.incbin "baserom.gba", 0x2db61f, 0x10

BattleScript_AbilityNoSpecificStatLoss:: @ 82DB62F
	.incbin "baserom.gba", 0x2db62f, 0x10

BattleScript_StickyHoldActivates:: @ 82DB63F
	.incbin "baserom.gba", 0x2db63f, 0xe

BattleScript_ColorChangeActivates:: @ 82DB64D
	.incbin "baserom.gba", 0x2db64d, 0x7

BattleScript_RoughSkinActivates:: @ 82DB654
	.incbin "baserom.gba", 0x2db654, 0x1b

BattleScript_CuteCharmActivates:: @ 82DB66F
	.incbin "baserom.gba", 0x2db66f, 0xd

BattleScript_ApplySecondaryEffect:: @ 82DB67C
	.incbin "baserom.gba", 0x2db67c, 0x3

BattleScript_SynchronizeActivates:: @ 82DB67F
	.incbin "baserom.gba", 0x2db67f, 0x3

BattleScript_NoItemSteal:: @ 82DB682
	.incbin "baserom.gba", 0x2db682, 0xa

gUnknown_082DB68C:: @ 82DB68C
	.incbin "baserom.gba", 0x2db68c, 0x9

gUnknown_082DB695:: @ 82DB695
	.incbin "baserom.gba", 0x2db695, 0x10

gUnknown_082DB6A5:: @ 82DB6A5
	.incbin "baserom.gba", 0x2db6a5, 0x8

BattleScript_MoveUsedLoafingAround:: @ 82DB6AD
	.incbin "baserom.gba", 0x2db6ad, 0x2c

gUnknown_082DB6D9:: @ 82DB6D9
	.incbin "baserom.gba", 0x2db6d9, 0x17

gUnknown_082DB6F0:: @ 82DB6F0
	.incbin "baserom.gba", 0x2db6f0, 0xb

BattleScript_SubstituteFade:: @ 82DB6FB
	.incbin "baserom.gba", 0x2db6fb, 0xb

BattleScript_BerryCurePrlzEnd2:: @ 82DB706
	.incbin "baserom.gba", 0x2db706, 0x6

BattleScript_BerryCureParRet:: @ 82DB70C
	.incbin "baserom.gba", 0x2db70c, 0x12

BattleScript_BerryCurePsnEnd2:: @ 82DB71E
	.incbin "baserom.gba", 0x2db71e, 0x6

BattleScript_BerryCurePsnRet:: @ 82DB724
	.incbin "baserom.gba", 0x2db724, 0x12

BattleScript_BerryCureBrnEnd2:: @ 82DB736
	.incbin "baserom.gba", 0x2db736, 0x6

BattleScript_BerryCureBrnRet:: @ 82DB73C
	.incbin "baserom.gba", 0x2db73c, 0x12

BattleScript_BerryCureFrzEnd2:: @ 82DB74E
	.incbin "baserom.gba", 0x2db74e, 0x6

BattleScript_BerryCureFrzRet:: @ 82DB754
	.incbin "baserom.gba", 0x2db754, 0x12

BattleScript_BerryCureSlpEnd2:: @ 82DB766
	.incbin "baserom.gba", 0x2db766, 0x6

BattleScript_BerryCureSlpRet:: @ 82DB76C
	.incbin "baserom.gba", 0x2db76c, 0x12

BattleScript_BerryCureConfusionEnd2:: @ 82DB77E
	.incbin "baserom.gba", 0x2db77e, 0x6

BattleScript_BerryCureConfusionRet:: @ 82DB784
	.incbin "baserom.gba", 0x2db784, 0x10

BattleScript_BerryCureChosenStatusEnd2:: @ 82DB794
	.incbin "baserom.gba", 0x2db794, 0x6

BattleScript_BerryCureChosenStatusRet:: @ 82DB79A
	.incbin "baserom.gba", 0x2db79a, 0x14

BattleScript_WhiteHerbEnd2:: @ 82DB7AE
	.incbin "baserom.gba", 0x2db7ae, 0x6

BattleScript_WhiteHerbRet:: @ 82DB7B4
	.incbin "baserom.gba", 0x2db7b4, 0x10

BattleScript_ItemHealHP_RemoveItem:: @ 82DB7C4
	.incbin "baserom.gba", 0x2db7c4, 0x1d

BattleScript_BerryPPHealEnd2:: @ 82DB7E1
	.incbin "baserom.gba", 0x2db7e1, 0x10

BattleScript_ItemHealHP_End2:: @ 82DB7F1
	.incbin "baserom.gba", 0x2db7f1, 0x6

BattleScript_ItemHealHP_Ret:: @ 82DB7F7
	.incbin "baserom.gba", 0x2db7f7, 0x1b

gUnknown_082DB812:: @ 82DB812
	.incbin "baserom.gba", 0x2db812, 0x4

BattleScript_HangedOnMsg:: @ 82DB816
	.incbin "baserom.gba", 0x2db816, 0xe

BattleScript_BerryConfuseHealEnd2:: @ 82DB824
	.incbin "baserom.gba", 0x2db824, 0x2a

BattleScript_BerryStatRaiseEnd2:: @ 82DB84E
	.incbin "baserom.gba", 0x2db84e, 0x1b

BattleScript_BerryFocusEnergyEnd2:: @ 82DB869
	.incbin "baserom.gba", 0x2db869, 0x10

BattleScript_ActionSelectionItemsCantBeUsed:: @ 82DB879
	.incbin "baserom.gba", 0x2db879, 0x4

gUnknown_082DB87D:: @ 82DB87D
	.incbin "baserom.gba", 0x2db87d, 0x4

gUnknown_082DB881:: @ 82DB881
	.incbin "baserom.gba", 0x2db881, 0x3d

gUnknown_082DB8BE:: @ 82DB8BE
	.incbin "baserom.gba", 0x2db8be, 0x35

gUnknown_082DB8F3:: @ 82DB8F3
	.incbin "baserom.gba", 0x2db8f3, 0xc7

gUnknown_082DB9BA:: @ 82DB9BA
	.incbin "baserom.gba", 0x2db9ba, 0x7

gUnknown_082DB9C1:: @ 82DB9C1
	.incbin "baserom.gba", 0x2db9c1, 0x7

gUnknown_082DB9C8:: @ 82DB9C8
	.incbin "baserom.gba", 0x2db9c8, 0xc

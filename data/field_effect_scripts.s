	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gFieldEffectScriptPointers:: @ 82DB9D4
	.4byte gFieldEffectScript_ExclamationMarkIcon1
	.4byte gFieldEffectScript_UseCutOnTallGrass
	.4byte gFieldEffectScript_UseCutOnTree
	.4byte gFieldEffectScript_Shadow
	.4byte gFieldEffectScript_TallGrass
	.4byte gFieldEffectScript_Ripple
	.4byte gFieldEffectScript_FieldMoveShowMon
	.4byte gFieldEffectScript_Ash
	.4byte gFieldEffectScript_SurfBlob
	.4byte gFieldEffectScript_UseSurf
	.4byte gFieldEffectScript_GroundImpactDust
	.4byte gFieldEffectScript_Unknown11
	.4byte gFieldEffectScript_BikeHopTallGrass
	.4byte gFieldEffectScript_SandFootprints
	.4byte gFieldEffectScript_BikeHopBigSplash
	.4byte gFieldEffectScript_Splash
	.4byte gFieldEffectScript_BikeHopSmallSplash
	.4byte gFieldEffectScript_LongGrass
	.4byte gFieldEffectScript_Unknown18
	.4byte gFieldEffectScript_Unknown19
	.4byte gFieldEffectScript_Unknown20
	.4byte gFieldEffectScript_Unknown21
	.4byte gFieldEffectScript_Unknown22
	.4byte gFieldEffectScript_BerryTreeGrowthSparkle
	.4byte gFieldEffectScript_DeepSandFootprints
	.4byte gFieldEffectScript_Unknown25
	.4byte gFieldEffectScript_Unknown26
	.4byte gFieldEffectScript_Unknown27
	.4byte gFieldEffectScript_TreeDisguise
	.4byte gFieldEffectScript_MountainDisguise
	.4byte gFieldEffectScript_Unknown30
	.4byte gFieldEffectScript_UseFly
	.4byte gFieldEffectScript_FlyIn
	.4byte gFieldEffectScript_ExclamationMarkIcon2
	.4byte gFieldEffectScript_FeetInFlowingWater
	.4byte gFieldEffectScript_BikeTireTracks
	.4byte gFieldEffectScript_SandDisguisePlaceholder
	.4byte gFieldEffectScript_UseRockSmash
	.4byte gFieldEffectScript_Unknown38
	.4byte gFieldEffectScript_Unknown39
	.4byte gFieldEffectScript_Unknown40
	.4byte gFieldEffectScript_ShortGrass
	.4byte gFieldEffectScript_HotSpringsWater
	.4byte gFieldEffectScript_Unknown43
	.4byte gFieldEffectScript_Unknown44
	.4byte gFieldEffectScript_Unknown45
	.4byte gFieldEffectScript_HeartIcon
	.4byte gFieldEffectScript_Unknown47
	.4byte gFieldEffectScript_Unknown48
	.4byte gFieldEffectScript_JumpOutOfAsh
	.4byte gFieldEffectScript_Unknown50
	.4byte gFieldEffectScript_Unknown51
	.4byte gFieldEffectScript_Unknown52
	.4byte gFieldEffectScript_Bubbles
	.4byte gFieldEffectScript_Unknown54
	.4byte gFieldEffectScript_Unknown55
	.4byte gFieldEffectScript_Unknown56
	.4byte gFieldEffectScript_Unknown57
	.4byte gFieldEffectScript_Unknown58
	.4byte gFieldEffectScript_FieldMoveShowMonInit
	.4byte gFieldEffectScript_Unknown60
	.4byte gFieldEffectScript_Unknown61
	.4byte gFieldEffectScript_Unknown62
	.4byte gFieldEffectScript_Unknown63
	.4byte gFieldEffectScript_Rayquaza
	.4byte gFieldEffectScript_Unknown65
	.4byte gFieldEffectScript_Unknown66

gFieldEffectScript_ExclamationMarkIcon1:: @ 82DBAE0
	field_eff_callnative FldEff_ExclamationMarkIcon1
	field_eff_end

gFieldEffectScript_UseCutOnTallGrass:: @ 82DBAE6
	field_eff_callnative sub_80D3A6C
	field_eff_end

gFieldEffectScript_UseCutOnTree:: @ 82DBAEC
	field_eff_callnative sub_80D3ABC
	field_eff_end

gFieldEffectScript_Shadow:: @ 82DBAF2
	field_eff_callnative oei_shadow
	field_eff_end

gFieldEffectScript_TallGrass:: @ 82DBAF8
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, oei_grass_normal
	field_eff_end

gFieldEffectScript_Ripple:: @ 82DBB02
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, oei_ripples
	field_eff_end

gFieldEffectScript_FieldMoveShowMon:: @ 82DBB0C
	field_eff_callnative FldEff_FieldMoveShowMon
	field_eff_end

gFieldEffectScript_Ash:: @ 82DBB12
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, oei_ash
	field_eff_end

gFieldEffectScript_SurfBlob:: @ 82DBB1C
	field_eff_callnative sub_8155534
	field_eff_end

gFieldEffectScript_UseSurf:: @ 82DBB22
	field_eff_callnative FldEff_UseSurf
	field_eff_end

gFieldEffectScript_GroundImpactDust:: @ 82DBB28
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8155890
	field_eff_end

gFieldEffectScript_Unknown11:: @ 82DBB32
	field_eff_callnative oei_sweet_scent
	field_eff_end

gFieldEffectScript_BikeHopTallGrass:: @ 82DBB38
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_8154658
	field_eff_end

gFieldEffectScript_SandFootprints:: @ 82DBB42
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154B04
	field_eff_end

gFieldEffectScript_BikeHopBigSplash:: @ 82DBB4C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, oei_water_drop_tall
	field_eff_end

gFieldEffectScript_Splash:: @ 82DBB56
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154CEC
	field_eff_end

gFieldEffectScript_BikeHopSmallSplash:: @ 82DBB60
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154E1C
	field_eff_end

gFieldEffectScript_LongGrass:: @ 82DBB6A
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_8154758
	field_eff_end

gFieldEffectScript_Unknown18:: @ 82DBB74
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_81548FC
	field_eff_end

gFieldEffectScript_Unknown19:: @ 82DBB7E
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_81551F0
	field_eff_end

gFieldEffectScript_Unknown20:: @ 82DBB88
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_815525C
	field_eff_end

gFieldEffectScript_Unknown21:: @ 82DBB92
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_81552C8
	field_eff_end

gFieldEffectScript_Unknown22:: @ 82DBB9C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8155334
	field_eff_end

gFieldEffectScript_BerryTreeGrowthSparkle:: @ 82DBBA6
	field_eff_callnative sub_8155B2C
	field_eff_end

gFieldEffectScript_DeepSandFootprints:: @ 82DBBAC
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154B78
	field_eff_end

gFieldEffectScript_Unknown25:: @ 82DBBB6
	field_eff_loadfadedpal gFieldEffectObjectPaletteInfo4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_PokecenterHeal
	field_eff_end

gFieldEffectScript_Unknown26:: @ 82DBBC5
	field_eff_callnative sub_80FA208
	field_eff_end

gFieldEffectScript_Unknown27:: @ 82DBBCB
	field_eff_callnative sub_80FA36C
	field_eff_end

gFieldEffectScript_TreeDisguise:: @ 82DBBD1
	field_eff_callnative ShowTreeDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_MountainDisguise:: @ 82DBBD7
	field_eff_callnative ShowMountainDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_Unknown30:: @ 82DBBDD
	field_eff_callnative FldEff_NPCFlyOut
	field_eff_end

gFieldEffectScript_UseFly:: @ 82DBBE3
	field_eff_callnative FldEff_UseFly
	field_eff_end

gFieldEffectScript_FlyIn:: @ 82DBBE9
	field_eff_callnative FldEff_FlyIn
	field_eff_end

gFieldEffectScript_ExclamationMarkIcon2:: @ 82DBBEF
	field_eff_callnative FldEff_ExclamationMarkIcon2
	field_eff_end

gFieldEffectScript_FeetInFlowingWater:: @ 82DBBF5
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154EFC
	field_eff_end

gFieldEffectScript_BikeTireTracks:: @ 82DBBFF
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8154BEC
	field_eff_end

gFieldEffectScript_SandDisguisePlaceholder:: @ 82DBC09
	field_eff_callnative ShowSandDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_UseRockSmash:: @ 82DBC0F
	field_eff_callnative FldEff_UseRockSmash
	field_eff_end

gFieldEffectScript_Unknown40:: @ 82DBC15
	field_eff_callnative sub_8145E2C
	field_eff_end

gFieldEffectScript_Unknown38:: @ 82DBC1B
	field_eff_callnative FldEff_UseDig
	field_eff_end

gFieldEffectScript_Unknown39:: @ 82DBC21
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8155900
	field_eff_end

gFieldEffectScript_ShortGrass:: @ 82DBC2B
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_815496C
	field_eff_end

gFieldEffectScript_HotSpringsWater:: @ 82DBC35
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, sub_81550B4
	field_eff_end

gFieldEffectScript_Unknown43:: @ 82DBC3F
	field_eff_callnative FldEff_UseWaterfall
	field_eff_end

gFieldEffectScript_Unknown44:: @ 82DBC45
	field_eff_callnative FldEff_UseDive
	field_eff_end

gFieldEffectScript_Unknown45:: @ 82DBC4B
	field_eff_loadpal gFieldEffectObjectPaletteInfo10
	field_eff_callnative FldEff_Pokeball
	field_eff_end

gFieldEffectScript_HeartIcon:: @ 82DBC56
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_HeartIcon
	field_eff_end

gFieldEffectScript_Unknown47:: @ 82DBC60
	field_eff_callnative sub_80FA6FC
	field_eff_end

gFieldEffectScript_Unknown48:: @ 82DBC66
	field_eff_callnative sub_80FA700
	field_eff_end

gFieldEffectScript_JumpOutOfAsh:: @ 82DBC6C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo2, FldEff_PopOutOfAsh
	field_eff_end

gFieldEffectScript_Unknown50:: @ 82DBC76
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo2, FldEff_LavaridgeGymWarp
	field_eff_end

gFieldEffectScript_Unknown51:: @ 82DBC80
	field_eff_callnative FldEff_SweetScent
	field_eff_end

gFieldEffectScript_Unknown52:: @ 82DBC86
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo9, sub_80FAA7C
	field_eff_end

gFieldEffectScript_Bubbles:: @ 82DBC90
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, sub_8155A88
	field_eff_end

gFieldEffectScript_Unknown54:: @ 82DBC9A
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo3, sub_8155DDC
	field_eff_end

gFieldEffectScript_Unknown55:: @ 82DBCA4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo7, sub_80FA13C
	field_eff_end

gFieldEffectScript_Unknown56:: @ 82DBCAE
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo8, sub_80FA248
	field_eff_end

gFieldEffectScript_Unknown57:: @ 82DBCB8
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo8, sub_80FA3AC
	field_eff_end

gFieldEffectScript_Unknown58:: @ 82DBCC2
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo6, sub_80D3B00
	field_eff_end

gFieldEffectScript_FieldMoveShowMonInit:: @ 82DBCCC
	field_eff_callnative FldEff_FieldMoveShowMonInit
	field_eff_end

gFieldEffectScript_Unknown60:: @ 82DBCD2
	field_eff_callnative FldEff_UsePuzzleEffect
	field_eff_end

gFieldEffectScript_Unknown61:: @ 82DBCD8
	field_eff_callnative sub_80FA458
	field_eff_end

gFieldEffectScript_Unknown62:: @ 82DBCDE
	field_eff_loadfadedpal gFieldEffectObjectPaletteInfo4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo5, FldEff_HallOfFameRecord
	field_eff_end

gFieldEffectScript_Unknown63:: @ 82DBCED
	field_eff_callnative FldEff_UseTeleport
	field_eff_end

gFieldEffectScript_Rayquaza:: @ 82DBCF3
	field_eff_callnative sub_80B8F98
	field_eff_end

gFieldEffectScript_Unknown65:: @ 82DBCF9
	field_eff_callnative sub_80B9ADC
	field_eff_end

gFieldEffectScript_Unknown66:: @ 82DBCFF
	field_eff_callnative sub_80B9E28
	field_eff_end

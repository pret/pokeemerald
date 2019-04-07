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
	.4byte gFieldEffectScript_UseSecretPowerCave
	.4byte gFieldEffectScript_BikeHopTallGrass
	.4byte gFieldEffectScript_SandFootprints
	.4byte gFieldEffectScript_BikeHopBigSplash
	.4byte gFieldEffectScript_Splash
	.4byte gFieldEffectScript_BikeHopSmallSplash
	.4byte gFieldEffectScript_LongGrass
	.4byte gFieldEffectScript_JumpLongGrass
	.4byte gFieldEffectScript_Unknown19
	.4byte gFieldEffectScript_Unknown20
	.4byte gFieldEffectScript_Unknown21
	.4byte gFieldEffectScript_Unknown22
	.4byte gFieldEffectScript_BerryTreeGrowthSparkle
	.4byte gFieldEffectScript_DeepSandFootprints
	.4byte gFieldEffectScript_PokeCenterHeal
	.4byte gFieldEffectScript_UseSecretPowerTree
	.4byte gFieldEffectScript_UseSecretPowerShrub
	.4byte gFieldEffectScript_TreeDisguise
	.4byte gFieldEffectScript_MountainDisguise
	.4byte gFieldEffectScript_NPCUseFly
	.4byte gFieldEffectScript_UseFly
	.4byte gFieldEffectScript_FlyIn
	.4byte gFieldEffectScript_QuestionMarkIcon
	.4byte gFieldEffectScript_FeetInFlowingWater
	.4byte gFieldEffectScript_BikeTireTracks
	.4byte gFieldEffectScript_SandDisguisePlaceholder
	.4byte gFieldEffectScript_UseRockSmash
	.4byte gFieldEffectScript_UseDig
	.4byte gFieldEffectScript_SandPile
	.4byte gFieldEffectScript_UseStrength
	.4byte gFieldEffectScript_ShortGrass
	.4byte gFieldEffectScript_HotSpringsWater
	.4byte gFieldEffectScript_UseWaterfall
	.4byte gFieldEffectScript_UseDive
	.4byte gFieldEffectScript_Pokeball
	.4byte gFieldEffectScript_HeartIcon
	.4byte gFieldEffectScript_Unknown47
	.4byte gFieldEffectScript_Unknown48
	.4byte gFieldEffectScript_JumpOutOfAsh
	.4byte gFieldEffectScript_LavaridgeGymWarp
	.4byte gFieldEffectScript_SweetScent
	.4byte gFieldEffectScript_SandPillar
	.4byte gFieldEffectScript_Bubbles
	.4byte gFieldEffectScript_Sparkle
	.4byte gFieldEffectScript_ShowSecretPowerCave
	.4byte gFieldEffectScript_ShowSecretPowerTree
	.4byte gFieldEffectScript_ShowSecretPowerShrub
	.4byte gFieldEffectScript_ShowCutGrass
	.4byte gFieldEffectScript_FieldMoveShowMonInit
	.4byte gFieldEffectScript_UsePuzzleEffect
	.4byte gFieldEffectScript_SecretBaseBootPC
	.4byte gFieldEffectScript_HallOfFameRecord
	.4byte gFieldEffectScript_UseTeleport
	.4byte gFieldEffectScript_Rayquaza
	.4byte gFieldEffectScript_Unknown65
	.4byte gFieldEffectScript_MoveDeoxysRock

gFieldEffectScript_ExclamationMarkIcon1:: @ 82DBAE0
	field_eff_callnative FldEff_ExclamationMarkIcon
	field_eff_end

gFieldEffectScript_UseCutOnTallGrass:: @ 82DBAE6
	field_eff_callnative FldEff_UseCutOnGrass
	field_eff_end

gFieldEffectScript_UseCutOnTree:: @ 82DBAEC
	field_eff_callnative FldEff_UseCutOnTree
	field_eff_end

gFieldEffectScript_Shadow:: @ 82DBAF2
	field_eff_callnative FldEff_Shadow
	field_eff_end

gFieldEffectScript_TallGrass:: @ 82DBAF8
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_TallGrass
	field_eff_end

gFieldEffectScript_Ripple:: @ 82DBB02
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_Ripple
	field_eff_end

gFieldEffectScript_FieldMoveShowMon:: @ 82DBB0C
	field_eff_callnative FldEff_FieldMoveShowMon
	field_eff_end

gFieldEffectScript_Ash:: @ 82DBB12
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_Ash
	field_eff_end

gFieldEffectScript_SurfBlob:: @ 82DBB1C
	field_eff_callnative FldEff_SurfBlob
	field_eff_end

gFieldEffectScript_UseSurf:: @ 82DBB22
	field_eff_callnative FldEff_UseSurf
	field_eff_end

gFieldEffectScript_GroundImpactDust:: @ 82DBB28
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_Dust
	field_eff_end

gFieldEffectScript_UseSecretPowerCave:: @ 82DBB32
	field_eff_callnative FldEff_UseSecretPowerCave
	field_eff_end

gFieldEffectScript_BikeHopTallGrass:: @ 82DBB38
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_JumpTallGrass
	field_eff_end

gFieldEffectScript_SandFootprints:: @ 82DBB42
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_SandFootprints
	field_eff_end

gFieldEffectScript_BikeHopBigSplash:: @ 82DBB4C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_JumpBigSplash
	field_eff_end

gFieldEffectScript_Splash:: @ 82DBB56
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_Splash
	field_eff_end

gFieldEffectScript_BikeHopSmallSplash:: @ 82DBB60
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_JumpSmallSplash
	field_eff_end

gFieldEffectScript_LongGrass:: @ 82DBB6A
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_LongGrass
	field_eff_end

gFieldEffectScript_JumpLongGrass:: @ 82DBB74
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_JumpLongGrass
	field_eff_end

gFieldEffectScript_Unknown19:: @ 82DBB7E
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_Unknown19
	field_eff_end

gFieldEffectScript_Unknown20:: @ 82DBB88
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_Unknown20
	field_eff_end

gFieldEffectScript_Unknown21:: @ 82DBB92
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_Unknown21
	field_eff_end

gFieldEffectScript_Unknown22:: @ 82DBB9C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_Unknown22
	field_eff_end

gFieldEffectScript_BerryTreeGrowthSparkle:: @ 82DBBA6
	field_eff_callnative FldEff_BerryTreeGrowthSparkle
	field_eff_end

gFieldEffectScript_DeepSandFootprints:: @ 82DBBAC
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_DeepSandFootprints
	field_eff_end

gFieldEffectScript_PokeCenterHeal:: @ 82DBBB6
	field_eff_loadfadedpal gFieldEffectObjectPaletteInfo4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_PokecenterHeal
	field_eff_end

gFieldEffectScript_UseSecretPowerTree:: @ 82DBBC5
	field_eff_callnative FldEff_UseSecretPowerTree
	field_eff_end

gFieldEffectScript_UseSecretPowerShrub:: @ 82DBBCB
	field_eff_callnative FldEff_UseSecretPowerShrub
	field_eff_end

gFieldEffectScript_TreeDisguise:: @ 82DBBD1
	field_eff_callnative ShowTreeDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_MountainDisguise:: @ 82DBBD7
	field_eff_callnative ShowMountainDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_NPCUseFly:: @ 82DBBDD
	field_eff_callnative FldEff_NPCFlyOut
	field_eff_end

gFieldEffectScript_UseFly:: @ 82DBBE3
	field_eff_callnative FldEff_UseFly
	field_eff_end

gFieldEffectScript_FlyIn:: @ 82DBBE9
	field_eff_callnative FldEff_FlyIn
	field_eff_end

gFieldEffectScript_QuestionMarkIcon:: @ 82DBBEF
	field_eff_callnative FldEff_QuestionMarkIcon
	field_eff_end

gFieldEffectScript_FeetInFlowingWater:: @ 82DBBF5
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_FeetInFlowingWater
	field_eff_end

gFieldEffectScript_BikeTireTracks:: @ 82DBBFF
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_BikeTireTracks
	field_eff_end

gFieldEffectScript_SandDisguisePlaceholder:: @ 82DBC09
	field_eff_callnative ShowSandDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_UseRockSmash:: @ 82DBC0F
	field_eff_callnative FldEff_UseRockSmash
	field_eff_end

gFieldEffectScript_UseStrength:: @ 82DBC15
	field_eff_callnative sub_8145E2C
	field_eff_end

gFieldEffectScript_UseDig:: @ 82DBC1B
	field_eff_callnative FldEff_UseDig
	field_eff_end

gFieldEffectScript_SandPile:: @ 82DBC21
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_SandPile
	field_eff_end

gFieldEffectScript_ShortGrass:: @ 82DBC2B
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_ShortGrass
	field_eff_end

gFieldEffectScript_HotSpringsWater:: @ 82DBC35
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo1, FldEff_HotSpringsWater
	field_eff_end

gFieldEffectScript_UseWaterfall:: @ 82DBC3F
	field_eff_callnative FldEff_UseWaterfall
	field_eff_end

gFieldEffectScript_UseDive:: @ 82DBC45
	field_eff_callnative FldEff_UseDive
	field_eff_end

gFieldEffectScript_Pokeball:: @ 82DBC4B
	field_eff_loadpal gFieldEffectObjectPaletteInfo10
	field_eff_callnative FldEff_Pokeball
	field_eff_end

gFieldEffectScript_HeartIcon:: @ 82DBC56
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_HeartIcon
	field_eff_end

gFieldEffectScript_Unknown47:: @ 82DBC60
	field_eff_callnative FldEff_NopA6FC
	field_eff_end

gFieldEffectScript_Unknown48:: @ 82DBC66
	field_eff_callnative FldEff_NopA700
	field_eff_end

gFieldEffectScript_JumpOutOfAsh:: @ 82DBC6C
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo2, FldEff_PopOutOfAsh
	field_eff_end

gFieldEffectScript_LavaridgeGymWarp:: @ 82DBC76
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo2, FldEff_LavaridgeGymWarp
	field_eff_end

gFieldEffectScript_SweetScent:: @ 82DBC80
	field_eff_callnative FldEff_SweetScent
	field_eff_end

gFieldEffectScript_SandPillar:: @ 82DBC86
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo9, FldEff_SandPillar
	field_eff_end

gFieldEffectScript_Bubbles:: @ 82DBC90
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo0, FldEff_Bubbles
	field_eff_end

gFieldEffectScript_Sparkle:: @ 82DBC9A
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo3, FldEff_Sparkle
	field_eff_end

gFieldEffectScript_ShowSecretPowerCave:: @ 82DBCA4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo7, FldEff_SecretPowerCave
	field_eff_end

gFieldEffectScript_ShowSecretPowerTree:: @ 82DBCAE
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo8, FldEff_SecretPowerTree
	field_eff_end

gFieldEffectScript_ShowSecretPowerShrub:: @ 82DBCB8
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo8, FldEff_SecretPowerShrub
	field_eff_end

gFieldEffectScript_ShowCutGrass:: @ 82DBCC2
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo6, FldEff_CutGrass
	field_eff_end

gFieldEffectScript_FieldMoveShowMonInit:: @ 82DBCCC
	field_eff_callnative FldEff_FieldMoveShowMonInit
	field_eff_end

gFieldEffectScript_UsePuzzleEffect:: @ 82DBCD2
	field_eff_callnative FldEff_UsePuzzleEffect
	field_eff_end

gFieldEffectScript_SecretBaseBootPC:: @ 82DBCD8
	field_eff_callnative FldEff_SecretBasePCTurnOn
	field_eff_end

gFieldEffectScript_HallOfFameRecord:: @ 82DBCDE
	field_eff_loadfadedpal gFieldEffectObjectPaletteInfo4
	field_eff_loadfadedpal_callnative gFieldEffectObjectPaletteInfo5, FldEff_HallOfFameRecord
	field_eff_end

gFieldEffectScript_UseTeleport:: @ 82DBCED
	field_eff_callnative FldEff_UseTeleport
	field_eff_end

gFieldEffectScript_Rayquaza:: @ 82DBCF3
	field_eff_callnative sub_80B8F98
	field_eff_end

gFieldEffectScript_Unknown65:: @ 82DBCF9
	field_eff_callnative sub_80B9ADC
	field_eff_end

gFieldEffectScript_MoveDeoxysRock:: @ 82DBCFF
	field_eff_callnative Fldeff_MoveDeoxysRock
	field_eff_end

	.align 2, 0

gItems: ; 85839A0
	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MASTER BALL$", 14
	.2byte ITEM_MASTER_BALL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMasterBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 0
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 0

	.charmapstr "ULTRA BALL$", 14
	.2byte ITEM_ULTRA_BALL
	.2byte 1200 ; price
	.byte 0
	.byte 0
	.4byte gUltraBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 1
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 1

	.charmapstr "GREAT BALL$", 14
	.2byte ITEM_GREAT_BALL
	.2byte 600 ; price
	.byte 0
	.byte 0
	.4byte gGreatBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 2
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 2

	.charmapstr "POKé BALL$", 14
	.2byte ITEM_POKE_BALL
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gPokeBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 3
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 3

	.charmapstr "SAFARI BALL$", 14
	.2byte ITEM_SAFARI_BALL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSafariBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 4
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 4

	.charmapstr "NET BALL$", 14
	.2byte ITEM_NET_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gNetBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 5
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 5

	.charmapstr "DIVE BALL$", 14
	.2byte ITEM_DIVE_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gDiveBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 6
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 6

	.charmapstr "NEST BALL$", 14
	.2byte ITEM_NEST_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gNestBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 7
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 7

	.charmapstr "REPEAT BALL$", 14
	.2byte ITEM_REPEAT_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gRepeatBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 8
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 8

	.charmapstr "TIMER BALL$", 14
	.2byte ITEM_TIMER_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gTimerBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 9
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 9

	.charmapstr "LUXURY BALL$", 14
	.2byte ITEM_LUXURY_BALL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gLuxuryBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 10
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 10

	.charmapstr "PREMIER BALL$", 14
	.2byte ITEM_PREMIER_BALL
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gPremierBallItemDescription
	.2byte 0
	.byte POCKET_POKE_BALLS
	.byte 11
	.4byte NULL
	.4byte 2
	.4byte item_in_battle_func_pokeball
	.4byte 11

	.charmapstr "POTION$", 14
	.2byte ITEM_POTION
	.2byte 300 ; price
	.byte 0
	.byte 20
	.4byte gPotionItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ANTIDOTE$", 14
	.2byte ITEM_ANTIDOTE
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gAntidoteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "BURN HEAL$", 14
	.2byte ITEM_BURN_HEAL
	.2byte 250 ; price
	.byte 0
	.byte 0
	.4byte gBurnHealItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ICE HEAL$", 14
	.2byte ITEM_ICE_HEAL
	.2byte 250 ; price
	.byte 0
	.byte 0
	.4byte gIceHealItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "AWAKENING$", 14
	.2byte ITEM_AWAKENING
	.2byte 250 ; price
	.byte 0
	.byte 0
	.4byte gAwakeningItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "PARLYZ HEAL$", 14
	.2byte ITEM_PARALYZE_HEAL
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gParalyzeHealItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "FULL RESTORE$", 14
	.2byte ITEM_FULL_RESTORE
	.2byte 3000 ; price
	.byte 0
	.byte 255
	.4byte gFullRestoreItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "MAX POTION$", 14
	.2byte ITEM_MAX_POTION
	.2byte 2500 ; price
	.byte 0
	.byte 255
	.4byte gMaxPotionItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "HYPER POTION$", 14
	.2byte ITEM_HYPER_POTION
	.2byte 1200 ; price
	.byte 0
	.byte 200
	.4byte gHyperPotionItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "SUPER POTION$", 14
	.2byte ITEM_SUPER_POTION
	.2byte 700 ; price
	.byte 0
	.byte 50
	.4byte gSuperPotionItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "FULL HEAL$", 14
	.2byte ITEM_FULL_HEAL
	.2byte 600 ; price
	.byte 0
	.byte 0
	.4byte gFullHealItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "REVIVE$", 14
	.2byte ITEM_REVIVE
	.2byte 1500 ; price
	.byte 0
	.byte 0
	.4byte gReviveItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "MAX REVIVE$", 14
	.2byte ITEM_MAX_REVIVE
	.2byte 4000 ; price
	.byte 0
	.byte 0
	.4byte gMaxReviveItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "FRESH WATER$", 14
	.2byte ITEM_FRESH_WATER
	.2byte 200 ; price
	.byte 0
	.byte 50
	.4byte gFreshWaterItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "SODA POP$", 14
	.2byte ITEM_SODA_POP
	.2byte 300 ; price
	.byte 0
	.byte 60
	.4byte gSodaPopItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "LEMONADE$", 14
	.2byte ITEM_LEMONADE
	.2byte 350 ; price
	.byte 0
	.byte 80
	.4byte gLemonadeItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "MOOMOO MILK$", 14
	.2byte ITEM_MOOMOO_MILK
	.2byte 500 ; price
	.byte 0
	.byte 100
	.4byte gMoomooMilkItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ENERGYPOWDER$", 14
	.2byte ITEM_ENERGY_POWDER
	.2byte 500 ; price
	.byte 0
	.byte 0
	.4byte gEnergyPowderItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ENERGY ROOT$", 14
	.2byte ITEM_ENERGY_ROOT
	.2byte 800 ; price
	.byte 0
	.byte 0
	.4byte gEnergyRootItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "HEAL POWDER$", 14
	.2byte ITEM_HEAL_POWDER
	.2byte 450 ; price
	.byte 0
	.byte 0
	.4byte gHealPowderItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "REVIVAL HERB$", 14
	.2byte ITEM_REVIVAL_HERB
	.2byte 2800 ; price
	.byte 0
	.byte 0
	.4byte gRevivalHerbItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ETHER$", 14
	.2byte ITEM_ETHER
	.2byte 1200 ; price
	.byte 0
	.byte 10
	.4byte gEtherItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_pp_recovery_item
	.4byte 1
	.4byte item_in_battle_func_pp_recovery_item
	.4byte 0

	.charmapstr "MAX ETHER$", 14
	.2byte ITEM_MAX_ETHER
	.2byte 2000 ; price
	.byte 0
	.byte 255
	.4byte gMaxEtherItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_pp_recovery_item
	.4byte 1
	.4byte item_in_battle_func_pp_recovery_item
	.4byte 0

	.charmapstr "ELIXIR$", 14
	.2byte ITEM_ELIXIR
	.2byte 3000 ; price
	.byte 0
	.byte 10
	.4byte gElixirItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_pp_recovery_item
	.4byte 1
	.4byte item_in_battle_func_pp_recovery_item
	.4byte 0

	.charmapstr "MAX ELIXIR$", 14
	.2byte ITEM_MAX_ELIXIR
	.2byte 4500 ; price
	.byte 0
	.byte 255
	.4byte gMaxElixirItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_pp_recovery_item
	.4byte 1
	.4byte item_in_battle_func_pp_recovery_item
	.4byte 0

	.charmapstr "LAVA COOKIE$", 14
	.2byte ITEM_LAVA_COOKIE
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gLavaCookieItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "BLUE FLUTE$", 14
	.2byte ITEM_BLUE_FLUTE
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gBlueFluteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "YELLOW FLUTE$", 14
	.2byte ITEM_YELLOW_FLUTE
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gYellowFluteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_cannot_use
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "RED FLUTE$", 14
	.2byte ITEM_RED_FLUTE
	.2byte 300 ; price
	.byte 0
	.byte 0
	.4byte gRedFluteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_cannot_use
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "BLACK FLUTE$", 14
	.2byte ITEM_BLACK_FLUTE
	.2byte 400 ; price
	.byte 0
	.byte 50
	.4byte gBlackFluteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_black_white_flutes
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WHITE FLUTE$", 14
	.2byte ITEM_WHITE_FLUTE
	.2byte 500 ; price
	.byte 0
	.byte 150
	.4byte gWhiteFluteItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_black_white_flutes
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BERRY JUICE$", 14
	.2byte ITEM_BERRY_JUICE
	.2byte 100 ; price
	.byte 1
	.byte 20
	.4byte gBerryJuiceItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "SACRED ASH$", 14
	.2byte ITEM_SACRED_ASH
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gSacredAshItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_in_battle_func_sacred_ash
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SHOAL SALT$", 14
	.2byte ITEM_SHOAL_SALT
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gShoalSaltItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SHOAL SHELL$", 14
	.2byte ITEM_SHOAL_SHELL
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gShoalShellItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RED SHARD$", 14
	.2byte ITEM_RED_SHARD
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gRedShardItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLUE SHARD$", 14
	.2byte ITEM_BLUE_SHARD
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gBlueShardItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "YELLOW SHARD$", 14
	.2byte ITEM_YELLOW_SHARD
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gYellowShardItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GREEN SHARD$", 14
	.2byte ITEM_GREEN_SHARD
	.2byte 200 ; price
	.byte 0
	.byte 0
	.4byte gGreenShardItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HP UP$", 14
	.2byte ITEM_HP_UP
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gHPUpItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PROTEIN$", 14
	.2byte ITEM_PROTEIN
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gProteinItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "IRON$", 14
	.2byte ITEM_IRON
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gIronItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CARBOS$", 14
	.2byte ITEM_CARBOS
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gCarbosItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CALCIUM$", 14
	.2byte ITEM_CALCIUM
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gCalciumItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RARE CANDY$", 14
	.2byte ITEM_RARE_CANDY
	.2byte 4800 ; price
	.byte 0
	.byte 0
	.4byte gRareCandyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FDF2C
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PP UP$", 14
	.2byte ITEM_PP_UP
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gPPUpItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FDF10
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ZINC$", 14
	.2byte ITEM_ZINC
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gZincItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PP MAX$", 14
	.2byte ITEM_PP_MAX
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gPPMaxItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FDF10
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GUARD SPEC.$", 14
	.2byte ITEM_GUARD_SPEC
	.2byte 700 ; price
	.byte 0
	.byte 0
	.4byte gGuardSpecItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "DIRE HIT$", 14
	.2byte ITEM_DIRE_HIT
	.2byte 650 ; price
	.byte 0
	.byte 0
	.4byte gDireHitItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "X ATTACK$", 14
	.2byte ITEM_X_ATTACK
	.2byte 500 ; price
	.byte 0
	.byte 0
	.4byte gXAttackItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "X DEFEND$", 14
	.2byte ITEM_X_DEFEND
	.2byte 550 ; price
	.byte 0
	.byte 0
	.4byte gXDefendItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "X SPEED$", 14
	.2byte ITEM_X_SPEED
	.2byte 350 ; price
	.byte 0
	.byte 0
	.4byte gXSpeedItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "X ACCURACY$", 14
	.2byte ITEM_X_ACCURACY
	.2byte 950 ; price
	.byte 0
	.byte 0
	.4byte gXAccuracyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "X SPECIAL$", 14
	.2byte ITEM_X_SPECIAL
	.2byte 350 ; price
	.byte 0
	.byte 0
	.4byte gXSpecialItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte status_incr_battle
	.4byte 0

	.charmapstr "POKé DOLL$", 14
	.2byte ITEM_POKE_DOLL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gPokeDollItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte sub_80FE5E4
	.4byte 0

	.charmapstr "FLUFFY TAIL$", 14
	.2byte ITEM_FLUFFY_TAIL
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gFluffyTailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 2
	.4byte sub_80FE5E4
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SUPER REPEL$", 14
	.2byte ITEM_SUPER_REPEL
	.2byte 500 ; price
	.byte 0
	.byte 200
	.4byte gSuperRepelItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte sub_80FE0BC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MAX REPEL$", 14
	.2byte ITEM_MAX_REPEL
	.2byte 700 ; price
	.byte 0
	.byte 250
	.4byte gMaxRepelItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte sub_80FE0BC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ESCAPE ROPE$", 14
	.2byte ITEM_ESCAPE_ROPE
	.2byte 550 ; price
	.byte 0
	.byte 0
	.4byte gEscapeRopeItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 2
	.4byte sub_80FE334
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "REPEL$", 14
	.2byte ITEM_REPEL
	.2byte 350 ; price
	.byte 0
	.byte 100
	.4byte gRepelItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte sub_80FE0BC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SUN STONE$", 14
	.2byte ITEM_SUN_STONE
	.2byte 2100 ; price
	.byte 0
	.byte 0
	.4byte gSunStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MOON STONE$", 14
	.2byte ITEM_MOON_STONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMoonStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "FIRE STONE$", 14
	.2byte ITEM_FIRE_STONE
	.2byte 2100 ; price
	.byte 0
	.byte 0
	.4byte gFireStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "THUNDERSTONE$", 14
	.2byte ITEM_THUNDER_STONE
	.2byte 2100 ; price
	.byte 0
	.byte 0
	.4byte gThunderStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WATER STONE$", 14
	.2byte ITEM_WATER_STONE
	.2byte 2100 ; price
	.byte 0
	.byte 0
	.4byte gWaterStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LEAF STONE$", 14
	.2byte ITEM_LEAF_STONE
	.2byte 2100 ; price
	.byte 0
	.byte 0
	.4byte gLeafStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte sub_80FE378
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TINYMUSHROOM$", 14
	.2byte ITEM_TINY_MUSHROOM
	.2byte 500 ; price
	.byte 0
	.byte 0
	.4byte gTinyMushroomItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BIG MUSHROOM$", 14
	.2byte ITEM_BIG_MUSHROOM
	.2byte 5000 ; price
	.byte 0
	.byte 0
	.4byte gBigMushroomItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PEARL$", 14
	.2byte ITEM_PEARL
	.2byte 1400 ; price
	.byte 0
	.byte 0
	.4byte gPearlItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BIG PEARL$", 14
	.2byte ITEM_BIG_PEARL
	.2byte 7500 ; price
	.byte 0
	.byte 0
	.4byte gBigPearlItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "STARDUST$", 14
	.2byte ITEM_STARDUST
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gStardustItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "STAR PIECE$", 14
	.2byte ITEM_STAR_PIECE
	.2byte 9800 ; price
	.byte 0
	.byte 0
	.4byte gStarPieceItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "NUGGET$", 14
	.2byte ITEM_NUGGET
	.2byte 10000 ; price
	.byte 0
	.byte 0
	.4byte gNuggetItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HEART SCALE$", 14
	.2byte ITEM_HEART_SCALE
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gHeartScaleItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ORANGE MAIL$", 14
	.2byte ITEM_ORANGE_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gOrangeMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HARBOR MAIL$", 14
	.2byte ITEM_HARBOR_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gHarborMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 1

	.charmapstr "GLITTER MAIL$", 14
	.2byte ITEM_GLITTER_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gGlitterMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 2

	.charmapstr "MECH MAIL$", 14
	.2byte ITEM_MECH_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gMechMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 3

	.charmapstr "WOOD MAIL$", 14
	.2byte ITEM_WOOD_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gWoodMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 4

	.charmapstr "WAVE MAIL$", 14
	.2byte ITEM_WAVE_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gWaveMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 5

	.charmapstr "BEAD MAIL$", 14
	.2byte ITEM_BEAD_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gBeadMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 6

	.charmapstr "SHADOW MAIL$", 14
	.2byte ITEM_SHADOW_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gShadowMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 7

	.charmapstr "TROPIC MAIL$", 14
	.2byte ITEM_TROPIC_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gTropicMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 8

	.charmapstr "DREAM MAIL$", 14
	.2byte ITEM_DREAM_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gDreamMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 9

	.charmapstr "FAB MAIL$", 14
	.2byte ITEM_FAB_MAIL
	.2byte 50 ; price
	.byte 0
	.byte 0
	.4byte gFabMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 10

	.charmapstr "RETRO MAIL$", 14
	.2byte ITEM_RETRO_MAIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRetroMailItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte sub_80FD278
	.4byte 0
	.4byte NULL
	.4byte 11

	.charmapstr "CHERI BERRY$", 14
	.2byte ITEM_CHERI_BERRY
	.2byte 20 ; price
	.byte 2
	.byte 0
	.4byte gCheriBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "CHESTO BERRY$", 14
	.2byte ITEM_CHESTO_BERRY
	.2byte 20 ; price
	.byte 3
	.byte 0
	.4byte gChestoBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "PECHA BERRY$", 14
	.2byte ITEM_PECHA_BERRY
	.2byte 20 ; price
	.byte 4
	.byte 0
	.4byte gPechaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "RAWST BERRY$", 14
	.2byte ITEM_RAWST_BERRY
	.2byte 20 ; price
	.byte 5
	.byte 0
	.4byte gRawstBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "ASPEAR BERRY$", 14
	.2byte ITEM_ASPEAR_BERRY
	.2byte 20 ; price
	.byte 6
	.byte 0
	.4byte gAspearBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "LEPPA BERRY$", 14
	.2byte ITEM_LEPPA_BERRY
	.2byte 20 ; price
	.byte 7
	.byte 10
	.4byte gLeppaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_pp_recovery_item
	.4byte 1
	.4byte item_in_battle_func_pp_recovery_item
	.4byte 0

	.charmapstr "ORAN BERRY$", 14
	.2byte ITEM_ORAN_BERRY
	.2byte 20 ; price
	.byte 1
	.byte 10
	.4byte gOranBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "PERSIM BERRY$", 14
	.2byte ITEM_PERSIM_BERRY
	.2byte 20 ; price
	.byte 8
	.byte 0
	.4byte gPersimBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "LUM BERRY$", 14
	.2byte ITEM_LUM_BERRY
	.2byte 20 ; price
	.byte 9
	.byte 0
	.4byte gLumBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "SITRUS BERRY$", 14
	.2byte ITEM_SITRUS_BERRY
	.2byte 20 ; price
	.byte 1
	.byte 30
	.4byte gSitrusBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte item_field_func_recovery_item
	.4byte 1
	.4byte item_in_battle_func_recovery_item
	.4byte 0

	.charmapstr "FIGY BERRY$", 14
	.2byte ITEM_FIGY_BERRY
	.2byte 20 ; price
	.byte 10
	.byte 8
	.4byte gFigyBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WIKI BERRY$", 14
	.2byte ITEM_WIKI_BERRY
	.2byte 20 ; price
	.byte 11
	.byte 8
	.4byte gWikiBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MAGO BERRY$", 14
	.2byte ITEM_MAGO_BERRY
	.2byte 20 ; price
	.byte 12
	.byte 8
	.4byte gMagoBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "AGUAV BERRY$", 14
	.2byte ITEM_AGUAV_BERRY
	.2byte 20 ; price
	.byte 13
	.byte 8
	.4byte gAguavBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "IAPAPA BERRY$", 14
	.2byte ITEM_IAPAPA_BERRY
	.2byte 20 ; price
	.byte 14
	.byte 8
	.4byte gIapapaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RAZZ BERRY$", 14
	.2byte ITEM_RAZZ_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gRazzBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLUK BERRY$", 14
	.2byte ITEM_BLUK_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gBlukBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "NANAB BERRY$", 14
	.2byte ITEM_NANAB_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gNanabBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WEPEAR BERRY$", 14
	.2byte ITEM_WEPEAR_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gWepearBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PINAP BERRY$", 14
	.2byte ITEM_PINAP_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gPinapBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "POMEG BERRY$", 14
	.2byte ITEM_POMEG_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gPomegBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "KELPSY BERRY$", 14
	.2byte ITEM_KELPSY_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gKelpsyBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "QUALOT BERRY$", 14
	.2byte ITEM_QUALOT_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gQualotBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HONDEW BERRY$", 14
	.2byte ITEM_HONDEW_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gHondewBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GREPA BERRY$", 14
	.2byte ITEM_GREPA_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gGrepaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TAMATO BERRY$", 14
	.2byte ITEM_TAMATO_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gTamatoBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte sub_80FDEBC
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CORNN BERRY$", 14
	.2byte ITEM_CORNN_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gCornnBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MAGOST BERRY$", 14
	.2byte ITEM_MAGOST_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gMagostBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RABUTA BERRY$", 14
	.2byte ITEM_RABUTA_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gRabutaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "NOMEL BERRY$", 14
	.2byte ITEM_NOMEL_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gNomelBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SPELON BERRY$", 14
	.2byte ITEM_SPELON_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gSpelonBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PAMTRE BERRY$", 14
	.2byte ITEM_PAMTRE_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gPamtreBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WATMEL BERRY$", 14
	.2byte ITEM_WATMEL_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gWatmelBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DURIN BERRY$", 14
	.2byte ITEM_DURIN_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gDurinBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BELUE BERRY$", 14
	.2byte ITEM_BELUE_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gBelueBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LIECHI BERRY$", 14
	.2byte ITEM_LIECHI_BERRY
	.2byte 20 ; price
	.byte 15
	.byte 4
	.4byte gLiechiBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GANLON BERRY$", 14
	.2byte ITEM_GANLON_BERRY
	.2byte 20 ; price
	.byte 16
	.byte 4
	.4byte gGanlonBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SALAC BERRY$", 14
	.2byte ITEM_SALAC_BERRY
	.2byte 20 ; price
	.byte 17
	.byte 4
	.4byte gSalacBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PETAYA BERRY$", 14
	.2byte ITEM_PETAYA_BERRY
	.2byte 20 ; price
	.byte 18
	.byte 4
	.4byte gPetayaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "APICOT BERRY$", 14
	.2byte ITEM_APICOT_BERRY
	.2byte 20 ; price
	.byte 19
	.byte 4
	.4byte gApicotBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LANSAT BERRY$", 14
	.2byte ITEM_LANSAT_BERRY
	.2byte 20 ; price
	.byte 20
	.byte 4
	.4byte gLansatBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "STARF BERRY$", 14
	.2byte ITEM_STARF_BERRY
	.2byte 20 ; price
	.byte 21
	.byte 4
	.4byte gStarfBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ENIGMA BERRY$", 14
	.2byte ITEM_ENIGMA_BERRY
	.2byte 20 ; price
	.byte 0
	.byte 0
	.4byte gEnigmaBerryItemDescription
	.2byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte sub_80FE650
	.4byte 1
	.4byte sub_80FE77C
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BRIGHTPOWDER$", 14
	.2byte ITEM_BRIGHT_POWDER
	.2byte 10 ; price
	.byte 22
	.byte 10
	.4byte gBrightPowderItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WHITE HERB$", 14
	.2byte ITEM_WHITE_HERB
	.2byte 100 ; price
	.byte 23
	.byte 0
	.4byte gWhiteHerbItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MACHO BRACE$", 14
	.2byte ITEM_MACHO_BRACE
	.2byte 3000 ; price
	.byte 24
	.byte 0
	.4byte gMachoBraceItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "EXP. SHARE$", 14
	.2byte ITEM_EXP_SHARE
	.2byte 3000 ; price
	.byte 25
	.byte 0
	.4byte gExpShareItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "QUICK CLAW$", 14
	.2byte ITEM_QUICK_CLAW
	.2byte 100 ; price
	.byte 26
	.byte 20
	.4byte gQuickClawItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SOOTHE BELL$", 14
	.2byte ITEM_SOOTHE_BELL
	.2byte 100 ; price
	.byte 27
	.byte 0
	.4byte gSootheBellItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MENTAL HERB$", 14
	.2byte ITEM_MENTAL_HERB
	.2byte 100 ; price
	.byte 28
	.byte 0
	.4byte gMentalHerbItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CHOICE BAND$", 14
	.2byte ITEM_CHOICE_BAND
	.2byte 100 ; price
	.byte 29
	.byte 0
	.4byte gChoiceBandItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "KING’S ROCK$", 14
	.2byte ITEM_KINGS_ROCK
	.2byte 100 ; price
	.byte 30
	.byte 10
	.4byte gKingsRockItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SILVERPOWDER$", 14
	.2byte ITEM_SILVER_POWDER
	.2byte 100 ; price
	.byte 31
	.byte 10
	.4byte gSilverPowderItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "AMULET COIN$", 14
	.2byte ITEM_AMULET_COIN
	.2byte 100 ; price
	.byte 32
	.byte 10
	.4byte gAmuletCoinItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CLEANSE TAG$", 14
	.2byte ITEM_CLEANSE_TAG
	.2byte 200 ; price
	.byte 33
	.byte 0
	.4byte gCleanseTagItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SOUL DEW$", 14
	.2byte ITEM_SOUL_DEW
	.2byte 200 ; price
	.byte 34
	.byte 0
	.4byte gSoulDewItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DEEPSEATOOTH$", 14
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte 200 ; price
	.byte 35
	.byte 0
	.4byte gDeepSeaToothItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DEEPSEASCALE$", 14
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte 200 ; price
	.byte 36
	.byte 0
	.4byte gDeepSeaScaleItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SMOKE BALL$", 14
	.2byte ITEM_SMOKE_BALL
	.2byte 200 ; price
	.byte 37
	.byte 0
	.4byte gSmokeBallItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "EVERSTONE$", 14
	.2byte ITEM_EVERSTONE
	.2byte 200 ; price
	.byte 38
	.byte 0
	.4byte gEverstoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "FOCUS BAND$", 14
	.2byte ITEM_FOCUS_BAND
	.2byte 200 ; price
	.byte 39
	.byte 10
	.4byte gFocusBandItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LUCKY EGG$", 14
	.2byte ITEM_LUCKY_EGG
	.2byte 200 ; price
	.byte 40
	.byte 0
	.4byte gLuckyEggItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SCOPE LENS$", 14
	.2byte ITEM_SCOPE_LENS
	.2byte 200 ; price
	.byte 41
	.byte 0
	.4byte gScopeLensItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "METAL COAT$", 14
	.2byte ITEM_METAL_COAT
	.2byte 100 ; price
	.byte 42
	.byte 10
	.4byte gMetalCoatItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LEFTOVERS$", 14
	.2byte ITEM_LEFTOVERS
	.2byte 200 ; price
	.byte 43
	.byte 10
	.4byte gLeftoversItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DRAGON SCALE$", 14
	.2byte ITEM_DRAGON_SCALE
	.2byte 2100 ; price
	.byte 44
	.byte 10
	.4byte gDragonScaleItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LIGHT BALL$", 14
	.2byte ITEM_LIGHT_BALL
	.2byte 100 ; price
	.byte 45
	.byte 0
	.4byte gLightBallItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SOFT SAND$", 14
	.2byte ITEM_SOFT_SAND
	.2byte 100 ; price
	.byte 46
	.byte 10
	.4byte gSoftSandItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HARD STONE$", 14
	.2byte ITEM_HARD_STONE
	.2byte 100 ; price
	.byte 47
	.byte 10
	.4byte gHardStoneItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MIRACLE SEED$", 14
	.2byte ITEM_MIRACLE_SEED
	.2byte 100 ; price
	.byte 48
	.byte 10
	.4byte gMiracleSeedItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLACKGLASSES$", 14
	.2byte ITEM_BLACK_GLASSES
	.2byte 100 ; price
	.byte 49
	.byte 10
	.4byte gBlackGlassesItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLACK BELT$", 14
	.2byte ITEM_BLACK_BELT
	.2byte 100 ; price
	.byte 50
	.byte 10
	.4byte gBlackBeltItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MAGNET$", 14
	.2byte ITEM_MAGNET
	.2byte 100 ; price
	.byte 51
	.byte 10
	.4byte gMagnetItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MYSTIC WATER$", 14
	.2byte ITEM_MYSTIC_WATER
	.2byte 100 ; price
	.byte 52
	.byte 10
	.4byte gMysticWaterItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SHARP BEAK$", 14
	.2byte ITEM_SHARP_BEAK
	.2byte 100 ; price
	.byte 53
	.byte 10
	.4byte gSharpBeakItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "POISON BARB$", 14
	.2byte ITEM_POISON_BARB
	.2byte 100 ; price
	.byte 54
	.byte 10
	.4byte gPoisonBarbItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "NEVERMELTICE$", 14
	.2byte ITEM_NEVER_MELT_ICE
	.2byte 100 ; price
	.byte 55
	.byte 10
	.4byte gNeverMeltIceItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SPELL TAG$", 14
	.2byte ITEM_SPELL_TAG
	.2byte 100 ; price
	.byte 56
	.byte 10
	.4byte gSpellTagItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TWISTEDSPOON$", 14
	.2byte ITEM_TWISTED_SPOON
	.2byte 100 ; price
	.byte 57
	.byte 10
	.4byte gTwistedSpoonItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CHARCOAL$", 14
	.2byte ITEM_CHARCOAL
	.2byte 9800 ; price
	.byte 58
	.byte 10
	.4byte gCharcoalItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DRAGON FANG$", 14
	.2byte ITEM_DRAGON_FANG
	.2byte 100 ; price
	.byte 59
	.byte 10
	.4byte gDragonFangItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SILK SCARF$", 14
	.2byte ITEM_SILK_SCARF
	.2byte 100 ; price
	.byte 60
	.byte 10
	.4byte gSilkScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "UP-GRADE$", 14
	.2byte ITEM_UP_GRADE
	.2byte 2100 ; price
	.byte 61
	.byte 0
	.4byte gUpGradeItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SHELL BELL$", 14
	.2byte ITEM_SHELL_BELL
	.2byte 200 ; price
	.byte 62
	.byte 8
	.4byte gShellBellItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SEA INCENSE$", 14
	.2byte ITEM_SEA_INCENSE
	.2byte 9600 ; price
	.byte 52
	.byte 5
	.4byte gSeaIncenseItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LAX INCENSE$", 14
	.2byte ITEM_LAX_INCENSE
	.2byte 9600 ; price
	.byte 22
	.byte 5
	.4byte gLaxIncenseItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LUCKY PUNCH$", 14
	.2byte ITEM_LUCKY_PUNCH
	.2byte 10 ; price
	.byte 63
	.byte 0
	.4byte gLuckyPunchItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "METAL POWDER$", 14
	.2byte ITEM_METAL_POWDER
	.2byte 10 ; price
	.byte 64
	.byte 0
	.4byte gMetalPowderItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "THICK CLUB$", 14
	.2byte ITEM_THICK_CLUB
	.2byte 500 ; price
	.byte 65
	.byte 0
	.4byte gThickClubItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "STICK$", 14
	.2byte ITEM_STICK
	.2byte 200 ; price
	.byte 66
	.byte 0
	.4byte gStickItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RED SCARF$", 14
	.2byte ITEM_RED_SCARF
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gRedScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLUE SCARF$", 14
	.2byte ITEM_BLUE_SCARF
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gBlueScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "PINK SCARF$", 14
	.2byte ITEM_PINK_SCARF
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gPinkScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GREEN SCARF$", 14
	.2byte ITEM_GREEN_SCARF
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gGreenScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "YELLOW SCARF$", 14
	.2byte ITEM_YELLOW_SCARF
	.2byte 100 ; price
	.byte 0
	.byte 0
	.4byte gYellowScarfItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MACH BIKE$", 14
	.2byte ITEM_MACH_BIKE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMachBikeItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte item_field_func_bike
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "COIN CASE$", 14
	.2byte ITEM_COIN_CASE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gCoinCaseItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte sub_80FDC34
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ITEMFINDER$", 14
	.2byte ITEM_ITEMFINDER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gItemfinderItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte it_itemfinder
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "OLD ROD$", 14
	.2byte ITEM_OLD_ROD
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gOldRodItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte rod
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GOOD ROD$", 14
	.2byte ITEM_GOOD_ROD
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gGoodRodItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte rod
	.4byte 0
	.4byte NULL
	.4byte 1

	.charmapstr "SUPER ROD$", 14
	.2byte ITEM_SUPER_ROD
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSuperRodItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte rod
	.4byte 0
	.4byte NULL
	.4byte 2

	.charmapstr "S.S. TICKET$", 14
	.2byte ITEM_SS_TICKET
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSSTicketItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CONTEST PASS$", 14
	.2byte ITEM_CONTEST_PASS
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gContestPassItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "WAILMER PAIL$", 14
	.2byte ITEM_WAILMER_PAIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gWailmerPailItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte sub_80FDDA4
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DEVON GOODS$", 14
	.2byte ITEM_DEVON_GOODS
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDevonGoodsItemDescription
	.2byte 2
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SOOT SACK$", 14
	.2byte ITEM_SOOT_SACK
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSootSackItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BASEMENT KEY$", 14
	.2byte ITEM_BASEMENT_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gBasementKeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ACRO BIKE$", 14
	.2byte ITEM_ACRO_BIKE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gAcroBikeItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte item_field_func_bike
	.4byte 0
	.4byte NULL
	.4byte 1

	.charmapstr "{POKEBLOCK} CASE$", 14
	.2byte ITEM_POKEBLOCK_CASE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gPokeblockCaseItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 3
	.4byte sub_80FDB6C
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LETTER$", 14
	.2byte ITEM_LETTER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gLetterItemDescription
	.2byte 2
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "EON TICKET$", 14
	.2byte ITEM_EON_TICKET
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gEonTicketItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 1

	.charmapstr "RED ORB$", 14
	.2byte ITEM_RED_ORB
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRedOrbItemDescription
	.2byte 2
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BLUE ORB$", 14
	.2byte ITEM_BLUE_ORB
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gBlueOrbItemDescription
	.2byte 2
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SCANNER$", 14
	.2byte ITEM_SCANNER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gScannerItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GO-GOGGLES$", 14
	.2byte ITEM_GO_GOGGLES
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gGoGogglesItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "METEORITE$", 14
	.2byte ITEM_METEORITE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMeteoriteItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RM. 1 KEY$", 14
	.2byte ITEM_ROOM_1_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRoom1KeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RM. 2 KEY$", 14
	.2byte ITEM_ROOM_2_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRoom2KeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RM. 4 KEY$", 14
	.2byte ITEM_ROOM_4_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRoom4KeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RM. 6 KEY$", 14
	.2byte ITEM_ROOM_6_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRoom6KeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "STORAGE KEY$", 14
	.2byte ITEM_STORAGE_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gStorageKeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "ROOT FOSSIL$", 14
	.2byte ITEM_ROOT_FOSSIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRootFossilItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CLAW FOSSIL$", 14
	.2byte ITEM_CLAW_FOSSIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gClawFossilItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DEVON SCOPE$", 14
	.2byte ITEM_DEVON_SCOPE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDevonScopeItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM01$", 14
	.2byte ITEM_TM01
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM01ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM02$", 14
	.2byte ITEM_TM02
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM02ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM03$", 14
	.2byte ITEM_TM03
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM03ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM04$", 14
	.2byte ITEM_TM04
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM04ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM05$", 14
	.2byte ITEM_TM05
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gTM05ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM06$", 14
	.2byte ITEM_TM06
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM06ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM07$", 14
	.2byte ITEM_TM07
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM07ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM08$", 14
	.2byte ITEM_TM08
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM08ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM09$", 14
	.2byte ITEM_TM09
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM09ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM10$", 14
	.2byte ITEM_TM10
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM10ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM11$", 14
	.2byte ITEM_TM11
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM11ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM12$", 14
	.2byte ITEM_TM12
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM12ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM13$", 14
	.2byte ITEM_TM13
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM13ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM14$", 14
	.2byte ITEM_TM14
	.2byte 5500 ; price
	.byte 0
	.byte 0
	.4byte gTM14ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM15$", 14
	.2byte ITEM_TM15
	.2byte 7500 ; price
	.byte 0
	.byte 0
	.4byte gTM15ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM16$", 14
	.2byte ITEM_TM16
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM16ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM17$", 14
	.2byte ITEM_TM17
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM17ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM18$", 14
	.2byte ITEM_TM18
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM18ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM19$", 14
	.2byte ITEM_TM19
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM19ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM20$", 14
	.2byte ITEM_TM20
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM20ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM21$", 14
	.2byte ITEM_TM21
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gTM21ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM22$", 14
	.2byte ITEM_TM22
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM22ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM23$", 14
	.2byte ITEM_TM23
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM23ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM24$", 14
	.2byte ITEM_TM24
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM24ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM25$", 14
	.2byte ITEM_TM25
	.2byte 5500 ; price
	.byte 0
	.byte 0
	.4byte gTM25ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM26$", 14
	.2byte ITEM_TM26
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM26ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM27$", 14
	.2byte ITEM_TM27
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gTM27ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM28$", 14
	.2byte ITEM_TM28
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM28ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM29$", 14
	.2byte ITEM_TM29
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM29ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM30$", 14
	.2byte ITEM_TM30
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM30ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM31$", 14
	.2byte ITEM_TM31
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM31ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM32$", 14
	.2byte ITEM_TM32
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM32ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM33$", 14
	.2byte ITEM_TM33
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM33ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM34$", 14
	.2byte ITEM_TM34
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM34ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM35$", 14
	.2byte ITEM_TM35
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM35ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM36$", 14
	.2byte ITEM_TM36
	.2byte 1000 ; price
	.byte 0
	.byte 0
	.4byte gTM36ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM37$", 14
	.2byte ITEM_TM37
	.2byte 2000 ; price
	.byte 0
	.byte 0
	.4byte gTM37ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM38$", 14
	.2byte ITEM_TM38
	.2byte 5500 ; price
	.byte 0
	.byte 0
	.4byte gTM38ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM39$", 14
	.2byte ITEM_TM39
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM39ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM40$", 14
	.2byte ITEM_TM40
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM40ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM41$", 14
	.2byte ITEM_TM41
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM41ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM42$", 14
	.2byte ITEM_TM42
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM42ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM43$", 14
	.2byte ITEM_TM43
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM43ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM44$", 14
	.2byte ITEM_TM44
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM44ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM45$", 14
	.2byte ITEM_TM45
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM45ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM46$", 14
	.2byte ITEM_TM46
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM46ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM47$", 14
	.2byte ITEM_TM47
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM47ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM48$", 14
	.2byte ITEM_TM48
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM48ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM49$", 14
	.2byte ITEM_TM49
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM49ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM50$", 14
	.2byte ITEM_TM50
	.2byte 3000 ; price
	.byte 0
	.byte 0
	.4byte gTM50ItemDescription
	.2byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM01$", 14
	.2byte ITEM_HM01
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM01ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM02$", 14
	.2byte ITEM_HM02
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM02ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM03$", 14
	.2byte ITEM_HM03
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM03ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM04$", 14
	.2byte ITEM_HM04
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM04ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM05$", 14
	.2byte ITEM_HM05
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM05ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM06$", 14
	.2byte ITEM_HM06
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM06ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM07$", 14
	.2byte ITEM_HM07
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM07ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HM08$", 14
	.2byte ITEM_HM08
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHM08ItemDescription
	.2byte 1
	.byte POCKET_TM_HM
	.byte 1
	.4byte sub_80FDF48
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.2byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "OAK’S PARCEL$", 14
	.2byte ITEM_OAKS_PARCEL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gOaksParcelItemDescription
	.2byte 2
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "POKé FLUTE$", 14
	.2byte ITEM_POKE_FLUTE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gPokeFluteItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SECRET KEY$", 14
	.2byte ITEM_SECRET_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSecretKeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BIKE VOUCHER$", 14
	.2byte ITEM_BIKE_VOUCHER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gBikeVoucherItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "GOLD TEETH$", 14
	.2byte ITEM_GOLD_TEETH
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gGoldTeethItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "OLD AMBER$", 14
	.2byte ITEM_OLD_AMBER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gOldAmberItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "CARD KEY$", 14
	.2byte ITEM_CARD_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gCardKeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "LIFT KEY$", 14
	.2byte ITEM_LIFT_KEY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gLiftKeyItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "HELIX FOSSIL$", 14
	.2byte ITEM_HELIX_FOSSIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gHelixFossilItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "DOME FOSSIL$", 14
	.2byte ITEM_DOME_FOSSIL
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gDomeFossilItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SILPH SCOPE$", 14
	.2byte ITEM_SILPH_SCOPE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSilphScopeItemDescription
	.2byte 1
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BICYCLE$", 14
	.2byte ITEM_BICYCLE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gBicycleItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TOWN MAP$", 14
	.2byte ITEM_TOWN_MAP
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gTownMapItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "VS SEEKER$", 14
	.2byte ITEM_VS_SEEKER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gVSSeekerItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "FAME CHECKER$", 14
	.2byte ITEM_FAME_CHECKER
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gFameCheckerItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TM CASE$", 14
	.2byte ITEM_TM_CASE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gTMCaseItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "BERRY POUCH$", 14
	.2byte ITEM_BERRY_POUCH
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gBerryPouchItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TEACHY TV$", 14
	.2byte ITEM_TEACHY_TV
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gTeachyTVItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 2
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TRI-PASS$", 14
	.2byte ITEM_TRI_PASS
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gTriPassItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RAINBOW PASS$", 14
	.2byte ITEM_RAINBOW_PASS
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRainbowPassItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "TEA$", 14
	.2byte ITEM_TEA
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gTeaItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MYSTICTICKET$", 14
	.2byte ITEM_MYSTIC_TICKET
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMysticTicketItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "AURORATICKET$", 14
	.2byte ITEM_AURORA_TICKET
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gAuroraTicketItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "POWDER JAR$", 14
	.2byte ITEM_POWDER_JAR
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gPowderJarItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte sub_80FDCA4
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "RUBY$", 14
	.2byte ITEM_RUBY
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gRubyItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "SAPPHIRE$", 14
	.2byte ITEM_SAPPHIRE
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gSapphireItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "MAGMA EMBLEM$", 14
	.2byte ITEM_MAGMA_EMBLEM
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gMagmaEmblemItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

	.charmapstr "OLD SEA MAP$", 14
	.2byte ITEM_OLD_SEA_MAP
	.2byte 0 ; price
	.byte 0
	.byte 0
	.4byte gOldSeaMapItemDescription
	.2byte 257
	.byte POCKET_KEY_ITEMS
	.byte 4
	.4byte item_field_func_cannot_use
	.4byte 0
	.4byte NULL
	.4byte 0

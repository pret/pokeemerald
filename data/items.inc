	.align 2
gItems:: @ 85839A0
	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MASTER BALL$", 14
	.2byte ITEM_MASTER_BALL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMasterBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 0
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 0

	.string "ULTRA BALL$", 14
	.2byte ITEM_ULTRA_BALL
	.2byte 1200 @ price
	.byte 0
	.byte 0
	.4byte gUltraBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 1
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 1

	.string "GREAT BALL$", 14
	.2byte ITEM_GREAT_BALL
	.2byte 600 @ price
	.byte 0
	.byte 0
	.4byte gGreatBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 2
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 2

	.string "POKé BALL$", 14
	.2byte ITEM_POKE_BALL
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gPokeBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 3
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 3

	.string "SAFARI BALL$", 14
	.2byte ITEM_SAFARI_BALL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSafariBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 4
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 4

	.string "NET BALL$", 14
	.2byte ITEM_NET_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gNetBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 5
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 5

	.string "DIVE BALL$", 14
	.2byte ITEM_DIVE_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gDiveBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 6
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 6

	.string "NEST BALL$", 14
	.2byte ITEM_NEST_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gNestBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 7
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 7

	.string "REPEAT BALL$", 14
	.2byte ITEM_REPEAT_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gRepeatBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 8
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 8

	.string "TIMER BALL$", 14
	.2byte ITEM_TIMER_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gTimerBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 9
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 9

	.string "LUXURY BALL$", 14
	.2byte ITEM_LUXURY_BALL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gLuxuryBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 10
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 10

	.string "PREMIER BALL$", 14
	.2byte ITEM_PREMIER_BALL
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gPremierBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_POKE_BALLS
	.byte 11
	.4byte NULL
	.4byte 2
	.4byte ItemUseInBattle_PokeBall
	.4byte 11

	.string "POTION$", 14
	.2byte ITEM_POTION
	.2byte 300 @ price
	.byte 0
	.byte 20
	.4byte gPotionItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ANTIDOTE$", 14
	.2byte ITEM_ANTIDOTE
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gAntidoteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "BURN HEAL$", 14
	.2byte ITEM_BURN_HEAL
	.2byte 250 @ price
	.byte 0
	.byte 0
	.4byte gBurnHealItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ICE HEAL$", 14
	.2byte ITEM_ICE_HEAL
	.2byte 250 @ price
	.byte 0
	.byte 0
	.4byte gIceHealItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "AWAKENING$", 14
	.2byte ITEM_AWAKENING
	.2byte 250 @ price
	.byte 0
	.byte 0
	.4byte gAwakeningItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "PARLYZ HEAL$", 14
	.2byte ITEM_PARALYZE_HEAL
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gParalyzeHealItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "FULL RESTORE$", 14
	.2byte ITEM_FULL_RESTORE
	.2byte 3000 @ price
	.byte 0
	.byte 255
	.4byte gFullRestoreItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "MAX POTION$", 14
	.2byte ITEM_MAX_POTION
	.2byte 2500 @ price
	.byte 0
	.byte 255
	.4byte gMaxPotionItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "HYPER POTION$", 14
	.2byte ITEM_HYPER_POTION
	.2byte 1200 @ price
	.byte 0
	.byte 200
	.4byte gHyperPotionItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "SUPER POTION$", 14
	.2byte ITEM_SUPER_POTION
	.2byte 700 @ price
	.byte 0
	.byte 50
	.4byte gSuperPotionItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "FULL HEAL$", 14
	.2byte ITEM_FULL_HEAL
	.2byte 600 @ price
	.byte 0
	.byte 0
	.4byte gFullHealItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "REVIVE$", 14
	.2byte ITEM_REVIVE
	.2byte 1500 @ price
	.byte 0
	.byte 0
	.4byte gReviveItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "MAX REVIVE$", 14
	.2byte ITEM_MAX_REVIVE
	.2byte 4000 @ price
	.byte 0
	.byte 0
	.4byte gMaxReviveItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "FRESH WATER$", 14
	.2byte ITEM_FRESH_WATER
	.2byte 200 @ price
	.byte 0
	.byte 50
	.4byte gFreshWaterItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "SODA POP$", 14
	.2byte ITEM_SODA_POP
	.2byte 300 @ price
	.byte 0
	.byte 60
	.4byte gSodaPopItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "LEMONADE$", 14
	.2byte ITEM_LEMONADE
	.2byte 350 @ price
	.byte 0
	.byte 80
	.4byte gLemonadeItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "MOOMOO MILK$", 14
	.2byte ITEM_MOOMOO_MILK
	.2byte 500 @ price
	.byte 0
	.byte 100
	.4byte gMoomooMilkItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ENERGYPOWDER$", 14
	.2byte ITEM_ENERGY_POWDER
	.2byte 500 @ price
	.byte 0
	.byte 0
	.4byte gEnergyPowderItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ENERGY ROOT$", 14
	.2byte ITEM_ENERGY_ROOT
	.2byte 800 @ price
	.byte 0
	.byte 0
	.4byte gEnergyRootItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "HEAL POWDER$", 14
	.2byte ITEM_HEAL_POWDER
	.2byte 450 @ price
	.byte 0
	.byte 0
	.4byte gHealPowderItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "REVIVAL HERB$", 14
	.2byte ITEM_REVIVAL_HERB
	.2byte 2800 @ price
	.byte 0
	.byte 0
	.4byte gRevivalHerbItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ETHER$", 14
	.2byte ITEM_ETHER
	.2byte 1200 @ price
	.byte 0
	.byte 10
	.4byte gEtherItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPRecovery
	.4byte 1
	.4byte ItemUseInBattle_PPRecovery
	.4byte 0

	.string "MAX ETHER$", 14
	.2byte ITEM_MAX_ETHER
	.2byte 2000 @ price
	.byte 0
	.byte 255
	.4byte gMaxEtherItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPRecovery
	.4byte 1
	.4byte ItemUseInBattle_PPRecovery
	.4byte 0

	.string "ELIXIR$", 14
	.2byte ITEM_ELIXIR
	.2byte 3000 @ price
	.byte 0
	.byte 10
	.4byte gElixirItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPRecovery
	.4byte 1
	.4byte ItemUseInBattle_PPRecovery
	.4byte 0

	.string "MAX ELIXIR$", 14
	.2byte ITEM_MAX_ELIXIR
	.2byte 4500 @ price
	.byte 0
	.byte 255
	.4byte gMaxElixirItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPRecovery
	.4byte 1
	.4byte ItemUseInBattle_PPRecovery
	.4byte 0

	.string "LAVA COOKIE$", 14
	.2byte ITEM_LAVA_COOKIE
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gLavaCookieItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "BLUE FLUTE$", 14
	.2byte ITEM_BLUE_FLUTE
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gBlueFluteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "YELLOW FLUTE$", 14
	.2byte ITEM_YELLOW_FLUTE
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gYellowFluteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "RED FLUTE$", 14
	.2byte ITEM_RED_FLUTE
	.2byte 300 @ price
	.byte 0
	.byte 0
	.4byte gRedFluteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "BLACK FLUTE$", 14
	.2byte ITEM_BLACK_FLUTE
	.2byte 400 @ price
	.byte 0
	.byte 50
	.4byte gBlackFluteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_BlackWhiteFlute
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WHITE FLUTE$", 14
	.2byte ITEM_WHITE_FLUTE
	.2byte 500 @ price
	.byte 0
	.byte 150
	.4byte gWhiteFluteItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_BlackWhiteFlute
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BERRY JUICE$", 14
	.2byte ITEM_BERRY_JUICE
	.2byte 100 @ price
	.byte 1
	.byte 20
	.4byte gBerryJuiceItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "SACRED ASH$", 14
	.2byte ITEM_SACRED_ASH
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gSacredAshItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_SacredAsh
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SHOAL SALT$", 14
	.2byte ITEM_SHOAL_SALT
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gShoalSaltItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SHOAL SHELL$", 14
	.2byte ITEM_SHOAL_SHELL
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gShoalShellItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RED SHARD$", 14
	.2byte ITEM_RED_SHARD
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gRedShardItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLUE SHARD$", 14
	.2byte ITEM_BLUE_SHARD
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gBlueShardItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "YELLOW SHARD$", 14
	.2byte ITEM_YELLOW_SHARD
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gYellowShardItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GREEN SHARD$", 14
	.2byte ITEM_GREEN_SHARD
	.2byte 200 @ price
	.byte 0
	.byte 0
	.4byte gGreenShardItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HP UP$", 14
	.2byte ITEM_HP_UP
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gHPUpItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PROTEIN$", 14
	.2byte ITEM_PROTEIN
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gProteinItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "IRON$", 14
	.2byte ITEM_IRON
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gIronItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CARBOS$", 14
	.2byte ITEM_CARBOS
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gCarbosItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CALCIUM$", 14
	.2byte ITEM_CALCIUM
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gCalciumItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RARE CANDY$", 14
	.2byte ITEM_RARE_CANDY
	.2byte 4800 @ price
	.byte 0
	.byte 0
	.4byte gRareCandyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_RareCandy
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PP UP$", 14
	.2byte ITEM_PP_UP
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gPPUpItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPUp
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ZINC$", 14
	.2byte ITEM_ZINC
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gZincItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PP MAX$", 14
	.2byte ITEM_PP_MAX
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gPPMaxItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_PPUp
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GUARD SPEC.$", 14
	.2byte ITEM_GUARD_SPEC
	.2byte 700 @ price
	.byte 0
	.byte 0
	.4byte gGuardSpecItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "DIRE HIT$", 14
	.2byte ITEM_DIRE_HIT
	.2byte 650 @ price
	.byte 0
	.byte 0
	.4byte gDireHitItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "X ATTACK$", 14
	.2byte ITEM_X_ATTACK
	.2byte 500 @ price
	.byte 0
	.byte 0
	.4byte gXAttackItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "X DEFEND$", 14
	.2byte ITEM_X_DEFEND
	.2byte 550 @ price
	.byte 0
	.byte 0
	.4byte gXDefendItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "X SPEED$", 14
	.2byte ITEM_X_SPEED
	.2byte 350 @ price
	.byte 0
	.byte 0
	.4byte gXSpeedItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "X ACCURACY$", 14
	.2byte ITEM_X_ACCURACY
	.2byte 950 @ price
	.byte 0
	.byte 0
	.4byte gXAccuracyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "X SPECIAL$", 14
	.2byte ITEM_X_SPECIAL
	.2byte 350 @ price
	.byte 0
	.byte 0
	.4byte gXSpecialItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_StatIncrease
	.4byte 0

	.string "POKé DOLL$", 14
	.2byte ITEM_POKE_DOLL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gPokeDollItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_Escape
	.4byte 0

	.string "FLUFFY TAIL$", 14
	.2byte ITEM_FLUFFY_TAIL
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gFluffyTailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 2
	.4byte ItemUseInBattle_Escape
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SUPER REPEL$", 14
	.2byte ITEM_SUPER_REPEL
	.2byte 500 @ price
	.byte 0
	.byte 200
	.4byte gSuperRepelItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_Repel
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MAX REPEL$", 14
	.2byte ITEM_MAX_REPEL
	.2byte 700 @ price
	.byte 0
	.byte 250
	.4byte gMaxRepelItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_Repel
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ESCAPE ROPE$", 14
	.2byte ITEM_ESCAPE_ROPE
	.2byte 550 @ price
	.byte 0
	.byte 0
	.4byte gEscapeRopeItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_EscapeRope
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "REPEL$", 14
	.2byte ITEM_REPEL
	.2byte 350 @ price
	.byte 0
	.byte 100
	.4byte gRepelItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_Repel
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SUN STONE$", 14
	.2byte ITEM_SUN_STONE
	.2byte 2100 @ price
	.byte 0
	.byte 0
	.4byte gSunStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MOON STONE$", 14
	.2byte ITEM_MOON_STONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMoonStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "FIRE STONE$", 14
	.2byte ITEM_FIRE_STONE
	.2byte 2100 @ price
	.byte 0
	.byte 0
	.4byte gFireStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "THUNDERSTONE$", 14
	.2byte ITEM_THUNDER_STONE
	.2byte 2100 @ price
	.byte 0
	.byte 0
	.4byte gThunderStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WATER STONE$", 14
	.2byte ITEM_WATER_STONE
	.2byte 2100 @ price
	.byte 0
	.byte 0
	.4byte gWaterStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LEAF STONE$", 14
	.2byte ITEM_LEAF_STONE
	.2byte 2100 @ price
	.byte 0
	.byte 0
	.4byte gLeafStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 1
	.4byte ItemUseOutOfBattle_EvolutionStone
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TINYMUSHROOM$", 14
	.2byte ITEM_TINY_MUSHROOM
	.2byte 500 @ price
	.byte 0
	.byte 0
	.4byte gTinyMushroomItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BIG MUSHROOM$", 14
	.2byte ITEM_BIG_MUSHROOM
	.2byte 5000 @ price
	.byte 0
	.byte 0
	.4byte gBigMushroomItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PEARL$", 14
	.2byte ITEM_PEARL
	.2byte 1400 @ price
	.byte 0
	.byte 0
	.4byte gPearlItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BIG PEARL$", 14
	.2byte ITEM_BIG_PEARL
	.2byte 7500 @ price
	.byte 0
	.byte 0
	.4byte gBigPearlItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "STARDUST$", 14
	.2byte ITEM_STARDUST
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gStardustItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "STAR PIECE$", 14
	.2byte ITEM_STAR_PIECE
	.2byte 9800 @ price
	.byte 0
	.byte 0
	.4byte gStarPieceItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "NUGGET$", 14
	.2byte ITEM_NUGGET
	.2byte 10000 @ price
	.byte 0
	.byte 0
	.4byte gNuggetItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HEART SCALE$", 14
	.2byte ITEM_HEART_SCALE
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gHeartScaleItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ORANGE MAIL$", 14
	.2byte ITEM_ORANGE_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gOrangeMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HARBOR MAIL$", 14
	.2byte ITEM_HARBOR_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gHarborMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 1

	.string "GLITTER MAIL$", 14
	.2byte ITEM_GLITTER_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gGlitterMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 2

	.string "MECH MAIL$", 14
	.2byte ITEM_MECH_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gMechMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 3

	.string "WOOD MAIL$", 14
	.2byte ITEM_WOOD_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gWoodMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 4

	.string "WAVE MAIL$", 14
	.2byte ITEM_WAVE_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gWaveMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 5

	.string "BEAD MAIL$", 14
	.2byte ITEM_BEAD_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gBeadMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 6

	.string "SHADOW MAIL$", 14
	.2byte ITEM_SHADOW_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gShadowMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 7

	.string "TROPIC MAIL$", 14
	.2byte ITEM_TROPIC_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gTropicMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 8

	.string "DREAM MAIL$", 14
	.2byte ITEM_DREAM_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gDreamMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 9

	.string "FAB MAIL$", 14
	.2byte ITEM_FAB_MAIL
	.2byte 50 @ price
	.byte 0
	.byte 0
	.4byte gFabMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 10

	.string "RETRO MAIL$", 14
	.2byte ITEM_RETRO_MAIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRetroMailItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 0
	.4byte ItemUseOutOfBattle_Mail
	.4byte 0
	.4byte NULL
	.4byte 11

	.string "CHERI BERRY$", 14
	.2byte ITEM_CHERI_BERRY
	.2byte 20 @ price
	.byte 2
	.byte 0
	.4byte gCheriBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "CHESTO BERRY$", 14
	.2byte ITEM_CHESTO_BERRY
	.2byte 20 @ price
	.byte 3
	.byte 0
	.4byte gChestoBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "PECHA BERRY$", 14
	.2byte ITEM_PECHA_BERRY
	.2byte 20 @ price
	.byte 4
	.byte 0
	.4byte gPechaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "RAWST BERRY$", 14
	.2byte ITEM_RAWST_BERRY
	.2byte 20 @ price
	.byte 5
	.byte 0
	.4byte gRawstBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "ASPEAR BERRY$", 14
	.2byte ITEM_ASPEAR_BERRY
	.2byte 20 @ price
	.byte 6
	.byte 0
	.4byte gAspearBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "LEPPA BERRY$", 14
	.2byte ITEM_LEPPA_BERRY
	.2byte 20 @ price
	.byte 7
	.byte 10
	.4byte gLeppaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_PPRecovery
	.4byte 1
	.4byte ItemUseInBattle_PPRecovery
	.4byte 0

	.string "ORAN BERRY$", 14
	.2byte ITEM_ORAN_BERRY
	.2byte 20 @ price
	.byte 1
	.byte 10
	.4byte gOranBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "PERSIM BERRY$", 14
	.2byte ITEM_PERSIM_BERRY
	.2byte 20 @ price
	.byte 8
	.byte 0
	.4byte gPersimBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "LUM BERRY$", 14
	.2byte ITEM_LUM_BERRY
	.2byte 20 @ price
	.byte 9
	.byte 0
	.4byte gLumBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "SITRUS BERRY$", 14
	.2byte ITEM_SITRUS_BERRY
	.2byte 20 @ price
	.byte 1
	.byte 30
	.4byte gSitrusBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_Medicine
	.4byte 1
	.4byte ItemUseInBattle_Medicine
	.4byte 0

	.string "FIGY BERRY$", 14
	.2byte ITEM_FIGY_BERRY
	.2byte 20 @ price
	.byte 10
	.byte 8
	.4byte gFigyBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WIKI BERRY$", 14
	.2byte ITEM_WIKI_BERRY
	.2byte 20 @ price
	.byte 11
	.byte 8
	.4byte gWikiBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MAGO BERRY$", 14
	.2byte ITEM_MAGO_BERRY
	.2byte 20 @ price
	.byte 12
	.byte 8
	.4byte gMagoBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "AGUAV BERRY$", 14
	.2byte ITEM_AGUAV_BERRY
	.2byte 20 @ price
	.byte 13
	.byte 8
	.4byte gAguavBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "IAPAPA BERRY$", 14
	.2byte ITEM_IAPAPA_BERRY
	.2byte 20 @ price
	.byte 14
	.byte 8
	.4byte gIapapaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RAZZ BERRY$", 14
	.2byte ITEM_RAZZ_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gRazzBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLUK BERRY$", 14
	.2byte ITEM_BLUK_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gBlukBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "NANAB BERRY$", 14
	.2byte ITEM_NANAB_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gNanabBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WEPEAR BERRY$", 14
	.2byte ITEM_WEPEAR_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gWepearBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PINAP BERRY$", 14
	.2byte ITEM_PINAP_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gPinapBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "POMEG BERRY$", 14
	.2byte ITEM_POMEG_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gPomegBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "KELPSY BERRY$", 14
	.2byte ITEM_KELPSY_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gKelpsyBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "QUALOT BERRY$", 14
	.2byte ITEM_QUALOT_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gQualotBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HONDEW BERRY$", 14
	.2byte ITEM_HONDEW_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gHondewBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GREPA BERRY$", 14
	.2byte ITEM_GREPA_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gGrepaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TAMATO BERRY$", 14
	.2byte ITEM_TAMATO_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gTamatoBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 1
	.4byte ItemUseOutOfBattle_ReduceEV
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CORNN BERRY$", 14
	.2byte ITEM_CORNN_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gCornnBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MAGOST BERRY$", 14
	.2byte ITEM_MAGOST_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gMagostBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RABUTA BERRY$", 14
	.2byte ITEM_RABUTA_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gRabutaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "NOMEL BERRY$", 14
	.2byte ITEM_NOMEL_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gNomelBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SPELON BERRY$", 14
	.2byte ITEM_SPELON_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gSpelonBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PAMTRE BERRY$", 14
	.2byte ITEM_PAMTRE_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gPamtreBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WATMEL BERRY$", 14
	.2byte ITEM_WATMEL_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gWatmelBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DURIN BERRY$", 14
	.2byte ITEM_DURIN_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gDurinBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BELUE BERRY$", 14
	.2byte ITEM_BELUE_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gBelueBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LIECHI BERRY$", 14
	.2byte ITEM_LIECHI_BERRY
	.2byte 20 @ price
	.byte 15
	.byte 4
	.4byte gLiechiBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GANLON BERRY$", 14
	.2byte ITEM_GANLON_BERRY
	.2byte 20 @ price
	.byte 16
	.byte 4
	.4byte gGanlonBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SALAC BERRY$", 14
	.2byte ITEM_SALAC_BERRY
	.2byte 20 @ price
	.byte 17
	.byte 4
	.4byte gSalacBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PETAYA BERRY$", 14
	.2byte ITEM_PETAYA_BERRY
	.2byte 20 @ price
	.byte 18
	.byte 4
	.4byte gPetayaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "APICOT BERRY$", 14
	.2byte ITEM_APICOT_BERRY
	.2byte 20 @ price
	.byte 19
	.byte 4
	.4byte gApicotBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LANSAT BERRY$", 14
	.2byte ITEM_LANSAT_BERRY
	.2byte 20 @ price
	.byte 20
	.byte 4
	.4byte gLansatBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "STARF BERRY$", 14
	.2byte ITEM_STARF_BERRY
	.2byte 20 @ price
	.byte 21
	.byte 4
	.4byte gStarfBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ENIGMA BERRY$", 14
	.2byte ITEM_ENIGMA_BERRY
	.2byte 20 @ price
	.byte 0
	.byte 0
	.4byte gEnigmaBerryItemDescription
	.byte 0
	.byte 0
	.byte POCKET_BERRIES
	.byte 4
	.4byte ItemUseOutOfBattle_EnigmaBerry
	.4byte 1
	.4byte ItemUseInBattle_EnigmaBerry
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BRIGHTPOWDER$", 14
	.2byte ITEM_BRIGHT_POWDER
	.2byte 10 @ price
	.byte 22
	.byte 10
	.4byte gBrightPowderItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WHITE HERB$", 14
	.2byte ITEM_WHITE_HERB
	.2byte 100 @ price
	.byte 23
	.byte 0
	.4byte gWhiteHerbItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MACHO BRACE$", 14
	.2byte ITEM_MACHO_BRACE
	.2byte 3000 @ price
	.byte 24
	.byte 0
	.4byte gMachoBraceItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "EXP. SHARE$", 14
	.2byte ITEM_EXP_SHARE
	.2byte 3000 @ price
	.byte 25
	.byte 0
	.4byte gExpShareItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "QUICK CLAW$", 14
	.2byte ITEM_QUICK_CLAW
	.2byte 100 @ price
	.byte 26
	.byte 20
	.4byte gQuickClawItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SOOTHE BELL$", 14
	.2byte ITEM_SOOTHE_BELL
	.2byte 100 @ price
	.byte 27
	.byte 0
	.4byte gSootheBellItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MENTAL HERB$", 14
	.2byte ITEM_MENTAL_HERB
	.2byte 100 @ price
	.byte 28
	.byte 0
	.4byte gMentalHerbItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CHOICE BAND$", 14
	.2byte ITEM_CHOICE_BAND
	.2byte 100 @ price
	.byte 29
	.byte 0
	.4byte gChoiceBandItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "KING’S ROCK$", 14
	.2byte ITEM_KINGS_ROCK
	.2byte 100 @ price
	.byte 30
	.byte 10
	.4byte gKingsRockItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SILVERPOWDER$", 14
	.2byte ITEM_SILVER_POWDER
	.2byte 100 @ price
	.byte 31
	.byte 10
	.4byte gSilverPowderItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "AMULET COIN$", 14
	.2byte ITEM_AMULET_COIN
	.2byte 100 @ price
	.byte 32
	.byte 10
	.4byte gAmuletCoinItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CLEANSE TAG$", 14
	.2byte ITEM_CLEANSE_TAG
	.2byte 200 @ price
	.byte 33
	.byte 0
	.4byte gCleanseTagItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SOUL DEW$", 14
	.2byte ITEM_SOUL_DEW
	.2byte 200 @ price
	.byte 34
	.byte 0
	.4byte gSoulDewItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DEEPSEATOOTH$", 14
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte 200 @ price
	.byte 35
	.byte 0
	.4byte gDeepSeaToothItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DEEPSEASCALE$", 14
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte 200 @ price
	.byte 36
	.byte 0
	.4byte gDeepSeaScaleItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SMOKE BALL$", 14
	.2byte ITEM_SMOKE_BALL
	.2byte 200 @ price
	.byte 37
	.byte 0
	.4byte gSmokeBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "EVERSTONE$", 14
	.2byte ITEM_EVERSTONE
	.2byte 200 @ price
	.byte 38
	.byte 0
	.4byte gEverstoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "FOCUS BAND$", 14
	.2byte ITEM_FOCUS_BAND
	.2byte 200 @ price
	.byte 39
	.byte 10
	.4byte gFocusBandItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LUCKY EGG$", 14
	.2byte ITEM_LUCKY_EGG
	.2byte 200 @ price
	.byte 40
	.byte 0
	.4byte gLuckyEggItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SCOPE LENS$", 14
	.2byte ITEM_SCOPE_LENS
	.2byte 200 @ price
	.byte 41
	.byte 0
	.4byte gScopeLensItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "METAL COAT$", 14
	.2byte ITEM_METAL_COAT
	.2byte 100 @ price
	.byte 42
	.byte 10
	.4byte gMetalCoatItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LEFTOVERS$", 14
	.2byte ITEM_LEFTOVERS
	.2byte 200 @ price
	.byte 43
	.byte 10
	.4byte gLeftoversItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DRAGON SCALE$", 14
	.2byte ITEM_DRAGON_SCALE
	.2byte 2100 @ price
	.byte 44
	.byte 10
	.4byte gDragonScaleItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LIGHT BALL$", 14
	.2byte ITEM_LIGHT_BALL
	.2byte 100 @ price
	.byte 45
	.byte 0
	.4byte gLightBallItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SOFT SAND$", 14
	.2byte ITEM_SOFT_SAND
	.2byte 100 @ price
	.byte 46
	.byte 10
	.4byte gSoftSandItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HARD STONE$", 14
	.2byte ITEM_HARD_STONE
	.2byte 100 @ price
	.byte 47
	.byte 10
	.4byte gHardStoneItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MIRACLE SEED$", 14
	.2byte ITEM_MIRACLE_SEED
	.2byte 100 @ price
	.byte 48
	.byte 10
	.4byte gMiracleSeedItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLACKGLASSES$", 14
	.2byte ITEM_BLACK_GLASSES
	.2byte 100 @ price
	.byte 49
	.byte 10
	.4byte gBlackGlassesItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLACK BELT$", 14
	.2byte ITEM_BLACK_BELT
	.2byte 100 @ price
	.byte 50
	.byte 10
	.4byte gBlackBeltItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MAGNET$", 14
	.2byte ITEM_MAGNET
	.2byte 100 @ price
	.byte 51
	.byte 10
	.4byte gMagnetItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MYSTIC WATER$", 14
	.2byte ITEM_MYSTIC_WATER
	.2byte 100 @ price
	.byte 52
	.byte 10
	.4byte gMysticWaterItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SHARP BEAK$", 14
	.2byte ITEM_SHARP_BEAK
	.2byte 100 @ price
	.byte 53
	.byte 10
	.4byte gSharpBeakItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "POISON BARB$", 14
	.2byte ITEM_POISON_BARB
	.2byte 100 @ price
	.byte 54
	.byte 10
	.4byte gPoisonBarbItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "NEVERMELTICE$", 14
	.2byte ITEM_NEVER_MELT_ICE
	.2byte 100 @ price
	.byte 55
	.byte 10
	.4byte gNeverMeltIceItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SPELL TAG$", 14
	.2byte ITEM_SPELL_TAG
	.2byte 100 @ price
	.byte 56
	.byte 10
	.4byte gSpellTagItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TWISTEDSPOON$", 14
	.2byte ITEM_TWISTED_SPOON
	.2byte 100 @ price
	.byte 57
	.byte 10
	.4byte gTwistedSpoonItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CHARCOAL$", 14
	.2byte ITEM_CHARCOAL
	.2byte 9800 @ price
	.byte 58
	.byte 10
	.4byte gCharcoalItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DRAGON FANG$", 14
	.2byte ITEM_DRAGON_FANG
	.2byte 100 @ price
	.byte 59
	.byte 10
	.4byte gDragonFangItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SILK SCARF$", 14
	.2byte ITEM_SILK_SCARF
	.2byte 100 @ price
	.byte 60
	.byte 10
	.4byte gSilkScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "UP-GRADE$", 14
	.2byte ITEM_UP_GRADE
	.2byte 2100 @ price
	.byte 61
	.byte 0
	.4byte gUpGradeItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SHELL BELL$", 14
	.2byte ITEM_SHELL_BELL
	.2byte 200 @ price
	.byte 62
	.byte 8
	.4byte gShellBellItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SEA INCENSE$", 14
	.2byte ITEM_SEA_INCENSE
	.2byte 9600 @ price
	.byte 52
	.byte 5
	.4byte gSeaIncenseItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LAX INCENSE$", 14
	.2byte ITEM_LAX_INCENSE
	.2byte 9600 @ price
	.byte 22
	.byte 5
	.4byte gLaxIncenseItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LUCKY PUNCH$", 14
	.2byte ITEM_LUCKY_PUNCH
	.2byte 10 @ price
	.byte 63
	.byte 0
	.4byte gLuckyPunchItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "METAL POWDER$", 14
	.2byte ITEM_METAL_POWDER
	.2byte 10 @ price
	.byte 64
	.byte 0
	.4byte gMetalPowderItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "THICK CLUB$", 14
	.2byte ITEM_THICK_CLUB
	.2byte 500 @ price
	.byte 65
	.byte 0
	.4byte gThickClubItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "STICK$", 14
	.2byte ITEM_STICK
	.2byte 200 @ price
	.byte 66
	.byte 0
	.4byte gStickItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RED SCARF$", 14
	.2byte ITEM_RED_SCARF
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gRedScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLUE SCARF$", 14
	.2byte ITEM_BLUE_SCARF
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gBlueScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "PINK SCARF$", 14
	.2byte ITEM_PINK_SCARF
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gPinkScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GREEN SCARF$", 14
	.2byte ITEM_GREEN_SCARF
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gGreenScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "YELLOW SCARF$", 14
	.2byte ITEM_YELLOW_SCARF
	.2byte 100 @ price
	.byte 0
	.byte 0
	.4byte gYellowScarfItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MACH BIKE$", 14
	.2byte ITEM_MACH_BIKE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMachBikeItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Bike
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "COIN CASE$", 14
	.2byte ITEM_COIN_CASE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gCoinCaseItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CoinCase
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ITEMFINDER$", 14
	.2byte ITEM_ITEMFINDER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gItemfinderItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Itemfinder
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "OLD ROD$", 14
	.2byte ITEM_OLD_ROD
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gOldRodItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Rod
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GOOD ROD$", 14
	.2byte ITEM_GOOD_ROD
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gGoodRodItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Rod
	.4byte 0
	.4byte NULL
	.4byte 1

	.string "SUPER ROD$", 14
	.2byte ITEM_SUPER_ROD
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSuperRodItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Rod
	.4byte 0
	.4byte NULL
	.4byte 2

	.string "S.S. TICKET$", 14
	.2byte ITEM_SS_TICKET
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSSTicketItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CONTEST PASS$", 14
	.2byte ITEM_CONTEST_PASS
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gContestPassItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "WAILMER PAIL$", 14
	.2byte ITEM_WAILMER_PAIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gWailmerPailItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_WailmerPail
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DEVON GOODS$", 14
	.2byte ITEM_DEVON_GOODS
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDevonGoodsItemDescription
	.byte 2
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SOOT SACK$", 14
	.2byte ITEM_SOOT_SACK
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSootSackItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BASEMENT KEY$", 14
	.2byte ITEM_BASEMENT_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gBasementKeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ACRO BIKE$", 14
	.2byte ITEM_ACRO_BIKE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gAcroBikeItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_Bike
	.4byte 0
	.4byte NULL
	.4byte 1

	.string "{POKEBLOCK} CASE$", 14
	.2byte ITEM_POKEBLOCK_CASE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gPokeblockCaseItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 3
	.4byte ItemUseOutOfBattle_PokeblockCase
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LETTER$", 14
	.2byte ITEM_LETTER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gLetterItemDescription
	.byte 2
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "EON TICKET$", 14
	.2byte ITEM_EON_TICKET
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gEonTicketItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 1

	.string "RED ORB$", 14
	.2byte ITEM_RED_ORB
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRedOrbItemDescription
	.byte 2
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BLUE ORB$", 14
	.2byte ITEM_BLUE_ORB
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gBlueOrbItemDescription
	.byte 2
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SCANNER$", 14
	.2byte ITEM_SCANNER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gScannerItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GO-GOGGLES$", 14
	.2byte ITEM_GO_GOGGLES
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gGoGogglesItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "METEORITE$", 14
	.2byte ITEM_METEORITE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMeteoriteItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RM. 1 KEY$", 14
	.2byte ITEM_ROOM_1_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRoom1KeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RM. 2 KEY$", 14
	.2byte ITEM_ROOM_2_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRoom2KeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RM. 4 KEY$", 14
	.2byte ITEM_ROOM_4_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRoom4KeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RM. 6 KEY$", 14
	.2byte ITEM_ROOM_6_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRoom6KeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "STORAGE KEY$", 14
	.2byte ITEM_STORAGE_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gStorageKeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "ROOT FOSSIL$", 14
	.2byte ITEM_ROOT_FOSSIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRootFossilItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CLAW FOSSIL$", 14
	.2byte ITEM_CLAW_FOSSIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gClawFossilItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DEVON SCOPE$", 14
	.2byte ITEM_DEVON_SCOPE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDevonScopeItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM01$", 14
	.2byte ITEM_TM01
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM01ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM02$", 14
	.2byte ITEM_TM02
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM02ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM03$", 14
	.2byte ITEM_TM03
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM03ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM04$", 14
	.2byte ITEM_TM04
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM04ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM05$", 14
	.2byte ITEM_TM05
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gTM05ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM06$", 14
	.2byte ITEM_TM06
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM06ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM07$", 14
	.2byte ITEM_TM07
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM07ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM08$", 14
	.2byte ITEM_TM08
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM08ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM09$", 14
	.2byte ITEM_TM09
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM09ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM10$", 14
	.2byte ITEM_TM10
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM10ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM11$", 14
	.2byte ITEM_TM11
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM11ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM12$", 14
	.2byte ITEM_TM12
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM12ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM13$", 14
	.2byte ITEM_TM13
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM13ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM14$", 14
	.2byte ITEM_TM14
	.2byte 5500 @ price
	.byte 0
	.byte 0
	.4byte gTM14ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM15$", 14
	.2byte ITEM_TM15
	.2byte 7500 @ price
	.byte 0
	.byte 0
	.4byte gTM15ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM16$", 14
	.2byte ITEM_TM16
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM16ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM17$", 14
	.2byte ITEM_TM17
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM17ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM18$", 14
	.2byte ITEM_TM18
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM18ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM19$", 14
	.2byte ITEM_TM19
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM19ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM20$", 14
	.2byte ITEM_TM20
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM20ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM21$", 14
	.2byte ITEM_TM21
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gTM21ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM22$", 14
	.2byte ITEM_TM22
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM22ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM23$", 14
	.2byte ITEM_TM23
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM23ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM24$", 14
	.2byte ITEM_TM24
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM24ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM25$", 14
	.2byte ITEM_TM25
	.2byte 5500 @ price
	.byte 0
	.byte 0
	.4byte gTM25ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM26$", 14
	.2byte ITEM_TM26
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM26ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM27$", 14
	.2byte ITEM_TM27
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gTM27ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM28$", 14
	.2byte ITEM_TM28
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM28ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM29$", 14
	.2byte ITEM_TM29
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM29ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM30$", 14
	.2byte ITEM_TM30
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM30ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM31$", 14
	.2byte ITEM_TM31
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM31ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM32$", 14
	.2byte ITEM_TM32
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM32ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM33$", 14
	.2byte ITEM_TM33
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM33ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM34$", 14
	.2byte ITEM_TM34
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM34ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM35$", 14
	.2byte ITEM_TM35
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM35ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM36$", 14
	.2byte ITEM_TM36
	.2byte 1000 @ price
	.byte 0
	.byte 0
	.4byte gTM36ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM37$", 14
	.2byte ITEM_TM37
	.2byte 2000 @ price
	.byte 0
	.byte 0
	.4byte gTM37ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM38$", 14
	.2byte ITEM_TM38
	.2byte 5500 @ price
	.byte 0
	.byte 0
	.4byte gTM38ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM39$", 14
	.2byte ITEM_TM39
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM39ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM40$", 14
	.2byte ITEM_TM40
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM40ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM41$", 14
	.2byte ITEM_TM41
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM41ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM42$", 14
	.2byte ITEM_TM42
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM42ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM43$", 14
	.2byte ITEM_TM43
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM43ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM44$", 14
	.2byte ITEM_TM44
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM44ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM45$", 14
	.2byte ITEM_TM45
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM45ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM46$", 14
	.2byte ITEM_TM46
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM46ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM47$", 14
	.2byte ITEM_TM47
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM47ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM48$", 14
	.2byte ITEM_TM48
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM48ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM49$", 14
	.2byte ITEM_TM49
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM49ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM50$", 14
	.2byte ITEM_TM50
	.2byte 3000 @ price
	.byte 0
	.byte 0
	.4byte gTM50ItemDescription
	.byte 0
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM01$", 14
	.2byte ITEM_HM01
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM01ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM02$", 14
	.2byte ITEM_HM02
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM02ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM03$", 14
	.2byte ITEM_HM03
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM03ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM04$", 14
	.2byte ITEM_HM04
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM04ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM05$", 14
	.2byte ITEM_HM05
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM05ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM06$", 14
	.2byte ITEM_HM06
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM06ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM07$", 14
	.2byte ITEM_HM07
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM07ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HM08$", 14
	.2byte ITEM_HM08
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHM08ItemDescription
	.byte 1
	.byte 0
	.byte POCKET_TM_HM
	.byte 1
	.4byte ItemUseOutOfBattle_TMHM
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "????????$", 14
	.2byte ITEM_NONE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDummyItemDescription
	.byte 0
	.byte 0
	.byte POCKET_ITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "OAK’S PARCEL$", 14
	.2byte ITEM_OAKS_PARCEL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gOaksParcelItemDescription
	.byte 2
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "POKé FLUTE$", 14
	.2byte ITEM_POKE_FLUTE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gPokeFluteItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SECRET KEY$", 14
	.2byte ITEM_SECRET_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSecretKeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BIKE VOUCHER$", 14
	.2byte ITEM_BIKE_VOUCHER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gBikeVoucherItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "GOLD TEETH$", 14
	.2byte ITEM_GOLD_TEETH
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gGoldTeethItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "OLD AMBER$", 14
	.2byte ITEM_OLD_AMBER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gOldAmberItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "CARD KEY$", 14
	.2byte ITEM_CARD_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gCardKeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "LIFT KEY$", 14
	.2byte ITEM_LIFT_KEY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gLiftKeyItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "HELIX FOSSIL$", 14
	.2byte ITEM_HELIX_FOSSIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gHelixFossilItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "DOME FOSSIL$", 14
	.2byte ITEM_DOME_FOSSIL
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gDomeFossilItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SILPH SCOPE$", 14
	.2byte ITEM_SILPH_SCOPE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSilphScopeItemDescription
	.byte 1
	.byte 0
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BICYCLE$", 14
	.2byte ITEM_BICYCLE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gBicycleItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TOWN MAP$", 14
	.2byte ITEM_TOWN_MAP
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gTownMapItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "VS SEEKER$", 14
	.2byte ITEM_VS_SEEKER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gVSSeekerItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "FAME CHECKER$", 14
	.2byte ITEM_FAME_CHECKER
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gFameCheckerItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TM CASE$", 14
	.2byte ITEM_TM_CASE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gTMCaseItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "BERRY POUCH$", 14
	.2byte ITEM_BERRY_POUCH
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gBerryPouchItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TEACHY TV$", 14
	.2byte ITEM_TEACHY_TV
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gTeachyTVItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 2
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TRI-PASS$", 14
	.2byte ITEM_TRI_PASS
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gTriPassItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RAINBOW PASS$", 14
	.2byte ITEM_RAINBOW_PASS
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRainbowPassItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "TEA$", 14
	.2byte ITEM_TEA
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gTeaItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MYSTICTICKET$", 14
	.2byte ITEM_MYSTIC_TICKET
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMysticTicketItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "AURORATICKET$", 14
	.2byte ITEM_AURORA_TICKET
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gAuroraTicketItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "POWDER JAR$", 14
	.2byte ITEM_POWDER_JAR
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gPowderJarItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_PowderJar
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "RUBY$", 14
	.2byte ITEM_RUBY
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gRubyItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "SAPPHIRE$", 14
	.2byte ITEM_SAPPHIRE
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gSapphireItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "MAGMA EMBLEM$", 14
	.2byte ITEM_MAGMA_EMBLEM
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gMagmaEmblemItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

	.string "OLD SEA MAP$", 14
	.2byte ITEM_OLD_SEA_MAP
	.2byte 0 @ price
	.byte 0
	.byte 0
	.4byte gOldSeaMapItemDescription
	.byte 1
	.byte 1
	.byte BAG_KEYITEMS
	.byte 4
	.4byte ItemUseOutOfBattle_CannotUse
	.4byte 0
	.4byte NULL
	.4byte 0

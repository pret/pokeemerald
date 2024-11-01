
PitShop_ShopNPC::
	lock
	faceplayer
	setvar VAR_TEMP_9, 0
PitShop_ShopNPCHook::
	message PitShop_ShopNPC_Text
#ifdef PIT_GEN_3_MODE
	goto_if_unset FLAG_STAT_CHANGER, PitShop_ShopNPCHook_Gen3IVs
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
#elif defined PIT_GEN_5_MODE
	goto_if_unset FLAG_STAT_CHANGER, PitShop_ShopNPCHook_Gen5IVs
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_Option4, PitShop_ShopNPC_Option6, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
#else
	goto_if_unset FLAG_STAT_CHANGER, PitShop_ShopNPCHook_Gen9IVs
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option0_100, PitShop_ShopNPC_Option0_200, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_Option2, PitShop_ShopNPC_Option3, PitShop_ShopNPC_Option4, PitShop_ShopNPC_Option5, PitShop_ShopNPC_Option6, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
#endif
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
#ifdef PIT_GEN_3_MODE
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_Sell
#elif defined PIT_GEN_5_MODE
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_Sell
#else
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_TMs_100
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_TMs_200
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_MegaStones
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 7, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 8, PitArena_MartScript_ZCrystals
	goto_if_eq VAR_RESULT, 9, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 10, PitArena_MartScript_Sell
#endif
EndOfMartScript::
	clearflag FLAG_SELL_FROM_MART
	clearflag FLAG_BUY_FROM_MART
	release
	end

PitShop_ShopNPCHook_Gen9IVs::
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option0_100, PitShop_ShopNPC_Option0_200, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_Option2, PitShop_ShopNPC_Option3, PitShop_ShopNPC_Option4, PitShop_ShopNPC_Option5, PitShop_ShopNPC_Option6, PitShop_ShopNPC_EditIVs, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_TMs_100
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_TMs_200
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_MegaStones
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 7, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 8, PitArena_MartScript_ZCrystals
	goto_if_eq VAR_RESULT, 9, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 10, PitArena_MartScript_EditIVs
	goto_if_eq VAR_RESULT, 11, PitArena_MartScript_Sell
	release
	end

PitShop_ShopNPCHook_Gen5IVs::
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_Option4, PitShop_ShopNPC_Option6, PitShop_ShopNPC_EditIVs, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_EditIVs
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_Sell
	release
	end

PitShop_ShopNPCHook_Gen3IVs::
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitShop_ShopNPC_Option0, PitShop_ShopNPC_Option1, PitShop_ShopNPC_OptionVitamin, PitShop_ShopNPC_EditIVs, PitShop_ShopNPC_Option7, PitShop_ShopNPC_Option8
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_EditIVs
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Sell
	release
	end

PitArena_MartScript_Vitamins::
	lock
	setflag FLAG_BUY_FROM_MART
	goto_if_set FLAG_HARD_MODE, PitArena_MartScript_Vitamins_2
	pokemart PitArena_Mart_Vitamins
PitArena_MartScript_Vitamins_1:
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return

PitArena_MartScript_Vitamins_2:
	pokemart PitArena_Mart_Vitamins_HARD
	goto PitArena_MartScript_Vitamins_1

PitArena_MartScript_TMs:
	setflag FLAG_BUY_FROM_MART
	setflag FLAG_TM_SHOP
	pokemart PitArena_Mart_TMs
	clearflag FLAG_TM_SHOP
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_TMs_100:
	setflag FLAG_BUY_FROM_MART
	setflag FLAG_TM_SHOP
	pokemart PitArena_Mart_TMs_100
	clearflag FLAG_TM_SHOP
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_TMs_200:
	setflag FLAG_BUY_FROM_MART
	setflag FLAG_TM_SHOP
	pokemart PitArena_Mart_TMs_200
	clearflag FLAG_TM_SHOP
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_EvoItems:
	setflag FLAG_BUY_FROM_MART
	pokemart PitArena_Mart_EvoItems
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_MegaStones:
	pokemart PitArena_Mart_MegaStones
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Mints::
	pokemart PitArena_Mart_Mints
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Gems::
	pokemart PitArena_Mart_Gems
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_ZCrystals::
	pokemart PitArena_Mart_ZCrystals
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_FormItems::
	pokemart PitArena_Mart_FormItems
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_EditIVs::
	showmoneybox 0, 0
	msgbox PitShop_ShopNPC_IV_Text, MSGBOX_YESNO
	hidemoneybox
	goto_if_eq VAR_RESULT, NO, PitShop_ShopNPCHook
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, PitArena_MartScript_EditIVs_NotEnoughMoney
	removemoney 1000
	call PitArena_MartScript_EditIVs_Execute
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Sell::
	clearflag FLAG_BUY_FROM_MART
	setflag FLAG_SELL_FROM_MART
	pokemart PitArena_Mart_EvoItems
	goto PitShop_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_EditIVs_NotEnoughMoney::
	msgbox PitArena_Tutor_NotGotTheMoney, MSGBOX_DEFAULT
	goto PitShop_ShopNPCHook
	release
	end

PitArena_MartScript_EditIVs_Execute::
	setvar VAR_PIT_TUTOR_STATE, 3
	setflag FLAG_STAT_EDIT_PAID
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PitShop_ShopNPCHook
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PitShop_ShopNPCHook
	special CallStatEditor
	waitstate
	goto PitShop_ShopNPCHook
	release
	end


PitShop_ShopNPC_Option0:
#ifdef PIT_GEN_9_MODE
	.string "TMs A-F$"
#else
	.string "TMs    $"
#endif
PitShop_ShopNPC_Option0_100:
	.string "TMs G-R$"
PitShop_ShopNPC_Option0_200:
	.string "TMs S-Z & HMs$"
PitShop_ShopNPC_Option1:
	.string "Evos$"
PitShop_ShopNPC_Option2:
	.string "Megas$"
PitShop_ShopNPC_Option3:
	.string "Mints   $"
PitShop_ShopNPC_Option4:
	.string "Gems$"
PitShop_ShopNPC_Option5:
	.string "Z-Moves$"
PitShop_ShopNPC_Option6:
	.string "Forms$"
PitShop_ShopNPC_Option7:
	.string "Sell$"
PitShop_ShopNPC_Option8:
	.string "Exit$"
PitShop_ShopNPC_EditIVs:
	.string "Edit IVs$"
PitTutor_MoveRelearnerText:
	.string "Move Relearner (free)$"
PitArena_EggMovesText:
	.string "Egg Moves (¥10,000/ea)$"
PitArena_TutorMovesText:
	.string "Tutor Moves (¥10,000/ea)$"
PitArena_PreEvoMovesText:
	.string "PreEvo Moves (¥5,000/ea)$"
PitShop_ShopNPC_OptionVitamin:
	.string "Vitamins$"
PitShop_ShopNPC_Text:
	.string "How may I assist you?$"
PitShop_ShopNPC_IV_Text:
	.string "Your Pokémon are at max IVs by default.\n"
	.string "Still want to change it for ¥1,000?$"

PitArena_Tutor_ConfirmMoveSelection_Text_0:
	.string "The move {STR_VAR_1}, is it?$"
PitArena_Tutor_ConfirmMoveSelection_Text_1:
	.string "That will be ¥{STR_VAR_2}, okay?$"
PitArena_Tutor_ConfirmMoveSelection_Text_2:
	.string "Alright. Come back anytime you want.$"
PitArena_Tutor_NotGotTheMoney:
	.string "Oh, you don't have enough money!$"


	.align 2
PitArena_Mart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
#ifndef PIT_GEN_3_MODE
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
#endif
	.2byte ITEM_NONE
	release
	end

.align 2
PitArena_Mart_Vitamins_HARD:
	.2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
#ifndef PIT_GEN_3_MODE
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
#endif
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_EvoItems:
#ifdef PIT_GEN_3_MODE
	.2byte  ITEM_METEORITE
#endif
	.2byte ITEM_EVERSTONE
    .2byte ITEM_FIRE_STONE
    .2byte ITEM_WATER_STONE
    .2byte ITEM_THUNDER_STONE
    .2byte ITEM_SUN_STONE
    .2byte ITEM_MOON_STONE
    .2byte ITEM_LEAF_STONE
    .2byte ITEM_LINKING_CORD
    .2byte ITEM_DRAGON_SCALE
    .2byte ITEM_UPGRADE
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_METAL_COAT
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_DEEP_SEA_TOOTH
    .2byte ITEM_DEEP_SEA_SCALE
#ifndef PIT_GEN_3_MODE
	.2byte ITEM_DAWN_STONE
    .2byte ITEM_DUSK_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_OVAL_STONE
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_PROTECTOR
    .2byte ITEM_ELECTIRIZER
    .2byte ITEM_MAGMARIZER
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_DUBIOUS_DISC
    .2byte ITEM_REAPER_CLOTH
#endif
#ifdef PIT_GEN_9_MODE
    .2byte ITEM_ICE_STONE
    .2byte ITEM_WHIPPED_DREAM
    .2byte ITEM_SACHET
    .2byte ITEM_SWEET_APPLE
    .2byte ITEM_TART_APPLE
    .2byte ITEM_SYRUPY_APPLE
    .2byte ITEM_CRACKED_POT
    .2byte ITEM_CHIPPED_POT
    .2byte ITEM_GALARICA_CUFF
    .2byte ITEM_GALARICA_WREATH
    .2byte ITEM_SCROLL_OF_DARKNESS
    .2byte ITEM_SCROLL_OF_WATERS
	.2byte ITEM_BLACK_AUGURITE
    .2byte ITEM_PEAT_BLOCK
	.2byte ITEM_AUSPICIOUS_ARMOR
    .2byte ITEM_MALICIOUS_ARMOR
    .2byte ITEM_LEADERS_CREST
    .2byte ITEM_GIMMIGHOUL_COIN
    .2byte ITEM_UNREMARKABLE_TEACUP
    .2byte ITEM_MASTERPIECE_TEACUP
    .2byte ITEM_METAL_ALLOY
	.2byte ITEM_STRAWBERRY_SWEET
    .2byte ITEM_LOVE_SWEET
    .2byte ITEM_BERRY_SWEET
    .2byte ITEM_CLOVER_SWEET
    .2byte ITEM_FLOWER_SWEET
    .2byte ITEM_STAR_SWEET
    .2byte ITEM_RIBBON_SWEET
#endif
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_MegaStones:
	.2byte ITEM_RED_ORB
    .2byte ITEM_BLUE_ORB
	.2byte ITEM_VENUSAURITE
    .2byte ITEM_CHARIZARDITE_X
    .2byte ITEM_CHARIZARDITE_Y
    .2byte ITEM_BLASTOISINITE
    .2byte ITEM_BEEDRILLITE
    .2byte ITEM_PIDGEOTITE
    .2byte ITEM_ALAKAZITE
    .2byte ITEM_SLOWBRONITE
    .2byte ITEM_GENGARITE
    .2byte ITEM_KANGASKHANITE
    .2byte ITEM_PINSIRITE
    .2byte ITEM_GYARADOSITE
    .2byte ITEM_AERODACTYLITE
    .2byte ITEM_MEWTWONITE_X
    .2byte ITEM_MEWTWONITE_Y
    .2byte ITEM_AMPHAROSITE
    .2byte ITEM_STEELIXITE
    .2byte ITEM_SCIZORITE
    .2byte ITEM_HERACRONITE
    .2byte ITEM_HOUNDOOMINITE
    .2byte ITEM_TYRANITARITE
    .2byte ITEM_SCEPTILITE
    .2byte ITEM_BLAZIKENITE
    .2byte ITEM_SWAMPERTITE
    .2byte ITEM_GARDEVOIRITE
    .2byte ITEM_SABLENITE
    .2byte ITEM_MAWILITE
    .2byte ITEM_AGGRONITE
    .2byte ITEM_MEDICHAMITE
    .2byte ITEM_MANECTITE
    .2byte ITEM_SHARPEDONITE
    .2byte ITEM_CAMERUPTITE
    .2byte ITEM_ALTARIANITE
    .2byte ITEM_BANETTITE
    .2byte ITEM_ABSOLITE
    .2byte ITEM_GLALITITE
    .2byte ITEM_SALAMENCITE
    .2byte ITEM_METAGROSSITE
    .2byte ITEM_LATIASITE
    .2byte ITEM_LATIOSITE
    .2byte ITEM_LOPUNNITE
    .2byte ITEM_GARCHOMPITE
    .2byte ITEM_LUCARIONITE
    .2byte ITEM_ABOMASITE
    .2byte ITEM_GALLADITE
    .2byte ITEM_AUDINITE
    .2byte ITEM_DIANCITE
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_Mints:
	.2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_ABILITY_PATCH
	.2byte ITEM_LONELY_MINT
    .2byte ITEM_ADAMANT_MINT
    .2byte ITEM_NAUGHTY_MINT
    .2byte ITEM_BRAVE_MINT
    .2byte ITEM_BOLD_MINT
    .2byte ITEM_IMPISH_MINT
    .2byte ITEM_LAX_MINT
    .2byte ITEM_RELAXED_MINT
    .2byte ITEM_MODEST_MINT
    .2byte ITEM_MILD_MINT
    .2byte ITEM_RASH_MINT
    .2byte ITEM_QUIET_MINT
    .2byte ITEM_CALM_MINT
    .2byte ITEM_GENTLE_MINT
    .2byte ITEM_CAREFUL_MINT
    .2byte ITEM_SASSY_MINT
    .2byte ITEM_TIMID_MINT
    .2byte ITEM_HASTY_MINT
    .2byte ITEM_JOLLY_MINT
    .2byte ITEM_NAIVE_MINT
    .2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_Gems:
    .2byte ITEM_NORMAL_GEM
    .2byte ITEM_FIRE_GEM
    .2byte ITEM_WATER_GEM
    .2byte ITEM_ELECTRIC_GEM
    .2byte ITEM_GRASS_GEM
    .2byte ITEM_ICE_GEM
    .2byte ITEM_FIGHTING_GEM
    .2byte ITEM_POISON_GEM
    .2byte ITEM_GROUND_GEM
    .2byte ITEM_FLYING_GEM
    .2byte ITEM_PSYCHIC_GEM
    .2byte ITEM_BUG_GEM
    .2byte ITEM_ROCK_GEM
    .2byte ITEM_GHOST_GEM
    .2byte ITEM_DRAGON_GEM
    .2byte ITEM_DARK_GEM
    .2byte ITEM_STEEL_GEM
    .2byte ITEM_FAIRY_GEM
	.2byte ITEM_NONE
	release
	end

 	.align 2
PitArena_Mart_ZCrystals:
    .2byte ITEM_NORMALIUM_Z
    .2byte ITEM_FIRIUM_Z
    .2byte ITEM_WATERIUM_Z
    .2byte ITEM_ELECTRIUM_Z
    .2byte ITEM_GRASSIUM_Z
    .2byte ITEM_ICIUM_Z
    .2byte ITEM_FIGHTINIUM_Z
    .2byte ITEM_POISONIUM_Z
    .2byte ITEM_GROUNDIUM_Z
    .2byte ITEM_FLYINIUM_Z
    .2byte ITEM_PSYCHIUM_Z
    .2byte ITEM_BUGINIUM_Z
    .2byte ITEM_ROCKIUM_Z
    .2byte ITEM_GHOSTIUM_Z
    .2byte ITEM_DRAGONIUM_Z
    .2byte ITEM_DARKINIUM_Z
    .2byte ITEM_STEELIUM_Z
    .2byte ITEM_FAIRIUM_Z
    .2byte ITEM_PIKANIUM_Z
    .2byte ITEM_EEVIUM_Z
    .2byte ITEM_SNORLIUM_Z
    .2byte ITEM_MEWNIUM_Z
    .2byte ITEM_DECIDIUM_Z
    .2byte ITEM_INCINIUM_Z
    .2byte ITEM_PRIMARIUM_Z
    .2byte ITEM_LYCANIUM_Z
    .2byte ITEM_MIMIKIUM_Z
    .2byte ITEM_KOMMONIUM_Z
    .2byte ITEM_TAPUNIUM_Z
    .2byte ITEM_SOLGANIUM_Z
    .2byte ITEM_LUNALIUM_Z
    .2byte ITEM_MARSHADIUM_Z
    .2byte ITEM_ALORAICHIUM_Z
    .2byte ITEM_PIKASHUNIUM_Z
    .2byte ITEM_ULTRANECROZIUM_Z
	.2byte ITEM_NONE
    release
	end

 	.align 2
PitArena_Mart_FormItems:
	.2byte  ITEM_METEORITE
    .2byte  ITEM_DNA_SPLICERS
	.2byte  ITEM_GRACIDEA
	.2byte  ITEM_GRISEOUS_CORE
	.2byte  ITEM_ROTOM_CATALOG
	.2byte  ITEM_REVEAL_GLASS
#ifdef PIT_GEN_9_MODE
	.2byte  ITEM_PRISON_BOTTLE
	.2byte  ITEM_ADAMANT_CRYSTAL
	.2byte  ITEM_LUSTROUS_ORB
	.2byte  ITEM_N_SOLARIZER
    .2byte  ITEM_N_LUNARIZER
    .2byte  ITEM_RUSTED_SWORD
    .2byte  ITEM_RUSTED_SHIELD
    .2byte  ITEM_REINS_OF_UNITY
#endif
    .2byte  ITEM_DOUSE_DRIVE
    .2byte  ITEM_SHOCK_DRIVE
    .2byte  ITEM_BURN_DRIVE
    .2byte  ITEM_CHILL_DRIVE
    .2byte  ITEM_FLAME_PLATE
    .2byte  ITEM_SPLASH_PLATE
    .2byte  ITEM_ZAP_PLATE
    .2byte  ITEM_MEADOW_PLATE
    .2byte  ITEM_ICICLE_PLATE
    .2byte  ITEM_FIST_PLATE
    .2byte  ITEM_TOXIC_PLATE
    .2byte  ITEM_EARTH_PLATE
    .2byte  ITEM_SKY_PLATE
    .2byte  ITEM_MIND_PLATE
    .2byte  ITEM_INSECT_PLATE
    .2byte  ITEM_STONE_PLATE
    .2byte  ITEM_SPOOKY_PLATE
    .2byte  ITEM_DRACO_PLATE
    .2byte  ITEM_DREAD_PLATE
    .2byte  ITEM_IRON_PLATE
    .2byte  ITEM_PIXIE_PLATE
#ifdef PIT_GEN_9_MODE
	.2byte  ITEM_YELLOW_NECTAR
    .2byte  ITEM_PINK_NECTAR
    .2byte  ITEM_PURPLE_NECTAR
	.2byte  ITEM_FIRE_MEMORY
    .2byte  ITEM_WATER_MEMORY
    .2byte  ITEM_ELECTRIC_MEMORY
    .2byte  ITEM_GRASS_MEMORY
    .2byte  ITEM_ICE_MEMORY
    .2byte  ITEM_FIGHTING_MEMORY
    .2byte  ITEM_POISON_MEMORY
    .2byte  ITEM_GROUND_MEMORY
    .2byte  ITEM_FLYING_MEMORY
    .2byte  ITEM_PSYCHIC_MEMORY
    .2byte  ITEM_BUG_MEMORY
    .2byte  ITEM_ROCK_MEMORY
    .2byte  ITEM_GHOST_MEMORY
    .2byte  ITEM_DRAGON_MEMORY
    .2byte  ITEM_DARK_MEMORY
    .2byte  ITEM_STEEL_MEMORY
    .2byte  ITEM_FAIRY_MEMORY
#endif
	.2byte ITEM_NONE
    release
	end

 	.align 2
PitArena_Mart_TMs:
#ifdef PIT_GEN_3_MODE
	.2byte ITEM_TM40
	.2byte ITEM_TM45
	.2byte ITEM_TM14
	.2byte ITEM_TM66
	.2byte ITEM_TM31
	.2byte ITEM_TM08
	.2byte ITEM_TM09
	.2byte ITEM_TM04
	.2byte ITEM_TM68
	.2byte ITEM_TM71
	.2byte ITEM_TM28
	.2byte ITEM_TM51
	.2byte ITEM_TM32
	.2byte ITEM_TM02
	.2byte ITEM_TM63
	.2byte ITEM_TM52
	.2byte ITEM_TM26
	.2byte ITEM_TM76
	.2byte ITEM_TM53
	.2byte ITEM_TM42
	.2byte ITEM_TM38
	.2byte ITEM_TM80
	.2byte ITEM_TM35
	.2byte ITEM_TM01
	.2byte ITEM_TM21
	.2byte ITEM_TM54
	.2byte ITEM_TM19
	.2byte ITEM_TM07
	.2byte ITEM_TM10
	.2byte ITEM_TM15
	.2byte ITEM_TM13
	.2byte ITEM_TM78
	.2byte ITEM_TM75
	.2byte ITEM_TM23
	.2byte ITEM_TM16
	.2byte ITEM_TM65
	.2byte ITEM_TM64
	.2byte ITEM_TM55
	.2byte ITEM_TM56
	.2byte ITEM_TM73
	.2byte ITEM_TM50
	.2byte ITEM_TM17
	.2byte ITEM_TM77
	.2byte ITEM_TM29
	.2byte ITEM_TM18
	.2byte ITEM_TM33
	.2byte ITEM_TM44
	.2byte ITEM_TM27
	.2byte ITEM_TM05
	.2byte ITEM_TM67
	.2byte ITEM_TM39
	.2byte ITEM_TM57
	.2byte ITEM_TM20
	.2byte ITEM_TM37
	.2byte ITEM_TM43
	.2byte ITEM_TM62
	.2byte ITEM_TM30
	.2byte ITEM_TM34
	.2byte ITEM_TM48
	.2byte ITEM_TM58
	.2byte ITEM_TM36
	.2byte ITEM_TM49
	.2byte ITEM_TM72
	.2byte ITEM_TM61
	.2byte ITEM_TM22
	.2byte ITEM_TM47
	.2byte ITEM_TM59
	.2byte ITEM_TM11
	.2byte ITEM_TM60
	.2byte ITEM_TM74
	.2byte ITEM_TM70
	.2byte ITEM_TM12
	.2byte ITEM_TM46
	.2byte ITEM_TM25
	.2byte ITEM_TM79
	.2byte ITEM_TM69
	.2byte ITEM_TM24
	.2byte ITEM_TM41
	.2byte ITEM_TM06
	.2byte ITEM_TM03
#endif
#ifdef PIT_GEN_5_MODE
	.2byte ITEM_TM62
	.2byte ITEM_TM40
	.2byte ITEM_TM51
	.2byte ITEM_TM45
	.2byte ITEM_TM14
	.2byte ITEM_TM31
	.2byte ITEM_TM08
	.2byte ITEM_TM78
	.2byte ITEM_TM96
	.2byte ITEM_TM04
	.2byte ITEM_TM57
	.2byte ITEM_TM28
	.2byte ITEM_TM32
	.2byte ITEM_TM02
	.2byte ITEM_TM82
	.2byte ITEM_TM85
	.2byte ITEM_TM26
	.2byte ITEM_TM49
	.2byte ITEM_TM63
	.2byte ITEM_TM53
	.2byte ITEM_TM64
	.2byte ITEM_TM42
	.2byte ITEM_TM54
	.2byte ITEM_TM38
	.2byte ITEM_TM43
	.2byte ITEM_TM35
	.2byte ITEM_TM91
	.2byte ITEM_TM56
	.2byte ITEM_TM52
	.2byte ITEM_TM70
	.2byte ITEM_TM79
	.2byte ITEM_TM21
	.2byte ITEM_TM97
	.2byte ITEM_TM68
	.2byte ITEM_TM86
	.2byte ITEM_TM74
	.2byte ITEM_TM07
	.2byte ITEM_TM10
	.2byte ITEM_TM01
	.2byte ITEM_TM15
	.2byte ITEM_TM13
	.2byte ITEM_TM59
	.2byte ITEM_TM98
	.2byte ITEM_TM16
	.2byte ITEM_TM47
	.2byte ITEM_TM50
	.2byte ITEM_TM66
	.2byte ITEM_TM88
	.2byte ITEM_TM84
	.2byte ITEM_TM17
	.2byte ITEM_TM77
	.2byte ITEM_TM29
	.2byte ITEM_TM03
	.2byte ITEM_TM60
	.2byte ITEM_TM18
	.2byte ITEM_TM33
	.2byte ITEM_TM44
	.2byte ITEM_TM67
	.2byte ITEM_TM27
	.2byte ITEM_TM05
	.2byte ITEM_TM69
	.2byte ITEM_TM80
	.2byte ITEM_TM39
	.2byte ITEM_TM48
	.2byte ITEM_TM20
	.2byte ITEM_TM37
	.2byte ITEM_TM55
	.2byte ITEM_TM30
	.2byte ITEM_TM65
	.2byte ITEM_TM99
	.2byte ITEM_TM100
	.2byte ITEM_TM58
	.2byte ITEM_TM36
	.2byte ITEM_TM34
	.2byte ITEM_TM23
	.2byte ITEM_TM95
	.2byte ITEM_TM22
	.2byte ITEM_TM71
	.2byte ITEM_TM76
	.2byte ITEM_TM90
	.2byte ITEM_TM11
	.2byte ITEM_TM87
	.2byte ITEM_TM75
	.2byte ITEM_TM12
	.2byte ITEM_TM19
	.2byte ITEM_TM46
	.2byte ITEM_TM25
	.2byte ITEM_TM73
	.2byte ITEM_TM24
	.2byte ITEM_TM41
	.2byte ITEM_TM06
	.2byte ITEM_TM92
	.2byte ITEM_TM89
	.2byte ITEM_TM09
	.2byte ITEM_TM72
	.2byte ITEM_TM94
	.2byte ITEM_TM93
	.2byte ITEM_TM61
	.2byte ITEM_TM83
	.2byte ITEM_TM81
#endif
#ifdef PIT_GEN_9_MODE
	.2byte ITEM_TM13
	.2byte ITEM_TM14
	.2byte ITEM_TM27
	.2byte ITEM_TM04
	.2byte ITEM_TM40
	.2byte ITEM_TM65
	.2byte ITEM_TM227
	.2byte ITEM_TM128
	.2byte ITEM_TM112
	.2byte ITEM_TM46
	.2byte ITEM_TM132
	.2byte ITEM_TM153
	.2byte ITEM_TM143
	.2byte ITEM_TM89
	.2byte ITEM_TM66
	.2byte ITEM_TM164
	.2byte ITEM_TM222
	.2byte ITEM_TM58
	.2byte ITEM_TM182
	.2byte ITEM_TM162
	.2byte ITEM_TM64
	.2byte ITEM_TM28
	.2byte ITEM_TM56
	.2byte ITEM_TM195
	.2byte ITEM_TM129
	.2byte ITEM_TM173
	.2byte ITEM_TM23
	.2byte ITEM_TM02
	.2byte ITEM_TM22
	.2byte ITEM_TM167
	.2byte ITEM_TM213
	.2byte ITEM_TM17
	.2byte ITEM_TM108
	.2byte ITEM_TM224
	.2byte ITEM_TM94
	.2byte ITEM_TM79
	.2byte ITEM_TM55
	.2byte ITEM_TM19
	.2byte ITEM_TM204
	.2byte ITEM_TM169
	.2byte ITEM_TM226
	.2byte ITEM_TM78
	.2byte ITEM_TM100
	.2byte ITEM_TM115
	.2byte ITEM_TM44
	.2byte ITEM_TM73
	.2byte ITEM_TM37
	.2byte ITEM_TM106
	.2byte ITEM_TM197
	.2byte ITEM_TM133
	.2byte ITEM_TM149
	.2byte ITEM_TM96
	.2byte ITEM_TM136
	.2byte ITEM_TM72
	.2byte ITEM_TM211
	.2byte ITEM_TM122
	.2byte ITEM_TM205
	.2byte ITEM_TM47
	.2byte ITEM_TM119
	.2byte ITEM_TM218
	.2byte ITEM_TM25
	.2byte ITEM_TM03
	.2byte ITEM_TM57
	.2byte ITEM_TM216
	.2byte ITEM_TM141
	.2byte ITEM_TM08
	.2byte ITEM_TM144
	.2byte ITEM_TM67
	.2byte ITEM_TM24
	.2byte ITEM_TM38
	.2byte ITEM_TM125
	.2byte ITEM_TM165
	.2byte ITEM_TM93
	.2byte ITEM_TM43
	.2byte ITEM_TM196
	.2byte ITEM_TM158
	.2byte ITEM_TM192
	.2byte ITEM_TM62
	.2byte ITEM_TM155
	.2byte ITEM_TM217
#endif
#ifndef PIT_GEN_9_MODE
	.2byte ITEM_HM01
	.2byte ITEM_HM02
	.2byte ITEM_HM03
	.2byte ITEM_HM04
	.2byte ITEM_HM05
	.2byte ITEM_HM06
	.2byte ITEM_HM07
	.2byte ITEM_HM08
#endif
	.2byte ITEM_NONE
    release
	end

 	.align 2
PitArena_Mart_TMs_100:
	.2byte ITEM_TM111
	.2byte ITEM_TM152
	.2byte ITEM_TM81
	.2byte ITEM_TM146
	.2byte ITEM_TM194
	.2byte ITEM_TM137
	.2byte ITEM_TM178
	.2byte ITEM_TM102
	.2byte ITEM_TM180
	.2byte ITEM_TM225
	.2byte ITEM_TM174
	.2byte ITEM_TM189
	.2byte ITEM_TM118
	.2byte ITEM_TM121
	.2byte ITEM_TM130
	.2byte ITEM_TM29
	.2byte ITEM_TM230
	.2byte ITEM_TM186
	.2byte ITEM_TM160
	.2byte ITEM_TM154
	.2byte ITEM_TM142
	.2byte ITEM_TM163
	.2byte ITEM_TM117
	.2byte ITEM_TM135
	.2byte ITEM_TM10
	.2byte ITEM_TM69
	.2byte ITEM_TM124
	.2byte ITEM_TM187
	.2byte ITEM_TM34
	.2byte ITEM_TM92
	.2byte ITEM_TM104
	.2byte ITEM_TM99
	.2byte ITEM_TM181
	.2byte ITEM_TM199
	.2byte ITEM_TM159
	.2byte ITEM_TM95
	.2byte ITEM_TM75
	.2byte ITEM_TM110
	.2byte ITEM_TM12
	.2byte ITEM_TM39
	.2byte ITEM_TM185
	.2byte ITEM_TM33
	.2byte ITEM_TM31
	.2byte ITEM_TM223
	.2byte ITEM_TM220
	.2byte ITEM_TM80
	.2byte ITEM_TM201
	.2byte ITEM_TM139
	.2byte ITEM_TM35
	.2byte ITEM_TM05
	.2byte ITEM_TM209
	.2byte ITEM_TM140
	.2byte ITEM_TM42
	.2byte ITEM_TM156
	.2byte ITEM_TM157
	.2byte ITEM_TM202
	.2byte ITEM_TM206
	.2byte ITEM_TM151
	.2byte ITEM_TM127
	.2byte ITEM_TM83
	.2byte ITEM_TM26
	.2byte ITEM_TM131
	.2byte ITEM_TM198
	.2byte ITEM_TM21
	.2byte ITEM_TM101
	.2byte ITEM_TM07
	.2byte ITEM_TM16
	.2byte ITEM_TM203
	.2byte ITEM_TM120
	.2byte ITEM_TM63
	.2byte ITEM_TM228
	.2byte ITEM_TM138
	.2byte ITEM_TM54
	.2byte ITEM_TM50
	.2byte ITEM_TM74
	.2byte ITEM_TM85
	.2byte ITEM_TM134
	.2byte ITEM_TM172
	.2byte ITEM_TM76
	.2byte ITEM_TM86
	.2byte ITEM_TM36
    release
	end

 	.align 2
PitArena_Mart_TMs_200:
	.2byte ITEM_TM176
	.2byte ITEM_TM51
	.2byte ITEM_TM188
	.2byte ITEM_TM200
	.2byte ITEM_TM06
	.2byte ITEM_TM215
	.2byte ITEM_TM71
	.2byte ITEM_TM114
	.2byte ITEM_TM61
	.2byte ITEM_TM98
	.2byte ITEM_TM219
	.2byte ITEM_TM70
	.2byte ITEM_TM148
	.2byte ITEM_TM214
	.2byte ITEM_TM179
	.2byte ITEM_TM53
	.2byte ITEM_TM30
	.2byte ITEM_TM52
	.2byte ITEM_TM168
	.2byte ITEM_TM190
	.2byte ITEM_TM90
	.2byte ITEM_TM177
	.2byte ITEM_TM116
	.2byte ITEM_TM170
	.2byte ITEM_TM84
	.2byte ITEM_TM150
	.2byte ITEM_TM41
	.2byte ITEM_TM15
	.2byte ITEM_TM103
	.2byte ITEM_TM49
	.2byte ITEM_TM183
	.2byte ITEM_TM210
	.2byte ITEM_TM32
	.2byte ITEM_TM88
	.2byte ITEM_TM113
	.2byte ITEM_TM01
	.2byte ITEM_TM87
	.2byte ITEM_TM207
	.2byte ITEM_TM171
	.2byte ITEM_TM18
	.2byte ITEM_TM221
	.2byte ITEM_TM166
	.2byte ITEM_TM09
	.2byte ITEM_TM68
	.2byte ITEM_TM82
	.2byte ITEM_TM126
	.2byte ITEM_TM175
	.2byte ITEM_TM91
	.2byte ITEM_TM20
	.2byte ITEM_TM109
	.2byte ITEM_TM161
	.2byte ITEM_TM212
	.2byte ITEM_TM60
	.2byte ITEM_TM229
	.2byte ITEM_TM191
	.2byte ITEM_TM184
	.2byte ITEM_TM45
	.2byte ITEM_TM48
	.2byte ITEM_TM145
	.2byte ITEM_TM11
	.2byte ITEM_TM193
	.2byte ITEM_TM208
	.2byte ITEM_TM147
	.2byte ITEM_TM107
	.2byte ITEM_TM105
	.2byte ITEM_TM59
	.2byte ITEM_HM01
	.2byte ITEM_HM02
	.2byte ITEM_HM03
	.2byte ITEM_HM04
	.2byte ITEM_HM05
	.2byte ITEM_HM06
	.2byte ITEM_HM07
	.2byte ITEM_HM08
	.2byte ITEM_NONE
    release
	end

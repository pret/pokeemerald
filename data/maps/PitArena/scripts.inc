PitArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PitArena_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PitArena_OnFrame
	.byte 0

PitArena_OnFrame:
	map_script_2 VAR_FINAL_FLOOR, 1, PitArena_OnFrameFloor100
	map_script_2 VAR_REWARD_STATE, 1, PitArena_OnFrameRewardDrop
	.2byte 0

PitArena_OnFrameFloor100::
	lockall
	setvar VAR_REWARD_STATE, 2
	setvar VAR_FINAL_FLOOR, 2
	msgbox PitArena_EndGameStatue_Text1, MSGBOX_DEFAULT
	releaseall
	end

PitArena_OnFrameRewardDrop::
	lockall
	setvar VAR_REWARD_STATE, 2
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	addobject 6
	addobject 7
	callnative UpdateObjectEventsFromScript
	releaseall
	end

PitArena_OnResume:
	callnative CheckFloorCleared
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnResumeNormal
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_REWARD_STATE, 1
	setflashlevel 0
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnResumeNormal
	setflashlevel 1
PitArena_OnResumeNormal:
	end

PitArena_OnTransition:
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnTransitionNormal
PitArena_OnTransitionNormal::
	callnative StartTimer1Script
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_Warp::
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
	lockall
	addvar VAR_PIT_FLOOR, 1
	clearflag FLAG_FLOOR_CLEARED
	setflag FLAG_REWARD_ITEM_1
	setflag FLAG_REWARD_ITEM_2
	setvar VAR_REWARD_STATE, 0
	callnative BufferMapFloorString
	callnative SetRandomTrainers
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_WarpFloor100
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	goto PitArena_WarpEnd
PitArena_WarpFloor100::
	setvar VAR_FINAL_FLOOR, 1
	warpteleport MAP_PIT_ARENA, 9, 11
	waitstate
PitArena_WarpEnd::
	releaseall
	end

PitArena_EndGameStatue::
	lockall
	msgbox PitArena_EndGameStatue_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitArena_EndGameStatue2
	setvar VAR_REWARD_STATE, 2
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	additem 6
	additem 7
	callnative UpdateObjectEventsFromScript
	removeobject 10
	special HealPlayerParty
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	special DrawWholeMapView
	releaseall
	end

PitArena_EndGameStatue2::
	msgbox PitArena_EndGameStatue_Text3, MSGBOX_AUTOCLOSE 
	special GameClear
	waitstate
	releaseall
	end


PitArena_EndGameStatue_Text1:
	.string "Congratulations, you have.\n"
	.string "completed the Pit of 100\l"
	.string "Trials....\p"
	.string "I hope your descent was\n"
	.string "pleasant.$"

PitArena_EndGameStatue_Text2:
	.string "Do you want to keep going?$"

PitArena_EndGameStatue_Text3:
	.string "Well, thanks for playing!$"

PitArena_TrainerBattle::
	trainerbattle_single TRAINER_RANDOM_BATTLE_0, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end
PitArena_TrainerBattle1::
	trainerbattle_single TRAINER_RANDOM_BATTLE_1, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end
PitArena_TrainerBattle2::
	trainerbattle_single TRAINER_RANDOM_BATTLE_2, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end
PitArena_TrainerBattle3::
	trainerbattle_single TRAINER_RANDOM_BATTLE_3, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_Text_Intro:
	.string "$"

PitArena_Text_Defeat:
	.string "$"

PitArena_TrainerBattleFinished::
	end

PitArena_Debug::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setvar VAR_PIT_FLOOR, 24
	additem ITEM_RARE_CANDY, 99
	special DrawWholeMapView
	end

PitArena_Debug2::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 24
	special DrawWholeMapView
	end


PitArena_HealNPC::
	lockall
	faceplayer
	special HealPlayerParty
	msgbox PitArena_HealNPC_Text, MSGBOX_DEFAULT
	release
	end

PitArena_HealNPC_Text:
	.string "Your party has been healed.\p"
	.string "Have a nice descent.$"


PitArena_RewardDrop1::
	finditem ITEM_RARE_CANDY
	end

PitArena_RewardDrop2::
	finditem ITEM_RARE_CANDY
	end

PitArena_NewMon::
	lockall
	callnative PlayerPartyCountToResultVar
	goto_if_eq VAR_RESULT, 6, PitArena_PartyFullRemoveOne
PitArenaNewMon2::
	givemon VAR_PIT_FLOOR, 0
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PitArena_EventScript_ReceiveMonParty
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

PitArena_EventScript_ReceiveMonParty::
	bufferspeciesname STR_VAR_2, VAR_0x800A
	playfanfare MUS_OBTAIN_ITEM
	message PitArena_Text_ReceivedMon
	waitmessage
	waitfanfare
	removeobject 8
	releaseall
	end

PitArena_PartyFullRemoveOne::
	message PitArena_GiveMonFullNothingChosen_Text1
	waitbuttonpress
	msgbox PitArena_GiveMonFullNothingChosen_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitArena_FullPartyNothingChosen
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, PitArena_FullPartyNothingChosen
	callnative RemovePartyPokemon
	goto PitArenaNewMon2
	release
	end

PitArena_FullPartyNothingChosen::
	release
	end

PitArena_GiveMonFullNothingChosen_Text1:
	.string "Your party is too full.$"

PitArena_GiveMonFullNothingChosen_Text2:
	.string "Do you want to get rid\n"
	.string "of a party member?$"

PitArena_Text_ReceivedMon:
	.string "{PLAYER} pulled a {STR_VAR_2}\n"
	.string "from the bag.$"


PitArena_ShopNPC::
	lockall
	faceplayer
	message PitArena_ShopNPC_Text
	dynmultichoice 1, 1, 0, 6, 0, DYN_MULTICHOICE_CB_NONE, PitArena_ShopNPC_Option1, PitArena_ShopNPC_Option2, PitArena_ShopNPC_Option3, PitArena_ShopNPC_Option4
	closemessage
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_MegaStones
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Mints
	release
	end

PitArena_MartScript_EvoItems:
	pokemart PitArena_Mart_EvoItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_MegaStones:
	pokemart PitArena_Mart_MegaStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Mints::
	pokemart PitArena_Mart_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_ShopNPC_Option1:
	.string "Evo Items$"
PitArena_ShopNPC_Option2:
	.string "Mega Stones$"
PitArena_ShopNPC_Option3:
	.string "Nature Mints$"
PitArena_ShopNPC_Option4:
	.string "Exit$"

PitArena_ShopNPC_Text:
	.string "How may I assist you?$"

	.align 2
PitArena_Mart_EvoItems:
	.2byte ITEM_FIRE_STONE
    .2byte ITEM_WATER_STONE
    .2byte ITEM_THUNDER_STONE
    .2byte ITEM_LEAF_STONE
    .2byte ITEM_ICE_STONE
    .2byte ITEM_SUN_STONE
    .2byte ITEM_MOON_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
    .2byte ITEM_SWEET_APPLE
    .2byte ITEM_TART_APPLE
    .2byte ITEM_CRACKED_POT
    .2byte ITEM_CHIPPED_POT
    .2byte ITEM_GALARICA_CUFF
    .2byte ITEM_GALARICA_WREATH
    .2byte ITEM_DRAGON_SCALE
    .2byte ITEM_UPGRADE
    .2byte ITEM_PROTECTOR
    .2byte ITEM_ELECTIRIZER
    .2byte ITEM_MAGMARIZER
    .2byte ITEM_DUBIOUS_DISC
    .2byte ITEM_REAPER_CLOTH
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_WHIPPED_DREAM
    .2byte ITEM_SACHET
    .2byte ITEM_OVAL_STONE
    .2byte ITEM_STRAWBERRY_SWEET
    .2byte ITEM_LOVE_SWEET
    .2byte ITEM_BERRY_SWEET
    .2byte ITEM_CLOVER_SWEET
    .2byte ITEM_FLOWER_SWEET
    .2byte ITEM_STAR_SWEET
    .2byte ITEM_RIBBON_SWEET
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_MegaStones:
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

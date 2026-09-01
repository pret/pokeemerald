ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "We're the KANTO RIDER FEDERATION!\n"
	.string "Vroom! Vavavavooom! Vroom!\p"
	.string "My bike's wimpy, so I have to\n"
	.string "make exhaust noises myself!$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "Hey, hey, lady!\n"
	.string "Fork over some spending money!$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "Aiyeeh!\p"
	.string "Wh-who are you?!\n"
	.string "I… I'll call the police!$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "Those BIKERS…\n"
	.string "Are they gone?\p"
	.string "Oh, thank goodness!\n"
	.string "They certainly had me terrified!$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "Those BIKERS ran off, and\n"
	.string "LOSTELLE was found safe.\p"
	.string "Everything turned out for the best!$"


.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts:: @ 826ACAF
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume: @ 826ACC4
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition: @ 826ACD0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp: @ 826ACDE
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos:: @ 826ACE8
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame: @ 826ACF5
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor:: @ 826ACFF
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile:: @ 826AD0D
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMaster:: @ 826AD17
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1:: @ 826AD84
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2:: @ 826ADC0
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3:: @ 826ADFC
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4:: @ 826AE38
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5:: @ 826AE74
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM12
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6:: @ 826AEB0
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7:: @ 826AEEC
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8:: @ 826AF28
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	compare VAR_FACING, DIR_WEST
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	compare VAR_FACING, DIR_EAST
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	compare VAR_RESULT, FALSE
	call_if_eq Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent:: @ 826AFA5
	multichoice 0, 0, MULTI_TENT, 1
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent:: @ 826AFBF
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent:: @ 826AFC7
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit:: @ 826AFCF
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull:: @ 826AFEF
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent:: @ 826B002
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth:: @ 826B015
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth:: @ 826B020
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest:: @ 826B02B
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast:: @ 826B036
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger:: @ 826B041
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom: @ 826B089
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise: @ 826B08B
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe: @ 826B08D
	.string "Aak!\n"
	.string "You've made it to me?\l"
	.string "Hmmm… You're sharp!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees: @ 826B0BC
	.string "It took me all night to plant all those\n"
	.string "trees…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five, six places!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze: @ 826B13B
	.string "It took me all night to make the maze…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five places!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels: @ 826B1AD
	.string "It took me all night to prepare\n"
	.string "the wall panels…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four places!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders: @ 826B223
	.string "It took me all night to shove in those\n"
	.string "boulders…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three places!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls: @ 826B293
	.string "It took me all night to make MECHADOLLS\n"
	.string "and another to think up the quiz…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two places!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors: @ 826B315
	.string "It took me all night to install\n"
	.string "the doors…\p"
	.string "You're almost my equal in greatness!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows: @ 826B365
	.string "It took me all night setting up arrows…\p"
	.string "You're my equal in greatness!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors: @ 826B3AB
	.string "It took me all night polishing floors…\p"
	.string "You're above me in greatness!\n"
	.string "Possibly…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry: @ 826B3FA
	.string "Wh-what should I do?\n"
	.string "My fountain of ideas for tricks has\l"
	.string "run dry…\p"
	.string "Perhaps it is time I toured the country\n"
	.string "on a quest to devise new tricks…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent: @ 826B485
	.string "I hate to admit defeat, but you have\n"
	.string "bested me!\p"
	.string "Still, you must have been reeled in by\n"
	.string "my charisma for you to visit me again\l"
	.string "and again. Yes, you must have!\p"
	.string "But that has nothing to do with my\n"
	.string "losing!\p"
	.string "In recognition of the friendship\n"
	.string "between you, the driven, and the genius\l"
	.string "that is myself, I demand that you take\l"
	.string "this keepsake!\p"
	.string "Actually there are two--\n"
	.string "a RED TENT and a BLUE TENT.\l"
	.string "Which do you prefer?$"

Route110_TrickHouseEnd_Text_NoRoomInPC: @ 826B615
	.string "What? No room in your PC?\n"
	.string "What am I to make of that?\p"
	.string "I wish I could say that, but I am much\n"
	.string "too kind and caring, so come back later!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney: @ 826B69A
	.string "… … … … … …\p"
	.string "I am leaving on a journey of discovery.\n"
	.string "A quest in search of new tricks.\p"
	.string "I wish that you will one day visit and\n"
	.string "entertain me again.\p"
	.string "And now, farewell!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward: @ 826B73D
	.string "Fine!\n"
	.string "You have earned this reward!$"

Route110_TrickHouseEnd_Text_NoRoomForThis: @ 826B760
	.string "What? Have you no room for this?\n"
	.string "What manner of items do you carry?\p"
	.string "But fine, since you've reached me,\n"
	.string "your reward will be with me till later.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou: @ 826B7EF
	.string "Scrub that smug smirk from your face!\n"
	.string "It's much too early to think you've won!\p"
	.string "I'll make new tricks to stump you, I will.\n"
	.string "You may mock me only when you're done.\p"
	.string "Come back for the next exciting\n"
	.string "installment!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe: @ 826B8BD
	.string "Now, now! You're ignoring me now?\n"
	.string "Now that, I consider heartbreaking!$"


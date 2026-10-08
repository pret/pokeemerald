Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER_END
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
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

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
	removeobject LOCALID_TRICK_MASTER_END
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
	playse SE_PIN
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
	delay 20
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	delay 4
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak!\n"
	.string "Je bent tot bij mij gekomen?\l"
	.string "Hmmm… Jij bent slim!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Ik heb de hele nacht al die bomen\n"
	.string "geplant…\p"
	.string "Je bent bijna net zo goed als ik!\n"
	.string "Nog maar een, twee, drie, vier, vijf, zes!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Ik heb de hele nacht aan het\n"
	.string "doolhof gewerkt…\p"
	.string "Je bent bijna net zo goed als ik!\n"
	.string "Nog maar een, twee, drie, vier, vijf!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Ik heb de hele nacht aan de\n"
	.string "muurpanelen gewerkt…\p"
	.string "Je bent bijna net zo goed als ik!\n"
	.string "Nog maar een, twee, drie, vier!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Ik heb de hele nacht die rotsen\n"
	.string "op hun plek geduwd…\p"
	.string "Je bent bijna net zo goed als ik!\n"
	.string "Nog maar een, twee, drie!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Ik heb een nacht MECHADOLLS gemaakt\n"
	.string "en nog een nacht de quiz bedacht…\p"
	.string "Je bent bijna net zo goed als ik!\n"
	.string "Nog maar een, twee!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Ik heb de hele nacht die deuren\n"
	.string "gemaakt…\p"
	.string "Je bent bijna net zo goed als ik!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Ik heb de hele nacht pijlen neergelegd…\p"
	.string "Je bent net zo goed als ik!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Ik heb de hele nacht vloeren gepoetst…\p"
	.string "Je bent zelfs beter dan ik!\n"
	.string "Misschien…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "W-wat moet ik nu?\n"
	.string "Ik heb geen ideeën meer voor\l"
	.string "nieuwe trucs…\p"
	.string "Misschien moet ik op reis gaan\n"
	.string "om nieuwe trucs te bedenken…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Ik geef het niet graag toe, maar\n"
	.string "je hebt me verslagen!\p"
	.string "Maar je kwam steeds terug, dus je\n"
	.string "vindt mij vast heel geweldig.\l"
	.string "Ja, dat moet wel!\p"
	.string "Maar daarom heb ik niet\n"
	.string "verloren, hoor!\p"
	.string "Als teken van vriendschap tussen\n"
	.string "jou, de doorzetter, en mij, het\l"
	.string "genie, moet je dit aannemen!\p"
	.string "Eigenlijk zijn er twee--\n"
	.string "een RODE TENT en een BLAUWE TENT.\l"
	.string "Welke wil je?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Wat? Geen plek in je PC?\n"
	.string "Wat moet ik daar nou mee?\p"
	.string "Dat zou ik willen zeggen, maar ik ben\n"
	.string "veel te lief. Kom later maar terug!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "Ik ga op ontdekkingsreis.\n"
	.string "Op zoek naar nieuwe trucs.\p"
	.string "Ik hoop dat je ooit weer langskomt\n"
	.string "om me te vermaken.\p"
	.string "En nu, vaarwel!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Goed dan!\n"
	.string "Je hebt deze beloning verdiend!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Wat? Heb je hier geen plek voor?\n"
	.string "Wat sjouw jij allemaal mee?\p"
	.string "Maar goed, je bent tot bij mij gekomen.\n"
	.string "Ik bewaar je beloning nog even.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Haal die grijns van je gezicht!\n"
	.string "Je hebt nog lang niet gewonnen!\p"
	.string "Ik maak nieuwe trucs om je te\n"
	.string "verslaan.\p"
	.string "Lach me pas uit als je klaar bent.\p"
	.string "Kom terug voor het volgende\n"
	.string "spannende deel!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Nou, nou! Negeer je me nu?\n"
	.string "Dat breekt mijn hart!$"


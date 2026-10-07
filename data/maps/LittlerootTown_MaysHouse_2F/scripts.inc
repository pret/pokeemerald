LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos

LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 8, 2
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
	delay 10
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
	delay 10
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
	end

RivalsHouse_2F_EventScript_May::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_Brendan::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_MayPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "Hè?\n"
	.string "Wie… Wie ben jij?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "O, jij bent {PLAYER}{KUN}.\n"
	.string "Dus jullie zijn vandaag verhuisd.\p"
	.string "Eh… Ik ben MAY.\n"
	.string "Leuk je te ontmoeten!\p"
	.string "Ik…\n"
	.string "Ik droom ervan om vrienden te\l"
	.string "worden met POKéMON overal.\p"
	.string "Ik… Ik hoorde over jou, {PLAYER}{KUN},\n"
	.string "van mijn vader, PROF. BIRCH.\p"
	.string "Ik hoopte dat je aardig zou zijn,\n"
	.string "{PLAYER}{KUN}, en dat we vrienden worden.\p"
	.string "O, dit is gek, hè?\n"
	.string "Ik… Ik ken je net, {PLAYER}{KUN}.\p"
	.string "Hihihi…\p"
	.string "O nee! Ik was het vergeten!\p"
	.string "Ik zou papa helpen om wilde\n"
	.string "POKéMON te vangen!\p"
	.string "{PLAYER}{KUN}, tot later!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "POKéMON zijn helemaal fit!\n"
	.string "Voorwerpen klaar, en…$"

RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "Hé!\n"
	.string "Jij…\p"
	.string "Wie ben jij?\p"
	.string "O, jij bent {PLAYER}, toch?\n"
	.string "Je woont hiernaast, hè?\p"
	.string "Ik wist niet dat je een meisje was.\p"
	.string "Papa, PROF. BIRCH, zei dat het kind\n"
	.string "van een GYMLEIDER naast ons kwam\l"
	.string "wonen. Ik dacht dat je een jongen was.\p"
	.string "Ik heet BRENDAN.\n"
	.string "Hoi, buurmeisje!\p"
	.string "Hè? Hé, {PLAYER}, heb jij geen\n"
	.string "POKéMON?\p"
	.string "Zal ik er een voor je vangen?\p"
	.string "O nee, ik was het vergeten…\p"
	.string "Ik zou mijn vader helpen om wilde\n"
	.string "POKéMON te vangen.\p"
	.string "Een andere keer, oké?$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "POKéMON zijn helemaal fit…\n"
	.string "Voorwerpen ingepakt, en…$"

RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "Het is de POKé BALL van {RIVAL}!\p"
	.string "Laat hem maar liggen.$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Ik keek net in mijn POKéDEX.\p"
	.string "Er zijn nog veel POKéMON die ik heb\n"
	.string "gezien, maar nog niet gevangen.\p"
	.string "En er zijn er veel die volgens mij\n"
	.string "nog gaan evolueren.\p"
	.string "Waar zal ik nu POKéMON gaan\n"
	.string "vangen?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "MAY: Waar zal ik nu POKéMON\n"
	.string "gaan vangen?\p"
	.string "Het zou grappig zijn als we elkaar\n"
	.string "tegenkomen, {PLAYER}{KUN}!$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "BRENDAN: Hé, het is {PLAYER}.\p"
	.string "Ik keek net in mijn POKéDEX.\p"
	.string "Ik moet nog veel POKéMON vangen,\n"
	.string "ik weet het, maar het gaat\l"
	.string "al best goed.\p"
	.string "Als ik in mijn POKéDEX kijk, wil ik\n"
	.string "meteen weer op pad.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "BRENDAN: Ik weet niet goed waar ik\n"
	.string "nu POKéMON ga vangen.\p"
	.string "Hé, {PLAYER}, als ik je zie als ik\n"
	.string "POKéMON vang, kunnen we\l"
	.string "vechten als je wilt.$"

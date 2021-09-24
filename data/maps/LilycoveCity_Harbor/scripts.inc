.set LOCALID_ATTENDANT, 1
.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_SAILOR, 4
.set LOCALID_BRINEY, 5

LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition:
	setescapewarp MAP_LILYCOVE_CITY, 255, 12, 33
	end

LilycoveCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_FerryUnavailable
	call LilycoveCity_Harbor_EventScript_GetEonTicketState
	call LilycoveCity_Harbor_EventScript_GetAuroraTicketState
	call LilycoveCity_Harbor_EventScript_GetOldSeaMapState
	call LilycoveCity_Harbor_EventScript_GetMysticTicketState
	call LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket
	call LilycoveCity_Harbor_EventScript_GetHasTicketsState
	compare VAR_TEMP_C, 2
	goto_if_eq LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
	compare VAR_TEMP_B, 1
	goto_if_eq LilycoveCity_Harbor_EventScript_EonTicketFirstTime
	compare VAR_TEMP_B, 2
	goto_if_eq LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime
	compare VAR_TEMP_B, 4
	goto_if_eq LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
	compare VAR_TEMP_B, 8
	goto_if_eq LilycoveCity_Harbor_EventScript_MysticTicketFirstTime
	compare VAR_TEMP_B, 0
	goto_if_ne LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime
	goto LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets
	end

@ First goto_if_eq is unnecessary; identical scripts
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets::
	compare VAR_TEMP_A, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_NoEventTickets
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect::
	setvar VAR_0x8004, 0
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontier
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToNavelRock::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBirthIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToSlateport::
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBattleFrontier::
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GetEonTicketState::
	setvar VAR_TEMP_E, 0
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 1
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 2
	return

LilycoveCity_Harbor_EventScript_GetAuroraTicketState::
	setvar VAR_TEMP_D, 0
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_AURORA_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 1
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 2
	return

LilycoveCity_Harbor_EventScript_GetOldSeaMapState::
	setvar VAR_TEMP_C, 0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 2
	return

LilycoveCity_Harbor_EventScript_GetMysticTicketState::
	setvar VAR_TEMP_9, 0
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 1
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 2
	return

LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket::
	setvar VAR_TEMP_B, 0
	compare VAR_TEMP_E, 2
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
	compare VAR_TEMP_D, 2
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
	compare VAR_TEMP_C, 2
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
	compare VAR_TEMP_9, 2
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket::
	addvar VAR_TEMP_B, 1
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket::
	addvar VAR_TEMP_B, 2
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap::
	addvar VAR_TEMP_B, 4
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket::
	addvar VAR_TEMP_B, 8
	return

LilycoveCity_Harbor_EventScript_GetHasTicketsState::
	setvar VAR_TEMP_A, 0
	compare VAR_TEMP_E, 1
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasEonTicket
	compare VAR_TEMP_D, 1
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
	compare VAR_TEMP_C, 1
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
	compare VAR_TEMP_9, 1
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetHasEonTicket::
	addvar VAR_TEMP_A, 1
	return

LilycoveCity_Harbor_EventScript_SetHasAuroraTicket::
	addvar VAR_TEMP_A, 2
	return

LilycoveCity_Harbor_EventScript_SetHasOldSeaMap::
	addvar VAR_TEMP_A, 4
	return

LilycoveCity_Harbor_EventScript_SetHasMysticTicket::
	addvar VAR_TEMP_A, 8
	return

LilycoveCity_Harbor_EventScript_EonTicketFirstTime::
	setflag FLAG_SHOWN_EON_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime::
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
	waitmovement 0
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
	addobject LOCALID_BRINEY
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MysticTicketFirstTime::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime::
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	message EventTicket_Text_OddTicketsWhereTo
	waitmessage
	setvar VAR_0x8004, 1
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	release
	end

LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	removeobject LOCALID_FERRY_SAILOR
	delay 30
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	showobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
	delay 30
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_GetEventTicketSailor::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	addobject LOCALID_FERRY_SAILOR
	delay 30
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithSailor::
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	removeobject LOCALID_FERRY_SAILOR
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_FerryUnavailable::
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_NoEventTickets::
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

@ Unused
LilycoveCity_Harbor_EventScript_NoTicket::
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
	release
	end

@ Unused
LilycoveCity_Harbor_EventScript_GoToSlateportUnused::
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

@ Unused
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused::
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind::
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_BoardFerry::
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	compare VAR_FACING, DIR_NORTH
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_ExitSailSelect::
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_fastest_up
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

LilycoveCity_Harbor_Movement_UnusedBoardFerry:
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_SailorFerryAvailable::
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth::
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast::
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_SailorOutOfWayNorth:
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_Movement_SailorOutOfWayEast:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth::
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast::
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_BrineyBoardFerry:
	walk_in_place_fastest_up
	delay_8
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth:
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth:
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast:
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast:
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Text_FerryUnavailable:
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

LilycoveCity_Harbor_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your Ticket?$"


LilycoveCity_Harbor_Text_NoTicket:
	.string "{PLAYER} doesn't have the Ticket…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a Ticket to board\n"
	.string "the ferry.$"

LilycoveCity_Harbor_Text_FlashTicketWhereTo:
	.string "{PLAYER} flashed the Ticket.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

LilycoveCity_Harbor_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

LilycoveCity_Harbor_Text_SlateportItIs:
	.string "Slateport City it is, then!$"

LilycoveCity_Harbor_Text_BattleFrontierItIs:
	.string "Battle Frontier it is, then!$"

LilycoveCity_Harbor_Text_PleaseBoard:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Then, where would you like to go?$"

LilycoveCity_Harbor_Text_SailorFerryUnavailable:
	.string "Until they finish making the ferry,\n"
	.string "we sailors have nothing to do…\p"
	.string "I wish they'd get a move on, the folks\n"
	.string "at the Shipyard in Slateport.$"

LilycoveCity_Harbor_Text_SailorFerryAvailable:
	.string "The ferry S.S. Tidal is finally in\n"
	.string "operation.\p"
	.string "The folks at the Shipyard in Slateport\n"
	.string "must've worked extra hard.\p"
	.string "Well, it's my turn to get busy now!$"

.set LOCALID_ATTENDANT, 1
.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_SAILOR, 4
.set LOCALID_BRINEY, 5

LilycoveCity_Harbor_MapScripts:: @ 821E000
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition: @ 821E006
	setescapewarp MAP_LILYCOVE_CITY, 255, 12, 33
	end

LilycoveCity_Harbor_EventScript_FerryAttendant:: @ 821E00F
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
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets:: @ 821E080
	compare VAR_TEMP_A, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_NoEventTickets
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect:: @ 821E09F
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

LilycoveCity_Harbor_EventScript_GoToSouthernIsland:: @ 821E109
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToNavelRock:: @ 821E119
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBirthIsland:: @ 821E129
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIsland:: @ 821E139
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToSlateport:: @ 821E149
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBattleFrontier:: @ 821E171
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GetEonTicketState:: @ 821E194
	setvar VAR_TEMP_E, 0
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 1
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 2
	return

LilycoveCity_Harbor_EventScript_GetAuroraTicketState:: @ 821E1C6
	setvar VAR_TEMP_D, 0
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_AURORA_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 1
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 2
	return

LilycoveCity_Harbor_EventScript_GetOldSeaMapState:: @ 821E1F8
	setvar VAR_TEMP_C, 0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 2
	return

LilycoveCity_Harbor_EventScript_GetMysticTicketState:: @ 821E22A
	setvar VAR_TEMP_9, 0
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 1
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 2
	return

LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket:: @ 821E25C
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

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket:: @ 821E28E
	addvar VAR_TEMP_B, 1
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket:: @ 821E294
	addvar VAR_TEMP_B, 2
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap:: @ 821E29A
	addvar VAR_TEMP_B, 4
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket:: @ 821E2A0
	addvar VAR_TEMP_B, 8
	return

LilycoveCity_Harbor_EventScript_GetHasTicketsState:: @ 821E2A6
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

LilycoveCity_Harbor_EventScript_SetHasEonTicket:: @ 821E2D8
	addvar VAR_TEMP_A, 1
	return

LilycoveCity_Harbor_EventScript_SetHasAuroraTicket:: @ 821E2DE
	addvar VAR_TEMP_A, 2
	return

LilycoveCity_Harbor_EventScript_SetHasOldSeaMap:: @ 821E2E4
	addvar VAR_TEMP_A, 4
	return

LilycoveCity_Harbor_EventScript_SetHasMysticTicket:: @ 821E2EA
	addvar VAR_TEMP_A, 8
	return

LilycoveCity_Harbor_EventScript_EonTicketFirstTime:: @ 821E2F0
	setflag FLAG_SHOWN_EON_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime:: @ 821E30F
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime:: @ 821E320
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime:: @ 821E33F
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime:: @ 821E350
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

LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime:: @ 821E40C
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MysticTicketFirstTime:: @ 821E41D
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime:: @ 821E43C
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime:: @ 821E44D
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

LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect:: @ 821E4B6
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

LilycoveCity_Harbor_EventScript_GetEventTicketSailor:: @ 821E4EE
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

LilycoveCity_Harbor_EventScript_BoardFerryWithSailor:: @ 821E514
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

LilycoveCity_Harbor_EventScript_FerryUnavailable:: @ 821E54D
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_NoEventTickets:: @ 821E557
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

@ Unused
LilycoveCity_Harbor_EventScript_NoTicket:: @ 821E56B
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
	release
	end

@ Unused
LilycoveCity_Harbor_EventScript_GoToSlateportUnused:: @ 821E575
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
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused:: @ 821E59D
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind:: @ 821E5C0
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_BoardFerry:: @ 821E5CC
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

LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast:: @ 821E610
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth:: @ 821E61B
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_ExitSailSelect:: @ 821E626
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_Movement_PlayerBoardFerryEast: @ 821E630
	walk_right
	walk_in_place_fastest_up
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth: @ 821E633
	walk_up
	step_end

LilycoveCity_Harbor_Movement_UnusedBoardFerry: @ 821E635
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_Sailor:: @ 821E637
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_SailorFerryAvailable:: @ 821E64C
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth:: @ 821E656
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast:: @ 821E661
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_SailorOutOfWayNorth: @ 821E66C
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_Movement_SailorOutOfWayEast: @ 821E671
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth:: @ 821E675
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast:: @ 821E680
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth:: @ 821E68B
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast:: @ 821E696
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth:: @ 821E6A1
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast:: @ 821E6BA
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_BrineyBoardFerry: @ 821E6D3
	walk_in_place_fastest_up
	delay_8
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth: @ 821E6D7
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth: @ 821E6DC
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast: @ 821E6E4
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast: @ 821E6EA
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Text_FerryUnavailable: @ 821E6F1
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

LilycoveCity_Harbor_Text_MayISeeYourTicket: @ 821E758
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

LilycoveCity_Harbor_Text_NoTicket: @ 821E792
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

LilycoveCity_Harbor_Text_FlashTicketWhereTo: @ 821E7ED
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

LilycoveCity_Harbor_Text_SailAnotherTime: @ 821E842
	.string "Please sail with us another time!$"

LilycoveCity_Harbor_Text_SlateportItIs: @ 821E864
	.string "SLATEPORT CITY it is, then!$"

LilycoveCity_Harbor_Text_BattleFrontierItIs: @ 821E880
	.string "BATTLE FRONTIER it is, then!$"

LilycoveCity_Harbor_Text_PleaseBoard: @ 821E89D
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo: @ 821E8CC
	.string "Then, where would you like to go?$"

LilycoveCity_Harbor_Text_SailorFerryUnavailable: @ 821E8EE
	.string "Until they finish making the ferry,\n"
	.string "we sailors have nothing to do…\p"
	.string "I wish they'd get a move on, the folks\n"
	.string "at the SHIPYARD in SLATEPORT.$"

LilycoveCity_Harbor_Text_SailorFerryAvailable: @ 821E976
	.string "The ferry S.S. TIDAL is finally in\n"
	.string "operation.\p"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
	.string "must've worked extra hard.\p"
	.string "Well, it's my turn to get busy now!$"

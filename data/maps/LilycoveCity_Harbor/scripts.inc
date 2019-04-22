LilycoveCity_Harbor_MapScripts:: @ 821E000
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition: @ 821E006
	setescapewarp MAP_LILYCOVE_CITY, 255, 12, 33
	end

LilycoveCity_Harbor_EventScript_21E00F:: @ 821E00F
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_21E54D
	call LilycoveCity_Harbor_EventScript_21E194
	call LilycoveCity_Harbor_EventScript_21E1C6
	call LilycoveCity_Harbor_EventScript_21E1F8
	call LilycoveCity_Harbor_EventScript_21E22A
	call LilycoveCity_Harbor_EventScript_21E25C
	call LilycoveCity_Harbor_EventScript_21E2A6
	compare VAR_TEMP_C, 2
	goto_if_eq LilycoveCity_Harbor_EventScript_21E350
	compare VAR_TEMP_B, 1
	goto_if_eq LilycoveCity_Harbor_EventScript_21E2F0
	compare VAR_TEMP_B, 2
	goto_if_eq LilycoveCity_Harbor_EventScript_21E320
	compare VAR_TEMP_B, 4
	goto_if_eq LilycoveCity_Harbor_EventScript_21E350
	compare VAR_TEMP_B, 8
	goto_if_eq LilycoveCity_Harbor_EventScript_21E41D
	compare VAR_TEMP_B, 0
	goto_if_ne LilycoveCity_Harbor_EventScript_21E44D
	goto LilycoveCity_Harbor_EventScript_21E080
	end

LilycoveCity_Harbor_EventScript_21E080:: @ 821E080
	compare VAR_TEMP_A, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_21E557
	msgbox LilycoveCity_Harbor_Text_21E758, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_21E7ED
	waitmessage
	goto LilycoveCity_Harbor_EventScript_21E09F
	end

LilycoveCity_Harbor_EventScript_21E09F:: @ 821E09F
	setvar VAR_0x8004, 0
	special sub_80E2548
	waitstate
	special sub_80E2878
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_21E149
	case 1, LilycoveCity_Harbor_EventScript_21E171
	case 2, LilycoveCity_Harbor_EventScript_21E109
	case 3, LilycoveCity_Harbor_EventScript_21E119
	case 4, LilycoveCity_Harbor_EventScript_21E129
	case 5, LilycoveCity_Harbor_EventScript_21E139
	case 6, LilycoveCity_Harbor_EventScript_21E626
	case 127, LilycoveCity_Harbor_EventScript_21E626
	end

LilycoveCity_Harbor_EventScript_21E109:: @ 821E109
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E119:: @ 821E119
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E129:: @ 821E129
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E139:: @ 821E139
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E149:: @ 821E149
	msgbox LilycoveCity_Harbor_Text_21E864, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_21E5C0
	setvar VAR_PORTHOLE_STATE, 5
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E171:: @ 821E171
	msgbox LilycoveCity_Harbor_Text_21E880, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_21E5C0
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E194:: @ 821E194
	setvar VAR_TEMP_E, 0
	goto_if_unset FLAG_SYS_HAS_EON_TICKET, Common_EventScript_NopReturn
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 1
	goto_if_set FLAG_HAS_EON_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 2
	return

LilycoveCity_Harbor_EventScript_21E1C6:: @ 821E1C6
	setvar VAR_TEMP_D, 0
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_AURORA_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 1
	goto_if_set FLAG_HAS_AURORA_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 2
	return

LilycoveCity_Harbor_EventScript_21E1F8:: @ 821E1F8
	setvar VAR_TEMP_C, 0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_HAS_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 2
	return

LilycoveCity_Harbor_EventScript_21E22A:: @ 821E22A
	setvar VAR_TEMP_9, 0
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 1
	goto_if_set FLAG_HAS_MYSTIC_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 2
	return

LilycoveCity_Harbor_EventScript_21E25C:: @ 821E25C
	setvar VAR_TEMP_B, 0
	compare VAR_TEMP_E, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E28E
	compare VAR_TEMP_D, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E294
	compare VAR_TEMP_C, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E29A
	compare VAR_TEMP_9, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E2A0
	return

LilycoveCity_Harbor_EventScript_21E28E:: @ 821E28E
	addvar VAR_TEMP_B, 1
	return

LilycoveCity_Harbor_EventScript_21E294:: @ 821E294
	addvar VAR_TEMP_B, 2
	return

LilycoveCity_Harbor_EventScript_21E29A:: @ 821E29A
	addvar VAR_TEMP_B, 4
	return

LilycoveCity_Harbor_EventScript_21E2A0:: @ 821E2A0
	addvar VAR_TEMP_B, 8
	return

LilycoveCity_Harbor_EventScript_21E2A6:: @ 821E2A6
	setvar VAR_TEMP_A, 0
	compare VAR_TEMP_E, 1
	call_if_eq LilycoveCity_Harbor_EventScript_21E2D8
	compare VAR_TEMP_D, 1
	call_if_eq LilycoveCity_Harbor_EventScript_21E2DE
	compare VAR_TEMP_C, 1
	call_if_eq LilycoveCity_Harbor_EventScript_21E2E4
	compare VAR_TEMP_9, 1
	call_if_eq LilycoveCity_Harbor_EventScript_21E2EA
	return

LilycoveCity_Harbor_EventScript_21E2D8:: @ 821E2D8
	addvar VAR_TEMP_A, 1
	return

LilycoveCity_Harbor_EventScript_21E2DE:: @ 821E2DE
	addvar VAR_TEMP_A, 2
	return

LilycoveCity_Harbor_EventScript_21E2E4:: @ 821E2E4
	addvar VAR_TEMP_A, 4
	return

LilycoveCity_Harbor_EventScript_21E2EA:: @ 821E2EA
	addvar VAR_TEMP_A, 8
	return

LilycoveCity_Harbor_EventScript_21E2F0:: @ 821E2F0
	setflag FLAG_HAS_EON_TICKET
	msgbox LilycoveCity_Harbor_Text_2A68D2, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2A68FC, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_21E30F
	end

LilycoveCity_Harbor_EventScript_21E30F:: @ 821E30F
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E320:: @ 821E320
	setflag FLAG_HAS_AURORA_TICKET
	msgbox LilycoveCity_Harbor_Text_2A68D2, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C6A71, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_21E33F
	end

LilycoveCity_Harbor_EventScript_21E33F:: @ 821E33F
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E350:: @ 821E350
	setflag FLAG_HAS_OLD_SEA_MAP
	msgbox LilycoveCity_Harbor_Text_2A6848, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C68A5, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E656
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E661
	addobject 5
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E675
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E680
	msgbox LilycoveCity_Harbor_Text_2C6951, MSGBOX_DEFAULT
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E68B
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E696
	msgbox LilycoveCity_Harbor_Text_2C69AA, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E6A1
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E6BA
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E40C:: @ 821E40C
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E41D:: @ 821E41D
	setflag FLAG_HAS_MYSTIC_TICKET
	msgbox LilycoveCity_Harbor_Text_2A68D2, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C6A71, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_21E43C
	end

LilycoveCity_Harbor_EventScript_21E43C:: @ 821E43C
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E44D:: @ 821E44D
	msgbox LilycoveCity_Harbor_Text_2A68D2, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	message LilycoveCity_Harbor_Text_2C6BD4
	waitmessage
	setvar VAR_0x8004, 1
	special sub_80E2548
	waitstate
	special sub_80E2878
	switch VAR_RESULT
	case 2, LilycoveCity_Harbor_EventScript_21E30F
	case 3, LilycoveCity_Harbor_EventScript_21E43C
	case 4, LilycoveCity_Harbor_EventScript_21E33F
	case 5, LilycoveCity_Harbor_EventScript_21E40C
	case 6, LilycoveCity_Harbor_EventScript_21E4B6
	case 127, LilycoveCity_Harbor_EventScript_21E4B6
	release
	end

LilycoveCity_Harbor_EventScript_21E4B6:: @ 821E4B6
	msgbox LilycoveCity_Harbor_Text_2A6A82, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	removeobject 4
	delay 30
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	showobjectat 1, MAP_LILYCOVE_CITY_HARBOR
	delay 30
	msgbox LilycoveCity_Harbor_Text_21E842, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_21E4EE:: @ 821E4EE
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	addobject 4
	delay 30
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E514:: @ 821E514
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	removeobject 4
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E61B
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E610
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	return

LilycoveCity_Harbor_EventScript_21E54D:: @ 821E54D
	msgbox LilycoveCity_Harbor_Text_21E6F1, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_21E557:: @ 821E557
	msgbox LilycoveCity_Harbor_Text_21E758, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_21E7ED
	waitmessage
	goto LilycoveCity_Harbor_EventScript_21E09F
	end

LilycoveCity_Harbor_EventScript_21E56B:: @ 821E56B
	msgbox LilycoveCity_Harbor_Text_21E792, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_21E575:: @ 821E575
	msgbox LilycoveCity_Harbor_Text_21E864, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_21E5C0
	setvar VAR_PORTHOLE_STATE, 5
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E59D:: @ 821E59D
	msgbox LilycoveCity_Harbor_Text_21E880, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_21E5C0
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E5C0:: @ 821E5C0
	message LilycoveCity_Harbor_Text_21E8CC
	waitmessage
	goto LilycoveCity_Harbor_EventScript_21E09F
	end

LilycoveCity_Harbor_EventScript_21E5CC:: @ 821E5CC
	msgbox LilycoveCity_Harbor_Text_21E89D, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_21E61B
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_21E610
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	return

LilycoveCity_Harbor_EventScript_21E610:: @ 821E610
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_Harbor_Movement_21E630
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E61B:: @ 821E61B
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_Harbor_Movement_21E633
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E626:: @ 821E626
	msgbox LilycoveCity_Harbor_Text_21E842, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_Movement_21E630: @ 821E630
	walk_right
	walk_in_place_fastest_up
	step_end

LilycoveCity_Harbor_Movement_21E633: @ 821E633
	walk_up
	step_end

LilycoveCity_Harbor_Movement_21E635: @ 821E635
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_21E637:: @ 821E637
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_21E64C
	msgbox LilycoveCity_Harbor_Text_21E8EE, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_21E64C:: @ 821E64C
	msgbox LilycoveCity_Harbor_Text_21E976, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_21E656:: @ 821E656
	applymovement 4, LilycoveCity_Harbor_Movement_21E66C
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E661:: @ 821E661
	applymovement 4, LilycoveCity_Harbor_Movement_21E671
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_21E66C: @ 821E66C
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_Movement_21E671: @ 821E671
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_EventScript_21E675:: @ 821E675
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E680:: @ 821E680
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E68B:: @ 821E68B
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E696:: @ 821E696
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E6A1:: @ 821E6A1
	applymovement 5, LilycoveCity_Harbor_Movement_21E6D3
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_Harbor_Movement_21E6D7
	applymovement 4, LilycoveCity_Harbor_Movement_21E6DC
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E6BA:: @ 821E6BA
	applymovement 5, LilycoveCity_Harbor_Movement_21E6D3
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_Harbor_Movement_21E6E4
	applymovement 4, LilycoveCity_Harbor_Movement_21E6EA
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_21E6D3: @ 821E6D3
	walk_in_place_fastest_up
	delay_8
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_21E6D7: @ 821E6D7
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_21E6DC: @ 821E6DC
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_21E6E4: @ 821E6E4
	delay_16
	walk_right
	walk_in_place_fastest_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_21E6EA: @ 821E6EA
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Text_21E6F1: @ 821E6F1
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

LilycoveCity_Harbor_Text_21E758: @ 821E758
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"


LilycoveCity_Harbor_Text_21E792: @ 821E792
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

LilycoveCity_Harbor_Text_21E7ED: @ 821E7ED
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

LilycoveCity_Harbor_Text_21E842: @ 821E842
	.string "Please sail with us another time!$"

LilycoveCity_Harbor_Text_21E864: @ 821E864
	.string "SLATEPORT CITY it is, then!$"

LilycoveCity_Harbor_Text_21E880: @ 821E880
	.string "BATTLE FRONTIER it is, then!$"

LilycoveCity_Harbor_Text_21E89D: @ 821E89D
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

LilycoveCity_Harbor_Text_21E8CC: @ 821E8CC
	.string "Then, where would you like to go?$"

LilycoveCity_Harbor_Text_21E8EE: @ 821E8EE
	.string "Until they finish making the ferry,\n"
	.string "we sailors have nothing to do…\p"
	.string "I wish they'd get a move on, the folks\n"
	.string "at the SHIPYARD in SLATEPORT.$"

LilycoveCity_Harbor_Text_21E976: @ 821E976
	.string "The ferry S.S. TIDAL is finally in\n"
	.string "operation.\p"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
	.string "must've worked extra hard.\p"
	.string "Well, it's my turn to get busy now!$"

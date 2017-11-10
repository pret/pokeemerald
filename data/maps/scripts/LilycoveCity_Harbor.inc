LilycoveCity_Harbor_MapScripts:: @ 821E000
	map_script 3, LilycoveCity_Harbor_MapScript1_21E006
	.byte 0

LilycoveCity_Harbor_MapScript1_21E006: @ 821E006
	setescapewarp LILYCOVE_CITY, 255, 12, 33
	end

LilycoveCity_Harbor_EventScript_21E00F:: @ 821E00F
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, LilycoveCity_Harbor_EventScript_21E54D
	call LilycoveCity_Harbor_EventScript_21E194
	call LilycoveCity_Harbor_EventScript_21E1C6
	call LilycoveCity_Harbor_EventScript_21E1F8
	call LilycoveCity_Harbor_EventScript_21E22A
	call LilycoveCity_Harbor_EventScript_21E25C
	call LilycoveCity_Harbor_EventScript_21E2A6
	compare_var_to_value VAR_0x400C, 2
	goto_eq LilycoveCity_Harbor_EventScript_21E350
	compare_var_to_value VAR_0x400B, 1
	goto_eq LilycoveCity_Harbor_EventScript_21E2F0
	compare_var_to_value VAR_0x400B, 2
	goto_eq LilycoveCity_Harbor_EventScript_21E320
	compare_var_to_value VAR_0x400B, 4
	goto_eq LilycoveCity_Harbor_EventScript_21E350
	compare_var_to_value VAR_0x400B, 8
	goto_eq LilycoveCity_Harbor_EventScript_21E41D
	compare_var_to_value VAR_0x400B, 0
	goto_if 5, LilycoveCity_Harbor_EventScript_21E44D
	goto LilycoveCity_Harbor_EventScript_21E080
	end

LilycoveCity_Harbor_EventScript_21E080:: @ 821E080
	compare_var_to_value VAR_0x400A, 0
	goto_eq LilycoveCity_Harbor_EventScript_21E557
	msgbox LilycoveCity_Harbor_Text_21E758, 4
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
	warp SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E119:: @ 821E119
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E129:: @ 821E129
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E139:: @ 821E139
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E149:: @ 821E149
	msgbox LilycoveCity_Harbor_Text_21E864, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_21E5C0
	setvar VAR_PORTHOLE, 5
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E171:: @ 821E171
	msgbox LilycoveCity_Harbor_Text_21E880, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_21E5C0
	call LilycoveCity_Harbor_EventScript_21E5CC
	warp BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E194:: @ 821E194
	setvar VAR_0x400E, 0
	checkflag FLAG_SYS_HAS_EON_TICKET
	goto_if 0, LilycoveCity_Harbor_EventScript_27374E
	checkitem ITEM_EON_TICKET, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400E, 1
	checkflag FLAG_0x1AE
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400E, 2
	return

LilycoveCity_Harbor_EventScript_21E1C6:: @ 821E1C6
	setvar VAR_0x400D, 0
	checkflag FLAG_0x8D5
	goto_if 0, LilycoveCity_Harbor_EventScript_27374E
	checkitem ITEM_AURORA_TICKET, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400D, 1
	checkflag FLAG_0x1AF
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400D, 2
	return

LilycoveCity_Harbor_EventScript_21E1F8:: @ 821E1F8
	setvar VAR_0x400C, 0
	checkflag FLAG_0x8D6
	goto_if 0, LilycoveCity_Harbor_EventScript_27374E
	checkitem ITEM_OLD_SEA_MAP, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400C, 1
	checkflag FLAG_0x1B0
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x400C, 2
	return

LilycoveCity_Harbor_EventScript_21E22A:: @ 821E22A
	setvar VAR_0x4009, 0
	checkflag FLAG_0x8E0
	goto_if 0, LilycoveCity_Harbor_EventScript_27374E
	checkitem ITEM_MYSTIC_TICKET, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x4009, 1
	checkflag FLAG_0x1DB
	goto_eq LilycoveCity_Harbor_EventScript_27374E
	setvar VAR_0x4009, 2
	return

LilycoveCity_Harbor_EventScript_21E25C:: @ 821E25C
	setvar VAR_0x400B, 0
	compare_var_to_value VAR_0x400E, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E28E
	compare_var_to_value VAR_0x400D, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E294
	compare_var_to_value VAR_0x400C, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E29A
	compare_var_to_value VAR_0x4009, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E2A0
	return

LilycoveCity_Harbor_EventScript_21E28E:: @ 821E28E
	addvar VAR_0x400B, 1
	return

LilycoveCity_Harbor_EventScript_21E294:: @ 821E294
	addvar VAR_0x400B, 2
	return

LilycoveCity_Harbor_EventScript_21E29A:: @ 821E29A
	addvar VAR_0x400B, 4
	return

LilycoveCity_Harbor_EventScript_21E2A0:: @ 821E2A0
	addvar VAR_0x400B, 8
	return

LilycoveCity_Harbor_EventScript_21E2A6:: @ 821E2A6
	setvar VAR_0x400A, 0
	compare_var_to_value VAR_0x400E, 1
	call_if 1, LilycoveCity_Harbor_EventScript_21E2D8
	compare_var_to_value VAR_0x400D, 1
	call_if 1, LilycoveCity_Harbor_EventScript_21E2DE
	compare_var_to_value VAR_0x400C, 1
	call_if 1, LilycoveCity_Harbor_EventScript_21E2E4
	compare_var_to_value VAR_0x4009, 1
	call_if 1, LilycoveCity_Harbor_EventScript_21E2EA
	return

LilycoveCity_Harbor_EventScript_21E2D8:: @ 821E2D8
	addvar VAR_0x400A, 1
	return

LilycoveCity_Harbor_EventScript_21E2DE:: @ 821E2DE
	addvar VAR_0x400A, 2
	return

LilycoveCity_Harbor_EventScript_21E2E4:: @ 821E2E4
	addvar VAR_0x400A, 4
	return

LilycoveCity_Harbor_EventScript_21E2EA:: @ 821E2EA
	addvar VAR_0x400A, 8
	return

LilycoveCity_Harbor_EventScript_21E2F0:: @ 821E2F0
	setflag FLAG_0x1AE
	msgbox LilycoveCity_Harbor_Text_2A68D2, 4
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2A68FC, 4
	goto LilycoveCity_Harbor_EventScript_21E30F
	end

LilycoveCity_Harbor_EventScript_21E30F:: @ 821E30F
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E320:: @ 821E320
	setflag FLAG_0x1AF
	msgbox LilycoveCity_Harbor_Text_2A68D2, 4
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C6A71, 4
	goto LilycoveCity_Harbor_EventScript_21E33F
	end

LilycoveCity_Harbor_EventScript_21E33F:: @ 821E33F
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp BIRTH_ISLAND_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E350:: @ 821E350
	setflag FLAG_0x1B0
	msgbox LilycoveCity_Harbor_Text_2A6848, 4
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C68A5, 4
	closemessage
	applymovement 4, LilycoveCity_Harbor_Movement_2725A6
	waitmovement 0
	playse SE_PIN
	applymovement 4, LilycoveCity_Harbor_Movement_272598
	waitmovement 0
	applymovement 4, LilycoveCity_Harbor_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E656
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E661
	addobject 5
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E675
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E680
	msgbox LilycoveCity_Harbor_Text_2C6951, 4
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E68B
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E696
	msgbox LilycoveCity_Harbor_Text_2C69AA, 4
	closemessage
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E6A1
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E6BA
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	warp FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E40C:: @ 821E40C
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E41D:: @ 821E41D
	setflag FLAG_0x1DB
	msgbox LilycoveCity_Harbor_Text_2A68D2, 4
	closemessage
	call LilycoveCity_Harbor_EventScript_21E4EE
	msgbox LilycoveCity_Harbor_Text_2C6A71, 4
	goto LilycoveCity_Harbor_EventScript_21E43C
	end

LilycoveCity_Harbor_EventScript_21E43C:: @ 821E43C
	closemessage
	call LilycoveCity_Harbor_EventScript_21E514
	warp NAVEL_ROCK_HARBOR, 255, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_21E44D:: @ 821E44D
	msgbox LilycoveCity_Harbor_Text_2A68D2, 4
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
	msgbox LilycoveCity_Harbor_Text_2A6A82, 4
	closemessage
	applymovement 4, LilycoveCity_Harbor_Movement_2725A6
	waitmovement 0
	delay 30
	removeobject 4
	delay 30
	applymovement 1, LilycoveCity_Harbor_Movement_2725AA
	waitmovement 0
	showobjectat 1, LILYCOVE_CITY_HARBOR
	delay 30
	msgbox LilycoveCity_Harbor_Text_21E842, 4
	release
	end

LilycoveCity_Harbor_EventScript_21E4EE:: @ 821E4EE
	applymovement VAR_LAST_TALKED, LilycoveCity_Harbor_Movement_2725A6
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, LILYCOVE_CITY_HARBOR
	delay 60
	addobject 4
	delay 30
	applymovement 4, LilycoveCity_Harbor_Movement_27259E
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E514:: @ 821E514
	applymovement 4, LilycoveCity_Harbor_Movement_2725A6
	waitmovement 0
	delay 30
	removeobject 4
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E61B
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E610
	delay 30
	hideobjectat 255, PETALBURG_CITY
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	return

LilycoveCity_Harbor_EventScript_21E54D:: @ 821E54D
	msgbox LilycoveCity_Harbor_Text_21E6F1, 4
	release
	end

LilycoveCity_Harbor_EventScript_21E557:: @ 821E557
	msgbox LilycoveCity_Harbor_Text_21E758, 4
	message LilycoveCity_Harbor_Text_21E7ED
	waitmessage
	goto LilycoveCity_Harbor_EventScript_21E09F
	end

	.incbin "baserom.gba", 0x21e56b, 0x55

LilycoveCity_Harbor_EventScript_21E5C0:: @ 821E5C0
	message LilycoveCity_Harbor_Text_21E8CC
	waitmessage
	goto LilycoveCity_Harbor_EventScript_21E09F
	end

LilycoveCity_Harbor_EventScript_21E5CC:: @ 821E5CC
	msgbox LilycoveCity_Harbor_Text_21E89D, 4
	closemessage
	applymovement VAR_LAST_TALKED, LilycoveCity_Harbor_Movement_2725A6
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, LILYCOVE_CITY_HARBOR
	compare_var_to_value VAR_FACING, 2
	call_if 1, LilycoveCity_Harbor_EventScript_21E61B
	compare_var_to_value VAR_FACING, 4
	call_if 1, LilycoveCity_Harbor_EventScript_21E610
	delay 30
	hideobjectat 255, PETALBURG_CITY
	setvar VAR_0x8004, 2
	call LilycoveCity_Harbor_EventScript_2721E2
	return

LilycoveCity_Harbor_EventScript_21E610:: @ 821E610
	applymovement 255, LilycoveCity_Harbor_Movement_21E630
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E61B:: @ 821E61B
	applymovement 255, LilycoveCity_Harbor_Movement_21E633
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E626:: @ 821E626
	msgbox LilycoveCity_Harbor_Text_21E842, 4
	release
	end

LilycoveCity_Harbor_Movement_21E630: @ 821E630
	step_right
	step_26
	step_end

LilycoveCity_Harbor_Movement_21E633: @ 821E633
	step_up
	step_end

	.incbin "baserom.gba", 0x21e635, 0x2

LilycoveCity_Harbor_EventScript_21E637:: @ 821E637
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq LilycoveCity_Harbor_EventScript_21E64C
	msgbox LilycoveCity_Harbor_Text_21E8EE, 4
	release
	end

LilycoveCity_Harbor_EventScript_21E64C:: @ 821E64C
	msgbox LilycoveCity_Harbor_Text_21E976, 4
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
	step_28
	step_40
	step_left
	step_41
	step_end

LilycoveCity_Harbor_Movement_21E671: @ 821E671
	step_40
	step_down
	step_41
	step_end

LilycoveCity_Harbor_EventScript_21E675:: @ 821E675
	applymovement 5, LilycoveCity_Harbor_Movement_2725A4
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E680:: @ 821E680
	applymovement 5, LilycoveCity_Harbor_Movement_2725AA
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E68B:: @ 821E68B
	applymovement 5, LilycoveCity_Harbor_Movement_2725AA
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E696:: @ 821E696
	applymovement 5, LilycoveCity_Harbor_Movement_2725A4
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E6A1:: @ 821E6A1
	applymovement 5, LilycoveCity_Harbor_Movement_21E6D3
	applymovement 255, LilycoveCity_Harbor_Movement_21E6D7
	applymovement 4, LilycoveCity_Harbor_Movement_21E6DC
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_21E6BA:: @ 821E6BA
	applymovement 5, LilycoveCity_Harbor_Movement_21E6D3
	applymovement 255, LilycoveCity_Harbor_Movement_21E6E4
	applymovement 4, LilycoveCity_Harbor_Movement_21E6EA
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_21E6D3: @ 821E6D3
	step_26
	step_13
	step_54
	step_end

LilycoveCity_Harbor_Movement_21E6D7: @ 821E6D7
	step_14
	step_up
	step_14
	step_54
	step_end

LilycoveCity_Harbor_Movement_21E6DC: @ 821E6DC
	step_14
	step_14
	step_14
	step_right
	step_26
	step_14
	step_54
	step_end

LilycoveCity_Harbor_Movement_21E6E4: @ 821E6E4
	step_14
	step_right
	step_26
	step_14
	step_54
	step_end

LilycoveCity_Harbor_Movement_21E6EA: @ 821E6EA
	step_14
	step_14
	step_14
	step_up
	step_14
	step_54
	step_end

LilycoveCity_Harbor_Text_21E6F1: @ 821E6F1
	.string "I beg your pardon?\n"
	.string "You’re looking for a ship?\p"
	.string "I’m sorry, the ferry service isn’t\n"
	.string "available at present…$"

LilycoveCity_Harbor_Text_21E758: @ 821E758
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

	.incbin "baserom.gba", 0x21e792, 0x5b

LilycoveCity_Harbor_Text_21E7ED: @ 821E7ED
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That’s all you need!\p"
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
	.string "I wish they’d get a move on, the folks\n"
	.string "at the SHIPYARD in SLATEPORT.$"

LilycoveCity_Harbor_Text_21E976: @ 821E976
	.string "The ferry S.S. TIDAL is finally in\n"
	.string "operation.\p"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
	.string "must’ve worked extra hard.\p"
	.string "Well, it’s my turn to get busy now!$"


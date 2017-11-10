SlateportCity_BattleTentCorridor_MapScripts:: @ 8208E26
	map_script 2, SlateportCity_BattleTentCorridor_MapScript2_208E5B
	map_script 4, SlateportCity_BattleTentCorridor_MapScript2_208E31
	.byte 0

SlateportCity_BattleTentCorridor_MapScript2_208E31: @ 8208E31
	map_script_2 VAR_0x4001, 0, SlateportCity_BattleTentCorridor_EventScript_208E3B
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_208E3B:: @ 8208E3B
	setvar VAR_0x4001, 1
	compare_var_to_value VAR_0x8006, 1
	goto_if 5, SlateportCity_BattleTentCorridor_EventScript_208E56
	setobjectxy 1, 2, 2
	turnobject 1, 1

SlateportCity_BattleTentCorridor_EventScript_208E56:: @ 8208E56
	turnobject 255, 2
	end

SlateportCity_BattleTentCorridor_MapScript2_208E5B: @ 8208E5B
	map_script_2 VAR_0x4000, 0, SlateportCity_BattleTentCorridor_EventScript_208E65
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_208E65:: @ 8208E65
	compare_var_to_value VAR_0x8006, 1
	goto_eq SlateportCity_BattleTentCorridor_EventScript_208EEE
	setvar VAR_0x4000, 1
	applymovement 1, SlateportCity_BattleTentCorridor_Movement_209062
	applymovement 255, SlateportCity_BattleTentCorridor_Movement_209059
	waitmovement 0
	compare_var_to_value VAR_0x8006, 2
	goto_eq SlateportCity_BattleTentCorridor_EventScript_209044
	setvar VAR_0x8004, 9
	special sub_81B9D08
	setvar VAR_0x8004, 8
	special sub_81B9D08
	msgbox SlateportCity_BattleTentCorridor_Text_25A1C8, 4
	fadescreen 1
	setvar VAR_0x8004, 6
	special sub_81B9D08
	waitstate

SlateportCity_BattleTentCorridor_EventScript_208EB4:: @ 8208EB4
	msgbox SlateportCity_BattleTentCorridor_Text_25AB96, 4
	closemessage
	applymovement 1, SlateportCity_BattleTentCorridor_Movement_2725A6
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement 1, SlateportCity_BattleTentCorridor_Movement_209068
	applymovement 255, SlateportCity_BattleTentCorridor_Movement_20905E
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 255, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_208EEE:: @ 8208EEE
	setvar VAR_0x8004, 9
	special sub_81A5E74
	setvar VAR_0x8004, 16
	special sub_81A5E74
	msgbox SlateportCity_BattleTentCorridor_Text_25A22D, 4
	playfanfare BGM_ME_ASA
	waitfanfare
	special sp000_heal_pokemon

SlateportCity_BattleTentCorridor_EventScript_208F0D:: @ 8208F0D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 1
	call_if 1, SlateportCity_BattleTentCorridor_EventScript_209014
	compare_var_to_value VAR_RESULT, 2
	call_if 1, SlateportCity_BattleTentCorridor_EventScript_20901B
	multichoice 20, 6, 104, 1
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208FBB
	case 1, SlateportCity_BattleTentCorridor_EventScript_208F5B
	case 2, SlateportCity_BattleTentCorridor_EventScript_208F89

SlateportCity_BattleTentCorridor_EventScript_208F5B:: @ 8208F5B
	msgbox SlateportCity_BattleTentCorridor_Text_25A350, 5
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208F0D
	case 1, SlateportCity_BattleTentCorridor_EventScript_209022
	case 127, SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_EventScript_208F89:: @ 8208F89
	message SlateportCity_BattleTentCorridor_Text_25A37A
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_208F0D
	case 0, SlateportCity_BattleTentCorridor_EventScript_209A1B
	case 127, SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_EventScript_208FBB:: @ 8208FBB
	setvar VAR_0x8004, 8
	special sub_81B9D08
	msgbox SlateportCity_BattleTentCorridor_Text_25AB2E, 5
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208EB4
	case 1, SlateportCity_BattleTentCorridor_EventScript_208FF1
	case 127, SlateportCity_BattleTentCorridor_EventScript_208EB4

SlateportCity_BattleTentCorridor_EventScript_208FF1:: @ 8208FF1
	fadescreen 1
	setvar VAR_0x8004, 7
	special sub_81B9D08
	waitstate
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_BattleTentCorridor_EventScript_208EB4
	msgbox SlateportCity_BattleTentCorridor_Text_25AB6C, 4
	goto SlateportCity_BattleTentCorridor_EventScript_208EB4

SlateportCity_BattleTentCorridor_EventScript_209014:: @ 8209014
	message SlateportCity_BattleTentCorridor_Text_25A263
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_20901B:: @ 820901B
	message SlateportCity_BattleTentCorridor_Text_25A289
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_209022:: @ 8209022
	message SlateportCity_BattleTentCorridor_Text_25ABAE
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special sub_81B9D08
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special sub_81A1780
	end

SlateportCity_BattleTentCorridor_EventScript_209044:: @ 8209044
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 10
	setvar VAR_0x8005, 0
	special sub_81A5E74
	goto SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_Movement_209059: @ 8209059
	step_up
	step_up
	step_up
	step_up
	step_end

SlateportCity_BattleTentCorridor_Movement_20905E: @ 820905E
	step_up
	step_up
	step_54
	step_end

SlateportCity_BattleTentCorridor_Movement_209062: @ 8209062
	step_up
	step_up
	step_up
	step_up
	step_25
	step_end

SlateportCity_BattleTentCorridor_Movement_209068: @ 8209068
	step_up
	step_54
	step_end

	.incbin "baserom.gba", 0x20906b, 0x8f5


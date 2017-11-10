LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
	map_script 1, LittlerootTown_MaysHouse_1F_MapScript1_1F88B5
	map_script 3, LittlerootTown_MaysHouse_1F_MapScript1_1F88F4
	map_script 2, LittlerootTown_MaysHouse_1F_MapScript2_1F893A
	.byte 0

LittlerootTown_MaysHouse_1F_MapScript1_1F88B5: @ 81F88B5
	compare_var_to_value VAR_0x4092, 6
	call_if 0, LittlerootTown_MaysHouse_1F_EventScript_1F88CA
	checkflag FLAG_0x112
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F88DD
	end

LittlerootTown_MaysHouse_1F_EventScript_1F88CA:: @ 81F88CA
	setmetatile 5, 4, 624, 1
	setmetatile 5, 2, 616, 1
	return

LittlerootTown_MaysHouse_1F_EventScript_1F88DD:: @ 81F88DD
	checkplayergender
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_MaysHouse_1F_EventScript_1F88EA
	return

LittlerootTown_MaysHouse_1F_EventScript_1F88EA:: @ 81F88EA
	setmetatile 6, 7, 659, 1
	return

LittlerootTown_MaysHouse_1F_MapScript1_1F88F4: @ 81F88F4
	compare_var_to_value VAR_0x4092, 3
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F892E
	compare_var_to_value VAR_0x4092, 5
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8916
	compare_var_to_value VAR_0x4092, 6
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8922
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8916:: @ 81F8916
	setobjectxyperm 1, 2, 4
	setobjectmovementtype 1, 7
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8922:: @ 81F8922
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, 7
	return

LittlerootTown_MaysHouse_1F_EventScript_1F892E:: @ 81F892E
	setobjectxyperm 1, 1, 8
	setobjectmovementtype 1, 7
	return

LittlerootTown_MaysHouse_1F_MapScript2_1F893A: @ 81F893A
	map_script_2 VAR_0x4092, 3, LittlerootTown_MaysHouse_1F_EventScript_1F898C
	map_script_2 VAR_0x4092, 5, LittlerootTown_MaysHouse_1F_EventScript_1F8964
	map_script_2 VAR_0x4092, 6, LittlerootTown_MaysHouse_1F_EventScript_1F899D
	map_script_2 VAR_0x408C, 1, LittlerootTown_MaysHouse_1F_EventScript_1F89AE
	map_script_2 VAR_0x4082, 3, LittlerootTown_MaysHouse_1F_EventScript_292AF2
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_1F8964:: @ 81F8964
	lockall
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7B67, 4
	closemessage
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_1F898A
	applymovement 1, LittlerootTown_MaysHouse_1F_Movement_1F898A
	waitmovement 0
	warp LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 1, 1
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_1F898A: @ 81F898A
	step_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_1F898C:: @ 81F898C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_292704
	end

LittlerootTown_MaysHouse_1F_EventScript_1F899D:: @ 81F899D
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_2928DC
	end

LittlerootTown_MaysHouse_1F_EventScript_1F89AE:: @ 81F89AE
	lockall
	playse SE_PIN
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_272598
	waitmovement 0
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_27259A
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_2725A8
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_1F89EC
	waitmovement 0
	special sub_8138B48
	msgbox LittlerootTown_MaysHouse_1F_Text_1F8BC5, 4
	setflag FLAG_0x057
	setvar VAR_0x408C, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_1F89EC: @ 81F89EC
	step_down
	step_left
	step_left
	step_left
	step_left
	step_left
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F89F3:: @ 81F89F3
LittlerootTown_MaysHouse_1F_EventScript_1F89F3:: @ 81F89F3
	lock
	faceplayer
	checkflag FLAG_0x082
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_1F8A33
	checkflag FLAG_SYS_POKEMON_GET
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_1F8A29
	compare_var_to_value VAR_0x408D, 3
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F
	special sub_8138B48
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8CA5, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F:: @ 81F8A1F
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8D37, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A29:: @ 81F8A29
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8D93, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A33:: @ 81F8A33
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8E01, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A3D:: @ 81F8A3D
LittlerootTown_MaysHouse_1F_EventScript_1F8A3D:: @ 81F8A3D
	lock
	faceplayer
	special sub_8138B10
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F9262, 4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A4C:: @ 81F8A4C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	applymovement VAR_0x8004, LittlerootTown_MaysHouse_1F_Movement_2725A8
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_292765
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A67:: @ 81F8A67
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A73:: @ 81F8A73
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A7F:: @ 81F8A7F
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A8B:: @ 81F8A8B
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_272598
	waitmovement 0
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x8008, 1
	call_if 5, LittlerootTown_MaysHouse_1F_EventScript_1F8B2A
	playbgm BGM_GIRL_SUP, 1
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B35
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B40
	compare_var_to_value VAR_0x8008, 2
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B4B
	msgbox LittlerootTown_MaysHouse_1F_Text_1F8EC6, 4
	closemessage
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B6A
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B7C
	compare_var_to_value VAR_0x8008, 2
	call_if 1, LittlerootTown_MaysHouse_1F_EventScript_1F8B8E
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_0x2EA
	setflag FLAG_0x332
	clearflag FLAG_0x2D2
	delay 30
	setvar VAR_0x408D, 3
	setvar VAR_0x4050, 1
	savebgm SE_STOP
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8B2A:: @ 81F8B2A
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_2725AA
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B35:: @ 81F8B35
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B56
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B40:: @ 81F8B40
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B5E
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B4B:: @ 81F8B4B
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B62
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8B56: @ 81F8B56
	step_27
	step_left
	step_26
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B5E: @ 81F8B5E
	step_up
	step_up
	step_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B62: @ 81F8B62
	step_28
	step_right
	step_26
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_1F8B6A:: @ 81F8B6A
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_1F8BA0
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BAF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B7C:: @ 81F8B7C
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_1F8BA4
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BB5
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B8E:: @ 81F8B8E
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_1F8BAB
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BBF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8BA0: @ 81F8BA0
	step_14
	step_13
	step_28
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BA4: @ 81F8BA4
	step_14
	step_13
	step_28
	step_14
	step_14
	step_26
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAB: @ 81F8BAB
	step_14
	step_13
	step_27
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAF: @ 81F8BAF
	step_28
	step_right
	step_26
	step_up
	step_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BB5: @ 81F8BB5
	step_28
	step_right
	step_26
	step_up
	step_up
	step_27
	step_left
	step_26
	step_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BBF: @ 81F8BBF
	step_27
	step_left
	step_26
	step_up
	step_up
	step_end


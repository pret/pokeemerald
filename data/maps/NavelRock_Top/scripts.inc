NavelRock_Top_MapScripts:: @ 8269113
	map_script 3, NavelRock_Top_MapScript1_26911E
	map_script 5, NavelRock_Top_MapScript1_269151
	.byte 0

NavelRock_Top_MapScript1_26911E: @ 826911E
	checkflag FLAG_0x092
	call_if 1, NavelRock_Top_EventScript_269131
	checkflag FLAG_0x092
	call_if 0, NavelRock_Top_EventScript_26913A
	end

NavelRock_Top_EventScript_269131:: @ 8269131
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HOOH
	return

NavelRock_Top_EventScript_26913A:: @ 826913A
	setvar VAR_TEMP_1, 1
	checkflag FLAG_0x1DC
	goto_eq NavelRock_Top_EventScript_27374E
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HOOH
	return

NavelRock_Top_MapScript1_269151: @ 8269151
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, NavelRock_Top_EventScript_26915B
	end

NavelRock_Top_EventScript_26915B:: @ 826915B
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if 5, NavelRock_Top_EventScript_27374E
	removeobject 1
	return

NavelRock_Top_EventScript_26916F:: @ 826916F
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 35
	special sub_813B80C
	applymovement 1, NavelRock_Top_Movement_269243
	applymovement EVENT_OBJ_ID_CAMERA, NavelRock_Top_Movement_269230
	waitmovement 0
	delay 50
	setweather 0
	doweather
	waitse
	playmoncry SPECIES_HO_OH, 2
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 35
	special sub_813B80C
	applymovement EVENT_OBJ_ID_CAMERA, NavelRock_Top_Movement_269234
	applymovement 1, NavelRock_Top_Movement_26923A
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, 250
	setvar VAR_0x8005, 70
	setvar VAR_0x8006, 0
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_eq NavelRock_Top_EventScript_269217
	compare VAR_RESULT, 4
	goto_eq NavelRock_Top_EventScript_269225
	compare VAR_RESULT, 5
	goto_eq NavelRock_Top_EventScript_269225
	setflag FLAG_0x092
	releaseall
	end

NavelRock_Top_EventScript_269217:: @ 8269217
	setflag FLAG_0x1DC
	setvar VAR_0x8004, 250
	goto NavelRock_Top_EventScript_273776
	end

NavelRock_Top_EventScript_269225:: @ 8269225
	setvar VAR_0x8004, 250
	goto NavelRock_Top_EventScript_273776
	end

NavelRock_Top_Movement_269230: @ 8269230
	walk_up
	walk_up
	walk_up
	step_end

NavelRock_Top_Movement_269234: @ 8269234
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

NavelRock_Top_Movement_26923A: @ 826923A
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

NavelRock_Top_Movement_269243: @ 8269243
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


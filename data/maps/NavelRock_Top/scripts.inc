NavelRock_Top_MapScripts:: @ 8269113
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_MapScript1_269151
	.byte 0

NavelRock_Top_OnTransition: @ 826911E
	call_if_set FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_269131
	call_if_unset FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_26913A
	end

NavelRock_Top_EventScript_269131:: @ 8269131
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HO_OH
	return

NavelRock_Top_EventScript_26913A:: @ 826913A
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_HO_OH, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HO_OH
	return

NavelRock_Top_MapScript1_269151: @ 8269151
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Top_EventScript_26915B
	end

NavelRock_Top_EventScript_26915B:: @ 826915B
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

NavelRock_Top_EventScript_26916F:: @ 826916F
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement 1, NavelRock_Top_Movement_269243
	applymovement EVENT_OBJ_ID_CAMERA, NavelRock_Top_Movement_269230
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, 2
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement EVENT_OBJ_ID_CAMERA, NavelRock_Top_Movement_269234
	applymovement 1, NavelRock_Top_Movement_26923A
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, SPECIES_HO_OH
	setvar VAR_0x8005, 70 @level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq NavelRock_Top_EventScript_269217
	compare VAR_RESULT, 4
	goto_if_eq NavelRock_Top_EventScript_269225
	compare VAR_RESULT, 5
	goto_if_eq NavelRock_Top_EventScript_269225
	setflag FLAG_CAUGHT_HO_OH
	releaseall
	end

NavelRock_Top_EventScript_269217:: @ 8269217
	setflag FLAG_DEFEATED_HO_OH
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_EventScript_269225:: @ 8269225
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
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

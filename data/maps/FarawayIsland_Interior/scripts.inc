FarawayIsland_Interior_MapScripts:: @ 8267CFA
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_MapScript1_267D54
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_MapScript2_267D98
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_MapScript1_267D0F
	.byte 0

FarawayIsland_Interior_MapScript1_267D0F: @ 8267D0F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_267D19
	end

FarawayIsland_Interior_EventScript_267D19:: @ 8267D19
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, 4
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, 5
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, 10
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	return

FarawayIsland_Interior_EventScript_267D4B:: @ 8267D4B
	setvar VAR_0x8004, 1
	special sub_81D4A90
	return

FarawayIsland_Interior_MapScript1_267D54: @ 8267D54
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_267D5E
	end

FarawayIsland_Interior_EventScript_267D5E:: @ 8267D5E
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_OnTransition: @ 8267D72
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
	setvar VAR_TEMP_1, 1
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_267D86
	end

FarawayIsland_Interior_EventScript_267D86:: @ 8267D86
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEW
	setvar VAR_TEMP_1, 0
	return

FarawayIsland_Interior_MapScript2_267D98: @ 8267D98
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_267DA2
	.2byte 0

FarawayIsland_Interior_EventScript_267DA2:: @ 8267DA2
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, FarawayIsland_Interior_Movement_267DCE
	waitmovement 0
	copyobjectxytoperm 1
	setvar VAR_TEMP_1, 1
	releaseall
	end

FarawayIsland_Interior_Movement_267DCE: @ 8267DCE
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	set_invisible
	step_end

FarawayIsland_Interior_Movement_267DD4: @ 8267DD4
	set_visible
	step_end

FarawayIsland_Interior_Movement_267DD6: @ 8267DD6
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_down
	walk_in_place_down
	step_end

FarawayIsland_Interior_Movement_267DDD: @ 8267DDD
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_up
	walk_in_place_up
	step_end

FarawayIsland_Interior_Movement_267DE4: @ 8267DE4
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_right
	walk_in_place_right
	step_end

FarawayIsland_Interior_Movement_267DEB: @ 8267DEB
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_left
	walk_in_place_left
	step_end

FarawayIsland_Interior_EventScript_267DF2:: @ 8267DF2
	lock
	faceplayer
	applymovement 1, FarawayIsland_Interior_Movement_267DD4
	waitmovement 0
	setvar VAR_0x8004, 0
	special sub_81D4A90
	message FarawayIsland_Interior_Text_Mew
	waitse
	playmoncry SPECIES_MEW, 2
	compare VAR_FACING, 2
	call_if_eq FarawayIsland_Interior_EventScript_267EAF
	compare VAR_FACING, 1
	call_if_eq FarawayIsland_Interior_EventScript_267EBA
	compare VAR_FACING, 3
	call_if_eq FarawayIsland_Interior_EventScript_267EC5
	compare VAR_FACING, 4
	call_if_eq FarawayIsland_Interior_EventScript_267ED0
	special sub_81D4BEC
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_MEW
	setvar VAR_0x8005, 30 @level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq FarawayIsland_Interior_EventScript_267E96
	compare VAR_RESULT, 4
	goto_if_eq FarawayIsland_Interior_EventScript_267EA4
	compare VAR_RESULT, 5
	goto_if_eq FarawayIsland_Interior_EventScript_267EA4
	compare VAR_RESULT, 10
	goto_if_eq FarawayIsland_Interior_EventScript_267EA4
	setflag FLAG_CAUGHT_MEW
	release
	end

FarawayIsland_Interior_EventScript_267E96:: @ 8267E96
	setflag FLAG_DEFEATED_MEW
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_267EA4:: @ 8267EA4
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_267EAF:: @ 8267EAF
	applymovement 1, FarawayIsland_Interior_Movement_267DD6
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267EBA:: @ 8267EBA
	applymovement 1, FarawayIsland_Interior_Movement_267DDD
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267EC5:: @ 8267EC5
	applymovement 1, FarawayIsland_Interior_Movement_267DE4
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267ED0:: @ 8267ED0
	applymovement 1, FarawayIsland_Interior_Movement_267DEB
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267EDB:: @ 8267EDB
	lockall
	fadescreenswapbuffers 1
	setflag FLAG_HIDE_MEW
	removeobject 1
	fadescreenswapbuffers 0
	msgbox FarawayIsland_Interior_Text_267EF1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FarawayIsland_Interior_Text_267EF1: @ 8267EF1
	.string "The feeling of being watched faded…$"

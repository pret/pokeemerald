FarawayIsland_Interior_MapScripts:: @ 8267CFA
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
	.byte 0

FarawayIsland_Interior_OnReturnToField: @ 8267D0F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_267D19
	end

FarawayIsland_Interior_EventScript_267D19:: @ 8267D19
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_267D4B
	return

FarawayIsland_Interior_EventScript_267D4B:: @ 8267D4B
	setvar VAR_0x8004, 1
	special sub_81D4A90
	return

FarawayIsland_Interior_OnResume: @ 8267D54
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
	end

FarawayIsland_Interior_EventScript_TryRemoveMew:: @ 8267D5E
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_OnTransition: @ 8267D72
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
	setvar VAR_TEMP_1, 1
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
	end

FarawayIsland_Interior_EventScript_TryShowMew:: @ 8267D86
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEW
	setvar VAR_TEMP_1, 0
	return

FarawayIsland_Interior_OnFrame: @ 8267D98
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
	.2byte 0

FarawayIsland_Interior_EventScript_FindMew:: @ 8267DA2
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, FarawayIsland_Interior_Movement_MewMoveAndHide
	waitmovement 0
	copyobjectxytoperm 1
	setvar VAR_TEMP_1, 1
	releaseall
	end

FarawayIsland_Interior_Movement_MewMoveAndHide: @ 8267DCE
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	set_invisible
	step_end

FarawayIsland_Interior_Movement_MewAppear: @ 8267DD4
	set_visible
	step_end

FarawayIsland_Interior_Movement_MewHideDown: @ 8267DD6
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_down
	walk_in_place_down
	step_end

FarawayIsland_Interior_Movement_MewHideUp: @ 8267DDD
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_up
	walk_in_place_up
	step_end

FarawayIsland_Interior_Movement_MewHideRight: @ 8267DE4
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_right
	walk_in_place_right
	step_end

FarawayIsland_Interior_Movement_MewHideLeft: @ 8267DEB
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_left
	walk_in_place_left
	step_end

FarawayIsland_Interior_EventScript_Mew:: @ 8267DF2
	lock
	faceplayer
	applymovement 1, FarawayIsland_Interior_Movement_MewAppear
	waitmovement 0
	setvar VAR_0x8004, 0
	special sub_81D4A90
	message FarawayIsland_Interior_Text_Mew
	waitse
	playmoncry SPECIES_MEW, 2
	compare VAR_FACING, DIR_NORTH
	call_if_eq FarawayIsland_Interior_EventScript_MewHideDown
	compare VAR_FACING, DIR_SOUTH
	call_if_eq FarawayIsland_Interior_EventScript_MewHideUp
	compare VAR_FACING, DIR_WEST
	call_if_eq FarawayIsland_Interior_EventScript_MewHideRight
	compare VAR_FACING, DIR_EAST
	call_if_eq FarawayIsland_Interior_EventScript_MewHideLeft
	special sub_81D4BEC
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_MEW
	setvar VAR_0x8005, 30 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FarawayIsland_Interior_EventScript_MewDefeated
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	setflag FLAG_CAUGHT_MEW
	release
	end

FarawayIsland_Interior_EventScript_MewDefeated:: @ 8267E96
	setflag FLAG_DEFEATED_MEW
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_PlayerOrMewRan:: @ 8267EA4
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_MewHideDown:: @ 8267EAF
	applymovement 1, FarawayIsland_Interior_Movement_MewHideDown
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_MewHideUp:: @ 8267EBA
	applymovement 1, FarawayIsland_Interior_Movement_MewHideUp
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_MewHideRight:: @ 8267EC5
	applymovement 1, FarawayIsland_Interior_Movement_MewHideRight
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_MewHideLeft:: @ 8267ED0
	applymovement 1, FarawayIsland_Interior_Movement_MewHideLeft
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_HideMewWhenGrassCut:: @ 8267EDB
	lockall
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MEW
	removeobject 1
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded: @ 8267EF1
	.string "The feeling of being watched faded…$"

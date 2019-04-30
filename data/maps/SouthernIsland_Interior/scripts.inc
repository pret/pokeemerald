SouthernIsland_Interior_MapScripts:: @ 8242A45
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_MapScript1_242A50
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_MapScript1_242A50: @ 8242A50
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_242A5A
	end

SouthernIsland_Interior_EventScript_242A5A:: @ 8242A5A
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 2
	return

SouthernIsland_Interior_OnTransition: @ 8242A6E
	compare VAR_ROAMER_POKEMON, 0
	call_if_eq SouthernIsland_Interior_EventScript_242A8A
	compare VAR_ROAMER_POKEMON, 0
	call_if_ne SouthernIsland_Interior_EventScript_242A95
	call SouthernIsland_Interior_EventScript_242AA0
	end

SouthernIsland_Interior_EventScript_242A8A:: @ 8242A8A
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_LATIOS
	setvar VAR_TEMP_4, 408
	return

SouthernIsland_Interior_EventScript_242A95:: @ 8242A95
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_LATIAS
	setvar VAR_TEMP_4, 407
	return

SouthernIsland_Interior_EventScript_242AA0:: @ 8242AA0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SouthernIsland_Interior_EventScript_242AB8
	compare VAR_RESULT, FEMALE
	goto_if_eq SouthernIsland_Interior_EventScript_242ABE
	end

SouthernIsland_Interior_EventScript_242AB8:: @ 8242AB8
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_242ABE:: @ 8242ABE
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_242AC4:: @ 8242AC4
	lockall
	setvar VAR_0x8008, 12
	goto SouthernIsland_Interior_EventScript_242AD0
	end

SouthernIsland_Interior_EventScript_242AD0:: @ 8242AD0
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_242B9A
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_242B9A
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_242B9A
	goto_if_unset FLAG_SYS_HAS_EON_TICKET, SouthernIsland_Interior_EventScript_242B9A
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SouthernIsland_Interior_Movement_242BCA
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, 0
	delay 30
	waitmoncry
	addobject 2
	delay 30
	applymovement EVENT_OBJ_ID_CAMERA, SouthernIsland_Interior_Movement_242BCE
	applymovement 2, SouthernIsland_Interior_Movement_242BDA
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, 2
	compare VAR_ROAMER_POKEMON, 0
	call_if_eq SouthernIsland_Interior_EventScript_242BA4
	compare VAR_ROAMER_POKEMON, 0
	call_if_ne SouthernIsland_Interior_EventScript_242BB7
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq SouthernIsland_Interior_EventScript_242B81
	compare VAR_RESULT, 4
	goto_if_eq SouthernIsland_Interior_EventScript_242B8F
	compare VAR_RESULT, 5
	goto_if_eq SouthernIsland_Interior_EventScript_242B8F
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_242B81:: @ 8242B81
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto SouthernIsland_Interior_EventScript_273776
	end

SouthernIsland_Interior_EventScript_242B8F:: @ 8242B8F
	copyvar VAR_0x8004, VAR_TEMP_4
	goto SouthernIsland_Interior_EventScript_273776
	end

SouthernIsland_Interior_EventScript_242B9A:: @ 8242B9A
	msgbox SouthernIsland_Interior_Text_2A6AA1, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_242BA4:: @ 8242BA4
	setvar VAR_0x8004, 408
	setvar VAR_0x8005, 50
	setvar VAR_0x8006, 191
	special CreateObedientEnemyMon
	return

SouthernIsland_Interior_EventScript_242BB7:: @ 8242BB7
	setvar VAR_0x8004, 407
	setvar VAR_0x8005, 50
	setvar VAR_0x8006, 191
	special CreateObedientEnemyMon
	return

SouthernIsland_Interior_Movement_242BCA: @ 8242BCA
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_242BCE: @ 8242BCE
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end

SouthernIsland_Interior_Movement_242BDA: @ 8242BDA
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

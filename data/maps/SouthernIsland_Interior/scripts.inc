.set LOCALID_LATI, 2

SouthernIsland_Interior_MapScripts:: @ 8242A45
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume: @ 8242A50
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati:: @ 8242A5A
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_LATI
	return

SouthernIsland_Interior_OnTransition: @ 8242A6E
	compare VAR_ROAMER_POKEMON, 0
	call_if_eq SouthernIsland_Interior_EventScript_SetUpLatios
	compare VAR_ROAMER_POKEMON, 0
	call_if_ne SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_EventScript_SetUpLatios:: @ 8242A8A
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias:: @ 8242A95
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx:: @ 8242AA0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SouthernIsland_Interior_EventScript_SetBrendanGfx
	compare VAR_RESULT, FEMALE
	goto_if_eq SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx:: @ 8242AB8
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx:: @ 8242ABE
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter:: @ 8242AC4
	lockall
	setvar VAR_0x8008, 12
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati:: @ 8242AD0
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, 0
	delay 30
	waitmoncry
	addobject LOCALID_LATI
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_LATI
	compare VAR_ROAMER_POKEMON, 0
	call_if_eq SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	compare VAR_ROAMER_POKEMON, 0
	call_if_ne SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SouthernIsland_Interior_EventScript_LatiDefeated
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated:: @ 8242B81
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati:: @ 8242B8F
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign:: @ 8242B9A
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars:: @ 8242BA4
	setvar VAR_0x8004, SPECIES_LATIOS
	setvar VAR_0x8005, 50 @ level
	setvar VAR_0x8006, ITEM_SOUL_DEW
	special CreateObedientEnemyMon
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars:: @ 8242BB7
	setvar VAR_0x8004, SPECIES_LATIAS
	setvar VAR_0x8005, 50 @ level
	setvar VAR_0x8006, ITEM_SOUL_DEW
	special CreateObedientEnemyMon
	return

SouthernIsland_Interior_Movement_CameraPanUp: @ 8242BCA
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown: @ 8242BCE
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

SouthernIsland_Interior_Movement_LatiApproach: @ 8242BDA
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

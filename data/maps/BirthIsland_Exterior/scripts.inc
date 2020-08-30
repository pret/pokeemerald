.set LOCALID_DEOXYS_ROCK, 1
.set LOCALID_DEOXYS, 2

BirthIsland_Exterior_MapScripts:: @ 8267F15
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
	.byte 0

BirthIsland_Exterior_OnReturnToField: @ 8267F25
	special SetDeoxysRockPalette
	end

BirthIsland_Exterior_OnTransition: @ 8267F29
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
	call_if_set FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
	call_if_unset FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
	end

BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle:: @ 8267F4E
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	return

BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle:: @ 8267F55
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
	return

BirthIsland_Exterior_OnResume: @ 8267F65
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
	end

BirthIsland_Exterior_EventScript_TryRemoveDeoxys:: @ 8267F6F
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_DEOXYS
	return

BirthIsland_Exterior_EventScript_Triangle:: @ 8267F83
	lock
	faceplayer
	special DoDeoxysRockInteraction
	waitstate
	switch VAR_RESULT
	case 0, BirthIsland_Exterior_EventScript_NotSolved1
	case 1, BirthIsland_Exterior_EventScript_NotSolved2
	case 2, BirthIsland_Exterior_EventScript_Deoxys
	case 3, BirthIsland_Exterior_EventScript_NotSolved3
	end

BirthIsland_Exterior_EventScript_NotSolved1:: @ 8267FBB
	release
	end

BirthIsland_Exterior_EventScript_NotSolved2:: @ 8267FBD
	release
	end

BirthIsland_Exterior_EventScript_NotSolved3:: @ 8267FBF
	release
	end

BirthIsland_Exterior_EventScript_Deoxys:: @ 8267FC1
	waitse
	setfieldeffectargument 0, LOCALID_DEOXYS_ROCK
	setfieldeffectargument 1, 58
	setfieldeffectargument 2, 26
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	addobject LOCALID_DEOXYS
	applymovement LOCALID_DEOXYS, BirthIsland_Exterior_Movement_DeoxysApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_DEOXYS, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_DEOXYS
	setvar VAR_0x8004, SPECIES_DEOXYS
	setvar VAR_0x8005, 30 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BirthIsland_Exterior_EventScript_DefeatedDeoxys
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BirthIsland_Exterior_EventScript_RanFromDeoxys
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BirthIsland_Exterior_EventScript_RanFromDeoxys
	setflag FLAG_BATTLED_DEOXYS
	release
	end

BirthIsland_Exterior_EventScript_DefeatedDeoxys:: @ 826803B
	setflag FLAG_DEFEATED_DEOXYS
	setvar VAR_0x8004, SPECIES_DEOXYS
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_EventScript_RanFromDeoxys:: @ 8268049
	setvar VAR_0x8004, SPECIES_DEOXYS
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_Movement_DeoxysApproach: @ 8268054
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

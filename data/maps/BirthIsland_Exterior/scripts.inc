BirthIsland_Exterior_MapScripts:: @ 8267F15
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_MapScript1_267F65
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_MapScript1_267F25
	.byte 0

BirthIsland_Exterior_MapScript1_267F25: @ 8267F25
	special sub_813B1D0
	end

BirthIsland_Exterior_OnTransition: @ 8267F29
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
	call_if_set FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_267F4E
	call_if_unset FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_267F55
	end

BirthIsland_Exterior_EventScript_267F4E:: @ 8267F4E
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	return

BirthIsland_Exterior_EventScript_267F55:: @ 8267F55
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
	return

BirthIsland_Exterior_MapScript1_267F65: @ 8267F65
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_267F6F
	end

BirthIsland_Exterior_EventScript_267F6F:: @ 8267F6F
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 2
	return

BirthIsland_Exterior_EventScript_267F83:: @ 8267F83
	lock
	faceplayer
	special DoDeoxysRockInteraction
	waitstate
	switch VAR_RESULT
	case 0, BirthIsland_Exterior_EventScript_267FBB
	case 1, BirthIsland_Exterior_EventScript_267FBD
	case 2, BirthIsland_Exterior_EventScript_267FC1
	case 3, BirthIsland_Exterior_EventScript_267FBF
	end

BirthIsland_Exterior_EventScript_267FBB:: @ 8267FBB
	release
	end

BirthIsland_Exterior_EventScript_267FBD:: @ 8267FBD
	release
	end

BirthIsland_Exterior_EventScript_267FBF:: @ 8267FBF
	release
	end

BirthIsland_Exterior_EventScript_267FC1:: @ 8267FC1
	waitse
	setfieldeffectargument 0, 1
	setfieldeffectargument 1, 58
	setfieldeffectargument 2, 26
	dofieldeffect FLDEFF_65
	playbgm MUS_RG_DEOEYE, 0
	waitfieldeffect FLDEFF_65
	addobject 2
	applymovement 2, BirthIsland_Exterior_Movement_268054
	waitmovement 0
	waitse
	playmoncry SPECIES_DEOXYS, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 2
	setvar VAR_0x8004, 410
	setvar VAR_0x8005, 30
	setvar VAR_0x8006, 0
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq BirthIsland_Exterior_EventScript_26803B
	compare VAR_RESULT, 4
	goto_if_eq BirthIsland_Exterior_EventScript_268049
	compare VAR_RESULT, 5
	goto_if_eq BirthIsland_Exterior_EventScript_268049
	setflag FLAG_BATTLED_DEOXYS
	release
	end

BirthIsland_Exterior_EventScript_26803B:: @ 826803B
	setflag FLAG_DEFEATED_DEOXYS
	setvar VAR_0x8004, 410
	goto BirthIsland_Exterior_EventScript_273776
	end

BirthIsland_Exterior_EventScript_268049:: @ 8268049
	setvar VAR_0x8004, 410
	goto BirthIsland_Exterior_EventScript_273776
	end

BirthIsland_Exterior_Movement_268054: @ 8268054
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

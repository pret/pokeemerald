BirthIsland_Exterior_MapScripts:: @ 8267F15
	map_script 3, BirthIsland_Exterior_MapScript1_267F29
	map_script 5, BirthIsland_Exterior_MapScript1_267F65
	map_script 7, BirthIsland_Exterior_MapScript1_267F25
	.byte 0

BirthIsland_Exterior_MapScript1_267F25: @ 8267F25
	special sub_813B1D0
	end

BirthIsland_Exterior_MapScript1_267F29: @ 8267F29
	setflag FLAG_0x8D3
	setvar VAR_OBJ_GFX_ID_0, 100
	setvar VAR_0x4034, 0
	setvar VAR_0x4035, 0
	checkflag FLAG_0x1AD
	call_if 1, BirthIsland_Exterior_EventScript_267F4E
	checkflag FLAG_0x1AD
	call_if 0, BirthIsland_Exterior_EventScript_267F55
	end

BirthIsland_Exterior_EventScript_267F4E:: @ 8267F4E
	setflag FLAG_0x2FB
	setflag FLAG_0x2FC
	return

BirthIsland_Exterior_EventScript_267F55:: @ 8267F55
	checkflag FLAG_0x1AC
	goto_eq BirthIsland_Exterior_EventScript_27374E
	clearflag FLAG_0x2FC
	clearflag FLAG_0x8D4
	return

BirthIsland_Exterior_MapScript1_267F65: @ 8267F65
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, BirthIsland_Exterior_EventScript_267F6F
	end

BirthIsland_Exterior_EventScript_267F6F:: @ 8267F6F
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 7
	goto_if 5, BirthIsland_Exterior_EventScript_27374E
	removeobject 2
	return

BirthIsland_Exterior_EventScript_267F83:: @ 8267F83
	lock
	faceplayer
	special sub_813AFC8
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
	dofieldeffect 65
	playbgm MUS_RG_DEOEYE, 0
	waitfieldeffect 65
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
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 1
	goto_eq BirthIsland_Exterior_EventScript_26803B
	compare VAR_RESULT, 4
	goto_eq BirthIsland_Exterior_EventScript_268049
	compare VAR_RESULT, 5
	goto_eq BirthIsland_Exterior_EventScript_268049
	setflag FLAG_0x1AD
	release
	end

BirthIsland_Exterior_EventScript_26803B:: @ 826803B
	setflag FLAG_0x1AC
	setvar VAR_0x8004, 410
	goto BirthIsland_Exterior_EventScript_273776
	end

BirthIsland_Exterior_EventScript_268049:: @ 8268049
	setvar VAR_0x8004, 410
	goto BirthIsland_Exterior_EventScript_273776
	end

BirthIsland_Exterior_Movement_268054: @ 8268054
	slow_step_down
	slow_step_down
	slow_step_down
	slow_step_down
	slow_step_down
	slow_step_down
	slow_step_down
	step_end


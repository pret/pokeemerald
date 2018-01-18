SkyPillar_Top_MapScripts:: @ 82396B8
	map_script 5, SkyPillar_Top_MapScript1_2396C8
	map_script 3, SkyPillar_Top_MapScript1_2396E6
	map_script 4, SkyPillar_Top_MapScript2_239713
	.byte 0

SkyPillar_Top_MapScript1_2396C8: @ 82396C8
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, SkyPillar_Top_EventScript_2396D2
	end

SkyPillar_Top_EventScript_2396D2:: @ 82396D2
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 7
	goto_if 5, SkyPillar_Top_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_MapScript1_2396E6: @ 82396E6
	compare VAR_0x40CA, 2
	call_if 0, SkyPillar_Top_EventScript_2396FD
	compare VAR_0x40CA, 2
	call_if 4, SkyPillar_Top_EventScript_239705
	end

SkyPillar_Top_EventScript_2396FD:: @ 82396FD
	setmaplayoutindex 438
	setobjectmovementtype 1, 8
	return

SkyPillar_Top_EventScript_239705:: @ 8239705
	checkflag FLAG_0x1C0
	call_if 0, SkyPillar_Top_EventScript_23970F
	return

SkyPillar_Top_EventScript_23970F:: @ 823970F
	clearflag FLAG_0x050
	return

SkyPillar_Top_MapScript2_239713: @ 8239713
	map_script_2 VAR_0x40CA, 0, SkyPillar_Top_EventScript_23971D
	.2byte 0

SkyPillar_Top_EventScript_23971D:: @ 823971D
	turnobject 1, 1
	end

SkyPillar_Top_EventScript_239722:: @ 8239722
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 1
	goto_eq SkyPillar_Top_EventScript_239768
	compare VAR_RESULT, 4
	goto_eq SkyPillar_Top_EventScript_239771
	compare VAR_RESULT, 5
	goto_eq SkyPillar_Top_EventScript_239771
	setflag FLAG_0x1C0
	releaseall
	end

SkyPillar_Top_EventScript_239768:: @ 8239768
	setflag FLAG_0x1C0
	goto SkyPillar_Top_EventScript_23977C
	end

SkyPillar_Top_EventScript_239771:: @ 8239771
	setvar VAR_0x8004, 406
	goto SkyPillar_Top_EventScript_239785
	end

SkyPillar_Top_EventScript_23977C:: @ 823977C
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	releaseall
	end

SkyPillar_Top_EventScript_239785:: @ 8239785
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	bufferspeciesname 0, VAR_0x8004
	msgbox gUnknown_08273204, 4
	releaseall
	end

SkyPillar_Top_EventScript_23979A:: @ 823979A
	lockall
	fadeoutbgm 1
	applymovement 255, SkyPillar_Top_Movement_2725B2
	waitmovement 0
	special SpawnScriptFieldObject
	applymovement 127, SkyPillar_Top_Movement_239858
	waitmovement 0
	special RemoveScriptFieldObject
	applymovement 1, SkyPillar_Top_Movement_23983A
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special sub_8139560
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	waitmoncry
	applymovement 1, SkyPillar_Top_Movement_23984B
	waitmovement 0
	removeobject 1
	msgbox SkyPillar_Top_Text_239860, 4
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnScriptFieldObject
	applymovement 127, SkyPillar_Top_Movement_23985C
	waitmovement 0
	special RemoveScriptFieldObject
	setvar VAR_0x405E, 5
	setvar VAR_0x40CA, 1
	setvar VAR_0x40D7, 1
	releaseall
	end

SkyPillar_Top_Movement_23983A: @ 823983A
	step_14
	step_23
	step_14
	step_14
	step_14
	step_14
	step_14
	step_1f
	step_14
	step_20
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_end

SkyPillar_Top_Movement_23984B: @ 823984B
	step_14
	step_1d
	step_13
	step_20
	step_13
	step_2e
	step_32
	step_32
	step_32
	step_32
	step_32
	step_32
	step_end

SkyPillar_Top_Movement_239858: @ 8239858
	slow_step_up
	slow_step_up
	slow_step_up
	step_end

SkyPillar_Top_Movement_23985C: @ 823985C
	slow_step_down
	slow_step_down
	slow_step_down
	step_end

SkyPillar_Top_Text_239860: @ 8239860
	.string "The awakened RAYQUAZA flew off…$"


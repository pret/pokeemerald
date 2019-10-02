SkyPillar_Top_MapScripts:: @ 82396B8
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_MapScript1_2396C8
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_MapScript2_239713
	.byte 0

SkyPillar_Top_MapScript1_2396C8: @ 82396C8
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_2396D2
	end

SkyPillar_Top_EventScript_2396D2:: @ 82396D2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition: @ 82396E6
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_Top_EventScript_2396FD
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_ge SkyPillar_Top_EventScript_239705
	end

SkyPillar_Top_EventScript_2396FD:: @ 82396FD
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_239705:: @ 8239705
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_23970F
	return

SkyPillar_Top_EventScript_23970F:: @ 823970F
	clearflag FLAG_RAYQUAZA_ON_SKY_TOWER_SUMMIT
	return

SkyPillar_Top_MapScript2_239713: @ 8239713
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_23971D
	.2byte 0

SkyPillar_Top_EventScript_23971D:: @ 823971D
	turnobject 1, DIR_SOUTH
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
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq SkyPillar_Top_EventScript_239768
	compare VAR_RESULT, 4
	goto_if_eq SkyPillar_Top_EventScript_239771
	compare VAR_RESULT, 5
	goto_if_eq SkyPillar_Top_EventScript_239771
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

SkyPillar_Top_EventScript_239768:: @ 8239768
	setflag FLAG_DEFEATED_RAYQUAZA
	goto SkyPillar_Top_EventScript_23977C
	end

SkyPillar_Top_EventScript_239771:: @ 8239771
	setvar VAR_0x8004, SPECIES_RAYQUAZA
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
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_23979A:: @ 823979A
	lockall
	fadeoutbgm 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SkyPillar_Top_Movement_239858
	waitmovement 0
	special RemoveCameraObject
	applymovement 1, SkyPillar_Top_Movement_23983A
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement 1, SkyPillar_Top_Movement_23984B
	waitmovement 0
	removeobject 1
	msgbox SkyPillar_Top_Text_239860, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SkyPillar_Top_Movement_23985C
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_SKY_PILLAR_STATE, 1
	setvar VAR_SKY_PILLAR_RAQUAZA_CRY_DONE, 1
	releaseall
	end

SkyPillar_Top_Movement_23983A: @ 823983A
	delay_16
	walk_in_place_fast_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_23984B: @ 823984B
	delay_16
	walk_in_place_down
	delay_8
	walk_in_place_right
	delay_8
	walk_fastest_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_239858: @ 8239858
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_23985C: @ 823985C
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_239860: @ 8239860
	.string "The awakened RAYQUAZA flew off…$"


NavelRock_Bottom_MapScripts:: @ 8269255
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_MapScript1_269284
	.byte 0

NavelRock_Bottom_OnTransition: @ 8269260
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_269273
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_269277
	end

NavelRock_Bottom_EventScript_269273:: @ 8269273
	setflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_EventScript_269277:: @ 8269277
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_MapScript1_269284: @ 8269284
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_26928E
	end

NavelRock_Bottom_EventScript_26928E:: @ 826928E
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

NavelRock_Bottom_EventScript_2692A2:: @ 82692A2
	lock
	faceplayer
	waitse
	delay 20
	playse SE_T_AME_E
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_T_AME_E
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	delay 20
	setvar VAR_0x8004, SPECIES_LUGIA
	setvar VAR_0x8005, 70  @level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq NavelRock_Bottom_EventScript_269336
	compare VAR_RESULT, 4
	goto_if_eq NavelRock_Bottom_EventScript_269344
	compare VAR_RESULT, 5
	goto_if_eq NavelRock_Bottom_EventScript_269344
	setflag FLAG_CAUGHT_LUGIA
	release
	end

NavelRock_Bottom_EventScript_269336:: @ 8269336
	setflag FLAG_DEFEATED_LUGIA
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_269344:: @ 8269344
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Base_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Base_Frlg_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Base_Frlg_OnResume
	.byte 0

NavelRock_Base_Frlg_OnTransition::
	call_if_set FLAG_FOUGHT_LUGIA, NavelRock_Base_Frlg_EventScript_HideLugia
	call_if_unset FLAG_FOUGHT_LUGIA, NavelRock_Base_Frlg_EventScript_TryShowLugia
	end

NavelRock_Base_Frlg_EventScript_HideLugia::
	setflag FLAG_HIDE_LUGIA
	return

NavelRock_Base_Frlg_EventScript_TryShowLugia::
	goto_if_set FLAG_LUGIA_FLEW_AWAY, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LUGIA
	return

NavelRock_Base_Frlg_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Base_Frlg_EventScript_TryRemoveLugia
	end

NavelRock_Base_Frlg_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_NAVEL_ROCK_LUGIA
	return

NavelRock_Base_Frlg_EventScript_Lugia::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Base_Frlg_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Base_Frlg_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Base_Frlg_EventScript_RanFromLugia
	setflag FLAG_FOUGHT_LUGIA
	release
	end

NavelRock_Base_Frlg_EventScript_DefeatedLugia::
	setflag FLAG_LUGIA_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_LUGIA
	goto EventScript_MonFlewAway
	end

NavelRock_Base_Frlg_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto EventScript_MonFlewAway
	end

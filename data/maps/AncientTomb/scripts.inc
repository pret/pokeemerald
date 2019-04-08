AncientTomb_MapScripts:: @ 8238FB3
	map_script MAP_SCRIPT_ON_RESUME, AncientTomb_MapScript1_238FC3
	map_script MAP_SCRIPT_ON_LOAD, AncientTomb_MapScript1_238FF2
	map_script MAP_SCRIPT_ON_TRANSITION, AncientTomb_OnTransition
	.byte 0

AncientTomb_MapScript1_238FC3: @ 8238FC3
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientTomb_EventScript_238FCD
	end

AncientTomb_EventScript_238FCD:: @ 8238FCD
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AncientTomb_OnTransition: @ 8238FE1
	setflag FLAG_LANDMARK_ANCIENT_TOMB
	call_if_unset FLAG_DEFEATED_REGISTEEL, AncientTomb_EventScript_238FEE
	end

AncientTomb_EventScript_238FEE:: @ 8238FEE
	clearflag FLAG_HIDE_REGISTEEL
	return

AncientTomb_MapScript1_238FF2: @ 8238FF2
	call_if_unset FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_238FFC
	end

AncientTomb_EventScript_238FFC:: @ 8238FFC
	setmetatile 7, 19, 553, 1
	setmetatile 8, 19, 553, 1
	setmetatile 9, 19, 553, 1
	setmetatile 7, 20, 565, 1
	setmetatile 8, 20, 565, 1
	setmetatile 9, 20, 565, 1
	return

AncientTomb_EventScript_239033:: @ 8239033
	lockall
	goto_if_set FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_239046
	braillemessage AncientTomb_Braille_2A6D06
	waitbuttonpress
	hidebox2
	releaseall
	end

AncientTomb_EventScript_239046:: @ 8239046
	msgbox gUnknown_0827304E, MSGBOX_DEFAULT
	releaseall
	end

AncientTomb_EventScript_239050:: @ 8239050
	lockall
	braillemessage AncientTomb_Braille_2A6D06
	waitbuttonpress
	hidebox2
	releaseall
	end

AncientTomb_EventScript_23905A:: @ 823905A
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGISTEEL, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGISTEEL, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq AncientTomb_EventScript_2390A1
	compare VAR_RESULT, 4
	goto_if_eq AncientTomb_EventScript_2390AA
	compare VAR_RESULT, 5
	goto_if_eq AncientTomb_EventScript_2390AA
	setflag FLAG_DEFEATED_REGISTEEL
	release
	end

AncientTomb_EventScript_2390A1:: @ 82390A1
	setflag FLAG_DEFEATED_REGISTEEL
	goto AncientTomb_EventScript_27376D
	end

AncientTomb_EventScript_2390AA:: @ 82390AA
	setvar VAR_0x8004, 403
	goto AncientTomb_EventScript_273776
	end


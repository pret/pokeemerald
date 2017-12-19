AncientTomb_MapScripts:: @ 8238FB3
	map_script 5, AncientTomb_MapScript1_238FC3
	map_script 1, AncientTomb_MapScript1_238FF2
	map_script 3, AncientTomb_MapScript1_238FE1
	.byte 0

AncientTomb_MapScript1_238FC3: @ 8238FC3
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, AncientTomb_EventScript_238FCD
	end

AncientTomb_EventScript_238FCD:: @ 8238FCD
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, AncientTomb_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

AncientTomb_MapScript1_238FE1: @ 8238FE1
	setflag FLAG_0x8B9
	checkflag FLAG_0x1BD
	call_if 0, AncientTomb_EventScript_238FEE
	end

AncientTomb_EventScript_238FEE:: @ 8238FEE
	clearflag FLAG_0x3A9
	return

AncientTomb_MapScript1_238FF2: @ 8238FF2
	checkflag FLAG_SYS_BRAILLE_FLY
	call_if 0, AncientTomb_EventScript_238FFC
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
	checkflag FLAG_SYS_BRAILLE_FLY
	goto_eq AncientTomb_EventScript_239046
	braillemessage AncientTomb_Braille_2A6D06
	waitbuttonpress
	hidebox2
	releaseall
	end

AncientTomb_EventScript_239046:: @ 8239046
	msgbox gUnknown_0827304E, 4
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
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 1
	goto_eq AncientTomb_EventScript_2390A1
	compare_var_to_value VAR_RESULT, 4
	goto_eq AncientTomb_EventScript_2390AA
	compare_var_to_value VAR_RESULT, 5
	goto_eq AncientTomb_EventScript_2390AA
	setflag FLAG_0x1BD
	release
	end

AncientTomb_EventScript_2390A1:: @ 82390A1
	setflag FLAG_0x1BD
	goto AncientTomb_EventScript_27376D
	end

AncientTomb_EventScript_2390AA:: @ 82390AA
	setvar VAR_0x8004, 403
	goto AncientTomb_EventScript_273776
	end


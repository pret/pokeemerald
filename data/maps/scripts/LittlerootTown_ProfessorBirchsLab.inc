LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script 3, LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1
	map_script 4, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06
	map_script 2, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9DB9
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1: @ 81F9CA1
	call LittlerootTown_ProfessorBirchsLab_EventScript_271ED7
	call LittlerootTown_ProfessorBirchsLab_EventScript_2720AD
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7
	compare_var_to_value VAR_0x40D3, 4
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3
	compare_var_to_value VAR_0x40D3, 3
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD:: @ 81F9CCD
	specialvar VAR_RESULT, sub_80C08E4
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9
	setobjectmovementtype 3, 3
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9:: @ 81F9CE9
	setvar VAR_0x40D3, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3:: @ 81F9CF3
	setmaplayoutindex 432
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7:: @ 81F9CF7
	setmaplayoutindex 432
	setobjectmovementtype 3, 3
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06: @ 81F9D06
	map_script_2 VAR_0x4084, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 3, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 6, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	map_script_2 VAR_0x40D3, 5, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40:: @ 81F9D40
	turnobject 255, 2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45:: @ 81F9D45
	turnobject 255, 2
	addobject 2
	addobject 3
	turnobject 3, 2
	setobjectxy 3, 5, 5
	turnobject 2, 1
	setobjectxy 2, 6, 4
	turnobject 1, 4
	setobjectxy 1, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71:: @ 81F9D71
	addobject 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75:: @ 81F9D75
	addobject 4
	addobject 5
	addobject 6
	addobject 3
	turnobject 4, 1
	setobjectxy 4, 8, 4
	turnobject 5, 1
	setobjectxy 5, 9, 4
	turnobject 6, 1
	setobjectxy 6, 10, 4
	turnobject 2, 1
	setobjectxy 2, 6, 4
	turnobject 3, 4
	setobjectxy 3, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9DB9: @ 81F9DB9
	map_script_2 VAR_0x4084, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB
	map_script_2 VAR_0x4084, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB:: @ 81F9DDB
	lockall
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74D
	waitmessage
	playfanfare BGM_FANFA4
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8B1, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07:: @ 81F9E07
	setvar VAR_0x8004, 0
	call LittlerootTown_ProfessorBirchsLab_EventScript_2723DD
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17:: @ 81F9E17
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8F6, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36:: @ 81F9E36
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA9D5, 4
	clearflag FLAG_0x3DF
	setvar VAR_0x4084, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48:: @ 81F9E48
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA35, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67:: @ 81F9E67
	lockall
	applymovement 255, LittlerootTown_ProfessorBirchsLab_Movement_1F9E78
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9E78: @ 81F9E78
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80:: @ 81F9E80
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB16D, 4
	closemessage
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F46
	waitmovement 0
	delay 20
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 20
	applymovement 3, LittlerootTown_ProfessorBirchsLab_Movement_2725A8
	applymovement 255, LittlerootTown_ProfessorBirchsLab_Movement_2725A4
	waitmovement 0
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C
	playse SE_PC_ON
	waitse
	delay 20
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F58
	waitmovement 0
	applymovement 3, LittlerootTown_ProfessorBirchsLab_Movement_2725A6
	applymovement 255, LittlerootTown_ProfessorBirchsLab_Movement_2725A6
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB419, 4
	playfanfare BGM_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB436
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, 4
	closemessage
	setflag FLAG_0x31B
	setflag FLAG_0x31A
	setvar VAR_0x40D3, 2
	setvar VAR_0x40F5, 0
	setflag FLAG_0x072
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32:: @ 81F9F32
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB30F, 4
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C:: @ 81F9F3C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB38E, 4
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_1F9F46: @ 81F9F46
	step_left
	step_25
	step_14
	step_14
	step_right
	step_25
	step_14
	step_14
	step_right
	step_down
	step_down
	step_down
	step_down
	step_right
	step_right
	step_right
	step_26
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F58: @ 81F9F58
	step_left
	step_left
	step_left
	step_up
	step_up
	step_up
	step_up
	step_left
	step_25
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62:: @ 81F9F62
	lockall
	applymovement 255, LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB5F9, 4
	setvar VAR_0x40D3, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C: @ 81F9F7C
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F84:: @ 81F9F84
	lock
	faceplayer
	compare_var_to_value VAR_0x4084, 3
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1
	checkflag FLAG_0x058
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA4E2, 4
	setflag FLAG_0x058
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7:: @ 81F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA641, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1:: @ 81F9FB1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA6CE, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FBB:: @ 81F9FBB
	release
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_2725A8
	waitmovement 0
	drawmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB7F6, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FEF:: @ 81F9FEF
	release
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_2725A8
	waitmovement 0
	drawmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB869, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA023:: @ 81FA023
	release
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_2725A8
	waitmovement 0
	drawmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB8E0, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA057:: @ 81FA057
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBAF8, 4
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA061:: @ 81FA061
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB959, 4
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C:: @ 81FA06C
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_0x4001, 155
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE, 0x0, 0x0, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1:: @ 81FA0A1
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call LittlerootTown_ProfessorBirchsLab_EventScript_2723DD
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC:: @ 81FA0CC
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2:: @ 81FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD:: @ 81FA0FD
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, 4
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D:: @ 81FA10D
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_0x4001, 158
	givemon SPECIES_TOTODILE, 5, ITEM_NONE, 0x0, 0x0, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA142
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA142:: @ 81FA142
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call LittlerootTown_ProfessorBirchsLab_EventScript_2723DD
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D:: @ 81FA16D
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA193:: @ 81FA193
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E:: @ 81FA19E
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, 4
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE:: @ 81FA1AE
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_0x4001, 152
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE, 0x0, 0x0, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3:: @ 81FA1E3
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call LittlerootTown_ProfessorBirchsLab_EventScript_2723DD
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E:: @ 81FA20E
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA234:: @ 81FA234
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F:: @ 81FA23F
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, 4
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F:: @ 81FA24F
	playfanfare BGM_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB9D7
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA25A:: @ 81FA25A
	lock
	faceplayer
	compare_var_to_value VAR_0x40D3, 5
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A
	compare_var_to_value VAR_0x40D3, 2
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA294
	checkflag FLAG_0x12F
	goto_if 0, LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	checkflag FLAG_0x119
	goto_if 0, LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A:: @ 81FA28A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB787, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA294:: @ 81FA294
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E:: @ 81FA29E
	checkflag FLAG_0x380
	goto_if 0, LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare_var_to_value VAR_0x40D3, 3
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare_var_to_value VAR_0x4084, 5
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA74, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2:: @ 81FA2D2
Route101_EventScript_1FA2D2:: @ 81FA2D2
	msgbox Route101_Text_2B5F52, 4
	closemessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox Route101_Text_2B603A, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x119
	setvar VAR_0x40DA, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8:: @ 81FA2F8
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAB22, 4
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAC4B, 4
	closemessage
	applymovement 3, LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0
	waitmovement 0
	applymovement 255, LittlerootTown_ProfessorBirchsLab_Movement_2725A8
	waitmovement 0
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA352
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F
	setvar VAR_0x4084, 5
	setflag FLAG_0x074
	setvar VAR_0x4051, 1
	setvar VAR_0x408D, 4
	setvar VAR_0x4050, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA352:: @ 81FA352
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FADD7, 4
	giveitem_std ITEM_POKE_BALL, 5
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAE40, 4
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F:: @ 81FA37F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF3F, 4
	giveitem_std ITEM_POKE_BALL, 5
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF8E, 4
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC:: @ 81FA3AC
	playfanfare BGM_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FAC32
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special sub_81AFDA0
	setflag FLAG_0x8E4
	setvar VAR_0x40CD, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4:: @ 81FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAD6F, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE:: @ 81FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAEF3, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7:: @ 81FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB05D, 4
	return

LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0: @ 81FA3E0
	step_down
	step_27
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3E3:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0A2, 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3EC:: @ 81FA3EC
	lock
	faceplayer
	compare_var_to_value VAR_0x40D3, 5
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A
	compare_var_to_value VAR_0x40D3, 6
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1FA465
	compare_var_to_value VAR_0x40D3, 2
	goto_if 4, LittlerootTown_ProfessorBirchsLab_EventScript_1FA490
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA428
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA431
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA428:: @ 81FA428
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF08, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA431:: @ 81FA431
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB073, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A:: @ 81FA43A
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA453
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA453:: @ 81FA453
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBB68, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C:: @ 81FA45C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC2D, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA465:: @ 81FA465
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA487
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E:: @ 81FA47E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC8D, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA487:: @ 81FA487
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBCD2, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA490:: @ 81FA490
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9:: @ 81FA4A9
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB528, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2:: @ 81FA4B2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB58A, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4BB:: @ 81FA4BB
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0E7, 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4C4:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB124, 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4CD:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB148, 3
	end


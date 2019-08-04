LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9DB9
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1: @ 81F9CA1
	call Common_EventScript_SetupRivalGender
	call LittlerootTown_ProfessorBirchsLab_EventScript_2720AD
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7
	compare VAR_0x40D3, 4
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3
	compare VAR_0x40D3, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD:: @ 81F9CCD
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9:: @ 81F9CE9
	setvar VAR_0x40D3, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3:: @ 81F9CF3
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7:: @ 81F9CF7
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06: @ 81F9D06
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 3, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 6, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	map_script_2 VAR_0x40D3, 5, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40:: @ 81F9D40
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45:: @ 81F9D45
	turnobject EVENT_OBJ_ID_PLAYER, 2
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
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB:: @ 81F9DDB
	lockall
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74D
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8B1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07:: @ 81F9E07
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17:: @ 81F9E17
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8F6, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36:: @ 81F9E36
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA9D5, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48:: @ 81F9E48
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA35, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67:: @ 81F9E67
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9E78
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9E78: @ 81F9E78
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80:: @ 81F9E80
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB16D, MSGBOX_DEFAULT
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
	applymovement 3, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C
	playse SE_PC_ON
	waitse
	delay 20
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F58
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB419, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB436
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_0x40D3, 2
	setvar VAR_SCOTT_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32:: @ 81F9F32
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB30F, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C:: @ 81F9F3C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB38E, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_1F9F46: @ 81F9F46
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F58: @ 81F9F58
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62:: @ 81F9F62
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB5F9, MSGBOX_DEFAULT
	setvar VAR_0x40D3, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C: @ 81F9F7C
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F84:: @ 81F9F84
	lock
	faceplayer
	compare VAR_BIRCH_LAB_STATE, 3
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA4E2, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7:: @ 81F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA641, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1:: @ 81F9FB1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA6CE, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FBB:: @ 81F9FBB
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB7F6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FEF:: @ 81F9FEF
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB869, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA023:: @ 81FA023
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB8E0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA057:: @ 81FA057
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBAF8, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA061:: @ 81FA061
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB959, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C:: @ 81FA06C
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE, 0x0, 0x0, 0
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1:: @ 81FA0A1
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC:: @ 81FA0CC
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2:: @ 81FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD:: @ 81FA0FD
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D:: @ 81FA10D
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_NONE, 0x0, 0x0, 0
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA142
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA142:: @ 81FA142
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D:: @ 81FA16D
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA193:: @ 81FA193
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E:: @ 81FA19E
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE:: @ 81FA1AE
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE, 0x0, 0x0, 0
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3:: @ 81FA1E3
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E:: @ 81FA20E
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA234:: @ 81FA234
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F:: @ 81FA23F
	erasemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_0x40D3, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F:: @ 81FA24F
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB9D7
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA25A:: @ 81FA25A
	lock
	faceplayer
	compare VAR_0x40D3, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A
	compare VAR_0x40D3, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA294
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A:: @ 81FA28A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB787, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA294:: @ 81FA294
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E:: @ 81FA29E
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_0x40D3, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA74, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2:: @ 81FA2D2
Route101_EventScript_1FA2D2:: @ 81FA2D2
	msgbox Route101_Text_2B5F52, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route101_Text_2B603A, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_0x40DA, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8:: @ 81FA2F8
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAB22, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAC4B, MSGBOX_DEFAULT
	closemessage
	applymovement 3, LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA352
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_0x4050, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA352:: @ 81FA352
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FADD7, MSGBOX_DEFAULT
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAE40, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F:: @ 81FA37F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF3F, MSGBOX_DEFAULT
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF8E, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC:: @ 81FA3AC
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FAC32
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special sub_81AFDA0
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4:: @ 81FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAD6F, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE:: @ 81FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAEF3, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7:: @ 81FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB05D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0: @ 81FA3E0
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3E3:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0A2, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3EC:: @ 81FA3EC
	lock
	faceplayer
	compare VAR_0x40D3, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA465
	compare VAR_0x40D3, 2
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA490
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA428
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA431
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA428:: @ 81FA428
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF08, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA431:: @ 81FA431
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB073, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A:: @ 81FA43A
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA453
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA453:: @ 81FA453
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBB68, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C:: @ 81FA45C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC2D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA465:: @ 81FA465
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA487
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E:: @ 81FA47E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC8D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA487:: @ 81FA487
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBCD2, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA490:: @ 81FA490
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9:: @ 81FA4A9
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB528, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2:: @ 81FA4B2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB58A, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4BB:: @ 81FA4BB
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0E7, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4C4:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB124, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4CD:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB148, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4D6:: @ 81FA4D6
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_1FBD1A
	waitmessage
	clearflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_1FA4E2: @ 81FA4E2
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA641: @ 81FA641
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA6CE: @ 81FA6CE
	.string "PROF. BIRCH is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA74D: @ 81FA74D
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_1FA8B1: @ 81FA8B1
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Text_1FA8F6: @ 81FA8F6
	.string "PROF. BIRCH: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

LittlerootTown_ProfessorBirchsLab_Text_1FA9D5: @ 81FA9D5
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAA35: @ 81FAA35
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAA74: @ 81FAA74
	.string "PROF. BIRCH: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAB22: @ 81FAB22
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.\p"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this POKéDEX.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAC32: @ 81FAC32
	.string "{PLAYER} received the POKéDEX!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAC4B: @ 81FAC4B
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare POKéMON\n"
	.string "and records its data in the POKéDEX,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAD6F: @ 81FAD6F
	.string "PROF. BIRCH: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"

LittlerootTown_ProfessorBirchsLab_Text_1FADD7: @ 81FADD7
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAE40: @ 81FAE40
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAEF3: @ 81FAEF3
	.string "Oh? Your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF08: @ 81FAF08
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF3F: @ 81FAF3F
	.string "BRENDAN: Huh…\n"
	.string "So you got a POKéDEX, too.\p"
	.string "Well then, here.\n"
	.string "I'll give you these.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF8E: @ 81FAF8E
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB05D: @ 81FB05D
	.string "Hey, your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB073: @ 81FB073
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"

LittlerootTown_ProfessorBirchsLab_Text_1FB0A2: @ 81FB0A2
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB0E7: @ 81FB0E7
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB124: @ 81FB124
	.string "It's crammed with books on POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB148: @ 81FB148
	.string "It's a book that's too hard to read.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB16D: @ 81FB16D
	.string "PROF. BIRCH: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study POKéMON.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also POKéMON from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB30F: @ 81FB30F
	.string "MAY: Eheheh!\p"
	.string "It's so cool that even my POKéDEX\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many POKéMON, {PLAYER}{KUN}!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB38E: @ 81FB38E
	.string "BRENDAN: I went out all over HOENN\n"
	.string "and checked out POKéMON.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode POKéDEX.\p"
	.string "Yep, you're lucky, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB419: @ 81FB419
	.string "PROF. BIRCH: Okay, all done!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB436: @ 81FB436
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB466: @ 81FB466
	.string "PROF. BIRCH: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB528: @ 81FB528
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB58A: @ 81FB58A
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB5F9: @ 81FB5F9
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare POKéMON only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB787: @ 81FB787
	.string "PROF. BIRCH: These are rare POKéMON\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB7F6: @ 81FB7F6
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB869: @ 81FB869
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB8E0: @ 81FB8E0
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB959: @ 81FB959
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9A8: @ 81FB9A8
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9D7: @ 81FB9D7
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9FC: @ 81FB9FC
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBA2C: @ 81FBA2C
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_1FBAF8: @ 81FBAF8
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBB3A: @ 81FBB3A
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBB68: @ 81FBB68
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBC2D: @ 81FBC2D
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBC8D: @ 81FBC8D
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBCD2: @ 81FBCD2
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBD1A: @ 81FBD1A
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

SootopolisCity_MapScripts:: @ 81E565C
	map_script 1, SootopolisCity_MapScript1_1E5676
	map_script 3, SootopolisCity_MapScript1_1E56EF
	map_script 5, SootopolisCity_MapScript1_1E590B
	map_script 2, SootopolisCity_MapScript2_1E5914
	map_script 4, SootopolisCity_MapScript2_1E58DB
	.byte 0

SootopolisCity_MapScript1_1E5676: @ 81E5676
	checkflag FLAG_0x09E
	call_if 0, SootopolisCity_EventScript_1E56E5
	checkflag FLAG_0x081
	goto_if 0, SootopolisCity_EventScript_1E5692
	checkflag FLAG_0x09E
	call_if 0, SootopolisCity_EventScript_1E5693
	end

SootopolisCity_EventScript_1E5692:: @ 81E5692
	end

SootopolisCity_EventScript_1E5693:: @ 81E5693
	setmetatile 9, 6, 584, 1
	setmetatile 9, 17, 584, 1
	setmetatile 9, 26, 584, 1
	setmetatile 44, 17, 584, 1
	setmetatile 8, 35, 584, 1
	setmetatile 53, 28, 584, 1
	setmetatile 45, 6, 584, 1
	setmetatile 48, 25, 584, 1
	setmetatile 51, 36, 584, 1
	return

SootopolisCity_EventScript_1E56E5:: @ 81E56E5
	setmetatile 31, 32, 592, 1
	return

SootopolisCity_MapScript1_1E56EF: @ 81E56EF
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	compare_var_to_value VAR_0x405E, 1
	call_if 1, SootopolisCity_EventScript_1E5781
	compare_var_to_value VAR_0x40CA, 1
	call_if 1, SootopolisCity_EventScript_1E5781
	call SootopolisCity_EventScript_1E5805
	call SootopolisCity_EventScript_1E57B2
	compare_var_to_value VAR_0x405E, 1
	call_if 1, SootopolisCity_EventScript_1E5785
	compare_var_to_value VAR_0x405E, 2
	call_if 1, SootopolisCity_EventScript_1E5785
	compare_var_to_value VAR_0x405E, 3
	call_if 1, SootopolisCity_EventScript_1E5785
	compare_var_to_value VAR_0x405E, 4
	call_if 1, SootopolisCity_EventScript_1E5785
	compare_var_to_value VAR_0x405E, 5
	call_if 1, SootopolisCity_EventScript_1E5785
	compare_var_to_value VAR_0x405E, 2
	call_if 1, SootopolisCity_EventScript_1E5842
	compare_var_to_value VAR_0x405E, 3
	call_if 1, SootopolisCity_EventScript_1E5842
	compare_var_to_value VAR_0x405E, 4
	call_if 1, SootopolisCity_EventScript_1E585B
	compare_var_to_value VAR_0x405E, 5
	call_if 1, SootopolisCity_EventScript_1E5871
	compare_var_to_value VAR_0x405E, 6
	call_if 1, SootopolisCity_EventScript_1E58D3
	end

SootopolisCity_EventScript_1E5781:: @ 81E5781
	setflag FLAG_SPECIAL_FLAG_0x4000
	return

SootopolisCity_EventScript_1E5785:: @ 81E5785
	setobjectxyperm 3, 13, 48
	setobjectxyperm 5, 46, 32
	setobjectxyperm 4, 48, 41
	setobjectxyperm 8, 45, 43
	setobjectmovementtype 3, 7
	setobjectmovementtype 5, 9
	setobjectmovementtype 4, 9
	setobjectmovementtype 8, 9
	return

SootopolisCity_EventScript_1E57B2:: @ 81E57B2
	compare_var_to_value VAR_0x405E, 0
	goto_eq SootopolisCity_EventScript_1E5800
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E5800
	compare_var_to_value VAR_0x405E, 1
	goto_eq SootopolisCity_EventScript_1E5801
	compare_var_to_value VAR_0x405E, 2
	goto_eq SootopolisCity_EventScript_1E5801
	compare_var_to_value VAR_0x405E, 3
	goto_eq SootopolisCity_EventScript_1E5801
	compare_var_to_value VAR_0x405E, 4
	goto_eq SootopolisCity_EventScript_1E5801
	compare_var_to_value VAR_0x40CA, 1
	goto_if 3, SootopolisCity_EventScript_1E5801
	return

SootopolisCity_EventScript_1E5800:: @ 81E5800
	return

SootopolisCity_EventScript_1E5801:: @ 81E5801
	setmaplayoutindex 357
	return

SootopolisCity_EventScript_1E5805:: @ 81E5805
	compare_var_to_value VAR_0x405E, 0
	goto_eq SootopolisCity_EventScript_1E583D
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E583D
	compare_var_to_value VAR_0x405E, 1
	goto_eq SootopolisCity_EventScript_1E583E
	compare_var_to_value VAR_0x40CA, 1
	goto_eq SootopolisCity_EventScript_1E583E
	compare_var_to_value VAR_0x40CA, 1
	goto_if 3, SootopolisCity_EventScript_27207A
	return

SootopolisCity_EventScript_1E583D:: @ 81E583D
	return

SootopolisCity_EventScript_1E583E:: @ 81E583E
	setweather 13
	return

SootopolisCity_EventScript_1E5842:: @ 81E5842
	checkflag FLAG_0x133
	goto_eq SootopolisCity_EventScript_1E584C
	return

SootopolisCity_EventScript_1E584C:: @ 81E584C
	setobjectxyperm 1, 30, 18
	setobjectxyperm 7, 32, 18
	return

SootopolisCity_EventScript_1E585B:: @ 81E585B
	setobjectxyperm 1, 30, 18
	setobjectxyperm 18, 31, 18
	setobjectxyperm 7, 32, 18
	end

SootopolisCity_EventScript_1E5871:: @ 81E5871
	setobjectxyperm 1, 31, 18
	setobjectxyperm 7, 29, 33
	setobjectxyperm 16, 33, 35
	setobjectxyperm 17, 34, 35
	compare_var_to_value VAR_0x40D8, 0
	call_if 1, SootopolisCity_EventScript_1E58AF
	compare_var_to_value VAR_0x40D8, 1
	call_if 1, SootopolisCity_EventScript_1E58BB
	compare_var_to_value VAR_0x40D8, 2
	call_if 1, SootopolisCity_EventScript_1E58C7
	return

SootopolisCity_EventScript_1E58AF:: @ 81E58AF
	setobjectxyperm 18, 31, 33
	setobjectmovementtype 18, 8
	return

SootopolisCity_EventScript_1E58BB:: @ 81E58BB
	setobjectxyperm 18, 32, 33
	setobjectmovementtype 18, 8
	return

SootopolisCity_EventScript_1E58C7:: @ 81E58C7
	setobjectxyperm 18, 30, 33
	setobjectmovementtype 18, 8
	return

SootopolisCity_EventScript_1E58D3:: @ 81E58D3
	setobjectxyperm 1, 31, 18
	return

SootopolisCity_MapScript2_1E58DB: @ 81E58DB
	map_script_2 VAR_0x405E, 5, SootopolisCity_EventScript_1E58E5
	.2byte 0

SootopolisCity_EventScript_1E58E5:: @ 81E58E5
	compare_var_to_value VAR_0x40CA, 1
	call_if 1, SootopolisCity_EventScript_1E58FC
	compare_var_to_value VAR_0x40CA, 2
	call_if 1, SootopolisCity_EventScript_1E5901
	end

SootopolisCity_EventScript_1E58FC:: @ 81E58FC
	turnobject 255, 2
	return

SootopolisCity_EventScript_1E5901:: @ 81E5901
	turnobject 255, 2
	setvar VAR_0x40CA, 3
	return

SootopolisCity_MapScript1_1E590B: @ 81E590B
	setdivewarp UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_MapScript2_1E5914: @ 81E5914
	map_script_2 VAR_0x405E, 1, SootopolisCity_EventScript_1E5926
	map_script_2 VAR_0x40CA, 1, SootopolisCity_EventScript_1E5BFE
	.2byte 0

SootopolisCity_EventScript_1E5926:: @ 81E5926
	lockall
	special sub_8138AD0
	compare_var_to_value VAR_0x8004, 43
	goto_if 5, SootopolisCity_EventScript_1E5A82
	compare_var_to_value VAR_0x8005, 32
	goto_if 5, SootopolisCity_EventScript_1E5A82
	goto SootopolisCity_EventScript_1E5946
	end

SootopolisCity_EventScript_1E5946:: @ 81E5946
	delay 60
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveScriptFieldObject
	delay 60
	fadescreenspeed 1, 8
	setweather 15
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement 10, SootopolisCity_Movement_2725A4
	applymovement 9, SootopolisCity_Movement_2725A8
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnScriptFieldObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement 127, SootopolisCity_Movement_1E5A75
	waitmovement 0
	special RemoveScriptFieldObject
	setvar VAR_0x405E, 2
	clearflag FLAG_SPECIAL_FLAG_0x4000
	releaseall
	end

SootopolisCity_Movement_1E5A68: @ 81E5A68
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_92
	step_end

SootopolisCity_Movement_1E5A75: @ 81E5A75
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_91
	step_end

SootopolisCity_EventScript_1E5A82:: @ 81E5A82
	delay 60
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveScriptFieldObject
	delay 60
	fadescreenspeed 1, 8
	setweather 15
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement 10, SootopolisCity_Movement_2725A4
	applymovement 9, SootopolisCity_Movement_2725A8
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnScriptFieldObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement 127, SootopolisCity_Movement_1E5BAE
	waitmovement 0
	special RemoveScriptFieldObject
	setvar VAR_0x405E, 2
	clearflag FLAG_SPECIAL_FLAG_0x4000
	releaseall
	end

SootopolisCity_Movement_1E5BA4: @ 81E5BA4
	step_91
	step_91
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

SootopolisCity_Movement_1E5BAE: @ 81E5BAE
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_92
	step_92
	step_end

SootopolisCity_Movement_1E5BB8: @ 81E5BB8
	step_1b
	step_1b
	step_1b
	step_14
	step_14
	step_14
	step_5e
	step_96
	step_5f
	step_end

SootopolisCity_Movement_1E5BC2: @ 81E5BC2
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_5e
	step_96
	step_5f
	step_end

SootopolisCity_Movement_1E5BCF: @ 81E5BCF
	step_40
	step_right
	step_14
	step_14
	step_14
	step_41
	step_end

SootopolisCity_Movement_1E5BD6: @ 81E5BD6
	step_1b
	step_1b
	step_1b
	step_1b
	step_1b
	step_1b
	step_end

SootopolisCity_Movement_1E5BDD: @ 81E5BDD
	step_1c
	step_1c
	step_1c
	step_14
	step_14
	step_14
	step_18
	step_end

SootopolisCity_Movement_1E5BE5: @ 81E5BE5
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_18
	step_end

SootopolisCity_Movement_1E5BF0: @ 81E5BF0
	step_40
	step_left
	step_14
	step_14
	step_14
	step_41
	step_end

SootopolisCity_Movement_1E5BF7: @ 81E5BF7
	step_1c
	step_1c
	step_1c
	step_1c
	step_1c
	step_1c
	step_end

SootopolisCity_EventScript_1E5BFE:: @ 81E5BFE
	lockall
	special sub_8138AD0
	compare_var_to_value VAR_0x8004, 43
	goto_if 5, SootopolisCity_EventScript_1E5CCE
	compare_var_to_value VAR_0x8005, 32
	goto_if 5, SootopolisCity_EventScript_1E5CCE
	goto SootopolisCity_EventScript_1E5C1E
	end

SootopolisCity_EventScript_1E5C1E:: @ 81E5C1E
	delay 60
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveScriptFieldObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	playse SE_T_KAMI
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5E63
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
	setweather 0
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special sub_81379F8
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_0x40CA, 3
	clearflag FLAG_0x053
	fadenewbgm BGM_RUNECITY
	delay 120
	clearflag FLAG_SPECIAL_FLAG_0x4000
	warp8 SOOTOPOLIS_CITY, 255, 43, 32
	waitstate
	end

SootopolisCity_EventScript_1E5CCE:: @ 81E5CCE
	delay 60
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveScriptFieldObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	special SpawnScriptFieldObject
	applymovement 127, SootopolisCity_Movement_1E5E63
	applymovement 255, SootopolisCity_Movement_1E5E68
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
	setweather 0
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special sub_81379F8
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_0x40CA, 2
	clearflag FLAG_0x053
	fadenewbgm BGM_NAMINORI
	delay 120
	clearflag FLAG_SPECIAL_FLAG_0x4000
	warp8 SOOTOPOLIS_CITY, 255, 29, 53
	waitstate
	end

SootopolisCity_EventScript_1E5D82:: @ 81E5D82
	setmetatile 27, 43, 656, 0
	setmetatile 28, 43, 656, 0
	setmetatile 29, 43, 656, 0
	setmetatile 30, 43, 656, 0
	setmetatile 27, 44, 656, 0
	setmetatile 28, 44, 656, 0
	setmetatile 29, 44, 656, 0
	setmetatile 30, 44, 656, 0
	setmetatile 27, 45, 656, 0
	setmetatile 28, 45, 656, 0
	setmetatile 29, 45, 656, 0
	setmetatile 30, 45, 656, 0
	setmetatile 32, 43, 656, 0
	setmetatile 33, 43, 656, 0
	setmetatile 34, 43, 656, 0
	setmetatile 35, 43, 656, 0
	setmetatile 32, 44, 656, 0
	setmetatile 33, 44, 656, 0
	setmetatile 34, 44, 656, 0
	setmetatile 35, 44, 656, 0
	setmetatile 32, 45, 656, 0
	setmetatile 33, 45, 656, 0
	setmetatile 34, 45, 656, 0
	setmetatile 35, 45, 656, 0
	return

SootopolisCity_Movement_1E5E5B: @ 81E5E5B
	step_16
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_end

SootopolisCity_Movement_1E5E63: @ 81E5E63
	step_up
	step_up
	step_up
	step_up
	step_end

SootopolisCity_Movement_1E5E68: @ 81E5E68
	step_up
	step_up
	step_up
	step_up
	step_end

	.incbin "baserom.gba", 0x1e5e6d, 0x20

SootopolisCity_EventScript_1E5E8D:: @ 81E5E8D
	lock
	faceplayer
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E5EC4
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E5ECE
	compare_var_to_value VAR_0x405E, 2
	goto_if 4, SootopolisCity_EventScript_1E5EBA
	msgbox SootopolisCity_Text_1E6D77, 4
	release
	end

SootopolisCity_EventScript_1E5EBA:: @ 81E5EBA
	msgbox SootopolisCity_Text_1E6DFE, 4
	release
	end

SootopolisCity_EventScript_1E5EC4:: @ 81E5EC4
	msgbox SootopolisCity_Text_1E6F38, 4
	release
	end

SootopolisCity_EventScript_1E5ECE:: @ 81E5ECE
	msgbox SootopolisCity_Text_1E6ED4, 4
	release
	end

SootopolisCity_EventScript_1E5ED8:: @ 81E5ED8
	lock
	faceplayer
	compare_var_to_value VAR_0x405E, 1
	goto_if 3, SootopolisCity_EventScript_1E5F1B
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E5F1B
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E5F10
	msgbox SootopolisCity_Text_1E6BFF, 4
	closemessage
	applymovement 3, SootopolisCity_Movement_2725A2
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E5F10:: @ 81E5F10
	msgbox SootopolisCity_Text_1E6C53, 4
	closemessage
	release
	end

SootopolisCity_EventScript_1E5F1B:: @ 81E5F1B
	dodailyevents
	special sub_8138B10
	checkflag FLAG_0x932
	goto_eq SootopolisCity_EventScript_1E5FBB
	msgbox SootopolisCity_Text_2A7BB0, 4
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_EventScript_272054
	setflag FLAG_0x932
	msgbox SootopolisCity_Text_2A7C7C, 4
	random 2
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_EventScript_1E5F79
	compare_var_to_value VAR_RESULT, 1
	goto_eq SootopolisCity_EventScript_1E5F9A
	end

SootopolisCity_EventScript_1E5F79:: @ 81E5F79
	giveitem_std ITEM_FIGY_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_EventScript_272054
	msgbox SootopolisCity_Text_2A7CB7, 4
	release
	end

SootopolisCity_EventScript_1E5F9A:: @ 81E5F9A
	giveitem_std ITEM_IAPAPA_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_EventScript_272054
	msgbox SootopolisCity_Text_2A7CB7, 4
	release
	end

SootopolisCity_EventScript_1E5FBB:: @ 81E5FBB
	msgbox SootopolisCity_Text_2A7CEC, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SootopolisCity_EventScript_1E5FD8
	msgbox SootopolisCity_Text_2A7DD2, 4
	release
	end

SootopolisCity_EventScript_1E5FD8:: @ 81E5FD8
	msgbox SootopolisCity_Text_2A7D80, 4
	release
	end

SootopolisCity_EventScript_1E5FE2:: @ 81E5FE2
	lockall
	applymovement 2, SootopolisCity_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E600D
	msgbox SootopolisCity_Text_1E71A1, 4
	closemessage
	applymovement 2, SootopolisCity_Movement_2725A2
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E600D:: @ 81E600D
	msgbox SootopolisCity_Text_1E728C, 4
	releaseall
	end

SootopolisCity_EventScript_1E6017:: @ 81E6017
	lock
	faceplayer
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E602E
	msgbox SootopolisCity_Text_1E6CCA, 4
	release
	end

SootopolisCity_EventScript_1E602E:: @ 81E602E
	msgbox SootopolisCity_Text_1E6D57, 4
	release
	end

SootopolisCity_EventScript_1E6038:: @ 81E6038
	lock
	faceplayer
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E607A
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E6084
	compare_var_to_value VAR_0x405E, 2
	goto_if 4, SootopolisCity_EventScript_1E6065
	msgbox SootopolisCity_Text_1E6F90, 4
	release
	end

SootopolisCity_EventScript_1E6065:: @ 81E6065
	msgbox SootopolisCity_Text_1E7078, 4
	closemessage
	applymovement 8, SootopolisCity_Movement_2725A2
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E607A:: @ 81E607A
	msgbox SootopolisCity_Text_1E710B, 4
	release
	end

SootopolisCity_EventScript_1E6084:: @ 81E6084
	msgbox SootopolisCity_Text_1E70D4, 4
	release
	end

SootopolisCity_EventScript_1E608E:: @ 81E608E
	lockall
	applymovement 4, SootopolisCity_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E60D9
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E60CF
	compare_var_to_value VAR_0x405E, 1
	goto_if 3, SootopolisCity_EventScript_1E60CF
	msgbox SootopolisCity_Text_1E690B, 4
	closemessage
	applymovement 4, SootopolisCity_Movement_2725A2
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E60CF:: @ 81E60CF
	msgbox SootopolisCity_Text_1E68A1, 4
	release
	end

SootopolisCity_EventScript_1E60D9:: @ 81E60D9
	msgbox SootopolisCity_Text_1E6920, 4
	release
	end

SootopolisCity_EventScript_1E60E3:: @ 81E60E3
	lockall
	applymovement 5, SootopolisCity_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x405E, 5
	goto_eq SootopolisCity_EventScript_1E612D
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq SootopolisCity_EventScript_1E6137
	compare_var_to_value VAR_0x405E, 6
	goto_if 4, SootopolisCity_EventScript_1E6141
	compare_var_to_value VAR_0x405E, 1
	goto_if 3, SootopolisCity_EventScript_1E6141
	msgbox SootopolisCity_Text_1E6692, 4
	closemessage
	applymovement 5, SootopolisCity_Movement_2725A2
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E612D:: @ 81E612D
	msgbox SootopolisCity_Text_1E6750, 4
	release
	end

SootopolisCity_EventScript_1E6137:: @ 81E6137
	msgbox SootopolisCity_Text_1E677F, 4
	release
	end

SootopolisCity_EventScript_1E6141:: @ 81E6141
	msgbox SootopolisCity_Text_1E6618, 4
	release
	end

SootopolisCity_EventScript_1E614B:: @ 81E614B
	msgbox SootopolisCity_Text_1E656F, 3
	end

SootopolisCity_EventScript_1E6154:: @ 81E6154
	msgbox SootopolisCity_Text_1E65C8, 3
	end


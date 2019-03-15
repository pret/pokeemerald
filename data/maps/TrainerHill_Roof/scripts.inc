TrainerHill_Roof_MapScripts:: @ 8268FA7
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Roof_MapScript1_2C8336
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Roof_MapScript2_2C8381
	.byte 0

TrainerHill_Roof_EventScript_268FB2:: @ 8268FB2
	setvar VAR_0x8004, TRAINER_HILL_FUNC_12
	special CallTrainerHillFunction
	lock
	faceplayer
	setvar VAR_0x8004, TRAINER_HILL_FUNC_1
	special CallTrainerHillFunction
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_268FEA
	case 1, TrainerHill_Roof_EventScript_268FF2
	case 2, TrainerHill_Roof_EventScript_2690A8

TrainerHill_Roof_EventScript_268FEA:: @ 8268FEA
	msgbox TrainerHill_Roof_Text_268986, MSGBOX_DEFAULT

TrainerHill_Roof_EventScript_268FF2:: @ 8268FF2
	setvar VAR_0x8004, TRAINER_HILL_FUNC_2
	special CallTrainerHillFunction
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_269020
	case 1, TrainerHill_Roof_EventScript_269037
	case 2, TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269020:: @ 8269020
	msgbox TrainerHill_Roof_Text_268AC5, MSGBOX_DEFAULT
	playfanfare MUS_FANFA1
	message gUnknown_08272A78
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269037:: @ 8269037
	msgbox TrainerHill_Roof_Text_268AC5, MSGBOX_DEFAULT
	msgbox gUnknown_08272A89, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_Text_268B07, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269054:: @ 8269054
	setvar VAR_0x8004, TRAINER_HILL_FUNC_3
	special CallTrainerHillFunction
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_269082
	case 1, TrainerHill_Roof_EventScript_269090
	case 2, TrainerHill_Roof_EventScript_26909E

TrainerHill_Roof_EventScript_269082:: @ 8269082
	msgbox TrainerHill_Roof_Text_268B43, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_26909E
	end

TrainerHill_Roof_EventScript_269090:: @ 8269090
	msgbox TrainerHill_Roof_Text_268C03, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_26909E
	end

TrainerHill_Roof_EventScript_26909E:: @ 826909E
	msgbox TrainerHill_Roof_Text_268C31, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_EventScript_2690A8:: @ 82690A8
	msgbox TrainerHill_Roof_Text_268C31, MSGBOX_DEFAULT
	release
	end


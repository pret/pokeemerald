TrainerHill_Roof_MapScripts:: @ 8268FA7
	map_script 5, TrainerHill_Roof_MapScript1_2C8336
	map_script 2, TrainerHill_Roof_MapScript2_2C8381
	.byte 0

TrainerHill_Roof_EventScript_268FB2:: @ 8268FB2
	setvar VAR_0x8004, 12
	special sp194_trainer_tower
	lock
	faceplayer
	setvar VAR_0x8004, 1
	special sp194_trainer_tower
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_268FEA
	case 1, TrainerHill_Roof_EventScript_268FF2
	case 2, TrainerHill_Roof_EventScript_2690A8

TrainerHill_Roof_EventScript_268FEA:: @ 8268FEA
	msgbox TrainerHill_Roof_Text_268986, 4

TrainerHill_Roof_EventScript_268FF2:: @ 8268FF2
	setvar VAR_0x8004, 2
	special sp194_trainer_tower
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_269020
	case 1, TrainerHill_Roof_EventScript_269037
	case 2, TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269020:: @ 8269020
	msgbox TrainerHill_Roof_Text_268AC5, 4
	playfanfare MUS_FANFA1
	message gUnknown_08272A78
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269037:: @ 8269037
	msgbox TrainerHill_Roof_Text_268AC5, 4
	msgbox gUnknown_08272A89, 4
	msgbox TrainerHill_Roof_Text_268B07, 4
	goto TrainerHill_Roof_EventScript_269054

TrainerHill_Roof_EventScript_269054:: @ 8269054
	setvar VAR_0x8004, 3
	special sp194_trainer_tower
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_269082
	case 1, TrainerHill_Roof_EventScript_269090
	case 2, TrainerHill_Roof_EventScript_26909E

TrainerHill_Roof_EventScript_269082:: @ 8269082
	msgbox TrainerHill_Roof_Text_268B43, 4
	goto TrainerHill_Roof_EventScript_26909E
	end

TrainerHill_Roof_EventScript_269090:: @ 8269090
	msgbox TrainerHill_Roof_Text_268C03, 4
	goto TrainerHill_Roof_EventScript_26909E
	end

TrainerHill_Roof_EventScript_26909E:: @ 826909E
	msgbox TrainerHill_Roof_Text_268C31, 4
	release
	end

TrainerHill_Roof_EventScript_2690A8:: @ 82690A8
	msgbox TrainerHill_Roof_Text_268C31, 4
	release
	end


Route105_MapScripts:: @ 81EE1DB
	map_script 1, Route105_MapScript1_1EE1EB
	map_script 3, Route105_MapScript1_1EE21E
	map_script 2, Route105_MapScript2_1EE240
	.byte 0

Route105_MapScript1_1EE1EB: @ 81EE1EB
	checkflag FLAG_0x0E4
	call_if 0, Route105_EventScript_1EE20B
	compare VAR_0x4037, 9
	call_if 1, Route105_EventScript_2739AB
	compare VAR_0x4037, 10
	call_if 1, Route105_EventScript_273A18
	end

Route105_EventScript_1EE20B:: @ 81EE20B
	setmetatile 9, 19, 124, 1
	setmetatile 9, 20, 145, 1
	return

Route105_MapScript1_1EE21E: @ 81EE21E
	compare VAR_0x4039, 1
	call_if 1, Route105_EventScript_273D13
	compare VAR_0x4037, 9
	call_if 1, Route105_EventScript_273D17
	compare VAR_0x4037, 10
	call_if 1, Route105_EventScript_273D17
	end

Route105_MapScript2_1EE240: @ 81EE240
	map_script_2 VAR_0x4039, 1, gUnknown_08273D1F
	.2byte 0

Route105_EventScript_1EE24A:: @ 81EE24A
	trainerbattle 0, TRAINER_FOSTER, 0, Route105_Text_295D0F, Route105_Text_295D62
	msgbox Route105_Text_295DAB, 6
	end

Route105_EventScript_1EE261:: @ 81EE261
	trainerbattle 0, TRAINER_LUIS, 0, Route105_Text_295DF5, Route105_Text_295E66
	msgbox Route105_Text_295E72, 6
	end

Route105_EventScript_1EE278:: @ 81EE278
	trainerbattle 0, TRAINER_DOMINIK, 0, Route105_Text_295EB7, Route105_Text_295EEA
	msgbox Route105_Text_295F08, 6
	end

Route105_EventScript_1EE28F:: @ 81EE28F
	trainerbattle 0, TRAINER_BEVERLY, 0, Route105_Text_295F5C, Route105_Text_295FA0
	msgbox Route105_Text_295FAE, 6
	end

Route105_EventScript_1EE2A6:: @ 81EE2A6
	trainerbattle 0, TRAINER_IMANI, 0, Route105_Text_296025, Route105_Text_296059
	msgbox Route105_Text_296076, 6
	end

Route105_EventScript_1EE2BD:: @ 81EE2BD
	trainerbattle 0, TRAINER_JOSUE, 0, Route105_Text_29626F, Route105_Text_2962CB
	msgbox Route105_Text_2962EC, 6
	end

Route105_EventScript_1EE2D4:: @ 81EE2D4
	trainerbattle 2, TRAINER_ANDRES_1, 0, Route105_Text_2960A9, Route105_Text_2960DB, Route105_EventScript_1EE300
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route105_EventScript_1EE31F
	msgbox Route105_Text_2960FA, 4
	release
	end

Route105_EventScript_1EE300:: @ 81EE300
	special sub_80B4808
	waitmovement 0
	msgbox Route105_Text_296159, 4
	setvar VAR_0x8004, 737
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 737
	callstd 8
	release
	end

Route105_EventScript_1EE31F:: @ 81EE31F
	trainerbattle 5, TRAINER_ANDRES_1, 0, Route105_Text_29619E, Route105_Text_2961DD
	msgbox Route105_Text_2961FE, 6
	end

Route104_Text_1EE336: @ 81EE336
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "DAD: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from DEVON’s MR. STONE\n"
	.string "about your POKéNAV, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you’re doing fine,\n"
	.string "so that’s fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route104_Text_1EE463: @ 81EE463
	.string "Registered DAD NORMAN\n"
	.string "in the POKéNAV.$"

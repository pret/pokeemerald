Route127_MapScripts:: @ 81F69D9
	map_script 3, Route127_MapScript1_1F69E9
	map_script 1, Route127_MapScript1_1F6A14
	map_script 2, Route127_MapScript2_1F6A2B
	.byte 0

Route127_MapScript1_1F69E9: @ 81F69E9
	checkflag FLAG_SYS_WEATHER_CTRL
	call_if 1, Route127_EventScript_27207A
	compare_var_to_value VAR_0x4039, 1
	call_if 1, Route127_EventScript_273D13
	compare_var_to_value VAR_0x4037, 13
	call_if 1, Route127_EventScript_273D17
	compare_var_to_value VAR_0x4037, 14
	call_if 1, Route127_EventScript_273D17
	end

Route127_MapScript1_1F6A14: @ 81F6A14
	compare_var_to_value VAR_0x4037, 13
	call_if 1, Route127_EventScript_273B5F
	compare_var_to_value VAR_0x4037, 14
	call_if 1, Route127_EventScript_273BCC
	end

Route127_MapScript2_1F6A2B: @ 81F6A2B
	map_script_2 VAR_0x4039, 1, gUnknown_08273D1F
	.2byte 0

Route127_EventScript_1F6A35:: @ 81F6A35
	trainerbattle 0, TRAINER_CAMDEN, 0, Route127_Text_2A225F, Route127_Text_2A2294
	msgbox Route127_Text_2A22A1, 6
	end

Route127_EventScript_1F6A4C:: @ 81F6A4C
	trainerbattle 0, TRAINER_DONNY, 0, Route127_Text_2A22DD, Route127_Text_2A2315
	msgbox Route127_Text_2A232C, 6
	end

Route127_EventScript_1F6A63:: @ 81F6A63
	trainerbattle 0, TRAINER_JONAH, 0, Route127_Text_2A2381, Route127_Text_2A23E1
	msgbox Route127_Text_2A240C, 6
	end

Route127_EventScript_1F6A7A:: @ 81F6A7A
	trainerbattle 0, TRAINER_HENRY, 0, Route127_Text_2A2450, Route127_Text_2A2483
	msgbox Route127_Text_2A2494, 6
	end

Route127_EventScript_1F6A91:: @ 81F6A91
	trainerbattle 0, TRAINER_ROGER, 0, Route127_Text_2A24C6, Route127_Text_2A250B
	msgbox Route127_Text_2A2538, 6
	end

Route127_EventScript_1F6AA8:: @ 81F6AA8
	trainerbattle 0, TRAINER_AIDAN, 0, Route127_Text_2A257A, Route127_Text_2A25C1
	msgbox Route127_Text_2A25D2, 6
	end

Route127_EventScript_1F6ABF:: @ 81F6ABF
	trainerbattle 0, TRAINER_ATHENA, 0, Route127_Text_2A27D0, Route127_Text_2A27FC
	msgbox Route127_Text_2A2832, 6
	end

Route127_EventScript_1F6AD6:: @ 81F6AD6
	trainerbattle 2, TRAINER_KOJI_1, 0, Route127_Text_2A264D, Route127_Text_2A2685, Route127_EventScript_1F6B02
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route127_EventScript_1F6B21
	msgbox Route127_Text_2A26AC, 4
	release
	end

Route127_EventScript_1F6B02:: @ 81F6B02
	special sub_80B4808
	waitmovement 0
	msgbox Route127_Text_2A26EE, 4
	setvar VAR_0x8004, 672
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 672
	callstd 8
	release
	end

Route127_EventScript_1F6B21:: @ 81F6B21
	trainerbattle 5, TRAINER_KOJI_1, 0, Route127_Text_2A2734, Route127_Text_2A276B
	msgbox Route127_Text_2A278E, 6
	end


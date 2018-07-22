Route131_MapScripts:: @ 81F7404
	map_script 3, Route131_MapScript1_1F740A
	.byte 0

Route131_MapScript1_1F740A: @ 81F740A
	compare VAR_0x405E, 4
	call_if 4, Route131_EventScript_1F741F
	call Route131_EventScript_1F741B
	end

Route131_EventScript_1F741B:: @ 81F741B
	setmaplayoutindex 319
	return

Route131_EventScript_1F741F:: @ 81F741F
	checkflag FLAG_SYS_WEATHER_CTRL
	call_if 1, Route131_EventScript_27207A
	return

Route131_EventScript_1F7429:: @ 81F7429
	trainerbattle 0, TRAINER_RICHARD, 0, Route131_Text_2A34C8, Route131_Text_2A350D
	msgbox Route131_Text_2A353D, 6
	end

Route131_EventScript_1F7440:: @ 81F7440
	trainerbattle 0, TRAINER_HERMAN, 0, Route131_Text_2A35C6, Route131_Text_2A3626
	msgbox Route131_Text_2A362D, 6
	end

Route131_EventScript_1F7457:: @ 81F7457
	trainerbattle 0, TRAINER_SUSIE, 0, Route131_Text_2A367B, Route131_Text_2A36AB
	msgbox Route131_Text_2A36D6, 6
	end

Route131_EventScript_1F746E:: @ 81F746E
	trainerbattle 0, TRAINER_KARA, 0, Route131_Text_2A3751, Route131_Text_2A378A
	msgbox Route131_Text_2A379F, 6
	end

Route131_EventScript_1F7485:: @ 81F7485
	trainerbattle 4, TRAINER_RELI_AND_IAN, 0, Route131_Text_2A37E9, Route131_Text_2A381F, Route131_Text_2A38B7
	msgbox Route131_Text_2A3855, 6
	end

Route131_EventScript_1F74A0:: @ 81F74A0
	trainerbattle 4, TRAINER_RELI_AND_IAN, 0, Route131_Text_2A38F8, Route131_Text_2A3925, Route131_Text_2A39CD
	msgbox Route131_Text_2A3960, 6
	end

Route131_EventScript_1F74BB:: @ 81F74BB
	trainerbattle 0, TRAINER_TALIA, 0, Route131_Text_2A39FE, Route131_Text_2A3A38
	msgbox Route131_Text_2A3A48, 6
	end

Route131_EventScript_1F74D2:: @ 81F74D2
	trainerbattle 0, TRAINER_KEVIN, 0, Route131_Text_2A3AA0, Route131_Text_2A3AFC
	msgbox Route131_Text_2A3B02, 6
	end


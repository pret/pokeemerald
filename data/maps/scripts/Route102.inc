Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_1EC0E1:: @ 81EC0E1
	msgbox Route102_Text_1EC2C0, 2
	end

Route102_EventScript_1EC0EA:: @ 81EC0EA
	msgbox Route102_Text_1EC35B, 3
	end

Route102_EventScript_1EC0F3:: @ 81EC0F3
	msgbox Route102_Text_1EC373, 3
	end

Route102_EventScript_1EC0FC:: @ 81EC0FC
	msgbox Route102_Text_1EC32E, 2
	end

Route102_EventScript_1EC105:: @ 81EC105
	trainerbattle 2, TRAINER_CALVIN_1, 0, Route102_Text_294513, Route102_Text_29457C, Route102_EventScript_1EC146
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route102_EventScript_1EC19C
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, sub_813B4E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route102_EventScript_1EC170
	msgbox Route102_Text_2945AC, 4
	release
	end

Route102_EventScript_1EC146:: @ 81EC146
	special sub_80B4808
	waitmovement 0
	checkflag FLAG_0x12F
	goto_eq Route102_EventScript_1EC157
	release
	end

Route102_EventScript_1EC157:: @ 81EC157
	msgbox Route102_Text_294668, 4
	setvar VAR_0x8004, 318
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 318
	callstd 8
	release
	end

Route102_EventScript_1EC170:: @ 81EC170
	checkflag FLAG_0x12F
	goto_eq Route102_EventScript_1EC183
	msgbox Route102_Text_2945AC, 4
	release
	end

Route102_EventScript_1EC183:: @ 81EC183
	msgbox Route102_Text_2945EB, 4
	setvar VAR_0x8004, 318
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 318
	callstd 8
	release
	end

Route102_EventScript_1EC19C:: @ 81EC19C
	trainerbattle 5, TRAINER_CALVIN_1, 0, Route102_Text_2946AE, Route102_Text_29470C
	msgbox Route102_Text_29473C, 6
	end

Route102_EventScript_1EC1B3:: @ 81EC1B3
	trainerbattle 0, TRAINER_RICK, 0, Route102_Text_29480C, Route102_Text_294847
	msgbox Route102_Text_294859, 6
	end

Route102_EventScript_1EC1CA:: @ 81EC1CA
	trainerbattle 0, TRAINER_TIANA, 0, Route102_Text_29489E, Route102_Text_2948F3
	msgbox Route102_Text_294916, 6
	end

Route102_EventScript_1EC1E1:: @ 81EC1E1
	trainerbattle 0, TRAINER_ALLEN, 0, Route102_Text_294775, Route102_Text_2947AA
	msgbox Route102_Text_2947DB, 6
	end


Route131_MapScripts:: @ 81F7404
	map_script MAP_SCRIPT_ON_TRANSITION, Route131_OnTransition
	.byte 0

Route131_OnTransition: @ 81F740A
	compare VAR_RAYQUAZA_STATE, 4
	call_if_ge Route131_EventScript_1F741F
	call Route131_EventScript_1F741B
	end

Route131_EventScript_1F741B:: @ 81F741B
	setmaplayoutindex LAYOUT_ROUTE131_SKY_PILLAR
	return

Route131_EventScript_1F741F:: @ 81F741F
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	return

Route131_EventScript_1F7429:: @ 81F7429
	trainerbattle_single TRAINER_RICHARD, Route131_Text_2A34C8, Route131_Text_2A350D
	msgbox Route131_Text_2A353D, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F7440:: @ 81F7440
	trainerbattle_single TRAINER_HERMAN, Route131_Text_2A35C6, Route131_Text_2A3626
	msgbox Route131_Text_2A362D, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F7457:: @ 81F7457
	trainerbattle_single TRAINER_SUSIE, Route131_Text_2A367B, Route131_Text_2A36AB
	msgbox Route131_Text_2A36D6, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F746E:: @ 81F746E
	trainerbattle_single TRAINER_KARA, Route131_Text_2A3751, Route131_Text_2A378A
	msgbox Route131_Text_2A379F, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F7485:: @ 81F7485
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_2A37E9, Route131_Text_2A381F, Route131_Text_2A38B7
	msgbox Route131_Text_2A3855, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F74A0:: @ 81F74A0
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_2A38F8, Route131_Text_2A3925, Route131_Text_2A39CD
	msgbox Route131_Text_2A3960, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F74BB:: @ 81F74BB
	trainerbattle_single TRAINER_TALIA, Route131_Text_2A39FE, Route131_Text_2A3A38
	msgbox Route131_Text_2A3A48, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_1F74D2:: @ 81F74D2
	trainerbattle_single TRAINER_KEVIN, Route131_Text_2A3AA0, Route131_Text_2A3AFC
	msgbox Route131_Text_2A3B02, MSGBOX_AUTOCLOSE
	end


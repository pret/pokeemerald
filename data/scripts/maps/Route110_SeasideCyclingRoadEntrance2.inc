Route110_SeasideCyclingRoadEntrance2_MapScripts:: @ 826EBA1
	map_script 3, Route110_SeasideCyclingRoadEntrance2_MapScript1_26EBA7
	.byte 0

Route110_SeasideCyclingRoadEntrance2_MapScript1_26EBA7: @ 826EBA7
	compare_var_to_value VAR_0x40A9, 3
	call_if 1, Route110_SeasideCyclingRoadEntrance2_EventScript_26EBBE
	compare_var_to_value VAR_0x40A9, 2
	call_if 1, Route110_SeasideCyclingRoadEntrance2_EventScript_26EBBE
	end

Route110_SeasideCyclingRoadEntrance2_EventScript_26EBBE:: @ 826EBBE
	setvar VAR_0x40A9, 1
	return

Route110_SeasideCyclingRoadEntrance2_EventScript_26EBC4:: @ 826EBC4
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadEntrance2_Text_26EC23, 4
	release
	end

Route110_SeasideCyclingRoadEntrance2_EventScript_26EBD0:: @ 826EBD0
	lockall
	specialvar VAR_RESULT, sp0E3_walkrun_bitfield_interpretation
	compare_var_to_value VAR_RESULT, 2
	call_if 1, Route110_SeasideCyclingRoadEntrance2_EventScript_26EBF6
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route110_SeasideCyclingRoadEntrance2_EventScript_26EBFC
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_0x4001, 1
	releaseall
	end

Route110_SeasideCyclingRoadEntrance2_EventScript_26EBF6:: @ 826EBF6
	setvar VAR_0x40A9, 1
	return

Route110_SeasideCyclingRoadEntrance2_EventScript_26EBFC:: @ 826EBFC
	msgbox Route110_SeasideCyclingRoadEntrance2_Text_26ECAA, 4
	closemessage
	applymovement 255, Route110_SeasideCyclingRoadEntrance2_Movement_26EC11
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadEntrance2_Movement_26EC11: @ 826EC11
	step_left
	step_end

Route110_SeasideCyclingRoadEntrance2_EventScript_26EC13:: @ 826EC13
	lockall
	setvar VAR_0x40A9, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_0x4001, 0
	releaseall
	end

Route110_SeasideCyclingRoadEntrance2_Text_26EC23: @ 826EC23
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you’d like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadEntrance2_Text_26ECAA: @ 826ECAA
	.string "Sorry, you can’t walk on CYCLING\n"
	.string "ROAD. It’s too dangerous.\p"
	.string "Please come back with a BIKE.$"


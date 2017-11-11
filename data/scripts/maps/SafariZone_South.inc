SafariZone_South_MapScripts:: @ 823D279
	map_script 3, SafariZone_South_MapScript1_23D2B1
	map_script 2, SafariZone_South_MapScript2_23D284
	.byte 0

SafariZone_South_MapScript2_23D284: @ 823D284
	map_script_2 VAR_0x40A4, 2, SafariZone_South_EventScript_23D28E
	.2byte 0

SafariZone_South_EventScript_23D28E:: @ 823D28E
	lockall
	applymovement 255, SafariZone_South_Movement_23D2C5
	waitmovement 0
	applymovement 1, SafariZone_South_Movement_23D2C7
	waitmovement 0
	setobjectxyperm 1, 32, 34
	setvar VAR_0x40A4, 0
	releaseall
	end

SafariZone_South_MapScript1_23D2B1: @ 823D2B1
	compare_var_to_value VAR_0x40A4, 2
	call_if 1, SafariZone_South_EventScript_23D2BD
	end

SafariZone_South_EventScript_23D2BD:: @ 823D2BD
	setobjectxyperm 1, 31, 34
	return

SafariZone_South_Movement_23D2C5: @ 823D2C5
	step_down
	step_end

SafariZone_South_Movement_23D2C7: @ 823D2C7
	step_right
	step_25
	step_end

SafariZone_South_EventScript_23D2CA:: @ 823D2CA
	msgbox SafariZone_South_Text_2A52EF, 2
	end

SafariZone_South_EventScript_23D2D3:: @ 823D2D3
	msgbox SafariZone_South_Text_2A533B, 2
	end

SafariZone_South_EventScript_23D2DC:: @ 823D2DC
	msgbox SafariZone_South_Text_2A553E, 2
	end

SafariZone_South_EventScript_23D2E5:: @ 823D2E5
	lock
	faceplayer
	checkflag FLAG_0x05D
	goto_if 0, SafariZone_South_EventScript_23D30D
	msgbox SafariZone_South_Text_2A51D4, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SafariZone_South_EventScript_23D31A
	msgbox SafariZone_South_Text_2A521A, 4
	release
	end

SafariZone_South_EventScript_23D30D:: @ 823D30D
	setflag FLAG_0x05D
	msgbox SafariZone_South_Text_2A52AB, 4
	release
	end

SafariZone_South_EventScript_23D31A:: @ 823D31A
	msgbox SafariZone_South_Text_2A5248, 4
	closemessage
	switch VAR_FACING
	case 2, SafariZone_South_EventScript_23D33F
	case 4, SafariZone_South_EventScript_23D359
	end

SafariZone_South_EventScript_23D33F:: @ 823D33F
	applymovement 1, SafariZone_South_Movement_23D38A
	waitmovement 0
	applymovement 255, SafariZone_South_Movement_23D385
	waitmovement 0
	goto SafariZone_South_EventScript_23D373
	end

SafariZone_South_EventScript_23D359:: @ 823D359
	applymovement 1, SafariZone_South_Movement_23D38D
	waitmovement 0
	applymovement 255, SafariZone_South_Movement_23D387
	waitmovement 0
	goto SafariZone_South_EventScript_23D373
	end

SafariZone_South_EventScript_23D373:: @ 823D373
	setvar VAR_0x40A4, 1
	special ExitSafariMode
	warpdoor ROUTE_121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

SafariZone_South_Movement_23D385: @ 823D385
	step_up
	step_end

SafariZone_South_Movement_23D387: @ 823D387
	step_right
	step_26
	step_end

SafariZone_South_Movement_23D38A: @ 823D38A
	step_left
	step_28
	step_end

SafariZone_South_Movement_23D38D: @ 823D38D
	step_down
	step_26
	step_end

SafariZone_South_EventScript_23D390:: @ 823D390
	msgbox SafariZone_South_Text_2A57EE, 2
	end

SafariZone_Southeast_EventScript_23D399:: @ 823D399
	msgbox SafariZone_Southeast_Text_2A582D, 2
	end

SafariZone_South_EventScript_23D3A2:: @ 823D3A2
	msgbox SafariZone_South_Text_2A5887, 2
	end

SafariZone_Southeast_EventScript_23D3AB:: @ 823D3AB
	msgbox SafariZone_Southeast_Text_2A58C6, 2
	end

SafariZone_Southeast_EventScript_23D3B4:: @ 823D3B4
	msgbox SafariZone_Southeast_Text_2A58FD, 2
	end

SafariZone_Southeast_EventScript_23D3BD:: @ 823D3BD
	msgbox SafariZone_Southeast_Text_2A5960, 2
	end

SafariZone_Northeast_EventScript_23D3C6:: @ 823D3C6
	msgbox SafariZone_Northeast_Text_2A59A4, 2
	end

SafariZone_Northeast_EventScript_23D3CF:: @ 823D3CF
	msgbox SafariZone_Northeast_Text_2A5A09, 2
	end

SafariZone_Northeast_EventScript_23D3D8:: @ 823D3D8
	msgbox SafariZone_Northeast_Text_2A5A44, 2
	end


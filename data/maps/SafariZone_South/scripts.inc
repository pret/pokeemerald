SafariZone_South_MapScripts:: @ 823D279
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_MapScript2_23D284
	.byte 0

SafariZone_South_MapScript2_23D284: @ 823D284
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_23D28E
	.2byte 0

SafariZone_South_EventScript_23D28E:: @ 823D28E
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, SafariZone_South_Movement_23D2C5
	waitmovement 0
	applymovement 1, SafariZone_South_Movement_23D2C7
	waitmovement 0
	setobjectxyperm 1, 32, 34
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

SafariZone_South_OnTransition: @ 823D2B1
	compare VAR_SAFARI_ZONE_STATE, 2
	call_if_eq SafariZone_South_EventScript_23D2BD
	end

SafariZone_South_EventScript_23D2BD:: @ 823D2BD
	setobjectxyperm 1, 31, 34
	return

SafariZone_South_Movement_23D2C5: @ 823D2C5
	walk_down
	step_end

SafariZone_South_Movement_23D2C7: @ 823D2C7
	walk_right
	walk_in_place_fastest_down
	step_end

SafariZone_South_EventScript_23D2CA:: @ 823D2CA
	msgbox SafariZone_South_Text_2A52EF, MSGBOX_NPC
	end

SafariZone_South_EventScript_23D2D3:: @ 823D2D3
	msgbox SafariZone_South_Text_2A533B, MSGBOX_NPC
	end

SafariZone_South_EventScript_23D2DC:: @ 823D2DC
	msgbox SafariZone_South_Text_2A553E, MSGBOX_NPC
	end

SafariZone_South_EventScript_23D2E5:: @ 823D2E5
	lock
	faceplayer
	goto_if_unset FLAG_GOOD_LUCK_SAFARI_ZONE, SafariZone_South_EventScript_23D30D
	msgbox SafariZone_South_Text_2A51D4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SafariZone_South_EventScript_23D31A
	msgbox SafariZone_South_Text_2A521A, MSGBOX_DEFAULT
	release
	end

SafariZone_South_EventScript_23D30D:: @ 823D30D
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_2A52AB, MSGBOX_DEFAULT
	release
	end

SafariZone_South_EventScript_23D31A:: @ 823D31A
	msgbox SafariZone_South_Text_2A5248, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case 2, SafariZone_South_EventScript_23D33F
	case 4, SafariZone_South_EventScript_23D359
	end

SafariZone_South_EventScript_23D33F:: @ 823D33F
	applymovement 1, SafariZone_South_Movement_23D38A
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, SafariZone_South_Movement_23D385
	waitmovement 0
	goto SafariZone_South_EventScript_23D373
	end

SafariZone_South_EventScript_23D359:: @ 823D359
	applymovement 1, SafariZone_South_Movement_23D38D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, SafariZone_South_Movement_23D387
	waitmovement 0
	goto SafariZone_South_EventScript_23D373
	end

SafariZone_South_EventScript_23D373:: @ 823D373
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warpdoor MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

SafariZone_South_Movement_23D385: @ 823D385
	walk_up
	step_end

SafariZone_South_Movement_23D387: @ 823D387
	walk_right
	walk_in_place_fastest_up
	step_end

SafariZone_South_Movement_23D38A: @ 823D38A
	walk_left
	walk_in_place_fastest_right
	step_end

SafariZone_South_Movement_23D38D: @ 823D38D
	walk_down
	walk_in_place_fastest_up
	step_end

SafariZone_South_EventScript_23D390:: @ 823D390
	msgbox SafariZone_South_Text_2A57EE, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_23D399:: @ 823D399
	msgbox SafariZone_Southeast_Text_2A582D, MSGBOX_NPC
	end

SafariZone_South_EventScript_23D3A2:: @ 823D3A2
	msgbox SafariZone_South_Text_2A5887, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_23D3AB:: @ 823D3AB
	msgbox SafariZone_Southeast_Text_2A58C6, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_23D3B4:: @ 823D3B4
	msgbox SafariZone_Southeast_Text_2A58FD, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_23D3BD:: @ 823D3BD
	msgbox SafariZone_Southeast_Text_2A5960, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_23D3C6:: @ 823D3C6
	msgbox SafariZone_Northeast_Text_2A59A4, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_23D3CF:: @ 823D3CF
	msgbox SafariZone_Northeast_Text_2A5A09, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_23D3D8:: @ 823D3D8
	msgbox SafariZone_Northeast_Text_2A5A44, MSGBOX_NPC
	end

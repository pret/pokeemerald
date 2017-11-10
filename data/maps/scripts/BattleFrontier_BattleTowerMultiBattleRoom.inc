BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8243D92
	map_script 5, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7
	map_script 3, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0
	map_script 4, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14
	map_script 2, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7: @ 8243DA7
	setvar VAR_0x8004, 17
	special sub_81A8E7C
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0: @ 8243DB0
	checkflag FLAG_0x152
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA
	clearflag FLAG_0x2C7
	clearflag FLAG_0x2C8
	clearflag FLAG_0x2C9
	clearflag FLAG_0x2CA
	clearflag FLAG_0x2CB
	clearflag FLAG_0x2CC
	setflag FLAG_0x360
	setflag FLAG_0x361
	setvar VAR_0x8004, 10
	special sub_8161F74
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA:: @ 8243DDA
	setvar VAR_0x4010, 7
	setvar VAR_0x4011, 7
	setvar VAR_0x4012, 7
	setvar VAR_0x4013, 7
	setvar VAR_0x4014, 7
	setvar VAR_0x4015, 7
	setvar VAR_0x4016, 7
	setvar VAR_0x4017, 7
	setvar VAR_0x4001, 1
	setvar VAR_0x4003, 1
	setobjectxyperm 1, 10, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14: @ 8243E14
	map_script_2 VAR_0x4003, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E:: @ 8243E1E
	turnobject 255, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23: @ 8243E23
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41
	map_script_2 VAR_0x4003, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35:: @ 8243E35
	lockall
	setvar VAR_0x4003, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41:: @ 8243E41
	lockall
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77
	waitmovement 0
	moveobjectoffscreen 1
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_2725A6
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244056, 4
	special sp000_heal_pokemon
	setvar VAR_0x4001, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75: @ 8243E75
	step_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77: @ 8243E77
	step_left
	step_25
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E7A:: @ 8243E7A
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_244094
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C, 4
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D:: @ 8243E9D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_81A1780
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5:: @ 8243EB5
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244149, 4
	closemessage
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_2725A6
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4
	closedoor 10, 1
	waitdooranim
	warp BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4:: @ 8243EE4
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A
	waitmovement 0
	return

	.incbin "baserom.gba", 0x243ef6, 0x24

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A: @ 8243F1A
	step_up
	step_up
	step_54
	step_end

	.incbin "baserom.gba", 0x243f1e, 0x8

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26: @ 8243F26
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F29:: @ 8243F29
	lock
	faceplayer
	setvar VAR_0x4002, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36:: @ 8243F36
	checkflag FLAG_0x152
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 0
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 1
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 2
	special sub_8161F74
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	case 127, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 3
	special sub_8161F74
	waitmessage
	waitbuttonpress
	closemessage
	compare_var_to_value VAR_FACING, 1
	call_if 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4
	compare_var_to_value VAR_FACING, 1
	call_if 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF
	removeobject VAR_LAST_TALKED
	setflag FLAG_0x152
	warpsilent BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3:: @ 8243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 4
	special sub_8161F74
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4:: @ 8243FD4
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF:: @ 8243FDF
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA: @ 8243FEA
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2: @ 8243FF2
	step_17
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FFB:: @ 8243FFB
	lock
	faceplayer
	setvar VAR_0x4002, 1
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244008:: @ 8244008
	lock
	faceplayer
	setvar VAR_0x4002, 2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244015:: @ 8244015
	lock
	faceplayer
	setvar VAR_0x4002, 3
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244022:: @ 8244022
	lock
	faceplayer
	setvar VAR_0x4002, 4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24402F:: @ 824402F
	lock
	faceplayer
	setvar VAR_0x4002, 5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24403C:: @ 824403C
	lock
	faceplayer
	setvar VAR_0x4002, 6
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244049:: @ 8244049
	lock
	faceplayer
	setvar VAR_0x4002, 7
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_Text_244056: @ 8244056
	.string "Please find a partner from out of\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244094: @ 8244094
	.string "{PLAYER}, you have not found a partner\n"
	.string "for your tag team.\p"
	.string "Would you like to quit looking and\n"
	.string "return to the reception counter?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C: @ 824410C
	.string "Then, please find a partner from\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244149: @ 8244149
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "MULTI BATTLE ROOM.$"

	.incbin "baserom.gba", 0x24419a, 0x4bb0


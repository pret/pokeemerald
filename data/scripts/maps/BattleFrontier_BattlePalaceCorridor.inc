BattleFrontier_BattlePalaceCorridor_MapScripts:: @ 824F4A3
	map_script 2, BattleFrontier_BattlePalaceCorridor_MapScript2_24F4A9
	.byte 0

BattleFrontier_BattlePalaceCorridor_MapScript2_24F4A9: @ 824F4A9
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattlePalaceCorridor_EventScript_24F4B3
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_24F4B3:: @ 824F4B3
	delay 16
	applymovement 1, BattleFrontier_BattlePalaceCorridor_Movement_24F5B8
	applymovement 255, BattleFrontier_BattlePalaceCorridor_Movement_24F5B8
	waitmovement 0
	lockall
	setvar VAR_0x8004, 3
	special sub_8195960
	compare VAR_RESULT, 0
	call_if 1, BattleFrontier_BattlePalaceCorridor_EventScript_24F58B
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePalaceCorridor_EventScript_24F594
	compare VAR_RESULT, 2
	call_if 1, BattleFrontier_BattlePalaceCorridor_EventScript_24F59D
	compare VAR_RESULT, 3
	call_if 1, BattleFrontier_BattlePalaceCorridor_EventScript_24F5A6
	compare VAR_RESULT, 4
	call_if 1, BattleFrontier_BattlePalaceCorridor_EventScript_24F5AF
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_81A1780
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceCorridor_EventScript_24F553
	applymovement 1, BattleFrontier_BattlePalaceCorridor_Movement_24F5BD
	applymovement 255, BattleFrontier_BattlePalaceCorridor_Movement_24F5C4
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement 1, BattleFrontier_BattlePalaceCorridor_Movement_24F5DA
	applymovement 255, BattleFrontier_BattlePalaceCorridor_Movement_24F5D9
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_24F581

BattleFrontier_BattlePalaceCorridor_EventScript_24F553:: @ 824F553
	applymovement 1, BattleFrontier_BattlePalaceCorridor_Movement_24F5CB
	applymovement 255, BattleFrontier_BattlePalaceCorridor_Movement_24F5D2
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement 1, BattleFrontier_BattlePalaceCorridor_Movement_24F5DA
	applymovement 255, BattleFrontier_BattlePalaceCorridor_Movement_24F5D9
	waitmovement 0
	closedoor 10, 3
	waitdooranim

BattleFrontier_BattlePalaceCorridor_EventScript_24F581:: @ 824F581
	warp BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 255, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_24F58B:: @ 824F58B
	msgbox BattleFrontier_BattlePalaceCorridor_Text_24F5DD, 4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_24F594:: @ 824F594
	msgbox BattleFrontier_BattlePalaceCorridor_Text_24F65B, 4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_24F59D:: @ 824F59D
	msgbox BattleFrontier_BattlePalaceCorridor_Text_24F718, 4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_24F5A6:: @ 824F5A6
	msgbox BattleFrontier_BattlePalaceCorridor_Text_24F78C, 4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_24F5AF:: @ 824F5AF
	msgbox BattleFrontier_BattlePalaceCorridor_Text_24F7D4, 4
	return

BattleFrontier_BattlePalaceCorridor_Movement_24F5B8: @ 824F5B8
	step_up
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_24F5BD: @ 824F5BD
	step_up
	step_up
	step_left
	step_left
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_24F5C4: @ 824F5C4
	step_up
	step_up
	step_up
	step_left
	step_left
	step_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_24F5CB: @ 824F5CB
	step_up
	step_right
	step_right
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_24F5D2: @ 824F5D2
	step_up
	step_up
	step_right
	step_right
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_24F5D9: @ 824F5D9
	step_up

BattleFrontier_BattlePalaceCorridor_Movement_24F5DA: @ 824F5DA
	step_up
	step_54
	step_end

BattleFrontier_BattlePalaceCorridor_Text_24F5DD: @ 824F5DD
	.string "People and POKéMON, they are but\n"
	.string "the same…\p"
	.string "Their individual nature makes them\n"
	.string "good at certain things, and not good\l"
	.string "at others.$"

BattleFrontier_BattlePalaceCorridor_Text_24F65B: @ 824F65B
	.string "Rather than trying to make a POKéMON\n"
	.string "do what it dislikes, try to let it do\l"
	.string "what it likes and is good at doing.\p"
	.string "Put yourself in the POKéMON’s position\n"
	.string "and consider what moves it would like.$"

BattleFrontier_BattlePalaceCorridor_Text_24F718: @ 824F718
	.string "A POKéMON’s nature is a remarkable\n"
	.string "thing…\p"
	.string "Some POKéMON behave in a completely\n"
	.string "different way when they are cornered.$"

BattleFrontier_BattlePalaceCorridor_Text_24F78C: @ 824F78C
	.string "Are you beginning to understand how\n"
	.string "a POKéMON’s nature makes it behave?$"

BattleFrontier_BattlePalaceCorridor_Text_24F7D4: @ 824F7D4
	.string "Ah… I see a strong, heartfelt bond\n"
	.string "between you and your POKéMON…$"


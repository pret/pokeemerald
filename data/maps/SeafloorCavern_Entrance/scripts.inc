SeafloorCavern_Entrance_MapScripts:: @ 823446E
	map_script 5, SeafloorCavern_Entrance_MapScript1_234474
	.byte 0

SeafloorCavern_Entrance_MapScript1_234474: @ 8234474
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	end

SeafloorCavern_Entrance_EventScript_234485:: @ 8234485
	lockall
	compare VAR_0x40D9, 1
	goto_if_eq SeafloorCavern_Entrance_EventScript_2344ED
	waitse
	playse SE_PIN
	applymovement 1, SeafloorCavern_Entrance_Movement_272598
	waitmovement 0
	applymovement 1, SeafloorCavern_Entrance_Movement_27259A
	waitmovement 0
	delay 20
	compare VAR_FACING, 3
	call_if_eq SeafloorCavern_Entrance_EventScript_23452E
	compare VAR_FACING, 4
	call_if_eq SeafloorCavern_Entrance_EventScript_234523
	compare VAR_FACING, 2
	call_if_eq SeafloorCavern_Entrance_EventScript_234539
	delay 30
	setvar VAR_0x40D9, 1
	moveobjectoffscreen 1
	msgbox SeafloorCavern_Entrance_Text_234544, MSGBOX_DEFAULT
	closemessage
	applymovement 1, SeafloorCavern_Entrance_Movement_2725A6
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_2344ED:: @ 82344ED
	compare VAR_FACING, 3
	call_if_eq SeafloorCavern_Entrance_EventScript_23452E
	compare VAR_FACING, 4
	call_if_eq SeafloorCavern_Entrance_EventScript_234523
	compare VAR_FACING, 2
	call_if_eq SeafloorCavern_Entrance_EventScript_234539
	msgbox SeafloorCavern_Entrance_Text_2346C8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, SeafloorCavern_Entrance_Movement_2725A6
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_234523:: @ 8234523
	applymovement 1, SeafloorCavern_Entrance_Movement_2725A4
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_23452E:: @ 823452E
	applymovement 1, SeafloorCavern_Entrance_Movement_2725A8
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_234539:: @ 8234539
	applymovement 1, SeafloorCavern_Entrance_Movement_2725AA
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_234544: @ 8234544
	.string "Hey!\n"
	.string "I remember your face!\p"
	.string "If you're here, it must mean that\n"
	.string "you're about to mess with us again!\p"
	.string "A punk like you, do you really think\n"
	.string "you can take on TEAM AQUA?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "TEAM MAGMA!\p"
	.string "Speaking of TEAM MAGMA, I hear they\n"
	.string "were spotted near MOSSDEEP.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"

SeafloorCavern_Entrance_Text_2346C8: @ 82346C8
	.string "A punk like you, do you really think\n"
	.string "you can take on TEAM AQUA?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "TEAM MAGMA!\p"
	.string "Speaking of TEAM MAGMA, I hear they\n"
	.string "were spotted near MOSSDEEP.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"


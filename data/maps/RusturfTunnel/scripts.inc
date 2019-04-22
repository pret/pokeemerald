RusturfTunnel_MapScripts:: @ 822CE27
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_MapScript2_22CE32
	.byte 0

RusturfTunnel_MapScript2_22CE32: @ 822CE32
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_22CEAE
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_22CEAE
	.2byte 0

RusturfTunnel_OnTransition: @ 822CE44
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	call_if_eq RusturfTunnel_EventScript_22CE50
	end

RusturfTunnel_EventScript_22CE50:: @ 822CE50
	setobjectxyperm 7, 13, 4
	setobjectxyperm 6, 13, 5
	return

RusturfTunnel_EventScript_22CE5F:: @ 822CE5F
	lock
	faceplayer
	msgbox RusturfTunnel_Text_22D7A3, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_22CE76:: @ 822CE76
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_22CE99
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_22D510, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_22CE99:: @ 822CE99
	msgbox RusturfTunnel_Text_22D5F3, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_22CEAE:: @ 822CEAE
	lockall
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_22CFA7
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_22CFBC
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_22CFC7
	call RusturfTunnel_EventScript_22CFFF
	msgbox RusturfTunnel_Text_22D65C, MSGBOX_DEFAULT
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_22CFC8
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_22CFC8
	giveitem_std ITEM_HM04
	setflag FLAG_RECEIVED_HM04
	msgbox RusturfTunnel_Text_22D6D2, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_22CF5D
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_22CF6F
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_22CF8B
	msgbox RusturfTunnel_Text_22D745, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_22CFD4
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_22CFE6
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_22CFE6
	call RusturfTunnel_EventScript_272216
	releaseall
	end

RusturfTunnel_EventScript_22CF5D:: @ 822CF5D
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D042
	applymovement 1, RusturfTunnel_Movement_22D067
	waitmovement 0
	return

RusturfTunnel_EventScript_22CF6F:: @ 822CF6F
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D045
	applymovement 1, RusturfTunnel_Movement_22D06C
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RusturfTunnel_EventScript_22CF8B:: @ 822CF8B
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D045
	applymovement 1, RusturfTunnel_Movement_22D06C
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFA7:: @ 822CFA7
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFBC:: @ 822CFBC
	applymovement 1, RusturfTunnel_Movement_22D048
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFC7:: @ 822CFC7
	return

RusturfTunnel_EventScript_22CFC8:: @ 822CFC8
	closemessage
	applymovement 1, RusturfTunnel_Movement_22D065
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFD4:: @ 822CFD4
	applymovement 10, RusturfTunnel_Movement_22D017
	applymovement 1, RusturfTunnel_Movement_22D04B
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFE6:: @ 822CFE6
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D02F
	applymovement 10, RusturfTunnel_Movement_22D023
	applymovement 1, RusturfTunnel_Movement_22D058
	waitmovement 0
	return

RusturfTunnel_EventScript_22CFFF:: @ 822CFFF
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_22D017: @ 822D017
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_22D023: @ 822D023
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_22D02F: @ 822D02F
	delay_8
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D035: @ 822D035
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D038: @ 822D038
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D03D: @ 822D03D
	walk_up
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D042: @ 822D042
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D045: @ 822D045
	walk_right
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_22D048: @ 822D048
	walk_up
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_22D04B: @ 822D04B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_22D058: @ 822D058
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_22D065: @ 822D065
	walk_right
	step_end

RusturfTunnel_Movement_22D067: @ 822D067
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_22D06C: @ 822D06C
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end

RusturfTunnel_EventScript_22D071:: @ 822D071
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_22D077:: @ 822D077
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_22D07D:: @ 822D07D
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_22D083:: @ 822D083
	lockall
	msgbox RusturfTunnel_Text_22D1C8, MSGBOX_DEFAULT
	closemessage
	applymovement 6, RusturfTunnel_Movement_22D0AB
	applymovement 7, RusturfTunnel_Movement_22D0AB
	waitmovement 0
	moveobjectoffscreen 6
	moveobjectoffscreen 7
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_22D0AB: @ 822D0AB
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_22D0AF:: @ 822D0AF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox RusturfTunnel_Text_22D1F7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_22D0C2:: @ 822D0C2
	lock
	faceplayer
	playbgm MUS_AQA_0, 0
	msgbox RusturfTunnel_Text_22D20A, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_10, RusturfTunnel_Text_22D2B0
	msgbox RusturfTunnel_Text_22D2E1, MSGBOX_DEFAULT
	giveitem_std ITEM_DEVON_GOODS
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D178
	applymovement 6, RusturfTunnel_Movement_22D181
	waitmovement 0
	removeobject 6
	delay 50
	addobject 5
	applymovement 5, RusturfTunnel_Movement_22D18B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D17E
	applymovement 5, RusturfTunnel_Movement_22D1A4
	waitmovement 0
	msgbox RusturfTunnel_Text_22D395, MSGBOX_DEFAULT
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_22D3BA
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, 0
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D19F
	applymovement 5, RusturfTunnel_Movement_22D193
	applymovement 7, RusturfTunnel_Movement_22D1A7
	waitmovement 0
	removeobject 5
	removeobject 7
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTunnel_Movement_22D178: @ 822D178
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_22D17E: @ 822D17E
	walk_down
	walk_in_place_fastest_up
	step_end

RusturfTunnel_Movement_22D181: @ 822D181
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_22D18B: @ 822D18B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_22D193: @ 822D193
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_22D19F: @ 822D19F
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_22D1A4: @ 822D1A4
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_22D1A7: @ 822D1A7
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_22D1B1:: @ 822D1B1
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_22D84D, RusturfTunnel_Text_22D8DB
	msgbox RusturfTunnel_Text_22D8F9, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_22D1C8: @ 822D1C8
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"

RusturfTunnel_Text_22D1F7: @ 822D1F7
	.string "PEEKO: Pii pihyoh!$"

RusturfTunnel_Text_22D20A: @ 822D20A
	.string "Grah, keelhaul it all!\p"
	.string "That hostage POKéMON turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You!\n"
	.string "So you want to battle me?$"

RusturfTunnel_Text_22D2B0: @ 822D2B0
	.string "Urrrggh! My career in crime comes to\n"
	.string "a dead end!$"

RusturfTunnel_Text_22D2E1: @ 822D2E1
	.string "This is plain not right…\p"
	.string "The BOSS told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some package\n"
	.string "from DEVON.\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"

RusturfTunnel_Text_22D395: @ 822D395
	.string "PEEKO!\n"
	.string "Am I glad to see you're safe!$"

RusturfTunnel_Text_22D3BA: @ 822D3BA
	.string "PEEKO owes her life to you!\p"
	.string "They call me MR. BRINEY.\n"
	.string "And, you are?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
	.string "I sincerely thank you!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near PETALBURG WOODS.\p"
	.string "Come, PEEKO, we should make our way\n"
	.string "home.\p"
	.string "PEEKO: Pihyoh!$"

RusturfTunnel_Text_22D510: @ 822D510
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in VERDANTURF\n"
	.string "TOWN just beyond here…\p"
	.string "If RUSTBORO and VERDANTURF were\n"
	.string "joined by this tunnel, I could visit\l"
	.string "her every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"

RusturfTunnel_Text_22D5F3: @ 822D5F3
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"

RusturfTunnel_Text_22D65C: @ 822D65C
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate it,\n"
	.string "I'd like you to have this HM.$"

RusturfTunnel_Text_22D6D2: @ 822D6D2
	.string "That HM contains STRENGTH.\p"
	.string "If a muscular POKéMON were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"

RusturfTunnel_Text_22D745: @ 822D745
	.string "WANDA!\n"
	.string "Now I can see you anytime!\p"
	.string "WANDA: That's…wonderful.\p"
	.string "Please, take some rest at my home.$"

RusturfTunnel_Text_22D7A3: @ 822D7A3
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"

RusturfTunnel_Text_22D84D: @ 822D84D
	.string "What do you call a wild man up in the\n"
	.string "mountains? A mountain man, right?\p"
	.string "So why don't they call a POKéMON in\n"
	.string "the mountains a mountain POKéMON?$"

RusturfTunnel_Text_22D8DB: @ 822D8DB
	.string "My POKéMON…\n"
	.string "Ran out of power…$"

RusturfTunnel_Text_22D8F9: @ 822D8F9
	.string "They halted development here to\n"
	.string "protect POKéMON, right?\l"
	.string "There's a feel-good story!$"


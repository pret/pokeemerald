LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_MapScript1_1F88B5
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_MapScript1_1F88F4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_MapScript2_1F893A
	.byte 0

LittlerootTown_MaysHouse_1F_MapScript1_1F88B5: @ 81F88B5
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_MaysHouse_1F_EventScript_1F88CA
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_1F88DD
	end

LittlerootTown_MaysHouse_1F_EventScript_1F88CA:: @ 81F88CA
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_MaysHouse_1F_EventScript_1F88DD:: @ 81F88DD
	checkplayergender
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F88EA
	return

LittlerootTown_MaysHouse_1F_EventScript_1F88EA:: @ 81F88EA
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_MaysHouse_1F_MapScript1_1F88F4: @ 81F88F4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F892E
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8916
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8922
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8916:: @ 81F8916
	setobjectxyperm 1, 2, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8922:: @ 81F8922
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_1F892E:: @ 81F892E
	setobjectxyperm 1, 1, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_MapScript2_1F893A: @ 81F893A
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_1F898C
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_1F8964
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_1F899D
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_2, 1, LittlerootTown_MaysHouse_1F_EventScript_1F89AE
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_292AF2
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_1F8964:: @ 81F8964
	lockall
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7B67, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F898A
	applymovement 1, LittlerootTown_MaysHouse_1F_Movement_1F898A
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 1, 1
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_1F898A: @ 81F898A
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_1F898C:: @ 81F898C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_292704
	end

LittlerootTown_MaysHouse_1F_EventScript_1F899D:: @ 81F899D
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_2928DC
	end

LittlerootTown_MaysHouse_1F_EventScript_1F89AE:: @ 81F89AE
	lockall
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_1F89EC
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox LittlerootTown_MaysHouse_1F_Text_1F8BC5, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_1F89EC: @ 81F89EC
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F89F3:: @ 81F89F3
LittlerootTown_MaysHouse_1F_EventScript_1F89F3:: @ 81F89F3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, LittlerootTown_BrendansHouse_1F_EventScript_1F8A33
	goto_if_set FLAG_SYS_POKEMON_GET, LittlerootTown_BrendansHouse_1F_EventScript_1F8A29
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F
	special GetRivalSonDaughterString
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8CA5, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F:: @ 81F8A1F
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8D37, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A29:: @ 81F8A29
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8D93, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A33:: @ 81F8A33
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8E01, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F8A3D:: @ 81F8A3D
LittlerootTown_MaysHouse_1F_EventScript_1F8A3D:: @ 81F8A3D
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F9262, MSGBOX_DEFAULT
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A4C:: @ 81F8A4C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_292765
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A67:: @ 81F8A67
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A73:: @ 81F8A73
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A7F:: @ 81F8A7F
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A8B:: @ 81F8A8B
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_MaysHouse_1F_EventScript_1F8B2A
	playbgm MUS_GIRL_SUP, 1
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B35
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B40
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B4B
	msgbox LittlerootTown_MaysHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B6A
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B7C
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B8E
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_0x4050, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8B2A:: @ 81F8B2A
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B35:: @ 81F8B35
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B56
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B40:: @ 81F8B40
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B5E
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B4B:: @ 81F8B4B
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B62
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8B56: @ 81F8B56
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B5E: @ 81F8B5E
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B62: @ 81F8B62
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_1F8B6A:: @ 81F8B6A
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BA0
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BAF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B7C:: @ 81F8B7C
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BA4
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BB5
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B8E:: @ 81F8B8E
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BAB
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BBF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8BA0: @ 81F8BA0
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BA4: @ 81F8BA4
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAB: @ 81F8BAB
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAF: @ 81F8BAF
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BB5: @ 81F8BB5
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BBF: @ 81F8BBF
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Text_1F8BC5: @ 81F8BC5
LittlerootTown_MaysHouse_1F_Text_1F8BC5: @ 81F8BC5
	.string "Oh, hello. And you are?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}, our new next-door\n"
	.string "neighbor! Hi!\p"
	.string "We have a {STR_VAR_1} about the same\n"
	.string "age as you.\p"
	.string "Our {STR_VAR_1} was excited about making\n"
	.string "a new friend.\p"
	.string "Our {STR_VAR_1} is upstairs, I think.$"

LittlerootTown_BrendansHouse_1F_Text_1F8CA5: @ 81F8CA5
	.string "Like child, like father.\p"
	.string "My husband is as wild about POKéMON\n"
	.string "as our child.\p"
	.string "If he's not at his LAB, he's likely\n"
	.string "scrabbling about in grassy places.$"

LittlerootTown_BrendansHouse_1F_Text_1F8D37: @ 81F8D37
	.string "That {RIVAL}!\p"
	.string "I guess our child is too busy with\n"
	.string "POKéMON to notice that you came\l"
	.string "to visit, {PLAYER}{KUN}.$"

LittlerootTown_BrendansHouse_1F_Text_1F8D93: @ 81F8D93
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "Like father, like child.\n"
	.string "{RIVAL} can't stay quietly at home.$"

LittlerootTown_BrendansHouse_1F_Text_1F8E01: @ 81F8E01
	.string "I think it's wonderful for people to\n"
	.string "travel with POKéMON.\p"
	.string "But you should go home every so often\n"
	.string "to let your mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"

LittlerootTown_MaysHouse_1F_Text_1F8EC6: @ 81F8EC6
	.string "Huh?\n"
	.string "Who… Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}.\n"
	.string "So your move was today.\p"
	.string "Um… I'm MAY.\n"
	.string "Glad to meet you!\p"
	.string "I…\n"
	.string "I have this dream of becoming friends\l"
	.string "with POKéMON all over the world.\p"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
	.string "my dad, PROF. BIRCH.\p"
	.string "I was hoping that you would be nice,\n"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
	.string "Oh, this is silly, isn't it?\n"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
	.string "Eheheh…\p"
	.string "Oh, no! I forgot!\p"
	.string "I was supposed to go help Dad catch\n"
	.string "some wild POKéMON!\p"
	.string "{PLAYER}{KUN}, I'll catch you later!$"

LittlerootTown_BrendansHouse_1F_Text_1F90B4: @ 81F90B4
	.string "Hey!\n"
	.string "You…\p"
	.string "Who are you?\p"
	.string "Oh, you're {PLAYER}, aren't you?\n"
	.string "Moved in next door, right?\p"
	.string "I didn't know that you're a girl.\p"
	.string "Dad, PROF. BIRCH, said that our new\n"
	.string "next-door neighbor is a GYM LEADER's\l"
	.string "kid, so I assumed you'd be a guy.\p"
	.string "My name's BRENDAN.\n"
	.string "So, hi, neighbor!\p"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
	.string "a POKéMON?\p"
	.string "Do you want me to go catch you one?\p"
	.string "Aw, darn, I forgot…\p"
	.string "I'm supposed to go help my dad catch\n"
	.string "some wild POKéMON.\p"
	.string "Some other time, okay?$"

LittlerootTown_BrendansHouse_1F_Text_1F9262: @ 81F9262
	.string "Hi, neighbor!\p"
	.string "Do you already have your\n"
	.string "own POKéMON?$"

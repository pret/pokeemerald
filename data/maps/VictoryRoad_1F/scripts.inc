VictoryRoad_1F_MapScripts:: @ 8235D7A
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition: @ 8235D80
	compare VAR_VICTORY_ROAD_1F_STATE, 1
	call_if_eq VictoryRoad_1F_EventScript_235D97
	compare VAR_VICTORY_ROAD_1F_STATE, 2
	call_if_eq VictoryRoad_1F_EventScript_235DA3
	end

VictoryRoad_1F_EventScript_235D97:: @ 8235D97
	setobjectxyperm 4, 2, 24
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_235DA3:: @ 8235DA3
	setobjectxyperm 4, 3, 24
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_235DAF:: @ 8235DAF
	lockall
	setvar VAR_0x8008, 1
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_235E15
	waitmovement 0
	goto VictoryRoad_1F_EventScript_235DE1
	end

VictoryRoad_1F_EventScript_235DC8:: @ 8235DC8
	lockall
	setvar VAR_0x8008, 2
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_235E21
	waitmovement 0
	goto VictoryRoad_1F_EventScript_235DE1
	end

VictoryRoad_1F_EventScript_235DE1:: @ 8235DE1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_235EE6, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_1, VictoryRoad_1F_Text_235FFC
	msgbox VictoryRoad_1F_Text_236020, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	moveobjectoffscreen 4
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_235E15: @ 8235E15
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
	walk_up
	step_end

VictoryRoad_1F_Movement_235E21: @ 8235E21
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_EventScript_235E2C:: @ 8235E2C
	msgbox VictoryRoad_1F_Text_236020, MSGBOX_NPC
	end

VictoryRoad_1F_EventScript_235E35:: @ 8235E35
	trainerbattle_single TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_235E5C
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E5C:: @ 8235E5C
	trainerbattle_rematch TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E73:: @ 8235E73
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_236184, VictoryRoad_1F_Text_2361CB
	msgbox VictoryRoad_1F_Text_2361E5, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E8A:: @ 8235E8A
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_236248, VictoryRoad_1F_Text_236290
	msgbox VictoryRoad_1F_Text_2362A4, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235EA1:: @ 8235EA1
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_2362EE, VictoryRoad_1F_Text_236336
	msgbox VictoryRoad_1F_Text_236356, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235EB8:: @ 8235EB8
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_236390, VictoryRoad_1F_Text_2363C4
	msgbox VictoryRoad_1F_Text_2363D5, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235ECF:: @ 8235ECF
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_236468, VictoryRoad_1F_Text_2364A7
	msgbox VictoryRoad_1F_Text_2364BB, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_235EE6: @ 8235EE6
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the POKéMON who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_235FFC: @ 8235FFC
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_236020: @ 8236020
	.string "WALLY: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"

VictoryRoad_1F_Text_236073: @ 8236073
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_2360DA: @ 82360DA
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_2360FE: @ 82360FE
	.string "WALLY: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the POKéMON LEAGUE!$"

VictoryRoad_1F_Text_236184: @ 8236184
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"

VictoryRoad_1F_Text_2361CB: @ 82361CB
	.string "My dream ends here again…$"

VictoryRoad_1F_Text_2361E5: @ 82361E5
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "CHAMPION! If anyone can, it's you!$"

VictoryRoad_1F_Text_236248: @ 8236248
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"

VictoryRoad_1F_Text_236290: @ 8236290
	.string "Impossible…\n"
	.string "I lost?$"

VictoryRoad_1F_Text_2362A4: @ 82362A4
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the CHAMPION…$"

VictoryRoad_1F_Text_2362EE: @ 82362EE
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of VICTORY.$"

VictoryRoad_1F_Text_236336: @ 8236336
	.string "Your battle style is fantastic…$"

VictoryRoad_1F_Text_236356: @ 8236356
	.string "You seem to have the potential for\n"
	.string "becoming the CHAMPION.$"

VictoryRoad_1F_Text_236390: @ 8236390
	.string "What is the VICTORY ROAD?\n"
	.string "I'll tell you if you win!$"

VictoryRoad_1F_Text_2363C4: @ 82363C4
	.string "Okay!\n"
	.string "Well done!$"

VictoryRoad_1F_Text_2363D5: @ 82363D5
	.string "Getting through here safely--that's\n"
	.string "the final test for any TRAINER aiming\l"
	.string "to become the POKéMON CHAMPION.\p"
	.string "That's why it's called the VICTORY\n"
	.string "ROAD.$"

VictoryRoad_1F_Text_236468: @ 8236468
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"

VictoryRoad_1F_Text_2364A7: @ 82364A7
	.string "This is a disgrace…$"

VictoryRoad_1F_Text_2364BB: @ 82364BB
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"

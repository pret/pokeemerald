Route119_MapScripts:: @ 81F4424
	map_script MAP_SCRIPT_ON_RESUME, Route119_MapScript1_1F442F
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_MapScript1_1F442F: @ 81F442F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_1F4439
	end

Route119_EventScript_1F4439:: @ 81F4439
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition: @ 81F444D
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_EventScript_1F4466
	special SetRoute119Weather
	end

Route119_EventScript_1F4466:: @ 81F4466
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_1F4472:: @ 81F4472
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F447D:: @ 81F447D
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F4488:: @ 81F4488
	lockall
	addobject 25
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route119_EventScript_1F4501
	compare VAR_RESULT, FEMALE
	call_if_eq Route119_EventScript_1F4506
	delay 65
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46C6
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46D1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject 25
	addobject 16
	delay 30
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_EventScript_1F450B
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_EventScript_1F4585
	releaseall
	end

Route119_EventScript_1F4501:: @ 81F4501
	playbgm MUS_GIRL_SUP, 1
	return

Route119_EventScript_1F4506:: @ 81F4506
	playbgm MUS_BOY_SUP, 1
	return

Route119_EventScript_1F450B:: @ 81F450B
	msgbox Route119_Text_1F49FD, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F453A
	case 1, Route119_EventScript_1F454A
	case 2, Route119_EventScript_1F455A
	end

Route119_EventScript_1F453A:: @ 81F453A
	trainerbattle_no_intro TRAINER_MAY_6, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F454A:: @ 81F454A
	trainerbattle_no_intro TRAINER_MAY_9, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F455A:: @ 81F455A
	trainerbattle_no_intro TRAINER_MAY_3, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F456A:: @ 81F456A
	msgbox Route119_Text_1F4AF3, MSGBOX_DEFAULT
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4B56, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F4585:: @ 81F4585
	msgbox Route119_Text_1F4C9A, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F45B4
	case 1, Route119_EventScript_1F45C4
	case 2, Route119_EventScript_1F45D4
	end

Route119_EventScript_1F45B4:: @ 81F45B4
	trainerbattle_no_intro TRAINER_BRENDAN_6, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45C4:: @ 81F45C4
	trainerbattle_no_intro TRAINER_BRENDAN_9, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45D4:: @ 81F45D4
	trainerbattle_no_intro TRAINER_BRENDAN_3, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45E4:: @ 81F45E4
	msgbox Route119_Text_1F4D4B, MSGBOX_DEFAULT
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4DB5, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F45FF:: @ 81F45FF
	giveitem_std ITEM_HM02
	setflag FLAG_RECEIVED_HM02
	return

Route119_EventScript_1F460F:: @ 81F460F
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject 16
	addobject 25
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46DC
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46EE
	removeobject 25
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46A0
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46A8
	addobject 43
	applymovement 43, Route119_Movement_1F4752
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_1F4E60, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46B0
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46BB
	removeobject 43
	releaseall
	end

Route119_EventScript_1F46A0:: @ 81F46A0
	setobjectxyperm 43, 27, 25
	return

Route119_EventScript_1F46A8:: @ 81F46A8
	setobjectxyperm 43, 28, 25
	return

Route119_EventScript_1F46B0:: @ 81F46B0
	applymovement 43, Route119_Movement_1F475A
	waitmovement 0
	return

Route119_EventScript_1F46BB:: @ 81F46BB
	applymovement 43, Route119_Movement_1F4763
	waitmovement 0
	return

Route119_EventScript_1F46C6:: @ 81F46C6
	applymovement 25, Route119_Movement_1F4728
	waitmovement 0
	return

Route119_EventScript_1F46D1:: @ 81F46D1
	applymovement 25, Route119_Movement_1F4732
	waitmovement 0
	return

Route119_EventScript_1F46DC:: @ 81F46DC
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F471E
	applymovement 25, Route119_Movement_1F473D
	waitmovement 0
	return

Route119_EventScript_1F46EE:: @ 81F46EE
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F4723
	applymovement 25, Route119_Movement_1F4747
	waitmovement 0
	return

Route119_EventScript_1F4700:: @ 81F4700
	setobjectxyperm 16, 25, 32
	setobjectxyperm 25, 25, 32
	return

Route119_EventScript_1F470F:: @ 81F470F
	setobjectxyperm 16, 26, 32
	setobjectxyperm 25, 26, 32
	return

Route119_Movement_1F471E: @ 81F471E
	delay_16
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4723: @ 81F4723
	delay_16
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4728: @ 81F4728
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F4732: @ 81F4732
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F473D: @ 81F473D
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_1F4747: @ 81F4747
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_1F4752: @ 81F4752
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_1F475A: @ 81F475A
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_1F4763: @ 81F4763
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_1F476B:: @ 81F476B
	msgbox Route119_Text_1F5261, MSGBOX_NPC
	end

Route119_EventScript_1F4774:: @ 81F4774
	msgbox Route119_Text_1F530E, MSGBOX_SIGN
	end

Route119_EventScript_1F477D:: @ 81F477D
	msgbox Route119_Text_1F5327, MSGBOX_SIGN
	end

Route119_EventScript_1F4786:: @ 81F4786
	trainerbattle_single TRAINER_BRENT, Route119_Text_29D8C2, Route119_Text_29D8F0
	msgbox Route119_Text_29D902, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F479D:: @ 81F479D
	trainerbattle_single TRAINER_DONALD, Route119_Text_29D941, Route119_Text_29D97C
	msgbox Route119_Text_29D993, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47B4:: @ 81F47B4
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_29D9CD, Route119_Text_29DA14
	msgbox Route119_Text_29DA2C, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47CB:: @ 81F47CB
	trainerbattle_single TRAINER_DOUG, Route119_Text_29DA7D, Route119_Text_29DABC
	msgbox Route119_Text_29DADB, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47E2:: @ 81F47E2
	trainerbattle_single TRAINER_GREG, Route119_Text_29DB17, Route119_Text_29DB66
	msgbox Route119_Text_29DB7C, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47F9:: @ 81F47F9
	trainerbattle_single TRAINER_KENT, Route119_Text_29DBC2, Route119_Text_29DC20
	msgbox Route119_Text_29DC2B, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4810:: @ 81F4810
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_29DC4C, Route119_Text_29DC9F, Route119_EventScript_1F483C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F485B
	msgbox Route119_Text_29DCC6, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_1F483C:: @ 81F483C
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DD1C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_1F485B:: @ 81F485B
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_29DD62, Route119_Text_29DDA5
	msgbox Route119_Text_29DDBD, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4872:: @ 81F4872
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_29DE0F, Route119_Text_29DE5D, Route119_EventScript_1F489E
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F48BD
	msgbox Route119_Text_29DE88, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_1F489E:: @ 81F489E
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DEF7, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_1F48BD:: @ 81F48BD
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_29DF6B, Route119_Text_29DF92
	msgbox Route119_Text_29DFAF, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F48D4:: @ 81F48D4
	trainerbattle_single TRAINER_HUGH, Route119_Text_29E007, Route119_Text_29E063
	msgbox Route119_Text_29E071, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F48EB:: @ 81F48EB
	trainerbattle_single TRAINER_PHIL, Route119_Text_29E0A5, Route119_Text_29E0E1
	msgbox Route119_Text_29E0F6, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4902:: @ 81F4902
	trainerbattle_single TRAINER_YASU, Route119_Text_29E134, Route119_Text_29E18D
	msgbox Route119_Text_29E19D, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4919:: @ 81F4919
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_29E1F5, Route119_Text_29E22B
	msgbox Route119_Text_29E245, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4930:: @ 81F4930
	trainerbattle_single TRAINER_HIDEO, Route119_Text_29E26A, Route119_Text_29E288
	msgbox Route119_Text_29E2A3, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4947:: @ 81F4947
	trainerbattle_single TRAINER_CHRIS, Route119_Text_29E30D, Route119_Text_29E372
	msgbox Route119_Text_29E3A2, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F495E:: @ 81F495E
	trainerbattle_single TRAINER_FABIAN, Route119_Text_29E3FF, Route119_Text_29E44F
	msgbox Route119_Text_29E492, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4975:: @ 81F4975
	trainerbattle_single TRAINER_DAYTON, Route119_Text_29E4DF, Route119_Text_29E513
	msgbox Route119_Text_29E532, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F498C:: @ 81F498C
	trainerbattle_single TRAINER_RACHEL, Route119_Text_29E56F, Route119_Text_29E5B1
	msgbox Route119_Text_29E5CB, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F49A3:: @ 81F49A3
	lock
	faceplayer
	msgbox Route119_Text_1F50EB, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_1F49BA:: @ 81F49BA
	lock
	faceplayer
	msgbox Route119_Text_1F5147, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_1F49D1:: @ 81F49D1
	msgbox Route119_Text_1F51A2, MSGBOX_NPC
	end

Route119_EventScript_1F49DA:: @ 81F49DA
	msgbox Route119_Text_1F52B9, MSGBOX_NPC
	end

Route119_EventScript_1F49E3:: @ 81F49E3
	msgbox Route119_Text_1F5339, MSGBOX_SIGN
	end

Route119_EventScript_1F49EC:: @ 81F49EC
	lockall
	pokenavcall Route119_Text_1F4FBA
	waitmessage
	clearflag FLAG_REGISTER_WINONA_POKENAV
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_1F49FD: @ 81F49FD
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Where were you? I was looking for you!\p"
	.string "How much stronger have you gotten?\n"
	.string "Let me check for you!\p"
	.string "Ready with your POKéMON?\n"
	.string "Of course you are! Go!$"

Route119_Text_1F4A98: @ 81F4A98
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, you're strong!\p"
	.string "I was worried that you might be\n"
	.string "struggling with your training.$"

Route119_Text_1F4AF3: @ 81F4AF3
	.string "MAY: But I had absolutely nothing to\n"
	.string "worry about! Keep it up!\p"
	.string "And, here! I have a present for you.$"

Route119_Text_1F4B56: @ 81F4B56
	.string "MAY: Use FLY, and your POKéMON will\n"
	.string "instantly carry you to any town you've\l"
	.string "already visited.\p"
	.string "But, to use FLY, you have to get\n"
	.string "the GYM BADGE from FORTREE CITY.\l"
	.string "That's important, so don't forget.\p"
	.string "You should FLY home and visit\n"
	.string "LITTLEROOT for a change.\p"
	.string "I bet your mom's worried about you,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Well, let's meet again somewhere!$"

Route119_Text_1F4C9A: @ 81F4C9A
	.string "BRENDAN: {PLAYER}! So this is where\n"
	.string "you've been looking for POKéMON?\p"
	.string "Let me see how good you got.\n"
	.string "I'll test you!\p"
	.string "Now!\n"
	.string "It's a battle, so battle!$"

Route119_Text_1F4D24: @ 81F4D24
	.string "Hmm…\n"
	.string "You've gotten pretty darn decent.$"

Route119_Text_1F4D4B: @ 81F4D4B
	.string "BRENDAN: I'd say you're good enough\n"
	.string "to search for POKéMON anywhere.\p"
	.string "Here, I'll give you this.\n"
	.string "Try it out.$"

Route119_Text_1F4DB5: @ 81F4DB5
	.string "BRENDAN: Use FLY, and your POKéMON\n"
	.string "instantly carries you to any town\l"
	.string "you've already visited.\p"
	.string "But you need the FORTREE GYM BADGE \n"
	.string "to do that.\p"
	.string "Anyway, I have to move along.$"

Route119_Text_1F4E60: @ 81F4E60
	.string "SCOTT: Hahahah!\n"
	.string "Way to go, {PLAYER}{KUN}!\p"
	.string "I just passed by a TRAINER riding\n"
	.string "a BIKE.\p"
	.string "You just beat that TRAINER, didn't you?\n"
	.string "It was pretty obvious that you did.\p"
	.string "The kid looked really upset with\n"
	.string "a face all red from anger.\p"
	.string "I sure seem to run into you often.\n"
	.string "Are you off to FORTREE GYM next?\p"
	.string "I expect that you'll do well at the GYM.\n"
	.string "Well, I'll be seeing you!$"


Route119_Text_1F4FBA: @ 81F4FBA
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
	.string "Just as I thought, you won at\n"
	.string "the FORTREE GYM.\p"
	.string "Your strength…\n"
	.string "Perhaps you really are the TRAINER\l"
	.string "that I've been searching for.\p"
	.string "Remember, you have a fan in me.\n"
	.string "I'll be cheering from the sidelines.\l"
	.string "Keep up the great work!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route119_Text_1F50EB: @ 81F50EB
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the WEATHER\n"
	.string "INSTITUTE. It's not safe.$"

Route119_Text_1F5147: @ 81F5147
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "WEATHER INSTITUTE.$"

Route119_Text_1F51A2: @ 81F51A2
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD POKéMON, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_1F5261: @ 81F5261
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_1F52B9: @ 81F52B9
	.string "Can your POKéMON use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_1F530E: @ 81F530E
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_1F5327: @ 81F5327
	.string "WEATHER INSTITUTE$"

Route119_Text_1F5339: @ 81F5339
	.string "TRAINER TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a SECRET BASE.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own SECRET BASE exactly the\l"
	.string "way you want.$"

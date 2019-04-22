AquaHideout_B2F_MapScripts:: @ 8233DCF
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition: @ 8233DD5
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_233DDF
	end

AquaHideout_B2F_EventScript_233DDF:: @ 8233DDF
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_233DE5:: @ 8233DE5
	lockall
	setvar VAR_0x8008, 1
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_233E09:: @ 8233E09
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_233EDD, AquaHideout_B2F_Text_233F8D, AquaHideout_B2F_EventScript_233E25
	msgbox AquaHideout_B2F_Text_233FF2, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_233E25:: @ 8233E25
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 4
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_233FA6, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_233E80
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_233FF2, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_233E80: @ 8233E80
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AquaHideout_B2F_Movement_233E85: @ 8233E85
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_233E8A:: @ 8233E8A
	trainerbattle_single TRAINER_GRUNT_4, AquaHideout_B2F_Text_2340B4, AquaHideout_B2F_Text_2340F0, AquaHideout_B2F_EventScript_233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_233EA5:: @ 8233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_233EAF:: @ 8233EAF
	trainerbattle_single TRAINER_GRUNT_22, AquaHideout_B2F_Text_23412D, AquaHideout_B2F_Text_2341CE
	msgbox AquaHideout_B2F_Text_2341FE, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_233EC6:: @ 8233EC6
	trainerbattle_single TRAINER_GRUNT_26, AquaHideout_B2F_Text_23426F, AquaHideout_B2F_Text_2342CC
	msgbox AquaHideout_B2F_Text_2342FF, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_233EDD: @ 8233EDD
	.string "Hehehe…\p"
	.string "Got here already, did you?\n"
	.string "We underestimated you!\p"
	.string "But this is it!\p"
	.string "I'm a cut above the GRUNTS you've seen\n"
	.string "so far.\p"
	.string "I'm not stalling for time.\n"
	.string "I'm going to pulverize you!$"

AquaHideout_B2F_Text_233F8D: @ 8233F8D
	.string "Hehehe…\n"
	.string "So, I lost, too…$"

AquaHideout_B2F_Text_233FA6: @ 8233FA6
	.string "Hehehe!\p"
	.string "While I was toying with you, our BOSS\n"
	.string "got through his preparations!$"

AquaHideout_B2F_Text_233FF2: @ 8233FF2
	.string "Hehehe!\p"
	.string "Our BOSS has already gone on his way to\n"
	.string "some cave under the sea!\p"
	.string "If you're going to give chase, you'd\n"
	.string "better search the big, wide sea beyond\l"
	.string "LILYCOVE.\p"
	.string "But will you find it then?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_2340B4: @ 82340B4
	.string "Wahahah, I grew weary of waiting!\n"
	.string "You owe me a battle, too!$"

AquaHideout_B2F_Text_2340F0: @ 82340F0
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"

AquaHideout_B2F_Text_234112: @ 8234112
	.string "BOSS…\n"
	.string "Is this good enough?$"

AquaHideout_B2F_Text_23412D: @ 823412D
	.string "Warp panels, the HIDEOUT's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"

AquaHideout_B2F_Text_2341CE: @ 82341CE
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"

AquaHideout_B2F_Text_2341FE: @ 82341FE
	.string "That reminds me… I can't remember\n"
	.string "where I put the MASTER BALL.\p"
	.string "If I fail to guard it, our BOSS will\n"
	.string "chew me out…$"

AquaHideout_B2F_Text_23426F: @ 823426F
	.string "When I joined TEAM AQUA, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"

AquaHideout_B2F_Text_2342CC: @ 82342CC
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"

AquaHideout_B2F_Text_2342FF: @ 82342FF
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"

CaveOfOrigin_B1F_MapScripts:: @ 82357A8
	.byte 0

CaveOfOrigin_B1F_EventScript_2357A9:: @ 82357A9
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_23586E, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_235ACE
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_2357F0

CaveOfOrigin_B1F_EventScript_2357F0:: @ 82357F0
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, 0
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_23582C
	case 1, CaveOfOrigin_B1F_EventScript_235837
	case 2, CaveOfOrigin_B1F_EventScript_23584D
	case 3, CaveOfOrigin_B1F_EventScript_235842
	goto CaveOfOrigin_B1F_EventScript_235842
	end

CaveOfOrigin_B1F_EventScript_23582C:: @ 823582C
	message CaveOfOrigin_B1F_Text_235B23
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_2357F0

CaveOfOrigin_B1F_EventScript_235837:: @ 8235837
	message CaveOfOrigin_B1F_Text_235BBF
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_2357F0

CaveOfOrigin_B1F_EventScript_235842:: @ 8235842
	message CaveOfOrigin_B1F_Text_235C99
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_2357F0

CaveOfOrigin_B1F_EventScript_23584D:: @ 823584D
	msgbox CaveOfOrigin_B1F_Text_235CEE, MSGBOX_DEFAULT
	closemessage
	playse SE_KAIDAN
	fadescreenspeed 1, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject 1
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen 0
	release
	end

CaveOfOrigin_B1F_Text_23586E: @ 823586E
	.string "Ah, so you are {PLAYER}{KUN}?\n"
	.string "I've heard tales of your exploits.\p"
	.string "My name is WALLACE.\p"
	.string "I was once the GYM LEADER of\n"
	.string "SOOTOPOLIS, but something came up.\p"
	.string "So now, I've entrusted my mentor JUAN\n"
	.string "with the GYM's operation.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON and KYOGRE, the two POKéMON\n"
	.string "wreaking havoc here, are considered\l"
	.string "to be super-ancient POKéMON.\p"
	.string "But there aren't just two super-\n"
	.string "ancient POKéMON.\p"
	.string "There is one more somewhere.\p"
	.string "Somewhere, there is a super-\n"
	.string "ancient POKéMON named RAYQUAZA.\p"
	.string "It's said that it was RAYQUAZA that\n"
	.string "becalmed the two combatants in\l"
	.string "the distant past.\p"
	.string "But even I have no clue as to\n"
	.string "RAYQUAZA's whereabouts…$"

CaveOfOrigin_B1F_Text_235ACE: @ 8235ACE
	.string "WALLACE: {PLAYER}{KUN}, do you perhaps\n"
	.string "know where RAYQUAZA is now?\p"
	.string "If you do, please tell me.$"

CaveOfOrigin_B1F_Text_235B23: @ 8235B23
	.string "WALLACE: The CAVE OF ORIGIN?\p"
	.string "But that's right here!\n"
	.string "I need you to do better than that!\p"
	.string "Please, I need you to think about\n"
	.string "where RAYQUAZA might be right now.$"

CaveOfOrigin_B1F_Text_235BBF: @ 8235BBF
	.string "WALLACE: MT. PYRE?\p"
	.string "But when I met the old lady there\n"
	.string "earlier, she made no mention of it.\p"
	.string "I very much doubt that the old lady\n"
	.string "would try to hide something from me…\p"
	.string "{PLAYER}{KUN}, could you think about this\n"
	.string "more carefully for me?$"

CaveOfOrigin_B1F_Text_235C99: @ 8235C99
	.string "WALLACE: Huh? You don't remember?\n"
	.string "Hmm… That's a problem…\p"
	.string "Can't you remember somehow?$"

CaveOfOrigin_B1F_Text_235CEE: @ 8235CEE
	.string "WALLACE: The SKY PILLAR?\p"
	.string "That's it!\n"
	.string "It must be the SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, there's not a moment to lose!\n"
	.string "We'll head to the SKY PILLAR right away!$"


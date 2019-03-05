FallarborTown_House2_MapScripts:: @ 8201382
	.byte 0

FallarborTown_House2_EventScript_201383:: @ 8201383
	lockall
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_House2_EventScript_2013A8
	msgbox FallarborTown_House2_Text_20145C, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_House2_EventScript_2013A8
	end

FallarborTown_House2_EventScript_2013A8:: @ 82013A8
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_House2_EventScript_201452
	msgbox FallarborTown_House2_Text_201541, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, FallarborTown_House2_EventScript_201452
	goto FallarborTown_House2_EventScript_2013D6
	end

FallarborTown_House2_EventScript_2013D6:: @ 82013D6
	msgbox FallarborTown_House2_Text_2015A5, MSGBOX_DEFAULT
	special sub_81B951C
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_House2_EventScript_201452
	special sub_81B98DC
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_House2_EventScript_201444
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_House2_EventScript_201436
	goto FallarborTown_House2_EventScript_20140C
	end

FallarborTown_House2_EventScript_20140C:: @ 820140C
	msgbox FallarborTown_House2_Text_2015C3, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_House2_EventScript_2013D6
	msgbox FallarborTown_House2_Text_201627, MSGBOX_DEFAULT
	takeitem ITEM_HEART_SCALE, 1
	goto FallarborTown_House2_EventScript_201452
	end

FallarborTown_House2_EventScript_201436:: @ 8201436
	msgbox FallarborTown_House2_Text_2015DE, MSGBOX_DEFAULT
	goto FallarborTown_House2_EventScript_2013D6
	end

FallarborTown_House2_EventScript_201444:: @ 8201444
	msgbox FallarborTown_House2_Text_201697, MSGBOX_DEFAULT
	goto FallarborTown_House2_EventScript_2013D6
	end

FallarborTown_House2_EventScript_201452:: @ 8201452
	msgbox FallarborTown_House2_Text_201653, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_House2_Text_20145C: @ 820145C
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

FallarborTown_House2_Text_201541: @ 8201541
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

FallarborTown_House2_Text_2015A5: @ 82015A5
	.string "Which POKéMON needs tutoring?$"

FallarborTown_House2_Text_2015C3: @ 82015C3
	.string "Which move should I teach?$"

FallarborTown_House2_Text_2015DE: @ 82015DE
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

FallarborTown_House2_Text_201627: @ 8201627
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

FallarborTown_House2_Text_201653: @ 8201653
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

FallarborTown_House2_Text_201697: @ 8201697
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"


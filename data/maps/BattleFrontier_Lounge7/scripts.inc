BattleFrontier_Lounge7_MapScripts:: @ 8265254
	.byte 0

BattleFrontier_Lounge7_EventScript_265255:: @ 8265255
	lock
	faceplayer
	setvar VAR_TEMP_C, 9
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_265276
	msgbox BattleFrontier_Lounge7_Text_2656ED, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_265284
	end

BattleFrontier_Lounge7_EventScript_265276:: @ 8265276
	msgbox BattleFrontier_Lounge7_Text_2658AB, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_265284
	end

BattleFrontier_Lounge7_EventScript_265284:: @ 8265284
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	special sub_813A958
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, 9
	setvar VAR_0x8006, 0
	special sub_813A128
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2653D7
	case 1, BattleFrontier_Lounge7_EventScript_2653E2
	case 2, BattleFrontier_Lounge7_EventScript_2653ED
	case 3, BattleFrontier_Lounge7_EventScript_2653F8
	case 4, BattleFrontier_Lounge7_EventScript_265403
	case 5, BattleFrontier_Lounge7_EventScript_26540E
	case 6, BattleFrontier_Lounge7_EventScript_265419
	case 7, BattleFrontier_Lounge7_EventScript_265424
	case 8, BattleFrontier_Lounge7_EventScript_26542F
	case 9, BattleFrontier_Lounge7_EventScript_26543A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case 127, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_26532F:: @ 826532F
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, 9
	setvar VAR_0x8006, 1
	special sub_813A128
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2653D7
	case 1, BattleFrontier_Lounge7_EventScript_2653E2
	case 2, BattleFrontier_Lounge7_EventScript_2653ED
	case 3, BattleFrontier_Lounge7_EventScript_2653F8
	case 4, BattleFrontier_Lounge7_EventScript_265403
	case 5, BattleFrontier_Lounge7_EventScript_26540E
	case 6, BattleFrontier_Lounge7_EventScript_265419
	case 7, BattleFrontier_Lounge7_EventScript_265424
	case 8, BattleFrontier_Lounge7_EventScript_26542F
	case 9, BattleFrontier_Lounge7_EventScript_26543A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case 127, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_2653D7:: @ 82653D7
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653E2:: @ 82653E2
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653ED:: @ 82653ED
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653F8:: @ 82653F8
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265403:: @ 8265403
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26540E:: @ 826540E
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265419:: @ 8265419
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265424:: @ 8265424
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26542F:: @ 826542F
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26543A:: @ 826543A
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265445:: @ 8265445
	lock
	faceplayer
	setvar VAR_TEMP_C, 10
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_265466
	msgbox BattleFrontier_Lounge7_Text_265A6C, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_265474
	end

BattleFrontier_Lounge7_EventScript_265466:: @ 8265466
	msgbox BattleFrontier_Lounge7_Text_265C2C, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_265474
	end

BattleFrontier_Lounge7_EventScript_265474:: @ 8265474
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	special sub_813A958
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, 10
	setvar VAR_0x8006, 0
	special sub_813A128
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2655C7
	case 1, BattleFrontier_Lounge7_EventScript_2655D2
	case 2, BattleFrontier_Lounge7_EventScript_2655DD
	case 3, BattleFrontier_Lounge7_EventScript_2655E8
	case 4, BattleFrontier_Lounge7_EventScript_2655F3
	case 5, BattleFrontier_Lounge7_EventScript_2655FE
	case 6, BattleFrontier_Lounge7_EventScript_265609
	case 7, BattleFrontier_Lounge7_EventScript_265614
	case 8, BattleFrontier_Lounge7_EventScript_26561F
	case 9, BattleFrontier_Lounge7_EventScript_26562A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case 127, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_26551F:: @ 826551F
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, 10
	setvar VAR_0x8006, 1
	special sub_813A128
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2655C7
	case 1, BattleFrontier_Lounge7_EventScript_2655D2
	case 2, BattleFrontier_Lounge7_EventScript_2655DD
	case 3, BattleFrontier_Lounge7_EventScript_2655E8
	case 4, BattleFrontier_Lounge7_EventScript_2655F3
	case 5, BattleFrontier_Lounge7_EventScript_2655FE
	case 6, BattleFrontier_Lounge7_EventScript_265609
	case 7, BattleFrontier_Lounge7_EventScript_265614
	case 8, BattleFrontier_Lounge7_EventScript_26561F
	case 9, BattleFrontier_Lounge7_EventScript_26562A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case 127, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_2655C7:: @ 82655C7
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655D2:: @ 82655D2
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655DD:: @ 82655DD
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655E8:: @ 82655E8
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655F3:: @ 82655F3
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655FE:: @ 82655FE
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265609:: @ 8265609
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265614:: @ 8265614
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26561F:: @ 826561F
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26562A:: @ 826562A
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265635:: @ 8265635
	special sub_813ADB8
	special sub_813A988
	msgbox BattleFrontier_Lounge7_Text_265A0E, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_265645:: @ 8265645
	msgbox BattleFrontier_Lounge7_Text_265A0E, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_26564F:: @ 826564F
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special sub_813AC7C
	buffernumberstring 1, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_265921, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_2656CA
	specialvar VAR_TEMP_1, sub_813AA04
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_Lounge7_EventScript_265696
	msgbox BattleFrontier_Lounge7_Text_265997, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_2656CA
	end

BattleFrontier_Lounge7_EventScript_265696:: @ 8265696
	msgbox BattleFrontier_Lounge7_Text_26595A, MSGBOX_DEFAULT
	special sub_813AEB4
	fadescreen 1
	special sub_813A988
	special sub_813ADB8
	special sub_81B892C
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_265645
	msgbox BattleFrontier_Lounge7_Text_2659C7, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special sub_813A9A4
	release
	end

BattleFrontier_Lounge7_EventScript_2656CA:: @ 82656CA
	compare VAR_TEMP_E, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_26532F
	goto BattleFrontier_Lounge7_EventScript_26551F
	end

BattleFrontier_Lounge7_EventScript_2656DB:: @ 82656DB
	msgbox BattleFrontier_Lounge7_Text_265C6F, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_2656E4:: @ 82656E4
	msgbox BattleFrontier_Lounge7_Text_265D17, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_2656ED: @ 82656ED
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_2658AB: @ 82658AB
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"

BattleFrontier_Lounge7_Text_2658EF: @ 82658EF
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

BattleFrontier_Lounge7_Text_265921: @ 8265921
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleFrontier_Lounge7_Text_26595A: @ 826595A
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

BattleFrontier_Lounge7_Text_265997: @ 8265997
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

BattleFrontier_Lounge7_Text_2659C7: @ 82659C7
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

BattleFrontier_Lounge7_Text_265A0E: @ 8265A0E
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleFrontier_Lounge7_Text_265A6C: @ 8265A6C
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_265C2C: @ 8265C2C
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"

BattleFrontier_Lounge7_Text_265C6F: @ 8265C6F
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleFrontier_Lounge7_Text_265D17: @ 8265D17
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleFrontier_Lounge7_Text_265E30:: @ 8265E30
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

BattleFrontier_Lounge7_Text_265E5B:: @ 8265E5B
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleFrontier_Lounge7_Text_265E8A:: @ 8265E8A
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

BattleFrontier_Lounge7_Text_265EC0:: @ 8265EC0
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

BattleFrontier_Lounge7_Text_265EED:: @ 8265EED
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

BattleFrontier_Lounge7_Text_265F1C:: @ 8265F1C
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleFrontier_Lounge7_Text_265F47:: @ 8265F47
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"

BattleFrontier_Lounge7_Text_265F77:: @ 8265F77
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

BattleFrontier_Lounge7_Text_265FAA:: @ 8265FAA
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"

BattleFrontier_Lounge7_Text_265FDD:: @ 8265FDD
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"

BattleFrontier_Lounge7_Text_26600A:: @ 826600A
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"

BattleFrontier_Lounge7_Text_26603E:: @ 826603E
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

BattleFrontier_Lounge7_Text_266070:: @ 8266070
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"

BattleFrontier_Lounge7_Text_2660A6:: @ 82660A6
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

BattleFrontier_Lounge7_Text_2660D0:: @ 82660D0
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"

BattleFrontier_Lounge7_Text_2660FF:: @ 82660FF
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleFrontier_Lounge7_Text_26612D:: @ 826612D
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

BattleFrontier_Lounge7_Text_26615F:: @ 826615F
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_266185:: @ 8266185
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_2661B5:: @ 82661B5
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"

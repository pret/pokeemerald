BattleFrontier_Lounge3_MapScripts:: @ 8261D82
	.byte 0

BattleFrontier_Lounge3_EventScript_261D83:: @ 8261D83
	lock
	faceplayer
	checkflag FLAG_0x157
	goto_eq BattleFrontier_Lounge3_EventScript_261EF9
	call BattleFrontier_Lounge3_EventScript_261EA0
	compare_var_to_value VAR_0x8004, 2
	goto_if 3, BattleFrontier_Lounge3_EventScript_261EEB
	setflag FLAG_0x157
	msgbox BattleFrontier_Lounge3_Text_262061, 4
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261DAF:: @ 8261DAF
	special sub_813A820
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_262A60, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_Lounge3_EventScript_261FA5
	msgbox BattleFrontier_Lounge3_Text_262ABD, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_Lounge3_EventScript_261FA5
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	special sub_813A958
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261DE9:: @ 8261DE9
	multichoice 20, 4, 87, 0
	copyvar VAR_0x4032, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge3_EventScript_261E30
	case 1, BattleFrontier_Lounge3_EventScript_261E3B
	case 2, BattleFrontier_Lounge3_EventScript_261E46
	case 3, BattleFrontier_Lounge3_EventScript_261FAF
	case 127, BattleFrontier_Lounge3_EventScript_261FAF
	end

BattleFrontier_Lounge3_EventScript_261E30:: @ 8261E30
	setvar VAR_0x8008, 5
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E3B:: @ 8261E3B
	setvar VAR_0x8008, 10
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E46:: @ 8261E46
	setvar VAR_0x8008, 15
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E51:: @ 8261E51
	specialvar VAR_0x4001, sub_813AA04
	compare_var_to_var VAR_0x4001, VAR_0x8008
	goto_if 4, BattleFrontier_Lounge3_EventScript_261E75
	msgbox BattleFrontier_Lounge3_Text_262B6E, 4
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261E75:: @ 8261E75
	copyvar VAR_0x8004, VAR_0x8008
	special sub_813A9A4
	setvar VAR_0x4033, 1
	special sub_813A8FC
	playse SE_REGI
	msgbox BattleFrontier_Lounge3_Text_262BE0, 4
	goto BattleFrontier_Lounge3_EventScript_261E96
	end

BattleFrontier_Lounge3_EventScript_261E96:: @ 8261E96
	special sub_813A854
	waitmessage
	waitbuttonpress
	special sub_813A988
	release
	end

BattleFrontier_Lounge3_EventScript_261EA0:: @ 8261EA0
	setvar VAR_0x8004, 0
	checkflag FLAG_SYS_TOWER_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_DOME_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_PALACE_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_ARENA_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_FACTORY_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_PIKE_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	checkflag FLAG_SYS_PYRAMID_SILVER
	call_if 1, BattleFrontier_Lounge3_EventScript_261EE5
	return

BattleFrontier_Lounge3_EventScript_261EE5:: @ 8261EE5
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_261EEB:: @ 8261EEB
	msgbox BattleFrontier_Lounge3_Text_261FFE, 4
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261EF9:: @ 8261EF9
	msgbox BattleFrontier_Lounge3_Text_26346B, 4
	compare_var_to_value VAR_0x4033, 1
	goto_if 4, BattleFrontier_Lounge3_EventScript_261F12
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261F12:: @ 8261F12
	compare_var_to_value VAR_0x4033, 1
	goto_eq BattleFrontier_Lounge3_EventScript_261F9E
	compare_var_to_value VAR_0x4033, 2
	goto_eq BattleFrontier_Lounge3_EventScript_261F2E
	goto BattleFrontier_Lounge3_EventScript_261F71
	end

BattleFrontier_Lounge3_EventScript_261F2E:: @ 8261F2E
	msgbox BattleFrontier_Lounge3_Text_263334, 4
	compare_var_to_value VAR_0x4032, 0
	call_if 1, BattleFrontier_Lounge3_EventScript_261F80
	compare_var_to_value VAR_0x4032, 1
	call_if 1, BattleFrontier_Lounge3_EventScript_261F8A
	compare_var_to_value VAR_0x4032, 2
	call_if 1, BattleFrontier_Lounge3_EventScript_261F94
	msgbox BattleFrontier_Lounge3_Text_2633D4, 9
	special sub_813A9D0
	msgbox BattleFrontier_Lounge3_Text_2633F2, 4
	setvar VAR_0x4033, 0
	release
	end

BattleFrontier_Lounge3_EventScript_261F71:: @ 8261F71
	msgbox BattleFrontier_Lounge3_Text_263298, 4
	setvar VAR_0x4033, 0
	release
	end

BattleFrontier_Lounge3_EventScript_261F80:: @ 8261F80
	buffernumberstring 0, 10
	setvar VAR_0x8004, 10
	return

BattleFrontier_Lounge3_EventScript_261F8A:: @ 8261F8A
	buffernumberstring 0, 20
	setvar VAR_0x8004, 20
	return

BattleFrontier_Lounge3_EventScript_261F94:: @ 8261F94
	buffernumberstring 0, 30
	setvar VAR_0x8004, 30
	return

BattleFrontier_Lounge3_EventScript_261F9E:: @ 8261F9E
	special sub_813A854
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_261FA5:: @ 8261FA5
	msgbox BattleFrontier_Lounge3_Text_26342D, 4
	release
	end

BattleFrontier_Lounge3_EventScript_261FAF:: @ 8261FAF
	special sub_813A988
	goto BattleFrontier_Lounge3_EventScript_261FA5
	end

BattleFrontier_Lounge3_EventScript_261FB8:: @ 8261FB8
	msgbox BattleFrontier_Lounge3_Text_263545, 2
	end

BattleFrontier_Lounge3_EventScript_261FC1:: @ 8261FC1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26346F, 4
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FD1:: @ 8261FD1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26351D, 4
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FE1:: @ 8261FE1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_2634C9, 4
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FF1:: @ 8261FF1
	closemessage
	applymovement VAR_LAST_TALKED, BattleFrontier_Lounge3_Movement_2725A2
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_261FFE: @ 8261FFE
	.string "…What’s that you want?\p"
	.string "Can’t you see we’re kind of busy here?\n"
	.string "Can’t your business wait till later?$"

BattleFrontier_Lounge3_Text_262061: @ 8262061
	.string "…Huh?\n"
	.string "You look to me like a tough TRAINER.\p"
	.string "Heheh…\n"
	.string "Listen, I have this proposition.\p"
	.string "We have a little group going here,\n"
	.string "and we play a little game with what\l"
	.string "goes on in the BATTLE FRONTIER.\p"
	.string "The rules are really simple.\p"
	.string "First, we pick one of the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Then, we each pick a different TRAINER\n"
	.string "who’s taking that facility’s challenge,\l"
	.string "and bet with our Battle Points.\p"
	.string "The guy who bet on the TRAINER with\n"
	.string "the best record takes all the Battle\l"
	.string "Points in the pool.\p"
	.string "Sounds simple, huh?\n"
	.string "So, anyway…$"

	.incbin "baserom.gba", 0x262261, 0x7ff

BattleFrontier_Lounge3_Text_262A60: @ 8262A60
	.string "I’ll see to it that you benefit, too.\n"
	.string "So how about it?\l"
	.string "How about entering that event for me?$"

BattleFrontier_Lounge3_Text_262ABD: @ 8262ABD
	.string "All right, that’s perfect.\n"
	.string "So, uh… How about spotting me some\l"
	.string "of your Battle Points?\p"
	.string "Trust me, I’ll show you my gratitude\n"
	.string "afterward.$"

BattleFrontier_Lounge3_Text_262B42: @ 8262B42
	.string "Great, great!\n"
	.string "So, how much can you spot me?$"

BattleFrontier_Lounge3_Text_262B6E: @ 8262B6E
	.string "Oh, no, no, no!\n"
	.string "You don’t have enough Battle Points!\p"
	.string "I wish you wouldn’t monkey around and\n"
	.string "waste everyone’s time!$"

BattleFrontier_Lounge3_Text_262BE0: @ 8262BE0
	.string "Heheh! Thanks much!\n"
	.string "So, off you go!$"

	.incbin "baserom.gba", 0x262c04, 0x694

BattleFrontier_Lounge3_Text_263298: @ 8263298
	.string "Oh, it’s you…\n"
	.string "Nice try…\p"
	.string "I hate to break it to you, but I can’t\n"
	.string "return your Battle Points…\p"
	.string "I guess we’ll have to let it motivate\n"
	.string "us to try harder next time!$"

BattleFrontier_Lounge3_Text_263334: @ 8263334
	.string "Oh, yes!\n"
	.string "Hello there, champ!\p"
	.string "I knew you could!\n"
	.string "I knew you would!\l"
	.string "We’re both big winners!\p"
	.string "I’ll return your Battle Points and,\n"
	.string "of course, a little extra from me!$"

BattleFrontier_Lounge3_Text_2633D4: @ 82633D4
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Points.$"

BattleFrontier_Lounge3_Text_2633F2: @ 82633F2
	.string "If you’re up for another challenge,\n"
	.string "please do think of me!$"

BattleFrontier_Lounge3_Text_26342D: @ 826342D
	.string "Not interested?! You shouldn’t be\n"
	.string "so afraid to take a chance!$"

BattleFrontier_Lounge3_Text_26346B: @ 826346B
	.string "Oh…$"

BattleFrontier_Lounge3_Text_26346F: @ 826346F
	.string "I backed the wrong TRAINER again!\p"
	.string "Maybe I should be battling normally\n"
	.string "like everyone else…$"

BattleFrontier_Lounge3_Text_2634C9: @ 82634C9
	.string "That TRAINER…\p"
	.string "He’s good, but he gets rattled too\n"
	.string "easily to survive the BATTLE DOME…$"

BattleFrontier_Lounge3_Text_26351D: @ 826351D
	.string "Giggle!\n"
	.string "I know a winner when I see one!$"

BattleFrontier_Lounge3_Text_263545: @ 8263545
	.string "Those TRAINERS…\n"
	.string "What are they doing?\l"
	.string "They should be taking challenges.$"


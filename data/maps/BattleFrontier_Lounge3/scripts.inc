BattleFrontier_Lounge3_MapScripts:: @ 8261D82
	.byte 0

BattleFrontier_Lounge3_EventScript_261D83:: @ 8261D83
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_BETTOR, BattleFrontier_Lounge3_EventScript_261EF9
	call BattleFrontier_Lounge3_EventScript_261EA0
	compare VAR_0x8004, 2
	goto_if_le BattleFrontier_Lounge3_EventScript_261EEB
	setflag FLAG_MET_BATTLE_FRONTIER_BETTOR
	msgbox BattleFrontier_Lounge3_Text_262061, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261DAF:: @ 8261DAF
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_262A60, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge3_EventScript_261FA5
	msgbox BattleFrontier_Lounge3_Text_262ABD, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge3_EventScript_261FA5
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261DE9:: @ 8261DE9
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, 0
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_261E30
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_261E3B
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_261E46
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_261FAF
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_261FAF
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
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_Lounge3_EventScript_261E75
	msgbox BattleFrontier_Lounge3_Text_262B6E, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261E75:: @ 8261E75
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_REGI
	msgbox BattleFrontier_Lounge3_Text_262BE0, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261E96
	end

BattleFrontier_Lounge3_EventScript_261E96:: @ 8261E96
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_261EA0:: @ 8261EA0
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	return

BattleFrontier_Lounge3_EventScript_261EE5:: @ 8261EE5
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_261EEB:: @ 8261EEB
	msgbox BattleFrontier_Lounge3_Text_261FFE, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261EF9:: @ 8261EF9
	msgbox BattleFrontier_Lounge3_Text_26346B, MSGBOX_DEFAULT
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	goto_if_ge BattleFrontier_Lounge3_EventScript_261F12
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261F12:: @ 8261F12
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	goto_if_eq BattleFrontier_Lounge3_EventScript_261F9E
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON
	goto_if_eq BattleFrontier_Lounge3_EventScript_261F2E
	goto BattleFrontier_Lounge3_EventScript_261F71
	end

BattleFrontier_Lounge3_EventScript_261F2E:: @ 8261F2E
	msgbox BattleFrontier_Lounge3_Text_263334, MSGBOX_DEFAULT
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5
	call_if_eq BattleFrontier_Lounge3_EventScript_261F80
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10
	call_if_eq BattleFrontier_Lounge3_EventScript_261F8A
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15
	call_if_eq BattleFrontier_Lounge3_EventScript_261F94
	msgbox BattleFrontier_Lounge3_Text_2633D4, 9
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_2633F2, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_261F71:: @ 8261F71
	msgbox BattleFrontier_Lounge3_Text_263298, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
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
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_261FA5:: @ 8261FA5
	msgbox BattleFrontier_Lounge3_Text_26342D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_261FAF:: @ 8261FAF
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_261FA5
	end

BattleFrontier_Lounge3_EventScript_261FB8:: @ 8261FB8
	msgbox BattleFrontier_Lounge3_Text_263545, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_261FC1:: @ 8261FC1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26346F, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FD1:: @ 8261FD1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26351D, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FE1:: @ 8261FE1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_2634C9, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FF1:: @ 8261FF1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_261FFE:: @ 8261FFE
	.string "…What's that you want?\p"
	.string "Can't you see we're kind of busy here?\n"
	.string "Can't your business wait till later?$"

BattleFrontier_Lounge3_Text_262061:: @ 8262061
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
	.string "who's taking that facility's challenge,\l"
	.string "and bet with our Battle Points.\p"
	.string "The guy who bet on the TRAINER with\n"
	.string "the best record takes all the Battle\l"
	.string "Points in the pool.\p"
	.string "Sounds simple, huh?\n"
	.string "So, anyway…$"

BattleFrontier_Lounge3_Text_262261:: @ 8262261
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's SINGLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_26230D:: @ 826230D
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's DOUBLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_2623B9:: @ 82623B9
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's MULTI BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_262464:: @ 8262464
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's SINGLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_26250E:: @ 826250E
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's DOUBLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_2625B8:: @ 82625B8
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Single Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_26266A:: @ 826266A
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Double Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_26271C:: @ 826271C
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's SINGLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_2627C9:: @ 82627C9
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's DOUBLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_262876:: @ 8262876
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "ARENA's Set KO Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_26291A:: @ 826291A
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE PIKE's\l"
	.string "Battle Choice.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_2629BC:: @ 82629BC
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "PYRAMID's Battle Quest.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_262A60:: @ 8262A60
	.string "I'll see to it that you benefit, too.\n"
	.string "So how about it?\l"
	.string "How about entering that event for me?$"

BattleFrontier_Lounge3_Text_262ABD:: @ 8262ABD
	.string "All right, that's perfect.\n"
	.string "So, uh… How about spotting me some\l"
	.string "of your Battle Points?\p"
	.string "Trust me, I'll show you my gratitude\n"
	.string "afterward.$"

BattleFrontier_Lounge3_Text_262B42:: @ 8262B42
	.string "Great, great!\n"
	.string "So, how much can you spot me?$"

BattleFrontier_Lounge3_Text_262B6E:: @ 8262B6E
	.string "Oh, no, no, no!\n"
	.string "You don't have enough Battle Points!\p"
	.string "I wish you wouldn't monkey around and\n"
	.string "waste everyone's time!$"

BattleFrontier_Lounge3_Text_262BE0:: @ 8262BE0
	.string "Heheh! Thanks much!\n"
	.string "So, off you go!$"

BattleFrontier_Lounge3_Text_262C04:: @ 8262C04
	.string "Get to the BATTLE TOWER's\n"
	.string "SINGLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262C90:: @ 8262C90
	.string "Get to the BATTLE TOWER's\n"
	.string "DOUBLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262D1C:: @ 8262D1C
	.string "Get to the BATTLE TOWER's\n"
	.string "MULTI BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262DA7:: @ 8262DA7
	.string "Get to the BATTLE DOME's\n"
	.string "SINGLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262E34:: @ 8262E34
	.string "Get to the BATTLE DOME's\n"
	.string "DOUBLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262EC1:: @ 8262EC1
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Single Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262F56:: @ 8262F56
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Double Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_262FEB:: @ 8262FEB
	.string "Get to the BATTLE PALACE's\n"
	.string "SINGLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_263078:: @ 8263078
	.string "Get to the BATTLE PALACE's\n"
	.string "DOUBLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_263105:: @ 8263105
	.string "Get to the BATTLE ARENA's\n"
	.string "Set KO Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_26318C:: @ 826318C
	.string "Get to the BATTLE PIKE's\n"
	.string "Battle Choice pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_263211:: @ 8263211
	.string "Get to the BATTLE PYRAMID's\n"
	.string "Battle Quest pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_263298:: @ 8263298
	.string "Oh, it's you…\n"
	.string "Nice try…\p"
	.string "I hate to break it to you, but I can't\n"
	.string "return your Battle Points…\p"
	.string "I guess we'll have to let it motivate\n"
	.string "us to try harder next time!$"

BattleFrontier_Lounge3_Text_263334:: @ 8263334
	.string "Oh, yes!\n"
	.string "Hello there, champ!\p"
	.string "I knew you could!\n"
	.string "I knew you would!\l"
	.string "We're both big winners!\p"
	.string "I'll return your Battle Points and,\n"
	.string "of course, a little extra from me!$"

BattleFrontier_Lounge3_Text_2633D4:: @ 82633D4
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Points.$"

BattleFrontier_Lounge3_Text_2633F2:: @ 82633F2
	.string "If you're up for another challenge,\n"
	.string "please do think of me!$"

BattleFrontier_Lounge3_Text_26342D:: @ 826342D
	.string "Not interested?! You shouldn't be\n"
	.string "so afraid to take a chance!$"

BattleFrontier_Lounge3_Text_26346B:: @ 826346B
	.string "Oh…$"

BattleFrontier_Lounge3_Text_26346F:: @ 826346F
	.string "I backed the wrong TRAINER again!\p"
	.string "Maybe I should be battling normally\n"
	.string "like everyone else…$"

BattleFrontier_Lounge3_Text_2634C9:: @ 82634C9
	.string "That TRAINER…\p"
	.string "He's good, but he gets rattled too\n"
	.string "easily to survive the BATTLE DOME…$"

BattleFrontier_Lounge3_Text_26351D:: @ 826351D
	.string "Giggle!\n"
	.string "I know a winner when I see one!$"

BattleFrontier_Lounge3_Text_263545:: @ 8263545
	.string "Those TRAINERS…\n"
	.string "What are they doing?\l"
	.string "They should be taking challenges.$"

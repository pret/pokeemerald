BattleFrontier_ScottsHouse_MapScripts:: @ 82636A7
	.byte 0

BattleFrontier_ScottsHouse_EventScript_2636A8:: @ 82636A8
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_2637DA
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_2638AA
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_263939
	goto BattleFrontier_ScottsHouse_EventScript_2636CB
	end

BattleFrontier_ScottsHouse_EventScript_2636CB:: @ 82636CB
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_263943
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_263704
	goto_if_unset FLAG_RECEIVED_STARF_BERRY_FROM_SCOTT, BattleFrontier_ScottsHouse_EventScript_26376A
	goto BattleFrontier_ScottsHouse_EventScript_2636EC
	end

BattleFrontier_ScottsHouse_EventScript_2636EC:: @ 82636EC
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_26381B
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_2638B4
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_263704:: @ 8263704
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	msgbox BattleFrontier_ScottsHouse_Text_2640BC, MSGBOX_DEFAULT
	giveitem_std ITEM_LANSAT_BERRY
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2637D0
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_26376A:: @ 826376A
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	msgbox BattleFrontier_ScottsHouse_Text_264216, MSGBOX_DEFAULT
	giveitem_std ITEM_STARF_BERRY
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2637D0
	setflag FLAG_RECEIVED_STARF_BERRY_FROM_SCOTT
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637D0:: @ 82637D0
	msgbox BattleFrontier_ScottsHouse_Text_2643EB, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637DA:: @ 82637DA
	msgbox BattleFrontier_ScottsHouse_Text_264373, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637E4:: @ 82637E4
	random 3
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_263807
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_263811
	msgbox BattleFrontier_ScottsHouse_Text_263DDD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263807:: @ 8263807
	msgbox BattleFrontier_ScottsHouse_Text_263F12, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263811:: @ 8263811
	msgbox BattleFrontier_ScottsHouse_Text_263FFE, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_26381B:: @ 826381B
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 50
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_26387A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 50
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_26387A
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_26387A:: @ 826387A
	msgbox BattleFrontier_ScottsHouse_Text_264412, MSGBOX_DEFAULT
	givedecoration_std DECOR_SILVER_SHIELD
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2638A0
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_2638AA
	end

BattleFrontier_ScottsHouse_EventScript_2638A0:: @ 82638A0
	msgbox BattleFrontier_ScottsHouse_Text_264583, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2638AA:: @ 82638AA
	msgbox BattleFrontier_ScottsHouse_Text_264546, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2638B4:: @ 82638B4
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 100
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_263913
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 100
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_263913
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_263913:: @ 8263913
	msgbox BattleFrontier_ScottsHouse_Text_26449F, MSGBOX_DEFAULT
	givedecoration_std DECOR_GOLD_SHIELD
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2638A0
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_2638AA
	end

BattleFrontier_ScottsHouse_EventScript_263939:: @ 8263939
	msgbox BattleFrontier_ScottsHouse_Text_263DB8, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263943:: @ 8263943
	msgbox BattleFrontier_ScottsHouse_Text_263A3F, MSGBOX_DEFAULT
	closemessage
	delay 30
	compare VAR_FACING, 2
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A13
	compare VAR_FACING, 1
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A1E
	compare VAR_FACING, 4
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A29
	compare VAR_FACING, 3
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A34
	msgbox BattleFrontier_ScottsHouse_Text_263B29, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_263BD4, MSGBOX_DEFAULT
	compare VAR_SCOTT_STATE, 13
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2639BC
	compare VAR_SCOTT_STATE, 9
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_2639CB
	compare VAR_SCOTT_STATE, 6
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_2639DA
	goto BattleFrontier_ScottsHouse_EventScript_2639E9
	end

BattleFrontier_ScottsHouse_EventScript_2639BC:: @ 82639BC
	buffernumberstring 0, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639CB:: @ 82639CB
	buffernumberstring 0, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639DA:: @ 82639DA
	buffernumberstring 0, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639E9:: @ 82639E9
	buffernumberstring 0, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639F8:: @ 82639F8
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_263CB0, 9
	msgbox BattleFrontier_ScottsHouse_Text_263CD0, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_263A13:: @ 8263A13
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A1E:: @ 8263A1E
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A29:: @ 8263A29
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A34:: @ 8263A34
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_263A3F: @ 8263A3F
	.string "SCOTT: Well, hello and welcome!\n"
	.string "Heheh… Sorry about the cramped space.\p"
	.string "Anyway, {PLAYER}{KUN}, let me formally\n"
	.string "welcome you to the BATTLE FRONTIER.\p"
	.string "This is my dream come true.\n"
	.string "It took me years and years, but I've\l"
	.string "finally given shape to my dream.$"

BattleFrontier_ScottsHouse_Text_263B29: @ 8263B29
	.string "On reflection, it was a terribly long\n"
	.string "journey…\p"
	.string "I left home alone on a quest to find\n"
	.string "strong TRAINERS.\p"
	.string "No one can imagine how much effort\n"
	.string "or time it took to make this real.$"

BattleFrontier_ScottsHouse_Text_263BD4: @ 8263BD4
	.string "But that's all in the past.\n"
	.string "No point dwelling on that!\p"
	.string "All I want for you is to enjoy battling\n"
	.string "to your heart's content here.\p"
	.string "{PLAYER}{KUN}, I want you to have this\n"
	.string "as a memento for all the time our\l"
	.string "paths crossed on our journeys.$"

BattleFrontier_ScottsHouse_Text_263CB0: @ 8263CB0
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Point(s).$"

BattleFrontier_ScottsHouse_Text_263CD0: @ 8263CD0
	.string "SCOTT: You can check your Battle\n"
	.string "Points on your FRONTIER PASS.\p"
	.string "The more success you have here at\n"
	.string "the BATTLE FRONTIER, the more Battle\l"
	.string "Points you will collect.\p"
	.string "Use your Battle Points the way you\n"
	.string "see fit, like trading them for items.$"

BattleFrontier_ScottsHouse_Text_263DB8: @ 8263DB8
	.string "I'm expecting great things from you!$"

BattleFrontier_ScottsHouse_Text_263DDD: @ 8263DDD
	.string "SCOTT: Every TRAINER is an individual.\n"
	.string "They all lead lives of their own.\p"
	.string "But when they're in a battle,\n"
	.string "it doesn't matter who they are.\p"
	.string "They're all the same!\p"
	.string "I love the purity of battle,\n"
	.string "where everyone is equal.\p"
	.string "That's why I go everywhere seeking\n"
	.string "TRAINERS who are serious about\l"
	.string "battling, and invite them here.$"

BattleFrontier_ScottsHouse_Text_263F12: @ 8263F12
	.string "SCOTT: Have you met any of\n"
	.string "the FRONTIER BRAINS?\p"
	.string "Better yet, have you obtained any\n"
	.string "symbols from them?\p"
	.string "I handpicked the FRONTIER BRAINS\n"
	.string "as the toughest TRAINERS anywhere.\p"
	.string "But I'm sure that seeing how tough\n"
	.string "you are will startle even them!$"

BattleFrontier_ScottsHouse_Text_263FFE: @ 8263FFE
	.string "SCOTT: You don't just train for battle,\n"
	.string "right?\p"
	.string "I think I remember you working on\n"
	.string "a POKéDEX as well.\p"
	.string "Well, guess what?\p"
	.string "You may run into wild POKéMON in\n"
	.string "the BATTLE FRONTIER somewhere…\l"
	.string "Fufufu!$"

BattleFrontier_ScottsHouse_Text_2640BC: @ 82640BC
	.string "SCOTT: Are you enjoying things in\n"
	.string "the BATTLE FRONTIER?\p"
	.string "…Wait a second…\n"
	.string "Oh!\p"
	.string "Your FRONTIER PASS!\n"
	.string "You've collected the full set\l"
	.string "of silver symbols!\p"
	.string "That's more than impressive!\n"
	.string "You are tough, just as I suspected!\p"
	.string "Normally, I wouldn't do something\n"
	.string "like this, but this is a special time!\p"
	.string "I want you to have this.\n"
	.string "I'm sure you can put it to proper use.$"

BattleFrontier_ScottsHouse_Text_264216: @ 8264216
	.string "SCOTT: I hope you're enjoying\n"
	.string "everything in the BATTLE FRONTIER.\p"
	.string "…Wait a second…\n"
	.string "Oh, my disbelieving eyes!\p"
	.string "Your FRONTIER PASS!\n"
	.string "You've gathered up the full set\l"
	.string "of gold symbols!\p"
	.string "That's more than stupendous!\n"
	.string "You're incredible, just as I suspected!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, you've got to accept this!\p"
	.string "I think you will be able to\n"
	.string "appreciate the value of my gift!$"

BattleFrontier_ScottsHouse_Text_264373: @ 8264373
	.string "I must say I have the gift of knowing\n"
	.string "a good TRAINER when I see one.\p"
	.string "I'm so glad I had the foresight to\n"
	.string "bring you here!$"

BattleFrontier_ScottsHouse_Text_2643EB: @ 82643EB
	.string "Your BERRY POCKET seems to\n"
	.string "be stuffed.$"

BattleFrontier_ScottsHouse_Text_264412: @ 8264412
	.string "SCOTT: Oh, I heard about you!\n"
	.string "How you ruled the BATTLE TOWER!\l"
	.string "You beat over 50 TRAINERS in a row?\p"
	.string "That's fantastic!\n"
	.string "I want you to have this!$"

BattleFrontier_ScottsHouse_Text_26449F: @ 826449F
	.string "SCOTT: Oh, my! I heard about you!\n"
	.string "How you overwhelmed the BATTLE TOWER!\l"
	.string "You beat over 100 TRAINERS in a row?\p"
	.string "That's ridiculously spectacular!\n"
	.string "You've got to have this!$"

BattleFrontier_ScottsHouse_Text_264546: @ 8264546
	.string "I'll be expecting to hear even greater\n"
	.string "things about you now!$"

BattleFrontier_ScottsHouse_Text_264583: @ 8264583
	.string "Oops, well, if you have too much\n"
	.string "stuff, come back for this later.$"


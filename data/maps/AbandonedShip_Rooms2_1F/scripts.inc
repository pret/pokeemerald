AbandonedShip_Rooms2_1F_MapScripts:: @ 82380A6
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_2380A7:: @ 82380A7
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_23819D, AbandonedShip_Rooms2_1F_Text_2381DA, AbandonedShip_Rooms2_1F_Text_238257, AbandonedShip_Rooms2_1F_EventScript_2380D7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_2380F0
	msgbox AbandonedShip_Rooms2_1F_Text_23820F, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380D7:: @ 82380D7
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380F0:: @ 82380F0
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2383FF, AbandonedShip_Rooms2_1F_Text_238473, AbandonedShip_Rooms2_1F_Text_238509
	msgbox AbandonedShip_Rooms2_1F_Text_238491, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23810B:: @ 823810B
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2382A4, AbandonedShip_Rooms2_1F_Text_2382F4, AbandonedShip_Rooms2_1F_Text_23836F, AbandonedShip_Rooms2_1F_EventScript_23813B
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_238154
	msgbox AbandonedShip_Rooms2_1F_Text_23830A, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_23813B:: @ 823813B
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_238154:: @ 8238154
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_238556, AbandonedShip_Rooms2_1F_Text_2385F2, AbandonedShip_Rooms2_1F_Text_238668
	msgbox AbandonedShip_Rooms2_1F_Text_23860B, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23816F:: @ 823816F
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_2386B4, AbandonedShip_Rooms2_1F_Text_2386E8
	msgbox AbandonedShip_Rooms2_1F_Text_238708, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_238186:: @ 8238186
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_23873F, AbandonedShip_Rooms2_1F_Text_238779
	msgbox AbandonedShip_Rooms2_1F_Text_2387A9, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_23819D: @ 823819D
	.string "DAN: While searching for treasures,\n"
	.string "we discovered a TRAINER!$"

AbandonedShip_Rooms2_1F_Text_2381DA: @ 82381DA
	.string "DAN: We couldn't win even though\n"
	.string "we worked together…$"

AbandonedShip_Rooms2_1F_Text_23820F: @ 823820F
	.string "DAN: We can't find any treasures…\n"
	.string "I wonder if someone got them already?$"

AbandonedShip_Rooms2_1F_Text_238257: @ 8238257
	.string "DAN: You don't even have two POKéMON.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_2382A4: @ 82382A4
	.string "KIRA: Oh?\n"
	.string "We were searching for treasures.\l"
	.string "But we discovered a TRAINER instead!$"

AbandonedShip_Rooms2_1F_Text_2382F4: @ 82382F4
	.string "KIRA: Ooh, so strong!$"

AbandonedShip_Rooms2_1F_Text_23830A: @ 823830A
	.string "KIRA: Where could the treasures be?\p"
	.string "I've already decided what I'm buying\n"
	.string "when we find the treasures!$"

AbandonedShip_Rooms2_1F_Text_23836F: @ 823836F
	.string "KIRA: Oh, you don't have two POKéMON?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_2383BB: @ 82383BB
	.string "KIRA: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"

AbandonedShip_Rooms2_1F_Text_2383FF: @ 82383FF
	.string "DAN: We've been searching for\n"
	.string "treasures all this time.\p"
	.string "Our POKéMON have grown stronger, too.\n"
	.string "Let us show you, okay?$"

AbandonedShip_Rooms2_1F_Text_238473: @ 8238473
	.string "DAN: You're strong, as usual!$"

AbandonedShip_Rooms2_1F_Text_238491: @ 8238491
	.string "DAN: We can't find any treasures,\n"
	.string "we lose at POKéMON…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"

AbandonedShip_Rooms2_1F_Text_238509: @ 8238509
	.string "DAN: You don't even have two POKéMON.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_238556: @ 8238556
	.string "KIRA: Oh? We meet again!\p"
	.string "Just like us, you still haven't given up\n"
	.string "searching for treasures, have you?\p"
	.string "Want to make it so the loser has\n"
	.string "to give up searching?$"

AbandonedShip_Rooms2_1F_Text_2385F2: @ 82385F2
	.string "KIRA: Oh, we lost again…$"

AbandonedShip_Rooms2_1F_Text_23860B: @ 823860B
	.string "KIRA: We're not leaving until we raise\n"
	.string "our POKéMON some more and we find\l"
	.string "the treasures here!$"

AbandonedShip_Rooms2_1F_Text_238668: @ 8238668
	.string "KIRA: Oh, you don't have two POKéMON?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_2386B4: @ 82386B4
	.string "I'm not good at swimming,\n"
	.string "but I am good at battles!$"

AbandonedShip_Rooms2_1F_Text_2386E8: @ 82386E8
	.string "Oops.\n"
	.string "That didn't go very well.$"

AbandonedShip_Rooms2_1F_Text_238708: @ 8238708
	.string "Walking around barefoot in this ship\n"
	.string "is kind of gross.$"

AbandonedShip_Rooms2_1F_Text_23873F: @ 823873F
	.string "Strength and compassion…\n"
	.string "Those are a TRAINER's treasures!$"

AbandonedShip_Rooms2_1F_Text_238779: @ 8238779
	.string "Ah, there is something about you\n"
	.string "that sparkles.$"

AbandonedShip_Rooms2_1F_Text_2387A9: @ 82387A9
	.string "In a cabin somewhere on board,\n"
	.string "I saw something sparkle.$"

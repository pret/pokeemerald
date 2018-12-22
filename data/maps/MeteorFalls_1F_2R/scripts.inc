MeteorFalls_1F_2R_MapScripts:: @ 822C4DD
	.byte 0

MeteorFalls_1F_2R_EventScript_22C4DE:: @ 822C4DE
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_22C608, MeteorFalls_1F_2R_Text_22C678, MeteorFalls_1F_2R_EventScript_22C50A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C529
	msgbox MeteorFalls_1F_2R_Text_22C6A3, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C50A:: @ 822C50A
	special sub_80B4808
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_22C6F6, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C529:: @ 822C529
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_22C73F, MeteorFalls_1F_2R_Text_22C7AD
	msgbox MeteorFalls_1F_2R_Text_22C7D8, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_22C540:: @ 822C540
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22C843, MeteorFalls_1F_2R_Text_22C89C, MeteorFalls_1F_2R_Text_22C92B, MeteorFalls_1F_2R_EventScript_22C570
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C589
	msgbox MeteorFalls_1F_2R_Text_22C8C1, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C570:: @ 822C570
	msgbox MeteorFalls_1F_2R_Text_22C99C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C589:: @ 822C589
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22CB47, MeteorFalls_1F_2R_Text_22CBA0, MeteorFalls_1F_2R_Text_22CC27
	msgbox MeteorFalls_1F_2R_Text_22CBC5, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_22C5A4:: @ 822C5A4
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22C9E6, MeteorFalls_1F_2R_Text_22CA44, MeteorFalls_1F_2R_Text_22CACD, MeteorFalls_1F_2R_EventScript_22C5D4
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C5ED
	msgbox MeteorFalls_1F_2R_Text_22CA70, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C5D4:: @ 822C5D4
	msgbox MeteorFalls_1F_2R_Text_22C99C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C5ED:: @ 822C5ED
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22CC98, MeteorFalls_1F_2R_Text_22CD08, MeteorFalls_1F_2R_Text_22CDAB
	msgbox MeteorFalls_1F_2R_Text_22CD34, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_22C608: @ 822C608
	.string "This is where we DRAGON users do our\n"
	.string "training.\p"
	.string "The CHAMPION even visits.\n"
	.string "Now do you see how special it is here?$"

MeteorFalls_1F_2R_Text_22C678: @ 822C678
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_22C6A3: @ 822C6A3
	.string "The road ahead remains long and harsh.\p"
	.string "When will my POKéMON and I become\n"
	.string "the best?$"

MeteorFalls_1F_2R_Text_22C6F6: @ 822C6F6
	.string "I want to know more about your power.\n"
	.string "Let me register you in my POKéNAV.$"

MeteorFalls_1F_2R_Text_22C73F: @ 822C73F
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"

MeteorFalls_1F_2R_Text_22C7AD: @ 822C7AD
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_22C7D8: @ 822C7D8
	.string "You've obviously kept up your\n"
	.string "POKéMON training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"

MeteorFalls_1F_2R_Text_22C843: @ 822C843
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"

MeteorFalls_1F_2R_Text_22C89C: @ 822C89C
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"

MeteorFalls_1F_2R_Text_22C8C1: @ 822C8C1
	.string "JOHN: We've been married for\n"
	.string "fifty years.\p"
	.string "Come to think of it, I've yet to beat\n"
	.string "my dear wife in a battle.$"

MeteorFalls_1F_2R_Text_22C92B: @ 822C92B
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"

MeteorFalls_1F_2R_Text_22C99C: @ 822C99C
	.string "JOHN: Young TRAINER, if the chance\n"
	.string "arises, will you battle with us again?$"

MeteorFalls_1F_2R_Text_22C9E6: @ 822C9E6
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "The bond we share as a couple could\n"
	.string "never be broken.$"

MeteorFalls_1F_2R_Text_22CA44: @ 822CA44
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_22CA70: @ 822CA70
	.string "JAY: Fifty years of marriage…\p"
	.string "If we ever argued, we always settled\n"
	.string "it with a POKéMON battle…$"

MeteorFalls_1F_2R_Text_22CACD: @ 822CACD
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"

MeteorFalls_1F_2R_Text_22CB47: @ 822CB47
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"

MeteorFalls_1F_2R_Text_22CBA0: @ 822CBA0
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"

MeteorFalls_1F_2R_Text_22CBC5: @ 822CBC5
	.string "JOHN: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"

MeteorFalls_1F_2R_Text_22CC27: @ 822CC27
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"

MeteorFalls_1F_2R_Text_22CC98: @ 822CC98
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "We've supported each other all that\n"
	.string "time. We've made ourselves strong.$"

MeteorFalls_1F_2R_Text_22CD08: @ 822CD08
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_22CD34: @ 822CD34
	.string "JAY: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"

MeteorFalls_1F_2R_Text_22CDAB: @ 822CDAB
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"


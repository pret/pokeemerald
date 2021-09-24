MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "This is where we Dragon users do our\n"
	.string "training.\p"
	.string "The Champion even visits.\n"
	.string "Now do you see how special it is here?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "The road ahead remains long and harsh.\p"
	.string "When will my Pokémon and I become\n"
	.string "the best?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "I want to know more about your power.\n"
	.string "Let me register you in my Pokénav.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "You've obviously kept up your\n"
	.string "Pokémon training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "John: We've always battled Pokémon\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "John: Oh, my.\n"
	.string "We've lost, dear wife.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "John: We've been married for\n"
	.string "fifty years.\p"
	.string "Come to think of it, I've yet to beat\n"
	.string "my dear wife in a battle.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "John: Well, well, what a young Trainer!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "John: Young Trainer, if the chance\n"
	.string "arises, will you battle with us again?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "Jay: We've been married for\n"
	.string "fifty years.\p"
	.string "The bond we share as a couple could\n"
	.string "never be broken.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "Jay: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "Jay: Fifty years of marriage…\p"
	.string "If we ever argued, we always settled\n"
	.string "it with a Pokémon battle…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "Jay: Well, well, aren't you a young\n"
	.string "Trainer?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "John: We've always battled Pokémon\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "John: Oh, my.\n"
	.string "We've lost, dear wife.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "John: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "John: Well, well, what a young Trainer!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more Pokémon.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "Jay: We've been married for\n"
	.string "fifty years.\p"
	.string "We've supported each other all that\n"
	.string "time. We've made ourselves strong.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "Jay: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "Jay: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "Jay: Well, well, aren't you a young\n"
	.string "Trainer?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more Pokémon.$"


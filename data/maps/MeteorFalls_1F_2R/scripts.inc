MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
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
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
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
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
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
	.string "C’est ici que nous, adeptes des dragons,\n"
	.string "nous entraînons.\p"
	.string "Même le MAITRE nous a rendu visite.\n"
	.string "Tu vois comme c’est spécial ici?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Arrgh!\n"
	.string "Je n’imaginais pas ta force si grande!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "La route est encore longue et difficile.\p"
	.string "Quand deviendrons-nous les meilleurs,\n"
	.string "mes POKéMON et moi?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Je veux en savoir plus sur ta puissance.\n"
	.string "Laisse-moi t’enregistrer dans mon\l"
	.string "POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Depuis notre rencontre, on s’est\n"
	.string "entraînés dur pour devenir numéro un.\p"
	.string "Donne-nous la possibilité de voir à quel\n"
	.string "point notre puissance a augmenté!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Arrgh!\n"
	.string "Je n’imaginais pas ta force si grande!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Il est évident que tu as poursuivi\n"
	.string "l’entraînement de tes POKéMON.\p"
	.string "Aussi longtemps que tu seras solide,\n"
	.string "je pourrai, moi aussi, l’être davantage!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: On a toujours fait des combats\n"
	.string "de POKéMON ensemble.\p"
	.string "On a confiance l’un en l’autre.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Oh, non!\n"
	.string "On a perdu, ma douce.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Et il faut que je livre un combat contre\n"
	.string "ma propre femme. Tu imagines?$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Eh bien, quel jeune DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si oui, il\n"
	.string "faudra revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Jeune DRESSEUR, nous\n"
	.string "affronteras-tu de nouveau si la\l"
	.string "chance se présente?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Le lien qui nous unit en tant que couple\n"
	.string "ne pourra jamais être rompu.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oh non!\n"
	.string "On a perdu, mon cher époux.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Cinquante ans de mariage…\p"
	.string "Quand on n’est pas d’accord, on règle\n"
	.string "toujours ça par un combat de POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Tu es un jeune DRESSEUR, hein?\p"
	.string "Pour te battre contre nous, il faut que\n"
	.string "tu reviennes avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: On a toujours fait des combats\n"
	.string "de POKéMON ensemble.\p"
	.string "On a confiance l’un en l’autre.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Oh, non!\n"
	.string "On a perdu, ma douce.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Cinquante ans de mariage…\p"
	.string "A la réflexion, ma chère femme et moi,\n"
	.string "on s’est battus jour après jour…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Eh bien, quel jeune DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si oui, il\n"
	.string "faudra revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "On s’est toujours soutenus.\n"
	.string "Ça nous a rendus forts.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oh non!\n"
	.string "On a perdu, mon cher époux.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Cinquante ans de mariage…\n"
	.string "Tellement de choses se sont passées!\p"
	.string "J’espère que l’on va encore avoir\n"
	.string "de bons souvenirs ensemble.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Tu es un jeune DRESSEUR, hein?\p"
	.string "Pour te battre contre nous, il faut que\n"
	.string "tu reviennes avec plus de POKéMON.$"


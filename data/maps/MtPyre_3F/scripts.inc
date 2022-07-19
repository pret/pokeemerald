MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "L’air pur de la montagne a augmenté\n"
	.string "mon pouvoir psychique!\p"
	.string "Un p’tit mioche comme toi…\n"
	.string "Tu rêves de gagner?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "J’ai honte de moi…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mes pouvoirs psychiques se sont sans\n"
	.string "aucun doute accrus, mais…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ah ah ah ah!\p"
	.string "C’est pas un endroit pour les mômes,\n"
	.string "encore moins pour toi!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Il est clair que j’ai perdu…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ça veut dire que mon entraînement\n"
	.string "n’est pas encore suffisant…\p"
	.string "Il faut que je continue à travailler\n"
	.string "pour arriver au plus haut niveau…\p"
	.string "Allez! Je suis motivée!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Qu’est-ce que tu viens faire ici?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "C’était époustouflant!\n"
	.string "Tu es un DRESSEUR d’exception!$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Les POKéMON qui ne sont plus de\n"
	.string "ce monde…\l"
	.string "Les POKéMON à tes côtés maintenant…\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils méritent tous d’être aimés de la\n"
	.string "même façon. Ne l’oublie pas!$"

MtPyre_3F_Text_GabrielleRegister:
	.string "J’aimerais revoir tes POKéMON quand\n"
	.string "ils auront plus d’expérience…\p"
	.string "Laisse-moi voir ton POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, c’est toi…\p"
	.string "Tu es là pour me montrer comme tes\n"
	.string "POKéMON ont progressé?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Incroyable! Je suis vraiment heureuse\n"
	.string "de connaître quelqu’un comme toi!$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Les POKéMON qui ne sont plus de\n"
	.string "ce monde…\l"
	.string "Les POKéMON à tes côtés maintenant…\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils méritent tous d’être aimés de la\n"
	.string "même façon. Je vois que tu n’as\l"
	.string "pas oublié!$"


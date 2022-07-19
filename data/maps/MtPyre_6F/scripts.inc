MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quand je suis ici…\n"
	.string "Un étrange pouvoir s’empare de moi…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Le pouvoir s’affaiblit…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Ce pouvoir vient peut-être des esprits\n"
	.string "errants des POKéMON qui reposent ici…$"

MtPyre_6F_Text_ValerieRegister:
	.string "… J’ai perdu ce match, mais…\n"
	.string "J’ai ce petit don en moi…\p"
	.string "Et sans même poser les mains\n"
	.string "sur ton POKéNAV…$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Derrière toi…\n"
	.string "Qu’est-ce que c’est…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Quelque chose a disparu…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Les POKéMON qui reposent ici…\n"
	.string "Parfois, ils s’amusent…$"

MtPyre_6F_Text_CedricIntro:
	.string "Est-ce que tu as perdu ton chemin?\n"
	.string "Ne t’inquiète pas, je suis là!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Tu n’avais pas perdu ton chemin?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Je pensais qu’un DRESSEUR perdu\n"
	.string "serait plus facile à battre.\p"
	.string "Je m’étais trompé et je ne\n"
	.string "recommencerai plus…$"


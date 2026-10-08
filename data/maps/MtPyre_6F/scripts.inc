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
	.string "Als ik hier ben…\n"
	.string "Stroomt er een vreemde kracht\l"
	.string "in me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "De kracht ebt weg…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Misschien komt de kracht van de\n"
	.string "geesten van POKéMON die hier\l"
	.string "onrustig slapen…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Ik verloor, maar…\n"
	.string "Ik heb een klein talent…\p"
	.string "Zonder je POKéNAV aan te raken…\n"
	.string "Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Achter je…\n"
	.string "Wat is dat…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Iets verdween…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "De POKéMON die hier rusten…\n"
	.string "Soms spelen ze…$"

MtPyre_6F_Text_CedricIntro:
	.string "Ben je de weg kwijt?\n"
	.string "Wees niet bang, ik ben er!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Was je niet de weg kwijt?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Ik dacht dat een TRAINER die de\n"
	.string "weg kwijt is in paniek en makkelijk\l"
	.string "te verslaan zou zijn.\p"
	.string "Dat is gemeen en ik doe het\n"
	.string "niet meer…$"


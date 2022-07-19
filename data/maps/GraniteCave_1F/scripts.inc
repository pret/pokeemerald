GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hé, toi!\n"
	.string "Il fait terriblement sombre là-dedans.\l"
	.string "Ça va être difficile à explorer.\p"
	.string "Ce type qui est passé tout à l’heure…\n"
	.string "PIERRE, je crois que c’était ça.\p"
	.string "Il savait utiliser FLASH, alors il n’a pas\n"
	.string "dû avoir de problème, mais…\p"
	.string "Pour nous, les MONTAGNARDS, la devise\n"
	.string "est d’aider ceux que l’on rencontre.\p"
	.string "Vas-y et bon courage!$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Apprends cette CS FLASH\n"
	.string "à un POKéMON et utilise-la.\p"
	.string "Ça permet d’éclairer même les cavernes\n"
	.string "les plus sombres.\p"
	.string "Mais pour l’utiliser, il faut le BADGE\n"
	.string "de l’ARENE POKéMON de MYOKARA.$"


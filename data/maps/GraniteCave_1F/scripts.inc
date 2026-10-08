GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hé, jij daar.\n"
	.string "Verderop is het heel donker.\l"
	.string "Dan is rondkijken lastig.\p"
	.string "Die man die hier net langskwam…\n"
	.string "STEVEN heette hij, geloof ik.\p"
	.string "Hij kon FLITS gebruiken, dus met\n"
	.string "hem gaat het wel goed, maar…\p"
	.string "Nou, wij WANDELAARS helpen altijd\n"
	.string "iedereen die we tegenkomen.\p"
	.string "Hier, deze geef ik aan jou.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Leer een POKéMON de verborgen\n"
	.string "aanval FLITS en gebruik hem.\p"
	.string "Dan wordt zelfs een pikdonkere\n"
	.string "grot licht.\p"
	.string "Maar dan heb je wel de GYM BADGE\n"
	.string "van de POKéMON GYM in DEWFORD nodig.$"


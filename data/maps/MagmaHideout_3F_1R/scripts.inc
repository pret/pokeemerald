MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Wat heb ik misdaan dat ik hier\n"
	.string "moet bewaken?\p"
	.string "Mijn linkeroor brandt!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Ik krijg een hitteberoerte…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Vind je het gek dat we kappen\n"
	.string "aanhebben in een vulkaan vol magma?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "We deden mee om onze leider te\n"
	.string "helpen zijn droom waar te maken.\p"
	.string "Het maakt me niet uit of je bij\n"
	.string "TEAM AQUA hoort of gewoon langskomt.\p"
	.string "Niemand bemoeit zich met ons\n"
	.string "zonder gevolgen!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh nee!\n"
	.string "Je bent totaal niet te vertrouwen!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Luister.\n"
	.string "TEAM MAGMA heeft gelijk!\p"
	.string "Luister niet naar TEAM AQUA.\n"
	.string "Geloof hun leugens niet!$"


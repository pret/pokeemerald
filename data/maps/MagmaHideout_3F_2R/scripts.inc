MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Ik begrijp alles wat onze leider\n"
	.string "zegt. Maar weet je wat?\p"
	.string "Een oeroude POKéMON opgraven en\n"
	.string "iemands METEORIET afpakken…\p"
	.string "Ik vind dat we te ver gaan.\n"
	.string "Wat denk jij?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ja, ik denk dat we iets\n"
	.string "verkeerd doen.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Door van jou te verliezen, werd\n"
	.string "mijn hoofd helder.\p"
	.string "Als ik onze leider weer zie, vraag\n"
	.string "ik hem waarom we dit doen.$"


MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Ik heb niets tegen je.\n"
	.string "Ik volg alleen bevelen!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Ik verloor misschien, maar…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "We groeven iets ongelofelijks op!\n"
	.string "En we hebben de BLAUWE BOL!\p"
	.string "Nu moet onze leider nog…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Ik kan niet tegen hitte. Misschien\n"
	.string "moest ik bij TEAM AQUA gaan…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ja, ik pas misschien echt niet\n"
	.string "bij TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Mis je de zee niet op een plek\n"
	.string "als deze?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Hier hoor je soms trillingen.\p"
	.string "Is het de vulkaan die rommelt?\n"
	.string "Of is het GROU…\p"
	.string "Oeps!\n"
	.string "Nee, nee, laat maar!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Je vecht met vuur.\n"
	.string "Net als een vulkaan!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Je won nu toevallig, maar dat\n"
	.string "maakt niet uit.\p"
	.string "Het doel van TEAM MAGMA is bijna\n"
	.string "bereikt!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Een van ons raakte in paniek\n"
	.string "omdat hij zijn MAGMAEMBLEEM kwijt was…\p"
	.string "Wacht even!\n"
	.string "Heb jij het gevonden?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Ik kan dit bijna niet geloven…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ik heb het gevoel dat ons plan\n"
	.string "mislukt…$"


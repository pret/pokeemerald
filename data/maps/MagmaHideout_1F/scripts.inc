MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Bij het appèl van TEAM MAGMA krijgen\n"
	.string "we bewaaktaken in de volgorde\l"
	.string "waarin we staan.\p"
	.string "Daarom zit ik in deze hoek.\n"
	.string "Ik ben altijd te laat!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Ik ben ook altijd te laat bij\n"
	.string "de training!\p"
	.string "Ik durf het amper te zeggen, maar\n"
	.string "ik ben een watje…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Oké, ik doe vanaf nu iets\n"
	.string "meer mijn best…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Onze leider zei dat we in\n"
	.string "MT. CHIMNEY moesten graven, dus\l"
	.string "groeven we en groeven we.\p"
	.string "En tijdens het graven vonden we\n"
	.string "iets waar we versteld van stonden!\p"
	.string "Wat we vonden?\p"
	.string "Fuhahaha!\n"
	.string "Ik vertel het als je me verslaat!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Verslagen!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Ik vertel het toch niet.\n"
	.string "Je ziet het vanzelf!\p"
	.string "Het is leuker om verrassingen\n"
	.string "voor het laatst te bewaren, toch?$"


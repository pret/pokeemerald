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
	.string "A l’appel de la TEAM MAGMA, nous\n"
	.string "nous sommes présentés un par un pour\l"
	.string "recevoir nos assignements.\p"
	.string "C’est pour ça que je suis coincé dans\n"
	.string "ce coin, j’arrive toujours trop tard!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "J’arrive aussi toujours en retard aux\n"
	.string "entraînements!\p"
	.string "J’aime pas trop l’avouer, mais je suis\n"
	.string "loin d’être le meilleur…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "OK, je vais essayer de m’entraîner\n"
	.string "un peu plus sérieusement.$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Notre leader nous a dit de creuser dans\n"
	.string "le MONT CHIMNEE, alors on a creusé.\p"
	.string "Et pendant qu’on était en train de\n"
	.string "creuser, on est tombés sur quelque\l"
	.string "chose de vraiment incroyable.\p"
	.string "Tu veux savoir ce que c’est?\p"
	.string "Ouahahah!\n"
	.string "Je te le dirai si t’arrives à me battre!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Ouille!\n"
	.string "Tu m’as eu!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "J’ai changé d’avis, j’vais rien te dire!\n"
	.string "Tu vas devoir découvrir par toi-même!\p"
	.string "Je te gâcherais la surprise si je te\n"
	.string "disais tout, tu crois pas?$"


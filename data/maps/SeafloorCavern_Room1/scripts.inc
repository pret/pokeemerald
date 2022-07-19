SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Pas besoin d’un môme dans nos pattes!\n"
	.string "Rentre chez toi!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Je veux rentrer chez moi…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Je veux avoir une promotion pour\n"
	.string "donner des ordres aux SBIRES…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Ce sous-marin… C’est minuscule à\n"
	.string "l’intérieur. J’ai mal partout!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Ça m’énerve de perdre!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Ce sous-marin qu’on a piqué…\n"
	.string "Plutôt brutale la balade!\p"
	.string "C’est trop étroit là-dedans!$"


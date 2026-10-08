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
	.string "We hebben geen kind nodig!\n"
	.string "Ga maar naar huis!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Ik wil naar huis…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Ik wil promotie maken, zodat ik\n"
	.string "de HANDLANGERS kan commanderen…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Die duikboot… Het is klein binnen.\n"
	.string "Ik heb overal pijn!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Verliezen doet pijn!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Die duikboot die we jatten,\n"
	.string "wat een vreselijke rit.\l"
	.string "Het is er veel te krap!$"


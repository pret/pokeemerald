SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Wie ben jij?\n"
	.string "Waar kwam je binnen?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Verloren…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Ik kan de uitgang niet vinden!\p"
	.string "Ik ben niet bang. Begrijp me niet\n"
	.string "verkeerd!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Wie ben jij?\n"
	.string "Waar denk je heen te gaan?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Ik kon niet winnen!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Mijn maatje liet de kaart in die\n"
	.string "duikboot liggen!\p"
	.string "Is dat niet nutteloos?$"


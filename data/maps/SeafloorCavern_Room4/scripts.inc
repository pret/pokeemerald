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
	.string "Qui es-tu?\n"
	.string "Comment as-tu atterri ici?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "J’ai perdu…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "J’arrive pas à trouver d’issue!\p"
	.string "J’ai pas peur. Comprends-moi bien!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Qui es-tu?\n"
	.string "Pour qui est-ce que tu te prends?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Tu m’as eue!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Mon partenaire a oublié la carte dans\n"
	.string "le sous-marin!\p"
	.string "C’est le roi des incapables!$"


AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Qu’est-ce qu’il y a de si drôle à me voir\n"
	.string "à bord du bateau avec ma bouée?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Waouh, tu m’as écrasé!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "C’est dur de lancer des POKé BALLS tout\n"
	.string "en se cramponnant à une bouée!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "C’est cool ici, hein?\n"
	.string "Je suis tout excité rien que d’être là!$"

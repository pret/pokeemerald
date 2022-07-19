DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Je pourrais parler pendant des heures\n"
	.string "de la vie sur une si petite île, \p"
	.string "en harmonie avec sa famille et ses\n"
	.string "POKéMON.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "J’ai quitté POIVRESSEL pour\n"
	.string "vivre avec mon mari ici.\p"
	.string "La vie passe lentement sur cette\n"
	.string "île. Mais c’est un vrai bonheur d’être\l"
	.string "entourée de cette mer magnifique.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZATON: Zaaaton!$"


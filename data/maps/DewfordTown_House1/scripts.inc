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
	.string "Het is fijn om op zo'n klein eiland\n"
	.string "te wonen, samen met POKéMON\l"
	.string "en je familie.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Ik kom uit de grote haven van\n"
	.string "SLATEPORT CITY. Ik trouwde hier.\p"
	.string "Het leven gaat rustig op dit\n"
	.string "kleine eiland. Maar de mooie zee\l"
	.string "om je heen… dat is ook geluk.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"


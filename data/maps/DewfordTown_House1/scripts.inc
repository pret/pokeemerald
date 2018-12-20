DewfordTown_House1_MapScripts:: @ 81FC3CD
	.byte 0

DewfordTown_House1_EventScript_1FC3CE:: @ 81FC3CE
	msgbox DewfordTown_House1_Text_1FC3F3, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_1FC3D7:: @ 81FC3D7
	msgbox DewfordTown_House1_Text_1FC45B, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_1FC3E0:: @ 81FC3E0
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox DewfordTown_House1_Text_1FC510, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_1FC3F3: @ 81FC3F3
	.string "There's a lot to be said for living on\n"
	.string "a small island like this in harmony with\l"
	.string "POKéMON and the family.$"

DewfordTown_House1_Text_1FC45B: @ 81FC45B
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.$"

DewfordTown_House1_Text_1FC510: @ 81FC510
	.string "ZIGZAGOON: Guguuh!$"


FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Les cabanes de CIMETRONELLE\n"
	.string "sont géniales!\p"
	.string "Je trouve que c’est la ville parfaite\n"
	.string "pour vivre avec les POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Les POKéMON et les hommes se sont\n"
	.string "adaptés à la nature pour survivre.\p"
	.string "Il n’est pas nécessaire d’adapter la\n"
	.string "nature au mode de vie que l’on souhaite.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZATON: Zaaaton!$"


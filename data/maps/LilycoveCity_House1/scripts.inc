LilycoveCity_House1_MapScripts:: @ 821ECCD
	.byte 0

LilycoveCity_House1_EventScript_ExpertM:: @ 821ECCE
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon:: @ 821ECD7
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, 0
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools: @ 821ECEA
	.string "POKéMON are partners to people.\n"
	.string "They aren't our tools.\p"
	.string "Unfortunately, there are some people\n"
	.string "who fail to understand that…$"

LilycoveCity_House1_Text_Kecleon: @ 821ED63
	.string "KECLEON: Ruroro?$"


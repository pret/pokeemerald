LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "Les POKéMON sont les partenaires des\n"
	.string "hommes. Ils ne sont pas nos outils.\p"
	.string "Malheureusement, certaines personnes\n"
	.string "ne veulent pas comprendre ça…$"

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Kécléééon?$"


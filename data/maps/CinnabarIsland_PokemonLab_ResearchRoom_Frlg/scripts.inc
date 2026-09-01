CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
	.string "EEVEE can evolve into one of three\n"
	.string "kinds of POKéMON.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	.string "There's an e-mail message.\p"
	.string "… … …\p"
	.string "There are three legendary bird\n"
	.string "POKéMON.\p"
	.string "They are ARTICUNO, ZAPDOS, and\n"
	.string "MOLTRES.\p"
	.string "Their whereabouts are unknown.\p"
	.string "We plan to explore the cavern\n"
	.string "close to CERULEAN.\p"
	.string "From: POKéMON RESEARCH TEAM…$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	.string "An amber pipe!$"


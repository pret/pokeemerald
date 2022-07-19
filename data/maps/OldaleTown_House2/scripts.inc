OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Lorsque les POKéMON se battent, ils\n"
	.string "gagnent de l’expérience et deviennent\l"
	.string "plus forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si les POKéMON de ton équipe deviennent\n"
	.string "plus forts, tu pourras voyager plus\l"
	.string "loin.$"


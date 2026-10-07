OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Als POKéMON vechten, gaan ze een\n"
	.string "level omhoog en worden ze sterker.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Als je POKéMON sterker worden,\n"
	.string "kun je veel verder van huis\l"
	.string "op reis gaan.$"


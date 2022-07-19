RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Chaque POKéMON a une capacité\n"
	.string "spéciale qu’il peut utiliser.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "Les POKéMON sont des créatures\n"
	.string "si étranges!$"


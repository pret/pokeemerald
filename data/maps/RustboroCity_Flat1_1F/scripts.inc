RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Elke POKéMON heeft een speciaal\n"
	.string "talent dat hij kan gebruiken.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "POKéMON zijn zulke vreemde wezens.$"


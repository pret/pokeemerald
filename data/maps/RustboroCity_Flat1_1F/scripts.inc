RustboroCity_Flat1_1F_MapScripts:: @ 82150CD
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man:: @ 82150CE
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman:: @ 82150D7
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility: @ 82150E0
	.string "Every POKéMON has a special ability\n"
	.string "that it can use.$"

RustboroCity_Flat1_1F_Text_PokemonStrange: @ 8215115
	.string "POKéMON are such strange creatures.$"


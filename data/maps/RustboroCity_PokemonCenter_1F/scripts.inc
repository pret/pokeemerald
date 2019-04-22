RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, RustboroCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call RustboroCity_PokemonCenter_1F_EventScript_2718DE
	end

RustboroCity_PokemonCenter_1F_EventScript_214D76:: @ 8214D76
	setvar VAR_0x800B, 1
	call RustboroCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_214D84:: @ 8214D84
	msgbox RustboroCity_PokemonCenter_1F_Text_214D9F, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_214D8D:: @ 8214D8D
	msgbox RustboroCity_PokemonCenter_1F_Text_214E13, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_214D96:: @ 8214D96
	msgbox RustboroCity_PokemonCenter_1F_Text_214E81, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_214D9F: @ 8214D9F
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_214E13: @ 8214E13
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_214E81: @ 8214E81
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"


FortreeCity_PokemonCenter_1F_MapScripts:: @ 82173D8
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition: @ 82173E3
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_2173E7:: @ 82173E7
	setvar VAR_0x800B, 1
	call FortreeCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_2173F5:: @ 82173F5
	msgbox FortreeCity_PokemonCenter_1F_Text_217410, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_2173FE:: @ 82173FE
	msgbox FortreeCity_PokemonCenter_1F_Text_21746D, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_217407:: @ 8217407
	msgbox FortreeCity_PokemonCenter_1F_Text_21751F, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_217410: @ 8217410
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"

FortreeCity_PokemonCenter_1F_Text_21746D: @ 821746D
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_21751F: @ 821751F
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"


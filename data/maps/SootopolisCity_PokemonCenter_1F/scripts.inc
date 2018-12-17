SootopolisCity_PokemonCenter_1F_MapScripts:: @ 82264F1
	map_script 3, SootopolisCity_PokemonCenter_1F_MapScript1_2264FC
	map_script 5, SootopolisCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

SootopolisCity_PokemonCenter_1F_MapScript1_2264FC: @ 82264FC
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_226500:: @ 8226500
	setvar VAR_0x800B, 1
	call SootopolisCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_22650E:: @ 822650E
	lock
	faceplayer
	compare VAR_0x40CA, 2
	goto_if 4, SootopolisCity_PokemonCenter_1F_EventScript_22652E
	checkflag FLAG_0x081
	goto_if 0, SootopolisCity_PokemonCenter_1F_EventScript_22652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_22664B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_22652E:: @ 822652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_226562, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_226538:: @ 8226538
	lock
	faceplayer
	compare VAR_0x40CA, 2
	goto_if 4, SootopolisCity_PokemonCenter_1F_EventScript_226558
	checkflag FLAG_0x081
	goto_if 0, SootopolisCity_PokemonCenter_1F_EventScript_226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_22672F, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_226558:: @ 8226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_2266B9, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_226562: @ 8226562
	.string "WALLACE is rumored to be the toughest\n"
	.string "TRAINER in the whole HOENN region.\p"
	.string "This town's GYM is led by the TRAINER\n"
	.string "who taught WALLACE.\p"
	.string "But the ELITE FOUR… They're said to be\n"
	.string "even stronger than WALLACE's mentor.\p"
	.string "How strong could they be?$"

SootopolisCity_PokemonCenter_1F_Text_22664B: @ 822664B
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"

SootopolisCity_PokemonCenter_1F_Text_2266B9: @ 82266B9
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "POKéMON.\p"
	.string "Because it's fun to be with POKéMON!$"

SootopolisCity_PokemonCenter_1F_Text_22672F: @ 822672F
	.string "Aren't POKéMON our friends?\p"
	.string "Why are they going wild this way?$"


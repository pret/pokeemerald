BattleFrontier_PokemonCenter_1F_MapScripts:: @ 82678F9
	map_script 3, BattleFrontier_PokemonCenter_1F_MapScript1_267904
	map_script 5, BattleFrontier_PokemonCenter_1F_MapScript1_277C30
	.byte 0

BattleFrontier_PokemonCenter_1F_MapScript1_267904: @ 8267904
	setrespawn 22
	end

BattleFrontier_PokemonCenter_1F_EventScript_267908:: @ 8267908
	setvar VAR_0x800B, 1
	call BattleFrontier_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_267916:: @ 8267916
	msgbox BattleFrontier_PokemonCenter_1F_Text_267944, 2
	end

BattleFrontier_PokemonCenter_1F_EventScript_26791F:: @ 826791F
	msgbox BattleFrontier_PokemonCenter_1F_Text_2679EB, 2
	end

BattleFrontier_PokemonCenter_1F_EventScript_267928:: @ 8267928
	msgbox BattleFrontier_PokemonCenter_1F_Text_267A4B, 2
	end

BattleFrontier_PokemonCenter_1F_EventScript_267931:: @ 8267931
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox BattleFrontier_PokemonCenter_1F_Text_267A90, 4
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_267944: @ 8267944
	.string "There was someone here using a \n"
	.string "POKéMON I’ve never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER’S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"

BattleFrontier_PokemonCenter_1F_Text_2679EB: @ 82679EB
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I’d better get the right POKéMON from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_267A4B: @ 8267A4B
	.string "Giggle… I’m going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_267A90: @ 8267A90
	.string "SKITTY: Mya myaaah!$"


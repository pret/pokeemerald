VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_20273A:: @ 820273A
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_202748:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20275A, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_202751:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20280B, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_20275A: @ 820275A
	.string "You can't consider yourself a real\n"
	.string "Trainer if you don't have faith\l"
	.string "in your Pokémon.\p"
	.string "Only those people who can believe\n"
	.string "in their battling Pokémon can win\l"
	.string "through to the very end.$"

VerdanturfTown_PokemonCenter_1F_Text_20280B: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "Verdanturf…\p"
	.string "It's the Battle Tent. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"


ThreeIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ThreeIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_THREE_ISLAND
	end

ThreeIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ThreeIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Lass::
	msgbox ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Rocker::
	msgbox ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto::
	.string "Hey, did you hear the news?\p"
	.string "The PC network here can now link\n"
	.string "with PCs in KANTO.\p"
	.string "I don't know how that came about,\n"
	.string "but it's fantastic!$"

ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands::
	.string "It's impossible to SURF between the\n"
	.string "islands around these parts.\p"
	.string "The tides are too fast and\n"
	.string "treacherous.$"

ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest::
	.string "Let's crush BERRIES!\n"
	.string "…That'd be wasting BERRIES?\p"
	.string "You can always find some BERRIES\n"
	.string "on the ground in BERRY FOREST.$"


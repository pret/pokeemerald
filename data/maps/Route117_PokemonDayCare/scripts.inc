Route117_PokemonDayCare_MapScripts:: @ 822BBB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition: @ 822BBB7
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end


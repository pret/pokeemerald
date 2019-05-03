MauvilleCity_PokemonCenter_2F_MapScripts:: @ 8211008
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MauvilleCity_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MauvilleCity_PokemonCenter_2F_MapScript2_276B6C
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_PokemonCenter_2F_MapScript1_276BBE
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

MauvilleCity_PokemonCenter_2F_EventScript_21101D:: @ 821101D
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

MauvilleCity_PokemonCenter_2F_EventScript_211023:: @ 8211023
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

MauvilleCity_PokemonCenter_2F_EventScript_211029:: @ 8211029
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

MauvilleCity_PokemonCenter_2F_EventScript_21102F:: @ 821102F
	msgbox MauvilleCity_PokemonCenter_2F_Text_211038, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_211038: @ 8211038
	.string "Did you know that you can link battle\n"
	.string "at the COLOSSEUM here?\p"
	.string "They put up your record on the wall\n"
	.string "for everyone to see.\p"
	.string "It's embarrassing if you lose more\n"
	.string "often than you win…$"


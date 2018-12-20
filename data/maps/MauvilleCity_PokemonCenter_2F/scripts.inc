MauvilleCity_PokemonCenter_2F_MapScripts:: @ 8211008
	map_script 2, MauvilleCity_PokemonCenter_2F_MapScript2_276C3B
	map_script 4, MauvilleCity_PokemonCenter_2F_MapScript2_276B6C
	map_script 1, MauvilleCity_PokemonCenter_2F_MapScript1_276BBE
	map_script 3, MauvilleCity_PokemonCenter_2F_MapScript1_276ACF
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


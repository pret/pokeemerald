MauvilleCity_PokemonCenter_2F_MapScripts:: @ 8211008
	map_script 2, MauvilleCity_PokemonCenter_2F_MapScript2_276C3B
	map_script 4, MauvilleCity_PokemonCenter_2F_MapScript2_276B6C
	map_script 1, MauvilleCity_PokemonCenter_2F_MapScript1_276BBE
	map_script 3, MauvilleCity_PokemonCenter_2F_MapScript1_276ACF
	.byte 0

	.incbin "baserom.gba", 0x21101d, 0x12

MauvilleCity_PokemonCenter_2F_EventScript_21102F:: @ 821102F
	msgbox MauvilleCity_PokemonCenter_2F_Text_211038, 2
	end

MauvilleCity_PokemonCenter_2F_Text_211038: @ 8211038
	.string "Did you know that you can link battle\n"
	.string "at the COLOSSEUM here?\p"
	.string "They put up your record on the wall\n"
	.string "for everyone to see.\p"
	.string "It’s embarrassing if you lose more\n"
	.string "often than you win…$"


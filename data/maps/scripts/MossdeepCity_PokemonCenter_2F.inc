MossdeepCity_PokemonCenter_2F_MapScripts:: @ 8222334
	map_script 2, MossdeepCity_PokemonCenter_2F_MapScript2_276C3B
	map_script 4, MossdeepCity_PokemonCenter_2F_MapScript2_276B6C
	map_script 1, MossdeepCity_PokemonCenter_2F_MapScript1_276BBE
	map_script 3, MossdeepCity_PokemonCenter_2F_MapScript1_276ACF
	.byte 0

	.incbin "baserom.gba", 0x222349, 0x12

MossdeepCity_PokemonCenter_2F_EventScript_22235B:: @ 822235B
	msgbox MossdeepCity_PokemonCenter_2F_Text_222364, 2
	end

MossdeepCity_PokemonCenter_2F_Text_222364: @ 8222364
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"


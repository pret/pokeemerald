MossdeepCity_PokemonCenter_2F_MapScripts:: @ 8222334
	map_script MAP_SCRIPT_TRIGGER_EVENTS, MossdeepCity_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_TRIGGER_MAP_SCRIPTS, MossdeepCity_PokemonCenter_2F_MapScript2_276B6C
	map_script MAP_SCRIPT_SET_METATILES, MossdeepCity_PokemonCenter_2F_MapScript1_276BBE
	map_script MAP_SCRIPT_SET_DATA, MossdeepCity_PokemonCenter_2F_MapScript1_276ACF
	.byte 0

MossdeepCity_PokemonCenter_2F_EventScript_222349:: @ 8222349
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

MossdeepCity_PokemonCenter_2F_EventScript_22234F:: @ 822234F
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

MossdeepCity_PokemonCenter_2F_EventScript_222355:: @ 8222355
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

MossdeepCity_PokemonCenter_2F_EventScript_22235B:: @ 822235B
	msgbox MossdeepCity_PokemonCenter_2F_Text_222364, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_2F_Text_222364: @ 8222364
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"


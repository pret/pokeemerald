LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, LilycoveCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_21C5C6
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5C6:: @ 821C5C6
	special SetLilycoveLadyGfx
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E0
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E4
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E0:: @ 821C5E0
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E4:: @ 821C5E4
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E8:: @ 821C5E8
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5F6:: @ 821C5F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C61E, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5FF:: @ 821C5FF
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_21C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C69D, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C614:: @ 821C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C6F6, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_21C61E: @ 821C61E
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade POKéMON with people far away.$"

LilycoveCity_PokemonCenter_1F_Text_21C69D: @ 821C69D
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal POKéMON and rip\l"
	.string "off METEORITES.$"

LilycoveCity_PokemonCenter_1F_Text_21C6F6: @ 821C6F6
	.string "Those rotten scoundrels who steal\n"
	.string "POKéMON and rip off METEORITES…\p"
	.string "I haven't seen them around recently.$"


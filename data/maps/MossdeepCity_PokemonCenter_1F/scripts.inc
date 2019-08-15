MossdeepCity_PokemonCenter_1F_MapScripts:: @ 822223F
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition: @ 822224A
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_22224E:: @ 822224E
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_22225C:: @ 822225C
	msgbox MossdeepCity_PokemonCenter_1F_Text_22226E, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_222265:: @ 8222265
	msgbox MossdeepCity_PokemonCenter_1F_Text_2222D9, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_22226E: @ 822226E
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCenter_1F_Text_2222D9: @ 82222D9
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"


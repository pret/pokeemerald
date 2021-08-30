MossdeepCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MossdeepCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MossdeepCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MossdeepCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MossdeepCity_PokemonCenter_2F_EventScript_Woman5::
	msgbox MossdeepCity_PokemonCenter_2F_Text_Woman5, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_2F_Text_Woman5:
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"


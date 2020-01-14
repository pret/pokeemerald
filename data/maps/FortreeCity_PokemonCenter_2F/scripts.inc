FortreeCity_PokemonCenter_2F_MapScripts:: @ 821763E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
FortreeCity_PokemonCenter_2F_EventScript_Colosseum:: @ 8217653
	call CableClub_EventScript_Colosseum
	end

FortreeCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 8217659
	call CableClub_EventScript_TradeCenter
	end

FortreeCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 821765F
	call CableClub_EventScript_RecordCorner
	end


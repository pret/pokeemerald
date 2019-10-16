EverGrandeCity_PokemonCenter_2F_MapScripts:: @ 8229CE0
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
EverGrandeCity_PokemonCenter_2F_EventScript_Colosseum:: @ 8229CF5
	call CableClub_EventScript_Colosseum
	end

EverGrandeCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 8229CFB
	call CableClub_EventScript_TradeCenter
	end

EverGrandeCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 8229D01
	call CableClub_EventScript_RecordCorner
	end



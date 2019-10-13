RustboroCity_PokemonCenter_2F_MapScripts:: @ 8214EDE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
RustboroCity_PokemonCenter_2F_EventScript_Colosseum:: @ 8214EF3
	call CableClub_EventScript_Colosseum
	end

RustboroCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 8214EF9
	call CableClub_EventScript_TradeCenter
	end

RustboroCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 8214EFF
	call CableClub_EventScript_RecordCorner
	end


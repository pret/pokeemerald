BattleFrontier_PokemonCenter_2F_MapScripts:: @ 8267AA4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
BattleFrontier_PokemonCenter_2F_EventScript_Colosseum:: @ 8267AB9
	call CableClub_EventScript_Colosseum
	end

BattleFrontier_PokemonCenter_2F_EventScript_TradeCenter:: @ 8267ABF
	call CableClub_EventScript_TradeCenter
	end

BattleFrontier_PokemonCenter_2F_EventScript_RecordCorner:: @ 8267AC5
	call CableClub_EventScript_RecordCorner
	end


LavaridgeTown_PokemonCenter_2F_MapScripts:: @ 81FFC97
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum:: @ 81FFCAC
	call CableClub_EventScript_Colosseum
	end

LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 81FFCB2
	call CableClub_EventScript_TradeCenter
	end

LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 81FFCB8
	call CableClub_EventScript_RecordCorner
	end


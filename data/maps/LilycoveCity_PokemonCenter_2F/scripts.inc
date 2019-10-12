LilycoveCity_PokemonCenter_2F_MapScripts:: @ 821C75D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
LilycoveCity_PokemonCenter_2F_EventScript_Colosseum:: @ 821C772
	call CableClub_EventScript_Colosseum
	end

LilycoveCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 821C778
	call CableClub_EventScript_TradeCenter
	end

LilycoveCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 821C77E
	call CableClub_EventScript_RecordCorner
	end


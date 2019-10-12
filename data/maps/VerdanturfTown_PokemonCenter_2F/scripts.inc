VerdanturfTown_PokemonCenter_2F_MapScripts:: @ 8202897
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum:: @ 82028AC
	call CableClub_EventScript_Colosseum
	end

VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 82028B2
	call CableClub_EventScript_TradeCenter
	end

VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 82028B8
	call CableClub_EventScript_RecordCorner
	end


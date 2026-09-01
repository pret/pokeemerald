PalletTown_PlayersHouse_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_Text_PlayedWithNES::
	.string "{PLAYER} played with the NES.\p"
	.string "…Okay!\n"
	.string "It's time to go!$"

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
	.string "It's a posted notice…\p"
	.string "If you're confused, ask for HELP!\n"
	.string "Press the L or R Button!$"


PlayerBasement_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Basement_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Basement_OnWarp
	.byte 0

Basement_OnWarp:
	map_script_2 VAR_TEMP_1, 0, Basement_LookUp
	.2byte 0

Basement_LookUp::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

Basement_OnFrame:
	map_script_2 VAR_GYM_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, Basement_QuitWithoutSaving
	map_script_2 VAR_GYM_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, Basement_Won
	map_script_2 VAR_GYM_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, Basement_Lost
	.2byte 0

Basement_QuitWithoutSaving::
	end

Basement_Won::
	end

Base_Lost::
	end

Basement_Text_0:
	.string "Right this way.$"

Basement_Teleport_Test_0::
	lockall
	msgbox Basement_Text_0, MSGBOX_DEFAULT
	closemessage

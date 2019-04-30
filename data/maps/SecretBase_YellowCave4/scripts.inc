SecretBase_YellowCave4_MapScripts:: @ 823B483
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_RedCave1_MapScript2_23B498
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_RedCave1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_RedCave1_MapScript2_23B4AE
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_RedCave1_MapScript1_23B4B8
	.byte 0

SecretBase_RedCave1_MapScript2_23B498: @ 823B498
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, EventScript_275D0C
	.2byte 0

SecretBase_RedCave1_OnTransition: @ 823B4A2
	call SecretBase_RedCave1_EventScript_275CE1
	special SetSecretBaseOwnerGfxId
	special sub_80EB1AC
	end

SecretBase_RedCave1_MapScript2_23B4AE: @ 823B4AE
	map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_RedCave1_EventScript_275B81
	.2byte 0

SecretBase_RedCave1_MapScript1_23B4B8: @ 823B4B8
	setstepcallback 6
	end

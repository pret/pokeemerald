SecretBase_YellowCave4_MapScripts:: @ 823B483
	map_script MAP_SCRIPT_TRIGGER_MAP_SCRIPTS, SecretBase_RedCave1_MapScript2_23B498
	map_script MAP_SCRIPT_SET_DATA, SecretBase_RedCave1_MapScript1_23B4A2
	map_script MAP_SCRIPT_TRIGGER_EVENTS, SecretBase_RedCave1_MapScript2_23B4AE
	map_script MAP_SCRIPT_TRIGGER_SPECIALS, SecretBase_RedCave1_MapScript1_23B4B8
	.byte 0

SecretBase_RedCave1_MapScript2_23B498: @ 823B498
	map_script_2 VAR_0x4089, 0, EventScript_275D0C
	.2byte 0

SecretBase_RedCave1_MapScript1_23B4A2: @ 823B4A2
	call SecretBase_RedCave1_EventScript_275CE1
	special sub_80E95D4
	special sub_80EB1AC
	end

SecretBase_RedCave1_MapScript2_23B4AE: @ 823B4AE
	map_script_2 VAR_0x4097, 0, SecretBase_RedCave1_EventScript_275B81
	.2byte 0

SecretBase_RedCave1_MapScript1_23B4B8: @ 823B4B8
	setstepcallback 6
	end

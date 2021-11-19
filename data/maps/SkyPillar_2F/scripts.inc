SkyPillar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_2F_SetHoleWarp
	.byte 0

SkyPillar_2F_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_2F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_2F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_2F_CLEAN
	return

SkyPillar_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_1F
	end


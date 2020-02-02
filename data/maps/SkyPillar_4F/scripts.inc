SkyPillar_4F_MapScripts:: @ 8239671
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_SetHoleWarp
	.byte 0

SkyPillar_4F_OnTransition: @ 8239681
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_4F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_4F_EventScript_CleanFloor:: @ 8239692
	setmaplayoutindex LAYOUT_SKY_PILLAR_4F_CLEAN
	return

SkyPillar_4F_SetHoleWarp: @ 8239696
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F, 255, 0, 0
	end


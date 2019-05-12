SkyPillar_1F_MapScripts:: @ 8239615
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_1F_OnTransition
	.byte 0

SkyPillar_1F_OnTransition: @ 823961B
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_1F_EventScript_CleanFloor
	end

SkyPillar_1F_EventScript_CleanFloor:: @ 8239627
	setmaplayoutindex LAYOUT_SKY_PILLAR_1F_CLEAN
	return


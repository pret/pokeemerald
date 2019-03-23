SkyPillar_3F_MapScripts:: @ 823965B
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_3F_MapScript1_239661
	.byte 0

SkyPillar_3F_MapScript1_239661: @ 8239661
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_3F_EventScript_23966D
	end

SkyPillar_3F_EventScript_23966D:: @ 823966D
	setmaplayoutindex LAYOUT_SKY_PILLAR_3F_CLEAN
	return


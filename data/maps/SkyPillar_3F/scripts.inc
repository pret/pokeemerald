SkyPillar_3F_MapScripts:: @ 823965B
	map_script 3, SkyPillar_3F_MapScript1_239661
	.byte 0

SkyPillar_3F_MapScript1_239661: @ 8239661
	compare VAR_0x40CA, 2
	call_if_lt SkyPillar_3F_EventScript_23966D
	end

SkyPillar_3F_EventScript_23966D:: @ 823966D
	setmaplayoutindex 435
	return


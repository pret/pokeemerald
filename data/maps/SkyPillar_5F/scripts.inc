SkyPillar_5F_MapScripts:: @ 82396A2
	map_script 3, SkyPillar_5F_MapScript1_2396A8
	.byte 0

SkyPillar_5F_MapScript1_2396A8: @ 82396A8
	compare VAR_0x40CA, 2
	call_if_lt SkyPillar_5F_EventScript_2396B4
	return

SkyPillar_5F_EventScript_2396B4:: @ 82396B4
	setmaplayoutindex 437
	return


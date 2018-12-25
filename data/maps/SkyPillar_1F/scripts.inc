SkyPillar_1F_MapScripts:: @ 8239615
	map_script 3, SkyPillar_1F_MapScript1_23961B
	.byte 0

SkyPillar_1F_MapScript1_23961B: @ 823961B
	compare VAR_0x40CA, 2
	call_if_lt SkyPillar_1F_EventScript_239627
	end

SkyPillar_1F_EventScript_239627:: @ 8239627
	setmaplayoutindex 433
	return


SkyPillar_4F_MapScripts:: @ 8239671
	map_script 2, SkyPillar_4F_MapScript2_2A8327
	map_script 3, SkyPillar_4F_MapScript1_239681
	map_script 5, SkyPillar_4F_MapScript1_239696
	.byte 0

SkyPillar_4F_MapScript1_239681: @ 8239681
	compare VAR_0x40CA, 2
	call_if_lt SkyPillar_4F_EventScript_239692
	copyvar VAR_ICE_STEP_COUNT, 0x1
	end

SkyPillar_4F_EventScript_239692:: @ 8239692
	setmaplayoutindex 436
	return

SkyPillar_4F_MapScript1_239696: @ 8239696
	setstepcallback 7
	setholewarp MAP_SKY_PILLAR_3F, 255, 0, 0
	end


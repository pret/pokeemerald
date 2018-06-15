SkyPillar_Top_EventObjects: @ 8537170
	object_event 1, EVENT_OBJ_GFX_RAYQUAZA_2, 0, 0, 14, 7, 3, 8, 17, 0, 0, 0, 0x0, 773, 0, 0
	object_event 2, EVENT_OBJ_GFX_RAYQUAZA_1, 0, 0, 14, 6, 3, 8, 17, 0, 0, 0, SkyPillar_Top_EventScript_239722, 80, 0, 0

SkyPillar_Top_MapWarps: @ 85371A0
	warp_def 16, 14, 3, 1, MAP_SKY_PILLAR_5F

SkyPillar_Top_MapCoordEvents: @ 85371A8
	coord_event 14, 9, 3, 0, VAR_0x40D7, 0, 0, SkyPillar_Top_EventScript_23979A

SkyPillar_Top_MapEvents:: @ 85371B8
	map_events SkyPillar_Top_EventObjects, SkyPillar_Top_MapWarps, SkyPillar_Top_MapCoordEvents, 0x0


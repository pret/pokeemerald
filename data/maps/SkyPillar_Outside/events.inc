SkyPillar_Outside_EventObjects: @ 853701C
	object_event 1, EVENT_OBJ_GFX_WALLACE, 0, 13, 7, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, SkyPillar_Outside_EventScript_2393F8, FLAG_0x357

SkyPillar_Outside_MapWarps: @ 8537034
	warp_def 17, 13, 3, 1, MAP_SKY_PILLAR_ENTRANCE
	warp_def 14, 5, 0, 0, MAP_SKY_PILLAR_1F

SkyPillar_Outside_MapEvents:: @ 8537044
	map_events SkyPillar_Outside_EventObjects, SkyPillar_Outside_MapWarps, 0x0, 0x0


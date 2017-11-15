GraniteCave_B1F_MapObjects: @ 8534420
	object_event 1, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 15, 21, 3, 1, 0, 0, 0, 0, GraniteCave_B1F_EventScript_29115D, 1051, 0, 0

GraniteCave_B1F_MapWarps: @ 8534438
	warp_def 25, 13, 3, 1, GRANITE_CAVE_1F
	warp_def 4, 21, 3, 2, GRANITE_CAVE_1F
	warp_def 29, 13, 3, 0, GRANITE_CAVE_B2F
	warp_def 28, 21, 3, 1, GRANITE_CAVE_B2F
	warp_def 8, 5, 3, 2, GRANITE_CAVE_B2F
	warp_def 12, 3, 3, 3, GRANITE_CAVE_B2F
	warp_def 29, 2, 3, 4, GRANITE_CAVE_B2F

GraniteCave_B1F_MapEvents:: @ 8534470
	map_events GraniteCave_B1F_MapObjects, GraniteCave_B1F_MapWarps, 0x0, 0x0


SeafloorCavern_Room9_EventObjects: @ 8535C48
	object_event 1, EVENT_OBJ_GFX_KYOGRE_1, 0, 0, 17, 38, 3, 8, 0, 0, 0, 0, 0x0, 859, 0, 0
	object_event 2, EVENT_OBJ_GFX_ARCHIE, 0, 0, 9, 42, 3, 10, 0, 0, 0, 0, 0x0, 828, 0, 0
	object_event 3, EVENT_OBJ_GFX_MAXIE, 0, 0, 9, 42, 3, 10, 0, 0, 0, 0, 0x0, 829, 0, 0
	object_event 4, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 8, 41, 3, 10, 0, 0, 0, 0, 0x0, 831, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_F, 0, 0, 8, 42, 3, 10, 0, 0, 0, 0, 0x0, 831, 0, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 14, 5, 3, 1, 17, 0, 0, 0, SeafloorCavern_Room9_EventScript_291401, 1090, 0, 0
	object_event 7, EVENT_OBJ_GFX_KYOGRE_2, 0, 0, 17, 38, 3, 8, 17, 0, 0, 0, 0x0, 733, 0, 0

SeafloorCavern_Room9_MapWarps: @ 8535CF0
	warp_def 5, 4, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM8

SeafloorCavern_Room9_MapCoordEvents: @ 8535CF8
	coord_event 17, 42, 3, 0, VAR_0x40A2, 0, 0, SeafloorCavern_Room9_EventScript_234DC9

SeafloorCavern_Room9_MapEvents:: @ 8535D08
	map_events SeafloorCavern_Room9_EventObjects, SeafloorCavern_Room9_MapWarps, SeafloorCavern_Room9_MapCoordEvents, 0x0


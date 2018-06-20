RusturfTunnel_EventObjects: @ 85341C4
	object_event 1, EVENT_OBJ_GFX_BLACK_BELT, 0, 23, 5, 3, 10, 0, 0, 0, 0, RusturfTunnel_EventScript_22CE76, 807
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 24, 5, 3, 1, 0, 0, 0, 0, RusturfTunnel_EventScript_2907A6, 931
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 1, 3, 1, 0, 0, 0, 0, RusturfTunnel_EventScript_291136, 1048
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 30, 2, 3, 1, 0, 0, 0, 0, RusturfTunnel_EventScript_291143, 1049
	object_event 5, EVENT_OBJ_GFX_OLD_MAN_1, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x0, 879
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 14, 5, 3, 9, 0, 0, 0, 0, RusturfTunnel_EventScript_22D0C2, 878
	object_event 7, EVENT_OBJ_GFX_WINGULL, 0, 14, 4, 3, 9, 0, 0, 0, 0, RusturfTunnel_EventScript_22D0AF, 880
	object_event 8, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 24, 4, 3, 8, 0, 0, 0, 0, RusturfTunnel_EventScript_2907A6, 932
	object_event 9, EVENT_OBJ_GFX_HIKER, 0, 32, 13, 3, 9, 1, 1, 1, 3, RusturfTunnel_EventScript_22D1B1, 0
	object_event 10, EVENT_OBJ_GFX_WOMAN_3, 0, 25, 4, 3, 9, 1, 1, 0, 0, RusturfTunnel_EventScript_22CE5F, 983

RusturfTunnel_MapWarps: @ 85342B4
	warp_def 4, 10, 3, 0, MAP_ROUTE116
	warp_def 29, 16, 3, 4, MAP_VERDANTURF_TOWN
	warp_def 18, 20, 3, 2, MAP_ROUTE116

RusturfTunnel_MapCoordEvents: @ 85342CC
	coord_event 23, 4, 3, 0, 0, 0, 0, RusturfTunnel_EventScript_22D071
	coord_event 9, 4, 3, 0, VAR_0x409A, 2, 0, RusturfTunnel_EventScript_22D083
	coord_event 9, 5, 3, 0, VAR_0x409A, 2, 0, RusturfTunnel_EventScript_22D083
	coord_event 25, 4, 3, 0, 0, 0, 0, RusturfTunnel_EventScript_22D077
	coord_event 25, 5, 3, 0, 0, 0, 0, RusturfTunnel_EventScript_22D07D

RusturfTunnel_MapEvents:: @ 853431C
	map_events RusturfTunnel_EventObjects, RusturfTunnel_MapWarps, RusturfTunnel_MapCoordEvents, 0x0


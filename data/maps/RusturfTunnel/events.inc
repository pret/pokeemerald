RusturfTunnel_EventObjects: @ 85341C4
	object_event 1, EVENT_OBJ_GFX_BLACK_BELT, 0, 23, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RusturfTunnel_EventScript_22CE76, FLAG_HIDE_RUSTURF_TUNNEL_LOVER_MAN
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 24, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, RusturfTunnel_EventScript_2907A6, FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 1, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, RusturfTunnel_EventScript_291136, FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 30, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, RusturfTunnel_EventScript_291143, FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER
	object_event 5, EVENT_OBJ_GFX_EXPERT_M, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_RUSTURF_TUNNEL_OLD_MAN
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 14, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RusturfTunnel_EventScript_22D0C2, FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	object_event 7, EVENT_OBJ_GFX_WINGULL, 0, 14, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RusturfTunnel_EventScript_22D0AF, FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	object_event 8, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 24, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RusturfTunnel_EventScript_2907A6, FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2
	object_event 9, EVENT_OBJ_GFX_HIKER, 0, 32, 13, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 3, RusturfTunnel_EventScript_22D1B1, 0
	object_event 10, EVENT_OBJ_GFX_WOMAN_2, 0, 25, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, RusturfTunnel_EventScript_22CE5F, FLAG_HIDE_RUSTURF_TUNNEL_LOVER_WOMAN

RusturfTunnel_MapWarps: @ 85342B4
	warp_def 4, 10, 3, 0, MAP_ROUTE116
	warp_def 29, 16, 3, 4, MAP_VERDANTURF_TOWN
	warp_def 18, 20, 3, 2, MAP_ROUTE116

RusturfTunnel_MapCoordEvents: @ 85342CC
	coord_event 23, 4, 3, 0, 0, RusturfTunnel_EventScript_22D071
	coord_event 9, 4, 3, VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_22D083
	coord_event 9, 5, 3, VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_22D083
	coord_event 25, 4, 3, 0, 0, RusturfTunnel_EventScript_22D077
	coord_event 25, 5, 3, 0, 0, RusturfTunnel_EventScript_22D07D

RusturfTunnel_MapEvents:: @ 853431C
	map_events RusturfTunnel_EventObjects, RusturfTunnel_MapWarps, RusturfTunnel_MapCoordEvents, 0x0


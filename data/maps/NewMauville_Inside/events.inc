NewMauville_Inside_EventObjects: @ 85364A8
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 32, 25, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NewMauville_Inside_EventScript_2911EC, FLAG_0x433
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 16, 22, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NewMauville_Inside_EventScript_2911F9, FLAG_0x434
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 39, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_291206, FLAG_0x456
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 17, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_291213, FLAG_0x462
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 2, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_291220, FLAG_0x463
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 25, 18, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_2377AF, FLAG_0x3CE
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 6, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_2377FC, FLAG_0x3CF
	object_event 8, EVENT_OBJ_GFX_ITEM_BALL, 0, 13, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewMauville_Inside_EventScript_237849, FLAG_0x3D0

NewMauville_Inside_MapWarps: @ 8536568
	warp_def 32, 33, 3, 1, MAP_NEW_MAUVILLE_ENTRANCE

NewMauville_Inside_MapCoordEvents: @ 8536570
	coord_event 30, 38, 3, VAR_TEMP_1, 0, NewMauville_Inside_EventScript_237459
	coord_event 18, 36, 3, VAR_TEMP_2, 0, NewMauville_Inside_EventScript_237471
	coord_event 4, 26, 3, VAR_TEMP_1, 0, NewMauville_Inside_EventScript_237459
	coord_event 16, 22, 3, VAR_TEMP_1, 0, NewMauville_Inside_EventScript_237459
	coord_event 25, 18, 3, VAR_TEMP_2, 0, NewMauville_Inside_EventScript_237471
	coord_event 2, 11, 3, VAR_TEMP_2, 0, NewMauville_Inside_EventScript_237471
	coord_event 6, 11, 3, VAR_TEMP_1, 0, NewMauville_Inside_EventScript_237459
	coord_event 13, 10, 3, VAR_TEMP_1, 0, NewMauville_Inside_EventScript_237459
	coord_event 17, 10, 3, VAR_TEMP_2, 0, NewMauville_Inside_EventScript_237471
	coord_event 33, 6, 3, VAR_0x40BA, 1, NewMauville_Inside_EventScript_237725

NewMauville_Inside_MapBGEvents: @ 8536610
	bg_event 32, 4, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 32, 3, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 32, 2, 0, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 33, 4, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 34, 4, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 35, 4, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 35, 3, 3, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F
	bg_event 35, 2, 0, BG_EVENT_PLAYER_FACING_ANY, NewMauville_Inside_EventScript_23778F

NewMauville_Inside_MapEvents:: @ 8536670
	map_events NewMauville_Inside_EventObjects, NewMauville_Inside_MapWarps, NewMauville_Inside_MapCoordEvents, NewMauville_Inside_MapBGEvents


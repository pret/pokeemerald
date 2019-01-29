InsideOfTruck_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MOVING_BOX, 0, 0, 0, 8, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0
	object_event 2, EVENT_OBJ_GFX_MOVING_BOX, 0, 0, 3, 8, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0
	object_event 3, EVENT_OBJ_GFX_MOVING_BOX, 0, 2, 3, 8, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0

InsideOfTruck_MapWarps:
	warp_def 4, 1, 0, 127, MAP_NONE
	warp_def 4, 2, 0, 127, MAP_NONE
	warp_def 4, 3, 0, 127, MAP_NONE

InsideOfTruck_MapCoordEvents:
	coord_event 3, 1, 3, VAR_0x4092, 0, InsideOfTruck_EventScript_23BF04
	coord_event 3, 2, 3, VAR_0x4092, 0, InsideOfTruck_EventScript_23BF04
	coord_event 3, 3, 3, VAR_0x4092, 0, InsideOfTruck_EventScript_23BF04

InsideOfTruck_MapBGEvents:
	bg_event 1, 0, 0, BG_EVENT_PLAYER_FACING_ANY, InsideOfTruck_EventScript_23BF6C
	bg_event 3, 4, 0, BG_EVENT_PLAYER_FACING_ANY, InsideOfTruck_EventScript_23BF6C
	bg_event 2, 3, 0, BG_EVENT_PLAYER_FACING_ANY, InsideOfTruck_EventScript_23BF6C
	bg_event 0, 1, 0, BG_EVENT_PLAYER_FACING_ANY, InsideOfTruck_EventScript_23BF6C
	bg_event 0, 2, 0, BG_EVENT_PLAYER_FACING_ANY, InsideOfTruck_EventScript_23BF6C

InsideOfTruck_MapEvents::
	map_events InsideOfTruck_EventObjects, InsideOfTruck_MapWarps, InsideOfTruck_MapCoordEvents, InsideOfTruck_MapBGEvents


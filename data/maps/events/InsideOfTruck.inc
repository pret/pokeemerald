InsideOfTruck_MapObjects: @ 853A078
	object_event 1, MAP_OBJ_GFX_MOVING_BOX, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MOVING_BOX, 0, 0, 0, 3, 8, 8, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MOVING_BOX, 0, 0, 2, 3, 8, 8, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C, 0, 0, 0

InsideOfTruck_MapWarps: @ 853A0C0
	warp_def 4, 1, 0, 127, NONE
	warp_def 4, 2, 0, 127, NONE
	warp_def 4, 3, 0, 127, NONE

InsideOfTruck_MapCoordEvents: @ 853A0D8
	coord_event 3, 1, 3, 0, VAR_0x4092, 0, 0, InsideOfTruck_EventScript_23BF04
	coord_event 3, 2, 3, 0, VAR_0x4092, 0, 0, InsideOfTruck_EventScript_23BF04
	coord_event 3, 3, 3, 0, VAR_0x4092, 0, 0, InsideOfTruck_EventScript_23BF04

InsideOfTruck_MapBGEvents: @ 853A108
	bg_event 1, 0, 0, 0, 0, InsideOfTruck_EventScript_23BF6C
	bg_event 3, 4, 0, 0, 0, InsideOfTruck_EventScript_23BF6C
	bg_event 2, 3, 0, 0, 0, InsideOfTruck_EventScript_23BF6C
	bg_event 0, 1, 0, 0, 0, InsideOfTruck_EventScript_23BF6C
	bg_event 0, 2, 0, 0, 0, InsideOfTruck_EventScript_23BF6C

InsideOfTruck_MapEvents:: @ 853A144
	map_events InsideOfTruck_MapObjects, InsideOfTruck_MapWarps, InsideOfTruck_MapCoordEvents, InsideOfTruck_MapBGEvents


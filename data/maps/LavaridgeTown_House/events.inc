LavaridgeTown_House_EventObjects:
	object_event 1, EVENT_OBJ_GFX_OLD_MAN, 0, 2, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, LavaridgeTown_House_EventScript_1FF912, 0
	object_event 2, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 6, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, LavaridgeTown_House_EventScript_1FF91B, 0
	object_event 3, EVENT_OBJ_GFX_NINJA_BOY, 0, 8, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LavaridgeTown_House_EventScript_2C804E, 0

LavaridgeTown_House_MapWarps:
	warp_def 3, 7, 0, 4, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 4, MAP_LAVARIDGE_TOWN

LavaridgeTown_House_MapEvents::
	map_events LavaridgeTown_House_EventObjects, LavaridgeTown_House_MapWarps, 0x0, 0x0


Route130_EventObjects: @ 852CA40
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 70, 21, 1, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN, 3, 6, 1, 3, Route130_EventScript_1F73BF, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_F, 0, 7, 21, 1, MOVEMENT_TYPE_WALK_DOWN_AND_UP, 1, 4, 1, 5, Route130_EventScript_1F73D6, 0
	object_event 3, EVENT_OBJ_GFX_BERRY_TREE, 0, 52, 9, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 82, BerryTreeScript, 17
	object_event 4, EVENT_OBJ_GFX_SWIMMER_M, 0, 7, 30, 1, MOVEMENT_TYPE_WALK_UP_AND_DOWN, 1, 4, 1, 5, Route130_EventScript_1F73ED, 0

Route130_MapEvents:: @ 852CAA0
	map_events Route130_EventObjects, 0x0, 0x0, 0x0


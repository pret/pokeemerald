Route104_PrettyPetalFlowerShop_EventObjects: @ 8533B28
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A373, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_3, 0, 7, 3, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A40C, 0
	object_event 3, EVENT_OBJ_GFX_GIRL_1, 0, 11, 6, 4, MOVEMENT_TYPE_WANDER_AROUND, 2, 2, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A442, 0

Route104_PrettyPetalFlowerShop_MapWarps: @ 8533B70
	warp_def 2, 8, 0, 1, MAP_ROUTE104
	warp_def 3, 8, 0, 1, MAP_ROUTE104

Route104_PrettyPetalFlowerShop_MapEvents:: @ 8533B80
	map_events Route104_PrettyPetalFlowerShop_EventObjects, Route104_PrettyPetalFlowerShop_MapWarps, 0x0, 0x0


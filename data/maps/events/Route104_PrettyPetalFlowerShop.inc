Route104_PrettyPetalFlowerShop_MapObjects: @ 8533B28
	object_event 1, MAP_OBJ_GFX_WOMAN_3, 0, 0, 0, 3, 3, 10, 0, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A373, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GIRL_3, 0, 0, 7, 3, 3, 5, 1, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A40C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_GIRL_1, 0, 0, 11, 6, 4, 2, 34, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_22A442, 0, 0, 0

Route104_PrettyPetalFlowerShop_MapWarps: @ 8533B70
	warp_def 2, 8, 0, 1, ROUTE_104
	warp_def 3, 8, 0, 1, ROUTE_104

Route104_PrettyPetalFlowerShop_MapEvents:: @ 8533B80
	map_events Route104_PrettyPetalFlowerShop_MapObjects, Route104_PrettyPetalFlowerShop_MapWarps, 0x0, 0x0


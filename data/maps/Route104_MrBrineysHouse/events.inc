Route104_MrBrineysHouse_EventObjects: @ 8533AD4
	object_event 1, EVENT_OBJ_GFX_EXPERT_M, 0, 5, 3, 3, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_229D67, 739
	object_event 2, EVENT_OBJ_GFX_WINGULL, 0, 6, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_229E5D, 881

Route104_MrBrineysHouse_MapWarps: @ 8533B04
	warp_def 5, 8, 0, 0, MAP_ROUTE104
	warp_def 6, 8, 0, 0, MAP_ROUTE104

Route104_MrBrineysHouse_MapEvents:: @ 8533B14
	map_events Route104_MrBrineysHouse_EventObjects, Route104_MrBrineysHouse_MapWarps, 0x0, 0x0


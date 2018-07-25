Route114_LanettesHouse_EventObjects: @ 8533DD4
	object_event 1, EVENT_OBJ_GFX_WOMAN_3, 0, 5, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route114_LanettesHouse_EventScript_22B2D2, 870

Route114_LanettesHouse_MapWarps: @ 8533DEC
	warp_def 5, 7, 0, 2, MAP_ROUTE114
	warp_def 6, 7, 0, 2, MAP_ROUTE114

Route114_LanettesHouse_MapBGEvents: @ 8533DFC
	bg_event 5, 1, 0, BG_EVENT_PLAYER_FACING_ANY, Route114_LanettesHouse_EventScript_22B309
	bg_event 8, 1, 0, BG_EVENT_PLAYER_FACING_ANY, Route114_LanettesHouse_EventScript_22B345
	bg_event 7, 1, 0, BG_EVENT_PLAYER_FACING_ANY, Route114_LanettesHouse_EventScript_22B345

Route114_LanettesHouse_MapEvents:: @ 8533E20
	map_events Route114_LanettesHouse_EventObjects, Route114_LanettesHouse_MapWarps, 0x0, Route114_LanettesHouse_MapBGEvents


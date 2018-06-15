FortreeCity_House2_EventObjects: @ 8530F30
	object_event 1, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 2, 3, 3, 5, 1, 0, 0, FortreeCity_House2_EventScript_2177CB, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 6, 3, 3, 9, 1, 0, 0, FortreeCity_House2_EventScript_2C811E, 0

FortreeCity_House2_MapWarps: @ 8530F60
	warp_def 3, 5, 0, 4, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 4, MAP_FORTREE_CITY

FortreeCity_House2_MapEvents:: @ 8530F70
	map_events FortreeCity_House2_EventObjects, FortreeCity_House2_MapWarps, 0x0, 0x0


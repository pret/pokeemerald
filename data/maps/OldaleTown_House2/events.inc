OldaleTown_House2_EventObjects: @ 852D7F0
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 4, 4, 3, 10, 0, 0, 0, 0, OldaleTown_House2_EventScript_1FBF5B, 0
	object_event 2, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 7, 4, 3, 9, 0, 0, 0, 0, OldaleTown_House2_EventScript_1FBF64, 0

OldaleTown_House2_MapWarps: @ 852D820
	warp_def 3, 7, 0, 1, MAP_OLDALE_TOWN
	warp_def 4, 7, 0, 1, MAP_OLDALE_TOWN

OldaleTown_House2_MapEvents:: @ 852D830
	map_events OldaleTown_House2_EventObjects, OldaleTown_House2_MapWarps, 0x0, 0x0


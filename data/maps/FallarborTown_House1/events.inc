FallarborTown_House1_EventObjects: @ 852E5B8
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 6, 4, 3, 2, 1, 1, 0, 0, FallarborTown_House1_EventScript_200F13, 928
	object_event 2, EVENT_OBJ_GFX_WOMAN_3, 0, 5, 6, 3, 5, 1, 0, 0, 0, FallarborTown_House1_EventScript_200FBC, 0

FallarborTown_House1_MapWarps: @ 852E5E8
	warp_def 3, 8, 0, 3, MAP_FALLARBOR_TOWN
	warp_def 4, 8, 0, 3, MAP_FALLARBOR_TOWN

FallarborTown_House1_MapEvents:: @ 852E5F8
	map_events FallarborTown_House1_EventObjects, FallarborTown_House1_MapWarps, 0x0, 0x0


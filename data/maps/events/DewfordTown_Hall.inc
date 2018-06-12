DewfordTown_Hall_EventObjects: @ 852DC48
	object_event 1, EVENT_OBJ_GFX_GIRL_2, 0, 0, 4, 6, 0, 7, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD4D0, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_3, 0, 0, 1, 5, 0, 10, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD4F9, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_MAN_1, 0, 0, 5, 4, 0, 9, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD50A, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 9, 3, 0, 7, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD547, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 5, 2, 3, 7, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD563, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_LITTLE_BOY_2, 0, 0, 14, 7, 0, 5, 1, 0, 0, 0, DewfordTown_Hall_EventScript_1FD57F, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 0, 12, 3, 3, 10, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD62F, 0, 0, 0
	object_event 8, EVENT_OBJ_GFX_PSYCHIC_M, 0, 0, 15, 3, 3, 9, 0, 0, 0, 0, DewfordTown_Hall_EventScript_1FD63B, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_MANIAC, 0, 0, 8, 6, 3, 5, 1, 0, 0, 0, DewfordTown_Hall_EventScript_1FD7DA, 940, 0, 0

DewfordTown_Hall_MapWarps: @ 852DD20
	warp_def 5, 8, 0, 0, DEWFORD_TOWN
	warp_def 6, 8, 0, 0, DEWFORD_TOWN

DewfordTown_Hall_MapBGEvents: @ 852DD30
	bg_event 0, 1, 3, 0, 0, DewfordTown_Hall_EventScript_1FD590
	bg_event 7, 1, 3, 0, 0, DewfordTown_Hall_EventScript_1FD5A0

DewfordTown_Hall_MapEvents:: @ 852DD48
	map_events DewfordTown_Hall_EventObjects, DewfordTown_Hall_MapWarps, 0x0, DewfordTown_Hall_MapBGEvents


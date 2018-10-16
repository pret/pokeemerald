VerdanturfTown_FriendshipRatersHouse_EventObjects: @ 852E9C8
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 3, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, VerdanturfTown_FriendshipRatersHouse_EventScript_203031, 0
	object_event 2, EVENT_OBJ_GFX_PIKACHU, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, VerdanturfTown_FriendshipRatersHouse_EventScript_2030DA, 0

VerdanturfTown_FriendshipRatersHouse_MapWarps: @ 852E9F8
	warp_def 3, 7, 0, 5, MAP_VERDANTURF_TOWN
	warp_def 4, 7, 0, 5, MAP_VERDANTURF_TOWN

VerdanturfTown_FriendshipRatersHouse_MapEvents:: @ 852EA08
	map_events VerdanturfTown_FriendshipRatersHouse_EventObjects, VerdanturfTown_FriendshipRatersHouse_MapWarps, 0x0, 0x0


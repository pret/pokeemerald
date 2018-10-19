SlateportCity_OceanicMuseum_1F_EventObjects: @ 852F670
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 7, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AD96, 0
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 18, 5, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE5F, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 12, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE68, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 2, 8, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE56, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 5, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 3, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE4D, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 14, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE71, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 7, EVENT_OBJ_GFX_BEAUTY, 0, 12, 7, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AD96, 0
	object_event 8, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 8, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AE7A, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	object_event 9, EVENT_OBJ_GFX_WOMAN_5, 0, 4, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AED4, FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION
	object_event 10, EVENT_OBJ_GFX_MANIAC, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AEDD, FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION
	object_event 11, EVENT_OBJ_GFX_POKEFAN_M, 0, 17, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AEE6, FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION
	object_event 12, EVENT_OBJ_GFX_LITTLE_GIRL, 0, 18, 8, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AEEF, FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION
	object_event 13, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 9, 4, 3, MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AEF8, FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	object_event 14, EVENT_OBJ_GFX_REPORTER_M, 0, 7, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_OceanicMuseum_1F_EventScript_28C883, FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION

SlateportCity_OceanicMuseum_1F_MapWarps: @ 852F7C0
	warp_def 9, 8, 0, 5, MAP_SLATEPORT_CITY
	warp_def 10, 8, 0, 7, MAP_SLATEPORT_CITY
	warp_def 6, 1, 0, 0, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F

SlateportCity_OceanicMuseum_1F_MapCoordEvents: @ 852F7D8
	coord_event 9, 7, 3, VAR_0x40AA, 0, SlateportCity_OceanicMuseum_1F_EventScript_20AD9F
	coord_event 10, 7, 3, VAR_0x40AA, 0, SlateportCity_OceanicMuseum_1F_EventScript_20ADB0

SlateportCity_OceanicMuseum_1F_MapBGEvents: @ 852F7F8
	bg_event 2, 7, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE83
	bg_event 2, 4, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE8C
	bg_event 9, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE95
	bg_event 12, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE9E
	bg_event 10, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE95
	bg_event 13, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AE9E
	bg_event 15, 4, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AEA7
	bg_event 18, 4, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AEB0
	bg_event 18, 7, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AEB9
	bg_event 2, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AEC2
	bg_event 3, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AEC2
	bg_event 16, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AECB
	bg_event 17, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_OceanicMuseum_1F_EventScript_20AECB

SlateportCity_OceanicMuseum_1F_MapEvents:: @ 852F894
	map_events SlateportCity_OceanicMuseum_1F_EventObjects, SlateportCity_OceanicMuseum_1F_MapWarps, SlateportCity_OceanicMuseum_1F_MapCoordEvents, SlateportCity_OceanicMuseum_1F_MapBGEvents


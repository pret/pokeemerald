SlateportCity_PokemonFanClub_EventObjects: @ 852F574
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 11, 4, 0, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A1E8, 0
	object_event 2, EVENT_OBJ_GFX_TWIN, 0, 1, 5, 0, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 0, 1, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A1F1, 0
	object_event 3, EVENT_OBJ_GFX_REPORTER_F, 0, 11, 5, 0, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, SlateportCity_PokemonFanClub_EventScript_28C943, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_4, 0, 6, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A17E, 0
	object_event 5, EVENT_OBJ_GFX_GENTLEMAN, 0, 6, 5, 4, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SlateportCity_PokemonFanClub_EventScript_209E96, 0
	object_event 6, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 3, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A20D, 0
	object_event 7, EVENT_OBJ_GFX_SKITTY, 0, 8, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A1FA, 0
	object_event 8, EVENT_OBJ_GFX_AZUMARILL, 0, 10, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_PokemonFanClub_EventScript_20A220, 0
	object_event 9, EVENT_OBJ_GFX_MAN_4, 0, 11, 8, 0, MOVEMENT_TYPE_FACE_LEFT, 0, 1, 0, 0, SlateportCity_PokemonFanClub_EventScript_2C7F16, 0

SlateportCity_PokemonFanClub_MapWarps: @ 852F64C
	warp_def 6, 10, 0, 4, MAP_SLATEPORT_CITY
	warp_def 7, 10, 0, 4, MAP_SLATEPORT_CITY

SlateportCity_PokemonFanClub_MapEvents:: @ 852F65C
	map_events SlateportCity_PokemonFanClub_EventObjects, SlateportCity_PokemonFanClub_MapWarps, 0x0, 0x0


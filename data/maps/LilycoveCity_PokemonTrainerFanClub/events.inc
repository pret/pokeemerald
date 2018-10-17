LilycoveCity_PokemonTrainerFanClub_EventObjects: @ 8531D20
	object_event 1, EVENT_OBJ_GFX_LASS, 0, 3, 11, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CA8E, 0
	object_event 2, EVENT_OBJ_GFX_MAN_4, 0, 8, 10, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CA17, 0
	object_event 3, EVENT_OBJ_GFX_POKEFAN_M, 0, 6, 11, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CB05, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_GIRL, 0, 5, 8, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CB7C, 0
	object_event 5, EVENT_OBJ_GFX_NINJA_BOY, 0, 7, 11, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CBF3, FLAG_HIDE_FANCLUB_LITTLE_BOY
	object_event 6, EVENT_OBJ_GFX_BOY_2, 0, 1, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CC55, FLAG_HIDE_FANCLUB_BOY
	object_event 7, EVENT_OBJ_GFX_WOMAN_3, 0, 3, 10, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CCB7, FLAG_HIDE_FANCLUB_LADY
	object_event 8, EVENT_OBJ_GFX_EXPERT_F, 0, 10, 10, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CD19, FLAG_HIDE_FANCLUB_OLD_LADY
	object_event 9, EVENT_OBJ_GFX_BOY_1, 0, 11, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_21CD7B, FLAG_0x2DA

LilycoveCity_PokemonTrainerFanClub_MapWarps: @ 8531DF8
	warp_def 6, 13, 0, 5, MAP_LILYCOVE_CITY
	warp_def 5, 13, 0, 5, MAP_LILYCOVE_CITY

LilycoveCity_PokemonTrainerFanClub_MapEvents:: @ 8531E08
	map_events LilycoveCity_PokemonTrainerFanClub_EventObjects, LilycoveCity_PokemonTrainerFanClub_MapWarps, 0x0, 0x0


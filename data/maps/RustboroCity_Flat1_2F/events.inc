RustboroCity_Flat1_2F_EventObjects: @ 85308EC
	object_event 1, EVENT_OBJ_GFX_POKEFAN_F, 0, 4, 6, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 3, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_21523D, 0
	object_event 2, EVENT_OBJ_GFX_TWIN, 0, 9, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, 0
	object_event 3, EVENT_OBJ_GFX_SKITTY_DOLL, 0, 9, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_215246, 0
	object_event 4, EVENT_OBJ_GFX_TREECKO_DOLL, 0, 10, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_215246, 0
	object_event 5, EVENT_OBJ_GFX_TORCHIC_DOLL, 0, 10, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_215246, 0
	object_event 6, EVENT_OBJ_GFX_MAN_1, 0, 8, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_21513A, 0
	object_event 7, EVENT_OBJ_GFX_MUDKIP_DOLL, 0, 8, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_215246, 0
	object_event 8, EVENT_OBJ_GFX_PIKACHU_DOLL, 0, 9, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, RustboroCity_Flat1_2F_EventScript_215246, 0

RustboroCity_Flat1_2F_MapWarps: @ 85309AC
	warp_def 2, 1, 0, 2, MAP_RUSTBORO_CITY_FLAT1_1F

RustboroCity_Flat1_2F_MapEvents:: @ 85309B4
	map_events RustboroCity_Flat1_2F_EventObjects, RustboroCity_Flat1_2F_MapWarps, 0x0, 0x0


EverGrandeCity_DrakesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_GlaciasRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_PhoebesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_SidneysRoom_EventScript_2723F8:: @ 82723F8
PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles:: @ 82723F8
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_SidneysRoom_Movement_2725C6
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_GlaciasRoom_EventScript_272475:: @ 8272475
EverGrandeCity_PhoebesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_SidneysRoom_EventScript_272475:: @ 8272475
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_SidneysRoom_Movement_2725BA
	waitmovement 0
	playse SE_TRACK_DOOR
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_GlaciasRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_PhoebesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_SidneysRoom_EventScript_2724BC:: @ 82724BC
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	return

EverGrandeCity_DrakesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_GlaciasRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_PhoebesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_SidneysRoom_EventScript_27255F:: @ 827255F
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	return

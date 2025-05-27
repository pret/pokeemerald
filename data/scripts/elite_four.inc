PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFour_EventScript_WalkInCloseDoor::
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	special DrawWholeMapView
	return

@ Essentially unused, only necessary when re-entering an Elite Four room after defeating the member, which isnt normally possible
PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom::
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	return

PokemonLeague_EliteFour_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	return

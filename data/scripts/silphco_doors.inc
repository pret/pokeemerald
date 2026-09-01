EventScript_NeedCardKey::
	msgbox Text_ItNeedsCardKey
	releaseall
	end

EventScript_DoorUnlocked::
	msgbox Text_TheDoorIsOpen
	releaseall
	end

EventScript_Close2FDoor1::
	setmetatile 5, 8, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 6, 8, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 5, 9, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 6, 9, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 6, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close2FDoor2::
	setmetatile 5, 15, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 6, 15, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 5, 16, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 6, 16, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 6, 17, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close3FDoor1::
	setmetatile 9, 11, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 10, 11, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 9, 12, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 10, 12, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 9, 13, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 10, 13, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close3FDoor2::
	setmetatile 20, 11, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 21, 11, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 20, 12, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 21, 12, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 20, 13, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 21, 13, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close4FDoor1::
	setmetatile 3, 16, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 4, 16, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 3, 17, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 4, 17, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 4, 18, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close4FDoor2::
	setmetatile 14, 11, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 15, 11, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 14, 12, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 15, 12, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 15, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close5FDoor1:: @ 81AMETATILE_SilphCo_Floor_WallRightCornerF
	setmetatile 7, 8, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 8, 8, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 7, 9, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 8, 9, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 7, 10, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 8, 10, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close5FDoor2::
	setmetatile 7, 17, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 8, 17, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 7, 18, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 8, 18, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 7, 19, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 8, 19, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close5FDoor3::
	setmetatile 18, 12, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 19, 12, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 18, 13, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 19, 13, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 18, 14, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 19, 14, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close6FDoor::
	setmetatile 5, 14, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 6, 14, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 5, 15, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 6, 15, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 5, 16, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 6, 16, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close7FDoor1::
	setmetatile 11, 8, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 12, 8, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 11, 9, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 12, 9, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 12, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close7FDoor2::
	setmetatile 24, 7, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 25, 7, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 24, 8, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 25, 8, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 25, 9, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close7FDoor3::
	setmetatile 25, 13, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 26, 13, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 25, 14, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 26, 14, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 26, 15, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close8FDoor::
	setmetatile 5, 9, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 6, 9, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 5, 10, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 6, 10, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 5, 11, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 6, 11, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close9FDoor1::
	setmetatile 2, 9, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 3, 9, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 2, 10, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 3, 10, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 2, 11, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 3, 11, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close9FDoor2::
	setmetatile 12, 15, METATILE_SilphCo_VerticalBarrier_TopLeft, 1
	setmetatile 13, 15, METATILE_SilphCo_VerticalBarrier_TopRight, 1
	setmetatile 12, 16, METATILE_SilphCo_VerticalBarrier_MidLeft, 1
	setmetatile 13, 16, METATILE_SilphCo_VerticalBarrier_MidRight, 1
	setmetatile 12, 17, METATILE_SilphCo_VerticalBarrier_BottomLeft, 1
	setmetatile 13, 17, METATILE_SilphCo_VerticalBarrier_BottomRight, 1
	return

EventScript_Close9FDoor3::
	setmetatile 21, 6, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 22, 6, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 21, 7, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 22, 7, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 22, 8, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close9FDoor4::
	setmetatile 21, 12, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 22, 12, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 21, 13, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 22, 13, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 22, 14, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close10FDoor::
	setmetatile 12, 11, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 13, 11, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 12, 12, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 13, 12, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 13, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Close11FDoor::
	setmetatile 5, 16, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 6, 16, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 5, 17, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 6, 17, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 6, 18, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_Open2FDoor1::
	setmetatile 5, 8, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 8, METATILE_SilphCo_Floor, 0
	setmetatile 5, 9, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 9, METATILE_SilphCo_Floor, 0
	setmetatile 6, 10, METATILE_SilphCo_Floor, 0
	return

EventScript_Open2FDoor2::
	setmetatile 5, 15, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 15, METATILE_SilphCo_Floor, 0
	setmetatile 5, 16, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 16, METATILE_SilphCo_Floor, 0
	setmetatile 6, 17, METATILE_SilphCo_Floor, 0
	return

EventScript_Open3FDoor1::
	setmetatile 9, 11, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 10, 11, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 9, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 10, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 9, 13, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 10, 13, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open3FDoor2::
	setmetatile 20, 11, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 21, 11, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 20, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 21, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 20, 13, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 21, 13, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open4FDoor1::
	setmetatile 3, 16, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 4, 16, METATILE_SilphCo_Floor, 0
	setmetatile 3, 17, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 4, 17, METATILE_SilphCo_Floor, 0
	setmetatile 4, 18, METATILE_SilphCo_Floor, 0
	return

EventScript_Open4FDoor2::
	setmetatile 14, 11, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 15, 11, METATILE_SilphCo_Floor, 0
	setmetatile 14, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 15, 12, METATILE_SilphCo_Floor, 0
	setmetatile 15, 13, METATILE_SilphCo_Floor, 0
	return

EventScript_Open5FDoor1::
	setmetatile 7, 8, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 8, 8, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 7, 9, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 8, 9, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 7, 10, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 8, 10, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open5FDoor2::
	setmetatile 7, 17, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 8, 17, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 7, 18, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 8, 18, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 7, 19, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 8, 19, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open5FDoor3::
	setmetatile 18, 12, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 19, 12, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 18, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 19, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 19, 14, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open6FDoor::
	setmetatile 5, 14, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 6, 14, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 5, 15, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 15, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 5, 16, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 6, 16, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open7FDoor1::
	setmetatile 11, 8, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 8, METATILE_SilphCo_Floor, 0
	setmetatile 11, 9, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 9, METATILE_SilphCo_Floor, 0
	setmetatile 12, 10, METATILE_SilphCo_Floor, 0
	return

EventScript_Open7FDoor2::
	setmetatile 24, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 25, 7, METATILE_SilphCo_Floor, 0
	setmetatile 24, 8, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 25, 8, METATILE_SilphCo_Floor, 0
	setmetatile 25, 9, METATILE_SilphCo_Floor, 0
	return

EventScript_Open7FDoor3::
	setmetatile 25, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 26, 13, METATILE_SilphCo_Floor, 0
	setmetatile 25, 14, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 26, 14, METATILE_SilphCo_Floor, 0
	setmetatile 26, 15, METATILE_SilphCo_Floor, 0
	return

EventScript_Open8FDoor::
	setmetatile 5, 9, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 6, 9, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 5, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 5, 11, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 6, 11, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open9FDoor1::
	setmetatile 2, 9, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 3, 9, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 2, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 10, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 2, 11, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 3, 11, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open9FDoor2::
	setmetatile 12, 15, METATILE_SilphCo_Wall_LeftEdge, 1
	setmetatile 13, 15, METATILE_SilphCo_Wall_RightEdge, 1
	setmetatile 12, 16, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 13, 16, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 17, METATILE_SilphCo_Floor_WallLeftCorner, 0
	setmetatile 13, 17, METATILE_SilphCo_Floor_WallRightCorner, 0
	return

EventScript_Open9FDoor3::
	setmetatile 21, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 22, 6, METATILE_SilphCo_Floor, 0
	setmetatile 21, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 22, 7, METATILE_SilphCo_Floor, 0
	setmetatile 22, 8, METATILE_SilphCo_Floor, 0
	return

EventScript_Open9FDoor4::
	setmetatile 21, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 22, 12, METATILE_SilphCo_Floor, 0
	setmetatile 21, 13, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 22, 13, METATILE_SilphCo_Floor, 0
	setmetatile 22, 14, METATILE_SilphCo_Floor, 0
	return

EventScript_Open10FDoor::
	setmetatile 12, 11, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 13, 11, METATILE_SilphCo_Floor, 0
	setmetatile 12, 12, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 13, 12, METATILE_SilphCo_Floor, 0
	setmetatile 13, 13, METATILE_SilphCo_Floor, 0
	return

EventScript_Open11FDoor::
	setmetatile 5, 16, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 16, METATILE_SilphCo_Floor, 0
	setmetatile 5, 17, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 6, 17, METATILE_SilphCo_Floor, 0
	setmetatile 6, 18, METATILE_SilphCo_Floor, 0
	return

SilphCo_2F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8004, FLAG_SILPH_2F_DOOR_1
	goto_if_set FLAG_SILPH_2F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_2F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 2
	setvar VAR_0x8004, FLAG_SILPH_2F_DOOR_2
	goto_if_set FLAG_SILPH_2F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_3F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 3
	setvar VAR_0x8004, FLAG_SILPH_3F_DOOR_1
	goto_if_set FLAG_SILPH_3F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_3F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 4
	setvar VAR_0x8004, FLAG_SILPH_3F_DOOR_2
	goto_if_set FLAG_SILPH_3F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_4F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 5
	setvar VAR_0x8004, FLAG_SILPH_4F_DOOR_1
	goto_if_set FLAG_SILPH_4F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_4F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 6
	setvar VAR_0x8004, FLAG_SILPH_4F_DOOR_2
	goto_if_set FLAG_SILPH_4F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_5F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 7
	setvar VAR_0x8004, FLAG_SILPH_5F_DOOR_1
	goto_if_set FLAG_SILPH_5F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_5F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 8
	setvar VAR_0x8004, FLAG_SILPH_5F_DOOR_2
	goto_if_set FLAG_SILPH_5F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_5F_EventScript_Door3::
	lockall
	setvar VAR_TEMP_1, 9
	setvar VAR_0x8004, FLAG_SILPH_5F_DOOR_3
	goto_if_set FLAG_SILPH_5F_DOOR_3, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_6F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 10
	setvar VAR_0x8004, FLAG_SILPH_6F_DOOR
	goto_if_set FLAG_SILPH_6F_DOOR, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_7F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 11
	setvar VAR_0x8004, FLAG_SILPH_7F_DOOR_1
	goto_if_set FLAG_SILPH_7F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_7F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 12
	setvar VAR_0x8004, FLAG_SILPH_7F_DOOR_2
	goto_if_set FLAG_SILPH_7F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_7F_EventScript_Door3::
	lockall
	setvar VAR_TEMP_1, 13
	setvar VAR_0x8004, FLAG_SILPH_7F_DOOR_3
	goto_if_set FLAG_SILPH_7F_DOOR_3, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_8F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 14
	setvar VAR_0x8004, FLAG_SILPH_8F_DOOR
	goto_if_set FLAG_SILPH_8F_DOOR, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_9F_EventScript_Door1::
	lockall
	setvar VAR_TEMP_1, 15
	setvar VAR_0x8004, FLAG_SILPH_9F_DOOR_1
	goto_if_set FLAG_SILPH_9F_DOOR_1, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_9F_EventScript_Door2::
	lockall
	setvar VAR_TEMP_1, 16
	setvar VAR_0x8004, FLAG_SILPH_9F_DOOR_2
	goto_if_set FLAG_SILPH_9F_DOOR_2, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_9F_EventScript_Door3::
	lockall
	setvar VAR_TEMP_1, 17
	setvar VAR_0x8004, FLAG_SILPH_9F_DOOR_3
	goto_if_set FLAG_SILPH_9F_DOOR_3, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_9F_EventScript_Door4::
	lockall
	setvar VAR_TEMP_1, 18
	setvar VAR_0x8004, FLAG_SILPH_9F_DOOR_4
	goto_if_set FLAG_SILPH_9F_DOOR_4, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_10F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 19
	setvar VAR_0x8004, FLAG_SILPH_10F_DOOR
	goto_if_set FLAG_SILPH_10F_DOOR, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

SilphCo_11F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 20
	setvar VAR_0x8004, FLAG_SILPH_11F_DOOR
	goto_if_set FLAG_SILPH_11F_DOOR, EventScript_DoorUnlocked
	goto EventScript_TryUnlockDoor
	end

EventScript_TryUnlockDoor::
	goto_if_set FLAG_HIDE_SILPH_CO_5F_CARD_KEY, EventScript_OpenDoor
	goto EventScript_NeedCardKey
	end

EventScript_OpenDoor::
	playfanfare MUS_LEVEL_UP
	msgbox Text_CardKeyOpenedDoor
	waitfanfare
	call_if_eq VAR_TEMP_1, 1, EventScript_Open2FDoor1
	call_if_eq VAR_TEMP_1, 2, EventScript_Open2FDoor2
	call_if_eq VAR_TEMP_1, 3, EventScript_Open3FDoor1
	call_if_eq VAR_TEMP_1, 4, EventScript_Open3FDoor2
	call_if_eq VAR_TEMP_1, 5, EventScript_Open4FDoor1
	call_if_eq VAR_TEMP_1, 6, EventScript_Open4FDoor2
	call_if_eq VAR_TEMP_1, 7, EventScript_Open5FDoor1
	call_if_eq VAR_TEMP_1, 8, EventScript_Open5FDoor2
	call_if_eq VAR_TEMP_1, 9, EventScript_Open5FDoor3
	call_if_eq VAR_TEMP_1, 10, EventScript_Open6FDoor
	call_if_eq VAR_TEMP_1, 11, EventScript_Open7FDoor1
	call_if_eq VAR_TEMP_1, 12, EventScript_Open7FDoor2
	call_if_eq VAR_TEMP_1, 13, EventScript_Open7FDoor3
	call_if_eq VAR_TEMP_1, 14, EventScript_Open8FDoor
	call_if_eq VAR_TEMP_1, 15, EventScript_Open9FDoor1
	call_if_eq VAR_TEMP_1, 16, EventScript_Open9FDoor2
	call_if_eq VAR_TEMP_1, 17, EventScript_Open9FDoor3
	call_if_eq VAR_TEMP_1, 18, EventScript_Open9FDoor4
	call_if_eq VAR_TEMP_1, 19, EventScript_Open10FDoor
	call_if_eq VAR_TEMP_1, 20, EventScript_Open11FDoor
	waitse
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	special SetHiddenItemFlag
	releaseall
	end

Text_CardKeyOpenedDoor::
	.string "Bingo!\n"
	.string "The CARD KEY opened the door!$"

Text_ItNeedsCardKey::
	.string "No!\n"
	.string "It needs a CARD KEY!$"

Text_TheDoorIsOpen::
	.string "The door is open…$"

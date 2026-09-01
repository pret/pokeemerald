PokemonMansion_EventScript_SecretSwitch::
	msgbox PokemonMansion_Text_PressSecretSwitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PokemonMansion_EventScript_DontPressSwitch
	msgbox PokemonMansion_Text_WhoWouldnt
	goto_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_ResetSwitch
	setflag FLAG_POKEMON_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, PokemonMansion_EventScript_PressSwitch_1F
	case 1, PokemonMansion_EventScript_PressSwitch_2F
	case 2, PokemonMansion_EventScript_PressSwitch_3F
	case 3, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_EventScript_ResetSwitch::
	clearflag FLAG_POKEMON_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, PokemonMansion_EventScript_ResetSwitch_1F
	case 1, PokemonMansion_EventScript_ResetSwitch_2F
	case 2, PokemonMansion_EventScript_ResetSwitch_3F
	case 3, PokemonMansion_EventScript_ResetSwitch_B1F
	end

PokemonMansion_EventScript_DontPressSwitch::
	msgbox PokemonMansion_Text_NotQuiteYet
	releaseall
	end

PokemonMansion_EventScript_PressSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 22, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 32, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 33, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 31, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 32, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 33, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile  5,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

PokemonMansion_EventScript_ResetSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 23, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 24, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 22, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 23, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 24, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 27, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 28, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 29, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 27, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 28, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 29, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 32, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 33, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 34, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 32, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 33, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 34, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 31, 18, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 19, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile  5,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

PokemonMansion_EventScript_PressSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 15, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 28, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 10, 31, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 32, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 12,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile  2, 15, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

PokemonMansion_EventScript_ResetSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 25, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 26, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 24, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 25, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 26, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 10, 28, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 10, 31, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 10, 32, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 12,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile  2, 15, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

PokemonMansion_EventScript_PressSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 17, 12, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 21,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 21,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

PokemonMansion_EventScript_ResetSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 18, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 19, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 17, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 18, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 19, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 21,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 21,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

PokemonMansion_EventScript_PressSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 34, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 35, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 33, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 34, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 35, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 16, 26, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 16, 28, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 16, 29, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 16, 30, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12, 10, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 12, 11, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 12, 12, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 20, 22, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 20, 23, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	return

PokemonMansion_EventScript_ResetSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 33, 21, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 26, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 16, 28, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 16, 29, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 30, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12, 10, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 12, 11, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 12, 12, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 20, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 21, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 22, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 20, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 21, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 22, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	return

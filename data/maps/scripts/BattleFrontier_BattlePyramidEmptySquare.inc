BattleFrontier_BattlePyramidEmptySquare_MapScripts:: @ 8252A33
	map_script 5, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2
	map_script 2, BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43
	map_script 3, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA
	.byte 0

BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43: @ 8252A43
	map_script_2 VAR_0x400D, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D
	map_script_2 VAR_0x400E, 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98
	map_script_2 VAR_0x400F, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F
	.2byte 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D:: @ 8252A5D
	lockall
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	setvar VAR_0x8007, 55
	setvar VAR_RESULT, 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77:: @ 8252A77
	special sub_81A8E7C
	delay 2
	compare_var_to_value VAR_RESULT, 2
	goto_if 5, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77
	setvar VAR_0x400D, 0
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F:: @ 8252A8F
	special AddMapNamePopUpWindowTask
	setvar VAR_0x400F, 0
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98:: @ 8252A98
	playbgm BGM_BATTLE_PYRAMID, 0
	setvar VAR_0x400E, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2: @ 8252AA2
	setvar VAR_0x8004, 15
	special sub_81A8E7C
	setvar VAR_0x8004, 0
	special sub_81A1780
	switch VAR_0x4000
	case 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	case 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66
	case 2, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 4
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 5
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare_var_to_value VAR_RESULT, 3
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare_var_to_value VAR_RESULT, 9
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	special sub_81A1780
	setvar VAR_0x400D, 1

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39:: @ 8252B39
	setvar VAR_0x8004, 17
	special sub_81A8E7C
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42:: @ 8252B42
BattleFrontier_BattlePyramidTop_EventScript_252B42:: @ 8252B42
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 255
	special sub_81A8E7C

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66:: @ 8252B66
BattleFrontier_BattlePyramidTop_EventScript_252B66:: @ 8252B66
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A8E7C
	setvar VAR_0x8004, 14
	special sub_81A8E7C
	special sp000_heal_pokemon
	warpsilent BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D:: @ 8252B8D
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special sub_81A8E7C
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x8004, 9
	special sub_81A8E7C
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	setvar VAR_0x400F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA: @ 8252BCA
	call BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5
	setvar VAR_0x400F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5:: @ 8252BD5
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 32
	setvar VAR_0x8006, 0
	special sub_81A8E7C
	return


ShoalCave_LowTideStairsRoom_MapScripts:: @ 82370FA
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideStairsRoom_MapScript1_237100
	.byte 0

ShoalCave_LowTideStairsRoom_MapScript1_237100: @ 8237100
	call ShoalCave_LowTideStairsRoom_EventScript_237106
	end

ShoalCave_LowTideStairsRoom_EventScript_237106:: @ 8237106
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_237119
	setmetatile 11, 11, 856, 1
	return

ShoalCave_LowTideStairsRoom_EventScript_237119:: @ 8237119
	return

ShoalCave_LowTideStairsRoom_EventScript_23711A:: @ 823711A
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_23714C
	giveitem_std ITEM_SHOAL_SALT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setmetatile 11, 11, 858, 0
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_3
	releaseall
	end

ShoalCave_LowTideStairsRoom_EventScript_23714C:: @ 823714C
	msgbox ShoalCave_LowTideStairsRoom_Text_2A8169, MSGBOX_DEFAULT
	releaseall
	end


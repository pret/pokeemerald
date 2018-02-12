ShoalCave_LowTideStairsRoom_MapScripts:: @ 82370FA
	map_script 1, ShoalCave_LowTideStairsRoom_MapScript1_237100
	.byte 0

ShoalCave_LowTideStairsRoom_MapScript1_237100: @ 8237100
	call ShoalCave_LowTideStairsRoom_EventScript_237106
	end

ShoalCave_LowTideStairsRoom_EventScript_237106:: @ 8237106
	checkflag FLAG_0x3BA
	goto_eq ShoalCave_LowTideStairsRoom_EventScript_237119
	setmetatile 11, 11, 856, 1
	return

ShoalCave_LowTideStairsRoom_EventScript_237119:: @ 8237119
	return

ShoalCave_LowTideStairsRoom_EventScript_23711A:: @ 823711A
	lockall
	checkflag FLAG_0x3BA
	goto_eq ShoalCave_LowTideStairsRoom_EventScript_23714C
	giveitem_std ITEM_SHOAL_SALT
	compare VAR_RESULT, 0
	goto_eq ShoalCave_LowTideStairsRoom_EventScript_272054
	setmetatile 11, 11, 858, 0
	special DrawWholeMapView
	setflag FLAG_0x3BA
	releaseall
	end

ShoalCave_LowTideStairsRoom_EventScript_23714C:: @ 823714C
	msgbox ShoalCave_LowTideStairsRoom_Text_2A8169, 4
	releaseall
	end


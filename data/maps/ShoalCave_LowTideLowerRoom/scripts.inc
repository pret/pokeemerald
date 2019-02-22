ShoalCave_LowTideLowerRoom_MapScripts:: @ 8237156
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_MapScript1_23715C
	.byte 0

ShoalCave_LowTideLowerRoom_MapScript1_23715C: @ 823715C
	call ShoalCave_LowTideLowerRoom_EventScript_237162
	end

ShoalCave_LowTideLowerRoom_EventScript_237162:: @ 8237162
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_237175
	setmetatile 18, 2, 856, 1
	return

ShoalCave_LowTideLowerRoom_EventScript_237175:: @ 8237175
	return

ShoalCave_LowTideLowerRoom_EventScript_237176:: @ 8237176
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_2371A8
	giveitem_std ITEM_SHOAL_SALT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setmetatile 18, 2, 858, 0
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_4
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_2371A8:: @ 82371A8
	msgbox ShoalCave_LowTideLowerRoom_Text_2A8169, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_2371B2:: @ 82371B2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_2371E1
	msgbox ShoalCave_LowTideLowerRoom_Text_2371EB, MSGBOX_DEFAULT
	giveitem_std ITEM_FOCUS_BAND
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FOCUS_BAND
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_2371E1:: @ 82371E1
	msgbox ShoalCave_LowTideLowerRoom_Text_23728D, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideLowerRoom_Text_2371EB: @ 82371EB
	.string "The penetrating cold around these\n"
	.string "parts is an impediment to training.\p"
	.string "But with focus, one can overcome!\p"
	.string "With this FOCUS BAND, buckle down and\n"
	.string "withstand the cold!$"

ShoalCave_LowTideLowerRoom_Text_23728D: @ 823728D
	.string "Everything starts with focus!$"


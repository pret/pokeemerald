ShoalCave_LowTideLowerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_OnLoad
	.byte 0

ShoalCave_LowTideLowerRoom_OnLoad:
	call ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles::
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Large, 1
	return

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd::
	return

ShoalCave_LowTideLowerRoom_EventScript_ShoalSalt4::
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Small, 0
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_4
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt::
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand
	msgbox ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_BAND
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FOCUS_BAND
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand::
	msgbox ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus:
	.string "The penetrating cold around these\n"
	.string "parts is an impediment to training.\p"
	.string "But with focus, one can overcome!\p"
	.string "With this Focus Band, buckle down and\n"
	.string "withstand the cold!$"

ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus:
	.string "Everything starts with focus!$"


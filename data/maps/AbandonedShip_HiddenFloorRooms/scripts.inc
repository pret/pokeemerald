AbandonedShip_HiddenFloorRooms_MapScripts:: @ 8238C49
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_MapScript2_238C4F
	.byte 0

AbandonedShip_HiddenFloorRooms_MapScript2_238C4F: @ 8238C4F
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_238C59
	.2byte 0

AbandonedShip_HiddenFloorRooms_EventScript_238C59:: @ 8238C59
	setvar VAR_TEMP_1, 1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	setvar VAR_TEMP_4, 1
	compare VAR_TEMP_2, 21
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238CD1
	compare VAR_TEMP_2, 36
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238CD7
	compare VAR_TEMP_3, 2
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238CDD
	switch VAR_TEMP_4
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_238CE3
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_238D0C
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_238D0D
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_238D33
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_238D6B
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_238DB2
	end

AbandonedShip_HiddenFloorRooms_EventScript_238CD1:: @ 8238CD1
	addvar VAR_TEMP_4, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CD7:: @ 8238CD7
	addvar VAR_TEMP_4, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CDD:: @ 8238CDD
	addvar VAR_TEMP_4, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CE3:: @ 8238CE3
	delay 20
	setfieldeffectargument 0, 10
	setfieldeffectargument 1, 10
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
	compare VAR_RESULT, 0
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238DD3
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D0C:: @ 8238D0C
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D0D:: @ 8238D0D
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238D32
	delay 20
	compare VAR_RESULT, 0
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238DB3
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D32:: @ 8238D32
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D33:: @ 8238D33
	delay 20
	setfieldeffectargument 0, 8
	setfieldeffectargument 1, 5
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	setfieldeffectargument 0, 11
	setfieldeffectargument 1, 3
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
	compare VAR_RESULT, 0
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238DE3
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D6B:: @ 8238D6B
	delay 20
	setfieldeffectargument 0, 16
	setfieldeffectargument 1, 3
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	setfieldeffectargument 0, 25
	setfieldeffectargument 1, 2
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	setfieldeffectargument 0, 24
	setfieldeffectargument 1, 6
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
	compare VAR_RESULT, 0
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_238DC3
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238DB2:: @ 8238DB2
	end

AbandonedShip_HiddenFloorRooms_EventScript_238DB3:: @ 8238DB3
	setfieldeffectargument 0, 42
	setfieldeffectargument 1, 10
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DC3:: @ 8238DC3
	setfieldeffectargument 0, 20
	setfieldeffectargument 1, 5
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DD3:: @ 8238DD3
	setfieldeffectargument 0, 1
	setfieldeffectargument 1, 12
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DE3:: @ 8238DE3
	setfieldeffectargument 0, 1
	setfieldeffectargument 1, 2
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DF3:: @ 8238DF3
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_238DFE, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_238DFE: @ 8238DFE
	.string "It's bright and shiny!\n"
	.string "But it's just trash…$"


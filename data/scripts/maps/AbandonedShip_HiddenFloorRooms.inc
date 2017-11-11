AbandonedShip_HiddenFloorRooms_MapScripts:: @ 8238C49
	map_script 2, AbandonedShip_HiddenFloorRooms_MapScript2_238C4F
	.byte 0

AbandonedShip_HiddenFloorRooms_MapScript2_238C4F: @ 8238C4F
	map_script_2 VAR_0x4001, 0, AbandonedShip_HiddenFloorRooms_EventScript_238C59
	.2byte 0

AbandonedShip_HiddenFloorRooms_EventScript_238C59:: @ 8238C59
	setvar VAR_0x4001, 1
	getplayerxy VAR_0x4002, VAR_0x4003
	setvar VAR_0x4004, 1
	compare_var_to_value VAR_0x4002, 21
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238CD1
	compare_var_to_value VAR_0x4002, 36
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238CD7
	compare_var_to_value VAR_0x4003, 2
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238CDD
	switch VAR_0x4004
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_238CE3
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_238D0C
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_238D0D
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_238D33
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_238D6B
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_238DB2
	end

AbandonedShip_HiddenFloorRooms_EventScript_238CD1:: @ 8238CD1
	addvar VAR_0x4004, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CD7:: @ 8238CD7
	addvar VAR_0x4004, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CDD:: @ 8238CDD
	addvar VAR_0x4004, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_238CE3:: @ 8238CE3
	delay 20
	setfieldeffectargument 0, 10
	setfieldeffectargument 1, 10
	setfieldeffectargument 2, 0
	dofieldeffect 54
	specialvar VAR_RESULT, sub_81392F8
	compare_var_to_value VAR_RESULT, 0
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238DD3
	waitfieldeffect 54
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D0C:: @ 8238D0C
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D0D:: @ 8238D0D
	specialvar VAR_RESULT, sub_81392AC
	compare_var_to_value VAR_RESULT, 1
	goto_eq AbandonedShip_HiddenFloorRooms_EventScript_238D32
	delay 20
	compare_var_to_value VAR_RESULT, 0
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238DB3
	waitfieldeffect 54
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D32:: @ 8238D32
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D33:: @ 8238D33
	delay 20
	setfieldeffectargument 0, 8
	setfieldeffectargument 1, 5
	setfieldeffectargument 2, 0
	dofieldeffect 54
	setfieldeffectargument 0, 11
	setfieldeffectargument 1, 3
	setfieldeffectargument 2, 0
	dofieldeffect 54
	specialvar VAR_RESULT, sub_8139320
	compare_var_to_value VAR_RESULT, 0
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238DE3
	waitfieldeffect 54
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238D6B:: @ 8238D6B
	delay 20
	setfieldeffectargument 0, 16
	setfieldeffectargument 1, 3
	setfieldeffectargument 2, 0
	dofieldeffect 54
	setfieldeffectargument 0, 25
	setfieldeffectargument 1, 2
	setfieldeffectargument 2, 0
	dofieldeffect 54
	setfieldeffectargument 0, 24
	setfieldeffectargument 1, 6
	setfieldeffectargument 2, 0
	dofieldeffect 54
	specialvar VAR_RESULT, sub_81392D4
	compare_var_to_value VAR_RESULT, 0
	call_if 1, AbandonedShip_HiddenFloorRooms_EventScript_238DC3
	waitfieldeffect 54
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_238DB2:: @ 8238DB2
	end

AbandonedShip_HiddenFloorRooms_EventScript_238DB3:: @ 8238DB3
	setfieldeffectargument 0, 42
	setfieldeffectargument 1, 10
	setfieldeffectargument 2, 0
	dofieldeffect 54
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DC3:: @ 8238DC3
	setfieldeffectargument 0, 20
	setfieldeffectargument 1, 5
	setfieldeffectargument 2, 0
	dofieldeffect 54
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DD3:: @ 8238DD3
	setfieldeffectargument 0, 1
	setfieldeffectargument 1, 12
	setfieldeffectargument 2, 0
	dofieldeffect 54
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DE3:: @ 8238DE3
	setfieldeffectargument 0, 1
	setfieldeffectargument 1, 2
	setfieldeffectargument 2, 0
	dofieldeffect 54
	return

AbandonedShip_HiddenFloorRooms_EventScript_238DF3:: @ 8238DF3
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_238DFE, 4
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_238DFE: @ 8238DFE
	.string "It’s bright and shiny!\n"
	.string "But it’s just trash…$"


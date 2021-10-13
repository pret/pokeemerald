AbandonedShip_HiddenFloorRooms_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_OnFrame
	.byte 0

AbandonedShip_HiddenFloorRooms_OnFrame:
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle
	.2byte 0

@ After the below calculation, VAR_TEMP_4 is the room number of the door the player entered
@ Bottom row, left column   (Rm 1)
@ Bottom row, middle column (Rm 2)
@ Bottom row, right column	(Rm 3)
@ Upper row,  left column   (Rm 4)
@ Upper row,  middle column (Rm 5)
@ Upper row,  right column  (Rm 6)
AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle::
	setvar VAR_TEMP_1, 1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	setvar VAR_TEMP_4, 1
	compare VAR_TEMP_2, 21
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn
	compare VAR_TEMP_2, 36
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn
	compare VAR_TEMP_3, 2
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow
	switch VAR_TEMP_4
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6
	end

AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn::
	addvar VAR_TEMP_4, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn::
	addvar VAR_TEMP_4, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow::
	addvar VAR_TEMP_4, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1::
	delay 20
	dofieldeffectsparkle 10, 10, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2::
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3::
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle
	delay 20
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle::
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4::
	delay 20
	dofieldeffectsparkle 8, 5, 0
	dofieldeffectsparkle 11, 3, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5::
	delay 20
	dofieldeffectsparkle 16, 3, 0
	dofieldeffectsparkle 25, 2, 0
	dofieldeffectsparkle 24, 6, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6::
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle::
	dofieldeffectsparkle 42, 10, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle::
	dofieldeffectsparkle 20, 5, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle::
	dofieldeffectsparkle 1, 12, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle::
	dofieldeffectsparkle 1, 2, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Trash::
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash:
	.string "It's bright and shiny!\n"
	.string "But it's just trash…$"


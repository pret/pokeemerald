.set LOCALID_ATTENDANT, 1

SafariZone_South_MapScripts:: @ 823D279
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_OnFrame
	.byte 0

SafariZone_South_OnFrame: @ 823D284
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_EnterSafariZone
	.2byte 0

SafariZone_South_EventScript_EnterSafariZone:: @ 823D28E
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerEnter
	waitmovement 0
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_ExitAttendantBlockDoor
	waitmovement 0
	setobjectxyperm LOCALID_ATTENDANT, 32, 34
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

SafariZone_South_OnTransition: @ 823D2B1
	compare VAR_SAFARI_ZONE_STATE, 2
	call_if_eq SafariZone_South_EventScript_SetExitAttendantAside
	end

SafariZone_South_EventScript_SetExitAttendantAside:: @ 823D2BD
	setobjectxyperm LOCALID_ATTENDANT, 31, 34
	return

SafariZone_South_Movement_PlayerEnter: @ 823D2C5
	walk_down
	step_end

SafariZone_South_Movement_ExitAttendantBlockDoor: @ 823D2C7
	walk_right
	walk_in_place_fastest_down
	step_end

SafariZone_South_EventScript_Boy:: @ 823D2CA
	msgbox SafariZone_South_Text_Boy, MSGBOX_NPC
	end

SafariZone_South_EventScript_Man:: @ 823D2D3
	msgbox SafariZone_South_Text_Man, MSGBOX_NPC
	end

SafariZone_South_EventScript_Youngster:: @ 823D2DC
	msgbox SafariZone_South_Text_Youngster, MSGBOX_NPC
	end

SafariZone_South_EventScript_ExitAttendant:: @ 823D2E5
	lock
	faceplayer
	goto_if_unset FLAG_GOOD_LUCK_SAFARI_ZONE, SafariZone_South_EventScript_GoodLuck
	msgbox SafariZone_South_Text_StillHaveTimeExit, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SafariZone_South_EventScript_ExitEarly
	msgbox SafariZone_South_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
	release
	end

SafariZone_South_EventScript_GoodLuck:: @ 823D30D
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

SafariZone_South_EventScript_ExitEarly:: @ 823D31A
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, SafariZone_South_EventScript_ExitEarlyNorth
	case DIR_EAST, SafariZone_South_EventScript_ExitEarlyEast
	end

SafariZone_South_EventScript_ExitEarlyNorth:: @ 823D33F
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitNorth
	waitmovement 0
	goto SafariZone_South_EventScript_Exit
	end

SafariZone_South_EventScript_ExitEarlyEast:: @ 823D359
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitEast
	waitmovement 0
	goto SafariZone_South_EventScript_Exit
	end

SafariZone_South_EventScript_Exit:: @ 823D373
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warpdoor MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

SafariZone_South_Movement_PlayerExitNorth: @ 823D385
	walk_up
	step_end

SafariZone_South_Movement_PlayerExitEast: @ 823D387
	walk_right
	walk_in_place_fastest_up
	step_end

SafariZone_South_Movement_MoveExitAttendantNorth: @ 823D38A
	walk_left
	walk_in_place_fastest_right
	step_end

SafariZone_South_Movement_MoveExitAttendantEast: @ 823D38D
	walk_down
	walk_in_place_fastest_up
	step_end

SafariZone_South_EventScript_ConstructionWorker1:: @ 823D390
	msgbox SafariZone_South_Text_AreaOffLimits1, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_ExpansionZoneAttendant:: @ 823D399
	msgbox SafariZone_Southeast_Text_ExpansionIsFinished, MSGBOX_NPC
	end

SafariZone_South_EventScript_ConstructionWorker2:: @ 823D3A2
	msgbox SafariZone_South_Text_AreaOffLimits2, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_LittleGirl:: @ 823D3AB
	msgbox SafariZone_Southeast_Text_LittleGirl, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_FatMan:: @ 823D3B4
	msgbox SafariZone_Southeast_Text_FatMan, MSGBOX_NPC
	end

SafariZone_Southeast_EventScript_RichBoy:: @ 823D3BD
	msgbox SafariZone_Southeast_Text_RichBoy, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_Boy:: @ 823D3C6
	msgbox SafariZone_Northeast_Text_Boy, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_Woman:: @ 823D3CF
	msgbox SafariZone_Northeast_Text_Woman, MSGBOX_NPC
	end

SafariZone_Northeast_EventScript_Girl:: @ 823D3D8
	msgbox SafariZone_Northeast_Text_Girl, MSGBOX_NPC
	end

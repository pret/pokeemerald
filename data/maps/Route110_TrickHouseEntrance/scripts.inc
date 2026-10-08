Route110_TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_OnWarp
	.byte 0

	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
	@ 0: Trick Master is hiding
	@ 1: Trick Master has left at start of challenge
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
	@ 3: Trick Master still making next puzzle
	@ 4: Finished final puzzle
	@ 5: Completed previous challenge
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)

Route110_TrickHouseEntrance_OnTransition:
	setflag FLAG_LANDMARK_TRICK_HOUSE
	goto_if_eq VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1, Route110_TrickHouseEntrance_EventScript_EnterFromCorridor
	goto_if_eq VAR_TRICK_HOUSE_PRIZE_PICKUP, 1, Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward
	goto_if_eq VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
	case 1, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1
	case 3, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2
	case 4, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3
	end

Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
	end

Route110_TrickHouseEntrance_EventScript_EnterFromCorridor::
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_FinishedPuzzles
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2::
	call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3::
	call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4::
	call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5::
	call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6::
	call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7::
	call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8::
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_FinishedPuzzles::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
	return

Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	return

Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor::
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_OnWarp:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_TrickMasterFound
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
	.2byte 0

Route110_TrickHouseEntrance_EventScript_TrickMasterFound::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	turnobject LOCALID_PLAYER, DIR_WEST
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot::
	addobject LOCALID_TRICK_MASTER
	hideobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
	case 1, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
	case 2, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
	case 3, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
	case 4, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
	case 5, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
	case 6, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
	case 7, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1::
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2::
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3::
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4::
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5::
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6::
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7::
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8::
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
	end

Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster::
	removeobject LOCALID_TRICK_MASTER
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
	end

Route110_TrickHouseEntrance_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_BeginChallenge
	.2byte 0

Route110_TrickHouseEntrance_EventScript_BeginChallenge::
	lockall
	delay 20
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_MeetTrickMaster
	msgbox Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
	closemessage
	delay 20
	applywaitmovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_UnusedRelease::
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMaster::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_FoundTrickMaster
	case 2, Route110_TrickHouseEntrance_EventScript_GiveReward
	case 3, Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle
	case 6, Route110_TrickHouseEntrance_EventScript_MechadollReward
	end

Route110_TrickHouseEntrance_EventScript_FoundTrickMaster::
	playse SE_PIN
	applywaitmovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_PLAYER, Common_Movement_Delay48
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_FoundBehindTree
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_FoundInDresser
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_FoundInPlanter
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_FoundInCupboard
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_FoundBehindWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion
	closemessage
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindTree::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInDresser::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInPlanter::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInCupboard::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
	return

Route110_TrickHouse_Movement_TrickMasterSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Route110_TrickHouse_Movement_TrickMasterJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

Route110_TrickHouseEntrance_EventScript_MeetTrickMaster::
	msgbox Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle::
	msgbox Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
	msgbox Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GiveReward::
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	msgbox Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward::
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward::
	giveitem ITEM_TIMER_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward::
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward::
	giveitem ITEM_SMOKE_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward::
	giveitem ITEM_TM_TAUNT
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward::
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward::
	giveitem ITEM_PP_MAX
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GotReward::
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_MechadollReward::
	applywaitmovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	msgbox Route110_TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
	call Route110_TrickHouseEntrance_EventScript_ChooseTent
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_ReceivedTent
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEntrance_EventScript_GiveRedTent
	goto Route110_TrickHouseEntrance_EventScript_GiveBlueTent

Route110_TrickHouseEntrance_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEntrance_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEntrance_EventScript_ReceivedTent::
	msgbox Route110_TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TRICK_MASTER, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applywaitmovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ItsAScroll
	case 1, Route110_TrickHouseEntrance_EventScript_GoInHolePrompt
	case 4, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote
	case 5, Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage
	end

Route110_TrickHouseEntrance_EventScript_ItsAScroll::
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GoInHolePrompt::
	msgbox Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom::
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, FALSE
	special DrawWholeMapView
	delay 20
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkUp
	applywaitmovement LOCALID_PLAYER, Route110_TrickHouseEntrance_Movement_EnterRoom
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1
	case 1, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2
	case 2, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3
	case 3, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4
	case 4, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5
	case 5, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6
	case 6, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7
	case 7, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8
	end

Route110_TrickHouseEntrance_Movement_EnterRoom:
	set_invisible
	step_end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage::
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHousePuzzle1_EventScript_Door
	case 1, Route110_TrickHousePuzzle2_EventScript_Door
	case 2, Route110_TrickHousePuzzle3_EventScript_Door
	case 3, Route110_TrickHousePuzzle4_EventScript_Door
	case 4, Route110_TrickHousePuzzle5_EventScript_Door
	case 5, Route110_TrickHousePuzzle6_EventScript_Door
	case 6, Route110_TrickHousePuzzle7_EventScript_Door
	case 7, Route110_TrickHousePuzzle8_EventScript_Door
	end

Route110_TrickHousePuzzle1_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle4_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle6_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle8_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_DoorLocked::
	msgbox Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_ReadScrollAgain::
	msgbox Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_FoundScroll::
	playfanfare MUS_OBTAIN_ITEM
	message Route110_TrickHousePuzzle_Text_FoundAScroll
	waitfanfare
	msgbox Route110_TrickHousePuzzle_Text_MemorizedSecretCode, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMasterHiding::
	lockall
	msgbox Route110_TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1::
	setvar VAR_0x8004, 6  @ x
	setvar VAR_0x8005, 3  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2::
	setvar VAR_0x8004, 11  @ x
	setvar VAR_0x8005, 5   @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3::
	setvar VAR_0x8004, 9  @ x
	setvar VAR_0x8005, 2  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle::
	setvar VAR_0x8006, 0
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	return

Route110_TrickHouseEntrance_Text_YoureBeingWatched:
	.string "Iemand houdt je in de gaten…$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me onder dit\n"
	.string "bureau verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindTree:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me achter deze\n"
	.string "boom verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedInDresser:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me in deze\n"
	.string "kast verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConealedBeyondWindow:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me buiten dit\n"
	.string "raam verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedInPlanter:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me in deze\n"
	.string "plantenbak verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedInCupboard:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me in dit\n"
	.string "kastje verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindWindow:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me achter dit\n"
	.string "raam verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion:
	.string "Hè? Grrr…\p"
	.string "Hoe wist je dat ik me onder dit\n"
	.string "kussen verstopte? Jij bent slim!$"

Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster:
	.string "Kijk!\p"
	.string "Ik ben de man met de grootste\n"
	.string "geheimen van heel HOENN!\l"
	.string "Ze noemen mij…\p"
	.string "de TRICK MASTER!\n"
	.string "Wahahaha! Leuk je te ontmoeten!$"

Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse:
	.string "Jij, jij komt mijn TRICK HOUSE\n"
	.string "uitdagen, hè?\p"
	.string "Daarom ben je hier, toch?\n"
	.string "Ja, zeker!\p"
	.string "Ik neem je uitdaging aan!\p"
	.string "Ga door die rol daar naar binnen\n"
	.string "en laat de uitdaging beginnen!\p"
	.string "Ik wacht op je achterin!$"

Route110_TrickHouseEntrance_Text_ItsAScroll:
	.string "Het is een rol papier.$"

Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll:
	.string "Achter de rol zit een groot gat!\p"
	.string "Wil je erin?$"

Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote:
	.string "Er hangt een briefje op de rol…\p"
	.string "“Ik ga op reis. Zoek me niet.\n"
	.string "TRICK MASTER”$"

Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick:
	.string "De volgende keer gebruik ik deze truc,\n"
	.string "en dat plan, en die list…\p"
	.string "Mufufufu… Het is zelfs voor mij\n"
	.string "super moeilijk!$"

Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges:
	.string "Hè? Wat?!\n"
	.string "Oh, jij bent het!\p"
	.string "Ik ben nieuwe lastige uitdagingen\n"
	.string "aan het bedenken!\p"
	.string "Ik mag toch wel wat meer tijd\n"
	.string "hebben om na te denken?\l"
	.string "Dat gun je me toch wel?\l"
	.string "Kom zo nog maar eens terug!$"

Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward:
	.string "Ah, jij bent het! Je komt je beloning\n"
	.string "van laatst halen, toch?\l"
	.string "Ja, dat klopt!\p"
	.string "Hier!\n"
	.string "Je krijgt hem nu!$"

Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward:
	.string "Hè?\n"
	.string "Kom je je beloning niet halen?$"

Route110_TrickHouseEntrance_Text_MechadollWhichTent:
	.string "MECHADOLL 5 BEN IK!\n"
	.string "NEEM JIJ DE BELONING NIET,\l"
	.string "DAN KUN JE TRICK MASTER NIET VOLGEN.\p"
	.string "RODE TENT OF BLAUWE TENT,\n"
	.string "WELKE WIL JIJ?$"

Route110_TrickHouseEntrance_Text_ThenFarewell:
	.string "DAN VAARWEL.$"

Route110_TrickHouseEntrance_Text_PCFullAgain:
	.string "STATUS VAN JE PC: WEER VOL.\n"
	.string "GEMEEN, DAT BEN JE.$"

Route110_TrickHousePuzzle_Text_FoundAScroll:
	.string "{PLAYER} vindt een rol papier.$"

Route110_TrickHousePuzzle_Text_MemorizedSecretCode:
	.string "{PLAYER} onthoudt de geheime code\n"
	.string "die op de rol staat.$"

Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt:
	.string "Er staat een geheime code op.$"

Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere:
	.string "De deur zit op slot.\p"
	.string "…Als je goed kijkt, staat er:\n"
	.string "“Schrijf hier de geheime code.”$"

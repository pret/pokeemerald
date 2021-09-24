.set LOCALID_NORMAN, 1
.set LOCALID_WALLY, 10
.set LOCALID_WALLYS_DAD, 11

PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad:
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_eq PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	compare VAR_PETALBURG_GYM_STATE, 7
	call_if_ge PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition:
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_lt PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
	setobjectxyperm LOCALID_WALLY, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
	setobjectxyperm LOCALID_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch::
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm LOCALID_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman::
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial::
	addobject LOCALID_WALLY
	playse SE_DOOR
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyFaceDown
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown::
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges::
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge::
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
	return

PetalburgCity_Gym_EventScript_NormanPostBattle::
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2::
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch::
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
	specialvar VAR_RESULT, IsEnigmaBerryValid
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	compare VAR_ENIGMA_BERRY_AVAILABLE, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
	giveitem ITEM_ENIGMA_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle::
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject LOCALID_WALLYS_DAD
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade::
	giveitem ITEM_TM42
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM42
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrives::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	delay 10
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
	removeobject LOCALID_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysDadExitNorth:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysDadEnterGym:
	walk_up
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_Unused:
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest:
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor::
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom::
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, 255, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom::
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked::
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge::
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge::
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge::
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge::
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge::
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia::
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge::
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody::
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge::
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
	setvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
	setvar VAR_0x8004, 2
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
	setvar VAR_0x8004, 3
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
	setvar VAR_0x8004, 4
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
	setvar VAR_0x8004, 5
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
	setvar VAR_0x8004, 6
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
	setvar VAR_0x8004, 7
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
	setvar VAR_0x8004, 8
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
	special PetalburgGymSlideOpenRoomDoors
	waitstate
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors::
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory::
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified::
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue::
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
	.string "Dad: Hm?\p"
	.string "Well, if it isn't {PLAYER}!\n"
	.string "So you're all finished moving in?\p"
	.string "I'm surprised that you managed to\n"
	.string "get here by yourself.\p"
	.string "Oh, I see.\n"
	.string "You're with your Pokémon.\p"
	.string "Hm… Then I guess you're going to\n"
	.string "become a Trainer like me, {PLAYER}.\p"
	.string "That's great news!\n"
	.string "I'll be looking forward to it!$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
	.string "Um… I…\n"
	.string "I'd like to get a Pokémon, please…$"

PetalburgCity_Gym_Text_DadOhYoureWallyRight:
	.string "Dad: Hm? You're… Uh… Oh, right.\n"
	.string "You're Wally, right?$"

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
	.string "Wally: I'm going to go stay with my\n"
	.string "relatives in Verdanturf Town.\p"
	.string "I thought I would be lonely by myself,\n"
	.string "so I wanted to take a Pokémon along.\p"
	.string "But I've never caught a Pokémon before.\n"
	.string "I don't know how…$"

PetalburgCity_Gym_Text_DadHmISee:
	.string "Dad: Hm. I see.$"

PetalburgCity_Gym_Text_DadPlayerGoWithWally:
	.string "Dad: {PLAYER}, you heard that,\n"
	.string "right?\p"
	.string "Go with Wally and make sure that he\n"
	.string "safely catches a Pokémon.$"

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
	.string "Wally, here, I'll loan you my Pokémon.\p"
	.string "Wally received a Zigzagoon!$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
	.string "Wally: Oh, wow!\n"
	.string "A Pokémon!\p"
	.string "Dad: Hm. I'll give you a Poké Ball, too.\n"
	.string "Go for it!\p"
	.string "Wally received a Poké Ball!$"

PetalburgCity_Gym_Text_WallyOhWowThankYou:
	.string "Wally: Oh, wow!\n"
	.string "Thank you!$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
	.string "{PLAYER}… Would you really come\n"
	.string "with me?$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut:
	.string "Dad: So, did it work out?$"

PetalburgCity_Gym_Text_WallyThankYouBye:
	.string "Wally: Thank you, yes, it did.\n"
	.string "Here's your Pokémon back.\p"
	.string "{PLAYER}, thank you for coming along\n"
	.string "with me.\p"
	.string "You two are why I was able to catch\n"
	.string "my Pokémon.\p"
	.string "I promise I'll take really good\n"
	.string "care of it.\p"
	.string "Oh! My mom's waiting for me,\n"
	.string "so I have to go!\p"
	.string "Bye, {PLAYER}!$"

PetalburgCity_Gym_Text_DadGoCollectBadges:
	.string "Dad: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong Trainer, here's my advice.\p"
	.string "Head for Rustboro City beyond this\n"
	.string "town.\p"
	.string "There, you should challenge\n"
	.string "the Gym Leader, Roxanne.\p"
	.string "After her, go on to other Pokémon\n"
	.string "Gyms and defeat their Leaders.\p"
	.string "Collect Badges from them,\n"
	.string "understood?\p"
	.string "Of course, I'm a Gym Leader, too.\n"
	.string "We'll battle one day, {PLAYER}.\p"
	.string "But that's only after you become\n"
	.string "stronger.$"

PetalburgCity_Gym_Text_NormanGoToRustboro:
	.string "Dad: Hm? Aren't you going to the\n"
	.string "Pokémon Gym in Rustboro City?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn Trainer.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four Gym Badges, okay?$"

PetalburgCity_Gym_Text_NormanGoToDewford:
	.string "Dad: I see… So, you've beaten\n"
	.string "the Gym Leader in Rustboro City.\p"
	.string "But there are many more Trainers\n"
	.string "who are stronger than you, {PLAYER}.\p"
	.string "Across the sea in Dewford Town is a\n"
	.string "Gym Leader named Brawly.\p"
	.string "You should go challenge him.$"

PetalburgCity_Gym_Text_YouHaveGottenStronger:
	.string "Dad: Hm… {PLAYER}, you have gotten\n"
	.string "stronger.\p"
	.string "I can tell by the number of Badges\n"
	.string "that you've earned.$"

PetalburgCity_Gym_Text_NormanIntro:
	.string "Dad: Hm…\n"
	.string "So, you did get four Gym Badges.\p"
	.string "Fine, as I promised, we will have\n"
	.string "a Pokémon battle.\p"
	.string "{PLAYER}…\p"
	.string "I'm so happy that I can have\n"
	.string "a real battle with my own child.\p"
	.string "But, a battle is a battle!\p"
	.string "I will do everything in my power as\n"
	.string "a Gym Leader to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"

PetalburgCity_Gym_Text_NormanDefeat:
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it. {PLAYER}…\p"
	.string "I lost to {PLAYER}?\p"
	.string "But, rules are rules!\n"
	.string "Here, take this.$"

PetalburgCity_Gym_Text_ReceivedBalanceBadge:
	.string "{PLAYER} received the Balance Badge\n"
	.string "from Dad!$"

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
	.string "Dad: With that Badge, the Defense\n"
	.string "of all your Pokémon will increase.\p"
	.string "Pokémon that know the HM move Surf\n"
	.string "will be able to travel over water.\p"
	.string "This is my gift to you. {PLAYER}, I'm\n"
	.string "sure you can use it correctly.$"

PetalburgCity_Gym_Text_ExplainFacade:
	.string "Dad: TM42 contains Facade.\p"
	.string "It doubles the power of moves if\n"
	.string "the Pokémon is poisoned, paralyzed,\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"

PetalburgCity_Gym_Text_DadHappyAndSad:
	.string "Dad: As the Gym Leader, I can't\n"
	.string "express how upset I am…\p"
	.string "But as a father, it makes me both\n"
	.string "happy and a little sad. It's odd…$"

PetalburgCity_Gym_Text_PleaseComeWithMe:
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
	.string "Please come with me.\n"
	.string "I have something I want you to have.$"

PetalburgCity_Gym_Text_LetMeBorrowPlayer:
	.string "Norman, you don't mind, do you?\p"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
	.string "a minute or two.$"

PetalburgCity_Gym_Text_DadGoingToKeepTraining:
	.string "Dad: {PLAYER}, you should go visit\n"
	.string "your mother every so often.\p"
	.string "I'm going to stay here and redouble\n"
	.string "my training.\p"
	.string "It would bother me as a Trainer to\n"
	.string "not avenge my loss to you, {PLAYER}!$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
	.string "Dad: {PLAYER}, how are things going?\p"
	.string "The world of Pokémon is deep.\p"
	.string "I honestly think that no amount of\n"
	.string "training would ever be enough.$"

PetalburgCity_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "The doors in this Gym open when you\n"
	.string "beat the awaiting Trainers.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The Trainers of Petalburg Gym\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the Speed Room.\p"
	.string "The door at the right leads to\n"
	.string "the Accuracy Room.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"

PetalburgCity_Gym_Text_GymGuidePostVictory:
	.string "{PLAYER}! Whoa! You've overcome even\n"
	.string "your own father!\p"
	.string "Like, whoa!\n"
	.string "What a stunning turn of events!$"

PetalburgCity_Gym_Text_RandallIntro:
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"

PetalburgCity_Gym_Text_RandallDefeat:
	.string "That was a magnificent battle!$"

PetalburgCity_Gym_Text_RandallPostBattle:
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the Confusion Room.\p"
	.string "The right door leads to the Defense\n"
	.string "Room.$"

PetalburgCity_Gym_Text_RandallPostBadge:
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your Pokémon.\p"
	.string "That's what I think being a\n"
	.string "Gym Leader is all about.$"

PetalburgCity_Gym_Text_ParkerIntro:
	.string "This is the Confusion Room.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your Pokémon!$"

PetalburgCity_Gym_Text_ParkerDefeat:
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"

PetalburgCity_Gym_Text_ParkerPostBattle:
	.string "The next room is the Strength Room.\n"
	.string "Can you withstand brute force?$"

PetalburgCity_Gym_Text_ParkerPostBadge:
	.string "After you beat our Leader, the\n"
	.string "training has become a lot tougher.$"

PetalburgCity_Gym_Text_GeorgeIntro:
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"

PetalburgCity_Gym_Text_GeorgeDefeat:
	.string "I couldn't restore HP enough…\n"
	.string "What Attack power…$"

PetalburgCity_Gym_Text_GeorgePostBattle:
	.string "I should have expected no less from\n"
	.string "our Leader's kid.\p"
	.string "No, wait! A Trainer's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The One-hit KO Room is next.$"

PetalburgCity_Gym_Text_GeorgePostBadge:
	.string "I'm going to keep training at Gyms.\n"
	.string "One day, I'll become a Leader.$"

PetalburgCity_Gym_Text_BerkeIntro:
	.string "I'm not going to take it easy just\n"
	.string "because you're our Leader's kid.\p"
	.string "I'll show you how horrid it is for\n"
	.string "a Pokémon to take a critical hit!$"

PetalburgCity_Gym_Text_BerkeDefeat:
	.string "Your power…\n"
	.string "You're the real deal.$"

PetalburgCity_Gym_Text_BerkePostBattle:
	.string "Your father really is strong.\n"
	.string "He's a Trainer worth my respect.\p"
	.string "And, I sense the same glow coming\n"
	.string "from you as your father.\p"
	.string "I hope that you'll stage a terrific\n"
	.string "battle with your father!$"

PetalburgCity_Gym_Text_BerkePostBadge:
	.string "Since your dad became the Leader,\n"
	.string "the Trainers of Petalburg City have\l"
	.string "become a lot tougher.$"

PetalburgCity_Gym_Text_MaryIntro:
	.string "Giggle…\n"
	.string "This is the Accuracy Room.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"

PetalburgCity_Gym_Text_MaryDefeat:
	.string "You were a cut above me…$"

PetalburgCity_Gym_Text_MaryPostBattle:
	.string "There are some even stronger\n"
	.string "Trainers waiting for you.\p"
	.string "The left is the Defense Room, and\n"
	.string "the right is the Recovery Room.\p"
	.string "Your Pokémon's Attack power will be\n"
	.string "on trial either way.$"

PetalburgCity_Gym_Text_MaryPostBadge:
	.string "Do you know what we're trying to\n"
	.string "achieve as Trainers?\p"
	.string "We're striving to become soul mates\n"
	.string "with our Pokémon.$"

PetalburgCity_Gym_Text_AlexiaIntro:
	.string "The higher the Defense, the more\n"
	.string "reckless I can be in attack.$"

PetalburgCity_Gym_Text_AlexiaDefeat:
	.string "Our defenses weren't enough…$"

PetalburgCity_Gym_Text_AlexiaPostBattle:
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the Strength Room.\p"
	.string "The right door opens to\n"
	.string "the One-hit KO Room.\p"
	.string "Both of them have Trainers who are\n"
	.string "skilled at offense.$"

PetalburgCity_Gym_Text_AlexiaPostBadge:
	.string "Hi! Have you tried using Surf?$"

PetalburgCity_Gym_Text_JodyIntro:
	.string "Our Gym Leader told us to go all out\n"
	.string "and beat you.\p"
	.string "Even if you happen to be the\n"
	.string "Leader's kid!$"

PetalburgCity_Gym_Text_JodyDefeat:
	.string "But… I went all out!$"

PetalburgCity_Gym_Text_JodyPostBattle:
	.string "The way you use your Pokémon…\n"
	.string "It's like your father's style.\p"
	.string "Go on through! The Gym Leader, your\n"
	.string "father, is waiting!$"

PetalburgCity_Gym_Text_JodyPostBadge:
	.string "Sure, it's fine to make your Pokémon\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings Trainers have\n"
	.string "for their Pokémon.$"

PetalburgCity_Gym_Text_DoorAppearsLocked:
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_EnterSpeedRoom:
	.string "“Speed Room,” the sign says.\p"
	.string "Do you want to go through?$"

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2:
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_EnterAccuracyRoom:
	.string "“Accuracy Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterConfusionRoom:
	.string "“Confusion Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterDefenseRoom:
	.string "“Defense Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterRecoveryRoom:
	.string "“Recovery Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterStrengthRoom:
	.string "“Strength Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterOHKORoom:
	.string "“One-hit KO Room,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_EnterGymLeadersRoom:
	.string "“Gym Leader's Room\p"
	.string "“See for yourself what Pokémon await\n"
	.string "you!” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_GymStatue:
	.string "Petalburg City Pokémon Gym$"

PetalburgCity_Gym_Text_GymStatueCertified:
	.string "Petalburg City Pokémon Gym\p"
	.string "Norman's certified Trainers:\n"
	.string "{PLAYER}$"

PetalburgCity_Gym_Text_NormanPreRematch:
	.string "Dad: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a Gym, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "…No, because we are parent and child,\n"
	.string "we owe it to each other to do the best\l"
	.string "we can. Isn't that right, {PLAYER}?$"

PetalburgCity_Gym_Text_NormanRematchDefeat:
	.string "Uh… Haha…\n"
	.string "Maybe that was going too hard…$"

PetalburgCity_Gym_Text_NormanPostRematch:
	.string "Dad: {PLAYER}…\n"
	.string "What is your dream?\p"
	.string "My dream…\n"
	.string "Hahaha…\l"
	.string "It has already come true, actually.$"

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
	.string "Dad: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a Gym, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "Hm? Wait a second, {PLAYER}.\p"
	.string "Do you only have one Pokémon that is\n"
	.string "capable of battle?\p"
	.string "Sorry, but you'll have to come back\n"
	.string "with at least two Pokémon.$"


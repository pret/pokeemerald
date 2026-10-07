LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
	end

LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_SetRivalLeftForRoute103::
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_MoveRivalFromOldale::
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return

LittlerootTown_EventScript_MoveMomToMaysDoor::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
	return

LittlerootTown_EventScript_SetTwinPos::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos::
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
	return

LittlerootTown_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_EventScript_StepOffTruckMale::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_StepOffTruckFemale::
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_GoInsideWithMom::
	delay 15
	playse SE_LEDGE
	applywaitmovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_LITTLEROOT_MOM
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitHouse
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachDoor
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomEnterHouse
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideplayer
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_Movement_MomExitHouse:
	walk_down
	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
	delay 80
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_OnWarp:
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
	addobject LOCALID_LITTLEROOT_BIRCH
	addobject LOCALID_LITTLEROOT_RIVAL
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
	end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoSaveBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	release
	end

LittlerootTown_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
	lockall
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
	releaseall
	end

LittlerootTown_EventScript_DangerousWithoutPokemon::
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_TwinApproachPlayerLeft:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_TwinPushPlayerFromRoute:
	walk_down
	step_end

LittlerootTown_Movement_TwinReturnLeft:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_faster_down
	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
	releaseall
	end

LittlerootTown_Movement_TwinApproachPlayerRight:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

LittlerootTown_Movement_TwinReturnRight:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
	lockall
	applywaitmovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	releaseall
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 10, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger3::
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger4::
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger5::
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetHomeDoorCoordsMale::
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_MomNoticePlayerMale::
	applywaitmovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
	return

LittlerootTown_EventScript_MomNoticePlayerFemale::
	applywaitmovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
	return

LittlerootTown_EventScript_MomApproachPlayerMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomApproachPlayer0::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
	return

LittlerootTown_EventScript_MomApproachPlayer1::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
	return

LittlerootTown_EventScript_MomApproachPlayerMale2::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
	return

LittlerootTown_EventScript_MomApproachPlayerMale3::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
	return

LittlerootTown_EventScript_MomApproachPlayerMale4::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
	return

LittlerootTown_EventScript_MomApproachPlayerMale5::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale2::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
	return

LittlerootTown_EventScript_MomApproachPlayerFemale3::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
	return

LittlerootTown_EventScript_MomApproachPlayerFemale4::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
	return

LittlerootTown_EventScript_MomApproachPlayerFemale5::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomReturnHomeMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
	return

LittlerootTown_EventScript_MomReturnHomeFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
	return

LittlerootTown_EventScript_MomReturnHome0::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
	return

LittlerootTown_EventScript_MomReturnHome1::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
	return

LittlerootTown_EventScript_MomReturnHomeMale2::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale3::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale4::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale5::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale2::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale3::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale4::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale5::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_MomApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayerMale2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale4:
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale5:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale2:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale3:
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomReturnHome0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHome1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHomeMale2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale4:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale5:
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale3:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomExitThroughDoor:
	walk_up
	step_end

LittlerootTown_EventScript_Mom::
	lock
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	applywaitmovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes::
	removeobject LOCALID_LITTLEROOT_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_GiveRunningShoes::
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_Text_OurNewHomeLetsGoInside:
	.string "MAMA: {PLAYER}, we zijn er, lieverd!\p"
	.string "De rit in de verhuiswagen was\n"
	.string "vast vermoeiend.\p"
	.string "Dit is LITTLEROOT TOWN.\p"
	.string "Wat vind je ervan?\n"
	.string "Dit is ons nieuwe huis!\p"
	.string "Het is een klein dorp, maar het\n"
	.string "woont hier vast heel fijn.\p"
	.string "En je krijgt je eigen kamer, {PLAYER}!\n"
	.string "Kom, we gaan naar binnen.$"

LittlerootTown_Text_WaitPlayer:
	.string "MAMA: Wacht even, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "MAMA: {PLAYER}! {PLAYER}! Heb je je\n"
	.string "voorgesteld aan PROF. BIRCH?\p"
	.string "O! Wat een schattige POKéMON!\n"
	.string "Gekregen van PROF. BIRCH? Wat leuk!\p"
	.string "Je lijkt echt op je vader.\n"
	.string "Je past goed bij POKéMON!\p"
	.string "Hier, lieverd! Ga je op avontuur,\n"
	.string "doe dan deze RENSCHOENEN aan.\p"
	.string "Daarmee ben je supersnel!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} doet de RENSCHOENEN\n"
	.string "aan.$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "MAMA: {PLAYER}, er zit uitleg bij\n"
	.string "de schoenen.\p"
	.string "“Houd de B-knop ingedrukt met deze\n"
	.string "RENSCHOENEN aan om snel te rennen!\p"
	.string "“Trek de RENSCHOENEN aan en ren\n"
	.string "lekker door de natuur!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Je hebt nu je eigen\n"
	.string "POKéMON…\l"
	.string "Je vader zal zo blij zijn.\p"
	.string "…Maar wees wel voorzichtig.\n"
	.string "Als er iets is, kom je gewoon thuis.\p"
	.string "Ga maar, lieverd, zet 'm op!$"

LittlerootTown_Text_CanUsePCToStoreItems:
	.string "Met een PC kun je voorwerpen\n"
	.string "en POKéMON bewaren.\p"
	.string "Wetenschap is echt geweldig!$"

LittlerootTown_Text_BirchSpendsDaysInLab:
	.string "PROF. BIRCH zit dagenlang in zijn LAB.\n"
	.string "Dan gaat hij ineens weer naar buiten\l"
	.string "voor nog meer onderzoek…\p"
	.string "Wanneer is PROF. BIRCH nou\n"
	.string "eens thuis?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Eh, eh, eh!\p"
	.string "Als je buiten in het hoge gras loopt,\n"
	.string "springen er wilde POKéMON uit!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
	.string "Het is gevaarlijk als je geen\n"
	.string "eigen POKéMON hebt.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Eh, hoi!\p"
	.string "Er zijn enge POKéMON buiten!\n"
	.string "Ik hoor ze roepen!\p"
	.string "Ik wil gaan kijken wat er is,\n"
	.string "maar ik heb geen POKéMON…\p"
	.string "Wil jij voor mij gaan kijken\n"
	.string "wat er gebeurt?$"

LittlerootTown_Text_YouSavedBirch:
	.string "Je hebt PROF. BIRCH gered!\n"
	.string "Wat fijn!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Ga je POKéMON vangen?\n"
	.string "Veel succes!$"

LittlerootTown_Text_TownSign:
	.string "LITTLEROOT TOWN\n"
	.string "“Een dorp dat geen kleur kan krijgen.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "POKéMON-LAB VAN PROF. BIRCH$"

LittlerootTown_Text_PlayersHouse:
	.string "HUIS VAN {PLAYER}$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "HUIS VAN PROF. BIRCH$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRCH: Zo, zo, {PLAYER}{KUN}!\n"
	.string "Dat heb je goed gedaan!\p"
	.string "Ik zag meteen dat je bijzonder\n"
	.string "was toen ik je voor het eerst zag,\l"
	.string "maar dit had ik niet verwacht.\p"
	.string "O ja. Heb je de POKéDEX nog\n"
	.string "die ik je gaf?\p"
	.string "Ik wil je iets laten zien.\n"
	.string "Kom mee naar mijn LAB.$"


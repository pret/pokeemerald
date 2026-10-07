RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applywaitmovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	playse SE_EXIT
	delay 10
	addobject LOCALID_RUSTBORO_SCIENTIST
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
	playse SE_EXIT
	removeobject LOCALID_RUSTBORO_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applywaitmovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applywaitmovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_RUSTBORO_GRUNT
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	applywaitmovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
	removeobject LOCALID_RUSTBORO_GRUNT
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	fadedefaultbgm
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceRight
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceLeft
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint::
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.string "De DEVON CORPORATION…\n"
	.string "We zeggen gewoon DEVON.\p"
	.string "Dat bedrijf maakt allerlei\n"
	.string "handige spullen.$"

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.string "Hm? Een stiekeme man?\p"
	.string "Nu je het zegt, ja, er ging net\n"
	.string "een enge vent de hoek om.$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Heb je de POKéMON GYM al\n"
	.string "uitgedaagd?\p"
	.string "Als je die glimmende GYM BADGE\n"
	.string "hebt, snappen TRAINERS pas wat\l"
	.string "er van ze verwacht wordt.$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Hé, dat is de GYM BADGE van RUSTBORO!\p"
	.string "Van alle GYM BADGES vind ik die\n"
	.string "van RUSTBORO de coolste.$"

RustboroCity_Text_YoureNewAroundHere:
	.string "O? Wie ben jij?\n"
	.string "Jou heb ik hier nog nooit gezien.\p"
	.string "Zit je net op de\n"
	.string "POKéMON TRAINER'S SCHOOL?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "Ik heb de GYMLEIDER uitgedaagd,\n"
	.string "maar…\p"
	.string "Met mijn VUUR-POKéMON is het niet\n"
	.string "makkelijk om te winnen…\p"
	.string "VUUR-POKéMON zijn niet zo goed\n"
	.string "tegen STEEN-POKéMON…$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "De oude zeeman MR. BRINEY woont in\n"
	.string "een huisje aan zee.\p"
	.string "Hij gaat af en toe wandelen in\n"
	.string "de tunnel.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "De oude zeeman MR. BRINEY woont in\n"
	.string "een huisje aan zee.\p"
	.string "Hij zei dat hij in SLATEPORT ging\n"
	.string "winkelen voor zijn huisdier PEEKO.\p"
	.string "Die oude zeebonk houdt echt\n"
	.string "veel van PEEKO.$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Wauw, jij hebt ook POKéMON.\p"
	.string "Als ik groter ben, ga ik ook op\n"
	.string "reis met POKéMON.$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "POKéMON TRAINER'S SCHOOL!\p"
	.string "Als ik op deze school zit, kan ik\n"
	.string "dan makkelijk zeldzame POKéMON\l"
	.string "vangen?$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "Als een POKéMON ervaring krijgt in\n"
	.string "gevechten, kan hij soms van\l"
	.string "uiterlijk veranderen.$"

RustboroCity_Text_PokemonChangeShape:
	.string "Verandert een POKéMON van vorm?\n"
	.string "Als ik dat zag, zou ik me rot schrikken!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "Een POKéMON die je ruilt met\n"
	.string "iemand, groeit snel.\p"
	.string "Maar zonder bepaalde GYM BADGES\n"
	.string "luistert hij misschien niet…$"

RustboroCity_Text_OutOfTheWay:
	.string "Opzij!\n"
	.string "Uit de weg!$"

RustboroCity_Text_WaitDontTakeMyGoods:
	.string "Wacht! Alsjeblieeeft!\p"
	.string "Neem mijn PAKKET niet mee!$"

RustboroCity_Text_HelpMeIWasRobbed:
	.string "O, jij bent het!\p"
	.string "Jij bent die geweldige TRAINER die\n"
	.string "mij hielp in PETALBURG WOODS!\p"
	.string "Help! TEAM AQUA heeft me beroofd!\n"
	.string "Ik moet het DEVONPAKKET terug hebben!\p"
	.string "Anders…\n"
	.string "krijg ik heel grote problemen.$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.string "Die enge vent is volgens mij die\n"
	.string "kant op gerend, naar de tunnel.$"

RustboroCity_Text_YouGotItThankYou:
	.string "O! Hoe ging het?\n"
	.string "Het DEVONPAKKET?\p"
	.string "Je hebt het!\n"
	.string "Je hebt het terug!\p"
	.string "Jij bent echt een geweldige TRAINER!\p"
	.string "Weet je wat? Als bedankje krijg je\n"
	.string "nog een SUPERBALL!$"

RustboroCity_Text_YoureLoadedWithItems:
	.string "Je hebt veel te veel spullen.\n"
	.string "Ik kan je deze SUPERBALL niet geven.$"

RustboroCity_Text_PleaseComeWithMe:
	.string "Pardon!\n"
	.string "Kom alsjeblieft met me mee!$"

RustboroCity_Text_MayHiLetsRegister:
	.string "MAY: O, hoi, {PLAYER}{KUN}!\p"
	.string "Je hebt MATCH CALL in je\n"
	.string "POKéNAV!\p"
	.string "Laten we elkaar opslaan, dan kunnen\n"
	.string "we elkaar altijd bellen!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredMay:
	.string "MAY staat nu\n"
	.string "in de POKéNAV.$"

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.string "MAY: O, trouwens, ik zag MR. BRINEY\n"
	.string "in PETALBURG WOODS.\p"
	.string "Hij was vast op weg naar zijn\n"
	.string "huisje aan zee.\p"
	.string "Hoe gaat het met je POKéDEX,\n"
	.string "{PLAYER}{KUN}? Die van mij ziet er goed uit!\p"
	.string "Dus…\n"
	.string "Zullen we even vechten?$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.string "MAY: O, wat is er?\p"
	.string "Heb je nog niet zoveel POKéMON\n"
	.string "gevangen of getraind?\p"
	.string "Dat is niet zo goed voor een TRAINER!$"

RustboroCity_Text_MayWantToBattle:
	.string "MAY: Nou, wat vind je?\n"
	.string "Zullen we hier even vechten?$"

RustboroCity_Text_MayImNotGoingToLose:
	.string "MAY: Je bent net TRAINER,\n"
	.string "{PLAYER}{KUN}. Ik ga niet verliezen!$"

RustboroCity_Text_MayDefeat:
	.string "Help!\n"
	.string "Je bent beter dan ik dacht!$"

RustboroCity_Text_MayMrBrineyHint:
	.string "MAY: O, trouwens, MR. BRINEY, die ik\n"
	.string "net tegenkwam…\p"
	.string "{PLAYER}{KUN}, je woont hier pas, dus je\n"
	.string "weet het misschien niet, maar\l"
	.string "MR. BRINEY was vroeger een beroemde\l"
	.string "zeeman.$"

RustboroCity_Text_BrendanHiLetsRegister:
	.string "BRENDAN: O, hé, {PLAYER}!\p"
	.string "Je hebt MATCH CALL in je\n"
	.string "POKéNAV! Cool!\p"
	.string "Laten we elkaar opslaan, dan kunnen\n"
	.string "we elkaar altijd bellen!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredBrendan:
	.string "BRENDAN staat nu\n"
	.string "in de POKéNAV.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.string "BRENDAN: Trouwens, {PLAYER}, ik liep\n"
	.string "langs MR. BRINEY in PETALBURG WOODS.\p"
	.string "Hij was vast op weg naar zijn\n"
	.string "huisje aan zee.\p"
	.string "{PLAYER}, hoe gaat je POKéDEX?\n"
	.string "Staat er al wat in?\p"
	.string "Die van mij is top.\p"
	.string "Zullen we vechten, dan zien we\n"
	.string "hoe ver je al bent?$"

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.string "BRENDAN: Wat is er? Vertrouw je je\n"
	.string "POKéMON niet?$"

RustboroCity_Text_BrendanWantToBattle:
	.string "BRENDAN: Hé!\n"
	.string "Zin om tegen me te vechten?$"

RustboroCity_Text_BrendanIWontGoEasy:
	.string "BRENDAN: Je bent net TRAINER,\n"
	.string "maar ik doe niet zacht!$"

RustboroCity_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "Je bent best goed.$"

RustboroCity_Text_BrendanMrBrineyHint:
	.string "BRENDAN: Trouwens, ken je MR. BRINEY?\n"
	.string "Die man die ik net tegenkwam?\p"
	.string "Je woont hier pas, {PLAYER}, dus je\n"
	.string "weet het vast niet, maar MR. BRINEY\l"
	.string "was vroeger een geweldige zeeman.$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Tunnel bijna klaar!\n"
	.string "Sneller op je bestemming!”\p"
	.string "…Dat staat op het bord, maar er\n"
	.string "is ook een grote rode “X”\l"
	.string "overheen geverfd…$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“Alles wat je nodig hebt,\n"
	.string "maken wij.”$"

RustboroCity_Text_GymSign:
	.string "RUSTBORO CITY POKéMON GYM\n"
	.string "LEIDER: ROXANNE\p"
	.string "“Slimste leerling die van STEEN houdt!”$"

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.string "DEVON CORP. FILIAAL\p"
	.string "“Alleen voor medewerkers van DEVON\n"
	.string "en mensen met toestemming.”$"

RustboroCity_Text_CitySign:
	.string "RUSTBORO CITY\p"
	.string "“De stad waar natuur en wetenschap\n"
	.string "samenkomen.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“Wij leren je alles over\n"
	.string "POKéMON!”$"

RustboroCity_Text_CuttersHouse:
	.string "HUIS VAN DE SNOEIER$"

RustboroCity_Text_DevelopedNewPokenavFeature:
	.string "Ik heb iets nieuws gemaakt voor\n"
	.string "de POKéNAV…\p"
	.string "En het is super gelukt!\p"
	.string "{PLAYER}, mag ik je POKéNAV zien?\n"
	.string "Die je van onze DIRECTEUR kreeg?$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.string "Alsjeblieft, {PLAYER}!\p"
	.string "Ik heb MATCH CALL in je\n"
	.string "POKéNAV gezet.\p"
	.string "Met MATCH CALL kun je kletsen met\n"
	.string "mensen die in je POKéNAV\l"
	.string "staan.\p"
	.string "{PLAYER}, onze DIRECTEUR STONE staat\n"
	.string "al in je POKéNAV.\p"
	.string "Probeer het maar.\n"
	.string "Bel onze DIRECTEUR eens.$"

RustboroCity_Text_PleaseSelectPokenav:
	.string "Kies de POKéNAV.$"

RustboroCity_Text_IdBetterGetBackToWork:
	.string "Oké, ik moet weer aan het werk.\n"
	.string "Pas goed op jezelf, {PLAYER}!$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Wist je dit?\p"
	.string "Je kunt 2 tegen 2 vechten, ook als\n"
	.string "je niet met een andere TRAINER bent.\p"
	.string "Als twee TRAINERS je zien en je hebt\n"
	.string "twee of meer POKéMON, vechten\l"
	.string "ze allebei tegen je.\p"
	.string "Zou het niet cool zijn als jij in je\n"
	.string "eentje twee TRAINERS verslaat?$"

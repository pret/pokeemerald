.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM10  @ Hidden Power
	.2byte ITEM_TM43  @ Secret Power
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Je suis le MAITRE DE LA FORME!\n"
	.string "J’ai tout ce qu’il vous faut!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Ton {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Bien joué!\p"
	.string "En récompense, voici ce RUBAN \n"
	.string "pour ton POKéMON.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} reçoit le RUBAN.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} met le RUBAN \n"
	.string "sur {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Il faut que tu fasses plus d’efforts.\p"
	.string "Si tu le fais, je donnerai quelque\n"
	.string "chose de chouette à ton POKéMON.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Ton {STR_VAR_1}, ce RUBAN \n"
	.string "lui va bien!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La lumière du phare se voit à des\n"
	.string "kilomètres à la ronde.\p"
	.string "Je me demande si ça n’effraie pas les\n"
	.string "POKéMON dans la mer.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Oh, regarde ça!\p"
	.string "Les algues que l’on peut prendre par\n"
	.string "ici sont fraîches et pleines de vie.\p"
	.string "C’est comme si elles allaient se\n"
	.string "cabrer et attaquer!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Là où l’eau est propre, se regroupent\n"
	.string "les fruits de la généreuse récolte.\p"
	.string "Et là où les gens se rassemblent,\n"
	.string "s’établit un marché.\p"
	.string "C’est ainsi qu’une ville se crée et\n"
	.string "se développe.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Faire ses achats là où l’on peut sentir\n"
	.string "le souffle de l’océan…\p"
	.string "POIVRESSEL est un lieu si merveilleux!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si tu mets des POUPEES ou des COUSSINS\n"
	.string "par terre, ils seront salis.\p"
	.string "Je vais acheter des BRIQUES pour\n"
	.string "que mes POUPEES et mes COUSSINS ne\l"
	.string "soient pas salis.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Coool! Je vais bientôt aller me battre\n"
	.string "dans une TENTE DE COMBAT.\p"
	.string "Mais avant, il faut que j’attrape\n"
	.string "quelques POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Pfou… Je suis claqué…\p"
	.string "Je suis venu à pied de LAVANDIA.\p"
	.string "Cette ville est immense.\n"
	.string "Si j’avais su, je serais venu en VELO.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "POUPE, celui qui a fondé ce\n"
	.string "MUSEE, est aussi à la tête d’une \l"
	.string "équipe d’exploration sous-marine.\p"
	.string "Alors tout le monde l’appelle\n"
	.string "CAPT. POUPE.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Qu’est-ce que c’est que ça?\n"
	.string "Cette longue file…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Lorsque j’étais enfant, je venais\n"
	.string "souvent au MUSEE.\p"
	.string "Après avoir vu les expositions, je\n"
	.string "songeais aux mystères de la mer.$"

SlateportCity_Text_QuitPushing:
	.string "Hé, toi! Arrête de pousser!\n"
	.string "Tu vois pas que c’est la file d’attente?$"

SlateportCity_Text_AquaHasPolicy:
	.string "La TEAM AQUA a une règle concernant\n"
	.string "le rassemblement et la dispersion sur\l"
	.string "le lieu de l’action.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Notre CHEF est brillant.\p"
	.string "Mais que veut-il faire avec ce\n"
	.string "MUSEE?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Je me demande en quoi va consister le\n"
	.string "prochain projet.\p"
	.string "Enervé, notre CHEF est effrayant, alors\n"
	.string "j’ferais bien d’pas tout faire rater.$"

SlateportCity_Text_ShouldTakeItAll:
	.string "S’il y a quelque chose au MUSEE qui\n"
	.string "peut être utile, on n’a qu’à se servir!$"

SlateportCity_Text_DontButtIn:
	.string "Hé, toi, là!\n"
	.string "On ne coupe pas la queue!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Une longue file d’attente, hein?\p"
	.string "Ça me rappelle quand je faisais la queue\n"
	.string "pour acheter les jeux qui cartonnaient.$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Pourquoi on fait la queue pour payer?\n"
	.string "On n’a qu’à entrer après tout!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Quoi? Quoi?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Tu veux lire ce panneau?\n"
	.string "Je vais le lire pour toi!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Voyons…\p"
	.string "Hum… Je crois que ça dit\n"
	.string "que la vie dans la mer est éternelle.\p"
	.string "Ouaip, je suis sûr que c’est ce qui\n"
	.string "est écrit.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grumpf…\p"
	.string "J’aurais dû apporter ma Game Boy\n"
	.string "Advance pour jouer dans la file\l"
	.string "d’attente…\p"
	.string "Grumpf…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quand tout sera terminé, on ira\n"
	.string "ensemble aux sources chaudes!\p"
	.string "C’est ce que dit notre leader.\n"
	.string "J’ai super hâte!$"

SlateportCity_Text_SeaIsSoWet:
	.string "La mer est tellement vaste…\p"
	.string "La mer peut-elle être faite des larmes\n"
	.string "versées par les POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Tu sais ce qu’ils font des bateaux\n"
	.string "devenus trop usagés pour naviguer?\p"
	.string "Ils les font couler dans la mer pour\n"
	.string "qu’ils servent de refuge aux POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "A chaque fois que je viens ici, je me\n"
	.string "laisse emporter et j’achète trop.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si tu veux changer le surnom de l’un de\n"
	.string "tes POKéMON, va voir le SPECIALISTE\l"
	.string "DES NOMS.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Tu ne peux pas donner de surnom à un\n"
	.string "POKéMON échangé.\p"
	.string "L’amour du premier DRESSEUR de ce\n"
	.string "POKéMON est contenu dans ce surnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Une TENTE DE COMBAT a été\n"
	.string "récemment construite à POIVRESSEL.\p"
	.string "Les ARENES sont marrantes, mais les\n"
	.string "TENTES DE COMBAT, c’est autre chose.\p"
	.string "Tu devrais y aller si tu veux te battre\n"
	.string "contre des POKéMON redoutables.$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "J’espérais qu’il y aurait une grande\n"
	.string "star pour avoir un autographe.\p"
	.string "Mais qui est cet homme interviewé?\n"
	.string "Ne serait-ce pas le CAPT. POUPE?$"

SlateportCity_Text_InterviewerSoCool:
	.string "La journaliste est tellement sympa et\n"
	.string "si jolie.\p"
	.string "Quand je serai grande, je serai\n"
	.string "reporter international!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Le CAPT. POUPE dit qu’ils ont \n"
	.string "trouvé quelque chose au fond de la mer.\p"
	.string "Je me demande ce que c’est…\n"
	.string "Qu’est-ce que ça pourrait bien être?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Que se passe-t-il ici?\p"
	.string "Le bon CAPITAINE est-il revenu du\n"
	.string "fond de l’océan avec une grosse prise?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé! Tu regardes?\n"
	.string "Est-ce que je passe à la télé?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Une interview à la télé! Là!\n"
	.string "Le CAPITAINE est célèbre!$"

SlateportCity_Text_BigSmileForCamera:
	.string "GUY: OK, CAPT. POUPE,\n"
	.string "un sourire à la caméra!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "INES: Je vois, je vois. Vous avez\n"
	.string "vécu une expérience inestimable…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. POUPE: En effet! Nous comptons\n"
	.string "progresser grâce à notre exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "INES: Merveilleux, CAPT. POUPE!\n"
	.string "Merci de nous avoir accordé un peu\l"
	.string "de votre précieux temps.\p"
	.string "Nous espérons vous revoir pour\n"
	.string "discuter de nouvelles découvertes!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. POUPE: Ouh…\p"
	.string "C’était la première fois qu’on me\n"
	.string "filmait pour passer à la télé.\l"
	.string "C’était stressant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh, {PLAYER}{KUN}!\n"
	.string "Tu as l’air en pleine forme!\p"
	.string "Nous avons fait une grande découverte\n"
	.string "en explorant les fonds marins.\p"
	.string "Nous avons trouvé une caverne\n"
	.string "sous-marine sur le CHENAL 128.\p"
	.string "Nous pensons qu’il s’agit de l’habitat\n"
	.string "d’un POKéMON que nous croyions disparu.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Hum, hum…\n"
	.string "CAPT. POUPE, je suppose.\p"
	.string "Nous, la TEAM AQUA, allons prendre\n"
	.string "le contrôle de votre sous-marin!\p"
	.string "Il est inutile de vous y opposer!\n"
	.string "Nous comptons sur votre coopération!\p"
	.string "Hum, hum…\n"
	.string "Il ne vous reste plus qu’à découvrir\l"
	.string "ce que la TEAM AQUA a prévu de faire!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. POUPE: Qu’est-ce que ça pouvait\n"
	.string "bien être?\p"
	.string "On aurait dit quelqu’un avec\n"
	.string "un mégaphone…\p"
	.string "D’où ce son venait-il?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Ça vient de l’EMBARCADERE!\p"
	.string "Le sous-marin!\n"
	.string "Ils essaient de le prendre!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Viens avec moi!$"

SlateportCity_Text_BattleTentSign:
	.string "TENTE DE COMBAT de POIVRESSEL\n"
	.string "“Pour les meilleurs POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Recherche marin capable de\n"
	.string "naviguer sur tous les courants.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Le ferry LE MARINA desservant les\n"
	.string "embarcadères de POIVRESSEL et\l"
	.string "NENUCRIQUE sera bientôt terminé.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“L’embarquement sur le ferry\n"
	.string "LE MARINA entre POIVRESSEL et\l"
	.string "NENUCRIQUE se fait a l’EMBARCADERE.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "FAN CLUB POKéMON\n"
	.string "“Pour tous les fans de POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“La mer infinie supporte\n"
	.string "toutes les formes de vie.”\p"
	.string "MUSEE OCEANOGRAPHIQUE$"

SlateportCity_Text_CitySign:
	.string "POIVRESSEL\p"
	.string "“Le port où le chemin des hommes\n"
	.string "et celui des POKéMON se croisent.”$"

SlateportCity_Text_MarketSign:
	.string "MARCHE DE POIVRESSEL\n"
	.string "“Des objets uniques introuvables\l"
	.string "ailleurs!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Le ferry LE MARINA est\n"
	.string "en construction au CHANTIER NAVAL.”\p"
	.string "“Il devrait entrer en service\n"
	.string "sous peu.”$"

SlateportCity_Text_HarborSign:
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Profitez d’une merveilleuse croisière\n"
	.string "sur LE MARINA.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "MAISON DU SPECIALISTE DES NOMS\n"
	.string "“Conseil en surnoms de POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON sauvage est blessé,\n"
	.string "il se soigne en mâchant des BAIES.\p"
	.string "Tu le savais?\p"
	.string "En voyant ça, quelqu’un a eu l’idée de\n"
	.string "faire des médicaments à base de\l"
	.string "BAIES.\p"
	.string "Tu le savais?\p"
	.string "Pour transformer des BAIES en\n"
	.string "médicaments, il faut les réduire\l"
	.string "en poudre.\p"
	.string "Tu le savais?\p"
	.string "On dirait que tu t’intéresses\n"
	.string "aux BAIES!\p"
	.string "J’ai quelque chose qui va sûrement\n"
	.string "te plaire!$"

SlateportCity_Text_ExplainBerryPowder:
	.string "J’ai récemment fait installer des\n"
	.string "machines pour broyer les BAIES\l"
	.string "dans les CENTRES POKéMON.\p"
	.string "Les BROYEURS DE BAIES se\n"
	.string "trouvent dans la SALLE LINK DIRECT.\p"
	.string "Tu le savais?\p"
	.string "Pourrais-tu aller faire de la\n"
	.string "POUDRE BAIE pour moi en\p"
	.string "utilisant ces machines?\p"
	.string "Je ferai une préparation juste\n"
	.string "pour toi si tu arrives à broyer\p"
	.string "des BAIES et à me ramener\n"
	.string "la POUDRE BAIE.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "M’as-tu amené de la POUDRE BAIE?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Contre quoi veux-tu l’échanger?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Je vais te donner 1 {STR_VAR_1}\n"
	.string "contre la POUDRE BAIE.$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Hmm.\n"
	.string "Tu n’as pas assez de POUDRE BAIE.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Cette POUDRE BAIE a l’air bonne.\n"
	.string "Ça fera de bons médicaments.\p"
	.string "Tu veux échanger ce qui te reste de\n"
	.string "POUDRE BAIE contre autre chose?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "OK! Reviens-me voir quand tu auras\n"
	.string "plus de POUDRE BAIE!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Reviens me voir si tu veux échanger\n"
	.string "de la POUDRE BAIE contre des\l"
	.string "médicaments.\p"
	.string "Je fais toujours des affaires ici.\p"
	.string "Tu le savais?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hein?\n"
	.string "C’est pas la première fois qu’on se\l"
	.string "rencontre, non?\p"
	.string "Est-ce que je me suis déjà présenté?\n"
	.string "Je m’appelle SCOTT.\p"
	.string "Je viens de voir la TEAM AQUA partir\n"
	.string "d’ici en trombe.\p"
	.string "Laisse-moi deviner… C’est toi\n"
	.string "qui les as fait fuir?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hum…\n"
	.string "Peut-être…\p"
	.string "Peut-être que ce DRESSEUR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Très bien! Je pense que nous\n"
	.string "allons devenir amis.\p"
	.string "Echangeons nos numéros pour les\n"
	.string "enregistrer dans nos POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Vous avez enregistré SCOTT dans\n"
	.string "le POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: J’aimerais bien rester un peu\n"
	.string "avec toi, mais je veux aussi garder un\l"
	.string "œil sur les autres gens talentueux.\p"
	.string "Alors je vais visiter les autres villes\n"
	.string "pendant quelque temps encore.\p"
	.string "A bientôt, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Oh, mais…\n"
	.string "C’est bien toi, {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, je suis sûr que tu veux\n"
	.string "participer au défi de la\l"
	.string "TENTE DE COMBAT!\p"
	.string "C’est une bonne idée!\n"
	.string "C’est même une très bonne idée!\p"
	.string "Après tout, les bons DRESSEURS\n"
	.string "se doivent d’aller dans les\l"
	.string "TENTES DE COMBAT!\p"
	.string "Donne-toi à fond!$"

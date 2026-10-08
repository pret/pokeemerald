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
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
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
	applywaitmovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
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
	pokemartlistend

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
	applywaitmovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
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
	applywaitmovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
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
	pokemartlistend

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
	pokemartlistend

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
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	delay 10
	applywaitmovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
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
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
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
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Ik ben de ENERGY GURU! Ik ga ervoor\n"
	.string "en verkoop je wat je nodig hebt!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Je {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Die heeft zich enorm ingezet!\p"
	.string "Geef hem als beloning dit\n"
	.string "INZETLINT.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} krijgt het INZETLINT.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} doet het INZETLINT\n"
	.string "bij {STR_VAR_1} om.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Je moet nog wat harder je best doen.\p"
	.string "Dan geef ik je POKéMON iets\n"
	.string "leuks.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Dat INZETLINT staat je\n"
	.string "{STR_VAR_1} heel goed!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Het licht van de vuurtoren schijnt\n"
	.string "heel ver weg.\p"
	.string "Schrikken de POKéMON in de zee\n"
	.string "daar niet van?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Oeh, kijk eens!\p"
	.string "Het zeewier hier is vers en\n"
	.string "vol leven.\p"
	.string "Het lijkt wel alsof het zelf kan\n"
	.string "opspringen en aanvallen!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Waar het water schoon is, groeit\n"
	.string "veel lekker eten.\p"
	.string "En waar mensen samenkomen, begint\n"
	.string "al snel een markt.\p"
	.string "Zo ontstaat een stad en zo groeit hij.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Winkelen terwijl je de zee\n"
	.string "kunt ruiken…\p"
	.string "SLATEPORT is echt geweldig!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Als je DOLLS of KUSSENS op de\n"
	.string "vloer zet, worden ze vies.\p"
	.string "Ik koop BAKSTENEN, dan worden\n"
	.string "mijn DOLLS en KUSSENS niet vies.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! Ik doe ook mee in\n"
	.string "de BATTLE TENT!\p"
	.string "Maar eerst moet ik nog wat\n"
	.string "POKéMON vangen!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Pff… Ik ben doodop…\p"
	.string "Ik liep helemaal van MAUVILLE CITY.\n"
	.string "Maar wat is deze stad groot.\p"
	.string "Had ik dat geweten, dan was ik\n"
	.string "met mijn FIETS gekomen.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, de man die het MUSEUM\n"
	.string "bouwde, is ook de leider van een\l"
	.string "team dat de zeebodem onderzoekt.\p"
	.string "Daarom noemt iedereen hem\n"
	.string "CAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Wat is dat daar?\n"
	.string "Die lange rij…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Als kind ging ik vaak naar\n"
	.string "het MUSEUM.\p"
	.string "Na de tentoonstelling droomde ik\n"
	.string "altijd over de geheimen van de zee.$"

SlateportCity_Text_QuitPushing:
	.string "Hé, jij daar! Niet duwen!\n"
	.string "Dit is de rij, zie je dat niet?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA spreekt altijd af op\n"
	.string "de plek van de klus, en gaat daar\l"
	.string "ook weer uit elkaar.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Onze BAAS is superslim.\p"
	.string "Wat zou hij nou met een\n"
	.string "MUSEUM willen?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Wat is het nieuwe plan, vraag ik me af.\p"
	.string "Onze BAAS is eng als hij boos is.\n"
	.string "Ik moet het niet verpesten…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Als er iets in het MUSEUM is wat we\n"
	.string "nodig hebben, nemen we alles mee!$"

SlateportCity_Text_DontButtIn:
	.string "Hé, jij daar!\n"
	.string "Niet voordringen!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Een lange rij, hè?\p"
	.string "Daar denk ik aan de keren dat ik in\n"
	.string "de rij stond voor een supergame…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Waarom staan we in de rij en betalen\n"
	.string "we? We lopen gewoon naar binnen!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Wat?\n"
	.string "Wat wil je?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Wil je dit bord lezen?\n"
	.string "Ik lees het wel voor je voor!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Eens kijken…\p"
	.string "Eh… Ik denk dat er zoiets staat als\n"
	.string "“het leven in de zee is eindeloos.”\p"
	.string "Ja, ik weet bijna zeker dat\n"
	.string "dat er staat.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Mopper…\p"
	.string "Had ik mijn Game Boy Advance\n"
	.string "maar meegenomen tegen de verveling…\p"
	.string "Mopper…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Als deze klus klaar is, neem ik\n"
	.string "jullie mee naar een warme bron!\p"
	.string "Dat zei onze leider.\n"
	.string "Ik kan niet wachten!$"

SlateportCity_Text_SeaIsSoWet:
	.string "De zee is zo groot…\p"
	.string "Zou de zee gemaakt zijn van de\n"
	.string "tranen van POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Weet je wat ze doen met oude\n"
	.string "schepen die niet meer kunnen varen?\p"
	.string "Die laten ze zinken. Dan worden het\n"
	.string "fijne plekken voor POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Elke keer als ik hier kom, koop\n"
	.string "ik veel te veel.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Wil je de bijnaam van je POKéMON\n"
	.string "veranderen? Dan moet je naar\l"
	.string "de NAME RATER.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Van een geruilde POKéMON kun je\n"
	.string "de bijnaam niet veranderen.\p"
	.string "In die bijnaam zit de liefde van\n"
	.string "de eerste TRAINER voor die POKéMON.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Kort geleden is er een BATTLE TENT\n"
	.string "gebouwd in SLATEPORT.\p"
	.string "GYMS zijn leuk, maar de BATTLE TENT\n"
	.string "is op zijn eigen manier geweldig.\p"
	.string "Zoek maar sterke POKéMON voor de\n"
	.string "BATTLE TENT!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Ik hoopte dat het een beroemde ster\n"
	.string "was, voor een handtekening.\p"
	.string "Maar wie wordt daar geïnterviewd?\n"
	.string "Is dat niet CAPT. STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Die mevrouw die de vragen stelt,\n"
	.string "is zo stoer en mooi.\p"
	.string "Als ik groot ben, word ik ook\n"
	.string "verslaggever over de hele wereld!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "CAPT. STERN zegt dat ze iets op de\n"
	.string "zeebodem hebben gevonden.\p"
	.string "Wat zou het zijn?\n"
	.string "Wat kan het zijn?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Wat is hier aan de hand?\p"
	.string "Is de KAPITEIN terug met een grote\n"
	.string "vis van de bodem van de zee?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé! Kijk je mee?\n"
	.string "Sta ik op TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Een interview voor de tv! Hier!\n"
	.string "De KAPITEIN is beroemd!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Oké, CAPT. STERN, een grote\n"
	.string "lach voor de camera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Ik snap het. Dat was dus\n"
	.string "een heel waardevolle ervaring…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. STERN: Ja, zeker. We gaan\n"
	.string "gewoon verder met ons onderzoek.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Geweldig, CAPT. STERN!\n"
	.string "Bedankt dat u even tijd voor\l"
	.string "ons had, ondanks uw drukke dag.\p"
	.string "Hopelijk mogen we u nog eens\n"
	.string "spreken over nieuwe ontdekkingen!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. STERN: Pfff…\p"
	.string "Ik was voor het eerst op tv.\n"
	.string "Dat was best spannend.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "O! {PLAYER}{KUN}!\n"
	.string "Wat zie jij er goed uit!\p"
	.string "We hebben iets groots ontdekt\n"
	.string "op de zeebodem.\p"
	.string "We vonden een grot onder water\n"
	.string "bij ROUTE 128.\p"
	.string "We denken dat daar een POKéMON\n"
	.string "woont die al heel lang weg zou zijn.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "U bent vast CAPT. STERN.\p"
	.string "Wij van TEAM AQUA nemen uw\n"
	.string "duikboot over!\p"
	.string "Protesteren heeft geen zin!\n"
	.string "U doet gewoon wat wij zeggen!\p"
	.string "Fufufu…\n"
	.string "Kijk maar goed wat TEAM AQUA\l"
	.string "van plan is!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. STERN: Wat was dat nou?\p"
	.string "Het klonk alsof iemand door\n"
	.string "een megafoon praatte…\p"
	.string "Waar kwam het vandaan?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Het komt van de HAVEN!\p"
	.string "De duikboot!\n"
	.string "Ze willen hem stelen!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Kom alsjeblieft mee!$"

SlateportCity_Text_BattleTentSign:
	.string "BATTLE TENT SLATEPORT\n"
	.string "“Vind hem! De beste POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "SCHEEPSWERF VAN STERN\p"
	.string "“Gezocht: een zeeman die op elke\n"
	.string "stroming kan varen.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "SCHEEPSWERF VAN STERN\p"
	.string "“De veerboot S.S. TIDAL is bijna\n"
	.string "klaar. Hij gaat varen tussen\l"
	.string "SLATEPORT en LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "SCHEEPSWERF VAN STERN\p"
	.string "“Instappen op de veerboot S.S. TIDAL\n"
	.string "van SLATEPORT naar LILYCOVE\l"
	.string "gaat via de HAVEN.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB\n"
	.string "“Voor alle fans van POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“De eindeloze zee geeft\n"
	.string "alles wat leeft.”\p"
	.string "OCEANIC MUSEUM$"

SlateportCity_Text_CitySign:
	.string "SLATEPORT CITY\p"
	.string "“De haven waar mensen en POKéMON\n"
	.string "elkaar tegenkomen.”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKET\n"
	.string "“Spullen die je nergens anders vindt!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SLATEPORT HARBOR\p"
	.string "“De veerboot S.S. TIDAL wordt nog\n"
	.string "gebouwd in de SCHEEPSWERF.\p"
	.string "“Hij gaat binnenkort varen.”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HARBOR\p"
	.string "“Maak een fijne boottocht met\n"
	.string "de veerboot S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "HUIS VAN DE NAME RATER\n"
	.string "“Wij beoordelen bijnamen.”$"

SlateportCity_Text_ExplainBerries:
	.string "Als een wilde POKéMON gewond is,\n"
	.string "kauwt hij op BESSEN om te genezen.\p"
	.string "Wist je dat?\p"
	.string "Iemand zag dat en kreeg een idee:\n"
	.string "medicijnen maken van BESSEN.\p"
	.string "Wist je dat?\p"
	.string "Om er medicijnen van te maken,\n"
	.string "moet je BESSEN tot poeder malen.\p"
	.string "Wist je dat?\p"
	.string "Jij houdt zeker van BESSEN!\p"
	.string "Ik heb iets leuks voor iemand\n"
	.string "zoals jij.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Ik heb pas machines laten zetten\n"
	.string "in POKéMON CENTERS om BESSEN te malen.\p"
	.string "De BERRY CRUSH-machines staan\n"
	.string "boven, in de DIRECT CORNER.\p"
	.string "Wist je dat?\p"
	.string "Wil jij met die machines\n"
	.string "BESSENPOEDER voor me maken?\p"
	.string "Ik maak allerlei medicijnen voor je\n"
	.string "als je veel BESSENPOEDER brengt.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Heb je BESSENPOEDER voor me\n"
	.string "meegebracht?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Waarvoor wil je het\n"
	.string "ruilen?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Oké, wil je je BESSENPOEDER ruilen\n"
	.string "voor één {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "O jee. Je hebt niet genoeg\n"
	.string "BESSENPOEDER.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Dit is mooi BESSENPOEDER.\n"
	.string "Daar maak ik goede medicijnen van.\p"
	.string "Wil je nog meer BESSENPOEDER\n"
	.string "ruilen voor iets anders?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Oké! Heb je weer wat BESSENPOEDER,\n"
	.string "breng het dan naar mij!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Kom terug als je BESSENPOEDER\n"
	.string "wilt ruilen voor medicijnen.\p"
	.string "Ik sta hier altijd met mijn kraam.\p"
	.string "Wist je dat?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hè?\n"
	.string "Ik heb jou vast al eens gezien.\p"
	.string "Heb ik me al voorgesteld?\n"
	.string "Zo niet: ik heet SCOTT.\p"
	.string "Ik zag TEAM AQUA net hard\n"
	.string "wegrennen, alsof ze gestoken waren.\p"
	.string "Laat me raden: jij hebt ze\n"
	.string "weggejaagd?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm…\n"
	.string "Misschien, heel misschien,\l"
	.string "is deze TRAINER…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Top! Volgens mij worden wij\n"
	.string "goede vrienden.\p"
	.string "Laten we elkaar in onze\n"
	.string "POKéNAV zetten.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Die SCOTT staat nu\n"
	.string "in de POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Ik zou het liefst met je\n"
	.string "meegaan, maar ik wil ook andere\l"
	.string "mensen met talent zien.\p"
	.string "Dus ik ga nog wat rondkijken\n"
	.string "in andere steden.\p"
	.string "Tot ziens, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: O, hé!\n"
	.string "Dat is {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, laat me raden: jij gaat\n"
	.string "de BATTLE TENT uitdagen?\p"
	.string "Ja! Dat is een goed idee!\n"
	.string "Dat is echt een top idee!\p"
	.string "Een sterke TRAINER past\n"
	.string "perfect in de BATTLE TENT!\p"
	.string "Doe je best!$"

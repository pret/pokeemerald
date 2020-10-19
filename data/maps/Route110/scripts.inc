.set LOCALID_CHALLENGE_BIKER, 21
.set LOCALID_RIVAL, 28
.set LOCALID_RIVAL_ON_BIKE, 29
.set LOCALID_BIRCH, 36

Route110_MapScripts:: @ 81EF269
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume: @ 81EF279
	special UpdateCyclingRoadState
	end

Route110_OnTransition: @ 81EF27D
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_CYCLING_CHALLENGE_STATE, 1
	call_if_eq Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic:: @ 81EF293
	savebgm MUS_CYCLING
	return

Route110_OnFrame: @ 81EF297
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge:: @ 81EF2A1
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1:: @ 81EF2AA
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2:: @ 81EF2C0
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3:: @ 81EF2D6
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4:: @ 81EF2EC
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1:: @ 81EF302
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1:: @ 81EF30B
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1:: @ 81EF314
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan:: @ 81EF31D
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman:: @ 81EF326
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2:: @ 81EF32F
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2:: @ 81EF338
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign:: @ 81EF341
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign:: @ 81EF34A
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign:: @ 81EF353
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign:: @ 81EF35C
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign:: @ 81EF365
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign:: @ 81EF36E
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep:: @ 81EF377
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems:: @ 81EF380
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign:: @ 81EF389
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign:: @ 81EF392
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	compare VAR_RESULT, FALSE
	goto_if_eq Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet:: @ 81EF3AD
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy:: @ 81EF3B7
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_PlayerRidingAcroBike
	compare VAR_CYCLING_CHALLENGE_STATE, 0
	goto_if_eq Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike:: @ 81EF3DE
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike:: @ 81EF3E8
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward:: @ 81EF3F2
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn:: @ 81EF409
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin:: @ 81EF420
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle:: @ 81EF44C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch:: @ 81EF46B
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale:: @ 81EF482
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob:: @ 81EF499
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony:: @ 81EF4B0
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin:: @ 81EF4C7
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle:: @ 81EF4F3
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch:: @ 81EF512
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine:: @ 81EF529
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail:: @ 81EF540
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle:: @ 81EF56C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch:: @ 81EF58B
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel:: @ 81EF5A2
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle:: @ 81EF5CE
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch:: @ 81EF5ED
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy:: @ 81EF604
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused:: @ 81EF61B
	end

Route110_EventScript_Kaleb:: @ 81EF61C
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph:: @ 81EF633
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa:: @ 81EF64A
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd:: @ 81EF661
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults:: @ 81EF673
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest:: @ 81EF6FD
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood:: @ 81EF70B
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk:: @ 81EF719
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad:: @ 81EF727
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst:: @ 81EF735
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge:: @ 81EF743
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1:: @ 81EF74D
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2:: @ 81EF758
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3:: @ 81EF763
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene:: @ 81EF76E
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route110_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_RivalApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_RivalApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route110_EventScript_MayBattle
	compare VAR_RESULT, FEMALE
	goto_if_eq Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic:: @ 81EF7E1
	playbgm MUS_ENCOUNTER_MAY, 1
	return

Route110_EventScript_PlayBrendanMusic:: @ 81EF7E6
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	return

Route110_EventScript_MayBattle:: @ 81EF7EB
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko:: @ 81EF81A
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic:: @ 81EF82A
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip:: @ 81EF83A
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated:: @ 81EF84A
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle:: @ 81EF865
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko:: @ 81EF894
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic:: @ 81EF8A4
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip:: @ 81EF8B4
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated:: @ 81EF8C4
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder:: @ 81EF8DF
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit:: @ 81EF8EC
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_MoveRival1
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_MoveRival2
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_RivalExit1
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_RivalExit2
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1:: @ 81EF94E
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2:: @ 81EF959
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3:: @ 81EF964
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1:: @ 81EF96F
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2:: @ 81EF97A
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3:: @ 81EF985
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1:: @ 81EF990
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2:: @ 81EF998
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3:: @ 81EF9A0
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1: @ 81EF9A8
	walk_down
	walk_left
	walk_in_place_fastest_down
	step_end

Route110_Movement_RivalApproachPlayer2: @ 81EF9AC
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3: @ 81EF9AE
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

Route110_Movement_RivalExit1: @ 81EF9B2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2: @ 81EF9BA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3: @ 81EF9C3
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1:: @ 81EF9CB
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2:: @ 81EF9D6
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3:: @ 81EF9E1
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4:: @ 81EF9EC
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene:: @ 81EF9F7
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_BirchApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_BirchApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_BirchApproachPlayer3
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_BirchExit1
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_BirchExit2
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_BirchExit3
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_BirchExit4
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1:: @ 81EFAD8
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2:: @ 81EFAE3
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3:: @ 81EFAEE
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4:: @ 81EFAF9
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1:: @ 81EFB04
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2:: @ 81EFB0F
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3:: @ 81EFB1A
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4:: @ 81EFB25
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance: @ 81EFB30
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1: @ 81EFB34
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2: @ 81EFB39
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3: @ 81EFB3D
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4: @ 81EFB40
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1: @ 81EFB44
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2: @ 81EFB4B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3: @ 81EFB51
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4: @ 81EFB57
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities: @ 81EFB5D
	.string "TEAM AQUA's activities…\n"
	.string "We can't talk about them yet.$"

Route110_Text_KickUpARuckus: @ 81EFB93
	.string "I want to get going to SLATEPORT and\n"
	.string "kick up a ruckus!$"

Route110_Text_MyFirstJobInAqua: @ 81EFBCA
	.string "This is my first job after joining\n"
	.string "TEAM AQUA. It's a little scary.$"

Route110_Text_AquaActionsBringSmiles: @ 81EFC0D
	.string "TEAM AQUA's actions should bring\n"
	.string "smiles to people's faces!$"

Route110_Text_MayLetsBattle: @ 81EFC48
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
	.string "While I was searching for other\n"
	.string "POKéMON, my POKéMON grew stronger.\p"
	.string "So…\n"
	.string "How about a little battle?$"

Route110_Text_MayDefeated: @ 81EFCCB
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route110_Text_MayTakeThis: @ 81EFCF1
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
	.string "training, too, haven't you?\p"
	.string "I think you deserve a reward!\n"
	.string "This is from me!$"

Route110_Text_MayExplainItemfinder: @ 81EFD58
	.string "MAY: That's an ITEMFINDER.\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
	.string "I know it's a little silly coming from\n"
	.string "me, but I think you should train a lot\l"
	.string "harder for the next time.$"

Route110_Text_BrendanLetsBattle: @ 81EFE3F
	.string "BRENDAN: Hey, {PLAYER}.\n"
	.string "So this is where you were.\l"
	.string "How's it going?\p"
	.string "Have you been raising your POKéMON?\n"
	.string "I'll check for you.$"

Route110_Text_BrendanDefeated: @ 81EFEB4
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route110_Text_BrendanTakeThis: @ 81EFECD
	.string "BRENDAN: {PLAYER}, you've trained\n"
	.string "without me noticing…\p"
	.string "Good enough!\n"
	.string "Here, take this.$"

Route110_Text_BrendanExplainItemfinder: @ 81EFF1C
	.string "BRENDAN: That's an ITEMFINDER.\p"
	.string "Use it to root around for items that\n"
	.string "aren't visible.\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "Anyway, I'm off to look for new\n"
	.string "POKéMON.$"

Route110_Text_RideBikeAtFullSpeed: @ 81EFFC3
	.string "Wouldn't it be great to ride a BIKE\n"
	.string "at full speed on CYCLING ROAD?$"

Route110_Text_HairStreamsBehindMe: @ 81F0006
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"

Route110_Text_YouGotBikeFromRydel: @ 81F006A
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"

Route110_Text_TwoRoads: @ 81F0261
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and POKéMON.\n"
	.string "Perhaps that is right and fair.$"

Route110_Text_WalkOnTheLowRoad: @ 81F02CA
	.string "I don't have a BIKE, so I'll take\n"
	.string "a leisurely walk on the low road.$"

Route110_Text_BikeTechniques: @ 81F030E
	.string "Learning techniques will make BIKE\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a BIKE technique.$"

Route110_Text_WhichShouldIChoose: @ 81F0390
	.string "Which should I choose?\p"
	.string "Make a beeline for MAUVILLE on\n"
	.string "CYCLING ROAD, or take the low road\l"
	.string "and look for POKéMON?$"

Route110_Text_CyclingChallengeResultSummary: @ 81F03FF
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest: @ 81F0431
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Route110_Text_ChallengeReactionGood: @ 81F04A4
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Route110_Text_ChallengeReactionOk: @ 81F0500
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Route110_Text_ChallengeReactionBad: @ 81F0567
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Route110_Text_ChallengeReactionWorst: @ 81F05CE
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that BIKE to RYDEL.$"

Route110_Text_RatedForNumberOfCollisions: @ 81F0661
	.string "This is CYCLING ROAD.\p"
	.string "If you were to ride from MAUVILLE to\n"
	.string "SLATEPORT on a MACH BIKE, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"

Route110_Text_AlwaysAimHigher: @ 81F06FB
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"

Route110_Text_AcroBikesDoNotQualify: @ 81F0755
	.string "On this CYCLING ROAD, those riding\n"
	.string "MACH BIKES are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "ACRO BIKES do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_SlateportCitySign: @ 81F0812
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_CyclingRoadSign: @ 81F082D
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_AquaWasHere: @ 81F0842
	.string "“TEAM AQUA was here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“TEAM MAGMA rules!” is what it\n"
	.string "says now.$"

Route110_Text_Route103Sign: @ 81F08CD
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign: @ 81F08E3
	.string "SEASIDE PARKING$"

Route110_Text_MauvilleCitySign: @ 81F08F3
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_TrainerTipsPrlzSleep: @ 81F090D
	.string "TRAINER TIPS\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "POKéMON battles.$"

Route110_Text_TrainerTipsRegisterItems: @ 81F0992
	.string "TRAINER TIPS\p"
	.string "The items in the BAG can be reorganized\n"
	.string "by pressing SELECT.$"

Route110_Text_TrickHouseSign: @ 81F09DB
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous TRICK HOUSE.”$"

Route110_Text_BestRecord: @ 81F0A1E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord: @ 81F0A5E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

Route110_Text_ImagineSeeingYouHere: @ 81F0AB5
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Imagine seeing you here!\p"
	.string "And where might my {RIVAL} be?$"

Route110_Text_HeardYouInstallMatchCall: @ 81F0AFF
	.string "Oh, I see!\n"
	.string "You two are running separately.\l"
	.string "Well, that's fine.\p"
	.string "Oh, yes, I heard that your POKéNAV\n"
	.string "had the MATCH CALL system installed.\p"
	.string "Well, then, I should register you in\n"
	.string "my POKéNAV as well.\p"
	.string "That way, even when we're apart,\n"
	.string "I can rate your POKéDEX anytime.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav: @ 81F0C0C
	.string "Registered PROF. BIRCH\n"
	.string "in the POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival: @ 81F0C33
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
	.string "Please keep an eye out for my {RIVAL}.\n"
	.string "… … … … … …\p"
	.string "Well, I had better get going.\n"
	.string "See you again, {PLAYER}{KUN}!$"


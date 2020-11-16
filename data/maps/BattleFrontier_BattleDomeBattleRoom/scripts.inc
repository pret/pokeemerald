.set LOCALID_ANNOUNCER, 1
.set LOCALID_AUDIENCE_TWIN, 2
.set LOCALID_AUDIENCE_WALKING, 6
.set LOCALID_REFEREE, 9
.set LOCALID_PLAYER, 13
.set LOCALID_OPPONENT, 15

BattleFrontier_BattleDomeBattleRoom_MapScripts:: @ 824BC9C
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
	.byte 0

	.set NO_DRAW,       0
	.set DRAW_TRAINER,  1
	.set DRAW_TUCKER,   2

BattleFrontier_BattleDomeBattleRoom_OnTransition: @ 824BCB1
	dome_setopponentgfx
	frontier_get FRONTIER_DATA_BATTLE_NUM
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, DOME_ROUND1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx:: @ 824BCDC
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale:: @ 824BCF4
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale:: @ 824BCFA
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_OnFrame: @ 824BD00
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom:: @ 824BD0A
	lockall
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
	compare VAR_RESULT, DOME_ROUND1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
	closemessage
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
	compare VAR_TEMP_F, DOME_FINAL
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter:: @ 824BD4E
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer

BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker:: @ 824BD5A
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer:: @ 824BD61
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitmovement 0
	compare VAR_TEMP_F, DOME_FINAL
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent:: @ 824BD82
	dome_getopponentname
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
	waitmovement 0
	tower_getopponentintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	dome_initopponentparty
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
	setvar VAR_TEMP_2, NO_DRAW
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
	setvar VAR_TEMP_2, DRAW_TRAINER
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw:: @ 824BDF7
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
	waitmovement 0
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
	waitmovement 0
	delay 180
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
	waitmovement 0
	compare VAR_TEMP_2, DRAW_TUCKER  @ Tucker always wins on a draw
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
	dome_compareseeds
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent:: @ 824BE4F
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	dome_getopponentname
	compare VAR_TEMP_2, NO_DRAW
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
	compare VAR_TEMP_2, DRAW_TRAINER
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
	compare VAR_TEMP_2, DRAW_TUCKER
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney:: @ 824BE8D
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost:: @ 824BE9A
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon:: @ 824BEB1
	frontier_gettrainername 1
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw:: @ 824BEC5
	frontier_gettrainername 0
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw:: @ 824BED9
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent:: @ 824BEE0
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	compare VAR_TEMP_2, NO_DRAW
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
	compare VAR_TEMP_2, DRAW_TRAINER
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	dome_getroundtext
	dome_resolvewinners DOME_PLAYER_WON_MATCH
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
	setvar VAR_0x8006, 1
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 3
	waitstate

BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney:: @ 824BF62
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
	waitmovement 0
	frontier_get FRONTIER_DATA_LVL_MODE
	switch VAR_RESULT
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin

BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney:: @ 824BF96
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin:: @ 824BF9E
	special DoDomeConfetti
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon:: @ 824BFC3
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw:: @ 824BFCC
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer:: @ 824BFD5
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
	dome_get DOME_DATA_HAS_WON_CHALLENGE
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt:: @ 824C023
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1:: @ 824C05A
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2:: @ 824C061
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal:: @ 824C068
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal:: @ 824C06F
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon:: @ 824C076
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1:: @ 824C0AD
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2:: @ 824C0B4
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal:: @ 824C0BB
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal:: @ 824C0C2
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion:: @ 824C0C9
	compare VAR_TEMP_F, DOME_FINAL
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker:: @ 824C105
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1:: @ 824C13C
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2:: @ 824C143
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal:: @ 824C14A
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal:: @ 824C151
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver:: @ 824C158
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold:: @ 824C161
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak:: @ 824C16A
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1:: @ 824C1A1
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2:: @ 824C1A8
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal:: @ 824C1AF
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal:: @ 824C1B6
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum:: @ 824C1BD
	frontier_get FRONTIER_DATA_BATTLE_NUM
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker:: @ 824C1CB
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver:: @ 824C1FC
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter

BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold:: @ 824C209
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter:: @ 824C211
	closemessage
	applymovement LOCALID_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	waitmovement 0
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
	waitmessage
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver:: @ 824C2B9
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
	switch VAR_RESULT
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
	dome_resolvewinners DOME_PLAYER_WON_MATCH
	frontier_getsymbols
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
	closemessage
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney

BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro:: @ 824C346
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold:: @ 824C373
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
	switch VAR_RESULT
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
	dome_resolvewinners DOME_PLAYER_WON_MATCH
	frontier_getsymbols
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
	closemessage
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney

BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle:: @ 824C400
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
	waitmovement 0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker:: @ 824C420
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	waitse
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney

BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw:: @ 824C436
	setvar VAR_TEMP_2, DRAW_TUCKER
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw

BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle:: @ 824C440
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
	setvar VAR_0x8005, 0
	setvar VAR_TEMP_9, 1
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_TEMP_9, 0
	dome_restorehelditems
	special HealPlayerParty
	dome_resetsketch
	return

BattleFrontier_BattleDomeBattleRoom_OnWarp: @ 824C481
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects:: @ 824C48B
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, DOME_FINAL
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
	frontier_getbrainstatus
	copyvar VAR_TEMP_E, VAR_RESULT
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
	call BattleFrontier_EventScript_SetBrainObjectGfx
	setobjectxyperm LOCALID_OPPONENT, 13, 9
	removeobject LOCALID_OPPONENT
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects:: @ 824C4EF
	end

BattleFrontier_BattleDomeBattleRoom_OnResume: @ 824C4F0
	compare VAR_TEMP_9, 1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience:: @ 824C4FC
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
	return

@ Add audience members to supplement the permanent object event audience
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience:: @ 824C502
	compare VAR_TEMP_F, DOME_ROUND1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
	compare VAR_TEMP_F, DOME_ROUND2
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
	compare VAR_TEMP_F, DOME_SEMIFINAL
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
	compare VAR_TEMP_F, DOME_FINAL
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience:: @ 824C52F
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience:: @ 824C530
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience:: @ 824C594
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2, 3, 1
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience:: @ 824C652
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2, 3, DIR_SOUTH
	return

BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible: @ 824C773
	set_invisible
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter: @ 824C775
	set_visible
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward: @ 824C77B
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience: @ 824C77D
	walk_up
	step_end

@ Identical to Movement_PlayerEnter
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker: @ 824C77F
	set_visible
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2: @ 824C787
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward: @ 824C789
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp: @ 824C78B
	face_up
	set_invisible
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance: @ 824C78E
	set_visible
	walk_up
	walk_up
	walk_up
	face_left
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_left
	delay_16
	walk_fast_up
	walk_fast_up
	face_left
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_left
	jump_2_left
	unlock_facing_direction
	face_up
	lock_facing_direction
	jump_2_left
	jump_2_left
	unlock_facing_direction
	face_right
	lock_facing_direction
	jump_2_left
	unlock_facing_direction
	face_down
	delay_2
	face_left
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	lock_facing_direction
	walk_right
	walk_slow_right
	walk_right
	walk_slow_right
	unlock_facing_direction
	face_up
	delay_16
	jump_in_place_up
	jump_in_place_up
	delay_16
	walk_right
	walk_right
	walk_right
	jump_in_place_up
	delay_16
	walk_right
	walk_down
	walk_down
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_4
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance: @ 824C7F9
	delay_16
	delay_16
	walk_left
	walk_left
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward: @ 824C829
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer: @ 824C82B
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround:: @ 824C82E
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 24, DIR_EAST
	turnvobject 26, DIR_EAST
	turnvobject 28, DIR_EAST
	turnvobject 30, DIR_EAST
	delay 20
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_SOUTH
	turnvobject 28, DIR_SOUTH
	turnvobject 30, DIR_SOUTH
	delay 20
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_EAST
	turnvobject 23, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 31, DIR_WEST
	delay 20
	turnvobject 1, DIR_SOUTH
	turnvobject 3, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 9, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 17, DIR_SOUTH
	turnvobject 19, DIR_SOUTH
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 25, DIR_SOUTH
	turnvobject 27, DIR_SOUTH
	turnvobject 31, DIR_SOUTH
	delay 20
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby:: @ 824C8F5
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 5, 11
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles:: @ 824C90F
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 17, 11
	waitstate
	end

@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos:: @ 824C919
	random 2
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_TEMP_D, 0
	goto_if_eq Common_EventScript_NopReturn
	setobjectxyperm LOCALID_AUDIENCE_WALKING, 2, 0
	setobjectmovementtype LOCALID_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat:: @ 824C938
	compare VAR_TEMP_D, 0
	goto_if_eq Common_EventScript_NopReturn
	applymovement LOCALID_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
	return

BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump: @ 824C94B
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_down
	delay_4
	jump_in_place_down
	enable_jump_landing_ground_effect
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat: @ 824C95E
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter: @ 824C964
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft: @ 824C969
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit: @ 824C96B
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome: @ 824C970
	.string "{PLAYER} has entered the BATTLE DOME!$"

BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer: @ 824C990
	.string "{STR_VAR_1}\n"
	.string "match!\p"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
	.string "Let the battle begin!$"

BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner: @ 824C9BE
	.string "{PLAYER} is the winner!\n"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner: @ 824C9E1
	.string "{STR_VAR_2} is the winner!\n"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ: @ 824CA04
	.string "{PLAYER} is the Level 50\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp: @ 824CA44
	.string "{PLAYER} is the Open Level\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait: @ 824CA86
	.string "What an unbelievable finish!\n"
	.string "We have a double knockout!\p"
	.string "In this event, the Battle Tournament\n"
	.string "rules call for a REFEREE'S decision.\p"
	.string "Please wait while the judging\n"
	.string "is under way.$"

BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer: @ 824CB34
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is {STR_VAR_1}!\l"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer: @ 824CB9D
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is {PLAYER}!\l"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope: @ 824CC06
	.string "The bright new hope!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_RisingStar: @ 824CC1C
	.string "The rising star!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship: @ 824CC2E
	.string "Will this TRAINER race to\n"
	.string "the championship?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry: @ 824CC5B
	.string "Can the feat of a championship\n"
	.string "on the first try be achieved?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged: @ 824CC99
	.string "Can the loss of the last match\n"
	.string "be avenged?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship: @ 824CCC5
	.string "The TRAINER is on fire for\n"
	.string "the first championship try!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal: @ 824CCFD
	.string "A win here means this TRAINER\n"
	.string "advances to the final!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue: @ 824CD33
	.string "Will the long-held dream of\n"
	.string "a championship finally come true?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion: @ 824CD72
	.string "The invincible champion!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer: @ 824CD8C
	.string "Can anyone hope to beat this\n"
	.string "TRAINER?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer: @ 824CDB3
	.string "Do battles exist solely for\n"
	.string "this TRAINER?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle: @ 824CDDE
	.string "The current champion aiming to\n"
	.string "retain the title!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned: @ 824CE10
	.string "The former champion has returned!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned: @ 824CE33
	.string "The former toughness has returned!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals: @ 824CE57
	.string "Will this TRAINER do as expected\n"
	.string "and advance to the finals?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory: @ 824CE94
	.string "Will the former champ regain\n"
	.string "lost glory?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster: @ 824CEBE
	.string "Feel the glow of a true master!$"

BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker: @ 824CEDE
	.string "And now… The TRAINER standing in\n"
	.string "{PLAYER}'s record-setting path…\p"
	.string "Yes! The one and only!\n"
	.string "The BATTLE DOME COMMISSIONER!\l"
	.string "Our very own DOME ACE!\l"
	.string "Make way for TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant: @ 824CF7A
	.string "Spectators: TUCKER! TUCKER!\n"
	.string "TUCKER! TUCKER! TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro: @ 824CFAE
	.string "TUCKER: Ahahah!\p"
	.string "Do you hear it? This crowd!\n"
	.string "They're all itching to see our match!\p"
	.string "Ahahah!\p"
	.string "I bet you're twitching all over from\n"
	.string "the tension of getting to battle me!\p"
	.string "But don't you worry about a thing!\p"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
	.string "in my brilliant glow!$"

BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy: @ 824D0D9
	.string "Your strategy!\n"
	.string "Let's see it!$"

BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer: @ 824D0F6
	.string "Unbelievable! It's incredible!\n"
	.string "The victor is {PLAYER}!$"

BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker: @ 824D127
	.string "The winner is TUCKER!\n"
	.string "The DOME ACE has prevailed!\p"
	.string "Congratulations, TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass: @ 824D172
	.string "TUCKER: Rules are rules!\n"
	.string "Let me see your FRONTIER PASS.$"

BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol: @ 824D1AA
	.string "The Tactics Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime: @ 824D1E0
	.string "… … … … … …\p"
	.string "I sorely underestimated you. I won't\n"
	.string "make the same mistake next time…$"

BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched: @ 824D232
	.string "Can the win streak be stretched?\n"
	.string "The confidence is there!$"

BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker: @ 824D26C
	.string "Ladies and gentlemen!\n"
	.string "Boys, girls, and POKéMON!\p"
	.string "Finally!\n"
	.string "Finally, the legend has returned!\p"
	.string "Yes, the name of that legend!\n"
	.string "Our very own DOME ACE!\l"
	.string "It's none other than TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro: @ 824D319
	.string "TUCKER: Ah…\n"
	.string "The pummeling roar of the crowd…\l"
	.string "Their furnace-like heat of excitement…\l"
	.string "This is a wonderful place…\p"
	.string "To the crowd, I am the DOME ACE…\n"
	.string "I represent their hopes and dreams…\l"
	.string "I must never fade from their sight…\p"
	.string "I must burn!\n"
	.string "Brighter and more brilliant!\l"
	.string "I must light all that gather here!$"

BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess: @ 824D43E
	.string "I will unleash all the power that\n"
	.string "I possess! Right here and now!$"

BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed: @ 824D47F
	.string "TUCKER: You're genuinely fantastic!\p"
	.string "Never before! I haven't ever lost in the\n"
	.string "times I've had to unleash my power.\p"
	.string "Yes, quite fantastic!\n"
	.string "Your FRONTIER PASS, please?$"

BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine: @ 824D522
	.string "The Tactics Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter: @ 824D54D
	.string "You're strong, but above all,\n"
	.string "you have a unique charm!\p"
	.string "In you, I see a definite potential for\n"
	.string "a superstar like me.\p"
	.string "I will very much look forward to\n"
	.string "our next encounter!$"

@ Unused
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2: @ 824D5F5
	.string "{PLAYER} is the Level 50\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

@ Unused
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2: @ 824D635
	.string "{PLAYER} is the Open Level\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker: @ 824D677
	.string "The final match!\p"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
	.string "Let the battle begin!$"

BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker: @ 824D6BE
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is our very own DOME ACE!\l"
	.string "It's TUCKER!\p"
	.string "Congratulations! And thank you!\n"
	.string "Let's hear it for the DOME ACE, TUCKER!$"

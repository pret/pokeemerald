.set LOCALID_LASS, 1
.set LOCALID_MAN, 2
.set LOCALID_POKEFAN_M, 3
.set LOCALID_LITTLE_GIRL, 4
.set LOCALID_NINJA_BOY, 5
.set LOCALID_BOY, 6
.set LOCALID_WOMAN, 7
.set LOCALID_EXPERT_F, 8

LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

	@ See field_specials.c for a breakdown of the Fan Club and its variables

LilycoveCity_PokemonTrainerFanClub_OnFrame:
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
	applymovement LOCALID_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
	delay_8
	walk_in_place_fastest_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
	walk_down
	walk_in_place_fastest_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_fastest_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition:
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 2
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special TryLoseFansFromPlayTime
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

@ Set up the fan club TV show, if the player has at least 5 fans in the club
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	compare VAR_0x8005, 5
	goto_if_ge LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
	special TryPutTrainerFanClubOnAir
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special BufferFanClubTrainerName
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special BufferFanClubTrainerName
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special BufferFanClubTrainerName
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer::
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview::
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
	special InterviewBefore
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_0x8004, FANCLUB_MEMBER1
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

@ Shouldnt be reached
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer:
	.string "Oh, wow!\n"
	.string "It's {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan:
	.string "I've heard the news!\n"
	.string "You're really strong, aren't you?\p"
	.string "We always argue about who is the\n"
	.string "strongest of all Trainers here.\p"
	.string "So when I heard about you, I decided\n"
	.string "to be your fan!\p"
	.string "I hope you'll keep on battling other\n"
	.string "tough Trainers.\p"
	.string "That way, we'll be able to see more\n"
	.string "of your hot, hot battles.\p"
	.string "That will make the others here see\n"
	.string "exactly how great you are.\p"
	.string "Remember, I'm cheering for you,\n"
	.string "{PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin:
	.string "Yo, {PLAYER}!\n"
	.string "You're the one we want to win!$"

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest:
	.string "The others, they don't know that\n"
	.string "you're the best of the best!\p"
	.string "Isn't that right, {PLAYER}?\n"
	.string "Show them you've got guts!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary:
	.string "I hate to say this, but the Trainer\n"
	.string "everybody's talking about is\l"
	.string "{STR_VAR_1}, no question about it!\p"
	.string "That Trainer's power…\n"
	.string "It's out of the ordinary.$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen:
	.string "Darn it… I've been telling people\n"
	.string "that {STR_VAR_1} is the best now…\p"
	.string "But no one wants to listen…$"

LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer:
	.string "I've been hearing things about\n"
	.string "a tough new Trainer.\p"
	.string "This Trainer's supposed to be beating\n"
	.string "Gym Leaders, even.\p"
	.string "Do you know anything about this\n"
	.string "new Trainer?$"

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou:
	.string "Oh!\n"
	.string "{PLAYER}!\p"
	.string "Go for it!\n"
	.string "I'm pulling for you!$"

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan:
	.string "Sigh…\n"
	.string "Brawly…\p"
	.string "Oh, no! Wait!\n"
	.string "That's not right! No, no, no!\p"
	.string "I'm your fan through and through!\p"
	.string "So make me proud!\n"
	.string "Go for it!$"

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly:
	.string "I can't help it, I can only get to\n"
	.string "like Brawly…$"

LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly:
	.string "Nobody understands the charm of\n"
	.string "Brawly…\p"
	.string "I don't care!\p"
	.string "Even if I'm the only one, I'm going\n"
	.string "to keep cheering for Brawly!$"

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly:
	.string "Whatever anyone says, my favorite\n"
	.string "Trainer is Dewford's Gym Leader\l"
	.string "Brawly!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather:
	.string "You've surpassed your own father in\n"
	.string "every regard!\p"
	.string "I'm telling you, so there's no question\n"
	.string "about it at all!$"

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling:
	.string "Even when things turned bleak,\n"
	.string "your father never gave up.\p"
	.string "This I know to be true.\p"
	.string "You never give up even if you lose!\n"
	.string "So keep on battling!$"

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman:
	.string "Norman battled with more power,\n"
	.string "charisma, and showmanship than you.\p"
	.string "Even though people may say that\n"
	.string "you're strong…\p"
	.string "You've still got a long way to go\n"
	.string "compared to your father.$"

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent:
	.string "You're beginning to get the same\n"
	.string "air of awe Norman exudes.\p"
	.string "But there's something conclusively\n"
	.string "different between you and Norman.\p"
	.string "I can't tell you what that is.\n"
	.string "You'll have to find it yourself.$"

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers:
	.string "Everyone here, we're all huge fans\n"
	.string "of Pokémon battles.\p"
	.string "We discuss who we consider to be\n"
	.string "the strongest of all Trainers.\p"
	.string "If you were to become famous,\n"
	.string "we might even become your fans!$"

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer:
	.string "Oh, woweee! It's {PLAYER}!\n"
	.string "For real, too!\p"
	.string "Please, shake my hand, shake my hand!$"

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou:
	.string "I'll always cheer for you, {PLAYER}!\n"
	.string "Always, always!\p"
	.string "I don't want to see you lose ever,\n"
	.string "{PLAYER}.\p"
	.string "Because I know you're really,\n"
	.string "really strong, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool:
	.string "{STR_VAR_1} is really cool…\p"
	.string "Everyone thinks so, right, right?$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe:
	.string "{STR_VAR_1} really is cool, don't\n"
	.string "you think so?\p"
	.string "Even if it's just me, I'm going to keep\n"
	.string "cheering my favorite Trainer.$"

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat:
	.string "My favorite Trainer is…\p"
	.string "Cool…\p"
	.string "Strong…\p"
	.string "And really nice…\p"
	.string "I wish there was a Trainer like that…$"

LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou:
	.string "Whoa! It's {PLAYER}!\n"
	.string "Wicked!\p"
	.string "When I grow up, I want to be strong\n"
	.string "like you, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou:
	.string "Even if I'm the only one…\p"
	.string "You'll always be the only one\n"
	.string "I cheer for, {PLAYER}!\p"
	.string "Because I believe in you, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool:
	.string "{STR_VAR_1} is so wickedly cool…\n"
	.string "I want to shake hands with my hero.$"

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan:
	.string "Even if I'm the only one…\p"
	.string "I'm never going to stop being\n"
	.string "{STR_VAR_1}'s fan!\p"
	.string "Because I've heard, {STR_VAR_1}\n"
	.string "never loses!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll:
	.string "{PLAYER}!\n"
	.string "You are amazing after all!\p"
	.string "Ever since I set eyes on you,\n"
	.string "I knew that you were great.\p"
	.string "It looks like my eyes didn't deceive me.$"

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner:
	.string "Who cares about the others.\n"
	.string "I'm in your corner!\p"
	.string "You don't need to worry. Just get\n"
	.string "out there and battle like always.$"

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne:
	.string "You're a pretty decent Trainer,\n"
	.string "I think.\p"
	.string "But I also think that {STR_VAR_1}\n"
	.string "is number one right now.\p"
	.string "That's just my opinion.\n"
	.string "Don't worry about it too much.$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer:
	.string "Wow, you really are strong.\n"
	.string "Maybe even stronger than {STR_VAR_1}.\p"
	.string "But {STR_VAR_1} needs me.\p"
	.string "If I don't cheer for {STR_VAR_1},\n"
	.string "who will?$"

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind:
	.string "You've changed my mind!\n"
	.string "You are strong, aren't you?\p"
	.string "I'd like you to tell me how you managed\n"
	.string "to get so strong!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation:
	.string "The tougher the situation, the more\n"
	.string "attractively you battle.\p"
	.string "I can't wait for your next battle!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout:
	.string "Among the recently hot Trainers,\n"
	.string "{STR_VAR_1} is the standout.\p"
	.string "That toughness, it's simply not normal.\p"
	.string "You're doing okay, but you're not in\n"
	.string "the same class as {STR_VAR_1}.$"

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger:
	.string "You are really popular…\p"
	.string "You're strong, and you're caring to\n"
	.string "Pokémon. No one can knock you.\p"
	.string "But, you know, I believe in {STR_VAR_1}.\p"
	.string "{STR_VAR_1} is definitely stronger!\n"
	.string "I'm positive!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive:
	.string "You…\p"
	.string "Impressive!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth:
	.string "Your true worth, it is fine if only\n"
	.string "I recognized it.\p"
	.string "The others I doubt will understand\n"
	.string "the hidden power that beats within.$"

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential:
	.string "Yes, I see strength in your eyes.\p"
	.string "But!\p"
	.string "You still haven't realized your\n"
	.string "potential.$"

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength:
	.string "It is true that you are tremendously\n"
	.string "powerful.\p"
	.string "But!\n"
	.string "I can tell…\p"
	.string "That strength cannot be considered\n"
	.string "true strength yet!\p"
	.string "True strength is…!\n"
	.string "… …\p"
	.string "Actually, I have no idea, either.$"

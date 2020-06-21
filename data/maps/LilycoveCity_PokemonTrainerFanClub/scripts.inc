.set LOCALID_LASS, 1
.set LOCALID_MAN, 2
.set LOCALID_POKEFAN_M, 3
.set LOCALID_LITTLE_GIRL, 4
.set LOCALID_NINJA_BOY, 5
.set LOCALID_BOY, 6
.set LOCALID_WOMAN, 7
.set LOCALID_EXPERT_F, 8

LilycoveCity_PokemonTrainerFanClub_MapScripts:: @ 821C785
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

	@ See field_specials.c for a breakdown of the Fan Club and its variables

LilycoveCity_PokemonTrainerFanClub_OnFrame: @ 821C790
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans:: @ 821C79A
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

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer: @ 821C7F5
	delay_8
	walk_in_place_fastest_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer: @ 821C7FD
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer: @ 821C804
	walk_down
	walk_in_place_fastest_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer: @ 821C807
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_fastest_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition: @ 821C80D
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 2
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions:: @ 821C829
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

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer:: @ 821C8DA
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer:: @ 821C8F1
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

@ Set up the fan club TV show, if the player has at least 5 fans in the club
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow:: @ 821C8F5
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

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan:: @ 821C9AE
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow:: @ 821C9B4
	special TrySetUpTrainerFanClubSpecial
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable:: @ 821C9B8
	setobjectxyperm LOCALID_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable:: @ 821C9C0
	setobjectxyperm LOCALID_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable:: @ 821C9C8
	setobjectxyperm LOCALID_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable:: @ 821C9D0
	setobjectxyperm LOCALID_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable:: @ 821C9D8
	setobjectxyperm LOCALID_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable:: @ 821C9E0
	setobjectxyperm LOCALID_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable:: @ 821C9E8
	setobjectxyperm LOCALID_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable:: @ 821C9F0
	setobjectxyperm LOCALID_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting:: @ 821C9F8
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man:: @ 821CA17
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

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan:: @ 821CA56
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan:: @ 821CA70
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan:: @ 821CA7A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion:: @ 821CA84
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass:: @ 821CA8E
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

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan:: @ 821CACD
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan:: @ 821CAE7
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan:: @ 821CAF1
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion:: @ 821CAFB
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM:: @ 821CB05
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

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan:: @ 821CB44
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan:: @ 821CB5E
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan:: @ 821CB68
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion:: @ 821CB72
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl:: @ 821CB7C
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

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan:: @ 821CBBB
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan:: @ 821CBD5
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan:: @ 821CBDF
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion:: @ 821CBE9
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy:: @ 821CBF3
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

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan:: @ 821CC27
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan:: @ 821CC41
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan:: @ 821CC4B
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy:: @ 821CC55
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

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan:: @ 821CC89
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan:: @ 821CCA3
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan:: @ 821CCAD
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman:: @ 821CCB7
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

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan:: @ 821CCEB
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan:: @ 821CD05
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan:: @ 821CD0F
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF:: @ 821CD19
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

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan:: @ 821CD4D
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan:: @ 821CD67
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan:: @ 821CD71
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer:: @ 821CD7B
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview:: @ 821CD90
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

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion:: @ 821CDE0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion:: @ 821CDEE
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion:: @ 821CE15
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

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer:: @ 821CE4D
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

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer:: @ 821CE9F
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer:: @ 821CEC6
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview:: @ 821CED8
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed:: @ 821CEED
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

@ Shouldnt be reached
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2:: @ 821CEFF
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer: @ 821CF00
	.string "Oh, wow!\n"
	.string "It's {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan: @ 821CF12
	.string "I've heard the news!\n"
	.string "You're really strong, aren't you?\p"
	.string "We always argue about who is the\n"
	.string "strongest of all TRAINERS here.\p"
	.string "So when I heard about you, I decided\n"
	.string "to be your fan!\p"
	.string "I hope you'll keep on battling other\n"
	.string "tough TRAINERS.\p"
	.string "That way, we'll be able to see more\n"
	.string "of your hot, hot battles.\p"
	.string "That will make the others here see\n"
	.string "exactly how great you are.\p"
	.string "Remember, I'm cheering for you,\n"
	.string "{PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin: @ 821D094
	.string "Yo, {PLAYER}!\n"
	.string "You're the one we want to win!$"

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest: @ 821D0BB
	.string "The others, they don't know that\n"
	.string "you're the best of the best!\p"
	.string "Isn't that right, {PLAYER}?\n"
	.string "Show them you've got guts!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary: @ 821D12A
	.string "I hate to say this, but the TRAINER\n"
	.string "everybody's talking about is\l"
	.string "{STR_VAR_1}, no question about it!\p"
	.string "That TRAINER's power…\n"
	.string "It's out of the ordinary.$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen: @ 821D1B5
	.string "Darn it… I've been telling people\n"
	.string "that {STR_VAR_1} is the best now…\p"
	.string "But no one wants to listen…$"

LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer: @ 821D20C
	.string "I've been hearing things about\n"
	.string "a tough new TRAINER.\p"
	.string "This TRAINER's supposed to be beating\n"
	.string "GYM LEADERS, even.\p"
	.string "Do you know anything about this\n"
	.string "new TRAINER?$"

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou: @ 821D2A6
	.string "Oh!\n"
	.string "{PLAYER}!\p"
	.string "Go for it!\n"
	.string "I'm pulling for you!$"

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan: @ 821D2CE
	.string "Sigh…\n"
	.string "BRAWLY…\p"
	.string "Oh, no! Wait!\n"
	.string "That's not right! No, no, no!\p"
	.string "I'm your fan through and through!\p"
	.string "So make me proud!\n"
	.string "Go for it!$"

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly: @ 821D347
	.string "I can't help it, I can only get to\n"
	.string "like BRAWLY…$"

LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly: @ 821D377
	.string "Nobody understands the charm of\n"
	.string "BRAWLY…\p"
	.string "I don't care!\p"
	.string "Even if I'm the only one, I'm going\n"
	.string "to keep cheering for BRAWLY!$"

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly: @ 821D3EE
	.string "Whatever anyone says, my favorite\n"
	.string "TRAINER is DEWFORD's GYM LEADER\l"
	.string "BRAWLY!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather: @ 821D438
	.string "You've surpassed your own father in\n"
	.string "every regard!\p"
	.string "I'm telling you, so there's no question\n"
	.string "about it at all!$"

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling: @ 821D4A3
	.string "Even when things turned bleak,\n"
	.string "your father never gave up.\p"
	.string "This I know to be true.\p"
	.string "You never give up even if you lose!\n"
	.string "So keep on battling!$"

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman: @ 821D52E
	.string "NORMAN battled with more power,\n"
	.string "charisma, and showmanship than you.\p"
	.string "Even though people may say that\n"
	.string "you're strong…\p"
	.string "You've still got a long way to go\n"
	.string "compared to your father.$"

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent: @ 821D5DC
	.string "You're beginning to get the same\n"
	.string "air of awe NORMAN exudes.\p"
	.string "But there's something conclusively\n"
	.string "different between you and NORMAN.\p"
	.string "I can't tell you what that is.\n"
	.string "You'll have to find it yourself.$"

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers: @ 821D69C
	.string "Everyone here, we're all huge fans\n"
	.string "of POKéMON battles.\p"
	.string "We discuss who we consider to be\n"
	.string "the strongest of all TRAINERS.\p"
	.string "If you were to become famous,\n"
	.string "we might even become your fans!$"

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer: @ 821D751
	.string "Oh, woweee! It's {PLAYER}!\n"
	.string "For real, too!\p"
	.string "Please, shake my hand, shake my hand!$"

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou: @ 821D79B
	.string "I'll always cheer for you, {PLAYER}!\n"
	.string "Always, always!\p"
	.string "I don't want to see you lose ever,\n"
	.string "{PLAYER}.\p"
	.string "Because I know you're really,\n"
	.string "really strong, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool: @ 821D822
	.string "{STR_VAR_1} is really cool…\p"
	.string "Everyone thinks so, right, right?$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe: @ 821D857
	.string "{STR_VAR_1} really is cool, don't\n"
	.string "you think so?\p"
	.string "Even if it's just me, I'm going to keep\n"
	.string "cheering my favorite TRAINER.$"

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat: @ 821D8C4
	.string "My favorite TRAINER is…\p"
	.string "Cool…\p"
	.string "Strong…\p"
	.string "And really nice…\p"
	.string "I wish there was a TRAINER like that…$"

LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou: @ 821D921
	.string "Whoa! It's {PLAYER}!\n"
	.string "Wicked!\p"
	.string "When I grow up, I want to be strong\n"
	.string "like you, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou: @ 821D96A
	.string "Even if I'm the only one…\p"
	.string "You'll always be the only one\n"
	.string "I cheer for, {PLAYER}!\p"
	.string "Because I believe in you, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool: @ 821D9D1
	.string "{STR_VAR_1} is so wickedly cool…\n"
	.string "I want to shake hands with my hero.$"

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan: @ 821DA0D
	.string "Even if I'm the only one…\p"
	.string "I'm never going to stop being\n"
	.string "{STR_VAR_1}'s fan!\p"
	.string "Because I've heard, {STR_VAR_1}\n"
	.string "never loses!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll: @ 821DA73
	.string "{PLAYER}!\n"
	.string "You are amazing after all!\p"
	.string "Ever since I set eyes on you,\n"
	.string "I knew that you were great.\p"
	.string "It looks like my eyes didn't deceive me.$"

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner: @ 821DAF5
	.string "Who cares about the others.\n"
	.string "I'm in your corner!\p"
	.string "You don't need to worry. Just get\n"
	.string "out there and battle like always.$"

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne: @ 821DB69
	.string "You're a pretty decent TRAINER,\n"
	.string "I think.\p"
	.string "But I also think that {STR_VAR_1}\n"
	.string "is number one right now.\p"
	.string "That's just my opinion.\n"
	.string "Don't worry about it too much.$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer: @ 821DBFB
	.string "Wow, you really are strong.\n"
	.string "Maybe even stronger than {STR_VAR_1}.\p"
	.string "But {STR_VAR_1} needs me.\p"
	.string "If I don't cheer for {STR_VAR_1},\n"
	.string "who will?$"

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind: @ 821DC68
	.string "You've changed my mind!\n"
	.string "You are strong, aren't you?\p"
	.string "I'd like you to tell me how you managed\n"
	.string "to get so strong!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation: @ 821DCD6
	.string "The tougher the situation, the more\n"
	.string "attractively you battle.\p"
	.string "I can't wait for your next battle!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout: @ 821DD36
	.string "Among the recently hot TRAINERS,\n"
	.string "{STR_VAR_1} is the standout.\p"
	.string "That toughness, it's simply not normal.\p"
	.string "You're doing okay, but you're not in\n"
	.string "the same class as {STR_VAR_1}.$"

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger: @ 821DDCE
	.string "You are really popular…\p"
	.string "You're strong, and you're caring to\n"
	.string "POKéMON. No one can knock you.\p"
	.string "But, you know, I believe in {STR_VAR_1}.\p"
	.string "{STR_VAR_1} is definitely stronger!\n"
	.string "I'm positive!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive: @ 821DE72
	.string "You…\p"
	.string "Impressive!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth: @ 821DE83
	.string "Your true worth, it is fine if only\n"
	.string "I recognized it.\p"
	.string "The others I doubt will understand\n"
	.string "the hidden power that beats within.$"

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential: @ 821DEFF
	.string "Yes, I see strength in your eyes.\p"
	.string "But!\p"
	.string "You still haven't realized your\n"
	.string "potential.$"

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength: @ 821DF51
	.string "It is true that you are tremendously\n"
	.string "powerful.\p"
	.string "But!\n"
	.string "I can tell…\p"
	.string "That strength cannot be considered\n"
	.string "true strength yet!\p"
	.string "True strength is…!\n"
	.string "… …\p"
	.string "Actually, I have no idea, either.$"

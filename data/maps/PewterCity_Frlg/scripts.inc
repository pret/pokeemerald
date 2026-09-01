PewterCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
	.byte 0

PewterCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PEWTER_CITY
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
	end

@ Impossible to speak to this NPC from a facing dir != DIR_EAST normally, so they arent checked
@ Additionally, no movement script exists for facing DIR_SOUTH, which would necessitate walking out of bounds
PewterCity_EventScript_GymGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_WalkToGymEast
	msgbox PewterCity_Text_GoTakeOnBrock
	closemessage
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	release
	end

PewterCity_EventScript_WalkToGymEast::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymWest::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideWest
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadWest
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymWest
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymWest
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymNorth::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideNorth
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymNorth
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymNorth
	waitmovement 0
	return

.macro walk_to_gym
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
.endm

.macro walk_to_gym_alt
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
.endm

PewterCity_Movement_PlayerWaitForGuideEast::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_down
	step_end

PewterCity_Movement_PlayerWalkToGymEast::
	walk_down
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWaitForGuideWest::
	delay_16
	step_end

PewterCity_Movement_PlayerWalkToGymWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	step_end

PewterCity_Movement_PlayerWaitForGuideNorth::
	delay_16
	step_end

PewterCity_Movement_PlayerWalkToGymNorth::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	step_end

PewterCity_Movement_GuideMoveToLeadEast::
	walk_down
	walk_left
	walk_in_place_faster_up
	walk_in_place_up
	step_end

PewterCity_Movement_GuideWalkToGymEast::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideMoveToLeadWest::
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideMoveToLeadNorth::
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymNorth::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GymGuideExit::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_EventScript_GymGuideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	goto PewterCity_EventScript_GymGuideTrigger
	end

@ This trigger is inaccessible and its corresponding movement script isnt linked
PewterCity_EventScript_GymGuideTriggerRight::
	lockall
	setvar VAR_TEMP_1, 3
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
	msgbox PewterCity_Text_GoTakeOnBrock
	closemessage
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	releaseall
	end

PewterCity_EventScript_WalkToGymTop::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
	waitmovement 0
	return

PewterCity_EventScript_WalkToGymMid::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
	waitmovement 0
	return

PewterCity_EventScript_WalkToGymBottom::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymRight::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymRight
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymRight
	waitmovement 0
	return

PewterCity_Movement_PlayerWalkToGymTop::
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymMid::
	walk_up
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymBottom::
	walk_up
	walk_up
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymRight::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_to_gym_alt
	step_end

PewterCity_Movement_GuideMoveToLeadTop::
	walk_left
	walk_down
	walk_in_place_faster_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideMoveToLeadMid::
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideMoveToLeadBottom::
	walk_down
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideApproachPlayerRight::
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymTop::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymMid::
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymBottom::
	walk_up
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymRight::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_EventScript_Lass::
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
	msgbox PewterCity_Text_ReallyYouHaveToGo
	closemessage
	delay 10
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
	call_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
	msgbox PewterCity_Text_ThisIsTheMuseum
	closemessage
	delay 10
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_MUSEUM_GUIDE
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
	release
	end

PewterCity_EventScript_LeadToMuseumNorth::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumSouth::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumWest::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumEast::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
	waitmovement 0
	return

PewterCity_EventScript_CheckedOutMuseum::
	msgbox PewterCity_Text_WerentThoseFossilsAmazing
	release
	end

.macro walk_to_museum
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
.endm

.macro walk_to_museum_south
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
.endm

PewterCity_Movement_PlayerWalkToMuseumNorth::
	walk_up
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumNorth::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumSouth::
	delay_16
	delay_16
	walk_left
	walk_to_museum_south
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumSouth::
	walk_left
	walk_up
	walk_to_museum_south
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumWest::
	walk_left
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumWest::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumEast::
	walk_right
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumEast::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_MuseumGuideExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_EventScript_FatMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BROCK, 2
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere
	release
	end

PewterCity_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut
	release
	end

PewterCity_EventScript_KnowWhatTheyreDoing::
	msgbox PewterCity_Text_ThatsRightItsHardWork
	release
	end

PewterCity_EventScript_TrainerTips::
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
	end

PewterCity_EventScript_PoliceNotice::
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
	end

PewterCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_BROCK, 0
	msgbox PewterCity_Text_GymSign
	releaseall
	end

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
	end

PewterCity_EventScript_RunningShoesAide::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	call PewterCity_EventScript_AideGiveRunningShoes
	release
	end

PewterCity_EventScript_RunningShoesAideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_RunningShoesAideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 2
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_RunningShoesAideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 3
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_AideGiveRunningShoes::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideNoticePlayer
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideNoticePlayer
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideNoticePlayer
	waitse
	playse SE_PIN
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_Delay48
	waitmovement 0
	msgbox PewterCity_Text_OhPlayer
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_AideApproachPlayer0
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideApproachPlayer1
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideApproachPlayer2
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideApproachPlayer3
	msgbox PewterCity_Text_AskedToDeliverThis
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Text_ReceivedRunningShoesFromAide
	waitmessage
	waitfanfare
	msgbox PewterCity_Text_SwitchedShoesWithRunningShoes
	special DisableMsgBoxWalkaway
	signmsg
	msgbox PewterCity_Text_ExplainRunningShoes
	normalmsg
	call EventScript_RestorePrevTextColor
	msgbox PewterCity_Text_MustBeGoingBackToLab
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_AideExit0
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideExit1
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideExit2
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideExit3
	delay 30
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Text_RunningShoesLetterFromMom
	closemessage
	removeobject LOCALID_PEWTER_AIDE
	setflag FLAG_SYS_B_DASH
	setvar VAR_MAP_SCENE_PEWTER_CITY, 2
	return

PewterCity_EventScript_AideNoticePlayer::
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

@ Aide already at player
PewterCity_EventScript_AideApproachPlayer0::
	closemessage
	delay 20
	return

PewterCity_EventScript_AideApproachPlayer1::
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideApproachPlayer2::
	closemessage
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerMid
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideApproachPlayer3::
	closemessage
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerBottom
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideExit0::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit0
	waitmovement 0
	return

PewterCity_EventScript_AideExit1::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit1
	waitmovement 0
	return

PewterCity_EventScript_AideExit2::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit2
	waitmovement 0
	return

PewterCity_EventScript_AideExit3::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit3
	waitmovement 0
	return

PewterCity_Movement_AideApproachPlayerMid::
	delay_4
	walk_down
	step_end

PewterCity_Movement_AideApproachPlayerBottom::
	delay_4
	walk_down
	walk_down
	step_end

PewterCity_Movement_AideExit0::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_AideExit1::
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

PewterCity_Movement_AideExit2::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_AideExit3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
PewterCity_Movement_WalkInPlaceLeft::
	walk_in_place_left
	step_end

Text_DreamEaterTeach::
	.string "Yawn!\n"
	.string "I must have dozed off in the sun.\p"
	.string "I had this weird dream about\n"
	.string "a DROWZEE eating my dream.\p"
	.string "And…\n"
	.string "I learned how to eat dreams…\p"
	.string "Oogh, this is too spooky!\p"
	.string "Let me teach it to a POKéMON so\n"
	.string "I can forget about it!$"

Text_DreamEaterDeclined::
	.string "…Snore…$"

Text_DreamEaterWhichMon::
	.string "Which POKéMON wants to learn\n"
	.string "DREAM EATER?$"

Text_DreamEaterTaught::
	.string "…ZZZ…\n"
	.string "I…can't eat…anymore…$"

PewterCity_Text_ClefairyCameFromMoon::
	.string "CLEFAIRY came from the moon.\n"
	.string "That's what the rumor is.\p"
	.string "They appeared after MOON STONES\n"
	.string "fell on MT. MOON.$"

PewterCity_Text_BrockOnlySeriousTrainerHere::
	.string "There aren't many serious POKéMON\n"
	.string "TRAINERS here.\p"
	.string "They're all like BUG CATCHERS,\n"
	.string "you know, just hobbyists.\p"
	.string "But PEWTER GYM's BROCK isn't like\n"
	.string "that, not one bit.$"

PewterCity_Text_DidYouCheckOutMuseum::
	.string "Did you check out the MUSEUM?$"

PewterCity_Text_WerentThoseFossilsAmazing::
	.string "Weren't those fossils from MT. MOON\n"
	.string "amazing?$"

PewterCity_Text_ReallyYouHaveToGo::
	.string "Really?\n"
	.string "You absolutely have to go!$"

PewterCity_Text_ThisIsTheMuseum::
	.string "This is it, the MUSEUM.\p"
	.string "You have to pay to get in, but it's\n"
	.string "worth it. See you around!$"

PewterCity_Text_DoYouKnowWhatImDoing::
	.string "Psssst!\n"
	.string "Do you know what I'm doing?$"

PewterCity_Text_ThatsRightItsHardWork::
	.string "That's right!\n"
	.string "It's hard work!$"

PewterCity_Text_SprayingRepelToKeepWildMonsOut::
	.string "I'm spraying REPEL to keep wild\n"
	.string "POKéMON out of my garden!$"

PewterCity_Text_BrocksLookingForChallengersFollowMe::
	.string "You're a TRAINER, right?\p"
	.string "BROCK's looking for new\n"
	.string "challengers. Follow me!$"

PewterCity_Text_GoTakeOnBrock::
	.string "If you have the right stuff,\n"
	.string "go take on BROCK!$"

PewterCity_Text_TrainerTipsEarningEXP::
	.string "TRAINER TIPS\p"
	.string "All POKéMON that appear in battle,\n"
	.string "however briefly, earn EXP Points.$"

PewterCity_Text_CallPoliceIfInfoOnThieves::
	.string "NOTICE!\p"
	.string "Thieves have been stealing POKéMON\n"
	.string "fossils from MT. MOON.\p"
	.string "Please call the PEWTER POLICE if\n"
	.string "you have any information.$"

PewterCity_Text_MuseumOfScience::
	.string "PEWTER MUSEUM OF SCIENCE$"

PewterCity_Text_GymSign::
	.string "PEWTER CITY POKéMON GYM\n"
	.string "LEADER: BROCK\l"
	.string "The Rock-Solid POKéMON TRAINER!$"

PewterCity_Text_CitySign::
	.string "PEWTER CITY\n"
	.string "A Stone Gray City$"

PewterCity_Text_OhPlayer::
	.string "Oh, {PLAYER}{KUN}!$"

PewterCity_Text_AskedToDeliverThis::
	.string "I'm glad I caught up to you.\n"
	.string "I'm PROF. OAK's AIDE.\p"
	.string "I've been asked to deliver this,\n"
	.string "so here you go.$"

PewterCity_Text_ReceivedRunningShoesFromAide::
	.string "{PLAYER} received the\n"
	.string "RUNNING SHOES from the AIDE.$"

PewterCity_Text_SwitchedShoesWithRunningShoes::
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

PewterCity_Text_ExplainRunningShoes::
	.string "Press the B Button to run.\n"
	.string "But only where there's room to run!$"

PewterCity_Text_MustBeGoingBackToLab::
	.string "Well, I must be going back to\n"
	.string "the LAB.\p"
	.string "Bye-bye!$"

PewterCity_Text_RunningShoesLetterFromMom::
	.string "There's a letter attached…\p"
	.string "Dear {PLAYER},\p"
	.string "Here is a pair of RUNNING SHOES\n"
	.string "for my beloved challenger.\p"
	.string "Remember, I'll always cheer for\n"
	.string "you! Don't ever give up!\p"
	.string "From Mom$"


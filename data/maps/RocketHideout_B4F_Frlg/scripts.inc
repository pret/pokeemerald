.equ NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_OnLoad::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_ne NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_EventScript_CountGruntDefeated::
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return

RocketHideout_B4F_EventScript_Giovanni::
	lock
	faceplayer
	famechecker FAMECHECKER_GIOVANNI, 0
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_HIDEOUT_GIOVANNI
	addobject LOCALID_SILPH_SCOPE
	clearflag FLAG_HIDE_SILPH_SCOPE
	setflag FLAG_HIDE_CELADON_ROCKETS
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	fadescreen FADE_FROM_BLACK
	release
	end

RocketHideout_B4F_EventScript_SilphScope::
	lock
	faceplayer
	removeobject LOCALID_SILPH_SCOPE
	giveitem ITEM_SILPH_SCOPE
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_EventScript_LiftKey::
	lock
	faceplayer
	setflag FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_RemoveBarrier
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_RemoveBarrier
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return

RocketHideout_B4F_Text_GiovanniIntro::
	.string "So! I must say, I am impressed you\n"
	.string "got here.\p"
	.string "TEAM ROCKET captures POKéMON from\n"
	.string "around the world.\p"
	.string "They're important tools for keeping\n"
	.string "our criminal enterprise going.\p"
	.string "I am the leader, GIOVANNI!\p"
	.string "For your insolence, you will feel a\n"
	.string "world of pain!$"

RocketHideout_B4F_Text_GiovanniDefeat::
	.string "WHAT!\n"
	.string "This can't be!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
	.string "I see that you raise POKéMON with\n"
	.string "utmost care.\p"
	.string "A child like you would never\n"
	.string "understand what I hope to achieve.\p"
	.string "I shall step aside this time!\p"
	.string "I hope we meet again…$"

RocketHideout_B4F_Text_Grunt2Intro::
	.string "I know you!\n"
	.string "You ruined our plans at MT. MOON!$"

RocketHideout_B4F_Text_Grunt2Defeat::
	.string "Burned again!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
	.string "Do you have something against TEAM\n"
	.string "ROCKET?$"

RocketHideout_B4F_Text_Grunt3Intro::
	.string "How can you not see the beauty of\n"
	.string "our evil?$"

RocketHideout_B4F_Text_Grunt3Defeat::
	.string "Ayaya!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
	.string "BOSS!\n"
	.string "I'm sorry I failed you!$"

RocketHideout_B4F_Text_Grunt1Intro::
	.string "The elevator doesn't work?\n"
	.string "Who has the LIFT KEY?$"

RocketHideout_B4F_Text_Grunt1Defeat::
	.string "No!$"

RocketHideout_B4F_Text_Grunt1PostBattle::
	.string "Oh, no!\n"
	.string "I dropped the LIFT KEY!$"


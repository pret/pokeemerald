SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
	.string "PRESIDENT: Oh, dear boy!\n"
	.string "Thank you for saving SILPH.\p"
	.string "I will never forget you saved us in\n"
	.string "our moment of peril.\p"
	.string "I have to thank you in some way.\p"
	.string "Because I am rich, I can give you\n"
	.string "anything.\p"
	.string "Here, maybe this will do.$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
	.string "PRESIDENT: Oh, dear girl!\n"
	.string "Thank you for saving SILPH.\p"
	.string "I will never forget you saved us in\n"
	.string "our moment of peril.\p"
	.string "I have to thank you in some way.\p"
	.string "Because I am rich, I can give you\n"
	.string "anything.\p"
	.string "Here, maybe this will do.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
	.string "{PLAYER} obtained a MASTER BALL\n"
	.string "from the PRESIDENT!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
	.string "PRESIDENT: You can't buy that\n"
	.string "anywhere.\p"
	.string "It's our secret prototype MASTER\n"
	.string "BALL.\p"
	.string "It will catch any POKéMON without\n"
	.string "fail!\p"
	.string "You should be quiet about using it,\n"
	.string "though.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
	.string "You have no room for this.$"

SilphCo_11F_Text_ThanksForRescuingUs::
	.string "SECRETARY: Thank you for rescuing\n"
	.string "all of us.\p"
	.string "We, from the PRESIDENT down,\n"
	.string "are indebted to you.$"

SilphCo_11F_Text_GiovanniIntro::
	.string "Ah, {PLAYER}!\n"
	.string "So we meet again!\p"
	.string "The PRESIDENT and I are discussing\n"
	.string "a vital business proposition.\p"
	.string "Keep your nose out of grown-up\n"
	.string "matters…\p"
	.string "Or, experience a world of pain!$"

SilphCo_11F_Text_GiovanniDefeat::
	.string "Arrgh!!\n"
	.string "I lost again!?$"

SilphCo_11F_Text_GiovanniPostBattle::
	.string "Blast it all!\n"
	.string "You ruined our plans for SILPH!\p"
	.string "But, TEAM ROCKET will never fall!\p"
	.string "{PLAYER}! Never forget that all\n"
	.string "POKéMON exist for TEAM ROCKET!\p"
	.string "I must go, but I shall return!$"

SilphCo_11F_Text_Grunt2Intro::
	.string "Stop right there!\n"
	.string "Don't you move!$"

SilphCo_11F_Text_Grunt2Defeat::
	.string "Don't…\n"
	.string "Please!$"

SilphCo_11F_Text_Grunt2PostBattle::
	.string "So, you want to see my BOSS?$"

SilphCo_11F_Text_Grunt1Intro::
	.string "Halt! Do you have an appointment\n"
	.string "with my BOSS?$"

SilphCo_11F_Text_Grunt1Defeat::
	.string "Gaah!\n"
	.string "Demolished!$"

SilphCo_11F_Text_Grunt1PostBattle::
	.string "Watch your step…\n"
	.string "My BOSS likes his POKéMON tough!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
	.string "The monitor has POKéMON on it!$"

SilphCo_11F_Text_FloorSign::
	.string "SILPH CO. HEAD OFFICE\n"
	.string "11F$"


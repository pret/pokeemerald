EventScript_AfterWhiteOutHeal_Frlg::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox gText_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreFirstBoss
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_PkmnCenterNurse_Frlg::
	message Text_WelcomeWantToHealPkmn_Frlg
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn_Frlg
	case 1 EventScript_PkmnCenterNurse_Goodbye_Frlg
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye_Frlg
	end

EventScript_PkmnCenterNurse_HealPkmn_Frlg::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSeconds_Frlg
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	goto EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom_Frlg
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom_Frlg::
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Frlg
	end

EventScript_PkmnCenterNurse_ReturnPkmn_Frlg::
	message Text_RestoredPkmnToFullHealth_Frlg
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Frlg::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	msgbox Text_RestoredPkmnToFullHealth_Frlg
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message Text_PlayerIsPlayingRightNowGoForIt_Frlg
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

EventScript_PkmnCenterNurse_Goodbye_Frlg::
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

Movement_Bow::
	nurse_joy_bow
	delay_4
	step_end

Text_WelcomeWantToHealPkmn_Frlg::
	.string "Welcome to our POKéMON CENTER!\p"
	.string "Would you like me to heal your\n"
	.string "POKéMON back to perfect health?$"

Text_TakeYourPkmnForFewSeconds_Frlg::
	.string "Okay, I'll take your POKéMON for a\n"
	.string "few seconds.$"

Text_WeHopeToSeeYouAgain_Frlg::
	.string "We hope to see you again!$"

Text_RestoredPkmnToFullHealth_Frlg::
	.string "Thank you for waiting.\n"
	.string "We've restored your POKéMON to\l"
	.string "full health.$"

BattleFrontier_BattleTowerLobby_EventScript_Apprentice::
	lock
	faceplayer
	apprentice_gavelvlmode
	goto_if_eq VAR_RESULT, FALSE, Apprentice_EventScript_FirstMeeting
	apprentice_shouldcheckgone
	goto_if_eq VAR_0x8004, FALSE, Apprentice_EventScript_AskQuestion  @ VAR_0x8004 always TRUE here
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, Apprentice_EventScript_Gone
Apprentice_EventScript_AskQuestion:
	apprentice_getquestion
	goto_if_eq VAR_RESULT, APPRENTICE_QUESTION_WHICH_MON, Apprentice_EventScript_UseWhichMon
	goto_if_eq VAR_RESULT, APPRENTICE_QUESTION_WHAT_ITEM, Apprentice_EventScript_UseWhatHeldItem
	goto_if_eq VAR_RESULT, APPRENTICE_QUESTION_WHICH_MOVE, Apprentice_EventScript_UseWhichMove
	goto_if_eq VAR_RESULT, APPRENTICE_QUESTION_WHICH_FIRST, Apprentice_EventScript_PutWhichMonFirst
	goto_if_eq VAR_RESULT, APPRENTICE_QUESTION_WIN_SPEECH, Apprentice_EventScript_PickWinSpeech
	release
	releaseall
	end

Apprentice_EventScript_FirstMeeting:
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_NAME
	apprentice_msg FALSE, APPRENTICE_MSG_PLEASE_TEACH
Apprentice_EventScript_WhichLvlMode:
	apprentice_menu APPRENTICE_ASK_YES_NO
	goto_if_eq VAR_RESULT, 1, Apprentice_EventScript_RejectTeach
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_LVL_MODE
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
	apprentice_setlvlmode VAR_RESULT
	apprentice_shufflespecies
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_LEVEL
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_LVL_MODE
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

@ Its impossible to fully reject an Apprentice, they just keep asking for you to teach them
Apprentice_EventScript_RejectTeach:
	apprentice_msg FALSE, APPRENTICE_MSG_REJECT
	goto Apprentice_EventScript_WhichLvlMode

Apprentice_EventScript_UseWhichMon:
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MON
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_SPECIES1
	apprentice_buff STR_VAR_2, APPRENTICE_BUFF_SPECIES2
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON
	apprentice_menu APPRENTICE_ASK_2SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	call_if_eq VAR_0x8005, 0, Apprentice_EventScript_ChoseFirstMon
	call_if_eq VAR_0x8005, 1, Apprentice_EventScript_ChoseSecondMon
	apprentice_getnumpartymons
	apprentice_setpartymon VAR_RESULT
	apprentice_answeredquestion
	apprentice_getnumpartymons
	call_if_eq VAR_RESULT, MULTI_PARTY_SIZE, Apprentice_EventScript_LastMonSelected
	apprentice_buff STR_VAR_1, VAR_0x8007
	apprentice_freequestion
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ChoseFirstMon:
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES1
	return

Apprentice_EventScript_ChoseSecondMon:
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES2
	return

Apprentice_EventScript_LastMonSelected:
	apprentice_randomizequestions
	return

Apprentice_EventScript_UseWhatHeldItem:
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg TRUE, APPRENTICE_MSG_WHAT_HELD_ITEM
	apprentice_freequestion
Apprentice_EventScript_ChooseHoldItem:
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	apprentice_openbag
	goto_if_eq VAR_RESULT, FALSE, Apprentice_EventScript_ConfirmHoldNothing
	apprentice_trysetitem
	goto_if_eq VAR_RESULT, FALSE, Apprentice_EventScript_AlreadySuggestedItem
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_ITEM
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_HELD_ITEM
	apprentice_answeredquestion
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ConfirmHoldNothing:
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, APPRENTICE_MSG_HOLD_NOTHING
	apprentice_menu APPRENTICE_ASK_GIVE
	apprentice_freequestion
	goto_if_eq VAR_RESULT, 0, Apprentice_EventScript_ChooseHoldItem
Apprentice_EventScript_HoldNothing:
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_NO_HELD_ITEM
	apprentice_answeredquestion
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

@ Because Battle Tower mons may not hold the same item, the player must suggest a
@ different item if theyve already told the Apprentice to use it for another mon
Apprentice_EventScript_AlreadySuggestedItem:
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_ITEM
	apprentice_buff STR_VAR_2, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, APPRENTICE_MSG_ITEM_ALREADY_SUGGESTED
	apprentice_menu APPRENTICE_ASK_GIVE
	apprentice_freequestion
	goto_if_eq VAR_RESULT, 0, Apprentice_EventScript_ChooseHoldItem
	goto Apprentice_EventScript_HoldNothing
	end

Apprentice_EventScript_UseWhichMove:
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MOVE
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_SPECIES3
	apprentice_buff STR_VAR_2, APPRENTICE_BUFF_MOVE1
	apprentice_buff STR_VAR_3, APPRENTICE_BUFF_MOVE2
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MOVE
	apprentice_menu APPRENTICE_ASK_MOVES
	copyvar VAR_0x8005, VAR_RESULT
	call_if_eq VAR_0x8005, 0, Apprentice_EventScript_ChoseMove1
	call_if_eq VAR_0x8005, 1, Apprentice_EventScript_ChoseMove2
	apprentice_setmove
	apprentice_answeredquestion
	apprentice_buff STR_VAR_1, VAR_0x8007
	apprentice_freequestion
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MOVE
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ChoseMove1:
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE1
	return

Apprentice_EventScript_ChoseMove2:
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE2
	return

Apprentice_EventScript_PutWhichMonFirst:
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON_FIRST
	apprentice_menu APPRENTICE_ASK_3SPECIES
	apprentice_setleadmon VAR_RESULT
	apprentice_answeredquestion
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_LEAD_MON_SPECIES
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON_FIRST
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

@ Last question, after which the Apprentice leaves (and is saved) to be replaced by another
Apprentice_EventScript_PickWinSpeech:
	apprentice_msg TRUE, APPRENTICE_MSG_PICK_WIN_SPEECH
	apprentice_shiftsaved
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	apprentice_save
	apprentice_buff STR_VAR_1, APPRENTICE_BUFF_WIN_SPEECH
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_WIN_SPEECH
	apprentice_reset
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_SetHideFlags:
	setflag FLAG_HIDE_APPRENTICE
	setflag FLAG_DAILY_APPRENTICE_LEAVES
	return

Apprentice_EventScript_LeaveNorth:
	apprentice_shouldleave
	goto_if_eq VAR_0x8004, FALSE, Apprentice_EventScript_DontMove  @ VAR_0x8004 always TRUE here
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_LeaveNorth
	waitmovement 0
	end

Apprentice_EventScript_Leave:
	apprentice_shouldleave
	goto_if_eq VAR_0x8004, FALSE, Apprentice_EventScript_DontMove  @ VAR_0x8004 always TRUE here
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_Leave
	waitmovement 0
	end

Apprentice_EventScript_Gone:
	release
	releaseall
	end

Apprentice_EventScript_DontMove:
	end

Apprentice_Movement_LeaveNorth:
	walk_fast_right
Apprentice_Movement_Leave:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	slide_down
	slide_down
	slide_down
	step_end

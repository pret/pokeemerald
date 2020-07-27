.set LOCALID_APPRENTICE, 6

BattleFrontier_BattleTowerLobby_EventScript_Apprentice:: @ 82B688D
	lock
	faceplayer
	apprentice_gavelvlmode
	compare VAR_RESULT, FALSE
	goto_if_eq Apprentice_EventScript_FirstMeeting
	apprentice_shouldcheckgone
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq Apprentice_EventScript_AskQuestion
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, Apprentice_EventScript_Gone
Apprentice_EventScript_AskQuestion: @ 82B68BE
	apprentice_getquestion
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_MON
	goto_if_eq Apprentice_EventScript_UseWhichMon
	compare VAR_RESULT, APPRENTICE_QUESTION_WHAT_ITEM
	goto_if_eq Apprentice_EventScript_UseWhatHeldItem
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_MOVE
	goto_if_eq Apprentice_EventScript_UseWhichMove
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_FIRST
	goto_if_eq Apprentice_EventScript_PutWhichMonFirst
	compare VAR_RESULT, APPRENTICE_QUESTION_WIN_SPEECH
	goto_if_eq Apprentice_EventScript_PickWinSpeech
	release
	releaseall
	end

Apprentice_EventScript_FirstMeeting: @ 82B6900
	apprentice_buff 0, APPRENTICE_BUFF_NAME
	apprentice_msg FALSE, APPRENTICE_MSG_PLEASE_TEACH
Apprentice_EventScript_WhichLvlMode: @ 82B6925
	apprentice_menu APPRENTICE_ASK_YES_NO
	compare VAR_RESULT, 1
	goto_if_eq Apprentice_EventScript_RejectTeach
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_LVL_MODE
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
	apprentice_setlvlmode VAR_RESULT
	apprentice_shufflespecies
	apprentice_buff 0, APPRENTICE_BUFF_LEVEL
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_LVL_MODE
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

@ Its impossible to fully reject an Apprentice, they just keep asking for you to teach them
Apprentice_EventScript_RejectTeach: @ 82B69BB
	apprentice_msg FALSE, APPRENTICE_MSG_REJECT
	goto Apprentice_EventScript_WhichLvlMode

Apprentice_EventScript_UseWhichMon: @ 82B69D3
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MON
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES1
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES2
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON
	apprentice_menu APPRENTICE_ASK_2SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq Apprentice_EventScript_ChoseFirstMon
	compare VAR_0x8005, 1
	call_if_eq Apprentice_EventScript_ChoseSecondMon
	apprentice_getnumpartymons
	apprentice_setpartymon VAR_RESULT
	apprentice_answeredquestion
	apprentice_getnumpartymons
	compare VAR_RESULT, MULTI_PARTY_SIZE
	call_if_eq Apprentice_EventScript_LastMonSelected
	apprentice_buff 0, VAR_0x8007
	apprentice_freequestion
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ChoseFirstMon: @ 82B6ABA
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES1
	return

Apprentice_EventScript_ChoseSecondMon: @ 82B6AC0
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES2
	return

Apprentice_EventScript_LastMonSelected: @ 82B6AC6
	apprentice_randomizequestions
	return

Apprentice_EventScript_UseWhatHeldItem: @ 82B6ACF
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg TRUE, APPRENTICE_MSG_WHAT_HELD_ITEM
	apprentice_freequestion
Apprentice_EventScript_ChooseHoldItem: @ 82B6B09
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	apprentice_openbag
	compare VAR_RESULT, FALSE
	goto_if_eq Apprentice_EventScript_ConfirmHoldNothing
	apprentice_trysetitem
	compare VAR_RESULT, FALSE
	goto_if_eq Apprentice_EventScript_AlreadySuggestedItem
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_HELD_ITEM
	apprentice_answeredquestion
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ConfirmHoldNothing: @ 82B6B81
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, APPRENTICE_MSG_HOLD_NOTHING
	apprentice_menu APPRENTICE_ASK_GIVE
	apprentice_freequestion
	compare VAR_RESULT, 0
	goto_if_eq Apprentice_EventScript_ChooseHoldItem
Apprentice_EventScript_HoldNothing: @ 82B6BD4
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
Apprentice_EventScript_AlreadySuggestedItem: @ 82B6C0C
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, APPRENTICE_MSG_ITEM_ALREADY_SUGGESTED
	apprentice_menu APPRENTICE_ASK_GIVE
	apprentice_freequestion
	compare VAR_RESULT, 0
	goto_if_eq Apprentice_EventScript_ChooseHoldItem
	goto Apprentice_EventScript_HoldNothing
	end

Apprentice_EventScript_UseWhichMove: @ 82B6C77
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MOVE
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_buff 1, APPRENTICE_BUFF_MOVE1
	apprentice_buff 2, APPRENTICE_BUFF_MOVE2
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MOVE
	apprentice_menu APPRENTICE_ASK_MOVES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq Apprentice_EventScript_ChoseMove1
	compare VAR_0x8005, 1
	call_if_eq Apprentice_EventScript_ChoseMove2
	apprentice_setmove
	apprentice_answeredquestion
	apprentice_buff 0, VAR_0x8007
	apprentice_freequestion
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MOVE
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_ChoseMove1: @ 82B6D50
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE1
	return

Apprentice_EventScript_ChoseMove2: @ 82B6D56
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE2
	return

Apprentice_EventScript_PutWhichMonFirst: @ 82B6D5C
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON_FIRST
	apprentice_menu APPRENTICE_ASK_3SPECIES
	apprentice_setleadmon VAR_RESULT
	apprentice_answeredquestion
	apprentice_buff 0, APPRENTICE_BUFF_LEAD_MON_SPECIES
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON_FIRST
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

@ Last question, after which the Apprentice leaves (and is saved) to be replaced by another
Apprentice_EventScript_PickWinSpeech: @ 82B6DD4
	apprentice_msg TRUE, APPRENTICE_MSG_PICK_WIN_SPEECH
	apprentice_shiftsaved
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	apprentice_save
	apprentice_buff 0, APPRENTICE_BUFF_WIN_SPEECH
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_WIN_SPEECH
	apprentice_reset
	call Apprentice_EventScript_SetHideFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
	goto Apprentice_EventScript_Leave
	end

Apprentice_EventScript_SetHideFlags: @ 82B6E4D
	setflag FLAG_HIDE_APPRENTICE
	setflag FLAG_DAILY_APPRENTICE_LEAVES
	return

Apprentice_EventScript_LeaveNorth: @ 82B6E54
	apprentice_shouldleave
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq Apprentice_EventScript_DontMove
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_LeaveNorth
	waitmovement 0
	end

Apprentice_EventScript_Leave: @ 82B6E72
	apprentice_shouldleave
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq Apprentice_EventScript_DontMove
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_Leave
	waitmovement 0
	end

Apprentice_EventScript_Gone: @ 82B6E90
	release
	releaseall
	end

Apprentice_EventScript_DontMove: @ 82B6E93
	end

Apprentice_Movement_LeaveNorth: @ 82B6E94
	walk_fast_right
Apprentice_Movement_Leave: @ 82B6E95
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

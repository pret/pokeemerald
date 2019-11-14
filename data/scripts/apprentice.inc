.macro apprentice_msg waitbuttonpress:req, which:req
setvar VAR_0x8004, APPRENTICE_FUNC_PRINT_MSG
setvar VAR_0x8005, \waitbuttonpress
setvar VAR_0x8006, \which
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_buff whichstringvar:req, tobuff:req
setvar VAR_0x8004, APPRENTICE_FUNC_16
setvar VAR_0x8005, \whichstringvar
setvar VAR_0x8006, \tobuff
special CallApprenticeFunction
.endm

.macro apprentice_menu which:req
setvar VAR_0x8004, APPRENTICE_FUNC_MENU
setvar VAR_0x8005, \which
special CallApprenticeFunction
waitstate
.endm

BattleFrontier_BattleTowerLobby_EventScript_Apprentice:: @ 82B688D
	lock
	faceplayer
	setvar VAR_0x8004, APPRENTICE_FUNC_0
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6900
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_TRUE_1
	special CallApprenticeFunction
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B68BE
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_2B6E90

BattleFrontier_BattleTowerLobby_EventScript_2B68BE: @ 82B68BE
	setvar VAR_0x8004, APPRENTICE_FUNC_11
	special CallApprenticeFunction
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B69D3
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ACF
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C77
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D5C
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6DD4
	release
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6900: @ 82B6900
	apprentice_buff 0, APPRENTICE_BUFF_NAME
	apprentice_msg FALSE, 0
BattleFrontier_BattleTowerLobby_EventScript_2B6925: @ 82B6925
	apprentice_menu APPRENTICE_ASK_YES_NO
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B69BB
	apprentice_msg FALSE, 2
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
	setvar VAR_0x8004, APPRENTICE_FUNC_1
	setorcopyvar VAR_0x8005, VAR_RESULT
	addvar VAR_0x8005, 1
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_LEVEL
	apprentice_msg TRUE, 3
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B69BB: @ 82B69BB
	apprentice_msg FALSE, 1
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6925

BattleFrontier_BattleTowerLobby_EventScript_2B69D3: @ 82B69D3
	setvar VAR_0x8004, APPRENTICE_FUNC_14
	setvar VAR_0x8005, 2
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES1
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES2
	apprentice_msg FALSE, 6
	apprentice_menu APPRENTICE_ASK_2SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ABA
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC0
	setvar VAR_0x8004, APPRENTICE_FUNC_12
	special CallApprenticeFunction
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, APPRENTICE_FUNC_13
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_5
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_12
	special CallApprenticeFunction
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC6
	setvar VAR_0x8004, APPRENTICE_FUNC_16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_15
	special CallApprenticeFunction
	apprentice_msg TRUE, 7
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6ABA: @ 82B6ABA
	setvar VAR_0x8007, 0
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC0: @ 82B6AC0
	setvar VAR_0x8007, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC6: @ 82B6AC6
	setvar VAR_0x8004, APPRENTICE_FUNC_4
	special CallApprenticeFunction
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6ACF: @ 82B6ACF
	setvar VAR_0x8004, APPRENTICE_FUNC_14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg TRUE, 10
	setvar VAR_0x8004, APPRENTICE_FUNC_15
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_2B6B09: @ 82B6B09
	fadescreen 1
	setvar VAR_RESULT, 0
	setvar VAR_0x8004, APPRENTICE_FUNC_19
	special CallApprenticeFunction
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B81
	setvar VAR_0x8004, APPRENTICE_FUNC_20
	special CallApprenticeFunction
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C0C
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_msg TRUE, 12
	setvar VAR_0x8004, APPRENTICE_FUNC_5
	special CallApprenticeFunction
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6B81: @ 82B6B81
	setvar VAR_0x8004, APPRENTICE_FUNC_14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 13
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09

BattleFrontier_BattleTowerLobby_EventScript_2B6BD4: @ 82B6BD4
	apprentice_msg TRUE, 14
	setvar VAR_0x8004, APPRENTICE_FUNC_5
	special CallApprenticeFunction
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C0C: @ 82B6C0C
	setvar VAR_0x8004, APPRENTICE_FUNC_14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 16
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6BD4
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C77: @ 82B6C77
	setvar VAR_0x8004, APPRENTICE_FUNC_14
	setvar VAR_0x8005, 3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_buff 1, APPRENTICE_BUFF_MOVE1
	apprentice_buff 2, APPRENTICE_BUFF_MOVE2
	apprentice_msg FALSE, 8
	apprentice_menu APPRENTICE_ASK_MOVES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D50
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D56
	setvar VAR_0x8004, APPRENTICE_FUNC_17
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_5
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_15
	special CallApprenticeFunction
	apprentice_msg TRUE, 9
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6D50: @ 82B6D50
	setvar VAR_0x8007, 3
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D56: @ 82B6D56
	setvar VAR_0x8007, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D5C: @ 82B6D5C
	apprentice_msg FALSE, 4
	apprentice_menu APPRENTICE_ASK_3SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, APPRENTICE_FUNC_18
	special CallApprenticeFunction
	setvar VAR_0x8004, APPRENTICE_FUNC_5
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES4
	apprentice_msg TRUE, 5
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6DD4: @ 82B6DD4
	apprentice_msg TRUE, 11
	setvar VAR_0x8004, APPRENTICE_FUNC_25
	special CallApprenticeFunction
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	setvar VAR_0x8004, APPRENTICE_FUNC_21
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_EASY_CHAT
	apprentice_msg TRUE, 15
	setvar VAR_0x8004, APPRENTICE_FUNC_9
	special CallApprenticeFunction
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E4D: @ 82B6E4D
	setflag FLAG_HIDE_APPRENTICE
	setflag FLAG_DAILY_APPRENTICE_LEAVES
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6E54: @ 82B6E54
	setvar VAR_0x8004, APPRENTICE_FUNC_SHOULD_LEAVE
	special CallApprenticeFunction
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ApprenticeDontMove
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E94
	waitmovement 0
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E72: @ 82B6E72
	setvar VAR_0x8004, APPRENTICE_FUNC_SHOULD_LEAVE
	special CallApprenticeFunction
	compare VAR_0x8004, FALSE  @ Always TRUE here
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ApprenticeDontMove
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E95
	waitmovement 0
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E90: @ 82B6E90
	release
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ApprenticeDontMove: @ 82B6E93
	end

BattleFrontier_BattleTowerLobby_Movement_2B6E94: @ 82B6E94
	walk_fast_right
BattleFrontier_BattleTowerLobby_Movement_2B6E95: @ 82B6E95
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

BattleFrontier_BattlePikeLobby_MapScripts:: @ 825B6C6
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_MapScript2_25B6D1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_MapScript2_25B6F3
	.byte 0

BattleFrontier_BattlePikeLobby_MapScript2_25B6D1: @ 825B6D1
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeLobby_EventScript_25B707
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattlePikeLobby_EventScript_25B710
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattlePikeLobby_EventScript_25B762
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattlePikeLobby_EventScript_25B806
	.2byte 0

BattleFrontier_BattlePikeLobby_MapScript2_25B6F3: @ 825B6F3
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_25B6FD
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_25B6FD:: @ 825B6FD
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_25B707:: @ 825B707
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeLobby_EventScript_25B710:: @ 825B710
	special HealPlayerParty
	setvar VAR_0x8004, 27
	special CallBattlePikeFunction
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_25C2E0, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattlePikeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 0
	special CallBattlePikeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_25B762:: @ 825B762
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_25B784
	msgbox BattleFrontier_BattlePikeLobby_Text_25C18A, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_25B78D

BattleFrontier_BattlePikeLobby_EventScript_25B784:: @ 825B784
	msgbox BattleFrontier_BattlePikeLobby_Text_25C383, MSGBOX_DEFAULT
	waitmessage

BattleFrontier_BattlePikeLobby_EventScript_25B78D:: @ 825B78D
	msgbox BattleFrontier_BattlePikeLobby_Text_25C3D9, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePikeLobby_Text_241520, 9
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 3
	special CallBattlePikeFunction
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	copyvar VAR_0x8006, VAR_RESULT
	special CallBattlePikeFunction
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 27
	special CallBattlePikeFunction
	message BattleFrontier_BattlePikeLobby_Text_25C1DF
	waitmessage
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special CallBattlePikeFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_25BE02, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_25B806:: @ 825B806
	lockall
	message BattleFrontier_BattlePikeLobby_Text_25C146
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 0
	special CallBattlePikeFunction
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 27
	special CallBattlePikeFunction
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special CallBattlePikeFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_25BE02, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_25B868:: @ 825B868
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 5
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_25BB52, MSGBOX_DEFAULT

BattleFrontier_BattlePikeLobby_EventScript_25B87F:: @ 825B87F
	message BattleFrontier_BattlePikeLobby_Text_25BBC1
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_25B8BB
	case 1, BattleFrontier_BattlePikeLobby_EventScript_25BA1A
	case 2, BattleFrontier_BattlePikeLobby_EventScript_25BA76
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_25BA76

BattleFrontier_BattlePikeLobby_EventScript_25B8BB:: @ 825B8BB
	message BattleFrontier_BattlePikeLobby_Text_25BE35
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattlePikeLobby_EventScript_25BA76
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_25BA76
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_25BA27
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePikeLobby_Text_25C094, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattlePikeLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_25BA73
	msgbox BattleFrontier_BattlePikeLobby_Text_25C0D8, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_25BA73
	case 1, BattleFrontier_BattlePikeLobby_EventScript_25B95C
	case 127, BattleFrontier_BattlePikeLobby_EventScript_25BA73

BattleFrontier_BattlePikeLobby_EventScript_25B95C:: @ 825B95C
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 28
	special CallBattlePikeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	special CallBattlePikeFunction
	setvar VAR_0x8004, 26
	special CallBattlePikeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8004, 26
	special CallBattlePikeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_25BA5C
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePikeLobby_Text_25C130, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 5
	special CallFrontierUtilFunc
	call BattleFrontier_BattlePikeLobby_EventScript_25BA94
	special HealPlayerParty
	call BattleFrontier_BattlePikeLobby_EventScript_25BB49
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 255, 6, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_25BA1A:: @ 825BA1A
	msgbox BattleFrontier_BattlePikeLobby_Text_25BBF5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25B87F

BattleFrontier_BattlePikeLobby_EventScript_25BA27:: @ 825BA27
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_25BA42
	case 1, BattleFrontier_BattlePikeLobby_EventScript_25BA4F

BattleFrontier_BattlePikeLobby_EventScript_25BA42:: @ 825BA42
	msgbox BattleFrontier_BattlePikeLobby_Text_25BE8C, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BA7E

BattleFrontier_BattlePikeLobby_EventScript_25BA4F:: @ 825BA4F
	msgbox BattleFrontier_BattlePikeLobby_Text_25BF9A, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BA7E

BattleFrontier_BattlePikeLobby_EventScript_25BA5C:: @ 825BA5C
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePikeLobby_EventScript_25BA76

BattleFrontier_BattlePikeLobby_EventScript_25BA73:: @ 825BA73
	special LoadPlayerParty

BattleFrontier_BattlePikeLobby_EventScript_25BA76:: @ 825BA76
	msgbox BattleFrontier_BattlePikeLobby_Text_25BE02, MSGBOX_DEFAULT

BattleFrontier_BattlePikeLobby_EventScript_25BA7E:: @ 825BA7E
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_25BA80:: @ 825BA80
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_25BA94:: @ 825BA94
	applymovement 1, BattleFrontier_BattlePikeLobby_Movement_25BAA7
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_25BAA6
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_25BAA6: @ 825BAA6
	walk_up

BattleFrontier_BattlePikeLobby_Movement_25BAA7: @ 825BAA7
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_25BAAB:: @ 825BAAB
	msgbox BattleFrontier_BattlePikeLobby_Text_25C422, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_25BAB4:: @ 825BAB4
	msgbox BattleFrontier_BattlePikeLobby_Text_25C4A5, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_25BABD:: @ 825BABD
	msgbox BattleFrontier_BattlePikeLobby_Text_25C4FD, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_25BAC6:: @ 825BAC6
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_25C5FB, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BAD5
	end

BattleFrontier_BattlePikeLobby_EventScript_25BAD5:: @ 825BAD5
	message BattleFrontier_BattlePikeLobby_Text_25C621
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_25BB1D
	case 1, BattleFrontier_BattlePikeLobby_EventScript_25BB2B
	case 2, BattleFrontier_BattlePikeLobby_EventScript_25BB39
	case 3, BattleFrontier_BattlePikeLobby_EventScript_25BB47
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_25BB47
	end

BattleFrontier_BattlePikeLobby_EventScript_25BB1D:: @ 825BB1D
	msgbox BattleFrontier_BattlePikeLobby_Text_25C644, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BAD5
	end

BattleFrontier_BattlePikeLobby_EventScript_25BB2B:: @ 825BB2B
	msgbox BattleFrontier_BattlePikeLobby_Text_25C68A, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BAD5
	end

BattleFrontier_BattlePikeLobby_EventScript_25BB39:: @ 825BB39
	msgbox BattleFrontier_BattlePikeLobby_Text_25C6EB, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_25BAD5
	end

BattleFrontier_BattlePikeLobby_EventScript_25BB47:: @ 825BB47
	releaseall
	end

BattleFrontier_BattlePikeCorridor_EventScript_25BB49:: @ 825BB49
BattleFrontier_BattlePikeLobby_EventScript_25BB49:: @ 825BB49
BattleFrontier_BattlePikeRandomRoom1_EventScript_25BB49:: @ 825BB49
BattleFrontier_BattlePikeThreePathRoom_EventScript_25BB49:: @ 825BB49
	playse SE_CURTAIN
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_25BB52: @ 825BB52
	.string "Where the luck of TRAINERS\n"
	.string "is put to the test…\p"
	.string "Welcome to the BATTLE PIKE…\p"
	.string "I am your guide to the BATTLE PIKE…$"

BattleFrontier_BattlePikeLobby_Text_25BBC1: @ 825BBC1
	.string "Would you like to take the Battle\n"
	.string "Choice challenge?$"

BattleFrontier_BattlePikeLobby_Text_25BBF5: @ 825BBF5
	.string "Here we conduct an event we call\n"
	.string "the Battle Choice.\p"
	.string "The Battle Choice rules are very\n"
	.string "simple…\p"
	.string "Choose one of three paths and make\n"
	.string "your way to the goal room at the end\l"
	.string "of the BATTLE PIKE. It's that simple.\p"
	.string "However, what happens on the chosen\n"
	.string "path depends entirely on the luck\l"
	.string "of the challenger…\p"
	.string "If you reach the goal, you will be\n"
	.string "rewarded with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please have a word with\l"
	.string "our staff in the big rooms on the way.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePikeLobby_Text_25BE02: @ 825BE02
	.string "We look forward to seeing you\n"
	.string "on another occasion…$"

BattleFrontier_BattlePikeLobby_Text_25BE35: @ 825BE35
	.string "You have the choice of two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you challenge?$"

BattleFrontier_BattlePikeLobby_Text_25BE8C: @ 825BE8C
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when\n"
	.string "you are ready…$"

BattleFrontier_BattlePikeLobby_Text_25BF9A: @ 825BF9A
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different\n"
	.string "POKéMON to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when\n"
	.string "you are ready…$"

BattleFrontier_BattlePikeLobby_Text_25C094: @ 825C094
	.string "Please choose the three POKéMON\n"
	.string "you wish to enter in the challenge…$"

BattleFrontier_BattlePikeLobby_Text_25C0D8: @ 825C0D8
	.string "Before starting your Battle Choice\n"
	.string "challenge, I must save the game.\l"
	.string "Is that acceptable?$"

BattleFrontier_BattlePikeLobby_Text_25C130: @ 825C130
	.string "Please step this way…$"

BattleFrontier_BattlePikeLobby_Text_25C146: @ 825C146
	.string "Your challenge has ended…\p"
	.string "I shall record your results.\n"
	.string "Please wait…$"

BattleFrontier_BattlePikeLobby_Text_25C18A: @ 825C18A
	.string "You have completed the challenge…\p"
	.string "I must say… You seem to possess luck\n"
	.string "in abundance…$"

BattleFrontier_BattlePikeLobby_Text_25C1DF: @ 825C1DF
	.string "I shall record your results.\n"
	.string "Please wait…$"

BattleFrontier_BattlePikeLobby_Text_25C209: @ 825C209
	.string "To commemorate your completion of\n"
	.string "the Battle Choice challenge, we award\l"
	.string "you these Battle Point(s)…$"

BattleFrontier_BattlePikeLobby_Text_25C26C: @ 825C26C
	.string "You appear to have reached the limit\n"
	.string "for Battle Points…\pPlease exchange some Battle Points\n"
	.string "for prizes, then return…$"

BattleFrontier_BattlePikeLobby_Text_25C2E0: @ 825C2E0
	.string "I beg your pardon, but…\p"
	.string "You failed to save before you quit\n"
	.string "your challenge the last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. I am sorry…$"

BattleFrontier_BattlePikeLobby_Text_25C383: @ 825C383
	.string "Congratulations…\p"
	.string "You have snatched victory from the\n"
	.string "PIKE QUEEN and cleared the event…$"

BattleFrontier_BattlePikeLobby_Text_25C3D9: @ 825C3D9
	.string "In recognition of your amazing luck,\n"
	.string "we award you these Battle Point(s)…$"

BattleFrontier_BattlePikeLobby_Text_25C422: @ 825C422
	.string "Arrgh! I blew my chance!\n"
	.string "I was one room away from the goal!\p"
	.string "In this place, you'd better watch out\n"
	.string "for poison, freezing, and so on.$"

BattleFrontier_BattlePikeLobby_Text_25C4A5: @ 825C4A5
	.string "I've completed the challenge 10 times\n"
	.string "now, but I've never had to battle\l"
	.string "a TRAINER once.$"

BattleFrontier_BattlePikeLobby_Text_25C4FD: @ 825C4FD
	.string "Listen! Listen!\p"
	.string "Don't you think that the special\n"
	.string "abilities of POKéMON will be useful\l"
	.string "here?$"

BattleFrontier_BattlePikeLobby_Text_25C558: @ 825C558
	.string "What is this weird place?\n"
	.string "I can't figure it out at all!\p"
	.string "I've taken the challenge a bunch\n"
	.string "of times, but all I ever do is run into\l"
	.string "TRAINERS whichever path I choose.$"

BattleFrontier_BattlePikeLobby_Text_25C5FB: @ 825C5FB
	.string "The Battle Choice's rules are listed.$"

BattleFrontier_BattlePikeLobby_Text_25C621: @ 825C621
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePikeLobby_Text_25C644: @ 825C644
	.string "The BAG and POKéNAV may not be used\n"
	.string "during a Battle Choice challenge.$"

BattleFrontier_BattlePikeLobby_Text_25C68A: @ 825C68A
	.string "During a Battle Choice challenge,\n"
	.string "any BERRY or HERB held by POKéMON\l"
	.string "will be effective only once.$"

BattleFrontier_BattlePikeLobby_Text_25C6EB: @ 825C6EB
	.string "During a Battle Choice challenge,\n"
	.string "the sequence of POKéMON cannot be\l"
	.string "changed.\p"
	.string "The sequence must be set before\n"
	.string "starting your challenge.$"


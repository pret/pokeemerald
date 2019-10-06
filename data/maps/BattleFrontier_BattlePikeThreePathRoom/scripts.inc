BattleFrontier_BattlePikeThreePathRoom_MapScripts:: @ 825C843
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeThreePathRoom_MapScript1_2C423E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_MapScript2_25C853
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_MapScript2_25C87D
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_MapScript2_25C853: @ 825C853
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C891
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C89A
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C8A4
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA78
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA97
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_MapScript2_25C87D: @ 825C87D
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C887
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C887:: @ 825C887
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C891:: @ 825C891
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C89A:: @ 825C89A
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C8A4:: @ 825C8A4
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_25CD75
	waitmessage
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	special CallBattlePikeFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CDDA, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_0x8004, 5
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 99
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C908:: @ 825C908
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C968
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C978
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C988
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C998
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9A8
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9B8
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9C8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C968:: @ 825C968
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CBDD, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C978:: @ 825C978
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CC00, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C988:: @ 825C988
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CC23, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C998:: @ 825C998
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CC46, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9A8:: @ 825C9A8
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CC69, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9B8:: @ 825C9B8
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CC8C, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9C8:: @ 825C9C8
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CCB0, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9D8:: @ 825C9D8
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CCD4, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA2A
	case 127, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA2A
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9FD:: @ 825C9FD
	setvar VAR_0x8004, 6
	special CallFrontierUtilFunc
	message BattleFrontier_BattlePikeThreePathRoom_Text_25CE08
	waitmessage
	special LoadPlayerParty
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 2
	special CallBattlePikeFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA2A:: @ 825CA2A
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CCFB, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C9FD
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA5A
	case 127, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA5A
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA5A:: @ 825CA5A
	message BattleFrontier_BattlePikeThreePathRoom_Text_25CD3C
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4222
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA78:: @ 825CA78
	setvar VAR_0x8004, 17
	special CallBattlePikeFunction
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA91
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA91:: @ 825CA91
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CA97:: @ 825CA97
	applymovement 2, BattleFrontier_BattlePikeThreePathRoom_Movement_25CBCE
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25D094, MSGBOX_DEFAULT
	releaseall
	applymovement 2, BattleFrontier_BattlePikeThreePathRoom_Movement_25CBD5
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CABB:: @ 825CABB
	setvar VAR_0x8004, 19
	special CallBattlePikeFunction
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBC2
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CE69, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB0A
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB00
	case 127, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB00
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB00:: @ 825CB00
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CEBB, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB0A:: @ 825CB0A
	setvar VAR_0x8004, 18
	special CallBattlePikeFunction
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB39
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB46
	case 2, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB53
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB39:: @ 825CB39
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CF64, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB60

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB46:: @ 825CB46
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CF23, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB60

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB53:: @ 825CB53
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CEE3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB60

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB60:: @ 825CB60
	setvar VAR_0x8004, 19
	special CallBattlePikeFunction
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB9A
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBA4
	case 2, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBAE
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBB8
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CB9A:: @ 825CB9A
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25D054, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBA4:: @ 825CBA4
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25D017, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBAE:: @ 825CBAE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CFA3, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBB8:: @ 825CBB8
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CFE5, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_25CBC2:: @ 825CBC2
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25D125, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_25CBCE: @ 825CBCE
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_25CBD5: @ 825CBD5
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_25CBDD: @ 825CBDD
	.string "You are currently in\n"
	.string "the 1st room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CC00: @ 825CC00
	.string "You are currently in\n"
	.string "the 3rd room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CC23: @ 825CC23
	.string "You are currently in\n"
	.string "the 5th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CC46: @ 825CC46
	.string "You are currently in\n"
	.string "the 7th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CC69: @ 825CC69
	.string "You are currently in\n"
	.string "the 9th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CC8C: @ 825CC8C
	.string "You are currently in\n"
	.string "the 11th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CCB0: @ 825CCB0
	.string "You are currently in\n"
	.string "the 13th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CCD4: @ 825CCD4
	.string "Will you continue with\n"
	.string "your challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CCFB: @ 825CCFB
	.string "Would you like to save your challenge\n"
	.string "and quit the game for now?$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CD3C: @ 825CD3C
	.string "Do you wish to retire from your\n"
	.string "Battle Choice challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CD75: @ 825CD75
	.string "We've been awaiting your return…\p"
	.string "Before resuming your Battle Choice\n"
	.string "challenge, let me save the game…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CDDA: @ 825CDDA
	.string "Please do enjoy your Battle Choice\n"
	.string "challenge…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CE08: @ 825CE08
	.string "I am saving your data…\n"
	.string "A little time, please…$"

BattleFrontier_BattlePikeRandomRoom1_Text_25CE36: @ 825CE36
BattleFrontier_BattlePikeRandomRoom3_Text_25CE36: @ 825CE36
BattleFrontier_BattlePikeThreePathRoom_Text_25CE36: @ 825CE36
	.string "The path is blocked!\n"
	.string "And there is no turning back…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CE69: @ 825CE69
	.string "I beg your pardon, but…\p"
	.string "Are you perhaps finding it difficult\n"
	.string "to choose your path?$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CEBB: @ 825CEBB
	.string "I see…\n"
	.string "I apologize for my impertinence…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CEE3: @ 825CEE3
	.string "Ah, let me see… There is something\n"
	.string "about the path on the right…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CF23: @ 825CF23
	.string "Ah, let me see… There is something\n"
	.string "about the path in the center…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CF64: @ 825CF64
	.string "Ah, let me see… There is something\n"
	.string "about the path on the left…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CFA3: @ 825CFA3
	.string "It seems to have the distinct aroma\n"
	.string "of POKéMON wafting around it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25CFE5: @ 825CFE5
	.string "Is it… A TRAINER?\n"
	.string "I sense the presence of people…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25D017: @ 825D017
	.string "I seem to have heard something…\n"
	.string "It may have been whispering…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25D054: @ 825D054
	.string "For some odd reason, I felt a wave\n"
	.string "of nostalgia coming from it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25D094: @ 825D094
	.string "I am sorry to say…\p"
	.string "A terrifying event, yes, a horrible one,\n"
	.string "is about to befall you…\p"
	.string "I urge you to pay the utmost care\n"
	.string "and prepare for the worst…$"

BattleFrontier_BattlePikeThreePathRoom_Text_25D125: @ 825D125
	.string "From every path I sense a dreadful\n"
	.string "presence…$"

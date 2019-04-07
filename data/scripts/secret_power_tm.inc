Route111_Text_2762C9: @ 82762C9
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about making my own room\n"
	.string "here using a POKéMON move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it to make your own room?$"

Route111_Text_27636E: @ 827636E
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use SECRET POWER in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You'll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It'll be your own secret room…\n"
	.string "A SECRET BASE!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don't always have\n"
	.string "to make your SECRET BASE in a tree.\p"
	.string "Try using SECRET POWER on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I'm going to look for other places, too.\n"
	.string "Okay, bye!$"

Route111_Text_27655C: @ 827655C
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_27659D: @ 827659D
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"

Route111_EventScript_2765FF:: @ 82765FF
	lock
	faceplayer
	msgbox Route111_Text_2762C9, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_27661E
	msgbox Route111_Text_27655C, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_27661E:: @ 827661E
	giveitem_std ITEM_TM43
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_276680
	msgbox Route111_Text_27636E, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	compare VAR_FACING, 3
	call_if_eq Route111_EventScript_27666A
	compare VAR_FACING, 4
	call_if_eq Route111_EventScript_27666A
	compare VAR_FACING, 2
	call_if_eq Route111_EventScript_276675
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_27666A:: @ 827666A
	applymovement VAR_LAST_TALKED, Route111_Movement_27668A
	waitmovement 0
	return

Route111_EventScript_276675:: @ 8276675
	applymovement VAR_LAST_TALKED, Route111_Movement_276696
	waitmovement 0
	return

Route111_EventScript_276680:: @ 8276680
	msgbox Route111_Text_27659D, MSGBOX_DEFAULT
	release
	end

Route111_Movement_27668A: @ 827668A
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_276696: @ 8276696
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about making my own room\n"
	.string "here using a Pokémon move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it to make your own room?$"

Route111_Text_ExplainSecretPower:
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use Secret Power in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You'll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It'll be your own secret room…\n"
	.string "A Secret Base!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don't always have\n"
	.string "to make your Secret Base in a tree.\p"
	.string "Try using Secret Power on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I'm going to look for other places, too.\n"
	.string "Okay, bye!$"

Route111_Text_DontWantThis:
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM43
	compare VAR_RESULT, FALSE
	goto_if_eq Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	compare VAR_FACING, DIR_WEST
	call_if_eq Route111_EventScript_SecretPowerManExit
	compare VAR_FACING, DIR_EAST
	call_if_eq Route111_EventScript_SecretPowerManExit
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
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

Route111_Movement_SecretPowerManExitNorth:
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

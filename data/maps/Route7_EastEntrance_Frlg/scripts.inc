Route7_EastEntrance_Frlg_MapScripts::
	.byte 0

Route7_EastEntrance_EventScript_Guard::
	msgbox Route7_EastEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route7_EastEntrance_EventScript_GuardTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route7_EastEntrance_EventScript_GuardTrigger
	end

Route7_EastEntrance_EventScript_GuardTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route7_EastEntrance_EventScript_GuardTrigger
	end

Route7_EastEntrance_EventScript_GuardTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route7_EastEntrance_EventScript_GuardTrigger
	end

Route7_EastEntrance_EventScript_GuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto_if_set FLAG_GOT_TEA, Route7_EastEntrance_EventScript_GiveTea
	msgbox Route7_EastEntrance_Text_ThirstyOnGuardDuty
	closemessage
	applymovement LOCALID_PLAYER, Route7_EastEntrance_Movement_BlockPlayerEntry
	waitmovement 0
	releaseall
	end

Route7_EastEntrance_EventScript_GiveTea::
	removeitem ITEM_TEA
	goto Route7_EastEntrance_EventScript_GuardDrinkTea
	end

Route7_EastEntrance_EventScript_GuardDrinkTea::
	msgbox Route7_EastEntrance_Text_ThatTeaLooksTasty
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route7_EastEntrance_WalkToGuardTop
	call_if_eq VAR_TEMP_1, 1, Route7_EastEntrance_WalkToGuardMid
	call_if_eq VAR_TEMP_1, 2, Route7_EastEntrance_WalkToGuardBottom
	msgbox Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards
	setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
	releaseall
	end

Route7_EastEntrance_WalkToGuardTop::
	applymovement LOCALID_PLAYER, Route7_EastEntrance_Movement_WalkToGuardTop
	waitmovement 0
	return

Route7_EastEntrance_WalkToGuardMid::
	applymovement LOCALID_PLAYER, Route7_EastEntrance_Movement_WalkToGuardMid
	waitmovement 0
	return

Route7_EastEntrance_WalkToGuardBottom::
	applymovement LOCALID_PLAYER, Route7_EastEntrance_Movement_WalkToGuardBottom
	waitmovement 0
	return

Route7_EastEntrance_Movement_WalkToGuardMid::
	walk_up
	step_end

Route7_EastEntrance_Movement_WalkToGuardBottom::
	walk_up
	walk_up
	step_end

Route7_EastEntrance_Movement_WalkToGuardTop::
	walk_in_place_up
	step_end

Route7_EastEntrance_Movement_BlockPlayerEntry::
	walk_left
	step_end

Route7_EastEntrance_Text_ThirstyOnGuardDuty::
	.string "I'm on guard duty.\n"
	.string "Gee, I'm thirsty, though!\p"
	.string "Oh, wait there, the road's closed.$"

Route7_EastEntrance_Text_ThatTeaLooksTasty::
	.string "Oh, that TEA…\n"
	.string "It looks awfully tasty…$"

Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards::
	.string "Huh? I can have this drink?\n"
	.string "Gee, thanks!\l"
	.string "… …\l"
	.string "Glug, glug…\l"
	.string "… …\l"
	.string "Gulp…\l"
	.string "If you want to go to SAFFRON\l"
	.string "CITY…\l"
	.string "… …\l"
	.string "You can go on through.\p"
	.string "I'll share this TEA with the other\n"
	.string "guards!$"

Route7_EastEntrance_Text_HiHowsItGoing::
	.string "Hi, how's it going?$"


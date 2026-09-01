Route5_SouthEntrance_Frlg_MapScripts::
	.byte 0

Route5_SouthEntrance_EventScript_Guard::
	msgbox Route5_SouthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route5_SouthEntrance_EventScript_GuardTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route5_SouthEntrance_EventScript_GuardTrigger
	end

Route5_SouthEntrance_EventScript_GuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto_if_set FLAG_GOT_TEA, Route5_SouthEntrance_EventScript_GiveTea
	msgbox Route5_SouthEntrance_Text_ThirstyOnGuardDuty
	closemessage
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_BlockPlayerEntry
	waitmovement 0
	releaseall
	end

Route5_SouthEntrance_EventScript_GiveTea::
	removeitem ITEM_TEA
	goto Route5_SouthEntrance_EventScript_GuardDrinkTea
	end

Route5_SouthEntrance_EventScript_GuardDrinkTea::
	msgbox Route5_SouthEntrance_Text_ThatTeaLooksTasty
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route5_SouthEntrance_EventScript_WalkToGuardLeft
	call_if_eq VAR_TEMP_1, 1, Route5_SouthEntrance_EventScript_WalkToGuardMid
	call_if_eq VAR_TEMP_1, 2, Route5_SouthEntrance_EventScript_WalkToGuardRight
	msgbox Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards
	setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
	releaseall
	end

Route5_SouthEntrance_EventScript_WalkToGuardLeft::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardLeft
	waitmovement 0
	return

Route5_SouthEntrance_EventScript_WalkToGuardMid::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardMid
	waitmovement 0
	return

Route5_SouthEntrance_EventScript_WalkToGuardRight::
	applymovement LOCALID_PLAYER, Route5_SouthEntrance_Movement_WalkToGuardRight
	waitmovement 0
	return

Route5_SouthEntrance_Movement_WalkToGuardMid::
	walk_left
	step_end

Route5_SouthEntrance_Movement_WalkToGuardRight::
	walk_left
	walk_left
	step_end

Route5_SouthEntrance_Movement_WalkToGuardLeft::
	walk_in_place_left
	step_end

Route5_SouthEntrance_Movement_BlockPlayerEntry::
	walk_up
	step_end

Route5_SouthEntrance_Text_ThirstyOnGuardDuty::
	.string "I'm on guard duty.\n"
	.string "Gee, I'm thirsty, though!\p"
	.string "Oh, wait there, the road's closed.$"

Route5_SouthEntrance_Text_ThatTeaLooksTasty::
	.string "Oh, that TEA…\n"
	.string "It looks awfully tasty…$"

Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards::
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

Route5_SouthEntrance_Text_HiHowsItGoing::
	.string "Hi, how's it going?$"


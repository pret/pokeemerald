.set LOCALID_OLD_MAN, 1

SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition:
	frontier_checkvisittrainer
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	call_if_ne SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout::
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_OLD_MAN, 3, 2
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor::
	setobjectxyperm LOCALID_OLD_MAN, 2, 2
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs
	waitmovement 0
	applymovement LOCALID_OLD_MAN, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_OLD_MAN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment
	special LoadPlayerParty
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	releaseall
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs:
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer:
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
	lock
	faceplayer
	frontier_checkvisittrainer
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
	compare VAR_TEMP_1, 1
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting::
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
	compare VAR_FACING, DIR_WEST
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 255, 3, 1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle::
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth:
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast:
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest:
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft:
	walk_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight:
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles:
	.string "When I was young, I traveled the world\n"
	.string "as a Pokémon Trainer.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "Trainers battle.$"

SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked:
	.string "The door appears to be locked.$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer:
	.string "A Trainer named {STR_VAR_1}\n"
	.string "is visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle:
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3:
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle:
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch:
	.string "I hope to see a good match!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw:
	.string "The match ended up a draw.$"

SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff:
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative:
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou:
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"


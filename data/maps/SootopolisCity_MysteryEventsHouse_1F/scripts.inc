.set LOCALID_OLD_MAN, 1

SootopolisCity_MysteryEventsHouse_1F_MapScripts:: @ 8227953
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition: @ 822795E
	frontier_checkvisittrainer
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	call_if_ne SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout:: @ 822797D
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_OLD_MAN, 3, 2
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor:: @ 8227991
	setobjectxyperm LOCALID_OLD_MAN, 2, 2
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_OnFrame: @ 822799D
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle:: @ 82279B7
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

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment:: @ 8227A04
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment:: @ 8227A0D
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment:: @ 8227A16
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs: @ 8227A1F
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer: @ 8227A21
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan:: @ 8227A24
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

SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer:: @ 8227A4E
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting:: @ 8227A58
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

SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle:: @ 8227AE2
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty:: @ 8227AEF
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth:: @ 8227AFE
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast:: @ 8227B10
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest:: @ 8227B22
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth: @ 8227B34
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast: @ 8227B38
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest: @ 8227B3C
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft: @ 8227B40
	walk_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight: @ 8227B43
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles: @ 8227B46
	.string "When I was young, I traveled the world\n"
	.string "as a POKéMON TRAINER.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "TRAINERS battle.$"

SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked: @ 8227BDD
	.string "The door appears to be locked.$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer: @ 8227BFC
	.string "A TRAINER named {STR_VAR_1}\n"
	.string "is visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle: @ 8227C44
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3: @ 8227C84
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle: @ 8227CEB
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch: @ 8227D21
	.string "I hope to see a good match!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie: @ 8227D3D
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw: @ 8227D40
	.string "The match ended up a draw.$"

SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff: @ 8227D5B
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won: @ 8227DB5
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative: @ 8227DB8
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost: @ 8227E00
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou: @ 8227E03
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"


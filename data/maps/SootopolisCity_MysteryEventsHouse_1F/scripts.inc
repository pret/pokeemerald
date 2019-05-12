SootopolisCity_MysteryEventsHouse_1F_MapScripts:: @ 8227953
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_MapScript2_22799D
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition: @ 822795E
	setvar VAR_0x8004, 16
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_22797D
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	call_if_ne SootopolisCity_MysteryEventsHouse_1F_EventScript_227991
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_22797D:: @ 822797D
	setvar VAR_TEMP_1, 1
	setobjectxyperm 1, 3, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227991:: @ 8227991
	setobjectxyperm 1, 2, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_MapScript2_22799D: @ 822799D
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_2279B7
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_2279B7
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_2279B7
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_2279B7:: @ 82279B7
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_227A1F
	waitmovement 0
	applymovement 1, SootopolisCity_MysteryEventsHouse_1F_Movement_227A21
	waitmovement 0
	moveobjectoffscreen 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227A04
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227A0D
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227A16
	special LoadPlayerParty
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	releaseall
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A04:: @ 8227A04
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227DB8, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A0D:: @ 8227A0D
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227E03, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A16:: @ 8227A16
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227D5B, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_227A1F: @ 8227A1F
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_227A21: @ 8227A21
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A24:: @ 8227A24
	lock
	faceplayer
	setvar VAR_0x8004, 16
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227A4E
	compare VAR_TEMP_1, 1
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227A58
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227B46, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A4E:: @ 8227A4E
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227B46, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227A58:: @ 8227A58
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227BFC, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227AE2
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_227AEF
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227AE2
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227CEB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227AE2
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227AE2
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227D21, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227AFE
	compare VAR_FACING, 4
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227B10
	compare VAR_FACING, 3
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_227B22
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 255, 3, 1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227AE2:: @ 8227AE2
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227C44, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_227AEF:: @ 8227AEF
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_227C84, MSGBOX_DEFAULT
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227AFE:: @ 8227AFE
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_227B40
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_227B34
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227B10:: @ 8227B10
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_227B43
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_227B38
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_227B22:: @ 8227B22
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_227B40
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_227B3C
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_227B34: @ 8227B34
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_227B38: @ 8227B38
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_227B3C: @ 8227B3C
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_227B40: @ 8227B40
	walk_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_227B43: @ 8227B43
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_227B46: @ 8227B46
	.string "When I was young, I traveled the world\n"
	.string "as a POKéMON TRAINER.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "TRAINERS battle.$"

SootopolisCity_MysteryEventsHouse_1F_Text_227BDD: @ 8227BDD
	.string "The door appears to be locked.$"

SootopolisCity_MysteryEventsHouse_1F_Text_227BFC: @ 8227BFC
	.string "A TRAINER named {STR_VAR_1}\n"
	.string "is visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

SootopolisCity_MysteryEventsHouse_1F_Text_227C44: @ 8227C44
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

SootopolisCity_MysteryEventsHouse_1F_Text_227C84: @ 8227C84
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

SootopolisCity_MysteryEventsHouse_1F_Text_227CEB: @ 8227CEB
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

SootopolisCity_MysteryEventsHouse_1F_Text_227D21: @ 8227D21
	.string "I hope to see a good match!$"

SootopolisCity_MysteryEventsHouse_1F_Text_227D3D: @ 8227D3D
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_227D40: @ 8227D40
	.string "The match ended up a draw.$"

SootopolisCity_MysteryEventsHouse_1F_Text_227D5B: @ 8227D5B
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

SootopolisCity_MysteryEventsHouse_1F_Text_227DB5: @ 8227DB5
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_227DB8: @ 8227DB8
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

SootopolisCity_MysteryEventsHouse_1F_Text_227E00: @ 8227E00
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_227E03: @ 8227E03
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"


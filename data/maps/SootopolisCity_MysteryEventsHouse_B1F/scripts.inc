SootopolisCity_MysteryEventsHouse_B1F_MapScripts:: @ 8227E4F
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_B1F_OnTransition: @ 8227E5A
	special SetEReaderTrainerGfxId
	end

SootopolisCity_MysteryEventsHouse_B1F_OnFrame: @ 8227E5E
	map_script_2 VAR_TEMP_1, 0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer
	.2byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer:: @ 8227E68
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement
	waitmovement 0
	special CopyEReaderTrainerGreeting
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost
	closemessage
	special HealPlayerParty
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 255, 3, 1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie:: @ 8227ECF
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon:: @ 8227EDD
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost:: @ 8227EE8
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement: @ 8227EF3
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement: @ 8227EF9
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end


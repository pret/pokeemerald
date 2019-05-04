SootopolisCity_MysteryEventsHouse_B1F_MapScripts:: @ 8227E4F
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_MapScript2_227E5E
	.byte 0

SootopolisCity_MysteryEventsHouse_B1F_OnTransition: @ 8227E5A
	special SetEReaderTrainerGfxId
	end

SootopolisCity_MysteryEventsHouse_B1F_MapScript2_227E5E: @ 8227E5E
	map_script_2 VAR_TEMP_1, 0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_227E68
	.2byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_227E68:: @ 8227E68
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_227EF3
	waitmovement 0
	special CopyEReaderTrainerGreeting
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	compare VAR_RESULT, 3
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_227ECF
	compare VAR_RESULT, 1
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_227EDD
	compare VAR_RESULT, 2
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_227EE8
	closemessage
	special HealPlayerParty
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_227EF9
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 255, 3, 1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_227ECF:: @ 8227ECF
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_227D40, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_227EDD:: @ 8227EDD
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_227EE8:: @ 8227EE8
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_Movement_227EF3: @ 8227EF3
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_227EF9: @ 8227EF9
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end


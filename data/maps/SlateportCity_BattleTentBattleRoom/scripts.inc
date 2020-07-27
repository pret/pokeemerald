.set LOCALID_OPPONENT, 2
.set LOCALID_PLAYER, 3

SlateportCity_BattleTentBattleRoom_MapScripts:: @ 8209960
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_BattleTentBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentBattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentBattleRoom_OnFrame
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1

SlateportCity_BattleTentBattleRoom_OnTransition: @ 8209970
	call SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx
	end

SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx:: @ 8209976
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
	return

SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale:: @ 820998E
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale:: @ 8209994
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SlateportCity_BattleTentBattleRoom_OnWarp: @ 820999A
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects:: @ 82099A4
	setvar VAR_TEMP_1, 1
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
	hideobjectat LOCALID_OPPONENT, MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
	end

SlateportCity_BattleTentBattleRoom_OnFrame: @ 82099B4
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom
	.2byte 0

SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom:: @ 82099BE
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter
	waitmovement 0
	factory_setopponentgfx
	setobjectxyperm LOCALID_OPPONENT, 5, 1
	removeobject LOCALID_OPPONENT
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter
	waitmovement 0
	battletent_getopponentintro
	lockall
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent
SlateportCity_BattleTent_EventScript_WarpToLobbyLost:: @ 8209A1B
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	special LoadPlayerParty
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 255, 6, 6
	waitstate
@ forced stop

SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent:: @ 8209A39
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 3, SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon
	setvar VAR_0x8006, 1
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 255, 2, 3
	waitstate
@ forced stop

SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon:: @ 8209A7B
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	special LoadPlayerParty
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 255, 6, 6
	waitstate
@ forced stop

SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter: @ 8209A99
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter: @ 8209A9E
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end


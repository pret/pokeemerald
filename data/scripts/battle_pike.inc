BattleFrontier_BattlePikeRoomNormal_MapScripts_2C3E1B: @ 82C3E1B
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp

BattleFrontier_BattlePikeRoom_OnTransition: @ 82C3E25
	battlepike_setroomobjects
	battlepike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EB1
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EB1
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EC0
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EA2
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EB1
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3E93
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EA2
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_2C3ECF
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3E93:: @ 82C3E93
	setobjectxyperm 1, 2, 5
	setobjectxyperm 2, 6, 5
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EA2:: @ 82C3EA2
	setobjectxyperm 1, 4, 4
	setobjectxyperm 2, 3, 4
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EB1:: @ 82C3EB1
	setobjectxyperm 1, 4, 4
	setobjectxyperm 2, 0, 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3EC0:: @ 82C3EC0
	setobjectxyperm 1, 5, 5
	setobjectxyperm 2, 0, 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3ECF:: @ 82C3ECF
	setobjectxyperm 1, 4, 3
	setobjectxyperm 2, 4, 4
	end

BattleFrontier_BattlePikeRoom_OnWarp: @ 82C3EDE
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom:: @ 82C3EE8
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_LINK_RECEPTIONIST
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_LINK_RECEPTIONIST
	battlepike_getroomtype
	compare VAR_RESULT, PIKE_ROOM_STATUS
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F35
	compare VAR_RESULT, PIKE_ROOM_HARD_BATTLE
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F35
	compare VAR_RESULT, PIKE_ROOM_DOUBLE_BATTLE
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F35
	compare VAR_RESULT, PIKE_ROOM_BRAIN
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F3F
	hideobjectat 2, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F35:: @ 82C3F35
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C3F3F:: @ 82C3F3F
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	hideobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_LeftRoomWarp:: @ 82C3F4E
	setvar VAR_0x8007, PIKE_ROOM_LEFT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_CenterRoomWarp:: @ 82C3F59
	setvar VAR_0x8007, PIKE_ROOM_CENTER
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_RightRoomWarp:: @ 82C3F64
	setvar VAR_0x8007, PIKE_ROOM_RIGHT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp:: @ 82C3F6F
	battlepike_getstreak
	addvar VAR_RESULT, 1
	battlepike_setstreak VAR_RESULT
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	battlepike_setnextroom
	battlepike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_WILD_MONS, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpWildMonRoom
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom:: @ 82C4030
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
	waitmovement 0
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL, 255, 4, 7
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpWildMonRoom:: @ 82C4049
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
	waitmovement 0
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS, 255, 4, 19
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062:: @ 82C4062
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_2, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D:: @ 82C406D
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_2, 0
	lockall
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C4082:: @ 82C4082
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_2, 1
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_2C408D:: @ 82C408D
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_2, 0
	lockall
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_Exit:: @ 82C40A2
	battlepike_ispartyfullhealth
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_DisableHealing
	compare VAR_RESULT, TRUE
	call_if_ne BattleFrontier_BattlePikeRoom_EventScript_EnableHealing
	battlepike_getstreak
	addvar VAR_RESULT, 1
	battlepike_setstreak VAR_RESULT
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	battlepike_isfinalroom
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	compare VAR_RESULT, FALSE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom
	waitstate
	end

BattleFrontier_BattlePikeRoom_EventScript_DisableHealing:: @ 82C4128
	battlepike_nohealing TRUE
	return

BattleFrontier_BattlePikeRoom_EventScript_EnableHealing:: @ 82C4136
	battlepike_nohealing FALSE
	return

BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom:: @ 82C4144
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
	waitmovement 0
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL, 255, 2, 7
	return

BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom:: @ 82C415C
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
	waitmovement 0
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
	return

BattleFrontier_BattlePikeRoomWildMons_EventScript_2C4174:: @ 82C4174
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_7
	special CallBattlePikeFunction
	battlepike_ispartyfullhealth
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_DisableHealing
	compare VAR_RESULT, TRUE
	call_if_ne BattleFrontier_BattlePikeRoom_EventScript_EnableHealing
	battlepike_getstreak
	addvar VAR_RESULT, 1
	battlepike_setstreak VAR_RESULT
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	battlepike_isfinalroom
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	compare VAR_RESULT, FALSE
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomWildMons_EventScript_2C4202:: @ 82C4202
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_2, 1
	end

BattleFrontier_BattlePikeRoomWildMons_EventScript_2C420D:: @ 82C420D
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_2, 0
	lockall
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePike_EventScript_Retire:: @ 82C4222
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoom_OnResume: @ 82C423E
	setorcopyvar VAR_0x8006, VAR_RESULT
	frontier_get FRONTIER_DATA_CHALLENGE_STATUS
	compare VAR_RESULT, CHALLENGE_STATUS_PAUSED
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B
	compare VAR_RESULT, CHALLENGE_STATUS_SAVING
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B
	call BattleFrontier_BattlePikeRoom_EventScript_ResetSketchedMoves
BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B:: @ 82C426B
	setorcopyvar VAR_RESULT, VAR_0x8006
	end

BattleFrontier_BattlePikeRoom_EventScript_ResetSketchedMoves:: @ 82C4271
	frontier_resetsketch
	return

BattleFrontier_BattlePikeRoom_Movement_HidePlayer: @ 82C427A
	set_invisible
	step_end

BattleFrontier_BattlePikeRandomRoom3_MapScripts:: @ 825E41A
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRandomRoom3_MapScript1_25E47A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRandomRoom3_MapScript2_25E42A
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRandomRoom3_MapScript2_25E466
	.byte 0

BattleFrontier_BattlePikeRandomRoom3_MapScript2_25E42A: @ 825E42A
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRandomRoom3_EventScript_25E43C
	map_script_2 VAR_TEMP_1, 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_25E44A
	.2byte 0

BattleFrontier_BattlePikeRandomRoom3_EventScript_25E43C:: @ 825E43C
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, 6
	special CallBattlePikeFunction
	end

BattleFrontier_BattlePikeRandomRoom3_EventScript_25E44A:: @ 825E44A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom3_MapScript2_25E466: @ 825E466
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRandomRoom3_EventScript_25E470
	.2byte 0

BattleFrontier_BattlePikeRandomRoom3_EventScript_25E470:: @ 825E470
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

BattleFrontier_BattlePikeRandomRoom3_MapScript1_25E47A: @ 825E47A
	call BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4271
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special CallFrontierUtilFunc
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePikeRandomRoom3_EventScript_25E4A3
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattlePikeRandomRoom3_EventScript_25E4A3
	end

BattleFrontier_BattlePikeRandomRoom3_EventScript_25E4A3:: @ 825E4A3
	setvar VAR_TEMP_1, 1
	end


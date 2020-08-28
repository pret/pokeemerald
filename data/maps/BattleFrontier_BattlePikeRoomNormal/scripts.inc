@ Objects in this room are set dynamically with OBJ_EVENT_GFX_VAR_0 and OBJ_EVENT_GFX_VAR_1
@ Note: LOCALIDs shared with data/scripts/battle_pike.inc
.equ LOCALID_OBJ_0, 1
.equ LOCALID_OBJ_1, 2

BattleFrontier_BattlePikeRoomNormal_MapScripts:: @ 825D152
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame: @ 825D167
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom:: @ 825D171
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom:: @ 825D1C6
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost:: @ 825D20A
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle:: @ 825D226
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom:: @ 825D231
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle:: @ 825D285
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
	waitmovement 0
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom:: @ 825D2BF
	delay 22
	lockall
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
	waitmovement 0
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter:: @ 825D2FB
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	showobjectat LOCALID_OBJ_0, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
	waitse
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
	waitmovement 0
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver:: @ 825D3BD
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver:: @ 825D3DA
	frontier_getsymbols
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold:: @ 825D416
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold:: @ 825D443
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold:: @ 825D460
	frontier_getsymbols
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy:: @ 825D49D
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal:: @ 825D4DC
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon:: @ 825D4EA
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons:: @ 825D4FC
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom:: @ 825D50E
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom:: @ 825D53E
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle:: @ 825D5DC
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom:: @ 825D605
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
	waitmovement 0
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_0x8004, PIKE_STATUSMON_KIRLIA
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
	compare VAR_0x8004, PIKE_STATUSMON_DUSCLOPS
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack:: @ 825D643
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	pike_getstatus
	compare VAR_RESULT, PIKE_STATUS_TOXIC
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
	compare VAR_RESULT, PIKE_STATUS_BURN
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
	compare VAR_RESULT, PIKE_STATUS_PARALYSIS
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
	compare VAR_RESULT, PIKE_STATUS_SLEEP
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
	pike_flashscreen
	waitstate
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	closemessage
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack:: @ 825D6D5
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, 0
	waitmoncry
	pike_getstatus
	compare VAR_RESULT, PIKE_STATUS_FREEZE
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
	compare VAR_RESULT, PIKE_STATUS_BURN
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
	pike_flashscreen
	waitstate
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_DUSCLOPS, 0
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, 0
	waitmoncry
	closemessage
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic:: @ 825D751
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp:: @ 825D758
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave:: @ 825D75F
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis:: @ 825D766
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam:: @ 825D76D
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp:: @ 825D774
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle:: @ 825D77B
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer: @ 825D795
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit: @ 825D798
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit: @ 825D79E
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon: @ 825D7A2
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer: @ 825D7A4
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer: @ 825D7AA
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC: @ 825D7B1
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside: @ 825D7B3
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight: @ 825D7B4
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer: @ 825D7B6
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1: @ 825D7BB
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2: @ 825D7BD
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp: @ 825D7BF
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight: @ 825D7C1
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft: @ 825D7C3
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown: @ 825D7C5
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer: @ 825D7C8
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer: @ 825D7CA
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit: @ 825D7CC
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit: @ 825D7D4
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2: @ 825D7DC
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer: @ 825D7DF
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy: @ 825D7E2
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter: @ 825D7E7
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside: @ 825D7EA
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC:: @ 825D7ED
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC:: @ 825D81B
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC:: @ 825D831
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC:: @ 825D83E
	pike_healonetwomons
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon:: @ 825D875
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons:: @ 825D881
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon:: @ 825D88D
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed:: @ 825D8A4
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, 1
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, 1
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, 1
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, 1
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, 1
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, 0
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, 1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed:: @ 825D8E7
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, 1
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, 1
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, 1
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, 1
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, 1
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, 0
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, 1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen:: @ 825D92A
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, 1
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, 1
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, 1
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, 1
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, 1
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, 0
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, 1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed:: @ 825D96D
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, 1
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, 1
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, 1
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, 1
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, 1
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, 0
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, 1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp: @ 825D9B0
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown: @ 825D9B3
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth: @ 825D9B6
	.string "Welcome…\n"
	.string "You must be commended for your luck…\p"
	.string "Your POKéMON shall be restored\n"
	.string "to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge: @ 825DA13
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon: @ 825DA51
	.string "Ah, you're a lucky one.\n"
	.string "I'm in somewhat-good spirits now.\p"
	.string "I will restore one of your POKéMON\n"
	.string "to full health.$"

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell: @ 825DABE
	.string "The best of luck to you.\n"
	.string "Farewell.$"

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons: @ 825DAE1
	.string "Excuse me…\p"
	.string "Would you care for a battle?\n"
	.string "I'll restore your POKéMON if you win.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe: @ 825DB2F
	.string "Very well…\n"
	.string "Now, shall we?$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou: @ 825DB49
	.string "I see…\n"
	.string "How unsporting of you…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised: @ 825DB67
	.string "Magnificent…\p"
	.string "As promised, I shall restore your\n"
	.string "POKéMON to full health.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2: @ 825DBAE
	.string "The best of luck to you.\n"
	.string "Farewell.$"

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut: @ 825DBD1
	.string "Oh, my!\p"
	.string "Watch out!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop: @ 825DBE4
	.string "Now, now!\n"
	.string "KIRLIA, stop that!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop: @ 825DC01
	.string "Now, now!\n"
	.string "DUSCLOPS, stop that!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic: @ 825DC20
	.string "KIRLIA used TOXIC!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis: @ 825DC33
	.string "KIRLIA used HYPNOSIS!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave: @ 825DC49
	.string "KIRLIA used THUNDER WAVE!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp: @ 825DC63
	.string "KIRLIA used WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp: @ 825DC7C
	.string "DUSCLOPS used WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam: @ 825DC97
	.string "DUSCLOPS used ICE BEAM!$"

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough: @ 825DCAF
	.string "Look here!\n"
	.string "That's quite enough!$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia: @ 825DCCF
	.string "I must apologize to you…\p"
	.string "My KIRLIA has a TIMID nature…$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops: @ 825DD06
	.string "I must apologize to you…\p"
	.string "My DUSCLOPS has a TIMID nature…$"

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled: @ 825DD3F
	.string "It attacks without warning if it is\n"
	.string "startled by another person…\p"
	.string "Are you and your POKéMON all right?$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine: @ 825DDA3
	.string "I do apologize for what happened…\n"
	.string "I do hope your POKéMON are fine.$"

BattleFrontier_BattlePikeRoomNormal_Text_Silence: @ 825DDE6
	.string "… … … … … …\n"
	.string "… … … … … …$"

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer: @ 825DDFE
	.string "Welcome…\p"
	.string "Here, we will have you battle\n"
	.string "a somewhat-tough TRAINER…$"

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth: @ 825DE3F
	.string "How wonderful…\p"
	.string "To honor your victory, your POKéMON\n"
	.string "shall be restored to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2: @ 825DE94
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen: @ 825DED2
	.string "I am LUCY…\n"
	.string "I am the law here…\l"
	.string "For I am the PIKE QUEEN…\p"
	.string "You already know it, but to advance,\n"
	.string "you must defeat me…\p"
	.string "…I'm not one for idle chatter.\n"
	.string "Hurry. Come on…$"

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck: @ 825DF71
	.string "Your luck…\n"
	.string "I hope you didn't use it all up here…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass: @ 825DFA2
	.string "LUCY: … … … … … …\n"
	.string "Show me your FRONTIER PASS…$"

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol: @ 825DFD0
	.string "The Luck Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear: @ 825E003
	.string "…That's all there is…\n"
	.string "Disappear already…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain: @ 825E02C
	.string "LUCY: …You again…\p"
	.string "… … … … … …\p"
	.string "…I've trampled flowers and braved\n"
	.string "storms to get to where I am…\p"
	.string "I don't feel any compulsion to keep\n"
	.string "losing to the same opponent…\p"
	.string "… … … … … …\n"
	.string "Fine… I'll do it…$"

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn: @ 825E0E8
	.string "Now!\n"
	.string "Come on!$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass: @ 825E0F6
	.string "LUCY: … … … … … …\p"
	.string "…FRONTIER PASS…$"

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine: @ 825E118
	.string "The Luck Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget: @ 825E140
	.string "…You, I won't forget…\n"
	.string "…Ever…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal: @ 825E15D
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You seem to be bereft of luck…\p"
	.string "If only you hadn't chosen this room,\n"
	.string "your POKéMON could have been healed…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne: @ 825E1DD
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore one POKéMON to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo: @ 825E238
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore two POKéMON to full health…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons: @ 825E293
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You should thank your lucky stars…\p"
	.string "Since you have chosen this room,\n"
	.string "all your POKéMON will be restored…$"

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster: @ 825E311
	.string "I shall go fetch our master…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons: @ 825E32E
	.string "Ah, you're a lucky one!\n"
	.string "I'm in good spirits now.\p"
	.string "I will restore two of your POKéMON\n"
	.string "to full health!$"


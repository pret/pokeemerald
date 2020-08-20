.set LOCALID_PLAYER, 1
.set LOCALID_OPPONENT, 2
.set LOCALID_ATTENDANT, 3
.set LOCALID_DUSCLOPS, 4
.set LOCALID_AZURILL, 5

BattleFrontier_BattlePalaceBattleRoom_MapScripts:: @ 824F815
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
	@ The opponent is represented by LOCALID_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1

BattleFrontier_BattlePalaceBattleRoom_OnTransition: @ 824F825
	frontier_settrainers
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx:: @ 824F833
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
	return

@ The opponent's gfx are set to the players by default
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale:: @ 824F84B
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale:: @ 824F856
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_OnFrame: @ 824F861
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom:: @ 824F86B
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge:: @ 824F8B5
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter:: @ 824F8BF
	tower_setopponent
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
	waitmovement 0
	palace_getopponentintro
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost:: @ 824F8FA
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent:: @ 824F911
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
	waitmovement 0
	removeobject LOCALID_OPPONENT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent:: @ 824F98A
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
	compare VAR_RESULT, 4
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
	compare VAR_RESULT, 5
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
	compare VAR_RESULT, 6
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord:: @ 824FA42
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle:: @ 824FA78
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle:: @ 824FAAA
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge:: @ 824FAB4
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge:: @ 824FAE2
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge:: @ 824FB14
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon:: @ 824FB28
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge:: @ 824FB3F
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
	waitmessage
	palace_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext:: @ 824FB61
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven:: @ 824FB79
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord:: @ 824FBD0
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser:: @ 824FC06
	call BattleFrontier_EventScript_SetBrainObjectGfx
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	setobjectxyperm LOCALID_OPPONENT, 15, 1
	addobject LOCALID_OPPONENT
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setobjectxy LOCALID_OPPONENT, 13, 1
	setobjectxyperm LOCALID_OPPONENT, 13, 1
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver:: @ 824FCAA
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver:: @ 824FCC7
	palace_incrementstreak
	frontier_getsymbols
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold:: @ 824FD3A
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold:: @ 824FD67
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold:: @ 824FD84
	palace_incrementstreak
	frontier_getsymbols
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle:: @ 824FDF7
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
	return

BattleFrontier_BattlePalaceBattleRoom_OnWarp: @ 824FE34
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects:: @ 824FE3E
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	removeobject LOCALID_OPPONENT
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 824FE66
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 824FE6D
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent:: @ 824FE74
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent:: @ 824FE7B
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent:: @ 824FE82
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent:: @ 824FE89
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible: @ 824FE90
	set_invisible
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom: @ 824FE92
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight: @ 824FE97
	face_right
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp: @ 824FE99
	face_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge: @ 824FE9B
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter: @ 824FEA1
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit: @ 824FEA7
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown: @ 824FEAC
	face_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1: @ 824FEAE
	set_visible
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2: @ 824FEB3
	set_visible
	walk_slow_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3: @ 824FEB6
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby:: @ 824FEBB
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 5, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles:: @ 824FED5
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 19, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter: @ 824FEDF
	delay_16
	delay_16
	set_visible
	walk_down
	walk_right
	walk_down
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter: @ 824FEE7
	set_visible
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_fastest_left
	delay_16
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter: @ 824FEF2
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	set_visible
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons: @ 824FF00
	.string "Excellent…\n"
	.string "Let me restore your POKéMON.$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent: @ 824FF28
	.string "The 2nd opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent: @ 824FF54
	.string "The 3rd opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent: @ 824FF80
	.string "The 4th opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent: @ 824FFAC
	.string "The 5th opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent: @ 824FFD8
	.string "The 6th opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent: @ 8250004
	.string "The 7th opponent is next.\n"
	.string "Are you prepared?$"

BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame: @ 8250030
	.string "Would you like to save and quit\n"
	.string "the game?$"

BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge: @ 825005A
	.string "Do you wish to quit your challenge?$"

BattleFrontier_BattlePalaceBattleRoom_Text_SavingData: @ 825007E
	.string "Saving the data.\n"
	.string "Have patience…$"

BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch: @ 825009E
	.string "Do you wish to record your latest\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven: @ 82500DD
	.string "And now…\p"
	.string "By winning consistently, you have\n"
	.string "earned the privilege of challenging\l"
	.string "our master, the PALACE MAVEN…$"

BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven: @ 825014A
	.string "I shall send for the PALACE MAVEN.\n"
	.string "Are you ready?$"

BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser: @ 825017C
	.string "Let great fanfare announce the arrival\n"
	.string "of the PALACE MAVEN, SPENSER!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro: @ 82501C1
	.string "SPENSER: My physical being is with\n"
	.string "POKéMON always!\p"
	.string "My heart beats as one with\n"
	.string "POKéMON always!\p"
	.string "Young one of a TRAINER!\n"
	.string "Do you believe in your POKéMON?\p"
	.string "Can you believe them through\n"
	.string "and through?\p"
	.string "If your bonds of trust are frail,\n"
	.string "you will never beat my brethren!$"

BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons: @ 82502C4
	.string "The bond you share with your POKéMON!\n"
	.string "Prove it to me here!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle: @ 82502FF
	.string "SPENSER: Gwahahah!\p"
	.string "Hah, you never fell for my bluster!\n"
	.string "Sorry for trying that stunt!\p"
	.string "Here!\n"
	.string "Bring me the thing!$"

BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass: @ 825036D
	.string "My, my, if only you could maintain that\n"
	.string "facade of distinguished authority…\p"
	.string "Here!\n"
	.string "Let's see your FRONTIER PASS!$"

BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol: @ 82503DC
	.string "The Spirits Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime: @ 8250412
	.string "SPENSER: Your POKéMON's eyes are \n"
	.string "truly clear and unclouded.\p"
	.string "I will eagerly await the next\n"
	.string "opportunity to see you.$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack: @ 8250485
	.string "SPENSER: Gwahahah!\n"
	.string "You've battled your way up again?\p"
	.string "You must have developed a truly\n"
	.string "formidable bond with your POKéMON.\p"
	.string "So be it!\p"
	.string "This time, I won't bluster or hold back.\n"
	.string "This time, there's no fooling around.\p"
	.string "Ready now?\n"
	.string "Prepare to lose!$"

BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah: @ 8250572
	.string "… … …Kaaah!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable: @ 825057E
	.string "SPENSER: Well, that was some display!\n"
	.string "Even fully unleashed, my brethren\l"
	.string "could not overpower you.\p"
	.string "Your team spirit is truly admirable!\p"
	.string "Here!\n"
	.string "Bring me that thing, will you?$"

BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass: @ 8250629
	.string "My, my, if only you could maintain\n"
	.string "a certain level of decorum…\p"
	.string "Gaaah, here!\n"
	.string "Hurry with that FRONTIER PASS, you!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine: @ 8250699
	.string "The Spirits Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain: @ 82506C4
	.string "SPENSER: Gwahahah!\p"
	.string "Come see me time and again!\n"
	.string "My brethren and I will be waiting!$"

.set LOCALID_PLAYER, 1
.set LOCALID_OPPONENT, 2
.set LOCALID_ATTENDANT, 3
.set LOCALID_DUSCLOPS, 4
.set LOCALID_AZURILL, 5

BattleFrontier_BattlePalaceBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
	@ The opponent is represented by LOCALID_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1

BattleFrontier_BattlePalaceBattleRoom_OnTransition:
	frontier_settrainers
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
	return

@ The opponent's gfx are set to the players by default
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom::
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter::
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
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent::
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
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
	waitmessage
	palace_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven::
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser::
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
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver::
	palace_incrementstreak
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
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
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold::
	palace_incrementstreak
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
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
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle::
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

BattleFrontier_BattlePalaceBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	removeobject LOCALID_OPPONENT
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
	face_right
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
	face_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
	face_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
	set_visible
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
	set_visible
	walk_slow_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
	delay_16
	delay_16
	set_visible
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
	set_visible
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_faster_left
	delay_16
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
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

BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
	.string "Excellent…\n"
	.string "Je vais soigner vos POKéMON.$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
	.string "Le deuxième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
	.string "Le troisième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
	.string "Le quatrième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
	.string "Le cinquième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
	.string "Le sixième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
	.string "Le septième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
	.string "Voulez-vous sauvegarder la partie et\n"
	.string "arrêter de jouer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
	.string "Voulez-vous abandonner votre défi?$"

BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
	.string "Sauvegarde en cours…\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
	.string "Voulez-vous enregistrer votre dernier\n"
	.string "combat sur votre PASSE ZONE?$"

BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
	.string "Et maintenant…\p"
	.string "Vos victoires vous donnent le droit\n"
	.string "d’affronter le CAPT. PALACE…$"

BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
	.string "Le CAPT. PALACE est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
	.string "Veuillez accueillir comme il se doit\n"
	.string "le CAPT. PALACE, ESTEBAN!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
	.string "ESTEBAN: Je ne fais qu’un avec mes\n"
	.string "POKéMON!\p"
	.string "Mon cœur et celui de mes POKéMON\n"
	.string "battent à l’unisson!\p"
	.string "Dis-moi, DRESSEUR en herbe!\n"
	.string "Crois-tu en tes POKéMON?\p"
	.string "Est-ce que tu crois en eux, quoi\n"
	.string "qu’il arrive?\p"
	.string "La confiance qui te lie à tes POKéMON\n"
	.string "devra être à toute épreuve!$"

BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
	.string "Montre-moi les liens qui t’unissent à\n"
	.string "tes POKéMON!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
	.string "ESTEBAN: Ahhhhh!\p"
	.string "Je me suis un peu trop vanté!\n"
	.string "Désolé pour ce petit numéro!\p"
	.string "Allez…\n"
	.string "Donne-moi ce que tu sais!$"

BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
	.string "Un bon DRESSEUR ne doit jamais perdre\n"
	.string "la face…\p"
	.string "Allez, ton PASSE ZONE!\n"
	.string "Et que ça saute!$"

BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
	.string "Le SYMBOLE ESPRIT a été ajouté sur le\n"
	.string "PASSE ZONE!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
	.string "ESTEBAN: Tu lis dans tes POKéMON comme\n"
	.string "dans un livre ouvert.\p"
	.string "J’attendrai avec impatience l’instant\n"
	.string "où nous nous reverrons.$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
	.string "ESTEBAN: Ahhhhh!!!\n"
	.string "Te voilà?\p"
	.string "Tu as dû développer un lien\n"
	.string "unique avec tes POKéMON.\p"
	.string "Battons-nous!\p"
	.string "Cette fois, je ne vais pas faire le\n"
	.string "malin! Cette fois, je vais gagner!\p"
	.string "On peut commencer?\n"
	.string "Prépare-toi à perdre!$"

BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
	.string "… … …\n"
	.string "Ahhhhh!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
	.string "ESTEBAN: Ce fut une belle\n"
	.string "démonstration! Mes POKéMON, même\l"
	.string "déchaînés, n’ont pas battu les tiens.\p"
	.string "Votre esprit d’équipe est remarquable!\p"
	.string "Allez…\n"
	.string "Tu me donnes ce que tu sais?$"

BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
	.string "Un bon DRESSEUR se doit d’être\n"
	.string "respectueux…\p"
	.string "Allez, grouille-toi!\n"
	.string "Sors-moi ton PASSE ZONE!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
	.string "Le SYMBOLE ESPRIT a pris une couleur\n"
	.string "dorée!$"

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
	.string "ESTEBAN: Ah, ah!\p"
	.string "Reviens me voir quand tu veux!\n"
	.string "Nous t’attendrons de pied ferme!$"

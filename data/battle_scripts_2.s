#include "config/battle.h"
#include "constants/battle.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattlescriptsForUsingItem::
	.4byte BattleScript_ItemRestoreHP                @ EFFECT_ITEM_RESTORE_HP
	.4byte BattleScript_ItemCureStatus               @ EFFECT_ITEM_CURE_STATUS
	.4byte BattleScript_ItemHealAndCureStatus        @ EFFECT_ITEM_HEAL_AND_CURE_STATUS
	.4byte BattleScript_ItemIncreaseStat             @ EFFECT_ITEM_INCREASE_STAT
	.4byte BattleScript_ItemSetMist                  @ EFFECT_ITEM_SET_MIST
	.4byte BattleScript_ItemSetFocusEnergy           @ EFFECT_ITEM_SET_FOCUS_ENERGY
	.4byte BattleScript_RunByUsingItem               @ EFFECT_ITEM_ESCAPE
	.4byte BattleScript_BallThrow                    @ EFFECT_ITEM_THROW_BALL
	.4byte BattleScript_ItemRestoreHP                @ EFFECT_ITEM_REVIVE
	.4byte BattleScript_ItemRestorePP                @ EFFECT_ITEM_RESTORE_PP
	.4byte BattleScript_ItemIncreaseAllStats         @ EFFECT_ITEM_INCREASE_ALL_STATS

	.align 2
gBattlescriptsForSafariActions::
	.4byte BattleScript_ActionWatchesCarefully
	.4byte BattleScript_ActionGetNear
	.4byte BattleScript_ActionThrowPokeblock
	.4byte BattleScript_ActionWallyThrow

BattleScript_ItemEnd:
	end

BattleScript_UseItemMessage:
	printstring STRINGID_EMPTYSTRING3
	pause B_WAIT_TIME_MED
	playse SE_USE_ITEM
	getbattlerside BS_ATTACKER
	copybyte cMULTISTRING_CHOOSER, gBattleCommunication
	printfromtable gTrainerUsedItemStringIds
	waitmessage B_WAIT_TIME_LONG
	return
	
BattleScript_ItemRestoreHPRet:
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printstring STRINGID_ITEMRESTOREDSPECIESHEALTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemRestoreHP::
	call BattleScript_UseItemMessage
	itemrestorehp BattleScript_ItemRestoreHPEnd, BattleScript_ItemRestoreHP_Battler
	call BattleScript_ItemRestoreHP_Party
	goto BattleScript_ItemRestoreHPEnd

BattleScript_ItemRestoreHP_Battler::
	call BattleScript_ItemRestoreHPRet
BattleScript_ItemRestoreHPEnd:
	end

BattleScript_ItemRestoreHP_Party::
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_ItemRestoreHP_SendOutRevivedBattler
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	printstring STRINGID_ITEMRESTOREDSPECIESHEALTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemRestoreHP_SendOutRevivedBattler:
	switchinanim BS_SCRIPTING, FALSE
	waitstate
	switchineffects BS_SCRIPTING
	end

BattleScript_ItemCureStatus::
	call BattleScript_UseItemMessage
BattleScript_ItemCureStatusAfterItemMsg:
	itemcurestatus BattleScript_ItemCureStatusEnd
	updatestatusicon BS_SCRIPTING
	printstring STRINGID_ITEMCUREDSPECIESSTATUS
	waitmessage B_WAIT_TIME_LONG
BattleScript_ItemCureStatusEnd:
	end

BattleScript_ItemHealAndCureStatus::
	call BattleScript_UseItemMessage
	itemrestorehp BattleScript_ItemCureStatusAfterItemMsg, BattleScript_ItemHealAndCureStatus_Battler
	call BattleScript_ItemRestoreHP_Party
	goto BattleScript_ItemHealAndCureStatusEnd

BattleScript_ItemHealAndCureStatus_Battler::
	call BattleScript_ItemRestoreHPRet
BattleScript_ItemHealAndCureStatusEnd::
	goto BattleScript_ItemCureStatusAfterItemMsg

BattleScript_ItemIncreaseStat::
	call BattleScript_UseItemMessage
	itemincreasestat
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_ItemEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ItemSetMist::
	call BattleScript_UseItemMessage
	setmist
	playmoveanimation BS_ATTACKER, MOVE_MIST
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ItemSetFocusEnergy::
	call BattleScript_UseItemMessage
	jumpifstatus2 BS_ATTACKER, STATUS2_FOCUS_ENERGY_ANY, BattleScript_ButItFailed
	setfocusenergy BS_ATTACKER
	playmoveanimation BS_ATTACKER, MOVE_FOCUS_ENERGY
	waitanimation
	copybyte sBATTLER, gBattlerAttacker
	printstring STRINGID_PKMNUSEDXTOGETPUMPED
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ItemRestorePP::
	call BattleScript_UseItemMessage
	itemrestorepp
	printstring STRINGID_ITEMRESTOREDSPECIESPP
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ItemIncreaseAllStats::
	call BattleScript_UseItemMessage
	call BattleScript_AllStatsUp
	end

BattleScript_BallThrow::
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_WALLY_TUTORIAL, BattleScript_BallThrowByWally
	printstring STRINGID_PLAYERUSEDITEM
	handleballthrow

BattleScript_BallThrowByWally::
	printstring STRINGID_WALLYUSEDITEM
	handleballthrow

BattleScript_SafariBallThrow::
	printstring STRINGID_PLAYERUSEDITEM
	updatestatusicon BS_ATTACKER
	handleballthrow

BattleScript_SuccessBallThrow::
	setbyte sMON_CAUGHT, TRUE
	incrementgamestat GAME_STAT_POKEMON_CAPTURES
	printstring STRINGID_GOTCHAPKMNCAUGHTPLAYER
	jumpifbyte CMP_NOT_EQUAL, sEXP_CATCH, TRUE, BattleScript_TryPrintCaughtMonInfo
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	sethword gBattle_BG2_X, 0
BattleScript_TryPrintCaughtMonInfo:
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_GiveCaughtMonEnd
	trysetcaughtmondexflags BattleScript_TryNicknameCaughtMon
	printstring STRINGID_PKMNDATAADDEDTODEX
	waitstate
	setbyte gBattleCommunication, 0
	displaydexinfo
BattleScript_TryNicknameCaughtMon::
	printstring STRINGID_GIVENICKNAMECAPTURED
	waitstate
	setbyte gBattleCommunication, 0
	trygivecaughtmonnick BattleScript_GiveCaughtMonEnd
	givecaughtmon
	printfromtable gCaughtMonStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SuccessBallThrowEnd
BattleScript_GiveCaughtMonEnd::
	givecaughtmon
BattleScript_SuccessBallThrowEnd::
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_WallyBallThrow::
	printstring STRINGID_GOTCHAPKMNCAUGHTWALLY
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	printfromtable gBallEscapeStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_SAFARI, BattleScript_ShakeBallThrowEnd
	jumpifbyte CMP_NOT_EQUAL, gNumSafariBalls, 0, BattleScript_ShakeBallThrowEnd
	printstring STRINGID_OUTOFSAFARIBALLS
	waitmessage B_WAIT_TIME_LONG
	setbyte gBattleOutcome, B_OUTCOME_NO_SAFARI_BALLS
BattleScript_ShakeBallThrowEnd::
	finishaction

BattleScript_TrainerBallBlock::
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_TRAINERBLOCKEDBALL
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_DONTBEATHIEF
	waitmessage B_WAIT_TIME_LONG
	finishaction

BattleScript_RunByUsingItem::
	playse SE_FLEE
	setbyte gBattleOutcome, B_OUTCOME_RAN
	finishturn

BattleScript_ActionWatchesCarefully:
	printstring STRINGID_PKMNWATCHINGCAREFULLY
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ActionGetNear:
	printfromtable gSafariGetNearStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ActionThrowPokeblock:
	printstring STRINGID_THREWPOKEBLOCKATPKMN
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_POKEBLOCK_THROW, NULL
	printfromtable gSafariPokeblockResultStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ActionWallyThrow:
	printstring STRINGID_RETURNMON
	waitmessage B_WAIT_TIME_LONG
	returnatktoball
	waitstate
	trainerslidein BS_TARGET
	waitstate
	printstring STRINGID_YOUTHROWABALLNOWRIGHT
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TrainerASlideMsgRet::
	handletrainerslidemsg BS_SCRIPTING, 0
	trainerslidein B_POSITION_OPPONENT_LEFT
	handletrainerslidemsg BS_SCRIPTING, 1
	waitstate
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	handletrainerslidemsg BS_SCRIPTING, 2
	return

BattleScript_TrainerASlideMsgEnd2::
	call BattleScript_TrainerASlideMsgRet
	end2

BattleScript_TrainerBSlideMsgRet::
	handletrainerslidemsg BS_SCRIPTING, 0
	trainerslidein B_POSITION_OPPONENT_RIGHT
	handletrainerslidemsg BS_SCRIPTING, 1
	waitstate
	trainerslideout B_POSITION_OPPONENT_RIGHT
	waitstate
	handletrainerslidemsg BS_SCRIPTING, 2
	return

BattleScript_TrainerBSlideMsgEnd2::
	call BattleScript_TrainerBSlideMsgRet
	end2

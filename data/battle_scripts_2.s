#include "constants/battle.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_config.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattlescriptsForBallThrow:: @ 82DBD08
	.4byte BattleScript_BallThrow        @ ITEM_NONE
	.4byte BattleScript_BallThrow        @ ITEM_MASTER_BALL
	.4byte BattleScript_BallThrow        @ ITEM_ULTRA_BALL
	.4byte BattleScript_BallThrow        @ ITEM_GREAT_BALL
	.4byte BattleScript_BallThrow        @ ITEM_POKE_BALL
	.4byte BattleScript_SafariBallThrow  @ ITEM_SAFARI_BALL
	.4byte BattleScript_BallThrow        @ ITEM_NET_BALL
	.4byte BattleScript_BallThrow        @ ITEM_DIVE_BALL
	.4byte BattleScript_BallThrow        @ ITEM_NEST_BALL
	.4byte BattleScript_BallThrow        @ ITEM_REPEAT_BALL
	.4byte BattleScript_BallThrow        @ ITEM_TIMER_BALL
	.4byte BattleScript_BallThrow        @ ITEM_LUXURY_BALL
	.4byte BattleScript_BallThrow        @ ITEM_PREMIER_BALL

	.align 2
gBattlescriptsForUsingItem:: @ 82DBD3C
	.4byte BattleScript_PlayerUsesItem
	.4byte BattleScript_OpponentUsesHealItem        @ AI_ITEM_FULL_RESTORE
	.4byte BattleScript_OpponentUsesHealItem        @ AI_ITEM_HEAL_HP
	.4byte BattleScript_OpponentUsesStatusCureItem  @ AI_ITEM_CURE_CONDITION
	.4byte BattleScript_OpponentUsesXItem           @ AI_ITEM_X_STAT
	.4byte BattleScript_OpponentUsesGuardSpecs      @ AI_ITEM_GUARD_SPECS

	.align 2
gBattlescriptsForRunningByItem:: @ 82DBD54
	.4byte BattleScript_RunByUsingItem

	.align 2
gBattlescriptsForSafariActions:: @ 82DBD58
	.4byte BattleScript_ActionWatchesCarefully
	.4byte BattleScript_ActionGetNear
	.4byte BattleScript_ActionThrowPokeblock
	.4byte BattleScript_ActionWallyThrow

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
	jumpifhalfword CMP_EQUAL, gLastUsedItem, ITEM_SAFARI_BALL, BattleScript_PrintCaughtMonInfo
	incrementgamestat GAME_STAT_POKEMON_CAPTURES
BattleScript_PrintCaughtMonInfo::
	printstring STRINGID_GOTCHAPKMNCAUGHT
	jumpifbyte CMP_NOT_EQUAL, sEXP_CATCH, TRUE, BattleScript_TryPrintCaughtMonInfo
	setbyte sGIVEEXP_STATE, 0x0
	getexp BS_TARGET
	sethword gBattle_BG2_X, 0x0
BattleScript_TryPrintCaughtMonInfo:
	trysetcaughtmondexflags BattleScript_TryNicknameCaughtMon
	printstring STRINGID_PKMNDATAADDEDTODEX
	waitstate
	setbyte gBattleCommunication, 0x0
	displaydexinfo
BattleScript_TryNicknameCaughtMon::
	printstring STRINGID_GIVENICKNAMECAPTURED
	waitstate
	setbyte gBattleCommunication, 0x0
	trygivecaughtmonnick BattleScript_GiveCaughtMonEnd
	givecaughtmon
	printfromtable gCaughtMonStringIds
	waitmessage 0x40
	goto BattleScript_SuccessBallThrowEnd
BattleScript_GiveCaughtMonEnd::
	givecaughtmon
BattleScript_SuccessBallThrowEnd::
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_WallyBallThrow::
	printstring STRINGID_GOTCHAPKMNCAUGHT2
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	printfromtable gBallEscapeStringIds
	waitmessage 0x40
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_SAFARI, BattleScript_ShakeBallThrowEnd
	jumpifbyte CMP_NOT_EQUAL, gNumSafariBalls, 0x0, BattleScript_ShakeBallThrowEnd
	printstring STRINGID_OUTOFSAFARIBALLS
	waitmessage 0x40
	setbyte gBattleOutcome, B_OUTCOME_NO_SAFARI_BALLS
BattleScript_ShakeBallThrowEnd::
	finishaction

BattleScript_TrainerBallBlock::
	waitmessage 0x40
	printstring STRINGID_TRAINERBLOCKEDBALL
	waitmessage 0x40
	printstring STRINGID_DONTBEATHIEF
	waitmessage 0x40
	finishaction

BattleScript_PlayerUsesItem::
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	end

BattleScript_OpponentUsesHealItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	useitemonopponent
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesStatusCureItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gTrainerItemCuredStatusStringIds
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesXItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gStatUpStringIds
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesGuardSpecs::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gMistUsedStringIds
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_RunByUsingItem::
	playse SE_FLEE
	setbyte gBattleOutcome, B_OUTCOME_RAN
	finishturn

BattleScript_ActionWatchesCarefully:
	printstring STRINGID_PKMNWATCHINGCAREFULLY
	waitmessage 0x40
	end2

BattleScript_ActionGetNear:
	printfromtable gSafariGetNearStringIds
	waitmessage 0x40
	end2

BattleScript_ActionThrowPokeblock:
	printstring STRINGID_THREWPOKEBLOCKATPKMN
	waitmessage 0x40
	playanimation BS_ATTACKER, B_ANIM_POKEBLOCK_THROW, NULL
	printfromtable gSafariPokeblockResultStringIds
	waitmessage 0x40
	end2

BattleScript_ActionWallyThrow:
	printstring STRINGID_RETURNMON
	waitmessage 0x40
	returnatktoball
	waitstate
	trainerslidein BS_TARGET
	waitstate
	printstring STRINGID_YOUTHROWABALLNOWRIGHT
	waitmessage 0x40
	end2

BattleScript_TrainerSlideMsgRet::
	handletrainerslidemsg BS_SCRIPTING, 0
	trainerslidein 1
	handletrainerslidemsg BS_SCRIPTING, 1
	waitstate
	trainerslideout 1
	handletrainerslidemsg BS_SCRIPTING, 2
	waitstate
	return

BattleScript_TrainerSlideMsgEnd2::
	call BattleScript_TrainerSlideMsgRet
	end2

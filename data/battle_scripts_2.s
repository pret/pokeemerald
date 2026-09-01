#include "config/battle.h"
#include "constants/global.h"
#include "constants/battle.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_stat_change.h"
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
	.4byte BattleScript_ItemIncreaseStat             @ EFFECT_ITEM_INCREASE_ALL_STATS
	.4byte BattleScript_UsePokeFlute                 @ EFFECT_ITEM_USE_POKE_FLUTE

	.align 2
gBattlescriptsForSafariActions::
	.4byte BattleScript_ActionWatchesCarefully
	.4byte BattleScript_ActionGetNear
	.4byte BattleScript_ActionThrowPokeblock
	.4byte BattleScript_ActionWallyThrow
	.4byte BattleScript_ActionThrowRock
	.4byte BattleScript_ActionThrowBait

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
	clearmoveresultflags MOVE_RESULT_NO_EFFECT
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
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
	clearmoveresultflags MOVE_RESULT_NO_EFFECT
	printstring STRINGID_ITEMRESTOREDSPECIESHEALTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemRestoreHP_SendOutRevivedBattler:
	switchhandleorder BS_SCRIPTING, 0
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	trytoclearprimalweather
	switchinanim BS_SCRIPTING, FALSE, FALSE
	waitstate
	switchineffects BS_SCRIPTING
	switchinevents
	end

BattleScript_ItemCureStatus::
	call BattleScript_UseItemMessage
BattleScript_ItemCureStatusAfterItemMsg:
	itemcurestatus BattleScript_ItemCureStatusEnd, BattleScript_CureStatus_Battler
	printfromtable gPartyCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ItemCureStatusEnd:
	end

BattleScript_CureStatus_Battler::
	updatestatusicon BS_SCRIPTING
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
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
	trybattlerstatchange BS_ATTACKER, STAT_CHANGE_NO_FLAGS
	end

BattleScript_UsePokeFlute::
	checkpokeflute
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 1, BattleScript_PokeFluteWakeUp
	printstring STRINGID_POKEFLUTECATCHY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_PokeFluteEnd

BattleScript_PokeFluteWakeUp::
	printstring STRINGID_POKEFLUTE
	waitmessage B_WAIT_TIME_LONG
	fanfare MUS_RG_POKE_FLUTE
	waitfanfare
	printstring STRINGID_MONHEARINGFLUTEAWOKE
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_PLAYER2
	waitstate
BattleScript_PokeFluteEnd::
	finishaction

BattleScript_ItemSetMist::
	call BattleScript_UseItemMessage
	setmist
	playmoveanimation MOVE_MIST
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ItemSetFocusEnergy::
	call BattleScript_UseItemMessage
	itemincreasestat
	jumpifvolatile BS_ATTACKER, VOLATILE_DRAGON_CHEER, BattleScript_ButItFailed
	jumpifvolatile BS_ATTACKER, VOLATILE_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy BS_ATTACKER
	playmoveanimation MOVE_FOCUS_ENERGY
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

BattleScript_BallThrow::
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_CATCH_TUTORIAL, BattleScript_BallThrowByWally
	printstring STRINGID_PLAYERUSEDITEM
	handleballthrow

BattleScript_BallThrowByWally::
	printstring STRINGID_TRAINER1USEDITEM
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
	trygivecaughtmonnick
	givecaughtmon BattleScript_SuccessBallThrowEnd
	printfromtable gCaughtMonStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SuccessBallThrowEnd
BattleScript_GiveCaughtMonEnd::
	givecaughtmon BattleScript_SuccessBallThrowEnd
BattleScript_SuccessBallThrowEnd::
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_WallyBallThrow::
	printstring STRINGID_GOTCHAPKMNCAUGHTWALLY
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	animatewildpokemonafterfailedpokeball BS_TARGET
	waitmessage B_WAIT_TIME_LONG
	printfromtable gBallEscapeStringIds
	waitanimation
	waitmessage B_WAIT_TIME_LONG
	handlefailedvictorycatch
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
	printfromtable gSafariReactionStringIds
	waitmessage B_WAIT_TIME_LONG
#if IS_FRLG
	playanimation BS_OPPONENT1, B_ANIM_SAFARI_REACTION
#endif
	end

BattleScript_ActionGetNear:
	printfromtable gSafariGetNearStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ActionThrowPokeblock:
	printstring STRINGID_THREWPOKEBLOCKATPKMN
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_POKEBLOCK_THROW, NULL
	printfromtable gSafariPokeblockResultStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ActionWallyThrow:
	printstring STRINGID_RETURNMON
	waitmessage B_WAIT_TIME_LONG
	returnatktoball
	waitstate
	trainerslidein BS_PLAYER1
	waitstate
	printstring STRINGID_YOUTHROWABALLNOWRIGHT
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_TrainerASlideMsgRet::
	trainerslidein BS_OPPONENT1
	handletrainerslidemsg BS_SCRIPTING, PRINT_SLIDE_MESSAGE
	waitstate
	trainerslideout BS_OPPONENT1
	waitstate
	handletrainerslidemsg BS_SCRIPTING, RESTORE_BATTLER_SLIDE_CONTROL
	return

BattleScript_TrainerASlideMsgEnd::
	call BattleScript_TrainerASlideMsgRet
	end

BattleScript_TrainerBSlideMsgRet::
	trainerslidein BS_OPPONENT2
	handletrainerslidemsg BS_SCRIPTING, PRINT_SLIDE_MESSAGE
	waitstate
	trainerslideout BS_OPPONENT2
	waitstate
	handletrainerslidemsg BS_SCRIPTING, RESTORE_BATTLER_SLIDE_CONTROL
	return

BattleScript_TrainerBSlideMsgEnd::
	call BattleScript_TrainerBSlideMsgRet
	end

BattleScript_TrainerPartnerSlideMsgRet::
	trainerslidein BS_PLAYER2
	handletrainerslidemsg BS_SCRIPTING, PRINT_SLIDE_MESSAGE
	waitstate
	trainerslideout BS_PLAYER2
	waitstate
	handletrainerslidemsg BS_SCRIPTING, RESTORE_BATTLER_SLIDE_CONTROL
	return

BattleScript_TrainerPartnerSlideMsgEnd::
	call BattleScript_TrainerPartnerSlideMsgRet
	end

BattleScript_TrainerSlideMsg::
	trainerslidein BS_SCRIPTING
	handletrainerslidemsg BS_SCRIPTING, PRINT_SLIDE_MESSAGE
	waitstate
	trainerslideout BS_SCRIPTING
	waitstate
	handletrainerslidemsg BS_SCRIPTING, RESTORE_BATTLER_SLIDE_CONTROL
	end3

BattleScript_GhostBallDodge::
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_ITDODGEDBALL
	waitmessage B_WAIT_TIME_LONG
	finishaction

BattleScript_ActionThrowRock::
	printstring STRINGID_THREWROCK
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_ROCK_THROW
	end

BattleScript_ActionThrowBait::
	printstring STRINGID_THREWBAIT
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_POKEBLOCK_THROW
	end

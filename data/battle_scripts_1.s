#include "config/general.h"
#include "config/battle.h"
#include "constants/global.h"
#include "constants/battle.h"
#include "constants/pokemon.h"
#include "constants/battle_arena.h"
#include "constants/battle_move_resolution.h"
#include "constants/battle_stat_change.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/trainers.h"
#include "constants/species.h"
#include "constants/config_changes.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

BattleScript_TryRevertWeatherform:
	setbyte gEffectBattler, 0
	sortbattlers
BattleScript_TryRevertWeatherformLoop:
	tryrevertweatherform
	addbyte gEffectBattler, 1
	jumpifbytenotequal gEffectBattler, gBattlersCount, BattleScript_TryRevertWeatherformLoop
	return

BattleScript_FickleBeamMessage::
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_FICKLEBEAMDOUBLED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagnitudeMessage::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MAGNITUDESTRENGTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_Terastallization::
	@ TODO: no string prints in S/V, but right now this helps with clarity
	flushtextbox
	printstring STRINGID_PKMNSTORINGENERGY
	playanimation BS_ATTACKER, B_ANIM_TERA_CHARGE
	waitanimation
	applyterastallization
	playanimation BS_ATTACKER, B_ANIM_TERA_ACTIVATE
	waitanimation
	printstring STRINGID_PKMNTERASTALLIZEDINTO
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_TeraFormChange::
	@ TODO: no string prints in S/V, but right now this helps with clarity
	flushtextbox
	printstring STRINGID_PKMNSTORINGENERGY
	handleformchange BS_ATTACKER, 0, FALSE @ Prevent species name from overriting type name
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_TERA_CHARGE
	waitanimation
	applyterastallization
	playanimation BS_ATTACKER, B_ANIM_TERA_ACTIVATE
	waitanimation
	printstring STRINGID_PKMNTERASTALLIZEDINTO
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	abilityonformchange BS_ATTACKER
	effectsafterformchange
	end3

BattleScript_EffectStatChange::
	attackcanceler
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_EffectStatChangeHalfHp::
	attackcanceler
	trymovestatchanges
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	goto BattleScript_MoveEnd

BattleScript_PlayMoveAnim::
    playmoveanimation MOVE_NONE
	waitanimation
    return

BattleScript_StatChangeFailed::
	pause B_WAIT_TIME_SHORT
    printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PlayMoveAnimAndChangeHP::
	call BattleScript_PlayMoveAnim
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_IGNORE
    return

BattleScript_PlayTidyUp::
	call BattleScript_PlayMoveAnim
	trytidyup TRUE, NULL
	printstring STRINGID_TIDYINGUPCOMPLETE
	waitmessage B_WAIT_TIME_LONG
    return

BattleScript_EffectDefog::
	attackcanceler
	trymovestatchanges
	trydefog TRUE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectMemento::
	attackcanceler
	trymovestatchanges
    tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_Memento::
	setatkhptozero
	attackanimation
	waitanimation
    return

BattleScript_TakeHeart::
	attackanimation
	waitanimation
	updatestatusicon BS_ATTACKER
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
    return

BattleScript_ToxicThread::
	seteffectprimary BS_ATTACKER, BS_SCRIPTING, MOVE_EFFECT_POISON
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_SwaggerConfusion::
	seteffectprimary BS_ATTACKER, BS_SCRIPTING, MOVE_EFFECT_CONFUSION
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_SwaggerOwnTempoPrevents::
	call BattleScript_OwnTempoPreventsRet
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_NoRetreatMessage::
	printstring STRINGID_CANTESCAPEDUETOUSEDMOVE
	waitmessage B_WAIT_TIME_LONG
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_AutotomizeMessage::
	printstring STRINGID_BECAMENIMBLE
	waitmessage B_WAIT_TIME_LONG
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_TarShotMessage::
	printstring STRINGID_PKMNBECAMEWEAKERTOFIRE
	waitmessage B_WAIT_TIME_LONG
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_AbilityStatChange::
	call BattleScript_AbilityPopUp
	trystatchanges BS_EFFECT_BATTLER, STAT_CHANGE_IGNORE_SELF
	return

BattleScript_DefiantActivates::
	call BattleScript_AbilityPopUp
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_SECOND_QUEUE
	return

BattleScript_AdrenalineOrbActivates::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_SECOND_QUEUE
	removeitem BS_SCRIPTING
	return

BattleScript_MoveEffectStatChange::
	trystatchanges BS_ATTACKER, STAT_CHANGE_SILENT_FAILURE | STAT_CHANGE_IGNORE_SELF
	return

BattleScript_ItemStatChange::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM
	removeitem BS_SCRIPTING
	return

BattleScript_ConsumableBerryStatRaise::
	call BattleScript_ItemPopUp_Scripting
 	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM | STAT_CHANGE_CERTAIN
	removeitem BS_SCRIPTING
	return

BattleScript_ConsumableBerryStatRaiseRipen::
	call BattleScript_AbilityPopUp
	waitabilitypopup
	call BattleScript_ItemPopUp_Scripting
 	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM | STAT_CHANGE_CERTAIN
	removeitem BS_SCRIPTING
	return

BattleScript_ConsumableItemStatRaise::
	call BattleScript_ItemPopUp_Scripting
 	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM | STAT_CHANGE_CERTAIN
	removeitem BS_SCRIPTING
	return

BattleScript_MirrorArmorReflect::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_SECOND_QUEUE | STAT_CHANGE_IGNORE_MIRROR_ARMOR
	return

BattleScript_EndTurnStatChange::
	trystatchanges BS_ATTACKER, STAT_CHANGE_IGNORE_MIRROR_ARMOR
	return

BattleScript_IncreaseStatChangeMessage::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	tryadrenalineorb
	return

BattleScript_DecreaseStatChangeMessage::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	trydefiantrattled
	tryadrenalineorb
	return

BattleScript_DecreaseStatChangeMessageMinStat::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StatDidntChangeMessagePause::
	pause B_WAIT_TIME_SHORT
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectShedTail::
	attackcanceler
	waitstate
	jumpifvolatile BS_ATTACKER, VOLATILE_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcommanderactive BS_ATTACKER, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	setsubstitute
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteString
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_IGNORE
	printstring STRINGID_SHEDITSTAIL
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_ATTACKER_VISIBLE
	moveendfrom MOVEEND_TARGET_VISIBLE
	call BattleScript_MoveSwitchOpenPartyScreenReturnWithNoAnim
	switchinanim BS_ATTACKER, FALSE, TRUE
	waitstate
	switchineffects BS_ATTACKER
	switchinevents
	goto BattleScript_MoveEnd

BattleScript_MoveEffectPsychicNoise::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	printstring STRINGID_PKMNPREVENTEDFROMHEALING
	waitmessage B_WAIT_TIME_LONG
	restoretarget
	return

BattleScript_EffectDoodle::
	attackcanceler
	trycopyability BS_ATTACKER, BattleScript_ButItFailed
	saveattacker
	attackanimation
	waitanimation
	setbyte gBattleCommunication, 0
	goto BattleScript_EffectDoodle_AfterCopy
BattleScript_EffectDoodle_CopyAbility:
	trycopyability BS_ATTACKER, BattleScript_EffectDoodleMoveEnd
BattleScript_EffectDoodle_AfterCopy:
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_ATTACKER
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0x0, BattleScript_EffectDoodleMoveEnd
	addbyte gBattleCommunication, 1
	jumpifnoally BS_ATTACKER, BattleScript_EffectDoodleMoveEnd
	setallytonextattacker BattleScript_EffectDoodle_CopyAbility
BattleScript_EffectDoodleMoveEnd:
	restoreattacker
	goto BattleScript_MoveEnd

BattleScript_SyrupBombActivates::
	printstring STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SyrupBombEndTurn::
	flushtextbox
	playanimation BS_TARGET, B_ANIM_SYRUP_BOMB_SPEED_DROP
	trystatchanges BS_ATTACKER, STAT_CHANGE_IGNORE_MIRROR_ARMOR
	return

BattleScript_MoveSwitchPursuitEnd:
	call BattleScript_MoveSwitchPursuitRet
	end

BattleScript_MoveSwitchPursuitRet:
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_MoveSwitchEnd
	jumpifcommanderactive BS_ATTACKER, BattleScript_MoveSwitchEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_MoveSwitchEnd
	printstring STRINGID_PKMNWENTBACK
	waitmessage B_WAIT_TIME_SHORT
	jumpifnopursuitswitchdmg BattleScript_MoveSwitchOpenPartyScreenRet
	return

BattleScript_MoveSwitch::
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_MoveSwitchEnd
	jumpifcommanderactive BS_ATTACKER, BattleScript_MoveSwitchEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_MoveSwitchEnd
	printstring STRINGID_PKMNWENTBACK
	waitmessage B_WAIT_TIME_SHORT
BattleScript_MoveSwitchOpenPartyScreen::
	call BattleScript_MoveSwitchOpenPartyScreenRet
BattleScript_MoveSwitchEnd:
	end

BattleScript_MoveSwitchOpenPartyScreenRet:
	call BattleScript_MoveSwitchOpenPartyScreenReturnWithNoAnim
	switchinanim BS_ATTACKER, FALSE, FALSE
	waitstate
	switchineffects BS_ATTACKER
	switchinevents
	return

BattleScript_MoveSwitchOpenPartyScreenReturnWithNoAnim:
	returntoball BS_ATTACKER, FALSE
	switchoutabilities BS_ATTACKER
	openpartyscreen BS_ATTACKER, BattleScript_MoveSwitchEnd
	waitstate
	switchhandleorder BS_ATTACKER, 2
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	return

BattleScript_PledgeWaitingForPartner::
	pause B_WAIT_TIME_MED
	printstring STRINGID_WAITINGFORPARTNERSMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHitCombinedPledge::
	pause B_WAIT_TIME_MED
	printstring STRINGID_THETWOMOVESBECOMEONE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TheRainbowActivates::
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_ARAINBOWAPPEAREDONSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_EFFECT_BATTLER, B_ANIM_RAINBOW
	waitanimation
	return

BattleScript_TheRainbowDisappeared::
	printstring STRINGID_THERAINBOWDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SeaOfFireActivates::
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_SEAOFFIREENVELOPEDSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_EFFECT_BATTLER, B_ANIM_SEA_OF_FIRE
	waitanimation
	return

BattleScript_HurtByTheSeaOfFire::
	printstring STRINGID_HURTBYTHESEAOFFIRE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_TheSeaOfFireDisappeared::
	printstring STRINGID_THESEAOFFIREDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TheSwampActivates::
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_SWAMPENVELOPEDSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_EFFECT_BATTLER, B_ANIM_SWAMP
	waitanimation
	return

BattleScript_TheSwampDisappeared::
	printstring STRINGID_THESWAMPDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectSaltCure::
	printstring STRINGID_TARGETISBEINGSALTCURED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SaltCureExtraDamage::
	playanimation BS_ATTACKER, B_ANIM_SALT_CURE_DAMAGE, NULL
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_TARGETISHURTBYSALTCURE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_HP_THRESHOLD
	return

BattleScript_EffectCorrosiveGas::
	attackcanceler
	jumpifcantloseitem BattleScript_CorrosiveGasFail
	attackanimation
	waitanimation
	jumpifability BS_TARGET, ABILITY_STICKY_HOLD, BattleScript_StickyHoldActivates
	setlastuseditem BS_TARGET
	removeitem BS_TARGET
	printstring STRINGID_PKMNITEMMELTED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_CorrosiveGasFail:
	pause B_WAIT_TIME_SHORT
	setmoveresultflags MOVE_RESULT_FAILED
	printstring STRINGID_NOEFFECTONTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRevivalBlessing::
	attackcanceler
	tryrevivalblessing BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREVIVEDREADYTOFIGHT
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_EffectRevivalBlessingSendOut
	goto BattleScript_MoveEnd

BattleScript_EffectRevivalBlessingSendOut:
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	hpthresholds BS_SCRIPTING
	switchinanim BS_SCRIPTING, FALSE, FALSE
	waitstate
	switchineffects BS_SCRIPTING
	switchinevents
	goto BattleScript_MoveEnd

BattleScript_MoveEffectStealthRock::
	setstealthrock BattleScript_MoveEffectStealthRockRet
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveEffectStealthRockRet:
	return

BattleScript_MoveEffectSpikes::
	trysetspikes BattleScript_MoveEffectSpikesRet
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveEffectSpikesRet:
	return

BattleScript_EffectTeatime::
	attackcanceler
	checkteatimetargets BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_EffectTeatimeGetTarget
BattleScript_EffectTeatimeNextTarget:
	jumpifnoberry BS_TARGET, BattleScript_EffectTeatimeGetTarget
	setbyte sBERRY_OVERRIDE, TRUE @ override the requirements for eating berries
	consumeberry BS_TARGET, TRUE @ consume the berry, then restore the item from changedItems
	setbyte sBERRY_OVERRIDE, FALSE
	removeitem BS_TARGET
	moveendcase MOVEEND_NEXT_TARGET
BattleScript_EffectTeatimeGetTarget:
	getpossiblenexttarget BattleScript_EffectTeatimeNextTarget
	moveendfrom MOVEEND_ITEM_EFFECTS_ATTACKER_2
	end

BattleScript_AffectionBasedEndurance::
	playanimation BS_TARGET, B_ANIM_AFFECTION_HANGED_ON
	printstring STRINGID_TARGETTOUGHEDITOUT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AffectionBasedStatusHeal::
	jumpifstatus BS_ATTACKER, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_AffectionBasedStatus_HealPoisonString
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_AffectionBasedStatus_HealSleepString
	jumpifstatus BS_ATTACKER, STATUS1_PARALYSIS, BattleScript_AffectionBasedStatus_HealParalysisString
	jumpifstatus BS_ATTACKER, STATUS1_BURN, BattleScript_AffectionBasedStatus_HealBurnString
	jumpifstatus BS_ATTACKER, STATUS1_FREEZE, BattleScript_AffectionBasedStatus_HealFreezeString
	jumpifstatus BS_ATTACKER, STATUS1_FROSTBITE, BattleScript_AffectionBasedStatus_HealFrostbiteString
	return
BattleScript_AffectionBasedStatus_HealPoisonString:
	printstring STRINGID_ATTACKEREXPELLEDTHEPOISON
	goto BattleScript_AffectionBasedStatusHeal_Continue
BattleScript_AffectionBasedStatus_HealSleepString:
	printstring STRINGID_ATTACKERSHOOKITSELFAWAKE
	goto BattleScript_AffectionBasedStatusHeal_Continue
BattleScript_AffectionBasedStatus_HealParalysisString:
	printstring STRINGID_ATTACKERBROKETHROUGHPARALYSIS
	goto BattleScript_AffectionBasedStatusHeal_Continue
BattleScript_AffectionBasedStatus_HealBurnString:
	printstring STRINGID_ATTACKERHEALEDITSBURN
	goto BattleScript_AffectionBasedStatusHeal_Continue
BattleScript_AffectionBasedStatus_HealFreezeString:
	printstring STRINGID_ATTACKERMELTEDTHEICE
	goto BattleScript_AffectionBasedStatusHeal_Continue
BattleScript_AffectionBasedStatus_HealFrostbiteString:
	printstring STRINGID_ATTACKERHEALEDITSFROSTBITE
BattleScript_AffectionBasedStatusHeal_Continue:
	waitmessage B_WAIT_TIME_LONG
	clearstatus BS_ATTACKER
	waitstate
	updatestatusicon BS_ATTACKER
	waitstate
	return

BattleScript_ShellTrapSetUp::
	flushtextbox
	playanimation BS_SCRIPTING, B_ANIM_SHELL_TRAP_SETUP, NULL
	printstring STRINGID_PREPARESHELLTRAP
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_ShellTrapSetUpEncored::
	flushtextbox
	playanimation BS_SCRIPTING, B_ANIM_SHELL_TRAP_SETUP, NULL
	printstring STRINGID_PREPARESHELLTRAP
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_ShellTrapFailed::
	printstring STRINGID_SHELLTRAPDIDNTWORK
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCourtChange::
	attackcanceler
	swapsidestatuses
	attackanimation
	waitanimation
	printstring STRINGID_COURTCHANGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_BeakBlastSetUp::
	flushtextbox
	playanimation BS_SCRIPTING, B_ANIM_BEAK_BLAST_SETUP, NULL
	printstring STRINGID_HEATUPBEAK
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_BeakBlastSetUpEncored::
	flushtextbox
	playanimation BS_SCRIPTING, B_ANIM_BEAK_BLAST_SETUP, NULL
	printstring STRINGID_HEATUPBEAK
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_BeakBlastBurn::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectBurn
	return

BattleScript_FlingMessage::
	printstring STRINGID_PKMNFLUNG
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectFlingConsumeBerry::
	setbyte sBERRY_OVERRIDE, 1 @ override the requirements for eating berries
	consumeberry BS_TARGET, FALSE
	setbyte sBERRY_OVERRIDE, 0
BattleScript_FlingEnd:
	removeitem BS_ATTACKER @ fallback if a beryy could not be consumed
	trysymbiosis BS_ATTACKER
	return

BattleScript_FlingFailConsumeItem::
	removeitem BS_ATTACKER
	goto BattleScript_ButItFailed

BattleScript_TargetAvoidsAttackConsumeFlingItem::
	call BattleScript_BattlerAvoidedAttack
	removeitem BS_ATTACKER
	return

BattleScript_TargetProtectedConsumeFlingItem::
	call BattleScript_TargetProtected
	removeitem BS_ATTACKER
	return

BattleScript_FlingBlockedByShieldDust::
	printstring STRINGID_ITEMWASUSEDUP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_RemoveItem::
	removeitem BS_ATTACKER
	return

BattleScript_EffectOctolock::
	attackcanceler
	trysetoctolock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PoltergeistMessage::
	printstring STRINGID_ABOUTTOUSEPOLTERGEIST
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BothCanNoLongerEscape::
	printstring STRINGID_BOTHCANNOLONGERESCAPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ButHoopaCantUseIt::
	printstring STRINGID_BUTHOOPACANTUSEIT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectIonDeluge::
	printstring STRINGID_IONDELUGEON
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectHaze::
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectLeechSeed::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	printstring STRINGID_PKMNSEEDED
	waitmessage B_WAIT_TIME_LONG
	restoretarget
	return

BattleScript_MoveEffectScreens::
	saveattacker
	copybyte gBattlerAttacker, gEffectBattler
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	restoreattacker
	return

BattleScript_StuffCheeks::
	attackanimation
	waitanimation
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_STUFF_CHEEKS
	removeitem BS_ATTACKER
    restorestatchangequeue
    return

BattleScript_EffectJungleHealing::
	attackcanceler
	jumpifteamhealthy BattleScript_ButItFailed
	attackanimation
	waitanimation
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte gBattleCommunication, 0
JungleHealing_RestoreTargetHealth:
	copybyte gBattlerAttacker, gBattlerTarget
	tryhealquarterhealth BS_TARGET, BattleScript_JungleHealing_TryCureStatus
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_JungleHealing_TryCureStatus:
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_JungleHealingCureStatus
	goto BattleScript_JungleHealingTryRestoreAlly
BattleScript_JungleHealingCureStatus:
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_JungleHealingTryRestoreAlly:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0x0, BattleScript_MoveEnd
	addbyte gBattleCommunication, 1
	jumpifnoally BS_TARGET, BattleScript_MoveEnd
	setallytonexttarget JungleHealing_RestoreTargetHealth
	goto BattleScript_MoveEnd

BattleScript_EffectLifeDew::
	attackcanceler
	jumpiffullhp BS_ATTACKER, BattleScript_EffectLifeDewCheckPartner
	copybyte gBattlerTarget, gBattlerAttacker
	attackanimation
	waitanimation
	call BattleScript_EffectLifeDewHealing
	jumpifabsent BS_ATTACKER_PARTNER, BattleScript_EffectLifeDewEnd
	jumpiffullhp BS_ATTACKER_PARTNER, BattleScript_EffectLifeDewEnd
	setallytonexttarget BattleScript_EffectLifeDewNextTarget
BattleScript_EffectLifeDewNextTarget:
	call BattleScript_EffectLifeDewHealing
BattleScript_EffectLifeDewEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectLifeDewCheckPartner:
	jumpifabsent BS_ATTACKER_PARTNER, BattleScript_ButItFailed
	jumpiffullhp BS_ATTACKER_PARTNER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setallytonexttarget BattleScript_EffectLifeDewNextTarget

BattleScript_EffectLifeDewHealing:
	tryhealquarterhealth BS_TARGET, BattleScript_EffectLifeDewEnd
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectAllySwitch::
	attackcanceler
	tryallyswitch BattleScript_ButItFailed
	attackanimation
	waitanimation
	@ The actual data/gfx swap happens in the move animation. Here it's just the gBattlerAttacker / scripting battler change
	allyswitchswapbattlers
	printstring STRINGID_ALLYSWITCHPOSITION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFairyLock::
	attackcanceler
	trysetfairylock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_NOONEWILLBEABLETORUNAWAY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RemoveFireType::
	printstring STRINGID_ATTACKERLOSTFIRETYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RemoveElectricType::
	printstring STRINGID_ATTACKERLOSTELECTRICTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RemoveGenericType::
	printstring STRINGID_ATTACKERLOSTITSTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectPurify::
	attackcanceler
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_PurifyWorks
	goto BattleScript_ButItFailed
BattleScript_PurifyWorks:
	attackanimation
	waitanimation
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
	printstring STRINGID_ATTACKERCUREDTARGETSTATUS
	waitmessage B_WAIT_TIME_LONG
	tryhealhalfhealth BS_ATTACKER, BattleScript_AlreadyAtFullHp
	goto BattleScript_RestoreHp

BattleScript_MoveEffectIncinerate::
	printstring STRINGID_INCINERATEBURN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectBugBite::
	printstring STRINGID_BUGBITE
	waitmessage B_WAIT_TIME_LONG
	setbyte sBERRY_OVERRIDE, 1   @ override the requirements for eating berries
	savetarget
	consumeberry BS_ATTACKER, FALSE
	setbyte sBERRY_OVERRIDE, 0
	restoretarget
	trysymbiosis BS_TARGET
	return

BattleScript_MoveEffectCoreEnforcer::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	setgastroacid BattleScript_CoreEnforcerRet
	printstring STRINGID_PKMNSABILITYSUPPRESSED
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
BattleScript_CoreEnforcerRet:
	restoretarget
	return

BattleScript_EffectLaserFocus::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_LASER_FOCUS_TIMER, BattleScript_ButItFailed
	setvolatile BS_ATTACKER, VOLATILE_LASER_FOCUS_TIMER, B_LASER_FOCUS_TIMER
	attackanimation
	waitanimation
	printstring STRINGID_LASERFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PartingShotEscape::
	call BattleScript_MoveSwitchPursuitRet
	return

BattleScript_EffectPowder::
	attackcanceler
	jumpifvolatile BS_TARGET, VOLATILE_POWDER, BattleScript_ButItFailed
	setvolatile BS_TARGET, VOLATILE_POWDER
	attackanimation
	waitanimation
	printstring STRINGID_COVEREDINPOWDER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFeint::
	printfromtable gBrokeProtectionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectThirdType::
	attackcanceler
	trythirdtype BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_THIRDTYPEADDED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBestow::
	attackcanceler
	trybestow BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	tryactivateabilitywithabilityshield BS_TARGET, FALSE
	tryactivateitem BS_TARGET, ACTIVATION_ON_USABLE_AGAIN
	trysymbiosis BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_ActivateSwitchInAbility::
	switchinabilities BS_SCRIPTING
	return

BattleScript_EffectAfterYou::
	attackcanceler
	tryafteryou BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_KINDOFFER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFlameBurst::
	printstring STRINGID_BURSTINGFLAMESHIT
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER, ASSURANCE_DOUBLE
	tryfaintmon BS_EFFECT_BATTLER
	return

BattleScript_EffectPowerTrick::
	attackcanceler
	powertrick
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDATKANDDEF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychoShift::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_ANY, BattleScript_EffectPsychoShiftCanWork
	goto BattleScript_ButItFailed
BattleScript_EffectPsychoShiftCanWork:
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifsafeguard BattleScript_SafeguardProtected
	trypsychoshift BattleScript_ButItFailed, BattleScript_SleepClauseBlocked
	attackanimation
	waitanimation
	copybyte gEffectBattler, gBattlerTarget
	printfromtable gStatusConditionsStringIds
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_TARGET
	updatestatusicon BS_TARGET
	waitstate
	trysynchronize
	curestatus BS_ATTACKER
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_ItDoesntAffectScrTarget::
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_SHORT
	flushtextbox
	return

BattleScript_ButItFailedRet::
	pause B_WAIT_TIME_SHORT
    printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
    return

BattleScript_MoveEffectSmackDown::
	printstring STRINGID_FELLSTRAIGHTDOWN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectHitEnemyHealAlly::
	jumpiftargetally BattleScript_EffectHealPulse
	goto BattleScript_EffectHit

BattleScript_MoveEffectDefog::
	trydefog TRUE, NULL
	return

BattleScript_EffectInstruct::
	attackcanceler
	pause B_WAIT_TIME_SHORT
	tryinstruct BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_USEDINSTRUCTEDMOVE
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerAttacker, gBattlerTarget
	copybyte gBattlerTarget, gEffectBattler
	jumptocalledmove TRUE

BattleScript_FinalGambit::
	setatkhptozero
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_TryHitSwitchTarget::
	forcerandomswitch BattleScript_HitSwitchTargetForceRandomSwitchFailed
	return

BattleScript_HitSwitchTargetDynamaxed::
	printstring STRINGID_MOVEBLOCKEDBYDYNAMAX
	waitmessage B_WAIT_TIME_LONG
BattleScript_HitSwitchTargetForceRandomSwitchFailed:
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	return

BattleScript_EffectSoak::
	attackcanceler
	jumpifability BS_TARGET, ABILITY_MULTITYPE, BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_RKS_SYSTEM, BattleScript_ButItFailed
	attackanimation
	waitanimation
	trysoak BattleScript_ButItFailed
	printstring STRINGID_TARGETCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectReflectType::
	attackcanceler
	tryreflecttype BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_REFLECTTARGETSTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectElectrify::
	attackcanceler
	tryelectrify BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_TARGETELECTRIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTerrain::
	attackcanceler
	setterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	goto BattleScript_MoveEnd

BattleScript_EffectTopsyTurvy::
	attackcanceler
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_DEF, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPATK, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPDEF, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPEED, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ACC, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_EVASION, 6, BattleScript_ButItFailed
BattleScript_EffectTopsyTurvyWorks:
	attackanimation
	waitanimation
	invertstatstages
	printstring STRINGID_TOPSYTURVYSWITCHEDSTATS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectIonDeluge::
	attackcanceler
	orword gFieldStatuses, STATUS_FIELD_ION_DELUGE
	attackanimation
	waitanimation
	printstring STRINGID_IONDELUGEON
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectQuash::
	attackcanceler
	tryquash BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_QUASHSUCCESS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealPulse::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_HEAL_BLOCK_TIMER, BattleScript_MoveUsedHealBlockPrevents @ stops pollen puff
	jumpifvolatile BS_TARGET, VOLATILE_HEAL_BLOCK_TIMER, BattleScript_MoveUsedHealBlockPrevents
	tryhealpulse BattleScript_AlreadyAtFullHp
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEntrainment::
	attackcanceler
	tryentrainment BattleScript_ButItFailed
	attackanimation
	waitanimation
	switchinabilities BS_TARGET
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	goto BattleScript_MoveEnd

BattleScript_EffectLuckyChant::
	attackcanceler
	setluckychant BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_SHIELDEDFROMCRITICALHITS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealingWish::
	attackcanceler
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	instanthpdrop
	setatkhptozero
	tryfaintmon BS_ATTACKER
	storehealingwish BS_ATTACKER
	jumpifgenconfiglowerthan CONFIG_B_HEALING_WISH_SWITCH, GEN_5, BattleScript_EffectHealingWishGen4
	goto BattleScript_MoveEnd

BattleScript_EffectHealingWishGen4:
	openpartyscreen BS_ATTACKER, BattleScript_MoveEnd
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returnatktoball
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	flushtextbox
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, FALSE, TRUE
	waitstate
	switchineffects BS_ATTACKER
	switchinevents
	goto BattleScript_MoveEnd

BattleScript_HealingWishActivates::
	setbyte cMULTISTRING_CHOOSER, 0
	goto BattleScript_EffectHealingWishRestore
BattleScript_LunarDanceActivates::
	setbyte cMULTISTRING_CHOOSER, 1
	restoremovepp BS_SCRIPTING
BattleScript_EffectHealingWishRestore:
	printfromtable gHealingWishStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_WISH_HEAL
	waitanimation
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	clearstatus BS_SCRIPTING,
	waitstate
	updatestatusicon BS_SCRIPTING
	waitstate
	printstring STRINGID_HEALINGWISHHEALED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectOverwriteAbility::
	attackcanceler
	tryoverwriteability BattleScript_ButItFailed
	attackanimation
	waitanimation
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_TARGET
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSplit::
	attackcanceler
	averagestats STAT_ATK
	averagestats STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSplit::
	attackcanceler
	averagestats STAT_DEF
	averagestats STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHeartSwap::
	attackcanceler
	swapstatstages STAT_ATK
	swapstatstages STAT_DEF
	swapstatstages STAT_SPEED
	swapstatstages STAT_SPATK
	swapstatstages STAT_SPDEF
	swapstatstages STAT_EVASION
	swapstatstages STAT_ACC
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSwap::
	attackcanceler
	swapstatstages STAT_ATK
	swapstatstages STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSwap::
	attackcanceler
	swapstatstages STAT_DEF
	swapstatstages STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpeedSwap::
	attackcanceler
	swapstats STAT_SPEED
	setvolatile BS_ATTACKER, VOLATILE_SPEED_SWAP, 1
	setvolatile BS_TARGET, VOLATILE_SPEED_SWAP, 1
	attackanimation
	waitanimation
	printstring STRINGID_ATTACKERSWITCHEDSTATWITHTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTelekinesis::
	attackcanceler
	settelekinesis BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_HURLEDINTOTHEAIR
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStealthRock::
	attackcanceler
	setstealthrock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POINTEDSTONESFLOAT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStickyWeb::
	attackcanceler
	setstickyweb BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_STICKYWEBUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGastroAcid::
	attackcanceler
	jumpifvolatile BS_TARGET, VOLATILE_GASTRO_ACID, BattleScript_ButItFailed
	setgastroacid BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSABILITYSUPPRESSED
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	goto BattleScript_MoveEnd

BattleScript_EffectToxicSpikes::
	attackcanceler
	settoxicspikes BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagnetRise::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_ROOT, BattleScript_ButItFailed
	jumpifvolatile BS_ATTACKER, VOLATILE_SMACK_DOWN, BattleScript_ButItFailed
	jumpifvolatile BS_ATTACKER, VOLATILE_MAGNET_RISE_TIMER, BattleScript_ButItFailed
	setvolatile BS_ATTACKER, VOLATILE_MAGNET_RISE_TIMER, B_MAGNET_RISE_TIMER
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEVITATEDONELECTROMAGNETISM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrickRoom::
	attackcanceler
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryRoomServiceLoop
	goto BattleScript_MoveEnd

BattleScript_TryRoomServiceLoop:
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_RoomServiceLoop:
	copybyte sBATTLER, gBattlerTarget
	tryroomservice BS_TARGET, BattleScript_RoomServiceLoop_NextBattler
	removeitem BS_TARGET
BattleScript_RoomServiceLoop_NextBattler:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RoomServiceLoop
	restoretarget
	return

BattleScript_EffectWonderRoom::
BattleScript_EffectMagicRoom::
	attackcanceler
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAquaRing::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_AQUA_RING, BattleScript_ButItFailed
	setvolatile BS_ATTACKER, VOLATILE_AQUA_RING
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSURROUNDEDWITHVEILOFWATER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEmbargo::
	attackcanceler
	setembargo BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCANTUSEITEMSANYMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTailwind::
	attackcanceler
	settailwind BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_TAILWINDBLEW
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryTailwindAbilitiesLoop
	goto BattleScript_MoveEnd

BattleScript_TryTailwindAbilitiesLoop:
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_TryTailwindAbilitiesLoop_Iter:
	trywindriderpower BS_TARGET, BattleScript_TryTailwindAbilitiesLoop_Increment
BattleScript_TryTailwindAbilitiesLoop_Increment:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TryTailwindAbilitiesLoop_Iter
	restoretarget
	return

BattleScript_EffectMiracleEye::
	attackcanceler
	jumpifgenconfiglowerthan CONFIG_B_MIRACLE_EYE_FAIL, GEN_5, BattleScript_MiracleEyeSet
	jumpifvolatile BS_TARGET, VOLATILE_MIRACLE_EYE, BattleScript_ButItFailed
BattleScript_MiracleEyeSet:
	setvolatile BS_TARGET, VOLATILE_MIRACLE_EYE
	goto BattleScript_IdentifiedFoe

BattleScript_EffectGravity::
	call BattleScript_EffectGravityInternal
	goto BattleScript_MoveEnd

BattleScript_EffectGravityInternal:
	attackcanceler
	setgravity BattleScript_ButItFailed
	attackanimation
	waitanimation
BattleScript_MoveEffectGravity::
	printstring STRINGID_GRAVITYINTENSIFIED
	waitmessage B_WAIT_TIME_LONG
	savetarget
	selectfirstvalidtarget
BattleScript_GravityLoop:
	jumpfifsemiinvulnerable BS_TARGET, STATE_ON_AIR, BattleScript_GravityLoopDrop
	jumpfifsemiinvulnerable BS_TARGET, STATE_SKY_DROP_ATTACKER, BattleScript_GravityLoopDrop
	jumpfifsemiinvulnerable BS_TARGET, STATE_SKY_DROP_TARGET, BattleScript_GravityLoopDrop
	jumpifvolatile BS_TARGET, VOLATILE_MAGNET_RISE_TIMER, BattleScript_GravityLoopDrop
	jumpifvolatile BS_TARGET, VOLATILE_TELEKINESIS, BattleScript_GravityLoopDrop
	goto BattleScript_GravityLoopEnd
BattleScript_GravityLoopDrop:
	gravityonairbornemons
	printstring STRINGID_GRAVITYGROUNDING
	waitmessage B_WAIT_TIME_LONG
BattleScript_GravityLoopEnd:
	moveendcase MOVEEND_TARGET_VISIBLE
	jumpifnexttargetvalid BattleScript_GravityLoop
	restoretarget
	return

BattleScript_EffectRoost::
	attackcanceler
	tryhealhalfhealth BS_TARGET, BattleScript_AlreadyAtFullHp
	setroost
	goto BattleScript_HealTarget

BattleScript_EffectHealBlock::
	attackcanceler
	jumpifvolatile BS_TARGET, VOLATILE_HEAL_BLOCK_TIMER, BattleScript_ButItFailed
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	setvolatile BS_TARGET, VOLATILE_HEAL_BLOCK_TIMER, B_HEAL_BLOCK_TIMER
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPREVENTEDFROMHEALING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHitEscape::
	jumpiffainted BS_TARGET, FALSE, BattleScript_HitEscapeSwitch
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
BattleScript_HitEscapeSwitch:
	call BattleScript_MoveSwitchPursuitRet
	return

BattleScript_EffectPlaceholder::
	attackcanceler
	pause 5
	printstring STRINGID_NOTDONEYET
	goto BattleScript_MoveEnd

BattleScript_EffectHit::
	attackcanceler
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	setadditionaleffects
BattleScript_MoveEnd::
	moveendall
	end

BattleScript_MoveAnimation::
	waitanimation
	return

BattleScript_MoveMissed::
	pause B_WAIT_TIME_SHORT
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_TerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printfromtable gTerrainPreventsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ImmunityProtectedRet::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ElectricTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ELECTRICTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_MistyTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MISTYTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_FlowerVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_FLOWERVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FlowerVeilProtects::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_FLOWERVEILPROTECTEDTARGET
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_SweetVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_FLOWERVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SweetVeilProtects:
	call BattleScript_SweetVeilProtectsRet
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AromaVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_AROMAVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AromaVeilProtects:
	call BattleScript_AromaVeilProtectsRet
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AbilityProtectsDoesntAffectRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityProtectsDoesntAffect::
	call BattleScript_AbilityProtectsDoesntAffectRet
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_InsomniaProtects::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSTAYEDAWAKEUSING
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause B_WAIT_TIME_SHORT
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_EffectAbsorbLiquidOoze::
	call BattleScript_AbilityPopUp
	jumpifability BS_EFFECT_BATTLER, ABILITY_MAGIC_GUARD, BattleScript_EffectAbsorbRet
	goto BattleScript_EffectAbsorb

BattleScript_EffectAbsorb::
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER, ASSURANCE_DOUBLE
	printfromtable gAbsorbDrainStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_EFFECT_BATTLER
BattleScript_EffectAbsorbRet:
	return

BattleScript_Explosion::
	tryexplosion
	setatkhptozero
	return

BattleScript_FaintAttackerForExplosion::
	tryfaintmon BS_ATTACKER
	return

BattleScript_MaxHp50Recoil::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_StatUp::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StatDown::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectHaze::
	attackcanceler
	attackanimation
	waitanimation
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SetUpBide::
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectRoar::
	attackcanceler
	jumpifroarfails BattleScript_ButItFailed
	jumpifcommanderactive BS_TARGET, BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_GUARD_DOG, BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifvolatile BS_TARGET, VOLATILE_ROOT, BattleScript_PrintMonIsRooted
	jumpiftargetdynamaxed BattleScript_RoarBlockedByDynamax
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	forcerandomswitch BattleScript_ButItFailed

BattleScript_RoarBlockedByDynamax:
	printstring STRINGID_MOVEBLOCKEDBYDYNAMAX
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	multihitplurality
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BattlerAvoidedMultiHit::
	pause B_WAIT_TIME_LONG
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	multihitplurality
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectConversion::
	attackcanceler
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRestoreHp::
	attackcanceler
	tryhealhalfhealth BS_ATTACKER, BattleScript_AlreadyAtFullHp
	attackanimation
	waitanimation
BattleScript_RestoreHp:
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_LONG
	printstring STRINGID_PKMNALREADYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected::
	call BattleScript_AbilityPopUp
	goto BattleScript_DoesntAffectTargetAtkString

BattleScript_EffectAuroraVeil::
	attackcanceler
	setauroraveil
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectLightScreen::
	attackcanceler
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectRest::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifability BS_ATTACKER, ABILITY_COMATOSE, BattleScript_RestIsAlreadyAsleep
	jumpifuproarwakes BattleScript_RestCantSleep
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_InsomniaProtects
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_InsomniaProtects
	jumpifability BS_ATTACKER, ABILITY_PURIFYING_SALT, BattleScript_InsomniaProtects
	jumpifabilitypreventsrest BS_TARGET, BattleScript_AbilityPreventsRest
	trysetrest
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSLEPTHEALTHY
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_HealTarget

BattleScript_RestCantSleep::
	pause B_WAIT_TIME_LONG
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsRest::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RecoilIfMiss::
	printstring STRINGID_PKMNCRASHED
	waitmessage B_WAIT_TIME_LONG
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_RecoilEnd
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
BattleScript_RecoilEnd:
	return

BattleScript_EffectMist::
	attackcanceler
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFocusEnergy::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_DRAGON_CHEER, BattleScript_ButItFailed
	jumpifvolatile BS_ATTACKER, VOLATILE_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy BS_TARGET
	attackanimation
	waitanimation
	printfromtable gFocusEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectConfuse::
	attackcanceler
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifvolatile BS_TARGET, VOLATILE_CONFUSION, BattleScript_AlreadyConfused
	jumpifterrainaffected BS_TARGET, B_TERRAIN_MISTY, BattleScript_MistyTerrainPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary BS_ATTACKER, BS_TARGET, MOVE_EFFECT_CONFUSION
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyConfused::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTransform::
	attackcanceler
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	flushtextbox
	transformdataexecution
	attackanimation
	waitanimation
	printfromtable gTransformUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectReflect::
	attackcanceler
	setreflect
BattleScript_PrintReflectLightScreenSafeguardString::
	attackanimation
	waitanimation
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_VoltAbsorbHeal:
	copybyte gBattlerAbility, gBattlerTarget
	tryhealquarterhealth BS_TARGET, BattleScript_AbilityProtectedTarget @ Check if max hp
	goto BattleScript_MoveHPDrain

BattleScript_AlreadyParalyzed::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNISALREADYPARALYZED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PowerHerbActivation::
	call BattleScript_ItemPopUp_AttackerNoFlush
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_POWERHERB
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_TwoTurnMoveCharging::
	waitmessage B_WAIT_TIME_LONG
	twoturnmoveschargestringandanimation
	setadditionaleffects @ only onChargeTurnOnly effects will work here
	return

BattleScript_SkyDropCharging::
	call BattleScript_TwoTurnMoveCharging
	goto BattleScript_MoveEnd

BattleScript_TwoTurnMovesSecondTurnRet:
	setbyte sB_ANIM_TURN, 1
	setbyte sB_ANIM_TARGETS_HIT, 0
	clearvolatile BS_ATTACKER, VOLATILE_MULTIPLETURNS
	clearsemiinvulnerablebit @ only for moves with EFFECT_SEMI_INVULNERABLE/EFFECT_SKY_DROP
	return

BattleScript_SkyDropTargetTooHeavy::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_TARGETTOOHEAVY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SkyDropFlyingType::
	makevisible BS_TARGET
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	return

BattleScript_SkyDropNoTarget::
	pause B_WAIT_TIME_SHORT
	setmoveresultflags MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectSubstitute::
	attackcanceler
	waitstate
	jumpifvolatile BS_ATTACKER, VOLATILE_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	setsubstitute
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteString
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_IGNORE
BattleScript_SubstituteString::
	pause B_WAIT_TIME_SHORT
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_AlreadyHasSubstitute::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHASSUBSTITUTE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedMustRecharge::
	printstring STRINGID_PKMNMUSTRECHARGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMimic::
	attackcanceler
	mimicattackcopy BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEARNEDMOVE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLeechSeed::
	attackcanceler
	pause B_WAIT_TIME_SHORT
BattleScript_DoLeechSeed::
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDoNothing::
	attackcanceler
	attackanimation
	waitanimation
	incrementgamestat GAME_STAT_USED_SPLASH
	printstring STRINGID_BUTNOTHINGHAPPENED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHoldHands::
	attackcanceler
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectCelebrate::
	attackcanceler
	attackanimation
	waitanimation
	printstring STRINGID_CELEBRATEMESSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHappyHour::
	attackcanceler
	attackanimation
	waitanimation
	seteffectprimary BS_ATTACKER, BS_TARGET, MOVE_EFFECT_HAPPY_HOUR
	goto BattleScript_MoveEnd

BattleScript_EffectDisable::
	attackcanceler
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNMOVEWASDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEncore::
	attackcanceler
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNGOTENCORE
	waitmessage B_WAIT_TIME_LONG
	trydomoveeffectsbeforemoves
	goto BattleScript_MoveEnd

BattleScript_EffectPainSplit::
	attackcanceler
	painsplitdmgcalc BattleScript_ButItFailed
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_IGNORE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_IGNORE
	printstring STRINGID_SHAREDPAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectConversion2::
	attackcanceler
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn::
	attackcanceler
	setalwayshitflag
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTOOKAIM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSketch::
	attackcanceler
	copymovepermanently BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSKETCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDestinyBond::
	attackcanceler
	setvolatile BS_ATTACKER, VOLATILE_DESTINY_BOND, 2
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTRYINGTOTAKEFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectEerieSpell::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	restoretarget
	return

BattleScript_EffectSpite::
	attackcanceler
	tryspiteppreduce BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell::
	attackcanceler
	attackanimation
	waitanimation
	healpartystatus
	waitstate
	printfromtable gPartyStatusHealStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifblockedbysoundproof BS_ATTACKER_PARTNER, BattleScript_HealBellSoundproof
	goto BattleScript_PartyHealEnd
BattleScript_HealBellSoundproof::
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_ATTACKER, BattleScript_CheckHealBellMon2Unaffected
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_LONG
BattleScript_CheckHealBellMon2Unaffected::
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_PARTNER, BattleScript_PartyHealEnd
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_LONG
BattleScript_PartyHealEnd::
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_MoveEffectAromatherapy::
	healpartystatus
	waitstate
	printfromtable gPartyStatusHealStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	return

BattleScript_EffectMeanLook::
	attackcanceler
	jumpifvolatile BS_TARGET, VOLATILE_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifgenconfiglowerthan CONFIG_B_GHOSTS_ESCAPE, GEN_6, BattleScript_EffectMeanLookGen5
	jumpiftype BS_TARGET, TYPE_GHOST, BattleScript_ButItFailed
BattleScript_EffectMeanLookGen5:
	attackanimation
	waitanimation
	seteffectprimary BS_ATTACKER, BS_TARGET, MOVE_EFFECT_PREVENT_ESCAPE
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare::
	attackcanceler
	jumpifvolatile BS_TARGET, VOLATILE_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	jumpifability BS_TARGET, ABILITY_COMATOSE, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed
BattleScript_NightmareWorked::
	attackanimation
	waitanimation
	seteffectprimary BS_ATTACKER, BS_TARGET, MOVE_EFFECT_NIGHTMARE
	printstring STRINGID_PKMNFELLINTONIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCurse::
	attackcanceler
	cursetarget BattleScript_CurseStatChange
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNLAIDCURSE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_CurseStatChange:
	trymovestatchanges
	goto BattleScript_MoveEnd

BattleScript_EffectProtect::
BattleScript_EffectEndure::
	attackcanceler
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes::
	attackcanceler
	trysetspikes BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectForesight::
	attackcanceler
	jumpifgenconfiglowerthan CONFIG_B_FORESIGHT_FAIL, GEN_3, BattleScript_ForesightFailCheck
	jumpifgenconfiglowerthan CONFIG_B_FORESIGHT_FAIL, GEN_5, BattleScript_ForesightSet
BattleScript_ForesightFailCheck:
	jumpifvolatile BS_TARGET, VOLATILE_FORESIGHT, BattleScript_ButItFailed
BattleScript_ForesightSet:
	setvolatile BS_TARGET, VOLATILE_FORESIGHT
BattleScript_IdentifiedFoe:
	attackanimation
	waitanimation
	printstring STRINGID_PKMNIDENTIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong::
	attackcanceler
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_FAINTINTHREE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_TryDestinyKnotTarget:
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotTargetRet
	call BattleScript_ItemPopUp_Attacker
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	printstring STRINGID_DESTINYKNOTACTIVATES
	tryinfatuating BattleScript_TryDestinyKnotTargetFailed
	volatileanimation BS_TARGET, VOLATILE_INFATUATION
	waitanimation
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TryDestinyKnotTargetRet
BattleScript_TryDestinyKnotTargetFailed:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryDestinyKnotTargetRet:
	return

BattleScript_TryDestinyKnotAttacker:
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotTargetRet
	call BattleScript_ItemPopUp_Attacker
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	swapattackerwithtarget
	printstring STRINGID_DESTINYKNOTACTIVATES
	tryinfatuating BattleScript_SwapTargetAttackerButItFailed
	swapattackerwithtarget
	volatileanimation BS_ATTACKER, VOLATILE_INFATUATION
	waitanimation
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectAttract::
	attackcanceler
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotAttacker
	goto BattleScript_MoveEnd

BattleScript_PresentHeal::
	attackcanceler
	attackanimation
	waitanimation
	goto BattleScript_PresentHealGetTarget
BattleScript_PresentHealNextTarget:
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_PresentHealGetTarget:
	getpossiblenexttarget BattleScript_PresentHealNextTarget
	moveendfrom MOVEEND_ITEM_EFFECTS_ATTACKER_2
	end

BattleScript_EffectSafeguard::
	attackcanceler
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectBatonPass::
	attackcanceler
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcommanderactive BS_ATTACKER, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	returntoball BS_ATTACKER, FALSE
	switchoutabilities BS_ATTACKER
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	waitstate
	switchhandleorder BS_ATTACKER, 2
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	flushtextbox
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, FALSE, TRUE
	waitstate
	switchineffects BS_ATTACKER
	switchinevents
	goto BattleScript_MoveEnd

BattleScript_EffectMorningSun::
BattleScript_EffectSynthesis::
BattleScript_EffectMoonlight::
BattleScript_EffectShoreUp::
	attackcanceler
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_HealTarget

BattleScript_MegaSolActivatesHealing::
	attackanimation
	waitanimation
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	goto BattleScript_HealTargetContinue

BattleScript_MegaSolActivatesTwoTurnMove::
	call BattleScript_AbilityPopUpScripting
	pause B_WAIT_TIME_SHORT
	return

BattleScript_EffectWeather::
	attackcanceler
BattleScript_EffectWeatherSetWeather:
	setfieldweather
	attackanimation
	waitanimation
	call BattleScript_MoveWeatherChangeRet
	goto BattleScript_MoveEnd

BattleScript_ChillyReceptionMessage::
	printstring STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectWeatherAndSwitch::
	attackcanceler
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_EffectWeatherSetWeather
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_EffectWeatherSetWeather
	setfieldweather
	clearmoveresultflags MOVE_RESULT_NO_EFFECT
	attackanimation
	waitanimation
	call BattleScript_MoveWeatherChangeRet
	moveendall
	goto BattleScript_MoveSwitch

BattleScript_MoveWeatherChangeRet::
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_FailOnPrimalWeather::
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	return

BattleScript_ExtremelyHarshSunlightWasNotLessened:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_NoReliefFromHeavyRain:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NORELIEFROMHEAVYRAIN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MysteriousAirCurrentBlowsOn:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MYSTERIOUSAIRCURRENTBLOWSON
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BlockedByPrimalWeather::
	call BattleScript_AbilityPopUp
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	return

BattleScript_BlockedByOverworldWeather::
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_SHORT
    printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectPsychUp::
	attackcanceler
	copyfoestats
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFutureSight::
	attackcanceler
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTeleport::
	jumpifgenconfiglowerthan CONFIG_B_TELEPORT_BEHAVIOR, GEN_8, BattleScript_EffectTeleportGen7
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_EffectBatonPass
	jumpifside BS_ATTACKER, B_SIDE_PLAYER, BattleScript_EffectBatonPass
	goto BattleScript_DoEffectTeleport
BattleScript_EffectTeleportGen7::
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_FailedFromAtkCanceler
BattleScript_DoEffectTeleport::
	attackcanceler
	isrunningimpossible
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FORBIDDEN, BattleScript_ButItFailed
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FAILURE, BattleScript_PrintAbilityMadeIneffective
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFLEDFROMBATTLE
	waitmessage B_WAIT_TIME_LONG
	setteleportoutcome BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_BeatUpAttackMessage::
	printstring STRINGID_PKMNATTACK
	return

BattleScript_EffectSoftboiled::
	attackcanceler
	tryhealhalfhealth BS_TARGET, BattleScript_AlreadyAtFullHp
BattleScript_HealTarget::
	attackanimation
	waitanimation
BattleScript_HealTargetContinue::
	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FailedFromAtkCanceler::
	attackcanceler
BattleScript_ButItFailed::
	pause B_WAIT_TIME_SHORT
	setmoveresultflags MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_RestoreAttackerButItFailed:
	restoreattacker
	goto BattleScript_ButItFailed
BattleScript_RestoreTargetButItFailed:
	restoretarget
	goto BattleScript_ButItFailed
BattleScript_SwapTargetAttackerButItFailed:
	swapattackerwithtarget
	goto BattleScript_ButItFailed

BattleScript_NotAffected::
	pause B_WAIT_TIME_SHORT
	setmoveresultflags MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffectedAbilityPopUp::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_Stockpile::
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSTOCKPILED
	waitmessage B_WAIT_TIME_LONG
    return

BattleScript_MoveEffectStockpileWoreOff::
	trybattlerstatchange BS_ATTACKER, STAT_CHANGE_CERTAIN
	printstring STRINGID_STOCKPILEDEFFECTWOREOFF
	waitmessage B_WAIT_TIME_SHORT
	return

BattleScript_EffectSwallow::
	attackcanceler
	stockpiletohpheal BattleScript_ButItFailed
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTorment::
	attackcanceler
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNonVolatileStatus::
	attackcanceler
	trynonvolatilestatus
	attackanimation
	waitanimation
	setnonvolatilestatus TRIGGER_ON_MOVE
	clearmoveresultflags MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	setalreadystatusedmoveattempt
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYHASBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FocusPunchLostFocus::
	printstring STRINGID_PKMNLOSTFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFollowMe::
	attackcanceler
	setforcedtarget
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCENTERATTENTION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt::
	attackcanceler
	jumpifability BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLFORTAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHelpingHand::
	attackcanceler
	trysethelpinghand BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREADYTOHELP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrick::
	attackcanceler
	tryswapitems BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	tryactivateabilitywithabilityshield BS_TARGET, TRUE
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_USABLE_AGAIN
	tryactivateitem BS_TARGET, ACTIVATION_ON_USABLE_AGAIN
	goto BattleScript_MoveEnd

BattleScript_EffectRolePlay::
	attackcanceler
	trycopyability BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_ATTACKER
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectWish::
	attackcanceler
	trywish BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectIngrain::
	attackcanceler
	trysetvolatile BS_ATTACKER, VOLATILE_ROOT, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagicCoat::
	attackcanceler
	trysetmagiccoat BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSHROUDEDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle::
	attackcanceler
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

@ TO-DO: The battle messages from this should come after the move has resolved
BattleScript_BreakScreens::
	playmoveanimation MOVE_NONE @use current move
	waitanimation
BattleScript_BreakScreensRetReflect:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_BREAK_REFLECT, BattleScript_BreakReflect
BattleScript_BreakScreensRetLightScreen:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_BREAK_LIGHT_SCREEN, BattleScript_BreakLightScreen
BattleScript_BreakScreensRetAuroraVeil:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_BREAK_AURORA_VEIL, BattleScript_BreakAuroraVeil
BattleScript_BreakScreensRetFinish:
	return

BattleScript_BreakReflect:
	printstring STRINGID_REFLECTWOREOFF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_BreakScreensRetLightScreen
BattleScript_BreakLightScreen:
	printstring STRINGID_LIGHTSCREENWOREOFF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_BreakScreensRetAuroraVeil
BattleScript_BreakAuroraVeil:
	printstring STRINGID_AURORAVEILWOREOFF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_BreakScreensRetFinish

BattleScript_StealStats::
	playmoveanimation MOVE_SPECTRAL_THIEF
	waitanimation
	printstring STRINGID_SPECTRALTHIEFSTEAL
	waitmessage B_WAIT_TIME_LONG
	trybattlerstatchange BS_ATTACKER, STAT_CHANGE_NO_FLAGS
	flushtextbox
	return

BattleScript_EffectYawn::
	attackcanceler
	trynonvolatilestatus
	setyawn BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectYawnFoe::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage B_WAIT_TIME_LONG
	restoretarget
	return

BattleScript_PrintAbilityMadeIneffective::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSkillSwap::
	attackcanceler
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
	jumpiftargetally BattleScript_EffectSkillSwap_AfterAbilityPopUp
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUpOverwriteThenNormal
	copybyte gBattlerAbility, gBattlerTarget
	copyhword sABILITY_OVERWRITE, gLastUsedAbility
	call BattleScript_AbilityPopUpOverwriteThenNormal
BattleScript_EffectSkillSwap_AfterAbilityPopUp:
	recordability BS_ATTACKER
	recordability BS_TARGET
	printstring STRINGID_PKMNSWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
.if B_SKILL_SWAP >= GEN_4
	switchinabilities BS_ATTACKER
	switchinabilities BS_TARGET
.endif
	goto BattleScript_MoveEnd

BattleScript_EffectImprison::
	attackcanceler
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSEALEDOPPONENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh::
	attackcanceler
	curestatuswithmove BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectGrudge::
	attackcanceler
	jumpifvolatile BS_ATTACKER, VOLATILE_GRUDGE, BattleScript_ButItFailed
	setvolatile BS_ATTACKER, VOLATILE_GRUDGE, 2
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWANTSGRUDGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch::
	attackcanceler
	trysetsnatch BattleScript_ButItFailed
	attackanimation
	waitanimation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWAITSFORTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStruggle::
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectMudSport::
BattleScript_EffectWaterSport::
	attackcanceler
	settypebasedhalvers BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gSportsUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCamouflage::
	attackcanceler
	settypetoenvironment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FaintBattler::
	tryillusionoff BS_FAINTED
	undodynamax BS_FAINTED
	playfaintcry BS_FAINTED
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_FAINTED
	copybyte sBATTLER, gBattlerFainted @ for message
	printstring STRINGID_BATTLERFAINTED
	tryconfusionafterskydrop BS_FAINTED
	cleareffectsonfaint BS_FAINTED
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	waitanimation
	tryactivatereceiver BS_FAINTED
	tryactivatesoulheart
	trytrainerslidemsgfirstoff BS_FAINTED
	return

BattleScript_GiveExp::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end

BattleScript_HandleFaintedMon::
	setbyte sSHIFT_SWITCHED, 0
	checkteamslost BattleScript_HandleFaintedMonMultiple
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonTryChoose
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChoose
@ Yes/No for sending out a new Pokémon if one is defeated in a wild battle
	printstring STRINGID_USENEXTPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChoose
@ Player said no, try to run
	jumpifplayerran BattleScript_FaintedMonEnd
	printstring STRINGID_CANTESCAPE2
BattleScript_FaintedMonTryChoose:
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_RECORDED_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonSendOutNew
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonSendOutNew
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, OPTIONS_BATTLE_STYLE_SET, BattleScript_FaintedMonSendOutNew
	jumpifcantswitch BS_PLAYER1, BattleScript_FaintedMonSendOutNew
	setbyte sILLUSION_NICK_HACK, 1
@ Yes/No for sending out a new Pokémon when the opponent is switching
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_FaintedMonSendOutNew
@ Player said yes, go to party screen (note optional flag, player may exit the menu instead)
	setatktoplayer0
	openpartyscreen BS_ATTACKER | PARTY_SCREEN_OPTIONAL, BattleScript_FaintedMonSendOutNew
	switchhandleorder BS_ATTACKER, 2
	jumpifbyte CMP_EQUAL, gBattleCommunication, PARTY_SIZE, BattleScript_FaintedMonSendOutNew
@ Switch Pokémon before opponent
	atknameinbuff1
	resetswitchinabilitybits
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	flushtextbox
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE, FALSE
	waitstate
	setbyte sSHIFT_SWITCHED, 1
BattleScript_FaintedMonSendOutNew:
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	trytoclearprimalweather
	flushtextbox
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE, FALSE
	waitstate
	resetplayerfainted
	trytrainerslidemsglaston BS_FAINTED
	jumpifbytenotequal sSHIFT_SWITCHED, sZero, BattleScript_FaintedMonShiftSwitched
BattleScript_FaintedMonSendOutNewEnd:
	switchineffects BS_FAINTED
	switchinevents
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonEnd
	cancelallactions
BattleScript_FaintedMonEnd::
	end
BattleScript_FaintedMonShiftSwitched:
	copybyte sSAVED_BATTLER, gBattlerTarget
	switchineffects BS_ATTACKER
	switchinevents
	resetsentmonsvalue
	copybyte gBattlerTarget, sSAVED_BATTLER
	goto BattleScript_FaintedMonSendOutNewEnd

BattleScript_HandleFaintedMonMultiple::
	openpartyscreen BS_FAINTED_MULTIPLE_1, BattleScript_HandleFaintedMonMultipleStart
BattleScript_HandleFaintedMonMultipleStart::
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_FAINTED_MULTIPLE_2, BattleScript_HandleFaintedMonMultipleEnd
	switchhandleorder BS_FAINTED, 0
BattleScript_HandleFaintedMonLoop::
	switchhandleorder BS_FAINTED, 3
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	trytoclearprimalweather
	flushtextbox
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE, FALSE
	waitstate
	trytrainerslidemsglaston BS_FAINTED
	switchineffects BS_FAINTED_MULTIPLE_1
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_HandleFaintedMonLoop
BattleScript_HandleFaintedMonMultipleEnd::
	switchinevents
	trytrainerslidemsglaston BS_FAINTED_MULTIPLE_2
	trytrainerslidemsglaston BS_FAINTED_MULTIPLE_1
	end

BattleScript_FirstTurnSwitchInEvents::
	switchinevents
	end3

BattleScript_EndTurnEvents::
	endturnevents
	end

BattleScript_LocalTrainerBattleWon::
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalTwoTrainersDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_LocalBattleWonLoseTexts
BattleScript_LocalTwoTrainersDefeated::
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_LocalBattleWonLoseTexts::
	trainerslidein BS_OPPONENT1
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleWonReward
	trainerslideout BS_OPPONENT1
	waitstate
	trainerslidein BS_OPPONENT2
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_LocalBattleWonReward::
	getmoneyreward
	printstring STRINGID_PLAYERGOTMONEY
	waitmessage B_WAIT_TIME_LONG
BattleScript_PayDayMoneyAndPickUpItems::
	givepaydaymoney
	pickup
	end

BattleScript_RivalBattleLost::
	jumpifhasnohp BS_ATTACKER, BattleScript_RivalBattleLostSkipMonRecall
	printstring STRINGID_TRAINER1MON1COMEBACK
	waitmessage B_WAIT_TIME_LONG
	returnatktoball
	waitstate
BattleScript_RivalBattleLostSkipMonRecall::
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_LocalBattleLostPrintWhiteOut
	end

BattleScript_LocalBattleLost::
	jumpifbattletype BATTLE_TYPE_DOME, BattleScript_CheckDomeDrew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_TRAINER_HILL, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_EREADER_TRAINER, BattleScript_LocalBattleLostEnd
	jumpifhalfword CMP_EQUAL, gTrainerBattleParameter + 2, TRAINER_SECRET_BASE, BattleScript_LocalBattleLostEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_RivalBattleLost
	jumpifnowhiteout BattleScript_LocalBattleLostEnd_
	jumpifbattletype BATTLE_TYPE_INGAME_PARTNER, BattleScript_LocalBattleLostPrintWhiteOut
BattleScript_LocalBattleLostPrintWhiteOut::
	getmoneyreward
	printstring STRINGID_PLAYERWHITEOUT
	waitmessage B_WAIT_TIME_LONG
.if B_WHITEOUT_MONEY >= GEN_4
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostEnd
	printstring STRINGID_PLAYERWHITEOUT2_WILD
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_PLAYERWHITEOUT3
	waitmessage B_WAIT_TIME_LONG
	end
BattleScript_LocalBattleLostEnd::
	printstring STRINGID_PLAYERWHITEOUT2_TRAINER
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_PLAYERWHITEOUT3
	waitmessage B_WAIT_TIME_LONG
	end
.else
	printstring STRINGID_PLAYERWHITEOUT3
	waitmessage B_WAIT_TIME_LONG
BattleScript_LocalBattleLostEnd::
	end
.endif

BattleScript_CheckDomeDrew::
	jumpifbyte CMP_EQUAL, gBattleOutcome, B_OUTCOME_DREW, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostPrintTrainersWinText::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostPrintWhiteOut
	returnopponentmon1toball
	waitstate
	returnopponentmon2toball
	waitstate
	trainerslidein BS_OPPONENT1
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbattletype BATTLE_TYPE_TOWER_LINK_MULTI, BattleScript_LocalBattleLostDoTrainer2WinText
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostDoTrainer2WinText::
	trainerslideout BS_OPPONENT1
	waitstate
	trainerslidein BS_OPPONENT2
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
BattleScript_LocalBattleLostEnd_::
	end

BattleScript_FrontierLinkBattleLost::
	returnopponentmon1toball
	waitstate
	returnopponentmon2toball
	waitstate
	trainerslidein BS_OPPONENT1
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	trainerslideout BS_OPPONENT1
	waitstate
	trainerslidein BS_OPPONENT2
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_FrontierLinkBattleLostEnd
	endlinkbattle
BattleScript_FrontierLinkBattleLostEnd::
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_LinkBattleWonOrLost::
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_TowerLinkBattleWon
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_LinkBattleWonOrLostWaitEnd
	endlinkbattle
BattleScript_LinkBattleWonOrLostWaitEnd::
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_TowerLinkBattleWon::
	playtrainerdefeatedmusic
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	trainerslidein BS_OPPONENT1
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	trainerslideout BS_OPPONENT1
	waitstate
	trainerslidein BS_OPPONENT2
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_TowerLinkBattleWonEnd
	endlinkbattle
BattleScript_TowerLinkBattleWonEnd::
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_FrontierTrainerBattleWon::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_PayDayMoneyAndPickUpItems
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_FrontierTrainerBattleWon_TwoDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_FrontierTrainerBattleWon_LoseTexts
BattleScript_FrontierTrainerBattleWon_TwoDefeated:
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_FrontierTrainerBattleWon_LoseTexts:
	trainerslidein BS_OPPONENT1
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_TryPickUpItems
	trainerslideout BS_OPPONENT1
	waitstate
	trainerslidein BS_OPPONENT2
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_TryPickUpItems:
	jumpifnotbattletype BATTLE_TYPE_PYRAMID, BattleScript_FrontierTrainerBattleWon_End
	pickup
BattleScript_FrontierTrainerBattleWon_End:
	end

BattleScript_SmokeBallEscape::
	playanimation BS_ATTACKER, B_ANIM_SMOKEBALL_ESCAPE
	printstring STRINGID_PKMNFLEDUSINGITS
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_RanAwayUsingMonAbility::
	call BattleScript_AbilityPopUp
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_GotAwaySafely::
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_WildMonFled::
	printstring STRINGID_WILDPKMNFLED
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_PrintCantRunFromTrainer::
	printstring STRINGID_NORUNNINGFROMTRAINERS
	end

BattleScript_PrintFailedToRunString::
	printfromtable gNoEscapeStringIds
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_PrintCantEscapeFromBattle::
	printselectionstringfromtable gNoEscapeStringIds
	endselectionscript

BattleScript_PrintFullBox::
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch::
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	end

BattleScript_DoSwitchOut::
	undodynamax BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	switchoutabilities BS_ATTACKER
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	flushtextbox
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE, FALSE
	waitstate
	switchineffects BS_ATTACKER
	switchinevents
	moveendcase MOVEEND_STATUS_IMMUNITY_ABILITIES
	moveendcase MOVEEND_MIRROR_MOVE
	end

BattleScript_Pausex20::
	pause B_WAIT_TIME_SHORT
	return

BattleScript_LevelUp::
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNGREWTOLV
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, TRUE
	goto BattleScript_AskToLearnMove
BattleScript_TryLearnMoveLoop::
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, FALSE
BattleScript_AskToLearnMove::
	buffermovetolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNMOVE2
	printstring STRINGID_TRYTOLEARNMOVE3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
.if P_ASK_MOVE_CONFIRMATION == TRUE
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
.endif
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnMoveLoop
BattleScript_ForgotAndLearnedNewMove::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS
BattleScript_LearnedNewMove::
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage B_WAIT_TIME_LONG
	updatechoicemoveonlvlup
	goto BattleScript_TryLearnMoveLoop
BattleScript_LearnMoveReturn::
	return

BattleScript_WeatherAbilityActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	jumpifability BS_SCRIPTING, ABILITY_SAND_SPIT, BattleScript_SandSpitActivates
	printfromtable gAbilityWeatherChangeStringId
BattleScript_WeatherAbilityActivatesContinue:
	waitstate
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_SandSpitActivates::
	printstring STRINGID_ASANDSTORMKICKEDUP
	goto BattleScript_WeatherAbilityActivatesContinue

BattleScript_OrichalcumPulseActivates::
	pause B_WAIT_TIME_SHORT
	copybyte sSAVED_BATTLER, sBATTLER
	call BattleScript_AbilityPopUp
	printfromtable gAbilityWeatherChangeStringId
	waitstate
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	call BattleScript_ActivateWeatherAbilities
	copybyte sBATTLER, sSAVED_BATTLER
	printstring STRINGID_ORICHALCUMPULSEACTIVATES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OrichalcumPulseActivatesInSun::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ORICHALCUMPULSEACTIVATESINSUN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WeatherContinues::
	printfromtable gWeatherTurnStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	setbyte gBattleCommunication, 0
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_WeatherFaded::
	printfromtable gWeatherEndsStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_DamagingWeather::
	printfromtable gSandStormHailDmgStringIds
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	goto BattleScript_DoTurnDmg

BattleScript_FogEnded::
	printstring STRINGID_FOGLIFTED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_IceBodyHeal::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_ICEBODYHPGAIN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OverworldStatusStarts::
	printfromtable gStartingStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	call BattleScript_OverworldStatusStarts_TryActivations
	end3

BattleScript_OverworldStatusStarts_TryActivations:
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SET_TRICK_ROOM, BattleScript_TryRoomServiceLoop
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SET_TAILWIND, BattleScript_TryTailwindAbilitiesLoop
	return

BattleScript_OverworldWeatherStarts::
	printfromtable gWeatherStartsStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_OverworldSSWeatherStarts::
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_OverworldTerrain::
	printfromtable gTerrainStartsStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_BATTLER_0, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	end3

BattleScript_OverworldHazard::
	printfromtable gStartingStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_SideStatusWoreOff::
    saveattacker
    copybyte gBattlerAttacker, sBATTLER
	printstring STRINGID_PKMNSXWOREOFF
    restoreattacker
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LuckyChantEnds::
	printstring STRINGID_LUCKYCHANTENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TailwindEnds::
	printstring STRINGID_TAILWINDENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TrickRoomEnds::
	printstring STRINGID_TRICKROOMENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WonderRoomEnds::
	printstring STRINGID_WONDERROOMENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicRoomEnds::
	printstring STRINGID_MAGICROOMENDS
	waitmessage B_WAIT_TIME_LONG
	setbyte gBattlerTarget, 0
	sortbattlers
BattleScript_MagicRoomHealingItemsLoop:
	copyarraywithindex gBattlerAttacker, gBattlersBySpeed, gBattlerTarget, 1
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_USABLE_AGAIN
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_MagicRoomHealingItemsLoop
	return

BattleScript_TerrainEnds::
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	tryboosterenergy ON_TERRAIN
	return

BattleScript_MudSportEnds::
	printstring STRINGID_MUDSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WaterSportEnds::
	printstring STRINGID_WATERSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_GravityEnds::
	printstring STRINGID_GRAVITYENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SafeguardProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SafeguardEnds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSAFEGUARDEXPIRED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LeechSeedTurnDrainLiquidOoze::
	call BattleScript_LeechSeedTurnDrain
	call BattleScript_AbilityPopUp
	copybyte gEffectBattler, gBattlerAttacker @gEffectBattler is overwritten so general usage not possible
	jumpifability BS_EFFECT_BATTLER, ABILITY_MAGIC_GUARD, BattleScript_LeechSeedTurnDrainHealBlockRet
	goto BattleScript_LeechSeedTurnDrainGainHp

BattleScript_LeechSeedTurnDrainHealBlock::
	call BattleScript_LeechSeedTurnDrain
BattleScript_LeechSeedTurnDrainHealBlockRet:
	return

BattleScript_LeechSeedTurnDrainRecovery::
	call BattleScript_LeechSeedTurnDrain
BattleScript_LeechSeedTurnDrainGainHp:
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	copybyte gEffectBattler, gBattlerAttacker @gEffectBattler is overwritten so general usage not possible
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_LeechSeedTurnDrain:
	playanimation BS_SCRIPTING, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	tryfaintmon BS_SCRIPTING
	tryactivateitem BS_SCRIPTING, ACTIVATION_ON_HP_THRESHOLD
	return

BattleScript_BideStoringEnergy::
	printstring STRINGID_PKMNSTORINGENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_BideAttack::
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BideNoEnergyToAttack::
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed

BattleScript_RoarSuccessSwitch::
	call BattleScript_RoarSuccessRet
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	trytoclearprimalweather
	flushtextbox
	switchinanim BS_TARGET, FALSE, FALSE
	waitstate
	printstring STRINGID_PKMNWASDRAGGEDOUT
	switchineffects BS_TARGET
	switchinevents
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessSwitch_Ret
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd
BattleScript_RoarSuccessSwitch_Ret:
	swapattackerwithtarget  @ continuation of RedCardActivates
	restoretarget
	restoreattacker
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	return

BattleScript_RoarSuccessEndBattle::
	call BattleScript_RoarSuccessRet
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	setteleportoutcome BS_ATTACKER
	finishaction

BattleScript_RoarSuccessRet:
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_HIT, BattleScript_RoarSuccessRet_Ret
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessRet_Ret
	attackanimation
	waitanimation
BattleScript_RoarSuccessRet_Ret:
	returntoball BS_TARGET, FALSE
	waitstate
	switchoutabilities BS_TARGET
	return

BattleScript_MistProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPROTECTEDBYMIST
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RageIsBuilding::
	trybattlerstatchange BS_TARGET, STAT_CHANGE_NO_FLAGS
	printstring STRINGID_PKMNRAGEBUILDING
	waitmessage B_WAIT_TIME_LONG
BattleScript_RageIsBuildingEnd:
	return

BattleScript_MoveUsedIsDisabled::
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove::
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore::
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SelectingDisabledMoveInPalace::
	printstring STRINGID_PKMNMOVEISDISABLED
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_EncoredMove::
	printselectionstring STRINGID_PKMNGOTENCOREDMOVE
	endselectionscript

BattleScript_EncoredMoveInPalace::
	printselectionstring STRINGID_PKMNGOTENCOREDMOVE
BattleScript_SelectingUnusableMoveInPalace::
	goto BattleScript_MoveEnd

BattleScript_EncoredNoMore::
	printstring STRINGID_PKMNENCOREENDED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DestinyBondTakesLife::
	printstring STRINGID_PKMNTOOKFOE
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_DmgHazardsOnBattler::
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_SCRIPTING
	return

BattleScript_PrintHurtByDmgHazards::
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesAbsorbed::
	printstring STRINGID_TOXICSPIKESABSORBED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesPoisoned::
	printstring STRINGID_TOXICSPIKESPOISONED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	waitstate
	return

BattleScript_ToxicSpikesBadlyPoisoned::
	printstring STRINGID_TOXICSPIKESBADLYPOISONED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	waitstate
	return

BattleScript_StickyWebOnSwitchIn::
	setbyte sSTICKY_WEB_STAT_DROP, 1
	printstring STRINGID_STICKYWEBSWITCHIN
	trybattlerstatchange BS_EFFECT_BATTLER, STAT_CHANGE_STICKY_WEB
	setbyte sSTICKY_WEB_STAT_DROP, 0
	return

BattleScript_PerishSongTakesLife::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_PerishBodyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSWILLPERISHIN3TURNS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_GulpMissileGorging::
	call BattleScript_AbilityPopUp
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE_INSTANT
	waitanimation
	playanimation BS_ATTACKER, B_ANIM_GULP_MISSILE
	waitanimation
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_GulpMissileNoDmgGorging
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	jumpiffainted BS_ATTACKER, TRUE, BattleScript_GulpMissileNoSecondEffectGorging
BattleScript_GulpMissileNoDmgGorging:
	seteffectprimary BS_TARGET, BS_ATTACKER, MOVE_EFFECT_PARALYSIS
BattleScript_GulpMissileNoSecondEffectGorging:
	return

BattleScript_GulpMissileGulping::
	call BattleScript_AbilityPopUp
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE_INSTANT
	waitanimation
	playanimation BS_ATTACKER, B_ANIM_GULP_MISSILE
	waitanimation
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_GulpMissileNoDmgGulping
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	jumpiffainted BS_ATTACKER, TRUE, BattleScript_GulpMissileNoSecondEffectGulping
BattleScript_GulpMissileNoDmgGulping:
	trystatchanges BS_TARGET, STAT_CHANGE_NO_FLAGS
BattleScript_GulpMissileNoSecondEffectGulping:
	return

BattleScript_SeedSowerActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESGRASSY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_WindPowerActivates::
	call BattleScript_AbilityPopUp
	setvolatile BS_ABILITY_BATTLER, VOLATILE_CHARGE_TIMER, 1
    copybyte gEffectBattler, gBattlerAbility
	printstring STRINGID_BEINGHITCHARGEDPKMNWITHPOWER
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicDebrisActivates::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	settoxicspikes BattleScript_ToxicDebrisRet
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_ToxicDebrisRet:
	restoretarget
	restoreattacker
	return

BattleScript_EarthEaterActivates::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
	tryhealquarterhealth BS_TARGET, BattleScript_EarthEaterRet
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_EarthEaterRet:
	return

BattleScript_PerishSongCountGoesDown::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AllStatsUpZMove::
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	trybattlerstatchange BS_ATTACKER, STAT_CHANGE_NO_FLAGS
	return

BattleScript_RapidSpinAway::
	rapidspinfree
	return

BattleScript_WrapFree::
	printstring STRINGID_PKMNGOTFREE
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerTarget, sBATTLER
	return

BattleScript_LeechSeedFree::
	printstring STRINGID_PKMNSHEDLEECHSEED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RemoveHazards::
    saveattacker
    copybyte gBattlerAttacker, sBATTLER
	printfromtable gRemoveHazardsStringIds
    restoreattacker
BattleScript_RemoveHazardsRet:
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MonTookFutureAttack::
	printstring STRINGID_PKMNTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	futuresighttargetfailure BattleScript_DoFutureAttackResult
	critmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoFutureAttackResult:
	resultmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_FutureAttackEnd::
	setadditionaleffects
	moveendall
	checkteamslost BattleScript_FutureAttackClearResults
BattleScript_FutureAttackClearResults:
	setmoveresultflags 0
	clearspecialstatuses
	return

BattleScript_NoMovesLeft::
	printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	endselectionscript

BattleScript_SelectingMoveWithNoPP::
	printselectionstring STRINGID_NOPPLEFT
	endselectionscript

BattleScript_NoPPForMove::
	printattackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTNOPPLEFT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	endselectionscript

BattleScript_MoveUsedIsTormented::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveTaunt::
	printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	endselectionscript

BattleScript_MoveUsedIsTaunted::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTauntInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveThroatChop::
	printselectionstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	endselectionscript

BattleScript_MoveUsedIsThroatChopPrevented::
	printstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveThroatChopInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_ThroatChopEndTurn::
	printstring STRINGID_THROATCHOPENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SlowStartEnds::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_SLOWSTARTEND
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SelectingNotAllowedMoveGravity::
	printselectionstring STRINGID_GRAVITYPREVENTSUSAGE
	endselectionscript

BattleScript_SelectingNotAllowedStuffCheeks::
	printselectionstring STRINGID_STUFFCHEEKSCANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedStuffCheeksInPalace::
	printstring STRINGID_STUFFCHEEKSCANTSELECT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedBelch::
	printselectionstring STRINGID_BELCHCANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedBelchInPalace::
	printstring STRINGID_BELCHCANTSELECT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_MoveUsedGravityPrevents::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveGravityInPalace::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveHealBlock::
	printselectionstring STRINGID_HEALBLOCKPREVENTSUSAGE
	endselectionscript

BattleScript_MoveUsedHealBlockPrevents::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveHealBlockInPalace::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedCurrentMove::
	printselectionstring STRINGID_CURRENTMOVECANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedCurrentMoveInPalace::
	printstring STRINGID_CURRENTMOVECANTSELECT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_WishComesTrue::
	playanimation BS_TARGET, B_ANIM_WISH_HEAL
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WishButFullHp::
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WishButHealBlocked::
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IngrainTurnHeal::
	playanimation BS_ATTACKER, B_ANIM_INGRAIN_HEAL
	printstring STRINGID_PKMNABSORBEDNUTRIENTS
BattleScript_TurnHeal:
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	return

BattleScript_AquaRingHeal::
	playanimation BS_ATTACKER, B_ANIM_AQUA_RING_HEAL
	printstring STRINGID_AQUARINGHEAL
	goto BattleScript_TurnHeal

BattleScript_PrintMonIsRooted::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PrintMonIsRootedRet::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_KnockedOff::
	playanimation BS_EFFECT_BATTLER, B_ANIM_ITEM_KNOCKOFF
	printstring STRINGID_PKMNKNOCKEDOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsImprisoned::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	endselectionscript

BattleScript_SelectingImprisonedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_GrudgeTakesPP::
	printstring STRINGID_PKMNLOSTPPGRUDGE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicBounce::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNMOVEBOUNCEDABILITY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicCoat::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNMOVEBOUNCED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicCoatPrankster::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNMOVEBOUNCED
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd

BattleScript_SnatchedMove::
	playanimation BS_ATTACKER, B_ANIM_SNATCH_MOVE
	printstring STRINGID_PKMNSNATCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EnduredMsg::
	printstring STRINGID_PKMNENDUREDHIT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SturdiedMsg::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUpTarget
	printstring STRINGID_PKMNENDUREDHIT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OneHitKOMsg::
	printstring STRINGID_ONEHITKO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectClearSmog::
	printstring STRINGID_RESETSTARGETSSTATLEVELS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FocusPunchSetUp::
	flushtextbox
	call BattleScript_SwapFromSubstitute
	playanimation BS_SCRIPTING, B_ANIM_FOCUS_PUNCH_SETUP
	call BattleScript_SwapToSubstitute
	printstring STRINGID_PKMNTIGHTENINGFOCUS
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_FocusPunchSetUpEncored::
	flushtextbox
	call BattleScript_SwapFromSubstitute
	playanimation BS_SCRIPTING, B_ANIM_FOCUS_PUNCH_SETUP
	call BattleScript_SwapToSubstitute
	printstring STRINGID_PKMNTIGHTENINGFOCUS
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_MegaEvolution::
	flushtextbox
	printstring STRINGID_MEGAEVOREACTING
BattleScript_MegaEvolutionAfterString:
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_MEGA_EVOLUTION
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printstring STRINGID_MEGAEVOEVOLVED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_SCRIPTING
	effectsafterformchange
	end3

BattleScript_WishMegaEvolution::
	flushtextbox
	printstring STRINGID_FERVENTWISHREACHED
	goto BattleScript_MegaEvolutionAfterString

BattleScript_PrimalReversion::
	flushtextbox
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_PRIMAL_REVERSION
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printstring STRINGID_PKMNREVERTEDTOPRIMAL
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_SCRIPTING
	return

BattleScript_PowerConstruct::
	flushtextbox
	printstring STRINGID_POWERCONSTRUCTPRESENCEOFMANY
	waitmessage B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_POWER_CONSTRUCT
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printstring STRINGID_POWERCONSTRUCTTRANSFORM
	waitmessage B_WAIT_TIME_SHORT
	return

BattleScript_UltraBurst::
	flushtextbox
	printstring STRINGID_ULTRABURSTREACTING
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_ULTRA_BURST
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printstring STRINGID_ULTRABURSTCOMPLETED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_SCRIPTING
	effectsafterformchange
	end3

BattleScript_BattlerFormChange::
	pause 5
	call BattleScript_AbilityPopUpScripting
	flushtextbox
BattleScript_BattlerFormChangeNoPopup::
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	sethword sABILITY_OVERWRITE, 0
BattleScript_BattlerFormChangeFromAfterAnimation::
	handleformchange BS_SCRIPTING, 1
	switchinabilities BS_SCRIPTING
	jumpifability BS_SCRIPTING, ABILITY_DISGUISE, BattleScript_ApplyDisguiseFormChangeHPLoss
	return

BattleScript_ZenMode::
	flushtextbox
	call BattleScript_AbilityPopUpScripting
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printfromtable gZenModeStringIds
	waitmessage B_WAIT_TIME_SHORT
	return

BattleScript_BattlerFormChangeDisguise::
	call BattleScript_AbilityPopUpScripting
	pause B_WAIT_TIME_LONG
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE_DISGUISE
	waitanimation
	printstring STRINGID_PKMNDISGUISEWASBUSTED
	waitmessage B_WAIT_TIME_SHORT
	call BattleScript_BattlerFormChangeFromAfterAnimation
	return

BattleScript_BattlerFormChangeWithString::
	pause 5
	call BattleScript_AbilityPopUpScripting
	flushtextbox
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_SCRIPTING, 1
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_SCRIPTING
	return

BattleScript_AttackerFormChangeMoveEffect::
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_ATTACKER, 1
	copybyte sBATTLER, gBattlerAttacker
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BallFetch::
	call BattleScript_AbilityPopUp
	printstring STRINGID_FETCHEDPOKEBALL
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CudChewActivates::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	setbyte sBERRY_OVERRIDE, 1 @ override the requirements for eating berries
	consumeberry BS_ATTACKER, FALSE
	setbyte sBERRY_OVERRIDE, 0
	return

BattleScript_ApplyDisguiseFormChangeHPLoss::
	jumpifgenconfiglowerthan CONFIG_B_DISGUISE_HP_LOSS, GEN_8, BattleScript_ApplyDisguiseFormChangeHPLossReturn
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
BattleScript_ApplyDisguiseFormChangeHPLossReturn:
	return

BattleScript_TargetFormChangeNoPopup:
	flushtextbox
	handleformchange BS_SCRIPTING, 0
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	call BattleScript_BattlerFormChangeFromAfterAnimation
	return

BattleScript_TargetFormChange::
	pause 5
	call BattleScript_AbilityPopUpTarget
	call BattleScript_TargetFormChangeNoPopup
	return

BattleScript_TargetFormChangeWithString::
	pause 5
	call BattleScript_AbilityPopUpTarget
BattleScript_TargetFormChangeWithStringNoPopup::
	call BattleScript_TargetFormChangeNoPopup
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IllusionOffAndTerastallization::
	call BattleScript_IllusionOff
	goto BattleScript_Terastallization

BattleScript_IllusionOff::
	call BattleScript_SwapFromSubstitute
	playanimation BS_SCRIPTING, B_ANIM_ILLUSION_OFF
	waitanimation
	call BattleScript_SwapToSubstitute
	updatenick
	waitstate
	printstring STRINGID_ILLUSIONWOREOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AnticipationActivates::
	pause 5
	call BattleScript_AbilityPopUp
	printstring STRINGID_ANTICIPATIONACTIVATES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AftermathDmg::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_AftermathDmgRet
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
BattleScript_AftermathDmgRet:
	return

BattleScript_DampPreventsAftermath::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	pause 40
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_BeforeSnoreMessage::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	return

BattleScript_MoveUsedWokeUp::
	printfromtable gWokeUpStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_MonWokeUpInUproar::
	printstring STRINGID_PKMNWOKEUPINUPROAR
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	return

BattleScript_PoisonTurnDmg::
	printstring STRINGID_PKMNHURTBYPOISON
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoStatusTurnDmg::
	statusanimation BS_ATTACKER
BattleScript_DoTurnDmg:
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	checkteamslost BattleScript_DoTurnDmgEnd
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_HP_THRESHOLD
BattleScript_DoTurnDmgEnd:
	return

BattleScript_PoisonHealActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	statusanimation BS_ATTACKER
	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	return

BattleScript_BurnTurnDmg::
	printstring STRINGID_PKMNHURTBYBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoStatusTurnDmg

BattleScript_FrostbiteTurnDmg::
	printstring STRINGID_PKMNHURTBYFROSTBITE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoStatusTurnDmg

BattleScript_MoveUsedIsFrozen::
	printstring STRINGID_PKMNISFROZEN
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_BattlerDefrosted::
	printfromtable gGotDefrostedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BattlerFrostbiteHealed::
	printfromtable gFrostbiteHealedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	return

BattleScript_MoveUsedIsParalyzed::
	printstring STRINGID_PKMNISPARALYZED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	cancelmultiturnmoves
	goto BattleScript_MoveEnd

BattleScript_PowderMoveNoEffect::
	pause B_WAIT_TIME_SHORT
	jumpiftype BS_SCRIPTING, TYPE_GRASS, BattleScript_PowderMoveNoEffectPrint
	jumpifability BS_SCRIPTING, ABILITY_OVERCOAT, BattleScript_PowderMoveNoEffectOvercoat
	setlastuseditem BS_SCRIPTING
	printstring STRINGID_SAFETYGOGGLESPROTECTED
	goto BattleScript_PowderMoveNoEffectWaitMsg
BattleScript_PowderMoveNoEffectOvercoat:
	call BattleScript_AbilityPopUp
BattleScript_PowderMoveNoEffectPrint:
	printstring STRINGID_ITDOESNTAFFECTSCR
BattleScript_PowderMoveNoEffectWaitMsg:
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedFlinched::
	printstring STRINGID_PKMNFLINCHED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinchedAndSteadfast::
	printstring STRINGID_PKMNFLINCHED
	waitmessage B_WAIT_TIME_LONG
    call BattleScript_AbilityStatChange
	goto BattleScript_MoveEnd

BattleScript_PrintUproarOverTurns::
	printfromtable gUproarOverTurnStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ThrashConfuses::
	volatileanimation BS_ATTACKER, VOLATILE_CONFUSION
	copybyte sBATTLER, gBattlerAttacker
	printstring STRINGID_PKMNFATIGUECONFUSION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ConfusionAfterRampage::
	volatileanimation BS_SCRIPTING, VOLATILE_CONFUSION
	printstring STRINGID_PKMNFATIGUECONFUSION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsConfused::
	printstring STRINGID_PKMNISCONFUSED
	waitmessage B_WAIT_TIME_LONG
	volatileanimation BS_ATTACKER, VOLATILE_CONFUSION
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, FALSE, BattleScript_MoveUsedIsConfusedRet
BattleScript_DoSelfConfusionDmg::
	cancelmultiturnmoves
	printstring STRINGID_ITHURTCONFUSION
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	tryselfconfusiondmgformchange
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_IGNORE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd
BattleScript_MoveUsedIsConfusedRet::
	return

BattleScript_MoveUsedPowder::
	pause B_WAIT_TIME_SHORT
	cancelmultiturnmoves
	volatileanimation BS_ATTACKER, VOLATILE_POWDER
	waitanimation
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_POWDEREXPLODES
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfusedNoMore::
	printstring STRINGID_PKMNHEALEDCONFUSION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PrintPayDayMoneyString::
	printstring STRINGID_PLAYERPICKEDUPMONEY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WrapTurnDmg::
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_DoTurnDmgEnd
	playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	printstring STRINGID_PKMNHURTBY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_WrapEnds::
	printstring STRINGID_PKMNFREEDFROM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsInLove::
	printstring STRINGID_PKMNINLOVE
	waitmessage B_WAIT_TIME_LONG
	volatileanimation BS_ATTACKER, VOLATILE_INFATUATION
	return

BattleScript_MoveUsedIsInLoveCantAttack::
	printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NightmareTurnDmg::
	printstring STRINGID_PKMNLOCKEDINNIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	volatileanimation BS_ATTACKER, VOLATILE_NIGHTMARE
	goto BattleScript_DoTurnDmg

BattleScript_CurseTurnDmg::
	printstring STRINGID_PKMNAFFLICTEDBYCURSE
	waitmessage B_WAIT_TIME_LONG
	volatileanimation BS_ATTACKER, VOLATILE_CURSED
	goto BattleScript_DoTurnDmg

BattleScript_TargetPRLZHeal::
	printstring STRINGID_PKMNHEALEDPARALYSIS
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetWokeUp::
	printstring STRINGID_TARGETWOKEUP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	return

BattleScript_TargetBurnHeal::
	printstring STRINGID_PKMNBURNHEALED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetPoisonHealed::
	printstring STRINGID_PKMNHEALEDPOISON
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_MoveEffectSleep::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gFellAsleepStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_UpdateEffectStatusIconRet::
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	trytriggerstatusform
	trysynchronize
	tryactivateitem BS_EFFECT_BATTLER, ACTIVATION_ON_STATUS_CHANGE
	flushtextbox
	return

BattleScript_YawnMakesAsleep::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNFELLASLEEP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	tryactivateitem BS_EFFECT_BATTLER, ACTIVATION_ON_STATUS_CHANGE
	jumpfifsemiinvulnerable BS_EFFECT_BATTLER, STATE_SKY_DROP_TARGET, BattleScript_YawnEnd
	makevisible BS_EFFECT_BATTLER
BattleScript_YawnEnd:
	return

BattleScript_EmbargoEndTurn::
	printstring STRINGID_EMBARGOENDS
	waitmessage B_WAIT_TIME_LONG
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_USABLE_AGAIN
	return

BattleScript_TelekinesisEndTurn::
	printstring STRINGID_TELEKINESISENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_HealBlockEndTurn::
	printstring STRINGID_HEALBLOCKEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BufferEndTurn::
	printstring STRINGID_BUFFERENDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectPoison::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotPoisonedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_FlameOrbActivates::
	call BattleScript_ItemPopUp_Scripting
BattleScript_MoveEffectBurn::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFrostbite::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrostbiteStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFreeze::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrozenStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectParalysis::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotParalyzedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectUproar::
	printstring STRINGID_PKMNCAUSEDUPROAR
	waitmessage B_WAIT_TIME_LONG
	jumpifgenconfiglowerthan CONFIG_B_UPROAR, GEN_5, BattleScript_MoveEffectUproarEnd
	setbyte sBATTLER, 0
	trywakebattlersuproar
BattleScript_MoveEffectUproarEnd:
	return

BattleScript_ToxicOrbActivates::
	call BattleScript_ItemPopUp_Scripting
BattleScript_MoveEffectToxic::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNBADLYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectPayDay::
	printstring STRINGID_COINSSCATTERED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectWrap::
	printfromtable gWrappedStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectConfusion::
	volatileanimation BS_EFFECT_BATTLER, VOLATILE_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectRecoilHP25::
	saveattacker
	copybyte gBattlerAttacker, sBATTLER
	call BattleScript_MoveEffectRecoil
	restoreattacker
	return

BattleScript_MoveEffectRecoil::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNHITWITHRECOIL
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_ItemSteal::
	playanimation BS_EFFECT_BATTLER, B_ANIM_ITEM_STEAL
BattleScript_ItemStealNoAnim::
	printstring STRINGID_PKMNSTOLEITEM
	waitmessage B_WAIT_TIME_LONG
	tryactivateabilitywithabilityshield BS_ATTACKER, FALSE
	return

BattleScript_AbilityShieldProtects::
	saveattacker
	copybyte gBattlerAttacker, gBattlerAbility
	call BattleScript_ItemPopUp_AttackerNoFlush
	printstring STRINGID_ABILITYSHIELDPROTECTS
	waitmessage B_WAIT_TIME_LONG
	restoreattacker
	return

BattleScript_AbilityPopUpTarget::
	copybyte gBattlerAbility, gBattlerTarget
BattleScript_AbilityPopUp::
	tryactivateabilityshield BS_ABILITY_BATTLER
	showabilitypopup
	pause B_WAIT_TIME_SHORT
	recordability BS_ABILITY_BATTLER
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_AbilityPopUpScripting:
	copybyte gBattlerAbility, sBATTLER
	goto BattleScript_AbilityPopUp

BattleScript_AbilityPopUpOverwriteThenNormal:
	setbyte sFIXED_ABILITY_POPUP, TRUE
	showabilitypopup
	pause B_WAIT_TIME_SHORT
	sethword sABILITY_OVERWRITE, 0
	updateabilitypopup
	pause B_WAIT_TIME_SHORT
	recordability BS_ABILITY_BATTLER
	destroyabilitypopup
	setbyte sFIXED_ABILITY_POPUP, FALSE
	return

BattleScript_ItemPopUp_Attacker::
	flushtextbox
BattleScript_ItemPopUp_AttackerNoFlush::
	showitempopup BS_ATTACKER
	pause B_WAIT_TIME_LONG
	destroyitempopup
	return

BattleScript_ItemPopUp_Scripting::
	flushtextbox
BattleScript_ItemPopUp_ScriptingNoFlush::
	showitempopup BS_SCRIPTING
	pause B_WAIT_TIME_LONG
	destroyitempopup
	return

BattleScript_ItemPopUp_Target::
	flushtextbox
BattleScript_ItemPopUp_TargetNoFlush::
	showitempopup BS_TARGET
	pause B_WAIT_TIME_LONG
	destroyitempopup
	return

@ Can't compare directly to a value, have to compare to value at pointer
sZero:
.byte 0

BattleScript_EmergencyExit::
	pause 5
	call BattleScript_AbilityPopUpScripting
	pause B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_SLIDE_OFFSCREEN
	waitanimation
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_SwitchOutEffects
	setteleportoutcome BS_SCRIPTING
	finishaction
	return

BattleScript_SwitchOutEffects::
	returntoball BS_SCRIPTING, FALSE
	switchoutabilities BS_SCRIPTING
	return

BattleScript_EmergencyExitSendReplacement::
	call BattleScript_EmergencyExit
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_EmergencyExitSendReplacement_End
	call BattleScript_QueuedSwitchOpenPartyScreen
BattleScript_EmergencyExitSendReplacement_End::
	return

BattleScript_QueuedSwitchOpenPartyScreen::
	openpartyscreen BS_SCRIPTING, BattleScript_QueuedSwitchRet
	waitstate
BattleScript_QueuedSwitch::
	switchhandleorder BS_SCRIPTING, 2
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	hpthresholds BS_SCRIPTING
	printstring STRINGID_SWITCHINMON
	switchinanim BS_SCRIPTING, FALSE, TRUE
	waitstate
	switchineffects BS_SCRIPTING
	switchinevents
BattleScript_QueuedSwitchRet:
	return

BattleScript_TraceActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_PKMNTRACED
	waitmessage B_WAIT_TIME_LONG
	settracedability BS_SCRIPTING
	switchinabilities BS_SCRIPTING
	return

BattleScript_ReceiverActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_RECEIVERABILITYTAKEOVER
	waitmessage B_WAIT_TIME_LONG
	settracedability BS_ABILITY_BATTLER
	switchinabilities BS_ABILITY_BATTLER
	return

BattleScript_AbilityHpHeal::
	call BattleScript_AbilityPopUp
 	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	return

BattleScript_CheekPouchActivates::
	saveattacker
	copybyte gBattlerAttacker, gBattlerAbility
	call BattleScript_AbilityHpHeal
	restoreattacker
	return

BattleScript_PickupActivates::
	pause 5
	tryrecycleitem BattleScript_PickupActivatesEnd
	call BattleScript_AbilityPopUp
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_PICK_UP
BattleScript_PickupActivatesEnd:
	return

BattleScript_HarvestActivates::
	pause 5
	tryrecycleitem BattleScript_HarvestActivatesEnd
	call BattleScript_AbilityPopUp
	printstring STRINGID_HARVESTBERRY
	waitmessage B_WAIT_TIME_LONG
	tryactivateitem BS_ATTACKER, ACTIVATION_ON_HARVEST
BattleScript_HarvestActivatesEnd:
	return

BattleScript_SolarPowerActivates::
	call BattleScript_AbilityPopUp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_HealerActivates::
	call BattleScript_AbilityPopUp
	curestatus BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ShedSkinActivates::
	call BattleScript_AbilityPopUp
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_ActivateWeatherAbilities:
	saveattacker
	savetarget
	tryboosterenergy ON_WEATHER
	setbyte gBattlerAttacker, 0
	sortbattlers
BattleScript_ActivateWeatherAbilities_Loop:
	copyarraywithindex gBattlerTarget, gBattlersBySpeed, gBattlerAttacker, 1
	activateweatherchangeabilities BS_TARGET
	addbyte gBattlerAttacker, 1
	jumpifbytenotequal gBattlerAttacker, gBattlersCount, BattleScript_ActivateWeatherAbilities_Loop
	restoreattacker
	restoretarget
	return

BattleScript_IntimidateActivates::
	call BattleScript_AbilityPopUp
	trystatchanges BS_EFFECT_BATTLER, STAT_CHANGE_INTIMIDATE
	destroyabilitypopup
	return

BattleScript_IntimidateWontDecrease:
	printstring STRINGID_STATSWONTDECREASE
    return

BattleScript_SupersweetSyrupActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_SUPERSWEETAROMAWAFTS
	trystatchanges BS_ATTACKER, STAT_CHANGE_NO_FLAGS
	destroyabilitypopup
	return

BattleScript_PrimalWeatherBlocksMove::
	pause B_WAIT_TIME_SHORT
	printfromtable gPrimalWeatherBlocksStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ProtosynthesisActivates::
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_SUNLIGHTACTIVATEDABILITY
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	return

BattleScript_QuarkDriveActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ELECTRICTERRAINACTIVATEDABILITY
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	return

BattleScript_RuinAbilityActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SupremeOverlordActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CostarActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ZeroToHeroActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_ZEROTOHEROTRANSFORMATION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CommanderActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_COMMANDERACTIVATES
	waitmessage B_WAIT_TIME_LONG
	trybattlerstatchange BS_EFFECT_BATTLER, STAT_CHANGE_NO_FLAGS
	return

BattleScript_HospitalityActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_HOSPITALITYRESTORATION
	waitmessage B_WAIT_TIME_LONG
 	playanimation BS_EFFECT_BATTLER, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER, ASSURANCE_DOUBLE
	return

BattleScript_AttackWeakenedByStrongWinds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ATTACKWEAKENEDBSTRONGWINDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MimicryActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_BATTLERTYPECHANGEDTO
	waitmessage B_WAIT_TIME_SHORT
	return

BattleScript_ActivateTerrainEffects:
	saveattacker
	savetarget
	tryboosterenergy ON_TERRAIN
	resetterrainabilityflags
	setbyte gBattlerAttacker, 0
	sortbattlers
BattleScript_ActivateTerrainSeed:
	copyarraywithindex gBattlerTarget, gBattlersBySpeed, gBattlerAttacker, 1
	tryterrainseed BS_TARGET, BattleScript_ActivateTerrainAbility
	removeitem BS_TARGET
BattleScript_ActivateTerrainAbility:
	activateterrainchangeabilities BS_TARGET
	addbyte gBattlerAttacker, 1
	jumpifbytenotequal gBattlerAttacker, gBattlersCount, BattleScript_ActivateTerrainSeed
	restoreattacker
	restoretarget
	return

BattleScript_ElectricSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESELECTRIC
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_HadronEngineActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_HADRONENGINEACTIVATES
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_HadronEngineActivatesInTerrain::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_HADRONENGINEACTIVATESINTERRAIN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MistySurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESMISTY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_GrassySurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESGRASSY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_PsychicSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESPSYCHIC
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_BadDreamsActivates::
	setbyte gBattlerTarget, 0
BattleScript_BadDreamsLoop:
	jumpiftargetally BattleScript_BadDreamsIncrement
	jumpifability BS_TARGET, ABILITY_MAGIC_GUARD, BattleScript_BadDreamsIncrement
	jumpifability BS_TARGET, ABILITY_COMATOSE, BattleScript_BadDreams_Dmg
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_BadDreams_Dmg
	goto BattleScript_BadDreamsIncrement
BattleScript_BadDreams_Dmg:
	jumpifbytenotequal sFIXED_ABILITY_POPUP, sZero, BattleScript_BadDreams_DmgAfterPopUp
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setbyte sFIXED_ABILITY_POPUP, TRUE
BattleScript_BadDreams_DmgAfterPopUp:
	printstring STRINGID_BADDREAMSDMG
	waitmessage B_WAIT_TIME_LONG
	dmg_1_8_targethp
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	jumpifhasnohp BS_TARGET, BattleScript_BadDreams_HidePopUp
BattleScript_BadDreamsIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_BadDreamsLoop
	jumpifbyteequal sFIXED_ABILITY_POPUP, sZero, BattleScript_BadDreamsEnd
	destroyabilitypopup
	setbyte sFIXED_ABILITY_POPUP, FALSE
	pause 15
BattleScript_BadDreamsEnd:
	return

BattleScript_BadDreams_HidePopUp:
	destroyabilitypopup
	tryfaintmon BS_TARGET
	goto BattleScript_BadDreamsIncrement

BattleScript_TookAttack::
	pause B_WAIT_TIME_SHORT
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SturdyPreventsOHKO::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECTSCR
	pause B_WAIT_TIME_LONG
	return

BattleScript_MoveHPDrain::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNRESTOREDHPUSING
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveStatDrain::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_NO_FLAGS
	return

BattleScript_AbilityProtectedTarget::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FlashFireBoost::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gFlashFireStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityPreventsPhasingOut::
	call BattleScript_AbilityPreventsPhasingOutRet
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsPhasingOutRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNANCHORSITSELFWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityNoStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSSTATLOSSWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityNoSpecificStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXPREVENTSYLOSS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemNoStatLoss::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_CLEARAMULETWONTLOWERSTATS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OwnTempoPrevents::
	call BattleScript_OwnTempoPreventsRet
	goto BattleScript_MoveEnd

BattleScript_OwnTempoPreventsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	copybyte sBATTLER, gBattlerTarget
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IceFaceNullsDamage::
	call BattleScript_TargetFormChangeWithString
	return

BattleScript_PokemonCannotUseMove::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_POKEMONCANNOTUSEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedPsychicTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PSYCHICTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_GrassyTerrainHeals::
	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	printstring STRINGID_GRASSYTERRAINHEALS
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	return

BattleScript_StickyHoldActivates::
	call BattleScript_StickyHoldActivatesRet
	goto BattleScript_MoveEnd

BattleScript_StickyHoldActivatesRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	copybyte sBATTLER, gBattlerAbility
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ColorChangeActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCHANGEDTYPEWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ProteanActivates::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TeraShellDistortingTypeMatchups::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_PKMNMADESHELLGLEAM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CursedBodyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_CURSEDBODYDISABLED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MummyActivates::
	setbyte sFIXED_ABILITY_POPUP, TRUE
	call BattleScript_AbilityPopUpTarget
	copybyte gBattlerAbility, gBattlerAttacker
	copyhword sABILITY_OVERWRITE, gLastUsedAbility
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_TARGET
	recordability BS_ATTACKER
	printstring STRINGID_ATTACKERACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	call BattleScript_TryRevertWeatherform
	flushtextbox
	tryendneutralizinggas
	return

BattleScript_WanderingSpiritActivates::
	saveattacker
	savetarget
	copybyte gBattlerAbility, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_WANDERING_SPIRIT
	call BattleScript_AbilityPopUpOverwriteThenNormal
	copybyte gBattlerAbility, gBattlerAttacker
	copyhword sABILITY_OVERWRITE, gLastUsedAbility
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_TARGET
	recordability BS_ATTACKER
	printstring STRINGID_SWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	jumpiffainted BS_TARGET, TRUE, BattleScript_WanderingSpiritActivatesRet
	switchinabilities BS_TARGET
BattleScript_WanderingSpiritActivatesRet:
	restoreattacker
	restoretarget
	return

BattleScript_SwitchInAbilityMsg::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ActivateAsOne::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	@ show unnerve
	sethword sABILITY_OVERWRITE, ABILITY_UNNERVE
	setbyte cMULTISTRING_CHOOSER, B_MSG_SWITCHIN_UNNERVE
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FriskMsg::
	printstring STRINGID_FRISKACTIVATES
	waitmessage B_WAIT_TIME_LONG
	addbyte sBATTLER, 1
	return

BattleScript_FriskActivates::
	call BattleScript_AbilityPopUp
	setbyte sBATTLER, 0
	tryfriskmessage
	return

BattleScript_ImposterActivates::
	call BattleScript_AbilityPopUp
	transformdataexecution
	playmoveanimation MOVE_TRANSFORM
	waitanimation
	printstring STRINGID_IMPOSTERTRANSFORM
	waitmessage B_WAIT_TIME_LONG
	restoreattacker
	restoretarget
	return

BattleScript_HurtAttacker:
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printfromtable gHurtByStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_HurtAttackerNoMsg:
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	tryfaintmon BS_ATTACKER
	return

BattleScript_RoughSkinActivates::
	flushtextbox
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_HurtAttackerNoMsg
	waitabilitypopup
	return

BattleScript_RockyHelmetActivates::
	call BattleScript_ItemPopUp_ScriptingNoFlush
	call BattleScript_HurtAttacker
	return

BattleScript_SpikyShieldEffect::
	jumpifabsent BS_ATTACKER, BattleScript_SpikyShieldRet
	clearmoveresultflags MOVE_RESULT_NO_EFFECT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNWASHURT
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	setmoveresultflags MOVE_RESULT_MISSED
BattleScript_SpikyShieldRet::
	return

BattleScript_KingsShieldEffect::
	trystatchanges BS_TARGET, STAT_CHANGE_NO_FLAGS
	return

BattleScript_BanefulBunkerEffect::
	clearmoveresultflags MOVE_RESULT_NO_EFFECT
	setnonvolatilestatus TRIGGER_ON_PROTECT
	setmoveresultflags MOVE_RESULT_MISSED
	return

BattleScript_CuteCharmActivates::
	call BattleScript_AbilityPopUp
	volatileanimation BS_ATTACKER, VOLATILE_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotTarget
	return

BattleScript_AbilityStatusEffect::
	waitstate
	call BattleScript_AbilityPopUp
	setnonvolatilestatus TRIGGER_ON_ABILITY
	return

BattleScript_BattleBondActivatesOnMoveEndAttacker::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKERBECAMEFULLYCHARGED
	handleformchange BS_ATTACKER, 0
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_ATTACKER, 1
	printstring STRINGID_ATTACKERBECAMEASHSPECIES
	return

BattleScript_DancerActivates::
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_SHORT
	jumptocalledmove TRUE

BattleScript_SynchronizeActivates::
	waitstate
	call BattleScript_AbilityPopUp
	setnonvolatilestatus TRIGGER_ON_ABILITY
	return

BattleScript_AbilityCuredStatus::
	call BattleScript_AbilityPopUp
	printfromtable gCureStatusStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BattlerShookOffTaunt::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSHOOKOFFTHETAUNT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BattlerGotOverItsInfatuation::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNGOTOVERITSINFATUATION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IgnoresWhileAsleep::
	printstring STRINGID_PKMNIGNORESASLEEP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_IgnoresAndUsesRandomMove::
	printstring STRINGID_PKMNIGNOREDORDERS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedLoafingAround::
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_LOAFING, BattleScript_MoveUsedLoafingAroundMsg
	@ Skip ahead if not the Battle Palace message
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER, BattleScript_MoveUsedLoafingAroundMsg
	setbyte gBattleCommunication, 0
	palacetryescapestatus
	setbyte cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER
BattleScript_MoveUsedLoafingAroundMsg::
	printfromtable gInobedientStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_TruantLoafingAround::
	flushtextbox
	call BattleScript_AbilityPopUp
	goto BattleScript_MoveUsedLoafingAroundMsg

BattleScript_IgnoresAndFallsAsleep::
	printstring STRINGID_PKMNBEGANTONAP
	waitmessage B_WAIT_TIME_LONG
	seteffectprimary BS_ATTACKER, BS_ATTACKER, MOVE_EFFECT_SLEEP
	goto BattleScript_MoveEnd

BattleScript_IgnoresAndHitsItself::
	printstring STRINGID_PKMNWONTOBEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoSelfConfusionDmg

BattleScript_SubstituteFade::
	playanimation BS_SCRIPTING, B_ANIM_SUBSTITUTE_FADE
	printstring STRINGID_PKMNSUBSTITUTEFADED
	return

BattleScript_BerryCureStatusRet::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printfromtable CureStatusBerryEffectStringID
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_BerryCureStatusAndConfusionRet::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printfromtable CureStatusBerryEffectStringID
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	printstring STRINGID_PKMNSITEMSNAPPEDOUT
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_GemActivates::
	call BattleScript_ItemPopUp_AttackerNoFlush
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	printstring STRINGID_GEMACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_BerryReduceAnimation::
	call BattleScript_ItemPopUp_ScriptingNoFlush
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	waitanimation
	waitabilitypopup
	return

BattleScript_BerryReduceDmg::
	printstring STRINGID_BERRYDMGREDUCES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureConfusionRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printstring STRINGID_PKMNSITEMSNAPPEDOUT
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_MentalHerbCureRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
BattleScript_MentalHerbCureRetInfatuation:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_INFATUATION, BattleScript_MentalHerbCuresInfatuation
BattleScript_MentalHerbCureRetTorment:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_TORMENT, BattleScript_MentalHerbCuresTorment
BattleScript_MentalHerbCureRetDisable:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_DISABLE, BattleScript_MentalHerbCuresDisable
BattleScript_MentalHerbCureRetHealBlock:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_HEALBLOCK, BattleScript_MentalHerbCuresHealBlock
BattleScript_MentalHerbCureRetEncore:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_ENCORE, BattleScript_MentalHerbCuresEncore
BattleScript_MentalHerbCureRetTaunt:
	jumpifbyte CMP_BITMASK, cMULTISTRING_CHOOSER, B_MSG_MENTALHERBCURE_TAUNT, BattleScript_MentalHerbCuresTaunt
BattleScript_MentalHerbCureRetFinish:
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_MentalHerbCuresInfatuation:
	printstring STRINGID_ATKGOTOVERINFATUATION
	waitmessage B_WAIT_TIME_LONG
	jumpifgenconfiglowerthan CONFIG_B_MENTAL_HERB, GEN_5, BattleScript_MentalHerbCureRetFinish
	goto BattleScript_MentalHerbCureRetTorment
BattleScript_MentalHerbCuresTorment:
	printstring STRINGID_TORMENTEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MentalHerbCureRetDisable
BattleScript_MentalHerbCuresDisable:
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MentalHerbCureRetHealBlock
BattleScript_MentalHerbCuresHealBlock:
	printstring STRINGID_HEALBLOCKEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MentalHerbCureRetEncore
BattleScript_MentalHerbCuresEncore:
	printstring STRINGID_PKMNENCOREENDED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MentalHerbCureRetTaunt
BattleScript_MentalHerbCuresTaunt:
	printstring STRINGID_PKMNSHOOKOFFTHETAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MentalHerbCureRetFinish

BattleScript_WhiteHerbRet::
	call BattleScript_ItemPopUp_ScriptingNoFlush
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_WhiteHerbFling::
	call BattleScript_ItemPopUp_ScriptingNoFlush
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemHealHP_RemoveBerry::
	jumpifability BS_SCRIPTING, ABILITY_RIPEN, BattleScript_ItemHealHP_RemoveItemRet_AbilityPopUp
	goto BattleScript_ItemHealHP_RemoveItemRet_BerryItemAnim
BattleScript_ItemHealHP_RemoveItemRet_AbilityPopUp:
	call BattleScript_AbilityPopUpScripting
BattleScript_ItemHealHP_RemoveItemRet_BerryItemAnim:
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	call BattleScript_ItemHealHP_RemoveItemRet_AnimContinue
	return

BattleScript_ItemHealHP_RemoveItem::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	call BattleScript_ItemHealHP_RemoveItemRet_AnimContinue
	return

BattleScript_ItemHealHP_RemoveItemRet_AnimContinue:
	playanimation BS_SCRIPTING, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_BerryPPHeal::
	jumpifability BS_SCRIPTING, ABILITY_RIPEN, BattleScript_BerryPPHeal_AbilityPopup
	goto BattleScript_BerryPPHeal_Anim
BattleScript_BerryPPHeal_AbilityPopup:
	call BattleScript_AbilityPopUpScripting
BattleScript_BerryPPHeal_Anim:
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printstring STRINGID_PKMNSITEMRESTOREDPP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_AirBalloonMsgInRet::
	printstring STRINGID_AIRBALLOONFLOAT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AirBalloonMsgPop::
	printstring STRINGID_AIRBALLOONPOP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_ItemHurtRet::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_HURTBYITEM
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_ItemHurtWithAnim::
	call BattleScript_ItemPopUp_Attacker
	playanimation BS_ATTACKER, B_ANIM_MON_HIT
	waitanimation
	call BattleScript_ItemHurtRet
	return

BattleScript_LifeOrbActivates::
	call BattleScript_ItemPopUp_AttackerNoFlush
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	printstring STRINGID_LOSTSOMEOFITSHP
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_ItemHealHP_Ret::
	call BattleScript_ItemPopUp_Attacker
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	playanimation BS_ATTACKER, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER, ASSURANCE_DOUBLE
	return

BattleScript_SelectingNotAllowedMoveChoiceItem::
	printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveChoiceItemInPalace::
	printstring STRINGID_ITEMALLOWSONLYYMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveGorillaTactics::
	printselectionstring STRINGID_ABILITYALLOWSONLYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveGorillaTacticsInPalace::
	printstring STRINGID_ABILITYALLOWSONLYMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveAssaultVest::
	printselectionstring STRINGID_ASSAULTVESTDOESNTALLOW
	endselectionscript

BattleScript_SelectingNotAllowedMoveAssaultVestInPalace::
	printstring STRINGID_ASSAULTVESTDOESNTALLOW
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingCantUseMove::
	printselectionstring STRINGID_CANTUSEMOVE
	endselectionscript

BattleScript_SelectingCantUseMoveInPalace::
	printstring STRINGID_CANTUSEMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedPlaceholder::
	printselectionstring STRINGID_NOTDONEYET
	endselectionscript

BattleScript_SelectingNotAllowedPlaceholderInPalace::
	printstring STRINGID_NOTDONEYET
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_HangedOnMsg::
	call BattleScript_ItemPopUp_Target
	playanimation BS_TARGET, B_ANIM_HANGED_ON
	printstring STRINGID_PKMNHUNGONWITHX
	waitmessage B_WAIT_TIME_LONG
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_FOCUS_SASH, BattleScript_HangedOnMsgRet
	removeitem BS_TARGET
BattleScript_HangedOnMsgRet:
	return

BattleScript_BerryConfuseHeal::
	jumpifability BS_SCRIPTING, ABILITY_RIPEN, BattleScript_BerryConfuseHealRet_AbilityPopup
	goto BattleScript_BerryConfuseHealRet_Anim
BattleScript_BerryConfuseHealRet_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryConfuseHealRet_Anim:
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	playanimation BS_SCRIPTING, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	seteffectprimary BS_SCRIPTING, BS_SCRIPTING, MOVE_EFFECT_CONFUSION
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_BerryFocusEnergy::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printstring STRINGID_PKMNUSEDXTOGETPUMPED
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_ActionSelectionItemsCantBeUsed::
	printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	endselectionscript

BattleScript_FlushMessageBox::
	flushtextbox
	return

BattleScript_PalacePrintFlavorTextRet::
	setbyte gBattleCommunication + 1, 0
BattleScript_PalaceTryBattlerFlavorText::
	palaceflavortext
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, TRUE, BattleScript_PalaceEndFlavorText
	printfromtable gBattlePalaceFlavorTextTable
	waitmessage B_WAIT_TIME_LONG
BattleScript_PalaceEndFlavorText::
	addbyte gBattleCommunication + 1, 1
	jumpifbytenotequal gBattleCommunication + 1, gBattlersCount, BattleScript_PalaceTryBattlerFlavorText
	setbyte gBattleCommunication, 0
	setbyte gBattleCommunication + 1, 0
	return

BattleScript_PalacePrintFlavorText::
	call BattleScript_PalacePrintFlavorTextRet
	end

BattleScript_ArenaTurnBeginningRet::
	waitcry
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	drawarenareftextbox
	arenajudgmentstring B_MSG_REF_COMMENCE_BATTLE
	arenawaitmessage
	pause B_WAIT_TIME_LONG
	erasearenareftextbox
	volumeup
	return

BattleScript_ArenaTurnBeginning::
	call BattleScript_ArenaTurnBeginningRet
	end

BattleScript_ArenaDoJudgment::
	makevisible BS_PLAYER1
	waitstate
	makevisible BS_OPPONENT1
	waitstate
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	pause B_WAIT_TIME_LONG
	drawarenareftextbox
	arenajudgmentstring B_MSG_REF_THATS_IT
	arenawaitmessage
	pause B_WAIT_TIME_LONG
	setbyte gBattleCommunication, 0  @ Reset state for arenajudgmentwindow
	arenajudgmentwindow
	pause B_WAIT_TIME_LONG
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_MIND
	arenawaitmessage
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_SKILL
	arenawaitmessage
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_BODY
	arenawaitmessage
	arenajudgmentwindow
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_PLAYER_LOST, BattleScript_ArenaJudgmentPlayerLoses
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_TIE, BattleScript_ArenaJudgmentDraw
@ ARENA_RESULT_PLAYER_WON
	arenajudgmentstring B_MSG_REF_PLAYER_WON
	arenawaitmessage
	arenajudgmentwindow
	erasearenareftextbox
	printstring STRINGID_DEFEATEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	undodynamax BS_OPPONENT1
	playfaintcry BS_OPPONENT1
	waitcry
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	waitanimation
	arenaopponentmonlost
	end

BattleScript_ArenaJudgmentPlayerLoses:
	arenajudgmentstring B_MSG_REF_OPPONENT_WON
	arenawaitmessage
	arenajudgmentwindow
	erasearenareftextbox
	printstring STRINGID_LOSTTOOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	undodynamax BS_PLAYER1
	playfaintcry BS_PLAYER1
	waitcry
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	waitanimation
	arenaplayermonlost
	end

BattleScript_ArenaJudgmentDraw:
	arenajudgmentstring B_MSG_REF_DRAW
	arenawaitmessage
	arenajudgmentwindow
	erasearenareftextbox
	printstring STRINGID_TIEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	arenabothmonslost
	undodynamax BS_PLAYER1
	playfaintcry BS_PLAYER1
	waitcry
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	waitanimation
	undodynamax BS_OPPONENT1
	playfaintcry BS_OPPONENT1
	waitcry
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	waitanimation
	end

BattleScript_AskIfWantsToForfeitMatch::
	printselectionstring STRINGID_QUESTIONFORFEITMATCH
	forfeityesnobox
	endselectionscript

BattleScript_PrintPlayerForfeited::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_PrintPlayerForfeitedLinkBattle::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	endlinkbattle
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_MirrorHerbCopyStatChange::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_MIRRORHERBCOPIED
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM | STAT_CHANGE_MIRROR_HERB
	return

BattleScript_OpportunistCopyStatChange::
	call BattleScript_AbilityPopUp
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_OPPORTUNIST
	return

BattleScript_TotemBoost::
	playanimation BS_ATTACKER, B_ANIM_TOTEM_FLARE, NULL
	printstring STRINGID_AURAFLAREDTOLIFE
	waitmessage B_WAIT_TIME_LONG
    end3

BattleScript_AnnounceAirLockCloudNine::
	call BattleScript_AbilityPopUp
	printstring STRINGID_AIRLOCKACTIVATES
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_ActivateTeraformZero::
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_LONG
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_ANY, BattleScript_ActivateTeraformZero_RemoveWeather
	jumpifterrain CMP_NOT_EQUAL, B_TERRAIN_NONE, BattleScript_ActivateTeraformZero_RemoveTerrain
	goto BattleScript_ActivateTeraformZero_Ret
BattleScript_ActivateTeraformZeroRemovesOnlyTerrain::
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_LONG
	jumpifterrain CMP_NOT_EQUAL, B_TERRAIN_NONE, BattleScript_ActivateTeraformZero_RemoveTerrain
	goto BattleScript_ActivateTeraformZero_Ret
BattleScript_ActivateTeraformZero_RemoveWeather:
	removeweather
	printfromtable gWeatherEndsStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	jumpifterrain CMP_NOT_EQUAL, B_TERRAIN_NONE, BattleScript_ActivateTeraformZero_RemoveTerrain
BattleScript_ActivateTeraformZero_RemoveTerrain:
	removeterrain
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ActivateTeraformZeroEffects:
	saveattacker
	savetarget
	tryboosterenergy ON_ANY
	resetterrainabilityflags
	setbyte gBattlerAttacker, 0
	sortbattlers
BattleScript_ActivateTeraformZeroLoop:
	copyarraywithindex gBattlerTarget, gBattlersBySpeed, gBattlerAttacker, 1
	activateterrainchangeabilities BS_TARGET
	activateweatherchangeabilities BS_TARGET
	addbyte gBattlerAttacker, 1
	jumpifbytenotequal gBattlerAttacker, gBattlersCount, BattleScript_ActivateTeraformZeroLoop
	restoreattacker
	restoretarget
BattleScript_ActivateTeraformZero_Ret:
	return

BattleScript_QuickClawActivation::
	flushtextbox
	call BattleScript_ItemPopUp_Attacker
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_QuickDrawActivation::
	flushtextbox
	call BattleScript_AbilityPopUp
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_CustapBerryActivation::
	flushtextbox
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_BERRY
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	waitabilitypopup
	end

BattleScript_MicleBerryActivate::
	call BattleScript_ItemPopUp_Scripting
	jumpifability BS_SCRIPTING, ABILITY_RIPEN, BattleScript_MicleBerryActivateRet_Ripen
	goto BattleScript_MicleBerryActivateRet_Anim
BattleScript_MicleBerryActivateRet_Ripen:
	waitabilitypopup
	call BattleScript_AbilityPopUpScripting
BattleScript_MicleBerryActivateRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_BERRY
	printstring STRINGID_MICLEBERRYACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	waitabilitypopup
	return

BattleScript_JabocaRowapBerryActivates::
	call BattleScript_ItemPopUp_Scripting
	jumpifability BS_TARGET, ABILITY_RIPEN, BattleScript_JabocaRowapBerryActivate_Ripen
	goto BattleScript_JabocaRowapBerryActivate_Anim
BattleScript_JabocaRowapBerryActivate_Ripen:
	waitabilitypopup
	call BattleScript_AbilityPopUp
BattleScript_JabocaRowapBerryActivate_Anim:
	jumpifabsent BS_TARGET, BattleScript_JabocaRowapBerryActivate_Dmg   @ dont play the animation for a fainted target
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_BERRY
	waitanimation
BattleScript_JabocaRowapBerryActivate_Dmg:
	call BattleScript_HurtAttacker
	removeitem BS_TARGET
	return

@ z moves / effects
BattleScript_ZMoveActivateDamaging::
	flushtextbox
	printstring STRINGID_ZPOWERSURROUNDS
	playanimation BS_ATTACKER, B_ANIM_ZMOVE_ACTIVATE, NULL
	printstring STRINGID_ZMOVEUNLEASHED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ZMoveActivateStatus::
	flushtextbox
	printstring STRINGID_ZPOWERSURROUNDS
	playanimation BS_ATTACKER, B_ANIM_ZMOVE_ACTIVATE, NULL
	setzeffect
	return

BattleScript_ZEffectPrintString::
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RecoverHPZMove::
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_HealReplacementZMove::
	playanimation BS_SCRIPTING, B_ANIM_WISH_HEAL, 0x0
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING, ASSURANCE_DOUBLE
	return

BattleScript_RemoveTerrain::
	removeterrain
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_Pickpocket::
	call BattleScript_AbilityPopUp
	swapattackerwithtarget
	copybyte gEffectBattler, gBattlerTarget
	call BattleScript_ItemSteal
	swapattackerwithtarget
	activateitemeffects
	return

BattleScript_PickpocketPrevented::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITEMCANNOTBEREMOVED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StickyBarbTransfer::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	printstring STRINGID_STICKYBARBTRANSFER
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_RedCardActivationNoSwitch::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_REDCARDACTIVATE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	restoretarget
	restoreattacker
	return

BattleScript_RedCardActivates::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_REDCARDACTIVATE
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	jumpifvolatile BS_EFFECT_BATTLER, VOLATILE_ROOT, BattleScript_RedCardIngrain
	jumpifability BS_EFFECT_BATTLER, ABILITY_SUCTION_CUPS, BattleScript_RedCardSuctionCups
	jumpiftargetdynamaxed BattleScript_RedCardDynamaxed
	removeitem BS_SCRIPTING
	setbyte sSWITCH_CASE, B_SWITCH_RED_CARD
	forcerandomswitch BattleScript_RedCardEnd
	@ changes the current battle script. the rest happens in BattleScript_RoarSuccessSwitch_Ret, if switch is successful
BattleScript_RedCardIngrain:
	printstring STRINGID_PKMNANCHOREDITSELF
BattleScript_RedCardIngrainContinue:
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	goto BattleScript_RedCardEnd
BattleScript_RedCardSuctionCups:
	printstring STRINGID_PKMNANCHORSITSELFWITH
	goto BattleScript_RedCardIngrainContinue
BattleScript_RedCardDynamaxed:
	printstring STRINGID_MOVEBLOCKEDBYDYNAMAX
	goto BattleScript_RedCardIngrainContinue

BattleScript_RedCardEnd:
	restoretarget
	restoreattacker
	return

BattleScript_EjectItemActivates::
	makevisible BS_ATTACKER
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_EJECTBUTTONACTIVATE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	undodynamax BS_SCRIPTING
	makeinvisible BS_SCRIPTING
	returntoball BS_SCRIPTING, FALSE
	switchoutabilities BS_SCRIPTING
	return

BattleScript_EjectPackActivates_SendReplacement::
	call BattleScript_EjectItemActivates
	goto BattleScript_QueuedSwitchOpenPartyScreen

BattleScript_DoesntAffectTargetAtkString::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	setmoveresultflags MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd

BattleScript_DoesntAffectScripting::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECTSCR
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PastelVeilActivates::
	setbyte gBattleCommunication, 0
	setbyte gBattleCommunication + 1, 0
BattleScript_PastelVeil_TryCurePoison:
	jumpifstatus BS_TARGET, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_PastelVeilCurePoison
	goto BattleScript_PastelVeilLoopIncrement
BattleScript_PastelVeilCurePoison:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication + 1, 0x0, BattleScript_PastelVeilCurePoisonNoPopUp
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication + 1, 1
BattleScript_PastelVeilCurePoisonNoPopUp: @ Only show Pastel Veil pop up once if it cures two mons
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
BattleScript_PastelVeilLoopIncrement:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0x0, BattleScript_PastelVeilEnd
	addbyte gBattleCommunication, 1
	jumpifnoally BS_TARGET, BattleScript_PastelVeilEnd
	setallytonexttarget BattleScript_PastelVeil_TryCurePoison
	goto BattleScript_PastelVeilEnd
BattleScript_PastelVeilEnd:
	restoretarget
	return

BattleScript_NeutralizingGasExits::
    copybyte sSAVED_BATTLER, sBATTLER
    savetarget
    pause B_WAIT_TIME_SHORT
    printstring STRINGID_NEUTRALIZINGGASOVER
    waitmessage B_WAIT_TIME_LONG
    setbyte gBattlerTarget, 0
    sortbattlers
BattleScript_NeutralizingGasExitsLoop:
    copyarraywithindex gEffectBattler, gBattlersBySpeed, gBattlerTarget, 1
    jumpifabilitycantbereactivated BS_EFFECT_BATTLER, BattleScript_NeutralizingGasExitsLoopIncrement
    switchinabilities BS_EFFECT_BATTLER
BattleScript_NeutralizingGasExitsLoopIncrement:
    addbyte gBattlerTarget, 1
    jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_NeutralizingGasExitsLoop
    restoretarget
    copybyte sBATTLER, sSAVED_BATTLER
    return

BattleScript_MagicianActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_ItemSteal
	return

BattleScript_SymbiosisActivates::
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_SYMBIOSISITEMPASS
	waitmessage B_WAIT_TIME_LONG
	tryactivateabilitywithabilityshield BS_EFFECT_BATTLER, FALSE
	return

BattleScript_MoveEffectSetWeather::
	playanimation 0, B_ANIM_MAX_SET_WEATHER
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_MoveEffectSetTerrain::
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	return

BattleScript_MoveEffectDamageNonTypes::
	printfromtable gDamageNonTypesStartStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DamageNonTypesContinues::
	printfromtable gDamageNonTypesDmgStringIds
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	goto BattleScript_DoTurnDmg

BattleScript_MoveEffectSpite::
	savetarget
	copybyte gBattlerTarget, gEffectBattler
	tryspiteppreduce BattleScript_MoveEffectSpiteRet
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveEffectSpiteRet:
	restoretarget
	return

BattleScript_EffectParalyzeSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_ParalyzeSideLoop:
	jumpifabsent BS_TARGET, BattleScript_ParalyzeSideIncrement
	trysetparalysis BattleScript_ParalyzeSideIncrement
BattleScript_ParalyzeSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_ParalyzeSideEnd
	setallytonexttarget BattleScript_ParalyzeSideLoop
BattleScript_ParalyzeSideEnd:
	restoretarget
	return

BattleScript_EffectPoisonSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_PoisonSideLoop:
	jumpifabsent BS_TARGET, BattleScript_PoisonSideIncrement
	trysetpoison BattleScript_PoisonSideIncrement
BattleScript_PoisonSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_PoisonSideEnd
	setallytonexttarget BattleScript_PoisonSideLoop
BattleScript_PoisonSideEnd:
	restoretarget
	return

BattleScript_EffectPoisonParalyzeSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_PoisonParalyzeSideLoop:
	jumpifabsent BS_TARGET, BattleScript_PoisonParalyzeSideIncrement
	trysetpoisonparalysis BattleScript_PoisonParalyzeSideIncrement
BattleScript_PoisonParalyzeSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_PoisonParalyzeSideEnd
	setallytonexttarget BattleScript_PoisonParalyzeSideLoop
BattleScript_PoisonParalyzeSideEnd:
	restoretarget
	return

BattleScript_EffectEffectSporeSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_EffectSporeSideLoop:
	jumpifabsent BS_TARGET, BattleScript_EffectSporeSideIncrement
	tryseteffectspore BattleScript_EffectSporeSideIncrement
BattleScript_EffectSporeSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_EffectSporeSideEnd
	setallytonexttarget BattleScript_EffectSporeSideLoop
BattleScript_EffectSporeSideEnd:
	restoretarget
	return

BattleScript_EffectConfuseSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_ConfuseSideLoop:
	jumpifabsent BS_TARGET, BattleScript_ConfuseSideIncrement
	trysetconfusion BattleScript_ConfuseSideIncrement
	volatileanimation BS_TARGET, VOLATILE_CONFUSION
BattleScript_ConfuseSidePrintMessage:
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
BattleScript_ConfuseSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_ConfuseSideEnd
	setallytonexttarget BattleScript_ConfuseSideLoop
BattleScript_ConfuseSideEnd:
	restoretarget
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_PrintCoinsScattered @ Gold Rush
	return

BattleScript_PrintCoinsScattered:
	printstring STRINGID_COINSSCATTERED
	return

BattleScript_EffectInfatuateSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_InfatuateSideLoop:
	jumpifabsent BS_TARGET, BattleScript_InfatuateSideIncrement
	trysetinfatuation BattleScript_InfatuateSideIncrement
	volatileanimation BS_TARGET, VOLATILE_INFATUATION
BattleScript_InfatuateSidePrintMessage:
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage B_WAIT_TIME_LONG
BattleScript_InfatuateSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_InfatuateSideEnd
	setallytonexttarget BattleScript_InfatuateSideLoop
BattleScript_InfatuateSideEnd:
	restoretarget
	return

BattleScript_EffectTormentSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_TormentSideLoop:
	jumpifabsent BS_TARGET, BattleScript_TormentSideIncrement
	trysettorment BattleScript_TormentSideIncrement
BattleScript_TormentSidePrintMessage:
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage B_WAIT_TIME_LONG
BattleScript_TormentSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_TormentSideEnd
	setallytonexttarget BattleScript_TormentSideLoop
BattleScript_TormentSideEnd:
	restoretarget
	return

BattleScript_TormentEnds::
	printstring STRINGID_TORMENTEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectMeanLookSide::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_MeanLookSideLoop:
	jumpifabsent BS_TARGET, BattleScript_MeanLookSideIncrement
	trysetescapeprevention BattleScript_MeanLookSideIncrement
BattleScript_MeanLookSidePrintMessage:
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage B_WAIT_TIME_LONG
BattleScript_MeanLookSideIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_MeanLookSideEnd
	setallytonexttarget BattleScript_MeanLookSideLoop
BattleScript_MeanLookSideEnd:
	restoretarget
	return

BattleScript_EffectRaiseCritAlliesAnim::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_RaiseCritAlliesLoop:
	jumpifabsent BS_TARGET, BattleScript_RaiseCritAlliesIncrement
    raisecritstatchangeanim  BS_TARGET
	printstring STRINGID_PKMNGETTINGPUMPED
	waitmessage B_WAIT_TIME_LONG
BattleScript_RaiseCritAlliesIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_RaiseCritAlliesEnd
	setallytonexttarget BattleScript_RaiseCritAlliesLoop
BattleScript_RaiseCritAlliesEnd:
	restoretarget
	return

BattleScript_EffectHealOneSixthAllies::
	jumpifteamhealthy BattleScript_MoveEnd
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_HealOneSixthAlliesLoop:
	jumpifabsent BS_TARGET, BattleScript_HealOneSixthAlliesIncrement
	tryhealsixthhealth BattleScript_HealOneSixthAlliesIncrement
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET, ASSURANCE_DOUBLE
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_HealOneSixthAlliesIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_HealOneSixthAlliesEnd
	setallytonexttarget BattleScript_HealOneSixthAlliesLoop
BattleScript_HealOneSixthAlliesEnd:
	restoretarget
	return

BattleScript_EffectRecycleBerriesAllies::
	savetarget
	copybyte sBATTLER, gEffectBattler
	copybyte gBattlerTarget, gEffectBattler
BattleScript_RecycleBerriesAlliesLoop:
	jumpifabsent BS_TARGET, BattleScript_RecycleBerriesAlliesIncrement
	tryrecycleberry BattleScript_RecycleBerriesAlliesIncrement
	swapattackerwithtarget
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
BattleScript_RecycleBerriesAlliesIncrement:
	jumpifbytenotequal gBattlerTarget, sBATTLER, BattleScript_RecycleBerriesAlliesEnd
	setallytonexttarget BattleScript_RecycleBerriesAlliesLoop
BattleScript_RecycleBerriesAlliesEnd:
	restoretarget
	return

BattleScript_MoveEffectSteelsurge::
	setsteelsurge BattleScript_MoveEnd
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

@@@ END MAX MOVES @@@

BattleScript_DynamaxBegins::
	flushtextbox
	jumpifcangigantamax BS_ATTACKER, BattleScript_DynamaxBegins_GigantamaxString_01
	printstring STRINGID_TIMETODYNAMAX
	waitmessage B_WAIT_TIME_MED
	goto BattleScript_DynamaxBegins_SwitchIn
BattleScript_DynamaxBegins_GigantamaxString_01:
	printstring STRINGID_TIMETOGIGANTAMAX
	waitmessage B_WAIT_TIME_MED
BattleScript_DynamaxBegins_SwitchIn:
	returnatktoball
	pause B_WAIT_TIME_SHORT
	returntoball BS_SCRIPTING, TRUE
	switchinanim BS_SCRIPTING, TRUE, TRUE
	updatedynamax
	playanimation BS_SCRIPTING, B_ANIM_DYNAMAX_GROWTH
	waitanimation
	jumpifbyteequal B_SHOW_DYNAMAX_MESSAGE, FALSE, BattleScript_DynamaxBegins_Ret
	jumpifcangigantamax BS_ATTACKER, BattleScript_DynamaxBegins_GigantamaxString_02
	printstring STRINGID_PKMNDYNAMAXED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DynamaxBegins_Ret
BattleScript_DynamaxBegins_GigantamaxString_02:
	printstring STRINGID_PKMNGIGANTAMAXED
	waitmessage B_WAIT_TIME_LONG
BattleScript_DynamaxBegins_Ret:
	end3

BattleScript_DynamaxEnds::
	flushtextbox
	updatedynamax
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	return

BattleScript_DynamaxEnds_Ret::
	flushtextbox
	updatedynamax
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE
	waitanimation
	pause B_WAIT_TIME_SHORT
	return

BattleScript_MoveBlockedByDynamax::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MOVEBLOCKEDBYDYNAMAX
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PokemonCantUseTheMove::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTPOKEMONCANTUSETHEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd


BattleScript_BattlerAvoidedAttack::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BATTLERAVOIDEDATTACK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TargetAvoidsAttack::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNAVOIDEDATTACK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TargetProtected::
	pause B_WAIT_TIME_SHORT
	playanimation BS_SCRIPTING, B_ANIM_PROTECTED_ITSELF
	waitanimation
	printstring STRINGID_PKMNPROTECTEDITSELF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_UnseenFist::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
BattleScript_CouldntFullyProtect::
	printstring STRINGID_COULDNTFULLYPROTECT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BerserkGene::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	trybattlerstatchange BS_SCRIPTING, STAT_CHANGE_ITEM
	jumpifability BS_SCRIPTING, ABILITY_OWN_TEMPO, BattleScript_BerserkGene_OwnTempoPrevents
	jumpifsafeguard BattleScript_BerserkGene_SafeguardProtected
	seteffectprimary BS_SCRIPTING, BS_SCRIPTING, MOVE_EFFECT_CONFUSION
	jumpifvolatile BS_SCRIPTING, VOLATILE_CONFUSION, BattleScript_BerserkGene_Confuse
	goto BattleScript_BerserkGene_End
BattleScript_BerserkGene_SafeguardProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_BerserkGene_End
BattleScript_BerserkGene_OwnTempoPrevents:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
BattleScript_BerserkGene_End:
	removeitem BS_SCRIPTING
	return

BattleScript_BerserkGene_Confuse::
	volatileanimation BS_SCRIPTING, VOLATILE_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
    goto BattleScript_BerserkGene_End

BattleScript_BoosterEnergy::
	call BattleScript_ItemPopUp_Scripting
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_BOOSTERENERGYACTIVATES
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	removeitem BS_SCRIPTING
	return

BattleScript_SleepClauseBlocked::
	pause B_WAIT_TIME_SHORT
	setmoveresultflags MOVE_RESULT_FAILED
	printstring STRINGID_BLOCKEDBYSLEEPCLAUSE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SleepClausePrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BLOCKEDBYSLEEPCLAUSE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_QuestionForfeitBattle::
	printselectionstring STRINGID_QUESTIONFORFEITBATTLE
	forfeityesnobox
	endselectionscript

BattleScript_ForfeitBattleGaveMoney::
	getmoneyreward
.if B_WHITEOUT_MONEY >= GEN_4
	printstring STRINGID_PLAYERWHITEOUT2_TRAINER
.else
	printstring STRINGID_PLAYERWHITEOUT3
.endif
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_Attackstring::
	printattackstring
	return

BattleScript_SubmoveAttackstring::
	printattackstring
	pause B_WAIT_TIME_LONG
	attackanimation
	waitanimation
	setcalledmove
	return

BattleScript_SleepTalkAttackstring::
	printattackstring
	pause B_WAIT_TIME_LONG
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	attackanimation
	waitanimation
	setcalledmove
	return

BattleScript_MetronomeAttackstring::
	printattackstring
	pause B_WAIT_TIME_LONG
	attackanimation
	waitanimation
	setcalledmove
	printstring STRINGID_WAGGLINGAFINGER
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_NaturePowerAttackstring::
	printattackstring
	pause B_WAIT_TIME_SHORT
	setcalledmove
	printstring STRINGID_NATUREPOWERTURNEDINTO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SwapFromSubstitute::
	jumpifvolatile BS_SCRIPTING, VOLATILE_SUBSTITUTE, BattleScript_SwapFromSubstituteContinue
	goto BattleScript_SwapFromSubstituteReturn
BattleScript_SwapFromSubstituteContinue:
	playanimation BS_SCRIPTING, B_ANIM_SWAP_FROM_SUBSTITUTE
	waitanimation
BattleScript_SwapFromSubstituteReturn:
	return

BattleScript_SwapToSubstitute::
	jumpifvolatile BS_SCRIPTING, VOLATILE_SUBSTITUTE, BattleScript_SwapToSubstituteContinue
	goto BattleScript_SwapToSubstituteReturn
BattleScript_SwapToSubstituteContinue:
	playanimation BS_SCRIPTING, B_ANIM_SWAP_TO_SUBSTITUTE
	waitanimation
BattleScript_SwapToSubstituteReturn:
	return

BattleScript_TooScaredToMove::
	printstring STRINGID_MONTOOSCAREDTOMOVE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_MON_SCARED
	goto BattleScript_MoveEnd

BattleScript_GhostGetOutGetOut::
	printstring STRINGID_GHOSTGETOUTGETOUT
	playanimation BS_ATTACKER, B_ANIM_GHOST_GET_OUT
	goto BattleScript_MoveEnd

BattleScript_SilphScopeUnveiled::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_SILPHSCOPEUNVEILED
	waitstate
	playanimation BS_OPPONENT1, B_ANIM_SILPH_SCOPED
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_GHOSTWASMAROWAK
	waitmessage B_WAIT_TIME_LONG
	end

BattleScript_WildBattleVictory::
	playfaintcry BS_TARGET
	waitcry
	jumpifnoballs BattleScript_WildBattleVictoryRet
	printstring STRINGID_VICTORYCATCH
	setbyte gBattleCommunication, 0
	catchornot
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication + 1, 0, BattleScript_WildBattleVictoryRet
	catchaftervictory
	return

BattleScript_WildBattleVictoryRet:
	handlefailedvictorycatch
	return

BattleScript_BelchFails::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BELCHCANTSELECT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

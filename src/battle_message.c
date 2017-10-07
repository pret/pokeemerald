#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_string_ids.h"
#include "moves.h"
#include "text.h"
#include "string_util.h"

extern u16 gLastUsedItem;
extern u8 gLastUsedAbility;
extern u8 gActiveBank;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gStringBank;
extern u8 gEffectBank;
extern u8 gAbilitiesPerBank[BATTLE_BANKS_COUNT];
extern u32 gBattleTypeFlags;
extern u16 gTrainerBattleOpponent_A;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern struct BattleEnigmaBerry gEnigmaBerries[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];

extern const u8 gMoveNames[LAST_MOVE_INDEX + 1][13];

// strings
extern const u8 gText_PkmnBoxSomeonesPCFull[];
extern const u8 gText_PkmnBoxLanettesPCFull[];
extern const u8 gText_PkmnTransferredSomeonesPC[];
extern const u8 gText_PkmnTransferredLanettesPC[];

// this file's functions
void sub_814F8F8(u8 *txtPtr);
void sub_814F950(u8 *txtPtr);

// ewram variables
EWRAM_DATA u8 gDisplayedStringBattle[300] = {0};
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT] = {0};

// const rom data

const u8 gText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
const u8 gText_PkmnGainedEXP[] = _("{B_BUFF1} gained{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
const u8 gText_EmptyString4[] = _("");
const u8 gText_ABoosted[] = _(" a boosted");
const u8 gText_PkmnGrewToLv[] = _("{B_BUFF1} grew to\nLV. {B_BUFF2}!{UNKNOWN_A}\p");
const u8 gText_PkmnLearnedMove[] = _("{B_BUFF1} learned\n{B_BUFF2}!{UNKNOWN_A}\p");
const u8 gText_TryToLearnMove1[] = _("{B_BUFF1} is trying to\nlearn {B_BUFF2}.\p");
const u8 gText_TryToLearnMove2[] = _("But, {B_BUFF1} can’t learn\nmore than four moves.\p");
const u8 gText_TryToLearnMove3[] = _("Delete a move to make\nroom for {B_BUFF2}?");
const u8 gText_PkmnForgotMove[] = _("{B_BUFF1} forgot\n{B_BUFF2}.\p");
const u8 gText_StopLearningMove[] = _("{PAUSE 32}Stop learning\n{B_BUFF2}?");
const u8 gText_DidNotLearnMove[] = _("{B_BUFF1} did not learn\n{B_BUFF2}.\p");
const u8 gText_UseNextPkmn[] = _("Use next POKéMON?");
const u8 gText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX}’s\nattack missed!");
const u8 gText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX}\nprotected itself!");
const u8 gText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} avoided\ndamage with {B_DEF_ABILITY}!");
const u8 gText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX} makes GROUND\nmoves miss with {B_DEF_ABILITY}!");
const u8 gText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} avoided\nthe attack!");
const u8 gText_ItDoesntAffect[] = _("It doesn’t affect\n{B_DEF_NAME_WITH_PREFIX}…");
const u8 gText_PkmnFainted[] = _("{B_ATK_NAME_WITH_PREFIX}\nfainted!\p");
const u8 gText_PkmnFainted2[] = _("{B_DEF_NAME_WITH_PREFIX}\nfainted!\p");
const u8 gText_PlayerGotMoney[] = _("{B_PLAYER_NAME} got ¥{B_BUFF1}\nfor winning!\p");
const u8 gText_PlayerWhiteout[] = _("{B_PLAYER_NAME} is out of\nusable POKéMON!\p");
const u8 gText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} whited out!{PAUSE_UNTIL_PRESS}");
const u8 gText_PreventsEscape[] = _("{B_ACTIVE_NAME_WITH_PREFIX} prevents\nescape with {B_SCR_ACTIVE_ABILITY}!\p");
const u8 gText_CantEscape2[] = _("Can’t escape!\p");
const u8 gText_PkmnCantEscape2[] = _("{B_ATK_NAME_WITH_PREFIX} can’t escape!");
const u8 gText_HitXTimes[] = _("Hit {B_BUFF1} time(s)!");
const u8 gText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\nfell asleep!");
const u8 gText_PkmnMadeSleep[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nmade {B_EFF_NAME_WITH_PREFIX} sleep!");
const u8 gText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready asleep!");
const u8 gText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} is\nalready asleep!");
const u8 gText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX}\nwasn’t affected!");
const u8 gText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nwas poisoned!");
const u8 gText_PkmnPoisonedBy[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\npoisoned {B_EFF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnHurtByPoison[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby poison!");
const u8 gText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} is already\npoisoned.");
const u8 gText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX} is badly\npoisoned!");
const u8 gText_PkmnEnergyDrained[] = _("{B_DEF_NAME_WITH_PREFIX} had its\nenergy drained!");
const u8 gText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} was burned!");
const u8 gText_PkmnBurnedBy[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nburned {B_EFF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby its burn!");
const u8 gText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} already\nhas a burn.");
const u8 gText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} was\nfrozen solid!");
const u8 gText_PkmnFrozenBy[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nfroze {B_EFF_NAME_WITH_PREFIX} solid!");
const u8 gText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} is\nfrozen solid!");
const u8 gText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} was\ndefrosted!");
const u8 gText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted!");
const u8 gText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted by {B_CURRENT_MOVE}!");
const u8 gText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} is paralyzed!\nIt may be unable to move!");
const u8 gText_PkmnWasParalyzedBy[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nparalyzed {B_EFF_NAME_WITH_PREFIX}!\lIt may be unable to move!");
const u8 gText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} is paralyzed!\nIt can’t move!");
const u8 gText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready paralyzed!");
const u8 gText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX} was\nhealed of paralysis!");
const u8 gText_PkmnDreamEaten[] = _("{B_DEF_NAME_WITH_PREFIX}’s\ndream was eaten!");
const u8 gText_StatsWontIncrease[] = _("{B_ATK_NAME_WITH_PREFIX}’s {B_BUFF1}\nwon’t go higher!");
const u8 gText_StatsWontDecrease[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_BUFF1}\nwon’t go lower!");
const u8 gText_TeamStoppedWorking[] = _("Your team’s {B_BUFF1}\nstopped working!");
const u8 gText_FoeStoppedWorking[] = _("The foe’s {B_BUFF1}\nstopped working!");
const u8 gText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} is\nconfused!");
const u8 gText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} snapped\nout of confusion!");
const u8 gText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX} became\nconfused!");
const u8 gText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready confused!");
const u8 gText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX}\nfell in love!");
const u8 gText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} is in love\nwith {B_ACTIVE_NAME_WITH_PREFIX}!");
const u8 gText_PkmnImmobilizedByLove[] = _("{B_ATK_NAME_WITH_PREFIX} is\nimmobilized by love!");
const u8 gText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} was\nblown away!");
const u8 gText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} transformed\ninto the {B_BUFF1} type!");
const u8 gText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} flinched!");
const u8 gText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} regained\nhealth!");
const u8 gText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX}’s\nHP is full!");
const u8 gText_PkmnRaisedSpDef[] = _("{B_ATK_PREFIX2}’s {B_CURRENT_MOVE}\nraised SP. DEF!");
const u8 gText_PkmnRaisedSpDefALittle[] = _("{B_ATK_PREFIX2}’s {B_CURRENT_MOVE}\nraised SP. DEF a little!");
const u8 gText_PkmnRaisedDef[] = _("{B_ATK_PREFIX2}’s {B_CURRENT_MOVE}\nraised DEFENSE!");
const u8 gText_PkmnRaisedDefALittle[] = _("{B_ATK_PREFIX2}’s {B_CURRENT_MOVE}\nraised DEFENSE a little!");
const u8 gText_PkmnCoveredByVeil[] = _("{B_ATK_PREFIX2}’s party is covered\nby a veil!");
const u8 gText_PkmnUsedSafeguard[] = _("{B_DEF_NAME_WITH_PREFIX}’s party is protected\nby SAFEGUARD!");
const u8 gText_PkmnSafeguardExpired[] = _("{B_ATK_PREFIX3}’s party is no longer\nprotected by SAFEGUARD!");
const u8 gText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} went\nto sleep!");
const u8 gText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX} slept and\nbecame healthy!");
const u8 gText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX} whipped\nup a whirlwind!");
const u8 gText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} took\nin sunlight!");
const u8 gText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} lowered\nits head!");
const u8 gText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} is glowing!");
const u8 gText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} flew\nup high!");
const u8 gText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} dug a hole!");
const u8 gText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} hid\nunderwater!");
const u8 gText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} sprang up!");
const u8 gText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX} was squeezed by\n{B_ATK_NAME_WITH_PREFIX}’s BIND!");
const u8 gText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped\nin the vortex!");
const u8 gText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped\nby SAND TOMB!");
const u8 gText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was WRAPPED by\n{B_ATK_NAME_WITH_PREFIX}!");
const u8 gText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} CLAMPED\n{B_DEF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby {B_BUFF1}!");
const u8 gText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} was freed\nfrom {B_BUFF1}!");
const u8 gText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX} kept going\nand crashed!");
const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_PREFIX2} became\nshrouded in MIST!");
const u8 gText_PkmnProtectedByMist[] = _("{B_ACTIVE_NAME_WITH_PREFIX} is protected\nby MIST!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX} is getting\npumped!");
const u8 gText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX} is hit\nwith recoil!");
const u8 gText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX} protected\nitself!");
const u8 gText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} is buffeted\nby the sandstorm!");
const u8 gText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} is pelted\nby HAIL!");
const u8 gText_PkmnsXWoreOff[] = _("{B_ATK_PREFIX1}’s {B_BUFF1}\nwore off!");
const u8 gText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} was seeded!");
const u8 gText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} evaded\nthe attack!");
const u8 gText_PkmnSappedByLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}’s health is\nsapped by LEECH SEED!");
const u8 gText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} is fast\nasleep.");
const u8 gText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} woke up!");
const u8 gText_PkmnUproarKeptAwake[] = _("But {B_ACTIVE_NAME_WITH_PREFIX}’s UPROAR\nkept it awake!");
const u8 gText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} woke up\nin the UPROAR!");
const u8 gText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} caused\nan UPROAR!");
const u8 gText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} is making\nan UPROAR!");
const u8 gText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} calmed down.");
const u8 gText_PkmnCantSleepInUproar[] = _("But {B_DEF_NAME_WITH_PREFIX} can’t\nsleep in an UPROAR!");
const u8 gText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} STOCKPILED\n{B_BUFF1}!");
const u8 gText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} can’t\nSTOCKPILE any more!");
const u8 gText_PkmnCantSleepInUproar2[] = _("But {B_DEF_NAME_WITH_PREFIX} can’t\nsleep in an UPROAR!");
const u8 gText_UproarKeptPkmnAwake[] = _("But the UPROAR kept\n{B_DEF_NAME_WITH_PREFIX} awake!");
const u8 gText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} stayed awake\nusing its {B_DEF_ABILITY}!");
const u8 gText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} is storing\nenergy!");
const u8 gText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} unleashed\nenergy!");
const u8 gText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} became\nconfused due to fatigue!");
const u8 gText_PkmnPickedUpItem[] = _("{B_PLAYER_NAME} picked up\n¥{B_BUFF1}!\p");
const u8 gText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX} is\nunaffected!");
const u8 gText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} transformed\ninto {B_BUFF1}!");
const u8 gText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} made\na SUBSTITUTE!");
const u8 gText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} already\nhas a SUBSTITUTE!");
const u8 gText_SubstituteDamaged[] = _("The SUBSTITUTE took damage\nfor {B_DEF_NAME_WITH_PREFIX}!\p");
const u8 gText_PkmnSubstituteFaded[] = _("{B_DEF_NAME_WITH_PREFIX}’s\nSUBSTITUTE faded!\p");
const u8 gText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} must\nrecharge!");
const u8 gText_PkmnRageBuilding[] = _("{B_DEF_NAME_WITH_PREFIX}’s RAGE\nis building!");
const u8 gText_PkmnMoveWasDisabled[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_BUFF1}\nwas disabled!");
const u8 gText_PkmnMoveDisabledNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} is disabled\nno more!");
const u8 gText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX} got\nan ENCORE!");
const u8 gText_PkmnEncoreEnded[] = _("{B_ATK_NAME_WITH_PREFIX}’s ENCORE\nended!");
const u8 gText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} took aim\nat {B_DEF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} SKETCHED\n{B_BUFF1}!");
const u8 gText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} is trying\nto take its foe with it!");
const u8 gText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} took\n{B_ATK_NAME_WITH_PREFIX} with it!");
const u8 gText_PkmnReducedPP[] = _("Reduced {B_DEF_NAME_WITH_PREFIX}’s\n{B_BUFF1} by {B_BUFF2}!");
const u8 gText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} stole\n{B_DEF_NAME_WITH_PREFIX}’s {B_LAST_ITEM}!");
const u8 gText_PkmnCantEscape[] = _("{B_DEF_NAME_WITH_PREFIX} can’t\nescape now!");
const u8 gText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} fell into\na NIGHTMARE!");
const u8 gText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} is locked\nin a NIGHTMARE!");
const u8 gText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP and\nlaid a CURSE on {B_DEF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} is afflicted\nby the CURSE!");
const u8 gText_SpikesScattered[] = _("SPIKES were scattered all around\nthe opponent’s side!");
const u8 gText_PkmnHurtBySpikes[] = _("{B_ACTIVE_NAME_WITH_PREFIX} is hurt\nby SPIKES!");
const u8 gText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identified\n{B_DEF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnPerishCountFell[] = _("{B_ATK_NAME_WITH_PREFIX}’s PERISH count\nfell to {B_BUFF1}!");
const u8 gText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} braced\nitself!");
const u8 gText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} ENDURED\nthe hit!");
const u8 gText_MagnitudeStrength[] = _("MAGNITUDE {B_BUFF1}!");
const u8 gText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP\nand maximized ATTACK!");
const u8 gText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}’s stat changes!");
const u8 gText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} got free of\n{B_DEF_NAME_WITH_PREFIX}’s {B_BUFF1}!");
const u8 gText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX} shed\nLEECH SEED!");
const u8 gText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX} blew away\nSPIKES!");
const u8 gText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} fled from\nbattle!");
const u8 gText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} foresaw\nan attack!");
const u8 gText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} took the\n{B_BUFF1} attack!");
const u8 gText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} chose\n{B_CURRENT_MOVE} as its destiny!");
const u8 gText_PkmnAttack[] = _("{B_BUFF1}’s attack!");
const u8 gText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX} became the\ncenter of attention!");
const u8 gText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX} began\ncharging power!");
const u8 gText_NaturePowerTurnedInto[] = _("NATURE POWER turned into\n{B_CURRENT_MOVE}!");
const u8 gText_PkmnStatusNormal[] = _("{B_ATK_NAME_WITH_PREFIX}’s status\nreturned to normal!");
const u8 gText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} was subjected\nto TORMENT!");
const u8 gText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} is tightening\nits focus!");
const u8 gText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX} fell for\nthe TAUNT!");
const u8 gText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} is ready to\nhelp {B_DEF_NAME_WITH_PREFIX}!");
const u8 gText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} switched\nitems with its opponent!");
const u8 gText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.");
const u8 gText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
const u8 gText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
const u8 gText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}!");
const u8 gText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} made a WISH!");
const u8 gText_PkmnWishCameTrue[] = _("{B_BUFF1}’s WISH\ncame true!");
const u8 gText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} planted its roots!");
const u8 gText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} absorbed\nnutrients with its roots!");
const u8 gText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} anchored\nitself with its roots!");
const u8 gText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} made\n{B_DEF_NAME_WITH_PREFIX} drowsy!");
const u8 gText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} knocked off\n{B_DEF_NAME_WITH_PREFIX}’s {B_LAST_ITEM}!");
const u8 gText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} swapped abilities\nwith its opponent!");
const u8 gText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} sealed the\nopponent’s move(s)!");
const u8 gText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} wants the\nopponent to bear a GRUDGE!");
const u8 gText_PkmnLostPPGrudge[] = _("{B_ATK_NAME_WITH_PREFIX}’s {B_BUFF1} lost\nall its PP due to the GRUDGE!");
const u8 gText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} shrouded\nitself in {B_CURRENT_MOVE}!");
const u8 gText_PkmnMoveBounced[] = _("{B_ATK_NAME_WITH_PREFIX}’s {B_CURRENT_MOVE}\nwas bounced back by MAGIC COAT!");
const u8 gText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} waits for a target\nto make a move!");
const u8 gText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} SNATCHED\n{B_ACTIVE_NAME_WITH_PREFIX}’s move!");
const u8 gText_ElectricityWeakened[] = _("Electricity’s power was\nweakened!");
const u8 gText_FireWeakened[] = _("Fire’s power was\nweakened!");
const u8 gText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX} found\none {B_LAST_ITEM}!");
const u8 gText_SoothingAroma[] = _("A soothing aroma wafted\nthrough the area!");
const u8 gText_ItemsCantBeUsedNow[] = _("Items can’t be used now.{PAUSE 64}");
const u8 gText_ForXCommaYZ[] = _("For {B_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}");
const u8 gText_PkmnUsedXToGetPumped[] = _("{B_ACTIVE_NAME_WITH_PREFIX} used\n{B_LAST_ITEM} to get pumped!");
const u8 gText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} lost its\nfocus and couldn’t move!");
const u8 gText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} was\ndragged out!\p");
const u8 gText_TheWallShattered[] = _("The wall shattered!");
const u8 gText_ButNoEffect[] = _("But it had no effect!");
const u8 gText_PkmnHasNoMovesLeft[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} has no\nmoves left!\p");
const u8 gText_PkmnMoveIsDisabled[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}’s {B_CURRENT_MOVE}\nis disabled!\p");
const u8 gText_PkmnCantUseMoveTorment[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} can’t use the same\nmove in a row due to the TORMENT!\p");
const u8 gText_PkmnCantUseMoveTaunt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} can’t use\n{B_CURRENT_MOVE} after the TAUNT!\p");
const u8 gText_PkmnCantUseMoveSealed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} can’t use the\nsealed {B_CURRENT_MOVE}!\p");
const u8 gText_PkmnMadeItRain[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nmade it rain!");
const u8 gText_PkmnRaisedSpeed[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nraised its SPEED!");
const u8 gText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was protected\nby {B_DEF_ABILITY}!");
const u8 gText_PkmnPreventsUsage[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!");
const u8 gText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} restored HP\nusing its {B_DEF_ABILITY}!");
const u8 gText_PkmnsXMadeYUseless[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} useless!");
const u8 gText_PkmnChangedTypeWith[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nmade it the {B_BUFF1} type!");
const u8 gText_PkmnPreventsParalysisWith[] = _("{B_EFF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevents paralysis!");
const u8 gText_PkmnPreventsRomanceWith[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevents romance!");
const u8 gText_PkmnPreventsPoisoningWith[] = _("{B_EFF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevents poisoning!");
const u8 gText_PkmnPreventsConfusionWith[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevents confusion!");
const u8 gText_PkmnRaisedFirePowerWith[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nraised its FIRE power!");
const u8 gText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} anchors\nitself with {B_DEF_ABILITY}!");
const u8 gText_PkmnCutsAttackWith[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\ncuts {B_DEF_NAME_WITH_PREFIX}’s ATTACK!");
const u8 gText_PkmnPreventsStatLossWith[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nprevents stat loss!");
const u8 gText_PkmnHurtsWith[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nhurt {B_ATK_NAME_WITH_PREFIX}!");
const u8 gText_PkmnTraced[] = _("{B_ACTIVE_NAME_WITH_PREFIX} TRACED\n{B_BUFF1}’s {B_BUFF2}!");
const u8 gText_PkmnsXPreventsBurns[] = _("{B_EFF_NAME_WITH_PREFIX}’s {STRING 27}\nprevents burns!");
const u8 gText_PkmnsXBlocksY[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nblocks {B_CURRENT_MOVE}!");
const u8 gText_PkmnsXBlocksY2[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nblocks {B_CURRENT_MOVE}!");
const u8 gText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_NAME_WITH_PREFIX}’s {STRING 24}\nrestored its HP a little!");
const u8 gText_PkmnsXWhippedUpSandstorm[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nwhipped up a sandstorm!");
const u8 gText_PkmnsXIntensifiedSun[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nintensified the sun’s rays!");
const u8 gText_PkmnsXPreventsYLoss[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nprevents {B_BUFF1} loss!");
const u8 gText_PkmnsXInfatuatedY[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\ninfatuated {B_ATK_NAME_WITH_PREFIX}!");
const u8 gText_PkmnsXMadeYIneffective[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} ineffective!");
const u8 gText_PkmnsXCuredYProblem[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
const u8 gText_ItSuckedLiquidOoze[] = _("It sucked up the\nLIQUID OOZE!");
const u8 gText_PkmnTransformed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} transformed!");
const u8 gText_PkmnsXTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\ntook the attack!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1}’s {STRING 23}\nprevents switching!\p");
const u8 gText_PreventedFromWorking[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_DEF_ABILITY}\nprevented {B_ACTIVE_NAME_WITH_PREFIX}’s\l{B_BUFF1} from working!");
const u8 gText_PkmnsXMadeItIneffective[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nmade it ineffective!");
const u8 gText_PkmnsXPreventsFlinching[] = _("{B_EFF_NAME_WITH_PREFIX}’s {STRING 27}\nprevents flinching!");
const u8 gText_PkmnsXPreventsYsZ[] = _("{B_ATK_NAME_WITH_PREFIX}’s {STRING 24}\nprevents {B_DEF_NAME_WITH_PREFIX}’s\l{B_DEF_ABILITY} from working!");
const u8 gText_PkmnsXCuredItsYProblem[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
const u8 gText_PkmnsXHadNoEffectOnY[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_SCR_ACTIVE_ABILITY}\nhad no effect on {B_EFF_NAME_WITH_PREFIX}!");
const u8 gText_StatSharply[] = _("sharply ");
const u8 gText_StatRose[] = _("rose!");
const u8 gText_StatHarshly[] = _("harshly ");
const u8 gText_StatFell[] = _("fell!");
const u8 gText_PkmnsStatChanged[] = _("{B_ATK_NAME_WITH_PREFIX}’s {B_BUFF1}\n{B_BUFF2}");
const u8 gText_PkmnsStatChanged2[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_BUFF1}\n{B_BUFF2}");
const u8 gText_UsingXTheYOfZN[] = _("Using {B_LAST_ITEM}, the {B_BUFF1}\nof {B_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
const u8 gText_PkmnsStatChanged3[] = _("{B_ATK_NAME_WITH_PREFIX}’s {B_BUFF1}\n{B_BUFF2}");
const u8 gText_PkmnsStatChanged4[] = _("{B_DEF_NAME_WITH_PREFIX}’s {B_BUFF1}\n{B_BUFF2}");
const u8 gText_StatsWontIncrease2[] = _("{B_ATK_NAME_WITH_PREFIX}’s stats won’t\ngo any higher!");
const u8 gText_StatsWontDecrease2[] = _("{B_DEF_NAME_WITH_PREFIX}’s stats won’t\ngo any lower!");
const u8 gText_CriticalHit[] = _("A critical hit!");
const u8 gText_OneHitKO[] = _("It’s a one-hit KO!");
const u8 gText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p");
const u8 gText_AndEllipsis[] = _("And…\p");
const u8 gText_HMMovesCantBeForgotten[] = _("HM moves can’t be\nforgotten now.\p");
const u8 gText_NotVeryEffective[] = _("It’s not very effective…");
const u8 gText_SuperEffective[] = _("It’s super effective!");
const u8 gText_GotAwaySafely[] = _("{PLAY_SE 0x0011}Got away safely!\p");
const u8 gText_PkmnFledUsingIts[] = _("{PLAY_SE 0x0011}{B_ATK_NAME_WITH_PREFIX} fled\nusing its {B_LAST_ITEM}!\p");
const u8 gText_PkmnFledUsing[] = _("{PLAY_SE 0x0011}{B_ATK_NAME_WITH_PREFIX} fled\nusing {STRING 24}!\p");
const u8 gText_WildPkmnFled[] = _("{PLAY_SE 0x0011}Wild {B_BUFF1} fled!");
const u8 gText_PlayerDefeatedLinkTrainer[] = _("Player defeated\n{B_20}!");
const u8 gText_TwoLinkTrainersDefeated[] = _("Player beat {B_20}\nand {B_21}!");
const u8 gText_PlayerLostAgainstLinkTrainer[] = _("Player lost against\n{B_20}!");
const u8 gText_PlayerLostToTwo[] = _("Player lost to {B_20}\nand {B_21}!");
const u8 gText_PlayerBattledToDrawLinkTrainer[] = _("Player battled to a draw against\n{B_20}!");
const u8 gText_PlayerBattledToDrawVsTwo[] = _("Player battled to a draw against\n{B_20} and {B_21}!");
const u8 gText_WildFled[] = _("{PLAY_SE 0x0011}{B_20} fled!");
const u8 gText_TwoWildFled[] = _("{PLAY_SE 0x0011}{B_20} and\n{B_21} fled!");
const u8 gText_NoRunningFromTrainers[] = _("No! There’s no running\nfrom a TRAINER battle!\p");
const u8 gText_CantEscape[] = _("Can’t escape!\p");
const u8 gText_DontLeaveBirch[] = _("PROF. BIRCH: Don’t leave me like this!\p");
const u8 gText_ButNothingHappened[] = _("But nothing happened!");
const u8 gText_ButItFailed[] = _("But it failed!");
const u8 gText_ItHurtConfusion[] = _("It hurt itself in its\nconfusion!");
const u8 gText_MirrorMoveFailed[] = _("The MIRROR MOVE failed!");
const u8 gText_StartedToRain[] = _("It started to rain!");
const u8 gText_DownpourStarted[] = _("A downpour started!");
const u8 gText_RainContinues[] = _("Rain continues to fall.");
const u8 gText_DownpourContinues[] = _("The downpour continues.");
const u8 gText_RainStopped[] = _("The rain stopped.");
const u8 gText_SandstormBrewed[] = _("A sandstorm brewed!");
const u8 gText_SandstormRages[] = _("The sandstorm rages.");
const u8 gText_SandstormSubsided[] = _("The sandstorm subsided.");
const u8 gText_SunlightGotBright[] = _("The sunlight got bright!");
const u8 gText_SunlightStrong[] = _("The sunlight is strong.");
const u8 gText_SunlightFaded[] = _("The sunlight faded.");
const u8 gText_StartedHail[] = _("It started to hail!");
const u8 gText_HailContinues[] = _("Hail continues to fall.");
const u8 gText_HailStopped[] = _("The hail stopped.");
const u8 gText_FailedToSpitUp[] = _("But it failed to SPIT UP\na thing!");
const u8 gText_FailedToSwallow[] = _("But it failed to SWALLOW\na thing!");
const u8 gText_WindBecameHeatWave[] = _("The wind turned into a\nHEAT WAVE!");
const u8 gText_StatChangesGone[] = _("All stat changes were\neliminated!");
const u8 gText_CoinsScattered[] = _("Coins scattered everywhere!");
const u8 gText_TooWeakForSubstitute[] = _("It was too weak to make\na SUBSTITUTE!");
const u8 gText_SharedPain[] = _("The battlers shared\ntheir pain!");
const u8 gText_BellChimed[] = _("A bell chimed!");
const u8 gText_FaintInThree[] = _("All affected POKéMON will\nfaint in three turns!");
const u8 gText_NoPPLeft[] = _("There’s no PP left for\nthis move!\p");
const u8 gText_ButNoPPLeft[] = _("But there was no PP left\nfor the move!");
const u8 gText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignored\norders while asleep!");
const u8 gText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignored\norders!");
const u8 gText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} began to nap!");
const u8 gText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} is\nloafing around!");
const u8 gText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} won’t\nobey!");
const u8 gText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} turned away!");
const u8 gText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} pretended\nnot to notice!");
const u8 gText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} is\nabout to use {B_BUFF2}.\pWill {B_PLAYER_NAME} change\nPOKéMON?");
const u8 gText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} learned\n{B_BUFF1}!");
const u8 gText_PlayerDefeatedLinkTrainerTrainer1[] = _("Player defeated\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
const u8 gText_CreptCloser[] = _("{B_PLAYER_NAME} crept closer to\n{B_OPPONENT_MON1_NAME}!");
const u8 gText_CantGetCloser[] = _("{B_PLAYER_NAME} can’t get any closer!");
const u8 gText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} is watching\ncarefully!");
const u8 gText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} is curious about\nthe {B_BUFF1}!");
const u8 gText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} is enthralled by\nthe {B_BUFF1}!");
const u8 gText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} completely ignored\nthe {B_BUFF1}!");
const u8 gText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} threw a {POKEBLOCK}\nat the {B_OPPONENT_MON1_NAME}!");
const u8 gText_OutOfSafariBalls[] = _("{PLAY_SE 0x0049}ANNOUNCER: You’re out of\nSAFARI BALLS! Game over!\p");
const u8 gText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
const u8 gText_WildPkmnAppeared[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
const u8 gText_WildPkmnAppeared2[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
const u8 gText_WildPkmnAppearedPause[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!{PAUSE 127}");
const u8 gText_TwoWildPkmnAppeared[] = _("Wild {B_OPPONENT_MON1_NAME} and\n{B_OPPONENT_MON2_NAME} appeared!\p");
const u8 gText_Trainer1WantsToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwould like to battle!\p");
const u8 gText_LinkTrainerWantsToBattle[] = _("{B_20}\nwants to battle!");
const u8 gText_TwoLinkTrainersWantToBattle[] = _("{B_20} and {B_21}\nwant to battle!");
const u8 gText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!");
const u8 gText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
const u8 gText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_BUFF1}!");
const u8 gText_LinkTrainerSentOutPkmn[] = _("{B_20} sent out\n{B_OPPONENT_MON1_NAME}!");
const u8 gText_LinkTrainerSentOutTwoPkmn[] = _("{B_20} sent out\n{B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
const u8 gText_TwoLinkTrainersSentOutPkmn[] = _("{B_20} sent out {B_LINK_OPPONENT_MON1_NAME}!\n{B_21} sent out {B_LINK_OPPONENT_MON2_NAME}!");
const u8 gText_LinkTrainerSentOutPkmn2[] = _("{B_20} sent out\n{B_BUFF1}!");
const u8 gText_LinkTrainerMultiSentOutPkmn[] = _("{B_22} sent out\n{B_BUFF1}!");
const u8 gText_GoPkmn[] = _("Go! {B_PLAYER_MON1_NAME}!");
const u8 gText_GoTwoPkmn[] = _("Go! {B_PLAYER_MON1_NAME} and\n{B_PLAYER_MON2_NAME}!");
const u8 gText_GoPkmn2[] = _("Go! {B_BUFF1}!");
const u8 gText_DoItPkmn[] = _("Do it! {B_BUFF1}!");
const u8 gText_GoForItPkmn[] = _("Go for it, {B_BUFF1}!");
const u8 gText_YourFoesWeakGetEmPkmn[] = _("Your foe’s weak!\nGet ’em, {B_BUFF1}!");
const u8 gText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_1F} sent out {B_LINK_PLAYER_MON2_NAME}!\nGo! {B_LINK_PLAYER_MON1_NAME}!");
const u8 gText_PkmnThatsEnough[] = _("{B_BUFF1}, that’s enough!\nCome back!");
const u8 gText_PkmnComeBack[] = _("{B_BUFF1}, come back!");
const u8 gText_PkmnOkComeBack[] = _("{B_BUFF1}, OK!\nCome back!");
const u8 gText_PkmnGoodComeBack[] = _("{B_BUFF1}, good!\nCome back!");
const u8 gText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwithdrew {B_BUFF1}!");
const u8 gText_LinkTrainer1WithdrewPkmn[] = _("{B_20} withdrew\n{B_BUFF1}!");
const u8 gText_LinkTrainer2WithdrewPkmn[] = _("{B_22} withdrew\n{B_BUFF1}!");
const u8 gText_WildPkmnPrefix[] = _("Wild ");
const u8 gText_FoePkmnPrefix[] = _("Foe ");
const u8 gText_EmptyString8[] = _( "");
const u8 gText_FoePkmnPrefix2[] = _("Foe");
const u8 gText_AllyPkmnPrefix[] = _("Ally");
const u8 gText_FoePkmnPrefix3[] = _("Foe");
const u8 gText_AllyPkmnPrefix2[] = _("Ally");
const u8 gText_FoePkmnPrefix4[] = _("Foe");
const u8 gText_AllyPkmnPrefix3[] = _("Ally");
const u8 gText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} used\n{B_BUFF2}");
const u8 gText_ExclamationMark[] = _("!");
const u8 gText_ExclamationMark2[] = _("!");
const u8 gText_ExclamationMark3[] = _("!");
const u8 gText_ExclamationMark4[] = _("!");
const u8 gText_ExclamationMark5[] = _("!");
const u8 gText_HP2[] = _("HP");
const u8 gText_Attack2[] = _("ATTACK");
const u8 gText_Defense2[] = _("DEFENSE");
const u8 gText_Speed[] = _("SPEED");
const u8 gText_SpAtk2[] = _("SP. ATK");
const u8 gText_SpDef2[] = _("SP. DEF");
const u8 gText_Accuracy[] = _("accuracy");
const u8 gText_Evasiveness[] = _("evasiveness");

const u8 * const gStatNamesTable[] =
{
    gText_HP2, gText_Attack2, gText_Defense2,
    gText_Speed, gText_SpAtk2, gText_SpDef2,
    gText_Accuracy, gText_Evasiveness
};

const u8 gText_PokeblockWasTooSpicy[] = _("was too spicy!");
const u8 gText_PokeblockWasTooDry[] = _("was too dry!");
const u8 gText_PokeblockWasTooSweet[] = _("was too sweet!");
const u8 gText_PokeblockWasTooBitter[] = _("was too bitter!");
const u8 gText_PokeblockWasTooSour[] = _("was too sour!");

const u8 * const gPokeblockWasTooXStringTable[] =
{
    gText_PokeblockWasTooSpicy, gText_PokeblockWasTooDry,
    gText_PokeblockWasTooSweet, gText_PokeblockWasTooBitter,
    gText_PokeblockWasTooSour
};

const u8 gText_PlayerUsedItem[] = _("{B_PLAYER_NAME} used\n{B_LAST_ITEM}!");
const u8 gText_WallyUsedItem[] = _("WALLY used\n{B_LAST_ITEM}!");
const u8 gText_Trainer1UsedItem[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nused {B_LAST_ITEM}!");
const u8 gText_TrainerBlockedBall[] = _("The TRAINER blocked the BALL!");
const u8 gText_DontBeAThief[] = _("Don’t be a thief!");
const u8 gText_ItDodgedBall[] = _("It dodged the thrown BALL!\nThis POKéMON can’t be caught!");
const u8 gText_YouMissedPkmn[] = _("You missed the POKéMON!");
const u8 gText_PkmnBrokeFree[] = _("Oh, no!\nThe POKéMON broke free!");
const u8 gText_ItAppearedCaught[] = _("Aww!\nIt appeared to be caught!");
const u8 gText_AarghAlmostHadIt[] = _("Aargh!\nAlmost had it!");
const u8 gText_ShootSoClose[] = _("Shoot!\nIt was so close, too!");
const u8 gText_GotchaPkmnCaught[] = _("Gotcha!\n{B_OPPONENT_MON1_NAME} was caught!{UNKNOWN_A}{PLAY_BGM BGM_KACHI22}\p");
const u8 gText_GotchaPkmnCaught2[] = _("Gotcha!\n{B_OPPONENT_MON1_NAME} was caught!{UNKNOWN_A}{PLAY_BGM BGM_KACHI22}{PAUSE 127}");
const u8 gText_GiveNicknameCaptured[] = _("Give a nickname to the\ncaptured {B_OPPONENT_MON1_NAME}?");
const u8 gText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} was sent to\n{B_PC_CREATOR_NAME} PC.");
const u8 gText_Someones[] = _("someone’s");
const u8 gText_Lanettes[] = _("LANETTE’s");
const u8 gText_PkmnDataAddedToDex[] = _("{B_OPPONENT_MON1_NAME}’s data was\nadded to the POKéDEX.\p");
const u8 gText_ItIsRaining[] = _("It is raining.");
const u8 gText_SandstormIsRaging[] = _("A sandstorm is raging.");
const u8 gText_BoxIsFull[] = _("The BOX is full!\nYou can’t catch any more!\p");
const u8 gText_EnigmaBerry[] = _("ENIGMA BERRY");
const u8 gText_BerrySuffix[] = _(" BERRY");
const u8 gText_PkmnsItemCuredParalysis[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\ncured paralysis!");
const u8 gText_PkmnsItemCuredPoison[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\ncured poison!");
const u8 gText_PkmnsItemHealedBurn[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nhealed its burn!");
const u8 gText_PkmnsItemDefrostedIt[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\ndefrosted it!");
const u8 gText_PkmnsItemWokeIt[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nwoke it from its sleep!");
const u8 gText_PkmnsItemSnappedOut[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nsnapped it out of confusion!");
const u8 gText_PkmnsItemCuredProblem[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\ncured its {B_BUFF1} problem!");
const u8 gText_PkmnsItemNormalizedStatus[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nnormalized its status!");
const u8 gText_PkmnsItemRestoredHealth[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nrestored health!");
const u8 gText_PkmnsItemRestoredPP[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nrestored {B_BUFF1}’s PP!");
const u8 gText_PkmnsItemRestoredStatus[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nrestored its status!");
const u8 gText_PkmnsItemRestoredHPALittle[] = _("{B_ACTIVE_NAME_WITH_PREFIX}’s {B_LAST_ITEM}\nrestored its HP a little!");
const u8 gText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} allows the\nuse of only {B_CURRENT_MOVE}!\p");
const u8 gText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} hung on\nusing its {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
const u8 gText_YouThrowABallNowRight[] = _("You throw a BALL now, right?\nI… I’ll do my best!");

// early declaration of strings
const u8 gText_PkmnIncapableOfPower[];
const u8 gText_GlintAppearsInEye[];
const u8 gText_PkmnGettingIntoPosition[];
const u8 gText_PkmnBeganGrowlingDeeply[];
const u8 gText_PkmnEagerForMore[];
const u8 gText_DefeatedOpponentByReferee[];
const u8 gText_LostToOpponentByReferee[];
const u8 gText_TiedOpponentByReferee[];
const u8 gText_QuestionForfeitMatch[];
const u8 gText_ForfeitedMatch[];
const u8 gText_Trainer1WinText[];
const u8 gText_Trainer2WinText[];
const u8 gText_TwoInGameTrainersDefeated[];
const u8 gText_Trainer2LoseText[];

const u8 * const gBattleStringsTable[BATTLESTRINGS_COUNT] =
{
	gText_Trainer1LoseText,
	gText_PkmnGainedEXP,
	gText_PkmnGrewToLv,
	gText_PkmnLearnedMove,
	gText_TryToLearnMove1,
	gText_TryToLearnMove2,
	gText_TryToLearnMove3,
	gText_PkmnForgotMove,
	gText_StopLearningMove,
	gText_DidNotLearnMove,
	gText_PkmnLearnedMove2,
	gText_AttackMissed,
	gText_PkmnProtectedItself,
	gText_StatsWontIncrease2,
	gText_AvoidedDamage,
	gText_ItDoesntAffect,
	gText_PkmnFainted,
	gText_PkmnFainted2,
	gText_PlayerGotMoney,
	gText_PlayerWhiteout,
	gText_PlayerWhiteout2,
	gText_PreventsEscape,
	gText_HitXTimes,
	gText_PkmnFellAsleep,
	gText_PkmnMadeSleep,
	gText_PkmnAlreadyAsleep,
	gText_PkmnAlreadyAsleep2,
	gText_PkmnWasntAffected,
	gText_PkmnWasPoisoned,
	gText_PkmnPoisonedBy,
	gText_PkmnHurtByPoison,
	gText_PkmnAlreadyPoisoned,
	gText_PkmnBadlyPoisoned,
	gText_PkmnEnergyDrained,
	gText_PkmnWasBurned,
	gText_PkmnBurnedBy,
	gText_PkmnHurtByBurn,
	gText_PkmnWasFrozen,
	gText_PkmnFrozenBy,
	gText_PkmnIsFrozen,
	gText_PkmnWasDefrosted,
	gText_PkmnWasDefrosted2,
	gText_PkmnWasDefrostedBy,
	gText_PkmnWasParalyzed,
	gText_PkmnWasParalyzedBy,
	gText_PkmnIsParalyzed,
	gText_PkmnIsAlreadyParalyzed,
	gText_PkmnHealedParalysis,
	gText_PkmnDreamEaten,
	gText_StatsWontIncrease,
	gText_StatsWontDecrease,
	gText_TeamStoppedWorking,
	gText_FoeStoppedWorking,
	gText_PkmnIsConfused,
	gText_PkmnHealedConfusion,
	gText_PkmnWasConfused,
	gText_PkmnAlreadyConfused,
	gText_PkmnFellInLove,
	gText_PkmnInLove,
	gText_PkmnImmobilizedByLove,
	gText_PkmnBlownAway,
	gText_PkmnChangedType,
	gText_PkmnFlinched,
	gText_PkmnRegainedHealth,
	gText_PkmnHPFull,
	gText_PkmnRaisedSpDef,
	gText_PkmnRaisedDef,
	gText_PkmnCoveredByVeil,
	gText_PkmnUsedSafeguard,
	gText_PkmnSafeguardExpired,
	gText_PkmnWentToSleep,
	gText_PkmnSleptHealthy,
	gText_PkmnWhippedWhirlwind,
	gText_PkmnTookSunlight,
	gText_PkmnLoweredHead,
	gText_PkmnIsGlowing,
	gText_PkmnFlewHigh,
	gText_PkmnDugHole,
	gText_PkmnSqueezedByBind,
	gText_PkmnTrappedInVortex,
	gText_PkmnWrappedBy,
	gText_PkmnClamped,
	gText_PkmnHurtBy,
	gText_PkmnFreedFrom,
	gText_PkmnCrashed,
	gText_PkmnShroudedInMist,
	gText_PkmnProtectedByMist,
	gText_PkmnGettingPumped,
	gText_PkmnHitWithRecoil,
	gText_PkmnProtectedItself2,
	gText_PkmnBuffetedBySandstorm,
	gText_PkmnPeltedByHail,
	gText_PkmnSeeded,
	gText_PkmnEvadedAttack,
	gText_PkmnSappedByLeechSeed,
	gText_PkmnFastAsleep,
	gText_PkmnWokeUp,
	gText_PkmnUproarKeptAwake,
	gText_PkmnWokeUpInUproar,
	gText_PkmnCausedUproar,
	gText_PkmnMakingUproar,
	gText_PkmnCalmedDown,
	gText_PkmnCantSleepInUproar,
	gText_PkmnStockpiled,
	gText_PkmnCantStockpile,
	gText_PkmnCantSleepInUproar2,
	gText_UproarKeptPkmnAwake,
	gText_PkmnStayedAwakeUsing,
	gText_PkmnStoringEnergy,
	gText_PkmnUnleashedEnergy,
	gText_PkmnFatigueConfusion,
	gText_PkmnPickedUpItem,
	gText_PkmnUnaffected,
	gText_PkmnTransformedInto,
	gText_PkmnMadeSubstitute,
	gText_PkmnHasSubstitute,
	gText_SubstituteDamaged,
	gText_PkmnSubstituteFaded,
	gText_PkmnMustRecharge,
	gText_PkmnRageBuilding,
	gText_PkmnMoveWasDisabled,
	gText_PkmnMoveIsDisabled,
	gText_PkmnMoveDisabledNoMore,
	gText_PkmnGotEncore,
	gText_PkmnEncoreEnded,
	gText_PkmnTookAim,
	gText_PkmnSketchedMove,
	gText_PkmnTryingToTakeFoe,
	gText_PkmnTookFoe,
	gText_PkmnReducedPP,
	gText_PkmnStoleItem,
	gText_PkmnCantEscape,
	gText_PkmnFellIntoNightmare,
	gText_PkmnLockedInNightmare,
	gText_PkmnLaidCurse,
	gText_PkmnAfflictedByCurse,
	gText_SpikesScattered,
	gText_PkmnHurtBySpikes,
	gText_PkmnIdentified,
	gText_PkmnPerishCountFell,
	gText_PkmnBracedItself,
	gText_PkmnEnduredHit,
	gText_MagnitudeStrength,
	gText_PkmnCutHPMaxedAttack,
	gText_PkmnCopiedStatChanges,
	gText_PkmnGotFree,
	gText_PkmnShedLeechSeed,
	gText_PkmnBlewAwaySpikes,
	gText_PkmnFledFromBattle,
	gText_PkmnForesawAttack,
	gText_PkmnTookAttack,
	gText_PkmnAttack,
	gText_PkmnCenterAttention,
	gText_PkmnChargingPower,
	gText_NaturePowerTurnedInto,
	gText_PkmnStatusNormal,
	gText_PkmnHasNoMovesLeft,
	gText_PkmnSubjectedToTorment,
	gText_PkmnCantUseMoveTorment,
	gText_PkmnTighteningFocus,
	gText_PkmnFellForTaunt,
	gText_PkmnCantUseMoveTaunt,
	gText_PkmnReadyToHelp,
	gText_PkmnSwitchedItems,
	gText_PkmnCopiedFoe,
	gText_PkmnMadeWish,
	gText_PkmnWishCameTrue,
	gText_PkmnPlantedRoots,
	gText_PkmnAbsorbedNutrients,
	gText_PkmnAnchoredItself,
	gText_PkmnWasMadeDrowsy,
	gText_PkmnKnockedOff,
	gText_PkmnSwappedAbilities,
	gText_PkmnSealedOpponentMove,
	gText_PkmnCantUseMoveSealed,
	gText_PkmnWantsGrudge,
	gText_PkmnLostPPGrudge,
	gText_PkmnShroudedItself,
	gText_PkmnMoveBounced,
	gText_PkmnWaitsForTarget,
	gText_PkmnSnatchedMove,
	gText_PkmnMadeItRain,
	gText_PkmnRaisedSpeed,
	gText_PkmnProtectedBy,
	gText_PkmnPreventsUsage,
	gText_PkmnRestoredHPUsing,
	gText_PkmnChangedTypeWith,
	gText_PkmnPreventsParalysisWith,
	gText_PkmnPreventsRomanceWith,
	gText_PkmnPreventsPoisoningWith,
	gText_PkmnPreventsConfusionWith,
	gText_PkmnRaisedFirePowerWith,
	gText_PkmnAnchorsItselfWith,
	gText_PkmnCutsAttackWith,
	gText_PkmnPreventsStatLossWith,
	gText_PkmnHurtsWith,
	gText_PkmnTraced,
	gText_StatSharply,
	gText_StatRose,
	gText_StatHarshly,
	gText_StatFell,
	gText_PkmnsStatChanged,
	gText_PkmnsStatChanged2,
	gText_PkmnsStatChanged3,
	gText_PkmnsStatChanged4,
	gText_CriticalHit,
	gText_OneHitKO,
	gText_123Poof,
	gText_AndEllipsis,
	gText_NotVeryEffective,
	gText_SuperEffective,
	gText_GotAwaySafely,
	gText_WildPkmnFled,
	gText_NoRunningFromTrainers,
	gText_CantEscape,
	gText_DontLeaveBirch,
	gText_ButNothingHappened,
	gText_ButItFailed,
	gText_ItHurtConfusion,
	gText_MirrorMoveFailed,
	gText_StartedToRain,
	gText_DownpourStarted,
	gText_RainContinues,
	gText_DownpourContinues,
	gText_RainStopped,
	gText_SandstormBrewed,
	gText_SandstormRages,
	gText_SandstormSubsided,
	gText_SunlightGotBright,
	gText_SunlightStrong,
	gText_SunlightFaded,
	gText_StartedHail,
	gText_HailContinues,
	gText_HailStopped,
	gText_FailedToSpitUp,
	gText_FailedToSwallow,
	gText_WindBecameHeatWave,
	gText_StatChangesGone,
	gText_CoinsScattered,
	gText_TooWeakForSubstitute,
	gText_SharedPain,
	gText_BellChimed,
	gText_FaintInThree,
	gText_NoPPLeft,
	gText_ButNoPPLeft,
	gText_PlayerUsedItem,
	gText_WallyUsedItem,
	gText_TrainerBlockedBall,
	gText_DontBeAThief,
	gText_ItDodgedBall,
	gText_YouMissedPkmn,
	gText_PkmnBrokeFree,
	gText_ItAppearedCaught,
	gText_AarghAlmostHadIt,
	gText_ShootSoClose,
	gText_GotchaPkmnCaught,
	gText_GotchaPkmnCaught2,
	gText_GiveNicknameCaptured,
	gText_PkmnSentToPC,
	gText_PkmnDataAddedToDex,
	gText_ItIsRaining,
	gText_SandstormIsRaging,
	gText_CantEscape2,
	gText_PkmnIgnoresAsleep,
	gText_PkmnIgnoredOrders,
	gText_PkmnBeganToNap,
	gText_PkmnLoafing,
	gText_PkmnWontObey,
	gText_PkmnTurnedAway,
	gText_PkmnPretendNotNotice,
	gText_EnemyAboutToSwitchPkmn,
	gText_CreptCloser,
	gText_CantGetCloser,
	gText_PkmnWatchingCarefully,
	gText_PkmnCuriousAboutX,
	gText_PkmnEnthralledByX,
	gText_PkmnIgnoredX,
	gText_ThrewPokeblockAtPkmn,
	gText_OutOfSafariBalls,
	gText_PkmnsItemCuredParalysis,
	gText_PkmnsItemCuredPoison,
	gText_PkmnsItemHealedBurn,
	gText_PkmnsItemDefrostedIt,
	gText_PkmnsItemWokeIt,
	gText_PkmnsItemSnappedOut,
	gText_PkmnsItemCuredProblem,
	gText_PkmnsItemRestoredHealth,
	gText_PkmnsItemRestoredPP,
	gText_PkmnsItemRestoredStatus,
	gText_PkmnsItemRestoredHPALittle,
	gText_ItemAllowsOnlyYMove,
	gText_PkmnHungOnWithX,
	gText_EmptyString3,
	gText_PkmnsXPreventsBurns,
	gText_PkmnsXBlocksY,
	gText_PkmnsXRestoredHPALittle2,
	gText_PkmnsXWhippedUpSandstorm,
	gText_PkmnsXPreventsYLoss,
	gText_PkmnsXInfatuatedY,
	gText_PkmnsXMadeYIneffective,
	gText_PkmnsXCuredYProblem,
	gText_ItSuckedLiquidOoze,
	gText_PkmnTransformed,
	gText_ElectricityWeakened,
	gText_FireWeakened,
	gText_PkmnHidUnderwater,
	gText_PkmnSprangUp,
	gText_HMMovesCantBeForgotten,
	gText_XFoundOneY,
	gText_PlayerDefeatedLinkTrainerTrainer1,
	gText_SoothingAroma,
	gText_ItemsCantBeUsedNow,
	gText_ForXCommaYZ,
	gText_UsingXTheYOfZN,
	gText_PkmnUsedXToGetPumped,
	gText_PkmnsXMadeYUseless,
	gText_PkmnTrappedBySandTomb,
	gText_EmptyString4,
	gText_ABoosted,
	gText_PkmnsXIntensifiedSun,
	gText_PkmnMakesGroundMiss,
	gText_YouThrowABallNowRight,
	gText_PkmnsXTookAttack,
	gText_PkmnChoseXAsDestiny,
	gText_PkmnLostFocus,
	gText_UseNextPkmn,
	gText_PkmnFledUsingIts,
	gText_PkmnFledUsing,
	gText_PkmnWasDraggedOut,
	gText_PreventedFromWorking,
	gText_PkmnsItemNormalizedStatus,
	gText_Trainer1UsedItem,
	gText_BoxIsFull,
	gText_PkmnAvoidedAttack,
	gText_PkmnsXMadeItIneffective,
	gText_PkmnsXPreventsFlinching,
	gText_PkmnAlreadyHasBurn,
	gText_StatsWontDecrease2,
	gText_PkmnsXBlocksY2,
	gText_PkmnsXWoreOff,
	gText_PkmnRaisedDefALittle,
	gText_PkmnRaisedSpDefALittle,
	gText_TheWallShattered,
	gText_PkmnsXPreventsYsZ,
	gText_PkmnsXCuredItsYProblem,
	gText_PkmnCantEscape2,
	gText_PkmnObtainedX,
	gText_PkmnObtainedX2,
	gText_PkmnObtainedXYObtainedZ,
	gText_ButNoEffect,
	gText_PkmnsXHadNoEffectOnY,
	gText_TwoInGameTrainersDefeated,
	gText_Trainer2LoseText,
	gText_PkmnIncapableOfPower,
	gText_GlintAppearsInEye,
	gText_PkmnGettingIntoPosition,
	gText_PkmnBeganGrowlingDeeply,
	gText_PkmnEagerForMore,
	gText_DefeatedOpponentByReferee,
	gText_LostToOpponentByReferee,
	gText_TiedOpponentByReferee,
	gText_QuestionForfeitMatch,
	gText_ForfeitedMatch,
	gText_PkmnTransferredSomeonesPC,
	gText_PkmnTransferredLanettesPC,
	gText_PkmnBoxSomeonesPCFull,
	gText_PkmnBoxLanettesPCFull,
	gText_Trainer1WinText,
	gText_Trainer2WinText,
};

const u16 gMissStringIds[] =
{
    STRINGID_ATTACKMISSED, STRINGID_PKMNPROTECTEDITSELF,
    STRINGID_PKMNAVOIDEDATTACK, STRINGID_AVOIDEDDAMAGE,
    STRINGID_PKMNMAKESGROUNDMISS
};

// todo: change values to string Ids
const u16 gUnknown_085CC83E[] =
{
    0x00e2, 0x00e3, 0x0021,
    0x0112, 0x0165, 0x00e8, 0x00e9, 0x00e5, 0x00ed, 0x00f0, 0x00f3,
    0x00ee, 0x00f4, 0x0066, 0x0067, 0x00ef, 0x00f5, 0x00ea, 0x00eb,
    0x00ec, 0x0065, 0x0098, 0x00e5, 0x00e5, 0x004e, 0x0160, 0x004d,
    0x0161, 0x004f, 0x0068, 0x0069, 0x001b, 0x006a, 0x0139, 0x0052,
    0x0053, 0x0070, 0x0071, 0x0073, 0x0074, 0x006c, 0x006e, 0x00f7,
    0x004c, 0x0075, 0x0076, 0x0077, 0x00d5, 0x00d6, 0x003d, 0x0130,
    0x0145, 0x0146, 0x00d7, 0x00d8, 0x003e, 0x0130, 0x0054, 0x0055,
    0x0056, 0x0057, 0x0058, 0x0059, 0x013d, 0x013e, 0x005a, 0x005c,
    0x005b, 0x005d, 0x005b, 0x0148, 0x0061, 0x00e5, 0x0063, 0x00e5,
    0x007d, 0x00e5, 0x007e, 0x00fb, 0x0028, 0x0029, 0x0037, 0x0038,
    0x0023, 0x0024, 0x002e, 0x002f, 0x0031, 0x0032, 0x0035, 0x0036,
    0x0017, 0x007c, 0x0045, 0x0136, 0x002d, 0x0139, 0x013b, 0x013c,
    0x00fd, 0x00fd, 0x00fd, 0x00fd, 0x0142, 0x00a1, 0x014f, 0x0107,
    0x0108, 0x0109, 0x010a, 0x0110, 0x0110, 0x0110, 0x0110, 0x0110,
    0x0110, 0x0110, 0x0110, 0x0111, 0x0110, 0x0110, 0x0110, 0x00f1,
    0x0110, 0x0110, 0x0110, 0x0116, 0x0117, 0x0118, 0x0119, 0x016d,
    0x011b, 0x011c, 0x011e, 0x011f, 0x0120, 0x0128, 0x0123, 0x0126,
    0x0125, 0x0124, 0x0127, 0x0129, 0x0156, 0x0131, 0x0163, 0x016a,
    0x00c7, 0x0163, 0x016a, 0x00c9, 0x0163, 0x016a, 0x0166, 0x0167,
    0x0168, 0x00cb, 0x0137, 0x0177, 0x0178, 0x0179, 0x017a,
};

const u16 gTrappingMoves[] =
{
    MOVE_BIND, MOVE_WRAP, MOVE_FIRE_SPIN, MOVE_CLAMP, MOVE_WHIRLPOOL, MOVE_SAND_TOMB, 0xFFFF
};

const u8 gText_PkmnIsEvolving[] = _("What?\n{STR_VAR_1} is evolving!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{UNKNOWN_A}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {STR_VAR_1}\nstopped evolving!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("What will\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} do?");
const u8 gText_WhatWillPkmnDo2[] = _("What will\n{B_PLAYER_NAME} do?");
const u8 gText_WhatWillWallyDo[] = _("What will\nWALLY do?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Link standby…");
const u8 gText_BattleMenu[] = _("FIGHT{CLEAR_TO 56}BAG\nPOKéMON{CLEAR_TO 56}RUN");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK}\nGO NEAR{CLEAR_TO 56}RUN");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TYPE/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Switch\nwhich?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

const u8 gText_HP[] = _("HP");
const u8 gText_Attack[] = _("ATTACK");
const u8 gText_Defense[] = _("DEFENSE");
const u8 gText_SpAtk[] = _("SP. ATK");
const u8 gText_SpDef[] = _("SP. DEF");

const u8 * const gStatNamesTable2[] =
{
    gText_HP, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GREY}SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GREY}Left: $" "{HIGHLIGHT DARK_GREY}");const u8 gText_Sleep[] = _( "sleep");const u8 gText_Poison[] = _(     "poison");const u8 gText_Burn[] = _( "burn");const u8 gText_Paralysis[] = _( "paralysis");const u8 gText_Ice[] = _( "ice");const u8 gText_Confusion[] = _( "confusion");const u8 gText_Love[] = _( "love");
const u8 gText_SpaceAndSpace[] = _(" and ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_ScrollTextUp[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("are");
const u8 gText_Are2[] = _("are");
const u8 gText_BadEgg[] = _("Bad EGG");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Draw");
const u8 gText_SpaceIs[] = _(" is");
const u8 gText_ApostropheS[] = _("’s");

const u8 gText_UnknownMoveTypes[][17] =
{
    _("a NORMAL move"),
    _("a FIGHTING move"),
    _("a FLYING move"),
    _("a POISON move"),
    _("a GROUND move"),
    _("a ROCK move"),
    _("a BUG move"),
    _("a GHOST move"),
    _("a STEEL move"),
    _("a ??? move"),
    _("a FIRE move"),
    _("a WATER move"),
    _("a GRASS move"),
    _("an ELECTRIC move"),
    _("a PSYCHIC move"),
    _("an ICE move"),
    _("a DRAGON move"),
    _("a DARK move")
};

const u8 gText_BattleTourney[] = _("BATTLE TOURNEY");
const u8 gText_Round1[] = _("Round 1");
const u8 gText_Round2[] = _("Round 2");
const u8 gText_Semifinal[] = _("Semifinal");
const u8 gText_Final[] = _("Final");

const u8 * const gRoundsStringTable[] =
{
    gText_Round1,
    gText_Round2,
    gText_Semifinal,
    gText_Final
};

const u8 gText_TheGreatNewHope[] = _("The great new hope!\p");
const u8 gText_WillChampinshipDreamComeTrue[] = _("Will the championship dream come true?!\p");
const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p");
const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p");
const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p");

const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mind");
const u8 gText_Skill[] = _("Skill");
const u8 gText_Body[] = _("Body");
const u8 gText_Judgement[] = _("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
const u8 gText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_OPPONENT_MON2_NAME}!");
const u8 gText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_BUFF1}!");
const u8 gText_TwoTrainersWantToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwant to battle!\p");
const u8 gText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_CLASS} {B_PARTNER_NAME} sent\nout {B_PLAYER_MON2_NAME}!\lGo, {B_PLAYER_MON1_NAME}!");
const u8 gText_TwoInGameTrainersDefeated[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwere defeated!\p");
const u8 gText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
const u8 gText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} appears incapable\nof using its power!");
const u8 gText_GlintAppearsInEye[] = _("A glint appears in\n{B_ACTIVE_NAME_WITH_PREFIX}’s eyes!");
const u8 gText_PkmnGettingIntoPosition[] = _("{B_ACTIVE_NAME_WITH_PREFIX} is getting into\nposition!");
const u8 gText_PkmnBeganGrowlingDeeply[] = _("{B_ACTIVE_NAME_WITH_PREFIX} began growling deeply!");
const u8 gText_PkmnEagerForMore[] = _("{B_ACTIVE_NAME_WITH_PREFIX} is eager for more!");

const u16 gUnknown_085CCF0A[] =
{
    0x016E, 0x016F, 0x0170, 0x0171
};

const u8 gText_RefIfNothingIsDecided[] = _("REFEREE: If nothing is decided in\n3 turns, we will go to judging!");
const u8 gText_RefThatsIt[] = _("REFEREE: That’s it! We will now go to\njudging to determine the winner!");
const u8 gText_RefJudgeMind[] = _("REFEREE: Judging category 1, Mind!\nThe POKéMON showing the most guts!\p");
const u8 gText_RefJudgeSkill[] = _("REFEREE: Judging category 2, Skill!\nThe POKéMON using moves the best!\p");
const u8 gText_RefJudgeBody[] = _("REFEREE: Judging category 3, Body!\nThe POKéMON with the most vitality!\p");
const u8 gText_RefJudgement1[] = _("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_PLAYER_NAME}’s {B_PLAYER_MON1_NAME}!\p");
const u8 gText_RefJudgement2[] = _("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_TRAINER1_NAME}’s {B_OPPONENT_MON1_NAME}!\p");
const u8 gText_RefJudgement3[] = _("REFEREE: Judgment: 3 to 3!\nWe have a draw!\p");
const u8 gText_DefeatedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} defeated the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE’s decision!");
const u8 gText_LostToOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} lost to the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE’s decision!");
const u8 gText_TiedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} tied the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE’s decision!");
const u8 gText_RefCommenceBattle[] = _("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nCommence battling!");

const u8 * const gRefereeStringsTable[] =
{
    gText_RefIfNothingIsDecided,
	gText_RefThatsIt,
	gText_RefJudgeMind,
	gText_RefJudgeSkill,
	gText_RefJudgeBody,
	gText_RefJudgement1,
	gText_RefJudgement2,
	gText_RefJudgement3,
	gText_RefCommenceBattle,
};

const u8 gText_QuestionForfeitMatch[] = _("Would you like to forfeit the match\nand quit now?");
const u8 gText_ForfeitedMatch[] = _("{B_PLAYER_NAME} forfeited the match!");
const u8 gText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
const u8 gText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
const u8 gText_Trainer1Fled[] = _( "{PLAY_SE 0x0011}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
const u8 gText_PlayerLostAgainstTrainer1[] = _("Player lost against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_PlayerBattledToDrawTrainer1[] = _("Player battled to a draw against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _("Would you like to record your battle\non your FRONTIER PASS?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}’s battle result was recorded\non the FRONTIER PASS.");
const u8 gText_LinkTrainerWantsToBattlePause[] = _("{B_20}\nwants to battle!{PAUSE 49}");
const u8 gText_TwoLinkTrainersWantToBattlePause[] = _("{B_20} and {B_21}\nwant to battle!{PAUSE 49}");

const u16 gUnknown_085CD336[] =
{
    0x000e, 0x0046, 0x004a, 0x006a, 0x006b, 0x006c, 0x006e, 0x006f,
	0x0079, 0x007b, 0x007d, 0x0094, 0x0096, 0x0097, 0x009b, 0x009c,
	0x009f, 0x00a4, 0x00aa, 0x00ad, 0x00b6, 0x00bf, 0x00cb, 0x00cd,
	0x00cf, 0x00d6, 0x00ed, 0x00f4, 0x00f5, 0x010a, 0x010f, 0x0112,
	0x0113, 0x011a, 0x0125, 0x0136, 0x013c, 0x0140, 0x0149, 0x014a,
	0x014e, 0x0154, 0x0000, 0x0064, 0x0069, 0x0075, 0x0085, 0x00af,
	0x010d, 0x0153, 0x0000, 0x0060, 0x0061, 0x0066, 0x0068, 0x008c,
	0x0090, 0x00a5, 0x00b8, 0x010c, 0x0111, 0x0118, 0x0119, 0x0129,
	0x012a, 0x012c, 0x0139, 0x015a, 0x015b, 0x0000, 0x0001, 0x000a,
	0x000b, 0x0011, 0x0013, 0x0014, 0x0015, 0x001e, 0x0023, 0x0025,
	0x0027, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f, 0x0040, 0x0047,
	0x0051, 0x0059, 0x005a, 0x005b, 0x005c, 0x0067, 0x0076, 0x007a,
	0x0080, 0x0084, 0x008b, 0x0091, 0x00a3, 0x00a9, 0x00ab, 0x00ae,
	0x00c1, 0x00cc, 0x00d5, 0x00f9, 0x00fd, 0x00ff, 0x0100, 0x0103,
	0x0104, 0x0110, 0x011b, 0x0141, 0x0157, 0x0000,
};

const u8 gUnknown_085CD422[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0};

const u16 gUnknown_085CD42C[] =
{
	0x01ff, 0x0100, 0x0000, 0x0101, 0x060f, 0x0000, 0x01ff, 0x0101,
	0x0000, 0x0100, 0x060f, 0x0000, 0x01ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x07ee, 0x0100,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0c00, 0x0b0e, 0x0000,
	0x01ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x0102,
	0x0000, 0x0c00, 0x0b0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x01ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x0100,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x0100, 0x0120, 0x0000, 0x0100,
	0x0200, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x01ff,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x0100, 0x01ff,
	0x0000, 0x0100, 0x0600, 0x0000, 0x0100, 0x01ff, 0x0000, 0x0100,
	0x0600, 0x0000, 0x0100, 0x01ff, 0x0000, 0x0100, 0x0600, 0x0000,
};

const u16 gUnknown_085CD54C[] =
{
	0x01ff, 0x0100, 0x0000, 0x0101, 0x060f, 0x0000, 0x01ff, 0x0101,
	0x0000, 0x0100, 0x060f, 0x0000, 0x01ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x07ee, 0x0100,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0c00, 0x0b0e, 0x0000,
	0x01ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x0102,
	0x0000, 0x0c00, 0x0b0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x07ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x01ee, 0x0100, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x0100,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x0100, 0x0120, 0x0000, 0x0100,
	0x0200, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0100, 0x0f0e, 0x0000,
	0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x01ff,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0d00,
	0x0f0e, 0x0000, 0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000,
	0x01ee, 0x01ff, 0x0000, 0x0d00, 0x0f0e, 0x0000, 0x01ee, 0x01ff,
	0x0000, 0x0d00, 0x0f0e, 0x0000, 0x0111, 0x0100, 0x0000, 0x0201,
	0x0301, 0x0000
};

const u16 * const gUnknown_085CD660[] =
{
    gUnknown_085CD42C, gUnknown_085CD54C
};

const u8 gUnknown_085CD668[] = {8, 4, 1, 0};

extern struct StringInfoBattle *gStringInfo;

void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8* stringPtr = NULL;

    gStringInfo = (struct StringInfoBattle*)(&gBattleBufferA[gActiveBank][4]);
    gLastUsedItem = gStringInfo->lastItem;
    gLastUsedAbility = gStringInfo->lastAbility;
    gBattleScripting.bank = gStringInfo->scrActive;
    *(&gBattleStruct->field_52) = gStringInfo->unk1605E;
    *(&gBattleStruct->hpScale) = gStringInfo->hpScale;
    gStringBank = gStringInfo->StringBank;
    *(&gBattleStruct->stringMoveType) = gStringInfo->moveType;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        gAbilitiesPerBank[i] = gStringInfo->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gStringInfo->textBuffs[0][i];
        gBattleTextBuff2[i] = gStringInfo->textBuffs[1][i];
        gBattleTextBuff3[i] = gStringInfo->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_x800000)
                {
                    stringPtr = gText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = gText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = gText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
                        stringPtr = gText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = gText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = gText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = gText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = gText_TwoTrainersWantToBattle;
                else
                    stringPtr = gText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = gText_WildPkmnAppeared2;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = gText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = gText_WildPkmnAppearedPause;
            else
                stringPtr = gText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = gText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = gText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = gText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = gText_GoTwoPkmn;
            }
            else
            {
                stringPtr = gText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = gText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_x800000)
                    stringPtr = gText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = gText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
                    stringPtr = gText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = gText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)))
                    stringPtr = gText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
                    stringPtr = gText_Trainer1SentOutPkmn;
                else
                    stringPtr = gText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = gText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = gText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = gText_PkmnOkComeBack;
            else
                stringPtr = gText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_800 || gBattleTypeFlags & BATTLE_TYPE_x2000000)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = gText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = gText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = gText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBankSide(gBattleScripting.bank) == SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = gText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = gText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = gText_GoForItPkmn;
            else
                stringPtr = gText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_x800000)
                {
                    if (gBattleScripting.bank == 1)
                        stringPtr = gText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = gText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = gText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
                        stringPtr = gText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = gText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.bank == 1)
                        stringPtr = gText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = gText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = gText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        sub_814F8F8(gBattleTextBuff1);

        if (gStringInfo->currentMove > LAST_MOVE_INDEX)
            StringCopy(gBattleTextBuff2, gText_UnknownMoveTypes[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff2, gMoveNames[gStringInfo->currentMove]);

        sub_814F950(gBattleTextBuff2);
        stringPtr = gText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & BATTLE_OUTCOME_BIT_x80)
        {
            gBattleTextBuff1[0] &= ~(BATTLE_OUTCOME_BIT_x80);
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT && gBattleTextBuff1[0] != BATTLE_DREW)
                gBattleTextBuff1[0] ^= (BATTLE_LOST | BATTLE_WON);

            if (gBattleTextBuff1[0] == BATTLE_LOST || gBattleTextBuff1[0] == BATTLE_DREW)
                stringPtr = gText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = gText_TwoWildFled;
            else
                stringPtr = gText_WildFled;
        }
        else
        {
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT && gBattleTextBuff1[0] != BATTLE_DREW)
                gBattleTextBuff1[0] ^= (BATTLE_LOST | BATTLE_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case BATTLE_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_x800000)
                        stringPtr = gText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = gText_TwoLinkTrainersDefeated;
                    break;
                case BATTLE_LOST:
                    stringPtr = gText_PlayerLostToTwo;
                    break;
                case BATTLE_DREW:
                    stringPtr = gText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
            {
                switch (gBattleTextBuff1[0])
                {
                case BATTLE_WON:
                    stringPtr = gText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case BATTLE_LOST:
                    stringPtr = gText_PlayerLostAgainstTrainer1;
                    break;
                case BATTLE_DREW:
                    stringPtr = gText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case BATTLE_WON:
                    stringPtr = gText_PlayerDefeatedLinkTrainer;
                    break;
                case BATTLE_LOST:
                    stringPtr = gText_PlayerLostAgainstLinkTrainer;
                    break;
                case BATTLE_DREW:
                    stringPtr = gText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT + BATTLESTRINGS_ID_ADDER)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_ID_ADDER];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

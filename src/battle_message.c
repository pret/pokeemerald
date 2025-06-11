#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);
static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst);

static EWRAM_DATA u8 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

#if FRENCH
static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} a gagné{B_BUFF2}\n{B_BUFF3} points EXP.!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" un bonus de");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1} monte au\nN. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} apprend\n{B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} tente d’apprendre\n{B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _("Mais {B_BUFF1} ne peut pas\navoir plus de quatre capacités.\p");
static const u8 sText_TryToLearnMove3[] = _("Effacer une ancienne\ncapacité pour {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} oublie\n{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}Arrêter d’apprendre\n{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} n’a pas appris\n{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("Utiliser un autre POKéMON?");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX}\nrate son attaque!");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX}\nse protège!");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} évite les\ndégâts avec {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX} fait échouer les\ncapacités SOL avec {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} évite\nl’attaque!");
static const u8 sText_ItDoesntAffect[] = _("Ça n’affecte pas\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX}\nest K.O.!\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX}\nest K.O.!\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} remporte {B_BUFF1}¥!\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME} n’a plus de\nPOKéMON en forme!\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} est hors-jeu!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} empêche la\nfuite avec {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("Fuite impossible!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX} ne peut\npas fuir!");
static const u8 sText_HitXTimes[] = _("Touché {B_BUFF1} fois!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\ns’endort!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nfait dormir {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} dort déjà!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} dort déjà!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX} n’est pas \naffecté!");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nest empoisonné!");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\na empoisonné {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("{B_ATK_NAME_WITH_PREFIX}\nsouffre du poison!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} est déjà\nempoisonné.");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX} est gravement\nempoisonné!");
static const u8 sText_PkmnEnergyDrained[] = _("L’énergie du {B_DEF_NAME_WITH_PREFIX}\nest drainée!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} est brûlé!");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_ABILITY} de\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} brûle\l{B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} souffre de\nsa brûlure!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} est déjà\nbrûlé.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} est gelé!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ngèle {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} est gelé!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} est dégelé!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} est dégelé!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} est dégelé\npar {B_CURRENT_MOVE}!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} est paralysé!\nIl peut ne plus attaquer!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nparalyse {B_EFF_NAME_WITH_PREFIX}!\lIl peut ne plus attaquer!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} est paralysé!\nIl ne peut plus attaquer!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX} est déjà\nparalysé!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX} n’est plus\nparalysé!");
static const u8 sText_PkmnDreamEaten[] = _("Le rêve de {B_DEF_NAME_WITH_PREFIX}\nest dévoré!");
static const u8 sText_StatsWontIncrease[] = _("Ah, {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\nn’ira pas plus haut!");
static const u8 sText_StatsWontDecrease[] = _("Ah, {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nn’ira pas plus bas!");
static const u8 sText_TeamStoppedWorking[] = _("{B_BUFF1} ne fonctionne\nplus dans votre équipe!");
static const u8 sText_FoeStoppedWorking[] = _("{B_BUFF1} ne fonctionne\nplus dans l’équipe ennemie!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} est confus!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} n’est plus\nconfus!");
static const u8 sText_PkmnWasConfused[] = _("Cela rend {B_EFF_NAME_WITH_PREFIX}\nconfus!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} est\ndéjà confus!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX} est amoureux!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} est amoureux\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("L’amour empêche {B_ATK_NAME_WITH_PREFIX}\nd’attaquer!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} est soufflé!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} prend le\ntype {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} a la trouille!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} récupère\nson énergie!");
static const u8 sText_PkmnHPFull[] = _("Les PV du {B_DEF_NAME_WITH_PREFIX} sont\nau maximum!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_CURRENT_MOVE} du POKéMON {B_ATK_PREFIX2} \naugmente sa DEF. SPE.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_CURRENT_MOVE} du POKéMON {B_ATK_PREFIX2} \naugmente un peu sa DEF. SPE.!");
static const u8 sText_PkmnRaisedDef[] = _("{B_CURRENT_MOVE} du POKéMON {B_ATK_PREFIX2}\naugmente sa DEFENSE!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_CURRENT_MOVE} du POKéMON {B_ATK_PREFIX2}\naugmente un peu sa DEFENSE!");
static const u8 sText_PkmnCoveredByVeil[] = _("L’équipe du POKéMON {B_ATK_PREFIX2} est\nrecouverte par un voile!");
static const u8 sText_PkmnUsedSafeguard[] = _("L’équipe de {B_DEF_NAME_WITH_PREFIX} est\nprotégée par RUNE PROTECT!");
static const u8 sText_PkmnSafeguardExpired[] = _("L’équipe du POKéMON {B_ATK_PREFIX3} n’est\nplus protégée par RUNE PROTECT!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} s’endort!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX} dort et\nrécupère son énergie!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX} déclenche un\ncyclone!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} rayonne!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} baisse la tête!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} est entouré d’une\nlumière intense!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} s’envole!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} creuse un trou!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} se cache sous\nl’eau!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} bondit!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX} est pris dans\nl’ETREINTE du {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} est piégé dans\nle tourbillon!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} est piégé par\nle TOURBI-SABLE!");
static const u8 sText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX} est LIGOTE\npar {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("{B_DEF_NAME_WITH_PREFIX} est pris dans\nle CLAQUOIR du {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} est blessé par\n{B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} est libéré de\n{B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX} s’écrase au\nsol!");
const u8 gText_PkmnShroudedInMist[] = _("Le POKéMON {B_ATK_PREFIX2} s’entoure de\nBRUME!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} est protégé par\nla BRUME!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX} se gonfle!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX} se blesse en\nfrappant!");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX} est prêt à\nse protéger!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} est secoué\npar la tempête de sable!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} est frappé par\nla GRELE!");
static const u8 sText_PkmnsXWoreOff[] = _("{B_BUFF1} du POKéMON {B_ATK_PREFIX1} \nprend fin!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} est infecté!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} évite l’attaque!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("VAMPIGRAINE draine\nl’énergie de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} dort\nprofondément.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} se réveille!");
static const u8 sText_PkmnUproarKeptAwake[] = _("Mais le BROUHAHA du\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} le tient éveillé!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} est réveillé par\nle BROUHAHA!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} provoque\nun BROUHAHA!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} fait un\nBROUHAHA!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} se calme.");
static const u8 sText_PkmnCantSleepInUproar[] = _("Mais le BROUHAHA empêche\n{B_DEF_NAME_WITH_PREFIX} de dormir!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} utilise STOCKAGE\n{B_BUFF1} fois!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} ne peut plus\nutiliser STOCKAGE!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("Mais le BROUHAHA empêche\n{B_DEF_NAME_WITH_PREFIX} de dormir!");
static const u8 sText_UproarKeptPkmnAwake[] = _("Mais le BROUHAHA tient\n{B_DEF_NAME_WITH_PREFIX} éveillé!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} reste éveillé\ngrâce à {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} se concentre!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} envoie la sauce!");
static const u8 sText_PkmnFatigueConfusion[] = _("La fatigue rend {B_ATK_NAME_WITH_PREFIX}\nconfus!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} obtient {B_BUFF1}¥!\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX} n’est pas\naffecté!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} se transforme\nen {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} crée un CLONE!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} a déjà un CLONE!");
static const u8 sText_SubstituteDamaged[] = _("Le CLONE prend les\ndégâts du {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("Le CLONE du {B_DEF_NAME_WITH_PREFIX}\ndisparaît!\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} doit\nse recharger!");
static const u8 sText_PkmnRageBuilding[] = _("La FRENESIE du {B_DEF_NAME_WITH_PREFIX}\naugmente!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{B_BUFF1} du {B_DEF_NAME_WITH_PREFIX}\nest mis sous ENTRAVE!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} n’est plus\nsous ENTRAVE!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX}, ENCORE\nune fois!");
static const u8 sText_PkmnEncoreEnded[] = _("ENCORE du {B_ATK_NAME_WITH_PREFIX}\nest terminé!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} vise\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} GRIBOUILLE\n{B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} veut emmener son\nennemi au tapis!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} emmène\n{B_ATK_NAME_WITH_PREFIX} au tapis!");
static const u8 sText_PkmnReducedPP[] = _("{B_BUFF1} du {B_DEF_NAME_WITH_PREFIX}\nbaisse de {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} vole\n{B_LAST_ITEM} au\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX} ne peut pas\ns’échapper!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} commence un\nCAUCHEMAR!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} est prisonnier\nd’un CAUCHEMAR!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} sacrifie ses PV\net lance une MALEDICTION\lau {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} est touché par\nla MALEDICTION!");
static const u8 sText_SpikesScattered[] = _("Des PICOTS s’éparpillent autour\nde l’équipe de l’ennemi!");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} est blessé par\nles PICOTS!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identifie\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("Le compte du REQUIEM du\n{B_ATK_NAME_WITH_PREFIX} descend à {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} rassemble ses \nforces!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} est TENACE\nface au coup!");
static const u8 sText_MagnitudeStrength[] = _("AMPLEUR {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} sacrifie ses PV\net monte son ATTAQUE au max!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copie les\nchangements\lde stats du {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} se libère\nde {B_BUFF1}\ldu {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX} repousse\nVAMPIGRAINE!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX} repousse les\nPICOTS!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} s’enfuit!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} prévoit une\nattaque!");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} prend l’attaque\nde {B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} prépare\n{B_CURRENT_MOVE}!");
static const u8 sText_PkmnAttack[] = _("Attaque de {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX} devient le centre\nd’attention!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX} se met à\ncharger son énergie!");
static const u8 sText_NaturePowerTurnedInto[] = _("FORCE-NATURE se transforme\nen {B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("Le statut du {B_ATK_NAME_WITH_PREFIX}\nrevient à la normale!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} est victime de la\nTOURMENTE!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} se concentre\ndavantage!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX} répond à\nla PROVOC!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} est prêt à aider\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} change d’objet\navec l’autre POKéMON!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} obtient\n{B_BUFF1}!");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} obtient\n{B_BUFF2}!");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} obtient\n{B_BUFF1}!\p{B_DEF_NAME_WITH_PREFIX} obtient\n{B_BUFF2}!");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copie\n{B_DEF_ABILITY}\ldu {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} fait un VOEU!");
static const u8 sText_PkmnWishCameTrue[] = _("Le VOEU du {B_BUFF1}\nse réalise!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} plante ses\nracines!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} absorbe des\nnutriments avec ses racines!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} s’accroche\navec ses racines!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} rend\n{B_DEF_NAME_WITH_PREFIX} somnolent!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} fait tomber\n{B_LAST_ITEM}\ldu {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} et le POKéMON\néchangent leur capacité spéciale!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} bloque une ou\nplusieurs capacités de l’adversaire!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} veut que\nl’adversaire ait de la RANCUNE!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_BUFF1} du {B_ATK_NAME_WITH_PREFIX}\nperd ses PP à cause de la RANCUNE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} s’entoure\nde {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_CURRENT_MOVE} du {B_ATK_NAME_WITH_PREFIX}\nest renvoyé par le REFLET MAGIK!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} attend que son\nennemi attaque!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} utilise SAISIE\nsur la capacité du\l{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricityWeakened[] = _("La puissance de l’électricité\nest affaiblie!");
static const u8 sText_FireWeakened[] = _("La puissance du feu\nest affaiblie!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX} trouve\n{B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("Une odeur apaisante\nflotte dans les airs!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Objets inutilisables\nici.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("Pour {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} est plein\nd’énergie grâce à {B_LAST_ITEM}!");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} est déconcentré\net ne peut pas attaquer!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} est traîné de\nforce au combat!\p");
static const u8 sText_TheWallShattered[] = _("Le mur vole en éclats!");
static const u8 sText_ButNoEffect[] = _("Mais ça n’a aucun effet!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX} n’a plus\nde capacités!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("Il y a une ENTRAVE sur {B_CURRENT_MOVE}\ndu {B_ACTIVE_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("La TOURMENTE empêche\n{B_ACTIVE_NAME_WITH_PREFIX} d’utiliser une\lcapacité deux fois de suite!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX} ne peut pas\nutiliser {B_CURRENT_MOVE} après PROVOC!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} ne peut pas\nutiliser {B_CURRENT_MOVE} bloqué!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_ABILITY} du\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} fait tomber\lla pluie!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\naugmente sa VITESSE!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} est protégé\npar {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_ABILITY} de\n{B_DEF_NAME_WITH_PREFIX} \pempêche {B_ATK_NAME_WITH_PREFIX}\nd’utiliser {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} restaure ses PV\ngrâce à {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nrend {B_CURRENT_MOVE} inutile!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nle transforme en type {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_DEF_ABILITY} du {B_EFF_NAME_WITH_PREFIX}\nempêche la paralysie!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nempêche la romance!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_DEF_ABILITY} du {B_EFF_NAME_WITH_PREFIX}\nempêche l’empoisonnement!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nempêche la confusion!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\naugmente sa puissance de FEU!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} s’accroche\navec {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_ABILITY} du\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} réduit\ll’ATTAQUE du {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nempêche la perte de stats!");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nblesse {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} CALQUE\n{B_BUFF2} du\l{B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_ABILITY} du {B_EFF_NAME_WITH_PREFIX}\nempêche les brûlures!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nbloque {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbloque {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_ABILITY} du {B_ATK_NAME_WITH_PREFIX}\nrestaure un peu ses PV!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nprovoque une tempête de sable!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nintensifie les rayons du soleil!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nempêche {B_BUFF1} de baisser!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nrend {B_ATK_NAME_WITH_PREFIX} amoureux!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nrend {B_CURRENT_MOVE} inefficace!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguérit son problème de {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("Il aspire le\nSUINTEMENT!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} se transforme!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nreçoit l’attaque!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_LAST_ABILITY} du {B_BUFF1}\nempêche l’échange!\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_ABILITY} du {B_DEF_NAME_WITH_PREFIX}\nempêche {B_BUFF1} du\l{B_SCR_ACTIVE_NAME_WITH_PREFIX} de fonctionner!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle rend inefficace!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_ABILITY} du {B_EFF_NAME_WITH_PREFIX}\nempêche la peur!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_ABILITY} du {B_ATK_NAME_WITH_PREFIX}\nempêche {B_DEF_ABILITY} du\l{B_DEF_NAME_WITH_PREFIX} de fonctionner!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_ABILITY} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguérit son problème de {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_ABILITY} du\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}\pest inefficace sur\n{B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("monte beaucoup!");
const u8 gText_StatRose[] = _("augmente!");
static const u8 sText_StatHarshly[] = _("baisse beaucoup!");
static const u8 sText_StatFell[] = _("baisse!");
static const u8 sText_AttackersStatRose[] = _("Ah, {B_BUFF1} du {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("Ah, {B_BUFF1} du {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Avec {B_LAST_ITEM}, {B_BUFF1} du\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_BUFF1} du {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("Ah, {B_BUFF1} du {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("Les stats du {B_ATK_NAME_WITH_PREFIX}\nn’iront pas plus haut!");
static const u8 sText_StatsWontDecrease2[] = _("Les stats du {B_DEF_NAME_WITH_PREFIX}\nn’iront pas plus bas!");
static const u8 sText_CriticalHit[] = _("Coup critique!");
static const u8 sText_OneHitKO[] = _("K.O. en un coup!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2 et{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Tadaa!\p");
static const u8 sText_AndEllipsis[] = _("Et…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Impossible d’oublier les\ncapacités CS maintenant.\p");
static const u8 sText_NotVeryEffective[] = _("Ce n’est pas très efficace…");
static const u8 sText_SuperEffective[] = _("C’est super efficace!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Vous prenez la fuite!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fuit en\nutilisant {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fuit en\nutilisant {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}{B_BUFF1} sauvage fuit!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("{B_LINK_OPPONENT1_NAME} a perdu!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{B_LINK_OPPONENT2_NAME} et {B_LINK_OPPONENT1_NAME}\nont perdu!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{B_LINK_OPPONENT1_NAME} a gagné!");
static const u8 sText_PlayerLostToTwo[] = _("{B_LINK_OPPONENT2_NAME} et {B_LINK_OPPONENT1_NAME}\nont gagné!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("Egalité avec \n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("Egalité avec\n{B_LINK_OPPONENT2_NAME} et {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} s’enfuit!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} et\n{B_LINK_OPPONENT2_NAME} s’enfuient!");
static const u8 sText_NoRunningFromTrainers[] = _("On ne s’enfuit pas d’un\ncombat de DRESSEURS!\p");
static const u8 sText_CantEscape[] = _("Fuite impossible!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. SEKO: Ne me laisse pas\ncomme ça!\p");
static const u8 sText_ButNothingHappened[] = _("Mais rien ne se passe!");
static const u8 sText_ButItFailed[] = _("Mais cela échoue!");
static const u8 sText_ItHurtConfusion[] = _("Il se blesse dans sa\nconfusion.");
static const u8 sText_MirrorMoveFailed[] = _("La MIMIQUE échoue!");
static const u8 sText_StartedToRain[] = _("Il commence à pleuvoir!");
static const u8 sText_DownpourStarted[] = _("Une pluie torrentielle commence!");
static const u8 sText_RainContinues[] = _("La pluie continue de tomber.");
static const u8 sText_DownpourContinues[] = _("La pluie torrentielle continue."); // Unused
static const u8 sText_RainStopped[] = _("La pluie s’est arrêtée.");
static const u8 sText_SandstormBrewed[] = _("Une tempête de sable\nse prépare!");
static const u8 sText_SandstormRages[] = _("La tempête de sable\nfait rage.");
static const u8 sText_SandstormSubsided[] = _("La tempête de sable\nse calme.");
static const u8 sText_SunlightGotBright[] = _("Les rayons du soleil brillent!");
static const u8 sText_SunlightStrong[] = _("Les rayons du soleil sont forts.");
static const u8 sText_SunlightFaded[] = _("Les rayons du soleil s’affaiblissent.");
static const u8 sText_StartedHail[] = _("Il commence à grêler!");
static const u8 sText_HailContinues[] = _("La grêle continue.");
static const u8 sText_HailStopped[] = _("La grêle s’est arrêtée.");
static const u8 sText_FailedToSpitUp[] = _("Mais la RELACHE a échoué!");
static const u8 sText_FailedToSwallow[] = _("Mais AVALE a échoué!");
static const u8 sText_WindBecameHeatWave[] = _("Le vent se transforme\nen CANICULE!");
static const u8 sText_StatChangesGone[] = _("Les changements de stats\nont tous été annulés!");
static const u8 sText_CoinsScattered[] = _("Une pluie de pièces!");
static const u8 sText_TooWeakForSubstitute[] = _("Trop faible pour créer\nun CLONE!");
static const u8 sText_SharedPain[] = _("Les adversaires se partagent\nles dégâts!");
static const u8 sText_BellChimed[] = _("Un GRELOT sonne!");
static const u8 sText_FaintInThree[] = _("Les POKéMON au combat seront\nK.O. dans 3 tours!");
static const u8 sText_NoPPLeft[] = _("Il n’y a plus de PP pour\ncette capacité!\p");
static const u8 sText_ButNoPPLeft[] = _("Mais il n’y a plus de PP pour\ncette capacité!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignore les ordres\net pionce!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignore les\nordres!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} fait la sieste!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} paresse!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} n’obéit pas!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} tourne le dos!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} fait semblant de\nne rien remarquer!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_BUFF2} va être envoyé par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}.\pVoulez-vous changer\nde POKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} apprend\n{B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Vous avez battu\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME} se rapproche de\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} ne peut pas\ns’approcher plus!");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} surveille\nattentivement!");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} est intéressé par\n{B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} est captivé par\n{B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} ignore complètement\n{B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} lance un {POKEBLOCK}\nà {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}ANNONCEUR: Vous n’avez plus de\nSAFARI BALLS! Perdu!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("Un {B_OPPONENT_MON1_NAME} sauvage apparaît!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Un {B_OPPONENT_MON1_NAME} sauvage apparaît!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Un {B_OPPONENT_MON1_NAME} sauvage apparaît!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Un {B_OPPONENT_MON2_NAME} et un {B_OPPONENT_MON1_NAME}\nsauvages apparaissent!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("Un combat est lancé\npar {B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{B_LINK_OPPONENT1_NAME}\nveut se battre!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{B_LINK_OPPONENT1_NAME} et {B_LINK_OPPONENT2_NAME}\nveulent se battre!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_OPPONENT_MON1_NAME} est envoyé par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_OPPONENT_MON1_NAME} et {B_OPPONENT_MON2_NAME} sont\nenvoyés par\l{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_BUFF1} est envoyé par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} envoie\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} envoie\n{B_OPPONENT_MON1_NAME} et {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} envoie\n{B_LINK_OPPONENT_MON1_NAME}!\p{B_LINK_OPPONENT2_NAME} envoie\n{B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} envoie\n{B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} envoie\n{B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("{B_PLAYER_MON1_NAME}! Go!");
static const u8 sText_GoTwoPkmn[] = _("{B_PLAYER_MON1_NAME} et\n{B_PLAYER_MON2_NAME}! Go!");
static const u8 sText_GoPkmn2[] = _("{B_BUFF1}! Go!");
static const u8 sText_DoItPkmn[] = _("{B_BUFF1}! Fonce!");
static const u8 sText_GoForItPkmn[] = _("En avant, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("L’ennemi est faible!\nAttaque, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} envoie\n{B_LINK_PLAYER_MON2_NAME}!\p{B_LINK_PLAYER_MON1_NAME}! Go!");
static const u8 sText_PkmnThatsEnough[] = _("Ça suffit, {B_BUFF1}!\nReviens!");
static const u8 sText_PkmnComeBack[] = _("Reviens, {B_BUFF1}!");
static const u8 sText_PkmnOkComeBack[] = _("OK, {B_BUFF1}!\nReviens!");
static const u8 sText_PkmnGoodComeBack[] = _("Bien, {B_BUFF1}!\nReviens!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_BUFF1} est retiré par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} retire\n{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} retire\n{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _(" sauvage");
static const u8 sText_FoePkmnPrefix[] = _(" ennemi");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("ennemi");
static const u8 sText_AllyPkmnPrefix[] = _("ami");
static const u8 sText_FoePkmnPrefix3[] = _("ennemi");
static const u8 sText_AllyPkmnPrefix2[] = _("ami");
static const u8 sText_FoePkmnPrefix4[] = _("ennemi");
static const u8 sText_AllyPkmnPrefix3[] = _("ami");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} utilise\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("PV");
static const u8 sText_Attack2[] = _("ATTAQUE");
static const u8 sText_Defense2[] = _("DEFENSE");
static const u8 sText_Speed[] = _("VITESSE");
static const u8 sText_SpAtk2[] = _("ATQ SP");
static const u8 sText_SpDef2[] = _("DEF SP");
static const u8 sText_Accuracy[] = _("précision");
static const u8 sText_Evasiveness[] = _("esquive");
#elif ITALIAN
static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} riceve{B_BUFF2} \n{B_BUFF3} punti ESP.!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" la bellezza di");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1} sale al L. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} impara {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} sta cercando di imparare\n{B_BUFF2}!\p");
static const u8 sText_TryToLearnMove2[] = _("Ma {B_BUFF1} non può conoscere\npiù di quattro mosse.\p");
static const u8 sText_TryToLearnMove3[] = _("Vuoi cancellare una mossa per\nfar posto a {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} scorda {B_BUFF2}!\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}Bloccare l’apprendimento\ndi {B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} non ha imparato\n{B_BUFF2}!\p");
static const u8 sText_UseNextPkmn[] = _("Usare un altro POKéMON?");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX} fallisce!");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX} si protegge!");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} evita\nil colpo con {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX} neutralizza le\nmosse di TERRA con {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} evita l’attacco!");
static const u8 sText_ItDoesntAffect[] = _("Non ha effetto su\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX} è esausto!\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX} è esausto!\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} vince\n¥{B_BUFF1}!\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME} non ha più\nPOKéMON utili!\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} è fuori combattimento!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} impedisce\nla fuga con {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("Non si scappa!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX}\nnon può scappare!");
static const u8 sText_HitXTimes[] = _("Colpi subiti: {B_BUFF1}!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\ns’è addormentato!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\naddormenta {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} sta già dormendo!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} sta già dormendo!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX} è incolume!");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX} è stato \navvelenato!");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\navvelena {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("Il veleno ha effetto\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} è già\navvelenato.");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nè iperavvelenato!");
static const u8 sText_PkmnEnergyDrained[] = _("Viene prelevata energia\nda {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} è stato \nscottato!");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nscotta {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} soffre\nper la scottatura!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} è già scottato.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} è stato\ncongelato!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncongela {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} è congelato!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} è stato\nscongelato!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} è stato\nscongelato!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} è stato\nscongelato da {B_CURRENT_MOVE}!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} è stato\nparalizzato!\lForse non riuscirà ad attaccare!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nparalizza {B_EFF_NAME_WITH_PREFIX}!\lForse non riuscirà ad attaccare!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} è paralizzato!\nNon può attaccare!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX}\nè già paralizzato!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX}\nè guarito dalla paralisi!");
static const u8 sText_PkmnDreamEaten[] = _("Mangia il sogno di\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_StatsWontIncrease[] = _("Non aumenta\n{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}.");
static const u8 sText_StatsWontDecrease[] = _("Non diminuisce \n{B_BUFF1} di {B_DEF_NAME_WITH_PREFIX}.");
static const u8 sText_TeamStoppedWorking[] = _("{B_BUFF1} della tua squadra\nnon funziona!");
static const u8 sText_FoeStoppedWorking[] = _("{B_BUFF1} dell’avversario\nnon funziona!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} è confuso!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} \nnon è più confuso!");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX} è stato confuso!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} è già confuso!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX} è innamorato!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} è innamorato\ndi {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("L’innamoramento impedisce\na {B_ATK_NAME_WITH_PREFIX} di attaccare!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} è spazzato via!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} si trasforma\nnel tipo {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} tentenna!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} s’è ripreso!");
static const u8 sText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX} ha tutti i PS!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta la DIF. SP.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta un po’ la DIF. SP.!");
static const u8 sText_PkmnRaisedDef[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta la DIFESA!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta un po’ la DIFESA!");
static const u8 sText_PkmnCoveredByVeil[] = _("Un velo ricopre la squadra\ndel POKéMON {B_ATK_PREFIX2}!");
static const u8 sText_PkmnUsedSafeguard[] = _("SALVAGUARDIA protegge\nla squadra di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSafeguardExpired[] = _("Cade SALVAGUARDIA della\nsquadra del POKéMON {B_ATK_PREFIX3}!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} va a dormire!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX}\ndorme e si riprende!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX}\ngenera un turbine!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} assorbe la luce!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} \nabbassa la testa!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} sta brillando!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} vola in alto!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} scava una fossa!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} \nsparisce sott’acqua!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} salta fuori!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_ATK_NAME_WITH_PREFIX} stritola\n{B_DEF_NAME_WITH_PREFIX} con LEGATUTTO!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} è intrappolato\nnel vortice!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} è intrappolato\nda SABBIOTOMBA!");
static const u8 sText_PkmnWrappedBy[] = _("{B_ATK_NAME_WITH_PREFIX} usa AVVOLGI-\nBOTTA su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} usa\nTENAGLIA su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} è ferito\nda {B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} è liberato\nda {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX}\nsi sbilancia e si schianta!");
const u8 gText_PkmnShroudedInMist[] = _("Il POKéMON {B_ATK_PREFIX2}\nè avvolto dalla NEBBIA!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nè protetto dalla NEBBIA!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX} si gonfia!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX}\nsubisce il contraccolpo!");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX} è pronto a \nproteggersi!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\nda una tempesta di sabbia!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\nda GRANDINE!");
static const u8 sText_PkmnsXWoreOff[] = _("Finito l’effetto di\n{B_BUFF1} del POKéMON {B_ATK_PREFIX1}!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} è pieno di semi!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} schiva l’attacco!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("PARASSISEME sottrae energia\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} dorme.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} si è svegliato!");
static const u8 sText_PkmnUproarKeptAwake[] = _("Ma BARAONDA di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} lo tiene sveglio!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} si sveglia\na causa di BARAONDA!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} scatena\nuna BARAONDA!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} sta facendo\nuna BARAONDA!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} si calma.");
static const u8 sText_PkmnCantSleepInUproar[] = _("Ma {B_DEF_NAME_WITH_PREFIX} non riesce\na dormire con BARAONDA!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} usa ACCUMULO:\n{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} non può più\nusare ACCUMULO!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("Ma {B_DEF_NAME_WITH_PREFIX} non riesce\na dormire con BARAONDA!");
static const u8 sText_UproarKeptPkmnAwake[] = _("Ma BARAONDA di\n{B_DEF_NAME_WITH_PREFIX} lo tiene sveglio!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} rimane sveglio\ngrazie a {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} \naccumula energia!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} libera energia!");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} è confuso\nper la fatica!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} raccoglie ¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX} è incolume!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} si trasforma\nin {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} crea \nun SOSTITUTO!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} ha già\nun SOSTITUTO!");
static const u8 sText_SubstituteDamaged[] = _("Il SOSTITUTO è colpito\nal posto di {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("Il SOSTITUTO di\n{B_DEF_NAME_WITH_PREFIX} svanisce!\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} deve ricaricarsi!");
static const u8 sText_PkmnRageBuilding[] = _("Cresce l’IRA di\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMoveWasDisabled[] = _("INIBITORE ha messo {B_BUFF1}\ndi {B_DEF_NAME_WITH_PREFIX} fuori uso!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("Termina l’effetto di INIBITORE\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX} è colpito\nda RIPETI!");
static const u8 sText_PkmnEncoreEnded[] = _("Termina l’effetto di RIPETI\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} prende\nla mira su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} disegna\nuno SCHIZZO di {B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} tenta di\ntrascinare con sé l’avversario!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} trascina\ncon sé {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnReducedPP[] = _("{B_BUFF1} di {B_DEF_NAME_WITH_PREFIX}\ncala di {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} ruba\n{B_LAST_ITEM} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX} \nnon può scappare!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} ha un INCUBO!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} è\nintrappolato in un INCUBO!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} riduce i suoi PS\nper lanciare una MALEDIZIONE\lsu {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\ndalla MALEDIZIONE!");
static const u8 sText_SpikesScattered[] = _("Ci sono PUNTE ovunque!");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nsoffre per le PUNTE!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identifica\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("ULTIMOCANTO di\n{B_ATK_NAME_WITH_PREFIX}: meno {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} si rinvigorisce!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} RESISTE!");
static const u8 sText_MagnitudeStrength[] = _("MAGNITUDO {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} riduce i suoi PS\nper massimizzare l’ATTACCO!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copia modifiche\nstatistiche di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} si libera da\n{B_BUFF1} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}\nsparge PARASSISEME!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX}\nspazza via le PUNTE!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} se la dà a\ngambe!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} \nprevede l’attacco!");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} subisce\n{B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} sceglie\n{B_CURRENT_MOVE} come suo destino!");
static const u8 sText_PkmnAttack[] = _("Attacco di {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX} è al\ncentro dell’attenzione!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX}\ninizia a caricarsi!");
static const u8 sText_NaturePowerTurnedInto[] = _("NATURFORZA si trasforma in\n{B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("Lo stato di {B_ATK_NAME_WITH_PREFIX}\ntorna normale!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} subisce\nl’ATTACCALITE!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} \nrestringe la mira!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX}\nè in balia di PROVOCAZIONE!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} è pronto ad\naiutare {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} scambia\nlo strumento!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} ottiene\n{B_BUFF1}!");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} ottiene\n{B_BUFF2}!");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} ottiene\n{B_BUFF1}!\p{B_DEF_NAME_WITH_PREFIX} ottiene\n{B_BUFF2}!");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copia\n{B_DEF_ABILITY} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX}\nesprime un DESIDERIO!");
static const u8 sText_PkmnWishCameTrue[] = _("Il DESIDERIO di {B_BUFF1}\nsi avvera!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} pianta le radici!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} assorbe\nsostanze nutritive con le radici!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} è ancorato\nal suolo grazie alle radici!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} fa\nassopire {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} blocca\n{B_LAST_ITEM} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} scambia abilità!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} blocca una\no più mosse dell’avversario!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} serba\nRANCORE all’avversario!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}\nperde tutti i PP\la causa di RANCORE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} si avvolge\nin {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_CURRENT_MOVE} di {B_ATK_NAME_WITH_PREFIX}\nrimbalza a causa di MAGIVELO!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} aspetta\nla mossa dell’avversario!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} ruba la mossa di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} con SCIPPO!");
static const u8 sText_ElectricityWeakened[] = _("La potenza dell’elettricità\nè stata indebolita!");
static const u8 sText_FireWeakened[] = _("La potenza del fuoco\nè stata indebolita!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX}\ntrova {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("La zona è pervasa da\nun piacevole profumo!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Impossibile usare strumenti qui.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("Per {B_SCR_ACTIVE_NAME_WITH_PREFIX},\nla {B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} usa\n{B_LAST_ITEM}: aumentano\li brutti colpi!");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} perde la mira\ne rimane immobile!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} è tirato dentro!\p");
static const u8 sText_TheWallShattered[] = _("La barriera si frantuma!");
static const u8 sText_ButNoEffect[] = _("Ma è inefficace!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX}\nnon ha più mosse!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("A causa di INIBITORE, {B_CURRENT_MOVE}\ndi {B_ACTIVE_NAME_WITH_PREFIX} è fuori uso!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare la\nstessa mossa 2 volte per\ll’ATTACCALITE!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare\n{B_CURRENT_MOVE} dopo PROVOCAZIONE!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare\nla mossa bloccata {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nprovoca la pioggia!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\naumenta la VELOCITÀ!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} è protetto\nda {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nimpedisce a {B_ATK_NAME_WITH_PREFIX}\ldi usare {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} ricarica PS\nusando {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nneutralizza {B_CURRENT_MOVE}!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nlo ha reso di tipo {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_DEF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene la paralisi!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\npreviene l’innamoramento!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_DEF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene l’avvelenamento!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\npreviene la confusione!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\naumenta la potenza del tipo FUOCO!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} è ancorato\nal suolo grazie a {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nriduce ATT. di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita calo delle statistiche!");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\ncolpisce {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} TRACCIA\n{B_BUFF2} di\l{B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene le scottature!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nblocca {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nblocca {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_ABILITY} di {B_ATK_NAME_WITH_PREFIX}\nristabilisce parte dei PS!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ngenera una tempesta di sabbia!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nintensifica i raggi solari!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita calo di {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nfa infatuare {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nrende inefficace {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("Succhia la MELMA!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} si trasforma!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nriceve l’attacco!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_LAST_ABILITY} di {B_BUFF1}\nevita lo scambio!\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nblocca {B_BUFF1}\ldi {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha neutralizzato!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\nevita il tentennamento!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_ABILITY} di {B_ATK_NAME_WITH_PREFIX}\nblocca {B_DEF_ABILITY}\ldi {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nnon agisce su {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("sale di molto!");
const u8 gText_StatRose[] = _("sale!");
static const u8 sText_StatHarshly[] = _("cala a picco!");
static const u8 sText_StatFell[] = _("cala!");
static const u8 sText_AttackersStatRose[] = _("Ehi, {B_BUFF1} di \n{B_ATK_NAME_WITH_PREFIX} {B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("Ehi, {B_BUFF1} di\n{B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Con {B_LAST_ITEM}, {B_BUFF1} di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("Ehi, {B_BUFF1} di\n{B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("Statistiche di {B_ATK_NAME_WITH_PREFIX}\nnon aumenteranno!");
static const u8 sText_StatsWontDecrease2[] = _("Statistiche di {B_DEF_NAME_WITH_PREFIX}\nnon caleranno!");
static const u8 sText_CriticalHit[] = _("Brutto colpo!");
static const u8 sText_OneHitKO[] = _("KO in un attacco!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2 e{PAUSE 15}… {PAUSE 15}… {PAUSE 15}…{PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1} puf!\p");
static const u8 sText_AndEllipsis[] = _("Al suo posto…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Ora è impossibile\nscordare mosse MN.\p");
static const u8 sText_NotVeryEffective[] = _("Non è molto efficace…");
static const u8 sText_SuperEffective[] = _("È superefficace!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Scampato pericolo!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugge\nusando {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugge\nusando {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}{B_BUFF1} selvatico fugge!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("Hai avuto la meglio su\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{B_LINK_OPPONENT2_NAME} e {B_LINK_OPPONENT1_NAME} hanno\nperso la sfida!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{B_LINK_OPPONENT1_NAME}\nha vinto la sfida!");
static const u8 sText_PlayerLostToTwo[] = _("{B_LINK_OPPONENT2_NAME} e {B_LINK_OPPONENT1_NAME}\nhanno vinto la sfida!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("La sfida contro {B_LINK_OPPONENT1_NAME}\nsi è conclusa in parità!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("La sfida contro {B_LINK_OPPONENT2_NAME} e\n{B_LINK_OPPONENT1_NAME} si è conclusa in\lparità!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} se l’è data a gambe!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} e\n{B_LINK_OPPONENT2_NAME} se la sono data a gambe!");
static const u8 sText_NoRunningFromTrainers[] = _("Non puoi sottrarti alla\nlotta con un ALLENATORE!\p");
static const u8 sText_CantEscape[] = _("Non si scappa!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. BIRCH: Non lasciarmi qui così!\p");
static const u8 sText_ButNothingHappened[] = _("Ma non succede nulla!");
static const u8 sText_ButItFailed[] = _("Ma fallisce!");
static const u8 sText_ItHurtConfusion[] = _("È così confuso da\ncolpirsi da solo!");
static const u8 sText_MirrorMoveFailed[] = _("La SPECULMOSSA ha fallito!");
static const u8 sText_StartedToRain[] = _("Inizia a piovere!");
static const u8 sText_DownpourStarted[] = _("Inizia un acquazzone!");
static const u8 sText_RainContinues[] = _("Continua a piovere.");
static const u8 sText_DownpourContinues[] = _("L’acquazzone continua.");
static const u8 sText_RainStopped[] = _("Ha smesso di piovere.");
static const u8 sText_SandstormBrewed[] = _("Sta arrivando una tempesta di sabbia!");
static const u8 sText_SandstormRages[] = _("La tempesta di sabbia imperversa!");
static const u8 sText_SandstormSubsided[] = _("La tempesta di sabbia cessa.");
static const u8 sText_SunlightGotBright[] = _("La luce solare diventa intensa!");
static const u8 sText_SunlightStrong[] = _("La luce solare è fortissima!");
static const u8 sText_SunlightFaded[] = _("La luce solare torna normale!");
static const u8 sText_StartedHail[] = _("Inizia a grandinare!");
static const u8 sText_HailContinues[] = _("Continua a grandinare.");
static const u8 sText_HailStopped[] = _("Ha smesso di grandinare.");
static const u8 sText_FailedToSpitUp[] = _("Ma SFOGHENERGIA\nfallisce!");
static const u8 sText_FailedToSwallow[] = _("Ma INTROENERGIA\nfallisce!");
static const u8 sText_WindBecameHeatWave[] = _("Il vento si è trasformato in\nONDACALDA!");
static const u8 sText_StatChangesGone[] = _("Eliminate tutte le modifiche\ndelle statistiche!");
static const u8 sText_CoinsScattered[] = _("Ci sono monete sparse ovunque!");
static const u8 sText_TooWeakForSubstitute[] = _("Troppo debole! Non può creare\nun SOSTITUTO!");
static const u8 sText_SharedPain[] = _("I POKéMON condividono\ni PS!");
static const u8 sText_BellChimed[] = _("Suona la campana!");
static const u8 sText_FaintInThree[] = _("Tutti i POKéMON che la ascoltano\nsaranno esausti in tre turni!");
static const u8 sText_NoPPLeft[] = _("Non ha più PP per\nquesta mossa!\p");
static const u8 sText_ButNoPPLeft[] = _("Ma non ha più PP per\nquesta mossa!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignora gli\nordini, sta dormendo!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignora gli\nordini!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} fa un riposino!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} sta ciondolando!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} non obbedisce!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} disobbedisce!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} fa finta \ndi niente!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("La prossima scelta di {B_TRAINER1_NAME},\n{B_TRAINER1_CLASS}, sarà {B_BUFF2}.\p{B_PLAYER_NAME}, vuoi cambiare\nPOKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} impara {B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Hai avuto la meglio su\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME} si avvicina a\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} non può avvicinarsi ancora!");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} guarda\nattentamente!");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} guarda con\ncuriosità la {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} è ammaliato\ndalla {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} ignora completamente\nla {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} lancia una {POKEMELLA}\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}ANNUNCIO: Hai finito tutte le\nSAFARI BALL! Fine del gioco!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Appaiono {B_OPPONENT_MON2_NAME} e\n{B_OPPONENT_MON1_NAME} selvatici!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("Parte la sfida di\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn[] = _("È il turno di {B_OPPONENT_MON1_NAME}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("Ecco {B_OPPONENT_MON1_NAME} e {B_OPPONENT_MON2_NAME},\nmandati in campo da\l{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("È il turno di {B_BUFF1}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda\nin campo {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda in campo\n{B_OPPONENT_MON1_NAME} e {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda in campo\n{B_LINK_OPPONENT_MON1_NAME}!\p{B_LINK_OPPONENT2_NAME} manda in campo\n{B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} manda\nin campo {B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} manda\nin campo {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Vai, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Avanti, {B_PLAYER_MON1_NAME} e\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Vai, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Dai, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Coraggio, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Nemico debole!\nForza, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} manda in campo\n{B_LINK_PLAYER_MON2_NAME}!\pVai, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, basta così!\nRientra!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, rientra!");
static const u8 sText_PkmnOkComeBack[] = _("{B_BUFF1}, OK!\nRientra!");
static const u8 sText_PkmnGoodComeBack[] = _("{B_BUFF1}, bene!\nRientra!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_BUFF1} è ritirato dalla lotta\nda {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} ritira\n{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} ritira\n{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _(" selvatico");
static const u8 sText_FoePkmnPrefix[] = _(" nemico");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("nemico");
static const u8 sText_AllyPkmnPrefix[] = _("amico");
static const u8 sText_FoePkmnPrefix3[] = _("nemico");
static const u8 sText_AllyPkmnPrefix2[] = _("amico");
static const u8 sText_FoePkmnPrefix4[] = _("nemico");
static const u8 sText_AllyPkmnPrefix3[] = _("amico");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} usa\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("PS");
static const u8 sText_Attack2[] = _("ATTACCO");
static const u8 sText_Defense2[] = _("DIFESA");
static const u8 sText_Speed[] = _("VELOC.");
static const u8 sText_SpAtk2[] = _("ATT. SP.");
static const u8 sText_SpDef2[] = _("DIF. SP.");
static const u8 sText_Accuracy[] = _("precisione");
static const u8 sText_Evasiveness[] = _("elusione");
#elif SPANISH
static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("¡{B_BUFF1} ganó {B_BUFF3}\npuntos de EXP.{B_BUFF2}!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" adicionales");
static const u8 sText_PkmnGrewToLv[] = _("¡{B_BUFF1} subió al\nnivel {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("¡{B_BUFF1} aprendió\n{B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} intenta\naprender {B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _("Pero {B_BUFF1} no puede aprender\nmás de cuatro movimientos.\p");
static const u8 sText_TryToLearnMove3[] = _("¿Quieres sustituir uno de esos\nmovimientos por {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} olvidó\n{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}¿Deja de aprender\n{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} no aprendió\n{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("¿Usas el siguiente POKéMON?");
static const u8 sText_AttackMissed[] = _("¡El ataque de\n{B_ATK_NAME_WITH_PREFIX} falló!");
static const u8 sText_PkmnProtectedItself[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nse ha protegido!");
static const u8 sText_AvoidedDamage[] = _("¡{B_DEF_NAME_WITH_PREFIX} se\nprotegió con {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("¡{B_DEF_NAME_WITH_PREFIX} impide ataques\nde TIERRA con {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} evitó\nel ataque!");
static const u8 sText_ItDoesntAffect[] = _("No afecta a\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("¡{B_ATK_NAME_WITH_PREFIX}\nse debilitó!\p");
static const u8 sText_TargetFainted[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nse debilitó!\p");
static const u8 sText_PlayerGotMoney[] = _("¡{B_PLAYER_NAME} ganó\n{B_BUFF1}¥!\p");
static const u8 sText_PlayerWhiteout[] = _("¡A {B_PLAYER_NAME} no le\nquedan POKéMON!\p");
static const u8 sText_PlayerWhiteout2[] = _("¡{B_PLAYER_NAME} está fuera\nde combate!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} impide la\nhuida con {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("¡No puedes huir!\p");
static const u8 sText_AttackerCantEscape[] = _("¡{B_ATK_NAME_WITH_PREFIX}\nno puede escapar!");
static const u8 sText_HitXTimes[] = _("N.º de golpes: {B_BUFF1}.");
static const u8 sText_PkmnFellAsleep[] = _("¡{B_EFF_NAME_WITH_PREFIX}\nse durmió!");
static const u8 sText_PkmnMadeSleep[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ndurmió a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nestá dormido!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("¡{B_ATK_NAME_WITH_PREFIX}\nestá dormido!");
static const u8 sText_PkmnWasntAffected[] = _("¡{B_DEF_NAME_WITH_PREFIX} no se\nvio afectado!");
static const u8 sText_PkmnWasPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX}\nfue envenenado!");
static const u8 sText_PkmnPoisonedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nenvenenó a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("¡El veneno resta salud\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX}\nestá envenenado.");
static const u8 sText_PkmnBadlyPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue \ngravemente envenenado!");
static const u8 sText_PkmnEnergyDrained[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha perdido\nenergía!");
static const u8 sText_PkmnWasBurned[] = _("¡{B_EFF_NAME_WITH_PREFIX} se ha quemado!");
static const u8 sText_PkmnBurnedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nquemó a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("¡{B_ATK_NAME_WITH_PREFIX} se resiente\nde la quemadura!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} \nya está quemado.");
static const u8 sText_PkmnWasFrozen[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue\ncongelado!");
static const u8 sText_PkmnFrozenBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncongeló a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\ncongelado!");
static const u8 sText_PkmnWasDefrosted[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nno está congelado!");
static const u8 sText_PkmnWasDefrosted2[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya\nno está congelado!");
static const u8 sText_PkmnWasDefrostedBy[] = _("¡{B_CURRENT_MOVE} descongeló\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWasParalyzed[] = _("¡{B_EFF_NAME_WITH_PREFIX} está paralizado!\n¡Quizás no se mueva!");
static const u8 sText_PkmnWasParalyzedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nparalizó a {B_EFF_NAME_WITH_PREFIX}!\l¡Quizás no se mueva!");
static const u8 sText_PkmnIsParalyzed[] = _("¡{B_ATK_NAME_WITH_PREFIX} está paralizado!\n¡No se puede mover!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nestá paralizado!");
static const u8 sText_PkmnHealedParalysis[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nno está paralizado!");
static const u8 sText_PkmnDreamEaten[] = _("¡Se comió el sueño\nde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_StatsWontIncrease[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\nno subirá más!");
static const u8 sText_StatsWontDecrease[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nno bajará más!");
static const u8 sText_TeamStoppedWorking[] = _("¡{B_BUFF1} no funciona\nen tu equipo!");
static const u8 sText_FoeStoppedWorking[] = _("¡{B_BUFF1} no funciona\nen el equipo rival!");
static const u8 sText_PkmnIsConfused[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nconfuso!");
static const u8 sText_PkmnHealedConfusion[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya\nno está confuso!");
static const u8 sText_PkmnWasConfused[] = _("¡{B_EFF_NAME_WITH_PREFIX} se\nencuentra confuso!");
static const u8 sText_PkmnAlreadyConfused[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nestá confuso!");
static const u8 sText_PkmnFellInLove[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha\nenamorado!");
static const u8 sText_PkmnInLove[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha enamorado\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("¡El amor impide que\n{B_ATK_NAME_WITH_PREFIX} ataque!");
static const u8 sText_PkmnBlownAway[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue\narrastrado!");
static const u8 sText_PkmnChangedType[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha cambiado \nal tipo {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("¡{B_ATK_NAME_WITH_PREFIX} retrocedió!");
static const u8 sText_PkmnRegainedHealth[] = _("¡{B_DEF_NAME_WITH_PREFIX} recuperó\nsalud!");
static const u8 sText_PkmnHPFull[] = _("¡Los PS de {B_DEF_NAME_WITH_PREFIX}\nestán al máximo!");
static const u8 sText_PkmnRaisedSpDef[] = _("¡{B_CURRENT_MOVE} de POKéMON\n{B_ATK_PREFIX2} subió la DEF. ESP.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("¡{B_CURRENT_MOVE} de POKéMON\n{B_ATK_PREFIX2} subió algo la DEF. ESP.!");
static const u8 sText_PkmnRaisedDef[] = _("¡{B_CURRENT_MOVE} de POKéMON\n{B_ATK_PREFIX2} subió la DEFENSA!");
static const u8 sText_PkmnRaisedDefALittle[] = _("¡{B_CURRENT_MOVE} de POKéMON\n{B_ATK_PREFIX2} subió algo la DEFENSA!");
static const u8 sText_PkmnCoveredByVeil[] = _("¡POKéMON {B_ATK_PREFIX2} se \nprotegió con VELO SAGRADO!");
static const u8 sText_PkmnUsedSafeguard[] = _("¡{B_DEF_NAME_WITH_PREFIX} está protegido\npor VELO SAGRADO!");
static const u8 sText_PkmnSafeguardExpired[] = _("¡VELO SAGRADO de POKéMON\n{B_ATK_PREFIX3} dejó de hacer efecto!");
static const u8 sText_PkmnWentToSleep[] = _("¡{B_ATK_NAME_WITH_PREFIX} se fue\na dormir!");
static const u8 sText_PkmnSleptHealthy[] = _("¡{B_ATK_NAME_WITH_PREFIX} recuperó\nsalud durmiendo!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("¡{B_ATK_NAME_WITH_PREFIX} provocó \nun remolino!");
static const u8 sText_PkmnTookSunlight[] = _("¡{B_ATK_NAME_WITH_PREFIX} absorbió \nluz solar!");
static const u8 sText_PkmnLoweredHead[] = _("¡{B_ATK_NAME_WITH_PREFIX} bajó \nla cabeza!");
static const u8 sText_PkmnIsGlowing[] = _("¡{B_ATK_NAME_WITH_PREFIX} está rodeado\nde una luz brillante!");
static const u8 sText_PkmnFlewHigh[] = _("¡{B_ATK_NAME_WITH_PREFIX} voló\nmuy alto!");
static const u8 sText_PkmnDugHole[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nocultó en un agujero!");
static const u8 sText_PkmnHidUnderwater[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ocultó\nbajo el agua!");
static const u8 sText_PkmnSprangUp[] = _("¡{B_ATK_NAME_WITH_PREFIX} dio un\nsalto tremendo!");
static const u8 sText_PkmnSqueezedByBind[] = _("¡ATADURA de {B_ATK_NAME_WITH_PREFIX}\noprime a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTrappedInVortex[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue atrapado\nen el torbellino!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("¡BUCLE ARENA atrapó\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWrappedBy[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue atrapado por\nREPETICIÓN de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("¡{B_ATK_NAME_WITH_PREFIX} ATENAZÓ\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("¡{B_BUFF1} ha herido\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFreedFrom[] = _("¡{B_ATK_NAME_WITH_PREFIX} se liberó \nde {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("¡{B_ATK_NAME_WITH_PREFIX} falló\ny se cayó!");
const u8 gText_PkmnShroudedInMist[] = _("¡NEBLINA ha cubierto a\nPOKéMON {B_ATK_PREFIX2}!");
static const u8 sText_PkmnProtectedByMist[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se ha\nprotegido con NEBLINA!");
const u8 gText_PkmnGettingPumped[] = _("¡{B_ATK_NAME_WITH_PREFIX} se está\npreparando para luchar!");
static const u8 sText_PkmnHitWithRecoil[] = _("¡{B_ATK_NAME_WITH_PREFIX} también\nse ha hecho daño!");
static const u8 sText_PkmnProtectedItself2[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nestá protegiendo!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("¡TORMENTA ARENA zarandea\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPeltedByHail[] = _("¡GRANIZO golpea\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXWoreOff[] = _("¡{B_BUFF1} de POKéMON \n{B_ATK_PREFIX1} se agotó!");
static const u8 sText_PkmnSeeded[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue infectado!");
static const u8 sText_PkmnEvadedAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} esquivó\nel ataque!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("¡DRENADORAS restó  \nsalud a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} está\ndormido como un tronco.");
static const u8 sText_PkmnWokeUp[] = _("¡{B_ATK_NAME_WITH_PREFIX} se despertó!");
static const u8 sText_PkmnUproarKeptAwake[] = _("¡Pero el ALBOROTO de \n{B_SCR_ACTIVE_NAME_WITH_PREFIX} no le deja dormir!");
static const u8 sText_PkmnWokeUpInUproar[] = _("¡ALBOROTO despertó a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnCausedUproar[] = _("¡{B_ATK_NAME_WITH_PREFIX}\nmontó un ALBOROTO!");
static const u8 sText_PkmnMakingUproar[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nmontando un ALBOROTO!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} se tranquilizó.");
static const u8 sText_PkmnCantSleepInUproar[] = _("¡Pero {B_DEF_NAME_WITH_PREFIX} no puede\ndormir con el ALBOROTO!");
static const u8 sText_PkmnStockpiled[] = _("¡{B_ATK_NAME_WITH_PREFIX} RESERVÓ\n{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede\nRESERVAR más!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("¡Pero {B_DEF_NAME_WITH_PREFIX} no puede\ndormir con el ALBOROTO!");
static const u8 sText_UproarKeptPkmnAwake[] = _("¡Pero el ALBOROTO mantuvo\ndespierto a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("¡{B_DEF_NAME_WITH_PREFIX} se mantuvo\ndespierto con {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("¡{B_ATK_NAME_WITH_PREFIX} está \nacumulando energía!");
static const u8 sText_PkmnUnleashedEnergy[] = _("¡{B_ATK_NAME_WITH_PREFIX} liberó \nenergía!");
static const u8 sText_PkmnFatigueConfusion[] = _("¡El cansancio terminó \nconfundiendo a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PlayerPickedUpMoney[] = _("¡{B_PLAYER_NAME} recogió\n{B_BUFF1}¥!\p");
static const u8 sText_PkmnUnaffected[] = _("¡No afectó a\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTransformedInto[] = _("¡{B_ATK_NAME_WITH_PREFIX} se transformó \nen {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("¡{B_ATK_NAME_WITH_PREFIX} creó\nun SUSTITUTO!");
static const u8 sText_PkmnHasSubstitute[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya tiene\nun SUSTITUTO!");
static const u8 sText_SubstituteDamaged[] = _("¡El SUSTITUTO recibe el daño\nen lugar de {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("¡El SUSTITUTO de\n{B_DEF_NAME_WITH_PREFIX} se debilitó!\p");
static const u8 sText_PkmnMustRecharge[] = _("¡{B_ATK_NAME_WITH_PREFIX} necesita\nrecuperarse de su ataque!");
static const u8 sText_PkmnRageBuilding[] = _("¡La FURIA de {B_DEF_NAME_WITH_PREFIX}\nestá creciendo!");
static const u8 sText_PkmnMoveWasDisabled[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nfue desactivado con ANULACIÓN!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nha liberado de ANULACIÓN!");
static const u8 sText_PkmnGotEncore[] = _("¡{B_DEF_NAME_WITH_PREFIX} sufrió los\nefectos de OTRA VEZ!");
static const u8 sText_PkmnEncoreEnded[] = _("¡OTRA VEZ ya no hace\nefecto en {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTookAim[] = _("¡{B_ATK_NAME_WITH_PREFIX} apuntó\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó ESQUEMA\nen {B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("¡{B_ATK_NAME_WITH_PREFIX} intenta\nllevarse a su rival!");
static const u8 sText_PkmnTookFoe[] = _("¡{B_DEF_NAME_WITH_PREFIX} se llevó\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnReducedPP[] = _("¡Redujo {B_BUFF1}\nde {B_DEF_NAME_WITH_PREFIX} en {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("¡{B_ATK_NAME_WITH_PREFIX} robó\n{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("¡{B_DEF_NAME_WITH_PREFIX} no \npuede escapar!");
static const u8 sText_PkmnFellIntoNightmare[] = _("¡{B_DEF_NAME_WITH_PREFIX} cae en \nuna PESADILLA!");
static const u8 sText_PkmnLockedInNightmare[] = _("¡{B_ATK_NAME_WITH_PREFIX} está inmerso\nen una PESADILLA!");
static const u8 sText_PkmnLaidCurse[] = _("¡{B_ATK_NAME_WITH_PREFIX} reduce sus PS\ny MALDICE a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("¡{B_ATK_NAME_WITH_PREFIX} es víctima \nde una MALDICIÓN!");
static const u8 sText_SpikesScattered[] = _("¡El equipo POKéMON {B_DEF_PREFIX1}\nha sido rodeado de PÚAS!");
static const u8 sText_PkmnHurtBySpikes[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha sido\nherido por PÚAS!");
static const u8 sText_PkmnIdentified[] = _("¡{B_ATK_NAME_WITH_PREFIX} identificó\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("¡Contador de salud de\n{B_ATK_NAME_WITH_PREFIX} bajó a {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nfortalecido!");
static const u8 sText_PkmnEnduredHit[] = _("¡{B_DEF_NAME_WITH_PREFIX} AGUANTÓ\nel golpe!");
static const u8 sText_MagnitudeStrength[] = _("¡MAGNITUD {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("¡{B_ATK_NAME_WITH_PREFIX} redujo sus PS\ny mejoró su ATAQUE!");
static const u8 sText_PkmnCopiedStatChanges[] = _("¡{B_ATK_NAME_WITH_PREFIX} copió las nuevas \ncaracteríst. de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("¡{B_ATK_NAME_WITH_PREFIX} se liberó de\n{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nliberó de DRENADORAS!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nliberó de PÚAS!");
static const u8 sText_PkmnFledFromBattle[] = _("¡{B_ATK_NAME_WITH_PREFIX} huyó del\ncombate!");
static const u8 sText_PkmnForesawAttack[] = _("¡{B_ATK_NAME_WITH_PREFIX} previó\nun ataque!");
static const u8 sText_PkmnTookAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} tomó \nel ataque de {B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("¡{B_ATK_NAME_WITH_PREFIX} usará\n{B_CURRENT_MOVE} más adelante!");
static const u8 sText_PkmnAttack[] = _("¡Ataque de {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("¡{B_ATK_NAME_WITH_PREFIX} se convirtió en\nel centro de atención!");
static const u8 sText_PkmnChargingPower[] = _("¡{B_ATK_NAME_WITH_PREFIX} comenzó \na cargar energía!");
static const u8 sText_NaturePowerTurnedInto[] = _("¡ADAPTACIÓN se convirtió \nen {B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("¡El estado de {B_ATK_NAME_WITH_PREFIX}\nregresó a la normalidad!");
static const u8 sText_PkmnSubjectedToTorment[] = _("¡{B_DEF_NAME_WITH_PREFIX} es víctima\nde TORMENTO!");
static const u8 sText_PkmnTighteningFocus[] = _("¡{B_ATK_NAME_WITH_PREFIX} está reforzando\nsu concentración!");
static const u8 sText_PkmnFellForTaunt[] = _("¡{B_DEF_NAME_WITH_PREFIX} se dejó\nengañar por MOFA!");
static const u8 sText_PkmnReadyToHelp[] = _("¡{B_ATK_NAME_WITH_PREFIX} está listo para\nayudar a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("¡{B_ATK_NAME_WITH_PREFIX} provocó \nun cambio de objeto!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} obtuvo\n{B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} obtuvo\n{B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} obtuvo\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtuvo\n{B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _("¡{B_ATK_NAME_WITH_PREFIX} copió\n{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("¡{B_ATK_NAME_WITH_PREFIX} pidió un DESEO!");
static const u8 sText_PkmnWishCameTrue[] = _("¡El DESEO de {B_BUFF1}\nse hizo realidad!");
static const u8 sText_PkmnPlantedRoots[] = _("¡{B_ATK_NAME_WITH_PREFIX} echó raíces!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("¡{B_ATK_NAME_WITH_PREFIX} absorbió\nnutrientes con las raíces!");
static const u8 sText_PkmnAnchoredItself[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ancló\ncon las raíces!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("¡{B_ATK_NAME_WITH_PREFIX} adormeció\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnKnockedOff[] = _("¡{B_ATK_NAME_WITH_PREFIX} echó abajo\n{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambió\nsu habilidad especial!");
static const u8 sText_PkmnSealedOpponentMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} selló\nmovimientos del oponente!");
static const u8 sText_PkmnWantsGrudge[] = _("¡{B_ATK_NAME_WITH_PREFIX} provoca\nRABIA a su rival!");
static const u8 sText_PkmnLostPPGrudge[] = _("¡La RABIA hizo que {B_BUFF1} de\n{B_ATK_NAME_WITH_PREFIX} se quedara sin PP!");
static const u8 sText_PkmnShroudedItself[] = _("¡{B_ATK_NAME_WITH_PREFIX} se cubrió\ncon {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("¡CAPA MÁGICA hizo rebotar\n{B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWaitsForTarget[] = _("¡{B_ATK_NAME_WITH_PREFIX} espera a que su\nrival haga algún movimiento!");
static const u8 sText_PkmnSnatchedMove[] = _("¡{B_DEF_NAME_WITH_PREFIX} ROBÓ el \nmovimiento de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricityWeakened[] = _("¡Se han debilitado los\nataques ELÉCTRICOS!");
static const u8 sText_FireWeakened[] = _("¡Se han debilitado los\nataques de FUEGO!");
static const u8 sText_XFoundOneY[] = _("¡{B_ATK_NAME_WITH_PREFIX} encontró una\nunidad de {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("¡Un balsámico aroma \nimpregnó la zona!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Aquí no se pueden usar objetos.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} encuentra\n{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} usa {B_LAST_ITEM}\npara potenciar los golpes críticos!");
static const u8 sText_PkmnLostFocus[] = _("¡{B_ATK_NAME_WITH_PREFIX} se desconcentró\ny quedó inmovilizado!");
static const u8 sText_PkmnWasDraggedOut[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue\narrastrado al combate!\p");
static const u8 sText_TheWallShattered[] = _("¡Destruyó la protección!");
static const u8 sText_ButNoEffect[] = _("¡Pero no surtió efecto!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("¡A {B_ACTIVE_NAME_WITH_PREFIX} no le quedan\nmás movimientos!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("¡{B_ACTIVE_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} por culpa de ANULACIÓN!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("¡{B_ACTIVE_NAME_WITH_PREFIX} no puede usar el \nmismo movimiento dos veces \lseguidas debido a TORMENTO!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("¡{B_ACTIVE_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} debido a MOFA!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("¡{B_ACTIVE_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} porque está sellado!\p");
static const u8 sText_PkmnMadeItRain[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nhizo llover!");
static const u8 sText_PkmnRaisedSpeed[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nsubió su VELOCIDAD!");
static const u8 sText_PkmnProtectedBy[] = _("¡{B_DEF_NAME_WITH_PREFIX} estaba protegido\npor {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide que {B_ATK_NAME_WITH_PREFIX}\lutilice {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("¡{B_DEF_NAME_WITH_PREFIX} restauró PS\nusando su {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\ninutilizó {B_CURRENT_MOVE}!");
static const u8 sText_PkmnChangedTypeWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nlo convirtió en \lel tipo {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("¡{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide que se quede paralizado!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide que se enamore!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("¡{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide que se envenene!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide que quede confuso!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nreforzó sus ataques de FUEGO!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("¡{B_DEF_NAME_WITH_PREFIX} se aferra\nal suelo con {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbaja el ATAQUE de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nimpide que pierda características!");
static const u8 sText_PkmnHurtsWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nhirió a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} RASTREÓ\n{B_BUFF2} de {B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide que se queme!");
static const u8 sText_PkmnsXBlocksY[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nbloquea {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbloquea {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("¡{B_ATK_NAME_WITH_PREFIX} restauró algo\nsus PS con {B_ATK_ABILITY}!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlevantó una tormenta de arena!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nintensificó los rayos del sol!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nimpide que pierda {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nenamoró a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nanuló {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXCuredYProblem[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncuró su problema de {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("¡Absorbió el \nLODO LÍQUIDO!");
static const u8 sText_PkmnTransformed[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se transformó!");
static const u8 sText_PkmnsXTookAttack[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nrecibió el ataque!");
const u8 gText_PkmnsXPreventsSwitching[] = _("¡{B_LAST_ABILITY} de {B_BUFF1}\nimpide el cambio!\p");
static const u8 sText_PreventedFromWorking[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpidió que {B_BUFF1}\lde {B_SCR_ACTIVE_NAME_WITH_PREFIX} funcionase!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlo hizo ineficaz!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX} \nimpide la retirada!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nimpide que {B_DEF_ABILITY}\lde {B_DEF_NAME_WITH_PREFIX} funcione!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncuró su problema de {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nno ha afectado a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("subió mucho");
const u8 gText_StatRose[] = _("subió");
static const u8 sText_StatHarshly[] = _("bajó mucho");
static const u8 sText_StatFell[] = _("bajó");
static const u8 sText_AttackersStatRose[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}!");
const u8 gText_DefendersStatRose[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}!");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("¡{B_BUFF1} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n{B_BUFF2} con {B_LAST_ITEM}!");
static const u8 sText_AttackersStatFell[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}!");
static const u8 sText_DefendersStatFell[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}!");
static const u8 sText_StatsWontIncrease2[] = _("¡Las características de\n{B_ATK_NAME_WITH_PREFIX} no subirán más!");
static const u8 sText_StatsWontDecrease2[] = _("¡Las características de\n{B_DEF_NAME_WITH_PREFIX} no bajarán más!");
static const u8 sText_CriticalHit[] = _("¡Un golpe crítico!");
static const u8 sText_OneHitKO[] = _("¡K.O. en 1 golpe!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2 y{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}¡puf!\p");
static const u8 sText_AndEllipsis[] = _("Y…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Los movimientos MO no\nse pueden olvidar así.\p");
static const u8 sText_NotVeryEffective[] = _("No es muy eficaz…");
static const u8 sText_SuperEffective[] = _("¡Es muy eficaz!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}¡Escapaste sin problemas!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} escapó\nusando su {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} escapó\nusando su {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}¡{B_BUFF1} salvaje ha huido!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("¡Derrotaste a\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("¡Derrotaste a\n{B_LINK_OPPONENT2_NAME} y {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("¡Has perdido contra\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("¡Has perdido contra\n{B_LINK_OPPONENT2_NAME} y {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("¡{B_LINK_OPPONENT1_NAME} ha empatado\ncontigo!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("¡{B_LINK_OPPONENT2_NAME} y {B_LINK_OPPONENT1_NAME} han\nempatado contigo!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} ha huido!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} y\n{B_LINK_OPPONENT2_NAME} han huido!");
static const u8 sText_NoRunningFromTrainers[] = _("¡No puedes huir de un\ncombate contra un ENTRENADOR!\p");
static const u8 sText_CantEscape[] = _("¡No puedes huir!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. ABEDUL: ¡¡¡No me dejes así!!!\p");
static const u8 sText_ButNothingHappened[] = _("¡Pero no tuvo ningún efecto!");
static const u8 sText_ButItFailed[] = _("¡Pero falló!");
static const u8 sText_ItHurtConfusion[] = _("¡Está tan confuso que se\nhirió a sí mismo!");
static const u8 sText_MirrorMoveFailed[] = _("¡El MOV. ESPEJO ha fallado!");
static const u8 sText_StartedToRain[] = _("¡Ha empezado a llover!");
static const u8 sText_DownpourStarted[] = _("¡Comenzó a caer un chaparrón!");
static const u8 sText_RainContinues[] = _("Sigue lloviendo…");
static const u8 sText_DownpourContinues[] = _("El chaparrón continúa…");
static const u8 sText_RainStopped[] = _("Ha dejado de llover.");
static const u8 sText_SandstormBrewed[] = _("¡Se acerca una tormenta de arena!");
static const u8 sText_SandstormRages[] = _("La tormenta de arena arrecia…");
static const u8 sText_SandstormSubsided[] = _("La tormenta de arena amainó.");
static const u8 sText_SunlightGotBright[] = _("¡El sol está brillando!");
static const u8 sText_SunlightStrong[] = _("Hace mucho sol…");
static const u8 sText_SunlightFaded[] = _("Se ha ido el sol.");
static const u8 sText_StartedHail[] = _("¡Ha empezado a granizar!");
static const u8 sText_HailContinues[] = _("Sigue granizando…");
static const u8 sText_HailStopped[] = _("Ha dejado de granizar.");
static const u8 sText_FailedToSpitUp[] = _("¡Pero no consiguió \nESCUPIR energía!");
static const u8 sText_FailedToSwallow[] = _("¡Pero no consiguió \nTRAGAR energía!");
static const u8 sText_WindBecameHeatWave[] = _("¡El viento se convirtió en\nuna ONDA ÍGNEA!");
static const u8 sText_StatChangesGone[] = _("¡Se han eliminado todos los\ncambios en las características!");
static const u8 sText_CoinsScattered[] = _("¡Hay monedas por todas partes!");
static const u8 sText_TooWeakForSubstitute[] = _("¡Estaba demasiado débil para\ncrear un SUSTITUTO!");
static const u8 sText_SharedPain[] = _("¡Los combatientes comparten\nel daño sufrido!");
static const u8 sText_BellChimed[] = _("¡Ha repicado una campana!");
static const u8 sText_FaintInThree[] = _("¡Los POKéMON de ambas partes se\ndebilitarán dentro de 3 turnos!");
static const u8 sText_NoPPLeft[] = _("¡No quedan PP para \neste movimiento!\p");
static const u8 sText_ButNoPPLeft[] = _("¡Pero no quedan PP para\neste movimiento!");
static const u8 sText_PkmnIgnoresAsleep[] = _("¡{B_ATK_NAME_WITH_PREFIX} ignoró las\nórdenes porque está dormido!");
static const u8 sText_PkmnIgnoredOrders[] = _("¡{B_ATK_NAME_WITH_PREFIX} ignoró\nlas órdenes!");
static const u8 sText_PkmnBeganToNap[] = _("¡{B_ATK_NAME_WITH_PREFIX} se fue a dormir!");
static const u8 sText_PkmnLoafing[] = _("¡{B_ATK_NAME_WITH_PREFIX} está \nholgazaneando!");
static const u8 sText_PkmnWontObey[] = _("¡{B_ATK_NAME_WITH_PREFIX} no\nquiere obedecer!");
static const u8 sText_PkmnTurnedAway[] = _("¡{B_ATK_NAME_WITH_PREFIX} se alejó!");
static const u8 sText_PkmnPretendNotNotice[] = _("¡{B_ATK_NAME_WITH_PREFIX} fingió\nno darse cuenta!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_BUFF2} será el próximo POKéMON \nde {B_TRAINER1_CLASS} {B_TRAINER1_NAME}.\p{B_PLAYER_NAME}, ¿quieres \ncambiar de POKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("¡{B_ATK_NAME_WITH_PREFIX} aprendió\n{B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("¡Derrotaste a\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _("¡{B_PLAYER_NAME} se acercó\nsigilosamente a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("¡{B_PLAYER_NAME} no se puede acercar más!");
static const u8 sText_PkmnWatchingCarefully[] = _("¡{B_OPPONENT_MON1_NAME} te observa\natentamente!");
static const u8 sText_PkmnCuriousAboutX[] = _("¡{B_OPPONENT_MON1_NAME} siente curiosidad\npor el {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("¡{B_OPPONENT_MON1_NAME} está embelesado\ncon el {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("¡{B_OPPONENT_MON1_NAME} ignoró\ncompletamente el {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("¡{B_PLAYER_NAME} lanzó un {POKEBLOCK}\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}ENCARGADO: ¡No te quedan más\nSAFARI BALLS! ¡Se acabó el tiempo!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("¡Un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("¡Un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("¡Un {B_OPPONENT_MON1_NAME} salvaje!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("¡Un {B_OPPONENT_MON2_NAME} y un\n{B_OPPONENT_MON1_NAME} salvajes!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("¡A luchar contra {B_TRAINER1_CLASS}\n{B_TRAINER1_NAME}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("¡{B_LINK_OPPONENT1_NAME}\nquiere luchar!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}\nquieren luchar!");
static const u8 sText_Trainer1SentOutPkmn[] = _("¡{B_OPPONENT_MON1_NAME} es el POKéMON enviado \npor {B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("¡{B_OPPONENT_MON2_NAME} y {B_OPPONENT_MON1_NAME} son la\nopción de {B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("¡{B_BUFF1} es el POKéMON enviado \npor {B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} envió\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} envió a\n{B_OPPONENT_MON1_NAME} y {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} envió a\n{B_LINK_OPPONENT_MON1_NAME}!\p¡{B_LINK_OPPONENT2_NAME} envió a\n{B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("¡{B_LINK_OPPONENT1_NAME} envió\na {B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("¡{B_LINK_SCR_TRAINER_NAME} envió\na {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME} y\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("¡Adelante, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("¡Vamos, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("¡Tú puedes, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("¡Tu enemigo está débil!\n¡A por él, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("¡{B_LINK_PARTNER_NAME} envió a\n{B_LINK_PLAYER_MON2_NAME}!\p¡Adelante, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("¡Ya vale, {B_BUFF1}!\n¡Ven aquí!");
static const u8 sText_PkmnComeBack[] = _("¡{B_BUFF1}, ven aquí!");
static const u8 sText_PkmnOkComeBack[] = _("¡Bien hecho, {B_BUFF1}!\n¡Ven aquí!");
static const u8 sText_PkmnGoodComeBack[] = _("¡Muy bien, {B_BUFF1}!\n¡Ven aquí!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("¡Retirada de {B_BUFF1} por \n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} retiró a\n{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("¡{B_LINK_SCR_TRAINER_NAME} retiró a\n{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _(" salvaje");
static const u8 sText_FoePkmnPrefix[] = _(" enemigo");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("enemigo");
static const u8 sText_AllyPkmnPrefix[] = _("amigo");
static const u8 sText_FoePkmnPrefix3[] = _("enemigo");
static const u8 sText_AllyPkmnPrefix2[] = _("amigo");
static const u8 sText_FoePkmnPrefix4[] = _("enemigo");
static const u8 sText_AllyPkmnPrefix3[] = _("amigo");
static const u8 sText_AttackerUsedX[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("PS");
static const u8 sText_Attack2[] = _("ATAQUE");
static const u8 sText_Defense2[] = _("DEFENSA");
static const u8 sText_Speed[] = _("VELOCID.");
static const u8 sText_SpAtk2[] = _("AT. ESP");
static const u8 sText_SpDef2[] = _("DF. ESP");
static const u8 sText_Accuracy[] = _("PRECISIÓN");
static const u8 sText_Evasiveness[] = _("EVASIÓN");
#else //ENGLISH
static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} gained{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" a boosted");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1} grew to\nLV. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} learned\n{B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} is trying to\nlearn {B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _("But, {B_BUFF1} can't learn\nmore than four moves.\p");
static const u8 sText_TryToLearnMove3[] = _("Delete a move to make\nroom for {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} forgot\n{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}Stop learning\n{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} did not learn\n{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("Use next POKéMON?");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX}'s\nattack missed!");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX}\nprotected itself!");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} avoided\ndamage with {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX} makes GROUND\nmoves miss with {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} avoided\nthe attack!");
static const u8 sText_ItDoesntAffect[] = _("It doesn't affect\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX}\nfainted!\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX}\nfainted!\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} got ¥{B_BUFF1}\nfor winning!\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME} is out of\nusable POKéMON!\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} whited out!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} prevents\nescape with {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("Can't escape!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX} can't escape!");
static const u8 sText_HitXTimes[] = _("Hit {B_BUFF1} time(s)!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\nfell asleep!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade {B_EFF_NAME_WITH_PREFIX} sleep!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready asleep!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} is\nalready asleep!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX}\nwasn't affected!");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nwas poisoned!");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\npoisoned {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby poison!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} is already\npoisoned.");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX} is badly\npoisoned!");
static const u8 sText_PkmnEnergyDrained[] = _("{B_DEF_NAME_WITH_PREFIX} had its\nenergy drained!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} was burned!");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nburned {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby its burn!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} already\nhas a burn.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} was\nfrozen solid!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nfroze {B_EFF_NAME_WITH_PREFIX} solid!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} is\nfrozen solid!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} was\ndefrosted!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted by {B_CURRENT_MOVE}!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} is paralyzed!\nIt may be unable to move!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nparalyzed {B_EFF_NAME_WITH_PREFIX}!\lIt may be unable to move!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} is paralyzed!\nIt can't move!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready paralyzed!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX} was\nhealed of paralysis!");
static const u8 sText_PkmnDreamEaten[] = _("{B_DEF_NAME_WITH_PREFIX}'s\ndream was eaten!");
static const u8 sText_StatsWontIncrease[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go higher!");
static const u8 sText_StatsWontDecrease[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go lower!");
static const u8 sText_TeamStoppedWorking[] = _("Your team's {B_BUFF1}\nstopped working!");
static const u8 sText_FoeStoppedWorking[] = _("The foe's {B_BUFF1}\nstopped working!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} is\nconfused!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} snapped\nout of confusion!");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX} became\nconfused!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} is\nalready confused!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX}\nfell in love!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} is in love\nwith {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("{B_ATK_NAME_WITH_PREFIX} is\nimmobilized by love!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} was\nblown away!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} transformed\ninto the {B_BUFF1} type!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} flinched!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} regained\nhealth!");
static const u8 sText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX}'s\nHP is full!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised SP. DEF!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised SP. DEF a little!");
static const u8 sText_PkmnRaisedDef[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised DEFENSE!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised DEFENSE a little!");
static const u8 sText_PkmnCoveredByVeil[] = _("{B_ATK_PREFIX2}'s party is covered\nby a veil!");
static const u8 sText_PkmnUsedSafeguard[] = _("{B_DEF_NAME_WITH_PREFIX}'s party is protected\nby SAFEGUARD!");
static const u8 sText_PkmnSafeguardExpired[] = _("{B_ATK_PREFIX3}'s party is no longer\nprotected by SAFEGUARD!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} went\nto sleep!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX} slept and\nbecame healthy!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX} whipped\nup a whirlwind!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} took\nin sunlight!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} lowered\nits head!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} is glowing!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} flew\nup high!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} dug a hole!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} hid\nunderwater!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} sprang up!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX} was squeezed by\n{B_ATK_NAME_WITH_PREFIX}'s BIND!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped\nin the vortex!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped\nby SAND TOMB!");
static const u8 sText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was WRAPPED by\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} CLAMPED\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt\nby {B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} was freed\nfrom {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX} kept going\nand crashed!");
const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_PREFIX2} became\nshrouded in MIST!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is protected\nby MIST!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX} is getting\npumped!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX} is hit\nwith recoil!");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX} protected\nitself!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} is buffeted\nby the sandstorm!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} is pelted\nby HAIL!");
static const u8 sText_PkmnsXWoreOff[] = _("{B_ATK_PREFIX1}'s {B_BUFF1}\nwore off!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} was seeded!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} evaded\nthe attack!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}'s health is\nsapped by LEECH SEED!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} is fast\nasleep.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} woke up!");
static const u8 sText_PkmnUproarKeptAwake[] = _("But {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s UPROAR\nkept it awake!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} woke up\nin the UPROAR!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} caused\nan UPROAR!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} is making\nan UPROAR!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} calmed down.");
static const u8 sText_PkmnCantSleepInUproar[] = _("But {B_DEF_NAME_WITH_PREFIX} can't\nsleep in an UPROAR!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} STOCKPILED\n{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} can't\nSTOCKPILE any more!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("But {B_DEF_NAME_WITH_PREFIX} can't\nsleep in an UPROAR!");
static const u8 sText_UproarKeptPkmnAwake[] = _("But the UPROAR kept\n{B_DEF_NAME_WITH_PREFIX} awake!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} stayed awake\nusing its {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} is storing\nenergy!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} unleashed\nenergy!");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} became\nconfused due to fatigue!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} picked up\n¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX} is\nunaffected!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} transformed\ninto {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} made\na SUBSTITUTE!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} already\nhas a SUBSTITUTE!");
static const u8 sText_SubstituteDamaged[] = _("The SUBSTITUTE took damage\nfor {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("{B_DEF_NAME_WITH_PREFIX}'s\nSUBSTITUTE faded!\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} must\nrecharge!");
static const u8 sText_PkmnRageBuilding[] = _("{B_DEF_NAME_WITH_PREFIX}'s RAGE\nis building!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwas disabled!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} is disabled\nno more!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX} got\nan ENCORE!");
static const u8 sText_PkmnEncoreEnded[] = _("{B_ATK_NAME_WITH_PREFIX}'s ENCORE\nended!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} took aim\nat {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} SKETCHED\n{B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} is trying\nto take its foe with it!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} took\n{B_ATK_NAME_WITH_PREFIX} with it!");
static const u8 sText_PkmnReducedPP[] = _("Reduced {B_DEF_NAME_WITH_PREFIX}'s\n{B_BUFF1} by {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} stole\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX} can't\nescape now!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} fell into\na NIGHTMARE!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} is locked\nin a NIGHTMARE!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP and\nlaid a CURSE on {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} is afflicted\nby the CURSE!");
static const u8 sText_SpikesScattered[] = _("SPIKES were scattered all around\nthe opponent's side!");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is hurt\nby SPIKES!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identified\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("{B_ATK_NAME_WITH_PREFIX}'s PERISH count\nfell to {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} braced\nitself!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} ENDURED\nthe hit!");
static const u8 sText_MagnitudeStrength[] = _("MAGNITUDE {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP\nand maximized ATTACK!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}'s stat changes!");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} got free of\n{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX} shed\nLEECH SEED!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX} blew away\nSPIKES!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} fled from\nbattle!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} foresaw\nan attack!");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} took the\n{B_BUFF1} attack!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} chose\n{B_CURRENT_MOVE} as its destiny!");
static const u8 sText_PkmnAttack[] = _("{B_BUFF1}'s attack!");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX} became the\ncenter of attention!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX} began\ncharging power!");
static const u8 sText_NaturePowerTurnedInto[] = _("NATURE POWER turned into\n{B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("{B_ATK_NAME_WITH_PREFIX}'s status\nreturned to normal!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} was subjected\nto TORMENT!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} is tightening\nits focus!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX} fell for\nthe TAUNT!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} is ready to\nhelp {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} switched\nitems with its opponent!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} made a WISH!");
static const u8 sText_PkmnWishCameTrue[] = _("{B_BUFF1}'s WISH\ncame true!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} planted its roots!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} absorbed\nnutrients with its roots!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} anchored\nitself with its roots!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} made\n{B_DEF_NAME_WITH_PREFIX} drowsy!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} knocked off\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} swapped abilities\nwith its opponent!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} sealed the\nopponent's move(s)!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} wants the\nopponent to bear a GRUDGE!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} lost\nall its PP due to the GRUDGE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} shrouded\nitself in {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\nwas bounced back by MAGIC COAT!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} waits for a target\nto make a move!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} SNATCHED\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s move!");
static const u8 sText_ElectricityWeakened[] = _("Electricity's power was\nweakened!");
static const u8 sText_FireWeakened[] = _("Fire's power was\nweakened!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX} found\none {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("A soothing aroma wafted\nthrough the area!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Items can't be used now.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("For {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used\n{B_LAST_ITEM} to get pumped!");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} lost its\nfocus and couldn't move!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} was\ndragged out!\p");
static const u8 sText_TheWallShattered[] = _("The wall shattered!");
static const u8 sText_ButNoEffect[] = _("But it had no effect!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX} has no\nmoves left!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("{B_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\nis disabled!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ACTIVE_NAME_WITH_PREFIX} can't use the same\nmove in a row due to the TORMENT!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX} can't use\n{B_CURRENT_MOVE} after the TAUNT!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} can't use the\nsealed {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade it rain!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its SPEED!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was protected\nby {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} restored HP\nusing its {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} useless!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade it the {B_BUFF1} type!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents paralysis!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents romance!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents poisoning!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents confusion!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nraised its FIRE power!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} anchors\nitself with {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncuts {B_DEF_NAME_WITH_PREFIX}'s ATTACK!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents stat loss!");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nhurt {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} TRACED\n{B_BUFF1}'s {B_BUFF2}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\nprevents burns!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nblocks {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nblocks {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nrestored its HP a little!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nwhipped up a sandstorm!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nintensified the sun's rays!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents {B_BUFF1} loss!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\ninfatuated {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} ineffective!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
static const u8 sText_ItSuckedLiquidOoze[] = _("It sucked up the\nLIQUID OOZE!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\ntook the attack!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1}'s {B_LAST_ABILITY}\nprevents switching!\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevented {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s\l{B_BUFF1} from working!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade it ineffective!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\nprevents flinching!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nprevents {B_DEF_NAME_WITH_PREFIX}'s\l{B_DEF_ABILITY} from working!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nhad no effect on {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("sharply ");
const u8 gText_StatRose[] = _("rose!");
static const u8 sText_StatHarshly[] = _("harshly ");
static const u8 sText_StatFell[] = _("fell!");
static const u8 sText_AttackersStatRose[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Using {B_LAST_ITEM}, the {B_BUFF1}\nof {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("{B_ATK_NAME_WITH_PREFIX}'s stats won't\ngo any higher!");
static const u8 sText_StatsWontDecrease2[] = _("{B_DEF_NAME_WITH_PREFIX}'s stats won't\ngo any lower!");
static const u8 sText_CriticalHit[] = _("A critical hit!");
static const u8 sText_OneHitKO[] = _("It's a one-hit KO!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p");
static const u8 sText_AndEllipsis[] = _("And…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("HM moves can't be\nforgotten now.\p");
static const u8 sText_NotVeryEffective[] = _("It's not very effective…");
static const u8 sText_SuperEffective[] = _("It's super effective!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Got away safely!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled\nusing its {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled\nusing {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}Wild {B_BUFF1} fled!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("Player defeated\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("Player beat {B_LINK_OPPONENT1_NAME}\nand {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("Player lost against\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("Player lost to {B_LINK_OPPONENT1_NAME}\nand {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("Player battled to a draw against\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("Player battled to a draw against\n{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} fled!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} and\n{B_LINK_OPPONENT2_NAME} fled!");
static const u8 sText_NoRunningFromTrainers[] = _("No! There's no running\nfrom a TRAINER battle!\p");
static const u8 sText_CantEscape[] = _("Can't escape!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. BIRCH: Don't leave me like this!\p");
static const u8 sText_ButNothingHappened[] = _("But nothing happened!");
static const u8 sText_ButItFailed[] = _("But it failed!");
static const u8 sText_ItHurtConfusion[] = _("It hurt itself in its\nconfusion!");
static const u8 sText_MirrorMoveFailed[] = _("The MIRROR MOVE failed!");
static const u8 sText_StartedToRain[] = _("It started to rain!");
static const u8 sText_DownpourStarted[] = _("A downpour started!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("Rain continues to fall.");
static const u8 sText_DownpourContinues[] = _("The downpour continues."); // Unused
static const u8 sText_RainStopped[] = _("The rain stopped.");
static const u8 sText_SandstormBrewed[] = _("A sandstorm brewed!");
static const u8 sText_SandstormRages[] = _("The sandstorm rages.");
static const u8 sText_SandstormSubsided[] = _("The sandstorm subsided.");
static const u8 sText_SunlightGotBright[] = _("The sunlight got bright!");
static const u8 sText_SunlightStrong[] = _("The sunlight is strong.");
static const u8 sText_SunlightFaded[] = _("The sunlight faded.");
static const u8 sText_StartedHail[] = _("It started to hail!");
static const u8 sText_HailContinues[] = _("Hail continues to fall.");
static const u8 sText_HailStopped[] = _("The hail stopped.");
static const u8 sText_FailedToSpitUp[] = _("But it failed to SPIT UP\na thing!");
static const u8 sText_FailedToSwallow[] = _("But it failed to SWALLOW\na thing!");
static const u8 sText_WindBecameHeatWave[] = _("The wind turned into a\nHEAT WAVE!");
static const u8 sText_StatChangesGone[] = _("All stat changes were\neliminated!");
static const u8 sText_CoinsScattered[] = _("Coins scattered everywhere!");
static const u8 sText_TooWeakForSubstitute[] = _("It was too weak to make\na SUBSTITUTE!");
static const u8 sText_SharedPain[] = _("The battlers shared\ntheir pain!");
static const u8 sText_BellChimed[] = _("A bell chimed!");
static const u8 sText_FaintInThree[] = _("All affected POKéMON will\nfaint in three turns!");
static const u8 sText_NoPPLeft[] = _("There's no PP left for\nthis move!\p");
static const u8 sText_ButNoPPLeft[] = _("But there was no PP left\nfor the move!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignored\norders while asleep!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignored\norders!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} began to nap!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} is\nloafing around!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} won't\nobey!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} turned away!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} pretended\nnot to notice!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} is\nabout to use {B_BUFF2}.\pWill {B_PLAYER_NAME} change\nPOKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} learned\n{B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Player defeated\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME} crept closer to\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} can't get any closer!");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} is watching\ncarefully!");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} is curious about\nthe {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} is enthralled by\nthe {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} completely ignored\nthe {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} threw a {POKEBLOCK}\nat the {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}ANNOUNCER: You're out of\nSAFARI BALLS! Game over!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Wild {B_OPPONENT_MON1_NAME} appeared!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Wild {B_OPPONENT_MON1_NAME} and\n{B_OPPONENT_MON2_NAME} appeared!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwould like to battle!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{B_LINK_OPPONENT1_NAME}\nwants to battle!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}\nwant to battle!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out\n{B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}!\n{B_LINK_OPPONENT2_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} sent out\n{B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} sent out\n{B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Go! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Go! {B_PLAYER_MON1_NAME} and\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Go! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Do it! {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Go for it, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Your foe's weak!\nGet 'em, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON2_NAME}!\nGo! {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, that's enough!\nCome back!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, come back!");
static const u8 sText_PkmnOkComeBack[] = _("{B_BUFF1}, OK!\nCome back!");
static const u8 sText_PkmnGoodComeBack[] = _("{B_BUFF1}, good!\nCome back!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwithdrew {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} withdrew\n{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} withdrew\n{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _("Wild ");
static const u8 sText_FoePkmnPrefix[] = _("Foe ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Foe");
static const u8 sText_AllyPkmnPrefix[] = _("Ally");
static const u8 sText_FoePkmnPrefix3[] = _("Foe");
static const u8 sText_AllyPkmnPrefix2[] = _("Ally");
static const u8 sText_FoePkmnPrefix4[] = _("Foe");
static const u8 sText_AllyPkmnPrefix3[] = _("Ally");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} used\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("HP");
static const u8 sText_Attack2[] = _("ATTACK");
static const u8 sText_Defense2[] = _("DEFENSE");
static const u8 sText_Speed[] = _("SPEED");
static const u8 sText_SpAtk2[] = _("SP. ATK");
static const u8 sText_SpDef2[] = _("SP. DEF");
static const u8 sText_Accuracy[] = _("accuracy");
static const u8 sText_Evasiveness[] = _("evasiveness");
#endif

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP2,
    [STAT_ATK]     = sText_Attack2,
    [STAT_DEF]     = sText_Defense2,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAtk2,
    [STAT_SPDEF]   = sText_SpDef2,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};

#if FRENCH
static const u8 sText_PokeblockWasTooSpicy[] = _("était trop épicée!");
static const u8 sText_PokeblockWasTooDry[] = _("était trop sèche!");
static const u8 sText_PokeblockWasTooSweet[] = _("était trop sucrée!");
static const u8 sText_PokeblockWasTooBitter[] = _("était trop amère!");
static const u8 sText_PokeblockWasTooSour[] = _("était trop acide!");
#elif ITALIAN
static const u8 sText_PokeblockWasTooSpicy[] = _("è troppo pepata!");
static const u8 sText_PokeblockWasTooDry[] = _("è troppo secca!");
static const u8 sText_PokeblockWasTooSweet[] = _("è troppo dolce!");
static const u8 sText_PokeblockWasTooBitter[] = _("è troppo amara!");
static const u8 sText_PokeblockWasTooSour[] = _("è troppo aspra!");
#elif SPANISH
static const u8 sText_PokeblockWasTooSpicy[] = _("demasiado picante!");
static const u8 sText_PokeblockWasTooDry[] = _("demasiado seca!");
static const u8 sText_PokeblockWasTooSweet[] = _("demasiado dulce!");
static const u8 sText_PokeblockWasTooBitter[] = _("demasiado amarga!");
static const u8 sText_PokeblockWasTooSour[] = _("demasiado ácida!");
#else //ENGLISH
static const u8 sText_PokeblockWasTooSpicy[] = _("was too spicy!");
static const u8 sText_PokeblockWasTooDry[] = _("was too dry!");
static const u8 sText_PokeblockWasTooSweet[] = _("was too sweet!");
static const u8 sText_PokeblockWasTooBitter[] = _("was too bitter!");
static const u8 sText_PokeblockWasTooSour[] = _("was too sour!");
#endif

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};
#if FRENCH
static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME} utilise\n{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("TIMMY utilise\n{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("{B_LAST_ITEM} est utilisé(e) par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_TrainerBlockedBall[] = _("Le DRESSEUR détourne la BALL!");
static const u8 sText_DontBeAThief[] = _("Voler, c’est mal!");
static const u8 sText_ItDodgedBall[] = _("Il a évité la BALL!\nCe POKéMON ne se laisse pas faire!");
static const u8 sText_YouMissedPkmn[] = _("Vous manquez le POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Oh, non!\nLe POKéMON s’est libéré!");
static const u8 sText_ItAppearedCaught[] = _("Raaah!\nÇa y était presque!");
static const u8 sText_AarghAlmostHadIt[] = _("Aaaaaah!\nPresque!");
static const u8 sText_ShootSoClose[] = _("Mince!\nÇa y était presque!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("Et hop!\n{B_OPPONENT_MON1_NAME} est attrapé!{WAIT_SE}{PLAY_BGM}{0x60}À\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("Et hop!\n{B_OPPONENT_MON1_NAME} est attrapé!{WAIT_SE}{PLAY_BGM}{0x60}À{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("Donner un surnom au\n{B_OPPONENT_MON1_NAME} capturé?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} est envoyé au\nPC {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("de quelqu’un");
static const u8 sText_Lanettes[] = _("d’ANNETTE");
static const u8 sText_PkmnDataAddedToDex[] = _("Les données de {B_OPPONENT_MON1_NAME} sont\najoutées au POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("Il pleut.");
static const u8 sText_SandstormIsRaging[] = _("La tempête de sable\nfait rage.");
static const u8 sText_BoxIsFull[] = _("La BOITE est pleine!\nVous ne pouvez plus rien attraper!\p");
static const u8 sText_EnigmaBerry[] = _("BAIE ENIGMA");
static const u8 sText_BerrySuffix[] = _("BAIE {B_COPY_VAR_3}");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle sort de sa paralysie!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle guérit de son empoisonnement!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle guérit de sa brûlure!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle dégèle!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle sort de son sommeil!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle tire de sa confusion!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguérit son problème de {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nramène son statut à la normale!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaure son énergie!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaure les PP de {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaure son statut!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_LAST_ITEM} du {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaure un peu ses PV!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("Avec {B_LAST_ITEM}, seule la capacité\n{B_CURRENT_MOVE} peut être utilisée!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} tient bon grâce\nà {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Il faut lancer une BALL, non?\nJe… je ferai de mon mieux!");
#elif ITALIAN
static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME} usa {B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("LINO usa {B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("{B_LAST_ITEM} è lo strumento usato\nda {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_TrainerBlockedBall[] = _("La BALL è stata bloccata!");
static const u8 sText_DontBeAThief[] = _("Non si ruba!");
static const u8 sText_ItDodgedBall[] = _("Ha schivato la BALL! Questo\nPOKéMON non può essere catturato!");
static const u8 sText_YouMissedPkmn[] = _("Ti è sfuggito il POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Oh, no!\nIl POKéMON si è liberato!");
static const u8 sText_ItAppearedCaught[] = _("Ah! Sembrava preso,\neh? E invece no!");
static const u8 sText_AarghAlmostHadIt[] = _("Grrr!\nPer un pelo!");
static const u8 sText_ShootSoClose[] = _("Nooo!\nEra così vicino!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("Preso!\n{B_OPPONENT_MON1_NAME} è catturato!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("Preso!\n{B_OPPONENT_MON1_NAME} è catturato!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("Vuoi dare un soprannome\na {B_OPPONENT_MON1_NAME}?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} è stato inviato\nal PC di {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("???");
static const u8 sText_Lanettes[] = _("LANETTE");
static const u8 sText_PkmnDataAddedToDex[] = _("I dati di {B_OPPONENT_MON1_NAME} sono stati\ninseriti nel POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("Piove.");
static const u8 sText_SandstormIsRaging[] = _("Imperversa una tempesta di sabbia.");
static const u8 sText_BoxIsFull[] = _("I BOX sono pieni!\nNon ne puoi catturare altri!\p");
static const u8 sText_EnigmaBerry[] = _("BACCAENIGMA");
static const u8 sText_BerrySuffix[] = _("BACCA{B_COPY_VAR_3}");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce la paralisi!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce l’avvelenamento!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce la scottatura!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha scongelato!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha svegliato!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nelimina la sua confusione!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nnormalizza il suo stato!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce la salute!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce i PP di {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce le sue statistiche!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce parte dei PS!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} consente di usare\nsoltanto {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} resiste\nusando {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Ora si lancia una BALL, vero?\nCercherò di fare del mio meglio!");
#elif SPANISH
static const u8 sText_PlayerUsedItem[] = _("¡{B_PLAYER_NAME} usó\n{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("¡BLASCO usó\n{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("¡Uso de {B_LAST_ITEM} por\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_TrainerBlockedBall[] = _("¡El ENTRENADOR bloqueó la BALL!");
static const u8 sText_DontBeAThief[] = _("¡Robar está mal!");
static const u8 sText_ItDodgedBall[] = _("¡Esquivó la BALL! ¡No has podido\natrapar a este POKéMON!");
static const u8 sText_YouMissedPkmn[] = _("¡Has apuntado mal al POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("¡Oh, no!\n¡El POKéMON se ha escapado!");
static const u8 sText_ItAppearedCaught[] = _("¡Vaya! ¡Parecía que lo\nhabías atrapado!");
static const u8 sText_AarghAlmostHadIt[] = _("¡Qué pena!\n¡Te faltó poco!");
static const u8 sText_ShootSoClose[] = _("¡Uy!\n¡Casi lo consigues!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("¡Ya está!\n¡{B_OPPONENT_MON1_NAME} atrapado!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("¡Ya está!\n¡{B_OPPONENT_MON1_NAME} atrapado!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("¿Quieres ponerle un \nmote a {B_OPPONENT_MON1_NAME}?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} fue enviado \nal PC de {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("alguien");
static const u8 sText_Lanettes[] = _("AREDIA");
static const u8 sText_PkmnDataAddedToDex[] = _("Registrados en la POKéDEX\nlos datos de {B_OPPONENT_MON1_NAME}.\p");
static const u8 sText_ItIsRaining[] = _("Está lloviendo…");
static const u8 sText_SandstormIsRaging[] = _("La tormenta de arena cobra fuerza…");
static const u8 sText_BoxIsFull[] = _("¡Las CAJAS están llenas!\n¡No puedes atrapar ninguno más!\p");
static const u8 sText_EnigmaBerry[] = _("BAYA ENIGMA");
static const u8 sText_BerrySuffix[] = _("BAYA {B_COPY_VAR_3}");
static const u8 sText_PkmnsItemCuredParalysis[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se curó de la\nparálisis con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemCuredPoison[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se curó del\nenvenenamiento con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemHealedBurn[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se curó las \nquemaduras con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se descongeló\ncon {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemWokeIt[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se despertó\ncon {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemSnappedOut[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se libró de la\nconfusión con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemCuredProblem[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncuró su problema de {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} normalizó su\nestado con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} restauró \nsalud con {B_LAST_ITEM}!");
static const u8 sText_PkmnsItemRestoredPP[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestauró los PP de {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestauró sus características!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} restauró algo\nsus PS con {B_LAST_ITEM}!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("¡{B_LAST_ITEM} sólo permite el\nuso de {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("¡{B_DEF_NAME_WITH_PREFIX} resistió\nusando su {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Ahora debo lanzar una BALL, ¿no?\n¡Intentaré hacerlo lo mejor posible!");
#else //ENGLISH
static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME} used\n{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("WALLY used\n{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nused {B_LAST_ITEM}!");
static const u8 sText_TrainerBlockedBall[] = _("The TRAINER blocked the BALL!");
static const u8 sText_DontBeAThief[] = _("Don't be a thief!");
static const u8 sText_ItDodgedBall[] = _("It dodged the thrown BALL!\nThis POKéMON can't be caught!");
static const u8 sText_YouMissedPkmn[] = _("You missed the POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Oh, no!\nThe POKéMON broke free!");
static const u8 sText_ItAppearedCaught[] = _("Aww!\nIt appeared to be caught!");
static const u8 sText_AarghAlmostHadIt[] = _("Aargh!\nAlmost had it!");
static const u8 sText_ShootSoClose[] = _("Shoot!\nIt was so close, too!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("Gotcha!\n{B_OPPONENT_MON1_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("Gotcha!\n{B_OPPONENT_MON1_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("Give a nickname to the\ncaptured {B_OPPONENT_MON1_NAME}?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} was sent to\n{B_PC_CREATOR_NAME} PC.");
static const u8 sText_Someones[] = _("someone's");
static const u8 sText_Lanettes[] = _("LANETTE's");
static const u8 sText_PkmnDataAddedToDex[] = _("{B_OPPONENT_MON1_NAME}'s data was\nadded to the POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("It is raining.");
static const u8 sText_SandstormIsRaging[] = _("A sandstorm is raging.");
static const u8 sText_BoxIsFull[] = _("The BOX is full!\nYou can't catch any more!\p");
static const u8 sText_EnigmaBerry[] = _("ENIGMA BERRY");
static const u8 sText_BerrySuffix[] = _(" BERRY");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured paralysis!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured poison!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nhealed its burn!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ndefrosted it!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nwoke it from its sleep!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nsnapped it out of confusion!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured its {B_BUFF1} problem!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nnormalized its status!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored health!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored {B_BUFF1}'s PP!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored its status!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored its HP a little!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} allows the\nuse of only {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} hung on\nusing its {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("You throw a BALL now, right?\nI… I'll do my best!");
#endif

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT - BATTLESTRINGS_TABLE_START] =
{
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = sText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues, // Unused
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND] = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM] = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH] = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK] = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]        = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]        = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]       = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]     = STRINGID_PKMNSPRANGUP,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB // MOVE_SAND_TOMB
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_ITISRAINING,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gTrappingMoves[NUM_TRAPPING_MOVES + 1] =
{
    MOVE_BIND,
    MOVE_WRAP,
    MOVE_FIRE_SPIN,
    MOVE_CLAMP,
    MOVE_WHIRLPOOL,
    MOVE_SAND_TOMB,
    0xFFFF // Never read
};

#if FRENCH
const u8 gText_PkmnIsEvolving[] = _("Quoi?\n{B_COPY_VAR_1} évolue!");
const u8 gText_CongratsPkmnEvolved[] = _("Félicitations! Votre {B_COPY_VAR_1}\névolue en {B_COPY_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Hein? {B_COPY_VAR_1}\nn’évolue plus!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("Que doit faire\n{B_ACTIVE_NAME_WITH_PREFIX}?");
const u8 gText_WhatWillPkmnDo2[] = _("Que doit faire\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("Que doit faire\nTIMMY?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Connexion en cours…");
const u8 gText_BattleMenu[] = _("ATTAQUE{CLEAR_TO 56}SAC\nPOKéMON{CLEAR_TO 56}FUITE");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK}\nSE RAP.{CLEAR_TO 56}FUITE");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TYPE/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}OUI\nNON");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Changer\nlequel?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("PV");
static const u8 sText_Attack[] = _("ATTAQUE");
static const u8 sText_Defense[] = _("DEFENSE");
static const u8 sText_SpAtk[] = _("ATQ SP");
static const u8 sText_SpDef[] = _("DEF SP");
#elif ITALIAN
const u8 gText_PkmnIsEvolving[] = _("Cosa?\n{B_COPY_VAR_1} si sta evolvendo!");
const u8 gText_CongratsPkmnEvolved[] = _("Complimenti! Il tuo {B_COPY_VAR_1}\nsi è evoluto in {B_COPY_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Bloccata evoluzione\ndi {B_COPY_VAR_1}!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("Cosa deve fare\n{B_ACTIVE_NAME_WITH_PREFIX}?");
const u8 gText_WhatWillPkmnDo2[] = _("Cosa deve fare\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("Cosa deve fare\nLINO?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Un momento…");
const u8 gText_BattleMenu[] = _("LOTTA{CLEAR_TO 56}ZAINO\nPOKéMON{CLEAR_TO 56}FUGA");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEMELLE}\nVICINO{CLEAR_TO 56}FUGA");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TIPO/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}SÌ\nNO");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Sposta\nquale?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("PS");
static const u8 sText_Attack[] = _("ATTACCO");
static const u8 sText_Defense[] = _("DIFESA");
static const u8 sText_SpAtk[] = _("ATT. SP.");
static const u8 sText_SpDef[] = _("DIF. SP.");
#elif SPANISH
const u8 gText_PkmnIsEvolving[] = _("¡Anda!\n¡{B_COPY_VAR_1} está evolucionando!");
const u8 gText_CongratsPkmnEvolved[] = _("¡Enhorabuena! ¡Tu {B_COPY_VAR_1}\nse ha convertido en {B_COPY_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("¿Eh? ¡La evolución de\n{B_COPY_VAR_1} se ha detenido!\p");
const u8 gText_EllipsisQuestionMark[] = _("(…)?\p");
const u8 gText_WhatWillPkmnDo[] = _("¿Qué debería hacer\n{B_ACTIVE_NAME_WITH_PREFIX}?");
const u8 gText_WhatWillPkmnDo2[] = _("¿Qué debería hacer\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("¿Qué debería hacer\nBLASCO?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Esperando conexión…");
const u8 gText_BattleMenu[] = _("LUCHA{CLEAR_TO 56}MOCHILA\nPOKéMON{CLEAR_TO 56}HUIDA");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK}\n+ CERCA{CLEAR_TO 56}HUIDA");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TIPO/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Sí\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}¿Cuál\ncambias?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("PS");
static const u8 sText_Attack[] = _("ATAQUE");
static const u8 sText_Defense[] = _("DEFENSA");
static const u8 sText_SpAtk[] = _("AT. ESP");
static const u8 sText_SpDef[] = _("DF. ESP");
#else //ENGLISH
const u8 gText_PkmnIsEvolving[] = _("What?\n{STR_VAR_1} is evolving!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {STR_VAR_1}\nstopped evolving!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("What will\n{B_ACTIVE_NAME_WITH_PREFIX} do?");
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

static const u8 sText_HP[] = _("HP");
static const u8 sText_Attack[] = _("ATTACK");
static const u8 sText_Defense[] = _("DEFENSE");
static const u8 sText_SpAtk[] = _("SP. ATK");
static const u8 sText_SpDef[] = _("SP. DEF");
#endif

// Unused
static const u8 *const sStatNamesTable2[] =
{
    sText_HP, sText_SpAtk, sText_Attack,
    sText_SpDef, sText_Defense, sText_Speed
};
#if FRENCH
const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Nb: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("sommeil");
const u8 gText_Poison[] = _("poison");
const u8 gText_Burn[] = _("brûlure");
const u8 gText_Paralysis[] = _("paralysie");
const u8 gText_Ice[] = _("gel");
const u8 gText_Confusion[] = _("confusion");
const u8 gText_Love[] = _("cœur");
const u8 gText_SpaceAndSpace[] = _(" et ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("sont");
const u8 gText_Are2[] = _("sont");
const u8 gText_BadEgg[] = _("Mauv. OEUF");
const u8 gText_BattleWallyName[] = _("TIMMY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Victoire");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Défaite");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Egalité");
static const u8 sText_SpaceIs[] = _(" est");
static const u8 sText_ApostropheS[] = _("de ");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][22] =
{
    [TYPE_NORMAL]   = _("une capacité NORMAL"),
    [TYPE_FIGHTING] = _("une capacité COMBAT"),
    [TYPE_FLYING]   = _("une capacité VOL"),
    [TYPE_POISON]   = _("une capacité POISON"),
    [TYPE_GROUND]   = _("une capacité SOL"),
    [TYPE_ROCK]     = _("une capacité ROCHE"),
    [TYPE_BUG]      = _("une capacité INSECTE"),
    [TYPE_GHOST]    = _("une capacité SPECTRE"),
    [TYPE_STEEL]    = _("une capacité ACIER"),
    [TYPE_MYSTERY]  = _("une capacité ???"),
    [TYPE_FIRE]     = _("une capacité FEU"),
    [TYPE_WATER]    = _("une capacité EAU"),
    [TYPE_GRASS]    = _("une capacité PLANTE"),
    [TYPE_ELECTRIC] = _("une capacité ELECTRIK"),
    [TYPE_PSYCHIC]  = _("une capacité PSY"),
    [TYPE_ICE]      = _("une capacité GLACE"),
    [TYPE_DRAGON]   = _("une capacité DRAGON"),
    [TYPE_DARK]     = _("une capacité TENEBRES")
};

const u8 gText_BattleTourney[] = _("TOURNOI DE COMBAT");
static const u8 sText_Round1[] = _("Premier tour");
static const u8 sText_Round2[] = _("Deuxième tour");
static const u8 sText_Semifinal[] = _("Demi-finale");
static const u8 sText_Final[] = _("Finale");
#elif ITALIAN
const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}SAFARI BALL");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Ancora $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("sonno");
const u8 gText_Poison[] = _("avvelenamento");
const u8 gText_Burn[] = _("scottatura");
const u8 gText_Paralysis[] = _("paralisi");
const u8 gText_Ice[] = _("congelamento");
const u8 gText_Confusion[] = _("confusione");
const u8 gText_Love[] = _("amore");
const u8 gText_SpaceAndSpace[] = _(" e ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("sono");
const u8 gText_Are2[] = _("sono");
const u8 gText_BadEgg[] = _("UOVO peste");
const u8 gText_BattleWallyName[] = _("LINO");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Vinto");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Perso");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Pari");
static const u8 sText_SpaceIs[] = _(" è");
static const u8 sText_ApostropheS[] = _("di ");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][22] =
{
    [TYPE_NORMAL]   = _("una mossa NORMALE"),
    [TYPE_FIGHTING] = _("una mossa LOTTA"),
    [TYPE_FLYING]   = _("una mossa VOLANTE"),
    [TYPE_POISON]   = _("una mossa VELENO"),
    [TYPE_GROUND]   = _("una mossa TERRA"),
    [TYPE_ROCK]     = _("una mossa ROCCIA"),
    [TYPE_BUG]      = _("una mossa COLEOTTERO"),
    [TYPE_GHOST]    = _("una mossa SPETTRO"),
    [TYPE_STEEL]    = _("una mossa ACCIAIO"),
    [TYPE_MYSTERY]  = _("una mossa ???"),
    [TYPE_FIRE]     = _("una mossa FUOCO"),
    [TYPE_WATER]    = _("una mossa ACQUA"),
    [TYPE_GRASS]    = _("una mossa ERBA"),
    [TYPE_ELECTRIC] = _("una mossa ELETTRO"),
    [TYPE_PSYCHIC]  = _("una mossa PSICO"),
    [TYPE_ICE]      = _("una mossa GHIACCIO"),
    [TYPE_DRAGON]   = _("una mossa DRAGO"),
    [TYPE_DARK]     = _("una mossa BUIO")
};

const u8 gText_BattleTourney[] = _("TORNEO LOTTA");
static const u8 sText_Round1[] = _("1º round");
static const u8 sText_Round2[] = _("2º round");
static const u8 sText_Semifinal[] = _("Semifinale");
static const u8 sText_Final[] = _("Finale");
#elif SPANISH
const u8 gText_SafariBalls[] = _("{HIGHLIGHT 2}SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT 2}Tienes $" "{HIGHLIGHT 2}");
const u8 gText_Sleep[] = _("sueño");
const u8 gText_Poison[] = _("envenenamiento");
const u8 gText_Burn[] = _("quemaduras");
const u8 gText_Paralysis[] = _("parálisis");
const u8 gText_Ice[] = _("congelación");
const u8 gText_Confusion[] = _("confusión");
const u8 gText_Love[] = _("enamoramiento");
const u8 gText_SpaceAndSpace[] = _(" y ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("no pueden");
const u8 gText_Are2[] = _("no pueden");
const u8 gText_BadEgg[] = _("HUEVO malo");
const u8 gText_BattleWallyName[] = _("BLASCO");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Victoria");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Derrota");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Empate");
static const u8 sText_SpaceIs[] = _(" es");
static const u8 sText_ApostropheS[] = _("de ");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][22] =
{
    [TYPE_NORMAL]   = _("un mov. NORMAL"),
    [TYPE_FIGHTING] = _("un mov. LUCHA"),
    [TYPE_FLYING]   = _("un mov. VOLADOR"),
    [TYPE_POISON]   = _("un mov. VENENO"),
    [TYPE_GROUND]   = _("un mov. TIERRA"),
    [TYPE_ROCK]     = _("un mov. ROCA"),
    [TYPE_BUG]      = _("un mov. BICHO"),
    [TYPE_GHOST]    = _("un mov. FANTASMA"),
    [TYPE_STEEL]    = _("un mov. ACERO"),
    [TYPE_MYSTERY]  = _("un mov. (?)"),
    [TYPE_FIRE]     = _("un mov. FUEGO"),
    [TYPE_WATER]    = _("un mov. AGUA"),
    [TYPE_GRASS]    = _("un mov. PLANTA"),
    [TYPE_ELECTRIC] = _("un mov. ELÉCTRICO"),
    [TYPE_PSYCHIC]  = _("un mov. PSÍQUICO"),
    [TYPE_ICE]      = _("un mov. HIELO"),
    [TYPE_DRAGON]   = _("un mov. DRAGÓN"),
    [TYPE_DARK]     = _("un mov. SINIESTRO")
};

const u8 gText_BattleTourney[] = _("TORNEO de COMBATES");
static const u8 sText_Round1[] = _("1.ª ronda");
static const u8 sText_Round2[] = _("2.ª ronda");
static const u8 sText_Semifinal[] = _("Semifinal");
static const u8 sText_Final[] = _("Final");
#else //ENGLISH
const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Left: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("sleep");
const u8 gText_Poison[] = _("poison");
const u8 gText_Burn[] = _("burn");
const u8 gText_Paralysis[] = _("paralysis");
const u8 gText_Ice[] = _("ice");
const u8 gText_Confusion[] = _("confusion");
const u8 gText_Love[] = _("love");
const u8 gText_SpaceAndSpace[] = _(" and ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("are");
const u8 gText_Are2[] = _("are");
const u8 gText_BadEgg[] = _("Bad EGG");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Draw");
static const u8 sText_SpaceIs[] = _(" is");
static const u8 sText_ApostropheS[] = _("'s");

// For displaying names of invalid moves.
// This is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("a NORMAL move"),
    [TYPE_FIGHTING] = _("a FIGHTING move"),
    [TYPE_FLYING]   = _("a FLYING move"),
    [TYPE_POISON]   = _("a POISON move"),
    [TYPE_GROUND]   = _("a GROUND move"),
    [TYPE_ROCK]     = _("a ROCK move"),
    [TYPE_BUG]      = _("a BUG move"),
    [TYPE_GHOST]    = _("a GHOST move"),
    [TYPE_STEEL]    = _("a STEEL move"),
    [TYPE_MYSTERY]  = _("a ??? move"),
    [TYPE_FIRE]     = _("a FIRE move"),
    [TYPE_WATER]    = _("a WATER move"),
    [TYPE_GRASS]    = _("a GRASS move"),
    [TYPE_ELECTRIC] = _("an ELECTRIC move"),
    [TYPE_PSYCHIC]  = _("a PSYCHIC move"),
    [TYPE_ICE]      = _("an ICE move"),
    [TYPE_DRAGON]   = _("a DRAGON move"),
    [TYPE_DARK]     = _("a DARK move")
};

const u8 gText_BattleTourney[] = _("BATTLE TOURNEY");
static const u8 sText_Round1[] = _("Round 1");
static const u8 sText_Round2[] = _("Round 2");
static const u8 sText_Semifinal[] = _("Semifinal");
static const u8 sText_Final[] = _("Final");
#endif

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};
#if FRENCH
static const u8 gText_TheGreatNewHope[] = _("The great new hope!\p"); // Unused
static const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p"); // Unused
static const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p"); // Unused
static const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p"); // Unused
static const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p"); // Unused
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mental");
const u8 gText_Skill[] = _("Technique");
const u8 gText_Body[] = _("Physique");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Jugement{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_OPPONENT_MON1_NAME} est envoyé par\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p{B_OPPONENT_MON2_NAME} est envoyé par\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_BUFF1} est envoyé par\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("Un combat est lancé\npar {B_TRAINER1_CLASS} {B_TRAINER1_NAME} et\l{B_TRAINER2_CLASS} {B_TRAINER2_NAME}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PLAYER_MON2_NAME} est envoyé par\n{B_PARTNER_CLASS} {B_PARTNER_NAME}!\p{B_PLAYER_MON1_NAME}! Go!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} et\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lont perdu!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} est incapable\nd’utiliser sa puissance!");
static const u8 sText_GlintAppearsInEye[] = _("Une lueur apparaît dans les\nyeux de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} se met\nen position!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} commence\nà grogner méchamment!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} en veut encore!");
#elif ITALIAN
static const u8 gText_TheGreatNewHope[] = _("The great new hope!\p"); // Unused
static const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p"); // Unused
static const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p"); // Unused
static const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p"); // Unused
static const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p"); // Unused
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mente");
const u8 gText_Skill[] = _("Abilità");
const u8 gText_Body[] = _("Corpo");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Voto{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("È il turno di {B_OPPONENT_MON1_NAME}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\pÈ il turno di {B_OPPONENT_MON2_NAME}, mandato in\ncampo da {B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("È il turno di {B_BUFF1}, mandato in\ncampo da {B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("Parte la sfida di \n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}, e\l{B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("È il turno di {B_PLAYER_MON2_NAME}, mandato in\ncampo da {B_PARTNER_NAME}, {B_PARTNER_CLASS}!\pVai, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("Hai avuto la meglio su\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}, e\l{B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} non è al massimo\ndella potenza!");
static const u8 sText_GlintAppearsInEye[] = _("Negli occhi di {B_SCR_ACTIVE_NAME_WITH_PREFIX} è\napparsa una scintilla!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} si sta mettendo\nin posizione!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha iniziato a\nruggire profondamente!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} è impaziente!");
#elif SPANISH
static const u8 gText_TheGreatNewHope[] = _("The great new hope!\p"); // Unused
static const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p"); // Unused
static const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p"); // Unused
static const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p"); // Unused
static const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p"); // Unused
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mente");
const u8 gText_Skill[] = _("Habilidad");
const u8 gText_Body[] = _("Cuerpo");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}a{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("¡{B_OPPONENT_MON1_NAME} es el POKéMON enviado \npor {B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p¡{B_OPPONENT_MON2_NAME} es el POKéMON enviado \npor {B_TRAINER2_CLASS} {B_TRAINER2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("¡{B_BUFF1} es el POKéMON enviado \npor {B_TRAINER2_CLASS} {B_TRAINER2_NAME}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} y\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lquieren luchar!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("¡{B_PLAYER_MON2_NAME} es el POKéMON enviado \npor {B_PARTNER_CLASS} {B_PARTNER_NAME}!\p¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("¡Derrota para\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\ly {B_TRAINER2_CLASS} {B_TRAINER2_NAME}!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("¡Parece que {B_ATK_NAME_WITH_PREFIX} no es\ncapaz de usar su fuerza!");
static const u8 sText_GlintAppearsInEye[] = _("¡A {B_SCR_ACTIVE_NAME_WITH_PREFIX} se le\nha encendido la mirada!");
static const u8 sText_PkmnGettingIntoPosition[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nestá preparándose!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha empezado\na gruñir con fuerza!");
static const u8 sText_PkmnEagerForMore[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} no se da\npor satisfecho!");
#else //ENGLISH
static const u8 gText_TheGreatNewHope[] = _("The great new hope!\p"); // Unused
static const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p"); // Unused
static const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p"); // Unused
static const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p"); // Unused
static const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p"); // Unused
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mind");
const u8 gText_Skill[] = _("Skill");
const u8 gText_Body[] = _("Body");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwant to battle!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_CLASS} {B_PARTNER_NAME} sent\nout {B_PLAYER_MON2_NAME}!\lGo, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwere defeated!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} appears incapable\nof using its power!");
static const u8 sText_GlintAppearsInEye[] = _("A glint appears in\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s eyes!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is getting into\nposition!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} began growling deeply!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is eager for more!");
#endif

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};
#if FRENCH
static const u8 sText_RefIfNothingIsDecided[] = _("ARBITRE: Si rien n’est décidé en 3\ntours, nous donnerons notre jugement!");
static const u8 sText_RefThatsIt[] = _("ARBITRE: Nous allons maintenant\ndécider du vainqueur.");
static const u8 sText_RefJudgeMind[] = _("ARBITRE: Catégorie 1, le mental!\nLe POKéMON le plus agressif!\p");
static const u8 sText_RefJudgeSkill[] = _("ARBITRE: Catégorie 2, la technique!\nLe POKéMON qui maîtrise le mieux\lses capacités!\p");
static const u8 sText_RefJudgeBody[] = _("ARBITRE: Catégorie 3, le physique!\nLe POKéMON le plus résistant!\p");
static const u8 sText_RefPlayerWon[] = _("ARBITRE: Jugement: {B_BUFF1} à {B_BUFF2}! Le gagnant\nest le {B_PLAYER_MON1_NAME} de {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("ARBITRE: Jugement: {B_BUFF1} à {B_BUFF2}! Le gagnant \nest le {B_OPPONENT_MON1_NAME} de {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("ARBITRE: Jugement: 3 à 3!\nC’est un match nul!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} bat {B_OPPONENT_MON1_NAME} sur\ndécision de l’ARBITRE!");
static const u8 sText_LostToOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} perd contre {B_OPPONENT_MON1_NAME}\nsur décision de l’ARBITRE!");
static const u8 sText_TiedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} est à égalité avec\n{B_OPPONENT_MON1_NAME} sur décision de l’ARBITRE!");
static const u8 sText_RefCommenceBattle[] = _("ARBITRE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nCommencez le combat!");
#elif ITALIAN
static const u8 sText_RefIfNothingIsDecided[] = _("ARBITRO: Se dopo 3 turni non c’è\nnulla di fatto, si passa ai punti!");
static const u8 sText_RefThatsIt[] = _("ARBITRO: Passeremo ai punti per\ndecretare il vincitore!");
static const u8 sText_RefJudgeMind[] = _("ARBITRO: Criterio di giudizio 1: Mente!\nIl POKéMON più valoroso!\p");
static const u8 sText_RefJudgeSkill[] = _("ARBITRO: Criterio di giudizio 2: Abilità!\nIl POKéMON che usa meglio le mosse!\p");
static const u8 sText_RefJudgeBody[] = _("ARBITRO: Criterio di giudizio 3: Corpo!\nIl POKéMON più vitale!\p");
static const u8 sText_RefPlayerWon[] = _("ARBITRO: {B_BUFF1} a {B_BUFF2}!\nVince {B_PLAYER_MON1_NAME} di {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("ARBITRO: {B_BUFF1} a {B_BUFF2}!\nVince {B_OPPONENT_MON1_NAME} di {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("ARBITRO: 3 a 3!\nAbbiamo un pareggio!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("L’ARBITRO ha decretato la vittoria\ndi {B_PLAYER_MON1_NAME} contro {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LostToOpponentByReferee[] = _("L’ARBITRO ha decretato la vittoria\ndi {B_OPPONENT_MON1_NAME} contro {B_PLAYER_MON1_NAME}!");
static const u8 sText_TiedOpponentByReferee[] = _("L’ARBITRO ha decretato il pareggio\ntra {B_PLAYER_MON1_NAME} e {B_OPPONENT_MON1_NAME}!");
static const u8 sText_RefCommenceBattle[] = _("ARBITRO: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nChe la lotta abbia inizio!");
#elif SPANISH
static const u8 sText_RefIfNothingIsDecided[] = _("JUEZ: Si la cosa no se decide en las\n3 próximas rondas, emitiremos un juicio.");
static const u8 sText_RefThatsIt[] = _("JUEZ: ¡Se acabó! Vamos a determinar\nquién consideramos que ha ganado.");
static const u8 sText_RefJudgeMind[] = _("JUEZ: Lo 1.º en valorar es la mente:\nqué POKéMON ha tenido más coraje.\p");
static const u8 sText_RefJudgeSkill[] = _("JUEZ: Lo 2.º, la habilidad: qué\nPOKéMON ha usado mejor sus ataques.\p");
static const u8 sText_RefJudgeBody[] = _("JUEZ: Lo 3.º, el cuerpo:\nqué POKéMON está más entero.\p");
static const u8 sText_RefPlayerWon[] = _("JUEZ: El resultado es {B_BUFF1} a {B_BUFF2}…\n¡Ha ganado {B_PLAYER_MON1_NAME}, de {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("JUEZ: El resultado es {B_BUFF1} a {B_BUFF2}…\n¡Ha ganado {B_OPPONENT_MON1_NAME}, de {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("JUEZ: El resultado es 3 a 3…\n¡Eso es empate!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("Por decisión del JUEZ, ¡{B_PLAYER_MON1_NAME}\nha ganado a su rival {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LostToOpponentByReferee[] = _("Por decisión del JUEZ, ¡{B_PLAYER_MON1_NAME}\nha perdido ante su rival {B_OPPONENT_MON1_NAME}!");
static const u8 sText_TiedOpponentByReferee[] = _("Por decisión del JUEZ, ¡{B_PLAYER_MON1_NAME}\ny {B_OPPONENT_MON1_NAME} han empatado!");
static const u8 sText_RefCommenceBattle[] = _("JUEZ: ¡Comienza el encuentro\n{B_PLAYER_MON1_NAME} contra {B_OPPONENT_MON1_NAME}!");
#else //ENGLISH
static const u8 sText_RefIfNothingIsDecided[] = _("REFEREE: If nothing is decided in\n3 turns, we will go to judging!");
static const u8 sText_RefThatsIt[] = _("REFEREE: That's it! We will now go to\njudging to determine the winner!");
static const u8 sText_RefJudgeMind[] = _("REFEREE: Judging category 1, Mind!\nThe POKéMON showing the most guts!\p");
static const u8 sText_RefJudgeSkill[] = _("REFEREE: Judging category 2, Skill!\nThe POKéMON using moves the best!\p");
static const u8 sText_RefJudgeBody[] = _("REFEREE: Judging category 3, Body!\nThe POKéMON with the most vitality!\p");
static const u8 sText_RefPlayerWon[] = _("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_RefDraw[] = _("REFEREE: Judgment: 3 to 3!\nWe have a draw!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} defeated the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
static const u8 sText_LostToOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} lost to the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
static const u8 sText_TiedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} tied the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
static const u8 sText_RefCommenceBattle[] = _("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nCommence battling!");
#endif

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};
#if FRENCH
static const u8 sText_QuestionForfeitMatch[] = _("Voulez-vous abandonner et\nquitter le combat?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} abandonne le match!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} a\ngagné!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("Egalité avec \n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _("Voulez-vous enregistrer votre\ncombat sur le PASSE ZONE?");
const u8 gText_BattleRecordedOnPass[] = _("Le résultat de {B_PLAYER_NAME} est\nenregistré sur le PASSE ZONE.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{B_LINK_OPPONENT1_NAME}\nveut se battre!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{B_LINK_OPPONENT1_NAME} et {B_LINK_OPPONENT2_NAME}\nveulent se battre!{PAUSE 49}");
#elif ITALIAN
static const u8 sText_QuestionForfeitMatch[] = _("Vuoi rinunciare all’incontro e\nuscire ora?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} lascia l’incontro!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("La sfida è vinta da\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("La sfida contro {B_TRAINER1_NAME},\n{B_TRAINER1_CLASS}, si è conclusa\lin parità!");
const u8 gText_RecordBattleToPass[] = _("Vuoi che il filmato della tua lotta \nvenga registrato nel PASS PARCO?");
const u8 gText_BattleRecordedOnPass[] = _("Il filmato della lotta di {B_PLAYER_NAME} è\nstato registrato nel PASS PARCO.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME}!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!{PAUSE 49}");
#elif SPANISH
static const u8 sText_QuestionForfeitMatch[] = _("¿Quieres abandonar el encuentro\ny salir?");
static const u8 sText_ForfeitedMatch[] = _("¡{B_PLAYER_NAME} abandona el encuentro!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("¡Has perdido contra\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha\nempatado contigo!");
const u8 gText_RecordBattleToPass[] = _("¿Quieres grabar el combate\nen el PASE del FRENTE?");
const u8 gText_BattleRecordedOnPass[] = _("El combate de {B_PLAYER_NAME} se ha grabado\nen el PASE del FRENTE.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME}\nquiere luchar!");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}\nquieren luchar!");
#else //ENGLISH
static const u8 sText_QuestionForfeitMatch[] = _("Would you like to forfeit the match\nand quit now?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} forfeited the match!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("Player lost against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("Player battled to a draw against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _("Would you like to record your battle\non your FRONTIER PASS?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}'s battle result was recorded\non the FRONTIER PASS.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{B_LINK_OPPONENT1_NAME}\nwants to battle!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}\nwant to battle!{PAUSE 49}");
#endif

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VICE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
    #if SPANISH
        .fontId = FONT_NARROW,
    #else
        .fontId = FONT_NORMAL,
    #endif
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
    #if SPANISH
        .fontId = FONT_NARROW,
    #else
        .fontId = FONT_NORMAL,
    #endif
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;
#if EUROPE
    u32 size;
    u8 *txtBuff;
#endif

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleBufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    *(&gBattleStruct->scriptPartyIdx) = gBattleMsgDataPtr->bakScriptPartyIdx;
    *(&gBattleStruct->hpScale) = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    *(&gBattleStruct->stringMoveType) = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        ChooseMoveUsedParticle(gBattleTextBuff1); // buff1 doesn't appear in the string, leftover from japanese move names

        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff2, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff2, gMoveNames[gBattleMsgDataPtr->currentMove]);

        ChooseTypeOfMoveUsedString(gBattleTextBuff2);
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

#if EUROPE
    size = StringLength(stringPtr) + 1;
    txtBuff = Alloc(size);
    memcpy(txtBuff, stringPtr, size);
    #if FRENCH || SPANISH
        // This swaps Team's Aqua/Magma class / name ;
        // French: Team Aqua Sbire -> Sbire Team Aqua
        // S: Equipo Aqua Soldado -> Soldado Equipo Aqua
        if (!(gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
            && gTrainerBattleOpponent_A != TRAINER_UNION_ROOM && gTrainerBattleOpponent_A != TRAINER_FRONTIER_BRAIN
            && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_HILL)))
        {
            u8 *toSwap, *txt;
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gTrainerBattleOpponent_A < TRAINERS_COUNT)
            {
                if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_TEAM_MAGMA || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_TEAM_AQUA)
                {
                    toSwap = NULL, txt = txtBuff;
                    while (*txt != EOS)
                    {
                        if (*txt == PLACEHOLDER_BEGIN)
                        {
                            txt++;
                            if (*txt == B_TXT_TRAINER1_CLASS)
                            {
                                toSwap = txt;
                            }
                            else if (*txt == B_TXT_TRAINER1_NAME && toSwap != NULL)
                            {
                                *toSwap = B_TXT_TRAINER1_NAME;
                                *txt = B_TXT_TRAINER1_CLASS;
                            }
                        }
                        txt++;
                    }
                }
            }
            if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && gTrainerBattleOpponent_B < TRAINERS_COUNT)
            {
                if (gTrainers[gTrainerBattleOpponent_B].trainerClass == TRAINER_CLASS_TEAM_MAGMA || gTrainers[gTrainerBattleOpponent_B].trainerClass == TRAINER_CLASS_TEAM_AQUA)
                {
                    toSwap = NULL, txt = txtBuff;
                    while (*txt != EOS)
                    {
                        if (*txt == PLACEHOLDER_BEGIN)
                        {
                            txt++;
                            if (*txt == B_TXT_TRAINER2_CLASS)
                            {
                                toSwap = txt;
                            }
                            else if (*txt == B_TXT_TRAINER2_NAME && toSwap != NULL)
                            {
                                *toSwap = B_TXT_TRAINER2_NAME;
                                *txt = B_TXT_TRAINER2_CLASS;
                            }
                        }
                        txt++;
                    }
                }
            }
        }
    #endif
    BattleStringExpandPlaceholdersToDisplayedString(txtBuff);
    Free(txtBuff);
#else //ENGLISH
    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
#endif
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

#if EUROPE
// wild Pokemon -> Pokemon wild
#define HANDLE_NICKNAME_STRING_CASE(battlerId, monIndex)                \
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
                                                                        \
        GetMonData(&gEnemyParty[monIndex], MON_DATA_NICKNAME, text);    \
        StringGet_Nickname(text);                                       \
        StringAppend(text, toCpy);                                      \
    }                                                                   \
    else                                                                \
    {                                                                   \
        GetMonData(&gPlayerParty[monIndex], MON_DATA_NICKNAME, text);   \
        StringGet_Nickname(text);                                       \
    }                                                                   \
                                           \
    toCpy = text;
#else //ENGLISH
#define HANDLE_NICKNAME_STRING_CASE(battler, monIndex)                \
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
        GetMonData(&gEnemyParty[monIndex], MON_DATA_NICKNAME, text);    \
    }                                                                   \
    else                                                                \
    {                                                                   \
        GetMonData(&gPlayerParty[monIndex], MON_DATA_NICKNAME, text);   \
    }                                                                   \
    StringGet_Nickname(text);                                           \
    toCpy = text;
#endif

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    // This buffer may hold either the name of a trainer, Pokémon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 multiplayerId;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 1]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 2]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 3]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // attacker name with prefix, only battler 0/1
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker,
                                            gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker))])
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);

                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget, gBattlerPartyIndexes[gBattlerTarget])
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler, gBattlerPartyIndexes[gEffectBattler])
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, gBattlerPartyIndexes[gBattleScripting.battler])
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                    #if EUROPE
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    #else //ENGLISH
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    #endif
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
            #if EUROPE
            {
                s32 gender = -1, trClass;
                const u8 *trName = NULL;
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                    trClass = GetSecretBaseTrainerClass();
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    trClass = GetUnionRoomTrainerClass();
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                    trClass = GetFrontierBrainTrainerClass();
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    trClass = GetFrontierOpponentClass(gTrainerBattleOpponent_A), gender = IsFrontierTrainerFemale(gTrainerBattleOpponent_A);
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    trClass = GetTrainerHillOpponentClass(gTrainerBattleOpponent_A);
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                    trClass = GetEreaderTrainerClassId();
                else
                {
                    trClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                    gender = gTrainers[gTrainerBattleOpponent_A].encounterMusic_gender & 0x7F;
                    trName = gTrainers[gTrainerBattleOpponent_A].trainerName;
                }
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, trName);
                break;
            }
            #else //ENGLISH
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                    toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                    toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                    toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_A].trainerClass];
                break;
            #endif
            case B_TXT_TRAINER1_NAME: // trainer1 name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                {
                    for (i = 0; i < (s32) ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
                        text[i] = gBattleResources->secretBase->trainerName[i];
                    text[i] = EOS;
                    ConvertInternationalString(text, gBattleResources->secretBase->language);
                    toCpy = text;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                {
                    toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                {
                    CopyFrontierBrainTrainerName(text);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                {
                    GetEreaderTrainerName(text);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_A].trainerName;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    toCpy = gLinkPlayers[0].name;
                else
                    toCpy = gSaveBlock2Ptr->playerName;
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, *(&gBattleStruct->scriptPartyIdx))
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
            #if EUROPE
            {
                s32 gender = -1, trClass;
                const u8 *trName = NULL;
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    trClass = GetFrontierOpponentClass(gTrainerBattleOpponent_B), gender = IsFrontierTrainerFemale(gTrainerBattleOpponent_B);
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    trClass = GetTrainerHillOpponentClass(gTrainerBattleOpponent_B);
                else
                {
                    trClass = gTrainers[gTrainerBattleOpponent_B].trainerClass;
                    gender = gTrainers[gTrainerBattleOpponent_B].encounterMusic_gender & 0x7F;
                    trName = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, trName);
                break;
            }
            #else //ENGLISH
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_B)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_B)];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_B].trainerClass];
                break;
            #endif
            case B_TXT_TRAINER2_NAME:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
            #if EUROPE
            {
                s32 trClass = GetFrontierOpponentClass(gPartnerTrainerId);
                s32 gender = IsFrontierTrainerFemale(gPartnerTrainerId);
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, NULL);
                break;
            }
            #else //ENGLISH
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            #endif
            case B_TXT_PARTNER_NAME:
                GetFrontierTrainerName(text, gPartnerTrainerId);
                toCpy = text;
                break;
            }

            // missing if (toCpy != NULL) check
            while (*toCpy != EOS)
            {
                dst[dstID] = *toCpy;
                dstID++;
                toCpy++;
            }
            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            #if EUROPE
            if (hword == STRINGID_STATSHARPLY || hword == STRINGID_STATHARSHLY)
                srcID += 3;
            #endif
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        #if EUROPE
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
                StringGet_Nickname(nickname);
                StringAppend(dst, nickname);
            }
            else
            {
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);
            }
        #else //ENGLISH
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
        #endif
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            else
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            StringGet_Nickname(dst);
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                #if EUROPE
                    CopyItemName(hword, dst);
                #else //ENGLISH
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                #endif
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "は" or "の") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "を つかった！". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "した！". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "を した！" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " こうげき！" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleBufferA[gActiveBattler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

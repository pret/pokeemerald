#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_record.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_special.h"
#include "battle_z_move.h"
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
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "trainer_slide.h"
#include "trainer_tower.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    union {
        struct {
            DEPRECATED("Use color.background instead") u8 bgColor;
            DEPRECATED("Use color.foreground instead") u8 fgColor;
            DEPRECATED("Use color.shadow instead") u8 shadowColor;
            DEPRECATED("Use color.accent instead") u8 accentColor;
        };
        union TextColor color;
    };
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
};

#if TESTING
EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#else
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#endif
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_EmptyString4[] = _("");

const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_NAME_WITH_PREFIX} surrounds itself with a protective mist!");
const u8 gText_PkmnGettingPumped[] = _("{B_DEF_NAME_WITH_PREFIX} is getting pumped!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1} is preventing switching out with its {B_LAST_ABILITY} Ability!\p");
const u8 gText_StatSharply[] = _(" sharply");
const u8 gText_StatRose[] = _("rose!");
const u8 gText_StatFell[] = _("fell!");
const u8 gText_DefendersStatRose[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} rose{B_BUFF2}!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}You got away safely!\p");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("You defeated {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("You defeated {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("You lost against {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("You lost to {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("You battled to a draw against {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("You battled to a draw against {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} fled!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME} fled!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("You defeated {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Oh! A wild {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME} appeared!\p");
static const u8 sText_GhostAppearedCantId[] = _("The GHOST appeared!\pDarn!\nThe GHOST can't be ID'd!\p");
static const u8 sText_TheGhostAppeared[] = _("The GHOST appeared!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("You are challenged by {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("You are challenged by {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("You are challenged by {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_BUFF1}!");
static const u8 sText_LinkTrainerIntroSendOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkTrainer2SentOutPkmn2[] = _("{B_LINK_OPPONENT2_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersIntroSendOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}! {B_LINK_OPPONENT2_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} sent out {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Go! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Go! {B_PLAYER_MON1_NAME} and {B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Go! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("You're in charge, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Go for it, {B_BUFF1}!");
static const u8 sText_BeCarefulPkmn[] = _("Be careful, {B_PLAYER_MON1_NAME}!");
static const u8 sText_JustALittleMorePkmn[] = _("Just a little more! Hang in there, {B_BUFF1}!"); //currently unused, will require code changes
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Your opponent's weak! Get 'em, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmn1GoPkmn[] = _("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON1_NAME}! Go, {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn2GoPkmn[] = _("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON2_NAME}! Go, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn1[] = _("{B_LINK_PARTNER_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmn2[] = _("{B_LINK_PARTNER_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkPartnerWithdrewPkmn1[] = _("{B_LINK_PARTNER_NAME} withdrew {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerWithdrewPkmn2[] = _("{B_LINK_PARTNER_NAME} withdrew {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_PkmnSwitchOut[] = _("{B_BUFF1}, switch out! Come back!"); //currently unused, I believe its used for when you switch on a Pokémon in shift mode
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, that's enough! Come back!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, come back!");
static const u8 sText_PkmnOkComeBack[] = _("OK, {B_BUFF1}! Come back!");
static const u8 sText_PkmnGoodComeBack[] = _("Good job, {B_BUFF1}! Come back!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} withdrew {B_BUFF1}!");
static const u8 sText_Trainer2WithdrewPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} withdrew {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} withdrew {B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_OPPONENT2_NAME} withdrew {B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _("The wild ");
static const u8 sText_FoePkmnPrefix[] = _("The opposing ");
static const u8 sText_WildPkmnPrefixLower[] = _("the wild ");
static const u8 sText_FoePkmnPrefixLower[] = _("the opposing ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Opposing");
static const u8 sText_AllyPkmnPrefix[] = _("Ally");
static const u8 sText_FoePkmnPrefix3[] = _("Opposing");
static const u8 sText_AllyPkmnPrefix2[] = _("Ally");
static const u8 sText_FoePkmnPrefix4[] = _("Opposing");
static const u8 sText_AllyPkmnPrefix3[] = _("Ally");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} used {B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("HP");
static const u8 sText_Attack[] = _("Attack");
static const u8 sText_Defense[] = _("Defense");
static const u8 sText_Speed[] = _("Speed");
static const u8 sText_SpAttack[] = _("Sp. Atk");
static const u8 sText_SpDefense[] = _("Sp. Def");
static const u8 sText_Accuracy[] = _("accuracy");
static const u8 sText_Evasiveness[] = _("evasiveness");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP,
    [STAT_ATK]     = sText_Attack,
    [STAT_DEF]     = sText_Defense,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAttack,
    [STAT_SPDEF]   = sText_SpDefense,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};
const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("was too spicy!"),
    [FLAVOR_DRY]    = COMPOUND_STRING("was too dry!"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("was too sweet!"),
    [FLAVOR_BITTER] = COMPOUND_STRING("was too bitter!"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("was too sour!"),
};

static const u8 sText_Someones[] = _("someone's");
static const u8 sText_Lanettes[] = _("LANETTE's"); //no decapitalize until it is everywhere
static const u8 sText_Bills[] = _("BILL's");
static const u8 sText_EnigmaBerry[] = _("ENIGMA BERRY"); //no decapitalize until it is everywhere
static const u8 sText_BerrySuffix[] = _(" BERRY"); //no decapitalize until it is everywhere
const u8 gText_EmptyString3[] = _("");

static const u8 sText_TwoInGameTrainersDefeated[] = _("You defeated {B_TRAINER1_NAME_WITH_CLASS} and {B_TRAINER2_NAME_WITH_CLASS}!\p");

// New battle strings.
const u8 gText_drastically[] = _(" drastically");
const u8 gText_severely[] = _("severely ");
static const u8 sText_TerrainReturnedToNormal[] = _("The terrain returned to normal!"); // Unused

const u8 *const gBattleStringsTable[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("{B_BUFF1} gained{B_BUFF2} {B_BUFF3} Exp. Points!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("{B_BUFF1} grew to Lv. {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("{B_BUFF1} learned {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} wants to learn the move {B_BUFF2}.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("However, {B_BUFF1} already knows four moves.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("Should another move be forgotten and replaced with {B_BUFF2}?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} forgot {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}Do you want to give up on having {B_BUFF1} learn {B_BUFF2}?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} did not learn {B_BUFF2}.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} learned {B_BUFF1}!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} protected itself!"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("It doesn't affect {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_ITDOESNTAFFECTSCR]                    = COMPOUND_STRING("It doesn't affect {B_SCR_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} fainted!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("You got ¥{B_BUFF1} for winning!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("You have no more Pokémon that can fight!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("You panicked and dropped ¥{B_BUFF1}…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("You gave ¥{B_BUFF1} to the winner…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("You were overwhelmed by your defeat!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} prevents escape with {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("The Pokémon was hit {B_BUFF1} time{B_BUFF2}!"),
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell asleep!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} made {B_EFF_NAME_WITH_PREFIX2} sleep!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already asleep!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is already asleep!"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was poisoned!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was poisoned by {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its poisoning!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already poisoned!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was badly poisoned!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} had its energy drained!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was burned!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} burned {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its burn!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was frozen solid!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} froze {B_EFF_NAME_WITH_PREFIX2} solid!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is frozen solid!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} thawed out!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} melted the ice!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is paralyzed, so it may be unable to move!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} paralyzed {B_EFF_NAME_WITH_PREFIX2}, so it may be unable to move!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} couldn't move because it's paralyzed!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already paralyzed!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was cured of paralysis!"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any lower!"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is confused!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} snapped out of its confusion!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became confused!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is already confused!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell in love!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is in love with {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is immobilized by love!"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flinched and couldn't move!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s HP was restored."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s HP is full!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("Light Screen made {B_ATK_TEAM2} side stronger against special moves!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("Reflect made {B_ATK_TEAM2} side stronger against physical moves!"),
    [STRINGID_PKMNAURORAVEIL]                       = COMPOUND_STRING("Aurora Veil made {B_ATK_TEAM2} side stronger against physical and special moves!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("{B_ATK_TEAM1} side became cloaked in a mystical veil!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by Safeguard!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("{B_ATK_TEAM1} side is no longer protected by the mystical veil!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} went to sleep!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} slept and restored its HP!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} whipped up a whirlwind!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed light!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tucked in its head!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flew up high!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} burrowed its way under the ground!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was squeezed by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped in the vortex!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was wrapped by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} clamped down on {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kept going and crashed!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by the mist!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was damaged by the recoil!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} protected itself!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is buffeted by the sandstorm!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is buffeted by the hail!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was seeded!"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} avoided the attack!"),
    [STRINGID_BATTLERAVOIDEDATTACK]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} avoided the attack!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s health is sapped by Leech Seed!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is fast asleep."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("The uproar woke {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} caused an uproar!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is making an uproar!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} calmed down."),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stockpiled {B_BUFF1}!"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("But {B_DEF_NAME_WITH_PREFIX2} can't sleep in an uproar!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("But the uproar kept {B_DEF_NAME_WITH_PREFIX2} awake!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} stayed awake!"),
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is storing energy!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} unleashed its energy!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} became confused due to fatigue!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("You picked up ¥{B_BUFF1}!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is unaffected!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} put in a substitute!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} already has a substitute!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("The substitute took damage for {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s substitute faded!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} must recharge!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s rage is building!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} is disabled!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s move is no longer disabled!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} must do an encore!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} can only use {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ended its encore!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} took aim at {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sketched {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hoping to take its attacker down with it!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took its attacker down with it!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} lost {B_BUFF2} PP from {B_BUFF1}!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole {B_BUFF2}'s {B_LAST_ITEM}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can no longer escape!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} began having a nightmare!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is locked in a nightmare!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cut its own HP and put a curse on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is afflicted by the curse!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("Spikes were scattered on the ground all around {B_DEF_TEAM2} side!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was hurt by the spikes!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was identified!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s perish count fell to {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} braced itself!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} endured the hit!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("Magnitude {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cut its own HP and maximized its Attack!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} copied {B_EFF_NAME_WITH_PREFIX2}'s stat changes!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!"),
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from Leech Seed!"),
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Spikes!"), // Not in gen 5+
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fled from battle!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foresaw an attack!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the {B_BUFF1} attack!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("{B_BUFF1}'s attack!"), // Not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} became the center of attention!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} began charging power!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Nature Power turned into {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s status returned to normal!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} has no moves left that it can use!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was subjected to torment!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use the same move twice in a row due to the torment!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is tightening its focus!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell for the taunt!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} after the taunt!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is ready to help {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched items with its target!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} copied {B_DEF_NAME_WITH_PREFIX2}'s Ability!"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("{B_BUFF1}'s wish came true!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} planted its roots!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed nutrients with its roots!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is anchored in place with its roots!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} grew drowsy!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} knocked off {B_EFF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} swapped Abilities with its target!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sealed any moves its target shares with it!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use its sealed {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wants its target to bear a grudge!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lost all of {B_BUFF1}'s PP due to the grudge!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shrouded itself with Magic Coat!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} bounced the {B_CURRENT_MOVE} back!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is waiting for a target to make a move!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} snatched {B_SCR_NAME_WITH_PREFIX2}'s move!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} made it rain!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was protected by {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents {B_ATK_NAME_WITH_PREFIX2} from using {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} had its HP restored."),
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s type changed to {B_BUFF1}!"),
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents romance!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} cannot be confused!"),
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("The power of {B_SCR_NAME_WITH_PREFIX}'s Fire-type moves rose!"),
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is anchored in place with its suction cups!"),
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s stats were not lowered!"),
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by {B_DEF_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("It traced {B_BUFF1}'s {B_BUFF2}!"),
    [STRINGID_STATSHARPLY]                          = gText_StatSharply,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("harshly "),
    [STRINGID_STATROSE]                             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} rose{B_BUFF2}!"),
    [STRINGID_STATFELL]                             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}fell!"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("A critical hit!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("It's a one-hit KO!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("One…{PAUSE 10}two…{PAUSE 10}and…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}ta-da!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("And…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("It's not very effective…"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("It's super effective!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}The wild {B_BUFF1} fled!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("No! There's no running from a Trainer battle!\p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("You can't escape!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("PROF. BIRCH: Don't leave me like this!\p"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("But nothing happened!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("But it failed!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("It hurt itself in its confusion!"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("It started to rain!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("A downpour started!"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("Rain continues to fall."), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("The downpour continues."), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("The rain stopped."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("A sandstorm kicked up!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("The sandstorm is raging."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("The sandstorm subsided."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("The sunlight turned harsh!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("The sunlight is strong."), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("The sunlight faded."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("It started to hail!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("The hail is crashing down."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("The hail stopped."),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("All stat changes were eliminated!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("Coins were scattered everywhere!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("But it does not have enough HP left to make a substitute!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("The battlers shared their pain!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("A bell chimed!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("All Pokémon that heard the song will faint in three turns!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("There's no PP left for this move!\p"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("But there was no PP left for the move!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("You used {B_LAST_ITEM}!"),
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("The Trainer blocked your Poké Ball!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("Don't be a thief!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("It dodged your thrown Poké Ball! This Pokémon can't be caught!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("Oh no! The Pokémon broke free!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("Aww! It appeared to be caught!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("Aargh! Almost had it!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("Gah! It was so close, too!"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("Gotcha! {B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("Gotcha! {B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("Would you like to give {B_DEF_NAME} a nickname?"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("{B_DEF_NAME}'s data has been added to the Pokédex!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("It's raining!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("The sandstorm is raging!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("You couldn't get away!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignored orders and kept sleeping!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignored orders!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} began to nap!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is loafing around!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} won't obey!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} turned away!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} pretended not to notice!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} is about to send out {B_BUFF2}. Will you switch your Pokémon?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("{B_PLAYER_NAME} crept closer to {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("{B_PLAYER_NAME} can't get any closer!"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is watching carefully!"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is curious about the {B_BUFF1}!"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is enthralled by the {B_BUFF1}!"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} completely ignored the {B_BUFF1}!"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("{B_PLAYER_NAME} threw a {POKEBLOCK} at the {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}ANNOUNCER: You're out of Safari Balls! Game over!\p"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its paralysis!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its poison!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its burn!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} defrosted it!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} woke it up!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} snapped it out of its confusion!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its {B_BUFF1} problem!"), // Not in Gen 5+
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored its health using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored PP to its move {B_BUFF1} using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} returned its stats to normal using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored a little HP using its {B_LAST_ITEM}!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{B_LAST_ITEM} only allows the use of {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hung on using its {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} had its HP restored."),
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} whipped up a sandstorm!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} was not lowered!"),
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fell in love!"),
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s item cannot be removed!"),
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} sucked up the liquid ooze!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} transformed!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("Electricity's power was weakened!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("Fire's power was weakened!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hid underwater!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sprang up!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("HM moves can't be forgotten now.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} found one {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("A soothing aroma wafted through the area!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Items can't be used now.{PAUSE 64}"), // Not present in Gen 5+
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("The {B_LAST_ITEM}{B_BUFF2} boosted {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("The {B_LAST_ITEM}{B_BUFF2} lowered {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"), // This string does not exist in Gen 5+. Used to print more info that's otherwise obscured such as using Room Service
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used the {B_LAST_ITEM} to get pumped!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} made {B_CURRENT_MOVE} useless!"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped by the quicksand!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING(" a boosted"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} intensified the sun's rays!"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("You throw a Ball now, right? I… I'll do my best!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the attack!"),
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} chose Doom Desire as its destiny!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lost its focus and couldn't move!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("Use next Pokémon?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled using its {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled using {B_ATK_ABILITY}!\p"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was dragged out!\p"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} normalized its status!"), // Not in Gen 5+
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{B_ATK_TRAINER_NAME_WITH_CLASS} used {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("The Box is full! You can't catch any more!\p"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} made it ineffective!"),
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} prevents flinching!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is already burned!"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} blocks {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("{B_ATK_TEAM1} side's {B_BUFF1} wore off!"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("The wall shattered!"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} cured its {B_BUFF1} problem!"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't escape!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtained {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} obtained {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtained {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("But it had no effect!"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} appears incapable of using its power!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("A glint appears in {B_SCR_NAME_WITH_PREFIX2}'s eyes!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is getting into position!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} began growling deeply!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is eager for more!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("{B_PLAYER_MON1_NAME} defeated the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("{B_PLAYER_MON1_NAME} lost to the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("{B_PLAYER_MON1_NAME} tied the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("Would you like to forfeit the match and quit now?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("The match was forfeited."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} endured the hit using {B_DEF_ABILITY}!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by the {B_LAST_ITEM}!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("Gravity intensified!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("A tailwind started blowing on {B_ATK_TEAM2} side!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} went back to {B_ATK_TRAINER_NAME}!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can't use items anymore!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} flung its {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was prevented from healing!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched its Attack and Defense!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Ability was suppressed!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("Lucky Chant shielded {B_ATK_TEAM2} side from critical hits!"), // Currently not present in Champions
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} acquired {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("Toxic spikes were scattered on the ground all around {B_DEF_TEAM2} side!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched stat changes with its target!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} surrounded itself with a veil of water!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} levitated with electromagnetism!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} twisted the dimensions!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("Pointed stones float in the air on {B_DEF_TEAM2} side!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped by swirling magma!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} vanished instantly!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("{B_CURRENT_MOVE} now protects {B_ATK_TEAM2} side!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shared its guard with the target!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shared its power with the target!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("It created a bizarre area in which Defense and Sp. Def stats are swapped!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became nimble!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was hurled into the air!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("It created a bizarre area in which Pokémon's held items lose their effects!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell straight down!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the kind offer!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s stat changes were removed!"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} and {B_SCR_NAME_WITH_PREFIX2} switched places!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became the same type as {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can use items again!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("electromagnetism"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} wore off!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from the telekinesis!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("{B_ATK_TEAM1} side's tailwind petered out!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("{B_ATK_TEAM1} side's Lucky Chant wore off!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("The twisted dimensions returned to normal!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("Wonder Room wore off, and Defense and Sp. Def stats returned to normal!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("Magic Room wore off, and held items' effects returned to normal!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("The effects of Mud Sport have faded."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("The effects of Water Sport have faded."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("Gravity returned to normal!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("A veil of water restored {B_ATK_NAME_WITH_PREFIX2}'s HP!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("The electricity disappeared from the battlefield."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("The mist disappeared from the battlefield."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("The weirdness disappeared from the battlefield!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("The grass disappeared from the battlefield."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_STATWASMAXEDOUT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} maxed its {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("The poisoning healed {B_ATK_NAME_WITH_PREFIX2} a little bit!"), // Not in Gen 5+
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is tormented!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} breaks the mold!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a bursting aura!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a blazing aura!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is slow to get going!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} finally got its act together!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} takes its toll!"), // Not in Gen 5+
    [STRINGID_PKMNWASHURT]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shuddered!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("{B_SCR_ABILITY} alerted {B_SCR_NAME_WITH_PREFIX2} to {B_EFF_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} healed it a little bit!"), // Not in Gen 5+
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("It started to hail!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was frisked, revealing its {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("{B_EFF_TEAM1} side is too nervous to eat Berries!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} harvested its {B_LAST_ITEM}!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} transformed it into the {B_BUFF1} type!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shared its {B_LAST_ITEM} with {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("Pointed stones dug into {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("The toxic spikes disappeared from the ground around {B_EFF_TEAM2} side!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was poisoned!"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was badly poisoned!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was caught in a sticky web!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("The healing wish came true for {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} regained health!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} became cloaked in mystical moonlight!"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} acquired {B_ATK_ABILITY}!"), // Not in Gen 5+
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} {B_BUFF2}lowered its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("The effects of the {B_LAST_ITEM} prevent status moves from being used!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} because of gravity!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was prevented from healing!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("This move effect is not done yet!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("A sticky web has been laid out on the ground on {B_DEF_TEAM2} side!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s move was postponed!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Toxic Spikes!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Sticky Web!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Stealth Rock!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("A deluge of ions showers the battlefield!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("All stat changes on {B_DEF_NAME_WITH_PREFIX2} were inverted!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("Mist swirled around the battlefield!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("Grass grew to cover the battlefield!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("An electric current ran across the battlefield!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("The battlefield got weird!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s moves have been electrified!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ITEM} is reacting to {B_ATK_TRAINER_NAME}'s Mega Ring!"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} has Mega Evolved into Mega {B_BUFF1}!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} has been afflicted with an infestation by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("It won't have any effect on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("The bursting flames hit {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM} from {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("{B_BUFF1} type was added to {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell for the feint!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cannot use {B_CURRENT_MOVE}!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is covered in powder!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("When the flame touched the powder on the Pokémon, it exploded!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hasn't eaten any held Berries, so it can't possibly belch!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole the target's boosted stats!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell from the sky due to the gravity!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounds itself with a protective mist!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is healed by the grassy terrain!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounds itself with electrified terrain!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by the Psychic Terrain!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is not affected thanks to its {B_LAST_ITEM}!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} surrounded itself with a veil of petals!"),
    [STRINGID_FLOWERVEILPROTECTEDTARGET]            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounded itself with a veil of petals!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is protected by an aromatic veil!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("Congratulations, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} followed {B_ATK_NAME_WITH_PREFIX2}'s instructions!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can use sound-based moves again!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("The effects of Throat Chop prevent {B_ATK_NAME_WITH_PREFIX2} from using certain moves!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} concentrated intensely!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("The {B_LAST_ITEM} strengthened {B_ATK_NAME_WITH_PREFIX2}'s power!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} lessened the damage it took!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} floats in the air with its Air Balloon!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Air Balloon popped!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} was burnt up!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole and ate its target's {B_LAST_ITEM}!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s illusion wore off!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured {B_DEF_NAME_WITH_PREFIX2}'s problem!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} burned itself out!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was cured of {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} was taken over!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is absorbing power!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("No one will be able to leave the battlefield during the next turn!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell in love because of the {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became cloaked in a freezing light!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("The effects of the {B_LAST_ITEM} held by {B_SCR_NAME_WITH_PREFIX2} prevents its stats from being lowered!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("{B_ATK_TRAINER_NAME}'s fervent wish has reached {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("The effects of the weather disappeared."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is exerting its pressure!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a dark aura!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a fairy aura!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} reversed all other Pokémon's auras!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is drowsing!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("All screens on the field were cleansed!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} found a {B_LAST_ITEM}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("A sandstorm kicked up!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("Both Pokémon will faint in three turns!"),
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s aura flared to life!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} has two Abilities!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s stat changes were removed!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted the accuracy of its next move using {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shook off the taunt!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} got over its infatuation!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s item cannot be removed!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("The {B_LAST_ITEM} attached itself to {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s burn was cured!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} held up its Red Card against {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is switched out with the {B_LAST_ITEM}!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} cured its infatuation status using its {B_LAST_ITEM}!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is no longer tormented!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is no longer prevented from healing!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its bond with its trainer!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became Ash-Greninja!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("The sunlight turned extremely harsh!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("The extremely harsh sunlight faded!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("The Water-type attack evaporated in the extremely harsh sunlight!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("The extremely harsh sunlight was not lessened at all!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("A heavy rain began to fall!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("The heavy rain has lifted!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("The Fire-type attack fizzled out in the heavy rain!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("There is no relief from this heavy rain!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("Mysterious strong winds are protecting Flying-type Pokémon!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("The mysterious strong winds have dissipated!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("The mysterious strong winds blow on regardless!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("The mysterious strong winds weakened the attack!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("It can't use the move because it doesn't have a Berry!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Primal Reversion! It reverted to its primal state!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("But {B_ATK_NAME_WITH_PREFIX2} can't use the move!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("But {B_ATK_NAME_WITH_PREFIX2} can't use it the way it is now!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("It broke through {B_EFF_NAME_WITH_PREFIX2}'s protection!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{B_ATK_ABILITY} only allows the use of {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} swapped Abilities with its target!"),
    [STRINGID_PKMNHEALEDPOISON]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was cured of its poisoning!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s type changed to {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("Neither Pokémon can run away!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can no longer escape because it used No Retreat!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} became weaker to fire!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is about to be attacked by its {B_LAST_ITEM}!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can no longer escape because of Octolock!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("Neutralizing gas filled the area!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("The effects of the neutralizing gas wore off!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is too heavy to be lifted!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} took {B_DEF_NAME_WITH_PREFIX2} into the sky!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got trapped by a snap trap!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is overflowing with space power!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} started heating up its beak!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} swapped the battle effects affecting each side of the field!"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} surrounded itself with its Z-Power!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} unleashes its full-force Z-Move!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} returned its decreased stats to normal using its Z-Power!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its stats using its Z-Power!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its critical-hit ratio using its Z-Power!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored its HP using its Z-Power!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its stats using its Z-Power!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s HP was restored by the Z-Power!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} managed to expel the poison so you wouldn't worry!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shook itself awake so you wouldn't worry!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} gathered all its energy to break through its paralysis so you wouldn't worry!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured its burn through sheer determination so you wouldn't worry!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} melted the ice with its fiery determination so you wouldn't worry!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} toughed it out so you wouldn't feel sad!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} used up all its electricity!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched {B_BUFF1} with its target!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("Being hit by {B_CURRENT_MOVE} charged {B_EFF_NAME_WITH_PREFIX2} with power!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("The harsh sunlight activated {B_SCR_NAME_WITH_PREFIX2}'s Protosynthesis!"),
    [STRINGID_ORICHALCUMPULSEACTIVATES]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} turned the sunlight harsh, sending its ancient pulse into a frenzy!"),
    [STRINGID_ORICHALCUMPULSEACTIVATESINSUN]        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} basked in the sunlight, sending its ancient pulse into a frenzy!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} was heightened!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("The Electric Terrain activated {B_SCR_NAME_WITH_PREFIX2}'s Quark Drive!"),
    [STRINGID_HADRONENGINEACTIVATES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} turned the ground into Electric Terrain, energizing its futuristic engine!"),
    [STRINGID_HADRONENGINEACTIVATESINTERRAIN]       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used the Electric Terrain to energize its futuristic engine!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} weakened the {B_BUFF1} of all surrounding Pokémon!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} gained strength from the fallen!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} prevents {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} from working!"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} set a shell trap!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s shell trap didn't work!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("The spikes disappeared from the ground around {B_ATK_TEAM2} side!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("The toxic spikes disappeared from the ground around {B_ATK_TEAM2} side!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("The sticky web has disappeared from the ground on {B_ATK_TEAM2} side!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("The pointed stones disappeared from {B_ATK_TEAM2} side!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} couldn't fully protect itself and got hurt!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s stockpiled effect wore off!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("{B_BUFF1} was revived and is ready to fight again!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{B_BUFF1} had its HP restored."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("{B_BUFF1} had its status healed!"), // Not in Gen 5+
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("The PP of {B_BUFF1}'s {B_BUFF2} was restored!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} trapped {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its frostbite!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got frostbite!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its frostbite!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured its frostbite through sheer determination so you wouldn't worry!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s frostbite was cured!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} cured its frostbite!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used its Mirror Herb to mirror its opponent's stat changes!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("It started to snow!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("Snow continues to fall."), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("The snow stopped."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("It started to snow!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} corroded {B_DEF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("Bright light is about to burst out of {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} regained its true power through Ultra Burst!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("The rest of your team gained Exp. Points thanks to the Exp. Share!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("{B_BUFF1} cannot be used!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is being salt cured!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got covered in sticky candy syrup!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("Sharp-pointed pieces of steel started floating around {B_DEF_TEAM2} Pokémon!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("The sharp steel bit into {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away sharp steel!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("The pieces of steel surrounding {B_ATK_TEAM2} Pokémon disappeared!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon got trapped with vines!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by G-Max Vine Lash's ferocious beating!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon got caught in a vortex of water!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by G-Max Cannonade's vortex!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon were surrounded by fire!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is burning up within G-Max Wildfire's flames!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon became surrounded by rocks!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by rocks thrown out by G-Max Volcalith!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("The move was blocked by the power of Dynamax!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} underwent a heroic transformation!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("The two moves have become one! It's a combined move!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("A rainbow appeared in the sky on {B_EFF_TEAM2} side!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("The rainbow on {B_ATK_TEAM2} side disappeared!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is waiting for {B_ATK_PARTNER_NAME}'s move…{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("A sea of fire enveloped {B_EFF_TEAM2} side!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by the sea of fire!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("The sea of fire around {B_ATK_TEAM2} side disappeared!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("A swamp enveloped {B_EFF_TEAM2} side!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("The swamp around {B_ATK_TEAM2} side disappeared!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is preparing to tell a chillingly bad joke!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} drank down all the matcha that {B_SCR_NAME_WITH_PREFIX2} made!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed electricity!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("The {B_LAST_ITEM} was used up…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} lost its {B_BUFF1} type!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shed its tail to create a decoy!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became cloaked in a harsh light!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("A supersweet aroma is wafting from the syrup covering {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("The dimensions were twisted!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("A bizarre area was created in which Pokémon's held items lose their effects!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("A bizarre area was created in which Defense and Sp. Def stats are swapped!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("Tidying up complete!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} terastallized into the {B_BUFF1} type!"), // Does not exist, meant to mimic form change strings
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used its {B_LAST_ITEM} to activate {B_SCR_ABILITY}!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("Fog crept up as thick as soup!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("The fog is deep…"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("The fog lifted."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} made its shell gleam! It's distorting type matchups!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is going all out for this attack!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was swallowed by {B_BUFF1} and became {B_BUFF1}'s commander!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} played the {B_LAST_ITEM}.\pNow, that's a catchy tune!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} played the {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("The Pokémon hearing the flute awoke!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("The sunlight is harsh!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("It's hailing!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("It's snowing!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("The battlefield is covered with grass!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("Mist swirls around the battlefield!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("An electric current is running across the battlefield!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("The battlefield seems weird!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("Waggling a finger let it use {B_CURRENT_MOVE}!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("Sleep Clause kept {B_DEF_NAME_WITH_PREFIX2} awake!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("It's super effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("It's not very effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}."),
    [STRINGID_ITDOESNTAFFECTTWOFOES]                = COMPOUND_STRING("It doesn't affect {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}…"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("Add {B_DEF_NAME} to your party?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Dynamax form!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Gigantamax form!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("Time to Dynamax!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("Time to Gigantamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("Would you like to give up on this battle and quit now? Quitting the battle is the same as losing the battle."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("You sense the presence of many!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into its Complete Forme!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Ability is protected by the effects of its {B_LAST_ITEM}!"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is too scared to move!"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("GHOST: Get out…… Get out……"),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("SILPH SCOPE unveiled the GHOST's\nidentity!"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("The GHOST was MAROWAK!\p"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{B_TRAINER1_NAME}: {B_OPPONENT_MON1_NAME}, come back!"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("{B_PLAYER_NAME} threw a ROCK\nat the {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("{B_PLAYER_NAME} threw some BAIT\nat the {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is angry!"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is eating!"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s disguise was busted!"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("{B_SCR_ABILITY} triggered!"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("{B_SCR_ABILITY} ended!"),
    [STRINGID_SCRCUREDPARALYSIS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was cured of paralysis!"),
    [STRINGID_SCRCUREDPOISON]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was cured of its poisoning!"),
    [STRINGID_SCRCUREDBURN]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s burn was cured!"),
    [STRINGID_SCRCUREDSLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_SCRCUREDCONFUSION]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} snapped out of its confusion!"),
    [STRINGID_PARTYCUREDPARALYSIS]                  = COMPOUND_STRING("{B_BUFF1} was cured of paralysis!"),
    [STRINGID_PARTYCUREDPOISON]                     = COMPOUND_STRING("{B_BUFF1} was cured of its poisoning!"),
    [STRINGID_PARTYCUREDBURN]                       = COMPOUND_STRING("{B_BUFF1}'s burn was cured!"),
    [STRINGID_PARTYCUREDSLEEP]                      = COMPOUND_STRING("{B_BUFF1} woke up!"),
    [STRINGID_PARTYCUREDFREEZE]                     = COMPOUND_STRING("{B_BUFF1} thawed out!"),
    [STRINGID_PARTYCUREDFROSTBITE]                  = COMPOUND_STRING("{B_BUFF1}'s frostbite was cured!"),
    [STRINGID_PKMNATKNOTLOWERED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Attack was not lowered!"),
    [STRINGID_VICTORYCATCH]                         = COMPOUND_STRING("{B_DEF_NAME} is weak!\nThrow a Poké Ball now!"),
    [STRINGID_CANTUSEMOVE]                          = COMPOUND_STRING("This move can't be used!\p"),
    [STRINGID_REFLECTWOREOFF]                       = COMPOUND_STRING("{B_DEF_TEAM1} side's Reflect wore off!"),
    [STRINGID_LIGHTSCREENWOREOFF]                   = COMPOUND_STRING("{B_DEF_TEAM1} side's Light Screen wore off!"),
    [STRINGID_AURORAVEILWOREOFF]                    = COMPOUND_STRING("{B_DEF_TEAM1} side's Aurora Veil wore off!"),
    [STRINGID_MOSTLYINEFFECTIVE]                    = COMPOUND_STRING("It's mostly ineffective…"),
    [STRINGID_EXTREMELYEFFECTIVE]                   = COMPOUND_STRING("It's extremely effective!"),
    [STRINGID_NOTVERYEFFECTIVEONDEF]                = COMPOUND_STRING("It's not very effective on {B_DEF_NAME_WITH_PREFIX2}."),
    [STRINGID_SUPEREFFECTIVEONDEF]                  = COMPOUND_STRING("It's super effective on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_MOSTLYINEFFECTIVEONDEF]               = COMPOUND_STRING("It's mostly ineffective on {B_DEF_NAME_WITH_PREFIX2}."),
    [STRINGID_EXTREMELYEFFECTIVEONDEF]              = COMPOUND_STRING("It's extremely effective on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EXTREMELYEFFECTIVETWOFOES]            = COMPOUND_STRING("It's extremely effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_MOSTLYINEFFECTIVETWOFOES]             = COMPOUND_STRING("It's mostly ineffective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}."),
    [STRINGID_CRITICALHITONDEF]                     = COMPOUND_STRING("A critical hit on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_S]                                    = COMPOUND_STRING("s"),
    [STRINGID_LOSTSOMEOFITSHP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lost some of its HP!"),
    [STRINGID_BELCHCANTUSE]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hasn't eaten any held Berries, so it can't possibly belch!\p"),
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gStartingStatusStringIds[B_MSG_STARTING_STATUS_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_SET_TRICK_ROOM]       = STRINGID_DIMENSIONSWERETWISTED,
    [B_MSG_SET_MAGIC_ROOM]       = STRINGID_BIZARREARENACREATED,
    [B_MSG_SET_WONDER_ROOM]      = STRINGID_BIZARREAREACREATED,
    [B_MSG_SET_TAILWIND]         = STRINGID_TAILWINDBLEW,
    [B_MSG_SET_RAINBOW]          = STRINGID_ARAINBOWAPPEAREDONSIDE,
    [B_MSG_SET_SEA_OF_FIRE]      = STRINGID_SEAOFFIREENVELOPEDSIDE,
    [B_MSG_SET_SWAMP]            = STRINGID_SWAMPENVELOPEDSIDE,
    [B_MSG_SET_SPIKES]           = STRINGID_SPIKESSCATTERED,
    [B_MSG_SET_POISON_SPIKES]    = STRINGID_POISONSPIKESSCATTERED,
    [B_MSG_SET_STICKY_WEB]       = STRINGID_STICKYWEBUSED,
    [B_MSG_SET_STEALTH_ROCK]     = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SET_SHARP_STEEL]      = STRINGID_SHARPSTEELFLOATS,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE,
    STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PKMNHEALEDPOISON,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
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
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u16 gAbilityWeatherChangeStringId[] =
{
    [B_MSG_STARTED_DRIZZLE]        = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_SAND_STREAM]    = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_DROUGHT]        = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL_WARNING]   = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW_WARNING]   = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_DESOLATE_LAND]  = STRINGID_EXTREMELYHARSHSUNLIGHT,
    [B_MSG_STARTED_PRIMORDIAL_SEA] = STRINGID_HEAVYRAIN,
    [B_MSG_STARTED_STRONG_WINDS]   = STRINGID_MYSTERIOUSAIRCURRENT,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN]                       = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SUN]                        = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_SANDSTORM]                  = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_HAIL]                       = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW]                       = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG]                        = STRINGID_FOGLIFTED,
    [B_MSG_WEATHER_END_EXTREMELY_HARSH_SUNLIGHT]   = STRINGID_EXTREMESUNLIGHTFADED,
    [B_MSG_WEATHER_END_HEAVY_RAIN]                 = STRINGID_HEAVYRAINLIFTED,
    [B_MSG_WEATHER_END_STRONG_WINDS]               = STRINGID_STRONGWINDSDISSIPATED,
};

const u16 gWeatherTurnStringIds[] =
{
    [B_MSG_WEATHER_TURN_RAIN]         = STRINGID_RAINCONTINUES,
    [B_MSG_WEATHER_TURN_DOWNPOUR]     = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_WEATHER_TURN_SUN]          = STRINGID_SUNLIGHTSTRONG,
    [B_MSG_WEATHER_TURN_SANDSTORM]    = STRINGID_SANDSTORMRAGES,
    [B_MSG_WEATHER_TURN_HAIL]         = STRINGID_HAILCONTINUES,
    [B_MSG_WEATHER_TURN_SNOW]         = STRINGID_SNOWCONTINUES,
    [B_MSG_WEATHER_TURN_FOG]          = STRINGID_FOGISDEEP,
    [B_MSG_WEATHER_TURN_STRONG_WINDS] = STRINGID_MYSTERIOUSAIRCURRENTBLOWSON,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gBrokeProtectionStringIds[] =
{
    [B_MSG_FEINT]                 = STRINGID_FELLFORFEINT,
    [B_MSG_BROKE_THROUGH_PROTECT] = STRINGID_BROKETHROUGHPROTECTION,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
    [B_MSG_SET_AURORA_VEIL]        = STRINGID_PKMNAURORAVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNAVOIDEDATTACK,
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

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_STAT_CHANGED]            = STRINGID_STATROSE,
    [B_MSG_STAT_WONT_CHANGE]        = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_MAXED]              = STRINGID_STATWASMAXEDOUT,
    [B_MSG_STAT_CHANGE_EMPTY]       = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]       = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_STAT_CHANGED_BELLY_DRUM] = STRINGID_PKMNCUTHPMAXEDATTACK,
    [B_MSG_USED_DIRE_HIT]           = STRINGID_PKMNUSEDXTOGETPUMPED,
};

// Mostly redundant, combine with above in a future pr
const u16 gStatDownStringIds[] =
{
    [B_MSG_STAT_CHANGED]            = STRINGID_STATFELL,
    [B_MSG_STAT_WONT_CHANGE]        = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_CHANGE_EMPTY]       = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]       = STRINGID_USINGITEMSTATOFPKMNFELL,
    [B_MSG_STAT_CHANGED_BELLY_DRUM] = STRINGID_PKMNCUTHPMAXEDATTACK, // Message for contrary is still printed
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
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

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNGOTFROSTBITE,
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_PKMNAVOIDEDATTACK,
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
    [WEATHER_SNOW]               = (B_OVERWORLD_SNOW >= GEN_9 ? STRINGID_ITISSNOWING : STRINGID_ITISHAILING),
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTISHARSH,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gTerrainStartsStringIds[] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_MISTSWIRLSAROUND,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_ELECTRICCURRENTISRUNNING,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_SEEMSWEIRD,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_ISCOVEREDWITHGRASS,
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariReactionStringIds[NUM_SAFARI_REACTIONS] =
{
    [B_MSG_MON_WATCHING] = STRINGID_PKMNWATCHINGCAREFULLY,
    [B_MSG_MON_ANGRY]    = STRINGID_PKMNANGRY,
    [B_MSG_MON_EATING]   = STRINGID_PKMNEATING
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

const u16 CureStatusBerryEffectStringID[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PKMNSITEMCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PKMNSITEMHEALEDBURN,
    [B_MSG_CURED_FREEZE] = STRINGID_PKMNSITEMDEFROSTEDIT,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNSITEMHEALEDFROSTBITE,
    [B_MSG_CURED_SLEEP] = STRINGID_PKMNSITEMWOKEIT,
    [B_MSG_CURED_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
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
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEITINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u16 gRemoveHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_SPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STICKY_WEB] = STRINGID_STICKYWEBDISAPPEAREDFROMTEAM,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STEALTH_ROCK] = STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM,
    [HAZARDS_STEELSURGE] = STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM,
};

const u16 gZenModeStringIds[] =
{
    [B_MSG_ZEN_MODE_TRIGGERED] = STRINGID_ZENMODETRIGGERED,
    [B_MSG_ZEN_MODE_ENDED] = STRINGID_ZENMODEENDED
};

const u16 gCureStatusStringIds[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_SCRCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_SCRCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_SCRCUREDBURN,
    [B_MSG_CURED_SLEEP] = STRINGID_SCRCUREDSLEEP,
    [B_MSG_CURED_FREEZE] = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_CURED_CONFUSION] = STRINGID_SCRCUREDCONFUSION,
    [B_MSG_CURED_INFATUATION] = STRINGID_PKMNGOTOVERITSINFATUATION,
    [B_MSG_CURED_TAUNT] = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gPartyCureStatusStringIds[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PARTYCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PARTYCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PARTYCUREDBURN,
    [B_MSG_CURED_SLEEP] = STRINGID_PARTYCUREDSLEEP,
    [B_MSG_CURED_FREEZE] = STRINGID_PARTYCUREDFREEZE,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PARTYCUREDFROSTBITE,
    [B_MSG_CURED_CONFUSION] = STRINGID_SCRCUREDCONFUSION,
    [B_MSG_CURED_INFATUATION] = STRINGID_PKMNGOTOVERITSINFATUATION,
    [B_MSG_CURED_TAUNT] = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gHurtByStringIds[] =
{
    [B_MSG_HURT] = STRINGID_PKMNWASHURT,
    [B_MSG_HURT_BY_ITEM] = STRINGID_PKMNHURTSWITH,
};

const u16 gBreakScreensStringIds[] =
{
    [B_MSG_BREAK_REFLECT] = STRINGID_REFLECTWOREOFF,
    [B_MSG_BREAK_LIGHT_SCREEN] = STRINGID_LIGHTSCREENWOREOFF,
    [B_MSG_BREAK_AURORA_VEIL] = STRINGID_AURORAVEILWOREOFF,
};

const u8 gText_PkmnIsEvolving[] = _("What?\n{STR_VAR_1} is evolving!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {STR_VAR_1}\nstopped evolving!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("What will\n{B_BUFF1} do?");
const u8 gText_WhatWillPkmnDo2[] = _("What will\n{B_PLAYER_NAME} do?");
const u8 gText_WhatWillWallyDo[] = _("What will\nWALLY do?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Link standby…");
const u8 gText_BattleMenu[] = _("Battle{CLEAR_TO 56}Bag\nPokémon{CLEAR_TO 56}Run");
const u8 gText_SafariZoneMenu[] = _("Ball{CLEAR_TO 56}{POKEBLOCK}\nGo Near{CLEAR_TO 56}Run");
const u8 gText_SafariZoneMenuFrlg[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}BALL{CLEAR_TO 56}BAIT\nROCK{CLEAR_TO 56}RUN");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TYPE/");
const u8 gText_MoveInterfacePPType[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Which move should\nbe forgotten?");
const u8 gText_BattleCatchOrNot[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Catch\nDon't catch");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Yes\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Switch\nwhich?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");
const u8 gText_SafariBalls[] = _("Safari Balls");
const u8 gText_SafariBallLeft[] = _("Left: $");
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
const u8 gText_BadEgg[] = _("Bad Egg");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Draw");
static const u8 sText_SpaceIs[] = _(" is");
static const u8 sText_ApostropheS[] = _("'s");
const u8 gText_BattleTourney[] = _("BATTLE TOURNEY");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = COMPOUND_STRING("Round 1"),
    [DOME_ROUND2]    = COMPOUND_STRING("Round 2"),
    [DOME_SEMIFINAL] = COMPOUND_STRING("Semifinal"),
    [DOME_FINAL]     = COMPOUND_STRING("Final"),
};

const u8 gText_TheGreatNewHope[] = _("The great new hope!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p");
const u8 gText_AFormerChampion[] = _("A former champion!\p");
const u8 gText_ThePreviousChampion[] = _("The previous champion!\p");
const u8 gText_TheUnbeatenChampion[] = _("The unbeaten champion!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mind");
const u8 gText_Skill[] = _("Skill");
const u8 gText_Body[] = _("Body");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_NAME_WITH_CLASS} sent out {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} sent out {B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("You are challenged by {B_TRAINER1_NAME_WITH_CLASS} and {B_TRAINER2_NAME_WITH_CLASS}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON2_NAME}! Go, {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutNGoZ[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON1_NAME}! Go, {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn1[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn2[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn1[] = _("{B_PARTNER_NAME_WITH_CLASS} withdrew {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn2[] = _("{B_PARTNER_NAME_WITH_CLASS} withdrew {B_PLAYER_MON2_NAME}!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = COMPOUND_STRING("REFEREE: If nothing is decided in 3 turns, we will go to judging!"),
    [B_MSG_REF_THATS_IT]           = COMPOUND_STRING("REFEREE: That's it! We will now go to judging to determine the winner!"),
    [B_MSG_REF_JUDGE_MIND]         = COMPOUND_STRING("REFEREE: Judging category 1, Mind! The POKéMON showing the most guts!\p"),
    [B_MSG_REF_JUDGE_SKILL]        = COMPOUND_STRING("REFEREE: Judging category 2, Skill! The POKéMON using moves the best!\p"),
    [B_MSG_REF_JUDGE_BODY]         = COMPOUND_STRING("REFEREE: Judging category 3, Body! The POKéMON with the most vitality!\p"),
    [B_MSG_REF_PLAYER_WON]         = COMPOUND_STRING("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}! The winner is {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p"),
    [B_MSG_REF_OPPONENT_WON]       = COMPOUND_STRING("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}! The winner is {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p"),
    [B_MSG_REF_DRAW]               = COMPOUND_STRING("REFEREE: Judgment: 3 to 3! We have a draw!\p"),
    [B_MSG_REF_COMMENCE_BATTLE]    = COMPOUND_STRING("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}! Commence battling!"),
};

static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_NAME_WITH_CLASS} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("You lost to {B_TRAINER1_NAME_WITH_CLASS}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("You battled to a draw against {B_TRAINER1_NAME_WITH_CLASS}!");
const u8 gText_RecordBattleToPass[] = _("Would you like to record your battle\non your Frontier Pass?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}'s battle result was recorded\non the Frontier Pass.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("You are challenged by {B_LINK_OPPONENT1_NAME}!\p");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("You are challenged by {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!\p");
static const u8 sText_Your1[] = _("Your");
static const u8 sText_Opposing1[] = _("The opposing");
static const u8 sText_Your2[] = _("your");
static const u8 sText_Opposing2[] = _("the opposing");
static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
    [B_CATCH_OR_NOT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_KantoTutorial[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_OAK_OLD_MAN] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
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
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena,
    [B_WIN_TYPE_KANTO_TUTORIAL] = sTextOnWindowsInfo_KantoTutorial,
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(enum StringID stringID, enum BattlerId battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

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
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    {
                        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                            stringPtr = sText_LinkTrainerWantsToBattle;
                        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                            stringPtr = sText_TwoTrainersWantToBattle;
                        else if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                            stringPtr = sText_LinkTrainerWantsToBattlePause;
                        else
                            stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    }
                    else
                    {
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                    }
                }
                else
                {
                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (IsGhostBattleWithoutScope())
                stringPtr = sText_GhostAppearedCantId;
            else if (gBattleTypeFlags & BATTLE_TYPE_GHOST)
                stringPtr = sText_TheGhostAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))))
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (IsOnPlayerSide(battler))
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetPartnerBattler(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI && (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK || gBattleTypeFlags & BATTLE_TYPE_LINK))
                {
                    if (BattlerIsPlayer(battler))
                        stringPtr = sText_LinkPartnerSentOutPkmn2GoPkmn; // Player is on left
                    else
                        stringPtr = sText_LinkPartnerSentOutPkmn1GoPkmn; // Link Partner on left
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                {
                    if (BattlerIsPlayer(battler) && (battler & BIT_FLANK) == B_FLANK_LEFT)
                        stringPtr = sText_InGamePartnerSentOutZGoN; // Player is on left
                    else
                        stringPtr = sText_InGamePartnerSentOutNGoZ; // Partner on left
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_RAID)
                {
                    stringPtr = sText_BeCarefulPkmn;
                }
                else
                {
                    stringPtr = sText_GoTwoPkmn;
                }
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetPartnerBattler(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if ((gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) || (gBattleTypeFlags & BATTLE_TYPE_MULTI && (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK || gBattleTypeFlags & BATTLE_TYPE_LINK)))
                    stringPtr = sText_TwoLinkTrainersIntroSendOutPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS || gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))) // Link Opponent doubles and test opponent
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler)))
            {
                if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerIntroSendOutPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1SentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if ((GetBattlerPosition(battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(battler) || BattlerIsWally(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerWithdrewPkmn1;
                else
                    stringPtr = sText_InGamePartnerWithdrewPkmn1;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent A and test opponent
            {
                stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerWithdrewPkmn2;
                else
                    stringPtr = sText_InGamePartnerWithdrewPkmn2;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (BattleSideHasTwoTrainers(B_SIDE_OPPONENT))
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if ((GetBattlerPosition(gBattleScripting.battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(gBattleScripting.battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerSentOutPkmn1;
                else
                    stringPtr = sText_InGamePartnerSentOutPkmn1;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent A and test opponent
            {
                stringPtr = sText_LinkTrainerSentOutPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(gBattleScripting.battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerSentOutPkmn2;
                else
                    stringPtr = sText_InGamePartnerSentOutPkmn2;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (BattleSideHasTwoTrainers(B_SIDE_OPPONENT))
                    stringPtr = sText_LinkTrainer2SentOutPkmn2;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2SentOutPkmn;
            }
            else // Single trainer double Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn2;
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
         && !IsZMove(gBattleMsgDataPtr->currentMove)
         && !IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, gTypesInfo[*(&gBattleStruct->stringMoveType)].generic);
        else
            StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(GetPartnerBattler(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
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
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(GetPartnerBattler(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
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
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
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
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= STRINGID_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
#ifndef NDEBUG
    u32 j, strWidth;
    u32 dstID = BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(0, gDisplayedStringBattle, 0, j, sizeof(gDisplayedStringBattle));
        if (strWidth == 0)
            break;
    }
    return dstID;
#else
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
#endif
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

static void GetBattlerNick(enum BattlerId battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetBattlerMon(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                            \
    if (!IsOnPlayerSide(battler))                                       \
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
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

#define HANDLE_NICKNAME_STRING_LOWERCASE(battler)                       \
    if (!IsOnPlayerSide(battler))                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefixLower;                           \
        else                                                            \
            toCpy = sText_WildPkmnPrefixLower;                          \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
    {
        GetTrainerTowerOpponentName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        enum TrainerClassID trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);

        if (trainerClass == TRAINER_CLASS_RIVAL_EARLY_FRLG || trainerClass == TRAINER_CLASS_RIVAL_LATE_FRLG || trainerClass == TRAINER_CLASS_CHAMPION_FRLG)
            toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
        else
            toCpy = GetTrainerNameFromId(trainerId);
    }

    assertf(DoesStringProperlyTerminate(toCpy, TRAINER_NAME_LENGTH + 1),"Opponent needs a valid name")
    {
        return sText_EmptyString4;
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClasses[GetSecretBaseTrainerClass()].name;
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClasses[GetUnionRoomTrainerClass()].name;
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClasses[GetFrontierBrainTrainerClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClasses[GetFrontierOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        toCpy = gTrainerClasses[GetTrainerTowerOpponentClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClasses[GetTrainerHillOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClasses[GetEreaderTrainerClassId()].name;
    else if (trainerId == TRAINER_LINK_OPPONENT)
        toCpy = gTrainerClasses[TRAINER_NONE].name;
    else
        toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 *textStart = &text[0];
    u8 multiplayerId;
    u8 fontId = FONT_NORMAL;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            u32 classLength = 0;
            u32 nameLength = 0;
            const u8 *classString;
            const u8 *nameString;
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
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(GetPartnerBattler(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_DEF_PARTNER_NAME: // partner target name
                GetBattlerNick(GetPartnerBattler(gBattlerTarget), text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
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
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerAttacker]].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerTarget]].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattleScripting.battler]].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gEffectBattler]].name;
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_TRAINER1_NAME_WITH_CLASS: // trainer1 name with trainer class
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(GetPartnerPosition(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(GetBattlerLeftFoe(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(GetBattlerRightFoe(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentA);
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
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerWonSpeech();
                }
                break;
            case B_TXT_26: // ?
                if (!IsOnPlayerSide(gBattleScripting.battler))
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                }
                GetMonData(&GetBattlerParty(gBattleScripting.battler)[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = IS_FRLG ? sText_Bills : sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentB);
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
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_PARTNER_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetPlayerName(textStart, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                default:
                    break;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME_WITH_CLASS:
                toCpy = textStart;
                if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                {
                    if (IS_FRLG)
                        textStart = StringCopy(textStart, COMPOUND_STRING("The old man"));
                    else
                        textStart = StringCopy(textStart, COMPOUND_STRING("WALLY"));
                }
                else if (GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT)
                {
                    textStart = StringCopy(textStart, BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker));
                }
                else
                {
                    classString = NULL;
                    switch (GetBattlerPosition(gBattlerAttacker))
                    {
                    case B_POSITION_PLAYER_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                            classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                        break;
                    case B_POSITION_OPPONENT_LEFT:
                        classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    case B_POSITION_OPPONENT_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                        else
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    default:
                        break;
                    }
                    classLength = 0;
                    nameLength = 0;
                    while (classString[classLength] != EOS)
                    {
                        textStart[classLength] = classString[classLength];
                        classLength++;
                    }
                    textStart[classLength] = CHAR_SPACE;
                    textStart += 1 + classLength;
                    nameString = BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker);
                    if (nameString != textStart)
                    {
                        while (nameString[nameLength] != EOS)
                        {
                            textStart[nameLength] = nameString[nameLength];
                            nameLength++;
                        }
                        textStart[nameLength] = EOS;
                    }
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_EFF_TEAM1:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_EFF_TEAM2:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerTarget)
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattleScripting.battler)
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    if (*toCpy == CHAR_SPACE)
                        dst[dstID] = CHAR_NBSP;
                    else
                        dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
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

    BreakStringAutomatic(dst, BATTLE_MSG_MAX_WIDTH, BATTLE_MSG_MAX_LINES, fontId, SHOW_SCROLL_PROMPT);

    return dstID;
}

static void IllusionNickHack(enum BattlerId battler, u32 partyId, u8 *dst)
{
    u32 id = PARTY_SIZE;
    struct Pokemon *party = GetBattlerParty(battler);
    struct Pokemon *mon = &party[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(GetPartnerBattler(battler)))
            partnerMon = GetBattlerMon(GetPartnerBattler(battler));
        else
            partnerMon = mon;

        id = GetIllusionMonPartyId(party, mon, partnerMon, battler);
    }

    if (id != PARTY_SIZE)
        GetMonData(&party[id], MON_DATA_NICKNAME, dst);
    else
        GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
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
            StringAppend(dst, gBattleStringsTable[hword]);
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
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (!IsOnPlayerSide(src[srcID + 1]))
            {
                if (src[srcID] == B_BUFF_MON_NICK_WITH_PREFIX_LOWER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefixLower);
                    else
                        StringAppend(dst, sText_WildPkmnPrefixLower);
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefix);
                    else
                        StringAppend(dst, sText_WildPkmnPrefix);
                }
            }
            GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
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
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.color = textInfo[windowId].color;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        // We cannot check the actual width of the window because
        // B_WIN_MOVE_NAME_1 and B_WIN_MOVE_NAME_3 are 16 wide for
        // Z-move details.
        if (gBattleStruct->zmove.viewing && windowId == B_WIN_MOVE_NAME_1)
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 16 * TILE_WIDTH);
        else
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * TILE_WIDTH);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled || ((gBattleTypeFlags & BATTLE_TYPE_POKEDUDE) && windowId != B_WIN_OAK_OLD_MAN))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
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

void SetPPNumbersPaletteInMoveSelection(enum BattlerId battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPPToMaxPPState(chooseMoveStruct->currentPP[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPP[gMoveSelectionCursor[battler]]);
    else
        var = 3;

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPPToMaxPPState(u8 currentPP, u8 maxPP)
{
    if (maxPP == currentPP)
    {
        return 3;
    }
    else if (maxPP <= 2)
    {
        if (currentPP > 1)
            return 3;
        else
            return 2 - currentPP;
    }
    else if (maxPP <= 7)
    {
        if (currentPP > 2)
            return 3;
        else
            return 2 - currentPP;
    }
    else
    {
        if (currentPP == 0)
            return 2;
        if (currentPP <= maxPP / 4)
            return 1;
        if (currentPP > maxPP / 2)
            return 3;
    }

    return 0;
}

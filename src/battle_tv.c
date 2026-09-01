#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_stat_change.h"
#include "battle_tv.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_anim.h"
#include "constants/moves.h"
#include "battle_message.h"
#include "battle_anim_scripts.h"
#include "tv.h"
#include "constants/battle_move_effects.h"

// this file's functions
static bool8 IsNotSpecialBattleString(enum StringID stringId);
static void AddMovePoints(u8 caseId, u16 arg1, u8 arg2, u8 arg3);
static void TrySetBattleSeminarShow(void);
static void AddPointsOnFainting(void);
static void AddPointsBasedOnWeather(u16 weatherFlags, enum Move move, u8 moveSlot);
static bool8 ShouldCalculateDamage(enum Move move, s32 *dmg, u16 *powerOverride);
static u32 GetTvPartyIndex(u32 battler);

#define TABLE_END ((u16)-1)

enum {
    PTS_MOVE_EFFECT,
    PTS_EFFECTIVENESS,
    PTS_SET_UP, // Broadly. Used by Wish, Future Sight, Ingrain, etc.
    PTS_RAIN,
    PTS_SUN,
    PTS_SANDSTORM,
    PTS_HAIL_SNOW,
    PTS_ELECTRIC,
    PTS_STATUS_DMG,
    PTS_STATUS_SKIP_TURN,
    PTS_SPIKES,
    PTS_WATER_SPORT,
    PTS_MUD_SPORT,
    PTS_REFLECT,
    PTS_LIGHT_SCREEN,
    PTS_SAFEGUARD,
    PTS_MIST,
    PTS_BREAK_WALL,
    PTS_CRITICAL_HIT,
    PTS_FAINT,
    PTS_FAINT_SET_UP,
    PTS_FLINCHED,
    PTS_STAT_INCREASE_1,
    PTS_STAT_INCREASE_2,
    PTS_STAT_INCREASE_3,
    PTS_STAT_DECREASE_SELF,
    PTS_STAT_DECREASE_1,
    PTS_STAT_DECREASE_2,
    PTS_STAT_DECREASE_3,
    PTS_STAT_INCREASE_NOT_SELF,
};

enum {
    FNT_NONE,
    FNT_CURSE,
    FNT_LEECH_SEED,
    FNT_POISON,
    FNT_BURN,
    FNT_NIGHTMARE,
    FNT_WRAP,
    FNT_SPIKES,
    FNT_FUTURE_SIGHT,
    FNT_DOOM_DESIRE,
    FNT_PERISH_SONG,
    FNT_DESTINY_BOND,
    FNT_CONFUSION,
    FNT_EXPLOSION,
    FNT_RECOIL,
    FNT_OTHER,
};

// const rom data
static const u16 sVariableDmgMoves[] =
{
    MOVE_COUNTER, MOVE_FISSURE, MOVE_BIDE, MOVE_MIRROR_COAT,
    MOVE_HORN_DRILL, MOVE_FLAIL, MOVE_REVERSAL, MOVE_HIDDEN_POWER,
    MOVE_SHEER_COLD, MOVE_FOCUS_PUNCH, MOVE_ERUPTION,
    MOVE_WATER_SPOUT, MOVE_DREAM_EATER, MOVE_WEATHER_BALL,
    MOVE_SNORE, MOVE_PAIN_SPLIT, MOVE_GUILLOTINE,
    MOVE_FRUSTRATION, MOVE_RETURN, MOVE_ENDEAVOR,
    MOVE_PRESENT, MOVE_REVENGE, TABLE_END,
    // those are handled by the function itself
    MOVE_MAGNITUDE, MOVE_PSYWAVE, TABLE_END
};

static const u16 sPoints_Effectiveness[] =
{
    4,  // Super Effective
    -3, // Not Very Effective
    -6  // No Effect
};
static const u16 sPoints_SetUp[] =
{
    4, // Future Sight
    4, // Doom Desire
    6,
    6, // Wish
    7, // Grudge
    6,
    2  // Ingrain
};
static const u16 sPoints_StatusDmg[] =
{
    5, // Curse
    3, // Leech Seed
    3, // Poison
    3, // Toxic
    3, // Burn
    3, // Nightmare
    3  // Wrap (Trapping move)
};

static const u16 *const sPointsArray[] =
{
    [PTS_EFFECTIVENESS]          = sPoints_Effectiveness,
    [PTS_SET_UP]                 = sPoints_SetUp,
    [PTS_STATUS_DMG]             = sPoints_StatusDmg,
};

// Points will always be calculated for these messages
// even if current Pokémon does not have corresponding move
static const u16 sSpecialBattleStrings[] =
{
    STRINGID_PKMNPERISHCOUNTFELL,
    STRINGID_PKMNWISHCAMETRUE,
    STRINGID_PKMNLOSTPPGRUDGE,
    STRINGID_PKMNTOOKFOE,
    STRINGID_PKMNABSORBEDNUTRIENTS,
    STRINGID_PKMNANCHOREDITSELF,
    STRINGID_PKMNAFFLICTEDBYCURSE,
    STRINGID_PKMNSAPPEDBYLEECHSEED,
    STRINGID_PKMNLOCKEDINNIGHTMARE,
    STRINGID_PKMNHURTBY,
    STRINGID_PKMNHURTBYBURN,
    STRINGID_PKMNHURTBYPOISON,
    STRINGID_PKMNHURTBYSPIKES,
    STRINGID_BATTLERFAINTED,
    STRINGID_PKMNHITWITHRECOIL,
    STRINGID_PKMNCRASHED,
    TABLE_END
};

// code
void BattleTv_SetDataBasedOnString(enum StringID stringId)
{
    struct BattleTv *tvPtr;
    u32 atkSide, defSide, effSide, scriptingSide;
    struct Pokemon *atkMon, *defMon;
    u8 moveSlot;
    u32 atkFlank, defFlank, effFlank, flank;
    u8 *perishCount;
    u16 *statStringId, *finishedMoveId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK)
     && stringId != STRINGID_ITDOESNTAFFECT
     && stringId != STRINGID_NOTVERYEFFECTIVE
     && stringId != STRINGID_MOSTLYINEFFECTIVE)
        return;

    tvPtr = &gBattleStruct->tv;

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    effSide = GetBattlerSide(gEffectBattler);
    scriptingSide = GetBattlerSide(gBattleMsgDataPtr->scrActive);
    atkMon = GetBattlerMon(gBattlerAttacker);
    defMon = GetBattlerMon(gBattlerTarget);
    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, gBattleMsgDataPtr->currentMove);

    if (moveSlot >= MAX_MON_MOVES && IsNotSpecialBattleString(stringId) && stringId > STRINGID_TABLE_START)
    {
        tvPtr->side[atkSide].faintCause = FNT_OTHER;
        return;
    }

    perishCount = (u8 *)(gBattleTextBuff1 + 4);
    statStringId = (u16 *)(gBattleTextBuff2 + 2);
    finishedMoveId = (u16 *)(gBattleTextBuff1 + 2);

    atkFlank = GetBattlerPosition(gBattlerAttacker) / 2;
    defFlank = GetBattlerPosition(gBattlerTarget) / 2;
    effFlank = GetBattlerPosition(gEffectBattler) / 2;

    switch (stringId)
    {
    case STRINGID_ITDOESNTAFFECT:
        AddMovePoints(PTS_EFFECTIVENESS, moveSlot, 2, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
            TrySetBattleSeminarShow();
        break;
    case STRINGID_NOTVERYEFFECTIVE:
    case STRINGID_NOTVERYEFFECTIVETWOFOES:
    case STRINGID_MOSTLYINEFFECTIVE:
    case STRINGID_MOSTLYINEFFECTIVETWOFOES:
        AddMovePoints(PTS_EFFECTIVENESS, moveSlot, 1, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && GetMonData(defMon, MON_DATA_HP) != 0)
            TrySetBattleSeminarShow();
        break;
    case STRINGID_SUPEREFFECTIVE:
    case STRINGID_SUPEREFFECTIVETWOFOES:
    case STRINGID_EXTREMELYEFFECTIVE:
    case STRINGID_EXTREMELYEFFECTIVETWOFOES:
        AddMovePoints(PTS_EFFECTIVENESS, moveSlot, 0, 0);
        break;
    case STRINGID_PKMNFORESAWATTACK:
        tvPtr->side[atkSide].futureSightMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].futureSightMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNCHOSEXASDESTINY:
        tvPtr->side[atkSide].doomDesireMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].doomDesireMoveSlot = moveSlot;
        break;
    case STRINGID_FAINTINTHREE:
        tvPtr->side[atkSide].perishSongMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].perishSongMoveSlot = moveSlot;
        tvPtr->side[atkSide].perishSong = 1;
        break;
    case STRINGID_PKMNPERISHCOUNTFELL:
        if (*perishCount == 0)
            tvPtr->side[atkSide].faintCause = FNT_PERISH_SONG;
        break;
    case STRINGID_PKMNWISHCAMETRUE:
        if (tvPtr->side[defSide].wishMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 3, defSide,
            (tvPtr->side[defSide].wishMonId - 1) * 4 + tvPtr->side[defSide].wishMoveSlot);
        }
        break;
    case STRINGID_PKMNWANTSGRUDGE:
        tvPtr->side[atkSide].grudgeMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].grudgeMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOSTPPGRUDGE:
        if (tvPtr->side[defSide].grudgeMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 4, defSide,
            (tvPtr->side[defSide].grudgeMonId - 1) * 4 + tvPtr->side[defSide].grudgeMoveSlot);
        }
        break;
    case STRINGID_PKMNTRYINGTOTAKEFOE:
        tvPtr->side[atkSide].destinyBondMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].destinyBondMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNTOOKFOE:
        if (tvPtr->side[defSide].destinyBondMonId != 0)
            tvPtr->side[atkSide].faintCause = FNT_DESTINY_BOND;
        break;
    case STRINGID_PKMNPLANTEDROOTS:
        tvPtr->pos[atkSide][atkFlank].ingrainMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[atkSide][atkFlank].ingrainMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNABSORBEDNUTRIENTS:
        if (tvPtr->pos[atkSide][atkFlank].ingrainMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 6, atkSide,
            (tvPtr->pos[atkSide][atkFlank].ingrainMonId - 1) * 4 + tvPtr->pos[atkSide][atkFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNANCHOREDITSELF:
        if (tvPtr->pos[defSide][defFlank].ingrainMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 6, defSide,
            (tvPtr->pos[defSide][defFlank].ingrainMonId - 1) * 4 + tvPtr->pos[defSide][defFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNTRANSFORMEDINTO:
        gBattleStruct->anyMonHasTransformed = TRUE;
        break;
    case STRINGID_CRITICALHIT:
    case STRINGID_CRITICALHITONDEF:
        AddMovePoints(PTS_CRITICAL_HIT, moveSlot, 0, 0);
        break;
    case STRINGID_STATROSE:
        if (gBattleTextBuff1[2] != 0)
        {
            if (gBattlerAttacker == gBattlerTarget)
            {
                if (*statStringId == STRINGID_DRASTICALLY)
                    AddMovePoints(PTS_STAT_INCREASE_3, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else if (*statStringId == STRINGID_STATSHARPLY)
                    AddMovePoints(PTS_STAT_INCREASE_2, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else
                    AddMovePoints(PTS_STAT_INCREASE_1, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
            else
            {
                AddMovePoints(PTS_STAT_INCREASE_NOT_SELF, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
        }
        break;
    case STRINGID_STATFELL:
        if (gBattleTextBuff1[2] != 0)
        {
            if (gBattlerAttacker != gBattlerTarget)
            {
                if (*statStringId == STRINGID_SEVERELY)
                    AddMovePoints(PTS_STAT_DECREASE_3, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else if (*statStringId == STRINGID_STATHARSHLY)
                    AddMovePoints(PTS_STAT_DECREASE_2, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else
                    AddMovePoints(PTS_STAT_DECREASE_1, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
            else
            {
                AddMovePoints(PTS_STAT_DECREASE_SELF, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
        }
        break;
    case STRINGID_PKMNLAIDCURSE:
        tvPtr->pos[defSide][defFlank].curseMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[defSide][defFlank].curseMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNAFFLICTEDBYCURSE:
        if (GetMonData(atkMon, MON_DATA_HP)
            && tvPtr->pos[atkSide][atkFlank].curseMonId != 0)
        {
            AddMovePoints(PTS_STATUS_DMG, 0, tvPtr->pos[atkSide][atkFlank].curseMonId - 1, tvPtr->pos[atkSide][atkFlank].curseMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_CURSE;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNSEEDED:
        tvPtr->pos[defSide][defFlank].leechSeedMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[defSide][defFlank].leechSeedMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNSAPPEDBYLEECHSEED:
        if (tvPtr->pos[atkSide][atkFlank].leechSeedMonId != 0)
        {
            AddMovePoints(PTS_STATUS_DMG, 1, tvPtr->pos[atkSide][atkFlank].leechSeedMonId - 1, tvPtr->pos[atkSide][atkFlank].leechSeedMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_LEECH_SEED;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNFELLINTONIGHTMARE:
        tvPtr->pos[defSide][defFlank].nightmareMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[defSide][defFlank].nightmareMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOCKEDINNIGHTMARE:
        if (GetMonData(atkMon, MON_DATA_HP) != 0
            && tvPtr->pos[atkSide][atkFlank].nightmareMonId != 0)
        {
            AddMovePoints(PTS_STATUS_DMG, 5, tvPtr->pos[atkSide][atkFlank].nightmareMonId - 1, tvPtr->pos[atkSide][atkFlank].nightmareMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_NIGHTMARE;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNSQUEEZEDBYBIND:
    case STRINGID_PKMNTRAPPEDINVORTEX:
    case STRINGID_PKMNWRAPPEDBY:
    case STRINGID_PKMNCLAMPED:
    case STRINGID_PKMNTRAPPEDBYSANDTOMB:
        tvPtr->pos[defSide][defFlank].wrapMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[defSide][defFlank].wrapMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBY:
        if (GetMonData(atkMon, MON_DATA_HP) != 0
            && tvPtr->pos[atkSide][atkFlank].wrapMonId != 0)
        {
            AddMovePoints(PTS_STATUS_DMG, 6, tvPtr->pos[atkSide][atkFlank].wrapMonId - 1, tvPtr->pos[atkSide][atkFlank].wrapMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_WRAP;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNWASBURNED:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].brnMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].brnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYBURN:
        if (GetMonData(atkMon, MON_DATA_HP) != 0)
        {
            if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].brnMonId != 0)
                AddMovePoints(PTS_STATUS_DMG, 4, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].brnMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].brnMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_BURN;
            tvPtr->side[atkSide].faintCauseMonId = GetTvPartyIndex(gBattlerAttacker);
        }
        break;
    case STRINGID_PKMNWASPOISONED:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].psnMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].psnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNBADLYPOISONED:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].badPsnMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].badPsnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYPOISON:
        if (GetMonData(atkMon, MON_DATA_HP) != 0)
        {
            if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].psnMonId != 0)
                AddMovePoints(PTS_STATUS_DMG, 2, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].psnMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].psnMoveSlot);
            if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].badPsnMonId != 0)
                AddMovePoints(PTS_STATUS_DMG, 3, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].badPsnMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].badPsnMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_POISON;
            tvPtr->side[atkSide].faintCauseMonId = GetTvPartyIndex(gBattlerAttacker);
        }
        break;
    case STRINGID_PKMNFELLINLOVE:
        tvPtr->pos[defSide][defFlank].attractMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[defSide][defFlank].attractMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNIMMOBILIZEDBYLOVE:
        if (tvPtr->pos[atkSide][atkFlank].attractMonId != 0)
            AddMovePoints(PTS_STATUS_SKIP_TURN, 0, tvPtr->pos[atkSide][atkFlank].attractMonId - 1, tvPtr->pos[atkSide][atkFlank].attractMoveSlot);
        break;
    case STRINGID_PKMNWASPARALYZED:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].prlzMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].prlzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISPARALYZED:
        if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].prlzMonId != 0)
            AddMovePoints(PTS_STATUS_SKIP_TURN, 2, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].prlzMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].prlzMoveSlot);
        break;
    case STRINGID_PKMNFELLASLEEP:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].slpMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].slpMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNFASTASLEEP:
        if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].slpMonId != 0
            && GetMoveEffect(gBattleMsgDataPtr->currentMove) != EFFECT_SNORE
            && GetMoveEffect(gBattleMsgDataPtr->currentMove) != EFFECT_SLEEP_TALK)
            AddMovePoints(PTS_STATUS_SKIP_TURN, 3, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].slpMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].slpMoveSlot);
        break;
    case STRINGID_PKMNWASFROZEN:
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].frzMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->mon[effSide][GetTvPartyIndex(gEffectBattler)].frzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISFROZEN:
        if (tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].frzMonId != 0)
            AddMovePoints(PTS_STATUS_SKIP_TURN, 4, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].frzMonId - 1, tvPtr->mon[atkSide][GetTvPartyIndex(gBattlerAttacker)].frzMoveSlot);
        break;
    case STRINGID_PKMNWASCONFUSED:
        tvPtr->pos[effSide][effFlank].confusionMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[effSide][effFlank].confusionMoveSlot = moveSlot;
        break;
    case STRINGID_ITHURTCONFUSION:
        if (tvPtr->pos[atkSide][atkFlank].confusionMonId != 0)
            AddMovePoints(PTS_STATUS_SKIP_TURN, 1, tvPtr->pos[atkSide][atkFlank].confusionMonId - 1, tvPtr->pos[atkSide][atkFlank].confusionMoveSlot);
        tvPtr->side[atkSide].faintCause = FNT_CONFUSION;
        break;
    case STRINGID_SPIKESSCATTERED:
        tvPtr->side[defSide].spikesMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[defSide].spikesMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYSPIKES:
        if (tvPtr->side[scriptingSide].spikesMonId != 0)
        {
            AddMovePoints(PTS_SPIKES, scriptingSide ^ BIT_SIDE, tvPtr->side[scriptingSide].spikesMonId - 1, tvPtr->side[scriptingSide].spikesMoveSlot);
            tvPtr->side[scriptingSide].faintCause = FNT_SPIKES;
        }
        break;
    case STRINGID_PKMNBLEWAWAYSPIKES:
        tvPtr->side[atkSide].spikesMonId = 0;
        tvPtr->side[atkSide].spikesMoveSlot = 0;
        break;
    case STRINGID_FIREWEAKENED:
        tvPtr->pos[atkSide][atkFlank].waterSportMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[atkSide][atkFlank].waterSportMoveSlot = moveSlot;
        break;
    case STRINGID_ELECTRICITYWEAKENED:
        tvPtr->pos[atkSide][atkFlank].mudSportMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->pos[atkSide][atkFlank].mudSportMoveSlot = moveSlot;
        break;
    case STRINGID_RETURNMON:
        if (tvPtr->pos[atkSide][atkFlank].waterSportMonId != 0)
        {
            tvPtr->pos[atkSide][atkFlank].waterSportMonId = 0;
            tvPtr->pos[atkSide][atkFlank].waterSportMoveSlot = 0;
        }
        if (tvPtr->pos[atkSide][atkFlank].mudSportMonId != 0)
        {
            tvPtr->pos[atkSide][atkFlank].mudSportMonId = 0;
            tvPtr->pos[atkSide][atkFlank].mudSportMoveSlot = 0;
        }
        break;
    case STRINGID_BATTLERFAINTED:
        AddPointsOnFainting();
        if (gBattlerAttacker == gBattleScripting.battler)
            flank = atkFlank;
        else
            flank = defFlank;

        if (tvPtr->pos[atkSide][flank].waterSportMonId != 0)
        {
            tvPtr->pos[atkSide][flank].waterSportMonId = 0;
            tvPtr->pos[atkSide][flank].waterSportMoveSlot = 0;
        }
        if (tvPtr->pos[atkSide][flank].mudSportMonId != 0)
        {
            tvPtr->pos[atkSide][flank].mudSportMonId = 0;
            tvPtr->pos[atkSide][flank].mudSportMoveSlot = 0;
        }
        break;
    case STRINGID_PKMNRAISEDDEF:
        tvPtr->side[atkSide].reflectMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].reflectMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNRAISEDSPDEF:
        tvPtr->side[atkSide].lightScreenMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].lightScreenMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNSXWOREOFF:
        if (*finishedMoveId == MOVE_REFLECT)
        {
            tvPtr->side[atkSide].reflectMonId = 0;
            tvPtr->side[atkSide].reflectMoveSlot = 0;
        }
        if (*finishedMoveId == MOVE_LIGHT_SCREEN)
        {
            tvPtr->side[atkSide].lightScreenMonId = 0;
            tvPtr->side[atkSide].lightScreenMoveSlot = 0;
        }
        if (*finishedMoveId == MOVE_MIST)
        {
            tvPtr->side[atkSide].mistMonId = 0;
            tvPtr->side[atkSide].mistMoveSlot = 0;
        }
        break;
    case STRINGID_PKMNCOVEREDBYVEIL:
        tvPtr->side[atkSide].safeguardMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].safeguardMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNUSEDSAFEGUARD:
        if (tvPtr->side[defSide].safeguardMonId != 0)
            AddMovePoints(PTS_SAFEGUARD, 0, tvPtr->side[defSide].safeguardMonId - 1, tvPtr->side[defSide].safeguardMoveSlot);
        break;
    case STRINGID_PKMNSAFEGUARDEXPIRED:
        tvPtr->side[atkSide].safeguardMonId = 0;
        tvPtr->side[atkSide].safeguardMoveSlot = 0;
        break;
    case STRINGID_PKMNSHROUDEDINMIST:
        tvPtr->side[atkSide].mistMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].mistMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNPROTECTEDBYMIST:
        if (tvPtr->side[defSide].mistMonId != 0)
            AddMovePoints(PTS_MIST, 0, tvPtr->side[defSide].mistMonId - 1, tvPtr->side[defSide].mistMoveSlot);
        break;
    case STRINGID_THEWALLSHATTERED:
        tvPtr->side[defSide].reflectMonId = 0;
        tvPtr->side[defSide].reflectMoveSlot = 0;
        tvPtr->side[defSide].lightScreenMonId = 0;
        tvPtr->side[defSide].lightScreenMoveSlot = 0;
        AddMovePoints(PTS_BREAK_WALL, 0, GetTvPartyIndex(gBattlerAttacker), moveSlot);
        break;
    case STRINGID_PKMNFLINCHED:
        if (tvPtr->pos[atkSide][0].attackedByMonId != 0)
            AddMovePoints(PTS_FLINCHED, 0, tvPtr->pos[atkSide][0].attackedByMonId - 1, tvPtr->pos[atkSide][0].attackedByMoveSlot);
        if (tvPtr->pos[atkSide][1].attackedByMonId != 0)
            AddMovePoints(PTS_FLINCHED, 0, tvPtr->pos[atkSide][1].attackedByMonId - 1, tvPtr->pos[atkSide][1].attackedByMoveSlot);
        break;
    case STRINGID_PKMNCRASHED:
    case STRINGID_PKMNHITWITHRECOIL:
        tvPtr->side[atkSide].faintCause = FNT_RECOIL;
        break;
    default:
        break;
    }
}

static bool8 IsNotSpecialBattleString(enum StringID stringId)
{
    s32 i = 0;

    do
    {
        if (sSpecialBattleStrings[i] == stringId)
            break;
        i++;
    } while (sSpecialBattleStrings[i] != TABLE_END);

    if (sSpecialBattleStrings[i] == TABLE_END)
        return TRUE;
    else
        return FALSE;
}

void BattleTv_SetDataBasedOnMove(enum Move move, u16 weatherFlags)
{
    struct BattleTv *tvPtr;
    u32 atkSide, defSide;
    u8 moveSlot;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    tvPtr = &gBattleStruct->tv;

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, move);

    if (moveSlot >= MAX_MON_MOVES)
    {
        tvPtr->side[atkSide].faintCause = FNT_OTHER;
        return;
    }

    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMoveSlot = moveSlot;
    tvPtr->side[atkSide].usedMoveSlot = moveSlot;
    AddMovePoints(PTS_MOVE_EFFECT, moveSlot, move, 0);
    AddPointsBasedOnWeather(weatherFlags, move, moveSlot);
    if (gBattleMons[gBattlerAttacker].volatiles.chargeTimer > 0)
        AddMovePoints(PTS_ELECTRIC, move, moveSlot, 0);

    if (move == MOVE_WISH)
    {
        tvPtr->side[atkSide].wishMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide].wishMoveSlot = moveSlot;
    }

    if (IsExplosionMove(move))
    {
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId = GetTvPartyIndex(gBattlerAttacker) + 1;
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot = moveSlot;
        tvPtr->side[atkSide ^ BIT_SIDE].faintCause = FNT_EXPLOSION;
        tvPtr->side[atkSide ^ BIT_SIDE].explosion = TRUE;
    }

    u32 movePower = GetMovePower(move);
    AddMovePoints(PTS_REFLECT,      move, movePower, 0);
    AddMovePoints(PTS_LIGHT_SCREEN, move, movePower, 0);
    AddMovePoints(PTS_WATER_SPORT,  move, 0,         0);
    AddMovePoints(PTS_MUD_SPORT,    move, 0,         0);
}

void BattleTv_SetDataBasedOnAnimation(u8 animationId)
{
    struct BattleTv *tvPtr;
    u32 atkSide;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    tvPtr = &gBattleStruct->tv;
    atkSide = GetBattlerSide(gBattlerAttacker);
    if (GetMoveAnimationScript(gCurrentMove) == gBattleAnimMove_FutureSight)
    {
        if (tvPtr->side[atkSide].futureSightMonId != 0 && gBattleScripting.animTurn > 0)
        {
            AddMovePoints(PTS_SET_UP, 0, atkSide,
                        (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_FUTURE_SIGHT;
        }
    }
    else if (GetMoveAnimationScript(gCurrentMove) == gBattleAnimMove_DoomDesire)
    {
        if (tvPtr->side[atkSide].doomDesireMonId != 0 && gBattleScripting.animTurn > 0)
        {
            AddMovePoints(PTS_SET_UP, 1, atkSide,
                        (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_DOOM_DESIRE;
        }
    }
}

// Helper following 4-party split in link multis
static struct Pokemon *GetTvPartyMon(u32 scoreIndex, u32 side)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_MULTI) && scoreIndex >= MULTI_PARTY_SIZE)
    {
        enum BattleTrainer trainer = (side == B_SIDE_PLAYER) ? B_TRAINER_PARTNER : B_TRAINER_OPPONENT_B;
        return &gParties[trainer][scoreIndex - MULTI_PARTY_SIZE];
    }
    else
    {
        enum BattleTrainer trainer = (side == B_SIDE_PLAYER) ? B_TRAINER_PLAYER : B_TRAINER_OPPONENT_A;
        return &gParties[trainer][scoreIndex];
    }
}

void TryPutLinkBattleTvShowOnAir(void)
{
    enum Species playerBestSpecies = 0, opponentBestSpecies = 0;
    s16 playerBestSum = 0, opponentBestSum = SHRT_MAX;
    u8 playerBestMonId = 0, opponentBestMonId = 0;
    struct BattleTvMovePoints *movePoints = NULL;
    u8 countPlayer = 0, countOpponent = 0;
    s16 sum = 0;
    enum Species species = SPECIES_NONE;
    enum Move move = MOVE_NONE;
    s32 i, j;
    int zero = 0, one = 1; //needed for matching

    if (gBattleStruct->anyMonHasTransformed)
        return;

    movePoints = &gBattleStruct->tvMovePoints;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE)
            countPlayer++;
        if (GetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_SPECIES) != SPECIES_NONE)
            countOpponent++;
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (GetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_SPECIES) != SPECIES_NONE)
                countPlayer++;
            if (GetMonData(&gParties[B_TRAINER_OPPONENT_B][i], MON_DATA_SPECIES) != SPECIES_NONE)
                countOpponent++;
        }
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) || countPlayer != countOpponent)
        return;

    // Find the best mon on each side by total move points.
    // Score indices 0-5 map to mons: in multi battles, 0-2 are the front
    // trainer's mons and 3-5 are the flank trainer's mons on each side.
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon;

        mon = GetTvPartyMon(i, B_SIDE_PLAYER);
        species = GetMonData(mon, MON_DATA_SPECIES);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            for (sum = 0, j = 0; j < MAX_MON_MOVES; j++)
                sum += movePoints->points[zero][i * 4 + j];

            if (playerBestSum < sum)
            {
                playerBestMonId = i;
                playerBestSum = sum;
                playerBestSpecies = species;
            }
        }

        mon = GetTvPartyMon(i, B_SIDE_OPPONENT);
        species = GetMonData(mon, MON_DATA_SPECIES);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            for (sum = 0, j = 0; j < MAX_MON_MOVES; j++)
                sum += movePoints->points[one][i * 4 + j];

            if (opponentBestSum == sum)
            {
                if (GetMonData(mon, MON_DATA_EXP) > GetMonData(GetTvPartyMon(opponentBestMonId, B_SIDE_OPPONENT), MON_DATA_EXP))
                {
                    opponentBestMonId = i;
                    opponentBestSum = sum;
                    opponentBestSpecies = species;
                }
            }
            else if (opponentBestSum > sum)
            {
                opponentBestMonId = i;
                opponentBestSum = sum;
                opponentBestSpecies = species;
            }
        }
    }

    for (sum = 0, i = 0, j = 0; j < MAX_MON_MOVES; j++)
    {
        if (sum < movePoints->points[zero][playerBestMonId * 4 + j])
        {
            sum = movePoints->points[zero][playerBestMonId * 4 + j];
            i = j;
        }
    }

    move = GetMonData(GetTvPartyMon(playerBestMonId, B_SIDE_PLAYER), MON_DATA_MOVE1 + i);
    if (playerBestSum == 0 || move == MOVE_NONE)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        // Only put on air if the best player-side mon was the local player's.
        // Score indices 0-2 belong to the front battler, 3-5 to the flank battler.
        // Check whether the local player's scoring range matches the best mon.
        if ((playerBestMonId < MULTI_PARTY_SIZE && !GetLinkTrainerFlankId(gBattleScripting.multiplayerId))
         || (playerBestMonId >= MULTI_PARTY_SIZE && GetLinkTrainerFlankId(gBattleScripting.multiplayerId)))
        {
            j = (opponentBestMonId < MULTI_PARTY_SIZE) ? FALSE : TRUE;
            PutBattleUpdateOnTheAir(GetOpposingLinkMultiBattlerId(j, gBattleScripting.multiplayerId), move, playerBestSpecies, opponentBestSpecies);
        }
    }
    else
    {
        PutBattleUpdateOnTheAir(gBattleScripting.multiplayerId ^ 1, move, playerBestSpecies, opponentBestSpecies);
    }
}

static void AddMovePoints(u8 caseId, u16 arg1, u8 arg2, u8 arg3)
{
    struct BattleTvMovePoints *movePoints = &gBattleStruct->tvMovePoints;
    struct BattleTv *tvPtr = &gBattleStruct->tv;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    s32 i;

    switch (caseId)
    {
#define move arg2
    case PTS_MOVE_EFFECT: // arg1 -> move slot, arg2 -> move
    {
        enum BattleMoveEffects effect = GetMoveEffect(move);
        u8 baseFromEffect = gBattleMoveEffects[effect].battleTvScore;

        // Changes depending on the effect
        switch (effect)
        {
        case EFFECT_FIXED_HP_DAMAGE:
            baseFromEffect *= (GetMoveFixedHPDamage(move) / 20);
            break;
        case EFFECT_FIRST_TURN_ONLY:
            if (MoveHasAdditionalEffectWithChance(move, MOVE_EFFECT_FLINCH, 100))
                baseFromEffect += 3;
            break;
        case EFFECT_CONFUSE:
            if (GetBattlerMoveTargetType(gBattlerAttacker, move) == TARGET_FOES_AND_ALLY)
                baseFromEffect += 2;
            break;
        case EFFECT_REFLECT_DAMAGE: // 5 for Counter, 6 for Mirror Coat
            if (GetMoveReflectDamage_DamageCategories(move) == 1u << DAMAGE_CATEGORY_SPECIAL) // Mirror Coat
                baseFromEffect++;
            break;
        case EFFECT_RECOIL:
            if (GetMoveRecoil(move) > 0)
                baseFromEffect++;
            break;
        default:
            break;
        }

        // Non-volatile statuses
        switch (GetMoveNonVolatileStatus(arg2))
        {
        case MOVE_EFFECT_SLEEP:
            baseFromEffect++;
            break;
        case MOVE_EFFECT_PARALYSIS:
            baseFromEffect += 3;
            break;
        case MOVE_EFFECT_BURN:
        case MOVE_EFFECT_POISON:
            baseFromEffect += 4;
            break;
        case MOVE_EFFECT_TOXIC:
            baseFromEffect += 5;
            break;
        default:
            break;
        }

        // Guaranteed hit but without negative priority
        if (GetMoveAccuracy(move) == 0 && GetMovePriority(move) >= 0)
            baseFromEffect++;
        // // Explosion moves get 0 points in vanilla, so we deduct here from EFFECT_HIT's score of 1
        if (IsExplosionMove(move) && baseFromEffect > 0)
            baseFromEffect--;

        // Additional move effects in any move
        for (i = 0; i < GetMoveAdditionalEffectCount(move); i++)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_ABSORB:
                baseFromEffect += 4;
                break;
            case MOVE_EFFECT_BREAK_SCREEN:
                baseFromEffect += 1;
                break;
            case MOVE_EFFECT_THRASH:
                if (additionalEffect->self == TRUE)
                    baseFromEffect += 3;
                break;
            case MOVE_EFFECT_WRAP:
                if (additionalEffect->self == FALSE)
                    baseFromEffect += 3;
                break;
            case MOVE_EFFECT_RECHARGE:
                if (additionalEffect->self == TRUE)
                    baseFromEffect += 4;
                break;
            case MOVE_EFFECT_UPROAR:
                if (additionalEffect->self == TRUE)
                    baseFromEffect += 3;
                break;
            case MOVE_EFFECT_STAT_PLUS:
                for (enum Stat i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    enum Stat stat = sAccurateStatOrder[i];
                    s32 stage = GetStatStage(stat, additionalEffect);

                    if (stage == 0)
                        continue;

                    if (additionalEffect->self == TRUE && (additionalEffect->chance == 100 || additionalEffect->chance == 0))
                    {
                        switch (stage)
                        {
                        case 1:
                            baseFromEffect += 2;
                            break;
                        case 2:
                            baseFromEffect += 3;
                            break;
                        }
                    }
                }
                break;
            default:
                break;
            }
        }

        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] += baseFromEffect;
        break;
    }
#undef move
    case PTS_EFFECTIVENESS:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] += sPointsArray[caseId][arg2];
        break;
    case PTS_STAT_INCREASE_1:
    case PTS_STAT_DECREASE_1:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] += 2;
        break;
    case PTS_STAT_INCREASE_2:
    case PTS_STAT_DECREASE_2:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] += 4;
        break;
    case PTS_STAT_INCREASE_3:
    case PTS_STAT_DECREASE_3:
    case PTS_CRITICAL_HIT:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] += 6;
        break;
    case PTS_STAT_DECREASE_SELF:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] -= 1;
        break;
    case PTS_STAT_INCREASE_NOT_SELF:
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg1] -= 2;
        break;

#define move arg1
    case PTS_RAIN:
    {
        s32 points = 0;

        if (!IsBattleMoveStatus(move))
        {
            switch (GetMoveType(move))
            {
            case TYPE_WATER: points += 3; break;
            case TYPE_FIRE:  points -= 4; break;
            default: break;
            }
        }
        else if (move == MOVE_WITHDRAW) // For some reason, vanilla gives points to it
        {
            points += 3;
        }

        switch (GetMoveEffect(move))
        {
        case EFFECT_WEATHER_BALL:
            points += 3;
            break;
        case EFFECT_SOLAR_BEAM:
            points -= 4;
            break;
        default:
            break;
        }

        if (MoveAlwaysHitsInRain(move))
            points += 3;

        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg2] += points;
        break;
    }
    case PTS_SUN:
    {
        s32 points = 0;

        if (!IsBattleMoveStatus(move) && GetMoveType(move) == TYPE_FIRE)
            points += 3;

        switch (GetMoveEffect(move))
        {
        case EFFECT_SOLAR_BEAM:
            points += 5;
            break;
        case EFFECT_WEATHER_BALL:
        case EFFECT_SYNTHESIS:
        case EFFECT_MORNING_SUN:
        case EFFECT_MOONLIGHT:
            points += 3;
            break;
        default:
            break;
        }
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg2] += points;
        break;
    }
    case PTS_SANDSTORM:
    case PTS_HAIL_SNOW:
    {
        s32 points = 0;
        switch (GetMoveEffect(move))
        {
        case EFFECT_WEATHER_BALL:
            points += 3;
            break;
        case EFFECT_SOLAR_BEAM:
            points -= 3;
            break;
        default:
            break;
        }
        movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg2] += points;
        break;
    }
    case PTS_ELECTRIC:
        if (!IsBattleMoveStatus(move) && GetMoveType(move) == TYPE_ELECTRIC)
            movePoints->points[atkSide][GetTvPartyIndex(gBattlerAttacker) * 4 + arg2] += 3;
        break;
#undef move

    case PTS_FAINT:
        tvPtr->side[arg2 ^ BIT_SIDE].faintCause = FNT_NONE;
        movePoints->points[arg2][0 * 4 + arg3] += 6;
        break;
    case PTS_FAINT_SET_UP:
        tvPtr->side[arg2].faintCause = FNT_NONE;
        movePoints->points[arg2][0 * 4 + arg3] += 6;
        break;
    case PTS_SET_UP:
        movePoints->points[arg2][0 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case PTS_BREAK_WALL:
        movePoints->points[atkSide][arg2 * 4 + arg3] += 6;
        break;
    case PTS_STATUS_DMG:
        movePoints->points[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case PTS_STATUS_SKIP_TURN:
        movePoints->points[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += 5;
        break;
    case PTS_MIST:
        movePoints->points[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += 3;
        break;
    case PTS_SAFEGUARD:
    case PTS_FLINCHED:
        movePoints->points[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += 4;
        break;
    case PTS_SPIKES:
        movePoints->points[arg1][arg2 * 4 + arg3] += 4;
        break;

#define move arg1
#define power arg2
    case PTS_WATER_SPORT:
        // If used fire move during Water Sport
        if (tvPtr->pos[defSide][0].waterSportMonId != -(tvPtr->pos[defSide][1].waterSportMonId) && GetMoveType(move) == TYPE_FIRE)
        {
            if (tvPtr->pos[defSide][0].waterSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][0].waterSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][0].waterSportMoveSlot] += 5;
            }
            if (tvPtr->pos[defSide][1].waterSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][1].waterSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][1].waterSportMoveSlot] += 5;
            }
        }
        break;
    case PTS_MUD_SPORT:
        // If used Electric move during Mud Sport
        if (tvPtr->pos[defSide][0].mudSportMonId != -(tvPtr->pos[defSide][1].mudSportMonId) && GetMoveType(move) == TYPE_ELECTRIC)
        {
            if (tvPtr->pos[defSide][0].mudSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][0].mudSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][0].mudSportMoveSlot] += 5;
            }
            if (tvPtr->pos[defSide][1].mudSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][1].mudSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][1].mudSportMoveSlot] += 5;
            }
        }
        break;
    case PTS_REFLECT:
        // If hit Reflect with damaging physical move
        if (IsBattleMovePhysical(move) && power != 0 && tvPtr->side[defSide].reflectMonId != 0)
        {
            u32 id = (tvPtr->side[defSide].reflectMonId - 1) * 4;
            movePoints->points[defSide][id + tvPtr->side[defSide].reflectMoveSlot] += 3;
        }
        break;
    case PTS_LIGHT_SCREEN:
        // If hit Light Screen with damaging special move
        if (IsBattleMoveSpecial(move) && power != 0 && tvPtr->side[defSide].lightScreenMonId != 0)
        {
            u32 id = (tvPtr->side[defSide].lightScreenMonId - 1) * 4;
            movePoints->points[defSide][id + tvPtr->side[defSide].lightScreenMoveSlot] += sPointsArray[caseId][0];
        }
        break;
#undef move
#undef power
    }
}

static void AddPointsOnFainting(void)
{
    struct BattleTv *tvPtr = &gBattleStruct->tv;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    u32 atkArrId = tvPtr->side[atkSide].faintCauseMonId;
    s32 i;

    if (tvPtr->side[atkSide].faintCause != FNT_NONE)
    {
        switch (tvPtr->side[atkSide].faintCause)
        {
        case FNT_CURSE:
            if (tvPtr->pos[atkSide][atkArrId].curseMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].curseMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].curseMoveSlot);
            }
            break;
        case FNT_LEECH_SEED:
            if (tvPtr->pos[atkSide][atkArrId].leechSeedMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].leechSeedMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].leechSeedMoveSlot);
            }
            break;
        case FNT_POISON:
            if (tvPtr->mon[atkSide][atkArrId].psnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].psnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].psnMoveSlot);
            }
            if (tvPtr->mon[atkSide][atkArrId].badPsnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].badPsnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].badPsnMoveSlot);
            }
            break;
        case FNT_BURN:
            if (tvPtr->mon[atkSide][atkArrId].brnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].brnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].brnMoveSlot);
            }
            break;
        case FNT_NIGHTMARE:
            if (tvPtr->pos[atkSide][atkArrId].nightmareMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].nightmareMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].nightmareMoveSlot);
            }
            break;
        case FNT_WRAP:
            if (tvPtr->pos[atkSide][atkArrId].wrapMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].wrapMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].wrapMoveSlot);
            }
            break;
        case FNT_SPIKES:
            if (tvPtr->side[atkSide].spikesMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide].spikesMonId - 1) * 4 + tvPtr->side[atkSide].spikesMoveSlot);
            }
            break;
        case FNT_FUTURE_SIGHT:
            if (tvPtr->side[atkSide].futureSightMonId != 0)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            }
            break;
        case FNT_DOOM_DESIRE:
            if (tvPtr->side[atkSide].doomDesireMonId != 0)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            }
            break;
        case FNT_PERISH_SONG:
            if (tvPtr->side[atkSide].perishSong
                && tvPtr->side[atkSide].perishSongMonId - 1 != GetTvPartyIndex(gBattlerAttacker))
            {
                AddMovePoints(PTS_FAINT, 0, atkSide,
                (tvPtr->side[atkSide].perishSongMonId - 1) * 4 + tvPtr->side[atkSide].perishSongMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].perishSong)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].perishSongMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].perishSongMoveSlot);
            }
            break;
        case FNT_DESTINY_BOND:
            if (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMoveSlot);
            }
            break;
        case FNT_CONFUSION:
            for (i = 0; i < 2; i++)
            {
                if (tvPtr->pos[atkSide][i].confusionMonId != 0)
                {
                    AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                    (tvPtr->pos[atkSide][i].confusionMonId - 1) * 4 + tvPtr->pos[atkSide][i].confusionMoveSlot);
                }
            }
            break;
        case FNT_EXPLOSION:
            if (tvPtr->side[atkSide].explosion)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide,
                (tvPtr->side[atkSide].explosionMonId - 1) * 4 + tvPtr->side[atkSide].explosionMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].explosion)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot);
            }
            break;
        case FNT_RECOIL:
            if (gBattlerAttacker == gBattleScripting.battler)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (GetTvPartyIndex(gBattlerAttacker)) * 4 + tvPtr->side[atkSide].usedMoveSlot);
            }
            break;
        case FNT_OTHER:
            break;
        }
    }
    else
    {
        if (tvPtr->side[defSide].faintCause == FNT_SPIKES)
        {
            if (tvPtr->side[defSide].spikesMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, defSide ^ BIT_SIDE,
                (tvPtr->side[defSide].spikesMonId - 1) * 4 + tvPtr->side[defSide].spikesMoveSlot);
            }
        }
        else
        {
            AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
            (GetTvPartyIndex(gBattlerAttacker)) * 4 + tvPtr->side[atkSide].usedMoveSlot);
        }
    }
}

static void TrySetBattleSeminarShow(void)
{
    s32 i;
    s32 dmgByMove[MAX_MON_MOVES];
    u16 powerOverride;
    u16 currMoveSaved;

    if (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return;
    else if (!IsOnPlayerSide(gBattlerAttacker))
        return;
    else if (gBattleMons[gBattlerAttacker].statStages[STAT_ACC] < DEFAULT_STAT_STAGE)
        return;
    else if (gBattleMons[gBattlerTarget].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE)
        return;
    else if (gCurrentMove == MOVE_HIDDEN_POWER || gCurrentMove == MOVE_WEATHER_BALL)
        return;
    else if (gBattleTypeFlags & (BATTLE_TYPE_PALACE | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID))
        return;
    else if (IsBattleMoveStatus(gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]]))
        return;

    i = 0;
    currMoveSaved = gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]];
    do
    {
        if (currMoveSaved == sVariableDmgMoves[i])
            break;
        i++;
    } while (sVariableDmgMoves[i] != TABLE_END);

    if (sVariableDmgMoves[i] != TABLE_END)
        return;

    dmgByMove[gMoveSelectionCursor[gBattlerAttacker]] = gBattleStruct->moveDamage[gBattlerTarget]; // TODO: Not sure
    currMoveSaved = gCurrentMove;
    u16 storedMoveResultFlags = gBattleStruct->moveResultFlags[gBattlerTarget];
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gCurrentMove = gBattleMons[gBattlerAttacker].moves[i];
        powerOverride = 0;
        if (ShouldCalculateDamage(gCurrentMove, &dmgByMove[i], &powerOverride))
        {
            struct DamageContext ctx = {0};
            ctx.battlerAtk = gBattlerAttacker;
            ctx.battlerDef = gBattlerTarget;
            ctx.move = ctx.chosenMove = ctx.baseMove = gCurrentMove;
            ctx.moveType = GetMoveType(gCurrentMove);
            ctx.isCrit = FALSE;
            ctx.randomFactor = FALSE;
            ctx.updateFlags = FALSE;
            ctx.isSelfInflicted = FALSE;
            ctx.fixedBasePower = powerOverride;
            ctx.abilities[gBattlerAttacker] = GetBattlerAbility(gBattlerAttacker);
            ctx.abilities[gBattlerTarget] = GetBattlerAbility(gBattlerTarget);
            ctx.holdEffects[gBattlerAttacker] = GetBattlerHoldEffect(gBattlerAttacker);
            ctx.holdEffects[gBattlerTarget] = GetBattlerHoldEffect(gBattlerTarget);
            dmgByMove[i] = CalculateMoveDamage(&ctx);
            if (dmgByMove[i] == 0 && !IsBattlerUnaffectedByMove(gBattlerTarget))
                dmgByMove[i] = 1;
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[gMoveSelectionCursor[gBattlerAttacker]])
        {
            enum Species opponentSpecies, playerSpecies;
            s32 bestMoveId;

            if (gMoveSelectionCursor[gBattlerAttacker] != 0)
                bestMoveId = 0;
            else
                bestMoveId = 1;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[bestMoveId])
                    bestMoveId = i;
            }

            opponentSpecies = GetMonData(GetBattlerMon(gBattlerTarget),   MON_DATA_SPECIES);
            playerSpecies   = GetMonData(GetBattlerMon(gBattlerAttacker), MON_DATA_SPECIES);
            TryPutBattleSeminarOnAir(opponentSpecies, playerSpecies, gMoveSelectionCursor[gBattlerAttacker], gBattleMons[gBattlerAttacker].moves, gBattleMons[gBattlerAttacker].moves[bestMoveId]);
            break;
        }
    }

    gCurrentMove = currMoveSaved;
    gBattleStruct->moveResultFlags[gBattlerTarget] = storedMoveResultFlags;
}

static bool8 ShouldCalculateDamage(enum Move move, s32 *dmg, u16 *powerOverride)
{
    if (IsBattleMoveStatus(move))
    {
        *dmg = 0;
        return FALSE;
    }
    else
    {
        s32 i = 0;
        do
        {
            if (move == sVariableDmgMoves[i])
                break;
            i++;
        } while (sVariableDmgMoves[i] != TABLE_END);

        if (sVariableDmgMoves[i] != TABLE_END)
        {
            *dmg = 0;
            return FALSE;
        }
        else if (move == MOVE_PSYWAVE)
        {
            *dmg = gBattleMons[gBattlerAttacker].level;
            *dmg /= 2;
            return FALSE;
        }
        else if (move == MOVE_MAGNITUDE)
        {
            *powerOverride = 10;
            return TRUE;
        }
        else
        {
            return TRUE;
        }
    }
}

void BattleTv_ClearExplosionFaintCause(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        struct BattleTv *tvPtr = &gBattleStruct->tv;

        tvPtr->side[B_SIDE_PLAYER].faintCause = FNT_NONE;
        tvPtr->side[B_SIDE_OPPONENT].faintCause = FNT_NONE;

        tvPtr->side[B_SIDE_PLAYER].faintCauseMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].faintCauseMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMoveSlot = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMoveSlot = 0;

        tvPtr->side[B_SIDE_PLAYER].explosion = FALSE;
        tvPtr->side[B_SIDE_OPPONENT].explosion = FALSE;
    }
}

u8 GetBattlerMoveSlotId(enum BattlerId battler, enum Move move)
{
    s32 i;
    struct Pokemon *mon = GetBattlerMon(battler);

    i = 0;
    while (1)
    {
        if (i >= MAX_MON_MOVES)
            break;
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == move)
            break;
        i++;
    }

    return i;
}

static void AddPointsBasedOnWeather(u16 weatherFlags, enum Move move, u8 moveSlot)
{
    if (weatherFlags & B_WEATHER_RAIN)
        AddMovePoints(PTS_RAIN, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_SUN)
        AddMovePoints(PTS_SUN, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_SANDSTORM)
        AddMovePoints(PTS_SANDSTORM, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_ICY_ANY)
        AddMovePoints(PTS_HAIL_SNOW, move, moveSlot, 0);
}

static u32 GetTvPartyIndex(u32 battler)
{
    u32 index = gBattlerPartyIndexes[battler];
    if ((gBattleTypeFlags & BATTLE_TYPE_MULTI) && (GetBattlerPosition(battler) & BIT_FLANK))
        index += MULTI_PARTY_SIZE;
    return index;
}

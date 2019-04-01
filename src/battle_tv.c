#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_tv.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_anim.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "battle_message.h"
#include "tv.h"

// this file's functions
static bool8 sub_817E0B8(u16 stringId);
static void AddMovePoints(u8 caseId, u16 arg1, u8 arg2, u8 arg3);
static void TrySetBattleSeminarShow(void);
static void AddPointsOnFainting(bool8 targetFainted);
static void AddPointsBasedOnWeather(u16 weatherFlags, u16 moveId, u8 moveSlot);
static bool8 ShouldCalculateDamage(u16 moveId, s32 *dmg, u16 *powerOverride);

// const rom data
static const u16 sVariableDmgMoves[] =
{
    MOVE_COUNTER, MOVE_FISSURE, MOVE_BIDE, MOVE_MIRROR_COAT,
    MOVE_HORN_DRILL, MOVE_FLAIL, MOVE_REVERSAL, MOVE_HIDDEN_POWER,
    MOVE_SHEER_COLD, MOVE_FOCUS_PUNCH, MOVE_ERUPTION,
    MOVE_WATER_SPOUT, MOVE_DREAM_EATER, MOVE_WEATHER_BALL,
    MOVE_SNORE, MOVE_PAIN_SPLIT, MOVE_GUILLOTINE,
    MOVE_FRUSTRATION, MOVE_RETURN, MOVE_ENDEAVOR,
    MOVE_PRESENT, MOVE_REVENGE, 0xFFFF,
    // those are handled by the function itself
    MOVE_MAGNITUDE, MOVE_PSYWAVE, 0xFFFF
};

static const u16 sUnknown_0860A4E0[] =
{
    0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0000, 0x0005, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0005, 0x0005, 0x0004, 0x0005, 0x0001, 0x0003, 0x0001,
    0x0003, 0x0005, 0x0001, 0x0007, 0x0001, 0x0007, 0x0007, 0x0001, 0x0005, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0005, 0x0001,
    0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0007, 0x0004, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0004,
    0x0005, 0x0002, 0x0004, 0x0001, 0x0004, 0x0001, 0x0007, 0x0002, 0x0001, 0x0005, 0x0007, 0x0003, 0x0003, 0x0004, 0x0003, 0x0003,
    0x0003, 0x0003, 0x0003, 0x0002, 0x0004, 0x0001, 0x0005, 0x0001, 0x0001, 0x0004, 0x0005, 0x0003, 0x0001, 0x0002, 0x0001, 0x0005,
    0x0004, 0x0003, 0x0006, 0x0004, 0x0003, 0x0003, 0x0003, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0005, 0x0001, 0x0001, 0x0007,
    0x0002, 0x0002, 0x0001, 0x0001, 0x0004, 0x0004, 0x0004, 0x0001, 0x0004, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001, 0x0007, 0x0007,
    0x0006, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0003, 0x0001, 0x0001, 0x0004, 0x0004,
    0x0003, 0x0003, 0x0003, 0x0001, 0x0004, 0x0007, 0x0007, 0x0005, 0x0007, 0x0001, 0x0007, 0x0001, 0x0005, 0x0000, 0x0004, 0x0004,
    0x0004, 0x0004, 0x0004, 0x0002, 0x0002, 0x0006, 0x0003, 0x0006, 0x0004, 0x0004, 0x0002, 0x0005, 0x0002, 0x0001, 0x0001, 0x0006,
    0x0006, 0x0006, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0006, 0x0001, 0x0004, 0x0001, 0x0001, 0x0003, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0003
};
static const u16 sUnknown_0860A68C[] =
{
    0x0004, 0xfffd, 0xfffa
};
static const u16 sUnknown_0860A692[] =
{
    0x0004, 0x0004, 0x0006, 0x0006, 0x0007, 0x0006, 0x0002
};
static const u16 sUnknown_0860A6A0[] =
{
    0x0091, 0x0003, 0x00fa, 0x0003, 0x00be, 0x0003, 0x0080, 0x0003, 0x006e, 0x0003, 0x0098, 0x0003, 0x0143, 0x0003, 0x0123, 0x0003,
    0x007f, 0x0003, 0x014a, 0x0003, 0x0039, 0x0003, 0x0134, 0x0003, 0x0038, 0x0003, 0x003d, 0x0003, 0x015a, 0x0000, 0x0037, 0x0003,
    0x0160, 0x0003, 0x0137, 0x0003, 0x0057, 0x0003, 0x004c, 0xfffc, 0x013b, 0xfffc, 0x00ac, 0xfffc, 0x0035, 0xfffc, 0x00dd, 0xfffc,
    0x007e, 0xfffc, 0x0101, 0xfffc, 0x0034, 0xfffc, 0x0133, 0xfffc, 0x012b, 0xfffc, 0x011c, 0xfffc, 0x0053, 0xfffc, 0x0007, 0xfffc,
    0x004c, 0xfffc, 0xffff, 0x0000
};
static const u16 sUnknown_0860A728[] =
{
    0x013b, 0x0003, 0x00ac, 0x0003, 0x0035, 0x0003, 0x00dd, 0x0003, 0x007e, 0x0003, 0x0101, 0x0003, 0x0034, 0x0003, 0x0133, 0x0003,
    0x012b, 0x0003, 0x011c, 0x0003, 0x0053, 0x0003, 0x0007, 0x0003, 0x004c, 0x0005, 0x00eb, 0x0003, 0x00ea, 0x0003, 0x00ec, 0x0003,
    0x0137, 0x0003, 0xffff, 0x0000
};
static const u16 sUnknown_0860A770[] =
{
    0x0137, 0x0003, 0x004c, 0xfffd, 0xffff, 0x0000
};
static const u16 sUnknown_0860A77C[] =
{
    0x0137, 0x0003, 0x004c, 0xfffd, 0xffff, 0x0000
};
static const u16 sUnknown_0860A788[] =
{
    0x0055, 0x0003, 0x0009, 0x0003, 0x00d1, 0x0003, 0x0054, 0x0003, 0x00c0, 0x0003, 0x015f, 0x0003, 0x0056, 0x0000, 0x0057, 0x0003,
    0x0158, 0x0003, 0xffff, 0x0000
};
static const u16 sUnknown_0860A7B0[] =
{
    0x0005, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003
};
static const u16 sUnknown_0860A7BE[] =
{
    0x0005, 0x0005, 0x0005, 0x0005, 0x0005
};
static const u16 sUnknown_0860A7C8[] =
{
    0x0004
};
static const u16 sUnknown_0860A7CA[] =
{
    0x0005
};
static const u16 sUnknown_0860A7CC[] =
{
    0x0005
};
static const u16 sUnknown_0860A7CE[] =
{
    0x0003
};
static const u16 sUnknown_0860A7D0[] =
{
    0x0003
};
static const u16 sUnknown_0860A7D2[] =
{
    0x0004
};
static const u16 sUnknown_0860A7D4[] =
{
    0x0003
};
static const u16 sUnknown_0860A7D6[] =
{
    0x0006
};
static const u16 sUnknown_0860A7D8[] =
{
    0x0006
};
static const u16 sUnknown_0860A7DA[] =
{
    0x0006
};
static const u16 sUnknown_0860A7DC[] =
{
    0x0004
};
static const u16 sUnknown_0860A7DE[] =
{
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002
};
static const u16 sUnknown_0860A7EC[] =
{
    0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004
};
static const u16 sUnknown_0860A7FA[] =
{
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff
};
static const u16 sUnknown_0860A808[] =
{
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002
};
static const u16 sUnknown_0860A816[] =
{
    0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004
};
static const u16 sUnknown_0860A824[] =
{
    0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe
};

static const u16 *const sPointsArray[] =
{
    sUnknown_0860A4E0,
    sUnknown_0860A68C,
    sUnknown_0860A692,
    sUnknown_0860A6A0,
    sUnknown_0860A728,
    sUnknown_0860A770,
    sUnknown_0860A77C,
    sUnknown_0860A788,
    sUnknown_0860A7B0,
    sUnknown_0860A7BE,
    sUnknown_0860A7C8,
    sUnknown_0860A7CA,
    sUnknown_0860A7CC,
    sUnknown_0860A7CE,
    sUnknown_0860A7D0,
    sUnknown_0860A7D2,
    sUnknown_0860A7D4,
    sUnknown_0860A7D6,
    sUnknown_0860A7D8,
    sUnknown_0860A7DA,
    sUnknown_0860A7DA,
    sUnknown_0860A7DC,
    sUnknown_0860A7DE,
    sUnknown_0860A7EC,
    sUnknown_0860A7FA,
    sUnknown_0860A808,
    sUnknown_0860A816,
    sUnknown_0860A824
};

static const u16 sUnknown_0860A8A4[] =
{
    STRINGID_PKMNPERISHCOUNTFELL, STRINGID_PKMNWISHCAMETRUE, STRINGID_PKMNLOSTPPGRUDGE,
    STRINGID_PKMNTOOKFOE, STRINGID_PKMNABSORBEDNUTRIENTS, STRINGID_PKMNANCHOREDITSELF,
    STRINGID_PKMNAFFLICTEDBYCURSE, STRINGID_PKMNSAPPEDBYLEECHSEED, STRINGID_PKMNLOCKEDINNIGHTMARE,
    STRINGID_PKMNHURTBY, STRINGID_PKMNHURTBYBURN, STRINGID_PKMNHURTBYPOISON,
    STRINGID_PKMNHURTBYSPIKES, STRINGID_ATTACKERFAINTED, STRINGID_TARGETFAINTED,
    STRINGID_PKMNHITWITHRECOIL, STRINGID_PKMNCRASHED, 0xFFFF
};

// code
void BattleTv_SetDataBasedOnString(u16 stringId)
{
    struct BattleTv *tvPtr;
    u32 atkSide, defSide, effSide, scriptingSide;
    struct Pokemon *atkMon, *defMon;
    u8 moveSlot;
    u32 atkFlank, defFlank, effFlank;
    u8 *perishCount;
    u16 *statStringId, *finishedMoveId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && stringId != STRINGID_ITDOESNTAFFECT && stringId != STRINGID_NOTVERYEFFECTIVE)
        return;

    tvPtr = &gBattleStruct->tv;

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    effSide = GetBattlerSide(gEffectBattler);
    scriptingSide = GetBattlerSide(gBattleMsgDataPtr->scrActive);

    if (atkSide == B_SIDE_PLAYER)
        atkMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        atkMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    if (defSide == B_SIDE_PLAYER)
        defMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerTarget]];
    else
        defMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]];

    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, gBattleMsgDataPtr->currentMove);

    if (moveSlot >= 4 && sub_817E0B8(stringId) && stringId > BATTLESTRINGS_ID_ADDER)
    {
        tvPtr->side[atkSide].faintCause = 15;
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
        AddMovePoints(1, moveSlot, 2, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
            TrySetBattleSeminarShow();
        break;
    case STRINGID_NOTVERYEFFECTIVE:
        AddMovePoints(1, moveSlot, 1, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && GetMonData(defMon, MON_DATA_HP, NULL) != 0)
            TrySetBattleSeminarShow();
        break;
    case STRINGID_SUPEREFFECTIVE:
        AddMovePoints(1, moveSlot, 0, 0);
        break;
    case STRINGID_PKMNFORESAWATTACK:
        tvPtr->side[atkSide].futureSightMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].futureSightMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNCHOSEXASDESTINY:
        tvPtr->side[atkSide].doomDesireMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].doomDesireMoveSlot = moveSlot;
        break;
    case STRINGID_FAINTINTHREE:
        tvPtr->side[atkSide].perishSongMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].perishSongMoveSlot = moveSlot;
        tvPtr->side[atkSide].perishSong = 1;
        break;
    case STRINGID_PKMNPERISHCOUNTFELL:
        if (*perishCount == 0)
            tvPtr->side[atkSide].faintCause = 10;
        break;
    case STRINGID_PKMNWISHCAMETRUE:
        if (tvPtr->side[defSide].wishMonId != 0)
        {
            AddMovePoints(2, 3, defSide,
            (tvPtr->side[defSide].wishMonId - 1) * 4 + tvPtr->side[defSide].wishMoveSlot);
        }
        break;
    case STRINGID_PKMNWANTSGRUDGE:
        tvPtr->side[atkSide].grudgeMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].grudgeMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOSTPPGRUDGE:
        if (tvPtr->side[defSide].grudgeMonId != 0)
        {
            AddMovePoints(2, 4, defSide,
            (tvPtr->side[defSide].grudgeMonId - 1) * 4 + tvPtr->side[defSide].grudgeMoveSlot);
        }
        break;
    case STRINGID_PKMNTRYINGTOTAKEFOE:
        tvPtr->side[atkSide].destinyBondMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].destinyBondMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNTOOKFOE:
        if (tvPtr->side[defSide].destinyBondMonId != 0)
            tvPtr->side[atkSide].faintCause = 11;
        break;
    case STRINGID_PKMNPLANTEDROOTS:
        tvPtr->pos[atkSide][atkFlank].ingrainMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[atkSide][atkFlank].ingrainMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNABSORBEDNUTRIENTS:
        if (tvPtr->pos[atkSide][atkFlank].ingrainMonId != 0)
        {
            AddMovePoints(2, 6, atkSide,
            (tvPtr->pos[atkSide][atkFlank].ingrainMonId - 1) * 4 + tvPtr->pos[atkSide][atkFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNANCHOREDITSELF:
        if (tvPtr->pos[defSide][defFlank].ingrainMonId != 0)
        {
            AddMovePoints(2, 6, defSide,
            (tvPtr->pos[defSide][defFlank].ingrainMonId - 1) * 4 + tvPtr->pos[defSide][defFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNTRANSFORMEDINTO:
        gBattleStruct->anyMonHasTransformed = TRUE;
        break;
    case STRINGID_CRITICALHIT:
        AddMovePoints(0x12, moveSlot, 0, 0);
        break;
    case STRINGID_PKMNSSTATCHANGED:
        if (gBattleTextBuff1[2] != 0)
        {
            if (*statStringId == STRINGID_STATSHARPLY)
                AddMovePoints(0x17, moveSlot, gBattleTextBuff1[2] - 1, 0);
            else
                AddMovePoints(0x16, moveSlot, gBattleTextBuff1[2] - 1, 0);
        }
        break;
    case STRINGID_PKMNSSTATCHANGED2:
        if (gBattleTextBuff1[2] != 0)
        {
            if (gBattlerAttacker == gBattlerTarget)
            {
                if (*statStringId == STRINGID_STATSHARPLY)
                    AddMovePoints(0x17, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else
                    AddMovePoints(0x16, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
            else
            {
                AddMovePoints(0x1B, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
        }
        break;
    case STRINGID_PKMNSSTATCHANGED3:
        if (gBattleTextBuff1[2] != 0)
            AddMovePoints(0x18, moveSlot, gBattleTextBuff1[2] - 1, 0);
        break;
    case STRINGID_PKMNSSTATCHANGED4:
        if (gBattleTextBuff1[2] != 0)
        {
            if (*statStringId == STRINGID_STATHARSHLY)
                AddMovePoints(0x1A, moveSlot, gBattleTextBuff1[2] - 1, 0);
            else
                AddMovePoints(0x19, moveSlot, gBattleTextBuff1[2] - 1, 0);
        }
        break;
    case STRINGID_PKMNLAIDCURSE:
        tvPtr->pos[defSide][defFlank].curseMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[defSide][defFlank].curseMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNAFFLICTEDBYCURSE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL)
            && tvPtr->pos[atkSide][atkFlank].curseMonId != 0)
        {
            AddMovePoints(8, 0, tvPtr->pos[atkSide][atkFlank].curseMonId - 1, tvPtr->pos[atkSide][atkFlank].curseMoveSlot);
            tvPtr->side[atkSide].faintCause = 1;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNSEEDED:
        tvPtr->pos[defSide][defFlank].leechSeedMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[defSide][defFlank].leechSeedMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNSAPPEDBYLEECHSEED:
        if (tvPtr->pos[atkSide][atkFlank].leechSeedMonId != 0)
        {
            AddMovePoints(8, 1, tvPtr->pos[atkSide][atkFlank].leechSeedMonId - 1, tvPtr->pos[atkSide][atkFlank].leechSeedMoveSlot);
            tvPtr->side[atkSide].faintCause = 2;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNFELLINTONIGHTMARE:
        tvPtr->pos[defSide][defFlank].nightmareMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[defSide][defFlank].nightmareMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOCKEDINNIGHTMARE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && tvPtr->pos[atkSide][atkFlank].nightmareMonId != 0)
        {
            AddMovePoints(8, 5, tvPtr->pos[atkSide][atkFlank].nightmareMonId - 1, tvPtr->pos[atkSide][atkFlank].nightmareMoveSlot);
            tvPtr->side[atkSide].faintCause = 5;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNSQUEEZEDBYBIND:
    case STRINGID_PKMNTRAPPEDINVORTEX:
    case STRINGID_PKMNWRAPPEDBY:
    case STRINGID_PKMNCLAMPED:
    case STRINGID_PKMNTRAPPEDBYSANDTOMB:
        tvPtr->pos[defSide][defFlank].wrapMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[defSide][defFlank].wrapMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBY:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && tvPtr->pos[atkSide][atkFlank].wrapMonId != 0)
        {
            AddMovePoints(8, 6, tvPtr->pos[atkSide][atkFlank].wrapMonId - 1, tvPtr->pos[atkSide][atkFlank].wrapMoveSlot);
            tvPtr->side[atkSide].faintCause = 6;
            tvPtr->side[atkSide].faintCauseMonId = atkFlank;
        }
        break;
    case STRINGID_PKMNWASBURNED:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].brnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].brnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYBURN:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMonId != 0)
                AddMovePoints(8, 4, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMoveSlot);
            tvPtr->side[atkSide].faintCause = 4;
            tvPtr->side[atkSide].faintCauseMonId = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNWASPOISONED:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].psnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].psnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNBADLYPOISONED:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].badPsnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].badPsnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYPOISON:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMonId != 0)
                AddMovePoints(8, 2, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMoveSlot);
            if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMonId != 0)
                AddMovePoints(8, 3, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMoveSlot);
            tvPtr->side[atkSide].faintCause = 3;
            tvPtr->side[atkSide].faintCauseMonId = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNFELLINLOVE:
        tvPtr->pos[defSide][defFlank].attractMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[defSide][defFlank].attractMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNIMMOBILIZEDBYLOVE:
        if (tvPtr->pos[atkSide][atkFlank].attractMonId != 0)
            AddMovePoints(9, 0, tvPtr->pos[atkSide][atkFlank].attractMonId - 1, tvPtr->pos[atkSide][atkFlank].attractMoveSlot);
        break;
    case STRINGID_PKMNWASPARALYZED:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].prlzMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].prlzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISPARALYZED:
        if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMonId != 0)
            AddMovePoints(9, 2, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMoveSlot);
        break;
    case STRINGID_PKMNFELLASLEEP:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].slpMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].slpMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNFASTASLEEP:
        if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMonId != 0
            && gBattleMsgDataPtr->currentMove != MOVE_SNORE
            && gBattleMsgDataPtr->currentMove != MOVE_SLEEP_TALK)
            AddMovePoints(9, 3, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMoveSlot);
        break;
    case STRINGID_PKMNWASFROZEN:
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].frzMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].frzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISFROZEN:
        if (tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMonId != 0)
            AddMovePoints(9, 4, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMonId - 1, tvPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMoveSlot);
        break;
    case STRINGID_PKMNWASCONFUSED:
        tvPtr->pos[effSide][effFlank].confusionMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[effSide][effFlank].confusionMoveSlot = moveSlot;
        break;
    case STRINGID_ITHURTCONFUSION:
        if (tvPtr->pos[atkSide][atkFlank].confusionMonId != 0)
            AddMovePoints(9, 1, tvPtr->pos[atkSide][atkFlank].confusionMonId - 1, tvPtr->pos[atkSide][atkFlank].confusionMoveSlot);
        tvPtr->side[atkSide].faintCause = 12;
        break;
    case STRINGID_SPIKESSCATTERED:
        tvPtr->side[defSide].spikesMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[defSide].spikesMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYSPIKES:
        if (tvPtr->side[scriptingSide].spikesMonId != 0)
        {
            AddMovePoints(10, scriptingSide ^ BIT_SIDE, tvPtr->side[scriptingSide].spikesMonId - 1, tvPtr->side[scriptingSide].spikesMoveSlot);
            tvPtr->side[scriptingSide].faintCause = 7;
        }
        break;
    case STRINGID_PKMNBLEWAWAYSPIKES:
        tvPtr->side[atkSide].spikesMonId = 0;
        tvPtr->side[atkSide].spikesMoveSlot = 0;
        break;
    case STRINGID_FIREWEAKENED:
        tvPtr->pos[atkSide][atkFlank].waterSportMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[atkSide][atkFlank].waterSportMoveSlot = moveSlot;
        break;
    case STRINGID_ELECTRICITYWEAKENED:
        tvPtr->pos[atkSide][atkFlank].mudSportMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->pos[atkSide][atkFlank].mudSportMoveSlot = moveSlot;
        break;
    case STRINGID_ATTACKERFAINTED:
        AddPointsOnFainting(FALSE);
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
    case STRINGID_TARGETFAINTED:
        AddPointsOnFainting(TRUE);
        if (tvPtr->pos[atkSide][defFlank].waterSportMonId != 0)
        {
            tvPtr->pos[atkSide][defFlank].waterSportMonId = 0;
            tvPtr->pos[atkSide][defFlank].waterSportMoveSlot = 0;
        }
        if (tvPtr->pos[atkSide][defFlank].mudSportMonId != 0)
        {
            tvPtr->pos[atkSide][defFlank].mudSportMonId = 0;
            tvPtr->pos[atkSide][defFlank].mudSportMoveSlot = 0;
        }
        break;
    case STRINGID_PKMNRAISEDDEF:
    case STRINGID_PKMNRAISEDDEFALITTLE:
        tvPtr->side[atkSide].reflectMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].reflectMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNRAISEDSPDEF:
    case STRINGID_PKMNRAISEDSPDEFALITTLE:
        tvPtr->side[atkSide].lightScreenMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
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
        tvPtr->side[atkSide].safeguardMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].safeguardMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNUSEDSAFEGUARD:
        if (tvPtr->side[defSide].safeguardMonId != 0)
            AddMovePoints(15, 0, tvPtr->side[defSide].safeguardMonId - 1, tvPtr->side[defSide].safeguardMoveSlot);
        break;
    case STRINGID_PKMNSAFEGUARDEXPIRED:
        tvPtr->side[atkSide].safeguardMonId = 0;
        tvPtr->side[atkSide].safeguardMoveSlot = 0;
        break;
    case STRINGID_PKMNSHROUDEDINMIST:
        tvPtr->side[atkSide].mistMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].mistMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNPROTECTEDBYMIST:
        if (tvPtr->side[defSide].mistMonId != 0)
            AddMovePoints(16, 0, tvPtr->side[defSide].mistMonId - 1, tvPtr->side[defSide].mistMoveSlot);
        break;
    case STRINGID_THEWALLSHATTERED:
        tvPtr->side[defSide].reflectMonId = 0;
        tvPtr->side[defSide].reflectMoveSlot = 0;
        tvPtr->side[defSide].lightScreenMonId = 0;
        tvPtr->side[defSide].lightScreenMoveSlot = 0;
        AddMovePoints(17, 0, gBattlerPartyIndexes[gBattlerAttacker], moveSlot);
        break;
    case STRINGID_PKMNFLINCHED:
        if (tvPtr->pos[atkSide][0].attackedByMonId != 0)
            AddMovePoints(21, 0, tvPtr->pos[atkSide][0].attackedByMonId - 1, tvPtr->pos[atkSide][0].attackedByMoveSlot);
        if (tvPtr->pos[atkSide][1].attackedByMonId != 0)
            AddMovePoints(21, 0, tvPtr->pos[atkSide][1].attackedByMonId - 1, tvPtr->pos[atkSide][1].attackedByMoveSlot);
        break;
    case STRINGID_PKMNCRASHED:
    case STRINGID_PKMNHITWITHRECOIL:
        tvPtr->side[atkSide].faintCause = 14;
        break;
    }
}

static bool8 sub_817E0B8(u16 stringId)
{
    s32 i = 0;

    do
    {
        if (sUnknown_0860A8A4[i] == stringId)
            break;
        i++;
    } while (sUnknown_0860A8A4[i] != 0xFFFF);

    if (sUnknown_0860A8A4[i] == 0xFFFF)
        return TRUE;
    else
        return FALSE;
}

void BattleTv_SetDataBasedOnMove(u16 move, u16 weatherFlags, struct DisableStruct *disableStructPtr)
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

    if (moveSlot >= 4)
    {
        tvPtr->side[atkSide].faintCause = 15;
        return;
    }

    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMoveSlot = moveSlot;
    tvPtr->side[atkSide].usedMoveSlot = moveSlot;
    AddMovePoints(0, moveSlot, gBattleMoves[move].effect, 0);
    AddPointsBasedOnWeather(weatherFlags, move, moveSlot);
    if (disableStructPtr->chargeTimer != 0)
        AddMovePoints(7, move, moveSlot, 0);

    if (move == MOVE_WISH)
    {
        tvPtr->side[atkSide].wishMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].wishMoveSlot = moveSlot;
    }
    if (move == MOVE_SELF_DESTRUCT || move == MOVE_EXPLOSION)
    {
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot = moveSlot;
        tvPtr->side[atkSide ^ BIT_SIDE].faintCause = 13;
        tvPtr->side[atkSide ^ BIT_SIDE].explosion = 1;
    }

    AddMovePoints(13, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    AddMovePoints(14, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    AddMovePoints(11, gBattleMoves[move].type, 0,                        0);
    AddMovePoints(12, gBattleMoves[move].type, 0,                        0);
}

void BattleTv_SetDataBasedOnAnimation(u8 animationId)
{
    struct BattleTv *tvPtr;
    u32 atkSide;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    tvPtr = &gBattleStruct->tv;
    atkSide = GetBattlerSide(gBattlerAttacker);
    switch (animationId)
    {
    case B_ANIM_FUTURE_SIGHT_HIT:
        if (tvPtr->side[atkSide].futureSightMonId != 0)
        {
            AddMovePoints(2, 0, atkSide,
                        (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            tvPtr->side[atkSide].faintCause = 8;
        }
        break;
    case B_ANIM_DOOM_DESIRE_HIT:
        if (tvPtr->side[atkSide].doomDesireMonId != 0)
        {
            AddMovePoints(2, 1, atkSide,
                        (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            tvPtr->side[atkSide].faintCause = 9;
        }
        break;
    }
}

#ifdef NONMATCHING
// for loop has an unused stack variable
void TryPutLinkBattleTvShowOnAir(void)
{
    u16 playerBestSpecies = 0, opponentBestSpecies = 0;
    s16 playerBestSum = 0, opponentBestSum = SHRT_MAX;
    u8 playerBestMonId = 0, opponentBestMonId = 0;
    struct BattleTvMovePoints *movePoints = NULL;
    u8 countPlayer = 0, countOpponent = 0;
    s16 sum = 0;
    u16 species = 0;
    u16 moveId = 0;
    s32 i, j;

    if (gBattleStruct->anyMonHasTransformed)
        return;

    movePoints = &gBattleStruct->tvMovePoints;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
            countPlayer++;
        if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
            countOpponent++;
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) || countPlayer != countOpponent)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
        {
            for (sum = 0, j = 0; j < MAX_MON_MOVES; j++)
                sum += movePoints->points[0][i * 4 + j];

            if (playerBestSum < sum)
            {
                playerBestMonId = i;
                playerBestSum = sum;
                playerBestSpecies = species;
            }
        }

        species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG, NULL))
        {
            for (sum = 0, j = 0; j < MAX_MON_MOVES; j++)
                sum += movePoints->points[1][i * 4 + j];

            if (opponentBestSum == sum)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_EXP, NULL) > GetMonData(&gEnemyParty[opponentBestMonId], MON_DATA_EXP, NULL))
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
        if (sum < movePoints->points[0][playerBestMonId * 4 + j])
        {
            sum = movePoints->points[0][playerBestMonId * 4 + j];
            i = j;
        }
    }

    moveId = GetMonData(&gPlayerParty[playerBestMonId], MON_DATA_MOVE1 + i, NULL);
    if (playerBestSum == 0 || moveId == 0)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((playerBestMonId < 3 && !GetLinkTrainerFlankId(gBattleScripting.multiplayerId))
            || (playerBestMonId >= 3 && GetLinkTrainerFlankId(gBattleScripting.multiplayerId)))
        {
            j = (opponentBestMonId < 3) ? 0 : 1;
            PutBattleUpdateOnTheAir(sub_806EF84(j, gBattleScripting.multiplayerId), moveId, playerBestSpecies, opponentBestSpecies);
        }
    }
    else
    {
        PutBattleUpdateOnTheAir(gBattleScripting.multiplayerId ^ 1, moveId, playerBestSpecies, opponentBestSpecies);
    }
}

#else
NAKED
void TryPutLinkBattleTvShowOnAir(void)
{
    asm_unified(
    "push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x20\n\
    movs r0, 0\n\
    str r0, [sp]\n\
    movs r1, 0\n\
    str r1, [sp, 0x4]\n\
    movs r2, 0\n\
    str r2, [sp, 0x8]\n\
    ldr r3, =0x00007fff\n\
    str r3, [sp, 0xC]\n\
    movs r4, 0\n\
    str r4, [sp, 0x10]\n\
    movs r7, 0\n\
    str r7, [sp, 0x14]\n\
    mov r8, r0\n\
    ldr r0, =gBattleStruct\n\
    ldr r1, [r0]\n\
    adds r0, r1, 0\n\
    adds r0, 0xB3\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _0817E42A\n\
    b _0817E670\n\
_0817E42A:\n\
    movs r2, 0xD2\n\
    lsls r2, 1\n\
    adds r2, r1\n\
    mov r10, r2\n\
    movs r6, 0\n\
_0817E434:\n\
    movs r0, 0x64\n\
    adds r4, r6, 0\n\
    muls r4, r0\n\
    ldr r0, =gPlayerParty\n\
    adds r0, r4, r0\n\
    movs r1, 0xB\n\
    movs r2, 0\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _0817E454\n\
    mov r0, r8\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r8, r0\n\
_0817E454:\n\
    ldr r5, =gEnemyParty\n\
    adds r0, r4, r5\n\
    movs r1, 0xB\n\
    movs r2, 0\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    beq _0817E46A\n\
    adds r0, r7, 0x1\n\
    lsls r0, 24\n\
    lsrs r7, r0, 24\n\
_0817E46A:\n\
    adds r6, 0x1\n\
    cmp r6, 0x5\n\
    ble _0817E434\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    movs r1, 0x2\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0817E47E\n\
    b _0817E670\n\
_0817E47E:\n\
    cmp r8, r7\n\
    beq _0817E484\n\
    b _0817E670\n\
_0817E484:\n\
    movs r6, 0\n\
    lsls r3, r6, 1\n\
    str r3, [sp, 0x18]\n\
    movs r4, 0x64\n\
    mov r8, r4\n\
_0817E48E:\n\
    mov r1, r8\n\
    muls r1, r6\n\
    ldr r0, =gPlayerParty\n\
    adds r4, r1, r0\n\
    adds r0, r4, 0\n\
    movs r1, 0xB\n\
    movs r2, 0\n\
    bl GetMonData\n\
    lsls r0, 16\n\
    lsrs r7, r0, 16\n\
    adds r0, r6, 0x1\n\
    mov r9, r0\n\
    cmp r7, 0\n\
    beq _0817E4EE\n\
    adds r0, r4, 0\n\
    movs r1, 0x2D\n\
    movs r2, 0\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    bne _0817E4EE\n\
    movs r4, 0\n\
    lsls r0, r6, 3\n\
    mov r2, r10\n\
    adds r1, r0, r2\n\
    movs r3, 0x3\n\
_0817E4C4:\n\
    lsls r0, r4, 16\n\
    asrs r0, 16\n\
    ldrh r4, [r1]\n\
    adds r0, r4\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    adds r1, 0x2\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0817E4C4\n\
    ldr r1, [sp, 0x8]\n\
    lsls r0, r1, 16\n\
    lsls r1, r4, 16\n\
    cmp r0, r1\n\
    bge _0817E4EE\n\
    lsls r0, r6, 24\n\
    lsrs r0, 24\n\
    str r0, [sp, 0x10]\n\
    lsrs r1, 16\n\
    str r1, [sp, 0x8]\n\
    str r7, [sp]\n\
_0817E4EE:\n\
    mov r0, r8\n\
    muls r0, r6\n\
    ldr r2, =gEnemyParty\n\
    adds r4, r0, r2\n\
    adds r0, r4, 0\n\
    movs r1, 0xB\n\
    movs r2, 0\n\
    bl GetMonData\n\
    lsls r0, 16\n\
    lsrs r7, r0, 16\n\
    ldr r3, [sp, 0x8]\n\
    lsls r3, 16\n\
    str r3, [sp, 0x1C]\n\
    cmp r7, 0\n\
    beq _0817E5A0\n\
    adds r0, r4, 0\n\
    movs r1, 0x2D\n\
    movs r2, 0\n\
    bl GetMonData\n\
    cmp r0, 0\n\
    bne _0817E5A0\n\
    movs r4, 0\n\
    ldr r0, [sp, 0xC]\n\
    lsls r2, r0, 16\n\
    movs r3, 0x1\n\
    lsls r1, r3, 1\n\
    adds r1, 0x1\n\
    lsls r1, 4\n\
    lsls r0, r6, 3\n\
    adds r0, r1\n\
    mov r3, r10\n\
    adds r1, r0, r3\n\
    movs r3, 0x3\n\
_0817E534:\n\
    lsls r0, r4, 16\n\
    asrs r0, 16\n\
    ldrh r4, [r1]\n\
    adds r0, r4\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    adds r1, 0x2\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0817E534\n\
    asrs r1, r2, 16\n\
    lsls r5, r4, 16\n\
    asrs r0, r5, 16\n\
    cmp r1, r0\n\
    bne _0817E590\n\
    mov r0, r8\n\
    muls r0, r6\n\
    ldr r1, =gEnemyParty\n\
    adds r0, r1\n\
    movs r1, 0x19\n\
    movs r2, 0\n\
    bl GetMonData\n\
    adds r4, r0, 0\n\
    ldr r2, [sp, 0x14]\n\
    mov r0, r8\n\
    muls r0, r2\n\
    ldr r3, =gEnemyParty\n\
    adds r0, r3\n\
    movs r1, 0x19\n\
    movs r2, 0\n\
    bl GetMonData\n\
    cmp r4, r0\n\
    bls _0817E5A0\n\
    b _0817E594\n\
    .pool\n\
_0817E590:\n\
    cmp r1, r0\n\
    ble _0817E5A0\n\
_0817E594:\n\
    lsls r0, r6, 24\n\
    lsrs r0, 24\n\
    str r0, [sp, 0x14]\n\
    lsrs r5, 16\n\
    str r5, [sp, 0xC]\n\
    str r7, [sp, 0x4]\n\
_0817E5A0:\n\
    mov r6, r9\n\
    cmp r6, 0x5\n\
    bgt _0817E5A8\n\
    b _0817E48E\n\
_0817E5A8:\n\
    movs r4, 0\n\
    movs r6, 0\n\
    movs r3, 0\n\
    ldr r5, =gPlayerParty\n\
    ldr r7, [sp, 0x10]\n\
    lsls r0, r7, 3\n\
    mov r1, r10\n\
    adds r2, r0, r1\n\
_0817E5B8:\n\
    lsls r0, r4, 16\n\
    asrs r0, 16\n\
    movs r7, 0\n\
    ldrsh r1, [r2, r7]\n\
    cmp r0, r1\n\
    bge _0817E5C8\n\
    ldrh r4, [r2]\n\
    adds r6, r3, 0\n\
_0817E5C8:\n\
    adds r2, 0x2\n\
    adds r3, 0x1\n\
    cmp r3, 0x3\n\
    ble _0817E5B8\n\
    movs r0, 0x64\n\
    ldr r1, [sp, 0x10]\n\
    muls r0, r1\n\
    adds r0, r5\n\
    adds r1, r6, 0\n\
    adds r1, 0xD\n\
    movs r2, 0\n\
    bl GetMonData\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    ldr r2, [sp, 0x1C]\n\
    cmp r2, 0\n\
    beq _0817E670\n\
    cmp r4, 0\n\
    beq _0817E670\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    movs r1, 0x40\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0817E65C\n\
    ldr r3, [sp, 0x10]\n\
    cmp r3, 0x2\n\
    bhi _0817E620\n\
    ldr r0, =gBattleScripting\n\
    adds r0, 0x25\n\
    ldrb r0, [r0]\n\
    bl GetLinkTrainerFlankId\n\
    lsls r0, 16\n\
    cmp r0, 0\n\
    beq _0817E630\n\
    b _0817E670\n\
    .pool\n\
_0817E620:\n\
    ldr r0, =gBattleScripting\n\
    adds r0, 0x25\n\
    ldrb r0, [r0]\n\
    bl GetLinkTrainerFlankId\n\
    lsls r0, 16\n\
    cmp r0, 0\n\
    beq _0817E670\n\
_0817E630:\n\
    movs r3, 0\n\
    ldr r7, [sp, 0x14]\n\
    cmp r7, 0x2\n\
    bls _0817E63A\n\
    movs r3, 0x1\n\
_0817E63A:\n\
    lsls r0, r3, 24\n\
    lsrs r0, 24\n\
    ldr r1, =gBattleScripting\n\
    adds r1, 0x25\n\
    ldrb r1, [r1]\n\
    bl sub_806EF84\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    adds r1, r4, 0\n\
    ldr r2, [sp]\n\
    ldr r3, [sp, 0x4]\n\
    bl PutBattleUpdateOnTheAir\n\
    b _0817E670\n\
    .pool\n\
_0817E65C:\n\
    ldr r0, =gBattleScripting\n\
    adds r0, 0x25\n\
    ldrb r1, [r0]\n\
    movs r0, 0x1\n\
    eors r0, r1\n\
    adds r1, r4, 0\n\
    ldr r2, [sp]\n\
    ldr r3, [sp, 0x4]\n\
    bl PutBattleUpdateOnTheAir\n\
_0817E670:\n\
    add sp, 0x20\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif

static void AddMovePoints(u8 caseId, u16 arg1, u8 arg2, u8 arg3)
{
    struct BattleTvMovePoints *movePoints = &gBattleStruct->tvMovePoints;
    struct BattleTv *tvPtr = &gBattleStruct->tv;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    const u16 *ptr;
    s32 i;

    switch (caseId)
    {
    case 0:
    case 1:
    case 18:
    case 22 ... 27:
        movePoints->points[atkSide][gBattlerPartyIndexes[gBattlerAttacker] * 4 + arg1] += sPointsArray[caseId][arg2];
        break;
    case 3 ... 7:
        i = 0;
        ptr = sPointsArray[caseId];
        do
        {
            if (arg1 == ptr[i])
            {
                movePoints->points[atkSide][gBattlerPartyIndexes[gBattlerAttacker] * 4 + arg2] += ptr[i+1];
                break;
            }
            i += 2;
        } while (ptr[i] != 0xFFFF);
        break;
    case 19:
        tvPtr->side[arg2 ^ 1].faintCause = 0;
        movePoints->points[arg2][0 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case 20:
        tvPtr->side[arg2].faintCause = 0;
    case 2:
        movePoints->points[arg2][0 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case 17:
        movePoints->points[atkSide][arg2 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case 8:
    case 9:
    case 15:
    case 16:
    case 21:
        movePoints->points[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += sPointsArray[caseId][arg1];
        break;
    case 10:
        movePoints->points[arg1][arg2 * 4 + arg3] += sPointsArray[caseId][0];
        break;
    case 11:
        if (tvPtr->pos[defSide][0].waterSportMonId != -(tvPtr->pos[defSide][1].waterSportMonId) && arg1 == 10)
        {
            if (tvPtr->pos[defSide][0].waterSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][0].waterSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][0].waterSportMoveSlot] += sPointsArray[caseId][0];
            }
            if (tvPtr->pos[defSide][1].waterSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][1].waterSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][1].waterSportMoveSlot] += sPointsArray[caseId][0];
            }
        }
        break;
    case 12:
        if (tvPtr->pos[defSide][0].mudSportMonId != -(tvPtr->pos[defSide][1].mudSportMonId) && arg1 == 13)
        {
            if (tvPtr->pos[defSide][0].mudSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][0].mudSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][0].mudSportMoveSlot] += sPointsArray[caseId][0];
            }
            if (tvPtr->pos[defSide][1].mudSportMonId != 0)
            {
                u32 id = (tvPtr->pos[defSide][1].mudSportMonId - 1) * 4;
                movePoints->points[defSide][id + tvPtr->pos[defSide][1].mudSportMoveSlot] += sPointsArray[caseId][0];
            }
        }
        break;
    case 13:
        if (arg1 <= 8 && arg2 != 0 && tvPtr->side[defSide].reflectMonId != 0)
        {
            u32 id = (tvPtr->side[defSide].reflectMonId - 1) * 4;
            movePoints->points[defSide][id + tvPtr->side[defSide].reflectMoveSlot] += sPointsArray[caseId][0];
        }
        break;
    case 14:
        if (arg1 > 8 && arg2 != 0 && tvPtr->side[defSide].lightScreenMonId != 0)
        {
            u32 id = (tvPtr->side[defSide].lightScreenMonId - 1) * 4;
            movePoints->points[defSide][id + tvPtr->side[defSide].lightScreenMoveSlot] += sPointsArray[caseId][0];
        }
        break;
    }
}

static void AddPointsOnFainting(bool8 targetFainted)
{
    struct BattleTv *tvPtr = &gBattleStruct->tv;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    u32 atkArrId = tvPtr->side[atkSide].faintCauseMonId;
    s32 i;

    if (tvPtr->side[atkSide].faintCause != 0)
    {
        switch (tvPtr->side[atkSide].faintCause)
        {
        case 1:
            if (tvPtr->pos[atkSide][atkArrId].curseMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].curseMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].curseMoveSlot);
            }
            break;
        case 2:
            if (tvPtr->pos[atkSide][atkArrId].leechSeedMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].leechSeedMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].leechSeedMoveSlot);
            }
            break;
        case 3:
            if (tvPtr->mon[atkSide][atkArrId].psnMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].psnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].psnMoveSlot);
            }
            if (tvPtr->mon[atkSide][atkArrId].badPsnMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].badPsnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].badPsnMoveSlot);
            }
            break;
        case 4:
            if (tvPtr->mon[atkSide][atkArrId].brnMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].brnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].brnMoveSlot);
            }
            break;
        case 5:
            if (tvPtr->pos[atkSide][atkArrId].nightmareMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].nightmareMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].nightmareMoveSlot);
            }
            break;
        case 6:
            if (tvPtr->pos[atkSide][atkArrId].wrapMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].wrapMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].wrapMoveSlot);
            }
            break;
        case 7:
            if (tvPtr->side[atkSide].spikesMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide].spikesMonId - 1) * 4 + tvPtr->side[atkSide].spikesMoveSlot);
            }
            break;
        case 8:
            if (tvPtr->side[atkSide].futureSightMonId != 0)
            {
                AddMovePoints(20, 0, atkSide,
                (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            }
            break;
        case 9:
            if (tvPtr->side[atkSide].doomDesireMonId != 0)
            {
                AddMovePoints(20, 0, atkSide,
                (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            }
            break;
        case 10:
            if (tvPtr->side[atkSide].perishSong
                && tvPtr->side[atkSide].perishSongMonId - 1 != gBattlerPartyIndexes[gBattlerAttacker])
            {
                AddMovePoints(19, 0, atkSide,
                (tvPtr->side[atkSide].perishSongMonId - 1) * 4 + tvPtr->side[atkSide].perishSongMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].perishSong)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].perishSongMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].perishSongMoveSlot);
            }
            break;
        case 11:
            if (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId != 0)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMoveSlot);
            }
            break;
        case 12:
            for (i = 0; i < 2; i++)
            {
                if (tvPtr->pos[atkSide][i].confusionMonId != 0)
                {
                    AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                    (tvPtr->pos[atkSide][i].confusionMonId - 1) * 4 + tvPtr->pos[atkSide][i].confusionMoveSlot);
                }
            }
            break;
        case 13:
            if (tvPtr->side[atkSide].explosion)
            {
                AddMovePoints(19, 0, atkSide,
                (tvPtr->side[atkSide].explosionMonId - 1) * 4 + tvPtr->side[atkSide].explosionMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].explosion)
            {
                AddMovePoints(19, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot);
            }
            break;
        case 14:
            if (targetFainted == TRUE)
            {
                AddMovePoints(20, 0, atkSide,
                (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + tvPtr->side[atkSide].usedMoveSlot);
            }
            break;
        case 15:
            break;
        }
    }
    else
    {
        if (tvPtr->side[defSide].faintCause == 7)
        {
            if (tvPtr->side[defSide].spikesMonId != 0)
            {
                AddMovePoints(19, 0, defSide ^ BIT_SIDE,
                (tvPtr->side[defSide].spikesMonId - 1) * 4 + tvPtr->side[defSide].spikesMoveSlot);
            }
        }
        else
        {
            AddMovePoints(20, 0, atkSide,
            (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + tvPtr->side[atkSide].usedMoveSlot);
        }
    }
}

static void TrySetBattleSeminarShow(void)
{
    s32 i;
    s32 dmgByMove[4];
    u16 powerOverride;
    u16 currMoveSaved;

    if (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return;
    else if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return;
    else if (gBattleMons[gBattlerAttacker].statStages[STAT_ACC] <= 5)
        return;
    else if (gBattleMons[gBattlerTarget].statStages[STAT_EVASION] > 6)
        return;
    else if (gCurrentMove == MOVE_HIDDEN_POWER || gCurrentMove == MOVE_WEATHER_BALL)
        return;
    else if (gBattleTypeFlags & (BATTLE_TYPE_PALACE | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID))
        return;
    else if (gBattleMoves[gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]]].power == 0)
        return;

    i = 0;
    currMoveSaved = gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]];
    do
    {
        if (currMoveSaved == sVariableDmgMoves[i])
            break;
        i++;
    } while (sVariableDmgMoves[i] != 0xFFFF);

    if (sVariableDmgMoves[i] != 0xFFFF)
        return;

    dmgByMove[gMoveSelectionCursor[gBattlerAttacker]] = gBattleMoveDamage;
    currMoveSaved = gCurrentMove;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gCurrentMove = gBattleMons[gBattlerAttacker].moves[i];
        powerOverride = 0;
        if (ShouldCalculateDamage(gCurrentMove, &dmgByMove[i], &powerOverride))
        {
            gBattleMoveDamage = CalculateMoveDamage(gCurrentMove, gBattlerAttacker, gBattlerTarget, gBattleMoves[gCurrentMove].type, powerOverride, FALSE, FALSE, FALSE);
            dmgByMove[i] = gBattleMoveDamage;
            if (dmgByMove[i] == 0 && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                dmgByMove[i] = 1;
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[gMoveSelectionCursor[gBattlerAttacker]])
        {
            u16 opponentSpecies, playerSpecies;
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

            opponentSpecies = GetMonData(&gEnemyParty [gBattlerPartyIndexes[gBattlerTarget]],   MON_DATA_SPECIES, NULL);
            playerSpecies   = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_SPECIES, NULL);
            sub_80EE35C(opponentSpecies, playerSpecies, gMoveSelectionCursor[gBattlerAttacker], gBattleMons[gBattlerAttacker].moves, gBattleMons[gBattlerAttacker].moves[bestMoveId]);
            break;
        }
    }

    gBattleMoveDamage = dmgByMove[gMoveSelectionCursor[gBattlerAttacker]];
    gCurrentMove = currMoveSaved;
}

static bool8 ShouldCalculateDamage(u16 moveId, s32 *dmg, u16 *powerOverride)
{
    if (gBattleMoves[moveId].power == 0)
    {
        *dmg = 0;
        return FALSE;
    }
    else
    {
        s32 i = 0;
        do
        {
            if (moveId == sVariableDmgMoves[i])
                break;
            i++;
        } while (sVariableDmgMoves[i] != 0xFFFF);

        if (sVariableDmgMoves[i] != 0xFFFF)
        {
            *dmg = 0;
            return FALSE;
        }
        else if (moveId == MOVE_PSYWAVE)
        {
            *dmg = gBattleMons[gBattlerAttacker].level;
            *dmg /= 2;
            return FALSE;
        }
        else if (moveId == MOVE_MAGNITUDE)
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

        tvPtr->side[B_SIDE_PLAYER].faintCause = 0;
        tvPtr->side[B_SIDE_OPPONENT].faintCause = 0;

        tvPtr->side[B_SIDE_PLAYER].faintCauseMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].faintCauseMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMoveSlot = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMoveSlot = 0;

        tvPtr->side[B_SIDE_PLAYER].explosion = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosion = 0;
    }
}

u8 GetBattlerMoveSlotId(u8 battlerId, u16 moveId)
{
    s32 i;
    struct Pokemon *party;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    i = 0;
    while (1)
    {
        if (i >= MAX_MON_MOVES)
            break;
        if (GetMonData(&party[gBattlerPartyIndexes[battlerId]], MON_DATA_MOVE1 + i, NULL) == moveId)
            break;
        i++;
    }

    return i;
}

static void AddPointsBasedOnWeather(u16 weatherFlags, u16 moveId, u8 moveSlot)
{
    if (weatherFlags & WEATHER_RAIN_ANY)
        AddMovePoints(3, moveId, moveSlot, 0);
    else if (weatherFlags & WEATHER_SUN_ANY)
        AddMovePoints(4, moveId, moveSlot, 0);
    else if (weatherFlags & WEATHER_SANDSTORM_ANY)
        AddMovePoints(5, moveId, moveSlot, 0);
    else if (weatherFlags & WEATHER_HAIL_ANY)
        AddMovePoints(6, moveId, moveSlot, 0);
}

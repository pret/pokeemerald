#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_link_817C95C.h"
#include "constants/battle_string_ids.h"
#include "constants/moves.h"
#include "battle_message.h"

struct BattleLinkStringSide
{
    u32 spikesMonId:3;
    u32 reflectMoveId:3;
    u32 lightScreenMonId:3;
    u32 safeguardMonId:3;
    u32 mistMonId:3;
    u32 futureSightMonId:3;
    u32 doomDesireMonId:3;
    u32 perishSongMonId:3;
    u32 wishMonId:3;
    u32 grudgeMonId:3;
    u32 field_8_6:2;
    u32 spikesMoveSlot:2;
    u32 reflectMoveSlot:2;
    u32 lightScreenMoveSlot:2;
    u32 safeguardMoveSlot:2;
    u32 mistMoveSlot:2;
    u32 futureSightMoveSlot:2;
    u32 doomDesireMoveSlot:2;
    u32 perishSongMoveSlot:2;
    u32 wishMoveSlot:2;
    u32 grudgeMoveSlot:2;
    u32 destinyBondMonId:3;
    u32 destinyBondMoveSlot:2;
    u32 field_3_0:4;
    u32 field_3_1:3;
    u32 field_4_0_0:1;
    u32 field_4_0:2;
    u32 field_4_0_b:3;
    u32 field_4_1:1;
    u32 field_4_2:1;
    u32 field_5_0:3;
    u32 field_5_1:2;
};

struct BattleLinkStringPosition
{
    u32 curseMonId:3;
    u32 leechSeedMonId:3;
    u32 nightmareMonId:3;
    u32 wrapMonId:3;
    u32 attractMonId:3;
    u32 confusionMonId:3;
    u32 curseMoveSlot:2;
    u32 leechSeedMoveSlot:2;
    u32 nightmareMoveSlot:2;
    u32 wrapMoveSlot:2;
    u32 attractMoveSlot:2;
    u32 confusionMoveSlot:2;
    u32 waterSportMoveSlot:2;
    u32 waterSportMonId:3;
    u32 mudSportMonId:3;
    u32 mudSportMoveSlot:2;
    u32 ingrainMonId:3;
    u32 ingrainMoveSlot:2;
    u32 field_5_5:3;
    u32 field_6_0:2;
};

struct BattleLinkStringMon
{
    u32 psnMonId:3;
    u32 badPsnMonId:3;
    u32 brnMonId:3;
    u32 prlzMonId:3;
    u32 slpMonId:3;
    u32 frzMonId:3;
    u32 psnMoveSlot:2;
    u32 badPsnMoveSlot:2;
    u32 brnMoveSlot:2;
    u32 prlzMoveSlot:2;
    u32 slpMoveSlot:2;
    u32 frzMoveSlot:2;
};

struct UnknownBattleLinkStruct
{
    struct BattleLinkStringMon mon[2][6]; // [side][partyId]
    struct BattleLinkStringPosition pos[2][2]; // [side][flank]
    struct BattleLinkStringSide side[2]; // [side]
};

extern struct StringInfoBattle *gStringInfo;

extern const struct BattleMove gBattleMoves[];

// this file's functions
bool8 sub_817E0B8(u16 stringId);
void sub_817E684(u8 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_817EECC(void);
void sub_817EA80(u8 arg0);
void sub_817F394(u16 weatherFlags, u16 moveId, u8 moveSlot);

// const rom data
extern const u16 gUnknown_0860A8A4[];

// code
void sub_817C95C(u16 stringId)
{
    struct UnknownBattleLinkStruct *structPtr;
    u32 atkSide, defSide, effSide, scriptingSide;
    struct Pokemon *atkMon, *defMon;
    u8 moveSlot;
    u32 atkFlank, defFlank, effFlank;
    u8 *perishCount;
    u16 *statStringId, *finishedMoveId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && stringId != STRINGID_ITDOESNTAFFECT && stringId != STRINGID_NOTVERYEFFECTIVE)
        return;

    structPtr = (struct UnknownBattleLinkStruct*)(&gBattleStruct->field_204);

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    effSide = GetBattlerSide(gEffectBattler);
    scriptingSide = GetBattlerSide(gStringInfo->scrActive);

    if (atkSide == B_SIDE_PLAYER)
        atkMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        atkMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    if (defSide == B_SIDE_PLAYER)
        defMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerTarget]];
    else
        defMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]];

    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, gStringInfo->currentMove);

    if (moveSlot >= 4 && sub_817E0B8(stringId) && stringId > BATTLESTRINGS_ID_ADDER)
    {
        structPtr->side[atkSide].field_3_0 = 15;
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
        sub_817E684(1, moveSlot, 2, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
            sub_817EECC();
        break;
    case STRINGID_NOTVERYEFFECTIVE:
        sub_817E684(1, moveSlot, 1, 0);
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && GetMonData(defMon, MON_DATA_HP, NULL) != 0)
            sub_817EECC();
        break;
    case STRINGID_SUPEREFFECTIVE:
        sub_817E684(1, moveSlot, 0, 0);
        break;
    case STRINGID_PKMNFORESAWATTACK:
        structPtr->side[atkSide].futureSightMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].futureSightMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNCHOSEXASDESTINY:
        structPtr->side[atkSide].doomDesireMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].doomDesireMoveSlot = moveSlot;
        break;
    case STRINGID_FAINTINTHREE:
        structPtr->side[atkSide].perishSongMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].perishSongMoveSlot = moveSlot;
        structPtr->side[atkSide].field_4_1 = 1;
        break;
    case STRINGID_PKMNPERISHCOUNTFELL:
        if (*perishCount == 0)
            structPtr->side[atkSide].field_3_0 = 10;
        break;
    case STRINGID_PKMNWISHCAMETRUE:
        if (structPtr->side[defSide].wishMonId != 0)
        {
            sub_817E684(2, 3, defSide,
            (structPtr->side[defSide].wishMonId - 1) * 4 + structPtr->side[defSide].wishMoveSlot);
        }
        break;
    case STRINGID_PKMNWANTSGRUDGE:
        structPtr->side[atkSide].grudgeMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].grudgeMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOSTPPGRUDGE:
        if (structPtr->side[defSide].grudgeMonId != 0)
        {
            sub_817E684(2, 4, defSide,
            (structPtr->side[defSide].grudgeMonId - 1) * 4 + structPtr->side[defSide].grudgeMoveSlot);
        }
        break;
    case STRINGID_PKMNTRYINGTOTAKEFOE:
        structPtr->side[atkSide].destinyBondMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].destinyBondMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNTOOKFOE:
        if (structPtr->side[defSide].destinyBondMonId != 0)
            structPtr->side[atkSide].field_3_0 = 11;
        break;
    case STRINGID_PKMNPLANTEDROOTS:
        structPtr->pos[atkSide][atkFlank].ingrainMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].ingrainMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNABSORBEDNUTRIENTS:
        if (structPtr->pos[atkSide][atkFlank].ingrainMonId != 0)
        {
            sub_817E684(2, 6, atkSide,
            (structPtr->pos[atkSide][atkFlank].ingrainMonId - 1) * 4 + structPtr->pos[atkSide][atkFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNANCHOREDITSELF:
        if (structPtr->pos[defSide][defFlank].ingrainMonId != 0)
        {
            sub_817E684(2, 6, defSide,
            (structPtr->pos[defSide][defFlank].ingrainMonId - 1) * 4 + structPtr->pos[defSide][defFlank].ingrainMoveSlot);
        }
        break;
    case STRINGID_PKMNTRANSFORMEDINTO:
        gBattleStruct->field_B3 = 1;
        break;
    case STRINGID_CRITICALHIT:
        sub_817E684(0x12, moveSlot, 0, 0);
        break;
    case STRINGID_PKMNSSTATCHANGED:
        if (gBattleTextBuff1[2] != 0)
        {
            if (*statStringId == STRINGID_STATSHARPLY)
                sub_817E684(0x17, moveSlot, gBattleTextBuff1[2] - 1, 0);
            else
                sub_817E684(0x16, moveSlot, gBattleTextBuff1[2] - 1, 0);
        }
        break;
    case STRINGID_PKMNSSTATCHANGED2:
        if (gBattleTextBuff1[2] != 0)
        {
            if (gBattlerAttacker == gBattlerTarget)
            {
                if (*statStringId == STRINGID_STATSHARPLY)
                    sub_817E684(0x17, moveSlot, gBattleTextBuff1[2] - 1, 0);
                else
                    sub_817E684(0x16, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
            else
            {
                sub_817E684(0x1B, moveSlot, gBattleTextBuff1[2] - 1, 0);
            }
        }
        break;
    case STRINGID_PKMNSSTATCHANGED3:
        if (gBattleTextBuff1[2] != 0)
            sub_817E684(0x18, moveSlot, gBattleTextBuff1[2] - 1, 0);
        break;
    case STRINGID_PKMNSSTATCHANGED4:
        if (gBattleTextBuff1[2] != 0)
        {
            if (*statStringId == STRINGID_STATHARSHLY)
                sub_817E684(0x1A, moveSlot, gBattleTextBuff1[2] - 1, 0);
            else
                sub_817E684(0x19, moveSlot, gBattleTextBuff1[2] - 1, 0);
        }
        break;
    case STRINGID_PKMNLAIDCURSE:
        structPtr->pos[defSide][defFlank].curseMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].curseMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNAFFLICTEDBYCURSE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL)
            && structPtr->pos[atkSide][atkFlank].curseMonId != 0)
        {
            sub_817E684(8, 0, structPtr->pos[atkSide][atkFlank].curseMonId - 1, structPtr->pos[atkSide][atkFlank].curseMoveSlot);
            structPtr->side[atkSide].field_3_0 = 1;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNSEEDED:
        structPtr->pos[defSide][defFlank].leechSeedMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].leechSeedMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNSAPPEDBYLEECHSEED:
        if (structPtr->pos[atkSide][atkFlank].leechSeedMonId != 0)
        {
            sub_817E684(8, 1, structPtr->pos[atkSide][atkFlank].leechSeedMonId - 1, structPtr->pos[atkSide][atkFlank].leechSeedMoveSlot);
            structPtr->side[atkSide].field_3_0 = 2;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNFELLINTONIGHTMARE:
        structPtr->pos[defSide][defFlank].nightmareMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].nightmareMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNLOCKEDINNIGHTMARE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && structPtr->pos[atkSide][atkFlank].nightmareMonId != 0)
        {
            sub_817E684(8, 5, structPtr->pos[atkSide][atkFlank].nightmareMonId - 1, structPtr->pos[atkSide][atkFlank].nightmareMoveSlot);
            structPtr->side[atkSide].field_3_0 = 5;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNSQUEEZEDBYBIND:
    case STRINGID_PKMNTRAPPEDINVORTEX:
    case STRINGID_PKMNWRAPPEDBY:
    case STRINGID_PKMNCLAMPED:
    case STRINGID_PKMNTRAPPEDBYSANDTOMB:
        structPtr->pos[defSide][defFlank].wrapMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].wrapMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBY:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && structPtr->pos[atkSide][atkFlank].wrapMonId != 0)
        {
            sub_817E684(8, 6, structPtr->pos[atkSide][atkFlank].wrapMonId - 1, structPtr->pos[atkSide][atkFlank].wrapMoveSlot);
            structPtr->side[atkSide].field_3_0 = 6;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNWASBURNED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].brnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].brnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYBURN:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMonId != 0)
                sub_817E684(8, 4, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].brnMoveSlot);
            structPtr->side[atkSide].field_3_0 = 4;
            structPtr->side[atkSide].field_3_1 = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNWASPOISONED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].psnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].psnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNBADLYPOISONED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].badPsnMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].badPsnMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYPOISON:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMonId != 0)
                sub_817E684(8, 2, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].psnMoveSlot);
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMonId != 0)
                sub_817E684(8, 3, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].badPsnMoveSlot);
            structPtr->side[atkSide].field_3_0 = 3;
            structPtr->side[atkSide].field_3_1 = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNFELLINLOVE:
        structPtr->pos[defSide][defFlank].attractMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].attractMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNIMMOBILIZEDBYLOVE:
        if (structPtr->pos[atkSide][atkFlank].attractMonId != 0)
            sub_817E684(9, 0, structPtr->pos[atkSide][atkFlank].attractMonId - 1, structPtr->pos[atkSide][atkFlank].attractMoveSlot);
        break;
    case STRINGID_PKMNWASPARALYZED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].prlzMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].prlzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISPARALYZED:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMonId != 0)
            sub_817E684(9, 2, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].prlzMoveSlot);
        break;
    case STRINGID_PKMNFELLASLEEP:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].slpMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].slpMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNFASTASLEEP:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMonId != 0
            && gStringInfo->currentMove != MOVE_SNORE
            && gStringInfo->currentMove != MOVE_SLEEP_TALK)
            sub_817E684(9, 3, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].slpMoveSlot);
        break;
    case STRINGID_PKMNWASFROZEN:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].frzMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].frzMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNISFROZEN:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMonId != 0)
            sub_817E684(9, 4, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMonId - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].frzMoveSlot);
        break;
    case STRINGID_PKMNWASCONFUSED:
        structPtr->pos[effSide][effFlank].confusionMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[effSide][effFlank].confusionMoveSlot = moveSlot;
        break;
    case STRINGID_ITHURTCONFUSION:
        if (structPtr->pos[atkSide][atkFlank].confusionMonId != 0)
            sub_817E684(9, 1, structPtr->pos[atkSide][atkFlank].confusionMonId - 1, structPtr->pos[atkSide][atkFlank].confusionMoveSlot);
        structPtr->side[atkSide].field_3_0 = 12;
        break;
    case STRINGID_SPIKESSCATTERED:
        structPtr->side[defSide].spikesMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[defSide].spikesMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNHURTBYSPIKES:
        if (structPtr->side[scriptingSide].spikesMonId != 0)
        {
            sub_817E684(10, scriptingSide ^ BIT_SIDE, structPtr->side[scriptingSide].spikesMonId - 1, structPtr->side[scriptingSide].spikesMoveSlot);
            structPtr->side[scriptingSide].field_3_0 = 7;
        }
        break;
    case STRINGID_PKMNBLEWAWAYSPIKES:
        structPtr->side[atkSide].spikesMonId = 0;
        structPtr->side[atkSide].spikesMoveSlot = 0;
        break;
    case STRINGID_FIREWEAKENED:
        structPtr->pos[atkSide][atkFlank].waterSportMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].waterSportMoveSlot = moveSlot;
        break;
    case STRINGID_ELECTRICITYWEAKENED:
        structPtr->pos[atkSide][atkFlank].mudSportMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].mudSportMoveSlot = moveSlot;
        break;
    case STRINGID_ATTACKERFAINTED:
        sub_817EA80(0);
    case STRINGID_RETURNMON:
        if (structPtr->pos[atkSide][atkFlank].waterSportMonId != 0)
        {
            structPtr->pos[atkSide][atkFlank].waterSportMonId = 0;
            structPtr->pos[atkSide][atkFlank].waterSportMoveSlot = 0;
        }
        if (structPtr->pos[atkSide][atkFlank].mudSportMonId != 0)
        {
            structPtr->pos[atkSide][atkFlank].mudSportMonId = 0;
            structPtr->pos[atkSide][atkFlank].mudSportMoveSlot = 0;
        }
        break;
    case STRINGID_TARGETFAINTED:
        sub_817EA80(1);
        if (structPtr->pos[atkSide][defFlank].waterSportMonId != 0)
        {
            structPtr->pos[atkSide][defFlank].waterSportMonId = 0;
            structPtr->pos[atkSide][defFlank].waterSportMoveSlot = 0;
        }
        if (structPtr->pos[atkSide][defFlank].mudSportMonId != 0)
        {
            structPtr->pos[atkSide][defFlank].mudSportMonId = 0;
            structPtr->pos[atkSide][defFlank].mudSportMoveSlot = 0;
        }
        break;
    case STRINGID_PKMNRAISEDDEF:
    case STRINGID_PKMNRAISEDDEFALITTLE:
        structPtr->side[atkSide].reflectMoveId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].reflectMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNRAISEDSPDEF:
    case STRINGID_PKMNRAISEDSPDEFALITTLE:
        structPtr->side[atkSide].lightScreenMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].lightScreenMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNSXWOREOFF:
        if (*finishedMoveId == MOVE_REFLECT)
        {
            structPtr->side[atkSide].reflectMoveId = 0;
            structPtr->side[atkSide].reflectMoveSlot = 0;
        }
        if (*finishedMoveId == MOVE_LIGHT_SCREEN)
        {
            structPtr->side[atkSide].lightScreenMonId = 0;
            structPtr->side[atkSide].lightScreenMoveSlot = 0;
        }
        if (*finishedMoveId == MOVE_MIST)
        {
            structPtr->side[atkSide].mistMonId = 0;
            structPtr->side[atkSide].mistMoveSlot = 0;
        }
        break;
    case STRINGID_PKMNCOVEREDBYVEIL:
        structPtr->side[atkSide].safeguardMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].safeguardMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNUSEDSAFEGUARD:
        if (structPtr->side[defSide].safeguardMonId != 0)
            sub_817E684(15, 0, structPtr->side[defSide].safeguardMonId - 1, structPtr->side[defSide].safeguardMoveSlot);
        break;
    case STRINGID_PKMNSAFEGUARDEXPIRED:
        structPtr->side[atkSide].safeguardMonId = 0;
        structPtr->side[atkSide].safeguardMoveSlot = 0;
        break;
    case STRINGID_PKMNSHROUDEDINMIST:
        structPtr->side[atkSide].mistMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].mistMoveSlot = moveSlot;
        break;
    case STRINGID_PKMNPROTECTEDBYMIST:
        if (structPtr->side[defSide].mistMonId != 0)
            sub_817E684(16, 0, structPtr->side[defSide].mistMonId - 1, structPtr->side[defSide].mistMoveSlot);
        break;
    case STRINGID_THEWALLSHATTERED:
        structPtr->side[defSide].reflectMoveId = 0;
        structPtr->side[defSide].reflectMoveSlot = 0;
        structPtr->side[defSide].lightScreenMonId = 0;
        structPtr->side[defSide].lightScreenMoveSlot = 0;
        sub_817E684(17, 0, gBattlerPartyIndexes[gBattlerAttacker], moveSlot);
        break;
    case STRINGID_PKMNFLINCHED:
        if (structPtr->pos[atkSide][0].field_5_5 != 0)
            sub_817E684(21, 0, structPtr->pos[atkSide][0].field_5_5 - 1, structPtr->pos[atkSide][0].field_6_0);
        if (structPtr->pos[atkSide][1].field_5_5 != 0)
            sub_817E684(21, 0, structPtr->pos[atkSide][1].field_5_5 - 1, structPtr->pos[atkSide][1].field_6_0);
        break;
    case STRINGID_PKMNCRASHED:
    case STRINGID_PKMNHITWITHRECOIL:
        structPtr->side[atkSide].field_3_0 = 14;
        break;
    }
}

bool8 sub_817E0B8(u16 stringId)
{
    s32 i = 0;

    while (1)
    {
        if (gUnknown_0860A8A4[i] == stringId)
            break;
        i++;
        if (gUnknown_0860A8A4[i] == 0xFFFF)
            break;
    }

    if (gUnknown_0860A8A4[i] == 0xFFFF)
        return TRUE;
    else
        return FALSE;
}

void sub_817E0FC(u16 move, u16 weatherFlags, struct DisableStruct *disableStructPtr)
{
    struct UnknownBattleLinkStruct *structPtr;
    u32 atkSide, defSide;
    u8 moveSlot;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    structPtr = (struct UnknownBattleLinkStruct*)(&gBattleStruct->field_204);

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, move);

    if (moveSlot >= 4)
    {
        structPtr->side[atkSide].field_3_0 = 15;
        return;
    }

    structPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].field_5_5 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
    structPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].field_6_0 = moveSlot;
    structPtr->side[atkSide].field_8_6 = moveSlot;
    sub_817E684(0, moveSlot, gBattleMoves[move].effect, 0);
    sub_817F394(weatherFlags, move, moveSlot);
    if (disableStructPtr->chargeTimer1 != 0)
        sub_817E684(7, move, moveSlot, 0);

    if (move == MOVE_WISH)
    {
        structPtr->side[atkSide].wishMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].wishMoveSlot = moveSlot;
    }
    if (move == MOVE_SELF_DESTRUCT || move == MOVE_EXPLOSION)
    {
        structPtr->side[atkSide ^ BIT_SIDE].field_4_0_b = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide ^ BIT_SIDE].field_4_0 = moveSlot;
        structPtr->side[atkSide ^ BIT_SIDE].field_3_0 = 13;
        structPtr->side[atkSide ^ BIT_SIDE].field_4_0_0 = 1;
    }

    sub_817E684(13, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    sub_817E684(14, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    sub_817E684(11, gBattleMoves[move].type, 0,                        0);
    sub_817E684(12, gBattleMoves[move].type, 0,                        0);
}

#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_link_817C95C.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_anim.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "battle_message.h"
#include "tv.h"

extern struct StringInfoBattle *gStringInfo;

extern const struct BattleMove gBattleMoves[];

// this file's functions
bool8 sub_817E0B8(u16 stringId);
void sub_817E684(u8 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_817EECC(void);
void sub_817EA80(u8 arg0);
void sub_817F394(u16 weatherFlags, u16 moveId, u8 moveSlot);
bool8 sub_817F21C(u16 moveId, s32 *dmg, u16 *powerOverride);

// const rom data
extern const u16 *const gUnknown_0860A834[];
extern const u16 gUnknown_0860A8A4[];
extern const u16 gUnknown_0860A4AC[];

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

    structPtr = &gBattleStruct->field_204;

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
        structPtr->side[atkSide].perishSong = 1;
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
        structPtr->side[atkSide].reflectMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
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
            structPtr->side[atkSide].reflectMonId = 0;
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
        structPtr->side[defSide].reflectMonId = 0;
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

    structPtr = &gBattleStruct->field_204;

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
        structPtr->side[atkSide ^ BIT_SIDE].explosionMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot = moveSlot;
        structPtr->side[atkSide ^ BIT_SIDE].field_3_0 = 13;
        structPtr->side[atkSide ^ BIT_SIDE].explosion = 1;
    }

    sub_817E684(13, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    sub_817E684(14, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    sub_817E684(11, gBattleMoves[move].type, 0,                        0);
    sub_817E684(12, gBattleMoves[move].type, 0,                        0);
}

void sub_817E32C(u8 animationId)
{
    struct UnknownBattleLinkStruct *structPtr;
    u32 atkSide;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    structPtr = &gBattleStruct->field_204;
    atkSide = GetBattlerSide(gBattlerAttacker);
    switch (animationId)
    {
    case B_ANIM_FUTURE_SIGHT_HIT:
        if (structPtr->side[atkSide].futureSightMonId != 0)
        {
            sub_817E684(2, 0, atkSide,
                        (structPtr->side[atkSide].futureSightMonId - 1) * 4 + structPtr->side[atkSide].futureSightMoveSlot);
            structPtr->side[atkSide].field_3_0 = 8;
        }
        break;
    case B_ANIM_DOOM_DESIRE_HIT:
        if (structPtr->side[atkSide].doomDesireMonId != 0)
        {
            sub_817E684(2, 1, atkSide,
                        (structPtr->side[atkSide].doomDesireMonId - 1) * 4 + structPtr->side[atkSide].doomDesireMoveSlot);
            structPtr->side[atkSide].field_3_0 = 9;
        }
        break;
    }
}

#ifdef NONMATCHING
// for loop has an unused stack variable
void sub_817E3F4(void)
{
    u16 playerBestSpecies = 0, opponentBestSpecies = 0;
    s16 playerBestSum = 0, opponentBestSum = SHRT_MAX;
    u8 playerBestMonId = 0, opponentBestMonId = 0;
    struct UnknownBattleLinkArrayStruct *array = NULL;
    u8 countPlayer = 0, countOpponent = 0;
    s16 sum = 0;
    u16 species = 0;
    u16 moveId = 0;
    s32 i, j;

    if (gBattleStruct->field_B3)
        return;

    array = &gBattleStruct->field_1A4;
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
            for (sum = 0, j = 0; j < 4; j++)
                sum += array->unk0[0][i * 4 + j];

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
            s32 id = 1;
            for (sum = 0, j = 0; j < 4; j++)
                sum += array->unk0[id][i * 4 + j];

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

    for (sum = 0, i = 0, j = 0; j < 4; j++)
    {
        if (sum < array->unk0[0][playerBestMonId * 4 + j])
        {
            sum = array->unk0[0][playerBestMonId * 4 + j];
            i = j;
        }
    }

    moveId = GetMonData(&gPlayerParty[playerBestMonId], MON_DATA_MOVE1 + i, NULL);
    if (playerBestSum == 0 || moveId == 0)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((playerBestMonId < 3 && !sub_806D82C(gBattleScripting.multiplayerId))
            || (playerBestMonId >= 3 && sub_806D82C(gBattleScripting.multiplayerId)))
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
ASM_DIRECT
void sub_817E3F4(void)
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
	bl sub_806D82C\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _0817E630\n\
	b _0817E670\n\
	.pool\n\
_0817E620:\n\
	ldr r0, =gBattleScripting\n\
	adds r0, 0x25\n\
	ldrb r0, [r0]\n\
	bl sub_806D82C\n\
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

void sub_817E684(u8 caseId, u16 arg1, u8 arg2, u8 arg3)
{
    struct UnknownBattleLinkArrayStruct *array = &gBattleStruct->field_1A4;
    struct UnknownBattleLinkStruct *structPtr = &gBattleStruct->field_204;
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
        array->unk0[atkSide][gBattlerPartyIndexes[gBattlerAttacker] * 4 + arg1] += gUnknown_0860A834[caseId][arg2];
        break;
    case 3 ... 7:
        i = 0;
        ptr = gUnknown_0860A834[caseId];
        do
        {
            if (arg1 == ptr[i])
            {
                array->unk0[atkSide][gBattlerPartyIndexes[gBattlerAttacker] * 4 + arg2] += ptr[i+1];
                break;
            }
            i += 2;
        } while (ptr[i] != 0xFFFF);
        break;
    case 19:
        structPtr->side[arg2 ^ 1].field_3_0 = 0;
        array->unk0[arg2][0 * 4 + arg3] += gUnknown_0860A834[caseId][arg1];
        break;
    case 20:
        structPtr->side[arg2].field_3_0 = 0;
    case 2:
        array->unk0[arg2][0 * 4 + arg3] += gUnknown_0860A834[caseId][arg1];
        break;
    case 17:
        array->unk0[atkSide][arg2 * 4 + arg3] += gUnknown_0860A834[caseId][arg1];
        break;
    case 8:
    case 9:
    case 15:
    case 16:
    case 21:
        array->unk0[atkSide ^ BIT_SIDE][arg2 * 4 + arg3] += gUnknown_0860A834[caseId][arg1];
        break;
    case 10:
        array->unk0[arg1][arg2 * 4 + arg3] += gUnknown_0860A834[caseId][0];
        break;
    case 11:
        if (structPtr->pos[defSide][0].waterSportMonId != -(structPtr->pos[defSide][1].waterSportMonId) && arg1 == 10)
        {
            if (structPtr->pos[defSide][0].waterSportMonId != 0)
            {
                u32 id = (structPtr->pos[defSide][0].waterSportMonId - 1) * 4;
                array->unk0[defSide][id + structPtr->pos[defSide][0].waterSportMoveSlot] += gUnknown_0860A834[caseId][0];
            }
            if (structPtr->pos[defSide][1].waterSportMonId != 0)
            {
                u32 id = (structPtr->pos[defSide][1].waterSportMonId - 1) * 4;
                array->unk0[defSide][id + structPtr->pos[defSide][1].waterSportMoveSlot] += gUnknown_0860A834[caseId][0];
            }
        }
        break;
    case 12:
        if (structPtr->pos[defSide][0].mudSportMonId != -(structPtr->pos[defSide][1].mudSportMonId) && arg1 == 13)
        {
            if (structPtr->pos[defSide][0].mudSportMonId != 0)
            {
                u32 id = (structPtr->pos[defSide][0].mudSportMonId - 1) * 4;
                array->unk0[defSide][id + structPtr->pos[defSide][0].mudSportMoveSlot] += gUnknown_0860A834[caseId][0];
            }
            if (structPtr->pos[defSide][1].mudSportMonId != 0)
            {
                u32 id = (structPtr->pos[defSide][1].mudSportMonId - 1) * 4;
                array->unk0[defSide][id + structPtr->pos[defSide][1].mudSportMoveSlot] += gUnknown_0860A834[caseId][0];
            }
        }
        break;
    case 13:
        if (arg1 <= 8 && arg2 != 0 && structPtr->side[defSide].reflectMonId != 0)
        {
            u32 id = (structPtr->side[defSide].reflectMonId - 1) * 4;
            array->unk0[defSide][id + structPtr->side[defSide].reflectMoveSlot] += gUnknown_0860A834[caseId][0];
        }
        break;
    case 14:
        if (arg1 > 8 && arg2 != 0 && structPtr->side[defSide].lightScreenMonId != 0)
        {
            u32 id = (structPtr->side[defSide].lightScreenMonId - 1) * 4;
            array->unk0[defSide][id + structPtr->side[defSide].lightScreenMoveSlot] += gUnknown_0860A834[caseId][0];
        }
        break;
        break;
    }
}

void sub_817EA80(u8 arg0)
{
    struct UnknownBattleLinkStruct *structPtr = &gBattleStruct->field_204;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    u32 atkArrId = structPtr->side[atkSide].field_3_1;
    s32 i;

    if (structPtr->side[atkSide].field_3_0 != 0)
    {
        switch (structPtr->side[atkSide].field_3_0)
        {
        case 1:
            if (structPtr->pos[atkSide][atkArrId].curseMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->pos[atkSide][atkArrId].curseMonId - 1) * 4 + structPtr->pos[atkSide][atkArrId].curseMoveSlot);
            }
            break;
        case 2:
            if (structPtr->pos[atkSide][atkArrId].leechSeedMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->pos[atkSide][atkArrId].leechSeedMonId - 1) * 4 + structPtr->pos[atkSide][atkArrId].leechSeedMoveSlot);
            }
            break;
        case 3:
            if (structPtr->mon[atkSide][atkArrId].psnMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->mon[atkSide][atkArrId].psnMonId - 1) * 4 + structPtr->mon[atkSide][atkArrId].psnMoveSlot);
            }
            if (structPtr->mon[atkSide][atkArrId].badPsnMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->mon[atkSide][atkArrId].badPsnMonId - 1) * 4 + structPtr->mon[atkSide][atkArrId].badPsnMoveSlot);
            }
            break;
        case 4:
            if (structPtr->mon[atkSide][atkArrId].brnMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->mon[atkSide][atkArrId].brnMonId - 1) * 4 + structPtr->mon[atkSide][atkArrId].brnMoveSlot);
            }
            break;
        case 5:
            if (structPtr->pos[atkSide][atkArrId].nightmareMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->pos[atkSide][atkArrId].nightmareMonId - 1) * 4 + structPtr->pos[atkSide][atkArrId].nightmareMoveSlot);
            }
            break;
        case 6:
            if (structPtr->pos[atkSide][atkArrId].wrapMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->pos[atkSide][atkArrId].wrapMonId - 1) * 4 + structPtr->pos[atkSide][atkArrId].wrapMoveSlot);
            }
            break;
        case 7:
            if (structPtr->side[atkSide].spikesMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->side[atkSide].spikesMonId - 1) * 4 + structPtr->side[atkSide].spikesMoveSlot);
            }
            break;
        case 8:
            if (structPtr->side[atkSide].futureSightMonId != 0)
            {
                sub_817E684(20, 0, atkSide,
                (structPtr->side[atkSide].futureSightMonId - 1) * 4 + structPtr->side[atkSide].futureSightMoveSlot);
            }
            break;
        case 9:
            if (structPtr->side[atkSide].doomDesireMonId != 0)
            {
                sub_817E684(20, 0, atkSide,
                (structPtr->side[atkSide].doomDesireMonId - 1) * 4 + structPtr->side[atkSide].doomDesireMoveSlot);
            }
            break;
        case 10:
            if (structPtr->side[atkSide].perishSong
                && structPtr->side[atkSide].perishSongMonId - 1 != gBattlerPartyIndexes[gBattlerAttacker])
            {
                sub_817E684(19, 0, atkSide,
                (structPtr->side[atkSide].perishSongMonId - 1) * 4 + structPtr->side[atkSide].perishSongMoveSlot);
            }
            if (structPtr->side[atkSide ^ BIT_SIDE].perishSong)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->side[atkSide ^ BIT_SIDE].perishSongMonId - 1) * 4 + structPtr->side[atkSide ^ BIT_SIDE].perishSongMoveSlot);
            }
            break;
        case 11:
            if (structPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId != 0)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId - 1) * 4 + structPtr->side[atkSide ^ BIT_SIDE].destinyBondMoveSlot);
            }
            break;
        case 12:
            for (i = 0; i < 2; i++)
            {
                if (structPtr->pos[atkSide][i].confusionMonId != 0)
                {
                    sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                    (structPtr->pos[atkSide][i].confusionMonId - 1) * 4 + structPtr->pos[atkSide][i].confusionMoveSlot);
                }
            }
            break;
        case 13:
            if (structPtr->side[atkSide].explosion)
            {
                sub_817E684(19, 0, atkSide,
                (structPtr->side[atkSide].explosionMonId - 1) * 4 + structPtr->side[atkSide].explosionMoveSlot);
            }
            if (structPtr->side[atkSide ^ BIT_SIDE].explosion)
            {
                sub_817E684(19, 0, atkSide ^ BIT_SIDE,
                (structPtr->side[atkSide ^ BIT_SIDE].explosionMonId - 1) * 4 + structPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot);
            }
            break;
        case 14:
            if (arg0 == 1)
            {
                sub_817E684(20, 0, atkSide,
                (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + structPtr->side[atkSide].field_8_6);
            }
            break;
        case 15:
            break;
        }
    }
    else
    {
        if (structPtr->side[defSide].field_3_0 == 7)
        {
            if (structPtr->side[defSide].spikesMonId != 0)
            {
                sub_817E684(19, 0, defSide ^ BIT_SIDE,
                (structPtr->side[defSide].spikesMonId - 1) * 4 + structPtr->side[defSide].spikesMoveSlot);
            }
        }
        else
        {
            sub_817E684(20, 0, atkSide,
            (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + structPtr->side[atkSide].field_8_6);
        }
    }
}

void sub_817EECC(void)
{
    s32 i;
    s32 dmgByMove[4];
    u16 powerOverride;
    u16 currMoveSaved;

    if (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return;
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return;
    if (gBattleMons[gBattlerAttacker].statStages[STAT_ACC] <= 5)
        return;
    if (gBattleMons[gBattlerTarget].statStages[STAT_EVASION] > 6)
        return;
    if (gCurrentMove == MOVE_HIDDEN_POWER || gCurrentMove == MOVE_WEATHER_BALL)
        return;
    if (gBattleTypeFlags & (BATTLE_TYPE_PALACE | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID))
        return;
    if (gBattleMoves[gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]]].power == 0)
        return;

    i = 0;
    currMoveSaved = gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]];
    while (1)
    {
        if (currMoveSaved == gUnknown_0860A4AC[i])
            break;
        i++;
        if (gUnknown_0860A4AC[i] == 0xFFFF)
            break;
    }

    if (gUnknown_0860A4AC[i] != 0xFFFF)
        return;

    dmgByMove[gMoveSelectionCursor[gBattlerAttacker]] = gBattleMoveDamage;
    currMoveSaved = gCurrentMove;
    for (i = 0; i < 4; i++)
    {
        gCurrentMove = gBattleMons[gBattlerAttacker].moves[i];
        powerOverride = 0;
        if (sub_817F21C(gCurrentMove, &dmgByMove[i], &powerOverride))
        {
            u8 moveResultFlags;
            u16 sideStatus = gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)];
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBattlerAttacker], &gBattleMons[gBattlerTarget], gCurrentMove,
                                                    sideStatus, powerOverride,
                                                    0, gBattlerAttacker, gBattlerTarget);

            if (gStatuses3[gBattlerAttacker] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
                gBattleMoveDamage *= 2;
            if (gProtectStructs[gBattlerAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            moveResultFlags = TypeCalc(gCurrentMove, gBattlerAttacker, gBattlerTarget);
            dmgByMove[i] = gBattleMoveDamage;
            if (dmgByMove[i] == 0 && !(moveResultFlags & MOVE_RESULT_NO_EFFECT))
                dmgByMove[i] = 1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[gMoveSelectionCursor[gBattlerAttacker]])
        {
            u16 opponentSpecies, playerSpecies;
            s32 bestMoveId;

            if (gMoveSelectionCursor[gBattlerAttacker] != 0)
                bestMoveId = 0;
            else
                bestMoveId = 1;

            for (i = 0; i < 4; i++)
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

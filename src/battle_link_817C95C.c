#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_link_817C95C.h"
#include "constants/battle_string_ids.h"
#include "constants/moves.h"
#include "battle_message.h"

struct BattleLinkStringSide
{
    u32 field_8_0:3; // correct
    u32 field_8_0_b:3; // correct
    u32 field_8_0_c:3; // correct
    u32 field_8_0_d:3;
    u32 field_8_0_e:3;
    u32 field_8_1:3; // correct
    u32 field_8_2:3; // correct
    u32 field_8_3:3; // correct
    u32 field_8_4:3; // correct
    u32 field_8_5:3; // correct
    u32 field_8_6:2;

    u32 field_0_0a:2; // correct
    u32 field_0_0b:2; // correct
    u32 field_0_0c:2; // correct
    u32 field_0_0d:2;
    u32 field_0_0e:2;
    u32 field_0_1:2; // correct
    u32 field_0_2:2; // correct
    u32 field_0_3:2; // correct
    u32 field_0_4:2; // correct
    u32 field_0_5:2; // correct
    u32 field_0_6:3; // correct
    u32 field_0_7:2; // correct

    u32 field_3_0:4; // correct
    u32 field_3_1:3; // correct

    u32 field_4_0:6;
    u32 field_4_1:1;
    u32 field_4_2:1;

    u32 field_5_0:3; // correct
    u32 field_5_1:2; // correct
};

struct BattleLinkStringPosition
{
    u32 field_0_0:3; // correct
    u32 field_0_3:3; // correct
    u32 field_0_6:3; // correct
    u32 field_1_1:3; // correct
    u32 field_1_4:3; // correct
    u32 field_2_0:3;
    u32 field_2_3:2; // correct
    u32 field_2_5:2; // correct
    u32 field_2_7:2; // correct
    u32 field_3_0:2; // correct
    u32 field_3_2:2; // correct
    u32 field_3_4:2;
    u32 field_3_6:2;
    u32 field_4_0:3;
    u32 field_4_3:3;
    u32 field_4_6:2;
    u32 field_5_0:3; // correct
    u32 field_5_3:2; // correct
    u32 field_5_5:3; // correct
    u32 field_6_0:2;
};

struct BattleLinkStringMon
{
    u32 field_0_0:3; // correct
    u32 field_0_3:3; // correct
    u32 field_0_6:3; // correct
    u32 field_1_1:3; // correct
    u32 field_1_4:3; // correct
    u32 field_1_7:3;
    u32 field_2_2:2;
    u32 field_2_4:2; // correct
    u32 field_2_6:2; // correct
    u32 field_3_0:2; // correct
    u32 field_3_2:2; // correct
    u32 field_3_4:2;
    u32 field_3_6:2;
};

struct UnknownBattleLinkStruct
{
    struct BattleLinkStringMon mon[2][6]; // [side][partyId]
    struct BattleLinkStringPosition pos[2][2]; // [side][flank]
    struct BattleLinkStringSide side[2]; // [side]
};

extern struct StringInfoBattle *gStringInfo;

// this file's functions
bool8 sub_817E0B8(u16 stringId);
void sub_817E684(u8 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_817EECC(void);
void sub_817EA80(u8 arg0);

void sub_817C95C(u16 stringId)
{
    struct UnknownBattleLinkStruct *structPtr;
    u32 atkSide, defSide, effSide, scriptingSide;
    struct Pokemon *atkMon, *defMon;
    u8 moveSlot;
    u32 atkFlank, defFlank, effFlank;

    register void *var1 asm("r1"), *var2 asm("r2");

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
        structPtr->side[atkSide].field_8_1 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_1 = moveSlot;
        break;
    case STRINGID_PKMNCHOSEXASDESTINY:
        structPtr->side[atkSide].field_8_2 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_2 = moveSlot;
        break;
    case STRINGID_FAINTINTHREE:
        structPtr->side[atkSide].field_8_3 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_3 = moveSlot;
        structPtr->side[atkSide].field_4_1 = 1;
        break;
    case STRINGID_PKMNPERISHCOUNTFELL:
        var1 = gBattleTextBuff1 + 4;
        if (*(u8*)(var1) == 0)
            structPtr->side[atkSide].field_3_0 = 10;
        break;
    case STRINGID_PKMNWISHCAMETRUE:
        if (structPtr->side[defSide].field_8_4 != 0)
        {
            sub_817E684(2, 3, defSide,
            (structPtr->side[defSide].field_8_4 - 1) * 4 + structPtr->side[defSide].field_0_4);
        }
        break;
    case STRINGID_PKMNWANTSGRUDGE:
        structPtr->side[atkSide].field_8_5 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_5 = moveSlot;
        break;
    case STRINGID_PKMNLOSTPPGRUDGE:
        if (structPtr->side[defSide].field_8_5 != 0)
        {
            sub_817E684(2, 4, defSide,
            (structPtr->side[defSide].field_8_5 - 1) * 4 + structPtr->side[defSide].field_0_5);
        }
        break;
    case STRINGID_PKMNTRYINGTOTAKEFOE:
        structPtr->side[atkSide].field_0_6 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_7 = moveSlot;
        break;
    case STRINGID_PKMNTOOKFOE:
        if (structPtr->side[defSide].field_0_6 != 0)
            structPtr->side[atkSide].field_3_0 = 11;
        break;
    case STRINGID_PKMNPLANTEDROOTS:
        structPtr->pos[atkSide][atkFlank].field_5_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].field_5_3 = moveSlot;
        break;
    case STRINGID_PKMNABSORBEDNUTRIENTS:
        if (structPtr->pos[atkSide][atkFlank].field_5_0 != 0)
        {
            sub_817E684(2, 6, atkSide,
            (structPtr->pos[atkSide][atkFlank].field_5_0 - 1) * 4 + structPtr->pos[atkSide][atkFlank].field_5_3);
        }
        break;
    case STRINGID_PKMNANCHOREDITSELF:
        if (structPtr->pos[defSide][defFlank].field_5_0 != 0)
        {
            sub_817E684(2, 6, defSide,
            (structPtr->pos[defSide][defFlank].field_5_0 - 1) * 4 + structPtr->pos[defSide][defFlank].field_5_3);
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
            var1 = gBattleTextBuff2 + 2;
            if (*(u16*)(var1) == STRINGID_STATSHARPLY)
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
                var1 = gBattleTextBuff2 + 2;
                if (*(u16*)(var1) == STRINGID_STATSHARPLY)
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
            var1 = gBattleTextBuff2 + 2;
            if (*(u16*)(var1) == STRINGID_STATHARSHLY)
                sub_817E684(0x1A, moveSlot, gBattleTextBuff1[2] - 1, 0);
            else
                sub_817E684(0x19, moveSlot, gBattleTextBuff1[2] - 1, 0);
        }
        break;
    case STRINGID_PKMNLAIDCURSE:
        structPtr->pos[defSide][defFlank].field_0_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].field_2_3 = moveSlot;
        break;
    case STRINGID_PKMNAFFLICTEDBYCURSE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL)
            && structPtr->pos[atkSide][atkFlank].field_0_0 != 0)
        {
            sub_817E684(8, 0, structPtr->pos[atkSide][atkFlank].field_0_0 - 1, structPtr->pos[atkSide][atkFlank].field_2_3);
            structPtr->side[atkSide].field_3_0 = 1;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNSEEDED:
        structPtr->pos[defSide][defFlank].field_0_3 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].field_2_5 = moveSlot;
        break;
    case STRINGID_PKMNSAPPEDBYLEECHSEED:
        if (structPtr->pos[atkSide][atkFlank].field_0_3 != 0)
        {
            sub_817E684(8, 1, structPtr->pos[atkSide][atkFlank].field_0_3 - 1, structPtr->pos[atkSide][atkFlank].field_2_5);
            structPtr->side[atkSide].field_3_0 = 2;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNFELLINTONIGHTMARE:
        structPtr->pos[defSide][defFlank].field_0_6 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].field_2_7 = moveSlot;
        break;
    case STRINGID_PKMNLOCKEDINNIGHTMARE:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && structPtr->pos[atkSide][atkFlank].field_0_6 != 0)
        {
            sub_817E684(8, 5, structPtr->pos[atkSide][atkFlank].field_0_6 - 1, structPtr->pos[atkSide][atkFlank].field_2_7);
            structPtr->side[atkSide].field_3_0 = 5;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNSQUEEZEDBYBIND:
    case STRINGID_PKMNTRAPPEDINVORTEX:
    case STRINGID_PKMNWRAPPEDBY:
    case STRINGID_PKMNCLAMPED:
    case STRINGID_PKMNTRAPPEDBYSANDTOMB:
        structPtr->pos[defSide][defFlank].field_1_1 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].field_3_0 = moveSlot;
        break;
    case STRINGID_PKMNHURTBY:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
            && structPtr->pos[atkSide][atkFlank].field_1_1 != 0)
        {
            sub_817E684(8, 6, structPtr->pos[atkSide][atkFlank].field_1_1 - 1, structPtr->pos[atkSide][atkFlank].field_3_0);
            structPtr->side[atkSide].field_3_0 = 6;
            structPtr->side[atkSide].field_3_1 = atkFlank;
        }
        break;
    case STRINGID_PKMNWASBURNED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_0_6 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_2_6 = moveSlot;
        break;
    case STRINGID_PKMNHURTBYBURN:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_6 != 0)
                sub_817E684(8, 4, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_6 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_2_6);
            structPtr->side[atkSide].field_3_0 = 4;
            structPtr->side[atkSide].field_3_1 = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNWASPOISONED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_0_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_2_2 = moveSlot;
        break;
    case STRINGID_PKMNBADLYPOISONED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_0_3 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_2_4 = moveSlot;
        break;
    case STRINGID_PKMNHURTBYPOISON:
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0)
        {
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_0 != 0)
                sub_817E684(8, 2, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_0 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_2_2);
            if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_3 != 0)
                sub_817E684(8, 3, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_0_3 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_2_4);
            structPtr->side[atkSide].field_3_0 = 3;
            structPtr->side[atkSide].field_3_1 = gBattlerPartyIndexes[gBattlerAttacker];
        }
        break;
    case STRINGID_PKMNFELLINLOVE:
        structPtr->pos[defSide][defFlank].field_1_4 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[defSide][defFlank].field_3_2 = moveSlot;
        break;
    case STRINGID_PKMNIMMOBILIZEDBYLOVE:
        if (structPtr->pos[atkSide][atkFlank].field_1_4 != 0)
            sub_817E684(9, 0, structPtr->pos[atkSide][atkFlank].field_1_4 - 1, structPtr->pos[atkSide][atkFlank].field_3_2);
        break;
    case STRINGID_PKMNWASPARALYZED:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_1_1 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_3_0 = moveSlot;
        break;
    case STRINGID_PKMNISPARALYZED:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_1 != 0)
            sub_817E684(9, 2, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_1 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_3_0);
        break;
    case STRINGID_PKMNFELLASLEEP:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_1_4 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_3_2 = moveSlot;
        break;
    case STRINGID_PKMNFASTASLEEP:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_4 != 0
            && gStringInfo->currentMove != MOVE_SNORE
            && gStringInfo->currentMove != MOVE_SLEEP_TALK)
            sub_817E684(9, 3, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_4 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_3_2);
        break;
    case STRINGID_PKMNWASFROZEN:
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_1_7 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->mon[effSide][gBattlerPartyIndexes[gEffectBattler]].field_3_4 = moveSlot;
        break;
    case STRINGID_PKMNISFROZEN:
        if (structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_7 != 0)
            sub_817E684(9, 4, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_1_7 - 1, structPtr->mon[atkSide][gBattlerPartyIndexes[gBattlerAttacker]].field_3_4);
        break;
    case STRINGID_PKMNWASCONFUSED:
        structPtr->pos[effSide][effFlank].field_2_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[effSide][effFlank].field_3_4 = moveSlot;
        break;
    case STRINGID_ITHURTCONFUSION:
        if (structPtr->pos[atkSide][atkFlank].field_2_0 != 0)
            sub_817E684(9, 1, structPtr->pos[atkSide][atkFlank].field_2_0 - 1, structPtr->pos[atkSide][atkFlank].field_3_4);
        structPtr->side[atkSide].field_3_0 = 12;
        break;
    case STRINGID_SPIKESSCATTERED:
        structPtr->side[defSide].field_8_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[defSide].field_0_0a = moveSlot;
        break;
    case STRINGID_PKMNHURTBYSPIKES:
        if (structPtr->side[scriptingSide].field_8_0 != 0)
        {
            sub_817E684(10, scriptingSide ^ BIT_SIDE, structPtr->side[scriptingSide].field_8_0 - 1, structPtr->side[scriptingSide].field_0_0a);
            structPtr->side[scriptingSide].field_3_0 = 7;
        }
        break;
    case STRINGID_PKMNBLEWAWAYSPIKES:
        structPtr->side[atkSide].field_8_0 = 0;
        structPtr->side[atkSide].field_0_0a = 0;
        break;
    case STRINGID_FIREWEAKENED:
        structPtr->pos[atkSide][atkFlank].field_4_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].field_3_6 = moveSlot;
        break;
    case STRINGID_ELECTRICITYWEAKENED:
        structPtr->pos[atkSide][atkFlank].field_4_3 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].field_4_6 = moveSlot;
        break;
    case STRINGID_ATTACKERFAINTED:
        sub_817EA80(0);
    case STRINGID_RETURNMON:
        if (structPtr->pos[atkSide][atkFlank].field_4_0 != 0)
        {
            structPtr->pos[atkSide][atkFlank].field_4_0 = 0;
            structPtr->pos[atkSide][atkFlank].field_3_6 = 0;
        }
        if (structPtr->pos[atkSide][atkFlank].field_4_3 != 0)
        {
            structPtr->pos[atkSide][atkFlank].field_4_3 = 0;
            structPtr->pos[atkSide][atkFlank].field_4_6 = 0;
        }
        break;
    case STRINGID_TARGETFAINTED:
        sub_817EA80(1);
        if (structPtr->pos[atkSide][defFlank].field_4_0 != 0)
        {
            structPtr->pos[atkSide][defFlank].field_4_0 = 0;
            structPtr->pos[atkSide][defFlank].field_3_6 = 0;
        }
        if (structPtr->pos[atkSide][defFlank].field_4_3 != 0)
        {
            structPtr->pos[atkSide][defFlank].field_4_3 = 0;
            structPtr->pos[atkSide][defFlank].field_4_6 = 0;
        }
        break;
    case STRINGID_PKMNRAISEDDEF:
    case STRINGID_PKMNRAISEDDEFALITTLE:
        structPtr->side[atkSide].field_8_0_b = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_0b = moveSlot;
        break;
    case STRINGID_PKMNRAISEDSPDEF:
    case STRINGID_PKMNRAISEDSPDEFALITTLE:
        structPtr->side[atkSide].field_8_0_c = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_0c = moveSlot;
        break;
    case STRINGID_PKMNSXWOREOFF:
        var1 = gBattleTextBuff1 + 2;
        if (*(u16*)(var1) == MOVE_REFLECT)
        {
            structPtr->side[atkSide].field_8_0_b = 0;
            structPtr->side[atkSide].field_0_0b = 0;
        }
        var2 = gBattleTextBuff1 + 2;
        if (*(u16*)(var2) == MOVE_LIGHT_SCREEN)
        {
            structPtr->side[atkSide].field_8_0_c = 0;
            structPtr->side[atkSide].field_0_0c = 0;
        }
        var1 = gBattleTextBuff1 + 2;
        if (*(u16*)(var1) == MOVE_MIST)
        {
            structPtr->side[atkSide].field_8_0_e = 0;
            structPtr->side[atkSide].field_0_0e = 0;
        }
        break;
    case STRINGID_PKMNCOVEREDBYVEIL:
        structPtr->side[atkSide].field_8_0_d = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_0d = moveSlot;
        break;
    case STRINGID_PKMNUSEDSAFEGUARD:
        if (structPtr->side[defSide].field_8_0_d != 0)
            sub_817E684(15, 0, structPtr->side[defSide].field_8_0_d - 1, structPtr->side[defSide].field_0_0d);
        break;
    case STRINGID_PKMNSAFEGUARDEXPIRED:
        structPtr->side[atkSide].field_8_0_d = 0;
        structPtr->side[atkSide].field_0_0d = 0;
        break;
    case STRINGID_PKMNSHROUDEDINMIST:
        structPtr->side[atkSide].field_8_0_e = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_0e = moveSlot;
        break;
    case STRINGID_PKMNPROTECTEDBYMIST:
        if (structPtr->side[defSide].field_8_0_e != 0)
            sub_817E684(16, 0, structPtr->side[defSide].field_8_0_e - 1, structPtr->side[defSide].field_0_0e);
        break;
    case STRINGID_THEWALLSHATTERED:
        structPtr->side[defSide].field_8_0_b = 0;
        structPtr->side[defSide].field_0_0b = 0;
        structPtr->side[defSide].field_8_0_c = 0;
        structPtr->side[defSide].field_0_0c = 0;
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

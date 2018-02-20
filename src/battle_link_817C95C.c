#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_link_817C95C.h"
#include "constants/battle_string_ids.h"
#include "battle_message.h"

struct UnknownBattleLinkSubStruct1
{
    u32 field_8_0:15;
    u32 field_8_1:3; // correct
    u32 field_8_2:3; // correct
    u32 field_8_3:3; // correct
    u32 field_8_4:3; // correct
    u32 field_8_5:3; // correct
    u32 field_8_6:2;

    u32 field_0_0a:3; // correct
    u32 field_0_0b:7;
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
    u32 field_4_3:19;
};

struct UnknownBattleLinkSubStruct2
{
    u32 field_0_0:3; // correct
    u32 field_0_3:3; // correct
    u32 field_0_6:3; // correct
    u32 field_1_1:3; // correct
    u32 field_1_4:4;
    u32 field_2_0:2;
    u32 field_2_3:2; // correct
    u32 field_2_5:2; // correct
    u32 field_2_7:2; // correct
    u32 field_3_0:2; // correct
    u32 field_3_2:6;
    u32 field_4:8;
    u32 field_5_0:3; // correct
    u32 field_5_3:2; // correct
    u32 field_5_5:2;
    u32 field_5_7:1;
    u32 field_6:8;
    u32 field_7:8;
};

struct UnknownBattleLinkSubStruct3
{
    u32 field_0 : 8;
    u32 field_1 : 8;
    u32 field_2 : 8;
    u32 field_3 : 8;
    u32 field_4 : 8;
    u32 field_5 : 8;
    u32 field_6 : 8;
    u32 field_7 : 8;
    u32 field_8 : 8;
    u32 field_9 : 8;
    u32 field_A : 8;
    u32 field_B : 8;
};

struct UnknownBattleLinkStruct
{
    u8 field_0[0x2f];
    struct UnknownBattleLinkSubStruct2 pos[2][2]; // [side][flank]
    struct UnknownBattleLinkSubStruct1 side[2]; // [side]
};

extern struct StringInfoBattle *gStringInfo;

// this file's functions
bool8 sub_817E0B8(u16 stringId);
void sub_817E684(u8 arg0, u16 moveSlotId, u8 arg2, u8 arg3);
void sub_817EECC(void);

void sub_817C95C(u16 stringId)
{
    struct UnknownBattleLinkStruct *structPtr;
    u8 atkSide, defSide, effSide, scriptingSide;
    struct Pokemon *atkMon, *defMon;
    u8 moveSlot;
    u8 atkFlank, defFlank, effFlank;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && stringId != STRINGID_ITDOESNTAFFECT && stringId != STRINGID_NOTVERYEFFECTIVE)
        return;

    structPtr = (void*)(&gBattleStruct->field_204);

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    effSide = GetBattlerSide(gEffectBattler);
    scriptingSide = GetBattlerSide(gStringInfo->scrActive);

    if (atkSide == B_SIDE_PLAYER)
        atkMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        atkMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    if (defSide == B_SIDE_PLAYER)
        defMon = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        defMon = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, gStringInfo->currentMove);

    if (moveSlot >= 4 && sub_817E0B8(stringId) && stringId >= BATTLESTRINGS_ID_ADDER)
    {
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
        structPtr->side[atkSide].field_8_1 = gBattlerPartyIndexes[gBattlerAttacker];
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
        if (gBattleTextBuff1[4] == 0)
            structPtr->side[atkSide].field_3_0 = 10;
        break;
    case STRINGID_PKMNWISHCAMETRUE:
        if (structPtr->side[defSide].field_8_4 != 0)
            sub_817E684(2, 3, defSide, (structPtr->side[defSide].field_8_4 - 1) * 4 + structPtr->side[defSide].field_0_4);
        break;
    case STRINGID_PKMNWANTSGRUDGE:
        structPtr->side[atkSide].field_8_5 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_5 = moveSlot;
        break;
    case STRINGID_PKMNLOSTPPGRUDGE:
        if (structPtr->side[defSide].field_8_5 != 0)
            sub_817E684(2, 4, defSide, (structPtr->side[defSide].field_8_5 - 1) * 4 + structPtr->side[defSide].field_0_5);
        break;
    case STRINGID_PKMNTRYINGTOTAKEFOE:
        structPtr->side[atkSide].field_0_6 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->side[atkSide].field_0_7 = moveSlot;
        break;
    case STRINGID_PKMNTOOKFOE:
        if (structPtr->side[defSide].field_0_6 != 0)
            structPtr->side[defSide].field_3_0 = 11;
        break;
    case STRINGID_PKMNPLANTEDROOTS:
        structPtr->pos[atkSide][atkFlank].field_5_0 = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        structPtr->pos[atkSide][atkFlank].field_5_3 = moveSlot;
        break;
    case STRINGID_PKMNABSORBEDNUTRIENTS:
        if (structPtr->pos[atkSide][atkFlank].field_5_0 != 0)
            sub_817E684(2, 6, atkSide, (structPtr->pos[atkSide][atkFlank].field_5_0 - 1) * 4 + structPtr->pos[atkSide][atkFlank].field_5_3);
        break;
    case STRINGID_PKMNANCHOREDITSELF:
        if (structPtr->pos[defSide][defFlank].field_5_0 != 0)
            sub_817E684(2, 6, defSide, (structPtr->pos[defSide][defFlank].field_5_0 - 1) * 4 + structPtr->pos[defSide][defFlank].field_5_3);
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
            u16 *statStringId = (void*)(gBattleTextBuff2 + 2);
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
                u16 *statStringId = (void*)(gBattleTextBuff2 + 2);
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
            u16 *statStringId = (void*)(gBattleTextBuff2 + 2);
            if (*statStringId == STRINGID_STATHARSHLY)
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
        if (GetMonData(atkMon, MON_DATA_HP, NULL) != 0
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

        break;
    }
}

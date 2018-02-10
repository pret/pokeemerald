#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "constants/abilities.h"
#include "constants/moves.h"
#include "pokemon.h"
#include "constants/species.h"
#include "random.h"
#include "util.h"
#include "constants/items.h"

extern u8 gActiveBattler;
extern u8 gAbsentBattlerFlags;
extern u32 gBattleTypeFlags;
extern u32 gStatuses3[MAX_BATTLERS_COUNT];
extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern u16 gLastLandedMoves[MAX_BATTLERS_COUNT];
extern u8 gLastHitBy[MAX_BATTLERS_COUNT];
extern u16 gDynamicBasePower;
extern u8 gMoveResultFlags;
extern u8 gCritMultiplier;
extern s32 gBattleMoveDamage;

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];
extern const u8 gTypeEffectiveness[];
extern const u8 * const gItemEffectTable[]; // todo: fix once struct is declared

// this file's functions
static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent);
static bool8 ShouldUseItem(void);

static bool8 ShouldSwitchIfPerishSong(void)
{
    if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG
        && gDisableStructs[gActiveBattler].perishSongTimer1 == 0)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = 6;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingPosition;
    u8 opposingBank;
    u8 moveFlags;
    s32 i, j;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party = NULL;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));

    if (gBattleMons[GetBattlerAtPosition(opposingPosition)].ability != ABILITY_WONDER_GUARD)
        return FALSE;

    // check if pokemon has a super effective move
    for (opposingBank = GetBattlerAtPosition(opposingPosition), i = 0; i < 4; i++)
    {
        move = gBattleMons[gActiveBattler].moves[i];
        if (move == MOVE_NONE)
            continue;

        moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
        if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            return FALSE;
    }

    // get party information
    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // find a pokemon in the party that has a super effective move
    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[gActiveBattler])
            continue;

        GetMonData(&party[i], MON_DATA_SPECIES); // unused return value
        GetMonData(&party[i], MON_DATA_ALT_ABILITY); // unused return value

        for (opposingBank = GetBattlerAtPosition(opposingPosition), j = 0; j < 4; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % 3 < 2)
            {
                // we found a mon
                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
    }

    return FALSE; // at this point there is not a single pokemon in the party that has a super effective move against a pokemon with wonder guard
}

static bool8 FindMonThatAbsorbsOpponentsMove(void)
{
    u8 bankIn1, bankIn2;
    u8 absorbingTypeAbility;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;

    if (HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0xFFFF)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            bankIn2 = gActiveBattler;
        else
            bankIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        bankIn1 = gActiveBattler;
        bankIn2 = gActiveBattler;
    }

    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_FIRE)
        absorbingTypeAbility = ABILITY_FLASH_FIRE;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_WATER)
        absorbingTypeAbility = ABILITY_WATER_ABSORB;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_ELECTRIC)
        absorbingTypeAbility = ABILITY_VOLT_ABSORB;
    else
        return FALSE;

    if (gBattleMons[gActiveBattler].ability == absorbingTypeAbility)
        return FALSE;

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[bankIn1])
            continue;
        if (i == gBattlerPartyIndexes[bankIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ALT_ABILITY) != 0)
            monAbility = gBaseStats[species].ability2;
        else
            monAbility = gBaseStats[species].ability1;

        if (absorbingTypeAbility == monAbility && Random() & 1)
        {
            // we found a mon
            *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
            BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }

    return FALSE;
}

static bool8 ShouldSwitchIfNaturalCure(void)
{
    if (!(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
        return FALSE;
    if (gBattleMons[gActiveBattler].ability != ABILITY_NATURAL_CURE)
        return FALSE;
    if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 2)
        return FALSE;

    if ((gLastLandedMoves[gActiveBattler] == 0 || gLastLandedMoves[gActiveBattler] == 0xFFFF) && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = 6;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0 && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = 6;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;
    if (Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = 6;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    return FALSE;
}

static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingPosition;
    u8 opposingBank;
    s32 i;
    u8 moveFlags;
    u16 move;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));
    opposingBank = GetBattlerAtPosition(opposingPosition);

    if (!(gAbsentBattlerFlags & gBitTable[opposingBank]))
    {
        for (i = 0; i < 4; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    opposingBank = GetBattlerAtPosition(BATTLE_PARTNER(opposingPosition));

    if (!(gAbsentBattlerFlags & gBitTable[opposingBank]))
    {
        for (i = 0; i < 4; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < BATTLE_STATS_NO; i++)
    {
        if (gBattleMons[gActiveBattler].statStages[i] > 6)
            buffedStatsValue += gBattleMons[gActiveBattler].statStages[i] - 6;
    }

    return (buffedStatsValue > 3);
}

static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent)
{
    u8 bankIn1, bankIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;
    u8 moveFlags;

    if (gLastLandedMoves[gActiveBattler] == 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0xFFFF)
        return FALSE;
    if (gLastHitBy[gActiveBattler] == 0xFF)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            bankIn2 = gActiveBattler;
        else
            bankIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        bankIn1 = gActiveBattler;
        bankIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[bankIn1])
            continue;
        if (i == gBattlerPartyIndexes[bankIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ALT_ABILITY) != 0)
            monAbility = gBaseStats[species].ability2;
        else
            monAbility = gBaseStats[species].ability1;

        moveFlags = AI_TypeCalc(gLastLandedMoves[gActiveBattler], species, monAbility);
        if (moveFlags & flags)
        {
            bankIn1 = gLastHitBy[gActiveBattler];

            for (j = 0; j < 4; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                moveFlags = AI_TypeCalc(move, gBattleMons[bankIn1].species, gBattleMons[bankIn1].ability);
                if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static bool8 ShouldSwitch(void)
{
    u8 bankIn1, bankIn2;
    u8 *activeBankPtr; // needed to match
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;

    if (gBattleMons[*(activeBankPtr = &gActiveBattler)].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[gActiveBattler] & STATUS3_ROOTED)
        return FALSE;
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBattler, ABILITY_SHADOW_TAG, 0, 0))
        return FALSE;
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBattler, ABILITY_ARENA_TRAP, 0, 0))
        return FALSE; // misses the flying or levitate check
    if (AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_MAGNET_PULL, 0, 0))
    {
        if (gBattleMons[gActiveBattler].type1 == TYPE_STEEL)
            return FALSE;
        if (gBattleMons[gActiveBattler].type2 == TYPE_STEEL)
            return FALSE;
    }
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    availableToSwitch = 0;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = *activeBankPtr;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(*activeBankPtr) ^ BIT_FLANK)])
            bankIn2 = *activeBankPtr;
        else
            bankIn2 = GetBattlerAtPosition(GetBattlerPosition(*activeBankPtr) ^ BIT_FLANK);
    }
    else
    {
        bankIn1 = *activeBankPtr;
        bankIn2 = *activeBankPtr;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[bankIn1])
            continue;
        if (i == gBattlerPartyIndexes[bankIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn2))
            continue;

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
        return FALSE;
    if (ShouldSwitchIfPerishSong())
        return TRUE;
    if (ShouldSwitchIfWonderGuard())
        return TRUE;
    if (FindMonThatAbsorbsOpponentsMove())
        return TRUE;
    if (ShouldSwitchIfNaturalCure())
        return TRUE;
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE))
        return FALSE;
    if (AreStatsRaised())
        return FALSE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
        || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE;

    return FALSE;
}

void AI_TrySwitchOrUseItem(void)
{
    struct Pokemon *party;
    u8 bankIn1, bankIn2;
    s32 firstId;
    s32 lastId; // + 1
    u8 bankIdentity = GetBattlerPosition(gActiveBattler);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch())
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) == 6)
            {
                s32 monToSwitchId = GetMostSuitableMonToSwitchInto();
                if (monToSwitchId == 6)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        bankIn1 = GetBattlerAtPosition(bankIdentity);
                        bankIn2 = bankIn1;
                    }
                    else
                    {
                        bankIn1 = GetBattlerAtPosition(bankIdentity);
                        bankIn2 = GetBattlerAtPosition(bankIdentity ^ BIT_FLANK);
                    }

                    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
                    {
                        if ((gActiveBattler & BIT_FLANK) == 0)
                            firstId = 0, lastId = 3;
                        else
                            firstId = 3, lastId = 6;
                    }
                    else
                    {
                        firstId = 0, lastId = 6;
                    }

                    for (monToSwitchId = firstId; monToSwitchId < lastId; monToSwitchId++)
                    {
                        if (GetMonData(&party[monToSwitchId], MON_DATA_HP) == 0)
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[bankIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[bankIn2])
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + bankIn1))
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + bankIn2))
                            continue;

                        break;
                    }
                }

                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler);
            return;
        }
        else if (ShouldUseItem())
        {
            return;
        }
    }

    BtlController_EmitTwoReturnValues(1, B_ACTION_USE_MOVE, (gActiveBattler ^ BIT_SIDE) << 8);
}

static void ModulateByTypeEffectiveness(u8 atkType, u8 defType1, u8 defType2, u8 *var)
{
    s32 i = 0;

    while (TYPE_EFFECT_ATK_TYPE(i) != TYPE_ENDTABLE)
    {
        if (TYPE_EFFECT_ATK_TYPE(i) == TYPE_FORESIGHT)
        {
            i += 3;
            continue;
        }
        else if (TYPE_EFFECT_ATK_TYPE(i) == atkType)
        {
            // check type1
            if (TYPE_EFFECT_DEF_TYPE(i) == defType1)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
            // check type2
            if (TYPE_EFFECT_DEF_TYPE(i) == defType2 && defType1 != defType2)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
        }
        i += 3;
    }
}

u8 GetMostSuitableMonToSwitchInto(void)
{
    u8 opposingBank;
    u8 bestDmg; // note : should be changed to u32 for obvious reasons
    u8 bestMonId;
    u8 bankIn1, bankIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u8 invalidMons;
    u16 move;

    if (*(gBattleStruct->monToSwitchIntoId + gActiveBattler) != 6)
        return *(gBattleStruct->monToSwitchIntoId + gActiveBattler);
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return gBattlerPartyIndexes[gActiveBattler] + 1;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK)])
            bankIn2 = gActiveBattler;
        else
            bankIn2 = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK);

        // UB: It considers the opponent only player's side even though it can battle alongside player;
        opposingBank = Random() & BIT_FLANK;
        if (gAbsentBattlerFlags & gBitTable[opposingBank])
            opposingBank ^= BIT_FLANK;
    }
    else
    {
        opposingBank = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_SIDE);
        bankIn1 = gActiveBattler;
        bankIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    invalidMons = 0;

    while (invalidMons != 0x3F) // all mons are invalid
    {
        bestDmg = 0;
        bestMonId = 6;
        // find the mon which type is the most suitable offensively
        for (i = firstId; i < lastId; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
                && GetMonData(&party[i], MON_DATA_HP) != 0
                && !(gBitTable[i] & invalidMons)
                && gBattlerPartyIndexes[bankIn1] != i
                && gBattlerPartyIndexes[bankIn2] != i
                && i != *(gBattleStruct->monToSwitchIntoId + bankIn1)
                && i != *(gBattleStruct->monToSwitchIntoId + bankIn2))
            {
                u8 type1 = gBaseStats[species].type1;
                u8 type2 = gBaseStats[species].type2;
                u8 typeDmg = 10;
                ModulateByTypeEffectiveness(gBattleMons[opposingBank].type1, type1, type2, &typeDmg);
                ModulateByTypeEffectiveness(gBattleMons[opposingBank].type2, type1, type2, &typeDmg);
                if (bestDmg < typeDmg)
                {
                    bestDmg = typeDmg;
                    bestMonId = i;
                }
            }
            else
            {
                invalidMons |= gBitTable[i];
            }
        }

        // ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != 6)
        {
            for (i = 0; i < 4; i++)
            {
                move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
                if (move != MOVE_NONE && TypeCalc(move, gActiveBattler, opposingBank) & MOVE_RESULT_SUPER_EFFECTIVE)
                    break;
            }

            if (i != 4)
                return bestMonId; // has both the typing and at least one super effective move

            invalidMons |= gBitTable[bestMonId]; // sorry buddy, we want something better
        }
        else
        {
            invalidMons = 0x3F; // no viable mon to switch
        }
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    bestDmg = 0;
    bestMonId = 6;

    // if we couldn't find the best mon in terms of typing, find the one that deals most damage
    for (i = firstId; i < lastId; i++)
    {
        if ((u16)(GetMonData(&party[i], MON_DATA_SPECIES)) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (gBattlerPartyIndexes[bankIn1] == i)
            continue;
        if (gBattlerPartyIndexes[bankIn2] == i)
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + bankIn2))
            continue;

        for (j = 0; j < 4; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            gBattleMoveDamage = 0;
            if (move != MOVE_NONE && gBattleMoves[move].power != 1)
            {
                AI_CalcDmg(gActiveBattler, opposingBank);
                TypeCalc(move, gActiveBattler, opposingBank);
            }
            if (bestDmg < gBattleMoveDamage)
            {
                bestDmg = gBattleMoveDamage;
                bestMonId = i;
            }
        }
    }

    return bestMonId;
}

// TODO: use PokemonItemEffect struct instead of u8 once it's documented
static u8 GetAI_ItemType(u8 itemId, const u8 *itemEffect) // NOTE: should take u16 as item Id argument
{
    if (itemId == ITEM_FULL_RESTORE)
        return AI_ITEM_FULL_RESTORE;
    if (itemEffect[4] & 4)
        return AI_ITEM_HEAL_HP;
    if (itemEffect[3] & 0x3F)
        return AI_ITEM_CURE_CONDITION;
    if (itemEffect[0] & 0x3F || itemEffect[1] != 0 || itemEffect[2] != 0)
        return AI_ITEM_X_STAT;
    if (itemEffect[3] & 0x80)
        return AI_ITEM_GUARD_SPECS;

    return AI_ITEM_NOT_RECOGNIZABLE;
}

static bool8 ShouldUseItem(void)
{
    struct Pokemon *party;
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT)
        return FALSE;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) != 0
            && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
            && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            validMons++;
        }
    }

    for (i = 0; i < 4; i++)
    {
        u16 item;
        const u8 *itemEffects;
        u8 paramOffset;
        u8 bankSide;

        if (i != 0 && validMons > (gBattleResources->battleHistory->itemsNo - i) + 1)
            continue;
        item = gBattleResources->battleHistory->trainerItems[i];
        if (item == ITEM_NONE)
            continue;
        if (gItemEffectTable[item - 13] == NULL)
            continue;

        if (item == ITEM_ENIGMA_BERRY)
            itemEffects = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        else
            itemEffects = gItemEffectTable[item - 13];

        *(gBattleStruct->AI_itemType + gActiveBattler / 2) = GetAI_ItemType(item, itemEffects);

        switch (*(gBattleStruct->AI_itemType + gActiveBattler / 2))
        {
        case AI_ITEM_FULL_RESTORE:
            if (gBattleMons[gActiveBattler].hp >= gBattleMons[gActiveBattler].maxHP / 4)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            shouldUse = TRUE;
            break;
        case AI_ITEM_HEAL_HP:
            paramOffset = GetItemEffectParamOffset(item, 4, 4);
            if (paramOffset == 0)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 4 || gBattleMons[gActiveBattler].maxHP - gBattleMons[gActiveBattler].hp > itemEffects[paramOffset])
                shouldUse = TRUE;
            break;
        case AI_ITEM_CURE_CONDITION:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (itemEffects[3] & 0x20 && gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & 0x10 && (gBattleMons[gActiveBattler].status1 & STATUS1_POISON || gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON))
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x10;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & 0x8 && gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & 0x4 && gBattleMons[gActiveBattler].status1 & STATUS1_FREEZE)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & 0x2 && gBattleMons[gActiveBattler].status1 & STATUS1_PARALYSIS)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & 0x1 && gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
                shouldUse = TRUE;
            }
            break;
        case AI_ITEM_X_STAT:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (gDisableStructs[gActiveBattler].isFirstTurn == 0)
                break;
            if (itemEffects[0] & 0xF)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
            if (itemEffects[1] & 0xF0)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
            if (itemEffects[1] & 0xF)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
            if (itemEffects[2] & 0xF)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
            if (itemEffects[2] & 0xF0)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
            if (itemEffects[0] & 0x30)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x80;
            shouldUse = TRUE;
            break;
        case AI_ITEM_GUARD_SPECS:
            bankSide = GetBattlerSide(gActiveBattler);
            if (gDisableStructs[gActiveBattler].isFirstTurn != 0 && gSideTimers[bankSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case AI_ITEM_NOT_RECOGNIZABLE:
            return FALSE;
        }

        if (shouldUse)
        {
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_ITEM, 0);
            *(gBattleStruct->chosenItem + (gActiveBattler / 2) * 2) = item;
            gBattleResources->battleHistory->trainerItems[i] = 0;
            return shouldUse;
        }
    }

    return FALSE;
}

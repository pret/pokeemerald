#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "abilities.h"
#include "moves.h"
#include "pokemon.h"
#include "species.h"
#include "rng.h"
#include "util.h"

extern u8 gActiveBank;
extern u8 gAbsentBankFlags;
extern u32 gBattleTypeFlags;
extern u32 gStatuses3[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u16 gUnknown_02024250[BATTLE_BANKS_COUNT];
extern u8 gUnknown_02024270[BATTLE_BANKS_COUNT];

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];

// this file's functions
bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent);

bool8 ShouldSwitchIfPerishSong(void)
{
    if (gStatuses3[gActiveBank] & STATUS3_PERISH_SONG
        && gDisableStructs[gActiveBank].perishSong1 == 0)
    {
        *(gBattleStruct->field_294 + gActiveBank) = 6;
        EmitCmd_x21(1, 2, 0);
        return TRUE;
    }

    return FALSE;
}

bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingIdentity;
    u8 opposingBank;
    u8 moveFlags;
    s32 i, j;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party = NULL;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

    opposingIdentity = GetBankIdentity(gActiveBank) ^ BIT_SIDE;

    if (gBattleMons[GetBankByIdentity(opposingIdentity)].ability != ABILITY_WONDER_GUARD)
        return FALSE;

    // check if pokemon has a super effective move
    for (opposingBank = GetBankByIdentity(opposingIdentity), i = 0; i < 4; i++)
    {
        move = gBattleMons[gActiveBank].moves[i];
        if (move == MOVE_NONE)
            continue;

        moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
        if (moveFlags & MOVESTATUS_SUPEREFFECTIVE)
            return FALSE;
    }

    // get party information
    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBank & BIT_MON) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
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
        if (i == gBattlePartyID[gActiveBank])
            continue;

        GetMonData(&party[i], MON_DATA_SPECIES); // unused return value
        GetMonData(&party[i], MON_DATA_ALT_ABILITY); // unused return value

        for (opposingBank = GetBankByIdentity(opposingIdentity), j = 0; j < 4; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVESTATUS_SUPEREFFECTIVE && Random() % 3 < 2)
            {
                // we found a mon
                *(gBattleStruct->field_294 + gActiveBank) = i;
                EmitCmd_x21(1, 2, 0);
                return TRUE;
            }
        }
    }

    return FALSE; // at this point there is not a single pokemon in the party that has a super effective move against a pokemon with wonder guard
}

bool8 sub_8062E54(void)
{
    u8 bankIn1, bankIn2;
    u8 absorbingTypeAbility;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;

    if (HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gUnknown_02024250[gActiveBank] == 0)
        return FALSE;
    if (gUnknown_02024250[gActiveBank] == 0xFFFF)
        return FALSE;
    if (gBattleMoves[gUnknown_02024250[gActiveBank]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBank;
        if (gAbsentBankFlags & gBitTable[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)])
            bankIn2 = gActiveBank;
        else
            bankIn2 = GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON);
    }
    else
    {
        bankIn1 = gActiveBank;
        bankIn2 = gActiveBank;
    }

    if (gBattleMoves[gUnknown_02024250[gActiveBank]].type == TYPE_FIRE)
        absorbingTypeAbility = ABILITY_FLASH_FIRE;
    else if (gBattleMoves[gUnknown_02024250[gActiveBank]].type == TYPE_WATER)
        absorbingTypeAbility = ABILITY_WATER_ABSORB;
    else if (gBattleMoves[gUnknown_02024250[gActiveBank]].type == TYPE_ELECTRIC)
        absorbingTypeAbility = ABILITY_VOLT_ABSORB;
    else
        return FALSE;

    if (gBattleMons[gActiveBank].ability == absorbingTypeAbility)
        return FALSE;

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBank & BIT_MON) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
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
        if (i == gBattlePartyID[bankIn1])
            continue;
        if (i == gBattlePartyID[bankIn2])
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn1))
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ALT_ABILITY) != 0)
            monAbility = gBaseStats[species].ability2;
        else
            monAbility = gBaseStats[species].ability1;

        if (absorbingTypeAbility == monAbility && Random() & 1)
        {
            // we found a mon
            *(gBattleStruct->field_294 + gActiveBank) = i;
            EmitCmd_x21(1, 2, 0);
            return TRUE;
        }
    }

    return FALSE;
}

bool8 ShouldSwitchIfNaturalCure(void)
{
    if (!(gBattleMons[gActiveBank].status1 & STATUS_SLEEP))
        return FALSE;
    if (gBattleMons[gActiveBank].ability != ABILITY_NATURAL_CURE)
        return FALSE;
    if (gBattleMons[gActiveBank].hp < gBattleMons[gActiveBank].maxHP / 2)
        return FALSE;

    if ((gUnknown_02024250[gActiveBank] == 0 || gUnknown_02024250[gActiveBank] == 0xFFFF) && Random() & 1)
    {
        *(gBattleStruct->field_294 + gActiveBank) = 6;
        EmitCmd_x21(1, 2, 0);
        return TRUE;
    }
    else if (gBattleMoves[gUnknown_02024250[gActiveBank]].power == 0 && Random() & 1)
    {
        *(gBattleStruct->field_294 + gActiveBank) = 6;
        EmitCmd_x21(1, 2, 0);
        return TRUE;
    }

    if (FindMonWithFlagsAndSuperEffective(MOVESTATUS_NOTAFFECTED, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVESTATUS_NOTVERYEFFECTIVE, 1))
        return TRUE;
    if (Random() & 1)
    {
        *(gBattleStruct->field_294 + gActiveBank) = 6;
        EmitCmd_x21(1, 2, 0);
        return TRUE;
    }

    return FALSE;
}

bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingIdentity;
    u8 opposingBank;
    s32 i;
    u8 moveFlags;
    u16 move;

    opposingIdentity = GetBankIdentity(gActiveBank) ^ BIT_SIDE;
    opposingBank = GetBankByIdentity(opposingIdentity);

    if (!(gAbsentBankFlags & gBitTable[opposingBank]))
    {
        for (i = 0; i < 4; i++)
        {
            move = gBattleMons[gActiveBank].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVESTATUS_SUPEREFFECTIVE)
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

    opposingBank = GetBankByIdentity(opposingIdentity ^ BIT_MON);

    if (!(gAbsentBankFlags & gBitTable[opposingBank]))
    {
        for (i = 0; i < 4; i++)
        {
            move = gBattleMons[gActiveBank].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBank].species, gBattleMons[opposingBank].ability);
            if (moveFlags & MOVESTATUS_SUPEREFFECTIVE)
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

bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < BATTLE_STATS_NO; i++)
    {
        if (gBattleMons[gActiveBank].statStages[i] > 6)
            buffedStatsValue += gBattleMons[gActiveBank].statStages[i] - 6;
    }

    return (buffedStatsValue > 3);
}

bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent)
{
    u8 bankIn1, bankIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;
    u8 moveFlags;

    if (gUnknown_02024250[gActiveBank] == 0)
        return FALSE;
    if (gUnknown_02024250[gActiveBank] == 0xFFFF)
        return FALSE;
    if (gUnknown_02024270[gActiveBank] == 0xFF)
        return FALSE;
    if (gBattleMoves[gUnknown_02024250[gActiveBank]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBank;
        if (gAbsentBankFlags & gBitTable[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)])
            bankIn2 = gActiveBank;
        else
            bankIn2 = GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON);
    }
    else
    {
        bankIn1 = gActiveBank;
        bankIn2 = gActiveBank;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBank & BIT_MON) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
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
        if (i == gBattlePartyID[bankIn1])
            continue;
        if (i == gBattlePartyID[bankIn2])
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn1))
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ALT_ABILITY) != 0)
            monAbility = gBaseStats[species].ability2;
        else
            monAbility = gBaseStats[species].ability1;

        moveFlags = AI_TypeCalc(gUnknown_02024250[gActiveBank], species, monAbility);
        if (moveFlags & flags)
        {
            bankIn1 = gUnknown_02024270[gActiveBank];

            for (j = 0; j < 4; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                moveFlags = AI_TypeCalc(move, gBattleMons[bankIn1].species, gBattleMons[bankIn1].ability);
                if (moveFlags & MOVESTATUS_SUPEREFFECTIVE && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->field_294 + gActiveBank) = i;
                    EmitCmd_x21(1, 2, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

bool8 ShouldSwitch(void)
{
    u8 bankIn1, bankIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;

    if (gBattleMons[gActiveBank].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[gActiveBank] & STATUS3_ROOTED)
        return FALSE;
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBank, ABILITY_SHADOW_TAG, 0, 0))
        return FALSE;
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBank, ABILITY_ARENA_TRAP, 0, 0))
        return FALSE; // misses the flying or levitate check
    if (AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, gActiveBank, ABILITY_MAGNET_PULL, 0, 0)
        && (gBattleMons[gActiveBank].type1 == TYPE_STEEL || gBattleMons[gActiveBank].type2 == TYPE_STEEL))
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    availableToSwitch = 0;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        bankIn1 = gActiveBank;
        if (gAbsentBankFlags & gBitTable[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)])
            bankIn2 = gActiveBank;
        else
            bankIn2 = GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON);
    }
    else
    {
        bankIn1 = gActiveBank;
        bankIn2 = gActiveBank;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBank & BIT_MON) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
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
        if (i == gBattlePartyID[bankIn1])
            continue;
        if (i == gBattlePartyID[bankIn2])
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn1))
            continue;
        if (i == *(gBattleStruct->field_5C + bankIn2))
            continue;

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
        return FALSE;
    if (ShouldSwitchIfPerishSong())
        return TRUE;
    if (ShouldSwitchIfWonderGuard())
        return TRUE;
    if (sub_8062E54())
        return TRUE;
    if (ShouldSwitchIfNaturalCure())
        return TRUE;
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE))
        return FALSE;
    if (AreStatsRaised())
        return FALSE;
    if (FindMonWithFlagsAndSuperEffective(MOVESTATUS_NOTAFFECTED, 2))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVESTATUS_NOTVERYEFFECTIVE, 3))
        return TRUE;

    return FALSE;
}

#include "global.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "species.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "rng.h"
#include "map_constants.h"
#include "field_player_avatar.h"
#include "abilities.h"
#include "event_data.h"
#include "safari_zone.h"
#include "pokeblock.h"
#include "battle_setup.h"
#include "roamer.h"

EWRAM_DATA u8 sWildEncountersDisabled = 0;
EWRAM_DATA u32 sFeebasRngValue = 0;

#define NUM_FEEBAS_SPOTS 6

extern const u16 gRoute119WaterTileData[];
extern const struct WildPokemonHeader gBattlePikeWildMonHeaders[];
extern const struct WildPokemonHeader gBattlePyramidWildMonHeaders[];

extern u8 GetBattlePikeWildMonHeaderId(void);
extern bool32 TryGenerateBattlePikeWildMon(bool8 checkKeenEyeIntimidate);
extern void GenerateBattlePyramidWildMon(void);

// this file's functions
u16 FeebasRandom(void);
void FeebasSeedRng(u16 seed);
bool8 IsWildLevelAllowedByRepel(u8 level);
void ApplyFluteEncounterRateMod(u32 *encRate);
void ApplyCleanseTagEncounterRateMod(u32 *encRate);
bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u8 ability, u8 *monIndex);
bool8 IsAbilityAllowingEncounter(u8 level);

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

u16 GetRoute119WaterTileNum(s16 x, s16 y, u8 section)
{
    u16 xCur;
    u16 yCur;
    u16 yMin = gRoute119WaterTileData[section * 3 + 0];
    u16 yMax = gRoute119WaterTileData[section * 3 + 1];
    u16 tileNum = gRoute119WaterTileData[section * 3 + 2];

    for (yCur = yMin; yCur <= yMax; yCur++)
    {
        for (xCur = 0; xCur < gMapHeader.mapData->width; xCur++)
        {
            u8 tileBehaviorId = MapGridGetMetatileBehaviorAt(xCur + 7, yCur + 7);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(tileBehaviorId) == TRUE)
            {
                tileNum++;
                if (x == xCur && y == yCur)
                    return tileNum;
            }
        }
    }
    return tileNum + 1;
}

bool8 CheckFeebas(void)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    s16 x;
    s16 y;
    u8 route119section = 0;
    u16 waterTileNum;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP_ROUTE119
     && gSaveBlock1Ptr->location.mapNum == MAP_ID_ROUTE119)
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
        x -= 7;
        y -= 7;

#ifdef NONMATCHING
        if (y >= gRoute119WaterTileData[3 * 1 + 0] && y <= gRoute119WaterTileData[3 * 1 + 1])
            route119section = 1;
        if (y >= gRoute119WaterTileData[3 * 2 + 0] && y <= gRoute119WaterTileData[3 * 2 + 1])
            route119section = 2;
#else
        {
            register const u16 *arr asm("r0");
            if (y >= (arr = gRoute119WaterTileData)[3 * 1 + 0] && y <= arr[3 * 1 + 1])
                route119section = 1;
            if (y >= arr[3 * 2 + 0] && y <= arr[3 * 2 + 1])
                route119section = 2;
        }
#endif

        if (Random() % 100 > 49) // 50% chance of encountering Feebas
            return FALSE;

        FeebasSeedRng(gSaveBlock1Ptr->easyChatPairs[0].unk2);
        for (i = 0; i != NUM_FEEBAS_SPOTS;)
        {
            feebasSpots[i] = FeebasRandom() % 447;
            if (feebasSpots[i] == 0)
                feebasSpots[i] = 447;
            if (feebasSpots[i] < 1 || feebasSpots[i] >= 4)
                i++;
        }
        waterTileNum = GetRoute119WaterTileNum(x, y, route119section);
        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (waterTileNum == feebasSpots[i])
                return TRUE;
        }
    }
    return FALSE;
}

u16 FeebasRandom(void)
{
    sFeebasRngValue = 12345 + 0x41C64E6D * sFeebasRngValue;
    return sFeebasRngValue >> 16;
}

void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % 100;

    if (rand < 20)                  // 20% chance
        return 0;
    if (rand >= 20 && rand < 40)    // 20% chance
        return 1;
    if (rand >= 40 && rand < 50)    // 10% chance
        return 2;
    if (rand >= 50 && rand < 60)    // 10% chance
        return 3;
    if (rand >= 60 && rand < 70)    // 10% chance
        return 4;
    if (rand >= 70 && rand < 80)    // 10% chance
        return 5;
    if (rand >= 80 && rand < 85)    // 5% chance
        return 6;
    if (rand >= 85 && rand < 90)    // 5% chance
        return 7;
    if (rand >= 90 && rand < 94)    // 4% chance
        return 8;
    if (rand >= 94 && rand < 98)    // 4% chance
        return 9;
    if (rand == 98)                 // 1% chance
        return 10;
    else                            // 1% chance
        return 11;
}

u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % 100;

    if (rand < 60)                  // 60% chance
        return 0;
    if (rand >= 60 && rand < 90)    // 30% chance
        return 1;
    if (rand >= 90 && rand < 95)    // 5% chance
        return 2;
    if (rand >= 95 && rand < 99)    // 4% chance
        return 3;
    else                            // 1% chance
        return 4;
}

enum
{
    OLD_ROD,
    GOOD_ROD,
    SUPER_ROD
};

u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % 100;

    switch (rod)
    {
    case OLD_ROD:
        if (rand < 70)  // 70% chance
            wildMonIndex = 0;
        else            // 30% chance
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < 60)                  // 60% chance
            wildMonIndex = 2;
        if (rand >= 60 && rand < 80)    // 20% chance
            wildMonIndex = 3;
        if (rand >= 80 && rand < 100)   // 20% chance
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < 40)                  // 40% chance
            wildMonIndex = 5;
        if (rand >= 40 && rand < 80)    // 40% chance
            wildMonIndex = 6;
        if (rand >= 80 && rand < 95)    // 15% chance
            wildMonIndex = 7;
        if (rand >= 95 && rand < 99)    // 4% chance
            wildMonIndex = 8;
        if (rand == 99)                 // 1% chance
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon)
{
    u8 min;
    u8 max;
    u8 range;
    u8 rand;

    // Make sure minimum level is less than maximum level
    if (wildPokemon->maxLevel >= wildPokemon->minLevel)
    {
        min = wildPokemon->minLevel;
        max = wildPokemon->maxLevel;
    }
    else
    {
        min = wildPokemon->maxLevel;
        max = wildPokemon->minLevel;
    }
    range = max - min + 1;
    rand = Random() % range;

    // check ability for max level mon
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE)
        {
            if (Random() % 2 == 0)
                return max;

            if (rand != 0)
                rand--;
        }
    }

    return min + rand;
}

u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == 0xFF)
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP_ALTERING_CAVE &&
                gSaveBlock1Ptr->location.mapNum == MAP_ID_ALTERING_CAVE)
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId > 8)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            return i;
        }
    }

    return -1;
}

u8 PickWildMonNature(void)
{
    u8 i;
    u8 j;
    struct Pokeblock *safariPokeblock;
    u8 natures[25];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < 25; i++)
                natures[i] = i;
            for (i = 0; i < 24; i++)
            {
                for (j = i + 1; j < 25; j++)
                {
                    if (Random() & 1)
                    {
                        u8 temp = natures[i];

                        natures[i] = natures[j];
                        natures[j] = temp;
                    }
                }
            }
            for (i = 0; i < 25; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }
    // check synchronize for a pokemon with the same ability
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE
        && Random() % 2 == 0)
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % 25;
    }

    // random nature
    return Random() % 25;
}

void CreateWildMon(u16 species, u8 level)
{
    bool32 checkCuteCharm;

    ZeroEnemyPartyMons();
    checkCuteCharm = TRUE;

    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, 32, gender, PickWildMonNature(), 0);
        return;
    }

    CreateMonWithNature(&gEnemyParty[0], species, level, 32, PickWildMonNature());
}

enum
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    0x1
#define WILD_CHECK_KEEN_EYE 0x2

bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, u8 area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (TryGetAbilityInfluencedWildMonIndex(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex))
            break;
        if (TryGetAbilityInfluencedWildMonIndex(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex))
            break;

        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TryGetAbilityInfluencedWildMonIndex(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex))
            break;

        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    }

    level = ChooseWildMonLevel(&wildMonInfo->wildPokemon[wildMonIndex]);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapDataId != 0x166 && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

u16 GenerateFishingWildMon(struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    u8 level = ChooseWildMonLevel(&wildMonInfo->wildPokemon[wildMonIndex]);

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return wildMonInfo->wildPokemon[wildMonIndex].species;
}

bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(gSaveBlock1Ptr->outbreakPokemonLevel))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (i = 0; i < 4; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != 0
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

bool8 DoWildEncounterRateDiceRoll(u16 encounterRate)
{
    if (Random() % 2880 < encounterRate)
        return TRUE;
    else
        return FALSE;
}

bool8 DoWildEncounterRateTest(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3))
    {
        u32 ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapDataId == 0x169)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == 8)
            encounterRate /= 2;
    }
    if (encounterRate > 2880)
        encounterRate = 2880;
    return DoWildEncounterRateDiceRoll(encounterRate);
}

bool8 DoGlobalWildEncounterDiceRoll(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP_SOOTOPOLIS_CITY
        || gSaveBlock1Ptr->location.mapNum != MAP_ID_SOOTOPOLIS_CITY)
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior)
{
    u16 headerId;
    struct Roamer *roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF) // invalid
    {
        if (gMapHeader.mapDataId == 0x166)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(gBattlePikeWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapDataId == 0x169)
        {
            headerId = gSaveBlock2Ptr->battlePyramidWildHeaderId;
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(gBattlePyramidWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(currMetaTileBehavior) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(gWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(currMetaTileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridge(currMetaTileBehavior) == TRUE))
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;
            if (previousMetaTileBehavior != currMetaTileBehavior && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(gWildMonHeaders[headerId].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                return FALSE;
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (DoWildEncounterRateTest(wildPokemonInfo->encounterRate, 1) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, 2, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF) // invalid
    {
        if (gMapHeader.mapDataId == 0x166)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapDataId == 0x169)
        {
            headerId = gSaveBlock2Ptr->battlePyramidWildHeaderId;
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF && gWildMonHeaders[headerId].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

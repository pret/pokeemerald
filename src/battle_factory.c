#include "global.h"
#include "battle.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "battle_tower.h"
#include "random.h"
#include "constants/battle_ai.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/frontier_util.h"
#include "constants/layouts.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"

static bool8 sPerformedRentalSwap;

static void InitFactoryChallenge(void);
static void GetBattleFactoryData(void);
static void SetBattleFactoryData(void);
static void SaveFactoryChallenge(void);
static void FactoryDummy1(void);
static void FactoryDummy2(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void SetPerformedRentalSwap(void);
static void SetRentalsToOpponentParty(void);
static void SetPlayerAndOpponentParties(void);
static void SetOpponentGfxVar(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);
static void GetOpponentMostCommonMonType(void);
static void GetOpponentBattleStyle(void);
static void RestorePlayerPartyHeldItems(void);
static u16 GetFactoryMonId(enum FrontierLevelMode lvlMode, u8 challengeNum, bool8 useBetterRange);
static enum FactoryStyle GetMoveBattleStyle(enum Move move);

// Number of moves needed on the team to be considered using a certain battle style
static const u8 sRequiredMoveCounts[FACTORY_NUM_STYLES - 1] = {
    [FACTORY_STYLE_PREPARATION - 1]   = 3,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = 3,
    [FACTORY_STYLE_ENDURANCE - 1]     = 3,
    [FACTORY_STYLE_HIGH_RISK - 1]     = 2,
    [FACTORY_STYLE_WEAKENING - 1]     = 2,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = 2,
    [FACTORY_STYLE_WEATHER - 1]       = 2
};

static void (*const sBattleFactoryFunctions[])(void) =
{
    [BATTLE_FACTORY_FUNC_INIT]                   = InitFactoryChallenge,
    [BATTLE_FACTORY_FUNC_GET_DATA]               = GetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SET_DATA]               = SetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SAVE]                   = SaveFactoryChallenge,
    [BATTLE_FACTORY_FUNC_NULL]                   = FactoryDummy1,
    [BATTLE_FACTORY_FUNC_NULL2]                  = FactoryDummy2,
    [BATTLE_FACTORY_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [BATTLE_FACTORY_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [BATTLE_FACTORY_FUNC_SET_SWAPPED]            = SetPerformedRentalSwap,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS]      = SetRentalsToOpponentParty,
    [BATTLE_FACTORY_FUNC_SET_PARTIES]            = SetPlayerAndOpponentParties,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX]       = SetOpponentGfxVar,
    [BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE]  = GetOpponentMostCommonMonType,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE]     = GetOpponentBattleStyle,
    [BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS]       = RestorePlayerPartyHeldItems,
};

static const u32 sWinStreakFlags[][2] =
{
    {STREAK_FACTORY_SINGLES_50, STREAK_FACTORY_SINGLES_OPEN},
    {STREAK_FACTORY_DOUBLES_50, STREAK_FACTORY_DOUBLES_OPEN},
};

static const u32 sWinStreakMasks[][2] =
{
    {~(STREAK_FACTORY_SINGLES_50), ~(STREAK_FACTORY_SINGLES_OPEN)},
    {~(STREAK_FACTORY_DOUBLES_50), ~(STREAK_FACTORY_DOUBLES_OPEN)},
};

static const u8 sFixedIVTable[][2] =
{
    {3, 6},
    {6, 9},
    {9, 12},
    {12, 15},
    {15, 18},
    {21, 31},
    {31, 31},
    {31, 31},
};

static const u16 sInitialRentalMonRanges[][2] =
{
    // Level 50
    {FRONTIER_MON_GRIMER,     FRONTIER_MON_FURRET_1},   // 110 - 199
    {FRONTIER_MON_DELCATTY_1, FRONTIER_MON_CLOYSTER_1}, // 162 - 266
    {FRONTIER_MON_DELCATTY_2, FRONTIER_MON_CLOYSTER_2}, // 267 - 371
    {FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_SLAKING_1},  // 372 - 467
    {FRONTIER_MON_DUGTRIO_2,  FRONTIER_MON_SLAKING_2},  // 468 - 563
    {FRONTIER_MON_DUGTRIO_3,  FRONTIER_MON_SLAKING_3},  // 564 - 659
    {FRONTIER_MON_DUGTRIO_4,  FRONTIER_MON_SLAKING_4},  // 660 - 755
    {FRONTIER_MON_DUGTRIO_1,  FRONTIER_MONS_HIGH_TIER}, // 372 - 849

    // Open level
    {FRONTIER_MON_DUGTRIO_1, FRONTIER_MON_SLAKING_1}, // 372 - 467
    {FRONTIER_MON_DUGTRIO_2, FRONTIER_MON_SLAKING_2}, // 468 - 563
    {FRONTIER_MON_DUGTRIO_3, FRONTIER_MON_SLAKING_3}, // 564 - 659
    {FRONTIER_MON_DUGTRIO_4, FRONTIER_MON_SLAKING_4}, // 660 - 755
    {FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1},  // 372 - 881
    {FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1},  // 372 - 881
    {FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1},  // 372 - 881
    {FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1},  // 372 - 881
};

// code
void CallBattleFactoryFunction(void)
{
    sBattleFactoryFunctions[gSpecialVar_0x8004]();
}

static void InitFactoryChallenge(void)
{
    u8 i;
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
    {
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
        gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    }

    sPerformedRentalSwap = FALSE;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); i++)
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = 0xFFFF;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        gFrontierTempParty[i] = 0xFFFF;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    TRAINER_BATTLE_PARAM.opponentA = 0;
}

static void GetBattleFactoryData(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
        break;
    }
}

static void SetBattleFactoryData(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        if (sPerformedRentalSwap == TRUE)
        {
            gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = gSpecialVar_0x8006;
            sPerformedRentalSwap = FALSE;
        }
        break;
    }
}

static void SaveFactoryChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void FactoryDummy1(void)
{

}

static void FactoryDummy2(void)
{

}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

static void SetPerformedRentalSwap(void)
{
    sPerformedRentalSwap = TRUE;
}

static void GenerateOpponentMons(void)
{
    int i, j, k;
    enum Species species[FRONTIER_PARTY_SIZE];
    enum Item heldItems[FRONTIER_PARTY_SIZE];
    int firstMonId = 0;
    u16 trainerId = 0;
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / FRONTIER_STAGES_PER_CHALLENGE;
    gFacilityTrainers = gBattleFrontierTrainers;

    do
    {
        // Choose a random trainer, ensuring no repeats in this challenge
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        // Unown (FRONTIER_MON_UNOWN) is forbidden on opponent Factory teams.
        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        // Ensure none of the opponent's Pokémon are the same as the potential rental Pokémon for the player
        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[monId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        // "High tier" Pokémon are only allowed on open level mode
        if (lvlMode == FRONTIER_LVL_50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != firstMonId + i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (k != firstMonId + i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        gFrontierTempParty[i] = monId;
        i++;
    }
}

static void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void SetRentalsToOpponentParty(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId = gFrontierTempParty[i];
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gParties[B_TRAINER_OPPONENT_A][i].box, MON_DATA_ATK_IV);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_PERSONALITY);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gParties[B_TRAINER_OPPONENT_A][i].box, MON_DATA_ABILITY_NUM);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gFacilityTrainerMons[gFrontierTempParty[i]].heldItem);
    }
}

static void SetPlayerAndOpponentParties(void)
{
    int i;
    u8 monLevel;
    u16 monId;
    u8 ivs;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = TENT_MIN_LEVEL;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = FRONTIER_MAX_LEVEL_OPEN;
        else
            monLevel = FRONTIER_MAX_LEVEL_50;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i].ivs;

            CreateFacilityMon(&gFacilityTrainerMons[monId], monLevel, ivs, READ_OTID_FROM_SAVE, FLAG_FRONTIER_MON_FACTORY, &gParties[B_TRAINER_PLAYER][i]);
        }
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
    case 2:
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs;
            CreateFacilityMon(&gFacilityTrainerMons[monId], monLevel, ivs, READ_OTID_FROM_SAVE, FLAG_FRONTIER_MON_FACTORY, &gParties[B_TRAINER_OPPONENT_A][i]);
        }
        break;
    }
}

static void GenerateInitialRentalMons(void)
{
    int i, j;
    u8 firstMonId;
    u8 battleMode;
    enum FrontierLevelMode lvlMode;
    u8 challengeNum;
    enum FrontierLevelMode factoryLvlMode;
    u8 factoryBattleMode;
    u8 rentalRank;
    u16 monId;
    enum Species currSpecies;
    enum Species species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    enum Item heldItems[PARTY_SIZE];

    gFacilityTrainers = gBattleFrontierTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = SPECIES_NONE;
        monIds[i] = 0;
        heldItems[i] = ITEM_NONE;
    }
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        factoryBattleMode = FRONTIER_MODE_DOUBLES;
    else
        factoryBattleMode = FRONTIER_MODE_SINGLES;

    gFacilityTrainerMons = gBattleFrontierMons;
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
    {
        factoryLvlMode = FRONTIER_LVL_OPEN;
        firstMonId = 0;
    }
    else
    {
        factoryLvlMode = FRONTIER_LVL_50;
        firstMonId = 0;
    }
    rentalRank = GetNumPastRentalsRank(factoryBattleMode, factoryLvlMode);

    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        if (i < rentalRank) // The more times the player has rented, the more initial rentals are generated from a better set of Pokémon
            monId = GetFactoryMonId(factoryLvlMode, challengeNum, TRUE);
        else
            monId = GetFactoryMonId(factoryLvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        // Cannot have two Pokémon of the same species.
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 existingMonId = monIds[j];
            if (existingMonId == monId)
                break;
            if (species[j] == gFacilityTrainerMons[monId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monId].species;
                else
                    break;
            }
        }
        if (j != firstMonId + i)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            if (heldItems[j] != ITEM_NONE && heldItems[j] == gFacilityTrainerMons[monId].heldItem)
            {
                if (gFacilityTrainerMons[monId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != firstMonId + i)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monId;
        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        monIds[i] = monId;
        i++;
    }
}

// Determines if the upcoming opponent has a single most-common
// type in its party. If there are two different types that are
// tied, then the opponent is deemed to have no preferred type,
// and NUMBER_OF_MON_TYPES is the result.
static void GetOpponentMostCommonMonType(void)
{
    u8 i;
    u8 typeCounts[NUMBER_OF_MON_TYPES];
    u8 mostCommonTypes[2];

    gFacilityTrainerMons = gBattleFrontierMons;

    // Count the number of times each type occurs in the opponent's party.
    for (i = TYPE_NORMAL; i < NUMBER_OF_MON_TYPES; i++)
        typeCounts[i] = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        enum Species species = gFacilityTrainerMons[gFrontierTempParty[i]].species;
        typeCounts[GetSpeciesType(species, 0)]++;
        if (GetSpeciesType(species, 0) != GetSpeciesType(species, 1))
            typeCounts[GetSpeciesType(species, 1)]++;
    }

    // Determine which are the two most-common types.
    // The second most-common type is only updated if
    // its count is equal to the most-common type.
    mostCommonTypes[0] = 0;
    mostCommonTypes[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typeCounts[mostCommonTypes[0]] < typeCounts[i])
            mostCommonTypes[0] = i;
        else if (typeCounts[mostCommonTypes[0]] == typeCounts[i])
            mostCommonTypes[1] = i;
    }

    if (typeCounts[mostCommonTypes[0]] != 0)
    {
        // The most-common type must be strictly greater than
        // the second-most-common type, or the top two must be
        // the same type.
        if (typeCounts[mostCommonTypes[0]] > typeCounts[mostCommonTypes[1]])
            gSpecialVar_Result = mostCommonTypes[0];
        else if (mostCommonTypes[0] == mostCommonTypes[1])
            gSpecialVar_Result = mostCommonTypes[0];
        else
            gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
    else
    {
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
}

static void GetOpponentBattleStyle(void)
{
    u8 i, j, count;
    u8 stylePoints[FACTORY_NUM_STYLES];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < FACTORY_NUM_STYLES; i++)
        stylePoints[i] = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u8 battleStyle = GetMoveBattleStyle(gFacilityTrainerMons[monId].moves[j]);
            stylePoints[battleStyle]++;
        }
    }

    gSpecialVar_Result = FACTORY_STYLE_NONE;
    for (i = 1; i < FACTORY_NUM_STYLES; i++)
    {
        if (stylePoints[i] >= sRequiredMoveCounts[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }

    // Has no singular style
    if (count > 2)
        gSpecialVar_Result = FACTORY_NUM_STYLES;
}

static enum FactoryStyle GetMoveBattleStyle(enum Move move)
{
    enum FactoryStyle style = gBattleMoveEffects[GetMoveEffect(move)].battleFactoryStyle;

    if (style != FACTORY_STYLE_NONE)
        return style;

    // Conditional effects
    switch (GetMoveEffect(move))
    {
    case EFFECT_TWO_TURNS_ATTACK:
        // Potential to miss a two-turn move
        if (GetMoveAccuracy(move) < 100 && GetMoveAccuracy(move) != 0)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    case EFFECT_RECOIL:
        // Only higher recoil moves are considered risky
        if (GetMoveRecoil(move) >= 33)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    default:
        break;
    }
    // Bad secondary effects for the user
    if (MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE)
     || MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_STAT_MINUS))
        return FACTORY_STYLE_HIGH_RISK;

    // Non-volatile effects
    if (GetMoveNonVolatileStatus(move) != MOVE_EFFECT_NONE)
        return FACTORY_STYLE_SLOW_STEADY;

    if (IsExplosionMove(move))
        return FACTORY_STYLE_HIGH_RISK;

    return FACTORY_STYLE_NONE;
}

bool8 InBattleFactory(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM;
}

static void RestorePlayerPartyHeldItems(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gParties[B_TRAINER_PLAYER][i],
                   MON_DATA_HELD_ITEM,
                   &gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].heldItem);
    }
}

// Get the IV to use for the opponent's pokémon.
// The IVs get higher for each subsequent challenge and for
// the last trainer in each challenge. Noland is an exception
// to this, as he uses the IVs that would be used by the regular
// trainers 2 challenges ahead of the current one.
// Due to a mistake in FillFactoryFrontierTrainerParty, the
// challenge number used to determine the IVs for regular trainers
// is Battle Tower's instead of Battle Factory's.
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle)
{
    u8 ivSet;
    bool8 useHigherIV = isLastBattle ? TRUE : FALSE;

// The Factory has an out-of-bounds access when generating the rental draft for round 9 (challengeNum==8),
// or the "elevated" rentals from round 8 (challengeNum+1==8)
// This happens to land on a number higher than 31, which is interpreted as "random IVs"
#ifdef BUGFIX
    if (challengeNum >= ARRAY_COUNT(sFixedIVTable))
#else
    if (challengeNum > ARRAY_COUNT(sFixedIVTable))
#endif
        ivSet = ARRAY_COUNT(sFixedIVTable) - 1;
    else
        ivSet = challengeNum;

    return sFixedIVTable[ivSet][useHigherIV];
}

void FillFactoryBrainParty(void)
{
    int i, j, k;
    enum Species species[FRONTIER_PARTY_SIZE];
    enum Item heldItems[FRONTIER_PARTY_SIZE];
    int monLevel;
    u8 fixedIV;
    u32 otId;

    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, FALSE);
    monLevel = SetFacilityPtrsGetLevel();
    i = 0;
    otId = READ_OTID_FROM_SAVE;

    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;
        if (monLevel == FRONTIER_MAX_LEVEL_50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (monId == gSaveBlock2Ptr->frontier.rentalMons[j].monId)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                monLevel, fixedIV, otId, FLAG_FRONTIER_MON_FACTORY,
                &gParties[B_TRAINER_OPPONENT_A][i]);
        i++;
    }
}

static u16 GetFactoryMonId(enum FrontierLevelMode lvlMode, u8 challengeNum, bool8 useBetterRange)
{
    u16 numMons, monId;
    u16 adder; // Used to skip past early mons for open level

    if (lvlMode == FRONTIER_LVL_50)
        adder = 0;
    else
        adder = 8;

    if (challengeNum < 7)
    {
        if (useBetterRange)
        {
            numMons = (sInitialRentalMonRanges[adder + challengeNum + 1][1] - sInitialRentalMonRanges[adder + challengeNum + 1][0]) + 1;
            monId = Random() % numMons;
            monId += sInitialRentalMonRanges[adder + challengeNum + 1][0];
        }
        else
        {
            numMons = (sInitialRentalMonRanges[adder + challengeNum][1] - sInitialRentalMonRanges[adder + challengeNum][0]) + 1;
            monId = Random() % numMons;
            monId += sInitialRentalMonRanges[adder + challengeNum][0];
        }
    }
    else
    {
        u16 challenge = challengeNum;
        if (challenge != 7)
            challenge = 7; // why bother assigning it above at all

        numMons = (sInitialRentalMonRanges[adder + challenge][1] - sInitialRentalMonRanges[adder + challenge][0]) + 1;
        monId = Random() % numMons;
        monId += sInitialRentalMonRanges[adder + challenge][0];
    }

    return monId;
}

u8 GetNumPastRentalsRank(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u8 ret;
    u8 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u64 GetAiScriptsInBattleFactory(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (lvlMode == FRONTIER_LVL_TENT)
    {
        return 0;
    }
    else
    {
        int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        int challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;

        if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
        else if (challengeNum < 2)
            return 0;
        else if (challengeNum < 4)
            return AI_FLAG_CHECK_BAD_MOVE;
        else
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
    }
}

static void FillFactoryFrontierTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i;
    u8 level;
    u8 fixedIV;
    u32 otID;

    if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
    // By mistake Battle Tower's Level 50 challenge number is used to determine the IVs for Battle Factory.
    #ifdef BUGFIX
        enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    #else
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][FRONTIER_LVL_50] / FRONTIER_STAGES_PER_CHALLENGE;
    #endif
        if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
            fixedIV = GetFactoryMonFixedIV(challengeNum, FALSE);
        else
            fixedIV = GetFactoryMonFixedIV(challengeNum, TRUE); // Last trainer in challenge uses higher IVs
    }
    else if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        for (i = firstMonId; i < firstMonId + FRONTIER_PARTY_SIZE; i++)
            CreateBattleTowerMon(&gParties[B_TRAINER_OPPONENT_A][i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
    #endif //FREE_BATTLE_TOWER_E_READER
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        FillFactoryBrainParty();
        return;
    }
    else
    {
        fixedIV = MAX_PER_STAT_IVS;
    }

    level = SetFacilityPtrsGetLevel();
    otID = READ_OTID_FROM_SAVE;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                level, fixedIV, otID, FLAG_FRONTIER_MON_FACTORY,
                &gParties[B_TRAINER_OPPONENT_A][firstMonId + i]);
    }
}

static void FillFactoryTentTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i;
    u8 level = TENT_MIN_LEVEL;
    u8 fixedIV = 0;
    u32 otID = READ_OTID_FROM_SAVE;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                level, fixedIV, otID, 0,
                &gParties[B_TRAINER_OPPONENT_A][firstMonId + i]);
    }
}

void FillFactoryTrainerParty(void)
{
    ZeroEnemyPartyMons();
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        FillFactoryFrontierTrainerParty(TRAINER_BATTLE_PARAM.opponentA, 0);
    else
        FillFactoryTentTrainerParty(TRAINER_BATTLE_PARAM.opponentA, 0);
}

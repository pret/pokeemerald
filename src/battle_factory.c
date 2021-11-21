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
#include "constants/frontier_util.h"
#include "constants/layouts.h"
#include "constants/trainers.h"
#include "constants/moves.h"

// IWRAM bss
static bool8 sPerformedRentalSwap;

// This file's functions.
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
static u16 GetFactoryMonId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange);
static u8 GetMoveBattleStyle(u16 move);

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

static const u16 sMoves_TotalPreparation[] =
{
    MOVE_SWORDS_DANCE, MOVE_GROWTH, MOVE_MEDITATE, MOVE_AGILITY, MOVE_DOUBLE_TEAM, MOVE_HARDEN,
    MOVE_MINIMIZE, MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_BARRIER, MOVE_FOCUS_ENERGY, MOVE_AMNESIA,
    MOVE_ACID_ARMOR, MOVE_SHARPEN, MOVE_CONVERSION, MOVE_CONVERSION_2, MOVE_BELLY_DRUM, MOVE_PSYCH_UP,
    MOVE_CHARGE, MOVE_SNATCH, MOVE_TAIL_GLOW, MOVE_COSMIC_POWER, MOVE_IRON_DEFENSE, MOVE_HOWL, MOVE_BULK_UP, MOVE_CALM_MIND, MOVE_DRAGON_DANCE,
    MOVE_NONE
};

static const u16 sMoves_ImpossibleToPredict[] =
{
    MOVE_MIMIC, MOVE_METRONOME, MOVE_MIRROR_MOVE, MOVE_TRANSFORM, MOVE_SUBSTITUTE, MOVE_SKETCH, MOVE_CURSE,
    MOVE_PRESENT, MOVE_FOLLOW_ME, MOVE_TRICK, MOVE_ROLE_PLAY, MOVE_ASSIST, MOVE_SKILL_SWAP, MOVE_CAMOUFLAGE,
    MOVE_NONE
};

static const u16 sMoves_WeakeningTheFoe[] =
{
    MOVE_SAND_ATTACK, MOVE_TAIL_WHIP, MOVE_LEER, MOVE_GROWL, MOVE_STRING_SHOT, MOVE_SCREECH, MOVE_SMOKESCREEN, MOVE_KINESIS,
    MOVE_FLASH, MOVE_COTTON_SPORE, MOVE_SPITE, MOVE_SCARY_FACE, MOVE_CHARM, MOVE_KNOCK_OFF, MOVE_SWEET_SCENT, MOVE_FEATHER_DANCE,
    MOVE_FAKE_TEARS, MOVE_METAL_SOUND, MOVE_TICKLE,
    MOVE_NONE
};

static const u16 sMoves_HighRiskHighReturn[] =
{
    MOVE_GUILLOTINE, MOVE_HORN_DRILL, MOVE_DOUBLE_EDGE, MOVE_HYPER_BEAM, MOVE_COUNTER, MOVE_FISSURE,
    MOVE_BIDE, MOVE_SELF_DESTRUCT, MOVE_SKY_ATTACK, MOVE_EXPLOSION, MOVE_FLAIL, MOVE_REVERSAL, MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG, MOVE_PAIN_SPLIT, MOVE_MIRROR_COAT, MOVE_MEMENTO, MOVE_GRUDGE, MOVE_FACADE, MOVE_FOCUS_PUNCH,
    MOVE_BLAST_BURN, MOVE_HYDRO_CANNON, MOVE_OVERHEAT, MOVE_FRENZY_PLANT, MOVE_PSYCHO_BOOST, MOVE_VOLT_TACKLE,
    MOVE_NONE
};

static const u16 sMoves_Endurance[] =
{
    MOVE_MIST, MOVE_RECOVER, MOVE_LIGHT_SCREEN, MOVE_HAZE, MOVE_REFLECT, MOVE_SOFT_BOILED, MOVE_REST, MOVE_PROTECT,
    MOVE_DETECT, MOVE_ENDURE, MOVE_MILK_DRINK, MOVE_HEAL_BELL, MOVE_SAFEGUARD, MOVE_BATON_PASS, MOVE_MORNING_SUN,
    MOVE_SYNTHESIS, MOVE_MOONLIGHT, MOVE_SWALLOW, MOVE_WISH, MOVE_INGRAIN, MOVE_MAGIC_COAT, MOVE_RECYCLE, MOVE_REFRESH,
    MOVE_MUD_SPORT, MOVE_SLACK_OFF, MOVE_AROMATHERAPY, MOVE_WATER_SPORT,
    MOVE_NONE
};

static const u16 sMoves_SlowAndSteady[] =
{
    MOVE_SING, MOVE_SUPERSONIC, MOVE_DISABLE, MOVE_LEECH_SEED, MOVE_POISON_POWDER, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER,
    MOVE_THUNDER_WAVE, MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_GLARE, MOVE_POISON_GAS, MOVE_LOVELY_KISS, MOVE_SPORE,
    MOVE_SPIDER_WEB, MOVE_SWEET_KISS, MOVE_SPIKES, MOVE_SWAGGER, MOVE_MEAN_LOOK, MOVE_ATTRACT, MOVE_ENCORE, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_WILL_O_WISP, MOVE_TAUNT, MOVE_YAWN, MOVE_IMPRISON, MOVE_SNATCH, MOVE_TEETER_DANCE, MOVE_GRASS_WHISTLE, MOVE_BLOCK,
    MOVE_NONE
};

static const u16 sMoves_DependsOnTheBattlesFlow[] =
{
    MOVE_SANDSTORM, MOVE_RAIN_DANCE, MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_WEATHER_BALL,
    MOVE_NONE
};

// Excludes FACTORY_STYLE_NONE
static const u16 *const sMoveStyles[FACTORY_NUM_STYLES - 1] =
{
    [FACTORY_STYLE_PREPARATION - 1]   = sMoves_TotalPreparation,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = sMoves_SlowAndSteady,
    [FACTORY_STYLE_ENDURANCE - 1]     = sMoves_Endurance,
    [FACTORY_STYLE_HIGH_RISK - 1]     = sMoves_HighRiskHighReturn,
    [FACTORY_STYLE_WEAKENING - 1]     = sMoves_WeakeningTheFoe,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = sMoves_ImpossibleToPredict,
    [FACTORY_STYLE_WEATHER - 1]       = sMoves_DependsOnTheBattlesFlow,
};

static void (* const sBattleFactoryFunctions[])(void) =
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
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
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
    for (i = 0; i < 6; i++)
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = 0xFFFF;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        gFrontierTempParty[i] = 0xFFFF;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
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
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
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
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    int firstMonId = 0;
    u16 trainerId = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / 7;
    gFacilityTrainers = gBattleFrontierTrainers;

    do
    {
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_A = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 6)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);
        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        for (j = 0; j < 6; j++)
        {
            if (gFacilityTrainerMons[monId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != 6)
            continue;

        if (lvlMode == FRONTIER_LVL_50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != firstMonId + i)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
                break;
        }
        if (k != firstMonId + i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
        gFrontierTempParty[i] = monId;
        i++;
    }
}

static void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
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
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ATK_IV, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData(&gEnemyParty[i], MON_DATA_PERSONALITY, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ABILITY_NUM, NULL);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[gFrontierTempParty[i]].itemTableId]);
    }
}

static void SetPlayerAndOpponentParties(void)
{
    int i, j, k;
    int count = 0;
    u8 bits = 0;
    u8 monLevel;
    u16 monId;
    u16 evs;
    u8 ivs;
    u8 friendship;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = 30;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = 100;
        else
            monLevel = 50;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i].ivs;
            CreateMon(&gPlayerParty[i],
                      gFacilityTrainerMons[monId].species,
                      monLevel,
                      ivs,
                      TRUE, gSaveBlock2Ptr->frontier.rentalMons[i].personality,
                      OT_ID_PLAYER_ID, 0);

            count = 0;
            bits = gFacilityTrainerMons[monId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monId].evSpread & bits)
                    SetMonData(&gPlayerParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gPlayerParty[i]);
            friendship = 0;
            for (k = 0; k < MAX_MON_MOVES; k++)
                SetMonMoveAvoidReturn(&gPlayerParty[i], gFacilityTrainerMons[monId].moves[k], k);
            SetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP, &friendship);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
            SetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM, &gSaveBlock2Ptr->frontier.rentalMons[i].abilityNum);
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
            CreateMon(&gEnemyParty[i],
                      gFacilityTrainerMons[monId].species,
                      monLevel,
                      ivs,
                      TRUE, gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality,
                      OT_ID_PLAYER_ID, 0);

            count = 0;
            bits = gFacilityTrainerMons[monId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monId].evSpread & bits)
                    SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gEnemyParty[i]);
            for (k = 0; k < MAX_MON_MOVES; k++)
                SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monId].moves[k], k);
            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
            SetMonData(&gEnemyParty[i], MON_DATA_ABILITY_NUM, &gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum);
        }
        break;
    }
}

static void GenerateInitialRentalMons(void)
{
    int i, j;
    u8 firstMonId;
    u8 battleMode;
    u8 lvlMode;
    u8 challengeNum;
    u8 factoryLvlMode;
    u8 factoryBattleMode;
    u8 rentalRank;
    u16 monId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    gFacilityTrainers = gBattleFrontierTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
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
        if (i < rentalRank) // The more times the player has rented, the more initial rentals are generated from a better set of pokemon
            monId = GetFactoryMonId(factoryLvlMode, challengeNum, TRUE);
        else
            monId = GetFactoryMonId(factoryLvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        // Cannot have two pokemon of the same species.
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
            if (heldItems[j] != 0 && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
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
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
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
        u32 species = gFacilityTrainerMons[gFrontierTempParty[i]].species;
        typeCounts[gBaseStats[species].type1]++;
        if (gBaseStats[species].type1 != gBaseStats[species].type2)
            typeCounts[gBaseStats[species].type2]++;
    }

    // Determine which are the two most-common types.
    // The second most-common type is only updated if
    // its count is equal to the most-common type.
    mostCommonTypes[0] = TYPE_NORMAL;
    mostCommonTypes[1] = TYPE_NORMAL;
    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
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

static u8 GetMoveBattleStyle(u16 move)
{
    const u16 *moves;
    u8 i, j;

    for (i = 0; i < ARRAY_COUNT(sMoveStyles); i++)
    {
        for (j = 0, moves = sMoveStyles[i]; moves[j] != MOVE_NONE; j++)
        {
            if (moves[j] == move)
                return i + 1;
        }
    }
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
        SetMonData(&gPlayerParty[i],
                   MON_DATA_HELD_ITEM,
                   &gBattleFrontierHeldItems[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].itemTableId]);
    }
}

u8 GetFactoryMonFixedIV(u8 arg0, u8 arg1)
{
    u8 a1;
    u8 a2 = (arg1 != 0) ? 1 : 0;

    if (arg0 > 8)
        a1 = 7;
    else
        a1 = arg0;

    return sFixedIVTable[a1][a2];
}

void FillFactoryBrainParty(void)
{
    int i, j, k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    u8 friendship;
    int monLevel;
    u8 fixedIV;
    u32 otId;

    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, 0);
    monLevel = SetFacilityPtrsGetLevel();
    i = 0;
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;
        if (monLevel == 50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        for (j = 0; j < 6; j++)
        {
            if (monId == gSaveBlock2Ptr->frontier.rentalMons[j].monId)
                break;
        }
        if (j != 6)
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
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[i],
                                             gFacilityTrainerMons[monId].species,
                                             monLevel,
                                             gFacilityTrainerMons[monId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monId].evSpread,
                                             otId);

        friendship = 0;
        for (k = 0; k < MAX_MON_MOVES; k++)
            SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monId].moves[k], k);
        SetMonData(&gEnemyParty[i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
        i++;
    }
}

static u16 GetFactoryMonId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange)
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

u8 GetNumPastRentalsRank(u8 battleMode, u8 lvlMode)
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

u32 GetAiScriptsInBattleFactory(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (lvlMode == FRONTIER_LVL_TENT)
    {
        return 0;
    }
    else
    {
        int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        int challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;

        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
        else if (challengeNum < 2)
            return 0;
        else if (challengeNum < 4)
            return AI_FLAG_CHECK_BAD_MOVE;
        else
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
    }
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot)
{
    u16 move = moveArg;
    if (moveArg == MOVE_RETURN)
        move = MOVE_FRUSTRATION;
    SetMonMoveSlot(mon, move, moveSlot);
}

#include "global.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "random_mon_generation.h"
#include "script.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokedex.h"
#include "constants/pokeball.h"
#include "constants/species.h"

#define EXHAUSTIVE_SEARCH_POOL_MAX_SIZE 20
#define INVALID_RANDOM_SPECIES SPECIES_NONE

enum RandomSpeciesDexMode
{
    RANDOM_MON_DEX_NATIONAL,
    RANDOM_MON_DEX_HOENN,
};

struct RandomSpeciesGeneratorOptions
{
    const enum Species *bannedSpecies;
    const enum Species *speciesPool;
    bool32 (*filterFunc)(enum Species species, const struct FilterFuncArgs *filterFuncArgs);
    u32 speciesPoolCount:11;
    u32 bannedSpeciesCount:11;
    u32 banLegendary:1;
    u32 banMythical:1;
    u32 banSubLegendary:1;
    u32 banUltraBeast:1;
    u32 banParadox:1;
    u32 randomizeForms:1;
    enum RandomSpeciesDexMode dexMode:1;
    u32 padding:3;
};

struct RandomItemGeneratorOptions
{
    const enum Item *heldItemPool;
    const enum HoldEffect *bannedHoldEffects;
    bool32 (*filterFunc)(enum Item item, const struct FilterFuncArgs *filterFuncArgs);
    u16 heldItemPoolCount;
    u16 bannedHoldEffectsCount;
};

static enum Species GetSpeciesCandidateForm(enum Species species, const struct RandomSpeciesGeneratorOptions *options, const struct FilterFuncArgs *filterFuncArgs);
static bool32 UNUSED IsInBstRangeFilterFunc(enum Species species, const struct FilterFuncArgs *filterFuncArgs);
static enum Species GetRandomSpeciesAtIndex(const struct RandomSpeciesGeneratorOptions *options, u32 index);
static enum Species SlowPickRandomSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs);
static enum Species FastPickRandomSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs);
static enum Item GetRandomItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index);
static bool32 UNUSED IsHeldItemFilterFunc(enum Item item, const struct FilterFuncArgs *filterFuncArgs);
static enum Item SlowPickRandomItem(const struct RandomItemGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs);
static enum Item FastPickRandomItem(const struct RandomItemGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs);
static bool32 MoveOrder(enum Move moveA, enum Move moveB);
static void SortMoves(enum Move *moves);
static bool32 IsMoveInMoveset(enum Move move, enum Move *moves, u32 count);

#if TESTING
#include "../test/random_mon_generator.h"
#else
#include "data/random_mon_generator.h"
#endif

static bool32 IsSpeciesBannedByRandomSpeciesOptions(enum Species species, const struct RandomSpeciesGeneratorOptions *options, const struct FilterFuncArgs *filterFuncArgs)
{
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[species];

    for (u32 i = 0; i < options->bannedSpeciesCount; i++)
    {
        if (baseSpecies == GET_BASE_SPECIES_ID(options->bannedSpecies[i]))
            return TRUE;
    }

    if (options->banLegendary && speciesInfo->isRestrictedLegendary)
        return TRUE;
    if (options->banMythical && speciesInfo->isMythical)
        return TRUE;
    if (options->banSubLegendary && speciesInfo->isSubLegendary)
        return TRUE;
    if (options->banUltraBeast && speciesInfo->isUltraBeast)
        return TRUE;
    if (options->banParadox && speciesInfo->isParadox)
        return TRUE;
    if (options->filterFunc != NULL && !options->filterFunc(species, filterFuncArgs))
        return TRUE;

    return FALSE;
}

/*
* The below function uses arg1 and arg2 as BST centerpoint and BST leniency points.
* If a mon is within centerpoint +/- leniency, it's valid.
* This only applies if .filterFunc for your struct points to this function.
*/

static bool32 UNUSED IsInBstRangeFilterFunc(enum Species species, const struct FilterFuncArgs *filterFuncArgs)
{
    u16 bstStandard = filterFuncArgs->arg1;
    u16 bstLeniency = filterFuncArgs->arg2;
    u16 bst = GetSpeciesBaseStatTotal(GET_BASE_SPECIES_ID(species));
    u16 minBst;
    u16 maxBst;

    assertf(bstStandard != FILTER_FUNC_ARG_NONE && bstLeniency != FILTER_FUNC_ARG_NONE, "missing BST filter args")
    {
        return FALSE;
    }

    minBst = (bstStandard > bstLeniency) ? bstStandard - bstLeniency : 0;
    maxBst = bstStandard + bstLeniency;

    return bst >= minBst && bst <= maxBst;
}

static enum Species GetRandomSpeciesAtIndex(const struct RandomSpeciesGeneratorOptions *options, u32 index)
{
    if (options->speciesPoolCount != 0)
        return options->speciesPool[index];

    if (options->dexMode == RANDOM_MON_DEX_HOENN)
        return NationalPokedexNumToSpecies(HoennToNationalOrder(index + 1));

    return NationalPokedexNumToSpecies(index + 1);
}

static bool32 IsRandomSpeciesFormTableException(enum Species species)
{
    switch (GET_BASE_SPECIES_ID(species))
    {
    case SPECIES_ROTOM:
    case SPECIES_ORICORIO:
    case SPECIES_TORNADUS:
    case SPECIES_THUNDURUS:
    case SPECIES_LANDORUS:
    case SPECIES_ENAMORUS:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsRandomSpeciesInFormChangeTables(enum Species species, const u16 *formTable)
{
    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct FormChange *formChanges = GetSpeciesFormChanges(formTable[i]);

        for (u32 j = 0; formChanges != NULL && formChanges[j].method != FORM_CHANGE_TERMINATOR; j++)
        {
            if (formChanges[j].targetSpecies == species)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 IsRandomSpeciesInFusionTables(enum Species species, const u16 *formTable)
{
    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct Fusion *fusionTable = gFusionTablePointers[formTable[i]];

        for (u32 j = 0; fusionTable != NULL && fusionTable[j].fusionStorageIndex != FUSION_TERMINATOR; j++)
        {
            if (fusionTable[j].targetSpecies1 == species
             || fusionTable[j].targetSpecies2 == species
             || fusionTable[j].fusingIntoMon == species)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 IsRandomSpeciesInFormOrFusionTables(enum Species species, const u16 *formTable)
{
    return IsRandomSpeciesInFormChangeTables(species, formTable)
        || IsRandomSpeciesInFusionTables(species, formTable);
}

static bool32 IsRandomSpeciesFormAllowed(enum Species species, const u16 *formTable)
{
    const struct SpeciesInfo *speciesInfo;
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);

    switch (species) // Special case because darm has galarian forms (desired) and zen mode forms (not desired)
    {
    case SPECIES_DARMANITAN_ZEN:
    case SPECIES_DARMANITAN_GALAR_ZEN:
        return FALSE;
    case SPECIES_DARMANITAN_GALAR:
        return TRUE;
    default:
        break;
    }

    if (species != baseSpecies
     && !IsRandomSpeciesFormTableException(baseSpecies)
     && IsRandomSpeciesInFormOrFusionTables(species, formTable))
        return FALSE;

    speciesInfo = &gSpeciesInfo[species];

    return !speciesInfo->isMegaEvolution
        && !speciesInfo->isGigantamax
        && !speciesInfo->isTotem
        && !speciesInfo->isUltraBurst
        && !speciesInfo->cannotBeTraded
        && !speciesInfo->isTeraForm
        && !speciesInfo->isPrimalReversion;
}

static enum Species GetSpeciesCandidateForm(enum Species species, const struct RandomSpeciesGeneratorOptions *options, const struct FilterFuncArgs *filterFuncArgs)
{
    const u16 *formTable = GetSpeciesFormTable(species);
    u16 validFormsCount = 0;
    u16 validForms[RANDOM_MON_MAX_FORMS];

    if (!options->randomizeForms || formTable == NULL)
    {
        if (IsSpeciesBannedByRandomSpeciesOptions(species, options, filterFuncArgs))
            return SPECIES_NONE;
        return species;
    }

    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        if (IsRandomSpeciesFormAllowed(formTable[i], formTable)
         && !IsSpeciesBannedByRandomSpeciesOptions(formTable[i], options, filterFuncArgs))
            validForms[validFormsCount++] = i;
    }

    if (validFormsCount == 0)
        return SPECIES_NONE;

    return formTable[validForms[RandomUniform(RNG_NONE, 0, validFormsCount - 1)]];
}

enum Species GetRandomSpecies(u32 optionId, const struct FilterFuncArgs *filterFuncArgs)
{
    const struct RandomSpeciesGeneratorOptions *options;
    u32 poolSize;

    assertf(optionId < RANDOM_SPECIES_OPTIONS_COUNT, "invalid random species option: %d", optionId)
    {
        return INVALID_RANDOM_SPECIES;
    }

    options = &sRandomSpeciesGeneratorOptions[optionId];

    if (options->speciesPoolCount != 0)
    {
        assertf(options->speciesPool != NULL, "positive speciesPoolCount passed with empty speciesPool")
        {
            return INVALID_RANDOM_SPECIES;
        }
        poolSize = options->speciesPoolCount;
    }
    else if (options->dexMode == RANDOM_MON_DEX_HOENN)
    {
        poolSize = HOENN_DEX_COUNT - 1;
    }
    else
    {
        poolSize = NATIONAL_DEX_COUNT;
    }

    if (poolSize <= EXHAUSTIVE_SEARCH_POOL_MAX_SIZE)
        return SlowPickRandomSpecies(options, poolSize, filterFuncArgs);

    return FastPickRandomSpecies(options, poolSize, filterFuncArgs);
}

static enum Species SlowPickRandomSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs)
{
    u32 eligibleSpeciesCount = 0;
    enum Species eligibleSpecies[EXHAUSTIVE_SEARCH_POOL_MAX_SIZE];

    for (u32 i = 0; i < poolSize; i++)
    {
        enum Species species = GetRandomSpeciesAtIndex(options, i);
        species = GetSpeciesCandidateForm(species, options, filterFuncArgs);
        if (species != SPECIES_NONE)
            eligibleSpecies[eligibleSpeciesCount++] = species;
    }

    if (eligibleSpeciesCount == 0)
    {
        errorf("Could not find a random species matching random species options");
        return INVALID_RANDOM_SPECIES;
    }

    return eligibleSpecies[RandomUniform(RNG_NONE, 0, eligibleSpeciesCount - 1)];
}

static enum Species FastPickRandomSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs)
{
    for (u32 i = 0; i < poolSize; i++)
    {
        enum Species species = GetRandomSpeciesAtIndex(options, RandomUniform(RNG_NONE, 0, poolSize - 1));
        species = GetSpeciesCandidateForm(species, options, filterFuncArgs);
        if (species != SPECIES_NONE)
            return species;
    }

    errorf("Could not get random species after %d tries", poolSize);
    return INVALID_RANDOM_SPECIES;
}

static bool32 IsRandomItemAllowed(const struct RandomItemGeneratorOptions *options, enum Item item, const struct FilterFuncArgs *filterFuncArgs)
{
    enum HoldEffect holdEffect = GetItemHoldEffect(item);

    if (GetItemPocket(item) == POCKET_KEY_ITEMS)
        return FALSE;
    if (GetItemPocket(item) == POCKET_TM_HM && GetItemPrice(item) == 0)
        return FALSE;
    for (u32 i = 0; i < options->bannedHoldEffectsCount; i++)
    {
        if (options->bannedHoldEffects[i] == holdEffect)
            return FALSE;
    }
    if (options->filterFunc != NULL && !options->filterFunc(item, filterFuncArgs))
        return FALSE;

    return TRUE;
}

static bool32 UNUSED IsHeldItemFilterFunc(enum Item item, const struct FilterFuncArgs *filterFuncArgs)
{
    (void)filterFuncArgs;

    return GetItemHoldEffect(item) != HOLD_EFFECT_NONE;
}

static enum Item GetRandomItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index)
{
    if (options->heldItemPoolCount != 0)
        return options->heldItemPool[index];

    return index + 1;
}

static enum Item SlowPickRandomItem(const struct RandomItemGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs)
{
    u32 eligibleItemCount = 0;
    enum Item eligibleItems[EXHAUSTIVE_SEARCH_POOL_MAX_SIZE];

    for (u32 i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomItemAtIndex(options, i);
        if (IsRandomItemAllowed(options, item, filterFuncArgs))
            eligibleItems[eligibleItemCount++] = item;
    }

    assertf(eligibleItemCount > 0, "Could not find a random held item matching random item options")
    {
        return ITEM_NONE;
    }

    return eligibleItems[RandomUniform(RNG_NONE, 0, eligibleItemCount - 1)];
}

static enum Item FastPickRandomItem(const struct RandomItemGeneratorOptions *options, u32 poolSize, const struct FilterFuncArgs *filterFuncArgs)
{
    for (u32 i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomItemAtIndex(options, RandomUniform(RNG_NONE, 0, poolSize - 1));
        if (IsRandomItemAllowed(options, item, filterFuncArgs))
            return item;
    }

    errorf("Could not get random held item after %d tries", poolSize);

    return ITEM_NONE;
}

enum Item GetRandomItem(u32 optionId, const struct FilterFuncArgs *filterFuncArgs)
{
    const struct RandomItemGeneratorOptions *options;
    u32 poolSize;

    assertf(optionId < RANDOM_ITEM_OPTIONS_COUNT, "invalid random item option: %d", optionId)
    {
        return ITEM_NONE;
    }

    options = &sRandomItemGeneratorOptions[optionId];

    if (options->heldItemPoolCount != 0)
    {
        assertf(options->heldItemPool != NULL, "positive heldItemPoolCount passed with empty heldItemPool")
        {
            return ITEM_NONE;
        }
        poolSize = options->heldItemPoolCount;
    }
    else
    {
        poolSize = ITEMS_COUNT - 1;
    }

    if (poolSize <= EXHAUSTIVE_SEARCH_POOL_MAX_SIZE)
        return SlowPickRandomItem(options, poolSize, filterFuncArgs);

    return FastPickRandomItem(options, poolSize, filterFuncArgs);
}

enum PokeBall GetRandomBall(void)
{
    return RandomUniform(RNG_RANDOM_BALL, BALL_POKE, POKEBALL_COUNT - 1);
}

static bool32 MoveOrder(enum Move moveA, enum Move moveB)
{
    if (moveA == moveB)
        return FALSE;
    if (moveA == MOVE_NONE)
        return TRUE;
    if (moveA == MOVE_DEFAULT)
        return moveB != MOVE_NONE;
    if (moveA == MOVE_RANDOM_TEACHABLE)
        return moveB != MOVE_NONE && moveB != MOVE_DEFAULT;

    return FALSE;
}

static void SortMoves(enum Move *moves)
{
    u16 temp;

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        for (u32 j = i; j < MAX_MON_MOVES; j++)
        {
            if (MoveOrder(moves[i], moves[j]))
                SWAP(moves[i], moves[j], temp);
        }
    }
}

static bool32 IsMoveInMoveset(enum Move move, enum Move *moves, u32 count)
{
    if (move == MOVE_NONE)
        return FALSE;

    for (u32 i = 0; i < count; i++)
    {
        if (moves[i] == move)
            return TRUE;
    }

    return FALSE;
}

#define IS_DUPLICATE_MOVE(move) IsMoveInMoveset(move, moves, i)

static void AssignDefaultMove(enum Species species, u32 level, enum Move *moves, u32 index)
{
    u32 i = MAX_MON_MOVES;
    moves[index] = MOVE_NONE;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    for (u32 j = 0; learnset[j].move != LEVEL_UP_MOVE_END; j++)
    {
        if (learnset[j].level > level)
            break;
        if (learnset[j].level == 0)
            continue;

        if (!IS_DUPLICATE_MOVE(learnset[j].move))
            moves[index] = learnset[j].move;
    }
}

static void AssignRandomTeachableMove(enum Species species, enum Move *moves, u32 i)
{
    u32 teachableCount = 0;
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

    while (teachableLearnset[teachableCount] != MOVE_UNAVAILABLE)
        teachableCount++;

    bool32 noCandidateFlag;
    enum Move candidate;

    if (teachableCount <= i)
    {
        noCandidateFlag = TRUE;
        for (u32 j = 0; j < teachableCount; j++)
        {
            if (!IS_DUPLICATE_MOVE(teachableLearnset[j]))
            {
                noCandidateFlag = FALSE;
                break;
            }
        }
        if (noCandidateFlag)
            return;
    }

    do {
        candidate = teachableLearnset[RandomUniform(RNG_NONE, 0, teachableCount - 1)];
    } while (IS_DUPLICATE_MOVE(candidate));

    moves[i] = candidate;
}

void ResolveMoves(enum Species species, u32 level, const u16 *movesTemplate, enum Move *moves)
{
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        moves[i] = movesTemplate[i];
    }
    SortMoves(moves);

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] < MOVES_COUNT)
        {
            assertf(!IS_DUPLICATE_MOVE(moves[i]), "move %d was assigned twice", moves[i])
            {
                moves[i] = MOVE_NONE;
            }
            continue;
        }

        enum Move specialMove = moves[i];
        moves[i] = MOVE_NONE;
        if (specialMove == MOVE_RANDOM_TEACHABLE)
            AssignRandomTeachableMove(species, moves, i);
        else if (specialMove == MOVE_DEFAULT)
            moves[i] = MOVE_DEFAULT; // Can't be assigned here because default moves need to be assigned in reverse order
        else
            errorf("Trying to assign invalid move %d when creating pokemon", moves[i]);
    }

    for (s32 i = MAX_MON_MOVES - 1; i >= 0; i--)
    {
        if (moves[i] == MOVE_DEFAULT)
            AssignDefaultMove(species, level, moves, i);
    }
    SortMoves(moves);
}

static u16 ReadFilterFuncArg(struct ScriptContext *ctx)
{
    u16 arg = ScriptReadHalfword(ctx);

    if (arg != FILTER_FUNC_ARG_NONE)
        arg = VarGet(arg);

    return arg;
}

void ScrCmd_getrandomspecies(struct ScriptContext *ctx)
{
    u16 destVar = ScriptReadHalfword(ctx);
    u16 speciesOptionId = VarGet(ScriptReadHalfword(ctx));
    struct FilterFuncArgs filterFuncArgs =
    {
        .arg1 = ReadFilterFuncArg(ctx),
        .arg2 = ReadFilterFuncArg(ctx),
    };

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(destVar);
    VarSet(destVar, GetRandomSpecies(speciesOptionId, &filterFuncArgs));
}

void ScrCmd_getrandomitem(struct ScriptContext *ctx)
{
    u16 destVar = ScriptReadHalfword(ctx);
    u16 itemOptionId = VarGet(ScriptReadHalfword(ctx));
    const struct FilterFuncArgs filterFuncArgs = {0};

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(destVar);
    VarSet(destVar, GetRandomItem(itemOptionId, &filterFuncArgs));
}

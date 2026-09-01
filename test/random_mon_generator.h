enum
{
    SPECIES_GENERATOR_FILTERED_POOL,
    SPECIES_GENERATOR_MYTHICAL_FILTER,
    SPECIES_GENERATOR_BST_FILTER,
    SPECIES_GENERATOR_NO_ARG_FILTER,
    SPECIES_GENERATOR_FORM_FILTER,
    RANDOM_SPECIES_OPTIONS_COUNT,
};

enum
{
    ITEM_GENERATOR_SINGLE_ITEM,
    ITEM_GENERATOR_FILTERED_POOL,
    ITEM_GENERATOR_NONE_POOL,
    ITEM_GENERATOR_HARD_BANNED_POOL,
    ITEM_GENERATOR_HELD_ITEM_FILTER,
    RANDOM_ITEM_OPTIONS_COUNT,
};

static const enum Species sRandomSpeciesOption0SpeciesPool[] =
{
    SPECIES_MEW,
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption1SpeciesPool[] =
{
    SPECIES_MEW,
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption2SpeciesPool[] =
{
    SPECIES_WOBBUFFET,
    SPECIES_MEW,
};

static const enum Species sRandomSpeciesOption3SpeciesPool[] =
{
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption4SpeciesPool[] =
{
    SPECIES_ROTOM,
};

static bool32 IsSpeciesCharizard(enum Species species, const struct FilterFuncArgs *filterFuncArgs)
{
    (void)filterFuncArgs;

    return species == SPECIES_CHARIZARD;
}

static bool32 IsSpeciesRotomHeat(enum Species species, const struct FilterFuncArgs *filterFuncArgs)
{
    (void)filterFuncArgs;

    return species == SPECIES_ROTOM_HEAT;
}

static const enum Item sRandomItemOption0HeldItemPool[] =
{
    ITEM_LEFTOVERS,
};

static const enum Item sRandomItemOption1HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_LUM_BERRY,
};

static const enum Item sRandomItemOption2HeldItemPool[] =
{
    ITEM_NONE,
};

static const enum Item sRandomItemOption3HeldItemPool[] =
{
    ITEM_MACH_BIKE,
    ITEM_HM01,
    ITEM_LEFTOVERS,
};

static const enum Item sRandomItemOption4HeldItemPool[] =
{
    ITEM_POTION,
    ITEM_LEFTOVERS,
};

static const enum HoldEffect sRandomItemOption1BannedHoldEffects[] =
{
    HOLD_EFFECT_LEFTOVERS,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [SPECIES_GENERATOR_FILTERED_POOL] =
    {
        .speciesPool = sRandomSpeciesOption0SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption0SpeciesPool),
        .banMythical = TRUE,
        .randomizeForms = FALSE,
    },
    [SPECIES_GENERATOR_MYTHICAL_FILTER] =
    {
        .speciesPool = sRandomSpeciesOption1SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption1SpeciesPool),
        .banMythical = TRUE,
        .randomizeForms = FALSE,
    },
    [SPECIES_GENERATOR_BST_FILTER] =
    {
        .speciesPool = sRandomSpeciesOption2SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption2SpeciesPool),
        .randomizeForms = FALSE,
        .filterFunc = IsInBstRangeFilterFunc,
    },
    [SPECIES_GENERATOR_NO_ARG_FILTER] =
    {
        .speciesPool = sRandomSpeciesOption3SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption3SpeciesPool),
        .randomizeForms = FALSE,
        .filterFunc = IsSpeciesCharizard,
    },
    [SPECIES_GENERATOR_FORM_FILTER] =
    {
        .speciesPool = sRandomSpeciesOption4SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption4SpeciesPool),
        .randomizeForms = TRUE,
        .filterFunc = IsSpeciesRotomHeat,
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    [ITEM_GENERATOR_SINGLE_ITEM] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
    },
    [ITEM_GENERATOR_FILTERED_POOL] =
    {
        .heldItemPool = sRandomItemOption1HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption1HeldItemPool),
        .bannedHoldEffects = sRandomItemOption1BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption1BannedHoldEffects),
    },
    [ITEM_GENERATOR_NONE_POOL] =
    {
        .heldItemPool = sRandomItemOption2HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption2HeldItemPool),
    },
    [ITEM_GENERATOR_HARD_BANNED_POOL] =
    {
        .heldItemPool = sRandomItemOption3HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption3HeldItemPool),
    },
    [ITEM_GENERATOR_HELD_ITEM_FILTER] =
    {
        .heldItemPool = sRandomItemOption4HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption4HeldItemPool),
        .filterFunc = IsHeldItemFilterFunc,
    },
};

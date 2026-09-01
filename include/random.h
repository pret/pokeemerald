#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE1(val) (1103515245 * (val) + 24691)
#define ISO_RANDOMIZE2(val) (1103515245 * (val) + 12345)

/* Some functions have been added to support Expansion's RNG implementation.
*
* LocalRandom(*val) provides a higher-quality replacement for uses of
* ISO_RANDOMIZE in vanilla Emerald. You can use LocalRandomSeed(u32) to
* create a local state.
*
* It is no longer possible to call Random() in interrupt handlers safely.
* AdvanceRandom() is provided to handle burning numbers in VBlank handlers.
* If you need to use random numbers in the VBlank handler, a local state
* should be used instead.
*
* Random2_32() was added, even though it is not used directly, because the
* underlying RNG always outputs 32 bits.
*/

struct Sfc32State {
    u32 a;
    u32 b;
    u32 c;
    u32 ctr;
};

typedef struct Sfc32State rng_value_t;

#define RNG_VALUE_EMPTY {0}

// Calling this function directly is discouraged.
// Use LocalRandom() instead.
static inline u32 _SFC32_Next(struct Sfc32State *state)
{
    const u32 result = state->a + state->b + state->ctr++;
    state->a = state->b ^ (state->b >> 9);
    state->b = state->c * 9;
    state->c = result + ((state->c << 21) | (state->c >> 11));
    return result;
}

static inline u32 LocalRandom32(rng_value_t *val)
{
    return _SFC32_Next(val);
}

static inline u16 LocalRandom(rng_value_t *val)
{
    return LocalRandom32(val) >> 16;
}

u32 Random32(void);
u32 Random2_32(void);

static inline u16 Random(void)
{
    return Random32() >> 16;
}

void SeedRng(u32 seed);
void SeedRng2(u32 seed);
rng_value_t LocalRandomSeed(u32 seed);

static inline u16 Random2(void)
{
    return Random2_32() >> 16;
}

void AdvanceRandom(void);

extern rng_value_t gRngValue;
extern rng_value_t gRng2Value;

void Shuffle8(void *data, size_t n);
void Shuffle16(void *data, size_t n);
void Shuffle32(void *data, size_t n);
void ShuffleN(void *data, size_t n, size_t size);

static inline void Shuffle(void *data, size_t n, size_t size)
{
    switch (size)
    {
    case 1: Shuffle8(data, n); break;
    case 2: Shuffle16(data, n); break;
    case 4: Shuffle32(data, n); break;
    default: ShuffleN(data, n, size); break;
    }
}

/* Structured random number generator.
 * Instead of the caller converting bits from Random() to a meaningful
 * value, the caller provides metadata that is used to return the
 * meaningful value directly. This allows code to interpret the random
 * call, for example, battle tests know what the domain of a random call
 * is, and can exhaustively test it.
 *
 * RandomTag identifies the purpose of the value.
 *
 * RandomUniform(tag, lo, hi) returns a number from lo to hi inclusive
 * with uniform probability.
 *
 * RandomUniformExcept(tag, lo, hi, reject) returns a number from lo to
 * hi inclusive with uniform probability, excluding those for which
 * reject returns TRUE.
 *
 * RandomElement(tag, array) returns an element in array with uniform
 * probability. The array must be known at compile-time (e.g. a global
 * const array).
 *
 * RandomPercentage(tag, t) returns FALSE with probability 1-t/100,
 * and TRUE with probability t/100.
 *
 * RandomWeighted(tag, w0, w1, ... wN) returns a number from 0 to N
 * inclusive. The return value is proportional to the weights, e.g.
 * RandomWeighted(..., 1, 1) returns 50% 0s and 50% 1s.
 * RandomWeighted(..., 2, 1) returns 2/3 0s and 1/3 1s.
 *
 * RandomChance(tag, successes, total) returns FALSE with probability
 * 1-successes/total, and TRUE with probability successes/total. */

enum RandomTag
{
    RNG_NONE,
    RNG_ACCURACY,
    RNG_CONFUSION,
    RNG_CONFUSION_TURNS,
    RNG_CRITICAL_HIT,
    RNG_CURSED_BODY,
    RNG_CUTE_CHARM,
    RNG_DAMAGE_MODIFIER,
    RNG_EFFECT_SPORE,
    RNG_FLAME_BODY,
    RNG_FORCE_RANDOM_SWITCH,
    RNG_FROZEN,
    RNG_G_MAX_STUN_SHOCK,
    RNG_G_MAX_BEFUDDLE,
    RNG_G_MAX_REPLENISH,
    RNG_G_MAX_SNOOZE,
    RNG_HARVEST,
    RNG_HITS,
    RNG_HOLD_EFFECT_FLINCH,
    RNG_INFATUATION,
    RNG_LOADED_DICE,
    RNG_METRONOME,
    RNG_MOODY_INCREASE,
    RNG_MOODY_DECREASE,
    RNG_RANDOM_FROM_LIST,
    RNG_PARALYSIS,
    RNG_PICKUP,
    RNG_POISON_POINT,
    RNG_POISON_TOUCH,
    RNG_RAMPAGE_TURNS,
    RNG_RANDOM_STAT_UP,
    RNG_SECONDARY_EFFECT,
    RNG_SECONDARY_EFFECT_2,
    RNG_SECONDARY_EFFECT_3,
    RNG_SHED_SKIN,
    RNG_SLEEP_TURNS,
    RNG_TAUNT_TURNS,
    RNG_ENCORE_TURNS,
    RNG_SPEED_TIE,
    RNG_STATIC,
    RNG_STENCH,
    RNG_TOXIC_CHAIN,
    RNG_QUICK_DRAW,
    RNG_QUICK_CLAW,
    RNG_TRACE,
    RNG_FOREWARN,
    RNG_FICKLE_BEAM,
    RNG_AI_ABILITY,
    RNG_AI_SCORE_TIE_DOUBLES_MOVE,
    RNG_AI_SCORE_TIE_DOUBLES_TARGET,
    RNG_AI_SCORE_TIE_SINGLES,
    RNG_AI_SWITCH_HASBADODDS,
    RNG_AI_SWITCH_BADLY_POISONED,
    RNG_AI_SWITCH_CURSED,
    RNG_AI_SWITCH_NIGHTMARE,
    RNG_AI_SWITCH_SEEDED,
    RNG_AI_SWITCH_YAWN,
    RNG_AI_SWITCH_PERISH_SONG,
    RNG_AI_SWITCH_INFATUATION,
    RNG_AI_SWITCH_ABSORBING,
    RNG_AI_SWITCH_ABSORBING_STAY_IN,
    RNG_AI_SWITCH_NATURAL_CURE,
    RNG_AI_SWITCH_REGENERATOR,
    RNG_AI_SWITCH_INTIMIDATE,
    RNG_AI_SWITCH_ENCORE,
    RNG_AI_SWITCH_CHOICE_LOCKED,
    RNG_AI_SWITCH_STATS_LOWERED,
    RNG_AI_SWITCH_SE_DEFENSIVE,
    RNG_AI_SWITCH_TRUANT,
    RNG_AI_SWITCH_WONDER_GUARD,
    RNG_AI_SWITCH_TRAPPER,
    RNG_AI_SWITCH_FREE_TURN,
    RNG_AI_SWITCH_ALL_MOVES_BAD,
    RNG_AI_SWITCH_DYN_FUNC,
    RNG_AI_CONSERVE_TERA,
    RNG_AI_SWITCH_ALL_SCORES_BAD,
    RNG_AI_SWITCH_ABSORBING_HIDDEN_POWER,
    RNG_AI_SWITCH_WISH_PASSING,
    RNG_AI_SWITCH_LOSES_1V1,
    RNG_AI_PP_STALL_DISREGARD_MOVE,
    RNG_AI_SUCKER_PUNCH,
    RNG_AI_CONSIDER_EXPLOSION,
    RNG_AI_FINAL_GAMBIT,
    RNG_AI_SHOULD_PIVOT_BREAK_SASH,
    RNG_SHELL_SIDE_ARM,
    RNG_RANDOM_TARGET,
    RNG_AI_PREDICT_ABILITY,
    RNG_AI_PREDICT_SWITCH,
    RNG_AI_PREDICT_MOVE,
    RNG_AI_STATUS_FOCUS_PUNCH,
    RNG_AI_BOOST_INTO_HAZE,
    RNG_AI_SHOULD_RECOVER,
    RNG_AI_PRIORITIZE_LAST_CHANCE,
    RNG_AI_RANDOM_SWITCHIN_POST_KO,
    RNG_AI_RANDOM_SWITCHIN_MID_BATTLE,
    RNG_AI_RANDOM_VALID_SWITCHIN_POST_KO,
    RNG_AI_RANDOM_VALID_SWITCHIN_MID_BATTLE,
    RNG_HEALER,
    RNG_DEXNAV_ENCOUNTER_LEVEL,
    RNG_POKERUS_PARTY_MEMBER,
    RNG_POKERUS_INFECTION,
    RNG_POKERUS_STRAIN_DISTRIBUTION,
    RNG_POKERUS_SPREAD,
    RNG_POKERUS_SPREAD_SIDE,
    RNG_AI_ASSUME_STATUS_SLEEP,
    RNG_AI_ASSUME_STATUS_NONVOLATILE,
    RNG_AI_ASSUME_STATUS_HIGH_ODDS,
    RNG_AI_ASSUME_STATUS_MEDIUM_ODDS,
    RNG_AI_ASSUME_STATUS_LOW_ODDS,
    RNG_AI_ASSUME_ALL_STATUS,
    RNG_AI_REFRESH_TRICK_ROOM_ON_LAST_TURN,
    RNG_AI_APPLY_TAILWIND_ON_LAST_TURN_OF_TRICK_ROOM,
    RNG_AI_REVERSE_BATTLER_LOGIC_ORDER,
    RNG_WRAP,
    RNG_BALLTHROW_CRITICAL,
    RNG_BALLTHROW_SHAKE,
    RNG_PROTECT_FAIL,
    RNG_PRESENT,
    RNG_MAGNITUDE,
    RNG_FISHING_BITE,
    RNG_FISHING_GEN3_STICKY,
    RNG_WILD_MON_TARGET,
    RNG_AI_FAKE_OUT_SAVE_ALLY,
    RNG_AI_DMG_ROLL_RANDOM,
    RNG_RANDOM_BERRY,
    RNG_DAYCARE_MAKE_EGG,
    RNG_DAYCARE_PICK_NATURE_PARENT,
    RNG_DAYCARE_NATURE_INHERITANCE,
    RNG_DAYCARE_INHERITED_STATS,
    RNG_DAYCARE_PICK_IVS_PARENT,
    RNG_DAYCARE_PICK_BALL_PARENT,
    RNG_DAYCARE_ABILITY_INHERITANCE,
    RNG_DEXNAV_RANDOM_EGG_MOVE,
    RNG_RANDOM_BALL,
};

#define RandomWeighted(tag, ...) \
    ({ \
        const u16 weights[] = { __VA_ARGS__ }; \
        u32 sum, i; \
        for (i = 0, sum = 0; i < ARRAY_COUNT(weights); i++) \
            sum += weights[i]; \
        RandomWeightedArray(tag, sum, ARRAY_COUNT(weights), weights); \
    })

#define RandomChance(tag, successes, total) (RandomWeighted(tag, total - successes, successes))

#define RandomPercentage(tag, t) \
    ({ \
        u32 r; \
        if_comptime (t == 50) \
        { \
            r = RandomUniform(tag, FALSE, TRUE); \
        } \
        else if (t <= 0) \
        { \
            r = FALSE; \
        } \
        else if (t >= 100) \
        { \
            r = TRUE; \
        } \
        else \
        { \
          const u16 weights[] = { 100 - t, t }; \
          r = RandomWeightedArray(tag, 100, ARRAY_COUNT(weights), weights); \
        } \
        r; \
    })

#define RandomElement(tag, array) \
    ({ \
        *(typeof((array)[0]) *)RandomElementArray(tag, array, sizeof((array)[0]), ARRAY_COUNT(array)); \
    })

u32 RandomUniform(enum RandomTag, u32 lo, u32 hi);
u32 RandomUniformExcept(enum RandomTag, u32 lo, u32 hi, bool32 (*reject)(u32));
u32 RandomWeightedArray(enum RandomTag, u32 sum, u32 n, const u16 *weights);
const void *RandomElementArray(enum RandomTag, const void *array, size_t size, size_t count);

u32 RandomUniformDefault(enum RandomTag, u32 lo, u32 hi);
u32 RandomUniformExceptDefault(enum RandomTag, u32 lo, u32 hi, bool32 (*reject)(u32));
u32 RandomWeightedArrayDefault(enum RandomTag, u32 sum, u32 n, const u16 *weights);
const void *RandomElementArrayDefault(enum RandomTag, const void *array, size_t size, size_t count);

u8 RandomWeightedIndex(u8 *weights, u8 length);

u32 RandomBitIndex(enum RandomTag tag, u32 bits);

#if TESTING
u32 RandomUniformTrials(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller);
u32 RandomUniformDefaultValue(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller);
u32 RandomWeightedArrayTrials(enum RandomTag tag, u32 sum, u32 n, const u16 *weights, void *caller);
u32 RandomWeightedArrayDefaultValue(enum RandomTag tag, u32 n, const u16 *weights, void *caller);
const void *RandomElementArrayTrials(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller);
const void *RandomElementArrayDefaultValue(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller);
#endif

u32 Crc32B (const u8 *data, u32 size);

#endif // GUARD_RANDOM_H

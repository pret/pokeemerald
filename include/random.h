#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE1(val) (1103515245 * (val) + 24691)
#define ISO_RANDOMIZE2(val) (1103515245 * (val) + 12345)

/* Some functions have been added to support HQ_RANDOM.
*
* If using HQ_RANDOM, you cannot call Random() in interrupt handlers safely.
* AdvanceRandom() is provided to handle burning numbers in the VBlank handler
* if you choose to do that, and can be used regardless of HQ_RANDOM setting.
* If you need to use random numbers in the VBlank handler, a local state
* should be used instead.
*
* LocalRandom(*val) allows you to have local random states that are the same
* type as the global states regardless of HQ_RANDOM setting, which is useful
* if you want to be able to set them from or assign them to gRngValue.
* LocalRandomSeed(u32) returns a properly seeded rng_value_t.
*
* Random2_32() was added to HQ_RANDOM because the output of the generator is
* always 32 bits and Random()/Random2() are just wrappers in that mode. It is
* also available in non-HQ mode for consistency.
*/

#if HQ_RANDOM == TRUE
struct Sfc32State {
    u32 a;
    u32 b;
    u32 c;
    u32 ctr;
};

typedef struct Sfc32State rng_value_t;

#define RNG_VALUE_EMPTY {}

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

static inline u16 LocalRandom(rng_value_t *val)
{
    return _SFC32_Next(val) >> 16;
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
#else
typedef u32 rng_value_t;

#define RNG_VALUE_EMPTY 0

//Returns a 16-bit pseudorandom number
u16 Random(void);
u16 Random2(void);

//Sets the initial seed value of the pseudorandom number generator
void SeedRng(u16 seed);
void SeedRng2(u16 seed);

//Returns a 32-bit pseudorandom number
#define Random32() (Random() | (Random() << 16))
#define Random2_32() (Random2() | (Random2() << 16))

static inline u16 LocalRandom(rng_value_t *val)
{
    *val = ISO_RANDOMIZE1(*val);
    return *val >> 16;
}

static inline void AdvanceRandom(void)
{
    Random();
}

static inline rng_value_t LocalRandomSeed(u32 seed)
{
    return seed;
}

#endif

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
    RNG_CRITICAL_HIT,
    RNG_CURSED_BODY,
    RNG_CUTE_CHARM,
    RNG_DAMAGE_MODIFIER,
    RNG_DIRE_CLAW,
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
    RNG_PARALYSIS,
    RNG_PICKUP,
    RNG_POISON_POINT,
    RNG_POISON_TOUCH,
    RNG_RAMPAGE_TURNS,
    RNG_SECONDARY_EFFECT,
    RNG_SECONDARY_EFFECT_2,
    RNG_SECONDARY_EFFECT_3,
    RNG_SHED_SKIN,
    RNG_SLEEP_TURNS,
    RNG_SPEED_TIE,
    RNG_STATIC,
    RNG_STENCH,
    RNG_TOXIC_CHAIN,
    RNG_TRI_ATTACK,
    RNG_QUICK_DRAW,
    RNG_QUICK_CLAW,
    RNG_TRACE,
    RNG_FICKLE_BEAM,
    RNG_AI_ABILITY,
    RNG_AI_SWITCH_HASBADODDS,
    RNG_AI_SWITCH_WONDER_GUARD,
    RNG_SHELL_SIDE_ARM,
};

#define RandomWeighted(tag, ...) \
    ({ \
        const u8 weights[] = { __VA_ARGS__ }; \
        u32 sum, i; \
        for (i = 0, sum = 0; i < ARRAY_COUNT(weights); i++) \
            sum += weights[i]; \
        RandomWeightedArray(tag, sum, ARRAY_COUNT(weights), weights); \
    })

#define RandomChance(tag, successes, total) (RandomWeighted(tag, total - successes, successes))

#define RandomPercentage(tag, t) \
    ({ \
        u32 r; \
        if (t <= 0) \
        { \
            r = FALSE; \
        } \
        else if (t >= 100) \
        { \
            r = TRUE; \
        } \
        else \
        { \
          const u8 weights[] = { 100 - t, t }; \
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
u32 RandomWeightedArray(enum RandomTag, u32 sum, u32 n, const u8 *weights);
const void *RandomElementArray(enum RandomTag, const void *array, size_t size, size_t count);

u32 RandomUniformDefault(enum RandomTag, u32 lo, u32 hi);
u32 RandomUniformExceptDefault(enum RandomTag, u32 lo, u32 hi, bool32 (*reject)(u32));
u32 RandomWeightedArrayDefault(enum RandomTag, u32 sum, u32 n, const u8 *weights);
const void *RandomElementArrayDefault(enum RandomTag, const void *array, size_t size, size_t count);

u8 RandomWeightedIndex(u8 *weights, u8 length);

#endif // GUARD_RANDOM_H

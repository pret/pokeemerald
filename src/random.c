#include "global.h"
#include "random.h"
#if MODERN
#include <alloca.h>
#endif

// IWRAM common
rng_value_t gRngValue;
rng_value_t gRng2Value;

#if HQ_RANDOM == TRUE

EWRAM_DATA static volatile bool8 sRngLoopUnlocked;

// Streams allow generators seeded the same to have separate outputs.
#define STREAM1 1
#define STREAM2 29

// A variant of SFC32 that lets you change the stream.
// stream can be any odd number.
static inline u32 _SFC32_Next_Stream(struct Sfc32State *state, const u8 stream)
{
    const u32 result = state->a + state->b + state->ctr;
    state->ctr += stream;
    state->a = state->b ^ (state->b >> 9);
    state->b = state->c * 9;
    state->c = result + ((state->c << 21) | (state->c >> 11));
    return result;
}

static void SFC32_Seed(struct Sfc32State *state, u32 seed, u8 stream)
{
    u32 i;
    state->a = state->b = 0;
    state->c = seed;
    state->ctr = stream;
    for(i = 0; i < 16; i++)
    {
        _SFC32_Next_Stream(state, stream);
    }
}

/*This ASM implementation uses some shortcuts and is generally faster on the GBA.
* It's not necessarily faster if inlined, or on other platforms.
* In addition, it's extremely non-portable. */
u32 NAKED Random32(void)
{
    asm(".thumb\n\
    push {r4, r5, r6}\n\
    mov r6, #11\n\
    ldr r5, =gRngValue\n\
    ldmia r5!, {r1, r2, r3, r4}\n\
    @ result = a + b + (d+=STREAM1)\n\
    add r1, r1, r2\n\
    add r0, r1, r4\n\
    add r4, r4, #" STR(STREAM1) "\n\
    @ a = b ^ (b >> 9)\n\
    lsr r1, r2, #9\n\
    eor r1, r1, r2\n\
    @ b = c + (c << 3) [c * 9]\n\
    lsl r2, r3, #3\n\
    add r2, r2, r3\n\
    @ c = rol(c, 21) + result\n\
    ror r3, r3, r6\n\
    add r3, r3, r0\n\
    sub r5, r5, #16\n\
    stmia r5!, {r1, r2, r3, r4}\n\
    pop {r4, r5, r6}\n\
    bx lr\n\
    .ltorg"
    );
}

u32 Random2_32(void)
{
    return _SFC32_Next_Stream(&gRng2Value, STREAM2);
}

void SeedRng(u32 seed)
{
    struct Sfc32State state;
    SFC32_Seed(&state, seed, STREAM1);

    sRngLoopUnlocked = FALSE;
    gRngValue = state;
    sRngLoopUnlocked = TRUE;
}

void SeedRng2(u32 seed)
{
    SFC32_Seed(&gRng2Value, seed, STREAM2);
}

rng_value_t LocalRandomSeed(u32 seed)
{
    rng_value_t result;
    SFC32_Seed(&result, seed, STREAM1);
    return result;
}

void AdvanceRandom(void)
{
    if (sRngLoopUnlocked == TRUE)
        Random32();
}

#define LOOP_RANDOM_START \
    struct Sfc32State *const state = &gRngValue; \
    sRngLoopUnlocked = FALSE;

#define LOOP_RANDOM_END sRngLoopUnlocked = TRUE;

#define LOOP_RANDOM ((u16)(_SFC32_Next(state) >> 16))

#else
EWRAM_DATA static u32 sRandCount = 0;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}

#define LOOP_RANDOM_START
#define LOOP_RANDOM_END

#define LOOP_RANDOM (Random())

#endif

#define SHUFFLE_IMPL \
    u32 tmp; \
    LOOP_RANDOM_START; \
    --n; \
    while (n > 1) \
    { \
        int j = (LOOP_RANDOM * (n+1)) >> 16; \
        SWAP(data[n], data[j], tmp); \
        --n; \
    } \
    LOOP_RANDOM_END

void Shuffle8(void *data_, size_t n)
{
    u8 *data = data_;
    SHUFFLE_IMPL;
}

void Shuffle16(void *data_, size_t n)
{
    u16 *data = data_;
    SHUFFLE_IMPL;
}

void Shuffle32(void *data_, size_t n)
{
    u32 *data = data_;
    SHUFFLE_IMPL;
}

void ShuffleN(void *data, size_t n, size_t size)
{
    void *tmp = alloca(size);
    LOOP_RANDOM_START;
    --n;

    while (n > 1)
    {
        int j = (LOOP_RANDOM * (n+1)) >> 16;
        memcpy(tmp, (u8 *)data + n*size, size); // tmp = data[n];
        memcpy((u8 *)data + n*size, (u8 *)data + j*size, size); // data[n] = data[j];
        memcpy((u8 *)data + j*size, tmp, size); // data[j] = tmp;
        --n;
    }

    LOOP_RANDOM_END;
}

__attribute__((weak, alias("RandomUniformDefault")))
u32 RandomUniform(enum RandomTag tag, u32 lo, u32 hi);

__attribute__((weak, alias("RandomUniformExceptDefault")))
u32 RandomUniformExcept(enum RandomTag, u32 lo, u32 hi, bool32 (*reject)(u32));

__attribute__((weak, alias("RandomWeightedArrayDefault")))
u32 RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u8 *weights);

__attribute__((weak, alias("RandomElementArrayDefault")))
const void *RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count);

u32 RandomUniformDefault(enum RandomTag tag, u32 lo, u32 hi)
{
    return lo + (((hi - lo + 1) * Random()) >> 16);
}

u32 RandomUniformExceptDefault(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32))
{
    LOOP_RANDOM_START;
    while (TRUE)
    {
        u32 n = lo + (((hi - lo + 1) * LOOP_RANDOM) >> 16);
        if (!reject(n))
            return n;
    }
    LOOP_RANDOM_END;
}

u32 RandomWeightedArrayDefault(enum RandomTag tag, u32 sum, u32 n, const u8 *weights)
{
    s32 i, targetSum;
    targetSum = (sum * Random()) >> 16;
    for (i = 0; i < n - 1; i++)
    {
        targetSum -= weights[i];
        if (targetSum < 0)
            return i;
    }
    return n - 1;
}

const void *RandomElementArrayDefault(enum RandomTag tag, const void *array, size_t size, size_t count)
{
    return (const u8 *)array + size * RandomUniformDefault(tag, 0, count - 1);
}

// Returns a random index according to a list of weights
u8 RandomWeightedIndex(u8 *weights, u8 length)
{
    u32 i;
    u16 randomValue;
    u16 weightSum = 0;
    for (i = 0; i < length; i++)
        weightSum += weights[i];
    randomValue = weightSum > 0 ? Random() % weightSum : 0;
    weightSum = 0;
    for (i = 0; i < length; i++)
    {
        weightSum += weights[i];
        if (randomValue <= weightSum)
            return i;
    }
    return 0;
}

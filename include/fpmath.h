#ifndef FPMATH_H_
#define FPMATH_H_

typedef s16 q4_12_t;
typedef u32 uq4_12_t;

#define Q_4_12_SHIFT (12)
#define UQ_4_12_SHIFT (12)

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((q4_12_t)((n) * 4096))
#define UQ_4_12(n)  ((uq4_12_t)((n) * 4096 + 0.5))
#define UQ_4_12_FLOORED(n)  ((uq4_12_t)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) << 8))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((s32)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((s32)((n) / 4096))
#define UQ_4_12_TO_INT(n)  ((u32)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((s32)((n) >> 8))

// Rounding value for Q4.12 fixed-point format
#define Q_4_12_ROUND ((1) << (Q_4_12_SHIFT - 1))
#define UQ_4_12_ROUND ((1) << (UQ_4_12_SHIFT - 1))

// Basic arithmetic for fixed point number formats
// Consumers should use encapsulated functions where possible

// FP API does not provide sanity checks against overflows

static inline uq4_12_t uq4_12_add(uq4_12_t a, uq4_12_t b)
{
    return a + b;
}

static inline uq4_12_t uq4_12_subtract(uq4_12_t a, uq4_12_t b)
{
    return a - b;
}

static inline uq4_12_t uq4_12_multiply(uq4_12_t a, uq4_12_t b)
{
    u32 product = (u32) a * b;
    return (product + UQ_4_12_ROUND) >> UQ_4_12_SHIFT;
}

static inline uq4_12_t uq4_12_multiply_half_down(uq4_12_t a, uq4_12_t b)
{
    u32 product = (u32) a * b;
    return (product + UQ_4_12_ROUND - 1) >> UQ_4_12_SHIFT;
}

static inline uq4_12_t uq4_12_divide(uq4_12_t dividend, uq4_12_t divisor)
{
    if (divisor == UQ_4_12(0.0)) return UQ_4_12(0);
    return (dividend << UQ_4_12_SHIFT) / divisor;
}

// Multiplies value by the UQ_4_12 number modifier.
// Returns an integer, rounded to nearest (rounding down on n.5)
static inline u32 uq4_12_multiply_by_int_half_down(uq4_12_t modifier, u32 value)
{
    return UQ_4_12_TO_INT((modifier * value) + UQ_4_12_ROUND - 1);
}

// Multiplies value by the UQ_4_12 number modifier.
// Returns an integer, rounded to nearest (rounding up on n.5)
static inline u32 uq4_12_multiply_by_int_half_up(uq4_12_t modifier, u32 value)
{
    return UQ_4_12_TO_INT((modifier * value) + UQ_4_12_ROUND);
}

#endif // FPMATH_H_

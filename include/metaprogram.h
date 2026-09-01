/* Macros to aid with metaprogramming. */
#ifndef METAPROGRAM_H
#define METAPROGRAM_H

/* Check if VA_OPT_ is supported by the compiler. GCC's version should be at least 9.5*/
#define PP_THIRD_ARG(a,b,c,...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(,),1,0,)
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)

#if !VA_OPT_SUPPORTED
#error ERROR: __VA_OPT__ is not supported. Please update your arm-none-eabi-gcc compiler to version 10 or higher
#endif // VA_OPT_SUPPORTED

/* Calls m0/m1/.../m8 depending on how many arguments are passed. */
#define VARARG_8(m, ...) CAT(m, NARG_8(__VA_ARGS__))(__VA_ARGS__)

/* Returns the number of arguments passed to it (up to 8). */
#define NARG_8(...) NARG_8_(_, ##__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define NARG_8_(_, a, b, c, d, e, f, g, h, N, ...) N

/* Expands 'a' and 'b' and then concatenates them. */
#define CAT(a, b) CAT_(a, b)
#define CAT_(a, b) a ## b

/* Expands '__VA_ARGS__' and then stringizes them. */
#define STR(...) STR_(__VA_ARGS__)
#define STR_(...) #__VA_ARGS__

/* You'll never guess what these do */
#define APPEND_SEMICOLON(a) a;
#define APPEND_COMMA(a) a,

/* Converts a string to a compound literal, essentially making it a pointer to const u8 */
#define COMPOUND_STRING_SIZE_LIMIT(str, limit) ((sizeof(COMPOUND_STRING(str)) <= (limit)) ? COMPOUND_STRING(str) : (const u8 [COMPOUND_STRING_CHECK_SIZE(str, limit)]) _(str))

/* Used for COMPOUND_STRING_SIZE_LIMIT. Stupid, but makes sure we only get
 * one error message regardless of how many characters over the limit we are.
 * Otherwise, GCC gives an error for each and every character (which is annoying). */
#define COMPOUND_STRING_CHECK_SIZE(str, limit) (sizeof(COMPOUND_STRING(str)) > limit ? sizeof(COMPOUND_STRING(str)) - 1 : sizeof(COMPOUND_STRING(str)))

/* Expands to the first/second/third/fourth argument. */
#define FIRST(a, ...) a
#define SECOND(a, ...) __VA_OPT__(FIRST(__VA_ARGS__))
#define THIRD(a, ...) __VA_OPT__(SECOND(__VA_ARGS__))
#define FOURTH(a, ...) __VA_OPT__(THIRD(__VA_ARGS__))

/* Expands to everything but the first x arguments */
#define EXCEPT_1(a, ...) __VA_OPT__(__VA_ARGS__)
#define EXCEPT_2(a, ...) __VA_OPT__(EXCEPT_1(__VA_ARGS__))
#define EXCEPT_3(a, ...) __VA_OPT__(EXCEPT_2(__VA_ARGS__))
#define EXCEPT_4(a, ...) __VA_OPT__(EXCEPT_3(__VA_ARGS__))

/* 'UNPACK_META (x, y, z)' expands to 'x, y, z'.
 * Useful for passing arguments which may contain commas into a macro. */
#define UNPACK_META(...) __VA_ARGS__

/* Updated version that can extract arguments from brackets as well.
 * Examples:
 *
 * UNPACK_B(a, b) => a, b
 * UNPACK_B((a, b)) => a, b
 * UNPACK_B((a)) => a
 *
 * The simple UNPACK is used for extracting non-bracketed arguments.
 * */
#define UNPACK_EXTRA(...) IF_YOU_SEE_ME_SOMETHING_IS_WRONG, __VA_ARGS__
#define UNPACK_B(a) INVOKE_WITH_(UNPACK_B_, a, UNPACK_EXTRA a)
#define UNPACK_B_(a, b, ...) __VA_OPT__(UNPACK_META)a

/* Expands to 'macro(...args, ...)'. */
#define INVOKE_WITH(macro, args, ...) INVOKE_WITH_(macro, UNPACK_META args __VA_OPT__(, __VA_ARGS__))
#define INVOKE_WITH_(macro, ...) macro(__VA_ARGS__)

/* Same as INVOKE_WITH but uses UNPACK_B to unpack arguments and only applies macro to args if there are any. */
#define INVOKE_WITH_B(macro, args, ...) INVOKE_B(macro, UNPACK_B(args) __VA_OPT__(, __VA_ARGS__))
#define INVOKE_B(macro, ...) INVOKE_B_(macro, __VA_ARGS__)
#define INVOKE_B_(macro, ...) __VA_OPT__(macro(__VA_ARGS__))

/* Recursive macros.
 * Based on https://www.scs.stanford.edu/~dm/blog/va-opt.html
 *
 * Macros prefixed with R_ are recursive, to correctly expand them the
 * top-level macro which references them should use 'RECURSIVELY' around
 * them. 'RECURSIVELY' cannot be nested, hence the top-level macro must
 * use it so that a recursive macro is able to reference another
 * recursive macro. */

#define RECURSIVELY(...) RECURSIVELY_4(RECURSIVELY_4(RECURSIVELY_4(RECURSIVELY_4(__VA_ARGS__))))
#define RECURSIVELY_4(...) RECURSIVELY_3(RECURSIVELY_3(RECURSIVELY_3(RECURSIVELY_3(__VA_ARGS__))))
#define RECURSIVELY_3(...) RECURSIVELY_2(RECURSIVELY_2(RECURSIVELY_2(RECURSIVELY_2(__VA_ARGS__))))
#define RECURSIVELY_2(...) RECURSIVELY_1(RECURSIVELY_1(RECURSIVELY_1(RECURSIVELY_1(__VA_ARGS__))))
#define RECURSIVELY_1(...) __VA_ARGS__

/* Useful for deferring expansion until the second scan. See
 * https://www.scs.stanford.edu/~dm/blog/va-opt.html for more info. */
#define PARENS ()

/* Expands to 'macro(a)' for each 'a' in '...' */
#define R_FOR_EACH(macro, ...) __VA_OPT__(R_FOR_EACH_(macro, __VA_ARGS__))
#define R_FOR_EACH_(macro, a, ...) macro(a) __VA_OPT__(R_FOR_EACH_P PARENS (macro, __VA_ARGS__))
#define R_FOR_EACH_P() R_FOR_EACH_

/* Expands to 'macro(...args, a)' for each 'a' in '...'. */
#define R_FOR_EACH_WITH(macro, args, ...) __VA_OPT__(R_FOR_EACH_WITH_(macro, args, __VA_ARGS__))
#define R_FOR_EACH_WITH_(macro, args, a, ...) INVOKE_WITH(macro, args, a) __VA_OPT__(R_FOR_EACH_WITH_P PARENS (macro, args, __VA_ARGS__))
#define R_FOR_EACH_WITH_P() R_FOR_EACH_WITH_

/* Expands to 'macro(a, b)' for each 'a' in 'as' and 'b' in 'bs'.
 * Uses the shorter of 'as' and 'bs'. (Credit to MGriffin) */
#define R_ZIP(macro, as, bs) CAT(R_ZIP_, CAT(R_ZIP_NONEMPTY(as), R_ZIP_NONEMPTY(bs)))(macro, FIRST as, FIRST bs, (EXCEPT_1 as), (EXCEPT_1 bs))
#define R_ZIP_00(macro, a, b, as, bs)
#define R_ZIP_01(macro, a, b, as, bs)
#define R_ZIP_10(macro, a, b, as, bs)
#define R_ZIP_11(macro, a, b, as, bs) macro(a, b) R_ZIP_P PARENS (macro, as, bs)
#define R_ZIP_P() R_ZIP

#define R_ZIP_NONEMPTY(as) R_ZIP_NONEMPTY_ as
#define R_ZIP_NONEMPTY_(...) FIRST(__VA_OPT__(1,) 0)

/* Just a lot of numbers (with leading zeroes - remove with REMOVE_LEADING_ZEROES) */
#define NUMBERS_256 (00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255)

/* Picks the xth VA_ARG if it exists, otherwise returns a default value */
#define DEFAULT(_default, ...) FIRST(__VA_OPT__(__VA_ARGS__, ) _default)
#define DEFAULT_2(_default, ...) DEFAULT(_default __VA_OPT__(, SECOND(__VA_ARGS__)))
#define DEFAULT_3(_default, ...) DEFAULT(_default __VA_OPT__(, THIRD(__VA_ARGS__)))
#define DEFAULT_4(_default, ...) DEFAULT(_default __VA_OPT__(, FOURTH(__VA_ARGS__)))

/* Simply a lists numbers 0-31, allows for word-spanning macros */
#define BITS_32(F, ...) \
    F(0, __VA_ARGS__) \
    F(1, __VA_ARGS__) \
    F(2, __VA_ARGS__) \
    F(3, __VA_ARGS__) \
    F(4, __VA_ARGS__) \
    F(5, __VA_ARGS__) \
    F(6, __VA_ARGS__) \
    F(7, __VA_ARGS__) \
    F(8, __VA_ARGS__) \
    F(9, __VA_ARGS__) \
    F(10, __VA_ARGS__) \
    F(11, __VA_ARGS__) \
    F(12, __VA_ARGS__) \
    F(13, __VA_ARGS__) \
    F(14, __VA_ARGS__) \
    F(15, __VA_ARGS__) \
    F(16, __VA_ARGS__) \
    F(17, __VA_ARGS__) \
    F(18, __VA_ARGS__) \
    F(19, __VA_ARGS__) \
    F(20, __VA_ARGS__) \
    F(21, __VA_ARGS__) \
    F(22, __VA_ARGS__) \
    F(23, __VA_ARGS__) \
    F(24, __VA_ARGS__) \
    F(25, __VA_ARGS__) \
    F(26, __VA_ARGS__) \
    F(27, __VA_ARGS__) \
    F(28, __VA_ARGS__) \
    F(29, __VA_ARGS__) \
    F(30, __VA_ARGS__) \
    F(31, __VA_ARGS__)

/* Compares _n to 1 shifted by _b by _operation (==, <, > etc) */
#define OP_BIT_SHIFT(_b, _n, _operation) (_n) _operation (1 << _b) ? _b :

/* (Credit to MGriffin) A rather monstrous way of finding the set bit in a word.
Invalid input causes a compiler error. Sample: https://cexplore.karathan.at/z/x1hm7B */
#define BIT_INDEX(_n) BITS_32(OP_BIT_SHIFT, _n, ==) *(u32 *)NULL

/* (Credit to MGriffin) A way to find the minimum required number of bits to
store a number (max: 32). Sample: https://godbolt.org/z/xb4KdPMhT */
#define BIT_SIZE(_n) (BITS_32(OP_BIT_SHIFT, _n, <) 32)

#define COMPRESS_BITS_0 0, 1
#define COMPRESS_BITS_1 1, 1
#define COMPRESS_BITS_2 2, 1
#define COMPRESS_BITS_3 3, 1
#define COMPRESS_BITS_4 4, 1
#define COMPRESS_BITS_5 5, 1
#define COMPRESS_BITS_6 6, 1
#define COMPRESS_BITS_7 7, 1

/* Will try and compress a set bit (or up to three sequential bits) into a single byte
Input must be of the form (upper << lower) where upper can be up to 7, lower up to 31 */
#define COMPRESS_BITS(_val) COMPRESS_BITS_STEP_2 _val
#define COMPRESS_BITS_STEP_2(_unpacked) INVOKE_WITH_(COMPRESS_BITS_STEP_3, COMPRESS_BITS_## _unpacked)
#define COMPRESS_BITS_STEP_3(upper, lower) (((upper % 8) << 5) + (BIT_INDEX(lower)))

/* Will read a compressed bit stored by COMPRESS_BIT into a single byte */
#define UNCOMPRESS_BITS(compressed) ((compressed >> 5) << (compressed & 0x1F))

/* Bit maxima */
#define MAX_u8 0xFF
#define MAX_u16 0xFFFF
#define MAX_u32 0xFFFFFFFF

/* Finds the maximum value of the given number of bits (up to 32 - obviously)*/
#define MAX_BITS(_bit) (MAX_u32 >> (32 - _bit))

/* Finds the required digits to display the number (maximum 4) */
#define MAX_DIGITS(_num) 1 + !!(_num / 10) + !!(_num / 100) + !!(_num / 1000)

/* Converts a number with leading zeroes to a normal int (base 10 and up to three digits only!) */
#define REMOVE_LEADING_ZEROES(_num) (((0x##_num / 256) * 100) + ((0x##_num / 16) * 10) + (0x##_num % 16))

/* Useful for counting arguments */
#define PLUS_ONE(...) + 1

/* Expands to 'if (true)' if 'cond' can be evaluated at compile-time and
 * evaluates to non-zero; expands to 'if (false)' otherwise.
 *
 * GCC will not generate code for an 'if (false) { ... }', so this can
 * be used to write compile-time optimizations without a run-time cost.
 *
 * Because 'cond' must be known at compile-time, this is rarely useful
 * outside macros. */
#define if_comptime(cond) if (__builtin_constant_p((cond) ? 0 : *(int *)0))

#endif

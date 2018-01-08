#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
#define NDEBUG
// NOTE: Don't try to enable assert right now as many pointers
// still exist in defines and WILL likely result in a broken ROM.

#define ENGLISH

#ifdef ENGLISH
#define UNITS_IMPERIAL
#else
#define UNITS_METRIC
#endif

#endif // GUARD_CONFIG_H

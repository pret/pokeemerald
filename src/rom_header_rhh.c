#include "global.h"
#include "constants/expansion.h"

// Similar to the GF ROM header, this struct allows external programs to
// detect details about Expansion.
// For this structure to be useful we have to maintain backwards binary
// compatibility. This means that we should only ever append data to the
// end. If there are any structs as members then those structs should
// not be modified after being introduced.
struct RHHRomHeader
{
    /*0x00*/ char rhh_magic[6]; // 'RHHEXP'. Useful to locate the header if it shifts.
    /*0x06*/ u8 expansionVersionMajor;
    /*0x07*/ u8 expansionVersionMinor;
    /*0x08*/ u8 expansionVersionPatch;
    /*0x09*/ u8 expansionVersionFlags;
};

__attribute__((section(".text.consts")))
static const struct RHHRomHeader sRHHRomHeader =
{
    .rhh_magic = { 'R', 'H', 'H', 'E', 'X', 'P' },
    .expansionVersionMajor = EXPANSION_VERSION_MAJOR,
    .expansionVersionMinor = EXPANSION_VERSION_MINOR,
    .expansionVersionPatch = EXPANSION_VERSION_PATCH,
    .expansionVersionFlags = (EXPANSION_TAGGED_RELEASE << 0),
};

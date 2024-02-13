#include "global.h"
#include "constants/abilities.h"
#include "constants/expansion.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/items.h"

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
    /*0x0A*/ u16 movesCount;
    /*0x0C*/ u16 numSpecies;
    /*0x0E*/ u16 abilitiesCount;
    /*0x10*/ const struct Ability *abilities;
    /*0x14*/ u16 itemsCount;
    /*0x16*/ u8 itemNameLength;
    /*0x17*/ u8 padding;
};

__attribute__((section(".text.consts")))
static const struct RHHRomHeader sRHHRomHeader =
{
    .rhh_magic = { 'R', 'H', 'H', 'E', 'X', 'P' },
    .expansionVersionMajor = EXPANSION_VERSION_MAJOR,
    .expansionVersionMinor = EXPANSION_VERSION_MINOR,
    .expansionVersionPatch = EXPANSION_VERSION_PATCH,
    .expansionVersionFlags = (EXPANSION_TAGGED_RELEASE << 0),
    .movesCount = MOVES_COUNT,
    .numSpecies = NUM_SPECIES,
    .abilitiesCount = ABILITIES_COUNT,
    .abilities = gAbilitiesInfo,
    .itemsCount = ITEMS_COUNT,
    .itemNameLength = ITEM_NAME_LENGTH,
};

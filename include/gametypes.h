#ifndef GUARD_GAMETYPES_H
#define GUARD_GAMETYPES_H

#include "gba/types.h"

//
// This header includes typedefs for fields that commonly appear throughout 
// the codebase, and which ROM hacks might benefit from being able to widen.
//
// These typedefs include the underlying type in their name for two reasons:
//
//  - Game Freak wasn't fully consistent about field widths throughout 
//    their codebase. For example, when Region Map Sections are persistently 
//    stored in savedata, they're stored as 8-bit values; but much of the 
//    codebase handles them as 16-bit values.
//
//  - Although Pokemon Emerald doesn't come close to maxing out RAM, it *does* 
//    use nearly all of its EEPROM. That is: the vanilla game uses 96% of the 
//    flash memory available for storing players' save files, leaving 2172 
//    bytes to spare within each of the game's two save files (primary and 
//    backup). These spare bytes are not contiguous: SaveBlock1 can only grow 
//    by 84 bytes, and SaveBlock2 can only grow by 120 bytes, with the rest 
//    of the free space located after the player's PC-boxed Pokemon.
//
//    With so little flash memory to spare, keeping track of how much space 
//    you're using is vital -- and so is arranging struct members to minimize 
//    compiler-inserted padding. It's easier to deal with this when you can 
//    see these types' widths at a glance.
//
// Accordingly, this file generally doesn't contain just single types, but 
// rather families of types. For example, Region Map Sections are saved as 
// u8s within the player's save file, but are sometimes handled as u16s or 
// even s16s and ints; and so there are multiple typedefs for Map Sections 
// corresponding to each of these underlying types, and each typedef has a 
// name which indicates the underlying type.
//
// For a given family of typedefs, the smallest one should be considered 
// the "real" or "canonical" type. Continuing with Map Sections as our 
// example, the smallest type is an 8-bit integer, and so any values that 
// can't fit in an 8-bit integer will be truncated and lost at some point 
// within the codebase. Therefore mapsec_u8_t is the "canonical" type for 
// Map Sections, and the larger typedefs just exist to describe situations 
// where the game handles Map Sections inconsistently with that "canon."
//

// Map Sections are named areas that can appear in the region map. Each 
// individual map can be assigned to a Map Section as appropriate. The 
// possible values are in constants/region_map_sections.h.
//
// If you choose to widen Map Sections, be aware that Met Locations (below) 
// are based on Map Sections and will also be widened.
typedef u8  mapsec_u8_t;
typedef u16 mapsec_u16_t;
typedef s16 mapsec_s16_t;
typedef s32 mapsec_s32_t;

// Met Locations for caught Pokemon use the same values as Map Sections, 
// except that 0xFD, 0xFE, and 0xFF have special meanings.
//
// Because this value appears inside every Pokemon's data, widening it will 
// consume a lot more space within flash memory. The space usage will be 
// greater than you expect due to how Pokemon substructs are laid out; you 
// would have to rearrange the substructs' contents in order to minimize 
// how much more space a wider Met Location would consume.
typedef mapsec_u8_t metloc_u8_t;

#endif //GUARD_GAMETYPES_H

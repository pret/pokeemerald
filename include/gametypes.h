#ifndef GUARD_GAMETYPES_H
#define GUARD_GAMETYPES_H

#include "gba/types.h"

//
// This header includes typedefs for fields that commonly appear throughout 
// the codebase, and which ROM hacks might benefit from being able to widen.
//
// Game Freak wasn't consistent with field widths; for example, some fields 
// are stored as u8s, but some functions take those fields as u16s. We offer 
// typedefs for those cases as well; the general naming convention takes 
// inspiration from <inttypes.h> and is:
//
//  - foo_t             The type something is persistently stored as.
//
//  - foo_min#_t        foo_t with a minimum size of # bits. For example, 
//                      foo_min16_t would be a u16 or s16 depending on the 
//                      signedness of foo_t.
//
//  - foo_min#_s_t      foo_min#_t, but signed. Used when foo_t is usually 
//                      unsigned.
//
//  - foo_min#_u_t      foo_min#_t, but unsigned. Used when foo_t is usually 
//                      signed.
//
//  - foo_int_t         For cases where a variable is a bare int.
//
// If you need to widen a type, make sure that its variations are widened 
// as well. For example, if bar_t is a u8 and you want to widen it to u32, 
// you must change bar_min16_t to a u32 as well, and bar_min16_s_t to an 
// s32.
//

// Map Sections are named areas that can appear in the region map. Each 
// individual map can be assigned to a Map Section as appropriate. The 
// possible values are in constants/region_map_sections.h.
typedef u8  mapsec_t;
typedef u16 mapsec_min16_t;
typedef s16 mapsec_min16_s_t;
typedef int mapsec_int_t;

// Met Locations for caught Pokemon use the same values as Map Sections, 
// except that 0xFD, 0xFE, and 0xFF have special meanings.
//
// Note that SetBoxMonData and friends use the SET8 macro to write this 
// data, so widening mapsec_t or metloc_t will require updating that as 
// well.
typedef mapsec_t metloc_t;

#endif //GUARD_GAMETYPES_H

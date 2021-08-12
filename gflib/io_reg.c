#include "global.h"
#include "io_reg.h"
#include "gba/io_reg.h"

static const u32 sUnused[] = {
    0,
    0,
    (1 << 26) | (1 << 3),
    (1 << 26) | (1 << 3) | (1 << 1),
    (1 << 26) | (1 << 3) | (1 << 2),
    (1 << 26) | (1 << 3) | (1 << 2) | (1 << 1),
    (1 << 26) | (1 << 4),
    (1 << 26) | (1 << 4) | (1 << 2),
    (1 << 26) | (1 << 4) | (1 << 3),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 2),
    (1 << 26) | (1 << 4) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 2) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1),
    (1 << 25) | (1 << 8), 
    (1 << 27) | (1 << 10), 
};

const u16 gOverworldBackgroundLayerFlags[] = {
    BLDCNT_TGT2_BG0,
    BLDCNT_TGT2_BG1,
    BLDCNT_TGT2_BG2,
    BLDCNT_TGT2_BG3,
};

const u16 gOrbEffectBackgroundLayerFlags[] = {
    BLDCNT_TGT1_BG0,
    BLDCNT_TGT1_BG1,
    BLDCNT_TGT1_BG2,
    BLDCNT_TGT1_BG3,
};

#define SUBSPRITE_TABLE_ENTRY(x) {ARRAY_COUNT(x), x}
#define SUBSPRITE_SHAPE(w, h) .shape = SPRITE_SHAPE(w##x##h), .size = SPRITE_SIZE(w##x##h)

static const struct Subsprite sOamTable_16x16_0[] = {
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_16x16_1[] = {
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_16x16_2[] = {
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8,
        .y =  0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 2,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_16x16_3[] = {
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_16x16_4[] = {
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 3
    }
};

static const struct SubspriteTable sOamTables_16x16[] = {
    {},
    {ARRAY_COUNT(sOamTable_16x16_0), sOamTable_16x16_0},
    {ARRAY_COUNT(sOamTable_16x16_1), sOamTable_16x16_1},
    {ARRAY_COUNT(sOamTable_16x16_2), sOamTable_16x16_2},
    {ARRAY_COUNT(sOamTable_16x16_3), sOamTable_16x16_3},
    {ARRAY_COUNT(sOamTable_16x16_4), sOamTable_16x16_4}
};

static const struct Subsprite sOamTable_16x32_0[] = {
    {
        .x = -8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_16x32_1[] = {
    {
        .x = -8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_16x32_2[] = {
    {
        .x = -8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8,
        .y =   0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x = -8,
        .y =   8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 6,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_16x32_3[] = {
    {
        .x = -8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8,
        .y =   0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 4,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_16x32_4[] = {
    {
        .x = -8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -8,
        .y =   0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 4,
        .priority = 3
    }
};

static const struct SubspriteTable sOamTables_16x32[] = {
    {},
    {ARRAY_COUNT(sOamTable_16x32_0), sOamTable_16x32_0},
    {ARRAY_COUNT(sOamTable_16x32_1), sOamTable_16x32_1},
    {ARRAY_COUNT(sOamTable_16x32_2), sOamTable_16x32_2},
    {ARRAY_COUNT(sOamTable_16x32_3), sOamTable_16x32_3},
    {ARRAY_COUNT(sOamTable_16x32_4), sOamTable_16x32_4}
};

static const struct Subsprite sOamTable_32x32_0[] = {
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_32x32_1[] = {
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_32x32_2[] = {
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y =   0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x = -16,
        .y =   8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_32x32_3[] = {
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y =   0,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 8,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_32x32_4[] = {
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16,
        .y =   0,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 8,
        .priority = 3
    }
};

const struct SubspriteTable sOamTables_32x32[] = {
    {},
    {ARRAY_COUNT(sOamTable_32x32_0), sOamTable_32x32_0},
    {ARRAY_COUNT(sOamTable_32x32_1), sOamTable_32x32_1},
    {ARRAY_COUNT(sOamTable_32x32_2), sOamTable_32x32_2},
    {ARRAY_COUNT(sOamTable_32x32_3), sOamTable_32x32_3},
    {ARRAY_COUNT(sOamTable_32x32_4), sOamTable_32x32_4}
};

static const struct Subsprite sOamTable_64x32_0[] = {
    {
        .x = -32,
        .y = -16,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x32_1[] = {
    {
        .x = -32,
        .y = -16,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_64x32_2[] = {
    {
        .x = -32,
        .y = -16,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x32_3[] = {
    {
        .x = -32,
        .y = -16,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    }
};

// Unused
static const struct SubspriteTable sOamTables_64x32[] = {
    {},
    {ARRAY_COUNT(sOamTable_64x32_0), sOamTable_64x32_0},
    {ARRAY_COUNT(sOamTable_64x32_1), sOamTable_64x32_1},
    {ARRAY_COUNT(sOamTable_64x32_2), sOamTable_64x32_2},
    {ARRAY_COUNT(sOamTable_64x32_3), sOamTable_64x32_3},
    {ARRAY_COUNT(sOamTable_64x32_3), sOamTable_64x32_3}
};

static const struct Subsprite sOamTable_64x64_0[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 64),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x64_1[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 64),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_64x64_2[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 64),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x64_3[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 64),
        .tileOffset = 0,
        .priority = 2
    }
};

const struct SubspriteTable sOamTables_64x64[] = {
    {},
    {ARRAY_COUNT(sOamTable_64x64_0), sOamTable_64x64_0},
    {ARRAY_COUNT(sOamTable_64x64_1), sOamTable_64x64_1},
    {ARRAY_COUNT(sOamTable_64x64_2), sOamTable_64x64_2},
    {ARRAY_COUNT(sOamTable_64x64_3), sOamTable_64x64_3},
    {ARRAY_COUNT(sOamTable_64x64_3), sOamTable_64x64_3}
};

static const struct Subsprite sOamTable_96x40_0[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 2
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 2
    },
    {
        .x = -48,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 48,
        .priority = 2
    },
    {
        .x = -16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 52,
        .priority = 2
    },
    {
        .x =  16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 56,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_96x40_1[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 1
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 1
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 1
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 28,
        .priority = 1
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 1
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 1
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 1
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 1
    },
    {
        .x = -48,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 48,
        .priority = 1
    },
    {
        .x = -16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 52,
        .priority = 1
    },
    {
        .x =  16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 56,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_96x40_2[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 2
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 2
    },
    {
        .x = -48,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 48,
        .priority = 2
    },
    {
        .x = -16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 52,
        .priority = 2
    },
    {
        .x =  16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 56,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_96x40_3[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 1
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 1
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 2
    },
    {
        .x = -48,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 48,
        .priority = 2
    },
    {
        .x = -16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 52,
        .priority = 2
    },
    {
        .x =  16,
        .y =  12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 56,
        .priority = 2
    }
};

// Used by SS Tidal
static const struct SubspriteTable sOamTables_96x40[] = {
    {ARRAY_COUNT(sOamTable_96x40_0), sOamTable_96x40_0},
    {ARRAY_COUNT(sOamTable_96x40_0), sOamTable_96x40_0},
    {ARRAY_COUNT(sOamTable_96x40_1), sOamTable_96x40_1},
    {ARRAY_COUNT(sOamTable_96x40_2), sOamTable_96x40_2},
    {ARRAY_COUNT(sOamTable_96x40_3), sOamTable_96x40_3},
    {ARRAY_COUNT(sOamTable_96x40_3), sOamTable_96x40_3}
};

static const struct Subsprite sOamTable_88x32_0[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x =  32,
        .y = -20,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 2
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 11,
        .priority = 2
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 15,
        .priority = 2
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 2
    },
    {
        .x =  32,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 21,
        .priority = 2
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 26,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 30,
        .priority = 2
    },
    {
        .x =  32,
        .y =  -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 33,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 37,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 41,
        .priority = 2
    },
    {
        .x =  32,
        .y =   4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 43,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_88x32_1[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x =  32,
        .y = -20,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 1
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 11,
        .priority = 1
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 15,
        .priority = 1
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 1
    },
    {
        .x =  32,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 21,
        .priority = 1
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 22,
        .priority = 1
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 26,
        .priority = 1
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 30,
        .priority = 1
    },
    {
        .x =  32,
        .y =  -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 32,
        .priority = 1
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 33,
        .priority = 1
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 37,
        .priority = 1
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 41,
        .priority = 1
    },
    {
        .x =  32,
        .y =   4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 43,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_88x32_2[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x =  32,
        .y = -20,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 2
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 11,
        .priority = 2
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 15,
        .priority = 2
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 2
    },
    {
        .x =  32,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 21,
        .priority = 2
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 26,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 30,
        .priority = 2
    },
    {
        .x =  32,
        .y =  -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 33,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 37,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 41,
        .priority = 2
    },
    {
        .x =  32,
        .y =   4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 43,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_88x32_3[] = {
    {
        .x = -48,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16,
        .y = -20,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x =  16,
        .y = -20,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x =  32,
        .y = -20,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 1
    },
    {
        .x = -48,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 11,
        .priority = 1
    },
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 15,
        .priority = 1
    },
    {
        .x =  16,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 1
    },
    {
        .x =  32,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 21,
        .priority = 1
    },
    {
        .x = -48,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -16,
        .y =  -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 26,
        .priority = 2
    },
    {
        .x =  16,
        .y =  -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 30,
        .priority = 2
    },
    {
        .x =  32,
        .y =  -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = -48,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 33,
        .priority = 2
    },
    {
        .x = -16,
        .y =   4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 37,
        .priority = 2
    },
    {
        .x =  16,
        .y =   4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 41,
        .priority = 2
    },
    {
        .x =  32,
        .y =   4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 43,
        .priority = 2
    }
};

// Used by Submarine Shadow
static const struct SubspriteTable sOamTables_88x32[] = {
    {ARRAY_COUNT(sOamTable_88x32_0), sOamTable_88x32_0},
    {ARRAY_COUNT(sOamTable_88x32_0), sOamTable_88x32_0},
    {ARRAY_COUNT(sOamTable_88x32_1), sOamTable_88x32_1},
    {ARRAY_COUNT(sOamTable_88x32_2), sOamTable_88x32_2},
    {ARRAY_COUNT(sOamTable_88x32_3), sOamTable_88x32_3},
    {ARRAY_COUNT(sOamTable_88x32_3), sOamTable_88x32_3}
};

#if OW_LARGE_OW_SUPPORT
// These tables allow (virtual) sprite sizes so that
// some space can be saved by making graphics smaller.
// Note: When using these for followers, the minimum
// `size` you must set in GraphicsInfo is 512.

static const struct Subsprite sOamTable_16x24_0[] = {
    {
        .x = -8, .y = -12,
        SUBSPRITE_SHAPE(16, 16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 2
    },
};

static const struct Subsprite sOamTable_16x24_1[] = {
    {
        .x = -8, .y = -12,
        SUBSPRITE_SHAPE(16, 16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -8, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 1
    },
};

static const struct Subsprite sOamTable_16x24_2[] = {
    {
        .x = -8, .y = -12,
        SUBSPRITE_SHAPE(16, 16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_16x24_3[] = {
    {
        .x = -8, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -8, .y = -4,
        SUBSPRITE_SHAPE(16, 16),
        .tileOffset = 2,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_16x24_4[] = {
    {
        .x = -8, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -8, .y = -4,
        SUBSPRITE_SHAPE(16, 16),
        .tileOffset = 2,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_32x24_0[] = {
    {
        .x = -16, .y = -12,
        SUBSPRITE_SHAPE(32, 16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16, .y = 4,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 8,
        .priority = 2
    },
};

static const struct Subsprite sOamTable_32x24_1[] = {
    {
        .x = -16, .y = -12,
        SUBSPRITE_SHAPE(32, 16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16, .y = 4,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 8,
        .priority = 1
    },
};

static const struct Subsprite sOamTable_32x24_2[] = {
    {
        .x = -16, .y = -12,
        SUBSPRITE_SHAPE(32, 16),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16, .y = 4,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 8,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_32x24_3[] = {
    {
        .x = -16, .y = -12,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16, .y = -4,
        SUBSPRITE_SHAPE(32, 16),
        .tileOffset = 4,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_32x24_4[] = {
    {
        .x = -16, .y = -12,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -16, .y = -4,
        SUBSPRITE_SHAPE(32, 16),
        .tileOffset = 4,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x16_0[] = {
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
};

static const struct Subsprite sOamTable_24x16_1[] = {
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 1
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 1
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 1
    },
};

static const struct Subsprite sOamTable_24x16_2[] = {
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 3
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x16_3[] = {
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 3
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 3
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 3
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x24_0[] = {
    {
        .x = -12, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -12,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = -4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
    {
        .x = -12, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x = 4, .y = 4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 2
    },
};

static const struct Subsprite sOamTable_24x24_1[] = {
    {
        .x = -12, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 4, .y = -12,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 1
    },
    {
        .x = -12, .y = -4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 1
    },
    {
        .x = 4, .y = -4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 1
    },
    {
        .x = -12, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 1
    },
    {
        .x = 4, .y = 4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 1
    },
};

static const struct Subsprite sOamTable_24x24_2[] = {
    {
        .x = -12, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -12,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = -4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
    {
        .x = -12, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 3
    },
    {
        .x = 4, .y = 4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x24_3[] = {
    {
        .x = -12, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -12,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 3
    },
    {
        .x = 4, .y = -4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 3
    },
    {
        .x = -12, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 3
    },
    {
        .x = 4, .y = 4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x24_4[] = {
    {
        .x = -12, .y = -12,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 4, .y = -12,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 1
    },
    {
        .x = -12, .y = -4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 3
    },
    {
        .x = 4, .y = -4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 3
    },
    {
        .x = -12, .y = 4,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 3
    },
    {
        .x = 4, .y = 4,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x32_0[] = {
    {
        .x = -12, .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -16,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x = -12, .y = 8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 9,
        .priority = 2
    },
    {
        .x = 4, .y = 8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 11,
        .priority = 2
    },
};

static const struct Subsprite sOamTable_24x32_1[] = {
    {
        .x = -12, .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 4, .y = -16,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 1
    },
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 1
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 1
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 1
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = -12, .y = 8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 9,
        .priority = 1
    },
    {
        .x = 4, .y = 8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 11,
        .priority = 1
    },
};

static const struct Subsprite sOamTable_24x32_2[] = {
    {
        .x = -12, .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -16,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 2
    },
    {
        .x = -12, .y = 8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 9,
        .priority = 3
    },
    {
        .x = 4, .y = 8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 11,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x32_3[] = {
    {
        .x = -12, .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = 4, .y = -16,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 2
    },
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 2
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 2
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 3
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 3
    },
    {
        .x = -12, .y = 8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 9,
        .priority = 3
    },
    {
        .x = 4, .y = 8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 11,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_24x32_4[] = {
    {
        .x = -12, .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 4, .y = -16,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 2,
        .priority = 1
    },
    {
        .x = -12, .y = -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 3,
        .priority = 1
    },
    {
        .x = 4, .y = -8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 5,
        .priority = 1
    },
    {
        .x = -12, .y = 0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 6,
        .priority = 3
    },
    {
        .x = 4, .y = 0,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 8,
        .priority = 3
    },
    {
        .x = -12, .y = 8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 9,
        .priority = 3
    },
    {
        .x = 4, .y = 8,
        SUBSPRITE_SHAPE(8, 8),
        .tileOffset = 11,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_64x64_Follower[] = {
    {
        .x = -32, .y = -32,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -32, .y = 0,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 32,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x64_HotSprings[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -32,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = 0,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 36,
        .priority = 2
    },
    {
        .x = -32,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 40,
        .priority = 2
    },
    {
        .x = 0,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 44,
        .priority = 2
    },
    {
        .x = -32,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 48,
        .priority = 2
    },
    {
        .x = 0,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 52,
        .priority = 2
    },
    {
        .x = -32,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 56,
        .priority = 3
    },
    {
        .x = 0,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 60,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_64x64_Grass2[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -32,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 32,
        .priority = 2
    },
    {
        .x = 0,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 36,
        .priority = 2
    },
    {
        .x = -32,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 40,
        .priority = 2
    },
    {
        .x = 0,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 44,
        .priority = 2
    },
    {
        .x = -32,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 48,
        .priority = 3
    },
    {
        .x = 0,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 52,
        .priority = 3
    },
    {
        .x = -32,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 56,
        .priority = 3
    },
    {
        .x = 0,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 60,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_64x64_Grass1[] = {
    {
        .x = -32,
        .y = -32,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -32,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 32,
        .priority = 1
    },
    {
        .x = 0,
        .y = 0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 36,
        .priority = 1
    },
    {
        .x = -32,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 40,
        .priority = 1
    },
    {
        .x = 0,
        .y = 8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 44,
        .priority = 1
    },
    {
        .x = -32,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 48,
        .priority = 3
    },
    {
        .x = 0,
        .y = 16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 52,
        .priority = 3
    },
    {
        .x = -32,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 56,
        .priority = 3
    },
    {
        .x = 0,
        .y = 24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 60,
        .priority = 3
    },
};

static const struct Subsprite sOamTable_64x64_Grass3[] = {
    {
        .x = -32,
        .y = -24,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -32,
        .y = 8,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 32,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_64x64_Grass4[] = {
    {
        .x = -32,
        .y = -24,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = -32,
        .y = 8,
        SUBSPRITE_SHAPE(64, 32),
        .tileOffset = 32,
        .priority = 3
    }
};


static const struct SubspriteTable sOamTables_16x24[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_1),
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_2),
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_3),
    SUBSPRITE_TABLE_ENTRY(sOamTable_16x24_4),
};


static const struct SubspriteTable sOamTables_24x16[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_1),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_2),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_3),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x16_3),
};

static const struct SubspriteTable sOamTables_24x24[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_0), // reflections
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_0), // all 2
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_1), // all 1
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_2), // bottom 8 3
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_3), // bottom 16 3
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x24_4), // top 1, bottom 16 3
};

static const struct SubspriteTable sOamTables_24x32[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_1),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_2),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_3),
    SUBSPRITE_TABLE_ENTRY(sOamTable_24x32_4),
};


static const struct SubspriteTable sOamTables_32x24[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_0),
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_1),
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_2),
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_3),
    SUBSPRITE_TABLE_ENTRY(sOamTable_32x24_4),
};


// For following pokemon
// Makes the top 32 pixels priority 1,
// so that very tall pokemon's heads
// will appear on top of buildings, etc.
static const struct SubspriteTable sOamTables_64x64_Tall[] = {
    {}, // unused
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Follower), // elevation 3
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_1), // elevation 4
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_HotSprings), // hot springs
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Grass2), // long grass
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Grass1) // long grass priority 1
};

// Like sOamTables_64x64_Tall, but fewer pixels visible in long grass
// Meant for pokemon that are more long than tall like Wailord
static const struct SubspriteTable sOamTables_64x64_Long[] = {
    {}, // unused
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Follower), // elevation 3
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_1), // elevation 4
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_HotSprings), // hot springs
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Grass3), // long grass
    SUBSPRITE_TABLE_ENTRY(sOamTable_64x64_Grass4) // long grass priority 1
};
#endif

static const struct Subsprite sOamTable_48x48[] = {
    {
        .x = -24,
        .y = -24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x =   8,
        .y = -24,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = -24,
        .y = -16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 6,
        .priority = 1
    },
    {
        .x =   8,
        .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 10,
        .priority = 1
    },
    {
        .x = -24,
        .y =  -8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x =   8,
        .y =  -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x = -24,
        .y =   0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 18,
        .priority = 2
    },
    {
        .x =   8,
        .y =   0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -24,
        .y =   8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x =   8,
        .y =   8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x = -24,
        .y =  16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 30,
        .priority = 2
    },
    {
        .x =   8,
        .y =  16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 34,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_48x48_4[] = {
    {
        .x = -24,
        .y = -24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x =   8,
        .y = -24,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = -24,
        .y = -16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 6,
        .priority = 1
    },
    {
        .x =   8,
        .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 10,
        .priority = 1
    },
    {
        .x = -24,
        .y =  -8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 12,
        .priority = 1
    },
    {
        .x =   8,
        .y =  -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 16,
        .priority = 1
    },
    {
        .x = -24,
        .y =   0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 18,
        .priority = 1
    },
    {
        .x =   8,
        .y =   0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 22,
        .priority = 1
    },
    {
        .x = -24,
        .y =   8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 24,
        .priority = 1
    },
    {
        .x =   8,
        .y =   8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 28,
        .priority = 1
    },
    {
        .x = -24,
        .y =  16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 30,
        .priority = 1
    },
    {
        .x =   8,
        .y =  16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 34,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_48x48_HotSprings[] = {
    {
        .x = -24,
        .y = -24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x =   8,
        .y = -24,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x = -24,
        .y = -16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x =   8,
        .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 10,
        .priority = 2
    },
    {
        .x = -24,
        .y =  -8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x =   8,
        .y =  -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x = -24,
        .y =   0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 18,
        .priority = 2
    },
    {
        .x =   8,
        .y =   0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -24,
        .y =   8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x =   8,
        .y =   8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x = -24,
        .y =  16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 30,
        .priority = 3
    },
    {
        .x =   8,
        .y =  16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 34,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_48x48_Grass2[] = {
    {
        .x = -24,
        .y = -24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x =   8,
        .y = -24,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x = -24,
        .y = -16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x =   8,
        .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 10,
        .priority = 2
    },
    {
        .x = -24,
        .y =  -8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x =   8,
        .y =  -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x = -24,
        .y =   0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 18,
        .priority = 2
    },
    {
        .x =   8,
        .y =   0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -24,
        .y =   8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 24,
        .priority = 3
    },
    {
        .x =   8,
        .y =   8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 28,
        .priority = 3
    },
    {
        .x = -24,
        .y =  16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 30,
        .priority = 3
    },
    {
        .x =   8,
        .y =  16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 34,
        .priority = 3
    }
};

static const struct Subsprite sOamTable_48x48_Grass1[] = {
    {
        .x = -24,
        .y = -24,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x =   8,
        .y = -24,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = -24,
        .y = -16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 6,
        .priority = 1
    },
    {
        .x =   8,
        .y = -16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 10,
        .priority = 1
    },
    {
        .x = -24,
        .y =  -8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 12,
        .priority = 1
    },
    {
        .x =   8,
        .y =  -8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 16,
        .priority = 1
    },
    {
        .x = -24,
        .y =   0,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 18,
        .priority = 1
    },
    {
        .x =   8,
        .y =   0,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 22,
        .priority = 1
    },
    {
        .x = -24,
        .y =   8,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 24,
        .priority = 3
    },
    {
        .x =   8,
        .y =   8,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 28,
        .priority = 3
    },
    {
        .x = -24,
        .y =  16,
        SUBSPRITE_SHAPE(32, 8),
        .tileOffset = 30,
        .priority = 3
    },
    {
        .x =   8,
        .y =  16,
        SUBSPRITE_SHAPE(16, 8),
        .tileOffset = 34,
        .priority = 3
    }
};

// Also used for truck
static const struct SubspriteTable sOamTables_48x48[] = {
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48), // reflections
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48), // elevation 3
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48_4), // elevation 4
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48_HotSprings), // hot springs
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48_Grass2), // long grass
    SUBSPRITE_TABLE_ENTRY(sOamTable_48x48_Grass1) // long grass priority 1
};
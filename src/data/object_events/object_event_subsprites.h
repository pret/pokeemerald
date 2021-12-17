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
    {0, NULL},
    {1, sOamTable_16x16_0},
    {1, sOamTable_16x16_1},
    {2, sOamTable_16x16_2},
    {2, sOamTable_16x16_3},
    {2, sOamTable_16x16_4}
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
    {0, NULL},
    {1, sOamTable_16x32_0},
    {1, sOamTable_16x32_1},
    {3, sOamTable_16x32_2},
    {2, sOamTable_16x32_3},
    {2, sOamTable_16x32_4}
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

static const struct SubspriteTable sOamTables_32x32[] = {
    {0, NULL},
    {1, sOamTable_32x32_0},
    {1, sOamTable_32x32_1},
    {3, sOamTable_32x32_2},
    {2, sOamTable_32x32_3},
    {2, sOamTable_32x32_4}
};

static const struct Subsprite sOamTable_48x48[] = {
    {
        .x = -24,
        .y = -24,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x =   8,
        .y = -24,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 4,
        .priority = 2
    },
    {
        .x = -24,
        .y = -16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 6,
        .priority = 2
    },
    {
        .x =   8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 10,
        .priority = 2
    },
    {
        .x = -24,
        .y =  -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 2
    },
    {
        .x =   8,
        .y =  -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 16,
        .priority = 2
    },
    {
        .x = -24,
        .y =   0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 18,
        .priority = 2
    },
    {
        .x =   8,
        .y =   0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 22,
        .priority = 2
    },
    {
        .x = -24,
        .y =   8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 2
    },
    {
        .x =   8,
        .y =   8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 28,
        .priority = 2
    },
    {
        .x = -24,
        .y =  16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 30,
        .priority = 2
    },
    {
        .x =   8,
        .y =  16,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 34,
        .priority = 2
    }
};

static const struct SubspriteTable sOamTables_48x48[] = {
    {12, sOamTable_48x48},
    {12, sOamTable_48x48},
    {12, sOamTable_48x48},
    {12, sOamTable_48x48},
    {12, sOamTable_48x48},
    {12, sOamTable_48x48}
};

static const struct Subsprite sOamTable_64x32_0[] = {
    {
        .x = -32,
        .y = -16,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x32_1[] = {
    {
        .x = -32,
        .y = -16,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_64x32_2[] = {
    {
        .x = -32,
        .y = -16,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x32_3[] = {
    {
        .x = -32,
        .y = -16,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 2
    }
};

// Unused
static const struct SubspriteTable sOamTables_64x32[] = {
    {0, NULL},
    {1, sOamTable_64x32_0},
    {1, sOamTable_64x32_1},
    {1, sOamTable_64x32_2},
    {1, sOamTable_64x32_3},
    {1, sOamTable_64x32_3}
};

static const struct Subsprite sOamTable_64x64_0[] = {
    {
        .x = -32,
        .y = -32,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x64_1[] = {
    {
        .x = -32,
        .y = -32,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 1
    }
};

static const struct Subsprite sOamTable_64x64_2[] = {
    {
        .x = -32,
        .y = -32,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct Subsprite sOamTable_64x64_3[] = {
    {
        .x = -32,
        .y = -32,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 2
    }
};

static const struct SubspriteTable sOamTables_64x64[] = {
    {0, NULL},
    {1, sOamTable_64x64_0},
    {1, sOamTable_64x64_1},
    {1, sOamTable_64x64_2},
    {1, sOamTable_64x64_3},
    {1, sOamTable_64x64_3}
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
    {15, sOamTable_96x40_0},
    {15, sOamTable_96x40_0},
    {15, sOamTable_96x40_1},
    {15, sOamTable_96x40_2},
    {15, sOamTable_96x40_3},
    {15, sOamTable_96x40_3}
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
    {16, sOamTable_88x32_0},
    {16, sOamTable_88x32_0},
    {16, sOamTable_88x32_1},
    {16, sOamTable_88x32_2},
    {16, sOamTable_88x32_3},
    {16, sOamTable_88x32_3}
};

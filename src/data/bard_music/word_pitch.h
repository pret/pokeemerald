#ifndef GUARD_WORD_PITCH_H
#define GUARD_WORD_PITCH_H

#define PITCH_END 0x1800

static const s16 sPitch1_0[] = {
    -0x300, PITCH_END
};

static const s16 sPitch1_1[] = {
    0x0900, PITCH_END
};

static const s16 sPitch1_2[] = {
    0x0100, PITCH_END
};

static const s16 sPitch1_3[] = {
    0x0400, PITCH_END
};

static const s16 sPitch1_4[] = {
    0x0b00, PITCH_END
};

static const s16 sPitch2_0[] = {
    -0x300, -0x100, PITCH_END
};

static const s16 sPitch2_1[] = {
    -0x300, 0x0200, PITCH_END
};

static const s16 sPitch2_2[] = {
    0x0200, 0x0400, PITCH_END
};

static const s16 sPitch2_3[] = {
    0x0600, 0x0800, PITCH_END
};

static const s16 sPitch2_4[] = {
    0x0900, 0x0800, PITCH_END
};

static const s16 sPitch3_0[] = {
    -0x300, -0x100, -0x300, PITCH_END
};

static const s16 sPitch3_1[] = {
    0x0400, -0x300, 0x0400, PITCH_END
};

static const s16 sPitch3_2[] = {
    0x0900, 0x0800, 0x0600, PITCH_END
};

static const s16 sPitch3_3[] = {
    0x0100, 0x0200, 0x0400, PITCH_END
};

static const s16 sPitch3_4[] = {
    0x0600, 0x1000, 0x0d00, PITCH_END
};

static const s16 sPitch4_0[] = {
    0x0400, 0x0900, 0x0400, 0x0900, PITCH_END
};

static const s16 sPitch4_1[] = {
    0x0900, 0x0400, 0x0d00, 0x0400, PITCH_END
};

static const s16 sPitch4_2[] = {
    0x0100, 0x0200, 0x0400, 0x0600, PITCH_END
};

static const s16 sPitch4_3[] = {
    0x0800, 0x0600, 0x0400, 0x0200, PITCH_END
};

static const s16 sPitch4_4[] = {
    0x0f00, 0x0d00, 0x0b00, 0x0a00, PITCH_END
};

static const s16 sPitch5_0[] = {
    -0x300, -0x100, 0x0100, 0x0200, 0x0400, PITCH_END
};

static const s16 sPitch5_1[] = {
    0x0900, 0x0800, 0x0600, 0x0400, 0x0200, PITCH_END
};

static const s16 sPitch5_2[] = {
    0x0100, 0x0400, 0x0900, 0x0400, 0x0100, PITCH_END
};

static const s16 sPitch5_3[] = {
    0x0900, 0x0400, 0x0900, 0x0400, -0x300, PITCH_END
};

static const s16 sPitch5_4[] = {
    0x0b00, 0x0800, 0x0400, 0x0400, 0x0600, PITCH_END
};

static const s16 sPitch6_0[] = {
    -0x300, -0x100, 0x0100, 0x0200, 0x0400, 0x0600, PITCH_END
};

static const s16 sPitch6_1[] = {
    0x0800, 0x0600, 0x0400, 0x0200, 0x0100, -0x100, PITCH_END
};

static const s16 sPitch6_2[] = {
    0x0100, 0x0200, 0x0400, 0x0100, 0x0200, 0x1000, PITCH_END
};

static const s16 sPitch6_3[] = {
    0x0400, -0x300, 0x0900, 0x0400, 0x0900, 0x0400, PITCH_END
};

static const s16 sPitch6_4[] = {
    0x0800, 0x0900, 0x0800, 0x0900, 0x0800, 0x0900, PITCH_END
};

static const s16 sPitch7_0[] = {
    0x0200, 0x0100, 0x0200, 0x0100, 0x0200, 0x0400, 0x0200, PITCH_END
};

static const s16 sPitch7_1[] = {
    0x0100, 0x0100, -0x100, -0x100, -0x300, 0x0400, -0x300, PITCH_END
};

static const s16 sPitch7_2[] = {
    0x0800, 0x0900, 0x0b00, 0x0d00, 0x0e00, 0x0d00, 0x0b00, PITCH_END
};

static const s16 sPitch7_3[] = {
    0x0800, 0x0600, 0x0400, 0x0200, 0x0d00, 0x0b00, 0x0900, PITCH_END
};

static const s16 sPitch7_4[] = {
    0x0300, 0x0400, 0x0600, 0x0800, 0x0700, 0x0800, 0x0400, PITCH_END
};

// Only sPitch7_# are used below
// This table is always indexed with (x + 30), where x is some value 0 - 4
static const s16 *const sBardSoundPitchTables[] = {
    sPitch1_0,
    sPitch1_1,
    sPitch1_2,
    sPitch1_3,
    sPitch1_4,
    sPitch2_0,
    sPitch2_1,
    sPitch2_2,
    sPitch2_3,
    sPitch2_4,
    sPitch3_0,
    sPitch3_1,
    sPitch3_2,
    sPitch3_3,
    sPitch3_4,
    sPitch4_0,
    sPitch4_1,
    sPitch4_2,
    sPitch4_3,
    sPitch4_4,
    sPitch5_0,
    sPitch5_1,
    sPitch5_2,
    sPitch5_3,
    sPitch5_4,
    sPitch6_0,
    sPitch6_1,
    sPitch6_2,
    sPitch6_3,
    sPitch6_4,
    sPitch7_0,
    sPitch7_1,
    sPitch7_2,
    sPitch7_3,
    sPitch7_4
};


#endif //GUARD_WORD_PITCH_H

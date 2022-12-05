#define _2NDFRAME_1STFRAME(duration1, duration2)\
    ANIMCMD_FRAME(1, duration1),                \
    ANIMCMD_FRAME(0, duration2)

#define ANIM_SINGLE_FRAME(name, frameNum, duration)\
static const union AnimCmd sAnim_##name[] =             \
{                                                       \
    ANIMCMD_FRAME(frameNum, duration),                  \
    ANIMCMD_END,                                        \
}

#define ANIM_BACK_AND_FORTH_1_TIME(name, duration1,            \
                                              duration2, duration3) \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(0, duration1),                                    \
    _2NDFRAME_1STFRAME(duration2, duration3),                       \
    ANIMCMD_END,                                                    \
}


#define ANIM_BACK_AND_FORTH_2_TIMES(name, duration1,           \
                                               duration2, duration3,\
                                               duration4, duration5)\
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(0, duration1),                                    \
    _2NDFRAME_1STFRAME(duration2, duration3),                       \
    _2NDFRAME_1STFRAME(duration4, duration5),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_BACK_AND_FORTH_3_TIMES(name, duration1,           \
                                               duration2, duration3,\
                                               duration4, duration5,\
                                               duration6, duration7)\
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(0, duration1),                                    \
    _2NDFRAME_1STFRAME(duration2, duration3),                       \
    _2NDFRAME_1STFRAME(duration4, duration5),                       \
    _2NDFRAME_1STFRAME(duration6, duration7),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_BACK_AND_FORTH_4_TIMES(name, duration1,           \
                                               duration2, duration3,\
                                               duration4, duration5,\
                                               duration6, duration7,\
                                               duration8, duration9)\
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(0, duration1),                                    \
    _2NDFRAME_1STFRAME(duration2, duration3),                       \
    _2NDFRAME_1STFRAME(duration4, duration5),                       \
    _2NDFRAME_1STFRAME(duration6, duration7),                       \
    _2NDFRAME_1STFRAME(duration8, duration9),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_BACK_AND_FORTH_5_TIMES(name, duration1,               \
                                               duration2, duration3,    \
                                               duration4, duration5,    \
                                               duration6, duration7,    \
                                               duration8, duration9,    \
                                               duration10, duration11)  \
static const union AnimCmd sAnim_##name[] =                             \
{                                                                       \
    ANIMCMD_FRAME(0, duration1),                                        \
    _2NDFRAME_1STFRAME(duration2, duration3),                           \
    _2NDFRAME_1STFRAME(duration4, duration5),                           \
    _2NDFRAME_1STFRAME(duration6, duration7),                           \
    _2NDFRAME_1STFRAME(duration8, duration9),                           \
    _2NDFRAME_1STFRAME(duration10, duration11),                         \
    ANIMCMD_END,                                                        \
}

#define ANIM_BACK_AND_FORTH_6_TIMES(name, duration1,               \
                                               duration2, duration3,    \
                                               duration4, duration5,    \
                                               duration6, duration7,    \
                                               duration8, duration9,    \
                                               duration10, duration11,  \
                                               duration12, duration13)  \
static const union AnimCmd sAnim_##name[] =                             \
{                                                                       \
    ANIMCMD_FRAME(0, duration1),                                        \
    _2NDFRAME_1STFRAME(duration2, duration3),                           \
    _2NDFRAME_1STFRAME(duration4, duration5),                           \
    _2NDFRAME_1STFRAME(duration6, duration7),                           \
    _2NDFRAME_1STFRAME(duration8, duration9),                           \
    _2NDFRAME_1STFRAME(duration10, duration11),                         \
    _2NDFRAME_1STFRAME(duration12, duration13),                         \
    ANIMCMD_END,                                                        \
}

#define ANIM_BACK_AND_FORTH_7_TIMES(name, duration1,               \
                                               duration2, duration3,    \
                                               duration4, duration5,    \
                                               duration6, duration7,    \
                                               duration8, duration9,    \
                                               duration10, duration11,  \
                                               duration12, duration13,  \
                                               duration14, duration15)  \
static const union AnimCmd sAnim_##name[] =                             \
{                                                                       \
    ANIMCMD_FRAME(0, duration1),                                        \
    _2NDFRAME_1STFRAME(duration2, duration3),                           \
    _2NDFRAME_1STFRAME(duration4, duration5),                           \
    _2NDFRAME_1STFRAME(duration6, duration7),                           \
    _2NDFRAME_1STFRAME(duration8, duration9),                           \
    _2NDFRAME_1STFRAME(duration10, duration11),                         \
    _2NDFRAME_1STFRAME(duration12, duration13),                         \
    _2NDFRAME_1STFRAME(duration14, duration15),                         \
    ANIMCMD_END,                                                        \
}

#define ANIM_BACK_AND_FORTH_8_TIMES(name, duration1,               \
                                               duration2, duration3,    \
                                               duration4, duration5,    \
                                               duration6, duration7,    \
                                               duration8, duration9,    \
                                               duration10, duration11,  \
                                               duration12, duration13,  \
                                               duration14, duration15,  \
                                               duration16, duration17)  \
static const union AnimCmd sAnim_##name[] =                             \
{                                                                       \
    ANIMCMD_FRAME(0, duration1),                                        \
    _2NDFRAME_1STFRAME(duration2, duration3),                           \
    _2NDFRAME_1STFRAME(duration4, duration5),                           \
    _2NDFRAME_1STFRAME(duration6, duration7),                           \
    _2NDFRAME_1STFRAME(duration8, duration9),                           \
    _2NDFRAME_1STFRAME(duration10, duration11),                         \
    _2NDFRAME_1STFRAME(duration12, duration13),                         \
    _2NDFRAME_1STFRAME(duration14, duration15),                         \
    _2NDFRAME_1STFRAME(duration16, duration17),                         \
    ANIMCMD_END,                                                        \
}

#define ANIM_BACK_AND_FORTH_9_TIMES(name, duration1,            \
                                        duration2, duration3,   \
                                        duration4, duration5,   \
                                        duration6, duration7,   \
                                        duration8, duration9,   \
                                        duration10, duration11, \
                                        duration12, duration13, \
                                        duration14, duration15, \
                                        duration16, duration17, \
                                        duration18, duration19) \
static const union AnimCmd sAnim_##name[] =                     \
{                                                               \
    ANIMCMD_FRAME(0, duration1),                                \
    _2NDFRAME_1STFRAME(duration2, duration3),                   \
    _2NDFRAME_1STFRAME(duration4, duration5),                   \
    _2NDFRAME_1STFRAME(duration6, duration7),                   \
    _2NDFRAME_1STFRAME(duration8, duration9),                   \
    _2NDFRAME_1STFRAME(duration10, duration11),                 \
    _2NDFRAME_1STFRAME(duration12, duration13),                 \
    _2NDFRAME_1STFRAME(duration14, duration15),                 \
    _2NDFRAME_1STFRAME(duration16, duration17),                 \
    _2NDFRAME_1STFRAME(duration18, duration19),                 \
    ANIMCMD_END,                                                \
}

#define ANIM_CONSTANT_BACK_AND_FORTH_1_TIME(name, duration) ANIM_BACK_AND_FORTH_1_TIME(name, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(name, duration) ANIM_BACK_AND_FORTH_2_TIMES(name, duration, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(name, duration) ANIM_BACK_AND_FORTH_3_TIMES(name, duration, duration, duration, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(name, duration) ANIM_BACK_AND_FORTH_4_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES(name, duration) ANIM_BACK_AND_FORTH_5_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES(name, duration) ANIM_BACK_AND_FORTH_6_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration)

#define ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_BEGIN(name, begin, duration) ANIM_BACK_AND_FORTH_2_TIMES(name, begin, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_BEGIN(name, begin, duration) ANIM_BACK_AND_FORTH_3_TIMES(name, begin, duration, duration, duration, duration, duration, duration)
#define ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES_BEGIN(name, begin, duration) ANIM_BACK_AND_FORTH_5_TIMES(name, begin, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration)

#define ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_END(name, duration, end) ANIM_BACK_AND_FORTH_2_TIMES(name, duration, duration, duration, duration, end)
#define ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(name, duration, end) ANIM_BACK_AND_FORTH_3_TIMES(name, duration, duration, duration, duration, duration, duration, end)
#define ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES_END(name, duration, end) ANIM_BACK_AND_FORTH_4_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, end)
#define ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES_END(name, duration, end) ANIM_BACK_AND_FORTH_6_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, end)

#define ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(name, duration1, duration2) ANIM_BACK_AND_FORTH_2_TIMES(name, duration1, duration2, duration1, duration2, duration1)

#define ANIM_BACK_AND_FORTH_REPEATED_FRAME(name, duration1, duration2,  \
                                                 duration3, duration4)  \
static const union AnimCmd sAnim_##name[] =                             \
{                                                                       \
    ANIMCMD_FRAME(0, duration1),                                        \
    ANIMCMD_FRAME(1, duration2),                                        \
    ANIMCMD_FRAME(1, duration3),                                        \
    ANIMCMD_FRAME(0, duration4),                                        \
    ANIMCMD_END,                                                        \
}

#define ANIM_2NDFRAMEx2_1STFRAME(name, duration1,              \
                                            duration2, duration3)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(1, duration1),                                    \
    _2NDFRAME_1STFRAME(duration2, duration3),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_1_TIME( name,                   \
                                            duration1, duration2)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_2_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_3_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    ANIMCMD_END,                                                \
}

#define ANIM_2NDFRAME_1STFRAME_4_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6,   \
                                            duration7, duration8)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    _2NDFRAME_1STFRAME(duration7, duration8),                       \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_5_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6,   \
                                            duration7, duration8,   \
                                            duration9, duration10)  \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    _2NDFRAME_1STFRAME(duration7, duration8),                       \
    _2NDFRAME_1STFRAME(duration9, duration10),                      \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_6_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6,   \
                                            duration7, duration8,   \
                                            duration9, duration10,  \
                                            duration11,duration12)  \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    _2NDFRAME_1STFRAME(duration7, duration8),                       \
    _2NDFRAME_1STFRAME(duration9, duration10),                      \
    _2NDFRAME_1STFRAME(duration11, duration12),                     \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_8_TIMES(name,                   \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6,   \
                                            duration7, duration8,   \
                                            duration9, duration10,  \
                                            duration11,duration12,  \
                                            duration13,duration14,  \
                                            duration15,duration16)  \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    _2NDFRAME_1STFRAME(duration7, duration8),                       \
    _2NDFRAME_1STFRAME(duration9, duration10),                      \
    _2NDFRAME_1STFRAME(duration11, duration12),                     \
    _2NDFRAME_1STFRAME(duration13, duration14),                     \
    _2NDFRAME_1STFRAME(duration15, duration16),                     \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_11_TIMES(name,                  \
                                            duration1, duration2,   \
                                            duration3, duration4,   \
                                            duration5, duration6,   \
                                            duration7, duration8,   \
                                            duration9, duration10,  \
                                            duration11,duration12,  \
                                            duration13,duration14,  \
                                            duration15,duration16,  \
                                            duration17,duration18,  \
                                            duration19,duration20,  \
                                            duration21,duration22)  \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    _2NDFRAME_1STFRAME(duration1, duration2),                       \
    _2NDFRAME_1STFRAME(duration3, duration4),                       \
    _2NDFRAME_1STFRAME(duration5, duration6),                       \
    _2NDFRAME_1STFRAME(duration7, duration8),                       \
    _2NDFRAME_1STFRAME(duration9, duration10),                      \
    _2NDFRAME_1STFRAME(duration11, duration12),                     \
    _2NDFRAME_1STFRAME(duration13, duration14),                     \
    _2NDFRAME_1STFRAME(duration15, duration16),                     \
    _2NDFRAME_1STFRAME(duration17, duration18),                     \
    _2NDFRAME_1STFRAME(duration19, duration20),                     \
    _2NDFRAME_1STFRAME(duration21, duration22),                     \
    ANIMCMD_END,                                                    \
}

#define ANIM_2NDFRAME_1STFRAME_13_TIMES_SINGLE_DURATION(name, duration)\
static const union AnimCmd sAnim_##name[] =                                 \
{                                                                           \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    ANIMCMD_END,                                                            \
}

#define ANIM_2NDFRAME_1STFRAME_16_TIMES_SINGLE_DURATION(name, duration)\
static const union AnimCmd sAnim_##name[] =                                 \
{                                                                           \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    _2NDFRAME_1STFRAME(duration, duration),                                 \
    ANIMCMD_END,                                                            \
}

#define ANIM_1STFRAME_3RDFRAME_1_TIME(name,               \
                                            duration1, duration2) \
static const union AnimCmd sAnim_##name[] =                     \
{                                                               \
    ANIMCMD_FRAME(0, duration1),                                 \
    ANIMCMD_FRAME(2, duration2),                                 \
    ANIMCMD_END,                                                \
}

#define ANIM_1STFRAME_3RDFRAME_2_TIMES(name,                        \
                                            duration1, duration2,   \
                                            duration3, duration4)   \
static const union AnimCmd sAnim_##name[] =                         \
{                                                                   \
    ANIMCMD_FRAME(0, duration1),                                    \
    ANIMCMD_FRAME(2, duration2),                                    \
    ANIMCMD_FRAME(0, duration3),                                    \
    ANIMCMD_FRAME(2, duration4),                                    \
    ANIMCMD_END,                                                    \
}

#define ANIM_1STFRAME_3RDFRAME_3_TIMES(name,               \
                                            duration1, duration2, \
                                            duration3, duration4, \
                                            duration5, duration6) \
static const union AnimCmd sAnim_##name[] =                     \
{                                                               \
    ANIMCMD_FRAME(0, duration1),                                 \
    ANIMCMD_FRAME(2, duration2),                                 \
    ANIMCMD_FRAME(0, duration3),                                 \
    ANIMCMD_FRAME(2, duration4),                                 \
    ANIMCMD_FRAME(0, duration5),                                 \
    ANIMCMD_FRAME(2, duration6),                                 \
    ANIMCMD_END,                                                \
}

#define ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(name, duration) ANIM_1STFRAME_3RDFRAME_2_TIMES(name, duration, duration, duration, duration)
#define ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(name, duration) ANIM_2NDFRAME_1STFRAME_3_TIMES(name, duration, duration, duration, duration, duration, duration)
#define ANIM_2NDFRAME_1STFRAME_4_TIMES_CONSTANT(name, duration) ANIM_2NDFRAME_1STFRAME_4_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration)
#define ANIM_2NDFRAME_1STFRAME_5_TIMES_CONSTANT(name, duration) ANIM_2NDFRAME_1STFRAME_5_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration)
#define ANIM_2NDFRAME_1STFRAME_6_TIMES_CONSTANT(name, duration) ANIM_2NDFRAME_1STFRAME_6_TIMES(name, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration, duration)

#define ANIM_2NDFRAME_1STFRAME_4_TIMES_CONSTANT_END(name, duration, end) ANIM_2NDFRAME_1STFRAME_4_TIMES(name, duration, duration, duration, duration, duration, duration, duration, end)

#define ANIM_2NDFRAME_1STFRAME_5_TIMES_CONSTANT_BEGIN(name, begin, duration) ANIM_2NDFRAME_1STFRAME_5_TIMES(name, begin, duration, duration, duration, duration, duration, duration, duration, duration, duration)

ANIM_BACK_AND_FORTH_1_TIME(None_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(Bulbasaur_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(Ivysaur_1, 1, 36, 10);
ANIM_BACK_AND_FORTH_1_TIME(Venusaur_1, 10, 25, 10);
ANIM_BACK_AND_FORTH_1_TIME(Charmander_1, 2, 46, 10);
ANIM_BACK_AND_FORTH_1_TIME(Charmeleon_1, 10, 25, 30);
ANIM_2NDFRAME_1STFRAME_1_TIME(Charizard_1, 40, 5);
ANIM_2NDFRAMEx2_1STFRAME(Squirtle_1, 50, 50, 10);
ANIM_BACK_AND_FORTH_1_TIME(Wartortle_1, 10, 20, 5);
ANIM_BACK_AND_FORTH_2_TIMES(Blastoise_1, 50, 25, 20, 25, 1);
ANIM_2NDFRAME_1STFRAME_4_TIMES_CONSTANT_END(Caterpie_1, 15, 5);
ANIM_2NDFRAME_1STFRAME_1_TIME(Metapod_1, 45, 5);
ANIM_BACK_AND_FORTH_6_TIMES(Butterfree_1, 5, 5, 5, 5, 5, 5, 25, 5, 5, 5, 5, 5, 5);
ANIM_BACK_AND_FORTH_3_TIMES(Weedle_1, 5, 15, 15, 15, 15, 15, 5);
ANIM_BACK_AND_FORTH_5_TIMES(Kakuna_1, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5);
ANIM_BACK_AND_FORTH_2_TIMES(Beedrill_1, 5, 35, 28, 10, 10);
ANIM_2NDFRAME_1STFRAME_6_TIMES(Pidgey_1, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Pidgeotto_1, 5, 10, 10, 35, 5);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Pidgeot_1, 20, 10, 15, 1);
ANIM_BACK_AND_FORTH_REPEATED_FRAME(Rattata_1, 3, 50, 28, 5);
ANIM_2NDFRAME_1STFRAME_6_TIMES_CONSTANT(Raticate_1, 5);
static const union AnimCmd sAnim_Spearow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
ANIM_2NDFRAME_1STFRAME_4_TIMES(Fearow_1, 7, 7, 7, 15, 7, 7, 7, 7);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Ekans_1, 8, 8, 8, 8, 40, 8);
ANIM_BACK_AND_FORTH_1_TIME(Arbok_1, 5, 35, 10);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Pikachu_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Pikachu_2, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Raichu_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Raichu_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Sandshrew_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Sandshrew_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Sandslash_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Sandslash_2, 20);
ANIM_BACK_AND_FORTH_4_TIMES(NidoranF_1, 5, 5, 5, 5, 50, 5, 5, 5, 1);
ANIM_2NDFRAME_1STFRAME_1_TIME(Nidorina_1, 40, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Nidoqueen_1, 45, 5);
ANIM_BACK_AND_FORTH_1_TIME(NidoranM_1, 15, 15, 5);
ANIM_BACK_AND_FORTH_1_TIME(Nidorino_1, 15, 15, 5);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Nidoking_1, 10, 15, 40, 10);
ANIM_BACK_AND_FORTH_1_TIME(Clefairy_1, 15, 15, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Clefable_1, 27, 27, 24, 25, 27, 5);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Vulpix_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Vulpix_2, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Ninetales_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Ninetales_2, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Jigglypuff_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Jigglypuff_2, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Wigglytuff_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Wigglytuff_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES(Zubat_1, 3);
ANIM_BACK_AND_FORTH_9_TIMES(Golbat_1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Oddish_1, 11, 6);
ANIM_BACK_AND_FORTH_REPEATED_FRAME(Gloom_1, 21, 45, 10, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Vileplume_1, 7, 21, 13, 21, 10);
ANIM_2NDFRAME_1STFRAME_8_TIMES(Paras_1, 5, 5, 5, 15, 5, 5, 5, 15, 5, 5, 5, 15, 5, 5, 5, 5);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Parasect_1, 10, 10, 10, 15, 35, 15);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Venonat_1, 5, 5, 5, 35, 15, 15);
ANIM_2NDFRAME_1STFRAME_11_TIMES(Venomoth_1, 4, 4, 4, 4, 4, 4, 4, 10, 4, 4, 4, 4, 4, 4, 4, 10, 4, 4, 4, 4, 4, 4);
ANIM_BACK_AND_FORTH_1_TIME(Diglett_1, 25, 35, 5);
ANIM_2NDFRAME_1STFRAME_5_TIMES_CONSTANT_BEGIN(Dugtrio_1, 35, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Meowth_1, 8, 8, 8, 17, 30, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Persian_1, 50, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Psyduck_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Psyduck_2, 20);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Golduck_1, 15, 20);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Golduck_2, 20);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Mankey_1, 5, 5, 5, 28, 20, 5);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Primeape_1, 15, 15, 15, 15, 15, 15);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Growlithe_1, 8, 8, 8, 15, 20, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Arcanine_1, 8, 8, 8, 15, 40, 10);
ANIM_BACK_AND_FORTH_1_TIME(Poliwag_1, 20, 10, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Poliwhirl_1, 10, 25, 10, 20, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Poliwrath_1, 45, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Abra_1, 7, 21, 13, 21, 10);
ANIM_BACK_AND_FORTH_1_TIME(Kadabra_1, 12, 45, 15);
ANIM_BACK_AND_FORTH_1_TIME(Alakazam_1, 9, 54, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Machop_1, 15, 10);
ANIM_BACK_AND_FORTH_1_TIME(Machoke_1, 20, 44, 20);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Machamp_1, 11);
ANIM_BACK_AND_FORTH_1_TIME(Bellsprout_1, 5, 25, 10);
ANIM_BACK_AND_FORTH_3_TIMES(Weepinbell_1, 5, 25, 10, 25, 10, 25, 10);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Victreebel_1, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Tentacool_1, 8, 15, 7, 11, 11);
ANIM_BACK_AND_FORTH_2_TIMES(Tentacruel_1, 19, 35, 19, 19, 8);
ANIM_BACK_AND_FORTH_1_TIME(Geodude_1, 15, 36, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Graveler_1, 16);
static const union AnimCmd sAnim_Golem_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 31),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
ANIM_2NDFRAME_1STFRAME_1_TIME(Ponyta_1, 45, 5);
ANIM_BACK_AND_FORTH_1_TIME(Rapidash_1, 10, 40, 10);
ANIM_BACK_AND_FORTH_1_TIME(Slowpoke_1, 20, 50, 20);
ANIM_2NDFRAMEx2_1STFRAME(Slowbro_1, 50, 45, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_END(Magnemite_1, 28, 10);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Magneton_1, 14);
ANIM_2NDFRAME_1STFRAME_6_TIMES(Farfetchd_1, 5, 5, 5, 15, 5, 5, 5, 15, 5, 5, 5, 5);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_END(Doduo_1, 18, 10);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES_END(Dodrio_1, 12, 8);
ANIM_2NDFRAME_1STFRAME_4_TIMES_CONSTANT(Seel_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_1_TIME(Dewgong_1, 30);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Grimer_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Grimer_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Muk_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Muk_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Shellder_1, 5, 5, 45, 5);
ANIM_2NDFRAME_1STFRAME_8_TIMES(Cloyster_1, 5, 5, 5, 5, 5, 5, 5, 25, 5, 5, 5, 5, 5, 5, 5, 5);
ANIM_2NDFRAMEx2_1STFRAME(Gastly_1, 50, 30, 10);

static const union AnimCmd sAnim_Haunter_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
ANIM_2NDFRAMEx2_1STFRAME(Gengar_1, 50, 40, 10);
ANIM_2NDFRAMEx2_1STFRAME(Onix_1, 50, 30, 30);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Drowzee_1, 12, 12, 12, 12, 45, 10);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Hypno_1, 15);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Krabby_1, 8, 8, 8, 8, 8, 8);
ANIM_BACK_AND_FORTH_4_TIMES(Kingler_1, 5, 15, 10, 15, 25, 10, 10, 10, 10);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Voltorb_1, 4, 25);
ANIM_SWITCH_BACK_AND_FORTH_2_TIMES(Electrode_1, 8, 30);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Exeggcute_1, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Exeggutor_1, 35, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(Cubone_1, 14);
ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(Marowak_1, 14);
ANIM_2NDFRAME_1STFRAME_1_TIME(Hitmonlee_1, 15, 20);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Hitmonchan_1, 5, 5, 5, 5, 5, 15, 25, 10);
ANIM_BACK_AND_FORTH_1_TIME(Lickitung_1, 28, 32, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Koffing_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Koffing_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Weezing_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Weezing_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_BEGIN(Rhyhorn_1, 11, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Rhyhorn_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Rhydon_1, 11, 10, 10, 48, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Rhydon_2, 20);
ANIM_BACK_AND_FORTH_1_TIME(Chansey_1, 30, 30, 20);
ANIM_2NDFRAME_1STFRAME_5_TIMES_CONSTANT(Tangela_1, 9);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Kangaskhan_1, 10, 10, 20, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Horsea_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Horsea_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Seadra_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Seadra_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES_END(Goldeen_1, 16, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Seaking_1, 10, 20, 10, 20, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Staryu_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Staryu_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Starmie_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Starmie_2, 20);
ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(MrMime_1, 15);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Scyther_1, 5, 5, 25, 5, 5, 5, 5, 5);

static const union AnimCmd sAnim_Jynx_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
ANIM_2NDFRAME_1STFRAME_2_TIMES(Electabuzz_1, 10, 10, 40, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Magmar_1, 40, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES_BEGIN(Pinsir_1, 11, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Pinsir_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Tauros_1, 10, 20, 25, 20);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Magikarp_1, 8);
ANIM_BACK_AND_FORTH_1_TIME(Gyarados_1, 8, 32, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Lapras_1, 30, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Ditto_1, 10, 10, 10, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Eevee_1, 33, 5);
ANIM_2NDFRAME_1STFRAME_1_TIME(Vaporeon_1, 40, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Jolteon_1, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Flareon_1, 30, 30);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Porygon_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Omanyte_1, 10, 10, 10, 20, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Omastar_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Kabuto_1, 8, 8, 8, 20, 8, 8, 8, 8);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Kabutops_1, 10, 10, 20, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Aerodactyl_1, 10, 25, 10, 25);
ANIM_2NDFRAMEx2_1STFRAME(Snorlax_1, 50, 50, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Articuno_1, 25, 15, 20, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Zapdos_1, 10, 10, 30, 10);
ANIM_2NDFRAME_1STFRAME_16_TIMES_SINGLE_DURATION(Moltres_1, 3);
ANIM_CONSTANT_BACK_AND_FORTH_1_TIME(Dratini_1, 15);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Dragonair_1, 10, 10, 20, 10);
ANIM_2NDFRAMEx2_1STFRAME(Dragonite_1, 50, 30, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Mewtwo_1, 15, 20);
ANIM_2NDFRAMEx2_1STFRAME(Mew_1, 50, 40, 10);
ANIM_BACK_AND_FORTH_1_TIME(Chikorita_1, 15, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Bayleef_1, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Meganium_1, 30, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Cyndaquil_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Quilava_1, 30, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Typhlosion_1, 20, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(Totodile_1, 8);
ANIM_2NDFRAME_1STFRAME_1_TIME(Croconaw_1, 40, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Feraligatr_1, 10, 10, 25, 40);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Sentret_1, 15, 15, 15, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Furret_1, 35, 5);
ANIM_2NDFRAME_1STFRAME_6_TIMES_CONSTANT(Hoothoot_1, 7);
ANIM_2NDFRAME_1STFRAME_1_TIME(Noctowl_1, 40, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Ledyba_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_13_TIMES_SINGLE_DURATION(Ledian_1, 3);
ANIM_2NDFRAME_1STFRAME_4_TIMES_CONSTANT(Spinarak_1, 6);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Ariados_1, 10, 10, 20, 10);
ANIM_BACK_AND_FORTH_8_TIMES(Crobat_1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);
ANIM_BACK_AND_FORTH_2_TIMES(Chinchou_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Chinchou_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Lanturn_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Lanturn_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Pichu_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Pichu_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Cleffa_1, 10, 10, 10, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Igglybuff_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Igglybuff_2, 20);
ANIM_2NDFRAMEx2_1STFRAME(Togepi_1, 50, 50, 10);
ANIM_BACK_AND_FORTH_1_TIME(Togetic_1, 15, 15, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Natu_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Natu_2, 20);
ANIM_BACK_AND_FORTH_3_TIMES(Xatu_1, 15, 45, 15, 10, 15, 10, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Xatu_2, 20);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Mareep_1, 10, 10, 10, 20, 15, 15);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Flaaffy_1, 10, 10, 10, 10);
ANIM_2NDFRAMEx2_1STFRAME(Ampharos_1, 50, 15, 10);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Bellossom_1, 22);
ANIM_BACK_AND_FORTH_2_TIMES(Marill_1, 20, 44, 22, 44, 11);
ANIM_BACK_AND_FORTH_2_TIMES(Azumarill_1, 22, 22, 22, 22, 11);
ANIM_2NDFRAME_1STFRAME_3_TIMES_CONSTANT(Sudowoodo_1, 15);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Politoed_1, 10, 10, 10, 10, 35, 5);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Hoppip_1, 25, 25, 25, 25);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Skiploom_1, 12, 12, 12, 30, 12, 12, 12, 15);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Jumpluff_1, 15, 25, 15, 25, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Aipom_1, 35, 5);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Sunkern_1, 10, 10, 10, 10);
ANIM_BACK_AND_FORTH_1_TIME(Sunflora_1, 15, 15, 15);
ANIM_2NDFRAME_1STFRAME_11_TIMES(Yanma_1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 20, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);
ANIM_BACK_AND_FORTH_1_TIME(Wooper_1, 15, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Quagsire_1, 32, 20);
ANIM_BACK_AND_FORTH_1_TIME(Espeon_1, 15, 25, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Umbreon_1, 40, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Murkrow_1, 15, 20);
ANIM_BACK_AND_FORTH_1_TIME(Slowking_1, 15, 20, 15);
ANIM_2NDFRAME_1STFRAME_5_TIMES_CONSTANT(Misdreavus_1, 10);
ANIM_BACK_AND_FORTH_1_TIME(Unown_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_2_TIMES(Wobbuffet_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Wobbuffet_2, 20);
ANIM_BACK_AND_FORTH_3_TIMES(Girafarig_1, 15, 20, 15, 10, 15, 10, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Girafarig_2, 20);
ANIM_2NDFRAME_1STFRAME_4_TIMES(Pineco_1, 10, 10, 10, 20, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Forretress_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Dunsparce_1, 10, 15, 15, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Gligar_1, 17, 10);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Steelix_1, 10, 8, 10, 20, 35, 5);
ANIM_2NDFRAME_1STFRAME_1_TIME(Snubbull_1, 32, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Granbull_1, 35, 20);
static const union AnimCmd sAnim_Qwilfish_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};
ANIM_2NDFRAME_1STFRAME_1_TIME(Scizor_1, 20, 20);
ANIM_2NDFRAMEx2_1STFRAME(Shuckle_1, 50, 50, 30);
ANIM_BACK_AND_FORTH_2_TIMES(Heracross_1, 11, 10, 10, 10, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Heracross_2, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Sneasel_1, 15, 15);
ANIM_2NDFRAME_1STFRAME_1_TIME(Teddiursa_1, 30, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Ursaring_1, 40, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Slugma_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Slugma_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Magcargo_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Magcargo_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Swinub_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Piloswine_1, 10, 10, 10, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Corsola_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Corsola_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Remoraid_1, 8, 8, 8, 8);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Octillery_1, 10, 10, 30, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Delibird_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Mantine_1, 30, 30, 30, 40);
ANIM_BACK_AND_FORTH_2_TIMES(Skarmory_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Skarmory_2, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Houndour_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Houndoom_1, 40, 30);
ANIM_BACK_AND_FORTH_2_TIMES(Kingdra_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Kingdra_2, 20);
ANIM_BACK_AND_FORTH_3_TIMES(Phanpy_1, 15, 20, 15, 10, 15, 10, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Phanpy_2, 20);
ANIM_BACK_AND_FORTH_3_TIMES(Donphan_1, 15, 20, 15, 10, 15, 10, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Donphan_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Porygon2_1, 15, 15, 15, 15, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Stantler_1, 15, 15);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Smeargle_1, 12, 12, 12, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Tyrogue_1, 40, 20);
ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES(Hitmontop_1, 4);
ANIM_2NDFRAME_1STFRAME_3_TIMES(Smoochum_1, 10, 10, 10, 30, 15, 15);
ANIM_2NDFRAMEx2_1STFRAME(Elekid_1, 50, 5, 20);
ANIM_BACK_AND_FORTH_3_TIMES(Magby_1, 15, 15, 20, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Miltank_1, 30, 30);
ANIM_2NDFRAME_1STFRAME_1_TIME(Blissey_1, 20, 15);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Raikou_1, 10, 10, 30, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Entei_1, 20, 20);
ANIM_2NDFRAME_1STFRAME_1_TIME(Suicune_1, 40, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Larvitar_1, 10, 10, 10, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Pupitar_1, 40, 10);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Tyranitar_1, 10, 20, 10, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(Lugia_1, 20, 10);
ANIM_2NDFRAME_1STFRAME_1_TIME(HoOh_1, 20, 20);
ANIM_2NDFRAME_1STFRAME_2_TIMES(Celebi_1, 30, 30, 30, 30);
ANIM_BACK_AND_FORTH_1_TIME(OldUnownB_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_2_TIMES(Treecko_1, 6, 15, 6, 15, 3);
ANIM_BACK_AND_FORTH_2_TIMES(Grovyle_1, 10, 18, 7, 12, 6);
ANIM_BACK_AND_FORTH_1_TIME(Sceptile_1, 10, 26, 10);
ANIM_BACK_AND_FORTH_3_TIMES(Torchic_1, 7, 4, 4, 4, 4, 4, 10);
ANIM_BACK_AND_FORTH_1_TIME(Combusken_1, 8, 25, 12);
ANIM_BACK_AND_FORTH_2_TIMES(Blaziken_1, 1, 25, 7, 7, 7);

static const union AnimCmd sAnim_Blaziken_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
ANIM_1STFRAME_3RDFRAME_1_TIME(Blaziken_3, 10, 10);
ANIM_SINGLE_FRAME(Blaziken_4, 0, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Mudkip_1, 10, 8, 10, 13, 7);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES_END(Marshtomp_1, 5, 1);
ANIM_BACK_AND_FORTH_2_TIMES(Swampert_1, 8, 44, 18, 18, 7);
ANIM_BACK_AND_FORTH_1_TIME(Poochyena_1, 10, 44, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Mightyena_1, 27, 6, 6, 6, 6);
ANIM_BACK_AND_FORTH_2_TIMES(Zigzagoon_1, 27, 6, 6, 6, 1);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Linoone_1, 14);
ANIM_BACK_AND_FORTH_1_TIME(Wurmple_1, 22, 35, 10);
ANIM_BACK_AND_FORTH_1_TIME(Silcoon_1, 15, 25, 15);
ANIM_SINGLE_FRAME(Silcoon_2, 1, 1);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Beautifly_1, 2);
ANIM_SINGLE_FRAME(Beautifly_2, 1, 1);
ANIM_BACK_AND_FORTH_2_TIMES(Cascoon_1, 10, 10, 10, 10, 20);
ANIM_SINGLE_FRAME(Cascoon_2, 1, 1);
ANIM_BACK_AND_FORTH_7_TIMES(Dustox_1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 8, 8, 12, 20, 20);
ANIM_SINGLE_FRAME(Dustox_2, 1, 1);
ANIM_BACK_AND_FORTH_1_TIME(Lotad_1, 22, 55, 22);
ANIM_BACK_AND_FORTH_2_TIMES(Lombre_1, 6, 30, 6, 30, 7);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Ludicolo_1, 22);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Seedot_1, 10);
ANIM_BACK_AND_FORTH_4_TIMES(Nuzleaf_1, 7, 15, 7, 15, 7, 15, 7, 15, 7);
ANIM_BACK_AND_FORTH_1_TIME(Shiftry_1, 7, 35, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Nincada_1, 15, 22, 11, 33, 11);

static const union AnimCmd sAnim_Ninjask_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};
ANIM_BACK_AND_FORTH_2_TIMES(Shedinja_1, 33, 33, 33, 33, 11);
ANIM_BACK_AND_FORTH_4_TIMES(Taillow_1, 5, 15, 2, 2, 2, 2, 2, 2, 1);
ANIM_BACK_AND_FORTH_1_TIME(Swellow_1, 5, 18, 11);
ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES(Shroomish_1, 6);
ANIM_BACK_AND_FORTH_2_TIMES(Breloom_1, 6, 30, 6, 30, 7);
ANIM_BACK_AND_FORTH_1_TIME(Wingull_1, 17, 23, 13);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Pelipper_1, 5);
ANIM_BACK_AND_FORTH_2_TIMES(Surskit_1, 6, 18, 6, 18, 8);
ANIM_SINGLE_FRAME(Surskit_2, 1, 1);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Masquerain_1, 8);
ANIM_SINGLE_FRAME(Masquerain_2, 1, 1);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Wailmer_1, 22);
ANIM_BACK_AND_FORTH_1_TIME(Wailord_1, 26, 48, 33);
ANIM_BACK_AND_FORTH_1_TIME(Skitty_1, 15, 35, 9);
ANIM_BACK_AND_FORTH_1_TIME(Delcatty_1, 10, 46, 10);
ANIM_BACK_AND_FORTH_2_TIMES(Kecleon_1, 10, 18, 8, 8, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Baltoy_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Claydol_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Nosepass_1, 27, 3);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Torkoal_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Sableye_1, 10);
ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES_END(Barboach_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES(Whiscash_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Luvdisc_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Corphish_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Crawdaunt_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Feebas_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Milotic_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Carvanha_1, 6);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES_END(Sharpedo_1, 6, 22);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Trapinch_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Vibrava_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Flygon_1, 15, 50);
ANIM_BACK_AND_FORTH_4_TIMES(Makuhita_1, 7, 10, 7, 10, 7, 10, 7, 10, 22);
ANIM_BACK_AND_FORTH_REPEATED_FRAME(Hariyama_1, 30, 30, 16, 11);
ANIM_BACK_AND_FORTH_2_TIMES(Electrike_1, 8, 25, 17, 25, 3);
ANIM_BACK_AND_FORTH_2_TIMES(Manectric_1, 8, 33, 10, 25, 3);
ANIM_BACK_AND_FORTH_2_TIMES(Numel_1, 15, 15, 20, 15, 40);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Camerupt_1, 15);

static const union AnimCmd sAnim_Spheal_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 43),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Sealeo_1, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Walrein_1, 2, 10, 30, 6, 15);
ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES(Cacnea_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Cacturne_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Snorunt_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Glalie_1, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Lunatone_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Lunatone_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Solrock_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Solrock_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Azurill_1, 12);
ANIM_CONSTANT_BACK_AND_FORTH_5_TIMES_BEGIN(Spoink_1, 5, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Grumpig_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Plusle_1, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Minun_1, 10);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Mawile_1, 10);
ANIM_BACK_AND_FORTH_1_TIME(Meditite_1, 22, 2, 22);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Medicham_1, 11);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_BEGIN(Swablu_1, 1, 10);
ANIM_1STFRAME_3RDFRAME_3_TIMES(Swablu_2, 1, 8, 12, 8, 12, 8);
ANIM_BACK_AND_FORTH_2_TIMES(Altaria_1, 15, 20, 15, 20, 15);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Altaria_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Wynaut_1, 15, 15, 15, 15, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Duskull_1, 15, 15, 15, 15, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Dusclops_1, 15, 15, 15, 15, 15);
ANIM_BACK_AND_FORTH_1_TIME(Roselia_1, 18, 44, 22);
static const union AnimCmd sAnim_Slakoth_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};
ANIM_BACK_AND_FORTH_3_TIMES(Vigoroth_1, 13, 7, 13, 7, 13, 7, 11);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Slaking_1, 22);
ANIM_BACK_AND_FORTH_2_TIMES(Gulpin_1, 14, 14, 14, 14, 4);
ANIM_BACK_AND_FORTH_REPEATED_FRAME(Swalot_1, 15, 30, 30, 30);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Tropius_1, 15);
static const union AnimCmd sAnim_Whismur_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};
ANIM_BACK_AND_FORTH_2_TIMES(Loudred_1, 9, 9, 9, 9, 33);
ANIM_BACK_AND_FORTH_1_TIME(Exploud_1, 9, 44, 9);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Clamperl_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Huntail_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Gorebyss_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Absol_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Shuppet_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Banette_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Seviper_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Zangoose_1, 15, 50);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Relicanth_1, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Aron_1, 33, 44, 33, 33, 11);
ANIM_BACK_AND_FORTH_2_TIMES(Lairon_1, 12, 29, 10, 29, 1);
ANIM_BACK_AND_FORTH_1_TIME(Aggron_1, 10, 44, 11);
ANIM_SINGLE_FRAME(Castform_0, 0, 1);
ANIM_SINGLE_FRAME(Castform_1, 1, 1);
ANIM_SINGLE_FRAME(Castform_2, 2, 1);
ANIM_SINGLE_FRAME(Castform_3, 3, 1);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES_END(Volbeat_1, 11, 5);
ANIM_BACK_AND_FORTH_2_TIMES(Illumise_1, 22, 22, 22, 22, 11);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Lileep_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Cradily_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_3_TIMES(Anorith_1, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Armaldo_1, 15, 15, 15, 15, 15);
ANIM_BACK_AND_FORTH_1_TIME(Ralts_1, 8, 25, 8);
ANIM_BACK_AND_FORTH_1_TIME(Kirlia_1, 10, 39, 10);
ANIM_CONSTANT_BACK_AND_FORTH_6_TIMES_END(Gardevoir_1, 3, 1);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Bagon_1, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Shelgon_1, 15);
ANIM_BACK_AND_FORTH_2_TIMES(Salamence_1, 10, 10, 30, 15, 15);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Beldum_1, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Metang_1, 8);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Metagross_1, 16);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Regirock_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Regirock_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Regice_1, 20, 15, 10, 18, 10);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Registeel_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Registeel_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Kyogre_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Kyogre_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Groudon_1, 11, 10, 10, 20, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Groudon_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Rayquaza_1, 1, 8, 22, 6, 6);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Rayquaza_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Latias_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Latias_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_2_TIMES(Latios_1, 10);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Latios_2, 20);

static const union AnimCmd sAnim_Jirachi_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Jirachi_2, 20);
ANIM_BACK_AND_FORTH_2_TIMES(Deoxys_1, 16, 16, 26, 16, 16);
ANIM_1STFRAME_3RDFRAME_2_TIMES_CONSTANT(Deoxys_2, 20);
ANIM_CONSTANT_BACK_AND_FORTH_4_TIMES(Chimecho_1, 15);

static const union AnimCmd sAnim_Egg_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};
ANIM_BACK_AND_FORTH_1_TIME(UnownB_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownC_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownD_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownE_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownF_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownG_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownH_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownI_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownJ_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownK_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownL_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownM_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownN_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownO_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownP_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownQ_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownR_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownS_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownT_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownU_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownV_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownW_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownX_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownY_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownZ_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownEMark_1, 30, 30, 1);
ANIM_BACK_AND_FORTH_1_TIME(UnownQMark_1, 30, 30, 1);

#define SINGLE_ANIMATION(name)                      \
static const union AnimCmd *const sAnims_##name[] = \
{                                                   \
    sAnim_GeneralFrame0,                            \
    sAnim_##name##_1,                               \
}

#define DOUBLE_ANIMATION(name)                      \
static const union AnimCmd *const sAnims_##name[] = \
{                                                   \
    sAnim_GeneralFrame0,                            \
    sAnim_##name##_1,                               \
    sAnim_##name##_2,                               \
}

SINGLE_ANIMATION(None);
SINGLE_ANIMATION(Bulbasaur);
SINGLE_ANIMATION(Ivysaur);
SINGLE_ANIMATION(Venusaur);
SINGLE_ANIMATION(Charmander);
SINGLE_ANIMATION(Charmeleon);
SINGLE_ANIMATION(Charizard);
SINGLE_ANIMATION(Squirtle);
SINGLE_ANIMATION(Wartortle);
SINGLE_ANIMATION(Blastoise);
SINGLE_ANIMATION(Caterpie);
SINGLE_ANIMATION(Metapod);
SINGLE_ANIMATION(Butterfree);
SINGLE_ANIMATION(Weedle);
SINGLE_ANIMATION(Kakuna);
SINGLE_ANIMATION(Beedrill);
SINGLE_ANIMATION(Pidgey);
SINGLE_ANIMATION(Pidgeotto);
SINGLE_ANIMATION(Pidgeot);
SINGLE_ANIMATION(Rattata);
SINGLE_ANIMATION(Raticate);
SINGLE_ANIMATION(Spearow);
SINGLE_ANIMATION(Fearow);
SINGLE_ANIMATION(Ekans);
SINGLE_ANIMATION(Arbok);
DOUBLE_ANIMATION(Pikachu);
DOUBLE_ANIMATION(Raichu);
DOUBLE_ANIMATION(Sandshrew);
DOUBLE_ANIMATION(Sandslash);
SINGLE_ANIMATION(NidoranF);
SINGLE_ANIMATION(Nidorina);
SINGLE_ANIMATION(Nidoqueen);
SINGLE_ANIMATION(NidoranM);
SINGLE_ANIMATION(Nidorino);
SINGLE_ANIMATION(Nidoking);
SINGLE_ANIMATION(Clefairy);
SINGLE_ANIMATION(Clefable);
DOUBLE_ANIMATION(Vulpix);
DOUBLE_ANIMATION(Ninetales);
DOUBLE_ANIMATION(Jigglypuff);
DOUBLE_ANIMATION(Wigglytuff);
SINGLE_ANIMATION(Zubat);
SINGLE_ANIMATION(Golbat);
SINGLE_ANIMATION(Oddish);
SINGLE_ANIMATION(Gloom);
SINGLE_ANIMATION(Vileplume);
SINGLE_ANIMATION(Paras);
SINGLE_ANIMATION(Parasect);
SINGLE_ANIMATION(Venonat);
SINGLE_ANIMATION(Venomoth);
SINGLE_ANIMATION(Diglett);
SINGLE_ANIMATION(Dugtrio);
SINGLE_ANIMATION(Meowth);
SINGLE_ANIMATION(Persian);
DOUBLE_ANIMATION(Psyduck);
DOUBLE_ANIMATION(Golduck);
SINGLE_ANIMATION(Mankey);
SINGLE_ANIMATION(Primeape);
SINGLE_ANIMATION(Growlithe);
SINGLE_ANIMATION(Arcanine);
SINGLE_ANIMATION(Poliwag);
SINGLE_ANIMATION(Poliwhirl);
SINGLE_ANIMATION(Poliwrath);
SINGLE_ANIMATION(Abra);
SINGLE_ANIMATION(Kadabra);
SINGLE_ANIMATION(Alakazam);
SINGLE_ANIMATION(Machop);
SINGLE_ANIMATION(Machoke);
SINGLE_ANIMATION(Machamp);
SINGLE_ANIMATION(Bellsprout);
SINGLE_ANIMATION(Weepinbell);
SINGLE_ANIMATION(Victreebel);
SINGLE_ANIMATION(Tentacool);
SINGLE_ANIMATION(Tentacruel);
SINGLE_ANIMATION(Geodude);
SINGLE_ANIMATION(Graveler);
SINGLE_ANIMATION(Golem);
SINGLE_ANIMATION(Ponyta);
SINGLE_ANIMATION(Rapidash);
SINGLE_ANIMATION(Slowpoke);
SINGLE_ANIMATION(Slowbro);
SINGLE_ANIMATION(Magnemite);
SINGLE_ANIMATION(Magneton);
SINGLE_ANIMATION(Farfetchd);
SINGLE_ANIMATION(Doduo);
SINGLE_ANIMATION(Dodrio);
SINGLE_ANIMATION(Seel);
SINGLE_ANIMATION(Dewgong);
DOUBLE_ANIMATION(Grimer);
DOUBLE_ANIMATION(Muk);
SINGLE_ANIMATION(Shellder);
SINGLE_ANIMATION(Cloyster);
SINGLE_ANIMATION(Gastly);
SINGLE_ANIMATION(Haunter);
SINGLE_ANIMATION(Gengar);
SINGLE_ANIMATION(Onix);
SINGLE_ANIMATION(Drowzee);
SINGLE_ANIMATION(Hypno);
SINGLE_ANIMATION(Krabby);
SINGLE_ANIMATION(Kingler);
SINGLE_ANIMATION(Voltorb);
SINGLE_ANIMATION(Electrode);
SINGLE_ANIMATION(Exeggcute);
SINGLE_ANIMATION(Exeggutor);
SINGLE_ANIMATION(Cubone);
SINGLE_ANIMATION(Marowak);
SINGLE_ANIMATION(Hitmonlee);
SINGLE_ANIMATION(Hitmonchan);
SINGLE_ANIMATION(Lickitung);
DOUBLE_ANIMATION(Koffing);
DOUBLE_ANIMATION(Weezing);
DOUBLE_ANIMATION(Rhyhorn);
DOUBLE_ANIMATION(Rhydon);
SINGLE_ANIMATION(Chansey);
SINGLE_ANIMATION(Tangela);
SINGLE_ANIMATION(Kangaskhan);
DOUBLE_ANIMATION(Horsea);
DOUBLE_ANIMATION(Seadra);
SINGLE_ANIMATION(Goldeen);
SINGLE_ANIMATION(Seaking);
DOUBLE_ANIMATION(Staryu);
DOUBLE_ANIMATION(Starmie);
SINGLE_ANIMATION(MrMime);
SINGLE_ANIMATION(Scyther);
SINGLE_ANIMATION(Jynx);
SINGLE_ANIMATION(Electabuzz);
SINGLE_ANIMATION(Magmar);
DOUBLE_ANIMATION(Pinsir);
SINGLE_ANIMATION(Tauros);
SINGLE_ANIMATION(Magikarp);
SINGLE_ANIMATION(Gyarados);
SINGLE_ANIMATION(Lapras);
SINGLE_ANIMATION(Ditto);
SINGLE_ANIMATION(Eevee);
SINGLE_ANIMATION(Vaporeon);
SINGLE_ANIMATION(Jolteon);
SINGLE_ANIMATION(Flareon);
SINGLE_ANIMATION(Porygon);
SINGLE_ANIMATION(Omanyte);
SINGLE_ANIMATION(Omastar);
SINGLE_ANIMATION(Kabuto);
SINGLE_ANIMATION(Kabutops);
SINGLE_ANIMATION(Aerodactyl);
SINGLE_ANIMATION(Snorlax);
SINGLE_ANIMATION(Articuno);
SINGLE_ANIMATION(Zapdos);
SINGLE_ANIMATION(Moltres);
SINGLE_ANIMATION(Dratini);
SINGLE_ANIMATION(Dragonair);
SINGLE_ANIMATION(Dragonite);
SINGLE_ANIMATION(Mewtwo);
SINGLE_ANIMATION(Mew);
SINGLE_ANIMATION(Chikorita);
SINGLE_ANIMATION(Bayleef);
SINGLE_ANIMATION(Meganium);
SINGLE_ANIMATION(Cyndaquil);
SINGLE_ANIMATION(Quilava);
SINGLE_ANIMATION(Typhlosion);
SINGLE_ANIMATION(Totodile);
SINGLE_ANIMATION(Croconaw);
SINGLE_ANIMATION(Feraligatr);
SINGLE_ANIMATION(Sentret);
SINGLE_ANIMATION(Furret);
SINGLE_ANIMATION(Hoothoot);
SINGLE_ANIMATION(Noctowl);
SINGLE_ANIMATION(Ledyba);
SINGLE_ANIMATION(Ledian);
SINGLE_ANIMATION(Spinarak);
SINGLE_ANIMATION(Ariados);
SINGLE_ANIMATION(Crobat);
DOUBLE_ANIMATION(Chinchou);
DOUBLE_ANIMATION(Lanturn);
DOUBLE_ANIMATION(Pichu);
SINGLE_ANIMATION(Cleffa);
DOUBLE_ANIMATION(Igglybuff);
SINGLE_ANIMATION(Togepi);
SINGLE_ANIMATION(Togetic);
DOUBLE_ANIMATION(Natu);
DOUBLE_ANIMATION(Xatu);
SINGLE_ANIMATION(Mareep);
SINGLE_ANIMATION(Flaaffy);
SINGLE_ANIMATION(Ampharos);
SINGLE_ANIMATION(Bellossom);
SINGLE_ANIMATION(Marill);
SINGLE_ANIMATION(Azumarill);
SINGLE_ANIMATION(Sudowoodo);
SINGLE_ANIMATION(Politoed);
SINGLE_ANIMATION(Hoppip);
SINGLE_ANIMATION(Skiploom);
SINGLE_ANIMATION(Jumpluff);
SINGLE_ANIMATION(Aipom);
SINGLE_ANIMATION(Sunkern);
SINGLE_ANIMATION(Sunflora);
SINGLE_ANIMATION(Yanma);
SINGLE_ANIMATION(Wooper);
SINGLE_ANIMATION(Quagsire);
SINGLE_ANIMATION(Espeon);
SINGLE_ANIMATION(Umbreon);
SINGLE_ANIMATION(Murkrow);
SINGLE_ANIMATION(Slowking);
SINGLE_ANIMATION(Misdreavus);
SINGLE_ANIMATION(Unown);
DOUBLE_ANIMATION(Wobbuffet);
DOUBLE_ANIMATION(Girafarig);
SINGLE_ANIMATION(Pineco);
SINGLE_ANIMATION(Forretress);
SINGLE_ANIMATION(Dunsparce);
SINGLE_ANIMATION(Gligar);
SINGLE_ANIMATION(Steelix);
SINGLE_ANIMATION(Snubbull);
SINGLE_ANIMATION(Granbull);
SINGLE_ANIMATION(Qwilfish);
SINGLE_ANIMATION(Scizor);
SINGLE_ANIMATION(Shuckle);
DOUBLE_ANIMATION(Heracross);
SINGLE_ANIMATION(Sneasel);
SINGLE_ANIMATION(Teddiursa);
SINGLE_ANIMATION(Ursaring);
DOUBLE_ANIMATION(Slugma);
DOUBLE_ANIMATION(Magcargo);
SINGLE_ANIMATION(Swinub);
SINGLE_ANIMATION(Piloswine);
DOUBLE_ANIMATION(Corsola);
SINGLE_ANIMATION(Remoraid);
SINGLE_ANIMATION(Octillery);
SINGLE_ANIMATION(Delibird);
SINGLE_ANIMATION(Mantine);
DOUBLE_ANIMATION(Skarmory);
SINGLE_ANIMATION(Houndour);
SINGLE_ANIMATION(Houndoom);
DOUBLE_ANIMATION(Kingdra);
DOUBLE_ANIMATION(Phanpy);
DOUBLE_ANIMATION(Donphan);
SINGLE_ANIMATION(Porygon2);
SINGLE_ANIMATION(Stantler);
SINGLE_ANIMATION(Smeargle);
SINGLE_ANIMATION(Tyrogue);
SINGLE_ANIMATION(Hitmontop);
SINGLE_ANIMATION(Smoochum);
SINGLE_ANIMATION(Elekid);
SINGLE_ANIMATION(Magby);
SINGLE_ANIMATION(Miltank);
SINGLE_ANIMATION(Blissey);
SINGLE_ANIMATION(Raikou);
SINGLE_ANIMATION(Entei);
SINGLE_ANIMATION(Suicune);
SINGLE_ANIMATION(Larvitar);
SINGLE_ANIMATION(Pupitar);
SINGLE_ANIMATION(Tyranitar);
SINGLE_ANIMATION(Lugia);
SINGLE_ANIMATION(HoOh);
SINGLE_ANIMATION(Celebi);
SINGLE_ANIMATION(OldUnownB);
SINGLE_ANIMATION(Treecko);
SINGLE_ANIMATION(Grovyle);
SINGLE_ANIMATION(Sceptile);
SINGLE_ANIMATION(Torchic);
SINGLE_ANIMATION(Combusken);
static const union AnimCmd *const sAnims_Blaziken[] ={
    sAnim_GeneralFrame0,
    sAnim_Blaziken_1,
    sAnim_Blaziken_2,
    sAnim_Blaziken_3,
    sAnim_Blaziken_4,
};
SINGLE_ANIMATION(Mudkip);
SINGLE_ANIMATION(Marshtomp);
SINGLE_ANIMATION(Swampert);
SINGLE_ANIMATION(Poochyena);
SINGLE_ANIMATION(Mightyena);
SINGLE_ANIMATION(Zigzagoon);
SINGLE_ANIMATION(Linoone);
SINGLE_ANIMATION(Wurmple);
DOUBLE_ANIMATION(Silcoon);
DOUBLE_ANIMATION(Beautifly);
DOUBLE_ANIMATION(Cascoon);
DOUBLE_ANIMATION(Dustox);
SINGLE_ANIMATION(Lotad);
SINGLE_ANIMATION(Lombre);
SINGLE_ANIMATION(Ludicolo);
SINGLE_ANIMATION(Seedot);
SINGLE_ANIMATION(Nuzleaf);
SINGLE_ANIMATION(Shiftry);
SINGLE_ANIMATION(Nincada);
SINGLE_ANIMATION(Ninjask);
SINGLE_ANIMATION(Shedinja);
SINGLE_ANIMATION(Taillow);
SINGLE_ANIMATION(Swellow);
SINGLE_ANIMATION(Shroomish);
SINGLE_ANIMATION(Breloom);
static const union AnimCmd *const sAnims_Spinda[] ={
    sAnim_GeneralFrame0,
};
SINGLE_ANIMATION(Wingull);
SINGLE_ANIMATION(Pelipper);
DOUBLE_ANIMATION(Surskit);
DOUBLE_ANIMATION(Masquerain);
SINGLE_ANIMATION(Wailmer);
SINGLE_ANIMATION(Wailord);
SINGLE_ANIMATION(Skitty);
SINGLE_ANIMATION(Delcatty);
SINGLE_ANIMATION(Kecleon);
SINGLE_ANIMATION(Baltoy);
SINGLE_ANIMATION(Claydol);
SINGLE_ANIMATION(Nosepass);
SINGLE_ANIMATION(Torkoal);
SINGLE_ANIMATION(Sableye);
SINGLE_ANIMATION(Barboach);
SINGLE_ANIMATION(Whiscash);
SINGLE_ANIMATION(Luvdisc);
SINGLE_ANIMATION(Corphish);
SINGLE_ANIMATION(Crawdaunt);
SINGLE_ANIMATION(Feebas);
SINGLE_ANIMATION(Milotic);
SINGLE_ANIMATION(Carvanha);
SINGLE_ANIMATION(Sharpedo);
SINGLE_ANIMATION(Trapinch);
SINGLE_ANIMATION(Vibrava);
SINGLE_ANIMATION(Flygon);
SINGLE_ANIMATION(Makuhita);
SINGLE_ANIMATION(Hariyama);
SINGLE_ANIMATION(Electrike);
SINGLE_ANIMATION(Manectric);
SINGLE_ANIMATION(Numel);
SINGLE_ANIMATION(Camerupt);
SINGLE_ANIMATION(Spheal);
SINGLE_ANIMATION(Sealeo);
SINGLE_ANIMATION(Walrein);
SINGLE_ANIMATION(Cacnea);
SINGLE_ANIMATION(Cacturne);
SINGLE_ANIMATION(Snorunt);
SINGLE_ANIMATION(Glalie);
DOUBLE_ANIMATION(Lunatone);
DOUBLE_ANIMATION(Solrock);
SINGLE_ANIMATION(Azurill);
SINGLE_ANIMATION(Spoink);
SINGLE_ANIMATION(Grumpig);
SINGLE_ANIMATION(Plusle);
SINGLE_ANIMATION(Minun);
SINGLE_ANIMATION(Mawile);
SINGLE_ANIMATION(Meditite);
SINGLE_ANIMATION(Medicham);
DOUBLE_ANIMATION(Swablu);
DOUBLE_ANIMATION(Altaria);
SINGLE_ANIMATION(Wynaut);
SINGLE_ANIMATION(Duskull);
SINGLE_ANIMATION(Dusclops);
SINGLE_ANIMATION(Roselia);
SINGLE_ANIMATION(Slakoth);
SINGLE_ANIMATION(Vigoroth);
SINGLE_ANIMATION(Slaking);
SINGLE_ANIMATION(Gulpin);
SINGLE_ANIMATION(Swalot);
SINGLE_ANIMATION(Tropius);
SINGLE_ANIMATION(Whismur);
SINGLE_ANIMATION(Loudred);
SINGLE_ANIMATION(Exploud);
SINGLE_ANIMATION(Clamperl);
SINGLE_ANIMATION(Huntail);
SINGLE_ANIMATION(Gorebyss);
SINGLE_ANIMATION(Absol);
SINGLE_ANIMATION(Shuppet);
SINGLE_ANIMATION(Banette);
SINGLE_ANIMATION(Seviper);
SINGLE_ANIMATION(Zangoose);
SINGLE_ANIMATION(Relicanth);
SINGLE_ANIMATION(Aron);
SINGLE_ANIMATION(Lairon);
SINGLE_ANIMATION(Aggron);
static const union AnimCmd *const sAnims_Castform[] ={
    sAnim_Castform_0,
    sAnim_Castform_1,
    sAnim_Castform_2,
    sAnim_Castform_3,
};
SINGLE_ANIMATION(Volbeat);
SINGLE_ANIMATION(Illumise);
SINGLE_ANIMATION(Lileep);
SINGLE_ANIMATION(Cradily);
SINGLE_ANIMATION(Anorith);
SINGLE_ANIMATION(Armaldo);
SINGLE_ANIMATION(Ralts);
SINGLE_ANIMATION(Kirlia);
SINGLE_ANIMATION(Gardevoir);
SINGLE_ANIMATION(Bagon);
SINGLE_ANIMATION(Shelgon);
SINGLE_ANIMATION(Salamence);
SINGLE_ANIMATION(Beldum);
SINGLE_ANIMATION(Metang);
SINGLE_ANIMATION(Metagross);
DOUBLE_ANIMATION(Regirock);
SINGLE_ANIMATION(Regice);
DOUBLE_ANIMATION(Registeel);
DOUBLE_ANIMATION(Kyogre);
DOUBLE_ANIMATION(Groudon);
DOUBLE_ANIMATION(Rayquaza);
DOUBLE_ANIMATION(Latias);
DOUBLE_ANIMATION(Latios);
DOUBLE_ANIMATION(Jirachi);
DOUBLE_ANIMATION(Deoxys);
SINGLE_ANIMATION(Chimecho);
SINGLE_ANIMATION(Egg);
SINGLE_ANIMATION(UnownB);
SINGLE_ANIMATION(UnownC);
SINGLE_ANIMATION(UnownD);
SINGLE_ANIMATION(UnownE);
SINGLE_ANIMATION(UnownF);
SINGLE_ANIMATION(UnownG);
SINGLE_ANIMATION(UnownH);
SINGLE_ANIMATION(UnownI);
SINGLE_ANIMATION(UnownJ);
SINGLE_ANIMATION(UnownK);
SINGLE_ANIMATION(UnownL);
SINGLE_ANIMATION(UnownM);
SINGLE_ANIMATION(UnownN);
SINGLE_ANIMATION(UnownO);
SINGLE_ANIMATION(UnownP);
SINGLE_ANIMATION(UnownQ);
SINGLE_ANIMATION(UnownR);
SINGLE_ANIMATION(UnownS);
SINGLE_ANIMATION(UnownT);
SINGLE_ANIMATION(UnownU);
SINGLE_ANIMATION(UnownV);
SINGLE_ANIMATION(UnownW);
SINGLE_ANIMATION(UnownX);
SINGLE_ANIMATION(UnownY);
SINGLE_ANIMATION(UnownZ);
SINGLE_ANIMATION(UnownEMark);
SINGLE_ANIMATION(UnownQMark);

#define ANIM_CMD(name,anims)       [SPECIES_##name] = sAnims_##anims

const union AnimCmd *const *const gMonFrontAnimsPtrTable[] =
{
    ANIM_CMD(NONE, None),
    ANIM_CMD(BULBASAUR, Bulbasaur),
    ANIM_CMD(IVYSAUR, Ivysaur),
    ANIM_CMD(VENUSAUR, Venusaur),
    ANIM_CMD(CHARMANDER, Charmander),
    ANIM_CMD(CHARMELEON, Charmeleon),
    ANIM_CMD(CHARIZARD, Charizard),
    ANIM_CMD(SQUIRTLE, Squirtle),
    ANIM_CMD(WARTORTLE, Wartortle),
    ANIM_CMD(BLASTOISE, Blastoise),
    ANIM_CMD(CATERPIE, Caterpie),
    ANIM_CMD(METAPOD, Metapod),
    ANIM_CMD(BUTTERFREE, Butterfree),
    ANIM_CMD(WEEDLE, Weedle),
    ANIM_CMD(KAKUNA, Kakuna),
    ANIM_CMD(BEEDRILL, Beedrill),
    ANIM_CMD(PIDGEY, Pidgey),
    ANIM_CMD(PIDGEOTTO, Pidgeotto),
    ANIM_CMD(PIDGEOT, Pidgeot),
    ANIM_CMD(RATTATA, Rattata),
    ANIM_CMD(RATICATE, Raticate),
    ANIM_CMD(SPEAROW, Spearow),
    ANIM_CMD(FEAROW, Fearow),
    ANIM_CMD(EKANS, Ekans),
    ANIM_CMD(ARBOK, Arbok),
    ANIM_CMD(PIKACHU, Pikachu),
    ANIM_CMD(RAICHU, Raichu),
    ANIM_CMD(SANDSHREW, Sandshrew),
    ANIM_CMD(SANDSLASH, Sandslash),
    ANIM_CMD(NIDORAN_F, NidoranF),
    ANIM_CMD(NIDORINA, Nidorina),
    ANIM_CMD(NIDOQUEEN, Nidoqueen),
    ANIM_CMD(NIDORAN_M, NidoranM),
    ANIM_CMD(NIDORINO, Nidorino),
    ANIM_CMD(NIDOKING, Nidoking),
    ANIM_CMD(CLEFAIRY, Clefairy),
    ANIM_CMD(CLEFABLE, Clefable),
    ANIM_CMD(VULPIX, Vulpix),
    ANIM_CMD(NINETALES, Ninetales),
    ANIM_CMD(JIGGLYPUFF, Jigglypuff),
    ANIM_CMD(WIGGLYTUFF, Wigglytuff),
    ANIM_CMD(ZUBAT, Zubat),
    ANIM_CMD(GOLBAT, Golbat),
    ANIM_CMD(ODDISH, Oddish),
    ANIM_CMD(GLOOM, Gloom),
    ANIM_CMD(VILEPLUME, Vileplume),
    ANIM_CMD(PARAS, Paras),
    ANIM_CMD(PARASECT, Parasect),
    ANIM_CMD(VENONAT, Venonat),
    ANIM_CMD(VENOMOTH, Venomoth),
    ANIM_CMD(DIGLETT, Diglett),
    ANIM_CMD(DUGTRIO, Dugtrio),
    ANIM_CMD(MEOWTH, Meowth),
    ANIM_CMD(PERSIAN, Persian),
    ANIM_CMD(PSYDUCK, Psyduck),
    ANIM_CMD(GOLDUCK, Golduck),
    ANIM_CMD(MANKEY, Mankey),
    ANIM_CMD(PRIMEAPE, Primeape),
    ANIM_CMD(GROWLITHE, Growlithe),
    ANIM_CMD(ARCANINE, Arcanine),
    ANIM_CMD(POLIWAG, Poliwag),
    ANIM_CMD(POLIWHIRL, Poliwhirl),
    ANIM_CMD(POLIWRATH, Poliwrath),
    ANIM_CMD(ABRA, Abra),
    ANIM_CMD(KADABRA, Kadabra),
    ANIM_CMD(ALAKAZAM, Alakazam),
    ANIM_CMD(MACHOP, Machop),
    ANIM_CMD(MACHOKE, Machoke),
    ANIM_CMD(MACHAMP, Machamp),
    ANIM_CMD(BELLSPROUT, Bellsprout),
    ANIM_CMD(WEEPINBELL, Weepinbell),
    ANIM_CMD(VICTREEBEL, Victreebel),
    ANIM_CMD(TENTACOOL, Tentacool),
    ANIM_CMD(TENTACRUEL, Tentacruel),
    ANIM_CMD(GEODUDE, Geodude),
    ANIM_CMD(GRAVELER, Graveler),
    ANIM_CMD(GOLEM, Golem),
    ANIM_CMD(PONYTA, Ponyta),
    ANIM_CMD(RAPIDASH, Rapidash),
    ANIM_CMD(SLOWPOKE, Slowpoke),
    ANIM_CMD(SLOWBRO, Slowbro),
    ANIM_CMD(MAGNEMITE, Magnemite),
    ANIM_CMD(MAGNETON, Magneton),
    ANIM_CMD(FARFETCHD, Farfetchd),
    ANIM_CMD(DODUO, Doduo),
    ANIM_CMD(DODRIO, Dodrio),
    ANIM_CMD(SEEL, Seel),
    ANIM_CMD(DEWGONG, Dewgong),
    ANIM_CMD(GRIMER, Grimer),
    ANIM_CMD(MUK, Muk),
    ANIM_CMD(SHELLDER, Shellder),
    ANIM_CMD(CLOYSTER, Cloyster),
    ANIM_CMD(GASTLY, Gastly),
    ANIM_CMD(HAUNTER, Haunter),
    ANIM_CMD(GENGAR, Gengar),
    ANIM_CMD(ONIX, Onix),
    ANIM_CMD(DROWZEE, Drowzee),
    ANIM_CMD(HYPNO, Hypno),
    ANIM_CMD(KRABBY, Krabby),
    ANIM_CMD(KINGLER, Kingler),
    ANIM_CMD(VOLTORB, Voltorb),
    ANIM_CMD(ELECTRODE, Electrode),
    ANIM_CMD(EXEGGCUTE, Exeggcute),
    ANIM_CMD(EXEGGUTOR, Exeggutor),
    ANIM_CMD(CUBONE, Cubone),
    ANIM_CMD(MAROWAK, Marowak),
    ANIM_CMD(HITMONLEE, Hitmonlee),
    ANIM_CMD(HITMONCHAN, Hitmonchan),
    ANIM_CMD(LICKITUNG, Lickitung),
    ANIM_CMD(KOFFING, Koffing),
    ANIM_CMD(WEEZING, Weezing),
    ANIM_CMD(RHYHORN, Rhyhorn),
    ANIM_CMD(RHYDON, Rhydon),
    ANIM_CMD(CHANSEY, Chansey),
    ANIM_CMD(TANGELA, Tangela),
    ANIM_CMD(KANGASKHAN, Kangaskhan),
    ANIM_CMD(HORSEA, Horsea),
    ANIM_CMD(SEADRA, Seadra),
    ANIM_CMD(GOLDEEN, Goldeen),
    ANIM_CMD(SEAKING, Seaking),
    ANIM_CMD(STARYU, Staryu),
    ANIM_CMD(STARMIE, Starmie),
    ANIM_CMD(MR_MIME, MrMime),
    ANIM_CMD(SCYTHER, Scyther),
    ANIM_CMD(JYNX, Jynx),
    ANIM_CMD(ELECTABUZZ, Electabuzz),
    ANIM_CMD(MAGMAR, Magmar),
    ANIM_CMD(PINSIR, Pinsir),
    ANIM_CMD(TAUROS, Tauros),
    ANIM_CMD(MAGIKARP, Magikarp),
    ANIM_CMD(GYARADOS, Gyarados),
    ANIM_CMD(LAPRAS, Lapras),
    ANIM_CMD(DITTO, Ditto),
    ANIM_CMD(EEVEE, Eevee),
    ANIM_CMD(VAPOREON, Vaporeon),
    ANIM_CMD(JOLTEON, Jolteon),
    ANIM_CMD(FLAREON, Flareon),
    ANIM_CMD(PORYGON, Porygon),
    ANIM_CMD(OMANYTE, Omanyte),
    ANIM_CMD(OMASTAR, Omastar),
    ANIM_CMD(KABUTO, Kabuto),
    ANIM_CMD(KABUTOPS, Kabutops),
    ANIM_CMD(AERODACTYL, Aerodactyl),
    ANIM_CMD(SNORLAX, Snorlax),
    ANIM_CMD(ARTICUNO, Articuno),
    ANIM_CMD(ZAPDOS, Zapdos),
    ANIM_CMD(MOLTRES, Moltres),
    ANIM_CMD(DRATINI, Dratini),
    ANIM_CMD(DRAGONAIR, Dragonair),
    ANIM_CMD(DRAGONITE, Dragonite),
    ANIM_CMD(MEWTWO, Mewtwo),
    ANIM_CMD(MEW, Mew),
    ANIM_CMD(CHIKORITA, Chikorita),
    ANIM_CMD(BAYLEEF, Bayleef),
    ANIM_CMD(MEGANIUM, Meganium),
    ANIM_CMD(CYNDAQUIL, Cyndaquil),
    ANIM_CMD(QUILAVA, Quilava),
    ANIM_CMD(TYPHLOSION, Typhlosion),
    ANIM_CMD(TOTODILE, Totodile),
    ANIM_CMD(CROCONAW, Croconaw),
    ANIM_CMD(FERALIGATR, Feraligatr),
    ANIM_CMD(SENTRET, Sentret),
    ANIM_CMD(FURRET, Furret),
    ANIM_CMD(HOOTHOOT, Hoothoot),
    ANIM_CMD(NOCTOWL, Noctowl),
    ANIM_CMD(LEDYBA, Ledyba),
    ANIM_CMD(LEDIAN, Ledian),
    ANIM_CMD(SPINARAK, Spinarak),
    ANIM_CMD(ARIADOS, Ariados),
    ANIM_CMD(CROBAT, Crobat),
    ANIM_CMD(CHINCHOU, Chinchou),
    ANIM_CMD(LANTURN, Lanturn),
    ANIM_CMD(PICHU, Pichu),
    ANIM_CMD(CLEFFA, Cleffa),
    ANIM_CMD(IGGLYBUFF, Igglybuff),
    ANIM_CMD(TOGEPI, Togepi),
    ANIM_CMD(TOGETIC, Togetic),
    ANIM_CMD(NATU, Natu),
    ANIM_CMD(XATU, Xatu),
    ANIM_CMD(MAREEP, Mareep),
    ANIM_CMD(FLAAFFY, Flaaffy),
    ANIM_CMD(AMPHAROS, Ampharos),
    ANIM_CMD(BELLOSSOM, Bellossom),
    ANIM_CMD(MARILL, Marill),
    ANIM_CMD(AZUMARILL, Azumarill),
    ANIM_CMD(SUDOWOODO, Sudowoodo),
    ANIM_CMD(POLITOED, Politoed),
    ANIM_CMD(HOPPIP, Hoppip),
    ANIM_CMD(SKIPLOOM, Skiploom),
    ANIM_CMD(JUMPLUFF, Jumpluff),
    ANIM_CMD(AIPOM, Aipom),
    ANIM_CMD(SUNKERN, Sunkern),
    ANIM_CMD(SUNFLORA, Sunflora),
    ANIM_CMD(YANMA, Yanma),
    ANIM_CMD(WOOPER, Wooper),
    ANIM_CMD(QUAGSIRE, Quagsire),
    ANIM_CMD(ESPEON, Espeon),
    ANIM_CMD(UMBREON, Umbreon),
    ANIM_CMD(MURKROW, Murkrow),
    ANIM_CMD(SLOWKING, Slowking),
    ANIM_CMD(MISDREAVUS, Misdreavus),
    ANIM_CMD(UNOWN, Unown),
    ANIM_CMD(WOBBUFFET, Wobbuffet),
    ANIM_CMD(GIRAFARIG, Girafarig),
    ANIM_CMD(PINECO, Pineco),
    ANIM_CMD(FORRETRESS, Forretress),
    ANIM_CMD(DUNSPARCE, Dunsparce),
    ANIM_CMD(GLIGAR, Gligar),
    ANIM_CMD(STEELIX, Steelix),
    ANIM_CMD(SNUBBULL, Snubbull),
    ANIM_CMD(GRANBULL, Granbull),
    ANIM_CMD(QWILFISH, Qwilfish),
    ANIM_CMD(SCIZOR, Scizor),
    ANIM_CMD(SHUCKLE, Shuckle),
    ANIM_CMD(HERACROSS, Heracross),
    ANIM_CMD(SNEASEL, Sneasel),
    ANIM_CMD(TEDDIURSA, Teddiursa),
    ANIM_CMD(URSARING, Ursaring),
    ANIM_CMD(SLUGMA, Slugma),
    ANIM_CMD(MAGCARGO, Magcargo),
    ANIM_CMD(SWINUB, Swinub),
    ANIM_CMD(PILOSWINE, Piloswine),
    ANIM_CMD(CORSOLA, Corsola),
    ANIM_CMD(REMORAID, Remoraid),
    ANIM_CMD(OCTILLERY, Octillery),
    ANIM_CMD(DELIBIRD, Delibird),
    ANIM_CMD(MANTINE, Mantine),
    ANIM_CMD(SKARMORY, Skarmory),
    ANIM_CMD(HOUNDOUR, Houndour),
    ANIM_CMD(HOUNDOOM, Houndoom),
    ANIM_CMD(KINGDRA, Kingdra),
    ANIM_CMD(PHANPY, Phanpy),
    ANIM_CMD(DONPHAN, Donphan),
    ANIM_CMD(PORYGON2, Porygon2),
    ANIM_CMD(STANTLER, Stantler),
    ANIM_CMD(SMEARGLE, Smeargle),
    ANIM_CMD(TYROGUE, Tyrogue),
    ANIM_CMD(HITMONTOP, Hitmontop),
    ANIM_CMD(SMOOCHUM, Smoochum),
    ANIM_CMD(ELEKID, Elekid),
    ANIM_CMD(MAGBY, Magby),
    ANIM_CMD(MILTANK, Miltank),
    ANIM_CMD(BLISSEY, Blissey),
    ANIM_CMD(RAIKOU, Raikou),
    ANIM_CMD(ENTEI, Entei),
    ANIM_CMD(SUICUNE, Suicune),
    ANIM_CMD(LARVITAR, Larvitar),
    ANIM_CMD(PUPITAR, Pupitar),
    ANIM_CMD(TYRANITAR, Tyranitar),
    ANIM_CMD(LUGIA, Lugia),
    ANIM_CMD(HO_OH, HoOh),
    ANIM_CMD(CELEBI, Celebi),
    ANIM_CMD(OLD_UNOWN_B, OldUnownB),
    ANIM_CMD(OLD_UNOWN_C, OldUnownB),
    ANIM_CMD(OLD_UNOWN_D, OldUnownB),
    ANIM_CMD(OLD_UNOWN_E, OldUnownB),
    ANIM_CMD(OLD_UNOWN_F, OldUnownB),
    ANIM_CMD(OLD_UNOWN_G, OldUnownB),
    ANIM_CMD(OLD_UNOWN_H, OldUnownB),
    ANIM_CMD(OLD_UNOWN_I, OldUnownB),
    ANIM_CMD(OLD_UNOWN_J, OldUnownB),
    ANIM_CMD(OLD_UNOWN_K, OldUnownB),
    ANIM_CMD(OLD_UNOWN_L, OldUnownB),
    ANIM_CMD(OLD_UNOWN_M, OldUnownB),
    ANIM_CMD(OLD_UNOWN_N, OldUnownB),
    ANIM_CMD(OLD_UNOWN_O, OldUnownB),
    ANIM_CMD(OLD_UNOWN_P, OldUnownB),
    ANIM_CMD(OLD_UNOWN_Q, OldUnownB),
    ANIM_CMD(OLD_UNOWN_R, OldUnownB),
    ANIM_CMD(OLD_UNOWN_S, OldUnownB),
    ANIM_CMD(OLD_UNOWN_T, OldUnownB),
    ANIM_CMD(OLD_UNOWN_U, OldUnownB),
    ANIM_CMD(OLD_UNOWN_V, OldUnownB),
    ANIM_CMD(OLD_UNOWN_W, OldUnownB),
    ANIM_CMD(OLD_UNOWN_X, OldUnownB),
    ANIM_CMD(OLD_UNOWN_Y, OldUnownB),
    ANIM_CMD(OLD_UNOWN_Z, OldUnownB),
    ANIM_CMD(TREECKO, Treecko),
    ANIM_CMD(GROVYLE, Grovyle),
    ANIM_CMD(SCEPTILE, Sceptile),
    ANIM_CMD(TORCHIC, Torchic),
    ANIM_CMD(COMBUSKEN, Combusken),
    ANIM_CMD(BLAZIKEN, Blaziken),
    ANIM_CMD(MUDKIP, Mudkip),
    ANIM_CMD(MARSHTOMP, Marshtomp),
    ANIM_CMD(SWAMPERT, Swampert),
    ANIM_CMD(POOCHYENA, Poochyena),
    ANIM_CMD(MIGHTYENA, Mightyena),
    ANIM_CMD(ZIGZAGOON, Zigzagoon),
    ANIM_CMD(LINOONE, Linoone),
    ANIM_CMD(WURMPLE, Wurmple),
    ANIM_CMD(SILCOON, Silcoon),
    ANIM_CMD(BEAUTIFLY, Beautifly),
    ANIM_CMD(CASCOON, Cascoon),
    ANIM_CMD(DUSTOX, Dustox),
    ANIM_CMD(LOTAD, Lotad),
    ANIM_CMD(LOMBRE, Lombre),
    ANIM_CMD(LUDICOLO, Ludicolo),
    ANIM_CMD(SEEDOT, Seedot),
    ANIM_CMD(NUZLEAF, Nuzleaf),
    ANIM_CMD(SHIFTRY, Shiftry),
    ANIM_CMD(NINCADA, Nincada),
    ANIM_CMD(NINJASK, Ninjask),
    ANIM_CMD(SHEDINJA, Shedinja),
    ANIM_CMD(TAILLOW, Taillow),
    ANIM_CMD(SWELLOW, Swellow),
    ANIM_CMD(SHROOMISH, Shroomish),
    ANIM_CMD(BRELOOM, Breloom),
    ANIM_CMD(SPINDA, Spinda),
    ANIM_CMD(WINGULL, Wingull),
    ANIM_CMD(PELIPPER, Pelipper),
    ANIM_CMD(SURSKIT, Surskit),
    ANIM_CMD(MASQUERAIN, Masquerain),
    ANIM_CMD(WAILMER, Wailmer),
    ANIM_CMD(WAILORD, Wailord),
    ANIM_CMD(SKITTY, Skitty),
    ANIM_CMD(DELCATTY, Delcatty),
    ANIM_CMD(KECLEON, Kecleon),
    ANIM_CMD(BALTOY, Baltoy),
    ANIM_CMD(CLAYDOL, Claydol),
    ANIM_CMD(NOSEPASS, Nosepass),
    ANIM_CMD(TORKOAL, Torkoal),
    ANIM_CMD(SABLEYE, Sableye),
    ANIM_CMD(BARBOACH, Barboach),
    ANIM_CMD(WHISCASH, Whiscash),
    ANIM_CMD(LUVDISC, Luvdisc),
    ANIM_CMD(CORPHISH, Corphish),
    ANIM_CMD(CRAWDAUNT, Crawdaunt),
    ANIM_CMD(FEEBAS, Feebas),
    ANIM_CMD(MILOTIC, Milotic),
    ANIM_CMD(CARVANHA, Carvanha),
    ANIM_CMD(SHARPEDO, Sharpedo),
    ANIM_CMD(TRAPINCH, Trapinch),
    ANIM_CMD(VIBRAVA, Vibrava),
    ANIM_CMD(FLYGON, Flygon),
    ANIM_CMD(MAKUHITA, Makuhita),
    ANIM_CMD(HARIYAMA, Hariyama),
    ANIM_CMD(ELECTRIKE, Electrike),
    ANIM_CMD(MANECTRIC, Manectric),
    ANIM_CMD(NUMEL, Numel),
    ANIM_CMD(CAMERUPT, Camerupt),
    ANIM_CMD(SPHEAL, Spheal),
    ANIM_CMD(SEALEO, Sealeo),
    ANIM_CMD(WALREIN, Walrein),
    ANIM_CMD(CACNEA, Cacnea),
    ANIM_CMD(CACTURNE, Cacturne),
    ANIM_CMD(SNORUNT, Snorunt),
    ANIM_CMD(GLALIE, Glalie),
    ANIM_CMD(LUNATONE, Lunatone),
    ANIM_CMD(SOLROCK, Solrock),
    ANIM_CMD(AZURILL, Azurill),
    ANIM_CMD(SPOINK, Spoink),
    ANIM_CMD(GRUMPIG, Grumpig),
    ANIM_CMD(PLUSLE, Plusle),
    ANIM_CMD(MINUN, Minun),
    ANIM_CMD(MAWILE, Mawile),
    ANIM_CMD(MEDITITE, Meditite),
    ANIM_CMD(MEDICHAM, Medicham),
    ANIM_CMD(SWABLU, Swablu),
    ANIM_CMD(ALTARIA, Altaria),
    ANIM_CMD(WYNAUT, Wynaut),
    ANIM_CMD(DUSKULL, Duskull),
    ANIM_CMD(DUSCLOPS, Dusclops),
    ANIM_CMD(ROSELIA, Roselia),
    ANIM_CMD(SLAKOTH, Slakoth),
    ANIM_CMD(VIGOROTH, Vigoroth),
    ANIM_CMD(SLAKING, Slaking),
    ANIM_CMD(GULPIN, Gulpin),
    ANIM_CMD(SWALOT, Swalot),
    ANIM_CMD(TROPIUS, Tropius),
    ANIM_CMD(WHISMUR, Whismur),
    ANIM_CMD(LOUDRED, Loudred),
    ANIM_CMD(EXPLOUD, Exploud),
    ANIM_CMD(CLAMPERL, Clamperl),
    ANIM_CMD(HUNTAIL, Huntail),
    ANIM_CMD(GOREBYSS, Gorebyss),
    ANIM_CMD(ABSOL, Absol),
    ANIM_CMD(SHUPPET, Shuppet),
    ANIM_CMD(BANETTE, Banette),
    ANIM_CMD(SEVIPER, Seviper),
    ANIM_CMD(ZANGOOSE, Zangoose),
    ANIM_CMD(RELICANTH, Relicanth),
    ANIM_CMD(ARON, Aron),
    ANIM_CMD(LAIRON, Lairon),
    ANIM_CMD(AGGRON, Aggron),
    ANIM_CMD(CASTFORM, Castform),
    ANIM_CMD(VOLBEAT, Volbeat),
    ANIM_CMD(ILLUMISE, Illumise),
    ANIM_CMD(LILEEP, Lileep),
    ANIM_CMD(CRADILY, Cradily),
    ANIM_CMD(ANORITH, Anorith),
    ANIM_CMD(ARMALDO, Armaldo),
    ANIM_CMD(RALTS, Ralts),
    ANIM_CMD(KIRLIA, Kirlia),
    ANIM_CMD(GARDEVOIR, Gardevoir),
    ANIM_CMD(BAGON, Bagon),
    ANIM_CMD(SHELGON, Shelgon),
    ANIM_CMD(SALAMENCE, Salamence),
    ANIM_CMD(BELDUM, Beldum),
    ANIM_CMD(METANG, Metang),
    ANIM_CMD(METAGROSS, Metagross),
    ANIM_CMD(REGIROCK, Regirock),
    ANIM_CMD(REGICE, Regice),
    ANIM_CMD(REGISTEEL, Registeel),
    ANIM_CMD(KYOGRE, Kyogre),
    ANIM_CMD(GROUDON, Groudon),
    ANIM_CMD(RAYQUAZA, Rayquaza),
    ANIM_CMD(LATIAS, Latias),
    ANIM_CMD(LATIOS, Latios),
    ANIM_CMD(JIRACHI, Jirachi),
    ANIM_CMD(DEOXYS, Deoxys),
    ANIM_CMD(CHIMECHO, Chimecho),
    ANIM_CMD(EGG, Egg),
    ANIM_CMD(UNOWN_B, UnownB),
    ANIM_CMD(UNOWN_C, UnownC),
    ANIM_CMD(UNOWN_D, UnownD),
    ANIM_CMD(UNOWN_E, UnownE),
    ANIM_CMD(UNOWN_F, UnownF),
    ANIM_CMD(UNOWN_G, UnownG),
    ANIM_CMD(UNOWN_H, UnownH),
    ANIM_CMD(UNOWN_I, UnownI),
    ANIM_CMD(UNOWN_J, UnownJ),
    ANIM_CMD(UNOWN_K, UnownK),
    ANIM_CMD(UNOWN_L, UnownL),
    ANIM_CMD(UNOWN_M, UnownM),
    ANIM_CMD(UNOWN_N, UnownN),
    ANIM_CMD(UNOWN_O, UnownO),
    ANIM_CMD(UNOWN_P, UnownP),
    ANIM_CMD(UNOWN_Q, UnownQ),
    ANIM_CMD(UNOWN_R, UnownR),
    ANIM_CMD(UNOWN_S, UnownS),
    ANIM_CMD(UNOWN_T, UnownT),
    ANIM_CMD(UNOWN_U, UnownU),
    ANIM_CMD(UNOWN_V, UnownV),
    ANIM_CMD(UNOWN_W, UnownW),
    ANIM_CMD(UNOWN_X, UnownX),
    ANIM_CMD(UNOWN_Y, UnownY),
    ANIM_CMD(UNOWN_Z, UnownZ),
    ANIM_CMD(UNOWN_EMARK, UnownEMark),
    ANIM_CMD(UNOWN_QMARK, UnownQMark),
};

#undef ANIM_CMD

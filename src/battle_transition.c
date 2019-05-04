#include "global.h"
#include "battle.h"
#include "battle_transition.h"
#include "bg.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "alloc.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "unk_transition.h"
#include "util.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

struct TransitionData
{
    vu8 VBlank_DMA;
    u16 WININ;
    u16 WINOUT;
    u16 WIN0H;
    u16 WIN0V;
    u16 field_A; // unused
    u16 field_C; // unused
    u16 BLDCNT;
    u16 BLDALPHA;
    u16 BLDY;
    s16 field_14;
    s16 field_16;
    s16 BG0HOFS_1;
    s16 BG0HOFS_2;
    s16 BG0VOFS; // used but not set
    s16 field_1E; // unused
    s16 field_20;
    s16 field_22; // unused
    s16 data[11];
};

struct StructRectangularSpiral
{
    u8 field_0;
    s16 field_2;
    u8 field_4;
    s16 field_6;
    u8 field_8;
};

typedef bool8 (*TransitionStateFunc)(struct Task *task);
typedef bool8 (*TransitionSpriteCallback)(struct Sprite *sprite);

// this file's functions
static void LaunchBattleTransitionTask(u8 transitionId);
static void Task_BattleTransitionMain(u8 taskId);
static void Phase1Task_TransitionAll(u8 taskId);
static void Phase2Task_Blur(u8 taskId);
static void Phase2Task_Swirl(u8 taskId);
static void Phase2Task_Shuffle(u8 taskId);
static void Phase2Task_BigPokeball(u8 taskId);
static void Phase2Task_PokeballsTrail(u8 taskId);
static void Phase2Task_Clockwise_BlackFade(u8 taskId);
static void Phase2Task_Ripple(u8 taskId);
static void Phase2Task_Wave(u8 taskId);
static void Phase2Task_Slice(u8 taskId);
static void Phase2Task_WhiteFade(u8 taskId);
static void Phase2Task_GridSquares(u8 taskId);
static void Phase2Task_Shards(u8 taskId);
static void Phase2Task_Sidney(u8 taskId);
static void Phase2Task_Phoebe(u8 taskId);
static void Phase2Task_Glacia(u8 taskId);
static void Phase2Task_Drake(u8 taskId);
static void Phase2Task_Champion(u8 taskId);
static void Phase2Task_Aqua(u8 taskId);
static void Phase2Task_Magma(u8 taskId);
static void Phase2Task_Regice(u8 taskId);
static void Phase2Task_Registeel(u8 taskId);
static void Phase2Task_Regirock(u8 taskId);
static void Phase2Task_Kyogre(u8 taskId);
static void Phase2Task_Groudon(u8 taskId);
static void Phase2Task_Rayquaza(u8 taskId);
static void Phase2Task_ShredSplit(u8 taskId);
static void Phase2Task_Blackhole1(u8 taskId);
static void Phase2Task_Blackhole2(u8 taskId);
static void Phase2Task_RectangularSpiral(u8 taskId);
static void Phase2Task_29(u8 taskId);
static void Phase2Task_30(u8 taskId);
static void Phase2Task_31(u8 taskId);
static void Phase2Task_32(u8 taskId);
static void Phase2Task_33(u8 taskId);
static void VBlankCB_BattleTransition(void);
static void VBlankCB_Phase2_Swirl(void);
static void HBlankCB_Phase2_Swirl(void);
static void VBlankCB_Phase2_Shuffle(void);
static void HBlankCB_Phase2_Shuffle(void);
static void VBlankCB0_Phase2_BigPokeball(void);
static void VBlankCB1_Phase2_BigPokeball(void);
static void VBlankCB_Phase2_Clockwise_BlackFade(void);
static void VBlankCB_Phase2_Ripple(void);
static void HBlankCB_Phase2_Ripple(void);
static void VBlankCB_Phase2_30(void);
static void HBlankCB_Phase2_30(void);
static void VBlankCB_Phase2_Wave(void);
static void VBlankCB_Phase2_Slice(void);
static void HBlankCB_Phase2_Slice(void);
static void VBlankCB0_Phase2_WhiteFade(void);
static void VBlankCB1_Phase2_WhiteFade(void);
static void HBlankCB_Phase2_WhiteFade(void);
static void VBlankCB_Phase2_Shards(void);
static void VBlankCB_Phase2_Rayquaza(void);
static bool8 Phase2_Blur_Func1(struct Task *task);
static bool8 Phase2_Blur_Func2(struct Task *task);
static bool8 Phase2_Blur_Func3(struct Task *task);
static bool8 Phase2_Swirl_Func1(struct Task *task);
static bool8 Phase2_Swirl_Func2(struct Task *task);
static bool8 Phase2_Shuffle_Func1(struct Task *task);
static bool8 Phase2_Shuffle_Func2(struct Task *task);
static bool8 Phase2_Aqua_Func1(struct Task *task);
static bool8 Phase2_Aqua_Func2(struct Task *task);
static bool8 Phase2_Magma_Func1(struct Task *task);
static bool8 Phase2_Magma_Func2(struct Task *task);
static bool8 Phase2_FramesCountdown(struct Task *task);
static bool8 Phase2_Regi_Func1(struct Task *task);
static bool8 Phase2_Regice_Func2(struct Task *task);
static bool8 Phase2_Registeel_Func2(struct Task *task);
static bool8 Phase2_Regirock_Func2(struct Task *task);
static bool8 Phase2_WeatherTrio_Func1(struct Task *task);
static bool8 Phase2_WaitPaletteFade(struct Task *task);
static bool8 Phase2_Kyogre_Func3(struct Task *task);
static bool8 Phase2_Kyogre_Func4(struct Task *task);
static bool8 Phase2_Kyogre_Func5(struct Task *task);
static bool8 Phase2_Groudon_Func3(struct Task *task);
static bool8 Phase2_Groudon_Func4(struct Task *task);
static bool8 Phase2_Groudon_Func5(struct Task *task);
static bool8 Phase2_WeatherDuo_Func6(struct Task *task);
static bool8 Phase2_WeatherDuo_Func7(struct Task *task);
static bool8 Phase2_BigPokeball_Func1(struct Task *task);
static bool8 Phase2_BigPokeball_Func2(struct Task *task);
static bool8 Phase2_BigPokeball_Func3(struct Task *task);
static bool8 Phase2_BigPokeball_Func4(struct Task *task);
static bool8 Phase2_BigPokeball_Func5(struct Task *task);
static bool8 Phase2_BigPokeball_Func6(struct Task *task);
static bool8 Phase2_PokeballsTrail_Func1(struct Task *task);
static bool8 Phase2_PokeballsTrail_Func2(struct Task *task);
static bool8 Phase2_PokeballsTrail_Func3(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func1(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func2(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func3(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func4(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func5(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func6(struct Task *task);
static bool8 Phase2_Clockwise_BlackFade_Func7(struct Task *task);
static bool8 Phase2_Ripple_Func1(struct Task *task);
static bool8 Phase2_Ripple_Func2(struct Task *task);
static bool8 Phase2_Wave_Func1(struct Task *task);
static bool8 Phase2_Wave_Func2(struct Task *task);
static bool8 Phase2_Wave_Func3(struct Task *task);
static bool8 Phase2_Slice_Func1(struct Task *task);
static bool8 Phase2_Slice_Func2(struct Task *task);
static bool8 Phase2_Slice_Func3(struct Task *task);
static bool8 Phase2_WhiteFade_Func1(struct Task *task);
static bool8 Phase2_WhiteFade_Func2(struct Task *task);
static bool8 Phase2_WhiteFade_Func3(struct Task *task);
static bool8 Phase2_WhiteFade_Func4(struct Task *task);
static bool8 Phase2_WhiteFade_Func5(struct Task *task);
static bool8 Phase2_GridSquares_Func1(struct Task *task);
static bool8 Phase2_GridSquares_Func2(struct Task *task);
static bool8 Phase2_GridSquares_Func3(struct Task *task);
static bool8 Phase2_Shards_Func1(struct Task *task);
static bool8 Phase2_Shards_Func2(struct Task *task);
static bool8 Phase2_Shards_Func3(struct Task *task);
static bool8 Phase2_Shards_Func4(struct Task *task);
static bool8 Phase2_Shards_Func5(struct Task *task);
static bool8 Phase2_ShredSplit_Func1(struct Task *task);
static bool8 Phase2_ShredSplit_Func2(struct Task *task);
static bool8 Phase2_ShredSplit_Func3(struct Task *task);
static bool8 Phase2_ShredSplit_Func4(struct Task *task);
static bool8 Phase2_Blackhole_Func1(struct Task *task);
static bool8 Phase2_Blackhole1_Func2(struct Task *task);
static bool8 Phase2_Blackhole1_Func3(struct Task *task);
static bool8 Phase2_Blackhole2_Func2(struct Task *task);
static bool8 Phase2_RectangularSpiral_Func1(struct Task *task);
static bool8 Phase2_RectangularSpiral_Func2(struct Task *task);
static bool8 Phase2_RectangularSpiral_Func3(struct Task *task);
static bool8 Phase2_29_Func1(struct Task *task);
static bool8 Phase2_29_Func2(struct Task *task);
static bool8 Phase2_30_Func1(struct Task *task);
static bool8 Phase2_30_Func2(struct Task *task);
static bool8 Phase2_30_Func3(struct Task *task);
static bool8 Phase2_30_Func4(struct Task *task);
static bool8 Phase2_Rayquaza_Func3(struct Task *task);
static bool8 Phase2_Rayquaza_Func4(struct Task *task);
static bool8 Phase2_Rayquaza_Func5(struct Task *task);
static bool8 Phase2_Rayquaza_Func6(struct Task *task);
static bool8 Phase2_Rayquaza_Func7(struct Task *task);
static bool8 Phase2_Rayquaza_Func8(struct Task *task);
static bool8 Phase2_Rayquaza_Func9(struct Task *task);
static bool8 Phase2_31_Func1(struct Task *task);
static bool8 Phase2_31_Func2(struct Task *task);
static bool8 Phase2_31_Func3(struct Task *task);
static bool8 Phase2_31_33_Func5(struct Task *task);
static bool8 Phase2_33_Func1(struct Task *task);
static bool8 Phase2_33_Func2(struct Task *task);
static bool8 Phase2_33_Func3(struct Task *task);
static bool8 Phase2_33_Func4(struct Task *task);
static bool8 Phase2_32_Func1(struct Task *task);
static bool8 Phase2_32_Func2(struct Task *task);
static bool8 Phase2_32_Func3(struct Task *task);
static bool8 Phase2_32_Func4(struct Task *task);
static bool8 Phase2_32_Func5(struct Task *task);
static bool8 Phase2_Mugshot_Func1(struct Task *task);
static bool8 Phase2_Mugshot_Func2(struct Task *task);
static bool8 Phase2_Mugshot_Func3(struct Task *task);
static bool8 Phase2_Mugshot_Func4(struct Task *task);
static bool8 Phase2_Mugshot_Func5(struct Task *task);
static bool8 Phase2_Mugshot_Func6(struct Task *task);
static bool8 Phase2_Mugshot_Func7(struct Task *task);
static bool8 Phase2_Mugshot_Func8(struct Task *task);
static bool8 Phase2_Mugshot_Func9(struct Task *task);
static bool8 Phase2_Mugshot_Func10(struct Task *task);
static void Phase2Task_MugShotTransition(u8 taskId);
static void Mugshots_CreateOpponentPlayerSprites(struct Task *task);
static void VBlankCB0_Phase2_Mugshots(void);
static void VBlankCB1_Phase2_Mugshots(void);
static void HBlankCB_Phase2_Mugshots(void);
static bool8 Transition_Phase1(struct Task *task);
static bool8 Transition_WaitForPhase1(struct Task *task);
static bool8 Transition_Phase2(struct Task *task);
static bool8 Transition_WaitForPhase2(struct Task *task);
static void sub_8149F08(void);
static void sub_8149F84(void);
static void CreatePhase1Task(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4);
static void sub_814A014(u16 *a0, s16 a1, s16 a2, s16 a3);
static void sub_8149F98(s16 *array, s16 sinAdd, s16 index, s16 indexIncrementer, s16 amplitude, s16 arrSize);
static void sub_8149F40(u16 **a0);
static void sub_814A1AC(s16 *a0, s16 a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6);
static bool8 sub_814A228(s16 *a0, bool8 a1, bool8 a2);
static void sub_8148484(s16 spriteId, s16 value);
static void sub_814849C(s16 spriteId);
static s16 sub_81484B8(s16 spriteId);
static bool8 Phase1_TransitionAll_Func1(struct Task *task);
static bool8 Phase1_TransitionAll_Func2(struct Task *task);
static bool8 IsPhase1Done(void);
static bool16 sub_8149048(const s16 * const *arg0, struct StructRectangularSpiral *arg1);
static void sub_814713C(struct Sprite *sprite);
static void sub_8148380(struct Sprite *sprite);
static void sub_8149864(struct Sprite *sprite);
static bool8 sub_81483A8(struct Sprite *sprite);
static bool8 sub_81483AC(struct Sprite *sprite);
static bool8 sub_81483F8(struct Sprite *sprite);
static bool8 sub_814842C(struct Sprite *sprite);
static bool8 sub_8148458(struct Sprite *sprite);

// iwram bss vars
IWRAM_DATA static s16 sUnusedRectangularSpiralVar;
IWRAM_DATA static u8 sTestingTransitionId;
IWRAM_DATA static u8 sTestingTransitionState;
IWRAM_DATA static struct StructRectangularSpiral sRectangularSpiralTransition[4];

// ewram vars
EWRAM_DATA static struct TransitionData *sTransitionStructPtr = NULL;

// const rom data
static const u32 sBigPokeball_Tileset[] = INCBIN_U32("graphics/battle_transitions/big_pokeball.4bpp");
static const u32 sPokeballTrail_Tileset[] = INCBIN_U32("graphics/battle_transitions/pokeball_trail.4bpp");
static const u8 sSpriteImage_85B98F0[] = INCBIN_U8("graphics/battle_transitions/pokeball.4bpp");
static const u32 sUnknown_085B9AF0[] = INCBIN_U32("graphics/battle_transitions/elite_four_bg.4bpp");
static const u8 sSpriteImage_85B9CD0[] = INCBIN_U8("graphics/battle_transitions/unused_brendan.4bpp");
static const u8 sSpriteImage_85BA4D0[] = INCBIN_U8("graphics/battle_transitions/unused_lass.4bpp");
static const u32 sShrinkingBoxTileset[] = INCBIN_U32("graphics/battle_transitions/shrinking_box.4bpp");
static const u32 sEvilTeam_Palette[] = INCBIN_U32("graphics/battle_transitions/evil_team.gbapal");
static const u32 sTeamAqua_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_aqua.4bpp.lz");
static const u32 sTeamAqua_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_aqua.bin.lz");
static const u32 sTeamMagma_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_magma.4bpp.lz");
static const u32 sTeamMagma_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_magma.bin.lz");
static const u32 gUnknown_085BBC14[] = INCBIN_U32("graphics/battle_transitions/85BBC14.4bpp");
static const u32 gUnknown_085BC2B4[] = INCBIN_U32("graphics/battle_transitions/85BC2B4.gbapal");
static const u32 gUnknown_085BC2D4[] = INCBIN_U32("graphics/battle_transitions/85BC2D4.gbapal");
static const u32 gUnknown_085BC2F4[] = INCBIN_U32("graphics/battle_transitions/85BC2F4.gbapal");
static const u32 gUnknown_085BC314[] = INCBIN_U32("graphics/battle_transitions/85BC314.bin");
static const u32 gUnknown_085BCB14[] = INCBIN_U32("graphics/battle_transitions/85BCB14.bin");
static const u32 gUnknown_085BD314[] = INCBIN_U32("graphics/battle_transitions/85BD314.bin");
static const u16 gUnknown_085BDB14[] = INCBIN_U16("graphics/battle_transitions/85BDB14.gbapal");
static const u32 gUnknown_085BDB34[] = INCBIN_U32("graphics/battle_transitions/kyogre.4bpp.lz");
static const u32 gUnknown_085BE1E8[] = INCBIN_U32("graphics/battle_transitions/kyogre.bin.lz");
static const u32 gUnknown_085BE51C[] = INCBIN_U32("graphics/battle_transitions/groudon.4bpp.lz");
static const u32 gUnknown_085BEA88[] = INCBIN_U32("graphics/battle_transitions/groudon.bin.lz");
static const u16 gUnknown_085BEDA0[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt1.gbapal");
static const u16 gUnknown_085BEEE0[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt2.gbapal");
static const u16 gUnknown_085BF0A0[] = INCBIN_U16("graphics/battle_transitions/groudon_pt1.gbapal");
static const u16 gUnknown_085BF2A0[] = INCBIN_U16("graphics/battle_transitions/groudon_pt2.gbapal");
static const u16 gUnknown_085BF4A0[] = INCBIN_U16("graphics/battle_transitions/rayquaza.gbapal");
static const u32 gUnknown_085BF6A0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.4bpp");
static const u32 gUnknown_085C6BE0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.bin");
static const u32 gUnknown_085C7BE0[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.gbapal");
static const u32 gUnknown_085C7C00[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.4bpp.lz");
static const u32 gUnknown_085C828C[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.bin.lz");
static const u32 gUnknown_085C8578[] = INCBIN_U32("graphics/battle_transitions/frontier_squares_blanktiles.gbapal");
static const u32 gUnknown_085C8598[] = INCBIN_U32("graphics/battle_transitions/frontier_square_1.4bpp.lz");
static const u32 gUnknown_085C86F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_2.4bpp.lz");
static const u32 gUnknown_085C87F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_3.4bpp.lz");
static const u32 gUnknown_085C88A4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_4.4bpp.lz");
static const u32 gUnknown_085C8928[] = INCBIN_U32("graphics/battle_transitions/frontier_squares.bin");

static const TaskFunc sPhase1_Tasks[B_TRANSITION_COUNT] =
{
    [0 ... B_TRANSITION_COUNT - 1] = &Phase1Task_TransitionAll
};

static const TaskFunc sPhase2_Tasks[B_TRANSITION_COUNT] =
{
    Phase2Task_Blur,                        // 0
    Phase2Task_Swirl,                       // 1
    Phase2Task_Shuffle,                     // 2
    Phase2Task_BigPokeball,                 // 3
    Phase2Task_PokeballsTrail,              // 4
    Phase2Task_Clockwise_BlackFade,         // 5
    Phase2Task_Ripple,                      // 6
    Phase2Task_Wave,                        // 7
    Phase2Task_Slice,                       // 8
    Phase2Task_WhiteFade,                   // 9
    Phase2Task_GridSquares,                 // 10
    Phase2Task_Shards,                      // 11
    Phase2Task_Sidney,                      // 12
    Phase2Task_Phoebe,                      // 13
    Phase2Task_Glacia,                      // 14
    Phase2Task_Drake,                       // 15
    Phase2Task_Champion,                    // 16
    Phase2Task_Aqua,                        // 17
    Phase2Task_Magma,                       // 18
    Phase2Task_Regice,                      // 19
    Phase2Task_Registeel,                   // 20
    Phase2Task_Regirock,                    // 21
    Phase2Task_Kyogre,                      // 22
    Phase2Task_Groudon,                     // 23
    Phase2Task_Rayquaza,                    // 24
    Phase2Task_ShredSplit,                  // 25
    Phase2Task_Blackhole1,                  // 26
    Phase2Task_Blackhole2,                  // 27
    Phase2Task_RectangularSpiral,           // 28
    Phase2Task_29,                          // 29
    Phase2Task_30,                          // 30
    Phase2Task_31,                          // 31
    Phase2Task_32,                          // 32
    Phase2Task_33,                          // 33
    Phase2Task_34,                          // 34
    Phase2Task_35,                          // 35
    Phase2Task_36,                          // 36
    Phase2Task_37,                          // 37
    Phase2Task_38,                          // 38
    Phase2Task_39,                          // 39
    Phase2Task_40,                          // 40
    Phase2Task_41,                          // 41
};

static const TransitionStateFunc sMainTransitionPhases[] =
{
    &Transition_Phase1,
    &Transition_WaitForPhase1,
    &Transition_Phase2,
    &Transition_WaitForPhase2
};

static const TransitionStateFunc sPhase2_Blur_Funcs[] =
{
    Phase2_Blur_Func1,
    Phase2_Blur_Func2,
    Phase2_Blur_Func3
};

static const TransitionStateFunc sPhase2_Swirl_Funcs[] =
{
    Phase2_Swirl_Func1,
    Phase2_Swirl_Func2,
};

static const TransitionStateFunc sPhase2_Shuffle_Funcs[] =
{
    Phase2_Shuffle_Func1,
    Phase2_Shuffle_Func2,
};

static const TransitionStateFunc sPhase2_Aqua_Funcs[] =
{
    Phase2_Aqua_Func1,
    Phase2_Aqua_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_FramesCountdown,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_Magma_Funcs[] =
{
    Phase2_Magma_Func1,
    Phase2_Magma_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_FramesCountdown,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_BigPokeball_Funcs[] =
{
    Phase2_BigPokeball_Func1,
    Phase2_BigPokeball_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_Regice_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Regice_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_Registeel_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Registeel_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_Regirock_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Regirock_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_Kyogre_Funcs[] =
{
    Phase2_WeatherTrio_Func1,
    Phase2_WaitPaletteFade,
    Phase2_Kyogre_Func3,
    Phase2_Kyogre_Func4,
    Phase2_Kyogre_Func5,
    Phase2_FramesCountdown,
    Phase2_WeatherDuo_Func6,
    Phase2_WeatherDuo_Func7
};

static const TransitionStateFunc sPhase2_PokeballsTrail_Funcs[] =
{
    Phase2_PokeballsTrail_Func1,
    Phase2_PokeballsTrail_Func2,
    Phase2_PokeballsTrail_Func3
};

static const s16 sUnknown_085C8B88[2] = {-16, 256};
static const s16 sUnknown_085C8B8C[5] = {0, 32, 64, 18, 48};
static const s16 sUnknown_085C8B96[2] = {8, -8};

static const TransitionStateFunc sPhase2_Clockwise_BlackFade_Funcs[] =
{
    Phase2_Clockwise_BlackFade_Func1,
    Phase2_Clockwise_BlackFade_Func2,
    Phase2_Clockwise_BlackFade_Func3,
    Phase2_Clockwise_BlackFade_Func4,
    Phase2_Clockwise_BlackFade_Func5,
    Phase2_Clockwise_BlackFade_Func6,
    Phase2_Clockwise_BlackFade_Func7
};

static const TransitionStateFunc sPhase2_Ripple_Funcs[] =
{
    Phase2_Ripple_Func1,
    Phase2_Ripple_Func2
};

static const TransitionStateFunc sPhase2_Wave_Funcs[] =
{
    Phase2_Wave_Func1,
    Phase2_Wave_Func2,
    Phase2_Wave_Func3
};

static const TransitionStateFunc sPhase2_Mugshot_Funcs[] =
{
    Phase2_Mugshot_Func1,
    Phase2_Mugshot_Func2,
    Phase2_Mugshot_Func3,
    Phase2_Mugshot_Func4,
    Phase2_Mugshot_Func5,
    Phase2_Mugshot_Func6,
    Phase2_Mugshot_Func7,
    Phase2_Mugshot_Func8,
    Phase2_Mugshot_Func9,
    Phase2_Mugshot_Func10
};

static const u8 sMugshotsTrainerPicIDsTable[MUGSHOTS_COUNT] =
{
    TRAINER_PIC_ELITE_FOUR_SIDNEY,
    TRAINER_PIC_ELITE_FOUR_PHOEBE,
    TRAINER_PIC_ELITE_FOUR_GLACIA,
    TRAINER_PIC_ELITE_FOUR_DRAKE,
    TRAINER_PIC_CHAMPION_WALLACE
};
static const s16 sMugshotsOpponentRotationScales[MUGSHOTS_COUNT][2] =
{
    {0x200, 0x200},
    {0x200, 0x200},
    {0x1B0, 0x1B0},
    {0x1A0, 0x1A0},
    {0x188, 0x188},
};
static const s16 sMugshotsOpponentCoords[MUGSHOTS_COUNT][2] =
{
    {0,     0},
    {0,     0},
    {-4,    4},
    {0,     5},
    {-8,    7},
};

static const TransitionSpriteCallback sUnknown_085C8C24[] =
{
    sub_81483A8,
    sub_81483AC,
    sub_81483F8,
    sub_814842C,
    sub_81483A8,
    sub_8148458,
    sub_81483A8
};

static const s16 sUnknown_085C8C40[2] = {12, -12};
static const s16 sUnknown_085C8C44[2] = {-1, 1};

static const TransitionStateFunc sPhase2_Slice_Funcs[] =
{
    Phase2_Slice_Func1,
    Phase2_Slice_Func2,
    Phase2_Slice_Func3
};

static const TransitionStateFunc sPhase2_ShredSplit_Funcs[] =
{
    Phase2_ShredSplit_Func1,
    Phase2_ShredSplit_Func2,
    Phase2_ShredSplit_Func3,
    Phase2_ShredSplit_Func4
};

static const u8 gUnknown_085C8C64[] = {39, 119};
static const s16 gUnknown_085C8C66[] = {1, -1};

static const TransitionStateFunc sPhase2_Blackhole1_Funcs[] =
{
    Phase2_Blackhole_Func1,
    Phase2_Blackhole1_Func2,
    Phase2_Blackhole1_Func3
};

static const TransitionStateFunc sPhase2_Blackhole2_Funcs[] =
{
    Phase2_Blackhole_Func1,
    Phase2_Blackhole2_Func2
};

static const s16 gUnknown_085C8C80[] = {-6, 4};

static const TransitionStateFunc sPhase2_RectangularSpiral_Funcs[] =
{
    Phase2_RectangularSpiral_Func1,
    Phase2_RectangularSpiral_Func2,
    Phase2_RectangularSpiral_Func3
};

static const s16 gUnknown_085C8C90[] = {1, 27, 275, -1};
static const s16 gUnknown_085C8C98[] = {2, 486, -1};
static const s16 gUnknown_085C8C9E[] = {3, 262, -1};
static const s16 gUnknown_085C8CA4[] = {4, 507, -2};
static const s16 gUnknown_085C8CAA[] = {1, 213, -1};
static const s16 gUnknown_085C8CB0[] = {2, 548, -2};
static const s16 gUnknown_085C8CB6[] = {3, 196, -1};
static const s16 gUnknown_085C8CBC[] = {4, 573, 309, -1};
static const s16 gUnknown_085C8CC4[] = {1, 474, -1};
static const s16 gUnknown_085C8CCA[] = {2, 295, 32, -1};
static const s16 gUnknown_085C8CD2[] = {3, 58, -1};
static const s16 gUnknown_085C8CD8[] = {4, 455, -1};
static const s16 gUnknown_085C8CDE[] = {1, 540, -1};
static const s16 gUnknown_085C8CE4[] = {2, 229, -1};
static const s16 gUnknown_085C8CEA[] = {3, 244, 28, -1};
static const s16 gUnknown_085C8CF2[] = {4, 517, -1};

static const s16 *const gUnknown_085C8CF8[] =
{
    gUnknown_085C8C90,
    gUnknown_085C8CA4,
    gUnknown_085C8C98,
    gUnknown_085C8C9E,
    gUnknown_085C8CEA,
    gUnknown_085C8CE4,
    gUnknown_085C8CF2,
    gUnknown_085C8CDE
};

static const s16 *const gUnknown_085C8D18[] =
{
    gUnknown_085C8CBC,
    gUnknown_085C8CB0,
    gUnknown_085C8CB6,
    gUnknown_085C8CAA,
    gUnknown_085C8CCA,
    gUnknown_085C8CD8,
    gUnknown_085C8CC4,
    gUnknown_085C8CD2
};

static const s16 *const *const gUnknown_085C8D38[] =
{
    gUnknown_085C8CF8,
    gUnknown_085C8D18
};

static const TransitionStateFunc sPhase2_Groudon_Funcs[] =
{
    Phase2_WeatherTrio_Func1,
    Phase2_WaitPaletteFade,
    Phase2_Groudon_Func3,
    Phase2_Groudon_Func4,
    Phase2_Groudon_Func5,
    Phase2_FramesCountdown,
    Phase2_WeatherDuo_Func6,
    Phase2_WeatherDuo_Func7
};

static const TransitionStateFunc sPhase2_Rayquaza_Funcs[] =
{
    Phase2_WeatherTrio_Func1,
    Phase2_WaitPaletteFade,
    Phase2_Rayquaza_Func3,
    Phase2_Rayquaza_Func4,
    Phase2_Rayquaza_Func5,
    Phase2_Rayquaza_Func6,
    Phase2_Rayquaza_Func7,
    Phase2_Rayquaza_Func8,
    Phase2_Rayquaza_Func9,
    Phase2_Blackhole1_Func2,
    Phase2_Blackhole1_Func3
};

static const TransitionStateFunc sPhase2_WhiteFade_Funcs[] =
{
    Phase2_WhiteFade_Func1,
    Phase2_WhiteFade_Func2,
    Phase2_WhiteFade_Func3,
    Phase2_WhiteFade_Func4,
    Phase2_WhiteFade_Func5
};

static const s16 sUnknown_085C8DA0[] = {0, 20, 15, 40, 10, 25, 35, 5};

static const TransitionStateFunc sPhase2_GridSquares_Funcs[] =
{
    Phase2_GridSquares_Func1,
    Phase2_GridSquares_Func2,
    Phase2_GridSquares_Func3
};

static const TransitionStateFunc sPhase2_Shards_Funcs[] =
{
    Phase2_Shards_Func1,
    Phase2_Shards_Func2,
    Phase2_Shards_Func3,
    Phase2_Shards_Func4,
    Phase2_Shards_Func5
};

static const s16 sUnknown_085C8DD0[][5] =
{
    {56,    0,      0,      160,    0},
    {104,   160,    240,    88,     1},
    {240,   72,     56,     0,      1},
    {0,     32,     144,    160,    0},
    {144,   160,    184,    0,      1},
    {56,    0,      168,    160,    0},
    {168,   160,    48,     0,      1},
};

static const s16 sUnknown_085C8E16[] = {8, 4, 2, 1, 1, 1, 0};

static const TransitionStateFunc sPhase1_TransitionAll_Funcs[] =
{
    Phase1_TransitionAll_Func1,
    Phase1_TransitionAll_Func2
};

static const struct SpriteFrameImage sSpriteImageTable_85C8E2C[] =
{
    sSpriteImage_85B98F0, 0x200
};

static const union AnimCmd sSpriteAnim_85C8E34[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_85C8E3C[] =
{
    sSpriteAnim_85C8E34
};

static const union AffineAnimCmd sSpriteAffineAnim_85C8E40[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 1),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd sSpriteAffineAnim_85C8E50[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 4, 1),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85C8E60[] =
{
    sSpriteAffineAnim_85C8E40,
    sSpriteAffineAnim_85C8E50
};

static const struct SpriteTemplate gUnknown_085C8E68 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 4105,
    .oam = &gEventObjectBaseOam_32x32,
    .anims = sSpriteAnimTable_85C8E3C,
    .images = sSpriteImageTable_85C8E2C,
    .affineAnims = sSpriteAffineAnimTable_85C8E60,
    .callback = sub_814713C
};

static const struct OamData gOamData_85C8E80 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sSpriteImageTable_85C8E88[] =
{
    sSpriteImage_85B9CD0, 0x800
};

static const struct SpriteFrameImage sSpriteImageTable_85C8E90[] =
{
    sSpriteImage_85BA4D0, 0x800
};

static const union AnimCmd sSpriteAnim_85C8E98[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_85C8EA0[] =
{
    sSpriteAnim_85C8E98
};

static const struct SpriteTemplate sSpriteTemplate_85C8EA4 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 4106,
    .oam = &gOamData_85C8E80,
    .anims = sSpriteAnimTable_85C8EA0,
    .images = sSpriteImageTable_85C8E88,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8148380
};

static const struct SpriteTemplate sSpriteTemplate_85C8EBC =
{
    .tileTag = 0xFFFF,
    .paletteTag = 4106,
    .oam = &gOamData_85C8E80,
    .anims = sSpriteAnimTable_85C8EA0,
    .images = sSpriteImageTable_85C8E90,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8148380
};

static const u16 gFieldEffectObjectPalette10[] = INCBIN_U16("graphics/event_objects/palettes/field_effect_object_palette_10.gbapal");

const struct SpritePalette gFieldEffectObjectPaletteInfo10 =
{
    gFieldEffectObjectPalette10, 0x1009
};

static const u16 sMugshotPal_Sidney[] = INCBIN_U16("graphics/battle_transitions/sidney_bg.gbapal");
static const u16 sMugshotPal_Phoebe[] = INCBIN_U16("graphics/battle_transitions/phoebe_bg.gbapal");
static const u16 sMugshotPal_Glacia[] = INCBIN_U16("graphics/battle_transitions/glacia_bg.gbapal");
static const u16 sMugshotPal_Drake[] = INCBIN_U16("graphics/battle_transitions/drake_bg.gbapal");
static const u16 sMugshotPal_Champion[] = INCBIN_U16("graphics/battle_transitions/wallace_bg.gbapal");
static const u16 sMugshotPal_Brendan[] = INCBIN_U16("graphics/battle_transitions/brendan_bg.gbapal");
static const u16 sMugshotPal_May[] = INCBIN_U16("graphics/battle_transitions/may_bg.gbapal");

static const u16 *const sOpponentMugshotsPals[MUGSHOTS_COUNT] =
{
    sMugshotPal_Sidney,
    sMugshotPal_Phoebe,
    sMugshotPal_Glacia,
    sMugshotPal_Drake,
    sMugshotPal_Champion
};

static const u16 *const sPlayerMugshotsPals[2] =
{
    sMugshotPal_Brendan,
    sMugshotPal_May
};

static const u16 sUnusedTrainerPalette[] = INCBIN_U16("graphics/battle_transitions/unused_trainer.gbapal");
static const struct SpritePalette sSpritePalette_UnusedTrainer =
{
    sUnusedTrainerPalette, 0x100A
};

static const u16 sBigPokeball_Tilemap[] = INCBIN_U16("graphics/battle_transitions/big_pokeball_map.bin");
static const u16 sMugshotsTilemap[] = INCBIN_U16("graphics/battle_transitions/elite_four_bg_map.bin");

static const TransitionStateFunc sPhase2_29_Funcs[] =
{
    Phase2_29_Func1,
    Phase2_29_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

static const TransitionStateFunc sPhase2_30_Funcs[] =
{
    Phase2_30_Func1,
    Phase2_30_Func2,
    Phase2_30_Func3,
    Phase2_30_Func4
};

static const TransitionStateFunc sPhase2_31_Funcs[] =
{
    Phase2_31_Func1,
    Phase2_31_Func2,
    Phase2_31_Func3,
    Phase2_31_33_Func5
};

static const TransitionStateFunc sPhase2_33_Funcs[] =
{
    Phase2_33_Func1,
    Phase2_33_Func2,
    Phase2_33_Func3,
    Phase2_33_Func4,
    Phase2_31_33_Func5
};

static const TransitionStateFunc sPhase2_32_Funcs[] =
{
    Phase2_32_Func1,
    Phase2_32_Func2,
    Phase2_32_Func3,
    Phase2_32_Func4,
    Phase2_32_Func5
};

static const u8 gUnknown_085C9A30[] = {0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x1b, 0x14, 0x0d, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x07, 0x0e, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x13, 0x0c, 0x0b, 0x0a, 0x09, 0x08, 0x0f, 0x10, 0x11, 0x12};
static const u8 gUnknown_085C9A53[] = {0x00, 0x10, 0x29, 0x16, 0x2c, 0x02, 0x2b, 0x15, 0x2e, 0x1b, 0x09, 0x30, 0x26, 0x05, 0x39, 0x3b, 0x0c, 0x3f, 0x23, 0x1c, 0x0a, 0x35, 0x07, 0x31, 0x27, 0x17, 0x37, 0x01, 0x3e, 0x11, 0x3d, 0x1e, 0x06, 0x22, 0x0f, 0x33, 0x20, 0x3a, 0x0d, 0x2d, 0x25, 0x34, 0x0b, 0x18, 0x3c, 0x13, 0x38, 0x21, 0x1d, 0x32, 0x28, 0x36, 0x0e, 0x03, 0x2f, 0x14, 0x12, 0x19, 0x04, 0x24, 0x1a, 0x2a, 0x1f, 0x08, 0x00};

// code
static void CB2_TestBattleTransition(void)
{
    switch (sTestingTransitionState)
    {
    case 0:
        LaunchBattleTransitionTask(sTestingTransitionId);
        sTestingTransitionState++;
        break;
    case 1:
        if (IsBattleTransitionDone())
        {
            sTestingTransitionState = 0;
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void TestBattleTransition(u8 transitionId)
{
    sTestingTransitionId = transitionId;
    SetMainCallback2(CB2_TestBattleTransition);
}

void BattleTransition_StartOnField(u8 transitionId)
{
    gMain.callback2 = CB2_OverworldBasic;
    LaunchBattleTransitionTask(transitionId);
}

void BattleTransition_Start(u8 transitionId)
{
    LaunchBattleTransitionTask(transitionId);
}

// in all tasks data[0] is reserved for the state
#define tState          data[0]

// main task that launches sub-tasks for phase1 and phase2
#define tTransitionId   data[1]
#define tTransitionDone data[15]

bool8 IsBattleTransitionDone(void)
{
    u8 taskId = FindTaskIdByFunc(Task_BattleTransitionMain);
    if (gTasks[taskId].tTransitionDone)
    {
        DestroyTask(taskId);
        FREE_AND_SET_NULL(sTransitionStructPtr);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void LaunchBattleTransitionTask(u8 transitionId)
{
    u8 taskId = CreateTask(Task_BattleTransitionMain, 2);
    gTasks[taskId].tTransitionId = transitionId;
    sTransitionStructPtr = AllocZeroed(sizeof(*sTransitionStructPtr));
}

static void Task_BattleTransitionMain(u8 taskId)
{
    while (sMainTransitionPhases[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Transition_Phase1(struct Task *task)
{
    SetWeatherScreenFadeOut();
    CpuCopy32(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    if (sPhase1_Tasks[task->tTransitionId] != NULL)
    {
        CreateTask(sPhase1_Tasks[task->tTransitionId], 4);
        task->tState++;
        return FALSE;
    }
    else
    {
        task->tState = 2;
        return TRUE;
    }
}

static bool8 Transition_WaitForPhase1(struct Task *task)
{
    if (FindTaskIdByFunc(sPhase1_Tasks[task->tTransitionId]) == 0xFF)
    {
        task->tState++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 Transition_Phase2(struct Task *task)
{
    CreateTask(sPhase2_Tasks[task->tTransitionId], 0);
    task->tState++;
    return FALSE;
}

static bool8 Transition_WaitForPhase2(struct Task *task)
{
    task->tTransitionDone = FALSE;
    if (FindTaskIdByFunc(sPhase2_Tasks[task->tTransitionId]) == 0xFF)
        task->tTransitionDone = TRUE;
    return FALSE;
}

#undef tTransitionId
#undef tTransitionDone

static void Phase1Task_TransitionAll(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        gTasks[taskId].tState++;
        CreatePhase1Task(0, 0, 3, 2, 2); // creates a sub-task for this sub-task
    }
    else if (IsPhase1Done())
    {
        DestroyTask(taskId);
    }
}

// sub-task for phase2
#define tData1              data[1]
#define tData2              data[2]
#define tData3              data[3]
#define tData4              data[4]
#define tData5              data[5]
#define tData6              data[6]
#define tFuncState          data[7]
#define tFrames             data[8]
#define tOpponentSpriteId   data[13]
#define tPlayerSpriteId     data[14]
#define tMugshotId          data[15]

static void Phase2Task_Blur(u8 taskId)
{
    while (sPhase2_Blur_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Blur_Func1(struct Task *task)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG3CNT, BGCNT_MOSAIC);
    task->tState++;
    return TRUE;
}

static bool8 Phase2_Blur_Func2(struct Task *task)
{
    if (task->tData1 != 0)
    {
        task->tData1--;
    }
    else
    {
        task->tData1 = 4;
        if (++task->tData2 == 10)
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 0x10, RGB_BLACK);
        SetGpuReg(REG_OFFSET_MOSAIC, (task->tData2 & 15) * 17);
        if (task->tData2 > 14)
            task->tState++;
    }
    return FALSE;
}

static bool8 Phase2_Blur_Func3(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Phase2Task_Blur);
        DestroyTask(taskId);
    }
    return FALSE;
}

static void Phase2Task_Swirl(u8 taskId)
{
    while (sPhase2_Swirl_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Swirl_Func1(struct Task *task)
{
    sub_8149F08();
    ScanlineEffect_Clear();
    BeginNormalPaletteFade(0xFFFFFFFF, 4, 0, 0x10, RGB_BLACK);
    sub_8149F98(gScanlineEffectRegBuffers[1], sTransitionStructPtr->field_14, 0, 2, 0, 160);

    SetVBlankCallback(VBlankCB_Phase2_Swirl);
    SetHBlankCallback(HBlankCB_Phase2_Swirl);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Swirl_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    task->tData1 += 4;
    task->tData2 += 8;

    sub_8149F98(gScanlineEffectRegBuffers[0], sTransitionStructPtr->field_14, task->tData1, 2, task->tData2, 160);

    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Phase2Task_Swirl);
        DestroyTask(taskId);
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Phase2_Swirl(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
}

static void HBlankCB_Phase2_Swirl(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1HOFS = var;
    REG_BG2HOFS = var;
    REG_BG3HOFS = var;
}

static void Phase2Task_Shuffle(u8 taskId)
{
    while (sPhase2_Shuffle_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Shuffle_Func1(struct Task *task)
{
    sub_8149F08();
    ScanlineEffect_Clear();

    BeginNormalPaletteFade(0xFFFFFFFF, 4, 0, 0x10, RGB_BLACK);
    memset(gScanlineEffectRegBuffers[1], sTransitionStructPtr->field_16, 0x140);

    SetVBlankCallback(VBlankCB_Phase2_Shuffle);
    SetHBlankCallback(HBlankCB_Phase2_Shuffle);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Shuffle_Func2(struct Task *task)
{
    u8 i;
    u16 r3, r4;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    r4 = task->tData1;
    r3 = task->tData2 >> 8;
    task->tData1 += 4224;
    task->tData2 += 384;

    for (i = 0; i < 160; i++, r4 += 4224)
    {
        u16 var = r4 / 256;
        gScanlineEffectRegBuffers[0][i] = sTransitionStructPtr->field_16 + Sin(var, r3);
    }

    if (!gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Phase2Task_Shuffle));

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Phase2_Shuffle(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
}

static void HBlankCB_Phase2_Shuffle(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

static void Phase2Task_BigPokeball(u8 taskId)
{
    while (sPhase2_BigPokeball_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Aqua(u8 taskId)
{
    while (sPhase2_Aqua_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Magma(u8 taskId)
{
    while (sPhase2_Magma_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Regice(u8 taskId)
{
    while (sPhase2_Regice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Registeel(u8 taskId)
{
    while (sPhase2_Registeel_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Regirock(u8 taskId)
{
    while (sPhase2_Regirock_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Kyogre(u8 taskId)
{
    while (sPhase2_Kyogre_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void sub_814669C(struct Task *task)
{
    s32 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    task->tData1 = 16;
    task->tData2 = 0;
    task->tData4 = 0;
    task->tData5 = 0x4000;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0H = 240;
    sTransitionStructPtr->WIN0V = 160;
    sTransitionStructPtr->BLDCNT = 0x3F41;
    sTransitionStructPtr->BLDALPHA = (task->tData1 << 8) | (task->tData2);

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 240;
    }

    SetVBlankCallback(VBlankCB0_Phase2_BigPokeball);
}

static bool8 Phase2_Aqua_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    task->tFrames = 60;
    sub_814669C(task);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(sTeamAqua_Tileset, dst2);
    LoadPalette(sEvilTeam_Palette, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Magma_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    task->tFrames = 60;
    sub_814669C(task);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(sTeamMagma_Tileset, dst2);
    LoadPalette(sEvilTeam_Palette, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Regi_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    task->tFrames = 60;
    sub_814669C(task);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    CpuCopy16(gUnknown_085BBC14, dst2, 0x2000);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_814669C(task);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    CpuCopy16(sBigPokeball_Tileset, dst2, 0x580);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func2(struct Task *task)
{
    s16 i, j;
    u16 *dst1, *dst2;
    const u16 *BigPokeballMap;

    sub_8149F58(&dst1, &dst2);
    BigPokeballMap = sBigPokeball_Tilemap;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++, BigPokeballMap++)
        {
            dst1[i * 32 + j] = *BigPokeballMap | 0xF000;
        }
    }
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Aqua_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(sTeamAqua_Tilemap, dst1);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Magma_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(sTeamMagma_Tilemap, dst1);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Regice_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2B4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BC314, dst1, 0x500);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Registeel_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2D4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BCB14, dst1, 0x500);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Regirock_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2F4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BD314, dst1, 0x500);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5, 160);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Kyogre_Func3(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085BDB34, dst2);
    LZ77UnCompVram(gUnknown_085BE1E8, dst1);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Kyogre_Func4(struct Task *task)
{
    if (task->tData1 % 3 == 0)
    {
        u16 var = task->tData1 % 30;
        var /= 3;
        LoadPalette(gUnknown_085BEDA0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->tData1 > 58)
    {
        task->tState++;
        task->tData1 = 0;
    }

    return FALSE;
}

static bool8 Phase2_Kyogre_Func5(struct Task *task)
{
    if (task->tData1 % 5 == 0)
    {
        s16 var = task->tData1 / 5;
        LoadPalette(gUnknown_085BEEE0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->tData1 > 68)
    {
        task->tState++;
        task->tData1 = 0;
        task->tFrames = 30;
    }

    return FALSE;
}

static bool8 Phase2_WeatherDuo_Func6(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFF8000, 1, 0, 0x10, RGB_BLACK);
    task->tState++;
    return FALSE;
}

static bool8 Phase2_WeatherDuo_Func7(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func3(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->tData3 == 0 || --task->tData3 == 0)
    {
        task->tData2++;
        task->tData3 = 2;
    }
    sTransitionStructPtr->BLDALPHA = (task->tData1 << 8) | task->tData2;
    if (task->tData2 > 15)
        task->tState++;
    task->tData4 += 8;
    task->tData5 -= 256;

    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5 >> 8, 160);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func4(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->tData3 == 0 || --task->tData3 == 0)
    {
        task->tData1--;
        task->tData3 = 2;
    }
    sTransitionStructPtr->BLDALPHA = (task->tData1 << 8) | task->tData2;
    if (task->tData1 == 0)
        task->tState++;
    task->tData4 += 8;
    task->tData5 -= 256;

    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5 >> 8, 160);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func5(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    task->tData4 += 8;
    task->tData5 -= 256;

    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 132, task->tData5 >> 8, 160);

    if (task->tData5 <= 0)
    {
        task->tState++;
        task->tData1 = 160;
        task->tData2 = 256;
        task->tData3 = 0;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_FramesCountdown(struct Task *task)
{
    if (--task->tFrames == 0)
        task->tState++;
    return FALSE;
}

static bool8 Phase2_WeatherTrio_Func1(struct Task *task)
{
    BeginNormalPaletteFade(0x0000FFFF, 1, 0, 0x10, RGB_BLACK);
    task->tState++;
    return FALSE;
}

static bool8 Phase2_WaitPaletteFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->tState++;
    return FALSE;
}

static bool8 Phase2_BigPokeball_Func6(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->tData2 < 1024)
        task->tData2 += 128;
    if (task->tData1 != 0)
    {
        task->tData1 -= (task->tData2 >> 8);
        if (task->tData1 < 0)
            task->tData1 = 0;
    }
    sub_814A014(gScanlineEffectRegBuffers[0], 120, 80, task->tData1);
    if (task->tData1 == 0)
    {
        SetVBlankCallback(NULL);
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        if (task->tData3 == 0)
        {
            task->tData3++;
            SetVBlankCallback(VBlankCB1_Phase2_BigPokeball);
        }

        sTransitionStructPtr->VBlank_DMA++;
    }

    return FALSE;
}

static void Transition_BigPokeball_Vblank(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_BLDALPHA = sTransitionStructPtr->BLDALPHA;
}

static void VBlankCB0_Phase2_BigPokeball(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_BG0HOFS, 0xA2400001);
}

static void VBlankCB1_Phase2_BigPokeball(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, 0xA2400001);
}

static void Phase2Task_PokeballsTrail(u8 taskId)
{
    while (sPhase2_PokeballsTrail_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_PokeballsTrail_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuSet(sPokeballTrail_Tileset, dst2, 0x20);
    CpuFill32(0, dst1, 0x800);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_PokeballsTrail_Func2(struct Task *task)
{
    s16 i;
    s16 rand;
    s16 arr0[ARRAY_COUNT(sUnknown_085C8B88)];
    s16 arr1[ARRAY_COUNT(sUnknown_085C8B8C)];

    memcpy(arr0, sUnknown_085C8B88, sizeof(sUnknown_085C8B88));
    memcpy(arr1, sUnknown_085C8B8C, sizeof(sUnknown_085C8B8C));
    rand = Random() & 1;
    for (i = 0; i <= 4; i++, rand ^= 1)
    {
        gFieldEffectArguments[0] = arr0[rand];      // x
        gFieldEffectArguments[1] = (i * 32) + 16;   // y
        gFieldEffectArguments[2] = rand;
        gFieldEffectArguments[3] = arr1[i];
        FieldEffectStart(FLDEFF_POKEBALL);
    }

    task->tState++;
    return FALSE;
}

static bool8 Phase2_PokeballsTrail_Func3(struct Task *task)
{
    if (!FieldEffectActiveListContains(FLDEFF_POKEBALL))
    {
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(Phase2Task_PokeballsTrail));
    }
    return FALSE;
}

bool8 FldEff_Pokeball(void)
{
    u8 spriteId = CreateSpriteAtEnd(&gUnknown_085C8E68, gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].data[0] = gFieldEffectArguments[2];
    gSprites[spriteId].data[1] = gFieldEffectArguments[3];
    gSprites[spriteId].data[2] = -1;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], gFieldEffectArguments[2]);
    return FALSE;
}

#define SOME_VRAM_STORE(ptr, posY, posX, toStore)                       \
{                                                                       \
    u32 index = (posY) * 32 + posX;                                     \
    ptr[index] = toStore;                                               \
}

static void sub_814713C(struct Sprite *sprite)
{
    s16 arr0[ARRAY_COUNT(sUnknown_085C8B96)];

    memcpy(arr0, sUnknown_085C8B96, sizeof(sUnknown_085C8B96));
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
    }
    else
    {
        if (sprite->pos1.x >= 0 && sprite->pos1.x <= 240)
        {
            s16 posX = sprite->pos1.x >> 3;
            s16 posY = sprite->pos1.y >> 3;

            if (posX != sprite->data[2])
            {
                u32 var;
                u16 *ptr;

                sprite->data[2] = posX;
                var = (((REG_BG0CNT >> 8) & 0x1F) << 11);  // r2
                ptr = (u16 *)(VRAM + var);

                SOME_VRAM_STORE(ptr, posY - 2, posX, 0xF001);
                SOME_VRAM_STORE(ptr, posY - 1, posX, 0xF001);
                SOME_VRAM_STORE(ptr, posY - 0, posX, 0xF001);
                SOME_VRAM_STORE(ptr, posY + 1, posX, 0xF001);
            }
        }
        sprite->pos1.x += arr0[sprite->data[0]];
        if (sprite->pos1.x < -15 || sprite->pos1.x > 255)
            FieldEffectStop(sprite, FLDEFF_POKEBALL);
    }
}

static void Phase2Task_Clockwise_BlackFade(u8 taskId)
{
    while (sPhase2_Clockwise_BlackFade_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Clockwise_BlackFade_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->WININ = 0;
    sTransitionStructPtr->WINOUT = 63;
    sTransitionStructPtr->WIN0H = -3855;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 0xF3F4;
    }

    SetVBlankCallback(VBlankCB_Phase2_Clockwise_BlackFade);
    sTransitionStructPtr->data[4] = 120;

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Clockwise_BlackFade_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], -1, 1, 1);
    do
    {
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = (sTransitionStructPtr->data[2] + 1) | 0x7800;
    } while (!sub_814A228(sTransitionStructPtr->data, 1, 1));

    sTransitionStructPtr->data[4] += 16;
    if (sTransitionStructPtr->data[4] >= 240)
    {
        sTransitionStructPtr->data[5] = 0;
        task->tState++;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Clockwise_BlackFade_Func3(struct Task *task)
{
    s16 r1, r3;
    vu8 var = 0;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, 240, sTransitionStructPtr->data[5], 1, 1);

    while (1)
    {
        r1 = 120, r3 = sTransitionStructPtr->data[2] + 1;
        if (sTransitionStructPtr->data[5] >= 80)
            r1 = sTransitionStructPtr->data[2], r3 = 240;
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = (r3) | (r1 << 8);
        if (var != 0)
            break;
        var = sub_814A228(sTransitionStructPtr->data, 1, 1);
    }

    sTransitionStructPtr->data[5] += 8;
    if (sTransitionStructPtr->data[5] >= 160)
    {
        sTransitionStructPtr->data[4] = 240;
        task->tState++;
    }
    else
    {
        while (sTransitionStructPtr->data[3] < sTransitionStructPtr->data[5])
        {
            gScanlineEffectRegBuffers[0][++sTransitionStructPtr->data[3]] = (r3) | (r1 << 8);
        }
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Clockwise_BlackFade_Func4(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], 160, 1, 1);
    do
    {
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = (sTransitionStructPtr->data[2] << 8) | 0xF0;
    } while (!sub_814A228(sTransitionStructPtr->data, 1, 1));

    sTransitionStructPtr->data[4] -= 16;
    if (sTransitionStructPtr->data[4] <= 0)
    {
        sTransitionStructPtr->data[5] = 160;
        task->tState++;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Clockwise_BlackFade_Func5(struct Task *task)
{
    s16 r1, r2, var4;
    vu8 var = 0;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, 0, sTransitionStructPtr->data[5], 1, 1);

    while (1)
    {
        r1 = (gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]]) & 0xFF;
        r2 = sTransitionStructPtr->data[2];
        if (sTransitionStructPtr->data[5] <= 80)
            r2 = 120, r1 = sTransitionStructPtr->data[2];
        var4 = (r1) | (r2 << 8);
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = var4;
        if (var != 0)
            break;
        var = sub_814A228(sTransitionStructPtr->data, 1, 1);
    }

    sTransitionStructPtr->data[5] -= 8;
    if (sTransitionStructPtr->data[5] <= 0)
    {
        sTransitionStructPtr->data[4] = 0;
        task->tState++;
    }
    else
    {
        while (sTransitionStructPtr->data[3] > sTransitionStructPtr->data[5])
        {
            gScanlineEffectRegBuffers[0][--sTransitionStructPtr->data[3]] = (r1) | (r2 << 8);
        }
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Clockwise_BlackFade_Func6(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], 0, 1, 1);
    do
    {
        s16 r2, r3;

        r2 = 120, r3 = sTransitionStructPtr->data[2];
        if (sTransitionStructPtr->data[2] >= 120)
            r2 = 0, r3 = 240;
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = (r3) | (r2 << 8);

    } while (!sub_814A228(sTransitionStructPtr->data, 1, 1));

    sTransitionStructPtr->data[4] += 16;
    if (sTransitionStructPtr->data[2] > 120)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Clockwise_BlackFade_Func7(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Clockwise_BlackFade));
    return FALSE;
}

static void VBlankCB_Phase2_Clockwise_BlackFade(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    REG_WIN0H = gScanlineEffectRegBuffers[1][0];
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, 0xA2400001);
}

static void Phase2Task_Ripple(u8 taskId)
{
    while (sPhase2_Ripple_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Ripple_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionStructPtr->field_16;
    }

    SetVBlankCallback(VBlankCB_Phase2_Ripple);
    SetHBlankCallback(HBlankCB_Phase2_Ripple);

    EnableInterrupts(INTR_FLAG_HBLANK);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Ripple_Func2(struct Task *task)
{
    u8 i;
    s16 r3;
    u16 r4, r8;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    r3 = task->tData2 >> 8;
    r4 = task->tData1;
    r8 = 384;
    task->tData1 += 0x400;
    if (task->tData2 <= 0x1FFF)
        task->tData2 += 0x180;

    for (i = 0; i < 160; i++, r4 += r8)
    {
        // todo: fix the asm
        s16 var = r4 >> 8;
        asm("");
        gScanlineEffectRegBuffers[0][i] = sTransitionStructPtr->field_16 + Sin(var, r3);
    }

    if (++task->tData3 == 81)
    {
        task->tData4++;
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 0x10, RGB_BLACK);
    }

    if (task->tData4 != 0 && !gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Phase2Task_Ripple));

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Phase2_Ripple(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
}

static void HBlankCB_Phase2_Ripple(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

static void Phase2Task_Wave(u8 taskId)
{
    while (sPhase2_Wave_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Wave_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0H = 240;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 242;
    }

    SetVBlankCallback(VBlankCB_Phase2_Wave);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Wave_Func2(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    bool8 nextFunc;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    toStore = gScanlineEffectRegBuffers[0];
    r5 = task->tData2;
    task->tData2 += 16;
    task->tData1 += 8;

    for (i = 0, nextFunc = TRUE; i < 160; i++, r5 += 4, toStore++)
    {
        s16 value = task->tData1 + Sin(r5, 40);
        if (value < 0)
            value = 0;
        if (value > 240)
            value = 240;
        *toStore = (value << 8) | (0xF1);
        if (value < 240)
            nextFunc = FALSE;
    }
    if (nextFunc)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Wave_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Wave));
    return FALSE;
}

static void VBlankCB_Phase2_Wave(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, 0xA2400001);
}

static void Phase2Task_Sidney(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_SIDNEY;
    Phase2Task_MugShotTransition(taskId);
}

static void Phase2Task_Phoebe(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_PHOEBE;
    Phase2Task_MugShotTransition(taskId);
}

static void Phase2Task_Glacia(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_GLACIA;
    Phase2Task_MugShotTransition(taskId);
}

static void Phase2Task_Drake(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_DRAKE;
    Phase2Task_MugShotTransition(taskId);
}

static void Phase2Task_Champion(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_CHAMPION;
    Phase2Task_MugShotTransition(taskId);
}

static void Phase2Task_MugShotTransition(u8 taskId)
{
    while (sPhase2_Mugshot_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Mugshot_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    ScanlineEffect_Clear();
    Mugshots_CreateOpponentPlayerSprites(task);

    task->tData1 = 0;
    task->tData2 = 1;
    task->tData3 = 239;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 62;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 0xF0F1;
    }

    SetVBlankCallback(VBlankCB0_Phase2_Mugshots);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func2(struct Task *task)
{
    s16 i, j;
    u16 *dst1, *dst2;
    const u16 *MugshotsMap;

    MugshotsMap = sMugshotsTilemap;
    sub_8149F58(&dst1, &dst2);
    CpuSet(sUnknown_085B9AF0, dst2, 0xF0);
    LoadPalette(sOpponentMugshotsPals[task->tMugshotId], 0xF0, 0x20);
    LoadPalette(sPlayerMugshotsPals[gSaveBlock2Ptr->playerGender], 0xFA, 0xC);

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++, MugshotsMap++)
        {
            dst1[i * 32 + j] = *MugshotsMap | 0xF000;
        }
    }

    EnableInterrupts(INTR_FLAG_HBLANK);

    SetHBlankCallback(HBlankCB_Phase2_Mugshots);
    task->tState++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func3(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    s16 value;
    s32 mergedValue;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    toStore = gScanlineEffectRegBuffers[0];
    r5 = task->tData1;
    task->tData1 += 0x10;

    for (i = 0; i < 80; i++, toStore++, r5 += 0x10)
    {
        value = task->tData2 + Sin(r5, 0x10);
        if (value < 0)
            value = 1;
        if (value > 0xF0)
            value = 0xF0;
        *toStore = value;
    }
    for (; i < 160; i++, toStore++, r5 += 0x10)
    {
        value = task->tData3 - Sin(r5, 0x10);
        if (value < 0)
            value = 0;
        if (value > 0xEF)
            value = 0xEF;
        *toStore = (value << 8) | (0xF0);
    }

    task->tData2 += 8;
    task->tData3 -= 8;
    if (task->tData2 > 0xF0)
        task->tData2 = 0xF0;
    if (task->tData3 < 0)
        task->tData3 = 0;
    mergedValue = *(s32*)(&task->tData2);
    if (mergedValue == 0xF0)
        task->tState++;

    sTransitionStructPtr->BG0HOFS_1 -= 8;
    sTransitionStructPtr->BG0HOFS_2 += 8;
    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func4(struct Task *task)
{
    u8 i;
    u16* toStore;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    for (i = 0, toStore = gScanlineEffectRegBuffers[0]; i < 160; i++, toStore++)
    {
        *toStore = 0xF0;
    }

    task->tState++;
    task->tData1 = 0;
    task->tData2 = 0;
    task->tData3 = 0;
    sTransitionStructPtr->BG0HOFS_1 -= 8;
    sTransitionStructPtr->BG0HOFS_2 += 8;

    sub_8148484(task->tOpponentSpriteId, 0);
    sub_8148484(task->tPlayerSpriteId, 1);
    sub_814849C(task->tOpponentSpriteId);

    PlaySE(SE_BT_START);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func5(struct Task *task)
{
    sTransitionStructPtr->BG0HOFS_1 -= 8;
    sTransitionStructPtr->BG0HOFS_2 += 8;
    if (sub_81484B8(task->tOpponentSpriteId))
    {
        task->tState++;
        sub_814849C(task->tPlayerSpriteId);
    }
    return FALSE;
}

static bool8 Phase2_Mugshot_Func6(struct Task *task)
{
    sTransitionStructPtr->BG0HOFS_1 -= 8;
    sTransitionStructPtr->BG0HOFS_2 += 8;
    if (sub_81484B8(task->tPlayerSpriteId))
    {
        sTransitionStructPtr->VBlank_DMA = FALSE;
        SetVBlankCallback(NULL);
        DmaStop(0);
        memset(gScanlineEffectRegBuffers[0], 0, 0x140);
        memset(gScanlineEffectRegBuffers[1], 0, 0x140);
        SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        task->tState++;
        task->tData3 = 0;
        task->tData4 = 0;
        sTransitionStructPtr->BLDCNT = 0xBF;
        SetVBlankCallback(VBlankCB1_Phase2_Mugshots);
    }
    return FALSE;
}

static bool8 Phase2_Mugshot_Func7(struct Task *task)
{
    bool32 r6;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    r6 = TRUE;
    sTransitionStructPtr->BG0HOFS_1 -= 8;
    sTransitionStructPtr->BG0HOFS_2 += 8;

    if (task->tData4 < 0x50)
        task->tData4 += 2;
    if (task->tData4 > 0x50)
        task->tData4 = 0x50;

    if (++task->tData3 & 1)
    {
        s16 i;
        for (i = 0, r6 = FALSE; i <= task->tData4; i++)
        {
            s16 index1 = 0x50 - i;
            s16 index2 = 0x50 + i;
            if (gScanlineEffectRegBuffers[0][index1] <= 15)
            {
                r6 = TRUE;
                gScanlineEffectRegBuffers[0][index1]++;
            }
            if (gScanlineEffectRegBuffers[0][index2] <= 15)
            {
                r6 = TRUE;
                gScanlineEffectRegBuffers[0][index2]++;
            }
        }
    }

    if (task->tData4 == 0x50 && !r6)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func8(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    BlendPalettes(-1, 0x10, 0x7FFF);
    sTransitionStructPtr->BLDCNT = 0xFF;
    task->tData3 = 0;

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Mugshot_Func9(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    task->tData3++;
    memset(gScanlineEffectRegBuffers[0], task->tData3, 0x140);
    if (task->tData3 > 15)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Mugshot_Func10(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

static void VBlankCB0_Phase2_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_BG0VOFS = sTransitionStructPtr->BG0VOFS;
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, 0xA2400001);
}

static void VBlankCB1_Phase2_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_BLDY, 0xA2400001);
}

static void HBlankCB_Phase2_Mugshots(void)
{
    if (REG_VCOUNT < 80)
        REG_BG0HOFS = sTransitionStructPtr->BG0HOFS_1;
    else
        REG_BG0HOFS = sTransitionStructPtr->BG0HOFS_2;
}

static void Mugshots_CreateOpponentPlayerSprites(struct Task *task)
{
    struct Sprite *opponentSprite, *playerSprite;

    s16 mugshotId = task->tMugshotId;
    task->tOpponentSpriteId = CreateTrainerSprite(sMugshotsTrainerPicIDsTable[mugshotId],
                                                     sMugshotsOpponentCoords[mugshotId][0] - 32,
                                                     sMugshotsOpponentCoords[mugshotId][1] + 42,
                                                     0, gDecompressionBuffer);
    task->tPlayerSpriteId = CreateTrainerSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 272, 106, 0, gDecompressionBuffer);

    opponentSprite = &gSprites[task->tOpponentSpriteId];
    playerSprite = &gSprites[task->tPlayerSpriteId];

    opponentSprite->callback = sub_8148380;
    playerSprite->callback = sub_8148380;

    opponentSprite->oam.affineMode = 3;
    playerSprite->oam.affineMode = 3;

    opponentSprite->oam.matrixNum = AllocOamMatrix();
    playerSprite->oam.matrixNum = AllocOamMatrix();

    opponentSprite->oam.shape = 1;
    playerSprite->oam.shape = 1;

    opponentSprite->oam.size = 3;
    playerSprite->oam.size = 3;

    CalcCenterToCornerVec(opponentSprite, 1, 3, 3);
    CalcCenterToCornerVec(playerSprite, 1, 3, 3);

    SetOamMatrixRotationScaling(opponentSprite->oam.matrixNum, sMugshotsOpponentRotationScales[mugshotId][0], sMugshotsOpponentRotationScales[mugshotId][1], 0);
    SetOamMatrixRotationScaling(playerSprite->oam.matrixNum, -512, 512, 0);
}

static void sub_8148380(struct Sprite *sprite)
{
    while (sUnknown_085C8C24[sprite->data[0]](sprite));
}

static bool8 sub_81483A8(struct Sprite *sprite)
{
    return FALSE;
}

static bool8 sub_81483AC(struct Sprite *sprite)
{
    s16 arr0[2];
    s16 arr1[2];

    memcpy(arr0, sUnknown_085C8C40, sizeof(sUnknown_085C8C40));
    memcpy(arr1, sUnknown_085C8C44, sizeof(sUnknown_085C8C44));

    sprite->data[0]++;
    sprite->data[1] = arr0[sprite->data[7]];
    sprite->data[2] = arr1[sprite->data[7]];
    return TRUE;
}

static bool8 sub_81483F8(struct Sprite *sprite)
{
    sprite->pos1.x += sprite->data[1];
    if (sprite->data[7] && sprite->pos1.x < 133)
        sprite->data[0]++;
    else if (!sprite->data[7] && sprite->pos1.x > 103)
        sprite->data[0]++;
    return FALSE;
}

static bool8 sub_814842C(struct Sprite *sprite)
{
    sprite->data[1] += sprite->data[2];
    sprite->pos1.x += sprite->data[1];
    if (sprite->data[1] == 0)
    {
        sprite->data[0]++;
        sprite->data[2] = -sprite->data[2];
        sprite->data[6] = 1;
    }
    return FALSE;
}

static bool8 sub_8148458(struct Sprite *sprite)
{
    sprite->data[1] += sprite->data[2];
    sprite->pos1.x += sprite->data[1];
    if (sprite->pos1.x < -31 || sprite->pos1.x > 271)
        sprite->data[0]++;
    return FALSE;
}

static void sub_8148484(s16 spriteId, s16 value)
{
    gSprites[spriteId].data[7] = value;
}

static void sub_814849C(s16 spriteId)
{
    gSprites[spriteId].data[0]++;
}

static s16 sub_81484B8(s16 spriteId)
{
    return gSprites[spriteId].data[6];
}

static void Phase2Task_Slice(u8 taskId)
{
    while (sPhase2_Slice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Slice_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    task->tData2 = 256;
    task->tData3 = 1;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0V = 160;
    sTransitionStructPtr->VBlank_DMA = FALSE;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionStructPtr->field_14;
        gScanlineEffectRegBuffers[1][160 + i] = 0xF0;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetGpuRegBits(REG_OFFSET_DISPSTAT, DISPSTAT_HBLANK_INTR);

    SetVBlankCallback(VBlankCB_Phase2_Slice);
    SetHBlankCallback(HBlankCB_Phase2_Slice);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Slice_Func2(struct Task *task)
{
    u16 i;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    task->tData1 += (task->tData2 >> 8);
    if (task->tData1 > 0xF0)
        task->tData1 = 0xF0;
    if (task->tData2 <= 0xFFF)
        task->tData2 += task->tData3;
    if (task->tData3 < 128)
        task->tData3 <<= 1; // multiplying by two

    for (i = 0; i < 160; i++)
    {
        u16 *storeLoc1 = &gScanlineEffectRegBuffers[0][i];
        u16 *storeLoc2 = &gScanlineEffectRegBuffers[0][i + 160];
        if (i & 1)
        {
            *storeLoc1 = sTransitionStructPtr->field_14 + task->tData1;
            *storeLoc2 = 0xF0 - task->tData1;
        }
        else
        {
            *storeLoc1 = sTransitionStructPtr->field_14 - task->tData1;
            *storeLoc2 = (task->tData1 << 8) | (0xF1);
        }
    }

    if (task->tData1 > 0xEF)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Slice_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Slice));
    return FALSE;
}

static void VBlankCB_Phase2_Slice(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 640);
    DmaSet(0, &gScanlineEffectRegBuffers[1][160], &REG_WIN0H, 0xA2400001);
}

static void HBlankCB_Phase2_Slice(void)
{
    if (REG_VCOUNT < 160)
    {
        u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
        REG_BG1HOFS = var;
        REG_BG2HOFS = var;
        REG_BG3HOFS = var;
    }
}

static void Phase2Task_ShredSplit(u8 taskId)
{
    while (sPhase2_ShredSplit_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_ShredSplit_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 0xA0; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionStructPtr->field_14;
        gScanlineEffectRegBuffers[1][0xA0 + i] = 0xF0;
        gScanlineEffectRegBuffers[0][i] = sTransitionStructPtr->field_14;
        gScanlineEffectRegBuffers[0][0xA0 + i] = 0xF0;
        gScanlineEffectRegBuffers[0][0x140 + i] = 0;
        gScanlineEffectRegBuffers[0][0x1E0 + i] = 0x100;
        gScanlineEffectRegBuffers[0][0x280 + i] = 1;
    }

    task->tData4 = 0;
    task->tData5 = 0;
    task->tData6 = 7;

    EnableInterrupts(INTR_FLAG_HBLANK);

    SetVBlankCallback(VBlankCB_Phase2_Slice);
    SetHBlankCallback(HBlankCB_Phase2_Slice);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_ShredSplit_Func2(struct Task *task)
{
    u16 i, j, k;
    u8 arr1[ARRAY_COUNT(gUnknown_085C8C64)];
    s16 arr2[ARRAY_COUNT(gUnknown_085C8C66)];
    u8 var;
    u16 *ptr4, *ptr3, *ptr1, *ptr2;
    s16 unkVar;

    memcpy(arr1, gUnknown_085C8C64, sizeof(arr1));
    memcpy(arr2, gUnknown_085C8C66, sizeof(arr2));

    sTransitionStructPtr->VBlank_DMA = FALSE;
    var = 0;

    for (i = 0; i <= task->tData5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                unkVar = (arr1[j]) + (arr2[k] * -(i) * 2);
                if (unkVar >= 0 && (unkVar != 79 || j != 1))
                {
                    ptr4 = &gScanlineEffectRegBuffers[0][unkVar + 320];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + 480];
                    ptr1 = &gScanlineEffectRegBuffers[0][unkVar + 640];
                    if (*ptr4 > 0xEF)
                    {
                        *ptr4 = 0xF0;
                        var++;
                    }
                    else
                    {
                        *ptr4 += (*ptr3 >> 8);
                        if (*ptr1 <= 0x7F)
                            *ptr1 *= 2;
                        if (*ptr3 <= 0xFFF)
                            *ptr3 += *ptr1;
                    }
                    ptr2 = &gScanlineEffectRegBuffers[0][unkVar];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + 160];
                    *ptr2 = sTransitionStructPtr->field_14 + *ptr4;
                    *ptr3 = 0xF0 - *ptr4;

                    if (i == 0)
                        break;
                }
            }
        }

        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                unkVar = (arr1[j] + 1) + (arr2[k] * -(i) * 2);
                if (unkVar <= 160 && (unkVar != 80 || j != 1))
                {
                    ptr4 = &gScanlineEffectRegBuffers[0][unkVar + 320];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + 480];
                    ptr1 = &gScanlineEffectRegBuffers[0][unkVar + 640];
                    if (*ptr4 > 0xEF)
                    {
                        *ptr4 = 0xF0;
                        var++;
                    }
                    else
                    {
                        *ptr4 += (*ptr3 >> 8);
                        if (*ptr1 <= 0x7F)
                            *ptr1 *= 2;
                        if (*ptr3 <= 0xFFF)
                            *ptr3 += *ptr1;
                    }
                    ptr2 = &gScanlineEffectRegBuffers[0][unkVar];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + 160];
                    *ptr2 = sTransitionStructPtr->field_14 - *ptr4;
                    *ptr3 = (*ptr4 << 8) | (0xF1);

                    if (i == 0)
                        break;
                }
            }
        }
    }

    if (--task->tData4 < 0)
        task->tData4 = 0;
    if (task->tData4 <= 0 && task->tData5 + 1 <= 20)
        task->tData4 = task->tData6, task->tData5++;
    if (var > 0x9F)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

// This function never increments the state counter, because the loop condition
// is always false, resulting in the game being stuck in an infinite loop.
// It's possible this transition is only partially
// done and the second part was left out.
static bool8 Phase2_ShredSplit_Func3(struct Task *task)
{
    u16 i;
    bool32 done = TRUE;
    u16 checkVar2 = 0xFF10;

    for (i = 0; i < 0xA0; i++)
    {
        if (gScanlineEffectRegBuffers[1][i] != 0xF0 && gScanlineEffectRegBuffers[1][i] != checkVar2)
            done = FALSE; // a break statement should be put here
    }

    if (done == TRUE)
        task->tState++;

    return FALSE;
}

static bool8 Phase2_ShredSplit_Func4(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_ShredSplit));
    return FALSE;
}

static void Phase2Task_Blackhole1(u8 taskId)
{
    while (sPhase2_Blackhole1_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_Blackhole2(u8 taskId)
{
    while (sPhase2_Blackhole2_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Blackhole_Func1(struct Task *task)
{
    s32 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->WININ = 0;
    sTransitionStructPtr->WINOUT = 63;
    sTransitionStructPtr->WIN0H = 240;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 0xA0; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 0;
    }

    SetVBlankCallback(VBlankCB1_Phase2_BigPokeball);

    task->tState++;
    task->tData1 = 1;
    task->tData2 = 0x100;
    task->tFuncState = 0;

    return FALSE;
}

static bool8 Phase2_Blackhole1_Func3(struct Task *task)
{
    if (task->tFuncState == 1)
    {
        DmaStop(0);
        SetVBlankCallback(NULL);
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        sTransitionStructPtr->VBlank_DMA = FALSE;
        if (task->tData2 < 0x400)
            task->tData2 += 0x80;
        if (task->tData1 < 0xA0)
            task->tData1 += (task->tData2 >> 8);
        if (task->tData1 > 0xA0)
            task->tData1 = 0xA0;
        sub_814A014(gScanlineEffectRegBuffers[0], 0x78, 0x50, task->tData1);
        if (task->tData1 == 0xA0)
        {
            task->tFuncState = 1;
            sub_8149F84();
        }
        else
        {
            sTransitionStructPtr->VBlank_DMA++;
        }
    }

    return FALSE;
}

static bool8 Phase2_Blackhole1_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->tFuncState == 0)
    {
        task->tFuncState++;
        task->tData1 = 0x30;
        task->tData6 = 0;
    }
    task->tData1 += gUnknown_085C8C80[task->tData6];
    task->tData6 = (task->tData6 + 1) % 2;
    sub_814A014(gScanlineEffectRegBuffers[0], 0x78, 0x50, task->tData1);
    if (task->tData1 < 9)
    {
        task->tState++;
        task->tFuncState = 0;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Blackhole2_Func2(struct Task *task)
{
    u16 index; // should be s16 I think
    s16 amplitude;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->tFuncState == 0)
    {
        task->tFuncState++;
        task->tData5 = 2;
        task->tData6 = 2;
    }
    if (task->tData1 > 0xA0)
        task->tData1 = 0xA0;

    sub_814A014(gScanlineEffectRegBuffers[0], 0x78, 0x50, task->tData1);
    if (task->tData1 == 0xA0)
    {
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }

    index = task->tData5;
    if ((task->tData5 & 0xFF) <= 128)
    {
        amplitude = task->tData6;
        task->tData5 += 8;
    }
    else
    {
        amplitude = task->tData6 - 1;
        task->tData5 += 16;
    }
    task->tData1 += Sin(index & 0xFF, amplitude);

    if (task->tData1 <= 0)
        task->tData1 = 1;
    if (task->tData5 > 0xFE)
        task->tData5 >>= 8, task->tData6++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static void Phase2Task_RectangularSpiral(u8 taskId)
{
    while (sPhase2_RectangularSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_RectangularSpiral_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuCopy16(sShrinkingBoxTileset, dst2, 0x20);
    CpuCopy16(sShrinkingBoxTileset + 0x70, dst2 + 0x20, 0x20);
    CpuFill16(0xF000, dst1, 0x800);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->tData3 = 1;
    task->tState++;

    sRectangularSpiralTransition[0].field_0 = 0;
    sRectangularSpiralTransition[0].field_2 = -1;
    sRectangularSpiralTransition[0].field_4 = 1;
    sRectangularSpiralTransition[0].field_6 = 308;
    sRectangularSpiralTransition[0].field_8 = 0;

    sRectangularSpiralTransition[1].field_0 = 0;
    sRectangularSpiralTransition[1].field_2 = -1;
    sRectangularSpiralTransition[1].field_4 = 1;
    sRectangularSpiralTransition[1].field_6 = 308;
    sRectangularSpiralTransition[1].field_8 = 0;

    sRectangularSpiralTransition[2].field_0 = 0;
    sRectangularSpiralTransition[2].field_2 = -3;
    sRectangularSpiralTransition[2].field_4 = 1;
    sRectangularSpiralTransition[2].field_6 = 307;
    sRectangularSpiralTransition[2].field_8 = 0;

    sRectangularSpiralTransition[3].field_0 = 0;
    sRectangularSpiralTransition[3].field_2 = -3;
    sRectangularSpiralTransition[3].field_4 = 1;
    sRectangularSpiralTransition[3].field_6 = 307;
    sRectangularSpiralTransition[3].field_8 = 0;

    return FALSE;
}

static bool8 Phase2_RectangularSpiral_Func2(struct Task *task)
{
    u16 *dst1, *dst2;
    u8 i;
    u16 j;
    bool32 done = TRUE;

    sub_8149F58(&dst1, &dst2);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < ARRAY_COUNT(sRectangularSpiralTransition); j++)
        {
            s16 var = 0, var2 = 0;
            s32 var3 = 0;

            if (sub_8149048(gUnknown_085C8D38[j / 2], &sRectangularSpiralTransition[j]))
            {
                u32 one;
                done = FALSE;
                var = sRectangularSpiralTransition[j].field_2;
                one = 1;
                if ((j & 1) == one)
                    var = 0x27D - var;

                var2 = var % 32;
                var3 = var / 32 * 32;

                dst1[var3 + var2] = 0xF002;
            }
        }
    }

    if (done == TRUE)
        task->tState++;
    return FALSE;
}

static bool8 Phase2_RectangularSpiral_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

static bool16 sub_8149048(const s16 * const *arg0, struct StructRectangularSpiral *arg1)
{
    const s16 *array = arg0[arg1->field_0];
    if (array[arg1->field_4] == -1)
        return FALSE;

    // ??
    sUnusedRectangularSpiralVar = array[0];
    sUnusedRectangularSpiralVar = array[1];
    sUnusedRectangularSpiralVar = array[2];
    sUnusedRectangularSpiralVar = array[3];

    switch (array[0])
    {
    case 1:
        arg1->field_2 += 0x1;
        break;
    case 2:
        arg1->field_2 -= 0x1;
        break;
    case 3:
        arg1->field_2 -= 0x20;
        break;
    case 4:
        arg1->field_2 += 0x20;
        break;
    }

    if (arg1->field_2 > 0x27F || array[arg1->field_4] == -1)
        return FALSE;

    if (arg1->field_8 == 0 && array[arg1->field_4] == -2)
    {
        arg1->field_8 = 1;
        arg1->field_4 = 1;
        arg1->field_2 = arg1->field_6;
        arg1->field_0 = 4;
    }

    if (arg1->field_2 == array[arg1->field_4])
    {
        (arg1->field_0)++;
        if (arg1->field_8 == 1)
        {
            if (arg1->field_0 > 7)
            {
                (arg1->field_4)++;
                (arg1->field_0) = 4;
            }
        }
        else
        {
            if (arg1->field_0 > 3)
            {
                (arg1->field_4)++;
                (arg1->field_0) = 0;
            }
        }
    }

    return TRUE;
}

static void Phase2Task_Groudon(u8 taskId)
{
    while (sPhase2_Groudon_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Groudon_Func3(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085BE51C, dst2);
    LZ77UnCompVram(gUnknown_085BEA88, dst1);

    task->tState++;
    task->tData1 = 0;
    return FALSE;
}

static bool8 Phase2_Groudon_Func4(struct Task *task)
{
    if (task->tData1 % 3 == 0)
    {
        u16 var = (task->tData1 % 30) / 3;
        LoadPalette(gUnknown_085BF0A0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->tData1 > 58)
    {
        task->tState++;
        task->tData1 = 0;
    }

    return FALSE;
}

static bool8 Phase2_Groudon_Func5(struct Task *task)
{
    if (task->tData1 % 5 == 0)
    {
        s16 var = task->tData1 / 5;
        LoadPalette(gUnknown_085BF2A0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->tData1 > 68)
    {
        task->tState++;
        task->tData1 = 0;
        task->tFrames = 30;
    }

    return FALSE;
}

static void Phase2Task_Rayquaza(u8 taskId)
{
    while (sPhase2_Rayquaza_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Rayquaza_Func3(struct Task *task)
{
    u16 *dst1, *dst2;
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    SetGpuReg(REG_OFFSET_BG0CNT, 0x9A08);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    CpuCopy16(gUnknown_085BF6A0, dst2, 0x2000);

    sTransitionStructPtr->field_20 = 0;
    task->tState++;
    LoadPalette(gUnknown_085BF4A0 + 0x50, 0xF0, 0x20);

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[0][i] = 0;
        gScanlineEffectRegBuffers[1][i] = 0x100;
    }

    SetVBlankCallback(VBlankCB_Phase2_Rayquaza);
    return FALSE;
}

static bool8 Phase2_Rayquaza_Func4(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuCopy16(gUnknown_085C6BE0, dst1, 0x1000);
    task->tState++;
    return FALSE;
}

static bool8 Phase2_Rayquaza_Func5(struct Task *task)
{
    if ((task->tData1 % 4) == 0)
    {
        u16 value = task->tData1 / 4;
        const u16 *palPtr = &gUnknown_085BF4A0[(value + 5) * 16];
        LoadPalette(palPtr, 0xF0, 0x20);
    }
    if (++task->tData1 > 40)
    {
        task->tState++;
        task->tData1 = 0;
    }

    return FALSE;
}

static bool8 Phase2_Rayquaza_Func6(struct Task *task)
{
    if (++task->tData1 > 20)
    {
        task->tState++;
        task->tData1 = 0;
        BeginNormalPaletteFade(0xFFFF8000, 2, 0, 0x10, RGB_BLACK);
    }

    return FALSE;
}

static bool8 Phase2_Rayquaza_Func7(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sTransitionStructPtr->field_20 = 1;
        task->tState++;
    }

    return FALSE;
}

static bool8 Phase2_Rayquaza_Func8(struct Task *task)
{
    BlendPalettes(0x00007FFF, 8, 0);
    BlendPalettes(0xFFFF8000, 0, 0);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_Rayquaza_Func9(struct Task *task)
{
    if ((task->tData1 % 3) == 0)
    {
        u16 value = task->tData1 / 3;
        const u16 *palPtr = &gUnknown_085BF4A0[(value + 0) * 16];
        LoadPalette(palPtr, 0xF0, 0x20);
    }
    if (++task->tData1 >= 40)
    {
        u16 i;

        sTransitionStructPtr->WININ = 0;
        sTransitionStructPtr->WINOUT = 63;
        sTransitionStructPtr->WIN0H = 240;
        sTransitionStructPtr->WIN0V = 160;

        for (i = 0; i < 160; i++)
        {
            gScanlineEffectRegBuffers[1][i] = 0;
        }

        SetVBlankCallback(VBlankCB1_Phase2_BigPokeball);
        task->tState++;
        task->tData2 = 0x100;
        task->tFuncState = 0;
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);
    }

    return FALSE;
}

static void VBlankCB_Phase2_Rayquaza(void)
{
    void *dmaSrc;

    DmaStop(0);
    VBlankCB_BattleTransition();

    if (sTransitionStructPtr->field_20 == 0)
        dmaSrc = gScanlineEffectRegBuffers[0];
    else if (sTransitionStructPtr->field_20 == 1)
        dmaSrc = gScanlineEffectRegBuffers[1];
    else
        dmaSrc = gScanlineEffectRegBuffers[0];

    DmaSet(0, dmaSrc, &REG_BG0VOFS, 0xA2400001);
}

static void Phase2Task_WhiteFade(u8 taskId)
{
    while (sPhase2_WhiteFade_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_WhiteFade_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->BLDCNT = 0xBF;
    sTransitionStructPtr->BLDY = 0;
    sTransitionStructPtr->WININ = 0x1E;
    sTransitionStructPtr->WINOUT = 0x3F;
    sTransitionStructPtr->WIN0V = 0xA0;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 0;
        gScanlineEffectRegBuffers[1][i + 160] = 0xF0;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetHBlankCallback(HBlankCB_Phase2_WhiteFade);
    SetVBlankCallback(VBlankCB0_Phase2_WhiteFade);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_WhiteFade_Func2(struct Task *task)
{
    s16 i, posY;
    s16 arr1[ARRAY_COUNT(sUnknown_085C8DA0)];
    struct Sprite *sprite;

    memcpy(arr1, sUnknown_085C8DA0, sizeof(sUnknown_085C8DA0));
    for (i = 0, posY = 0; i < 8; i++, posY += 0x14)
    {
        sprite = &gSprites[CreateInvisibleSprite(sub_8149864)];
        sprite->pos1.x = 0xF0;
        sprite->pos1.y = posY;
        sprite->data[5] = arr1[i];
    }
    sprite->data[6]++;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_WhiteFade_Func3(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = 0;
    if (sTransitionStructPtr->field_20 > 7)
    {
        BlendPalettes(-1, 0x10, 0x7FFF);
        task->tState++;
    }
    return FALSE;
}

static bool8 Phase2_WhiteFade_Func4(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = 0;

    DmaStop(0);
    SetVBlankCallback(0);
    SetHBlankCallback(0);

    sTransitionStructPtr->WIN0H = 0xF0;
    sTransitionStructPtr->BLDY = 0;
    sTransitionStructPtr->BLDCNT = 0xFF;
    sTransitionStructPtr->WININ = 0x3F;

    SetVBlankCallback(VBlankCB1_Phase2_WhiteFade);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_WhiteFade_Func5(struct Task *task)
{
   if (++sTransitionStructPtr->BLDY > 16)
   {
       sub_8149F84();
       DestroyTask(FindTaskIdByFunc(Phase2Task_WhiteFade));
   }
   return FALSE;
}

static void VBlankCB0_Phase2_WhiteFade(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 640);
    DmaSet(0, &gScanlineEffectRegBuffers[1][160], &REG_WIN0H, 0xA2400001);
}

static void VBlankCB1_Phase2_WhiteFade(void)
{
    VBlankCB_BattleTransition();
    REG_BLDY = sTransitionStructPtr->BLDY;
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0H = sTransitionStructPtr->WIN0H;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
}

static void HBlankCB_Phase2_WhiteFade(void)
{
    REG_BLDY = gScanlineEffectRegBuffers[1][REG_VCOUNT];
}

static void sub_8149864(struct Sprite *sprite)
{
    if (sprite->data[5])
    {
        sprite->data[5]--;
        if (sprite->data[6])
            sTransitionStructPtr->VBlank_DMA = 1;
    }
    else
    {
        u16 i;
        u16* ptr1 = &gScanlineEffectRegBuffers[0][sprite->pos1.y];
        u16* ptr2 = &gScanlineEffectRegBuffers[0][sprite->pos1.y + 160];
        for (i = 0; i < 20; i++)
        {
            ptr1[i] = sprite->data[0] >> 8;
            ptr2[i] = (u8)(sprite->pos1.x);
        }
        if (sprite->pos1.x == 0 && sprite->data[0] == 0x1000)
            sprite->data[1] = 1;

        sprite->pos1.x -= 16;
        sprite->data[0] += 0x80;

        if (sprite->pos1.x < 0)
            sprite->pos1.x = 0;
        if (sprite->data[0] > 0x1000)
            sprite->data[0] = 0x1000;

        if (sprite->data[6])
            sTransitionStructPtr->VBlank_DMA = 1;

        if (sprite->data[1])
        {
            if (sprite->data[6] == 0 || (sTransitionStructPtr->field_20 > 6 && sprite->data[2]++ > 7))
            {
                sTransitionStructPtr->field_20++;
                DestroySprite(sprite);
            }
        }
    }
}

static void Phase2Task_GridSquares(u8 taskId)
{
    while (sPhase2_GridSquares_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_GridSquares_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuSet(sShrinkingBoxTileset, dst2, 0x10);
    CpuFill16(0xF000, dst1, 0x800);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_GridSquares_Func2(struct Task *task)
{
    u16* dst1;

    if (task->tData1 == 0)
    {
        sub_8149F40(&dst1);
        task->tData1 = 3;
        task->tData2++;
        CpuSet(sShrinkingBoxTileset + (task->tData2 * 8), dst1, 0x10);
        if (task->tData2 > 0xD)
        {
            task->tState++;
            task->tData1 = 16;
        }
    }

    task->tData1--;
    return FALSE;
}

static bool8 Phase2_GridSquares_Func3(struct Task *task)
{
    if (--task->tData1 == 0)
    {
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(Phase2Task_GridSquares));
    }
    return FALSE;
}

static void Phase2Task_Shards(u8 taskId)
{
    while (sPhase2_Shards_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_Shards_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    ScanlineEffect_Clear();

    sTransitionStructPtr->WININ = 0x3F;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0V = 0xA0;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[0][i] = 0xF0;
    }

    CpuSet(gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 0xA0);
    SetVBlankCallback(VBlankCB_Phase2_Shards);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_Shards_Func2(struct Task *task)
{
    sub_814A1AC(sTransitionStructPtr->data,
                sUnknown_085C8DD0[task->tData1][0],
                sUnknown_085C8DD0[task->tData1][1],
                sUnknown_085C8DD0[task->tData1][2],
                sUnknown_085C8DD0[task->tData1][3],
                1, 1);
    task->tData2 = sUnknown_085C8DD0[task->tData1][4];
    task->tState++;
    return TRUE;
}

static bool8 Phase2_Shards_Func3(struct Task *task)
{
    s16 i;
    bool8 nextFunc;

    sTransitionStructPtr->VBlank_DMA = 0;

    for (i = 0, nextFunc = FALSE; i < 16; i++)
    {
        s16 r3 = gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] >> 8;
        s16 r4 = gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] & 0xFF;
        if (task->tData2 == 0)
        {
            if (r3 < sTransitionStructPtr->data[2])
                r3 = sTransitionStructPtr->data[2];
            if (r3 > r4)
                r3 = r4;
        }
        else
        {
            if (r4 > sTransitionStructPtr->data[2])
                r4 = sTransitionStructPtr->data[2];
            if (r4 <= r3)
                r4 = r3;
        }
        gScanlineEffectRegBuffers[0][sTransitionStructPtr->data[3]] = (r4) | (r3 << 8);
        if (nextFunc)
        {
            task->tState++;
            break;
        }
        else
            nextFunc = sub_814A228(sTransitionStructPtr->data, 1, 1);
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static bool8 Phase2_Shards_Func4(struct Task *task)
{
    if (++task->tData1 < 7)
    {
        task->tState++;
        task->tData3 = sUnknown_085C8E16[task->tData1 - 1];
        return TRUE;
    }
    else
    {
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(Phase2Task_Shards));
        return FALSE;
    }
}

static bool8 Phase2_Shards_Func5(struct Task *task)
{
    if (--task->tData3 == 0)
    {
        task->tState = 1;
        return TRUE;
    }
    else
        return FALSE;
}

static void VBlankCB_Phase2_Shards(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    REG_WIN0H = gScanlineEffectRegBuffers[1][0];
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, 0xA2400001);
}

// sub-task for phase2
#undef tData1
#undef tData2
#undef tData3
#undef tData4
#undef tData5
#undef tData6
#undef tFuncState
#undef tFrames
#undef tOpponentSpriteId
#undef tPlayerSpriteId
#undef tMugshotId

// sub-task for sub-task phase
#define tData1      data[1]
#define tData2      data[2]
#define tData3      data[3]
#define tData4      data[4]
#define tData5      data[5]
#define tData6      data[6]
#define tData7      data[7]

static void CreatePhase1Task(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4)
{
    u8 taskId = CreateTask(TransitionPhase1_Task_RunFuncs, 3);
    gTasks[taskId].tData1 = a0;
    gTasks[taskId].tData2 = a1;
    gTasks[taskId].tData3 = a2;
    gTasks[taskId].tData4 = a3;
    gTasks[taskId].tData5 = a4;
    gTasks[taskId].tData6 = a0;
}

static bool8 IsPhase1Done(void)
{
    if (FindTaskIdByFunc(TransitionPhase1_Task_RunFuncs) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

void TransitionPhase1_Task_RunFuncs(u8 taskId)
{
    while (sPhase1_TransitionAll_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase1_TransitionAll_Func1(struct Task *task)
{
    if (task->tData6 == 0 || --task->tData6 == 0)
    {
        task->tData6 = task->tData1;
        task->tData7 += task->tData4;
        if (task->tData7 > 16)
            task->tData7 = 16;
        BlendPalettes(-1, task->tData7, 0x2D6B);
    }
    if (task->tData7 > 15)
    {
        task->tState++;
        task->tData6 = task->tData2;
    }
    return FALSE;
}

static bool8 Phase1_TransitionAll_Func2(struct Task *task)
{
    if (task->tData6 == 0 || --task->tData6 == 0)
    {
        task->tData6 = task->tData2;
        task->tData7 -= task->tData5;
        if (task->tData7 < 0)
            task->tData7 = 0;
        BlendPalettes(-1, task->tData7, 0x2D6B);
    }
    if (task->tData7 == 0)
    {
        if (--task->tData3 == 0)
            DestroyTask(FindTaskIdByFunc(TransitionPhase1_Task_RunFuncs));
        else
        {
            task->tData6 = task->tData1;
            task->tState = 0;
        }
    }
    return FALSE;
}

#undef tData1
#undef tData2
#undef tData3
#undef tData4
#undef tData5
#undef tData6
#undef tData7

static void sub_8149F08(void)
{
    memset(sTransitionStructPtr, 0, sizeof(*sTransitionStructPtr));
    sub_8089C08(&sTransitionStructPtr->field_14, &sTransitionStructPtr->field_16);
}

static void VBlankCB_BattleTransition(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8149F40(u16 **a0)
{
    u16 reg, *vram;

    reg = REG_BG0CNT >> 2;
    reg <<= 0xE;
    vram = (u16*)(VRAM + reg);

    *a0 = vram;
}

void sub_8149F58(u16 **a0, u16 **a1)
{
    u16 reg0, reg1, *vram0, *vram1;

    reg0 = REG_BG0CNT >> 8;
    reg1 = REG_BG0CNT >> 2;

    reg0 <<= 0xB;
    reg1 <<= 0xE;

    vram0 = (u16*)(VRAM + reg0);
    *a0 = vram0;

    vram1 = (u16*)(VRAM + reg1);
    *a1 = vram1;
}

static void sub_8149F84(void)
{
    BlendPalettes(-1, 0x10, 0);
}

static void sub_8149F98(s16 *array, s16 sinAdd, s16 index, s16 indexIncrementer, s16 amplitude, s16 arrSize)
{
    u8 i;
    for (i = 0; arrSize > 0; arrSize--, i++, index += indexIncrementer)
    {
        array[i] = sinAdd + Sin(0xFF & index, amplitude);
    }
}

static void sub_814A014(u16 *array, s16 a1, s16 a2, s16 a3)
{
    s16 i;

    memset(array, 0xA, 160 * sizeof(s16));
    for (i = 0; i < 64; i++)
    {
        s16 sinResult, cosResult;
        s16 toStoreOrr, r2, r3, toStore, r7, r8;

        sinResult = Sin(i, a3);
        cosResult = Cos(i, a3);

        toStoreOrr = a1 - sinResult;
        toStore = a1 + sinResult;
        r7 = a2 - cosResult;
        r8 = a2 + cosResult;

        if (toStoreOrr < 0)
            toStoreOrr = 0;
        if (toStore > 0xF0)
            toStore = 0xF0;
        if (r7 < 0)
            r7 = 0;
        if (r8 > 0x9F)
            r8 = 0x9F;

        toStore |= (toStoreOrr << 8);
        array[r7] = toStore;
        array[r8] = toStore;

        cosResult = Cos(i + 1, a3);
        r3 = a2 - cosResult;
        r2 = a2 + cosResult;

        if (r3 < 0)
            r3 = 0;
        if (r2 > 0x9F)
            r2 = 0x9F;

        while (r7 > r3)
            array[--r7] = toStore;
        while (r7 < r3)
            array[++r7] = toStore;

        while (r8 > r2)
            array[--r8] = toStore;
        while (r8 < r2)
            array[++r8] = toStore;
    }
}

static void sub_814A1AC(s16 *data, s16 a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    data[0] = a1;
    data[1] = a2;
    data[2] = a1;
    data[3] = a2;
    data[4] = a3;
    data[5] = a4;
    data[6] = a5;
    data[7] = a6;
    data[8] = a3 - a1;
    if (data[8] < 0)
    {
        data[8] = -data[8];
        data[6] = -a5;
    }
    data[9] = a4 - a2;
    if (data[9] < 0)
    {
        data[9] = -data[9];
        data[7] = -a6;
    }
    data[10] = 0;
}

static bool8 sub_814A228(s16 *data, bool8 a1, bool8 a2)
{
    u8 var;
    if (data[8] > data[9])
    {
        data[2] += data[6];
        data[10] += data[9];
        if (data[10] > data[8])
        {
            data[3] += data[7];
            data[10] -= data[8];
        }
    }
    else
    {
        data[3] += data[7];
        data[10] += data[8];
        if (data[10] > data[9])
        {
            data[2] += data[6];
            data[10] -= data[9];
        }
    }
    var = 0;
    if ((data[6] > 0 && data[2] >= data[4]) || (data[6] < 0 && data[2] <= data[4]))
    {
        var++;
        if (a1)
            data[2] = data[4];
    }
    if ((data[7] > 0 && data[3] >= data[5]) || (data[7] < 0 && data[3] <= data[5]))
    {
        var++;
        if (a2)
            data[3] = data[5];
    }

    if (var == 2)
        return TRUE;
    else
        return FALSE;
}

// sub-task for phase2 of a couple of new transitions
#define tData1      data[1]
#define tData2      data[2]
#define tData3      data[3]
#define tData4      data[4]
#define tData5      data[5]
#define tData6      data[6]
#define tData7      data[7]

static bool8 Phase2_29_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_814669C(task);
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085C7C00, dst2);
    LoadPalette(gUnknown_085C7BE0, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

static bool8 Phase2_29_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_085C828C, dst1);
    sub_8149F98(gScanlineEffectRegBuffers[0], 0, task->tData4, 0x84, task->tData5, 160);

    task->tState++;
    return TRUE;
}

static void Phase2Task_29(u8 taskId)
{
    while (sPhase2_29_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_30(u8 taskId)
{
    while (sPhase2_30_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_30_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F08();
    ScanlineEffect_Clear();
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    task->tData2 = 0x2000;
    task->tData1 = 0x7FFF;
    task->tData5 = 0;
    task->tData6 = 16;
    task->tData7 = 2560;
    sTransitionStructPtr->BLDCNT = 0x3F41;
    sTransitionStructPtr->BLDALPHA = (task->tData6 << 8) | (task->tData5);
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_BLDALPHA = sTransitionStructPtr->BLDALPHA;
    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085C7C00, dst2);
    LoadPalette(gUnknown_085C7BE0, 0xF0, 0x20);
    sTransitionStructPtr->field_16 = 0;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_30_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_085C828C, dst1);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_30_Func3(struct Task *task)
{
    u8 i;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionStructPtr->field_16;
    }

    SetVBlankCallback(VBlankCB_Phase2_30);
    SetHBlankCallback(HBlankCB_Phase2_30);
    EnableInterrupts(INTR_FLAG_HBLANK);

    task->tState++;
    return TRUE;
}

static bool8 Phase2_30_Func4(struct Task *task)
{
    u8 i;
    u16 var6, amplitude, var8;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    amplitude = task->tData2 >> 8;
    var6 = task->tData1;
    var8 = 384;

    task->tData1 = var6 - task->tData7;

    if (task->tData3 >= 70)
    {
        if (task->tData2 - 384 >= 0)
            task->tData2 -= 384;
        else
            task->tData2 = 0;
    }

    if (task->tData3 >= 0 && task->tData3 % 3 == 0)
    {
        if (task->tData5 < 16)
            task->tData5++;
        else if (task->tData6 > 0)
            task->tData6--;

        sTransitionStructPtr->BLDALPHA = (task->tData6 << 8) | (task->tData5);
    }

    for (i = 0; i < 160; i++, var6 += var8)
    {
        s16 index = var6 / 256;
        asm("");
        gScanlineEffectRegBuffers[0][i] = sTransitionStructPtr->field_16 + Sin(index, amplitude);
    }

    if (++task->tData3 == 101)
    {
        task->tData4++;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    }

    if (task->tData4 != 0 && !gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Phase2Task_30));

    task->tData7 -= 17;
    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Phase2_30(void)
{
    VBlankCB_BattleTransition();
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_BLDALPHA = sTransitionStructPtr->BLDALPHA;

    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 320);
}

static void HBlankCB_Phase2_30(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG0VOFS = var;
}

static void Phase2Task_31(u8 taskId)
{
    while (sPhase2_31_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_33(u8 taskId)
{
    while (sPhase2_33_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Phase2Task_32(u8 taskId)
{
    while (sPhase2_32_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Phase2_31_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_085C8598, dst2);

    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect(0, 1, 0, 0, 1, 0x20, 0xF);
    FillBgTilemapBufferRect(0, 1, 0x1D, 0, 1, 0x20, 0xF);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(gUnknown_085C8578, 0xF0, 0x20);

    task->tData2 = 1;
    task->tData3 = 0;
    task->tData4 = 0;
    task->tData7 = 10;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_31_Func2(struct Task *task)
{
    CopyRectToBgTilemapBufferRect(0, gUnknown_085C8928, 0, 0, 4, 4, task->tData2, task->tData3, 4, 4, 0xF, 0, 0);
    CopyBgTilemapBufferToVram(0);

    task->tData2 += 4;
    if (++task->tData4 == 7)
    {
        task->tData2 = 1;
        task->tData3 += 4;
        task->tData4 = 0;
        if (task->tData3 > 19)
            task->tState++;
    }

    return FALSE;
}

static bool8 Phase2_31_Func3(struct Task *task)
{
    u8 i;
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    if (task->tData6++ >= task->tData7)
    {
        switch (task->tData5)
        {
        case 0:
            for (i = 250; i < 255; i++)
            {
                gPlttBufferUnfaded[i] = 0;
                gPlttBufferFaded[i] = 0;
            }
            break;
        case 1:
            BlendPalettes(0xFFFF7FFF, 0x10, 0);
            LZ77UnCompVram(gUnknown_085C86F4, dst2);
            break;
        case 2:
            LZ77UnCompVram(gUnknown_085C87F4, dst2);
            break;
        case 3:
            LZ77UnCompVram(gUnknown_085C88A4, dst2);
            break;
        default:
            FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
            CopyBgTilemapBufferToVram(0);
            task->tState++;
            return FALSE;
        }

        task->tData6 = 0;
        task->tData5++;
    }

    return FALSE;
}

static bool8 Phase2_33_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_085C8598, dst2);

    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect(0, 1, 0, 0, 1, 0x20, 0xF);
    FillBgTilemapBufferRect(0, 1, 0x1D, 0, 1, 0x20, 0xF);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(gUnknown_085C8578, 0xE0, 0x20);
    LoadPalette(gUnknown_085C8578, 0xF0, 0x20);
    BlendPalette(0xE0, 0x10, 8, 0);

    task->tData2 = 34;
    task->tData3 = 0;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_33_Func2(struct Task *task)
{
    u8 var = gUnknown_085C9A30[task->tData2];
    u8 varMod = var % 7;
    u8 varDiv = var / 7;
    CopyRectToBgTilemapBufferRect(0, &gUnknown_085C8928, 0, 0, 4, 4, 4 * varMod + 1, 4 * varDiv, 4, 4, 0xF, 0, 0);
    CopyBgTilemapBufferToVram(0);

    if (--task->tData2 < 0)
        task->tState++;
    return FALSE;
}

static bool8 Phase2_33_Func3(struct Task *task)
{
    BlendPalette(0xE0, 0x10, 3, 0);
    BlendPalettes(0xFFFF3FFF, 0x10, 0);

    task->tData2 = 0;
    task->tData3 = 0;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_33_Func4(struct Task *task)
{
    if ((task->tData3 ^= 1))
    {
        CopyRectToBgTilemapBufferRect(
        0,
        gUnknown_085C8928,
        0,
        0,
        4,
        4,
        4 * (gUnknown_085C9A30[task->tData2] % 7) + 1,
        4 * (gUnknown_085C9A30[task->tData2] / 7),
        4,
        4,
        0xE,
        0,
        0);
    }
    else
    {
        if (task->tData2 > 0)
        {
            FillBgTilemapBufferRect(
            0,
            1,
            4 * (gUnknown_085C9A30[task->tData2 - 1] % 7) + 1,
            4 * (gUnknown_085C9A30[task->tData2 - 1] / 7),
            4,
            4,
            0xF);
        }

        task->tData2++;
    }

    if (task->tData2 > 34)
        task->tState++;

    CopyBgTilemapBufferToVram(0);
    return FALSE;
}

static bool8 Phase2_31_33_Func5(struct Task *task)
{
    FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    BlendPalettes(0xFFFFFFFF, 0x10, 0);
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

// sub task for phase2 32
#define tSub32_X_delta  data[0]
#define tSub32_Y_delta  data[1]
#define tSub32_Bool     data[2]

static void sub_814ABE4(u8 taskId)
{
    if (!(gTasks[taskId].tSub32_Bool ^= 1))
    {
        SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_X);
        SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_Y);
        gBattle_BG0_X += gTasks[taskId].tSub32_X_delta;
        gBattle_BG0_Y += gTasks[taskId].tSub32_Y_delta;
    }
}

static bool8 Phase2_32_Func1(struct Task *task)
{
    u8 taskId = 0;
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_085C8598, dst2);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(gUnknown_085C8578, 0xF0, 0x20);

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_Y);

    task->tData2 = 0;
    taskId = CreateTask(sub_814ABE4, 1);
    switch (Random() % 4)
    {
    case 0:
        gTasks[taskId].tSub32_X_delta = 1;
        gTasks[taskId].tSub32_Y_delta = 1;
        break;
    case 1:
        gTasks[taskId].tSub32_X_delta = -1;
        gTasks[taskId].tSub32_Y_delta = -1;
        break;
    case 2:
        gTasks[taskId].tSub32_X_delta = 1;
        gTasks[taskId].tSub32_Y_delta = -1;
        break;
    default:
        gTasks[taskId].tSub32_X_delta = -1;
        gTasks[taskId].tSub32_Y_delta = 1;
        break;
    }

    task->tState++;
    return FALSE;
}

static bool8 Phase2_32_Func2(struct Task *task)
{
    u8 var = gUnknown_085C9A53[task->tData2];
    u8 varDiv = var / 8;
    u8 varAnd = var & 7;

    CopyRectToBgTilemapBufferRect(
    0,
    &gUnknown_085C8928,
    0,
    0,
    4,
    4,
    4 * varDiv + 1,
    4 * varAnd,
    4,
    4,
    0xF,
    0,
    0);
    CopyBgTilemapBufferToVram(0);

    if (++task->tData2 > 63)
        task->tState++;
    return 0;
}

static bool8 Phase2_32_Func3(struct Task *task)
{
    BlendPalettes(0xFFFF7FFF, 0x10, 0);

    task->tData2 = 0;

    task->tState++;
    return FALSE;
}

static bool8 Phase2_32_Func4(struct Task *task)
{
    u8 var = gUnknown_085C9A53[task->tData2];
    u8 varDiv = var / 8;
    u8 varAnd = var & 7;

    FillBgTilemapBufferRect(0, 1, 4 * varDiv + 1, 4 * varAnd, 4, 4, 0xF);
    CopyBgTilemapBufferToVram(0);

    if (++task->tData2 > 63)
    {
        DestroyTask(FindTaskIdByFunc(sub_814ABE4));
        task->tState++;
    }

    return FALSE;
}

#undef tSub32_X_delta
#undef tSub32_Y_delta
#undef tSub32_Bool

static bool8 Phase2_32_Func5(struct Task *task)
{
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_Y);

    FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    BlendPalettes(0xFFFFFFFF, 0x10, 0);

    DestroyTask(FindTaskIdByFunc(task->func));
    task->tState++; // UB: changing value of a destroyed task
    return FALSE;
}

#undef tData1
#undef tData2
#undef tData3
#undef tData4
#undef tData5
#undef tData6
#undef tData7

#include "global.h"
#include "battle_transition.h"
#include "unk_transition.h"
#include "main.h"
#include "overworld.h"
#include "task.h"
#include "palette.h"
#include "trig.h"
#include "field_effect.h"
#include "random.h"
#include "sprite.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "field_camera.h"
#include "unknown_task.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "decompress.h"

struct TransitionData
{
    vs8 VBlank_DMA;
    u16 WININ;
    u16 WINOUT;
    u16 field_6;
    u16 WIN0V;
    u16 field_A;
    u16 field_C;
    u16 BLDCNT;
    u16 BLDALPHA;
    u16 BLDY;
    s16 field_14;
    s16 field_16;
    s16 field_18;
    s16 field_1A;
    s16 field_1C;
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

extern u16 gUnknown_020393A8[];
extern u16 gUnknown_02038C28[][0x3C0];

extern void c2_exit_to_overworld_2_switch(void);
extern void sub_80AC3D0(void);
extern void dp12_8087EA4(void);

// this file's functions
void LaunchBattleTransitionTask(u8 transitionId);
void Task_BattleTransitionMain(u8 taskId);
void Phase1Task_TransitionAll(u8 taskId);
void Phase2Task_Blur(u8 taskId);
void Phase2Task_Swirl(u8 taskId);
void Phase2Task_Shuffle(u8 taskId);
void Phase2Task_BigPokeball(u8 taskId);
void Phase2Task_PokeballsTrail(u8 taskId);
void Phase2Task_Clockwise_BlackFade(u8 taskId);
void Phase2Task_Ripple(u8 taskId);
void Phase2Task_Wave(u8 taskId);
void Phase2Task_Slice(u8 taskId);
void Phase2Task_WhiteFade(u8 taskId);
void Phase2Task_GridSquares(u8 taskId);
void Phase2Task_Shards(u8 taskId);
void Phase2Task_Sydney(u8 taskId);
void Phase2Task_Phoebe(u8 taskId);
void Phase2Task_Glacia(u8 taskId);
void Phase2Task_Drake(u8 taskId);
void Phase2Task_Champion(u8 taskId);
void Phase2Task_Aqua(u8 taskId);
void Phase2Task_Magma(u8 taskId);
void Phase2Task_Regice(u8 taskId);
void Phase2Task_Registeel(u8 taskId);
void Phase2Task_Regirock(u8 taskId);
void Phase2Task_Kyogre(u8 taskId);
void Phase2Task_Groudon(u8 taskId);
void Phase2Task_Rayquaza(u8 taskId);
void Phase2Task_25(u8 taskId);
void Phase2Task_Blackhole1(u8 taskId);
void Phase2Task_Blackhole2(u8 taskId);
void Phase2Task_RectangularSpiral(u8 taskId);
void Phase2Task_29(u8 taskId);
void Phase2Task_30(u8 taskId);
void Phase2Task_31(u8 taskId);
void Phase2Task_32(u8 taskId);
void Phase2Task_33(u8 taskId);
void VBlankCB_BattleTransition(void);
void VBlankCB_Phase2_Swirl(void);
void HBlankCB_Phase2_Swirl(void);
void VBlankCB_Phase2_Shuffle(void);
void HBlankCB_Phase2_Shuffle(void);
void VBlankCB0_Phase2_BigPokeball(void);
void VBlankCB1_Phase2_BigPokeball(void);
void VBlankCB_Phase2_Clockwise_BlackFade(void);
void VBlankCB_Phase2_Ripple(void);
void HBlankCB_Phase2_Ripple(void);
void VBlankCB_Phase2_Wave(void);
void VBlankCB_Phase2_Slice(void);
void HBlankCB_Phase2_Slice(void);
void VBlankCB0_Phase2_WhiteFade(void);
void VBlankCB1_Phase2_WhiteFade(void);
void HBlankCB_Phase2_WhiteFade(void);
void VBlankCB_Phase2_Shards(void);
bool8 Phase2_Blur_Func1(struct Task *task);
bool8 Phase2_Blur_Func2(struct Task *task);
bool8 Phase2_Blur_Func3(struct Task *task);
bool8 Phase2_Swirl_Func1(struct Task *task);
bool8 Phase2_Swirl_Func2(struct Task *task);
bool8 Phase2_Shuffle_Func1(struct Task *task);
bool8 Phase2_Shuffle_Func2(struct Task *task);
bool8 Phase2_Aqua_Func1(struct Task *task);
bool8 Phase2_Aqua_Func2(struct Task *task);
bool8 Phase2_Magma_Func1(struct Task *task);
bool8 Phase2_Magma_Func2(struct Task *task);
bool8 Phase2_FramesCountdown(struct Task *task);
bool8 Phase2_Regi_Func1(struct Task *task);
bool8 Phase2_Regice_Func2(struct Task *task);
bool8 Phase2_Registeel_Func2(struct Task *task);
bool8 Phase2_Regirock_Func2(struct Task *task);
bool8 Phase2_WeatherTrio_Func1(struct Task *task);
bool8 Phase2_WaitPaletteFade(struct Task *task);
bool8 Phase2_Kyogre_Func3(struct Task *task);
bool8 Phase2_Kyogre_Func4(struct Task *task);
bool8 Phase2_Kyogre_Func5(struct Task *task);
bool8 Phase2_Groudon_Func3(struct Task *task);
bool8 Phase2_Groudon_Func4(struct Task *task);
bool8 Phase2_Groudon_Func5(struct Task *task);
bool8 Phase2_WeatherDuo_Func6(struct Task *task);
bool8 Phase2_WeatherDuo_Func7(struct Task *task);
bool8 Phase2_BigPokeball_Func1(struct Task *task);
bool8 Phase2_BigPokeball_Func2(struct Task *task);
bool8 Phase2_BigPokeball_Func3(struct Task *task);
bool8 Phase2_BigPokeball_Func4(struct Task *task);
bool8 Phase2_BigPokeball_Func5(struct Task *task);
bool8 Phase2_BigPokeball_Func6(struct Task *task);
bool8 Phase2_PokeballsTrail_Func1(struct Task *task);
bool8 Phase2_PokeballsTrail_Func2(struct Task *task);
bool8 Phase2_PokeballsTrail_Func3(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func1(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func2(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func3(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func4(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func5(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func6(struct Task *task);
bool8 Phase2_Clockwise_BlackFade_Func7(struct Task *task);
bool8 Phase2_Ripple_Func1(struct Task *task);
bool8 Phase2_Ripple_Func2(struct Task *task);
bool8 Phase2_Wave_Func1(struct Task *task);
bool8 Phase2_Wave_Func2(struct Task *task);
bool8 Phase2_Wave_Func3(struct Task *task);
bool8 Phase2_Slice_Func1(struct Task *task);
bool8 Phase2_Slice_Func2(struct Task *task);
bool8 Phase2_Slice_Func3(struct Task *task);
bool8 Phase2_WhiteFade_Func1(struct Task *task);
bool8 Phase2_WhiteFade_Func2(struct Task *task);
bool8 Phase2_WhiteFade_Func3(struct Task *task);
bool8 Phase2_WhiteFade_Func4(struct Task *task);
bool8 Phase2_WhiteFade_Func5(struct Task *task);
bool8 Phase2_GridSquares_Func1(struct Task *task);
bool8 Phase2_GridSquares_Func2(struct Task *task);
bool8 Phase2_GridSquares_Func3(struct Task *task);
bool8 Phase2_Shards_Func1(struct Task *task);
bool8 Phase2_Shards_Func2(struct Task *task);
bool8 Phase2_Shards_Func3(struct Task *task);
bool8 Phase2_Shards_Func4(struct Task *task);
bool8 Phase2_Shards_Func5(struct Task *task);
bool8 Phase2_25_Func1(struct Task *task);
bool8 Phase2_25_Func2(struct Task *task);
bool8 Phase2_25_Func3(struct Task *task);
bool8 Phase2_25_Func4(struct Task *task);
bool8 Phase2_Blackhole_Func1(struct Task *task);
bool8 Phase2_Blackhole1_Func2(struct Task *task);
bool8 Phase2_Blackhole1_Func3(struct Task *task);
bool8 Phase2_Blackhole2_Func2(struct Task *task);
bool8 Phase2_RectangularSpiral_Func1(struct Task *task);
bool8 Phase2_RectangularSpiral_Func2(struct Task *task);
bool8 Phase2_RectangularSpiral_Func3(struct Task *task);
bool8 Phase2_Mugshot_Func1(struct Task *task);
bool8 Phase2_Mugshot_Func2(struct Task *task);
bool8 Phase2_Mugshot_Func3(struct Task *task);
bool8 Phase2_Mugshot_Func4(struct Task *task);
bool8 Phase2_Mugshot_Func5(struct Task *task);
bool8 Phase2_Mugshot_Func6(struct Task *task);
bool8 Phase2_Mugshot_Func7(struct Task *task);
bool8 Phase2_Mugshot_Func8(struct Task *task);
bool8 Phase2_Mugshot_Func9(struct Task *task);
bool8 Phase2_Mugshot_Func10(struct Task *task);
void Phase2Task_MugShotTransition(u8 taskId);
void Mugshots_CreateOpponentPlayerSprites(struct Task *task);
void VBlankCB0_Phase2_Mugshots(void);
void VBlankCB1_Phase2_Mugshots(void);
void HBlankCB_Phase2_Mugshots(void);
bool8 Transition_Phase1(struct Task *task);
bool8 Transition_WaitForPhase1(struct Task *task);
bool8 Transition_Phase2(struct Task *task);
bool8 Transition_WaitForPhase2(struct Task *task);
void sub_8149F08(void);
void sub_8149F84(void);
void CreatePhase1Task(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4);
void sub_814A014(u16 *a0, s16 a1, s16 a2, s16 a3);
void sub_8149F98(s16 *array, s16 sinAdd, s16 index, s16 indexIncrementer, s16 amplitude, s16 arrSize);
void sub_8149F58(u16 **a0, u16 **a1);
void sub_814A1AC(s16 *a0, s16 a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6);
bool8 sub_814A228(s16 *a0, bool8 a1, bool8 a2);
void sub_8148484(s16 spriteId, s16 value);
void sub_814849C(s16 spriteId);
s16 sub_81484B8(s16 spriteId);
bool8 IsPhase1Done(void);
bool16 sub_8149048(const s16 * const *arg0, struct StructRectangularSpiral *arg1);
void sub_814713C(struct Sprite *sprite);
void sub_8148380(struct Sprite *sprite);
bool8 sub_81483A8(struct Sprite *sprite);
bool8 sub_81483AC(struct Sprite *sprite);
bool8 sub_81483F8(struct Sprite *sprite);
bool8 sub_814842C(struct Sprite *sprite);
bool8 sub_8148458(struct Sprite *sprite);

// iwram bss vars
IWRAM_DATA static s16 sUnusedRectangularSpiralVar;
IWRAM_DATA static u8 sTestingTransitionId;
IWRAM_DATA static u8 sTestingTransitionState;
IWRAM_DATA static struct StructRectangularSpiral sRectangularSpiralTransition[4];

// ewram vars
EWRAM_DATA struct TransitionData *sTransitionStructPtr = NULL;

// const rom data
const u32 sBigPokeball_Tileset[] = INCBIN_U32("graphics/battle_transitions/big_pokeball.4bpp");
const u32 sPokeballTrail_Tileset[] = INCBIN_U32("graphics/battle_transitions/pokeball_trail.4bpp");
const u32 sSpriteImage_85B98F0[] = INCBIN_U32("graphics/battle_transitions/pokeball.4bpp");
const u32 sUnknown_085B9AF0[] = INCBIN_U32("graphics/battle_transitions/elite_four_bg.4bpp");
const u32 sSpriteImage_85B9CD0[] = INCBIN_U32("graphics/battle_transitions/unused_brendan.4bpp");
const u32 sSpriteImage_85BA4D0[] = INCBIN_U32("graphics/battle_transitions/unused_lass.4bpp");
const u32 sShrinkingBoxTileset[] = INCBIN_U32("graphics/battle_transitions/shrinking_box.4bpp");
const u32 sEvilTeam_Palette[] = INCBIN_U32("graphics/battle_transitions/evil_team.gbapal");
const u32 sTeamAqua_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_aqua.4bpp.lz");
const u32 sTeamAqua_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_aqua.bin.lz");
const u32 sTeamMagma_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_magma.4bpp.lz");
const u32 sTeamMagma_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_magma.bin.lz");
const u32 gUnknown_085BBC14[] = INCBIN_U32("graphics/battle_transitions/85BBC14.4bpp");
const u32 gUnknown_085BC2B4[] = INCBIN_U32("graphics/battle_transitions/85BC2B4.gbapal");
const u32 gUnknown_085BC2D4[] = INCBIN_U32("graphics/battle_transitions/85BC2D4.gbapal");
const u32 gUnknown_085BC2F4[] = INCBIN_U32("graphics/battle_transitions/85BC2F4.gbapal");
const u32 gUnknown_085BC314[] = INCBIN_U32("graphics/battle_transitions/85BC314.bin");
const u32 gUnknown_085BCB14[] = INCBIN_U32("graphics/battle_transitions/85BCB14.bin");
const u32 gUnknown_085BD314[] = INCBIN_U32("graphics/battle_transitions/85BD314.bin");
const u16 gUnknown_085BDB14[] = INCBIN_U16("graphics/battle_transitions/85BDB14.gbapal");
const u32 gUnknown_085BDB34[] = INCBIN_U32("graphics/battle_transitions/kyogre.4bpp.lz");
const u32 gUnknown_085BE1E8[] = INCBIN_U32("graphics/battle_transitions/kyogre.bin.lz");
const u32 gUnknown_085BE51C[] = INCBIN_U32("graphics/battle_transitions/groudon.4bpp.lz");
const u32 gUnknown_085BEA88[] = INCBIN_U32("graphics/battle_transitions/groudon.bin.lz");
const u16 gUnknown_085BEDA0[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt1.gbapal");
const u16 gUnknown_085BEEE0[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt2.gbapal");
const u16 gUnknown_085BF0A0[] = INCBIN_U16("graphics/battle_transitions/groudon_pt1.gbapal");
const u16 gUnknown_085BF2A0[] = INCBIN_U16("graphics/battle_transitions/groudon_pt2.gbapal");
const u16 gUnknown_085BF4A0[] = INCBIN_U16("graphics/battle_transitions/rayquaza.gbapal");
const u32 gUnknown_085BF6A0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.4bpp");
const u32 gUnknown_085C6BE0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.bin");
const u32 gUnknown_085C7BE0[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.gbapal");
const u32 gUnknown_085C7C00[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.4bpp.lz");
const u32 gUnknown_085C828C[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.bin.lz");
const u32 gUnknown_085C8578[] = INCBIN_U32("graphics/battle_transitions/frontier_squares_blanktiles.gbapal");
const u32 gUnknown_085C8598[] = INCBIN_U32("graphics/battle_transitions/frontier_square_1.4bpp.lz");
const u32 gUnknown_085C86F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_2.4bpp.lz");
const u32 gUnknown_085C87F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_3.4bpp.lz");
const u32 gUnknown_085C88A4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_4.4bpp.lz");
const u32 gUnknown_085C8928[] = INCBIN_U32("graphics/battle_transitions/frontier_squares.bin");

const TaskFunc sPhase1_Tasks[B_TRANSITION_COUNT] =
{
    [0 ... B_TRANSITION_COUNT - 1] = &Phase1Task_TransitionAll
};

const TaskFunc sPhase2_Tasks[B_TRANSITION_COUNT] =
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
    Phase2Task_Sydney,                      // 12
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
    Phase2Task_25,                          // 25
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

const TransitionStateFunc sMainTransitionPhases[] =
{
    &Transition_Phase1,
    &Transition_WaitForPhase1,
    &Transition_Phase2,
    &Transition_WaitForPhase2
};

const TransitionStateFunc sPhase2_Blur_Funcs[] =
{
    Phase2_Blur_Func1,
    Phase2_Blur_Func2,
    Phase2_Blur_Func3
};

const TransitionStateFunc sPhase2_Swirl_Funcs[] =
{
    Phase2_Swirl_Func1,
    Phase2_Swirl_Func2,
};

const TransitionStateFunc sPhase2_Shuffle_Funcs[] =
{
    Phase2_Shuffle_Func1,
    Phase2_Shuffle_Func2,
};

const TransitionStateFunc sPhase2_Aqua_Funcs[] =
{
    Phase2_Aqua_Func1,
    Phase2_Aqua_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_FramesCountdown,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_Magma_Funcs[] =
{
    Phase2_Magma_Func1,
    Phase2_Magma_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_FramesCountdown,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_BigPokeball_Funcs[] =
{
    Phase2_BigPokeball_Func1,
    Phase2_BigPokeball_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_Regice_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Regice_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_Registeel_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Registeel_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_Regirock_Funcs[] =
{
    Phase2_Regi_Func1,
    Phase2_Regirock_Func2,
    Phase2_BigPokeball_Func3,
    Phase2_BigPokeball_Func4,
    Phase2_BigPokeball_Func5,
    Phase2_BigPokeball_Func6
};

const TransitionStateFunc sPhase2_Kyogre_Funcs[] =
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

const TransitionStateFunc sPhase2_PokeballsTrail_Funcs[] =
{
    Phase2_PokeballsTrail_Func1,
    Phase2_PokeballsTrail_Func2,
    Phase2_PokeballsTrail_Func3
};

const s16 sUnknown_085C8B88[2] = {-16, 256};
const s16 sUnknown_085C8B8C[5] = {0, 32, 64, 18, 48};
const s16 sUnknown_085C8B96[2] = {8, -8};

const TransitionStateFunc sPhase2_Clockwise_BlackFade_Funcs[] =
{
    Phase2_Clockwise_BlackFade_Func1,
    Phase2_Clockwise_BlackFade_Func2,
    Phase2_Clockwise_BlackFade_Func3,
    Phase2_Clockwise_BlackFade_Func4,
    Phase2_Clockwise_BlackFade_Func5,
    Phase2_Clockwise_BlackFade_Func6,
    Phase2_Clockwise_BlackFade_Func7
};

const TransitionStateFunc sPhase2_Ripple_Funcs[] =
{
    Phase2_Ripple_Func1,
    Phase2_Ripple_Func2
};

const TransitionStateFunc sPhase2_Wave_Funcs[] =
{
    Phase2_Wave_Func1,
    Phase2_Wave_Func2,
    Phase2_Wave_Func3
};

const TransitionStateFunc sPhase2_Mugshot_Funcs[] =
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

const u8 sMugshotsTrainerPicIDsTable[MUGSHOTS_COUNT] =
{
    TRAINER_PIC_ELITE_FOUR_SIDNEY,
    TRAINER_PIC_ELITE_FOUR_PHOEBE,
    TRAINER_PIC_ELITE_FOUR_GLACIA,
    TRAINER_PIC_ELITE_FOUR_DRAKE,
    TRAINER_PIC_CHAMPION_WALLACE
};
const s16 sMugshotsOpponentRotationScales[MUGSHOTS_COUNT][2] =
{
    {0x200, 0x200},
    {0x200, 0x200},
    {0x1B0, 0x1B0},
    {0x1A0, 0x1A0},
    {0x188, 0x188},
};
const s16 sMugshotsOpponentCoords[MUGSHOTS_COUNT][2] =
{
    {0,     0},
    {0,     0},
    {-4,    4},
    {0,     5},
    {-8,    7},
};

const TransitionSpriteCallback sUnknown_085C8C24[] =
{
    sub_81483A8,
    sub_81483AC,
    sub_81483F8,
    sub_814842C,
    sub_81483A8,
    sub_8148458,
    sub_81483A8
};

const s16 sUnknown_085C8C40[2] = {12, -12};
const s16 sUnknown_085C8C44[2] = {-1, 1};

const TransitionStateFunc sPhase2_Slice_Funcs[] =
{
    Phase2_Slice_Func1,
    Phase2_Slice_Func2,
    Phase2_Slice_Func3
};

const TransitionStateFunc sPhase2_25_Funcs[] =
{
    Phase2_25_Func1,
    Phase2_25_Func2,
    Phase2_25_Func3,
    Phase2_25_Func4
};

const u8 gUnknown_085C8C64[] = {39, 119};
const s16 gUnknown_085C8C66[] = {1, -1};

const TransitionStateFunc sPhase2_Blackhole1_Funcs[] =
{
    Phase2_Blackhole_Func1,
    Phase2_Blackhole1_Func2,
    Phase2_Blackhole1_Func3
};

const TransitionStateFunc sPhase2_Blackhole2_Funcs[] =
{
    Phase2_Blackhole_Func1,
    Phase2_Blackhole2_Func2
};

const s16 gUnknown_085C8C80[] = {-6, 4};

const TransitionStateFunc sPhase2_RectangularSpiral_Funcs[] =
{
    Phase2_RectangularSpiral_Func1,
    Phase2_RectangularSpiral_Func2,
    Phase2_RectangularSpiral_Func3
};

const s16 gUnknown_085C8C90[] = {1, 27, 275, -1};
const s16 gUnknown_085C8C98[] = {2, 486, -1};
const s16 gUnknown_085C8C9E[] = {3, 262, -1};
const s16 gUnknown_085C8CA4[] = {4, 507, -2};
const s16 gUnknown_085C8CAA[] = {1, 213, -1};
const s16 gUnknown_085C8CB0[] = {2, 548, -2};
const s16 gUnknown_085C8CB6[] = {3, 196, -1};
const s16 gUnknown_085C8CBC[] = {4, 573, 309, -1};
const s16 gUnknown_085C8CC4[] = {1, 474, -1};
const s16 gUnknown_085C8CCA[] = {2, 295, 32, -1};
const s16 gUnknown_085C8CD2[] = {3, 58, -1};
const s16 gUnknown_085C8CD8[] = {4, 455, -1};
const s16 gUnknown_085C8CDE[] = {1, 540, -1};
const s16 gUnknown_085C8CE4[] = {2, 229, -1};
const s16 gUnknown_085C8CEA[] = {3, 244, 28, -1};
const s16 gUnknown_085C8CF2[] = {4, 517, -1};

const s16 *const gUnknown_085C8CF8[] =
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

const s16 *const gUnknown_085C8D18[] =
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

const s16 *const *const gUnknown_085C8D38[] =
{
	gUnknown_085C8CF8,
	gUnknown_085C8D18
};

const TransitionStateFunc sPhase2_Groudon_Funcs[] =
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

extern const u16 gFieldEffectObjectPalette10[];
extern const u16 sBigPokeball_Tilemap[];
extern const u16 sMugshotsTilemap[];
extern const struct SpriteTemplate gUnknown_085C8E68;
extern const u16 *const sOpponentMugshotsPals[MUGSHOTS_COUNT];
extern const u16 *const sPlayerMugshotsPals[2];

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
            SetMainCallback2(c2_exit_to_overworld_2_switch);
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

// main task that launches sub-tasks for phase1 and phase2
#define tState          data[0]
#define tTransitionID   data[1]
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

void LaunchBattleTransitionTask(u8 transitionId)
{
    u8 taskId = CreateTask(Task_BattleTransitionMain, 2);
    gTasks[taskId].tTransitionID = transitionId;
    sTransitionStructPtr = AllocZeroed(sizeof(*sTransitionStructPtr));
}

void Task_BattleTransitionMain(u8 taskId)
{
    while (sMainTransitionPhases[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Transition_Phase1(struct Task *task)
{
    sub_80AC3D0();
    CpuCopy32(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    if (sPhase1_Tasks[task->tTransitionID] != NULL)
    {
        CreateTask(sPhase1_Tasks[task->tTransitionID], 4);
        task->tState++;
        return FALSE;
    }
    else
    {
        task->tState = 2;
        return TRUE;
    }
}

bool8 Transition_WaitForPhase1(struct Task *task)
{
    if (FindTaskIdByFunc(sPhase1_Tasks[task->tTransitionID]) == 0xFF)
    {
        task->tState++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 Transition_Phase2(struct Task *task)
{
    CreateTask(sPhase2_Tasks[task->tTransitionID], 0);
    task->tState++;
    return FALSE;
}

bool8 Transition_WaitForPhase2(struct Task *task)
{
    task->tTransitionDone = FALSE;
    if (FindTaskIdByFunc(sPhase2_Tasks[task->tTransitionID]) == 0xFF)
        task->tTransitionDone = TRUE;
    return FALSE;
}

#undef tState
#undef tTransitionID
#undef tTransitionDone

// sub-task for phase1
#define tState          data[0]

void Phase1Task_TransitionAll(u8 taskId)
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

#undef tState

// sub-task for phase2
#define tState              data[0]
#define tFrames             data[8]
#define tOpponentSpriteId   data[13]
#define tPlayerSpriteId     data[14]
#define tMugshotId          data[15]

void Phase2Task_Blur(u8 taskId)
{
    while (sPhase2_Blur_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Blur_Func1(struct Task *task)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG3CNT, BGCNT_MOSAIC);
    task->tState++;
    return TRUE;
}

bool8 Phase2_Blur_Func2(struct Task *task)
{
    if (task->data[1] != 0)
    {
        task->data[1]--;
    }
    else
    {
        task->data[1] = 4;
        if (++task->data[2] == 10)
            BeginNormalPaletteFade(-1, -1, 0, 0x10, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, (task->data[2] & 15) * 17);
        if (task->data[2] > 14)
            task->tState++;
    }
    return FALSE;
}

bool8 Phase2_Blur_Func3(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Phase2Task_Blur);
        DestroyTask(taskId);
    }
    return FALSE;
}

void Phase2Task_Swirl(u8 taskId)
{
    while (sPhase2_Swirl_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Swirl_Func1(struct Task *task)
{
    sub_8149F08();
    dp12_8087EA4();
    BeginNormalPaletteFade(-1, 4, 0, 0x10, 0);
    sub_8149F98(gUnknown_020393A8, sTransitionStructPtr->field_14, 0, 2, 0, 160);

    SetVBlankCallback(VBlankCB_Phase2_Swirl);
    SetHBlankCallback(HBlankCB_Phase2_Swirl);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Swirl_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    task->data[1] += 4;
    task->data[2] += 8;

    sub_8149F98(gUnknown_02038C28[0], sTransitionStructPtr->field_14, task->data[1], 2, task->data[2], 160);

    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Phase2Task_Swirl);
        DestroyTask(taskId);
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

void VBlankCB_Phase2_Swirl(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
}

void HBlankCB_Phase2_Swirl(void)
{
    u16 var = gUnknown_02038C28[1][REG_VCOUNT];
    REG_BG1HOFS = var;
    REG_BG2HOFS = var;
    REG_BG3HOFS = var;
}

void Phase2Task_Shuffle(u8 taskId)
{
    while (sPhase2_Shuffle_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Shuffle_Func1(struct Task *task)
{
    sub_8149F08();
    dp12_8087EA4();

    BeginNormalPaletteFade(-1, 4, 0, 0x10, 0);
    memset(gUnknown_020393A8, sTransitionStructPtr->field_16, 0x140);

    SetVBlankCallback(VBlankCB_Phase2_Shuffle);
    SetHBlankCallback(HBlankCB_Phase2_Shuffle);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Shuffle_Func2(struct Task *task)
{
    u8 i;
    u16 r3, r4;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    r4 = task->data[1];
    r3 = task->data[2] >> 8;
    task->data[1] += 4224;
    task->data[2] += 384;

    for (i = 0; i < 160; i++, r4 += 4224)
    {
        u16 var = r4 / 256;
        gUnknown_02038C28[0][i] = sTransitionStructPtr->field_16 + Sin(var, r3);
    }

    if (!gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Phase2Task_Shuffle));

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

void VBlankCB_Phase2_Shuffle(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
}

void HBlankCB_Phase2_Shuffle(void)
{
    u16 var = gUnknown_02038C28[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

void Phase2Task_BigPokeball(u8 taskId)
{
    while (sPhase2_BigPokeball_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Aqua(u8 taskId)
{
    while (sPhase2_Aqua_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Magma(u8 taskId)
{
    while (sPhase2_Magma_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Regice(u8 taskId)
{
    while (sPhase2_Regice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Registeel(u8 taskId)
{
    while (sPhase2_Registeel_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Regirock(u8 taskId)
{
    while (sPhase2_Regirock_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Kyogre(u8 taskId)
{
    while (sPhase2_Kyogre_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void sub_814669C(struct Task *task)
{
    s32 i;

    sub_8149F08();
    dp12_8087EA4();

    task->data[1] = 16;
    task->data[2] = 0;
    task->data[4] = 0;
    task->data[5] = 0x4000;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->field_6 = 240;
    sTransitionStructPtr->WIN0V = 160;
    sTransitionStructPtr->BLDCNT = 0x3F41;
    sTransitionStructPtr->BLDALPHA = (task->data[1] << 8) | (task->data[2]);

    for (i = 0; i < 160; i++)
    {
        gUnknown_02038C28[1][i] = 240;
    }

    SetVBlankCallback(VBlankCB0_Phase2_BigPokeball);
}

bool8 Phase2_Aqua_Func1(struct Task *task)
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

bool8 Phase2_Magma_Func1(struct Task *task)
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

bool8 Phase2_Regi_Func1(struct Task *task)
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

bool8 Phase2_BigPokeball_Func1(struct Task *task)
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

bool8 Phase2_BigPokeball_Func2(struct Task *task)
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
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return TRUE;
}

bool8 Phase2_Aqua_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(sTeamAqua_Tilemap, dst1);
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Magma_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LZ77UnCompVram(sTeamMagma_Tilemap, dst1);
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Regice_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2B4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BC314, dst1, 0x500);
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Registeel_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2D4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BCB14, dst1, 0x500);
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Regirock_Func2(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    LoadPalette(gUnknown_085BC2F4, 0xF0, 0x20);
    CpuCopy16(gUnknown_085BD314, dst1, 0x500);
    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5], 160);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Kyogre_Func3(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085BDB34, dst2);
    LZ77UnCompVram(gUnknown_085BE1E8, dst1);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Kyogre_Func4(struct Task *task)
{
    if (task->data[1] % 3 == 0)
    {
        u16 var = task->data[1] % 30;
        var /= 3;
        LoadPalette(gUnknown_085BEDA0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 58)
    {
        task->tState++;
        task->data[1] = 0;
    }

    return FALSE;
}

bool8 Phase2_Kyogre_Func5(struct Task *task)
{
    if (task->data[1] % 5 == 0)
    {
        s16 var = task->data[1] / 5;
        LoadPalette(gUnknown_085BEEE0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 68)
    {
        task->tState++;
        task->data[1] = 0;
        task->tFrames = 30;
    }

    return FALSE;
}

bool8 Phase2_WeatherDuo_Func6(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFF8000, 1, 0, 0x10, 0);
    task->tState++;
    return FALSE;
}

bool8 Phase2_WeatherDuo_Func7(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    return FALSE;
}

bool8 Phase2_BigPokeball_Func3(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->data[3] == 0 || --task->data[3] == 0)
    {
        task->data[2]++;
        task->data[3] = 2;
    }
    sTransitionStructPtr->BLDALPHA = (task->data[1] << 8) | task->data[2];
    if (task->data[2] > 15)
        task->tState++;
    task->data[4] += 8;
    task->data[5] -= 256;

    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5] >> 8, 160);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_BigPokeball_Func4(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->data[3] == 0 || --task->data[3] == 0)
    {
        task->data[1]--;
        task->data[3] = 2;
    }
    sTransitionStructPtr->BLDALPHA = (task->data[1] << 8) | task->data[2];
    if (task->data[1] == 0)
        task->tState++;
    task->data[4] += 8;
    task->data[5] -= 256;

    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5] >> 8, 160);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_BigPokeball_Func5(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    task->data[4] += 8;
    task->data[5] -= 256;

    sub_8149F98(gUnknown_02038C28[0], 0, task->data[4], 132, task->data[5] >> 8, 160);

    if (task->data[5] <= 0)
    {
        task->tState++;
        task->data[1] = 160;
        task->data[2] = 256;
        task->data[3] = 0;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_FramesCountdown(struct Task *task)
{
    if (--task->tFrames == 0)
        task->tState++;
    return FALSE;
}

bool8 Phase2_WeatherTrio_Func1(struct Task *task)
{
    BeginNormalPaletteFade(0x0000FFFF, 1, 0, 0x10, 0);
    task->tState++;
    return FALSE;
}

bool8 Phase2_WaitPaletteFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->tState++;
    return FALSE;
}

bool8 Phase2_BigPokeball_Func6(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->data[2] < 1024)
        task->data[2] += 128;
    if (task->data[1] != 0)
    {
        task->data[1] -= (task->data[2] >> 8);
        if (task->data[1] < 0)
            task->data[1] = 0;
    }
    sub_814A014(gUnknown_02038C28[0], 120, 80, task->data[1]);
    if (task->data[1] == 0)
    {
        SetVBlankCallback(NULL);
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        if (task->data[3] == 0)
        {
            task->data[3]++;
            SetVBlankCallback(VBlankCB1_Phase2_BigPokeball);
        }

        sTransitionStructPtr->VBlank_DMA++;
    }

    return FALSE;
}

void Transition_BigPokeball_Vblank(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    REG_BLDALPHA = sTransitionStructPtr->BLDALPHA;
}

void VBlankCB0_Phase2_BigPokeball(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gUnknown_020393A8, &REG_BG0HOFS, 0xA2400001);
}

void VBlankCB1_Phase2_BigPokeball(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gUnknown_020393A8, &REG_WIN0H, 0xA2400001);
}

void Phase2Task_PokeballsTrail(u8 taskId)
{
    while (sPhase2_PokeballsTrail_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_PokeballsTrail_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuSet(sPokeballTrail_Tileset, dst2, 0x20);
    CpuFill32(0, dst1, 0x800);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->tState++;
    return FALSE;
}

bool8 Phase2_PokeballsTrail_Func2(struct Task *task)
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

bool8 Phase2_PokeballsTrail_Func3(struct Task *task)
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

void sub_814713C(struct Sprite *sprite)
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

void Phase2Task_Clockwise_BlackFade(u8 taskId)
{
    while (sPhase2_Clockwise_BlackFade_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Clockwise_BlackFade_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    dp12_8087EA4();

    sTransitionStructPtr->WININ = 0;
    sTransitionStructPtr->WINOUT = 63;
    sTransitionStructPtr->field_6 = -3855;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gUnknown_020393A8[i] = 0xF3F4;
    }

    SetVBlankCallback(VBlankCB_Phase2_Clockwise_BlackFade);
    sTransitionStructPtr->data[4] = 120;

    task->tState++;
    return TRUE;
}

bool8 Phase2_Clockwise_BlackFade_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], -1, 1, 1);
    do
    {
        gUnknown_02038C28[0][sTransitionStructPtr->data[3]] = (sTransitionStructPtr->data[2] + 1) | 0x7800;
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

bool8 Phase2_Clockwise_BlackFade_Func3(struct Task *task)
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
        gUnknown_02038C28[0][sTransitionStructPtr->data[3]] = (r3) | (r1 << 8);
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
            gUnknown_02038C28[0][++sTransitionStructPtr->data[3]] = (r3) | (r1 << 8);
        }
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Clockwise_BlackFade_Func4(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], 160, 1, 1);
    do
    {
        gUnknown_02038C28[0][sTransitionStructPtr->data[3]] = (sTransitionStructPtr->data[2] << 8) | 0xF0;
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

bool8 Phase2_Clockwise_BlackFade_Func5(struct Task *task)
{
    s16 r1, r2, var4;
    vu8 var = 0;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, 0, sTransitionStructPtr->data[5], 1, 1);

    while (1)
    {
        r1 = (gUnknown_02038C28[0][sTransitionStructPtr->data[3]]) & 0xFF;
        r2 = sTransitionStructPtr->data[2];
        if (sTransitionStructPtr->data[5] <= 80)
            r2 = 120, r1 = sTransitionStructPtr->data[2];
        var4 = (r1) | (r2 << 8);
        gUnknown_02038C28[0][sTransitionStructPtr->data[3]] = var4;
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
            gUnknown_02038C28[0][--sTransitionStructPtr->data[3]] = (r1) | (r2 << 8);
        }
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Clockwise_BlackFade_Func6(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionStructPtr->data, 120, 80, sTransitionStructPtr->data[4], 0, 1, 1);
    do
    {
        s16 r2, r3;

        r2 = 120, r3 = sTransitionStructPtr->data[2];
        if (sTransitionStructPtr->data[2] >= 120)
            r2 = 0, r3 = 240;
        gUnknown_02038C28[0][sTransitionStructPtr->data[3]] = (r3) | (r2 << 8);

    } while (!sub_814A228(sTransitionStructPtr->data, 1, 1));

    sTransitionStructPtr->data[4] += 16;
    if (sTransitionStructPtr->data[2] > 120)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Clockwise_BlackFade_Func7(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Clockwise_BlackFade));
    return FALSE;
}

void VBlankCB_Phase2_Clockwise_BlackFade(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    REG_WIN0H = gUnknown_02038C28[1][0];
    DmaSet(0, gUnknown_02038C28[1], &REG_WIN0H, 0xA2400001);
}

void Phase2Task_Ripple(u8 taskId)
{
    while (sPhase2_Ripple_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Ripple_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    dp12_8087EA4();

    for (i = 0; i < 160; i++)
    {
        gUnknown_020393A8[i] = sTransitionStructPtr->field_16;
    }

    SetVBlankCallback(VBlankCB_Phase2_Ripple);
    SetHBlankCallback(HBlankCB_Phase2_Ripple);

    EnableInterrupts(INTR_FLAG_HBLANK);

    task->tState++;
    return TRUE;
}

bool8 Phase2_Ripple_Func2(struct Task *task)
{
    u8 i;
    s16 r3;
    u16 r4, r8;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    r3 = task->data[2] >> 8;
    r4 = task->data[1];
    r8 = 384;
    task->data[1] += 0x400;
    if (task->data[2] <= 0x1FFF)
        task->data[2] += 0x180;

    for (i = 0; i < 160; i++, r4 += r8)
    {
        // todo: fix the asm
        s16 var = r4 >> 8;
        asm("");
        gUnknown_02038C28[0][i] = sTransitionStructPtr->field_16 + Sin(var, r3);
    }

    if (++task->data[3] == 81)
    {
        task->data[4]++;
        BeginNormalPaletteFade(-1, -2, 0, 0x10, 0);
    }

    if (task->data[4] != 0 && !gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Phase2Task_Ripple));

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

void VBlankCB_Phase2_Ripple(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
}

void HBlankCB_Phase2_Ripple(void)
{
    u16 var = gUnknown_02038C28[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

void Phase2Task_Wave(u8 taskId)
{
    while (sPhase2_Wave_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Wave_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    dp12_8087EA4();

    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->field_6 = 240;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gUnknown_02038C28[1][i] = 242;
    }

    SetVBlankCallback(VBlankCB_Phase2_Wave);

    task->tState++;
    return TRUE;
}

bool8 Phase2_Wave_Func2(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    bool8 nextFunc;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    toStore = gUnknown_02038C28[0];
    r5 = task->data[2];
    task->data[2] += 16;
    task->data[1] += 8;

    for (i = 0, nextFunc = TRUE; i < 160; i++, r5 += 4, toStore++)
    {
        s16 value = task->data[1] + Sin(r5, 40);
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

bool8 Phase2_Wave_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Wave));
    return FALSE;
}

void VBlankCB_Phase2_Wave(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    DmaSet(0, gUnknown_02038C28[1], &REG_WIN0H, 0xA2400001);
}

void Phase2Task_Sydney(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_SYDNEY;
    Phase2Task_MugShotTransition(taskId);
}

void Phase2Task_Phoebe(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_PHOEBE;
    Phase2Task_MugShotTransition(taskId);
}

void Phase2Task_Glacia(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_GLACIA;
    Phase2Task_MugShotTransition(taskId);
}

void Phase2Task_Drake(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_DRAKE;
    Phase2Task_MugShotTransition(taskId);
}

void Phase2Task_Champion(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_CHAMPION;
    Phase2Task_MugShotTransition(taskId);
}

void Phase2Task_MugShotTransition(u8 taskId)
{
    while (sPhase2_Mugshot_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Mugshot_Func1(struct Task *task)
{
    u8 i;

    sub_8149F08();
    dp12_8087EA4();
    Mugshots_CreateOpponentPlayerSprites(task);

    task->data[1] = 0;
    task->data[2] = 1;
    task->data[3] = 239;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 62;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 160; i++)
    {
        gUnknown_02038C28[1][i] = 0xF0F1;
    }

    SetVBlankCallback(VBlankCB0_Phase2_Mugshots);

    task->tState++;
    return FALSE;
}

bool8 Phase2_Mugshot_Func2(struct Task *task)
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

bool8 Phase2_Mugshot_Func3(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    s16 value;
    s32 mergedValue;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    toStore = gUnknown_02038C28[0];
    r5 = task->data[1];
    task->data[1] += 0x10;

    for (i = 0; i < 80; i++, toStore++, r5 += 0x10)
    {
        value = task->data[2] + Sin(r5, 0x10);
        if (value < 0)
            value = 1;
        if (value > 0xF0)
            value = 0xF0;
        *toStore = value;
    }
    for (; i < 160; i++, toStore++, r5 += 0x10)
    {
        value = task->data[3] - Sin(r5, 0x10);
        if (value < 0)
            value = 0;
        if (value > 0xEF)
            value = 0xEF;
        *toStore = (value << 8) | (0xF0);
    }

    task->data[2] += 8;
    task->data[3] -= 8;
    if (task->data[2] > 0xF0)
        task->data[2] = 0xF0;
    if (task->data[3] < 0)
        task->data[3] = 0;
    mergedValue = *(s32*)(&task->data[2]);
    if (mergedValue == 0xF0)
        task->tState++;

    sTransitionStructPtr->field_18 -= 8;
    sTransitionStructPtr->field_1A += 8;
    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Mugshot_Func4(struct Task *task)
{
    u8 i;
    u16* toStore;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    for (i = 0, toStore = gUnknown_02038C28[0]; i < 160; i++, toStore++)
    {
        *toStore = 0xF0;
    }

    task->tState++;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    sTransitionStructPtr->field_18 -= 8;
    sTransitionStructPtr->field_1A += 8;

    sub_8148484(task->tOpponentSpriteId, 0);
    sub_8148484(task->tPlayerSpriteId, 1);
    sub_814849C(task->tOpponentSpriteId);

    PlaySE(SE_BT_START);

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Mugshot_Func5(struct Task *task)
{
    sTransitionStructPtr->field_18 -= 8;
    sTransitionStructPtr->field_1A += 8;
    if (sub_81484B8(task->tOpponentSpriteId))
    {
        task->tState++;
        sub_814849C(task->tPlayerSpriteId);
    }
    return FALSE;
}

bool8 Phase2_Mugshot_Func6(struct Task *task)
{
    sTransitionStructPtr->field_18 -= 8;
    sTransitionStructPtr->field_1A += 8;
    if (sub_81484B8(task->tPlayerSpriteId))
    {
        sTransitionStructPtr->VBlank_DMA = FALSE;
        SetVBlankCallback(NULL);
        DmaStop(0);
        memset(gUnknown_02038C28[0], 0, 0x140);
        memset(gUnknown_02038C28[1], 0, 0x140);
        SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        task->tState++;
        task->data[3] = 0;
        task->data[4] = 0;
        sTransitionStructPtr->BLDCNT = 0xBF;
        SetVBlankCallback(VBlankCB1_Phase2_Mugshots);
    }
    return FALSE;
}

bool8 Phase2_Mugshot_Func7(struct Task *task)
{
    bool32 r6;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    r6 = TRUE;
    sTransitionStructPtr->field_18 -= 8;
    sTransitionStructPtr->field_1A += 8;

    if (task->data[4] < 0x50)
        task->data[4] += 2;
    if (task->data[4] > 0x50)
        task->data[4] = 0x50;

    if (++task->data[3] & 1)
    {
        s16 i;
        for (i = 0, r6 = FALSE; i <= task->data[4]; i++)
        {
            s16 index1 = 0x50 - i;
            s16 index2 = 0x50 + i;
            if (gUnknown_02038C28[0][index1] <= 15)
            {
                r6 = TRUE;
                gUnknown_02038C28[0][index1]++;
            }
            if (gUnknown_02038C28[0][index2] <= 15)
            {
                r6 = TRUE;
                gUnknown_02038C28[0][index2]++;
            }
        }
    }

    if (task->data[4] == 0x50 && !r6)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Mugshot_Func8(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    BlendPalettes(-1, 0x10, 0x7FFF);
    sTransitionStructPtr->BLDCNT = 0xFF;
    task->data[3] = 0;

    task->tState++;
    return TRUE;
}

bool8 Phase2_Mugshot_Func9(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;

    task->data[3]++;
    memset(gUnknown_02038C28[0], task->data[3], 0x140);
    if (task->data[3] > 15)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Mugshot_Func10(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

void VBlankCB0_Phase2_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
    REG_BG0VOFS = sTransitionStructPtr->field_1C;
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    DmaSet(0, gUnknown_02038C28[1], &REG_WIN0H, 0xA2400001);
}

void VBlankCB1_Phase2_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionStructPtr->VBlank_DMA != 0)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 320);
    REG_BLDCNT = sTransitionStructPtr->BLDCNT;
    DmaSet(0, gUnknown_02038C28[1], &REG_BLDY, 0xA2400001);
}

void HBlankCB_Phase2_Mugshots(void)
{
    if (REG_VCOUNT < 80)
        REG_BG0HOFS = sTransitionStructPtr->field_18;
    else
        REG_BG0HOFS = sTransitionStructPtr->field_1A;
}

void Mugshots_CreateOpponentPlayerSprites(struct Task *task)
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

void sub_8148380(struct Sprite *sprite)
{
    while (sUnknown_085C8C24[sprite->data[0]](sprite));
}

bool8 sub_81483A8(struct Sprite *sprite)
{
    return FALSE;
}

bool8 sub_81483AC(struct Sprite *sprite)
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

bool8 sub_81483F8(struct Sprite *sprite)
{
    sprite->pos1.x += sprite->data[1];
    if (sprite->data[7] && sprite->pos1.x < 133)
        sprite->data[0]++;
    else if (!sprite->data[7] && sprite->pos1.x > 103)
        sprite->data[0]++;
    return FALSE;
}

bool8 sub_814842C(struct Sprite *sprite)
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

bool8 sub_8148458(struct Sprite *sprite)
{
    sprite->data[1] += sprite->data[2];
    sprite->pos1.x += sprite->data[1];
    if (sprite->pos1.x < -31 || sprite->pos1.x > 271)
        sprite->data[0]++;
    return FALSE;
}

void sub_8148484(s16 spriteId, s16 value)
{
    gSprites[spriteId].data[7] = value;
}

void sub_814849C(s16 spriteId)
{
    gSprites[spriteId].data[0]++;
}

s16 sub_81484B8(s16 spriteId)
{
    return gSprites[spriteId].data[6];
}

void Phase2Task_Slice(u8 taskId)
{
    while (sPhase2_Slice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Slice_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    dp12_8087EA4();

    task->data[2] = 256;
    task->data[3] = 1;
    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0V = 160;
    sTransitionStructPtr->VBlank_DMA = FALSE;

    for (i = 0; i < 160; i++)
    {
        gUnknown_02038C28[1][i] = sTransitionStructPtr->field_14;
        gUnknown_02038C28[1][160 + i] = 0xF0;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetGpuRegBits(REG_OFFSET_DISPSTAT, DISPSTAT_HBLANK_INTR);

    SetVBlankCallback(VBlankCB_Phase2_Slice);
    SetHBlankCallback(HBlankCB_Phase2_Slice);

    task->tState++;
    return TRUE;
}

bool8 Phase2_Slice_Func2(struct Task *task)
{
    u16 i;

    sTransitionStructPtr->VBlank_DMA = FALSE;

    task->data[1] += (task->data[2] >> 8);
    if (task->data[1] > 0xF0)
        task->data[1] = 0xF0;
    if (task->data[2] <= 0xFFF)
        task->data[2] += task->data[3];
    if (task->data[3] < 128)
        task->data[3] <<= 1; // multiplying by two

    for (i = 0; i < 160; i++)
    {
        u16* storeLoc1 = &gUnknown_02038C28[0][i];
        u16* storeLoc2 = &gUnknown_02038C28[0][i + 160];
        if (1 & i)
        {
            *storeLoc1 = sTransitionStructPtr->field_14 + task->data[1];
            *storeLoc2 = 0xF0 - task->data[1];
        }
        else
        {
            *storeLoc1 = sTransitionStructPtr->field_14 - task->data[1];
            *storeLoc2 = (task->data[1] << 8) | (0xF1);
        }
    }

    if (task->data[1] > 0xEF)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Slice_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_Slice));
    return FALSE;
}

void VBlankCB_Phase2_Slice(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    REG_WININ = sTransitionStructPtr->WININ;
    REG_WINOUT = sTransitionStructPtr->WINOUT;
    REG_WIN0V = sTransitionStructPtr->WIN0V;
    if (sTransitionStructPtr->VBlank_DMA)
        DmaCopy16(3, gUnknown_02038C28[0], gUnknown_02038C28[1], 640);
    DmaSet(0, &gUnknown_02038C28[1][160], &REG_WIN0H, 0xA2400001);
}

void HBlankCB_Phase2_Slice(void)
{
    if (REG_VCOUNT < 160)
    {
        u16 var = gUnknown_02038C28[1][REG_VCOUNT];
        REG_BG1HOFS = var;
        REG_BG2HOFS = var;
        REG_BG3HOFS = var;
    }
}

void Phase2Task_25(u8 taskId)
{
    while (sPhase2_25_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_25_Func1(struct Task *task)
{
    u16 i;

    sub_8149F08();
    dp12_8087EA4();

    sTransitionStructPtr->WININ = 63;
    sTransitionStructPtr->WINOUT = 0;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 0xA0; i++)
    {
        gUnknown_02038C28[1][i] = sTransitionStructPtr->field_14;
        gUnknown_02038C28[1][0xA0 + i] = 0xF0;
        gUnknown_02038C28[0][i] = sTransitionStructPtr->field_14;
        gUnknown_02038C28[0][0xA0 + i] = 0xF0;
        gUnknown_02038C28[0][0x140 + i] = 0;
        gUnknown_02038C28[0][0x1E0 + i] = 0x100;
        gUnknown_02038C28[0][0x280 + i] = 1;
    }

    task->data[4] = 0;
    task->data[5] = 0;
    task->data[6] = 7;

    EnableInterrupts(INTR_FLAG_HBLANK);

    SetVBlankCallback(VBlankCB_Phase2_Slice);
    SetHBlankCallback(HBlankCB_Phase2_Slice);

    task->tState++;
    return TRUE;
}

bool8 Phase2_25_Func2(struct Task *task)
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

    for (i = 0; i <= task->data[5]; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                unkVar = (arr1[j]) + (arr2[k] * -(i) * 2);
                if (unkVar >= 0 && (unkVar != 79 || j != 1))
                {
                    ptr4 = &gUnknown_02038C28[0][unkVar + 320];
                    ptr3 = &gUnknown_02038C28[0][unkVar + 480];
                    ptr1 = &gUnknown_02038C28[0][unkVar + 640];
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
                    ptr2 = &gUnknown_02038C28[0][unkVar];
                    ptr3 = &gUnknown_02038C28[0][unkVar + 160];
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
                    ptr4 = &gUnknown_02038C28[0][unkVar + 320];
                    ptr3 = &gUnknown_02038C28[0][unkVar + 480];
                    ptr1 = &gUnknown_02038C28[0][unkVar + 640];
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
                    ptr2 = &gUnknown_02038C28[0][unkVar];
                    ptr3 = &gUnknown_02038C28[0][unkVar + 160];
                    *ptr2 = sTransitionStructPtr->field_14 - *ptr4;
                    *ptr3 = (*ptr4 << 8) | (0xF1);

                    if (i == 0)
                        break;
                }
            }
        }
    }

    if (--task->data[4] < 0)
        task->data[4] = 0;
    if (task->data[4] <= 0 && task->data[5] + 1 <= 20)
        task->data[4] = task->data[6], task->data[5]++;
    if (var > 0x9F)
        task->tState++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_25_Func3(struct Task *task)
{
    u16 i;
    bool32 done = TRUE;
    u16 checkVar2 = 0xFF10;

    for (i = 0; i < 0xA0; i++)
    {
        if (gUnknown_02038C28[1][i] != 0xF0 && gUnknown_02038C28[1][i] != checkVar2)
            done = FALSE; // a break statement should be put here
    }

    if (done == TRUE)
        task->tState++;

    return FALSE;
}

bool8 Phase2_25_Func4(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(Phase2Task_25));
    return FALSE;
}

void Phase2Task_Blackhole1(u8 taskId)
{
    while (sPhase2_Blackhole1_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

void Phase2Task_Blackhole2(u8 taskId)
{
    while (sPhase2_Blackhole2_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Blackhole_Func1(struct Task *task)
{
    s32 i;

    sub_8149F08();
    dp12_8087EA4();

    sTransitionStructPtr->WININ = 0;
    sTransitionStructPtr->WINOUT = 63;
    sTransitionStructPtr->field_6 = 240;
    sTransitionStructPtr->WIN0V = 160;

    for (i = 0; i < 0xA0; i++)
    {
        gUnknown_02038C28[1][i] = 0;
    }

    SetVBlankCallback(VBlankCB1_Phase2_BigPokeball);

    task->tState++;
    task->data[1] = 1;
    task->data[2] = 0x100;
    task->data[7] = 0;

    return FALSE;
}

bool8 Phase2_Blackhole1_Func3(struct Task *task)
{
    if (task->data[7] == 1)
    {
        DmaStop(0);
        SetVBlankCallback(NULL);
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        sTransitionStructPtr->VBlank_DMA = FALSE;
        if (task->data[2] < 0x400)
            task->data[2] += 0x80;
        if (task->data[1] < 0xA0)
            task->data[1] += (task->data[2] >> 8);
        if (task->data[1] > 0xA0)
            task->data[1] = 0xA0;
        sub_814A014(gUnknown_02038C28[0], 0x78, 0x50, task->data[1]);
        if (task->data[1] == 0xA0)
        {
            task->data[7] = 1;
            sub_8149F84();
        }
        else
        {
            sTransitionStructPtr->VBlank_DMA++;
        }
    }

    return FALSE;
}

bool8 Phase2_Blackhole1_Func2(struct Task *task)
{
    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->data[7] == 0)
    {
        task->data[7]++;
        task->data[1] = 0x30;
        task->data[6] = 0;
    }
    task->data[1] += gUnknown_085C8C80[task->data[6]];
    task->data[6] = (task->data[6] + 1) % 2;
    sub_814A014(gUnknown_02038C28[0], 0x78, 0x50, task->data[1]);
    if (task->data[1] < 9)
    {
        task->tState++;
        task->data[7] = 0;
    }

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

bool8 Phase2_Blackhole2_Func2(struct Task *task)
{
    u16 index; // should be s16 I think
    s16 amplitude;

    sTransitionStructPtr->VBlank_DMA = FALSE;
    if (task->data[7] == 0)
    {
        task->data[7]++;
        task->data[5] = 2;
        task->data[6] = 2;
    }
    if (task->data[1] > 0xA0)
        task->data[1] = 0xA0;

    sub_814A014(gUnknown_02038C28[0], 0x78, 0x50, task->data[1]);
    if (task->data[1] == 0xA0)
    {
        DmaStop(0);
        sub_8149F84();
        DestroyTask(FindTaskIdByFunc(task->func));
    }

    index = task->data[5];
    if ((task->data[5] & 0xFF) <= 128)
    {
        amplitude = task->data[6];
        task->data[5] += 8;
    }
    else
    {
        amplitude = task->data[6] - 1;
        task->data[5] += 16;
    }
    task->data[1] += Sin(index & 0xFF, amplitude);

    if (task->data[1] <= 0)
        task->data[1] = 1;
    if (task->data[5] > 0xFE)
        task->data[5] >>= 8, task->data[6]++;

    sTransitionStructPtr->VBlank_DMA++;
    return FALSE;
}

void Phase2Task_RectangularSpiral(u8 taskId)
{
    while (sPhase2_RectangularSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_RectangularSpiral_Func1(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuCopy16(sShrinkingBoxTileset, dst2, 0x20);
    CpuCopy16(sShrinkingBoxTileset + 0x70, dst2 + 0x20, 0x20);
    CpuFill16(0xF000, dst1, 0x800);
    LoadPalette(gFieldEffectObjectPalette10, 0xF0, 0x20);

    task->data[3] = 1;
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

bool8 Phase2_RectangularSpiral_Func2(struct Task *task)
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

bool8 Phase2_RectangularSpiral_Func3(struct Task *task)
{
    DmaStop(0);
    sub_8149F84();
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

bool16 sub_8149048(const s16 * const *arg0, struct StructRectangularSpiral *arg1)
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

void Phase2Task_Groudon(u8 taskId)
{
    while (sPhase2_Groudon_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Phase2_Groudon_Func3(struct Task *task)
{
    u16 *dst1, *dst2;

    sub_8149F58(&dst1, &dst2);
    CpuFill16(0, dst1, 0x800);
    LZ77UnCompVram(gUnknown_085BE51C, dst2);
    LZ77UnCompVram(gUnknown_085BEA88, dst1);

    task->tState++;
    task->data[1] = 0;
    return FALSE;
}

bool8 Phase2_Groudon_Func4(struct Task *task)
{
    if (task->data[1] % 3 == 0)
    {
        u16 var = (task->data[1] % 30) / 3;
        LoadPalette(gUnknown_085BF0A0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 58)
    {
        task->tState++;
        task->data[1] = 0;
    }

    return FALSE;
}

bool8 Phase2_Groudon_Func5(struct Task *task)
{
    if (task->data[1] % 5 == 0)
    {
        s16 var = task->data[1] / 5;
        LoadPalette(gUnknown_085BF2A0 + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 68)
    {
        task->tState++;
        task->data[1] = 0;
        task->tFrames = 30;
    }

    return FALSE;
}


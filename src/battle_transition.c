#include "global.h"
#include "battle.h"
#include "battle_transition.h"
#include "battle_transition_frontier.h"
#include "bg.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

#define PALTAG_UNUSED_MUGSHOT 0x100A

#define B_TRANS_DMA_FLAGS (1 | ((DMA_SRC_INC | DMA_DEST_FIXED | DMA_REPEAT | DMA_16BIT | DMA_START_HBLANK | DMA_ENABLE) << 16))

#define SET_TILEMAP_TILE(ptr, posY, posX, toStore)                       \
{                                                                       \
    u32 index = (posY) * 32 + posX;                                     \
    ptr[index] = toStore;                                               \
}

struct TransitionData
{
    vu8 VBlank_DMA;
    u16 WININ;
    u16 WINOUT;
    u16 WIN0H;
    u16 WIN0V;
    u16 unused1;
    u16 unused2;
    u16 BLDCNT;
    u16 BLDALPHA;
    u16 BLDY;
    s16 cameraX;
    s16 cameraY;
    s16 BG0HOFS_Lower;
    s16 BG0HOFS_Upper;
    s16 BG0VOFS; // used but not set
    s16 unused3;
    s16 field_20;
    s16 unused4;
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

static bool8 Transition_StartIntro(struct Task *task);
static bool8 Transition_WaitForIntro(struct Task *task);
static bool8 Transition_StartMain(struct Task *task);
static bool8 Transition_WaitForMain(struct Task *task);

static void LaunchBattleTransitionTask(u8 transitionId);
static void Task_BattleTransition(u8 taskId);
static void Task_Intro(u8 taskId);
static void Task_Blur(u8 taskId);
static void Task_Swirl(u8 taskId);
static void Task_Shuffle(u8 taskId);
static void Task_BigPokeball(u8 taskId);
static void Task_PokeballsTrail(u8 taskId);
static void Task_Clockwise_BlackFade(u8 taskId);
static void Task_Ripple(u8 taskId);
static void Task_Wave(u8 taskId);
static void Task_Slice(u8 taskId);
static void Task_WhiteFade(u8 taskId);
static void Task_GridSquares(u8 taskId);
static void Task_Shards(u8 taskId);
static void Task_Sidney(u8 taskId);
static void Task_Phoebe(u8 taskId);
static void Task_Glacia(u8 taskId);
static void Task_Drake(u8 taskId);
static void Task_Champion(u8 taskId);
static void Task_Aqua(u8 taskId);
static void Task_Magma(u8 taskId);
static void Task_Regice(u8 taskId);
static void Task_Registeel(u8 taskId);
static void Task_Regirock(u8 taskId);
static void Task_Kyogre(u8 taskId);
static void Task_Groudon(u8 taskId);
static void Task_Rayquaza(u8 taskId);
static void Task_ShredSplit(u8 taskId);
static void Task_Blackhole1(u8 taskId);
static void Task_Blackhole2(u8 taskId);
static void Task_RectangularSpiral(u8 taskId);
static void Task_FrontierLogoWiggle(u8 taskId);
static void Task_FrontierLogoWave(u8 taskId);
static void Task_FrontierSquares(u8 taskId);
static void Task_FrontierSquaresScroll(u8 taskId);
static void Task_FrontierSquaresSpiral(u8 taskId);
static void VBlankCB_BattleTransition(void);
static void VBlankCB_Swirl(void);
static void HBlankCB_Swirl(void);
static void VBlankCB_Shuffle(void);
static void HBlankCB_Shuffle(void);
static void VBlankCB_PatternWeave(void);
static void VBlankCB1_BigPokeball(void);
static void VBlankCB_Clockwise_BlackFade(void);
static void VBlankCB_Ripple(void);
static void HBlankCB_Ripple(void);
static void VBlankCB_FrontierLogoWave(void);
static void HBlankCB_FrontierLogoWave(void);
static void VBlankCB_Wave(void);
static void VBlankCB_Slice(void);
static void HBlankCB_Slice(void);
static void VBlankCB0_WhiteFade(void);
static void VBlankCB1_WhiteFade(void);
static void HBlankCB_WhiteFade(void);
static void VBlankCB_Shards(void);
static void VBlankCB_Rayquaza(void);
static bool8 Blur_Init(struct Task *task);
static bool8 Blur_Main(struct Task *task);
static bool8 Blur_End(struct Task *task);
static bool8 Swirl_Init(struct Task *task);
static bool8 Swirl_End(struct Task *task);
static bool8 Shuffle_Init(struct Task *task);
static bool8 Shuffle_End(struct Task *task);
static bool8 Aqua_Init(struct Task *task);
static bool8 Aqua_SetGfx(struct Task *task);
static bool8 Magma_Init(struct Task *task);
static bool8 Magma_SetGfx(struct Task *task);
static bool8 FramesCountdown(struct Task *task);
static bool8 Regi_Init(struct Task *task);
static bool8 Regice_SetGfx(struct Task *task);
static bool8 Registeel_SetGfx(struct Task *task);
static bool8 Regirock_SetGfx(struct Task *task);
static bool8 WeatherTrio_BgFadeBlack(struct Task *task);
static bool8 WeatherTrio_WaitFade(struct Task *task);
static bool8 Kyogre_Init(struct Task *task);
static bool8 Kyogre_PalettePulsate(struct Task *task);
static bool8 Kyogre_PaletteBrighten(struct Task *task);
static bool8 Groudon_Init(struct Task *task);
static bool8 Groudon_PalettePulsate(struct Task *task);
static bool8 Groudon_PaletteBrighten(struct Task *task);
static bool8 WeatherDuo_FadeOut(struct Task *task);
static bool8 WeatherDuo_End(struct Task *task);
static bool8 BigPokeball_Init(struct Task *task);
static bool8 BigPokeball_SetGfx(struct Task *task);
static bool8 PatternWeave_1(struct Task *task);
static bool8 PatternWeave_2(struct Task *task);
static bool8 PatternWeave_3(struct Task *task);
static bool8 PatternWeave_End(struct Task *task);
static bool8 PokeballsTrail_Init(struct Task *task);
static bool8 PokeballsTrail_Main(struct Task *task);
static bool8 PokeballsTrail_End(struct Task *task);
static bool8 Clockwise_BlackFade_Init(struct Task *task);
static bool8 Clockwise_BlackFade_Func2(struct Task *task);
static bool8 Clockwise_BlackFade_Func3(struct Task *task);
static bool8 Clockwise_BlackFade_Func4(struct Task *task);
static bool8 Clockwise_BlackFade_Func5(struct Task *task);
static bool8 Clockwise_BlackFade_Func6(struct Task *task);
static bool8 Clockwise_BlackFade_End(struct Task *task);
static bool8 Ripple_Init(struct Task *task);
static bool8 Ripple_Func2(struct Task *task);
static bool8 Wave_Init(struct Task *task);
static bool8 Wave_Func2(struct Task *task);
static bool8 Wave_End(struct Task *task);
static bool8 Slice_Init(struct Task *task);
static bool8 Slice_Func2(struct Task *task);
static bool8 Slice_End(struct Task *task);
static bool8 WhiteFade_Init(struct Task *task);
static bool8 WhiteFade_Func2(struct Task *task);
static bool8 WhiteFade_Func3(struct Task *task);
static bool8 WhiteFade_Func4(struct Task *task);
static bool8 WhiteFade_End(struct Task *task);
static bool8 GridSquares_Init(struct Task *task);
static bool8 GridSquares_Func2(struct Task *task);
static bool8 GridSquares_End(struct Task *task);
static bool8 Shards_Init(struct Task *task);
static bool8 Shards_Func2(struct Task *task);
static bool8 Shards_Func3(struct Task *task);
static bool8 Shards_Func4(struct Task *task);
static bool8 Shards_Func5(struct Task *task);
static bool8 ShredSplit_Init(struct Task *task);
static bool8 ShredSplit_Func2(struct Task *task);
static bool8 ShredSplit_Func3(struct Task *task);
static bool8 ShredSplit_End(struct Task *task);
static bool8 Blackhole_Init(struct Task *task);
static bool8 Blackhole1_Func2(struct Task *task);
static bool8 Blackhole1_Func3(struct Task *task);
static bool8 Blackhole2_Func2(struct Task *task);
static bool8 RectangularSpiral_Init(struct Task *task);
static bool8 RectangularSpiral_Func2(struct Task *task);
static bool8 RectangularSpiral_End(struct Task *task);
static bool8 FrontierLogoWiggle_Init(struct Task *task);
static bool8 FrontierLogoWiggle_SetGfx(struct Task *task);
static bool8 FrontierLogoWave_Init(struct Task *task);
static bool8 FrontierLogoWave_SetGfx(struct Task *task);
static bool8 FrontierLogoWave_Func3(struct Task *task);
static bool8 FrontierLogoWave_Func4(struct Task *task);
static bool8 Rayquaza_Func3(struct Task *task);
static bool8 Rayquaza_Func4(struct Task *task);
static bool8 Rayquaza_Func5(struct Task *task);
static bool8 Rayquaza_Func6(struct Task *task);
static bool8 Rayquaza_Func7(struct Task *task);
static bool8 Rayquaza_Func8(struct Task *task);
static bool8 Rayquaza_Func9(struct Task *task);
static bool8 FrontierSquares_Init(struct Task *task);
static bool8 FrontierSquares_Func2(struct Task *task);
static bool8 FrontierSquares_Func3(struct Task *task);
static bool8 FrontierSquares_End(struct Task *task);
static bool8 FrontierSquaresSpiral_Init(struct Task *task);
static bool8 FrontierSquaresSpiral_Func2(struct Task *task);
static bool8 FrontierSquaresSpiral_Func3(struct Task *task);
static bool8 FrontierSquaresSpiral_Func4(struct Task *task);
static bool8 FrontierSquaresScroll_Init(struct Task *task);
static bool8 FrontierSquaresScroll_Func2(struct Task *task);
static bool8 FrontierSquaresScroll_Func3(struct Task *task);
static bool8 FrontierSquaresScroll_Func4(struct Task *task);
static bool8 FrontierSquaresScroll_End(struct Task *task);
static bool8 Mugshot_Init(struct Task *task);
static bool8 Mugshot_SetGfx(struct Task *task);
static bool8 Mugshot_ShowBanner(struct Task *task);
static bool8 Mugshot_StartOpponentSlide(struct Task *task);
static bool8 Mugshot_WaitStartPlayerSlide(struct Task *task);
static bool8 Mugshot_WaitPlayerSlide(struct Task *task);
static bool8 Mugshot_GradualWhiteFade(struct Task *task);
static bool8 Mugshot_InitFadeWhiteToBlack(struct Task *task);
static bool8 Mugshot_FadeToBlack(struct Task *task);
static bool8 Mugshot_End(struct Task *task);
static void DoMugshotTransition(u8 taskId);
static void Mugshots_CreateTrainerPics(struct Task *task);
static void VBlankCB0_Mugshots(void);
static void VBlankCB1_Mugshots(void);
static void HBlankCB_Mugshots(void);
static void InitTransitionData(void);
static void FadeScreenBlack(void);
static void CreateIntroTask(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4);
static void sub_814A014(u16 *a0, s16 a1, s16 a2, s16 a3);
static void SetSinWave(s16 *array, s16 sinAdd, s16 index, s16 indexIncrementer, s16 amplitude, s16 arrSize);
static void GetBg0TilemapDst(u16 **tileset);
static void sub_814A1AC(s16 *a0, s16 a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6);
static bool8 sub_814A228(s16 *a0, bool8 a1, bool8 a2);
static void SetTrainerPicSlideTable(s16 spriteId, s16 arrId);
static void IncrementTrainerPicState(s16 spriteId);
static s16 IsTrainerPicSlideDone(s16 spriteId);
static bool8 Transition_Intro_1(struct Task *task);
static bool8 Transition_Intro_2(struct Task *task);
static bool8 IsIntroTaskDone(void);
static bool16 sub_8149048(const s16 * const *arg0, struct StructRectangularSpiral *arg1);
static void SpriteCB_FldEffPokeball(struct Sprite *sprite);
static void SpriteCB_MugshotTrainerPic(struct Sprite *sprite);
static void sub_8149864(struct Sprite *sprite);
static bool8 MugshotTrainerPic_Nothing(struct Sprite *sprite);
static bool8 MugshotTrainerPic_SetSlideOffsets(struct Sprite *sprite);
static bool8 MugshotTrainerPic_Slide1(struct Sprite *sprite);
static bool8 MugshotTrainerPic_Slide2(struct Sprite *sprite);
static bool8 MugshotTrainerPic_Slide3(struct Sprite *sprite);

static s16 sUnusedRectangularSpiralVar;
static u8 sTestingTransitionId;
static u8 sTestingTransitionState;
static struct StructRectangularSpiral sRectangularSpiralTransition[4];

EWRAM_DATA static struct TransitionData *sTransitionData = NULL;

static const u32 sBigPokeball_Tileset[] = INCBIN_U32("graphics/battle_transitions/big_pokeball.4bpp");
static const u32 sPokeballTrail_Tileset[] = INCBIN_U32("graphics/battle_transitions/pokeball_trail.4bpp");
static const u8 sPokeball_Gfx[] = INCBIN_U8("graphics/battle_transitions/pokeball.4bpp");
static const u32 sEliteFour_Tileset[] = INCBIN_U32("graphics/battle_transitions/elite_four_bg.4bpp");
static const u8 sUnusedBrendan_Gfx[] = INCBIN_U8("graphics/battle_transitions/unused_brendan.4bpp");
static const u8 sUnusedLass_Gfx[] = INCBIN_U8("graphics/battle_transitions/unused_lass.4bpp");
static const u32 sShrinkingBoxTileset[] = INCBIN_U32("graphics/battle_transitions/shrinking_box.4bpp");
static const u16 sEvilTeam_Palette[] = INCBIN_U16("graphics/battle_transitions/evil_team.gbapal");
static const u32 sTeamAqua_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_aqua.4bpp.lz");
static const u32 sTeamAqua_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_aqua.bin.lz");
static const u32 sTeamMagma_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_magma.4bpp.lz");
static const u32 sTeamMagma_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_magma.bin.lz");
static const u32 sRegis_Tileset[] = INCBIN_U32("graphics/battle_transitions/regis.4bpp");
static const u16 sRegice_Palette[] = INCBIN_U16("graphics/battle_transitions/regice.gbapal");
static const u16 sRegisteel_Palette[] = INCBIN_U16("graphics/battle_transitions/registeel.gbapal");
static const u16 sRegirock_Palette[] = INCBIN_U16("graphics/battle_transitions/regirock.gbapal");
static const u32 sRegice_Tilemap[] = INCBIN_U32("graphics/battle_transitions/regice.bin");
static const u32 sRegisteel_Tilemap[] = INCBIN_U32("graphics/battle_transitions/registeel.bin");
static const u32 sRegirock_Tilemap[] = INCBIN_U32("graphics/battle_transitions/regirock.bin");
static const u16 gUnknown_085BDB14[] = INCBIN_U16("graphics/battle_transitions/85BDB14.gbapal");
static const u32 sKyogre_Tileset[] = INCBIN_U32("graphics/battle_transitions/kyogre.4bpp.lz");
static const u32 sKyogre_Tilemap[] = INCBIN_U32("graphics/battle_transitions/kyogre.bin.lz");
static const u32 sGroudon_Tileset[] = INCBIN_U32("graphics/battle_transitions/groudon.4bpp.lz");
static const u32 sGroudon_Tilemap[] = INCBIN_U32("graphics/battle_transitions/groudon.bin.lz");
static const u16 sKyogre1_Palette[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt1.gbapal");
static const u16 sKyogre2_Palette[] = INCBIN_U16("graphics/battle_transitions/kyogre_pt2.gbapal");
static const u16 sGroudon1_Palette[] = INCBIN_U16("graphics/battle_transitions/groudon_pt1.gbapal");
static const u16 sGroudon2_Palette[] = INCBIN_U16("graphics/battle_transitions/groudon_pt2.gbapal");
static const u16 sRayquaza_Palette[] = INCBIN_U16("graphics/battle_transitions/rayquaza.gbapal");
static const u32 sRayquaza_Tileset[] = INCBIN_U32("graphics/battle_transitions/rayquaza.4bpp");
static const u32 sRayquaza_Tilemap[] = INCBIN_U32("graphics/battle_transitions/rayquaza.bin");
static const u16 sFrontierLogo_Palette[] = INCBIN_U16("graphics/battle_transitions/frontier_logo.gbapal");
static const u32 sFrontierLogo_Tileset[] = INCBIN_U32("graphics/battle_transitions/frontier_logo.4bpp.lz");
static const u32 sFrontierLogo_Tilemap[] = INCBIN_U32("graphics/battle_transitions/frontier_logo.bin.lz");
static const u16 sFrontierSquares_Palette[] = INCBIN_U16("graphics/battle_transitions/frontier_squares_blanktiles.gbapal");
static const u32 sFrontierSquares_FilledBg_Tileset[] = INCBIN_U32("graphics/battle_transitions/frontier_square_1.4bpp.lz");
static const u32 sFrontierSquares_EmptyBg_Tileset[] = INCBIN_U32("graphics/battle_transitions/frontier_square_2.4bpp.lz");
static const u32 sFrontierSquares_Shrink1_Tileset[] = INCBIN_U32("graphics/battle_transitions/frontier_square_3.4bpp.lz");
static const u32 sFrontierSquares_Shrink2_Tileset[] = INCBIN_U32("graphics/battle_transitions/frontier_square_4.4bpp.lz");
static const u32 sFrontierSquares_Tilemap[] = INCBIN_U32("graphics/battle_transitions/frontier_squares.bin");

// All battle transitions use the same intro
static const TaskFunc sTasks_Intro[B_TRANSITION_COUNT] =
{
    [0 ... B_TRANSITION_COUNT - 1] = &Task_Intro
};

// After the intro each transition has a unique main task.
// This task will call the functions that do the transition effects.
static const TaskFunc sTasks_Main[B_TRANSITION_COUNT] =
{
    [B_TRANSITION_BLUR] = Task_Blur,
    [B_TRANSITION_SWIRL] = Task_Swirl,
    [B_TRANSITION_SHUFFLE] = Task_Shuffle,
    [B_TRANSITION_BIG_POKEBALL] = Task_BigPokeball,
    [B_TRANSITION_POKEBALLS_TRAIL] = Task_PokeballsTrail,
    [B_TRANSITION_CLOCKWISE_BLACKFADE] = Task_Clockwise_BlackFade,
    [B_TRANSITION_RIPPLE] = Task_Ripple,
    [B_TRANSITION_WAVE] = Task_Wave,
    [B_TRANSITION_SLICE] = Task_Slice,
    [B_TRANSITION_WHITEFADE] = Task_WhiteFade,
    [B_TRANSITION_GRID_SQUARES] = Task_GridSquares,
    [B_TRANSITION_SHARDS] = Task_Shards,
    [B_TRANSITION_SIDNEY] = Task_Sidney,
    [B_TRANSITION_PHOEBE] = Task_Phoebe,
    [B_TRANSITION_GLACIA] = Task_Glacia,
    [B_TRANSITION_DRAKE] = Task_Drake,
    [B_TRANSITION_CHAMPION] = Task_Champion,
    [B_TRANSITION_AQUA] = Task_Aqua,
    [B_TRANSITION_MAGMA] = Task_Magma,
    [B_TRANSITION_REGICE] = Task_Regice,
    [B_TRANSITION_REGISTEEL] = Task_Registeel,
    [B_TRANSITION_REGIROCK] = Task_Regirock,
    [B_TRANSITION_KYOGRE] = Task_Kyogre,
    [B_TRANSITION_GROUDON] = Task_Groudon,
    [B_TRANSITION_RAYQUAZA] = Task_Rayquaza,
    [B_TRANSITION_SHRED_SPLIT] = Task_ShredSplit,
    [B_TRANSITION_BLACKHOLE1] = Task_Blackhole1,
    [B_TRANSITION_BLACKHOLE2] = Task_Blackhole2,
    [B_TRANSITION_RECTANGULAR_SPIRAL] = Task_RectangularSpiral,
    [B_TRANSITION_FRONTIER_LOGO_WIGGLE] = Task_FrontierLogoWiggle,
    [B_TRANSITION_FRONTIER_LOGO_WAVE] = Task_FrontierLogoWave,
    [B_TRANSITION_FRONTIER_SQUARES] = Task_FrontierSquares,
    [B_TRANSITION_FRONTIER_SQUARES_SCROLL] = Task_FrontierSquaresScroll,
    [B_TRANSITION_FRONTIER_SQUARES_SPIRAL] = Task_FrontierSquaresSpiral,
    [B_TRANSITION_FRONTIER_CIRCLES_MEET] = Task_FrontierCirclesMeet,
    [B_TRANSITION_FRONTIER_CIRCLES_CROSS] = Task_FrontierCirclesCross,
    [B_TRANSITION_FRONTIER_CIRCLES_ASYMMETRIC_SPIRAL] = Task_FrontierCirclesAsymmetricSpiral,
    [B_TRANSITION_FRONTIER_CIRCLES_SYMMETRIC_SPIRAL] = Task_FrontierCirclesSymmetricSpiral,
    [B_TRANSITION_FRONTIER_CIRCLES_MEET_IN_SEQ] = Task_FrontierCirclesMeetInSeq,
    [B_TRANSITION_FRONTIER_CIRCLES_CROSS_IN_SEQ] = Task_FrontierCirclesCrossInSeq,
    [B_TRANSITION_FRONTIER_CIRCLES_ASYMMETRIC_SPIRAL_IN_SEQ] = Task_FrontierCirclesAsymmetricSpiralInSeq,
    [B_TRANSITION_FRONTIER_CIRCLES_SYMMETRIC_SPIRAL_IN_SEQ] = Task_FrontierCirclesSymmetricSpiralInSeq,
};

static const TransitionStateFunc sTaskHandlers[] =
{
    &Transition_StartIntro,
    &Transition_WaitForIntro,
    &Transition_StartMain,
    &Transition_WaitForMain
};

static const TransitionStateFunc sBlur_Funcs[] =
{
    Blur_Init,
    Blur_Main,
    Blur_End
};

static const TransitionStateFunc sSwirl_Funcs[] =
{
    Swirl_Init,
    Swirl_End,
};

static const TransitionStateFunc sShuffle_Funcs[] =
{
    Shuffle_Init,
    Shuffle_End,
};

static const TransitionStateFunc sAqua_Funcs[] =
{
    Aqua_Init,
    Aqua_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    FramesCountdown,
    PatternWeave_End
};

static const TransitionStateFunc sMagma_Funcs[] =
{
    Magma_Init,
    Magma_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    FramesCountdown,
    PatternWeave_End
};

static const TransitionStateFunc sBigPokeball_Funcs[] =
{
    BigPokeball_Init,
    BigPokeball_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    PatternWeave_End
};

static const TransitionStateFunc sRegice_Funcs[] =
{
    Regi_Init,
    Regice_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    PatternWeave_End
};

static const TransitionStateFunc sRegisteel_Funcs[] =
{
    Regi_Init,
    Registeel_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    PatternWeave_End
};

static const TransitionStateFunc sRegirock_Funcs[] =
{
    Regi_Init,
    Regirock_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    PatternWeave_End
};

static const TransitionStateFunc sKyogre_Funcs[] =
{
    WeatherTrio_BgFadeBlack,
    WeatherTrio_WaitFade,
    Kyogre_Init,
    Kyogre_PalettePulsate,
    Kyogre_PaletteBrighten,
    FramesCountdown,
    WeatherDuo_FadeOut,
    WeatherDuo_End
};

static const TransitionStateFunc sPokeballsTrail_Funcs[] =
{
    PokeballsTrail_Init,
    PokeballsTrail_Main,
    PokeballsTrail_End
};

static const s16 sUnknown_085C8B88[2] = {-16, 256};
static const s16 sUnknown_085C8B8C[5] = {0, 32, 64, 18, 48};
static const s16 sUnknown_085C8B96[2] = {8, -8};

static const TransitionStateFunc sClockwise_BlackFade_Funcs[] =
{
    Clockwise_BlackFade_Init,
    Clockwise_BlackFade_Func2,
    Clockwise_BlackFade_Func3,
    Clockwise_BlackFade_Func4,
    Clockwise_BlackFade_Func5,
    Clockwise_BlackFade_Func6,
    Clockwise_BlackFade_End
};

static const TransitionStateFunc sRipple_Funcs[] =
{
    Ripple_Init,
    Ripple_Func2
};

static const TransitionStateFunc sWave_Funcs[] =
{
    Wave_Init,
    Wave_Func2,
    Wave_End
};

static const TransitionStateFunc sMugshot_Funcs[] =
{
    Mugshot_Init,
    Mugshot_SetGfx,
    Mugshot_ShowBanner,
    Mugshot_StartOpponentSlide,
    Mugshot_WaitStartPlayerSlide,
    Mugshot_WaitPlayerSlide,
    Mugshot_GradualWhiteFade,
    Mugshot_InitFadeWhiteToBlack,
    Mugshot_FadeToBlack,
    Mugshot_End
};

static const u8 sMugshotsTrainerPicIDsTable[MUGSHOTS_COUNT] =
{
    [MUGSHOT_SIDNEY]   = TRAINER_PIC_ELITE_FOUR_SIDNEY,
    [MUGSHOT_PHOEBE]   = TRAINER_PIC_ELITE_FOUR_PHOEBE,
    [MUGSHOT_GLACIA]   = TRAINER_PIC_ELITE_FOUR_GLACIA,
    [MUGSHOT_DRAKE]    = TRAINER_PIC_ELITE_FOUR_DRAKE,
    [MUGSHOT_CHAMPION] = TRAINER_PIC_CHAMPION_WALLACE,
};
static const s16 sMugshotsOpponentRotationScales[MUGSHOTS_COUNT][2] =
{
    [MUGSHOT_SIDNEY] =   {0x200, 0x200},
    [MUGSHOT_PHOEBE] =   {0x200, 0x200},
    [MUGSHOT_GLACIA] =   {0x1B0, 0x1B0},
    [MUGSHOT_DRAKE] =    {0x1A0, 0x1A0},
    [MUGSHOT_CHAMPION] = {0x188, 0x188},
};
static const s16 sMugshotsOpponentCoords[MUGSHOTS_COUNT][2] =
{
    [MUGSHOT_SIDNEY] =   { 0,  0},
    [MUGSHOT_PHOEBE] =   { 0,  0},
    [MUGSHOT_GLACIA] =   {-4,  4},
    [MUGSHOT_DRAKE] =    { 0,  5},
    [MUGSHOT_CHAMPION] = {-8,  7},
};

static const TransitionSpriteCallback sMugshotTrainerPicFuncs[] =
{
    MugshotTrainerPic_Nothing,
    MugshotTrainerPic_SetSlideOffsets,
    MugshotTrainerPic_Slide1,
    MugshotTrainerPic_Slide2,
    MugshotTrainerPic_Nothing,
    MugshotTrainerPic_Slide3,
    MugshotTrainerPic_Nothing
};

static const s16 sTrainerPicSlideOffsets1[2] = {12, -12};
static const s16 sTrainerPicSlideOffsets2[2] = {-1,   1};

static const TransitionStateFunc sSlice_Funcs[] =
{
    Slice_Init,
    Slice_Func2,
    Slice_End
};

static const TransitionStateFunc sShredSplit_Funcs[] =
{
    ShredSplit_Init,
    ShredSplit_Func2,
    ShredSplit_Func3,
    ShredSplit_End
};

static const u8 gUnknown_085C8C64[] = {39, 119};
static const s16 gUnknown_085C8C66[] = {1, -1};

static const TransitionStateFunc sBlackhole1_Funcs[] =
{
    Blackhole_Init,
    Blackhole1_Func2,
    Blackhole1_Func3
};

static const TransitionStateFunc sBlackhole2_Funcs[] =
{
    Blackhole_Init,
    Blackhole2_Func2
};

static const s16 gUnknown_085C8C80[] = {-6, 4};

static const TransitionStateFunc sRectangularSpiral_Funcs[] =
{
    RectangularSpiral_Init,
    RectangularSpiral_Func2,
    RectangularSpiral_End
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

static const TransitionStateFunc sGroudon_Funcs[] =
{
    WeatherTrio_BgFadeBlack,
    WeatherTrio_WaitFade,
    Groudon_Init,
    Groudon_PalettePulsate,
    Groudon_PaletteBrighten,
    FramesCountdown,
    WeatherDuo_FadeOut,
    WeatherDuo_End
};

static const TransitionStateFunc sRayquaza_Funcs[] =
{
    WeatherTrio_BgFadeBlack,
    WeatherTrio_WaitFade,
    Rayquaza_Func3,
    Rayquaza_Func4,
    Rayquaza_Func5,
    Rayquaza_Func6,
    Rayquaza_Func7,
    Rayquaza_Func8,
    Rayquaza_Func9,
    Blackhole1_Func2,
    Blackhole1_Func3
};

static const TransitionStateFunc sWhiteFade_Funcs[] =
{
    WhiteFade_Init,
    WhiteFade_Func2,
    WhiteFade_Func3,
    WhiteFade_Func4,
    WhiteFade_End
};

static const s16 sUnknown_085C8DA0[] = {0, 20, 15, 40, 10, 25, 35, 5};

static const TransitionStateFunc sGridSquares_Funcs[] =
{
    GridSquares_Init,
    GridSquares_Func2,
    GridSquares_End
};

static const TransitionStateFunc sShards_Funcs[] =
{
    Shards_Init,
    Shards_Func2,
    Shards_Func3,
    Shards_Func4,
    Shards_Func5
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

static const TransitionStateFunc sTransitionIntroFuncs[] =
{
    Transition_Intro_1,
    Transition_Intro_2
};

static const struct SpriteFrameImage sSpriteImage_Pokeball[] =
{
    sPokeball_Gfx, sizeof(sPokeball_Gfx)
};

static const union AnimCmd sSpriteAnim_Pokeball[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Pokeball[] =
{
    sSpriteAnim_Pokeball
};

static const union AffineAnimCmd sSpriteAffineAnim_Pokeball1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 1),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd sSpriteAffineAnim_Pokeball2[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 4, 1),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_Pokeball[] =
{
    sSpriteAffineAnim_Pokeball1,
    sSpriteAffineAnim_Pokeball2
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_POKEBALL,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sSpriteAnimTable_Pokeball,
    .images = sSpriteImage_Pokeball,
    .affineAnims = sSpriteAffineAnimTable_Pokeball,
    .callback = SpriteCB_FldEffPokeball
};

static const struct OamData sOam_UnusedBrendanLass =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sImageTable_UnusedBrendan[] =
{
    sUnusedBrendan_Gfx, sizeof(sUnusedBrendan_Gfx)
};

static const struct SpriteFrameImage sImageTable_UnusedLass[] =
{
    sUnusedLass_Gfx, sizeof(sUnusedLass_Gfx)
};

static const union AnimCmd sSpriteAnim_UnusedBrendanLass[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_UnusedBrendanLass[] =
{
    sSpriteAnim_UnusedBrendanLass
};

static const struct SpriteTemplate sSpriteTemplate_UnusedBrendan =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_UNUSED_MUGSHOT,
    .oam = &sOam_UnusedBrendanLass,
    .anims = sSpriteAnimTable_UnusedBrendanLass,
    .images = sImageTable_UnusedBrendan,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MugshotTrainerPic
};

static const struct SpriteTemplate sSpriteTemplate_UnusedLass =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_UNUSED_MUGSHOT,
    .oam = &sOam_UnusedBrendanLass,
    .anims = sSpriteAnimTable_UnusedBrendanLass,
    .images = sImageTable_UnusedLass,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MugshotTrainerPic
};

static const u16 sFieldEffectPal_Pokeball[] = INCBIN_U16("graphics/field_effects/palettes/pokeball.gbapal");

const struct SpritePalette gSpritePalette_Pokeball = {sFieldEffectPal_Pokeball, FLDEFF_PAL_TAG_POKEBALL};

static const u16 sMugshotPal_Sidney[] = INCBIN_U16("graphics/battle_transitions/sidney_bg.gbapal");
static const u16 sMugshotPal_Phoebe[] = INCBIN_U16("graphics/battle_transitions/phoebe_bg.gbapal");
static const u16 sMugshotPal_Glacia[] = INCBIN_U16("graphics/battle_transitions/glacia_bg.gbapal");
static const u16 sMugshotPal_Drake[] = INCBIN_U16("graphics/battle_transitions/drake_bg.gbapal");
static const u16 sMugshotPal_Champion[] = INCBIN_U16("graphics/battle_transitions/wallace_bg.gbapal");
static const u16 sMugshotPal_Brendan[] = INCBIN_U16("graphics/battle_transitions/brendan_bg.gbapal");
static const u16 sMugshotPal_May[] = INCBIN_U16("graphics/battle_transitions/may_bg.gbapal");

static const u16 *const sOpponentMugshotsPals[MUGSHOTS_COUNT] =
{
    [MUGSHOT_SIDNEY] = sMugshotPal_Sidney,
    [MUGSHOT_PHOEBE] = sMugshotPal_Phoebe,
    [MUGSHOT_GLACIA] = sMugshotPal_Glacia,
    [MUGSHOT_DRAKE] = sMugshotPal_Drake,
    [MUGSHOT_CHAMPION] = sMugshotPal_Champion
};

static const u16 *const sPlayerMugshotsPals[GENDER_COUNT] =
{
    [MALE] = sMugshotPal_Brendan,
    [FEMALE] = sMugshotPal_May
};

static const u16 sUnusedTrainerPalette[] = INCBIN_U16("graphics/battle_transitions/unused_trainer.gbapal");
static const struct SpritePalette sSpritePalette_UnusedTrainer = {sUnusedTrainerPalette, PALTAG_UNUSED_MUGSHOT};

static const u16 sBigPokeball_Tilemap[] = INCBIN_U16("graphics/battle_transitions/big_pokeball_map.bin");
static const u16 sMugshotsTilemap[] = INCBIN_U16("graphics/battle_transitions/elite_four_bg_map.bin");

static const TransitionStateFunc sFrontierLogoWiggle_Funcs[] =
{
    FrontierLogoWiggle_Init,
    FrontierLogoWiggle_SetGfx,
    PatternWeave_1,
    PatternWeave_2,
    PatternWeave_3,
    PatternWeave_End
};

static const TransitionStateFunc sFrontierLogoWave_Funcs[] =
{
    FrontierLogoWave_Init,
    FrontierLogoWave_SetGfx,
    FrontierLogoWave_Func3,
    FrontierLogoWave_Func4
};

static const TransitionStateFunc sFrontierSquares_Funcs[] =
{
    FrontierSquares_Init,
    FrontierSquares_Func2,
    FrontierSquares_Func3,
    FrontierSquares_End
};

static const TransitionStateFunc sFrontierSquaresSpiral_Funcs[] =
{
    FrontierSquaresSpiral_Init,
    FrontierSquaresSpiral_Func2,
    FrontierSquaresSpiral_Func3,
    FrontierSquaresSpiral_Func4,
    FrontierSquares_End
};

static const TransitionStateFunc sFrontierSquaresScroll_Funcs[] =
{
    FrontierSquaresScroll_Init,
    FrontierSquaresScroll_Func2,
    FrontierSquaresScroll_Func3,
    FrontierSquaresScroll_Func4,
    FrontierSquaresScroll_End
};

static const u8 gUnknown_085C9A30[] = {
    0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22,
    0x1b, 0x14, 0x0d, 0x06, 0x05, 0x04, 0x03,
    0x02, 0x01, 0x00, 0x07, 0x0e, 0x15, 0x16,
    0x17, 0x18, 0x19, 0x1a, 0x13, 0x0c, 0x0b,
    0x0a, 0x09, 0x08, 0x0f, 0x10, 0x11, 0x12
};

static const u8 gUnknown_085C9A53[] = {
    0x00, 0x10, 0x29, 0x16, 0x2c, 0x02, 0x2b, 0x15,
    0x2e, 0x1b, 0x09, 0x30, 0x26, 0x05, 0x39, 0x3b,
    0x0c, 0x3f, 0x23, 0x1c, 0x0a, 0x35, 0x07, 0x31,
    0x27, 0x17, 0x37, 0x01, 0x3e, 0x11, 0x3d, 0x1e,
    0x06, 0x22, 0x0f, 0x33, 0x20, 0x3a, 0x0d, 0x2d,
    0x25, 0x34, 0x0b, 0x18, 0x3c, 0x13, 0x38, 0x21,
    0x1d, 0x32, 0x28, 0x36, 0x0e, 0x03, 0x2f, 0x14,
    0x12, 0x19, 0x04, 0x24, 0x1a, 0x2a, 0x1f, 0x08
};

//---------------------------
// Main transition functions
//---------------------------

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

// Unused
static void TestBattleTransition(u8 transitionId)
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
    u8 taskId = FindTaskIdByFunc(Task_BattleTransition);
    if (gTasks[taskId].tTransitionDone)
    {
        DestroyTask(taskId);
        FREE_AND_SET_NULL(sTransitionData);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void LaunchBattleTransitionTask(u8 transitionId)
{
    u8 taskId = CreateTask(Task_BattleTransition, 2);
    gTasks[taskId].tTransitionId = transitionId;
    sTransitionData = AllocZeroed(sizeof(*sTransitionData));
}

static void Task_BattleTransition(u8 taskId)
{
    while (sTaskHandlers[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Transition_StartIntro(struct Task *task)
{
    SetWeatherScreenFadeOut();
    CpuCopy32(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    if (sTasks_Intro[task->tTransitionId] != NULL)
    {
        CreateTask(sTasks_Intro[task->tTransitionId], 4);
        task->tState++;
        return FALSE;
    }
    else
    {
        task->tState = 2;
        return TRUE;
    }
}

static bool8 Transition_WaitForIntro(struct Task *task)
{
    if (FindTaskIdByFunc(sTasks_Intro[task->tTransitionId]) == TASK_NONE)
    {
        task->tState++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 Transition_StartMain(struct Task *task)
{
    CreateTask(sTasks_Main[task->tTransitionId], 0);
    task->tState++;
    return FALSE;
}

static bool8 Transition_WaitForMain(struct Task *task)
{
    task->tTransitionDone = FALSE;
    if (FindTaskIdByFunc(sTasks_Main[task->tTransitionId]) == TASK_NONE)
        task->tTransitionDone = TRUE;
    return FALSE;
}

#undef tTransitionId
#undef tTransitionDone

static void Task_Intro(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        gTasks[taskId].tState++;
        CreateIntroTask(0, 0, 3, 2, 2);
    }
    else if (IsIntroTaskDone())
    {
        DestroyTask(taskId);
    }
}

#define tFuncState          data[7]
#define tOpponentSpriteId   data[13]
#define tPlayerSpriteId     data[14]
#define tMugshotId          data[15]

//--------------------
// B_TRANSITION_BLUR
//--------------------

#define tDelay   data[1]
#define tCounter data[2]

static void Task_Blur(u8 taskId)
{
    while (sBlur_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Blur_Init(struct Task *task)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    SetGpuRegBits(REG_OFFSET_BG3CNT, BGCNT_MOSAIC);
    task->tState++;
    return TRUE;
}

static bool8 Blur_Main(struct Task *task)
{
    if (task->tDelay != 0)
    {
        task->tDelay--;
    }
    else
    {
        task->tDelay = 4;
        if (++task->tCounter == 10)
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        SetGpuReg(REG_OFFSET_MOSAIC, (task->tCounter & 15) * 17);
        if (task->tCounter > 14)
            task->tState++;
    }
    return FALSE;
}

static bool8 Blur_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Task_Blur);
        DestroyTask(taskId);
    }
    return FALSE;
}

#undef tDelay
#undef tCounter

//--------------------
// B_TRANSITION_SWIRL
//--------------------

#define tSinIndex  data[1]
#define tAmplitude data[2]

static void Task_Swirl(u8 taskId)
{
    while (sSwirl_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Swirl_Init(struct Task *task)
{
    InitTransitionData();
    ScanlineEffect_Clear();
    BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 16, RGB_BLACK);
    SetSinWave(gScanlineEffectRegBuffers[1], sTransitionData->cameraX, 0, 2, 0, DISPLAY_HEIGHT);

    SetVBlankCallback(VBlankCB_Swirl);
    SetHBlankCallback(HBlankCB_Swirl);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

static bool8 Swirl_End(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    task->tSinIndex += 4;
    task->tAmplitude += 8;

    SetSinWave(gScanlineEffectRegBuffers[0], sTransitionData->cameraX, task->tSinIndex, 2, task->tAmplitude, DISPLAY_HEIGHT);

    if (!gPaletteFade.active)
    {
        u8 taskId = FindTaskIdByFunc(Task_Swirl);
        DestroyTask(taskId);
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Swirl(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
}

static void HBlankCB_Swirl(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1HOFS = var;
    REG_BG2HOFS = var;
    REG_BG3HOFS = var;
}

#undef tSinIndex
#undef tAmplitude

//----------------------
// B_TRANSITION_SHUFFLE
//----------------------

#define tSinVal    data[1]
#define tAmplitude data[2]

static void Task_Shuffle(u8 taskId)
{
    while (sShuffle_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Shuffle_Init(struct Task *task)
{
    InitTransitionData();
    ScanlineEffect_Clear();

    BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 16, RGB_BLACK);
    memset(gScanlineEffectRegBuffers[1], sTransitionData->cameraY, DISPLAY_HEIGHT * 2);

    SetVBlankCallback(VBlankCB_Shuffle);
    SetHBlankCallback(HBlankCB_Shuffle);

    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    task->tState++;
    return FALSE;
}

static bool8 Shuffle_End(struct Task *task)
{
    u8 i;
    u16 amplitude, sinVal;

    sTransitionData->VBlank_DMA = FALSE;
    sinVal = task->tSinVal;
    amplitude = task->tAmplitude >> 8;
    task->tSinVal += 4224;
    task->tAmplitude += 384;

    for (i = 0; i < DISPLAY_HEIGHT; i++, sinVal += 4224)
    {
        u16 sinIndex = sinVal / 256;
        gScanlineEffectRegBuffers[0][i] = sTransitionData->cameraY + Sin(sinIndex, amplitude);
    }

    if (!gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Task_Shuffle));

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Shuffle(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
}

static void HBlankCB_Shuffle(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

#undef tSinVal
#undef tAmplitude

//------------------------------------------------------------------------
// B_TRANSITION_BIG_POKEBALL, B_TRANSITION_AQUA, B_TRANSITION_MAGMA,
// B_TRANSITION_REGICE, B_TRANSITION_REGISTEEL, B_TRANSITION_REGIROCK
// and B_TRANSITION_KYOGRE.
//
// With the exception of B_TRANSITION_KYOGRE, all of the above transitions
// use the same weave effect (see the PatternWeave functions).
// Unclear why Kyogre's was grouped here and not with Groudon/Rayquaza's.
//------------------------------------------------------------------------

#define tBlendTarget1 data[1]
#define tBlendTarget2 data[2]
#define tBlendDelay   data[3]

// Data 1-3 change purpose for PatternWeave_End
#define tEndAmplitude      data[1]
#define tEndAmplitudeDelta data[2]
#define tVBlankSet         data[3]

#define tSinIndex     data[4]
#define tAmplitude    data[5]
#define tEndDelay     data[8]

static void Task_BigPokeball(u8 taskId)
{
    while (sBigPokeball_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Aqua(u8 taskId)
{
    while (sAqua_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Magma(u8 taskId)
{
    while (sMagma_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Regice(u8 taskId)
{
    while (sRegice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Registeel(u8 taskId)
{
    while (sRegisteel_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Regirock(u8 taskId)
{
    while (sRegirock_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Kyogre(u8 taskId)
{
    while (sKyogre_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void InitPatternWeaveTransition(struct Task *task)
{
    s32 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    task->tBlendTarget1 = 16;
    task->tBlendTarget2 = 0;
    task->tSinIndex = 0;
    task->tAmplitude = 0x4000;
    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = 0;
    sTransitionData->WIN0H = DISPLAY_WIDTH;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;
    sTransitionData->BLDCNT = BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL;
    sTransitionData->BLDALPHA = BLDALPHA_BLEND(task->tBlendTarget2, task->tBlendTarget1);

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = DISPLAY_WIDTH;

    SetVBlankCallback(VBlankCB_PatternWeave);
}

static bool8 Aqua_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    task->tEndDelay = 60;
    InitPatternWeaveTransition(task);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sTeamAqua_Tileset, tileset);
    LoadPalette(sEvilTeam_Palette, 0xF0, sizeof(sEvilTeam_Palette));

    task->tState++;
    return FALSE;
}

static bool8 Magma_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    task->tEndDelay = 60;
    InitPatternWeaveTransition(task);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sTeamMagma_Tileset, tileset);
    LoadPalette(sEvilTeam_Palette, 0xF0, sizeof(sEvilTeam_Palette));

    task->tState++;
    return FALSE;
}

static bool8 Regi_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    task->tEndDelay = 60;
    InitPatternWeaveTransition(task);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    CpuCopy16(sRegis_Tileset, tileset, 0x2000);

    task->tState++;
    return FALSE;
}

static bool8 BigPokeball_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    InitPatternWeaveTransition(task);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    CpuCopy16(sBigPokeball_Tileset, tileset, sizeof(sBigPokeball_Tileset));
    LoadPalette(sFieldEffectPal_Pokeball, 0xF0, sizeof(sFieldEffectPal_Pokeball));

    task->tState++;
    return FALSE;
}

static bool8 BigPokeball_SetGfx(struct Task *task)
{
    s16 i, j;
    u16 *tilemap, *tileset;
    const u16 *bigPokeballMap;

    GetBg0TilesDst(&tilemap, &tileset);
    bigPokeballMap = sBigPokeball_Tilemap;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++, bigPokeballMap++)
            SET_TILEMAP_TILE(tilemap, i, j, *bigPokeballMap | 0xF000);
    }

    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return TRUE;
}

static bool8 Aqua_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sTeamAqua_Tilemap, tilemap);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return FALSE;
}

static bool8 Magma_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sTeamMagma_Tilemap, tilemap);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return FALSE;
}

static bool8 Regice_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LoadPalette(sRegice_Palette, 0xF0, sizeof(sRegice_Palette));
    CpuCopy16(sRegice_Tilemap, tilemap, 0x500);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return FALSE;
}

static bool8 Registeel_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LoadPalette(sRegisteel_Palette, 0xF0, sizeof(sRegisteel_Palette));
    CpuCopy16(sRegisteel_Tilemap, tilemap, 0x500);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return FALSE;
}

static bool8 Regirock_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LoadPalette(sRegirock_Palette, 0xF0, sizeof(sRegirock_Palette));
    CpuCopy16(sRegirock_Tilemap, tilemap, 0x500);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude, DISPLAY_HEIGHT);

    task->tState++;
    return FALSE;
}

#define tTimer data[1]

static bool8 Kyogre_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sKyogre_Tileset, tileset);
    LZ77UnCompVram(sKyogre_Tilemap, tilemap);

    task->tState++;
    return FALSE;
}

static bool8 Kyogre_PalettePulsate(struct Task *task)
{
    if (task->tTimer % 3 == 0)
    {
        u16 var = task->tTimer % 30;
        var /= 3;
        LoadPalette(sKyogre1_Palette + (var * 16), 0xF0, 0x20);
    }
    if (++task->tTimer > 58)
    {
        task->tState++;
        task->tTimer = 0;
    }

    return FALSE;
}

static bool8 Kyogre_PaletteBrighten(struct Task *task)
{
    if (task->tTimer % 5 == 0)
    {
        s16 var = task->tTimer / 5;
        LoadPalette(sKyogre2_Palette + (var * 16), 0xF0, 0x20);
    }
    if (++task->tTimer > 68)
    {
        task->tState++;
        task->tTimer = 0;
        task->tEndDelay = 30;
    }

    return FALSE;
}

static bool8 WeatherDuo_FadeOut(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_OBJECTS | (1 << 15), 1, 0, 16, RGB_BLACK);
    task->tState++;
    return FALSE;
}

static bool8 WeatherDuo_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DmaStop(0);
        FadeScreenBlack();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    return FALSE;
}

#undef tTimer

// The PatternWeave_ functions are used by several different transitions.
// They create an effect where a pattern/image (such as the Magma emblem) is
// formed by a shimmering weave effect.
static bool8 PatternWeave_1(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    if (task->tBlendDelay == 0 || --task->tBlendDelay == 0)
    {
        task->tBlendTarget2++;
        task->tBlendDelay = 2;
    }
    sTransitionData->BLDALPHA = BLDALPHA_BLEND(task->tBlendTarget2, task->tBlendTarget1);
    if (task->tBlendTarget2 > 15)
        task->tState++;
    task->tSinIndex += 8;
    task->tAmplitude -= 256;

    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude >> 8, DISPLAY_HEIGHT);

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 PatternWeave_2(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    if (task->tBlendDelay == 0 || --task->tBlendDelay == 0)
    {
        task->tBlendTarget1--;
        task->tBlendDelay = 2;
    }
    sTransitionData->BLDALPHA = BLDALPHA_BLEND(task->tBlendTarget2, task->tBlendTarget1);
    if (task->tBlendTarget1 == 0)
        task->tState++;
    task->tSinIndex += 8;
    task->tAmplitude -= 256;

    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude >> 8, DISPLAY_HEIGHT);

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 PatternWeave_3(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    task->tSinIndex += 8;
    task->tAmplitude -= 256;

    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->tSinIndex, 132, task->tAmplitude >> 8, DISPLAY_HEIGHT);

    if (task->tAmplitude <= 0)
    {
        task->tState++;
        task->tEndAmplitude = 160;
        task->tEndAmplitudeDelta = 256;
        task->tVBlankSet = FALSE;
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 FramesCountdown(struct Task *task)
{
    if (--task->tEndDelay == 0)
        task->tState++;
    return FALSE;
}

static bool8 WeatherTrio_BgFadeBlack(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_BG, 1, 0, 16, RGB_BLACK);
    task->tState++;
    return FALSE;
}

static bool8 WeatherTrio_WaitFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->tState++;
    return FALSE;
}

static bool8 PatternWeave_End(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    if (task->tEndAmplitudeDelta < 1024)
        task->tEndAmplitudeDelta += 128;
    if (task->tEndAmplitude != 0)
    {
        task->tEndAmplitude -= task->tEndAmplitudeDelta >> 8;
        if (task->tEndAmplitude < 0)
            task->tEndAmplitude = 0;
    }
    sub_814A014(gScanlineEffectRegBuffers[0], 120, 80, task->tEndAmplitude);
    if (task->tEndAmplitude == 0)
    {
        SetVBlankCallback(NULL);
        DmaStop(0);
        FadeScreenBlack();
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        if (!task->tVBlankSet)
        {
            task->tVBlankSet++;
            SetVBlankCallback(VBlankCB1_BigPokeball);
        }

        sTransitionData->VBlank_DMA++;
    }

    return FALSE;
}

static void Transition_BigPokeball_Vblank(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    REG_BLDCNT = sTransitionData->BLDCNT;
    REG_BLDALPHA = sTransitionData->BLDALPHA;
}

static void VBlankCB_PatternWeave(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_BG0HOFS, B_TRANS_DMA_FLAGS);
}

static void VBlankCB1_BigPokeball(void)
{
    Transition_BigPokeball_Vblank();
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

#undef tAmplitude
#undef tSinIndex
#undef tBlendTarget1
#undef tBlendTarget2
#undef tEndAmplitude
#undef tVBlankSet

static void Task_PokeballsTrail(u8 taskId)
{
    while (sPokeballsTrail_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 PokeballsTrail_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuSet(sPokeballTrail_Tileset, tileset, 0x20);
    CpuFill32(0, tilemap, BG_SCREEN_SIZE);
    LoadPalette(sFieldEffectPal_Pokeball, 0xF0, sizeof(sFieldEffectPal_Pokeball));

    task->tState++;
    return FALSE;
}

static bool8 PokeballsTrail_Main(struct Task *task)
{
    s16 i;
    s16 rand;
    s16 xCoords[ARRAY_COUNT(sUnknown_085C8B88)];
    s16 arr1[ARRAY_COUNT(sUnknown_085C8B8C)];

    memcpy(xCoords, sUnknown_085C8B88, sizeof(sUnknown_085C8B88));
    memcpy(arr1, sUnknown_085C8B8C, sizeof(sUnknown_085C8B8C));
    rand = Random() & 1;
    for (i = 0; i <= 4; i++, rand ^= 1)
    {
        gFieldEffectArguments[0] = xCoords[rand];   // x
        gFieldEffectArguments[1] = (i * 32) + 16;   // y
        gFieldEffectArguments[2] = rand;
        gFieldEffectArguments[3] = arr1[i];
        FieldEffectStart(FLDEFF_POKEBALL);
    }

    task->tState++;
    return FALSE;
}

static bool8 PokeballsTrail_End(struct Task *task)
{
    if (!FieldEffectActiveListContains(FLDEFF_POKEBALL))
    {
        FadeScreenBlack();
        DestroyTask(FindTaskIdByFunc(Task_PokeballsTrail));
    }
    return FALSE;
}

#define sData0 data[0]
#define sData1 data[1]
#define sData2 data[2]

bool8 FldEff_Pokeball(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_Pokeball, gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].sData0 = gFieldEffectArguments[2];
    gSprites[spriteId].sData1 = gFieldEffectArguments[3];
    gSprites[spriteId].sData2 = -1;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], gFieldEffectArguments[2]);
    return FALSE;
}

static void SpriteCB_FldEffPokeball(struct Sprite *sprite)
{
    s16 arr0[ARRAY_COUNT(sUnknown_085C8B96)];

    memcpy(arr0, sUnknown_085C8B96, sizeof(sUnknown_085C8B96));
    if (sprite->sData1 != 0)
    {
        sprite->sData1--;
    }
    else
    {
        if (sprite->x >= 0 && sprite->x <= DISPLAY_WIDTH)
        {
            s16 posX = sprite->x >> 3;
            s16 posY = sprite->y >> 3;

            if (posX != sprite->sData2)
            {
                u32 var;
                u16 *ptr;

                sprite->sData2 = posX;
                var = (((REG_BG0CNT >> 8) & 0x1F) << 11);
                ptr = (u16 *)(VRAM + var);

                SET_TILEMAP_TILE(ptr, posY - 2, posX, 0xF001);
                SET_TILEMAP_TILE(ptr, posY - 1, posX, 0xF001);
                SET_TILEMAP_TILE(ptr, posY - 0, posX, 0xF001);
                SET_TILEMAP_TILE(ptr, posY + 1, posX, 0xF001);
            }
        }
        sprite->x += arr0[sprite->sData0];
        if (sprite->x < -15 || sprite->x > DISPLAY_WIDTH + 15)
            FieldEffectStop(sprite, FLDEFF_POKEBALL);
    }
}

#undef sData0
#undef sData1
#undef sData2

static void Task_Clockwise_BlackFade(u8 taskId)
{
    while (sClockwise_BlackFade_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Clockwise_BlackFade_Init(struct Task *task)
{
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->WININ = 0;
    sTransitionData->WINOUT = WINOUT_WIN01_ALL;
    sTransitionData->WIN0H = WIN_RANGE(DISPLAY_WIDTH, DISPLAY_WIDTH + 1);
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = WIN_RANGE(DISPLAY_WIDTH + 3, DISPLAY_WIDTH + 4);

    SetVBlankCallback(VBlankCB_Clockwise_BlackFade);
    sTransitionData->data[4] = 120;

    task->tState++;
    return TRUE;
}

static bool8 Clockwise_BlackFade_Func2(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionData->data, 120, 80, sTransitionData->data[4], -1, 1, 1);
    do
    {
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = (sTransitionData->data[2] + 1) | 0x7800;
    } while (!sub_814A228(sTransitionData->data, 1, 1));

    sTransitionData->data[4] += 16;
    if (sTransitionData->data[4] >= DISPLAY_WIDTH)
    {
        sTransitionData->data[5] = 0;
        task->tState++;
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Clockwise_BlackFade_Func3(struct Task *task)
{
    s16 r1, r3;
    vu8 var = 0;

    sTransitionData->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionData->data, 120, 80, 240, sTransitionData->data[5], 1, 1);

    while (1)
    {
        r1 = 120, r3 = sTransitionData->data[2] + 1;
        if (sTransitionData->data[5] >= DISPLAY_HEIGHT / 2)
            r1 = sTransitionData->data[2], r3 = DISPLAY_WIDTH;
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = (r3) | (r1 << 8);
        if (var != 0)
            break;
        var = sub_814A228(sTransitionData->data, 1, 1);
    }

    sTransitionData->data[5] += 8;
    if (sTransitionData->data[5] >= DISPLAY_HEIGHT)
    {
        sTransitionData->data[4] = DISPLAY_WIDTH;
        task->tState++;
    }
    else
    {
        while (sTransitionData->data[3] < sTransitionData->data[5])
            gScanlineEffectRegBuffers[0][++sTransitionData->data[3]] = (r3) | (r1 << 8);
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Clockwise_BlackFade_Func4(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionData->data, 120, 80, sTransitionData->data[4], 160, 1, 1);
    do
    {
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = (sTransitionData->data[2] << 8) | 0xF0;
    } while (!sub_814A228(sTransitionData->data, 1, 1));

    sTransitionData->data[4] -= 16;
    if (sTransitionData->data[4] <= 0)
    {
        sTransitionData->data[5] = DISPLAY_HEIGHT;
        task->tState++;
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Clockwise_BlackFade_Func5(struct Task *task)
{
    s16 r1, r2, var4;
    vu8 var = 0;

    sTransitionData->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionData->data, 120, 80, 0, sTransitionData->data[5], 1, 1);

    while (1)
    {
        r1 = (gScanlineEffectRegBuffers[0][sTransitionData->data[3]]) & 0xFF;
        r2 = sTransitionData->data[2];
        if (sTransitionData->data[5] <= DISPLAY_HEIGHT / 2)
            r2 = 120, r1 = sTransitionData->data[2];
        var4 = (r1) | (r2 << 8);
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = var4;
        if (var != 0)
            break;
        var = sub_814A228(sTransitionData->data, 1, 1);
    }

    sTransitionData->data[5] -= 8;
    if (sTransitionData->data[5] <= 0)
    {
        sTransitionData->data[4] = 0;
        task->tState++;
    }
    else
    {
        while (sTransitionData->data[3] > sTransitionData->data[5])
        {
            gScanlineEffectRegBuffers[0][--sTransitionData->data[3]] = (r1) | (r2 << 8);
        }
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Clockwise_BlackFade_Func6(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;

    sub_814A1AC(sTransitionData->data, 120, 80, sTransitionData->data[4], 0, 1, 1);
    do
    {
        s16 r2, r3;

        r2 = 120, r3 = sTransitionData->data[2];
        if (sTransitionData->data[2] >= 120)
            r2 = 0, r3 = DISPLAY_WIDTH;
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = (r3) | (r2 << 8);

    } while (!sub_814A228(sTransitionData->data, 1, 1));

    sTransitionData->data[4] += 16;
    if (sTransitionData->data[2] > 120)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Clockwise_BlackFade_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
    DestroyTask(FindTaskIdByFunc(Task_Clockwise_BlackFade));
    return FALSE;
}

static void VBlankCB_Clockwise_BlackFade(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    REG_WIN0H = gScanlineEffectRegBuffers[1][0];
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

static void Task_Ripple(u8 taskId)
{
    while (sRipple_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Ripple_Init(struct Task *task)
{
    u8 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = sTransitionData->cameraY;

    SetVBlankCallback(VBlankCB_Ripple);
    SetHBlankCallback(HBlankCB_Ripple);

    EnableInterrupts(INTR_FLAG_HBLANK);

    task->tState++;
    return TRUE;
}

static bool8 Ripple_Func2(struct Task *task)
{
    u8 i;
    s16 r3;
    u16 r4, r8;

    sTransitionData->VBlank_DMA = FALSE;

    r3 = task->data[2] >> 8;
    r4 = task->data[1];
    r8 = 384;
    task->data[1] += 0x400;
    if (task->data[2] <= 0x1FFF)
        task->data[2] += 0x180;

    for (i = 0; i < DISPLAY_HEIGHT; i++, r4 += r8)
    {
        s16 var = r4 >> 8;
        gScanlineEffectRegBuffers[0][i] = sTransitionData->cameraY + Sin(var & 0xffff, r3);
    }

    if (++task->data[3] == 81)
    {
        task->data[4]++;
        BeginNormalPaletteFade(PALETTES_ALL, -2, 0, 16, RGB_BLACK);
    }

    if (task->data[4] != 0 && !gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Task_Ripple));

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_Ripple(void)
{
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
}

static void HBlankCB_Ripple(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG1VOFS = var;
    REG_BG2VOFS = var;
    REG_BG3VOFS = var;
}

// B_TRANSITION_WAVE
static void Task_Wave(u8 taskId)
{
    while (sWave_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Wave_Init(struct Task *task)
{
    u8 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = 0;
    sTransitionData->WIN0H = DISPLAY_WIDTH;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = DISPLAY_WIDTH + 2;

    SetVBlankCallback(VBlankCB_Wave);

    task->tState++;
    return TRUE;
}

static bool8 Wave_Func2(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    bool8 nextFunc;

    sTransitionData->VBlank_DMA = FALSE;
    toStore = gScanlineEffectRegBuffers[0];
    r5 = task->data[2];
    task->data[2] += 16;
    task->data[1] += 8;

    for (i = 0, nextFunc = TRUE; i < DISPLAY_HEIGHT; i++, r5 += 4, toStore++)
    {
        s16 value = task->data[1] + Sin(r5, 40);
        if (value < 0)
            value = 0;
        if (value > DISPLAY_WIDTH)
            value = DISPLAY_WIDTH;
        *toStore = (value << 8) | (DISPLAY_WIDTH + 1);
        if (value < DISPLAY_WIDTH)
            nextFunc = FALSE;
    }
    if (nextFunc)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Wave_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
    DestroyTask(FindTaskIdByFunc(Task_Wave));
    return FALSE;
}

static void VBlankCB_Wave(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

static void Task_Sidney(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_SIDNEY;
    DoMugshotTransition(taskId);
}

static void Task_Phoebe(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_PHOEBE;
    DoMugshotTransition(taskId);
}

static void Task_Glacia(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_GLACIA;
    DoMugshotTransition(taskId);
}

static void Task_Drake(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_DRAKE;
    DoMugshotTransition(taskId);
}

static void Task_Champion(u8 taskId)
{
    gTasks[taskId].tMugshotId = MUGSHOT_CHAMPION;
    DoMugshotTransition(taskId);
}

static void DoMugshotTransition(u8 taskId)
{
    while (sMugshot_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Mugshot_Init(struct Task *task)
{
    u8 i;

    InitTransitionData();
    ScanlineEffect_Clear();
    Mugshots_CreateTrainerPics(task);

    task->data[1] = 0;
    task->data[2] = 1;
    task->data[3] = DISPLAY_WIDTH - 1;
    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = 0xF0F1;

    SetVBlankCallback(VBlankCB0_Mugshots);

    task->tState++;
    return FALSE;
}

static bool8 Mugshot_SetGfx(struct Task *task)
{
    s16 i, j;
    u16 *tilemap, *tileset;
    const u16 *mugshotsMap;

    mugshotsMap = sMugshotsTilemap;
    GetBg0TilesDst(&tilemap, &tileset);
    CpuSet(sEliteFour_Tileset, tileset, 0xF0);
    LoadPalette(sOpponentMugshotsPals[task->tMugshotId], 0xF0, 0x20);
    LoadPalette(sPlayerMugshotsPals[gSaveBlock2Ptr->playerGender], 0xFA, 0xC);

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++, mugshotsMap++)
            SET_TILEMAP_TILE(tilemap, i, j, *mugshotsMap | 0xF000);
    }

    EnableInterrupts(INTR_FLAG_HBLANK);

    SetHBlankCallback(HBlankCB_Mugshots);
    task->tState++;
    return FALSE;
}

static bool8 Mugshot_ShowBanner(struct Task *task)
{
    u8 i, r5;
    u16* toStore;
    s16 value;
    s32 mergedValue;

    sTransitionData->VBlank_DMA = FALSE;

    toStore = gScanlineEffectRegBuffers[0];
    r5 = task->data[1];
    task->data[1] += 16;

    for (i = 0; i < DISPLAY_HEIGHT / 2; i++, toStore++, r5 += 16)
    {
        value = task->data[2] + Sin(r5, 16);
        if (value < 0)
            value = 1;
        if (value > DISPLAY_WIDTH)
            value = DISPLAY_WIDTH;
        *toStore = value;
    }
    for (; i < DISPLAY_HEIGHT; i++, toStore++, r5 += 16)
    {
        value = task->data[3] - Sin(r5, 16);
        if (value < 0)
            value = 0;
        if (value > DISPLAY_WIDTH - 1)
            value = DISPLAY_WIDTH - 1;
        *toStore = (value << 8) | (DISPLAY_WIDTH);
    }

    task->data[2] += 8;
    task->data[3] -= 8;
    if (task->data[2] > DISPLAY_WIDTH)
        task->data[2] = DISPLAY_WIDTH;
    if (task->data[3] < 0)
        task->data[3] = 0;
    mergedValue = *(s32*)(&task->data[2]);
    if (mergedValue == DISPLAY_WIDTH)
        task->tState++;

    sTransitionData->BG0HOFS_Lower -= 8;
    sTransitionData->BG0HOFS_Upper += 8;
    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Mugshot_StartOpponentSlide(struct Task *task)
{
    u8 i;
    u16* toStore;

    sTransitionData->VBlank_DMA = FALSE;

    for (i = 0, toStore = gScanlineEffectRegBuffers[0]; i < DISPLAY_HEIGHT; i++, toStore++)
        *toStore = DISPLAY_WIDTH;

    task->tState++;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;

    sTransitionData->BG0HOFS_Lower -= 8;
    sTransitionData->BG0HOFS_Upper += 8;

    SetTrainerPicSlideTable(task->tOpponentSpriteId, 0);
    SetTrainerPicSlideTable(task->tPlayerSpriteId, 1);
    IncrementTrainerPicState(task->tOpponentSpriteId);

    PlaySE(SE_MUGSHOT);

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Mugshot_WaitStartPlayerSlide(struct Task *task)
{
    sTransitionData->BG0HOFS_Lower -= 8;
    sTransitionData->BG0HOFS_Upper += 8;
    
    // Start player's pic slide in once the opponent is finished
    if (IsTrainerPicSlideDone(task->tOpponentSpriteId))
    {
        task->tState++;
        IncrementTrainerPicState(task->tPlayerSpriteId);
    }
    return FALSE;
}

static bool8 Mugshot_WaitPlayerSlide(struct Task *task)
{
    sTransitionData->BG0HOFS_Lower -= 8;
    sTransitionData->BG0HOFS_Upper += 8;

    if (IsTrainerPicSlideDone(task->tPlayerSpriteId))
    {
        sTransitionData->VBlank_DMA = FALSE;
        SetVBlankCallback(NULL);
        DmaStop(0);
        memset(gScanlineEffectRegBuffers[0], 0, DISPLAY_HEIGHT * 2);
        memset(gScanlineEffectRegBuffers[1], 0, DISPLAY_HEIGHT * 2);
        SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        task->tState++;
        task->data[3] = 0;
        task->data[4] = 0;
        sTransitionData->BLDCNT = BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN;
        SetVBlankCallback(VBlankCB1_Mugshots);
    }
    return FALSE;
}

static bool8 Mugshot_GradualWhiteFade(struct Task *task)
{
    bool32 active;

    sTransitionData->VBlank_DMA = FALSE;
    active = TRUE;
    sTransitionData->BG0HOFS_Lower -= 8;
    sTransitionData->BG0HOFS_Upper += 8;

    if (task->data[4] < DISPLAY_HEIGHT / 2)
        task->data[4] += 2;
    if (task->data[4] > DISPLAY_HEIGHT / 2)
        task->data[4] = DISPLAY_HEIGHT / 2;

    if (++task->data[3] & 1)
    {
        s16 i;
        for (i = 0, active = FALSE; i <= task->data[4]; i++)
        {
            s16 index1 = DISPLAY_HEIGHT / 2 - i;
            s16 index2 = DISPLAY_HEIGHT / 2 + i;
            if (gScanlineEffectRegBuffers[0][index1] <= 15)
            {
                active = TRUE;
                gScanlineEffectRegBuffers[0][index1]++;
            }
            if (gScanlineEffectRegBuffers[0][index2] <= 15)
            {
                active = TRUE;
                gScanlineEffectRegBuffers[0][index2]++;
            }
        }
    }

    if (task->data[4] == DISPLAY_HEIGHT / 2 && !active)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Mugshot_InitFadeWhiteToBlack(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    sTransitionData->BLDCNT = 0xFF;
    task->data[3] = 0;

    task->tState++;
    return TRUE;
}

static bool8 Mugshot_FadeToBlack(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;

    task->data[3]++;
    memset(gScanlineEffectRegBuffers[0], task->data[3], DISPLAY_HEIGHT * 2);
    if (task->data[3] > 15)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Mugshot_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
    DestroyTask(FindTaskIdByFunc(task->func));
    return FALSE;
}

static void VBlankCB0_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_BG0VOFS = sTransitionData->BG0VOFS;
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

static void VBlankCB1_Mugshots(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA != 0)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_BLDCNT = sTransitionData->BLDCNT;
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_BLDY, B_TRANS_DMA_FLAGS);
}

static void HBlankCB_Mugshots(void)
{
    if (REG_VCOUNT < DISPLAY_HEIGHT / 2)
        REG_BG0HOFS = sTransitionData->BG0HOFS_Lower;
    else
        REG_BG0HOFS = sTransitionData->BG0HOFS_Upper;
}

// data fields for player/opponent sprites in mugshots
#define sState          data[0]
#define sOffsetX        data[1]
#define sOffsetX2       data[2]
#define sDone           data[6]
#define sSlideTableId   data[7]

static void Mugshots_CreateTrainerPics(struct Task *task)
{
    struct Sprite *opponentSprite, *playerSprite;

    s16 mugshotId = task->tMugshotId;
    task->tOpponentSpriteId = CreateTrainerSprite(sMugshotsTrainerPicIDsTable[mugshotId],
                                                     sMugshotsOpponentCoords[mugshotId][0] - 32,
                                                     sMugshotsOpponentCoords[mugshotId][1] + 42,
                                                     0, gDecompressionBuffer);
    task->tPlayerSpriteId = CreateTrainerSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender),
                                                     DISPLAY_WIDTH + 32,
                                                     106,
                                                     0, gDecompressionBuffer);

    opponentSprite = &gSprites[task->tOpponentSpriteId];
    playerSprite = &gSprites[task->tPlayerSpriteId];

    opponentSprite->callback = SpriteCB_MugshotTrainerPic;
    playerSprite->callback = SpriteCB_MugshotTrainerPic;

    opponentSprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    playerSprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;

    opponentSprite->oam.matrixNum = AllocOamMatrix();
    playerSprite->oam.matrixNum = AllocOamMatrix();

    opponentSprite->oam.shape = SPRITE_SHAPE(64x32);
    playerSprite->oam.shape = SPRITE_SHAPE(64x32);

    opponentSprite->oam.size = SPRITE_SIZE(64x32);
    playerSprite->oam.size = SPRITE_SIZE(64x32);

    CalcCenterToCornerVec(opponentSprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_DOUBLE);
    CalcCenterToCornerVec(playerSprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_DOUBLE);

    SetOamMatrixRotationScaling(opponentSprite->oam.matrixNum, sMugshotsOpponentRotationScales[mugshotId][0], sMugshotsOpponentRotationScales[mugshotId][1], 0);
    SetOamMatrixRotationScaling(playerSprite->oam.matrixNum, -512, 512, 0);
}

static void SpriteCB_MugshotTrainerPic(struct Sprite *sprite)
{
    while (sMugshotTrainerPicFuncs[sprite->sState](sprite));
}

static bool8 MugshotTrainerPic_Nothing(struct Sprite *sprite)
{
    return FALSE;
}

static bool8 MugshotTrainerPic_SetSlideOffsets(struct Sprite *sprite)
{
    s16 offsets1[ARRAY_COUNT(sTrainerPicSlideOffsets1)];
    s16 offsets2[ARRAY_COUNT(sTrainerPicSlideOffsets2)];

    memcpy(offsets1, sTrainerPicSlideOffsets1, sizeof(sTrainerPicSlideOffsets1));
    memcpy(offsets2, sTrainerPicSlideOffsets2, sizeof(sTrainerPicSlideOffsets2));

    sprite->sState++;
    sprite->sOffsetX = offsets1[sprite->sSlideTableId];
    sprite->sOffsetX2 = offsets2[sprite->sSlideTableId];
    return TRUE;
}

// fast slide to around middle screen
static bool8 MugshotTrainerPic_Slide1(struct Sprite *sprite)
{
    sprite->x += sprite->sOffsetX;
    if (sprite->sSlideTableId && sprite->x < 133)
        sprite->sState++;
    else if (!sprite->sSlideTableId && sprite->x > 103)
        sprite->sState++;
    return FALSE;
}

// slower but accelerating slide
static bool8 MugshotTrainerPic_Slide2(struct Sprite *sprite)
{
    sprite->sOffsetX += sprite->sOffsetX2;
    sprite->x += sprite->sOffsetX;
    if (sprite->sOffsetX == 0)
    {
        sprite->sState++;
        sprite->sOffsetX2 = -sprite->sOffsetX2;
        sprite->sDone = TRUE;
    }
    return FALSE;
}

// Has no practical effect
static bool8 MugshotTrainerPic_Slide3(struct Sprite *sprite)
{
    sprite->sOffsetX += sprite->sOffsetX2;
    sprite->x += sprite->sOffsetX;
    if (sprite->x < -31 || sprite->x > DISPLAY_WIDTH + 31)
        sprite->sState++;
    return FALSE;
}

static void SetTrainerPicSlideTable(s16 spriteId, s16 arrId)
{
    gSprites[spriteId].sSlideTableId = arrId;
}

static void IncrementTrainerPicState(s16 spriteId)
{
    gSprites[spriteId].sState++;
}

static s16 IsTrainerPicSlideDone(s16 spriteId)
{
    return gSprites[spriteId].sDone;
}

#undef sState
#undef sOffsetX
#undef sOffsetX2
#undef sDone
#undef sSlideTableId

static void Task_Slice(u8 taskId)
{
    while (sSlice_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Slice_Init(struct Task *task)
{
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    task->data[2] = 256;
    task->data[3] = 1;
    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = 0;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;
    sTransitionData->VBlank_DMA = FALSE;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionData->cameraX;
        gScanlineEffectRegBuffers[1][DISPLAY_HEIGHT + i] = DISPLAY_WIDTH;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetGpuRegBits(REG_OFFSET_DISPSTAT, DISPSTAT_HBLANK_INTR);

    SetVBlankCallback(VBlankCB_Slice);
    SetHBlankCallback(HBlankCB_Slice);

    task->tState++;
    return TRUE;
}

static bool8 Slice_Func2(struct Task *task)
{
    u16 i;

    sTransitionData->VBlank_DMA = FALSE;

    task->data[1] += (task->data[2] >> 8);
    if (task->data[1] > DISPLAY_WIDTH)
        task->data[1] = DISPLAY_WIDTH;
    if (task->data[2] <= 0xFFF)
        task->data[2] += task->data[3];
    if (task->data[3] < 128)
        task->data[3] <<= 1; // multiplying by two

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        u16 *storeLoc1 = &gScanlineEffectRegBuffers[0][i];
        u16 *storeLoc2 = &gScanlineEffectRegBuffers[0][i + DISPLAY_HEIGHT];
        if (i & 1)
        {
            *storeLoc1 = sTransitionData->cameraX + task->data[1];
            *storeLoc2 = DISPLAY_WIDTH - task->data[1];
        }
        else
        {
            *storeLoc1 = sTransitionData->cameraX - task->data[1];
            *storeLoc2 = (task->data[1] << 8) | (DISPLAY_WIDTH + 1);
        }
    }

    if (task->data[1] >= DISPLAY_WIDTH)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Slice_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
    DestroyTask(FindTaskIdByFunc(Task_Slice));
    return FALSE;
}

static void VBlankCB_Slice(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 4);
    DmaSet(0, &gScanlineEffectRegBuffers[1][DISPLAY_HEIGHT], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

static void HBlankCB_Slice(void)
{
    if (REG_VCOUNT < DISPLAY_HEIGHT)
    {
        u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
        REG_BG1HOFS = var;
        REG_BG2HOFS = var;
        REG_BG3HOFS = var;
    }
}

static void Task_ShredSplit(u8 taskId)
{
    while (sShredSplit_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 ShredSplit_Init(struct Task *task)
{
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = 0;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        gScanlineEffectRegBuffers[1][i] = sTransitionData->cameraX;
        gScanlineEffectRegBuffers[1][DISPLAY_HEIGHT + i] = DISPLAY_WIDTH;
        gScanlineEffectRegBuffers[0][i] = sTransitionData->cameraX;
        gScanlineEffectRegBuffers[0][DISPLAY_HEIGHT + i] = DISPLAY_WIDTH;
        gScanlineEffectRegBuffers[0][DISPLAY_HEIGHT * 2 + i] = 0;
        gScanlineEffectRegBuffers[0][DISPLAY_HEIGHT * 3 + i] = 256;
        gScanlineEffectRegBuffers[0][DISPLAY_HEIGHT * 4 + i] = 1;
    }

    task->data[4] = 0;
    task->data[5] = 0;
    task->data[6] = 7;

    EnableInterrupts(INTR_FLAG_HBLANK);

    SetVBlankCallback(VBlankCB_Slice);
    SetHBlankCallback(HBlankCB_Slice);

    task->tState++;
    return TRUE;
}

static bool8 ShredSplit_Func2(struct Task *task)
{
    u16 i, j, k;
    u8 arr1[ARRAY_COUNT(gUnknown_085C8C64)];
    s16 arr2[ARRAY_COUNT(gUnknown_085C8C66)];
    u8 var;
    u16 *ptr4, *ptr3, *ptr1, *ptr2;
    s16 unkVar;

    memcpy(arr1, gUnknown_085C8C64, sizeof(arr1));
    memcpy(arr2, gUnknown_085C8C66, sizeof(arr2));

    sTransitionData->VBlank_DMA = FALSE;
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
                    ptr4 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 2];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 3];
                    ptr1 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 4];
                    if (*ptr4 >= DISPLAY_WIDTH)
                    {
                        *ptr4 = DISPLAY_WIDTH;
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
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT];
                    *ptr2 = sTransitionData->cameraX + *ptr4;
                    *ptr3 = DISPLAY_WIDTH - *ptr4;

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
                if (unkVar <= DISPLAY_HEIGHT && (unkVar != DISPLAY_HEIGHT / 2 || j != 1))
                {
                    ptr4 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 2];
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 3];
                    ptr1 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT * 4];
                    if (*ptr4 >= DISPLAY_WIDTH)
                    {
                        *ptr4 = DISPLAY_WIDTH;
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
                    ptr3 = &gScanlineEffectRegBuffers[0][unkVar + DISPLAY_HEIGHT];
                    *ptr2 = sTransitionData->cameraX - *ptr4;
                    *ptr3 = (*ptr4 << 8) | (DISPLAY_WIDTH + 1);

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
    if (var >= DISPLAY_HEIGHT)
        task->tState++;

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

// This function never increments the state counter, because the loop condition
// is always false, resulting in the game being stuck in an infinite loop.
// It's possible this transition is only partially
// done and the second part was left out.
static bool8 ShredSplit_Func3(struct Task *task)
{
    u16 i;
    bool32 done = TRUE;
    u16 checkVar2 = 0xFF10;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        if (gScanlineEffectRegBuffers[1][i] != DISPLAY_WIDTH && gScanlineEffectRegBuffers[1][i] != checkVar2)
            done = FALSE; // a break statement should be put here
    }

    if (done == TRUE)
        task->tState++;

    return FALSE;
}

static bool8 ShredSplit_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
    DestroyTask(FindTaskIdByFunc(Task_ShredSplit));
    return FALSE;
}

static void Task_Blackhole1(u8 taskId)
{
    while (sBlackhole1_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_Blackhole2(u8 taskId)
{
    while (sBlackhole2_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Blackhole_Init(struct Task *task)
{
    s32 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->WININ = 0;
    sTransitionData->WINOUT = WINOUT_WIN01_ALL;
    sTransitionData->WIN0H = DISPLAY_WIDTH;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = 0;

    SetVBlankCallback(VBlankCB1_BigPokeball);

    task->tState++;
    task->data[1] = 1;
    task->data[2] = 0x100;
    task->tFuncState = 0;

    return FALSE;
}

static bool8 Blackhole1_Func3(struct Task *task)
{
    if (task->tFuncState == 1)
    {
        DmaStop(0);
        SetVBlankCallback(NULL);
        DestroyTask(FindTaskIdByFunc(task->func));
    }
    else
    {
        sTransitionData->VBlank_DMA = FALSE;
        if (task->data[2] < 1024)
            task->data[2] += 128;
        if (task->data[1] < DISPLAY_HEIGHT)
            task->data[1] += (task->data[2] >> 8);
        if (task->data[1] > DISPLAY_HEIGHT)
            task->data[1] = DISPLAY_HEIGHT;
        sub_814A014(gScanlineEffectRegBuffers[0], 120, 80, task->data[1]);
        if (task->data[1] == DISPLAY_HEIGHT)
        {
            task->tFuncState = 1;
            FadeScreenBlack();
        }
        else
        {
            sTransitionData->VBlank_DMA++;
        }
    }

    return FALSE;
}

static bool8 Blackhole1_Func2(struct Task *task)
{
    sTransitionData->VBlank_DMA = FALSE;
    if (task->tFuncState == 0)
    {
        task->tFuncState++;
        task->data[1] = 0x30;
        task->data[6] = 0;
    }
    task->data[1] += gUnknown_085C8C80[task->data[6]];
    task->data[6] = (task->data[6] + 1) % 2;
    sub_814A014(gScanlineEffectRegBuffers[0], 120, 80, task->data[1]);
    if (task->data[1] < 9)
    {
        task->tState++;
        task->tFuncState = 0;
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Blackhole2_Func2(struct Task *task)
{
    u16 index; // should be s16 I think
    s16 amplitude;

    sTransitionData->VBlank_DMA = FALSE;
    if (task->tFuncState == 0)
    {
        task->tFuncState++;
        task->data[5] = 2;
        task->data[6] = 2;
    }
    if (task->data[1] > DISPLAY_HEIGHT)
        task->data[1] = DISPLAY_HEIGHT;

    sub_814A014(gScanlineEffectRegBuffers[0], 120, 80, task->data[1]);
    if (task->data[1] == DISPLAY_HEIGHT)
    {
        DmaStop(0);
        FadeScreenBlack();
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

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static void Task_RectangularSpiral(u8 taskId)
{
    while (sRectangularSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 RectangularSpiral_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuCopy16(sShrinkingBoxTileset, tileset, 0x20);
    CpuCopy16(sShrinkingBoxTileset + 0x70, tileset + 0x20, 0x20);
    CpuFill16(0xF000, tilemap, BG_SCREEN_SIZE);
    LoadPalette(sFieldEffectPal_Pokeball, 0xF0, sizeof(sFieldEffectPal_Pokeball));

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

static bool8 RectangularSpiral_Func2(struct Task *task)
{
    u16 *tilemap, *tileset;
    u8 i;
    u16 j;
    bool32 done = TRUE;

    GetBg0TilesDst(&tilemap, &tileset);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < ARRAY_COUNT(sRectangularSpiralTransition); j++)
        {
            s16 var = 0, var2 = 0;
            s32 var3 = 0;

            if (sub_8149048(gUnknown_085C8D38[j / 2], &sRectangularSpiralTransition[j]))
            {
                done = FALSE;
                var = sRectangularSpiralTransition[j].field_2;
                if ((j % 2) == 1)
                    var = 0x27D - var;

                var2 = var % 32;
                var3 = var / 32;

                SET_TILEMAP_TILE(tilemap, var3, var2, 0xF002);
            }
        }
    }

    if (done == TRUE)
        task->tState++;
    return FALSE;
}

static bool8 RectangularSpiral_End(struct Task *task)
{
    DmaStop(0);
    FadeScreenBlack();
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

static void Task_Groudon(u8 taskId)
{
    while (sGroudon_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Groudon_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sGroudon_Tileset, tileset);
    LZ77UnCompVram(sGroudon_Tilemap, tilemap);

    task->tState++;
    task->data[1] = 0;
    return FALSE;
}

static bool8 Groudon_PalettePulsate(struct Task *task)
{
    if (task->data[1] % 3 == 0)
    {
        u16 var = (task->data[1] % 30) / 3;
        LoadPalette(sGroudon1_Palette + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 58)
    {
        task->tState++;
        task->data[1] = 0;
    }

    return FALSE;
}

static bool8 Groudon_PaletteBrighten(struct Task *task)
{
    if (task->data[1] % 5 == 0)
    {
        s16 var = task->data[1] / 5;
        LoadPalette(sGroudon2_Palette + (var * 16), 0xF0, 0x20);
    }
    if (++task->data[1] > 68)
    {
        task->tState++;
        task->data[1] = 0;
        task->tEndDelay = 30;
    }

    return FALSE;
}

#undef tEndDelay

static void Task_Rayquaza(u8 taskId)
{
    while (sRayquaza_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Rayquaza_Func3(struct Task *task)
{
    u16 *tilemap, *tileset;
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(26) | BGCNT_TXT256x512);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    CpuCopy16(sRayquaza_Tileset, tileset, 0x2000);

    sTransitionData->field_20 = 0;
    task->tState++;
    LoadPalette(sRayquaza_Palette + 0x50, 0xF0, 0x20);

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        gScanlineEffectRegBuffers[0][i] = 0;
        gScanlineEffectRegBuffers[1][i] = 0x100;
    }

    SetVBlankCallback(VBlankCB_Rayquaza);
    return FALSE;
}

static bool8 Rayquaza_Func4(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuCopy16(sRayquaza_Tilemap, tilemap, sizeof(sRayquaza_Tilemap));
    task->tState++;
    return FALSE;
}

static bool8 Rayquaza_Func5(struct Task *task)
{
    if ((task->data[1] % 4) == 0)
    {
        u16 value = task->data[1] / 4;
        const u16 *palPtr = &sRayquaza_Palette[(value + 5) * 16];
        LoadPalette(palPtr, 0xF0, 0x20);
    }
    if (++task->data[1] > 40)
    {
        task->tState++;
        task->data[1] = 0;
    }

    return FALSE;
}

static bool8 Rayquaza_Func6(struct Task *task)
{
    if (++task->data[1] > 20)
    {
        task->tState++;
        task->data[1] = 0;
        BeginNormalPaletteFade(PALETTES_OBJECTS | (1 << 15), 2, 0, 16, RGB_BLACK);
    }

    return FALSE;
}

static bool8 Rayquaza_Func7(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sTransitionData->field_20 = 1;
        task->tState++;
    }

    return FALSE;
}

static bool8 Rayquaza_Func8(struct Task *task)
{
    BlendPalettes(PALETTES_BG & ~(1 << 15), 8, RGB_BLACK);
    BlendPalettes(PALETTES_OBJECTS | (1 << 15), 0, RGB_BLACK);

    task->tState++;
    return FALSE;
}

static bool8 Rayquaza_Func9(struct Task *task)
{
    if ((task->data[1] % 3) == 0)
    {
        u16 value = task->data[1] / 3;
        const u16 *palPtr = &sRayquaza_Palette[(value + 0) * 16];
        LoadPalette(palPtr, 0xF0, 0x20);
    }
    if (++task->data[1] >= 40)
    {
        u16 i;

        sTransitionData->WININ = 0;
        sTransitionData->WINOUT = WINOUT_WIN01_ALL;
        sTransitionData->WIN0H = DISPLAY_WIDTH;
        sTransitionData->WIN0V = DISPLAY_HEIGHT;

        for (i = 0; i < DISPLAY_HEIGHT; i++)
            gScanlineEffectRegBuffers[1][i] = 0;

        SetVBlankCallback(VBlankCB1_BigPokeball);
        task->tState++;
        task->data[2] = 0x100;
        task->tFuncState = 0;
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);
    }

    return FALSE;
}

static void VBlankCB_Rayquaza(void)
{
    void *dmaSrc;

    DmaStop(0);
    VBlankCB_BattleTransition();

    if (sTransitionData->field_20 == 0)
        dmaSrc = gScanlineEffectRegBuffers[0];
    else if (sTransitionData->field_20 == 1)
        dmaSrc = gScanlineEffectRegBuffers[1];
    else
        dmaSrc = gScanlineEffectRegBuffers[0];

    DmaSet(0, dmaSrc, &REG_BG0VOFS, B_TRANS_DMA_FLAGS);
}

static void Task_WhiteFade(u8 taskId)
{
    while (sWhiteFade_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 WhiteFade_Init(struct Task *task)
{
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->BLDCNT = BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN;
    sTransitionData->BLDY = 0;
    sTransitionData->WININ = WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ;
    sTransitionData->WINOUT = WINOUT_WIN01_ALL;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 0;
        gScanlineEffectRegBuffers[1][i + DISPLAY_HEIGHT] = DISPLAY_WIDTH;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetHBlankCallback(HBlankCB_WhiteFade);
    SetVBlankCallback(VBlankCB0_WhiteFade);

    task->tState++;
    return FALSE;
}

static bool8 WhiteFade_Func2(struct Task *task)
{
    s16 i, posY;
    s16 arr1[ARRAY_COUNT(sUnknown_085C8DA0)];
    struct Sprite *sprite;

    memcpy(arr1, sUnknown_085C8DA0, sizeof(sUnknown_085C8DA0));
    for (i = 0, posY = 0; i < 8; i++, posY += 20)
    {
        sprite = &gSprites[CreateInvisibleSprite(sub_8149864)];
        sprite->x = DISPLAY_WIDTH;
        sprite->y = posY;
        sprite->data[5] = arr1[i];
    }
    sprite->data[6]++;

    task->tState++;
    return FALSE;
}

static bool8 WhiteFade_Func3(struct Task *task)
{
    sTransitionData->VBlank_DMA = 0;
    if (sTransitionData->field_20 > 7)
    {
        BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
        task->tState++;
    }
    return FALSE;
}

static bool8 WhiteFade_Func4(struct Task *task)
{
    sTransitionData->VBlank_DMA = 0;

    DmaStop(0);
    SetVBlankCallback(0);
    SetHBlankCallback(0);

    sTransitionData->WIN0H = DISPLAY_WIDTH;
    sTransitionData->BLDY = 0;
    sTransitionData->BLDCNT = 0xFF;
    sTransitionData->WININ = WININ_WIN0_ALL;

    SetVBlankCallback(VBlankCB1_WhiteFade);

    task->tState++;
    return FALSE;
}

static bool8 WhiteFade_End(struct Task *task)
{
   if (++sTransitionData->BLDY > 16)
   {
       FadeScreenBlack();
       DestroyTask(FindTaskIdByFunc(Task_WhiteFade));
   }
   return FALSE;
}

static void VBlankCB0_WhiteFade(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    REG_BLDCNT = sTransitionData->BLDCNT;
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 4);
    DmaSet(0, &gScanlineEffectRegBuffers[1][DISPLAY_HEIGHT], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

static void VBlankCB1_WhiteFade(void)
{
    VBlankCB_BattleTransition();
    REG_BLDY = sTransitionData->BLDY;
    REG_BLDCNT = sTransitionData->BLDCNT;
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0H = sTransitionData->WIN0H;
    REG_WIN0V = sTransitionData->WIN0V;
}

static void HBlankCB_WhiteFade(void)
{
    REG_BLDY = gScanlineEffectRegBuffers[1][REG_VCOUNT];
}

static void sub_8149864(struct Sprite *sprite)
{
    if (sprite->data[5])
    {
        sprite->data[5]--;
        if (sprite->data[6])
            sTransitionData->VBlank_DMA = 1;
    }
    else
    {
        u16 i;
        u16* ptr1 = &gScanlineEffectRegBuffers[0][sprite->y];
        u16* ptr2 = &gScanlineEffectRegBuffers[0][sprite->y + DISPLAY_HEIGHT];
        for (i = 0; i < 20; i++)
        {
            ptr1[i] = sprite->data[0] >> 8;
            ptr2[i] = (u8)(sprite->x);
        }
        if (sprite->x == 0 && sprite->data[0] == 0x1000)
            sprite->data[1] = 1;

        sprite->x -= 16;
        sprite->data[0] += 0x80;

        if (sprite->x < 0)
            sprite->x = 0;
        if (sprite->data[0] > 0x1000)
            sprite->data[0] = 0x1000;

        if (sprite->data[6])
            sTransitionData->VBlank_DMA = 1;

        if (sprite->data[1])
        {
            if (sprite->data[6] == 0 || (sTransitionData->field_20 > 6 && sprite->data[2]++ > 7))
            {
                sTransitionData->field_20++;
                DestroySprite(sprite);
            }
        }
    }
}

static void Task_GridSquares(u8 taskId)
{
    while (sGridSquares_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 GridSquares_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    CpuSet(sShrinkingBoxTileset, tileset, 16);
    CpuFill16(0xF000, tilemap, BG_SCREEN_SIZE);
    LoadPalette(sFieldEffectPal_Pokeball, 0xF0, sizeof(sFieldEffectPal_Pokeball));

    task->tState++;
    return FALSE;
}

static bool8 GridSquares_Func2(struct Task *task)
{
    u16* tileset;

    if (task->data[1] == 0)
    {
        GetBg0TilemapDst(&tileset);
        task->data[1] = 3;
        task->data[2]++;
        CpuSet(sShrinkingBoxTileset + (task->data[2] * 8), tileset, 16);
        if (task->data[2] > 13)
        {
            task->tState++;
            task->data[1] = 16;
        }
    }

    task->data[1]--;
    return FALSE;
}

static bool8 GridSquares_End(struct Task *task)
{
    if (--task->data[1] == 0)
    {
        FadeScreenBlack();
        DestroyTask(FindTaskIdByFunc(Task_GridSquares));
    }
    return FALSE;
}

static void Task_Shards(u8 taskId)
{
    while (sShards_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Shards_Init(struct Task *task)
{
    u16 i;

    InitTransitionData();
    ScanlineEffect_Clear();

    sTransitionData->WININ = WININ_WIN0_ALL;
    sTransitionData->WINOUT = 0;
    sTransitionData->WIN0V = DISPLAY_HEIGHT;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = DISPLAY_WIDTH;

    CpuSet(gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT);
    SetVBlankCallback(VBlankCB_Shards);

    task->tState++;
    return TRUE;
}

static bool8 Shards_Func2(struct Task *task)
{
    sub_814A1AC(sTransitionData->data,
                sUnknown_085C8DD0[task->data[1]][0],
                sUnknown_085C8DD0[task->data[1]][1],
                sUnknown_085C8DD0[task->data[1]][2],
                sUnknown_085C8DD0[task->data[1]][3],
                1, 1);
    task->data[2] = sUnknown_085C8DD0[task->data[1]][4];
    task->tState++;
    return TRUE;
}

static bool8 Shards_Func3(struct Task *task)
{
    s16 i;
    bool8 nextFunc;

    sTransitionData->VBlank_DMA = 0;

    for (i = 0, nextFunc = FALSE; i < 16; i++)
    {
        s16 r3 = gScanlineEffectRegBuffers[0][sTransitionData->data[3]] >> 8;
        s16 r4 = gScanlineEffectRegBuffers[0][sTransitionData->data[3]] & 0xFF;
        if (task->data[2] == 0)
        {
            if (r3 < sTransitionData->data[2])
                r3 = sTransitionData->data[2];
            if (r3 > r4)
                r3 = r4;
        }
        else
        {
            if (r4 > sTransitionData->data[2])
                r4 = sTransitionData->data[2];
            if (r4 <= r3)
                r4 = r3;
        }
        gScanlineEffectRegBuffers[0][sTransitionData->data[3]] = (r4) | (r3 << 8);
        if (nextFunc)
        {
            task->tState++;
            break;
        }
        else
            nextFunc = sub_814A228(sTransitionData->data, 1, 1);
    }

    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static bool8 Shards_Func4(struct Task *task)
{
    if (++task->data[1] < 7)
    {
        task->tState++;
        task->data[3] = sUnknown_085C8E16[task->data[1] - 1];
        return TRUE;
    }
    else
    {
        DmaStop(0);
        FadeScreenBlack();
        DestroyTask(FindTaskIdByFunc(Task_Shards));
        return FALSE;
    }
}

static bool8 Shards_Func5(struct Task *task)
{
    if (--task->data[3] == 0)
    {
        task->tState = 1;
        return TRUE;
    }

    return FALSE;
}

static void VBlankCB_Shards(void)
{
    DmaStop(0);
    VBlankCB_BattleTransition();
    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    REG_WININ = sTransitionData->WININ;
    REG_WINOUT = sTransitionData->WINOUT;
    REG_WIN0V = sTransitionData->WIN0V;
    REG_WIN0H = gScanlineEffectRegBuffers[1][0];
    DmaSet(0, gScanlineEffectRegBuffers[1], &REG_WIN0H, B_TRANS_DMA_FLAGS);
}

#undef tFuncState
#undef tOpponentSpriteId
#undef tPlayerSpriteId
#undef tMugshotId

static void CreateIntroTask(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4)
{
    u8 taskId = CreateTask(Task_BattleTransition_Intro, 3);
    gTasks[taskId].data[1] = a0;
    gTasks[taskId].data[2] = a1;
    gTasks[taskId].data[3] = a2;
    gTasks[taskId].data[4] = a3;
    gTasks[taskId].data[5] = a4;
    gTasks[taskId].data[6] = a0;
}

static bool8 IsIntroTaskDone(void)
{
    if (FindTaskIdByFunc(Task_BattleTransition_Intro) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

void Task_BattleTransition_Intro(u8 taskId)
{
    while (sTransitionIntroFuncs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 Transition_Intro_1(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[1];
        task->data[7] += task->data[4];
        if (task->data[7] > 16)
            task->data[7] = 16;
        BlendPalettes(PALETTES_ALL, task->data[7], RGB(11, 11, 11));
    }
    if (task->data[7] > 15)
    {
        task->tState++;
        task->data[6] = task->data[2];
    }
    return FALSE;
}

static bool8 Transition_Intro_2(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[2];
        task->data[7] -= task->data[5];
        if (task->data[7] < 0)
            task->data[7] = 0;
        BlendPalettes(PALETTES_ALL, task->data[7], RGB(11, 11, 11));
    }
    if (task->data[7] == 0)
    {
        if (--task->data[3] == 0)
            DestroyTask(FindTaskIdByFunc(Task_BattleTransition_Intro));
        else
        {
            task->data[6] = task->data[1];
            task->tState = 0;
        }
    }
    return FALSE;
}

static void InitTransitionData(void)
{
    memset(sTransitionData, 0, sizeof(*sTransitionData));
    GetCameraOffsetWithPan(&sTransitionData->cameraX, &sTransitionData->cameraY);
}

static void VBlankCB_BattleTransition(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void GetBg0TilemapDst(u16 **tileset)
{
    u16 charBase = REG_BG0CNT >> 2;
    charBase <<= 14;
    *tileset = (u16*)(VRAM + charBase);
}

void GetBg0TilesDst(u16 **tilemap, u16 **tileset)
{
    u16 screenBase = REG_BG0CNT >> 8;
    u16 charBase = REG_BG0CNT >> 2;

    screenBase <<= 11;
    charBase <<= 14;

    *tilemap = (u16*)(VRAM + screenBase);
    *tileset = (u16*)(VRAM + charBase);
}

static void FadeScreenBlack(void)
{
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
}

static void SetSinWave(s16 *array, s16 sinAdd, s16 index, s16 indexIncrementer, s16 amplitude, s16 arrSize)
{
    u8 i;
    for (i = 0; arrSize > 0; arrSize--, i++, index += indexIncrementer)
        array[i] = sinAdd + Sin(index & 0xFF, amplitude);
}

static void sub_814A014(u16 *array, s16 x, s16 y, s16 amplitude)
{
    s16 i;

    memset(array, 10, DISPLAY_HEIGHT * sizeof(s16));
    for (i = 0; i < 64; i++)
    {
        s16 sinResult, cosResult;
        s16 toStoreOrr, r2, r3, toStore, r7, r8;

        sinResult = Sin(i, amplitude);
        cosResult = Cos(i, amplitude);

        toStoreOrr = x - sinResult;
        toStore = x + sinResult;
        r7 = y - cosResult;
        r8 = y + cosResult;

        if (toStoreOrr < 0)
            toStoreOrr = 0;
        if (toStore > DISPLAY_WIDTH)
            toStore = DISPLAY_WIDTH;
        if (r7 < 0)
            r7 = 0;
        if (r8 > DISPLAY_HEIGHT - 1)
            r8 = DISPLAY_HEIGHT - 1;

        toStore |= (toStoreOrr << 8);
        array[r7] = toStore;
        array[r8] = toStore;

        cosResult = Cos(i + 1, amplitude);
        r3 = y - cosResult;
        r2 = y + cosResult;

        if (r3 < 0)
            r3 = 0;
        if (r2 > DISPLAY_HEIGHT - 1)
            r2 = DISPLAY_HEIGHT - 1;

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

static bool8 FrontierLogoWiggle_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    InitPatternWeaveTransition(task);
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sFrontierLogo_Tileset, tileset);
    LoadPalette(sFrontierLogo_Palette, 0xF0, sizeof(sFrontierLogo_Palette));

    task->tState++;
    return FALSE;
}

static bool8 FrontierLogoWiggle_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sFrontierLogo_Tilemap, tilemap);
    SetSinWave(gScanlineEffectRegBuffers[0], 0, task->data[4], 0x84, task->data[5], DISPLAY_HEIGHT);

    task->tState++;
    return TRUE;
}

static void Task_FrontierLogoWiggle(u8 taskId)
{
    while (sFrontierLogoWiggle_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_FrontierLogoWave(u8 taskId)
{
    while (sFrontierLogoWave_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 FrontierLogoWave_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    InitTransitionData();
    ScanlineEffect_Clear();
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    task->data[2] = 0x2000;
    task->data[1] = 0x7FFF;
    task->data[5] = 0;
    task->data[6] = 16;
    task->data[7] = 2560;
    sTransitionData->BLDCNT = BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL;
    sTransitionData->BLDALPHA = BLDALPHA_BLEND(task->data[5], task->data[6]);
    REG_BLDCNT = sTransitionData->BLDCNT;
    REG_BLDALPHA = sTransitionData->BLDALPHA;
    GetBg0TilesDst(&tilemap, &tileset);
    CpuFill16(0, tilemap, BG_SCREEN_SIZE);
    LZ77UnCompVram(sFrontierLogo_Tileset, tileset);
    LoadPalette(sFrontierLogo_Palette, 0xF0, sizeof(sFrontierLogo_Palette));
    sTransitionData->cameraY = 0;

    task->tState++;
    return FALSE;
}

static bool8 FrontierLogoWave_SetGfx(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sFrontierLogo_Tilemap, tilemap);

    task->tState++;
    return TRUE;
}

static bool8 FrontierLogoWave_Func3(struct Task *task)
{
    u8 i;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = sTransitionData->cameraY;

    SetVBlankCallback(VBlankCB_FrontierLogoWave);
    SetHBlankCallback(HBlankCB_FrontierLogoWave);
    EnableInterrupts(INTR_FLAG_HBLANK);

    task->tState++;
    return TRUE;
}

static bool8 FrontierLogoWave_Func4(struct Task *task)
{
    u8 i;
    u16 var6, amplitude, var8;

    sTransitionData->VBlank_DMA = FALSE;

    amplitude = task->data[2] >> 8;
    var6 = task->data[1];
    var8 = 384;

    task->data[1] = var6 - task->data[7];

    if (task->data[3] >= 70)
    {
        if (task->data[2] - 384 >= 0)
            task->data[2] -= 384;
        else
            task->data[2] = 0;
    }

    if (task->data[3] >= 0 && task->data[3] % 3 == 0)
    {
        if (task->data[5] < 16)
            task->data[5]++;
        else if (task->data[6] > 0)
            task->data[6]--;

        sTransitionData->BLDALPHA = BLDALPHA_BLEND(task->data[5], task->data[6]);
    }

    for (i = 0; i < DISPLAY_HEIGHT; i++, var6 += var8)
    {
        s16 index = var6 / 256;
        gScanlineEffectRegBuffers[0][i] = sTransitionData->cameraY + Sin(index & 0xff, amplitude);
    }

    if (++task->data[3] == 101)
    {
        task->data[4]++;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    }

    if (task->data[4] != 0 && !gPaletteFade.active)
        DestroyTask(FindTaskIdByFunc(Task_FrontierLogoWave));

    task->data[7] -= 17;
    sTransitionData->VBlank_DMA++;
    return FALSE;
}

static void VBlankCB_FrontierLogoWave(void)
{
    VBlankCB_BattleTransition();
    REG_BLDCNT = sTransitionData->BLDCNT;
    REG_BLDALPHA = sTransitionData->BLDALPHA;

    if (sTransitionData->VBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
}

static void HBlankCB_FrontierLogoWave(void)
{
    u16 var = gScanlineEffectRegBuffers[1][REG_VCOUNT];
    REG_BG0VOFS = var;
}

static void Task_FrontierSquares(u8 taskId)
{
    while (sFrontierSquares_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_FrontierSquaresSpiral(u8 taskId)
{
    while (sFrontierSquaresSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static void Task_FrontierSquaresScroll(u8 taskId)
{
    while (sFrontierSquaresScroll_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 FrontierSquares_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sFrontierSquares_FilledBg_Tileset, tileset);

    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect(0, 1, 0, 0, 1, 0x20, 0xF);
    FillBgTilemapBufferRect(0, 1, 0x1D, 0, 1, 0x20, 0xF);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(sFrontierSquares_Palette, 0xF0, sizeof(sFrontierSquares_Palette));

    task->data[2] = 1;
    task->data[3] = 0;
    task->data[4] = 0;
    task->data[7] = 10;

    task->tState++;
    return FALSE;
}

static bool8 FrontierSquares_Func2(struct Task *task)
{
    CopyRectToBgTilemapBufferRect(0, sFrontierSquares_Tilemap, 0, 0, 4, 4, task->data[2], task->data[3], 4, 4, 0xF, 0, 0);
    CopyBgTilemapBufferToVram(0);

    task->data[2] += 4;
    if (++task->data[4] == 7)
    {
        task->data[2] = 1;
        task->data[3] += 4;
        task->data[4] = 0;
        if (task->data[3] > 19)
            task->tState++;
    }

    return FALSE;
}

static bool8 FrontierSquares_Func3(struct Task *task)
{
    u8 i;
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    if (task->data[6]++ >= task->data[7])
    {
        switch (task->data[5])
        {
        case 0:
            for (i = 250; i < 255; i++)
            {
                gPlttBufferUnfaded[i] = 0;
                gPlttBufferFaded[i] = 0;
            }
            break;
        case 1:
            BlendPalettes(PALETTES_ALL & ~(1 << 15), 16, RGB_BLACK);
            LZ77UnCompVram(sFrontierSquares_EmptyBg_Tileset, tileset);
            break;
        case 2:
            LZ77UnCompVram(sFrontierSquares_Shrink1_Tileset, tileset);
            break;
        case 3:
            LZ77UnCompVram(sFrontierSquares_Shrink2_Tileset, tileset);
            break;
        default:
            FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
            CopyBgTilemapBufferToVram(0);
            task->tState++;
            return FALSE;
        }

        task->data[6] = 0;
        task->data[5]++;
    }

    return FALSE;
}

static bool8 FrontierSquaresSpiral_Init(struct Task *task)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sFrontierSquares_FilledBg_Tileset, tileset);

    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect(0, 1, 0, 0, 1, 0x20, 0xF);
    FillBgTilemapBufferRect(0, 1, 0x1D, 0, 1, 0x20, 0xF);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(sFrontierSquares_Palette, 0xE0, sizeof(sFrontierSquares_Palette));
    LoadPalette(sFrontierSquares_Palette, 0xF0, sizeof(sFrontierSquares_Palette));
    BlendPalette(0xE0, 16, 8, 0);

    task->data[2] = 34;
    task->data[3] = 0;

    task->tState++;
    return FALSE;
}

static bool8 FrontierSquaresSpiral_Func2(struct Task *task)
{
    u8 var = gUnknown_085C9A30[task->data[2]];
    u8 varMod = var % 7;
    u8 varDiv = var / 7;
    CopyRectToBgTilemapBufferRect(0, &sFrontierSquares_Tilemap, 0, 0, 4, 4, 4 * varMod + 1, 4 * varDiv, 4, 4, 0xF, 0, 0);
    CopyBgTilemapBufferToVram(0);

    if (--task->data[2] < 0)
        task->tState++;
    return FALSE;
}

static bool8 FrontierSquaresSpiral_Func3(struct Task *task)
{
    BlendPalette(0xE0, 16, 3, 0);
    BlendPalettes(PALETTES_ALL & ~(1 << 15 | 1 << 14), 16, RGB_BLACK);

    task->data[2] = 0;
    task->data[3] = 0;

    task->tState++;
    return FALSE;
}

static bool8 FrontierSquaresSpiral_Func4(struct Task *task)
{
    if ((task->data[3] ^= 1))
    {
        CopyRectToBgTilemapBufferRect(
        0,
        sFrontierSquares_Tilemap,
        0,
        0,
        4,
        4,
        4 * (gUnknown_085C9A30[task->data[2]] % 7) + 1,
        4 * (gUnknown_085C9A30[task->data[2]] / 7),
        4,
        4,
        0xE,
        0,
        0);
    }
    else
    {
        if (task->data[2] > 0)
        {
            FillBgTilemapBufferRect(
            0,
            1,
            4 * (gUnknown_085C9A30[task->data[2] - 1] % 7) + 1,
            4 * (gUnknown_085C9A30[task->data[2] - 1] / 7),
            4,
            4,
            0xF);
        }

        task->data[2]++;
    }

    if (task->data[2] > 34)
        task->tState++;

    CopyBgTilemapBufferToVram(0);
    return FALSE;
}

static bool8 FrontierSquares_End(struct Task *task)
{
    FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
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

static bool8 FrontierSquaresScroll_Init(struct Task *task)
{
    u8 taskId = 0;
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sFrontierSquares_FilledBg_Tileset, tileset);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(sFrontierSquares_Palette, 0xF0, sizeof(sFrontierSquares_Palette));

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_Y);

    task->data[2] = 0;
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

static bool8 FrontierSquaresScroll_Func2(struct Task *task)
{
    u8 var = gUnknown_085C9A53[task->data[2]];
    u8 varDiv = var / 8;
    u8 varAnd = var & 7;

    CopyRectToBgTilemapBufferRect(
    0,
    &sFrontierSquares_Tilemap,
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

    if (++task->data[2] > 63)
        task->tState++;
    return 0;
}

static bool8 FrontierSquaresScroll_Func3(struct Task *task)
{
    BlendPalettes(PALETTES_ALL & ~(1 << 15), 16, RGB_BLACK);

    task->data[2] = 0;

    task->tState++;
    return FALSE;
}

static bool8 FrontierSquaresScroll_Func4(struct Task *task)
{
    u8 var = gUnknown_085C9A53[task->data[2]];
    u8 varDiv = var / 8;
    u8 varAnd = var % 8;

    FillBgTilemapBufferRect(0, 1, 4 * varDiv + 1, 4 * varAnd, 4, 4, 0xF);
    CopyBgTilemapBufferToVram(0);

    if (++task->data[2] > 63)
    {
        DestroyTask(FindTaskIdByFunc(sub_814ABE4));
        task->tState++;
    }

    return FALSE;
}

#undef tSub32_X_delta
#undef tSub32_Y_delta
#undef tSub32_Bool

static bool8 FrontierSquaresScroll_End(struct Task *task)
{
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_Y);

    FillBgTilemapBufferRect_Palette0(0, 1, 0, 0, 0x20, 0x20);
    CopyBgTilemapBufferToVram(0);
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);

    DestroyTask(FindTaskIdByFunc(task->func));

#ifndef UBFIX
    task->tState++; // UB: changing value of a destroyed task
#endif
    return FALSE;
}

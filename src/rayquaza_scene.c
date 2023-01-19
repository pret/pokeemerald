#include "global.h"
#include "rayquaza_scene.h"
#include "sprite.h"
#include "task.h"
#include "graphics.h"
#include "bg.h"
#include "main.h"
#include "malloc.h"
#include "palette.h"
#include "scanline_effect.h"
#include "menu.h"
#include "menu_helpers.h"
#include "gpu_regs.h"
#include "decompress.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "random.h"

/*
    This file handles the cutscene showing Rayquaza arriving to settle the Groudon/Kyogre fight
    It consists of 5 separate scenes:
    - Groudon and Kyogre facing one another in a thunderstorm             (RAY_ANIM_DUO_FIGHT)
    - Over-the-shoulder of Rayquaza flying                                (RAY_ANIM_TAKES_FLIGHT)
    - Rayquaza emerging from a spotlight down through the clouds          (RAY_ANIM_DESCENDS)
    - A close-up of Rayquaza flying down                                  (RAY_ANIM_CHARGES)
    - Rayquaza floating above Groudon/Kyogre as they back away offscreen  (RAY_ANIM_CHASES_AWAY)

    A shortened version of the first scene is used when the player first arrives
    in Sootopolis during the Groudon/Kyogre conflict, before awakening Rayquaza (RAY_ANIM_DUO_FIGHT_PRE)
    This is indicated with the first two arguments to DoRayquazaScene
*/

enum
{
    RAY_ANIM_DUO_FIGHT_PRE,
    RAY_ANIM_DUO_FIGHT,
    RAY_ANIM_TAKES_FLIGHT,
    RAY_ANIM_DESCENDS,
    RAY_ANIM_CHARGES,
    RAY_ANIM_CHASES_AWAY,
    RAY_ANIM_END
};

#define TAG_DUOFIGHT_GROUDON             30505
#define TAG_DUOFIGHT_GROUDON_SHOULDER    30506
#define TAG_DUOFIGHT_GROUDON_CLAW        30507
#define TAG_DUOFIGHT_KYOGRE              30508
#define TAG_DUOFIGHT_KYOGRE_PECTORAL_FIN 30509
#define TAG_DUOFIGHT_KYOGRE_DORSAL_FIN   30510
#define TAG_FLIGHT_SMOKE                 30555
#define TAG_DESCENDS_RAYQUAZA            30556
#define TAG_DESCENDS_RAYQUAZA_TAIL       30557
#define TAG_CHASE_GROUDON                30565
#define TAG_CHASE_GROUDON_TAIL           30566
#define TAG_CHASE_KYOGRE                 30568
#define TAG_CHASE_RAYQUAZA               30569
#define TAG_CHASE_RAYQUAZA_TAIL          30570
#define TAG_CHASE_SPLASH                 30571

#define MAX_SMOKE 10

struct RayquazaScene
{
    MainCallback exitCallback;
    u8 tilemapBuffers[4][BG_SCREEN_SIZE];
    u16 unk; // never read
    u8 animId;
    bool8 endEarly;
    s16 revealedLightLine;
    s16 revealedLightTimer;
    u8 unused[12];
};

static EWRAM_DATA struct RayquazaScene *sRayScene = NULL;

static void CB2_InitRayquazaScene(void);
static void CB2_RayquazaScene(void);
static void Task_EndAfterFadeScreen(u8);

// RAY_ANIM_DUO_FIGHT_PRE / RAY_ANIM_DUO_FIGHT
static void Task_DuoFightAnim(u8);
static void Task_HandleDuoFight(u8);
static void Task_DuoFightEnd(u8);
static void DuoFightEnd(u8, s8);
static void Task_DuoFight_AnimateClouds(u8);
static void DuoFight_PanOffScene(u8);
static void DuoFight_AnimateRain(void);
static void DuoFight_Lightning1(void);
static void DuoFight_Lightning2(void);
static void DuoFight_LightningLong(void);
static u8 DuoFightPre_CreateGroudonSprites(void);
static u8 DuoFightPre_CreateKyogreSprites(void);
static u8 DuoFight_CreateGroudonSprites(void);
static u8 DuoFight_CreateKyogreSprites(void);
static void SpriteCB_DuoFightPre_Groudon(struct Sprite *);
static void SpriteCB_DuoFightPre_Kyogre(struct Sprite *);
static void SpriteCB_DuoFight_Groudon(struct Sprite *);
static void SpriteCB_DuoFight_Kyogre(struct Sprite *);
static void DuoFight_SlideGroudonDown(struct Sprite *);
static void DuoFight_SlideKyogreDown(struct Sprite *);

// RAY_ANIM_TAKES_FLIGHT
static void Task_RayTakesFlightAnim(u8);
static void Task_HandleRayTakesFlight(u8);
static void Task_RayTakesFlightEnd(u8);
static void Task_TakesFlight_CreateSmoke(u8);
static void SpriteCB_TakesFlight_Smoke(struct Sprite *);

// RAY_ANIM_DESCENDS
static void Task_RayDescendsAnim(u8);
static void Task_HandleRayDescends(u8);
static void Task_RayDescendsEnd(u8);
static u8 CreateDescendsRayquazaSprite(void);
static void SpriteCB_Descends_Rayquaza(struct Sprite *);

// RAY_ANIM_CHARGES
static void Task_RayChargesAnim(u8);
static void Task_HandleRayCharges(u8);
static void Task_RayChargesEnd(u8);
static void Task_RayCharges_ShakeRayquaza(u8);
static void Task_RayCharges_FlyOffscreen(u8);
static void RayCharges_AnimateBg(void);

// RAY_ANIM_CHASES_AWAY
static void Task_RayChasesAwayAnim(u8);
static void Task_HandleRayChasesAway(u8);
static void Task_RayChasesAwayEnd(u8);
static void Task_ChasesAway_AnimateBg(u8);
static void ChasesAway_KyogreStartLeave(u8);
static void ChasesAway_GroudonStartLeave(u8);
static void ChasesAway_CreateTrioSprites(u8);
static void Task_ChasesAway_AnimateRing(u8);
static void SpriteCB_ChasesAway_GroudonLeave(struct Sprite *);
static void SpriteCB_ChasesAway_KyogreLeave(struct Sprite *);
static void SpriteCB_ChasesAway_RayquazaFloat(struct Sprite *);
static void SpriteCB_ChasesAway_Rayquaza(struct Sprite *);
static void SpriteCB_ChasesAway_DuoRingPush(struct Sprite *);
static void ChasesAway_SetRayquazaAnim(struct Sprite *, u8, s16, s16);

static const TaskFunc sTasksForAnimations[] =
{
    [RAY_ANIM_DUO_FIGHT_PRE] = Task_DuoFightAnim,
    [RAY_ANIM_DUO_FIGHT]     = Task_DuoFightAnim,
    [RAY_ANIM_TAKES_FLIGHT]  = Task_RayTakesFlightAnim,
    [RAY_ANIM_DESCENDS]      = Task_RayDescendsAnim,
    [RAY_ANIM_CHARGES]       = Task_RayChargesAnim,
    [RAY_ANIM_CHASES_AWAY]   = Task_RayChasesAwayAnim,
    [RAY_ANIM_END]           = Task_EndAfterFadeScreen,
};

static const struct OamData sOam_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_DuoFightPre_Groudon_Head[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_Groudon_Body[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_Groudon[] =
{
    sAnim_DuoFightPre_Groudon_Head,
    sAnim_DuoFightPre_Groudon_Body
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_Groudon =
{
    .tileTag = TAG_DUOFIGHT_GROUDON,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_64x64,
    .anims = sAnims_DuoFightPre_Groudon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_GroudonShoulderKyogreDorsalFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFightPre_GroudonShoulderKyogreDorsalFin[] =
{
    sAnim_DuoFightPre_GroudonShoulderKyogreDorsalFin
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_GroudonShoulder =
{
    .tileTag = TAG_DUOFIGHT_GROUDON_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_GroudonShoulderKyogreDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_GroudonClaw[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFightPre_GroudonClaw[] =
{
    sAnim_DuoFightPre_GroudonClaw
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_GroudonClaw =
{
    .tileTag = TAG_DUOFIGHT_GROUDON_CLAW,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_64x32,
    .anims = sAnims_DuoFightPre_GroudonClaw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_TopLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_TopRight[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_FaceLeft[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_FaceRight[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_ChinLeft[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_ChinRight[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_LeftPectoralFin[] =
{
    ANIMCMD_FRAME(48, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_FRAME(80, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_LeftShoulder[] =
{
    ANIMCMD_FRAME(56, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_FRAME(88, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_Kyogre_RightShoulder[] =
{
    ANIMCMD_FRAME(96, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_FRAME(112, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_JUMP(0),
};

// Edge of the right pectoral fin is its own sprite (see KyogrePectoralFin)
static const union AnimCmd *const sAnims_DuoFightPre_Kyogre[] =
{
    sAnim_DuoFightPre_Kyogre_TopLeft,
    sAnim_DuoFightPre_Kyogre_TopRight,
    sAnim_DuoFightPre_Kyogre_FaceLeft,
    sAnim_DuoFightPre_Kyogre_FaceRight,
    sAnim_DuoFightPre_Kyogre_ChinLeft,
    sAnim_DuoFightPre_Kyogre_ChinRight,
    sAnim_DuoFightPre_Kyogre_LeftPectoralFin,
    sAnim_DuoFightPre_Kyogre_LeftShoulder,
    sAnim_DuoFightPre_Kyogre_RightShoulder
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_Kyogre =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x16,
    .anims = sAnims_DuoFightPre_Kyogre,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_KyogrePectoralFin[] =
{
    ANIMCMD_FRAME(0, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_FRAME(4, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_KyogrePectoralFin[] =
{
    sAnim_DuoFightPre_KyogrePectoralFin
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_KyogrePectoralFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_PECTORAL_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFightPre_KyogrePectoralFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_KyogreDorsalFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_DORSAL_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_GroudonShoulderKyogreDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams sScanlineParams_DuoFight_Clouds =
{
    .dmaDest = &REG_BG1HOFS,
    .dmaControl = SCANLINE_EFFECT_DMACNT_16BIT,
    .initState = 1
};

static const struct BgTemplate sBgTemplates_DuoFight[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const union AnimCmd sAnim_DuoFight_Groudon_Head[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_Groudon_Body[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_FRAME(320, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_Groudon[] =
{
    sAnim_DuoFight_Groudon_Head,
    sAnim_DuoFight_Groudon_Body
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_Groudon =
{
    gRaySceneDuoFight_Groudon_Gfx, 0x3000, TAG_DUOFIGHT_GROUDON
};

static const struct CompressedSpritePalette sSpritePal_DuoFight_Groudon =
{
    gRaySceneDuoFight_Groudon_Pal, TAG_DUOFIGHT_GROUDON
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_Groudon =
{
    .tileTag = TAG_DUOFIGHT_GROUDON,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_64x64,
    .anims = sAnims_DuoFight_Groudon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_GroudonShoulderKyogreDorsalFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFight_GroudonShoulderKyogreDorsalFin[] =
{
    sAnim_DuoFight_GroudonShoulderKyogreDorsalFin
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_GroudonShoulder =
{
    gRaySceneDuoFight_GroudonShoulder_Gfx, 0x200, TAG_DUOFIGHT_GROUDON_SHOULDER
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_GroudonShoulder =
{
    .tileTag = TAG_DUOFIGHT_GROUDON_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFight_GroudonShoulderKyogreDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_GroudonClaw[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFight_GroudonClaw[] =
{
    sAnim_DuoFight_GroudonClaw
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_GroudonClaw =
{
    gRaySceneDuoFight_GroudonClaw_Gfx, 0x400, TAG_DUOFIGHT_GROUDON_CLAW
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_GroudonClaw =
{
    .tileTag = TAG_DUOFIGHT_GROUDON_CLAW,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_64x32,
    .anims = sAnims_DuoFight_GroudonClaw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_Kyogre_TopLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_TopRight[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_FaceLeft[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_FaceRight[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_ChinLeft[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_ChinRight[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_Kyogre_LeftPectoralFin[] =
{
    ANIMCMD_FRAME(48, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_FRAME(80, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_Kyogre_LeftShoulder[] =
{
    ANIMCMD_FRAME(56, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_FRAME(88, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_Kyogre_RightShoulder[] =
{
    ANIMCMD_FRAME(96, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_FRAME(112, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_Kyogre[] =
{
    sAnim_DuoFight_Kyogre_TopLeft,
    sAnim_DuoFight_Kyogre_TopRight,
    sAnim_DuoFight_Kyogre_FaceLeft,
    sAnim_DuoFight_Kyogre_FaceRight,
    sAnim_DuoFight_Kyogre_ChinLeft,
    sAnim_DuoFight_Kyogre_ChinRight,
    sAnim_DuoFight_Kyogre_LeftPectoralFin,
    sAnim_DuoFight_Kyogre_LeftShoulder,
    sAnim_DuoFight_Kyogre_RightShoulder
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_Kyogre =
{
    gRaySceneDuoFight_Kyogre_Gfx, 0xF00, TAG_DUOFIGHT_KYOGRE
};

static const struct CompressedSpritePalette sSpritePal_DuoFight_Kyogre =
{
    gRaySceneDuoFight_Kyogre_Pal, TAG_DUOFIGHT_KYOGRE
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_Kyogre =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x16,
    .anims = sAnims_DuoFight_Kyogre,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_KyogrePectoralFin[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_KyogrePectoralFin[] =
{
    sAnim_DuoFight_KyogrePectoralFin
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_KyogrePectoralFin =
{
    gRaySceneDuoFight_KyogrePectoralFin_Gfx, 0xC0, TAG_DUOFIGHT_KYOGRE_PECTORAL_FIN
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_KyogrePectoralFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_PECTORAL_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFight_KyogrePectoralFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_KyogreDorsalFin =
{
    gRaySceneDuoFight_KyogreDorsalFin_Gfx, 0x200, TAG_DUOFIGHT_KYOGRE_DORSAL_FIN
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_KyogreDorsalFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_DORSAL_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFight_GroudonShoulderKyogreDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_TakesFlight[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_TakesFlight_Smoke[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_TakesFlight_Smoke[] =
{
    sAnim_TakesFlight_Smoke
};

static const union AffineAnimCmd sAffineAnim_TakesFlight_Smoke[] =
{
    AFFINEANIMCMD_FRAME(-64, -64, 0, 1),
    AFFINEANIMCMD_FRAME(32, 32, 0, 14),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_TakesFlight_Smoke[] =
{
    sAffineAnim_TakesFlight_Smoke
};

static const struct CompressedSpriteSheet sSpriteSheet_TakesFlight_Smoke =
{
    gRaySceneTakesFlight_Smoke_Gfx, 0x100, TAG_FLIGHT_SMOKE
};

static const struct CompressedSpritePalette sSpritePal_TakesFlight_Smoke =
{
    gRaySceneTakesFlight_Smoke_Pal, TAG_FLIGHT_SMOKE
};

static const struct SpriteTemplate sSpriteTemplate_TakesFlight_Smoke =
{
    .tileTag = TAG_FLIGHT_SMOKE,
    .paletteTag = TAG_FLIGHT_SMOKE,
    .oam = &sOam_32x16,
    .anims = sAnims_TakesFlight_Smoke,
    .images = NULL,
    .affineAnims = sAffineAnims_TakesFlight_Smoke,
    .callback = SpriteCB_TakesFlight_Smoke,
};

static const s8 sTakesFlight_SmokeCoords[MAX_SMOKE][2] =
{
    {-1,  5},
    {-3, -4},
    { 5, -3},
    {-7,  2},
    {-9, -1},
    { 1, -5},
    { 3,  4},
    {-5,  3},
    { 7, -2},
    { 9,  1}
};

static const struct BgTemplate sBgTemplates_Descends[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_Descends_Rayquaza[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Descends_Rayquaza[] =
{
    sAnim_Descends_Rayquaza
};

static const union AnimCmd sAnim_Descends_RayquazaTail[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(8, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Descends_RayquazaTail[] =
{
    sAnim_Descends_RayquazaTail
};

static const struct CompressedSpriteSheet sSpriteSheet_Descends_Rayquaza =
{
    gRaySceneDescends_Rayquaza_Gfx, 0x1000, TAG_DESCENDS_RAYQUAZA
};

static const struct CompressedSpriteSheet sSpriteSheet_Descends_RayquazaTail =
{
    gRaySceneDescends_RayquazaTail_Gfx, 0x200, TAG_DESCENDS_RAYQUAZA_TAIL
};

static const struct CompressedSpritePalette sSpritePal_Descends_Rayquaza =
{
    gRaySceneTakesFlight_Rayquaza_Pal, TAG_DESCENDS_RAYQUAZA // "Takes flight" palette re-used here
};

static const struct SpriteTemplate sSpriteTemplate_Descends_Rayquaza =
{
    .tileTag = TAG_DESCENDS_RAYQUAZA,
    .paletteTag = TAG_DESCENDS_RAYQUAZA,
    .oam = &sOam_64x64,
    .anims = sAnims_Descends_Rayquaza,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Descends_RayquazaTail =
{
    .tileTag = TAG_DESCENDS_RAYQUAZA_TAIL,
    .paletteTag = TAG_DESCENDS_RAYQUAZA,
    .oam = &sOam_16x32,
    .anims = sAnims_Descends_RayquazaTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_Charges[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_ChasesAway_Groudon_Still[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Groudon_Moving[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(128, 32),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_ChasesAway_Groudon[] =
{
    sAnim_ChasesAway_Groudon_Still,
    sAnim_ChasesAway_Groudon_Moving
};

static const union AnimCmd sAnim_ChasesAway_GroudonTail[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_GroudonTail[] =
{
    sAnim_ChasesAway_GroudonTail,
};

static const union AnimCmd sAnim_ChasesAway_Kyogre_Front[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Kyogre_Back[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Kyogre_Tail[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_Kyogre[] =
{
    sAnim_ChasesAway_Kyogre_Front,
    sAnim_ChasesAway_Kyogre_Back,
    sAnim_ChasesAway_Kyogre_Tail
};

static const union AnimCmd sAnim_ChasesAway_Rayquaza_FlyingDown[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Rayquaza_Arriving[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Rayquaza_Floating[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Rayquaza_Shouting[] =
{
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_Rayquaza[] =
{
    sAnim_ChasesAway_Rayquaza_FlyingDown,
    sAnim_ChasesAway_Rayquaza_Arriving,
    sAnim_ChasesAway_Rayquaza_Floating,
    sAnim_ChasesAway_Rayquaza_Shouting
};

static const union AnimCmd sAnim_ChasesAway_RayquazaTail_FlyingDown[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_RayquazaTail_Arriving[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_RayquazaTail_Floating[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_RayquazaTail_Shouting[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_RayquazaTail[] =
{
    sAnim_ChasesAway_RayquazaTail_FlyingDown,
    sAnim_ChasesAway_RayquazaTail_Arriving,
    sAnim_ChasesAway_RayquazaTail_Floating,
    sAnim_ChasesAway_RayquazaTail_Shouting
};

static const union AnimCmd sAnim_ChasesAway_KyogreSplash[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(20, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_ChasesAway_KyogreSplash[] =
{
    sAnim_ChasesAway_KyogreSplash
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_Groudon =
{
    gRaySceneChasesAway_Groudon_Gfx, 0x1800, TAG_CHASE_GROUDON
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_GroudonTail =
{
    gRaySceneChasesAway_GroudonTail_Gfx, 0x80, TAG_CHASE_GROUDON_TAIL
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_Kyogre =
{
    gRaySceneChasesAway_Kyogre_Gfx, 0x600, TAG_CHASE_KYOGRE
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_Rayquaza =
{
    gRaySceneChasesAway_Rayquaza_Gfx, 0x2000, TAG_CHASE_RAYQUAZA
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_RayquazaTail =
{
    gRaySceneChasesAway_RayquazaTail_Gfx, 0x800, TAG_CHASE_RAYQUAZA_TAIL
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_KyogreSplash =
{
    gRaySceneChasesAway_KyogreSplash_Gfx, 0x300, TAG_CHASE_SPLASH
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_Groudon =
{
    gRaySceneChasesAway_Groudon_Pal, TAG_CHASE_GROUDON
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_Kyogre =
{
    gRaySceneChasesAway_Kyogre_Pal, TAG_CHASE_KYOGRE
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_Rayquaza =
{
    gRaySceneChasesAway_Rayquaza_Pal, TAG_CHASE_RAYQUAZA
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_KyogreSplash =
{
    gRaySceneChasesAway_KyogreSplash_Pal, TAG_CHASE_SPLASH
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_Groudon =
{
    .tileTag = TAG_CHASE_GROUDON,
    .paletteTag = TAG_CHASE_GROUDON,
    .oam = &sOam_64x64,
    .anims = sAnims_ChasesAway_Groudon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_GroudonTail =
{
    .tileTag = TAG_CHASE_GROUDON_TAIL,
    .paletteTag = TAG_CHASE_GROUDON,
    .oam = &sOam_16x16,
    .anims = sAnims_ChasesAway_GroudonTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_Kyogre =
{
    .tileTag = TAG_CHASE_KYOGRE,
    .paletteTag = TAG_CHASE_KYOGRE,
    .oam = &sOam_32x32,
    .anims = sAnims_ChasesAway_Kyogre,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_Rayquaza =
{
    .tileTag = TAG_CHASE_RAYQUAZA,
    .paletteTag = TAG_CHASE_RAYQUAZA,
    .oam = &sOam_64x64,
    .anims = sAnims_ChasesAway_Rayquaza,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ChasesAway_Rayquaza,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_RayquazaTail =
{
    .tileTag = TAG_CHASE_RAYQUAZA_TAIL,
    .paletteTag = TAG_CHASE_RAYQUAZA,
    .oam = &sOam_32x32,
    .anims = sAnims_ChasesAway_RayquazaTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_KyogreSplash =
{
    .tileTag = TAG_CHASE_SPLASH,
    .paletteTag = TAG_CHASE_SPLASH,
    .oam = &sOam_32x8,
    .anims = sAnims_ChasesAway_KyogreSplash,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_ChasesAway[] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

void DoRayquazaScene(u8 animId, bool8 endEarly, void (*exitCallback)(void))
{
    sRayScene = AllocZeroed(sizeof(*sRayScene));
    sRayScene->animId = animId;
    sRayScene->exitCallback = exitCallback;
    sRayScene->endEarly = endEarly;
    SetMainCallback2(CB2_InitRayquazaScene);
}

static void CB2_InitRayquazaScene(void)
{
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    FillPalette(RGB_BLACK, 0xF0, 32);
    CreateTask(sTasksForAnimations[sRayScene->animId], 0);
    SetMainCallback2(CB2_RayquazaScene);
}

static void CB2_RayquazaScene(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_RayquazaScene(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_EndAfterFadeScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetMainCallback2(sRayScene->exitCallback);
        Free(sRayScene);
        DestroyTask(taskId);
    }
}

static void Task_SetNextAnim(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sRayScene->endEarly == TRUE)
        {
            gTasks[taskId].func = Task_EndAfterFadeScreen;
        }
        else
        {
            sRayScene->animId++;
            sRayScene->unk = 0;
            gTasks[taskId].func = sTasksForAnimations[sRayScene->animId];
        }
    }
}

// The cutscene window is cropped to a narrower view, with black borders on each vertical edge
// This function is used in scenes where sprites in these borders need to be hidden
static void SetWindowsHideVertBorders(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, DISPLAY_HEIGHT - 24));
    gPlttBufferUnfaded[0] = 0;
    gPlttBufferFaded[0] = 0;
}

static void ResetWindowDimensions(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);
}


// RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE

#define tTimer           data[0]
#define tHelperTaskId    data[1]
#define tGroudonSpriteId data[2]
#define tKyogreSpriteId  data[3]

#define sGroudonBodySpriteId     data[0]
#define sGroudonShoulderSpriteId data[1]
#define sGroudonClawSpriteId     data[2]

static void Task_HandleDuoFightPre(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        s16 frame = tTimer;
        if (frame == 64)
        {
            DuoFight_Lightning1();
        }
        else if (frame == 144)
        {
            DuoFight_Lightning2();
        }
        else
        {
            switch (frame)
            {
            case 328:
                DuoFightEnd(taskId, 0);
                return;
            case 148:
                DuoFight_LightningLong();
                break;
            }
        }

        tTimer++;
    }
}

static u8 DuoFightPre_CreateGroudonSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_Groudon, 88, 72, 3);
    gSprites[spriteId].callback = SpriteCB_DuoFightPre_Groudon;
    data = gSprites[spriteId].data;
    sGroudonBodySpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_Groudon, 56, 104, 3);
    sGroudonShoulderSpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_GroudonShoulder, 75, 101, 0);
    sGroudonClawSpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_GroudonClaw, 109, 114, 1);
    StartSpriteAnim(&gSprites[sGroudonBodySpriteId], 1);
    return spriteId;
}

static void SpriteCB_DuoFightPre_Groudon(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0x1F;
    if (data[5] == 0 && sprite->x != 72)
    {
        sprite->x--;
        gSprites[sprite->sGroudonBodySpriteId].x--;
        gSprites[sGroudonShoulderSpriteId].x--;
        gSprites[sGroudonClawSpriteId].x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sGroudonShoulderSpriteId].x2 = 0;
        gSprites[sGroudonShoulderSpriteId].y2 = 0;
        gSprites[sGroudonClawSpriteId].x2 = 0;
        gSprites[sGroudonClawSpriteId].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sGroudonShoulderSpriteId].x2 = -1;
        gSprites[sGroudonShoulderSpriteId].y2 = 0;
        gSprites[sGroudonClawSpriteId].x2 = -1;
        gSprites[sGroudonClawSpriteId].y2 = 0;
        break;
    case 2:
        gSprites[sGroudonShoulderSpriteId].x2 = -1;
        gSprites[sGroudonShoulderSpriteId].y2 = 1;
        gSprites[sGroudonClawSpriteId].x2 = -2;
        gSprites[sGroudonClawSpriteId].y2 = 1;
        break;
    }
}

static u8 DuoFightPre_CreateKyogreSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 136, 96, 1);
    gSprites[spriteId].callback = SpriteCB_DuoFightPre_Kyogre;
    data = gSprites[spriteId].data;

    data[0]  = CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 168,  96, 1) << 8;
    data[0] |= CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 136, 112, 1);
    data[1]  = CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 168, 112, 1) << 8;
    data[1] |= CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 136, 128, 1);
    data[2]  = CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 168, 128, 1) << 8;
    data[2] |= CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 104, 128, 2);
    data[3]  = CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 136, 128, 2) << 8;
    data[3] |= CreateSprite(&sSpriteTemplate_DuoFightPre_Kyogre, 184, 128, 0);
    data[4]  = CreateSprite(&sSpriteTemplate_DuoFightPre_KyogrePectoralFin, 208, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFightPre_KyogreDorsalFin, 200, 120, 1);

    StartSpriteAnim(&gSprites[data[0] >> 8], 1);
    StartSpriteAnim(&gSprites[data[0] & 0xFF], 2);
    StartSpriteAnim(&gSprites[data[1] >> 8], 3);
    StartSpriteAnim(&gSprites[data[1] & 0xFF], 4);
    StartSpriteAnim(&gSprites[data[2] >> 8], 5);
    StartSpriteAnim(&gSprites[data[2] & 0xFF], 6);
    StartSpriteAnim(&gSprites[data[3] >> 8], 7);
    StartSpriteAnim(&gSprites[data[3] & 0xFF], 8);

    return spriteId;
}

static void SpriteCB_DuoFightPre_Kyogre(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0x1F;
    if (data[5] == 0 && sprite->x != 152)
    {
        sprite->x++;
        gSprites[sprite->data[0] >> 8].x++;
        gSprites[sprite->data[0] & 0xFF].x++;
        gSprites[data[1] >> 8].x++;
        gSprites[data[1] & 0xFF].x++;
        gSprites[data[2] >> 8].x++;
        gSprites[data[2] & 0xFF].x++;
        gSprites[data[3] >> 8].x++;
        gSprites[data[3] & 0xFF].x++;
        gSprites[data[4] >> 8].x++;
        gSprites[data[4] & 0xFF].x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->y2 = 0;
        gSprites[data[0] >> 8].y2 = 0;
        gSprites[data[0] & 0xFF].y2 = 0;
        gSprites[data[1] >> 8].y2 = 0;
        gSprites[data[1] & 0xFF].y2 = 0;
        gSprites[data[2] >> 8].y2 = 0;
        gSprites[data[2] & 0xFF].y2 = 0;
        gSprites[data[3] >> 8].y2 = 0;
        gSprites[data[3] & 0xFF].y2 = 0;
        gSprites[data[4] >> 8].y2 = 0;
        gSprites[data[4] & 0xFF].y2 = 0;
        break;
    case 1:
    case 3:
        sprite->y2 = 1;
        gSprites[data[0] >> 8].y2 = 1;
        gSprites[data[0] & 0xFF].y2 = 1;
        gSprites[data[1] >> 8].y2 = 1;
        gSprites[data[1] & 0xFF].y2 = 1;
        gSprites[data[2] >> 8].y2 = 1;
        gSprites[data[2] & 0xFF].y2 = 1;
        gSprites[data[3] >> 8].y2 = 1;
        gSprites[data[3] & 0xFF].y2 = 1;
        gSprites[data[4] >> 8].y2 = 1;
        gSprites[data[4] & 0xFF].y2 = 1;
        break;
    case 2:
        sprite->y2 = 2;
        gSprites[data[0] >> 8].y2 = 2;
        gSprites[data[0] & 0xFF].y2 = 2;
        gSprites[data[1] >> 8].y2 = 2;
        gSprites[data[1] & 0xFF].y2 = 2;
        gSprites[data[2] >> 8].y2 = 2;
        gSprites[data[4] & 0xFF].y2 = 2;
        break;
    }
}

static void VBlankCB_DuoFight(void)
{
    VBlankCB_RayquazaScene();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void InitDuoFightSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_DuoFight, ARRAY_COUNT(sBgTemplates_DuoFight));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadDuoFightSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDuoFight_Clouds_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDuoFight_Clouds2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneDuoFight_Clouds1_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneDuoFight_Clouds3_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneDuoFight_Clouds_Pal, 0, 0x40);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_Groudon);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_GroudonShoulder);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_GroudonClaw);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_Kyogre);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_KyogrePectoralFin);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_KyogreDorsalFin);
    LoadCompressedSpritePalette(&sSpritePal_DuoFight_Groudon);
    LoadCompressedSpritePalette(&sSpritePal_DuoFight_Kyogre);
}

static void Task_DuoFightAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ScanlineEffect_Clear();
    InitDuoFightSceneBgs();
    LoadDuoFightSceneGfx();
    CpuFastFill16(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    ScanlineEffect_SetParams(sScanlineParams_DuoFight_Clouds);
    tTimer = 0;
    tHelperTaskId = CreateTask(Task_DuoFight_AnimateClouds, 0);
    if (sRayScene->animId == RAY_ANIM_DUO_FIGHT_PRE)
    {
        tGroudonSpriteId = DuoFightPre_CreateGroudonSprites();
        tKyogreSpriteId = DuoFightPre_CreateKyogreSprites();
        gTasks[taskId].func = Task_HandleDuoFightPre;
    }
    else
    {
        tGroudonSpriteId = DuoFight_CreateGroudonSprites();
        tKyogreSpriteId = DuoFight_CreateKyogreSprites();
        gTasks[taskId].func = Task_HandleDuoFight;
        StopMapMusic();
    }

    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_DuoFight);
    PlaySE(SE_DOWNPOUR);
}

static void Task_DuoFight_AnimateClouds(u8 taskId)
{
    s16 i;
    u16 *data = gTasks[taskId].data;

    for (i = 24; i < 92; i++)
    {
        if (i <= 47)
        {
            gScanlineEffectRegBuffers[0][i] = data[0] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[0] >> 8;
        }
        else if (i <= 63)
        {
            gScanlineEffectRegBuffers[0][i] = data[1] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[1] >> 8;
        }
        else if (i <= 75)
        {
            gScanlineEffectRegBuffers[0][i] = data[2] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[2] >> 8;
        }
        else if (i <= 83)
        {
            gScanlineEffectRegBuffers[0][i] = data[3] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[3] >> 8;
        }
        else if (i <= 87)
        {
            gScanlineEffectRegBuffers[0][i] = data[4] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[4] >> 8;
        }
        else
        {
            gScanlineEffectRegBuffers[0][i] = data[5] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[5] >> 8;
        }
    }

    if (sRayScene->animId == RAY_ANIM_DUO_FIGHT_PRE)
    {
        data[0] += 448;
        data[1] += 384;
        data[2] += 320;
        data[3] += 256;
        data[4] += 192;
        data[5] += 128;
    }
    else
    {
        data[0] += 768;
        data[1] += 640;
        data[2] += 512;
        data[3] += 384;
        data[4] += 256;
        data[5] += 128;
    }
}

static void Task_HandleDuoFight(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        s16 frame = tTimer;
        if (frame == 32 || frame == 112)
        {
            DuoFight_Lightning1();
        }
        else if (frame == 216)
        {
            DuoFight_Lightning2();
        }
        else if (frame == 220)
        {
            DuoFight_LightningLong();
        }
        else
        {
            switch (frame)
            {
            case 412:
                DuoFightEnd(taskId, 2);
                return;
            case 380:
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
                gTasks[tHelperTaskId].func = DuoFight_PanOffScene;
                gTasks[tHelperTaskId].data[0] = 0;
                gTasks[tHelperTaskId].data[2] = data[2];
                gTasks[tHelperTaskId].data[3] = data[3];
                ScanlineEffect_Stop();
                break;
            }
        }

        tTimer++;
    }
}

// In the below functions, BlendPalettesGradually flashes the bg white and the duo black
// and gradually fades them back to original color to simulate lightning
static void DuoFight_Lightning1(void)
{
    PlaySE(SE_THUNDER);
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 0, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_Lightning2(void)
{
    PlaySE(SE_THUNDER);
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 0, 16, 16, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 16, RGB_BLACK,      0, 1);
}

static void DuoFight_LightningLong(void)
{
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 4, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 4, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_AnimateRain(void)
{
    ChangeBgX(2, 0x400, BG_COORD_ADD);
    ChangeBgY(2, 0x800, BG_COORD_SUB);
}

// Only used by the full version, which pans up at the end (so scene objects move down)
// DuoFightPre just fades to black with no pan
static void DuoFight_PanOffScene(u8 taskId)
{
    u16 bgY;
    s16 *data = gTasks[taskId].data;
    DuoFight_SlideGroudonDown(&gSprites[tGroudonSpriteId]);
    DuoFight_SlideKyogreDown(&gSprites[tKyogreSpriteId]);

    bgY = GetBgY(1);
    if (GetBgY(1) == 0 || bgY > 0x8000)
        ChangeBgY(1, 0x400, BG_COORD_SUB);

    if (tTimer != 16)
    {
        tTimer++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - tTimer, tTimer));
    }
}

static void DuoFightEnd(u8 taskId, s8 palDelay)
{
    PlaySE(SE_DOWNPOUR_STOP);
    BeginNormalPaletteFade(PALETTES_ALL, palDelay, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_DuoFightEnd;
}

static void Task_DuoFightEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        DestroyTask(tHelperTaskId);
        ChangeBgY(1, 0, BG_COORD_SET);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        tTimer = 0;
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

static u8 DuoFight_CreateGroudonSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFight_Groudon, 98, 72, 3);
    gSprites[spriteId].callback = SpriteCB_DuoFight_Groudon;
    data = gSprites[spriteId].data;
    sGroudonBodySpriteId = CreateSprite(&sSpriteTemplate_DuoFight_Groudon, 66, 104, 3);
    sGroudonShoulderSpriteId = CreateSprite(&sSpriteTemplate_DuoFight_GroudonShoulder, 85, 101, 0);
    sGroudonClawSpriteId = CreateSprite(&sSpriteTemplate_DuoFight_GroudonClaw, 119, 114, 1);
    StartSpriteAnim(&gSprites[sGroudonBodySpriteId], 1);
    return spriteId;
}

static void SpriteCB_DuoFight_Groudon(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0xF;
    if (!(data[5] & 7) && sprite->x != 72)
    {
        sprite->x--;
        gSprites[sprite->sGroudonBodySpriteId].x--;
        gSprites[sGroudonShoulderSpriteId].x--;
        gSprites[sGroudonClawSpriteId].x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sGroudonShoulderSpriteId].x2 = 0;
        gSprites[sGroudonShoulderSpriteId].y2 = 0;
        gSprites[sGroudonClawSpriteId].x2 = 0;
        gSprites[sGroudonClawSpriteId].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sGroudonShoulderSpriteId].x2 = -1;
        gSprites[sGroudonShoulderSpriteId].y2 = 0;
        gSprites[sGroudonClawSpriteId].x2 = -1;
        gSprites[sGroudonClawSpriteId].y2 = 0;
        break;
    case 2:
        gSprites[sGroudonShoulderSpriteId].x2 = -1;
        gSprites[sGroudonShoulderSpriteId].y2 = 1;
        gSprites[sGroudonClawSpriteId].x2 = -2;
        gSprites[sGroudonClawSpriteId].y2 = 1;
        break;
    }
}

static void DuoFight_SlideGroudonDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->y <= DISPLAY_HEIGHT)
    {
        sprite->y += 8;
        gSprites[sprite->sGroudonBodySpriteId].y += 8;
        gSprites[sGroudonShoulderSpriteId].y += 8;
        gSprites[sGroudonClawSpriteId].y += 8;
    }
}

static u8 DuoFight_CreateKyogreSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 126, 96, 1);
    gSprites[spriteId].callback = SpriteCB_DuoFight_Kyogre;
    data = gSprites[spriteId].data;

    data[0] = CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 158, 96, 1) << 8;
    data[0] |= CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 126, 112, 1);
    data[1] = CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 158, 112, 1) << 8;
    data[1] |= CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 126, 128, 1);
    data[2] = CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 158, 128, 1) << 8;
    data[2] |= CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 94, 128, 2);
    data[3] = CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 126, 128, 2) << 8;
    data[3] |= CreateSprite(&sSpriteTemplate_DuoFight_Kyogre, 174, 128, 0);
    data[4] = CreateSprite(&sSpriteTemplate_DuoFight_KyogrePectoralFin, 198, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFight_KyogreDorsalFin, 190, 120, 1);

    StartSpriteAnim(&gSprites[data[0] >> 8], 1);
    StartSpriteAnim(&gSprites[data[0] & 0xFF], 2);
    StartSpriteAnim(&gSprites[data[1] >> 8], 3);
    StartSpriteAnim(&gSprites[data[1] & 0xFF], 4);
    StartSpriteAnim(&gSprites[data[2] >> 8], 5);
    StartSpriteAnim(&gSprites[data[2] & 0xFF], 6);
    StartSpriteAnim(&gSprites[data[3] >> 8], 7);
    StartSpriteAnim(&gSprites[data[3] & 0xFF], 8);

    return spriteId;
}

static void SpriteCB_DuoFight_Kyogre(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0xF;
    if (!(data[5] & 7) && sprite->x != 152)
    {
        sprite->x++;
        gSprites[sprite->data[0] >> 8].x++;
        gSprites[sprite->data[0] & 0xFF].x++;
        gSprites[data[1] >> 8].x++;
        gSprites[data[1] & 0xFF].x++;
        gSprites[data[2] >> 8].x++;
        gSprites[data[2] & 0xFF].x++;
        gSprites[data[3] >> 8].x++;
        gSprites[data[3] & 0xFF].x++;
        gSprites[data[4] >> 8].x++;
        gSprites[data[4] & 0xFF].x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->y2 = 0;
        gSprites[data[0] >> 8].y2 = 0;
        gSprites[data[0] & 0xFF].y2 = 0;
        gSprites[data[1] >> 8].y2 = 0;
        gSprites[data[1] & 0xFF].y2 = 0;
        gSprites[data[2] >> 8].y2 = 0;
        gSprites[data[2] & 0xFF].y2 = 0;
        gSprites[data[3] >> 8].y2 = 0;
        gSprites[data[3] & 0xFF].y2 = 0;
        gSprites[data[4] >> 8].y2 = 0;
        gSprites[data[4] & 0xFF].y2 = 0;
        break;
    case 1:
    case 3:
        sprite->y2 = 1;
        gSprites[data[0] >> 8].y2 = 1;
        gSprites[data[0] & 0xFF].y2 = 1;
        gSprites[data[1] >> 8].y2 = 1;
        gSprites[data[1] & 0xFF].y2 = 1;
        gSprites[data[2] >> 8].y2 = 1;
        gSprites[data[2] & 0xFF].y2 = 1;
        gSprites[data[3] >> 8].y2 = 1;
        gSprites[data[3] & 0xFF].y2 = 1;
        gSprites[data[4] >> 8].y2 = 1;
        gSprites[data[4] & 0xFF].y2 = 1;
        break;
    case 2:
        sprite->y2 = 2;
        gSprites[data[0] >> 8].y2 = 2;
        gSprites[data[0] & 0xFF].y2 = 2;
        gSprites[data[1] >> 8].y2 = 2;
        gSprites[data[1] & 0xFF].y2 = 2;
        gSprites[data[2] >> 8].y2 = 2;
        gSprites[data[4] & 0xFF].y2 = 2;
        break;
    }
}

static void DuoFight_SlideKyogreDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->y <= DISPLAY_HEIGHT)
    {
        sprite->y += 8;
        gSprites[sprite->data[0] >> 8].y += 8;
        gSprites[sprite->data[0] & 0xFF].y += 8;
        gSprites[data[1] >> 8].y += 8;
        gSprites[data[1] & 0xFF].y += 8;
        gSprites[data[2] >> 8].y += 8;
        gSprites[data[2] & 0xFF].y += 8;
        gSprites[data[3] >> 8].y += 8;
        gSprites[data[3] & 0xFF].y += 8;
        gSprites[data[4] >> 8].y += 8;
        gSprites[data[4] & 0xFF].y += 8;
    }
}

#undef tTimer
#undef tHelperTaskId
#undef tGroudonSpriteId
#undef tKyogreSpriteId

#undef sGroudonBodySpriteId
#undef sGroudonShoulderSpriteId
#undef sGroudonClawSpriteId


// RAY_ANIM_TAKES_FLIGHT

#define tState      data[0]
#define tTimer      data[1]
#define tScale      data[2]
#define tScaleSpeed data[3]
#define tYCoord     data[4]
#define tYSpeed     data[5]
#define tYOffset    data[6]
#define tYOffsetDir data[7]

static void InitTakesFlightSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates_TakesFlight, ARRAY_COUNT(sBgTemplates_TakesFlight));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadTakesFlightSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDuoFight_Clouds_Gfx, 0, 0, 0); // Re-uses clouds from previous scene
    DecompressAndCopyTileDataToVram(1, gRaySceneTakesFlight_Bg_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(2, gRaySceneTakesFlight_Rayquaza_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDuoFight_Clouds2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneTakesFlight_Bg_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneTakesFlight_Rayquaza_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneTakesFlight_Rayquaza_Pal, 0, 64);
    LoadCompressedSpriteSheet(&sSpriteSheet_TakesFlight_Smoke);
    LoadCompressedSpritePalette(&sSpritePal_TakesFlight_Smoke);
}

static void Task_RayTakesFlightAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    PlayNewMapMusic(MUS_RAYQUAZA_APPEARS);
    InitTakesFlightSceneBgs();
    LoadTakesFlightSceneGfx();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
    BlendPalettes(PALETTES_ALL, 16, 0);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    CreateTask(Task_TakesFlight_CreateSmoke, 0);
    tState = 0;
    tTimer = 0;
    gTasks[taskId].func = Task_HandleRayTakesFlight;
}

// Animate Rayquaza (flying up and down, and changing size as it gets further from the screen)
// In this scene Rayquaza is a bg tilemap on bg 2, not a sprite
static void Task_HandleRayTakesFlight(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tScale = 0;
            tScaleSpeed = 30;
            tYCoord = 0;
            tYSpeed = 7;
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Fly in
        tScale += tScaleSpeed;
        tYCoord += tYSpeed;

        if (tScaleSpeed > 3)
            tScaleSpeed -= 3;

        if (tYSpeed != 0)
            tYSpeed--;

        if (tScale > 255)
        {
            tScale = 256;
            tScaleSpeed = 0;
            tYOffset = 12;
            tYOffsetDir = -1;
            tTimer = 0;
            tState++;
        }
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32, tScale, tScale, 0);
        break;
    case 2:
        // Float up and down
        tTimer++;
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32 + (tYOffset >> 2), tScale, tScale, 0);
        tYOffset += tYOffsetDir;
        if (tYOffset == 12 || tYOffset == -12)
        {
            tYOffsetDir *= -1;
            if (tTimer > 295)
            {
                tState++;
                BeginNormalPaletteFade(PALETTES_ALL, 6, 0, 0x10, RGB_BLACK);
            }
        }
        break;
    case 3:
        // Fly away, fade out
        tScale += 16;
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32, tScale, tScale, 0);
        Task_RayTakesFlightEnd(taskId);
        break;
    }
}

#undef tState
#undef tTimer
#undef tScale
#undef tScaleSpeed
#undef tYCoord
#undef tYSpeed
#undef tYOffset
#undef tYOffsetDir

static void Task_RayTakesFlightEnd(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#define tSmokeId data[0]
#define tTimer   data[1]

#define sSmokeId data[0]
#define sTimer   data[1]

static void Task_TakesFlight_CreateSmoke(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 3) == 0)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_TakesFlight_Smoke,
                                   (sTakesFlight_SmokeCoords[tSmokeId][0] * 4) + 120,
                                   (sTakesFlight_SmokeCoords[tSmokeId][1] * 4) + 80,
                                   0);
        gSprites[spriteId].sSmokeId = (s8)(tSmokeId);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        gSprites[spriteId].oam.priority = 2;
        InitSpriteAffineAnim(&gSprites[spriteId]);
        if (tSmokeId == MAX_SMOKE - 1)
        {
            DestroyTask(taskId);
            return;
        }
        else
        {
            tSmokeId++;
        }
    }

    tTimer++;
}

#undef tSmokeId
#undef tTimer

static void SpriteCB_TakesFlight_Smoke(struct Sprite *sprite)
{
    if (sprite->sTimer == 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        sprite->x2 += sTakesFlight_SmokeCoords[sprite->sSmokeId][0];
        sprite->y2 += sTakesFlight_SmokeCoords[sprite->sSmokeId][1];
    }

    sprite->sTimer++;
    sprite->sTimer &= 0xF;
}

#undef sSmokeId
#undef sTimer


// RAY_ANIM_DESCENDS

static void InitDescendsSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_Descends, ARRAY_COUNT(sBgTemplates_Descends));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    SetBgTilemapBuffer(3, sRayScene->tilemapBuffers[3]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadDescendsSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDescends_Light_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(1, gRaySceneDescends_Bg_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDescends_Light_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneDescends_Bg_Tilemap, sRayScene->tilemapBuffers[3]);
    CpuFastFill16(0, sRayScene->tilemapBuffers[2], BG_SCREEN_SIZE);
    CpuFastCopy(sRayScene->tilemapBuffers[3], sRayScene->tilemapBuffers[1], BG_SCREEN_SIZE);
    CpuFastFill16(0, &sRayScene->tilemapBuffers[1][0x100], 0x340);

    LoadCompressedPalette(gRaySceneDescends_Bg_Pal, 0, 0x40);
    gPlttBufferUnfaded[0] = RGB_WHITE;
    gPlttBufferFaded[0] = RGB_WHITE;
    LoadCompressedSpriteSheet(&sSpriteSheet_Descends_Rayquaza);
    LoadCompressedSpriteSheet(&sSpriteSheet_Descends_RayquazaTail);
    LoadCompressedSpritePalette(&sSpritePal_Descends_Rayquaza);
}

// Draw ray of light emerging from the clouds
static void HBlankCB_RayDescends(void)
{
    u16 vcount = GetGpuReg(REG_OFFSET_VCOUNT);
    if (vcount >= 24 && vcount <= 135 && vcount - 24 <= sRayScene->revealedLightLine)
        REG_BLDALPHA = 0xD08; // This line is above where light has been revealed, draw it
    else
        REG_BLDALPHA = 0x1000; // Below where light has been revealed, hide it

    if (vcount == 0)
    {
        if (sRayScene->revealedLightLine <= 0x1FFF)
        {
            // Increase the number of pixel rows of the light that have been revealed
            // Gradually slows as it reaches the bottom
            if (sRayScene->revealedLightLine <= 39)
                sRayScene->revealedLightLine += 4;
            else if (sRayScene->revealedLightLine <= 79)
                sRayScene->revealedLightLine += 2;
            else
                sRayScene->revealedLightLine += 1;
        }

        // Pointless
        sRayScene->revealedLightTimer++;
    }
}

#define tState data[0]
#define tTimer data[1]

static void Task_RayDescendsAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitDescendsSceneBgs();
    LoadDescendsSceneGfx();
    SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    sRayScene->revealedLightLine = 0;
    sRayScene->revealedLightTimer = 0;
    tState = 0;
    tTimer = 0;
    data[2] = 0; // Below data assignments do nothing
    data[3] = 0;
    data[4] = 0x1000;
    gTasks[taskId].func = Task_HandleRayDescends;
}

static void Task_HandleRayDescends(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            // Delay, then start ray of light
            if (tTimer == 10)
            {
                tTimer = 0;
                tState++;
                SetHBlankCallback(HBlankCB_RayDescends);
                EnableInterrupts(INTR_FLAG_HBLANK | INTR_FLAG_VBLANK);
            }
            else
            {
                tTimer++;
            }
        }
        break;
    case 2:
        // Delay, then start Rayquaza emerging from clouds
        if (tTimer == 80)
        {
            tTimer = 0;
            tState++;
            CreateDescendsRayquazaSprite();
        }
        else
        {
            tTimer++;
        }
        break;
    case 3:
        // Wait while Rayquaza descends
        if (++tTimer == 368)
        {
            tTimer = 0;
            tState++;
        }
        break;
    case 4:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayDescendsEnd;
        break;
    }
}

static void Task_RayDescendsEnd(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#define sTailSpriteId data[0]
#define sTimer        data[2]
#define sXMovePeriod  data[3]
#define sYMovePeriod  data[4]

static u8 CreateDescendsRayquazaSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Descends_Rayquaza, 160, 0, 0);
    s16 *data = gSprites[spriteId].data;
    sTailSpriteId = CreateSprite(&sSpriteTemplate_Descends_RayquazaTail, 184, -48, 0);
    gSprites[spriteId].callback = SpriteCB_Descends_Rayquaza;
    gSprites[spriteId].oam.priority = 3;
    gSprites[sTailSpriteId].oam.priority = 3;
    return spriteId;
}

static void SpriteCB_Descends_Rayquaza(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    s16 frame = sTimer;

    // Updates to Rayquaza's coords occur more frequently
    // as time goes on (it accelerates as it emerges)
    if (frame == 0)
    {
        sXMovePeriod = 12;
        sYMovePeriod = 8;
    }
    else if (frame == 256)
    {
        sXMovePeriod = 9;
        sYMovePeriod = 7;
    }
    else if (frame == 268)
    {
        sXMovePeriod = 8;
        sYMovePeriod = 6;
    }
    else if (frame == 280)
    {
        sXMovePeriod = 7;
        sYMovePeriod = 5;
    }
    else if (frame == 292)
    {
        sXMovePeriod = 6;
        sYMovePeriod = 4;
    }
    else if (frame == 304)
    {
        sXMovePeriod = 5;
        sYMovePeriod = 3;
    }
    else if (frame == 320)
    {
        sXMovePeriod = 4;
        sYMovePeriod = 2;
    }

    if (sTimer % sXMovePeriod == 0)
    {
        sprite->x2--;
        gSprites[sTailSpriteId].x2--;
    }
    if (sTimer % sYMovePeriod == 0)
    {
        sprite->y2++;
        gSprites[sTailSpriteId].y2++;
    }

    sTimer++;
}

#undef sTailSpriteId
#undef sTimer
#undef sXMovePeriod
#undef sYMovePeriod


// RAY_ANIM_CHARGES

static void InitChargesSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_Charges, ARRAY_COUNT(sBgTemplates_Charges));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    SetBgTilemapBuffer(3, sRayScene->tilemapBuffers[3]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadChargesSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, gRaySceneCharges_Rayquaza_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(2, gRaySceneCharges_Streaks_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(3, gRaySceneCharges_Bg_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneCharges_Orbs_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneCharges_Rayquaza_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneCharges_Streaks_Tilemap, sRayScene->tilemapBuffers[2]);
    LZDecompressWram(gRaySceneCharges_Bg_Tilemap, sRayScene->tilemapBuffers[3]);
    LoadCompressedPalette(gRaySceneCharges_Bg_Pal, 0, 0x80);
}

#define tState          data[0]
#define tTimer          data[1]
#define tRayquazaTaskId data[2]
#define tSoundTimer     data[3]

static void Task_RayChargesAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChargesSceneBgs();
    LoadChargesSceneGfx();
    SetWindowsHideVertBorders();
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    tState = 0;
    tTimer = 0;
    tRayquazaTaskId = CreateTask(Task_RayCharges_ShakeRayquaza, 0);
    gTasks[taskId].func = Task_HandleRayCharges;
}

static void Task_HandleRayCharges(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    RayCharges_AnimateBg();
    if ((tSoundTimer & 7) == 0 && tState <= 1 && tTimer <= 89)
        PlaySE(SE_INTRO_BLAST);

    tSoundTimer++;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Delay while Rayquaza shakes, then start Rayquaza moving offscreen
        if (tTimer == 127)
        {
            tTimer = 0;
            tState++;
            gTasks[tRayquazaTaskId].func = Task_RayCharges_FlyOffscreen;
        }
        else
        {
            tTimer++;
        }
        break;
    case 2:
        // Delay for Rayquaza's flying animation
        if (tTimer == 12)
        {
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 3:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChargesEnd;
        break;
    }
}

#undef tState
#undef tTimer
#undef tSoundTimer

#define tState    data[0]
#define tOffset   data[1]
#define tShakeDir data[2]
#define tTimer    data[15]

static void Task_RayCharges_ShakeRayquaza(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 3) == 0)
    {
        ChangeBgX(1, (Random() % 8 - 4) << 8, BG_COORD_SET);
        ChangeBgY(1, (Random() % 8 - 4) << 8, BG_COORD_SET);
    }

    tTimer++;
}

// Rayquaza backs up then launches forward
static void Task_RayCharges_FlyOffscreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tState == 0)
    {
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        tState++;
        tOffset = 10;
        tShakeDir = -1;
    }
    else if (tState == 1)
    {
        ChangeBgX(1, tOffset << 8, BG_COORD_SUB);
        ChangeBgY(1, tOffset << 8, BG_COORD_ADD);
        tOffset += tShakeDir;
        if (tOffset == -10)
            tShakeDir *= -1;
    }
}

#undef tState
#undef tOffset
#undef tShakeDir
#undef tTimer

static void RayCharges_AnimateBg(void)
{
    // Update yellow orbs
    ChangeBgX(2, 0x400, BG_COORD_SUB);
    ChangeBgY(2, 0x400, BG_COORD_ADD);

    // Update blue streaks
    ChangeBgX(0, 0x800, BG_COORD_SUB);
    ChangeBgY(0, 0x800, BG_COORD_ADD);
}

static void Task_RayChargesEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    RayCharges_AnimateBg();
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        ResetWindowDimensions();
        DestroyTask(tRayquazaTaskId);
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#undef tRayquazaTaskId


// RAY_ANIM_CHASES_AWAY

static void InitChasesAwaySceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates_ChasesAway, ARRAY_COUNT(sBgTemplates_ChasesAway));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadChasesAwaySceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(2, gRaySceneChasesAway_Ring_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(0, gRaySceneChasesAway_Light_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneChasesAway_Bg_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneChasesAway_Light_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneChasesAway_Ring_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneChasesAway_Bg_Pal, 0, 0x60);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_Groudon);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_GroudonTail);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_Kyogre);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_Rayquaza);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_RayquazaTail);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_KyogreSplash);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_Groudon);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_Kyogre);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_Rayquaza);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_KyogreSplash);
}

#define tState    data[0]
#define tTimer    data[1]
#define tBgTaskId data[2]

static void Task_RayChasesAwayAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChasesAwaySceneBgs();
    LoadChasesAwaySceneGfx();
    SetWindowsHideVertBorders();
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 14));
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    tState = 0;
    tTimer = 0;
    gTasks[taskId].func = Task_HandleRayChasesAway;
    tBgTaskId = CreateTask(Task_ChasesAway_AnimateBg, 0);
    gTasks[tBgTaskId].data[0] = 0;
    gTasks[tBgTaskId].data[1] = 0;
    gTasks[tBgTaskId].data[2] = 0;
    gTasks[tBgTaskId].data[3] = 1;
    gTasks[tBgTaskId].data[4] = 1;
}

static void Task_HandleRayChasesAway(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            ChasesAway_CreateTrioSprites(taskId);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Wait for Rayquaza to enter and finish shout anim
        if (gSprites[data[5]].callback == SpriteCB_ChasesAway_RayquazaFloat)
        {
            // Delay, then start Groudon/Kyogre leaving
            if (tTimer == 64)
            {
                ChasesAway_KyogreStartLeave(taskId);
                ChasesAway_GroudonStartLeave(taskId);
                tTimer = 0;
                tState++;
            }
            else
            {
                tTimer++;
            }
        }
        break;
    case 2:
        // Wait for Groudon/Kyogre to leave
        if (tTimer == 448)
        {
            tTimer = 0;
            tState++;
        }
        else
        {
            // Flash bg white and trio black a few times
            tTimer++;
            if (tTimer % 144 == 0)
            {
                BlendPalettesGradually(PALETTES_BG & ~1, 0, 16, 0, RGB_WHITEALPHA, 0, 0);
                BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK,      0, 1);
            }
        }
        break;
    case 3:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChasesAwayEnd;
        break;
    }
}

#undef tState
#undef tTimer

#define tTimer      data[0]
#define tBlendHi    data[1]
#define tBlendLo    data[2]
#define tBlendHiDir data[3]
#define tBlendLoDir data[4]

// Flickers the ray of light behind Rayquaza
static void Task_ChasesAway_AnimateBg(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 0xF) == 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, ((tBlendHi + 14) << 8 & 0x1F00) | ((tBlendLo + 9) & 0xF));
        tBlendHi -= tBlendHiDir;
        tBlendLo += tBlendLoDir;
        if (tBlendHi == -3 || tBlendHi == 0)
            tBlendHiDir *= -1;
        if (tBlendLo == 3 || tBlendLo == 0)
            tBlendLoDir *= -1;
    }

    tTimer++;
}

#undef tTimer
#undef tBlendHi
#undef tBlendLo
#undef tBlendHiDir
#undef tBlendLoDir

#define tTimer data[1]

static void Task_RayChasesAwayEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        StopMapMusic();
        if (tTimer == 0)
        {
            SetVBlankCallback(NULL);
            ResetWindowDimensions();
            ResetSpriteData();
            FreeAllSpritePalettes();
            DestroyTask(tBgTaskId);
        }

        if (tTimer == 32)
        {
            tTimer = 0;
            gTasks[taskId].func = Task_SetNextAnim;
        }
        else
        {
            tTimer++;
        }
    }
}

#undef tTimer
#undef tBgTaskId

#define tGroudonSpriteId  taskData[3]
#define tKyogreSpriteId   taskData[4]
#define tRayquazaSpriteId taskData[5]

static void ChasesAway_CreateTrioSprites(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;

    tGroudonSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_Groudon, 64, 120, 0);
    spriteData = gSprites[tGroudonSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_GroudonTail, 16, 130, 0);
    gSprites[tGroudonSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;

    tKyogreSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 160, 128, 1);
    spriteData = gSprites[tKyogreSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 192, 128, 1);
    spriteData[1] = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 224, 128, 1);
    gSprites[tKyogreSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
    gSprites[spriteData[1]].oam.priority = 1;
    StartSpriteAnim(&gSprites[spriteData[0]], 1);
    StartSpriteAnim(&gSprites[spriteData[1]], 2);

    tRayquazaSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_Rayquaza, 120, -65, 0);
    spriteData = gSprites[tRayquazaSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_RayquazaTail, 120, -113, 0);
    gSprites[tRayquazaSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
}

#define sBodyPartSpriteId1 data[0]
#define sBodyPartSpriteId2 data[1]
#define sTimer             data[4]
#define sDecel             data[5]
#define sSpeed             data[6]
#define sIsKyogre          data[7]

static void ChasesAway_PushDuoBack(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;

    gSprites[tGroudonSpriteId].callback = SpriteCB_ChasesAway_DuoRingPush;
    gSprites[tGroudonSpriteId].sTimer = 0;
    gSprites[tGroudonSpriteId].sDecel = 0;
    gSprites[tGroudonSpriteId].sSpeed = 4;
    gSprites[tGroudonSpriteId].sIsKyogre = FALSE;

    gSprites[tKyogreSpriteId].callback = SpriteCB_ChasesAway_DuoRingPush;
    gSprites[tKyogreSpriteId].sTimer = 0;
    gSprites[tKyogreSpriteId].sDecel = 0;
    gSprites[tKyogreSpriteId].sSpeed = 4;
    gSprites[tKyogreSpriteId].sIsKyogre = TRUE;
}

// Pushes Groudon/Kyogre back slightly, for when Rayquaza's hyper voice ring comes out
static void SpriteCB_ChasesAway_DuoRingPush(struct Sprite *sprite)
{
    if ((sprite->sTimer & 7) == 0)
    {
        if (!sprite->sIsKyogre)
        {
            sprite->x -= sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId1].x -= sprite->sSpeed;
        }
        else
        {
            sprite->x += sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId1].x += sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId2].x += sprite->sSpeed;
        }

        sprite->sDecel++;
        sprite->sSpeed -= sprite->sDecel;
        if (sprite->sDecel == 3)
        {
            sprite->sTimer = 0;
            sprite->sDecel = 0;
            sprite->sSpeed = 0;
            sprite->callback = SpriteCallbackDummy;
            return;
        }
    }

    sprite->sTimer++;
}

#undef sBodyPartSpriteId1
#undef sBodyPartSpriteId2
#undef sTimer
#undef sDecel
#undef sSpeed
#undef sIsKyogre

static void ChasesAway_GroudonStartLeave(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    gSprites[tGroudonSpriteId].callback = SpriteCB_ChasesAway_GroudonLeave;
    StartSpriteAnim(&gSprites[tGroudonSpriteId], 1);
}

static void SpriteCB_ChasesAway_GroudonLeave(struct Sprite *sprite)
{
    switch (sprite->animCmdIndex)
    {
    case 0:
    case 2:
        if (sprite->animDelayCounter % 12 == 0)
        {
            sprite->x -= 2;
            gSprites[sprite->data[0]].x -=2;
        }
        gSprites[sprite->data[0]].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sprite->data[0]].y2 = -2;
        if ((sprite->animDelayCounter & 15) == 0)
        {
            sprite->y++;
            gSprites[sprite->data[0]].y++;
        }
        break;
    }
}

static void ChasesAway_KyogreStartLeave(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;
    spriteData = gSprites[tKyogreSpriteId].data;

    gSprites[tKyogreSpriteId].callback = SpriteCB_ChasesAway_KyogreLeave;
    gSprites[spriteData[0]].callback = SpriteCB_ChasesAway_KyogreLeave;
    gSprites[spriteData[1]].callback = SpriteCB_ChasesAway_KyogreLeave;
}

static void SpriteCB_ChasesAway_KyogreLeave(struct Sprite *sprite)
{
    if ((sprite->data[4] & 3) == 0)
    {
        if (sprite->x2 == 1)
            sprite->x2 = -1;
        else
            sprite->x2 = 1;
    }
    if (sprite->data[5] == 128)
    {
        sprite->data[7] = CreateSprite(&sSpriteTemplate_ChasesAway_KyogreSplash, 152, 132, 0);
        gSprites[sprite->data[7]].oam.priority = 1;
        sprite->data[7] = CreateSprite(&sSpriteTemplate_ChasesAway_KyogreSplash, 224, 132, 0);
        gSprites[sprite->data[7]].oam.priority = 1;
        gSprites[sprite->data[7]].hFlip = 1;
        sprite->data[5]++;
    }
    if (sprite->data[5] > 127)
    {
        if (sprite->y2 != 32)
        {
            sprite->data[6]++;
            sprite->y2 = sprite->data[6] >> 4;
        }
    }
    else
    {
        sprite->data[5]++;
    }

    if (sprite->data[4] % 64 == 0)
        PlaySE(SE_M_WHIRLPOOL);

    sprite->data[4]++;
}

#define sTailSpriteId data[0]
#define sYOffset      data[4]
#define sYOffsetDir   data[5]
#define sFloatTimer   data[6]
#define sTimer        data[7]

#define sTailFloatDelay  data[4]
#define sTailFloatPeak   data[5]

static void SpriteCB_ChasesAway_Rayquaza(struct Sprite *sprite)
{
    s16 frame = sprite->sTimer;
    if (frame <= 64)
    {
        sprite->y2 += 2;
        gSprites[sprite->sTailSpriteId].y2 += 2;
        if (sprite->sTimer == 64)
        {
            ChasesAway_SetRayquazaAnim(sprite, 1, 0, -48);
            sprite->sYOffset = 5;
            sprite->sYOffsetDir = -1;
            gSprites[sprite->sTailSpriteId].sTailFloatDelay = 3;
            gSprites[sprite->sTailSpriteId].sTailFloatPeak = 5;
        }
    }
    else if (frame <= 111)
    {
        SpriteCB_ChasesAway_RayquazaFloat(sprite);
        if (sprite->sYOffset == 0)
            PlaySE(SE_MUGSHOT);
        if (sprite->sYOffset == -3)
            ChasesAway_SetRayquazaAnim(sprite, 2, 48, 16);
    }
    else if (frame == 112)
    {
        gSprites[sprite->sTailSpriteId].sTailFloatDelay = 7;
        gSprites[sprite->sTailSpriteId].sTailFloatPeak = 3;
        SpriteCB_ChasesAway_RayquazaFloat(sprite);
    }
    else if (frame <= 327)
    {
        SpriteCB_ChasesAway_RayquazaFloat(sprite);
    }
    else if (frame == 328)
    {
        SpriteCB_ChasesAway_RayquazaFloat(sprite);
        ChasesAway_SetRayquazaAnim(sprite, 3, 48, 16);
        sprite->x2 = 1;
        gSprites[sprite->sTailSpriteId].x2 = 1;
        PlayCry_Normal(SPECIES_RAYQUAZA, 0);
        CreateTask(Task_ChasesAway_AnimateRing, 0);
    }
    else
    {
        switch (frame)
        {
        case 376:
            sprite->x2 = 0;
            gSprites[sprite->sTailSpriteId].x2 = 0;
            SpriteCB_ChasesAway_RayquazaFloat(sprite);
            ChasesAway_SetRayquazaAnim(sprite, 2, 48, 16);
            sprite->callback = SpriteCB_ChasesAway_RayquazaFloat;
            return;
        case 352:
            ChasesAway_PushDuoBack(FindTaskIdByFunc(Task_HandleRayChasesAway));
            break;
        }
    }

    if (sprite->sTimer > 328 && (sprite->sTimer & 1) == 0)
    {
        sprite->x2 *= -1;
        gSprites[sprite->sTailSpriteId].x2 = sprite->x2;
    }

    sprite->sTimer++;
}

static void SpriteCB_ChasesAway_RayquazaFloat(struct Sprite *body)
{
    struct Sprite *tail = &gSprites[body->sTailSpriteId];
    if (!(body->sFloatTimer & tail->sTailFloatDelay))
    {
        body->y2 += body->sYOffset;
        gSprites[body->sTailSpriteId].y2 += body->sYOffset; // why access gSprites again? tail->y2 would be sufficient
        body->sYOffset += body->sYOffsetDir;
        if (body->sYOffset >= tail->sTailFloatPeak || body->sYOffset <= -tail->sTailFloatPeak)
        {
            if (body->sYOffset > tail->sTailFloatPeak)
                body->sYOffset = tail->sTailFloatPeak;
            else if (body->sYOffset < -tail->sTailFloatPeak)
                body->sYOffset = -tail->sTailFloatPeak;

            body->sYOffsetDir *= -1;
        }
    }

    body->sFloatTimer++;
}

static void ChasesAway_SetRayquazaAnim(struct Sprite *body, u8 animNum, s16 x, s16 y)
{
    struct Sprite *tail = &gSprites[body->sTailSpriteId];

    tail->x = body->x + x;
    tail->y = body->y + y;

    tail->x2 = body->x2;
    tail->y2 = body->y2;

    StartSpriteAnim(body, animNum);
    StartSpriteAnim(tail, animNum);
}

#undef sTailSpriteId
#undef sYOffset
#undef sYOffsetDir
#undef sFloatTimer
#undef sTimer
#undef sTailFloatDelay
#undef sTailFloatPeak

#define tState      data[0]
#define tScale      data[1]
#define tNumRings   data[2]
#define tScaleTimer data[3]
#define tScaleSpeed data[4]
#define tSoundTimer data[5]

static void Task_ChasesAway_AnimateRing(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        SetBgAffine(2, 0x4000, 0x4000, 120, 64, 256, 256, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        tScaleSpeed = 16;
        tState++;
        break;
    case 1:
        if (tSoundTimer == 8)
            PlaySE(SE_SLIDING_DOOR);
        if (tNumRings == 2)
        {
            tState++;
        }
        else
        {
            tScale += tScaleSpeed;
            tSoundTimer++;
            if (tScaleTimer % 3 == 0 && tScaleSpeed != 4)
                tScaleSpeed -= 2;

            tScaleTimer++;
            SetBgAffine(2, 0x4000, 0x4000, 120, 64, 256 - tScale, 256 - tScale, 0);
            if (tScale > 255)
            {
                tScale = 0;
                tScaleTimer = 0;
                tSoundTimer = 0;
                tScaleSpeed = 16;
                tNumRings++;
            }
        }
        break;
    case 2:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        DestroyTask(taskId);
        break;
    }
}

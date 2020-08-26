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
#include "constants/species.h"
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

#define TAG_DUOFIGHT_GROUDON          30505
#define TAG_DUOFIGHT_GROUDON_SHOULDER 30506
#define TAG_DUOFIGHT_GROUDON_CLAW     30507
#define TAG_DUOFIGHT_KYOGRE           30508
#define TAG_DUOFIGHT_KYOGRE_SHOULDER  30509
#define TAG_DUOFIGHT_KYOGRE_FIN       30510
#define TAG_FLIGHT_SMOKE              30555
#define TAG_DESCENDS_RAYQUAZA         30556
#define TAG_DESCENDS_RAYQUAZA_TAIL    30557
#define TAG_CHASE_GROUDON             30565
#define TAG_CHASE_GROUDON_TAIL        30566
#define TAG_CHASE_KYOGRE              30568
#define TAG_CHASE_RAYQUAZA            30569
#define TAG_CHASE_RAYQUAZA_TAIL       30570
#define TAG_CHASE_SPLASH              30571

struct RayquazaScene
{
    MainCallback exitCallback;
    u8 tilemapBuffers[4][BG_SCREEN_SIZE];
    u16 unk; // never read
    u8 animId;
    bool8 endEarly;
    s16 field_2008;
    s16 field_200A;
    u8 unused[12];
};

static EWRAM_DATA struct RayquazaScene *sRayScene = NULL;

static void CB2_InitRayquazaScene(void);
static void CB2_RayquazaScene(void);
static void Task_EndAfterFadeScreen(u8 taskId);

// RAY_ANIM_DUO_FIGHT_PRE / RAY_ANIM_DUO_FIGHT
static void Task_DuoFightAnim(u8 taskId);
static void Task_HandleDuoFight(u8 taskId);
static void Task_DuoFightEnd(u8 taskId);
static void DuoFightEnd(u8 taskId, s8 palDelay);
static void Task_DuoFight_AnimateClouds(u8 taskId);
static void DuoFight_PanOffScene(u8 taskId);
static void DuoFight_AnimateRain(void);
static void DuoFight_Lightning1(void);
static void DuoFight_Lightning2(void);
static void DuoFight_LightningLong(void);
static void SpriteCB_DuoFightPre_Groudon(struct Sprite *sprite);
static void SpriteCB_DuoFightPre_Kyogre(struct Sprite *sprite);
static void DuoFight_SlideGroudonDown(struct Sprite *sprite);
static void DuoFight_SlideKyogreDown(struct Sprite *sprite);
static void SpriteCB_DuoFight_Groudon(struct Sprite *sprite);
static void SpriteCB_DuoFight_Kyogre(struct Sprite *sprite);
static u8 CreateDuoFightGroudonSprites(void);
static u8 CreateDuoFightKyogreSprites(void);

// RAY_ANIM_TAKES_FLIGHT
static void Task_RayTakesFlightAnim(u8 taskId);
static void Task_HandleRayTakesFlight(u8 taskId);
static void Task_RayTakesFlightEnd(u8 taskId);
static void sub_81D81A4(u8 taskId);
static void SpriteCB_TakesFlight_Smoke(struct Sprite *sprite);

// RAY_ANIM_DESCENDS
static void Task_RayDescendsAnim(u8 taskId);
static void Task_HandleRayDescends(u8 taskId);
static void Task_RayDescendsEnd(u8 taskId);
static void sub_81D874C(struct Sprite *sprite);
static u8 sub_81D86CC(void);

// RAY_ANIM_CHARGES
static void Task_RayChargesAnim(u8 taskId);
static void Task_HandleRayCharges(u8 taskId);
static void Task_RayChargesEnd(u8 taskId);
static void sub_81D8AD8(u8 taskId);
static void sub_81D8B2C(u8 taskId);
static void sub_81D8BB4(void);

// RAY_ANIM_CHASES_AWAY
static void Task_RayChasesAwayAnim(u8 taskId);
static void Task_HandleRayChasesAway(u8 taskId);
static void Task_RayChasesAwayEnd(u8 taskId);
static void sub_81D8FB0(u8 taskId);
static void sub_81D94D4(u8 taskId);
static void sub_81D93D8(u8 taskId);
static void sub_81D90A8(u8 taskId);
static void sub_81D98B4(u8 taskId);
static void sub_81D9420(struct Sprite *sprite);
static void sub_81D97E0(struct Sprite *sprite);
static void sub_81D9528(struct Sprite *sprite);
static void SpriteCB_ChasesAway_Rayquaza(struct Sprite *sprite);
static void sub_81D9338(struct Sprite *sprite);
static void sub_81D9868(struct Sprite *sprite, u8 animNum, s16 x, s16 y);

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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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

static const union AnimCmd sSpriteAnim_862A6FC[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A710[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_Groudon[] =
{
    sSpriteAnim_862A6FC,
    sSpriteAnim_862A710
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

static const union AnimCmd sAnim_DuoFightPre_GroudonShoulderKyogreFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFightPre_GroudonShoulderKyogreFin[] =
{
    sAnim_DuoFightPre_GroudonShoulderKyogreFin
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_GroudonShoulder =
{
    .tileTag = TAG_DUOFIGHT_GROUDON_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_GROUDON,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_GroudonShoulderKyogreFin,
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

static const union AnimCmd sSpriteAnim_862A78C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A794[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A79C[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7A4[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7AC[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7B4[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7BC[] =
{
    ANIMCMD_FRAME(48, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_FRAME(80, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A7D0[] =
{
    ANIMCMD_FRAME(56, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_FRAME(88, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A7E4[] =
{
    ANIMCMD_FRAME(96, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_FRAME(112, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_Kyogre[] =
{
    sSpriteAnim_862A78C,
    sSpriteAnim_862A794,
    sSpriteAnim_862A79C,
    sSpriteAnim_862A7A4,
    sSpriteAnim_862A7AC,
    sSpriteAnim_862A7B4,
    sSpriteAnim_862A7BC,
    sSpriteAnim_862A7D0,
    sSpriteAnim_862A7E4
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

static const union AnimCmd sAnim_DuoFightPre_KyogreShoulder[] =
{
    ANIMCMD_FRAME(0, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_FRAME(4, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_KyogreShoulder[] =
{
    sAnim_DuoFightPre_KyogreShoulder
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_KyogreShoulder =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFightPre_KyogreShoulder,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_KyogreFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_GroudonShoulderKyogreFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams sScanlineParams_DuoFight_Clouds =
{
    .dmaDest = (vu16 *)REG_ADDR_BG1HOFS,
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

static const union AnimCmd sSpriteAnim_862A894[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A8A8[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_FRAME(320, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_Groudon[] =
{
    sSpriteAnim_862A894,
    sSpriteAnim_862A8A8
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

static const union AnimCmd sAnim_DuoFight_GroudonShoulderKyogreFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFight_GroudonShoulderKyogreFin[] =
{
    sAnim_DuoFight_GroudonShoulderKyogreFin
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
    .anims = sAnims_DuoFight_GroudonShoulderKyogreFin,
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

static const union AnimCmd sSpriteAnim_862A944[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A94C[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A954[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A95C[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A964[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A96C[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A974[] =
{
    ANIMCMD_FRAME(48, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_FRAME(80, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A988[] =
{
    ANIMCMD_FRAME(56, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_FRAME(88, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A99C[] =
{
    ANIMCMD_FRAME(96, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_FRAME(112, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_Kyogre[] =
{
    sSpriteAnim_862A944,
    sSpriteAnim_862A94C,
    sSpriteAnim_862A954,
    sSpriteAnim_862A95C,
    sSpriteAnim_862A964,
    sSpriteAnim_862A96C,
    sSpriteAnim_862A974,
    sSpriteAnim_862A988,
    sSpriteAnim_862A99C
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

static const union AnimCmd sAnim_DuoFight_KyogreShoulder[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_KyogreShoulder[] =
{
    sAnim_DuoFight_KyogreShoulder
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_KyogreShoulder =
{
    gRaySceneDuoFight_KyogreShoulder_Gfx, 0xC0, TAG_DUOFIGHT_KYOGRE_SHOULDER
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_KyogreShoulder =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFight_KyogreShoulder,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_KyogreFin =
{
    gRaySceneDuoFight_KyogreFin_Gfx, 0x200, TAG_DUOFIGHT_KYOGRE_FIN
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_KyogreFin =
{
    .tileTag = TAG_DUOFIGHT_KYOGRE_FIN,
    .paletteTag = TAG_DUOFIGHT_KYOGRE,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFight_GroudonShoulderKyogreFin,
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

static const s8 sUnknown_0862AAB8[][2] =
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

static const union AnimCmd sSpriteAnim_862AB54[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB5C[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(128, 32),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_ChasesAway_Groudon[] =
{
    sSpriteAnim_862AB54,
    sSpriteAnim_862AB5C
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

static const union AnimCmd sSpriteAnim_862AB84[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB8C[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB94[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_Kyogre[] =
{
    sSpriteAnim_862AB84,
    sSpriteAnim_862AB8C,
    sSpriteAnim_862AB94
};

static const union AnimCmd sSpriteAnim_862ABA8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABB0[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABB8[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABC0[] =
{
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_Rayquaza[] =
{
    sSpriteAnim_862ABA8,
    sSpriteAnim_862ABB0,
    sSpriteAnim_862ABB8,
    sSpriteAnim_862ABC0
};

static const union AnimCmd sSpriteAnim_862ABD8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABE0[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABE8[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABF0[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_RayquazaTail[] =
{
    sSpriteAnim_862ABD8,
    sSpriteAnim_862ABE0,
    sSpriteAnim_862ABE8,
    sSpriteAnim_862ABF0
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

static void sub_81D68C8(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, DISPLAY_HEIGHT - 24));
    gPlttBufferUnfaded[0] = 0;
    gPlttBufferFaded[0] = 0;
}

static void sub_81D6904(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
}

#define tCounter         data[0]
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
        s16 counter = tCounter;
        if (counter == 64)
        {
            DuoFight_Lightning1();
        }
        else if (counter == 144)
        {
            DuoFight_Lightning2();
        }
        else
        {
            switch (counter)
            {
            case 328:
                DuoFightEnd(taskId, 0);
                return;
            case 148:
                DuoFight_LightningLong();
                break;
            }
        }

        tCounter++;
    }
}

static u8 CreateDuoFightPreGroudonSprites(void)
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
    if (data[5] == 0 && sprite->pos1.x != 72)
    {
        sprite->pos1.x--;
        gSprites[sprite->sGroudonBodySpriteId].pos1.x--;
        gSprites[sGroudonShoulderSpriteId].pos1.x--;
        gSprites[sGroudonClawSpriteId].pos1.x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sGroudonShoulderSpriteId].pos2.x = 0;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 0;
        gSprites[sGroudonClawSpriteId].pos2.x = 0;
        gSprites[sGroudonClawSpriteId].pos2.y = 0;
        break;
    case 1:
    case 3:
        gSprites[sGroudonShoulderSpriteId].pos2.x = -1;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 0;
        gSprites[sGroudonClawSpriteId].pos2.x = -1;
        gSprites[sGroudonClawSpriteId].pos2.y = 0;
        break;
    case 2:
        gSprites[sGroudonShoulderSpriteId].pos2.x = -1;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 1;
        gSprites[sGroudonClawSpriteId].pos2.x = -2;
        gSprites[sGroudonClawSpriteId].pos2.y = 1;
        break;
    }
}

static u8 CreateDuoFightPreKyogreSprites(void)
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
    data[4]  = CreateSprite(&sSpriteTemplate_DuoFightPre_KyogreShoulder, 208, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFightPre_KyogreFin, 200, 120, 1);

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
    if (data[5] == 0 && sprite->pos1.x != 152)
    {
        sprite->pos1.x++;
        gSprites[sprite->data[0] >> 8].pos1.x++;
        gSprites[sprite->data[0] & 0xFF].pos1.x++;
        gSprites[data[1] >> 8].pos1.x++;
        gSprites[data[1] & 0xFF].pos1.x++;
        gSprites[data[2] >> 8].pos1.x++;
        gSprites[data[2] & 0xFF].pos1.x++;
        gSprites[data[3] >> 8].pos1.x++;
        gSprites[data[3] & 0xFF].pos1.x++;
        gSprites[data[4] >> 8].pos1.x++;
        gSprites[data[4] & 0xFF].pos1.x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->pos2.y = 0;
        gSprites[data[0] >> 8].pos2.y = 0;
        gSprites[data[0] & 0xFF].pos2.y = 0;
        gSprites[data[1] >> 8].pos2.y = 0;
        gSprites[data[1] & 0xFF].pos2.y = 0;
        gSprites[data[2] >> 8].pos2.y = 0;
        gSprites[data[2] & 0xFF].pos2.y = 0;
        gSprites[data[3] >> 8].pos2.y = 0;
        gSprites[data[3] & 0xFF].pos2.y = 0;
        gSprites[data[4] >> 8].pos2.y = 0;
        gSprites[data[4] & 0xFF].pos2.y = 0;
        break;
    case 1:
    case 3:
        sprite->pos2.y = 1;
        gSprites[data[0] >> 8].pos2.y = 1;
        gSprites[data[0] & 0xFF].pos2.y = 1;
        gSprites[data[1] >> 8].pos2.y = 1;
        gSprites[data[1] & 0xFF].pos2.y = 1;
        gSprites[data[2] >> 8].pos2.y = 1;
        gSprites[data[2] & 0xFF].pos2.y = 1;
        gSprites[data[3] >> 8].pos2.y = 1;
        gSprites[data[3] & 0xFF].pos2.y = 1;
        gSprites[data[4] >> 8].pos2.y = 1;
        gSprites[data[4] & 0xFF].pos2.y = 1;
        break;
    case 2:
        sprite->pos2.y = 2;
        gSprites[data[0] >> 8].pos2.y = 2;
        gSprites[data[0] & 0xFF].pos2.y = 2;
        gSprites[data[1] >> 8].pos2.y = 2;
        gSprites[data[1] & 0xFF].pos2.y = 2;
        gSprites[data[2] >> 8].pos2.y = 2;
        gSprites[data[4] & 0xFF].pos2.y = 2;
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
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_KyogreShoulder);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_KyogreFin);
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
    tCounter = 0;
    tHelperTaskId = CreateTask(Task_DuoFight_AnimateClouds, 0);
    if (sRayScene->animId == RAY_ANIM_DUO_FIGHT_PRE)
    {
        tGroudonSpriteId = CreateDuoFightPreGroudonSprites();
        tKyogreSpriteId = CreateDuoFightPreKyogreSprites();
        gTasks[taskId].func = Task_HandleDuoFightPre;
    }
    else
    {
        tGroudonSpriteId = CreateDuoFightGroudonSprites();
        tKyogreSpriteId = CreateDuoFightKyogreSprites();
        gTasks[taskId].func = Task_HandleDuoFight;
        StopMapMusic();
    }

    BlendPalettes(-1, 0x10, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_DuoFight);
    PlaySE(SE_T_OOAME);
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
        s16 counter = tCounter;
        if (counter == 32 || counter == 112)
        {
            DuoFight_Lightning1();
        }
        else if (counter == 216)
        {
            DuoFight_Lightning2();
        }
        else if (counter == 220)
        {
            DuoFight_LightningLong();
        }
        else
        {
            switch (counter)
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

        tCounter++;
    }
}

// In the below functions, BlendPalettesGradually flashes the bg white and the duo black
// and gradually fades them back to original color to simulate lightning
static void DuoFight_Lightning1(void)
{
    PlaySE(SE_T_KAMI);
    BlendPalettesGradually(0x00007FFF, 0, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(0xFFFF0000, 0, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_Lightning2(void)
{
    PlaySE(SE_T_KAMI);
    BlendPalettesGradually(0x00007FFF, 0, 16, 16, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(0xFFFF0000, 0, 16, 16, RGB_BLACK,      0, 1);
}

static void DuoFight_LightningLong(void)
{
    BlendPalettesGradually(0x00007FFF, 4, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(0xFFFF0000, 4, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_AnimateRain(void)
{
    ChangeBgX(2, 0x400, 1);
    ChangeBgY(2, 0x800, 2);
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
        ChangeBgY(1, 0x400, 2);

    if (tCounter != 16)
    {
        tCounter++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - tCounter, tCounter));
    }
}

static void DuoFightEnd(u8 taskId, s8 palDelay)
{
    PlaySE(SE_T_OOAME_E);
    BeginNormalPaletteFade(0xFFFFFFFF, palDelay, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_DuoFightEnd;
}

static void Task_DuoFightEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        DestroyTask(tHelperTaskId);
        ChangeBgY(1, 0, 0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        tCounter = 0;
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

static u8 CreateDuoFightGroudonSprites(void)
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
    if (!(data[5] & 7) && sprite->pos1.x != 72)
    {
        sprite->pos1.x--;
        gSprites[sprite->sGroudonBodySpriteId].pos1.x--;
        gSprites[sGroudonShoulderSpriteId].pos1.x--;
        gSprites[sGroudonClawSpriteId].pos1.x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sGroudonShoulderSpriteId].pos2.x = 0;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 0;
        gSprites[sGroudonClawSpriteId].pos2.x = 0;
        gSprites[sGroudonClawSpriteId].pos2.y = 0;
        break;
    case 1:
    case 3:
        gSprites[sGroudonShoulderSpriteId].pos2.x = -1;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 0;
        gSprites[sGroudonClawSpriteId].pos2.x = -1;
        gSprites[sGroudonClawSpriteId].pos2.y = 0;
        break;
    case 2:
        gSprites[sGroudonShoulderSpriteId].pos2.x = -1;
        gSprites[sGroudonShoulderSpriteId].pos2.y = 1;
        gSprites[sGroudonClawSpriteId].pos2.x = -2;
        gSprites[sGroudonClawSpriteId].pos2.y = 1;
        break;
    }
}

static void DuoFight_SlideGroudonDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->pos1.y <= 160)
    {
        sprite->pos1.y += 8;
        gSprites[sprite->sGroudonBodySpriteId].pos1.y += 8;
        gSprites[sGroudonShoulderSpriteId].pos1.y += 8;
        gSprites[sGroudonClawSpriteId].pos1.y += 8;
    }
}

static u8 CreateDuoFightKyogreSprites(void)
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
    data[4] = CreateSprite(&sSpriteTemplate_DuoFight_KyogreShoulder, 198, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFight_KyogreFin, 190, 120, 1);

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
    if (!(data[5] & 7) && sprite->pos1.x != 152)
    {
        sprite->pos1.x++;
        gSprites[sprite->data[0] >> 8].pos1.x++;
        gSprites[sprite->data[0] & 0xFF].pos1.x++;
        gSprites[data[1] >> 8].pos1.x++;
        gSprites[data[1] & 0xFF].pos1.x++;
        gSprites[data[2] >> 8].pos1.x++;
        gSprites[data[2] & 0xFF].pos1.x++;
        gSprites[data[3] >> 8].pos1.x++;
        gSprites[data[3] & 0xFF].pos1.x++;
        gSprites[data[4] >> 8].pos1.x++;
        gSprites[data[4] & 0xFF].pos1.x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->pos2.y = 0;
        gSprites[data[0] >> 8].pos2.y = 0;
        gSprites[data[0] & 0xFF].pos2.y = 0;
        gSprites[data[1] >> 8].pos2.y = 0;
        gSprites[data[1] & 0xFF].pos2.y = 0;
        gSprites[data[2] >> 8].pos2.y = 0;
        gSprites[data[2] & 0xFF].pos2.y = 0;
        gSprites[data[3] >> 8].pos2.y = 0;
        gSprites[data[3] & 0xFF].pos2.y = 0;
        gSprites[data[4] >> 8].pos2.y = 0;
        gSprites[data[4] & 0xFF].pos2.y = 0;
        break;
    case 1:
    case 3:
        sprite->pos2.y = 1;
        gSprites[data[0] >> 8].pos2.y = 1;
        gSprites[data[0] & 0xFF].pos2.y = 1;
        gSprites[data[1] >> 8].pos2.y = 1;
        gSprites[data[1] & 0xFF].pos2.y = 1;
        gSprites[data[2] >> 8].pos2.y = 1;
        gSprites[data[2] & 0xFF].pos2.y = 1;
        gSprites[data[3] >> 8].pos2.y = 1;
        gSprites[data[3] & 0xFF].pos2.y = 1;
        gSprites[data[4] >> 8].pos2.y = 1;
        gSprites[data[4] & 0xFF].pos2.y = 1;
        break;
    case 2:
        sprite->pos2.y = 2;
        gSprites[data[0] >> 8].pos2.y = 2;
        gSprites[data[0] & 0xFF].pos2.y = 2;
        gSprites[data[1] >> 8].pos2.y = 2;
        gSprites[data[1] & 0xFF].pos2.y = 2;
        gSprites[data[2] >> 8].pos2.y = 2;
        gSprites[data[4] & 0xFF].pos2.y = 2;
        break;
    }
}

static void DuoFight_SlideKyogreDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->pos1.y <= 160)
    {
        sprite->pos1.y += 8;
        gSprites[sprite->data[0] >> 8].pos1.y += 8;
        gSprites[sprite->data[0] & 0xFF].pos1.y += 8;
        gSprites[data[1] >> 8].pos1.y += 8;
        gSprites[data[1] & 0xFF].pos1.y += 8;
        gSprites[data[2] >> 8].pos1.y += 8;
        gSprites[data[2] & 0xFF].pos1.y += 8;
        gSprites[data[3] >> 8].pos1.y += 8;
        gSprites[data[3] & 0xFF].pos1.y += 8;
        gSprites[data[4] >> 8].pos1.y += 8;
        gSprites[data[4] & 0xFF].pos1.y += 8;
    }
}

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
    DecompressAndCopyTileDataToVram(0, gRaySceneDuoFight_Clouds_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(1, gRaySceneTakesFlight_Bg_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(2, gRaySceneTakesFlight_Rayquaza_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDuoFight_Clouds2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneTakesFlight_Bg_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneTakesFlight_Rayquaza_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneTakesFlight_Rayquaza_Pal, 0, 0x40);
    LoadCompressedSpriteSheet(&sSpriteSheet_TakesFlight_Smoke);
    LoadCompressedSpritePalette(&sSpritePal_TakesFlight_Smoke);
}

static void Task_RayTakesFlightAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    PlayNewMapMusic(MUS_REKKUU_KOURIN);
    InitTakesFlightSceneBgs();
    LoadTakesFlightSceneGfx();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
    BlendPalettes(-1, 0x10, 0);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    CreateTask(sub_81D81A4, 0);
    data[0] = 0;
    data[1] = 0;
    gTasks[taskId].func = Task_HandleRayTakesFlight;
}

static void Task_HandleRayTakesFlight(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        if (data[1] == 8)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            data[2] = 0;
            data[3] = 30;
            data[4] = 0;
            data[5] = 7;
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
        }
        break;
    case 1:
        data[2] += data[3];
        data[4] += data[5];
        if (data[3] > 3)
            data[3] -= 3;
        if (data[5] != 0)
            data[5]--;
        if (data[2] > 255)
        {
            data[2] = 256;
            data[3] = 0;
            data[6] = 12;
            data[7] = -1;
            data[1] = 0;
            data[0]++;
        }
        SetBgAffine(2, 0x7800, 0x1800, 0x78, data[4] + 32, data[2], data[2], 0);
        break;
    case 2:
        data[1]++;
        SetBgAffine(2, 0x7800, 0x1800, 0x78, data[4] + 32 + (data[6] >> 2), data[2], data[2], 0);
        data[6] += data[7];
        if (data[6] == 12 || data[6] == -12)
        {
            data[7] *= -1;
            if (data[1] > 295)
            {
                data[0]++;
                BeginNormalPaletteFade(0xFFFFFFFF, 6, 0, 0x10, RGB_BLACK);
            }
        }
        break;
    case 3:
        data[2] += 16;
        SetBgAffine(2, 0x7800, 0x1800, 0x78, data[4] + 32, data[2], data[2], 0);
        Task_RayTakesFlightEnd(taskId);
        break;
    }
}

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

static void sub_81D81A4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((data[1] & 3) == 0)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_TakesFlight_Smoke,
                                   (sUnknown_0862AAB8[data[0]][0] * 4) + 120,
                                   (sUnknown_0862AAB8[data[0]][1] * 4) + 80,
                                   0);
        gSprites[spriteId].data[0] = (s8)(data[0]);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        gSprites[spriteId].oam.priority = 2;
        InitSpriteAffineAnim(&gSprites[spriteId]);
        if (data[0] == 9)
        {
            DestroyTask(taskId);
            return;
        }
        else
        {
            data[0]++;
        }
    }

    data[1]++;
}

static void SpriteCB_TakesFlight_Smoke(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.x += sUnknown_0862AAB8[sprite->data[0]][0];
        sprite->pos2.y += sUnknown_0862AAB8[sprite->data[0]][1];
    }

    sprite->data[1]++;
    sprite->data[1] &= 0xF;
}

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
    while (FreeTempTileDataBuffersIfPossible());

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

static void HBlankCB_RayDescends(void)
{
    u16 VCOUNT = GetGpuReg(REG_OFFSET_VCOUNT);
    if (VCOUNT >= 24 && VCOUNT <= 135 && VCOUNT - 24 <= sRayScene->field_2008)
        REG_BLDALPHA = 0xD08;
    else
        REG_BLDALPHA = 0x1000;

    if (VCOUNT == 0)
    {
        if (sRayScene->field_2008 <= 0x1FFF)
        {
            if (sRayScene->field_2008 <= 39)
                sRayScene->field_2008 += 4;
            else if (sRayScene->field_2008 <= 79)
                sRayScene->field_2008 += 2;
            else
                sRayScene->field_2008 += 1;
        }

        sRayScene->field_200A++;
    }
}

static void Task_RayDescendsAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitDescendsSceneBgs();
    LoadDescendsSceneGfx();
    SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    BlendPalettes(-1, 0x10, 0);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    sRayScene->field_2008 = 0;
    sRayScene->field_200A = 0;
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0x1000;
    gTasks[taskId].func = Task_HandleRayDescends;
}

static void Task_HandleRayDescends(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        if (data[1] == 8)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            if (data[1] == 10)
            {
                data[1] = 0;
                data[0]++;
                SetHBlankCallback(HBlankCB_RayDescends);
                EnableInterrupts(INTR_FLAG_HBLANK | INTR_FLAG_VBLANK);
            }
            else
            {
                data[1]++;
            }
        }
        break;
    case 2:
        if (data[1] == 80)
        {
            data[1] = 0;
            data[0]++;
            sub_81D86CC();
        }
        else
        {
            data[1]++;
        }
        break;
    case 3:
        if (++data[1] == 368)
        {
            data[1] = 0;
            data[0]++;
        }
        break;
    case 4:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
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

static u8 sub_81D86CC(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Descends_Rayquaza, 160, 0, 0);
    s16 *data = gSprites[spriteId].data;
    data[0] = CreateSprite(&sSpriteTemplate_Descends_RayquazaTail, 184, -48, 0);
    gSprites[spriteId].callback = sub_81D874C;
    gSprites[spriteId].oam.priority = 3;
    gSprites[data[0]].oam.priority = 3;
    return spriteId;
}

static void sub_81D874C(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    s16 counter = data[2];
    if (counter == 0)
    {
        data[3] = 12;
        data[4] = 8;
    }
    else if (counter == 256)
    {
        data[3] = 9;
        data[4] = 7;
    }
    else if (counter == 268)
    {
        data[3] = 8;
        data[4] = 6;
    }
    else if (counter == 280)
    {
        data[3] = 7;
        data[4] = 5;
    }
    else if (counter == 292)
    {
        data[3] = 6;
        data[4] = 4;
    }
    else if (counter == 304)
    {
        data[3] = 5;
        data[4] = 3;
    }
    else if (counter == 320)
    {
        data[3] = 4;
        data[4] = 2;
    }

    if (data[2] % data[3] == 0)
    {
        sprite->pos2.x--;
        gSprites[data[0]].pos2.x--;
    }
    if (data[2] % data[4] == 0)
    {
        sprite->pos2.y++;
        gSprites[data[0]].pos2.y++;
    }

    data[2]++;
}

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
    LZDecompressWram(gRaySceneCharges_Rayquaza2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneCharges_Rayquaza_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneCharges_Streaks_Tilemap, sRayScene->tilemapBuffers[2]);
    LZDecompressWram(gRaySceneCharges_Bg_Tilemap, sRayScene->tilemapBuffers[3]);
    LoadCompressedPalette(gRaySceneCharges_Bg_Pal, 0, 0x80);
}

static void Task_RayChargesAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChargesSceneBgs();
    LoadChargesSceneGfx();
    sub_81D68C8();
    BlendPalettes(-1, 0x10, 0);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    data[0] = 0;
    data[1] = 0;
    data[2] = CreateTask(sub_81D8AD8, 0);
    gTasks[taskId].func = Task_HandleRayCharges;
}

static void Task_HandleRayCharges(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    sub_81D8BB4();
    if ((data[3] & 7) == 0 && data[0] <= 1 && data[1] <= 89)
        PlaySE(SE_OP_BASYU);

    data[3]++;
    switch (data[0])
    {
    case 0:
        if (data[1] == 8)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
        }
        break;
    case 1:
        if (data[1] == 127)
        {
            data[1] = 0;
            data[0]++;
            gTasks[data[2]].func = sub_81D8B2C;
        }
        else
        {
            data[1]++;
        }
        break;
    case 2:
        if (data[1] == 12)
        {
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChargesEnd;
        break;
    }
}

// These two, BG scrolling for Rayquaza charge
static void sub_81D8AD8(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((data[15] & 3) == 0)
    {
        ChangeBgX(1, (Random() % 8 - 4) << 8, 0);
        ChangeBgY(1, (Random() % 8 - 4) << 8, 0);
    }

    data[15]++;
}

static void sub_81D8B2C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        data[0]++;
        data[1] = 10;
        data[2] = -1;
    }
    else if (data[0] == 1)
    {
        ChangeBgX(1, data[1] << 8, 2);
        ChangeBgY(1, data[1] << 8, 1);
        data[1] += data[2];
        if (data[1] == -10)
            data[2] *= -1;
    }
}

static void sub_81D8BB4(void)
{
    ChangeBgX(2, 0x400, 2);
    ChangeBgY(2, 0x400, 1);
    ChangeBgX(0, 0x800, 2);
    ChangeBgY(0, 0x800, 1);
}

static void Task_RayChargesEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    sub_81D8BB4();
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        sub_81D6904();
        DestroyTask(data[2]);
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

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
    DecompressAndCopyTileDataToVram(0, gRaySceneChasesAway_Bg_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;

    LZDecompressWram(gRaySceneChasesAway_Ring_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneChasesAway_Bg_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneChasesAway_Ring_Map, sRayScene->tilemapBuffers[2]);
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

static void Task_RayChasesAwayAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChasesAwaySceneBgs();
    LoadChasesAwaySceneGfx();
    sub_81D68C8();
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 14));
    BlendPalettes(-1, 0x10, 0);
    SetVBlankCallback(VBlankCB_RayquazaScene);
    data[0] = 0;
    data[1] = 0;
    gTasks[taskId].func = Task_HandleRayChasesAway;
    data[2] = CreateTask(sub_81D8FB0, 0);
    gTasks[data[2]].data[0] = 0;
    gTasks[data[2]].data[1] = 0;
    gTasks[data[2]].data[2] = 0;
    gTasks[data[2]].data[3] = 1;
    gTasks[data[2]].data[4] = 1;
}

static void Task_HandleRayChasesAway(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        if (data[1] == 8)
        {
            sub_81D90A8(taskId);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
        }
        break;
    case 1:
        if (gSprites[data[5]].callback == sub_81D97E0)
        {
            if (data[1] == 64)
            {
                sub_81D94D4(taskId);
                sub_81D93D8(taskId);
                data[1] = 0;
                data[0]++;
            }
            else
            {
                data[1]++;
            }
        }
        break;
    case 2:
        if (data[1] == 448)
        {
            data[1] = 0;
            data[0]++;
        }
        else
        {
            data[1]++;
            if (data[1] % 144 == 0)
            {
                BlendPalettesGradually(0x0000FFFE, 0, 16, 0, RGB_WHITEALPHA, 0, 0);
                BlendPalettesGradually(0xFFFF0000, 0, 16, 0, RGB_BLACK,      0, 1);
            }
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 4, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChasesAwayEnd;
        break;
    }
}

static void sub_81D8FB0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((data[0] & 0xF) == 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, ((data[1] + 14) << 8 & 0x1F00) | ((data[2] + 9) & 0xF));
        data[1] -= data[3];
        data[2] += data[4];
        if (data[1] == -3 || data[1] == 0)
            data[3] *= -1;
        if (data[2] == 3 || data[2] == 0)
            data[4] *= -1;
    }

    data[0]++;
}

static void Task_RayChasesAwayEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        StopMapMusic();
        if (data[1] == 0)
        {
            SetVBlankCallback(NULL);
            sub_81D6904();
            ResetSpriteData();
            FreeAllSpritePalettes();
            DestroyTask(data[2]);
        }

        if (data[1] == 32)
        {
            data[1] = 0;
            gTasks[taskId].func = Task_SetNextAnim;
        }
        else
        {
            data[1]++;
        }
    }
}

static void sub_81D90A8(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;

    taskData[3] = CreateSprite(&sSpriteTemplate_ChasesAway_Groudon, 64, 120, 0);
    spriteData = gSprites[taskData[3]].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_GroudonTail, 16, 130, 0);
    gSprites[taskData[3]].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;

    taskData[4] = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 160, 128, 1);
    spriteData = gSprites[taskData[4]].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 192, 128, 1);
    spriteData[1] = CreateSprite(&sSpriteTemplate_ChasesAway_Kyogre, 224, 128, 1);
    gSprites[taskData[4]].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
    gSprites[spriteData[1]].oam.priority = 1;
    StartSpriteAnim(&gSprites[spriteData[0]], 1);
    StartSpriteAnim(&gSprites[spriteData[1]], 2);

    taskData[5] = CreateSprite(&sSpriteTemplate_ChasesAway_Rayquaza, 120, -65, 0);
    spriteData = gSprites[taskData[5]].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_RayquazaTail, 120, -113, 0);
    gSprites[taskData[5]].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
}

static void sub_81D9274(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;

    gSprites[taskData[3]].callback = sub_81D9338;
    gSprites[taskData[3]].data[4] = 0;
    gSprites[taskData[3]].data[5] = 0;
    gSprites[taskData[3]].data[6] = 4;
    gSprites[taskData[3]].data[7] = 0;

    gSprites[taskData[4]].callback = sub_81D9338;
    gSprites[taskData[4]].data[4] = 0;
    gSprites[taskData[4]].data[5] = 0;
    gSprites[taskData[4]].data[6] = 4;
    gSprites[taskData[4]].data[7] = 1;
}

static void sub_81D9338(struct Sprite *sprite)
{
    if ((sprite->data[4] & 7) == 0)
    {
        if (sprite->data[7] == 0)
        {
            sprite->pos1.x -= sprite->data[6];
            gSprites[sprite->data[0]].pos1.x -= sprite->data[6];
        }
        else
        {
            sprite->pos1.x += sprite->data[6];
            gSprites[sprite->data[0]].pos1.x += sprite->data[6];
            gSprites[sprite->data[1]].pos1.x += sprite->data[6];
        }

        sprite->data[5]++;
        sprite->data[6] -= sprite->data[5];
        if (sprite->data[5] == 3)
        {
            sprite->data[4] = 0;
            sprite->data[5] = 0;
            sprite->data[6] = 0;
            sprite->callback = SpriteCallbackDummy;
            return;
        }
    }

    sprite->data[4]++;
}

static void sub_81D93D8(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    gSprites[taskData[3]].callback = sub_81D9420;
    StartSpriteAnim(&gSprites[taskData[3]], 1);
}

static void sub_81D9420(struct Sprite *sprite)
{
    switch (sprite->animCmdIndex)
    {
    case 0:
    case 2:
        if (sprite->animDelayCounter % 12 == 0)
        {
            sprite->pos1.x -= 2;
            gSprites[sprite->data[0]].pos1.x -=2;
        }
        gSprites[sprite->data[0]].pos2.y = 0;
        break;
    case 1:
    case 3:
        gSprites[sprite->data[0]].pos2.y = -2;
        if ((sprite->animDelayCounter & 15) == 0)
        {
            sprite->pos1.y++;
            gSprites[sprite->data[0]].pos1.y++;
        }
        break;
    }
}

static void sub_81D94D4(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;
    spriteData = gSprites[taskData[4]].data;

    gSprites[taskData[4]].callback = sub_81D9528;
    gSprites[spriteData[0]].callback = sub_81D9528;
    gSprites[spriteData[1]].callback = sub_81D9528;
}

static void sub_81D9528(struct Sprite *sprite)
{
    if ((sprite->data[4] & 3) == 0)
    {
        if (sprite->pos2.x == 1)
            sprite->pos2.x = -1;
        else
            sprite->pos2.x = 1;
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
        if (sprite->pos2.y != 32)
        {
            sprite->data[6]++;
            sprite->pos2.y = sprite->data[6] >> 4;
        }
    }
    else
    {
        sprite->data[5]++;
    }

    if (sprite->data[4] % 64 == 0)
        PlaySE(SE_W250);

    sprite->data[4]++;
}

static void SpriteCB_ChasesAway_Rayquaza(struct Sprite *sprite)
{
    s16 counter = sprite->data[7];
    if (counter <= 64)
    {
        sprite->pos2.y += 2;
        gSprites[sprite->data[0]].pos2.y += 2;
        if (sprite->data[7] == 64)
        {
            sub_81D9868(sprite, 1, 0, -48);
            sprite->data[4] = 5;
            sprite->data[5] = -1;
            gSprites[sprite->data[0]].data[4] = 3;
            gSprites[sprite->data[0]].data[5] = 5;
        }
    }
    else if (counter <= 111)
    {
        sub_81D97E0(sprite);
        if (sprite->data[4] == 0)
            PlaySE(SE_BT_START);
        if (sprite->data[4] == -3)
            sub_81D9868(sprite, 2, 48, 16);
    }
    else if (counter == 112)
    {
        gSprites[sprite->data[0]].data[4] = 7;
        gSprites[sprite->data[0]].data[5] = 3;
        sub_81D97E0(sprite);
    }
    else if (counter <= 327)
    {
        sub_81D97E0(sprite);
    }
    else if (counter == 328)
    {
        sub_81D97E0(sprite);
        sub_81D9868(sprite, 3, 48, 16);
        sprite->pos2.x = 1;
        gSprites[sprite->data[0]].pos2.x = 1;
        PlayCry1(SPECIES_RAYQUAZA, 0);
        CreateTask(sub_81D98B4, 0);
    }
    else
    {
        switch (counter)
        {
        case 376:
            sprite->pos2.x = 0;
            gSprites[sprite->data[0]].pos2.x = 0;
            sub_81D97E0(sprite);
            sub_81D9868(sprite, 2, 48, 16);
            sprite->callback = sub_81D97E0;
            return;
        case 352:
            sub_81D9274(FindTaskIdByFunc(Task_HandleRayChasesAway));
            break;
        }
    }

    if (sprite->data[7] > 328 && (sprite->data[7] & 1) == 0)
    {
        sprite->pos2.x *= -1;
        gSprites[sprite->data[0]].pos2.x = sprite->pos2.x;
    }

    sprite->data[7]++;
}

static void sub_81D97E0(struct Sprite *sprite)
{
    struct Sprite *sprite2 = &gSprites[sprite->data[0]];
    if (!(sprite->data[6] & sprite2->data[4]))
    {
        sprite->pos2.y += sprite->data[4];
        gSprites[sprite->data[0]].pos2.y += sprite->data[4];
        sprite->data[4] += sprite->data[5];
        if (sprite->data[4] >= sprite2->data[5] || sprite->data[4] <= -sprite2->data[5])
        {
            if (sprite->data[4] > sprite2->data[5])
                sprite->data[4] = sprite2->data[5];
            else if (sprite->data[4] < -sprite2->data[5])
                sprite->data[4] = -sprite2->data[5];

            sprite->data[5] *= -1;
        }
    }

    sprite->data[6]++;
}

static void sub_81D9868(struct Sprite *sprite, u8 animNum, s16 x, s16 y)
{
    struct Sprite *sprite2 = &gSprites[sprite->data[0]];

    sprite2->pos1.x = sprite->pos1.x + x;
    sprite2->pos1.y = sprite->pos1.y + y;

    sprite2->pos2.x = sprite->pos2.x;
    sprite2->pos2.y = sprite->pos2.y;

    StartSpriteAnim(sprite, animNum);
    StartSpriteAnim(sprite2, animNum);
}

static void sub_81D98B4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        SetBgAffine(2, 0x4000, 0x4000, 0x78, 0x40, 0x100, 0x100, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        data[4] = 16;
        data[0]++;
        break;
    case 1:
        if (data[5] == 8)
            PlaySE(SE_JIDO_DOA);
        if (data[2] == 2)
        {
            data[0]++;
        }
        else
        {
            data[1] += data[4];
            data[5]++;
            if (data[3] % 3 == 0 && data[4] != 4)
                data[4] -= 2;

            data[3]++;
            SetBgAffine(2, 0x4000, 0x4000, 0x78, 0x40, 0x100 - data[1], 0x100 - data[1], 0);
            if (data[1] > 255)
            {
                data[1] = 0;
                data[3] = 0;
                data[5] = 0;
                data[4] = 16;
                data[2]++;
            }
        }
        break;
    case 2:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        DestroyTask(taskId);
        break;
    }
}

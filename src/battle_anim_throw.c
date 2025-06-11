#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "palette.h"
#include "pokeball.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "data.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/rgb.h"

// iwram
COMMON_DATA u32 gMonShrinkDuration = 0;
COMMON_DATA u16 gMonShrinkDelta = 0;
COMMON_DATA u16 gMonShrinkDistance = 0;

enum {
    BALL_ROLL_1,
    BALL_PIVOT_1,
    BALL_ROLL_2,
    BALL_PIVOT_2,
    BALL_ROLL_3,
    BALL_NEXT_MOVE,
    BALL_WAIT_NEXT_SHAKE
};

enum {
    MON_SHRINK,
    MON_SHRINK_STEP,
    MON_SHRINK_INVISIBLE,
    MON_SHRINK_FREE
};

enum {
    SHINY_STAR_ENCIRCLE,
    SHINY_STAR_DIAGONAL,
};

static void AnimTask_UnusedLevelUpHealthBox_Step(u8);
static void AnimTask_FlashHealthboxOnLevelUp_Step(u8);
static void AnimTask_ThrowBall_Step(u8);
static void SpriteCB_Ball_Throw(struct Sprite *);
static void AnimTask_ThrowBall_StandingTrainer_Step(u8);
static void Task_PlayerThrow_Wait(u8);
static void SpriteCB_Ball_Arc(struct Sprite *);
static void SpriteCB_Ball_Block(struct Sprite *);
static void SpriteCB_Ball_MonShrink(struct Sprite *);
static void SpriteCB_Ball_MonShrink_Step(struct Sprite *);
static void SpriteCB_Ball_Bounce(struct Sprite *);
static void SpriteCB_Ball_Bounce_Step(struct Sprite *);
static void SpriteCB_Ball_Release(struct Sprite *);
static void SpriteCB_Ball_Wobble(struct Sprite *);
static void SpriteCB_Ball_Wobble_Step(struct Sprite *);
static void SpriteCB_Ball_Capture(struct Sprite *);
static void SpriteCB_Ball_Release_Step(struct Sprite *);
static void SpriteCB_Ball_Capture_Step(struct Sprite *);
static void MakeCaptureStars(struct Sprite *);
static void SpriteCB_Ball_FadeOut(struct Sprite *);
static void DestroySpriteAfterOneFrame(struct Sprite *);
static void LoadBallParticleGfx(u8);
static void SpriteCB_CaptureStar_Flicker(struct Sprite *);
static void SpriteCB_Ball_Release_Wait(struct Sprite *);
static void SpriteCB_Ball_Block_Step(struct Sprite *);
static void PokeBallOpenParticleAnimation_Step1(struct Sprite *);
static void PokeBallOpenParticleAnimation_Step2(struct Sprite *);
static void DestroyBallOpenAnimationParticle(struct Sprite *);
static void FanOutBallOpenParticles_Step1(struct Sprite *);
static void RepeatBallOpenParticleAnimation_Step1(struct Sprite *);
static void PremierBallOpenParticleAnimation_Step1(struct Sprite *);
static void Task_FadeMon_ToBallColor(u8);
static void Task_FadeMon_ToNormal(u8);
static void Task_FadeMon_ToNormal_Step(u8);
static void Task_ShinyStars(u8);
static void SpriteCB_ShinyStars_Encircle(struct Sprite *);
static void SpriteCB_ShinyStars_Diagonal(struct Sprite *);
static void Task_ShinyStars_Wait(u8);
static void SpriteCB_PokeBlock_LiftArm(struct Sprite *);
static void SpriteCB_PokeBlock_Arc(struct Sprite *);
static void SpriteCB_ThrowPokeBlock_Free(struct Sprite *);
static void PokeBallOpenParticleAnimation(u8);
static void GreatBallOpenParticleAnimation(u8);
static void SafariBallOpenParticleAnimation(u8);
static void UltraBallOpenParticleAnimation(u8);
static void MasterBallOpenParticleAnimation(u8);
static void DiveBallOpenParticleAnimation(u8);
static void RepeatBallOpenParticleAnimation(u8);
static void TimerBallOpenParticleAnimation(u8);
static void PremierBallOpenParticleAnimation(u8);
static void SpriteCB_PokeBlock_Throw(struct Sprite *);

struct CaptureStar
{
    s8 xOffset;
    s8 yOffset;
    s8 amplitude;
};

static const struct CaptureStar sCaptureStars[] =
{
    {
        .xOffset = 10,
        .yOffset = 2,
        .amplitude = -3,
    },
    {
        .xOffset = 15,
        .yOffset = 0,
        .amplitude = -4,
    },
    {
        .xOffset = -10,
        .yOffset = 2,
        .amplitude = -4,
    },
};

#define TAG_PARTICLES_POKEBALL    55020
#define TAG_PARTICLES_GREATBALL   55021
#define TAG_PARTICLES_SAFARIBALL  55022
#define TAG_PARTICLES_ULTRABALL   55023
#define TAG_PARTICLES_MASTERBALL  55024
#define TAG_PARTICLES_NETBALL     55025
#define TAG_PARTICLES_DIVEBALL    55026
#define TAG_PARTICLES_NESTBALL    55027
#define TAG_PARTICLES_REPEATBALL  55028
#define TAG_PARTICLES_TIMERBALL   55029
#define TAG_PARTICLES_LUXURYBALL  55030
#define TAG_PARTICLES_PREMIERBALL 55031

static const struct CompressedSpriteSheet sBallParticleSpriteSheets[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_MASTERBALL},
    [BALL_NET]     = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NETBALL},
    [BALL_DIVE]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_PREMIERBALL},
};

static const struct CompressedSpritePalette sBallParticlePalettes[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_MASTERBALL},
    [BALL_NET]     = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NETBALL},
    [BALL_DIVE]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_PREMIERBALL},
};

static const union AnimCmd sAnim_RegularBall[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MasterBall[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NetDiveBall[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NestBall[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LuxuryPremierBall[] =
{
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_UltraRepeatTimerBall[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_BallParticles[] =
{
    sAnim_RegularBall,
    sAnim_MasterBall,
    sAnim_NetDiveBall,
    sAnim_NestBall,
    sAnim_LuxuryPremierBall,
    sAnim_UltraRepeatTimerBall,
};

static const u8 sBallParticleAnimNums[POKEBALL_COUNT] =
{
    [BALL_POKE]    = 0,
    [BALL_GREAT]   = 0,
    [BALL_SAFARI]  = 0,
    [BALL_ULTRA]   = 5,
    [BALL_MASTER]  = 1,
    [BALL_NET]     = 2,
    [BALL_DIVE]    = 2,
    [BALL_NEST]    = 3,
    [BALL_REPEAT]  = 5,
    [BALL_TIMER]   = 5,
    [BALL_LUXURY]  = 4,
    [BALL_PREMIER] = 4,
};

static const TaskFunc sBallParticleAnimationFuncs[POKEBALL_COUNT] =
{
    [BALL_POKE]    = PokeBallOpenParticleAnimation,
    [BALL_GREAT]   = GreatBallOpenParticleAnimation,
    [BALL_SAFARI]  = SafariBallOpenParticleAnimation,
    [BALL_ULTRA]   = UltraBallOpenParticleAnimation,
    [BALL_MASTER]  = MasterBallOpenParticleAnimation,
    [BALL_NET]     = SafariBallOpenParticleAnimation,
    [BALL_DIVE]    = DiveBallOpenParticleAnimation,
    [BALL_NEST]    = UltraBallOpenParticleAnimation,
    [BALL_REPEAT]  = RepeatBallOpenParticleAnimation,
    [BALL_TIMER]   = TimerBallOpenParticleAnimation,
    [BALL_LUXURY]  = GreatBallOpenParticleAnimation,
    [BALL_PREMIER] = PremierBallOpenParticleAnimation,
};

static const struct SpriteTemplate sBallParticleSpriteTemplates[POKEBALL_COUNT] =
{
    [BALL_POKE] = {
        .tileTag = TAG_PARTICLES_POKEBALL,
        .paletteTag = TAG_PARTICLES_POKEBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_GREAT] = {
        .tileTag = TAG_PARTICLES_GREATBALL,
        .paletteTag = TAG_PARTICLES_GREATBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_SAFARI] = {
        .tileTag = TAG_PARTICLES_SAFARIBALL,
        .paletteTag = TAG_PARTICLES_SAFARIBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_ULTRA] = {
        .tileTag = TAG_PARTICLES_ULTRABALL,
        .paletteTag = TAG_PARTICLES_ULTRABALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_MASTER] = {
        .tileTag = TAG_PARTICLES_MASTERBALL,
        .paletteTag = TAG_PARTICLES_MASTERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_NET] = {
        .tileTag = TAG_PARTICLES_NETBALL,
        .paletteTag = TAG_PARTICLES_NETBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_DIVE] = {
        .tileTag = TAG_PARTICLES_DIVEBALL,
        .paletteTag = TAG_PARTICLES_DIVEBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_NEST] = {
        .tileTag = TAG_PARTICLES_NESTBALL,
        .paletteTag = TAG_PARTICLES_NESTBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_REPEAT] = {
        .tileTag = TAG_PARTICLES_REPEATBALL,
        .paletteTag = TAG_PARTICLES_REPEATBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_TIMER] = {
        .tileTag = TAG_PARTICLES_TIMERBALL,
        .paletteTag = TAG_PARTICLES_TIMERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_LUXURY] = {
        .tileTag = TAG_PARTICLES_LUXURYBALL,
        .paletteTag = TAG_PARTICLES_LUXURYBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_PREMIER] = {
        .tileTag = TAG_PARTICLES_PREMIERBALL,
        .paletteTag = TAG_PARTICLES_PREMIERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

const u16 gBallOpenFadeColors[] =
{
    [BALL_POKE] = RGB(31, 22, 30),
    [BALL_GREAT] = RGB(16, 23, 30),
    [BALL_SAFARI] = RGB(23, 30, 20),
    [BALL_ULTRA] = RGB(31, 31, 15),
    [BALL_MASTER] = RGB(23, 20, 28),
    [BALL_NET] = RGB(21, 31, 25),
    [BALL_DIVE] = RGB(12, 25, 30),
    [BALL_NEST] = RGB(30, 27, 10),
    [BALL_REPEAT] = RGB(31, 24, 16),
    [BALL_TIMER] = RGB(29, 30, 30),
    [BALL_LUXURY] = RGB(31, 17, 10),
    [BALL_PREMIER] = RGB(31, 9, 10),

    // Garbage data
    RGB_BLACK,
    RGB(1, 16, 0),
    RGB(3, 0, 1),
    RGB(1, 8, 0),
    RGB(0, 8, 0),
    RGB(3, 8, 1),
    RGB(6, 8, 1),
    RGB(4, 0, 0),
};

const struct SpriteTemplate gPokeblockSpriteTemplate =
{
    .tileTag = ANIM_TAG_POKEBLOCK,
    .paletteTag = ANIM_TAG_POKEBLOCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeBlock_Throw,
};

static const union AnimCmd sAnim_SafariRock[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_SafariRock[] = {
    sAnim_SafariRock,
};

// Unused, leftover from FRLG
static const struct SpriteTemplate sSafariRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SafariRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeBlock_Throw,
};

extern const struct SpriteTemplate gWishStarSpriteTemplate;
extern const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate;

// This is an unused function, but it seems likely that it was
// intended to be an additional effect during the level-up animation.
// It is an upward blue gradient effect on the mon's healthbox.
void AnimTask_UnusedLevelUpHealthBox(u8 taskId)
{
    struct BattleAnimBgData animBgData;
    u8 healthBoxSpriteId;
    u8 battler;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;

    battler = gBattleAnimAttacker;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 0);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
    SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 1);
    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    spriteId3 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    spriteId4 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    gSprites[healthBoxSpriteId].oam.priority = 1;
    gSprites[spriteId1].oam.priority = 1;
    gSprites[spriteId2].oam.priority = 1;
    gSprites[spriteId3] = gSprites[healthBoxSpriteId];
    gSprites[spriteId4] = gSprites[spriteId1];
    gSprites[spriteId3].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId4].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId3].callback = SpriteCallbackDummy;
    gSprites[spriteId4].callback = SpriteCallbackDummy;

    GetBattleAnimBg1Data(&animBgData);
    AnimLoadCompressedBgTilemap(animBgData.bgId, UnusedLevelupAnimationTilemap);
    AnimLoadCompressedBgGfx(animBgData.bgId, UnusedLevelupAnimationGfx, animBgData.tilesOffset);
    LoadCompressedPalette(gCureBubblesPal, BG_PLTT_ID(animBgData.paletteId), PLTT_SIZE_4BPP);

    gBattle_BG1_X = -gSprites[spriteId3].x + 32;
    gBattle_BG1_Y = -gSprites[spriteId3].y - 32;
    gTasks[taskId].data[1] = 640;
    gTasks[taskId].data[0] = spriteId3;
    gTasks[taskId].data[2] = spriteId4;
    gTasks[taskId].func = AnimTask_UnusedLevelUpHealthBox_Step;
}

static void AnimTask_UnusedLevelUpHealthBox_Step(u8 taskId)
{
    u8 spriteId1, spriteId2;
    u8 battler;

    battler = gBattleAnimAttacker;
    gTasks[taskId].data[13] += gTasks[taskId].data[1];
    gBattle_BG1_Y += (u16)gTasks[taskId].data[13] >> 8;
    gTasks[taskId].data[13] &= 0xFF;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 8)
                gTasks[taskId].data[15]++;
        }
        break;
    case 1:
        if (++gTasks[taskId].data[10] == 30)
            gTasks[taskId].data[15]++;
        break;
    case 2:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 0)
            {
                ResetBattleAnimBg(FALSE);
                gBattle_WIN0H = 0;
                gBattle_WIN0V = 0;
                SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
                SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
                if (!IsContest())
                    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

                SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
                DestroySprite(&gSprites[gTasks[taskId].data[0]]);
                DestroySprite(&gSprites[gTasks[taskId].data[2]]);
                SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);
                spriteId1 = gSprites[gHealthboxSpriteIds[battler]].oam.affineParam;
                spriteId2 = gSprites[gHealthboxSpriteIds[battler]].data[5];
                gSprites[gHealthboxSpriteIds[battler]].oam.priority = 1;
                gSprites[spriteId1].oam.priority = 1;
                gSprites[spriteId2].oam.priority = 1;
                DestroyAnimVisualTask(taskId);
            }
        }
        break;
    }
}

static void LoadHealthboxPalsForLevelUp(u8 *paletteId1, u8 *paletteId2, u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1, spriteId2;
    u16 offset1, offset2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    *paletteId1 = AllocSpritePalette(TAG_HEALTHBOX_PALS_1);
    *paletteId2 = AllocSpritePalette(TAG_HEALTHBOX_PALS_2);

    offset1 = OBJ_PLTT_ID(gSprites[healthBoxSpriteId].oam.paletteNum);
    offset2 = OBJ_PLTT_ID(gSprites[spriteId2].oam.paletteNum);
    LoadPalette(&gPlttBufferUnfaded[offset1], OBJ_PLTT_ID(*paletteId1), PLTT_SIZE_4BPP);
    LoadPalette(&gPlttBufferUnfaded[offset2], OBJ_PLTT_ID(*paletteId2), PLTT_SIZE_4BPP);

    gSprites[healthBoxSpriteId].oam.paletteNum = *paletteId1;
    gSprites[spriteId1].oam.paletteNum = *paletteId1;
    gSprites[spriteId2].oam.paletteNum = *paletteId2;
}

void AnimTask_LoadHealthboxPalsForLevelUp(u8 taskId)
{
    u8 paletteId1, paletteId2;
    LoadHealthboxPalsForLevelUp(&paletteId1, &paletteId2, gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

static void FreeHealthboxPalsForLevelUp(u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1, spriteId2;
    u8 paletteId1, paletteId2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];

    FreeSpritePaletteByTag(TAG_HEALTHBOX_PALS_1);
    FreeSpritePaletteByTag(TAG_HEALTHBOX_PALS_2);
    paletteId1 = IndexOfSpritePaletteTag(TAG_HEALTHBOX_PAL);
    paletteId2 = IndexOfSpritePaletteTag(TAG_HEALTHBAR_PAL);
    gSprites[healthBoxSpriteId].oam.paletteNum = paletteId1;
    gSprites[spriteId1].oam.paletteNum = paletteId1;
    gSprites[spriteId2].oam.paletteNum = paletteId2;
}

void AnimTask_FreeHealthboxPalsForLevelUp(u8 taskId)
{
    FreeHealthboxPalsForLevelUp(gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FlashHealthboxOnLevelUp(u8 taskId)
{
    gTasks[taskId].data[10] = gBattleAnimArgs[0];
    gTasks[taskId].data[11] = gBattleAnimArgs[1];
    gTasks[taskId].func = AnimTask_FlashHealthboxOnLevelUp_Step;
}

static void AnimTask_FlashHealthboxOnLevelUp_Step(u8 taskId)
{
    u8 paletteNum;
    u32 paletteOffset, colorOffset;

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0]++ >= gTasks[taskId].data[11])
    {
        gTasks[taskId].data[0] = 0;
        paletteNum = IndexOfSpritePaletteTag(TAG_HEALTHBOX_PALS_1);
        colorOffset = gTasks[taskId].data[10] == 0 ? 6 : 2;
        switch (gTasks[taskId].data[1])
        {
        case 0:
            gTasks[taskId].data[2] += 2;
            if (gTasks[taskId].data[2] > 16)
                gTasks[taskId].data[2] = 16;

            paletteOffset = OBJ_PLTT_ID(paletteNum);
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 16)
                gTasks[taskId].data[1]++;
            break;
        case 1:
            gTasks[taskId].data[2] -= 2;
            if (gTasks[taskId].data[2] < 0)
                gTasks[taskId].data[2] = 0;

            paletteOffset = OBJ_PLTT_ID(paletteNum);
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 0)
                DestroyAnimVisualTask(taskId);
            break;
        }
    }
}

void AnimTask_SwitchOutShrinkMon(u8 taskId)
{
    u8 spriteId;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[10] = 0x100;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 0x30;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        SetBattlerSpriteYOffsetFromYScale(spriteId);
        if (gTasks[taskId].data[10] >= 0x2D0)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        ResetSpriteRotScale(spriteId);
        gSprites[spriteId].invisible = TRUE;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_SwitchOutBallEffect(u8 taskId)
{
    u8 spriteId;
    u16 ball;
    u8 ballId;
    u8 x, y;
    u8 priority, subpriority;
    u32 selectedPalettes;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        ball = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);
    else
        ball = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(ball);
    switch (gTasks[taskId].data[0])
    {
    case 0:
        x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
        priority = gSprites[spriteId].oam.priority;
        subpriority = gSprites[spriteId].subpriority;
        gTasks[taskId].data[10] = AnimateBallOpenParticles(x, y + 32, priority, subpriority, ballId);
        selectedPalettes = GetBattlePalettesMask(TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
        gTasks[taskId].data[11] = LaunchBallFadeMonTask(FALSE, gBattleAnimAttacker, selectedPalettes, ballId);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gTasks[gTasks[taskId].data[10]].isActive && !gTasks[gTasks[taskId].data[11]].isActive)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_LoadBallGfx(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);
    LoadBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreeBallGfx(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);
    FreeBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_IsBallBlockedByTrainer(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        gBattleAnimArgs[ARG_RET_ID] = -1;
    else
        gBattleAnimArgs[ARG_RET_ID] = 0;

    DestroyAnimVisualTask(taskId);
}

u8 ItemIdToBallId(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_MASTER_BALL:
        return BALL_MASTER;
    case ITEM_ULTRA_BALL:
        return BALL_ULTRA;
    case ITEM_GREAT_BALL:
        return BALL_GREAT;
    case ITEM_SAFARI_BALL:
        return BALL_SAFARI;
    case ITEM_NET_BALL:
        return BALL_NET;
    case ITEM_DIVE_BALL:
        return BALL_DIVE;
    case ITEM_NEST_BALL:
        return BALL_NEST;
    case ITEM_REPEAT_BALL:
        return BALL_REPEAT;
    case ITEM_TIMER_BALL:
        return BALL_TIMER;
    case ITEM_LUXURY_BALL:
        return BALL_LUXURY;
    case ITEM_PREMIER_BALL:
        return BALL_PREMIER;
    case ITEM_POKE_BALL:
    default:
        return BALL_POKE;
    }
}

#define tSpriteId data[0]

#define sDuration data[0]
#define sTargetX  data[1]
#define sTargetY  data[2]

void AnimTask_ThrowBall(u8 taskId)
{
    u8 ballId;
    u8 spriteId;

    ballId = ItemIdToBallId(gLastUsedItem);
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[spriteId].sDuration = 34;
    gSprites[spriteId].sTargetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    gSprites[spriteId].sTargetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) - 16;
    gSprites[spriteId].callback = SpriteCB_Ball_Throw;
    gBattleSpritesDataPtr->animationData->wildMonInvisible = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible;
    gTasks[taskId].tSpriteId = spriteId;
    gTasks[taskId].func = AnimTask_ThrowBall_Step;
}

static void AnimTask_ThrowBall_Step(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tSpriteId;
    if ((u16)gSprites[spriteId].sDuration == 0xFFFF)
        DestroyAnimVisualTask(taskId);
}

// Safari Zone throw / Wally's throw
void AnimTask_ThrowBall_StandingTrainer(u8 taskId)
{
    s16 x, y;
    u8 ballId;
    u8 subpriority;
    u8 spriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        x = 32;
        y = 11;
    }
    else
    {
        x = 23;
        y = 5;
    }

    ballId = ItemIdToBallId(gLastUsedItem);
    subpriority = GetBattlerSpriteSubpriority(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)) + 1;
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], x + 32, y | 80, subpriority);
    gSprites[spriteId].sDuration = 34;
    gSprites[spriteId].sTargetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    gSprites[spriteId].sTargetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) - 16;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].callback = SpriteCB_TrainerThrowObject;
    gTasks[taskId].tSpriteId = spriteId;
    gTasks[taskId].func = AnimTask_ThrowBall_StandingTrainer_Step;
}

static void AnimTask_ThrowBall_StandingTrainer_Step(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animCmdIndex == 1)
    {
        PlaySE12WithPanning(SE_BALL_THROW, 0);
        gSprites[gTasks[taskId].tSpriteId].callback = SpriteCB_Ball_Throw;
        CreateTask(Task_PlayerThrow_Wait, 10);
        gTasks[taskId].func = AnimTask_ThrowBall_Step;
    }
}

#undef sDuration
#undef sTargetX
#undef sTargetY

#undef tSpriteId

static void Task_PlayerThrow_Wait(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animEnded)
    {
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]], 0);
        DestroyTask(taskId);
    }
}

#define sTargetXArg data[1]
#define sTargetYArg data[2]

#define sOffsetX   data[1] // re-use
#define sTargetX   data[2] // re-use
#define sOffsetY   data[3]
#define sTargetY   data[4]
#define sAmplitude data[5]

static void SpriteCB_Ball_Throw(struct Sprite *sprite)
{
    u16 targetX = sprite->sTargetXArg;
    u16 targetY = sprite->sTargetYArg;

    sprite->sOffsetX = sprite->x;
    sprite->sTargetX = targetX;
    sprite->sOffsetY = sprite->y;
    sprite->sTargetY = targetY;
    sprite->sAmplitude = -40;
    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_Ball_Arc;
}

#undef sTargetXArg
#undef sTargetYArg
#undef sOffsetX
#undef sTargetX
#undef sOffsetY
#undef sTargetY
#undef sAmplitude

#define sTimer  data[5]
#define sTaskId data[5] // re-use

static void SpriteCB_Ball_Arc(struct Sprite *sprite)
{
    s32 i;
    u8 ballId;

    if (TranslateAnimHorizontalArc(sprite))
    {
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        {
            sprite->callback = SpriteCB_Ball_Block;
        }
        else
        {
            StartSpriteAnim(sprite, 1);
            sprite->x += sprite->x2;
            sprite->y += sprite->y2;
            sprite->x2 = 0;
            sprite->y2 = 0;

            for (i = 0; i < 8; i++)
                sprite->data[i] = 0;

            sprite->sTimer = 0;
            sprite->callback = SpriteCB_Ball_MonShrink;

            ballId = ItemIdToBallId(gLastUsedItem);
            switch (ballId)
            {
            case 0 ... POKEBALL_COUNT - 1:
                AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
                LaunchBallFadeMonTask(FALSE, gBattleAnimTarget, 14, ballId);
                break;
            }
        }
    }
}

static void SpriteCB_Ball_MonShrink(struct Sprite *sprite)
{
    if (++sprite->sTimer == 10)
    {
        sprite->sTaskId = CreateTask(TaskDummy, 50);
        sprite->callback = SpriteCB_Ball_MonShrink_Step;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] = 0;
    }
}

#undef sTimer
#undef sTaskId

#define tState  data[0]
#define sTimer  data[1]
#define sTaskId data[5]

static void SpriteCB_Ball_MonShrink_Step(struct Sprite *sprite)
{
    u8 spriteId;
    u8 taskId;

    spriteId = gBattlerSpriteIds[gBattleAnimTarget];
    taskId = sprite->sTaskId;

    if (++gTasks[taskId].sTimer == 11)
        PlaySE(SE_BALL_TRADE);

    switch (gTasks[taskId].tState)
    {
    case MON_SHRINK:
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[10] = 256;
        gMonShrinkDuration = 28;
        gMonShrinkDistance = (gSprites[spriteId].y + gSprites[spriteId].y2) - (sprite->y + sprite->y2);
        gMonShrinkDelta = (u32)(gMonShrinkDistance * 256) / gMonShrinkDuration;
        gTasks[taskId].data[2] = gMonShrinkDelta;
        gTasks[taskId].tState++; // MON_SHRINK_STEP
        break;
    case MON_SHRINK_STEP:
        gTasks[taskId].data[10] += 32;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        gTasks[taskId].data[3] += gTasks[taskId].data[2];
        gSprites[spriteId].y2 = -gTasks[taskId].data[3] >> 8;
        if (gTasks[taskId].data[10] >= 1152)
            gTasks[taskId].tState++; // MON_SHRINK_INVISIBLE
        break;
    case MON_SHRINK_INVISIBLE:
        ResetSpriteRotScale(spriteId);
        gSprites[spriteId].invisible = TRUE;
        gTasks[taskId].tState++; // MON_SHRINK_FREE
        break;
    case MON_SHRINK_FREE:
    default:
        if (gTasks[taskId].data[1] > 10)
        {
            DestroyTask(taskId);
            StartSpriteAnim(sprite, 2);
            sprite->data[5] = 0;
            sprite->callback = SpriteCB_Ball_Bounce;
        }
        break;
    }
}

#undef sTimer
#undef tState
#undef sTaskId

#define sState     data[3]
#define sAmplitude data[4]
#define sPhase     data[5]

static void SpriteCB_Ball_Bounce(struct Sprite *sprite)
{
    s16 phase;

    if (sprite->animEnded)
    {
        sprite->sState = 0;
        sprite->sAmplitude = 40;
        sprite->sPhase = 0;
        phase = 0;
        sprite->y += Cos(phase, 40);
        sprite->y2 = -Cos(phase, sprite->sAmplitude);
        sprite->callback = SpriteCB_Ball_Bounce_Step;
    }
}

#undef sState
#undef sAmplitude
#undef sPhase

#define DIRECTION(state)   (state & 0xFF)
#define PHASE_DELTA(state) (state >> 8)
#define BOUNCES(state)     (state >> 8)
#define FALL(state)        (state &= -0x100)
#define RISE_FASTER(state) (state += 257)

#define BALL_FALLING 0
#define BALL_RISING  1

#define sState     data[3]
#define sAmplitude data[4]
#define sPhase     data[5]
#define sTimer     data[5] // re-use

// Animates the Poké Ball dropping to ground and bouncing.
static void SpriteCB_Ball_Bounce_Step(struct Sprite *sprite)
{
    bool8 lastBounce;
    s16 bounceCount;

    lastBounce = FALSE;

    switch (DIRECTION(sprite->sState))
    {
    case BALL_FALLING:
        sprite->y2 = -Cos(sprite->sPhase, sprite->sAmplitude);
        sprite->sPhase += PHASE_DELTA(sprite->sState) + 4;
        // Once the ball touches the ground
        if (sprite->sPhase >= 64)
        {
            sprite->sAmplitude -= 10;
            RISE_FASTER(sprite->sState);

            bounceCount = BOUNCES(sprite->sState);
            if (bounceCount == 4)
                lastBounce = TRUE;

            switch (bounceCount)
            {
            case 1:
                PlaySE(SE_BALL_BOUNCE_1);
                break;
            case 2:
                PlaySE(SE_BALL_BOUNCE_2);
                break;
            case 3:
                PlaySE(SE_BALL_BOUNCE_3);
                break;
            default:
                PlaySE(SE_BALL_BOUNCE_4);
                break;
            }
        }
        break;
    case BALL_RISING:
        sprite->y2 = -Cos(sprite->sPhase, sprite->sAmplitude);
        sprite->sPhase -= PHASE_DELTA(sprite->sState) + 4;
        // Once ball reaches max height
        if (sprite->sPhase <= 0)
        {
            // Set to BALL_FALLING
            sprite->sPhase = 0;
            FALL(sprite->sState);
        }
        break;
    }

    if (lastBounce)
    {
        sprite->sState = 0;
        sprite->y += Cos(64, 40);
        sprite->y2 = 0;
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_NO_SHAKES)
        {
            sprite->sTimer = 0;
            sprite->callback = SpriteCB_Ball_Release;
        }
        else
        {
            sprite->callback = SpriteCB_Ball_Wobble;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

#undef sState
#undef sAmplitude
#undef sPhase
#undef sTimer

#undef DIRECTION
#undef PHASE_DELTA
#undef BOUNCES
#undef FALL
#undef RISE_FASTER

#define sTimer data[3]
#define sState data[3] // re-use

static void SpriteCB_Ball_Wobble(struct Sprite *sprite)
{
    if (++sprite->sTimer == 31)
    {
        sprite->sState = 0;
        sprite->affineAnimPaused = TRUE;
        StartSpriteAffineAnim(sprite, BALL_ROTATE_RIGHT);
        gBattleSpritesDataPtr->animationData->ballSubpx = 0;
        sprite->callback = SpriteCB_Ball_Wobble_Step;
        PlaySE(SE_BALL);
    }
}

#undef sTimer
#undef sState

#define sState     data[3]
#define sDirection data[4]
#define sTimer     data[5]

#define STATE(state)       (state & 0xFF)
#define SHAKES(state)      (state >> 8)
#define SHAKE_INC(state)   (state += 0x100)
#define RESET_STATE(state) (state &= -0x100)

static void SpriteCB_Ball_Wobble_Step(struct Sprite *sprite)
{
    s8 shakes;
    u16 frame;

    switch (STATE(sprite->sState))
    {
    case BALL_ROLL_1:
        // Rolling effect: every frame in the rotation, the sprite shifts 176/256 of a pixel.
        if (gBattleSpritesDataPtr->animationData->ballSubpx > 255)
        {
            sprite->x2 += sprite->sDirection;
            gBattleSpritesDataPtr->animationData->ballSubpx &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->ballSubpx += 176;
        }

        sprite->sTimer++;
        sprite->affineAnimPaused = FALSE;
        frame = sprite->sTimer + 7;
        if (frame > 14)
        {
            gBattleSpritesDataPtr->animationData->ballSubpx = 0;
            sprite->sState++; // BALL_PIVOT_1
            sprite->sTimer = 0;
        }
        break;
    case BALL_PIVOT_1:
        if (++sprite->sTimer == 1)
        {
            sprite->sTimer = 0;
            sprite->sDirection = -sprite->sDirection;
            sprite->sState++; // BALL_ROLL_2
            sprite->affineAnimPaused = FALSE;
            if (sprite->sDirection < 0)
                ChangeSpriteAffineAnim(sprite, BALL_ROTATE_LEFT);
            else
                ChangeSpriteAffineAnim(sprite, BALL_ROTATE_RIGHT);
        }
        else
        {
            sprite->affineAnimPaused = TRUE;
        }
        break;
    case BALL_ROLL_2:
        if (gBattleSpritesDataPtr->animationData->ballSubpx > 255)
        {
            sprite->x2 += sprite->sDirection;
            gBattleSpritesDataPtr->animationData->ballSubpx &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->ballSubpx += 176;
        }

        sprite->sTimer++;
        sprite->affineAnimPaused = FALSE;
        frame = sprite->sTimer + 12;
        if (frame > 24)
        {
            gBattleSpritesDataPtr->animationData->ballSubpx = 0;
            sprite->sState++; // BALL_PIVOT_2
            sprite->sTimer = 0;
        }
        break;
    case BALL_PIVOT_2:
        if (sprite->sTimer++ < 0)
        {
            sprite->affineAnimPaused = TRUE;
            break;
        }

        sprite->sTimer = 0;
        sprite->sDirection = -sprite->sDirection;
        sprite->sState++; // BALL_ROLL_3
        sprite->affineAnimPaused = FALSE;
        if (sprite->sDirection < 0)
            ChangeSpriteAffineAnim(sprite, BALL_ROTATE_LEFT);
        else
            ChangeSpriteAffineAnim(sprite, BALL_ROTATE_RIGHT);
        // fall through
    case BALL_ROLL_3:
        if (gBattleSpritesDataPtr->animationData->ballSubpx > 0xFF)
        {
            sprite->x2 += sprite->sDirection;
            gBattleSpritesDataPtr->animationData->ballSubpx &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->ballSubpx += 176;
        }

        sprite->sTimer++;
        sprite->affineAnimPaused = FALSE;
        frame = sprite->sTimer + 4;
        if (frame > 8)
        {
            gBattleSpritesDataPtr->animationData->ballSubpx = 0;
            sprite->sState++; // BALL_NEXT_MOVE
            sprite->sTimer = 0;
            sprite->sDirection = -sprite->sDirection;
        }
        break;
    case BALL_NEXT_MOVE:
        SHAKE_INC(sprite->sState);
        shakes = SHAKES(sprite->sState);
        if (shakes == gBattleSpritesDataPtr->animationData->ballThrowCaseId)
        {
            sprite->affineAnimPaused = TRUE;
            sprite->callback = SpriteCB_Ball_Release;
        }
        else
        {
            if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_3_SHAKES_SUCCESS && shakes == 3)
            {
                sprite->callback = SpriteCB_Ball_Capture;
                sprite->affineAnimPaused = TRUE;
            }
            else
            {
                sprite->sState++; // BALL_WAIT_NEXT_SHAKE
                sprite->affineAnimPaused = TRUE;
            }
        }
        break;
    case BALL_WAIT_NEXT_SHAKE:
    default:
        if (++sprite->sTimer == 31)
        {
            sprite->sTimer = 0;
            RESET_STATE(sprite->sState);
            StartSpriteAffineAnim(sprite, 3);
            if (sprite->sDirection < 0)
                StartSpriteAffineAnim(sprite, BALL_ROTATE_LEFT);
            else
                StartSpriteAffineAnim(sprite, BALL_ROTATE_RIGHT);

            PlaySE(SE_BALL);
        }
        break;
    }
}

#undef STATE
#undef SHAKES
#undef SHAKE_INC
#undef RESET_STATE

#undef sState

#define sTimer data[5]

static void SpriteCB_Ball_Release(struct Sprite *sprite)
{
    if (++sprite->sTimer == 31)
    {
        sprite->data[5] = 0;
        sprite->callback = SpriteCB_Ball_Release_Step;
    }
}
#undef sTimer

#define sState data[0]
#define sTimer data[4]

static void SpriteCB_Ball_Capture(struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    sprite->callback = SpriteCB_Ball_Capture_Step;
    sprite->data[3] = 0;
    sprite->sTimer = 0;
    sprite->data[5] = 0;
}

// Fade and unfade ball, create star animations, play sound effects
static void SpriteCB_Ball_Capture_Step(struct Sprite *sprite)
{
    u8 *battler = &gBattleAnimTarget;

    sprite->sTimer++;
    if (sprite->sTimer == 40)
    {
        PlaySE(SE_RG_BALL_CLICK);
        BlendPalettes(0x10000 << sprite->oam.paletteNum, 6, RGB_BLACK);
        MakeCaptureStars(sprite);
    }
    else if (sprite->sTimer == 60)
    {
        BeginNormalPaletteFade(0x10000 << sprite->oam.paletteNum, 2, 6, 0, RGB_BLACK);
    }
    else if (sprite->sTimer == 95)
    {
        gDoingBattleAnim = FALSE;
        UpdateOamPriorityInAllHealthboxes(1);
        m4aMPlayAllStop();
        PlaySE(MUS_RG_CAUGHT_INTRO);
    }
    else if (sprite->sTimer == 315)
    {
        FreeOamMatrix(gSprites[gBattlerSpriteIds[*battler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[*battler]]);

        sprite->sState = 0;
        sprite->callback = SpriteCB_Ball_FadeOut;
    }
}

#undef sTimer
#undef sState

#define sState data[0]
#define sFrame data[0] // re-use

static void SpriteCB_Ball_FadeOut(struct Sprite *sprite)
{
    u8 paletteIndex;

    switch (sprite->sState)
    {
    case 0:
        sprite->data[1] = 0;
        sprite->data[2] = 0;
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        paletteIndex = IndexOfSpritePaletteTag(sprite->template->paletteTag);
        BeginNormalPaletteFade(1 << (paletteIndex + 0x10), 0, 0, 16, RGB_WHITE);
        sprite->sState++;
        break;
    case 1:
        if (sprite->data[1]++ > 0)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[2], sprite->data[2]));
            if (sprite->data[2] == 16)
                sprite->sState++;
        }
        break;
    case 2:
        sprite->invisible = TRUE;
        sprite->sState++;
        break;
    default:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);

            sprite->sFrame = 0;
            sprite->callback = DestroySpriteAfterOneFrame;
        }
        break;
    }
}

#undef sState
#undef sFrame

#define sFrame data[0]

static void DestroySpriteAfterOneFrame(struct Sprite *sprite)
{
    if (sprite->sFrame == 0)
    {
        sprite->sFrame = -1;
    }
    else
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}
#undef sFrame

#define sDuration  data[0]
#define sTargetX   data[2]
#define sTargetY   data[4]
#define sAmplitude data[5]

static void MakeCaptureStars(struct Sprite *sprite)
{
    u32 i;
    u8 subpriority;

    if (sprite->subpriority)
    {
        subpriority = sprite->subpriority - 1;
    }
    else
    {
        subpriority = 0;
        sprite->subpriority = 1;
    }

    LoadBallParticleGfx(BALL_MASTER);
    for (i = 0; i < ARRAY_COUNT(sCaptureStars); i++)
    {
        u8 spriteId = CreateSprite(&sBallParticleSpriteTemplates[BALL_MASTER], sprite->x, sprite->y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].sDuration = 24;
            gSprites[spriteId].sTargetX = sprite->x + sCaptureStars[i].xOffset;
            gSprites[spriteId].sTargetY = sprite->y + sCaptureStars[i].yOffset;
            gSprites[spriteId].sAmplitude = sCaptureStars[i].amplitude;
            InitAnimArcTranslation(&gSprites[spriteId]);
            gSprites[spriteId].callback = SpriteCB_CaptureStar_Flicker;
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[BALL_MASTER]);
        }
    }
}

#undef sDuration
#undef sTargetX
#undef sTargetY
#undef sAmplitude

static void SpriteCB_CaptureStar_Flicker(struct Sprite *sprite)
{
    sprite->invisible = !sprite->invisible;
    if (TranslateAnimHorizontalArc(sprite))
        DestroySprite(sprite);
}

#define sFrame   data[0]
#define sOffsetY data[1]

// Poké Ball didn't catch - starts:
// - Ball particle animations
// - Wild mon fade to normal color
// - Wild mon emerge from Poké Ball
static void SpriteCB_Ball_Release_Step(struct Sprite *sprite)
{
    u8 ballId;

    StartSpriteAnim(sprite, 1);
    StartSpriteAffineAnim(sprite, 0);
    sprite->callback = SpriteCB_Ball_Release_Wait;

    ballId = ItemIdToBallId(gLastUsedItem);
    switch (ballId)
    {
    case 0 ... POKEBALL_COUNT - 1:
        AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
        LaunchBallFadeMonTask(TRUE, gBattleAnimTarget, 14, ballId);
        break;
    }

    // Animate Pokémon emerging from Poké Ball
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = FALSE;
    StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], BATTLER_AFFINE_EMERGE);
    AnimateSprite(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]]);
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].sOffsetY = 4096;
}

static void SpriteCB_Ball_Release_Wait(struct Sprite *sprite)
{
    bool8 released = FALSE;

    if (sprite->animEnded)
        sprite->invisible = TRUE;

    if (gSprites[gBattlerSpriteIds[gBattleAnimTarget]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], BATTLER_AFFINE_NORMAL);
        released = TRUE;
    }
    else
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].sOffsetY -= 288;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].y2 = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].sOffsetY >> 8;
    }

    if (sprite->animEnded && released)
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].y2 = 0;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = gBattleSpritesDataPtr->animationData->wildMonInvisible;
        sprite->sFrame = 0;
        sprite->callback = DestroySpriteAfterOneFrame;
        gDoingBattleAnim = 0;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

#undef sFrame
#undef sOffsetY

static void SpriteCB_Ball_Block(struct Sprite *sprite)
{
    s32 i;

    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->y2 = 0;
    sprite->x2 = 0;
    for (i = 0; i < 6; i++)
        sprite->data[i] = 0;

    sprite->callback = SpriteCB_Ball_Block_Step;
}

#define sDy    data[0]
#define sDx    data[1]

#define sFrame data[0] // re-use

// Poké Ball moves down off screen after being blocked. The x-speed oscillates.
static void SpriteCB_Ball_Block_Step(struct Sprite *sprite)
{
    s16 dy = sprite->sDy + 0x800;
    s16 dx = sprite->sDx + 0x680;
    sprite->x2 -= dx >> 8;
    sprite->y2 += dy >> 8;
    sprite->sDy = (sprite->sDy + 0x800) & 0xFF;
    sprite->sDx = (sprite->sDx + 0x680) & 0xFF;

    if (sprite->y + sprite->y2 > DISPLAY_HEIGHT
     || sprite->x + sprite->x2 < -8)
    {
        sprite->sFrame = 0;
        sprite->callback = DestroySpriteAfterOneFrame;
        gDoingBattleAnim = 0;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

#undef sDy
#undef sDx

#undef sFrame

static void LoadBallParticleGfx(u8 ballId)
{
    if (GetSpriteTileStartByTag(sBallParticleSpriteSheets[ballId].tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&sBallParticleSpriteSheets[ballId]);
        LoadCompressedSpritePaletteUsingHeap(&sBallParticlePalettes[ballId]);
    }
}

u8 AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, u8 ballId)
{
    u8 taskId;

    LoadBallParticleGfx(ballId);
    taskId = CreateTask(sBallParticleAnimationFuncs[ballId], 5);
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = priority;
    gTasks[taskId].data[4] = subpriority;
    gTasks[taskId].data[15] = ballId;
    PlaySE(SE_BALL_OPEN);

    return taskId;
}

static void IncrBallParticleCount(void)
{
    if (gMain.inBattle)
        gBattleSpritesDataPtr->animationData->numBallParticles++;
}

static void PokeBallOpenParticleAnimation(u8 taskId)
{
    u8 spriteId;
    u8 x, y;
    u8 priority, subpriority;
    u8 ballId;
    u8 var0;

    ballId = gTasks[taskId].data[15];
    if (gTasks[taskId].data[0] < 16)
    {
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PokeBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;

            var0 = (u8)gTasks[taskId].data[0];
            if (var0 >= 8)
                var0 -= 8;

            gSprites[spriteId].data[0] = var0 * 32;
        }

        if (gTasks[taskId].data[0] == 15)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
            return;
        }
    }

    gTasks[taskId].data[0]++;
}

static void PokeBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
        sprite->callback = PokeBallOpenParticleAnimation_Step2;
    else
        sprite->data[1]--;
}

static void PokeBallOpenParticleAnimation_Step2(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], sprite->data[1]);
    sprite->data[1] += 2;
    if (sprite->data[1] == 50)
        DestroyBallOpenAnimationParticle(sprite);
}

static void TimerBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 2;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void DiveBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 2;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Net Ball
static void SafariBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 4;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Nest Ball
static void UltraBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 10; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 25;
            gSprites[spriteId].data[4] = 5;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Luxury Ball
static void GreatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    if (gTasks[taskId].data[7])
    {
        gTasks[taskId].data[7]--;
    }
    else
    {
        ballId = gTasks[taskId].data[15];
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                IncrBallParticleCount();
                StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;
                gSprites[spriteId].data[5] = 2;
                gSprites[spriteId].data[6] = 2;
            }
        }

        gTasks[taskId].data[7] = 8;
        if (++gTasks[taskId].data[0] == 2)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
        }
    }
}

static void FanOutBallOpenParticles_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], sprite->data[2]);
    sprite->data[0] = (sprite->data[0] + sprite->data[4]) & 0xFF;
    sprite->data[1] += sprite->data[5];
    sprite->data[2] += sprite->data[6];
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void RepeatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 12; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = RepeatBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 21;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void RepeatBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], Sin(sprite->data[0], sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void MasterBallOpenParticleAnimation(u8 taskId)
{
    u8 i, j;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                IncrBallParticleCount();
                StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;

                if (j == 0)
                {
                    gSprites[spriteId].data[5] = 2;
                    gSprites[spriteId].data[6] = 1;
                }
                else
                {
                    gSprites[spriteId].data[5] = 1;
                    gSprites[spriteId].data[6] = 2;
                }
            }
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void PremierBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            IncrBallParticleCount();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PremierBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void PremierBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], Sin(sprite->data[0] & 0x3F, sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 10) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void DestroyBallOpenAnimationParticle(struct Sprite *sprite)
{
    s32 i, j;

    if (!gMain.inBattle)
    {
        if (sprite->data[7] == 1)
            DestroySpriteAndFreeResources(sprite);
        else
            DestroySprite(sprite);
    }
    else
    {
        gBattleSpritesDataPtr->animationData->numBallParticles--;
        if (gBattleSpritesDataPtr->animationData->numBallParticles == 0)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
            {
                if (FuncIsActiveTask(sBallParticleAnimationFuncs[i]) == TRUE)
                    break;
            }

            if (i == POKEBALL_COUNT)
            {
                for (j = 0; j < POKEBALL_COUNT; j++)
                {
                    FreeSpriteTilesByTag(sBallParticleSpriteSheets[j].tag);
                    FreeSpritePaletteByTag(sBallParticlePalettes[j].tag);
                }
            }

            DestroySprite(sprite);
        }
        else
        {
            DestroySprite(sprite);
        }
    }
}

#define tCoeff     data[0]
#define tdCoeff    data[1]
#define tTimer     data[2]
#define tPalOffset data[3]
#define tPaletteLo data[10]
#define tPaletteHi data[11]
#define tBallId    data[15]

u8 LaunchBallFadeMonTask(bool8 unfadeLater, u8 spritePalNum, u32 selectedPalettes, u8 ballId)
{
    u8 taskId;

    taskId = CreateTask(Task_FadeMon_ToBallColor, 5);
    gTasks[taskId].tBallId = ballId;
    gTasks[taskId].tPalOffset = spritePalNum;
    gTasks[taskId].tPaletteLo = selectedPalettes;
    gTasks[taskId].tPaletteHi = selectedPalettes >> 16;

    if (!unfadeLater)
    {
        BlendPalette(OBJ_PLTT_ID(spritePalNum), 16, 0, gBallOpenFadeColors[ballId]);
        gTasks[taskId].tdCoeff = 1;
    }
    else
    {
        BlendPalette(OBJ_PLTT_ID(spritePalNum), 16, 16, gBallOpenFadeColors[ballId]);
        gTasks[taskId].tCoeff = 16;
        gTasks[taskId].tdCoeff = -1;
        gTasks[taskId].func = Task_FadeMon_ToNormal;
    }

    BeginNormalPaletteFade(selectedPalettes, 0, 0, 16, RGB_WHITE);
    return taskId;
}

static void Task_FadeMon_ToBallColor(u8 taskId)
{
    u8 ballId = gTasks[taskId].tBallId;

    if (gTasks[taskId].tTimer <= 16)
    {
        BlendPalette(OBJ_PLTT_ID(gTasks[taskId].tPalOffset), 16, gTasks[taskId].tCoeff, gBallOpenFadeColors[ballId]);
        gTasks[taskId].tCoeff += gTasks[taskId].tdCoeff;
        gTasks[taskId].tTimer++;
    }
    else if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].tPaletteLo | ((u16)gTasks[taskId].tPaletteHi << 16);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB_WHITE);
        DestroyTask(taskId);
    }
}

static void Task_FadeMon_ToNormal(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].tPaletteLo | ((u16)gTasks[taskId].tPaletteHi << 16);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB_WHITE);
        gTasks[taskId].func = Task_FadeMon_ToNormal_Step;
    }
}

static void Task_FadeMon_ToNormal_Step(u8 taskId)
{
    u8 ballId = gTasks[taskId].tBallId;

    if (gTasks[taskId].tTimer <= 16)
    {
        BlendPalette(OBJ_PLTT_ID(gTasks[taskId].tPalOffset), 16, gTasks[taskId].tCoeff, gBallOpenFadeColors[ballId]);
        gTasks[taskId].tCoeff += gTasks[taskId].tdCoeff;
        gTasks[taskId].tTimer++;
    }
    else
    {
        DestroyTask(taskId);
    }
}

#undef tCoeff
#undef tdCoeff
#undef tTimer
#undef tPalOffset
#undef tPaletteLo
#undef tPaletteHi
#undef tBallId

// arg0: TRUE to swap to mon, FALSE to swap to substitute
void AnimTask_SwapMonSpriteToFromSubstitute(u8 taskId)
{
    u8 spriteId;
    u32 x;
    u32 done = FALSE;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[10])
    {
    case 0:
        gTasks[taskId].data[11] = gBattleAnimArgs[0];
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].x2 += gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].x2 -= gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        x = gSprites[spriteId].x + gSprites[spriteId].x2 + 32;
        if (x > DISPLAY_WIDTH + 64)
            gTasks[taskId].data[10]++;
        break;
    case 1:
        LoadBattleMonGfxAndAnimate(gBattleAnimAttacker, gTasks[taskId].data[11], spriteId);
        gTasks[taskId].data[10]++;
        break;
    case 2:
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].x2 -= gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].x2 += gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            if (gSprites[spriteId].x2 <= 0)
            {
                gSprites[spriteId].x2 = 0;
                done = TRUE;
            }
        }
        else
        {
            if (gSprites[spriteId].x2 >= 0)
            {
                gSprites[spriteId].x2 = 0;
                done = TRUE;
            }
        }

        if (done)
            DestroyAnimVisualTask(taskId);

        break;
    }
}

void AnimTask_SubstituteFadeToInvisible(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == B_POSITION_OPPONENT_LEFT)
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        else
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        gTasks[taskId].data[15]++;
        break;
    case 1:
        if (gTasks[taskId].data[1]++ > 1)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - gTasks[taskId].data[0], gTasks[taskId].data[0]));
            if (gTasks[taskId].data[0] == 16)
                gTasks[taskId].data[15]++;
        }
        break;
    case 2:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        RequestDma3Fill(0, (void *)OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP, MON_PIC_SIZE, 1);
        ClearBehindSubstituteBit(gBattleAnimAttacker);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_IsAttackerBehindSubstitute(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].behindSubstitute;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_SetTargetToEffectBattler(u8 taskId)
{
    gBattleAnimTarget = gEffectBattler;
    DestroyAnimVisualTask(taskId);
}

#define tBattler   data[0]
#define tStarMove  data[1]
#define tStarTimer data[10]
#define tStarIdx   data[11]
#define tNumStars  data[12]
#define tTimer     data[13]

#define sTaskId data[0]
#define sPhase  data[1] // For encircling stars
#define sTimer  data[1] // For diagnoal stars

void TryShinyAnimation(u8 battler, struct Pokemon *mon)
{
    bool8 isShiny;
    u32 otId, personality;
    u32 shinyValue;
    u8 taskCirc, taskDgnl;

    isShiny = FALSE;
    gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = TRUE;
    otId = GetMonData(mon, MON_DATA_OT_ID);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (IsBattlerSpriteVisible(battler))
    {
        shinyValue = GET_SHINY_VALUE(otId, personality);
        if (shinyValue < SHINY_ODDS)
            isShiny = TRUE;

        if (isShiny)
        {
            if (GetSpriteTileStartByTag(ANIM_TAG_GOLD_STARS) == 0xFFFF)
            {
                LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
                LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
            }

            taskCirc = CreateTask(Task_ShinyStars, 10);
            taskDgnl = CreateTask(Task_ShinyStars, 10);
            gTasks[taskCirc].tBattler = battler;
            gTasks[taskDgnl].tBattler = battler;
            gTasks[taskCirc].tStarMove = SHINY_STAR_ENCIRCLE;
            gTasks[taskDgnl].tStarMove = SHINY_STAR_DIAGONAL;
            return;
        }
    }

    gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = TRUE;
}

static void Task_ShinyStars(u8 taskId)
{
    u8 battler;
    u8 x, y;
    u8 spriteId;
    u16 timer;
    s16 starIdx;
    u8 pan;

    if (gTasks[taskId].tTimer < 60)
    {
        gTasks[taskId].tTimer++;
        return;
    }

    // Wait until the ball particles have despawned
    if (gBattleSpritesDataPtr->animationData->numBallParticles)
        return;

    timer = gTasks[taskId].tStarTimer++;
    if (timer % 4) // Create sprite 1 of every 4 frames
        return;

    battler = gTasks[taskId].tBattler;
    x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
    y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);

    starIdx = gTasks[taskId].tStarIdx;
    if (starIdx == 0) // Big star
    {
        spriteId = CreateSprite(&gWishStarSpriteTemplate, x, y, 5);
    }
    else if (starIdx >= 0 && gTasks[taskId].tStarIdx < 4) // Medium star
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 4;
    }
    else // Small star
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 5;
    }

    if (gTasks[taskId].tStarMove == SHINY_STAR_ENCIRCLE)
    {
        gSprites[spriteId].callback = SpriteCB_ShinyStars_Encircle;
    }
    else
    {
        gSprites[spriteId].callback = SpriteCB_ShinyStars_Diagonal;
        gSprites[spriteId].x2 = -32;
        gSprites[spriteId].y2 = 32;
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].tStarIdx == 0)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                pan = -64;
            else
                pan = 63;

            PlaySE12WithPanning(SE_SHINY, pan);
        }
    }

    gSprites[spriteId].sTaskId = taskId;
    gTasks[taskId].tStarIdx++;
    if (spriteId != MAX_SPRITES)
        gTasks[taskId].tNumStars++;

    if (gTasks[taskId].tStarIdx == 5)
        gTasks[taskId].func = Task_ShinyStars_Wait;
}

static void Task_ShinyStars_Wait(u8 taskId)
{
    u8 battler;

    if (gTasks[taskId].tNumStars == 0)
    {
        if (gTasks[taskId].tStarMove == SHINY_STAR_DIAGONAL)
        {
            battler = gTasks[taskId].tBattler;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = TRUE;
        }

        DestroyTask(taskId);
    }
}

static void SpriteCB_ShinyStars_Encircle(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->sPhase, 24);
    sprite->y2 = Cos(sprite->sPhase, 24);
    sprite->sPhase += 12;
    if (sprite->sPhase > 255)
    {
        gTasks[sprite->sTaskId].tNumStars--;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

static void SpriteCB_ShinyStars_Diagonal(struct Sprite *sprite)
{
    // Delayed four frames to de-sync from encircling stars
    if (sprite->sTimer < 4)
    {
        sprite->sTimer++;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x2 += 5;
        sprite->y2 -= 5;
        if (sprite->x2 > 32)
        {
            gTasks[sprite->sTaskId].tNumStars--;
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
    }
}

#undef tBattler
#undef tStarMove
#undef tStarTimer
#undef tStarIdx
#undef tNumStars
#undef tTimer

#undef sTaskId
#undef sPhase
#undef sTimer

void AnimTask_LoadPokeblockGfx(u8 taskId)
{
    u8 UNUSED paletteIndex;

    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    paletteIndex = IndexOfSpritePaletteTag(ANIM_TAG_POKEBLOCK);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreePokeblockGfx(u8 taskId)
{
    FreeSpriteTilesByTag(ANIM_TAG_POKEBLOCK);
    FreeSpritePaletteByTag(ANIM_TAG_POKEBLOCK);
    DestroyAnimVisualTask(taskId);
}

#define sDuration data[0]
#define sTargetX data[2]
#define sTargetY data[4]
#define sAmplitude data[5]

static void SpriteCB_PokeBlock_Throw(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->sDuration = 30;
    sprite->sTargetX = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), BATTLER_COORD_X) + gBattleAnimArgs[2];
    sprite->sTargetY = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), BATTLER_COORD_Y) + gBattleAnimArgs[3];
    sprite->sAmplitude = -32;
    InitAnimArcTranslation(sprite);
    gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].callback = SpriteCB_TrainerThrowObject;
    sprite->callback = SpriteCB_PokeBlock_LiftArm;
}

#undef sDuration
#undef sTargetX
#undef sTargetY
#undef sAmplitude

static void SpriteCB_PokeBlock_LiftArm(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animCmdIndex == 1)
        sprite->callback = SpriteCB_PokeBlock_Arc;
}

static void SpriteCB_PokeBlock_Arc(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 0;
        sprite->invisible = TRUE;
        sprite->callback = SpriteCB_ThrowPokeBlock_Free;
    }
}

// Destroy after end of player animation
static void SpriteCB_ThrowPokeBlock_Free(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animEnded)
    {
        if (++sprite->data[0] > 0)
        {
            StartSpriteAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], 0);
            DestroyAnimSprite(sprite);
        }
    }
}

void AnimTask_SetAttackerTargetLeftPos(u8 taskId)
{
    switch (gBattleAnimArgs[0])
    {
    case 0:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case 1:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetTrappedMoveAnimId(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->animArg == MOVE_FIRE_SPIN)
        gBattleAnimArgs[0] = TRAP_ANIM_FIRE_SPIN;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_WHIRLPOOL)
        gBattleAnimArgs[0] = TRAP_ANIM_WHIRLPOOL;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_CLAMP)
        gBattleAnimArgs[0] = TRAP_ANIM_CLAMP;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_SAND_TOMB)
        gBattleAnimArgs[0] = TRAP_ANIM_SAND_TOMB;
    else
        gBattleAnimArgs[0] = TRAP_ANIM_BIND;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetBattlersFromArg(u8 taskId)
{
    gBattleAnimAttacker = gBattleSpritesDataPtr->animationData->animArg;
    gBattleAnimTarget = gBattleSpritesDataPtr->animationData->animArg >> 8;
    DestroyAnimVisualTask(taskId);
}

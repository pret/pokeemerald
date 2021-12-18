#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "decompress.h"
#include "graphics.h"
#include "main.h"
#include "m4a.h"
#include "pokeball.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "data.h"
#include "constants/songs.h"

static void Task_DoPokeballSendOutAnim(u8 taskId);
static void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite);
static void SpriteCB_PlayerMonSendOut_2(struct Sprite *sprite);
static void SpriteCB_OpponentMonSendOut(struct Sprite *sprite);
static void SpriteCB_BallThrow(struct Sprite *sprite);
static void SpriteCB_BallThrow_ReachMon(struct Sprite *sprite);
static void SpriteCB_BallThrow_StartShrinkMon(struct Sprite *sprite);
static void SpriteCB_BallThrow_ShrinkMon(struct Sprite *sprite);
static void SpriteCB_BallThrow_Close(struct Sprite *sprite);
static void SpriteCB_BallThrow_FallToGround(struct Sprite *sprite);
static void SpriteCB_BallThrow_StartShakes(struct Sprite *sprite);
static void SpriteCB_BallThrow_Shake(struct Sprite *sprite);
static void SpriteCB_BallThrow_StartCaptureMon(struct Sprite *sprite);
static void SpriteCB_BallThrow_CaptureMon(struct Sprite *sprite);
static void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite);
static void SpriteCB_ReleaseMon2FromBall(struct Sprite *sprite);
static void HandleBallAnimEnd(struct Sprite *sprite);
static void SpriteCB_PokeballReleaseMon(struct Sprite *sprite);
static void SpriteCB_ReleasedMonFlyOut(struct Sprite *sprite);
static void SpriteCB_TradePokeball(struct Sprite *sprite);
static void SpriteCB_TradePokeballSendOff(struct Sprite *sprite);
static void SpriteCB_TradePokeballEnd(struct Sprite *sprite);
static void SpriteCB_HealthboxSlideInDelayed(struct Sprite *sprite);
static void SpriteCB_HealthboxSlideIn(struct Sprite *sprite);
static void SpriteCB_HitAnimHealthoxEffect(struct Sprite *sprite);
static u16 GetBattlerPokeballItemId(u8 battlerId);

// rom const data

#define GFX_TAG_POKEBALL    55000
#define GFX_TAG_GREATBALL   55001
#define GFX_TAG_ULTRABALL   55002
#define GFX_TAG_MASTERBALL  55003
#define GFX_TAG_PREMIERBALL 55004
#define GFX_TAG_HEALBALL    55005
#define GFX_TAG_NETBALL     55006
#define GFX_TAG_NESTBALL    55007
#define GFX_TAG_DIVEBALL    55008
#define GFX_TAG_DUSKBALL    55009
#define GFX_TAG_TIMERBALL   55010
#define GFX_TAG_QUICKBALL   55011
#define GFX_TAG_REPEATBALL  55012
#define GFX_TAG_LUXURYBALL  55013
#define GFX_TAG_LEVELBALL   55014
#define GFX_TAG_LUREBALL    55015
#define GFX_TAG_MOONBALL    55016
#define GFX_TAG_FRIENDBALL  55017
#define GFX_TAG_LOVEBALL    55018
#define GFX_TAG_FASTBALL    55019
#define GFX_TAG_HEAVYBALL   55020
#define GFX_TAG_DREAMBALL   55021
#define GFX_TAG_SAFARIBALL  55022
#define GFX_TAG_SPORTBALL   55023
#define GFX_TAG_PARKBALL    55024
#define GFX_TAG_BEASTBALL   55025
#define GFX_TAG_CHERISHBALL 55026

const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gInterfaceGfx_PokeBall,    384, GFX_TAG_POKEBALL},
    [BALL_GREAT]   = {gInterfaceGfx_GreatBall,   384, GFX_TAG_GREATBALL},
    [BALL_ULTRA]   = {gInterfaceGfx_UltraBall,   384, GFX_TAG_ULTRABALL},
    [BALL_MASTER]  = {gInterfaceGfx_MasterBall,  384, GFX_TAG_MASTERBALL},
    [BALL_PREMIER] = {gInterfaceGfx_PremierBall, 384, GFX_TAG_PREMIERBALL},
    [BALL_HEAL]    = {gInterfaceGfx_HealBall,    384, GFX_TAG_HEALBALL},
    [BALL_NET]     = {gInterfaceGfx_NetBall,     384, GFX_TAG_NETBALL},
    [BALL_NEST]    = {gInterfaceGfx_NestBall,    384, GFX_TAG_NESTBALL},
    [BALL_DIVE]    = {gInterfaceGfx_DiveBall,    384, GFX_TAG_DIVEBALL},
    [BALL_DUSK]    = {gInterfaceGfx_DuskBall,    384, GFX_TAG_DUSKBALL},
    [BALL_TIMER]   = {gInterfaceGfx_TimerBall,   384, GFX_TAG_TIMERBALL},
    [BALL_QUICK]   = {gInterfaceGfx_QuickBall,   384, GFX_TAG_QUICKBALL},
    [BALL_REPEAT]  = {gInterfaceGfx_RepeatBall,  384, GFX_TAG_REPEATBALL},
    [BALL_LUXURY]  = {gInterfaceGfx_LuxuryBall,  384, GFX_TAG_LUXURYBALL},
    [BALL_LEVEL]   = {gInterfaceGfx_LevelBall,   384, GFX_TAG_LEVELBALL},
    [BALL_LURE]    = {gInterfaceGfx_LureBall,    384, GFX_TAG_LUREBALL},
    [BALL_MOON]    = {gInterfaceGfx_MoonBall,    384, GFX_TAG_MOONBALL},
    [BALL_FRIEND]  = {gInterfaceGfx_FriendBall,  384, GFX_TAG_FRIENDBALL},
    [BALL_LOVE]    = {gInterfaceGfx_LoveBall,    384, GFX_TAG_LOVEBALL},
    [BALL_FAST]    = {gInterfaceGfx_FastBall,    384, GFX_TAG_FASTBALL},
    [BALL_HEAVY]   = {gInterfaceGfx_HeavyBall,   384, GFX_TAG_HEAVYBALL},
    [BALL_DREAM]   = {gInterfaceGfx_DreamBall,   384, GFX_TAG_DREAMBALL},
    [BALL_SAFARI]  = {gInterfaceGfx_SafariBall,  384, GFX_TAG_SAFARIBALL},
    [BALL_SPORT]   = {gInterfaceGfx_SportBall,   384, GFX_TAG_SPORTBALL},
    [BALL_PARK]    = {gInterfaceGfx_ParkBall,    384, GFX_TAG_PARKBALL},
    [BALL_BEAST]   = {gInterfaceGfx_BeastBall,   384, GFX_TAG_BEASTBALL},
    [BALL_CHERISH] = {gInterfaceGfx_CherishBall, 384, GFX_TAG_CHERISHBALL},
};

const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gInterfacePal_PokeBall,    GFX_TAG_POKEBALL},
    [BALL_GREAT]   = {gInterfacePal_GreatBall,   GFX_TAG_GREATBALL},
    [BALL_ULTRA]   = {gInterfacePal_UltraBall,   GFX_TAG_ULTRABALL},
    [BALL_MASTER]  = {gInterfacePal_MasterBall,  GFX_TAG_MASTERBALL},
    [BALL_PREMIER] = {gInterfacePal_PremierBall, GFX_TAG_PREMIERBALL},
    [BALL_HEAL]    = {gInterfacePal_HealBall,    GFX_TAG_HEALBALL},
    [BALL_NET]     = {gInterfacePal_NetBall,     GFX_TAG_NETBALL},
    [BALL_NEST]    = {gInterfacePal_NestBall,    GFX_TAG_NESTBALL},
    [BALL_DIVE]    = {gInterfacePal_DiveBall,    GFX_TAG_DIVEBALL},
    [BALL_DUSK]    = {gInterfacePal_DuskBall,    GFX_TAG_DUSKBALL},
    [BALL_TIMER]   = {gInterfacePal_TimerBall,   GFX_TAG_TIMERBALL},
    [BALL_QUICK]   = {gInterfacePal_QuickBall,   GFX_TAG_QUICKBALL},
    [BALL_REPEAT]  = {gInterfacePal_RepeatBall,  GFX_TAG_REPEATBALL},
    [BALL_LUXURY]  = {gInterfacePal_LuxuryBall,  GFX_TAG_LUXURYBALL},
    [BALL_LEVEL]   = {gInterfacePal_LevelBall,   GFX_TAG_LEVELBALL},
    [BALL_LURE]    = {gInterfacePal_LureBall,    GFX_TAG_LUREBALL},
    [BALL_MOON]    = {gInterfacePal_MoonBall,    GFX_TAG_MOONBALL},
    [BALL_FRIEND]  = {gInterfacePal_FriendBall,  GFX_TAG_FRIENDBALL},
    [BALL_LOVE]    = {gInterfacePal_LoveBall,    GFX_TAG_LOVEBALL},
    [BALL_FAST]    = {gInterfacePal_FastBall,    GFX_TAG_FASTBALL},
    [BALL_HEAVY]   = {gInterfacePal_HeavyBall,   GFX_TAG_HEAVYBALL},
    [BALL_DREAM]   = {gInterfacePal_DreamBall,   GFX_TAG_DREAMBALL},
    [BALL_SAFARI]  = {gInterfacePal_SafariBall,  GFX_TAG_SAFARIBALL},
    [BALL_SPORT]   = {gInterfacePal_SportBall,   GFX_TAG_SPORTBALL},
    [BALL_PARK]    = {gInterfacePal_ParkBall,    GFX_TAG_PARKBALL},
    [BALL_BEAST]   = {gInterfacePal_BeastBall,   GFX_TAG_BEASTBALL},
    [BALL_CHERISH] = {gInterfacePal_CherishBall, GFX_TAG_CHERISHBALL},
};

static const struct OamData sBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
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
    .affineParam = 0,
};

static const union AnimCmd sBallAnimSeq3[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq5[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq4[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq6[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBallAnimSeq1[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd sBallAnimSeq2[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sBallAnimSequences[] =
{
    sBallAnimSeq0,
    sBallAnimSeq1,
    sBallAnimSeq2,

    // unused?
    sBallAnimSeq3,
    sBallAnimSeq4,
    sBallAnimSeq5,
    sBallAnimSeq6,
};

static const union AffineAnimCmd sAffineAnim_BallRotate_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_BallRotate_Right[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -3, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_BallRotate_Left[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 3, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_BallRotate_3[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_BallRotate_4[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 25, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sAffineAnim_BallRotate[] =
{
    [BALL_AFFINE_ANIM_0] = sAffineAnim_BallRotate_0,
    [BALL_ROTATE_RIGHT]  = sAffineAnim_BallRotate_Right,
    [BALL_ROTATE_LEFT]   = sAffineAnim_BallRotate_Left,
    [BALL_AFFINE_ANIM_3] = sAffineAnim_BallRotate_3,
    [BALL_AFFINE_ANIM_4] = sAffineAnim_BallRotate_4,
};

const struct SpriteTemplate gBallSpriteTemplates[POKEBALL_COUNT] =
{
    {
        .tileTag = GFX_TAG_POKEBALL,
        .paletteTag = GFX_TAG_POKEBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_GREATBALL,
        .paletteTag = GFX_TAG_GREATBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_ULTRABALL,
        .paletteTag = GFX_TAG_ULTRABALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_MASTERBALL,
        .paletteTag = GFX_TAG_MASTERBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_PREMIERBALL,
        .paletteTag = GFX_TAG_PREMIERBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_HEALBALL,
        .paletteTag = GFX_TAG_HEALBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_NETBALL,
        .paletteTag = GFX_TAG_NETBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_NESTBALL,
        .paletteTag = GFX_TAG_NESTBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_DIVEBALL,
        .paletteTag = GFX_TAG_DIVEBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_DUSKBALL,
        .paletteTag = GFX_TAG_DUSKBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_TIMERBALL,
        .paletteTag = GFX_TAG_TIMERBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_QUICKBALL,
        .paletteTag = GFX_TAG_QUICKBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_REPEATBALL,
        .paletteTag = GFX_TAG_REPEATBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_LUXURYBALL,
        .paletteTag = GFX_TAG_LUXURYBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_LEVELBALL,
        .paletteTag = GFX_TAG_LEVELBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_LUREBALL,
        .paletteTag = GFX_TAG_LUREBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_MOONBALL,
        .paletteTag = GFX_TAG_MOONBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_FRIENDBALL,
        .paletteTag = GFX_TAG_FRIENDBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_LOVEBALL,
        .paletteTag = GFX_TAG_LOVEBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_FASTBALL,
        .paletteTag = GFX_TAG_FASTBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_HEAVYBALL,
        .paletteTag = GFX_TAG_HEAVYBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_DREAMBALL,
        .paletteTag = GFX_TAG_DREAMBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_SAFARIBALL,
        .paletteTag = GFX_TAG_SAFARIBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_SPORTBALL,
        .paletteTag = GFX_TAG_SPORTBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_PARKBALL,
        .paletteTag = GFX_TAG_PARKBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_BEASTBALL,
        .paletteTag = GFX_TAG_BEASTBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    {
        .tileTag = GFX_TAG_CHERISHBALL,
        .paletteTag = GFX_TAG_CHERISHBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
};

#define tFrames          data[0]
#define tPan             data[1]
#define tThrowId         data[2]
#define tBattler         data[3]
#define tOpponentBattler data[4]

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow)
{
    u8 taskId;

    gDoingBattleAnim = TRUE;
    gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive = 1;

    taskId = CreateTask(Task_DoPokeballSendOutAnim, 5);
    gTasks[taskId].tPan = pan;
    gTasks[taskId].tThrowId = kindOfThrow;
    gTasks[taskId].tBattler = gActiveBattler;

    return 0;
}

#define sBattler         data[6]

static void Task_DoPokeballSendOutAnim(u8 taskId)
{
    u32 throwCaseId, ballId, battlerId, ballSpriteId;
    bool32 notSendOut = FALSE;

    if (gTasks[taskId].tFrames == 0)
    {
        gTasks[taskId].tFrames++;
        return;
    }

    throwCaseId = gTasks[taskId].tThrowId;
    battlerId = gTasks[taskId].tBattler;
    ballId = ItemIdToBallId(GetBattlerPokeballItemId(battlerId));
    LoadBallGfx(ballId);
    ballSpriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[ballSpriteId].data[0] = 0x80;
    gSprites[ballSpriteId].data[1] = 0;
    gSprites[ballSpriteId].data[7] = throwCaseId;

    switch (throwCaseId)
    {
    case POKEBALL_PLAYER_SENDOUT:
        gBattlerTarget = battlerId;
        gSprites[ballSpriteId].x = 24;
        gSprites[ballSpriteId].y = 68;
        gSprites[ballSpriteId].callback = SpriteCB_PlayerMonSendOut_1;
        break;
    case POKEBALL_OPPONENT_SENDOUT:
        gSprites[ballSpriteId].x = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X);
        gSprites[ballSpriteId].y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 24;
        gBattlerTarget = battlerId;
        gSprites[ballSpriteId].data[0] = 0;
        gSprites[ballSpriteId].callback = SpriteCB_OpponentMonSendOut;
        break;
    default:
        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        notSendOut = TRUE;
        break;
    }

    gSprites[ballSpriteId].sBattler = gBattlerTarget;
    if (!notSendOut)
    {
        DestroyTask(taskId);
        return;
    }

    // this will perform an unused ball throw animation
    gSprites[ballSpriteId].data[0] = 0x22;
    gSprites[ballSpriteId].data[2] = GetBattlerSpriteCoord(gBattlerTarget, BATTLER_COORD_X);
    gSprites[ballSpriteId].data[4] = GetBattlerSpriteCoord(gBattlerTarget, BATTLER_COORD_Y) - 16;
    gSprites[ballSpriteId].data[5] = -40;
    InitAnimArcTranslation(&gSprites[ballSpriteId]);
    gSprites[ballSpriteId].oam.affineParam = taskId;
    gTasks[taskId].tOpponentBattler = gBattlerTarget;
    gTasks[taskId].func = TaskDummy;
    PlaySE(SE_BALL_THROW);
}

// This sequence of functions is very similar to those that get run when
// a Pokéball gets thrown at a wild Pokémon, starting at SpriteCB_Ball_Arc.
// These do not seem to get run.
static void SpriteCB_BallThrow(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        u16 ballId;
        u8 taskId = sprite->oam.affineParam;
        u8 opponentBattler = gTasks[taskId].tOpponentBattler;
        u8 noOfShakes = gTasks[taskId].tThrowId;

        StartSpriteAnim(sprite, 1);
        sprite->affineAnimPaused = 1;
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[5] = 0;
        ballId = ItemIdToBallId(GetBattlerPokeballItemId(opponentBattler));
        AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 0x1C, ballId);
        sprite->data[0] = LaunchBallFadeMonTask(FALSE, opponentBattler, 14, ballId);
        sprite->sBattler = opponentBattler;
        sprite->data[7] = noOfShakes;
        DestroyTask(taskId);
        sprite->callback = SpriteCB_BallThrow_ReachMon;
    }
}

#undef tFrames
#undef tPan
#undef tThrowId
#undef tBattler
#undef tOpponentBattler

static void SpriteCB_BallThrow_ReachMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_BallThrow_StartShrinkMon;
}

static void SpriteCB_BallThrow_StartShrinkMon(struct Sprite *sprite)
{
    if (++sprite->data[5] == 10)
    {
        sprite->data[5] = 0;
        sprite->callback = SpriteCB_BallThrow_ShrinkMon;
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[sprite->sBattler]], BATTLER_AFFINE_RETURN);
        AnimateSprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
        gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] = 0;
    }
}

static void SpriteCB_BallThrow_ShrinkMon(struct Sprite *sprite)
{
    sprite->data[5]++;
    if (sprite->data[5] == 11)
        PlaySE(SE_BALL_TRADE);
    if (gSprites[gBattlerSpriteIds[sprite->sBattler]].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[gBattlerSpriteIds[sprite->sBattler]].invisible = TRUE;
        sprite->data[5] = 0;
        sprite->callback = SpriteCB_BallThrow_Close;
    }
    else
    {
        gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] += 0x60;
        gSprites[gBattlerSpriteIds[sprite->sBattler]].y2 = -gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] >> 8;
    }
}

static void SpriteCB_BallThrow_Close(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[3] = 0;
            sprite->data[4] = 32;
            sprite->data[5] = 0;
            sprite->y += Cos(0, 32);
            sprite->y2 = -Cos(0, sprite->data[4]);
            sprite->callback = SpriteCB_BallThrow_FallToGround;
        }
    }
}

static void SpriteCB_BallThrow_FallToGround(struct Sprite *sprite)
{
    bool8 r5 = FALSE;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        sprite->y2 = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] += 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] >= 64)
        {
            sprite->data[4] -= 10;
            sprite->data[3] += 0x101;
            if (sprite->data[3] >> 8 == 4)
                r5 = TRUE;
            switch (sprite->data[3] >> 8)
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
    case 1:
        sprite->y2 = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] -= 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] <= 0)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
        }
        break;
    }
    if (r5)
    {
        sprite->data[3] = 0;
        sprite->y += Cos(64, 32);
        sprite->y2 = 0;
        if (sprite->data[7] == 0)
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            sprite->callback = SpriteCB_BallThrow_StartShakes;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

static void SpriteCB_BallThrow_StartShakes(struct Sprite *sprite)
{
    sprite->data[3]++;
    if (sprite->data[3] == 31)
    {
        sprite->data[3] = 0;
        sprite->affineAnimPaused = TRUE;
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = SpriteCB_BallThrow_Shake;
        PlaySE(SE_BALL);
    }
}

static void SpriteCB_BallThrow_Shake(struct Sprite *sprite)
{
    switch (sprite->data[3] & 0xFF)
    {
    case 0:
    case 2:
        sprite->x2 += sprite->data[4];
        sprite->data[5] += sprite->data[4];
        sprite->affineAnimPaused = FALSE;
        if (sprite->data[5] > 3 || sprite->data[5] < -3)
        {
            sprite->data[3]++;
            sprite->data[5] = 0;
        }
        break;
    case 1:
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[5] = 0;
            sprite->data[4] = -sprite->data[4];
            sprite->data[3]++;
            sprite->affineAnimPaused = FALSE;
            if (sprite->data[4] < 0)
                ChangeSpriteAffineAnim(sprite, 2);
            else
                ChangeSpriteAffineAnim(sprite, 1);
        }
        else
        {
            sprite->affineAnimPaused = TRUE;
        }
        break;
    case 3:
        sprite->data[3] += 0x100;
        if (sprite->data[3] >> 8 == sprite->data[7])
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            if (sprite->data[7] == 4 && sprite->data[3] >> 8 == 3)
            {
                sprite->callback = SpriteCB_BallThrow_StartCaptureMon;
                sprite->affineAnimPaused = TRUE;
            }
            else
            {
                sprite->data[3]++;
                sprite->affineAnimPaused = TRUE;
            }
        }
        break;
    case 4:
    default:
        sprite->data[5]++;
        if (sprite->data[5] == 31)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
            StartSpriteAffineAnim(sprite, 3);
            if (sprite->data[4] < 0)
                StartSpriteAffineAnim(sprite, 2);
            else
                StartSpriteAffineAnim(sprite, 1);
            PlaySE(SE_BALL);
        }
        break;
    }
}

#define tCryTaskSpecies         data[0]
#define tCryTaskPan             data[1]
#define tCryTaskWantedCry       data[2]
#define tCryTaskBattler         data[3]
#define tCryTaskMonSpriteId     data[4]
#define tCryTaskMonPtr1         data[5]
#define tCryTaskMonPtr2         data[6]
#define tCryTaskFrames          data[10]
#define tCryTaskState           data[15]

static void Task_PlayCryWhenReleasedFromBall(u8 taskId)
{
    u8 wantedCry = gTasks[taskId].tCryTaskWantedCry;
    s8 pan = gTasks[taskId].tCryTaskPan;
    u16 species = gTasks[taskId].tCryTaskSpecies;
    u8 battlerId = gTasks[taskId].tCryTaskBattler;
    u8 monSpriteId = gTasks[taskId].tCryTaskMonSpriteId;
    struct Pokemon *mon = (void*)(u32)((gTasks[taskId].tCryTaskMonPtr1 << 16) | (u16)(gTasks[taskId].tCryTaskMonPtr2));

    switch (gTasks[taskId].tCryTaskState)
    {
    case 0:
    default:
        if (gSprites[monSpriteId].affineAnimEnded)
            gTasks[taskId].tCryTaskState = wantedCry + 1;
        break;
    case 1:
        // Play single cry
        if (ShouldPlayNormalMonCry(mon) == TRUE)
            PlayCry_ByMode(species, pan, CRY_MODE_NORMAL);
        else
            PlayCry_ByMode(species, pan, CRY_MODE_WEAK);
        gBattleSpritesDataPtr->healthBoxesData[battlerId].waitForCry = FALSE;
        DestroyTask(taskId);
        break;
    case 2:
        StopCryAndClearCrySongs();
        gTasks[taskId].tCryTaskFrames = 3;
        gTasks[taskId].tCryTaskState = 20;
        break;
    case 20:
        if (gTasks[taskId].tCryTaskFrames == 0)
        {
            // Play first doubles cry
            if (ShouldPlayNormalMonCry(mon) == TRUE)
                PlayCry_ReleaseDouble(species, pan, CRY_MODE_DOUBLES);
            else
                PlayCry_ReleaseDouble(species, pan, CRY_MODE_WEAK_DOUBLES);

            gBattleSpritesDataPtr->healthBoxesData[battlerId].waitForCry = FALSE;
            DestroyTask(taskId);
        }
        else
        {
            gTasks[taskId].tCryTaskFrames--;
        }
        break;
    case 3:
        gTasks[taskId].tCryTaskFrames = 6;
        gTasks[taskId].tCryTaskState = 30;
        break;
    case 30:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        gTasks[taskId].tCryTaskState++;
        // fall through
    case 31:
        if (!IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            gTasks[taskId].tCryTaskFrames = 3;
            gTasks[taskId].tCryTaskState++;
        }
        break;
    case 32:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        // Play second doubles cry
        if (ShouldPlayNormalMonCry(mon) == TRUE)
            PlayCry_ReleaseDouble(species, pan, CRY_MODE_NORMAL);
        else
            PlayCry_ReleaseDouble(species, pan, CRY_MODE_WEAK);

        gBattleSpritesDataPtr->healthBoxesData[battlerId].waitForCry = FALSE;
        DestroyTask(taskId);
        break;
    }
}

static void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite)
{
    u8 battlerId = sprite->sBattler;
    u32 ballId;

    StartSpriteAnim(sprite, 1);
    ballId = ItemIdToBallId(GetBattlerPokeballItemId(battlerId));
    AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 0x1C, ballId);
    sprite->data[0] = LaunchBallFadeMonTask(TRUE, sprite->sBattler, 14, ballId);
    sprite->callback = HandleBallAnimEnd;

    if (gMain.inBattle)
    {
        struct Pokemon *mon, *illusionMon;
        s8 pan;
        u16 wantedCryCase;
        u8 taskId;

        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        {
            mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
            pan = 25;
        }
        else
        {
            mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
            pan = -25;
        }

        if ((battlerId == GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) || battlerId == GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
         && IsDoubleBattle() && gBattleSpritesDataPtr->animationData->introAnimActive)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (IsBGMPlaying())
                    m4aMPlayStop(&gMPlayInfo_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 128);
            }
        }

        if (!IsDoubleBattle() || !gBattleSpritesDataPtr->animationData->introAnimActive)
            wantedCryCase = 0;
        else if (battlerId == GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) || battlerId == GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
            wantedCryCase = 1;
        else
            wantedCryCase = 2;

        gBattleSpritesDataPtr->healthBoxesData[battlerId].waitForCry = TRUE;

        taskId = CreateTask(Task_PlayCryWhenReleasedFromBall, 3);

        illusionMon = GetIllusionMonPtr(battlerId);
        if (illusionMon != NULL)
            gTasks[taskId].tCryTaskSpecies = GetMonData(illusionMon, MON_DATA_SPECIES);
        else
            gTasks[taskId].tCryTaskSpecies = GetMonData(mon, MON_DATA_SPECIES);

        gTasks[taskId].tCryTaskPan = pan;
        gTasks[taskId].tCryTaskWantedCry = wantedCryCase;
        gTasks[taskId].tCryTaskBattler = battlerId;
        gTasks[taskId].tCryTaskMonSpriteId = gBattlerSpriteIds[sprite->sBattler];
        gTasks[taskId].tCryTaskMonPtr1 = (u32)(mon) >> 16;
        gTasks[taskId].tCryTaskMonPtr2 = (u32)(mon);
        gTasks[taskId].tCryTaskState = 0;
    }

    StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[sprite->sBattler]], BATTLER_AFFINE_EMERGE);

    if (GetBattlerSide(sprite->sBattler) == B_SIDE_OPPONENT)
        gSprites[gBattlerSpriteIds[sprite->sBattler]].callback = SpriteCB_OpponentMonFromBall;
    else
        gSprites[gBattlerSpriteIds[sprite->sBattler]].callback = SpriteCB_PlayerMonFromBall;

    AnimateSprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
    gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] = 0x1000;
}

#undef tCryTaskSpecies
#undef tCryTaskPan
#undef tCryTaskWantedCry
#undef tCryTaskBattler
#undef tCryTaskMonSpriteId
#undef tCryTaskMonPtr1
#undef tCryTaskMonPtr2
#undef tCryTaskFrames
#undef tCryTaskState

static void SpriteCB_BallThrow_StartCaptureMon(struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    sprite->callback = SpriteCB_BallThrow_CaptureMon;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

static void HandleBallAnimEnd(struct Sprite *sprite)
{
    bool8 affineAnimEnded = FALSE;
    u8 battlerId = sprite->sBattler;

    gSprites[gBattlerSpriteIds[battlerId]].invisible = FALSE;
    if (sprite->animEnded)
        sprite->invisible = TRUE;
    if (gSprites[gBattlerSpriteIds[battlerId]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[battlerId]], BATTLER_AFFINE_NORMAL);
        affineAnimEnded = TRUE;
    }
    else
    {
        gSprites[gBattlerSpriteIds[battlerId]].data[1] -= 288;
        gSprites[gBattlerSpriteIds[battlerId]].y2 = gSprites[gBattlerSpriteIds[battlerId]].data[1] >> 8;
    }
    if (sprite->animEnded && affineAnimEnded)
    {
        s32 i, doneBattlers;

        gSprites[gBattlerSpriteIds[battlerId]].y2 = 0;
        gDoingBattleAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = 0;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);

        for (doneBattlers = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[i].ballAnimActive == 0)
                doneBattlers++;
        }
        if (doneBattlers == MAX_BATTLERS_COUNT)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
                FreeBallGfx(i);
        }
    }
}

static void SpriteCB_BallThrow_CaptureMon(struct Sprite *sprite)
{
    u8 battlerId = sprite->sBattler;

    sprite->data[4]++;
    if (sprite->data[4] == 40)
    {
        return;
    }
    else if (sprite->data[4] == 95)
    {
        gDoingBattleAnim = FALSE;
        m4aMPlayAllStop();
        PlaySE(MUS_EVOLVED);
    }
    else if (sprite->data[4] == 315)
    {
        FreeOamMatrix(gSprites[gBattlerSpriteIds[sprite->sBattler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
        DestroySpriteAndFreeResources(sprite);
        if (gMain.inBattle)
            gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = 0;
    }
}

static void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite)
{
    sprite->data[0] = 25;
    sprite->data[2] = GetBattlerSpriteCoord(sprite->sBattler, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(sprite->sBattler, BATTLER_COORD_Y_PIC_OFFSET) + 24;
    sprite->data[5] = -30;
    sprite->oam.affineParam = sprite->sBattler;
    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_PlayerMonSendOut_2;
}

#define HIBYTE(x) (((x) >> 8) & 0xFF)

static void SpriteCB_PlayerMonSendOut_2(struct Sprite *sprite)
{
    u32 r6;
    u32 r7;

    if (HIBYTE(sprite->data[7]) >= 35 && HIBYTE(sprite->data[7]) < 80)
    {
        s16 r4;

        if ((sprite->oam.affineParam & 0xFF00) == 0)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] / 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] / 3) & ~1) | r7;
            StartSpriteAffineAnim(sprite, 4);
        }
        r4 = sprite->data[0];
        AnimTranslateLinear(sprite);
        sprite->data[7] += sprite->sBattler / 3;
        sprite->y2 += Sin(HIBYTE(sprite->data[7]), sprite->data[5]);
        sprite->oam.affineParam += 0x100;
        if ((sprite->oam.affineParam >> 8) % 3 != 0)
            sprite->data[0] = r4;
        else
            sprite->data[0] = r4 - 1;
        if (HIBYTE(sprite->data[7]) >= 80)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] * 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] * 3) & ~1) | r7;
        }
    }
    else
    {
        if (TranslateAnimHorizontalArc(sprite))
        {
            sprite->x += sprite->x2;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->x2 = 0;
            sprite->sBattler = sprite->oam.affineParam & 0xFF;
            sprite->data[0] = 0;

            if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->introAnimActive
             && sprite->sBattler == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT))
                sprite->callback = SpriteCB_ReleaseMon2FromBall;
            else
                sprite->callback = SpriteCB_ReleaseMonFromBall;

            StartSpriteAffineAnim(sprite, 0);
        }
    }
}

static void SpriteCB_ReleaseMon2FromBall(struct Sprite *sprite)
{
    if (sprite->data[0]++ > 24)
    {
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_ReleaseMonFromBall;
    }
}

static void SpriteCB_OpponentMonSendOut(struct Sprite *sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 15)
    {
        sprite->data[0] = 0;
        if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->introAnimActive
         && sprite->sBattler == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
            sprite->callback = SpriteCB_ReleaseMon2FromBall;
        else
            sprite->callback = SpriteCB_ReleaseMonFromBall;
    }
}

#undef sBattler

static u8 AnimateBallOpenParticlesForPokeball(u8 x, u8 y, u8 kindOfStars, u8 d)
{
    return AnimateBallOpenParticles(x, y, kindOfStars, d, BALL_POKE);
}

static u8 LaunchBallFadeMonTaskForPokeball(bool8 unFadeLater, u8 battlerId, u32 arg2)
{
    return LaunchBallFadeMonTask(unFadeLater, battlerId, arg2, BALL_POKE);
}

// Pokeball in Birch intro, and when receiving via trade
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 battlerId, u8 x, u8 y, u8 oamPriority, u8 subpriortiy, u8 g, u32 h, u16 species)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[0]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[0]);
    spriteId = CreateSprite(&gBallSpriteTemplates[0], x, y, subpriortiy);

    gSprites[spriteId].data[0] = monSpriteId;
    gSprites[spriteId].data[5] = gSprites[monSpriteId].x;
    gSprites[spriteId].data[6] = gSprites[monSpriteId].y;

    gSprites[monSpriteId].x = x;
    gSprites[monSpriteId].y = y;
    gSprites[monSpriteId].data[7] = species;

    gSprites[spriteId].data[1] = g;
    gSprites[spriteId].data[2] = battlerId;
    gSprites[spriteId].data[3] = h;
    gSprites[spriteId].data[4] = h >> 0x10;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = SpriteCB_PokeballReleaseMon;

    gSprites[monSpriteId].invisible = TRUE;
}

static void SpriteCB_PokeballReleaseMon(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        u8 r5;
        u8 r7 = sprite->data[0];
        u8 battlerId = sprite->data[2];
        u32 r4 = (u16)sprite->data[3] | ((u16)sprite->data[4] << 16);

        if (sprite->subpriority != 0)
            r5 = sprite->subpriority - 1;
        else
            r5 = 0;

        StartSpriteAnim(sprite, 1);
        AnimateBallOpenParticlesForPokeball(sprite->x, sprite->y - 5, sprite->oam.priority, r5);
        sprite->data[1] = LaunchBallFadeMonTaskForPokeball(1, battlerId, r4);
        sprite->callback = SpriteCB_ReleasedMonFlyOut;
        gSprites[r7].invisible = FALSE;
        StartSpriteAffineAnim(&gSprites[r7], BATTLER_AFFINE_EMERGE);
        AnimateSprite(&gSprites[r7]);
        gSprites[r7].data[1] = 0x1000;
        sprite->data[7] = 0;
    }
    else
    {
        sprite->data[1]--;
    }
}

static void SpriteCB_ReleasedMonFlyOut(struct Sprite *sprite)
{
    bool8 r12 = FALSE;
    bool8 r6 = FALSE;
    u8 monSpriteId = sprite->data[0];
    u16 var1;
    u16 var2;

    if (sprite->animEnded)
        sprite->invisible = TRUE;
    if (gSprites[monSpriteId].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[monSpriteId], BATTLER_AFFINE_NORMAL);
        r12 = TRUE;
    }
    var1 = (sprite->data[5] - sprite->x) * sprite->data[7] / 128 + sprite->x;
    var2 = (sprite->data[6] - sprite->y) * sprite->data[7] / 128 + sprite->y;
    gSprites[monSpriteId].x = var1;
    gSprites[monSpriteId].y = var2;
    if (sprite->data[7] < 128)
    {
        s16 sine = -(gSineTable[(u8)sprite->data[7]] / 8);

        sprite->data[7] += 4;
        gSprites[monSpriteId].x2 = sine;
        gSprites[monSpriteId].y2 = sine;
    }
    else
    {
        gSprites[monSpriteId].x = sprite->data[5];
        gSprites[monSpriteId].y = sprite->data[6];
        gSprites[monSpriteId].x2 = 0;
        gSprites[monSpriteId].y2 = 0;
        r6 = TRUE;
    }
    if (sprite->animEnded && r12 && r6)
    {
        if (gSprites[monSpriteId].data[7] == SPECIES_EGG)
            DoMonFrontSpriteAnimation(&gSprites[monSpriteId], gSprites[monSpriteId].data[7], TRUE, 0);
        else
            DoMonFrontSpriteAnimation(&gSprites[monSpriteId], gSprites[monSpriteId].data[7], FALSE, 0);

        DestroySpriteAndFreeResources(sprite);
    }
}

u8 CreateTradePokeballSprite(u8 a, u8 b, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 g, u32 h)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[0]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[0]);
    spriteId = CreateSprite(&gBallSpriteTemplates[0], x, y, subPriority);
    gSprites[spriteId].data[0] = a;
    gSprites[spriteId].data[1] = g;
    gSprites[spriteId].data[2] = b;
    gSprites[spriteId].data[3] = h;
    gSprites[spriteId].data[4] = h >> 16;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = SpriteCB_TradePokeball;
    return spriteId;
}

static void SpriteCB_TradePokeball(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        u8 r6;
        u8 monSpriteId = sprite->data[0];
        u8 r8 = sprite->data[2];
        u32 r5 = (u16)sprite->data[3] | ((u16)sprite->data[4] << 16);

        if (sprite->subpriority != 0)
            r6 = sprite->subpriority - 1;
        else
            r6 = 0;

        StartSpriteAnim(sprite, 1);
        AnimateBallOpenParticlesForPokeball(sprite->x, sprite->y - 5, sprite->oam.priority, r6);
        sprite->data[1] = LaunchBallFadeMonTaskForPokeball(1, r8, r5);
        sprite->callback = SpriteCB_TradePokeballSendOff;
#ifdef BUGFIX
        // FIX: If this is used on a sprite that has previously had an affine animation, it will not
        // play the shrink anim properly due to being paused. Works together with the fix to ResetSpriteAfterAnim.
        gSprites[monSpriteId].affineAnimPaused = FALSE;
#endif // BUGFIX
        StartSpriteAffineAnim(&gSprites[monSpriteId], BATTLER_AFFINE_RETURN);
        AnimateSprite(&gSprites[monSpriteId]);
        gSprites[monSpriteId].data[1] = 0;
    }
    else
    {
        sprite->data[1]--;
    }
}

static void SpriteCB_TradePokeballSendOff(struct Sprite *sprite)
{
    u8 monSpriteId;

    sprite->data[5]++;
    if (sprite->data[5] == 11)
        PlaySE(SE_BALL_TRADE);
    monSpriteId = sprite->data[0];
    if (gSprites[monSpriteId].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[monSpriteId].invisible = TRUE;
        sprite->data[5] = 0;
        sprite->callback = SpriteCB_TradePokeballEnd;
    }
    else
    {
        gSprites[monSpriteId].data[1] += 96;
        gSprites[monSpriteId].y2 = -gSprites[monSpriteId].data[1] >> 8;
    }
}

static void SpriteCB_TradePokeballEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy;
}

static void Unref_DestroySpriteAndFreeResources(struct Sprite *sprite)
{
    DestroySpriteAndFreeResources(sprite);
}

#define sSpeedX data[0]
#define sSpeedY data[1]

#define sDelayTimer data[1]

void StartHealthboxSlideIn(u8 battlerId)
{
    struct Sprite *healthboxSprite = &gSprites[gHealthboxSpriteIds[battlerId]];

    healthboxSprite->sSpeedX = 5;
    healthboxSprite->sSpeedY = 0;
    healthboxSprite->x2 = 0x73;
    healthboxSprite->y2 = 0;
    healthboxSprite->callback = SpriteCB_HealthboxSlideIn;
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
    {
        healthboxSprite->sSpeedX = -healthboxSprite->sSpeedX;
        healthboxSprite->sSpeedY = -healthboxSprite->sSpeedY;
        healthboxSprite->x2 = -healthboxSprite->x2;
        healthboxSprite->y2 = -healthboxSprite->y2;
    }
    gSprites[healthboxSprite->data[5]].callback(&gSprites[healthboxSprite->data[5]]);
    if (GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT)
        healthboxSprite->callback = SpriteCB_HealthboxSlideInDelayed;
}

static void SpriteCB_HealthboxSlideInDelayed(struct Sprite *sprite)
{
    sprite->sDelayTimer++;
    if (sprite->sDelayTimer == 20)
    {
        sprite->sDelayTimer = 0;
        sprite->callback = SpriteCB_HealthboxSlideIn;
    }
}

static void SpriteCB_HealthboxSlideIn(struct Sprite *sprite)
{
    sprite->x2 -= sprite->sSpeedX;
    sprite->y2 -= sprite->sSpeedY;
    if (sprite->x2 == 0 && sprite->y2 == 0)
        sprite->callback = SpriteCallbackDummy;
}

#undef sSpeedX
#undef sSpeedY
#undef sDelayTimer

void DoHitAnimHealthboxEffect(u8 battlerId)
{
    u8 spriteId;

    spriteId = CreateInvisibleSpriteWithCallback(SpriteCB_HitAnimHealthoxEffect);
    gSprites[spriteId].data[0] = 1;
    gSprites[spriteId].data[1] = gHealthboxSpriteIds[battlerId];
    gSprites[spriteId].callback = SpriteCB_HitAnimHealthoxEffect;
}

static void SpriteCB_HitAnimHealthoxEffect(struct Sprite *sprite)
{
    u8 r1 = sprite->data[1];

    gSprites[r1].y2 = sprite->data[0];
    sprite->data[0] = -sprite->data[0];
    sprite->data[2]++;
    if (sprite->data[2] == 21)
    {
        gSprites[r1].x2 = 0;
        gSprites[r1].y2 = 0;
        DestroySprite(sprite);
    }
}

void LoadBallGfx(u8 ballId)
{
    u16 var;

    if (GetSpriteTileStartByTag(gBallSpriteSheets[ballId].tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[ballId]);
        LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[ballId]);
    }

    switch (ballId)
    {
    case BALL_POKE ... BALL_MASTER:
    case BALL_NET ... BALL_NEST:
    case BALL_REPEAT:
    case BALL_SAFARI:
        var = GetSpriteTileStartByTag(gBallSpriteSheets[ballId].tag);
        LZDecompressVram(gOpenPokeballGfx, (void *)(OBJ_VRAM0 + 0x100 + var * 32));
        break;
    }
}

void FreeBallGfx(u8 ballId)
{
    FreeSpriteTilesByTag(gBallSpriteSheets[ballId].tag);
    FreeSpritePaletteByTag(gBallSpritePalettes[ballId].tag);
}

static u16 GetBattlerPokeballItemId(u8 battlerId)
{
    struct Pokemon *mon, *illusionMon;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];

    illusionMon = GetIllusionMonPtr(battlerId);
    if (illusionMon != NULL)
        mon = illusionMon;

    return GetMonData(mon, MON_DATA_POKEBALL);
}

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

#define GFX_TAG_POKE_BALL    55000
#define GFX_TAG_GREAT_BALL   55001
#define GFX_TAG_SAFARI_BALL  55002
#define GFX_TAG_ULTRA_BALL   55003
#define GFX_TAG_MASTER_BALL  55004
#define GFX_TAG_NET_BALL     55005
#define GFX_TAG_DIVE_BALL    55006
#define GFX_TAG_NEST_BALL    55007
#define GFX_TAG_REPEAT_BALL  55008
#define GFX_TAG_TIMER_BALL   55009
#define GFX_TAG_LUXURY_BALL  55010
#define GFX_TAG_PREMIER_BALL 55011

const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBallGfx_Poke,    384, GFX_TAG_POKE_BALL},
    [BALL_GREAT]   = {gBallGfx_Great,   384, GFX_TAG_GREAT_BALL},
    [BALL_SAFARI]  = {gBallGfx_Safari,  384, GFX_TAG_SAFARI_BALL},
    [BALL_ULTRA]   = {gBallGfx_Ultra,   384, GFX_TAG_ULTRA_BALL},
    [BALL_MASTER]  = {gBallGfx_Master,  384, GFX_TAG_MASTER_BALL},
    [BALL_NET]     = {gBallGfx_Net,     384, GFX_TAG_NET_BALL},
    [BALL_DIVE]    = {gBallGfx_Dive,    384, GFX_TAG_DIVE_BALL},
    [BALL_NEST]    = {gBallGfx_Nest,    384, GFX_TAG_NEST_BALL},
    [BALL_REPEAT]  = {gBallGfx_Repeat,  384, GFX_TAG_REPEAT_BALL},
    [BALL_TIMER]   = {gBallGfx_Timer,   384, GFX_TAG_TIMER_BALL},
    [BALL_LUXURY]  = {gBallGfx_Luxury,  384, GFX_TAG_LUXURY_BALL},
    [BALL_PREMIER] = {gBallGfx_Premier, 384, GFX_TAG_PREMIER_BALL},
};

const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBallPal_Poke,    GFX_TAG_POKE_BALL},
    [BALL_GREAT]   = {gBallPal_Great,   GFX_TAG_GREAT_BALL},
    [BALL_SAFARI]  = {gBallPal_Safari,  GFX_TAG_SAFARI_BALL},
    [BALL_ULTRA]   = {gBallPal_Ultra,   GFX_TAG_ULTRA_BALL},
    [BALL_MASTER]  = {gBallPal_Master,  GFX_TAG_MASTER_BALL},
    [BALL_NET]     = {gBallPal_Net,     GFX_TAG_NET_BALL},
    [BALL_DIVE]    = {gBallPal_Dive,    GFX_TAG_DIVE_BALL},
    [BALL_NEST]    = {gBallPal_Nest,    GFX_TAG_NEST_BALL},
    [BALL_REPEAT]  = {gBallPal_Repeat,  GFX_TAG_REPEAT_BALL},
    [BALL_TIMER]   = {gBallPal_Timer,   GFX_TAG_TIMER_BALL},
    [BALL_LUXURY]  = {gBallPal_Luxury,  GFX_TAG_LUXURY_BALL},
    [BALL_PREMIER] = {gBallPal_Premier, GFX_TAG_PREMIER_BALL},
};

static const struct OamData sBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
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
    [BALL_POKE] =
    {
        .tileTag = GFX_TAG_POKE_BALL,
        .paletteTag = GFX_TAG_POKE_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_GREAT] =
    {
        .tileTag = GFX_TAG_GREAT_BALL,
        .paletteTag = GFX_TAG_GREAT_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_SAFARI] =
    {
        .tileTag = GFX_TAG_SAFARI_BALL,
        .paletteTag = GFX_TAG_SAFARI_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_ULTRA] =
    {
        .tileTag = GFX_TAG_ULTRA_BALL,
        .paletteTag = GFX_TAG_ULTRA_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_MASTER] =
    {
        .tileTag = GFX_TAG_MASTER_BALL,
        .paletteTag = GFX_TAG_MASTER_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_NET] =
    {
        .tileTag = GFX_TAG_NET_BALL,
        .paletteTag = GFX_TAG_NET_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_DIVE] =
    {
        .tileTag = GFX_TAG_DIVE_BALL,
        .paletteTag = GFX_TAG_DIVE_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_NEST] =
    {
        .tileTag = GFX_TAG_NEST_BALL,
        .paletteTag = GFX_TAG_NEST_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_REPEAT] =
    {
        .tileTag = GFX_TAG_REPEAT_BALL,
        .paletteTag = GFX_TAG_REPEAT_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_TIMER] =
    {
        .tileTag = GFX_TAG_TIMER_BALL,
        .paletteTag = GFX_TAG_TIMER_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_LUXURY] =
    {
        .tileTag = GFX_TAG_LUXURY_BALL,
        .paletteTag = GFX_TAG_LUXURY_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_BallThrow,
    },
    [BALL_PREMIER] =
    {
        .tileTag = GFX_TAG_PREMIER_BALL,
        .paletteTag = GFX_TAG_PREMIER_BALL,
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
    gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive = TRUE;

    taskId = CreateTask(Task_DoPokeballSendOutAnim, 5);
    gTasks[taskId].tPan = pan;
    gTasks[taskId].tThrowId = kindOfThrow;
    gTasks[taskId].tBattler = gActiveBattler;

    return 0;
}

#define sBattler         data[6]

static void Task_DoPokeballSendOutAnim(u8 taskId)
{
    u16 throwCaseId;
    u8 battlerId;
    u16 itemId, ballId;
    u8 ballSpriteId;
    bool8 notSendOut = FALSE;

    if (gTasks[taskId].tFrames == 0)
    {
        gTasks[taskId].tFrames++;
        return;
    }

    throwCaseId = gTasks[taskId].tThrowId;
    battlerId = gTasks[taskId].tBattler;

    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        itemId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
    else
        itemId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(itemId);
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
    gSprites[ballSpriteId].data[0] = 34;
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
        sprite->affineAnimPaused = TRUE;
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[5] = 0;
        ballId = ItemIdToBallId(GetBattlerPokeballItemId(opponentBattler));
        AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
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
    struct Pokemon *mon = (void *)(u32)((gTasks[taskId].tCryTaskMonPtr1 << 16) | (u16)(gTasks[taskId].tCryTaskMonPtr2));

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
    AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
    sprite->data[0] = LaunchBallFadeMonTask(TRUE, sprite->sBattler, 14, ballId);
    sprite->callback = HandleBallAnimEnd;

    if (gMain.inBattle)
    {
        struct Pokemon *mon;
        u16 species;
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

        species = GetMonData(mon, MON_DATA_SPECIES);
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
        gTasks[taskId].tCryTaskSpecies = species;
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
        gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = FALSE;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);

        for (doneBattlers = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[i].ballAnimActive == FALSE)
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
            gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = FALSE;
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

#undef HIBYTE

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

static u8 AnimateBallOpenParticlesForPokeball(u8 x, u8 y, u8 kindOfStars, u8 subpriority)
{
    return AnimateBallOpenParticles(x, y, kindOfStars, subpriority, BALL_POKE);
}

static u8 LaunchBallFadeMonTaskForPokeball(bool8 unFadeLater, u8 spritePalNum, u32 selectedPalettes)
{
    return LaunchBallFadeMonTask(unFadeLater, spritePalNum, selectedPalettes, BALL_POKE);
}

// Sprite data for the Pokémon
#define sSpecies data[7]

// Sprite data for the Poké Ball
#define sMonSpriteId data[0]
#define sDelay       data[1]
#define sMonPalNum   data[2]
#define sFadePalsLo  data[3]
#define sFadePalsHi  data[4]
#define sFinalMonX   data[5]
#define sFinalMonY   data[6]
#define sTrigIdx     data[7]

// Poké Ball in Birch intro, and when receiving via trade
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subpriority, u8 delay, u32 fadePalettes, u16 species)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[BALL_POKE]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[BALL_POKE]);
    spriteId = CreateSprite(&gBallSpriteTemplates[BALL_POKE], x, y, subpriority);

    gSprites[spriteId].sMonSpriteId = monSpriteId;
    gSprites[spriteId].sFinalMonX = gSprites[monSpriteId].x;
    gSprites[spriteId].sFinalMonY = gSprites[monSpriteId].y;

    gSprites[monSpriteId].x = x;
    gSprites[monSpriteId].y = y;
    gSprites[monSpriteId].sSpecies = species;

    gSprites[spriteId].sDelay = delay;
    gSprites[spriteId].sMonPalNum = monPalNum;
    gSprites[spriteId].sFadePalsLo = fadePalettes;
    gSprites[spriteId].sFadePalsHi = fadePalettes >> 16;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = SpriteCB_PokeballReleaseMon;

    gSprites[monSpriteId].invisible = TRUE;
}

static void SpriteCB_PokeballReleaseMon(struct Sprite *sprite)
{
    if (sprite->sDelay == 0)
    {
        u8 subpriority;
        u8 spriteId = sprite->sMonSpriteId;
        u8 monPalNum = sprite->sMonPalNum;
        u32 selectedPalettes = (u16)sprite->sFadePalsLo | ((u16)sprite->sFadePalsHi << 16);

        if (sprite->subpriority != 0)
            subpriority = sprite->subpriority - 1;
        else
            subpriority = 0;

        StartSpriteAnim(sprite, 1);
        AnimateBallOpenParticlesForPokeball(sprite->x, sprite->y - 5, sprite->oam.priority, subpriority);
        // sDelay re-used to store task id but never read
        sprite->sDelay = LaunchBallFadeMonTaskForPokeball(TRUE, monPalNum, selectedPalettes);
        sprite->callback = SpriteCB_ReleasedMonFlyOut;
        gSprites[spriteId].invisible = FALSE;
        StartSpriteAffineAnim(&gSprites[spriteId], BATTLER_AFFINE_EMERGE);
        AnimateSprite(&gSprites[spriteId]);
        gSprites[spriteId].data[1] = 0x1000;
        sprite->sTrigIdx = 0;
    }
    else
    {
        sprite->sDelay--;
    }
}

static void SpriteCB_ReleasedMonFlyOut(struct Sprite *sprite)
{
    bool8 emergeAnimFinished = FALSE;
    bool8 atFinalPosition = FALSE;
    u8 monSpriteId = sprite->sMonSpriteId;
    u16 x, y;

    if (sprite->animEnded)
        sprite->invisible = TRUE;

    if (gSprites[monSpriteId].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[monSpriteId], BATTLER_AFFINE_NORMAL);
        emergeAnimFinished = TRUE;
    }

    x = (sprite->sFinalMonX - sprite->x) * sprite->sTrigIdx / 128 + sprite->x;
    y = (sprite->sFinalMonY - sprite->y) * sprite->sTrigIdx / 128 + sprite->y;
    gSprites[monSpriteId].x = x;
    gSprites[monSpriteId].y = y;

    if (sprite->sTrigIdx < 128)
    {
        s16 sine = -(gSineTable[(u8)sprite->sTrigIdx] / 8);

        sprite->sTrigIdx += 4;
        gSprites[monSpriteId].x2 = sine;
        gSprites[monSpriteId].y2 = sine;
    }
    else
    {
        gSprites[monSpriteId].x = sprite->sFinalMonX;
        gSprites[monSpriteId].y = sprite->sFinalMonY;
        gSprites[monSpriteId].x2 = 0;
        gSprites[monSpriteId].y2 = 0;
        atFinalPosition = TRUE;
    }
    if (sprite->animEnded && emergeAnimFinished && atFinalPosition)
    {
        if (gSprites[monSpriteId].sSpecies == SPECIES_EGG)
            DoMonFrontSpriteAnimation(&gSprites[monSpriteId], gSprites[monSpriteId].sSpecies, TRUE, 0);
        else
            DoMonFrontSpriteAnimation(&gSprites[monSpriteId], gSprites[monSpriteId].sSpecies, FALSE, 0);

        DestroySpriteAndFreeResources(sprite);
    }
}

#undef sSpecies
#undef sFinalMonX
#undef sFinalMonY
#undef sTrigIdx

#define sTimer       data[5]

u8 CreateTradePokeballSprite(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 delay, u32 fadePalettes)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[BALL_POKE]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[BALL_POKE]);
    spriteId = CreateSprite(&gBallSpriteTemplates[BALL_POKE], x, y, subPriority);
    gSprites[spriteId].sMonSpriteId = monSpriteId;
    gSprites[spriteId].sDelay = delay;
    gSprites[spriteId].sMonPalNum = monPalNum;
    gSprites[spriteId].sFadePalsLo = fadePalettes;
    gSprites[spriteId].sFadePalsHi = fadePalettes >> 16;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = SpriteCB_TradePokeball;
    return spriteId;
}

static void SpriteCB_TradePokeball(struct Sprite *sprite)
{
    if (sprite->sDelay == 0)
    {
        u8 subpriority;
        u8 monSpriteId = sprite->sMonSpriteId;
        u8 monPalNum = sprite->sMonPalNum;
        u32 selectedPalettes = (u16)sprite->sFadePalsLo | ((u16)sprite->sFadePalsHi << 16);

        if (sprite->subpriority != 0)
            subpriority = sprite->subpriority - 1;
        else
            subpriority = 0;

        StartSpriteAnim(sprite, 1);
        AnimateBallOpenParticlesForPokeball(sprite->x, sprite->y - 5, sprite->oam.priority, subpriority);
        // sDelay re-used to store task id but never read
        sprite->sDelay = LaunchBallFadeMonTaskForPokeball(TRUE, monPalNum, selectedPalettes);
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
        sprite->sDelay--;
    }
}

static void SpriteCB_TradePokeballSendOff(struct Sprite *sprite)
{
    u8 monSpriteId;

    sprite->sTimer++;
    if (sprite->sTimer == 11)
        PlaySE(SE_BALL_TRADE);

    monSpriteId = sprite->sMonSpriteId;
    if (gSprites[monSpriteId].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[monSpriteId].invisible = TRUE;
        sprite->sTimer = 0;
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

#undef sMonSpriteId
#undef sDelay
#undef sMonPalNum
#undef sFadePalsLo
#undef sFadePalsHi
#undef sTimer

// Unreferenced here and in RS, but used in FRLG, possibly by mistake.
static void UNUSED DestroySpriteAndFreeResources_Ball(struct Sprite *sprite)
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
    case BALL_DIVE:
    case BALL_LUXURY:
    case BALL_PREMIER:
        break;
    default:
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
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
    else
        return GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
}

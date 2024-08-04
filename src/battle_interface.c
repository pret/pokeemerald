#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_z_move.h"
#include "graphics.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "sound.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"
#include "battle_anim.h"
#include "data.h"
#include "pokemon_summary_screen.h"
#include "strings.h"
#include "battle_debug.h"
#include "item.h"
#include "item_icon.h"
#include "item_use.h"
#include "test_runner.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "level_caps.h"

enum
{   // Corresponds to gHealthboxElementsGfxTable (and the tables after it) in graphics.c
    // These are indexes into the tables, which are filled with 8x8 square pixel data.
    HEALTHBOX_GFX_0, //hp bar [black section]
    HEALTHBOX_GFX_1, //hp bar "H"
    HEALTHBOX_GFX_2, //hp bar "P"
    HEALTHBOX_GFX_HP_BAR_GREEN, //hp bar [0 pixels]
    HEALTHBOX_GFX_4,  //hp bar [1 pixels]
    HEALTHBOX_GFX_5,  //hp bar [2 pixels]
    HEALTHBOX_GFX_6,  //hp bar [3 pixels]
    HEALTHBOX_GFX_7,  //hp bar [4 pixels]
    HEALTHBOX_GFX_8,  //hp bar [5 pixels]
    HEALTHBOX_GFX_9,  //hp bar [6 pixels]
    HEALTHBOX_GFX_10, //hp bar [7 pixels]
    HEALTHBOX_GFX_11, //hp bar [8 pixels]
    HEALTHBOX_GFX_12, //exp bar [0 pixels]
    HEALTHBOX_GFX_13, //exp bar [1 pixels]
    HEALTHBOX_GFX_14, //exp bar [2 pixels]
    HEALTHBOX_GFX_15, //exp bar [3 pixels]
    HEALTHBOX_GFX_16, //exp bar [4 pixels]
    HEALTHBOX_GFX_17, //exp bar [5 pixels]
    HEALTHBOX_GFX_18, //exp bar [6 pixels]
    HEALTHBOX_GFX_19, //exp bar [7 pixels]
    HEALTHBOX_GFX_20, //exp bar [8 pixels]
    HEALTHBOX_GFX_STATUS_PSN_BATTLER0,  //status psn "(P"
    HEALTHBOX_GFX_22,                   //status psn "SN"
    HEALTHBOX_GFX_23,                   //status psn "|)""
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER0,  //status prz
    HEALTHBOX_GFX_25,
    HEALTHBOX_GFX_26,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER0,  //status slp
    HEALTHBOX_GFX_28,
    HEALTHBOX_GFX_29,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER0,  //status frz
    HEALTHBOX_GFX_31,
    HEALTHBOX_GFX_32,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER0,  //status brn
    HEALTHBOX_GFX_34,
    HEALTHBOX_GFX_35,
    HEALTHBOX_GFX_STATUS_FRB_BATTLER0,  //status frb
    HEALTHBOX_GFX_116,
    HEALTHBOX_GFX_117,
    HEALTHBOX_GFX_36, //misc [Black section]
    HEALTHBOX_GFX_37, //misc [Black section]
    HEALTHBOX_GFX_38, //misc [Black section]
    HEALTHBOX_GFX_39, //misc [Blank Health Window?]
    HEALTHBOX_GFX_40, //misc [Blank Health Window?]
    HEALTHBOX_GFX_41, //misc [Blank Health Window?]
    HEALTHBOX_GFX_42, //misc [Blank Health Window?]
    HEALTHBOX_GFX_43, //misc [Top of Health Window?]
    HEALTHBOX_GFX_44, //misc [Top of Health Window?]
    HEALTHBOX_GFX_45, //misc [Top of Health Window?]
    HEALTHBOX_GFX_46, //misc [Blank Health Window?]
    HEALTHBOX_GFX_HP_BAR_YELLOW, //hp bar yellow [0 pixels]
    HEALTHBOX_GFX_48, //hp bar yellow [1 pixels]
    HEALTHBOX_GFX_49, //hp bar yellow [2 pixels]
    HEALTHBOX_GFX_50, //hp bar yellow [3 pixels]
    HEALTHBOX_GFX_51, //hp bar yellow [4 pixels]
    HEALTHBOX_GFX_52, //hp bar yellow [5 pixels]
    HEALTHBOX_GFX_53, //hp bar yellow [6 pixels]
    HEALTHBOX_GFX_54, //hp bar yellow [7 pixels]
    HEALTHBOX_GFX_55, //hp bar yellow [8 pixels]
    HEALTHBOX_GFX_HP_BAR_RED,  //hp bar red [0 pixels]
    HEALTHBOX_GFX_57, //hp bar red [1 pixels]
    HEALTHBOX_GFX_58, //hp bar red [2 pixels]
    HEALTHBOX_GFX_59, //hp bar red [3 pixels]
    HEALTHBOX_GFX_60, //hp bar red [4 pixels]
    HEALTHBOX_GFX_61, //hp bar red [5 pixels]
    HEALTHBOX_GFX_62, //hp bar red [6 pixels]
    HEALTHBOX_GFX_63, //hp bar red [7 pixels]
    HEALTHBOX_GFX_64, //hp bar red [8 pixels]
    HEALTHBOX_GFX_65, //hp bar frame end
    HEALTHBOX_GFX_STATUS_BALL, // Full
    HEALTHBOX_GFX_STATUS_BALL_EMPTY,
    HEALTHBOX_GFX_STATUS_BALL_FAINTED,
    HEALTHBOX_GFX_STATUS_BALL_STATUSED,
    HEALTHBOX_GFX_STATUS_BALL_CAUGHT,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER1, //status2 "PSN"
    HEALTHBOX_GFX_72,
    HEALTHBOX_GFX_73,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER1, //status2 "PRZ"
    HEALTHBOX_GFX_75,
    HEALTHBOX_GFX_76,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER1, //status2 "SLP"
    HEALTHBOX_GFX_78,
    HEALTHBOX_GFX_79,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER1, //status2 "FRZ"
    HEALTHBOX_GFX_81,
    HEALTHBOX_GFX_82,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER1, //status2 "BRN"
    HEALTHBOX_GFX_84,
    HEALTHBOX_GFX_85,
    HEALTHBOX_GFX_STATUS_FRB_BATTLER1, //status2 "FRB"
    HEALTHBOX_GFX_118,
    HEALTHBOX_GFX_119,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER2, //status3 "PSN"
    HEALTHBOX_GFX_87,
    HEALTHBOX_GFX_88,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER2, //status3 "PRZ"
    HEALTHBOX_GFX_90,
    HEALTHBOX_GFX_91,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER2, //status3 "SLP"
    HEALTHBOX_GFX_93,
    HEALTHBOX_GFX_94,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER2, //status3 "FRZ"
    HEALTHBOX_GFX_96,
    HEALTHBOX_GFX_97,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER2, //status3 "BRN"
    HEALTHBOX_GFX_99,
    HEALTHBOX_GFX_100,
    HEALTHBOX_GFX_STATUS_FRB_BATTLER2, //status3 "FRB"
    HEALTHBOX_GFX_120,
    HEALTHBOX_GFX_121,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER3, //status4 "PSN"
    HEALTHBOX_GFX_102,
    HEALTHBOX_GFX_103,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER3, //status4 "PRZ"
    HEALTHBOX_GFX_105,
    HEALTHBOX_GFX_106,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER3, //status4 "SLP"
    HEALTHBOX_GFX_108,
    HEALTHBOX_GFX_109,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER3, //status4 "FRZ"
    HEALTHBOX_GFX_111,
    HEALTHBOX_GFX_112,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER3, //status4 "BRN"
    HEALTHBOX_GFX_114,
    HEALTHBOX_GFX_115,
    HEALTHBOX_GFX_STATUS_FRB_BATTLER3, //status4 "FRB"
    HEALTHBOX_GFX_122,
    HEALTHBOX_GFX_123,
    HEALTHBOX_GFX_FRAME_END,
    HEALTHBOX_GFX_FRAME_END_BAR,
};

static const u8 *GetHealthboxElementGfxPtr(u8);
static u8 *AddTextPrinterAndCreateWindowOnHealthbox(const u8 *, u32, u32, u32, u32 *);
static u8 *AddTextPrinterAndCreateWindowOnHealthboxToFit(const u8 *, u32, u32, u32, u32 *, u32);

static void RemoveWindowOnHealthbox(u32 windowId);
static void UpdateHpTextInHealthboxInDoubles(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp);
static void UpdateStatusIconInHealthbox(u8);

static void TextIntoHealthboxObject(void *, u8 *, s32);
static void SafariTextIntoHealthboxObject(void *, u8 *, u32);
static void HpTextIntoHealthboxObject(void *, u8 *, u32);
static void FillHealthboxObject(void *, u32, u32);

static void Task_HidePartyStatusSummary_BattleStart_1(u8);
static void Task_HidePartyStatusSummary_BattleStart_2(u8);
static void Task_HidePartyStatusSummary_DuringBattle(u8);

static void SpriteCB_HealthBoxOther(struct Sprite *);
static void SpriteCB_HealthBar(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *);

static u8 GetStatusIconForBattlerId(u8, u8);
static s32 CalcNewBarValue(s32, s32, s32, s32 *, u8, u16);
static u8 GetScaledExpFraction(s32, s32, s32, u8);
static void MoveBattleBarGraphically(u8, u8);
static u8 CalcBarFilledPixels(s32, s32, s32, s32 *, u8 *, u8);

static void SpriteCb_AbilityPopUp(struct Sprite *);
static void Task_FreeAbilityPopUpGfx(u8);

static void SpriteCB_LastUsedBall(struct Sprite *);
static void SpriteCB_LastUsedBallWin(struct Sprite *);

static const struct OamData sOamData_64x32 =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sHealthboxPlayerSpriteTemplates[2] =
{
    {
        .tileTag = TAG_HEALTHBOX_PLAYER1_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_PLAYER2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate sHealthboxOpponentSpriteTemplates[2] =
{
    {
        .tileTag = TAG_HEALTHBOX_OPPONENT1_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_OPPONENT2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate sHealthboxSafariSpriteTemplate =
{
    .tileTag = TAG_HEALTHBOX_SAFARI_TILE,
    .paletteTag = TAG_HEALTHBOX_PAL,
    .oam = &sOamData_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_Healthbar =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sHealthbarSpriteTemplates[MAX_BATTLERS_COUNT] =
{
    {
        .tileTag = TAG_HEALTHBAR_PLAYER1_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_OPPONENT1_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_PLAYER2_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_OPPONENT2_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    }
};

/*  v-- Origin
[0  +  ][1     ]   64x8
*/
static const struct Subsprite sHealthBar_Subsprites_Player[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    }
};

/*       v-- Origin
[]  [0  +  ][1     ]   8x8 + 64x8
2^ ^--- Note 8px space
*/
static const struct Subsprite sHealthBar_Subsprites_Opponent[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 8,
        .priority = 1
    }
};

static const struct SubspriteTable sHealthBar_SubspriteTables[] =
{
    [B_SIDE_PLAYER]   = {ARRAY_COUNT(sHealthBar_Subsprites_Player), sHealthBar_Subsprites_Player},
    [B_SIDE_OPPONENT] = {ARRAY_COUNT(sHealthBar_Subsprites_Opponent), sHealthBar_Subsprites_Opponent}
};
/*                      v-- Origin
[0     ][1     ][2     ][3     ]   128x8
*/
static const struct Subsprite sStatusSummaryBar_Subsprites_Enter[] =
{
    {
        .x = 32 * -3,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 32 * -2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = 32 * -1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    }
};

/*                      v-- Origin
[0     ][1     ][2     ][3     ][4     ][5     ]   192x8
                 ^-- uses same tiles --^
*/
static const struct Subsprite sStatusSummaryBar_Subsprites_Exit[] =
{
    {
        .x = 32 * -3,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 32 * -2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = 32 * -1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    }
};

static const struct SubspriteTable sStatusSummaryBar_SubspriteTable_Enter[] =
{
    {ARRAY_COUNT(sStatusSummaryBar_Subsprites_Enter), sStatusSummaryBar_Subsprites_Enter}
};

static const struct SubspriteTable sStatusSummaryBar_SubspriteTable_Exit[] =
{
    {ARRAY_COUNT(sStatusSummaryBar_Subsprites_Exit), sStatusSummaryBar_Subsprites_Exit}
};

static const struct CompressedSpriteSheet sStatusSummaryBarSpriteSheet =
{
    gBattleInterface_BallStatusBarGfx, 0x200, TAG_STATUS_SUMMARY_BAR_TILE
};

static const struct SpritePalette sStatusSummaryBarSpritePal =
{
    gBattleInterface_BallStatusBarPal, TAG_STATUS_SUMMARY_BAR_PAL
};

static const struct SpritePalette sStatusSummaryBallsSpritePal =
{
    gBattleInterface_BallDisplayPal, TAG_STATUS_SUMMARY_BALLS_PAL
};

static const struct SpriteSheet sStatusSummaryBallsSpriteSheet =
{
    &gHealthboxElementsGfxTable[HEALTHBOX_GFX_STATUS_BALL], 0x80, TAG_STATUS_SUMMARY_BALLS_TILE
};

static const struct OamData sOamData_StatusSummaryBalls =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sStatusSummaryBarSpriteTemplates[2] =
{
    { // Player
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar_Enter
    },
    { // Opponent
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar_Enter
    }
};

static const struct SpriteTemplate sStatusSummaryBallsSpriteTemplates[2] =
{
    {
        .tileTag = TAG_STATUS_SUMMARY_BALLS_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BALLS_PAL,
        .oam = &sOamData_StatusSummaryBalls,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBalls_Enter
    },
    {
        .tileTag = TAG_STATUS_SUMMARY_BALLS_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BALLS_PAL,
        .oam = &sOamData_StatusSummaryBalls,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBalls_Enter
    }
};

static const u8 sEmptyWhiteText_GrayHighlight[] = __("{COLOR WHITE}{HIGHLIGHT DARK_GRAY}              ");
static const u8 sEmptyWhiteText_TransparentHighlight[] = __("{COLOR WHITE}{HIGHLIGHT TRANSPARENT}              ");

enum
{
    PAL_STATUS_PSN,
    PAL_STATUS_PAR,
    PAL_STATUS_SLP,
    PAL_STATUS_FRZ,
    PAL_STATUS_BRN
};

static const u16 sStatusIconColors[] =
{
    [PAL_STATUS_PSN] = RGB(24, 12, 24),
    [PAL_STATUS_PAR] = RGB(23, 23, 3),
    [PAL_STATUS_SLP] = RGB(20, 20, 17),
    [PAL_STATUS_FRZ] = RGB(17, 22, 28),
    [PAL_STATUS_BRN] = RGB(28, 14, 10),
};

static const struct WindowTemplate sHealthboxWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 8,
    .height = 2,
    .paletteNum = 0,
    .baseBlock = 0
};

// Because the healthbox is too large to fit into one sprite, it is divided into two sprites.
// healthboxLeft  or healthboxMain  is the left part that is used as the 'main' sprite.
// healthboxRight or healthboxOther is the right part of the healthbox.
// There's also the third sprite under name of healthbarSprite that refers to the healthbar visible on the healtbox.

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_HealthBarSpriteId     data[5]
#define hMain_Battler               data[6]
#define hMain_Data7                 data[7]

// data fields for healthboxRight
#define hOther_HealthBoxSpriteId    data[5]

// data fields for healthbar
#define hBar_HealthBoxSpriteId      data[5]
#define hBar_Data6                  data[6]

// This function is here to cover a specific case - one player's mon in a 2 vs 1 double battle. In this scenario - display singles layout.
// The same goes for a 2 vs 1 where opponent has only one pokemon.
u32 WhichBattleCoords(u32 battlerId) // 0 - singles, 1 - doubles
{
    if (GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT
        && gPlayerPartyCount == 1
        && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        return 0;
    else if (GetBattlerPosition(battlerId) == B_POSITION_OPPONENT_LEFT
             && gEnemyPartyCount == 1
             && !(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
        return 0;
    else
        return IsDoubleBattle();
}

u8 CreateBattlerHealthboxSprites(u8 battlerId)
{
    s16 data6 = 0;
    u8 healthboxLeftSpriteId, healthboxRightSpriteId;
    u8 healthbarSpriteId;
    struct Sprite *healthBarSpritePtr;

    if (WhichBattleCoords(battlerId) == 0) // Singles
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;

            gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;
            gSprites[healthboxRightSpriteId].oam.tileNum += 64;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxRightSpriteId].oam.tileNum += 32;

            data6 = 2;
        }
        gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

        gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
        gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;
    }
    else
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 1;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 2;
        }
    }

    healthbarSpriteId = CreateSpriteAtEnd(&sHealthbarSpriteTemplates[gBattlerPositions[battlerId]], 140, 60, 0);
    healthBarSpritePtr = &gSprites[healthbarSpriteId];
    SetSubspriteTables(healthBarSpritePtr, &sHealthBar_SubspriteTables[GetBattlerSide(battlerId)]);
    healthBarSpritePtr->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    healthBarSpritePtr->oam.priority = 1;

    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + healthBarSpritePtr->oam.tileNum * TILE_SIZE_4BPP), 64);

    gSprites[healthboxLeftSpriteId].hMain_HealthBarSpriteId = healthbarSpriteId;
    gSprites[healthboxLeftSpriteId].hMain_Battler = battlerId;
    gSprites[healthboxLeftSpriteId].invisible = TRUE;

    gSprites[healthboxRightSpriteId].invisible = TRUE;

    healthBarSpritePtr->hBar_HealthBoxSpriteId = healthboxLeftSpriteId;
    healthBarSpritePtr->hBar_Data6 = data6;
    healthBarSpritePtr->invisible = TRUE;

    CreateIndicatorSprite(battlerId);

    gBattleStruct->ballSpriteIds[0] = MAX_SPRITES;
    gBattleStruct->ballSpriteIds[1] = MAX_SPRITES;

    return healthboxLeftSpriteId;
}

u8 CreateSafariPlayerHealthboxSprites(void)
{
    u8 healthboxLeftSpriteId, healthboxRightSpriteId;

    healthboxLeftSpriteId = CreateSprite(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
    healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

    gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;
    gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;

    gSprites[healthboxRightSpriteId].oam.tileNum += 64;

    gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;
    gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;

    gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

    return healthboxLeftSpriteId;
}

static const u8 *GetHealthboxElementGfxPtr(u8 elementId)
{
    return gHealthboxElementsGfxTable[elementId];
}

// Syncs the position of healthbar accordingly with the healthbox.
static void SpriteCB_HealthBar(struct Sprite *sprite)
{
    u8 healthboxSpriteId = sprite->hBar_HealthBoxSpriteId;

    switch (sprite->hBar_Data6)
    {
    case 0:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 1:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 2:
    default:
        sprite->x = gSprites[healthboxSpriteId].x + 8;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    }

    sprite->x2 = gSprites[healthboxSpriteId].x2;
    sprite->y2 = gSprites[healthboxSpriteId].y2;
}

static void SpriteCB_HealthBoxOther(struct Sprite *sprite)
{
    u8 healthboxMainSpriteId = sprite->hOther_HealthBoxSpriteId;

    sprite->x = gSprites[healthboxMainSpriteId].x + 64;
    sprite->y = gSprites[healthboxMainSpriteId].y;

    sprite->x2 = gSprites[healthboxMainSpriteId].x2;
    sprite->y2 = gSprites[healthboxMainSpriteId].y2;
}

void SetBattleBarStruct(u8 battlerId, u8 healthboxSpriteId, s32 maxVal, s32 oldVal, s32 receivedValue)
{
    gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId = healthboxSpriteId;
    gBattleSpritesDataPtr->battleBars[battlerId].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[battlerId].oldValue = oldVal;
    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue = receivedValue;
    gBattleSpritesDataPtr->battleBars[battlerId].currValue = -32768;
}

void SetHealthboxSpriteInvisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = TRUE;
    UpdateIndicatorVisibilityAndType(healthboxSpriteId, TRUE);
}

void SetHealthboxSpriteVisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = FALSE;
    UpdateIndicatorVisibilityAndType(healthboxSpriteId, FALSE);
}

static void UpdateSpritePos(u8 spriteId, s16 x, s16 y)
{
    gSprites[spriteId].x = x;
    gSprites[spriteId].y = y;
}

void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBattlerOnly)
{

}

static void TryToggleHealboxVisibility(u32 priority, u32 healthboxLeftSpriteId, u32 healthboxRightSpriteId, u32 healthbarSpriteId)
{
    bool32 invisible = FALSE;

    if (priority == 0)  // start of anim -> make invisible
        invisible = TRUE;
    else if (priority == 1) // end of anim -> make visible
        invisible = FALSE;

    gSprites[healthboxLeftSpriteId].invisible = invisible;
    gSprites[healthboxRightSpriteId].invisible = invisible;
    gSprites[healthbarSpriteId].invisible = invisible;

    UpdateIndicatorVisibilityAndType(healthboxLeftSpriteId, invisible);
}

void UpdateOamPriorityInAllHealthboxes(u8 priority, bool32 hideHPBoxes)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        u8 healthboxLeftSpriteId = gHealthboxSpriteIds[i];
        u8 healthboxRightSpriteId = gSprites[gHealthboxSpriteIds[i]].oam.affineParam;
        u8 healthbarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

        gSprites[healthboxLeftSpriteId].oam.priority = priority;
        gSprites[healthboxRightSpriteId].oam.priority = priority;
        gSprites[healthbarSpriteId].oam.priority = priority;

        UpdateIndicatorOamPriority(healthboxLeftSpriteId, priority);

        if (B_HIDE_HEALTHBOX_IN_ANIMS == TRUE && hideHPBoxes && IsBattlerAlive(i))
            TryToggleHealboxVisibility(priority, healthboxLeftSpriteId, healthboxRightSpriteId, healthbarSpriteId);
    }
}

void GetBattlerHealthboxCoords(u8 battler, s16 *x, s16 *y)
{
    *x = 0, *y = 0;

    if (!WhichBattleCoords(battler))
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            *x = 44, *y = 30;
        else
            *x = 158, *y = 88;
    }
    else
    {
        switch (GetBattlerPosition(battler))
        {
        case B_POSITION_PLAYER_LEFT:
            *x = 159, *y = 76;
            break;
        case B_POSITION_PLAYER_RIGHT:
            *x = 171, *y = 101;
            break;
        case B_POSITION_OPPONENT_LEFT:
            *x = 44, *y = 19;
            break;
        case B_POSITION_OPPONENT_RIGHT:
            *x = 32, *y = 44;
            break;
        }
    }
}

void InitBattlerHealthboxCoords(u8 battler)
{
    s16 x, y;

    GetBattlerHealthboxCoords(battler, &x, &y);
    UpdateSpritePos(gHealthboxSpriteIds[battler], x, y);
}

static void UpdateLvlInHealthbox(u8 healthboxSpriteId, u8 lvl)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;
    u8 text[16];
    u32 xPos;
    u8 *objVram;
    u8 battler = gSprites[healthboxSpriteId].hMain_Battler;

    // Don't print Lv char if mon has a gimmick with an indicator active.
    if (GetIndicatorTileTag(battler) != TAG_NONE)
    {
        objVram = ConvertIntToDecimalStringN(text, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        xPos = 5 * (3 - (objVram - (text + 2))) - 1;
        UpdateIndicatorLevelData(healthboxSpriteId, lvl);
        UpdateIndicatorVisibilityAndType(healthboxSpriteId, FALSE);
    }
    else
    {
        text[0] = CHAR_EXTRA_SYMBOL;
        text[1] = CHAR_LV_2;

        objVram = ConvertIntToDecimalStringN(text + 2, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        xPos = 5 * (3 - (objVram - (text + 2)));
        UpdateIndicatorVisibilityAndType(healthboxSpriteId, TRUE);
    }

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, xPos, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
    {
        objVram = (void *)(OBJ_VRAM0);
        if (!WhichBattleCoords(battler))
            objVram += spriteTileNum + 0x820;
        else
            objVram += spriteTileNum + 0x420;
    }
    else
    {
        objVram = (void *)(OBJ_VRAM0);
        objVram += spriteTileNum + 0x400;
    }
    TextIntoHealthboxObject(objVram, windowTileData, 3);
    RemoveWindowOnHealthbox(windowId);
}

static void PrintHpOnHealthbox(u32 spriteId, s16 currHp, s16 maxHp, u32 bgColor, u32 rightTile, u32 leftTile)
{
    u8 *windowTileData;
    u32 windowId, tilesCount, x;
    u8 text[28], *txtPtr;
    void *objVram = (void *)(OBJ_VRAM0) + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP;

    // To fit 4 digit HP values we need to modify a bit the way hp is printed on Healthbox.
    // 6 chars can fit on the right healthbox, the rest goes to the left one
    txtPtr = ConvertIntToDecimalStringN(text, currHp, STR_CONV_MODE_RIGHT_ALIGN, 4);
    *txtPtr++ = CHAR_SLASH;
    txtPtr = ConvertIntToDecimalStringN(txtPtr, maxHp, STR_CONV_MODE_LEFT_ALIGN, 4);
    // Print last 6 chars on the right window
    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(txtPtr - 6, 0, 5, bgColor, &windowId);
    HpTextIntoHealthboxObject(objVram + rightTile, windowTileData, 4);
    RemoveWindowOnHealthbox(windowId);
    // Print the rest of the chars on the left window
    txtPtr[-6] = EOS;
    // if max hp is 3 digits print on block closer to the right window, if 4 digits print further from the right window
    if (maxHp >= 1000)
        x = 9, tilesCount = 3;
    else
        x = 6, tilesCount = 2, leftTile += 0x20;
    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, x, 5, bgColor, &windowId);
    HpTextIntoHealthboxObject(objVram + leftTile, windowTileData, tilesCount);
    RemoveWindowOnHealthbox(windowId);
}

// Note: this is only possible to trigger via debug, it was an unused GF function.
static void UpdateOpponentHpTextDoubles(u32 healthboxSpriteId, u32 barSpriteId, s16 value, u8 maxOrCurrent)
{
    u8 text[32], *txtPtr;
    u32 i, var;
    u32 battlerId = gSprites[healthboxSpriteId].hMain_Battler;

    if (gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars) // don't print text if only bars are visible
    {
        memcpy(text, sEmptyWhiteText_TransparentHighlight, sizeof(sEmptyWhiteText_TransparentHighlight));
        if (maxOrCurrent == HP_CURRENT)
            var = 0;
        else
            var = 4;

        txtPtr = ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
        if (!maxOrCurrent)
            StringCopy(txtPtr, gText_Slash);
        RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

        for (i = var; i < var + 3; i++)
        {
            if (i < 3)
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                      (void *)((OBJ_VRAM0) + 32 * (1 + gSprites[barSpriteId].oam.tileNum + i)),
                      0x20);
            }
            else
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                      (void *)((OBJ_VRAM0 + 0x20) + 32 * (i + gSprites[barSpriteId].oam.tileNum)),
                      0x20);
            }
        }

        if (maxOrCurrent == HP_CURRENT)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[224],
                      (void *)((OBJ_VRAM0) + ((gSprites[barSpriteId].oam.tileNum + 4) * TILE_SIZE_4BPP)),
                      0x20);
            CpuFill32(0, (void *)((OBJ_VRAM0) + (gSprites[barSpriteId].oam.tileNum * TILE_SIZE_4BPP)), 0x20);
        }
    }
}

// Same with this one.
static void UpdateOpponentHpTextSingles(u32 healthboxSpriteId, s16 value, u32 maxOrCurrent)
{
    u8 text[32];
    u32 var, i;
    u32 battler = gSprites[healthboxSpriteId].hMain_Battler;

    memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
    if (gBattleSpritesDataPtr->battlerData[battler].hpNumbersNoBars) // don't print text if only bars are visible
    {
        if (maxOrCurrent == HP_CURRENT)
            var = 21;
        else
            var = 49;

        ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_LEADING_ZEROS, 3);
        RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

        for (i = 0; i < 3; i++)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[i * 64 + 32],
                      (void *)((OBJ_VRAM0) + TILE_SIZE_4BPP * (gSprites[healthboxSpriteId].oam.tileNum + var + i)),
                      0x20);
        }
    }
}

void UpdateHpTextInHealthbox(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp)
{
    u32 battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    if (WhichBattleCoords(battlerId))
    {
        UpdateHpTextInHealthboxInDoubles(healthboxSpriteId, maxOrCurrent, currHp, maxHp);
    }
    else // Single Battle
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER) // Player
        {
            PrintHpOnHealthbox(healthboxSpriteId, currHp, maxHp, 2, 0xB00, 0x3A0);
        }
        else // Opponent
        {
            UpdateOpponentHpTextSingles(healthboxSpriteId, currHp, HP_CURRENT);
            UpdateOpponentHpTextSingles(healthboxSpriteId, maxHp, HP_MAX);
        }
    }
}

static void UpdateHpTextInHealthboxInDoubles(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp)
{
    u32 barSpriteId = gSprites[healthboxSpriteId].data[5];

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
    {
        if (gBattleSpritesDataPtr->battlerData[gSprites[healthboxSpriteId].data[6]].hpNumbersNoBars) // don't print text if only bars are visible
        {
            PrintHpOnHealthbox(barSpriteId, currHp, maxHp, 0, 0x80, 0x20);
            // Clears the end of the healthbar gfx.
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END),
                          (void *)(OBJ_VRAM0 + 0x680) + (gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP),
                           0x20);
            // Erases HP bar leftover.
            FillHealthboxObject((void *)(OBJ_VRAM0) + (gSprites[barSpriteId].oam.tileNum * TILE_SIZE_4BPP), 0, 2);
        }
    }
    else // Opponent
    {
        UpdateOpponentHpTextDoubles(healthboxSpriteId, barSpriteId, maxHp, HP_MAX);
        UpdateOpponentHpTextDoubles(healthboxSpriteId, barSpriteId, currHp, HP_CURRENT);
    }
}

// Prints mon's nature, catch and flee rate. Probably used to test pokeblock-related features.
static void PrintSafariMonInfo(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 text[20];
    s32 j, spriteTileNum;
    u8 *barFontGfx;
    u8 i, var, nature, healthBarSpriteId;

    memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
    barFontGfx = &gMonSpritesGfxPtr->barFontGfx[0x520 + (GetBattlerPosition(gSprites[healthboxSpriteId].hMain_Battler) * 384)];
    var = 5;
    nature = GetNature(mon);
    StringCopy(&text[6], gNaturesInfo[nature].name);
    RenderTextHandleBold(barFontGfx, FONT_BOLD, text);

    for (j = 6, i = 0; i < var; i++, j++)
    {
        u8 elementId;

        if ((text[j] >= 55 && text[j] <= 74) || (text[j] >= 135 && text[j] <= 154))
            elementId = 44;
        else if ((text[j] >= 75 && text[j] <= 79) || (text[j] >= 155 && text[j] <= 159))
            elementId = 45;
        else
            elementId = 43;

        CpuCopy32(GetHealthboxElementGfxPtr(elementId), barFontGfx + (i * 64), 0x20);
    }

    for (j = 1; j < var + 1; j++)
    {
        spriteTileNum = (gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;

        spriteTileNum = (8 + gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;
    }

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    ConvertIntToDecimalStringN(&text[6], gBattleStruct->safariCatchFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(&text[9], gBattleStruct->safariEscapeFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    text[5] = CHAR_SPACE;
    text[8] = CHAR_SLASH;
    RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

    j = healthBarSpriteId; // Needed to match for some reason.
    for (j = 0; j < 5; j++)
    {
        if (j <= 1)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0) + (gSprites[healthBarSpriteId].oam.tileNum + 2 + j) * TILE_SIZE_4BPP,
                      32);
        }
        else
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0 + 0xC0) + (j + gSprites[healthBarSpriteId].oam.tileNum) * TILE_SIZE_4BPP,
                      32);
        }
    }
}

void SwapHpBarsWithHpText(void)
{
    u32 healthBarSpriteId, i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gSprites[gHealthboxSpriteIds[i]].callback == SpriteCallbackDummy
         && GetBattlerSide(i) != B_SIDE_OPPONENT
         && (WhichBattleCoords(i) || GetBattlerSide(i) != B_SIDE_PLAYER))
        {
            s32 currHp = GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_HP);
            s32 maxHp = GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_MAX_HP);
            bool8 noBars;

            gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars ^= 1;
            noBars = gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars;
            if (GetBattlerSide(i) == B_SIDE_PLAYER)
            {
                if (!WhichBattleCoords(i))
                    continue;
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    continue;

                if (noBars == TRUE) // bars to text
                {
                    healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                    CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 0x100);
                    UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], HP_BOTH, currHp, maxHp);
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gPlayerParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END_BAR), (void *)(OBJ_VRAM0 + 0x680 + gSprites[gHealthboxSpriteIds[i]].oam.tileNum * TILE_SIZE_4BPP), 32);
                }
            }
            else
            {
                if (noBars == TRUE) // bars to text
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    {
                        // Most likely a debug function.
                        PrintSafariMonInfo(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]]);
                    }
                    else
                    {
                        healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                        CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * 32), 0x100);
                        UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], HP_BOTH, currHp, maxHp);
                    }
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                        UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_NICK);
                }
            }
            gSprites[gHealthboxSpriteIds[i]].hMain_Data7 ^= 1;
        }
    }
}

#undef tBattler
#undef tType
#undef tPosX
#undef tLevelXDelta

#define tBattler                data[0]
#define tSummaryBarSpriteId     data[1]
#define tBallIconSpriteId(n)    data[3 + n]
#define tIsBattleStart          data[10]
#define tBlend                  data[15]

u8 CreatePartyStatusSummarySprites(u8 battlerId, struct HpAndStatus *partyInfo, bool8 skipPlayer, bool8 isBattleStart)
{
    bool8 isOpponent;
    s16 bar_X, bar_Y, bar_pos2_X, bar_data0;
    s32 i, j, var;
    u8 summaryBarSpriteId;
    u8 ballIconSpritesIds[PARTY_SIZE];
    u8 taskId;

    if (!skipPlayer || GetBattlerPosition(battlerId) != B_POSITION_OPPONENT_RIGHT)
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            isOpponent = FALSE;
            bar_X = 136, bar_Y = 96;
            bar_pos2_X = 100;
            bar_data0 = -5;
        }
        else
        {
            isOpponent = TRUE;

            if (!skipPlayer || !WhichBattleCoords(battlerId))
                bar_X = 104, bar_Y = 40;
            else
                bar_X = 104, bar_Y = 16;

            bar_pos2_X = -100;
            bar_data0 = 5;
        }
    }
    else
    {
        isOpponent = TRUE;
        bar_X = 104, bar_Y = 40;
        bar_pos2_X = -100;
        bar_data0 = 5;
    }

    LoadCompressedSpriteSheetUsingHeap(&sStatusSummaryBarSpriteSheet);
    LoadSpriteSheet(&sStatusSummaryBallsSpriteSheet);
    LoadSpritePalette(&sStatusSummaryBarSpritePal);
    LoadSpritePalette(&sStatusSummaryBallsSpritePal);

    summaryBarSpriteId = CreateSprite(&sStatusSummaryBarSpriteTemplates[isOpponent], bar_X, bar_Y, 10);
    SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Enter);
    gSprites[summaryBarSpriteId].x2 = bar_pos2_X;
    gSprites[summaryBarSpriteId].data[0] = bar_data0;

    if (isOpponent)
    {
        gSprites[summaryBarSpriteId].x -= 96;
        gSprites[summaryBarSpriteId].oam.matrixNum = ST_OAM_HFLIP;
    }
    else
    {
        gSprites[summaryBarSpriteId].x += 96;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        ballIconSpritesIds[i] = CreateSpriteAtEnd(&sStatusSummaryBallsSpriteTemplates[isOpponent], bar_X, bar_Y - 4, 9);

        if (!isBattleStart)
            gSprites[ballIconSpritesIds[i]].callback = SpriteCB_StatusSummaryBalls_OnSwitchout;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x2 = 0;
            gSprites[ballIconSpritesIds[i]].y2 = 0;
        }

        gSprites[ballIconSpritesIds[i]].data[0] = summaryBarSpriteId;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x += 10 * i + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = i * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = 120;
        }
        else
        {
            gSprites[ballIconSpritesIds[i]].x -= 10 * (5 - i) + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = (6 - i) * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = -120;
        }

        gSprites[ballIconSpritesIds[i]].data[2] = isOpponent;
    }

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with major status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
            }
        }
        else
        {
            for (i = 0, var = PARTY_SIZE - 1, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                     // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                    var--;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostPlayerMons & gBitTable[j])
                {
                    // fainted arena mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
                i++;
            }
        }
    }
    else
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
        {
            for (var = PARTY_SIZE - 1, i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 2;
                }
                var--;
            }
        }
        else
        {
            for (var = 0, i = 0, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                    i++;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                     // fainted mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostOpponentMons & gBitTable[j])
                {
                     // fainted arena mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                     // mon with primary status
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 2;
                }
                var++;
            }
        }
    }

    taskId = CreateTask(TaskDummy, 5);
    gTasks[taskId].tBattler = battlerId;
    gTasks[taskId].tSummaryBarSpriteId = summaryBarSpriteId;

    for (i = 0; i < PARTY_SIZE; i++)
        gTasks[taskId].tBallIconSpriteId(i) = ballIconSpritesIds[i];

    gTasks[taskId].tIsBattleStart = isBattleStart;

    if (isBattleStart)
    {
        gBattleSpritesDataPtr->animationData->field_9_x1C++;
    }

    PlaySE12WithPanning(SE_BALL_TRAY_ENTER, 0);
    return taskId;
}

// Slide the party summary tray back offscreen
void Task_HidePartyStatusSummary(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    bool8 isBattleStart;
    u8 summaryBarSpriteId;
    u8 battlerId;
    s32 i;

    isBattleStart = gTasks[taskId].tIsBattleStart;
    summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;
    battlerId = gTasks[taskId].tBattler;

    for (i = 0; i < PARTY_SIZE; i++)
        ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));

    gTasks[taskId].tBlend = 16;

    for (i = 0; i < PARTY_SIZE; i++)
        gSprites[ballIconSpriteIds[i]].oam.objMode = ST_OAM_OBJ_BLEND;

    gSprites[summaryBarSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;

    if (isBattleStart)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            {
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[3] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[4] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
            else
            {
                gSprites[ballIconSpriteIds[i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[i]].data[3] = 0;
                gSprites[ballIconSpriteIds[i]].data[4] = 0;
                gSprites[ballIconSpriteIds[i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
        }
        gSprites[summaryBarSpriteId].data[0] /= 2;
        gSprites[summaryBarSpriteId].data[1] = 0;
        gSprites[summaryBarSpriteId].callback = SpriteCB_StatusSummaryBar_Exit;
        SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Exit);
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_1;
    }
    else
    {
        gTasks[taskId].func = Task_HidePartyStatusSummary_DuringBattle;
    }
}

static void Task_HidePartyStatusSummary_BattleStart_1(u8 taskId)
{
    if ((gTasks[taskId].data[11]++ % 2) == 0)
    {
        if (--gTasks[taskId].tBlend < 0)
            return;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    if (gTasks[taskId].tBlend == 0)
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_2;
}

static void Task_HidePartyStatusSummary_BattleStart_2(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    s32 i;

    u8 battlerId = gTasks[taskId].tBattler;
    if (--gTasks[taskId].tBlend == -1)
    {
        u8 summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        gBattleSpritesDataPtr->animationData->field_9_x1C--;
        if (gBattleSpritesDataPtr->animationData->field_9_x1C == 0)
        {
            DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
            DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);
        }
        else
        {
            FreeSpriteOamMatrix(&gSprites[summaryBarSpriteId]);
            DestroySprite(&gSprites[summaryBarSpriteId]);
            FreeSpriteOamMatrix(&gSprites[ballIconSpriteIds[0]]);
            DestroySprite(&gSprites[ballIconSpriteIds[0]]);
        }

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

static void Task_HidePartyStatusSummary_DuringBattle(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    s32 i;
    u8 battlerId = gTasks[taskId].tBattler;

    if (--gTasks[taskId].tBlend >= 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    else if (gTasks[taskId].tBlend == -1)
    {
        u8 summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
        DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

#undef tBattler
#undef tSummaryBarSpriteId
#undef tBallIconSpriteId
#undef tIsBattleStart
#undef tBlend

static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *sprite)
{
    if (sprite->x2 != 0)
        sprite->x2 += sprite->data[0];
}

static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *sprite)
{
    sprite->data[1] += 32;
    if (sprite->data[0] > 0)
        sprite->x2 += sprite->data[1] >> 4;
    else
        sprite->x2 -= sprite->data[1] >> 4;
    sprite->data[1] &= 0xF;
}

static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;
    s8 pan;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }

    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;

    if (var1 != 0)
    {
        sprite->x2 += var2 >> 4;
        if (sprite->x2 > 0)
            sprite->x2 = 0;
    }
    else
    {
        sprite->x2 -= var2 >> 4;
        if (sprite->x2 < 0)
            sprite->x2 = 0;
    }

    if (sprite->x2 == 0)
    {
        pan = SOUND_PAN_TARGET;
        if (var1 != 0)
            pan = SOUND_PAN_ATTACKER;

        if (sprite->data[7] != 0)
            PlaySE2WithPanning(SE_BALL_TRAY_EXIT, pan);
        else
            PlaySE1WithPanning(SE_BALL_TRAY_BALL, pan);

        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }
    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;
    if (var1 != 0)
        sprite->x2 += var2 >> 4;
    else
        sprite->x2 -= var2 >> 4;
    if (sprite->x2 + sprite->x > 248
     || sprite->x2 + sprite->x < -8)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *sprite)
{
    u8 barSpriteId = sprite->data[0];

    sprite->x2 = gSprites[barSpriteId].x2;
    sprite->y2 = gSprites[barSpriteId].y2;
}

static void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    void *ptr;
    u32 windowId, spriteTileNum, species;
    u8 *windowTileData;
    u8 gender;
    struct Pokemon *illusionMon = GetIllusionMonPtr(gSprites[healthboxSpriteId].hMain_Battler);
    if (illusionMon != NULL)
        mon = illusionMon;

    StringCopy(gDisplayedStringBattle, gText_HealthboxNickname);
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    StringGet_Nickname(nickname);
    ptr = StringAppend(gDisplayedStringBattle, nickname);

    gender = GetMonGender(mon);
    species = GetMonData(mon, MON_DATA_SPECIES);

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && StringCompare(nickname, GetSpeciesName(species)) == 0)
        gender = 100;

    switch (gender)
    {
    default:
        StringCopy(ptr, gText_HealthboxGender_None);
        break;
    case MON_MALE:
        StringCopy(ptr, gText_HealthboxGender_Male);
        break;
    case MON_FEMALE:
        StringCopy(ptr, gText_HealthboxGender_Female);
        break;
    }

    windowTileData = AddTextPrinterAndCreateWindowOnHealthboxToFit(gDisplayedStringBattle, 0, 3, 2, &windowId, 55);

    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;

    if (GetBattlerSide(gSprites[healthboxSpriteId].data[6]) == B_SIDE_PLAYER)
    {
        TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x40 + spriteTileNum), windowTileData, 6);
        ptr = (void *)(OBJ_VRAM0);
        if (!WhichBattleCoords(gSprites[healthboxSpriteId].data[6]))
            ptr += spriteTileNum + 0x800;
        else
            ptr += spriteTileNum + 0x400;
        TextIntoHealthboxObject(ptr, windowTileData + 0xC0, 1);
    }
    else
    {
        TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x20 + spriteTileNum), windowTileData, 7);
    }

    RemoveWindowOnHealthbox(windowId);
}

static void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus)
{
    u8 battlerId, healthBarSpriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
        return;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return;

    battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return;
    if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES)), FLAG_GET_CAUGHT))
        return;

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;

    if (noStatus)
        CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_BALL_CAUGHT), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
    else
        CpuFill32(0, (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
}

static void UpdateStatusIconInHealthbox(u8 healthboxSpriteId)
{
    s32 i;
    u8 battlerId, healthBarSpriteId;
    u32 status, pltAdder;
    const u8 *statusGfxPtr;
    s16 tileNumAdder;
    u8 statusPalId;

    battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        status = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_STATUS);
        if (!WhichBattleCoords(battlerId))
            tileNumAdder = 0x1A;
        else
            tileNumAdder = 0x12;
    }
    else
    {
        status = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_STATUS);
        tileNumAdder = 0x11;
    }

    if (status & STATUS1_SLEEP)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_SLP_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_SLP;
    }
    else if (status & STATUS1_PSN_ANY)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PSN_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_PSN;
    }
    else if (status & STATUS1_BURN)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_BRN_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_BRN;
    }
    else if (status & STATUS1_FREEZE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_FRZ_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_FRZ;
    }
    else if (status & STATUS1_FROSTBITE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_FRB_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_FRZ;
    }
    else if (status & STATUS1_PARALYSIS)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PRZ_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_PAR;
    }
    else
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_39);

        for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * TILE_SIZE_4BPP), 32);

        if (!gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 64);

        TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
        return;
    }

    pltAdder = PLTT_ID(gSprites[healthboxSpriteId].oam.paletteNum);
    pltAdder += battlerId + 12;

    FillPalette(sStatusIconColors[statusPalId], OBJ_PLTT_OFFSET + pltAdder, PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[OBJ_PLTT_OFFSET + pltAdder], (u16 *)OBJ_PLTT + pltAdder, PLTT_SIZEOF(1));
    CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder) * TILE_SIZE_4BPP), 96);
    if (WhichBattleCoords(battlerId) == 1 || GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
    {
        if (!gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
        {
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_0), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 32);
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_65), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 1) * TILE_SIZE_4BPP), 32);
        }
    }
    TryAddPokeballIconToHealthbox(healthboxSpriteId, FALSE);
}

static u8 GetStatusIconForBattlerId(u8 statusElementId, u8 battlerId)
{
    u8 ret = statusElementId;

    switch (statusElementId)
    {
    case HEALTHBOX_GFX_STATUS_PSN_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_PRZ_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_SLP_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_FRZ_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_FRB_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_FRB_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_FRB_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_FRB_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_FRB_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_BRN_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER3;
        break;
    }
    return ret;
}

static void UpdateSafariBallsTextOnHealthbox(u8 healthboxSpriteId)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gText_SafariBalls, 0, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;
    TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x40) + spriteTileNum, windowTileData, 6);
    TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x800) + spriteTileNum, windowTileData + 0xC0, 2);
    RemoveWindowOnHealthbox(windowId);
}

static void UpdateLeftNoOfBallsTextOnHealthbox(u8 healthboxSpriteId)
{
    u8 text[16];
    u8 *txtPtr;
    u32 windowId, spriteTileNum;
    u8 *windowTileData;

    txtPtr = StringCopy(text, gText_SafariBallLeft);
    ConvertIntToDecimalStringN(txtPtr, gNumSafariBalls, STR_CONV_MODE_LEFT_ALIGN, 2);

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, GetStringRightAlignXOffset(FONT_SMALL, text, 0x2F), 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;
    SafariTextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x2C0) + spriteTileNum, windowTileData, 2);
    SafariTextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0xA00) + spriteTileNum, windowTileData + 0x40, 4);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId)
{
    u32 battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    s32 maxHp = GetMonData(mon, MON_DATA_MAX_HP);
    s32 currHp = GetMonData(mon, MON_DATA_HP);

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        u8 isDoubles = WhichBattleCoords(battlerId);

        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));

        if (elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, HP_BOTH, currHp, maxHp);
        else if (elementId == HEALTHBOX_MAX_HP)
            UpdateHpTextInHealthbox(healthboxSpriteId, HP_MAX, currHp, maxHp);
        else if (elementId == HEALTHBOX_CURRENT_HP)
            UpdateHpTextInHealthbox(healthboxSpriteId, HP_CURRENT, currHp, maxHp);

        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battlerId, healthboxSpriteId, HEALTH_BAR, 0);
        }

        if (!isDoubles && (elementId == HEALTHBOX_EXP_BAR || elementId == HEALTHBOX_ALL))
        {
            u16 species;
            u32 exp, currLevelExp;
            s32 currExpBarValue, maxExpBarValue;
            u8 level;

            LoadBattleBarGfx(3);
            species = GetMonData(mon, MON_DATA_SPECIES);
            level = GetMonData(mon, MON_DATA_LEVEL);
            exp = GetMonData(mon, MON_DATA_EXP);
            currLevelExp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
            currExpBarValue = exp - currLevelExp;
            maxExpBarValue = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - currLevelExp;
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxExpBarValue, currExpBarValue, isDoubles);
            MoveBattleBar(battlerId, healthboxSpriteId, EXP_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT)
            UpdateSafariBallsTextOnHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT || elementId == HEALTHBOX_SAFARI_BALLS_TEXT)
            UpdateLeftNoOfBallsTextOnHealthbox(healthboxSpriteId);
    }
    else
    {
        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
        {
            if (elementId == HEALTHBOX_ALL)
                UpdateHpTextInHealthbox(healthboxSpriteId, HP_BOTH, currHp, maxHp);
            else if (elementId == HEALTHBOX_MAX_HP)
                UpdateHpTextInHealthbox(healthboxSpriteId, HP_MAX, currHp, maxHp);
            else if (elementId == HEALTHBOX_CURRENT_HP)
                UpdateHpTextInHealthbox(healthboxSpriteId, HP_CURRENT, currHp, maxHp);
        }
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battlerId, healthboxSpriteId, HEALTH_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
    }
}

#define B_EXPBAR_PIXELS 64
#define B_HEALTHBAR_PIXELS 48

s32 MoveBattleBar(u8 battlerId, u8 healthboxSpriteId, u8 whichBar, u8 unused)
{
    s32 currentBarValue;

    if (whichBar == HEALTH_BAR) // health bar
    {
        u16 hpFraction = B_FAST_HP_DRAIN == FALSE ? 1 : max(gBattleSpritesDataPtr->battleBars[battlerId].maxValue / (B_HEALTHBAR_PIXELS / 2), 1);
        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    B_HEALTHBAR_PIXELS / 8, hpFraction);
    }
    else // exp bar
    {
        u16 expFraction = GetScaledExpFraction(gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].maxValue, 8);
        if (expFraction == 0)
            expFraction = 1;
        expFraction = abs(gBattleSpritesDataPtr->battleBars[battlerId].receivedValue / expFraction);

        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    B_EXPBAR_PIXELS / 8, expFraction);
    }

    if (whichBar == EXP_BAR || (whichBar == HEALTH_BAR && !gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars))
        MoveBattleBarGraphically(battlerId, whichBar);

    if (currentBarValue == -1)
        gBattleSpritesDataPtr->battleBars[battlerId].currValue = 0;

    return currentBarValue;
}

static void MoveBattleBarGraphically(u8 battlerId, u8 whichBar)
{
    u8 array[8];
    u8 filledPixelsCount, level;
    u8 barElementId;
    u8 i;

    switch (whichBar)
    {
    case HEALTH_BAR:
        filledPixelsCount = CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                            gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                            gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                            &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                            array, B_HEALTHBAR_PIXELS / 8);

        if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            barElementId = HEALTHBOX_GFX_HP_BAR_GREEN;
        else if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            barElementId = HEALTHBOX_GFX_HP_BAR_YELLOW;
        else
            barElementId = HEALTHBOX_GFX_HP_BAR_RED; // 20 % or less

        for (i = 0; i < 6; i++)
        {
            u8 healthbarSpriteId = gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].hMain_HealthBarSpriteId;
            if (i < 2)
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[healthbarSpriteId].oam.tileNum + 2 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 64 + (i + gSprites[healthbarSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    case EXP_BAR:
        CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    array, B_EXPBAR_PIXELS / 8);
        level = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_LEVEL);
        if (level >= MAX_LEVEL)
        {
            for (i = 0; i < 8; i++)
                array[i] = 0;
        }
        for (i = 0; i < 8; i++)
        {
            if (i < 4)
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].oam.tileNum + 0x24 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 0xB80 + (i + gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    }
}

static s32 CalcNewBarValue(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 scale, u16 toAdd)
{
    s32 ret, newValue;
    scale *= 8;

    if (*currValue == -32768) // first function call
    {
        if (maxValue < scale)
            *currValue = Q_24_8(oldValue);
        else
            *currValue = oldValue;
    }

    newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    if (maxValue < scale)
    {
        if (newValue == Q_24_8_TO_INT(*currValue) && (*currValue & 0xFF) == 0)
            return -1;
    }
    else
    {
        if (newValue == *currValue) // we're done, the bar's value has been updated
            return -1;
    }

    if (maxValue < scale) // handle cases of max var having less pixels than the whole bar
    {
        s32 toAdd = Q_24_8(maxValue) / scale;

        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            if (ret >= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
        else // move bar left
        {
            *currValue -= toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            // try round up
            if ((*currValue & 0xFF) > 0)
                ret++;
            if (ret <= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
    }
    else
    {
        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            if (*currValue > newValue)
                *currValue = newValue;
            ret = *currValue;
        }
        else // move bar left
        {
            *currValue -= toAdd;
            if (*currValue < newValue)
                *currValue = newValue;
            ret = *currValue;
        }
    }

    return ret;
}

static u8 CalcBarFilledPixels(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 *pixelsArray, u8 scale)
{
    u8 pixels, filledPixels, totalPixels;
    u8 i;

    s32 newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    totalPixels = scale * 8;

    for (i = 0; i < scale; i++)
        pixelsArray[i] = 0;

    if (maxValue < totalPixels)
        pixels = (*currValue * totalPixels / maxValue) >> 8;
    else
        pixels = *currValue * totalPixels / maxValue;

    filledPixels = pixels;

    if (filledPixels == 0 && newValue > 0)
    {
        pixelsArray[0] = 1;
        filledPixels = 1;
    }
    else
    {
        for (i = 0; i < scale; i++)
        {
            if (pixels >= 8)
            {
                pixelsArray[i] = 8;
            }
            else
            {
                pixelsArray[i] = pixels;
                break;
            }
            pixels -= 8;
        }
    }

    return filledPixels;
}

static u8 GetScaledExpFraction(s32 oldValue, s32 receivedValue, s32 maxValue, u8 scale)
{
    s32 newVal, result;
    s8 oldToMax, newToMax;

    scale *= (B_FAST_EXP_GROW) ? 2 : 8;
    newVal = oldValue - receivedValue;

    if (newVal < 0)
        newVal = 0;
    else if (newVal > maxValue)
        newVal = maxValue;

    oldToMax = oldValue * scale / maxValue;
    newToMax = newVal * scale / maxValue;
    result = oldToMax - newToMax;

    return abs(result);
}

u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale)
{
    u8 result = hp * scale / maxhp;

    if (result == 0 && hp > 0)
        return 1;

    return result;
}

u8 GetHPBarLevel(s16 hp, s16 maxhp)
{
    u8 result;

    if (hp == maxhp)
    {
        result = HP_BAR_FULL;
    }
    else
    {
        u8 fraction = GetScaledHPFraction(hp, maxhp, B_HEALTHBAR_PIXELS);
        if (fraction > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            result = HP_BAR_GREEN;
        else if (fraction > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            result = HP_BAR_YELLOW;
        else if (fraction > 0)
            result = HP_BAR_RED;
        else
            result = HP_BAR_EMPTY;
    }

    return result;
}

static u8 *AddTextPrinterAndCreateWindowOnHealthboxWithFont(const u8 *str, u32 x, u32 y, u32 bgColor, u32 *windowId, u32 fontId)
{
    u16 winId;
    u8 color[3];
    struct WindowTemplate winTemplate = sHealthboxWindowTemplate;

    winId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(winId, PIXEL_FILL(bgColor));

    color[0] = bgColor;
    color[1] = 1;
    color[2] = 3;

    AddTextPrinterParameterized4(winId, fontId, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);

    *windowId = winId;
    return (u8 *)(GetWindowAttribute(winId, WINDOW_TILE_DATA));
}

static u8 *AddTextPrinterAndCreateWindowOnHealthbox(const u8 *str, u32 x, u32 y, u32 bgColor, u32 *windowId)
{
    return AddTextPrinterAndCreateWindowOnHealthboxWithFont(str, x, y, bgColor, windowId, FONT_SMALL);
}

static u8 *AddTextPrinterAndCreateWindowOnHealthboxToFit(const u8 *str, u32 x, u32 y, u32 bgColor, u32 *windowId, u32 width)
{
    u32 fontId = GetFontIdToFit(str, FONT_SMALL, 0, width);
    return AddTextPrinterAndCreateWindowOnHealthboxWithFont(str, x, y, bgColor, windowId, fontId);
}

static void RemoveWindowOnHealthbox(u32 windowId)
{
    RemoveWindow(windowId);
}

static void FillHealthboxObject(void *dest, u32 valMult, u32 numTiles)
{
    CpuFill32(0x11111111 * valMult, dest, numTiles * TILE_SIZE_4BPP);
}

static void HpTextIntoHealthboxObject(void *dest, u8 *windowTileData, u32 windowWidth)
{
    CpuCopy32(windowTileData + 256, dest, windowWidth * TILE_SIZE_4BPP);
}

static void TextIntoHealthboxObject(void *dest, u8 *windowTileData, s32 windowWidth)
{
    CpuCopy32(windowTileData + 256, dest + 256, windowWidth * TILE_SIZE_4BPP);
// + 256 as that prevents the top 4 blank rows of sHealthboxWindowTemplate from being copied
    if (windowWidth > 0)
    {
        do
        {
            CpuCopy32(windowTileData + 20, dest + 20, 12);
            dest += 32, windowTileData += 32;
            windowWidth--;
        } while (windowWidth != 0);
    }
}

static void SafariTextIntoHealthboxObject(void *dest, u8 *windowTileData, u32 windowWidth)
{
    CpuCopy32(windowTileData, dest, windowWidth * TILE_SIZE_4BPP);
    CpuCopy32(windowTileData + 256, dest + 256, windowWidth * TILE_SIZE_4BPP);
}

#define ABILITY_POP_UP_TAG 0xD720

// for sprite
#define tOriginalX      data[0]
#define tHide           data[1]
#define tFrames         data[2]
#define tRightToLeft    data[3]
#define tBattlerId      data[4]
#define tIsMain         data[5]

// for task
#define tSpriteId1      data[6]
#define tSpriteId2      data[7]

static const u8 ALIGNED(4) sAbilityPopUpGfx[] = INCBIN_U8("graphics/battle_interface/ability_pop_up.4bpp");
static const u16 sAbilityPopUpPalette[] = INCBIN_U16("graphics/battle_interface/ability_pop_up.gbapal");

static const struct SpriteSheet sSpriteSheet_AbilityPopUp =
{
    sAbilityPopUpGfx, sizeof(sAbilityPopUpGfx), ABILITY_POP_UP_TAG
};
static const struct SpritePalette sSpritePalette_AbilityPopUp =
{
    sAbilityPopUpPalette, ABILITY_POP_UP_TAG
};

static const struct OamData sOamData_AbilityPopUp =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_AbilityPopUp =
{
    .tileTag = ABILITY_POP_UP_TAG,
    .paletteTag = ABILITY_POP_UP_TAG,
    .oam = &sOamData_AbilityPopUp,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_AbilityPopUp
};

#define ABILITY_POP_UP_POS_X_DIFF (64 - 7) // Hide second sprite underneath to gain proper letter spacing
#define ABILITY_POP_UP_POS_X_SLIDE 68

static const s16 sAbilityPopUpCoordsDoubles[MAX_BATTLERS_COUNT][2] =
{
    {29, 80}, // player left
    {186, 19}, // opponent left
    {29, 97}, // player right
    {186, 36}, // opponent right
};

static const s16 sAbilityPopUpCoordsSingles[MAX_BATTLERS_COUNT][2] =
{
    {29, 97}, // player
    {186, 57}, // opponent
};

#define POPUP_WINDOW_WIDTH 8
#define MAX_POPUP_STRING_WIDTH (POPUP_WINDOW_WIDTH * 8)

static u8* AddTextPrinterAndCreateWindowOnAbilityPopUp(const u8 *str, u32 x, u32 y, u32 color1, u32 color2, u32 color3, u32 *windowId)
{
    u32 fontId;
    u8 color[3] = {color1, color2, color3};
    struct WindowTemplate winTemplate = {0};
    winTemplate.width = POPUP_WINDOW_WIDTH;
    winTemplate.height = 2;

    *windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(*windowId, PIXEL_FILL(color1));

    fontId = GetFontIdToFit(str, FONT_SMALL, 0, 76);
    AddTextPrinterParameterized4(*windowId, fontId, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
    return (u8 *)(GetWindowAttribute(*windowId, WINDOW_TILE_DATA));
}

static void TextIntoAbilityPopUp(void *dest, u8 *windowTileData, s32 xTileAmount, bool32 arg3)
{
    CpuCopy32(windowTileData + 256, dest + 256, xTileAmount * 32);
    if (xTileAmount > 0)
    {
        do
        {
            if (arg3)
                CpuCopy32(windowTileData + 16, dest + 16, 16);
            else
                CpuCopy32(windowTileData + 20, dest + 20, 12);
            dest += 32, windowTileData += 32;
            xTileAmount--;
        } while (xTileAmount != 0);
    }
}

static void PrintOnAbilityPopUp(const u8 *str, u8 *spriteTileData1, u8 *spriteTileData2, u32 x1, u32 x2, u32 y, u32 color1, u32 color2, u32 color3)
{
    u32 windowId;
    u8 *windowTileData;
    u16 width;

    windowTileData = AddTextPrinterAndCreateWindowOnAbilityPopUp(str, x1, y, color1, color2, color3, &windowId);
    TextIntoAbilityPopUp(spriteTileData1, windowTileData, 8, (y == 0));
    RemoveWindow(windowId);

    width = GetStringWidth(FONT_SMALL, str, 0);

    if (width > MAX_POPUP_STRING_WIDTH - 5)
    {
        windowTileData = AddTextPrinterAndCreateWindowOnAbilityPopUp(str, x2 - MAX_POPUP_STRING_WIDTH, y, color1, color2, color3, &windowId);
        TextIntoAbilityPopUp(spriteTileData2, windowTileData, 3, (y == 0));
        RemoveWindow(windowId);
    }
}

static const u8 sText_Spaces20[]= _("                    ");
static void ClearAbilityName(u8 spriteId1, u8 spriteId2)
{
    PrintOnAbilityPopUp(sText_Spaces20,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32) + 256,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32) + 256,
                        5, 12,
                        4,
                        7, 9, 1);
}

static void PrintBattlerOnAbilityPopUp(u8 battlerId, u8 spriteId1, u8 spriteId2)
{
    int i;
    u8 lastChar;
    u8* textPtr;
    u8 monName[POKEMON_NAME_LENGTH + 3] = {0};
    u8* nick = gBattleMons[battlerId].nickname; // This needs to be updated for Illusion support

    for (i = 0; i < POKEMON_NAME_LENGTH; ++i)
    {
        monName[i] = nick[i];

        if (nick[i] == EOS || i + 1 == POKEMON_NAME_LENGTH) // End of string
            break;
    }

    textPtr = monName + i + 1;

    if (*(textPtr - 1) == EOS)
        textPtr--;

    lastChar = *(textPtr - 1);

    // Make the string say "[NAME]'s" instead of "[NAME]"
    textPtr[0] = CHAR_SGL_QUOTE_RIGHT; // apostraphe
    textPtr++;
    if (lastChar != CHAR_S && lastChar != CHAR_s)
    {
        textPtr[0] = CHAR_s;
        textPtr++;
    }

    textPtr[0] = EOS;

    PrintOnAbilityPopUp((const u8 *)monName,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32),
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32),
                        5, 12,
                        0,
                        2, 7, 1);
}

static void PrintAbilityOnAbilityPopUp(u32 ability, u8 spriteId1, u8 spriteId2)
{
    ClearAbilityName(spriteId1, spriteId2);
    PrintOnAbilityPopUp(gAbilitiesInfo[ability].name,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32) + 256,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32) + 256,
                        5, 12,
                        4,
                        7, 9, 1);
}

#define PIXEL_COORDS_TO_OFFSET(x, y)(            \
/*Add tiles by X*/                                \
((y / 8) * 32 * 8)                                \
/*Add tiles by X*/                                \
+ ((x / 8) * 32)                                \
/*Add pixels by Y*/                                \
+ ((((y) - ((y / 8) * 8))) * 4)                    \
/*Add pixels by X*/                                \
+ ((((x) - ((x / 8) * 8)) / 2)))

static const u16 sOverwrittenPixelsTable[][2] =
{
    {PIXEL_COORDS_TO_OFFSET(0, 0), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 1), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 2), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 3), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 4), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 5), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 6), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 7), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 8), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 9), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 10), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 11), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 12), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 13), 8},

    {PIXEL_COORDS_TO_OFFSET(8, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(24, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(32, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(40, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(48, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(56, 13), 8},

    {PIXEL_COORDS_TO_OFFSET(0, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(24, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(32, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(40, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(48, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(56, 14), 8},

    {PIXEL_COORDS_TO_OFFSET(0, 15), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 16), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 17), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 18), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 19), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 20), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 21), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 22), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 23), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 24), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 25), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 26), 3},

//Second Row Of Image
    {PIXEL_COORDS_TO_OFFSET(0, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(0, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(0, 47), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 47), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 47), 8},
};

static inline void CopyPixels(u8 *dest, const u8 *src, u32 pixelCount)
{
    u32 i = 0;

    if (pixelCount & 1)
    {
        while (pixelCount != 0)
        {
            dest[i] &= ~(0xF);
            dest[i] |= (src[i] & 0xF);
            if (--pixelCount != 0)
            {
                dest[i] &= ~(0xF0);
                dest[i] |= (src[i] & 0xF0);
                pixelCount--;
            }
            i++;
        }
    }
    else
    {
        for (i = 0; i < pixelCount / 2; i++)
            dest[i] = src[i];
    }
}

static void RestoreOverwrittenPixels(u8 *tiles)
{
    u32 i;
    u8 *buffer = Alloc(sizeof(sAbilityPopUpGfx) * 2);

    CpuCopy32(tiles, buffer, sizeof(sAbilityPopUpGfx));

    for (i = 0; i < ARRAY_COUNT(sOverwrittenPixelsTable); i++)
    {
        CopyPixels(buffer + sOverwrittenPixelsTable[i][0],
                   sAbilityPopUpGfx + sOverwrittenPixelsTable[i][0],
                   sOverwrittenPixelsTable[i][1]);
    }

    CpuCopy32(buffer, tiles, sizeof(sAbilityPopUpGfx));
    Free(buffer);
}

void CreateAbilityPopUp(u8 battlerId, u32 ability, bool32 isDoubleBattle)
{
    const s16 (*coords)[2];
    u8 spriteId1, spriteId2, battlerPosition, taskId;

    if (B_ABILITY_POP_UP == FALSE)
        return;

    if (gBattleScripting.abilityPopupOverwrite != 0)
        ability = gBattleScripting.abilityPopupOverwrite;

    if (gTestRunnerEnabled)
    {
        TestRunner_Battle_RecordAbilityPopUp(battlerId, ability);
        if (gTestRunnerHeadless)
            return;
    }

    if (!gBattleStruct->activeAbilityPopUps)
    {
        LoadSpriteSheet(&sSpriteSheet_AbilityPopUp);
        LoadSpritePalette(&sSpritePalette_AbilityPopUp);
    }
    gBattleStruct->activeAbilityPopUps |= gBitTable[battlerId];
    battlerPosition = GetBattlerPosition(battlerId);

    if (isDoubleBattle)
        coords = sAbilityPopUpCoordsDoubles;
    else
        coords = sAbilityPopUpCoordsSingles;

    if ((battlerPosition & BIT_SIDE) == B_SIDE_PLAYER)
    {
        spriteId1 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] - ABILITY_POP_UP_POS_X_SLIDE,
                                coords[battlerPosition][1], 0);
        spriteId2 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] - ABILITY_POP_UP_POS_X_SLIDE + ABILITY_POP_UP_POS_X_DIFF,
                                coords[battlerPosition][1], 1); //Appears below

        gSprites[spriteId1].tRightToLeft = TRUE;
        gSprites[spriteId2].tRightToLeft = TRUE;
    }
    else
    {
        spriteId1 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_SLIDE,
                                coords[battlerPosition][1], 0);
        spriteId2 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_SLIDE + ABILITY_POP_UP_POS_X_DIFF,
                                coords[battlerPosition][1], 1); //Appears below

        gSprites[spriteId1].tRightToLeft = FALSE;
        gSprites[spriteId2].tRightToLeft = FALSE;
    }

    gSprites[spriteId1].tOriginalX = coords[battlerPosition][0];
    gSprites[spriteId2].tOriginalX = coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_DIFF;
    gSprites[spriteId2].oam.tileNum += (8 * 4); //Second half of pop up

    gBattleStruct->abilityPopUpSpriteIds[battlerId][0] = spriteId1;
    gBattleStruct->abilityPopUpSpriteIds[battlerId][1] = spriteId2;

    taskId = CreateTask(Task_FreeAbilityPopUpGfx, 5);
    gTasks[taskId].tSpriteId1 = spriteId1;
    gTasks[taskId].tSpriteId2 = spriteId2;

    gSprites[spriteId1].tIsMain = TRUE;
    gSprites[spriteId1].tBattlerId = battlerId;
    gSprites[spriteId2].tBattlerId = battlerId;

    StartSpriteAnim(&gSprites[spriteId1], 0);
    StartSpriteAnim(&gSprites[spriteId2], 0);

    PrintBattlerOnAbilityPopUp(battlerId, spriteId1, spriteId2);
    PrintAbilityOnAbilityPopUp(ability, spriteId1, spriteId2);
    RestoreOverwrittenPixels((void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32));
}

void UpdateAbilityPopup(u8 battlerId)
{
    u8 spriteId1 = gBattleStruct->abilityPopUpSpriteIds[battlerId][0];
    u8 spriteId2 = gBattleStruct->abilityPopUpSpriteIds[battlerId][1];
    u16 ability = (gBattleScripting.abilityPopupOverwrite != 0) ? gBattleScripting.abilityPopupOverwrite : gBattleMons[battlerId].ability;

    PrintAbilityOnAbilityPopUp(ability, spriteId1, spriteId2);
    RestoreOverwrittenPixels((void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32));
}

#define FRAMES_TO_WAIT 48

static void SpriteCb_AbilityPopUp(struct Sprite *sprite)
{
    if (!sprite->tHide) // Show
    {
        if (sprite->tIsMain && ++sprite->tFrames == 4)
            PlaySE(SE_BALL_TRAY_ENTER);
        if ((!sprite->tRightToLeft && (sprite->x -= 4) <= sprite->tOriginalX)
            || (sprite->tRightToLeft && (sprite->x += 4) >= sprite->tOriginalX)
           )
        {
            sprite->x = sprite->tOriginalX;
            sprite->tHide = TRUE;
            sprite->tFrames = FRAMES_TO_WAIT;
        }
    }
    else // Hide
    {
        if (sprite->tFrames == 0)
        {
            if ((!sprite->tRightToLeft && (sprite->x += 4) >= sprite->tOriginalX + ABILITY_POP_UP_POS_X_SLIDE)
                ||(sprite->tRightToLeft && (sprite->x -= 4) <= sprite->tOriginalX - ABILITY_POP_UP_POS_X_SLIDE)
               )
            {
                gBattleStruct->activeAbilityPopUps &= ~(gBitTable[sprite->tBattlerId]);
                DestroySprite(sprite);
            }
        }
        else
        {
            if (!gBattleScripting.fixedPopup)
                sprite->tFrames--;
        }
    }
}

void DestroyAbilityPopUp(u8 battlerId)
{
    if (gBattleStruct->activeAbilityPopUps & gBitTable[battlerId])
    {
        gSprites[gBattleStruct->abilityPopUpSpriteIds[battlerId][0]].tFrames = 0;
        gSprites[gBattleStruct->abilityPopUpSpriteIds[battlerId][1]].tFrames = 0;
    }
    gBattleScripting.fixedPopup = FALSE;
}

static void Task_FreeAbilityPopUpGfx(u8 taskId)
{
    if (!gSprites[gTasks[taskId].tSpriteId1].inUse
        && !gSprites[gTasks[taskId].tSpriteId2].inUse
        && !gBattleStruct->activeAbilityPopUps)
    {
        FreeSpriteTilesByTag(ABILITY_POP_UP_TAG);
        FreeSpritePaletteByTag(ABILITY_POP_UP_TAG);
        DestroyTask(taskId);
    }
}

// last used ball
#define LAST_BALL_WINDOW_TAG 0xD721

static const struct OamData sOamData_LastUsedBall =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = (B_LAST_USED_BALL_CYCLE == TRUE ? SPRITE_SHAPE(32x64) : SPRITE_SHAPE(32x32)),
    .x = 0,
    .matrixNum = 0,
    .size = (B_LAST_USED_BALL_CYCLE == TRUE ? SPRITE_SIZE(32x64) : SPRITE_SIZE(32x32)),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_LastUsedBallWindow =
{
    .tileTag = LAST_BALL_WINDOW_TAG,
    .paletteTag = ABILITY_POP_UP_TAG,
    .oam = &sOamData_LastUsedBall,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_LastUsedBallWin
};

#if B_LAST_USED_BALL_BUTTON == R_BUTTON && B_LAST_USED_BALL_CYCLE == TRUE
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_r_cycle.4bpp");
#elif B_LAST_USED_BALL_CYCLE == TRUE
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_l_cycle.4bpp");
#elif B_LAST_USED_BALL_BUTTON == R_BUTTON
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_r.4bpp");
#else
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_l.4bpp");
#endif
static const struct SpriteSheet sSpriteSheet_LastUsedBallWindow =
{
    sLastUsedBallWindowGfx, sizeof(sLastUsedBallWindowGfx), LAST_BALL_WINDOW_TAG
};

#define LAST_USED_BALL_X_F    14
#define LAST_USED_BALL_X_0    -14
#define LAST_USED_BALL_Y      ((IsDoubleBattle()) ? 78 : 68)
#define LAST_USED_BALL_Y_BNC  ((IsDoubleBattle()) ? 76 : 66)

#define LAST_BALL_WIN_X_F       (LAST_USED_BALL_X_F - 0)
#define LAST_BALL_WIN_X_0       (LAST_USED_BALL_X_0 - 0)
#define LAST_USED_WIN_Y         (LAST_USED_BALL_Y - 8)

#define sHide  data[0]
#define sTimer  data[1]
#define sMoving data[2]
#define sBounce data[3] // 0 = Bounce down; 1 = Bounce up

#define sState     data[0]
#define sSameBall  data[1]

bool32 CanThrowLastUsedBall(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return FALSE;
    if (!CanThrowBall())
        return FALSE;
    if (gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FRONTIER))
        return FALSE;
    if (!CheckBagHasItem(gBallToDisplay, 1))
        return FALSE;

    return TRUE;
}

void TryAddLastUsedBallItemSprites(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return;
    if (gLastThrownBall == 0
      || (gLastThrownBall != 0 && !CheckBagHasItem(gLastThrownBall, 1)))
    {
        // we're out of the last used ball, so just set it to the first ball in the bag
        u16 firstBall;

        // we have to compact the bag first bc it is typically only compacted when you open it
        CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);

        firstBall = gBagPockets[BALLS_POCKET].itemSlots[0].itemId;
        if (firstBall > ITEM_NONE)
            gBallToDisplay = firstBall;
    }

    if (!CanThrowLastUsedBall())
        return;

    // ball
    if (gBattleStruct->ballSpriteIds[0] == MAX_SPRITES)
    {
        gBattleStruct->ballSpriteIds[0] = AddItemIconSprite(102, 102, gBallToDisplay);
        gSprites[gBattleStruct->ballSpriteIds[0]].x = LAST_USED_BALL_X_0;
        gSprites[gBattleStruct->ballSpriteIds[0]].y = LAST_USED_BALL_Y;
        gSprites[gBattleStruct->ballSpriteIds[0]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
        gSprites[gBattleStruct->ballSpriteIds[0]].callback = SpriteCB_LastUsedBall;
    }

    // window
    LoadSpritePalette(&sSpritePalette_AbilityPopUp);
    if (GetSpriteTileStartByTag(LAST_BALL_WINDOW_TAG) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_LastUsedBallWindow);

    if (gBattleStruct->ballSpriteIds[1] == MAX_SPRITES)
    {
        gBattleStruct->ballSpriteIds[1] = CreateSprite(&sSpriteTemplate_LastUsedBallWindow,
                                                       LAST_BALL_WIN_X_0,
                                                       LAST_USED_WIN_Y, 5);
        gSprites[gBattleStruct->ballSpriteIds[1]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
    }
    if (B_LAST_USED_BALL_CYCLE == TRUE)
        ArrowsChangeColorLastBallCycle(0); //Default the arrows to be invisible
}

static void DestroyLastUsedBallWinGfx(struct Sprite *sprite)
{
    FreeSpriteTilesByTag(LAST_BALL_WINDOW_TAG);
    FreeSpritePaletteByTag(ABILITY_POP_UP_TAG);
    DestroySprite(sprite);
    gBattleStruct->ballSpriteIds[1] = MAX_SPRITES;
}

static void DestroyLastUsedBallGfx(struct Sprite *sprite)
{
    FreeSpriteTilesByTag(102);
    FreeSpritePaletteByTag(102);
    DestroySprite(sprite);
    gBattleStruct->ballSpriteIds[0] = MAX_SPRITES;
}

static void SpriteCB_LastUsedBallWin(struct Sprite *sprite)
{
    if (sprite->sHide)
    {
        if (sprite->x != LAST_BALL_WIN_X_0)
            sprite->x--;

        if (sprite->x == LAST_BALL_WIN_X_0)
            DestroyLastUsedBallWinGfx(sprite);
    }
    else
    {
        if (sprite->x != LAST_BALL_WIN_X_F)
            sprite->x++;
    }
}

static void SpriteCB_LastUsedBall(struct Sprite *sprite)
{
    if (sprite->sHide)
    {
        if (sprite->y < LAST_USED_BALL_Y) // Used to recover from an incomplete bounce before hiding the window
            sprite->y++;

        if (sprite->x != LAST_USED_BALL_X_0)
            sprite->x--;

        if (sprite->x == LAST_USED_BALL_X_0)
            DestroyLastUsedBallGfx(sprite);
    }
    else
    {
        if (sprite->x != LAST_USED_BALL_X_F)
            sprite->x++;
    }
}

static void TryHideOrRestoreLastUsedBall(u8 caseId)
{
    if (B_LAST_USED_BALL == FALSE)
        return;
    if (gBattleStruct->ballSpriteIds[0] == MAX_SPRITES)
        return;

    switch (caseId)
    {
    case 0: // hide
        if (gBattleStruct->ballSpriteIds[0] != MAX_SPRITES)
            gSprites[gBattleStruct->ballSpriteIds[0]].sHide = TRUE;   // hide
        if (gBattleStruct->ballSpriteIds[1] != MAX_SPRITES)
            gSprites[gBattleStruct->ballSpriteIds[1]].sHide = TRUE;   // hide
        gLastUsedBallMenuPresent = FALSE;
        break;
    case 1: // restore
        if (gBattleStruct->ballSpriteIds[0] != MAX_SPRITES)
            gSprites[gBattleStruct->ballSpriteIds[0]].sHide = FALSE;   // restore
        if (gBattleStruct->ballSpriteIds[1] != MAX_SPRITES)
            gSprites[gBattleStruct->ballSpriteIds[1]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
        break;
    }
    if (B_LAST_USED_BALL_CYCLE == TRUE)
        ArrowsChangeColorLastBallCycle(0); //Default the arrows to be invisible
}

void TryHideLastUsedBall(void)
{
    if (B_LAST_USED_BALL == TRUE)
        TryHideOrRestoreLastUsedBall(0);
}

void TryRestoreLastUsedBall(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return;

    if (gBattleStruct->ballSpriteIds[0] != MAX_SPRITES)
        TryHideOrRestoreLastUsedBall(1);
    else
        TryAddLastUsedBallItemSprites();
}

static void SpriteCB_LastUsedBallBounce(struct Sprite *sprite)
{
    if ((sprite->sTimer++ % 4) != 0)  // Change the image every 4 frame
        return;
    if (sprite->sBounce)
    {
        if (sprite->y > LAST_USED_BALL_Y_BNC)
            sprite->y--;
        else
            sprite->sMoving = FALSE;
    }
    else
    {
        if (sprite->y < LAST_USED_BALL_Y)
            sprite->y++;
        else
            sprite->sMoving = FALSE;
    }
}

static void Task_BounceBall(u8 taskId)
{
    struct Sprite *sprite = &gSprites[gBattleStruct->ballSpriteIds[0]];
    struct Task *task = &gTasks[taskId];
    switch(task->sState)
    {
    case 0:  // Bounce up
        sprite->sBounce = TRUE;
        sprite->sMoving = TRUE;
        sprite->callback = SpriteCB_LastUsedBallBounce;
        if (task->sSameBall)
            task->sState = 3;
        else
            task->sState = 1;
        break;
    case 1:  // Destroy Icon
        if (!sprite->sMoving)
        {
            DestroyLastUsedBallGfx(sprite);
            task->sState++;
        }  // Passthrough
    case 2: //Create New Icon
        if (!sprite->inUse)
        {
            gBattleStruct->ballSpriteIds[0] = AddItemIconSprite(102, 102, gBallToDisplay);
            gSprites[gBattleStruct->ballSpriteIds[0]].x = LAST_USED_BALL_X_F;
            gSprites[gBattleStruct->ballSpriteIds[0]].y = LAST_USED_BALL_Y_BNC;
            task->sState++;
        }  // Fallthrough
    case 3: // Bounce Down
        if (!sprite->sMoving)
        {
            sprite->sBounce = FALSE;
            sprite->sMoving = TRUE;
            sprite->callback = SpriteCB_LastUsedBallBounce; //Show and bounce down
            task->sState++;
        }
        break;
    case 4:  // Destroy Task
        if(!sprite->sMoving)
        {
            sprite->callback = SpriteCB_LastUsedBall;
            DestroyTask(taskId);
        }
    }
    if (!gLastUsedBallMenuPresent)
    {
        // Used to check if the R button was released before the animation was complete
        sprite->callback = SpriteCB_LastUsedBall;
        DestroyTask(taskId);
    }
}

void SwapBallToDisplay(bool32 sameBall)
{
    u8 taskId;
    taskId = CreateTask(Task_BounceBall, 10);
    gTasks[taskId].sSameBall = sameBall;
}

void ArrowsChangeColorLastBallCycle(bool32 showArrows)
{
#if B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == TRUE
    u16 paletteNum = 16 + gSprites[gBattleStruct->ballSpriteIds[1]].oam.paletteNum;
    struct PlttData *defaultPlttArrow;
    struct PlttData *defaultPlttOutline;
    struct PlttData *pltArrow;
    struct PlttData *pltOutline;
    if (gBattleStruct->ballSpriteIds[1] == MAX_SPRITES)
        return;
    paletteNum *= 16;
    pltArrow = (struct PlttData *)&gPlttBufferFaded[paletteNum + 9];  // Arrow color is in idx 9
    pltOutline = (struct PlttData *)&gPlttBufferFaded[paletteNum + 8];  // Arrow outline is in idx 8
    if (!showArrows) //Make invisible
    {
        defaultPlttArrow = (struct PlttData *)&gPlttBufferFaded[paletteNum + 13];  // Background color is idx 13
        pltArrow->r = defaultPlttArrow->r;
        pltArrow->g = defaultPlttArrow->g;
        pltArrow->b = defaultPlttArrow->b;
        pltOutline->r = defaultPlttArrow->r;
        pltOutline->g = defaultPlttArrow->g;
        pltOutline->b = defaultPlttArrow->b;
    }
    else // Make gray
    {
        defaultPlttArrow = (struct PlttData *)&gPlttBufferFaded[paletteNum + 11];  // Grey color is idx 11
        defaultPlttOutline = (struct PlttData *)&gPlttBufferFaded[paletteNum + 10];  //Light grey color for outline is idx 10
        pltArrow->r = defaultPlttArrow->r;
        pltArrow->g = defaultPlttArrow->g;
        pltArrow->b = defaultPlttArrow->b;
        pltOutline->r = defaultPlttOutline->r;
        pltOutline->g = defaultPlttOutline->g;
        pltOutline->b = defaultPlttOutline->b;
    }
#endif
}

void CategoryIcons_LoadSpritesGfx(void)
{
    LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
    LoadSpritePalette(&gSpritePal_CategoryIcons);
}

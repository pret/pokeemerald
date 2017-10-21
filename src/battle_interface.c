#include "global.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "sound.h"
#include "songs.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "species.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"
#include "battle_anim.h"

enum
{
    HEALTH_BAR,
    EXP_BAR
};

struct TestingBar
{
    s32 maxValue;
    s32 currValue;
    s32 field_8;
    u32 unkC_0:5;
    u32 unk10;
};

enum
{
    HEALTHBOX_GFX_0,
    HEALTHBOX_GFX_1,
    HEALTHBOX_GFX_2,
    HEALTHBOX_GFX_3,
    HEALTHBOX_GFX_4,
    HEALTHBOX_GFX_5,
    HEALTHBOX_GFX_6,
    HEALTHBOX_GFX_7,
    HEALTHBOX_GFX_8,
    HEALTHBOX_GFX_9,
    HEALTHBOX_GFX_10,
    HEALTHBOX_GFX_11,
    HEALTHBOX_GFX_12,
    HEALTHBOX_GFX_13,
    HEALTHBOX_GFX_14,
    HEALTHBOX_GFX_15,
    HEALTHBOX_GFX_16,
    HEALTHBOX_GFX_17,
    HEALTHBOX_GFX_18,
    HEALTHBOX_GFX_19,
    HEALTHBOX_GFX_20,
    HEALTHBOX_GFX_STATUS_PSN_BANK0,
    HEALTHBOX_GFX_22,
    HEALTHBOX_GFX_23,
    HEALTHBOX_GFX_STATUS_PRZ_BANK0,
    HEALTHBOX_GFX_25,
    HEALTHBOX_GFX_26,
    HEALTHBOX_GFX_STATUS_SLP_BANK0,
    HEALTHBOX_GFX_28,
    HEALTHBOX_GFX_29,
    HEALTHBOX_GFX_STATUS_FRZ_BANK0,
    HEALTHBOX_GFX_31,
    HEALTHBOX_GFX_32,
    HEALTHBOX_GFX_STATUS_BRN_BANK0,
    HEALTHBOX_GFX_34,
    HEALTHBOX_GFX_35,
    HEALTHBOX_GFX_36,
    HEALTHBOX_GFX_37,
    HEALTHBOX_GFX_38,
    HEALTHBOX_GFX_39,
    HEALTHBOX_GFX_40,
    HEALTHBOX_GFX_41,
    HEALTHBOX_GFX_42,
    HEALTHBOX_GFX_43,
    HEALTHBOX_GFX_44,
    HEALTHBOX_GFX_45,
    HEALTHBOX_GFX_46,
    HEALTHBOX_GFX_47,
    HEALTHBOX_GFX_48,
    HEALTHBOX_GFX_49,
    HEALTHBOX_GFX_50,
    HEALTHBOX_GFX_51,
    HEALTHBOX_GFX_52,
    HEALTHBOX_GFX_53,
    HEALTHBOX_GFX_54,
    HEALTHBOX_GFX_55,
    HEALTHBOX_GFX_56,
    HEALTHBOX_GFX_57,
    HEALTHBOX_GFX_58,
    HEALTHBOX_GFX_59,
    HEALTHBOX_GFX_60,
    HEALTHBOX_GFX_61,
    HEALTHBOX_GFX_62,
    HEALTHBOX_GFX_63,
    HEALTHBOX_GFX_64,
    HEALTHBOX_GFX_65,
    HEALTHBOX_GFX_66,
    HEALTHBOX_GFX_67,
    HEALTHBOX_GFX_68,
    HEALTHBOX_GFX_69,
    HEALTHBOX_GFX_70,
    HEALTHBOX_GFX_STATUS_PSN_BANK1,
    HEALTHBOX_GFX_72,
    HEALTHBOX_GFX_73,
    HEALTHBOX_GFX_STATUS_PRZ_BANK1,
    HEALTHBOX_GFX_75,
    HEALTHBOX_GFX_76,
    HEALTHBOX_GFX_STATUS_SLP_BANK1,
    HEALTHBOX_GFX_78,
    HEALTHBOX_GFX_79,
    HEALTHBOX_GFX_STATUS_FRZ_BANK1,
    HEALTHBOX_GFX_81,
    HEALTHBOX_GFX_82,
    HEALTHBOX_GFX_STATUS_BRN_BANK1,
    HEALTHBOX_GFX_84,
    HEALTHBOX_GFX_85,
    HEALTHBOX_GFX_STATUS_PSN_BANK2,
    HEALTHBOX_GFX_87,
    HEALTHBOX_GFX_88,
    HEALTHBOX_GFX_STATUS_PRZ_BANK2,
    HEALTHBOX_GFX_90,
    HEALTHBOX_GFX_91,
    HEALTHBOX_GFX_STATUS_SLP_BANK2,
    HEALTHBOX_GFX_93,
    HEALTHBOX_GFX_94,
    HEALTHBOX_GFX_STATUS_FRZ_BANK2,
    HEALTHBOX_GFX_96,
    HEALTHBOX_GFX_97,
    HEALTHBOX_GFX_STATUS_BRN_BANK2,
    HEALTHBOX_GFX_99,
    HEALTHBOX_GFX_100,
    HEALTHBOX_GFX_STATUS_PSN_BANK3,
    HEALTHBOX_GFX_102,
    HEALTHBOX_GFX_103,
    HEALTHBOX_GFX_STATUS_PRZ_BANK3,
    HEALTHBOX_GFX_105,
    HEALTHBOX_GFX_106,
    HEALTHBOX_GFX_STATUS_SLP_BANK3,
    HEALTHBOX_GFX_108,
    HEALTHBOX_GFX_109,
    HEALTHBOX_GFX_STATUS_FRZ_BANK3,
    HEALTHBOX_GFX_111,
    HEALTHBOX_GFX_112,
    HEALTHBOX_GFX_STATUS_BRN_BANK3,
    HEALTHBOX_GFX_114,
    HEALTHBOX_GFX_115,
    HEALTHBOX_GFX_116,
    HEALTHBOX_GFX_117,
};

extern u8 gBanksByIdentity[BATTLE_BANKS_COUNT];
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];

extern const u8 * const gNatureNamePointers[];
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];

// strings
extern const u8 gText_Slash[];
extern const u8 gText_HighlightDarkGrey[];
extern const u8 gText_DynColor2[];
extern const u8 gText_DynColor2Male[];
extern const u8 gText_DynColor1Female[];
extern const u8 gText_SafariBalls[];
extern const u8 gText_SafariBallLeft[];

// graphics
extern const u8 gBattleInterface_BallStatusBarGfx[];
extern const u8 gBattleInterface_BallDisplayGfx[];
extern const u16 gBattleInterface_BallStatusBarPal[];
extern const u16 gBattleInterface_BallDisplayPal[];
extern const u8 gHealthboxElementsGfxTable[][32];

// functions
extern bool8 IsDoubleBattle(void);
extern void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor *color, s8 speed, const u8 *str); // menu.h
extern void LoadBattleBarGfx(u8 arg0);

// this file's functions

static const u8 *GetHealthboxElementGfxPtr(u8 elementId);
static u8* AddTextPrinterAndCreateWindowOnHealthbox(const u8 *str, u32 x, u32 y, u32 arg3, u32 *windowId);

static void RemoveWindowOnHealthbox(u32 windowId);
static void UpdateHpTextInHealthboxInDoubles(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent);
static void UpdateStatusIconInHealthbox(u8 healthboxSpriteId);

static void sub_8075198(void *dest, u8 *windowTileData, s32 arg2);
static void sub_80751E4(void *dest, u8 *windowTileData, u32 arg2);
static void sub_8075170(void *dest, u8 *windowTileData, u32 arg2);
static void sub_807513C(void *dest, u32 arg1, u32 arg2);

static void sub_8073E08(u8 taskId);
static void sub_8073F98(u8 taskId);
static void sub_8073E64(u8 taskId);

static void sub_8072924(struct Sprite *sprite);
static void sub_80728B4(struct Sprite *sprite);
static void sub_8074158(struct Sprite *sprite);
static void sub_8074090(struct Sprite *sprite);
static void SpriteCB_StatusSummaryBar(struct Sprite *sprite);
static void SpriteCB_StatusSummaryBallsOnBattleStart(struct Sprite *sprite);
static void SpriteCB_StatusSummaryBallsOnSwitchout(struct Sprite *sprite);

static u8 GetStatusIconForBankId(u8 statusElementId, u8 bank);
static s32 sub_8074DB8(s32 maxValue, s32 currValue, s32 arg2, s32 *arg3, u8 arg4, u16 arg5);
static u8 GetScaledExpFraction(s32 currValue, s32 arg1, s32 maxValue, u8 scale);
static void sub_8074B9C(u8 bank, u8 whichBar);
static u8 sub_8074E8C(s32 maxValue, s32 currValue, s32 arg2, s32 *arg3, u8 *arg4, u8 arg5);
static void sub_8074F88(struct TestingBar *barInfo, s32 *arg1, u16 *arg2);

// const rom data
static const struct OamData sUnknown_0832C138 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
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
        .oam = &sUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_PLAYER2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sUnknown_0832C138,
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
        .oam = &sUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_OPPONENT2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sUnknown_0832C138,
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
    .oam = &sUnknown_0832C138,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sUnknown_0832C1B8 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sUnknown_0832C1C0[4] =
{
    {
        .tileTag = 0xd704,
        .paletteTag = 0xd704,
        .oam = &sUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd705,
        .paletteTag = 0xd704,
        .oam = &sUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd706,
        .paletteTag = 0xd704,
        .oam = &sUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd707,
        .paletteTag = 0xd704,
        .oam = &sUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    }
};

static const struct Subsprite sUnknown_0832C220[] =
{
    {240,   0,  1,  3,  0,      1},
    {48,    0,  0,  2,  32,     1},
    {240,   32, 1,  1,  48,     1},
    {16,    32, 1,  1,  52,     1},
    {48,    32, 1,  1,  56,     1}
};

static const struct Subsprite sUnknown_0832C234[] =
{
    {240,   0,  1,  3,  64,     1},
    {48,    0,  0,  2,  96,     1},
    {240,   32, 1,  1,  112,    1},
    {16,    32, 1,  1,  116,    1},
    {48,    32, 1,  1,  120,    1}
};

static const struct Subsprite sUnknown_0832C248[] =
{
    {240,   0,  1,  3,  0,      1},
    {48,    0,  0,  2,  32,     1}
};

static const struct Subsprite sUnknown_0832C250[] =
{
    {240,   0,  1,  3,  0,      1},
    {48,    0,  0,  2,  32,     1}
};

static const struct Subsprite sUnknown_0832C258[] =
{
    {240,   0,  1,  1,  0,      1},
    {16,    0,  1,  1,  4,      1}
};

static const struct Subsprite sUnknown_0832C260[] =
{
    {240,   0,  1,  1,  0,      1},
    {16,    0,  1,  1,  4,      1},
    {224,   0,  0,  0,  8,      1}
};

// unused subsprite table
static const struct SubspriteTable sUnknown_0832C26C[] =
{
    {ARRAY_COUNT(sUnknown_0832C220), sUnknown_0832C220},
    {ARRAY_COUNT(sUnknown_0832C248), sUnknown_0832C248},
    {ARRAY_COUNT(sUnknown_0832C234), sUnknown_0832C234},
    {ARRAY_COUNT(sUnknown_0832C250), sUnknown_0832C250}
};

static const struct SubspriteTable sUnknown_0832C28C[] =
{
    {ARRAY_COUNT(sUnknown_0832C258), sUnknown_0832C258},
    {ARRAY_COUNT(sUnknown_0832C260), sUnknown_0832C260}
};

static const struct Subsprite sStatusSummaryBar_Subsprites_0[] =
{
    {160,   0,  1,  1,  0,      1},
    {192,   0,  1,  1,  4,      1},
    {224,   0,  1,  1,  8,      1},
    {0,     0,  1,  1,  12,     1}
};

static const struct Subsprite sUnknown_0832C2AC[] =
{
    {160,   0,  1,  1,  0,      1},
    {192,   0,  1,  1,  4,      1},
    {224,   0,  1,  1,  8,      1},
    {0,     0,  1,  1,  8,      1},
    {32,    0,  1,  1,  8,      1},
    {64,    0,  1,  1,  12,     1}
};

static const struct SubspriteTable sStatusSummaryBar_SubspriteTable[] =
{
    {ARRAY_COUNT(sStatusSummaryBar_Subsprites_0), sStatusSummaryBar_Subsprites_0}
};

static const struct SubspriteTable sUnknown_0832C2CC[] =
{
    {ARRAY_COUNT(sUnknown_0832C2AC), sUnknown_0832C2AC}
};

// unused unknown image
static const u8 sUnknown_0832C2D4[] = INCBIN_U8("graphics/battle_interface/unknown_32C2D4.4bpp");

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
    gBattleInterface_BallDisplayGfx, 0x80, TAG_STATUS_SUMMARY_BALLS_TILE
};

// unused oam data
static const struct OamData sUnknown_0832C354 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOamData_StatusSummaryBalls =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sStatusSummaryBarSpriteTemplates[2] =
{
    {
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar
    },
    {
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar
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
        .callback = SpriteCB_StatusSummaryBallsOnBattleStart
    },
    {
        .tileTag = TAG_STATUS_SUMMARY_BALLS_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BALLS_PAL,
        .oam = &sOamData_StatusSummaryBalls,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBallsOnBattleStart
    }
};

// possibly text
static const u8 sUnknown_0832C3C4[] =
{
    0xfc, 0x01, 0x01, 0xfc, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

// possibly text
static const u8 sUnknown_0832C3D8[] =
{
    0xfc, 0x01, 0x01, 0xfc, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

enum
{
    PAL_STATUS_PSN,
    PAL_STATUS_PAR,
    PAL_STATUS_SLP,
    PAL_STATUS_FRZ,
    PAL_STATUS_BRN
};

static const u16 sStatusIconPalettes[] =
{
    0x6198, // PAL_STATUS_PSN
    0xEF7, // PAL_STATUS_PAR
    0x4694, // PAL_STATUS_SLP
    0x72D1, // PAL_STATUS_FRZ
    0x29DC // PAL_STATUS_BRN
};

static const struct WindowTemplate sHealthboxWindowTemplate = {0, 0, 0, 8, 2, 0, 0}; // width = 8, height = 2

// code

static s32 DummiedOutFunction(s16 unused1, s16 unused2, s32 unused3)
{
    return 9;
}

#ifdef NONMATCHING
static void sub_8072308(s16 arg0, u16 *arg1, u8 arg2)
{
    s8 i, j;
    u8 array[4];
    u8 *arrayPtr;
    s32 r9, vaaa;

    for (i = 0; i < 4; i++)
        array[i] = 0;

    i = 3;
    r9 = -1;
    arrayPtr = array;
    while (1)
    {
        if (arg0 > 0)
        {
            array[i] = arg0 % 10;
            arg0 = arg0 / 10;
            i--;
        }
        else
        {
            break;
        }
    }

    for (; i > -1; i--)
    {
        array[i] = 0xFF;
    }

    if (arrayPtr[3] == 0xFF)
        arrayPtr[3] = 0;

    if (arg2 == 0)
    {
        for (i = 0, j = 0; i < 4; i++)
        {
            if (array[j] == 0xFF)
            {
                arg1[j] &= 0xFC00;
                arg1[j] |= 0x1E;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= 0x1E;
            }
            else
            {
                arg1[j] &= 0xFC00;
                arg1[j] |= array[j] + 0x14;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= array[i] + 0x34;
            }
            j++;
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (array[i] == 0xFF)
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= 0x1E;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= 0x1E;
            }
            else
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= array[i] + 0x14;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= array[i] + 0x34;
            }
        }
    }
}

#else
__attribute__((naked))
static void sub_8072308(s16 arg0, u16 *arg1, u8 arg2)
{
    asm(".syntax unified\n\
        	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x4\n\
	adds r7, r1, 0\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	mov r10, r2\n\
	movs r3, 0\n\
	movs r2, 0\n\
_08072324:\n\
	lsls r0, r3, 24\n\
	asrs r0, 24\n\
	mov r3, sp\n\
	adds r1, r3, r0\n\
	strb r2, [r1]\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _08072324\n\
	movs r3, 0x3\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	mov r9, r0\n\
	mov r8, sp\n\
_08072344:\n\
	lsls r0, r5, 16\n\
	asrs r6, r0, 16\n\
	cmp r6, 0\n\
	ble _08072372\n\
	lsls r4, r3, 24\n\
	asrs r4, 24\n\
	mov r1, sp\n\
	adds r5, r1, r4\n\
	adds r0, r6, 0\n\
	movs r1, 0xA\n\
	bl __modsi3\n\
	strb r0, [r5]\n\
	adds r0, r6, 0\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	subs r4, 0x1\n\
	lsls r4, 24\n\
	lsrs r3, r4, 24\n\
	b _08072344\n\
_08072372:\n\
	lsls r1, r3, 24\n\
	asrs r0, r1, 24\n\
	cmp r0, r9\n\
	ble _08072396\n\
	movs r4, 0xFF\n\
	movs r3, 0x1\n\
	negs r3, r3\n\
_08072380:\n\
	asrs r2, r1, 24\n\
	mov r5, sp\n\
	adds r1, r5, r2\n\
	ldrb r0, [r1]\n\
	orrs r0, r4\n\
	strb r0, [r1]\n\
	subs r2, 0x1\n\
	lsls r1, r2, 24\n\
	asrs r0, r1, 24\n\
	cmp r0, r3\n\
	bgt _08072380\n\
_08072396:\n\
	mov r1, r8\n\
	ldrb r0, [r1, 0x3]\n\
	cmp r0, 0xFF\n\
	bne _080723A2\n\
	movs r0, 0\n\
	strb r0, [r1, 0x3]\n\
_080723A2:\n\
	mov r2, r10\n\
	cmp r2, 0\n\
	bne _08072432\n\
	movs r3, 0\n\
	movs r1, 0\n\
	movs r6, 0xFC\n\
	lsls r6, 8\n\
	movs r5, 0x1E\n\
	mov r12, r5\n\
_080723B4:\n\
	lsls r1, 24\n\
	asrs r2, r1, 24\n\
	mov r0, sp\n\
	adds r5, r0, r2\n\
	ldrb r0, [r5]\n\
	mov r8, r1\n\
	cmp r0, 0xFF\n\
	bne _080723EA\n\
	lsls r1, r2, 1\n\
	adds r1, r7\n\
	ldrh r2, [r1]\n\
	adds r0, r6, 0\n\
	ands r0, r2\n\
	mov r2, r12\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	lsls r3, 24\n\
	asrs r1, r3, 23\n\
	adds r1, r7\n\
	adds r1, 0x40\n\
	ldrh r2, [r1]\n\
	adds r0, r6, 0\n\
	ands r0, r2\n\
	mov r5, r12\n\
	orrs r0, r5\n\
	strh r0, [r1]\n\
	b _0807241A\n\
_080723EA:\n\
	lsls r2, 1\n\
	adds r2, r7\n\
	ldrh r0, [r2]\n\
	adds r1, r6, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x14\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	lsls r4, r3, 24\n\
	asrs r3, r4, 24\n\
	lsls r2, r3, 1\n\
	adds r2, r7\n\
	adds r2, 0x40\n\
	ldrh r0, [r2]\n\
	adds r1, r6, 0\n\
	ands r1, r0\n\
	mov r5, sp\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	adds r0, 0x34\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	adds r3, r4, 0\n\
_0807241A:\n\
	movs r0, 0x80\n\
	lsls r0, 17\n\
	add r0, r8\n\
	lsrs r1, r0, 24\n\
	movs r2, 0x80\n\
	lsls r2, 17\n\
	adds r0, r3, r2\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _080723B4\n\
	b _08072496\n\
_08072432:\n\
	movs r3, 0\n\
	movs r4, 0xFC\n\
	lsls r4, 8\n\
	movs r6, 0x1E\n\
_0807243A:\n\
	lsls r1, r3, 24\n\
	asrs r2, r1, 24\n\
	mov r3, sp\n\
	adds r5, r3, r2\n\
	ldrb r0, [r5]\n\
	adds r3, r1, 0\n\
	cmp r0, 0xFF\n\
	bne _08072466\n\
	lsls r1, r2, 1\n\
	adds r1, r7\n\
	ldrh r2, [r1]\n\
	adds r0, r4, 0\n\
	ands r0, r2\n\
	orrs r0, r6\n\
	strh r0, [r1]\n\
	adds r1, 0x40\n\
	ldrh r2, [r1]\n\
	adds r0, r4, 0\n\
	ands r0, r2\n\
	orrs r0, r6\n\
	strh r0, [r1]\n\
	b _08072488\n\
_08072466:\n\
	lsls r2, 1\n\
	adds r2, r7\n\
	ldrh r0, [r2]\n\
	adds r1, r4, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x14\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	adds r2, 0x40\n\
	ldrh r0, [r2]\n\
	adds r1, r4, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x34\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
_08072488:\n\
	movs r5, 0x80\n\
	lsls r5, 17\n\
	adds r0, r3, r5\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _0807243A\n\
_08072496:\n\
	add sp, 0x4\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
        .syntax divided");
}

#endif // NONMATCHING

void sub_80724A8(s16 arg0, s16 arg1, u16 *arg2)
{
    arg2[4] = 0x1E;
    sub_8072308(arg1, arg2, 0);
    sub_8072308(arg0, arg2 + 5, 1);
}

// because the healthbox is too large to fit into one sprite, it is divided into two sprites
// healthboxSpriteId_1 or healthboxSpriteId refers to the 'main' healthbox
// healthboxSpriteId_2 refers to the other part
// there's also one other sprite that appears to be a black square? dont fully understand its role

u8 CreateBankHealthboxSprites(u8 bank)
{
    s16 data6 = 0;
    u8 healthboxSpriteId_1, healthboxSpriteId_2;
    u8 unkSpriteId;
    struct Sprite *unkSpritePtr;

    if (!IsDoubleBattle())
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            healthboxSpriteId_1 = CreateSprite(&sHealthboxPlayerSpriteTemplates[0], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[0], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.shape = 0;

            gSprites[healthboxSpriteId_2].oam.shape = 0;
            gSprites[healthboxSpriteId_2].oam.tileNum += 64;
        }
        else
        {
            healthboxSpriteId_1 = CreateSprite(&sHealthboxOpponentSpriteTemplates[0], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[0], 240, 160, 1);

            gSprites[healthboxSpriteId_2].oam.tileNum += 32;

            data6 = 2;
        }
        gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;
        gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
        gSprites[healthboxSpriteId_2].callback = sub_8072924;
    }
    else
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            healthboxSpriteId_1 = CreateSprite(&sHealthboxPlayerSpriteTemplates[GetBankIdentity(bank) / 2], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[GetBankIdentity(bank) / 2], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;

            gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
            gSprites[healthboxSpriteId_2].oam.tileNum += 32;
            gSprites[healthboxSpriteId_2].callback = sub_8072924;

            data6 = 1;
        }
        else
        {
            healthboxSpriteId_1 = CreateSprite(&sHealthboxOpponentSpriteTemplates[GetBankIdentity(bank) / 2], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[GetBankIdentity(bank) / 2], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;

            gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
            gSprites[healthboxSpriteId_2].oam.tileNum += 32;
            gSprites[healthboxSpriteId_2].callback = sub_8072924;

            data6 = 2;
        }
    }

    unkSpriteId = CreateSpriteAtEnd(&sUnknown_0832C1C0[gBanksByIdentity[bank]], 140, 60, 0);
    unkSpritePtr = &gSprites[unkSpriteId];
    SetSubspriteTables(unkSpritePtr, &sUnknown_0832C28C[GetBankSide(bank)]);
    unkSpritePtr->subspriteMode = 2;
    unkSpritePtr->oam.priority = 1;

    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void*)(OBJ_VRAM0 + unkSpritePtr->oam.tileNum * 32), 64);

    gSprites[healthboxSpriteId_1].data5 = unkSpriteId;
    gSprites[healthboxSpriteId_1].data6 = bank;
    gSprites[healthboxSpriteId_1].invisible = 1;

    gSprites[healthboxSpriteId_2].invisible = 1;

    unkSpritePtr->data5 = healthboxSpriteId_1;
    unkSpritePtr->data6 = data6;
    unkSpritePtr->invisible = 1;

    return healthboxSpriteId_1;
}

u8 CreateSafariPlayerHealthboxSprites(void)
{
    u8 healthboxSpriteId_1, healthboxSpriteId_2;

    healthboxSpriteId_1 = CreateSprite(&sHealthboxSafariSpriteTemplate, 240, 160, 1);
    healthboxSpriteId_2 = CreateSpriteAtEnd(&sHealthboxSafariSpriteTemplate, 240, 160, 1);

    gSprites[healthboxSpriteId_1].oam.shape = 0;
    gSprites[healthboxSpriteId_2].oam.shape = 0;

    gSprites[healthboxSpriteId_2].oam.tileNum += 64;

    gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;
    gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;

    gSprites[healthboxSpriteId_2].callback = sub_8072924;

    return healthboxSpriteId_1;
}

static const u8 *GetHealthboxElementGfxPtr(u8 elementId)
{
    return gHealthboxElementsGfxTable[elementId];
}

static void sub_80728B4(struct Sprite *sprite)
{
    u8 var = sprite->data5;

    switch (sprite->data6)
    {
    case 0:
        sprite->pos1.x = gSprites[var].pos1.x + 16;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    case 1:
        sprite->pos1.x = gSprites[var].pos1.x + 16;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    case 2:
    default:
        sprite->pos1.x = gSprites[var].pos1.x + 8;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    }

    sprite->pos2.x = gSprites[var].pos2.x;
    sprite->pos2.y = gSprites[var].pos2.y;
}

static void sub_8072924(struct Sprite *sprite)
{
    u8 otherSpriteId = sprite->data5;

    sprite->pos1.x = gSprites[otherSpriteId].pos1.x + 64;
    sprite->pos1.y = gSprites[otherSpriteId].pos1.y;

    sprite->pos2.x = gSprites[otherSpriteId].pos2.x;
    sprite->pos2.y = gSprites[otherSpriteId].pos2.y;
}

void SetBattleBarStruct(u8 bank, u8 healthboxSpriteId, s32 maxVal, s32 currVal, s32 field_C)
{
    gBattleSpritesDataPtr->battleBars[bank].healthboxSpriteId = healthboxSpriteId;
    gBattleSpritesDataPtr->battleBars[bank].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[bank].currentValue = currVal;
    gBattleSpritesDataPtr->battleBars[bank].field_C = field_C;
    gBattleSpritesDataPtr->battleBars[bank].field_10 = -32768;
}

void SetHealthboxSpriteInvisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = 1;
    gSprites[gSprites[healthboxSpriteId].data5].invisible = 1;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = 1;
}

void SetHealthboxSpriteVisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = 0;
    gSprites[gSprites[healthboxSpriteId].data5].invisible = 0;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = 0;
}

static void UpdateSpritePos(u8 spriteId, s16 x, s16 y)
{
    gSprites[spriteId].pos1.x = x;
    gSprites[spriteId].pos1.y = y;
}

void DestoryHealthboxSprite(u8 healthboxSpriteId)
{
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].oam.affineParam]);
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].data5]);
    DestroySprite(&gSprites[healthboxSpriteId]);
}

void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly)
{

}

void UpdateOamPriorityInAllHealthboxes(u8 priority)
{
    s32 i;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        u8 healthboxSpriteId_1 = gHealthBoxesIds[i];
        u8 healthboxSpriteId_2 = gSprites[gHealthBoxesIds[i]].oam.affineParam;
        u8 healthboxSpriteId_3 = gSprites[gHealthBoxesIds[i]].data5;

        gSprites[healthboxSpriteId_1].oam.priority = priority;
        gSprites[healthboxSpriteId_2].oam.priority = priority;
        gSprites[healthboxSpriteId_3].oam.priority = priority;
    }
}

void SetBankHealthboxSpritePos(u8 bank)
{
    s16 x = 0, y = 0;

    if (!IsDoubleBattle())
    {
        if (GetBankSide(bank) != SIDE_PLAYER)
            x = 44, y = 30;
        else
            x = 158, y = 88;
    }
    else
    {
        switch (GetBankIdentity(bank))
        {
        case IDENTITY_PLAYER_MON1:
            x = 159, y = 76;
            break;
        case IDENTITY_PLAYER_MON2:
            x = 171, y = 101;
            break;
        case IDENTITY_OPPONENT_MON1:
            x = 44, y = 19;
            break;
        case IDENTITY_OPPONENT_MON2:
            x = 32, y = 44;
            break;
        }
    }

    UpdateSpritePos(gHealthBoxesIds[bank], x, y);
}

static void UpdateLvlInHealthbox(u8 healthboxSpriteId, u8 lvl)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;
    u8 text[16];
    u32 xPos, var1;
    void *objVram;

    text[0] = 0xF9;
    text[1] = 5;

    xPos = (u32) ConvertIntToDecimalStringN(text + 2, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
    // Alright, that part was unmatchable. It's basically doing:
    // xPos = 5 * (3 - (u32)(&text[2]));
    xPos--;
    xPos--;
    xPos -= ((u32)(text));
    var1 = (3 - xPos);
    xPos = 4 * var1;
    xPos += var1;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, xPos, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        objVram = (void*)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            objVram += spriteTileNum + 0x820;
        else
            objVram += spriteTileNum + 0x420;
    }
    else
    {
        objVram = (void*)(OBJ_VRAM0);
        objVram += spriteTileNum + 0x400;
    }
    sub_8075198(objVram, windowTileData, 3);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHpTextInHealthbox(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;
    u8 text[32];
    void *objVram;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER && !IsDoubleBattle())
    {
        spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
        if (maxOrCurrent != HP_CURRENT) // singles, max
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 2, &windowId);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB40;
            sub_8075170(objVram, windowTileData, 2);
            RemoveWindowOnHealthbox(windowId);
        }
        else // singles, current
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text[3] = CHAR_SLASH;
            text[4] = EOS;
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 2, &windowId);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0x3E0;
            sub_8075170(objVram, windowTileData, 1);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB00;
            sub_8075170(objVram, windowTileData + 0x20, 2);
            RemoveWindowOnHealthbox(windowId);
        }

    }
    else
    {
        u8 bank;

        memcpy(text, sUnknown_0832C3C4, sizeof(sUnknown_0832C3C4));
        bank = gSprites[healthboxSpriteId].data6;
        if (IsDoubleBattle() == TRUE || GetBankSide(bank) == SIDE_OPPONENT)
        {
            UpdateHpTextInHealthboxInDoubles(healthboxSpriteId, value, maxOrCurrent);
        }
        else
        {
            u32 var;
            u8 i;

            if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
            {
                if (maxOrCurrent == HP_CURRENT)
                    var = 29;
                else
                    var = 89;
            }
            else
            {
                if (maxOrCurrent == HP_CURRENT)
                    var = 20;
                else
                    var = 48;
            }

            ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

            for (i = 0; i < 3; i++)
            {
                CpuCopy32(&gMonSpritesGfxPtr->fontPixels[i * 64 + 32],
                          (void*)((OBJ_VRAM0) + 32 * (gSprites[healthboxSpriteId].oam.tileNum + var + i)),
                          0x20);
            }
        }
    }
}

static void UpdateHpTextInHealthboxInDoubles(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;
    u8 text[32];
    void *objVram;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        if (gBattleSpritesDataPtr->bankData[gSprites[healthboxSpriteId].data6].hpNumbersNoBars) // don't print text if only bars are visible
        {
            spriteTileNum = gSprites[gSprites[healthboxSpriteId].data5].oam.tileNum * 32;
            objVram = (void*)(OBJ_VRAM0) + spriteTileNum;

            if (maxOrCurrent != HP_CURRENT) // doubles, max hp
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 0, &windowId);
                sub_8075170((void*)(OBJ_VRAM0) + spriteTileNum + 0xC0, windowTileData, 2);
                RemoveWindowOnHealthbox(windowId);
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_116),
                          (void*)(OBJ_VRAM0 + 0x680) + (gSprites[healthboxSpriteId].oam.tileNum * 32),
                           0x20);
            }
            else
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                text[3] = CHAR_SLASH;
                text[4] = EOS;
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 0, &windowId);
                sub_807513C(objVram, 0, 3);
                sub_8075170((void*)(OBJ_VRAM0 + 0x60) + spriteTileNum, windowTileData, 3);
                RemoveWindowOnHealthbox(windowId);
            }
        }
    }
    else
    {
        u8 bank;

        memcpy(text, sUnknown_0832C3D8, sizeof(sUnknown_0832C3D8));
        bank = gSprites[healthboxSpriteId].data6;

        if (gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars) // don't print text if only bars are visible
        {
            u8 var = 4;
            u8 r7;
            u8 *txtPtr;
            u8 i;

            if (maxOrCurrent == HP_CURRENT)
                var = 0;

            r7 = gSprites[healthboxSpriteId].data5;
            txtPtr = ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            if (!maxOrCurrent)
                StringCopy(txtPtr, gText_Slash);
            RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

            for (i = var; i < var + 3; i++)
            {
                if (i < 3)
                {
                    CpuCopy32(&gMonSpritesGfxPtr->fontPixels[((i - var) * 64) + 32],
                          (void*)((OBJ_VRAM0) + 32 * (1 + gSprites[r7].oam.tileNum + i)),
                          0x20);
                }
                else
                {
                    CpuCopy32(&gMonSpritesGfxPtr->fontPixels[((i - var) * 64) + 32],
                          (void*)((OBJ_VRAM0 + 0x20) + 32 * (i + gSprites[r7].oam.tileNum)),
                          0x20);
                }
            }

            if (maxOrCurrent == HP_CURRENT)
            {
                CpuCopy32(&gMonSpritesGfxPtr->fontPixels[224],
                          (void*)((OBJ_VRAM0) + ((gSprites[r7].oam.tileNum + 4) * 32)),
                          0x20);
                CpuFill32(0, (void*)((OBJ_VRAM0) + (gSprites[r7].oam.tileNum * 32)), 0x20);
            }
            else
            {
                if (GetBankSide(bank) == SIDE_PLAYER) // impossible to reach part, because the bank is from the opponent's side
                {
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_116),
                          (void*)(OBJ_VRAM0) + ((gSprites[healthboxSpriteId].oam.tileNum + 52) * 32),
                           0x20);
                }
            }
        }
    }
}

static void sub_80730D4(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 text[20];
    s32 j, var2;
    u8 *fontPixels;
    u8 i, var, nature, healthboxSpriteId_2;

    memcpy(text, sUnknown_0832C3C4, sizeof(sUnknown_0832C3C4));
    fontPixels = &gMonSpritesGfxPtr->fontPixels[0x520 + (GetBankIdentity(gSprites[healthboxSpriteId].data6) * 384)];
    var = 5;
    nature = GetNature(mon);
    StringCopy(text + 6, gNatureNamePointers[nature]);
    RenderTextFont9(fontPixels, 9, text);

    for (j = 6, i = 0; i < var; i++, j++)
    {
        u8 elementId;

        if ((text[j] >= 55 && text[j] <= 74) || (text[j] >= 135 && text[j] <= 154))
            elementId = 44;
        else if ((text[j] >= 75 && text[j] <= 79) || (text[j] >= 155 && text[j] <= 159))
            elementId = 45;
        else
            elementId = 43;

        CpuCopy32(GetHealthboxElementGfxPtr(elementId), fontPixels + (i * 64), 0x20);
    }

    for (j = 1; j < var + 1; j++)
    {
        var2 = (gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * 32;
        CpuCopy32(fontPixels, (void*)(OBJ_VRAM0) + (var2), 0x20);
        fontPixels += 0x20;

        var2 = (8 + gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * 32;
        CpuCopy32(fontPixels, (void*)(OBJ_VRAM0) + (var2), 0x20);
        fontPixels += 0x20;
    }

    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;
    ConvertIntToDecimalStringN(text + 6, gBattleStruct->field_7C, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(text + 9, gBattleStruct->field_7B, STR_CONV_MODE_RIGHT_ALIGN, 2);
    text[5] = CHAR_SPACE;
    text[8] = CHAR_SLASH;
    RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

    j = healthboxSpriteId_2; // needed to match for some reason
    for (j = 0; j < 5; j++)
    {
        if (j <= 1)
        {
            CpuCopy32(&gMonSpritesGfxPtr->fontPixels[0x40 * j + 0x20],
                      (void*)(OBJ_VRAM0) + (gSprites[healthboxSpriteId_2].oam.tileNum + 2 + j) * 32,
                      32);
        }
        else
        {
            CpuCopy32(&gMonSpritesGfxPtr->fontPixels[0x40 * j + 0x20],
                      (void*)(OBJ_VRAM0 + 0xC0) + (j + gSprites[healthboxSpriteId_2].oam.tileNum) * 32,
                      32);
        }
    }
}

void SwapHpBarsWithHpText(void)
{
    s32 i;
    u8 spriteId;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gSprites[gHealthBoxesIds[i]].callback == SpriteCallbackDummy
         && GetBankSide(i) != SIDE_OPPONENT
         && (IsDoubleBattle() || GetBankSide(i) != SIDE_PLAYER))
        {
            bool8 noBars;

            gBattleSpritesDataPtr->bankData[i].hpNumbersNoBars ^= 1;
            noBars = gBattleSpritesDataPtr->bankData[i].hpNumbersNoBars;
            if (GetBankSide(i) == SIDE_PLAYER)
            {
                if (!IsDoubleBattle())
                    continue;
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    continue;

                if (noBars == TRUE) // bars to text
                {
                    spriteId = gSprites[gHealthBoxesIds[i]].data5;

                    CpuFill32(0, (void*)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * 32), 0x100);
                    UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gPlayerParty[gBattlePartyID[i]], MON_DATA_HP), HP_CURRENT);
                    UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gPlayerParty[gBattlePartyID[i]], MON_DATA_MAX_HP), HP_MAX);
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthBoxesIds[i]);
                    UpdateHealthboxAttribute(gHealthBoxesIds[i], &gPlayerParty[gBattlePartyID[i]], HEALTHBOX_HEALTH_BAR);
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_117), (void*)(OBJ_VRAM0 + 0x680 + gSprites[gHealthBoxesIds[i]].oam.tileNum * 32), 32);
                }
            }
            else
            {
                if (noBars == TRUE) // bars to text
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    {
                        sub_80730D4(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]]);
                    }
                    else
                    {
                        spriteId = gSprites[gHealthBoxesIds[i]].data5;

                        CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * 32), 0x100);
                        UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gEnemyParty[gBattlePartyID[i]], MON_DATA_HP), HP_CURRENT);
                        UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gEnemyParty[gBattlePartyID[i]], MON_DATA_MAX_HP), HP_MAX);
                    }
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthBoxesIds[i]);
                    UpdateHealthboxAttribute(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]], HEALTHBOX_HEALTH_BAR);
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                        UpdateHealthboxAttribute(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]], HEALTHBOX_NICK);
                }
            }
            gSprites[gHealthBoxesIds[i]].data7 ^= 1;
        }
    }
}

u8 CreatePartyStatusSummarySprites(u8 bank, struct HpAndStatus *partyInfo, u8 arg2, bool8 isBattleStart)
{
    bool8 isOpponent;
    s16 bar_X, bar_Y, bar_pos2_X, bar_data0;
    s32 i, j, var;
    u8 barSpriteId;
    u8 ballIconSpritesIds[6];
    u8 taskId;

    if (!arg2 || GetBankIdentity(bank) != IDENTITY_OPPONENT_MON2)
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            isOpponent = FALSE;
            bar_X = 136, bar_Y = 96;
            bar_pos2_X = 100;
            bar_data0 = -5;
        }
        else
        {
            isOpponent = TRUE;

            if (!arg2 || !IsDoubleBattle())
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

    LoadCompressedObjectPicUsingHeap(&sStatusSummaryBarSpriteSheet);
    LoadSpriteSheet(&sStatusSummaryBallsSpriteSheet);
    LoadSpritePalette(&sStatusSummaryBarSpritePal);
    LoadSpritePalette(&sStatusSummaryBallsSpritePal);

    barSpriteId = CreateSprite(&sStatusSummaryBarSpriteTemplates[isOpponent], bar_X, bar_Y, 10);
    SetSubspriteTables(&gSprites[barSpriteId], sStatusSummaryBar_SubspriteTable);
    gSprites[barSpriteId].pos2.x = bar_pos2_X;
    gSprites[barSpriteId].data0 = bar_data0;

    if (isOpponent)
    {
        gSprites[barSpriteId].pos1.x -= 96;
        gSprites[barSpriteId].oam.matrixNum = 8;
    }
    else
    {
        gSprites[barSpriteId].pos1.x += 96;
    }

    for (i = 0; i < 6; i++)
    {
        ballIconSpritesIds[i] = CreateSpriteAtEnd(&sStatusSummaryBallsSpriteTemplates[isOpponent], bar_X, bar_Y - 4, 9);

        if (!isBattleStart)
            gSprites[ballIconSpritesIds[i]].callback = SpriteCB_StatusSummaryBallsOnSwitchout;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].pos2.x = 0;
            gSprites[ballIconSpritesIds[i]].pos2.y = 0;
        }

        gSprites[ballIconSpritesIds[i]].data0 = barSpriteId;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].pos1.x += 10 * i + 24;
            gSprites[ballIconSpritesIds[i]].data1 = i * 7 + 10;
            gSprites[ballIconSpritesIds[i]].pos2.x = 120;
        }
        else
        {
            gSprites[ballIconSpritesIds[i]].pos1.x -= 10 * (5 - i) + 24;
            gSprites[ballIconSpritesIds[i]].data1 = (6 - i) * 7 + 10;
            gSprites[ballIconSpritesIds[i]].pos2.x = -120;
        }

        gSprites[ballIconSpritesIds[i]].data2 = isOpponent;
    }

    if (GetBankSide(bank) == SIDE_PLAYER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < 6; i++)
            {
                if (partyInfo[i].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data7 = 1;
                }
                else if (partyInfo[i].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
            }
        }
        else
        {
            for (i = 0, var = 5, j = 0; j < 6; j++)
            {
                if (partyInfo[j].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data7 = 1;
                    var--;
                    continue;
                }
                else if (partyInfo[j].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->field_2A0 & gBitTable[j]) // hmm...?
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0) // mon with major status
                {
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
            for (var = 5, i = 0; i < 6; i++)
            {
                if (partyInfo[i].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data7 = 1;
                }
                else if (partyInfo[i].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 2;
                }
                var--;
            }
        }
        else
        {
            for (var = 0, i = 0, j = 0; j < 6; j++)
            {
                if (partyInfo[j].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data7 = 1;
                    i++;
                    continue;
                }
                else if (partyInfo[j].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->field_2A1 & gBitTable[j]) // hmm...?
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 2;
                }
                var++;
            }
        }
    }

    taskId = CreateTask(TaskDummy, 5);
    gTasks[taskId].data[0] = bank;
    gTasks[taskId].data[1] = barSpriteId;

    for (i = 0; i < 6; i++)
        gTasks[taskId].data[3 + i] = ballIconSpritesIds[i];

    gTasks[taskId].data[10] = isBattleStart;

    if (isBattleStart)
    {
        gBattleSpritesDataPtr->animationData->field_9_x1C++;
    }

    PlaySE12WithPanning(SE_TB_START, 0);
    return taskId;
}

void sub_8073C30(u8 taskId)
{
    u8 sp[6];
    u8 r7;
    u8 r10;
    u8 bank;
    s32 i;

    r7 = gTasks[taskId].data[10];
    r10 = gTasks[taskId].data[1];
    bank = gTasks[taskId].data[0];

    for (i = 0; i < 6; i++)
        sp[i] = gTasks[taskId].data[3 + i];

    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x10);

    gTasks[taskId].data[15] = 16;

    for (i = 0; i < 6; i++)
        gSprites[sp[i]].oam.objMode = 1;

    gSprites[r10].oam.objMode = 1;

    if (r7 != 0)
    {
        for (i = 0; i < 6; i++)
        {
            if (GetBankSide(bank) != SIDE_PLAYER)
            {
                gSprites[sp[5 - i]].data1 = 7 * i;
                gSprites[sp[5 - i]].data3 = 0;
                gSprites[sp[5 - i]].data4 = 0;
                gSprites[sp[5 - i]].callback = sub_8074158;
            }
            else
            {
                gSprites[sp[i]].data1 = 7 * i;
                gSprites[sp[i]].data3 = 0;
                gSprites[sp[i]].data4 = 0;
                gSprites[sp[i]].callback = sub_8074158;
            }
        }
        gSprites[r10].data0 /= 2;
        gSprites[r10].data1 = 0;
        gSprites[r10].callback = sub_8074090;
        SetSubspriteTables(&gSprites[r10], sUnknown_0832C2CC);
        gTasks[taskId].func = sub_8073E08;
    }
    else
    {
        gTasks[taskId].func = sub_8073F98;
    }
}

static void sub_8073E08(u8 taskId)
{
    u16 temp = gTasks[taskId].data[11]++;

    if (!(temp & 1))
    {
        gTasks[taskId].data[15]--;
        if (gTasks[taskId].data[15] < 0)
            return;

        SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].data[15]) | ((16 - gTasks[taskId].data[15]) << 8));
    }
    if (gTasks[taskId].data[15] == 0)
        gTasks[taskId].func = sub_8073E64;
}

static void sub_8073E64(u8 taskId)
{
    u8 sp[6];
    s32 i;

    u8 bank = gTasks[taskId].data[0];
    gTasks[taskId].data[15]--;
    if (gTasks[taskId].data[15] == -1)
    {
        u8 var = gTasks[taskId].data[1];

        for (i = 0; i < 6; i++)
            sp[i] = gTasks[taskId].data[3 + i];

        gBattleSpritesDataPtr->animationData->field_9_x1C--;
        if (!gBattleSpritesDataPtr->animationData->field_9_x1C)
        {
            DestroySpriteAndFreeResources(&gSprites[var]);
            DestroySpriteAndFreeResources(&gSprites[sp[0]]);
        }
        else
        {
            FreeSpriteOamMatrix(&gSprites[var]);
            DestroySprite(&gSprites[var]);
            FreeSpriteOamMatrix(&gSprites[sp[0]]);
            DestroySprite(&gSprites[sp[0]]);
        }

        for (i = 1; i < 6; i++)
            DestroySprite(&gSprites[sp[i]]);
    }
    else if (gTasks[taskId].data[15] == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x1 = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

static void sub_8073F98(u8 taskId)
{
    u8 sp[6];
    s32 i;

    u8 bank = gTasks[taskId].data[0];
    gTasks[taskId].data[15]--;
    if (gTasks[taskId].data[15] >= 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].data[15]) | ((16 - gTasks[taskId].data[15]) << 8));
    }
    else if (gTasks[taskId].data[15] == -1)
    {
        u8 var = gTasks[taskId].data[1];

        for (i = 0; i < 6; i++)
            sp[i] = gTasks[taskId].data[3 + i];

        DestroySpriteAndFreeResources(&gSprites[var]);
        DestroySpriteAndFreeResources(&gSprites[sp[0]]);

        for (i = 1; i < 6; i++)
            DestroySprite(&gSprites[sp[i]]);
    }
    else if (gTasks[taskId].data[15] == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x1 = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

static void SpriteCB_StatusSummaryBar(struct Sprite *sprite)
{
    if (sprite->pos2.x != 0)
        sprite->pos2.x += sprite->data0;
}

static void sub_8074090(struct Sprite *sprite)
{
    sprite->data1 += 32;
    if (sprite->data0 > 0)
        sprite->pos2.x += sprite->data1 >> 4;
    else
        sprite->pos2.x -= sprite->data1 >> 4;
    sprite->data1 &= 0xF;
}

static void SpriteCB_StatusSummaryBallsOnBattleStart(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;
    s8 pan;

    if (sprite->data1 > 0)
    {
        sprite->data1--;
        return;
    }

    var1 = sprite->data2;
    var2 = sprite->data3;
    var2 += 56;
    sprite->data3 = var2 & 0xFFF0;

    if (var1 != 0)
    {
        sprite->pos2.x += var2 >> 4;
        if (sprite->pos2.x > 0)
            sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x -= var2 >> 4;
        if (sprite->pos2.x < 0)
            sprite->pos2.x = 0;
    }

    if (sprite->pos2.x == 0)
    {
        pan = PAN_SIDE_OPPONENT;
        if (var1 != 0)
            pan = PAN_SIDE_PLAYER;

        if (sprite->data7 != 0)
            PlaySE2WithPanning(SE_TB_KARA, pan);
        else
            PlaySE1WithPanning(SE_TB_KON, pan);

        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_8074158(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;

    if (sprite->data1 > 0)
    {
        sprite->data1--;
        return;
    }
    var1 = sprite->data2;
    var2 = sprite->data3;
    var2 += 56;
    sprite->data3 = var2 & 0xFFF0;
    if (var1 != 0)
        sprite->pos2.x += var2 >> 4;
    else
        sprite->pos2.x -= var2 >> 4;
    if (sprite->pos2.x + sprite->pos1.x > 248
     || sprite->pos2.x + sprite->pos1.x < -8)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBallsOnSwitchout(struct Sprite *sprite)
{
    u8 barSpriteId = sprite->data0;

    sprite->pos2.x = gSprites[barSpriteId].pos2.x;
    sprite->pos2.y = gSprites[barSpriteId].pos2.y;
}

static void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    void *ptr;
    const u8 *genderTxt;
    u32 windowId, spriteTileNum;
    u8 *windowTileData;
    u16 species;
    u8 gender;

    StringCopy(gDisplayedStringBattle, gText_HighlightDarkGrey);
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    StringGetEnd10(nickname);
    ptr = StringAppend(gDisplayedStringBattle, nickname);

    gender = GetMonGender(mon);
    species = GetMonData(mon, MON_DATA_SPECIES);

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && StringCompare(nickname, gSpeciesNames[species]) == 0)
        gender = 100;

    // AddTextPrinterAndCreateWindowOnHealthbox's arguments are the same in all 3 cases.
    // It's possible they may have been different in early development phases.
    switch (gender)
    {
    default:
        StringCopy(ptr, gText_DynColor2);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_MALE:
        StringCopy(ptr, gText_DynColor2Male);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_FEMALE:
        StringCopy(ptr, gText_DynColor1Female);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    }

    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        sub_8075198((void*)(0x6010040 + spriteTileNum), windowTileData, 6);
        ptr = (void*)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            ptr += spriteTileNum + 0x800;
        else
            ptr += spriteTileNum + 0x400;
        sub_8075198(ptr, windowTileData + 0xC0, 1);
    }
    else
    {
        sub_8075198((void*)(0x6010020 + spriteTileNum), windowTileData, 7);
    }

    RemoveWindowOnHealthbox(windowId);
}

static void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus)
{
    u8 bank, healthboxSpriteId_2;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
        return;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return;

    bank = gSprites[healthboxSpriteId].data6;
    if (GetBankSide(bank) == SIDE_PLAYER)
        return;
    if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES)), FLAG_GET_CAUGHT))
        return;

    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;

    if (noStatus)
        CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_70), (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 8) * 32), 32);
    else
        CpuFill32(0, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 8) * 32), 32);
}

static void UpdateStatusIconInHealthbox(u8 healthboxSpriteId)
{
    s32 i;
    u8 bank, healthboxSpriteId_2;
    u32 status, pltAdder;
    const u8 *statusGfxPtr;
    s16 tileNumAdder;
    u8 statusPalId;

    bank = gSprites[healthboxSpriteId].data6;
    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;
    if (GetBankSide(bank) == SIDE_PLAYER)
    {
        status = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_STATUS);
        if (!IsDoubleBattle())
            tileNumAdder = 0x1A;
        else
            tileNumAdder = 0x12;
    }
    else
    {
        status = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_STATUS);
        tileNumAdder = 0x11;
    }

    if (status & STATUS_SLEEP)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(HEALTHBOX_GFX_STATUS_SLP_BANK0, bank));
        statusPalId = PAL_STATUS_SLP;
    }
    else if (status & STATUS_PSN_ANY)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(HEALTHBOX_GFX_STATUS_PSN_BANK0, bank));
        statusPalId = PAL_STATUS_PSN;
    }
    else if (status & STATUS_BURN)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(HEALTHBOX_GFX_STATUS_BRN_BANK0, bank));
        statusPalId = PAL_STATUS_BRN;
    }
    else if (status & STATUS_FREEZE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(HEALTHBOX_GFX_STATUS_FRZ_BANK0, bank));
        statusPalId = PAL_STATUS_FRZ;
    }
    else if (status & STATUS_PARALYSIS)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(HEALTHBOX_GFX_STATUS_PRZ_BANK0, bank));
        statusPalId = PAL_STATUS_PAR;
    }
    else
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_39);

        for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * 32), 32);

        if (!gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + gSprites[healthboxSpriteId_2].oam.tileNum * 32), 64);

        TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
        return;
    }

    pltAdder = gSprites[healthboxSpriteId].oam.paletteNum * 16;
    pltAdder += bank + 12;

    FillPalette(sStatusIconPalettes[statusPalId], pltAdder + 0x100, 2);
    CpuCopy16(gPlttBufferUnfaded + 0x100 + pltAdder, (void*)(OBJ_PLTT + pltAdder * 2), 2);
    CpuCopy32(statusGfxPtr, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder) * 32), 96);
    if (IsDoubleBattle() == TRUE || GetBankSide(bank) == SIDE_OPPONENT)
    {
        if (!gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars)
        {
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_0), (void*)(OBJ_VRAM0 + gSprites[healthboxSpriteId_2].oam.tileNum * 32), 32);
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_65), (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 1) * 32), 32);
        }
    }
    TryAddPokeballIconToHealthbox(healthboxSpriteId, FALSE);
}

static u8 GetStatusIconForBankId(u8 statusElementId, u8 bank)
{
    u8 ret = statusElementId;

    switch (statusElementId)
    {
    case HEALTHBOX_GFX_STATUS_PSN_BANK0:
        if (bank == 0)
            ret = HEALTHBOX_GFX_STATUS_PSN_BANK0;
        else if (bank == 1)
            ret = HEALTHBOX_GFX_STATUS_PSN_BANK1;
        else if (bank == 2)
            ret = HEALTHBOX_GFX_STATUS_PSN_BANK2;
        else
            ret = HEALTHBOX_GFX_STATUS_PSN_BANK3;
        break;
    case HEALTHBOX_GFX_STATUS_PRZ_BANK0:
        if (bank == 0)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BANK0;
        else if (bank == 1)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BANK1;
        else if (bank == 2)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BANK2;
        else
            ret = HEALTHBOX_GFX_STATUS_PRZ_BANK3;
        break;
    case HEALTHBOX_GFX_STATUS_SLP_BANK0:
        if (bank == 0)
            ret = HEALTHBOX_GFX_STATUS_SLP_BANK0;
        else if (bank == 1)
            ret = HEALTHBOX_GFX_STATUS_SLP_BANK1;
        else if (bank == 2)
            ret = HEALTHBOX_GFX_STATUS_SLP_BANK2;
        else
            ret = HEALTHBOX_GFX_STATUS_SLP_BANK3;
        break;
    case HEALTHBOX_GFX_STATUS_FRZ_BANK0:
        if (bank == 0)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BANK0;
        else if (bank == 1)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BANK1;
        else if (bank == 2)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BANK2;
        else
            ret = HEALTHBOX_GFX_STATUS_FRZ_BANK3;
        break;
    case HEALTHBOX_GFX_STATUS_BRN_BANK0:
        if (bank == 0)
            ret = HEALTHBOX_GFX_STATUS_BRN_BANK0;
        else if (bank == 1)
            ret = HEALTHBOX_GFX_STATUS_BRN_BANK1;
        else if (bank == 2)
            ret = HEALTHBOX_GFX_STATUS_BRN_BANK2;
        else
            ret = HEALTHBOX_GFX_STATUS_BRN_BANK3;
        break;
    }
    return ret;
}

static void UpdateSafariBallsTextOnHealthbox(u8 healthboxSpriteId)
{
    u32 windowId, spriteTileNum;
    u8 *windowTileData;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gText_SafariBalls, 0, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
    sub_8075198((void*)(OBJ_VRAM0 + 0x40) + spriteTileNum, windowTileData, 6);
    sub_8075198((void*)(OBJ_VRAM0 + 0x800) + spriteTileNum, windowTileData + 0xC0, 2);
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

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, GetStringRightAlignXOffset(0, text, 0x2F), 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
    sub_80751E4((void*)(OBJ_VRAM0 + 0x2C0) + spriteTileNum, windowTileData, 2);
    sub_80751E4((void*)(OBJ_VRAM0 + 0xA00) + spriteTileNum, windowTileData + 0x40, 4);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId)
{
    s32 maxHp, currHp;
    u8 bank = gSprites[healthboxSpriteId].data6;

    if (elementId == HEALTHBOX_ALL && !IsDoubleBattle())
        GetBankSide(bank); // pointless function call

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        u8 isDoubles;

        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_CURRENT_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_HP), HP_CURRENT);
        if (elementId == HEALTHBOX_MAX_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_MAX_HP), HP_MAX);
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(bank, healthboxSpriteId, maxHp, currHp, 0);
            sub_8074AA0(bank, healthboxSpriteId, HEALTH_BAR, 0);
        }
        isDoubles = IsDoubleBattle();
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
            currLevelExp = gExperienceTables[gBaseStats[species].growthRate][level];
            currExpBarValue = exp - currLevelExp;
            maxExpBarValue = gExperienceTables[gBaseStats[species].growthRate][level + 1] - currLevelExp;
            SetBattleBarStruct(bank, healthboxSpriteId, maxExpBarValue, currExpBarValue, isDoubles);
            sub_8074AA0(bank, healthboxSpriteId, EXP_BAR, 0);
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
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(bank, healthboxSpriteId, maxHp, currHp, 0);
            sub_8074AA0(bank, healthboxSpriteId, HEALTH_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
    }
}

s32 sub_8074AA0(u8 bank, u8 healthboxSpriteId, u8 whichBar, u8 arg3)
{
    s32 var;

    if (whichBar == HEALTH_BAR) // health bar
    {
        var = sub_8074DB8(gBattleSpritesDataPtr->battleBars[bank].maxValue,
                    gBattleSpritesDataPtr->battleBars[bank].currentValue,
                    gBattleSpritesDataPtr->battleBars[bank].field_C,
                    &gBattleSpritesDataPtr->battleBars[bank].field_10,
                    6, 1);
    }
    else // exp bar
    {
        u16 expFraction = GetScaledExpFraction(gBattleSpritesDataPtr->battleBars[bank].currentValue,
                    gBattleSpritesDataPtr->battleBars[bank].field_C,
                    gBattleSpritesDataPtr->battleBars[bank].maxValue, 8);
        if (expFraction == 0)
            expFraction = 1;
        expFraction = abs(gBattleSpritesDataPtr->battleBars[bank].field_C / expFraction);

        var = sub_8074DB8(gBattleSpritesDataPtr->battleBars[bank].maxValue,
                    gBattleSpritesDataPtr->battleBars[bank].currentValue,
                    gBattleSpritesDataPtr->battleBars[bank].field_C,
                    &gBattleSpritesDataPtr->battleBars[bank].field_10,
                    8, expFraction);
    }

    if (whichBar == EXP_BAR || (whichBar == HEALTH_BAR && !gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars))
        sub_8074B9C(bank, whichBar);

    if (var == -1)
        gBattleSpritesDataPtr->battleBars[bank].field_10 = 0;

    return var;
}

static void sub_8074B9C(u8 bank, u8 whichBar)
{
    u8 array[7];
    u8 subRet, level;
    u8 barElementId;
    u8 i;

    switch (whichBar)
    {
    case HEALTH_BAR:
        subRet = sub_8074E8C(gBattleSpritesDataPtr->battleBars[bank].maxValue,
                            gBattleSpritesDataPtr->battleBars[bank].currentValue,
                            gBattleSpritesDataPtr->battleBars[bank].field_C,
                            &gBattleSpritesDataPtr->battleBars[bank].field_10,
                            array, 6);
        barElementId = 3;
        if (subRet <= 0x18)
        {
            barElementId = 0x38;
            if (subRet > 9)
                barElementId = 0x2F;
        }
        for (i = 0; i < 6; i++)
        {
            u8 healthboxSpriteId_2 = gSprites[gBattleSpritesDataPtr->battleBars[bank].healthboxSpriteId].data5;
            if (i < 2)
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 2 + i) * 32), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void*)(OBJ_VRAM0 + 64 + (i + gSprites[healthboxSpriteId_2].oam.tileNum) * 32), 32);
        }
        break;
    case EXP_BAR:
        sub_8074E8C(gBattleSpritesDataPtr->battleBars[bank].maxValue,
                    gBattleSpritesDataPtr->battleBars[bank].currentValue,
                    gBattleSpritesDataPtr->battleBars[bank].field_C,
                    &gBattleSpritesDataPtr->battleBars[bank].field_10,
                    array, 8);
        level = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_LEVEL);
        if (level == MAX_MON_LEVEL)
        {
            for (i = 0; i < 8; i++)
                array[i] = 0;
        }
        for (i = 0; i < 8; i++)
        {
            if (i < 4)
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void*)(OBJ_VRAM0 + (gSprites[gBattleSpritesDataPtr->battleBars[bank].healthboxSpriteId].oam.tileNum + 0x24 + i) * 32), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void*)(OBJ_VRAM0 + 0xB80 + (i + gSprites[gBattleSpritesDataPtr->battleBars[bank].healthboxSpriteId].oam.tileNum) * 32), 32);
        }
        break;
    }
}

static s32 sub_8074DB8(s32 maxValue, s32 currValue, s32 arg2, s32 *arg3, u8 arg4, u16 arg5)
{
    s32 r6;
    s32 ret;
    arg4 <<= 3;

    if (*arg3 == -32768)
    {
        if (maxValue < arg4)
            *arg3 = currValue << 8;
        else
            *arg3 = currValue;
    }

    currValue -= arg2;
    if (currValue < 0)
        currValue = 0;
    else if (currValue > maxValue)
        currValue = maxValue;

    if (maxValue < arg4)
    {
        s32 var = *arg3 >> 8;

        r6 = *arg3;
        if (currValue == var && (r6 & 0xFF) == 0)
            return -1;
    }
    else
    {
        r6 = *arg3;
        if (currValue == r6)
            return -1;
    }

    if (maxValue < arg4)
    {
        s32 var = (maxValue << 8) / arg4;

        if (arg2 < 0)
        {
            *arg3 = r6 + var;
            ret = *arg3 >> 8;
            if (ret >= currValue)
            {
                *arg3 = currValue << 8;
                ret = currValue;
            }
        }
        else
        {
            *arg3 = r6 - var;
            ret = *arg3 >> 8;
            if ((*arg3 & 0xFF) > 0)
                ret++;
            if (ret <= currValue)
            {
                *arg3 = currValue << 8;
                ret = currValue;
            }
        }
    }
    else
    {
        if (arg2 < 0)
        {
            *arg3 += arg5;
            if (*arg3 > currValue)
                *arg3 = currValue;
            ret = *arg3;
        }
        else
        {
            *arg3 -= arg5;
            if (*arg3 < currValue)
                *arg3 = currValue;
            ret = *arg3;
        }
    }

    return ret;
}

static u8 sub_8074E8C(s32 maxValue, s32 currValue, s32 arg2, s32 *arg3, u8 *arg4, u8 arg5)
{
    s32 r5 = currValue - arg2;
    u8 ret;
    u8 i;
    u8 r2;

    if (r5 < 0)
        r5 = 0;
    else if (r5 > maxValue)
        r5 = maxValue;

    ret = arg5 << 3;

    for (i = 0; i < arg5; i++)
        arg4[i] = 0;

    if (maxValue < ret)
        r2 = (*arg3 * ret / maxValue) >> 8;
    else
        r2 = *arg3 * ret / maxValue;

    ret = r2;

    if (ret == 0 && r5 > 0)
    {
        arg4[0] = 1;
        ret = 1;
    }
    else
    {
        for (i = 0; i < arg5; i++)
        {
            if (r2 >= 8)
            {
                arg4[i] = 8;
            }
            else
            {
                arg4[i] = r2;
                break;
            }
            r2 -= 8;
        }
    }

    return ret;
}

static s16 sub_8074F28(struct TestingBar *barInfo, s32 *arg1, u16 *arg2, s32 arg3)
{
    s16 ret, var;

    ret = sub_8074DB8(barInfo->maxValue,
                    barInfo->currValue,
                    barInfo->field_8,
                    arg1, 6, 1);
    sub_8074F88(barInfo, arg1, arg2);

    if (barInfo->maxValue < 0x30)
        var = *arg1 >> 8;
    else
        var = *arg1;

    DummiedOutFunction(barInfo->maxValue, var, arg3);

    return ret;
}

static void sub_8074F88(struct TestingBar *barInfo, s32 *arg1, u16 *arg2)
{
    u8 sp8[6];
    u16 sp10[6];
    u8 i;

    sub_8074E8C(barInfo->maxValue, barInfo->currValue,
                barInfo->field_8, arg1, sp8, 6);

    for (i = 0; i < 6; i++)
        sp10[i] = (barInfo->unkC_0 << 12) | (barInfo->unk10 + sp8[i]);

    CpuCopy16(sp10, arg2, sizeof(sp10));
}

static u8 GetScaledExpFraction(s32 currValue, s32 arg1, s32 maxValue, u8 scale)
{
    s32 r5, result;
    s8 r4, r0;

    scale *= 8;
    r5 = currValue - arg1;

    if (r5 < 0)
        r5 = 0;
    else if (r5 > maxValue)
        r5 = maxValue;

    r4 = currValue * scale / maxValue;
    r0 = r5 * scale / maxValue;
    result = r4 - r0;

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
    s32 result;

    if (hp == maxhp)
    {
        result = 4;
    }
    else
    {
        u8 fraction = GetScaledHPFraction(hp, maxhp, 48);
        if (fraction > 24)
            result = 3;
        else if (fraction > 9)
            result = 2;
        else if (fraction > 0)
            result = 1;
        else
            result = 0;
    }

    return result;
}

static u8* AddTextPrinterAndCreateWindowOnHealthbox(const u8 *str, u32 x, u32 y, u32 arg3, u32 *windowId)
{
    u16 winId;
    struct TextColor color;
    struct WindowTemplate winTemplate = sHealthboxWindowTemplate;

    winId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(winId, (arg3 << 4) | (arg3));

    color.fgColor = arg3;
    color.bgColor = 1;
    color.shadowColor = 3;

    AddTextPrinterParametrized2(winId, 0, x, y, 0, 0, &color, -1, str);

    *windowId = winId;
    return (u8*)(GetWindowAttribute(winId, WINDOW_TILE_DATA));
}

static void RemoveWindowOnHealthbox(u32 windowId)
{
    RemoveWindow(windowId);
}

static void sub_807513C(void *dest, u32 arg1, u32 arg2)
{
    CpuFill32(0x11111111 * arg1, dest, arg2 * 32);
}

static void sub_8075170(void *dest, u8 *windowTileData, u32 arg2)
{
    CpuCopy32(windowTileData + 256, dest, arg2 * 32);
}

static void sub_8075198(void *dest, u8 *windowTileData, s32 arg2)
{
    CpuCopy32(windowTileData + 256, dest + 256, arg2 * 32);

    if (arg2 > 0)
    {
        do
        {
            CpuCopy32(windowTileData + 20, dest + 20, 12);
            dest += 32, windowTileData+= 32;
            arg2--;
        } while (arg2 != 0);
    }
}

static void sub_80751E4(void *dest, u8 *windowTileData, u32 arg2)
{
    CpuCopy32(windowTileData, dest, arg2 * 32);
    CpuCopy32(windowTileData + 256, dest + 256, arg2 * 32);
}

#include "global.h"
#include "main.h"
#include "pokeblock.h"
#include "malloc.h"
#include "decompress.h"
#include "graphics.h"
#include "palette.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "scanline_effect.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "sound.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "menu.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "pokemon_summary_screen.h"
#include "item_menu.h"

struct UsePokeblockSubStruct
{
    /*0x00*/ void (*field_0)(void);
    /*0x04*/ void (*callback)(void);
    /*0x08*/ struct Pokeblock *pokeblock;
    /*0x0C*/ struct Pokemon *mon;
    /*0x10*/ u8 stringBuffer[0x40];
    /*0x50*/ u8 field_50;
    /*0x51*/ u8 field_51;
    /*0x52*/ u8 field_52;
    /*0x53*/ u8 field_53;
    /*0x54*/ u8 field_54;
    /*0x55*/ u8 field_55;
    /*0x56*/ u8 field_56;
    /*0x57*/ u8 field_57[5];
    /*0x5C*/ u8 field_5c[5];
    /*0x61*/ u8 field_61[5];
    /*0x66*/ s16 field_66[5];
    /*0x70*/ u8 field_70;
    /*0x71*/ u8 field_71;
    /*0x74*/ u8 (*unk74)(void);
    /*0x78*/ u8 unk78;
    /*0x79*/ u8 filler79[0x1];
    /*0x7A*/ u8 field_7A[0x22];
};

struct Unk7FB8
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
};

struct UsePokeblockStruct
{
    /*0x0000*/ u8 filler0[4];
    /*0x0000*/ u16 field_4[6][0x40];
    /*0x0304*/ u8 field_304[3][0x2000];
    /*0x6304*/ u8 filler_6304[0x1000];
    /*0x7304*/ u8 tilemapBuffer[BG_SCREEN_SIZE + 2];
    /*0x7B06*/ u8 field_7B06[7];
    /*0x7B0E*/ s16 field_7B0E;
    /*0x7B10*/ u8 field_7B10;
    /*0x7B12*/ u16 field_7B12;
    /*0x7B12*/ u16 field_7B14;
    /*0x7B12*/ u8 *field_7B18;
    /*0x7B1C*/ struct Sprite *field_7B1C[10];
    /*0x7B44*/ struct Sprite *field_7B44[2];
    /*0x7B4C*/ u8 field_7B4C;
    /*0x7B4D*/ u8 field_7B4D[3][24];
    /*0x7B95*/ u8 field_7B95[3][64];
    /*0x7C58*/ struct UnknownStruct_81D1ED4 field_7C58;
    /*0x7FB0*/ u8 unk7FB0[3];
    /*0x7FB3*/ s8 field_7FB3;
    /*0x7FB4*/ s8 field_7FB4;
    /*0x7FB5*/ s8 field_7FB5;
    /*0x7FB6*/ s8 field_7FB6;
    /*0x7FB8*/ struct Unk7FB8 field_7FB8[6];
    /*0x7FD0*/ struct UsePokeblockSubStruct info;
};

#define TAG_TILE_CONDITION_UP_DOWN    0
#define TAG_PAL_CONDITION_UP_DOWN     0
#define TAG_PAL_POKEBLOCK_CONDITION   1

extern void sub_81D21DC(u8);

// this file's functions
void sub_816636C(void (*func)(void));
void sub_8166380(void);
void sub_816631C(void);
void sub_81662C0(void);
void sub_8166564(void);
void sub_8166304(void);
void sub_81668F8(void);
void sub_8167420(void);
void sub_8167760(void);
u8 sub_81672E4(u8 arg0);
static bool8 sub_8168328(void);
bool8 sub_8167930(void);
void sub_8167608(u8 arg0);
void sub_8167BA0(u16 arg0, u8 copyToVramMode);
void sub_8166634(void);
static void sub_8167CA0(bool8);
void sub_8166BEC(void);
void sub_8166D44(void);
s8 sub_8166DE4(void);
bool8 IsSheenMaxed(void);
void sub_8166F50(void);
void sub_816681C(void);
void sub_8166F94(void);
u8 sub_81672A4(u8 a0);
void sub_8166A34(void);
void sub_8167104(void);
void sub_8167338(void);
void sub_81681F4(u8);
void sub_8166E24(void);
bool8 sub_8166EDC(void);
void Pokeblock_BufferEnhancedStatText(u8 *dest, u8 statId, s16 a2);
void Pokeblock_MenuWindowTextPrint(const u8 *message);
void sub_8167184(struct Pokeblock *, struct Pokemon *);
void sub_81673DC(struct Sprite *sprite);
void sub_81674BC(void);
void sub_816753C(s16, u8);
static u8 sub_8167EA4(void);
static u8 sub_8167FA4(void);
static u8 sub_8168048(void);
void sub_8168180(struct Sprite *sprite);
void sub_81681B4(struct Sprite *sprite);
void sub_8168168(struct Sprite *sprite);
void sub_8168374(struct Sprite *sprite);

extern const u16 gUnknown_086231E8[];
extern const u16 gUnknown_08623208[];
extern const struct SpritePalette gSpritePalette_085DFDB8;
extern const struct SpriteTemplate gSpriteTemplate_085DFDA0;

// ram variables
EWRAM_DATA struct UsePokeblockSubStruct *gUnknown_0203BC90 = NULL;
EWRAM_DATA void (*gUnknown_0203BC94)(void) = NULL;
EWRAM_DATA struct Pokeblock *gUnknown_0203BC98 = NULL;
EWRAM_DATA u8 gPokeblockMonId = 0;
EWRAM_DATA s16 gPokeblockGain = 0;
EWRAM_DATA u8 *gUnknown_0203BCA0 = NULL;
EWRAM_DATA u8 *gUnknown_0203BCA4 = NULL;
EWRAM_DATA u8 *gUnknown_0203BCA8 = NULL;
EWRAM_DATA struct UsePokeblockStruct *gUnknown_0203BCAC = NULL;

// const rom data
// todo: make it static once the file is decompiled

const u32 gUnknown_085DFA60[] = INCBIN_U32("graphics/interface/85DFA60.bin");
const u32 gUnknown_085DFA80[] = INCBIN_U32("graphics/interface/85DFA80.4bpp");
const u32 gUnknown_085DFB60[] = INCBIN_U32("graphics/interface/85DFB60.bin");
const u32 gUnknown_085DFC0C[] = INCBIN_U32("graphics/interface/85DFC0C.bin");

const u32 gUnknown_085DFCB0[] =
{
    MON_DATA_COOL,
    MON_DATA_TOUGH,
    MON_DATA_SMART,
    MON_DATA_CUTE,
    MON_DATA_BEAUTY
};

const u8 gUnknown_085DFCC4[] =
{
    0, // Spicy/Cool
    4, // Dry/Beauty
    3, // Sweet/Cute
    2, // Bitter/Smart
    1  // Sour/Tough 
};

static const u8 sNatureTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_WHITE
};

const struct BgTemplate gUnknown_085DFCCC[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x100
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x17,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

const struct WindowTemplate gUnknown_085DFCDC[] = 
{
    {
        .bg = 0,
        .tilemapLeft = 0xD,
        .tilemapTop = 1,
        .width = 0xD,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0xE,
        .width = 0xB,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x35
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0x11,
        .width = 0x1C,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x4B
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate sUsePokeblockYesNoWinTemplate = 
{
    .bg = 0,
    .tilemapLeft = 0x18,
    .tilemapTop = 0xB,
    .width = 5,
    .height = 4,
    .paletteNum = 0xF,
    .baseBlock = 0x83
};

const u8 *const sContestStatNames[] =
{
    gText_Coolness,
    gText_Toughness,
    gText_Smartness,
    gText_Cuteness,
    gText_Beauty3
};

const struct SpriteSheet gSpriteSheet_ConditionUpDown = 
{
    gUsePokeblockUpDown_Gfx, 0x200, TAG_TILE_CONDITION_UP_DOWN
};

const struct SpritePalette gSpritePalette_ConditionUpDown =
{
    gUsePokeblockUpDown_Pal, TAG_PAL_CONDITION_UP_DOWN
};

const s16 gUnknown_085DFD28[][2] =
{
    {0x9C, 0x24},
    {0x75, 0x3B},
    {0x75, 0x76},
    {0xC5, 0x76},
    {0xC5, 0x3B}
};

const struct OamData gOamData_085DFD3C = 
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

const union AnimCmd gSpriteAnim_085DFD44[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd gSpriteAnim_085DFD4C[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_085DFD54[] =
{
    gSpriteAnim_085DFD44,
    gSpriteAnim_085DFD4C
};

const struct SpriteTemplate gSpriteTemplate_085DFD5C =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gOamData_085DFD3C,
    .anims = gSpriteAnimTable_085DFD54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct OamData gOamData_085DFD74 = 
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

const union AnimCmd gSpriteAnim_085DFD7C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd gSpriteAnim_085DFD84[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

const union AnimCmd gSpriteAnim_085DFD8C[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_085DFD94[] =
{
    gSpriteAnim_085DFD7C,
    gSpriteAnim_085DFD84,
    gSpriteAnim_085DFD8C
};

const struct SpriteTemplate gSpriteTemplate_085DFDA0 =
{
    .tileTag = 1,
    .paletteTag = 1,
    .oam = &gOamData_085DFD74,
    .anims = gSpriteAnimTable_085DFD94,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8168374,
};

const struct SpritePalette gSpritePalette_085DFDB8 =
{
    gUsePokeblockCondition_Pal, TAG_PAL_POKEBLOCK_CONDITION
};

// code
void ChooseMonToGivePokeblock(struct Pokeblock *pokeblock, void (*callback)(void))
{
    gUnknown_0203BCAC = AllocZeroed(sizeof(*gUnknown_0203BCAC));
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = pokeblock;
    gUnknown_0203BC90->callback = callback;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_816631C);
}

void CB2_ReturnAndChooseMonToGivePokeblock(void)
{
    gUnknown_0203BCAC = AllocZeroed(sizeof(*gUnknown_0203BCAC));
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = gUnknown_0203BC98;
    gUnknown_0203BC90->callback = gUnknown_0203BC94;
    gPokeblockMonId = sub_81672E4(gPokeblockMonId);
    gUnknown_0203BC90->field_56 = gPokeblockMonId < 4 ? 0 : 1;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_81662C0);
}

void sub_81662C0(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gUnknown_0203BC90->field_0 == sub_8166564)
    {
        gUnknown_0203BC90->field_50 = 0;
        SetMainCallback2(sub_8166304);
    }
}

void sub_8166304(void)
{
    sub_81668F8();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_816631C(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_8166340(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(&gUnknown_0203BCAC->field_7C58);
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_816636C(void (*func)(void))
{
    gUnknown_0203BC90->field_0 = func;
    gUnknown_0203BC90->field_50 = 0;
}

void sub_8166380(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        gUnknown_0203BCAC->field_7B10 = 0xFF;
        sub_81D1ED4(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gUnknown_0203BC90->field_50++;
        break;
    case 2:
        SetVBlankCallback(NULL);
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
        gUnknown_0203BC90->field_50++;
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_085DFCCC, ARRAY_COUNT(gUnknown_085DFCCC));
        InitWindows(gUnknown_085DFCDC);
        DeactivateAllTextPrinters();
        LoadUserWindowBorderGfx(0, 0x97, 0xE0);
        gUnknown_0203BC90->field_50++;
        break;
    case 4:
        gUnknown_0203BC90->field_50++;
        break;
    case 5:
        if (!sub_8168328())
            gUnknown_0203BC90->field_50++;
        break;
    case 6:
        gKeyRepeatStartDelay = 20;
        sub_8167420();
        gUnknown_0203BC90->field_50++;
        break;
    case 7:
        if (!sub_8167930())
            gUnknown_0203BC90->field_50++;
        break;
    case 8:
        sub_8167608(0);
        sub_8167760();
        gUnknown_0203BC90->field_50++;
        break;
    case 9:
        if (!sub_81D312C(&gUnknown_0203BCAC->field_7B0E))
            gUnknown_0203BC90->field_50++;
        break;
    case 10:
        gUnknown_0203BC90->field_50++;
        break;
    case 11:
        sub_81D2754(gUnknown_0203BCAC->field_7C58.unk0[0], gUnknown_0203BCAC->field_7C58.unk14[0]);
        sub_81D20AC(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 12:
        if (!sub_81D20BC(&gUnknown_0203BCAC->field_7C58))
        {
            sub_81D1F84(&gUnknown_0203BCAC->field_7C58, gUnknown_0203BCAC->field_7C58.unk14[0], gUnknown_0203BCAC->field_7C58.unk14[0]);
            gUnknown_0203BC90->field_50++;
        }
        break;
    case 13:
        sub_81D2230(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 14:
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        sub_8167BA0(0, 1);
        gUnknown_0203BC90->field_50++;
        break;
    case 15:
        sub_816636C(sub_8166564);
        break;
    }
}

void sub_8166564(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(sub_8166340);
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            sub_81D3464(gUnknown_0203BCAC->field_7B1C);
            if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
            {
                u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
                sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
            }

            sub_816636C(sub_8166634);
        }
        break;
    }
}

void sub_8166634(void)
{
    u8 var;

    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        if (gMain.heldKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(TRUE);
            sub_81D3520(gUnknown_0203BCAC->field_7B1C);
            gUnknown_0203BC90->field_50 = 1;
        }
        else if (gMain.heldKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(FALSE);
            sub_81D3520(gUnknown_0203BCAC->field_7B1C);
            gUnknown_0203BC90->field_50 = 1;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_0203BC90->field_50 = 3;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gUnknown_0203BCAC->info.field_71 == gUnknown_0203BCAC->info.field_70 - 1)
                gUnknown_0203BC90->field_50 = 3;
            else
                gUnknown_0203BC90->field_50 = 5;
        }
        break;
    case 1:
        var = gUnknown_0203BCAC->info.unk74();
        if (!var)
            gUnknown_0203BC90->field_50 = var;
        break;
    case 2:
        break;
    case 3:
        sub_816636C(sub_8166BEC);
        break;
    case 4:
        break;
    case 5:
        sub_8166D44();
        gUnknown_0203BC90->field_50++;
        break;
    case 6:
        switch (sub_8166DE4())
        {
        case 1:
        case -1:
            gUnknown_0203BC90->field_50 = 0;
            break;
        case 0:
            if (IsSheenMaxed())
            {
                sub_8166F50();
                gUnknown_0203BC90->field_50 = 7;
            }
            else
            {
                sub_816636C(sub_816681C);
            }
            break;
        }
        break;
    case 7:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            sub_8166F94();
            gUnknown_0203BC90->field_50 = 0;
        }
        break;
    }
}

void sub_816681C(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        gPokeblockMonId = sub_81672A4(gUnknown_0203BCAC->info.field_71);
        gUnknown_0203BC94 = gUnknown_0203BC90->callback;
        gUnknown_0203BC98 = gUnknown_0203BC90->pokeblock;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetVBlankCallback(NULL);
            FREE_AND_SET_NULL(gUnknown_0203BCA0);
            FREE_AND_SET_NULL(gUnknown_0203BCA4);
            FREE_AND_SET_NULL(gUnknown_0203BCA8);
            FREE_AND_SET_NULL(gUnknown_0203BCAC);
            FreeAllWindowBuffers();
            gMain.savedCallback = CB2_ReturnAndChooseMonToGivePokeblock;
            CB2_PreparePokeblockFeedScene();
        }
        break;
    }
}

void sub_81668F8(void)
{
    u16 var;

    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        if (gUnknown_0203BCAC->info.field_71 != gPokeblockMonId)
        {
            sub_8167CA0(gUnknown_0203BC90->field_56);
            gUnknown_0203BC90->field_50++;
        }
        else
        {
            gUnknown_0203BC90->field_50 = 3;
        }
        break;
    case 1:
        var = gUnknown_0203BCAC->info.unk74();
        if (!var)
            gUnknown_0203BC90->field_50 = var;
        break;
    case 2:
        break;
    case 3:
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 4:
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        gUnknown_0203BC90->field_50++;
        break;
    case 5:
        SetVBlankCallback(sub_8166340);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            sub_81D3464(gUnknown_0203BCAC->field_7B1C);
            sub_816636C(sub_8166A34);
            SetMainCallback2(sub_816631C);
        }
        break;
    }
}

void sub_8166A34(void)
{
    u8 var;

    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        gUnknown_0203BC90->mon = gPlayerParty;
        gUnknown_0203BC90->mon += gUnknown_0203BCAC->field_7FB8[gUnknown_0203BCAC->info.field_71].unk1;
        sub_81D3520(gUnknown_0203BCAC->field_7B1C);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            gUnknown_0203BC90->field_50++;
        break;
    case 2:
        sub_8167104();
        sub_81D2754(gUnknown_0203BC90->field_5c, gUnknown_0203BCAC->field_7C58.unk14[3]);
        sub_81D1F84(&gUnknown_0203BCAC->field_7C58, gUnknown_0203BCAC->field_7C58.unk14[gUnknown_0203BCAC->field_7FB3], gUnknown_0203BCAC->field_7C58.unk14[3]);
        sub_8167338();
        gUnknown_0203BC90->field_50++;
        break;
    case 3:
        var = sub_81D2074(&gUnknown_0203BCAC->field_7C58);
        if (!var)
        {
            sub_81681F4(sub_81672A4(gUnknown_0203BCAC->info.field_71));
            if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
            {
                u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
                sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
            }

            gUnknown_0203BC90->field_52 = 0;
            gUnknown_0203BC90->field_50++;
        }
        break;
    case 4:
        if (++gUnknown_0203BC90->field_52 > 16)
        {
            sub_8166E24();
            gUnknown_0203BC90->field_50++;
        }
        break;
    case 5:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON) && !sub_8166EDC())
        {
            TryClearPokeblock((u8)gSpecialVar_ItemId);
            sub_816636C(sub_8166BEC);
        }
        break;
    }
}

void sub_8166BEC(void)
{
    u8 i, var;

    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
            gUnknown_0203BC90->field_50 = 2;
        break;
    case 2:
        gScanlineEffect.state = 3;
        ScanlineEffect_InitHBlankDmaTransfer();
        gUnknown_0203BC90->field_50++;
        break;
    case 3:
        SetMainCallback2(gUnknown_0203BC90->callback);
        sub_81D354C(gUnknown_0203BCAC->field_7B1C);
        for (i = 0; i < 7; i++)
            DestroySprite(&gSprites[gUnknown_0203BCAC->field_7B06[i]]);

        FreeSpriteTilesByTag(0);
        FreeSpriteTilesByTag(1);
        FreeSpritePaletteByTag(0);
        FreeSpritePaletteByTag(1);

        for (i = 0; i < 2; i++)
            DestroySprite(gUnknown_0203BCAC->field_7B44[i]);

        if (gUnknown_0203BCAC->field_7B10 != 0xFF)
            DestroySprite(&gSprites[gUnknown_0203BCAC->field_7B10]);

        SetVBlankCallback(NULL);
        FREE_AND_SET_NULL(gUnknown_0203BCA0);
        FREE_AND_SET_NULL(gUnknown_0203BCA4);
        FREE_AND_SET_NULL(gUnknown_0203BCA8);
        FREE_AND_SET_NULL(gUnknown_0203BCAC);
        FreeAllWindowBuffers();
        break;
    }
}

void sub_8166D44(void)
{
    u8 stringBuffer[0x40];

    GetMonData(&gPlayerParty[sub_81672A4(gUnknown_0203BCAC->info.field_71)], MON_DATA_NICKNAME, stringBuffer);
    StringGetEnd10(stringBuffer);
    StringAppend(stringBuffer, gText_GetsAPokeBlockQuestion);
    StringCopy(gStringVar4, stringBuffer);
    FillWindowPixelBuffer(2, 17);
    DrawTextBorderOuter(2, 151, 14);
    AddTextPrinterParameterized(2, 1, gStringVar4, 0, 1, 0, NULL);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
    CreateYesNoMenu(&sUsePokeblockYesNoWinTemplate, 151, 14, 0);
}

s8 sub_8166DE4(void)
{
    s8 menuItem = Menu_ProcessInputNoWrapClearOnChoose();

    switch (menuItem)
    {
    case 0:
        break;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(2);
        ClearWindowTilemap(2);
        break;
    }

    return menuItem;
}

void sub_8166E24(void)
{
    DrawTextBorderOuter(2, 151, 14);
    FillWindowPixelBuffer(2, 17);

    for (gUnknown_0203BC90->field_53 = 0; gUnknown_0203BC90->field_53 < 5; gUnknown_0203BC90->field_53++)
    {
        if (gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53] != 0)
            break;
    }

    if (gUnknown_0203BC90->field_53 < 5)
        Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53]);
    else
        Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, 0);

    Pokeblock_MenuWindowTextPrint(gStringVar4);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

bool8 sub_8166EDC(void)
{
    FillWindowPixelBuffer(2, 17);

    while (1)
    {
        gUnknown_0203BC90->field_53++;
        if (gUnknown_0203BC90->field_53 < 5)
        {
            if (gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53] != 0)
                break;
        }
        else
        {
            gUnknown_0203BC90->field_53 = 5;
            return FALSE;
        }
    }

    Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53]);
    Pokeblock_MenuWindowTextPrint(gStringVar4);
    CopyWindowToVram(2, 2);

    return TRUE;
}

void sub_8166F50(void)
{
    FillWindowPixelBuffer(2, 17);
    DrawTextBorderOuter(2, 151, 14);
    AddTextPrinterParameterized(2, 1, gText_WontEatAnymore, 0, 1, 0, NULL);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

void sub_8166F94(void)
{
    rbox_fill_rectangle(2);
    ClearWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

void Pokeblock_MenuWindowTextPrint(const u8 *message)
{
    AddTextPrinterParameterized(2, 1, gStringVar4, 0, 1, 0, NULL);
}

void Pokeblock_BufferEnhancedStatText(u8 *dest, u8 statId, s16 a2)
{
    switch (a2)
    {
    case 1 ... 32767:
        a2 = 0;
        // fallthrough
    case -32768 ... -1:
        if (a2)
            dest[(u16)a2] += 0; // something you can't imagine
        StringCopy(dest, sContestStatNames[statId]);
        StringAppend(dest, gText_WasEnhanced);
        break;
    case 0:
        StringCopy(dest, gText_NothingChanged);
        break;
    }
}

void Pokeblock_GetMonContestStats(struct Pokemon *mon, u8 *data)
{
    u16 i;

    for (i = 0; i < 5; i++)
        data[i] = GetMonData(mon, gUnknown_085DFCB0[i]);
}

void sub_8167054(struct Pokeblock *pokeblock, struct Pokemon *mon)
{
    u16 i;
    s16 cstat;
    u8 data;

    if (GetMonData(mon, MON_DATA_SHEEN) != 255)
    {
        sub_8167184(pokeblock, mon);
        for (i = 0; i < 5; i++)
        {
            data = GetMonData(mon, gUnknown_085DFCB0[i]);
            cstat = data +  gUnknown_0203BC90->field_66[i];
            if (cstat < 0)
                cstat = 0;
            if (cstat > 255)
                cstat = 255;
            data = cstat;
            SetMonData(mon, gUnknown_085DFCB0[i], &data);
        }

        cstat = (u8)(GetMonData(mon, MON_DATA_SHEEN)) + pokeblock->feel;
        if (cstat > 255)
            cstat = 255;

        data = cstat;
        SetMonData(mon, MON_DATA_SHEEN, &data);
    }
}

void sub_8167104(void)
{
    u16 i;
    struct Pokemon *mon = gPlayerParty;
    mon += gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->info.field_71 * 4 + 9];

    Pokeblock_GetMonContestStats(mon, gUnknown_0203BC90->field_57);
    sub_8167054(gUnknown_0203BC90->pokeblock, mon);
    Pokeblock_GetMonContestStats(mon, gUnknown_0203BC90->field_5c);
    for (i = 0; i < 5; i++)
        gUnknown_0203BC90->field_61[i] = gUnknown_0203BC90->field_5c[i] - gUnknown_0203BC90->field_57[i];
}

void sub_8167184(struct Pokeblock *pokeblock, struct Pokemon *mon)
{
    s8 i, direction, taste;

    gUnknown_0203BC90->field_66[0] = pokeblock->spicy;
    gUnknown_0203BC90->field_66[1] = pokeblock->sour;
    gUnknown_0203BC90->field_66[2] = pokeblock->bitter;
    gUnknown_0203BC90->field_66[3] = pokeblock->sweet;
    gUnknown_0203BC90->field_66[4] = pokeblock->dry;

    if (gPokeblockGain > 0)
        direction = 1;
    else if (gPokeblockGain < 0)
        direction = -1;
    else
        return;

    for (i = 0; i < 5; i++)
    {
        s16 amount = gUnknown_0203BC90->field_66[i];
        s8 boost = amount / 10;

        if (amount % 10 >= 5) // round to the nearest
            boost++;

        taste = GetMonFlavorRelation(mon, gUnknown_085DFCC4[i]);
        if (taste == direction)
            gUnknown_0203BC90->field_66[i] += boost * taste;
    }
}

bool8 IsSheenMaxed(void)
{
    if (GetBoxOrPartyMonData(gUnknown_0203BCAC->field_7FB8[gUnknown_0203BCAC->info.field_71].unk0,
                             gUnknown_0203BCAC->field_7FB8[gUnknown_0203BCAC->info.field_71].unk1,
                             MON_DATA_SHEEN,
                             NULL) == 255)
        return TRUE;
    else
        return FALSE;
}

u8 sub_81672A4(u8 a0)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            if (a0 == 0)
                return i;
            a0--;
        }
    }

    return 0;
}

u8 sub_81672E4(u8 partyCount)
{
    u8 i, numEggs;

    for (i = 0, numEggs = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            numEggs++;
    }

    return partyCount - numEggs;
}

u8 sub_8167324(u8 a0)
{
    return sub_81672A4(a0);
}

void sub_8167338(void)
{
    u16 i, spriteId;

    LoadSpriteSheet(&gSpriteSheet_ConditionUpDown);
    LoadSpritePalette(&gSpritePalette_ConditionUpDown);
    gUnknown_0203BC90->field_54 = 0;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_0203BC90->field_61[i] != 0)
        {
            spriteId = CreateSprite(&gSpriteTemplate_085DFD5C, gUnknown_085DFD28[i][0], gUnknown_085DFD28[i][1], 0);
            if (spriteId != MAX_SPRITES)
            {
                if (gUnknown_0203BC90->field_61[i] != 0)
                    gSprites[spriteId].callback = sub_81673DC;

                gUnknown_0203BC90->field_54++;
            }
        }
    }
}

void sub_81673DC(struct Sprite *sprite)
{
    if (sprite->data[0] < 6)
        sprite->pos2.y -= 2;
    else if (sprite->data[0] < 12)
        sprite->pos2.y += 2;

    if (++sprite->data[0] > 60)
    {
        DestroySprite(sprite);
        gUnknown_0203BC90->field_54--;
    }
}

void sub_8167420(void)
{
    u16 i;
    u16 numMons;

    for (i = 0, numMons = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            gUnknown_0203BCAC->field_7FB8[numMons].unk0 = 14;
            gUnknown_0203BCAC->field_7FB8[numMons].unk1 = i;
            gUnknown_0203BCAC->field_7FB8[numMons].unk2 = 0;
            numMons++;
        }
    }

    gUnknown_0203BCAC->info.field_71 = 0;
    gUnknown_0203BCAC->info.field_70 = numMons + 1;
    sub_81674BC();
}

void sub_81674BC(void)
{
    s16 var, var2;

    sub_816753C(gUnknown_0203BCAC->info.field_71, 0);
    gUnknown_0203BCAC->field_7FB3 = 0;
    gUnknown_0203BCAC->field_7FB4 = 1;
    gUnknown_0203BCAC->field_7FB5 = 2;

    var = gUnknown_0203BCAC->info.field_71 + 1;
    if (var >= gUnknown_0203BCAC->info.field_70)
        var = 0;

    var2 = gUnknown_0203BCAC->info.field_71 - 1;
    if (var2 < 0)
        var2 = gUnknown_0203BCAC->info.field_70 - 1;

    sub_816753C(var, 1);
    sub_816753C(var2, 2);
}

void sub_816753C(s16 id1, u8 id2)
{
    u8 boxId = gUnknown_0203BCAC->field_7FB8[id1].unk0;
    u8 monId = gUnknown_0203BCAC->field_7FB8[id1].unk1;
    u8 r6 = gUnknown_0203BCAC->info.field_70;
    bool8 r8 = FALSE;

    sub_81D2ED4(gUnknown_0203BCAC->field_7B4D[id2], gUnknown_0203BCAC->field_7B95[id2], boxId, monId, id1, r6, r8);
    sub_81D2F78(&gUnknown_0203BCAC->field_7C58, gUnknown_0203BCAC->unk7FB0, boxId, monId, id1, id2, r6, r8);
    sub_81D3094(gUnknown_0203BCAC->field_304[id2], gUnknown_0203BCAC->field_4[id2], boxId, monId, id1, r6, r8);
}

void sub_8167608(u8 arg0)
{
    u8 spriteId;
    struct SpriteTemplate spriteTemplate;
    struct SpriteSheet spriteSheet;
    struct SpritePalette spritePal;

    if (gUnknown_0203BCAC->field_7B10 == 0xFF)
    {
        sub_81D31D0(&spriteSheet, &spriteTemplate, &spritePal);
        spriteSheet.data = gUnknown_0203BCAC->field_304[arg0];
        spritePal.data = gUnknown_0203BCAC->field_4[arg0];
        gUnknown_0203BCAC->field_7B12 = LoadSpritePalette(&spritePal);
        gUnknown_0203BCAC->field_7B14 = LoadSpriteSheet(&spriteSheet);
        spriteId = CreateSprite(&spriteTemplate, 38, 104, 0);
        gUnknown_0203BCAC->field_7B10 = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(100);
            FreeSpritePaletteByTag(100);
            gUnknown_0203BCAC->field_7B10 = 0xFF;
        }
        else
        {
            gUnknown_0203BCAC->field_7B10 = spriteId;
            gSprites[gUnknown_0203BCAC->field_7B10].callback = sub_8168168;
            gSprites[gUnknown_0203BCAC->field_7B10].pos2.y -= 34;
            gUnknown_0203BCAC->field_7B18 = (void*)(OBJ_VRAM0 + (gUnknown_0203BCAC->field_7B14 * 32));
            gUnknown_0203BCAC->field_7B12 = (gUnknown_0203BCAC->field_7B12 * 16) + 0x100;
        }
    }
    else
    {
        do {} while(0); // Surprised to see something like this? It's a very neat trick for generating the same assembly. It has no practical purpose, feel free to remove it.
        DmaCopy16Defvars(3, gUnknown_0203BCAC->field_304[arg0], gUnknown_0203BCAC->field_7B18, 0x800);
        LoadPalette(gUnknown_0203BCAC->field_4[arg0], gUnknown_0203BCAC->field_7B12, 32);
    }
}

void sub_8167760(void)
{
    u16 i, spriteId;
    struct SpriteSheet spriteSheets[4];
    struct SpriteTemplate spriteTemplate;
    struct SpritePalette spritePals[3];
    struct SpriteSheet spriteSheet2;
    struct SpritePalette spritePal2;

    sub_81D321C(spriteSheets, &spriteTemplate, spritePals);
    LoadSpriteSheets(spriteSheets);
    LoadSpritePalettes(spritePals);

    for (i = 0; i < gUnknown_0203BCAC->info.field_70 - 1; i++)
    {
        spriteId = CreateSprite(&spriteTemplate, 226, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            gUnknown_0203BCAC->field_7B06[i] = spriteId;
            gSprites[spriteId].data[0] = i;
            gSprites[spriteId].callback = sub_8168180;
        }
        else
        {
            gUnknown_0203BCAC->field_7B06[i] = -1;
        }
    }

    spriteTemplate.tileTag = 103;
    for (; i < 6; i++)
    {
        spriteId = CreateSprite(&spriteTemplate, 230, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            gUnknown_0203BCAC->field_7B06[i] = spriteId;
            gSprites[spriteId].oam.size = 0;
        }
        else
        {
            gUnknown_0203BCAC->field_7B06[i] = -1;
        }
    }

    spriteTemplate.tileTag = 102;
    spriteTemplate.callback = sub_81681B4;
    spriteId = CreateSprite(&spriteTemplate, 222, (i * 20) + 8, 0);
    if (spriteId != MAX_SPRITES)
    {
        gUnknown_0203BCAC->field_7B06[i] = spriteId;
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
        gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
    }
    else
    {
        gUnknown_0203BCAC->field_7B06[i] = -1;
    }

    sub_81D32B0(&spriteSheet2, &spritePal2);
    LoadSpriteSheet(&spriteSheet2);
    LoadSpritePalette(&spritePal2);
}

bool8 sub_8167930(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 136 << 6, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, 28736);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2|BLDCNT_EFFECT_BLEND|BLDCNT_TGT2_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        break;
    case 1:
        gUnknown_0203BCA4 = Alloc(6656);
        gUnknown_0203BCA0 = Alloc(1280);
        gUnknown_0203BCA8 = Alloc(1280);
        break;
    case 2:
        LZ77UnCompVram(gUnknown_085DFB60, gUnknown_0203BCA8);
        break;
    case 3:
        LoadBgTiles(3, gUnknown_085DFA80, 224, 0);
        break;
    case 4:
         LoadBgTilemap(3, gUnknown_0203BCA8, 1280, 0);
        break;
    case 5:
        LoadPalette(gUnknown_085DFA60, 208, 32);
        gUnknown_0203BCAC->field_7B0E = 0xFFB0;
        break;
    case 6:
        LZ77UnCompVram(gUsePokeblockGraph_Gfx, gUnknown_0203BCA4);
        break;
    case 7:
        LZ77UnCompVram(gUsePokeblockGraph_Tilemap, gUnknown_0203BCA0);
        LoadPalette(gUsePokeblockGraph_Pal, 32, 32);
        break;
    case 8:
        LoadBgTiles(1, gUnknown_0203BCA4, 6656, 160 << 2);
        break;
    case 9:
        SetBgTilemapBuffer(1, gUnknown_0203BCA0);
        CopyToBgTilemapBufferRect(1, gUsePokeblockNatureWin_Pal, 0, 13, 12, 4);
        CopyBgTilemapBufferToVram(1);
        break;
    case 10:
        LZ77UnCompVram(gUnknown_085DFC0C, gUnknown_0203BCAC->tilemapBuffer);
        break;
    case 11:
        LoadBgTilemap(2, gUnknown_0203BCAC->tilemapBuffer, 1280, 0);
        LoadPalette(gUnknown_086231E8, 48, 32);
        LoadPalette(gUnknown_08623208, 240, 32);
        sub_81D21DC(2);
        break;
    default:
        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    gUnknown_0203BCAC->info.unk78++;
    return TRUE;
}

void sub_8167BA0(u16 arg0, u8 copyToVramMode)
{
    u8 partyIndex;
    u8 nature;
    u8 *str;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
    {
        AddTextPrinterParameterized(0, 1, gUnknown_0203BCAC->field_7B95[arg0], 0, 1, 0, NULL);
        partyIndex = sub_81672A4(gUnknown_0203BCAC->info.field_71);
        nature = GetNature(&gPlayerParty[partyIndex]);
        str = StringCopy(gUnknown_0203BCAC->info.field_7A, gText_NatureSlash);
        str = StringCopy(str, gNatureNamePointers[nature]);
        AddTextPrinterParameterized3(1, 1, 2, 1, sNatureTextColors, 0, gUnknown_0203BCAC->info.field_7A);
    }

    if (copyToVramMode)
    {
        CopyWindowToVram(0, 3);
        CopyWindowToVram(1, 3);
    }
    else
    {
        CopyWindowToVram(0, 2);
        CopyWindowToVram(1, 2);
    }
}

static void sub_8167CA0(bool8 arg0)
{
    u16 var0;
    bool32 r8, r4;

    if (arg0)
        var0 = gUnknown_0203BCAC->field_7FB5;
    else
        var0 = gUnknown_0203BCAC->field_7FB4;

    sub_81D1F84(
        &gUnknown_0203BCAC->field_7C58,
        gUnknown_0203BCAC->field_7C58.unk14[gUnknown_0203BCAC->field_7FB3],
        gUnknown_0203BCAC->field_7C58.unk14[var0]);

    r8 = (gUnknown_0203BCAC->info.field_71 ^ (gUnknown_0203BCAC->info.field_70 - 1)) ? 1 : 0;
    if (arg0)
    {
        gUnknown_0203BCAC->field_7FB5 = gUnknown_0203BCAC->field_7FB4;
        gUnknown_0203BCAC->field_7FB4 = gUnknown_0203BCAC->field_7FB3;
        gUnknown_0203BCAC->field_7FB3 = var0;
        gUnknown_0203BCAC->field_7FB6 = gUnknown_0203BCAC->field_7FB5;

        gUnknown_0203BCAC->info.field_71 = (gUnknown_0203BCAC->info.field_71 == 0)
            ? gUnknown_0203BCAC->info.field_70 - 1
            : gUnknown_0203BCAC->info.field_71 - 1;

        gUnknown_0203BCAC->field_7B4C = (gUnknown_0203BCAC->info.field_71 == 0)
            ? gUnknown_0203BCAC->info.field_70 - 1
            : gUnknown_0203BCAC->info.field_71 - 1;
    }
    else
    {
        gUnknown_0203BCAC->field_7FB4 = gUnknown_0203BCAC->field_7FB5;
        gUnknown_0203BCAC->field_7FB5 = gUnknown_0203BCAC->field_7FB3;
        gUnknown_0203BCAC->field_7FB3 = var0;
        gUnknown_0203BCAC->field_7FB6 = gUnknown_0203BCAC->field_7FB4;

        gUnknown_0203BCAC->info.field_71 = (gUnknown_0203BCAC->info.field_71 < gUnknown_0203BCAC->info.field_70 - 1)
            ? gUnknown_0203BCAC->info.field_71 + 1
            : 0;

        gUnknown_0203BCAC->field_7B4C = (gUnknown_0203BCAC->info.field_71 < gUnknown_0203BCAC->info.field_70 - 1)
            ? gUnknown_0203BCAC->info.field_71 + 1
            : 0;
    }

    r4 = (gUnknown_0203BCAC->info.field_71 ^ (gUnknown_0203BCAC->info.field_70 - 1)) ? 1 : 0;
    sub_81D3520(gUnknown_0203BCAC->field_7B1C);

    if (!r8)
        gUnknown_0203BCAC->info.unk74 = sub_8167EA4;
    else if (!r4)
        gUnknown_0203BCAC->info.unk74 = sub_8167FA4;
    else
        gUnknown_0203BCAC->info.unk74 = sub_8168048;
}

static u8 sub_8167EA4(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_8167608(gUnknown_0203BCAC->field_7FB3);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        if (!sub_81D3178(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
        {
            sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 3:
        sub_81D3464(gUnknown_0203BCAC->field_7B1C);
        if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
        {
            u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
            sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
        }

        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8167FA4(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        if (!sub_81D31A4(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
            gUnknown_0203BCAC->info.unk78++;
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 3:
        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8168048(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_81D2074(&gUnknown_0203BCAC->field_7C58);
        if (!sub_81D3150(&gUnknown_0203BCAC->field_7B0E))
        {
            sub_8167608(gUnknown_0203BCAC->field_7FB3);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        if (!sub_81D3178(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
        {
            sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 3:
        sub_81D3464(gUnknown_0203BCAC->field_7B1C);
        if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
        {
            u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
            sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
        }

        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

void sub_8168168(struct Sprite *sprite)
{
    sprite->pos1.x = gUnknown_0203BCAC->field_7B0E + 38;
}

void sub_8168180(struct Sprite *sprite)
{
    if (sprite->data[0] == gUnknown_0203BCAC->info.field_71)
        StartSpriteAnim(sprite, 0);
    else
        StartSpriteAnim(sprite, 1);
}

void sub_81681B4(struct Sprite *sprite)
{
    if (gUnknown_0203BCAC->info.field_71 == gUnknown_0203BCAC->info.field_70 - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(101);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(102);
}

void sub_81681F4(u8 monIndex)
{
    u8 sheen = GetMonData(&gPlayerParty[monIndex], MON_DATA_SHEEN);

    gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3] = (sheen != 255)
        ? sheen / 29
        : 9;
}

static void sub_8168248(void)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spritePalette = gSpritePalette_085DFDB8;
    spriteSheet.data = gUsePokeblockCondition_Gfx;
    spriteSheet.size = 0x800;
    spriteSheet.tag = 1;
    LoadCompressedSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
}

static void sub_8168294(void)
{
    u16 i;
    s16 xDiff, xStart;
    int yStart = 17;
    int var = 8;
    struct Sprite **sprites = gUnknown_0203BCAC->field_7B44;
    const struct SpriteTemplate *template = &gSpriteTemplate_085DFDA0;

    for (i = 0, xDiff = 64, xStart = -96; i < 2; i++)
    {
        u8 spriteId = CreateSprite(template, i * xDiff + xStart, yStart, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = var;
            gSprites[spriteId].data[1] = (i * xDiff) | 0x20;
            gSprites[spriteId].data[2] = i;
            StartSpriteAnim(&gSprites[spriteId], i);
            sprites[i] = &gSprites[spriteId];
        }
    }
}

static bool8 sub_8168328(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_8168248();
        gUnknown_0203BCAC->info.unk78++;
        return TRUE;
    case 1:
        sub_8168294();
        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return FALSE;
}

void sub_8168374(struct Sprite *sprite)
{
    s16 prevX = sprite->pos1.x;

    sprite->pos1.x += sprite->data[0];
    if ((prevX <= sprite->data[1] && sprite->pos1.x >= sprite->data[1])
     || (prevX >= sprite->data[1] && sprite->pos1.x <= sprite->data[1]))
    {
        sprite->pos1.x = sprite->data[1];
        sprite->callback = SpriteCallbackDummy;
    }
}

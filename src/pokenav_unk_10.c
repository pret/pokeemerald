#include "global.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "international_string_util.h"
#include "pokenav.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"

struct Pokenav10Struct
{
    u32 field_0[5];
    struct Sprite *field_14;
};

struct Pokenav10Struct2
{
    u32 filler0[2];
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u8 filler[2];
    u16 field_10;
};

// To do: move to C.
extern const u16 gUnknown_08623FF8[];
extern const u16 gUnknown_08624038[];
extern const u16 gUnknown_08624018[];
extern const u16 gUnknown_08624078[];
extern const u16 gUnknown_08624058[];
extern const u32 gUnknown_08624280[];
extern const u8 gText_RibbonsF700[];
extern const u8 *const gRibbonDescriptionPointers[][2];
extern const u8 *const gGiftRibbonDescriptionPointers[][2];

extern u32 gUnknown_030012C0;
extern u32 gUnknown_030012C4;

void sub_81D0E84(struct Pokenav10Struct2 *structPtr);
void sub_81D0FF0(struct Pokenav10Struct2 *structPtr);
void sub_81D10D0(struct Pokenav10Struct2 *structPtr);
u32 sub_81D06C4(void);
u32 sub_81D07D8(void);
u32 sub_81D06D4(void);
void sub_81D06E4(u8 *nick, u8 *level, u8 *gender);
void sub_81D0760(u16 *species, u32 *personality, u32 *otId);
u16 sub_81D1184(s32 unused0, s32 unused1);
void sub_81D1258(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3);
void sub_81D1284(struct Sprite *sprite);
u32 *sub_81D0914(u32 *arg0);
u32 *sub_81D092C(u32 *arg0);
void sub_81D1350(void);
void sub_81D13BC(u16 *dst, u32 id);
void sub_81D1370(u32 arg0, u32 id);
u16 sub_81D0944(void);
u32 sub_81D0954(void);
void sub_81D1500(struct Pokenav10Struct *structPtr);
bool32 sub_81D1524(struct Pokenav10Struct *structPtr);
void sub_81D1538(struct Sprite *sprite);

// code
static const struct WindowTemplate gUnknown_08624BB8 =
{
    .bg = 2,
    .tilemapLeft = 12,
    .tilemapTop = 13,
    .width = 16,
    .height = 4,
    .paletteNum = 1,
    .baseBlock = 0x14,
};

void sub_81D0E60(struct Pokenav10Struct2 *structPtr)
{
    structPtr->field_A = AddWindow(&gUnknown_08624BB8);
    PutWindowTilemap(structPtr->field_A);
    sub_81D0E84(structPtr);
}

void sub_81D0E84(struct Pokenav10Struct2 *structPtr)
{
    u8 color[] = {4, 2, 3};

    ConvertIntToDecimalStringN(gStringVar1, sub_81D07D8(), STR_CONV_MODE_LEFT_ALIGN, 2);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_RibbonsF700);
    FillWindowPixelBuffer(structPtr->field_A, PIXEL_FILL(4));
    AddTextPrinterParameterized3(structPtr->field_A, 1, 0, 1, color, -1, gStringVar4);
    CopyWindowToVram(structPtr->field_A, 2);
}

void sub_81D0EFC(struct Pokenav10Struct2 *structPtr)
{
    s32 i;
    u32 ribbonId = sub_81D0954();
    u8 color[] = {4, 2, 3};

    FillWindowPixelBuffer(structPtr->field_A, PIXEL_FILL(4));
    if (ribbonId < 25)
    {
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(structPtr->field_A, 1, 0, (i * 16) + 1, color, -1, gRibbonDescriptionPointers[ribbonId][i]);
    }
    else
    {
        ribbonId = gSaveBlock1Ptr->giftRibbons[ribbonId - 25];
        if (ribbonId == 0)
            return;

        ribbonId--;
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(structPtr->field_A, 1, 0, (i * 16) + 1, color, -1, gGiftRibbonDescriptionPointers[ribbonId][i]);
    }

    CopyWindowToVram(structPtr->field_A, 2);
}

static const struct WindowTemplate gUnknown_08624BC4 =
{
    .bg = 2,
    .tilemapLeft = 14,
    .tilemapTop = 1,
    .width = 13,
    .height = 2,
    .paletteNum = 10,
    .baseBlock = 0x54,
};

void sub_81D0FCC(struct Pokenav10Struct2 *structPtr)
{
    structPtr->field_8 = AddWindow(&gUnknown_08624BC4);
    PutWindowTilemap(structPtr->field_8);
    sub_81D0FF0(structPtr);
}

static const u8 sMaleIconString[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sFemaleIconString[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sGenderlessIconString[] = _("{UNK_SPACER}");

void sub_81D0FF0(struct Pokenav10Struct2 *structPtr)
{
    const u8 *genderTxt;
    u8 *txtPtr;
    u8 level, gender;
    u16 windowId = structPtr->field_8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    sub_81D06E4(gStringVar3, &level, &gender);
    AddTextPrinterParameterized(windowId, 1, gStringVar3, 0, 1, TEXT_SPEED_FF, NULL);
    switch (gender)
    {
    case MON_MALE:
        genderTxt = sMaleIconString;
        break;
    case MON_FEMALE:
        genderTxt = sFemaleIconString;
        break;
    default:
        genderTxt = sGenderlessIconString;
        break;
    }

    txtPtr = StringCopy(gStringVar1, genderTxt);
    *(txtPtr++) = CHAR_SLASH;
    *(txtPtr++) = CHAR_SPECIAL_F9;
    *(txtPtr++) = 5;
    ConvertIntToDecimalStringN(txtPtr, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, 1, gStringVar1, 60, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(windowId, 2);
}

static const struct WindowTemplate gUnknown_08624BE8[] =
{
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 5,
        .width = 7,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 0x6E,
    },
    {},
};

void sub_81D10A4(struct Pokenav10Struct2 *structPtr)
{
    structPtr->field_C = AddWindow(gUnknown_08624BE8);
    FillWindowPixelBuffer(structPtr->field_C, PIXEL_FILL(1));
    PutWindowTilemap(structPtr->field_C);
    sub_81D10D0(structPtr);
}

void sub_81D10D0(struct Pokenav10Struct2 *structPtr)
{
    s32 x;
    u8 *txtPtr;
    u32 id = sub_81D06C4() + 1;
    u32 count = sub_81D06D4();

    txtPtr = ConvertIntToDecimalStringN(gStringVar1, id, STR_CONV_MODE_RIGHT_ALIGN, 3);
    *(txtPtr++) = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, count, STR_CONV_MODE_RIGHT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 56);
    AddTextPrinterParameterized(structPtr->field_C, 1, gStringVar1, x, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(structPtr->field_C, 2);
}

void sub_81D1148(struct Pokenav10Struct2 *structPtr)
{
    u16 species;
    u32 personality, otId;

    sub_81D0760(&species, &personality, &otId);
    ResetAllPicSprites();
    structPtr->field_10 = sub_81D1184(40, 104);
    sub_81C7990(15, 0);
}

void sub_81D1178(struct Pokenav10Struct2 *structPtr)
{
    FreeAndDestroyMonPicSprite(structPtr->field_10);
}

u16 sub_81D1184(s32 unused0, s32 unused1)
{
    u16 species, spriteId;
    u32 personality, otId;

    sub_81D0760(&species, &personality, &otId);
    spriteId = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 40, 104, 15, 0xFFFF);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

void sub_81D11D8(struct Pokenav10Struct2 *structPtr)
{
    sub_81D1258(&gSprites[structPtr->field_10], 40, -32, 6);
}

void sub_81D11FC(struct Pokenav10Struct2 *structPtr)
{
    FreeAndDestroyMonPicSprite(structPtr->field_10);
    structPtr->field_10 = sub_81D1184(-32, 104);
    sub_81D1258(&gSprites[structPtr->field_10], -32, 40, 6);
}

bool32 sub_81D1234(struct Pokenav10Struct2 *structPtr)
{
    return (gSprites[structPtr->field_10].callback != SpriteCallbackDummy);
}

void sub_81D1258(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3)
{
    u32 var = arg2 - arg1;

    sprite->pos1.x = arg1;
    sprite->data[0] = arg1 << 4;
    sprite->data[1] = (var << 4) / arg3;
    sprite->data[2] = arg3;
    sprite->data[3] = arg2;

    sprite->callback = sub_81D1284;
}

void sub_81D1284(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
    {
        sprite->data[2]--;
        sprite->data[0] += sprite->data[1];
        sprite->pos1.x = sprite->data[0] >> 4;
        if (sprite->pos1.x <= -32)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->pos1.x = sprite->data[3];
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_81D12D8(void)
{
    u32 *ptr;

    sub_81D1350();

    ptr = sub_81D0914(&gUnknown_030012C0);
    for (gUnknown_030012C4 = 0; gUnknown_030012C4 < gUnknown_030012C0; gUnknown_030012C4++)
        sub_81D1370(gUnknown_030012C4, *(ptr++));

    ptr = sub_81D092C(&gUnknown_030012C0);
    for (gUnknown_030012C4 = 0; gUnknown_030012C4 < gUnknown_030012C0; gUnknown_030012C4++)
        sub_81D1370(gUnknown_030012C4 + 27, *(ptr++));

    CopyBgTilemapBufferToVram(1);
}

void sub_81D1350(void)
{
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
}

void sub_81D1370(u32 arg0, u32 id)
{
    u16 bgData[4];
    u32 destX = (arg0 % 9) * 2 + 11;
    u32 destY = (arg0 / 9) * 2 + 4;

    sub_81D13BC(bgData, id);
    CopyToBgTilemapBufferRect(1, bgData, destX, destY, 2, 2);
}

struct
{
    u16 var0;
    u16 var2;
} static const gUnknown_08624BF8[] =
{
    {0, 0},
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
    {1, 1},
    {2, 1},
    {3, 1},
    {4, 1},
    {1, 2},
    {2, 2},
    {3, 2},
    {4, 2},
    {1, 3},
    {2, 3},
    {3, 3},
    {4, 3},
    {1, 4},
    {2, 4},
    {3, 4},
    {4, 4},
    {5, 0},
    {6, 0},
    {7, 1},
    {8, 2},
    {9, 1},
    {9, 3},
    {9, 4},
    {10, 3},
    {10, 4},
    {11, 0},
    {11, 1},
};

void sub_81D13BC(u16 *dst, u32 id)
{
    u16 r3 = gUnknown_08624BF8[id].var2 + 2;
    u16 r1 = (gUnknown_08624BF8[id].var0 * 2) + 1;

    dst[0] = r1 | (r3 << 12);
    dst[1] = r1 | (r3 << 12) |0x400;
    dst[2] = (r1 + 1) | (r3 << 12);
    dst[3] = (r1 + 1) | (r3 << 12) | 0x400;
}

static const struct CompressedSpriteSheet gUnknown_08624C78 =
{
    gUnknown_08624280, 0x1800, 9
};

static const struct SpritePalette gUnknown_08624C80[] =
{
    {gUnknown_08623FF8, 15},
    {gUnknown_08624018, 16},
    {gUnknown_08624038, 17},
    {gUnknown_08624058, 18},
    {gUnknown_08624078, 19},
    {},
};

static const struct OamData sOamData_8624CB0 =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CB8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CC8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(32, 32, 0, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CE0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-32, -32, 0, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_8624CF8[] =
{
    sSpriteAffineAnim_8624CB8,
    sSpriteAffineAnim_8624CC8,
    sSpriteAffineAnim_8624CE0
};

static const struct SpriteTemplate gUnknown_08624D04 =
{
    .tileTag = 9,
    .paletteTag = 15,
    .oam = &sOamData_8624CB0,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_8624CF8,
    .callback = SpriteCallbackDummy,
};

void sub_81D13FC(struct Pokenav10Struct *structPtr)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08624C78);
    Pokenav_AllocAndLoadPalettes(gUnknown_08624C80);

    spriteId = CreateSprite(&gUnknown_08624D04, 0, 0, 0);
    structPtr->field_14 = &gSprites[spriteId];
    structPtr->field_14->invisible = TRUE;
}

void sub_81D1448(struct Pokenav10Struct *structPtr)
{
    u32 ribbonId;
    s32 r4 = sub_81D0944();
    s32 r5 = (r4 % 9) * 16 + 96;
    s32 r0 = (r4 / 9) * 16 + 40;

    structPtr->field_14->pos1.x = r5;
    structPtr->field_14->pos1.y = r0;

    ribbonId = sub_81D0954();
    structPtr->field_14->oam.tileNum = (gUnknown_08624BF8[ribbonId].var0 * 16) + GetSpriteTileStartByTag(9);
    structPtr->field_14->oam.paletteNum = IndexOfSpritePaletteTag(gUnknown_08624BF8[ribbonId].var2 + 15);

    StartSpriteAffineAnim(structPtr->field_14, 1);
    structPtr->field_14->invisible = FALSE;
    structPtr->field_14->data[0] = 0;
    structPtr->field_14->callback = sub_81D1538;
}

void sub_81D1500(struct Pokenav10Struct *structPtr)
{
    structPtr->field_14->data[0] = 1;
    StartSpriteAffineAnim(structPtr->field_14, 2);
    structPtr->field_14->callback = sub_81D1538;
}

bool32 sub_81D1524(struct Pokenav10Struct *structPtr)
{
    return (structPtr->field_14->callback != SpriteCallbackDummy);
}

void sub_81D1538(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sprite->invisible = sprite->data[0];
        sprite->callback = SpriteCallbackDummy;
    }
}

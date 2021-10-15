#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "palette.h"
#include "decompress.h"
#include "malloc.h"
#include "menu.h"
#include "pokemon_icon.h"
#include "union_room.h"
#include "list_menu.h"
#include "text_window.h"
#include "string_util.h"
#include "link_rfu.h"
#include "mevent.h"
#include "mystery_gift.h"
#include "wonder_transfer.h"
#include "constants/rgb.h"
#include "constants/mevent.h"

struct WonderGraphics
{
    u8 textPal1:4;
    u8 textPal2:4;
    u8 textPal3:4;
    u8 textPal4:4;
    const u32 * tiles;
    const u32 * map;
    const u16 * pal;
};

//======================
//    Wonder Cards
//======================

enum {
    CARD_WIN_0,
    CARD_WIN_1,
    CARD_WIN_2,
    CARD_WIN_COUNT
};

#define TAG_ICON_SHADOW 0x8000

struct UnkStruct_203F3C8_02DC
{
    u8 unk_00;
    u8 unk_01[WONDER_CARD_TEXT_LENGTH + 1];
    u8 unk_42[4];
};

struct WonderCardData
{
    /*0000*/ struct WonderCard card;
    /*014c*/ struct WonderCardMetadata cardMetadata;
    /*0170*/ const struct WonderGraphics * gfx;
    /*0174*/ u8 enterExitState;
    /*0175*/ u8 unk_0175;
    /*0176*/ u16 windowIds[CARD_WIN_COUNT];
    /*017C*/ u8 monIconSpriteId;
    /*017D*/ u8 unk_017D[7][2];
    /*018B*/ u8 unk_018B[WONDER_CARD_TEXT_LENGTH + 1];
    /*01B4*/ u8 unk_01B4[WONDER_CARD_TEXT_LENGTH + 1];
    /*01DD*/ u8 unk_01DD[7];
    /*01E4*/ u8 unk_01E4[4][WONDER_CARD_TEXT_LENGTH + 1];
    /*0288*/ u8 unk_0288[WONDER_CARD_TEXT_LENGTH + 1];
    /*02B1*/ u8 unk_02B1[WONDER_CARD_TEXT_LENGTH + 1];
    /*02DC*/ struct UnkStruct_203F3C8_02DC unk_02DC[8];
    /*045C*/ u8 buffer_045C[0x1000];
};

EWRAM_DATA static struct WonderCardData * sWonderCardData = NULL;

static void BufferCardText(void);
static void DrawCardWindow(u8 whichWindow);
static void CreateCardSprites(void);
static void DestroyCardSprites(void);

extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;

static const u8 sCard_TextColorTable[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY}
};

static const u8 ALIGNED(4) sCard_TextYOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_GIFT] = 7,
    [CARD_TYPE_STAMP] = 4,
    [CARD_TYPE_LINK_STAT] = 7
};

static const struct WindowTemplate sCard_WindowTemplates[] = {
    [CARD_WIN_0] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 25,
        .height = 4,
        .paletteNum = 2,
        .baseBlock = 0x029c
    },
    [CARD_WIN_1] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 28,
        .height = 8,
        .paletteNum = 2,
        .baseBlock = 0x01bc
    },
    [CARD_WIN_2] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 28,
        .height = 5,
        .paletteNum = 2,
        .baseBlock = 0x0130
    }
};

static const u16 sWonderCardBgPal1[]     = INCBIN_U16("graphics/wonder_card/bg1.gbapal");
static const u16 sWonderCardBgPal2[]     = INCBIN_U16("graphics/wonder_card/bg2.gbapal");
static const u16 sWonderCardBgPal3[]     = INCBIN_U16("graphics/wonder_card/bg3.gbapal");
static const u16 sWonderCardBgPal4[]     = INCBIN_U16("graphics/wonder_card/bg4.gbapal");
static const u16 sWonderCardBgPal5[]     = INCBIN_U16("graphics/wonder_card/bg5.gbapal");
static const u16 sWonderCardBgPal6[]     = INCBIN_U16("graphics/wonder_card/bg6.gbapal");
static const u16 sWonderCardBgPal7[]     = INCBIN_U16("graphics/wonder_card/bg7.gbapal");
static const u16 sWonderCardBgPal8[]     = INCBIN_U16("graphics/wonder_card/bg8.gbapal");
static const u32 sWonderCardBgGfx1[]     = INCBIN_U32("graphics/wonder_card/bg1.4bpp.lz");
static const u32 sWonderCardBgTilemap1[] = INCBIN_U32("graphics/wonder_card/bg1.bin.lz");
static const u32 sWonderCardBgGfx2[]     = INCBIN_U32("graphics/wonder_card/bg2.4bpp.lz");
static const u32 sWonderCardBgTilemap2[] = INCBIN_U32("graphics/wonder_card/bg2.bin.lz");
static const u32 sWonderCardBgGfx3[]     = INCBIN_U32("graphics/wonder_card/bg3.4bpp.lz");
static const u32 sWonderCardBgTilemap3[] = INCBIN_U32("graphics/wonder_card/bg3.bin.lz");
static const u32 sWonderCardBgGfx7[]     = INCBIN_U32("graphics/wonder_card/bg7.4bpp.lz");
static const u32 sWonderCardBgTilemap7[] = INCBIN_U32("graphics/wonder_card/bg7.bin.lz");
static const u32 sWonderCardBgGfx8[]     = INCBIN_U32("graphics/wonder_card/bg8.4bpp.lz");
static const u32 sWonderCardBgTilemap8[] = INCBIN_U32("graphics/wonder_card/bg8.bin.lz");
static const u16 sIconShadowPal1[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_1.gbapal");
static const u16 sIconShadowPal2[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_2.gbapal");
static const u16 sIconShadowPal3[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_3.gbapal");
static const u16 sIconShadowPal4[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_4.gbapal");
static const u16 sIconShadowPal5[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_5.gbapal");
static const u16 sIconShadowPal6[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_6.gbapal");
static const u16 sIconShadowPal7[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_7.gbapal");
static const u16 sIconShadowPal8[]       = INCBIN_U16("graphics/wonder_card/icon_shadow_8.gbapal");
static const u32 sIconShadowGfx[]        = INCBIN_U32("graphics/wonder_card/icon_shadow.4bpp.lz");

static const struct CompressedSpriteSheet sSpriteSheet_IconShadow = {
    sIconShadowGfx, 0x100, TAG_ICON_SHADOW
};

static const struct SpritePalette sSpritePalettes_IconShadow[] = {
    {sIconShadowPal1, TAG_ICON_SHADOW},
    {sIconShadowPal2, TAG_ICON_SHADOW},
    {sIconShadowPal3, TAG_ICON_SHADOW},
    {sIconShadowPal4, TAG_ICON_SHADOW},
    {sIconShadowPal5, TAG_ICON_SHADOW},
    {sIconShadowPal6, TAG_ICON_SHADOW},
    {sIconShadowPal7, TAG_ICON_SHADOW},
    {sIconShadowPal8, TAG_ICON_SHADOW}
};

static const struct SpriteTemplate sSpriteTemplate_IconShadow = {
    .tileTag = TAG_ICON_SHADOW,
    .paletteTag = TAG_ICON_SHADOW,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct WonderGraphics sCardGraphics[NUM_WONDER_BGS] = {
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 0, .tiles = sWonderCardBgGfx1, .map = sWonderCardBgTilemap1, .pal = sWonderCardBgPal1},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 1, .tiles = sWonderCardBgGfx2, .map = sWonderCardBgTilemap2, .pal = sWonderCardBgPal2},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 2, .tiles = sWonderCardBgGfx3, .map = sWonderCardBgTilemap3, .pal = sWonderCardBgPal3},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 3, .tiles = sWonderCardBgGfx3, .map = sWonderCardBgTilemap3, .pal = sWonderCardBgPal4},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 4, .tiles = sWonderCardBgGfx3, .map = sWonderCardBgTilemap3, .pal = sWonderCardBgPal5},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 5, .tiles = sWonderCardBgGfx3, .map = sWonderCardBgTilemap3, .pal = sWonderCardBgPal6},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 6, .tiles = sWonderCardBgGfx7, .map = sWonderCardBgTilemap7, .pal = sWonderCardBgPal7},
    {.textPal1 = 1, .textPal2 = 0, .textPal3 = 0, .textPal4 = 7, .tiles = sWonderCardBgGfx8, .map = sWonderCardBgTilemap8, .pal = sWonderCardBgPal8}
};

bool32 WonderCard_Init(struct WonderCard * card, struct WonderCardMetadata * metadata)
{
    if (card == NULL || metadata == NULL)
        return FALSE;
    sWonderCardData = AllocZeroed(sizeof(*sWonderCardData));
    if (sWonderCardData == NULL)
        return FALSE;
    sWonderCardData->card = *card;
    sWonderCardData->cardMetadata = *metadata;
    if (sWonderCardData->card.bgType >= NUM_WONDER_BGS)
        sWonderCardData->card.bgType = 0;
    if (sWonderCardData->card.type >= CARD_TYPE_COUNT)
        sWonderCardData->card.type = 0;
    if (sWonderCardData->card.maxStamps > ARRAY_COUNT(sWonderCardData->unk_017D))
        sWonderCardData->card.maxStamps = 0;
    sWonderCardData->gfx = &sCardGraphics[sWonderCardData->card.bgType];
    return TRUE;
}

void WonderCard_Destroy(void)
{
    if (sWonderCardData != NULL)
    {
        *sWonderCardData = (struct WonderCardData){};
        Free(sWonderCardData);
        sWonderCardData = NULL;
    }
}

s32 WonderCard_Enter(void)
{
    if (sWonderCardData == NULL)
        return -1;
    switch(sWonderCardData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        DecompressAndCopyTileDataToVram(2, sWonderCardData->gfx->tiles, 0, 0x008, 0);
        sWonderCardData->windowIds[CARD_WIN_0] = AddWindow(&sCard_WindowTemplates[CARD_WIN_0]);
        sWonderCardData->windowIds[CARD_WIN_1] = AddWindow(&sCard_WindowTemplates[CARD_WIN_1]);
        sWonderCardData->windowIds[CARD_WIN_2] = AddWindow(&sCard_WindowTemplates[CARD_WIN_2]);
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible())
            return 0;
        LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
        gPaletteFade.bufferTransferDisabled = TRUE;
        LoadPalette(sWonderCardData->gfx->pal, 0x10, 0x20);
        LZ77UnCompWram(sWonderCardData->gfx->map, sWonderCardData->buffer_045C);
        CopyRectToBgTilemapBufferRect(2, sWonderCardData->buffer_045C, 0, 0, 30, 20, 0, 0, 30, 20, 1, 0x008, 0);
        CopyBgTilemapBufferToVram(2);
        break;
    case 4:
        BufferCardText();
        break;
    case 5:
        DrawCardWindow(CARD_WIN_0);
        DrawCardWindow(CARD_WIN_1);
        DrawCardWindow(CARD_WIN_2);
        CopyBgTilemapBufferToVram(1);
        break;
    case 6:
        LoadMonIconPalettes();
        break;
    case 7:
        ShowBg(1);
        ShowBg(2);
        gPaletteFade.bufferTransferDisabled = FALSE;
        CreateCardSprites();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        UpdatePaletteFade();
        break;
    default:
        if (UpdatePaletteFade())
            return 0;
        sWonderCardData->enterExitState = 0;
        return 1;
    }
    ++sWonderCardData->enterExitState;
    return 0;
}

s32 WonderCard_Exit(bool32 flag)
{
    if (sWonderCardData == NULL)
        return -1;
    switch (sWonderCardData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 3:
        HideBg(1);
        HideBg(2);
        RemoveWindow(sWonderCardData->windowIds[CARD_WIN_2]);
        RemoveWindow(sWonderCardData->windowIds[CARD_WIN_1]);
        RemoveWindow(sWonderCardData->windowIds[CARD_WIN_0]);
        break;
    case 4:
        DestroyCardSprites();
        FreeMonIconPalettes();
        break;
    case 5:
        PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader, flag);
        CopyBgTilemapBufferToVram(0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        break;
    default:
        if (UpdatePaletteFade())
            return 0;
        sWonderCardData->enterExitState = 0;
        return 1;
    }
    ++sWonderCardData->enterExitState;
    return 0;
}

static void BufferCardText(void)
{
    u16 i = 0;
    u16 r6;
    u16 sp0[3] = {0, 0, 0};

    memcpy(sWonderCardData->unk_018B, sWonderCardData->card.unk_0A, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->unk_018B[WONDER_CARD_TEXT_LENGTH] = EOS;
    memcpy(sWonderCardData->unk_01B4, sWonderCardData->card.unk_32, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->unk_01B4[WONDER_CARD_TEXT_LENGTH] = EOS;
    if (sWonderCardData->card.unk_04 > 999999)
        sWonderCardData->card.unk_04 = 999999;
    ConvertIntToDecimalStringN(sWonderCardData->unk_01DD, sWonderCardData->card.unk_04, STR_CONV_MODE_LEFT_ALIGN, 6);
    for (i = 0; i < 4; i++)
    {
        memcpy(sWonderCardData->unk_01E4[i], sWonderCardData->card.unk_5A[i], WONDER_CARD_TEXT_LENGTH);
        sWonderCardData->unk_01E4[i][WONDER_CARD_TEXT_LENGTH] = EOS;
    }
    memcpy(sWonderCardData->unk_0288, sWonderCardData->card.unk_FA, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->unk_0288[WONDER_CARD_TEXT_LENGTH] = EOS;
    switch (sWonderCardData->card.type)
    {
    case CARD_TYPE_GIFT:
        memcpy(sWonderCardData->unk_02B1, sWonderCardData->card.unk_122, WONDER_CARD_TEXT_LENGTH);
        sWonderCardData->unk_02B1[WONDER_CARD_TEXT_LENGTH] = EOS;
        break;
    case CARD_TYPE_STAMP:
        sWonderCardData->unk_02B1[0] = EOS;
        break;
    case CARD_TYPE_LINK_STAT:
        sWonderCardData->unk_02B1[0] = EOS;
        sp0[0] = sWonderCardData->cardMetadata.battlesWon < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.battlesWon : MAX_WONDER_CARD_STAT;
        sp0[1] = sWonderCardData->cardMetadata.battlesLost < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.battlesLost : MAX_WONDER_CARD_STAT;
        sp0[2] = sWonderCardData->cardMetadata.numTrades < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.numTrades : MAX_WONDER_CARD_STAT;
        for (i = 0; i < 8; i++)
        {
            memset(sWonderCardData->unk_02DC[i].unk_42, EOS, sizeof(sWonderCardData->unk_02DC[i].unk_42));
            memset(sWonderCardData->unk_02DC[i].unk_01, EOS, sizeof(sWonderCardData->unk_02DC[i].unk_01));
        }
        for (i = 0, r6 = 0; i < WONDER_CARD_TEXT_LENGTH; i++)
        {
            if (sWonderCardData->card.unk_122[i] != CHAR_DYNAMIC)
            {
                sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_01[r6] = sWonderCardData->card.unk_122[i];
                r6++;
            }
            else
            {
                u8 r3 = sWonderCardData->card.unk_122[i + 1];
                if (r3 > 2)
                {
                    i += 2;
                }
                else
                {
                    ConvertIntToDecimalStringN(sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_42, sp0[r3], STR_CONV_MODE_LEADING_ZEROS, 3);
                    sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_00 = sWonderCardData->card.unk_122[i + 2];
                    sWonderCardData->unk_0175++;
                    if (sWonderCardData->unk_0175 > 7)
                        break;
                    r6 = 0;
                    i += 2;
                }
            }
        }
    }
}

static void DrawCardWindow(u8 whichWindow)
{
    s8 sp0C = 0;
    s32 windowId = sWonderCardData->windowIds[whichWindow];
    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, 0);
    switch (whichWindow)
    {
    case CARD_WIN_0:
    {
        s32 x;
        AddTextPrinterParameterized3(windowId, 3, 0, 1, sCard_TextColorTable[sWonderCardData->gfx->textPal1], 0, sWonderCardData->unk_018B);
        x = 160 - GetStringWidth(3, sWonderCardData->unk_01B4, GetFontAttribute(3, FONTATTR_LETTER_SPACING));
        if (x < 0)
            x = 0;
        AddTextPrinterParameterized3(windowId, 3, x, 17, sCard_TextColorTable[sWonderCardData->gfx->textPal1], 0, sWonderCardData->unk_01B4);
        if (sWonderCardData->card.unk_04 != 0)
            AddTextPrinterParameterized3(windowId, 1, 166, 17, sCard_TextColorTable[sWonderCardData->gfx->textPal1], 0, sWonderCardData->unk_01DD);
        break;
    }
    case CARD_WIN_1:
        for (; sp0C < 4; sp0C++)
            AddTextPrinterParameterized3(windowId, 3, 0, 16 * sp0C + 2, sCard_TextColorTable[sWonderCardData->gfx->textPal2], 0, sWonderCardData->unk_01E4[sp0C]);
        break;
    case CARD_WIN_2:
        AddTextPrinterParameterized3(windowId, 3, 0, sCard_TextYOffsets[sWonderCardData->card.type], sCard_TextColorTable[sWonderCardData->gfx->textPal3], 0, sWonderCardData->unk_0288);
        if (sWonderCardData->card.type != CARD_TYPE_LINK_STAT)
        {
            AddTextPrinterParameterized3(windowId, 3, 0, 16 + sCard_TextYOffsets[sWonderCardData->card.type], sCard_TextColorTable[sWonderCardData->gfx->textPal3], 0, sWonderCardData->unk_02B1);
        }
        else
        {
            s32 x = 0;
            s32 y = sCard_TextYOffsets[sWonderCardData->card.type] + 16;
            s32 spacing = GetFontAttribute(3, FONTATTR_LETTER_SPACING);
            for (; sp0C < sWonderCardData->unk_0175; sp0C++)
            {
                AddTextPrinterParameterized3(windowId, 3, x, y, sCard_TextColorTable[sWonderCardData->gfx->textPal3], 0, sWonderCardData->unk_02DC[sp0C].unk_01);
                if (sWonderCardData->unk_02DC[sp0C].unk_42[0] != EOS)
                {
                    x += GetStringWidth(3, sWonderCardData->unk_02DC[sp0C].unk_01, spacing);
                    AddTextPrinterParameterized3(windowId, 3, x, y, sCard_TextColorTable[sWonderCardData->gfx->textPal3], 0, sWonderCardData->unk_02DC[sp0C].unk_42);
                    x += GetStringWidth(3, sWonderCardData->unk_02DC[sp0C].unk_42, spacing) + sWonderCardData->unk_02DC[sp0C].unk_00;
                }
            }
        }
        break;
    }
    CopyWindowToVram(windowId, 3);
}

static void CreateCardSprites(void)
{
    u8 i = 0;
    sWonderCardData->monIconSpriteId = SPRITE_NONE;
    if (sWonderCardData->cardMetadata.iconSpecies != SPECIES_NONE)
    {
        sWonderCardData->monIconSpriteId = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(sWonderCardData->cardMetadata.iconSpecies), SpriteCallbackDummy, 220, 20, 0, FALSE);
        gSprites[sWonderCardData->monIconSpriteId].oam.priority = 2;
    }
    if (sWonderCardData->card.maxStamps != 0 && sWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        LoadCompressedSpriteSheetUsingHeap(&sSpriteSheet_IconShadow);
        LoadSpritePalette(&sSpritePalettes_IconShadow[sWonderCardData->gfx->textPal4]);
        for (; i < sWonderCardData->card.maxStamps; i++)
        {
            sWonderCardData->unk_017D[i][0] = SPRITE_NONE;
            sWonderCardData->unk_017D[i][1] = SPRITE_NONE;
            sWonderCardData->unk_017D[i][0] = CreateSprite(&sSpriteTemplate_IconShadow, 216 - 32 * i, 144, 8);
            if (sWonderCardData->cardMetadata.stampData[0][i] != SPECIES_NONE)
                sWonderCardData->unk_017D[i][1] = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(sWonderCardData->cardMetadata.stampData[0][i]), 
                                                                               SpriteCallbackDummy,
                                                                               216 - 32 * i,
                                                                               136, 0, 0);
        }
    }
}

static void DestroyCardSprites(void)
{
    u8 i = 0;
    if (sWonderCardData->monIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->monIconSpriteId]);
    if (sWonderCardData->card.maxStamps != 0 && sWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        for (; i < sWonderCardData->card.maxStamps; i++)
        {
            if (sWonderCardData->unk_017D[i][0] != SPRITE_NONE)
                DestroySprite(&gSprites[sWonderCardData->unk_017D[i][0]]);
            if (sWonderCardData->unk_017D[i][1] != SPRITE_NONE)
                FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->unk_017D[i][1]]);
        }
        FreeSpriteTilesByTag(TAG_ICON_SHADOW);
        FreeSpritePaletteByTag(TAG_ICON_SHADOW);
    }
}

//======================
//    Wonder News
//======================

enum {
    NEWS_WIN_0,
    NEWS_WIN_1,
    NEWS_WIN_COUNT
};

#define TAG_ARROWS 0x1000

struct WonderNewsData
{
    /*0000*/ struct WonderNews news;
    /*01bc*/ const struct WonderGraphics * gfx;
    /*01c0*/ u8 arrowsRemoved:1;
             u8 enterExitState:7;
    /*01c1*/ u8 arrowTaskId;
    /*01c2*/ bool8 scrolling:1;
             u8 scrollIncrement:7;
    /*01c3*/ bool8 scrollingDown:1;
             u8 scrollTotal:7;
    /*01c4*/ u16 scrollEnd;
    /*01c6*/ u16 scrollOffset;
    /*01c8*/ u16 windowIds[NEWS_WIN_COUNT];
    /*01cc*/ u8 filler_01CC[2];
    /*01ce*/ u8 unk_01CE[WONDER_NEWS_TEXT_LENGTH + 1];
    /*01f7*/ u8 unk_01F7[10][WONDER_NEWS_TEXT_LENGTH + 1];
    /*0394*/ struct ScrollArrowsTemplate arrowsTemplate;
    /*03a4*/ u8 buffer_03A4[0x1000];
};

EWRAM_DATA static struct WonderNewsData * sWonderNewsData = NULL;

static void BufferNewsText(void);
static void DrawNewsWindows(void);
static void UpdateNewsScroll(void);

static const u8 sNews_TextColorTable[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_DARK_GRAY}
};

static const struct WindowTemplate sNews_WindowTemplates[] = {
    [NEWS_WIN_0] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28,
        .height = 3,
        .paletteNum = 2,
        .baseBlock = 0x2AC
    },
    [NEWS_WIN_1] = {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 3,
        .width = 28,
        .height = 20,
        .paletteNum = 2,
        .baseBlock = 0x07C
    }
};

static const struct ScrollArrowsTemplate sNews_ArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 232,
    .firstY = 24,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 232,
    .secondY = 152,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 2,
    .tileTag = TAG_ARROWS,
    .palTag = TAG_ARROWS,
    .palNum = 0
};

static const u16 sWonderNewsPal1[]     = INCBIN_U16("graphics/wonder_news/bg1.gbapal");
static const u16 sWonderNewsPal7[]     = INCBIN_U16("graphics/wonder_news/bg7.gbapal");
static const u16 sWonderNewsPal8[]     = INCBIN_U16("graphics/wonder_news/bg8.gbapal");
static const u32 sWonderNewsGfx1[]     = INCBIN_U32("graphics/wonder_news/bg1.4bpp.lz");
static const u32 sWonderNewsTilemap1[] = INCBIN_U32("graphics/wonder_news/bg1.bin.lz");
static const u32 sWonderNewsGfx2[]     = INCBIN_U32("graphics/wonder_news/bg2.4bpp.lz");
static const u32 sWonderNewsTilemap2[] = INCBIN_U32("graphics/wonder_news/bg2.bin.lz");
static const u32 sWonderNewsGfx3[]     = INCBIN_U32("graphics/wonder_news/bg3.4bpp.lz");
static const u32 sWonderNewsTilemap3[] = INCBIN_U32("graphics/wonder_news/bg3.bin.lz");
static const u32 sWonderNewsGfx7[]     = INCBIN_U32("graphics/wonder_news/bg7.4bpp.lz");
static const u32 sWonderNewsTilemap7[] = INCBIN_U32("graphics/wonder_news/bg7.bin.lz");
static const u32 sWonderNewsGfx8[]     = INCBIN_U32("graphics/wonder_news/bg8.4bpp.lz");
static const u32 sWonderNewsTilemap8[] = INCBIN_U32("graphics/wonder_news/bg8.bin.lz");

static const struct WonderGraphics sNewsGraphics[NUM_WONDER_BGS] = {
    {1, 0, 0, 0, sWonderNewsGfx1, sWonderNewsTilemap1, sWonderNewsPal1},
    {1, 0, 0, 0, sWonderNewsGfx2, sWonderNewsTilemap2, sWonderCardBgPal2},
    {1, 0, 0, 0, sWonderNewsGfx3, sWonderNewsTilemap3, sWonderCardBgPal3},
    {1, 0, 0, 0, sWonderNewsGfx3, sWonderNewsTilemap3, sWonderCardBgPal4},
    {1, 0, 0, 0, sWonderNewsGfx3, sWonderNewsTilemap3, sWonderCardBgPal5},
    {1, 0, 0, 0, sWonderNewsGfx3, sWonderNewsTilemap3, sWonderCardBgPal6},
    {1, 0, 0, 0, sWonderNewsGfx7, sWonderNewsTilemap7, sWonderNewsPal7},
    {1, 0, 0, 0, sWonderNewsGfx8, sWonderNewsTilemap8, sWonderNewsPal8}
};

bool32 WonderNews_Init(const struct WonderNews * news)
{
    if (news == NULL)
        return FALSE;
    sWonderNewsData = AllocZeroed(sizeof(*sWonderNewsData));
    if (sWonderNewsData == NULL)
        return FALSE;
    sWonderNewsData->news = *news;
    if (sWonderNewsData->news.bgType >= ARRAY_COUNT(sNewsGraphics))
        sWonderNewsData->news.bgType = 0;
    sWonderNewsData->gfx = &sNewsGraphics[sWonderNewsData->news.bgType];
    sWonderNewsData->arrowTaskId = TASK_NONE;
    return TRUE;
}

void WonderNews_Destroy(void)
{
    if (sWonderNewsData != NULL)
    {
        *sWonderNewsData = (struct WonderNewsData){};
        Free(sWonderNewsData);
        sWonderNewsData = NULL;
    }
}

s32 WonderNews_Enter(void)
{
    if (sWonderNewsData == NULL)
        return -1;

    switch (sWonderNewsData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        ChangeBgY(0, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(26, 152));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(3, 0x000, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        DecompressAndCopyTileDataToVram(3, sWonderNewsData->gfx->tiles, 0, 8, 0);
        sWonderNewsData->windowIds[NEWS_WIN_0] = AddWindow(&sNews_WindowTemplates[NEWS_WIN_0]);
        sWonderNewsData->windowIds[NEWS_WIN_1] = AddWindow(&sNews_WindowTemplates[NEWS_WIN_1]);
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible())
            return 0;
        LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
        gPaletteFade.bufferTransferDisabled = TRUE;
        LoadPalette(sWonderNewsData->gfx->pal, 0x10, 0x20);
        LZ77UnCompWram(sWonderNewsData->gfx->map, sWonderNewsData->buffer_03A4);
        CopyRectToBgTilemapBufferRect(1, sWonderNewsData->buffer_03A4, 0, 0, 30, 3, 0, 0, 30, 3, 1, 8, 0);
        CopyRectToBgTilemapBufferRect(3, sWonderNewsData->buffer_03A4, 0, 3, 30, 23, 0, 3, 30, 23, 1, 8, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(3);
        break;
    case 4:
        BufferNewsText();
        break;
    case 5:
        DrawNewsWindows();
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(2);
        break;
    case 6:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gPaletteFade.bufferTransferDisabled = FALSE;
        sWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair(&sWonderNewsData->arrowsTemplate, &sWonderNewsData->scrollOffset);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        UpdatePaletteFade();
        break;
    default:
        if (UpdatePaletteFade())
            return 0;
        sWonderNewsData->enterExitState = 0;
        return 1;
    }

    ++sWonderNewsData->enterExitState;
    return 0;
}

s32 WonderNews_Exit(bool32 flag)
{
    if (sWonderNewsData == NULL)
        return -1;
    switch (sWonderNewsData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        ChangeBgY(2, 0, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 24);
        FillBgTilemapBufferRect_Palette0(3, 0x000, 0, 0, 30, 24);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 3:
        HideBg(1);
        HideBg(2);
        RemoveWindow(sWonderNewsData->windowIds[NEWS_WIN_1]);
        RemoveWindow(sWonderNewsData->windowIds[NEWS_WIN_0]);
        break;
    case 4:
        ChangeBgY(2, 0, 0);
        ChangeBgY(3, 0, 0);
        if (sWonderNewsData->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sWonderNewsData->arrowTaskId);
            sWonderNewsData->arrowTaskId = TASK_NONE;
        }
        break;
    case 5:
        PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader, flag);
        MG_DrawCheckerboardPattern(3);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(3);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        break;
    default:
        if (UpdatePaletteFade())
            return 0;
        sWonderNewsData->enterExitState = 0;
        return 1;
    }
    ++sWonderNewsData->enterExitState;
    return 0;
}

void WonderNews_RemoveScrollIndicatorArrowPair(void)
{
    if (!sWonderNewsData->arrowsRemoved && sWonderNewsData->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sWonderNewsData->arrowTaskId);
        sWonderNewsData->arrowTaskId = TASK_NONE;
        sWonderNewsData->arrowsRemoved = TRUE;
    }
}


void WonderNews_AddScrollIndicatorArrowPair(void)
{
    if (sWonderNewsData->arrowsRemoved)
    {
        sWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair(&sWonderNewsData->arrowsTemplate, &sWonderNewsData->scrollOffset);
        sWonderNewsData->arrowsRemoved = FALSE;
    }
}

u32 WonderNews_GetInput(u16 input)
{
    if (sWonderNewsData->scrolling)
    {
        UpdateNewsScroll();
        return NEWS_INPUT_NONE;
    }
    switch (input)
    {
    case A_BUTTON:
        return NEWS_INPUT_A;
    case B_BUTTON:
        return NEWS_INPUT_B;
    case DPAD_UP:
        if (sWonderNewsData->scrollOffset == 0)
            return NEWS_INPUT_NONE;
        if (sWonderNewsData->arrowsRemoved)
            return NEWS_INPUT_NONE;
        sWonderNewsData->scrollingDown = FALSE;
        break;
    case DPAD_DOWN:
        if (sWonderNewsData->scrollOffset == sWonderNewsData->scrollEnd)
            return NEWS_INPUT_NONE;
        if (sWonderNewsData->arrowsRemoved)
            return NEWS_INPUT_NONE;
        sWonderNewsData->scrollingDown = TRUE;
        break;
    default:
        return NEWS_INPUT_NONE;
    }

    // Init scroll
    sWonderNewsData->scrolling = TRUE;
    sWonderNewsData->scrollIncrement = 2;
    sWonderNewsData->scrollTotal = 0;
    if (!sWonderNewsData->scrollingDown)
        return NEWS_INPUT_SCROLL_UP;
    else
        return NEWS_INPUT_SCROLL_DOWN;
}

static void BufferNewsText(void)
{
    u8 i = 0;
    memcpy(sWonderNewsData->unk_01CE, sWonderNewsData->news.unk_04, WONDER_NEWS_TEXT_LENGTH);
    sWonderNewsData->unk_01CE[WONDER_NEWS_TEXT_LENGTH] = EOS;
    for (; i < 10; ++i)
    {
        memcpy(sWonderNewsData->unk_01F7[i], sWonderNewsData->news.unk_2C[i], WONDER_NEWS_TEXT_LENGTH);
        sWonderNewsData->unk_01F7[i][WONDER_NEWS_TEXT_LENGTH] = EOS;
        if (i > 7 && sWonderNewsData->unk_01F7[i][0] != EOS)
            ++sWonderNewsData->scrollEnd;
    }
    sWonderNewsData->arrowsTemplate = sNews_ArrowsTemplate;
    sWonderNewsData->arrowsTemplate.fullyDownThreshold = sWonderNewsData->scrollEnd;
}

static void DrawNewsWindows(void)
{
    u8 i = 0;
    s32 x;
    PutWindowTilemap(sWonderNewsData->windowIds[NEWS_WIN_0]);
    PutWindowTilemap(sWonderNewsData->windowIds[NEWS_WIN_1]);
    FillWindowPixelBuffer(sWonderNewsData->windowIds[NEWS_WIN_0], 0);
    FillWindowPixelBuffer(sWonderNewsData->windowIds[NEWS_WIN_1], 0);
    x = (224 - GetStringWidth(3, sWonderNewsData->unk_01CE, GetFontAttribute(3, FONTATTR_LETTER_SPACING))) / 2;
    if (x < 0)
        x = 0;
    AddTextPrinterParameterized3(sWonderNewsData->windowIds[NEWS_WIN_0], 3, x, 6, sNews_TextColorTable[sWonderNewsData->gfx->textPal1], 0, sWonderNewsData->unk_01CE);
    for (; i < 10; ++i)
        AddTextPrinterParameterized3(sWonderNewsData->windowIds[NEWS_WIN_1], 3, 0, 16 * i + 2, sNews_TextColorTable[sWonderNewsData->gfx->textPal2], 0, sWonderNewsData->unk_01F7[i]);
    CopyWindowToVram(sWonderNewsData->windowIds[NEWS_WIN_0], 3);
    CopyWindowToVram(sWonderNewsData->windowIds[NEWS_WIN_1], 3);
}

static void UpdateNewsScroll(void)
{
    u16 bgMove = sWonderNewsData->scrollIncrement;
    bgMove *= 256;
    if (sWonderNewsData->scrollingDown)
    {
        ChangeBgY(2, bgMove, BG_COORD_ADD);
        ChangeBgY(3, bgMove, BG_COORD_ADD);
    }
    else
    {
        ChangeBgY(2, bgMove, BG_COORD_SUB);
        ChangeBgY(3, bgMove, BG_COORD_SUB);
    }
    sWonderNewsData->scrollTotal += sWonderNewsData->scrollIncrement;
    if (sWonderNewsData->scrollTotal > 15)
    {
        if (sWonderNewsData->scrollingDown)
            ++sWonderNewsData->scrollOffset;
        else
            --sWonderNewsData->scrollOffset;
        sWonderNewsData->scrolling = FALSE;
        sWonderNewsData->scrollTotal = 0;
    }
}

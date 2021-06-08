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
#include "constants/rgb.h"

struct UnkStruct_8467FB8
{
    u8 textPal1:4;
    u8 textPal2:4;
    u8 textPal3:4;
    u8 textPal4:4;
    const u32 * tiles;
    const u32 * map;
    const u16 * pal;
};

struct UnkStruct_203F3C8_02DC
{
    u8 unk_00;
    u8 unk_01[41];
    u8 unk_42[4];
};

struct UnkStruct_203F3C8
{
    /*0000*/ struct WonderCard unk_0000;
    /*014c*/ struct MEventBuffer_3430_Sub unk_014C;
    /*0170*/ const struct UnkStruct_8467FB8 * unk_0170;
    /*0174*/ u8 unk_0174;
    /*0175*/ u8 unk_0175;
    /*0176*/ u16 unk_0176[3];
    /*017C*/ u8 unk_017C;
    /*017D*/ u8 unk_017D[7][2];
    /*018B*/ u8 unk_018B[41];
    /*01B4*/ u8 unk_01B4[41];
    /*01DD*/ u8 unk_01DD[7];
    /*01E4*/ u8 unk_01E4[4][41];
    /*0288*/ u8 unk_0288[41];
    /*02B1*/ u8 unk_02B1[41];
    /*02DC*/ struct UnkStruct_203F3C8_02DC unk_02DC[8];
    /*045C*/ u8 buffer_045C[0x1000];
};

EWRAM_DATA struct UnkStruct_203F3C8 * sWonderCardData = NULL;

void sub_801BEF8(void);
void sub_801C178(u8 whichWindow);
void sub_801C4C0(void);
void sub_801C61C(void);

extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;

const u8 sTextColorTable[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY}
};
const u8 ALIGNED(4) gUnknown_082F0E18[3] = {7, 4, 7};
const struct WindowTemplate gUnknown_082F0E1C[] = {
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 25,
        .height = 4,
        .paletteNum = 2,
        .baseBlock = 0x029c
    }, {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 28,
        .height = 8,
        .paletteNum = 2,
        .baseBlock = 0x01bc
    }, {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 28,
        .height = 5,
        .paletteNum = 2,
        .baseBlock = 0x0130
    }
};

const u16 gWonderCardBgPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_1.gbapal");
const u16 gWonderCardBgPal2[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_2.gbapal");
const u16 gWonderCardBgPal3[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_3.gbapal");
const u16 gWonderCardBgPal4[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_4.gbapal");
const u16 gWonderCardBgPal5[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_5.gbapal");
const u16 gWonderCardBgPal6[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_6.gbapal");
const u16 gWonderCardBgPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_7.gbapal");
const u16 gWonderCardBgPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_8.gbapal");
const u32 gWonderCardBgGfx1[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_1.4bpp.lz");
const u32 gWonderCardBgTilemap1[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_1.bin.lz");
const u32 gWonderCardBgGfx2[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_2.4bpp.lz");
const u32 gWonderCardBgTilemap2[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_2.bin.lz");
const u32 gWonderCardBgGfx3[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_3.4bpp.lz");
const u32 gWonderCardBgTilemap3[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_3.bin.lz");
const u32 gWonderCardBgGfx7[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_7.4bpp.lz");
const u32 gWonderCardBgTilemap7[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_7.bin.lz");
const u32 gWonderCardBgGfx8[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_8.4bpp.lz");
const u32 gWonderCardBgTilemap8[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_8.bin.lz");
const u16 gWonderCardShadowPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_1.gbapal");
const u16 gWonderCardShadowPal2[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_2.gbapal");
const u16 gWonderCardShadowPal3[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_3.gbapal");
const u16 gWonderCardShadowPal4[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_4.gbapal");
const u16 gWonderCardShadowPal5[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_5.gbapal");
const u16 gWonderCardShadowPal6[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_6.gbapal");
const u16 gWonderCardShadowPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_7.gbapal");
const u16 gWonderCardShadowPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_8.gbapal");
const u32 gWonderCardShadowGfx[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_shadow.4bpp.lz");

const struct CompressedSpriteSheet gUnknown_082F1D00 = {
    gWonderCardShadowGfx, 0x100, 0x8000
};
const struct SpritePalette gUnknown_082F1D08[] = {
    {gWonderCardShadowPal1, 0x8000},
    {gWonderCardShadowPal2, 0x8000},
    {gWonderCardShadowPal3, 0x8000},
    {gWonderCardShadowPal4, 0x8000},
    {gWonderCardShadowPal5, 0x8000},
    {gWonderCardShadowPal6, 0x8000},
    {gWonderCardShadowPal7, 0x8000},
    {gWonderCardShadowPal8, 0x8000}
};
const struct SpriteTemplate gUnknown_082F1D48 = {
    0x8000, 0x8000, &gOamData_AffineOff_ObjNormal_32x16, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
};
const struct UnkStruct_8467FB8 gUnknown_082F1D60[8] = {
    {1, 0, 0, 0, gWonderCardBgGfx1, gWonderCardBgTilemap1, gWonderCardBgPal1},
    {1, 0, 0, 1, gWonderCardBgGfx2, gWonderCardBgTilemap2, gWonderCardBgPal2},
    {1, 0, 0, 2, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal3},
    {1, 0, 0, 3, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal4},
    {1, 0, 0, 4, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal5},
    {1, 0, 0, 5, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal6},
    {1, 0, 0, 6, gWonderCardBgGfx7, gWonderCardBgTilemap7, gWonderCardBgPal7},
    {1, 0, 0, 7, gWonderCardBgGfx8, gWonderCardBgTilemap8, gWonderCardBgPal8}
};

bool32 InitWonderCardResources(struct WonderCard * r5, struct MEventBuffer_3430_Sub * r6)
{
    if (r5 == NULL || r6 == NULL)
        return FALSE;
    sWonderCardData = AllocZeroed(sizeof(struct UnkStruct_203F3C8));
    if (sWonderCardData == NULL)
        return FALSE;
    sWonderCardData->unk_0000 = *r5;
    sWonderCardData->unk_014C = *r6;
    if (sWonderCardData->unk_0000.unk_08_2 >= ARRAY_COUNT(gUnknown_082F1D60))
        sWonderCardData->unk_0000.unk_08_2 = 0;
    if (sWonderCardData->unk_0000.unk_08_0 >= ARRAY_COUNT(gUnknown_082F0E18))
        sWonderCardData->unk_0000.unk_08_0 = 0;
    if (sWonderCardData->unk_0000.unk_09 > ARRAY_COUNT(sWonderCardData->unk_017D))
        sWonderCardData->unk_0000.unk_09 = 0;
    sWonderCardData->unk_0170 = &gUnknown_082F1D60[sWonderCardData->unk_0000.unk_08_2];
    return TRUE;
}

void DestroyWonderCardResources(void)
{
    if (sWonderCardData != NULL)
    {
        *sWonderCardData = (struct UnkStruct_203F3C8){};
        Free(sWonderCardData);
        sWonderCardData = NULL;
    }
}

s32 FadeToWonderCardMenu(void)
{
    if (sWonderCardData == NULL)
        return -1;
    switch(sWonderCardData->unk_0174)
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
            DecompressAndCopyTileDataToVram(2, sWonderCardData->unk_0170->tiles, 0, 0x008, 0);
            sWonderCardData->unk_0176[0] = AddWindow(&gUnknown_082F0E1C[0]);
            sWonderCardData->unk_0176[1] = AddWindow(&gUnknown_082F0E1C[1]);
            sWonderCardData->unk_0176[2] = AddWindow(&gUnknown_082F0E1C[2]);
            break;
        case 3:
            if (FreeTempTileDataBuffersIfPossible())
                return 0;
            LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
            gPaletteFade.bufferTransferDisabled = TRUE;
            LoadPalette(sWonderCardData->unk_0170->pal, 0x10, 0x20);
            LZ77UnCompWram(sWonderCardData->unk_0170->map, sWonderCardData->buffer_045C);
            CopyRectToBgTilemapBufferRect(2, sWonderCardData->buffer_045C, 0, 0, 30, 20, 0, 0, 30, 20, 1, 0x008, 0);
            CopyBgTilemapBufferToVram(2);
            break;
        case 4:
            sub_801BEF8();
            break;
        case 5:
            sub_801C178(0);
            sub_801C178(1);
            sub_801C178(2);
            CopyBgTilemapBufferToVram(1);
            break;
        case 6:
            LoadMonIconPalettes();
            break;
        case 7:
            ShowBg(1);
            ShowBg(2);
            gPaletteFade.bufferTransferDisabled = FALSE;
            sub_801C4C0();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            UpdatePaletteFade();
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderCardData->unk_0174 = 0;
            return 1;
    }
    ++sWonderCardData->unk_0174;
    return 0;
}

s32 FadeOutFromWonderCard(bool32 flag)
{
    if (sWonderCardData == NULL)
        return -1;
    switch (sWonderCardData->unk_0174)
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
            RemoveWindow(sWonderCardData->unk_0176[2]);
            RemoveWindow(sWonderCardData->unk_0176[1]);
            RemoveWindow(sWonderCardData->unk_0176[0]);
            break;
        case 4:
            sub_801C61C();
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
            sWonderCardData->unk_0174 = 0;
            return 1;
    }
    ++sWonderCardData->unk_0174;
    return 0;
}

void sub_801BEF8(void)
{
    u16 i = 0;
    u16 r6;
    u16 sp0[3] = {0, 0, 0};

    memcpy(sWonderCardData->unk_018B, sWonderCardData->unk_0000.unk_0A, 40);
    sWonderCardData->unk_018B[40] = EOS;
    memcpy(sWonderCardData->unk_01B4, sWonderCardData->unk_0000.unk_32, 40);
    sWonderCardData->unk_01B4[40] = EOS;
    if (sWonderCardData->unk_0000.unk_04 > 999999)
        sWonderCardData->unk_0000.unk_04 = 999999;
    ConvertIntToDecimalStringN(sWonderCardData->unk_01DD, sWonderCardData->unk_0000.unk_04, STR_CONV_MODE_LEFT_ALIGN, 6);
    for (i = 0; i < 4; i++)
    {
        memcpy(sWonderCardData->unk_01E4[i], sWonderCardData->unk_0000.unk_5A[i], 40);
        sWonderCardData->unk_01E4[i][40] = EOS;
    }
    memcpy(sWonderCardData->unk_0288, sWonderCardData->unk_0000.unk_FA, 40);
    sWonderCardData->unk_0288[40] = EOS;
    switch (sWonderCardData->unk_0000.unk_08_0)
    {
        case 0:
            memcpy(sWonderCardData->unk_02B1, sWonderCardData->unk_0000.unk_122, 40);
            sWonderCardData->unk_02B1[40] = EOS;
            break;
        case 1:
            sWonderCardData->unk_02B1[00] = EOS;
            break;
        case 2:
            sWonderCardData->unk_02B1[00] = EOS;
            sp0[0] = sWonderCardData->unk_014C.unk_00 < 999 ? sWonderCardData->unk_014C.unk_00 : 999;
            sp0[1] = sWonderCardData->unk_014C.unk_02 < 999 ? sWonderCardData->unk_014C.unk_02 : 999;
            sp0[2] = sWonderCardData->unk_014C.unk_04 < 999 ? sWonderCardData->unk_014C.unk_04 : 999;
            for (i = 0; i < 8; i++)
            {
                memset(sWonderCardData->unk_02DC[i].unk_42, EOS, 4);
                memset(sWonderCardData->unk_02DC[i].unk_01, EOS, 41);
            }
            for (i = 0, r6 = 0; i < 40; i++)
            {
                if (sWonderCardData->unk_0000.unk_122[i] != 0xF7)
                {
                    sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_01[r6] = sWonderCardData->unk_0000.unk_122[i];
                    r6++;
                }
                else
                {
                    u8 r3 = sWonderCardData->unk_0000.unk_122[i + 1];
                    if (r3 > 2)
                    {
                        i += 2;
                    }
                    else
                    {
                        ConvertIntToDecimalStringN(sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_42, sp0[r3], STR_CONV_MODE_LEADING_ZEROS, 3);
                        sWonderCardData->unk_02DC[sWonderCardData->unk_0175].unk_00 = sWonderCardData->unk_0000.unk_122[i + 2];
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

void sub_801C178(u8 whichWindow)
{
    s8 sp0C = 0;
    s32 windowId = sWonderCardData->unk_0176[whichWindow];
    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, 0);
    switch (whichWindow)
    {
        case 0:
        {
            s32 x;
            AddTextPrinterParameterized3(windowId, 3, 0, 1, sTextColorTable[sWonderCardData->unk_0170->textPal1], 0, sWonderCardData->unk_018B);
            x = 160 - GetStringWidth(3, sWonderCardData->unk_01B4, GetFontAttribute(3, 2));
            if (x < 0)
                x = 0;
            AddTextPrinterParameterized3(windowId, 3, x, 17, sTextColorTable[sWonderCardData->unk_0170->textPal1], 0, sWonderCardData->unk_01B4);
            if (sWonderCardData->unk_0000.unk_04 != 0)
            {
                AddTextPrinterParameterized3(windowId, 1, 166, 17, sTextColorTable[sWonderCardData->unk_0170->textPal1], 0, sWonderCardData->unk_01DD);
            }
            break;
        }
        case 1:
            for (; sp0C < 4; sp0C++)
            {
                AddTextPrinterParameterized3(windowId, 3, 0, 16 * sp0C + 2, sTextColorTable[sWonderCardData->unk_0170->textPal2], 0, sWonderCardData->unk_01E4[sp0C]);
            }
            break;
        case 2:
            AddTextPrinterParameterized3(windowId, 3, 0, gUnknown_082F0E18[sWonderCardData->unk_0000.unk_08_0], sTextColorTable[sWonderCardData->unk_0170->textPal3], 0, sWonderCardData->unk_0288);
            if (sWonderCardData->unk_0000.unk_08_0 != 2)
            {
                AddTextPrinterParameterized3(windowId, 3, 0, 16 + gUnknown_082F0E18[sWonderCardData->unk_0000.unk_08_0], sTextColorTable[sWonderCardData->unk_0170->textPal3], 0, sWonderCardData->unk_02B1);
            }
            else
            {
                s32 x = 0;
                s32 y = gUnknown_082F0E18[sWonderCardData->unk_0000.unk_08_0] + 16;
                s32 spacing = GetFontAttribute(3, 2);
                for (; sp0C < sWonderCardData->unk_0175; sp0C++)
                {
                    AddTextPrinterParameterized3(windowId, 3, x, y, sTextColorTable[sWonderCardData->unk_0170->textPal3], 0, sWonderCardData->unk_02DC[sp0C].unk_01);
                    if (sWonderCardData->unk_02DC[sp0C].unk_42[0] != EOS)
                    {
                        x += GetStringWidth(3, sWonderCardData->unk_02DC[sp0C].unk_01, spacing);
                        AddTextPrinterParameterized3(windowId, 3, x, y, sTextColorTable[sWonderCardData->unk_0170->textPal3], 0, sWonderCardData->unk_02DC[sp0C].unk_42);
                        x += GetStringWidth(3, sWonderCardData->unk_02DC[sp0C].unk_42, spacing) + sWonderCardData->unk_02DC[sp0C].unk_00;
                    }
                }
            }
            break;
    }
    CopyWindowToVram(windowId, 3);
}

void sub_801C4C0(void)
{
    u8 r7 = 0;
    sWonderCardData->unk_017C = 0xFF;
    if (sWonderCardData->unk_014C.unk_06 != SPECIES_NONE)
    {
        sWonderCardData->unk_017C = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(sWonderCardData->unk_014C.unk_06), SpriteCallbackDummy, 0xDC, 0x14, 0);
        gSprites[sWonderCardData->unk_017C].oam.priority = 2;
    }
    if (sWonderCardData->unk_0000.unk_09 != 0 && sWonderCardData->unk_0000.unk_08_0 == 1)
    {
        LoadCompressedSpriteSheetUsingHeap(&gUnknown_082F1D00);
        LoadSpritePalette(&gUnknown_082F1D08[sWonderCardData->unk_0170->textPal4]);
        for (; r7 < sWonderCardData->unk_0000.unk_09; r7++)
        {
            sWonderCardData->unk_017D[r7][0] = 0xFF;
            sWonderCardData->unk_017D[r7][1] = 0xFF;
            sWonderCardData->unk_017D[r7][0] = CreateSprite(&gUnknown_082F1D48, 0xd8 - 32 * r7, 0x90, 8);
            if (sWonderCardData->unk_014C.unk_08[0][r7] != 0)
            {
                sWonderCardData->unk_017D[r7][1] = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(sWonderCardData->unk_014C.unk_08[0][r7]), SpriteCallbackDummy, 0xd8 - 32 * r7, 0x88, 0);
            }
        }
    }
}

void sub_801C61C(void)
{
    u8 r6 = 0;
    if (sWonderCardData->unk_017C != 0xFF)
        FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->unk_017C]);
    if (sWonderCardData->unk_0000.unk_09 != 0 && sWonderCardData->unk_0000.unk_08_0 == 1)
    {
        for (; r6 < sWonderCardData->unk_0000.unk_09; r6++)
        {
            if (sWonderCardData->unk_017D[r6][0] != 0xFF)
            {
                DestroySprite(&gSprites[sWonderCardData->unk_017D[r6][0]]);
            }
            if (sWonderCardData->unk_017D[r6][1] != 0xFF)
            {
                FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->unk_017D[r6][1]]);
            }
        }
        FreeSpriteTilesByTag(0x8000);
        FreeSpritePaletteByTag(0x8000);
    }
}

struct UnkStruct_203F3CC
{
    /*0000*/ struct WonderNews unk_0000;
    /*01bc*/ const struct UnkStruct_8467FB8 * unk_01BC;
    /*01c0*/ u8 unk_01C0_0:1;
             u8 unk_01C0_1:7;
    /*01c1*/ u8 unk_01C1;
    /*01c2*/ u8 unk_01C2_0:1;
             u8 unk_01C2_1:7;
    /*01c3*/ u8 unk_01C3_0:1;
             u8 unk_01C3_1:7;
    /*01c4*/ u16 unk_01C4;
    /*01c6*/ u16 unk_01C6;
    /*01c8*/ u16 unk_01C8[2];
    /*01cc*/ u8 filler_01CC[2];
    /*01ce*/ u8 unk_01CE[41];
    /*01f7*/ u8 unk_01F7[10][41];
    /*0394*/ struct ScrollArrowsTemplate unk_0394;
    /*03a4*/ u8 buffer_03A4[0x1000];
};

EWRAM_DATA struct UnkStruct_203F3CC * sWonderNewsData = NULL;

void sub_801CDCC(void);
void sub_801CE7C(void);
void sub_801CFA4(void);

const u8 gUnknown_082F1DE0[][3] = {
    {0, 2, 3},
    {0, 1, 2}
};
const struct WindowTemplate gUnknown_082F1DE8[] = {
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28,
        .height = 3,
        .paletteNum = 2,
        .baseBlock = 0x2AC
    }, {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 3,
        .width = 28,
        .height = 20,
        .paletteNum = 2,
        .baseBlock = 0x07C
    }
};
const struct ScrollArrowsTemplate gUnknown_082F1DF8 = {
    0x02, 0xe8, 0x18, 0x03, 0xe8, 0x98,
    0x0000, 0x0002, 0x1000, 0x1000, 0x0
};
const u16 gWonderNewsPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_1.gbapal");
const u16 gWonderNewsPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_7.gbapal");
const u16 gWonderNewsPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_8.gbapal");
const u32 gWonderNewsGfx1[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_1.4bpp.lz");
const u32 gWonderNewsTilemap1[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_1.bin.lz");
const u32 gWonderNewsGfx2[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_2.4bpp.lz");
const u32 gWonderNewsTilemap2[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_2.bin.lz");
const u32 gWonderNewsGfx3[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_3.4bpp.lz");
const u32 gWonderNewsTilemap3[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_3.bin.lz");
const u32 gWonderNewsGfx7[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_7.4bpp.lz");
const u32 gWonderNewsTilemap7[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_7.bin.lz");
const u32 gWonderNewsGfx8[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_8.4bpp.lz");
const u32 gWonderNewsTilemap8[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_8.bin.lz");

const struct UnkStruct_8467FB8 gUnknown_082F24C8[] = {
    {1, 0, 0, 0, gWonderNewsGfx1, gWonderNewsTilemap1, gWonderNewsPal1},
    {1, 0, 0, 0, gWonderNewsGfx2, gWonderNewsTilemap2, gWonderCardBgPal2},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal3},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal4},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal5},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal6},
    {1, 0, 0, 0, gWonderNewsGfx7, gWonderNewsTilemap7, gWonderNewsPal7},
    {1, 0, 0, 0, gWonderNewsGfx8, gWonderNewsTilemap8, gWonderNewsPal8}
};

bool32 InitWonderNewsResources(const struct WonderNews * a0)
{
    if (a0 == NULL)
        return FALSE;
    sWonderNewsData = AllocZeroed(sizeof(struct UnkStruct_203F3CC));
    if (sWonderNewsData == NULL)
        return FALSE;
    sWonderNewsData->unk_0000 = *a0;
    if (sWonderNewsData->unk_0000.unk_03 >= ARRAY_COUNT(gUnknown_082F24C8))
        sWonderNewsData->unk_0000.unk_03 = 0;
    sWonderNewsData->unk_01BC = &gUnknown_082F24C8[sWonderNewsData->unk_0000.unk_03];
    sWonderNewsData->unk_01C1 = 0xFF;
    return TRUE;
}

void DestroyWonderNewsResources(void)
{
    if (sWonderNewsData != NULL)
    {
        *sWonderNewsData = (struct UnkStruct_203F3CC){};
        Free(sWonderNewsData);
        sWonderNewsData = NULL;
    }
}

s32 FadeToWonderNewsMenu(void)
{
    if (sWonderNewsData == NULL)
        return -1;

    switch (sWonderNewsData->unk_01C0_1)
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
            DecompressAndCopyTileDataToVram(3, sWonderNewsData->unk_01BC->tiles, 0, 8, 0);
            sWonderNewsData->unk_01C8[0] = AddWindow(&gUnknown_082F1DE8[0]);
            sWonderNewsData->unk_01C8[1] = AddWindow(&gUnknown_082F1DE8[1]);
            break;
        case 3:
            if (FreeTempTileDataBuffersIfPossible())
                return 0;
            LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
            gPaletteFade.bufferTransferDisabled = TRUE;
            LoadPalette(sWonderNewsData->unk_01BC->pal, 0x10, 0x20);
            LZ77UnCompWram(sWonderNewsData->unk_01BC->map, sWonderNewsData->buffer_03A4);
            CopyRectToBgTilemapBufferRect(1, sWonderNewsData->buffer_03A4, 0, 0, 30, 3, 0, 0, 30, 3, 1, 8, 0);
            CopyRectToBgTilemapBufferRect(3, sWonderNewsData->buffer_03A4, 0, 3, 30, 23, 0, 3, 30, 23, 1, 8, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(3);
            break;
        case 4:
            sub_801CDCC();
            break;
        case 5:
            sub_801CE7C();
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(2);
            break;
        case 6:
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gPaletteFade.bufferTransferDisabled = FALSE;
            sWonderNewsData->unk_01C1 = AddScrollIndicatorArrowPair(&sWonderNewsData->unk_0394, &sWonderNewsData->unk_01C6);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            UpdatePaletteFade();
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderNewsData->unk_01C0_1 = 0;
            return 1;
    }

    ++sWonderNewsData->unk_01C0_1;
    return 0;
}

s32 FadeOutFromWonderNews(bool32 flag)
{
    if (sWonderNewsData == NULL)
        return -1;
    switch (sWonderNewsData->unk_01C0_1)
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
            RemoveWindow(sWonderNewsData->unk_01C8[1]);
            RemoveWindow(sWonderNewsData->unk_01C8[0]);
            break;
        case 4:
            ChangeBgY(2, 0, 0);
            ChangeBgY(3, 0, 0);
            if (sWonderNewsData->unk_01C1 != 0xFF)
            {
                RemoveScrollIndicatorArrowPair(sWonderNewsData->unk_01C1);
                sWonderNewsData->unk_01C1 = 0xFF;
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
            sWonderNewsData->unk_01C0_1 = 0;
            return 1;
    }
    ++sWonderNewsData->unk_01C0_1;
    return 0;
}

void MENews_RemoveScrollIndicatorArrowPair(void)
{
    if (!sWonderNewsData->unk_01C0_0 && sWonderNewsData->unk_01C1 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sWonderNewsData->unk_01C1);
        sWonderNewsData->unk_01C1 = 0xFF;
        sWonderNewsData->unk_01C0_0 = TRUE;
    }
}


void MENews_AddScrollIndicatorArrowPair(void)
{
    if (sWonderNewsData->unk_01C0_0)
    {
        sWonderNewsData->unk_01C1 = AddScrollIndicatorArrowPair(&sWonderNewsData->unk_0394, &sWonderNewsData->unk_01C6);
        sWonderNewsData->unk_01C0_0 = FALSE;
    }
}

u32 MENews_GetInput(u16 input)
{
    if (sWonderNewsData->unk_01C2_0)
    {
        sub_801CFA4();
        return 0xFF;
    }
    switch (input)
    {
        case A_BUTTON:
            return 0;
        case B_BUTTON:
            return 1;
        case DPAD_UP:
            if (sWonderNewsData->unk_01C6 == 0)
                return 0xFF;
            if (sWonderNewsData->unk_01C0_0)
                return 0xFF;
            sWonderNewsData->unk_01C3_0 = FALSE;
            break;
        case DPAD_DOWN:
            if (sWonderNewsData->unk_01C6 == sWonderNewsData->unk_01C4)
                return 0xFF;
            if (sWonderNewsData->unk_01C0_0)
                return 0xFF;
            sWonderNewsData->unk_01C3_0 = TRUE;
            break;
        default:
            return 0xFF;
    }
    sWonderNewsData->unk_01C2_0 = TRUE;
    sWonderNewsData->unk_01C2_1 = 2;
    sWonderNewsData->unk_01C3_1 = 0;
    if (sWonderNewsData->unk_01C3_0 == FALSE)
        return 2;
    else
        return 3;
}

void sub_801CDCC(void)
{
    u8 i = 0;
    memcpy(sWonderNewsData->unk_01CE, sWonderNewsData->unk_0000.unk_04, 40);
    sWonderNewsData->unk_01CE[40] = EOS;
    for (; i < 10; ++i)
    {
        memcpy(sWonderNewsData->unk_01F7[i], sWonderNewsData->unk_0000.unk_2C[i], 40);
        sWonderNewsData->unk_01F7[i][40] = EOS;
        if (i > 7 && sWonderNewsData->unk_01F7[i][0] != EOS)
            ++sWonderNewsData->unk_01C4;
    }
    sWonderNewsData->unk_0394 = gUnknown_082F1DF8;
    sWonderNewsData->unk_0394.fullyDownThreshold = sWonderNewsData->unk_01C4;
}

void sub_801CE7C(void)
{
    u8 i = 0;
    s32 x;
    PutWindowTilemap(sWonderNewsData->unk_01C8[0]);
    PutWindowTilemap(sWonderNewsData->unk_01C8[1]);
    FillWindowPixelBuffer(sWonderNewsData->unk_01C8[0], 0);
    FillWindowPixelBuffer(sWonderNewsData->unk_01C8[1], 0);
    x = (0xe0 - GetStringWidth(3, sWonderNewsData->unk_01CE, GetFontAttribute(3, 2))) / 2;
    if (x < 0)
        x = 0;
    AddTextPrinterParameterized3(sWonderNewsData->unk_01C8[0], 3, x, 6, gUnknown_082F1DE0[sWonderNewsData->unk_01BC->textPal1], 0, sWonderNewsData->unk_01CE);
    for (; i < 10; ++i)
    {
        AddTextPrinterParameterized3(sWonderNewsData->unk_01C8[1], 3, 0, 16 * i + 2, gUnknown_082F1DE0[sWonderNewsData->unk_01BC->textPal2], 0, sWonderNewsData->unk_01F7[i]);
    }
    CopyWindowToVram(sWonderNewsData->unk_01C8[0], 3);
    CopyWindowToVram(sWonderNewsData->unk_01C8[1], 3);
}

void sub_801CFA4(void)
{
    u16 r4 = sWonderNewsData->unk_01C2_1;
    r4 <<= 8;
    if (sWonderNewsData->unk_01C3_0)
    {
        ChangeBgY(2, r4, 1);
        ChangeBgY(3, r4, 1);
    }
    else
    {
        ChangeBgY(2, r4, 2);
        ChangeBgY(3, r4, 2);
    }
    sWonderNewsData->unk_01C3_1 += sWonderNewsData->unk_01C2_1;
    if (sWonderNewsData->unk_01C3_1 > 15)
    {
        if (sWonderNewsData->unk_01C3_0)
            ++sWonderNewsData->unk_01C6;
        else
            --sWonderNewsData->unk_01C6;
        sWonderNewsData->unk_01C2_0 = FALSE;
        sWonderNewsData->unk_01C3_1 = 0;
    }
}

#include "global.h"
#include "bg.h"
#include "window.h"
#include "pokenav.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "menu.h"
#include "menu_specialized.h"
#include "mon_markings.h"
#include "palette.h"
#include "pokenav.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"

u32 sub_81CE37C(s32);
u32 sub_81CE2D0(s32);
u32 sub_81CE4D8(s32);
u32 sub_81CE5E4(s32);
u32 sub_81CE6BC(s32);
u32 sub_81CE700(s32);

BSS_DATA u8 gUnknown_030012BC;

const u16 gUnknown_086231E8[] = INCBIN_U16("graphics/pokenav/86231E8.gbapal");
const u16 gUnknown_08623208[] = INCBIN_U16("graphics/pokenav/8623208.gbapal");
const u32 gUnknown_08623228[] = INCBIN_U32("graphics/pokenav/8623228.4bpp.lz");
const u32 gUnknown_0862323C[] = INCBIN_U32("graphics/pokenav/862323C.bin.lz");
const u16 gUnknown_08623338[] = INCBIN_U16("graphics/pokenav/8623338.gbapal");

const struct BgTemplate gUnknown_08623358[3] = 
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct WindowTemplate gUnknown_08623364 = 
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 1,
    .width = 13,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 2
};

const struct WindowTemplate gUnknown_0862336C = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x36
};

const struct WindowTemplate gUnknown_08623374 = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 0x1C,
    .width = 5,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const struct WindowTemplate gUnknown_0862337C = 
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 0x1C,
    .width = 3,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const LoopedTask gUnknown_08623384[] =
{
    NULL,
    sub_81CE37C,
    sub_81CE2D0,
    sub_81CE4D8,
    sub_81CE5E4,
    sub_81CE6BC,
    sub_81CE700
};

struct Pokenav7Struct
{
    u32 loopedTaskId;
    u8 tilemapBuffers[3][BG_SCREEN_SIZE];
    u8 filler[2];
    u8 unk1806[10];
    u32 (*unk1810)(void);
    s16 unk1814;
    u8 unk1816;
    u16 unk1818;
    u16 unk181A;
    void *unk181C;
    u8 unk1820;
    u8 unk1821;
    u8 unk1822;
    u8 unk1823;
    struct PokemonMarkMenu monMarks;
    struct Sprite *unk28dc;
    struct Sprite *unk28e0[10];
    u8 unk2908;
    u8 filler2[0x38ac - 0x2909];
};

extern s8 sub_81CDC84(void); // This function's declaration here is different than its definition in pokenav_unk_6. u8/s8

u32 sub_81CDE94(s32 state);
u32 sub_81CDE80(void);
void sub_81CED30(u8 var);
void sub_81CE9E4(void);
void sub_81CE934(void);
bool32 sub_81CE754(u8 a0, u16 a1, bool8 a2);
void sub_81CEE44(void);
void sub_81CEE90(void);
void sub_81CEEC8(void);
void sub_81CEE68(void);
void sub_81CEE74(bool8 showBg);

// code
bool32 sub_81CDDD4(void)
{
    struct Pokenav7Struct *structPtr = AllocSubstruct(0xC, sizeof(struct Pokenav7Struct));

    if (structPtr == NULL)
        return FALSE;

    structPtr->unk1816 = 0xFF;
    structPtr->loopedTaskId = CreateLoopedTask(sub_81CDE94, 1);
    structPtr->unk1810 = sub_81CDE80;
    structPtr->unk2908 = 0;
    return TRUE;
}

void sub_81CDE2C(s32 id)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);
    structPtr->loopedTaskId = CreateLoopedTask(gUnknown_08623384[id], 1);
    structPtr->unk1810 = sub_81CDE80;
}

u32 sub_81CDE64(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);
    return structPtr->unk1810();
}

u32 sub_81CDE80(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);
    return IsLoopedTaskActive(structPtr->loopedTaskId);
}

u32 sub_81CDE94(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    switch (state)
    {
    case 0:
        if (sub_81CD3C4() != TRUE)
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 1:
        InitBgTemplates(gUnknown_08623358, ARRAY_COUNT(gUnknown_08623358));
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        decompress_and_copy_tile_data_to_vram(3, gPokenavCondition_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        decompress_and_copy_tile_data_to_vram(2, gUnknown_08623228, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 3:
         if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;

        LZ77UnCompVram(gPokenavCondition_Tilemap, structPtr->tilemapBuffers[0]);
        SetBgTilemapBuffer(3, structPtr->tilemapBuffers[0]);
        if (sub_81CDD5C() == TRUE)
            CopyToBgTilemapBufferRect(3, gPokenavOptions_Tilemap, 0, 5, 9, 4);

        CopyBgTilemapBufferToVram(3);
        CopyPaletteIntoBufferUnfaded(gPokenavCondition_Pal, 0x10, 0x20);
        CopyPaletteIntoBufferUnfaded(gUnknown_08623208, 0xF0, 0x20);
        structPtr->unk1814 = -80;
        return LT_INC_AND_PAUSE;
    case 4:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;

        LZ77UnCompVram(gUnknown_0862323C, structPtr->tilemapBuffers[2]);
        SetBgTilemapBuffer(2, structPtr->tilemapBuffers[2]);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(gUnknown_086231E8, 0x30, 0x20);
        sub_81D21DC(2);
        return LT_INC_AND_PAUSE;
    case 5:
        sub_8199DF0(1, 0, 0, 1);
        sub_8199DF0(1, 17, 1, 1);
        CpuFill32(0, structPtr->tilemapBuffers[1], BG_SCREEN_SIZE);
        SetBgTilemapBuffer(1, structPtr->tilemapBuffers[1]);
        return LT_INC_AND_PAUSE;
    case 6:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;

        structPtr->unk1820 = AddWindow(&gUnknown_08623364);
        if (sub_81CDD5C() == TRUE)
        {
            structPtr->unk1821 = AddWindow(&gUnknown_0862336C);
            structPtr->unk1822 = AddWindow(&gUnknown_08623374);
            structPtr->unk1823 = AddWindow(&gUnknown_0862337C);
        }
        DeactivateAllTextPrinters();
        return LT_INC_AND_PAUSE;
    case 7:
        sub_81CED30(0);
        return LT_INC_AND_PAUSE;
    case 8:
        sub_81CE9E4();
        return LT_INC_AND_PAUSE;
    case 9:
        if (sub_81CDD5C() == TRUE)
            sub_81CE934();
        return LT_INC_AND_PAUSE;
    case 10:
        sub_81CE754(0, sub_81CDC84(), TRUE);
        return LT_INC_AND_PAUSE;
    case 11:
        sub_81CE754(1, sub_81CDC84(), TRUE);
        return LT_INC_AND_PAUSE;
    case 12:
        sub_81CE754(2, sub_81CDC84(), TRUE);
        return LT_INC_AND_PAUSE;
    case 13:
        if (sub_81CE754(3, sub_81CDC84(), TRUE) != TRUE)
            return LT_PAUSE;
        PutWindowTilemap(structPtr->unk1820);
        if (sub_81CDD5C() == TRUE)
        {
            PutWindowTilemap(structPtr->unk1821);
            PutWindowTilemap(structPtr->unk1822);
            PutWindowTilemap(structPtr->unk1823);
        }
        return LT_INC_AND_PAUSE;
    case 14:
        ShowBg(1);
        HideBg(2);
        ShowBg(3);
        if (sub_81CDD5C() == TRUE)
            PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return LT_INC_AND_PAUSE;
    case 15:
        PokenavFadeScreen(1);
        if (!sub_81CDD5C())
        {
            LoadLeftHeaderGfxForIndex(6);
            sub_81C7FA0(1, TRUE, 0);
            sub_81C7FA0(6, TRUE, 0);
        }
        return LT_INC_AND_PAUSE;
    case 16:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (!sub_81CDD5C() && sub_81C8010())
            return LT_PAUSE;
        SetVBlankCallback_(sub_81CEE44);
        return LT_INC_AND_PAUSE;
    case 17:
        sub_81CEE90();
        sub_81D20AC(sub_81CDC70());
        return LT_INC_AND_PAUSE;
    case 18:
        if (sub_81D20BC(sub_81CDC70()))
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 19:
        sub_81CEE74(TRUE);
        return LT_INC_AND_PAUSE;
    case 20:
        if (!sub_81D3178(sub_81CDC70(), &structPtr->unk1814))
        {
            sub_81D3464(structPtr->unk28e0);
            if (sub_81CDD5C() == TRUE || sub_81CDC60() != sub_81CDC50())
                sub_81D3480(structPtr->unk28e0, structPtr->unk1816, sub_81CDDB0());

            return LT_FINISH;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

u32 sub_81CE2D0(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    switch (state)
    {
    case 0:
        sub_81CEEC8();
        sub_81D3520(structPtr->unk28e0);
        return 1;
    case 1:
        if (sub_81D31A4(sub_81CDC70(), &structPtr->unk1814))
            return 2;
        sub_81CEE74(FALSE);
        return 1;
    case 2:
        PokenavFadeScreen(0);
        if (!sub_81CDD5C())
            sub_81C78A0();
        return 0;
    case 3:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return 2;
        sub_81D354C(structPtr->unk28e0);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return 1;
    }

    return LT_FINISH;
}

u32 sub_81CE37C(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);
    struct UnknownStruct_81D1ED4 *unkPtr = sub_81CDC70();

    switch (state)
    {
    case 0:
        sub_81CD548(0);
        return 1;
    case 1:
        sub_81CD548(1);
        return 1;
    case 2:
        sub_81CD548(2);
        sub_81D3520(structPtr->unk28e0);
        return 1;
    case 3:
        sub_81D2074(unkPtr);
        return 1;
    case 4:
        if (!sub_81D3150(&structPtr->unk1814))
        {
            sub_81CED30(sub_81CDC84());
            return 1;
        }
        return 2;
    case 5:
        sub_81CE754(0, sub_81CDC84(), FALSE);
        return 1;
    case 6:
        sub_81CE754(1, sub_81CDC84(), FALSE);
        return 1;
    case 7:
        sub_81CE754(2, sub_81CDC84(), FALSE);
        return 1;
    case 8:
        if (sub_81CE754(3, sub_81CDC84(), FALSE) == TRUE)
            return 1;
        return 2;
    case 9:
        unkPtr = sub_81CDC70();
        if (!sub_81D3178(unkPtr, &structPtr->unk1814))
        {
            sub_81D3464(structPtr->unk28e0);
            if (sub_81CDD5C() != TRUE && sub_81CDC60() == sub_81CDC50())
                return 1;

            sub_81D3480(structPtr->unk28e0, structPtr->unk1816, sub_81CDDB0());
            return 1;
        }
        return 2;
    }

    return LT_FINISH;
}

u32 sub_81CE4D8(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    switch (state)
    {
    case 0:
        sub_81CD548(0);
        return 1;
    case 1:
        sub_81CD548(1);
        return 1;
    case 2:
        sub_81CD548(2);
        return 1;
    case 3:
        sub_81CED30(sub_81CDC84());
        return 1;
    case 4:
        sub_81CE754(0, sub_81CDC84(), FALSE);
        return 1;
    case 5:
        sub_81CE754(1, sub_81CDC84(), FALSE);
        return 1;
    case 6:
        sub_81CE754(2, sub_81CDC84(), FALSE);
        return 1;
    case 7:
        if (sub_81CE754(3, sub_81CDC84(), FALSE) == TRUE)
            return 1;
        return 2;
    case 8:
        if (!sub_81D3178(sub_81CDC70(), &structPtr->unk1814))
        {
            sub_81D3464(structPtr->unk28e0);
            sub_81D3480(structPtr->unk28e0, structPtr->unk1816, sub_81CDDB0());
            return 1;
        }
        return 2;
    }

    return LT_FINISH;
}

u32 sub_81CE5E4(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    switch (state)
    {
    case 0:
        sub_81CD548(0);
        return 1;
    case 1:
        sub_81CD548(1);
        return 1;
    case 2:
        sub_81CD548(2);
        sub_81D3520(structPtr->unk28e0);
        return 1;
    case 3:
        if (!sub_81D31A4(sub_81CDC70(), &structPtr->unk1814))
            return 1;
        return 2;
    case 4:
        sub_81CE754(0, sub_81CDC84(), FALSE);
        return 1;
    case 5:
        sub_81CE754(1, sub_81CDC84(), FALSE);
        return 1;
    case 6:
        sub_81CE754(2, sub_81CDC84(), FALSE);
        return 1;
    case 7:
        if (sub_81CE754(3, sub_81CDC84(), FALSE) == TRUE)
            return 1;
        return 2;
    }

    return LT_FINISH;
}

u32 sub_81CE6BC(s32 state)
{
    switch (state)
    {
    case 0:
        sub_811FAA4(sub_81CDD7C(), 176, 32);
        return 1;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MARKINGS);
        return 1;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return 2;
        return 1;
    }

    return LT_FINISH;
}

u32 sub_81CE700(s32 state)
{
    switch (state)
    {
    case 0:
        sub_811FAF8();
        return 1;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return 1;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return 2;
        return 1;
    }

    return LT_FINISH;
}

static u8 *UnusedPrintNumberString(u8 *dst, u16 num)
{
    u8 *txtPtr = ConvertIntToDecimalStringN(dst, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    txtPtr = StringCopy(txtPtr, gText_Number2);

    return txtPtr;
}

bool32 sub_81CE754(u8 a0, u16 a1, bool8 a2)
{
    u8 text[32];
    const u8 *str;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    switch (a0)
    {
    case 0:
        FillWindowPixelBuffer(structPtr->unk1820, 0);
        if (sub_81CDD5C() == TRUE)
            FillWindowPixelBuffer(structPtr->unk1821, 0);
        break;
    case 1:
        if (sub_81CDC60() != sub_81CDC50() - 1 || sub_81CDD5C() == TRUE)
        {
            str = sub_81CDD04(a1);
            AddTextPrinterParameterized(structPtr->unk1820, 1, str, 0, 1, 0, NULL);
        }
        break;
    case 2:
        if (sub_81CDD5C() == TRUE)
        {
            str = sub_81CDD24(a1);
            AddTextPrinterParameterized(structPtr->unk1820, 1, str, 0, 17, 0, NULL);
            text[0] = EXT_CTRL_CODE_BEGIN;
            text[1] = 4;
            text[2] = 8;
            text[3] = 0;
            text[4] = 9;
            StringCopy(text + 5, gText_Number2);
            AddTextPrinterParameterized(structPtr->unk1821, 1, text, 4, 1, 0, NULL);
            ConvertIntToDecimalStringN(text + 5, sub_81CDD48(), STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(structPtr->unk1821, 1, text, 28, 1, 0, NULL);
        }
        break;
    case 3:
        switch (structPtr->unk2908)
        {
        case 0:
            if (a2)
                CopyWindowToVram(structPtr->unk1820, 3);
            else
                CopyWindowToVram(structPtr->unk1820, 2);

            if (sub_81CDD5C() == TRUE)
            {
                structPtr->unk2908++;
                return FALSE;
            }
            else
            {
                structPtr->unk2908 = 0;
                return TRUE;
            }
        case 1:
            if (a2)
                CopyWindowToVram(structPtr->unk1821, 3);
            else
                CopyWindowToVram(structPtr->unk1821, 2);

            structPtr->unk2908 = 0;
            return TRUE;
        }
    }

    return FALSE;
}

void sub_81CE934(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    CopyWindowToVram(structPtr->unk1822, 3);
    CopyWindowToVram(structPtr->unk1823, 3);
}

void sub_81CE964(struct Sprite *sprite)
{
    if (sprite->data[0] == sub_81CDC60())
        StartSpriteAnim(sprite, 0);
    else
        StartSpriteAnim(sprite, 1);
}

void sub_81CE990(struct Sprite *sprite)
{
    if (sub_81CDC60() == sub_81CDC50() - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(0x65);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(0x66);
}

void sub_81CE9C8(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, sub_81CDD7C());
}

void sub_81CE9E4(void)
{
    struct SpriteSheet sprSheets[4];
    struct SpriteTemplate sprTemplate;
    struct SpritePalette sprPals[3];
    struct SpriteSheet sprSheet;
    struct Sprite *sprite;
    u16 i, spriteId;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    sub_81D321C(sprSheets, &sprTemplate, sprPals);
    if (sub_81CDD5C() == TRUE)
    {
        structPtr->monMarks.baseTileTag = 0x6A;
        structPtr->monMarks.basePaletteTag = 0x6A;
        sub_811F90C(&structPtr->monMarks);
        sub_811FA90();
        sprite = sub_811FF94(0x69, 0x69, gUnknown_08623338);
        sprite->oam.priority = 3;
        sprite->pos1.x = 192;
        sprite->pos1.y = 32;
        sprite->callback = sub_81CE9C8;
        structPtr->unk28dc = sprite;
        sub_81C7990(IndexOfSpritePaletteTag(0x69), 0);
    }
    else
    {
        LoadSpriteSheets(sprSheets);
        Pokenav_AllocAndLoadPalettes(sprPals);
        for (i = 0; i < sub_81CDC50() - 1; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 226, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                structPtr->unk1806[i] = spriteId;
                gSprites[spriteId].data[0] = i;
                gSprites[spriteId].callback = sub_81CE964;
            }
            else
            {
                structPtr->unk1806[i] = 0xFF;
            }
        }

        sprTemplate.tileTag = 0x67;
        sprTemplate.callback = SpriteCallbackDummy;
        for (; i < 6; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 230, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                structPtr->unk1806[i] = spriteId;
                gSprites[spriteId].oam.size = 0;
            }
            else
            {
                structPtr->unk1806[i] = 0xFF;
            }
        }

        sprTemplate.tileTag = 0x66;
        sprTemplate.callback = sub_81CE990;
        spriteId = CreateSprite(&sprTemplate, 222, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            structPtr->unk1806[i] = spriteId;
            gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
            gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
        }
        else
        {
            structPtr->unk1806[i] = 0xFF;
        }
    }

    sub_81D32B0(&sprSheet, &sprPals[0]);
    LoadSpriteSheet(&sprSheet);
    sprPals[1].data = NULL;
    Pokenav_AllocAndLoadPalettes(sprPals);
}

void sub_81CEBF4(struct Pokenav7Struct *structPtr)
{
    u8 i;

    if (sub_81CDD5C() == TRUE)
    {
        DestroySprite(structPtr->unk28dc);
        FreeSpriteTilesByTag(0x6A);
        FreeSpriteTilesByTag(0x69);
        FreeSpritePaletteByTag(0x6A);
        FreeSpritePaletteByTag(0x69);
    }
    else
    {
        for (i = 0; i < 7; i++)
            DestroySprite(&gSprites[structPtr->unk1806[i]]);

        FreeSpriteTilesByTag(0x65);
        FreeSpriteTilesByTag(0x66);
        FreeSpriteTilesByTag(0x67);
        FreeSpritePaletteByTag(0x65);
        FreeSpritePaletteByTag(0x66);
    }

    if (structPtr->unk1816 != 0xFF)
    {
        DestroySprite(&gSprites[structPtr->unk1816]);
        FreeSpriteTilesByTag(0x64);
        FreeSpritePaletteByTag(0x64);
    }
}

void sub_81CECA0(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    RemoveWindow(structPtr->unk1820);
    if (sub_81CDD5C() == TRUE)
    {
        RemoveWindow(structPtr->unk1821);
        RemoveWindow(structPtr->unk1822);
        RemoveWindow(structPtr->unk1823);
    }
    else
    {
        sub_81C7FDC();
    }

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    sub_81CEBF4(structPtr);
    sub_81CEE68();
    FreePokenavSubstruct(0xC);
}

void sub_81CED10(struct Sprite *sprite)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);
    sprite->pos1.x = structPtr->unk1814 + 38;
}

void sub_81CED30(u8 var)
{
    struct SpriteTemplate sprTemplate;
    struct SpriteSheet sprSheet;
    struct SpritePalette sprPal;
    u8 spriteId;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    if (structPtr->unk1816 == 0xFF)
    {
        sub_81D31D0(&sprSheet, &sprTemplate, &sprPal);
        sprSheet.data = sub_81CDCB4(var);
        sprPal.data = sub_81CDCD4(var);
        structPtr->unk1818 = LoadSpritePalette(&sprPal);
        structPtr->unk181A = LoadSpriteSheet(&sprSheet);
        spriteId = CreateSprite(&sprTemplate, 38, 104, 0);
        structPtr->unk1816 = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(0x64);
            FreeSpritePaletteByTag(0x64);
            structPtr->unk1816 = 0xFF;
        }
        else
        {
            structPtr->unk1816 = spriteId;
            gSprites[structPtr->unk1816].callback = sub_81CED10;
            structPtr->unk181C = (void*)(VRAM) + 0x10000 + (structPtr->unk181A * 32);
            structPtr->unk1818 = (structPtr->unk1818 * 16) + 0x100;
        }
    }
    else
    {
        DmaCopy16Defvars(3, sub_81CDCB4(var), structPtr->unk181C, 0x800);
        LoadPalette(sub_81CDCD4(var), structPtr->unk1818, 0x20);
    }
}

void sub_81CEE44(void)
{
    struct UnknownStruct_81D1ED4 *unk = sub_81CDC70();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(unk);
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_81CEE68(void)
{
    SetPokenavVBlankCallback();
}

void sub_81CEE74(bool8 showBg)
{
    if (showBg)
        ShowBg(2);
    else
        HideBg(2);
}

void sub_81CEE90(void)
{
    struct UnknownStruct_81D1ED4 *unk = sub_81CDC70();
    u8 id = sub_81CDC84();

    gUnknown_030012BC = id;
    sub_81D1F84(unk, unk->unk14[3], unk->unk14[id]);
    sub_81D2074(unk);
}

void sub_81CEEC8(void)
{
    struct UnknownStruct_81D1ED4 *unk = sub_81CDC70();

    if (sub_81CDD5C() || sub_81CDC60() != sub_81CDC50() - 1)
        sub_81D1F84(unk, unk->unk14[sub_81CDC84()], unk->unk14[3]);
}

u8 sub_81CEF14(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(0xC);

    if (sub_81CDD5C() == 1)
        return structPtr->monMarks.markings;
    else
        return 0;
}

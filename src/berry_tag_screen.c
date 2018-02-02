#include "global.h"
#include "berry_tag_screen.h"
#include "berry.h"
#include "decompress.h"
#include "field_map_obj.h"
#include "item_menu.h"
#include "constants/items.h"
#include "item.h"
#include "item_use.h"
#include "main.h"
#include "menu.h"
#include "text.h"
#include "window.h"
#include "task.h"
#include "menu_helpers.h"
#include "palette.h"
#include "overworld.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "bg.h"
#include "malloc.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item_menu_icons.h"
#include "decompress.h"
#include "international_string_util.h"

// const rom data
static const struct BgTemplate gUnknown_085EFCF0[] =
{
  {
      .bg = 0,
      .charBaseIndex = 0,
      .mapBaseIndex = 31,
      .screenSize = 0,
      .paletteMode = 0,
      .priority = 0,
      .baseTile = 0
  },
  {
      .bg = 1,
      .charBaseIndex = 0,
      .mapBaseIndex = 30,
      .screenSize = 0,
      .paletteMode = 0,
      .priority = 1,
      .baseTile = 0
  },
  {
      .bg = 2,
      .charBaseIndex = 0,
      .mapBaseIndex = 29,
      .screenSize = 0,
      .paletteMode = 0,
      .priority = 2,
      .baseTile = 0
  },
  {
      .bg = 3,
      .charBaseIndex = 0,
      .mapBaseIndex = 28,
      .screenSize = 0,
      .paletteMode = 0,
      .priority = 3,
      .baseTile = 0
  }
};

static const u16 gUnknown_085EFD00[] = INCBIN_U16("graphics/interface/berry_tag_screen.gbapal");

static const struct TextColor gUnknown_085EFD20[] =
{
    {0, 2, 3},
    {15, 14, 13}
};

static const struct WindowTemplate gUnknown_085EFD28[] =
{
    {0x01, 0x0b, 0x04, 0x08, 0x02, 0x0f, 0x0045},
    {0x01, 0x0b, 0x07, 0x12, 0x04, 0x0f, 0x0055},
    {0x01, 0x04, 0x0e, 0x19, 0x04, 0x0f, 0x009d},
    {0x00, 0x02, 0x00, 0x08, 0x02, 0x0f, 0x0101},
    DUMMY_WIN_TEMPLATE
};

static const u8 *const gBerryFirmnessStringPointers[] =
{
    gBerryFirmnessString_VerySoft,
    gBerryFirmnessString_Soft,
    gBerryFirmnessString_Hard,
    gBerryFirmnessString_VeryHard,
    gBerryFirmnessString_SuperHard
};

// this file's functions
static void sub_8177C84(void);
static void sub_8177E14(void);
static void sub_8178008(void);
static void sub_8178090(void);
static void sub_81780F4(void);
static void sub_8178338(void);
static void sub_817839C(void);
static void sub_8178404(void);
static void sub_8178110(void);
static void sub_8178174(void);
static void sub_8178250(void);
static void sub_81782D0(void);
static void sub_8178304(void);
static bool8 sub_8177CB0(void);
static bool8 sub_8177E88(void);
static void sub_8178654(u8 taskId);
static void sub_8178610(u8 taskId);
static void sub_81787AC(u8 taskId);
static void sub_81786AC(u8 taskId, s8 toMove);
static void sub_8178728(s8 toMove);

// code
struct BerryTagScreenStruct
{
    u16 tilemapBuffers[3][0x400];
    u16 berryId;
    u8 berrySpriteId;
    u8 flavorCircleIds[FLAVOR_COUNT];
    u16 field_1808;
};

extern struct BerryTagScreenStruct *sBerryTag;

void DoBerryTagScreen(void)
{
    sBerryTag = AllocZeroed(0x180C);
    sBerryTag->berryId = ItemIdToBerryType(gSpecialVar_ItemId);
    SetMainCallback2(sub_8177C84);
}

static void sub_8177C54(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void sub_8177C70(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8177C84(void)
{
    while (1)
    {
        if (sub_81221EC() == TRUE)
            break;
        if (sub_8177CB0() == TRUE)
            break;
        if (sub_81221AC() == TRUE)
            break;
    }
}

static bool8 sub_8177CB0(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        clear_scheduled_bg_copies_to_vram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        if (!sub_81221AC())
            ResetTasks();
        gMain.state++;
        break;
    case 6:
        sub_8177E14();
        sBerryTag->field_1808 = 0;
        gMain.state++;
        break;
    case 7:
        if (sub_8177E88())
            gMain.state++;
        break;
    case 8:
        sub_8178008();
        gMain.state++;
        break;
    case 9:
        sub_8178090();
        gMain.state++;
        break;
    case 10:
        sub_81780F4();
        gMain.state++;
        break;
    case 11:
        sub_8178338();
        gMain.state++;
        break;
    case 12:
        sub_817839C();
        sub_8178404();
        gMain.state++;
        break;
    case 13:
        CreateTask(sub_8178654, 0);
        gMain.state++;
        break;
    case 14:
        BlendPalettes(-1, 0x10, 0);
        gMain.state++;
        break;
    case 15:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default: // done
        SetVBlankCallback(sub_8177C70);
        SetMainCallback2(sub_8177C54);
        return TRUE;
    }

    return FALSE;
}

static void sub_8177E14(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085EFCF0, ARRAY_COUNT(gUnknown_085EFCF0));
    SetBgTilemapBuffer(2, sBerryTag->tilemapBuffers[0]);
    SetBgTilemapBuffer(3, sBerryTag->tilemapBuffers[1]);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 sub_8177E88(void)
{
    u16 i;

    switch (sBerryTag->field_1808)
    {
    case 0:
        reset_temp_tile_data_buffers();
        decompress_and_copy_tile_data_to_vram(2, gUnknown_08D9BB44, 0, 0, 0);
        sBerryTag->field_1808++;
        break;
    case 1:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            LZDecompressWram(gUnknown_08D9BF98, sBerryTag->tilemapBuffers[0]);
            sBerryTag->field_1808++;
        }
        break;
    case 2:
        LZDecompressWram(gUnknown_08D9C13C, sBerryTag->tilemapBuffers[2]);
        sBerryTag->field_1808++;
        break;
    case 3:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = 0x4042;
        }
        else
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = 0x5042;
        }
        sBerryTag->field_1808++;
        break;
    case 4:
        LoadCompressedPalette(gUnknown_08D9BEF0, 0, 0xC0);
        sBerryTag->field_1808++;
        break;
    case 5:
        LoadCompressedObjectPic(&gUnknown_0857FDEC);
        sBerryTag->field_1808++;
        break;
    default:
        LoadCompressedObjectPalette(&gUnknown_0857FDF4);
        return TRUE; // done
    }

    return FALSE;
}

static void sub_8178008(void)
{
    u16 i;

    InitWindows(gUnknown_085EFD28);
    DeactivateAllTextPrinters();
    LoadPalette(gUnknown_085EFD00, 0xF0, 0x20);
    for (i = 0; i < ARRAY_COUNT(gUnknown_085EFD28) - 1; i++)
        PutWindowTilemap(i);
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
}

static void sub_817804C(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId)
{
    AddTextPrinterParameterized2(windowId, 1, x, y, 0, 0, &gUnknown_085EFD20[colorStructId], speed, text);
}

static void sub_8178090(void)
{
    memcpy(GetBgTilemapBuffer(0), sBerryTag->tilemapBuffers[2], sizeof(sBerryTag->tilemapBuffers[2]));
    FillWindowPixelBuffer(3, 0xFF);
    sub_817804C(3, gText_BerryTag, GetStringCenterAlignXOffset(1, gText_BerryTag, 0x40), 1, 0, 1);
    PutWindowTilemap(3);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void sub_81780F4(void)
{
    sub_8178110();
    sub_8178174();
    sub_8178250();
    sub_81782D0();
    sub_8178304();
}

static void sub_8178110(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    ConvertIntToDecimalStringN(gStringVar1, sBerryTag->berryId, 2, 2);
    StringCopy(gStringVar2, berry->name);
    StringExpandPlaceholders(gStringVar4, gText_UnkF908Var1Var2);
    sub_817804C(0, gStringVar4, 0, 1, 0, 0);
}

static void sub_8178174(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(1, 1, gText_SizeSlash, 0, 1, TEXT_SPEED_FF, NULL);
    if (berry->size != 0)
    {
        u32 inches, fraction;

        inches = 1000 * berry->size / 254;
        if (inches % 10 > 4)
            inches += 10;
        fraction = (inches % 100) / 10;
        inches /= 100;

        ConvertIntToDecimalStringN(gStringVar1, inches, 0, 2);
        ConvertIntToDecimalStringN(gStringVar2, fraction, 0, 2);
        StringExpandPlaceholders(gStringVar4, gText_Var1DotVar2);
        PrintTextOnWindow(1, 1, gStringVar4, 0x28, 1, 0, NULL);
    }
    else
    {
        PrintTextOnWindow(1, 1, gText_ThreeMarks, 0x28, 1, 0, NULL);
    }
}

static void sub_8178250(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(1, 1, gText_FirmSlash, 0, 0x11, TEXT_SPEED_FF, NULL);
    if (berry->firmness != 0)
        PrintTextOnWindow(1, 1, gBerryFirmnessStringPointers[berry->firmness - 1], 0x28, 0x11, 0, NULL);
    else
        PrintTextOnWindow(1, 1, gText_ThreeMarks, 0x28, 0x11, 0, NULL);
}

static void sub_81782D0(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(2, 1, berry->description1, 0, 1, 0, NULL);
}

static void sub_8178304(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(2, 1, berry->description2, 0, 0x11, 0, NULL);
}

static void sub_8178338(void)
{
    sBerryTag->berrySpriteId = CreateBerryTagSprite(sBerryTag->berryId - 1, 56, 64);
}

static void sub_817836C(void)
{
    DestroySprite(&gSprites[sBerryTag->berrySpriteId]);
    FreeBerryTagSpritePalette();
}

static void sub_817839C(void)
{
    sBerryTag->flavorCircleIds[FLAVOR_SPICY] = CreateBerryFlavorCircleSprite(64);
    sBerryTag->flavorCircleIds[FLAVOR_DRY] = CreateBerryFlavorCircleSprite(104);
    sBerryTag->flavorCircleIds[FLAVOR_SWEET] = CreateBerryFlavorCircleSprite(144);
    sBerryTag->flavorCircleIds[FLAVOR_BITTER] = CreateBerryFlavorCircleSprite(184);
    sBerryTag->flavorCircleIds[FLAVOR_SOUR] = CreateBerryFlavorCircleSprite(224);
}

static void sub_8178404(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    if (berry->spicy)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = 0;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = 1;

    if (berry->dry)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = 0;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = 1;

    if (berry->sweet)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = 0;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = 1;

    if (berry->bitter)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = 0;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = 1;

    if (berry->sour)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = 0;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = 1;
}

static void sub_8178594(void)
{
    u16 i;

    for (i = 0; i < FLAVOR_COUNT; i++)
        DestroySprite(&gSprites[sBerryTag->flavorCircleIds[i]]);
}

static void sub_81785D0(u8 taskId)
{
    PlaySE(SE_SELECT);
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gTasks[taskId].func = sub_8178610;
}

static void sub_8178610(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_817836C();
        sub_8178594();
        Free(sBerryTag);
        FreeAllWindowBuffers();
        SetMainCallback2(bag_menu_mail_related);
        DestroyTask(taskId);
    }
}

static void sub_8178654(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 arrowKeys = gMain.newAndRepeatedKeys & DPAD_ANY;
        if (arrowKeys == DPAD_UP)
            sub_81786AC(taskId, -1);
        else if (arrowKeys == DPAD_DOWN)
            sub_81786AC(taskId, 1);
        else if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            sub_81785D0(taskId);
    }
}

static void sub_81786AC(u8 taskId, s8 toMove)
{
    s16 *data = gTasks[taskId].data;
    s16 currPocketPosition = gUnknown_0203CE58.unk12[3] + gUnknown_0203CE58.unk8[3];
    u32 newPocketPosition = currPocketPosition + toMove;
    if (newPocketPosition < 46 && BagGetItemIdByPocketPosition(BAG_BERRIES, newPocketPosition) != 0)
    {
        if (toMove < 0)
            data[1] = 2;
        else
            data[1] = 1;

        data[0] = 0;
        PlaySE(SE_SELECT);
        sub_8178728(toMove);
        gTasks[taskId].func = sub_81787AC;
    }
}

static void sub_8178728(s8 toMove)
{
    u16 *scrollPos = &gUnknown_0203CE58.unk12[3];
    u16 *cursorPos = &gUnknown_0203CE58.unk8[3];
    if (toMove > 0)
    {
        if (*cursorPos < 4 || BagGetItemIdByPocketPosition(BAG_BERRIES, *scrollPos + 8) == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }
    else
    {
        if (*cursorPos > 3 || *scrollPos == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }

    sBerryTag->berryId = ItemIdToBerryType(BagGetItemIdByPocketPosition(BAG_BERRIES, *scrollPos + *cursorPos));
}

static void sub_81787AC(u8 taskId)
{
    u16 i;
    s16 posY;
    s16 *data = gTasks[taskId].data;
    data[0] += 0x10;
    data[0] &= 0xFF;

    if (data[1] == 1)
    {
        switch (data[0])
        {
        case 0x30:
            FillWindowPixelBuffer(0, 0);
            break;
        case 0x40:
            sub_8178110();
            break;
        case 0x50:
            sub_817836C();
            sub_8178338();
            break;
        case 0x60:
            FillWindowPixelBuffer(1, 0);
            break;
        case 0x70:
            sub_8178174();
            break;
        case 0x80:
            sub_8178250();
            break;
        case 0x90:
            sub_8178404();
            break;
        case 0xA0:
            FillWindowPixelBuffer(2, 0);
            break;
        case 0xB0:
            sub_81782D0();
            break;
        case 0xC0:
            sub_8178304();
            break;
        }
    }
    else
    {
        switch (data[0])
        {
        case 0x30:
            FillWindowPixelBuffer(2, 0);
            break;
        case 0x40:
            sub_8178304();
            break;
        case 0x50:
            sub_81782D0();
            break;
        case 0x60:
            sub_8178404();
            break;
        case 0x70:
            FillWindowPixelBuffer(1, 0);
            break;
        case 0x80:
            sub_8178250();
            break;
        case 0x90:
            sub_8178174();
            break;
        case 0xA0:
            sub_817836C();
            sub_8178338();
            break;
        case 0xB0:
            FillWindowPixelBuffer(0, 0);
            break;
        case 0xC0:
            sub_8178110();
            break;
        }
    }

    if (data[1] == 1)
        posY = -data[0];
    else
        posY = data[0];

    gSprites[sBerryTag->berrySpriteId].pos2.y = posY;
    for (i = 0; i < FLAVOR_COUNT; i++)
        gSprites[sBerryTag->flavorCircleIds[i]].pos2.y = posY;

    ChangeBgY(1, 0x1000, data[1]);
    ChangeBgY(2, 0x1000, data[1]);

    if (data[0] == 0)
        gTasks[taskId].func = sub_8178654;
}

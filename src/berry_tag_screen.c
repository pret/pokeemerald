#include "global.h"
#include "berry_tag_screen.h"
#include "berry.h"
#include "decompress.h"
#include "field_map_obj.h"
#include "item_menu.h"
#include "constants/items.h"
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
const struct BgTemplate gUnknown_085EFCF0[] =
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

const u16 gUnknown_085EFD00[] = INCBIN_U16("graphics/interface/berry_tag_screen.gbapal");

const struct TextColor gUnknown_085EFD20[] =
{
    {0, 2, 3},
    {15, 14, 13}
};

const struct WindowTemplate gUnknown_085EFD28[] =
{
    {0x01, 0x0b, 0x04, 0x08, 0x02, 0x0f, 0x0045},
    {0x01, 0x0b, 0x07, 0x12, 0x04, 0x0f, 0x0055},
    {0x01, 0x04, 0x0e, 0x19, 0x04, 0x0f, 0x009d},
    {0x00, 0x02, 0x00, 0x08, 0x02, 0x0f, 0x0101},
    DUMMY_WIN_TEMPLATE
};

const u8 *const gBerryFirmnessStringPointers[] =
{
    gBerryFirmnessString_VerySoft,
    gBerryFirmnessString_Soft,
    gBerryFirmnessString_Hard,
    gBerryFirmnessString_VeryHard,
    gBerryFirmnessString_SuperHard
};

// this file's functions
void sub_8177C84(void);
void sub_8177E14(void);
void sub_8178008(void);
void sub_8178090(void);
void sub_81780F4(void);
void sub_8178338(void);
void sub_817839C(void);
void sub_8178404(void);
void sub_8178110(void);
void sub_8178174(void);
void sub_8178250(void);
void sub_81782D0(void);
void sub_8178304(void);
bool8 sub_8177CB0(void);
bool8 sub_8177E88(void);
void sub_8178654(u8 taskId);

// code
struct BerryTagScreenStruct
{
    u16 tilemapBuffers[3][0x400];
    u16 berryId;
    u8 berrySpriteId;
    u16 field_1804;
    u16 field_1806;
    u16 field_1808;
};

extern struct BerryTagScreenStruct *sBerryTag;

void sub_8177C14(void)
{
    sBerryTag = AllocZeroed(0x180C);
    sBerryTag->berryId = ItemIdToBerryType(gSpecialVar_ItemId);
    SetMainCallback2(sub_8177C84);
}

void sub_8177C54(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_8177C70(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8177C84(void)
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

bool8 sub_8177CB0(void)
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

void sub_8177E14(void)
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

bool8 sub_8177E88(void)
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

void sub_8178008(void)
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

void sub_817804C(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId)
{
    AddTextPrinterParameterized2(windowId, 1, x, y, 0, 0, &gUnknown_085EFD20[colorStructId], speed, text);
}

void sub_8178090(void)
{
    memcpy(GetBgTilemapBuffer(0), sBerryTag->tilemapBuffers[2], sizeof(sBerryTag->tilemapBuffers[2]));
    FillWindowPixelBuffer(3, 0xFF);
    sub_817804C(3, gText_BerryTag, GetStringCenterAlignXOffset(1, gText_BerryTag, 0x40), 1, 0, 1);
    PutWindowTilemap(3);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_81780F4(void)
{
    sub_8178110();
    sub_8178174();
    sub_8178250();
    sub_81782D0();
    sub_8178304();
}

void sub_8178110(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    ConvertIntToDecimalStringN(gStringVar1, sBerryTag->berryId, 2, 2);
    StringCopy(gStringVar2, berry->name);
    StringExpandPlaceholders(gStringVar4, gText_UnkF908Var1Var2);
    sub_817804C(0, gStringVar4, 0, 1, 0, 0);
}

void sub_8178174(void)
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

void sub_8178250(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(1, 1, gText_FirmSlash, 0, 0x11, TEXT_SPEED_FF, NULL);
    if (berry->firmness != 0)
        PrintTextOnWindow(1, 1, gBerryFirmnessStringPointers[berry->firmness - 1], 0x28, 0x11, 0, NULL);
    else
        PrintTextOnWindow(1, 1, gText_ThreeMarks, 0x28, 0x11, 0, NULL);
}

void sub_81782D0(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(2, 1, berry->description1, 0, 1, 0, NULL);
}

void sub_8178304(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);
    PrintTextOnWindow(2, 1, berry->description2, 0, 0x11, 0, NULL);
}

void sub_8178338(void)
{
    sBerryTag->berrySpriteId = CreateBerryTagSprite(sBerryTag->berryId - 1, 56, 64);
}

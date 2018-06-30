#include "global.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "rom_818CFC8.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"


// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
static EWRAM_DATA u8 mapNamePopupTaskId = 0;

// .rodata
static const u8 gMapPopUp_Table[][960] =
{
    INCBIN_U8("graphics/interface/map_popup/wood.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/marble.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/stone.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/brick.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/underwater.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/stone2.4bpp"),
};

static const u8 gMapPopUp_Outline_Table[][960] =
{
    INCBIN_U8("graphics/interface/map_popup/wood_outline.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/marble_outline.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/stone_outline.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/brick_outline.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/underwater_outline.4bpp"),
    INCBIN_U8("graphics/interface/map_popup/stone2_outline.4bpp"),
};

static const u16 gMapPopUp_Palette_Table[][16] =
{
    INCBIN_U16("graphics/interface/map_popup/wood.gbapal"),
    INCBIN_U16("graphics/interface/map_popup/marble_outline.gbapal"),
    INCBIN_U16("graphics/interface/map_popup/stone_outline.gbapal"),
    INCBIN_U16("graphics/interface/map_popup/brick_outline.gbapal"),
    INCBIN_U16("graphics/interface/map_popup/underwater_outline.gbapal"),
    INCBIN_U16("graphics/interface/map_popup/stone2_outline.gbapal"),
};

static const u16 gUnknown_0857F444[16] = INCBIN_U16("graphics/interface/map_popup/857F444.gbapal");

static const u8 gRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_BRICK,
	MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK,
	MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
	MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_UNDERWATER,
	MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
	MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2,
	MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_MARBLE,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD,
	MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2,
	MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_MARBLE
};

static const u8 gText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 gText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 gText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 gText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 gText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 gText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 gText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 gText_Pyramid[] = _("PYRAMID");

static const u8 * const gBattlePyramid_MapHeaderStrings[] =
{
    gText_PyramidFloor1,
    gText_PyramidFloor2,
    gText_PyramidFloor3,
    gText_PyramidFloor4,
    gText_PyramidFloor5,
    gText_PyramidFloor6,
    gText_PyramidFloor7,
    gText_Pyramid,
};

// text
bool8 sub_80D47D4(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return 1;
}

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_SPECIAL_FLAG_0x4000) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            mapNamePopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
            SetGpuReg(REG_OFFSET_BG0VOFS, 40);
            gTasks[mapNamePopupTaskId].data[0] = 6;
            gTasks[mapNamePopupTaskId].data[2] = 40;
        }
        else
        {
            if (gTasks[mapNamePopupTaskId].data[0] != 2)
                gTasks[mapNamePopupTaskId].data[0] = 2;
            gTasks[mapNamePopupTaskId].data[3] = 1;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 6:
        task->data[4]++;
        if (task->data[4] > 30)
        {
            task->data[0] = 0;
            task->data[4] = 0;
            ShowMapNamePopUpWindow();
        }
        break;
    case 0:
        task->data[2] -= 2;
        if (task->data[2] <= 0 )
        {
            task->data[2] = 0;
            task->data[0] = 1;
            gTasks[mapNamePopupTaskId].data[1] = 0;
        }
        break;
    case 1:
        task->data[1]++;
        if (task->data[1] > 120 )
        {
            task->data[1] = 0;
            task->data[0] = 2;
        }
        break;
    case 2:
        task->data[2] += 2;
        if (task->data[2] > 39)
        {
            task->data[2] = 40;
            if (task->data[3])
            {
                task->data[0] = 6;
                task->data[4] = 0;
                task->data[3] = 0;
            }
            else
            {
                task->data[0] = 4;
                return;
            }
        }
        break;
    case 4:
        sub_819746C(GetMapNamePopUpWindowId(), TRUE);
        task->data[0] = 5;
        break;
    case 5:
        HideMapNamePopUpWindow();
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->data[2]);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        sub_819746C(GetMapNamePopUpWindowId(), TRUE);
        RemoveMapNamePopUpWindow();
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(mapNamePopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8* mapDisplayHeaderSource;

    if(InBattlePyramid())
    {
        if(gMapHeader.mapLayoutId == 0x17A)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[7];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.field_CB2];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }
    AddMapNamePopUpWindow();
    LoadMapNamePopUpWindowBg();
    x = GetStringCenterAlignXOffset(7, withoutPrefixPtr, 80);
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    PrintTextOnWindow(GetMapNamePopUpWindowId(), 7, mapDisplayHeader, x, 3, 0xFF, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), 3);
}

#ifdef NONMATCHING
static void sub_80D4A78(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    for(i=0; i<=11; i++)
    {
        FillBgTilemapBufferRect(bg, 0x21D + i, x + i - 1, y - 1, 1, 1, 0xE);
    }
    FillBgTilemapBufferRect(bg, 0x229 + i, x - 1, y, 1, 1, 0xE);
    FillBgTilemapBufferRect(bg, 0x22A + i, deltaX + x, y, 1, 1, 0xE);
    FillBgTilemapBufferRect(bg, 0x22B + i, x - 1, y + 1 , 1, 1, 0xE);
    FillBgTilemapBufferRect(bg, 0x22C + i, deltaX + x, y + 1, 1, 1, 0xE);
    FillBgTilemapBufferRect(bg, 0x22D + i, x - 1, y + 2, 1, 1, 0xE);
    FillBgTilemapBufferRect(bg, 0x22E + i, deltaX + x, y + 2, 1, 1, 0xE);
    for(i=0; i<=11; i++)
    {
        FillBgTilemapBufferRect(bg, 0x22F + i, x + i - 1, y + deltaY, 1, 1, 0xE);
    }
}
#else
NAKED
static void sub_80D4A78(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    asm("\n\
        .syntax unified\n\
        push {r4-r7,lr}\n\
        mov r7, r10\n\
        mov r6, r9\n\
        mov r5, r8\n\
        push {r5-r7}\n\
        sub sp, 0x1C\n\
        ldr r4, [sp, 0x3C]\n\
        lsls r0, 24\n\
        lsrs r7, r0, 24\n\
        lsls r1, 24\n\
        lsrs r1, 24\n\
        mov r10, r1\n\
        lsls r2, 24\n\
        lsls r3, 24\n\
        lsrs r3, 24\n\
        str r3, [sp, 0x10]\n\
        lsls r4, 24\n\
        lsrs r4, 24\n\
        str r4, [sp, 0x14]\n\
        movs r5, 0\n\
        lsls r0, r1, 24\n\
        asrs r1, r0, 24\n\
        lsrs r3, r2, 24\n\
        str r3, [sp, 0xC]\n\
        movs r6, 0xFF\n\
        lsls r6, 24\n\
        adds r6, r2\n\
        mov r8, r6\n\
        str r0, [sp, 0x18]\n\
        subs r4, r1, 0x1\n\
    _080D4AB4:\n\
        ldr r0, =0x0000021d\n\
        adds r1, r5, r0\n\
        lsls r1, 16\n\
        lsrs r1, 16\n\
        lsls r2, r4, 24\n\
        lsrs r2, 24\n\
        movs r3, 0x1\n\
        str r3, [sp]\n\
        str r3, [sp, 0x4]\n\
        movs r6, 0xE\n\
        mov r9, r6\n\
        str r6, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        mov r6, r8\n\
        lsrs r3, r6, 24\n\
        bl FillBgTilemapBufferRect\n\
        adds r4, 0x1\n\
        adds r5, 0x1\n\
        cmp r5, 0xB\n\
        ble _080D4AB4\n\
        ldr r1, =0x00000229\n\
        movs r0, 0x1\n\
        negs r0, r0\n\
        add r0, r10\n\
        lsls r0, 24\n\
        lsrs r0, 24\n\
        mov r8, r0\n\
        movs r5, 0x1\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r2, r9\n\
        str r2, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        mov r2, r8\n\
        ldr r3, [sp, 0xC]\n\
        bl FillBgTilemapBufferRect\n\
        ldr r1, =0x0000022a\n\
        ldr r6, [sp, 0x10]\n\
        add r6, r10\n\
        lsls r6, 24\n\
        lsrs r6, 24\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r3, r9\n\
        str r3, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        adds r2, r6, 0\n\
        ldr r3, [sp, 0xC]\n\
        bl FillBgTilemapBufferRect\n\
        ldr r1, =0x0000022b\n\
        ldr r4, [sp, 0xC]\n\
        adds r4, 0x1\n\
        lsls r4, 24\n\
        lsrs r4, 24\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r0, r9\n\
        str r0, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        mov r2, r8\n\
        adds r3, r4, 0\n\
        bl FillBgTilemapBufferRect\n\
        movs r1, 0x8B\n\
        lsls r1, 2\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r2, r9\n\
        str r2, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        adds r2, r6, 0\n\
        adds r3, r4, 0\n\
        bl FillBgTilemapBufferRect\n\
        ldr r1, =0x0000022d\n\
        ldr r4, [sp, 0xC]\n\
        adds r4, 0x2\n\
        lsls r4, 24\n\
        lsrs r4, 24\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r3, r9\n\
        str r3, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        mov r2, r8\n\
        adds r3, r4, 0\n\
        bl FillBgTilemapBufferRect\n\
        ldr r1, =0x0000022e\n\
        str r5, [sp]\n\
        str r5, [sp, 0x4]\n\
        mov r0, r9\n\
        str r0, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        adds r2, r6, 0\n\
        adds r3, r4, 0\n\
        bl FillBgTilemapBufferRect\n\
        movs r5, 0\n\
        ldr r1, [sp, 0xC]\n\
        ldr r2, [sp, 0x14]\n\
        adds r0, r1, r2\n\
        lsls r4, r0, 24\n\
        movs r6, 0x1\n\
    _080D4B8A:\n\
        ldr r3, =0x0000022f\n\
        adds r1, r5, r3\n\
        lsls r1, 16\n\
        lsrs r1, 16\n\
        subs r0, r5, 0x1\n\
        ldr r3, [sp, 0x18]\n\
        asrs r2, r3, 24\n\
        adds r2, r0\n\
        lsls r2, 24\n\
        lsrs r2, 24\n\
        str r6, [sp]\n\
        str r6, [sp, 0x4]\n\
        movs r0, 0xE\n\
        str r0, [sp, 0x8]\n\
        adds r0, r7, 0\n\
        lsrs r3, r4, 24\n\
        bl FillBgTilemapBufferRect\n\
        adds r5, 0x1\n\
        cmp r5, 0xB\n\
        ble _080D4B8A\n\
        add sp, 0x1C\n\
        pop {r3-r5}\n\
        mov r8, r3\n\
        mov r9, r4\n\
        mov r10, r5\n\
        pop {r4-r7}\n\
        pop {r0}\n\
        bx r0\n\
        .pool\n\
        .syntax divided");
}
#endif // NONMATCHING

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popupWindowId;
    u16 regionMapSectionId;
    u8 popUpThemeId;

    popupWindowId = GetMapNamePopUpWindowId();
    regionMapSectionId = gMapHeader.regionMapSectionId;
    if(regionMapSectionId > MAPSEC_DYNAMIC)
    {
        if(regionMapSectionId > MAPSEC_SPECIAL_AREA)
            regionMapSectionId -= (MAPSEC_SPECIAL_AREA - MAPSEC_DYNAMIC);
        else
            regionMapSectionId = 0; //discard kanto region sections
    }
    popUpThemeId = gRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    LoadBgTiles(GetWindowAttribute(popupWindowId, 0), &(gMapPopUp_Outline_Table[popUpThemeId][0]), 0x400, 0x21D);
    CallWindowFunction(popupWindowId, sub_80D4A78);
    PutWindowTilemap(popupWindowId);
    if(gMapHeader.weather == WEATHER_BUBBLES)
        LoadPalette(&gUnknown_0857F444, 0xE0, 0x20);
    else
        LoadPalette(&(gMapPopUp_Palette_Table[popUpThemeId][0]), 0xE0, 0x20);
    BlitBitmapToWindow(popupWindowId, &(gMapPopUp_Table[popUpThemeId][0]), 0, 0, 80, 24);
}

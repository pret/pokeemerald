
// Includes
#include "global.h"
#include "main.h"
#include "menu.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "trig.h"
#include "map_constants.h"
#include "overworld.h"
#include "flags.h"
#include "event_data.h"
#include "rom6.h"
#include "secret_base.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "region_map.h"

#define MAP_WIDTH 28
#define MAP_HEIGHT 15
#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)

// Static type declarations

struct RegionMapLocation
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u8 *name;
};

// Static RAM declarations

EWRAM_DATA struct RegionMap *gRegionMap = NULL;
EWRAM_DATA struct {
    /*0x000*/ void (*unk_000)(void);
    /*0x004*/ u16 unk_004;
    /*0x006*/ u16 mapSecId;
    /*0x008*/ struct RegionMap regionMap;
    /*0x88c*/ u8 filler_88c[0x1c0];
    /*0xa4c*/ u8 unk_a4c[0x28];
} *gUnknown_0203A148 = NULL; // a74

IWRAM_DATA bool32 gUnknown_03001180;

// Static ROM declarations

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
static u16 GetRegionMapSectionIdAt_Internal(u16 x, u16 y);
static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y);
static void RegionMap_InitializeStateBasedOnPlayerLocation(void);
static void RegionMap_InitializeStateBasedOnSSTidalLocation(void);
static u8 get_flagnr_blue_points(u16 mapSecId);
static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId);
static u16 RegionMap_GetTerraCaveMapSecId(void);
static void RegionMap_GetMarineCaveCoords(u16 *x, u16 *y);
static bool32 RegionMap_IsPlayerInCave(u8 mapSecId);
static void RegionMap_GetPositionOfCursorWithinMapSection(void);
static bool8 RegionMap_IsMapSecIdInNextRow(u16 y);
static void FreeRegionMapCursorSprite(void);
static void HideRegionMapPlayerIcon(void);
static void UnhideRegionMapPlayerIcon(void);
static void RegionMapPlayerIconSpriteCallback_Zoomed(struct Sprite *sprite);
static void RegionMapPlayerIconSpriteCallback_Full(struct Sprite *sprite);
static void RegionMapPlayerIconSpriteCallback(struct Sprite *sprite);
void sub_81248C0(void);
void sub_81248D4(void);
void sub_81248F4(void func(void));
void sub_8124904(void);
void sub_8124A70(void);
void sub_8124D14(void);

// .rodata

extern const u8 gUnknown_0859F60C[];
extern const u8 gUnknown_0859F650[];
extern const u16 gUnknown_0859F73C[];
extern const u8 gUnknown_0859F77C[];
extern const u8 gUnknown_085A04E0[];
extern const u8 gUnknown_085A096C[];
extern const struct RegionMapLocation gRegionMapEntries[];
extern const u8 gUnknown_085A084C[];
extern const u16 gUnknown_085A082C[];
extern const u16 gUnknown_085A08CC[];
extern const u8 gUnknown_085A08EC[];
extern const u16 gUnknown_085A1B24[][2];
extern const u16 gUnknown_085A1B84[];
extern const u16 gUnknown_085A1B8A[];
extern const struct UCoords16 gUnknown_085A1BAC[];
extern const u8 gUnknown_085A1BCC[];
extern const struct SpritePalette gUnknown_085A1C00;
extern const struct SpriteTemplate gUnknown_085A1C08;
extern const struct OamData gUnknown_085A1C20;
extern const union AnimCmd *const gUnknown_085A1C30[];
extern const u8 gUnknown_085A1C34[];
extern const struct BgTemplate gUnknown_085A1EE4[];
extern const struct WindowTemplate gUnknown_085A1EF0[];
extern const u8 gUnknown_085A1C58[];
extern const u8 gUnknown_085A1C90[];
extern const u16 gUnknown_085A1C38[];
extern const struct {
    const u8 *const *name;
    u16 mapSecId;
    u16 flag;
} gUnknown_085A1EDC[];

// .text

void InitRegionMap(struct RegionMap *regionMap, bool8 zoomed)
{
    sub_8122CF8(regionMap, NULL, zoomed);
    while (sub_8122DB0());
}

void sub_8122CF8(struct RegionMap *regionMap, struct BgTemplate *template, bool8 zoomed)
{
    gRegionMap = regionMap;
    gRegionMap->initStep = 0;
    gRegionMap->zoomed = zoomed;
    gRegionMap->inputCallback = zoomed == TRUE ? ProcessRegionMapInput_Zoomed : ProcessRegionMapInput_Full;
    if (template != NULL)
    {
        gRegionMap->bgNum = template->bg;
        gRegionMap->charBaseIdx = template->charBaseIndex;
        gRegionMap->mapBaseIdx = template->mapBaseIndex;
        gRegionMap->bgManaged = TRUE;
    }
    else
    {
        gRegionMap->bgNum = 2;
        gRegionMap->charBaseIdx = 2;
        gRegionMap->mapBaseIdx = 28;
        gRegionMap->bgManaged = FALSE;
    }
}

void sub_8122D88(struct RegionMap *regionMap)
{
    gRegionMap = regionMap;
    RegionMap_InitializeStateBasedOnPlayerLocation();
    gRegionMap->playerIconSpritePosX = gRegionMap->cursorPosX;
    gRegionMap->playerIconSpritePosY = gRegionMap->cursorPosY;
}

bool8 sub_8122DB0(void)
{
    switch (gRegionMap->initStep)
    {
        case 0:
            if (gRegionMap->bgManaged)
            {
                decompress_and_copy_tile_data_to_vram(gRegionMap->bgNum, gUnknown_0859F77C, 0, 0, 0);
            }
            else
            {
                LZ77UnCompVram(gUnknown_0859F77C, (u16 *)BG_CHAR_ADDR(2));
            }
            break;
        case 1:
            if (gRegionMap->bgManaged)
            {
                if (!free_temp_tile_data_buffers_if_possible())
                {
                    decompress_and_copy_tile_data_to_vram(gRegionMap->bgNum, gUnknown_085A04E0, 0, 0, 1);
                }
            }
            else
            {
                LZ77UnCompVram(gUnknown_085A04E0, (u16 *)BG_SCREEN_ADDR(28));
            }
            break;
        case 2:
            if (!free_temp_tile_data_buffers_if_possible())
            {
                LoadPalette(gUnknown_0859F73C, 0x70, 0x60);
            }
            break;
        case 3:
            LZ77UnCompWram(gUnknown_0859F60C, gRegionMap->cursorSmallImage);
            break;
        case 4:
            LZ77UnCompWram(gUnknown_0859F650, gRegionMap->cursorLargeImage);
            break;
        case 5:
            RegionMap_InitializeStateBasedOnPlayerLocation();
            gRegionMap->playerIconSpritePosX = gRegionMap->cursorPosX;
            gRegionMap->playerIconSpritePosY = gRegionMap->cursorPosY;
            gRegionMap->mapSecId = CorrectSpecialMapSecId_Internal(gRegionMap->mapSecId);
            gRegionMap->iconDrawType = get_flagnr_blue_points(gRegionMap->mapSecId);
            GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, 16);
            break;
        case 6:
            if (gRegionMap->zoomed == FALSE)
            {
                CalcZoomScrollParams(0, 0, 0, 0, 0x100, 0x100, 0);
            }
            else
            {
                gRegionMap->scrollX = gRegionMap->cursorPosX * 8 - 0x34;
                gRegionMap->scrollY = gRegionMap->cursorPosY * 8 - 0x44;
                gRegionMap->zoomedCursorPosX = gRegionMap->cursorPosX;
                gRegionMap->zoomedCursorPosY = gRegionMap->cursorPosY;
                CalcZoomScrollParams(gRegionMap->scrollX, gRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
            }
            break;
        case 7:
            RegionMap_GetPositionOfCursorWithinMapSection();
            UpdateRegionMapVideoRegs();
            gRegionMap->cursorSprite = NULL;
            gRegionMap->playerIconSprite = NULL;
            gRegionMap->cursorMovementFrameCounter = 0;
            gRegionMap->blinkPlayerIcon = FALSE;
            if (gRegionMap->bgManaged)
            {
                SetBgAttribute(gRegionMap->bgNum, BG_CTRL_ATTR_MAPBASEINDEX, 2);
                SetBgAttribute(gRegionMap->bgNum, BG_CTRL_ATTR_VISIBLE, gRegionMap->charBaseIdx);
                SetBgAttribute(gRegionMap->bgNum, BG_CTRL_ATTR_CHARBASEINDEX, gRegionMap->mapBaseIdx);
                SetBgAttribute(gRegionMap->bgNum, BG_CTRL_ATTR_PRIORITY, 1);
                SetBgAttribute(gRegionMap->bgNum, BG_CTRL_ATTR_SCREENSIZE, 1);
            }
            gRegionMap->initStep ++;
            return FALSE;
        default:
            return FALSE;
    }
    gRegionMap->initStep ++;
    return TRUE;
}

void sub_8123030(u16 a0, u32 a1)
{
    BlendPalettes(0x380, a1, a0);
    CpuCopy16(gPlttBufferFaded + 0x70, gPlttBufferUnfaded + 0x70, 0x60);
}

void FreeRegionMapIconResources(void)
{
    if (gRegionMap->cursorSprite != NULL)
    {
        DestroySprite(gRegionMap->cursorSprite);
        FreeSpriteTilesByTag(gRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(gRegionMap->cursorPaletteTag);
    }
    if (gRegionMap->playerIconSprite != NULL)
    {
        DestroySprite(gRegionMap->playerIconSprite);
        FreeSpriteTilesByTag(gRegionMap->playerIconTileTag);
        FreeSpritePaletteByTag(gRegionMap->playerIconPaletteTag);
    }
}

u8 sub_81230AC(void)
{
    return gRegionMap->inputCallback();
}

static u8 ProcessRegionMapInput_Full(void)
{
    u8 input;

    input = INPUT_EVENT_NONE;
    gRegionMap->cursorDeltaX = 0;
    gRegionMap->cursorDeltaY = 0;
    if (gMain.heldKeys & DPAD_UP && gRegionMap->cursorPosY > MAPCURSOR_Y_MIN)
    {
        gRegionMap->cursorDeltaY = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_DOWN && gRegionMap->cursorPosY < MAPCURSOR_Y_MAX)
    {
        gRegionMap->cursorDeltaY = +1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_LEFT && gRegionMap->cursorPosX > MAPCURSOR_X_MIN)
    {
        gRegionMap->cursorDeltaX = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_RIGHT && gRegionMap->cursorPosX < MAPCURSOR_X_MAX)
    {
        gRegionMap->cursorDeltaX = +1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        input = INPUT_EVENT_A_BUTTON;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        input = INPUT_EVENT_B_BUTTON;
    }
    if (input == INPUT_EVENT_MOVE_START)
    {
        gRegionMap->cursorMovementFrameCounter = 4;
        gRegionMap->inputCallback = MoveRegionMapCursor_Full;
    }
    return input;
}

static u8 MoveRegionMapCursor_Full(void)
{
    u16 mapSecId;

    if (gRegionMap->cursorMovementFrameCounter != 0)
    {
        return INPUT_EVENT_MOVE_CONT;
    }
    if (gRegionMap->cursorDeltaX > 0)
    {
        gRegionMap->cursorPosX ++;
    }
    if (gRegionMap->cursorDeltaX < 0)
    {
        gRegionMap->cursorPosX --;
    }
    if (gRegionMap->cursorDeltaY > 0)
    {
        gRegionMap->cursorPosY ++;
    }
    if (gRegionMap->cursorDeltaY < 0)
    {
        gRegionMap->cursorPosY --;
    }
    mapSecId = GetRegionMapSectionIdAt_Internal(gRegionMap->cursorPosX, gRegionMap->cursorPosY);
    gRegionMap->iconDrawType = get_flagnr_blue_points(mapSecId);
    if (mapSecId != gRegionMap->mapSecId)
    {
        gRegionMap->mapSecId = mapSecId;
        GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, 16);
    }
    RegionMap_GetPositionOfCursorWithinMapSection();
    gRegionMap->inputCallback = ProcessRegionMapInput_Full;
    return INPUT_EVENT_MOVE_END;
}

static u8 ProcessRegionMapInput_Zoomed(void)
{
    u8 input;

    input = INPUT_EVENT_NONE;
    gRegionMap->zoomedCursorDeltaX = 0;
    gRegionMap->zoomedCursorDeltaY = 0;
    if (gMain.heldKeys & DPAD_UP && gRegionMap->scrollY > -0x34)
    {
        gRegionMap->zoomedCursorDeltaY = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_DOWN && gRegionMap->scrollY < 0x3c)
    {
        gRegionMap->zoomedCursorDeltaY = +1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_LEFT && gRegionMap->scrollX > -0x2c)
    {
        gRegionMap->zoomedCursorDeltaX = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_RIGHT && gRegionMap->scrollX < 0xac)
    {
        gRegionMap->zoomedCursorDeltaX = +1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        input = INPUT_EVENT_A_BUTTON;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        input = INPUT_EVENT_B_BUTTON;
    }
    if (input == INPUT_EVENT_MOVE_START)
    {
        gRegionMap->inputCallback = MoveRegionMapCursor_Zoomed;
        gRegionMap->zoomedCursorMovementFrameCounter = 0;
    }
    return input;
}

static u8 MoveRegionMapCursor_Zoomed(void)
{
    u16 x;
    u16 y;
    u16 mapSecId;

    gRegionMap->scrollY += gRegionMap->zoomedCursorDeltaY;
    gRegionMap->scrollX += gRegionMap->zoomedCursorDeltaX;
    RegionMap_SetBG2XAndBG2Y(gRegionMap->scrollX, gRegionMap->scrollY);
    gRegionMap->zoomedCursorMovementFrameCounter ++;
    if (gRegionMap->zoomedCursorMovementFrameCounter == 8)
    {
        x = (gRegionMap->scrollX + 0x2c) / 8 + 1;
        y = (gRegionMap->scrollY + 0x34) / 8 + 2;
        if (x != gRegionMap->zoomedCursorPosX || y != gRegionMap->zoomedCursorPosY)
        {
            gRegionMap->zoomedCursorPosX = x;
            gRegionMap->zoomedCursorPosY = y;
            mapSecId = GetRegionMapSectionIdAt_Internal(x, y);
            gRegionMap->iconDrawType = get_flagnr_blue_points(mapSecId);
            if (mapSecId != gRegionMap->mapSecId)
            {
                gRegionMap->mapSecId = mapSecId;
                GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, 16);
            }
            RegionMap_GetPositionOfCursorWithinMapSection();
        }
        gRegionMap->zoomedCursorMovementFrameCounter = 0;
        gRegionMap->inputCallback = ProcessRegionMapInput_Zoomed;
        return INPUT_EVENT_MOVE_END;
    }
    return INPUT_EVENT_MOVE_CONT;
}

void sub_8123418(void)
{
    if (gRegionMap->zoomed == FALSE)
    {
        gRegionMap->scrollY = 0;
        gRegionMap->scrollX = 0;
        gRegionMap->unk_040 = 0;
        gRegionMap->unk_03c = 0;
        gRegionMap->unk_060 = gRegionMap->cursorPosX * 8 - 0x34;
        gRegionMap->unk_062 = gRegionMap->cursorPosY * 8 - 0x44;
        gRegionMap->unk_044 = (gRegionMap->unk_060 << 8) / 16;
        gRegionMap->unk_048 = (gRegionMap->unk_062 << 8) / 16;
        gRegionMap->zoomedCursorPosX = gRegionMap->cursorPosX;
        gRegionMap->zoomedCursorPosY = gRegionMap->cursorPosY;
        gRegionMap->unk_04c = 0x10000;
        gRegionMap->unk_050 = -0x800;
    }
    else
    {
        gRegionMap->unk_03c = gRegionMap->scrollX * 256;
        gRegionMap->unk_040 = gRegionMap->scrollY * 256;
        gRegionMap->unk_060 = 0;
        gRegionMap->unk_062 = 0;
        gRegionMap->unk_044 = -(gRegionMap->unk_03c / 16);
        gRegionMap->unk_048 = -(gRegionMap->unk_040 / 16);
        gRegionMap->cursorPosX = gRegionMap->zoomedCursorPosX;
        gRegionMap->cursorPosY = gRegionMap->zoomedCursorPosY;
        gRegionMap->unk_04c = 0x8000;
        gRegionMap->unk_050 = 0x800;
    }
    gRegionMap->unk_06e = 0;
    FreeRegionMapCursorSprite();
    HideRegionMapPlayerIcon();
}

bool8 sub_8123514(void)
{
    bool8 r4;

    if (gRegionMap->unk_06e >= 16)
    {
        return 0;
    }
    gRegionMap->unk_06e ++;
    if (gRegionMap->unk_06e == 16)
    {
        gRegionMap->unk_044 = 0;
        gRegionMap->unk_048 = 0;
        gRegionMap->scrollX = gRegionMap->unk_060;
        gRegionMap->scrollY = gRegionMap->unk_062;
        gRegionMap->unk_04c = (gRegionMap->zoomed == FALSE) ? (128 << 8) : (256 << 8);
        gRegionMap->zoomed = !gRegionMap->zoomed;
        gRegionMap->inputCallback = (gRegionMap->zoomed == FALSE) ? ProcessRegionMapInput_Full : ProcessRegionMapInput_Zoomed;
        CreateRegionMapCursor(gRegionMap->cursorTileTag, gRegionMap->cursorPaletteTag);
        UnhideRegionMapPlayerIcon();
        r4 = FALSE;
    }
    else
    {
        gRegionMap->unk_03c += gRegionMap->unk_044;
        gRegionMap->unk_040 += gRegionMap->unk_048;
        gRegionMap->scrollX = gRegionMap->unk_03c >> 8;
        gRegionMap->scrollY = gRegionMap->unk_040 >> 8;
        gRegionMap->unk_04c += gRegionMap->unk_050;
        if ((gRegionMap->unk_044 < 0 && gRegionMap->scrollX < gRegionMap->unk_060) || (gRegionMap->unk_044 > 0 && gRegionMap->scrollX > gRegionMap->unk_060))
        {
            gRegionMap->scrollX = gRegionMap->unk_060;
            gRegionMap->unk_044 = 0;
        }
        if ((gRegionMap->unk_048 < 0 && gRegionMap->scrollY < gRegionMap->unk_062) || (gRegionMap->unk_048 > 0 && gRegionMap->scrollY > gRegionMap->unk_062))
        {
            gRegionMap->scrollY = gRegionMap->unk_062;
            gRegionMap->unk_048 = 0;
        }
        if (gRegionMap->zoomed == FALSE)
        {
            if (gRegionMap->unk_04c < (128 << 8))
            {
                gRegionMap->unk_04c = (128 << 8);
                gRegionMap->unk_050 = 0;
            }
        }
        else
        {
            if (gRegionMap->unk_04c > (256 << 8))
            {
                gRegionMap->unk_04c = (256 << 8);
                gRegionMap->unk_050 = 0;
            }
        }
        r4 = TRUE;
    }
    CalcZoomScrollParams(gRegionMap->scrollX, gRegionMap->scrollY, 0x38, 0x48, gRegionMap->unk_04c >> 8, gRegionMap->unk_04c >> 8, 0);
    return r4;
}

static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
{
    s32 var1;
    s32 var2;
    s32 var3;
    s32 var4;

    gRegionMap->bg2pa = e * gSineTable[rotation + 64] >> 8;
    gRegionMap->bg2pc = e * -gSineTable[rotation] >> 8;
    gRegionMap->bg2pb = f * gSineTable[rotation] >> 8;
    gRegionMap->bg2pd = f * gSineTable[rotation + 64] >> 8;

    var1 = (scrollX << 8) + (c << 8);
    var2 = d * gRegionMap->bg2pb + gRegionMap->bg2pa * c;
    gRegionMap->bg2x = var1 - var2;

    var3 = (scrollY << 8) + (d << 8);
    var4 = gRegionMap->bg2pd * d + gRegionMap->bg2pc * c;
    gRegionMap->bg2y = var3 - var4;

    gRegionMap->needUpdateVideoRegs = TRUE;
}

static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y)
{
    gRegionMap->bg2x = (x << 8) + 0x1c00;
    gRegionMap->bg2y = (y << 8) + 0x2400;
    gRegionMap->needUpdateVideoRegs = TRUE;
}

void UpdateRegionMapVideoRegs(void)
{
    if (gRegionMap->needUpdateVideoRegs)
    {
        SetGpuReg(REG_OFFSET_BG2PA, gRegionMap->bg2pa);
        SetGpuReg(REG_OFFSET_BG2PB, gRegionMap->bg2pb);
        SetGpuReg(REG_OFFSET_BG2PC, gRegionMap->bg2pc);
        SetGpuReg(REG_OFFSET_BG2PD, gRegionMap->bg2pd);
        SetGpuReg(REG_OFFSET_BG2X_L, gRegionMap->bg2x);
        SetGpuReg(REG_OFFSET_BG2X_H, gRegionMap->bg2x >> 16);
        SetGpuReg(REG_OFFSET_BG2Y_L, gRegionMap->bg2y);
        SetGpuReg(REG_OFFSET_BG2Y_H, gRegionMap->bg2y >> 16);
        gRegionMap->needUpdateVideoRegs = FALSE;
    }
}

void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y)
{
    CalcZoomScrollParams(x, y, 0x38, 0x48, 0x100, 0x100, 0);
    UpdateRegionMapVideoRegs();
    if (gRegionMap->playerIconSprite != NULL)
    {
        gRegionMap->playerIconSprite->pos2.x = -x;
        gRegionMap->playerIconSprite->pos2.y = -y;
    }
}

static u16 GetRegionMapSectionIdAt_Internal(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;
    return gUnknown_085A096C[x + y * MAP_WIDTH];
}

static void RegionMap_InitializeStateBasedOnPlayerLocation(void)
{
    const struct MapHeader *mapHeader;
    u16 mapWidth;
    u16 mapHeight;
    u16 x;
    u16 y;
    u16 r1;
    u16 r9;
    struct WarpData *r4;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP_SS_TIDAL_CORRIDOR
        && (gSaveBlock1Ptr->location.mapNum == MAP_ID_SS_TIDAL_CORRIDOR
            || gSaveBlock1Ptr->location.mapNum == MAP_ID_SS_TIDAL_LOWER_DECK
            || gSaveBlock1Ptr->location.mapNum == MAP_ID_SS_TIDAL_ROOMS))
    {
        RegionMap_InitializeStateBasedOnSSTidalLocation();
        return;
    }

    switch (get_map_light_level_by_bank_and_number(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        default:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            gRegionMap->playerIsInCave = FALSE;
            mapWidth = gMapHeader.mapData->width;
            mapHeight = gMapHeader.mapData->height;
            x = gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y;
            if (gRegionMap->mapSecId == MAPSEC_UNDERWATER || gRegionMap->mapSecId == MAPSEC_UNDERWATER_MARINE_CAVE)
            {
                gRegionMap->playerIsInCave = TRUE;
            }
            break;
        case 4:
        case 7:
            if (gMapHeader.flags & 0x02)
            {
                mapHeader = get_mapheader_by_bank_and_number(gSaveBlock1Ptr->warp4.mapGroup, gSaveBlock1Ptr->warp4.mapNum);
                gRegionMap->mapSecId = mapHeader->regionMapSectionId;
                gRegionMap->playerIsInCave = TRUE;
                mapWidth = mapHeader->mapData->width;
                mapHeight = mapHeader->mapData->height;
                x = gSaveBlock1Ptr->warp4.x;
                y = gSaveBlock1Ptr->warp4.y;
            }
            else
            {
                gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
                gRegionMap->playerIsInCave = TRUE;
                mapWidth = 1;
                mapHeight = 1;
                x = 1;
                y = 1;
            }
            break;
        case 9:
            mapHeader = get_mapheader_by_bank_and_number((u16)gSaveBlock1Ptr->warp2.mapGroup, (u16)gSaveBlock1Ptr->warp2.mapNum);
            gRegionMap->mapSecId = mapHeader->regionMapSectionId;
            gRegionMap->playerIsInCave = TRUE;
            mapWidth = mapHeader->mapData->width;
            mapHeight = mapHeader->mapData->height;
            x = gSaveBlock1Ptr->warp2.x;
            y = gSaveBlock1Ptr->warp2.y;
            break;
        case 8:

            gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            if (gRegionMap->mapSecId != MAPSEC_SS_TIDAL)
            {
                r4 = &gSaveBlock1Ptr->warp4;
                mapHeader = get_mapheader_by_bank_and_number(r4->mapGroup, r4->mapNum);
            }
            else
            {
                r4 = &gSaveBlock1Ptr->warp2;
                mapHeader = get_mapheader_by_bank_and_number(r4->mapGroup, r4->mapNum);
                gRegionMap->mapSecId = mapHeader->regionMapSectionId;
            }
            if (RegionMap_IsPlayerInCave(gRegionMap->mapSecId))
            {
                gRegionMap->playerIsInCave = TRUE;
            }
            else
            {
                gRegionMap->playerIsInCave = FALSE;
            }
            mapWidth = mapHeader->mapData->width;
            mapHeight = mapHeader->mapData->height;
            x = r4->x;
            y = r4->y;
            break;
    }

    r9 = x;

    r1 = mapWidth / gRegionMapEntries[gRegionMap->mapSecId].width;
    if (r1 == 0)
    {
        r1 = 1;
    }
    x /= r1;
    if (x >= gRegionMapEntries[gRegionMap->mapSecId].width)
    {
        x = gRegionMapEntries[gRegionMap->mapSecId].width - 1;
    }

    r1 = mapHeight / gRegionMapEntries[gRegionMap->mapSecId].height;
    if (r1 == 0)
    {
        r1 = 1;
    }
    y /= r1;
    if (y >= gRegionMapEntries[gRegionMap->mapSecId].height)
    {
        y = gRegionMapEntries[gRegionMap->mapSecId].height - 1;
    }

    switch (gRegionMap->mapSecId)
    {
        case MAPSEC_ROUTE_114:
            if (y != 0)
            {
                x = 0;
            }
            break;
        case MAPSEC_ROUTE_126:
        case MAPSEC_UNDERWATER_125:
            x = 0;
            if (gSaveBlock1Ptr->pos.x > 32)
            {
                x = 1;
            }
            if (gSaveBlock1Ptr->pos.x > 0x33)
            {
                x++;
            }
            y = 0;
            if (gSaveBlock1Ptr->pos.y > 0x25)
            {
                y = 1;
            }
            if (gSaveBlock1Ptr->pos.y > 0x38)
            {
                y++;
            }
            break;
        case MAPSEC_ROUTE_121:
            x = 0;
            if (r9 > 14)
            {
                x = 1;
            }
            if (r9 > 0x1C)
            {
                x++;
            }
            if (r9 > 0x36)
            {
                x++;
            }
            break;
        case MAPSEC_UNDERWATER_MARINE_CAVE:
            RegionMap_GetMarineCaveCoords(&gRegionMap->cursorPosX, &gRegionMap->cursorPosY);
            return;
    }
    gRegionMap->cursorPosX = gRegionMapEntries[gRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    gRegionMap->cursorPosY = gRegionMapEntries[gRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static void RegionMap_InitializeStateBasedOnSSTidalLocation(void)
{
    u16 y;
    u16 x;
    u8 mapGroup;
    u8 mapNum;
    u16 r1;
    s16 sp2;
    s16 sp4;
    const struct MapHeader *mapHeader;

    y = 0;
    x = 0;
    switch (GetSSTidalLocation(&mapGroup, &mapNum, &sp2, &sp4))
    {
        case 1:
            gRegionMap->mapSecId = MAPSEC_SLATEPORT_CITY;
            break;
        case 2:
            gRegionMap->mapSecId = MAPSEC_LILYCOVE_CITY;
            break;
        case 3:
            gRegionMap->mapSecId = MAPSEC_ROUTE_124;
            break;
        case 4:
            gRegionMap->mapSecId = MAPSEC_ROUTE_131;
            break;
        default:
        case 0:
            mapHeader = get_mapheader_by_bank_and_number(mapGroup, mapNum);

            gRegionMap->mapSecId = mapHeader->regionMapSectionId;
            r1 = mapHeader->mapData->width / gRegionMapEntries[gRegionMap->mapSecId].width;
            if (r1 == 0)
                r1 = 1;
            x = sp2 / r1;
            if (x >= gRegionMapEntries[gRegionMap->mapSecId].width)
                x = gRegionMapEntries[gRegionMap->mapSecId].width - 1;

            r1 = mapHeader->mapData->height / gRegionMapEntries[gRegionMap->mapSecId].height;
            if (r1 == 0)
                r1 = 1;
            y = sp4 / r1;
            if (y >= gRegionMapEntries[gRegionMap->mapSecId].height)
                y = gRegionMapEntries[gRegionMap->mapSecId].height - 1;
            break;
    }
    gRegionMap->playerIsInCave = FALSE;
    gRegionMap->cursorPosX = gRegionMapEntries[gRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    gRegionMap->cursorPosY = gRegionMapEntries[gRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static u8 get_flagnr_blue_points(u16 mapSecId)
{
    switch (mapSecId)
    {
        case MAPSEC_NONE:
            return MAPSECTYPE_NONE;
        case MAPSEC_LITTLEROOT_TOWN:
            return FlagGet(FLAG_VISITED_LITTLEROOT_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_OLDALE_TOWN:
            return FlagGet(FLAG_VISITED_OLDALE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_DEWFORD_TOWN:
            return FlagGet(FLAG_VISITED_DEWFORD_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_LAVARIDGE_TOWN:
            return FlagGet(FLAG_VISITED_LAVARIDGE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_FALLARBOR_TOWN:
            return FlagGet(FLAG_VISITED_FALLARBOR_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_VERDANTURF_TOWN:
            return FlagGet(FLAG_VISITED_VERDANTURF_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_PACIFIDLOG_TOWN:
            return FlagGet(FLAG_VISITED_PACIFIDLOG_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_PETALBURG_CITY:
            return FlagGet(FLAG_VISITED_PETALBURG_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_SLATEPORT_CITY:
            return FlagGet(FLAG_VISITED_SLATEPORT_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_MAUVILLE_CITY:
            return FlagGet(FLAG_VISITED_MAUVILLE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_RUSTBORO_CITY:
            return FlagGet(FLAG_VISITED_RUSTBORO_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_FORTREE_CITY:
            return FlagGet(FLAG_VISITED_FORTREE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_LILYCOVE_CITY:
            return FlagGet(FLAG_VISITED_LILYCOVE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_MOSSDEEP_CITY:
            return FlagGet(FLAG_VISITED_MOSSDEEP_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_SOOTOPOLIS_CITY:
            return FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_EVER_GRANDE_CITY:
            return FlagGet(FLAG_VISITED_EVER_GRANDE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
        case MAPSEC_BATTLE_FRONTIER:
            return FlagGet(FLAG_UNLOCK_BATTLE_FRONTIER) ? MAPSECTYPE_BATTLE_FRONTIER : MAPSECTYPE_NONE;
        case MAPSEC_SOUTHERN_ISLAND:
            return FlagGet(FLAG_UNLOCK_SOUTHERN_ISLAND) ? MAPSECTYPE_PLAIN : MAPSECTYPE_NONE;
        default:
            return MAPSECTYPE_PLAIN;
    }
}

u16 GetRegionMapSectionIdAt(u16 x, u16 y)
{
    return GetRegionMapSectionIdAt_Internal(x, y);
}

static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId)
{
    u32 i;

    for (i = 0; i < 3; i ++)
    {
        if (gUnknown_085A1B84[i] == mapSecId)
        {
            return RegionMap_GetTerraCaveMapSecId();
        }
    }
    for (i = 0; gUnknown_085A1B24[i][0] != MAPSEC_NONE; i ++)
    {
        if (gUnknown_085A1B24[i][0] == mapSecId)
        {
            return gUnknown_085A1B24[i][1];
        }
    }
    return mapSecId;
}

static u16 RegionMap_GetTerraCaveMapSecId(void)
{
    s16 idx;

    idx = VarGet(VAR_0x4037) - 1;
    if (idx < 0 || idx > 15)
    {
        idx = 0;
    }
    return gUnknown_085A1B8A[idx];
}

static void RegionMap_GetMarineCaveCoords(u16 *x, u16 *y)
{
    u16 idx;

    idx = VarGet(VAR_0x4037);
    if (idx < 9 || idx > 16)
    {
        idx = 9;
    }
    idx -= 9;
    *x = gUnknown_085A1BAC[idx].x + MAPCURSOR_X_MIN;
    *y = gUnknown_085A1BAC[idx].y + MAPCURSOR_Y_MIN;
}

static bool32 RegionMap_IsPlayerInCave(u8 mapSecId)
{
    int i;

    for (i = 0; i == 0; i ++)
    {
        if (gUnknown_085A1BCC[i] == mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

u16 CorrectSpecialMapSecId(u16 mapSecId)
{
    return CorrectSpecialMapSecId_Internal(mapSecId);
}

static void RegionMap_GetPositionOfCursorWithinMapSection(void)
{
    u16 x;
    u16 y;
    u16 posWithinMapSec;

    if (gRegionMap->mapSecId == MAPSEC_NONE)
    {
        gRegionMap->posWithinMapSec = 0;
        return;
    }
    if (!gRegionMap->zoomed)
    {
        x = gRegionMap->cursorPosX;
        y = gRegionMap->cursorPosY;
    }
    else
    {
        x = gRegionMap->zoomedCursorPosX;
        y = gRegionMap->zoomedCursorPosY;
    }
    posWithinMapSec = 0;
    while (1)
    {
        if (x <= MAPCURSOR_X_MIN)
        {
            if (RegionMap_IsMapSecIdInNextRow(y))
            {
                y --;
                x = MAPCURSOR_X_MAX + 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            x --;
            if (GetRegionMapSectionIdAt_Internal(x, y) == gRegionMap->mapSecId)
            {
                posWithinMapSec ++;
            }
        }
    }
    gRegionMap->posWithinMapSec = posWithinMapSec;
}

static bool8 RegionMap_IsMapSecIdInNextRow(u16 y)
{
    u16 x;

    if (y -- == 0)
    {
        return FALSE;
    }
    for (x = MAPCURSOR_X_MIN; x <= MAPCURSOR_X_MAX; x ++)
    {
        if (GetRegionMapSectionIdAt_Internal(x, y) == gRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void SpriteCallback_CursorFull(struct Sprite *sprite)
{
    if (gRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->pos1.x += 2 * gRegionMap->cursorDeltaX;
        sprite->pos1.y += 2 * gRegionMap->cursorDeltaY;
        gRegionMap->cursorMovementFrameCounter --;
    }
}

static void SpriteCallback_CursorZoomed(struct Sprite *sprite)
{

}

void CreateRegionMapCursor(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteTemplate template;
    struct SpritePalette palette;
    struct SpriteSheet sheet;

    palette = gUnknown_085A1C00;
    template = gUnknown_085A1C08;
    sheet.tag = tileTag;
    template.tileTag = tileTag;
    gRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    gRegionMap->cursorPaletteTag = paletteTag;
    if (!gRegionMap->zoomed)
    {
        sheet.data = gRegionMap->cursorSmallImage;
        sheet.size = sizeof(gRegionMap->cursorSmallImage);
        template.callback = SpriteCallback_CursorFull;
    }
    else
    {
        sheet.data = gRegionMap->cursorLargeImage;
        sheet.size = sizeof(gRegionMap->cursorLargeImage);
        template.callback = SpriteCallback_CursorZoomed;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0x38, 0x48, 0);
    if (spriteId != MAX_SPRITES)
    {
        gRegionMap->cursorSprite = &gSprites[spriteId];
        if (gRegionMap->zoomed == TRUE)
        {
            gRegionMap->cursorSprite->oam.size = 2;
            gRegionMap->cursorSprite->pos1.x -= 8;
            gRegionMap->cursorSprite->pos1.y -= 8;
            StartSpriteAnim(gRegionMap->cursorSprite, 1);
        }
        else
        {
            gRegionMap->cursorSprite->oam.size = 1;
            gRegionMap->cursorSprite->pos1.x = 8 * gRegionMap->cursorPosX + 4;
            gRegionMap->cursorSprite->pos1.y = 8 * gRegionMap->cursorPosY + 4;
        }
        gRegionMap->cursorSprite->data1 = 2;
        gRegionMap->cursorSprite->data2 = (IndexOfSpritePaletteTag(paletteTag) << 4) + 0x101;
        gRegionMap->cursorSprite->data3 = TRUE;
    }
}

static void FreeRegionMapCursorSprite(void)
{
    if (gRegionMap->cursorSprite != NULL)
    {
        DestroySprite(gRegionMap->cursorSprite);
        FreeSpriteTilesByTag(gRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(gRegionMap->cursorPaletteTag);
    }
}

void sub_8124268(void)
{
    gRegionMap->cursorSprite->data3 = TRUE;
}

void sub_8124278(void)
{
    gRegionMap->cursorSprite->data3 = FALSE;
}

void CreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteSheet sheet = {gUnknown_085A084C, 0x80, tileTag};
    struct SpritePalette palette = {gUnknown_085A082C, paletteTag};
    struct SpriteTemplate template = {tileTag, paletteTag, &gUnknown_085A1C20, gUnknown_085A1C30, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy};

    if (sub_8124668(gMapHeader.regionMapSectionId))
    {
        gRegionMap->playerIconSprite = NULL;
        return;
    }
    if (gSaveBlock2Ptr->playerGender == FEMALE)
    {
        sheet.data = gUnknown_085A08EC;
        palette.data = gUnknown_085A08CC;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0, 0, 1);
    gRegionMap->playerIconSprite = &gSprites[spriteId];
    if (!gRegionMap->zoomed)
    {
        gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 8 + 4;
        gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 8 + 4;
        gRegionMap->playerIconSprite->callback = RegionMapPlayerIconSpriteCallback_Full;
    }
    else
    {
        gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 16 - 0x30;
        gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 16 - 0x42;
        gRegionMap->playerIconSprite->callback = RegionMapPlayerIconSpriteCallback_Zoomed;
    }
}

static void HideRegionMapPlayerIcon(void)
{
    if (gRegionMap->playerIconSprite != NULL)
    {
        gRegionMap->playerIconSprite->invisible = TRUE;
        gRegionMap->playerIconSprite->callback = SpriteCallbackDummy;
    }
}

static void UnhideRegionMapPlayerIcon(void)
{
    if (gRegionMap->playerIconSprite != NULL)
    {
        if (gRegionMap->zoomed == TRUE)
        {
            gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 16 - 0x30;
            gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 16 - 0x42;
            gRegionMap->playerIconSprite->callback = RegionMapPlayerIconSpriteCallback_Zoomed;
            gRegionMap->playerIconSprite->invisible = FALSE;
        }
        else
        {
            gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 8 + 4;
            gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 8 + 4;
            gRegionMap->playerIconSprite->pos2.x = 0;
            gRegionMap->playerIconSprite->pos2.y = 0;
            gRegionMap->playerIconSprite->callback = RegionMapPlayerIconSpriteCallback_Full;
            gRegionMap->playerIconSprite->invisible = FALSE;
        }
    }
}

static void RegionMapPlayerIconSpriteCallback_Zoomed(struct Sprite *sprite)
{
    sprite->pos2.x = -2 * gRegionMap->scrollX;
    sprite->pos2.y = -2 * gRegionMap->scrollY;
    sprite->data0 = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    sprite->data1 = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
    if (sprite->data0 < -8 || sprite->data0 > 0xa8 || sprite->data1 < -8 || sprite->data1 > 0xf8)
    {
        sprite->data2 = FALSE;
    }
    else
    {
        sprite->data2 = TRUE;
    }
    if (sprite->data2 == TRUE)
    {
        RegionMapPlayerIconSpriteCallback(sprite);
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

static void RegionMapPlayerIconSpriteCallback_Full(struct Sprite *sprite)
{
    RegionMapPlayerIconSpriteCallback(sprite);
}

static void RegionMapPlayerIconSpriteCallback(struct Sprite *sprite)
{
    if (gRegionMap->blinkPlayerIcon)
    {
        if (++ sprite->data7 > 16)
        {
            sprite->data7 = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void sub_812454C(void)
{
    if (gRegionMap->playerIsInCave)
    {
        gRegionMap->blinkPlayerIcon = TRUE;
    }
}

u8 *GetMapName(u8 *dest, u16 regionMapId, u16 padLength)
{
    u8 *str;
    u16 i;

    if (regionMapId == MAPSEC_SECRET_BASE)
    {
        str = GetSecretBaseMapName(dest);
    }
    else if (regionMapId < MAPSEC_NONE)
    {
        str = StringCopy(dest, gRegionMapEntries[regionMapId].name);
    }
    else
    {
        if (padLength == 0)
        {
            padLength = 18;
        }
        return StringFill(dest, CHAR_SPACE, padLength);
    }
    if (padLength != 0)
    {
        for (i = str - dest; i < padLength; i ++)
        {
            *str++ = CHAR_SPACE;
        }
        *str = EOS;
    }
    return str;
}

u8 *sub_81245DC(u8 *dest, u16 mapSecId)
{
    switch (mapSecId)
    {
        case MAPSEC_SS_TIDAL:
            return StringCopy(dest, gText_Ferry);
        case MAPSEC_SECRET_BASE:
            return StringCopy(dest, gText_SecretBase);
        default:
            return GetMapName(dest, mapSecId, 0);
    }
}

u8 *sub_8124610(u8 *dest, u16 mapSecId)
{
    if (mapSecId == MAPSEC_AQUA_HIDEOUT_OLD)
    {
        return StringCopy(dest, gText_Hideout);
    }
    else
    {
        return sub_81245DC(dest, mapSecId);
    }
}

void sub_8124630(u16 mapSecId, u16 *x, u16 *y, u16 *width, u16 *height)
{
    *x = gRegionMapEntries[mapSecId].x;
    *y = gRegionMapEntries[mapSecId].y;
    *width = gRegionMapEntries[mapSecId].width;
    *height = gRegionMapEntries[mapSecId].height;
}

bool8 sub_8124658(void)
{
    return gRegionMap->zoomed;
}

bool32 sub_8124668(u8 mapSecId)
{
    u32 i;

    for (i = 0; i < 3; i ++)
    {
        if (mapSecId == gUnknown_085A1C34[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

void MCB2_FlyMap(void)
{
    switch (gMain.state)
    {
        case 0:
            SetVBlankCallback(NULL);
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            SetGpuReg(REG_OFFSET_BG0HOFS, 0);
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            SetGpuReg(REG_OFFSET_BG1HOFS, 0);
            SetGpuReg(REG_OFFSET_BG1VOFS, 0);
            SetGpuReg(REG_OFFSET_BG2VOFS, 0);
            SetGpuReg(REG_OFFSET_BG2HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3VOFS, 0);
            gUnknown_0203A148 = malloc(sizeof(*gUnknown_0203A148));
            if (gUnknown_0203A148 == NULL)
            {
                SetMainCallback2(sub_8086194);
            }
            else
            {
                ResetPaletteFade();
                ResetSpriteData();
                FreeSpriteTileRanges();
                FreeAllSpritePalettes();
                gMain.state ++;
            }
            break;
        case 1:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(1, gUnknown_085A1EE4, 3);
            gMain.state ++;
            break;
        case 2:
            InitWindows(gUnknown_085A1EF0);
            DeactivateAllTextPrinters();
            gMain.state ++;
            break;
        case 3:
            sub_809882C(0, 0x65, 0xd0);
            clear_scheduled_bg_copies_to_vram();
            gMain.state ++;
            break;
        case 4:
            InitRegionMap(&gUnknown_0203A148->regionMap, FALSE);
            CreateRegionMapCursor(0, 0);
            CreateRegionMapPlayerIcon(1, 1);
            gUnknown_0203A148->mapSecId = gUnknown_0203A148->regionMap.mapSecId;
            StringFill(gUnknown_0203A148->unk_a4c, CHAR_SPACE, 16);
            gUnknown_03001180 = TRUE;
            sub_8124904();
            gMain.state ++;
            break;
        case 5:
            LZ77UnCompVram(gUnknown_085A1C58, (u16 *)BG_CHAR_ADDR(3));
            gMain.state ++;
            break;
        case 6:
            LZ77UnCompVram(gUnknown_085A1C90, (u16 *)BG_SCREEN_ADDR(30));
            gMain.state ++;
            break;
        case 7:
            LoadPalette(gUnknown_085A1C38, 0x10, 0x20);
            PutWindowTilemap(2);
            FillWindowPixelBuffer(2, 0x00);
            PrintTextOnWindow(2, 1, gText_FlyToWhere, 0, 1, 0, NULL);
            schedule_bg_copy_tilemap_to_vram(0);
            gMain.state ++;
            break;
        case 8:
            sub_8124A70();
            gMain.state ++;
            break;
        case 9:
            BlendPalettes(-1, 16, 0);
            SetVBlankCallback(sub_81248C0);
            gMain.state ++;
            break;
        case 10:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            sub_81248F4(sub_8124D14);
            SetMainCallback2(sub_81248D4);
            gMain.state ++;
            break;
    }
}

void sub_81248C0(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_81248D4(void)
{
    gUnknown_0203A148->unk_000();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
}

void sub_81248F4(void callback(void))
{
    gUnknown_0203A148->unk_000 = callback;
    gUnknown_0203A148->unk_004 = 0;
}

void sub_8124904(void)
{
    u16 i;
    bool32 flag;
    const u8 *name;

    if (gUnknown_0203A148->regionMap.iconDrawType > MAPSECTYPE_NONE && gUnknown_0203A148->regionMap.iconDrawType <= MAPSECTYPE_BATTLE_FRONTIER)
    {
        flag = FALSE;
        for (i = 0; i < 1; i ++)
        {
            if (gUnknown_0203A148->regionMap.mapSecId == gUnknown_085A1EDC[i].mapSecId)
            {
                if (FlagGet(gUnknown_085A1EDC[i].flag))
                {
                    StringLength(gUnknown_085A1EDC[i].name[gUnknown_0203A148->regionMap.posWithinMapSec]);
                    flag = TRUE;
                    sub_8198070(0, FALSE);
                    SetWindowBorderStyle(1, FALSE, 0x65, 0x0d);
                    PrintTextOnWindow(1, 1, gUnknown_0203A148->regionMap.mapSecName, 0, 1, 0, NULL);
                    name = gUnknown_085A1EDC[i].name[gUnknown_0203A148->regionMap.posWithinMapSec];
                    PrintTextOnWindow(1, 1, name, GetStringRightAlignXOffset(1, name, 0x60), 0x11, 0, NULL);
                    schedule_bg_copy_tilemap_to_vram(0);
                    gUnknown_03001180 = TRUE;
                }
                break;
            }
        }
        if (!flag)
        {
            if (gUnknown_03001180 == TRUE)
            {
                sub_8198070(1, FALSE);
                SetWindowBorderStyle(0, FALSE, 0x65, 0x0d);
            }
            else
            {
                FillWindowPixelBuffer(0, 0x11);
            }
            PrintTextOnWindow(0, 1, gUnknown_0203A148->regionMap.mapSecName, 0, 1, 0, NULL);
            schedule_bg_copy_tilemap_to_vram(0);
            gUnknown_03001180 = FALSE;
        }
    }
    else
    {
        if (gUnknown_03001180 == TRUE)
        {
            sub_8198070(1, FALSE);
            SetWindowBorderStyle(0, FALSE, 0x65, 0x0d);
        }
        FillWindowPixelBuffer(0, 0x11);
        CopyWindowToVram(0, 2);
        schedule_bg_copy_tilemap_to_vram(0);
        gUnknown_03001180 = FALSE;
    }
}

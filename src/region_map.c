
// Includes
#include "global.h"
#include "main.h"
#include "menu.h"
#include "gpu_regs.h"
#include "palette.h"
#include "trig.h"
#include "map_constants.h"
#include "overworld.h"
#include "flags.h"
#include "event_data.h"
#include "rom6.h"
#include "region_map.h"

#define MAP_WIDTH 28
#define MAP_HEIGHT 15
#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)

// Static type declarations

struct UnkStruct_0203A148 {
    u8 filler_000[0xa74];
};

struct RegionMapLocation
{
    u8 x, y;
    u8 width, height;
    const u8 *regionMapSectionId;
};

// Static RAM declarations

EWRAM_DATA struct RegionMap *gRegionMap = NULL;
EWRAM_DATA struct UnkStruct_0203A148 *gUnknown_0203A148 = NULL;

// Static ROM declarations

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
u16 GetRegionMapSectionIdAt(u16 x, u16 y);
static void sub_812378C(s16 x, s16 y);
static void sub_81238AC(void);
static void sub_8123C00(void);
static u8 get_flagnr_blue_points(u16 mapSecId);
u16 sub_8123EB4(u16 mapSecId);
static u16 sub_8123F04(void);
static void sub_8123F30(u16 *x, u16 *y);
static bool32 sub_8123F74(u8 mapSecId);
static void sub_8123FB0(void);
static bool8 sub_8124038(u16 y);
void sub_8124238(void);
void sub_81243B0(void);
void sub_81243DC(void);

// .rodata

extern const u8 gUnknown_0859F60C[];
extern const u8 gUnknown_0859F650[];
extern const u16 gUnknown_0859F73C[];
extern const u8 gUnknown_0859F77C[];
extern const u8 gUnknown_085A04E0[];
extern const u8 gUnknown_085A096C[];
extern const struct RegionMapLocation gRegionMapEntries[];
extern const u16 gUnknown_085A1B24[][2];
extern const u16 gUnknown_085A1B84[];
extern const u16 gUnknown_085A1B8A[];
extern const struct UCoords16 gUnknown_085A1BAC[];
extern const u8 gUnknown_085A1BCC[];
extern const struct SpritePalette gUnknown_085A1C00;
extern const struct SpriteTemplate gUnknown_085A1C08;

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
    sub_81238AC();
    gRegionMap->unk_074 = gRegionMap->cursorPosX;
    gRegionMap->unk_076 = gRegionMap->cursorPosY;
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
                LZ77UnCompVram(gUnknown_0859F77C, (u16 *)BG_SCREEN_ADDR(16));
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
            sub_81238AC();
            gRegionMap->unk_074 = gRegionMap->cursorPosX;
            gRegionMap->unk_076 = gRegionMap->cursorPosY;
            gRegionMap->mapSecId = sub_8123EB4(gRegionMap->mapSecId);
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
            sub_8123FB0();
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
    mapSecId = GetRegionMapSectionIdAt(gRegionMap->cursorPosX, gRegionMap->cursorPosY);
    gRegionMap->iconDrawType = get_flagnr_blue_points(mapSecId);
    if (mapSecId != gRegionMap->mapSecId)
    {
        gRegionMap->mapSecId = mapSecId;
        GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, 16);
    }
    sub_8123FB0();
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
    sub_812378C(gRegionMap->scrollX, gRegionMap->scrollY);
    gRegionMap->zoomedCursorMovementFrameCounter ++;
    if (gRegionMap->zoomedCursorMovementFrameCounter == 8)
    {
        x = (gRegionMap->scrollX + 0x2c) / 8 + 1;
        y = (gRegionMap->scrollY + 0x34) / 8 + 2;
        if (x != gRegionMap->zoomedCursorPosX || y != gRegionMap->zoomedCursorPosY)
        {
            gRegionMap->zoomedCursorPosX = x;
            gRegionMap->zoomedCursorPosY = y;
            mapSecId = GetRegionMapSectionIdAt(x, y);
            gRegionMap->iconDrawType = get_flagnr_blue_points(mapSecId);
            if (mapSecId != gRegionMap->mapSecId)
            {
                gRegionMap->mapSecId = mapSecId;
                GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, 16);
            }
            sub_8123FB0();
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
    sub_8124238();
    sub_81243B0();
}

u8 sub_8123514(void)
{
    u8 r4;

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
        sub_81243DC();
        r4 = 0;
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
        r4 = 1;
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

static void sub_812378C(s16 x, s16 y)
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

void sub_8123824(s16 x, s16 y)
{
    CalcZoomScrollParams(x, y, 0x38, 0x48, 0x100, 0x100, 0);
    UpdateRegionMapVideoRegs();
    if (gRegionMap->playerIconSprite != NULL)
    {
        gRegionMap->playerIconSprite->pos2.x = -x;
        gRegionMap->playerIconSprite->pos2.y = -y;
    }
}

u16 GetRegionMapSectionIdAt(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;
    return gUnknown_085A096C[x + y * MAP_WIDTH];
}

static void sub_81238AC(void)
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
        sub_8123C00();
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
            if (gRegionMap->mapSecId != MAPSEC_UNK_0x57)
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
            if (sub_8123F74(gRegionMap->mapSecId))
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
            sub_8123F30(&gRegionMap->cursorPosX, &gRegionMap->cursorPosY);
            return;
    }
    gRegionMap->cursorPosX = gRegionMapEntries[gRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    gRegionMap->cursorPosY = gRegionMapEntries[gRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static void sub_8123C00(void)
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

u16 sub_8123E9C(u16 x, u16 y)
{
    return GetRegionMapSectionIdAt(x, y);
}

u16 sub_8123EB4(u16 mapSecId)
{
    u32 i;

    for (i = 0; i < 3; i ++)
    {
        if (gUnknown_085A1B84[i] == mapSecId)
        {
            return sub_8123F04();
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

static u16 sub_8123F04(void)
{
    s16 idx;

    idx = VarGet(VAR_0x4037) - 1;
    if (idx < 0 || idx > 15)
    {
        idx = 0;
    }
    return gUnknown_085A1B8A[idx];
}

static void sub_8123F30(u16 *x, u16 *y)
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

static bool32 sub_8123F74(u8 mapSecId)
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

u16 sub_8123F9C(u16 mapSecId)
{
    return sub_8123EB4(mapSecId);
}

static void sub_8123FB0(void)
{
    u16 x;
    u16 y;
    u16 unk_003;

    if (gRegionMap->mapSecId == MAPSEC_NONE)
    {
        gRegionMap->unk_003 = 0;
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
    unk_003 = 0;
    while (1)
    {
        if (x <= MAPCURSOR_X_MIN)
        {
            if (sub_8124038(y))
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
            if (GetRegionMapSectionIdAt(x, y) == gRegionMap->mapSecId)
            {
                unk_003 ++;
            }
        }
    }
    gRegionMap->unk_003 = unk_003;
}

static bool8 sub_8124038(u16 y)
{
    u16 x;

    if (y -- == 0)
    {
        return 0;
    }
    for (x = MAPCURSOR_X_MIN; x <= MAPCURSOR_X_MAX; x ++)
    {
        if (GetRegionMapSectionIdAt(x, y) == gRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void sub_8124088(struct Sprite *sprite)
{
    if (gRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->pos1.x += 2 * gRegionMap->cursorDeltaX;
        sprite->pos1.y += 2 * gRegionMap->cursorDeltaY;
        gRegionMap->cursorMovementFrameCounter --;
    }
}

static void TaskDummy8(struct Sprite *sprite)
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
        template.callback = sub_8124088;
    }
    else
    {
        sheet.data = gRegionMap->cursorLargeImage;
        sheet.size = sizeof(gRegionMap->cursorLargeImage);
        template.callback = TaskDummy8;
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
        gRegionMap->cursorSprite->data3 = 1;
    }
}

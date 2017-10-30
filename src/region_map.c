
// Includes
#include "global.h"
#include "main.h"
#include "menu.h"
#include "gpu_regs.h"
#include "palette.h"
#include "trig.h"
#include "region_map.h"

// Static type declarations

struct UnkStruct_0203A148 {
    u8 filler_000[0xa74];
};

// Static RAM declarations

EWRAM_DATA struct RegionMap *gRegionMap = NULL;
EWRAM_DATA struct UnkStruct_0203A148 *gUnknown_0203A148 = NULL;

// Static ROM declarations

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
void sub_81237B4(void);
void sub_81238AC(void);
u8 get_flagnr_blue_points(u16 mapSecId);
u16 sub_8123EB4(u16 mapSecId);
void sub_8123FB0(void);
u16 sub_812386C(u16 x, u16 y);
void sub_812378C(s16 x, s16 y);
void sub_8124238(void);
void sub_81243B0(void);
void sub_81243DC(void);

// .rodata

extern const u8 gUnknown_0859F77C[];
extern const u8 gUnknown_085A04E0[];
extern const u16 gUnknown_0859F73C[];
extern const u8 gUnknown_0859F60C[];
extern const u8 gUnknown_0859F650[];

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
            gRegionMap->unk_002 = get_flagnr_blue_points(gRegionMap->mapSecId);
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
                gRegionMap->unk_064 = gRegionMap->cursorPosX;
                gRegionMap->unk_066 = gRegionMap->cursorPosY;
                CalcZoomScrollParams(gRegionMap->scrollX, gRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
            }
            break;
        case 7:
            sub_8123FB0();
            sub_81237B4();
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
    if (gMain.heldKeys & DPAD_UP && gRegionMap->cursorPosY > 2)
    {
        gRegionMap->cursorDeltaY = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_DOWN && gRegionMap->cursorPosY < 16)
    {
        gRegionMap->cursorDeltaY = +1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_LEFT && gRegionMap->cursorPosX > 1)
    {
        gRegionMap->cursorDeltaX = -1;
        input = INPUT_EVENT_MOVE_START;
    }
    if (gMain.heldKeys & DPAD_RIGHT && gRegionMap->cursorPosX < 28)
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
    mapSecId = sub_812386C(gRegionMap->cursorPosX, gRegionMap->cursorPosY);
    gRegionMap->unk_002 = get_flagnr_blue_points(mapSecId);
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
        if (x != gRegionMap->unk_064 || y != gRegionMap->unk_066)
        {
            gRegionMap->unk_064 = x;
            gRegionMap->unk_066 = y;
            mapSecId = sub_812386C(x, y);
            gRegionMap->unk_002 = get_flagnr_blue_points(mapSecId);
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
        gRegionMap->unk_064 = gRegionMap->cursorPosX;
        gRegionMap->unk_066 = gRegionMap->cursorPosY;
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
        gRegionMap->cursorPosX = gRegionMap->unk_064;
        gRegionMap->cursorPosY = gRegionMap->unk_066;
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
        return 0;
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
        if ((gRegionMap->unk_044 < 0 && gRegionMap->scrollX < gRegionMap->unk_060)
            || (gRegionMap->unk_044 > 0 && gRegionMap->scrollX > gRegionMap->unk_060))
        {
            gRegionMap->scrollX = gRegionMap->unk_060;
            gRegionMap->unk_044 = 0;
        }
        if ((gRegionMap->unk_048 < 0 && gRegionMap->scrollY < gRegionMap->unk_062)
            || (gRegionMap->unk_048 > 0 && gRegionMap->scrollY > gRegionMap->unk_062))
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

void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
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

void sub_812378C(s16 x, s16 y)
{
    gRegionMap->bg2x = (x << 8) + 0x1c00;
    gRegionMap->bg2y = (y << 8) + 0x2400;
    gRegionMap->needUpdateVideoRegs = TRUE;
}

void sub_81237B4(void)
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

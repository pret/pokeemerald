#include <limits.h>
#include "global.h"
#include "bg.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "decompress.h"

#define DISPCNT_ALL_BG_AND_MODE_BITS    (DISPCNT_BG_ALL_ON | 0x7)

struct BgControl
{
    struct BgConfig {
        u8 visible:1;
        u8 unknown_1:1;
        u8 screenSize:2;
        u8 priority:2;
        u8 mosaic:1;
        u8 wraparound:1;

        u8 charBaseIndex:2;
        u8 mapBaseIndex:5;
        u8 paletteMode:1;
    } configs[NUM_BACKGROUNDS];

    u16 bgVisibilityAndMode;
};

struct BgConfig2
{
    u32 baseTile:10;
    u32 basePalette:4;

    void *tilemap;
    s32 bg_x;
    s32 bg_y;
};

static struct BgControl sGpuBgConfigs;
static struct BgConfig2 sGpuBgConfigs2[NUM_BACKGROUNDS];
static u32 sDmaBusyBitfield[NUM_BACKGROUNDS];
#if IS_FRLG
static u8 gpu_tile_allocation_map_bg[0x100];
#endif

COMMON_DATA u32 gWindowTileAutoAllocEnabled = 0;

static const struct BgConfig sZeroedBgControlStruct = { 0 };

static u32 GetBgType(u32 bg);

void ResetBgs(void)
{
    ResetBgControlStructs();
    sGpuBgConfigs.bgVisibilityAndMode = 0;
    SetTextModeAndHideBgs();
}

static void SetBgModeInternal(u32 bgMode)
{
    sGpuBgConfigs.bgVisibilityAndMode &= ~0x7;
    sGpuBgConfigs.bgVisibilityAndMode |= bgMode;
}

u32 GetBgMode(void)
{
    return sGpuBgConfigs.bgVisibilityAndMode & 0x7;
}

void ResetBgControlStructs(void)
{
    int i;

    for (i = 0; i < NUM_BACKGROUNDS; i++)
    {
        sGpuBgConfigs.configs[i] = sZeroedBgControlStruct;
    }
}

enum
{
    BG_CTRL_ATTR_VISIBLE = 1,
    BG_CTRL_ATTR_CHARBASEINDEX = 2,
    BG_CTRL_ATTR_MAPBASEINDEX = 3,
    BG_CTRL_ATTR_SCREENSIZE = 4,
    BG_CTRL_ATTR_PALETTEMODE = 5,
    BG_CTRL_ATTR_PRIORITY = 6,
    BG_CTRL_ATTR_MOSAIC = 7,
    BG_CTRL_ATTR_WRAPAROUND = 8,
};

static void SetBgControlAttributes(u32 bg, u8 charBaseIndex, u8 mapBaseIndex, u8 screenSize, u8 paletteMode, u8 priority, u8 mosaic, u8 wraparound)
{
    if (!IsInvalidBg(bg))
    {
        if (charBaseIndex != 0xFF)
        {
            sGpuBgConfigs.configs[bg].charBaseIndex = charBaseIndex;
        }

        if (mapBaseIndex != 0xFF)
        {
            sGpuBgConfigs.configs[bg].mapBaseIndex = mapBaseIndex;
        }

        if (screenSize != 0xFF)
        {
            sGpuBgConfigs.configs[bg].screenSize = screenSize;
        }

        if (paletteMode != 0xFF)
        {
            sGpuBgConfigs.configs[bg].paletteMode = paletteMode;
        }

        if (priority != 0xFF)
        {
            sGpuBgConfigs.configs[bg].priority = priority;
        }

        if (mosaic != 0xFF)
        {
            sGpuBgConfigs.configs[bg].mosaic = mosaic;
        }

        if (wraparound != 0xFF)
        {
            sGpuBgConfigs.configs[bg].wraparound = wraparound;
        }

        sGpuBgConfigs.configs[bg].visible = 1;
    }
}

static u16 GetBgControlAttribute(u32 bg, u32 attributeId)
{
    if (!IsInvalidBg(bg) && sGpuBgConfigs.configs[bg].visible)
    {
        switch (attributeId)
        {
        case BG_CTRL_ATTR_VISIBLE:
            return sGpuBgConfigs.configs[bg].visible;
        case BG_CTRL_ATTR_CHARBASEINDEX:
            return sGpuBgConfigs.configs[bg].charBaseIndex;
        case BG_CTRL_ATTR_MAPBASEINDEX:
            return sGpuBgConfigs.configs[bg].mapBaseIndex;
        case BG_CTRL_ATTR_SCREENSIZE:
            return sGpuBgConfigs.configs[bg].screenSize;
        case BG_CTRL_ATTR_PALETTEMODE:
            return sGpuBgConfigs.configs[bg].paletteMode;
        case BG_CTRL_ATTR_PRIORITY:
            return sGpuBgConfigs.configs[bg].priority;
        case BG_CTRL_ATTR_MOSAIC:
            return sGpuBgConfigs.configs[bg].mosaic;
        case BG_CTRL_ATTR_WRAPAROUND:
            return sGpuBgConfigs.configs[bg].wraparound;
        }
    }

    return 0xFF;
}

u8 LoadBgVram(u32 bg, const void *src, u16 size, u16 destOffset, u32 mode)
{
    u16 offset;
    s8 cursor;

    if (IsInvalidBg(bg) || !sGpuBgConfigs.configs[bg].visible)
        return -1;

    switch (mode)
    {
    case 0x1:
        offset = sGpuBgConfigs.configs[bg].charBaseIndex * BG_CHAR_SIZE;
        offset = destOffset + offset;
        cursor = RequestDma3Copy(src, (void *)(offset + BG_VRAM), size, 0);
        if (cursor == -1)
            return -1;
        break;
    case 0x2:
        offset = sGpuBgConfigs.configs[bg].mapBaseIndex * BG_SCREEN_SIZE;
        offset = destOffset + offset;
        cursor = RequestDma3Copy(src, (void *)(offset + BG_VRAM), size, 0);
        if (cursor == -1)
            return -1;
        break;
    default:
        cursor = -1;
        break;
    }

    return cursor;
}

static void ShowBgInternal(u32 bg)
{
    u16 value;
    if (!IsInvalidBg(bg) && sGpuBgConfigs.configs[bg].visible)
    {
        value = sGpuBgConfigs.configs[bg].priority |
                (sGpuBgConfigs.configs[bg].charBaseIndex << 2) |
                (sGpuBgConfigs.configs[bg].mosaic << 6) |
                (sGpuBgConfigs.configs[bg].paletteMode << 7) |
                (sGpuBgConfigs.configs[bg].mapBaseIndex << 8) |
                (sGpuBgConfigs.configs[bg].wraparound << 13) |
                (sGpuBgConfigs.configs[bg].screenSize << 14);

        SetGpuReg((bg << 1) + REG_OFFSET_BG0CNT, value);

        sGpuBgConfigs.bgVisibilityAndMode |= 1 << (bg + 8);
        sGpuBgConfigs.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
}

static void HideBgInternal(u32 bg)
{
    if (!IsInvalidBg(bg))
    {
        sGpuBgConfigs.bgVisibilityAndMode &= ~(1 << (bg + 8));
        sGpuBgConfigs.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
}

static void SyncBgVisibilityAndMode(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, (GetGpuReg(REG_OFFSET_DISPCNT) & ~DISPCNT_ALL_BG_AND_MODE_BITS) | sGpuBgConfigs.bgVisibilityAndMode);
}

void SetTextModeAndHideBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) & ~DISPCNT_ALL_BG_AND_MODE_BITS);
}

static void SetBgAffineInternal(u32 bg, s32 srcCenterX, s32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    switch (sGpuBgConfigs.bgVisibilityAndMode & 0x7)
    {
    default:
    case 0:
        return;
    case 1:
        if (bg != 2)
            return;
        break;
    case 2:
        if (bg != 2 && bg != 3)
            return;
        break;
    }

    src.texX = srcCenterX;
    src.texY = srcCenterY;
    src.scrX = dispCenterX;
    src.scrY = dispCenterY;
    src.sx = scaleX;
    src.sy = scaleY;
    src.alpha = rotationAngle;

    BgAffineSet(&src, &dest, 1);

    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2X_L, (s16)(dest.dx));
    SetGpuReg(REG_OFFSET_BG2X_H, (s16)(dest.dx >> 16));
    SetGpuReg(REG_OFFSET_BG2Y_L, (s16)(dest.dy));
    SetGpuReg(REG_OFFSET_BG2Y_H, (s16)(dest.dy >> 16));
}

bool32 IsInvalidBg(u32 bg)
{
    if (bg >= NUM_BACKGROUNDS)
        return TRUE;
    else
        return FALSE;
}

int BgTileAllocOp(int bg, int offset, int count, int mode)
{
    int result = BgTileAllocOpUnchecked(bg, offset, count, mode);
    fatal_assertf(result > 0);
    return result;
}

// From FRLG. Dummied out.
int BgTileAllocOpUnchecked(int bg, int offset, int count, int mode)
{
#if IS_FRLG
    int start, end;
    int blockSize;
    int blockStart;
    int i;

    switch (mode)
    {
    case 0:
        start = GetBgControlAttribute(bg, BG_CTRL_ATTR_CHARBASEINDEX) * (BG_CHAR_SIZE / TILE_SIZE_4BPP);
        end = start + 0x400;
        if (end > 0x800)
            end = 0x800;
        blockSize = 0;
        blockStart = 0;
        for (i = start, offset = 0; i < end; i++, offset++)
        {
            if (!((gpu_tile_allocation_map_bg[i / 8] >> (i % 8)) & 1))
            {
                if (blockSize)
                {
                    blockSize++;
                    if (blockSize == count)
                        return blockStart;
                }
                else
                {
                    blockStart = offset;
                    blockSize = 1;
                }
            }
            else
            {
                blockSize = 0;
            }
        }
        return -1;
    case 1:
        start = GetBgControlAttribute(bg, BG_CTRL_ATTR_CHARBASEINDEX) * (BG_CHAR_SIZE / TILE_SIZE_4BPP) + offset;
        end = start + count;
        for (i = start; i < end; i++)
            gpu_tile_allocation_map_bg[i / 8] |= 1 << (i % 8);
        break;
    case 2:
        start = GetBgControlAttribute(bg, BG_CTRL_ATTR_CHARBASEINDEX) * (BG_CHAR_SIZE / TILE_SIZE_4BPP) + offset;
        end = start + count;
        for (i = start; i < end; i++)
            gpu_tile_allocation_map_bg[i / 8] &= ~(1 << (i % 8));
        break;
    }
#endif
    return 0;
}

void ResetBgsAndClearDma3BusyFlags(u32 enableWindowTileAutoAlloc)
{
    int i;
    ResetBgs();

    for (i = 0; i < NUM_BACKGROUNDS; i++)
    {
        sDmaBusyBitfield[i] = 0;
    }

    gWindowTileAutoAllocEnabled = enableWindowTileAutoAlloc;

#if IS_FRLG
    for (i = 0; i < ARRAY_COUNT(gpu_tile_allocation_map_bg); i++)
    {
        gpu_tile_allocation_map_bg[i] = 0;
    }
#endif
}

void InitBgsFromTemplates(u32 bgMode, const struct BgTemplate *templates, u8 numTemplates)
{
    int i;
    u32 bg;

    SetBgModeInternal(bgMode);
    ResetBgControlStructs();

    for (i = 0; i < numTemplates; i++)
    {
        bg = templates[i].bg;
        if (bg < NUM_BACKGROUNDS)
        {
            SetBgControlAttributes(bg,
                                   templates[i].charBaseIndex,
                                   templates[i].mapBaseIndex,
                                   templates[i].screenSize,
                                   templates[i].paletteMode,
                                   templates[i].priority,
                                   0,
                                   0);

            sGpuBgConfigs2[bg].baseTile = templates[i].baseTile;
            sGpuBgConfigs2[bg].basePalette = 0;

            sGpuBgConfigs2[bg].tilemap = NULL;
            sGpuBgConfigs2[bg].bg_x = 0;
            sGpuBgConfigs2[bg].bg_y = 0;
#if IS_FRLG
            gpu_tile_allocation_map_bg[(templates[i].charBaseIndex * (BG_CHAR_SIZE / TILE_SIZE_4BPP)) / 8] = 1;
#endif
        }
    }
}

void InitBgFromTemplate(const struct BgTemplate *template)
{
    u32 bg = template->bg;

    if (bg < NUM_BACKGROUNDS)
    {
        SetBgControlAttributes(bg,
                               template->charBaseIndex,
                               template->mapBaseIndex,
                               template->screenSize,
                               template->paletteMode,
                               template->priority,
                               0,
                               0);

        sGpuBgConfigs2[bg].baseTile = template->baseTile;
        sGpuBgConfigs2[bg].basePalette = 0;

        sGpuBgConfigs2[bg].tilemap = NULL;
        sGpuBgConfigs2[bg].bg_x = 0;
        sGpuBgConfigs2[bg].bg_y = 0;
#if IS_FRLG
        gpu_tile_allocation_map_bg[(template->charBaseIndex * (BG_CHAR_SIZE / TILE_SIZE_4BPP)) / 8] = 1;
#endif
    }
}

void SetBgMode(u32 bgMode)
{
    SetBgModeInternal(bgMode);
}

u16 LoadBgTiles(u32 bg, const void *src, u16 size, u16 destOffset)
{
    u16 tileOffset;
    u8 cursor;

    if (bg > 3)
        return -1;

    if (GetBgControlAttribute(bg, BG_CTRL_ATTR_PALETTEMODE) == 0)
    {
        tileOffset = (sGpuBgConfigs2[bg].baseTile + destOffset) * 0x20;
    }
    else
    {
        tileOffset = (sGpuBgConfigs2[bg].baseTile + destOffset) * 0x40;
    }

    cursor = LoadBgVram(bg, src, size, tileOffset, DISPCNT_MODE_1);

    if (cursor == 0xFF)
    {
        return -1;
    }

    sDmaBusyBitfield[cursor / 0x20] |= (1 << (cursor % 0x20));

    if (gWindowTileAutoAllocEnabled == TRUE)
        BgTileAllocOp(bg, tileOffset / 0x20, size / 0x20, 1);

    return cursor;
}

u16 LoadBgTilemap(u32 bg, const void *src, u16 size, u16 destOffset)
{
    u8 cursor = LoadBgVram(bg, src, size, destOffset * 2, DISPCNT_MODE_2);

    if (cursor == 0xFF)
    {
        return -1;
    }

    sDmaBusyBitfield[cursor / 0x20] |= (1 << (cursor % 0x20));

    return cursor;
}

bool32 IsDma3ManagerBusyWithBgCopy(void)
{
    int i;

    for (i = 0; i < 0x80; i++)
    {
        u8 div = i / 0x20;
        u8 mod = i % 0x20;

        if ((sDmaBusyBitfield[div] & (1 << mod)))
        {
            s8 reqSpace = CheckForSpaceForDma3Request(i);
            if (reqSpace == -1)
            {
                return TRUE;
            }

            sDmaBusyBitfield[div] &= ~(1 << mod);
        }
    }

    return FALSE;
}

void ShowBg(u32 bg)
{
    ShowBgInternal(bg);
    SyncBgVisibilityAndMode();
}

void HideBg(u32 bg)
{
    HideBgInternal(bg);
    SyncBgVisibilityAndMode();
}

void SetBgAttribute(u32 bg, u32 attributeId, u8 value)
{
    switch (attributeId)
    {
    case BG_ATTR_CHARBASEINDEX:
        SetBgControlAttributes(bg, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_MAPBASEINDEX:
        SetBgControlAttributes(bg, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_SCREENSIZE:
        SetBgControlAttributes(bg, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_PALETTEMODE:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_PRIORITY:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF);
        break;
    case BG_ATTR_MOSAIC:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF);
        break;
    case BG_ATTR_WRAPAROUND:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value);
        break;
    }
}

u16 GetBgAttribute(u32 bg, u32 attributeId)
{
    switch (attributeId)
    {
    case BG_ATTR_CHARBASEINDEX:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_CHARBASEINDEX);
    case BG_ATTR_MAPBASEINDEX:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_MAPBASEINDEX);
    case BG_ATTR_SCREENSIZE:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
    case BG_ATTR_PALETTEMODE:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_PALETTEMODE);
    case BG_ATTR_PRIORITY:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_PRIORITY);
    case BG_ATTR_MOSAIC:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_MOSAIC);
    case BG_ATTR_WRAPAROUND:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_WRAPAROUND);
    case BG_ATTR_METRIC:
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            return GetBgMetricTextMode(bg, 0) * 0x800;
        case BG_TYPE_AFFINE:
            return GetBgMetricAffineMode(bg, 0) * 0x100;
        default:
            return 0;
        }
    case BG_ATTR_TYPE:
        return GetBgType(bg);
    case BG_ATTR_BASETILE:
        return sGpuBgConfigs2[bg].baseTile;
    default:
        return -1;
    }
}

s32 ChangeBgX(u32 bg, s32 value, u8 op)
{
    u32 mode;
    u16 temp1;
    u16 temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_x = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_x += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_x -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_x >> 0x8;
        SetGpuReg(REG_OFFSET_BG0HOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_x >> 0x8;
        SetGpuReg(REG_OFFSET_BG1HOFS, temp1);
        break;
    case 2:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[2].bg_x >> 0x8;
            SetGpuReg(REG_OFFSET_BG2HOFS, temp1);
        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_x >> 0x10;
            temp2 = sGpuBgConfigs2[2].bg_x & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG2X_H, temp1);
            SetGpuReg(REG_OFFSET_BG2X_L, temp2);
        }
        break;
    case 3:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[3].bg_x >> 0x8;
            SetGpuReg(REG_OFFSET_BG3HOFS, temp1);
        }
        else if (mode == 2)
        {
            temp1 = sGpuBgConfigs2[3].bg_x >> 0x10;
            temp2 = sGpuBgConfigs2[3].bg_x & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG3X_H, temp1);
            SetGpuReg(REG_OFFSET_BG3X_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_x;
}

s32 GetBgX(u32 bg)
{
    if (IsInvalidBg(bg))
        return -1;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return -1;
    else
        return sGpuBgConfigs2[bg].bg_x;
}

s32 ChangeBgY(u32 bg, s32 value, u8 op)
{
    u32 mode;
    u16 temp1;
    u16 temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_y = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_y += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_y -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_y >> 0x8;
        SetGpuReg(REG_OFFSET_BG0VOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_y >> 0x8;
        SetGpuReg(REG_OFFSET_BG1VOFS, temp1);
        break;
    case 2:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 0x8;
            SetGpuReg(REG_OFFSET_BG2VOFS, temp1);
        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 0x10;
            temp2 = sGpuBgConfigs2[2].bg_y & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG2Y_H, temp1);
            SetGpuReg(REG_OFFSET_BG2Y_L, temp2);
        }
        break;
    case 3:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 0x8;
            SetGpuReg(REG_OFFSET_BG3VOFS, temp1);
        }
        else if (mode == 2)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 0x10;
            temp2 = sGpuBgConfigs2[3].bg_y & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG3Y_H, temp1);
            SetGpuReg(REG_OFFSET_BG3Y_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_y;
}

s32 ChangeBgY_ScreenOff(u32 bg, s32 value, u8 op)
{
    u32 mode;
    u16 temp1;
    u16 temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_y = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_y += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_y -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_y >> 0x8;
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_y >> 0x8;
        SetGpuReg_ForcedBlank(REG_OFFSET_BG1VOFS, temp1);
        break;
    case 2:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 0x8;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2VOFS, temp1);

        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 0x10;
            temp2 = sGpuBgConfigs2[2].bg_y & 0xFFFF;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_H, temp1);
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_L, temp2);
        }
        break;
    case 3:
        if (mode == 0)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 0x8;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3VOFS, temp1);
        }
        else if (mode == 2)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 0x10;
            temp2 = sGpuBgConfigs2[3].bg_y & 0xFFFF;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_H, temp1);
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_y;
}

s32 GetBgY(u32 bg)
{
    if (IsInvalidBg(bg))
        return -1;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return -1;
    else
        return sGpuBgConfigs2[bg].bg_y;
}

void SetBgAffine(u32 bg, s32 srcCenterX, s32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle)
{
    SetBgAffineInternal(bg, srcCenterX, srcCenterY, dispCenterX, dispCenterY, scaleX, scaleY, rotationAngle);
}

void SetBgTilemapBuffer(u32 bg, void *tilemap)
{
    if (!IsInvalidBg(bg) && GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        sGpuBgConfigs2[bg].tilemap = tilemap;
    }
}

void UnsetBgTilemapBuffer(u32 bg)
{
    if (!IsInvalidBg(bg) && GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        sGpuBgConfigs2[bg].tilemap = NULL;
    }
}

void *GetBgTilemapBuffer(u32 bg)
{
    if (IsInvalidBg(bg))
        return NULL;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return NULL;
    else
        return sGpuBgConfigs2[bg].tilemap;
}

void CopyToBgTilemapBuffer(u32 bg, const void *src, u32 mode, u32 destOffset)
{
    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        if (mode != 0)
            CpuCopy16(src, (void *)(sGpuBgConfigs2[bg].tilemap + (destOffset * 2)), mode);
        else
            DecompressDataWithHeaderWram(src, (void *)(sGpuBgConfigs2[bg].tilemap + (destOffset * 2)));
    }
}

void DecompressAndCopyToBgTilemapBuffer(u32 bg, const u32 *src, u32 mode, u32 destOffset)
{
    void *buffer = malloc_and_decompress(src, NULL);

    CopyToBgTilemapBuffer(bg, buffer, mode, destOffset);
    Free(buffer);
}

void CopyBgTilemapBufferToVram(u32 bg)
{
    u16 sizeToLoad;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            sizeToLoad = GetBgMetricTextMode(bg, 0) * 0x800;
            break;
        case BG_TYPE_AFFINE:
            sizeToLoad = GetBgMetricAffineMode(bg, 0) * 0x100;
            break;
        default:
            sizeToLoad = 0;
            break;
        }
        LoadBgVram(bg, sGpuBgConfigs2[bg].tilemap, sizeToLoad, 0, 2);
    }
}

void CopyToBgTilemapBufferRect(u32 bg, const void *src, u8 destX, u8 destY, u8 width, u8 height)
{
    u16 mode;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
        {
            const u16 *srcCopy = src;
            for (u32 j = destY; j < (destY + height); j++)
            {
                for (u32 i = destX; i < (destX + width); i++)
                {
                    ((u16 *)sGpuBgConfigs2[bg].tilemap)[((j * 0x20) + i)] = *srcCopy++;
                }
            }
            break;
        }
        case BG_TYPE_AFFINE:
        {
            const u8 *srcCopy = src;
            mode = GetBgMetricAffineMode(bg, 0x1);
            for (u32 j = destY; j < (destY + height); j++)
            {
                for (u32 i = destX; i < (destX + width); i++)
                {
                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[((j * mode) + i)] = *srcCopy++;
                }
            }
            break;
        }
        }
    }
}

void CopyToBgTilemapBufferRect_ChangePalette(u32 bg, const void *src, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette)
{
    CopyRectToBgTilemapBufferRect(bg, src, 0, 0, rectWidth, rectHeight, destX, destY, rectWidth, rectHeight, palette, 0, 0);
}

void CopyRectToBgTilemapBufferRect(u32 bg, const void *src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette1, s16 tileOffset, s16 palette2)
{
    u16 screenWidth, screenHeight, screenSize;
    u16 var;
    const void *srcPtr;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
        screenWidth = GetBgMetricTextMode(bg, 0x1) * 0x20;
        screenHeight = GetBgMetricTextMode(bg, 0x2) * 0x20;
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            srcPtr = src + ((srcY * srcWidth) + srcX) * 2;
            for (u32 j = destY; j < (destY + rectHeight); j++)
            {
                for (u32 i = destX; i < (destX + rectWidth); i++)
                {
                    u16 index = GetTileMapIndexFromCoords(i, j, screenSize, screenWidth, screenHeight);
                    CopyTileMapEntry(srcPtr, sGpuBgConfigs2[bg].tilemap + (index * 2), palette1, tileOffset, palette2);
                    srcPtr += 2;
                }
                srcPtr += (srcWidth - rectWidth) * 2;
            }
            break;
        case BG_TYPE_AFFINE:
            srcPtr = src + ((srcY * srcWidth) + srcX);
            var = GetBgMetricAffineMode(bg, 0x1);
            for (u32 j = destY; j < (destY + rectHeight); j++)
            {
                for (u32 i = destX; i < (destX + rectWidth); i++)
                {
                    *(u8 *)(sGpuBgConfigs2[bg].tilemap + ((var * j) + i)) = *(u8 *)(srcPtr) + tileOffset;
                    srcPtr++;
                }
                srcPtr += (srcWidth - rectWidth);
            }
            break;
        }
    }
}

void FillBgTilemapBufferRect_Palette0(u32 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height)
{
    u16 mode;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    ((u16 *)sGpuBgConfigs2[bg].tilemap)[((j * 0x20) + i)] = tileNum;
                }
            }
            break;
        case BG_TYPE_AFFINE:
            mode = GetBgMetricAffineMode(bg, 0x1);
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[((j * mode) + i)] = tileNum;
                }
            }
            break;
        }
    }
}

void FillBgTilemapBufferRect(u32 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height, u8 palette)
{
    WriteSequenceToBgTilemapBuffer(bg, tileNum, x, y, width, height, palette, 0);
}

void WriteSequenceToBgTilemapBuffer(u32 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, s16 tileNumDelta)
{
    u16 mode;
    u16 mode2;
    u16 attribute;
    u16 mode3;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        attribute = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
        mode = GetBgMetricTextMode(bg, 0x1) * 0x20;
        mode2 = GetBgMetricTextMode(bg, 0x2) * 0x20;
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    CopyTileMapEntry(&firstTileNum, &((u16 *)sGpuBgConfigs2[bg].tilemap)[(u16)GetTileMapIndexFromCoords(i, j, attribute, mode, mode2)], paletteSlot, 0, 0);
                    firstTileNum = (firstTileNum & 0xFC00) + ((firstTileNum + tileNumDelta) & 0x3FF);
                }
            }
            break;
        case BG_TYPE_AFFINE:
            mode3 = GetBgMetricAffineMode(bg, 0x1);
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[(j * mode3) + i] = firstTileNum;
                    firstTileNum = (firstTileNum & 0xFC00) + ((firstTileNum + tileNumDelta) & 0x3FF);
                }
            }
            break;
        }
    }
}

u16 GetBgMetricTextMode(u32 bg, u32 whichMetric)
{
    u8 screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);

    switch (whichMetric)
    {
    case 0:
        switch (screenSize)
        {
        case 0:
            return 1;
        case 1:
        case 2:
            return 2;
        case 3:
            return 4;
        }
        break;
    case 1:
        switch (screenSize)
        {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        }
        break;
    case 2:
        switch (screenSize)
        {
        case 0:
        case 1:
            return 1;
        case 2:
        case 3:
            return 2;
        }
        break;
    }
    return 0;
}

u32 GetBgMetricAffineMode(u32 bg, u32 whichMetric)
{
    u8 screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);

    switch (whichMetric)
    {
    case 0:
        switch (screenSize)
        {
        case 0:
            return 0x1;
        case 1:
            return 0x4;
        case 2:
            return 0x10;
        case 3:
            return 0x40;
        }
        break;
    case 1:
    case 2:
        return 0x10 << screenSize;
    }
    return 0;
}

u32 GetTileMapIndexFromCoords(s32 x, s32 y, s32 screenSize, u32 screenWidth, u32 screenHeight)
{
    x = x & (screenWidth - 1);
    y = y & (screenHeight - 1);

    switch (screenSize)
    {
    case 0:
    case 2:
        break;
    case 3:
        if (y >= 0x20)
            y += 0x20;
    case 1:
        if (x >= 0x20)
        {
            x -= 0x20;
            y += 0x20;
        }
        break;
    }
    return (y * 0x20) + x;
}

void CopyTileMapEntry(const u16 *src, u16 *dest, s32 palette1, s32 tileOffset, s32 palette2)
{
    u16 var;

    switch (palette1)
    {
    case 0 ... 15:
        var = ((*src + tileOffset) & 0xFFF) + ((palette1 + palette2) << 12);
        break;
    case 16:
        var = *dest;
        var &= 0xFC00;
        var += palette2 << 12;
        var |= (*src + tileOffset) & 0x3FF;
        break;
    default:
    case 17:
        var = *src + tileOffset + (palette2 << 12);
        break;
    }
    *dest = var;
}

static u32 GetBgType(u32 bg)
{
    u32 mode = GetBgMode();

    switch (bg)
    {
    case 0:
    case 1:
        switch (mode)
        {
        case 0:
        case 1:
            return BG_TYPE_NORMAL;
        }
        break;
    case 2:
        switch (mode)
        {
        case 0:
            return BG_TYPE_NORMAL;
        case 1:
        case 2:
            return BG_TYPE_AFFINE;
        }
        break;
    case 3:
        switch (mode)
        {
        case 0:
            return BG_TYPE_NORMAL;
        case 2:
            return BG_TYPE_AFFINE;
        }
        break;
    }

    return BG_TYPE_NONE;
}

bool32 IsTileMapOutsideWram(u32 bg)
{
    if (sGpuBgConfigs2[bg].tilemap > (void *)IWRAM_END)
        return TRUE;
    else if (sGpuBgConfigs2[bg].tilemap == NULL)
        return TRUE;
    else
        return FALSE;
}

#include "global.h"
#include "dma3.h"

#define DISPCNT_ALL_BG_AND_MODE_BITS    0x0F07
#define SECONDARY_TILESET_BASE_TILE     0x4000
#define SECONDARY_TILESET_BASE_BLOCK    0x800

struct BgControl {
    struct BgConfig {
        u16 visible:1;
        u16 unknown_1:1;
        u16 screenSize:2;
        u16 priority:2;
        u16 mosaic:1;
        u16 wraparound:1;
        
        u16 tilesBaseBlock:2;
        u16 tileMapBaseBlock:5;
        u16 paletteMode:1;
        
        u8 unknown_2;
        u8 unknown_3;
    } configs[4];
    
    u16 bgVisibilityAndMode;
};

struct BgTemplate {
    u32 bg:2;
    u32 tilesBaseBlock:2;
    u32 tileMapBaseBlock:5;
    u32 screenSize:2;
    u32 paletteMode:1;
    u32 priority:2;
    u32 unk_1:10;
};

struct BgConfig2 {
    u32 unk_1:10;
    u32 unk_2:4;
    u32 unk_3:18;
    
    void* tilemap;
    u32 bg_x;
    u32 bg_y;
};

extern struct BgControl gUnknown_030008E0;    // gGpuBgConfigs
extern struct BgConfig2 gUnknown_030008F8[4]; // gGpuBgConfigs2
extern u32 gUnknown_03000938[4];
extern u32 gUnneededFireRedVariable;
extern struct BgConfig gZeroedBgControlStruct;
extern bool32 IsInvalidBgDuplicate(u8 bg);

void ResetBgControlStructs();
u16 GetBgMetricTextMode(u8 bg, u8 whichMetric);
u16 GetBgMetricAffineMode(u8 bg, u8 whichMetric);
u32 GetBgType(u8 bg);
void SetTextModeAndHideBgs();
bool8 IsInvalidBg(u8 bg);
bool32 IsTileMapOutsideWram(u8 bg);
void CopyRectToBgTilemapBufferRect(u8 bg, void *src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette1, u16 tileOffset, u16 palette2);
void CopyTileMapEntry(u16 *src, u16 *dest, s32 palette1, u16 tileOffset, u32 palette2);
u32 GetTileMapIndexFromCoords(u32 x, u32 y, u32 screenSize, u32 screenWidth, u32 screenHeight);

extern void SetGpuReg(u8 regOffset, u16 value);
extern void SetGpuReg_ForcedBlank(u8 regOffset, u16 value);
extern u16 GetGpuReg(u8 regOffset);
extern int CheckForSpaceForDma3Request(s16 index);

void ResetBgs(void)
{
    ResetBgControlStructs();
    gUnknown_030008E0.bgVisibilityAndMode = 0;
    SetTextModeAndHideBgs();
}

void SetBgModeInternal(u8 bgMode)
{
    gUnknown_030008E0.bgVisibilityAndMode &= 0xFFF8;
    gUnknown_030008E0.bgVisibilityAndMode |= bgMode;
}

u8 GetBgMode(void)
{
    return gUnknown_030008E0.bgVisibilityAndMode & 0x7;
}

void ResetBgControlStructs(void)
{
    struct BgConfig* bgConfigs = &gUnknown_030008E0.configs[0];
    struct BgConfig zeroedConfig = gZeroedBgControlStruct;
    int i;
    
    for (i = 0; i < 4; i++)
    {
        bgConfigs[i] = zeroedConfig;
    }
}

void Unused_ResetBgControlStruct(u8 bg)
{
    if (IsInvalidBg(bg) == FALSE)
    {
        gUnknown_030008E0.configs[bg] = gZeroedBgControlStruct;
    }
}

void SetBgControlAttributes(u8 bg, u8 tilesBaseBlock, u8 tileMapBaseBlock, u8 screenSize, u8 paletteMode, u8 priority, u8 mosaic, u8 wraparound)
{
    if (IsInvalidBg(bg) == FALSE)
    {
        if (tilesBaseBlock != 0xFF)
        {
            gUnknown_030008E0.configs[bg].tilesBaseBlock = tilesBaseBlock & 0x3;
        }
        
        if (tileMapBaseBlock != 0xFF)
        {
            gUnknown_030008E0.configs[bg].tileMapBaseBlock = tileMapBaseBlock & 0x1F;
        }
        
        if (screenSize != 0xFF)
        {
            gUnknown_030008E0.configs[bg].screenSize = screenSize & 0x3;
        }
        
        if (paletteMode != 0xFF)
        {
            gUnknown_030008E0.configs[bg].paletteMode = paletteMode;
        }
        
        if (priority != 0xFF)
        {
            gUnknown_030008E0.configs[bg].priority = priority & 0x3;
        }
        
        if (mosaic != 0xFF)
        {
            gUnknown_030008E0.configs[bg].mosaic = mosaic & 0x1;
        }
        
        if (wraparound != 0xFF)
        {
            gUnknown_030008E0.configs[bg].wraparound = wraparound;
        }
        
        gUnknown_030008E0.configs[bg].unknown_2 = 0;
        gUnknown_030008E0.configs[bg].unknown_3 = 0;
        
        gUnknown_030008E0.configs[bg].visible = 1;
    }
}

u16 GetBgControlAttribute(u8 bg, u8 attributeId)
{
    if (IsInvalidBg(bg) == FALSE && gUnknown_030008E0.configs[bg].visible != FALSE)
    {
        switch (attributeId)
        {
            case 1:
                return gUnknown_030008E0.configs[bg].visible;
            case 2:
                return gUnknown_030008E0.configs[bg].tilesBaseBlock;
            case 3:
                return gUnknown_030008E0.configs[bg].tileMapBaseBlock;
            case 4:
                return gUnknown_030008E0.configs[bg].screenSize;
            case 5:
                return gUnknown_030008E0.configs[bg].paletteMode;
            case 6:
                return gUnknown_030008E0.configs[bg].priority;
            case 7:
                return gUnknown_030008E0.configs[bg].mosaic;
            case 8:
                return gUnknown_030008E0.configs[bg].wraparound;
        }
    }
    
    return 0xFF;
}

u8 LoadBgVram(u8 bg, void *src, u16 size, u16 destOffset, u8 mode)
{
    u16 offset;
    s8 cursor;
    
    if (IsInvalidBg(bg) == FALSE && gUnknown_030008E0.configs[bg].visible != FALSE)
    {
        switch (mode)
        {
            case 0x1:
                offset = gUnknown_030008E0.configs[bg].tilesBaseBlock * SECONDARY_TILESET_BASE_TILE;
                break;
            case 0x2:
                offset = gUnknown_030008E0.configs[bg].tileMapBaseBlock * SECONDARY_TILESET_BASE_BLOCK;
                break;
            default:
                cursor = -1;
                goto end;
        }
        
        offset = destOffset + offset;
        
        cursor = RequestDma3Copy(src, (void*)(offset + BG_VRAM), size, 0);
        
        if (cursor == -1)
        {
            return -1;
        }
    }
    else
    {
       return -1;
    }
    
end:
    return cursor;
}

void ShowBgInternal(u8 bg)
{
    u16 value;
    if (IsInvalidBg(bg) == FALSE && gUnknown_030008E0.configs[bg].visible != FALSE)
    {
        value = gUnknown_030008E0.configs[bg].priority |
                (gUnknown_030008E0.configs[bg].tilesBaseBlock << 2) |
                (gUnknown_030008E0.configs[bg].mosaic << 6) |
                (gUnknown_030008E0.configs[bg].paletteMode << 7) |
                (gUnknown_030008E0.configs[bg].tileMapBaseBlock << 8) |
                (gUnknown_030008E0.configs[bg].wraparound << 13) |
                (gUnknown_030008E0.configs[bg].screenSize << 14);
        
        SetGpuReg((bg << 1) + 0x8, value);
        
        gUnknown_030008E0.bgVisibilityAndMode |= 1 << (bg + 8);
        gUnknown_030008E0.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
}

void HideBgInternal(u8 bg)
{
    if (IsInvalidBg(bg) == FALSE)
    {
        gUnknown_030008E0.bgVisibilityAndMode &= ~(1 << (bg + 8));
        gUnknown_030008E0.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
}

void SyncBgVisibilityAndMode()
{
    SetGpuReg(0, (GetGpuReg(0) & ~DISPCNT_ALL_BG_AND_MODE_BITS) | gUnknown_030008E0.bgVisibilityAndMode);
}

void SetTextModeAndHideBgs()
{
    SetGpuReg(0, GetGpuReg(0) & ~DISPCNT_ALL_BG_AND_MODE_BITS);
}

void SetBgAffineInternal(u8 bg, u32 srcCenterX, u32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;
    
    switch (gUnknown_030008E0.bgVisibilityAndMode & 0x7)
    {
        case 1:
            if (bg != 2)
                return;
            break;
        case 2:
            if (bg < 2 || bg > 3)
                return;
            break;
        case 0:
        default:
            return;
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

bool8 IsInvalidBg(u8 bg)
{
    if (bg > 3)
        return TRUE;
    return FALSE;
}

int DummiedOutFireRedLeafGreenTileAllocFunc(int a1, int a2, int a3, int a4)
{
    return 0;
}

void ResetBgsAndClearDma3BusyFlags(u32 leftoverFireRedLeafGreenVariable)
{
    int i;
    ResetBgs();
    
    for (i = 0; i < 4; i++)
    {
        gUnknown_03000938[i] = 0;
    }
    
    gUnneededFireRedVariable = leftoverFireRedLeafGreenVariable;
}

void InitBgsFromTemplates(u8 bgMode, struct BgTemplate *templates, u8 numTemplates)
{
    int i;
    u8 bg;
    
    SetBgModeInternal(bgMode);
    ResetBgControlStructs();

    for (i = 0; i < numTemplates; i++)
    {
        bg = templates[i].bg;
        if (bg < 4) {
            SetBgControlAttributes(bg,
                                   templates[i].tilesBaseBlock,
                                   templates[i].tileMapBaseBlock,
                                   templates[i].screenSize,
                                   templates[i].paletteMode,
                                   templates[i].priority,
                                   0,
                                   0);
            
            gUnknown_030008F8[bg].unk_1 = templates[i].unk_1;
            gUnknown_030008F8[bg].unk_2 = 0;
            gUnknown_030008F8[bg].unk_3 = 0;
            
            gUnknown_030008F8[bg].tilemap = NULL;
            gUnknown_030008F8[bg].bg_x = 0;
            gUnknown_030008F8[bg].bg_y = 0;
        }
    }
}

void InitBgFromTemplate(struct BgTemplate *template)
{
    u8 bg = template->bg;
    
    if (bg < 4)
    {
        SetBgControlAttributes(bg,
                               template->tilesBaseBlock,
                               template->tileMapBaseBlock,
                               template->screenSize,
                               template->paletteMode,
                               template->priority,
                               0,
                               0);
        
        gUnknown_030008F8[bg].unk_1 = template->unk_1;
        gUnknown_030008F8[bg].unk_2 = 0;
        gUnknown_030008F8[bg].unk_3 = 0;
        
        gUnknown_030008F8[bg].tilemap = NULL;
        gUnknown_030008F8[bg].bg_x = 0;
        gUnknown_030008F8[bg].bg_y = 0;
    }
}

void SetBgMode(u8 bgMode)
{
    SetBgModeInternal(bgMode);
}

u16 LoadBgTiles(u8 bg, void *src, u16 size, u16 destOffset)
{
    u16 unk;
    u8 cursor;
    
    if (GetBgControlAttribute(bg, 5) == 0)
    {
        unk = (gUnknown_030008F8[bg].unk_1 + destOffset) * 0x20;
    }
    else
    {
        unk = (gUnknown_030008F8[bg].unk_1 + destOffset) * 0x40;
    }
    
    cursor = LoadBgVram(bg, src, size, unk, DISPCNT_MODE_1);
    
    if (cursor == 0xFF)
    {
        return -1;
    }
    
    gUnknown_03000938[cursor / 0x20] |= (1 << (cursor % 0x20));
    
    if (gUnneededFireRedVariable == 1)
    {
        DummiedOutFireRedLeafGreenTileAllocFunc(bg, unk / 0x20, size / 0x20, 1);
    }
    
    return cursor;
}

u16 LoadBgTilemap(u8 bg, void *src, u16 size, u16 destOffset)
{
    u8 cursor;
    
    cursor = LoadBgVram(bg, src, size, destOffset * 2, DISPCNT_MODE_2);
    
    if (cursor == 0xFF)
    {
        return -1;
    }
    
    gUnknown_03000938[cursor / 0x20] |= (1 << (cursor % 0x20));
    
    return cursor;
}

u16 Unused_LoadBgPalette(u8 bg, void *src, u16 size, u16 destOffset)
{
    u16 unk_1;
    s8 cursor;
    
    if (IsInvalidBgDuplicate(bg) == FALSE)
    {
        unk_1 = (gUnknown_030008F8[bg].unk_2 * 0x20) + (destOffset * 2);
        cursor = RequestDma3Copy(src, (void*)(unk_1 + BG_PLTT), size, 0);
        
        if (cursor == -1)
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    gUnknown_03000938[cursor / 0x20] |= (1 << (cursor % 0x20));

    return (u8)cursor;
}

#ifdef NONMATCHING  // Matches everything but r5 and r6 are flipped, rrr
bool8 IsDma3ManagerBusyWithBgCopy(void)
{
    u8 mod;
    u8 div;
    s8 reqSpace;
    
    int i;
    
    for (i = 0; i < 0x80; i++)
    {
        div = i / 0x20;
        mod = i % 0x20;
        
        if ((gUnknown_03000938[div] & (1 << mod)) != FALSE)
        {
            reqSpace = CheckForSpaceForDma3Request(i);
            if (reqSpace == -1)
            {
                return TRUE;
            }
            
            gUnknown_03000938[div] &= ~(1 << mod);
        }
    }

    return FALSE;
}
#else
__attribute__((naked))
bool8 IsDma3ManagerBusyWithBgCopy(void)
{
    asm("push {r4-r7,lr}\n\
    mov r5, #0\n\
    mov r7, #0x1\n\
    neg r7, r7\n\
_08001ADC:\n\
    add r0, r5, #0\n\
    cmp r5, #0\n\
    bge _08001AE4\n\
    add r0, #0x1F\n\
_08001AE4:\n\
    asr r0, #5\n\
    lsl r2, r0, #24\n\
    lsl r0, #5\n\
    sub r0, r5, r0\n\
    lsl r0, #24\n\
    lsr r0, #24\n\
    ldr r1, =gUnknown_03000938\n\
    lsr r2, #22\n\
    add r4, r2, r1\n\
    mov r6, #0x1\n\
    lsl r6, r0\n\
    ldr r0, [r4]\n\
    and r0, r6\n\
    cmp r0, #0\n\
    beq _08001B22\n\
    lsl r0, r5, #16\n\
    asr r0, #16\n\
    bl CheckForSpaceForDma3Request\n\
    lsl r0, #24\n\
    asr r0, #24\n\
    cmp r0, r7\n\
    bne _08001B1C\n\
    mov r0, #0x1\n\
    b _08001B2A\n\
    .pool\n\
_08001B1C:\n\
    ldr r0, [r4]\n\
    bic r0, r6\n\
    str r0, [r4]\n\
_08001B22:\n\
    add r5, #0x1\n\
    cmp r5, #0x7F\n\
    ble _08001ADC\n\
    mov r0, #0\n\
_08001B2A:\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n");
}
#endif // NONMATCHING

void ShowBg(u8 bg)
{
    ShowBgInternal(bg);
    SyncBgVisibilityAndMode();
}

void HideBg(u8 bg)
{
    HideBgInternal(bg);
    SyncBgVisibilityAndMode();
}

void SetBgAttribute(u8 bg, u8 attributeId, u8 value)
{
    switch (attributeId)
    {
        case 1:
            SetBgControlAttributes(bg, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            break;
        case 2:
            SetBgControlAttributes(bg, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            break;
        case 3:
            SetBgControlAttributes(bg, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF);
            break;
        case 4:
            SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF);
            break;
        case 7:
            SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF);
            break;
        case 5:
            SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF);
            break;
        case 6:
            SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value);
            break;
    }
}

u16 GetBgAttribute(u8 bg, u8 attributeId)
{
    switch (attributeId)
    {
        case 1:
            return GetBgControlAttribute(bg, 2);
        case 2:
            return GetBgControlAttribute(bg, 3);
        case 3:
            return GetBgControlAttribute(bg, 4);
        case 4:
            return GetBgControlAttribute(bg, 5);
        case 7:
            return GetBgControlAttribute(bg, 6);
        case 5:
            return GetBgControlAttribute(bg, 7);
        case 6:
            return GetBgControlAttribute(bg, 8);
        case 8:
            switch (GetBgType(bg))
            {
                case 0:
                    return GetBgMetricTextMode(bg, 0) * 0x800;
                case 1:
                    return GetBgMetricAffineMode(bg, 0) * 0x100;
                default:
                    return 0;
            }
        case 9:
            return GetBgType(bg);
        case 10:
            return gUnknown_030008F8[bg].unk_1;
        default:
            return -1;
    }
}

#ifdef NONMATCHING  // Everything that uses temp1 doesn't match
u32 ChangeBgX(u8 bg, u32 value, u8 op)
{
    u8 mode;
    u32 temp1;
    
    if (IsInvalidBgDuplicate(bg) != FALSE || GetBgControlAttribute(bg, 1) == 0)
    {
        return -1;
    }
    
    switch (op)
    {
        case 0:
        default:
            gUnknown_030008F8[bg].bg_x = value;
            break;
        case 1:
            gUnknown_030008F8[bg].bg_x += value;
            break;
        case 2:
            gUnknown_030008F8[bg].bg_x -= value;
            break;
    }
    
    mode = GetBgMode();
    
    switch (bg)
    {
        case 0:
            SetGpuReg(REG_OFFSET_BG0HOFS, gUnknown_030008F8[0].bg_x >> 0x8);
            break;
        case 1:
            SetGpuReg(REG_OFFSET_BG1HOFS, gUnknown_030008F8[1].bg_x >> 0x8);
            break;
        case 2:
            if (mode == 0)
            {
                SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_030008F8[2].bg_x >> 0x8);
            }
            else
            {
                temp1 = gUnknown_030008F8[2].bg_x;
                SetGpuReg(REG_OFFSET_BG2X_H, (u16)(temp1 >> 0x10));
                SetGpuReg(REG_OFFSET_BG2X_L, (u16)(temp1));
            }
            break;
        case 3:
            if (mode == 0)
            {
                SetGpuReg(REG_OFFSET_BG3HOFS, gUnknown_030008F8[3].bg_x >> 0x8);
            }
            else if (mode == 2)
            {
                temp1 = gUnknown_030008F8[3].bg_x;
                SetGpuReg(REG_OFFSET_BG2X_H, (u16)(temp1 >> 0x10));
                SetGpuReg(REG_OFFSET_BG2X_L, (u16)(temp1));
            }
            break;
    }
    
    return gUnknown_030008F8[bg].bg_x;
}
#else
__attribute__((naked))
u32 ChangeBgX(u8 bg, u32 value, u8 op)
{
    asm("push {r4-r6,lr}\n\
    add r6, r1, #0\n\
    lsl r0, #24\n\
    lsr r4, r0, #24\n\
    lsl r2, #24\n\
    lsr r5, r2, #24\n\
    add r0, r4, #0\n\
    bl IsInvalidBgDuplicate\n\
    cmp r0, #0\n\
    bne _08001D28\n\
    add r0, r4, #0\n\
    mov r1, #0x1\n\
    bl GetBgControlAttribute\n\
    lsl r0, #16\n\
    cmp r0, #0\n\
    bne _08001D2E\n\
_08001D28:\n\
    mov r0, #0x1\n\
    neg r0, r0\n\
    b _08001E34\n\
_08001D2E:\n\
    cmp r5, #0x1\n\
    beq _08001D4C\n\
    cmp r5, #0x1\n\
    ble _08001D3A\n\
    cmp r5, #0x2\n\
    beq _08001D60\n\
_08001D3A:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r1, r4, #4\n\
    add r0, #0x8\n\
    add r0, r1, r0\n\
    str r6, [r0]\n\
    add r5, r1, #0\n\
    b _08001D70\n\
    .pool\n\
_08001D4C:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r2, r4, #4\n\
    add r0, #0x8\n\
    add r0, r2, r0\n\
    ldr r1, [r0]\n\
    add r1, r6\n\
    b _08001D6C\n\
    .pool\n\
_08001D60:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r2, r4, #4\n\
    add r0, #0x8\n\
    add r0, r2, r0\n\
    ldr r1, [r0]\n\
    sub r1, r6\n\
_08001D6C:\n\
    str r1, [r0]\n\
    add r5, r2, #0\n\
_08001D70:\n\
    bl GetBgMode\n\
    lsl r0, #24\n\
    lsr r0, #24\n\
    cmp r4, #0x1\n\
    beq _08001DAC\n\
    cmp r4, #0x1\n\
    bgt _08001D8C\n\
    cmp r4, #0\n\
    beq _08001D96\n\
    b _08001E2C\n\
    .pool\n\
_08001D8C:\n\
    cmp r4, #0x2\n\
    beq _08001DC0\n\
    cmp r4, #0x3\n\
    beq _08001DF8\n\
    b _08001E2C\n\
_08001D96:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x8]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x10\n\
    bl SetGpuReg\n\
    b _08001E2C\n\
    .pool\n\
_08001DAC:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x18]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x14\n\
    bl SetGpuReg\n\
    b _08001E2C\n\
    .pool\n\
_08001DC0:\n\
    cmp r0, #0\n\
    bne _08001DD8\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x28]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x18\n\
    bl SetGpuReg\n\
    b _08001E2C\n\
    .pool\n\
_08001DD8:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x28]\n\
    lsr r1, r0, #16\n\
    lsl r0, #16\n\
    lsr r4, r0, #16\n\
    mov r0, #0x2A\n\
    bl SetGpuReg\n\
    mov r0, #0x28\n\
    add r1, r4, #0\n\
    bl SetGpuReg\n\
    b _08001E2C\n\
    .pool\n\
_08001DF8:\n\
    cmp r0, #0\n\
    bne _08001E10\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x38]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x1C\n\
    bl SetGpuReg\n\
    b _08001E2C\n\
    .pool\n\
_08001E10:\n\
    cmp r0, #0x2\n\
    bne _08001E2C\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x38]\n\
    lsr r1, r0, #16\n\
    lsl r0, #16\n\
    lsr r4, r0, #16\n\
    mov r0, #0x3A\n\
    bl SetGpuReg\n\
    mov r0, #0x38\n\
    add r1, r4, #0\n\
    bl SetGpuReg\n\
_08001E2C:\n\
    ldr r0, =gUnknown_030008F8\n\
    add r0, #0x8\n\
    add r0, r5, r0\n\
    ldr r0, [r0]\n\
_08001E34:\n\
    pop {r4-r6}\n\
    pop {r1}\n\
    bx r1\n\
    .pool\n");
}
#endif // NONMATCHING

u32 GetBgX(u8 bg)
{
    if (IsInvalidBgDuplicate(bg) != FALSE)
        return -1;
    if (GetBgControlAttribute(bg, 0x1) == 0)
        return -1;
    return gUnknown_030008F8[bg].bg_x;
}

#ifdef NONMATCHING  // Everything that uses temp1 doesn't match
u32 ChangeBgY(u8 bg, u32 value, u8 op)
{
    u8 mode;
    u32 temp1;
    
    if (IsInvalidBgDuplicate(bg) != FALSE || GetBgControlAttribute(bg, 1) == 0)
    {
        return -1;
    }
    
    switch (op)
    {
        case 0:
        default:
            gUnknown_030008F8[bg].bg_y = value;
            break;
        case 1:
            gUnknown_030008F8[bg].bg_y += value;
            break;
        case 2:
            gUnknown_030008F8[bg].bg_y -= value;
            break;
    }
    
    mode = GetBgMode();
    
    switch (bg)
    {
        case 0:
            SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_030008F8[0].bg_y >> 0x8);
            break;
        case 1:
            SetGpuReg(REG_OFFSET_BG1VOFS, gUnknown_030008F8[1].bg_y >> 0x8);
            break;
        case 2:
            if (mode == 0)
            {
                SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_030008F8[2].bg_y >> 0x8);
            }
            else
            {
                temp1 = gUnknown_030008F8[2].bg_y;
                
                SetGpuReg(REG_OFFSET_BG2Y_H, (u16)(temp1 >> 0x10));
                SetGpuReg(REG_OFFSET_BG2Y_L, (u16)(temp1));
            }
            break;
        case 3:
            if (mode == 0)
            {
                SetGpuReg(REG_OFFSET_BG3VOFS, gUnknown_030008F8[3].bg_y >> 0x8);
            }
            else if (mode == 2)
            {
                temp1 = gUnknown_030008F8[3].bg_y;
                
                SetGpuReg(REG_OFFSET_BG3Y_H, (u16)(temp1 >> 0x10));
                SetGpuReg(REG_OFFSET_BG3Y_L, (u16)(temp1));
            }
            break;
    }
    
    return gUnknown_030008F8[bg].bg_y;
}
#else
__attribute__((naked))
u32 ChangeBgY(u8 bg, u32 value, u8 op)
{
    asm("push {r4-r6,lr}\n\
	add r6, r1, #0\n\
	lsl r0, #24\n\
	lsr r4, r0, #24\n\
	lsl r2, #24\n\
	lsr r5, r2, #24\n\
	add r0, r4, #0\n\
	bl IsInvalidBgDuplicate\n\
	cmp r0, #0\n\
	bne _08001EA0\n\
	add r0, r4, #0\n\
	mov r1, #0x1\n\
	bl GetBgControlAttribute\n\
	lsl r0, #16\n\
	cmp r0, #0\n\
	bne _08001EA6\n\
_08001EA0:\n\
	mov r0, #0x1\n\
	neg r0, r0\n\
	b _08001FAC\n\
_08001EA6:\n\
	cmp r5, #0x1\n\
	beq _08001EC4\n\
	cmp r5, #0x1\n\
	ble _08001EB2\n\
	cmp r5, #0x2\n\
	beq _08001ED8\n\
_08001EB2:\n\
	ldr r0, =gUnknown_030008F8\n\
	lsl r1, r4, #4\n\
	add r0, #0xC\n\
	add r0, r1, r0\n\
	str r6, [r0]\n\
	add r5, r1, #0\n\
	b _08001EE8\n\
	.pool\n\
_08001EC4:\n\
	ldr r0, =gUnknown_030008F8\n\
	lsl r2, r4, #4\n\
	add r0, #0xC\n\
	add r0, r2, r0\n\
	ldr r1, [r0]\n\
	add r1, r6\n\
	b _08001EE4\n\
	.pool\n\
_08001ED8:\n\
	ldr r0, =gUnknown_030008F8\n\
	lsl r2, r4, #4\n\
	add r0, #0xC\n\
	add r0, r2, r0\n\
	ldr r1, [r0]\n\
	sub r1, r6\n\
_08001EE4:\n\
	str r1, [r0]\n\
	add r5, r2, #0\n\
_08001EE8:\n\
	bl GetBgMode\n\
	lsl r0, #24\n\
	lsr r0, #24\n\
	cmp r4, #0x1\n\
	beq _08001F24\n\
	cmp r4, #0x1\n\
	bgt _08001F04\n\
	cmp r4, #0\n\
	beq _08001F0E\n\
	b _08001FA4\n\
	.pool\n\
_08001F04:\n\
	cmp r4, #0x2\n\
	beq _08001F38\n\
	cmp r4, #0x3\n\
	beq _08001F70\n\
	b _08001FA4\n\
_08001F0E:\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0xC]\n\
	lsl r0, #8\n\
	lsr r1, r0, #16\n\
	mov r0, #0x12\n\
	bl SetGpuReg\n\
	b _08001FA4\n\
	.pool\n\
_08001F24:\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0x1C]\n\
	lsl r0, #8\n\
	lsr r1, r0, #16\n\
	mov r0, #0x16\n\
	bl SetGpuReg\n\
	b _08001FA4\n\
	.pool\n\
_08001F38:\n\
	cmp r0, #0\n\
	bne _08001F50\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0x2C]\n\
	lsl r0, #8\n\
	lsr r1, r0, #16\n\
	mov r0, #0x1A\n\
	bl SetGpuReg\n\
	b _08001FA4\n\
	.pool\n\
_08001F50:\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0x2C]\n\
	lsr r1, r0, #16\n\
	lsl r0, #16\n\
	lsr r4, r0, #16\n\
	mov r0, #0x2E\n\
	bl SetGpuReg\n\
	mov r0, #0x2C\n\
	add r1, r4, #0\n\
	bl SetGpuReg\n\
	b _08001FA4\n\
	.pool\n\
_08001F70:\n\
	cmp r0, #0\n\
	bne _08001F88\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0x3C]\n\
	lsl r0, #8\n\
	lsr r1, r0, #16\n\
	mov r0, #0x1E\n\
	bl SetGpuReg\n\
	b _08001FA4\n\
	.pool\n\
_08001F88:\n\
	cmp r0, #0x2\n\
	bne _08001FA4\n\
	ldr r0, =gUnknown_030008F8\n\
	ldr r0, [r0, #0x3C]\n\
	lsr r1, r0, #16\n\
	lsl r0, #16\n\
	lsr r4, r0, #16\n\
	mov r0, #0x3E\n\
	bl SetGpuReg\n\
	mov r0, #0x3C\n\
	add r1, r4, #0\n\
	bl SetGpuReg\n\
_08001FA4:\n\
	ldr r0, =gUnknown_030008F8\n\
	add r0, #0xC\n\
	add r0, r5, r0\n\
	ldr r0, [r0]\n\
_08001FAC:\n\
	pop {r4-r6}\n\
	pop {r1}\n\
	bx r1\n\
	.pool\n");
}
#endif // NONMATCHING

#ifdef NONMATCHING // Same issue as ChangeBgX and ChangeBgY
u32 ChangeBgY_ScreenOff(u8 bg, u32 value, u8 op)
{
    u8 mode;
    u16 temp1;
    
    if (IsInvalidBgDuplicate(bg) != FALSE || GetBgControlAttribute(bg, 1) == 0)
    {
        return -1;
    }
    
    switch (op)
    {
        case 0:
        default:
            gUnknown_030008F8[bg].bg_y = value;
            break;
        case 1:
            gUnknown_030008F8[bg].bg_y += value;
            break;
        case 2:
            gUnknown_030008F8[bg].bg_y -= value;
            break;
    }
    
    mode = GetBgMode();
    
    switch (bg)
    {
        case 0:
            SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, gUnknown_030008F8[0].bg_y >> 0x8);
            break;
        case 1:
            SetGpuReg_ForcedBlank(REG_OFFSET_BG1VOFS, gUnknown_030008F8[1].bg_y >> 0x8);
            break;
        case 2:
            if (mode == 0)
            {
                SetGpuReg_ForcedBlank(REG_OFFSET_BG2VOFS, gUnknown_030008F8[2].bg_y >> 0x8);
                
            }
            else
            {
                temp1 = gUnknown_030008F8[2].bg_y;
                
                SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_H, (gUnknown_030008F8[2].bg_y >> 0x10));
                SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_L, (temp1));
            }
            break;
        case 3:
            if (mode == 0)
            {
                SetGpuReg_ForcedBlank(REG_OFFSET_BG3VOFS, gUnknown_030008F8[3].bg_y >> 0x8);
            }
            else if (mode == 2)
            {
                temp1 = gUnknown_030008F8[3].bg_y;
                
                SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_H, (gUnknown_030008F8[3].bg_y >> 0x10));
                SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_L, (temp1));
            }
            break;
    }
    
    return gUnknown_030008F8[bg].bg_y;
}
#else
__attribute__((naked))
u32 ChangeBgY_ScreenOff(u8 bg, u32 value, u8 op)
{
    asm("push {r4-r6,lr}\n\
    add r6, r1, #0\n\
    lsl r0, #24\n\
    lsr r4, r0, #24\n\
    lsl r2, #24\n\
    lsr r5, r2, #24\n\
    add r0, r4, #0\n\
    bl IsInvalidBgDuplicate\n\
    cmp r0, #0\n\
    bne _08001FDC\n\
    add r0, r4, #0\n\
    mov r1, #0x1\n\
    bl GetBgControlAttribute\n\
    lsl r0, #16\n\
    cmp r0, #0\n\
    bne _08001FE2\n\
_08001FDC:\n\
    mov r0, #0x1\n\
    neg r0, r0\n\
    b _080020E8\n\
_08001FE2:\n\
    cmp r5, #0x1\n\
    beq _08002000\n\
    cmp r5, #0x1\n\
    ble _08001FEE\n\
    cmp r5, #0x2\n\
    beq _08002014\n\
_08001FEE:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r1, r4, #4\n\
    add r0, #0xC\n\
    add r0, r1, r0\n\
    str r6, [r0]\n\
    add r5, r1, #0\n\
    b _08002024\n\
    .pool\n\
_08002000:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r2, r4, #4\n\
    add r0, #0xC\n\
    add r0, r2, r0\n\
    ldr r1, [r0]\n\
    add r1, r6\n\
    b _08002020\n\
    .pool\n\
_08002014:\n\
    ldr r0, =gUnknown_030008F8\n\
    lsl r2, r4, #4\n\
    add r0, #0xC\n\
    add r0, r2, r0\n\
    ldr r1, [r0]\n\
    sub r1, r6\n\
_08002020:\n\
    str r1, [r0]\n\
    add r5, r2, #0\n\
_08002024:\n\
    bl GetBgMode\n\
    lsl r0, #24\n\
    lsr r0, #24\n\
    cmp r4, #0x1\n\
    beq _08002060\n\
    cmp r4, #0x1\n\
    bgt _08002040\n\
    cmp r4, #0\n\
    beq _0800204A\n\
    b _080020E0\n\
    .pool\n\
_08002040:\n\
    cmp r4, #0x2\n\
    beq _08002074\n\
    cmp r4, #0x3\n\
    beq _080020AC\n\
    b _080020E0\n\
_0800204A:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0xC]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x12\n\
    bl SetGpuReg_ForcedBlank\n\
    b _080020E0\n\
    .pool\n\
_08002060:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x1C]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x16\n\
    bl SetGpuReg_ForcedBlank\n\
    b _080020E0\n\
    .pool\n\
_08002074:\n\
    cmp r0, #0\n\
    bne _0800208C\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x2C]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x1A\n\
    bl SetGpuReg_ForcedBlank\n\
    b _080020E0\n\
    .pool\n\
_0800208C:\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x2C]\n\
    lsr r1, r0, #16\n\
    lsl r0, #16\n\
    lsr r4, r0, #16\n\
    mov r0, #0x2E\n\
    bl SetGpuReg_ForcedBlank\n\
    mov r0, #0x2C\n\
    add r1, r4, #0\n\
    bl SetGpuReg_ForcedBlank\n\
    b _080020E0\n\
    .pool\n\
_080020AC:\n\
    cmp r0, #0\n\
    bne _080020C4\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x3C]\n\
    lsl r0, #8\n\
    lsr r1, r0, #16\n\
    mov r0, #0x1E\n\
    bl SetGpuReg_ForcedBlank\n\
    b _080020E0\n\
    .pool\n\
_080020C4:\n\
    cmp r0, #0x2\n\
    bne _080020E0\n\
    ldr r0, =gUnknown_030008F8\n\
    ldr r0, [r0, #0x3C]\n\
    lsr r1, r0, #16\n\
    lsl r0, #16\n\
    lsr r4, r0, #16\n\
    mov r0, #0x3E\n\
    bl SetGpuReg_ForcedBlank\n\
    mov r0, #0x3C\n\
    add r1, r4, #0\n\
    bl SetGpuReg_ForcedBlank\n\
_080020E0:\n\
    ldr r0, =gUnknown_030008F8\n\
    add r0, #0xC\n\
    add r0, r5, r0\n\
    ldr r0, [r0]\n\
_080020E8:\n\
    pop {r4-r6}\n\
    pop {r1}\n\
    bx r1\n\
    .pool\n");
}
#endif // NONMATCHING

u32 GetBgY(u8 bg)
{
    if (IsInvalidBgDuplicate(bg) != FALSE)
        return -1;
    if (GetBgControlAttribute(bg, 0x1) == 0)
        return -1;
    return gUnknown_030008F8[bg].bg_y;
}

void SetBgAffine(u8 bg, u32 srcCenterX, u32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle)
{
    SetBgAffineInternal(bg, srcCenterX, srcCenterY, dispCenterX, dispCenterY, scaleX, scaleY, rotationAngle);
}

u8 Unused_AdjustBgMosaic(u8 a1, u8 a2)
{
    u16 result;
    s16 test1;
    s16 test2;
    
    result = GetGpuReg(REG_OFFSET_MOSAIC);
    
    test1 = result & 0xF;
    test2 = (result >> 4) & 0xF;
    result &= 0xFF00;
    
    switch (a2)
    {
        case 0:
        default:
            test1 = a1 & 0xF;
            test2 = a1 >> 0x4;
            break;
        case 1:
            test1 = a1 & 0xF;
            break;
        case 2:
            if ((test1 + a1) > 0xF)
            {
                test1 = 0xF;
            }
            else
            {
                test1 += a1;
            }
            break;
        case 3:
            if ((test1 - a1) < 0)
            {
                test1 = 0x0;
            }
            else
            {
                test1 -= a1;
            }
            break;
        case 4:
            test2 = a1 & 0xF;
            break;
        case 5:
            if ((test2 + a1) > 0xF)
            {
                test2 = 0xF;
            }
            else
            {
                test2 += a1;
            }
            break;
        case 6:
            if ((test2 - a1) < 0)
            {
                test2 = 0x0;
            }
            else
            {
                test2 -= a1;
            }
            break;
    }
    
    result |= ((test2 << 0x4) & 0xF0);
    result |= (test1 & 0xF);
    
    SetGpuReg(REG_OFFSET_MOSAIC, result);
    
    return result;
}

void SetBgTilemapBuffer(u8 bg, void *tilemap)
{
    if (IsInvalidBgDuplicate(bg) == FALSE && GetBgControlAttribute(bg, 0x1) != 0x0)
    {
        gUnknown_030008F8[bg].tilemap = tilemap;
    }
}

void UnsetBgTilemapBuffer(u8 bg)
{
    if (IsInvalidBgDuplicate(bg) == FALSE && GetBgControlAttribute(bg, 0x1) != 0x0)
    {
        gUnknown_030008F8[bg].tilemap = NULL;
    }
}

void* GetBgTilemapBuffer(u8 bg)
{
    if (IsInvalidBgDuplicate(bg) != FALSE)
        return NULL;
    if (GetBgControlAttribute(bg, 0x1) == 0)
        return NULL;
    return gUnknown_030008F8[bg].tilemap;
}

void CopyToBgTilemapBuffer(u8 bg, void *src, u16 mode, u16 destOffset)
{
    if (IsInvalidBgDuplicate(bg) == FALSE && IsTileMapOutsideWram(bg) == FALSE)
    {
        if (mode != 0)
        {
            CpuCopy16(src, (void *)(gUnknown_030008F8[bg].tilemap + (destOffset * 2)), mode);
        }
        else
        {
            LZ77UnCompWram(src, (void *)(gUnknown_030008F8[bg].tilemap + (destOffset * 2)));
        }
    }
}

void CopyBgTilemapBufferToVram(u8 bg)
{
    u16 sizeToLoad;
    
    if (IsInvalidBgDuplicate(bg) == FALSE && IsTileMapOutsideWram(bg) == FALSE)
    {
        switch (GetBgType(bg))
        {
            case 0:
                sizeToLoad = GetBgMetricTextMode(bg, 0) * 0x800;
                break;
            case 1:
                sizeToLoad = GetBgMetricAffineMode(bg, 0) * 0x100;
                break;
            default:
                sizeToLoad = 0;
                break;
        }
        LoadBgVram(bg, gUnknown_030008F8[bg].tilemap, sizeToLoad, 0, 2);
    }
}

void CopyToBgTilemapBufferRect(u8 bg, void* src, u8 destX, u8 destY, u8 width, u8 height)
{
    void* srcCopy;
    u16 destX16;
    u16 destY16;
    u16 mode;
    
    if (IsInvalidBgDuplicate(bg) == FALSE && IsTileMapOutsideWram(bg) == FALSE)
    {
        switch (GetBgType(bg))
        {
            case 0:
                srcCopy = src;
                for (destY16 = destY; destY16 < (destY + height); destY16++)
                {
                    for (destX16 = destX; destX16 < (destX + width); destX16++)
                    {
                        ((u16*)gUnknown_030008F8[bg].tilemap)[((destY16 * 0x20) + destX16)] = *((u16*)srcCopy)++;
                    }
                }
                break;
            case 1:
                srcCopy = src;
                mode = GetBgMetricAffineMode(bg, 0x1);
                for (destY16 = destY; destY16 < (destY + height); destY16++)
                {
                    for (destX16 = destX; destX16 < (destX + width); destX16++)
                    {
                        ((u8*)gUnknown_030008F8[bg].tilemap)[((destY16 * mode) + destX16)] = *((u8*)srcCopy)++;
                    }
                }
                break;
        }
    }
}

void CopyToBgTilemapBufferRect_ChangePalette(u8 bg, void *src, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette)
{
    CopyRectToBgTilemapBufferRect(bg, src, 0, 0, rectWidth, rectHeight, destX, destY, rectWidth, rectHeight, palette, 0, 0);
}
/*
void CopyRectToBgTilemapBufferRect(u8 bg, void* src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette1, u16 tileOffset, u16 palette2)
{
    u16 attribute;
    u16 mode;
    u16 mode2;
    
    void* srcCopy;
    u16 destX16;
    u16 destY16;
    
    if (IsInvalidBgDuplicate(bg) == FALSE && IsTileMapOutsideWram(bg) == FALSE)
    {
        attribute = GetBgControlAttribute(bg, 0x4);
        mode = GetBgMetricTextMode(bg, 0x1) * 0x20;
        mode2 = GetBgMetricTextMode(bg, 0x2) * 0x20;
        switch (GetBgType(bg))
        {
            case 0:
                srcCopy = src;
                for (destY16 = destY; destY16 < (destY + rectHeight); destY16++)
                {
                    for (destX16 = destX; destX16 < (destX + rectWidth); destX16++)
                    {
                        CopyTileMapEntry(&((u16*)srcCopy)[(srcY * rectWidth) + srcX], &((u16*)gUnknown_030008F8[bg].tilemap)[GetTileMapIndexFromCoords(destX16, destY16, attribute, mode, mode2)], palette1, tileOffset, palette2);
                    }
                }
                break;
            case 1:
                srcCopy = src;
                mode = GetBgMetricAffineMode(bg, 0x1);
                for (destY16 = destY; destY16 < (destY + rectHeight); destY16++)
                {
                    for (destX16 = destX; destX16 < (destX + rectWidth); destX16++)
                    {
                        CopyTileMapEntry(&((u16*)srcCopy)[(srcY * rectWidth) + srcX], &((u16*)gUnknown_030008F8[bg].tilemap)[GetTileMapIndexFromCoords(destX16, destY16, attribute, mode, mode2)], palette1, tileOffset, palette2);
                    }
                }
                break;
        }
    }
}*/

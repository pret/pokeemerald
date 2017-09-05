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
    
    u32 unk_4;
    u32 unk_5;
    u32 unk_6;
};

extern struct BgControl gUnknown_030008E0;    // gGpuBgConfigs
extern struct BgConfig2 gUnknown_030008F8[4]; // gGpuBgConfigs2
extern u32 gUnknown_03000938[4];
extern u32 gUnneededFireRedVariable;
extern struct BgConfig gZeroedBgControlStruct;
extern bool32 IsInvalidBgDuplicate(u8 bg);

void ResetBgControlStructs();

extern void SetTextModeAndHideBgs();
extern bool8 IsInvalidBg(u8 bg);
extern void SetGpuReg(u8 regOffset, u16 value);
extern u16 GetGpuReg(u8 regOffset);

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

void SetBgAffineInternal(u8 bg, u32 srcCenterX, u32 srcCenterY, u16 dispCenterX, u16 dispCenterY, u16 scaleX, u16 scaleY, u16 rotationAngle)
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
            
            gUnknown_030008F8[bg].unk_4 = 0;
            gUnknown_030008F8[bg].unk_5 = 0;
            gUnknown_030008F8[bg].unk_6 = 0;
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
        
        gUnknown_030008F8[bg].unk_4 = 0;
        gUnknown_030008F8[bg].unk_5 = 0;
        gUnknown_030008F8[bg].unk_6 = 0;
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
    
    gUnknown_03000938[cursor >> 5] |= (1 << (cursor & 0x1F));
    
    if (gUnneededFireRedVariable == 1)
    {
        DummiedOutFireRedLeafGreenTileAllocFunc(bg, unk >> 5, size >> 5, 1);
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
    
    gUnknown_03000938[cursor >> 5] |= (1 << (cursor & 0x1F));
    
    return cursor;
}

#ifdef NONMATCHING
u16 Unused_LoadBgPalette(u8 bg, void *src, u16 size, u16 destOffset)
{
    u16 unk_1;
    s8 cursor;
    int cursor2;
    u32* ptr;
    
    if (IsInvalidBgDuplicate(bg) == FALSE)
    {
        unk_1 = (gUnknown_030008F8[bg].unk_2 * 0x20) + (destOffset * 2);
        cursor = RequestDma3Copy(src, (void*)(unk_1 + BG_PLTT), size, 0);
        cursor2 = cursor;
    }
    else
    {
        return -1;
    }
    
    if (cursor == -1)
    {
        return -1;
    }

    ptr = gUnknown_03000938;
    
    if (cursor < 0)
    {
        cursor2 += 0x1F;
    }
    
    cursor2 >>= 5;
    
    ptr[cursor2] |= (1 << (s8)(cursor - (cursor2 << 5)));

    return (u8)cursor;
}
#else
__attribute__((naked))
u8 Unused_LoadBgPalette(u8 bg, void *src, u16 size, u16 destOffset)
{
    asm("push {r4-r7,lr}\n\
    add r7, r1, #0\n\
    lsl r0, #24\n\
    lsr r4, r0, #24\n\
    lsl r2, #16\n\
    lsr r6, r2, #16\n\
    lsl r3, #16\n\
    lsr r5, r3, #16\n\
    add r0, r4, #0\n\
    bl IsInvalidBgDuplicate\n\
    cmp r0, #0\n\
    bne _08001A98\n\
    ldr r1, =gUnknown_030008F8\n\
    lsl r0, r4, #4\n\
    add r0, r1\n\
    ldrb r1, [r0, #0x1]\n\
    lsl r1, #26\n\
    lsr r1, #28\n\
    lsl r1, #5\n\
    lsl r0, r5, #1\n\
    add r1, r0\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    mov r0, #0xA0\n\
    lsl r0, #19\n\
    add r1, r0\n\
    add r0, r7, #0\n\
    add r2, r6, #0\n\
    mov r3, #0\n\
    bl RequestDma3Copy\n\
    lsl r3, r0, #24\n\
    asr r1, r3, #24\n\
    mov r0, #0x1\n\
    neg r0, r0\n\
    cmp r1, r0\n\
    bne _08001AA4\n\
_08001A98:\n\
    ldr r0, =0x0000ffff\n\
    b _08001AC8\n\
    .pool\n\
_08001AA4:\n\
    ldr r4, =gUnknown_03000938\n\
    add r0, r1, #0\n\
    cmp r1, #0\n\
    bge _08001AAE\n\
    add r0, #0x1F\n\
_08001AAE:\n\
    asr r0, #5\n\
    lsl r2, r0, #2\n\
    add r2, r4\n\
    lsl r0, #5\n\
    sub r0, r1, r0\n\
    lsl r0, #24\n\
    asr r0, #24\n\
    mov r1, #0x1\n\
    lsl r1, r0\n\
    ldr r0, [r2]\n\
    orr r0, r1\n\
    str r0, [r2]\n\
    lsr r0, r3, #24\n\
_08001AC8:\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool");
}
#endif // NONMATCHING

#include "global.h"
#include "palette.h"
#include "task.h"

enum
{
    NORMAL_FADE,
    FAST_FADE,
    HARDWARE_FADE,
};

// These are structs for some unused palette system.
// The full functionality of this system is unknown.

struct PaletteStructTemplate
{
    u16 uid;
    u16 *src;
    u16 pst_field_8_0:1;
    u16 pst_field_8_1:9;
    u16 size:5;
    u16 pst_field_9_7:1;
    u8 pst_field_A;
    u8 srcCount:5;
    u8 pst_field_B_5:3;
    u8 pst_field_C;
};

struct PaletteStruct
{
    struct PaletteStructTemplate *base;
    u32 ps_field_4_0:1;
    u16 ps_field_4_1:1;
    u32 baseDestOffset:9;
    u16 destOffset:10;
    u16 srcIndex:7;
    u8 ps_field_8;
    u8 ps_field_9;
};

extern void LZDecompressWram(const void *src, void *dest);
extern void SetGpuReg(u8 regOffset, u16 value);
extern void sub_8149DFC(u8 a1);
extern void sub_80A1670(u16 a1);
extern void sub_80A2D54(u8 a1);
extern void SetWordTaskArg(u8 taskId, u8 dataElem, u32 value);
extern void _call_via_r1(u32 a1, void *a2);

extern void BlendPalette(u16, u16, u8, u16);

EWRAM_DATA u16 gPlttBufferUnfaded[0x200] = {0};
EWRAM_DATA u16 gPlttBufferFaded[0x200] = {0};
EWRAM_DATA struct PaletteStruct sPaletteStructs[0x10] = {0};
EWRAM_DATA struct PaletteFadeControl gPaletteFade = {0};
EWRAM_DATA u32 gFiller_2037FE0 = 0;
EWRAM_DATA u32 sPlttBufferTransferPending = 0;
EWRAM_DATA u8 sPaletteDecompressionBuffer[0x400] = {0};

extern struct PaletteStructTemplate gDummyPaletteStructTemplate;
extern void *gUnknown_0852487C;
extern u8 gUnknown_0852489C[];

extern u16 gUnknown_03000F3C;
extern void *gUnknown_03000F44;

static void unused_sub_80A1CDC(struct PaletteStruct *, u32 *);
static void unused_sub_80A1E40(struct PaletteStruct *, u32 *);
static void unused_sub_80A1F00(struct PaletteStruct *);
static u8 GetPaletteNumByUid(u16);
static u8 UpdateNormalPaletteFade(void);
static void BeginFastPaletteFadeInternal(u8);
static u8 UpdateFastPaletteFade(void);
static u8 UpdateHardwarePaletteFade(void);
static void UpdateBlendRegisters(void);
static bool8 IsSoftwarePaletteFadeFinishing(void);

void sub_80A1818(u16 a1)
{
  void **v1 = &gUnknown_0852487C;
  CpuSet(v1[a1 & 0x3], gPlttBufferUnfaded + 0x80, 0x10);
  BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
  if ((u8)FindTaskIdByFunc(sub_8149DFC) != 0xFF )
  {
    gUnknown_03000F44 = sub_80A1670;
    gUnknown_03000F3C = 0x20;
  }
  return;
}

void sub_80A1884(u16 a1)
{
  void **v1 = &gUnknown_0852487C;
  CpuSet(v1[a1 & 0x3], gPlttBufferUnfaded + 0x80, 0x10);
  if ((u8)FindTaskIdByFunc(sub_8149DFC) == 0xFF )
  {
    BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if (!--gUnknown_03000F3C)
        gUnknown_03000F44 = 0;
  }
  return;
}

void LoadCompressedPalette(const void *src, u16 offset, u16 size)
{
    LZDecompressWram(src, sPaletteDecompressionBuffer);
    CpuCopy16(sPaletteDecompressionBuffer, gPlttBufferUnfaded + offset, size);
    CpuCopy16(sPaletteDecompressionBuffer, gPlttBufferFaded + offset, size);
}

void LoadPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void FillPalette(u16 value, u16 offset, u16 size)
{
    CpuFill16(value, gPlttBufferUnfaded + offset, size);
    CpuFill16(value, gPlttBufferFaded + offset, size);
}

void TransferPlttBuffer(void)
{
    if (!gPaletteFade.bufferTransferDisabled)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
    }
}

u8 UpdatePaletteFade(void)
{
    u8 result;
    u8 dummy = 0;

    if (sPlttBufferTransferPending)
        return -1;

    if (gPaletteFade.mode == NORMAL_FADE)
        result = UpdateNormalPaletteFade();
    else if (gPaletteFade.mode == FAST_FADE)
        result = UpdateFastPaletteFade();
    else
        result = UpdateHardwarePaletteFade();

    sPlttBufferTransferPending = gPaletteFade.multipurpose1 | dummy;

    return result;
}

void ResetPaletteFade(void)
{
    u8 i;

    for (i = 0; i < 16; i++)
        ResetPaletteStruct(i);

    ResetPaletteFadeControl();
}

void ReadPlttIntoBuffers(void)
{
    u16 i;
    u16 *pltt = (u16 *)PLTT;

    for (i = 0; i < PLTT_SIZE / 2; i++)
    {
        gPlttBufferUnfaded[i] = pltt[i];
        gPlttBufferFaded[i] = pltt[i];
    }
}

bool8 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor)
{
    u8 temp;
    register u32 _blendColor asm("r8") = blendColor;

    if (gPaletteFade.active)
    {
        return FALSE;
    }
    else
    {
        gPaletteFade.deltaY = 2;

        if (delay < 0)
        {
            gPaletteFade.deltaY += (delay * -1);
            delay = 0;
        }

        gPaletteFade_selectedPalettes = selectedPalettes;
        gPaletteFade.delayCounter = delay;
        gPaletteFade_delay = delay;
        gPaletteFade.y = startY;
        gPaletteFade.targetY = targetY;
        gPaletteFade.blendColor = _blendColor;
        gPaletteFade.active = 1;
        gPaletteFade.mode = NORMAL_FADE;

        if (startY < targetY)
            gPaletteFade.yDec = 0;
        else
            gPaletteFade.yDec = 1;

        UpdatePaletteFade();

        temp = gPaletteFade.bufferTransferDisabled;
        gPaletteFade.bufferTransferDisabled = 0;
        CpuCopy32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
        gPaletteFade.bufferTransferDisabled = temp;
        return TRUE;
    }
}

bool8 unref_sub_80A1C1C(u32 a1, u8 a2, u8 a3, u8 a4, u16 a5)
{
    ReadPlttIntoBuffers();
    return BeginNormalPaletteFade(a1, a2, a3, a4, a5);
}

void unref_sub_80A1C64(u8 a1, u32 *a2)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        struct PaletteStruct *palstruct = &sPaletteStructs[i];
        if (palstruct->ps_field_4_0)
        {
            if (palstruct->base->pst_field_8_0 == a1)
            {
                u8 val1 = palstruct->srcIndex;
                u8 val2 = palstruct->base->srcCount;
                if (val1 == val2)
                {
                    unused_sub_80A1F00(palstruct);
                    if (!palstruct->ps_field_4_0)
                        continue;
                }
                if (palstruct->ps_field_8 == 0)
                    unused_sub_80A1CDC(palstruct, a2);
                else
                    palstruct->ps_field_8--;

                unused_sub_80A1E40(palstruct, a2);
            }
        }
    }
}

static void unused_sub_80A1CDC(struct PaletteStruct *a1, u32 *a2)
{
    s32 srcIndex;
    s32 srcCount;
    u8 i = 0;
    u16 srcOffset = a1->srcIndex * a1->base->size;

    if (!a1->base->pst_field_8_0)
    {
        while (i < a1->base->size)
        {
            gPlttBufferUnfaded[a1->destOffset] = a1->base->src[srcOffset];
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }
    else
    {
        while (i < a1->base->size)
        {
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }

    a1->destOffset = a1->baseDestOffset;
    a1->ps_field_8 = a1->base->pst_field_A;
    a1->srcIndex++;

    srcIndex = a1->srcIndex;
    srcCount = a1->base->srcCount;

    if (srcIndex >= srcCount)
    {
        if (a1->ps_field_9)
            a1->ps_field_9--;
        a1->srcIndex = 0;
    }

    *a2 |= 1 << (a1->baseDestOffset >> 4);
}

static void unused_sub_80A1E40(struct PaletteStruct *a1, u32 *a2)
{
    if (gPaletteFade.active && ((1 << (a1->baseDestOffset >> 4)) & gPaletteFade_selectedPalettes))
    {
        if (!a1->base->pst_field_8_0)
        {
            if (gPaletteFade.delayCounter != gPaletteFade_delay)
            {
                BlendPalette(
                    a1->baseDestOffset,
                    a1->base->size,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            }
        }
        else
        {
            if (!gPaletteFade.delayCounter)
            {
                if (a1->ps_field_8 != a1->base->pst_field_A)
                {
                    u32 srcOffset = a1->srcIndex * a1->base->size;
                    u8 i;

                    for (i = 0; i < a1->base->size; i++)
                        gPlttBufferFaded[a1->baseDestOffset + i] = a1->base->src[srcOffset + i];
                }
            }
        }
    }
}

static void unused_sub_80A1F00(struct PaletteStruct *a1)
{
    if (!a1->ps_field_9)
    {
        s32 val = a1->base->pst_field_B_5;

        if (!val)
        {
            a1->srcIndex = 0;
            a1->ps_field_8 = a1->base->pst_field_A;
            a1->ps_field_9 = a1->base->pst_field_C;
            a1->destOffset = a1->baseDestOffset;
        }
        else
        {
            if (val < 0)
                return;
            if (val > 2)
                return;
            ResetPaletteStructByUid(a1->base->uid);
        }
    }
    else
    {
        a1->ps_field_9--;
    }
}

void ResetPaletteStructByUid(u16 a1)
{
    u8 paletteNum = GetPaletteNumByUid(a1);
    if (paletteNum != 16)
        ResetPaletteStruct(paletteNum);
}

void ResetPaletteStruct(u8 paletteNum)
{
    sPaletteStructs[paletteNum].base = &gDummyPaletteStructTemplate;
    sPaletteStructs[paletteNum].ps_field_4_0 = 0;
    sPaletteStructs[paletteNum].baseDestOffset = 0;
    sPaletteStructs[paletteNum].destOffset = 0;
    sPaletteStructs[paletteNum].srcIndex = 0;
    sPaletteStructs[paletteNum].ps_field_4_1 = 0;
    sPaletteStructs[paletteNum].ps_field_8 = 0;
    sPaletteStructs[paletteNum].ps_field_9 = 0;
}

void ResetPaletteFadeControl()
{
    gPaletteFade.multipurpose1 = 0;
    gPaletteFade.multipurpose2 = 0;
    gPaletteFade.delayCounter = 0;
    gPaletteFade.y = 0;
    gPaletteFade.targetY = 0;
    gPaletteFade.blendColor = 0;
    gPaletteFade.active = 0;
    gPaletteFade.multipurpose2 = 0; // assign same value twice
    gPaletteFade.yDec = 0;
    gPaletteFade.bufferTransferDisabled = 0;
    gPaletteFade.shouldResetBlendRegisters = 0;
    gPaletteFade.hardwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishingCounter = 0;
    gPaletteFade.objPaletteToggle = 0;
    gPaletteFade.deltaY = 2;
}

void unref_sub_80A2048(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 1;
}

void unref_sub_80A2074(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 0;
}

static u8 GetPaletteNumByUid(u16 uid)
{
    u8 i;

    for (i = 0; i < 16; i++)
        if (sPaletteStructs[i].base->uid == uid)
            return i;

    return 16;
}

static u8 UpdateNormalPaletteFade()
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gPaletteFade.active)
        return 0;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gPaletteFade.active;
    }
    else
    {
        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.delayCounter < gPaletteFade_delay)
            {
                gPaletteFade.delayCounter++;
                return 2;
            }
            gPaletteFade.delayCounter = 0;
        }

        paletteOffset = 0;

        if (!gPaletteFade.objPaletteToggle)
        {
            selectedPalettes = gPaletteFade_selectedPalettes;
        }
        else
        {
            selectedPalettes = gPaletteFade_selectedPalettes >> 16;
            paletteOffset = 256;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gPaletteFade.objPaletteToggle ^= 1;

        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.y == gPaletteFade.targetY)
            {
                gPaletteFade_selectedPalettes = 0;
                gPaletteFade.softwareFadeFinishing = 1;
            }
            else
            {
                s8 val;

                if (!gPaletteFade.yDec)
                {
                    val = gPaletteFade.y;
                    val += gPaletteFade.deltaY;
                    if (val > gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
                else
                {
                    val = gPaletteFade.y;
                    val -= gPaletteFade.deltaY;
                    if (val < gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
            }
        }

        return gPaletteFade.active;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void BeginFastPaletteFade(u8 submode)
{
    gPaletteFade.deltaY = 2;
    BeginFastPaletteFadeInternal(submode);
}

static void BeginFastPaletteFadeInternal(u8 submode)
{
    gPaletteFade.y = 31;
    gPaletteFade_submode = submode & 0x3F;
    gPaletteFade.active = 1;
    gPaletteFade.mode = FAST_FADE;

    if (submode == FAST_FADE_IN_FROM_BLACK)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    if (submode == FAST_FADE_IN_FROM_WHITE)
        CpuFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u8 UpdateFastPaletteFade(void)
{
    u16 i;
    u16 paletteOffsetStart;
    u16 paletteOffsetEnd;
    s8 r0;
    s8 g0;
    s8 b0;
    s8 r;
    s8 g;
    s8 b;

    if (!gPaletteFade.active)
        return 0;

    if (IsSoftwarePaletteFadeFinishing())
        return gPaletteFade.active;

    if (gPaletteFade.objPaletteToggle)
    {
        paletteOffsetStart = 256;
        paletteOffsetEnd = 512;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = 256;
    }

    switch (gPaletteFade_submode)
    {
    case FAST_FADE_IN_FROM_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r - 2;
            g = faded->g - 2;
            b = faded->b - 2;

            if (r < r0)
                r = r0;
            if (g < g0)
                g = g0;
            if (b < b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_WHTIE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r + 2;
            g = data->g + 2;
            b = data->b + 2;

            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_IN_FROM_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
    }

    gPaletteFade.objPaletteToggle ^= 1;

    if (gPaletteFade.objPaletteToggle)
        return gPaletteFade.active;

    if (gPaletteFade.y - gPaletteFade.deltaY < 0)
        gPaletteFade.y = 0;
    else
        gPaletteFade.y -= gPaletteFade.deltaY;

    if (gPaletteFade.y == 0)
    {
        switch (gPaletteFade_submode)
        {
        case FAST_FADE_IN_FROM_WHITE:
        case FAST_FADE_IN_FROM_BLACK:
            CpuCopy32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_WHTIE:
            CpuFill32(0xFFFFFFFF, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_BLACK:
            CpuFill32(0x00000000, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gPaletteFade.mode = NORMAL_FADE;
        gPaletteFade.softwareFadeFinishing = 1;
    }

    return gPaletteFade.active;
}

void BeginHardwarePaletteFade(u8 blendCnt, u8 delay, u8 y, u8 targetY, u8 shouldResetBlendRegisters)
{
    gPaletteFade_blendCnt = blendCnt;
    gPaletteFade.delayCounter = delay;
    gPaletteFade_delay = delay;
    gPaletteFade.y = y;
    gPaletteFade.targetY = targetY;
    gPaletteFade.active = 1;
    gPaletteFade.mode = HARDWARE_FADE;
    gPaletteFade.shouldResetBlendRegisters = shouldResetBlendRegisters & 1;
    gPaletteFade.hardwareFadeFinishing = 0;

    if (y < targetY)
        gPaletteFade.yDec = 0;
    else
        gPaletteFade.yDec = 1;
}

static u8 UpdateHardwarePaletteFade(void)
{
    if (!gPaletteFade.active)
        return 0;

    if (gPaletteFade.delayCounter < gPaletteFade_delay)
    {
        gPaletteFade.delayCounter++;
        return 2;
    }

    gPaletteFade.delayCounter = 0;

    if (!gPaletteFade.yDec)
    {
        gPaletteFade.y++;
        if (gPaletteFade.y > gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y--;
        }
    }
    else
    {
        s32 y = gPaletteFade.y--;
        if (y - 1 < gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y++;
        }
    }

    if (gPaletteFade.hardwareFadeFinishing)
    {
        if (gPaletteFade.shouldResetBlendRegisters)
        {
            gPaletteFade_blendCnt = 0;
            gPaletteFade.y = 0;
        }
        gPaletteFade.shouldResetBlendRegisters = 0;
    }

    return gPaletteFade.active;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gPaletteFade_blendCnt);
    SetGpuReg(REG_OFFSET_BLDY, gPaletteFade.y);
    if (gPaletteFade.hardwareFadeFinishing)
    {
        gPaletteFade.hardwareFadeFinishing = 0;
        gPaletteFade.mode = 0;
        gPaletteFade_blendCnt = 0;
        gPaletteFade.y = 0;
        gPaletteFade.active = 0;
    }
}

static bool8 IsSoftwarePaletteFadeFinishing(void)
{
    if (gPaletteFade.softwareFadeFinishing)
    {
        if (gPaletteFade.softwareFadeFinishingCounter == 4)
        {
            gPaletteFade.active = 0;
            gPaletteFade.softwareFadeFinishing = 0;
            gPaletteFade.softwareFadeFinishingCounter = 0;
        }
        else
        {
            gPaletteFade.softwareFadeFinishingCounter++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void BlendPalettes(u32 selectedPalettes, u8 coeff, u16 color)
{
    u16 paletteOffset;

    for (paletteOffset = 0; selectedPalettes; paletteOffset += 16)
    {
        if (selectedPalettes & 1)
            BlendPalette(paletteOffset, 16, coeff, color);
        selectedPalettes >>= 1;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

void TintPalette_GrayScale(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        *palette++ = gray << 10 | gray << 5 | gray;
    }
    return;
}

void TintPalette_GrayScale2(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        if ((u32)gray > 0x1F)
            gray = 0x1F;
        
        gray = gUnknown_0852489C[gray];
        
        *palette++ = gray << 10 | gray << 5 | gray;
    }
    return;
}

#ifdef NONMATCHING
void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    u32 gray;
    u32 sepia;
    s8 r2;
    s8 g2;
    s8 b2;
    
    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = (s32)(r >> 8);
        
        sepia = (gray * 0x133);
        
        r2 = (u16)sepia >> 8;
        
        g2 = gray;
        
        b2 = (gray * 15);
        
        if (r2 > 0x1F)
            r2 = 0x1F;
        
        *palette++ = b2 << 10 | g2 << 5 | r2;
    }
    return;
}
#else
__attribute__((naked))
void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    asm("push {r4-r7,lr}\n\
    add r5, r0, #0\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    cmp r1, #0\n\
    beq _080A2BA2\n\
    mov r7, #0x1F\n\
    add r6, r1, #0\n\
_080A2B50:\n\
    ldrh r0, [r5]\n\
    mov r1, #0x1F\n\
    and r1, r0\n\
    lsl r0, #16\n\
    lsr r2, r0, #21\n\
    and r2, r7\n\
    lsr r3, r0, #26\n\
    and r3, r7\n\
    mov r0, #0x4C\n\
    mul r1, r0\n\
    mov r0, #0x97\n\
    mul r0, r2\n\
    add r1, r0\n\
    lsl r0, r3, #3\n\
    sub r0, r3\n\
    lsl r0, #2\n\
    add r0, r3\n\
    add r1, r0\n\
    asr r1, #8\n\
    ldr r0, =0x00000133\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r2, r0, #24\n\
    lsl r0, r1, #24\n\
    lsr r4, r0, #24\n\
    lsl r0, r1, #4\n\
    sub r0, r1\n\
    lsl r0, #20\n\
    lsr r3, r0, #24\n\
    cmp r2, #0x1F\n\
    ble _080A2B90\n\
    mov r2, #0x1F\n\
_080A2B90:\n\
    lsl r0, r3, #10\n\
    lsl r1, r4, #5\n\
    orr r0, r1\n\
    orr r0, r2\n\
    strh r0, [r5]\n\
    add r5, #0x2\n\
    sub r6, #0x1\n\
    cmp r6, #0\n\
    bne _080A2B50\n\
_080A2BA2:\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

#ifdef NONMATCHING
void sub_80A2BAC(u16 *palette, u16 count, u16 a3, u16 a4, u16 a5)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;
    u8 r2;
    u8 g2;
    u8 b2;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        r2 = (u16)(gray * a3) >> 8;
        
        g2 = (u16)(gray * a4) >> 8;
        
        b2 = (u16)(gray * a5) >> 8;
        
        if (r2 > 0x1F)
            r2 = 0x1F;
        
        if (g2 > 0x1F)
            g2 = 0x1F;
        
        if (b2 > 0x1F)
            b2 = 0x1F;
        
        *palette++ = b2 << 10 | g2 << 5 | r2;
    }
    return;
}
#else
__attribute__((naked))
void sub_80A2BAC(u16 *palette, u16 count, u16 a3, u16 a4, u16 a5)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    add r5, r0, #0\n\
    ldr r0, [sp, #0x1C]\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    lsl r2, #16\n\
    lsr r2, #16\n\
    mov r9, r2\n\
    lsl r3, #16\n\
    lsr r3, #16\n\
    mov r8, r3\n\
    lsl r0, #16\n\
    lsr r0, #16\n\
    mov r12, r0\n\
    cmp r1, #0\n\
    beq _080A2C38\n\
    mov r7, #0x1F\n\
    add r6, r1, #0\n\
_080A2BD6:\n\
    ldrh r0, [r5]\n\
    mov r1, #0x1F\n\
    and r1, r0\n\
    lsl r0, #16\n\
    lsr r2, r0, #21\n\
    and r2, r7\n\
    lsr r3, r0, #26\n\
    and r3, r7\n\
    mov r0, #0x4C\n\
    mul r1, r0\n\
    mov r0, #0x97\n\
    mul r0, r2\n\
    add r1, r0\n\
    lsl r0, r3, #3\n\
    sub r0, r3\n\
    lsl r0, #2\n\
    add r0, r3\n\
    add r1, r0\n\
    asr r1, #8\n\
    mov r0, r9\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r4, r0, #24\n\
    mov r0, r8\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r2, r0, #24\n\
    mov r0, r12\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r3, r0, #24\n\
    cmp r4, #0x1F\n\
    ble _080A2C1A\n\
    mov r4, #0x1F\n\
_080A2C1A:\n\
    cmp r2, #0x1F\n\
    ble _080A2C20\n\
    mov r2, #0x1F\n\
_080A2C20:\n\
    cmp r3, #0x1F\n\
    ble _080A2C26\n\
    mov r3, #0x1F\n\
_080A2C26:\n\
    lsl r0, r3, #10\n\
    lsl r1, r2, #5\n\
    orr r0, r1\n\
    orr r0, r4\n\
    strh r0, [r5]\n\
    add r5, #0x2\n\
    sub r6, #0x1\n\
    cmp r6, #0\n\
    bne _080A2BD6\n\
_080A2C38:\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0");
}
#endif

void sub_80A2C44(u32 a1, s8 a2, u8 a3, u8 a4, u16 a5, u8 a6, u8 a7)
{
    u8 v11;
    struct Task *v12;
    u32 v13;
    struct Task *v14;
    struct Task *v15;
    struct Task *v16;

    v11 = CreateTask((void *)sub_80A2D54, a6);
    v15 = gTasks;
    v12 = &v15[v11];
    v12->data[0] = a3;
    v12->data[1] = a4;

    if (a2 >= 0)
    {
        v12->data[3] = a2;
        v13 = 1;
    }
    else
    {
        v12->data[3] = 0;
        v13 = -a2 + 1;
    }

    v12->data[2] = v13;

    if (a4 < a3)
        gTasks[v11].data[2] *= -1;

    SetWordTaskArg(v11, 5, a1);
    v16 = gTasks;
    v14 = &v16[v11];
    v14->data[7] = a5;
    v14->data[8] = a7;
    _call_via_r1(v11, v14->func);
}

u32 sub_80A2CF8(u8 a1)
{
    int i = 0;
    void *func = sub_80A2D54;
    struct Task *v2 = gTasks;

    for (; i <= 0xF; i++)
    {
        if ((v2->isActive == 1) && (v2->func == func) && (v2->data[8] == a1))
            return 1;
        v2++;
    }
    return 0;
}

void sub_80A2D34()
{
    int v0;

    while (1)
    {
        v0 = FindTaskIdByFunc(sub_80A2D54);
        if (v0 == 0xFF)
            break;
        DestroyTask(v0);
    }
}

void sub_80A2D54(u8 a1)
{
    s16 *v2;
    u32 v3;
    u16 v5;
    s32 v6;
    u16 v7;
    u32 v8;
    s16 v9;
    u16 v10;
    s32 v11;

    v2 = gTasks[a1].data;
    v3 = GetWordTaskArg(a1, 5);
    v2[4] += 1;

    if (v2[4] > v2[3])
    {
        v2[4] = 0;
        BlendPalettes(v3, v2[0], v2[7]);
        v10 = v2[0];
        v11 = v2[0];
        v5 = v2[1];
        v6 = v2[1];
        if (v11 == v6)
        {
            DestroyTask(a1);
        }
        else
        {
            v7 = v2[2];
            v8 = v10 + v7;
            v2[0] = v8;
            if (v7 << 16 >= 0)
            {
                v9 = v8;
                if (v9 < v6)
                {
                    return;
                }
            }
            else if ((v9 = v8) > v6)
            {
                return;
            }
            v2[0] = v5;
        }
    }
    return;
}

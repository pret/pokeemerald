#include "global.h"
#include "palette.h"
#include "roulette.h"
#include "roulette_util.h"
#include "util.h"

void sub_8151678(struct UnkStruct0 *r0)
{
    r0->var00 = 0;
    r0->var02 = 0;
    memset(&r0->var04, 0, sizeof(r0->var04));
}

u8 sub_815168C(struct UnkStruct0 *r0, u8 r1, const struct UnkStruct1 *r2)
{
    if (!(r1 < 16) || (r0->var04[r1].var00_7))
        return 0xFF;

    r0->var04[r1].var04.var00 = r2->var00;
    r0->var04[r1].var04.var02 = r2->var02;
    r0->var04[r1].var04.var04 = r2->var04;
    r0->var04[r1].var04.var05 = r2->var05;
    r0->var04[r1].var04.var06 = r2->var06;
    r0->var04[r1].var04.var07_0 = r2->var07_0;
    r0->var04[r1].var04.var07_5 = r2->var07_5;
    r0->var04[r1].var04.var07_7 = r2->var07_7;
    r0->var04[r1].var00_0 = 0;
    r0->var04[r1].var00_7 = 1;
    r0->var04[r1].var02 = 0;
    r0->var04[r1].var01 = 0;
    if (r0->var04[r1].var04.var07_7 < 0)
        r0->var04[r1].var03 = 0xFF;
    else
        r0->var04[r1].var03 = 1;

    return r1;
}

u8 sub_8151710(struct UnkStruct0 *r0, u8 r1)
{
    if (r1 >= 16)
        return 0xFF;
    if (!r0->var04[r1].var00_7)
        return 0xFF;

    memset(&r0->var04[r1], 0, sizeof(r0->var04[r1]));
    return r1;
}

u8 sub_8151744(struct UnkStruct3 *r0)
{
    u8 i;
    u8 returnval;

    for (i = 0; i < r0->var04.var04; i++)
    {
        struct PlttData *faded =   (struct PlttData *)&gPlttBufferFaded[r0->var04.var02 + i];
        struct PlttData *unfaded = (struct PlttData *)&gPlttBufferUnfaded[r0->var04.var02 + i];

        switch (r0->var00_0)
        {
        case 1:
            if (faded->r + r0->var03 >= 0 && faded->r + r0->var03 < 32)
                faded->r += r0->var03;
            if (faded->g + r0->var03 >= 0 && faded->g + r0->var03 < 32)
                faded->g += r0->var03;
            if (faded->b + r0->var03 >= 0 && faded->b + r0->var03 < 32)
                faded->b += r0->var03;
            break;
        case 2:
            if (r0->var03 < 0)
            {
                if (faded->r + r0->var03 >= unfaded->r)
                    faded->r += r0->var03;
                if (faded->g + r0->var03 >= unfaded->g)
                    faded->g += r0->var03;
                if (faded->b + r0->var03 >= unfaded->b)
                    faded->b += r0->var03;
            }
            else
            {
                if (faded->r + r0->var03 <= unfaded->r)
                    faded->r += r0->var03;
                if (faded->g + r0->var03 <= unfaded->g)
                    faded->g += r0->var03;
                if (faded->b + r0->var03 <= unfaded->b)
                    faded->b += r0->var03;
            }
            break;
        }
    }
    if ((u32)r0->var02++ != r0->var04.var07_0)
    {
        returnval = 0;
    }
    else
    {
        r0->var02 = 0;
        r0->var03 *= -1;
        if (r0->var00_0 == 1)
            r0->var00_0++;
        else
            r0->var00_0--;
        returnval = 1;
    }
    return returnval;
}

u8 sub_815194C(struct UnkStruct3 *r0)
{
    u8 rg2 = 0;

    switch (r0->var00_0)
    {
    case 1:
        for (rg2 = 0; rg2 < r0->var04.var04; rg2++)
            gPlttBufferFaded[r0->var04.var02 + rg2] = r0->var04.var00;
        r0->var00_0++;
        break;
    case 2:
        for (rg2 = 0; rg2 < r0->var04.var04; rg2++)
            gPlttBufferFaded[r0->var04.var02 + rg2] = gPlttBufferUnfaded[r0->var04.var02 + rg2];
        r0->var00_0--;
        break;
    }
    return 1;
}

void task_tutorial_controls_fadein(struct UnkStruct0 *r0)
{
    u8 i = 0;

    if (r0->var00)
    {
        for (i = 0; i < 16; i++)
        {
            if ((r0->var02 >> i) & 1)
            {
                if (--r0->var04[i].var01 == 0xFF) // if underflow ?
                {
                    if (r0->var04[i].var04.var00 & 0x8000) // PlttData->unused_15 ?
                        sub_8151744(&r0->var04[i]);
                    else
                        sub_815194C(&r0->var04[i]);

                    r0->var04[i].var01 = r0->var04[i].var04.var05;
                }
            }
        }
    }
}

void sub_8151A48(struct UnkStruct0 *r0, u16 r1)
{
    u8 i = 0;

    r0->var00++;
    for (i = 0; i < 16; i++)
    {
        if ((r1 >> i) & 1)
        {
            if (r0->var04[i].var00_7)
            {
                r0->var02 |= 1 << i;
                r0->var04[i].var00_0 = 1;
            }
        }
    }
}

void sub_8151A9C(struct UnkStruct0 *r0, u16 r1)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        if ((r0->var02 >> i) & 1)
        {
            if (r0->var04[i].var00_7)
            {
                if ((r1 >> i) & 1)
                {
                    u32 offset = r0->var04[i].var04.var02;
                    u16 *faded = &gPlttBufferFaded[offset];
                    u16 *unfaded = &gPlttBufferUnfaded[offset];
                    memcpy(faded, unfaded, r0->var04[i].var04.var04 * 2);
                    r0->var04[i].var00_0 = 0;
                    r0->var04[i].var02 = 0;
                    r0->var04[i].var01 = 0;
                    if (r0->var04[i].var04.var07_7 < 0)
                        r0->var04[i].var03 = 0xFF;
                    else
                        r0->var04[i].var03 = 0x1;
                }
            }
        }
    }
    if (r1 == 0xFFFF)
    {
        r0->var00 = 0;
        r0->var02 = 0;
    }
    else
    {
        r0->var02 = r0->var02 & ~r1;
    }
}

void InitPulseBlend(struct PulseBlend *pulseBlend)
{
    u8 i = 0;
    pulseBlend->usedPulseBlendPalettes = 0;
    memset(&pulseBlend->pulseBlendPalettes, 0, sizeof(pulseBlend->pulseBlendPalettes));
    for (; i < 16; i++)
        pulseBlend->pulseBlendPalettes[i].paletteSelector = i;
}

int InitPulseBlendPaletteSettings(struct PulseBlend *pulseBlend, const struct PulseBlendSettings *settings)
{
    u8 i = 0;
    struct PulseBlendPalette *pulseBlendPalette = NULL;

    if (!pulseBlend->pulseBlendPalettes[0].inUse)
    {
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[0];
    }
    else
    {
        while (++i < 16)
        {
            if (!pulseBlend->pulseBlendPalettes[i].inUse)
            {
                pulseBlendPalette = &pulseBlend->pulseBlendPalettes[i];
                break;
            }
        }
    }

    if (pulseBlendPalette == NULL)
        return 0xFF;
    
    pulseBlendPalette->blendCoeff = 0;
    pulseBlendPalette->fadeDirection = 0;
    pulseBlendPalette->available = 1;
    pulseBlendPalette->inUse = 1;
    pulseBlendPalette->delayCounter = 0;
    pulseBlendPalette->fadeCycleCounter = 0;
    memcpy(&pulseBlendPalette->pulseBlendSettings, settings, sizeof(*settings));
    return i;
}

static void ClearPulseBlendPalettesSettings(struct PulseBlendPalette *pulseBlendPalette)
{
    u16 i;

    if (!pulseBlendPalette->available && pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
    {
        for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
            gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
    }

    memset(&pulseBlendPalette->pulseBlendSettings, 0, sizeof(pulseBlendPalette->pulseBlendSettings));
    pulseBlendPalette->blendCoeff = 0;
    pulseBlendPalette->fadeDirection = 0;
    pulseBlendPalette->unk1_5 = 0;
    pulseBlendPalette->available = 1;
    pulseBlendPalette->inUse = 0;
    pulseBlendPalette->fadeCycleCounter = 0;
    pulseBlendPalette->delayCounter = 0;
}

void UnloadUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection)
{
    u16 i = 0;

    if (!multiSelection)
    {
        ClearPulseBlendPalettesSettings(&pulseBlend->pulseBlendPalettes[pulseBlendPaletteSelector & 0xF]);
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            if ((pulseBlendPaletteSelector & 1) && pulseBlend->pulseBlendPalettes[i].inUse)
                ClearPulseBlendPalettesSettings(&pulseBlend->pulseBlendPalettes[i]);

            pulseBlendPaletteSelector >>= 1;
        }
    }
}

void MarkUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection)
{
    u8 i = 0;

    if (!multiSelection)
    {
        i = pulseBlendPaletteSelector & 0xF;
        pulseBlend->pulseBlendPalettes[i].available = 0;
        pulseBlend->usedPulseBlendPalettes |= 1 << i;
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            if (!(pulseBlendPaletteSelector & 1) || !pulseBlend->pulseBlendPalettes[i].inUse || !pulseBlend->pulseBlendPalettes[i].available)
            {
                pulseBlendPaletteSelector <<= 1;
            }
            else
            {
                pulseBlend->pulseBlendPalettes[i].available = 0;
                pulseBlend->usedPulseBlendPalettes |= 1 << i;
            }
        }
    }    
}

void UnmarkUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection)
{
    u16 i;
    struct PulseBlendPalette *pulseBlendPalette;
    u8 j = 0;

    if (!multiSelection)
    {
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[pulseBlendPaletteSelector & 0xF];
        if (!pulseBlendPalette->available && pulseBlendPalette->inUse)
        {
            if (pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
            {
                for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
                    gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
            }

            pulseBlendPalette->available = 1;
            pulseBlend->usedPulseBlendPalettes &= ~(1 << j);
        }
    }
    else
    {
        for (j = 0; j < 16; j++)
        {
            pulseBlendPalette = &pulseBlend->pulseBlendPalettes[j];
            if (!(pulseBlendPaletteSelector & 1) || pulseBlendPalette->available || !pulseBlendPalette->inUse)
            {
                pulseBlendPaletteSelector <<= 1;
            }
            else
            {
                if (pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
                {
                    for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
                        gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
                }

                pulseBlendPalette->available = 1;
                pulseBlend->usedPulseBlendPalettes &= ~(1 << j);
            }
        }
    }
}

void UpdatePulseBlend(struct PulseBlend *pulseBlend)
{
    struct PulseBlendPalette *pulseBlendPalette;
    u8 i = 0;

    if (pulseBlend->usedPulseBlendPalettes)
    {
        for (i = 0; i < 16; i++)
        {
            pulseBlendPalette = &pulseBlend->pulseBlendPalettes[i];
            if ((!pulseBlendPalette->available && pulseBlendPalette->inUse) && (!gPaletteFade.active || !pulseBlendPalette->pulseBlendSettings.unk7_7))
            {
                if (--pulseBlendPalette->delayCounter == 0xFF)
                {
                    pulseBlendPalette->delayCounter = pulseBlendPalette->pulseBlendSettings.delay;
                    BlendPalette(pulseBlendPalette->pulseBlendSettings.paletteOffset, pulseBlendPalette->pulseBlendSettings.numColors, pulseBlendPalette->blendCoeff, pulseBlendPalette->pulseBlendSettings.blendColor);
                    switch (pulseBlendPalette->pulseBlendSettings.fadeType)
                    {
                    case 0: // Fade all the way to the max blend amount, then wrap around
                        // BUG: This comparison will never be true for maxBlendCoeff values that are >= 8. This is because
                        // maxBlendCoeff is a signed 4-bit field, but blendCoeff is an unsigned 4-bit field. This code is never
                        // reached, anyway, so the bug is not observable in vanilla gameplay.
                        if (pulseBlendPalette->blendCoeff++ == pulseBlendPalette->pulseBlendSettings.maxBlendCoeff)
                        {
                            pulseBlendPalette->fadeCycleCounter++;
                            pulseBlendPalette->blendCoeff = 0;
                        }
                        break;
                    case 1: // Fade in and out
                        if (pulseBlendPalette->fadeDirection)
                        {
                            if (--pulseBlendPalette->blendCoeff == 0)
                            {
                                pulseBlendPalette->fadeCycleCounter++;
                                pulseBlendPalette->fadeDirection ^= 1;
                            }
                        }
                        else
                        {
                            u8 max = (pulseBlendPalette->pulseBlendSettings.maxBlendCoeff - 1) & 0xF;
                            if (pulseBlendPalette->blendCoeff++ == max)
                            {
                                pulseBlendPalette->fadeCycleCounter++;
                                pulseBlendPalette->fadeDirection ^= 1;
                            }
                        }
                        break;
                    case 2: // Flip back and forth
                        if (pulseBlendPalette->fadeDirection)
                            pulseBlendPalette->blendCoeff = 0;
                        else
                            pulseBlendPalette->blendCoeff = pulseBlendPalette->pulseBlendSettings.maxBlendCoeff & 0xF;
                        
                        pulseBlendPalette->fadeDirection ^= 1;
                        pulseBlendPalette->fadeCycleCounter++;
                        break;
                    }

                    if (pulseBlendPalette->pulseBlendSettings.numFadeCycles != 0xFF
                     && pulseBlendPalette->fadeCycleCounter == pulseBlendPalette->pulseBlendSettings.numFadeCycles)
                        UnmarkUsedPulseBlendPalettes(pulseBlend, pulseBlendPalette->paletteSelector, FALSE);
                }
            }
        }
    }
}

void sub_8152008(u16 *dest, u16 src, u8 left, u8 top, u8 width, u8 height)
{
    u16 *_dest;
    u8 i;
    u8 j;
    i = 0;
    dest = &dest[top * 32 + left];
    for (; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
        {
            *_dest++ = src;
        }
    }
}

void sub_8152058(u16 *dest, u16 *src, u8 left, u8 top, u8 width, u8 height)
{
    u16 *_dest;
    u16 *_src = src;
    u8 i;
    u8 j;
    i = 0;
    dest = &dest[top * 32 + left];
    for (; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
        {
            *_dest++ = *_src++;
        }
    }
}

#include "global.h"
#include "palette.h"
#include "palette_util.h"
#include "util.h"

// "RouletteFlash" is more accurately a general flashing/fading util
// this file handles fading the palettes for the color/icon selections on the Roulette wheel
// but it also handles the "pulse blend" effect of Mirage Tower

void RouletteFlash_Reset(struct RouletteFlashUtil *flash)
{
    flash->enabled = 0;
    flash->flags = 0;
    memset(&flash->palettes, 0, sizeof(flash->palettes));
}

u8 RouletteFlash_Add(struct RouletteFlashUtil *flash, u8 id, const struct RouletteFlashSettings *settings)
{
    if (id >= ARRAY_COUNT(flash->palettes) || flash->palettes[id].available)
        return 0xFF;

    flash->palettes[id].settings.color = settings->color;
    flash->palettes[id].settings.paletteOffset = settings->paletteOffset;
    flash->palettes[id].settings.numColors = settings->numColors;
    flash->palettes[id].settings.delay = settings->delay;
    flash->palettes[id].settings.unk6 = settings->unk6;
    flash->palettes[id].settings.numFadeCycles = settings->numFadeCycles;
    flash->palettes[id].settings.unk7_5 = settings->unk7_5;
    flash->palettes[id].settings.colorDeltaDir = settings->colorDeltaDir;
    flash->palettes[id].state = 0;
    flash->palettes[id].available = TRUE;
    flash->palettes[id].fadeCycleCounter = 0;
    flash->palettes[id].delayCounter = 0;
    if (flash->palettes[id].settings.colorDeltaDir < 0)
        flash->palettes[id].colorDelta = -1;
    else
        flash->palettes[id].colorDelta = 1;

    return id;
}

static u8 UNUSED RouletteFlash_Remove(struct RouletteFlashUtil *flash, u8 id)
{
    if (id >= ARRAY_COUNT(flash->palettes))
        return 0xFF;
    if (!flash->palettes[id].available)
        return 0xFF;

    memset(&flash->palettes[id], 0, sizeof(flash->palettes[id]));
    return id;
}

static u8 RouletteFlash_FadePalette(struct RouletteFlashPalette *pal)
{
    u8 i;
    struct PlttData *faded, *unfaded;

    for (i = 0; i < pal->settings.numColors; i++)
    {
        faded = (struct PlttData *)&gPlttBufferFaded[pal->settings.paletteOffset + i];
        unfaded = (struct PlttData *)&gPlttBufferUnfaded[pal->settings.paletteOffset + i];

        switch (pal->state)
        {
        case 1:
            // Fade color
            if (faded->r + pal->colorDelta < 32 && faded->r + pal->colorDelta >= 0)
                faded->r += pal->colorDelta;
            if (faded->g + pal->colorDelta < 32 && faded->g + pal->colorDelta >= 0)
                faded->g += pal->colorDelta;
            if (faded->b + pal->colorDelta < 32 && faded->b + pal->colorDelta >= 0)
                faded->b += pal->colorDelta;
            break;
        case 2:
            // Fade back to original color
            if (pal->colorDelta < 0)
            {
                if (faded->r + pal->colorDelta >= unfaded->r)
                    faded->r += pal->colorDelta;
                if (faded->g + pal->colorDelta >= unfaded->g)
                    faded->g += pal->colorDelta;
                if (faded->b + pal->colorDelta >= unfaded->b)
                    faded->b += pal->colorDelta;
            }
            else
            {
                if (faded->r + pal->colorDelta <= unfaded->r)
                    faded->r += pal->colorDelta;
                if (faded->g + pal->colorDelta <= unfaded->g)
                    faded->g += pal->colorDelta;
                if (faded->b + pal->colorDelta <= unfaded->b)
                    faded->b += pal->colorDelta;
            }
            break;
        }
    }

    if (pal->fadeCycleCounter++ != (u8)pal->settings.numFadeCycles)
        return 0;

    pal->fadeCycleCounter = 0;
    pal->colorDelta *= -1;

    if (pal->state == 1)
        pal->state++;
    else
        pal->state--;
    return 1;
}

static u8 RouletteFlash_FlashPalette(struct RouletteFlashPalette *pal)
{
    u8 i = 0;
    switch (pal->state)
    {
    case 1:
        // Flash to color
        for (i = 0; i < pal->settings.numColors; i++)
            gPlttBufferFaded[pal->settings.paletteOffset + i] = pal->settings.color;
        pal->state++;
        break;
    case 2:
        // Restore to original color
        for (i = 0; i < pal->settings.numColors; i++)
            gPlttBufferFaded[pal->settings.paletteOffset + i] =
                gPlttBufferUnfaded[pal->settings.paletteOffset + i];
        pal->state--;
        break;
    }
    return 1;
}

void RouletteFlash_Run(struct RouletteFlashUtil *flash)
{
    u8 i = 0;

    if (!flash->enabled)
        return;

    for (i = 0; i < ARRAY_COUNT(flash->palettes); i++)
    {
        if (!((flash->flags >> i) & 1))
            continue;

        if (flash->palettes[i].delayCounter-- == 0)
        {
            if (flash->palettes[i].settings.color & FLASHUTIL_USE_EXISTING_COLOR)
                RouletteFlash_FadePalette(&flash->palettes[i]);
            else
                RouletteFlash_FlashPalette(&flash->palettes[i]);

            flash->palettes[i].delayCounter = flash->palettes[i].settings.delay;
        }
    }
}

void RouletteFlash_Enable(struct RouletteFlashUtil *flash, u16 flags)
{
    u8 i = 0;

    flash->enabled++;
    for (i = 0; i < ARRAY_COUNT(flash->palettes); i++)
    {
        if ((flags >> i) & 1)
        {
            if (flash->palettes[i].available)
            {
                flash->flags |= 1 << i;
                flash->palettes[i].state = 1;
            }
        }
    }
}

void RouletteFlash_Stop(struct RouletteFlashUtil *flash, u16 flags)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(flash->palettes); i++)
    {
        if ((flash->flags >> i) & 1)
        {
            if (flash->palettes[i].available)
            {
                if ((flags >> i) & 1)
                {
                    memcpy(&gPlttBufferFaded[flash->palettes[i].settings.paletteOffset],
                        &gPlttBufferUnfaded[flash->palettes[i].settings.paletteOffset],
                        flash->palettes[i].settings.numColors * 2);

                    flash->palettes[i].state = 0;
                    flash->palettes[i].fadeCycleCounter = 0;
                    flash->palettes[i].delayCounter = 0;
                    if (flash->palettes[i].settings.colorDeltaDir < 0)
                        flash->palettes[i].colorDelta = -1;
                    else
                        flash->palettes[i].colorDelta = 1;
                }
            }
        }
    }

    if (flags == 0xFFFF)
    {
        // Stopped all
        flash->enabled = 0;
        flash->flags = 0;
    }
    else
    {
        flash->flags &= ~flags;
    }
}

void InitPulseBlend(struct PulseBlend *pulseBlend)
{
    u8 i = 0;
    pulseBlend->usedPulseBlendPalettes = 0;
    memset(pulseBlend->pulseBlendPalettes, 0, sizeof(pulseBlend->pulseBlendPalettes));
    for (i = 0; i < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); i++)
        pulseBlend->pulseBlendPalettes[i].paletteSelector = i;
}

u8 InitPulseBlendPaletteSettings(
    struct PulseBlend *pulseBlend, const struct PulseBlendSettings *settings)
{
    u8 i = 0;
    struct PulseBlendPalette *pulseBlendPalette = NULL;

    for (i = 0; i < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); i++)
    {
        if (!pulseBlend->pulseBlendPalettes[i].inUse)
        {
            pulseBlendPalette = &pulseBlend->pulseBlendPalettes[i];
            break;
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
    if (!pulseBlendPalette->available && pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
    {
        u16 i;
        for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
            gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
    }

    memset(&pulseBlendPalette->pulseBlendSettings, 0, sizeof(pulseBlendPalette->pulseBlendSettings));
    pulseBlendPalette->blendCoeff = 0;
    pulseBlendPalette->fadeDirection = 0;
    pulseBlendPalette->flags = 0;
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
        return;
    }

    for (i = 0; i < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); i++)
    {
        if ((pulseBlendPaletteSelector & 1) && pulseBlend->pulseBlendPalettes[i].inUse)
            ClearPulseBlendPalettesSettings(&pulseBlend->pulseBlendPalettes[i]);

        pulseBlendPaletteSelector >>= 1;
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
        return;
    }

    for (i = 0; i < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); i++)
    {
        if (!(pulseBlendPaletteSelector & 1) || !pulseBlend->pulseBlendPalettes[i].inUse ||
            !pulseBlend->pulseBlendPalettes[i].available)
        {
            pulseBlendPaletteSelector <<= 1;
            continue;
        }

        pulseBlend->pulseBlendPalettes[i].available = 0;
        pulseBlend->usedPulseBlendPalettes |= 1 << i;
    }
}

void UnmarkUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection)
{
    u8 j = 0;
    u16 i = 0;
    struct PulseBlendPalette *pulseBlendPalette;


    if (!multiSelection)
    {
#ifdef BUGFIX
        j = pulseBlendPaletteSelector & 0xF;
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[j];
#else
        // BUG: j stays 0, so usedPulseBlendPalettes clears bit 0 instead of the marked index.
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[pulseBlendPaletteSelector & 0xF];
#endif
        if (pulseBlendPalette->inUse == 0 || pulseBlendPalette->available)
            return;

        if (pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
        {
            for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
                gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
        }

        pulseBlendPalette->available = 1;
        pulseBlend->usedPulseBlendPalettes &= ~(1 << j);
        return;
    }

    for (j = 0; j < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); j++)
    {
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[j];
        if (!(pulseBlendPaletteSelector & 1) || !pulseBlendPalette->inUse || pulseBlendPalette->available)
        {
            pulseBlendPaletteSelector <<= 1;
            continue;
        }

        if (pulseBlendPalette->pulseBlendSettings.restorePaletteOnUnload)
        {
            for (i = pulseBlendPalette->pulseBlendSettings.paletteOffset; i < pulseBlendPalette->pulseBlendSettings.paletteOffset + pulseBlendPalette->pulseBlendSettings.numColors; i++)
                gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
        }

        pulseBlendPalette->available = 1;
        pulseBlend->usedPulseBlendPalettes &= ~(1 << j);
    }
}

void UpdatePulseBlend(struct PulseBlend *pulseBlend)
{
    u8 i = 0;
    u8 j = 0;
    struct PulseBlendPalette *pulseBlendPalette = NULL;

    if (!pulseBlend->usedPulseBlendPalettes)
        return;

    for (i = 0; i < ARRAY_COUNT(pulseBlend->pulseBlendPalettes); i++)
    {
        pulseBlendPalette = &pulseBlend->pulseBlendPalettes[i];
        if (!pulseBlendPalette->inUse || pulseBlendPalette->available)
            continue;
        if (gPaletteFade.active && pulseBlendPalette->pulseBlendSettings.unk7_7)
            continue;
        if (pulseBlendPalette->delayCounter-- != 0)
            continue;

        pulseBlendPalette->delayCounter = pulseBlendPalette->pulseBlendSettings.delay;

        BlendPalette(pulseBlendPalette->pulseBlendSettings.paletteOffset,
            pulseBlendPalette->pulseBlendSettings.numColors,
            (u16)pulseBlendPalette->blendCoeff,
            pulseBlendPalette->pulseBlendSettings.blendColor);

        switch (pulseBlendPalette->pulseBlendSettings.fadeType)
        {
        case 0:
            // Fade all the way to the max blend amount, then wrap around
            // BUG: This comparison will never be true for maxBlendCoeff values that are >= 8. This
            // is because maxBlendCoeff is a signed 4-bit field, but blendCoeff is an unsigned 4-bit
            // field. This code is never reached, anyway, so the bug is not observable in vanilla
            // gameplay.
            if (pulseBlendPalette->blendCoeff++ ==
                pulseBlendPalette->pulseBlendSettings.maxBlendCoeff)
            {
                pulseBlendPalette->fadeCycleCounter++;
                pulseBlendPalette->blendCoeff = 0;
            }
            break;
        case 1:
            if (pulseBlendPalette->fadeDirection)
            {
                if (pulseBlendPalette->blendCoeff-- == 1)
                {
                    pulseBlendPalette->fadeCycleCounter++;
                    pulseBlendPalette->fadeDirection ^= 1;
                }
            }
            else
            {
                j = (pulseBlendPalette->pulseBlendSettings.maxBlendCoeff - 1) & 0xF;
                if (pulseBlendPalette->blendCoeff++ == j)
                {
                    pulseBlendPalette->fadeCycleCounter++;
                    pulseBlendPalette->fadeDirection ^= 1;
                }
            }
            break;
#ifdef UBFIX
        case -2:
#else
        case 2:
#endif
            if (pulseBlendPalette->fadeDirection)
                pulseBlendPalette->blendCoeff = 0;
            else
                pulseBlendPalette->blendCoeff = pulseBlendPalette->pulseBlendSettings.maxBlendCoeff & 0xF;

            pulseBlendPalette->fadeDirection ^= 1;
            pulseBlendPalette->fadeCycleCounter++;
        default:
            break;
        }
        if (pulseBlendPalette->pulseBlendSettings.numFadeCycles == 0xFF)
            continue;
        if (pulseBlendPalette->fadeCycleCounter != pulseBlendPalette->pulseBlendSettings.numFadeCycles)
            continue;

        UnmarkUsedPulseBlendPalettes(pulseBlend, pulseBlendPalette->paletteSelector, FALSE);
    }
}

// Below used for the Roulette grid
void FillTilemapRect(u16 *dest, u16 value, u8 left, u8 top, u8 width, u8 height)
{
    u8 i = 0, j = 0;
    u16 *_dest = NULL;

    dest += top * 32 + left;
    for (i = 0; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
            *_dest++ = value;
    }
}

void SetTilemapRect(u16 *dest, const u16 *src, u8 left, u8 top, u8 width, u8 height)
{
    u8 i = 0, j = 0;
    u16 *_dest = NULL;
    u16 *_src = (u16 *)src;

    dest += top * 32 + left;
    for (i = 0; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
            *_dest++ = *_src++;
    }
}

static void UNUSED FillTilemapRect_Unused(void *dest, u16 value, u8 left, u8 top, u8 width, u8 height)
{
    u8 i, j;
    u8 x, y;

    for (i = 0, y = top; i < height; i++)
    {
        for (x = left, j = 0; j < width; j++)
        {
            *(u16 *)((dest) + (y * 64 + x * 2)) = value;
            x = (x + 1) % 32;
        }
        y = (y + 1) % 32;
    }
}

static void UNUSED SetTilemapRect_Unused(void *dest, const u16 *src, u8 left, u8 top, u8 width, u8 height)
{
    u8 i, j;
    u8 x, y;
    const u16 *_src;

    for (i = 0, _src = src, y = top; i < height; i++)
    {
        for (x = left, j = 0; j < width; j++)
        {
            *(u16 *)((dest) + (y * 64 + x * 2)) = *(_src++);
            x = (x + 1) % 32;
        }
        y = (y + 1) % 32;
    }
}

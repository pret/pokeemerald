#ifndef GUARD_PALETTE_UTIL_H
#define GUARD_PALETTE_UTIL_H

struct PulseBlendSettings
{
    u16 blendColor;
    u16 paletteOffset;
    u8 numColors;
    u8 delay;
    u8 numFadeCycles;
    s8 maxBlendCoeff:4;
    s8 fadeType:2;
    s8 restorePaletteOnUnload:1;
    s8 unk7_7:1;
};

struct PulseBlendPalette
{
    u8 paletteSelector;
    u8 blendCoeff:4;
    u8 fadeDirection:1;
    s8 unk1_5:1;
    s8 available:1;
    u32 inUse:1;
    u8 delayCounter;
    u8 fadeCycleCounter;
    struct PulseBlendSettings pulseBlendSettings;
};

struct PulseBlend
{
    u16 usedPulseBlendPalettes;
    struct PulseBlendPalette pulseBlendPalettes[16];
};


#define FLASHUTIL_USE_EXISTING_COLOR (1 << 15)

struct RouletteFlashSettings
{
    u16 color;
    u16 paletteOffset;
    u8 numColors;
    u8 delay;
    s8 unk6;      // Set but never used
    s8 numFadeCycles:5;
    s8 unk7_5:2;  // Set but never used
    s8 colorDeltaDir:1;
};

struct RouletteFlashPalette
{
    u8 state:7;
    bool8 available:1;
    u8 delayCounter;
    s8 fadeCycleCounter;
    s8 colorDelta;
    struct RouletteFlashSettings settings;
};

struct RouletteFlashUtil
{
    u8 enabled;
    u8 unused;
    u16 flags;
    struct RouletteFlashPalette palettes[16];
};

int InitPulseBlendPaletteSettings(struct PulseBlend *pulseBlend, const struct PulseBlendSettings *settings);
void InitPulseBlend(struct PulseBlend *pulseBlend);
void MarkUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection);
void UnloadUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection);
void UnmarkUsedPulseBlendPalettes(struct PulseBlend *pulseBlend, u16 pulseBlendPaletteSelector, u8 multiSelection);
void UpdatePulseBlend(struct PulseBlend *pulseBlend);
void FillTilemapRect(u16 *dest, u16 value, u8 left, u8 top, u8 width, u8 height);
void SetTilemapRect(u16 *dest, u16 *src, u8 left, u8 top, u8 width, u8 height);
void RouletteFlash_Run(struct RouletteFlashUtil *flash);
void RouletteFlash_Reset(struct RouletteFlashUtil *flash);
u8 RouletteFlash_Add(struct RouletteFlashUtil *flash, u8 id, const struct RouletteFlashSettings *settings);
void RouletteFlash_Stop(struct RouletteFlashUtil *flash, u16 flags);
void RouletteFlash_Enable(struct RouletteFlashUtil *flash, u16 flags);

#endif // GUARD_PALETTE_UTIL_H

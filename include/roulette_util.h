#ifndef GUARD_ROULETTE_UTIL_H
#define GUARD_ROULETTE_UTIL_H

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

struct UnkStruct1
{
    u16 var00;
    u16 var02;
    u8 var04;
    u8 var05;
    u8 var06;
    s8 var07_0:5;
    s8 var07_5:2;
    s8 var07_7:1;
};

struct UnkStruct3
{
    u8 var00_0:7;
    bool8 active:1;
    u8 var01;
    s8 var02;
    s8 var03;
    struct UnkStruct1 var04;
};

struct UnkStruct0
{
    u8 var00;
    u8 var01;
    u16 var02; //flag for each UnkStruct3
    struct UnkStruct3 var04[0x10];
};

int InitPulseBlendPaletteSettings(struct PulseBlend *, const struct PulseBlendSettings *);
void InitPulseBlend(struct PulseBlend *);
void MarkUsedPulseBlendPalettes(struct PulseBlend *, u16, u8);
void UnloadUsedPulseBlendPalettes(struct PulseBlend *, u16, u8);
void UnmarkUsedPulseBlendPalettes(struct PulseBlend *, u16, u8);
void UpdatePulseBlend(struct PulseBlend *);
void ClearTilemapRect(u16 *dest, u16 src, u8 left, u8 top, u8 width, u8 height);
void SetTilemapRect(u16 *dest, u16 *src, u8 left, u8 top, u8 width, u8 height);
void task_tutorial_controls_fadein(struct UnkStruct0 *r0);
void sub_8151678(struct UnkStruct0 *r0);
u8 sub_815168C(struct UnkStruct0 *r0, u8 r1, const struct UnkStruct1 *r2);
void sub_8151A9C(struct UnkStruct0 *r0, u16 r1);
void sub_8151A48(struct UnkStruct0 *r0, u16 r1);

#endif // GUARD_ROULETTE_UTIL_H

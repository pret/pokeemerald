#ifndef GUARD_SCANLINE_EFFECT_H
#define GUARD_SCANLINE_EFFECT_H

// DMA control value to transfer a single 16-bit value at HBlank
#define SCANLINE_EFFECT_DMACNT_16BIT (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_16BIT | DMA_DEST_RELOAD) << 16) | 1)
#define SCANLINE_EFFECT_DMACNT_32BIT (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_32BIT | DMA_DEST_RELOAD) << 16) | 1)

#define SCANLINE_EFFECT_REG_BG0HOFS (REG_ADDR_BG0HOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG0VOFS (REG_ADDR_BG0VOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG1HOFS (REG_ADDR_BG1HOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG1VOFS (REG_ADDR_BG1VOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG2HOFS (REG_ADDR_BG2HOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG2VOFS (REG_ADDR_BG2VOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG3HOFS (REG_ADDR_BG3HOFS - REG_ADDR_BG0HOFS)
#define SCANLINE_EFFECT_REG_BG3VOFS (REG_ADDR_BG3VOFS - REG_ADDR_BG0HOFS)

struct ScanlineEffectParams
{
    volatile void *dmaDest;
    u32 dmaControl;
    u8 initState;
    u8 unused9;
};

struct ScanlineEffect
{
    void *dmaSrcBuffers[2];
    volatile void *dmaDest;
    u32 dmaControl;
    void (*setFirstScanlineReg)(void);
    u8 srcBuffer;
    u8 state;
    u8 unused16;
    u8 unused17;
    u8 waveTaskId;
};

extern struct ScanlineEffect gScanlineEffect;

extern u16 gScanlineEffectRegBuffers[2][0x3C0];

void ScanlineEffect_Stop(void);
void ScanlineEffect_Clear(void);
void ScanlineEffect_SetParams(struct ScanlineEffectParams);
void ScanlineEffect_InitHBlankDmaTransfer(void);
u8 ScanlineEffect_InitWave(u8 startLine, u8 endLine, u8 frequency, u8 amplitude, u8 delayInterval, u8 regOffset, bool8 a7);

#endif // GUARD_SCANLINE_EFFECT_H

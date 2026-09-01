#include "global.h"
#include "battle.h"
#include "data.h"
#include "task.h"
#include "trig.h"
#include "scanline_effect.h"

static void CopyValue16Bit(void);
static void CopyValue32Bit(void);

// EWRAM vars

// Per-scanline register values.
// This is double buffered so that it can be safely written to at any time
// without overwriting the buffer that the DMA is currently reading
EWRAM_DATA u16 ALIGNED(4) gScanlineEffectRegBuffers[2][0x3C0] = {0};

EWRAM_DATA struct ScanlineEffect gScanlineEffect = {0};
EWRAM_DATA static bool8 sShouldStopWaveTask = FALSE;

void ScanlineEffect_Stop(void)
{
    gScanlineEffect.state = 0;
    DmaStop(0);
    if (gScanlineEffect.waveTaskId != TASK_NONE)
    {
        DestroyTask(gScanlineEffect.waveTaskId);
        gScanlineEffect.waveTaskId = TASK_NONE;
    }
}

void ScanlineEffect_Clear(void)
{
    CpuFill16(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    gScanlineEffect.dmaSrcBuffers[0] = NULL;
    gScanlineEffect.dmaSrcBuffers[1] = NULL;
    gScanlineEffect.dmaDest = NULL;
    gScanlineEffect.dmaControl = 0;
    gScanlineEffect.srcBuffer = 0;
    gScanlineEffect.state = 0;
    gScanlineEffect.waveTaskId = TASK_NONE;
}

void ScanlineEffect_SetParams(struct ScanlineEffectParams params)
{
    if (params.dmaControl == SCANLINE_EFFECT_DMACNT_16BIT)  // 16-bit
    {
        // Set the DMA src to the value for the second scanline because the
        // first DMA transfer occurs in HBlank *after* the first scanline is drawn
        gScanlineEffect.dmaSrcBuffers[0] = (u16 *)gScanlineEffectRegBuffers[0] + 1;
        gScanlineEffect.dmaSrcBuffers[1] = (u16 *)gScanlineEffectRegBuffers[1] + 1;
        gScanlineEffect.setFirstScanlineReg = CopyValue16Bit;
    }
    else  // assume 32-bit
    {
        // Set the DMA src to the value for the second scanline because the
        // first DMA transfer occurs in HBlank *after* the first scanline is drawn
        gScanlineEffect.dmaSrcBuffers[0] = (u32 *)gScanlineEffectRegBuffers[0] + 1;
        gScanlineEffect.dmaSrcBuffers[1] = (u32 *)gScanlineEffectRegBuffers[1] + 1;
        gScanlineEffect.setFirstScanlineReg = CopyValue32Bit;
    }

    gScanlineEffect.dmaControl = params.dmaControl;
    gScanlineEffect.dmaDest    = params.dmaDest;
    gScanlineEffect.state      = params.initState;
}

void ScanlineEffect_InitHBlankDmaTransfer(void)
{
    if (gScanlineEffect.state == 0)
    {
        return;
    }
    else if (gScanlineEffect.state == 3)
    {
        gScanlineEffect.state = 0;
        DmaStop(0);
        sShouldStopWaveTask = TRUE;
    }
    else
    {
        DmaStop(0);
        // Set DMA to copy to dest register on each HBlank for the next frame.
        // The HBlank DMA transfers do not occurr during VBlank, so the transfer
        // will begin on the HBlank after the first scanline
        DmaSet(0, gScanlineEffect.dmaSrcBuffers[gScanlineEffect.srcBuffer], gScanlineEffect.dmaDest, gScanlineEffect.dmaControl);
        // Manually set the reg for the first scanline
        gScanlineEffect.setFirstScanlineReg();
        // Swap current buffer
        gScanlineEffect.srcBuffer ^= 1;
    }
}

// These two functions are used to copy the register for the first scanline,
// depending whether it is a 16-bit register or a 32-bit register.

static void CopyValue16Bit(void)
{
    vu16 *dest = (vu16 *)gScanlineEffect.dmaDest;
    vu16 *src = (vu16 *)&gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer];

    *dest = *src;
}

static void CopyValue32Bit(void)
{
    vu32 *dest = (vu32 *)gScanlineEffect.dmaDest;
    vu32 *src = (vu32 *)&gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer];

    *dest = *src;
}

#define tStartLine            data[0]
#define tEndLine              data[1]
#define tWaveLength           data[2]
#define tSrcBufferOffset      data[3]
#define tFramesUntilMove      data[4]
#define tDelayInterval        data[5]
#define tRegOffset            data[6]
#define tApplyBattleBgOffsets data[7]

static void TaskFunc_UpdateWavePerFrame(u8 taskId)
{
    int value = 0;
    int i;
    int offset;

    if (sShouldStopWaveTask)
    {
        DestroyTask(taskId);
        gScanlineEffect.waveTaskId = TASK_NONE;
    }
    else
    {
        if (gTasks[taskId].tApplyBattleBgOffsets)
        {
            switch (gTasks[taskId].tRegOffset)
            {
            case SCANLINE_EFFECT_REG_BG0HOFS:
                value = gBattle_BG0_X;
                break;
            case SCANLINE_EFFECT_REG_BG0VOFS:
                value = gBattle_BG0_Y;
                break;
            case SCANLINE_EFFECT_REG_BG1HOFS:
                value = gBattle_BG1_X;
                break;
            case SCANLINE_EFFECT_REG_BG1VOFS:
                value = gBattle_BG1_Y;
                break;
            case SCANLINE_EFFECT_REG_BG2HOFS:
                value = gBattle_BG2_X;
                break;
            case SCANLINE_EFFECT_REG_BG2VOFS:
                value = gBattle_BG2_Y;
                break;
            case SCANLINE_EFFECT_REG_BG3HOFS:
                value = gBattle_BG3_X;
                break;
            case SCANLINE_EFFECT_REG_BG3VOFS:
                value = gBattle_BG3_Y;
                break;
            }
        }
        if (gTasks[taskId].tFramesUntilMove != 0)
        {
            gTasks[taskId].tFramesUntilMove--;
            offset = gTasks[taskId].tSrcBufferOffset + 320;
            for (i = gTasks[taskId].tStartLine; i < gTasks[taskId].tEndLine; i++)
            {
                gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gScanlineEffectRegBuffers[0][offset] + value;
                offset++;
            }
        }
        else
        {
            gTasks[taskId].tFramesUntilMove = gTasks[taskId].tDelayInterval;
            offset = gTasks[taskId].tSrcBufferOffset + 320;
            for (i = gTasks[taskId].tStartLine; i < gTasks[taskId].tEndLine; i++)
            {
                gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gScanlineEffectRegBuffers[0][offset] + value;
                offset++;
            }

            // increment src buffer offset
            gTasks[taskId].tSrcBufferOffset++;
            if (gTasks[taskId].tSrcBufferOffset == gTasks[taskId].tWaveLength)
                gTasks[taskId].tSrcBufferOffset = 0;
        }
    }
}

static void GenerateWave(u16 *buffer, u8 frequency, u8 amplitude, u8 unused)
{
    u16 i = 0;
    u8 theta = 0;

    while (i < 256)
    {
        buffer[i] = (gSineTable[theta] * amplitude) / 256;
        theta += frequency;
        i++;
    }
}

// Initializes a background "wave" effect that affects scanlines startLine (inclusive) to endLine (exclusive).
// 'frequency' and 'amplitude' control the frequency and amplitude of the wave.
// 'delayInterval' controls how fast the wave travels up the screen. The wave will shift upwards one scanline every 'delayInterval'+1 frames.
// 'regOffset' is the offset of the video register to modify.
u8 ScanlineEffect_InitWave(u8 startLine, u8 endLine, u8 frequency, u8 amplitude, u8 delayInterval, u8 regOffset, bool8 applyBattleBgOffsets)
{
    int i;
    int offset;
    struct ScanlineEffectParams params;
    u8 taskId;

    ScanlineEffect_Clear();

    params.dmaDest = (void *)(REG_ADDR_BG0HOFS + regOffset);
    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.initState = 1;
    params.unused9 = 0;
    ScanlineEffect_SetParams(params);

    taskId = CreateTask(TaskFunc_UpdateWavePerFrame, 0);

    gTasks[taskId].tStartLine            = startLine;
    gTasks[taskId].tEndLine              = endLine;
    gTasks[taskId].tWaveLength           = 256 / frequency;
    gTasks[taskId].tSrcBufferOffset      = 0;
    gTasks[taskId].tFramesUntilMove      = delayInterval;
    gTasks[taskId].tDelayInterval        = delayInterval;
    gTasks[taskId].tRegOffset            = regOffset;
    gTasks[taskId].tApplyBattleBgOffsets = applyBattleBgOffsets;

    gScanlineEffect.waveTaskId = taskId;
    sShouldStopWaveTask = FALSE;

    GenerateWave(&gScanlineEffectRegBuffers[0][320], frequency, amplitude, endLine - startLine);

    offset = 320;
    for (i = startLine; i < endLine; i++)
    {
        gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[0][offset];
        gScanlineEffectRegBuffers[1][i] = gScanlineEffectRegBuffers[0][offset];
        offset++;
    }

    return taskId;
}

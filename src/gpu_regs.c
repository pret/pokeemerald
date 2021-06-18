#include "global.h"
#include "gpu_regs.h"

#define GPU_REG_BUF_SIZE 0x60

#define GPU_REG_BUF(offset) (*(u16 *)(&sGpuRegBuffer[offset]))
#define GPU_REG(offset) (*(vu16 *)(REG_BASE + offset))

#define EMPTY_SLOT 0xFF

static u8 sGpuRegBuffer[GPU_REG_BUF_SIZE];
static u8 sGpuRegWaitingList[GPU_REG_BUF_SIZE];
static volatile bool8 sGpuRegBufferLocked;
static volatile bool8 sShouldSyncRegIE;
static vu16 sRegIE;

static void CopyBufferedValueToGpuReg(u8 regOffset);
static void SyncRegIE(void);
static void UpdateRegDispstatIntrBits(u16 regIE);

void InitGpuRegManager(void)
{
    s32 i;

    for (i = 0; i < GPU_REG_BUF_SIZE; i++)
    {
        sGpuRegBuffer[i] = 0;
        sGpuRegWaitingList[i] = EMPTY_SLOT;
    }

    sGpuRegBufferLocked = FALSE;
    sShouldSyncRegIE = FALSE;
    sRegIE = 0;
}

static void CopyBufferedValueToGpuReg(u8 regOffset)
{
    if (regOffset == REG_OFFSET_DISPSTAT)
    {
        REG_DISPSTAT &= ~(DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR);
        REG_DISPSTAT |= GPU_REG_BUF(REG_OFFSET_DISPSTAT);
    }
    else
    {
        GPU_REG(regOffset) = GPU_REG_BUF(regOffset);
    }
}

void CopyBufferedValuesToGpuRegs(void)
{
    if (!sGpuRegBufferLocked)
    {
        s32 i;

        for (i = 0; i < GPU_REG_BUF_SIZE; i++)
        {
            u8 regOffset = sGpuRegWaitingList[i];
            if (regOffset == EMPTY_SLOT)
                return;
            CopyBufferedValueToGpuReg(regOffset);
            sGpuRegWaitingList[i] = EMPTY_SLOT;
        }
    }
}

void SetGpuReg(u8 regOffset, u16 value)
{
    if (regOffset < GPU_REG_BUF_SIZE)
    {
        u16 vcount;

        GPU_REG_BUF(regOffset) = value;
        vcount = REG_VCOUNT & 0xFF;

        if ((vcount >= 161 && vcount <= 225) || (REG_DISPCNT & DISPCNT_FORCED_BLANK))
        {
            CopyBufferedValueToGpuReg(regOffset);
        }
        else
        {
            s32 i;

            sGpuRegBufferLocked = TRUE;

            for (i = 0; i < GPU_REG_BUF_SIZE && sGpuRegWaitingList[i] != EMPTY_SLOT; i++)
            {
                if (sGpuRegWaitingList[i] == regOffset)
                {
                    sGpuRegBufferLocked = FALSE;
                    return;
                }
            }

            sGpuRegWaitingList[i] = regOffset;
            sGpuRegBufferLocked = FALSE;
        }
    }
}

void SetGpuReg_ForcedBlank(u8 regOffset, u16 value)
{
    if (regOffset < GPU_REG_BUF_SIZE)
    {
        GPU_REG_BUF(regOffset) = value;

        if (REG_DISPCNT & DISPCNT_FORCED_BLANK)
        {
            CopyBufferedValueToGpuReg(regOffset);
        }
        else
        {
            s32 i;

            sGpuRegBufferLocked = TRUE;

            for (i = 0; i < GPU_REG_BUF_SIZE && sGpuRegWaitingList[i] != EMPTY_SLOT; i++)
            {
                if (sGpuRegWaitingList[i] == regOffset)
                {
                    sGpuRegBufferLocked = FALSE;
                    return;
                }
            }

            sGpuRegWaitingList[i] = regOffset;
            sGpuRegBufferLocked = FALSE;
        }
    }
}

u16 GetGpuReg(u8 regOffset)
{
    if (regOffset == REG_OFFSET_DISPSTAT)
        return REG_DISPSTAT;

    if (regOffset == REG_OFFSET_VCOUNT)
        return REG_VCOUNT;

    return GPU_REG_BUF(regOffset);
}

void SetGpuRegBits(u8 regOffset, u16 mask)
{
    u16 regValue = GPU_REG_BUF(regOffset);
    SetGpuReg(regOffset, regValue | mask);
}

void ClearGpuRegBits(u8 regOffset, u16 mask)
{
    u16 regValue = GPU_REG_BUF(regOffset);
    SetGpuReg(regOffset, regValue & ~mask);
}

static void SyncRegIE(void)
{
    if (sShouldSyncRegIE)
    {
        u16 temp = REG_IME;
        REG_IME = 0;
        REG_IE = sRegIE;
        REG_IME = temp;
        sShouldSyncRegIE = FALSE;
    }
}

void EnableInterrupts(u16 mask)
{
    sRegIE |= mask;
    sShouldSyncRegIE = TRUE;
    SyncRegIE();
    UpdateRegDispstatIntrBits(sRegIE);
}

void DisableInterrupts(u16 mask)
{
    sRegIE &= ~mask;
    sShouldSyncRegIE = TRUE;
    SyncRegIE();
    UpdateRegDispstatIntrBits(sRegIE);
}

static void UpdateRegDispstatIntrBits(u16 regIE)
{
    u16 oldValue = GetGpuReg(REG_OFFSET_DISPSTAT) & (DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR);
    u16 newValue = 0;

    if (regIE & INTR_FLAG_VBLANK)
        newValue |= DISPSTAT_VBLANK_INTR;

    if (regIE & INTR_FLAG_HBLANK)
        newValue |= DISPSTAT_HBLANK_INTR;

    if (oldValue != newValue)
        SetGpuReg(REG_OFFSET_DISPSTAT, newValue);
}

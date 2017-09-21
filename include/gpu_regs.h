
#ifndef GUARD_GPU_REGS_H
#define GUARD_GPU_REGS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void DisableInterrupts(u16);
void EnableInterrupts(u16);
void SetGpuReg(u8, u16);
void ClearGpuRegBits(u8 regOffset, u16 mask);

#endif //GUARD_GPU_REGS_H

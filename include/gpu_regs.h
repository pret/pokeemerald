#ifndef GUARD_gpu_regs_H
#define GUARD_gpu_regs_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void DisableInterrupts(u16);
void EnableInterrupts(u16);
void SetGpuReg(u8, u16);

#endif //GUARD_gpu_regs_H

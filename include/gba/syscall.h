#ifndef GUARD_GBA_SYSCALL_H
#define GUARD_GBA_SYSCALL_H

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_16BIT     0x00000000
#define CPU_SET_32BIT     0x04000000

extern void CpuSet(void *src, void *dest, u32 controlData);

#endif // GUARD_GBA_SYSCALL_H

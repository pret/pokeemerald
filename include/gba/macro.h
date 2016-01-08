#ifndef GUARD_GBA_MACRO_H
#define GUARD_GBA_MACRO_H

#define CPU_FILL(dest, value, size, bit)                                          \
do {                                                                              \
    vu##bit tmp = (vu##bit)(value);                                               \
    CpuSet((void *)&tmp,                                                          \
           dest,                                                                  \
           CPU_SET_##bit##BIT | CPU_SET_SRC_FIXED | ((size)/(bit/8) & 0x1FFFFF)); \
} while (0)

#define CpuFill16(dest, value, size) CPU_FILL(dest, value, size, 16)
#define CpuFill32(dest, value, size) CPU_FILL(dest, value, size, 32)

#endif // GUARD_GBA_MACRO_H

#ifndef GUARD_DMA3_H
#define GUARD_DMA3_H

#include <gba/gba.h>

void ClearDma3Requests(void);
void ProcessDma3Requests(void);
s16 RequestDma3Copy(const void *src, void *dest, u16 size, u8 mode);
s16 RequestDma3Fill(s32 value, void *dest, u16 size, u8 mode);
s16 CheckForSpaceForDma3Request(s16 index);

#endif // GUARD_DMA3_H

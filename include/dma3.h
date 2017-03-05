#ifndef GUARD_DMA3_H
#define GUARD_DMA3_H

extern u8 gDma3ManagerLocked;
extern u8 gDma3RequestCursor;

struct DmaRequestsStruct
{
 /* 0x00 */ u8 *src;
 /* 0x04 */ u8 *dest;
 /* 0x08 */ u16 size;
 /* 0x0A */ u16 mode;
 /* 0x0C */ u32 value;
};

extern struct DmaRequestsStruct gDma3Requests[128];

void ClearDma3Requests(void);
void ProcessDma3Requests(void);
int RequestDma3Copy(void *src, void *dest, u16 size, u8 mode);
int RequestDma3Fill(s32 value, void *dest, u16 size, u8 mode);

#endif

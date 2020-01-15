#include "global.h"
#include "main.h"

#include "librfu.h"

// Nonmatching, only register differences
/*u16 rfu_initializeAPI(u32 *unk0, u16 unk1, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
    u16 i;
    u16 *v13;
    u16 *v12;
    u16 num;

    if (((u32)unk0 & 0xF000000) == 0x2000000 && copyInterruptToRam)
    {
        return 2;
    }
    
    if ((u32)unk0 & 3)
        return 2;
    
    // Nintendo pls, just use a ternary for once
    if (copyInterruptToRam)
    {
        // An assert/debug print may have existed before, ie
        // printf("%s %u < %u", "somefile.c:12345", unk1, num)
        // to push this into r3?
        num = 0xe64;
        if (unk1 < num)
            return 1;
    }

    if (copyInterruptToRam == FALSE)
    {
        num = 0x504; // same as above, this should be r3 not r0
        if (unk1 < num)
            return 1;
    }
    gRfuLinkStatus = unk0;
    gRfuStatic = unk0 + (0xB4 / sizeof(u32));
    gRfuFixed = (struct RfuFixed*)(unk0 + (0xDC / sizeof(u32)));
    gRfuSlotStatusNI[0] = (struct RfuSlotStatusNI*)(unk0 + (0x1BC / sizeof(u32)));
    gRfuSlotStatusUNI[0] = (struct RfuSlotStatusUNI*)(unk0 + (0x37C / sizeof(u32)));

    for (i = 1; i < 4; i++, num)
    {
        gRfuSlotStatusNI[i] = (struct RfuSlotStatusNI*)&gRfuSlotStatusNI[i-1]->unk_70;
        gRfuSlotStatusUNI[i] = (struct RfuSlotStatusUNI*)&gRfuSlotStatusUNI[i-1]->unk_1c;
    }
    
    gRfuFixed->unk_dc = (u32)&gRfuSlotStatusUNI[3]->unk_1c;
    STWI_init_all(&gRfuSlotStatusUNI[3]->unk_1c, interrupt, copyInterruptToRam);
    rfu_STC_clearAPIVariables();

    for (i = 0; i < 4; i++)
    {
        gRfuSlotStatusNI[i]->unk_68 = 0;
        gRfuSlotStatusNI[i]->unk_6c = 0;
        gRfuSlotStatusUNI[i]->unk_14 = 0;
        gRfuSlotStatusUNI[i]->unk_18 = 0;
    }

    // Not matching, register differences
    v12 = (u16*)((u32)&sub_82E53F4 & ~1);
    v13 = (u16*)gRfuFixed->unk_8;
        
    for (i = 47; i != 0xFFFF; i--)
    {
        *v13 = *v12;
        ++v12;
        ++v13;
    }
        
    gRfuFixed->unk_4 = (u32)(&gRfuFixed->unk_8[1]);
        
    return 0;
}*/

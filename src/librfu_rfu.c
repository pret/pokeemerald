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
    gUnknown_03007890 = unk0;
    gUnknown_03007894 = unk0 + (0xB4 / sizeof(u32));
    gUnknown_03007898 = (struct RfuUnk3*)(unk0 + (0xDC / sizeof(u32)));
    gUnknown_03007880[0] = (struct RfuUnk2*)(unk0 + (0x1BC / sizeof(u32)));
    gUnknown_03007870[0] = (struct RfuUnk1*)(unk0 + (0x37C / sizeof(u32)));

    for (i = 1; i < 4; i++, num)
    {
        gUnknown_03007880[i] = (struct RfuUnk2*)&gUnknown_03007880[i-1]->unk_70;
        gUnknown_03007870[i] = (struct RfuUnk1*)&gUnknown_03007870[i-1]->unk_1c;
    }
    
    gUnknown_03007898->unk_dc = (u32)&gUnknown_03007870[3]->unk_1c;
    STWI_init_all(&gUnknown_03007870[3]->unk_1c, interrupt, copyInterruptToRam);
    rfu_STC_clearAPIVariables();

    for (i = 0; i < 4; i++)
    {
        gUnknown_03007880[i]->unk_68 = 0;
        gUnknown_03007880[i]->unk_6c = 0;
        gUnknown_03007870[i]->unk_14 = 0;
        gUnknown_03007870[i]->unk_18 = 0;
    }

    // Not matching, register differences
    v12 = (u16*)((u32)&sub_82E53F4 & ~1);
    v13 = (u16*)gUnknown_03007898->unk_8;
        
    for (i = 47; i != 0xFFFF; i--)
    {
        *v13 = *v12;
        ++v12;
        ++v13;
    }
        
    gUnknown_03007898->unk_4 = (u32)(&gUnknown_03007898->unk_8[1]);
        
    return 0;
}*/

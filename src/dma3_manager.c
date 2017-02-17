#include "global.h"

extern u8 gDma3ManagerLocked;
extern u8 gDma3RequestCursor;

// size is 0x10
struct DmaRequestsStruct
{
 /* 0x00 */ u8 *src;
 /* 0x04 */ u8 *dest;
 /* 0x08 */ u16 size;
 /* 0x0A */ u16 mode;
 /* 0x0C */ u32 value;
};

extern struct DmaRequestsStruct gDma3Requests[128];

void ClearDma3Requests(void)
{
    int i;

    gDma3ManagerLocked = TRUE;
    gDma3RequestCursor = FALSE;

    for(i = 0; i < (u8)ARRAY_COUNT(gDma3Requests); i++)
    {
        gDma3Requests[i].size = 0;
        gDma3Requests[i].src = 0;
        gDma3Requests[i].dest = 0;
    }
    
    gDma3ManagerLocked = FALSE;
}

#ifdef NONMATCHING
void ProcessDma3Requests(void)
{
    // NOTE: the fillerA member of the DMA struct is actually u32 value;
    // NOTE: gUnknown_0300001C is just a pointer inside the gDma3Requests structure, not a true symbol; feel free to remove
    u16 total_size;
    
    if (gDma3ManagerLocked)
        return;

    total_size = 0;

    // as long as there are DMA requests to process (unless size or vblank is an issue), do not exit
    while (gDma3Requests[gDma3RequestCursor].size)
    {
        total_size += gDma3Requests[gDma3RequestCursor].size;
        
        if (total_size > 0xA000)
            return; // don't do too much at once

        if (REG_VCOUNT > 224)
            return;// we're about to leave vblank, stop

        switch (gDma3Requests[gDma3RequestCursor].mode)
        {
        case 1: // regular 32-bit copy
            // _08000C8C
            if(gDma3Requests[gDma3RequestCursor].size <= 0x1000)
            {
                DmaCopy32(3, gDma3Requests[gDma3RequestCursor].src, gDma3Requests[gDma3RequestCursor].dest, gDma3Requests[gDma3RequestCursor].size);
                break;
            }
            while (gDma3Requests[gDma3RequestCursor].size > 0x1000)
            {
                DmaCopy32(3, gDma3Requests[gDma3RequestCursor].src, gDma3Requests[gDma3RequestCursor].dest, 0x1000);
                gDma3Requests[gDma3RequestCursor].src += 0x1000;
                gDma3Requests[gDma3RequestCursor].dest += 0x1000;
                gDma3Requests[gDma3RequestCursor].size -= 0x1000;
            }
            DmaCopy32(3, gDma3Requests[gDma3RequestCursor].src, gDma3Requests[gDma3RequestCursor].dest, gDma3Requests[gDma3RequestCursor].size);
            break;
        case 2: // repeat a single 32-bit value across RAM
            // _08000CD0
            while (gDma3Requests[gDma3RequestCursor].size > 0x1000)
            {
                DmaFill32(3, gDma3Requests[gDma3RequestCursor].value, gDma3Requests[gDma3RequestCursor].dest, 0x1000);
                gDma3Requests[gDma3RequestCursor].dest += 0x1000;
                gDma3Requests[gDma3RequestCursor].size -= 0x1000;
            }
            DmaFill32(3, gDma3Requests[gDma3RequestCursor].value, gDma3Requests[gDma3RequestCursor].dest, gDma3Requests[gDma3RequestCursor].size);
            break;
        case 3:    // regular 16-bit copy
             // _08000D3C
            while (gDma3Requests[gDma3RequestCursor].size > 0x1000)
            {
                DmaCopy16(3, gDma3Requests[gDma3RequestCursor].src, gDma3Requests[gDma3RequestCursor].dest, 0x1000);
                gDma3Requests[gDma3RequestCursor].src += 0x1000;
                gDma3Requests[gDma3RequestCursor].dest += 0x1000;
                gDma3Requests[gDma3RequestCursor].size -= 0x1000;
            }
            DmaCopy16(3, gDma3Requests[gDma3RequestCursor].src, gDma3Requests[gDma3RequestCursor].dest, gDma3Requests[gDma3RequestCursor].size);
            break;
        case 4: // repeat a single 16-bit value across RAM
            // _08000D88
            while (gDma3Requests[gDma3RequestCursor].size > 0x1000)
            {
                DmaFill16(3, gDma3Requests[gDma3RequestCursor].value, gDma3Requests[gDma3RequestCursor].dest, 0x1000);
                gDma3Requests[gDma3RequestCursor].dest += 0x1000;
                gDma3Requests[gDma3RequestCursor].size -= 0x1000;
            }
            DmaFill16(3, gDma3Requests[gDma3RequestCursor].value, gDma3Requests[gDma3RequestCursor].dest, gDma3Requests[gDma3RequestCursor].size);
            break;
        }        
        gDma3Requests[gDma3RequestCursor].src = 0;
        gDma3Requests[gDma3RequestCursor].dest = 0;
        gDma3Requests[gDma3RequestCursor].size = 0;
        gDma3Requests[gDma3RequestCursor].mode = 0;
        gDma3Requests[gDma3RequestCursor].value = 0;
        gDma3RequestCursor++;
        
        if (gDma3RequestCursor >= 128) // loop back to the first DMA request
            gDma3RequestCursor = 0;
    }
}
#else
__attribute__((naked))
void ProcessDma3Requests(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0xC\n\
    ldr r0, =gDma3ManagerLocked\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _08000C06\n\
    b _08000E46\n\
_08000C06:\n\
    movs r0, 0\n\
    str r0, [sp, 0x8]\n\
    ldr r1, =gDma3Requests\n\
    ldr r2, =gDma3RequestCursor\n\
    ldrb r0, [r2]\n\
    lsls r0, 4\n\
    adds r0, r1\n\
    ldrh r0, [r0, 0x8]\n\
    mov r12, r2\n\
    cmp r0, 0\n\
    bne _08000C1E\n\
    b _08000E46\n\
_08000C1E:\n\
    mov r8, r1\n\
    adds r1, 0x4\n\
    mov r10, r1\n\
    movs r6, 0x80\n\
    lsls r6, 5\n\
    ldr r7, =0x040000D4 @REG_DMA3\n\
    movs r2, 0\n\
    mov r9, r2\n\
_08000C2E:\n\
    mov r3, r12 @ gDma3RequestCursor\n\
    ldrb r0, [r3]\n\
    lsls r5, r0, 4\n\
    mov r0, r8  @ gDma3Requests\n\
    adds r1, r5, r0 @ gDma3Requests[gDma3RequestCursor]\n\
    ldrh r0, [r1, 0x8] @ gDma3Requests[gDma3RequestCursor].size\n\
    ldr r2, [sp, 0x8]\n\
    adds r0, r2, r0\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0xA0\n\
    lsls r0, 8\n\
    ldr r3, [sp, 0x8]\n\
    cmp r3, r0\n\
    bls _08000C50\n\
    b _08000E46\n\
_08000C50:\n\
    ldr r0, =0x04000006 @REG_VCOUNT\n\
    ldrb r0, [r0]\n\
    cmp r0, 0xE0\n\
    bls _08000C5A\n\
    b _08000E46\n\
_08000C5A:\n\
    ldrh r0, [r1, 0xA]\n\
    cmp r0, 0x2\n\
    beq _08000CD0\n\
    cmp r0, 0x2\n\
    bgt _08000C80\n\
    cmp r0, 0x1\n\
    beq _08000C8C\n\
    b _08000DF0\n\
    .pool\n\
_08000C80:\n\
    cmp r0, 0x3\n\
    beq _08000D3C\n\
    cmp r0, 0x4\n\
    bne _08000C8A\n\
    b _08000D88\n\
_08000C8A:\n\
    b _08000DF0\n\
_08000C8C:\n\
    ldr r3, [r1]\n\
    mov r2, r10\n\
    adds r0, r5, r2\n\
    ldr r2, [r0]\n\
    ldrh r1, [r1, 0x8]\n\
    cmp r1, r6\n\
    bhi _08000CA6\n\
    str r3, [r7]\n\
    str r2, [r7, 0x4]\n\
    lsrs r0, r1, 2\n\
    movs r1, 0x84\n\
    lsls r1, 24\n\
    b _08000DAA\n\
_08000CA6:\n\
    ldr r4, =0x040000D4 @REG_DMA3\n\
    str r3, [r4]\n\
    str r2, [r4, 0x4]\n\
    ldr r0, =0x84000400\n\
    str r0, [r4, 0x8]\n\
    ldr r0, [r4, 0x8]\n\
    adds r3, r6\n\
    adds r2, r6\n\
    subs r1, r6\n\
    cmp r1, r6\n\
    bhi _08000CA6\n\
    str r3, [r4]\n\
    str r2, [r4, 0x4]\n\
    lsrs r0, r1, 2\n\
    movs r1, 0x84\n\
    lsls r1, 24\n\
    b _08000D76\n\
    .pool\n\
_08000CD0:\n\
    mov r3, r10\n\
    adds r0, r5, r3\n\
    ldr r4, [r0]\n\
    ldrh r1, [r1, 0x8]\n\
    cmp r1, r6\n\
    bhi _08000CF4\n\
    mov r0, r8\n\
    adds r0, 0xC\n\
    adds r0, r5, r0\n\
    ldr r0, [r0]\n\
    str r0, [sp]\n\
    mov r5, sp\n\
    str r5, [r7]\n\
    str r4, [r7, 0x4]\n\
    lsrs r0, r1, 2\n\
    movs r1, 0x85\n\
    lsls r1, 24\n\
    b _08000DAA\n\
_08000CF4:\n\
    mov r2, r12\n\
    ldrb r0, [r2]\n\
    lsls r0, 4\n\
    mov r5, r8\n\
    adds r5, 0xC\n\
    adds r0, r5\n\
    ldr r0, [r0]\n\
    str r0, [sp]\n\
    ldr r3, =0x040000D4 @REG_DMA3\n\
    mov r0, sp\n\
    str r0, [r3]\n\
    str r4, [r3, 0x4]\n\
    ldr r0, =0x85000400\n\
    str r0, [r3, 0x8]\n\
    ldr r0, [r3, 0x8]\n\
    adds r4, r6\n\
    subs r1, r6\n\
    cmp r1, r6\n\
    bhi _08000CF4\n\
    ldrb r0, [r2]\n\
    lsls r0, 4\n\
    adds r0, r5\n\
    ldr r0, [r0]\n\
    str r0, [sp]\n\
    mov r2, sp\n\
    str r2, [r3]\n\
    str r4, [r3, 0x4]\n\
    lsrs r0, r1, 2\n\
    movs r1, 0x85\n\
    lsls r1, 24\n\
    b _08000DEA\n\
    .pool\n\
_08000D3C:\n\
    ldr r3, [r1]\n\
    mov r2, r10\n\
    adds r0, r5, r2\n\
    ldr r2, [r0]\n\
    ldrh r1, [r1, 0x8]\n\
    cmp r1, r6\n\
    bhi _08000D56\n\
    str r3, [r7]\n\
    str r2, [r7, 0x4]\n\
    lsrs r0, r1, 1\n\
    movs r1, 0x80\n\
    lsls r1, 24\n\
    b _08000DAA\n\
_08000D56:\n\
    ldr r4, =0x040000D4 @REG_DMA3\n\
    str r3, [r4]\n\
    str r2, [r4, 0x4]\n\
    ldr r0, =0x80000800\n\
    str r0, [r4, 0x8]\n\
    ldr r0, [r4, 0x8]\n\
    adds r3, r6\n\
    adds r2, r6\n\
    subs r1, r6\n\
    cmp r1, r6\n\
    bhi _08000D56\n\
    str r3, [r4]\n\
    str r2, [r4, 0x4]\n\
    lsrs r0, r1, 1\n\
    movs r1, 0x80\n\
    lsls r1, 24\n\
_08000D76:\n\
    orrs r0, r1\n\
    str r0, [r4, 0x8]\n\
    ldr r0, [r4, 0x8]\n\
    b _08000DF0\n\
    .pool\n\
_08000D88:\n\
    mov r3, r10\n\
    adds r0, r5, r3\n\
    ldr r2, [r0]\n\
    ldrh r4, [r1, 0x8]\n\
    add r1, sp, 0x4\n\
    cmp r4, r6\n\
    bhi _08000DB2\n\
    mov r0, r8\n\
    adds r0, 0xC\n\
    adds r0, r5, r0\n\
    ldr r0, [r0]\n\
    strh r0, [r1]\n\
    str r1, [r7]\n\
    str r2, [r7, 0x4]\n\
    lsrs r0, r4, 1\n\
    movs r1, 0x81\n\
    lsls r1, 24\n\
_08000DAA:\n\
    orrs r0, r1\n\
    str r0, [r7, 0x8]\n\
    ldr r0, [r7, 0x8]\n\
    b _08000DF0\n\
_08000DB2:\n\
    mov r5, r12\n\
    ldrb r0, [r5]\n\
    lsls r0, 4\n\
    ldr r3, =gUnknown_0300001C\n\
    adds r0, r3\n\
    ldr r0, [r0]\n\
    strh r0, [r1]\n\
    ldr r3, =0x040000D4 @REG_DMA3\n\
    str r1, [r3]\n\
    str r2, [r3, 0x4]\n\
    ldr r0, =0x81000800\n\
    str r0, [r3, 0x8]\n\
    ldr r0, [r3, 0x8]\n\
    adds r2, r6\n\
    subs r4, r6\n\
    cmp r4, r6\n\
    bhi _08000DB2\n\
    ldrb r0, [r5]\n\
    lsls r0, 4\n\
    ldr r5, =gUnknown_0300001C\n\
    adds r0, r5\n\
    ldr r0, [r0]\n\
    strh r0, [r1]\n\
    str r1, [r3]\n\
    str r2, [r3, 0x4]\n\
    lsrs r0, r4, 1\n\
    movs r1, 0x81\n\
    lsls r1, 24\n\
_08000DEA:\n\
    orrs r0, r1\n\
    str r0, [r3, 0x8]\n\
    ldr r0, [r3, 0x8]\n\
_08000DF0:\n\
    ldr r1, =gDma3Requests\n\
    mov r3, r12\n\
    ldrb r0, [r3]\n\
    lsls r0, 4\n\
    adds r0, r1\n\
    mov r2, r9\n\
    str r2, [r0]\n\
    ldrb r0, [r3]\n\
    lsls r0, 4\n\
    add r0, r10\n\
    str r2, [r0]\n\
    ldrb r0, [r3]\n\
    lsls r0, 4\n\
    adds r0, r1\n\
    movs r4, 0\n\
    strh r2, [r0, 0x8]\n\
    ldrb r0, [r3]\n\
    lsls r0, 4\n\
    adds r0, r1\n\
    mov r5, r9\n\
    strh r5, [r0, 0xA]\n\
    ldrb r0, [r3]\n\
    lsls r0, 4\n\
    adds r1, 0xC\n\
    adds r0, r1\n\
    mov r1, r9\n\
    str r1, [r0]\n\
    ldrb r0, [r3]\n\
    adds r0, 0x1\n\
    strb r0, [r3]\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bge _08000E34\n\
    strb r4, [r3]\n\
_08000E34:\n\
    mov r2, r12\n\
    ldrb r0, [r2]\n\
    lsls r0, 4\n\
    ldr r3, =gDma3Requests\n\
    adds r0, r3\n\
    ldrh r0, [r0, 0x8]\n\
    cmp r0, 0\n\
    beq _08000E46\n\
    b _08000C2E\n\
_08000E46:\n\
    add sp, 0xC\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif

int RequestDma3Copy(void *src, void *dest, u16 size, u8 mode)
{
    int cursor;
    int var = 0;
    
    gDma3ManagerLocked = 1;
    
    cursor = gDma3RequestCursor;
    while(1)
    {
        if(!gDma3Requests[cursor].size) // an empty copy was found and the current cursor will be returned.
        {
            gDma3Requests[cursor].src = src;
            gDma3Requests[cursor].dest = dest;
            gDma3Requests[cursor].size = size;
        
            if(mode == 1)
                gDma3Requests[cursor].mode = mode;
            else
                gDma3Requests[cursor].mode = 3;
        
            gDma3ManagerLocked = FALSE;
            return (s16)cursor;
        }
        if(++cursor >= 0x80) // loop back to start.
        {
            cursor = 0;
        }
        if(++var >= 0x80) // max checks were made. all resulted in failure.
        {
            break;
        }
    }
    gDma3ManagerLocked = FALSE;
    return -1;
}

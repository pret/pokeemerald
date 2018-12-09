#include "global.h"
#include "palette.h"
#include "roulette.h"
#include "roulette_util.h"
#include "util.h"

void sub_8151678(struct UnkStruct0 *r0)
{
    r0->var00 = 0;
    r0->var02 = 0;
    memset(&r0->var04, 0, sizeof(r0->var04));
}

u8 sub_815168C(struct UnkStruct0 *r0, u8 r1, struct UnkStruct1 *r2)
{
    if (!(r1 < 16) || (r0->var04[r1].var00_7))
        return 0xFF;

    r0->var04[r1].var04.var00 = r2->var00;
    r0->var04[r1].var04.var02 = r2->var02;
    r0->var04[r1].var04.var04 = r2->var04;
    r0->var04[r1].var04.var05 = r2->var05;
    r0->var04[r1].var04.var06 = r2->var06;
    r0->var04[r1].var04.var07_0 = r2->var07_0;
    r0->var04[r1].var04.var07_5 = r2->var07_5;
    r0->var04[r1].var04.var07_7 = r2->var07_7;
    r0->var04[r1].var00_0 = 0;
    r0->var04[r1].var00_7 = 1;
    r0->var04[r1].var02 = 0;
    r0->var04[r1].var01 = 0;
    if (r0->var04[r1].var04.var07_7 < 0)
        r0->var04[r1].var03 = 0xFF;
    else
        r0->var04[r1].var03 = 1;

    return r1;
}

u8 sub_8151710(struct UnkStruct0 *r0, u8 r1)
{
    if (r1 >= 16)
        return 0xFF;
    if (!r0->var04[r1].var00_7)
        return 0xFF;

    memset(&r0->var04[r1], 0, sizeof(r0->var04[r1]));
    return r1;
}

u8 sub_8151744(struct UnkStruct3 *r0)
{
    u8 i;
    u8 returnval;

    for (i = 0; i < r0->var04.var04; i++)
    {
        struct PlttData *faded =   (struct PlttData *)&gPlttBufferFaded[r0->var04.var02 + i];
        struct PlttData *unfaded = (struct PlttData *)&gPlttBufferUnfaded[r0->var04.var02 + i];

        switch (r0->var00_0)
        {
        case 1:
            if (faded->r + r0->var03 >= 0 && faded->r + r0->var03 < 32)
                faded->r += r0->var03;
            if (faded->g + r0->var03 >= 0 && faded->g + r0->var03 < 32)
                faded->g += r0->var03;
            if (faded->b + r0->var03 >= 0 && faded->b + r0->var03 < 32)
                faded->b += r0->var03;
            break;
        case 2:
            if (r0->var03 < 0)
            {
                if (faded->r + r0->var03 >= unfaded->r)
                    faded->r += r0->var03;
                if (faded->g + r0->var03 >= unfaded->g)
                    faded->g += r0->var03;
                if (faded->b + r0->var03 >= unfaded->b)
                    faded->b += r0->var03;
            }
            else
            {
                if (faded->r + r0->var03 <= unfaded->r)
                    faded->r += r0->var03;
                if (faded->g + r0->var03 <= unfaded->g)
                    faded->g += r0->var03;
                if (faded->b + r0->var03 <= unfaded->b)
                    faded->b += r0->var03;
            }
            break;
        }
    }
    if ((u32)r0->var02++ != r0->var04.var07_0)
    {
        returnval = 0;
    }
    else
    {
        r0->var02 = 0;
        r0->var03 *= -1;
        if (r0->var00_0 == 1)
            r0->var00_0++;
        else
            r0->var00_0--;
        returnval = 1;
    }
    return returnval;
}

u8 sub_815194C(struct UnkStruct3 *r0)
{
    u8 rg2 = 0;

    switch (r0->var00_0)
    {
    case 1:
        for (rg2 = 0; rg2 < r0->var04.var04; rg2++)
            gPlttBufferFaded[r0->var04.var02 + rg2] = r0->var04.var00;
        r0->var00_0++;
        break;
    case 2:
        for (rg2 = 0; rg2 < r0->var04.var04; rg2++)
            gPlttBufferFaded[r0->var04.var02 + rg2] = gPlttBufferUnfaded[r0->var04.var02 + rg2];
        r0->var00_0--;
        break;
    }
    return 1;
}

void task_tutorial_controls_fadein(struct UnkStruct0 *r0)
{
    u8 i = 0;

    if (r0->var00)
    {
        for (i = 0; i < 16; i++)
        {
            if ((r0->var02 >> i) & 1)
            {
                if (--r0->var04[i].var01 == 0xFF) // if underflow ?
                {
                    if (r0->var04[i].var04.var00 & 0x8000) // PlttData->unused_15 ?
                        sub_8151744(&r0->var04[i]);
                    else
                        sub_815194C(&r0->var04[i]);

                    r0->var04[i].var01 = r0->var04[i].var04.var05;
                }
            }
        }
    }
}

void sub_8151A48(struct UnkStruct0 *r0, u16 r1)
{
    u8 i = 0;

    r0->var00++;
    for (i = 0; i < 16; i++)
    {
        if ((r1 >> i) & 1)
        {
            if (r0->var04[i].var00_7)
            {
                r0->var02 |= 1 << i;
                r0->var04[i].var00_0 = 1;
            }
        }
    }
}

void sub_8151A9C(struct UnkStruct0 *r0, u16 r1)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        if ((r0->var02 >> i) & 1)
        {
            if (r0->var04[i].var00_7)
            {
                if ((r1 >> i) & 1)
                {
                    u32 offset = r0->var04[i].var04.var02;
                    u16 *faded = &gPlttBufferFaded[offset];
                    u16 *unfaded = &gPlttBufferUnfaded[offset];
                    memcpy(faded, unfaded, r0->var04[i].var04.var04 * 2);
                    r0->var04[i].var00_0 = 0;
                    r0->var04[i].var02 = 0;
                    r0->var04[i].var01 = 0;
                    if (r0->var04[i].var04.var07_7 < 0)
                        r0->var04[i].var03 = 0xFF;
                    else
                        r0->var04[i].var03 = 0x1;
                }
            }
        }
    }
    if (r1 == 0xFFFF)
    {
        r0->var00 = 0;
        r0->var02 = 0;
    }
    else
    {
        r0->var02 = r0->var02 & ~r1;
    }
}

void sub_8151B3C(struct InnerStruct203CF18 *arg0)
{
    u8 i = 0;
    arg0->unk0 = 0;
    memset(&arg0->unk4, 0, sizeof(arg0->unk4));
    for (; i < 16; i++)
    {
        arg0->unk4[i].unk0 = i;
    }
}

int sub_8151B68(struct InnerStruct203CF18 *arg0, const struct InnerStruct203CF18_3 *arg1)
{
    u8 i = 0;
    struct InnerStruct203CF18_2 *r4 = NULL;

    if (!arg0->unk4[0].unk1_7)
    {
        r4 = &arg0->unk4[0];
    }
    else
    {
        while (++i < 16)
        {
            if (!arg0->unk4[i].unk1_7)
            {
                r4 = &arg0->unk4[i];
                break;
            }
        }
    }

    if (r4 == 0)
        return 0xFF;
    
    r4->unk1_0 = 0;
    r4->unk1_4 = 0;
    r4->unk1_6 = 1;
    r4->unk1_7 = 1;
    r4->unk2 = 0;
    r4->unk3 = 0;
    memcpy(&r4->unk4, arg1, sizeof(*arg1));
    return i;
}

void sub_8151BD4(struct InnerStruct203CF18_2 *arg0)
{
    u16 i;

    if (!arg0->unk1_6 && arg0->unk4.unk7_6)
    {
        for (i = arg0->unk4.unk2; i < arg0->unk4.unk2 + arg0->unk4.unk4; i++)
            gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
    }

    memset(&arg0->unk4, 0, sizeof(arg0->unk4));
    arg0->unk1_0 = 0;
    arg0->unk1_4 = 0;
    arg0->unk1_5 = 0;
    arg0->unk1_6 = 1;
    arg0->unk1_7 = 0;
    arg0->unk3 = 0;
    arg0->unk2 = 0;
}

void sub_8151C50(struct InnerStruct203CF18 *arg0, u16 arg1, u8 arg2)
{
    u16 i = 0;

    if (!arg2)
    {
        sub_8151BD4(&arg0->unk4[arg1 & 0xF]);
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            if ((arg1 & 1) && arg0->unk4[i].unk1_7)
                sub_8151BD4(&arg0->unk4[i]);

            arg1 >>= 1;
        }
    }
}

// there seems to be a temp var involved inside the first if block
void sub_8151CA8(struct InnerStruct203CF18 *arg0, u16 arg1, u8 arg2)
{
    u8 i = 0;

    if (!arg2)
    {
        i = arg1 & 0xF;
        arg0->unk4[i].unk1_6 = 0;
        arg0->unk0 |= 1 << i;
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            if (!(arg1 & 1) || !arg0->unk4[i].unk1_7 || !arg0->unk4[i].unk1_6)
            {
                arg1 <<= 1;
            }
            else
            {
                arg0->unk4[i].unk1_6 = 0;
                arg0->unk0 |= 1 << i;
            }
        }
    }    
}

void sub_8151D28(struct InnerStruct203CF18 *arg0, u16 arg1, u8 arg2)
{
    u16 i;
    struct InnerStruct203CF18_2 *var0;
    u8 j = 0;

    if (!arg2)
    {
        var0 = &arg0->unk4[arg1 & 0xF];
        if (!var0->unk1_6 && var0->unk1_7)
        {
            if (var0->unk4.unk7_6)
            {
                for (i = var0->unk4.unk2; i < var0->unk4.unk2 + var0->unk4.unk4; i++)
                    gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
            }

            var0->unk1_6 = 1;
            arg0->unk0 &= ~(1 << j);
        }
    }
    else
    {
        for (j = 0; j < 16; j++)
        {
            var0 = &arg0->unk4[j];
            if (!(arg1 & 1) || var0->unk1_6 || !var0->unk1_7)
            {
                arg1 <<= 1;
            }
            else
            {
                if (var0->unk4.unk7_6)
                {
                    for (i = var0->unk4.unk2; i < var0->unk4.unk2 + var0->unk4.unk4; i++)
                        gPlttBufferFaded[i] = gPlttBufferUnfaded[i];
                }

                var0->unk1_6 = 1;
                arg0->unk0 &= ~(1 << j);
            }
        }
    }
}

#ifdef NONMATCHING
void sub_8151E50(struct InnerStruct203CF18 *arg0)
{
    struct InnerStruct203CF18_2 *var0;
    u8 i = 0;

    if (arg0->unk0)
    {
        for (i = 0; i < 16; i++)
        {
            var0 = &arg0->unk4[i];
            if ((!var0->unk1_6 && var0->unk1_7) && (!gPaletteFade.active || !var0->unk4.unk7_7))
            {
                if (--var0->unk2 == 0xFF)
                {
                    var0->unk2 = var0->unk4.unk5;
                    BlendPalette(var0->unk4.unk2, var0->unk4.unk4, var0->unk1_0, var0->unk4.unk0);
                    switch (var0->unk4.unk7_4)
                    {
                    case 0:
                        if (var0->unk1_0++ == var0->unk4.unk7_0)
                        {
                            var0->unk3++;
                            var0->unk1_0 = 0;
                        }
                        break;
                    case 1:
                        if (var0->unk1_4)
                        {
                            if (--var0->unk1_0 == 0)
                            {
                                var0->unk3++;
                                var0->unk1_4 ^= 1;
                            }
                        }
                        else
                        {
                            if (var0->unk1_0++ == var0->unk4.unk7_0 - 1)
                            {
                                var0->unk3++;
                                var0->unk1_4 ^= 1;
                            }
                        }
                        break;
                    case 2:
                        if (var0->unk1_4)
                            var0->unk1_0 = 0;
                        else
                            var0->unk1_0 = var0->unk4.unk7_0;
                        
                        var0->unk1_4 ^= 1;
                        var0->unk3++;
                        break;
                    }

                    if (var0->unk4.unk6 != 0xFF && var0->unk3 == 0xFF)
                        sub_8151D28(arg0, var0->unk0, 0);
                }
            }
        }
    }
}
#else
NAKED
void sub_8151E50(struct InnerStruct203CF18 *arg0)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    str r0, [sp]\n\
    movs r0, 0\n\
    mov r10, r0\n\
    ldr r1, [sp]\n\
    ldrh r0, [r1]\n\
    cmp r0, 0\n\
    bne _08151E6C\n\
    b _08151FF6\n\
_08151E6C:\n\
    movs r2, 0xF\n\
    mov r9, r2\n\
    movs r3, 0x10\n\
    negs r3, r3\n\
    mov r8, r3\n\
    movs r7, 0x1\n\
_08151E78:\n\
    mov r5, r10\n\
    lsls r0, r5, 1\n\
    add r0, r10\n\
    lsls r0, 2\n\
    adds r0, 0x4\n\
    ldr r1, [sp]\n\
    adds r4, r1, r0\n\
    ldrb r2, [r4, 0x1]\n\
    movs r3, 0xC0\n\
    ands r3, r2\n\
    cmp r3, 0x80\n\
    beq _08151E92\n\
    b _08151FE6\n\
_08151E92:\n\
    ldr r0, =gPaletteFade\n\
    ldrb r1, [r0, 0x7]\n\
    adds r0, r3, 0\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08151EA8\n\
    ldrb r0, [r4, 0xB]\n\
    ands r3, r0\n\
    cmp r3, 0\n\
    beq _08151EA8\n\
    b _08151FE6\n\
_08151EA8:\n\
    ldrb r0, [r4, 0x2]\n\
    subs r0, 0x1\n\
    strb r0, [r4, 0x2]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0xFF\n\
    beq _08151EB8\n\
    b _08151FE6\n\
_08151EB8:\n\
    ldrb r0, [r4, 0x9]\n\
    strb r0, [r4, 0x2]\n\
    ldrh r0, [r4, 0x6]\n\
    ldrb r1, [r4, 0x8]\n\
    lsls r2, 28\n\
    lsrs r2, 28\n\
    ldrh r3, [r4, 0x4]\n\
    bl BlendPalette\n\
    ldrb r5, [r4, 0xB]\n\
    lsls r0, r5, 26\n\
    asrs r0, 30\n\
    cmp r0, 0x1\n\
    beq _08151F16\n\
    cmp r0, 0x1\n\
    bgt _08151EE4\n\
    cmp r0, 0\n\
    beq _08151EEA\n\
    b _08151FD0\n\
    .pool\n\
_08151EE4:\n\
    cmp r0, 0x2\n\
    beq _08151F92\n\
    b _08151FD0\n\
_08151EEA:\n\
    ldrb r2, [r4, 0x1]\n\
    lsls r1, r2, 28\n\
    lsrs r0, r1, 28\n\
    adds r0, 0x1\n\
    mov r3, r9\n\
    ands r0, r3\n\
    mov r6, r8\n\
    adds r3, r6, 0\n\
    ands r3, r2\n\
    orrs r3, r0\n\
    strb r3, [r4, 0x1]\n\
    lsrs r1, 28\n\
    lsls r0, r5, 28\n\
    asrs r0, 28\n\
    cmp r1, r0\n\
    bne _08151FD0\n\
    ldrb r0, [r4, 0x3]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x3]\n\
    ands r3, r6\n\
    strb r3, [r4, 0x1]\n\
    b _08151FD0\n\
_08151F16:\n\
    ldrb r3, [r4, 0x1]\n\
    movs r0, 0x10\n\
    ands r0, r3\n\
    cmp r0, 0\n\
    beq _08151F54\n\
    lsls r0, r3, 28\n\
    lsrs r0, 28\n\
    subs r0, 0x1\n\
    mov r5, r9\n\
    ands r0, r5\n\
    mov r2, r8\n\
    ands r2, r3\n\
    orrs r2, r0\n\
    strb r2, [r4, 0x1]\n\
    cmp r0, 0\n\
    bne _08151FD0\n\
    ldrb r0, [r4, 0x3]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x3]\n\
    lsls r0, r2, 27\n\
    lsrs r0, 31\n\
    eors r0, r7\n\
    ands r0, r7\n\
    lsls r0, 4\n\
    movs r3, 0x11\n\
    negs r3, r3\n\
    adds r1, r3, 0\n\
    ands r2, r1\n\
    orrs r2, r0\n\
    strb r2, [r4, 0x1]\n\
    b _08151FD0\n\
_08151F54:\n\
    lsls r0, r5, 28\n\
    asrs r0, 28\n\
    subs r0, 0x1\n\
    mov r5, r9\n\
    ands r0, r5\n\
    lsls r2, r3, 28\n\
    lsrs r1, r2, 28\n\
    adds r1, 0x1\n\
    ands r1, r5\n\
    mov r5, r8\n\
    ands r3, r5\n\
    orrs r3, r1\n\
    strb r3, [r4, 0x1]\n\
    lsrs r2, 28\n\
    cmp r2, r0\n\
    bne _08151FD0\n\
    ldrb r0, [r4, 0x3]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x3]\n\
    lsls r0, r3, 27\n\
    lsrs r0, 31\n\
    eors r0, r7\n\
    ands r0, r7\n\
    lsls r0, 4\n\
    movs r2, 0x11\n\
    negs r2, r2\n\
    adds r1, r2, 0\n\
    ands r3, r1\n\
    orrs r3, r0\n\
    strb r3, [r4, 0x1]\n\
    b _08151FD0\n\
_08151F92:\n\
    ldrb r2, [r4, 0x1]\n\
    movs r0, 0x10\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _08151FA2\n\
    mov r0, r8\n\
    ands r0, r2\n\
    b _08151FB0\n\
_08151FA2:\n\
    lsls r1, r5, 28\n\
    asrs r1, 28\n\
    mov r3, r9\n\
    ands r1, r3\n\
    mov r0, r8\n\
    ands r0, r2\n\
    orrs r0, r1\n\
_08151FB0:\n\
    strb r0, [r4, 0x1]\n\
    ldrb r2, [r4, 0x1]\n\
    lsls r0, r2, 27\n\
    lsrs r0, 31\n\
    eors r0, r7\n\
    ands r0, r7\n\
    lsls r0, 4\n\
    movs r5, 0x11\n\
    negs r5, r5\n\
    adds r1, r5, 0\n\
    ands r2, r1\n\
    orrs r2, r0\n\
    strb r2, [r4, 0x1]\n\
    ldrb r0, [r4, 0x3]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x3]\n\
_08151FD0:\n\
    ldrb r1, [r4, 0xA]\n\
    cmp r1, 0xFF\n\
    beq _08151FE6\n\
    ldrb r0, [r4, 0x3]\n\
    cmp r0, r1\n\
    bne _08151FE6\n\
    ldrb r1, [r4]\n\
    ldr r0, [sp]\n\
    movs r2, 0\n\
    bl sub_8151D28\n\
_08151FE6:\n\
    mov r0, r10\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r10, r0\n\
    cmp r0, 0xF\n\
    bhi _08151FF6\n\
    b _08151E78\n\
_08151FF6:\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0");
}
#endif // NONMATCHING

void sub_8152008(u16 *dest, u16 src, u8 left, u8 top, u8 width, u8 height)
{
    u16 *_dest;
    u8 i;
    u8 j;
    i = 0;
    dest = &dest[top * 32 + left];
    for (; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
        {
            *_dest++ = src;
        }
    }
}

void sub_8152058(u16 *dest, u16 *src, u8 left, u8 top, u8 width, u8 height)
{
    u16 *_dest;
    u16 *_src = src;
    u8 i;
    u8 j;
    i = 0;
    dest = &dest[top * 32 + left];
    for (; i < height; i++)
    {
        _dest = dest + i * 32;
        for (j = 0; j < width; j++)
        {
            *_dest++ = *_src++;
        }
    }
}

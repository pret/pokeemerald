#include "global.h"
#include "alloc.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "link.h"
#include "main.h"
#include "metatile_behavior.h"
#include "rom_8011DC0.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "strings.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"
#include "constants/vars.h"

struct Unk81D38FC
{
    u8 unk0[0x270];
    int checksum;
};

struct Unknown030012C8
{
    u8 unk0[8];
    u32 *unk8;
    int unkC;
    int unk10;
    int unk14;
};

struct Unk03006370
{
    u16 unk0;
    u32 unk4;
    u32 *unk8;
};

struct Unk81D5014
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 *unk10;
};

void sub_81D41A0(void);
static void sub_81D4170(void);
int sub_81D3D70(u8, u32, u32*, u32*);
void sub_81D41F4(void);
static u16 sub_81D3EE8(u8);
static void sub_81D413C(void);
static void sub_81D414C(void);
static void sub_81D3F1C(u32, u32*, u32*);
static void sub_81D3F68(void);
bool8 sub_81D4834(s16, s16);
static bool8 sub_81D4C14(struct EventObject*, u8);
static u8 sub_81D4C9C(struct EventObject*, u8);
static u8 sub_81D4C58(struct EventObject*, u8);
static u8 sub_81D4CE0(struct EventObject*, u8);
static u8 sub_81D4D24(u8);
static u8 sub_81D4890(u8);
void sub_81D5084(u8);

extern struct Unknown030012C8 gUnknown_030012C8;
extern u16 gUnknown_030012E0;
extern u16 gUnknown_030012E2;
extern u16 gUnknown_030012E4;
extern u16 gUnknown_030012E6;
extern u32 gUnknown_030012E8;
extern u16 gUnknown_030012EC;
extern u16 gUnknown_030012EE;
extern u16 gUnknown_030012F0;
extern u16 gUnknown_030012F2;
extern u16 gUnknown_030012F4;
extern s16 gUnknown_030012F8;
extern s16 gUnknown_030012FA;
extern u8 gUnknown_030012FC[4];
extern u8 gUnknown_0203CF50;
extern struct Unk03006370 gUnknown_03006370;

extern const u8 gUnknown_08625B6C[];
extern const u8 gUnknown_089A3470[];
extern const u8 gMultiBootProgram_BerryGlitchFix_Start[];
extern const s16 gFarawayIslandRockCoords[4][2];

extern const struct SpritePalette gFieldEffectObjectPaletteInfo1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static u8 sub_81D38D4(void)
{
    return (gSaveBlock1Ptr->trainerHill.unused + 1) % 256;
}

static bool32 sub_81D38FC(struct Unk81D38FC *arg0)
{
    int checksum = CalcByteArraySum(arg0->unk0, 0x270);
    if (checksum != arg0->checksum)
        return FALSE;

    return TRUE;
}

bool8 sub_81D3920(u8 *buffer)
{
    u32 i;
    u32 checksum;
    int var0 = buffer[0];
    if (var0 < 1 || var0 > 8)
        return FALSE;

    for (i = 0; i < var0; i++)
    {
        struct Unk81D38FC *var1 = (struct Unk81D38FC *)(&buffer[i * (sizeof(struct Unk81D38FC)) + 8]);
        if (!sub_81D38FC(var1))
            return FALSE;
    }

    checksum = CalcByteArraySum(buffer + 8, var0 * 0x274);
    if (checksum != ((int *)buffer)[1])
        return FALSE;

    return TRUE;
}

static bool32 sub_81D396C(u8 *buffer)
{
    u32 checksum;
    int var0 = buffer[0];
    if (var0 < 1 || var0 > 8)
        return FALSE;

    checksum = CalcByteArraySum(buffer + 8, 0xEE0);
    if (checksum != ((int *)buffer)[1])
        return FALSE;

    return TRUE;
}

static bool32 sub_81D3998(struct Unk81D38FC *arg0, u8 *buffer2)
{
    int i;
    const u8 *ereaderVals;

    memset(buffer2, 0, 0x1000);
    buffer2[0] = arg0->unk0[0];
    buffer2[1] = sub_81D38D4();
    buffer2[2] = (arg0->unk0[0] + 1) / 2;

    for (i = 0; i < arg0->unk0[0]; i++)
    {
        if (!(i & 1))
        {
            u8 *var0 = &buffer2[(i / 2) * 0x3B8];
            u8 *var1 = arg0[i].unk0;
            var0[8] = var1[8];
            memcpy(&var0[0x29C], &var1[0x154], 0x124);
            var0 += 0xC;
            var1 += 0xC;
            memcpy(var0, var1, 0x148);
        }
        else
        {
            u8 *var0 = &buffer2[(i / 2) * 0x3B8];
            u8 *var1 = arg0[i].unk0;
            var0[9] = var1[8];
            memcpy(&var0[0x154], &var1[0xC], 0x148);
        }
    }

    if (i & 1)
    {
        u8 *var0 = &buffer2[(i / 2) * 0x3B8];
        var0 += 0x154;

        ereaderVals = gUnknown_08625B6C;
        memcpy(var0, &ereaderVals[(i / 2) * 0x148], 0x148);
    }

    ((int *)buffer2)[1] = CalcByteArraySum(buffer2 + 8, 0xEE0);
    if (sub_8153634(SECTOR_ID_TRAINER_HILL, buffer2) != 1)
        return FALSE;

    return TRUE;
}

bool32 sub_81D3AB0(struct Unk81D38FC *arg0)
{
    u8 *var0 = AllocZeroed(0x1000);
    bool32 result = sub_81D3998(arg0, var0);
    Free(var0);
    return result;
}

static bool32 sub_81D3AD8(u8 *arg0, u8 *arg1)
{
    if (TryCopySpecialSaveSection(SECTOR_ID_TRAINER_HILL, arg1) != 1)
        return FALSE;

    memcpy(arg0, arg1, 0xEE8);
    if (!sub_81D396C(arg0))
        return FALSE;

    return TRUE;
}

static bool32 sub_81D3B0C(u8 *arg0)
{
    u8 *var0 = AllocZeroed(0x1000);
    bool32 result = sub_81D3AD8(arg0, var0);
    Free(var0);
    return result;
}

bool32 sub_81D3B34(void)
{
    u8 *var0 = AllocZeroed(0x1000);
    bool32 result = sub_81D3B0C(var0);
    Free(var0);
    return result;
}

static int unref_sub_81D3B54(int arg0, u32 *arg1)
{
    int result;
    u16 var0;
    int var1;

    sub_81D41A0();
    while (1)
    {
        sub_81D4170();
        if (gUnknown_030012E2 & 2)
            gShouldAdvanceLinkState = 2;

        var1 = sub_81D3D70(1, arg0, arg1, NULL);
        gUnknown_030012E4 = var1;
        if ((gUnknown_030012E4 & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (gUnknown_030012E4 & 0x8)
        {
            result = 1;
            break;
        }

        var0 = gUnknown_030012E4 & 0x4;
        if (var0)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = var0;
        VBlankIntrWait();
    }

    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
    sub_81D41F4();
    return result;
}

static int unref_sub_81D3BE8(u32 *arg0)
{
    int result;
    u16 var0;
    int var1;

    sub_81D41A0();
    while (1)
    {
        sub_81D4170();
        if (gUnknown_030012E2 & 2)
            gShouldAdvanceLinkState = 2;

        var1 = sub_81D3D70(0, 0, NULL, arg0);
        gUnknown_030012E4 = var1;
        if ((gUnknown_030012E4 & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (gUnknown_030012E4 & 0x8)
        {
            result = 1;
            break;
        }

        var0 = gUnknown_030012E4 & 0x4;
        if (var0)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = var0;
        VBlankIntrWait();
    }

    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
    sub_81D41F4();
    return result;
}

static void sub_81D3C7C(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

static void sub_81D3CBC(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;

    if (!gUnknown_030012C8.unk0[1])
        CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
}

static void sub_81D3D34(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_INTR_ENABLE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    gUnknown_030012E6 = 0;
    gUnknown_030012E8 = 0;
}

int sub_81D3D70(u8 arg0, u32 arg1, u32 *arg2, u32 *arg3)
{
    switch (gUnknown_030012C8.unk0[1])
    {
    case 0:
        sub_81D3CBC();
        gUnknown_030012C8.unk0[2] = 1;
        gUnknown_030012C8.unk0[1] = 1;
        break;
    case 1:
        if (sub_81D3EE8(arg0))
            sub_81D413C();

        if (gShouldAdvanceLinkState == 2)
        {
            gUnknown_030012C8.unk0[4] = 2;
            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    case 2:
        sub_81D3D34();
        sub_81D3F1C(arg1, arg2, arg3);
        gUnknown_030012C8.unk0[1] = 3;
        // fall through
    case 3:
        if (gShouldAdvanceLinkState == 2)
        {
            gUnknown_030012C8.unk0[4] = 2;
            gUnknown_030012C8.unk0[1] = 6;
        }
        else
        {
            gUnknown_030012E6++;
            gUnknown_030012E8++;
            if (!gUnknown_030012C8.unk0[0] && gUnknown_030012E8 > 60)
            {
                gUnknown_030012C8.unk0[4] = 1;
                gUnknown_030012C8.unk0[1] = 6;
            }

            if (gUnknown_030012C8.unk0[2] != 2)
            {
                if (gUnknown_030012C8.unk0[0] && gUnknown_030012E6 > 2)
                {
                    sub_81D413C();
                    gUnknown_030012C8.unk0[2] = 2;
                }
                else
                {
                    sub_81D413C();
                    gUnknown_030012C8.unk0[2] = 2;
                }
            }
        }
        break;
    case 4:
        sub_81D3CBC();
        gUnknown_030012C8.unk0[1] = 5;
        break;
    case 5:
        if (gUnknown_030012C8.unk0[0] == 1 && gUnknown_030012E6 > 2)
            sub_81D413C();

        if (++gUnknown_030012E6 > 60)
        {
            gUnknown_030012C8.unk0[4] = 1;
            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    case 6:
        if (gUnknown_030012C8.unk0[2])
        {
            sub_81D3C7C();
            gUnknown_030012C8.unk0[2] = 0;
        }
        break;
    }

    return gUnknown_030012C8.unk0[2] | (gUnknown_030012C8.unk0[4] << 2) | (gUnknown_030012C8.unk0[3] << 4);
}

static u16 sub_81D3EE8(u8 arg0)
{
    u16 terminal = (*(vu32 *)REG_ADDR_SIOCNT) & (SIO_MULTI_SI | SIO_MULTI_SD);
    if (terminal == SIO_MULTI_SD && arg0)
    {
        gUnknown_030012C8.unk0[0] = 1;
        return 1;
    }
    else
    {
        gUnknown_030012C8.unk0[0] = 0;
        return 0;
    }
}

static void sub_81D3F1C(u32 arg0, u32 *arg1, u32 *arg2)
{
    if (gUnknown_030012C8.unk0[0])
    {
        REG_SIOCNT |= SIO_38400_BPS;
        gUnknown_030012C8.unk8 = arg1;
        REG_SIODATA32 = arg0;
        gUnknown_030012C8.unk10 = arg0 / 4 + 1;
        sub_81D3F68();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        gUnknown_030012C8.unk8 = arg2;
    }
}

static void sub_81D3F68(void)
{
    REG_TM3CNT_L = 0xFDA7;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void sub_81D3F9C(void)
{
    sub_81D414C();
    sub_81D413C();
}

void sub_81D3FAC(void)
{
    u16 i, playerCount, k;
    u32 value;
    u16 var0;
    u16 recvBuffer[4];

    switch (gUnknown_030012C8.unk0[1])
    {
    case 1:
        REG_SIOMLT_SEND = 0xCCD0; // Handshake id
        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        for (i = 0, playerCount = 0, k = 0; i < 4; i++)
        {
            if (recvBuffer[i] == 0xCCD0)
                playerCount++;
            else if (recvBuffer[i] != 0xFFFF)
                k++;
        }

        if (playerCount == 2 && k == 0)
            gUnknown_030012C8.unk0[1] = 2;
        break;
    case 3:
        value = REG_SIODATA32;
        if (!gUnknown_030012C8.unkC && !gUnknown_030012C8.unk0[0])
            gUnknown_030012C8.unk10 = value / 4 + 1;

        if (gUnknown_030012C8.unk0[0] == 1)
        {
            if (gUnknown_030012C8.unkC < gUnknown_030012C8.unk10)
            {
                REG_SIODATA32 = gUnknown_030012C8.unk8[gUnknown_030012C8.unkC];
                gUnknown_030012C8.unk14 += gUnknown_030012C8.unk8[gUnknown_030012C8.unkC];
            }
            else
            {
                REG_SIODATA32 = gUnknown_030012C8.unk14;
            }
        }
        else
        {
            if (gUnknown_030012C8.unkC > 0 && gUnknown_030012C8.unkC < gUnknown_030012C8.unk10 + 1)
            {
                gUnknown_030012C8.unk8[gUnknown_030012C8.unkC - 1] = value;
                gUnknown_030012C8.unk14 += value;
            }
            else if (gUnknown_030012C8.unkC)
            {
                if (gUnknown_030012C8.unk14 == value)
                    gUnknown_030012C8.unk0[3] = 1;
                else
                    gUnknown_030012C8.unk0[3] = 2;
            }

            gUnknown_030012E8 = 0;
        }

        if (++gUnknown_030012C8.unkC < gUnknown_030012C8.unk10 + 2)
        {
            if (gUnknown_030012C8.unk0[0])
                REG_TM3CNT_H |= TIMER_ENABLE;
            else
                sub_81D413C();
        }
        else
        {
            gUnknown_030012C8.unk0[1] = 4;
            gUnknown_030012E6 = 0;
        }
        break;
    case 5:
        if (!gUnknown_030012C8.unk0[0])
            REG_SIOMLT_SEND = gUnknown_030012C8.unk0[3];

        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        var0 = recvBuffer[1] - 1;
        if (var0 < 2)
        {
            if (gUnknown_030012C8.unk0[0] == 1)
                gUnknown_030012C8.unk0[3] = recvBuffer[1];

            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    }
}

static void sub_81D413C(void)
{
    REG_SIOCNT |= SIO_ENABLE;
}

static void sub_81D414C(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFDA7;
}

static void sub_81D4170(void)
{
    int keysMask = REG_KEYINPUT ^ KEYS_MASK;
    gUnknown_030012E2 = keysMask & ~gUnknown_030012E0;
    gUnknown_030012E0 = keysMask;
}

void sub_81D41A0(void)
{
    gUnknown_030012EC = REG_IME;
    gUnknown_030012EE = REG_IE;
    gUnknown_030012F0 = REG_TM3CNT_H;
    gUnknown_030012F2 = REG_SIOCNT;
    gUnknown_030012F4 = REG_RCNT;
}

void sub_81D41F4(void)
{
    REG_IME = gUnknown_030012EC;
    REG_IE = gUnknown_030012EE;
    REG_TM3CNT_H = gUnknown_030012F0;
    REG_SIOCNT = gUnknown_030012F2;
    REG_RCNT = gUnknown_030012F4;
}

void sub_81D4238(void)
{
    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
}

u8 sub_81D4258(void)
{
    u8 eventObjectId;
    TryGetEventObjectIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectId);
    return eventObjectId;
}

u32 sub_81D427C(void)
{
    u8 i;
    int skip;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    gUnknown_030012F8 = gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x - mew->currentCoords.x;
    gUnknown_030012FA = gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y - mew->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(gUnknown_030012FC); i++)
        gUnknown_030012FC[i] = DIR_NONE;

    if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x == gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x
     && gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y == gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y)
    {
        return DIR_NONE;
    }

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 8 == 0)
        mew->invisible = 0;
    else
        mew->invisible = 1;

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 9 == 0)
        return DIR_NONE;

    for (i = 0; i < ARRAY_COUNT(gFarawayIslandRockCoords); i++)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x == gFarawayIslandRockCoords[i][0])
        {
            skip = 0;
            if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y < gFarawayIslandRockCoords[i][1])
            {
                if (mew->currentCoords.y <= gFarawayIslandRockCoords[i][1])
                    skip = 1;
            }
            else
            {
                if (mew->currentCoords.y >= gFarawayIslandRockCoords[i][1])
                    skip = 1;
            }

            if (!skip)
            {
                if (gUnknown_030012F8 > 0)
                {
                    if (mew->currentCoords.x + 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                    {
                        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
                else if (gUnknown_030012F8 < 0)
                {
                    if (mew->currentCoords.x - 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                    {
                        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                }

                if (mew->currentCoords.x == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                {
                    if (gUnknown_030012FA > 0)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                    else
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
            }
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y == gFarawayIslandRockCoords[i][1])
        {
            skip = 0;
            if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x < gFarawayIslandRockCoords[i][0])
            {
                if (mew->currentCoords.x <= gFarawayIslandRockCoords[i][0])
                    skip = 1;
            }
            else
            {
                if (mew->currentCoords.x >= gFarawayIslandRockCoords[i][0])
                    skip = 1;
            }

            if (!skip)
            {
                if (gUnknown_030012FA > 0)
                {
                    if (mew->currentCoords.y + 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
                else if (gUnknown_030012FA < 0)
                {
                    if (mew->currentCoords.y - 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                }

                if (mew->currentCoords.y == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                {
                    if (gUnknown_030012F8 > 0)
                    {
                        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                    else
                    {
                        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
            }
        }
    }

    if (sub_81D4C14(mew, 0))
    {
        if (sub_81D4C58(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_NORTH;
    }

    if (sub_81D4C9C(mew, 0))
    {
        if (sub_81D4C58(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_SOUTH;
    }

    if (sub_81D4C58(mew, 0))
    {
        if (sub_81D4C14(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_EAST;
    }

    if (sub_81D4CE0(mew, 0))
    {
        if (sub_81D4C14(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_WEST;
    }

    if (gUnknown_030012FA == 0)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y > mew->currentCoords.y)
        {
            if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                return DIR_NORTH;
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y < mew->currentCoords.y)
        {
            if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                return DIR_SOUTH;
        }

        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
            return DIR_NORTH;

        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
            return DIR_SOUTH;
    }

    if (gUnknown_030012F8 == 0)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x > mew->currentCoords.x)
        {
            if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                return DIR_WEST;
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x < mew->currentCoords.x)
        {
            if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                return DIR_EAST;
        }

        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
            return DIR_EAST;

        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
            return DIR_WEST;
    }

    return sub_81D4890(DIR_NONE);
}

bool8 sub_81D4834(s16 x, s16 y)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x == x
     && gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y == y)
    {
        return FALSE;
    }

    return MetatileBehavior_IsPokeGrass(MapGridGetMetatileBehaviorAt(x, y));
}

static u8 sub_81D4890(u8 ignoredDir)
{
    u8 i;
    u8 count = 0;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    for (i = 0; i < ARRAY_COUNT(gUnknown_030012FC); i++)
        gUnknown_030012FC[i] = DIR_NONE;

    if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1) == TRUE && ignoredDir != DIR_NORTH)
    {
        gUnknown_030012FC[count] = DIR_NORTH;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_EAST)
    {
        gUnknown_030012FC[count] = DIR_EAST;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1) == TRUE && ignoredDir != DIR_SOUTH)
    {
        gUnknown_030012FC[count] = DIR_SOUTH;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_WEST)
    {
        gUnknown_030012FC[count] = DIR_WEST;
        count++;
    }

    if (count > 1)
        return gUnknown_030012FC[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % count];
    else
        return gUnknown_030012FC[0];
}

void UpdateFarawayIslandStepCounter(void)
{
    u16 steps = VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        steps++;
        if (steps >= 9999)
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0);
        else
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, steps);
    }
}

bool8 EventObjectIsFarawayIslandMew(struct EventObject *eventObject)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (eventObject->graphicsId == EVENT_OBJ_GFX_MEW)
            return TRUE;
    }

    return FALSE;
}

bool8 IsMewPlayingHideAndSeek(void)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (FlagGet(FLAG_CAUGHT_MEW) != TRUE && FlagGet(FLAG_HIDE_MEW) != TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 sub_81D4A58(struct EventObject *eventObject)
{
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) != 0xFFFF
     && VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 4 == 0)
        return TRUE;

    return FALSE;
}

void sub_81D4A90(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    mew->invisible = 0;
    if (gSpecialVar_0x8004 == 1)
    {
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[mew->spriteId].subpriority = 1;
    }
    else
    {
        VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0xFFFF);
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        if (gSpecialVar_Facing != DIR_NORTH)
            gSprites[mew->spriteId].subpriority = 1;

        LoadSpritePalette(&gFieldEffectObjectPaletteInfo1);
        UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(gFieldEffectObjectPaletteInfo1.tag));

        x = mew->currentCoords.x;
        y = mew->currentCoords.y;
        sub_80930E0(&x, &y, 8, 8);
        gUnknown_0203CF50 = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[15], x, y, gSprites[mew->spriteId].subpriority - 1);
        if (gUnknown_0203CF50 != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[gUnknown_0203CF50];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_81D4BEC(void)
{
    if (gUnknown_0203CF50 != MAX_SPRITES)
        DestroySprite(&gSprites[gUnknown_0203CF50]);
}

static bool8 sub_81D4C14(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012FA > 0 && sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
    {
        gUnknown_030012FC[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C58(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012F8 < 0 && sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
    {
        gUnknown_030012FC[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C9C(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012FA < 0 && sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
    {
        gUnknown_030012FC[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4CE0(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012F8 > 0 && sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
    {
        gUnknown_030012FC[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4D24(u8 mod)
{
    return gUnknown_030012FC[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % mod];
}

void sub_81D4D50(struct Unk03006370 *arg0, int arg1, u32 *arg2)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    gIntrTable[1] = sub_81D3FAC;
    gIntrTable[2] = sub_81D3F9C;
    sub_81D41A0();
    sub_81D4238();
    REG_IE |= INTR_FLAG_VCOUNT;
    REG_IME = backupIME;
    arg0->unk0 = 0;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
}

void sub_81D4DB8(struct Unk03006370 *arg0)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    sub_81D4238();
    sub_81D41F4();
    RestoreSerialTimer3IntrHandlers();
    REG_IME = backupIME;
}

u8 sub_81D4DE8(struct Unk03006370 *arg0)
{
    u8 var0 = 0;
    arg0->unk0 = sub_81D3D70(1, arg0->unk4, arg0->unk8, NULL);
    if ((arg0->unk0 & 0x13) == 0x10)
        var0 = 1;

    if (arg0->unk0 & 0x8)
        var0 = 2;

    if (arg0->unk0 & 0x4)
        var0 = 3;

    gShouldAdvanceLinkState = 0;
    return var0;
}

void sub_81D4E30(void)
{
    memset(gDecompressionBuffer, 0, 0x2000);
    gLinkType = 0x5503;
    OpenLink();
    SetSuppressLinkErrorMessage(TRUE);
}

bool32 sub_81D4E60(void)
{
    volatile u16 backupIME;
    u16 sp4[4];

    backupIME = REG_IME;
    REG_IME = 0;
    *(u64 *)sp4 = *(u64 *)gLink.tempRecvBuffer;
    REG_IME = backupIME;
    if (sp4[0] == 0xB9A0 && sp4[1] == 0xCCD0
     && sp4[2] == 0xFFFF && sp4[3] == 0xFFFF)
    {
        return TRUE;
    }

    return FALSE;
}

bool32 sub_81D4EC0(void)
{
    if (IsLinkMaster() && GetLinkPlayerCount_2() == 2)
        return TRUE;

    return FALSE;
}

u32 sub_81D4EE4(u8 *arg0, u16 *arg1)
{
    u8 var0;

    var0 = *arg0 - 3;
    if (var0 < 3 && HasLinkErrorOccurred())
    {
        *arg0 = 0;
        return 3;
    }

    switch (*arg0)
    {
    case 0:
        if (IsLinkMaster() && GetLinkPlayerCount_2() > 1)
        {
            *arg0 = 1;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            *arg0 = 0;
            return 1;
        }
        break;
    case 1:
        if (++(*arg1) > 5)
        {
            *arg1 = 0;
            *arg0 = 2;
        }
        break;
    case 2:
        if (GetLinkPlayerCount_2() == 2)
        {
            PlaySE(SE_PINPON);
            CheckShouldAdvanceLinkState();
            *arg1 = 0;
            *arg0 = 3;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            *arg0 = 0;
            return 1;
        }
        break;
    case 3:
        if (++(*arg1) > 30)
        {
            *arg0 = 0;
            return 5;
        }

        if (IsLinkConnectionEstablished())
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkPlayerDataExchangeComplete())
                {
                    *arg0 = 0;
                    return 2;
                }
                else
                {
                    *arg0 = 4;
                }
            }
            else
            {
                *arg0 = 3;
            }
        }
        break;
    case 4:
        sub_800ABF4(0);
        *arg0 = 5;
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
        {
            *arg0 = 0;
            return 4;
        }
        break;
    default:
        return 0;
    }

    return 0;
}

void sub_81D5014(void)
{
    int value;
    struct Unk81D5014 *data;
    u8 taskId = CreateTask(sub_81D5084, 0);
    data = (struct Unk81D5014 *)gTasks[taskId].data;
    data->unk8 = 0;
    data->unk9 = 0;
    data->unkA = 0;
    data->unkB = 0;
    data->unkC = 0;
    data->unkD = 0;
    data->unk0 = 0;
    data->unk2 = 0;
    data->unk4 = 0;
    data->unk6 = 0;
    data->unkE = 0;
    data->unk10 = AllocZeroed(0x40);
}

void sub_81D505C(u16 *arg0)
{
    *arg0 = 0;
}

bool32 sub_81D5064(u16 *arg0, u16 arg1)
{
    if (++(*arg0) > arg1)
    {
        *arg0 = 0;
        return TRUE;
    }
    
    return FALSE;
}

void sub_81D5084(u8 taskId)
{
    struct Unk81D5014 *data = (struct Unk81D5014 *)gTasks[taskId].data;
    switch (data->unk8)
    {
    case 0:
        if (mevent_0814257C(&data->unk9, gUnknown_085EDFD6))
            data->unk8 = 1;
        break;
    case 1:
        sub_81D4E30();
        sub_81D505C(&data->unk0);
        data->unk8 = 2;
        break;
    case 2:
        if (sub_81D5064(&data->unk0, 10))
            data->unk8 = 3;
        break;
    case 3:
        if (!sub_81D4EC0())
        {
            CloseLink();
            data->unk8 = 4;
        }
        else
        {
            data->unk8 = 13;
        }
        break;
    case 4:
        if (mevent_0814257C(&data->unk9, gUnknown_085EDFF5))
        {
            sub_8018884(gUnknown_085EE014);
            sub_81D505C(&data->unk0);
            data->unk8 = 5;
        }
        break;
    case 5:
        if (sub_81D5064(&data->unk0, 90))
        {
            sub_81D4E30();
            data->unk8 = 6;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_81D505C(&data->unk0);
            PlaySE(SE_SELECT);
            data->unk8 = 23;
        }
        break;
    case 6:
        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            CloseLink();
            sub_81D505C(&data->unk0);
            data->unk8 = 23;
        }
        else if (GetLinkPlayerCount_2() > 1)
        {
            sub_81D505C(&data->unk0);
            CloseLink();
            data->unk8 = 7;
        }
        else if (sub_81D4E60())
        {
            PlaySE(SE_SELECT);
            CloseLink();
            sub_81D505C(&data->unk0);
            data->unk8 = 8;
        }
        else if (sub_81D5064(&data->unk0, 10))
        {
            CloseLink();
            sub_81D4E30();
            sub_81D505C(&data->unk0);
        }
        break;
    case 7:
        if (mevent_0814257C(&data->unk9, gUnknown_085EE05C))
            data->unk8 = 4;
        break;
    case 8:
        sub_8018884(gUnknown_085EE097);
        // XXX: This (u32*) cast is discarding the const qualifier from gUnknown_089A3470
        sub_81D4D50(&gUnknown_03006370, gMultiBootProgram_BerryGlitchFix_Start - gUnknown_089A3470, (u32*)gUnknown_089A3470);
        data->unk8 = 9;
        break;
    case 9:
        data->unkE = sub_81D4DE8(&gUnknown_03006370);
        if (data->unkE)
            data->unk8 = 10;
        break;
    case 10:
        sub_81D4DB8(&gUnknown_03006370);
        if (data->unkE == 3)
        {
            data->unk8 = 20;
        }
        else if (data->unkE == 1)
        {
            sub_81D505C(&data->unk0);
            sub_8018884(gUnknown_085EE120);
            data->unk8 = 11;
        }
        else
        {
            data->unk8 = 0;
        }
        break;
    case 11:
        if (sub_81D5064(&data->unk0, 840))
            data->unk8 = 12;
        break;
    case 12:
        sub_81D4E30();
        sub_8018884(gUnknown_085EE0DC);
        data->unk8 = 13;
        break;
    case 13:
        switch (sub_81D4EE4(&data->unk9, &data->unk0))
        {
            case 0:
                break;
            case 2:
                sub_8018884(gUnknown_085EE097);
                data->unk8 = 14;
                break;
            case 1:
                PlaySE(SE_SELECT);
                CloseLink();
                data->unk8 = 23;
                break;
            case 5:
                CloseLink();
                data->unk8 = 21;
                break;
            case 3:
            case 4:
                CloseLink();
                data->unk8 = 20;
                break;
        }
        break;
    case 14:
        if (HasLinkErrorOccurred())
        {
            CloseLink();
            data->unk8 = 20;
        }
        else if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            data->unk8 = 15;
        }
        break;
    case 15:
        data->unkE = sub_81D3920(gDecompressionBuffer);
        sub_800ABF4(data->unkE);
        data->unk8 = 16;
        break;
    case 16:
        if (!gReceivedRemoteLinkPlayers)
        {
            if (data->unkE == 1)
                data->unk8 = 17;
            else
                data->unk8 = 20;
        }
        break;
    case 17:
        if (sub_81D3AB0((struct Unk81D38FC *)&gDecompressionBuffer))
        {
            sub_8018884(gUnknown_085EE0FA);
            sub_81D505C(&data->unk0);
            data->unk8 = 18;
        }
        else
        {
            data->unk8 = 22;
        }
        break;
    case 18:
        if (sub_81D5064(&data->unk0, 120))
        {
            sub_8018884(gUnknown_085EE107);
            PlayFanfare(MUS_FANFA4);
            data->unk8 = 19;
        }
        break;
    case 19:
        if (IsFanfareTaskInactive() && (gMain.newKeys & (A_BUTTON | B_BUTTON)))
            data->unk8 = 26;
        break;
    case 23:
        if (mevent_0814257C(&data->unk9,gUnknown_085EE06B))
            data->unk8 = 26;
        break;
    case 20:
        if (mevent_0814257C(&data->unk9, gUnknown_085EE0A3))
            data->unk8 = 0;
        break;
    case 21:
        if (mevent_0814257C(&data->unk9, gUnknown_085EE0BF))
            data->unk8 = 0;
        break;
    case 22:
        if (mevent_0814257C(&data->unk9, gUnknown_085EE12D))
            data->unk8 = 0;
        break;
    case 26:
        Free(data->unk10);
        DestroyTask(taskId);
        SetMainCallback2(sub_80186A4);
        break;
    }
}

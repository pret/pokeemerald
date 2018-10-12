#include "global.h"
#include "string_util.h"
#include "script.h"
#include "text.h"
#include "random.h"
#include "main.h"

struct Unk030062ECStruct
{
    u8 unk0;
    u16 unk2[3][5];
};

extern struct Unk030062ECStruct *gUnknown_030062EC;

extern const u8 *const gUnknown_08611330[];
extern const u8 gUnknown_08611548[8];

// This file's functions.
void sub_81A087C(void);

void sub_819F99C(u8 id)
{
    u8 i, var;
    const u8 *str;

    var = gSaveBlock2Ptr->field_DC[id].field_2;
    for (i = 0; var != 0 && i < 4; i++)
    {
        var /= 10;
    }

    StringCopy7(gStringVar1, gSaveBlock2Ptr->field_DC[id].playerName);
    ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->field_DC[id].language);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->field_DC[id].field_2, STR_CONV_MODE_RIGHT_ALIGN, i);
    str = gUnknown_08611330[gSaveBlock2Ptr->field_DC[id].field_0_0];
    StringExpandPlaceholders(gStringVar4, str);
}

void sub_819FA50(void)
{
    EnableBothScriptContexts();
}

void sub_819FA5C(struct UnkRecordMixingStruct *structPtr)
{
    u8 i;

    for (i = 0; i < 6; i++)
        structPtr->unk28[i] |= 0xFFFF;

    structPtr->playerName[0] = EOS;
    structPtr->field_0_0 = 16;
}

void sub_819FAA0(void)
{
    u8 i, j;

    gSaveBlock2Ptr->field_B2_1 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->field_DC[i].unk28[j] |= 0xFFFF;
        gSaveBlock2Ptr->field_DC[i].field_0_0 = 16;
        gSaveBlock2Ptr->field_DC[i].playerName[0] = EOS;
        gSaveBlock2Ptr->field_DC[i].field_0_1 = 0;
        gSaveBlock2Ptr->field_DC[i].field_2 = 0;
        gSaveBlock2Ptr->field_DC[i].field_1 = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->field_DC[i].playerId[j] = 0;
        gSaveBlock2Ptr->field_DC[i].language = gGameLanguage;
        gSaveBlock2Ptr->field_DC[i].unk40 = 0;
    }

    sub_81A087C();
}

u8 sub_819FBB0(void)
{
    return (gSaveBlock2Ptr->field_B1_0 != 0);
}

void sub_819FBC8(void)
{
    if (gSaveBlock2Ptr->field_DC[0].field_2 == 0)
    {
        do
        {
            gSaveBlock2Ptr->field_B0 = gUnknown_08611548[Random() % ARRAY_COUNT(gUnknown_08611548)];
        } while (gSaveBlock2Ptr->field_B0 == gSaveBlock2Ptr->field_DC[0].field_0_0);
    }
    else
    {
        do
        {
            gSaveBlock2Ptr->field_B0 = Random() % 16;
        } while (gSaveBlock2Ptr->field_B0 == gSaveBlock2Ptr->field_DC[0].field_0_0);
    }
}

void sub_819FC40(u8 value)
{
    gSaveBlock2Ptr->field_B1_0 = value;
}

void sub_819FC60(void)
{
    u8 array[10];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(array); i++)
        array[i] = i;

    for (i = 0; i < 50; i++)
    {
        u8 temp;
        u8 var1 = Random() % ARRAY_COUNT(array);
        u8 var2 = Random() % ARRAY_COUNT(array);
        SWAP(array[var1], array[var2], temp);
    }

    for (i = 0; i < 3; i++)
        gSaveBlock2Ptr->field_B4[i] = ((array[i * 2] & 0xF) << 4) | ((array[i * 2 + 1]) & 0xF);
}

u8 sub_819FCF8(u8 val, u8 *arg1, u8 *arg2)
{
    u8 i, count;
    u8 ret = 0;

    if (val == 2)
    {
        do
        {
            ret = Random() % 3;
            for (count = 0, i = 0; i < 5; i++)
            {
                if (gUnknown_030062EC->unk2[ret][i] != 0)
                    count++;
            }
        } while (count > 3);
    }
    else if (val == 1)
    {
        ret = arg1[*arg2];
        (*arg2)++;
    }

    return ret;
}

#include "global.h"
#include "dewford_trend.h"
#include "easy_chat.h"
#include "event_data.h"
#include "link.h"
#include "malloc.h"
#include "random.h"
#include "text.h"
#include "tv.h"
#include "string_util.h"
#include "constants/easy_chat.h"

// static functions
static void sub_8122804(struct EasyChatPair *s, u16 b, u8 c);
static bool8 sub_8122A58(struct EasyChatPair *a, struct EasyChatPair *b, u8 c);
static void sub_8122B28(struct EasyChatPair *s);
static bool8 SB1ContainsWords(u16 *a);
static bool8 IsEasyChatPairEqual(u16 *words1, u16 *words2);
static s16 GetEqualEasyChatPairIndex(struct EasyChatPair *s, struct EasyChatPair *a, u16 b);

// text
void InitDewfordTrend(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gSaveBlock1Ptr->easyChatPairs[i].words[0] = GetRandomEasyChatWordFromGroup(EC_GROUP_CONDITIONS);

        if (Random() & 1)
            gSaveBlock1Ptr->easyChatPairs[i].words[1] = GetRandomEasyChatWordFromGroup(EC_GROUP_LIFESTYLE);
        else
            gSaveBlock1Ptr->easyChatPairs[i].words[1] = GetRandomEasyChatWordFromGroup(EC_GROUP_HOBBIES);

        gSaveBlock1Ptr->easyChatPairs[i].unk1_6 = Random() & 1;
        sub_8122B28(&(gSaveBlock1Ptr->easyChatPairs[i]));
    }
    sub_8122804(gSaveBlock1Ptr->easyChatPairs, 5, 0);
}

void UpdateDewfordTrendPerDay(u16 a)
{
    u16 i;

    if (a != 0)
    {
        u32 sp0 = a * 5;

        for (i = 0; i < 5; i++)
        {
            u32 r4;
            u32 r2 = sp0;
            struct EasyChatPair *r5 = &(gSaveBlock1Ptr->easyChatPairs[i]);

            if (r5->unk1_6 == 0)
            {
                if (r5->unk0_0 >= (u16)r2)
                {
                    r5->unk0_0 -= r2;
                    if (r5->unk0_0 == 0)
                        r5->unk1_6 = 1;
                    continue;
                }
                r2 -= r5->unk0_0;
                r5->unk0_0 = 0;
                r5->unk1_6 = 1;
            }
            r4 = r5->unk0_0 + r2;
            if ((u16)r4 > r5->unk0_7)
            {
                u32 sp4 = r4 % r5->unk0_7;
                r4 = r4 / r5->unk0_7;

                r5->unk1_6 = r4 ^ 1;
                if (r5->unk1_6)
                    r5->unk0_0 = sp4;
                else
                    r5->unk0_0 = r5->unk0_7 - sp4;
            }
            else
            {
                r5->unk0_0 = r4;

                if (r5->unk0_0 == r5->unk0_7)
                    r5->unk1_6 = 0;
            }
        }
        sub_8122804(gSaveBlock1Ptr->easyChatPairs, 5, 0);
    }
}


bool8 sub_81226D8(u16 *a)
{
    struct EasyChatPair s = {0};
    u16 i;

    if (!SB1ContainsWords(a))
    {
        if (!FlagGet(FLAG_SYS_POPWORD_INPUT))
        {
            FlagSet(FLAG_SYS_POPWORD_INPUT);
            if (!FlagGet(FLAG_SYS_MIX_RECORD))
            {
                gSaveBlock1Ptr->easyChatPairs[0].words[0] = a[0];
                gSaveBlock1Ptr->easyChatPairs[0].words[1] = a[1];
                return TRUE;
            }
        }

        s.words[0] = a[0];
        s.words[1] = a[1];
        s.unk1_6 = 1;
        sub_8122B28(&s);

        for (i = 0; i < 5; i++)
        {
            if (sub_8122A58(&s, &(gSaveBlock1Ptr->easyChatPairs[i]), 0))
            {
                u16 r3 = 4;

                while (r3 > i)
                {
                    gSaveBlock1Ptr->easyChatPairs[r3] = gSaveBlock1Ptr->easyChatPairs[r3 - 1];
                    r3--;
                }
                gSaveBlock1Ptr->easyChatPairs[i] = s;
                if(i == 4)
                    sub_80EDC60(a);
                return (i == 0);
            }
        }
        gSaveBlock1Ptr->easyChatPairs[4] = s;
        sub_80EDC60(a);
    }
    return FALSE;
}


static void sub_8122804(struct EasyChatPair *s, u16 b, u8 c)
{
    u16 h;

    for (h = 0; h < b; h++)
    {
        u16 i;

        for (i = h + 1; i < b; i++)
        {
            if (sub_8122A58(&s[i], &s[h], c))
            {
                struct EasyChatPair temp;

                temp = s[i];
                s[i] = s[h];
                s[h] = temp;
            }
        }
    }
}

void ReceiveEasyChatPairsData(struct EasyChatPair *a, size_t size, u8 unused)
{
    u16 i, j, r3, players;
    struct EasyChatPair *buffer1, *buffer2, *src, *dst, *foo_of_buffer2;

    buffer1 = Alloc(0x100);
    if(buffer1 != NULL)
    {
        buffer2 = Alloc(0x100);
        if(buffer2 == NULL)
        {
            Free(buffer1);
        }
        else
        {
            players = GetLinkPlayerCount();
            for (i = 0; i < players; i++)
                memcpy(&(buffer1[i * 5]), (u8 *)a + i * size, 40);
            src = buffer1;
            dst = buffer2;
            r3 = 0;
            for (i = 0; i < players; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    s16 foo = GetEqualEasyChatPairIndex(buffer2, src, r3);
                    if (foo < 0)
                    {
                        *(dst++) = *src;
                        r3++;
                    }
                    else
                    {
                        foo_of_buffer2 = (struct EasyChatPair *)((u32)buffer2 + (foo * 8)); //required to do this to reverse the order of register operands in add ASM statement
                        if (foo_of_buffer2->unk0_0 < src->unk0_0)
                        {
                            *foo_of_buffer2 = *src;
                        }
                    }
                    src++;
                }
            }
            sub_8122804(buffer2, r3, 2);
            src = buffer2;
            dst = gSaveBlock1Ptr->easyChatPairs;
            for (i = 0; i < 5; i++)
                *(dst++) = *(src++);
            Free(buffer1);
            Free(buffer2);
        }
    }
}

void BufferTrendyPhraseString(void)
{
    struct EasyChatPair *s = &gSaveBlock1Ptr->easyChatPairs[gSpecialVar_0x8004];

    ConvertEasyChatWordsToString(gStringVar1, s->words, 2, 1);
}

void TrendyPhraseIsOld(void)
{
    u16 result = 0;
    
    do
    {
        if (gSaveBlock1Ptr->easyChatPairs[0].unk0_0 - gSaveBlock1Ptr->easyChatPairs[1].unk0_0 > 1)
            break;
        if (gSaveBlock1Ptr->easyChatPairs[0].unk1_6)
            break;
        if (!gSaveBlock1Ptr->easyChatPairs[1].unk1_6)
            break;
        result = 1;
    } while (0);
    
    gSpecialVar_Result = result;
}

void GetDewfordHallPaintingNameIndex(void)
{
    gSpecialVar_Result = (gSaveBlock1Ptr->easyChatPairs[0].words[0] + gSaveBlock1Ptr->easyChatPairs[0].words[1]) & 7;
}

static bool8 sub_8122A58(struct EasyChatPair *a, struct EasyChatPair *b, u8 c)
{
    switch (c)
    {
    case 0:
        if (a->unk0_0 > b->unk0_0)
            return 1;
        if (a->unk0_0 < b->unk0_0)
            return 0;
        if (a->unk0_7 > b->unk0_7)
            return 1;
        if (a->unk0_7 < b->unk0_7)
            return 0;
        break;
    case 1:
        if (a->unk0_7 > b->unk0_7)
            return 1;
        if (a->unk0_7 < b->unk0_7)
            return 0;
        if (a->unk0_0 > b->unk0_0)
            return 1;
        if (a->unk0_0 < b->unk0_0)
            return 0;
        break;
    case 2:
        if (a->unk0_0 > b->unk0_0)
            return 1;
        if (a->unk0_0 < b->unk0_0)
            return 0;
        if (a->unk0_7 > b->unk0_7)
            return 1;
        if (a->unk0_7 < b->unk0_7)
            return 0;
        if (a->unk2 > b->unk2)
            return 1;
        if (a->unk2 < b->unk2)
            return 0;
        if (a->words[0] > b->words[0])
            return 1;
        if (a->words[0] < b->words[0])
            return 0;
        if (a->words[1] > b->words[1])
            return 1;
        if (a->words[1] < b->words[1])
            return 0;
        return 1;
    }
    return Random() & 1;
}

static void sub_8122B28(struct EasyChatPair *s)
{
    u16 r4;

    r4 = Random() % 98;
    if (r4 > 50)
    {
        r4 = Random() % 98;
        if (r4 > 80)
            r4 = Random() % 98;
    }
    s->unk0_7 = r4 + 30;
    s->unk0_0 = (Random() % (r4 + 1)) + 30;
    s->unk2 = Random();
}

static bool8 SB1ContainsWords(u16 *a)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        if (IsEasyChatPairEqual(a, gSaveBlock1Ptr->easyChatPairs[i].words) != 0)
            return TRUE;
    }
    return FALSE;
}

static bool8 IsEasyChatPairEqual(u16 *words1, u16 *words2)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        if (*(words1++) != *(words2++))
            return FALSE;
    }
    return TRUE;
}

static s16 GetEqualEasyChatPairIndex(struct EasyChatPair*s, struct EasyChatPair *a, u16 b)
{
    s16 i;

    for (i = 0; i < b; i++)
    {
        if (IsEasyChatPairEqual(a->words, s->words))
            return i;
        s++;
    }
    return -1;
}

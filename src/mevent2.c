#include "global.h"
#include "util.h"
#include "main.h"
#include "event_data.h"
#include "easy_chat.h"
#include "script.h"
#include "battle_tower.h"
#include "mevent_news.h"
#include "string_util.h"
#include "new_game.h"
#include "mevent.h"
#include "constants/mevent.h"

static EWRAM_DATA bool32 gUnknown_02022C70 = FALSE;

static void sub_801B180(void);
static void ClearSavedWonderNewsInternal(void);
static bool32 ValidateWonderNews(const struct WonderNews *news);
static bool32 ValidateWonderCard(const struct WonderCard *card);
static void InitSavedWonderCard(void);
static void sub_801B368(void);
static void sub_801B9F8(void);
static void sub_801BA8C(u32 a0, u32 a1, u32 *a2, int a3);

#define CALC_CRC(data) CalcCRC16WithTable((void *)&(data), sizeof(data))

void sub_801AFD8(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift, sizeof(gSaveBlock1Ptr->mysteryGift));
    sub_801B180();
    InitQuestionnaireWords();
}

struct WonderNews *GetSavedWonderNews(void)
{
    return &gSaveBlock1Ptr->mysteryGift.news;
}

struct WonderCard *GetSavedWonderCard(void)
{
    return &gSaveBlock1Ptr->mysteryGift.card;
}

struct MEventBuffer_3430 *sav1_get_mevent_buffer_2(void)
{
    return &gSaveBlock1Ptr->mysteryGift.unk_3430;
}

struct MysteryEventStruct *sub_801B044(void)
{
    return &gSaveBlock1Ptr->mysteryGift.unk_340;
}

u16 *GetQuestionnaireWordsPtr(void)
{
    return gSaveBlock1Ptr->mysteryGift.questionnaireWords;
}

void ClearSavedWonderNews(void)
{
    ClearSavedWonderNewsInternal();
}

bool32 SaveWonderNews(const struct WonderNews *news)
{
    if (!ValidateWonderNews(news))
        return FALSE;

    ClearSavedWonderNewsInternal();
    gSaveBlock1Ptr->mysteryGift.news = *news;
    gSaveBlock1Ptr->mysteryGift.newsCrc = CALC_CRC(gSaveBlock1Ptr->mysteryGift.news);
    return TRUE;
}

bool32 ValidateSavedWonderNews(void)
{
    if (CALC_CRC(gSaveBlock1Ptr->mysteryGift.news) != gSaveBlock1Ptr->mysteryGift.newsCrc)
        return FALSE;
    if (!ValidateWonderNews(&gSaveBlock1Ptr->mysteryGift.news))
        return FALSE;

    return TRUE;
}

static bool32 ValidateWonderNews(const struct WonderNews *data)
{
    if (data->unk_00 == 0)
        return FALSE;

    return TRUE;
}

bool32 WonderNews_Test_Unk_02(void)
{
    const struct WonderNews *data = &gSaveBlock1Ptr->mysteryGift.news;
    if (data->unk_02 == 0)
        return FALSE;

    return TRUE;
}

static void ClearSavedWonderNewsInternal(void)
{
    CpuFill32(0, GetSavedWonderNews(), sizeof(gSaveBlock1Ptr->mysteryGift.news));
    gSaveBlock1Ptr->mysteryGift.newsCrc = 0;
}

static void sub_801B180(void)
{
    CpuFill32(0, sub_801B044(), sizeof(struct MysteryEventStruct));
    sub_801DBC0();
}

bool32 sub_801B1A4(const u8 *src)
{
    const u8 *r5 = (const u8 *)&gSaveBlock1Ptr->mysteryGift.news;
    u32 i;
    if (!ValidateSavedWonderNews())
        return FALSE;

    for (i = 0; i < sizeof(struct WonderNews); i++)
    {
        if (r5[i] != src[i])
            return FALSE;
    }

    return TRUE;
}

void ClearSavedWonderCard(void)
{
    InitSavedWonderCard();
    sub_801B368();
    sub_801B9F8();
    ClearRamScript();
    ClearMysteryEventFlags();
    ClearMysteryEventVars();
    ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);
}

bool32 SaveWonderCard(const struct WonderCard *card)
{
    struct MEventBuffer_3430 *r2;
    if (!ValidateWonderCard(card))
        return FALSE;

    ClearSavedWonderCard();
    memcpy(&gSaveBlock1Ptr->mysteryGift.card, card, sizeof(struct WonderCard));
    gSaveBlock1Ptr->mysteryGift.cardCrc = CALC_CRC(gSaveBlock1Ptr->mysteryGift.card);
    r2 = &gSaveBlock1Ptr->mysteryGift.unk_3430;
    r2->unk_06 = (&gSaveBlock1Ptr->mysteryGift.card)->unk_02;
    return TRUE;
}

bool32 ValidateSavedWonderCard(void)
{
    if (gSaveBlock1Ptr->mysteryGift.cardCrc != CALC_CRC(gSaveBlock1Ptr->mysteryGift.card))
        return FALSE;
    if (!ValidateWonderCard(&gSaveBlock1Ptr->mysteryGift.card))
        return FALSE;
    if (!ValidateSavedRamScript())
        return FALSE;

    return TRUE;
}

static bool32 ValidateWonderCard(const struct WonderCard *card)
{
    if (card->flagId == 0)
        return FALSE;
    if (card->unk_08_0 > 2)
        return FALSE;
    if (!(card->unk_08_6 == 0 || card->unk_08_6 == 1 || card->unk_08_6 == 2))
        return FALSE;
    if (card->bgType >= NUM_WONDER_BGS)
        return FALSE;
    if (card->unk_09 > 7)
        return FALSE;

    return TRUE;
}

bool32 WonderCard_Test_Unk_08_6(void)
{
    const struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
    if (card->unk_08_6 == 0)
        return FALSE;

    return TRUE;
}

static void InitSavedWonderCard(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift.card, sizeof(gSaveBlock1Ptr->mysteryGift.card));
    gSaveBlock1Ptr->mysteryGift.cardCrc = 0;
}

static void sub_801B368(void)
{
    CpuFill32(0, sav1_get_mevent_buffer_2(), 18 *sizeof(u16));
    gSaveBlock1Ptr->mysteryGift.unkCrc = 0;
}

u16 GetWonderCardFlagID(void)
{
    if (ValidateSavedWonderCard())
        return gSaveBlock1Ptr->mysteryGift.card.flagId;

    return 0;
}

void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer)
{
    if (buffer->unk_08_6 == 1)
        buffer->unk_08_6 = 0;
}

static bool32 IsWonderCardFlagIDInValidRange(u16 flagId)
{
    if (flagId >= 1000 && flagId < 1000 + NUM_MYSTERY_GIFT_FLAGS)
        return TRUE;

    return FALSE;
}

static const u16 sMysteryGiftFlags[] =
{
    FLAG_RECEIVED_AURORA_TICKET,
    FLAG_RECEIVED_MYSTIC_TICKET,
    FLAG_RECEIVED_OLD_SEA_MAP,
    FLAG_MYSTERY_GIFT_UNUSED_1,
    FLAG_MYSTERY_GIFT_UNUSED_2,
    FLAG_MYSTERY_GIFT_UNUSED_3,
    FLAG_MYSTERY_GIFT_UNUSED_4,
    FLAG_MYSTERY_GIFT_UNUSED_5,
    FLAG_MYSTERY_GIFT_UNUSED_6,
    FLAG_MYSTERY_GIFT_UNUSED_7,
    FLAG_MYSTERY_GIFT_UNUSED_8,
    FLAG_MYSTERY_GIFT_UNUSED_9,
    FLAG_MYSTERY_GIFT_UNUSED_10,
    FLAG_MYSTERY_GIFT_UNUSED_11,
    FLAG_MYSTERY_GIFT_UNUSED_12,
    FLAG_MYSTERY_GIFT_UNUSED_13,
    FLAG_MYSTERY_GIFT_UNUSED_14,
    FLAG_MYSTERY_GIFT_UNUSED_15,
    FLAG_MYSTERY_GIFT_UNUSED_16,
    FLAG_MYSTERY_GIFT_UNUSED_17,
};

bool32 CheckReceivedGiftFromWonderCard(void)
{
    u16 value = GetWonderCardFlagID();
    if (!IsWonderCardFlagIDInValidRange(value))
        return FALSE;

    if (FlagGet(sMysteryGiftFlags[value - 1000]) == TRUE)
        return FALSE;

    return TRUE;
}

static int sub_801B438(const struct MEventBuffer_3430 *data, int size)
{
    int r3 = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (data->unk_08[1][i] && data->unk_08[0][i])
            r3++;
    }

    return r3;
}

static bool32 sub_801B460(const struct MEventBuffer_3430 *data1, const u16 *data2, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (data1->unk_08[1][i] == data2[1])
            return TRUE;
        if (data1->unk_08[0][i] == data2[0])
            return TRUE;
    }

    return FALSE;
}

static bool32 sub_801B4A4(const u16 *data)
{
    if (data[1] == 0)
        return FALSE;
    if (data[0] == 0)
        return FALSE;
    if (data[0] >= NUM_SPECIES)
        return FALSE;
    return TRUE;
}

static int sub_801B4CC(void)
{
    struct WonderCard *data;
    if (!ValidateSavedWonderCard())
        return 0;

    data = &gSaveBlock1Ptr->mysteryGift.card;
    if (data->unk_08_0 != 1)
        return 0;

    return sub_801B438(&gSaveBlock1Ptr->mysteryGift.unk_3430, data->unk_09);
}

bool32 sub_801B508(const u16 *data)
{
    struct WonderCard *buffer = &gSaveBlock1Ptr->mysteryGift.card;
    int size = buffer->unk_09;
    int i;
    if (!sub_801B4A4(data))
        return FALSE;

    if (sub_801B460(&gSaveBlock1Ptr->mysteryGift.unk_3430, data, size))
        return FALSE;

    for (i = 0; i < size; i++)
    {
        if (gSaveBlock1Ptr->mysteryGift.unk_3430.unk_08[1][i] == 0 && gSaveBlock1Ptr->mysteryGift.unk_3430.unk_08[0][i] == 0)
        {
            gSaveBlock1Ptr->mysteryGift.unk_3430.unk_08[1][i] = data[1];
            gSaveBlock1Ptr->mysteryGift.unk_3430.unk_08[0][i] = data[0];
            return TRUE;
        }
    }

    return FALSE;
}

void sub_801B580(struct MEventStruct_Unk1442CC *data, bool32 isWonderNews)
{
    int i;
    CpuFill32(0, data, sizeof(struct MEventStruct_Unk1442CC));
    data->unk_00 = 0x101;
    data->unk_04 = 1;
    data->unk_08 = 1;

    if (isWonderNews)
    {
        data->unk_0C = 5;
        data->unk_10 = 0x0201;
    }
    else // Wonder Card
    {
        data->unk_0C = 4;
        data->unk_10 = 0x0200;
    }

    if (ValidateSavedWonderCard())
    {
        data->unk_14 = GetSavedWonderCard()->flagId;
        data->unk_20 = *sav1_get_mevent_buffer_2();
        data->unk_44 = GetSavedWonderCard()->unk_09;
    }
    else
    {
        data->unk_14 = 0;
    }

    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
        data->questionnaireWords[i] = gSaveBlock1Ptr->mysteryGift.questionnaireWords[i];

    CopyTrainerId(data->playerTrainerId, gSaveBlock2Ptr->playerTrainerId);
    StringCopy(data->playerName, gSaveBlock2Ptr->playerName);
    for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
        data->easyChatProfile[i] = gSaveBlock1Ptr->easyChatProfile[i];

    memcpy(data->romHeaderGameCode, RomHeaderGameCode, 4);
    data->romHeaderSoftwareVersion = RomHeaderSoftwareVersion;
}

bool32 sub_801B6A0(const struct MEventStruct_Unk1442CC *data, bool32 a1)
{
    if (data->unk_00 != 0x101)
        return FALSE;

    if (!(data->unk_04 & 1))
        return FALSE;

    if (!(data->unk_08 & 1))
        return FALSE;

    if (!a1)
    {
        if (!(data->unk_0C & 4))
            return FALSE;

        if (!(data->unk_10 & 0x380))
            return FALSE;
    }

    return TRUE;
}

u32 sub_801B6EC(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, const void *unused)
{
    if (a1->unk_14 == 0)
        return 0;

    if (*a0 == a1->unk_14)
        return 1;

    return 2;
}

u32 sub_801B708(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, const void *unused)
{
    int r4 = a1->unk_44 - sub_801B438(&a1->unk_20, a1->unk_44);
    if (r4 == 0)
        return 1;
    if (sub_801B460(&a1->unk_20, a0, a1->unk_44))
        return 3;
    if (r4 == 1)
        return 4;
    return 2;
}

bool32 MysteryGift_DoesQuestionnaireMatch(const struct MEventStruct_Unk1442CC *data, const u16 *words)
{
    int i;
    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
    {
        if (data->questionnaireWords[i] != words[i])
            return FALSE;
    }

    return TRUE;
}

static int sub_801B770(const struct MEventStruct_Unk1442CC *a0)
{
    return sub_801B438(&a0->unk_20, a0->unk_44);
}

u16 MEventStruct_Unk1442CC_GetValueNFrom_unk_20(const struct MEventStruct_Unk1442CC *a0, u32 command)
{
    switch (command)
    {
    case 0:
        return a0->unk_20.unk_00;
    case 1:
        return a0->unk_20.unk_02;
    case 2:
        return a0->unk_20.unk_04;
    case 3:
        return sub_801B770(a0);
    case 4:
        return a0->unk_44;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}

static void sub_801B7D8(u32 command)
{
    struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.card;
    if (data->unk_08_0 == 2)
    {
        u16 *dest = NULL;
        switch (command)
        {
        case 0:
            dest = &gSaveBlock1Ptr->mysteryGift.unk_3430.unk_00;
            break;
        case 1:
            dest = &gSaveBlock1Ptr->mysteryGift.unk_3430.unk_02;
            break;
        case 2:
            dest = &gSaveBlock1Ptr->mysteryGift.unk_3430.unk_04;
            break;
        case 3:
            break;
        case 4:
            break;
        }

        if (dest == NULL)
        {
            AGB_ASSERT(0);
        }
        else if (++(*dest) > 999)
        {
            *dest = 999;
        }
    }
}

u16 mevent_081445C0(u32 command)
{
    switch (command)
    {
        case GET_CARD_BATTLES_WON_INTERNAL:
        {
            struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
            if (card->unk_08_0 == 2)
            {
                struct MEventBuffer_3430 *buffer = &gSaveBlock1Ptr->mysteryGift.unk_3430;
                return buffer->unk_00;
            }
            break;
        }
        case 1: // Never occurs
        {
            struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
            if (card->unk_08_0 == 2)
            {
                struct MEventBuffer_3430 *buffer = &gSaveBlock1Ptr->mysteryGift.unk_3430;
                return buffer->unk_02;
            }
            break;
        }
        case 2: // Never occurs
        {
            struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
            if (card->unk_08_0 == 2)
            {
                struct MEventBuffer_3430 *buffer = &gSaveBlock1Ptr->mysteryGift.unk_3430;
                return buffer->unk_04;
            }
            break;
        }
        case GET_NUM_STAMPS_INTERNAL:
        {
            struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
            if (card->unk_08_0 == 1)
                return sub_801B4CC();
            break;
        }
        case GET_MAX_STAMPS_INTERNAL:
        {
            struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
            if (card->unk_08_0 == 1)
                return card->unk_09;
            break;
        }
    }

    AGB_ASSERT(0);
    return 0;
}

void ResetReceivedWonderCardFlag(void)
{
    gUnknown_02022C70 = FALSE;
}

bool32 MEventHandleReceivedWonderCard(u16 flagId)
{
    gUnknown_02022C70 = FALSE;
    if (flagId == 0)
        return FALSE;

    if (!ValidateSavedWonderCard())
        return FALSE;

    if (gSaveBlock1Ptr->mysteryGift.card.flagId != flagId)
        return FALSE;

    gUnknown_02022C70 = TRUE;
    return TRUE;
}

void RecordIdOfWonderCardSenderByEventType(u32 a0, u32 a1)
{
    if (gUnknown_02022C70)
    {
        switch (a0)
        {
        case 2:
            sub_801BA8C(2, a1, gSaveBlock1Ptr->mysteryGift.unk_344[1], 5);
            break;
        case 0:
            sub_801BA8C(0, a1, gSaveBlock1Ptr->mysteryGift.unk_344[0], 5);
            break;
        case 1:
            sub_801BA8C(1, a1, gSaveBlock1Ptr->mysteryGift.unk_344[0], 5);
            break;
        default:
            AGB_ASSERT(0);
        }
    }
}

static void sub_801B9F8(void)
{
    CpuFill32(0, gSaveBlock1Ptr->mysteryGift.unk_344, sizeof(gSaveBlock1Ptr->mysteryGift.unk_344));
}

static bool32 sub_801BA24(u32 a0, u32 *a1, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        if (a1[i] == a0)
            break;
    }

    if (i == size)
    {
        for (j = size - 1; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return TRUE;
    }
    else
    {
        for (j = i; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return FALSE;
    }
}

static void sub_801BA8C(u32 a0, u32 a1, u32 *a2, int a3)
{
    if (sub_801BA24(a1, a2, a3))
        sub_801B7D8(a0);
}

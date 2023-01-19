#include "global.h"
#include "mystery_gift.h"
#include "random.h"
#include "event_data.h"
#include "wonder_news.h"

/*
    Wonder News related functions.
    Because this feature is largely unused, the names in here are
    mostly nebulous and without a real indication of purpose.
*/

enum {
    NEWS_VAL_INVALID,
    NEWS_VAL_RECV_FRIEND,
    NEWS_VAL_RECV_WIRELESS,
    NEWS_VAL_NONE,
    NEWS_VAL_SENT,
    NEWS_VAL_SENT_MAX,
    NEWS_VAL_GET_MAX,
};

static u32 GetNewsId(struct WonderNewsMetadata *);
static void IncrementGetNewsCounter(struct WonderNewsMetadata *);
static u32 GetNewsValByNewsType(struct WonderNewsMetadata *);
static void IncrementSentNewsCounter(struct WonderNewsMetadata *);
static void ResetSentNewsCounter(struct WonderNewsMetadata *);

void GenerateRandomWonderNews(u32 newsType)
{
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();

    data->newsType = newsType;
    switch (newsType)
    {
    case WONDER_NEWS_NONE:
        break;
    case WONDER_NEWS_RECV_FRIEND:
    case WONDER_NEWS_RECV_WIRELESS:
        data->rand = (Random() % 15) + 16;
        break;
    case WONDER_NEWS_SENT:
        data->rand = (Random() % 15) + 1;
        break;
    }
}

void InitSavedWonderNews(void)
{
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();

    data->newsType = WONDER_NEWS_NONE;
    data->sentCounter = 0;
    data->getCounter = 0;
    data->rand = 0;
    VarSet(VAR_WONDER_NEWS_COUNTER, 0);
}

// Unused
static void TryIncrementWonderNewsVar(void)
{
    u16 *var = GetVarPointer(VAR_WONDER_NEWS_COUNTER);
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();

    if (data->getCounter > 4 && ++(*var) >= 500)
    {
        data->getCounter = 0;
        *var = 0;
    }
}

// Unused
u16 RetrieveWonderNewsVal(void)
{
    u16 *result = &gSpecialVar_Result;
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();
    u16 newsVal;

    // Checks if Mystery Event is enabled, not Mystery Gift?
    if (!IsMysteryEventEnabled() || !ValidateSavedWonderNews())
        return 0;

    newsVal = GetNewsValByNewsType(data);

    switch (newsVal)
    {
    case NEWS_VAL_RECV_FRIEND:
        *result = GetNewsId(data);
        break;
    case NEWS_VAL_RECV_WIRELESS:
        *result = GetNewsId(data);
        break;
    case NEWS_VAL_SENT:
        *result = GetNewsId(data);
        IncrementSentNewsCounter(data);
        break;
    case NEWS_VAL_SENT_MAX:
        *result = GetNewsId(data);
        ResetSentNewsCounter(data);
        break;
    case NEWS_VAL_INVALID:
    case NEWS_VAL_NONE:
    case NEWS_VAL_GET_MAX:
        break;
    }

    return newsVal;
}

static u32 GetNewsId(struct WonderNewsMetadata *data)
{
    u32 id;
    data->newsType = WONDER_NEWS_NONE;
    id = data->rand + 132;
    data->rand = 0;
    IncrementGetNewsCounter(data);
    return id;
}

static void ResetSentNewsCounter(struct WonderNewsMetadata *data)
{
    data->sentCounter = 0;
}

static void IncrementSentNewsCounter(struct WonderNewsMetadata *data)
{
    data->sentCounter++;
    if (data->sentCounter > 4)
        data->sentCounter = 4;
}

static void IncrementGetNewsCounter(struct WonderNewsMetadata *data)
{
    data->getCounter++;
    if (data->getCounter > 5)
        data->getCounter = 5;
}

static u32 GetNewsValByNewsType(struct WonderNewsMetadata *data)
{
    if (data->getCounter == 5)
        return NEWS_VAL_GET_MAX;

    switch (data->newsType)
    {
    case WONDER_NEWS_NONE:
        return NEWS_VAL_NONE;
    case WONDER_NEWS_RECV_FRIEND:
        return NEWS_VAL_RECV_FRIEND;
    case WONDER_NEWS_RECV_WIRELESS:
        return NEWS_VAL_RECV_WIRELESS;
    case WONDER_NEWS_SENT:
        if (data->sentCounter < 3)
            return NEWS_VAL_SENT;
        return NEWS_VAL_SENT_MAX;
    default:
        AGB_ASSERT(0);
        return NEWS_VAL_INVALID;
    }
}

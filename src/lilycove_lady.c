#include "global.h"
#include "main.h"
#include "overworld.h"
#include "fldeff.h"
#include "field_specials.h"
#include "pokeblock.h"
#include "event_data.h"
#include "script.h"
#include "random.h"
#include "string_util.h"
#include "item.h"
#include "constants/items.h"
#include "item_menu.h"
#include "text.h"
#include "easy_chat.h"
#include "lilycove_lady.h"
#include "contest.h"
#include "berry.h"
#include "strings.h"

// TODO use array count macro?
#define QUIZ_QUESTION_LEN 9
#define QUIZ_QUESTION_NUM 16

enum
{
    QUIZ_AUTHOR_LADY,
    QUIZ_AUTHOR_PLAYER,
    QUIZ_AUTHOR_OTHER_PLAYER
};

enum
{
    QUIZ_PHASE_ATTEMPT_QUIZ,
    QUIZ_PHASE_MAKE_YOUR_OWN,
    QUIZ_PHASE_GIVE_PRIZE
};

#include "data/lilycove_lady.h"


static void InitLilycoveQuizLady(void);
static void InitLilycoveFavorLady(void);
static void InitLilycoveContestLady(void);
static void sub_818E004(void);
static void sub_818DBC4(void);
static void sub_818E674(void);
static u8 BufferAuthorName(void);
static bool8 IsQuizTrainerIdNotPlayer(void);
static u8 GetPlayerNameLength(const u8 *);



static EWRAM_DATA struct LilycoveLadyFavor *sFavorLadyPtr = NULL;
static EWRAM_DATA struct LilycoveLadyQuiz *sQuizLadyPtr = NULL;
static EWRAM_DATA struct LilycoveLadyContest *sContestLadyPtr = NULL;

extern EWRAM_DATA u16 gSpecialVar_ItemId;

u8 GetLilycoveLadyId(void)
{
    return gSaveBlock1Ptr->lilycoveLady.id;
}

void SetLilycoveLadyGfx(void)
{
    LilycoveLady *lilycoveLady;

    VarSet(VAR_OBJ_GFX_ID_0, sLilycoveLadyGfxId[GetLilycoveLadyId()]);
    if (GetLilycoveLadyId() == LILYCOVE_LADY_CONTEST)
    {
        lilycoveLady = &gSaveBlock1Ptr->lilycoveLady;
        VarSet(VAR_OBJ_GFX_ID_1, sContestLadyMonGfxId[lilycoveLady->contest.category]);
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void SetLilycoveLady(void)
{
    u16 id;

    id = ((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]);
    id %= 6;
    id >>= 1;
    switch (id)
    {
        case LILYCOVE_LADY_QUIZ:
            InitLilycoveQuizLady();
            break;
        case LILYCOVE_LADY_FAVOR:
            InitLilycoveFavorLady();
            break;
        case LILYCOVE_LADY_CONTEST:
            InitLilycoveContestLady();
            break;
    }
}

void sub_818DA78(void)
{
    switch (GetLilycoveLadyId())
    {
        case LILYCOVE_LADY_QUIZ:
            sub_818E004();
            break;
        case LILYCOVE_LADY_FAVOR:
            sub_818DBC4();
            break;
        case LILYCOVE_LADY_CONTEST:
            sub_818E674();
            break;
    }
}

void SetLilycoveLadyRandomly(void)
{
    u8 id;

    id = Random() % 3;
    switch (id)
    {
        case LILYCOVE_LADY_QUIZ:
            InitLilycoveQuizLady();
            break;
        case LILYCOVE_LADY_FAVOR:
            InitLilycoveFavorLady();
            break;
        case LILYCOVE_LADY_CONTEST:
            InitLilycoveContestLady();
            break;
    }
}

void Script_GetLilycoveLadyId(void)
{
    gSpecialVar_Result = GetLilycoveLadyId();
}

static u8 GetNumAcceptedItems(const u16 *itemsArray)
{
    u8 items;

    for (items = 0; *itemsArray != ITEM_NONE; items ++, itemsArray ++);
    return items;
}

static void sub_818DB20(void)
{
    u8 size;
    u8 idx;

    sFavorLadyPtr->favorId = Random() % 6;
    size = GetNumAcceptedItems(sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId]);
    idx = Random() % size;
    sFavorLadyPtr->unk_010 = sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId][idx];
}

static void InitLilycoveFavorLady(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    sFavorLadyPtr->id = LILYCOVE_LADY_FAVOR;
    sFavorLadyPtr->phase = 0;
    sFavorLadyPtr->playerName[0] = EOS;
    sFavorLadyPtr->unk_002 = 0;
    sFavorLadyPtr->unk_003= 0;
    sFavorLadyPtr->itemId = ITEM_NONE;
    sFavorLadyPtr->language = gGameLanguage;
    sub_818DB20();
}

static void sub_818DBC4(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    sFavorLadyPtr->id = LILYCOVE_LADY_FAVOR;
    sFavorLadyPtr->phase = 0;
}

u8 sub_818DBE8(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    if (sFavorLadyPtr->phase == 2)
    {
        return 2;
    }
    else if (sFavorLadyPtr->phase == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static const u8 *GetFavorLadyDescription(u8 idx)
{
    return sFavorLadyDescriptions[idx];
}

void BufferFavorLadyDescription(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    StringCopy(gStringVar1, GetFavorLadyDescription(sFavorLadyPtr->favorId));
}

bool8 sub_818DC60(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    if (sFavorLadyPtr->playerName[0] != EOS)
    {
        StringCopy7(gStringVar3, sFavorLadyPtr->playerName);
        ConvertInternationalString(gStringVar3, sFavorLadyPtr->language);
        return TRUE;
    }
    return FALSE;
}

static void BufferItemName(u8 *dest, u16 itemId)
{
    StringCopy(dest, ItemId_GetName(itemId));
}

void sub_818DCC8(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    BufferItemName(gStringVar2, sFavorLadyPtr->itemId);
}

static void sub_818DCF4(const u8 *src, u8 *dest)
{
    memset(dest, 0xFF, 8);
    StringCopy7(dest, src);
}

void sub_818DD14(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    sub_818DCF4(sFavorLadyPtr->playerName, gStringVar3);
    ConvertInternationalString(gStringVar3, sFavorLadyPtr->language);
}

bool8 sub_818DD54(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    return sFavorLadyPtr->unk_002 ? TRUE : FALSE;
}

void OpenBagMenuForFavorLady(void)
{
    sub_81AAC50();
}

static bool8 sub_818DD84(u16 itemId)
{
    u8 numItems;
    u8 i;
    bool8 response;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    numItems = GetNumAcceptedItems(sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId]);
    sFavorLadyPtr->phase = 1;
    BufferItemName(gStringVar2, itemId);
    sFavorLadyPtr->itemId = itemId;
    sub_818DCF4(gSaveBlock2Ptr->playerName, sFavorLadyPtr->playerName);
    sFavorLadyPtr->language = gGameLanguage;
    response = FALSE;
    for (i = 0; i < numItems; i ++)
    {
        if (sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId][i] == itemId)
        {
            response = TRUE;
            sFavorLadyPtr->unk_003 ++;
            sFavorLadyPtr->unk_002 = 1;
            if (sFavorLadyPtr->unk_010 == itemId)
            {
                sFavorLadyPtr->unk_003 = 5;
            }
            break;
        }
        sFavorLadyPtr->unk_002 = 0;
    }
    return response;
}

bool8 sub_818DE44(void)
{
    return sub_818DD84(gSpecialVar_ItemId);
}

bool8 sub_818DE5C(void)
{
    u8 checkval;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    checkval = sFavorLadyPtr->unk_003;
    return checkval < 5 ? FALSE : TRUE;
}

static void BufferPrizeName(u16 itemId)
{
    BufferItemName(gStringVar2, itemId);
}

u16 sub_818DEA0(void)
{
    u16 itemId;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    itemId = sFavorLadyPrizes[sFavorLadyPtr->favorId];
    BufferPrizeName(itemId);
    sFavorLadyPtr->phase = 2;
    return itemId;
}

void sub_818DEDC(void)
{
    InitLilycoveFavorLady();
    sFavorLadyPtr->phase = 1;
}

void sub_818DEF4(void)
{
    EnableBothScriptContexts();
}

static void PickQuizQuestion(void)
{
    u8 questionId;
    u8 i;

    questionId = Random() % QUIZ_QUESTION_NUM;
    for (i = 0; i < QUIZ_QUESTION_LEN; i ++)
    {
        sQuizLadyPtr->question[i] = sQuizLadyQuizQuestions[questionId][i];
    }
    sQuizLadyPtr->answer = sQuizLadyQuizAnswers[questionId];
    sQuizLadyPtr->itemId = sQuizLadyPrizes[questionId];
    sQuizLadyPtr->questionId = questionId;
    sQuizLadyPtr->playerName[0] = EOS;
}

static void InitLilycoveQuizLady(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->id = LILYCOVE_LADY_QUIZ;
    sQuizLadyPtr->phase = QUIZ_PHASE_ATTEMPT_QUIZ;
    for (i = 0; i < QUIZ_QUESTION_LEN; i ++)
    {
        sQuizLadyPtr->question[i] = -1;
    }
    sQuizLadyPtr->answer = -1;
    sQuizLadyPtr->response = -1;
    for (i = 0; i < 4; i ++)
    {
        sQuizLadyPtr->playerTrainerId[i] = 0;
    }
    sQuizLadyPtr->itemId = ITEM_NONE;
    sQuizLadyPtr->waitingForChallenger = FALSE;
    sQuizLadyPtr->prevQuestionId = QUIZ_QUESTION_NUM;
    sQuizLadyPtr->language = gGameLanguage;
    PickQuizQuestion();
}

static void sub_818E004(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->id = LILYCOVE_LADY_QUIZ;
    sQuizLadyPtr->phase = QUIZ_PHASE_ATTEMPT_QUIZ;
    sQuizLadyPtr->waitingForChallenger = FALSE;
    sQuizLadyPtr->response = -1;
}

u8 GetQuizLadyPhase(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sQuizLadyPtr->phase == QUIZ_PHASE_GIVE_PRIZE)
    {
        return QUIZ_PHASE_GIVE_PRIZE;
    }
    else if (sQuizLadyPtr->phase == QUIZ_PHASE_MAKE_YOUR_OWN)
    {
        return QUIZ_PHASE_MAKE_YOUR_OWN;
    }
    else
    {
        return QUIZ_PHASE_ATTEMPT_QUIZ;
    }
}

// 0: waiting for someone to attempt player's quiz
// 1: ready to attempt other player's quiz
// 2: ready to attempt lady's quiz
u8 sub_818E06C(void) //sub_818E06C
{
    int i;
    int j;
    u8 author;
    struct LilycoveLadyQuiz *quiz;

    quiz = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sub_811F8D8(quiz->answer) == 0)
    {
        i = quiz->questionId;
        do
        {
            if (++ i >= QUIZ_QUESTION_NUM)
            {
                i = 0;
            }
        } while (sub_811F8D8(sQuizLadyQuizAnswers[i]) == 0);
        for (j = 0; j < QUIZ_QUESTION_LEN; j ++)
        {
            quiz->question[j] = sQuizLadyQuizQuestions[i][j];
        }
        quiz->answer = sQuizLadyQuizAnswers[i];
        quiz->itemId = sQuizLadyPrizes[i];
        quiz->questionId = i;
        quiz->playerName[0] = EOS;
    }
    author = BufferAuthorName();
    if (author == QUIZ_AUTHOR_LADY)
    {
        return 2;
    }
    else if (author == QUIZ_AUTHOR_OTHER_PLAYER || IsQuizTrainerIdNotPlayer())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static u8 BufferAuthorName(void)
{
    u8 author;
    u8 nameLen;
    u8 i;

    author = QUIZ_AUTHOR_PLAYER;
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sQuizLadyPtr->playerName[0] == EOS)
    {
        StringCopy7(gStringVar1, gText_QuizLady_Lady);
        author = QUIZ_AUTHOR_LADY;
    }
    else
    {
        StringCopy7(gStringVar1, sQuizLadyPtr->playerName);
        ConvertInternationalString(gStringVar1, sQuizLadyPtr->language);
        nameLen = GetPlayerNameLength(sQuizLadyPtr->playerName);
        if (nameLen == GetPlayerNameLength(gSaveBlock2Ptr->playerName))
        {
            u8 *name = sQuizLadyPtr->playerName;
            for (i = 0; i < nameLen; i ++)
            {
                name = sQuizLadyPtr->playerName;
                if (name[i] != gSaveBlock2Ptr->playerName[i])
                {
                    author = QUIZ_AUTHOR_OTHER_PLAYER;
                    break;
                }
            }
        }

    }
    return author;
}

static bool8 IsQuizTrainerIdNotPlayer(void)
{
    bool8 notPlayer;
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    notPlayer = FALSE;
    for (i = 0; i < 4; i ++)
    {
        if (sQuizLadyPtr->playerTrainerId[i] != gSaveBlock2Ptr->playerTrainerId[i])
        {
            notPlayer = TRUE;
            break;
        }
    }
    return notPlayer;
}

static u8 GetPlayerNameLength(const u8 *playerName)
{
    u8 len;
    const u8 *ptr;

    for (len = 0, ptr = playerName; *ptr != EOS; len ++, ptr ++);
    return len;
}

void sub_818E274(void)
{
    StringCopy(gStringVar1, ItemId_GetName(sQuizLadyPtr->itemId));
}

bool8 sub_818E298(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (BufferAuthorName() == QUIZ_AUTHOR_LADY)
    {
        sQuizLadyPtr->language = gGameLanguage;
        return TRUE;
    }
    return FALSE;
}

bool8 IsQuizLadyWaitingForChallenger(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    return sQuizLadyPtr->waitingForChallenger;
}

void sub_818E2FC(void) //sub_818E2FC
{
    ShowEasyChatScreen();
}

bool8 sub_818E308(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar1, sQuizLadyPtr->answer);
    CopyEasyChatWord(gStringVar2, sQuizLadyPtr->response);
    return StringCompare(gStringVar1, gStringVar2) ? FALSE : TRUE;
}

void BufferQuizPrizeItem(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gSpecialVar_0x8005 = sQuizLadyPtr->itemId;
}

void SetQuizLadyPhase_MakeYourOwn(void) 
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->phase = QUIZ_PHASE_MAKE_YOUR_OWN;
}

void SetQuizLadyPhase_GivePrize(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->phase = QUIZ_PHASE_GIVE_PRIZE;
}

void ClearQuizLadyResponse(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->response = -1;
}

void sub_818E3E0(void)
{
    sub_81AAC70();
}

void sub_818E3EC(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sub_818E298())
    {
        sQuizLadyPtr->prevQuestionId = sQuizLadyPtr->questionId;
    }
    else
    {
        sQuizLadyPtr->prevQuestionId = QUIZ_QUESTION_NUM;
    }
    PickQuizQuestion();
}

void sub_818E430(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    for (i = 0; i < QUIZ_QUESTION_LEN; i ++)
    {
        sQuizLadyPtr->question[i] = -1;
    }
    sQuizLadyPtr->answer = -1;
}

void sub_818E47C(void)
{
    gSpecialVar_0x8004 = EASY_CHAT_TYPE_QUIZ_SET_QUESTION;
    ShowEasyChatScreen();
}

void sub_818E490(void)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
}

void sub_818E4A4(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->itemId = gSpecialVar_ItemId;
    for (i = 0; i < 4; i ++)
    {
        sQuizLadyPtr->playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    }
    StringCopy7(sQuizLadyPtr->playerName, gSaveBlock2Ptr->playerName);
    sQuizLadyPtr->language = gGameLanguage;
}

void sub_818E510(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->waitingForChallenger = TRUE;
}

void sub_818E538(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar3, sQuizLadyPtr->answer);
}

void sub_818E564(void)
{
    EnableBothScriptContexts();
}

void sub_818E570(const LilycoveLady *lilycoveLady)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (lilycoveLady->quiz.prevQuestionId < QUIZ_QUESTION_NUM && sQuizLadyPtr->id == LILYCOVE_LADY_QUIZ)
    {
        for (i = 0; i < 4; i ++)
        {
            if (lilycoveLady->quiz.prevQuestionId != sQuizLadyPtr->questionId)
            {
                break;
            }
            sQuizLadyPtr->questionId = Random() % QUIZ_QUESTION_NUM;
        }
        if (lilycoveLady->quiz.prevQuestionId == sQuizLadyPtr->questionId)
        {
            sQuizLadyPtr->questionId = (sQuizLadyPtr->questionId + 1) % QUIZ_QUESTION_NUM;
        }
        sQuizLadyPtr->prevQuestionId = lilycoveLady->quiz.prevQuestionId;
    }
}

static void ResetContestLadyContestData(void)
{
    sContestLadyPtr->playerName[0] = EOS;
    sContestLadyPtr->fave_pkblk = 0;
    sContestLadyPtr->other_pkblk = 0;
    sContestLadyPtr->max_sheen = 0;
    sContestLadyPtr->category = Random() % CONTEST_CATEGORIES_COUNT;
}

static void InitLilycoveContestLady(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    sContestLadyPtr->id = LILYCOVE_LADY_CONTEST;
    sContestLadyPtr->givenPokeblock = FALSE;
    ResetContestLadyContestData();
    sContestLadyPtr->language = gGameLanguage;
}

static void sub_818E674(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    sContestLadyPtr->id = LILYCOVE_LADY_CONTEST;
    sContestLadyPtr->givenPokeblock = FALSE;
    if (sContestLadyPtr->fave_pkblk == FLAVOR_COUNT 
     || sContestLadyPtr->other_pkblk == FLAVOR_COUNT)
    {
        ResetContestLadyContestData();
    }
}

static void sub_818E6B0(u8 sheen)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->max_sheen <= sheen)
    {
        sContestLadyPtr->max_sheen = sheen;
        memset(sContestLadyPtr->playerName, EOS, sizeof(sContestLadyPtr->playerName));
        memcpy(sContestLadyPtr->playerName, gSaveBlock2Ptr->playerName, sizeof(sContestLadyPtr->playerName));
        sContestLadyPtr->language = gGameLanguage;
    }
}

bool8 GivePokeblockToContestLady(struct Pokeblock *pokeblock)
{
    u8 sheen;
    bool8 response;

    sheen = 0;
    response = FALSE;
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    switch (sContestLadyPtr->category)
    {
        case CONTEST_CATEGORY_COOL:
            if (pokeblock->spicy != 0)
            {
                sheen = pokeblock->spicy;
                response = TRUE;
            }
            break;
        case CONTEST_CATEGORY_BEAUTY:
            if (pokeblock->dry != 0)
            {
                sheen = pokeblock->dry;
                response = TRUE;
            }
            break;
        case CONTEST_CATEGORY_CUTE:
            if (pokeblock->sweet != 0)
            {
                sheen = pokeblock->sweet;
                response = TRUE;
            }
            break;
        case CONTEST_CATEGORY_SMART:
            if (pokeblock->bitter != 0)
            {
                sheen = pokeblock->bitter;
                response = TRUE;
            }
            break;
        case CONTEST_CATEGORY_TOUGH:
            if (pokeblock->sour != 0)
            {
                sheen = pokeblock->sour;
                response = TRUE;
            }
            break;
    }
    if (response == TRUE)
    {
        sub_818E6B0(sheen);
        sContestLadyPtr->fave_pkblk ++;
    }
    else
    {
        sContestLadyPtr->other_pkblk ++;
    }
    return response;
}

static void BufferContestLadyCategoryAndMonName(u8 *dest1, u8 *dest2)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest1, sContestLadyCategoryNames[sContestLadyPtr->category]);
    StringCopy10(dest2, sContestLadyMonNames[sContestLadyPtr->category]);
}

void BufferContestLadyMonName(u8 *dest1, u8 *dest2)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    *dest1 = sContestLadyPtr->category;
    StringCopy(dest2, sContestLadyMonNames[sContestLadyPtr->category]);
}

void BufferContestLadyPlayerName(u8 *dest)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest, sContestLadyPtr->playerName);
}

void BufferContestLadyLanguage(u8 *dest)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    *dest = sContestLadyPtr->language;
}

void BufferContestName(u8 *dest, u8 category)
{
    StringCopy(dest, sContestNames[category]);
}

u8 sub_818E880(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->fave_pkblk >= FLAVOR_COUNT)
    {
        return 1;
    }
    else if (sContestLadyPtr->fave_pkblk == 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool8 sub_818E8B4(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->givenPokeblock == TRUE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_818E8E0(void)
{
    bool8 response;

    response = FALSE;
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->fave_pkblk >= FLAVOR_COUNT 
     || sContestLadyPtr->other_pkblk >= FLAVOR_COUNT)
    {
        response = TRUE;
    }
    return response;
}

// called when mon enjoys pokeblock
void sub_818E914(void)
{
    BufferContestLadyCategoryAndMonName(gStringVar2, gStringVar1);
}

void OpenPokeblockCaseForContestLady(void)
{
    OpenPokeblockCase(3, CB2_ReturnToField);
}

void ContestLadyGivenPokeblock(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    sContestLadyPtr->givenPokeblock = TRUE;
}

void GetContestLadyMonSpecies(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    gSpecialVar_0x8005 = sContestLadyMonSpecies[sContestLadyPtr->category];
}

u8 GetContestLadyCategory(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    return sContestLadyPtr->category;
}

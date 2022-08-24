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
#include "strings.h"
#include "constants/lilycove_lady.h"

#include "data/lilycove_lady.h"

static void InitLilycoveQuizLady(void);
static void InitLilycoveFavorLady(void);
static void InitLilycoveContestLady(void);
static void ResetQuizLadyForRecordMix(void);
static void ResetFavorLadyForRecordMix(void);
static void ResetContestLadyForRecordMix(void);
static u8 BufferQuizAuthorName(void);
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

void InitLilycoveLady(void)
{
    u16 id = ((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]);
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

void ResetLilycoveLadyForRecordMix(void)
{
    switch (GetLilycoveLadyId())
    {
    case LILYCOVE_LADY_QUIZ:
        ResetQuizLadyForRecordMix();
        break;
    case LILYCOVE_LADY_FAVOR:
        ResetFavorLadyForRecordMix();
        break;
    case LILYCOVE_LADY_CONTEST:
        ResetContestLadyForRecordMix();
        break;
    }
}

// Unused
void InitLilycoveLadyRandomly(void)
{
    u8 lady = Random() % LILYCOVE_LADY_COUNT;

    switch (lady)
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
    u8 numItems;

    for (numItems = 0; *itemsArray != ITEM_NONE; numItems++, itemsArray++);
    return numItems;
}

static void FavorLadyPickFavorAndBestItem(void)
{
    u8 numItems;
    u8 bestItem;

    sFavorLadyPtr->favorId = Random() % ARRAY_COUNT(sFavorLadyRequests);
    numItems = GetNumAcceptedItems(sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId]);
    bestItem = Random() % numItems;
    sFavorLadyPtr->bestItem = sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId][bestItem];
}

static void InitLilycoveFavorLady(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    sFavorLadyPtr->id = LILYCOVE_LADY_FAVOR;
    sFavorLadyPtr->state = LILYCOVE_LADY_STATE_READY;
    sFavorLadyPtr->playerName[0] = EOS;
    sFavorLadyPtr->likedItem = FALSE;
    sFavorLadyPtr->numItemsGiven = 0;
    sFavorLadyPtr->itemId = ITEM_NONE;
    sFavorLadyPtr->language = gGameLanguage;
    FavorLadyPickFavorAndBestItem();
}

static void ResetFavorLadyForRecordMix(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    sFavorLadyPtr->id = LILYCOVE_LADY_FAVOR;
    sFavorLadyPtr->state = LILYCOVE_LADY_STATE_READY;
}

u8 GetFavorLadyState(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    if (sFavorLadyPtr->state == LILYCOVE_LADY_STATE_PRIZE)
        return LILYCOVE_LADY_STATE_PRIZE;
    else if (sFavorLadyPtr->state == LILYCOVE_LADY_STATE_COMPLETED)
        return LILYCOVE_LADY_STATE_COMPLETED;
    else
        return LILYCOVE_LADY_STATE_READY;
}

static const u8 *GetFavorLadyRequest(u8 idx)
{
    return sFavorLadyRequests[idx];
}

void BufferFavorLadyRequest(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    StringCopy(gStringVar1, GetFavorLadyRequest(sFavorLadyPtr->favorId));
}

bool8 HasAnotherPlayerGivenFavorLadyItem(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    if (sFavorLadyPtr->playerName[0] != EOS)
    {
        StringCopy_PlayerName(gStringVar3, sFavorLadyPtr->playerName);
        ConvertInternationalString(gStringVar3, sFavorLadyPtr->language);
        return TRUE;
    }
    return FALSE;
}

static void BufferItemName(u8 *dest, u16 itemId)
{
    StringCopy(dest, ItemId_GetName(itemId));
}

void BufferFavorLadyItemName(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    BufferItemName(gStringVar2, sFavorLadyPtr->itemId);
}

static void SetFavorLadyPlayerName(const u8 *src, u8 *dest)
{
    memset(dest, EOS, PLAYER_NAME_LENGTH + 1);
    StringCopy_PlayerName(dest, src);
}

void BufferFavorLadyPlayerName(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    SetFavorLadyPlayerName(sFavorLadyPtr->playerName, gStringVar3);
    ConvertInternationalString(gStringVar3, sFavorLadyPtr->language);
}

// Only used to determine if a record-mixed player had given her an item she liked
bool8 DidFavorLadyLikeItem(void)
{
    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    return sFavorLadyPtr->likedItem ? TRUE : FALSE;
}

void Script_FavorLadyOpenBagMenu(void)
{
    FavorLadyOpenBagMenu();
}

static bool8 DoesFavorLadyLikeItem(u16 itemId)
{
    u8 numItems;
    u8 i;
    bool8 likedItem;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    numItems = GetNumAcceptedItems(sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId]);
    sFavorLadyPtr->state = LILYCOVE_LADY_STATE_COMPLETED;
    BufferItemName(gStringVar2, itemId);
    sFavorLadyPtr->itemId = itemId;
    SetFavorLadyPlayerName(gSaveBlock2Ptr->playerName, sFavorLadyPtr->playerName);
    sFavorLadyPtr->language = gGameLanguage;
    likedItem = FALSE;
    for (i = 0; i < numItems; i ++)
    {
        if (sFavorLadyAcceptedItemLists[sFavorLadyPtr->favorId][i] == itemId)
        {
            likedItem = TRUE;
            sFavorLadyPtr->numItemsGiven++;
            sFavorLadyPtr->likedItem = TRUE;
            if (sFavorLadyPtr->bestItem == itemId)
                sFavorLadyPtr->numItemsGiven = LILYCOVE_LADY_GIFT_THRESHOLD;
            break;
        }
        sFavorLadyPtr->likedItem = FALSE;
    }
    return likedItem;
}

bool8 Script_DoesFavorLadyLikeItem(void)
{
    return DoesFavorLadyLikeItem(gSpecialVar_ItemId);
}

bool8 IsFavorLadyThresholdMet(void)
{
    u8 numItemsGiven;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    numItemsGiven = sFavorLadyPtr->numItemsGiven;
    return numItemsGiven < LILYCOVE_LADY_GIFT_THRESHOLD ? FALSE : TRUE;
}

static void FavorLadyBufferPrizeName(u16 prize)
{
    BufferItemName(gStringVar2, prize);
}

u16 FavorLadyGetPrize(void)
{
    u16 prize;

    sFavorLadyPtr = &gSaveBlock1Ptr->lilycoveLady.favor;
    prize = sFavorLadyPrizes[sFavorLadyPtr->favorId];
    FavorLadyBufferPrizeName(prize);
    sFavorLadyPtr->state = LILYCOVE_LADY_STATE_PRIZE;
    return prize;
}

void SetFavorLadyState_Complete(void)
{
    InitLilycoveFavorLady();
    sFavorLadyPtr->state = LILYCOVE_LADY_STATE_COMPLETED;
}

void FieldCallback_FavorLadyEnableScriptContexts(void)
{
    ScriptContext_Enable();
}

static void QuizLadyPickQuestion(void)
{
    u8 questionId;
    u8 i;

    questionId = Random() % ARRAY_COUNT(sQuizLadyQuizQuestions);
    for (i = 0; i < QUIZ_QUESTION_LEN; i ++)
        sQuizLadyPtr->question[i] = sQuizLadyQuizQuestions[questionId][i];
    sQuizLadyPtr->correctAnswer = sQuizLadyQuizAnswers[questionId];
    sQuizLadyPtr->prize = sQuizLadyPrizes[questionId];
    sQuizLadyPtr->questionId = questionId;
    sQuizLadyPtr->playerName[0] = EOS;
}

static void InitLilycoveQuizLady(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->id = LILYCOVE_LADY_QUIZ;
    sQuizLadyPtr->state = LILYCOVE_LADY_STATE_READY;

    for (i = 0; i < QUIZ_QUESTION_LEN; i ++)
        sQuizLadyPtr->question[i] = EC_EMPTY_WORD;

    sQuizLadyPtr->correctAnswer = EC_EMPTY_WORD;
    sQuizLadyPtr->playerAnswer = EC_EMPTY_WORD;

    for (i = 0; i < TRAINER_ID_LENGTH; i ++)
        sQuizLadyPtr->playerTrainerId[i] = 0;

    sQuizLadyPtr->prize = ITEM_NONE;
    sQuizLadyPtr->waitingForChallenger = FALSE;
    sQuizLadyPtr->prevQuestionId = ARRAY_COUNT(sQuizLadyQuizQuestions);
    sQuizLadyPtr->language = gGameLanguage;
    QuizLadyPickQuestion();
}

static void ResetQuizLadyForRecordMix(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->id = LILYCOVE_LADY_QUIZ;
    sQuizLadyPtr->state = LILYCOVE_LADY_STATE_READY;
    sQuizLadyPtr->waitingForChallenger = FALSE;
    sQuizLadyPtr->playerAnswer = EC_EMPTY_WORD;
}

u8 GetQuizLadyState(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sQuizLadyPtr->state == LILYCOVE_LADY_STATE_PRIZE)
        return LILYCOVE_LADY_STATE_PRIZE;
    else if (sQuizLadyPtr->state == LILYCOVE_LADY_STATE_COMPLETED)
        return LILYCOVE_LADY_STATE_COMPLETED;
    else
        return LILYCOVE_LADY_STATE_READY;
}

u8 GetQuizAuthor(void)
{
    s32 i, j;
    u8 authorNameId;
    struct LilycoveLadyQuiz *quiz = &gSaveBlock1Ptr->lilycoveLady.quiz;

    if (IsEasyChatAnswerUnlocked(quiz->correctAnswer) == FALSE)
    {
        i = quiz->questionId;
        do
        {
            if (++i >= (int)ARRAY_COUNT(sQuizLadyQuizQuestions))
                i = 0;
        } while (IsEasyChatAnswerUnlocked(sQuizLadyQuizAnswers[i]) == FALSE);

        for (j = 0; j < QUIZ_QUESTION_LEN; j++)
            quiz->question[j] = sQuizLadyQuizQuestions[i][j];
        quiz->correctAnswer = sQuizLadyQuizAnswers[i];
        quiz->prize = sQuizLadyPrizes[i];
        quiz->questionId = i;
        quiz->playerName[0] = EOS;
    }
    authorNameId = BufferQuizAuthorName();
    if (authorNameId == QUIZ_AUTHOR_NAME_LADY)
        return QUIZ_AUTHOR_LADY;
    else if (authorNameId == QUIZ_AUTHOR_NAME_OTHER_PLAYER || IsQuizTrainerIdNotPlayer())
        return QUIZ_AUTHOR_OTHER_PLAYER;
    else
        return QUIZ_AUTHOR_PLAYER;
}

static u8 BufferQuizAuthorName(void)
{
    u8 authorNameId;
    u8 nameLen;
    u8 i;

    authorNameId = QUIZ_AUTHOR_NAME_PLAYER;
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sQuizLadyPtr->playerName[0] == EOS)
    {
        StringCopy_PlayerName(gStringVar1, gText_QuizLady_Lady);
        authorNameId = QUIZ_AUTHOR_NAME_LADY;
    }
    else
    {
        StringCopy_PlayerName(gStringVar1, sQuizLadyPtr->playerName);
        ConvertInternationalString(gStringVar1, sQuizLadyPtr->language);
        nameLen = GetPlayerNameLength(sQuizLadyPtr->playerName);
        if (nameLen == GetPlayerNameLength(gSaveBlock2Ptr->playerName))
        {
            u8 *name = sQuizLadyPtr->playerName;
            for (i = 0; i < nameLen; i++)
            {
                name = sQuizLadyPtr->playerName;
                if (name[i] != gSaveBlock2Ptr->playerName[i])
                {
                    authorNameId = QUIZ_AUTHOR_NAME_OTHER_PLAYER;
                    break;
                }
            }
        }

    }
    return authorNameId;
}

static bool8 IsQuizTrainerIdNotPlayer(void)
{
    bool8 notPlayer;
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    notPlayer = FALSE;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
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

    for (len = 0, ptr = playerName; *ptr != EOS; len++, ptr++);
    return len;
}

void BufferQuizPrizeName(void)
{
    StringCopy(gStringVar1, ItemId_GetName(sQuizLadyPtr->prize));
}

bool8 BufferQuizAuthorNameAndCheckIfLady(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (BufferQuizAuthorName() == QUIZ_AUTHOR_NAME_LADY)
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

void QuizLadyGetPlayerAnswer(void)
{
    ShowEasyChatScreen();
}

bool8 IsQuizAnswerCorrect(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar1, sQuizLadyPtr->correctAnswer);
    CopyEasyChatWord(gStringVar2, sQuizLadyPtr->playerAnswer);
    return StringCompare(gStringVar1, gStringVar2) ? FALSE : TRUE;
}

void BufferQuizPrizeItem(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gSpecialVar_0x8005 = sQuizLadyPtr->prize;
}

void SetQuizLadyState_Complete(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->state = LILYCOVE_LADY_STATE_COMPLETED;
}

void SetQuizLadyState_GivePrize(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->state = LILYCOVE_LADY_STATE_PRIZE;
}

void ClearQuizLadyPlayerAnswer(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->playerAnswer = EC_EMPTY_WORD;
}

void Script_QuizLadyOpenBagMenu(void)
{
    QuizLadyOpenBagMenu();
}

void QuizLadyPickNewQuestion(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (BufferQuizAuthorNameAndCheckIfLady())
        sQuizLadyPtr->prevQuestionId = sQuizLadyPtr->questionId;
    else
        sQuizLadyPtr->prevQuestionId = ARRAY_COUNT(sQuizLadyQuizQuestions);
    QuizLadyPickQuestion();
}

void ClearQuizLadyQuestionAndAnswer(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    for (i = 0; i < QUIZ_QUESTION_LEN; i++)
        sQuizLadyPtr->question[i] = EC_EMPTY_WORD;
    sQuizLadyPtr->correctAnswer = EC_EMPTY_WORD;
}

void QuizLadySetCustomQuestion(void)
{
    gSpecialVar_0x8004 = EASY_CHAT_TYPE_QUIZ_SET_QUESTION;
    ShowEasyChatScreen();
}

void QuizLadyTakePrizeForCustomQuiz(void)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
}

void QuizLadyRecordCustomQuizData(void)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->prize = gSpecialVar_ItemId;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        sQuizLadyPtr->playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    StringCopy_PlayerName(sQuizLadyPtr->playerName, gSaveBlock2Ptr->playerName);
    sQuizLadyPtr->language = gGameLanguage;
}

void QuizLadySetWaitingForChallenger(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    sQuizLadyPtr->waitingForChallenger = TRUE;
}

void BufferQuizCorrectAnswer(void)
{
    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar3, sQuizLadyPtr->correctAnswer);
}


void FieldCallback_QuizLadyEnableScriptContexts(void)
{
    ScriptContext_Enable();
}

void QuizLadyClearQuestionForRecordMix(const LilycoveLady *lilycoveLady)
{
    u8 i;

    sQuizLadyPtr = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (lilycoveLady->quiz.prevQuestionId < ARRAY_COUNT(sQuizLadyQuizQuestions)
        && sQuizLadyPtr->id == LILYCOVE_LADY_QUIZ)
    {
        for (i = 0; i < 4; i++)
        {
            if (lilycoveLady->quiz.prevQuestionId != sQuizLadyPtr->questionId)
                break;
            sQuizLadyPtr->questionId = Random() % ARRAY_COUNT(sQuizLadyQuizQuestions);
        }
        if (lilycoveLady->quiz.prevQuestionId == sQuizLadyPtr->questionId)
            sQuizLadyPtr->questionId = (sQuizLadyPtr->questionId + 1) % (int)ARRAY_COUNT(sQuizLadyQuizQuestions);

        sQuizLadyPtr->prevQuestionId = lilycoveLady->quiz.prevQuestionId;
    }
}

static void ResetContestLadyContestData(void)
{
    sContestLadyPtr->playerName[0] = EOS;
    sContestLadyPtr->numGoodPokeblocksGiven = 0;
    sContestLadyPtr->numOtherPokeblocksGiven = 0;
    sContestLadyPtr->maxSheen = 0;
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

static void ResetContestLadyForRecordMix(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    sContestLadyPtr->id = LILYCOVE_LADY_CONTEST;
    sContestLadyPtr->givenPokeblock = FALSE;

    if (sContestLadyPtr->numGoodPokeblocksGiven == LILYCOVE_LADY_GIFT_THRESHOLD
     || sContestLadyPtr->numOtherPokeblocksGiven == LILYCOVE_LADY_GIFT_THRESHOLD)
        ResetContestLadyContestData();
}

static void ContestLadySavePlayerNameIfHighSheen(u8 sheen)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->maxSheen <= sheen)
    {
        sContestLadyPtr->maxSheen = sheen;
        memset(sContestLadyPtr->playerName, EOS, sizeof(sContestLadyPtr->playerName));
        memcpy(sContestLadyPtr->playerName, gSaveBlock2Ptr->playerName, sizeof(sContestLadyPtr->playerName));
        sContestLadyPtr->language = gGameLanguage;
    }
}

bool8 GivePokeblockToContestLady(struct Pokeblock *pokeblock)
{
    u8 sheen = 0;
    bool8 correctFlavor = FALSE;

    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    switch (sContestLadyPtr->category)
    {
    case CONTEST_CATEGORY_COOL:
        if (pokeblock->spicy != 0)
        {
            sheen = pokeblock->spicy;
            correctFlavor = TRUE;
        }
        break;
    case CONTEST_CATEGORY_BEAUTY:
        if (pokeblock->dry != 0)
        {
            sheen = pokeblock->dry;
            correctFlavor = TRUE;
        }
        break;
    case CONTEST_CATEGORY_CUTE:
        if (pokeblock->sweet != 0)
        {
            sheen = pokeblock->sweet;
            correctFlavor = TRUE;
        }
        break;
    case CONTEST_CATEGORY_SMART:
        if (pokeblock->bitter != 0)
        {
            sheen = pokeblock->bitter;
            correctFlavor = TRUE;
        }
        break;
    case CONTEST_CATEGORY_TOUGH:
        if (pokeblock->sour != 0)
        {
            sheen = pokeblock->sour;
            correctFlavor = TRUE;
        }
        break;
    }
    if (correctFlavor == TRUE)
    {
        ContestLadySavePlayerNameIfHighSheen(sheen);
        sContestLadyPtr->numGoodPokeblocksGiven++;
    }
    else
    {
        sContestLadyPtr->numOtherPokeblocksGiven++;
    }
    return correctFlavor;
}

static void BufferContestLadyCategoryAndMonName(u8 *category, u8 *nickname)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(category, sContestLadyCategoryNames[sContestLadyPtr->category]);
    StringCopy_Nickname(nickname, sContestLadyMonNames[sContestLadyPtr->category]);
}

void BufferContestLadyMonName(u8 *category, u8 *nickname)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    *category = sContestLadyPtr->category;
    StringCopy(nickname, sContestLadyMonNames[sContestLadyPtr->category]);
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

// Used by the Contest Lady's TV show to determine how well she performed
u8 GetContestLadyPokeblockState(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->numGoodPokeblocksGiven >= LILYCOVE_LADY_GIFT_THRESHOLD)
        return CONTEST_LADY_GOOD;
    else if (sContestLadyPtr->numGoodPokeblocksGiven == 0)
        return CONTEST_LADY_BAD;
    else
        return CONTEST_LADY_NORMAL;
}


bool8 HasPlayerGivenContestLadyPokeblock(void)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->givenPokeblock == TRUE)
        return TRUE;
    return FALSE;
}

bool8 ShouldContestLadyShowGoOnAir(void)
{
    bool8 putOnAir = FALSE;

    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (sContestLadyPtr->numGoodPokeblocksGiven >= LILYCOVE_LADY_GIFT_THRESHOLD
     || sContestLadyPtr->numOtherPokeblocksGiven >= LILYCOVE_LADY_GIFT_THRESHOLD)
        putOnAir = TRUE;

    return putOnAir;
}

void Script_BufferContestLadyCategoryAndMonName(void)
{
    BufferContestLadyCategoryAndMonName(gStringVar2, gStringVar1);
}

void OpenPokeblockCaseForContestLady(void)
{
    OpenPokeblockCase(PBLOCK_CASE_GIVE, CB2_ReturnToField);
}

void SetContestLadyGivenPokeblock(void)
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

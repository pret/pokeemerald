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
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/moves.h"

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


//TODO name phases

static void InitLilycoveQuizLady(void);
static void InitLilycoveFavorLady(void);
static void InitLilycoveContestLady(void);
static void sub_818E004(void);
static void sub_818DBC4(void);
static void sub_818E674(void);
static u8 BufferAuthorName(void);
static bool8 IsQuizTrainerIdNotPlayer(void);
static u8 GetPlayerNameLength(const u8 *);

static const u16 sContestLadyMonGfxId[] =
{
    EVENT_OBJ_GFX_ZIGZAGOON_1,
    EVENT_OBJ_GFX_SKITTY,
    EVENT_OBJ_GFX_POOCHYENA,
    EVENT_OBJ_GFX_KECLEON_1,
    EVENT_OBJ_GFX_PIKACHU
};

static const u16 sLilycoveLadyGfxId[] =
{
    EVENT_OBJ_GFX_WOMAN_4,
    EVENT_OBJ_GFX_WOMAN_2,
    EVENT_OBJ_GFX_GIRL_2
};

// Quiz Lady data
static const u16 sQuizLadyQuestion1[] =
{
    EC_WORD_WHICH,
    EC_WORD_STORES,
    EC_WORD_INFORMATION,
    EC_WORD_ON,
    EC_WORD_POKEMON,
    EC_WORD_QUES,
    EC_WORD_CAMERA,
    EC_WORD_POKEDEX,
    EC_WORD_POKENAV
};

static const u16 sQuizLadyQuestion2[] =
{
    EC_WORD_WHICH, 
    EC_WORD_ISN_T,
    EC_WORD_A,
    EC_WORD_GAME,
    EC_WORD_VERSION,
    EC_WORD_QUES,
    EC_WORD_RUBY,
    EC_WORD_SAPPHIRE,
    EC_WORD_DARK
};

static const u16 sQuizLadyQuestion3[] =
{
    EC_WORD_HOW,
    EC_WORD_DO,
    EC_WORD_POKEMON,
    EC_WORD_EVOLVE,
    EC_WORD_QUES,
    0xFFFF,
    EC_WORD_LEVEL,
    EC_WORD_INSOMNIA,
    EC_WORD_CUTE_CHARM
};

static const u16 sQuizLadyQuestion4[] =
{
    EC_WORD_WHICH,
    EC_WORD_IS,
    EC_WORD_THE,
    EC_WORD_PRETTY,
    EC_WORD_ITEM,
    EC_WORD_QUES,
    EC_WORD_COLD,
    EC_WORD_FLOWERS,
    EC_WORD_MACHINE
};

static const u16 sQuizLadyQuestion5[] =
{
    EC_WORD_WHICH,
    EC_WORD_ITEM,
    EC_WORD_DO,
    EC_WORD_YOU,
    EC_WORD_BREAK,
    EC_WORD_QUES,
    EC_WORD_EGG,
    EC_WORD_MAIL,
    EC_WORD_PHONE
};

static const u16 sQuizLadyQuestion6[] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_WORD_STOP,
    EC_MOVE2(CONFUSION),
    EC_WORD_QUES,
    0xFFFF,
    EC_WORD_ILLUMINATE,
    EC_WORD_OWN_TEMPO,
    EC_WORD_SWIFT_SWIM
};

static const u16 sQuizLadyQuestion7[] =
{
    EC_WORD_WHICH,
    EC_WORD_OF,
    EC_WORD_THESE,
    EC_WORD_IS,
    EC_WORD_MUSIC,
    EC_WORD_QUES,
    EC_WORD_FLYING,
    EC_WORD_STEEL,
    EC_WORD_ROCK
};

static const u16 sQuizLadyQuestion8[] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_MOVE2(BLOCK),
    EC_WORD_ESCAPE,
    EC_WORD_QUES,
    0xFFFF, 
    EC_WORD_RUN_AWAY,
    EC_WORD_SHADOW_TAG,
    EC_WORD_WONDER_GUARD
};

static const u16 sQuizLadyQuestion9[] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_WORD_STOP,
    EC_WORD_POISON,
    EC_WORD_QUES,
    0xFFFF,
    EC_WORD_GUTS,
    EC_WORD_IMMUNITY,
    EC_WORD_SHED_SKIN
};

static const u16 sQuizLadyQuestion10[] =
{
    EC_WORD_WHICH,
    EC_WORD_GOES,
    EC_WORD_WITH,
    EC_WORD_CENTER,
    EC_WORD_QUES,
    0xFFFF,
    EC_WORD_POKEDEX,
    EC_WORD_POKEMON,
    EC_WORD_POKENAV
};

static const u16 sQuizLadyQuestion11[] =
{
    EC_WORD_WHICH,
    EC_WORD_STORES,
    EC_WORD_YOUR,
    EC_WORD_POKEMON,
    EC_WORD_QUES,
    0xFFFF,
    EC_WORD_PC,
    EC_WORD_DEPT_STORE,
    EC_WORD_TELEVISION
};

static const u16 sQuizLadyQuestion12[] =
{
    EC_WORD_WHICH,
    EC_WORD_MACHINE,
    EC_WORD_GIVES,
    EC_WORD_YOU,
    EC_WORD_INFORMATION,
    EC_WORD_QUES,
    EC_WORD_BIKE,
    EC_WORD_LOCOMOTIVE,
    EC_WORD_TELEVISION
};

static const u16 sQuizLadyQuestion13[] =
{
    EC_WORD_A,
    EC_WORD_POKEMON,
    EC_WORD_WAS,
    EC_WORD_ONCE,
    EC_WORD_THIS,
    EC_WORD_QUES,
    EC_WORD_PHONE,
    EC_WORD_PLUSH_DOLL,
    EC_WORD_LETTER
};

static const u16 sQuizLadyQuestion14[] =
{
    EC_WORD_STEEL,
    EC_WORD_IS,
    EC_WORD_STRONG,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_ICE,
    EC_WORD_GROUND,
    0xFFFF
};

static const u16 sQuizLadyQuestion15[] =
{
    EC_WORD_DARK,
    EC_WORD_IS,
    EC_WORD_WEAK,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_PSYCHIC,
    EC_WORD_FIGHTING,
    0xFFFF
};

static const u16 sQuizLadyQuestion16[] =
{
    EC_WORD_GHOST,
    EC_WORD_IS,
    EC_WORD_WEAK,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_NORMAL,
    EC_WORD_DARK,
    0xFFFF
};

static const u16 *const sQuizLadyQuizQuestions[] =
{
    sQuizLadyQuestion1,
    sQuizLadyQuestion2,
    sQuizLadyQuestion3,
    sQuizLadyQuestion4,
    sQuizLadyQuestion5,
    sQuizLadyQuestion6,
    sQuizLadyQuestion7,
    sQuizLadyQuestion8,
    sQuizLadyQuestion9,
    sQuizLadyQuestion10,
    sQuizLadyQuestion11,
    sQuizLadyQuestion12,
    sQuizLadyQuestion13,
    sQuizLadyQuestion14,
    sQuizLadyQuestion15,
    sQuizLadyQuestion16
};

static const u16 sQuizLadyQuizAnswers[] =
{
    EC_WORD_POKEDEX,
    EC_WORD_DARK,
    EC_WORD_LEVEL,
    EC_WORD_FLOWERS,
    EC_WORD_EGG,
    EC_WORD_OWN_TEMPO,
    EC_WORD_ROCK,
    EC_WORD_SHADOW_TAG,
    EC_WORD_IMMUNITY,
    EC_WORD_POKEMON,
    EC_WORD_PC,
    EC_WORD_TELEVISION,
    EC_WORD_PLUSH_DOLL,
    EC_WORD_ICE,
    EC_WORD_FIGHTING,
    EC_WORD_DARK            // DARK is accepted as the correct answer despite the fact that it's wrong
};

static const u16 sQuizLadyPrizes[] =
{
    ITEM_GLITTER_MAIL,
    ITEM_BEAD_MAIL,
    ITEM_TROPIC_MAIL,
    ITEM_MAX_ETHER,
    ITEM_MAX_ETHER,
    ITEM_MAX_ETHER,
    ITEM_WATMEL_BERRY,
    ITEM_BELUE_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_LUXURY_BALL,
    ITEM_TM15_HYPER_BEAM,
    ITEM_BIG_PEARL,
    ITEM_STAR_PIECE,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_PREMIER_BALL
};

#define QUIZ_QUESTION_LEN 9
#define QUIZ_QUESTION_NUM 16

// Favor Lady data
static const u8 *const sFavorLadyDescriptions[] =
{
    gText_FavorLady_Slippery,
    gText_FavorLady_Roundish,
    gText_FavorLady_Whamish,
    gText_FavorLady_Shiny,
    gText_FavorLady_Sticky,
    gText_FavorLady_Pointy
};

static const u16 sFavorLadyAcceptedItems_Slippery[] =
{
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_MAX_REPEL,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_BURN_HEAL,
    ITEM_BELUE_BERRY,
    ITEM_AWAKENING,
    ITEM_ICE_HEAL,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_ENERGY_POWDER,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Roundish[] =
{
    ITEM_FLUFFY_TAIL,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_HARD_STONE,
    ITEM_SMOKE_BALL,
    ITEM_SHOAL_SHELL,
    ITEM_TINY_MUSHROOM,
    ITEM_BIG_MUSHROOM,
    ITEM_PECHA_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_GREPA_BERRY,
    ITEM_MAGOST_BERRY,
    ITEM_WATMEL_BERRY,
    ITEM_POKE_BALL,
    ITEM_ULTRA_BALL,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Whamish[] =
{
    ITEM_REVIVAL_HERB,
    ITEM_POTION,
    ITEM_FRESH_WATER,
    ITEM_SODA_POP,
    ITEM_LEMONADE,
    ITEM_HARD_STONE,
    ITEM_LIGHT_BALL,
    ITEM_LAVA_COOKIE,
    ITEM_CHESTO_BERRY,
    ITEM_NANAB_BERRY,
    ITEM_WEPEAR_BERRY,
    ITEM_KELPSY_BERRY,
    ITEM_NOMEL_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Shiny[] =
{
    ITEM_HEAL_POWDER,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFEND,
    ITEM_BLUE_FLUTE,
    ITEM_YELLOW_FLUTE,
    ITEM_RED_FLUTE,
    ITEM_BLACK_FLUTE,
    ITEM_WHITE_FLUTE,
    ITEM_NUGGET,
    ITEM_SUN_STONE,
    ITEM_STARDUST,
    ITEM_STAR_PIECE,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_TWISTED_SPOON,
    ITEM_SILVER_POWDER,
    ITEM_BRIGHT_POWDER,
    ITEM_LUXURY_BALL,
    ITEM_PREMIER_BALL,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Sticky[] =
{
    ITEM_ENERGY_ROOT,
    ITEM_FULL_RESTORE,
    ITEM_MAX_POTION,
    ITEM_DIRE_HIT,
    ITEM_X_ACCURACY,
    ITEM_GUARD_SPEC,
    ITEM_WATMEL_BERRY,
    ITEM_LEFTOVERS,
    ITEM_TINY_MUSHROOM,
    ITEM_HEART_SCALE,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Pointy[] =
{
    ITEM_QUICK_CLAW,
    ITEM_POISON_BARB,
    ITEM_SHARP_BEAK,
    ITEM_DRAGON_FANG,
    ITEM_TAMATO_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_PETAYA_BERRY,
    ITEM_SALAC_BERRY,
    ITEM_STARDUST,
    ITEM_STAR_PIECE,
    ITEM_NONE
};

static const u16 *const sFavorLadyAcceptedItemLists[] =
{
    sFavorLadyAcceptedItems_Slippery,
    sFavorLadyAcceptedItems_Roundish,
    sFavorLadyAcceptedItems_Whamish,
    sFavorLadyAcceptedItems_Shiny,
    sFavorLadyAcceptedItems_Sticky,
    sFavorLadyAcceptedItems_Pointy
};

static const u16 sFavorLadyPrizes[] =
{
    ITEM_LUXURY_BALL,
    ITEM_NUGGET,
    ITEM_PROTEIN,
    ITEM_HEART_SCALE,
    ITEM_RARE_CANDY,
    ITEM_PP_MAX
};


static const u8 *const sContestLadyMonNames[] =
{
    gText_ContestLady_Handsome,
    gText_ContestLady_Vinny,
    gText_ContestLady_Moreme,
    gText_ContestLady_Ironhard,
    gText_ContestLady_Muscle
};

static const u8 *const sContestLadyCategoryNames[] =
{
    gText_ContestLady_Coolness,
    gText_ContestLady_Beauty,
    gText_ContestLady_Cuteness,
    gText_ContestLady_Smartness,
    gText_ContestLady_Toughness
};

static const u8 *const sContestNames[] =
{
    gText_CoolnessContest,
    gText_BeautyContest,
    gText_CutenessContest,
    gText_SmartnessContest,
    gText_ToughnessContest
};

static const u16 sContestLadyMonSpecies[] =
{
    SPECIES_ZIGZAGOON,
    SPECIES_SKITTY,
    SPECIES_POOCHYENA,
    SPECIES_KECLEON,
    SPECIES_PIKACHU
};

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

static void sub_818E794(u8 *dest1, u8 *dest2) //sub_818E794
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest1, sContestLadyCategoryNames[sContestLadyPtr->category]);
    StringCopy10(dest2, sContestLadyMonNames[sContestLadyPtr->category]);
}

void sub_818E7E0(u8 *dest1, u8 *dest2)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    *dest1 = sContestLadyPtr->category;
    StringCopy(dest2, sContestLadyMonNames[sContestLadyPtr->category]);
}

void sub_818E81C(u8 *dest)
{
    sContestLadyPtr = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest, sContestLadyPtr->playerName);
}

void sub_818E848(u8 *dest)
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
    sub_818E794(gStringVar2, gStringVar1);
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

#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/moves.h"

static const u16 sContestLadyMonGfxId[] =
{
    [CONTEST_CATEGORY_COOL]   = OBJ_EVENT_GFX_ZIGZAGOON_1,
    [CONTEST_CATEGORY_BEAUTY] = OBJ_EVENT_GFX_SKITTY,
    [CONTEST_CATEGORY_CUTE]   = OBJ_EVENT_GFX_POOCHYENA,
    [CONTEST_CATEGORY_SMART]  = OBJ_EVENT_GFX_KECLEON,
    [CONTEST_CATEGORY_TOUGH]  = OBJ_EVENT_GFX_PIKACHU
};

static const u16 sLilycoveLadyGfxId[] =
{
    OBJ_EVENT_GFX_WOMAN_4,
    OBJ_EVENT_GFX_WOMAN_2,
    OBJ_EVENT_GFX_GIRL_2
};

// Quiz Lady data
static const u16 sQuizLadyQuestion1[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion2[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion3[QUIZ_QUESTION_LEN] =
{
    EC_WORD_HOW,
    EC_WORD_DO,
    EC_WORD_POKEMON,
    EC_WORD_EVOLVE,
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_LEVEL,
    EC_WORD_INSOMNIA,
    EC_WORD_CUTE_CHARM
};

static const u16 sQuizLadyQuestion4[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion5[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion6[QUIZ_QUESTION_LEN] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_WORD_STOP,
    EC_MOVE2(CONFUSION),
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_ILLUMINATE,
    EC_WORD_OWN_TEMPO,
    EC_WORD_SWIFT_SWIM
};

static const u16 sQuizLadyQuestion7[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion8[QUIZ_QUESTION_LEN] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_MOVE2(BLOCK),
    EC_WORD_ESCAPE,
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_RUN_AWAY,
    EC_WORD_SHADOW_TAG,
    EC_WORD_WONDER_GUARD
};

static const u16 sQuizLadyQuestion9[QUIZ_QUESTION_LEN] =
{
    EC_WORD_WHICH,
    EC_WORD_WILL,
    EC_WORD_STOP,
    EC_WORD_POISON,
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_GUTS,
    EC_WORD_IMMUNITY,
    EC_WORD_SHED_SKIN
};

static const u16 sQuizLadyQuestion10[QUIZ_QUESTION_LEN] =
{
    EC_WORD_WHICH,
    EC_WORD_GOES,
    EC_WORD_WITH,
    EC_WORD_CENTER,
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_POKEDEX,
    EC_WORD_POKEMON,
    EC_WORD_POKENAV
};

static const u16 sQuizLadyQuestion11[QUIZ_QUESTION_LEN] =
{
    EC_WORD_WHICH,
    EC_WORD_STORES,
    EC_WORD_YOUR,
    EC_WORD_POKEMON,
    EC_WORD_QUES,
    EC_EMPTY_WORD,
    EC_WORD_PC,
    EC_WORD_DEPT_STORE,
    EC_WORD_TELEVISION
};

static const u16 sQuizLadyQuestion12[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion13[QUIZ_QUESTION_LEN] =
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

static const u16 sQuizLadyQuestion14[QUIZ_QUESTION_LEN] =
{
    EC_WORD_STEEL,
    EC_WORD_IS,
    EC_WORD_STRONG,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_ICE,
    EC_WORD_GROUND,
    EC_EMPTY_WORD
};

static const u16 sQuizLadyQuestion15[QUIZ_QUESTION_LEN] =
{
    EC_WORD_DARK,
    EC_WORD_IS,
    EC_WORD_WEAK,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_PSYCHIC,
    EC_WORD_FIGHTING,
    EC_EMPTY_WORD
};

static const u16 sQuizLadyQuestion16[QUIZ_QUESTION_LEN] =
{
    EC_WORD_GHOST,
    EC_WORD_IS,
    EC_WORD_WEAK,
    EC_WORD_VERSUS,
    EC_WORD_WHICH,
    EC_WORD_QUES,
    EC_WORD_NORMAL,
    EC_WORD_DARK,
    EC_EMPTY_WORD
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
    EC_WORD_DARK
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
    ITEM_TM_HYPER_BEAM,
    ITEM_BIG_PEARL,
    ITEM_STAR_PIECE,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_PREMIER_BALL
};

// Favor Lady data
static const u8 *const sFavorLadyRequests[] =
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
    [CONTEST_CATEGORY_COOL]   = gText_ContestLady_Handsome,
    [CONTEST_CATEGORY_BEAUTY] = gText_ContestLady_Vinny,
    [CONTEST_CATEGORY_CUTE]   = gText_ContestLady_Moreme,
    [CONTEST_CATEGORY_SMART]  = gText_ContestLady_Ironhard,
    [CONTEST_CATEGORY_TOUGH]  = gText_ContestLady_Muscle
};

static const u8 *const sContestLadyCategoryNames[] =
{
    [CONTEST_CATEGORY_COOL]   = gText_ContestLady_Coolness,
    [CONTEST_CATEGORY_BEAUTY] = gText_ContestLady_Beauty,
    [CONTEST_CATEGORY_CUTE]   = gText_ContestLady_Cuteness,
    [CONTEST_CATEGORY_SMART]  = gText_ContestLady_Smartness,
    [CONTEST_CATEGORY_TOUGH]  = gText_ContestLady_Toughness
};

static const u8 *const sContestNames[] =
{
    [CONTEST_CATEGORY_COOL]   = gText_CoolnessContest,
    [CONTEST_CATEGORY_BEAUTY] = gText_BeautyContest,
    [CONTEST_CATEGORY_CUTE]   = gText_CutenessContest,
    [CONTEST_CATEGORY_SMART]  = gText_SmartnessContest,
    [CONTEST_CATEGORY_TOUGH]  = gText_ToughnessContest
};

static const u16 sContestLadyMonSpecies[] =
{
    [CONTEST_CATEGORY_COOL]   = SPECIES_ZIGZAGOON,
    [CONTEST_CATEGORY_BEAUTY] = SPECIES_SKITTY,
    [CONTEST_CATEGORY_CUTE]   = SPECIES_POOCHYENA,
    [CONTEST_CATEGORY_SMART]  = SPECIES_KECLEON,
    [CONTEST_CATEGORY_TOUGH]  = SPECIES_PIKACHU
};

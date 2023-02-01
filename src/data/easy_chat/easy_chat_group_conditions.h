const u8 gEasyChatWord_Hot[] = _("HOT");
const u8 gEasyChatWord_Exists[] = _("EXISTS");
const u8 gEasyChatWord_Excess[] = _("EXCESS");
const u8 gEasyChatWord_Approved[] = _("APPROVED");
const u8 gEasyChatWord_Has[] = _("HAS");
const u8 gEasyChatWord_Good[] = _("GOOD");
const u8 gEasyChatWord_Less[] = _("LESS");
const u8 gEasyChatWord_Momentum[] = _("MOMENTUM");
const u8 gEasyChatWord_Going[] = _("GOING");
const u8 gEasyChatWord_Weird[] = _("WEIRD");
const u8 gEasyChatWord_Busy[] = _("BUSY");
const u8 gEasyChatWord_Together[] = _("TOGETHER");
const u8 gEasyChatWord_Full[] = _("FULL");
const u8 gEasyChatWord_Absent[] = _("ABSENT");
const u8 gEasyChatWord_Being[] = _("BEING");
const u8 gEasyChatWord_Need[] = _("NEED");
const u8 gEasyChatWord_Tasty[] = _("TASTY");
const u8 gEasyChatWord_Skilled[] = _("SKILLED");
const u8 gEasyChatWord_Noisy[] = _("NOISY");
const u8 gEasyChatWord_Big[] = _("BIG");
const u8 gEasyChatWord_Late[] = _("LATE");
const u8 gEasyChatWord_Close[] = _("CLOSE");
const u8 gEasyChatWord_Docile[] = _("DOCILE");
const u8 gEasyChatWord_Amusing[] = _("AMUSING");
const u8 gEasyChatWord_Entertaining[] = _("ENTERTAINING");
const u8 gEasyChatWord_Perfection[] = _("PERFECTION");
const u8 gEasyChatWord_Pretty[] = _("PRETTY");
const u8 gEasyChatWord_Healthy[] = _("HEALTHY");
const u8 gEasyChatWord_Excellent[] = _("EXCELLENT");
const u8 gEasyChatWord_UpsideDown[] = _("UPSIDE DOWN");
const u8 gEasyChatWord_Cold[] = _("COLD");
const u8 gEasyChatWord_Refreshing[] = _("REFRESHING");
const u8 gEasyChatWord_Unavoidable[] = _("UNAVOIDABLE");
const u8 gEasyChatWord_Much[] = _("MUCH");
const u8 gEasyChatWord_Overwhelming[] = _("OVERWHELMING");
const u8 gEasyChatWord_Fabulous[] = _("FABULOUS");
const u8 gEasyChatWord_Else[] = _("ELSE");
const u8 gEasyChatWord_Expensive[] = _("EXPENSIVE");
const u8 gEasyChatWord_Correct[] = _("CORRECT");
const u8 gEasyChatWord_Impossible[] = _("IMPOSSIBLE");
const u8 gEasyChatWord_Small[] = _("SMALL");
const u8 gEasyChatWord_Different[] = _("DIFFERENT");
const u8 gEasyChatWord_Tired[] = _("TIRED");
const u8 gEasyChatWord_Skill[] = _("SKILL");
const u8 gEasyChatWord_Top[] = _("TOP");
const u8 gEasyChatWord_NonStop[] = _("NON-STOP");
const u8 gEasyChatWord_Preposterous[] = _("PREPOSTEROUS");
const u8 gEasyChatWord_None[] = _("NONE");
const u8 gEasyChatWord_Nothing[] = _("NOTHING");
const u8 gEasyChatWord_Natural[] = _("NATURAL");
const u8 gEasyChatWord_Becomes[] = _("BECOMES");
const u8 gEasyChatWord_Lukewarm[] = _("LUKEWARM");
const u8 gEasyChatWord_Fast[] = _("FAST");
const u8 gEasyChatWord_Low[] = _("LOW");
const u8 gEasyChatWord_Awful[] = _("AWFUL");
const u8 gEasyChatWord_Alone[] = _("ALONE");
const u8 gEasyChatWord_Bored[] = _("BORED");
const u8 gEasyChatWord_Secret[] = _("SECRET");
const u8 gEasyChatWord_Mystery[] = _("MYSTERY");
const u8 gEasyChatWord_Lacks[] = _("LACKS");
const u8 gEasyChatWord_Best[] = _("BEST");
const u8 gEasyChatWord_Lousy[] = _("LOUSY");
const u8 gEasyChatWord_Mistake[] = _("MISTAKE");
const u8 gEasyChatWord_Kind[] = _("KIND");
const u8 gEasyChatWord_Well[] = _("WELL");
const u8 gEasyChatWord_Weakened[] = _("WEAKENED");
const u8 gEasyChatWord_Simple[] = _("SIMPLE");
const u8 gEasyChatWord_Seems[] = _("SEEMS");
const u8 gEasyChatWord_Badly[] = _("BADLY");

const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
        .text = gEasyChatWord_Hot,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
        .text = gEasyChatWord_Exists,
        .alphabeticalOrder = 55,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
        .text = gEasyChatWord_Excess,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
        .text = gEasyChatWord_Approved,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
        .text = gEasyChatWord_Has,
        .alphabeticalOrder = 54,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
        .text = gEasyChatWord_Good,
        .alphabeticalOrder = 68,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
        .text = gEasyChatWord_Less,
        .alphabeticalOrder = 50,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
        .text = gEasyChatWord_Momentum,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
        .text = gEasyChatWord_Going,
        .alphabeticalOrder = 60,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
        .text = gEasyChatWord_Weird,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
        .text = gEasyChatWord_Busy,
        .alphabeticalOrder = 56,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
        .text = gEasyChatWord_Together,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
        .text = gEasyChatWord_Full,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
        .text = gEasyChatWord_Absent,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
        .text = gEasyChatWord_Being,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
        .text = gEasyChatWord_Need,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
        .text = gEasyChatWord_Tasty,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
        .text = gEasyChatWord_Skilled,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
        .text = gEasyChatWord_Noisy,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
        .text = gEasyChatWord_Big,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
        .text = gEasyChatWord_Late,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
        .text = gEasyChatWord_Close,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
        .text = gEasyChatWord_Docile,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
        .text = gEasyChatWord_Amusing,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
        .text = gEasyChatWord_Entertaining,
        .alphabeticalOrder = 52,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
        .text = gEasyChatWord_Perfection,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
        .text = gEasyChatWord_Pretty,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
        .text = gEasyChatWord_Healthy,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
        .text = gEasyChatWord_Excellent,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
        .text = gEasyChatWord_UpsideDown,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
        .text = gEasyChatWord_Cold,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
        .text = gEasyChatWord_Refreshing,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
        .text = gEasyChatWord_Unavoidable,
        .alphabeticalOrder = 63,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
        .text = gEasyChatWord_Much,
        .alphabeticalOrder = 59,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
        .text = gEasyChatWord_Overwhelming,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
        .text = gEasyChatWord_Fabulous,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
        .text = gEasyChatWord_Else,
        .alphabeticalOrder = 61,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
        .text = gEasyChatWord_Expensive,
        .alphabeticalOrder = 53,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
        .text = gEasyChatWord_Correct,
        .alphabeticalOrder = 51,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
        .text = gEasyChatWord_Impossible,
        .alphabeticalOrder = 62,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
        .text = gEasyChatWord_Small,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
        .text = gEasyChatWord_Different,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
        .text = gEasyChatWord_Tired,
        .alphabeticalOrder = 58,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
        .text = gEasyChatWord_Skill,
        .alphabeticalOrder = 49,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
        .text = gEasyChatWord_Top,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
        .text = gEasyChatWord_NonStop,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
        .text = gEasyChatWord_Preposterous,
        .alphabeticalOrder = 45,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
        .text = gEasyChatWord_None,
        .alphabeticalOrder = 47,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
        .text = gEasyChatWord_Nothing,
        .alphabeticalOrder = 48,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
        .text = gEasyChatWord_Natural,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
        .text = gEasyChatWord_Becomes,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
        .text = gEasyChatWord_Lukewarm,
        .alphabeticalOrder = 46,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
        .text = gEasyChatWord_Fast,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
        .text = gEasyChatWord_Low,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
        .text = gEasyChatWord_Awful,
        .alphabeticalOrder = 57,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
        .text = gEasyChatWord_Alone,
        .alphabeticalOrder = 67,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
        .text = gEasyChatWord_Bored,
        .alphabeticalOrder = 66,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
        .text = gEasyChatWord_Secret,
        .alphabeticalOrder = 43,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
        .text = gEasyChatWord_Mystery,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
        .text = gEasyChatWord_Lacks,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
        .text = gEasyChatWord_Best,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
        .text = gEasyChatWord_Lousy,
        .alphabeticalOrder = 42,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
        .text = gEasyChatWord_Mistake,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
        .text = gEasyChatWord_Kind,
        .alphabeticalOrder = 44,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
        .text = gEasyChatWord_Well,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
        .text = gEasyChatWord_Weakened,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
        .text = gEasyChatWord_Simple,
        .alphabeticalOrder = 65,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
        .text = gEasyChatWord_Seems,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
        .text = gEasyChatWord_Badly,
        .alphabeticalOrder = 64,
        .enabled = TRUE,
    },
};

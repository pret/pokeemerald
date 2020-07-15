#ifndef GUARD_CONTEST_H
#define GUARD_CONTEST_H

#include "palette.h"
#include "constants/contest.h"

enum
{
    CONTEST_DEBUG_MODE_OFF,
    // Prints the totalPoints value for each contestant.
    CONTEST_DEBUG_MODE_PRINT_POINT_TOTAL,
    // Prints the ContestResourcesField1C::unk_C value as a bitstring for each contestant.
    CONTEST_DEBUG_MODE_PRINT_UNK_C,
    // Prints the ContestResourcesField1C::unk_D value as a bitstring for each contestant.
    CONTEST_DEBUG_MODE_PRINT_UNK_D
};

enum
{
    CONTEST_EFFECT_HIGHLY_APPEALING,
    CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
    CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
    CONTEST_EFFECT_REPETITION_NOT_BORING,
    CONTEST_EFFECT_AVOID_STARTLE_ONCE,
    CONTEST_EFFECT_AVOID_STARTLE,
    CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY,
    CONTEST_EFFECT_USER_LESS_EASILY_STARTLED,
    CONTEST_EFFECT_STARTLE_FRONT_MON,
    CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS,
    CONTEST_EFFECT_STARTLE_PREV_MON,
    CONTEST_EFFECT_STARTLE_PREV_MONS,
    CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
    CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
    CONTEST_EFFECT_STARTLE_PREV_MON_2,
    CONTEST_EFFECT_STARTLE_PREV_MONS_2,
    CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
    CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
    CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
    CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
    CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL,
    CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL,
    CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL,
    CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL,
    CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL,
    CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS,
    CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
    CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
    CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION,
    CONTEST_EFFECT_BETTER_IF_FIRST,
    CONTEST_EFFECT_BETTER_IF_LAST,
    CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
    CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
    CONTEST_EFFECT_BETTER_WHEN_LATER,
    CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
    CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
    CONTEST_EFFECT_BETTER_IF_DIFF_TYPE,
    CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
    CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
    CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
    CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
    CONTEST_EFFECT_NEXT_APPEAL_LATER,
    CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER,
    CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
    CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
    CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
    CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
    CONTEST_EFFECT_DONT_EXCITE_AUDIENCE
};

enum
{
    COMBO_STARTER_RAIN_DANCE = 1,
    COMBO_STARTER_RAGE,
    COMBO_STARTER_FOCUS_ENERGY,
    COMBO_STARTER_HYPNOSIS,
    COMBO_STARTER_ENDURE,
    COMBO_STARTER_HORN_ATTACK,
    COMBO_STARTER_SWORDS_DANCE,
    COMBO_STARTER_STOCKPILE,
    COMBO_STARTER_SUNNY_DAY,
    COMBO_STARTER_REST,
    COMBO_STARTER_VICE_GRIP,
    COMBO_STARTER_DEFENSE_CURL,
    COMBO_STARTER_CHARGE,
    COMBO_STARTER_ROCK_THROW,
    COMBO_STARTER_YAWN,
    COMBO_STARTER_SCARY_FACE,
    COMBO_STARTER_POWDER_SNOW,
    COMBO_STARTER_LOCK_ON,
    COMBO_STARTER_SOFT_BOILED,
    COMBO_STARTER_MEAN_LOOK,
    COMBO_STARTER_SCRATCH,
    COMBO_STARTER_GROWTH,
    COMBO_STARTER_HAIL,
    COMBO_STARTER_SANDSTORM,
    COMBO_STARTER_BELLY_DRUM,
    COMBO_STARTER_MIND_READER,
    COMBO_STARTER_DRAGON_BREATH,
    COMBO_STARTER_DRAGON_RAGE,
    COMBO_STARTER_DRAGON_DANCE,
    COMBO_STARTER_SURF,
    COMBO_STARTER_DIVE,
    COMBO_STARTER_STRING_SHOT,
    COMBO_STARTER_LEER,
    COMBO_STARTER_TAUNT,
    COMBO_STARTER_CHARM,
    COMBO_STARTER_HARDEN,
    COMBO_STARTER_SING,
    COMBO_STARTER_EARTHQUAKE,
    COMBO_STARTER_DOUBLE_TEAM,
    COMBO_STARTER_CURSE,
    COMBO_STARTER_SWEET_SCENT,
    COMBO_STARTER_SLUDGE,
    COMBO_STARTER_SLUDGE_BOMB,
    COMBO_STARTER_THUNDER_PUNCH,
    COMBO_STARTER_FIRE_PUNCH,
    COMBO_STARTER_ICE_PUNCH,
    COMBO_STARTER_PECK,
    COMBO_STARTER_METAL_SOUND,
    COMBO_STARTER_MUD_SPORT,
    COMBO_STARTER_WATER_SPORT,
    COMBO_STARTER_BONE_CLUB,
    COMBO_STARTER_BONEMERANG,
    COMBO_STARTER_BONE_RUSH,
    COMBO_STARTER_SAND_ATTACK,
    COMBO_STARTER_MUD_SLAP,
    COMBO_STARTER_FAKE_OUT,
    COMBO_STARTER_PSYCHIC,
    COMBO_STARTER_KINESIS,
    COMBO_STARTER_CONFUSION,
    COMBO_STARTER_POUND,
    COMBO_STARTER_SMOG,
    COMBO_STARTER_CALM_MIND
};

enum
{
    CONTEST_STRING_MORE_CONSCIOUS,
    CONTEST_STRING_NO_APPEAL,
    CONTEST_STRING_SETTLE_DOWN,
    CONTEST_STRING_OBLIVIOUS_TO_OTHERS,
    CONTEST_STRING_LESS_AWARE,
    CONTEST_STRING_STOPPED_CARING,
    CONTEST_STRING_STARTLE_ATTEMPT,
    CONTEST_STRING_DAZZLE_ATTEMPT,
    CONTEST_STRING_JUDGE_LOOK_AWAY2,
    CONTEST_STRING_UNNERVE_ATTEMPT,
    CONTEST_STRING_NERVOUS,
    CONTEST_STRING_UNNERVE_WAITING,
    CONTEST_STRING_TAUNT_WELL,
    CONTEST_STRING_REGAINED_FORM,
    CONTEST_STRING_JAM_WELL,
    CONTEST_STRING_HUSTLE_STANDOUT,
    CONTEST_STRING_WORK_HARD_UNNOTICED,
    CONTEST_STRING_WORK_BEFORE,
    CONTEST_STRING_APPEAL_NOT_WELL,
    CONTEST_STRING_WORK_PRECEDING,
    CONTEST_STRING_APPEAL_NOT_WELL2,
    CONTEST_STRING_APPEAL_NOT_SHOWN_WELL,
    CONTEST_STRING_APPEAL_SLIGHTLY_WELL,
    CONTEST_STRING_APPEAL_PRETTY_WELL,
    CONTEST_STRING_APPEAL_EXCELLENTLY,
    CONTEST_STRING_APPEAL_DUD,
    CONTEST_STRING_APPEAL_NOT_VERY_WELL,
    CONTEST_STRING_APPEAL_SLIGHTLY_WELL2,
    CONTEST_STRING_APPEAL_PRETTY_WELL2,
    CONTEST_STRING_APPEAL_VERY_WELL,
    CONTEST_STRING_APPEAL_EXCELLENTLY2,
    CONTEST_STRING_SAME_TYPE_GOOD,
    CONTEST_STRING_DIFF_TYPE_GOOD,
    CONTEST_STRING_STOOD_OUT_AS_MUCH,
    CONTEST_STRING_NOT_AS_WELL,
    CONTEST_STRING_CONDITION_ROSE,
    CONTEST_STRING_HOT_STATUS,
    CONTEST_STRING_MOVE_UP_LINE,
    CONTEST_STRING_MOVE_BACK_LINE,
    CONTEST_STRING_SCRAMBLE_ORDER,
    CONTEST_STRING_JUDGE_EXPECTANTLY2,
    CONTEST_STRING_WENT_OVER_WELL,
    CONTEST_STRING_WENT_OVER_VERY_WELL,
    CONTEST_STRING_APPEAL_COMBO_EXCELLENTLY,
    CONTEST_STRING_AVERT_GAZE,
    CONTEST_STRING_AVOID_SEEING,
    CONTEST_STRING_NOT_FAZED,
    CONTEST_STRING_LITTLE_DISTRACTED,
    CONTEST_STRING_ATTEMPT_STARTLE,
    CONTEST_STRING_LOOKED_DOWN,
    CONTEST_STRING_TURNED_BACK,
    CONTEST_STRING_UTTER_CRY,
    CONTEST_STRING_LEAPT_UP,
    CONTEST_STRING_TRIPPED_OVER,
    CONTEST_STRING_MESSED_UP2,
    CONTEST_STRING_FAILED_TARGET_NERVOUS,
    CONTEST_STRING_FAILED_ANYONE_NERVOUS,
    CONTEST_STRING_IGNORED,
    CONTEST_STRING_NO_CONDITION_IMPROVE,
    CONTEST_STRING_BAD_CONDITION_WEAK_APPEAL,
    CONTEST_STRING_UNAFFECTED,
    CONTEST_STRING_ATTRACTED_ATTENTION,
    CONTEST_STRING_NONE = 255
};

enum {
    CONTEST_FILTER_NONE,
    CONTEST_FILTER_NO_POSTGAME,
    CONTEST_FILTER_ONLY_POSTGAME
};

struct ContestPokemon
{
    /*0x00*/ u16 species;
    /*0x02*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0D*/ u8 trainerName[PLAYER_NAME_LENGTH + 1];
    /*0x15*/ u8 trainerGfxId;
    /*0x18*/ u32 aiChecks;
    /*0x1C*/ u8 whichRank:2; // 0x1 0x2
    u8 aiPool_Cool:1; // 0x4
    u8 aiPool_Beauty:1; // 0x8
    u8 aiPool_Cute:1; // 0x10
    u8 aiPool_Smart:1; // 0x20
    u8 aiPool_Tough:1; // 0x40
    /*0x1E*/ u16 moves[MAX_MON_MOVES]; // moves
    /*0x26*/ u8 cool; // cool
    /*0x27*/ u8 beauty; // beauty
    /*0x28*/ u8 cute; // cute
    /*0x29*/ u8 smart; // smart
    /*0x2A*/ u8 tough; // tough
    /*0x2B*/ u8 sheen; // sheen
    /*0x2C*/ u8 unk2C[12];
    /*0x38*/ u32 personality;  // personality
    /*0x3C*/ u32 otId;  // otId
};

struct Shared1A004
{
    u16 cachedWindowPalettes[16][16]; // Saved palette data before a move happens?
    u16 unk18204[PLTT_BUFFER_SIZE];     // Saved copy of gPlttBufferUnfaded
    u16 unk18604[PLTT_BUFFER_SIZE];     // Saved copy of gPlttBufferFaded
    u8 savedJunk[0x800];
};

struct ContestStruct_field_18
{
    u16 species;
    u16 unk2;
    u8 unk4_0:1;
    u8 unk5;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

struct Contest
{
    /*0x0*/ u8 playerMoveChoice;
    /*0x1*/ u8 turnNumber;
    /*0x2*/ u8 unused2[CONTESTANT_COUNT];
    /*0x6*/ u16 unk1920A_0:1;  // Task active flags?
    u16 unk1920A_1:1;
    u16 unk1920A_2:1;
    u16 unk1920A_3:1;
    u16 unk1920A_4:1;
    u16 isShowingApplauseMeter:1;
    u16 applauseMeterIsMoving:1;
    u16 unk1920A_7:1;
    /*0x7*/ u16 unk1920B_0:1;
    u16 unk1920B_1:1;
    u16 unk1920B_2:1;
    /*0x8*/ u8 mainTaskId;
    /*0x9*/ u8 unk1920D[4];
    /*0xD*/ u8 unk19211;
    /*0xE*/ u8 unk19212;
    /*0xF*/ u8 filler19213;
    /*0x10*/ u8 unk19214;
    /*0x11*/ u8 unk19215;
    /*0x12*/ u8 unk19216;    // sprite ID
    /*0x13*/ s8 applauseLevel;
    /*0x19218*/ u8 prevTurnOrder[CONTESTANT_COUNT];
    /*0x1921C*/ u32 unk1921C;   // saved RNG value?
    u16 moveHistory[CONTEST_TURN_COUNT][CONTESTANT_COUNT];
    u8 excitementHistory[CONTEST_TURN_COUNT][CONTESTANT_COUNT];
    u8 applauseMeterSpriteId;
    /*0x1925D*/ u8 contestSetupState;
    /*0x1925E*/ u8 unk1925E;
};

struct ContestantStatus
{
    /*0x00*/ s16 appeal1;  // move appeal?
    /*0x02*/ s16 appeal2;  // final appeal after end of turn, maybe?
    /*0x04*/ s16 pointTotal;
    /*0x06*/ u16 currMove;
    /*0x08*/ u16 prevMove;
    /*0x0A*/ u8 moveCategory;
    /*0x0B*/ u8 ranking:2;
    u8 unkB_2:2;
    u8 moveRepeatCount:3;
    u8 noMoreTurns:1;  // used a one-time move?
    /*0x0C*/ u8 nervous:1;
    u8 numTurnsSkipped:2;
    /*0x0D*/ s8 condition;
    /*0x0E*/ u8 jam;
    /*0x0F*/ u8 jamReduction;

    // Flags set by move effect
    /*0x10*/ u8 resistant:1;
    u8 immune:1;
    u8 moreEasilyStartled:1;
    u8 usedRepeatableMove:1;
    u8 conditionMod:2; // 1: just raised condition; 2: appeal greatly improved by condition
    u8 turnOrderMod:2; // 1: defined; 2: random
    /*0x11*/ u8 turnOrderModAction:2; // 1: made first; 2: made last; 3: made random
    u8 turnSkipped:1;
    u8 exploded:1;
    u8 overrideCategoryExcitementMod:1;
    u8 appealTripleCondition:1;

    /*0x12*/ u8 jamSafetyCount;
    /*0x13*/ u8 effectStringId;   // status action?
    /*0x14*/ u8 effectStringId2;
    /*0x15*/ u8 disappointedRepeat:1;
    u8 unk15_1:1;
    u8 unk15_2:1;
    u8 unk15_3:1;
    u8 hasJudgesAttention:1;
    u8 judgesAttentionWasRemoved:1;
    u8 unk15_6:1;
    /*0x16*/ u8 unk16;
    /*0x17*/ u8 unk17;
    /*0x18*/ u8 unk18;
    /*0x19*/ u8 nextTurnOrder;  // turn position
    /*0x1A*/ u8 attentionLevel;  // How much the Pokemon "stood out"
    /*0x1B*/ u8 unk1B;
};

struct UnknownContestStruct7
{
    u8 turnOrder[CONTESTANT_COUNT];
    s16 jam;
    s16 jam2;
    u8 jamQueue[5];
    u8 unnervedPokes[CONTESTANT_COUNT];
    u8 contestant;
};

struct ContestAIInfo
{
    /*0x00*/ u8 aiState;
    /*0x02*/ u16 nextMove;
    /*0x04*/ u8 nextMoveIndex;
    /*0x05*/ u8 unk5[4];
    /*0x09*/ u8 aiAction;
    /*0x0A*/ u8 fillerA[0x6]; // TODO: don't know what's here
    /*0x10*/ u8 currentAICheck;
    /*0x14*/ u32 aiChecks;
    /*0x18*/ s16 scriptResult;
    /*0x1A*/ s16 scriptArr[3];
    /*0x20*/ const u8 *stack[8];
    /*0x40*/ u8 stackSize;
    /*0x41*/ u8 contestantId;
};

struct UnknownContestStruct5
{
    s8 bits_0;  // current move excitement?
    u8 excitementFrozen:1;
    u8 excitementFreezer:3;
    s8 unk2;
};

struct UnknownContestStruct4
{
    u8 unk0;  // sprite ID
    u8 unk1;  // sprite ID
    u8 unk2_0:1;
    u8 unk2_1:1;
    u8 unk2_2:1;
};

struct UnknownContestStruct6
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct ContestResourcesField1C
{
    u16 unk0[5];
    s16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE_1:1;
    u8 unkE_2:1;
};

struct ContestResourcesField20
{
    u8 filler_00[0x0C];
};

struct ContestResources
{
    struct Contest *contest;
    struct ContestantStatus *status;
    struct UnknownContestStruct7 *field_8;
    struct ContestAIInfo *aiData;
    struct UnknownContestStruct5 *field_10;
    struct UnknownContestStruct4 *field_14;
    struct ContestStruct_field_18 *field_18;
    struct ContestResourcesField1C * field_1c;
    struct ContestResourcesField20 * field_20;
    u8 * contestBgTilemaps[CONTESTANT_COUNT];
    void * field_34;
    void * field_38;
    void * field_3c;
};

#define eContest (*gContestResources->contest)
#define eContestantStatus (gContestResources->status)
#define eContestResources8 (*gContestResources->field_8)
#define eContestAI (*gContestResources->aiData)
#define eContestResources10 (*gContestResources->field_10)
#define eContestResources14 (*gContestResources->field_14)
#define eUnzippedContestAudienceGfx (gHeap + 0x18000)
#define eUnknownHeap19000 (gHeap + 0x19000)
#define eContestDebugMode (gHeap[0x1a000])
#define eUnknownHeap1A004 (*(struct Shared1A004 *)(gHeap + 0x1a004))

extern struct ContestPokemon gContestMons[CONTESTANT_COUNT];
extern s16 gContestMonConditions[CONTESTANT_COUNT];
extern s16 gContestMonTotalPoints[CONTESTANT_COUNT];
extern s16 gUnknown_02039F10[CONTESTANT_COUNT];
extern s16 gContestMonRound2Points[CONTESTANT_COUNT];
extern u8 gContestFinalStandings[CONTESTANT_COUNT];
extern u8 gContestMonPartyIndex;
extern u8 gContestPlayerMonIndex;
extern u8 gContestantTurnOrder[CONTESTANT_COUNT];
extern u8 gLinkContestFlags;
extern u8 gUnknown_02039F2B;
extern u16 gSpecialVar_ContestCategory;
extern u16 gSpecialVar_ContestRank;
extern u8 gNumLinkContestPlayers;
extern u8 gHighestRibbonRank;
extern struct ContestResources *gContestResources;
extern u8 sContestBgCopyFlags;
extern struct ContestWinner gCurContestWinner;
extern u8 gUnknown_02039F5C;
extern u8 gUnknown_02039F5D;
extern u32 gContestRngValue;

// contest.c
void ResetLinkContestBoolean(void);
void LoadContestBgAfterMoveAnim(void);
void CB2_StartContest(void);
void sub_80DA8C8(u8 partyIndex);
void sub_80DAB8C(u8 contestType, u8 rank);
void sub_80DACBC(u8 contestType, u8 rank, bool32 isPostgame);
u8 GetContestEntryEligibility(struct Pokemon *pkmn);
void sub_80DB09C(u8 contestCategory);
bool8 IsSpeciesNotUnown(u16 species);
bool8 Contest_IsMonsTurnDisabled(u8 a);
void SaveLinkContestResults(void);
void SortContestants(bool8 a);
void SetContestantEffectStringID(u8 a, u8 b);
void SetContestantEffectStringID2(u8 a, u8 b);
void SetStartledString(u8 contestant, u8 jam);
void MakeContestantNervous(u8 p);
s8 Contest_GetMoveExcitement(u16 move);
bool8 sub_80DE1E8(u8 a);
void Contest_PrintTextToBg0WindowAt(u32 windowId, u8 *currChar, s32 x, s32 y, s32 fontId);
void ResetContestLinkResults(void);
bool8 sub_80DEDA8(u8 a);
u8 sub_80DEFA8(u8 a, u8 b);
void ClearContestWinnerPicsInContestHall(void);
void sub_80DFA08(struct ContestPokemon *mon, s32 language);

// contest link
void sub_81D9DE4(u8 taskId);
void sub_80FCF40(u8);
void sub_80FCFD0(u8);
void sub_80F8714(u8);
bool32 sub_80FC670(s16 *);
bool32 sub_80FC4F4(void *, u16);
bool8 sub_80FC55C(void);
bool8 sub_80FC530(u8);
u8 sub_80F86E0(u8 *);
void sub_80FC9F8(u8 taskId);

#endif //GUARD_CONTEST_H

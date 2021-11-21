#ifndef GUARD_CONTEST_H
#define GUARD_CONTEST_H

#include "palette.h"
#include "constants/contest.h"

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

// Constants for changing in-contest Condition (the stars that appear during appeals)
enum {
    CONDITION_NO_CHANGE,
    CONDITION_GAIN,
    CONDITION_LOSE,
};

struct ContestPokemon
{
    u16 species;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u8 trainerGfxId;
    u32 aiFlags;
    u8 whichRank:2;
    u8 aiPool_Cool:1;
    u8 aiPool_Beauty:1;
    u8 aiPool_Cute:1;
    u8 aiPool_Smart:1;
    u8 aiPool_Tough:1;
    u16 moves[MAX_MON_MOVES];
    u8 cool;
    u8 beauty;
    u8 cute;
    u8 smart;
    u8 tough;
    u8 sheen;
    u8 highestRank;
    bool8 gameCleared;
    u8 unused[10];
    u32 personality;
    u32 otId;
};

struct ContestTempSave
{
    u16 cachedWindowPalettes[16][16]; // Saved palette data before a move happens?
    u16 cachedPlttBufferUnfaded[PLTT_BUFFER_SIZE];
    u16 cachedPlttBufferFaded[PLTT_BUFFER_SIZE];
    u8 savedJunk[0x800];
};

struct ContestMoveAnimData
{
    u16 species;
    u16 targetSpecies;
    bool8 hasTargetAnim:1;
    u8 contestant;
    u32 personality;
    u32 otId;
    u32 targetPersonality;
};

struct Contest
{
    u8 playerMoveChoice;
    u8 appealNumber;
    u8 unk[CONTESTANT_COUNT]; // never read
    bool16 unused1:1;
    bool16 unused2:1;
    bool16 unused3:1;
    bool16 unused4:1;
    bool16 waitForJudgeSpeechBubble:1;
    bool16 isShowingApplauseMeter:1;
    bool16 applauseMeterIsMoving:1;
    bool16 animatingAudience:1;
    bool16 waitForAudienceBlend:1;
    bool16 sliderHeartsAnimating:1; // When the slider heart is appearing/disappearing
    bool16 waitForLink:1;
    u8 mainTaskId;
    u8 filler1[4];
    u8 judgeAttentionTaskId;
    u8 blendTaskId;
    u8 filler2;
    u8 turnNumber;
    u8 currentContestant;
    u8 judgeSpeechBubbleSpriteId;
    s8 applauseLevel;
    u8 prevTurnOrder[CONTESTANT_COUNT];
    u32 unusedRng;
    u16 moveHistory[CONTEST_NUM_APPEALS][CONTESTANT_COUNT];
    u8 excitementHistory[CONTEST_NUM_APPEALS][CONTESTANT_COUNT];
    u8 applauseMeterSpriteId;
    u8 contestSetupState;
    u8 moveAnimTurnCount;
};

struct ContestantStatus
{
    s16 baseAppeal;
    s16 appeal;
    s16 pointTotal;
    u16 currMove;
    u16 prevMove;
    u8 moveCategory;
    u8 ranking:2;
    u8 unused1:2;
    u8 moveRepeatCount:3;
    bool8 noMoreTurns:1;  // used a one-time move?
    bool8 nervous:1;
    u8 numTurnsSkipped:2;
    s8 condition;
    u8 jam;
    u8 jamReduction;

    // Flags set by move effect
    bool8 resistant:1;
    bool8 immune:1;
    bool8 moreEasilyStartled:1;
    bool8 usedRepeatableMove:1;
    u8 conditionMod:2; // 1: just raised condition; 2: appeal greatly improved by condition
    u8 turnOrderMod:2; // 1: defined; 2: random
    u8 turnOrderModAction:2; // 1: made first; 2: made last; 3: made random
    bool8 turnSkipped:1;
    bool8 exploded:1;
    bool8 overrideCategoryExcitementMod:1;
    bool8 appealTripleCondition:1;

    u8 jamSafetyCount;
    u8 effectStringId;   // status action?
    u8 effectStringId2;
    bool8 repeatedMove:1;
    bool8 unused2:1;
    bool8 repeatedPrevMove:1; // never read
    bool8 completedComboFlag:1;
    bool8 hasJudgesAttention:1;
    bool8 judgesAttentionWasRemoved:1;
    bool8 usedComboMove:1;
    bool8 completedCombo;
    u8 comboAppealBonus;
    u8 repeatJam;
    u8 nextTurnOrder;  // turn position
    u8 attentionLevel;  // How much the Pokemon "stood out"
    u8 contestantAnimTarget;
};

struct ContestAppealMoveResults
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
    /*0x05*/ u8 moveScores[MAX_MON_MOVES];
    /*0x09*/ u8 aiAction;
    /*0x0A*/ u8 filler[6];
    /*0x10*/ u8 currentAIFlag;
    /*0x14*/ u32 aiFlags;
    /*0x18*/ s16 scriptResult;
    /*0x1A*/ s16 vars[3];
    /*0x20*/ const u8 *stack[8];
    /*0x40*/ u8 stackSize;
    /*0x41*/ u8 contestantId;
};

struct ContestExcitement
{
    s8 moveExcitement;
    u8 frozen:1;
    u8 freezer:3;
    s8 excitementAppealBonus;
};

struct ContestGraphicsState
{
    u8 sliderHeartSpriteId;
    u8 nextTurnSpriteId;
    bool8 sliderUpdating:1;
    bool8 boxBlinking:1;
    bool8 updatingAppealHearts:1;
};

struct ContestFinalStandings
{
    s32 totalPoints;
    s32 round1Points;
    s32 random;
    s32 contestant;
};

struct ContestTV
{
    u16 appeals[CONTEST_NUM_APPEALS];
    s16 move;
    u8 winnerFlags;
    u8 loserFlags;
    bool8 madeAppeal:1;
    bool8 madeExcitingAppeal:1;
};

struct ContestUnused
{
    u8 filler[12];
};

struct ContestResources
{
    struct Contest *contest;
    struct ContestantStatus *status;
    struct ContestAppealMoveResults *appealResults;
    struct ContestAIInfo *aiData;
    struct ContestExcitement *excitement;
    struct ContestGraphicsState *gfxState;
    struct ContestMoveAnimData *moveAnim;
    struct ContestTV *tv;
    struct ContestUnused * unused;
    u8 * contestBgTilemaps[CONTESTANT_COUNT];
    void * boxBlinkTiles1;
    void * boxBlinkTiles2;
    void * animBgTileBuffer;
};

#define eContest (*gContestResources->contest)
#define eContestantStatus (gContestResources->status)
#define eContestAppealResults (*gContestResources->appealResults)
#define eContestAI (*gContestResources->aiData)
#define eContestExcitement (*gContestResources->excitement)
#define eContestGfxState (gContestResources->gfxState)
#define eUnzippedContestAudience_Gfx (gHeap + 0x18000)
#define eContestAudienceFrame2_Gfx (gHeap + 0x19000)
#define eContestDebugMode (gHeap[0x1a000])
#define eContestTempSave (*(struct ContestTempSave *)(gHeap + 0x1a004))

extern struct ContestPokemon gContestMons[CONTESTANT_COUNT];
extern s16 gContestMonRound1Points[CONTESTANT_COUNT];
extern s16 gContestMonTotalPoints[CONTESTANT_COUNT];
extern s16 gContestMonAppealPointTotals[CONTESTANT_COUNT];
extern s16 gContestMonRound2Points[CONTESTANT_COUNT];
extern u8 gContestFinalStandings[CONTESTANT_COUNT];
extern u8 gContestMonPartyIndex;
extern u8 gContestPlayerMonIndex;
extern u8 gContestantTurnOrder[CONTESTANT_COUNT];
extern u8 gLinkContestFlags;
extern u8 gContestLinkLeaderIndex;
extern u16 gSpecialVar_ContestCategory;
extern u16 gSpecialVar_ContestRank;
extern u8 gNumLinkContestPlayers;
extern u8 gHighestRibbonRank;
extern struct ContestResources *gContestResources;
extern u8 sContestBgCopyFlags;
extern struct ContestWinner gCurContestWinner;
extern u8 gCurContestWinnerIsForArtist;
extern u8 gCurContestWinnerSaveIdx;
extern u32 gContestRngValue;

// contest.c
void ResetLinkContestBoolean(void);
void LoadContestBgAfterMoveAnim(void);
void CB2_StartContest(void);
void CreateContestMonFromParty(u8 partyIndex);
void SetContestants(u8 contestType, u8 rank);
void SetLinkAIContestants(u8 contestType, u8 rank, bool32 isPostgame);
u8 GetContestEntryEligibility(struct Pokemon *pkmn);
void CalculateRound1Points(u8 contestCategory);
bool8 IsSpeciesNotUnown(u16 species);
bool8 Contest_IsMonsTurnDisabled(u8 a);
void SaveLinkContestResults(void);
void SortContestants(bool8 a);
void SetContestantEffectStringID(u8 a, u8 b);
void SetContestantEffectStringID2(u8 a, u8 b);
void SetStartledString(u8 contestant, u8 jam);
void MakeContestantNervous(u8 p);
s8 Contest_GetMoveExcitement(u16 move);
bool8 IsContestantAllowedToCombo(u8 contestant);
void Contest_PrintTextToBg0WindowAt(u32 windowId, u8 *currChar, s32 x, s32 y, s32 fontId);
void ResetContestLinkResults(void);
bool8 SaveContestWinner(u8 rank);
u8 GetContestWinnerSaveIdx(u8 rank, bool8 shift);
void ClearContestWinnerPicsInContestHall(void);
void StripPlayerAndMonNamesForLinkContest(struct ContestPokemon *mon, s32 language);

#endif //GUARD_CONTEST_H

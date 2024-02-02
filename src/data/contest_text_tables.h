#include "global.h"

// sAppealResultTexts
extern const u8 gText_BecameMoreConsciousOfOtherMons[];
extern const u8 gText_MonCantMakeAnAppealAfterThis[];
extern const u8 gText_SettledDownJustLittleBit[];
extern const u8 gText_BecameObliviousToOtherMons[];
extern const u8 gText_BecameLessAwareOfOtherMons[];
extern const u8 gText_StoppedCaringAboutOtherMons[];
extern const u8 gText_TriedToStartleOtherMons[];
extern const u8 gText_TriedToDazzleOthers[];
extern const u8 gText_JudgeLookedAwayFromMon[];
extern const u8 gText_TriedToUnnerveNextMon[];
extern const u8 gText_MonBecameNervous[];
extern const u8 gText_AppealTriedToUnnerveWaitingMons[];
extern const u8 gText_TauntedMonsDoingWell[];
extern const u8 gText_MonRegainedItsForm[];
extern const u8 gText_TriedToJamMonDoingWell[];
extern const u8 gText_StandoutMonHustledEvenMore[];
extern const u8 gText_LargelyUnnoticedMonWorkedHard[];
extern const u8 gText_WorkedAsMuchAsMonBefore[];
extern const u8 gText_WorkedAsMuchAsPrecedingMon[];
extern const u8 gText_MonsAppealWasDud[];
extern const u8 gText_MonsAppealDidNotGoWell[];
extern const u8 gText_MonsAppealDidNotGoWell2[];
extern const u8 gText_MonsAppealDidNotGoWell3[];
extern const u8 gText_MonsAppealDidNotWorkVeryWell[];
extern const u8 gText_MonsAppealWentSlightlyWell[];
extern const u8 gText_MonsAppealWentSlightlyWell2[];
extern const u8 gText_MonsAppealWentPrettyWell[];
extern const u8 gText_MonsAppealWentPrettyWell2[];
extern const u8 gText_MonsAppealWentVeryWell[];
extern const u8 gText_MonsAppealWentExcellently[];
extern const u8 gText_MonsAppealWentExcellently2[];
extern const u8 gText_SameTypeAsOneBeforeGood[];
extern const u8 gText_NotSameTypeAsOneBeforeGood[];
extern const u8 gText_StoodOutMuchMoreThanMonBefore[];
extern const u8 gText_DidntDoAsWellAsMonBefore[];
extern const u8 gText_MonsConditionRoseAboveUsual[];
extern const u8 gText_MonsHotStatusMadeGreatAppeal[];
extern const u8 gText_MovedUpInLineForNextAppeal[];
extern const u8 gText_MovedBackInLineForNextAppeal[];
extern const u8 gText_ScrambledUpOrderForNextTurn[];
extern const u8 gText_JudgeLookedAtMonExpectantly[];
extern const u8 gText_AppealComboWentOverWell[];
extern const u8 gText_AppealComboWentOverVeryWell[];
extern const u8 gText_AppealComboWentOverExcellently[];
extern const u8 gText_MonManagedToAvertGaze[];
extern const u8 gText_MonManagedToAvoidSeeingIt[];
extern const u8 gText_MonIsntFazedByThatSortOfThing[];
extern const u8 gText_MonBecameALittleDistracted[];
extern const u8 gText_TriedToStartleOtherPokemon[];
extern const u8 gText_MonLookedDownOutOfDistraction[];
extern const u8 gText_MonTurnedBackOutOfDistraction[];
extern const u8 gText_MonCouldntHelpUtteringCry[];
extern const u8 gText_MonCouldntHelpLeapingUp[];
extern const u8 gText_MonTrippedOutOfDistraction[];
extern const u8 gText_ButItMessedUp2[];
extern const u8 gText_ButItFailedToMakeTargetNervous[];
extern const u8 gText_ButItFailedToMakeAnyoneNervous[];
extern const u8 gText_ButItWasIgnored[];
extern const u8 gText_CouldntImproveItsCondition[];
extern const u8 gText_BadConditionResultedInWeakAppeal[];
extern const u8 gText_MonWasUnaffected[];
extern const u8 gText_AttractedCrowdsAttention[];

// Misc, used directly
extern const u8 gText_MonAppealedWithMove[];
extern const u8 gText_MonCantAppealNextTurn[];
extern const u8 gText_RepeatedAppeal[];
extern const u8 gText_MonsXDidntGoOverWell[];
extern const u8 gText_MonsXWentOverGreat[];
extern const u8 gText_MonsXGotTheCrowdGoing[];
extern const u8 gText_CrowdContinuesToWatchMon[];
extern const u8 gText_MonsMoveIsIgnored[];
extern const u8 gText_MonWasTooNervousToMove[];
extern const u8 gText_MonWasWatchingOthers[];
extern const u8 gText_AllOutOfAppealTime[];
extern const u8 gText_Contest_Shyness[];
extern const u8 gText_Contest_Anxiety[];
extern const u8 gText_Contest_Laziness[];
extern const u8 gText_Contest_Hesitancy[];
extern const u8 gText_Contest_Fear[];
extern const u8 gText_AppealNumWhichMoveWillBePlayed[];
extern const u8 gText_AppealNumButItCantParticipate[];

static const u8 *const sAppealResultTexts[] =
{
    [CONTEST_STRING_MORE_CONSCIOUS]            = gText_BecameMoreConsciousOfOtherMons,
    [CONTEST_STRING_NO_APPEAL]                 = gText_MonCantMakeAnAppealAfterThis,
    [CONTEST_STRING_SETTLE_DOWN]               = gText_SettledDownJustLittleBit,
    [CONTEST_STRING_OBLIVIOUS_TO_OTHERS]       = gText_BecameObliviousToOtherMons,
    [CONTEST_STRING_LESS_AWARE]                = gText_BecameLessAwareOfOtherMons,
    [CONTEST_STRING_STOPPED_CARING]            = gText_StoppedCaringAboutOtherMons,
    [CONTEST_STRING_STARTLE_ATTEMPT]           = gText_TriedToStartleOtherMons,
    [CONTEST_STRING_DAZZLE_ATTEMPT]            = gText_TriedToDazzleOthers,
    [CONTEST_STRING_JUDGE_LOOK_AWAY2]          = gText_JudgeLookedAwayFromMon,
    [CONTEST_STRING_UNNERVE_ATTEMPT]           = gText_TriedToUnnerveNextMon,
    [CONTEST_STRING_NERVOUS]                   = gText_MonBecameNervous,
    [CONTEST_STRING_UNNERVE_WAITING]           = gText_AppealTriedToUnnerveWaitingMons,
    [CONTEST_STRING_TAUNT_WELL]                = gText_TauntedMonsDoingWell,
    [CONTEST_STRING_REGAINED_FORM]             = gText_MonRegainedItsForm,
    [CONTEST_STRING_JAM_WELL]                  = gText_TriedToJamMonDoingWell,
    [CONTEST_STRING_HUSTLE_STANDOUT]           = gText_StandoutMonHustledEvenMore,
    [CONTEST_STRING_WORK_HARD_UNNOTICED]       = gText_LargelyUnnoticedMonWorkedHard,
    [CONTEST_STRING_WORK_BEFORE]               = gText_WorkedAsMuchAsMonBefore,
    [CONTEST_STRING_APPEAL_NOT_WELL]           = gText_MonsAppealDidNotGoWell,
    [CONTEST_STRING_WORK_PRECEDING]            = gText_WorkedAsMuchAsPrecedingMon,
    [CONTEST_STRING_APPEAL_NOT_WELL2]          = gText_MonsAppealDidNotGoWell2,
    [CONTEST_STRING_APPEAL_NOT_SHOWN_WELL]     = gText_MonsAppealDidNotGoWell3,
    [CONTEST_STRING_APPEAL_SLIGHTLY_WELL]      = gText_MonsAppealWentSlightlyWell,
    [CONTEST_STRING_APPEAL_PRETTY_WELL]        = gText_MonsAppealWentPrettyWell,
    [CONTEST_STRING_APPEAL_EXCELLENTLY]        = gText_MonsAppealWentExcellently,
    [CONTEST_STRING_APPEAL_DUD]                = gText_MonsAppealWasDud,
    [CONTEST_STRING_APPEAL_NOT_VERY_WELL]      = gText_MonsAppealDidNotWorkVeryWell,
    [CONTEST_STRING_APPEAL_SLIGHTLY_WELL2]     = gText_MonsAppealWentSlightlyWell2,
    [CONTEST_STRING_APPEAL_PRETTY_WELL2]       = gText_MonsAppealWentPrettyWell2,
    [CONTEST_STRING_APPEAL_VERY_WELL]          = gText_MonsAppealWentVeryWell,
    [CONTEST_STRING_APPEAL_EXCELLENTLY2]       = gText_MonsAppealWentExcellently2,
    [CONTEST_STRING_SAME_TYPE_GOOD]            = gText_SameTypeAsOneBeforeGood,
    [CONTEST_STRING_DIFF_TYPE_GOOD]            = gText_NotSameTypeAsOneBeforeGood,
    [CONTEST_STRING_STOOD_OUT_AS_MUCH]         = gText_StoodOutMuchMoreThanMonBefore,
    [CONTEST_STRING_NOT_AS_WELL]               = gText_DidntDoAsWellAsMonBefore,
    [CONTEST_STRING_CONDITION_ROSE]            = gText_MonsConditionRoseAboveUsual,
    [CONTEST_STRING_HOT_STATUS]                = gText_MonsHotStatusMadeGreatAppeal,
    [CONTEST_STRING_MOVE_UP_LINE]              = gText_MovedUpInLineForNextAppeal,
    [CONTEST_STRING_MOVE_BACK_LINE]            = gText_MovedBackInLineForNextAppeal,
    [CONTEST_STRING_SCRAMBLE_ORDER]            = gText_ScrambledUpOrderForNextTurn,
    [CONTEST_STRING_JUDGE_EXPECTANTLY2]        = gText_JudgeLookedAtMonExpectantly,
    [CONTEST_STRING_WENT_OVER_WELL]            = gText_AppealComboWentOverWell,
    [CONTEST_STRING_WENT_OVER_VERY_WELL]       = gText_AppealComboWentOverVeryWell,
    [CONTEST_STRING_APPEAL_COMBO_EXCELLENTLY]  = gText_AppealComboWentOverExcellently,
    [CONTEST_STRING_AVERT_GAZE]                = gText_MonManagedToAvertGaze,
    [CONTEST_STRING_AVOID_SEEING]              = gText_MonManagedToAvoidSeeingIt,
    [CONTEST_STRING_NOT_FAZED]                 = gText_MonIsntFazedByThatSortOfThing,
    [CONTEST_STRING_LITTLE_DISTRACTED]         = gText_MonBecameALittleDistracted,
    [CONTEST_STRING_ATTEMPT_STARTLE]           = gText_TriedToStartleOtherPokemon,
    [CONTEST_STRING_LOOKED_DOWN]               = gText_MonLookedDownOutOfDistraction,
    [CONTEST_STRING_TURNED_BACK]               = gText_MonTurnedBackOutOfDistraction,
    [CONTEST_STRING_UTTER_CRY]                 = gText_MonCouldntHelpUtteringCry,
    [CONTEST_STRING_LEAPT_UP]                  = gText_MonCouldntHelpLeapingUp,
    [CONTEST_STRING_TRIPPED_OVER]              = gText_MonTrippedOutOfDistraction,
    [CONTEST_STRING_MESSED_UP2]                = gText_ButItMessedUp2,
    [CONTEST_STRING_FAILED_TARGET_NERVOUS]     = gText_ButItFailedToMakeTargetNervous,
    [CONTEST_STRING_FAILED_ANYONE_NERVOUS]     = gText_ButItFailedToMakeAnyoneNervous,
    [CONTEST_STRING_IGNORED]                   = gText_ButItWasIgnored,
    [CONTEST_STRING_NO_CONDITION_IMPROVE]      = gText_CouldntImproveItsCondition,
    [CONTEST_STRING_BAD_CONDITION_WEAK_APPEAL] = gText_BadConditionResultedInWeakAppeal,
    [CONTEST_STRING_UNAFFECTED]                = gText_MonWasUnaffected,
    [CONTEST_STRING_ATTRACTED_ATTENTION]       = gText_AttractedCrowdsAttention
};

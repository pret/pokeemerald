#include "constants/global.h"
#include "constants/contest.h"
	.include "asm/macros.inc"
	.include "asm/macros/contest_ai_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	enum_start
	enum MON_1
	enum MON_2
	enum MON_3
	enum MON_4

	.align 2
gContestAI_ScriptsTable::
	.4byte AI_CheckBadMove      @ CONTEST_AI_CHECK_BAD_MOVE
	.4byte AI_CheckCombo        @ CONTEST_AI_CHECK_COMBO
	.4byte AI_CheckBoring       @ CONTEST_AI_CHECK_BORING
	.4byte AI_CheckExcitement   @ CONTEST_AI_CHECK_EXCITEMENT
	.4byte AI_CheckOrder        @ CONTEST_AI_CHECK_ORDER
	.4byte AI_CheckGoodMove     @ CONTEST_AI_CHECK_GOOD_MOVE
	.4byte AI_Erratic           @ CONTEST_AI_ERRATIC
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_1
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_2
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_3
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_4
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_5
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_6
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_7
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_8
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_9
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_10
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_11
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_12
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_13
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_14
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_15
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_16
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_17
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_18
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_19
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_20
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_21
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_22
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_23
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_24
	.4byte AI_Nothing           @ CONTEST_AI_DUMMY_25


@ Unused. Encourages improving condition on the 1st appeal, or startling mons if the users turn is later
AI_CheckTiming:
	if_appeal_num_not_eq 0, AI_CheckTiming_SkipCondition
	if_effect_not_eq CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, AI_CheckTiming_SkipCondition
	score +10
AI_CheckTiming_SkipCondition:
	call AI_CheckTiming_TryStartle
	end
AI_CheckTiming_TryStartle:
	if_user_order_more_than MON_2, AI_CheckTiming_End
	if_effect_type_not_eq CONTEST_EFFECT_TYPE_STARTLE_MON, AI_CheckTiming_End
	if_effect_type_not_eq CONTEST_EFFECT_TYPE_STARTLE_MONS, AI_CheckTiming_End
	score +10
AI_CheckTiming_End:
	end

@ Unused, doesnt make much sense
@ Encourages using an avoid being startled move
@ The various appeal and turn checks are pointless, it will always encourage these moves
AI_AvoidStartle:
	if_appeal_num_eq 0, AI_AvoidStartle_1stAppeal
	if_appeal_num_eq 1, AI_AvoidStartle_2ndAppeal
	if_appeal_num_eq 2, AI_AvoidStartle_3rdAppeal
	if_appeal_num_eq 3, AI_AvoidStartle_4thAppeal
	if_last_appeal      AI_AvoidStartle_LastAppeal
	end
AI_AvoidStartle_1stAppeal:
	if_user_order_not_eq MON_1, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_2, AI_AvoidStartle_EncourageIfAvoidMove2
	if_user_order_not_eq MON_3, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_4, AI_AvoidStartle_EncourageIfAvoidMove
	end
AI_AvoidStartle_EncourageIfAvoidMove:
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE, AI_AvoidStartle_Encourage
	end
AI_AvoidStartle_EncourageIfAvoidMove2:
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE, AI_AvoidStartle_Encourage
	end
AI_AvoidStartle_EncourageIfAvoidMove3:
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE, AI_AvoidStartle_Encourage
	end
AI_AvoidStartle_2ndAppeal:
	if_user_order_not_eq MON_1, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_2, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_3, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_4, AI_AvoidStartle_EncourageIfAvoidMove
	end
AI_AvoidStartle_3rdAppeal:
	if_user_order_not_eq MON_1, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_2, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_3, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_4, AI_AvoidStartle_EncourageIfAvoidMove
	end
AI_AvoidStartle_4thAppeal:
	if_user_order_not_eq MON_1, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_2, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_3, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_4, AI_AvoidStartle_EncourageIfAvoidMove
	end
AI_AvoidStartle_LastAppeal:
	if_user_order_not_eq MON_1, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_2, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_3, AI_AvoidStartle_EncourageIfAvoidMove
	if_user_order_not_eq MON_4, AI_AvoidStartle_EncourageIfAvoidMove
	end
AI_AvoidStartle_Encourage:
	score +10
	end
AI_AvoidStartle_End:
	end

@ Unused
AI_PreferMostAppealingMove:
	if_most_appealing_move AI_PreferMostAppealingMove_Encourage
	end
AI_PreferMostAppealingMove_Encourage:
	score +10
	end

@ Discourages using the same move multiple times if it would get boring
AI_CheckBoring:
	if_effect_eq CONTEST_EFFECT_REPETITION_NOT_BORING, AI_CheckBoring_NotBoring
	if_move_used_count_eq 1, AI_CheckBoring_1stRepeat
	if_move_used_count_eq 2, AI_CheckBoring_2ndRepeat
	if_move_used_count_eq 3, AI_CheckBoring_3rdRepeat
	if_move_used_count_eq 4, AI_CheckBoring_4thRepeat
	@ No repeats
	end
AI_CheckBoring_1stRepeat:
	score -5
	end
AI_CheckBoring_2ndRepeat:
	score -15
	end
AI_CheckBoring_3rdRepeat:
	score -20
	end
AI_CheckBoring_4thRepeat:
	score -25
	end
AI_CheckBoring_NotBoring:
	end

@ Strongly encourages using an exciting move if user is in a position to receive the max excitement bonus
@ Encourages using exciting moves in general
@ If the user doesnt have a good exciting move to use, then encourage lowering excitement to prevent
@ opponents from benefitting from the excitement
AI_CheckExcitement:
	if_move_excitement_less_than 0, AI_CheckExcitement_Negative
	if_move_excitement_eq 0, AI_CheckExcitement_Neutral
	if_move_excitement_eq 1, AI_CheckExcitement_Positive
	end
AI_CheckExcitement_Negative:
	if_excitement_eq 4, AI_CheckExcitement_Negative_1AwayFromMax
	if_excitement_eq 3, AI_CheckExcitement_Negative_2AwayFromMax
	if_user_has_exciting_move AI_CheckExcitement_End
	score +15
	end
AI_CheckExcitement_Negative_1AwayFromMax:
	if_user_order_not_eq MON_1, AI_CheckExcitement_Negative_1AwayFromMax_Not1stUp
	if_random_less_than 51, AI_CheckExcitement_End
	score +20
	end
AI_CheckExcitement_Negative_1AwayFromMax_Not1stUp:
	if_random_less_than 127, AI_CheckExcitement_End
	score -10
	end
AI_CheckExcitement_Negative_2AwayFromMax:
	if_user_order_not_eq MON_1, AI_CheckExcitement_Negative_2AwayFromMax_Not1stUp
	if_last_appeal AI_CheckExcitement_Negative_2AwayFromMax_LastAppeal
	if_random_less_than 51, AI_CheckExcitement_End
	score +10
	end
AI_CheckExcitement_Negative_2AwayFromMax_LastAppeal:
	score +15
	end
AI_CheckExcitement_Negative_2AwayFromMax_Not1stUp:
	if_random_less_than 127, AI_CheckExcitement_End
	score +10
	end
AI_CheckExcitement_Neutral:
	if_random_less_than 127, AI_CheckExcitement_End
	score +10
	end
AI_CheckExcitement_Positive:
	if_move_used_count_more_than 0, AI_CheckExcitement_Positive_Repeat
	if_user_order_not_eq MON_1, AI_CheckExcitement_Positive_Not1stUpForMax
	if_excitement_not_eq 4, AI_CheckExcitement_Positive_Not1stUpForMax
	score +30
	end
AI_CheckExcitement_Positive_Not1stUpForMax:
	if_random_less_than 100, AI_CheckExcitement_End
	score +10
	end
AI_CheckExcitement_Positive_Repeat:
	if_effect_not_eq CONTEST_EFFECT_REPETITION_NOT_BORING, AI_CheckExcitement_End
	if_user_order_not_eq MON_1, AI_CheckExcitement_Positive_Not1stUpForMax
	if_excitement_not_eq 4, AI_CheckExcitement_Positive_Not1stUpForMax
	score +30
	end
AI_CheckExcitement_End:
	end

@ Strongly encourages using a move if it would finish a combo
@ Encourages using a move if it would start a combo, esp if the user goes earlier
@ Discourages starting a combo in the last round
@ Discourages using a combo finisher when its combo starter hasnt been used yet
AI_CheckCombo:
	if_would_finish_combo AI_CheckCombo_WouldFinish
	call AI_CheckCombo_CheckStarter
	call AI_CheckCombo_CheckFinisherWithoutStarter
	end
AI_CheckCombo_CheckStarter:
	if_move_used_count_not_eq 0, AI_CheckCombo_End
	if_not_combo_starter AI_CheckCombo_End
	if_user_order_eq MON_1, AI_CheckCombo_Starter1stUp
	if_user_order_eq MON_2, AI_CheckCombo_Starter2ndUp
	if_user_order_eq MON_3, AI_CheckCombo_Starter3rdUp
	if_user_order_eq MON_4, AI_CheckCombo_StarterLast
	end
AI_CheckCombo_CheckFinisherWithoutStarter:
	if_not_combo_finisher AI_CheckCombo_End
	score -10
	end
AI_CheckCombo_WouldFinish:
	score +25
	end
AI_CheckCombo_Starter1stUp:
	if_last_appeal AI_CheckCombo_StarterOnLastAppeal
	if_random_less_than 150, AI_CheckCombo_End
	score +10
	end
AI_CheckCombo_Starter2ndUp:
	if_last_appeal AI_CheckCombo_StarterOnLastAppeal
	if_random_less_than 125, AI_CheckCombo_End
	score +10
	end
AI_CheckCombo_Starter3rdUp:
	if_last_appeal AI_CheckCombo_StarterOnLastAppeal
	if_random_less_than 50, AI_CheckCombo_End
	score +10
	end
AI_CheckCombo_StarterLast:
	if_last_appeal AI_CheckCombo_StarterOnLastAppeal
	score +10
	end
AI_CheckCombo_StarterOnLastAppeal:
	if_random_less_than 125, AI_CheckCombo_End
	score -15
	end
AI_CheckCombo_End:
	end

@ Checks if move should be encouraged based on its effect
AI_CheckGoodMove:
	if_effect_eq CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,            AI_CGM_BetterWithGoodCondition
	if_effect_eq CONTEST_EFFECT_NEXT_APPEAL_EARLIER,                   AI_CGM_NextAppealEarlier
	if_effect_eq CONTEST_EFFECT_NEXT_APPEAL_LATER,                     AI_CGM_NextAppealLater
	if_effect_eq CONTEST_EFFECT_REPETITION_NOT_BORING,                 AI_CGM_RepetitionNotBoring
	if_effect_eq CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, AI_CGM_ImproveCondition
	if_effect_eq CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,                  AI_CGM_DontExciteAudience
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,           AI_CGM_AppealAsGoodAsPrevOnes
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,            AI_CGM_AppealAsGoodAsPrevOne
	if_effect_eq CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,          AI_CGM_BetterWhenAudienceExcited
	if_effect_eq CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,         AI_CGM_WorsenConditionOfPrevMons
	if_effect_eq CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,                 AI_CGM_TargetMonWithJudgesAttention
	if_effect_eq CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,     AI_CGM_TargetMonWithJudgesAttention
	if_effect_eq CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,           AI_CGM_MakeFollowingMonsNervous
	if_effect_eq CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,         AI_CGM_JamsOthersButMissOneTurn
	end

AI_CGM_BetterWithGoodCondition:
	if_user_condition_eq 3, AI_CGM_BetterWithGoodCondition_3
	if_user_condition_eq 2, AI_CGM_BetterWithGoodCondition_2
	if_user_condition_eq 1, AI_CGM_BetterWithGoodCondition_1
	if_user_condition_eq 0, AI_CGM_BetterWithGoodCondition_0
	end
AI_CGM_BetterWithGoodCondition_3:
	score +20
	end
AI_CGM_BetterWithGoodCondition_2:
	if_random_less_than 125, AI_CGM_End
	score +15
	end
AI_CGM_BetterWithGoodCondition_1:
	if_random_less_than 125, AI_CGM_End
	score +5
	end
AI_CGM_BetterWithGoodCondition_0:
	score -20
	end

AI_CGM_NextAppealEarlier:
	if_user_doesnt_have_move CONTEST_EFFECT_BETTER_IF_FIRST, AI_CGM_End
	if_random_less_than 50, AI_CGM_End
	score +20
	end

AI_CGM_NextAppealLater:
	if_user_doesnt_have_move CONTEST_EFFECT_BETTER_IF_LAST, AI_CGM_End
	if_random_less_than 50, AI_CGM_End
	score +20
	end

AI_CGM_RepetitionNotBoring:
	if_user_order_not_eq MON_4, AI_CGM_End
	if_random_less_than 50, AI_CGM_End
	score +15
	end

AI_CGM_Unused:
	if_last_appeal AI_CGM_Unused_LastAppeal
	if_random_less_than 220, AI_CGM_Unused_Discourage
	score +10
	end
AI_CGM_Unused_LastAppeal:
	if_random_less_than 20, AI_CGM_End
	score +15
	end
AI_CGM_Unused_Discourage:
	score -20
	end

@ Enourages improving condition, esp if user has moves better with good condition or on 1st appeal
@ Discourages improving condition if at max condition, or if last appeal
AI_CGM_ImproveCondition:
	if_user_doesnt_have_move CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION, AI_CGM_ImproveCondition_CheckAppealNum
	if_user_condition_eq 3, AI_CGM_ImproveCondition_AtMax
	if_random_less_than 50, AI_CGM_End
	score +15
	end
AI_CGM_ImproveCondition_AtMax:
	score -10
	end
AI_CGM_ImproveCondition_CheckAppealNum:
	if_last_appeal AI_CGM_ImproveCondition_LastAppeal
	if_appeal_num_eq 0, AI_CGM_ImproveCondition_FirstAppeal
	if_move_used_count_eq 1, AI_CGM_End
	if_random_less_than 125, AI_CGM_End
	score +10
	end
AI_CGM_ImproveCondition_FirstAppeal:
	if_random_less_than 100, AI_CGM_End
	score +10
	end
AI_CGM_ImproveCondition_LastAppeal:
	score -10
	end

@ Encourage stopping audience excitement early in the appeal, or last appeal if no better options
AI_CGM_DontExciteAudience:
	if_move_used_count_eq 1, AI_CGM_End
	if_user_order_eq MON_1, AI_CGM_DontExciteAudience_EarlyTurn
	if_user_order_eq MON_2, AI_CGM_DontExciteAudience_EarlyTurn
	if_not_last_appeal AI_CGM_End
	if_user_has_exciting_move AI_CGM_End
	if_excitement_less_than 1, AI_CGM_End
	score +10
	end
AI_CGM_DontExciteAudience_EarlyTurn:
	if_random_less_than 127, AI_CGM_End
	score +10
	end

@ Encourages move the later the user goes
AI_CGM_AppealAsGoodAsPrevOnes:
	if_user_order_eq MON_2, AI_CGM_AppealAsGoodAsPrevOnes_2ndUp
	if_user_order_eq MON_3, AI_CGM_AppealAsGoodAsPrevOnes_3rdUp
	if_user_order_eq MON_4, AI_CGM_AppealAsGoodAsPrevOnes_Last
	end
AI_CGM_AppealAsGoodAsPrevOnes_2ndUp:
	score +5
	end
AI_CGM_AppealAsGoodAsPrevOnes_3rdUp:
	score +15
	end
AI_CGM_AppealAsGoodAsPrevOnes_Last:
	score +20
	end

@ Encourages move more for each opponent who will have a turn before the user
AI_CGM_AppealAsGoodAsPrevOne:
	if_user_order_eq MON_1, AI_CGM_AppealAsGoodAsPrevOne_1stUp
	if_user_order_eq MON_2, AI_CGM_AppealAsGoodAsPrevOne_2ndUp
	if_user_order_eq MON_3, AI_CGM_AppealAsGoodAsPrevOne_3rdUp
	if_user_order_eq MON_4, AI_CGM_AppealAsGoodAsPrevOne_Last
	end
AI_CGM_AppealAsGoodAsPrevOne_1stUp:
	score -10
	end
AI_CGM_AppealAsGoodAsPrevOne_2ndUp:
	if_cannot_participate MON_1, AI_CGM_End
	score +5
	end
AI_CGM_AppealAsGoodAsPrevOne_3rdUp:
	if_cannot_participate MON_1, AI_CGM_AppealAsGoodAsPrevOne_3rdUp_CheckMon2
	score +5
	goto AI_CGM_AppealAsGoodAsPrevOne_3rdUp_CheckMon2
	end
AI_CGM_AppealAsGoodAsPrevOne_3rdUp_CheckMon2:
	if_cannot_participate MON_2, AI_CGM_End
	score +5
	end
AI_CGM_AppealAsGoodAsPrevOne_Last:
	if_cannot_participate MON_1, AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon2
	score +5
	goto AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon2
	end
AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon2:
	if_cannot_participate MON_2, AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon3
	score +5
	goto AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon3
	end
AI_CGM_AppealAsGoodAsPrevOne_Last_CheckMon3:
	if_cannot_participate MON_3, AI_CGM_End
	score +5
	end

@ Encourage move if audience is close to full exictement and user goes first
@ See bug note, only does this on 1st appeal (when it will never happen)
AI_CGM_BetterWhenAudienceExcited:
	if_user_order_eq MON_1, AI_CGM_BetterWhenAudienceExcited_1stUp
	if_user_order_more_than MON_1, AI_CGM_BetterWhenAudienceExcited_Not1stUp
	end
AI_CGM_BetterWhenAudienceExcited_1stUp:
	@ BUG: Should be if_appeal_num_eq 0
	@ 1st up on 1st appeal excitement will always be 0
	if_appeal_num_not_eq 0, AI_CGM_BetterWhenAudienceExcited_Not1stAppeal
	if_excitement_eq 4, AI_CGM_BetterWhenAudienceExcited_1AwayFromMax
	if_excitement_eq 3, AI_CGM_BetterWhenAudienceExcited_2AwayFromMax
	end
AI_CGM_BetterWhenAudienceExcited_Not1stAppeal:
	if_random_less_than 125, AI_CGM_End
	score -15
	end
AI_CGM_BetterWhenAudienceExcited_1AwayFromMax:
	if_random_less_than 125, AI_CGM_End
	score +20
	end
AI_CGM_BetterWhenAudienceExcited_2AwayFromMax:
	if_random_less_than 125, AI_CGM_End
	score +15
	end
AI_CGM_BetterWhenAudienceExcited_Not1stUp:
	if_random_less_than 178, AI_CGM_End
	score +10
	end

@ Encourage move more for each condition star the prev mons have
AI_CGM_WorsenConditionOfPrevMons:
	if_user_order_eq MON_1, AI_CGM_End
	goto AI_CGM_WorsenConditionOfPrevMons_CheckMon1
	end
AI_CGM_WorsenConditionOfPrevMons_CheckMon1:
	if_cannot_participate MON_1, AI_CGM_WorsenConditionOfPrevMons_TryCheckMon2
	if_condition_eq MON_1, 0, AI_CGM_WorsenConditionOfPrevMons_TryCheckMon2
	if_condition_eq MON_1, 1, AI_CGM_WorsenConditionOfPrevMons_Mon1Has1Star
	if_condition_eq MON_1, 2, AI_CGM_WorsenConditionOfPrevMons_Mon1Has2Stars
	if_condition_eq MON_1, 3, AI_CGM_WorsenConditionOfPrevMons_Mon1Has3Stars
	end
AI_CGM_WorsenConditionOfPrevMons_Mon1Has1Star:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	score +5
	if_user_order_more_than MON_2, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	end
AI_CGM_WorsenConditionOfPrevMons_Mon1Has2Stars:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	score +10
	if_user_order_more_than MON_2, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	end
AI_CGM_WorsenConditionOfPrevMons_Mon1Has3Stars:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	score +15
	if_user_order_more_than MON_2, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	end
AI_CGM_WorsenConditionOfPrevMons_TryCheckMon2:
	if_user_order_more_than MON_2, AI_CGM_WorsenConditionOfPrevMons_CheckMon2
	end
AI_CGM_WorsenConditionOfPrevMons_CheckMon2:
	if_cannot_participate MON_2, AI_CGM_WorsenConditionOfPrevMons_TryCheckMon3
	if_condition_eq MON_2, 0, AI_CGM_WorsenConditionOfPrevMons_TryCheckMon3
	if_condition_eq MON_2, 1, AI_CGM_WorsenConditionOfPrevMons_Mon2Has1Star
	if_condition_eq MON_2, 2, AI_CGM_WorsenConditionOfPrevMons_Mon2Has2Stars
	if_condition_eq MON_2, 3, AI_CGM_WorsenConditionOfPrevMons_Mon2Has3Stars
	end
AI_CGM_WorsenConditionOfPrevMons_Mon2Has1Star:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	score +5
	if_user_order_more_than MON_3, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	end
AI_CGM_WorsenConditionOfPrevMons_Mon2Has2Stars:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	score +10
	if_user_order_more_than MON_3, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	end
AI_CGM_WorsenConditionOfPrevMons_Mon2Has3Stars:
	if_random_less_than 125, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	score +15
	if_user_order_more_than MON_3, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	end
AI_CGM_WorsenConditionOfPrevMons_TryCheckMon3:
	if_user_order_more_than MON_3, AI_CGM_WorsenConditionOfPrevMons_CheckMon3
	end
AI_CGM_WorsenConditionOfPrevMons_CheckMon3:
	if_cannot_participate MON_3, AI_CGM_WorsenConditionOfPrevMons_end
	if_condition_eq MON_3, 0, AI_CGM_WorsenConditionOfPrevMons_end
	if_condition_eq MON_3, 1, AI_CGM_WorsenConditionOfPrevMons_Mon3Has1Star
	if_condition_eq MON_3, 2, AI_CGM_WorsenConditionOfPrevMons_Mon3Has2Stars
	if_condition_eq MON_3, 3, AI_CGM_WorsenConditionOfPrevMons_Mon3Has3Stars
	end
AI_CGM_WorsenConditionOfPrevMons_Mon3Has1Star:
	if_random_less_than 125, AI_CGM_End
	score +5
	end
AI_CGM_WorsenConditionOfPrevMons_Mon3Has2Stars:
	if_random_less_than 125, AI_CGM_End
	score +10
	end
AI_CGM_WorsenConditionOfPrevMons_Mon3Has3Stars:
	if_random_less_than 125, AI_CGM_End
	score +15
	end
AI_CGM_WorsenConditionOfPrevMons_end:
	end

@ Encourage if a prev mon has started a combo, esp if they havent completed it yet
@ BUG: Incorrectly uses if_used_combo_starter below, instead of if_not_used_combo_starter
@      As a result it encourages move if a prev mon has not begun a combo
AI_CGM_TargetMonWithJudgesAttention:
	if_user_order_eq MON_1, AI_CGM_End
	goto AI_CGM_TargetMonWithJudgesAttention_CheckMon1
	end
AI_CGM_TargetMonWithJudgesAttention_CheckMon1:
	if_cannot_participate MON_1, AI_CGM_TargetMonWithJudgesAttention_CheckMon2
	if_used_combo_starter MON_1, AI_CGM_TargetMonWithJudgesAttention_CheckMon2
	if_random_less_than 125, AI_CGM_TargetMonWithJudgesAttention_CheckMon2
	score +2
	if_not_completed_combo MON_1, AI_CGM_TargetMonWithJudgesAttention_CheckMon2
	score +8
	end
AI_CGM_TargetMonWithJudgesAttention_CheckMon2:
	if_user_order_eq MON_2, AI_CGM_End
	if_cannot_participate MON_2, AI_CGM_TargetMonWithJudgesAttention_CheckMon3
	if_used_combo_starter MON_2, AI_CGM_TargetMonWithJudgesAttention_CheckMon3
	if_random_less_than 125, AI_CGM_TargetMonWithJudgesAttention_CheckMon3
	score +2
	if_not_completed_combo MON_2, AI_CGM_TargetMonWithJudgesAttention_CheckMon3
	score +8
	end
AI_CGM_TargetMonWithJudgesAttention_CheckMon3:
	if_user_order_eq MON_3, AI_CGM_End
	if_cannot_participate MON_3, AI_CGM_End
	if_used_combo_starter MON_3, AI_CGM_End
	if_random_less_than 125, AI_CGM_End
	score +2
	if_not_completed_combo MON_3, AI_CGM_End
	score +8
	end

@ Encourage making mons nervous that have started a combo and can appeal after the user
AI_CGM_MakeFollowingMonsNervous:
	if_user_order_eq MON_4, AI_CGM_End
	goto AI_CGM_MakeFollowingMonsNervous_CheckMon4
	end
AI_CGM_MakeFollowingMonsNervous_CheckMon4:
	if_cannot_participate MON_4, AI_CGM_MakeFollowingMonsNervous_CheckMon3
	if_not_used_combo_starter MON_4, AI_CGM_MakeFollowingMonsNervous_CheckMon3
	score +5
	if_random_less_than 125, AI_CGM_TargetMonWithJudgesAttention_CheckMon2
	score +5
	end
AI_CGM_MakeFollowingMonsNervous_CheckMon3:
	if_user_order_eq MON_3, AI_CGM_End
	if_cannot_participate MON_3, AI_CGM_MakeFollowingMonsNervous_CheckMon2
	if_not_used_combo_starter MON_3, AI_CGM_MakeFollowingMonsNervous_CheckMon2
	score +5
	if_random_less_than 125, AI_CGM_TargetMonWithJudgesAttention_CheckMon3
	score +5
	end
AI_CGM_MakeFollowingMonsNervous_CheckMon2:
	if_user_order_eq MON_2, AI_CGM_End
	if_cannot_participate MON_2, AI_CGM_End
	if_not_used_combo_starter MON_2, AI_CGM_End
	score +5
	if_random_less_than 125, AI_CGM_End
	score +5
	end

@ Encourages move if users turn is later, or if its the last appeal
AI_CGM_JamsOthersButMissOneTurn:
	if_last_appeal AI_CGM_JamsOthersButMissOneTurn_LastAppeal
	goto AI_CGM_JamsOthersButMissOneTurn_TurnOrder
	end
AI_CGM_JamsOthersButMissOneTurn_LastAppeal:
	score +5
	goto AI_CGM_JamsOthersButMissOneTurn_TurnOrder
	end
AI_CGM_JamsOthersButMissOneTurn_TurnOrder:
	if_user_order_eq MON_1, AI_CGM_JamsOthersButMissOneTurn_1stUp
	if_user_order_eq MON_2, AI_CGM_JamsOthersButMissOneTurn_2ndUp
	if_user_order_eq MON_3, AI_CGM_JamsOthersButMissOneTurn_3rdUp
	if_user_order_eq MON_4, AI_CGM_JamsOthersButMissOneTurn_Last
	end
AI_CGM_JamsOthersButMissOneTurn_1stUp:
	score -15
	end
AI_CGM_JamsOthersButMissOneTurn_2ndUp:
	if_random_less_than 125, AI_CGM_End
	score -10
	end
AI_CGM_JamsOthersButMissOneTurn_3rdUp:
	if_random_less_than 125, AI_CGM_End
	score +5
	end
AI_CGM_JamsOthersButMissOneTurn_Last:
	if_random_less_than 125, AI_CGM_End
	score +15
	end

AI_CGM_End:
	end

@ Randomly encourage moves in Cute, Smart, and Tough contests.
AI_Erratic:
	if_contest_type_eq CONTEST_CATEGORY_CUTE, AI_Erratic_CuteSmartTough
	if_contest_type_eq CONTEST_CATEGORY_SMART, AI_Erratic_CuteSmartTough
	if_contest_type_eq CONTEST_CATEGORY_TOUGH, AI_Erratic_CuteSmartTough
	end
AI_Erratic_CuteSmartTough:
	if_random_less_than 125, AI_Erratic_End
	score +10
	end
AI_Erratic_End:
	end

@ Checks if move should be discouraged based on its effect
AI_CheckBadMove:
	if_effect_eq CONTEST_EFFECT_STARTLE_FRONT_MON,                     AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_STARTLE_PREV_MON,                      AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,               AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_STARTLE_PREV_MON_2,                    AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,            AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_BETTER_IF_SAME_TYPE,                   AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_BETTER_IF_DIFF_TYPE,                   AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,               AI_CBM_DependsOnPrevMon
	if_effect_eq CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS,            AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_PREV_MONS,                     AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,               AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_PREV_MONS_2,                   AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,     AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,                 AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,         AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,         AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,  AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL,              AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL,            AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL,              AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL,             AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL,             AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION, AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,         AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,           AI_CBM_DependsOnPrevMons
	if_effect_eq CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS,            AI_CBM_DependsOnNextMon
	if_effect_eq CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,           AI_CBM_DependsOnNextMons
	if_effect_eq CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,                  AI_CBM_DependsOnNextMons
	if_effect_eq CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, AI_CBM_ImproveCondition
	if_effect_eq CONTEST_EFFECT_AVOID_STARTLE_ONCE,                    AI_CBM_AvoidStartle
	if_effect_eq CONTEST_EFFECT_AVOID_STARTLE,                         AI_CBM_AvoidStartle
	if_effect_eq CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY,                AI_CBM_AvoidStartle
	if_effect_eq CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,        AI_CBM_NoMoreMoves
	end

@ If previous mon is skipping turn (or user is first), discourage move
AI_CBM_DependsOnPrevMon:
	if_user_order_eq MON_1, AI_CBM_DependsOnPrevMon_1stUp
	if_user_order_eq MON_2, AI_CBM_DependsOnPrevMon_2ndUp
	if_user_order_eq MON_3, AI_CBM_DependsOnPrevMon_3rdUp
	if_user_order_eq MON_4, AI_CBM_DependsOnPrevMon_Last
	end
AI_CBM_DependsOnPrevMon_1stUp:
	score -10
	end
AI_CBM_DependsOnPrevMon_2ndUp:
	if_can_participate MON_1, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnPrevMon_3rdUp:
	if_can_participate MON_2, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnPrevMon_Last:
	if_can_participate MON_3, AI_CBM_End
	score -10
	end

@ If previous mons are all skipping turns (or user is first), discourage move
AI_CBM_DependsOnPrevMons:
	if_user_order_eq MON_1, AI_CBM_DependsOnPrevMons_1stUp
	if_user_order_eq MON_2, AI_CBM_DependsOnPrevMons_2ndUp
	if_user_order_eq MON_3, AI_CBM_DependsOnPrevMons_3rdUp
	if_user_order_eq MON_4, AI_CBM_DependsOnPrevMons_Last
	end
AI_CBM_DependsOnPrevMons_1stUp:
	score -20
	end
AI_CBM_DependsOnPrevMons_2ndUp:
	if_can_participate MON_1, AI_CBM_End
	score -15
	end
AI_CBM_DependsOnPrevMons_3rdUp:
	if_can_participate MON_1, AI_CBM_End
	if_can_participate MON_2, AI_CBM_End
	score -15
	end
AI_CBM_DependsOnPrevMons_Last:
	if_can_participate MON_1, AI_CBM_End
	if_can_participate MON_2, AI_CBM_End
	if_can_participate MON_3, AI_CBM_End
	score -15
	end

@ If next mon is skipping turn (or user is last), discourage move
AI_CBM_DependsOnNextMon:
	if_user_order_eq MON_1, AI_CBM_DependsOnNextMon_1stUp
	if_user_order_eq MON_2, AI_CBM_DependsOnNextMon_2ndUp
	if_user_order_eq MON_3, AI_CBM_DependsOnNextMon_3rdUp
	score -10
	end
AI_CBM_DependsOnNextMon_1stUp:
	if_can_participate MON_2, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnNextMon_2ndUp:
	if_can_participate MON_3, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnNextMon_3rdUp:
	if_can_participate MON_4, AI_CBM_End
	score -10
	end

@ If next mons are all skipping turns (or user is last), discourage move
AI_CBM_DependsOnNextMons:
	if_user_order_eq MON_1, AI_CBM_DependsOnNextMons_1stUp
	if_user_order_eq MON_2, AI_CBM_DependsOnNextMons_2ndUp
	if_user_order_eq MON_3, AI_CBM_DependsOnNextMons_3rdUp
	score -10
	end
AI_CBM_DependsOnNextMons_1stUp:
	if_can_participate MON_2, AI_CBM_End
	if_can_participate MON_3, AI_CBM_End
	if_can_participate MON_4, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnNextMons_2ndUp:
	if_can_participate MON_3, AI_CBM_End
	if_can_participate MON_4, AI_CBM_End
	score -10
	end
AI_CBM_DependsOnNextMons_3rdUp:
	if_can_participate MON_4, AI_CBM_End
	score -10
	end

@ If at max condition, discourage move
AI_CBM_ImproveCondition:
	if_user_condition_less_than 3, AI_CBM_End
	score -20
	end

@ If there are no upcoming mons who can make an appeal (or if user is last), discourage move
@ Identical to AI_CBM_DependsOnNextMons
AI_CBM_AvoidStartle:
	if_user_order_eq MON_1, AI_CBM_AvoidStartle_1stUp
	if_user_order_eq MON_2, AI_CBM_AvoidStartle_2ndUp
	if_user_order_eq MON_3, AI_CBM_AvoidStartle_3rdUp
	score -10
	end
AI_CBM_AvoidStartle_1stUp:
	if_can_participate MON_2, AI_CBM_End
	if_can_participate MON_3, AI_CBM_End
	if_can_participate MON_4, AI_CBM_End
	score -10
	end
AI_CBM_AvoidStartle_2ndUp:
	if_can_participate MON_3, AI_CBM_End
	if_can_participate MON_4, AI_CBM_End
	score -10
	end
AI_CBM_AvoidStartle_3rdUp:
	if_can_participate MON_4, AI_CBM_End
	score -10
	end

@ Very good if its the last appeal, otherwise discourage move
AI_CBM_NoMoreMoves:
	if_appeal_num_eq 0, AI_CBM_NoMoreMoves_1stAppeal
	if_appeal_num_eq 1, AI_CBM_NoMoreMoves_2ndAppeal
	if_appeal_num_eq 2, AI_CBM_NoMoreMoves_3rdAppeal
	if_appeal_num_eq 3, AI_CBM_NoMoreMoves_4thAppeal
	if_last_appeal      AI_CBM_NoMoreMoves_LastAppeal
	end
AI_CBM_NoMoreMoves_1stAppeal:
	if_random_less_than 20, AI_CBM_End
	score -15
	end
AI_CBM_NoMoreMoves_2ndAppeal:
	if_random_less_than 40, AI_CBM_End
	score -15
	end
AI_CBM_NoMoreMoves_3rdAppeal:
	if_random_less_than 60, AI_CBM_End
	score -15
	end
AI_CBM_NoMoreMoves_4thAppeal:
	if_random_less_than 80, AI_CBM_End
	score -15
	end
AI_CBM_NoMoreMoves_LastAppeal:
	if_random_less_than 20, AI_CBM_End
	score +20
	end

AI_CBM_End:
	end

@ Encourages/discourages move affected by the move order
@ e.g. use BETTER_IF_FIRST moves if user is first, dont use AVOID_STARTLE moves if last
AI_CheckOrder:
	if_user_order_eq MON_1, AI_CheckOrder_1stUp
	if_user_order_eq MON_2, AI_CheckOrder_2ndUp
	if_user_order_eq MON_3, AI_CheckOrder_3rdUp
	if_user_order_eq MON_4, AI_CheckOrder_Last
	end
AI_CheckOrder_1stUp:
	if_effect_eq CONTEST_EFFECT_BETTER_IF_FIRST,         AI_CheckOrder_1stUp_Encourage
	if_effect_eq CONTEST_EFFECT_BETTER_WHEN_LATER,       AI_CheckOrder_1stUp_Discourage
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE, AI_CheckOrder_1stUp_RandomEncourage
	end
AI_CheckOrder_1stUp_Encourage:
	score +15
	end
AI_CheckOrder_1stUp_Discourage:
	score -15
	end
AI_CheckOrder_1stUp_RandomEncourage:
	if_random_less_than 100, AI_CBM_End
	score +10
	end
AI_CheckOrder_2ndUp:
	if_effect_eq CONTEST_EFFECT_BETTER_WHEN_LATER,       AI_CheckOrder_2ndUp_Discourage
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE, AI_CheckOrder_2ndUp_RandomEncourage
	end
AI_CheckOrder_2ndUp_Discourage:
	score -5
	end
AI_CheckOrder_2ndUp_RandomEncourage:
	if_random_less_than 125, AI_CBM_End
	score +10
	end
AI_CheckOrder_3rdUp:
	if_effect_eq CONTEST_EFFECT_BETTER_WHEN_LATER,           AI_CheckOrder_3rdUp_Encourage
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES, AI_CheckOrder_3rdUp_Encourage
	if_effect_eq CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,   AI_CheckOrder_3rdUp_Encourage
	end
AI_CheckOrder_3rdUp_Encourage:
	score +5
	end
AI_CheckOrder_Last:
	if_effect_eq CONTEST_EFFECT_BETTER_WHEN_LATER,             AI_CheckOrder_Last_StronglyEncourage
	if_effect_eq CONTEST_EFFECT_BETTER_IF_LAST,                AI_CheckOrder_Last_StronglyEncourage
	if_effect_eq CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,   AI_CheckOrder_Last_StronglyEncourage
	if_effect_eq CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,     AI_CheckOrder_Last_StronglyEncourage
	if_effect_eq CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN, AI_CheckOrder_Last_Encourage
	if_effect_type_eq CONTEST_EFFECT_TYPE_AVOID_STARTLE,       AI_CheckOrder_Last_Discourage
	if_effect_type_eq CONTEST_EFFECT_TYPE_STARTLE_MONS,        AI_CheckOrder_Last_RandomEncourage
	end
AI_CheckOrder_Last_StronglyEncourage:
	score +15
	end
AI_CheckOrder_Last_Discourage:
	score -10
	end
AI_CheckOrder_Last_RandomEncourage:
	if_random_less_than 125, AI_CBM_End
	score +10
	end
AI_CheckOrder_Last_Encourage:
	score +5
	end

AI_Nothing:
	end

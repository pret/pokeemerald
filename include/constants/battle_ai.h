#ifndef GUARD_CONSTANTS_BATTLE_AI_H
#define GUARD_CONSTANTS_BATTLE_AI_H

// battlers
#define AI_TARGET 0
#define AI_USER 1
#define AI_TARGET_PARTNER 2
#define AI_USER_PARTNER 3

// get_type command
#define AI_TYPE1_TARGET 0
#define AI_TYPE1_USER 1
#define AI_TYPE2_TARGET 2
#define AI_TYPE2_USER 3
#define AI_TYPE_MOVE 4

// type effectiveness
#define AI_EFFECTIVENESS_x8     7
#define AI_EFFECTIVENESS_x4     6
#define AI_EFFECTIVENESS_x2     5
#define AI_EFFECTIVENESS_x1     4
#define AI_EFFECTIVENESS_x0_5   3
#define AI_EFFECTIVENESS_x0_25  2
#define AI_EFFECTIVENESS_x0_125 1
#define AI_EFFECTIVENESS_x0     0

// AI Flags. Most run specific functions to update score, new flags are used for internal logic in other scripts
#define AI_FLAG_CHECK_BAD_MOVE        (1 << 0)
#define AI_FLAG_TRY_TO_FAINT          (1 << 1)
#define AI_FLAG_CHECK_VIABILITY       (1 << 2)
#define AI_FLAG_SETUP_FIRST_TURN      (1 << 3)
#define AI_FLAG_RISKY                 (1 << 4)
#define AI_FLAG_PREFER_STRONGEST_MOVE (1 << 5)
#define AI_FLAG_PREFER_BATON_PASS     (1 << 6)
#define AI_FLAG_DOUBLE_BATTLE         (1 << 7)   // removed, split between AI_FLAG_CHECK_BAD_MOVE & AI_FLAG_CHECK_GOOD_MOVE
#define AI_FLAG_HP_AWARE              (1 << 8)
#define AI_FLAG_POWERFUL_STATUS       (1 << 9)   // AI prefers moves that set up field effects or side statuses, even if the user can faint the target
// New, Trainer Handicap Flags
#define AI_FLAG_NEGATE_UNAWARE        (1 << 10)  // AI is NOT aware of negating effects like wonder room, mold breaker, etc
#define AI_FLAG_WILL_SUICIDE          (1 << 11)  // AI will use explosion / self destruct / final gambit / etc
// New, Trainer Strategy Flags
#define AI_FLAG_PREFER_STATUS_MOVES   (1 << 12)  // AI gets a score bonus for status moves. Should be combined with AI_FLAG_CHECK_BAD_MOVE to prevent using only status moves
#define AI_FLAG_STALL                 (1 << 13)  // AI stalls battle and prefers secondary damage/trapping/etc. TODO not finished
#define AI_FLAG_SMART_SWITCHING       (1 << 14)  // AI includes a lot more switching checks. Automatically includes AI_FLAG_SMART_MON_CHOICES.
#define AI_FLAG_ACE_POKEMON           (1 << 15)  // AI has an Ace Pokemon. The last Pokemon in the party will not be used until it's the last one remaining.
#define AI_FLAG_OMNISCIENT            (1 << 16)  // AI has full knowledge of player moves, abilities, hold items
#define AI_FLAG_SMART_MON_CHOICES     (1 << 17)  // AI will make smarter decisions when choosing which mon to send out mid-battle and after a KO, which are separate decisions. Automatically included by AI_FLAG_SMART_SWITCHING.
#define AI_FLAG_CONSERVATIVE          (1 << 18)  // AI assumes all moves will low roll damage
#define AI_FLAG_SEQUENCE_SWITCHING    (1 << 19)  // AI switches in mons in exactly party order, and never switches mid-battle

#define AI_FLAG_COUNT                       20

// 'other' ai logic flags
#define AI_FLAG_ROAMING               (1 << 29)
#define AI_FLAG_SAFARI                (1 << 30)
#define AI_FLAG_FIRST_BATTLE          (1 << 31)

#define AI_SCORE_DEFAULT 100 // Default score for all AI moves.

#endif // GUARD_CONSTANTS_BATTLE_AI_H

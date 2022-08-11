#ifndef GUARD_CONSTANTS_BATTLE_ARENA_H
#define GUARD_CONSTANTS_BATTLE_ARENA_H

#define BATTLE_ARENA_FUNC_INIT              0
#define BATTLE_ARENA_FUNC_GET_DATA          1
#define BATTLE_ARENA_FUNC_SET_DATA          2
#define BATTLE_ARENA_FUNC_SAVE              3
#define BATTLE_ARENA_FUNC_SET_PRIZE         4
#define BATTLE_ARENA_FUNC_GIVE_PRIZE        5
#define BATTLE_ARENA_FUNC_GET_TRAINER_NAME  6

#define ARENA_DATA_PRIZE              0
#define ARENA_DATA_WIN_STREAK         1
#define ARENA_DATA_WIN_STREAK_ACTIVE  2

#define ARENA_CATEGORY_MIND  0
#define ARENA_CATEGORY_SKILL 1
#define ARENA_CATEGORY_BODY  2

#define ARENA_RESULT_RUNNING     0 // For intermediate steps, when BattleArena_ShowJudgmentWindow should be called again immediately
#define ARENA_RESULT_STEP_DONE   1 // A step has been completed, the script may advance to the next instruction
#define ARENA_RESULT_PLAYER_WON  2
#define ARENA_RESULT_PLAYER_LOST 3
#define ARENA_RESULT_TIE         4

#endif //GUARD_CONSTANTS_BATTLE_ARENA_H

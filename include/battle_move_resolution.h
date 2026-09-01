#ifndef GUARD_BATTLE_MOVE_RESOLUTION_H
#define GUARD_BATTLE_MOVE_RESOLUTION_H

#include "constants/battle_move_resolution.h"

enum CancelerResult DoAttackCanceler(void);
enum MoveEndResult DoMoveEnd(enum MoveEndState endMode, enum MoveEndState endState);
enum MoveResult DoStatChange(void);

bool32 IsStatChangeMove(enum Move move);
#endif // GUARD_BATTLE_MOVE_RESOLUTION_H

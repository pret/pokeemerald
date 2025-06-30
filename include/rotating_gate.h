#ifndef GUARD_ROTATING_GATE_H
#define GUARD_ROTATING_GATE_H

void RotatingGatePuzzleCameraUpdate(s16 deltaX, s16 deltaY);
void RotatingGate_InitPuzzleAndGraphics(void);
bool32 CheckForRotatingGatePuzzleCollision(u8 direction, s16 x, s16 y);
bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(u8 direction, s16 x, s16 y);

#endif // GUARD_ROTATING_GATE_H

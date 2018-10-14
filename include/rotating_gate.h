#ifndef GUARD_ROTATING_GATE_H
#define GUARD_ROTATING_GATE_H

void RotatingGatePuzzleCameraUpdate(s16, s16);
void RotatingGate_InitPuzzleAndGraphics(void);
u32 CheckForRotatingGatePuzzleCollision(u8, s16, s16);
bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(u8, s16, s16);

#endif // GUARD_ROTATING_GATE_H

#ifndef GUARD_FARAWAY_ISLAND_H
#define GUARD_FARAWAY_ISLAND_H

u32 GetMewMoveDirection(void);
bool8 ShouldMewShakeGrass(struct ObjectEvent *objectEvent);
void UpdateFarawayIslandStepCounter(void);
bool8 ObjectEventIsFarawayIslandMew(struct ObjectEvent *objectEvent);
bool8 IsMewPlayingHideAndSeek(void);

#endif // GUARD_FARAWAY_ISLAND_H

#ifndef GUARD_FARAWAY_ISLAND_H
#define GUARD_FARAWAY_ISLAND_H

u32 GetMewMoveDirection(void);
bool8 ShouldMewShakeGrass(struct ObjectEvent*);
void UpdateFarawayIslandStepCounter(void);
bool8 ObjectEventIsFarawayIslandMew(struct ObjectEvent *);
bool8 IsMewPlayingHideAndSeek(void);

#endif // GUARD_FARAWAY_ISLAND_H

#ifndef GUARD_FARAWAY_ISLAND_H
#define GUARD_FARAWAY_ISLAND_H

u32 GetMewMoveDirection(void);
bool8 sub_81D4A58(struct EventObject*);
void UpdateFarawayIslandStepCounter(void);
bool8 EventObjectIsFarawayIslandMew(struct EventObject *);
bool8 IsMewPlayingHideAndSeek(void);

#endif // GUARD_FARAWAY_ISLAND_H

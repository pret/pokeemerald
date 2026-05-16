#ifndef GUARD_FIELD_DOOR_H
#define GUARD_FIELD_DOOR_H

void FieldSetDoorOpened(u32 x, u32 y);
void FieldSetDoorClosed(u32 x, u32 y);
s8 FieldAnimateDoorClose(u32 x, u32 y);
s8 FieldAnimateDoorOpen(u32 x, u32 y);
bool8 FieldIsDoorAnimationRunning(void);
u32 GetDoorSoundEffect(u32 x, u32 y);

#endif //GUARD_FIELD_DOOR_H

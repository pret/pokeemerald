#ifndef GUARD_EVENT_OBJECT_LOCK_H
#define GUARD_EVENT_OBJECT_LOCK_H

bool8 IsFreezePlayerFinished(void);
void ScriptFreezeObjectEvents(void);
bool8 IsFreezeSelectedObjectAndPlayerFinished(void);
void LockSelectedObjectEvent(void);
void FreezeForApproachingTrainers(void);
bool8 IsFreezeObjectAndPlayerFinished(void);
void ScriptUnfreezeObjectEvents(void);
void UnionRoom_UnlockPlayerAndChatPartner(void);

#endif // GUARD_EVENT_OBJECT_LOCK_H

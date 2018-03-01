#ifndef GUARD_BATTLE_TV_H
#define GUARD_BATTLE_TV_H

void BattleTv_SetDataBasedOnString(u16 stringId);
void BattleTv_SetDataBasedOnMove(u16 move, u16 weatherFlags, struct DisableStruct *disableStructPtr);
void BattleTv_SetDataBasedOnAnimation(u8 animationId);
void TryPutLinkBattleTvShowOnAir(void);
void BattleTv_ClearExplosionFaintCause(void);
u8 GetBattlerMoveSlotId(u8 battlerId, u16 moveId);

#endif // GUARD_BATTLE_TV_H

#ifndef GUARD_BATTLE_TV_H
#define GUARD_BATTLE_TV_H

void BattleTv_SetDataBasedOnString(enum StringID stringId);
void BattleTv_SetDataBasedOnMove(enum Move move, u16 weatherFlags);
void BattleTv_SetDataBasedOnAnimation(u8 animationId);
void TryPutLinkBattleTvShowOnAir(void);
void BattleTv_ClearExplosionFaintCause(void);
u8 GetBattlerMoveSlotId(enum BattlerId battler, enum Move move);

#endif // GUARD_BATTLE_TV_H

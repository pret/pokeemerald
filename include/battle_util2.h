#ifndef GUARD_BATTLE_UTIL2_H
#define GUARD_BATTLE_UTIL2_H

void AllocateBattleResources(void);
void FreeBattleResources(void);
void AdjustFriendshipOnBattleFaint(enum BattlerId battler);
void SwitchPartyOrderInGameMulti(enum BattlerId battler, u8 arg1);
u32 BattlePalace_TryEscapeStatus(enum BattlerId battler);
void AllocateBattleGfxResources(void);
void CloseMainBattleScreen(void);

#endif // GUARD_BATTLE_UTIL_H

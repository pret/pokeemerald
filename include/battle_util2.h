#ifndef GUARD_BATTLE_UTIL2_H
#define GUARD_BATTLE_UTIL2_H

void AllocateBattleResources(void);
void FreeBattleResources(void);
void AdjustFriendshipOnBattleFaint(u8 battler);
void SwitchPartyOrderInGameMulti(u8 battler, u8 arg1);
u32 sub_805725C(u8 battler);

#endif // GUARD_BATTLE_UTIL_H

#ifndef GUARD_BATTLE_AI_SWITCH_ITEMS_H
#define GUARD_BATTLE_AI_SWITCH_ITEMS_H

void GetAIPartyIndexes(u32 battlerId, s32 *firstId, s32 *lastId);
void AI_TrySwitchOrUseItem(u32 battler);
u8 GetMostSuitableMonToSwitchInto(u32 battler);
bool32 ShouldSwitch(u32 battler);

#endif // GUARD_BATTLE_AI_SWITCH_ITEMS_H

#ifndef GUARD_BATTLE_TERASTAL_H
#define GUARD_BATTLE_TERASTAL_H

void ActivateTera(u32 battler);
void ApplyBattlerVisualsForTeraAnim(u32 battler);
bool32 CanTerastallize(u32 battler);
u32 GetBattlerTeraType(u32 battler);
void ExpendTypeStellarBoost(u32 battler, u32 type);
bool32 IsTypeStellarBoosted(u32 battler, u32 type);
uq4_12_t GetTeraMultiplier(u32 battler, u32 type);

u16 GetTeraTypeRGB(u32 type);

#endif

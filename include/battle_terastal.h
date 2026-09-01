#ifndef GUARD_BATTLE_TERASTAL_H
#define GUARD_BATTLE_TERASTAL_H

void ActivateTera(enum BattlerId battler);
void ApplyBattlerVisualsForTeraAnim(enum BattlerId battler);
bool32 IsTeraOrbCharged(void);
bool32 CanTerastallize(enum BattlerId battler);
enum Type GetBattlerTeraType(enum BattlerId battler);
void ExpendTypeStellarBoost(enum BattlerId battler, enum Type type);
bool32 IsTypeStellarBoosted(enum BattlerId battler, enum Type type);
uq4_12_t GetTeraMultiplier(struct DamageContext *ctx);

u16 GetTeraTypeRGB(enum Type type);

#endif

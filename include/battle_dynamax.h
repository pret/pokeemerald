#ifndef GUARD_BATTLE_DYNAMAX_H
#define GUARD_BATTLE_DYNAMAX_H

#define DYNAMAX_TURNS_COUNT 3

bool32 CanDynamax(enum BattlerId battler);
bool32 IsGigantamaxed(enum BattlerId battler);
void ApplyDynamaxHPMultiplier(struct Pokemon *mon);
void ActivateDynamax(enum BattlerId battler);
u32 GetNonDynamaxHP(enum BattlerId battler);
u32 GetNonDynamaxMaxHP(enum BattlerId battler);
void UndoDynamax(enum BattlerId battler);

enum Move GetMaxMove(enum BattlerId battler, enum Move baseMove);
u32 GetMaxMovePower(enum Move baseMove, enum Move move);
bool32 IsMaxMove(enum Move move);
void ChooseDamageNonTypesString(enum Type type);

void BS_UpdateDynamax(void);
void BS_SetSteelsurge(void);
void BS_HealOneSixth(void);
void BS_TryRecycleBerry(void);
void BS_JumpIfDynamaxed(void);

#endif

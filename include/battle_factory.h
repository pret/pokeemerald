#ifndef GUARD_BATTLE_FACTORY_H
#define GUARD_BATTLE_FACTORY_H

void CallBattleFactoryFunction(void);
bool8 InBattleFactory(void);
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle);
void FillFactoryBrainParty(void);
u8 GetNumPastRentalsRank(u8 battleMode, enum FrontierLevelMode lvlMode);
u64 GetAiScriptsInBattleFactory(void);
void FillFactoryTrainerParty(void);

#endif // GUARD_BATTLE_FACTORY_H

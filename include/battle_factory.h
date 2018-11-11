#ifndef GUARD_BATTLE_FACTORY_H
#define GUARD_BATTLE_FACTORY_H

void CallBattleFactoryFunction(void);
bool8 sub_81A6BF4(void);
u8 GetFactoryMonFixedIV(u8 arg0, u8 arg1);
void FillFactoryBrainParty(void);
u8 sub_81A6F70(u8 battleMode, u8 lvlMode);
u32 GetAiScriptsInBattleFactory(void);
void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot);

#endif // GUARD_BATTLE_FACTORY_H

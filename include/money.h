#ifndef GUARD_MONEY_H
#define GUARD_MONEY_H

u32 GetMoney(u32* moneyPtr);
void SetMoney(u32* moneyPtr, u32 newValue);
bool8 IsEnoughMoney(u32* moneyPtr, u32 cost);
void AddMoney(u32* moneyPtr, u32 toAdd);
void SubtractMoney(u32* moneyPtr, u32 toSub);

#endif // GUARD_MONEY_H

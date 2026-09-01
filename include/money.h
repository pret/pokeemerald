#ifndef GUARD_MONEY_H
#define GUARD_MONEY_H

#define MAX_MONEY 999999 // Can be increased to INT_MAX

#define MAX_MONEY_DIGITS ((MAX_MONEY > 999999999) ? 10 : \
        (MAX_MONEY > 99999999) ? 9 : \
        (MAX_MONEY > 9999999) ? 8 : \
        (MAX_MONEY > 999999) ? 7 : \
        (MAX_MONEY > 99999) ? 6 : \
        (MAX_MONEY > 9999) ? 5 : \
        (MAX_MONEY > 999) ? 4 : \
        (MAX_MONEY > 99) ? 3 : \
        (MAX_MONEY > 9) ? 2 : 1)

u32 GetMoney(u32 *moneyPtr);
void SetMoney(u32 *moneyPtr, u32 newValue);
bool8 IsEnoughMoney(u32 *moneyPtr, u32 cost);
void AddMoney(u32 *moneyPtr, u32 toAdd);
void RemoveMoney(u32 *moneyPtr, u32 toSub);
bool8 IsEnoughForCostInVar0x8005(void);
void SubtractMoneyFromVar0x8005(void);
void PrintMoneyAmountInMoneyBox(u8 windowId, int amount, u8 speed);
void PrintMoneyAmount(u8 windowId, u8 x, u8 y, int amount, u8 speed);
void PrintMoneyAmountInMoneyBoxWithBorder(u8 windowId, u16 tileStart, u8 pallete, int amount);
void ChangeAmountInMoneyBox(int amount);
void DrawMoneyBox(int amount, u8 x, u8 y);
void HideMoneyBox(void);
void AddMoneyLabelObject(u16 x, u16 y);
void RemoveMoneyLabelObject(void);
u32 CalculateMoneyTextHorizontalPosition(u32 amount);

#endif // GUARD_MONEY_H

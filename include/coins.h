#ifndef GUARD_COINS_H
#define GUARD_COINS_H

void PrintCoinsString(u32 coinAmount);
void ShowCoinsWindow(u32 coinAmount, u8 x, u8 y);
void HideCoinsWindow(void);
u16 GetCoins(void);
void SetCoins(u16 coinAmount);
bool8 AddCoins(u16 toAdd);
bool8 RemoveCoins(u16 toSub);

#endif // GUARD_COINS_H

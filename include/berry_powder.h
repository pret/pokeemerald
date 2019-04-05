#ifndef GUARD_BERRY_POWDER_H
#define GUARD_BERRY_POWDER_H

void SetBerryPowder(u32 *powder, u32 amount);
void ApplyNewEncryptionKeyToBerryPowder(u32 encryptionKey);
bool8 GiveBerryPowder(u32 amountToAdd);
u32 GetBerryPowder(void);

#endif // GUARD_BERRY_POWDER_H

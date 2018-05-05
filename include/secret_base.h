#ifndef GUARD_SECRET_BASE_H
#define GUARD_SECRET_BASE_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void sub_80E9578(void);
void sub_80E980C(void);
u8 *GetSecretBaseMapName(u8 *dest);
const u8 *GetSecretBaseTrainerLoseText(void);
bool8 CurrentMapIsSecretBase(void);

#endif //GUARD_SECRET_BASE_H

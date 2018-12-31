#ifndef GUARD_SECRET_BASE_H
#define GUARD_SECRET_BASE_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void sub_80E9578(void);
void sub_80E980C(void);
void sub_80EB18C(struct SecretBaseRecord *dest);
void sub_80E9914(void);
u8 *GetSecretBaseMapName(u8 *dest);
const u8 *GetSecretBaseTrainerLoseText(void);
void sub_80E8EE0(struct MapEvents const *events);
void sub_80E9238(u8 flagIn);
bool8 CurrentMapIsSecretBase(void);
void SecretBasePerStepCallback(u8 taskId);
bool8 sub_80E9680(void);
void sub_80EB498(void);
void sub_80EB56C(void);
void sub_80EB9E0(void);
void sub_80EBB28(void);
void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events);

// SetCurrentSecretBaseFromPosition
void sub_80E9608(const struct MapPosition *position, const struct MapEvents *events);
// SetCurrentSecretBaseVar
void sub_80E8B6C(void);
void sub_80E8BC8(void);
void sub_80E8D4C(void);
void EnableBothScriptContexts(void);

#endif //GUARD_SECRET_BASE_H

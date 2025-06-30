#ifndef GUARD_SECRET_BASE_H
#define GUARD_SECRET_BASE_H

void HideSecretBaseDecorationSprites(void);
void CopyCurSecretBaseOwnerName_StrVar1(void);
void ClearJapaneseSecretBases(struct SecretBase *bases);
void SetPlayerSecretBaseParty(void);
u8 *GetSecretBaseMapName(u8 *dest);
const u8 *GetSecretBaseTrainerLoseText(void);
void SetOccupiedSecretBaseEntranceMetatiles(struct MapEvents const *events);
void InitSecretBaseAppearance(bool8 hidePC);
bool8 CurMapIsSecretBase(void);
void SecretBasePerStepCallback(u8 taskId);
bool8 TrySetCurSecretBase(void);
void CheckInteractedWithFriendsPosterDecor(void);
void CheckInteractedWithFriendsFurnitureBottom(void);
void CheckInteractedWithFriendsFurnitureMiddle(void);
void CheckInteractedWithFriendsFurnitureTop(void);
void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events);
bool8 SecretBaseMapPopupEnabled(void);
void CheckLeftFriendsSecretBase(void);
void ClearSecretBases(void);
void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events);
void TrySetCurSecretBaseIndex(void);
void CheckPlayerHasSecretBase(void);
void ToggleSecretBaseEntranceMetatile(void);
void ReceiveSecretBasesData(void *secretBases, size_t recordSize, u8 linkIdx);

#endif //GUARD_SECRET_BASE_H

#ifndef GUARD_BATTLE_TERASTAL_H
#define GUARD_BATTLE_TERASTAL_H

void PrepareBattlerForTera(u32 battler);
void ApplyBattlerVisualsForTeraAnim(u32 battler);
bool32 CanTerastallize(u32 battler);
u32 GetBattlerTeraType(u32 battler);
bool32 IsTerastallized(u32 battler);
void ExpendTypeStellarBoost(u32 battler, u32 type);
bool32 IsTypeStellarBoosted(u32 battler, u32 type);
uq4_12_t GetTeraMultiplier(u32 battler, u32 type);

u16 GetTeraTypeRGB(u32 type);

void ChangeTeraTriggerSprite(u8 spriteId, u8 animId);
void CreateTeraTriggerSprite(u8 battler, u8 palId);
bool32 IsTeraTriggerSpriteActive(void);
void HideTeraTriggerSprite(void);
void DestroyTeraTriggerSprite(void);

void TeraIndicator_LoadSpriteGfx(void);
bool32 TeraIndicator_ShouldBeInvisible(u32 battler);
u8 TeraIndicator_GetSpriteId(u32 healthboxSpriteId);
void TeraIndicator_SetVisibilities(u32 healthboxId, bool32 invisible);
void TeraIndicator_UpdateOamPriorities(u32 healthboxId, u32 oamPriority);
void TeraIndicator_UpdateLevel(u32 healthboxId, u32 level);
void TeraIndicator_CreateSprite(u32 battler, u32 healthboxSpriteId);
void TeraIndicator_DestroySprite(u32 healthboxSpriteId);
void TeraIndicator_UpdateType(u32 battler, u32 healthboxSpriteId);

#endif

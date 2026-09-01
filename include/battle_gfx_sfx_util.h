#ifndef GUARD_BATTLE_GFX_SFX_UTIL_H
#define GUARD_BATTLE_GFX_SFX_UTIL_H

void AllocateBattleSpritesData(void);
void FreeBattleSpritesData(void);
u16 ChooseMoveAndTargetInBattlePalace(enum BattlerId battler);
void SpriteCB_WaitForBattlerBallReleaseAnim(struct Sprite *sprite);
void SpriteCB_TrainerSlideIn(struct Sprite *sprite);
void SpriteCB_TrainerSpawn(struct Sprite *sprite);
void InitAndLaunchChosenStatusAnimation(enum BattlerId battler, bool32 isVolatile, u32 status);
bool8 TryHandleLaunchBattleTableAnimation(u8 activeBattlerId, u8 attacker, u8 target, u8 tableId, u16 argument);
void InitAndLaunchSpecialAnimation(enum BattlerId activeBattlerId, enum BattlerId attacker, enum BattlerId target, u8 tableId);
bool8 IsBattleSEPlaying(enum BattlerId battler);
void BattleLoadMonSpriteGfx(struct Pokemon *mon, enum BattlerId battler);
void DecompressGhostFrontPic(enum BattlerId battler);
void BattleGfxSfxDummy2(enum Species species);
void DecompressTrainerFrontPic(enum TrainerPicID trainerPicId, enum BattlerId battler);
void FreeTrainerFrontPicPalette(enum TrainerPicID trainerPicId);
bool8 BattleLoadAllHealthBoxesGfx(u8 state);
void LoadBattleBarGfx(u8 unused);
bool8 BattleInitAllSprites(u8 *state1, u8 *battler);
void ClearSpritesHealthboxAnimData(void);
void CopyAllBattleSpritesInvisibilities(void);
void CopyBattleSpriteInvisibility(enum BattlerId battler);
void HandleSpeciesGfxDataChange(enum BattlerId battlerAtk, enum BattlerId battlerDef, u8 changeType);
void BattleLoadSubstituteOrMonSpriteGfx(enum BattlerId battler, bool8 loadMonSprite);
void LoadBattleMonGfxAndAnimate(enum BattlerId battler, bool8 loadMonSprite, u8 spriteId);
void TrySetBehindSubstituteSpriteBit(enum BattlerId battler, enum Move move);
void ClearBehindSubstituteBit(enum BattlerId battler);
void HandleLowHpMusicChange(struct Pokemon *mon, enum BattlerId battler);
void BattleStopLowHpSound(void);
void HandleBattleLowHpMusicChange(void);
void SetBattlerSpriteAffineMode(u8 affineMode);
void CreateEnemyShadowSprite(enum BattlerId battler);
void LoadAndCreateEnemyShadowSprites(void);
void SpriteCB_SetInvisible(struct Sprite *sprite);
void SetBattlerShadowSpriteCallback(enum BattlerId battler, enum Species species);
void HideBattlerShadowSprite(enum BattlerId battler);
void FillAroundBattleWindows(void);
void ClearTemporarySpeciesSpriteData(enum BattlerId battler, bool32 dontClearTransform, bool32 dontClearSubstitute);
void AllocateMonSpritesGfx(void);
void FreeMonSpritesGfx(void);
bool32 ShouldPlayNormalMonCry(struct Pokemon *mon);

#endif // GUARD_BATTLE_GFX_SFX_UTIL_H

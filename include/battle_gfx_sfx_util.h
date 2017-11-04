#ifndef GUARD_BATTLE_GFX_SFX_UTIL
#define GUARD_BATTLE_GFX_SFX_UTIL

void AllocateBattleSpritesData(void);
void FreeBattleSpritesData(void);
void sub_805D714(struct Sprite *sprite);
void sub_805D770(struct Sprite *sprite, bool8 arg1);
void sub_805D7AC(struct Sprite *sprite);
void InitAndLaunchChosenStatusAnimation(bool8 isStatus2, u32 status);
bool8 TryHandleLaunchBattleTableAnimation(u8 activeBank, u8 atkBank, u8 defBank, u8 tableId, u16 argument);
void InitAndLaunchSpecialAnimation(u8 activeBank, u8 atkBank, u8 defBank, u8 tableId);
bool8 IsMoveWithoutAnimation(u16 moveId, u8 animationTurn);
bool8 mplay_80342A4(u8 bank);
void BattleLoadOpponentMonSpriteGfx(struct Pokemon *mon, u8 bank);
void BattleLoadPlayerMonSpriteGfx(struct Pokemon *mon, u8 bank);
void nullsub_23(void);
void nullsub_24(u16 species);
void DecompressTrainerFrontPic(u16 frontPicId, u8 bank);
void DecompressTrainerBackPic(u16 backPicId, u8 bank);
void nullsub_25(u8 arg0);
void FreeTrainerFrontPicPalette(u16 frontPicId);
void sub_805DFFC(void);
bool8 BattleLoadAllHealthBoxesGfx(u8 state);
void LoadBattleBarGfx(u8 arg0);
bool8 BattleInitAllSprites(u8 *state1, u8 *bank);
void ClearSpritesHealthboxAnimData(void);
void CopyAllBattleSpritesInvisibilities(void);
void CopyBattleSpriteInvisibility(u8 bank);
void HandleSpeciesGfxDataChange(u8 bankAtk, u8 bankDef, bool8 notTransform);
void BattleLoadSubstituteOrMonSpriteGfx(u8 bank, bool8 loadMonSprite);
void LoadBattleMonGfxAndAnimate(u8 bank, bool8 loadMonSprite, u8 spriteId);
void TrySetBehindSubstituteSpriteBit(u8 bank, u16 move);
void ClearBehindSubstituteBit(u8 bank);
void HandleLowHpMusicChange(struct Pokemon *mon, u8 bank);
void BattleStopLowHpSound(void);
u8 GetMonHPBarLevel(struct Pokemon *mon);
void sub_805EAE8(void);
void sub_805EB9C(u8 affineMode);
void LoadAndCreateEnemyShadowSprites(void);
void SpriteCB_SetInvisible(struct Sprite *sprite);
void SetBankEnemyShadowSpriteCallback(u8 bank, u16 species);
void EnemyShadowCallbackToSetInvisible(u8 bank);
void sub_805EF14(void);
void ClearTemporarySpeciesSpriteData(u8 bank, bool8 dontClearSubstitute);
void AllocateMonSpritesGfx(void);
void FreeMonSpritesGfx(void);
bool32 ShouldPlayNormalPokeCry(struct Pokemon *mon);

#endif // GUARD_BATTLE_GFX_SFX_UTIL

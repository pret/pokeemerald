#ifndef GUARD_BATTLE_GIMMICK_H
#define GUARD_BATTLE_GIMMICK_H

#include "constants/trainer_slide.h"

enum Gimmick
{
    GIMMICK_NONE,
    GIMMICK_MEGA,
    GIMMICK_ULTRA_BURST,
    GIMMICK_Z_MOVE,
    GIMMICK_DYNAMAX,
    GIMMICK_TERA,
    GIMMICKS_COUNT,
};

struct GimmickInfo
{
    const struct SpritePalette *triggerPal;        // trigger gfx data
    const struct SpriteSheet *triggerSheet;
    const struct SpriteTemplate *triggerTemplate;
    const u32 indicatorPalTag;
    const u8 *indicatorData;
    bool32 (*CanActivate)(enum BattlerId battler);
    void (*ActivateGimmick)(enum BattlerId battler);
    enum TrainerSlideType attackerSlideType;
    enum TrainerSlideType opponentSlideType;
};

void AssignUsableGimmicks(void);
bool32 CanActivateGimmick(enum BattlerId battler, enum Gimmick gimmick);
bool32 IsGimmickSelected(enum BattlerId battler, enum Gimmick gimmick);
void SetActiveGimmick(enum BattlerId battler, enum Gimmick gimmick);
enum Gimmick GetActiveGimmick(enum BattlerId battler);
bool32 ShouldTrainerBattlerUseGimmick(enum BattlerId battler, enum Gimmick gimmick);
bool32 HasTrainerUsedGimmick(enum BattlerId battler, enum Gimmick gimmick);
void SetGimmickAsActivated(enum BattlerId battler, enum Gimmick gimmick);

void ChangeGimmickTriggerSprite(u32 spriteId, u32 animId);
void CreateGimmickTriggerSprite(enum BattlerId battler);
bool32 IsGimmickTriggerSpriteActive(void);
bool32 IsGimmickTriggerSpriteMatchingBattler(enum BattlerId battler);
void HideGimmickTriggerSprite(void);
void DestroyGimmickTriggerSprite(void);

void LoadIndicatorSpritesGfx(void);
u32 GetIndicatorPalTag(enum BattlerId battler);
void UpdateIndicatorVisibilityAndType(u32 healthboxId, bool32 invisible);
void UpdateIndicatorOamPriority(u32 healthboxId, u32 oamPriority);
void UpdateIndicatorLevelData(u32 healthboxId, u32 level);
void CreateIndicatorSprite(enum BattlerId battler);

extern const struct GimmickInfo gGimmicksInfo[];

#endif

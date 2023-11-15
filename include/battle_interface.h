#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

#include "battle_controllers.h"

enum
{
    HP_CURRENT,
    HP_MAX,
    HP_BOTH
};

enum
{
    HEALTH_BAR,
    EXP_BAR
};

enum
{
    HP_BAR_EMPTY,
    HP_BAR_RED,
    HP_BAR_YELLOW,
    HP_BAR_GREEN,
    HP_BAR_FULL,
};

#define TAG_HEALTHBOX_PLAYER1_TILE      0xD6FF
#define TAG_HEALTHBOX_PLAYER2_TILE      0xD700
#define TAG_HEALTHBOX_OPPONENT1_TILE    0xD701
#define TAG_HEALTHBOX_OPPONENT2_TILE    0xD702

#define TAG_HEALTHBAR_PLAYER1_TILE      0xD704
#define TAG_HEALTHBAR_OPPONENT1_TILE    0xD705
#define TAG_HEALTHBAR_PLAYER2_TILE      0xD706
#define TAG_HEALTHBAR_OPPONENT2_TILE    0xD707

#define TAG_HEALTHBOX_PALS_1            0xD709
#define TAG_HEALTHBOX_PALS_2            0xD70A
#define TAG_HEALTHBOX_SAFARI_TILE       0xD70B
#define TAG_STATUS_SUMMARY_BAR_TILE     0xD70C

#define TAG_STATUS_SUMMARY_BAR_PAL      0xD710
#define TAG_STATUS_SUMMARY_BALLS_PAL    0xD712

#define TAG_STATUS_SUMMARY_BALLS_TILE   0xD714

#define TAG_HEALTHBAR_PAL               TAG_HEALTHBAR_PLAYER1_TILE
#define TAG_HEALTHBOX_PAL               TAG_HEALTHBOX_PLAYER1_TILE

#define TAG_MEGA_TRIGGER_TILE           0xD777
#define TAG_MEGA_INDICATOR_TILE         0xD778
#define TAG_ALPHA_INDICATOR_TILE        0xD779
#define TAG_OMEGA_INDICATOR_TILE        0xD77A
#define TAG_ZMOVE_TRIGGER_TILE          0xD77B
#define TAG_BURST_TRIGGER_TILE          0xD77C

#define TAG_MEGA_TRIGGER_PAL            0xD777
#define TAG_MEGA_INDICATOR_PAL          0xD778
#define TAG_ALPHA_OMEGA_INDICATOR_PAL   0xD779 // Alpha and Omega indicators use the same palette as each of them only uses 4 different colors.
#define TAG_ZMOVE_TRIGGER_PAL           0xD77B
#define TAG_BURST_TRIGGER_PAL           0xD77C

enum
{
    HEALTHBOX_ALL,
    HEALTHBOX_CURRENT_HP,
    HEALTHBOX_MAX_HP,
    HEALTHBOX_LEVEL,
    HEALTHBOX_NICK,
    HEALTHBOX_HEALTH_BAR,
    HEALTHBOX_EXP_BAR,
    HEALTHBOX_UNUSED_7,
    HEALTHBOX_UNUSED_8,
    HEALTHBOX_STATUS_ICON,
    HEALTHBOX_SAFARI_ALL_TEXT,
    HEALTHBOX_SAFARI_BALLS_TEXT
};

u32 WhichBattleCoords(u32 battlerId);
u8 CreateBattlerHealthboxSprites(u8 battler);
u8 CreateSafariPlayerHealthboxSprites(void);
void SetBattleBarStruct(u8 battler, u8 healthboxSpriteId, s32 maxVal, s32 currVal, s32 receivedValue);
void SetHealthboxSpriteInvisible(u8 healthboxSpriteId);
void SetHealthboxSpriteVisible(u8 healthboxSpriteId);
void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly);
void UpdateOamPriorityInAllHealthboxes(u8 priority, bool32 hideHpBoxes);
void InitBattlerHealthboxCoords(u8 battler);
void UpdateHpTextInHealthbox(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp);
void SwapHpBarsWithHpText(void);
void ChangeMegaTriggerSprite(u8 spriteId, u8 animId);
void CreateMegaTriggerSprite(u8 battlerId, u8 palId);
bool32 IsMegaTriggerSpriteActive(void);
void HideMegaTriggerSprite(void);
void DestroyMegaTriggerSprite(void);
void ChangeBurstTriggerSprite(u8 spriteId, u8 animId);
void CreateBurstTriggerSprite(u8 battlerId, u8 palId);
bool32 IsBurstTriggerSpriteActive(void);
void HideBurstTriggerSprite(void);
void DestroyBurstTriggerSprite(void);
void MegaIndicator_LoadSpritesGfx(void);
u8 CreatePartyStatusSummarySprites(u8 battler, struct HpAndStatus *partyInfo, bool8 skipPlayer, bool8 isBattleStart);
void Task_HidePartyStatusSummary(u8 taskId);
void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
s32 MoveBattleBar(u8 battler, u8 healthboxSpriteId, u8 whichBar, u8 unused);
u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u8 GetHPBarLevel(s16 hp, s16 maxhp);
void CreateAbilityPopUp(u8 battlerId, u32 ability, bool32 isDoubleBattle);
void DestroyAbilityPopUp(u8 battlerId);
void HideTriggerSprites(void);
bool32 CanThrowLastUsedBall(void);
void TryHideLastUsedBall(void);
void TryRestoreLastUsedBall(void);
void TryAddLastUsedBallItemSprites(void);
void SwapBallToDisplay(bool32 sameBall);
void ArrowsChangeColorLastBallCycle(bool32 showArrows);
void UpdateAbilityPopup(u8 battlerId);

#endif // GUARD_BATTLE_INTERFACE_H

#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

#include "battle_controllers.h"

// used for sBattlerCoords and sBattlerHealthboxCoords
enum BattleCoordTypes
{
    BATTLE_COORDS_SINGLES,
    BATTLE_COORDS_DOUBLES,
    BATTLE_COORDS_COUNT,
};

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
#define TAG_SHADOW_PAL                  TAG_HEALTHBOX_PLAYER1_TILE

#define TAG_SHADOW_TILE                 0xD759

#define TAG_GIMMICK_TRIGGER_TILE        0xD777
#define TAG_MEGA_INDICATOR_TILE         0xD778
#define TAG_ALPHA_INDICATOR_TILE        0xD779
#define TAG_OMEGA_INDICATOR_TILE        0xD77A
#define TAG_DYNAMAX_INDICATOR_TILE      0xD77B

#define TAG_NORMAL_INDICATOR_TILE       0xD77C
#define TAG_FIGHTING_INDICATOR_TILE     0xD77D
#define TAG_FLYING_INDICATOR_TILE       0xD77E
#define TAG_POISON_INDICATOR_TILE       0xD77F
#define TAG_GROUND_INDICATOR_TILE       0xD780
#define TAG_ROCK_INDICATOR_TILE         0xD781
#define TAG_BUG_INDICATOR_TILE          0xD782
#define TAG_GHOST_INDICATOR_TILE        0xD783
#define TAG_STEEL_INDICATOR_TILE        0xD784
// empty spot for TYPE_MYSTERY
#define TAG_FIRE_INDICATOR_TILE         0xD786
#define TAG_WATER_INDICATOR_TILE        0xD787
#define TAG_GRASS_INDICATOR_TILE        0xD788
#define TAG_ELECTRIC_INDICATOR_TILE     0xD789
#define TAG_PSYCHIC_INDICATOR_TILE      0xD78A
#define TAG_ICE_INDICATOR_TILE          0xD78B
#define TAG_DRAGON_INDICATOR_TILE       0xD78C
#define TAG_DARK_INDICATOR_TILE         0xD78D
#define TAG_FAIRY_INDICATOR_TILE        0xD78E
#define TAG_STELLAR_INDICATOR_TILE      0xD78F
#define TAG_TERA_TRIGGER_TILE           0xD790

#define TAG_GIMMICK_TRIGGER_PAL         0xD777
#define TAG_MEGA_INDICATOR_PAL          0xD778
#define TAG_MISC_INDICATOR_PAL          0xD779 // Alpha, Omega, and Dynamax indicators use the same palette as each of them only uses 4 different colors.
#define TAG_TERA_INDICATOR_PAL          0xD77A

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

enum BattleCoordTypes GetBattlerCoordsIndex(enum BattlerId battler);
u8 CreateBattlerHealthboxSprites(enum BattlerId battler);
u8 CreateSafariPlayerHealthboxSprites(void);
void SetBattleBarStruct(enum BattlerId battler, u8 healthboxSpriteId, s32 maxVal, s32 oldVal, s32 receivedValue);
void SetHealthboxSpriteInvisible(u8 healthboxSpriteId);
void SetHealthboxSpriteVisible(u8 healthboxSpriteId);
void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBattlerOnly);
void UpdateOamPriorityInAllHealthboxes(u8 priority, bool32 hideHpBoxes);
void InitBattlerHealthboxCoords(enum BattlerId battler);
void GetBattlerHealthboxCoords(enum BattlerId battler, s16 *x, s16 *y);
void UpdateHpTextInHealthbox(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp);
void SwapHpBarsWithHpText(void);
u8 CreatePartyStatusSummarySprites(enum BattlerId battler, struct HpAndStatus *partyInfo, bool8 skipPlayer, bool8 isBattleStart);
void Task_HidePartyStatusSummary(u8 taskId);
void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
s32 MoveBattleBar(enum BattlerId battler, u8 healthboxSpriteId, u8 whichBar, u8 unused);
u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u8 GetHPBarLevel(s16 hp, s16 maxhp);
bool32 IsAnyAbilityPopUpActive(void);
void CreateAbilityPopUp(enum BattlerId battlerId, enum Ability ability, bool32 isDoubleBattle);
void DestroyAbilityPopUp(enum BattlerId battlerId);
bool32 CanThrowLastUsedBall(void);
void TryHideLastUsedBall(void);
void TryRestoreLastUsedBall(void);
void TryAddLastUsedBallItemSprites(void);
void SwapBallToDisplay(bool32 sameBall);
void ArrowsChangeColorLastBallCycle(bool32 showArrows);
void UpdateAbilityPopup(enum BattlerId battlerId);
void CategoryIcons_LoadSpritesGfx(void);
void TryToAddMoveInfoWindow(void);
void TryToHideMoveInfoWindow(void);
void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus);
void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon);
void CreateItemPopUp(enum BattlerId battlerId);
void FreeAbilityPopUpGfx(void);

#endif // GUARD_BATTLE_INTERFACE_H

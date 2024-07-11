#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "constants/battle_script_commands.h"

// Arguments for 'flags' in HandleBattleWindow
#define WINDOW_CLEAR (1 << 0)
#define WINDOW_BG1   (1 << 7)

// Arguments for 'xStart, yStart, xEnd, yEnd' in HandleBattleWindow
#define YESNOBOX_X_Y 24, 8, 29, 13

struct StatFractions
{
    u8 dividend;
    u8 divisor;
};

struct PickupItem
{
    u16 itemId;
    u8 percentage[10];
};

s32 CalcCritChanceStageArgs(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility, u32 abilityAtk, u32 abilityDef, u32 holdEffectAtk);
s32 CalcCritChanceStage(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility);
s32 GetCritHitOdds(s32 critChanceIndex);
u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move, u32 atkAbility, u32 defAbility, u32 atkHoldEffect, u32 defHoldEffect);
u8 GetBattlerTurnOrderNum(u8 battlerId);
bool32 NoAliveMonsForPlayer(void);
bool32 NoAliveMonsForEitherParty(void);
void SetMoveEffect(bool32 primary, bool32 certain);
bool32 CanBattlerSwitch(u32 battlerId);
void BattleDestroyYesNoCursorAt(u8 cursorPosition);
void BattleCreateYesNoCursorAt(u8 cursorPosition);
void BufferMoveToLearnIntoBattleTextBuff2(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 UproarWakeUpCheck(u8 battlerId);
bool32 DoesSubstituteBlockMove(u32 battlerAtk, u32 battlerDef, u32 move);
bool32 DoesDisguiseBlockMove(u32 battler, u32 move);
bool32 CanPoisonType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanParalyzeType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanUseLastResort(u8 battlerId);
u32 IsFlowerVeilProtected(u32 battler);
u32 IsLeafGuardProtected(u32 battler);
bool32 IsShieldsDownProtected(u32 battler);
u32 IsAbilityStatusProtected(u32 battler);
bool32 TryResetBattlerStatChanges(u8 battler);
bool32 CanCamouflage(u8 battlerId);
u32 GetNaturePowerMove(u32 battler);
void StealTargetItem(u8 battlerStealer, u8 battlerItem);
u8 GetCatchingBattler(void);
u32 GetHighestStatId(u32 battlerId);
bool32 ProteanTryChangeType(u32 battler, u32 ability, u32 move, u32 moveType);
bool32 ShouldTeraShellDistortTypeMatchups(u32 move, u32 battlerDef);
bool32 IsMoveNotAllowedInSkyBattles(u32 move);
bool32 DoSwitchInAbilities(u32 battlerId);
u8 GetFirstFaintedPartyIndex(u8 battlerId);
bool32 IsMoveAffectedByParentalBond(u32 move, u32 battler);

extern void (* const gBattleScriptingCommandsTable[])(void);
extern const struct StatFractions gAccuracyStageRatios[];

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H

#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "constants/battle_script_commands.h"
#include "battle_set_effect.h"

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
    enum Item itemId;
    u8 percentage[10];
};

bool32 HasBattlerActedThisTurn(enum BattlerId battler);
u32 GetBattlerTurnOrderNum(enum BattlerId battler);
u32 GetBattlerRawSpeedOrder(enum BattlerId battler);
bool32 NoAliveMonsForBattlerSide(enum BattlerId battler);
bool32 NoAliveMonsForPlayer(void);
bool32 NoAliveMonsForEitherParty(void);
bool32 TrySetReflect(enum BattlerId battler);
bool32 TrySetLightScreen(enum BattlerId battler);
void TrySynchronizeActivation(enum BattlerId battlerAtk, enum BattlerId effectBattler, enum MoveEffect effect);
void SetNonVolatileStatus(enum BattlerId battlerAtk, enum BattlerId effectBattler, enum MoveEffect effect, const u8 *battleScript, enum StatusTrigger trigger);
bool32 CanBattlerSwitch(enum BattlerId battlerId);
void BattleDestroyYesNoCursorAt(u8 cursorPosition);
void BattleCreateYesNoCursorAt(u8 cursorPosition);
void BufferMoveToLearnIntoBattleTextBuff2(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 UproarWakeUpCheck(enum BattlerId battler);
bool32 DoesSubstituteBlockMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 IsSubstituteProtected(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Move move);
bool32 DoesDisguiseBlockMove(enum BattlerId battler, enum Move move);
bool32 DoesIceFaceBlockMove(enum BattlerId battler, enum Move move);
bool32 CanUseLastResort(enum BattlerId battlerId);
bool32 TryDefogClear(enum BattlerId battlerAtk, bool32 clear);
bool32 TryTidyUpClear(bool32 clear);
u32 IsFlowerVeilProtected(enum BattlerId battler);
u32 IsLeafGuardProtected(enum BattlerId battler, enum Ability ability);
bool32 IsShieldsDownProtected(enum BattlerId battler, enum Ability ability);
u32 IsAbilityStatusProtected(enum BattlerId battler, enum Ability ability);
bool32 TryResetBattlerStatChanges(enum BattlerId battler);
bool32 CanCamouflage(enum BattlerId battler);
void StealTargetItem(enum BattlerId battlerStealer, enum BattlerId battlerItem, enum Item itemOverride);
u8 GetCatchingBattler(void);
bool32 ProteanTryChangeType(enum BattlerId battler, enum Ability ability, enum Move move, enum Type moveType);
u8 GetFirstFaintedPartyIndex(enum BattlerId battler);
void SaveBattlerTarget(enum BattlerId battler);
void SaveBattlerAttacker(enum BattlerId battler);
void RestoreAttacker(void);
void RestoreTarget(void);
bool32 CanBurnHitThaw(enum Move move);
bool32 CanMoveThawTarget(enum Ability abilityAtk, enum Move move);
bool32 CanFireMoveThawTarget(enum Move move, enum Type moveType);

extern void (*const gBattleScriptingCommandsTable[])(void);
extern const struct StatFractions gAccuracyStageRatios[];

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H

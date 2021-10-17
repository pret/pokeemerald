#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_pyramid.h"
#include "battle_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "party_menu.h"
#include "pokemon.h"
#include "international_string_util.h"
#include "item.h"
#include "util.h"
#include "battle_scripts.h"
#include "random.h"
#include "text.h"
#include "safari_zone.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "window.h"
#include "battle_message.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "event_data.h"
#include "link.h"
#include "malloc.h"
#include "berry.h"
#include "pokedex.h"
#include "mail.h"
#include "field_weather.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_config.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"

extern struct Evolution gEvolutionTable[][EVOS_PER_MON];

/*
NOTE: The data and functions in this file up until (but not including) sSoundMovesTable
are actually part of battle_main.c. They needed to be moved to this file in order to
match the ROM; this is also why sSoundMovesTable's declaration is in the middle of
functions instead of at the top of the file with the other declarations.
*/

static bool32 TryRemoveScreens(u8 battler);
static bool32 IsUnnerveAbilityOnOpposingSide(u8 battlerId);

extern const u8 *const gBattleScriptsForMoveEffects[];
extern const u8 *const gBattlescriptsForBallThrow[];
extern const u8 *const gBattlescriptsForRunningByItem[];
extern const u8 *const gBattlescriptsForUsingItem[];
extern const u8 *const gBattlescriptsForSafariActions[];

static const u8 sPkblToEscapeFactor[][3] = {
    {
        [B_MSG_MON_CURIOUS]    = 0,
        [B_MSG_MON_ENTHRALLED] = 0,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 3,
        [B_MSG_MON_ENTHRALLED] = 5,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 2,
        [B_MSG_MON_ENTHRALLED] = 3,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 2,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 1,
        [B_MSG_MON_IGNORED]    = 0
    }
};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

static const u16 sSkillSwapBannedAbilities[] =
{
    ABILITY_WONDER_GUARD,
    ABILITY_MULTITYPE,
    ABILITY_ILLUSION,
    ABILITY_STANCE_CHANGE,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_NEUTRALIZING_GAS,
    ABILITY_ICE_FACE,
    ABILITY_HUNGER_SWITCH,
    ABILITY_GULP_MISSILE,
};

static const u16 sRolePlayBannedAbilities[] =
{
    ABILITY_TRACE,
    ABILITY_WONDER_GUARD,
    ABILITY_FORECAST,
    ABILITY_FLOWER_GIFT,
    ABILITY_MULTITYPE,
    ABILITY_ILLUSION,
    ABILITY_ZEN_MODE,
    ABILITY_IMPOSTER,
    ABILITY_STANCE_CHANGE,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_RECEIVER,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_ICE_FACE,
    ABILITY_HUNGER_SWITCH,
    ABILITY_GULP_MISSILE,
};

static const u16 sRolePlayBannedAttackerAbilities[] =
{
    ABILITY_MULTITYPE,
    ABILITY_ZEN_MODE,
    ABILITY_STANCE_CHANGE,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_ICE_FACE,
    ABILITY_GULP_MISSILE,
};

static const u16 sWorrySeedBannedAbilities[] =
{
    ABILITY_MULTITYPE,
    ABILITY_STANCE_CHANGE,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_TRUANT,
    ABILITY_ICE_FACE,
    ABILITY_GULP_MISSILE,
};

static const u16 sGastroAcidBannedAbilities[] =
{
    ABILITY_AS_ONE_ICE_RIDER,
    ABILITY_AS_ONE_SHADOW_RIDER,
    ABILITY_BATTLE_BOND,
    ABILITY_COMATOSE,
    ABILITY_DISGUISE,
    ABILITY_GULP_MISSILE,
    ABILITY_ICE_FACE,
    ABILITY_MULTITYPE,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_RKS_SYSTEM,
    ABILITY_SCHOOLING,
    ABILITY_SHIELDS_DOWN,
    ABILITY_STANCE_CHANGE,
    ABILITY_ZEN_MODE,
};

static const u16 sEntrainmentBannedAttackerAbilities[] =
{
    ABILITY_TRACE,
    ABILITY_FORECAST,
    ABILITY_FLOWER_GIFT,
    ABILITY_ZEN_MODE,
    ABILITY_ILLUSION,
    ABILITY_IMPOSTER,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_RECEIVER,
    ABILITY_DISGUISE,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_NEUTRALIZING_GAS,
    ABILITY_ICE_FACE,
    ABILITY_HUNGER_SWITCH,
    ABILITY_GULP_MISSILE,
};

static const u16 sEntrainmentTargetSimpleBeamBannedAbilities[] =
{
    ABILITY_TRUANT,
    ABILITY_MULTITYPE,
    ABILITY_STANCE_CHANGE,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_ICE_FACE,
    ABILITY_GULP_MISSILE,
};

bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move)
{
    u32 ability = GetBattlerAbility(battlerAtk);

    if (gSideTimers[defSide].followmeTimer == 0
        || gBattleMons[gSideTimers[defSide].followmeTarget].hp == 0
        || gBattleMoves[move].effect == EFFECT_SNIPE_SHOT
        || ability == ABILITY_PROPELLER_TAIL || ability == ABILITY_STALWART)
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowder(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk, TRUE)))
        return FALSE;

    return TRUE;
}

// Functions
void HandleAction_UseMove(void)
{
    u32 i, side, moveType, var = 4;

    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gBattleStruct->field_91 & gBitTable[gBattlerAttacker] || !IsBattlerAlive(gBattlerAttacker))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gIsCriticalHit = FALSE;
    gBattleStruct->atkCancellerTracker = 0;
    gMoveResultFlags = 0;
    gMultiHitCounter = 0;
    gBattleCommunication[6] = 0;
    gBattleScripting.savedMoveEffect = 0;
    gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = 0;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(MOVE_STRUGGLE, 0);
    }
    else if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
          && gDisableStructs[gBattlerAttacker].encoredMove == gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrentMove = gChosenMove = gDisableStructs[gBattlerAttacker].encoredMove;
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
          && gDisableStructs[gBattlerAttacker].encoredMove != gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gDisableStructs[gBattlerAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].encoredMovePos = 0;
        gDisableStructs[gBattlerAttacker].encoreTimer = 0;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gChosenMoveByBattler[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    if (gBattleMons[gBattlerAttacker].hp != 0)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    // Set dynamic move type.
    SetTypeBeforeUsingMove(gChosenMove, gBattlerAttacker);
    GET_MOVE_TYPE(gChosenMove, moveType);

    // choose target
    side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
    if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove)
        && gBattleMoves[gCurrentMove].target == MOVE_TARGET_SELECTED
        && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gSideTimers[side].followmeTarget))
    {
        gBattlerTarget = gSideTimers[side].followmeTarget;
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
           && gSideTimers[side].followmeTimer == 0
           && (gBattleMoves[gCurrentMove].power != 0 || gBattleMoves[gCurrentMove].target != MOVE_TARGET_USER)
           && ((gBattleMons[*(gBattleStruct->moveTarget + gBattlerAttacker)].ability != ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
            || (gBattleMons[*(gBattleStruct->moveTarget + gBattlerAttacker)].ability != ABILITY_STORM_DRAIN && moveType == TYPE_WATER)))
    {
        side = GetBattlerSide(gBattlerAttacker);
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (side != GetBattlerSide(gActiveBattler)
                && *(gBattleStruct->moveTarget + gBattlerAttacker) != gActiveBattler
                && ((GetBattlerAbility(gActiveBattler) == ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
                 || (GetBattlerAbility(gActiveBattler) == ABILITY_STORM_DRAIN && moveType == TYPE_WATER))
                && GetBattlerTurnOrderNum(gActiveBattler) < var
                && gBattleMoves[gCurrentMove].effect != EFFECT_SNIPE_SHOT
                && (GetBattlerAbility(gBattlerAttacker) != ABILITY_PROPELLER_TAIL
                 || GetBattlerAbility(gBattlerAttacker) != ABILITY_STALWART))
            {
                var = GetBattlerTurnOrderNum(gActiveBattler);
            }
        }
        if (var == 4)
        {
            if (gBattleMoves[gChosenMove].target & MOVE_TARGET_RANDOM)
            {
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                }
                else
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
                }
            }
            else if (gBattleMoves[gChosenMove].target & MOVE_TARGET_FOES_AND_ALLY)
            {
                for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
                {
                    if (gBattlerTarget == gBattlerAttacker)
                        continue;
                    if (IsBattlerAlive(gBattlerTarget))
                        break;
                }
            }
            else
            {
                gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
            }

            if (!IsBattlerAlive(gBattlerTarget))
            {
                if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
                else
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                    if (!IsBattlerAlive(gBattlerTarget))
                        gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
            }
        }
        else
        {
            gActiveBattler = gBattlerByTurnOrder[var];
            RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
            if (gBattleMons[gActiveBattler].ability == ABILITY_LIGHTNING_ROD)
                gSpecialStatuses[gActiveBattler].lightningRodRedirected = 1;
            else if (gBattleMons[gActiveBattler].ability == ABILITY_STORM_DRAIN)
                gSpecialStatuses[gActiveBattler].stormDrainRedirected = 1;
            gBattlerTarget = gActiveBattler;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
          && gBattleMoves[gChosenMove].target & MOVE_TARGET_RANDOM)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget]
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
        {
            gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
        }
    }
    else if (gBattleMoves[gChosenMove].target == MOVE_TARGET_ALLY)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            gBattlerTarget = BATTLE_PARTNER(gBattlerAttacker);
        else
            gBattlerTarget = gBattlerAttacker;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
          && gBattleMoves[gChosenMove].target == MOVE_TARGET_FOES_AND_ALLY)
    {
        for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
        {
            if (gBattlerTarget == gBattlerAttacker)
                continue;
            if (IsBattlerAlive(gBattlerTarget))
                break;
        }
    }
    else
    {
        gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
        if (!IsBattlerAlive(gBattlerTarget))
        {
            if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
            else
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                if (!IsBattlerAlive(gBattlerTarget))
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE && gProtectStructs[gBattlerAttacker].palaceUnableToUseMove)
    {
        // Battle Palace, select battle script for failure to use move
        if (gBattleMons[gBattlerAttacker].hp == 0)
        {
            gCurrentActionFuncId = B_ACTION_FINISHED;
            return;
        }
        else if (gPalaceSelectionBattleScripts[gBattlerAttacker] != NULL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = gPalaceSelectionBattleScripts[gBattlerAttacker];
            gPalaceSelectionBattleScripts[gBattlerAttacker] = NULL;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
        }
    }
    else
    {
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddMindPoints(gBattlerAttacker);

    // Record HP of each battler
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        gBattleStruct->hpBefore[i] = gBattleMons[i].hp;

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gBattleStruct->field_58 + gBattlerAttacker))

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;

    UndoFormChange(gBattlerPartyIndexes[gBattlerAttacker], GetBattlerSide(gBattlerAttacker), TRUE);
}

void HandleAction_UseItem(void)
{
    gBattlerAttacker = gBattlerTarget = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);

    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][1] | (gBattleResources->bufferB[gBattlerAttacker][2] << 8);

    if (gLastUsedItem <= LAST_BALL) // is ball
    {
        gBattlescriptCurrInstr = gBattlescriptsForBallThrow[gLastUsedItem];
    }
    else if (gLastUsedItem == ITEM_POKE_DOLL || gLastUsedItem == ITEM_FLUFFY_TAIL)
    {
        gBattlescriptCurrInstr = gBattlescriptsForRunningByItem[0];
    }
    else if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
    {
        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[0];
    }
    else
    {
        gBattleScripting.battler = gBattlerAttacker;

        switch (*(gBattleStruct->AI_itemType + (gBattlerAttacker >> 1)))
        {
        case AI_ITEM_FULL_RESTORE:
        case AI_ITEM_HEAL_HP:
            break;
        case AI_ITEM_CURE_CONDITION:
            gBattleCommunication[MULTISTRING_CHOOSER] = AI_HEAL_CONFUSION;
            if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & (1 << AI_HEAL_CONFUSION))
            {
                if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 0x3E)
                    gBattleCommunication[MULTISTRING_CHOOSER] = AI_HEAL_SLEEP;
            }
            else
            {
                // Check for other statuses, stopping at first (shouldn't be more than one)
                while (!(*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleCommunication[MULTISTRING_CHOOSER]++;
                    // MULTISTRING_CHOOSER will be either AI_HEAL_PARALYSIS, AI_HEAL_FREEZE,
                    // AI_HEAL_BURN, AI_HEAL_POISON, or AI_HEAL_SLEEP
                }
            }
            break;
        case AI_ITEM_X_STAT:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_ROSE_ITEM;
            if (*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1)) & (1 << AI_DIRE_HIT))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_USED_DIRE_HIT;
            }
            else
            {
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK)
                PREPARE_STRING_BUFFER(gBattleTextBuff2, CHAR_X)

                while (!((*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1))) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleTextBuff1[2]++;
                }

                gBattleScripting.animArg1 = gBattleTextBuff1[2] + 14;
                gBattleScripting.animArg2 = 0;
            }
            break;
        case AI_ITEM_GUARD_SPEC:
            // It seems probable that at some point there was a special message for
            // an AI trainer using Guard Spec in a double battle.
            // There isn't now however, and the assignment to 2 below goes out of
            // bounds for gMistUsedStringIds and instead prints "{mon} is getting pumped"
            // from the next table, gFocusEnergyUsedStringIds.
            // In any case this isn't an issue in the retail version, as no trainers
            // are ever given any Guard Spec to use.
#ifndef UBFIX
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else
#endif
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_MIST;
            break;
        }

        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[*(gBattleStruct->AI_itemType + gBattlerAttacker / 2)];
    }
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

bool8 TryRunFromBattle(u8 battler)
{
    bool8 effect = FALSE;
    u8 holdEffect;
    u8 pyramidMultiplier;
    u8 speedVar;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
    {
        gLastUsedItem = gBattleMons[battler].item;
        gProtectStructs[battler].fleeFlag = 1;
        effect++;
    }
    else if (gBattleMons[battler].ability == ABILITY_RUN_AWAY)
    {
        if (InBattlePyramid())
        {
            gBattleStruct->runTries++;
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[BATTLE_OPPOSITE(battler)].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
            {
                gLastUsedAbility = ABILITY_RUN_AWAY;
                gProtectStructs[battler].fleeFlag = 2;
                effect++;
            }
        }
        else
        {
            gLastUsedAbility = ABILITY_RUN_AWAY;
            gProtectStructs[battler].fleeFlag = 2;
            effect++;
        }
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL) && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        effect++;
    }
    else
    {
        u8 runningFromBattler = BATTLE_OPPOSITE(battler);
        if (!IsBattlerAlive(runningFromBattler))
            runningFromBattler |= BIT_FLANK;

        if (InBattlePyramid())
        {
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect++;
        }
        else if (gBattleMons[battler].speed < gBattleMons[runningFromBattler].speed)
        {
            speedVar = (gBattleMons[battler].speed * 128) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect++;
        }
        else // same speed or faster
        {
            effect++;
        }

        gBattleStruct->runTries++;
    }

    if (effect)
    {
        gCurrentTurnActionNumber = gBattlersCount;
        gBattleOutcome = B_OUTCOME_RAN;
    }

    return effect;
}

void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gCurrentTurnActionNumber = gBattlersCount;

        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_LOST;
            }
            else
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_WON;
            }
        }

        gBattleOutcome |= B_OUTCOME_LINK_BATTLE_RAN;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (!TryRunFromBattle(gBattlerAttacker)) // failed to run away
            {
                ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE_2;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
        }
        else
        {
            if (!CanBattlerEscape(gBattlerAttacker))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ATTACKER_CANT_ESCAPE;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gBattlersCount;
                gBattleOutcome = B_OUTCOME_MON_FLED;
            }
        }
    }
}

void HandleAction_WatchesCarefully(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = gBattlescriptsForBallThrow[ITEM_SAFARI_BALL];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowBall(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gLastUsedItem = gLastThrownBall;
    RemoveBagItem(gLastUsedItem, 1);
    gBattlescriptCurrInstr = BattleScript_BallThrow;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleResources->bufferB[gBattlerAttacker][1] - 1;
    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][2];

    if (gBattleResults.pokeblockThrows < 0xFF)
        gBattleResults.pokeblockThrows++;
    if (gBattleStruct->safariPkblThrowCounter < 3)
        gBattleStruct->safariPkblThrowCounter++;
    if (gBattleStruct->safariEscapeFactor > 1)
    {
        // BUG: safariEscapeFactor can become 0 below. This causes the pokeblock throw glitch.
        #ifdef BUGFIX
        if (gBattleStruct->safariEscapeFactor <= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #else
        if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #endif
            gBattleStruct->safariEscapeFactor = 1;
        else
            gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariEscapeFactor > 20)
        gBattleStruct->safariEscapeFactor = 20;

    if (gBattleStruct->safariGoNearCounter < 3)
    {
        gBattleStruct->safariGoNearCounter++;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CREPT_CLOSER;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_GET_CLOSER;
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_FLEE);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

void HandleAction_WallyBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
    gActionsByTurnOrder[1] = B_ACTION_FINISHED;
}

void HandleAction_TryFinish(void)
{
    if (!HandleFaintedMonActions())
    {
        gBattleStruct->faintedActionsState = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
    }
}

void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_x100000
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_x4000000);
}

void HandleAction_ActionFinished(void)
{
    *(gBattleStruct->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = 6;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_x100000
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_x4000000 | HITMARKER_IGNORE_DISGUISE);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLastLandedMoves[gBattlerAttacker] = 0;
    gLastHitByType[gBattlerAttacker] = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.moveendState = 0;
    gBattleScripting.moveendState = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

// rom const data

static const u8 sMovesNotAffectedByStench[] =
{
    [MOVE_AIR_SLASH] = 1,
    [MOVE_ASTONISH] = 1,
    [MOVE_BITE] = 1,
    [MOVE_BONE_CLUB] = 1,
    [MOVE_DARK_PULSE] = 1,
    [MOVE_DOUBLE_IRON_BASH] = 1,
    [MOVE_DRAGON_RUSH] = 1,
    [MOVE_EXTRASENSORY] = 1,
    [MOVE_FAKE_OUT] = 1,
    [MOVE_FIERY_WRATH] = 1,
    [MOVE_FIRE_FANG] = 1,
    [MOVE_FLING] = 1,
    [MOVE_FLOATY_FALL] = 1,
    [MOVE_HEADBUTT] = 1,
    [MOVE_HEART_STAMP] = 1,
    [MOVE_HYPER_FANG] = 1,
    [MOVE_ICE_FANG] = 1,
    [MOVE_ICICLE_CRASH] = 1,
    [MOVE_IRON_HEAD] = 1,
    [MOVE_NEEDLE_ARM] = 1,
    [MOVE_NONE] = 1,
    [MOVE_ROCK_SLIDE] = 1,
    [MOVE_ROLLING_KICK] = 1,
    [MOVE_SECRET_POWER] = 1,
    [MOVE_SKY_ATTACK] = 1,
    [MOVE_SNORE] = 1,
    [MOVE_STEAMROLLER] = 1,
    [MOVE_STOMP] = 1,
    [MOVE_THUNDER_FANG] = 1,
    [MOVE_TWISTER] = 1,
    [MOVE_WATERFALL] = 1,
    [MOVE_ZEN_HEADBUTT] = 1,
    [MOVE_ZING_ZAP] = 1,
};

static const u8 sAbilitiesAffectedByMoldBreaker[] =
{
    [ABILITY_BATTLE_ARMOR] = 1,
    [ABILITY_CLEAR_BODY] = 1,
    [ABILITY_DAMP] = 1,
    [ABILITY_DRY_SKIN] = 1,
    [ABILITY_FILTER] = 1,
    [ABILITY_FLASH_FIRE] = 1,
    [ABILITY_FLOWER_GIFT] = 1,
    [ABILITY_HEATPROOF] = 1,
    [ABILITY_HYPER_CUTTER] = 1,
    [ABILITY_IMMUNITY] = 1,
    [ABILITY_INNER_FOCUS] = 1,
    [ABILITY_INSOMNIA] = 1,
    [ABILITY_KEEN_EYE] = 1,
    [ABILITY_LEAF_GUARD] = 1,
    [ABILITY_LEVITATE] = 1,
    [ABILITY_LIGHTNING_ROD] = 1,
    [ABILITY_LIMBER] = 1,
    [ABILITY_MAGMA_ARMOR] = 1,
    [ABILITY_MARVEL_SCALE] = 1,
    [ABILITY_MOTOR_DRIVE] = 1,
    [ABILITY_OBLIVIOUS] = 1,
    [ABILITY_OWN_TEMPO] = 1,
    [ABILITY_SAND_VEIL] = 1,
    [ABILITY_SHELL_ARMOR] = 1,
    [ABILITY_SHIELD_DUST] = 1,
    [ABILITY_SIMPLE] = 1,
    [ABILITY_SNOW_CLOAK] = 1,
    [ABILITY_SOLID_ROCK] = 1,
    [ABILITY_SOUNDPROOF] = 1,
    [ABILITY_STICKY_HOLD] = 1,
    [ABILITY_STORM_DRAIN] = 1,
    [ABILITY_STURDY] = 1,
    [ABILITY_SUCTION_CUPS] = 1,
    [ABILITY_TANGLED_FEET] = 1,
    [ABILITY_THICK_FAT] = 1,
    [ABILITY_UNAWARE] = 1,
    [ABILITY_VITAL_SPIRIT] = 1,
    [ABILITY_VOLT_ABSORB] = 1,
    [ABILITY_WATER_ABSORB] = 1,
    [ABILITY_WATER_VEIL] = 1,
    [ABILITY_WHITE_SMOKE] = 1,
    [ABILITY_WONDER_GUARD] = 1,
    [ABILITY_BIG_PECKS] = 1,
    [ABILITY_CONTRARY] = 1,
    [ABILITY_FRIEND_GUARD] = 1,
    [ABILITY_HEAVY_METAL] = 1,
    [ABILITY_LIGHT_METAL] = 1,
    [ABILITY_MAGIC_BOUNCE] = 1,
    [ABILITY_MULTISCALE] = 1,
    [ABILITY_SAP_SIPPER] = 1,
    [ABILITY_TELEPATHY] = 1,
    [ABILITY_WONDER_SKIN] = 1,
    [ABILITY_AROMA_VEIL] = 1,
    [ABILITY_BULLETPROOF] = 1,
    [ABILITY_FLOWER_VEIL] = 1,
    [ABILITY_FUR_COAT] = 1,
    [ABILITY_OVERCOAT] = 1,
    [ABILITY_SWEET_VEIL] = 1,
    [ABILITY_DAZZLING] = 1,
    [ABILITY_DISGUISE] = 1,
    [ABILITY_FLUFFY] = 1,
    [ABILITY_QUEENLY_MAJESTY] = 1,
    [ABILITY_WATER_BUBBLE] = 1,
    [ABILITY_MIRROR_ARMOR] = 1,
    [ABILITY_PUNK_ROCK] = 1,
    [ABILITY_ICE_SCALES] = 1,
    [ABILITY_ICE_FACE] = 1,
    [ABILITY_PASTEL_VEIL] = 1,
};

static const u8 sAbilitiesNotTraced[ABILITIES_COUNT] =
{
    [ABILITY_AS_ONE_ICE_RIDER] = 1,
    [ABILITY_AS_ONE_SHADOW_RIDER] = 1,
    [ABILITY_BATTLE_BOND] = 1,
    [ABILITY_COMATOSE] = 1,
    [ABILITY_DISGUISE] = 1,
    [ABILITY_FLOWER_GIFT] = 1,
    [ABILITY_FORECAST] = 1,
    [ABILITY_GULP_MISSILE] = 1,
    [ABILITY_HUNGER_SWITCH] = 1,
    [ABILITY_ICE_FACE] = 1,
    [ABILITY_ILLUSION] = 1,
    [ABILITY_IMPOSTER] = 1,
    [ABILITY_MULTITYPE] = 1,
    [ABILITY_NEUTRALIZING_GAS] = 1,
    [ABILITY_NONE] = 1,
    [ABILITY_POWER_CONSTRUCT] = 1,
    [ABILITY_POWER_OF_ALCHEMY] = 1,
    [ABILITY_RECEIVER] = 1,
    [ABILITY_RKS_SYSTEM] = 1,
    [ABILITY_SCHOOLING] = 1,
    [ABILITY_SHIELDS_DOWN] = 1,
    [ABILITY_STANCE_CHANGE] = 1,
    [ABILITY_TRACE] = 1,
    [ABILITY_ZEN_MODE] = 1,
};

static const u8 sHoldEffectToType[][2] =
{
    {HOLD_EFFECT_BUG_POWER, TYPE_BUG},
    {HOLD_EFFECT_STEEL_POWER, TYPE_STEEL},
    {HOLD_EFFECT_GROUND_POWER, TYPE_GROUND},
    {HOLD_EFFECT_ROCK_POWER, TYPE_ROCK},
    {HOLD_EFFECT_GRASS_POWER, TYPE_GRASS},
    {HOLD_EFFECT_DARK_POWER, TYPE_DARK},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_FIGHTING},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELECTRIC},
    {HOLD_EFFECT_WATER_POWER, TYPE_WATER},
    {HOLD_EFFECT_FLYING_POWER, TYPE_FLYING},
    {HOLD_EFFECT_POISON_POWER, TYPE_POISON},
    {HOLD_EFFECT_ICE_POWER, TYPE_ICE},
    {HOLD_EFFECT_GHOST_POWER, TYPE_GHOST},
    {HOLD_EFFECT_PSYCHIC_POWER, TYPE_PSYCHIC},
    {HOLD_EFFECT_FIRE_POWER, TYPE_FIRE},
    {HOLD_EFFECT_DRAGON_POWER, TYPE_DRAGON},
    {HOLD_EFFECT_NORMAL_POWER, TYPE_NORMAL},
    {HOLD_EFFECT_FAIRY_POWER, TYPE_FAIRY},
};

// percent in UQ_4_12 format
static const u16 sPercentToModifier[] =
{
    UQ_4_12(0.00), // 0
    UQ_4_12(0.01), // 1
    UQ_4_12(0.02), // 2
    UQ_4_12(0.03), // 3
    UQ_4_12(0.04), // 4
    UQ_4_12(0.05), // 5
    UQ_4_12(0.06), // 6
    UQ_4_12(0.07), // 7
    UQ_4_12(0.08), // 8
    UQ_4_12(0.09), // 9
    UQ_4_12(0.10), // 10
    UQ_4_12(0.11), // 11
    UQ_4_12(0.12), // 12
    UQ_4_12(0.13), // 13
    UQ_4_12(0.14), // 14
    UQ_4_12(0.15), // 15
    UQ_4_12(0.16), // 16
    UQ_4_12(0.17), // 17
    UQ_4_12(0.18), // 18
    UQ_4_12(0.19), // 19
    UQ_4_12(0.20), // 20
    UQ_4_12(0.21), // 21
    UQ_4_12(0.22), // 22
    UQ_4_12(0.23), // 23
    UQ_4_12(0.24), // 24
    UQ_4_12(0.25), // 25
    UQ_4_12(0.26), // 26
    UQ_4_12(0.27), // 27
    UQ_4_12(0.28), // 28
    UQ_4_12(0.29), // 29
    UQ_4_12(0.30), // 30
    UQ_4_12(0.31), // 31
    UQ_4_12(0.32), // 32
    UQ_4_12(0.33), // 33
    UQ_4_12(0.34), // 34
    UQ_4_12(0.35), // 35
    UQ_4_12(0.36), // 36
    UQ_4_12(0.37), // 37
    UQ_4_12(0.38), // 38
    UQ_4_12(0.39), // 39
    UQ_4_12(0.40), // 40
    UQ_4_12(0.41), // 41
    UQ_4_12(0.42), // 42
    UQ_4_12(0.43), // 43
    UQ_4_12(0.44), // 44
    UQ_4_12(0.45), // 45
    UQ_4_12(0.46), // 46
    UQ_4_12(0.47), // 47
    UQ_4_12(0.48), // 48
    UQ_4_12(0.49), // 49
    UQ_4_12(0.50), // 50
    UQ_4_12(0.51), // 51
    UQ_4_12(0.52), // 52
    UQ_4_12(0.53), // 53
    UQ_4_12(0.54), // 54
    UQ_4_12(0.55), // 55
    UQ_4_12(0.56), // 56
    UQ_4_12(0.57), // 57
    UQ_4_12(0.58), // 58
    UQ_4_12(0.59), // 59
    UQ_4_12(0.60), // 60
    UQ_4_12(0.61), // 61
    UQ_4_12(0.62), // 62
    UQ_4_12(0.63), // 63
    UQ_4_12(0.64), // 64
    UQ_4_12(0.65), // 65
    UQ_4_12(0.66), // 66
    UQ_4_12(0.67), // 67
    UQ_4_12(0.68), // 68
    UQ_4_12(0.69), // 69
    UQ_4_12(0.70), // 70
    UQ_4_12(0.71), // 71
    UQ_4_12(0.72), // 72
    UQ_4_12(0.73), // 73
    UQ_4_12(0.74), // 74
    UQ_4_12(0.75), // 75
    UQ_4_12(0.76), // 76
    UQ_4_12(0.77), // 77
    UQ_4_12(0.78), // 78
    UQ_4_12(0.79), // 79
    UQ_4_12(0.80), // 80
    UQ_4_12(0.81), // 81
    UQ_4_12(0.82), // 82
    UQ_4_12(0.83), // 83
    UQ_4_12(0.84), // 84
    UQ_4_12(0.85), // 85
    UQ_4_12(0.86), // 86
    UQ_4_12(0.87), // 87
    UQ_4_12(0.88), // 88
    UQ_4_12(0.89), // 89
    UQ_4_12(0.90), // 90
    UQ_4_12(0.91), // 91
    UQ_4_12(0.92), // 92
    UQ_4_12(0.93), // 93
    UQ_4_12(0.94), // 94
    UQ_4_12(0.95), // 95
    UQ_4_12(0.96), // 96
    UQ_4_12(0.97), // 97
    UQ_4_12(0.98), // 98
    UQ_4_12(0.99), // 99
    UQ_4_12(1.00), // 100
};

#define X UQ_4_12

static const u16 sTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{
//   normal  fight   flying  poison  ground  rock    bug     ghost   steel   mystery fire    water   grass  electric psychic ice     dragon  dark    fairy
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // normal
    {X(2.0), X(1.0), X(0.5), X(0.5), X(1.0), X(2.0), X(0.5), X(0.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(2.0), X(0.5)}, // fight
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // flying
    {X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(0.5), X(1.0), X(0.5), X(0.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0)}, // poison
    {X(1.0), X(1.0), X(0.0), X(2.0), X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // ground
    {X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0)}, // rock
    {X(1.0), X(0.5), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0), X(0.5)}, // bug
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0)}, // ghost
    #else
    {X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0)}, // ghost
    #endif
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0)}, // steel
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // mystery
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(0.5), X(2.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0)}, // fire
    {X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // water
    {X(1.0), X(1.0), X(0.5), X(0.5), X(2.0), X(2.0), X(0.5), X(1.0), X(0.5), X(1.0), X(0.5), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // grass
    {X(1.0), X(1.0), X(2.0), X(1.0), X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(0.5), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // electric
    {X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(0.0), X(1.0)}, // psychic
    {X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(0.5), X(2.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0)}, // ice
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(0.0)}, // dragon
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(0.5)}, // dark
    #else
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(0.5)}, // dark
    #endif
    {X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0)}, // fairy
};

static const u16 sInverseTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{
//   normal  fight   flying  poison  ground  rock    bug     ghost   steel   mystery fire    water   grass  electric psychic ice     dragon  dark    fairy
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // normal
    {X(0.5), X(1.0), X(2.0), X(2.0), X(1.0), X(0.5), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(2.0)}, // fight
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // flying
    {X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5)}, // poison
    {X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // ground
    {X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0)}, // rock
    {X(1.0), X(2.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(0.5), X(2.0)}, // bug
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0)}, // ghost
    #else
    {X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0)}, // ghost
    #endif
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(0.5)}, // steel
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // mystery
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0)}, // fire
    {X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // water
    {X(1.0), X(1.0), X(2.0), X(2.0), X(0.5), X(0.5), X(2.0), X(1.0), X(2.0), X(1.0), X(2.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // grass
    {X(1.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(2.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // electric
    {X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0), X(1.0)}, // psychic
    {X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0)}, // ice
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(2.0)}, // dragon
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(2.0)}, // dark
    #else
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(2.0)}, // dark
    #endif
    {X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0)}, // fairy
};

#undef X

// code
u8 GetBattlerForBattleScript(u8 caseId)
{
    u8 ret = 0;
    switch (caseId)
    {
    case BS_TARGET:
        ret = gBattlerTarget;
        break;
    case BS_ATTACKER:
        ret = gBattlerAttacker;
        break;
    case BS_EFFECT_BATTLER:
        ret = gEffectBattler;
        break;
    case BS_BATTLER_0:
        ret = 0;
        break;
    case BS_SCRIPTING:
        ret = gBattleScripting.battler;
        break;
    case BS_FAINTED:
        ret = gBattlerFainted;
        break;
    case 5:
        ret = gBattlerFainted;
        break;
    case 4:
    case 6:
    case 8:
    case 9:
    case BS_PLAYER1:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    case BS_OPPONENT1:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case BS_PLAYER2:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        break;
    case BS_OPPONENT2:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        break;
    case BS_ABILITY_BATTLER:
        ret = gBattlerAbility;
        break;
    }
    return ret;
}

void PressurePPLose(u8 target, u8 attacker, u16 move)
{
    int moveIndex;

    if (GetBattlerAbility(target) != ABILITY_PRESSURE)
        return;

    for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[attacker].moves[moveIndex] == move)
            break;
    }

    if (moveIndex == MAX_MON_MOVES)
        return;

    if (gBattleMons[attacker].pp[moveIndex] != 0)
        gBattleMons[attacker].pp[moveIndex]--;

    if (!(gBattleMons[attacker].status2 & STATUS2_TRANSFORMED)
        && !(gDisableStructs[attacker].mimickedMoves & gBitTable[moveIndex]))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + moveIndex, 0, 1, &gBattleMons[gActiveBattler].pp[moveIndex]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void PressurePPLoseOnUsingImprison(u8 attacker)
{
    int i, j;
    int imprisonPos = 4;
    u8 atkSide = GetBattlerSide(attacker);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (atkSide != GetBattlerSide(i) && GetBattlerAbility(i) == ABILITY_PRESSURE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[attacker].moves[j] == MOVE_IMPRISON)
                    break;
            }
            if (j != MAX_MON_MOVES)
            {
                imprisonPos = j;
                if (gBattleMons[attacker].pp[j] != 0)
                    gBattleMons[attacker].pp[j]--;
            }
        }
    }

    if (imprisonPos != 4
        && !(gBattleMons[attacker].status2 & STATUS2_TRANSFORMED)
        && !(gDisableStructs[attacker].mimickedMoves & gBitTable[imprisonPos]))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + imprisonPos, 0, 1, &gBattleMons[gActiveBattler].pp[imprisonPos]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void PressurePPLoseOnUsingPerishSong(u8 attacker)
{
    int i, j;
    int perishSongPos = 4;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (GetBattlerAbility(i) == ABILITY_PRESSURE && i != attacker)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[attacker].moves[j] == MOVE_PERISH_SONG)
                    break;
            }
            if (j != MAX_MON_MOVES)
            {
                perishSongPos = j;
                if (gBattleMons[attacker].pp[j] != 0)
                    gBattleMons[attacker].pp[j]--;
            }
        }
    }

    if (perishSongPos != MAX_MON_MOVES
        && !(gBattleMons[attacker].status2 & STATUS2_TRANSFORMED)
        && !(gDisableStructs[attacker].mimickedMoves & gBitTable[perishSongPos]))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + perishSongPos, 0, 1, &gBattleMons[gActiveBattler].pp[perishSongPos]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void MarkAllBattlersForControllerExec(void) // unused
{
    int i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattleControllerExecFlags |= gBitTable[i] << (32 - MAX_BATTLERS_COUNT);
    }
    else
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattleControllerExecFlags |= gBitTable[i];
    }
}

bool32 IsBattlerMarkedForControllerExec(u8 battlerId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return (gBattleControllerExecFlags & (gBitTable[battlerId] << 0x1C)) != 0;
    else
        return (gBattleControllerExecFlags & (gBitTable[battlerId])) != 0;
}

void MarkBattlerForControllerExec(u8 battlerId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattleControllerExecFlags |= gBitTable[battlerId] << (32 - MAX_BATTLERS_COUNT);
    else
        gBattleControllerExecFlags |= gBitTable[battlerId];
}

void MarkBattlerReceivedLinkData(u8 battlerId)
{
    s32 i;

    for (i = 0; i < GetLinkPlayerCount(); i++)
        gBattleControllerExecFlags |= gBitTable[battlerId] << (i << 2);

    gBattleControllerExecFlags &= ~(0x10000000 << battlerId);
}

void CancelMultiTurnMoves(u8 battler)
{
    gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
    gBattleMons[battler].status2 &= ~(STATUS2_LOCK_CONFUSE);
    gBattleMons[battler].status2 &= ~(STATUS2_UPROAR);
    gBattleMons[battler].status2 &= ~(STATUS2_BIDE);

    gStatuses3[battler] &= ~(STATUS3_SEMI_INVULNERABLE);

    gDisableStructs[battler].rolloutTimer = 0;
    gDisableStructs[battler].furyCutterCounter = 0;
}

bool8 WasUnableToUseMove(u8 battler)
{
    if (gProtectStructs[battler].prlzImmobility
        || gProtectStructs[battler].usedImprisonedMove
        || gProtectStructs[battler].loveImmobility
        || gProtectStructs[battler].usedDisabledMove
        || gProtectStructs[battler].usedTauntedMove
        || gProtectStructs[battler].usedGravityPreventedMove
        || gProtectStructs[battler].usedHealBlockedMove
        || gProtectStructs[battler].flag2Unknown
        || gProtectStructs[battler].flinchImmobility
        || gProtectStructs[battler].confusionSelfDmg
        || gProtectStructs[battler].powderSelfDmg
        || gProtectStructs[battler].usedThroatChopPreventedMove)
        return TRUE;
    else
        return FALSE;
}

void PrepareStringBattle(u16 stringId, u8 battler)
{
    // Support for Contrary ability.
    // If a move attempted to raise stat - print "won't increase".
    // If a move attempted to lower stat - print "won't decrease".
    if (stringId == STRINGID_STATSWONTDECREASE && !(gBattleScripting.statChanger & STAT_BUFF_NEGATIVE))
        stringId = STRINGID_STATSWONTINCREASE;
    else if (stringId == STRINGID_STATSWONTINCREASE && gBattleScripting.statChanger & STAT_BUFF_NEGATIVE)
        stringId = STRINGID_STATSWONTDECREASE;

    else if (stringId == STRINGID_STATSWONTDECREASE2 && GetBattlerAbility(battler) == ABILITY_CONTRARY)
        stringId = STRINGID_STATSWONTINCREASE2;
    else if (stringId == STRINGID_STATSWONTINCREASE2 && GetBattlerAbility(battler) == ABILITY_CONTRARY)
        stringId = STRINGID_STATSWONTDECREASE2;

    // Check Defiant and Competitive stat raise whenever a stat is lowered.
    else if ((stringId == STRINGID_DEFENDERSSTATFELL || stringId == STRINGID_PKMNCUTSATTACKWITH)
              && ((GetBattlerAbility(gBattlerTarget) == ABILITY_DEFIANT && CompareStat(gBattlerTarget, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
                 || (GetBattlerAbility(gBattlerTarget) == ABILITY_COMPETITIVE && CompareStat(gBattlerTarget, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN)))
              && gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != BATTLE_PARTNER(gBattlerTarget)
              && gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != gBattlerTarget)
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_DefiantActivates;
        if (GetBattlerAbility(gBattlerTarget) == ABILITY_DEFIANT)
            SET_STATCHANGER(STAT_ATK, 2, FALSE);
        else
            SET_STATCHANGER(STAT_SPATK, 2, FALSE);
    }

    gActiveBattler = battler;
    BtlController_EmitPrintString(0, stringId);
    MarkBattlerForControllerExec(gActiveBattler);
}

void ResetSentPokesToOpponentValue(void)
{
    s32 i;
    u32 bits = 0;

    gSentPokesToOpponent[0] = 0;
    gSentPokesToOpponent[1] = 0;

    for (i = 0; i < gBattlersCount; i += 2)
        bits |= gBitTable[gBattlerPartyIndexes[i]];

    for (i = 1; i < gBattlersCount; i += 2)
        gSentPokesToOpponent[(i & BIT_FLANK) >> 1] = bits;
}

void OpponentSwitchInResetSentPokesToOpponentValue(u8 battler)
{
    s32 i = 0;
    u32 bits = 0;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        u8 flank = ((battler & BIT_FLANK) >> 1);
        gSentPokesToOpponent[flank] = 0;

        for (i = 0; i < gBattlersCount; i += 2)
        {
            if (!(gAbsentBattlerFlags & gBitTable[i]))
                bits |= gBitTable[gBattlerPartyIndexes[i]];
        }

        gSentPokesToOpponent[flank] = bits;
    }
}

void UpdateSentPokesToOpponentValue(u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        OpponentSwitchInResetSentPokesToOpponentValue(battler);
    }
    else
    {
        s32 i;
        for (i = 1; i < gBattlersCount; i++)
            gSentPokesToOpponent[(i & BIT_FLANK) >> 1] |= gBitTable[gBattlerPartyIndexes[battler]];
    }
}

void BattleScriptPush(const u8 *bsPtr)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = gBattlescriptCurrInstr;
}

void BattleScriptPop(void)
{
    gBattlescriptCurrInstr = gBattleResources->battleScriptsStack->ptr[--gBattleResources->battleScriptsStack->size];
}

static bool32 IsGravityPreventingMove(u32 move)
{
    if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        return FALSE;

    switch (move)
    {
    case MOVE_BOUNCE:
    case MOVE_FLY:
    case MOVE_FLYING_PRESS:
    case MOVE_HIGH_JUMP_KICK:
    case MOVE_JUMP_KICK:
    case MOVE_MAGNET_RISE:
    case MOVE_SKY_DROP:
    case MOVE_SPLASH:
    case MOVE_TELEKINESIS:
    case MOVE_FLOATY_FALL:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsHealBlockPreventingMove(u32 battler, u32 move)
{
    if (!(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
        return FALSE;

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_ABSORB:
    case EFFECT_MORNING_SUN:
    case EFFECT_MOONLIGHT:
    case EFFECT_RESTORE_HP:
    case EFFECT_REST:
    case EFFECT_ROOST:
    case EFFECT_HEALING_WISH:
    case EFFECT_WISH:
    case EFFECT_DREAM_EATER:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsBelchPreventingMove(u32 battler, u32 move)
{
    if (gBattleMoves[move].effect != EFFECT_BELCH)
        return FALSE;

    return !(gBattleStruct->ateBerry[battler & BIT_SIDE] & gBitTable[gBattlerPartyIndexes[battler]]);
}

u8 TrySetCantSelectMoveBattleScript(void)
{
    u32 limitations = 0;
    u8 moveId = gBattleResources->bufferB[gActiveBattler][2] & ~(RET_MEGA_EVOLUTION);
    u32 move = gBattleMons[gActiveBattler].moves[moveId];
    u32 holdEffect = GetBattlerHoldEffect(gActiveBattler, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[gActiveBattler];

    if (gDisableStructs[gActiveBattler].disabledMove == move && move != MOVE_NONE)
    {
        gBattleScripting.battler = gActiveBattler;
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMove;
            limitations++;
        }
    }

    if (move == gLastMoves[gActiveBattler] && move != MOVE_STRUGGLE && (gBattleMons[gActiveBattler].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(gActiveBattler);
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMove;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBattler].tauntTimer != 0 && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTauntInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTaunt;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBattler].throatChopTimer != 0 && gBattleMoves[move].flags & FLAG_SOUND)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveThroatChopInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveThroatChop;
            limitations++;
        }
    }

    if (GetImprisonedMovesCount(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMove;
            limitations++;
        }
    }

    if (IsGravityPreventingMove(move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveGravityInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveGravity;
            limitations++;
        }
    }

    if (IsHealBlockPreventingMove(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveHealBlockInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveHealBlock;
            limitations++;
        }
    }

    if (IsBelchPreventingMove(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelchInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelch;
            limitations++;
        }
    }
    
    if (move == MOVE_STUFF_CHEEKS && ItemId_GetPocket(gBattleMons[gActiveBattler].item) != POCKET_BERRIES)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelchInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedStuffCheeks;
            limitations++;
        }
    }

    gPotentialItemEffectBattler = gActiveBattler;
    if (HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[gActiveBattler].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
            limitations++;
        }
    }
    else if (holdEffect == HOLD_EFFECT_ASSAULT_VEST && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        gLastUsedItem = gBattleMons[gActiveBattler].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveAssaultVest;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBattler].pp[moveId] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingMoveWithNoPP;
            limitations++;
        }
    }

    return limitations;
}

u8 CheckMoveLimitations(u8 battlerId, u8 unusableMoves, u8 check)
{
    u8 holdEffect = GetBattlerHoldEffect(battlerId, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[battlerId];
    s32 i;

    gPotentialItemEffectBattler = battlerId;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[battlerId].moves[i] == 0 && check & MOVE_LIMITATION_ZEROMOVE)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].pp[i] == 0 && check & MOVE_LIMITATION_PP)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == gDisableStructs[battlerId].disabledMove && check & MOVE_LIMITATION_DISABLED)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == gLastMoves[battlerId] && check & MOVE_LIMITATION_TORMENTED && gBattleMons[battlerId].status2 & STATUS2_TORMENT)
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].tauntTimer && check & MOVE_LIMITATION_TAUNT && gBattleMoves[gBattleMons[battlerId].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        else if (GetImprisonedMovesCount(battlerId, gBattleMons[battlerId].moves[i]) && check & MOVE_LIMITATION_IMPRISON)
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].encoreTimer && gDisableStructs[battlerId].encoredMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
        else if (HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
        else if (holdEffect == HOLD_EFFECT_ASSAULT_VEST && gBattleMoves[gBattleMons[battlerId].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        else if (IsGravityPreventingMove(gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (IsHealBlockPreventingMove(battlerId, gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (IsBelchPreventingMove(battlerId, gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].throatChopTimer && gBattleMoves[gBattleMons[battlerId].moves[i]].flags & FLAG_SOUND)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == MOVE_STUFF_CHEEKS && ItemId_GetPocket(gBattleMons[gActiveBattler].item) != POCKET_BERRIES)
            unusableMoves |= gBitTable[i];
    }
    return unusableMoves;
}

bool8 AreAllMovesUnusable(void)
{
    u8 unusable;
    unusable = CheckMoveLimitations(gActiveBattler, 0, 0xFF);

    if (unusable == 0xF) // All moves are unusable.
    {
        gProtectStructs[gActiveBattler].noValidMoves = 1;
        gSelectionBattleScripts[gActiveBattler] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[gActiveBattler].noValidMoves = 0;
    }

    return (unusable == 0xF);
}

u8 GetImprisonedMovesCount(u8 battlerId, u16 move)
{
    s32 i;
    u8 imprisonedMoves = 0;
    u8 battlerSide = GetBattlerSide(battlerId);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (battlerSide != GetBattlerSide(i) && gStatuses3[i] & STATUS3_IMPRISONED_OTHERS)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < MAX_MON_MOVES)
                imprisonedMoves++;
        }
    }

    return imprisonedMoves;
}

enum
{
    ENDTURN_ORDER,
    ENDTURN_REFLECT,
    ENDTURN_LIGHT_SCREEN,
    ENDTURN_AURORA_VEIL,
    ENDTURN_MIST,
    ENDTURN_LUCKY_CHANT,
    ENDTURN_SAFEGUARD,
    ENDTURN_TAILWIND,
    ENDTURN_WISH,
    ENDTURN_RAIN,
    ENDTURN_SANDSTORM,
    ENDTURN_SUN,
    ENDTURN_HAIL,
    ENDTURN_GRAVITY,
    ENDTURN_WATER_SPORT,
    ENDTURN_MUD_SPORT,
    ENDTURN_TRICK_ROOM,
    ENDTURN_WONDER_ROOM,
    ENDTURN_MAGIC_ROOM,
    ENDTURN_ELECTRIC_TERRAIN,
    ENDTURN_MISTY_TERRAIN,
    ENDTURN_GRASSY_TERRAIN,
    ENDTURN_PSYCHIC_TERRAIN,
    ENDTURN_ION_DELUGE,
    ENDTURN_FAIRY_LOCK,
    ENDTURN_RETALIATE,
    ENDTURN_FIELD_COUNT,
};

u8 DoFieldEndTurnEffects(void)
{
    u8 effect = 0;

    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerAttacker]; gBattlerAttacker++)
    {
    }
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerTarget]; gBattlerTarget++)
    {
    }

    do
    {
        s32 i;
        u8 side;

        switch (gBattleStruct->turnCountersTracker)
        {
        case ENDTURN_ORDER:
            for (i = 0; i < gBattlersCount; i++)
            {
                gBattlerByTurnOrder[i] = i;
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], 0))
                        SwapTurnOrder(i, j);
                }
            }

            gBattleStruct->turnCountersTracker++;
            gBattleStruct->turnSideTracker = 0;
            // fall through
        case ENDTURN_REFLECT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].reflectBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimers[side].reflectTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_REFLECT;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_REFLECT);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LIGHT_SCREEN:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].lightscreenBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimers[side].lightscreenTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LIGHTSCREEN;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_LIGHT_SCREEN);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_AURORA_VEIL:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].auroraVeilBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_AURORA_VEIL)
                {
                    if (--gSideTimers[side].auroraVeilTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_AURORA_VEIL;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_AURORA_VEIL);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_MIST:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].mistBattlerId;
                if (gSideTimers[side].mistTimer != 0
                 && --gSideTimers[side].mistTimer == 0)
                {
                    gSideStatuses[side] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(BattleScript_SideStatusWoreOff);
                    gBattleCommunication[MULTISTRING_CHOOSER] = side;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_MIST);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SAFEGUARD:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].safeguardBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimers[side].safeguardTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_SAFEGUARD;
                        BattleScriptExecute(BattleScript_SafeguardEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LUCKY_CHANT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].luckyChantBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LUCKY_CHANT)
                {
                    if (--gSideTimers[side].luckyChantTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LUCKY_CHANT;
                        BattleScriptExecute(BattleScript_LuckyChantEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TAILWIND:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].tailwindBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_TAILWIND)
                {
                    if (--gSideTimers[side].tailwindTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_TAILWIND;
                        BattleScriptExecute(BattleScript_TailwindEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_WISH:
            while (gBattleStruct->turnSideTracker < gBattlersCount)
            {
                gActiveBattler = gBattlerByTurnOrder[gBattleStruct->turnSideTracker];
                if (gWishFutureKnock.wishCounter[gActiveBattler] != 0
                 && --gWishFutureKnock.wishCounter[gActiveBattler] == 0
                 && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattlerTarget = gActiveBattler;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
            }
            break;
        case ENDTURN_RAIN:
            if (gBattleWeather & WEATHER_RAIN_ANY)
            {
                if (!(gBattleWeather & WEATHER_RAIN_PERMANENT)
                 && !(gBattleWeather & WEATHER_RAIN_PRIMAL))
                {
                    if (--gWishFutureKnock.weatherDuration == 0)
                    {
                        gBattleWeather &= ~WEATHER_RAIN_TEMPORARY;
                        gBattleWeather &= ~WEATHER_RAIN_DOWNPOUR;
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_STOPPED;
                    }
                    else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                }
                else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                }

                BattleScriptExecute(BattleScript_RainContinuesOrEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SANDSTORM:
            if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            {
                if (!(gBattleWeather & WEATHER_SANDSTORM_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SANDSTORM_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SANDSTORM;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SUN:
            if (gBattleWeather & WEATHER_SUN_ANY)
            {
                if (!(gBattleWeather & WEATHER_SUN_PERMANENT)
                 && !(gBattleWeather & WEATHER_SUN_PRIMAL)
                 && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SUN_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SunlightFaded;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_SunlightContinues;
                }

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_HAIL:
            if (gBattleWeather & WEATHER_HAIL_ANY)
            {
                if (!(gBattleWeather & WEATHER_HAIL_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_HAIL_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HAIL;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_TRICK_ROOM:
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && --gFieldTimers.trickRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_TRICK_ROOM);
                BattleScriptExecute(BattleScript_TrickRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM && --gFieldTimers.wonderRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_WONDER_ROOM);
                BattleScriptExecute(BattleScript_WonderRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM && --gFieldTimers.magicRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_MAGIC_ROOM);
                BattleScriptExecute(BattleScript_MagicRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_ELECTRIC_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.electricTerrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_TERRAIN_PERMANENT);
                BattleScriptExecute(BattleScript_ElectricTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MISTY_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.mistyTerrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN);
                BattleScriptExecute(BattleScript_MistyTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_GRASSY_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
            {
                if (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT)
                  && (gFieldTimers.grassyTerrainTimer == 0 || --gFieldTimers.grassyTerrainTimer == 0))
                    gFieldStatuses &= ~(STATUS_FIELD_GRASSY_TERRAIN);

                BattleScriptExecute(BattleScript_GrassyTerrainHeals);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_PSYCHIC_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.psychicTerrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_PSYCHIC_TERRAIN);
                BattleScriptExecute(BattleScript_PsychicTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WATER_SPORT:
            if (gFieldStatuses & STATUS_FIELD_WATERSPORT && --gFieldTimers.waterSportTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_WATERSPORT);
                BattleScriptExecute(BattleScript_WaterSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MUD_SPORT:
            if (gFieldStatuses & STATUS_FIELD_MUDSPORT && --gFieldTimers.mudSportTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_MUDSPORT);
                BattleScriptExecute(BattleScript_MudSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && --gFieldTimers.gravityTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_GRAVITY);
                BattleScriptExecute(BattleScript_GravityEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_ION_DELUGE:
            gFieldStatuses &= ~(STATUS_FIELD_ION_DELUGE);
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FAIRY_LOCK:
            if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK && --gFieldTimers.fairyLockTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_FAIRY_LOCK);
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_RETALIATE:
            gActiveBattler = gBattlerByTurnOrder[gBattleStruct->turnSideTracker];
            if (gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].retaliateTimer > 0)
                gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].retaliateTimer--;
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FIELD_COUNT:
            effect++;
            break;
        }
    } while (effect == 0);

    return (gBattleMainFunc != BattleTurnPassed);
}

enum
{
    ENDTURN_INGRAIN,
    ENDTURN_AQUA_RING,
    ENDTURN_ABILITIES,
    ENDTURN_ITEMS1,
    ENDTURN_LEECH_SEED,
    ENDTURN_POISON,
    ENDTURN_BAD_POISON,
    ENDTURN_BURN,
    ENDTURN_NIGHTMARES,
    ENDTURN_CURSE,
    ENDTURN_WRAP,
    ENDTURN_UPROAR,
    ENDTURN_THRASH,
    ENDTURN_FLINCH,
    ENDTURN_DISABLE,
    ENDTURN_ENCORE,
    ENDTURN_MAGNET_RISE,
    ENDTURN_TELEKINESIS,
    ENDTURN_HEALBLOCK,
    ENDTURN_EMBARGO,
    ENDTURN_LOCK_ON,
    ENDTURN_CHARGE,
    ENDTURN_LASER_FOCUS,
    ENDTURN_TAUNT,
    ENDTURN_YAWN,
    ENDTURN_ITEMS2,
    ENDTURN_ORBS,
    ENDTURN_ROOST,
    ENDTURN_ELECTRIFY,
    ENDTURN_POWDER,
    ENDTURN_THROAT_CHOP,
    ENDTURN_SLOW_START,
    ENDTURN_BATTLER_COUNT
};

// Ingrain, Leech Seed, Strength Sap and Aqua Ring
s32 GetDrainedBigRootHp(u32 battler, s32 hp)
{
    if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_BIG_ROOT)
        hp = (hp * 1300) / 1000;
    if (hp == 0)
        hp = 1;

    return hp * -1;
}

#define MAGIC_GUARD_CHECK \
if (ability == ABILITY_MAGIC_GUARD) \
{\
    RecordAbilityBattle(gActiveBattler, ability);\
    gBattleStruct->turnEffectsTracker++;\
            break;\
}


u8 DoBattlerEndTurnEffects(void)
{
    u32 ability, i, effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);
    while (gBattleStruct->turnEffectsBattlerId < gBattlersCount && gBattleStruct->turnEffectsTracker <= ENDTURN_BATTLER_COUNT)
    {
        gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->turnEffectsBattlerId];
        if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
        {
            gBattleStruct->turnEffectsBattlerId++;
            continue;
        }

        ability = GetBattlerAbility(gActiveBattler);
        switch (gBattleStruct->turnEffectsTracker)
        {
        case ENDTURN_INGRAIN:  // ingrain
            if ((gStatuses3[gActiveBattler] & STATUS3_ROOTED)
             && !BATTLER_MAX_HP(gActiveBattler)
             && !(gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK)
             && gBattleMons[gActiveBattler].hp != 0)
            {
                gBattleMoveDamage = GetDrainedBigRootHp(gActiveBattler, gBattleMons[gActiveBattler].maxHP / 16);
                BattleScriptExecute(BattleScript_IngrainTurnHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_AQUA_RING:  // aqua ring
            if ((gStatuses3[gActiveBattler] & STATUS3_AQUA_RING)
             && !BATTLER_MAX_HP(gActiveBattler)
             && !(gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK)
             && gBattleMons[gActiveBattler].hp != 0)
            {
                gBattleMoveDamage = GetDrainedBigRootHp(gActiveBattler, gBattleMons[gActiveBattler].maxHP / 16);
                BattleScriptExecute(BattleScript_AquaRingHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ABILITIES:  // end turn abilities
            if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, gActiveBattler, 0, 0, 0))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS1:  // item effects
            if (ItemBattleEffects(1, gActiveBattler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS2:  // item effects again
            if (ItemBattleEffects(1, gActiveBattler, TRUE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ORBS:
            if (ItemBattleEffects(ITEMEFFECT_ORBS, gActiveBattler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LEECH_SEED:  // leech seed
            if ((gStatuses3[gActiveBattler] & STATUS3_LEECHSEED)
             && gBattleMons[gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER].hp != 0
             && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;

                gBattlerTarget = gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER; // Notice gBattlerTarget is actually the HP receiver.
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleScripting.animArg1 = gBattlerTarget;
                gBattleScripting.animArg2 = gBattlerAttacker;
                BattleScriptExecute(BattleScript_LeechSeedTurnDrain);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_POISON:  // poison
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_POISON)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!BATTLER_MAX_HP(gActiveBattler) && !(gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK))
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BAD_POISON:  // toxic poison
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!BATTLER_MAX_HP(gActiveBattler) && !(gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK))
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                        gBattleMons[gActiveBattler].status1 += STATUS1_TOXIC_TURN(1);
                    gBattleMoveDamage *= (gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) >> 8;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BURN:  // burn
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;

                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / (B_BURN_DAMAGE >= GEN_7 ? 16 : 8);
                if (ability == ABILITY_HEATPROOF)
                {
                    if (gBattleMoveDamage > (gBattleMoveDamage / 2) + 1) // Record ability if the burn takes less damage than it normally would.
                        RecordAbilityBattle(gActiveBattler, ABILITY_HEATPROOF);
                    gBattleMoveDamage /= 2;
                }
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_BurnTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_NIGHTMARES:  // spooky nightmares
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_NIGHTMARE)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                // R/S does not perform this sleep check, which causes the nightmare effect to
                // persist even after the affected Pokemon has been awakened by Shed Skin.
                if (gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_NightmareTurnDmg);
                    effect++;
                }
                else
                {
                    gBattleMons[gActiveBattler].status2 &= ~STATUS2_NIGHTMARE;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CURSE:  // curse
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_CURSED)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_CurseTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_WRAP:  // wrap
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_WRAPPED) && gBattleMons[gActiveBattler].hp != 0)
            {
                if (--gDisableStructs[gActiveBattler].wrapTurns != 0)  // damaged by wrap
                {
                    MAGIC_GUARD_CHECK;

                    gBattleScripting.animArg1 = gBattleStruct->wrappedMove[gActiveBattler];
                    gBattleScripting.animArg2 = gBattleStruct->wrappedMove[gActiveBattler] >> 8;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gActiveBattler]);
                    gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;
                    if (GetBattlerHoldEffect(gBattleStruct->wrappedBy[gActiveBattler], TRUE) == HOLD_EFFECT_BINDING_BAND)
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / ((B_BINDING_DAMAGE >= GEN_6) ? 6 : 8);
                    else
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / ((B_BINDING_DAMAGE >= GEN_6) ? 8 : 16);

                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                }
                else  // broke free
                {
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_WRAPPED);
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gActiveBattler]);
                    gBattlescriptCurrInstr = BattleScript_WrapEnds;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_UPROAR:  // uproar
            if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
            {
                for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                {
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                     && gBattleMons[gBattlerAttacker].ability != ABILITY_SOUNDPROOF)
                    {
                        gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        BattleScriptExecute(BattleScript_MonWokeUpInUproar);
                        gActiveBattler = gBattlerAttacker;
                        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        break;
                    }
                }
                if (gBattlerAttacker != gBattlersCount)
                {
                    effect = 2;  // a pokemon was awaken
                    break;
                }
                else
                {
                    gBattlerAttacker = gActiveBattler;
                    gBattleMons[gActiveBattler].status2 -= STATUS2_UPROAR_TURN(1);  // uproar timer goes down
                    if (WasUnableToUseMove(gActiveBattler))
                    {
                        CancelMultiTurnMoves(gActiveBattler);
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                    }
                    else if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_CONTINUES;
                        gBattleMons[gActiveBattler].status2 |= STATUS2_MULTIPLETURNS;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                        CancelMultiTurnMoves(gActiveBattler);
                    }
                    BattleScriptExecute(BattleScript_PrintUproarOverTurns);
                    effect = 1;
                }
            }
            if (effect != 2)
                gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_THRASH:  // thrash
            if (gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
            {
                gBattleMons[gActiveBattler].status2 -= STATUS2_LOCK_CONFUSE_TURN(1);
                if (WasUnableToUseMove(gActiveBattler))
                    CancelMultiTurnMoves(gActiveBattler);
                else if (!(gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
                 && (gBattleMons[gActiveBattler].status2 & STATUS2_MULTIPLETURNS))
                {
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_MULTIPLETURNS);
                    if (!(gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION))
                    {
                        gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER;
                        SetMoveEffect(TRUE, 0);
                        if (gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
                            BattleScriptExecute(BattleScript_ThrashConfuses);
                        effect++;
                    }
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_FLINCH:  // reset flinch
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_FLINCHED);
            gBattleStruct->turnEffectsTracker++;
        case ENDTURN_DISABLE:  // disable
            if (gDisableStructs[gActiveBattler].disableTimer != 0)
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gDisableStructs[gActiveBattler].disabledMove == gBattleMons[gActiveBattler].moves[i])
                        break;
                }
                if (i == MAX_MON_MOVES)  // pokemon does not have the disabled move anymore
                {
                    gDisableStructs[gActiveBattler].disabledMove = 0;
                    gDisableStructs[gActiveBattler].disableTimer = 0;
                }
                else if (--gDisableStructs[gActiveBattler].disableTimer == 0)  // disable ends
                {
                    gDisableStructs[gActiveBattler].disabledMove = 0;
                    BattleScriptExecute(BattleScript_DisabledNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ENCORE:  // encore
            if (gDisableStructs[gActiveBattler].encoreTimer != 0)
            {
                if (gBattleMons[gActiveBattler].moves[gDisableStructs[gActiveBattler].encoredMovePos] != gDisableStructs[gActiveBattler].encoredMove)  // pokemon does not have the encored move anymore
                {
                    gDisableStructs[gActiveBattler].encoredMove = 0;
                    gDisableStructs[gActiveBattler].encoreTimer = 0;
                }
                else if (--gDisableStructs[gActiveBattler].encoreTimer == 0
                 || gBattleMons[gActiveBattler].pp[gDisableStructs[gActiveBattler].encoredMovePos] == 0)
                {
                    gDisableStructs[gActiveBattler].encoredMove = 0;
                    gDisableStructs[gActiveBattler].encoreTimer = 0;
                    BattleScriptExecute(BattleScript_EncoredNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LOCK_ON:  // lock-on decrement
            if (gStatuses3[gActiveBattler] & STATUS3_ALWAYS_HITS)
                gStatuses3[gActiveBattler] -= STATUS3_ALWAYS_HITS_TURN(1);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CHARGE:  // charge
            if (gDisableStructs[gActiveBattler].chargeTimer && --gDisableStructs[gActiveBattler].chargeTimer == 0)
                gStatuses3[gActiveBattler] &= ~STATUS3_CHARGED_UP;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TAUNT:  // taunt
            if (gDisableStructs[gActiveBattler].tauntTimer && --gDisableStructs[gActiveBattler].tauntTimer == 0)
            {
                BattleScriptExecute(BattleScript_BufferEndTurn);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_YAWN:  // yawn
            if (gStatuses3[gActiveBattler] & STATUS3_YAWN)
            {
                gStatuses3[gActiveBattler] -= STATUS3_YAWN_TURN(1);
                if (!(gStatuses3[gActiveBattler] & STATUS3_YAWN) && !(gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                 && GetBattlerAbility(gActiveBattler) != ABILITY_VITAL_SPIRIT
                 && GetBattlerAbility(gActiveBattler) != ABILITY_INSOMNIA && !UproarWakeUpCheck(gActiveBattler)
                 && !IsLeafGuardProtected(gActiveBattler))
                {
                    CancelMultiTurnMoves(gActiveBattler);
                    gEffectBattler = gActiveBattler;
                    if (IsBattlerTerrainAffected(gActiveBattler, STATUS_FIELD_ELECTRIC_TERRAIN))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINPREVENTS_ELECTRIC;
                        BattleScriptExecute(BattleScript_TerrainPreventsEnd2);
                    }
                    else if (IsBattlerTerrainAffected(gActiveBattler, STATUS_FIELD_MISTY_TERRAIN))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINPREVENTS_MISTY;
                        BattleScriptExecute(BattleScript_TerrainPreventsEnd2);
                    }
                    else
                    {
                        gBattleMons[gActiveBattler].status1 |= (Random() & 3) + 2;
                        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        BattleScriptExecute(BattleScript_YawnMakesAsleep);
                    }
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LASER_FOCUS:
            if (gStatuses3[gActiveBattler] & STATUS3_LASER_FOCUS)
            {
                if (gDisableStructs[gActiveBattler].laserFocusTimer == 0 || --gDisableStructs[gActiveBattler].laserFocusTimer == 0)
                    gStatuses3[gActiveBattler] &= ~(STATUS3_LASER_FOCUS);
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_EMBARGO:
            if (gStatuses3[gActiveBattler] & STATUS3_EMBARGO)
            {
                if (gDisableStructs[gActiveBattler].embargoTimer == 0 || --gDisableStructs[gActiveBattler].embargoTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_EMBARGO);
                    BattleScriptExecute(BattleScript_EmbargoEndTurn);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_MAGNET_RISE:
            if (gStatuses3[gActiveBattler] & STATUS3_MAGNET_RISE)
            {
                if (gDisableStructs[gActiveBattler].magnetRiseTimer == 0 || --gDisableStructs[gActiveBattler].magnetRiseTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_MAGNET_RISE);
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_STRING_BUFFER(gBattleTextBuff1, STRINGID_ELECTROMAGNETISM);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TELEKINESIS:
            if (gStatuses3[gActiveBattler] & STATUS3_TELEKINESIS)
            {
                if (gDisableStructs[gActiveBattler].telekinesisTimer == 0 || --gDisableStructs[gActiveBattler].telekinesisTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_TELEKINESIS);
                    BattleScriptExecute(BattleScript_TelekinesisEndTurn);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_HEALBLOCK:
            if (gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK)
            {
                if (gDisableStructs[gActiveBattler].healBlockTimer == 0 || --gDisableStructs[gActiveBattler].healBlockTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_HEAL_BLOCK);
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_HEAL_BLOCK);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ROOST: // Return flying type.
            if (gBattleResources->flags->flags[gActiveBattler] & RESOURCE_FLAG_ROOST)
            {
                gBattleResources->flags->flags[gActiveBattler] &= ~(RESOURCE_FLAG_ROOST);
                gBattleMons[gActiveBattler].type1 = gBattleStruct->roostTypes[gActiveBattler][0];
                gBattleMons[gActiveBattler].type2 = gBattleStruct->roostTypes[gActiveBattler][1];
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ELECTRIFY:
            gStatuses3[gActiveBattler] &= ~(STATUS3_ELECTRIFIED);
            gBattleStruct->turnEffectsTracker++;
        case ENDTURN_POWDER:
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_POWDER);
            gBattleStruct->turnEffectsTracker++;
        case ENDTURN_THROAT_CHOP:
            if (gDisableStructs[gActiveBattler].throatChopTimer && --gDisableStructs[gActiveBattler].throatChopTimer == 0)
            {
                BattleScriptExecute(BattleScript_ThroatChopEndTurn);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_SLOW_START:
            if (gDisableStructs[gActiveBattler].slowStartTimer
                && --gDisableStructs[gActiveBattler].slowStartTimer == 0
                && ability == ABILITY_SLOW_START)
            {
                BattleScriptExecute(BattleScript_SlowStartEnds);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BATTLER_COUNT:  // done
            gBattleStruct->turnEffectsTracker = 0;
            gBattleStruct->turnEffectsBattlerId++;
            break;
        }

        if (effect != 0)
            return effect;

    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);
    return 0;
}

bool8 HandleWishPerishSongOnTurnEnd(void)
{
    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);

    switch (gBattleStruct->wishPerishSongState)
    {
    case 0:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattleStruct->wishPerishSongBattlerId;
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }

            gBattleStruct->wishPerishSongBattlerId++;
            if (gWishFutureKnock.futureSightCounter[gActiveBattler] != 0
             && --gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
             && gBattleMons[gActiveBattler].hp != 0)
            {
                if (gWishFutureKnock.futureSightMove[gActiveBattler] == MOVE_FUTURE_SIGHT)
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FUTURE_SIGHT;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOOM_DESIRE;

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gWishFutureKnock.futureSightMove[gActiveBattler]);

                gBattlerTarget = gActiveBattler;
                gBattlerAttacker = gWishFutureKnock.futureSightAttacker[gActiveBattler];
                gSpecialStatuses[gBattlerTarget].dmg = 0xFFFF;
                gCurrentMove = gWishFutureKnock.futureSightMove[gActiveBattler];
                SetTypeBeforeUsingMove(gCurrentMove, gActiveBattler);
                BattleScriptExecute(BattleScript_MonTookFutureAttack);

                if (gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
                 && gWishFutureKnock.futureSightCounter[gActiveBattler ^ BIT_FLANK] == 0)
                {
                    gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] &= ~(SIDE_STATUS_FUTUREATTACK);
                }
                return TRUE;
            }
        }
        gBattleStruct->wishPerishSongState = 1;
        gBattleStruct->wishPerishSongBattlerId = 0;
        // fall through
    case 1:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->wishPerishSongBattlerId];
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }
            gBattleStruct->wishPerishSongBattlerId++;
            if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG)
            {
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gActiveBattler].perishSongTimer);
                if (gDisableStructs[gActiveBattler].perishSongTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~STATUS3_PERISH_SONG;
                    gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
                    gBattlescriptCurrInstr = BattleScript_PerishSongTakesLife;
                }
                else
                {
                    gDisableStructs[gActiveBattler].perishSongTimer--;
                    gBattlescriptCurrInstr = BattleScript_PerishSongCountGoesDown;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                return TRUE;
            }
        }
        // Hm...
        {
            u8 *state = &gBattleStruct->wishPerishSongState;
            *state = 2;
            gBattleStruct->wishPerishSongBattlerId = 0;
        }
        // fall through
    case 2:
        if ((gBattleTypeFlags & BATTLE_TYPE_ARENA)
         && gBattleStruct->arenaTurnCounter == 2
         && gBattleMons[0].hp != 0 && gBattleMons[1].hp != 0)
        {
            s32 i;

            for (i = 0; i < 2; i++)
                CancelMultiTurnMoves(i);

            gBattlescriptCurrInstr = BattleScript_ArenaDoJudgment;
            BattleScriptExecute(BattleScript_ArenaDoJudgment);
            gBattleStruct->wishPerishSongState++;
            return TRUE;
        }
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);

    return FALSE;
}

#define FAINTED_ACTIONS_MAX_CASE 7

bool8 HandleFaintedMonActions(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;
    do
    {
        s32 i;
        switch (gBattleStruct->faintedActionsState)
        {
        case 0:
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & gBitTable[i] && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(gBitTable[i]);
            }
            // fall through
        case 1:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gBattleStruct->givenExpMons & gBitTable[gBattlerPartyIndexes[gBattleStruct->faintedActionsBattlerId]])
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gBattleStruct->faintedActionsState = 2;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 3;
            break;
        case 2:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 3;
            else
                gBattleStruct->faintedActionsState = 1;

            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                gAbsentBattlerFlags |= gBitTable[gBattlerFainted];
                return FALSE;
            }
            break;
        case 3:
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                return FALSE;
            }
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            // fall through
        case 4:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gBattleStruct->faintedActionsState = 5;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 6;
            break;
        case 5:
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 6;
            else
                gBattleStruct->faintedActionsState = 4;
            break;
        case 6:
            if (ItemBattleEffects(1, 0, TRUE))
                return TRUE;
            gBattleStruct->faintedActionsState++;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gBattleStruct->faintedActionsState != FAINTED_ACTIONS_MAX_CASE);
    return FALSE;
}

void TryClearRageAndFuryCutter(void)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gChosenMoveByBattler[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~(STATUS2_RAGE);
        if (gDisableStructs[i].furyCutterCounter != 0 && gChosenMoveByBattler[i] != MOVE_FURY_CUTTER)
            gDisableStructs[i].furyCutterCounter = 0;
    }
}

enum
{
    CANCELLER_FLAGS,
    CANCELLER_ASLEEP,
    CANCELLER_FROZEN,
    CANCELLER_TRUANT,
    CANCELLER_RECHARGE,
    CANCELLER_FLINCH,
    CANCELLER_DISABLED,
    CANCELLER_GRAVITY,
    CANCELLER_HEAL_BLOCKED,
    CANCELLER_TAUNTED,
    CANCELLER_IMPRISONED,
    CANCELLER_CONFUSED,
    CANCELLER_PARALYSED,
    CANCELLER_IN_LOVE,
    CANCELLER_BIDE,
    CANCELLER_THAW,
    CANCELLER_POWDER_MOVE,
    CANCELLER_POWDER_STATUS,
    CANCELLER_THROAT_CHOP,
    CANCELLER_END,
    CANCELLER_PSYCHIC_TERRAIN,
    CANCELLER_END2,
};

u8 AtkCanceller_UnableToUseMove(void)
{
    u8 effect = 0;
    s32 *bideDmg = &gBattleScripting.bideDmg;
    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_FLAGS: // flags clear
            gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_DESTINY_BOND);
            gStatuses3[gBattlerAttacker] &= ~(STATUS3_GRUDGE);
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_ASLEEP: // check being asleep
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
            {
                if (UproarWakeUpCheck(gBattlerAttacker))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u8 toSub;
                    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                    else
                        gBattleMons[gBattlerAttacker].status1 -= toSub;
                    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                    {
                        if (gChosenMove != MOVE_SNORE && gChosenMove != MOVE_SLEEP_TALK)
                        {
                            gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                            effect = 2;
                        }
                    }
                    else
                    {
                        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                        BattleScriptPushCursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_FROZEN: // check being frozen
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE && !(gBattleMoves[gCurrentMove].flags & FLAG_THAW_USER))
            {
                if (Random() % 5)
                {
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                }
                else // unfreeze
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_TRUANT: // truant
            if (gBattleMons[gBattlerAttacker].ability == ABILITY_TRUANT && gDisableStructs[gBattlerAttacker].truantCounter)
            {
                CancelMultiTurnMoves(gBattlerAttacker);
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LOAFING;
                gBattlerAbility = gBattlerAttacker;
                gBattlescriptCurrInstr = BattleScript_TruantLoafingAround;
                gMoveResultFlags |= MOVE_RESULT_MISSED;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_RECHARGE: // recharge
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
            {
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_RECHARGE);
                gDisableStructs[gBattlerAttacker].rechargeTimer = 0;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_FLINCH: // flinch
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FLINCHED)
            {
                gProtectStructs[gBattlerAttacker].flinchImmobility = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_DISABLED: // disabled move
            if (gDisableStructs[gBattlerAttacker].disabledMove == gCurrentMove && gDisableStructs[gBattlerAttacker].disabledMove != 0)
            {
                gProtectStructs[gBattlerAttacker].usedDisabledMove = 1;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_HEAL_BLOCKED:
            if (gStatuses3[gBattlerAttacker] & STATUS3_HEAL_BLOCK && IsHealBlockPreventingMove(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedHealBlockedMove = 1;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedHealBlockPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && IsGravityPreventingMove(gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedGravityPreventedMove = 1;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedGravityPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_TAUNTED: // taunt
            if (gDisableStructs[gBattlerAttacker].tauntTimer && gBattleMoves[gCurrentMove].power == 0)
            {
                gProtectStructs[gBattlerAttacker].usedTauntedMove = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_IMPRISONED: // imprisoned
            if (GetImprisonedMovesCount(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedImprisonedMove = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_CONFUSED: // confusion
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_CONFUSION_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
                {
                    if (Random() % ((B_CONFUSION_SELF_DMG_CHANCE >= GEN_7) ? 3 : 2) == 0) // confusion dmg
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                        gBattlerTarget = gBattlerAttacker;
                        gBattleMoveDamage = CalculateMoveDamage(MOVE_NONE, gBattlerAttacker, gBattlerAttacker, TYPE_MYSTERY, 40, FALSE, FALSE, TRUE);
                        gProtectStructs[gBattlerAttacker].confusionSelfDmg = 1;
                        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                        BattleScriptPushCursor();
                    }
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                }
                else // snapped out of confusion
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_PARALYSED: // paralysis
            if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && (Random() % 4) == 0)
            {
                gProtectStructs[gBattlerAttacker].prlzImmobility = 1;
                // This is removed in Emerald for some reason
                //CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_IN_LOVE: // infatuation
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
            {
                gBattleScripting.battler = CountTrailingZeroBits((gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION) >> 0x10);
                if (Random() & 1)
                {
                    BattleScriptPushCursor();
                }
                else
                {
                    BattleScriptPush(BattleScript_MoveUsedIsInLoveCantAttack);
                    gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    gProtectStructs[gBattlerAttacker].loveImmobility = 1;
                    CancelMultiTurnMoves(gBattlerAttacker);
                }
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_BIDE: // bide
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_BIDE_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
                {
                    gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
                }
                else
                {
                    // This is removed in Emerald for some reason
                    //gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
                    if (gTakenDmg[gBattlerAttacker])
                    {
                        gCurrentMove = MOVE_BIDE;
                        *bideDmg = gTakenDmg[gBattlerAttacker] * 2;
                        gBattlerTarget = gTakenDmgByBattler[gBattlerAttacker];
                        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                            gBattlerTarget = GetMoveTarget(MOVE_BIDE, 1);
                        gBattlescriptCurrInstr = BattleScript_BideAttack;
                    }
                    else
                    {
                        gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
                    }
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_THAW: // move thawing
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE)
            {
                if (!(gBattleMoves[gCurrentMove].effect == EFFECT_BURN_UP && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_FIRE)))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED_BY_MOVE;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_MOVE:
            if ((gBattleMoves[gCurrentMove].flags & FLAG_POWDER) && (gBattlerAttacker != gBattlerTarget))
            {
                if ((B_POWDER_GRASS >= GEN_6 && IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS))
                    || GetBattlerAbility(gBattlerTarget) == ABILITY_OVERCOAT)
                {
                    gBattlerAbility = gBattlerTarget;
                    effect = 1;
                }
                else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_SAFETY_GOGGLES)
                {
                    RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_SAFETY_GOGGLES);
                    gLastUsedItem = gBattleMons[gBattlerTarget].item;
                    effect = 1;
                }

                if (effect)
                    gBattlescriptCurrInstr = BattleScript_PowderMoveNoEffect;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_STATUS:
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_POWDER)
            {
                u32 moveType;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (moveType == TYPE_FIRE)
                {
                    gProtectStructs[gBattlerAttacker].powderSelfDmg = 1;
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedPowder;
                    effect = 1;
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_THROAT_CHOP:
            if (gDisableStructs[gBattlerAttacker].throatChopTimer && gBattleMoves[gCurrentMove].flags & FLAG_SOUND)
            {
                gProtectStructs[gBattlerAttacker].usedThroatChopPreventedMove = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsThroatChopPrevented;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_END:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END && gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    if (effect == 2)
    {
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    return effect;
}

// After Protean Activation.
u8 AtkCanceller_UnableToUseMove2(void)
{
    u8 effect = 0;

    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_END:
            gBattleStruct->atkCancellerTracker++;
        case CANCELLER_PSYCHIC_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN
                && IsBattlerGrounded(gBattlerTarget)
                && GetChosenMovePriority(gBattlerAttacker) > 0
                && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedPsychicTerrainPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_END2:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    return effect;
}

bool8 HasNoMonsToSwitch(u8 battler, u8 partyIdBattlerOn1, u8 partyIdBattlerOn2)
{
    struct Pokemon *party;
    u8 id1, id2;
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        id2 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        id1 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        party = gEnemyParty;

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[id2];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[id1];

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != *(gBattleStruct->monToSwitchIntoId + id2) && i != id1[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        id1 = ((battler & BIT_FLANK) / 2);
        for (i = id1 * 3; i < id1 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 * 3 + 3);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;
                id2 = GetBattlerMultiplayerId(battler);
                id1 = GetLinkTrainerFlankId(id2);
            }
            else
            {
                party = gEnemyParty;
                if (battler == 1)
                    id1 = 0;
                else
                    id1 = 1;
            }
        }
        else
        {
            id2 = GetBattlerMultiplayerId(battler);

            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                party = gPlayerParty;
            else
                party = gEnemyParty;

            id1 = GetLinkTrainerFlankId(id2);
        }

        for (i = id1 * 3; i < id1 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 * 3 + 3);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        if (battler == 1)
            id1 = 0;
        else
            id1 = 3;

        for (i = id1; i < id1 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 + 3);
    }
    else
    {
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        {
            id2 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            id1 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            party = gEnemyParty;
        }
        else
        {
            id2 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            id1 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            party = gPlayerParty;
        }

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[id2];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[id1];

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != *(gBattleStruct->monToSwitchIntoId + id2) && i != id1[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == PARTY_SIZE);
    }
}

u8 TryWeatherFormChange(u8 battler)
{
    u8 ret = 0;
    bool32 weatherEffect = WEATHER_HAS_EFFECT;

    if (gBattleMons[battler].species == SPECIES_CASTFORM)
    {
        if (gBattleMons[battler].ability != ABILITY_FORECAST || gBattleMons[battler].hp == 0)
        {
            ret = 0;
        }
        else if (!weatherEffect && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
        {
            SET_BATTLER_TYPE(battler, TYPE_NORMAL);
            ret = 1;
        }
        else if (!weatherEffect)
        {
            ret = 0;
        }
        else if (!(gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SUN_ANY | WEATHER_HAIL_ANY)) && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
        {
            SET_BATTLER_TYPE(battler, TYPE_NORMAL);
            ret = 1;
        }
        else if (gBattleWeather & WEATHER_SUN_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_FIRE))
        {
            SET_BATTLER_TYPE(battler, TYPE_FIRE);
            ret = 2;
        }
        else if (gBattleWeather & WEATHER_RAIN_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_WATER))
        {
            SET_BATTLER_TYPE(battler, TYPE_WATER);
            ret = 3;
        }
        else if (gBattleWeather & WEATHER_HAIL_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_ICE))
        {
            SET_BATTLER_TYPE(battler, TYPE_ICE);
            ret = 4;
        }
    }
    else if (gBattleMons[battler].species == SPECIES_CHERRIM)
    {
        if (gBattleMons[battler].ability != ABILITY_FLOWER_GIFT || gBattleMons[battler].hp == 0)
            ret = 0;
        else if (gBattleMonForms[battler] == 0 && weatherEffect && gBattleWeather & WEATHER_SUN_ANY)
            ret = 2;
        else if (gBattleMonForms[battler] != 0 && (!weatherEffect || !(gBattleWeather & WEATHER_SUN_ANY)))
            ret = 1;
    }

    return ret;
}
static const u16 sWeatherFlagsInfo[][3] =
{
    [ENUM_WEATHER_RAIN] = {WEATHER_RAIN_TEMPORARY, WEATHER_RAIN_PERMANENT, HOLD_EFFECT_DAMP_ROCK},
    [ENUM_WEATHER_RAIN_PRIMAL] = {WEATHER_RAIN_PRIMAL, WEATHER_RAIN_PRIMAL, HOLD_EFFECT_DAMP_ROCK},
    [ENUM_WEATHER_SUN] = {WEATHER_SUN_TEMPORARY, WEATHER_SUN_PERMANENT, HOLD_EFFECT_HEAT_ROCK},
    [ENUM_WEATHER_SUN_PRIMAL] = {WEATHER_SUN_PRIMAL, WEATHER_SUN_PRIMAL, HOLD_EFFECT_HEAT_ROCK},
    [ENUM_WEATHER_SANDSTORM] = {WEATHER_SANDSTORM_TEMPORARY, WEATHER_SANDSTORM_PERMANENT, HOLD_EFFECT_SMOOTH_ROCK},
    [ENUM_WEATHER_HAIL] = {WEATHER_HAIL_TEMPORARY, WEATHER_HAIL_PERMANENT, HOLD_EFFECT_ICY_ROCK},
    [ENUM_WEATHER_STRONG_WINDS] = {WEATHER_STRONG_WINDS, WEATHER_STRONG_WINDS, HOLD_EFFECT_NONE},
};

bool32 TryChangeBattleWeather(u8 battler, u32 weatherEnumId, bool32 viaAbility)
{
    if (viaAbility && B_ABILITY_WEATHER <= GEN_5
        && !(gBattleWeather & sWeatherFlagsInfo[weatherEnumId][1]))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1]);
        return TRUE;
    }
    else if (gBattleWeather & WEATHER_PRIMAL_ANY
          && GetBattlerAbility(battler) != ABILITY_DESOLATE_LAND
          && GetBattlerAbility(battler) != ABILITY_PRIMORDIAL_SEA
          && GetBattlerAbility(battler) != ABILITY_DELTA_STREAM)
    {
        return FALSE;
    }
    else if (!(gBattleWeather & (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1])))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0]);
        if (GetBattlerHoldEffect(battler, TRUE) == sWeatherFlagsInfo[weatherEnumId][2])
            gWishFutureKnock.weatherDuration = 8;
        else
            gWishFutureKnock.weatherDuration = 5;

        return TRUE;
    }

    return FALSE;
}

static bool32 TryChangeBattleTerrain(u32 battler, u32 statusFlag, u8 *timer)
{
    if (!(gFieldStatuses & statusFlag))
    {
        gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_GRASSY_TERRAIN | EFFECT_ELECTRIC_TERRAIN | EFFECT_PSYCHIC_TERRAIN);
        gFieldStatuses |= statusFlag;

        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
            *timer = 8;
        else
            *timer = 5;

        gBattlerAttacker = gBattleScripting.battler = battler;
        return TRUE;
    }

    return FALSE;
}

static bool32 ShouldChangeFormHpBased(u32 battler)
{
    // Ability,     form >, form <=, hp divided
    static const u16 forms[][4] =
    {
        {ABILITY_ZEN_MODE, SPECIES_DARMANITAN, SPECIES_DARMANITAN_ZEN_MODE, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR, SPECIES_MINIOR_CORE_RED, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_BLUE, SPECIES_MINIOR_CORE_BLUE, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_GREEN, SPECIES_MINIOR_CORE_GREEN, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_INDIGO, SPECIES_MINIOR_CORE_INDIGO, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_ORANGE, SPECIES_MINIOR_CORE_ORANGE, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_VIOLET, SPECIES_MINIOR_CORE_VIOLET, 2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_YELLOW, SPECIES_MINIOR_CORE_YELLOW, 2},
        {ABILITY_SCHOOLING, SPECIES_WISHIWASHI_SCHOOL, SPECIES_WISHIWASHI, 4},
        {ABILITY_GULP_MISSILE, SPECIES_CRAMORANT, SPECIES_CRAMORANT_GORGING, 2},
        {ABILITY_GULP_MISSILE, SPECIES_CRAMORANT, SPECIES_CRAMORANT_GULPING, 1},
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(forms); i++)
    {
        if (gBattleMons[battler].ability == forms[i][0])
        {
            if (gBattleMons[battler].species == forms[i][2]
                && gBattleMons[battler].hp > gBattleMons[battler].maxHP / forms[i][3])
            {
                gBattleMons[battler].species = forms[i][1];
                return TRUE;
            }
            if (gBattleMons[battler].species == forms[i][1]
                && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / forms[i][3])
            {
                gBattleMons[battler].species = forms[i][2];
                return TRUE;
            }
        }
    }
    return FALSE;
}

static u8 ForewarnChooseMove(u32 battler)
{
    struct Forewarn {
        u8 battlerId;
        u8 power;
        u16 moveId;
    };
    u32 i, j, bestId, count;
    struct Forewarn *data = malloc(sizeof(struct Forewarn) * MAX_BATTLERS_COUNT * MAX_MON_MOVES);

    // Put all moves
    for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && GetBattlerSide(i) != GetBattlerSide(battler))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[i].moves[j] == MOVE_NONE)
                    continue;
                data[count].moveId = gBattleMons[i].moves[j];
                data[count].battlerId = i;
                switch (gBattleMoves[data[count].moveId].effect)
                {
                case EFFECT_OHKO:
                    data[count].power = 150;
                    break;
                case EFFECT_COUNTER:
                case EFFECT_MIRROR_COAT:
                case EFFECT_METAL_BURST:
                    data[count].power = 120;
                    break;
                default:
                    if (gBattleMoves[data[count].moveId].power == 1)
                        data[count].power = 80;
                    else
                        data[count].power = gBattleMoves[data[count].moveId].power;
                    break;
                }
                count++;
            }
        }
    }

    for (bestId = 0, i = 1; i < count; i++)
    {
        if (data[i].power > data[bestId].power)
            bestId = i;
        else if (data[i].power == data[bestId].power && Random() & 1)
            bestId = i;
    }

    gBattlerTarget = data[bestId].battlerId;
    PREPARE_MOVE_BUFFER(gBattleTextBuff1, data[bestId].moveId)
    RecordKnownMove(gBattlerTarget, data[bestId].moveId);

    free(data);
}

u8 AbilityBattleEffects(u8 caseID, u8 battler, u16 ability, u8 special, u16 moveArg)
{
    u8 effect = 0;
    u32 speciesAtk, speciesDef;
    u32 pidAtk, pidDef;
    u32 moveType, move;
    u32 i, j;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return 0;

    if (gBattlerAttacker >= gBattlersCount)
        gBattlerAttacker = battler;

    speciesAtk = gBattleMons[gBattlerAttacker].species;
    pidAtk = gBattleMons[gBattlerAttacker].personality;

    speciesDef = gBattleMons[gBattlerTarget].species;
    pidDef = gBattleMons[gBattlerTarget].personality;

    if (special)
        gLastUsedAbility = special;
    else
        gLastUsedAbility = GetBattlerAbility(battler);

    if (moveArg)
        move = moveArg;
    else
        move = gCurrentMove;

    GET_MOVE_TYPE(move, moveType);

    switch (caseID)
    {
    case ABILITYEFFECT_ON_SWITCHIN: // 0
        gBattleScripting.battler = battler;
        switch (gLastUsedAbility)
        {
        case ABILITYEFFECT_SWITCH_IN_TERRAIN:
            if (VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY)
            {
                u16 terrainFlags = VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY;    // only works for status flag (1 << 15)
                gFieldStatuses = terrainFlags | STATUS_FIELD_TERRAIN_PERMANENT; // terrain is permanent
                switch (VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY)
                {
                case STATUS_FIELD_ELECTRIC_TERRAIN:
                    gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                    break;
                case STATUS_FIELD_MISTY_TERRAIN:
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    break;
                case STATUS_FIELD_GRASSY_TERRAIN:
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    break;
                case STATUS_FIELD_PSYCHIC_TERRAIN:
                    gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                    break;
                }

                BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
                effect++;
            }
            #if B_THUNDERSTORM_TERRAIN == TRUE
            else if (GetCurrentWeather() == WEATHER_RAIN_THUNDERSTORM && !(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN))
            {
                // overworld weather started rain, so just do electric terrain anim
                gFieldStatuses = (STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_TERRAIN_PERMANENT);
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
                effect++;
            }
            #endif
            break;
        case ABILITYEFFECT_SWITCH_IN_WEATHER:
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
            {
                switch (GetCurrentWeather())
                {
                case WEATHER_RAIN:
                case WEATHER_RAIN_THUNDERSTORM:
                case WEATHER_DOWNPOUR:
                    if (!(gBattleWeather & WEATHER_RAIN_ANY))
                    {
                        gBattleWeather = (WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_PERMANENT);
                        gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
                        effect++;
                    }
                    break;
                case WEATHER_SANDSTORM:
                    if (!(gBattleWeather & WEATHER_SANDSTORM_ANY))
                    {
                        gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                        gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                        effect++;
                    }
                    break;
                case WEATHER_DROUGHT:
                    if (!(gBattleWeather & WEATHER_SUN_ANY))
                    {
                        gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                        gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
                        effect++;
                    }
                    break;
                }
            }
            if (effect)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeather();
                BattleScriptPushCursorAndCallback(BattleScript_OverworldWeatherStarts);
            }
            break;
        case ABILITY_IMPOSTER:
            if (IsBattlerAlive(BATTLE_OPPOSITE(battler))
                && !(gBattleMons[BATTLE_OPPOSITE(battler)].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))
                && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED)
                && !(gBattleStruct->illusion[BATTLE_OPPOSITE(battler)].on)
                && !(gStatuses3[BATTLE_OPPOSITE(battler)] & STATUS3_SEMI_INVULNERABLE))
            {
                gBattlerAttacker = battler;
                gBattlerTarget = BATTLE_OPPOSITE(battler);
                BattleScriptPushCursorAndCallback(BattleScript_ImposterActivates);
                effect++;
            }
            break;
        case ABILITY_MOLD_BREAKER:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_MOLDBREAKER;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TERAVOLT:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TERAVOLT;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TURBOBLAZE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TURBOBLAZE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SLOW_START:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gDisableStructs[battler].slowStartTimer = 5;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SLOWSTART;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_UNNERVE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_UNNERVE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AS_ONE_ICE_RIDER:
        case ABILITY_AS_ONE_SHADOW_RIDER:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ASONE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_ActivateAsOne);
                effect++;
            }
            break;
        case ABILITY_CURIOUS_MEDICINE:
            if (!gSpecialStatuses[battler].switchInAbilityDone && IsDoubleBattle()
              && IsBattlerAlive(BATTLE_PARTNER(battler)) && TryResetBattlerStatChanges(BATTLE_PARTNER(battler)))
            {
                u32 i;
                gEffectBattler = BATTLE_PARTNER(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CURIOUS_MEDICINE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_ANTICIPATION:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                u32 side = GetBattlerSide(battler);

                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (IsBattlerAlive(i) && side != GetBattlerSide(i))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            move = gBattleMons[i].moves[j];
                            GET_MOVE_TYPE(move, moveType);
                            if (CalcTypeEffectivenessMultiplier(move, moveType, i, battler, FALSE) >= UQ_4_12(2.0))
                            {
                                effect++;
                                break;
                            }
                        }
                    }
                }

                if (effect)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ANTICIPATION;
                    gSpecialStatuses[battler].switchInAbilityDone = 1;
                    BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                }
            }
            break;
        case ABILITY_FRISK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_FriskActivates); // Try activate
                effect++;
            }
            return effect; // Note: It returns effect as to not record the ability if Frisk does not activate.
        case ABILITY_FOREWARN:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                ForewarnChooseMove(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FOREWARN;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DOWNLOAD:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                u32 statId, opposingBattler;
                u32 opposingDef = 0, opposingSpDef = 0;

                opposingBattler = BATTLE_OPPOSITE(battler);
                for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
                {
                    if (IsBattlerAlive(opposingBattler))
                    {
                        opposingDef += gBattleMons[opposingBattler].defense
                                    * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][0]
                                    / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][1];
                        opposingSpDef += gBattleMons[opposingBattler].spDefense
                                      * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][0]
                                      / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][1];
                    }
                }

                if (opposingDef < opposingSpDef)
                    statId = STAT_ATK;
                else
                    statId = STAT_SPATK;

                gSpecialStatuses[battler].switchInAbilityDone = 1;

                if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    gBattleMons[battler].statStages[statId]++;
                    SET_STATCHANGER(statId, 1, FALSE);
                    gBattlerAttacker = battler;
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                    effect++;
                }
            }
            break;
        case ABILITY_PRESSURE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DARK_AURA:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_DARKAURA;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_FAIRY_AURA:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AURA_BREAK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_AURABREAK;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_COMATOSE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COMATOSE;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SCREEN_CLEANER:
            if (!gSpecialStatuses[battler].switchInAbilityDone && TryRemoveScreens(battler))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SCREENCLEANER;
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DRIZZLE:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
                effect++;
            }
            else if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_PRIMAL_ANY && !gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
            break;
        case ABILITY_SAND_STREAM:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SandstreamActivates);
                effect++;
            }
            else if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_PRIMAL_ANY && !gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
            break;
        case ABILITY_DROUGHT:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SUN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DroughtActivates);
                effect++;
            }
            else if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_PRIMAL_ANY && !gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
            break;
        case ABILITY_SNOW_WARNING:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_HAIL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SnowWarningActivates);
                effect++;
            }
            else if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_PRIMAL_ANY && !gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
            break;
        case ABILITY_ELECTRIC_SURGE:
            if (TryChangeBattleTerrain(battler, STATUS_FIELD_ELECTRIC_TERRAIN, &gFieldTimers.electricTerrainTimer))
            {
                BattleScriptPushCursorAndCallback(BattleScript_ElectricSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_GRASSY_SURGE:
            if (TryChangeBattleTerrain(battler, STATUS_FIELD_GRASSY_TERRAIN, &gFieldTimers.grassyTerrainTimer))
            {
                BattleScriptPushCursorAndCallback(BattleScript_GrassySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_MISTY_SURGE:
            if (TryChangeBattleTerrain(battler, STATUS_FIELD_MISTY_TERRAIN, &gFieldTimers.mistyTerrainTimer))
            {
                BattleScriptPushCursorAndCallback(BattleScript_MistySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_PSYCHIC_SURGE:
            if (TryChangeBattleTerrain(battler, STATUS_FIELD_PSYCHIC_TERRAIN, &gFieldTimers.psychicTerrainTimer))
            {
                BattleScriptPushCursorAndCallback(BattleScript_PsychicSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_INTIMIDATE:
            if (!(gSpecialStatuses[battler].intimidatedMon))
            {
                gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_INTIMIDATED;
                gSpecialStatuses[battler].intimidatedMon = 1;
            }
            break;
        case ABILITY_FORECAST:
        case ABILITY_FLOWER_GIFT:
            effect = TryWeatherFormChange(battler);
            if (effect != 0)
            {
                BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                *(&gBattleStruct->formToChangeInto) = effect - 1;
            }
            break;
        case ABILITY_TRACE:
            if (!(gSpecialStatuses[battler].traced))
            {
                gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_TRACED;
                gSpecialStatuses[battler].traced = 1;
            }
            break;
        case ABILITY_CLOUD_NINE:
        case ABILITY_AIR_LOCK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                BattleScriptPushCursorAndCallback(BattleScript_AnnounceAirLockCloudNine);
                effect++;
            }
            break;
        case ABILITY_SCHOOLING:
            if (gBattleMons[battler].level < 20)
                break;
        case ABILITY_SHIELDS_DOWN:
            if (ShouldChangeFormHpBased(battler))
            {
                BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                effect++;
            }
            break;
        case ABILITY_INTREPID_SWORD:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                SET_STATCHANGER(STAT_ATK, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
            break;
        case ABILITY_DAUNTLESS_SHIELD:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = 1;
                SET_STATCHANGER(STAT_DEF, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
            break;
        case ABILITY_DESOLATE_LAND:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SUN_PRIMAL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DesolateLandActivates);
                effect++;
            }
            break;
        case ABILITY_PRIMORDIAL_SEA:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN_PRIMAL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_PrimordialSeaActivates);
                effect++;
            }
            break;
        case ABILITY_DELTA_STREAM:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_STRONG_WINDS, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DeltaStreamActivates);
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_ENDTURN: // 1
        if (gBattleMons[battler].hp != 0)
        {
            gBattlerAttacker = battler;
            switch (gLastUsedAbility)
            {
            case ABILITY_HARVEST:
                if (((WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY) || Random() % 2 == 0)
                 && gBattleMons[battler].item == ITEM_NONE
                 && gBattleStruct->changedItems[battler] == ITEM_NONE
                 && ItemId_GetPocket(gBattleStruct->usedHeldItems[battler]) == POCKET_BERRIES)
                {
                    gLastUsedItem = gBattleStruct->changedItems[battler] = gBattleStruct->usedHeldItems[battler];
                    gBattleStruct->usedHeldItems[battler] = ITEM_NONE;
                    BattleScriptPushCursorAndCallback(BattleScript_HarvestActivates);
                    effect++;
                }
                break;
            case ABILITY_DRY_SKIN:
                if (gBattleWeather & WEATHER_SUN_ANY)
                    goto SOLAR_POWER_HP_DROP;
            // Dry Skin works similarly to Rain Dish in Rain
            case ABILITY_RAIN_DISH:
                if (WEATHER_HAS_EFFECT
                 && (gBattleWeather & WEATHER_RAIN_ANY)
                 && !BATTLER_MAX_HP(battler)
                 && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / (gLastUsedAbility == ABILITY_RAIN_DISH ? 16 : 8);
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
                break;
            case ABILITY_HYDRATION:
                if (WEATHER_HAS_EFFECT
                 && (gBattleWeather & WEATHER_RAIN_ANY)
                 && gBattleMons[battler].status1 & STATUS1_ANY)
                {
                    goto ABILITY_HEAL_MON_STATUS;
                }
                break;
            case ABILITY_SHED_SKIN:
                if ((gBattleMons[battler].status1 & STATUS1_ANY) && (Random() % 3) == 0)
                {
                ABILITY_HEAL_MON_STATUS:
                    if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);

                    gBattleMons[battler].status1 = 0;
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    gBattleScripting.battler = gActiveBattler = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_ShedSkinActivates);
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    effect++;
                }
                break;
            case ABILITY_SPEED_BOOST:
                if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) && gDisableStructs[battler].isFirstTurn != 2)
                {
                    gBattleMons[battler].statStages[STAT_SPEED]++;
                    gBattleScripting.animArg1 = 14 + STAT_SPEED;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_MOODY:
                if (gDisableStructs[battler].isFirstTurn != 2)
                {
                    u32 validToRaise = 0, validToLower = 0;
                    u32 statsNum = (B_MOODY_ACC_EVASION != GEN_8) ? NUM_BATTLE_STATS : NUM_STATS;

                    for (i = STAT_ATK; i < statsNum; i++)
                    {
                        if (CompareStat(battler, i, MIN_STAT_STAGE, CMP_GREATER_THAN))
                            validToLower |= gBitTable[i];
                        if (CompareStat(battler, i, MAX_STAT_STAGE, CMP_LESS_THAN))
                            validToRaise |= gBitTable[i];
                    }

                    if (validToLower != 0 || validToRaise != 0) // Can lower one stat, or can raise one stat
                    {
                        gBattleScripting.statChanger = gBattleScripting.savedStatChanger = 0; // for raising and lowering stat respectively
                        if (validToRaise != 0) // Find stat to raise
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToRaise & gBitTable[i]));
                            SET_STATCHANGER(i, 2, FALSE);
                            validToLower &= ~(gBitTable[i]); // Can't lower the same stat as raising.
                        }
                        if (validToLower != 0) // Find stat to lower
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToLower & gBitTable[i]));
                            SET_STATCHANGER2(gBattleScripting.savedStatChanger, i, 1, TRUE);
                        }
                        BattleScriptPushCursorAndCallback(BattleScript_MoodyActivates);
                        effect++;
                    }
                }
                break;
            case ABILITY_TRUANT:
                gDisableStructs[gBattlerAttacker].truantCounter ^= 1;
                break;
            case ABILITY_BAD_DREAMS:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP
                    || gBattleMons[BATTLE_OPPOSITE(battler)].status1 & STATUS1_SLEEP
                    || GetBattlerAbility(battler) == ABILITY_COMATOSE
                    || GetBattlerAbility(BATTLE_OPPOSITE(battler)) == ABILITY_COMATOSE)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_BadDreamsActivates);
                    effect++;
                }
                break;
            SOLAR_POWER_HP_DROP:
            case ABILITY_SOLAR_POWER:
                if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_SolarPowerActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect++;
                }
                break;
            case ABILITY_HEALER:
                gBattleScripting.battler = BATTLE_PARTNER(battler);
                if (IsBattlerAlive(gBattleScripting.battler)
                    && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY
                    && (Random() % 100) < 30)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_HealerActivates);
                    effect++;
                }
                break;
            case ABILITY_SCHOOLING:
                if (gBattleMons[battler].level < 20)
                    break;
            case ABILITY_ZEN_MODE:
            case ABILITY_SHIELDS_DOWN:
                if ((effect = ShouldChangeFormHpBased(battler)))
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                break;
            case ABILITY_POWER_CONSTRUCT:
                if ((gBattleMons[battler].species == SPECIES_ZYGARDE || gBattleMons[battler].species == SPECIES_ZYGARDE_10)
                    && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[battler]] = gBattleMons[battler].species;
                    gBattleMons[battler].species = SPECIES_ZYGARDE_COMPLETE;
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                    effect++;
                }
                break;
            case ABILITY_BALL_FETCH:
                if (gBattleMons[battler].item == ITEM_NONE
                    && gBattleResults.catchAttempts[gLastUsedBall - ITEM_ULTRA_BALL] >= 1
                    && !gHasFetchedBall)
                {
                    gBattleScripting.battler = battler;
                    BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedBall);
                    MarkBattlerForControllerExec(battler);
                    gHasFetchedBall = TRUE;
                    gLastUsedItem = gLastUsedBall;
                    BattleScriptPushCursorAndCallback(BattleScript_BallFetch);
                    effect++;
                }
                break;
            }
        }
        break;
    case ABILITYEFFECT_MOVES_BLOCK: // 2
        if ((gLastUsedAbility == ABILITY_SOUNDPROOF && gBattleMoves[move].flags & FLAG_SOUND && !(gBattleMoves[move].target & MOVE_TARGET_USER))
            || (gLastUsedAbility == ABILITY_BULLETPROOF && gBattleMoves[move].flags & FLAG_BALLISTIC))
        {
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if ((((gLastUsedAbility == ABILITY_DAZZLING || gLastUsedAbility == ABILITY_QUEENLY_MAJESTY
                   || (IsBattlerAlive(battler ^= BIT_FLANK)
                       && ((GetBattlerAbility(battler) == ABILITY_DAZZLING) || GetBattlerAbility(battler) == ABILITY_QUEENLY_MAJESTY)))
                   ))
                 && GetChosenMovePriority(gBattlerAttacker) > 0
                 && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(battler))
        {
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_DazzlingProtected;
            effect = 1;
        }
        else if (BlocksPrankster(move, gBattlerAttacker, gBattlerTarget, TRUE)
          && !(IS_MOVE_STATUS(move) && GetBattlerAbility(gBattlerTarget) == ABILITY_MAGIC_BOUNCE))
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE) || !(gBattleMoves[move].target & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
                CancelMultiTurnMoves(gBattlerAttacker); // Don't cancel moves that can hit two targets bc one target might not be protected
            gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
            gBattlescriptCurrInstr = BattleScript_DarkTypePreventsPrankster;
            effect = 1;
        }
        
        break;
    case ABILITYEFFECT_ABSORBING: // 3
        if (move != MOVE_NONE)
        {
            u8 statId;
            switch (gLastUsedAbility)
            {
            case ABILITY_VOLT_ABSORB:
                if (moveType == TYPE_ELECTRIC)
                    effect = 1;
                break;
            case ABILITY_WATER_ABSORB:
            case ABILITY_DRY_SKIN:
                if (moveType == TYPE_WATER)
                    effect = 1;
                break;
            case ABILITY_MOTOR_DRIVE:
                if (moveType == TYPE_ELECTRIC)
                    effect = 2, statId = STAT_SPEED;
                break;
            case ABILITY_LIGHTNING_ROD:
                if (moveType == TYPE_ELECTRIC)
                    effect = 2, statId = STAT_SPATK;
                break;
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER)
                    effect = 2, statId = STAT_SPATK;
                break;
            case ABILITY_SAP_SIPPER:
                if (moveType == TYPE_GRASS)
                    effect = 2, statId = STAT_ATK;
                break;
            case ABILITY_FLASH_FIRE:
                if (moveType == TYPE_FIRE && !((gBattleMons[battler].status1 & STATUS1_FREEZE) && B_FLASH_FIRE_FROZEN <= GEN_4))
                {
                    if (!(gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
                        effect = 3;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_NO_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        effect = 3;
                    }
                }
                break;
            }

            if (effect == 1) // Drain Hp ability.
            {
                if (BATTLER_MAX_HP(battler) || gStatuses3[battler] & STATUS3_HEAL_BLOCK)
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;

                    gBattleMoveDamage = gBattleMons[battler].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                }
            }
            else if (effect == 2) // Boost Stat ability;
            {
                if (!CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain_PPLoss;

                    SET_STATCHANGER(statId, 1, FALSE);
                    gBattleMons[battler].statStages[statId]++;
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                }
            }
        }
        break;
    case ABILITYEFFECT_MOVE_END: // Think contact abilities.
        switch (gLastUsedAbility)
        {
        case ABILITY_JUSTIFIED:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_DARK
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_ATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_SPEED, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_WATER_COMPACTION:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_WATER
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_STAMINA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_BERSERK:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
            // Had more than half of hp before, now has less
             && gBattleStruct->hpBefore[battler] > gBattleMons[battler].maxHP / 2
             && gBattleMons[battler].hp < gBattleMons[battler].maxHP / 2
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_EMERGENCY_EXIT:
        case ABILITY_WIMP_OUT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
            // Had more than half of hp before, now has less
             && gBattleStruct->hpBefore[battler] > gBattleMons[battler].maxHP / 2
             && gBattleMons[battler].hp < gBattleMons[battler].maxHP / 2
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
             && (CanBattlerSwitch(battler) || !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
             && !(gBattleTypeFlags & BATTLE_TYPE_ARENA)
             && CountUsablePartyMons(battler) > 0)
            {
                gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_EMERGENCY_EXIT;
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) // Don't activate if speed cannot be raised
               || CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN))) // Don't activate if defense cannot be lowered
            {
                if (gBattleMoves[gCurrentMove].effect == EFFECT_HIT_ESCAPE && CanBattlerSwitch(gBattlerAttacker))
                    gProtectStructs[battler].disableEjectPack = 1;  // Set flag for target

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WeakArmorActivates;
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && gDisableStructs[gBattlerAttacker].disabledMove == MOVE_NONE
             && IsBattlerAlive(gBattlerAttacker)
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0
             && (Random() % 3) == 0)
            {
                gDisableStructs[gBattlerAttacker].disabledMove = gChosenMove;
                gDisableStructs[gBattlerAttacker].disableTimer = 4;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CursedBodyActivates;
                effect++;
            }
            break;
        case ABILITY_MUMMY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
            {
                switch (gBattleMons[gBattlerAttacker].ability)
                {
                case ABILITY_MUMMY:
                case ABILITY_BATTLE_BOND:
                case ABILITY_COMATOSE:
                case ABILITY_DISGUISE:
                case ABILITY_MULTITYPE:
                case ABILITY_POWER_CONSTRUCT:
                case ABILITY_RKS_SYSTEM:
                case ABILITY_SCHOOLING:
                case ABILITY_SHIELDS_DOWN:
                case ABILITY_STANCE_CHANGE:
                    break;
                default:
                    gLastUsedAbility = gBattleMons[gBattlerAttacker].ability = ABILITY_MUMMY;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MummyActivates;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITY_ANGER_POINT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_ATK, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_ATK], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
            break;
        case ABILITY_COLOR_CHANGE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && move != MOVE_STRUGGLE
             && gBattleMoves[move].power != 0
             && TARGET_TURN_DAMAGED
             && !IS_BATTLER_OF_TYPE(battler, moveType)
             && gBattleMons[battler].hp != 0)
            {
                SET_BATTLER_TYPE(battler, moveType);
                PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ColorChangeActivates;
                effect++;
            }
            break;
        case ABILITY_GOOEY:
        case ABILITY_TANGLING_HAIR:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && CompareStat(gBattlerAttacker, STAT_SPEED, MIN_STAT_STAGE, CMP_GREATER_THAN)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_SPD_MINUS_1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_ROUGH_SKIN:
        case ABILITY_IRON_BARBS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (!IsAbilityOnField(ABILITY_DAMP)
             && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
            break;
        case ABILITY_INNARDS_OUT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker))
            {
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].dmg;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
            break;
        case ABILITY_EFFECT_SPORE:
            if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GRASS)
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OVERCOAT
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                i = Random() % 3;
                if (i == 0)
                    goto POISON_POINT;
                if (i == 1)
                    goto STATIC;
                // Sleep
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && TARGET_TURN_DAMAGED
                 && CanSleep(gBattlerAttacker)
                 && IsMoveMakingContact(move, gBattlerAttacker)
                 && (Random() % 3) == 0)
                {
                    gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_SLEEP;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
            }
            break;
        POISON_POINT:
        case ABILITY_POISON_POINT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && CanBePoisoned(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && (Random() % 3) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        STATIC:
        case ABILITY_STATIC:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && CanBeParalyzed(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && (Random() % 3) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_PARALYSIS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_FLAME_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
             && TARGET_TURN_DAMAGED
             && CanBeBurned(gBattlerAttacker)
             && (Random() % 3) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_BURN;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_CUTE_CHARM:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
             && TARGET_TURN_DAMAGED
             && gBattleMons[gBattlerTarget].hp != 0
             && (Random() % 3) == 0
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OBLIVIOUS
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != MON_GENDERLESS
             && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != MON_GENDERLESS)
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
            break;
        case ABILITY_ILLUSION:
            if (gBattleStruct->illusion[gBattlerTarget].on && !gBattleStruct->illusion[gBattlerTarget].broken && TARGET_TURN_DAMAGED)
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IllusionOff;
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED)
            {
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CottonDownActivates;
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN)
             && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
            {
                SET_STATCHANGER(STAT_SPEED, 6, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_SAND_SPIT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !(WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY))
            {
                if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_PRIMAL_ANY)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BlockedByPrimalWeatherRet;
                    effect++;
                }
                else if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
                {
                    gBattleScripting.battler = gActiveBattler = battler;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_SandSpitActivates;
                    effect++;
                }
            }
            break;
        case ABILITY_PERISH_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
             && !(gStatuses3[gBattlerAttacker] & STATUS3_PERISH_SONG))
            {
                if (!(gStatuses3[battler] & STATUS3_PERISH_SONG))
                {
                    gStatuses3[battler] |= STATUS3_PERISH_SONG;
                    gDisableStructs[battler].perishSongTimer = 3;
                    gDisableStructs[battler].perishSongTimerStartValue = 3;
                }
                gStatuses3[gBattlerAttacker] |= STATUS3_PERISH_SONG;
                gDisableStructs[gBattlerAttacker].perishSongTimer = 3;
                gDisableStructs[gBattlerAttacker].perishSongTimerStartValue = 3;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PerishBodyActivates;
                effect++;
            }
            break;
        case ABILITY_GULP_MISSILE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler))
            {
                if (gBattleMons[gBattlerTarget].species == SPECIES_CRAMORANT_GORGING)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[gBattlerTarget]] = gBattleMons[gBattlerTarget].species;
                    gBattleMons[gBattlerTarget].species = SPECIES_CRAMORANT;
                    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                    {
                        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_GulpMissileGorging;
                    effect++;
                }
                else if (gBattleMons[gBattlerTarget].species == SPECIES_CRAMORANT_GULPING)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[gBattlerTarget]] = gBattleMons[gBattlerTarget].species;
                    gBattleMons[gBattlerTarget].species = SPECIES_CRAMORANT;
                    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                    {
                        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_GulpMissileGulping;
                    effect++;
                }
            }
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER: // Same as above, but for attacker
        switch (gLastUsedAbility)
        {
        case ABILITY_POISON_TOUCH:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerTarget].confusionSelfDmg
             && CanBePoisoned(gBattlerTarget)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && (Random() % 3) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_STENCH:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && (Random() % 10) == 0
             && !IS_MOVE_STATUS(move)
             && !sMovesNotAffectedByStench[gCurrentMove])
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
                effect++;
            }
            break;
        case ABILITY_GULP_MISSILE:
            if (((gCurrentMove == MOVE_SURF && TARGET_TURN_DAMAGED) || gStatuses3[gBattlerAttacker] & STATUS3_UNDERWATER)
             && (effect = ShouldChangeFormHpBased(gBattlerAttacker)))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerFormChange;
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_OTHER: // Abilities that activate on *another* battler's moveend: Dancer, Soul-Heart, Receiver, Symbiosis
        switch (GetBattlerAbility(battler))
        {
        case ABILITY_DANCER:
            if (IsBattlerAlive(battler)
             && (gBattleMoves[gCurrentMove].flags & FLAG_DANCE)
             && !gSpecialStatuses[battler].dancerUsedMove
             && gBattlerAttacker != battler)
            {
                // Set bit and save Dancer mon's original target
                gSpecialStatuses[battler].dancerUsedMove = 1;
                gSpecialStatuses[battler].dancerOriginalTarget = *(gBattleStruct->moveTarget + battler) | 0x4;
                gBattleStruct->atkCancellerTracker = 0;
                gBattlerAttacker = gBattlerAbility = battler;
                gCalledMove = gCurrentMove;

                // Set the target to the original target of the mon that first used a Dance move
                gBattlerTarget = gBattleScripting.savedBattler & 0x3;

                // Make sure that the target isn't an ally - if it is, target the original user
                if (GetBattlerSide(gBattlerTarget) == GetBattlerSide(gBattlerAttacker))
                    gBattlerTarget = (gBattleScripting.savedBattler & 0xF0) >> 4;
                gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
                BattleScriptExecute(BattleScript_DancerActivates);
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_IMMUNITY: // 5
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            switch (gBattleMons[battler].ability)
            {
            case ABILITY_IMMUNITY:
                if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    effect = 1;
                }
                break;
            case ABILITY_OWN_TEMPO:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    effect = 2;
                }
                break;
            case ABILITY_LIMBER:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    effect = 1;
                }
                break;
            case ABILITY_INSOMNIA:
            case ABILITY_VITAL_SPIRIT:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    effect = 1;
                }
                break;
            case ABILITY_WATER_VEIL:
            case ABILITY_WATER_BUBBLE:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
                break;
            case ABILITY_MAGMA_ARMOR:
                if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    effect = 1;
                }
                break;
            case ABILITY_OBLIVIOUS:
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                    effect = 3;
                else if (gDisableStructs[battler].tauntTimer != 0)
                    effect = 4;
                break;
            }
            if (effect)
            {
                switch (effect)
                {
                case 1: // status cleared
                    gBattleMons[battler].status1 = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 2: // get rid of confusion
                    gBattleMons[battler].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 3: // get rid of infatuation
                    gBattleMons[battler].status2 &= ~(STATUS2_INFATUATION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerGotOverItsInfatuation;
                    break;
                case 4: // get rid of taunt
                    gDisableStructs[battler].tauntTimer = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerShookOffTaunt;
                    break;
                }

                gBattleScripting.battler = gActiveBattler = gBattlerAbility = battler;
                BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                return effect;
            }
        }
        break;
    case ABILITYEFFECT_FORECAST: // 6
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (gBattleMons[battler].ability == ABILITY_FORECAST || gBattleMons[battler].ability == ABILITY_FLOWER_GIFT)
            {
                effect = TryWeatherFormChange(battler);
                if (effect)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                    gBattleScripting.battler = battler;
                    gBattleStruct->formToChangeInto = effect - 1;
                    return effect;
                }
            }
        }
        break;
    case ABILITYEFFECT_SYNCHRONIZE:
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);

            if (!(gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect + MOVE_EFFECT_AFFECTS_USER;
                gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_ATK_SYNCHRONIZE: // 8
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);

            if (!(gBattleMons[gBattlerTarget].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect;
                gBattleScripting.battler = gBattlerAbility = gBattlerAttacker;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_INTIMIDATE1:
    case ABILITYEFFECT_INTIMIDATE2:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].ability == ABILITY_INTIMIDATE && gBattleResources->flags->flags[i] & RESOURCE_FLAG_INTIMIDATED)
            {
                gLastUsedAbility = ABILITY_INTIMIDATE;
                gBattleResources->flags->flags[i] &= ~(RESOURCE_FLAG_INTIMIDATED);
                if (caseID == ABILITYEFFECT_INTIMIDATE1)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_IntimidateActivatesEnd3);
                }
                else
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_IntimidateActivates;
                }
                battler = gBattlerAbility = gBattleStruct->intimidateBattler = i;
                effect++;
                break;
            }
        }
        break;
    case ABILITYEFFECT_TRACE1:
    case ABILITYEFFECT_TRACE2:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].ability == ABILITY_TRACE && (gBattleResources->flags->flags[i] & RESOURCE_FLAG_TRACED))
            {
                u8 side = (GetBattlerPosition(i) ^ BIT_SIDE) & BIT_SIDE; // side of the opposing pokemon
                u8 target1 = GetBattlerAtPosition(side);
                u8 target2 = GetBattlerAtPosition(side + BIT_FLANK);

                if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                {
                    if (!sAbilitiesNotTraced[gBattleMons[target1].ability] && gBattleMons[target1].hp != 0
                     && !sAbilitiesNotTraced[gBattleMons[target2].ability] && gBattleMons[target2].hp != 0)
                        gActiveBattler = GetBattlerAtPosition(((Random() & 1) * 2) | side), effect++;
                    else if (!sAbilitiesNotTraced[gBattleMons[target1].ability] && gBattleMons[target1].hp != 0)
                        gActiveBattler = target1, effect++;
                    else if (!sAbilitiesNotTraced[gBattleMons[target2].ability] && gBattleMons[target2].hp != 0)
                        gActiveBattler = target2, effect++;
                }
                else
                {
                    if (!sAbilitiesNotTraced[gBattleMons[target1].ability] && gBattleMons[target1].hp != 0)
                        gActiveBattler = target1, effect++;
                }

                if (effect)
                {
                    if (caseID == ABILITYEFFECT_TRACE1)
                    {
                        BattleScriptPushCursorAndCallback(BattleScript_TraceActivatesEnd3);
                    }
                    else
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_TraceActivates;
                    }
                    gBattleResources->flags->flags[i] &= ~(RESOURCE_FLAG_TRACED);
                    gBattleStruct->tracedAbility[i] = gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                    battler = gBattlerAbility = gBattleScripting.battler = i;

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
                    break;
                }
            }
        }
        break;
    }

    if (effect && gLastUsedAbility != 0xFF)
        RecordAbilityBattle(battler, gLastUsedAbility);
    if (effect && caseID <= ABILITYEFFECT_MOVE_END)
        gBattlerAbility = battler;

    return effect;
}

u32 GetBattlerAbility(u8 battlerId)
{
    if (gStatuses3[battlerId] & STATUS3_GASTRO_ACID)
        return ABILITY_NONE;
    else if ((((gBattleMons[gBattlerAttacker].ability == ABILITY_MOLD_BREAKER
            || gBattleMons[gBattlerAttacker].ability == ABILITY_TERAVOLT
            || gBattleMons[gBattlerAttacker].ability == ABILITY_TURBOBLAZE)
            && !(gStatuses3[gBattlerAttacker] & STATUS3_GASTRO_ACID))
            || gBattleMoves[gCurrentMove].flags & FLAG_TARGET_ABILITY_IGNORED)
            && sAbilitiesAffectedByMoldBreaker[gBattleMons[battlerId].ability]
            && gBattlerByTurnOrder[gCurrentTurnActionNumber] == gBattlerAttacker
            && gActionsByTurnOrder[gBattlerByTurnOrder[gBattlerAttacker]] == B_ACTION_USE_MOVE
            && gCurrentTurnActionNumber < gBattlersCount)
        return ABILITY_NONE;
    else
        return gBattleMons[battlerId].ability;
}

u32 IsAbilityOnSide(u32 battlerId, u32 ability)
{
    if (IsBattlerAlive(battlerId) && GetBattlerAbility(battlerId) == ability)
        return battlerId + 1;
    else if (IsBattlerAlive(BATTLE_PARTNER(battlerId)) && GetBattlerAbility(BATTLE_PARTNER(battlerId)) == ability)
        return BATTLE_PARTNER(battlerId) + 1;
    else
        return 0;
}

u32 IsAbilityOnOpposingSide(u32 battlerId, u32 ability)
{
    return IsAbilityOnSide(BATTLE_OPPOSITE(battlerId), ability);
}

u32 IsAbilityOnField(u32 ability)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerAlive(i) && GetBattlerAbility(i) == ability)
            return i + 1;
    }

    return 0;
}

u32 IsAbilityOnFieldExcept(u32 battlerId, u32 ability)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != battlerId && IsBattlerAlive(i) && GetBattlerAbility(i) == ability)
            return i + 1;
    }

    return 0;
}

u32 IsAbilityPreventingEscape(u32 battlerId)
{
    u32 id;
    #if B_GHOSTS_ESCAPE >= GEN_6
        if (IS_BATTLER_OF_TYPE(battlerId, TYPE_GHOST))
            return 0;
    #endif
    #if B_SHADOW_TAG_ESCAPE >= GEN_4
        if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_SHADOW_TAG)) && gBattleMons[battlerId].ability != ABILITY_SHADOW_TAG)
    #else
        if (id = IsAbilityOnOpposingSide(battlerId, ABILITY_SHADOW_TAG))
    #endif
        return id;
    if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_ARENA_TRAP)) && IsBattlerGrounded(battlerId))
        return id;
    if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_MAGNET_PULL)) && IS_BATTLER_OF_TYPE(battlerId, TYPE_STEEL))
        return id;

    return 0;
}

bool32 CanBattlerEscape(u32 battlerId) // no ability check
{
    if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_SHED_SHELL)
        return TRUE;
    else if ((B_GHOSTS_ESCAPE >= GEN_6 && !IS_BATTLER_OF_TYPE(battlerId, TYPE_GHOST)) && gBattleMons[battlerId].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return FALSE;
    else if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        return FALSE;
    else
        return TRUE;
}

void BattleScriptExecute(const u8 *BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands_PopCallbacksStack;
    gCurrentActionFuncId = 0;
}

void BattleScriptPushCursorAndCallback(const u8 *BS_ptr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands;
}

enum
{
    ITEM_NO_EFFECT, // 0
    ITEM_STATUS_CHANGE, // 1
    ITEM_EFFECT_OTHER, // 2
    ITEM_PP_CHANGE, // 3
    ITEM_HP_CHANGE, // 4
    ITEM_STATS_CHANGE, // 5
};

bool32 IsBattlerTerrainAffected(u8 battlerId, u32 terrainFlag)
{
    if (!(gFieldStatuses & terrainFlag))
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;
    
    return IsBattlerGrounded(battlerId);
}

bool32 CanSleep(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if (ability == ABILITY_INSOMNIA
      || ability == ABILITY_VITAL_SPIRIT
      || ability == ABILITY_COMATOSE
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityOnSide(battlerId, ABILITY_SWEET_VEIL)
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBePoisoned(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_POISON)
     || IS_BATTLER_OF_TYPE(battlerId, TYPE_STEEL)
     || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battlerId].status1 & STATUS1_ANY
     || ability == ABILITY_IMMUNITY
     || ability == ABILITY_COMATOSE
     || gBattleMons[battlerId].status1 & STATUS1_ANY
     || IsAbilityStatusProtected(battlerId)
     || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeBurned(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FIRE)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || ability == ABILITY_WATER_VEIL
      || ability == ABILITY_WATER_BUBBLE
      || ability == ABILITY_COMATOSE
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeParalyzed(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if ((B_PARALYZE_ELECTRIC >= GEN_6 && IS_BATTLER_OF_TYPE(battlerId, TYPE_ELECTRIC))
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || ability == ABILITY_LIMBER
      || ability == ABILITY_COMATOSE
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeFrozen(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      || (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || ability == ABILITY_MAGMA_ARMOR
      || ability == ABILITY_COMATOSE
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeConfused(u8 battlerId)
{
    if (GetBattlerAbility(gEffectBattler) == ABILITY_OWN_TEMPO
      || gBattleMons[gEffectBattler].status2 & STATUS2_CONFUSION
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

// second argument is 1/X of current hp compared to max hp
bool32 HasEnoughHpToEatBerry(u32 battlerId, u32 hpFraction, u32 itemId)
{
    bool32 isBerry = (ItemId_GetPocket(itemId) == POCKET_BERRIES);

    if (gBattleMons[battlerId].hp == 0)
        return FALSE;
    if (gBattleScripting.overrideBerryRequirements)
        return TRUE;
    // Unnerve prevents consumption of opponents' berries.
    if (isBerry && IsUnnerveAbilityOnOpposingSide(battlerId))
        return FALSE;
    if (gBattleMons[battlerId].hp <= gBattleMons[battlerId].maxHP / hpFraction)
        return TRUE;

    if (hpFraction <= 4 && GetBattlerAbility(battlerId) == ABILITY_GLUTTONY && isBerry
         && gBattleMons[battlerId].hp <= gBattleMons[battlerId].maxHP / 2)
    {
        RecordAbilityBattle(battlerId, ABILITY_GLUTTONY);
        return TRUE;
    }

    return FALSE;
}

static u8 HealConfuseBerry(u32 battlerId, u32 itemId, u8 flavorId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battlerId, 2, itemId))
    {
        PREPARE_FLAVOR_BUFFER(gBattleTextBuff1, flavorId);

        gBattleMoveDamage = gBattleMons[battlerId].maxHP / GetBattlerHoldEffectParam(battlerId);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
        {
            gBattleMoveDamage *= 2;
            gBattlerAbility = battlerId;
        }
        gBattleScripting.battler = battlerId;
        if (end2)
        {
            if (GetFlavorRelationByPersonality(gBattleMons[battlerId].personality, flavorId) < 0)
                BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
            else
                BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            if (GetFlavorRelationByPersonality(gBattleMons[battlerId].personality, flavorId) < 0)
                gBattlescriptCurrInstr = BattleScript_BerryConfuseHealRet;
            else
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }

        return ITEM_HP_CHANGE;
    }
    return 0;
}

static u8 StatRaiseBerry(u32 battlerId, u32 itemId, u32 statId, bool32 end2)
{
    if (CompareStat(battlerId, statId, MAX_STAT_STAGE, CMP_LESS_THAN) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), itemId))
    {
        BufferStatChange(battlerId, statId, STRINGID_STATROSE);
        gEffectBattler = battlerId;
        if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.animArg1 = 14 + statId;
        gBattleScripting.animArg2 = 0;

        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 RandomStatRaiseBerry(u32 battlerId, u32 itemId, bool32 end2)
{
    s32 i;
    u16 stringId;

    for (i = 0; i < 5; i++)
    {
        if (CompareStat(battlerId, STAT_ATK + i, MAX_STAT_STAGE, CMP_LESS_THAN))
            break;
    }
    if (i != 5 && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), itemId))
    {
        do
        {
            i = Random() % 5;
        } while (!CompareStat(battlerId, STAT_ATK + i, MAX_STAT_STAGE, CMP_LESS_THAN));

        PREPARE_STAT_BUFFER(gBattleTextBuff1, i + 1);
        stringId = (GetBattlerAbility(battlerId) == ABILITY_CONTRARY) ? STRINGID_STATFELL : STRINGID_STATROSE;
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        gBattleTextBuff2[1] = B_BUFF_STRING;
        gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
        gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
        gBattleTextBuff2[4] = B_BUFF_STRING;
        gBattleTextBuff2[5] = stringId;
        gBattleTextBuff2[6] = stringId >> 8;
        gBattleTextBuff2[7] = EOS;
        gEffectBattler = battlerId;
        if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
            SET_STATCHANGER(i + 1, 4, FALSE);
        else
            SET_STATCHANGER(i + 1, 2, FALSE);

        gBattleScripting.animArg1 = 0x21 + i + 6;
        gBattleScripting.animArg2 = 0;
        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 TrySetMicleBerry(u32 battlerId, u32 itemId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battlerId, 4, itemId))
    {
        gProtectStructs[battlerId].micle = TRUE;  // battler's next attack has increased accuracy

        if (end2)
        {
            BattleScriptExecute(BattleScript_MicleBerryActivateEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MicleBerryActivateRet;
        }
        return ITEM_EFFECT_OTHER;
    }
    return 0;
}

static u8 DamagedStatBoostBerryEffect(u8 battlerId, u8 statId, u8 split)
{
    if (IsBattlerAlive(battlerId)
     && TARGET_TURN_DAMAGED
     && CompareStat(battlerId, statId, MAX_STAT_STAGE, CMP_LESS_THAN)
     && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
     && GetBattleMoveSplit(gCurrentMove) == split)
    {
        BufferStatChange(battlerId, statId, STRINGID_STATROSE);

        gEffectBattler = battlerId;
        if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.animArg1 = 14 + statId;
        gBattleScripting.animArg2 = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

u8 TryHandleSeed(u8 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute)
{
    if (gFieldStatuses & terrainFlag && CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
    {
        BufferStatChange(battler, statId, STRINGID_STATROSE);
        gLastUsedItem = itemId; // For surge abilities
        gEffectBattler = gBattleScripting.battler = battler;
        SET_STATCHANGER(statId, 1, FALSE);
        gBattleScripting.animArg1 = 0xE + statId;
        gBattleScripting.animArg2 = 0;
        if (execute)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 ItemHealHp(u32 battlerId, u32 itemId, bool32 end2, bool32 percentHeal)
{
    if (HasEnoughHpToEatBerry(battlerId, 2, itemId)
      && !(gBattleScripting.overrideBerryRequirements && gBattleMons[battlerId].hp == gBattleMons[battlerId].maxHP))
    {
        if (percentHeal)
            gBattleMoveDamage = (gBattleMons[battlerId].maxHP * GetBattlerHoldEffectParam(battlerId) / 100) * -1;
        else
            gBattleMoveDamage = GetBattlerHoldEffectParam(battlerId) * -1;

        // check ripen
        if (ItemId_GetPocket(itemId) == POCKET_BERRIES && GetBattlerAbility(battlerId) == ABILITY_RIPEN)
            gBattleMoveDamage *= 2;

        gBattlerAbility = battlerId;    // in SWSH, berry juice shows ability pop up but has no effect. This is mimicked here
        if (end2)
        {
            BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }
        return ITEM_HP_CHANGE;
    }
    return 0;
}

static bool32 UnnerveOn(u32 battlerId, u32 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES && IsUnnerveAbilityOnOpposingSide(battlerId))
        return TRUE;
    return FALSE;
}

static bool32 GetMentalHerbEffect(u8 battlerId)
{
    bool32 ret = FALSE;
    
    // Check infatuation
    if (gBattleMons[battlerId].status2 & STATUS2_INFATUATION)
    {
        gBattleMons[battlerId].status2 &= ~(STATUS2_INFATUATION);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_INFATUATION;  // STRINGID_TARGETGOTOVERINFATUATION
        StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
        ret = TRUE;
    }
    #if B_MENTAL_HERB >= GEN_5
        // Check taunt
        if (gDisableStructs[battlerId].tauntTimer != 0)
        {
            gDisableStructs[battlerId].tauntTimer = gDisableStructs[battlerId].tauntTimer2 = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
            ret = TRUE;
        }
        // Check encore
        if (gDisableStructs[battlerId].encoreTimer != 0)
        {
            gDisableStructs[battlerId].encoredMove = 0;
            gDisableStructs[battlerId].encoreTimerStartValue = gDisableStructs[battlerId].encoreTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_ENCORE;   // STRINGID_PKMNENCOREENDED
            ret = TRUE;
        }
        // Check torment
        if (gBattleMons[battlerId].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battlerId].status2 &= ~(STATUS2_TORMENT);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TORMENT;
            ret = TRUE;
        }
        // Check heal block
        if (gStatuses3[battlerId] & STATUS3_HEAL_BLOCK)
        {
            gStatuses3[battlerId] &= ~(STATUS3_HEAL_BLOCK);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_HEALBLOCK;
            ret = TRUE;
        }
        // Check disable
        if (gDisableStructs[battlerId].disableTimer != 0)
        {
            gDisableStructs[battlerId].disableTimer = gDisableStructs[battlerId].disableTimerStartValue = 0;
            gDisableStructs[battlerId].disabledMove = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_DISABLE;
            ret = TRUE;
        }
    #endif
    return ret;
}

u8 ItemBattleEffects(u8 caseID, u8 battlerId, bool8 moveTurn)
{
    int i = 0, moveType;
    u8 effect = ITEM_NO_EFFECT;
    u8 changedPP = 0;
    u8 battlerHoldEffect, atkHoldEffect;
    u8 atkHoldEffectParam;
    u16 atkItem;

    gLastUsedItem = gBattleMons[battlerId].item;
    battlerHoldEffect = GetBattlerHoldEffect(battlerId, TRUE);

    atkItem = gBattleMons[gBattlerAttacker].item;
    atkHoldEffect = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    atkHoldEffectParam = GetBattlerHoldEffectParam(gBattlerAttacker);

    switch (caseID)
    {
    case ITEMEFFECT_ON_SWITCH_IN:
        if (!gSpecialStatuses[battlerId].switchInItemDone)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_DOUBLE_PRIZE:
                if (GetBattlerSide(battlerId) == B_SIDE_PLAYER && !gBattleStruct->moneyMultiplierItem)
                {
                    gBattleStruct->moneyMultiplier *= 2;
                    gBattleStruct->moneyMultiplierItem = 1;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    gActiveBattler = gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (B_BERRIES_INSTANT >= GEN_4 && !(gBattleMons[battlerId].status2 & STATUS2_FOCUS_ENERGY) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (!(i > 1))
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_AIR_BALLOON:
                effect = ITEM_EFFECT_OTHER;
                gBattleScripting.battler = battlerId;
                BattleScriptPushCursorAndCallback(BattleScript_AirBaloonMsgIn);
                RecordItemEffectBattle(battlerId, HOLD_EFFECT_AIR_BALLOON);
                break;
            case HOLD_EFFECT_ROOM_SERVICE:
                if (TryRoomService(battlerId))
                {
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SEEDS:
                switch (GetBattlerHoldEffectParam(battlerId))
                {
                case HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_ELECTRIC_TERRAIN, STAT_DEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_GRASSY_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_GRASSY_TERRAIN, STAT_DEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_MISTY_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_MISTY_TERRAIN, STAT_SPDEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_PSYCHIC_TERRAIN, STAT_SPDEF, gLastUsedItem, TRUE);
                    break;
                }
                break;
            case HOLD_EFFECT_EJECT_PACK:
                if (gProtectStructs[battlerId].statFell
                 && gProtectStructs[battlerId].disableEjectPack == 0
                 && !(gCurrentMove == MOVE_PARTING_SHOT && CanBattlerSwitch(gBattlerAttacker))) // Does not activate if attacker used Parting Shot and can switch out
                {
                    gProtectStructs[battlerId].statFell = FALSE;
                    gActiveBattler = gBattleScripting.battler = battlerId;
                    effect = ITEM_STATS_CHANGE;
                    if (moveTurn)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_EjectPackActivate_Ret;
                    }
                    else
                    {
                        BattleScriptExecute(BattleScript_EjectPackActivate_End2);
                    }
                }
                break;
            }

            if (effect)
            {
                gSpecialStatuses[battlerId].switchInItemDone = 1;
                gActiveBattler = gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case ITEM_PP_CHANGE:
                    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED) && !(gDisableStructs[battlerId].mimickedMoves & gBitTable[i]))
                        gBattleMons[battlerId].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case 1:
        if (gBattleMons[battlerId].hp)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_RESTORE_PP:
                if (!moveTurn)
                {
                    struct Pokemon *mon;
                    u8 ppBonuses;
                    u16 move;

                    mon = GetBattlerPartyData(battlerId);
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        move = GetMonData(mon, MON_DATA_MOVE1 + i);
                        changedPP = GetMonData(mon, MON_DATA_PP1 + i);
                        ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
                        if (move && changedPP == 0)
                            break;
                    }
                    if (i != MAX_MON_MOVES)
                    {
                        u8 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
                        u8 ppRestored = GetBattlerHoldEffectParam(battlerId);

                        if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
                        {
                            ppRestored *= 2;
                            gBattlerAbility = battlerId;
                        }
                        if (changedPP + ppRestored > maxPP)
                            changedPP = maxPP;
                        else
                            changedPP = changedPP + ppRestored;

                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);

                        BattleScriptExecute(BattleScript_BerryPPHealEnd2);
                        BtlController_EmitSetMonData(0, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
                        MarkBattlerForControllerExec(gActiveBattler);
                        effect = ITEM_PP_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    gActiveBattler = gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_BLACK_SLUDGE:
                if (IS_BATTLER_OF_TYPE(battlerId, TYPE_POISON))
                {
                    goto LEFTOVERS;
                }
                else if (GetBattlerAbility(battlerId) != ABILITY_MAGIC_GUARD && !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[battlerId].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_ItemHurtEnd2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battlerId, battlerHoldEffect);
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                }
                break;
            case HOLD_EFFECT_LEFTOVERS:
            LEFTOVERS:
                if (gBattleMons[battlerId].hp < gBattleMons[battlerId].maxHP && !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[battlerId].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_End2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battlerId, battlerHoldEffect);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (!moveTurn && !(gBattleMons[battlerId].status2 & STATUS2_FOCUS_ENERGY) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (!moveTurn)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureConfusionEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if ((gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (!(i > 1))
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_MENTAL_HERB:
                if (GetMentalHerbEffect(battlerId))
                {
                    gBattleScripting.savedBattler = gBattlerAttacker;
                    gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_MentalHerbCureEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_MICLE_BERRY:
                if (!moveTurn)
                    effect = TrySetMicleBerry(battlerId, gLastUsedItem, TRUE);
                break;
            }

            if (effect)
            {
                gActiveBattler = gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case ITEM_PP_CHANGE:
                    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED) && !(gDisableStructs[battlerId].mimickedMoves & gBitTable[i]))
                        gBattleMons[battlerId].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case ITEMEFFECT_BATTLER_MOVE_END:
        goto DO_ITEMEFFECT_MOVE_END;    // this hurts a bit to do, but is an easy solution
    case ITEMEFFECT_MOVE_END:
        for (battlerId = 0; battlerId < gBattlersCount; battlerId++)
        {
            gLastUsedItem = gBattleMons[battlerId].item;
            battlerHoldEffect = GetBattlerHoldEffect(battlerId, TRUE);
        DO_ITEMEFFECT_MOVE_END:
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_MICLE_BERRY:
                if (B_HP_BERRIES >= GEN_4)
                    effect = TrySetMicleBerry(battlerId, gLastUsedItem, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_HP:
                if (B_HP_BERRIES >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, FALSE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, FALSE, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, FALSE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, FALSE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, FALSE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, FALSE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, FALSE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, FALSE);
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, FALSE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureParRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCurePsnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureBrnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureSlpRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureConfusionRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_MENTAL_HERB:
                if (GetMentalHerbEffect(battlerId))
                {
                    gBattleScripting.savedBattler = gBattlerAttacker;
                    gBattlerAttacker = battlerId;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MentalHerbCureRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if ((gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    }
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WhiteHerbRet;
                    return effect;
                }
                break;
            }

            if (effect)
            {
                gActiveBattler = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                if (effect == ITEM_STATUS_CHANGE)
                {
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                break;
            }
        }
        break;
    case ITEMEFFECT_KINGSROCK:
        // Occur on each hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_FLINCH:
            if (gBattleMoveDamage != 0  // Need to have done damage
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED
                && (Random() % 100) < atkHoldEffectParam
                && gBattleMoves[gCurrentMove].flags & FLAG_KINGS_ROCK_AFFECTED
                && gBattleMons[gBattlerTarget].hp)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
            }
            break;
        case HOLD_EFFECT_BLUNDER_POLICY:
            if (gBattleStruct->blunderPolicy
             && gBattleMons[gBattlerAttacker].hp != 0
             && CompareStat(gBattlerAttacker, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleStruct->blunderPolicy = FALSE;
                gLastUsedItem = atkItem;
                gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPEED, 2, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_LIFEORB_SHELLBELL:
        // Occur after the final hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_SHELL_BELL:
            if (gSpecialStatuses[gBattlerAttacker].damagedMons  // Need to have done damage
                && gBattlerAttacker != gBattlerTarget
                && gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP
                && gBattleMons[gBattlerAttacker].hp != 0)
            {
                gLastUsedItem = atkItem;
                gPotentialItemEffectBattler = gBattlerAttacker;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleMoveDamage = (gSpecialStatuses[gBattlerTarget].dmg / atkHoldEffectParam) * -1;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = -1;
                gSpecialStatuses[gBattlerTarget].dmg = 0;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_Ret;
                effect = ITEM_HP_CHANGE;
            }
            break;
        case HOLD_EFFECT_LIFE_ORB:
            if (IsBattlerAlive(gBattlerAttacker)
                && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
                && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD
                && gSpecialStatuses[gBattlerAttacker].damagedMons)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 10;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                effect = ITEM_HP_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHurtRet;
                gLastUsedItem = gBattleMons[gBattlerAttacker].item;
            }
            break;
        case HOLD_EFFECT_THROAT_SPRAY:  // Does NOT need to be a damaging move
            if (gProtectStructs[gBattlerAttacker].targetAffected
             && gBattleMons[gBattlerAttacker].hp != 0
             && gBattleMoves[gCurrentMove].flags & FLAG_SOUND
             && CompareStat(gBattlerAttacker, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN)
             && !NoAliveMonsForEitherParty())   // Don't activate if battle will end
            {
                gLastUsedItem = atkItem;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_TARGET:
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            GET_MOVE_TYPE(gCurrentMove, moveType);
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_AIR_BALLOON:
                if (TARGET_TURN_DAMAGED)
                {
                    effect = ITEM_EFFECT_OTHER;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AirBaloonMsgPop;
                }
                break;
            case HOLD_EFFECT_ROCKY_HELMET:
                if (TARGET_TURN_DAMAGED
                    && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                    && IsBattlerAlive(gBattlerAttacker)
                    && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 6;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_RockyHelmetActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_WEAKNESS_POLICY:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WeaknessPolicy;
                }
                break;
            case HOLD_EFFECT_SNOWBALL:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_ICE)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_ATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_LUMINOUS_MOSS:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_WATER)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPDEF, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_CELL_BATTERY:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_ELECTRIC)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_ATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_ABSORB_BULB:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_WATER)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_JABOCA_BERRY:  // consume and damage attacker if used physical move
                if (IsBattlerAlive(battlerId)
                 && TARGET_TURN_DAMAGED
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                 && IS_MOVE_PHYSICAL(gCurrentMove)
                 && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_ROWAP_BERRY:  // consume and damage attacker if used special move
                if (IsBattlerAlive(battlerId)
                 && TARGET_TURN_DAMAGED
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                 && IS_MOVE_SPECIAL(gCurrentMove)
                 && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (GetBattlerAbility(battlerId) == ABILITY_RIPEN)
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_KEE_BERRY:  // consume and boost defense if used physical move
                effect = DamagedStatBoostBerryEffect(battlerId, STAT_DEF, SPLIT_PHYSICAL);
                break;
            case HOLD_EFFECT_MARANGA_BERRY:  // consume and boost sp. defense if used special move
                effect = DamagedStatBoostBerryEffect(battlerId, STAT_SPDEF, SPLIT_SPECIAL);
                break;
            case HOLD_EFFECT_STICKY_BARB:
                if (TARGET_TURN_DAMAGED
                  && (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                  && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                  && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                  && IsBattlerAlive(gBattlerAttacker)
                  && CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
                  && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
                {
                    // No sticky hold checks.
                    gEffectBattler = battlerId; // gEffectBattler = target
                    StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker takes target's barb
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_StickyBarbTransfer;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            }
        }
        break;
    case ITEMEFFECT_ORBS:
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_TOXIC_ORB:
            if (!gBattleMons[battlerId].status1
                && CanPoisonType(battlerId, battlerId)
                && GetBattlerAbility(battlerId) != ABILITY_IMMUNITY
                && GetBattlerAbility(battlerId) != ABILITY_COMATOSE
                && IsBattlerAlive)
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battlerId].status1 = STATUS1_TOXIC_POISON;
                BattleScriptExecute(BattleScript_ToxicOrb);
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!gBattleMons[battlerId].status1
                && !IS_BATTLER_OF_TYPE(battlerId, TYPE_FIRE)
                && GetBattlerAbility(battlerId) != ABILITY_WATER_VEIL
                && GetBattlerAbility(battlerId) != ABILITY_WATER_BUBBLE
                && GetBattlerAbility(battlerId) != ABILITY_COMATOSE
                && IsBattlerAlive)
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battlerId].status1 = STATUS1_BURN;
                BattleScriptExecute(BattleScript_FlameOrb);
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_STICKY_BARB:   // Not an orb per se, but similar effect, and needs to NOT activate with pickpocket
            if (GetBattlerAbility(battlerId) != ABILITY_MAGIC_GUARD)
            {
                gBattleMoveDamage = gBattleMons[battlerId].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_ItemHurtEnd2);
                effect = ITEM_HP_CHANGE;
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
                PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
            }
            break;
        }

        if (effect == ITEM_STATUS_CHANGE)
        {
            gActiveBattler = battlerId;
            BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        break;
    }

    // Berry was successfully used on a Pokemon.
    if (effect && (gLastUsedItem >= FIRST_BERRY_INDEX && gLastUsedItem <= LAST_BERRY_INDEX))
        gBattleStruct->ateBerry[battlerId & BIT_SIDE] |= gBitTable[gBattlerPartyIndexes[battlerId]];

    return effect;
}

void ClearFuryCutterDestinyBondGrudge(u8 battlerId)
{
    gDisableStructs[battlerId].furyCutterCounter = 0;
    gBattleMons[battlerId].status2 &= ~(STATUS2_DESTINY_BOND);
    gStatuses3[battlerId] &= ~(STATUS3_GRUDGE);
}

void HandleAction_RunBattleScript(void) // identical to RunBattleScriptCommands
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[*gBattlescriptCurrInstr]();
}

u32 SetRandomTarget(u32 battlerId)
{
    u32 target;
    static const u8 targets[2][2] =
    {
        [B_SIDE_PLAYER] = {B_POSITION_OPPONENT_LEFT, B_POSITION_OPPONENT_RIGHT},
        [B_SIDE_OPPONENT] = {B_POSITION_PLAYER_LEFT, B_POSITION_PLAYER_RIGHT},
    };

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerId)][Random() % 2]);
        if (!IsBattlerAlive(target))
            target ^= BIT_FLANK;
    }
    else
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerId)][0]);
    }

    return target;
}

u32 GetMoveTarget(u16 move, u8 setTarget)
{
    u8 targetBattler = 0;
    u32 i, moveTarget, side;

    if (setTarget)
        moveTarget = setTarget - 1;
    else
        moveTarget = gBattleMoves[move].target;
    
    // Special cases
    if (move == MOVE_CURSE && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
        moveTarget = MOVE_TARGET_USER;
    
    switch (moveTarget)
    {
    case MOVE_TARGET_SELECTED:
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
        {
            targetBattler = gSideTimers[side].followmeTarget;
        }
        else
        {
            targetBattler = SetRandomTarget(gBattlerAttacker);
            if (gBattleMoves[move].type == TYPE_ELECTRIC
                && IsAbilityOnOpposingSide(gBattlerAttacker, ABILITY_LIGHTNING_ROD)
                && gBattleMons[targetBattler].ability != ABILITY_LIGHTNING_ROD)
            {
                targetBattler ^= BIT_FLANK;
                RecordAbilityBattle(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].lightningRodRedirected = 1;
            }
            else if (gBattleMoves[move].type == TYPE_WATER
                && IsAbilityOnOpposingSide(gBattlerAttacker, ABILITY_STORM_DRAIN)
                && gBattleMons[targetBattler].ability != ABILITY_STORM_DRAIN)
            {
                targetBattler ^= BIT_FLANK;
                RecordAbilityBattle(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].stormDrainRedirected = 1;
            }
        }
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    case MOVE_TARGET_OPPONENTS_FIELD:
        targetBattler = GetBattlerAtPosition((GetBattlerPosition(gBattlerAttacker) & BIT_SIDE) ^ BIT_SIDE);
        if (!IsBattlerAlive(targetBattler))
            targetBattler ^= BIT_FLANK;
        break;
    case MOVE_TARGET_RANDOM:
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
            targetBattler = gSideTimers[side].followmeTarget;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && moveTarget & MOVE_TARGET_RANDOM)
            targetBattler = SetRandomTarget(gBattlerAttacker);
        else
            targetBattler = GetBattlerAtPosition((GetBattlerPosition(gBattlerAttacker) & BIT_SIDE) ^ BIT_SIDE);
        break;
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
    default:
        targetBattler = gBattlerAttacker;
        break;
    case MOVE_TARGET_ALLY:
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            targetBattler = BATTLE_PARTNER(gBattlerAttacker);
        else
            targetBattler = gBattlerAttacker;
        break;
    }

    *(gBattleStruct->moveTarget + gBattlerAttacker) = targetBattler;

    return targetBattler;
}

static bool32 IsMonEventLegal(u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
        return TRUE;
    if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS
        && GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL) != SPECIES_MEW)
            return TRUE;
    return GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_EVENT_LEGAL, NULL);
}

u8 IsMonDisobedient(void)
{
    s32 rnd;
    s32 calc;
    u8 obedienceLevel = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return 0;
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return 0;

    if (IsMonEventLegal(gBattlerAttacker)) // only false if illegal Mew or Deoxys
    {
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gBattlerAttacker) == 2)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return 0;
        if (!IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
            return 0;
        if (FlagGet(FLAG_BADGE08_GET))
            return 0;

        obedienceLevel = 10;

        if (FlagGet(FLAG_BADGE02_GET))
            obedienceLevel = 30;
        if (FlagGet(FLAG_BADGE04_GET))
            obedienceLevel = 50;
        if (FlagGet(FLAG_BADGE06_GET))
            obedienceLevel = 70;
    }

    if (gBattleMons[gBattlerAttacker].level <= obedienceLevel)
        return 0;
    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
        return 0;

    // is not obedient
    if (gCurrentMove == MOVE_RAGE)
        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_RAGE);
    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP && (gCurrentMove == MOVE_SNORE || gCurrentMove == MOVE_SLEEP_TALK))
    {
        gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
        return 1;
    }

    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
    {
        calc = CheckMoveLimitations(gBattlerAttacker, gBitTable[gCurrMovePos], 0xFF);
        if (calc == 0xF) // all moves cannot be used
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & (NUM_LOAF_STRINGS - 1);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
        else // use a random move
        {
            do
            {
                gCurrMovePos = gChosenMovePos = Random() & (MAX_MON_MOVES - 1);
            } while (gBitTable[gCurrMovePos] & calc);

            gCalledMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
            gBattlescriptCurrInstr = BattleScript_IgnoresAndUsesRandomMove;
            gBattlerTarget = GetMoveTarget(gCalledMove, 0);
            gHitMarker |= HITMARKER_x200000;
            return 2;
        }
    }
    else
    {
        obedienceLevel = gBattleMons[gBattlerAttacker].level - obedienceLevel;

        calc = (Random() & 255);
        if (calc < obedienceLevel && CanSleep(gBattlerAttacker))
        {
            // try putting asleep
            int i;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].status2 & STATUS2_UPROAR)
                    break;
            }
            if (i == gBattlersCount)
            {
                gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
                return 1;
            }
        }
        calc -= obedienceLevel;
        if (calc < obedienceLevel)
        {
            gBattleMoveDamage = CalculateMoveDamage(MOVE_NONE, gBattlerAttacker, gBattlerAttacker, TYPE_MYSTERY, 40, FALSE, FALSE, TRUE);
            gBattlerTarget = gBattlerAttacker;
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
            return 2;
        }
        else
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & (NUM_LOAF_STRINGS - 1);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
    }
}

u32 GetBattlerHoldEffect(u8 battlerId, bool32 checkNegating)
{
    if (checkNegating)
    {
        if (gStatuses3[battlerId] & STATUS3_EMBARGO)
            return HOLD_EFFECT_NONE;
        if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
            return HOLD_EFFECT_NONE;
        if (gBattleMons[battlerId].ability == ABILITY_KLUTZ && !(gStatuses3[battlerId] & STATUS3_GASTRO_ACID))
            return HOLD_EFFECT_NONE;
    }

    gPotentialItemEffectBattler = battlerId;

    if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId] != 0 && gBattleMons[battlerId].item)
        return gBattleStruct->debugHoldEffects[battlerId];
    else if (gBattleMons[battlerId].item == ITEM_ENIGMA_BERRY)
        return gEnigmaBerries[battlerId].holdEffect;
    else
        return ItemId_GetHoldEffect(gBattleMons[battlerId].item);
}

u32 GetBattlerHoldEffectParam(u8 battlerId)
{
    if (gBattleMons[battlerId].item == ITEM_ENIGMA_BERRY)
        return gEnigmaBerries[battlerId].holdEffectParam;
    else
        return ItemId_GetHoldEffectParam(gBattleMons[battlerId].item);
}

bool32 IsMoveMakingContact(u16 move, u8 battlerAtk)
{
    if (!(gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
        return FALSE;
    else if (GetBattlerAbility(battlerAtk) == ABILITY_LONG_REACH)
        return FALSE;
    else if (GetBattlerHoldEffect(battlerAtk, TRUE) == HOLD_EFFECT_PROTECTIVE_PADS)
        return FALSE;
    else
        return TRUE;
}

bool32 IsBattlerGrounded(u8 battlerId)
{
    if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    else if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_SMACKED_DOWN)
        return TRUE;

    else if (gStatuses3[battlerId] & STATUS3_TELEKINESIS)
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_MAGNET_RISE)
        return FALSE;
    else if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    else if (GetBattlerAbility(battlerId) == ABILITY_LEVITATE)
        return FALSE;
    else if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FLYING))
        return FALSE;

    else
        return TRUE;
}

bool32 IsBattlerAlive(u8 battlerId)
{
    if (gBattleMons[battlerId].hp == 0)
        return FALSE;
    else if (battlerId >= gBattlersCount)
        return FALSE;
    else if (gAbsentBattlerFlags & gBitTable[battlerId])
        return FALSE;
    else
        return TRUE;
}

u8 GetBattleMonMoveSlot(struct BattlePokemon *battleMon, u16 move)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (battleMon->moves[i] == move)
            break;
    }
    return i;
}

u32 GetBattlerWeight(u8 battlerId)
{
    u32 i;
    u32 weight = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(gBattleMons[battlerId].species), 1);
    u32 ability = GetBattlerAbility(battlerId);
    u32 holdEffect = GetBattlerHoldEffect(battlerId, TRUE);

    if (ability == ABILITY_HEAVY_METAL)
        weight *= 2;
    else if (ability == ABILITY_LIGHT_METAL)
        weight /= 2;

    if (holdEffect == HOLD_EFFECT_FLOAT_STONE)
        weight /= 2;

    for (i = 0; i < gDisableStructs[battlerId].autotomizeCount; i++)
    {
        if (weight > 1000)
        {
            weight -= 1000;
        }
        else if (weight <= 1000)
        {
            weight = 1;
            break;
        }
    }

    if (weight == 0)
        weight = 1;

    return weight;
}

u32 CountBattlerStatIncreases(u8 battlerId, bool32 countEvasionAcc)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if ((i == STAT_ACC || i == STAT_EVASION) && !countEvasionAcc)
            continue;
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE) // Stat is increased.
            count += gBattleMons[battlerId].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return count;
}

u32 GetMoveTargetCount(u16 move, u8 battlerAtk, u8 battlerDef)
{
    switch (gBattleMoves[move].target)
    {
    case MOVE_TARGET_BOTH:
        return IsBattlerAlive(battlerDef)
             + IsBattlerAlive(BATTLE_PARTNER(battlerDef));
    case MOVE_TARGET_FOES_AND_ALLY:
        return IsBattlerAlive(battlerDef)
             + IsBattlerAlive(BATTLE_PARTNER(battlerDef))
             + IsBattlerAlive(BATTLE_PARTNER(battlerAtk));
    case MOVE_TARGET_OPPONENTS_FIELD:
        return 1;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_USER_OR_SELECTED:
        return IsBattlerAlive(battlerDef);
    case MOVE_TARGET_USER:
        return IsBattlerAlive(battlerAtk);
    default:
        return 0;
    }
}

static void MulModifier(u16 *modifier, u16 val)
{
    *modifier = UQ_4_12_TO_INT((*modifier * val) + UQ_4_12_ROUND);
}

static u32 ApplyModifier(u16 modifier, u32 val)
{
    return UQ_4_12_TO_INT((modifier * val) + UQ_4_12_ROUND);
}

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
};

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
{
    100, 20,
    250, 40,
    500, 60,
    1000, 80,
    2000, 100,
    0xFFFF, 0xFFFF
};

static const u8 sSpeedDiffPowerTable[] = {40, 60, 80, 120, 150};
static const u8 sHeatCrashPowerTable[] = {40, 40, 60, 80, 100, 120};
static const u8 sTrumpCardPowerTable[] = {200, 80, 60, 50, 40};

const struct TypePower gNaturalGiftTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)] = {TYPE_FIRE, 80},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY)] = {TYPE_WATER, 80},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)] = {TYPE_ELECTRIC, 80},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)] = {TYPE_GRASS, 80},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY)] = {TYPE_ICE, 80},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)] = {TYPE_FIGHTING, 80},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)] = {TYPE_POISON, 80},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY)] = {TYPE_GROUND, 80},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)] = {TYPE_FLYING, 80},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY)] = {TYPE_PSYCHIC, 80},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)] = {TYPE_BUG, 80},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)] = {TYPE_ROCK, 80},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)] = {TYPE_GHOST, 80},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)] = {TYPE_DRAGON, 80},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY)] = {TYPE_DARK, 80},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)] = {TYPE_STEEL, 80},
    [ITEM_TO_BERRY(ITEM_OCCA_BERRY)] = {TYPE_FIRE, 80},
    [ITEM_TO_BERRY(ITEM_PASSHO_BERRY)] = {TYPE_WATER, 80},
    [ITEM_TO_BERRY(ITEM_WACAN_BERRY)] = {TYPE_ELECTRIC, 80},
    [ITEM_TO_BERRY(ITEM_RINDO_BERRY)] = {TYPE_GRASS, 80},
    [ITEM_TO_BERRY(ITEM_YACHE_BERRY)] = {TYPE_ICE, 80},
    [ITEM_TO_BERRY(ITEM_CHOPLE_BERRY)] = {TYPE_FIGHTING, 80},
    [ITEM_TO_BERRY(ITEM_KEBIA_BERRY)] = {TYPE_POISON, 80},
    [ITEM_TO_BERRY(ITEM_SHUCA_BERRY)] = {TYPE_GROUND, 80},
    [ITEM_TO_BERRY(ITEM_COBA_BERRY)] = {TYPE_FLYING, 80},
    [ITEM_TO_BERRY(ITEM_PAYAPA_BERRY)] = {TYPE_PSYCHIC, 80},
    [ITEM_TO_BERRY(ITEM_TANGA_BERRY)] = {TYPE_BUG, 80},
    [ITEM_TO_BERRY(ITEM_CHARTI_BERRY)] = {TYPE_ROCK, 80},
    [ITEM_TO_BERRY(ITEM_KASIB_BERRY)] = {TYPE_GHOST, 80},
    [ITEM_TO_BERRY(ITEM_HABAN_BERRY)] = {TYPE_DRAGON, 80},
    [ITEM_TO_BERRY(ITEM_COLBUR_BERRY)] = {TYPE_DARK, 80},
    [ITEM_TO_BERRY(ITEM_BABIRI_BERRY)] = {TYPE_STEEL, 80},
    [ITEM_TO_BERRY(ITEM_CHILAN_BERRY)] = {TYPE_NORMAL, 80},
    [ITEM_TO_BERRY(ITEM_ROSELI_BERRY)] = {TYPE_FAIRY, 80},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)] = {TYPE_FIRE, 90},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)] = {TYPE_WATER, 90},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY)] = {TYPE_ELECTRIC, 90},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)] = {TYPE_GRASS, 90},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)] = {TYPE_ICE, 90},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY)] = {TYPE_FIGHTING, 90},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY)] = {TYPE_POISON, 90},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY)] = {TYPE_GROUND, 90},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)] = {TYPE_FLYING, 90},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY)] = {TYPE_PSYCHIC, 90},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)] = {TYPE_BUG, 90},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY)] = {TYPE_ROCK, 90},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY)] = {TYPE_GHOST, 90},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)] = {TYPE_DRAGON, 90},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY)] = {TYPE_DARK, 90},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY)] = {TYPE_STEEL, 90},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY)] = {TYPE_FIRE, 100},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)] = {TYPE_WATER, 100},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)] = {TYPE_ELECTRIC, 100},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY)] = {TYPE_GRASS, 100},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY)] = {TYPE_ICE, 100},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)] = {TYPE_FIGHTING, 100},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY)] = {TYPE_POISON, 100},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY)] = {TYPE_GROUND, 100},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY)] = {TYPE_FLYING, 100},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)] = {TYPE_PSYCHIC, 100},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY)] = {TYPE_BUG, 100},
    [ITEM_TO_BERRY(ITEM_MICLE_BERRY)] = {TYPE_ROCK, 100},
    [ITEM_TO_BERRY(ITEM_CUSTAP_BERRY)] = {TYPE_GHOST, 100},
    [ITEM_TO_BERRY(ITEM_JABOCA_BERRY)] = {TYPE_DRAGON, 100},
    [ITEM_TO_BERRY(ITEM_ROWAP_BERRY)] = {TYPE_DARK, 100},
    [ITEM_TO_BERRY(ITEM_KEE_BERRY)] = {TYPE_FAIRY, 100},
    [ITEM_TO_BERRY(ITEM_MARANGA_BERRY)] = {TYPE_DARK, 100},
};

static u16 CalcMoveBasePower(u16 move, u8 battlerAtk, u8 battlerDef)
{
    u32 i;
    u16 basePower = gBattleMoves[move].power;
    u32 weight, hpFraction, speed;

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_PLEDGE:
        // todo
        break;
    case EFFECT_FLING:
        // todo: program Fling + Unburden interaction
        break;
    case EFFECT_ERUPTION:
        basePower = gBattleMons[battlerAtk].hp * basePower / gBattleMons[battlerAtk].maxHP;
        break;
    case EFFECT_FLAIL:
        hpFraction = GetScaledHPFraction(gBattleMons[battlerAtk].hp, gBattleMons[battlerAtk].maxHP, 48);
        for (i = 0; i < sizeof(sFlailHpScaleToPowerTable); i += 2)
        {
            if (hpFraction <= sFlailHpScaleToPowerTable[i])
                break;
        }
        basePower = sFlailHpScaleToPowerTable[i + 1];
        break;
    case EFFECT_RETURN:
        basePower = 10 * (gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FRUSTRATION:
        basePower = 10 * (255 - gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FURY_CUTTER:
        for (i = 1; i < gDisableStructs[battlerAtk].furyCutterCounter; i++)
            basePower *= 2;
        break;
    case EFFECT_ROLLOUT:
        for (i = 1; i < (5 - gDisableStructs[battlerAtk].rolloutTimer); i++)
            basePower *= 2;
        if (gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL)
            basePower *= 2;
        break;
    case EFFECT_MAGNITUDE:
        basePower = gBattleStruct->magnitudeBasePower;
        break;
    case EFFECT_PRESENT:
        basePower = gBattleStruct->presentBasePower;
        break;
    case EFFECT_TRIPLE_KICK:
        basePower += gBattleScripting.tripleKickPower;
        break;
    case EFFECT_SPIT_UP:
        basePower = 100 * gDisableStructs[battlerAtk].stockpileCounter;
        break;
    case EFFECT_REVENGE:
        if ((gProtectStructs[battlerAtk].physicalDmg
                && gProtectStructs[battlerAtk].physicalBattlerId == battlerDef)
            || (gProtectStructs[battlerAtk].specialDmg
                && gProtectStructs[battlerAtk].specialBattlerId == battlerDef))
            basePower *= 2;
        break;
    case EFFECT_WEATHER_BALL:
        if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_ANY)
            basePower *= 2;
        break;
    case EFFECT_PURSUIT:
        if (gActionsByTurnOrder[GetBattlerTurnOrderNum(gBattlerTarget)] == B_ACTION_SWITCH)
            basePower *= 2;
        break;
    case EFFECT_NATURAL_GIFT:
        basePower = gNaturalGiftTable[ITEM_TO_BERRY(gBattleMons[battlerAtk].item)].power;
        break;
    case EFFECT_WAKE_UP_SLAP:
        if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP || GetBattlerAbility(battlerDef) == ABILITY_COMATOSE)
            basePower *= 2;
        break;
    case EFFECT_SMELLINGSALT:
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS)
            basePower *= 2;
        break;
    case EFFECT_WRING_OUT:
        basePower = 120 * gBattleMons[battlerDef].hp / gBattleMons[battlerDef].maxHP;
        break;
    case EFFECT_HEX:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY || GetBattlerAbility(battlerDef) == ABILITY_COMATOSE)
            basePower *= 2;
        break;
    case EFFECT_ASSURANCE:
        if (gProtectStructs[battlerDef].physicalDmg != 0 || gProtectStructs[battlerDef].specialDmg != 0 || gProtectStructs[battlerDef].confusionSelfDmg != 0)
            basePower *= 2;
        break;
    case EFFECT_TRUMP_CARD:
        i = GetBattleMonMoveSlot(&gBattleMons[battlerAtk], move);
        if (i != 4)
        {
            if (gBattleMons[battlerAtk].pp[i] >= ARRAY_COUNT(sTrumpCardPowerTable))
                basePower = sTrumpCardPowerTable[ARRAY_COUNT(sTrumpCardPowerTable) - 1];
            else
                basePower = sTrumpCardPowerTable[gBattleMons[battlerAtk].pp[i]];
        }
        break;
    case EFFECT_ACROBATICS:
        if (gBattleMons[battlerAtk].item == ITEM_NONE
            // Edge case, because removal of items happens after damage calculation.
            || (gSpecialStatuses[battlerAtk].gemBoost && GetBattlerHoldEffect(battlerAtk, FALSE) == HOLD_EFFECT_GEMS))
            basePower *= 2;
        break;
    case EFFECT_LOW_KICK:
        weight = GetBattlerWeight(battlerDef);
        for (i = 0; sWeightToDamageTable[i] != 0xFFFF; i += 2)
        {
            if (sWeightToDamageTable[i] > weight)
                break;
        }
        if (sWeightToDamageTable[i] != 0xFFFF)
            basePower = sWeightToDamageTable[i + 1];
        else
            basePower = 120;
        break;
    case EFFECT_HEAT_CRASH:
        weight = GetBattlerWeight(battlerAtk) / GetBattlerWeight(battlerDef);
        if (weight >= ARRAY_COUNT(sHeatCrashPowerTable))
            basePower = sHeatCrashPowerTable[ARRAY_COUNT(sHeatCrashPowerTable) - 1];
        else
            basePower = sHeatCrashPowerTable[i];
        break;
    case EFFECT_PUNISHMENT:
        basePower = 60 + (CountBattlerStatIncreases(battlerDef, FALSE) * 20);
        if (basePower > 200)
            basePower = 200;
        break;
    case EFFECT_STORED_POWER:
        basePower += (CountBattlerStatIncreases(battlerAtk, TRUE) * 20);
        break;
    case EFFECT_ELECTRO_BALL:
        speed = GetBattlerTotalSpeedStat(battlerAtk) / GetBattlerTotalSpeedStat(battlerDef);
        if (speed >= ARRAY_COUNT(sSpeedDiffPowerTable))
            speed = ARRAY_COUNT(sSpeedDiffPowerTable) - 1;
        basePower = sSpeedDiffPowerTable[speed];
        break;
    case EFFECT_GYRO_BALL:
        basePower = ((25 * GetBattlerTotalSpeedStat(battlerDef)) / GetBattlerTotalSpeedStat(battlerAtk)) + 1;
        if (basePower > 150)
            basePower = 150;
        break;
    case EFFECT_ECHOED_VOICE:
        // gBattleStruct->sameMoveTurns incremented in ppreduce
        if (gBattleStruct->sameMoveTurns[battlerAtk] != 0)
        {
            basePower += (basePower * gBattleStruct->sameMoveTurns[battlerAtk]);
            if (basePower > 200)
                basePower = 200;
        }
        break;
    case EFFECT_PAYBACK:
        if (GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef)
            && (gDisableStructs[battlerDef].isFirstTurn != 2 || B_PAYBACK_SWITCH_BOOST < GEN_5))
            basePower *= 2;
        break;
    case EFFECT_ROUND:
        if (gChosenMoveByBattler[BATTLE_PARTNER(battlerAtk)] == MOVE_ROUND && !(gAbsentBattlerFlags & gBitTable[BATTLE_PARTNER(battlerAtk)]))
            basePower *= 2;
        break;
    case EFFECT_FUSION_COMBO:
        if (gBattleMoves[gLastUsedMove].effect == EFFECT_FUSION_COMBO && move != gLastUsedMove)
            basePower *= 2;
        break;
    case EFFECT_LASH_OUT:
        if (gProtectStructs[battlerAtk].statFell)
            basePower *= 2;
        break;
    case EFFECT_EXPLOSION:
        if (move == MOVE_MISTY_EXPLOSION && gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN && IsBattlerGrounded(battlerAtk))
            MulModifier(&basePower, UQ_4_12(1.5));
        break;
    case EFFECT_DYNAMAX_DOUBLE_DMG:
        #ifdef B_DYNAMAX
        if (IsDynamaxed(battlerDef))
            basePower *= 2;
        #endif
        break;
    case EFFECT_HIDDEN_POWER:
    {
        #if B_HIDDEN_POWER_DMG < GEN_6
        u8 powerBits;

        powerBits = ((gBattleMons[gBattlerAttacker].hpIV & 2) >> 1)
                | ((gBattleMons[gBattlerAttacker].attackIV & 2) << 0)
                | ((gBattleMons[gBattlerAttacker].defenseIV & 2) << 1)
                | ((gBattleMons[gBattlerAttacker].speedIV & 2) << 2)
                | ((gBattleMons[gBattlerAttacker].spAttackIV & 2) << 3)
                | ((gBattleMons[gBattlerAttacker].spDefenseIV & 2) << 4);

        basePower = (40 * powerBits) / 63 + 30;
        #endif
        break;
    }
    case EFFECT_GRAV_APPLE:
        if (gFieldStatuses & STATUS_FIELD_GRAVITY)
            MulModifier(&basePower, UQ_4_12(1.5));
        break;
    }

    // move-specific base power changes
    switch (move)
    {
    case MOVE_WATER_SHURIKEN:
        if (gBattleMons[battlerAtk].species == SPECIES_GRENINJA_ASH)
            basePower = 20;
        break;
    }

    if (basePower == 0)
        basePower = 1;
    return basePower;
}

static u32 CalcMoveBasePowerAfterModifiers(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 updateFlags)
{
    u32 i, ability;
    u32 holdEffectAtk, holdEffectParamAtk;
    u16 basePower = CalcMoveBasePower(move, battlerAtk, battlerDef);
    u16 holdEffectModifier;
    u16 modifier = UQ_4_12(1.0);
    u32 atkSide = GET_BATTLER_SIDE(battlerAtk);

    // attacker's abilities
    switch (GetBattlerAbility(battlerAtk))
    {
    case ABILITY_TECHNICIAN:
        if (basePower <= 60)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_FLARE_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && IS_MOVE_SPECIAL(move))
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TOXIC_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && IS_MOVE_PHYSICAL(move))
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_RECKLESS:
        if (gBattleMoves[move].flags & FLAG_RECKLESS_BOOST)
           MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_IRON_FIST:
        if (gBattleMoves[move].flags & FLAG_IRON_FIST_BOOST)
           MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_SHEER_FORCE:
        if (gBattleMoves[move].flags & FLAG_SHEER_FORCE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_SAND_FORCE:
        if ((moveType == TYPE_STEEL || moveType == TYPE_ROCK || moveType == TYPE_GROUND)
            && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_RIVALRY:
        if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality) != MON_GENDERLESS
            && GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality) != MON_GENDERLESS)
        {
            if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality)
             == GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality))
               MulModifier(&modifier, UQ_4_12(1.25));
            else
               MulModifier(&modifier, UQ_4_12(0.75));
        }
        break;
    case ABILITY_ANALYTIC:
        if (GetBattlerTurnOrderNum(battlerAtk) == gBattlersCount - 1 && move != MOVE_FUTURE_SIGHT && move != MOVE_DOOM_DESIRE)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_TOUGH_CLAWS:
        if (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STRONG_JAW:
        if (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_MEGA_LAUNCHER:
        if (gBattleMoves[move].flags & FLAG_MEGA_LAUNCHER_BOOST)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_WATER)
           MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_STEELWORKER:
        if (moveType == TYPE_STEEL)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PIXILATE:
        if (moveType == TYPE_FAIRY && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_GALVANIZE:
        if (moveType == TYPE_ELECTRIC && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_REFRIGERATE:
        if (moveType == TYPE_ICE && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_AERILATE:
        if (moveType == TYPE_FLYING && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_NORMALIZE:
        if (moveType == TYPE_NORMAL && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_PUNK_ROCK:
        if (gBattleMoves[move].flags & FLAG_SOUND)
            MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STEELY_SPIRIT:
        if (moveType == TYPE_STEEL)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TRANSISTOR:
        if (moveType == TYPE_ELECTRIC)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_DRAGONS_MAW:
        if (moveType == TYPE_DRAGON)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // field abilities
    if ((IsAbilityOnField(ABILITY_DARK_AURA) && moveType == TYPE_DARK)
        || (IsAbilityOnField(ABILITY_FAIRY_AURA) && moveType == TYPE_FAIRY))
    {
        if (IsAbilityOnField(ABILITY_AURA_BREAK))
            MulModifier(&modifier, UQ_4_12(0.75));
        else
            MulModifier(&modifier, UQ_4_12(1.25));
    }

    // attacker partner's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerAtk)))
        {
        case ABILITY_BATTERY:
            if (IS_MOVE_SPECIAL(move))
                MulModifier(&modifier, UQ_4_12(1.3));
            break;
        case ABILITY_POWER_SPOT:
            MulModifier(&modifier, UQ_4_12(1.3));
            break;
        case ABILITY_STEELY_SPIRIT:
            if (moveType == TYPE_STEEL)
                MulModifier(&modifier, UQ_4_12(1.5));
            break;
        }
    }

    // target's abilities
    ability = GetBattlerAbility(battlerDef);
    switch (ability)
    {
    case ABILITY_HEATPROOF:
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_FIRE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
        break;
    case ABILITY_DRY_SKIN:
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(1.25));
        break;
    case ABILITY_FLUFFY:
        if (IsMoveMakingContact(move, battlerAtk))
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    }

    holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);
    holdEffectParamAtk = GetBattlerHoldEffectParam(battlerAtk);
    if (holdEffectParamAtk > 100)
        holdEffectParamAtk = 100;

    holdEffectModifier = UQ_4_12(1.0) + sPercentToModifier[holdEffectParamAtk];

    // attacker's hold effect
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_LUSTROUS_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_PALKIA && (moveType == TYPE_WATER || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_ADAMANT_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_DIALGA && (moveType == TYPE_STEEL || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GRISEOUS_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_GIRATINA && (moveType == TYPE_GHOST || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_SOUL_DEW:
        if ((gBattleMons[battlerAtk].species == SPECIES_LATIAS || gBattleMons[battlerAtk].species == SPECIES_LATIOS) && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GEMS:
        if (gSpecialStatuses[battlerAtk].gemBoost && gBattleMons[battlerAtk].item)
            MulModifier(&modifier, UQ_4_12(1.0) + sPercentToModifier[gSpecialStatuses[battlerAtk].gemParam]);
        break;
    case HOLD_EFFECT_BUG_POWER:
    case HOLD_EFFECT_STEEL_POWER:
    case HOLD_EFFECT_GROUND_POWER:
    case HOLD_EFFECT_ROCK_POWER:
    case HOLD_EFFECT_GRASS_POWER:
    case HOLD_EFFECT_DARK_POWER:
    case HOLD_EFFECT_FIGHTING_POWER:
    case HOLD_EFFECT_ELECTRIC_POWER:
    case HOLD_EFFECT_WATER_POWER:
    case HOLD_EFFECT_FLYING_POWER:
    case HOLD_EFFECT_POISON_POWER:
    case HOLD_EFFECT_ICE_POWER:
    case HOLD_EFFECT_GHOST_POWER:
    case HOLD_EFFECT_PSYCHIC_POWER:
    case HOLD_EFFECT_FIRE_POWER:
    case HOLD_EFFECT_DRAGON_POWER:
    case HOLD_EFFECT_NORMAL_POWER:
    case HOLD_EFFECT_FAIRY_POWER:
        for (i = 0; i < ARRAY_COUNT(sHoldEffectToType); i++)
        {
            if (holdEffectAtk == sHoldEffectToType[i][0])
            {
                if (moveType == sHoldEffectToType[i][1])
                    MulModifier(&modifier, holdEffectModifier);
                break;
            }
        }
        break;
    case HOLD_EFFECT_PLATE:
        if (moveType == ItemId_GetSecondaryId(gBattleMons[battlerAtk].item))
            MulModifier(&modifier, holdEffectModifier);
        break;
    }

    // move effect
    switch (gBattleMoves[move].effect)
    {
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_VENOSHOCK:
        if (gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_RETALIATE:
        if (gSideTimers[atkSide].retaliateTimer == 1)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_SOLARBEAM:
        if (WEATHER_HAS_EFFECT && gBattleWeather & (WEATHER_HAIL_ANY | WEATHER_SANDSTORM_ANY | WEATHER_RAIN_ANY))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_STOMPING_TANTRUM:
        if (gBattleStruct->lastMoveFailed & gBitTable[battlerAtk])
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BULLDOZE:
    case EFFECT_MAGNITUDE:
    case EFFECT_EARTHQUAKE:
        if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_KNOCK_OFF:
        if (gBattleMons[battlerDef].item != ITEM_NONE && GetBattlerAbility(battlerDef) != ABILITY_STICKY_HOLD)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // various effecs
    if (gProtectStructs[battlerAtk].helpingHand)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP && moveType == TYPE_ELECTRIC)
        MulModifier(&modifier, UQ_4_12(2.0));
    if (gStatuses3[battlerAtk] & STATUS3_ME_FIRST)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && moveType == TYPE_GRASS && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN && moveType == TYPE_DRAGON && IsBattlerGrounded(battlerDef) && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, UQ_4_12(0.5));
    if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN && moveType == TYPE_ELECTRIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN && moveType == TYPE_PSYCHIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));

    return ApplyModifier(modifier, basePower);
}

static u32 CalcAttackStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    u8 atkStage;
    u32 atkStat;
    u16 modifier;

    if (gBattleMoves[move].effect == EFFECT_FOUL_PLAY)
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerDef].attack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerDef].spAttack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_SPATK];
        }
    }
    else if (gBattleMoves[move].effect == EFFECT_BODY_PRESS)
    {
        atkStat = gBattleMons[battlerAtk].defense;
        atkStage = gBattleMons[battlerAtk].statStages[STAT_DEF];
    }
    else
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerAtk].attack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spAttack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_SPATK];
        }
    }

    // critical hits ignore attack stat's stage drops
    if (isCrit && atkStage < DEFAULT_STAT_STAGE)
        atkStage = DEFAULT_STAT_STAGE;
    // pokemon with unaware ignore attack stat changes while taking damage
    if (GetBattlerAbility(battlerDef) == ABILITY_UNAWARE)
        atkStage = DEFAULT_STAT_STAGE;

    atkStat *= gStatStageRatios[atkStage][0];
    atkStat /= gStatStageRatios[atkStage][1];

    // apply attack stat modifiers
    modifier = UQ_4_12(1.0);

    // attacker's abilities
    switch (GetBattlerAbility(battlerAtk))
    {
    case ABILITY_HUGE_POWER:
    case ABILITY_PURE_POWER:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_SLOW_START:
        if (gDisableStructs[battlerAtk].slowStartTimer != 0)
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case ABILITY_SOLAR_POWER:
        if (IS_MOVE_SPECIAL(move) && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_DEFEATIST:
        if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 2))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TYPE_FIRE && gBattleResources->flags->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SWARM:
        if (moveType == TYPE_BUG && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TORRENT:
        if (moveType == TYPE_WATER && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_BLAZE:
        if (moveType == TYPE_FIRE && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_OVERGROW:
        if (moveType == TYPE_GRASS && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PLUS:
    case ABILITY_MINUS:
        if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
        {
            u32 partnerAbility = GetBattlerAbility(BATTLE_PARTNER(battlerAtk));
            if (partnerAbility == ABILITY_PLUS || partnerAbility == ABILITY_MINUS)
                MulModifier(&modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[battlerAtk].species == SPECIES_CHERRIM && WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY) && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_HUSTLE:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_STAKEOUT:
        if (gDisableStructs[battlerDef].isFirstTurn == 2) // just switched in
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_GUTS:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_THICK_FAT:
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_THICK_FAT);
        }
        break;
    case ABILITY_ICE_SCALES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    }

    // ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerAtk)))
        {
        case ABILITY_FLOWER_GIFT:
            if (gBattleMons[BATTLE_PARTNER(battlerAtk)].species == SPECIES_CHERRIM && WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY) && IS_MOVE_PHYSICAL(move))
                MulModifier(&modifier, UQ_4_12(1.5));
            break;
        }
    }

    // attacker's hold effect
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_CUBONE
         || GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_MAROWAK)
         && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (gBattleMons[battlerAtk].species == SPECIES_PIKACHU)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // The offensive stats of a Player's Pokémon are boosted by x1.1 (+10%) if they have the 1st badge and 7th badges.
    // Having the 1st badge boosts physical attack while having the 7th badge boosts special attack.
    if (ShouldGetStatBadgeBoost(FLAG_BADGE01_GET, battlerAtk) && IS_MOVE_PHYSICAL(move))
        MulModifier(&modifier, UQ_4_12(1.1));
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerAtk) && IS_MOVE_SPECIAL(move))
        MulModifier(&modifier, UQ_4_12(1.1));

    return ApplyModifier(modifier, atkStat);
}

static bool32 CanEvolve(u32 species)
{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[species][i].method
         && gEvolutionTable[species][i].method != EVO_MEGA_EVOLUTION
         && gEvolutionTable[species][i].method != EVO_MOVE_MEGA_EVOLUTION)
            return TRUE;
    }
    return FALSE;
}

static u32 CalcDefenseStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    bool32 usesDefStat;
    u8 defStage;
    u32 defStat, def, spDef;
    u16 modifier;

    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) // the defense stats are swapped
    {
        def = gBattleMons[battlerDef].spDefense;
        spDef = gBattleMons[battlerDef].defense;
    }
    else
    {
        def = gBattleMons[battlerDef].defense;
        spDef = gBattleMons[battlerDef].spDefense;
    }

    if (gBattleMoves[move].effect == EFFECT_PSYSHOCK || IS_MOVE_PHYSICAL(move)) // uses defense stat instead of sp.def
    {
        defStat = def;
        defStage = gBattleMons[battlerDef].statStages[STAT_DEF];
        usesDefStat = TRUE;
    }
    else // is special
    {
        defStat = spDef;
        defStage = gBattleMons[battlerDef].statStages[STAT_SPDEF];
        usesDefStat = FALSE;
    }

    // critical hits ignore positive stat changes
    if (isCrit && defStage > DEFAULT_STAT_STAGE)
        defStage = DEFAULT_STAT_STAGE;
    // pokemon with unaware ignore defense stat changes while dealing damage
    if (GetBattlerAbility(battlerAtk) == ABILITY_UNAWARE)
        defStage = DEFAULT_STAT_STAGE;
    // certain moves also ignore stat changes
    if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
        defStage = DEFAULT_STAT_STAGE;

    defStat *= gStatStageRatios[defStage][0];
    defStat /= gStatStageRatios[defStage][1];

    // apply defense stat modifiers
    modifier = UQ_4_12(1.0);

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_MARVEL_SCALE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY && usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_MARVEL_SCALE);
        }
        break;
    case ABILITY_FUR_COAT:
        if (usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(2.0));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_FUR_COAT);
        }
        break;
    case ABILITY_GRASS_PELT:
        if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_GRASS_PELT);
        }
        break;
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[battlerDef].species == SPECIES_CHERRIM && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && !usesDefStat)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PUNK_ROCK:
        if (gBattleMoves[move].flags & FLAG_SOUND)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    }

    // ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerDef)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerDef)))
        {
        case ABILITY_FLOWER_GIFT:
            if (gBattleMons[BATTLE_PARTNER(battlerDef)].species == SPECIES_CHERRIM && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && !usesDefStat)
                MulModifier(&modifier, UQ_4_12(1.5));
            break;
        }
    }

    // target's hold effects
    switch (GetBattlerHoldEffect(battlerDef, TRUE))
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && !usesDefStat)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_METAL_POWDER:
        if (gBattleMons[battlerDef].species == SPECIES_DITTO && usesDefStat && !(gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_EVIOLITE:
        if (CanEvolve(gBattleMons[battlerDef].species))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (!usesDefStat)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // sandstorm sp.def boost for rock types
    if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_ROCK) && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY && !usesDefStat)
        MulModifier(&modifier, UQ_4_12(1.5));

    // The defensive stats of a Player's Pokémon are boosted by x1.1 (+10%) if they have the 5th badge and 7th badges.
    // Having the 5th badge boosts physical defense while having the 7th badge boosts special defense.
    if (ShouldGetStatBadgeBoost(FLAG_BADGE05_GET, battlerDef) && IS_MOVE_PHYSICAL(move))
        MulModifier(&modifier, UQ_4_12(1.1));
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerDef) && IS_MOVE_SPECIAL(move))
        MulModifier(&modifier, UQ_4_12(1.1));

    return ApplyModifier(modifier, defStat);
}

static u32 CalcFinalDmg(u32 dmg, u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, u16 typeEffectivenessModifier, bool32 isCrit, bool32 updateFlags)
{
    u32 percentBoost;
    u32 abilityAtk = GetBattlerAbility(battlerAtk);
    u32 abilityDef = GetBattlerAbility(battlerDef);
    u32 defSide = GET_BATTLER_SIDE(battlerDef);
    u16 finalModifier = UQ_4_12(1.0);
    u16 itemDef = gBattleMons[battlerDef].item;

    // check multiple targets in double battle
    if (GetMoveTargetCount(move, battlerAtk, battlerDef) >= 2)
        MulModifier(&finalModifier, UQ_4_12(0.75));

    // take type effectiveness
    MulModifier(&finalModifier, typeEffectivenessModifier);

    // check crit
    if (isCrit)
        dmg = ApplyModifier((B_CRIT_MULTIPLIER >= GEN_6 ? UQ_4_12(1.5) : UQ_4_12(2.0)), dmg);

    // check burn
    if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && IS_MOVE_PHYSICAL(move)
        && gBattleMoves[move].effect != EFFECT_FACADE && abilityAtk != ABILITY_GUTS)
        dmg = ApplyModifier(UQ_4_12(0.5), dmg);

    // check sunny/rain weather
    if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_RAIN_ANY)
    {
        if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(UQ_4_12(0.5), dmg);
        else if (moveType == TYPE_WATER)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
    }
    else if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
    {
        if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
        else if (moveType == TYPE_WATER)
            dmg = ApplyModifier(UQ_4_12(0.5), dmg);
    }

    // check stab
    if (IS_BATTLER_OF_TYPE(battlerAtk, moveType) && move != MOVE_STRUGGLE)
    {
        if (abilityAtk == ABILITY_ADAPTABILITY)
            MulModifier(&finalModifier, UQ_4_12(2.0));
        else
            MulModifier(&finalModifier, UQ_4_12(1.5));
    }

    // reflect, light screen, aurora veil
    if (((gSideStatuses[defSide] & SIDE_STATUS_REFLECT && IS_MOVE_PHYSICAL(move))
            || (gSideStatuses[defSide] & SIDE_STATUS_LIGHTSCREEN && IS_MOVE_SPECIAL(move))
            || (gSideStatuses[defSide] & SIDE_STATUS_AURORA_VEIL))
        && abilityAtk != ABILITY_INFILTRATOR)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            MulModifier(&finalModifier, UQ_4_12(0.66));
        else
            MulModifier(&finalModifier, UQ_4_12(0.5));
    }

    // attacker's abilities
    switch (abilityAtk)
    {
    case ABILITY_TINTED_LENS:
        if (typeEffectivenessModifier <= UQ_4_12(0.5))
            MulModifier(&finalModifier, UQ_4_12(2.0));
        break;
    case ABILITY_SNIPER:
        if (isCrit)
            MulModifier(&finalModifier, UQ_4_12(1.5));
        break;
    case ABILITY_NEUROFORCE:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.25));
        break;
    }

    // target's abilities
    switch (abilityDef)
    {
    case ABILITY_MULTISCALE:
    case ABILITY_SHADOW_SHIELD:
        if (BATTLER_MAX_HP(battlerDef))
            MulModifier(&finalModifier, UQ_4_12(0.5));
        break;
    case ABILITY_FILTER:
    case ABILITY_SOLID_ROCK:
    case ABILITY_PRISM_ARMOR:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.75));
        break;
    }

    // target's ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerDef)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerDef)))
        {
        case ABILITY_FRIEND_GUARD:
            MulModifier(&finalModifier, UQ_4_12(0.75));
            break;
        }
    }

    // attacker's hold effect
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_METRONOME:
        percentBoost = min((gBattleStruct->sameMoveTurns[battlerAtk] * GetBattlerHoldEffectParam(battlerAtk)), 100);
        MulModifier(&finalModifier, UQ_4_12(1.0) + sPercentToModifier[percentBoost]);
        break;
    case HOLD_EFFECT_EXPERT_BELT:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.2));
        break;
    case HOLD_EFFECT_LIFE_ORB:
        MulModifier(&finalModifier, UQ_4_12(1.3));
        break;
    }

    // target's hold effect
    switch (GetBattlerHoldEffect(battlerDef, TRUE))
    {
    // berries reducing dmg
    case HOLD_EFFECT_RESIST_BERRY:
        if (moveType == GetBattlerHoldEffectParam(battlerDef)
            && (moveType == TYPE_NORMAL || typeEffectivenessModifier >= UQ_4_12(2.0))
            && !UnnerveOn(battlerDef, itemDef))
        {
            if (abilityDef == ABILITY_RIPEN)
                MulModifier(&finalModifier, UQ_4_12(0.25));
            else
                MulModifier(&finalModifier, UQ_4_12(0.5));
            if (updateFlags)
                gSpecialStatuses[battlerDef].berryReduced = 1;
        }
        break;
    }

    if (gBattleMoves[move].flags & FLAG_DMG_MINIMIZE    && gStatuses3[battlerDef] & STATUS3_MINIMIZED)
        MulModifier(&finalModifier, UQ_4_12(2.0));
    if (gBattleMoves[move].flags & FLAG_DMG_UNDERGROUND && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
        MulModifier(&finalModifier, UQ_4_12(2.0));
    if (gBattleMoves[move].flags & FLAG_DMG_UNDERWATER  && gStatuses3[battlerDef] & STATUS3_UNDERWATER)
        MulModifier(&finalModifier, UQ_4_12(2.0));
    if (gBattleMoves[move].flags & FLAG_DMG_2X_IN_AIR   && gStatuses3[battlerDef] & STATUS3_ON_AIR)
        MulModifier(&finalModifier, UQ_4_12(2.0));

    dmg = ApplyModifier(finalModifier, dmg);
    if (dmg == 0)
        dmg = 1;

    return dmg;
}

s32 CalculateMoveDamage(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, s32 fixedBasePower, bool32 isCrit, bool32 randomFactor, bool32 updateFlags)
{
    s32 dmg;
    u16 typeEffectivenessModifier;

    typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(move, moveType, battlerAtk, battlerDef, updateFlags);

    // Don't calculate damage if the move has no effect on target.
    if (typeEffectivenessModifier == UQ_4_12(0))
        return 0;

    if (fixedBasePower)
        gBattleMovePower = fixedBasePower;
    else
        gBattleMovePower = CalcMoveBasePowerAfterModifiers(move, battlerAtk, battlerDef, moveType, updateFlags);

    // long dmg basic formula
    dmg = ((gBattleMons[battlerAtk].level * 2) / 5) + 2;
    dmg *= gBattleMovePower;
    dmg *= CalcAttackStat(move, battlerAtk, battlerDef, moveType, isCrit, updateFlags);
    dmg /= CalcDefenseStat(move, battlerAtk, battlerDef, moveType, isCrit, updateFlags);
    dmg = (dmg / 50) + 2;

    // Calculate final modifiers.
    dmg = CalcFinalDmg(dmg, move, battlerAtk, battlerDef, moveType, typeEffectivenessModifier, isCrit, updateFlags);

    // Add a random factor.
    if (randomFactor)
    {
        dmg *= 100 - (Random() % 16);
        dmg /= 100;
    }

    if (dmg == 0)
        dmg = 1;

    return dmg;
}

static void MulByTypeEffectiveness(u16 *modifier, u16 move, u8 moveType, u8 battlerDef, u8 defType, u8 battlerAtk, bool32 recordAbilities)
{
    u16 mod = GetTypeModifier(moveType, defType);

    if (mod == UQ_4_12(0.0) && GetBattlerHoldEffect(battlerDef, TRUE) == HOLD_EFFECT_RING_TARGET)
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordItemEffectBattle(battlerDef, HOLD_EFFECT_RING_TARGET);
    }
    else if ((moveType == TYPE_FIGHTING || moveType == TYPE_NORMAL) && defType == TYPE_GHOST && gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
    }
    else if ((moveType == TYPE_FIGHTING || moveType == TYPE_NORMAL) && defType == TYPE_GHOST && GetBattlerAbility(battlerAtk) == ABILITY_SCRAPPY && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_SCRAPPY);
    }

    if (moveType == TYPE_PSYCHIC && defType == TYPE_DARK && gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if (gBattleMoves[move].effect == EFFECT_FREEZE_DRY && defType == TYPE_WATER)
        mod = UQ_4_12(2.0);
    if (moveType == TYPE_GROUND && defType == TYPE_FLYING && IsBattlerGrounded(battlerDef) && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);

    if (gProtectStructs[battlerDef].kingsShielded && gBattleMoves[move].effect != EFFECT_FEINT)
        mod = UQ_4_12(1.0);

    // WEATHER_STRONG_WINDS weakens Super Effective moves against Flying-type Pokémon
    if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_STRONG_WINDS)
    {
        if (defType == TYPE_FLYING && mod >= UQ_4_12(2.0))
            mod = UQ_4_12(1.0);
    }

    MulModifier(modifier, mod);
}

static void UpdateMoveResultFlags(u16 modifier)
{
    if (modifier == UQ_4_12(0.0))
    {
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE);
    }
    else if (modifier == UQ_4_12(1.0))
    {
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modifier > UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else //if (modifier < UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
}

static u16 CalcTypeEffectivenessMultiplierInternal(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities, u16 modifier)
{
    MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, gBattleMons[battlerDef].type1, battlerAtk, recordAbilities);
    if (gBattleMons[battlerDef].type2 != gBattleMons[battlerDef].type1)
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, gBattleMons[battlerDef].type2, battlerAtk, recordAbilities);
    if (gBattleMons[battlerDef].type3 != TYPE_MYSTERY && gBattleMons[battlerDef].type3 != gBattleMons[battlerDef].type2
        && gBattleMons[battlerDef].type3 != gBattleMons[battlerDef].type1)
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, gBattleMons[battlerDef].type3, battlerAtk, recordAbilities);

    if (moveType == TYPE_GROUND && !IsBattlerGrounded(battlerDef) && !(gBattleMoves[move].flags & FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING))
    {
        modifier = UQ_4_12(0.0);
        if (recordAbilities && GetBattlerAbility(battlerDef) == ABILITY_LEVITATE)
        {
            gLastUsedAbility = ABILITY_LEVITATE;
            gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastLandedMoves[battlerDef] = 0;
            gBattleCommunication[MISS_TYPE] = B_MSG_GROUND_MISS;
            RecordAbilityBattle(battlerDef, ABILITY_LEVITATE);
        }
    }

    // Thousand Arrows ignores type modifiers for flying mons
    if (!IsBattlerGrounded(battlerDef) && (gBattleMoves[move].flags & FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING)
        && (gBattleMons[battlerDef].type1 == TYPE_FLYING || gBattleMons[battlerDef].type2 == TYPE_FLYING || gBattleMons[battlerDef].type3 == TYPE_FLYING))
    {
        modifier = UQ_4_12(1.0);
    }

    if (((GetBattlerAbility(battlerDef) == ABILITY_WONDER_GUARD && modifier <= UQ_4_12(1.0))
        || (GetBattlerAbility(battlerDef) == ABILITY_TELEPATHY && battlerDef == BATTLE_PARTNER(battlerAtk)))
        && gBattleMoves[move].power)
    {
        modifier = UQ_4_12(0.0);
        if (recordAbilities)
        {
            gLastUsedAbility = gBattleMons[battlerDef].ability;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gLastLandedMoves[battlerDef] = 0;
            gBattleCommunication[MISS_TYPE] = B_MSG_AVOIDED_DMG;
            RecordAbilityBattle(battlerDef, gBattleMons[battlerDef].ability);
        }
    }

    return modifier;
}

u16 CalcTypeEffectivenessMultiplier(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities)
{
    u16 modifier = UQ_4_12(1.0);

    if (move != MOVE_STRUGGLE && moveType != TYPE_MYSTERY)
    {
        modifier = CalcTypeEffectivenessMultiplierInternal(move, moveType, battlerAtk, battlerDef, recordAbilities, modifier);
        if (gBattleMoves[move].effect == EFFECT_TWO_TYPED_MOVE)
            modifier = CalcTypeEffectivenessMultiplierInternal(move, gBattleMoves[move].argument, battlerAtk, battlerDef, recordAbilities, modifier);
    }

    if (recordAbilities)
        UpdateMoveResultFlags(modifier);
    return modifier;
}

u16 CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef)
{
    u16 modifier = UQ_4_12(1.0);
    u8 moveType = gBattleMoves[move].type;

    if (move != MOVE_STRUGGLE && moveType != TYPE_MYSTERY)
    {
        MulByTypeEffectiveness(&modifier, move, moveType, 0, gBaseStats[speciesDef].type1, 0, FALSE);
        if (gBaseStats[speciesDef].type2 != gBaseStats[speciesDef].type1)
            MulByTypeEffectiveness(&modifier, move, moveType, 0, gBaseStats[speciesDef].type2, 0, FALSE);

        if (moveType == TYPE_GROUND && abilityDef == ABILITY_LEVITATE && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
            modifier = UQ_4_12(0.0);
        if (abilityDef == ABILITY_WONDER_GUARD && modifier <= UQ_4_12(1.0) && gBattleMoves[move].power)
            modifier = UQ_4_12(0.0);
    }

    UpdateMoveResultFlags(modifier);
    return modifier;
}

u16 GetTypeModifier(u8 atkType, u8 defType)
{
    if (B_FLAG_INVERSE_BATTLE != 0 && FlagGet(B_FLAG_INVERSE_BATTLE))
        return sInverseTypeEffectivenessTable[atkType][defType];
    else
        return sTypeEffectivenessTable[atkType][defType];
}

s32 GetStealthHazardDamage(u8 hazardType, u8 battlerId)
{
    u8 type1 = gBattleMons[battlerId].type1;
    u8 type2 = gBattleMons[battlerId].type2;
    u32 maxHp = gBattleMons[battlerId].maxHP;
    s32 dmg = 0;
    u16 modifier = UQ_4_12(1.0);

    MulModifier(&modifier, GetTypeModifier(hazardType, type1));
    if (type2 != type1)
        MulModifier(&modifier, GetTypeModifier(hazardType, type2));

    switch (modifier)
    {
    case UQ_4_12(0.0):
        dmg = 0;
        break;
    case UQ_4_12(0.25):
        dmg = maxHp / 32;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(0.5):
        dmg = maxHp / 16;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(1.0):
        dmg = maxHp / 8;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(2.0):
        dmg = maxHp / 4;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(4.0):
        dmg = maxHp / 2;
        if (dmg == 0)
            dmg = 1;
        break;
    }

    return dmg;
}

bool32 IsPartnerMonFromSameTrainer(u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        return FALSE;
    else if (GetBattlerSide(battlerId) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        return FALSE;
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        return FALSE;
    else
        return TRUE;
}

u16 GetMegaEvolutionSpecies(u16 preEvoSpecies, u16 heldItemId)
{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[preEvoSpecies][i].method == EVO_MEGA_EVOLUTION
            && gEvolutionTable[preEvoSpecies][i].param == heldItemId)
                return gEvolutionTable[preEvoSpecies][i].targetSpecies;
    }
    return SPECIES_NONE;
}

u16 GetWishMegaEvolutionSpecies(u16 preEvoSpecies, u16 moveId1, u16 moveId2, u16 moveId3, u16 moveId4)
{
    u32 i, par;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[preEvoSpecies][i].method == EVO_MOVE_MEGA_EVOLUTION)
        {
            par = gEvolutionTable[preEvoSpecies][i].param;
            if (par == moveId1 || par == moveId2 || par == moveId3 || par == moveId4)
                return gEvolutionTable[preEvoSpecies][i].targetSpecies;
        }
    }
    return SPECIES_NONE;
}

bool32 CanMegaEvolve(u8 battlerId)
{
    u32 itemId, holdEffect, species;
    struct Pokemon *mon;
    u8 battlerPosition = GetBattlerPosition(battlerId);
    u8 partnerPosition = GetBattlerPosition(BATTLE_PARTNER(battlerId));
    struct MegaEvolutionData *mega = &(((struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]))->mega);

#ifdef ITEM_EXPANSION
    // Check if Player has a Mega Bracelet
    if ((GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT))
     && !CheckBagHasItem(ITEM_MEGA_BRACELET, 1))
        return FALSE;
#endif

    // Check if trainer already mega evolved a pokemon.
    if (mega->alreadyEvolved[battlerPosition])
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (IsPartnerMonFromSameTrainer(battlerId)
            && (mega->alreadyEvolved[partnerPosition] || (mega->toEvolve & gBitTable[BATTLE_PARTNER(battlerId)])))
            return FALSE;
    }

    // Gets mon data.
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];

    species = GetMonData(mon, MON_DATA_SPECIES);
    itemId = GetMonData(mon, MON_DATA_HELD_ITEM);

    // Check if there is an entry in the evolution table for regular Mega Evolution.
    if (GetMegaEvolutionSpecies(species, itemId) != SPECIES_NONE)
    {
        if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId])
            holdEffect = gBattleStruct->debugHoldEffects[battlerId];
        else if (itemId == ITEM_ENIGMA_BERRY)
            holdEffect = gEnigmaBerries[battlerId].holdEffect;
        else
            holdEffect = ItemId_GetHoldEffect(itemId);

        // Can Mega Evolve via Item.
        if (holdEffect == HOLD_EFFECT_MEGA_STONE)
        {
            gBattleStruct->mega.isWishMegaEvo = FALSE;
            return TRUE;
        }
    }

    // Check if there is an entry in the evolution table for Wish Mega Evolution.
    if (GetWishMegaEvolutionSpecies(species, GetMonData(mon, MON_DATA_MOVE1), GetMonData(mon, MON_DATA_MOVE2), GetMonData(mon, MON_DATA_MOVE3), GetMonData(mon, MON_DATA_MOVE4)))
    {
        gBattleStruct->mega.isWishMegaEvo = TRUE;
        return TRUE;
    }

    // No checks passed, the mon CAN'T mega evolve.
    return FALSE;
}

void UndoMegaEvolution(u32 monId)
{
    if (gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] & gBitTable[monId])
    {
        gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] &= ~(gBitTable[monId]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleStruct->mega.playerEvolvedSpecies);
        CalculateMonStats(&gPlayerParty[monId]);
    }
    // While not exactly a mega evolution, Zygarde follows the same rules.
    else if (GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL) == SPECIES_ZYGARDE_COMPLETE)
    {
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleStruct->changedSpecies[monId]);
        gBattleStruct->changedSpecies[monId] = 0;
        CalculateMonStats(&gPlayerParty[monId]);
    }
}

void UndoFormChange(u32 monId, u32 side, bool32 isSwitchingOut)
{
    u32 i, currSpecies;
    struct Pokemon *party = (side == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
    static const u16 species[][2] = // changed form id, default form id
    {
        {SPECIES_MIMIKYU_BUSTED, SPECIES_MIMIKYU},
        {SPECIES_GRENINJA_ASH, SPECIES_GRENINJA_BATTLE_BOND},
        {SPECIES_AEGISLASH_BLADE, SPECIES_AEGISLASH},
        {SPECIES_DARMANITAN_ZEN_MODE, SPECIES_DARMANITAN},
        {SPECIES_MINIOR, SPECIES_MINIOR_CORE_RED},
        {SPECIES_MINIOR_METEOR_BLUE, SPECIES_MINIOR_CORE_BLUE},
        {SPECIES_MINIOR_METEOR_GREEN, SPECIES_MINIOR_CORE_GREEN},
        {SPECIES_MINIOR_METEOR_INDIGO, SPECIES_MINIOR_CORE_INDIGO},
        {SPECIES_MINIOR_METEOR_ORANGE, SPECIES_MINIOR_CORE_ORANGE},
        {SPECIES_MINIOR_METEOR_VIOLET, SPECIES_MINIOR_CORE_VIOLET},
        {SPECIES_MINIOR_METEOR_YELLOW, SPECIES_MINIOR_CORE_YELLOW},
        {SPECIES_WISHIWASHI_SCHOOL, SPECIES_WISHIWASHI},
        {SPECIES_CRAMORANT_GORGING, SPECIES_CRAMORANT},
        {SPECIES_CRAMORANT_GULPING, SPECIES_CRAMORANT},
    };

    if (isSwitchingOut) // Don't revert Mimikyu Busted or Ash-Greninja when switching out
        i = 2;
    else
        i = 0;

    currSpecies = GetMonData(&party[monId], MON_DATA_SPECIES, NULL);
    for (; i < ARRAY_COUNT(species); i++)
    {
        if (currSpecies == species[i][0])
        {
            SetMonData(&party[monId], MON_DATA_SPECIES, &species[i][1]);
            CalculateMonStats(&party[monId]);
            break;
        }
    }
}

bool32 DoBattlersShareType(u32 battler1, u32 battler2)
{
    s32 i;
    u8 types1[3] = {gBattleMons[battler1].type1, gBattleMons[battler1].type2, gBattleMons[battler1].type3};
    u8 types2[3] = {gBattleMons[battler2].type1, gBattleMons[battler2].type2, gBattleMons[battler2].type3};

    if (types1[2] == TYPE_MYSTERY)
        types1[2] = types1[0];
    if (types2[2] == TYPE_MYSTERY)
        types2[2] = types2[0];

    for (i = 0; i < 3; i++)
    {
        if (types1[i] == types2[0] || types1[i] == types2[1] || types1[i] == types2[2])
            return TRUE;
    }

    return FALSE;
}

bool32 CanBattlerGetOrLoseItem(u8 battlerId, u16 itemId)
{
    u16 species = gBattleMons[battlerId].species;
    u16 holdEffect = ItemId_GetHoldEffect(itemId);
    
    // Mail can be stolen now
    if (itemId == ITEM_ENIGMA_BERRY)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_KYOGRE && itemId == ITEM_BLUE_ORB) // includes primal
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GROUDON && itemId == ITEM_RED_ORB) // includes primal
        return FALSE;
    // Mega stone cannot be lost if pokemon's base species can mega evolve with it.
    else if (holdEffect == HOLD_EFFECT_MEGA_STONE && (GetMegaEvolutionSpecies(GET_BASE_SPECIES_ID(species), itemId) != SPECIES_NONE))
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GIRATINA && itemId == ITEM_GRISEOUS_ORB)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GENESECT && holdEffect == HOLD_EFFECT_DRIVE)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_SILVALLY && holdEffect == HOLD_EFFECT_MEMORY)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_ARCEUS && holdEffect == HOLD_EFFECT_PLATE)
        return FALSE;
#ifdef HOLD_EFFECT_Z_CRYSTAL
    else if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;
#endif
    else
        return TRUE;
}

struct Pokemon *GetIllusionMonPtr(u32 battlerId)
{
    if (gBattleStruct->illusion[battlerId].broken)
        return NULL;
    if (!gBattleStruct->illusion[battlerId].set)
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
            SetIllusionMon(&gPlayerParty[gBattlerPartyIndexes[battlerId]], battlerId);
        else
            SetIllusionMon(&gEnemyParty[gBattlerPartyIndexes[battlerId]], battlerId);
    }
    if (!gBattleStruct->illusion[battlerId].on)
        return NULL;

    return gBattleStruct->illusion[battlerId].mon;
}

void ClearIllusionMon(u32 battlerId)
{
    memset(&gBattleStruct->illusion[battlerId], 0, sizeof(gBattleStruct->illusion[battlerId]));
}

bool32 SetIllusionMon(struct Pokemon *mon, u32 battlerId)
{
    struct Pokemon *party, *partnerMon;
    s32 i, id;

    gBattleStruct->illusion[battlerId].set = 1;
    if (GetMonAbility(mon) != ABILITY_ILLUSION)
        return FALSE;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (IsBattlerAlive(BATTLE_PARTNER(battlerId)))
        partnerMon = &party[gBattlerPartyIndexes[BATTLE_PARTNER(battlerId)]];
    else
        partnerMon = mon;

    // Find last alive non-egg pokemon.
    for (i = PARTY_SIZE - 1; i >= 0; i--)
    {
        id = i;
        if (GetMonData(&party[id], MON_DATA_SANITY_HAS_SPECIES)
            && GetMonData(&party[id], MON_DATA_HP)
            && !GetMonData(&party[id], MON_DATA_IS_EGG)
            && &party[id] != mon
            && &party[id] != partnerMon)
        {
            gBattleStruct->illusion[battlerId].on = 1;
            gBattleStruct->illusion[battlerId].broken = 0;
            gBattleStruct->illusion[battlerId].partyId = id;
            gBattleStruct->illusion[battlerId].mon = &party[id];
            return TRUE;
        }
    }

    return FALSE;
}

bool8 ShouldGetStatBadgeBoost(u16 badgeFlag, u8 battlerId)
{
    if (B_BADGE_BOOST != GEN_3)
        return FALSE;
    else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_FRONTIER))
        return FALSE;
    else if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        return FALSE;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        return FALSE;
    else if (FlagGet(badgeFlag))
        return TRUE;
    else
        return FALSE;
}

u8 GetBattleMoveSplit(u32 moveId)
{
    if (IS_MOVE_STATUS(moveId) || B_PHYSICAL_SPECIAL_SPLIT >= GEN_4)
        return gBattleMoves[moveId].split;
    else if (gBattleMoves[moveId].type < TYPE_MYSTERY)
        return SPLIT_PHYSICAL;
    else
        return SPLIT_SPECIAL;
}

static bool32 TryRemoveScreens(u8 battler)
{
    bool32 removed = FALSE;
    u8 battlerSide = GetBattlerSide(battler);
    u8 enemySide = GetBattlerSide(BATTLE_OPPOSITE(battler));

    // try to remove from battler's side
    if (gSideStatuses[battlerSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[battlerSide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[battlerSide].reflectTimer = 0;
        gSideTimers[battlerSide].lightscreenTimer = 0;
        gSideTimers[battlerSide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    // try to remove from battler opponent's side
    if (gSideStatuses[enemySide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[enemySide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[enemySide].reflectTimer = 0;
        gSideTimers[enemySide].lightscreenTimer = 0;
        gSideTimers[enemySide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    return removed;
}

static bool32 IsUnnerveAbilityOnOpposingSide(u8 battlerId)
{
    if (IsAbilityOnOpposingSide(battlerId, ABILITY_UNNERVE)
      || IsAbilityOnOpposingSide(battlerId, ABILITY_AS_ONE_ICE_RIDER)
      || IsAbilityOnOpposingSide(battlerId, ABILITY_AS_ONE_SHADOW_RIDER))
        return TRUE;
    return FALSE;
}

bool32 TestMoveFlags(u16 move, u32 flag)
{
    if (gBattleMoves[move].flags & flag)
        return TRUE;
    return FALSE;
}

struct Pokemon *GetBattlerPartyData(u8 battlerId)
{
    struct Pokemon *mon;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];

    return mon;
}

//Make sure the input bank is any bank on the specific mon's side
bool32 CanFling(u8 battlerId)
{
    u16 item = gBattleMons[battlerId].item;
    u16 itemEffect = ItemId_GetHoldEffect(item);

    if (item == ITEM_NONE
      || GetBattlerAbility(battlerId) == ABILITY_KLUTZ
      || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
      || gDisableStructs[battlerId].embargoTimer != 0
      || !CanBattlerGetOrLoseItem(battlerId, item)
      //|| itemEffect == HOLD_EFFECT_PRIMAL_ORB
      || itemEffect == HOLD_EFFECT_GEMS
      #ifdef ITEM_ABILITY_CAPSULE
      || item == ITEM_ABILITY_CAPSULE
      #endif
      || (ItemId_GetPocket(item) == POCKET_BERRIES && IsAbilityOnSide(battlerId, ABILITY_UNNERVE))
      || GetPocketByItemId(item) == POCKET_POKE_BALLS)
        return FALSE;

    return TRUE;
}

// ability checks
bool32 IsRolePlayBannedAbilityAtk(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRolePlayBannedAttackerAbilities); i++)
    {
        if (ability == sRolePlayBannedAttackerAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsRolePlayBannedAbility(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRolePlayBannedAbilities); i++)
    {
        if (ability == sRolePlayBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsSkillSwapBannedAbility(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sSkillSwapBannedAbilities); i++)
    {
        if (ability == sSkillSwapBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsWorrySeedBannedAbility(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sWorrySeedBannedAbilities); i++)
    {
        if (ability == sWorrySeedBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsGastroAcidBannedAbility(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sGastroAcidBannedAbilities); i++)
    {
        if (ability == sGastroAcidBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsEntrainmentBannedAbilityAttacker(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sEntrainmentBannedAttackerAbilities); i++)
    {
        if (ability == sEntrainmentBannedAttackerAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsEntrainmentTargetOrSimpleBeamBannedAbility(u16 ability)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sEntrainmentTargetSimpleBeamBannedAbilities); i++)
    {
        if (ability == sEntrainmentTargetSimpleBeamBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

// Sort an array of battlers by speed
// Useful for effects like pickpocket, eject button, red card, dancer
void SortBattlersBySpeed(u8 *battlers, bool8 slowToFast)
{
    int i, j, currSpeed, currBattler;
    u16 speeds[4] = {0};
    
    for (i = 0; i < gBattlersCount; i++)
        speeds[i] = GetBattlerTotalSpeedStat(battlers[i]);

    for (i = 1; i < gBattlersCount; i++)
    {
        currBattler = battlers[i];
        currSpeed = speeds[i];
        j = i - 1;

        if (slowToFast)
        {
            while (j >= 0 && speeds[j] > currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && speeds[j] < currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }

        battlers[j + 1] = currBattler;
        speeds[j + 1] = currSpeed;
    }
}

void TryRestoreStolenItems(void)
{
    u32 i;
    u16 stolenItem = ITEM_NONE;
    
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleStruct->itemStolen[i].stolen)
        {
            stolenItem = gBattleStruct->itemStolen[i].originalItem;
            if (stolenItem != ITEM_NONE && ItemId_GetPocket(stolenItem) != POCKET_BERRIES)
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &stolenItem);  // Restore stolen non-berry items
        }
    }
}

bool32 CanStealItem(u8 battlerStealing, u8 battlerItem, u16 item)
{
    u8 stealerSide = GetBattlerSide(battlerStealing);
    
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        return FALSE;
    
    // Check if the battler trying to steal should be able to
    if (stealerSide == B_SIDE_OPPONENT
        && !(gBattleTypeFlags &
             (BATTLE_TYPE_EREADER_TRAINER
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_LINK
              | BATTLE_TYPE_RECORDED_LINK
              | BATTLE_TYPE_SECRET_BASE
              #if B_TRAINERS_KNOCK_OFF_ITEMS
              | BATTLE_TYPE_TRAINER
              #endif
              )))
    {
        return FALSE;
    }
    else if (!(gBattleTypeFlags &
          (BATTLE_TYPE_EREADER_TRAINER
           | BATTLE_TYPE_FRONTIER
           | BATTLE_TYPE_LINK
           | BATTLE_TYPE_RECORDED_LINK
           | BATTLE_TYPE_SECRET_BASE))
        && (gWishFutureKnock.knockedOffMons[stealerSide] & gBitTable[gBattlerPartyIndexes[battlerStealing]]))
    {
        return FALSE;
    }
    
    if (!CanBattlerGetOrLoseItem(battlerItem, item)      // Battler with item cannot have it stolen
      ||!CanBattlerGetOrLoseItem(battlerStealing, item)) // Stealer cannot take the item
        return FALSE;
    
    return TRUE;
}

void TrySaveExchangedItem(u8 battlerId, u16 stolenItem)
{
    // Because BtlController_EmitSetMonData does SetMonData, we need to save the stolen item only if it matches the battler's original
    // So, if the player steals an item during battle and has it stolen from it, it will not end the battle with it (naturally)
    #if B_TRAINERS_KNOCK_OFF_ITEMS == TRUE
    // If regular trainer battle and mon's original item matches what is being stolen, save it to be restored at end of battle
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
      && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
      && GetBattlerSide(battlerId) == B_SIDE_PLAYER
      && stolenItem == gBattleStruct->itemStolen[gBattlerPartyIndexes[battlerId]].originalItem)
        gBattleStruct->itemStolen[gBattlerPartyIndexes[battlerId]].stolen = TRUE;
    #endif
}

bool32 IsBattlerAffectedByHazards(u8 battlerId, bool32 toxicSpikes)
{
    bool32 ret = TRUE;
    u32 holdEffect = GetBattlerHoldEffect(gActiveBattler, TRUE);
    if (toxicSpikes && holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS && !IS_BATTLER_OF_TYPE(battlerId, TYPE_POISON))
    {
        ret = FALSE;
        RecordItemEffectBattle(battlerId, holdEffect);
    }
    else if (holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
    {
        ret = FALSE;
        RecordItemEffectBattle(battlerId, holdEffect);
    }
    return ret;
}

bool32 TestSheerForceFlag(u8 battler, u16 move)
{
    if (GetBattlerAbility(battler) == ABILITY_SHEER_FORCE && gBattleMoves[move].flags & FLAG_SHEER_FORCE_BOOST)
        return TRUE;
    else
        return FALSE;
}

// This function is the body of "jumpifstat", but can be used dynamically in a function
bool32 CompareStat(u8 battlerId, u8 statId, u8 cmpTo, u8 cmpKind)
{
    bool8 ret = FALSE;
    u8 statValue = gBattleMons[battlerId].statStages[statId];
    
    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (GetBattlerAbility(battlerId) == ABILITY_CONTRARY)
    {
        if (cmpKind == CMP_GREATER_THAN)
            cmpKind = CMP_LESS_THAN;
        else if (cmpKind == CMP_LESS_THAN)
            cmpKind = CMP_GREATER_THAN;

        if (cmpTo == MIN_STAT_STAGE)
            cmpTo = MAX_STAT_STAGE;
        else if (cmpTo == MAX_STAT_STAGE)
            cmpTo = MIN_STAT_STAGE;
    }

    switch (cmpKind)
    {
    case CMP_EQUAL:
        if (statValue == cmpTo)
            ret = TRUE;
        break;
    case CMP_NOT_EQUAL:
        if (statValue != cmpTo)
            ret = TRUE;
        break;
    case CMP_GREATER_THAN:
        if (statValue > cmpTo)
            ret = TRUE;
        break;
    case CMP_LESS_THAN:
        if (statValue < cmpTo)
            ret = TRUE;
        break;
    case CMP_COMMON_BITS:
        if (statValue & cmpTo)
            ret = TRUE;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(statValue & cmpTo))
            ret = TRUE;
        break;
    }
    
    return ret;
}

void BufferStatChange(u8 battlerId, u8 statId, u8 stringId)
{
    bool8 hasContrary = (GetBattlerAbility(battlerId) == ABILITY_CONTRARY);

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
    if (stringId == STRINGID_STATFELL)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
    }
    else if (stringId == STRINGID_STATROSE)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
    }
    else
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, stringId)
    }
}

bool32 TryRoomService(u8 battlerId)
{
    if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && CompareStat(battlerId, STAT_SPEED, MIN_STAT_STAGE, CMP_GREATER_THAN))
    {
        BufferStatChange(battlerId, STAT_SPEED, STRINGID_STATFELL);
        gEffectBattler = gBattleScripting.battler = battlerId;
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        gBattleScripting.animArg1 = 0xE + STAT_SPEED;
        gBattleScripting.animArg2 = 0;
        gLastUsedItem = gBattleMons[battlerId].item;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void DoBurmyFormChange(u32 monId)
{
    u16 newSpecies, currSpecies;
    s32 sentIn;
    struct Pokemon *party = gPlayerParty;

    sentIn = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];
    currSpecies = GetMonData(&party[monId], MON_DATA_SPECIES, NULL);

    if ((GET_BASE_SPECIES_ID(currSpecies) == SPECIES_BURMY) && (gBitTable[monId] & sentIn))
    {
        switch (gBattleTerrain)
        {  
            case BATTLE_TERRAIN_GRASS:
            case BATTLE_TERRAIN_LONG_GRASS:
            case BATTLE_TERRAIN_POND:
            case BATTLE_TERRAIN_MOUNTAIN:
            case BATTLE_TERRAIN_PLAIN:
                newSpecies = SPECIES_BURMY;
                break;
            case BATTLE_TERRAIN_CAVE:
            case BATTLE_TERRAIN_SAND:
                newSpecies = SPECIES_BURMY_SANDY_CLOAK;
                break;
            case BATTLE_TERRAIN_BUILDING:
                newSpecies = SPECIES_BURMY_TRASH_CLOAK;
                break;
            default: // Don't change form if last battle was water-related
                newSpecies = SPECIES_NONE;
                break;
        }

        if (newSpecies != SPECIES_NONE)
        {
            SetMonData(&party[monId], MON_DATA_SPECIES, &newSpecies);
            CalculateMonStats(&party[monId]);
        }
    }
}

bool32 BlocksPrankster(u16 move, u8 battlerPrankster, u8 battlerDef, bool32 checkTarget)
{
    #if B_PRANKSTER_DARK_TYPES >= GEN_7
    if (!gProtectStructs[battlerPrankster].pranksterElevated)
        return FALSE;
    if (GetBattlerSide(battlerPrankster) == GetBattlerSide(battlerDef))
        return FALSE;
    if (checkTarget && (gBattleMoves[move].target & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_DEPENDS)))
        return FALSE;
    if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
        return FALSE;
    if (gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;
    
    return TRUE;
    #endif
    return FALSE;
}

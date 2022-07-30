#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "malloc.h"
#include "pokemon.h"
#include "trainer_hill.h"
#include "party_menu.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "random.h"
#include "battle_scripts.h"
#include "constants/battle_string_ids.h"

void AllocateBattleResources(void)
{
    gBattleResources = gBattleResources; // something dumb needed to match

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        InitTrainerHillBattleStruct();

    gBattleStruct = AllocZeroed(sizeof(*gBattleStruct));

    gBattleResources = AllocZeroed(sizeof(*gBattleResources));
    gBattleResources->secretBase = AllocZeroed(sizeof(*gBattleResources->secretBase));
    gBattleResources->flags = AllocZeroed(sizeof(*gBattleResources->flags));
    gBattleResources->battleScriptsStack = AllocZeroed(sizeof(*gBattleResources->battleScriptsStack));
    gBattleResources->battleCallbackStack = AllocZeroed(sizeof(*gBattleResources->battleCallbackStack));
    gBattleResources->beforeLvlUp = AllocZeroed(sizeof(*gBattleResources->beforeLvlUp));
    gBattleResources->ai = AllocZeroed(sizeof(*gBattleResources->ai));
    gBattleResources->battleHistory = AllocZeroed(sizeof(*gBattleResources->battleHistory));
    gBattleResources->AI_ScriptsStack = AllocZeroed(sizeof(*gBattleResources->AI_ScriptsStack));

    gLinkBattleSendBuffer = AllocZeroed(BATTLE_BUFFER_LINK_SIZE);
    gLinkBattleRecvBuffer = AllocZeroed(BATTLE_BUFFER_LINK_SIZE);

    gBattleAnimBgTileBuffer = AllocZeroed(0x2000);
    gBattleAnimBgTilemapBuffer = AllocZeroed(0x1000);

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u16 currSecretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
        CreateSecretBaseEnemyParty(&gSaveBlock1Ptr->secretBases[currSecretBaseId]);
    }
}

void FreeBattleResources(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        FreeTrainerHillBattleStruct();

    if (gBattleResources != NULL)
    {
        FREE_AND_SET_NULL(gBattleStruct);

        FREE_AND_SET_NULL(gBattleResources->secretBase);
        FREE_AND_SET_NULL(gBattleResources->flags);
        FREE_AND_SET_NULL(gBattleResources->battleScriptsStack);
        FREE_AND_SET_NULL(gBattleResources->battleCallbackStack);
        FREE_AND_SET_NULL(gBattleResources->beforeLvlUp);
        FREE_AND_SET_NULL(gBattleResources->ai);
        FREE_AND_SET_NULL(gBattleResources->battleHistory);
        FREE_AND_SET_NULL(gBattleResources->AI_ScriptsStack);
        FREE_AND_SET_NULL(gBattleResources);

        FREE_AND_SET_NULL(gLinkBattleSendBuffer);
        FREE_AND_SET_NULL(gLinkBattleRecvBuffer);

        FREE_AND_SET_NULL(gBattleAnimBgTileBuffer);
        FREE_AND_SET_NULL(gBattleAnimBgTilemapBuffer);
    }
}

void AdjustFriendshipOnBattleFaint(u8 battlerId)
{
    u8 opposingBattlerId;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u8 opposingBattlerId2;

        opposingBattlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        opposingBattlerId2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

        if (gBattleMons[opposingBattlerId2].level > gBattleMons[opposingBattlerId].level)
            opposingBattlerId = opposingBattlerId2;
    }
    else
    {
        opposingBattlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    }

    if (gBattleMons[opposingBattlerId].level > gBattleMons[battlerId].level)
    {
        if (gBattleMons[opposingBattlerId].level - gBattleMons[battlerId].level > 29)
            AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battlerId]], FRIENDSHIP_EVENT_FAINT_LARGE);
        else
            AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battlerId]], FRIENDSHIP_EVENT_FAINT_SMALL);
    }
    else
    {
        AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battlerId]], FRIENDSHIP_EVENT_FAINT_SMALL);
    }
}

void SwitchPartyOrderInGameMulti(u8 battlerId, u8 arg1)
{
    if (GetBattlerSide(battlerId) != B_SIDE_OPPONENT)
    {
        s32 i;
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
            gBattlePartyCurrentOrder[i] = *(0 * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders));

        SwitchPartyMonSlots(GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battlerId]), GetPartyIdFromBattlePartyId(arg1));

        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
            *(0 * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
    }
}

// Called when a Pokémon is unable to attack during a Battle Palace battle.
// Check if it was because they are frozen/asleep, and if so try to cure the status.
u32 BattlePalace_TryEscapeStatus(u8 battlerId)
{
    u32 effect = 0;

    do
    {
        switch (gBattleCommunication[MULTIUSE_STATE])
        {
        case 0:
            if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
            {
                if (UproarWakeUpCheck(battlerId))
                {
                    // Wake up from Uproar
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u32 toSub;

                    if (gBattleMons[battlerId].ability == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;

                    // Reduce number of sleep turns
                    if ((gBattleMons[battlerId].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    else
                        gBattleMons[battlerId].status1 -= toSub;

                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        // Still asleep
                        gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                        effect = 2;
                    }
                    else
                    {
                        // Wake up
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        BattleScriptPushCursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            break;
        case 1:
            if (gBattleMons[battlerId].status1 & STATUS1_FREEZE)
            {
                if (Random() % 5 != 0)
                {
                    // Still frozen
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                }
                else
                {
                    // Unfreeze
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
                }
                effect = 2;
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            break;
        case 2:
            break;
        }
        // Loop until reaching the final state, or stop early if Pokémon was Asleep/Frozen
    } while (gBattleCommunication[MULTIUSE_STATE] != 2 && effect == 0);

    if (effect == 2)
    {
        gActiveBattler = battlerId;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }

    return effect;
}

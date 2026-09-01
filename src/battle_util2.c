#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "malloc.h"
#include "pokemon.h"
#include "trainer_hill.h"
#include "trainer_tower.h"
#include "party_menu.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "random.h"
#include "battle_scripts.h"
#include "window.h"
#include "constants/battle_string_ids.h"

void AllocateBattleGfxResources(void)
{
    gBattleAnimBgTileBuffer = AllocZeroed(0x2000);
    gBattleAnimBgTilemapBuffer = AllocZeroed(0x1000);
}

static void FreeBattleGfxResources(void)
{
    FREE_AND_SET_NULL(gBattleAnimBgTileBuffer);
    FREE_AND_SET_NULL(gBattleAnimBgTilemapBuffer);
}

void CloseMainBattleScreen(void)
{
    FreeBattleGfxResources();
    FreeAllWindowBuffers();
}

void AllocateBattleResources(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        InitTrainerTowerBattleStruct();
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        InitTrainerHillBattleStruct();

    gBattleStruct = AllocZeroed(sizeof(*gBattleStruct));
    gAiBattleData = AllocZeroed(sizeof(*gAiBattleData));
    gAiThinkingStruct = AllocZeroed(sizeof(*gAiThinkingStruct));
    gAiLogicData = AllocZeroed(sizeof(*gAiLogicData));
    gAiPartyData = AllocZeroed(sizeof(*gAiPartyData));
    gBattleHistory = AllocZeroed(sizeof(*gBattleHistory));

#if B_FLAG_SKY_BATTLE
    gBattleStruct->isSkyBattle = FlagGet(B_FLAG_SKY_BATTLE);
#endif

    gBattleResources = AllocZeroed(sizeof(*gBattleResources));
    gBattleResources->secretBase = AllocZeroed(sizeof(*gBattleResources->secretBase));
    gBattleResources->battleScriptsStack = AllocZeroed(sizeof(*gBattleResources->battleScriptsStack));
    gBattleResources->battleCallbackStack = AllocZeroed(sizeof(*gBattleResources->battleCallbackStack));
    gBattleResources->beforeLvlUp = AllocZeroed(sizeof(*gBattleResources->beforeLvlUp));

    gLinkBattleSendBuffer = AllocZeroed(BATTLE_BUFFER_LINK_SIZE);
    gLinkBattleRecvBuffer = AllocZeroed(BATTLE_BUFFER_LINK_SIZE);

    AllocateBattleGfxResources();

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u16 currSecretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
        CreateSecretBaseEnemyParty(&gSaveBlock1Ptr->secretBases[currSecretBaseId]);
    }
}

void FreeBattleResources(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        FreeTrainerTowerBattleStruct();
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        FreeTrainerHillBattleStruct();

    gFieldTimers.terrain = 0;
    if (gBattleResources != NULL)
    {
        FREE_AND_SET_NULL(gBattleStruct);
        FREE_AND_SET_NULL(gAiBattleData);
        FREE_AND_SET_NULL(gAiThinkingStruct);
        FREE_AND_SET_NULL(gAiLogicData);
        FREE_AND_SET_NULL(gAiPartyData);
        FREE_AND_SET_NULL(gBattleHistory);

        FREE_AND_SET_NULL(gBattleResources->secretBase);
        FREE_AND_SET_NULL(gBattleResources->battleScriptsStack);
        FREE_AND_SET_NULL(gBattleResources->battleCallbackStack);
        FREE_AND_SET_NULL(gBattleResources->beforeLvlUp);
        FREE_AND_SET_NULL(gBattleResources);

        FREE_AND_SET_NULL(gLinkBattleSendBuffer);
        FREE_AND_SET_NULL(gLinkBattleRecvBuffer);

        FreeBattleGfxResources();
    }
}

void AdjustFriendshipOnBattleFaint(enum BattlerId battler)
{
    enum BattlerId opposingBattlerId;

    if (IsDoubleBattle())
    {
        enum BattlerId opposingBattlerId2;

        opposingBattlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        opposingBattlerId2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

        if (gBattleMons[opposingBattlerId2].level > gBattleMons[opposingBattlerId].level)
            opposingBattlerId = opposingBattlerId2;
    }
    else
    {
        opposingBattlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    }

    if (gBattleMons[opposingBattlerId].level - gBattleMons[battler].level > 29)
        AdjustFriendship(GetBattlerMon(battler), FRIENDSHIP_EVENT_FAINT_LARGE);
    else
        AdjustFriendship(GetBattlerMon(battler), FRIENDSHIP_EVENT_FAINT_SMALL);
}

void SwitchPartyOrderInGameMulti(enum BattlerId battler, u8 arg1)
{
    if (IsOnPlayerSide(battler))
    {
        s32 i;
        u8 battlerPartyId = gBattlerPartyIndexes[battler];
        u8 switchInPartyId = arg1;
        enum BattleTrainer trainer = GetBattlerTrainer(battler);

        // In 6v6 multis, the partner party is stored in gParties[B_TRAINER_PARTNER]
        // and uses indexes 0-2, but we still use the combined party order.
        if (IsMultiBattle() == TRUE && !AreMultiPartiesFullTeams() && trainer == B_TRAINER_PARTNER)
        {
            battlerPartyId += MULTI_PARTY_SIZE;
            switchInPartyId += MULTI_PARTY_SIZE;
        }

        for (enum BattlerId battlerId = 0; battlerId < gBattlersCount; battlerId++)
        {
            if (!IsOnPlayerSide(battlerId))
                continue;

            // Don't update battler's orders for party menu if the switching battler and updating battler
            // don't share a party, unless it's a 6v6 multi where player and partner party are temporarily
            // merged for party menu and summary screen viewing
            if (!(IsMultiBattle() == TRUE && !AreMultiPartiesFullTeams()) && !BattlersShareParty(battler, battlerId))
                continue;

            for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
                gBattlePartyCurrentOrder[i] = gBattleStruct->battlerPartyOrders[battlerId][i];

            SwitchPartyMonSlots(GetPartyIdFromBattlePartyId(battlerPartyId), GetPartyIdFromBattlePartyId(switchInPartyId));

            for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
                gBattleStruct->battlerPartyOrders[battlerId][i] = gBattlePartyCurrentOrder[i];
        }
    }
}

// Called when a Pokémon is unable to attack during a Battle Palace battle.
// Check if it was because they are frozen/asleep, and if so try to cure the status.
u32 BattlePalace_TryEscapeStatus(enum BattlerId battler)
{
    u32 effect = 0;

    do
    {
        switch (gBattleCommunication[MULTIUSE_STATE])
        {
        case 0:
            if (gBattleMons[battler].status1 & STATUS1_SLEEP)
            {
                if (UproarWakeUpCheck(battler))
                {
                    // Wake up from Uproar
                    gEffectBattler = battler;
                    gBattleMons[battler].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battler].volatiles.nightmare = FALSE;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
                    BattleScriptCall(BattleScript_MoveUsedWokeUp);
                    effect = 2;
                }
                else
                {
                    u32 toSub;

                    if (GetBattlerAbility(battler) == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;

                    // Reduce number of sleep turns
                    if ((gBattleMons[battler].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[battler].status1 &= ~(STATUS1_SLEEP);
                    else
                        gBattleMons[battler].status1 -= toSub;

                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        // Still asleep
                        gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                        effect = 2;
                    }
                    else
                    {
                        // Wake up
                        gBattleMons[battler].volatiles.nightmare = FALSE;
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                        BattleScriptCall(BattleScript_MoveUsedWokeUp);
                        effect = 2;
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            break;
        case 1:
            if (gBattleMons[battler].status1 & STATUS1_FREEZE)
            {
                if (Random() % (GetConfig(B_FREEZE_TURNS) >= GEN_CHAMPIONS ? 4 : 5) != 0 && GetBattlerPartyState(battler)->freezeTurns < 2)
                {
                    // Still frozen
                    if (GetConfig(B_FREEZE_TURNS) >= GEN_CHAMPIONS)
                        GetBattlerPartyState(battler)->freezeTurns++;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                }
                else
                {
                    // Unfreeze
                    GetBattlerPartyState(battler)->freezeTurns = 0;
                    gBattleMons[battler].status1 &= ~(STATUS1_FREEZE);
                    gBattleScripting.battler = battler;
                    BattleScriptCall(BattleScript_BattlerDefrosted);
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
        BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
        MarkBattlerForControllerExec(battler);
    }

    return effect;
}

struct Pokemon *GetBattlerParty(enum BattlerId battler)
{
    return gParties[GetBattlerTrainer(battler)];
}

struct Pokemon *GetTrainerParty(enum BattleTrainer trainer)
{
    return gParties[trainer];
}

struct Pokemon* GetBattlerMon(enum BattlerId battler)
{
    u32 index = gBattlerPartyIndexes[battler];

    return &GetBattlerParty(battler)[index];
}

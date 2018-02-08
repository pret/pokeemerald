#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "link.h"
#include "task.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "pokemon.h"
#include "constants/species.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "battle_message.h"

extern u8 gBattleBuffersTransferData[0x100];
extern u8 gUnknown_0202428C;
extern u32 gUnknown_02022FF4;
extern u8 gUnknown_0203C7B4;
extern u8 gUnknown_02022D08;
extern u8 gUnknown_02022D09;
extern u8 gUnknown_02022D0A;

extern const struct BattleMove gBattleMoves[];

extern void task00_08081A90(u8 taskId); // cable_club
extern void sub_81B8D64(u8 bank, u8 arg1); // party_menu

// this file's funcionts
static void CreateTasksForSendRecvLinkBuffers(void);
static void InitLinkBtlControllers(void);
static void InitSinglePlayerBtlControllers(void);
static void SetBattlePartyIds(void);
static void Task_HandleSendLinkBuffersData(u8 taskId);
static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId);

void HandleLinkBattleSetup(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if (gLinkVSyncDisabled)
            sub_800B488();
        if (!gReceivedRemoteLinkPlayers)
            OpenLink();
        CreateTask(task00_08081A90, 0);
        CreateTasksForSendRecvLinkBuffers();
    }
}

void SetUpBattleVarsAndBirchZigzagoon(void)
{
    s32 i;

    gBattleMainFunc = nullsub_20;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerControllerFuncs[i] = nullsub_21;
        gBattlerPositions[i] = 0xFF;
        gActionSelectionCursor[i] = 0;
        gMoveSelectionCursor[i] = 0;
    }

    HandleLinkBattleSetup();
    gBattleControllerExecFlags = 0;
    ClearBattleAnimationVars();
    ClearBattleMonForms();
    BattleAI_HandleItemUseBeforeAISetup(0xF);

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        ZeroEnemyPartyMons();
        CreateMon(&gEnemyParty[0], SPECIES_ZIGZAGOON, 2, 32, 0, 0, 0, 0);
        i = 0;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &i);
    }

    gUnknown_02022FF4 = 0;
    gUnknown_0202428C = 0;
}

void sub_8032768(void)
{
    s32 i;
    u8 *data;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        sub_8184DA4(1);
    else
        sub_8184DA4(2);

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_SaveParties();

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        InitLinkBtlControllers();
    else
        InitSinglePlayerBtlControllers();

    SetBattlePartyIds();

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gBattlersCount; i++)
            sub_81B8D64(i, 0);
    }

    for (i = 0; i < sizeof(gBattleStruct->field_1A4); i++)
        *(gBattleStruct->field_1A4 + i) = 0;

    for (i = 0; i < sizeof(gBattleStruct->field_204); i++)
        *(gBattleStruct->field_204 + i) = 0;
}

static void InitSinglePlayerBtlControllers(void)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            gBattlerControllerFuncs[0] = SetControllerToRecordedPlayer;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[2] = SetControllerToPlayerPartner;
            gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[3] = SetControllerToOpponent;
            gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;
        }
        else
        {
            gBattlerControllerFuncs[0] = SetControllerToPlayer;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[2] = SetControllerToPlayerPartner;
            gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[3] = SetControllerToOpponent;
            gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;
        }

        gBattlersCount = 4;

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);

        gBattlerPartyIndexes[0] = 0;
        gBattlerPartyIndexes[1] = 0;
        gBattlerPartyIndexes[2] = 3;
        gBattlerPartyIndexes[3] = 3;
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            gBattlerControllerFuncs[0] = SetControllerToSafari;
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
            gBattlerControllerFuncs[0] = SetControllerToWally;
        else
            gBattlerControllerFuncs[0] = SetControllerToPlayer;

        gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

        gBattlerControllerFuncs[1] = SetControllerToOpponent;
        gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

        gBattlersCount = 2;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
                {
                    gBattleMainFunc = BeginBattleIntro;

                    gBattlerControllerFuncs[0] = SetControllerToRecordedPlayer;
                    gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

                    gBattlerControllerFuncs[1] = SetControllerToRecordedOpponent;
                    gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

                    gBattlersCount = 2;
                }
                else // see how the banks are switched
                {
                    gBattlerControllerFuncs[1] = SetControllerToRecordedPlayer;
                    gBattlerPositions[1] = B_POSITION_PLAYER_LEFT;

                    gBattlerControllerFuncs[0] = SetControllerToRecordedOpponent;
                    gBattlerPositions[0] = B_POSITION_OPPONENT_LEFT;

                    gBattlersCount = 2;
                }
            }
            else
            {
                gBattlerControllerFuncs[0] = SetControllerToRecordedPlayer;
                gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[1] = SetControllerToOpponent;
                gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;
            }
        }
    }
    else
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattlerControllerFuncs[0] = SetControllerToPlayer;
        gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

        gBattlerControllerFuncs[1] = SetControllerToOpponent;
        gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

        gBattlerControllerFuncs[2] = SetControllerToPlayer;
        gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

        gBattlerControllerFuncs[3] = SetControllerToOpponent;
        gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;

        gBattlersCount = 4;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
            {
                gBattleMainFunc = BeginBattleIntro;

                gBattlerControllerFuncs[0] = SetControllerToRecordedPlayer;
                gBattlerPositions[0] = 0;

                gBattlerControllerFuncs[1] = SetControllerToOpponent;
                gBattlerPositions[1] = 1;

                gBattlerControllerFuncs[2] = SetControllerToRecordedPlayer;
                gBattlerPositions[2] = 2;

                gBattlerControllerFuncs[3] = SetControllerToOpponent;
                gBattlerPositions[3] = 3;

                gBattlersCount = 4;

                sub_81B8D64(0, 0);
                sub_81B8D64(1, 0);
                sub_81B8D64(2, 1);
                sub_81B8D64(3, 1);

                gBattlerPartyIndexes[0] = 0;
                gBattlerPartyIndexes[1] = 0;
                gBattlerPartyIndexes[2] = 3;
                gBattlerPartyIndexes[3] = 3;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                u8 var; // multiplayer Id in a recorded battle?

                for (var = gUnknown_0203C7B4, i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        sub_81B8D64(gLinkPlayers[i].lp_field_18, 0);
                        break;
                    case 1:
                    case 2:
                        sub_81B8D64(gLinkPlayers[i].lp_field_18, 1);
                        break;
                    }

                    if (i == var)
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_PLAYER_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_PLAYER_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[var].lp_field_18 & 1))
                            || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[var].lp_field_18 & 1)))
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_PLAYER_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_PLAYER_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedOpponent;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_OPPONENT_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].lp_field_18] = B_POSITION_OPPONENT_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                }
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            {
                gBattlerControllerFuncs[0] = SetControllerToRecordedPlayer;
                gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[2] = SetControllerToRecordedPlayer;
                gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                  gBattlerControllerFuncs[1] = SetControllerToRecordedOpponent;
                  gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

                  gBattlerControllerFuncs[3] = SetControllerToRecordedOpponent;
                  gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;
                }
                else
                {
                  gBattlerControllerFuncs[1] = SetControllerToOpponent;
                  gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

                  gBattlerControllerFuncs[3] = SetControllerToOpponent;
                  gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;
                }
            }
            else
            {
                gBattlerControllerFuncs[1] = SetControllerToRecordedPlayer;
                gBattlerPositions[1] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[3] = SetControllerToRecordedPlayer;
                gBattlerPositions[3] = B_POSITION_PLAYER_RIGHT;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                    gBattlerControllerFuncs[0] = SetControllerToRecordedOpponent;
                    gBattlerPositions[0] = B_POSITION_OPPONENT_LEFT;

                    gBattlerControllerFuncs[2] = SetControllerToRecordedOpponent;
                    gBattlerPositions[2] = B_POSITION_OPPONENT_RIGHT;
                }
                else
                {
                    gBattlerControllerFuncs[0] = SetControllerToOpponent;
                    gBattlerPositions[0] = B_POSITION_OPPONENT_LEFT;

                    gBattlerControllerFuncs[2] = SetControllerToOpponent;
                    gBattlerPositions[2] = B_POSITION_OPPONENT_RIGHT;
                }
            }
        }
    }
}

static void InitLinkBtlControllers(void)
{
    s32 i;
    u8 multiplayerId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[0] = SetControllerToPlayer;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToLinkOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlersCount = 2;
        }
        else
        {
            gBattlerControllerFuncs[1] = SetControllerToPlayer;
            gBattlerPositions[1] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[0] = SetControllerToLinkOpponent;
            gBattlerPositions[0] = B_POSITION_OPPONENT_LEFT;

            gBattlersCount = 2;
        }
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[0] = SetControllerToPlayer;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToLinkOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[2] = SetControllerToPlayer;
            gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[3] = SetControllerToLinkOpponent;
            gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = 4;
        }
        else
        {
            gBattlerControllerFuncs[1] = SetControllerToPlayer;
            gBattlerPositions[1] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[0] = SetControllerToLinkOpponent;
            gBattlerPositions[0] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[3] = SetControllerToPlayer;
            gBattlerPositions[3] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[2] = SetControllerToLinkOpponent;
            gBattlerPositions[2] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = 4;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[0] = SetControllerToPlayer;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[2] = SetControllerToLinkPartner;
            gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[3] = SetControllerToOpponent;
            gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = 4;
        }
        else
        {
            gBattlerControllerFuncs[0] = SetControllerToLinkPartner;
            gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[1] = SetControllerToLinkOpponent;
            gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[2] = SetControllerToPlayer;
            gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[3] = SetControllerToLinkOpponent;
            gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = 4;
        }

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);
        gBattlerPartyIndexes[0] = 0;
        gBattlerPartyIndexes[1] = 0;
        gBattlerPartyIndexes[2] = 3;
        gBattlerPartyIndexes[3] = 3;
    }
    else
    {
        multiplayerId = GetMultiplayerId();

        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            gBattleMainFunc = BeginBattleIntro;

        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            switch (gLinkPlayers[i].lp_field_18)
            {
            case 0:
            case 3:
                sub_81B8D64(gLinkPlayers[i].lp_field_18, 0);
                break;
            case 1:
            case 2:
                sub_81B8D64(gLinkPlayers[i].lp_field_18, 1);
                break;
            }

            if (i == multiplayerId)
            {
                gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToPlayer;
                switch (gLinkPlayers[i].lp_field_18)
                {
                case 0:
                case 3:
                    gBattlerPositions[gLinkPlayers[i].lp_field_18] = 0;
                    gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                    break;
                case 1:
                case 2:
                    gBattlerPositions[gLinkPlayers[i].lp_field_18] = 2;
                    gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                    break;
                }
            }
            else
            {
                if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[multiplayerId].lp_field_18 & 1))
                 || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[multiplayerId].lp_field_18 & 1)))
                {
                    gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToLinkPartner;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBattlerPositions[gLinkPlayers[i].lp_field_18] = 0;
                        gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBattlerPositions[gLinkPlayers[i].lp_field_18] = 2;
                        gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
                else
                {
                    gBattlerControllerFuncs[gLinkPlayers[i].lp_field_18] = SetControllerToLinkOpponent;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBattlerPositions[gLinkPlayers[i].lp_field_18] = 1;
                        gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBattlerPositions[gLinkPlayers[i].lp_field_18] = 3;
                        gBattlerPartyIndexes[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
            }
        }

        gBattlersCount = 4;
    }
}

static void SetBattlePartyIds(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gBattlersCount; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (i < 2)
                {
                    if (GET_BATTLER_SIDE2(i) == B_SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG) == 0)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                }
                else
                {
                    if (GET_BATTLER_SIDE2(i) == B_SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) != SPECIES_NONE  // Probably a typo by Game Freak. The rest use SPECIES2.
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlerPartyIndexes[i - 2] != j)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlerPartyIndexes[i - 2] != j)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                }
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            gBattlerPartyIndexes[1] = 0, gBattlerPartyIndexes[3] = 3;
    }
}

static void PrepareBufferDataTransfer(u8 bufferId, u8 *data, u16 size)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        PrepareBufferDataTransferLink(bufferId, size, data);
    }
    else
    {
        switch (bufferId)
        {
        case 0:
            for (i = 0; i < size; i++)
            {
                gBattleBufferA[gActiveBattler][i] = *data;
                data++;
            }
            break;
        case 1:
            for (i = 0; i < size; i++)
            {
                gBattleBufferB[gActiveBattler][i] = *data;
                data++;
            }
            break;
        }
    }
}

static void CreateTasksForSendRecvLinkBuffers(void)
{
    gUnknown_02022D08 = CreateTask(Task_HandleSendLinkBuffersData, 0);
    gTasks[gUnknown_02022D08].data[11] = 0;
    gTasks[gUnknown_02022D08].data[12] = 0;
    gTasks[gUnknown_02022D08].data[13] = 0;
    gTasks[gUnknown_02022D08].data[14] = 0;
    gTasks[gUnknown_02022D08].data[15] = 0;

    gUnknown_02022D09 = CreateTask(Task_HandleCopyReceivedLinkBuffersData, 0);
    gTasks[gUnknown_02022D09].data[12] = 0;
    gTasks[gUnknown_02022D09].data[13] = 0;
    gTasks[gUnknown_02022D09].data[14] = 0;
    gTasks[gUnknown_02022D09].data[15] = 0;

    gUnknown_02022D0A = 0;
}

enum
{
    LINK_BUFF_BUFFER_ID,
    LINK_BUFF_ACTIVE_BANK,
    LINK_BUFF_ATTACKER,
    LINK_BUFF_TARGET,
    LINK_BUFF_SIZE_LO,
    LINK_BUFF_SIZE_HI,
    LINK_BUFF_ABSENT_BANK_FLAGS,
    LINK_BUFF_EFFECT_BANK,
    LINK_BUFF_DATA
};

void PrepareBufferDataTransferLink(u8 bufferId, u16 size, u8 *data)
{
    s32 alignedSize;
    s32 i;

    alignedSize = size - size % 4 + 4;
    if (gTasks[gUnknown_02022D08].data[14] + alignedSize + LINK_BUFF_DATA + 1 > BATTLE_BUFFER_LINK_SIZE)
    {
        gTasks[gUnknown_02022D08].data[12] = gTasks[gUnknown_02022D08].data[14];
        gTasks[gUnknown_02022D08].data[14] = 0;
    }
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_BUFFER_ID] = bufferId;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ACTIVE_BANK] = gActiveBattler;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ATTACKER] = gBattlerAttacker;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_TARGET] = gBattlerTarget;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_LO] = alignedSize;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_HI] = (alignedSize & 0x0000FF00) >> 8;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ABSENT_BANK_FLAGS] = gAbsentBattlerFlags;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_EFFECT_BANK] = gEffectBattler;

    for (i = 0; i < size; i++)
        gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_DATA + i] = data[i];

    gTasks[gUnknown_02022D08].data[14] = gTasks[gUnknown_02022D08].data[14] + alignedSize + LINK_BUFF_DATA;
}

static void Task_HandleSendLinkBuffersData(u8 taskId)
{
    u16 var;
    u16 blockSize;

    switch (gTasks[taskId].data[11])
    {
    case 0:
        gTasks[taskId].data[10] = 100;
        gTasks[taskId].data[11]++;
        break;
    case 1:
        gTasks[taskId].data[10]--;
        if (gTasks[taskId].data[10] == 0)
            gTasks[taskId].data[11]++;
        break;
    case 2:
        if (gLinkVSyncDisabled)
        {
            gTasks[taskId].data[11]++;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                var = 2;
            else
                var = (gBattleTypeFlags & BATTLE_TYPE_MULTI) ? 4 : 2;

            if (GetLinkPlayerCount_2() >= var)
            {
                if (IsLinkMaster())
                {
                    sub_800A620();
                    gTasks[taskId].data[11]++;
                }
                else
                {
                    gTasks[taskId].data[11]++;
                }
            }
        }
        break;
    case 3:
        if (gTasks[taskId].data[15] != gTasks[taskId].data[14])
        {
            if (gTasks[taskId].data[13] == 0)
            {
                if (gTasks[taskId].data[15] > gTasks[taskId].data[14]
                 && gTasks[taskId].data[15] == gTasks[taskId].data[12])
                {
                    gTasks[taskId].data[12] = 0;
                    gTasks[taskId].data[15] = 0;
                }
                blockSize = (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8)) + LINK_BUFF_DATA;
                SendBlock(bitmask_all_link_players_but_self(), &gLinkBattleSendBuffer[gTasks[taskId].data[15]], blockSize);
                gTasks[taskId].data[11]++;
            }
            else
            {
                gTasks[taskId].data[13]--;
                break;
            }
        }
        break;
    case 4:
        if (sub_800A520())
        {
            blockSize = gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8);
            gTasks[taskId].data[13] = 1;
            gTasks[taskId].data[15] = gTasks[taskId].data[15] + blockSize + LINK_BUFF_DATA;
            gTasks[taskId].data[11] = 3;
        }
        break;
    case 5:
        gTasks[taskId].data[13]--;
        if (gTasks[taskId].data[13] == 0)
        {
            gTasks[taskId].data[13] = 1;
            gTasks[taskId].data[11] = 3;
        }
        break;
    }
}

// fix me
void sub_8033648(void)
{
    u8 i;
    s32 j;
    u16 r6;
    u8 *recvBuffer;
    u8 *dest;
    u8 *src;

    if (gReceivedRemoteLinkPlayers != 0 && (gBattleTypeFlags & BATTLE_TYPE_20))
    {
        sub_8011BD0();
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (GetBlockReceivedStatus() & gBitTable[i])
            {
                ResetBlockReceivedFlag(i);
                recvBuffer = (u8 *)gBlockRecvBuffer[i];
                #ifndef NONMATCHING
                    asm("");
                    recvBuffer = (u8 *)&gBlockRecvBuffer[i];
                #endif
                r6 = gBlockRecvBuffer[i][2];

                if (gTasks[gUnknown_02022D09].data[14] + 9 + r6 > 0x1000)
                {
                    gTasks[gUnknown_02022D09].data[12] = gTasks[gUnknown_02022D09].data[14];
                    gTasks[gUnknown_02022D09].data[14] = 0;
                }

                dest = &gLinkBattleRecvBuffer[gTasks[gUnknown_02022D09].data[14]];
                src = recvBuffer;

                for (j = 0; j < r6 + 8; j++)
                    dest[j] = src[j];

                gTasks[gUnknown_02022D09].data[14] = gTasks[gUnknown_02022D09].data[14] + r6 + 8;
            }
        }
    }
}

static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId)
{
    u16 blockSize;
    u8 bank;
    u8 var;

    if (gTasks[taskId].data[15] != gTasks[taskId].data[14])
    {
        if (gTasks[taskId].data[15] > gTasks[taskId].data[14]
         && gTasks[taskId].data[15] == gTasks[taskId].data[12])
        {
            gTasks[taskId].data[12] = 0;
            gTasks[taskId].data[15] = 0;
        }
        bank = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_ACTIVE_BANK];
        blockSize = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8);

        switch (gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 0])
        {
        case 0:
            if (gBattleControllerExecFlags & gBitTable[bank])
                return;

            memcpy(gBattleBufferA[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            sub_803F850(bank);

            if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
            {
                gBattlerAttacker = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 2];
                gBattlerTarget = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 3];
                gAbsentBattlerFlags = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 6];
                gEffectBattler = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 7];
            }
            break;
        case 1:
            memcpy(gBattleBufferB[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            break;
        case 2:
            var = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_DATA];
            gBattleControllerExecFlags &= ~(gBitTable[bank] << (var * 4));
            break;
        }

        gTasks[taskId].data[15] = gTasks[taskId].data[15] + blockSize + LINK_BUFF_DATA;
    }
}

void BtlController_EmitGetMonData(u8 bufferId, u8 requestId, u8 monToCheck)
{
    gBattleBuffersTransferData[0] = CONTROLLER_GETMONDATA;
    gBattleBuffersTransferData[1] = requestId;
    gBattleBuffersTransferData[2] = monToCheck;
    gBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitGetRawMonData(u8 bufferId, u8 monId, u8 bytes)
{
    gBattleBuffersTransferData[0] = CONTROLLER_GETRAWMONDATA;
    gBattleBuffersTransferData[1] = monId;
    gBattleBuffersTransferData[2] = bytes;
    gBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitSetMonData(u8 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_SETMONDATA;
    gBattleBuffersTransferData[1] = requestId;
    gBattleBuffersTransferData[2] = monToCheck;
    for (i = 0; i < bytes; i++)
        gBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 3 + bytes);
}

void BtlController_EmitSetRawMonData(u8 bufferId, u8 monId, u8 bytes, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_SETRAWMONDATA;
    gBattleBuffersTransferData[1] = monId;
    gBattleBuffersTransferData[2] = bytes;
    for (i = 0; i < bytes; i++)
        gBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, bytes + 3);
}

void BtlController_EmitLoadMonSprite(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_LOADMONSPRITE;
    gBattleBuffersTransferData[1] = CONTROLLER_LOADMONSPRITE;
    gBattleBuffersTransferData[2] = CONTROLLER_LOADMONSPRITE;
    gBattleBuffersTransferData[3] = CONTROLLER_LOADMONSPRITE;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit)
{
    gBattleBuffersTransferData[0] = CONTROLLER_SWITCHINANIM;
    gBattleBuffersTransferData[1] = partyId;
    gBattleBuffersTransferData[2] = dontClearSubstituteBit;
    gBattleBuffersTransferData[3] = 5;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitReturnMonToBall(u8 bufferId, u8 arg1)
{
    gBattleBuffersTransferData[0] = CONTROLLER_RETURNMONTOBALL;
    gBattleBuffersTransferData[1] = arg1;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitDrawTrainerPic(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_DRAWTRAINERPIC;
    gBattleBuffersTransferData[1] = CONTROLLER_DRAWTRAINERPIC;
    gBattleBuffersTransferData[2] = CONTROLLER_DRAWTRAINERPIC;
    gBattleBuffersTransferData[3] = CONTROLLER_DRAWTRAINERPIC;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitTrainerSlide(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_TRAINERSLIDE;
    gBattleBuffersTransferData[1] = CONTROLLER_TRAINERSLIDE;
    gBattleBuffersTransferData[2] = CONTROLLER_TRAINERSLIDE;
    gBattleBuffersTransferData[3] = CONTROLLER_TRAINERSLIDE;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitTrainerSlideBack(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleBuffersTransferData[1] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleBuffersTransferData[2] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleBuffersTransferData[3] = CONTROLLER_TRAINERSLIDEBACK;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitFaintAnimation(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_FAINTANIMATION;
    gBattleBuffersTransferData[1] = CONTROLLER_FAINTANIMATION;
    gBattleBuffersTransferData[2] = CONTROLLER_FAINTANIMATION;
    gBattleBuffersTransferData[3] = CONTROLLER_FAINTANIMATION;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitPaletteFade(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_PALETTEFADE;
    gBattleBuffersTransferData[1] = CONTROLLER_PALETTEFADE;
    gBattleBuffersTransferData[2] = CONTROLLER_PALETTEFADE;
    gBattleBuffersTransferData[3] = CONTROLLER_PALETTEFADE;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitSuccessBallThrowAnim(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_SUCCESSBALLTHROWANIM;
    gBattleBuffersTransferData[1] = CONTROLLER_SUCCESSBALLTHROWANIM;
    gBattleBuffersTransferData[2] = CONTROLLER_SUCCESSBALLTHROWANIM;
    gBattleBuffersTransferData[3] = CONTROLLER_SUCCESSBALLTHROWANIM;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitBallThrowAnim(u8 bufferId, u8 caseId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_BALLTHROWANIM;
    gBattleBuffersTransferData[1] = caseId;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitPause(u8 bufferId, u8 toWait, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_PAUSE;
    gBattleBuffersTransferData[1] = toWait;
    for (i = 0; i < toWait * 3; i++)
        gBattleBuffersTransferData[2 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, toWait * 3 + 2);
}

void BtlController_EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit)
{
    gBattleBuffersTransferData[0] = CONTROLLER_MOVEANIMATION;
    gBattleBuffersTransferData[1] = move;
    gBattleBuffersTransferData[2] = (move & 0xFF00) >> 8;
    gBattleBuffersTransferData[3] = turnOfMove;
    gBattleBuffersTransferData[4] = movePower;
    gBattleBuffersTransferData[5] = (movePower & 0xFF00) >> 8;
    gBattleBuffersTransferData[6] = dmg;
    gBattleBuffersTransferData[7] = (dmg & 0x0000FF00) >> 8;
    gBattleBuffersTransferData[8] = (dmg & 0x00FF0000) >> 16;
    gBattleBuffersTransferData[9] = (dmg & 0xFF000000) >> 24;
    gBattleBuffersTransferData[10] = friendship;
    gBattleBuffersTransferData[11] = multihit;
    if (WEATHER_HAS_EFFECT2)
    {
        gBattleBuffersTransferData[12] = gBattleWeather;
        gBattleBuffersTransferData[13] = (gBattleWeather & 0xFF00) >> 8;
    }
    else
    {
        gBattleBuffersTransferData[12] = 0;
        gBattleBuffersTransferData[13] = 0;
    }
    gBattleBuffersTransferData[14] = 0;
    gBattleBuffersTransferData[15] = 0;
    memcpy(&gBattleBuffersTransferData[16], disableStructPtr, sizeof(struct DisableStruct));
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 16 + sizeof(struct DisableStruct));
}

void BtlController_EmitPrintString(u8 bufferId, u16 stringID)
{
    s32 i;
    struct StringInfoBattle* stringInfo;

    gBattleBuffersTransferData[0] = CONTROLLER_PRINTSTRING;
    gBattleBuffersTransferData[1] = gBattleOutcome;
    gBattleBuffersTransferData[2] = stringID;
    gBattleBuffersTransferData[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct StringInfoBattle*)(&gBattleBuffersTransferData[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.battler;
    stringInfo->unk1605E = gBattleStruct->field_52;
    stringInfo->hpScale = gBattleStruct->hpScale;
    stringInfo->StringBank = gStringBattler;
    stringInfo->moveType = gBattleMoves[gCurrentMove].type;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, sizeof(struct StringInfoBattle) + 4);
}

void BtlController_EmitPrintSelectionString(u8 bufferId, u16 stringID)
{
    s32 i;
    struct StringInfoBattle *stringInfo;

    gBattleBuffersTransferData[0] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    gBattleBuffersTransferData[1] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    gBattleBuffersTransferData[2] = stringID;
    gBattleBuffersTransferData[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct StringInfoBattle*)(&gBattleBuffersTransferData[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.battler;
    stringInfo->unk1605E = gBattleStruct->field_52;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, sizeof(struct StringInfoBattle) + 4);
}

void BtlController_EmitChooseAction(u8 bufferId, u8 arg1, u16 arg2)
{
    gBattleBuffersTransferData[0] = CONTROLLER_CHOOSEACTION;
    gBattleBuffersTransferData[1] = arg1;
    gBattleBuffersTransferData[2] = arg2;
    gBattleBuffersTransferData[3] = (arg2 & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitUnknownYesNoBox(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_UNKNOWNYESNOBOX;
    gBattleBuffersTransferData[1] = CONTROLLER_UNKNOWNYESNOBOX;
    gBattleBuffersTransferData[2] = CONTROLLER_UNKNOWNYESNOBOX;
    gBattleBuffersTransferData[3] = CONTROLLER_UNKNOWNYESNOBOX;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitChooseMove(u8 bufferId, bool8 isDoubleBattle, bool8 NoPpNumber, struct ChooseMoveStruct *movePpData)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_CHOOSEMOVE;
    gBattleBuffersTransferData[1] = isDoubleBattle;
    gBattleBuffersTransferData[2] = NoPpNumber;
    gBattleBuffersTransferData[3] = 0;
    for (i = 0; i < sizeof(*movePpData); i++)
        gBattleBuffersTransferData[4 + i] = *((u8*)(movePpData) + i);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, sizeof(*movePpData) + 4);
}

void BtlController_EmitChooseItem(u8 bufferId, u8 *arg1)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_OPENBAG;
    for (i = 0; i < 3; i++)
        gBattleBuffersTransferData[1 + i] = arg1[i];
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, u8* arg4)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_CHOOSEPOKEMON;
    gBattleBuffersTransferData[1] = caseId;
    gBattleBuffersTransferData[2] = arg2;
    gBattleBuffersTransferData[3] = abilityId;
    for (i = 0; i < 3; i++)
        gBattleBuffersTransferData[4 + i] = arg4[i];
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 8);  // but only 7 bytes were written
}

void BtlController_EmitCmd23(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_23;
    gBattleBuffersTransferData[1] = CONTROLLER_23;
    gBattleBuffersTransferData[2] = CONTROLLER_23;
    gBattleBuffersTransferData[3] = CONTROLLER_23;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

// why is the argument u16 if it's being cast to s16 anyway?
void BtlController_EmitHealthBarUpdate(u8 bufferId, u16 hpValue)
{
    gBattleBuffersTransferData[0] = CONTROLLER_HEALTHBARUPDATE;
    gBattleBuffersTransferData[1] = 0;
    gBattleBuffersTransferData[2] = (s16)hpValue;
    gBattleBuffersTransferData[3] = ((s16)hpValue & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

// why is the argument u16 if it's being cast to s16 anyway?
void BtlController_EmitExpUpdate(u8 bufferId, u8 partyId, u16 expPoints)
{
    gBattleBuffersTransferData[0] = CONTROLLER_EXPUPDATE;
    gBattleBuffersTransferData[1] = partyId;
    gBattleBuffersTransferData[2] = (s16)expPoints;
    gBattleBuffersTransferData[3] = ((s16)expPoints & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitStatusIconUpdate(u8 bufferId, u32 status1, u32 status2)
{
    gBattleBuffersTransferData[0] = CONTROLLER_STATUSICONUPDATE;
    gBattleBuffersTransferData[1] = status1;
    gBattleBuffersTransferData[2] = (status1 & 0x0000FF00) >> 8;
    gBattleBuffersTransferData[3] = (status1 & 0x00FF0000) >> 16;
    gBattleBuffersTransferData[4] = (status1 & 0xFF000000) >> 24;
    gBattleBuffersTransferData[5] = status2;
    gBattleBuffersTransferData[6] = (status2 & 0x0000FF00) >> 8;
    gBattleBuffersTransferData[7] = (status2 & 0x00FF0000) >> 16;
    gBattleBuffersTransferData[8] = (status2 & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 9);
}

void BtlController_EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status)
{
    gBattleBuffersTransferData[0] = CONTROLLER_STATUSANIMATION;
    gBattleBuffersTransferData[1] = status2;
    gBattleBuffersTransferData[2] = status;
    gBattleBuffersTransferData[3] = (status & 0x0000FF00) >> 8;
    gBattleBuffersTransferData[4] = (status & 0x00FF0000) >> 16;
    gBattleBuffersTransferData[5] = (status & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 6);
}

void BtlController_EmitStatusXor(u8 bufferId, u8 b)
{
    gBattleBuffersTransferData[0] = CONTROLLER_STATUSXOR;
    gBattleBuffersTransferData[1] = b;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitDataTransfer(u8 bufferId, u16 size, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_DATATRANSFER;
    gBattleBuffersTransferData[1] = CONTROLLER_DATATRANSFER;
    gBattleBuffersTransferData[2] = size;
    gBattleBuffersTransferData[3] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleBuffersTransferData[4 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, size + 4);
}

void BtlController_EmitDMA3Transfer(u8 bufferId, void *dst, u16 size, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_DMA3TRANSFER;
    gBattleBuffersTransferData[1] = (u32)(dst);
    gBattleBuffersTransferData[2] = ((u32)(dst) & 0x0000FF00) >> 8;
    gBattleBuffersTransferData[3] = ((u32)(dst) & 0x00FF0000) >> 16;
    gBattleBuffersTransferData[4] = ((u32)(dst) & 0xFF000000) >> 24;
    gBattleBuffersTransferData[5] = size;
    gBattleBuffersTransferData[6] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleBuffersTransferData[7 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, size + 7);
}

void BtlController_EmitPlayBGM(u8 bufferId, u16 songId, void *unusedDumbDataParameter)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_31;
    gBattleBuffersTransferData[1] = songId;
    gBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    for (i = 0; i < songId; i++) // ????
        gBattleBuffersTransferData[3 + i] = *(u8*)(unusedDumbDataParameter++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, songId + 3);
}

void BtlController_EmitCmd32(u8 bufferId, u16 size, void *data)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_32;
    gBattleBuffersTransferData[1] = size;
    gBattleBuffersTransferData[2] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, size + 3);
}

void BtlController_EmitTwoReturnValues(u8 bufferId, u8 arg1, u16 arg2)
{
    gBattleBuffersTransferData[0] = CONTROLLER_TWORETURNVALUES;
    gBattleBuffersTransferData[1] = arg1;
    gBattleBuffersTransferData[2] = arg2;
    gBattleBuffersTransferData[3] = (arg2 & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitChosenMonReturnValue(u8 bufferId, u8 b, u8 *c)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_CHOSENMONRETURNVALUE;
    gBattleBuffersTransferData[1] = b;
    for (i = 0; i < 3; i++)
        gBattleBuffersTransferData[2 + i] = c[i];
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 5);
}

void BtlController_EmitOneReturnValue(u8 bufferId, u16 arg1)
{
    gBattleBuffersTransferData[0] = CONTROLLER_ONERETURNVALUE;
    gBattleBuffersTransferData[1] = arg1;
    gBattleBuffersTransferData[2] = (arg1 & 0xFF00) >> 8;
    gBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitOneReturnValue_Duplicate(u8 bufferId, u16 b)
{
    gBattleBuffersTransferData[0] = CONTROLLER_ONERETURNVALUE_DUPLICATE;
    gBattleBuffersTransferData[1] = b;
    gBattleBuffersTransferData[2] = (b & 0xFF00) >> 8;
    gBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitCmd37(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_37;
    gBattleBuffersTransferData[1] = CONTROLLER_37;
    gBattleBuffersTransferData[2] = CONTROLLER_37;
    gBattleBuffersTransferData[3] = CONTROLLER_37;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitCmd38(u8 bufferId, u8 b)
{
    gBattleBuffersTransferData[0] = CONTROLLER_38;
    gBattleBuffersTransferData[1] = b;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitCmd39(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_39;
    gBattleBuffersTransferData[1] = CONTROLLER_39;
    gBattleBuffersTransferData[2] = CONTROLLER_39;
    gBattleBuffersTransferData[3] = CONTROLLER_39;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitCmd40(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_40;
    gBattleBuffersTransferData[1] = CONTROLLER_40;
    gBattleBuffersTransferData[2] = CONTROLLER_40;
    gBattleBuffersTransferData[3] = CONTROLLER_40;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitHitAnimation(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_HITANIMATION;
    gBattleBuffersTransferData[1] = CONTROLLER_HITANIMATION;
    gBattleBuffersTransferData[2] = CONTROLLER_HITANIMATION;
    gBattleBuffersTransferData[3] = CONTROLLER_HITANIMATION;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitCmd42(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_42;
    gBattleBuffersTransferData[1] = CONTROLLER_42;
    gBattleBuffersTransferData[2] = CONTROLLER_42;
    gBattleBuffersTransferData[3] = CONTROLLER_42;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitPlaySE(u8 bufferId, u16 songId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_EFFECTIVENESSSOUND;
    gBattleBuffersTransferData[1] = songId;
    gBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    gBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitPlayFanfareOrBGM(u8 bufferId, u16 songId, bool8 playBGM)
{
    gBattleBuffersTransferData[0] = CONTROLLER_PLAYFANFAREORBGM;
    gBattleBuffersTransferData[1] = songId;
    gBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    gBattleBuffersTransferData[3] = playBGM;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitFaintingCry(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_FAINTINGCRY;
    gBattleBuffersTransferData[1] = CONTROLLER_FAINTINGCRY;
    gBattleBuffersTransferData[2] = CONTROLLER_FAINTINGCRY;
    gBattleBuffersTransferData[3] = CONTROLLER_FAINTINGCRY;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitIntroSlide(u8 bufferId, u8 terrainId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_INTROSLIDE;
    gBattleBuffersTransferData[1] = terrainId;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitIntroTrainerBallThrow(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleBuffersTransferData[1] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleBuffersTransferData[2] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleBuffersTransferData[3] = CONTROLLER_INTROTRAINERBALLTHROW;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitDrawPartyStatusSummary(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2)
{
    s32 i;

    gBattleBuffersTransferData[0] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    gBattleBuffersTransferData[1] = arg2 & 0x7F;
    gBattleBuffersTransferData[2] = (arg2 & 0x80) >> 7;
    gBattleBuffersTransferData[3] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    for (i = 0; i < (s32)(sizeof(struct HpAndStatus) * 6); i++)
        gBattleBuffersTransferData[4 + i] = *(i + (u8*)(hpAndStatus));
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, sizeof(struct HpAndStatus) * 6 + 4);
}

void BtlController_EmitCmd49(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_49;
    gBattleBuffersTransferData[1] = CONTROLLER_49;
    gBattleBuffersTransferData[2] = CONTROLLER_49;
    gBattleBuffersTransferData[3] = CONTROLLER_49;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitCmd50(u8 bufferId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_50;
    gBattleBuffersTransferData[1] = CONTROLLER_50;
    gBattleBuffersTransferData[2] = CONTROLLER_50;
    gBattleBuffersTransferData[3] = CONTROLLER_50;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitSpriteInvisibility(u8 bufferId, bool8 isInvisible)
{
    gBattleBuffersTransferData[0] = CONTROLLER_SPRITEINVISIBILITY;
    gBattleBuffersTransferData[1] = isInvisible;
    gBattleBuffersTransferData[2] = CONTROLLER_SPRITEINVISIBILITY;
    gBattleBuffersTransferData[3] = CONTROLLER_SPRITEINVISIBILITY;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitBattleAnimation(u8 bufferId, u8 animationId, u16 argument)
{
    gBattleBuffersTransferData[0] = CONTROLLER_BATTLEANIMATION;
    gBattleBuffersTransferData[1] = animationId;
    gBattleBuffersTransferData[2] = argument;
    gBattleBuffersTransferData[3] = (argument & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 4);
}

void BtlController_EmitLinkStandbyMsg(u8 bufferId, u8 arg1, bool32 arg2)
{
    bool8 arg2_ = arg2;
    gBattleBuffersTransferData[0] = CONTROLLER_LINKSTANDBYMSG;
    gBattleBuffersTransferData[1] = arg1;

    if (arg2_)
        gBattleBuffersTransferData[3] = gBattleBuffersTransferData[2] = sub_81850DC(&gBattleBuffersTransferData[4]);
    else
        gBattleBuffersTransferData[3] = gBattleBuffersTransferData[2] = 0;

    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, gBattleBuffersTransferData[2] + 4);
}

void BtlController_EmitResetActionMoveSelection(u8 bufferId, u8 caseId)
{
    gBattleBuffersTransferData[0] = CONTROLLER_RESETACTIONMOVESELECTION;
    gBattleBuffersTransferData[1] = caseId;
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, 2);
}

void BtlController_EmitCmd55(u8 bufferId, u8 arg1)
{
    gBattleBuffersTransferData[0] = CONTROLLER_55;
    gBattleBuffersTransferData[1] = arg1;
    gBattleBuffersTransferData[2] = gSaveBlock2Ptr->field_CA9_b;
    gBattleBuffersTransferData[3] = gSaveBlock2Ptr->field_CA9_b;
    gBattleBuffersTransferData[5] = gBattleBuffersTransferData[4] = sub_81850DC(&gBattleBuffersTransferData[6]);
    PrepareBufferDataTransfer(bufferId, gBattleBuffersTransferData, gBattleBuffersTransferData[4] + 6);
}

#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "link.h"
#include "task.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "pokemon.h"
#include "species.h"
#include "recorded_battle.h"
#include "util.h"

extern u32 gBattleTypeFlags;
extern u32 gBattleExecBuffer;
extern void (*gBattleMainFunc)(void);
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern u8 gBanksByIdentity[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern u8 gActiveBank;
extern u8 gUnknown_0202428C;
extern u32 gUnknown_02022FF4;
extern u8 gUnknown_0203C7B4;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gUnknown_02022D08;
extern u8 gUnknown_02022D09;
extern u8 gUnknown_02022D0A;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gEffectBank;

extern void task00_08081A90(u8 taskId); // cable_club
extern void sub_81B8D64(u8 bank, u8 arg1); // party_menu

// this file's funcionts
static void sub_8033244(void);
static void SetControllersVariablesInLinkBattle(void);
static void SetControllersVariables(void);
static void sub_8033050(void);
void PrepareBufferDataTransferLink(u8 bufferId, u16 size, u8 *data);
static void Task_HandleSendLinkBuffersData(u8 taskId);
static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId);

void HandleLinkBattleSetup(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if (gLinkVSyncDisabled)
            sub_800B488();
        if (!gReceivedRemoteLinkPlayers)
            sub_8009734();
        CreateTask(task00_08081A90, 0);
        sub_8033244();
    }
}

void SetUpBattleVarsAndBirchZigzagoon(void)
{
    s32 i;

    gBattleMainFunc = nullsub_20;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        gBattleBankFunc[i] = nullsub_21;
        gBanksByIdentity[i] = 0xFF;
        gActionSelectionCursor[i] = 0;
        gMoveSelectionCursor[i] = 0;
    }

    HandleLinkBattleSetup();
    gBattleExecBuffer = 0;
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
        sub_8185EB8();

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        SetControllersVariablesInLinkBattle();
    else
        SetControllersVariables();

    sub_8033050();

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gNoOfAllBanks; i++)
            sub_81B8D64(i, 0);
    }

    for (i = 0; i < sizeof(gBattleStruct->field_1A4); i++)
        *(gBattleStruct->field_1A4 + i) = 0;

    for (i = 0; i < sizeof(gBattleStruct->field_204); i++)
        *(gBattleStruct->field_204 + i) = 0;
}

static void SetControllersVariables(void)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            gBattleBankFunc[0] = SetBankFuncToRecordedPlayerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetBankFuncToPlayerPartnerBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
        }
        else
        {
            gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetBankFuncToPlayerPartnerBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
        }

        gNoOfAllBanks = 4;

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);

        gBattlePartyID[0] = 0;
        gBattlePartyID[1] = 0;
        gBattlePartyID[2] = 3;
        gBattlePartyID[3] = 3;
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            gBattleBankFunc[0] = SetBankFuncToSafariBufferRunCommand;
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
            gBattleBankFunc[0] = SetBankFuncToWallyBufferRunCommand;
        else
            gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;

        gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

        gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
        gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

        gNoOfAllBanks = 2;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
                {
                    gBattleMainFunc = BeginBattleIntro;

                    gBattleBankFunc[0] = SetBankFuncToRecordedPlayerBufferRunCommand;
                    gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                    gBattleBankFunc[1] = SetBankFuncToRecordedOpponentBufferRunCommand;
                    gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                    gNoOfAllBanks = 2;
                }
                else // see how the banks are switched
                {
                    gBattleBankFunc[1] = SetBankFuncToRecordedPlayerBufferRunCommand;
                    gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

                    gBattleBankFunc[0] = SetBankFuncToRecordedOpponentBufferRunCommand;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gNoOfAllBanks = 2;
                }
            }
            else
            {
                gBattleBankFunc[0] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
                gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;
            }
        }
    }
    else
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;
        gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

        gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
        gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

        gBattleBankFunc[2] = SetBankFuncToPlayerBufferRunCommand;
        gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

        gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
        gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

        gNoOfAllBanks = 4;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
            {
                gBattleMainFunc = BeginBattleIntro;

                gBattleBankFunc[0] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[0] = 0;

                gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
                gBanksByIdentity[1] = 1;

                gBattleBankFunc[2] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[2] = 2;

                gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
                gBanksByIdentity[3] = 3;

                gNoOfAllBanks = 4;

                sub_81B8D64(0, 0);
                sub_81B8D64(1, 0);
                sub_81B8D64(2, 1);
                sub_81B8D64(3, 1);

                gBattlePartyID[0] = 0;
                gBattlePartyID[1] = 0;
                gBattlePartyID[2] = 3;
                gBattlePartyID[3] = 3;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                u8 var; // multiplayer Id in a recorded battle?

                for (var = gUnknown_0203C7B4, i = 0; i < BATTLE_BANKS_COUNT; i++)
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
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToRecordedPlayerBufferRunCommand;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[var].lp_field_18 & 1))
                            || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[var].lp_field_18 & 1)))
                    {
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToRecordedPlayerBufferRunCommand;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else
                    {
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToRecordedOpponentBufferRunCommand;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_OPPONENT_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_OPPONENT_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                }
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            {
                gBattleBankFunc[0] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[2] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                  gBattleBankFunc[1] = SetBankFuncToRecordedOpponentBufferRunCommand;
                  gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                  gBattleBankFunc[3] = SetBankFuncToRecordedOpponentBufferRunCommand;
                  gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
                }
                else
                {
                  gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
                  gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                  gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
                  gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
                }
            }
            else
            {
                gBattleBankFunc[1] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[3] = SetBankFuncToRecordedPlayerBufferRunCommand;
                gBanksByIdentity[3] = IDENTITY_PLAYER_MON2;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                    gBattleBankFunc[0] = SetBankFuncToRecordedOpponentBufferRunCommand;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gBattleBankFunc[2] = SetBankFuncToRecordedOpponentBufferRunCommand;
                    gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;
                }
                else
                {
                    gBattleBankFunc[0] = SetBankFuncToOpponentBufferRunCommand;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gBattleBankFunc[2] = SetBankFuncToOpponentBufferRunCommand;
                    gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;
                }
            }
        }
    }
}

static void SetControllersVariablesInLinkBattle(void)
{
    s32 i;
    u8 multiplayerId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gNoOfAllBanks = 2;
        }
        else
        {
            gBattleBankFunc[1] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[0] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

            gNoOfAllBanks = 2;
        }
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
        else
        {
            gBattleBankFunc[1] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[0] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[3] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[2] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetBankFuncToLinkPartnerBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetBankFuncToOpponentBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
        else
        {
            gBattleBankFunc[0] = SetBankFuncToLinkPartnerBufferRunCommand;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetBankFuncToPlayerBufferRunCommand;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetBankFuncToLinkOpponentBufferRunCommand;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);
        gBattlePartyID[0] = 0;
        gBattlePartyID[1] = 0;
        gBattlePartyID[2] = 3;
        gBattlePartyID[3] = 3;
    }
    else
    {
        multiplayerId = GetMultiplayerId();

        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            gBattleMainFunc = BeginBattleIntro;

        for (i = 0; i < BATTLE_BANKS_COUNT; i++)
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
                gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToPlayerBufferRunCommand;
                switch (gLinkPlayers[i].lp_field_18)
                {
                case 0:
                case 3:
                    gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 0;
                    gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                    break;
                case 1:
                case 2:
                    gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 2;
                    gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                    break;
                }
            }
            else
            {
                if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[multiplayerId].lp_field_18 & 1))
                 || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[multiplayerId].lp_field_18 & 1)))
                {
                    gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToLinkPartnerBufferRunCommand;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 0;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 2;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
                else
                {
                    gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetBankFuncToLinkOpponentBufferRunCommand;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 1;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 3;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
            }
        }

        gNoOfAllBanks = 4;
    }
}

static void sub_8033050(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gNoOfAllBanks; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (i < 2)
                {
                    if (GET_BANK_SIDE2(i) == SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0)
                        {
                            gBattlePartyID[i] = j;
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
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                }
                else
                {
                    if (GET_BANK_SIDE2(i) == SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) != SPECIES_NONE  // Probably a typo by Game Freak. The rest use SPECIES2.
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlePartyID[i - 2] != j)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlePartyID[i - 2] != j)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                }
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            gBattlePartyID[1] = 0, gBattlePartyID[3] = 3;
    }
}

void PrepareBufferDataTransfer(u8 bufferId, u8 *data, u16 size)
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
                gBattleBufferA[gActiveBank][i] = *data;
                data++;
            }
            break;
        case 1:
            for (i = 0; i < size; i++)
            {
                gBattleBufferB[gActiveBank][i] = *data;
                data++;
            }
            break;
        }
    }
}

static void sub_8033244(void)
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
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ACTIVE_BANK] = gActiveBank;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ATTACKER] = gBankAttacker;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_TARGET] = gBankTarget;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_LO] = alignedSize;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_HI] = (alignedSize & 0x0000FF00) >> 8;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ABSENT_BANK_FLAGS] = gAbsentBankFlags;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_EFFECT_BANK] = gEffectBank;

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

            if (sub_800ABAC() >= var)
            {
                if (sub_800ABBC())
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
            if (gBattleExecBuffer & gBitTable[bank])
                return;

            memcpy(gBattleBufferA[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            sub_803F850(bank);

            if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
            {
                gBankAttacker = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 2];
                gBankTarget = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 3];
                gAbsentBankFlags = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 6];
                gEffectBank = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 7];
            }
            break;
        case 1:
            memcpy(gBattleBufferB[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            break;
        case 2:
            var = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_DATA];
            gBattleExecBuffer &= ~(gBitTable[bank] << (var * 4));
            break;
        }

        gTasks[taskId].data[15] = gTasks[taskId].data[15] + blockSize + LINK_BUFF_DATA;
    }
}

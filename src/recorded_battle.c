#include "global.h"
#include "battle.h"
#include "recorded_battle.h"
#include "main.h"
#include "pokemon.h"
#include "rng.h"
#include "event_data.h"
#include "link.h"
#include "string_util.h"

#define BANK_RECORD_SIZE 664

extern u32 gBattleTypeFlags;

struct PlayerInfo
{
    u32 trainerId;
    u8 name[PLAYER_NAME_LENGTH];
    u8 gender;
    u16 field_E;
    u16 language;
};

EWRAM_DATA u32 gRecordedBattleRngSeed = 0;
EWRAM_DATA u32 gBattlePalaceMoveSelectionRngValue = 0;
EWRAM_DATA u8 sBattleRecords[BATTLE_BANKS_COUNT][BANK_RECORD_SIZE] = {0};
EWRAM_DATA u16 sRecordedBytesNo[BATTLE_BANKS_COUNT] = {0};
EWRAM_DATA u16 gUnknown_0203C79C[4] = {0};
EWRAM_DATA u16 gUnknown_0203C7A4[4] = {0};
EWRAM_DATA u8 gUnknown_0203C7AC = 0;
EWRAM_DATA u8 gUnknown_0203C7AD = 0;
EWRAM_DATA u8 gUnknown_0203C7AE = 0;
EWRAM_DATA u8 gUnknown_0203C7AF = 0;
EWRAM_DATA MainCallback sRecordedBattle_Callback2 = NULL;
EWRAM_DATA u8 gUnknown_0203C7B4 = 0;
EWRAM_DATA u8 gUnknown_0203C7B5 = 0;
EWRAM_DATA u8 gUnknown_0203C7B6 = 0;
EWRAM_DATA u8 gUnknown_0203C7B7 = 0;
EWRAM_DATA u32 sRecordedBattle_BattleFlags = 0;
EWRAM_DATA u32 sRecordedBattle_AI_Scripts = 0;
EWRAM_DATA struct Pokemon sSavedPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA struct Pokemon sSavedOpponentParty[PARTY_SIZE] = {0};
EWRAM_DATA u16 gUnknown_0203CC70[8] = {0};
EWRAM_DATA struct PlayerInfo sRecordedBattle_Players[BATTLE_BANKS_COUNT] = {0};

extern u8 gUnknown_0203CCD0;

extern u32 sub_81A513C(void);

void sub_8184DA4(u8 arg0)
{
    s32 i, j;

    gUnknown_0203C7AC = arg0;
    gUnknown_0203CCD0 = 0;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        sRecordedBytesNo[i] = 0;
        gUnknown_0203C79C[i] = 0;
        gUnknown_0203C7A4[i] = 0;

        if (arg0 == 1)
        {
            for (j = 0; j < BANK_RECORD_SIZE; j++)
            {
                sBattleRecords[i][j] |= 0xFF;
            }
            sRecordedBattle_BattleFlags = gBattleTypeFlags;
            sRecordedBattle_AI_Scripts = gBattleResources->ai->aiFlags;
        }
    }
}

void sub_8184E58(void)
{
    s32 i, j;

    if (gUnknown_0203C7AC == 1)
    {
        gRecordedBattleRngSeed = gRngValue;
        gUnknown_0203C7AE = VarGet(VAR_FRONTIER_FACILITY);
        gUnknown_0203C7AF = sub_81A513C();
    }
    else if (gUnknown_0203C7AC == 2)
    {
        gRngValue = gRecordedBattleRngSeed;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 linkPlayersCount;
        u8 text[30];

        gUnknown_0203C7B4 = GetMultiplayerId();
        linkPlayersCount = GetLinkPlayerCount();

        for (i = 0; i < BATTLE_BANKS_COUNT; i++)
        {
            sRecordedBattle_Players[i].trainerId = gLinkPlayers[i].trainerId;
            sRecordedBattle_Players[i].gender = gLinkPlayers[i].gender;
            sRecordedBattle_Players[i].field_E = gLinkPlayers[i].lp_field_18;
            sRecordedBattle_Players[i].language = gLinkPlayers[i].language;

            if (i < linkPlayersCount)
            {
                StringCopy(text, gLinkPlayers[i].name);
                StripExtCtrlCodes(text);
                StringCopy(sRecordedBattle_Players[i].name, text);
            }
            else
            {
                for (j = 0; j < PLAYER_NAME_LENGTH; j++)
                    sRecordedBattle_Players[i].name[j] = gLinkPlayers[i].name[j];
            }
        }
    }
    else
    {
        sRecordedBattle_Players[0].trainerId = (gSaveBlock2Ptr->playerTrainerId[0])
                                    | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
                                    | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
                                    | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

        sRecordedBattle_Players[0].gender = gSaveBlock2Ptr->playerGender;
        sRecordedBattle_Players[0].field_E = 0;
        sRecordedBattle_Players[0].language = gGameLanguage;

        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            sRecordedBattle_Players[0].name[i] = gSaveBlock2Ptr->playerName[i];
    }
}

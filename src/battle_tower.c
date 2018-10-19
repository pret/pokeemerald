#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "battle_frontier_1.h"
#include "constants/battle_frontier.h"

extern void sub_81A3ACC(void);
extern u8 GetFrontierEnemyMonLevel(u8);

extern const u32 gUnknown_085DF9AC[][2];
extern const u32 gUnknown_085DF9CC[][2];
extern void (* const gUnknown_085DF96C[])(void);
extern const u8 gUnknown_085DF9F6[];
extern const u8 gUnknown_085DF9EC[];

// This file's functions.
void sub_8164ED8(void);
void sub_8163E90(void);
void sub_8165B20(void);
u16 GetCurrentBattleTowerWinStreak(u8 lvlMode, u8 battleMode);
void sub_816534C(void *);

// code
void sub_8161F74(void)
{
    gUnknown_085DF96C[gSpecialVar_0x8004]();
}

void sub_8161F94(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 1;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    sub_81A3ACC();
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] = 0;

    sub_8164ED8();
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

void sub_8162054(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSpecialVar_Result = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);
        break;
    case 2:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]) != 0);
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}

void sub_81620F4(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_085DF9AC[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_085DF9CC[battleMode][lvlMode];
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}

void sub_81621C0(void)
{
    if (gTrainerBattleOpponent_A == 500)
        sub_816534C(&gSaveBlock2Ptr->frontier.filler_BEC);

    if (gSaveBlock2Ptr->frontier.field_D04 < 9999)
        gSaveBlock2Ptr->frontier.field_D04++;

    gSaveBlock2Ptr->frontier.field_CB2++;
    sub_8163E90();
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CB2;
}

bool8 ChooseSpecialBattleTowerTrainer(void)
{
    s32 i, j, validMons;
    s32 trainerIds[9];
    s32 idsCount = 0;
    s32 winStreak = 0;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (VarGet(VAR_FRONTIER_FACILITY) != FRONTIER_FACILITY_TOWER)
        return FALSE;

    winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);
    for (i = 0; i < 5; i++)
    {
        u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.records[i]);
        u32 recordHasData = 0;
        u32 checksum = 0;
        for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
        {
            recordHasData |= record[j];
            checksum += record[j];
        }
        validMons = 0;
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.records[i].party[j].species != 0
                && gSaveBlock2Ptr->frontier.records[i].party[j].level <= GetFrontierEnemyMonLevel(lvlMode))
                validMons++;
        }

        if (validMons >= gUnknown_085DF9F6[battleMode]
            && gSaveBlock2Ptr->frontier.records[i].winStreak == winStreak
            && gSaveBlock2Ptr->frontier.records[i].lvlMode == lvlMode
            && recordHasData
            && gSaveBlock2Ptr->frontier.records[i].checksum == checksum)
        {
            trainerIds[idsCount] = i + BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID;
            idsCount++;
        }
    }

    if (battleMode == FRONTIER_MODE_SINGLES)
    {
        sub_8165B20();
        for (i = 0; i < 4; i++)
        {
            if (gSaveBlock2Ptr->apprentices[i].lvlMode != 0
                && gUnknown_085DF9EC[gSaveBlock2Ptr->apprentices[i].field_1] == winStreak
                && gSaveBlock2Ptr->apprentices[i].lvlMode - 1 == lvlMode)
            {
                trainerIds[idsCount] = i + BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID;
                idsCount++;
            }
        }
    }

    if (idsCount != 0)
    {
        gTrainerBattleOpponent_A = trainerIds[Random() % idsCount];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

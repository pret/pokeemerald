#include "global.h"
#include "battle_tower.h"
#include "apprentice.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "text.h"
#include "main.h"
#include "international_string_util.h"
#include "battle.h"
#include "battle_frontier_1.h"
#include "battle_frontier_2.h"
#include "recorded_battle.h"
#include "easy_chat.h"
#include "gym_leader_rematch.h"
#include "battle_transition.h"
#include "trainer_see.h"
#include "new_game.h"
#include "string_util.h"
#include "constants/battle_frontier.h"
#include "constants/trainers.h"
#include "constants/event_objects.h"
#include "constants/moves.h"

extern void sub_81A3ACC(void);
extern void CreateFrontierBrainPokemon(void);
extern void sub_81A6CD0(void);
extern u8 GetFrontierEnemyMonLevel(u8);
extern u8 GetFacilityEnemyMonLevel(void);
extern u16 sub_81A39C4(void);
extern void SetFrontierBrainTrainerGfxId(void);
extern u8 GetFrontierBrainTrainerPicIndex(void);
extern u8 GetFrontierBrainTrainerClass(void);
extern u8 IsFrontierBrainFemale(void);
extern void CopyFrontierBrainTrainerName(u8 *dst);
extern void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 move, u8 moveSlot);

extern const u32 gUnknown_085DF9AC[][2];
extern const u32 gUnknown_085DF9CC[][2];
extern void (* const gUnknown_085DF96C[])(void);
extern const u8 gUnknown_085DF9F6[];
extern const u8 gUnknown_085DF9EC[];
extern const u16 gBattleFrontierHeldItems[];

// This file's functions.
void sub_8164ED8(void);
void SaveCurrentWinStreak(void);
void sub_8165B20(void);
void sub_8165E18(void);
void sub_816537C(void);
void sub_8164FB8(struct EmeraldBattleTowerRecord *record);
u16 GetCurrentBattleTowerWinStreak(u8 lvlMode, u8 battleMode);
void sub_816534C(void *);
u16 sub_8162548(u8, u8);
void sub_81630C4(u16 trainerId, u8 firstMonId, u8 monCount);
void sub_8165EA4(u16 trainerId, u8 firstMonId, u8 monCount);
void sub_81635D4(u16 trainerId, u8 firstMonId);
void sub_816379C(u16 trainerId, u8 firstMonId);
u8 GetFrontierTrainerFixedIvs(u16 trainerId);
void sub_8165404(u16 trainerId);

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
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
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
    if (gTrainerBattleOpponent_A == BATTLE_TOWER_EREADER_TRAINER_ID)
        sub_816534C(&gSaveBlock2Ptr->frontier.ereaderTrainer);

    if (gSaveBlock2Ptr->frontier.field_D04 < 9999)
        gSaveBlock2Ptr->frontier.field_D04++;

    gSaveBlock2Ptr->frontier.curChallengeBattleNum++;
    SaveCurrentWinStreak();
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
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
        u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[i]);
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
            if (gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species != 0
                && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].level <= GetFrontierEnemyMonLevel(lvlMode))
                validMons++;
        }

        if (validMons >= gUnknown_085DF9F6[battleMode]
            && gSaveBlock2Ptr->frontier.towerRecords[i].winStreak == winStreak
            && gSaveBlock2Ptr->frontier.towerRecords[i].lvlMode == lvlMode
            && recordHasData
            && gSaveBlock2Ptr->frontier.towerRecords[i].checksum == checksum)
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

void ChooseNextBattleTowerTrainer(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    if (lvlMode == FRONTIER_LVL_TENT)
    {
        sub_8165E18();
    }
    else
    {
        u16 id;
        u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u32 r5 = sub_81A39C4() / 7;
        GetFacilityEnemyMonLevel(); // Pointless function call.

        if (battleMode == FRONTIER_MODE_MULTIS || battleMode == FRONTIER_MODE_LINK_MULTIS)
        {
            id = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            gTrainerBattleOpponent_A = gSaveBlock2Ptr->frontier.battledTrainerIds[id * 2];
            gTrainerBattleOpponent_B = gSaveBlock2Ptr->frontier.battledTrainerIds[id * 2 + 1];
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_B, 1);
        }
        else if (ChooseSpecialBattleTowerTrainer())
        {
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            gSaveBlock2Ptr->frontier.battledTrainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;
        }
        else
        {
            s32 i;
            while (1)
            {
                id = sub_8162548(r5, gSaveBlock2Ptr->frontier.curChallengeBattleNum);

                // Ensure trainer wasn't previously fought in this challenge.
                for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
                {
                    if (gSaveBlock2Ptr->frontier.battledTrainerIds[i] == id)
                        break;
                }
                if (i == gSaveBlock2Ptr->frontier.curChallengeBattleNum)
                    break;
            }

            gTrainerBattleOpponent_A = id;
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            if (gSaveBlock2Ptr->frontier.curChallengeBattleNum + 1 < 7)
                gSaveBlock2Ptr->frontier.battledTrainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;
        }
    }
}

extern const u16 gUnknown_085DFA1A[][2];
extern const u16 gUnknown_085DF9FA[][2];

u16 sub_8162548(u8 challengeNum, u8 battleNum)
{
    u16 trainerId;

    if (challengeNum <= 7)
    {
        if (battleNum == 6)
        {
            trainerId = (gUnknown_085DFA1A[challengeNum][1] - gUnknown_085DFA1A[challengeNum][0]) + 1;
            trainerId = gUnknown_085DFA1A[challengeNum][0] + (Random() % trainerId);
        }
        else
        {
            trainerId = (gUnknown_085DF9FA[challengeNum][1] - gUnknown_085DF9FA[challengeNum][0]) + 1;
            trainerId = gUnknown_085DF9FA[challengeNum][0] + (Random() % trainerId);
        }
    }
    else
    {
        trainerId = (gUnknown_085DF9FA[7][1] - gUnknown_085DF9FA[7][0]) + 1;
        trainerId = gUnknown_085DF9FA[7][0] + (Random() % trainerId);
    }

    return trainerId;
}

#ifdef NONMATCHING
u16 sub_81625B4(u8 challengeNum, u8 battleNum, u16 *trainerIdPtr, u8 *arg3) // Unused
{
    register u16 trainerId, count;

    if (challengeNum <= 7)
    {
        if (battleNum == 6)
        {
            count = (gUnknown_085DFA1A[challengeNum][1] - gUnknown_085DFA1A[challengeNum][0]) + 1;
            trainerId = gUnknown_085DFA1A[challengeNum][0];
        }
        else
        {
            count = (gUnknown_085DF9FA[challengeNum][1] - gUnknown_085DF9FA[challengeNum][0]) + 1;
            trainerId = gUnknown_085DF9FA[challengeNum][0];
        }
    }
    else
    {
        count = (gUnknown_085DF9FA[7][1] - gUnknown_085DF9FA[7][0]) + 1;
        trainerId = gUnknown_085DF9FA[7][0];
    }

    *trainerIdPtr = trainerId;
    *arg3 = count;
}
#else
NAKED
u16 sub_81625B4(u8 challengeNum, u8 battleNum, u16 *trainerIdPtr, u8 *arg3)
{
    asm_unified("	push {r4,lr}\n\
	adds r4, r2, 0\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	adds r2, r0, 0\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	cmp r0, 0x7\n\
	bhi _081625F4\n\
	cmp r1, 0x6\n\
	bne _081625D4\n\
	ldr r1, =gUnknown_085DFA1A\n\
	lsls r2, r0, 2\n\
	b _081625D8\n\
	.pool\n\
_081625D4:\n\
	ldr r1, =gUnknown_085DF9FA\n\
	lsls r2, 2\n\
_081625D8:\n\
	adds r0, r1, 0x2\n\
	adds r0, r2, r0\n\
	adds r2, r1\n\
	ldrh r0, [r0]\n\
	ldrh r1, [r2]\n\
	subs r0, r1\n\
	adds r0, 0x1\n\
	lsls r0, 16\n\
	lsrs r1, r0, 16\n\
	ldrh r0, [r2]\n\
	b _08162604\n\
	.pool\n\
_081625F4:\n\
	ldr r0, =gUnknown_085DF9FA\n\
	ldrh r1, [r0, 0x1E]\n\
	ldrh r2, [r0, 0x1C]\n\
	subs r1, r2\n\
	adds r1, 0x1\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	ldrh r0, [r0, 0x1C]\n\
_08162604:\n\
	strh r0, [r4]\n\
	strb r1, [r3]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.pool");
}
#endif

void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId)
{
    u32 i;
    u8 facilityClass;
    u8 trainerObjectGfxId;

    GetFacilityEnemyMonLevel(); // Pointless function call.
    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        SetFrontierBrainTrainerGfxId();
        return;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleTrainerGfxIds[i];
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    switch (tempVarId)
    {
    case 0:
    default:
        VarSet(VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_BOY_1);
        return;
    case 1:
        VarSet(VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_BOY_1);
        return;
    case 15:
        VarSet(VAR_OBJ_GFX_ID_E, EVENT_OBJ_GFX_BOY_1);
        return;
    }
}

void SetEReaderTrainerGfxId(void)
{
    SetBattleFacilityTrainerGfxId(BATTLE_TOWER_EREADER_TRAINER_ID, 0);
}

u8 GetBattleFacilityTrainerGfxId(u16 trainerId)
{
    u32 i;
    u8 facilityClass;
    u8 trainerObjectGfxId;

    GetFacilityEnemyMonLevel(); // Pointless function call.
    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }
    else
    {
        return EVENT_OBJ_GFX_BOY_1;
    }
}

void PutNewBattleTowerRecord(union BattleTowerRecord *newRecord)
{
    u16 slotValues[6];
    u16 slotIds[6];
    s32 i, j, k;
    s32 slotsCount = 0;
    struct EmeraldBattleTowerRecord *newRecordEm = &newRecord->emerald;

    // Find a record slot of the same player and replace it.
    for (i = 0; i < 5; i++)
    {
        k = 0;
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[i].trainerId[j] != newRecordEm->trainerId[j])
                break;
        }
        if (j == 4)
        {
            for (k = 0; k < PLAYER_NAME_LENGTH; k++)
            {
                // BUG: Wrong variable used, 'j' instead of 'k'.
                if (gSaveBlock2Ptr->frontier.towerRecords[i].name[j] != newRecordEm->name[j])
                    break;
                if (newRecordEm->name[j] == EOS)
                {
                    k = PLAYER_NAME_LENGTH;
                    break;
                }
            }
        }

        if (k == PLAYER_NAME_LENGTH)
            break;
    }
    if (i < 5)
    {
        gSaveBlock2Ptr->frontier.towerRecords[i] = *newRecordEm;
        return;
    }

    // Find an empty record slot.
    for (i = 0; i < 5; i++)
    {
        if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak == 0)
            break;
    }
    if (i < 5)
    {
        gSaveBlock2Ptr->frontier.towerRecords[i] = *newRecordEm;
        return;
    }

    // Find possible slots to replace the record.
    slotValues[0] = gSaveBlock2Ptr->frontier.towerRecords[0].winStreak;
    slotIds[0] = 0;
    slotsCount++;

    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < slotsCount; j++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak < slotValues[j])
            {
                j = 0;
                slotsCount = 1;
                slotValues[0] = gSaveBlock2Ptr->frontier.towerRecords[i].winStreak;
                slotIds[0] = i;
                break;
            }
            else if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak > slotValues[j])
            {
                break;
            }
        }

        if (j == slotsCount)
        {
            slotValues[slotsCount] = gSaveBlock2Ptr->frontier.towerRecords[i].winStreak;
            slotIds[slotsCount] = i;
            slotsCount++;
        }
    }

    i = Random() % slotsCount;
    gSaveBlock2Ptr->frontier.towerRecords[slotIds[i]] = *newRecordEm;
}

u8 GetFrontierTrainerFrontSpriteId(u16 trainerId)
{
    GetFacilityEnemyMonLevel(); // Pointless function call

    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        return GetFrontierBrainTrainerPicIndex();
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        return gFacilityClassToPicIndex[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[sub_818649C()];
        else
            return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass];
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[gApprentices[sub_81864A8()].facilityClass];
        else
            return gFacilityClassToPicIndex[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass];
    }
}

u8 GetFrontierOpponentClass(u16 trainerId)
{
    u8 trainerClass = 0;
    GetFacilityEnemyMonLevel(); // Pointless function call.

    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        trainerClass = GetFrontierBrainTrainerClass();
    }
    else if (trainerId == TRAINER_STEVEN_PARTNER)
    {
        trainerClass = gTrainers[TRAINER_STEVEN].trainerClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        trainerClass = gFacilityClassToTrainerClass[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[sub_818649C()];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass];
            asm("");
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[sub_81864A8()].facilityClass];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass];
            asm("");
        }
    }

    return trainerClass;
}

u8 GetFrontierTrainerFacilityClass(u16 trainerId)
{
    u8 facilityClass;
    GetFacilityEnemyMonLevel(); // Pointless function call.

    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = sub_818649C();
        else
            facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass;
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = gApprentices[sub_81864A8()].facilityClass;
        else
            facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass;
    }

    return facilityClass;
}

void GetFrontierTrainerName(u8 *dst, u16 trainerId)
{
    s32 i = 0;
    GetFacilityEnemyMonLevel(); // Pointless function call.

    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gSaveBlock2Ptr->frontier.ereaderTrainer.name[i];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(dst);
        return;
    }
    else if (trainerId == TRAINER_STEVEN_PARTNER)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gTrainers[TRAINER_STEVEN].trainerName[i];
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gFacilityTrainers[trainerId].trainerName[i];
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            sub_8186468(dst);
            return;
        }
        else
        {
            struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID];
            TVShowConvertInternationalString(dst, record->name, record->language);
            return;
        }
    }
    else
    {
        u8 id, language;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            id = sub_81864A8();
            language = sub_81864C0();
        }
        else
        {
            struct Apprentice *apprentice = &gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID];
            id = apprentice->id;
            language = apprentice->language;
        }
        TVShowConvertInternationalString(dst, GetApprenticeNameInLanguage(id, language), language);
        return;
    }

    dst[i] = EOS;
}

bool8 IsFrontierTrainerFemale(u16 trainerId)
{
    u32 i;
    u8 facilityClass;

    GetFacilityEnemyMonLevel(); // Pointless function call.
    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        return IsFrontierBrainFemale();
    }
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].id].facilityClass;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
        return TRUE;
    else
        return FALSE;
}

void sub_8163048(u8 monsCount)
{
    ZeroEnemyPartyMons();
    sub_81630C4(gTrainerBattleOpponent_A, 0, monsCount);
}

void sub_816306C(u8 monsCount)
{
    ZeroEnemyPartyMons();
    sub_81630C4(gTrainerBattleOpponent_A, 0, monsCount);
    sub_81630C4(gTrainerBattleOpponent_B, 3, monsCount);
}

void sub_81630A0(u8 monsCount)
{
    ZeroEnemyPartyMons();
    sub_8165EA4(gTrainerBattleOpponent_A, 0, monsCount);
}

void sub_81630C4(u16 trainerId, u8 firstMonId, u8 monCount)
{
    s32 i, j;
    u16 chosenMonIndices[4];
    u8 friendship = 0xFF;
    u8 level = GetFacilityEnemyMonLevel();
    u8 fixedIV = 0;
    u8 bfMonCount;
    const u16 *bfMonPool = NULL;
    u32 otID = 0;

    if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        // Normal battle frontier trainer.
        fixedIV = GetFrontierTrainerFixedIvs(trainerId);
        bfMonPool = gFacilityTrainers[gTrainerBattleOpponent_A].bfMonPool;
    }
    else if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        for (i = firstMonId; i < firstMonId + 3; i++)
            sub_806819C(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CreateFrontierBrainPokemon();
        return;
    }
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
    {
        // Record mixed player.
        for (j = 0, i = firstMonId; i < firstMonId + monCount; j++, i++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[j].species != 0
                && gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[j].level <= level)
            {
                sub_8068338(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[j], FALSE);
            }
        }
        return;
    }
    else
    {
        // Apprentice.
        for (i = firstMonId; i < firstMonId + 3; i++)
            CreateApprenticeMon(&gEnemyParty[i], &gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID], i - firstMonId);
        return;
    }

    // Regular battle frontier trainer.
    // Attempt to fill the trainer's party with random Pokemon until 3 have been
    // successfully chosen. The trainer's party may not have duplicate pokemon species
    // or duplicate held items.
    for (bfMonCount = 0; bfMonPool[bfMonCount] != 0xFFFF; bfMonCount++)
        ;
    i = 0;
    otID = Random32();
    while (i != monCount)
    {
        u16 monPoolId = bfMonPool[Random() % bfMonCount];
        if ((level == 50 || level == 20) && monPoolId > 849)
            continue;

        // Ensure this pokemon species isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_SPECIES, NULL) == gFacilityTrainerMons[monPoolId].species)
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this Pokemon's held item isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) != 0
             && GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) == gBattleFrontierHeldItems[gFacilityTrainerMons[monPoolId].itemTableId])
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this exact pokemon index isn't a duplicate. This check doesn't seem necessary
        // because the species and held items were already checked directly above.
        for (j = 0; j < i; j++)
        {
            if (chosenMonIndices[j] == monPoolId)
                break;
        }
        if (j != i)
            continue;

        chosenMonIndices[i] = monPoolId;

        // Place the chosen pokemon into the trainer's party.
        CreateMonWithEVSpreadPersonalityOTID(&gEnemyParty[i + firstMonId],
                                             gFacilityTrainerMons[monPoolId].species,
                                             level,
                                             gFacilityTrainerMons[monPoolId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monPoolId].evSpread,
                                             otID);

        friendship = 255;
        // Give the chosen pokemon its specified moves.
        for (j = 0; j < 4; j++)
        {
            SetMonMoveSlot(&gEnemyParty[i + firstMonId], gFacilityTrainerMons[monPoolId].moves[j], j);
            if (gFacilityTrainerMons[monPoolId].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;  // Frustration is more powerful the lower the pokemon's friendship is.
        }

        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monPoolId].itemTableId]);

        // The pokemon was successfully added to the trainer's party, so it's safe to move on to
        // the next party slot.
        i++;
    }
}

// Probably an early draft before the 'CreateApprenticeMon' was written.
void Unused_CreateApprenticeMons(u16 trainerId, u8 firstMonId)
{
    s32 i, j;
    u8 friendship = 0xFF;
    u8 level = 0;
    u8 fixedIV = 0;
    struct Apprentice *apprentice = &gSaveBlock2Ptr->apprentices[0];

    if (apprentice->field_1 < 5)
        fixedIV = 6;
    else
        fixedIV = 9;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = 100;
    else
        level = 50;

    for (i = 0; i != 3; i++)
    {
        CreateMonWithEVSpread(&gEnemyParty[firstMonId + i], apprentice->monData[i].species, level, fixedIV, 8);
        friendship = 0xFF;
        for (j = 0; j < 4; j++)
        {
            if (apprentice->monData[i].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &apprentice->monData[i].item);
    }
}

u16 RandomizeFacilityTrainerMonId(u16 trainerId)
{
    u32 monPoolId;
    u8 level = GetFacilityEnemyMonLevel();
    const u16 *bfMonPool = gFacilityTrainers[trainerId].bfMonPool;
    u8 bfMonCount = 0;

    /*
    I had to use ugly C tricks to get this part to match.
    A cleaner version would look like this

    for (bfMonCount = 0; bfMonPool[bfMonCount] != 0xFFFF; bfMonCount++)
        ;

    */

    monPoolId = bfMonPool[bfMonCount];
    goto COMPARE;
    while (1)
    {
        bfMonCount++;
        monPoolId = bfMonPool[bfMonCount];
    COMPARE:
        if (monPoolId == 0xFFFF)
            break;
    }

    do
    {
        monPoolId = bfMonPool[Random() % bfMonCount];
    } while((level == 50 || level == 20) && monPoolId > 849);

    return monPoolId;
}

void sub_8163590(void)
{
    ZeroEnemyPartyMons();
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        sub_81635D4(gTrainerBattleOpponent_A, 0);
    else
        sub_816379C(gTrainerBattleOpponent_A, 0);
}

extern u16 gUnknown_03006298[];

void sub_81635D4(u16 trainerId, u8 firstMonId)
{
    u8 i, j;
    u8 friendship;
    u8 level;
    u8 fixedIV;
    u32 otID;

    if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
    {
        u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode; // Unused variable.
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.field_CE0[battleMode][0] / 7;
        if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 6)
            fixedIV = sub_81A6CA8(challengeNum, 0);
        else
            fixedIV = sub_81A6CA8(challengeNum, 1);
    }
    else if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
    {
        for (i = firstMonId; i < firstMonId + 3; i++)
            sub_806819C(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        sub_81A6CD0();
        return;
    }
    else
    {
        fixedIV = 31;
    }


    level = GetFacilityEnemyMonLevel();
    otID = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);
    for (i = 0; i < 3; i++)
    {
        u16 poolId = gUnknown_03006298[i];
        CreateMonWithEVSpreadPersonalityOTID(&gEnemyParty[firstMonId + i],
                                             gFacilityTrainerMons[poolId].species,
                                             level,
                                             gFacilityTrainerMons[poolId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[poolId].evSpread,
                                             otID);

        friendship = 0;
        for (j = 0; j < 4; j++)
            SetMonMoveAvoidReturn(&gEnemyParty[firstMonId + i], gFacilityTrainerMons[poolId].moves[j], j);

        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[poolId].itemTableId]);
    }
}

void sub_816379C(u16 trainerId, u8 firstMonId)
{
    u8 i, j;
    u8 friendship;
    u8 level = 30;
    u8 fixedIV = 0;
    u32 otID = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < 3; i++)
    {
        u16 poolId = gUnknown_03006298[i];
        CreateMonWithEVSpreadPersonalityOTID(&gEnemyParty[firstMonId + i],
                                             gFacilityTrainerMons[poolId].species,
                                             level,
                                             gFacilityTrainerMons[poolId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[poolId].evSpread,
                                             otID);

        friendship = 0;
        for (j = 0; j < 4; j++)
        {
            SetMonMoveAvoidReturn(&gEnemyParty[firstMonId + i], gFacilityTrainerMons[poolId].moves[j], j);
            if (gFacilityTrainerMons[poolId].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }

        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[poolId].itemTableId]);
    }
}

void FrontierSpeechToString(const u16 *words)
{
    ConvertEasyChatWordsToString(gStringVar4, words, 3, 2);
    if (GetStringWidth(1, gStringVar4, -1) > 204)
    {
        s32 i = 0;

        ConvertEasyChatWordsToString(gStringVar4, words, 2, 3);
        while (gStringVar4[i++] != CHAR_NEWLINE)
            ;
        while (gStringVar4[i] != CHAR_NEWLINE)
            i++;

        gStringVar4[i] = CHAR_PROMPT_SCROLL;
    }
}

void sub_8163914(void)
{
    u16 trainerId;
    GetFacilityEnemyMonLevel(); // Pointless function call.

    if (gSpecialVar_0x8005)
        trainerId = gTrainerBattleOpponent_B;
    else
        trainerId = gTrainerBattleOpponent_A;

    if (trainerId == BATTLE_TOWER_EREADER_TRAINER_ID)
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
    else if (trainerId < BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID)
        FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
    else if (trainerId < BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID)
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].greeting);
    else
        CopyFriendsApprenticeChallengeText(trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID);
}

static void HandleSpecialTrainerBattleEnd(void)
{
    s32 i;

    sub_81864CC();
    switch (gBattleScripting.specialTrainerBattleType)
    {
    case SPECIAL_BATTLE_TOWER:
    case SPECIAL_BATTLE_DOME:
    case SPECIAL_BATTLE_PALACE:
    case SPECIAL_BATTLE_ARENA:
    case SPECIAL_BATTLE_FACTORY:
    case SPECIAL_BATTLE_PIKE_SINGLE:
    case SPECIAL_BATTLE_PIKE_DOUBLE:
    case SPECIAL_BATTLE_PYRAMID:
        if (gSaveBlock2Ptr->frontier.battlesCount < 0xFFFFFF)
        {
            gSaveBlock2Ptr->frontier.battlesCount++;
            if (gSaveBlock2Ptr->frontier.battlesCount % 20 == 0)
                UpdateGymLeaderRematch();
        }
        else
        {
            gSaveBlock2Ptr->frontier.battlesCount = 0xFFFFFF;
        }
        break;
    case SPECIAL_BATTLE_SECRET_BASE:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 itemBefore = GetMonData(&gSaveBlock1Ptr->playerParty[i], MON_DATA_HELD_ITEM);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &itemBefore);
        }
        break;
    case SPECIAL_BATTLE_EREADER:
        sub_816537C();
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_StartBattleAfterTransition(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = HandleSpecialTrainerBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

extern const u8 MossdeepCity_SpaceCenter_2F_EventScript_224157[];
extern const u8 MossdeepCity_SpaceCenter_2F_EventScript_224166[];

void DoSpecialTrainerBattle(void)
{
    s32 i;

    gBattleScripting.specialTrainerBattleType = gSpecialVar_0x8004;
    switch (gSpecialVar_0x8004)
    {
    case SPECIAL_BATTLE_TOWER:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
        {
        case FRONTIER_MODE_SINGLES:
            sub_8163048(3);
            break;
        case FRONTIER_MODE_DOUBLES:
            sub_8163048(4);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
            break;
        case FRONTIER_MODE_MULTIS:
            sub_816306C(2);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.field_CD6;
            sub_8165404(gPartnerTrainerId);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
            break;
        case FRONTIER_MODE_LINK_MULTIS:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_MULTI | BATTLE_TYPE_x800000;
            sub_816306C(2);
            break;
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(0));
        break;
    case SPECIAL_BATTLE_SECRET_BASE:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 itemBefore = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
            SetMonData(&gSaveBlock1Ptr->playerParty[i], MON_DATA_HELD_ITEM, &itemBefore);
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(12));
        break;
    case SPECIAL_BATTLE_EREADER:
        ZeroEnemyPartyMons();
        for (i = 0; i < 3; i++)
            sub_806819C(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i]);
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_EREADER_TRAINER;
        gTrainerBattleOpponent_A = 0;
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(13));
        break;
    case SPECIAL_BATTLE_DOME:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOME;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            sub_8163048(2);
        CreateTask(Task_StartBattleAfterTransition, 1);
        sub_806E694(0);
        BattleTransition_StartOnField(sub_80B100C(3));
        break;
    case SPECIAL_BATTLE_PALACE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
            sub_8163048(3);
        else
            sub_81630A0(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(4));
        break;
    case SPECIAL_BATTLE_ARENA:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_ARENA;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
            sub_8163048(3);
        else
            sub_81630A0(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(5));
        break;
    case SPECIAL_BATTLE_FACTORY:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_FACTORY;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        sub_8163590();
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(6));
        break;
    case SPECIAL_BATTLE_PIKE_SINGLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        sub_8163048(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(7));
        break;
    case SPECIAL_BATTLE_PYRAMID:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID;
        sub_8163048(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(10));
        break;
    case SPECIAL_BATTLE_PIKE_DOUBLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        sub_816306C(1);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(7));
        break;
    case SPECIAL_BATTLE_STEVEN:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        sub_8165404(TRAINER_STEVEN_PARTNER);
        gApproachingTrainerId = 0;
        BattleSetup_ConfigureTrainerBattle(MossdeepCity_SpaceCenter_2F_EventScript_224157 + 1);
        gApproachingTrainerId = 1;
        BattleSetup_ConfigureTrainerBattle(MossdeepCity_SpaceCenter_2F_EventScript_224166 + 1);
        gPartnerTrainerId = TRAINER_STEVEN_PARTNER;
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(B_TRANSITION_MAGMA);
        break;
    }
}

void SaveCurrentWinStreak(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);

    if (gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] < winStreak)
        gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] = winStreak;
}

void sub_8163EE4(void)
{
    s32 i;
    u8 lvlMode, battleMode, class;
    struct EmeraldBattleTowerRecord *playerRecord = &gSaveBlock2Ptr->frontier.towerPlayer;

    sub_8164FB8(playerRecord);
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        class = gTowerFemaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] +
                                       gSaveBlock2Ptr->playerTrainerId[1] +
                                       gSaveBlock2Ptr->playerTrainerId[2] +
                                       gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerFemaleFacilityClasses)];
    }
    else
    {
        class = gTowerMaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] +
                                     gSaveBlock2Ptr->playerTrainerId[1] +
                                     gSaveBlock2Ptr->playerTrainerId[2] +
                                     gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerMaleFacilityClasses)];
    }
    playerRecord->lvlMode = lvlMode;
    playerRecord->facilityClass = class;
    CopyUnalignedWord(playerRecord->trainerId, gSaveBlock2Ptr->playerTrainerId);
    StringCopy7(playerRecord->name, gSaveBlock2Ptr->playerName);
    playerRecord->winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);

    for (i = 0; i < 6; i++)
    {
        playerRecord->greeting[i] = gSaveBlock1Ptr->unk2BBC[i];
        playerRecord->unk1C[i] = gSaveBlock1Ptr->unk2BC8[i];
        playerRecord->unk28[i] = gSaveBlock1Ptr->unk2BD4[i];
    }

    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.field_CAA[i] != 0)
            sub_80686FC(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], &playerRecord->party[i]);
    }

    playerRecord->language = gGameLanguage;
    CalcEmeraldBattleTowerChecksum(&gSaveBlock2Ptr->frontier.towerPlayer);
    SaveCurrentWinStreak();
}

void SaveBattleTowerProgress(void)
{
    u16 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 challengeNum = (signed)(gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] / 7);

    if (gSpecialVar_0x8005 == 0 && (challengeNum > 1 || gSaveBlock2Ptr->frontier.curChallengeBattleNum != 0))
        sub_8163EE4();

    gSaveBlock2Ptr->frontier.field_CA8 =gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

void nullsub_61(void)
{

}

void nullsub_116(void)
{

}

void sub_81640E0(u16 trainerId)
{
    s32 i, count;
    u32 validSpecies[3];
    u16 species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    u16 species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);

    count = 0;
    for (i = 0; i < 3; i++)
    {
        u16 apprenticeSpecies = gSaveBlock2Ptr->apprentices[trainerId - BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID].monData[i].species;
        if (apprenticeSpecies != species1 && apprenticeSpecies != species2)
        {
            validSpecies[count] = i;
            count++;
        }
    }

    gUnknown_03006298[0] = validSpecies[Random() % count];
    do
    {
        gUnknown_03006298[1] = validSpecies[Random() % count];
    } while (gUnknown_03006298[0] == gUnknown_03006298[1]);
}

void sub_8164188(u16 trainerId)
{
    s32 i, count;
    u32 validSpecies[3];
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    u16 species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);

    count = 0;
    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[i].species != species1
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[i].species != species2
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[i].level <= GetFrontierEnemyMonLevel(lvlMode)
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID].party[i].species != 0)
        {
            validSpecies[count] = i;
            count++;
        }
    }

    gUnknown_03006298[2] = validSpecies[Random() % count];
    do
    {
        gUnknown_03006298[3] = validSpecies[Random() % count];
    } while (gUnknown_03006298[2] == gUnknown_03006298[3]);
}

void sub_81642A0(void)
{
    s32 i, j, k;
    u32 spArray[5];
    s32 r10;
    u16 trainerId;
    u16 monPoolId;
    u32 lvlMode, battleMode;
    s32 challengeNum;
    u32 species1, species2;
    u32 level;
    struct EventObjectTemplate *eventObjTemplates;

    eventObjTemplates = gSaveBlock1Ptr->eventObjectTemplates;
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] / 7;
    species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);
    level = GetFacilityEnemyMonLevel();

    for (j = 0; j < 6; j++)
    {
        do
        {
            trainerId = sub_8162548(challengeNum, 0);
            for (i = 0; i < j; i++)
            {
                if (gSaveBlock2Ptr->frontier.battledTrainerIds[i] == trainerId)
                    break;
                if (gFacilityTrainers[gSaveBlock2Ptr->frontier.battledTrainerIds[i]].facilityClass == gFacilityTrainers[trainerId].facilityClass)
                    break;
            }
        } while (i != j);
        gSaveBlock2Ptr->frontier.battledTrainerIds[j] = trainerId;
    }

    r10 = 8;
    for (i = 0; i < 6; i++)
    {
        trainerId = gSaveBlock2Ptr->frontier.battledTrainerIds[i];
        eventObjTemplates[i + 1].graphicsId = GetBattleFacilityTrainerGfxId(trainerId);
        for (j = 0; j < 2; j++)
        {
            while (1)
            {
                monPoolId = RandomizeFacilityTrainerMonId(trainerId);
                if (j % 2 != 0 && gFacilityTrainerMons[gSaveBlock2Ptr->frontier.battledTrainerIds[r10 - 1]].itemTableId == gFacilityTrainerMons[monPoolId].itemTableId)
                    continue;

                for (k = 8; k < r10; k++)
                {
                    if (gFacilityTrainerMons[gSaveBlock2Ptr->frontier.battledTrainerIds[k]].species == gFacilityTrainerMons[monPoolId].species)
                        break;
                    if (species1 == gFacilityTrainerMons[monPoolId].species)
                        break;
                    if (species2 == gFacilityTrainerMons[monPoolId].species)
                        break;
                }
                if (k == r10)
                    break;
            }

            gSaveBlock2Ptr->frontier.battledTrainerIds[r10] = monPoolId;
            r10++;
        }
    }

    r10 = 0;
    sub_8165B20();
    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->apprentices[i].lvlMode != 0
            && gUnknown_085DF9EC[gSaveBlock2Ptr->apprentices[i].field_1] / 7 <= challengeNum
            && gSaveBlock2Ptr->apprentices[i].lvlMode - 1 == lvlMode)
        {
            k = 0;
            for (j = 0; j < 3; j++)
            {
                if (species1 != gSaveBlock2Ptr->apprentices[i].monData[j].species
                    && species2 != gSaveBlock2Ptr->apprentices[i].monData[j].species)
                {
                    k++;
                }
            }
            if (k > 2)
            {
                spArray[r10] = i + BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID;
                r10++;
            }
        }
    }
    if (r10 != 0)
    {
        gSaveBlock2Ptr->frontier.battledTrainerIds[6] = spArray[Random() % r10];
        eventObjTemplates[7].graphicsId = GetBattleFacilityTrainerGfxId(gSaveBlock2Ptr->frontier.battledTrainerIds[6]);
        FlagClear(FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1);
        sub_81640E0(gSaveBlock2Ptr->frontier.battledTrainerIds[6]);
    }

    r10 = 0;
    for (i = 0; i < 5; i++)
    {
        u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[i]);
        u32 recordHasData = 0;
        u32 checksum = 0;
        for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
        {
            recordHasData |= record[j];
            checksum += record[j];
        }

        if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak / 7 <= challengeNum
            && gSaveBlock2Ptr->frontier.towerRecords[i].lvlMode == lvlMode
            && recordHasData
            && gSaveBlock2Ptr->frontier.towerRecords[i].checksum == checksum)
        {
            k = 0;
            for (j = 0; j < 4; j++)
            {
                if (species1 != gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species
                    && species2 != gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species
                    && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].level <= GetFrontierEnemyMonLevel(lvlMode)
                    && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species != 0)
                {
                    k++;
                }
            }
            if (k > 1)
            {
                spArray[r10] = i + BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID;
                r10++;
            }
        }
    }
    if (r10 != 0)
    {
        gSaveBlock2Ptr->frontier.battledTrainerIds[7] = spArray[Random() % r10];
        eventObjTemplates[8].graphicsId = GetBattleFacilityTrainerGfxId(gSaveBlock2Ptr->frontier.battledTrainerIds[7]);
        FlagClear(FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2);
        sub_8164188(gSaveBlock2Ptr->frontier.battledTrainerIds[7]);
    }
}

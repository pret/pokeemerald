#include "global.h"
#include "battle_pyramid_bag.h"
#include "event_data.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "save.h"
#include "fieldmap.h"
#include "palette.h"
#include "field_message_box.h"
#include "random.h"
#include "item.h"
#include "util.h"
#include "sound.h"
#include "task.h"
#include "start_menu.h"
#include "trainer_see.h"
#include "main.h"
#include "load_save.h"
#include "script.h"
#include "malloc.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/moves.h"

extern u8 gUnknown_0203CEF8[3];
extern void door_upload_tiles(void);

extern const struct MapLayout *const gMapLayouts[];

#define TOTAL_ROUNDS 20

struct Struct_08613650
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6[10];
};

extern const u16 gBattleFrontierHeldItems[];
extern const struct FacilityMon gBattleFrontierMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];

// This file's functions.
void sub_81AAA7C(u8 lvlMode);
u8 sub_81AA9E4(void);
u16 sub_81A9AA8(u8);
u8 sub_81A9998(s32 *, u8, u8);
u8 sub_81AAA40(void);
u8 InBattlePyramid(void);
void sub_81A97DC(u8 taskId);
void sub_81A9B44(u16 trainerId);
void sub_81AA96C(u8 *);
void sub_81AA33C(u8 *, u8 *);

// Const rom data.
extern void (* const gUnknown_08613EE0[])(void);
extern const struct Struct_08613650 gUnknown_08613650[];
extern const u16 sPickupItemsLvl50[TOTAL_ROUNDS][10];
extern const u16 sPickupItemsLvlOpen[TOTAL_ROUNDS][10];
extern const u8 gUnknown_08613ABC[63][2];
extern const u8 gUnknown_08613B3A[];
extern const u16 gUnknown_08613F34[9];
extern const u16 gUnknown_08613F28[6];
extern const u16 gUnknown_08D856C8[][16];
extern const u8 gUnknown_08613C1C[50][2];
extern const u8 gUnknown_08613ED8[];
extern const u8 *const *const *const gUnknown_08613EC0[];

// code
void sub_81A8E7C(void)
{
    gUnknown_08613EE0[gSpecialVar_0x8004]();
}

void sub_81A8E9C(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
    else
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;

    if (!isCurrent)
    {
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
        sub_81AAA7C(lvlMode);
    }

    sub_81C4EEC();
    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

void sub_81A8F38(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E18;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50];
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN];
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        break;
    }
}

void sub_81A9048(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E18 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x2000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x2000);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x1000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x1000);
        }
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_E2A = gSpecialVar_0x8006;
        break;
    }
}

void sub_81A9134(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    save_serialize_map();
    TrySavingData(SAVE_LINK);
}

void sub_81A917C(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F34[Random() % ARRAY_COUNT(gUnknown_08613F34)];
    else
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F28[Random() % ARRAY_COUNT(gUnknown_08613F28)];
}

void sub_81A91FC(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E18, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E18, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E18 = 0;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81A9254(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gSaveBlock2Ptr->frontier.field_E22[i] = Random();

    gSaveBlock2Ptr->frontier.field_E2A = 0;
}

void sub_81A9290(void)
{
    s32 i;
    s32 r7;
    s32 rand;
    u8 id;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 floor = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    u32 round = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7) % TOTAL_ROUNDS;

    if (round >= TOTAL_ROUNDS)
        round = TOTAL_ROUNDS - 1;

    id = sub_81AA9E4();
    r7 = (gSpecialVar_LastTalked - gUnknown_08613650[id].unk1) - 1;
    rand = gSaveBlock2Ptr->frontier.field_E22[r7 / 2];
    SeedRng2(rand);

    for (i = 0; i < r7 + 1; i++)
        rand = Random2() % 100;

    for (i = gUnknown_08613B3A[floor]; i < ARRAY_COUNT(gUnknown_08613ABC); i++)
    {
        if (rand < gUnknown_08613ABC[i][0])
            break;
    }

    if (lvlMode != FRONTIER_LVL_50)
        gSpecialVar_0x8000 = sPickupItemsLvlOpen[round][gUnknown_08613ABC[i][1]];
    else
        gSpecialVar_0x8000 = sPickupItemsLvl50[round][gUnknown_08613ABC[i][1]];

    gSpecialVar_0x8001 = 1;
}

void sub_81A93C8(void)
{
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    s32 i = 0;

    for (;;)
    {
        if (events[i].localId == gSpecialVar_LastTalked)
        {
            events[i].x = 0x7FFF;
            events[i].y = 0x7FFF;
            break;
        }
        i++;
        if (events[i].localId == 0)
            break;
    }
}

void sub_81A9414(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

void sub_81A9424(void)
{
    s32 i;
    s32 var_24;
    u8 id;
    s32 class = 0;
    s32 r7 = 0;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    u16 trainerId = sub_81A9AA8(gEventObjects[gSelectedEventObject].localId);

    for (i = 0; i < ARRAY_COUNT(gUnknown_08613C1C); i++)
    {
        if (gUnknown_08613C1C[i][0] == gFacilityTrainers[trainerId].facilityClass)
        {
            class = gUnknown_08613C1C[i][1];
            break;
        }
    }

    var_24 = gUnknown_08613ED8[gEventObjects[gSelectedEventObject].localId - 1];
    i = 0;
    while (!i)
    {
        switch (var_24)
        {
        case 0:
            r7 = sub_81A9998(&var_24, 8, 0);
            i = 1;
            break;
        case 1:
            for (i = 0; i < sub_81AAA40(); i++)
            {
                if (events[i].graphicsId == EVENT_OBJ_GFX_ITEM_BALL && events[i].x != 0x7FFF && events[i].y != 0x7FFF)
                    r7++;
            }
            i = 1;
            break;
        case 2:
            id = sub_81AA9E4();
            r7 = gUnknown_08613650[id].unk1;
            for (i = 0; i < 8; i++)
            {
                if (gBitTable[i] & gSaveBlock2Ptr->frontier.field_E2A)
                    r7--;
            }
            i = 1;
            break;
        case 3:
            sub_81A9998(&var_24, 8, 2);
            break;
        case 4:
            sub_81A9998(&var_24, 8, 1);
            break;
        case 5:
            sub_81A9998(&var_24, 16, 2);
            break;
        case 6:
            sub_81A9998(&var_24, 16, 1);
            break;
        case 7:
            sub_81A9998(&var_24, 24, 2);
            break;
        case 8:
            sub_81A9998(&var_24, 24, 1);
            break;
        }
    }
    ShowFieldMessage(gUnknown_08613EC0[class][var_24][r7]);
}

void sub_81A9618(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < 999)
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
}

void sub_81A966C(void)
{
    gSpecialVar_Result = InBattlePyramid();
}

void sub_81A9684(void)
{
    switch (gSpecialVar_0x8006)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E68 = gSpecialVar_0x8005;
        break;
    case 1:
        switch (gSpecialVar_Result)
        {
        case 0:
            if (!gPaletteFade.active)
            {
                if (gSaveBlock2Ptr->frontier.field_E68 >= 120)
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                else
                    PlaySE(gSpecialVar_0x8007);
                gSpecialVar_Result++;
            }
            break;
        case 1:
            if (gSpecialVar_0x8005 != 0)
            {
                gSpecialVar_0x8005--;
                gSaveBlock2Ptr->frontier.field_E68++;
                if (gSaveBlock2Ptr->frontier.field_E68 > 120)
                {
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                    gSpecialVar_Result++;
                }
                door_upload_tiles();
            }
            else
            {
                gSpecialVar_Result = 2;
            }
            break;
        case 2:
        default:
            break;
        }
        break;
    }
}

void sub_81A975C(void)
{
    s32 i, j;
    u16 item = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.selectedPartyMons[j] != 0 && gSaveBlock2Ptr->frontier.selectedPartyMons[j] - 1 == i)
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

void sub_81A97C8(void)
{
    CreateTask(sub_81A97DC, 0);
}

void sub_81A97DC(u8 taskId)
{
    if (gPaletteFade.active)
    {
        CpuCopy16(gUnknown_08D856C8[gSaveBlock2Ptr->frontier.curChallengeBattleNum], &gPlttBufferUnfaded[96], 32);
        DestroyTask(taskId);
    }
}

void sub_81A9828(void)
{
    sub_809FDD4();
}

void sub_81A9834(void)
{
    s32 i, j, k, l;

    for (i = 0; i < 3; i++)
    {
        s32 id = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        for (j = 0; j < 3; j++)
        {
            if (GetMonData(&gSaveBlock1Ptr->playerParty[id], MON_DATA_SPECIES, NULL) == GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL))
            {
                for (k = 0; k < 4; k++)
                {
                    for (l = 0; l < 4; l++)
                    {
                        if (GetMonData(&gSaveBlock1Ptr->playerParty[id], MON_DATA_MOVE1 + l, NULL) == GetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + k, NULL))
                            break;
                    }
                    if (l == 4)
                        SetMonMoveSlot(&gPlayerParty[j], MOVE_SKETCH, k);
                }
                gSaveBlock1Ptr->playerParty[id] = gPlayerParty[j];
                gUnknown_0203CEF8[j] = id + 1;
                break;
            }
        }
    }

    for (i = 0; i < 3; i++)
        gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gUnknown_0203CEF8[i];
}

u8 sub_81A9998(s32 *arg0, u8 arg1, u8 arg2)
{
    s32 i, j;
    u8 ret = 0;
    u16 *map = gUnknown_03005DC0.map;
    map += gUnknown_03005DC0.width * 7 + 7;

    for (i = 0; i < 32; map += 47, i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((map[j] & 0x3FF) == 0x28E)
            {
                j += 7 - gEventObjects[gSelectedEventObject].initialCoords.x;
                i += 7 - gEventObjects[gSelectedEventObject].initialCoords.y;
                if (j >= arg1 || j <= -arg1 || i >= arg1 || i <= -arg1 || arg2 == 0)
                {
                    if (j > 0 && i > 0)
                    {
                        if (j >= i)
                            ret = 2;
                        else
                            ret = 3;
                    }
                    else if (j < 0 && i < 0)
                    {
                        if (j > i)
                            ret = 0;
                        else
                            ret = 1;
                    }
                    else if (j == 0)
                    {
                        if (i > 0)
                            ret = 3;
                        else
                            ret = 0;
                    }
                    else if (i == 0)
                    {
                        if (j > 0)
                            ret = 2;
                        else
                            ret = 1;
                    }
                    else if (j < 0)
                    {
                        if (j + i > 0)
                            ret = 3;
                        else
                            ret = 1;
                    }
                    else
                    {
                        ret = (~(j + i) >= 0) ? 0 : 2;
                    }
                    *arg0 = 0;
                }
                else
                {
                    *arg0 = arg2;
                }
                return ret;
            }
        }
    }

    return ret;
}

u16 sub_81A9AA8(u8 arg0)
{
    return gSaveBlock2Ptr->frontier.field_CB4[arg0 - 1];
}

bool8 GetBattlePyramidTrainerFlag(u8 eventId)
{
    return gSaveBlock2Ptr->frontier.field_E2A & gBitTable[gEventObjects[eventId].localId - 1];
}

void sub_81A9B04(void)
{
    sub_81A9B44(gTrainerBattleOpponent_A);
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        gSelectedEventObject = GetChosenApproachingTrainerEventObjectId(1);
        sub_81A9B44(gTrainerBattleOpponent_B);
    }
}

struct PyramidWildMon
{
    u16 species;
    u8 lvl;
    u8 abilityBit;
    u16 moves[4];
};

extern const struct PyramidWildMon *const gBattlePyramidOpenLevelWildMonPointers[];
extern const struct PyramidWildMon *const gBattlePyramidLevel50WildMonPointers[];

void sub_81A9B44(u16 trainerId)
{
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
            gSaveBlock2Ptr->frontier.field_E2A |= gBitTable[i];
    }

    gEventObjects[gSelectedEventObject].movementType = MOVEMENT_TYPE_WANDER_AROUND;
    gSaveBlock1Ptr->eventObjectTemplates[gSpecialVar_LastTalked - 1].movementType = MOVEMENT_TYPE_WANDER_AROUND;
    gEventObjects[gSelectedEventObject].initialCoords.x = gEventObjects[gSelectedEventObject].currentCoords.x;
    gEventObjects[gSelectedEventObject].initialCoords.y = gEventObjects[gSelectedEventObject].currentCoords.y;
}

void GenerateBattlePyramidWildMon(void)
{
    u8 name[POKEMON_NAME_LENGTH + 1];
    s32 i;
    const struct PyramidWildMon *wildMons;
    u32 id;
    u32 lvl = gSaveBlock2Ptr->frontier.lvlMode;
    u16 round = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvl] / 7) % TOTAL_ROUNDS;

    if (round >= TOTAL_ROUNDS)
        round = TOTAL_ROUNDS - 1;

    if (lvl != FRONTIER_LVL_50)
        wildMons = gBattlePyramidOpenLevelWildMonPointers[round];
    else
        wildMons = gBattlePyramidLevel50WildMonPointers[round];

    id = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) - 1;
    SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wildMons[id].species);
    GetSpeciesName(name, wildMons[id].species);
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, &name);
    if (lvl != FRONTIER_LVL_50)
    {
        lvl = SetFacilityPtrsGetLevel();
        lvl -= wildMons[id].lvl;
        lvl = lvl - 5 + (Random() % 11);
    }
    else
    {
        lvl = wildMons[id].lvl - 5 + ((Random() % 11));
    }
    SetMonData(&gEnemyParty[0],
               MON_DATA_EXP,
               &gExperienceTables[gBaseStats[wildMons[id].species].growthRate][lvl]);

    switch (wildMons[id].abilityBit)
    {
    case 0:
    case 1:
        SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &wildMons[id].abilityBit);
        break;
    case 2:
    default:
        if (gBaseStats[wildMons[id].species].ability2)
        {
            i = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY, NULL) % 2;
            SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &i);
        }
        else
        {
            i = 0;
            SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &i);
        }
        break;
    }

    for (i = 0; i < 4; i++)
        SetMonMoveSlot(&gEnemyParty[0], wildMons[id].moves[i], i);

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvl] >= 140) // BUG: Reading outside the array as lvl was used for mon level instead of frontier lvl mode.
    {
        id = (Random() % 17) + 15;
        for (i = 0; i < NUM_STATS; i++)
            SetMonData(&gEnemyParty[0], MON_DATA_HP_IV + i, &id);
    }
    CalculateMonStats(&gEnemyParty[0]);
}

u8 sub_81A9E28(void)
{
    u8 id = sub_81AA9E4();
    return gUnknown_08613650[id].unk4;
}

u8 InBattlePyramid(void)
{
    if (gMapHeader.mapLayoutId == 361)
        return 1;
    else if (gMapHeader.mapLayoutId == 378)
        return 2;
    else
        return FALSE;
}

bool8 InBattlePyramid_(void)
{
    return (gMapHeader.mapLayoutId == 361 || gMapHeader.mapLayoutId == 378);
}

void sub_81A9E90(void)
{
    if (InBattlePyramid())
    {
        sub_81A9834();
        gSaveBlock2Ptr->frontier.field_CA8 = 2;
        VarSet(VAR_TEMP_E, 0);
        LoadPlayerParty();
    }
}

void sub_81A9EC8(void)
{
    if (InBattlePyramid())
        DoSoftReset();
}

void sub_81A9EDC(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
}

void sub_81A9EFC(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechWin);
}

void sub_81A9F1C(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechLose);
}

struct ClassMusic
{
    u8 class;
    u8 music;
};

extern const struct ClassMusic gUnknown_08613B44[54];
extern const u8 BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88[];

u8 GetTrainerEncounterMusicIdInBattlePyramind(u16 trainerId)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_08613B44); i++)
    {
        if (gUnknown_08613B44[i].class == gFacilityClassToTrainerClass[gFacilityTrainers[trainerId].facilityClass])
            return gUnknown_08613B44[i].music;
    }
    return 0;
}

void sub_81A9F80(void)
{
    ScriptContext1_SetupScript(BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88);
}

u16 sub_81A9F90(u8 count)
{
    s32 i;
    u16 trainerId;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 challengeNum = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7;
    u32 battleNum = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    if (battleNum == 7)
    {
        do
        {
            trainerId = sub_8162548(challengeNum + 1, battleNum);
            for (i = 0 ; i < count; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                    break;
            }
        } while (i != count);
    }
    else
    {
        do
        {
            trainerId = sub_8162548(challengeNum, battleNum);
            for (i = 0 ; i < count; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                    break;
            }
        } while (i != count);
    }

    return trainerId;
}

void sub_81AA078(u16 *mapArg, u8 arg1)
{
    s32 j, k;
    s32 i;
    u8 var0, var1;
    u8 *allocated = AllocZeroed(0x10);

    sub_81AA96C(allocated);
    sub_81AA33C(&var0, &var1);
    for (i = 0; i < 16; i++)
    {
        u16 *map;
        s32 heightAdd, widthAdd;
        const struct MapLayout *mapLayout = gMapLayouts[allocated[i] + 0x169];
        const u16 *layoutMap = mapLayout->map;

        gUnknown_03005DC0.map = mapArg;
        gUnknown_03005DC0.width = mapLayout->width * 4 + 15;
        gUnknown_03005DC0.height = mapLayout->height * 4 + 14;
        map = mapArg;
        heightAdd = (((i / 4 * mapLayout->height) + 7) * (gUnknown_03005DC0.width));
        widthAdd = ((i % 4 * mapLayout->width) + 7);
        map += heightAdd + widthAdd;
        for (j = 0; j < mapLayout->height; j++)
        {
            for (k = 0; k < mapLayout->width; k++)
            {
                if ((layoutMap[k] & 0x3FF) != 0x28E)
                {
                    map[k] = layoutMap[k];
                }
                else if (i != var1)
                {
                    if (i == var0 && arg1 == 0)
                    {
                        gSaveBlock1Ptr->pos.x = (mapLayout->width * (i % 4)) + k;
                        gSaveBlock1Ptr->pos.y = (mapLayout->height * (i / 4)) + j;
                    }
                    map[k] = (layoutMap[k] & 0xFC00) | 0x28D;
                }
                else
                {
                    map[k] = layoutMap[k];
                }
            }
            map += 15 + (mapLayout->width * 4);
            layoutMap += mapLayout->width;
        }
    }
    mapheader_run_script_with_tag_x1();
    free(allocated);
}

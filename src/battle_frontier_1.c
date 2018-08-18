#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_frontier_1.h"
#include "battle_message.h"
#include "event_data.h"
#include "overworld.h"
#include "util.h"
#include "malloc.h"
#include "string_util.h"
#include "random.h"
#include "task.h"
#include "main.h"
#include "gpu_regs.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "palette.h"
#include "decompress.h"
#include "menu.h"
#include "sound.h"
#include "pokemon_icon.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/abilities.h"
#include "constants/songs.h"

#define DOME_ROUND1 0
#define DOME_ROUND2 1
#define DOME_QUARTERFINAL 1 // Different name for the same round.
#define DOME_SEMIFINAL 2
#define DOME_FINAL 3

struct Unknown_0203BC8C_Struct
{
    u16 species;
    u16 moves[4];
    u8 itemTableId;
    u8 evSpread;
    u8 nature;
};

struct Unknown_0203CD78_Struct
{
    u8 arr[16];
    u8 unk_10;
    u8 unk_11[3];
};

extern void sub_81B8558(void);
extern u32 sub_81A39C4(void);
extern u16 sub_8162548(u8, u8);
extern u16 RandomizeFacilityTrainerMonId(u16);
extern u8 GetFrontierEnemyMonLevel(void);
extern void sub_8195898(u8 *dst, u16 trainerId);
extern u16 sub_81A5060(u8, u8);
extern void sub_8162614(u16, u8);
extern void sub_81A4C30(void);
extern u16 sub_818D8F0(u16);
extern bool8 sub_81A3610(void);
extern u16 sub_81A4FF0(u8);

extern u8 gUnknown_0203CEF8[];
extern u32 gUnknown_0203CD70;
extern u32 gUnknown_0203CD74;
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern struct Unknown_0203BC8C_Struct *gFacilityTrainerMons;
extern struct Unknown_0203CD78_Struct *gUnknown_0203CD78;

extern void (* const gUnknown_0860D090[])(void);
extern const u32 gUnknown_0860D0EC[][2];
extern const u32 gUnknown_0860D0FC[][2];
extern const u16 gBattleFrontierHeldItems[];
extern const u8 gUnknown_0860D10C[][4];
extern const u8 gUnknown_0860D14C[];
extern const struct BgTemplate gUnknown_0860CE84[4];
extern const struct WindowTemplate gUnknown_0860CEB4[];
extern const struct CompressedSpriteSheet gUnknown_0860CF50;
extern const struct SpriteTemplate gUnknown_0860D068;
extern const struct SpriteTemplate gUnknown_0860D050;
extern const u8 gUnknown_0860D080[];
extern const u8 gUnknown_0860D15C[];
extern const u8 gUnknown_0860D1A0[];
extern const u8 gUnknown_0860D19C[];
extern const u8 gUnknown_0860D1C0[];
extern const u8 gUnknown_0860D3F1[][2];

// gfx
extern const u8 gUnknown_08D83D50[];
extern const u8 gUnknown_08D84970[];
extern const u8 gUnknown_08D84F00[];
extern const u8 gUnknown_08D85444[];
extern const u8 gUnknown_08D85358[];
extern const u8 gUnknown_08D85600[];
extern const u8 gUnknown_08D854C8[];

// This file's functions.
u8 GetDomeTrainerMonIvs(u16 trainerId);
void SwapDomeTrainers(s32 id1, s32 id2, u16 *statsArray);
void CalcDomeMonStats(u16 species, s32 level, s32 ivs, u8 evBits, u8 nature, s32 *stats);
void CreateDomeTrainerMons(u16 tournamentTrainerId);
u16 TrainerIdToTournamentId(u16 trainerId);
s32 sub_818FC78(u16 tournamentTrainerId);
s32 sub_818FCBC(u16 tournamentTrainerId, bool8 arg1);
s32 sub_818FDB8(u16 tournamentTrainerId, bool8 arg1);
s32 sub_818FFC0(s32 move, s32 species, s32 arg2);
s32 sub_818FEB4(s32 *arr, bool8 arg1);
u16 TrainerIdOfPlayerOpponent(void);
void sub_8190400(u8 taskId);
void sub_8190CD4(u8 taskId);
void sub_8194220(u8 taskId);
void sub_8194B54(void);
void sub_8194B70(void);
void sub_819314C(u8, u8);
void sub_81924E0(u8, u8);
u8 sub_819221C(u8 taskId);
s32 sub_8192F08(u8, u8*);

// code
void sub_818E9AC(void)
{
    gUnknown_0860D090[gSpecialVar_0x8004]();
}

void sub_818E9CC(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 battleMode = VarGet(VAR_0x40CE);

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode] = 0;

    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

void sub_818EA84(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 battleMode = VarGet(VAR_0x40CE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode];
        break;
    case 1:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[battleMode][lvlMode]) != 0);
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
        break;
    case 6:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_5;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_4;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        }
        break;
    case 7:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_7;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_6;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        }
        break;
    case 8:
        sub_81B8558();
        gUnknown_0203CEF8[0] = gSaveBlock2Ptr->frontier.field_CB0;
        gUnknown_0203CEF8[1] = gSaveBlock2Ptr->frontier.field_CB0 >> 8;
        break;
    case 9:
        gSpecialVar_Result = (gSaveBlock2Ptr->frontier.field_D0A * 2) - 3 + gSaveBlock2Ptr->frontier.field_D0B;
        break;
    }
}

void sub_818ED28(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 battleMode = VarGet(VAR_0x40CE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 1:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_0860D0EC[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_0860D0FC[battleMode][lvlMode];
        break;
    case 2:
        gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
        break;
    case 4:
        gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        break;
    case 5:
        gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
        break;
    case 6:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_5 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_4 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        }
        break;
    case 7:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_7 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_6 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        }
        break;
    case 8:
        gSaveBlock2Ptr->frontier.field_CB0 = T1_READ_16(gUnknown_0203CEF8);
        break;
    }
}

void InitDomeTrainers(void)
{
    s32 i, j, k;
    s32 monLevel;
    s32 species[3];
    s32 monTypesBits, monTypesCount;
    s32 trainerId;
    s32 monTournamentId;
    u16 *statSums;
    s32 *statValues;
    u8 ivs = 0;

    species[0] = 0;
    species[1] = 0;
    species[2] = 0;
    statSums = AllocZeroed(sizeof(u16) * DOME_TOURNAMENT_TRAINERS_COUNT);
    statValues = AllocZeroed(sizeof(s32) * 6);

    gSaveBlock2Ptr->frontier.field_D0A = gSaveBlock2Ptr->frontier.chosenLvl + 1;
    gSaveBlock2Ptr->frontier.field_D0B = VarGet(VAR_0x40CE) + 1;
    gSaveBlock2Ptr->frontier.domeTrainers[0].trainerId = TRAINER_PLAYER;
    gSaveBlock2Ptr->frontier.domeTrainers[0].unk1 = 0;
    gSaveBlock2Ptr->frontier.domeTrainers[0].unk2 = 0;
    gSaveBlock2Ptr->frontier.domeTrainers[0].unk3 = 0;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->frontier.domeMonId[0][i] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_SPECIES, NULL);
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].moves[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_MOVE1 + j, NULL);
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].evs[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_HP_EV + j, NULL);

        gSaveBlock2Ptr->frontier.field_EFC[i].nature = GetNature(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1]);
    }

    for (i = 1; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (i > 5)
        {
            do
            {
                trainerId = sub_8162548(sub_81A39C4(), 0);
                for (j = 1; j < i; j++)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == trainerId)
                        break;
                }
            } while (j != i);
            gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId = trainerId;
        }
        else
        {
            do
            {
                trainerId = sub_8162548(sub_81A39C4() + 1, 0);
                for (j = 1; j < i; j++)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == trainerId)
                        break;
                }
            } while (j != i);
            gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId = trainerId;
        }

        for (j = 0; j < 3; j++)
        {
            // Make sure the mon is valid.
            do
            {
                monTournamentId = RandomizeFacilityTrainerMonId(trainerId);
                for (k = 0; k < j; k++)
                {
                    s32 checkingMonId = gSaveBlock2Ptr->frontier.domeMonId[i][k];
                    if (checkingMonId == monTournamentId
                        || species[0] == gFacilityTrainerMons[monTournamentId].species
                        || species[1] == gFacilityTrainerMons[monTournamentId].species
                        || gFacilityTrainerMons[checkingMonId].itemTableId == gFacilityTrainerMons[monTournamentId].itemTableId)
                        break;
                }
            } while (k != j);

            gSaveBlock2Ptr->frontier.domeMonId[i][j] = monTournamentId;
            species[j] = gFacilityTrainerMons[monTournamentId].species;
        }

        gSaveBlock2Ptr->frontier.domeTrainers[i].unk1 = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].unk2 = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].unk3 = 0;
    }

    monTypesBits = 0;
    statSums[0] = 0;
    for (i = 0; i < 3; i++)
    {
        trainerId = gSaveBlock2Ptr->frontier.field_CAA[i] - 1; // Great variable choice, gamefreak.
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_ATK, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_DEF, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPATK, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPDEF, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPEED, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_MAX_HP, NULL);
        monTypesBits |= gBitTable[gBaseStats[GetMonData(&gPlayerParty[trainerId], MON_DATA_SPECIES, NULL)].type1];
        monTypesBits |= gBitTable[gBaseStats[GetMonData(&gPlayerParty[trainerId], MON_DATA_SPECIES, NULL)].type2];
    }

    for (monTypesCount = 0, j = 0; j < 32; j++)
    {
        if (monTypesBits & 1)
            monTypesCount++;
        monTypesBits >>= 1;
    }

    monLevel = GetFrontierEnemyMonLevel();
    statSums[0] += (monTypesCount * monLevel) / 20;

    for (i = 1; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        monTypesBits = 0;
        statSums[i] = 0;
        ivs = GetDomeTrainerMonIvs(gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
        for (j = 0; j < 3; j++)
        {
            CalcDomeMonStats(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[i][j]].species,
                             monLevel, ivs,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[i][j]].evSpread,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[i][j]].nature,
                             statValues);

            statSums[i] += statValues[STAT_ATK];
            statSums[i] += statValues[STAT_DEF];
            statSums[i] += statValues[STAT_SPATK];
            statSums[i] += statValues[STAT_SPDEF];
            statSums[i] += statValues[STAT_SPEED];
            statSums[i] += statValues[STAT_HP];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[i][j]].species].type1];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[i][j]].species].type2];
        }

        for (monTypesCount = 0, j = 0; j < 32; j++)
        {
            if (monTypesBits & 1)
                monTypesCount++;
            monTypesBits >>= 1;
        }
        statSums[i] += (monTypesCount * monLevel) / 20;
    }

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT - 1; i++)
    {
        for (j = i + 1; j < DOME_TOURNAMENT_TRAINERS_COUNT; j++)
        {
            if (statSums[i] < statSums[j])
            {
                SwapDomeTrainers(i, j, statSums);
            }
            else
            {
                if (statSums[i] == statSums[j])
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == TRAINER_PLAYER)
                        SwapDomeTrainers(i, j, statSums);
                    else if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId > gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId)
                        SwapDomeTrainers(i, j, statSums);
                }
            }
        }
    }

    if (sub_81A3610())
    {
        for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
        {
            if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == TRAINER_PLAYER)
                break;
        }

        if (gUnknown_0860D3F1[i][0] != 0)
        {
            j = 0;
            gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId = TRAINER_FRONTIER_BRAIN;
        }
        else
        {
            j = 1;
            gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId = TRAINER_FRONTIER_BRAIN;
        }

        for (i = 0; i < 3; i++)
            gSaveBlock2Ptr->frontier.domeMonId[j][i] = sub_81A4FF0(i);
    }

    Free(statSums);
    Free(statValues);
}

#define CALC_STAT(base, statIndex)                                                          \
{                                                                                           \
    u8 baseStat = gBaseStats[species].base;                                                 \
    stats[statIndex] = (((2 * baseStat + ivs + evs[statIndex] / 4) * level) / 100) + 5;     \
    stats[statIndex] = (u8) ModifyStatByNature(nature, stats[statIndex], statIndex);        \
}

void CalcDomeMonStats(u16 species, s32 level, s32 ivs, u8 evBits, u8 nature, s32 *stats)
{
    s32 i, count;
    u8 bits;
    u16 resultingEvs;
    s32 evs[6];

    count = 0, bits = evBits;
    for (i = 0; i < 6; bits >>= 1, i++)
    {
        if (bits & 1)
            count++;
    }

    resultingEvs = 510 / count;
    for (i = 0; i < 6; bits <<= 1, i++)
    {
        evs[i] = 0;
        if (evBits & bits)
            evs[i] = resultingEvs;
    }

    if (species == SPECIES_SHEDINJA)
    {
        stats[STAT_HP] = 1;
    }
    else
    {
        s32 n = 2 * gBaseStats[species].baseHP;
        stats[STAT_HP] = (((n + ivs + evs[STAT_HP] / 4) * level) / 100) + level + 10;
    }

    CALC_STAT(baseAttack, STAT_ATK);
    CALC_STAT(baseDefense, STAT_DEF);
    CALC_STAT(baseSpeed, STAT_SPEED);
    CALC_STAT(baseSpAttack, STAT_SPATK);
    CALC_STAT(baseSpDefense, STAT_SPDEF);
}

#define SWAP_16(x, y)   \
{                       \
    temp = x;           \
    x = y;              \
    y = temp;           \
}

void SwapDomeTrainers(s32 id1, s32 id2, u16 *statsArray)
{
    s32 i;
    u16 temp;

    SWAP_16(statsArray[id1], statsArray[id2]);
    SWAP_16(gSaveBlock2Ptr->frontier.domeTrainers[id1].trainerId, gSaveBlock2Ptr->frontier.domeTrainers[id2].trainerId);

    for (i = 0; i < 3; i++)
        SWAP_16(gSaveBlock2Ptr->frontier.domeMonId[id1][i], gSaveBlock2Ptr->frontier.domeMonId[id2][i]);
}

void sub_818F9B0(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlock2Ptr->frontier.field_CB2]);
}

void sub_818F9E0(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlock2Ptr->frontier.field_CB2]);
    sub_8195898(gStringVar2, gTrainerBattleOpponent_A);
}

void sub_818FA20(void)
{
    gUnknown_0203CD70 = 0;
    gUnknown_0203CD74 =  GetMonData(&gPlayerParty[0], MON_DATA_MAX_HP, NULL);
    gUnknown_0203CD74 += GetMonData(&gPlayerParty[1], MON_DATA_MAX_HP, NULL);
    CalculatePlayerPartyCount();
    CreateDomeTrainerMons(TrainerIdToTournamentId(gTrainerBattleOpponent_A));
}

void CreateDomeMon(u8 monPartyId, u16 tournamentTrainerId, u8 tournamentMonId, u32 otId)
{
    s32 i;
    u8 happiness = 0xFF;
    u8 fixedIv = GetDomeTrainerMonIvs(tournamentTrainerId); // BUG: Should be using trainerId instead of tournamentTrainerId. As a result, all Pokemon have ivs of 3.
    u8 level = GetFrontierEnemyMonLevel();
    CreateMonWithEVSpreadPersonalityOTID(&gEnemyParty[monPartyId],
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].species,
                                         level,
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].nature,
                                         fixedIv,
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].evSpread, otId);

    happiness = 0xFF;
    for (i = 0; i < 4; i++)
    {
        SetMonMoveSlot(&gEnemyParty[monPartyId],
                       gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].moves[i], i);
        if (gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].moves[i] == MOVE_FRUSTRATION)
            happiness = 0;
    }

    SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &happiness);
    SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM,
               &gBattleFrontierHeldItems[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][tournamentMonId]].itemTableId]);
}

void CreateDomeTrainerMons(u16 tournamentTrainerId)
{
    u8 monsCount = 0;
    u32 otId = 0;
    s32 i, bits;

    ZeroEnemyPartyMons();
    bits = sub_818FC78(tournamentTrainerId);
    otId = Random32();
    if (Random() % 10 > 5)
    {
        for (i = 0; i < 3; i++)
        {
            if (bits & 1)
            {
                CreateDomeMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            bits >>= 1;
        }
    }
    else
    {
        for (i = 2; i >= 0; i--)
        {
            if (bits & 4)
            {
                CreateDomeMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            bits <<= 1;
        }
    }
}

s32 sub_818FC78(u16 tournamentTrainerId)
{
    s32 bits;
    if (Random() & 1)
    {
        bits = sub_818FCBC(tournamentTrainerId, FALSE);
        if (bits == 0)
            bits = sub_818FDB8(tournamentTrainerId, TRUE);
    }
    else
    {
        bits = sub_818FDB8(tournamentTrainerId, FALSE);
        if (bits == 0)
            bits = sub_818FCBC(tournamentTrainerId, TRUE);
    }

    return bits;
}

s32 sub_818FCBC(u16 tournamentTrainerId, bool8 arg1)
{
    s32 i, moveId, playerMonId;
    s32 array[3];

    for (i = 0; i < 3; i++)
    {
        array[i] = 0;
        for (moveId = 0; moveId < 4; moveId++)
        {
            for (playerMonId = 0; playerMonId < 3; playerMonId++)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentTrainerId].trainerId == TRAINER_FRONTIER_BRAIN)
                {
                    array[i] += sub_818FFC0(sub_81A5060(i, moveId),
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 0);
                }
                else
                {
                    array[i] += sub_818FFC0(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][i]].moves[moveId],
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 0);
                }
            }
        }
    }
    return sub_818FEB4(array, arg1);
}

s32 sub_818FDB8(u16 tournamentTrainerId, bool8 arg1)
{
    s32 i, moveId, playerMonId;
    s32 array[3];

    for (i = 0; i < 3; i++)
    {
        array[i] = 0;
        for (moveId = 0; moveId < 4; moveId++)
        {
            for (playerMonId = 0; playerMonId < 3; playerMonId++)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentTrainerId].trainerId == TRAINER_FRONTIER_BRAIN)
                {
                    array[i] += sub_818FFC0(sub_81A5060(i, moveId),
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 1);
                }
                else
                {
                    array[i] += sub_818FFC0(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonId[tournamentTrainerId][i]].moves[moveId],
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 1);
                }
            }
        }
    }
    return sub_818FEB4(array, arg1);
}

s32 sub_818FEB4(s32 *arr, bool8 arg1)
{
    s32 i, j;
    s32 bits = 0;
    s32 array[3];

    for (i = 0; i < 3; i++)
        array[i] = i;

    if (arr[0] == arr[1] && arr[0] == arr[2])
    {
        if (arg1)
        {
            i = 0;
            while (i != 2)
            {
                u32 rand = Random() & 3;
                if (rand != 3 && !(bits & gBitTable[rand]))
                {
                    bits |= gBitTable[rand];
                    i++;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                s32 temp;

                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }

                if (arr[i] == arr[j] && (Random() & 1))
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

        for (i = 0; i < 2; i++)
        {
            bits |= gBitTable[array[i]];
        }
    }

    return bits;
}

// Functionally equivalent, while loop is impossible to match.
#ifdef NONMATCHING
s32 sub_818FFC0(s32 move, s32 species, s32 arg2)
{
    s32 type1, type2, ability, moveType;
    s32 i = 0;
    s32 typePower = 20;

    if (move == MOVE_NONE || move == 0xFFFF || gBattleMoves[move].power == 0)
        return 0;

    type1 = gBaseStats[species].type1;
    type2 = gBaseStats[species].type2;
    ability = gBaseStats[species].ability1;
    moveType = gBattleMoves[move].type;

    if (ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        if (arg2 == 1)
            typePower = 8;
    }
    else
    {
        while (gTypeEffectiveness[i + 0] != TYPE_ENDTABLE)
        {
            if (gTypeEffectiveness[i + 0] == TYPE_FORESIGHT)
            {
                i += 3;
            }
            else
            {
                u8 val = gTypeEffectiveness[i + 0];
                if (val == moveType)
                {
                    // BUG: * 2 is not necessary and makes the condition always false if the ability is wonder guard.
                    if (gTypeEffectiveness[i + 1] == type1 && (ability != ABILITY_WONDER_GUARD || gTypeEffectiveness[i + 2] == TYPE_MUL_SUPER_EFFECTIVE * 2))
                        typePower = (gTypeEffectiveness[i + 2] * typePower) / 10;
                    if (gTypeEffectiveness[i + 1] == type2 && type1 != type2 && (ability != ABILITY_WONDER_GUARD || gTypeEffectiveness[i + 2] == TYPE_MUL_SUPER_EFFECTIVE * 2))
                        typePower = (gTypeEffectiveness[i + 2] * typePower) / 10;
                }
                i += 3;
            }
        }
    }

    switch (arg2)
    {
    case 0:
        switch (typePower)
        {
        case 10:
        case 5:
        case 0:
        default:
            typePower = 0;
            break;
        case 20:
            typePower = 2;
            break;
        case 40:
            typePower = 4;
            break;
        case 80:
            typePower = 8;
            break;
        }
        break;
    case 1:
        switch (typePower)
        {
        default:
        case 20:
            typePower = 0;
            break;
        case 5:
            typePower = 4;
            break;
        case 0:
            typePower = 8;
            break;
        case 10:
            typePower = 2;
            break;
        case 40:
            typePower = -2;
            break;
        case 80:
            typePower = -4;
            break;
        }
        break;
    case 2:
        switch (typePower)
        {
        case 0:
            typePower = -16;
            break;
        case 5:
            typePower = -8;
            break;
        case 10:
        default:
            typePower = 0;
            break;
        case 20:
            typePower = 4;
            break;
        case 40:
            typePower = 12;
            break;
        case 80:
            typePower = 20;
            break;
        }
        break;
    }

    return typePower;
}
#else
NAKED
s32 sub_818FFC0(s32 move, s32 species, s32 arg2)
{
    asm_unified("\n\
	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x8\n\
	adds r3, r0, 0\n\
	adds r4, r1, 0\n\
	str r2, [sp]\n\
	movs r6, 0\n\
	movs r2, 0x14\n\
	cmp r3, 0\n\
	beq _0818FFF0\n\
	ldr r0, =0x0000ffff\n\
	cmp r3, r0\n\
	beq _0818FFF0\n\
	ldr r0, =gBattleMoves\n\
	lsls r1, r3, 1\n\
	adds r1, r3\n\
	lsls r1, 2\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3, 0x1]\n\
	cmp r0, 0\n\
	bne _0818FFFC\n\
_0818FFF0:\n\
	movs r0, 0\n\
	b _08190156\n\
	.pool\n\
_0818FFFC:\n\
	ldr r1, =gBaseStats\n\
	lsls r0, r4, 3\n\
	subs r0, r4\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x6]\n\
	mov r10, r1\n\
	ldrb r1, [r0, 0x7]\n\
	mov r9, r1\n\
	ldrb r0, [r0, 0x16]\n\
	mov r8, r0\n\
	ldrb r3, [r3, 0x2]\n\
	str r3, [sp, 0x4]\n\
	cmp r0, 0x1A\n\
	bne _0819002C\n\
	cmp r3, 0x4\n\
	bne _0819002C\n\
	ldr r0, [sp]\n\
	cmp r0, 0x1\n\
	bne _081900AA\n\
	movs r2, 0x8\n\
	b _081900A4\n\
	.pool\n\
_0819002C:\n\
	ldr r0, =gTypeEffectiveness\n\
	adds r1, r6, r0\n\
	ldrb r0, [r1]\n\
	ldr r7, =gTypeEffectiveness\n\
	cmp r0, 0xFF\n\
	beq _081900A4\n\
	adds r4, r1, 0\n\
_0819003A:\n\
	ldrb r0, [r4]\n\
	cmp r0, 0xFE\n\
	beq _08190096\n\
	ldrb r0, [r4]\n\
	ldr r1, [sp, 0x4]\n\
	cmp r0, r1\n\
	bne _08190096\n\
	ldrb r0, [r4, 0x1]\n\
	adds r5, r6, 0x1\n\
	cmp r0, r10\n\
	bne _0819006C\n\
	adds r1, r6, 0x2\n\
	mov r0, r8\n\
	cmp r0, 0x19\n\
	bne _0819005E\n\
	ldrb r0, [r4, 0x2]\n\
	cmp r0, 0x28\n\
	bne _0819006C\n\
_0819005E:\n\
	adds r0, r1, r7\n\
	ldrb r0, [r0]\n\
	muls r0, r2\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	adds r2, r0, 0\n\
_0819006C:\n\
	adds r0, r5, r7\n\
	ldrb r0, [r0]\n\
	cmp r0, r9\n\
	bne _08190096\n\
	cmp r10, r9\n\
	beq _08190096\n\
	adds r1, r6, 0x2\n\
	mov r0, r8\n\
	cmp r0, 0x19\n\
	bne _08190088\n\
	adds r0, r1, r7\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x28\n\
	bne _08190096\n\
_08190088:\n\
	adds r0, r1, r7\n\
	ldrb r0, [r0]\n\
	muls r0, r2\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	adds r2, r0, 0\n\
_08190096:\n\
	adds r4, 0x3\n\
	adds r6, 0x3\n\
	ldr r1, =gTypeEffectiveness\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, 0xFF\n\
	bne _0819003A\n\
_081900A4:\n\
	ldr r0, [sp]\n\
	cmp r0, 0x1\n\
	beq _081900E0\n\
_081900AA:\n\
	ldr r1, [sp]\n\
	cmp r1, 0x1\n\
	bgt _081900BC\n\
	cmp r1, 0\n\
	beq _081900C4\n\
	b _08190154\n\
	.pool\n\
_081900BC:\n\
	ldr r0, [sp]\n\
	cmp r0, 0x2\n\
	beq _08190114\n\
	b _08190154\n\
_081900C4:\n\
	cmp r2, 0xA\n\
	beq _08190146\n\
	cmp r2, 0xA\n\
	ble _08190146\n\
	cmp r2, 0x28\n\
	beq _0819014A\n\
	cmp r2, 0x28\n\
	bgt _081900DA\n\
	cmp r2, 0x14\n\
	beq _08190104\n\
	b _08190146\n\
_081900DA:\n\
	cmp r2, 0x50\n\
	bne _08190146\n\
	b _08190100\n\
_081900E0:\n\
	cmp r2, 0xA\n\
	beq _08190104\n\
	cmp r2, 0xA\n\
	bgt _081900F2\n\
	cmp r2, 0\n\
	beq _08190100\n\
	cmp r2, 0x5\n\
	beq _0819014A\n\
	b _08190146\n\
_081900F2:\n\
	cmp r2, 0x28\n\
	beq _08190108\n\
	cmp r2, 0x28\n\
	ble _08190146\n\
	cmp r2, 0x50\n\
	beq _0819010E\n\
	b _08190146\n\
_08190100:\n\
	movs r2, 0x8\n\
	b _08190154\n\
_08190104:\n\
	movs r2, 0x2\n\
	b _08190154\n\
_08190108:\n\
	movs r2, 0x2\n\
	negs r2, r2\n\
	b _08190154\n\
_0819010E:\n\
	movs r2, 0x4\n\
	negs r2, r2\n\
	b _08190154\n\
_08190114:\n\
	cmp r2, 0xA\n\
	beq _08190146\n\
	cmp r2, 0xA\n\
	bgt _08190126\n\
	cmp r2, 0\n\
	beq _0819013A\n\
	cmp r2, 0x5\n\
	beq _08190140\n\
	b _08190146\n\
_08190126:\n\
	cmp r2, 0x28\n\
	beq _0819014E\n\
	cmp r2, 0x28\n\
	bgt _08190134\n\
	cmp r2, 0x14\n\
	beq _0819014A\n\
	b _08190146\n\
_08190134:\n\
	cmp r2, 0x50\n\
	beq _08190152\n\
	b _08190146\n\
_0819013A:\n\
	movs r2, 0x10\n\
	negs r2, r2\n\
	b _08190154\n\
_08190140:\n\
	movs r2, 0x8\n\
	negs r2, r2\n\
	b _08190154\n\
_08190146:\n\
	movs r2, 0\n\
	b _08190154\n\
_0819014A:\n\
	movs r2, 0x4\n\
	b _08190154\n\
_0819014E:\n\
	movs r2, 0xC\n\
	b _08190154\n\
_08190152:\n\
	movs r2, 0x14\n\
_08190154:\n\
	adds r0, r2, 0\n\
_08190156:\n\
	add sp, 0x8\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
                ");
}
#endif // NONMATCHING

u8 GetDomeTrainerMonIvs(u16 trainerId)
{
    u8 fixedIv;
    if (trainerId <= 99)
        fixedIv = 3;
    else if (trainerId <= 119)
        fixedIv = 6;
    else if (trainerId <= 139)
        fixedIv = 9;
    else if (trainerId <= 159)
        fixedIv = 12;
    else if (trainerId <= 179)
        fixedIv = 15;
    else if (trainerId <= 199)
        fixedIv = 18;
    else if (trainerId <= 219)
        fixedIv = 21;
    else
        fixedIv = 31;

    return fixedIv;
}

s32 TournamentIdOfOpponent(s32 roundId, s32 trainerId)
{
    s32 i, j, val;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == trainerId)
            break;
    }

    if (roundId != DOME_ROUND1)
    {
        if (roundId == DOME_FINAL)
            val = gUnknown_0860D10C[i][roundId] + 8;
        else
            val = gUnknown_0860D10C[i][roundId] + 4;

        for (j = gUnknown_0860D10C[i][roundId]; j < val; j++)
        {
            if (gUnknown_0860D14C[j] != i && !gSaveBlock2Ptr->frontier.domeTrainers[gUnknown_0860D14C[j]].unk1)
                break;
        }

        if (j != val)
            return gUnknown_0860D14C[j];
        else
            return 0xFF;
    }
    else
    {
        if (!gSaveBlock2Ptr->frontier.domeTrainers[gUnknown_0860D10C[i][0]].unk1)
            return gUnknown_0860D10C[i][0];
        else
            return 0xFF;
    }
}

void sub_8190298(void)
{
    gTrainerBattleOpponent_A = TrainerIdOfPlayerOpponent();
}

u16 TrainerIdOfPlayerOpponent(void)
{
    return gSaveBlock2Ptr->frontier.domeTrainers[TournamentIdOfOpponent(gSaveBlock2Ptr->frontier.field_CB2, TRAINER_PLAYER)].trainerId;
}

void sub_81902E4(void)
{
    sub_8162614(gTrainerBattleOpponent_A, 0);
}

void sub_81902F8(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

void sub_819033C(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u8 battleMode = VarGet(VAR_0x40CE);

    if (gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode] < 999)
        gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode]++;
    if (gSaveBlock2Ptr->frontier.field_D1C[battleMode][lvlMode] < 999)
        gSaveBlock2Ptr->frontier.field_D1C[battleMode][lvlMode]++;

    if (gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.field_D14[battleMode][lvlMode])
        gSaveBlock2Ptr->frontier.field_D14[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.field_D0C[battleMode][lvlMode];
}

void ShowDomeOpponentInfo(void)
{
    u8 taskId = CreateTask(sub_8190400, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = TrainerIdToTournamentId(TrainerIdOfPlayerOpponent());
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;

    SetMainCallback2(sub_8194B54);
}

void sub_8190400(u8 taskId)
{
    s32 i;
    s32 r5 = gTasks[taskId].data[1];
    s32 r9 = gTasks[taskId].data[2];
    s32 r7 = gTasks[taskId].data[3];

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        EnableInterrupts(INTR_FLAG_VBLANK);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_0860CE84, ARRAY_COUNT(gUnknown_0860CE84));
        InitWindows(gUnknown_0860CEB4);
        DeactivateAllTextPrinters();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        if (r9 == 2)
            gBattle_BG2_X = 0, gBattle_BG2_Y = 0;
        else
            gBattle_BG2_X = 0, gBattle_BG2_Y = 160;

        gTasks[taskId].data[0]++;
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D83D50, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D84970, 0x2000, 0, 1);
        DecompressAndLoadBgGfxUsingHeap(3, gUnknown_08D84F00, 0x800, 0, 1);
        LoadCompressedObjectPic(&gUnknown_0860CF50);
        LoadCompressedPalette(gUnknown_08D85358, 0, 0x200);
        LoadCompressedPalette(gUnknown_08D85444, 0x100, 0x200);
        LoadCompressedPalette(gUnknown_08D85600, 0xF0, 0x20);
        if (r9 == 2)
            LoadCompressedPalette(gUnknown_08D854C8, 0x50, 0x20);
        CpuFill32(0, gPlttBufferFaded, 0x400);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetVBlankCallback(sub_8194B70);
        gUnknown_0203CD78 = AllocZeroed(sizeof(*gUnknown_0203CD78));
        for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            gUnknown_0203CD78->arr[i] |= 0xFF;
        LoadMonIconPalettes();
        i = CreateTask(sub_8190CD4, 0);
        gTasks[i].data[0] = 0;
        gTasks[i].data[2] = 0;
        gTasks[i].data[3] = r9;
        gTasks[i].data[4] = r7;
        if (r9 == 2)
        {
            sub_819314C(0, r5);
            gUnknown_0203CD78->unk_10 = 1;
        }
        else
        {
            sub_81924E0(0, r5);
        }
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        if (r9 != 0)
        {
            r7 = CreateSprite(&gUnknown_0860D068, 120, 4, 0);
            StartSpriteAnim(&gSprites[r7], 0);
            gSprites[r7].data[0] = i;

            r7 = CreateSprite(&gUnknown_0860D068, 120, 156, 0);
            StartSpriteAnim(&gSprites[r7], 1);
            gSprites[r7].data[0] = i;

            r7 = CreateSprite(&gUnknown_0860D050, 6, 80, 0);
            StartSpriteAnim(&gSprites[r7], 0);
            gSprites[r7].data[0] = i;
            gSprites[r7].data[1] = 0;
            if (r9 == 1)
                gSprites[r7].invisible = 1;

            r7 = CreateSprite(&gUnknown_0860D050, 234, 80, 0);
            StartSpriteAnim(&gSprites[r7], 1);
            gSprites[r7].data[0] = i;
            gSprites[r7].data[1] = 1;
        }
        DestroyTask(taskId);
        break;
    }
}

void sub_8190790(struct Sprite *sprite)
{
    sprite->pos1.y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y >= -32)
            sprite->invisible = 0;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.y >= 192)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_818D8F0(sprite->data[3]);
        }
    }
}

void sub_81907F8(struct Sprite *sprite)
{
    sprite->pos1.y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y <= 192)
            sprite->invisible = 0;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.y <= -32)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_818D8F0(sprite->data[3]);
        }
    }
}

void sub_8190860(struct Sprite *sprite)
{
    sprite->pos1.x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x >= -32)
            sprite->invisible = 0;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.x >= 272)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_818D8F0(sprite->data[3]);
        }
    }
}

void sub_81908CC(struct Sprite *sprite)
{
    sprite->pos1.x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x <= 272)
            sprite->invisible = 0;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.x <= -32)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_818D8F0(sprite->data[3]);
        }
    }
}

void sub_8190938(struct Sprite *sprite)
{
    if (!sprite->data[3])
        UpdateMonIconFrame(sprite);
}

void sub_8190950(struct Sprite *sprite)
{
    if (!sprite->data[3])
        UpdateMonIconFrame(sprite);
    sprite->pos1.y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y >= -16)
            sprite->invisible = 0;
        if (++sprite->data[1] == 40)
            sprite->callback = sub_8190938;
    }
    else
    {
        if (sprite->pos1.y >= 176)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

void sub_81909CC(struct Sprite *sprite)
{
    if (!sprite->data[3])
        UpdateMonIconFrame(sprite);
    sprite->pos1.y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y <= 176)
            sprite->invisible = 0;
        if (++sprite->data[1] == 40)
            sprite->callback = sub_8190938;
    }
    else
    {
        if (sprite->pos1.y <= -16)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

void sub_8190A48(struct Sprite *sprite)
{
    if (!sprite->data[3])
        UpdateMonIconFrame(sprite);
    sprite->pos1.x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x >= -16)
            sprite->invisible = 0;
        if (++sprite->data[1] == 64)
            sprite->callback = sub_8190938;
    }
    else
    {
        if (sprite->pos1.x >= 256)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

void sub_8190AC4(struct Sprite *sprite)
{
    if (!sprite->data[3])
        UpdateMonIconFrame(sprite);
    sprite->pos1.x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x <= 256)
            sprite->invisible = 0;
        if (++sprite->data[1] == 64)
            sprite->callback = sub_8190938;
    }
    else
    {
        if (sprite->pos1.x <= -16)
        {
            gUnknown_0203CD78->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

void sub_8190B40(struct Sprite *sprite)
{
    s32 taskId1 = sprite->data[0];
    s32 arrId = gTasks[gTasks[taskId1].data[4]].data[1];
    s32 tournmanetTrainerId = gUnknown_0860D080[arrId];
    s32 r12 = gSaveBlock2Ptr->frontier.field_CB2;

    if (gTasks[taskId1].data[3] == 1)
    {
        if (sprite->data[1])
        {
            if ((gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].unk1
                && gUnknown_0203CD78->unk_10 - 1 < gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].unk2))
            {
                sprite->invisible = 0;
            }
            else if (!gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].unk1
                     && gUnknown_0203CD78->unk_10 - 1 < r12)
            {
                sprite->invisible = 0;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = 1;
            }
        }
        else
        {
            if (gUnknown_0203CD78->unk_10 != 0)
            {
                sprite->invisible = 0;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = 1;
            }
        }
    }
    else
    {
        if (sprite->data[1])
        {
            if (gUnknown_0203CD78->unk_10 > 1)
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = 1;
            }
            else
            {
                sprite->invisible = 0;
            }
        }
        else
        {
            if (gUnknown_0203CD78->unk_10 != 0)
            {
                sprite->invisible = 0;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = 1;
            }
        }
    }
}

void sub_8190C6C(struct Sprite *sprite)
{
    s32 taskId1 = sprite->data[0];

    if (gTasks[taskId1].data[3] == 1)
    {
        if (gUnknown_0203CD78->unk_10 != 0)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = 1;
        }
        else
        {
            sprite->invisible = 0;
        }
    }
    else
    {
        if (gUnknown_0203CD78->unk_10 != 1)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = 1;
        }
        else
        {
            sprite->invisible = 0;
        }
    }
}

void sub_8190CD4(u8 taskId)
{
    s32 i;
    s32 var;
    s32 r9 = gTasks[taskId].data[3];
    s32 taskId2 = gTasks[taskId].data[4];
    s32 arg, arg2;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
            gTasks[taskId].data[0] = 1;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        i = sub_819221C(taskId);
        switch (i)
        {
        case 9:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
            gTasks[taskId].data[0] = 8;
            break;
        case 1 ... 8:
            gTasks[taskId].data[5] = i;
            if (gTasks[taskId].data[2] != 0)
                var = 9;
            else
                var = 0;

            for (i = var; i < var + 9; i++)
            {
                CopyWindowToVram(i, 2);
                FillWindowPixelBuffer(i, 0);
            }
            gTasks[taskId].data[0] = 3;
            break;
        case 0:
            break;
        }
        break;
    case 3:
        i = gTasks[taskId].data[5];
        switch (i)
        {
        case 1:
        case 5:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 160;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 160;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == 1)
            {
                if (gUnknown_0203CD78->unk_10 == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    arg = gUnknown_0860D080[gTasks[taskId2].data[1]];
                    sub_81924E0(gTasks[taskId].data[2] | 0x10, arg);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 0;
                    arg = gUnknown_0860D080[gTasks[taskId2].data[1]];
                    sub_81924E0(gTasks[taskId].data[2] | 0x10, arg);
                    gUnknown_0203CD78->unk_10 = 0;
                }
            }
            else
            {
                if (gUnknown_0203CD78->unk_10 == 0)
                {
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(arg2, gUnknown_0203CD78->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    arg = gUnknown_0203CD78->unk_11[0];
                    sub_81924E0(gTasks[taskId].data[2] | 0x10, arg);
                }
                else if (gUnknown_0203CD78->unk_10 == 2)
                {
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(arg2, gUnknown_0203CD78->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    arg = gUnknown_0203CD78->unk_11[1];
                    sub_81924E0(gTasks[taskId].data[2] | 0x10, arg);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 160;
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_819314C(gTasks[taskId].data[2] | 0x10, arg2);
                }
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190790;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190950;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190790;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190950;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 4;
            gTasks[taskId].data[5] = 0;
            break;
        case 2:
        case 6:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = -160;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = -160;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == 2)
            {
                if (gUnknown_0203CD78->unk_10 == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    arg = gUnknown_0860D080[gTasks[taskId2].data[1]];
                    sub_81924E0(gTasks[taskId].data[2] | 4, arg);
                }
                else
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 0;
                    arg = gUnknown_0860D080[gTasks[taskId2].data[1]];
                    sub_81924E0(gTasks[taskId].data[2] | 4, arg);
                    gUnknown_0203CD78->unk_10 = 0;
                }
            }
            else
            {
                if (gUnknown_0203CD78->unk_10 == 0)
                {
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(arg2, gUnknown_0203CD78->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    arg = gUnknown_0203CD78->unk_11[0];
                    sub_81924E0(gTasks[taskId].data[2] | 4, arg);
                }
                else if (gUnknown_0203CD78->unk_10 == 2)
                {
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(arg2, gUnknown_0203CD78->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    arg = gUnknown_0203CD78->unk_11[1];
                    sub_81924E0(gTasks[taskId].data[2] | 4, arg);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 0;
                    arg2 = gTasks[taskId2].data[1] - 16;
                    sub_819314C(gTasks[taskId].data[2] | 4, arg2);
                }
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81907F8;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81909CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81907F8;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81909CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 5;
            gTasks[taskId].data[5] = 0;
            break;
        case 3:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = 256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (gUnknown_0203CD78->unk_10 == 0)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                arg = gUnknown_0860D080[gTasks[taskId2].data[1]];
                sub_81924E0(gTasks[taskId].data[2] | 8, arg);
            }
            else
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 0;
                arg = gUnknown_0860D15C[(gTasks[taskId2].data[1] * 4) + (gUnknown_0203CD78->unk_10 - 1)];
                sub_819314C(gTasks[taskId].data[2] | 8, arg);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190860;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190A48;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190860;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190A48;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 6;
            gTasks[taskId].data[5] = 0;
            break;
        case 7:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = 256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (gUnknown_0203CD78->unk_10 == 0)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                arg = gUnknown_0203CD78->unk_11[0];
                sub_81924E0(gTasks[taskId].data[2] | 8, arg);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
                arg2 = gTasks[taskId2].data[1] - 16;
                sub_819314C(gTasks[taskId].data[2] | 8, arg2);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190860;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190A48;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190860;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190A48;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 6;
            gTasks[taskId].data[5] = 0;
            break;
        case 4:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (gUnknown_0203CD78->unk_10 == 1)
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 0;
            }
            arg = gUnknown_0860D15C[(gUnknown_0203CD78->unk_10 - 1) + (gTasks[taskId2].data[1] * 4)];
            sub_819314C(gTasks[taskId].data[2] | 2, arg);

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81908CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190AC4;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81908CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190AC4;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 7;
            gTasks[taskId].data[5] = 0;
            break;
        case 8:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (gUnknown_0203CD78->unk_10 == 2)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                arg = gUnknown_0203CD78->unk_11[1];
                sub_81924E0(gTasks[taskId].data[2] | 2, arg);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
                arg2 = gTasks[taskId2].data[1] - 16;
                sub_819314C(gTasks[taskId].data[2] | 2, arg2);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81908CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190AC4;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_81908CC;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                        gSprites[gUnknown_0203CD78->arr[i]].data[3] = gUnknown_0203CD78->arr[i];
                    }
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                    {
                        gSprites[gUnknown_0203CD78->arr[i]].callback = sub_8190AC4;
                        gSprites[gUnknown_0203CD78->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[gUnknown_0203CD78->arr[i]].data[1] = 0;
                        gSprites[gUnknown_0203CD78->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 7;
            gTasks[taskId].data[5] = 0;
            break;
        }
        break;
    case 4:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y -= 4;
            gBattle_BG1_Y -= 4;
            gBattle_BG2_Y -= 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 5:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y += 4;
            gBattle_BG1_Y += 4;
            gBattle_BG2_Y += 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 6:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X -= 4;
            gBattle_BG1_X -= 4;
            gBattle_BG2_X -= 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 7:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X += 4;
            gBattle_BG1_X += 4;
            gBattle_BG2_X += 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 8:
        if (!gPaletteFade.active)
        {
            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                        sub_818D8F0(gUnknown_0203CD78->arr[i]);
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                        sub_80D2EF8(&gSprites[gUnknown_0203CD78->arr[i]]);
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                        sub_818D8F0(gUnknown_0203CD78->arr[i]);
                }
                else
                {
                    if (gUnknown_0203CD78->arr[i] != 0xFF)
                        sub_80D2EF8(&gSprites[gUnknown_0203CD78->arr[i]]);
                }
            }

            FreeMonIconPalettes();
            FREE_AND_SET_NULL(gUnknown_0203CD78);
            FreeAllWindowBuffers();
            if (r9 == 0)
            {
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            }
            else
            {
                i = CreateTask(sub_8194220, 0);
                gTasks[i].data[0] = 0;
                gTasks[i].data[1] = 0;
                gTasks[i].data[2] = 3;
                gTasks[i].data[3] = gTasks[taskId].data[4];
                gTasks[i].data[4] = gTasks[taskId2].data[6];
            }
            DestroyTask(taskId);
        }
        break;
    }
}

u8 sub_819221C(u8 taskId)
{
    u8 retVal = 0;
    s32 taskId2 = gTasks[taskId].data[4];
    s32 r5 = gTasks[taskId2].data[1];
    u8 r10 = gUnknown_0860D080[r5];
    u16 roundId = gSaveBlock2Ptr->frontier.field_CB2;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        retVal = 9;

    if (gTasks[taskId].data[3] != 0)
    {
        if (gTasks[taskId].data[3] == 1)
        {
            if (gMain.newKeys & DPAD_UP && gUnknown_0203CD78->unk_10 == 0)
            {
                if (r5 == 0)
                    r5 = 15;
                else
                    r5--;
                retVal = 1;
            }
            else if (gMain.newKeys & DPAD_DOWN && gUnknown_0203CD78->unk_10 != 0)
            {
                if (r5 == 15)
                    r5 = 0;
                else
                    r5++;
                retVal = 2;
            }
            else if (gMain.newKeys & DPAD_LEFT && gUnknown_0203CD78->unk_10 != 0)
            {
                gUnknown_0203CD78->unk_10--;
                retVal = 3;
            }
            else if (gMain.newKeys & DPAD_RIGHT)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[r10].unk1 && gUnknown_0203CD78->unk_10 - 1 < gSaveBlock2Ptr->frontier.domeTrainers[r10].unk2)
                {
                    gUnknown_0203CD78->unk_10++;
                    retVal = 4;
                }
                if (!gSaveBlock2Ptr->frontier.domeTrainers[r10].unk1 && gUnknown_0203CD78->unk_10 - 1 < roundId)
                {
                    gUnknown_0203CD78->unk_10++;
                    retVal = 4;
                }
            }

            if (retVal == 9)
            {
                if (gUnknown_0203CD78->unk_10 != 0)
                    gTasks[taskId2].data[1] = gUnknown_0860D1A0[(r5 / 2) * 4 + (gUnknown_0203CD78->unk_10 - 1)];
                else
                    gTasks[taskId2].data[1] = r5;
            }
        }
        else
        {
            if (gMain.newKeys & DPAD_UP && gUnknown_0203CD78->unk_10 == 1)
            {
                if (r5 == 16)
                    r5 = gUnknown_0860D19C[roundId];
                else
                    r5--;
                retVal = 5;
            }
            else if (gMain.newKeys & DPAD_DOWN && gUnknown_0203CD78->unk_10 == 1)
            {
                if (r5 == gUnknown_0860D19C[roundId])
                    r5 = 16;
                else
                    r5++;
                retVal = 6;
            }
            else if (gMain.newKeys & DPAD_LEFT && gUnknown_0203CD78->unk_10 != 0)
            {
                retVal = 7;
                gUnknown_0203CD78->unk_10--;
            }
            else if (gMain.newKeys & DPAD_RIGHT && (gUnknown_0203CD78->unk_10 == 0 || gUnknown_0203CD78->unk_10 == 1))
            {
                retVal = 8;
                gUnknown_0203CD78->unk_10++;
            }

            if (retVal == 9)
            {
                if (gUnknown_0203CD78->unk_10 == 0)
                    gTasks[taskId2].data[1] = gUnknown_0860D1C0[gUnknown_0203CD78->unk_11[0]];
                else if (gUnknown_0203CD78->unk_10 == 2)
                    gTasks[taskId2].data[1] = gUnknown_0860D1C0[gUnknown_0203CD78->unk_11[1]];
                else
                    gTasks[taskId2].data[1] = r5;
            }
        }

        if (retVal != 0 && retVal != 9)
        {
            PlaySE(SE_SELECT);
            gTasks[taskId2].data[1] = r5;
            gTasks[taskId].data[2] ^= 1;
        }
    }

    return retVal;
}

#include "global.h"
#include "battle_pike.h"
#include "event_data.h"
#include "frontier_util.h"
#include "fieldmap.h"
#include "save.h"
#include "battle.h"
#include "random.h"
#include "task.h"
#include "battle_tower.h"
#include "party_menu.h"
#include "malloc.h"
#include "palette.h"
#include "script.h"
#include "battle_setup.h"
#include "constants/event_objects.h"
#include "constants/battle_frontier.h"
#include "constants/abilities.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "constants/species.h"

#define PIKE_ROOM_SINGLE_BATTLE 0
#define PIKE_ROOM_HEAL_FULL 1
#define PIKE_ROOM_NPC 2
#define PIKE_ROOM_STATUS 3
#define PIKE_ROOM_HEAL_PART 4
#define PIKE_ROOM_WILD_MONS 5
#define PIKE_ROOM_HARD_BATTLE 6
#define PIKE_ROOM_DOUBLE_BATTLE 7
#define PIKE_ROOM_BRAIN 8

// For the room with a status effect.
#define PIKE_STATUS_KIRLIA 0
#define PIKE_STATUS_DUSCLOPS 1

struct Unk0861231C
{
    u16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
};

struct PikeWildMon
{
    u16 species;
    u8 levelDelta;
    u16 moves[4];
};

extern const struct Unk0861231C gUnknown_0861231C[];
extern const struct PikeWildMon *const *const gUnknown_08612314[2];
extern const u16 gUnknown_086123E4[][6];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];

// IWRAM bss
static IWRAM_DATA u8 sRoomType;
static IWRAM_DATA u8 sStatusMon;
static IWRAM_DATA bool8 sUnknown_0300128E;
static IWRAM_DATA u32 sStatusFlags;
static IWRAM_DATA u8 sUnknown_03001294;

// This file's functions.
static void sub_81A705C(void);
static void sub_81A7140(void);
static void sub_81A7248(void);
static void sub_81A73B8(void);
static void sub_81A7070(void);
static void sub_81A73EC(void);
static void sub_81A7400(void);
static void sub_81A740C(void);
static void sub_81A7418(void);
static void nullsub_76(void);
static void nullsub_124(void);
static void sub_81A7468(void);
static void sub_81A74CC(void);
static void sub_81A74E0(void);
static void sub_81A7508(void);
static void sub_81A7580(void);
static void sub_81A8090(void);
static void sub_81A80DC(void);
static void sub_81A825C(void);
static void sub_81A827C(void);
static void sub_81A84B4(void);
static void sub_81A84EC(void);
static void sub_81A863C(void);
static void sub_81A8658(void);
static void sub_81A869C(void);
static void sub_81A86C0(void);
static void sub_81A8794(void);
static void sub_81A87E8(void);
static void sub_81A8830(void);
static u8 GetNextRoomType(void);
static void PrepareOneTrainer(bool8 difficult);
static u16 sub_81A7B58(void);
static void PrepareTwoTrainers(void);
static void TryHealMons(u8 healCount);
static void sub_81A7EE4(u8 taskId);
static bool8 AtLeastTwoAliveMons(void);
static u8 SpeciesToPikeMonId(u16 species);
static bool8 CanEncounterWildMon(u8 monLevel);
static u8 sub_81A8590(u8);
static bool8 sub_81A7D8C(struct Task *task);
static bool8 sub_81A7DE8(struct Task *task);

// Const rom data.
static const u8 gUnknown_086125DC[][4] =
{
    {0x23, 0x46, 0x23, 0x01},
    {0x04, 0x09, 0x05, 0x00},
    {0x15, 0x2a, 0x15, 0x01},
    {0x1c, 0x38, 0x1c, 0x01},
    {0x15, 0x2a, 0x15, 0x01},
    {0x1c, 0x8c, 0x38, 0x01},
    {0x15, 0x46, 0x23, 0x00},
};

static void (* const sBattlePikeFunctions[])(void) =
{
    sub_81A705C,
    sub_81A7140,
    sub_81A7248,
    sub_81A73B8,
    sub_81A7070,
    sub_81A73EC,
    sub_81A7400,
    sub_81A740C,
    sub_81A7418,
    nullsub_76,
    nullsub_124,
    sub_81A7468,
    sub_81A74CC,
    sub_81A74E0,
    sub_81A7508,
    sub_81A7580,
    sub_81A8090,
    sub_81A80DC,
    sub_81A825C,
    sub_81A827C,
    sub_81A84B4,
    sub_81A84EC,
    sub_81A863C,
    sub_81A8658,
    sub_81A869C,
    sub_81A86C0,
    sub_81A8794,
    sub_81A87E8,
    sub_81A8830
};

static const u8 gUnknown_0861266C[] = {3, 3, 1, 0, 0, 2, 2, 1, 4};

static const u8 gUnknown_08612675[][3] =
{
    {2, 1, 0},
    {2, 0, 1},
    {1, 2, 0},
    {1, 0, 2},
    {0, 2, 1},
    {0, 1, 2},
};

static bool8 (* const gUnknown_08612688[])(struct Task *) =
{
    sub_81A7D8C, sub_81A7DE8
};

static const u32 gUnknown_08612690[] = {0x400, 0x800};

// code
void CallBattlePikeFunction(void)
{
    sBattlePikeFunctions[gSpecialVar_0x8004]();
}

static void sub_81A705C(void)
{
    u8 roomType = GetNextRoomType();
    sRoomType = roomType;
}

static void sub_81A7070(void)
{
    bool32 setPerson1, setPerson2;
    u32 person1;
    u16 person2;

    VarSet(VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_LINK_RECEPTIONIST);
    VarSet(VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_DUSCLOPS);
    setPerson1 = TRUE;
    setPerson2 = FALSE;
    person1 = 0;
    person2 = 0;

    switch (sRoomType)
    {
    case PIKE_ROOM_SINGLE_BATTLE:
        PrepareOneTrainer(FALSE);
        setPerson1 = FALSE;
        break;
    case PIKE_ROOM_HEAL_FULL:
        person1 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        break;
    case PIKE_ROOM_NPC:
        person1 = (u8)(sub_81A7B58());
        break;
    case PIKE_ROOM_STATUS:
        person1 = EVENT_OBJ_GFX_GENTLEMAN;
        if (sStatusMon == PIKE_STATUS_DUSCLOPS)
            person2 = EVENT_OBJ_GFX_DUSCLOPS;
        else
            person2 = EVENT_OBJ_GFX_KIRLIA;
        setPerson2 = TRUE;
        break;
    case PIKE_ROOM_HEAL_PART:
        person1 = EVENT_OBJ_GFX_GENTLEMAN;
        break;
    case PIKE_ROOM_WILD_MONS:
        setPerson1 = FALSE;
        break;
    case PIKE_ROOM_HARD_BATTLE:
        PrepareOneTrainer(TRUE);
        person2 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        setPerson1 = FALSE;
        setPerson2 = TRUE;
        break;
    case PIKE_ROOM_DOUBLE_BATTLE:
        PrepareTwoTrainers();
        setPerson1 = FALSE;
        break;
    case PIKE_ROOM_BRAIN:
        SetFrontierBrainEventObjGfx(FRONTIER_FACILITY_PIKE);
        person2 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        setPerson1 = FALSE;
        setPerson2 = TRUE;
        break;
    default:
        return;
    }

    if (setPerson1 == TRUE)
        VarSet(VAR_OBJ_GFX_ID_0, person1);
    if (setPerson2 == TRUE)
        VarSet(VAR_OBJ_GFX_ID_1, person2);
}

static void sub_81A7140(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E02;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 4:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x800;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x400;
        break;
    }
}

static void sub_81A7248(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E02 = gSpecialVar_0x8006;
        break;
    case 1:
        if (gSpecialVar_0x8006 <= 9999)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006 <= 9999 && gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] < gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 3:
        if (gSpecialVar_0x8006 <= 9999)
            gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 4:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x800;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x800);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x400;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x400);
        }
        break;
    }
}

static void sub_81A73B8(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum >= 15)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static void sub_81A73EC(void)
{
    gSpecialVar_Result = sRoomType;
}

static void sub_81A7400(void)
{
    sUnknown_0300128E = TRUE;
}

static void sub_81A740C(void)
{
    sUnknown_0300128E = FALSE;
}

static void sub_81A7418(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    save_serialize_map();
    TrySavingData(SAVE_LINK);
}

static void nullsub_76(void)
{

}

static void nullsub_124(void)
{

}

static void sub_81A7468(void)
{
    switch (sStatusFlags)
    {
    case STATUS1_FREEZE:
        gSpecialVar_Result = 0;
        break;
    case STATUS1_BURN:
        gSpecialVar_Result = 1;
        break;
    case STATUS1_TOXIC_POISON:
        gSpecialVar_Result = 2;
        break;
    case STATUS1_PARALYSIS:
        gSpecialVar_Result = 3;
        break;
    case STATUS1_SLEEP:
        gSpecialVar_Result = 4;
        break;
    }
}

static void sub_81A74CC(void)
{
    gSpecialVar_Result = sStatusMon;
}

static void sub_81A74E0(void)
{
    u16 toHeal = (Random() % 2) + 1;
    TryHealMons(toHeal);
    gSpecialVar_Result = toHeal;
}

static void sub_81A7508(void)
{
    s32 id;

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        id = gUnknown_0861231C[sUnknown_03001294].unk2;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 10)
        id = gUnknown_0861231C[sUnknown_03001294].unk3;
    else
        id = gUnknown_0861231C[sUnknown_03001294].unk4;

    FrontierSpeechToString(gUnknown_086123E4[id]);
}

static void sub_81A7580(void)
{
    CreateTask(sub_81A7EE4, 2);
}

static void HealMon(struct Pokemon *mon)
{
    u8 i;
    u16 hp;
    u8 ppBonuses;
    u8 data[4];

    for (i = 0; i < 4; i++)
        data[i] = 0;

    hp = GetMonData(mon, MON_DATA_MAX_HP);
    data[0] = hp;
    data[1] = hp >> 8;
    SetMonData(mon, MON_DATA_HP, data);

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    for (i = 0; i < 4; i++)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + i);
        data[0] = CalculatePPWithBonus(move, ppBonuses, i);
        SetMonData(mon, MON_DATA_PP1 + i, data);
    }

    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    SetMonData(mon, MON_DATA_STATUS, data);
}

static bool8 DoesAbilityPreventStatus(struct Pokemon *mon, u32 status)
{
    u8 ability = GetMonAbility(mon);
    bool8 ret = FALSE;

    switch (status)
    {
    case STATUS1_FREEZE:
        if (ability == ABILITY_MAGMA_ARMOR)
            ret = TRUE;
        break;
    case STATUS1_BURN:
        if (ability == ABILITY_WATER_VEIL)
            ret = TRUE;
        break;
    case STATUS1_PARALYSIS:
        if (ability == ABILITY_LIMBER)
            ret = TRUE;
        break;
    case STATUS1_SLEEP:
        if (ability == ABILITY_INSOMNIA || ability == ABILITY_VITAL_SPIRIT)
            ret = TRUE;
        break;
    case STATUS1_TOXIC_POISON:
        if (ability == ABILITY_IMMUNITY)
            ret = TRUE;
        break;
    }
    return ret;
}

static bool8 DoesTypePreventStatus(u16 species, u32 status)
{
    bool8 ret = FALSE;

    switch (status)
    {
    case STATUS1_TOXIC_POISON:
        if (gBaseStats[species].type1 == TYPE_STEEL || gBaseStats[species].type1 == TYPE_POISON
            || gBaseStats[species].type2 == TYPE_STEEL || gBaseStats[species].type2 == TYPE_POISON)
            ret = TRUE;
        break;
    case STATUS1_FREEZE:
        if (gBaseStats[species].type1 == TYPE_ICE || gBaseStats[species].type2 == TYPE_ICE)
            ret = TRUE;
        break;
    case STATUS1_PARALYSIS:
        if (gBaseStats[species].type1 == TYPE_GROUND || gBaseStats[species].type1 == TYPE_ELECTRIC
            || gBaseStats[species].type2 == TYPE_GROUND || gBaseStats[species].type2 == TYPE_ELECTRIC)
            ret = TRUE;
        break;
    case STATUS1_BURN:
        if (gBaseStats[species].type1 == TYPE_FIRE || gBaseStats[species].type2 == TYPE_FIRE)
            ret = TRUE;
        break;
    case STATUS1_SLEEP:
        break;
    }
    return ret;
}

static bool8 TryInflictRandomStatus(void)
{
    u8 j, i;
    u8 count;
    u8 indices[3];
    u32 status;
    u16 species;
    bool8 statusChosen;
    struct Pokemon *mon;

    for (i = 0; i < 3; i++)
        indices[i] = i;
    for (j = 0; j < 10; j++)
    {
        u8 temp, id;

        i = Random() % 3;
        id = Random() % 3;
        SWAP(indices[i], indices[id], temp);
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        count = 1;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 9)
        count = 2;
    else
        count = 3;

    status = 0;
    do
    {
        u8 rand;

        statusChosen = FALSE;
        rand = Random() % 100;

        if (rand < 35)
            sStatusFlags = STATUS1_TOXIC_POISON;
        else if (rand < 60)
            sStatusFlags = STATUS1_FREEZE;
        else if (rand < 80)
            sStatusFlags = STATUS1_PARALYSIS;
        else if (rand < 90)
            sStatusFlags = STATUS1_SLEEP;
        else
            sStatusFlags = STATUS1_BURN;

        if (status != sStatusFlags)
        {
            status = sStatusFlags;
            j = 0;
            for (i = 0; i < 3; i++)
            {
                mon = &gPlayerParty[indices[i]];
                if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
                    && GetMonData(mon, MON_DATA_HP) != 0)
                {
                    j++;
                    species = GetMonData(mon, MON_DATA_SPECIES);
                    if (!DoesTypePreventStatus(species, sStatusFlags))
                    {
                        statusChosen = TRUE;
                        break;
                    }
                }
                if (j == count)
                    break;
            }
            if (j == 0)
                return FALSE;
        }
    } while (!statusChosen);

    switch (sStatusFlags)
    {
    case STATUS1_FREEZE:
        sStatusMon = PIKE_STATUS_DUSCLOPS;
        break;
    case STATUS1_BURN:
        if (Random() % 2 != 0)
            sStatusMon = PIKE_STATUS_DUSCLOPS;
        else
            sStatusMon = PIKE_STATUS_KIRLIA;
        break;
    case STATUS1_PARALYSIS:
    case STATUS1_SLEEP:
    case STATUS1_TOXIC_POISON:
    default:
        sStatusMon = PIKE_STATUS_KIRLIA;
        break;
    }

    j = 0;
    for (i = 0; i < 3; i++)
    {
        mon = &gPlayerParty[indices[i]];
        if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
            && GetMonData(mon, MON_DATA_HP) != 0)
        {
            j++;
            species = GetMonData(mon, MON_DATA_SPECIES);
            if (!DoesAbilityPreventStatus(mon, sStatusFlags) && !DoesTypePreventStatus(species, sStatusFlags))
                SetMonData(mon, MON_DATA_STATUS, &sStatusFlags);
        }
        if (j == count)
            break;
    }

    return TRUE;
}

static bool8 AtLeastOneHealthyMon(void)
{
    u8 i;
    u8 healthyMonsCount;
    u8 count;

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        count = 1;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 9)
        count = 2;
    else
        count = 3;

    healthyMonsCount = 0;
    for (i = 0; i < 3; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
            && GetMonData(mon, MON_DATA_HP) != 0)
        {
            healthyMonsCount++;
        }
        if (healthyMonsCount == count)
            break;
    }

    if (healthyMonsCount == 0)
        return FALSE;
    else
        return TRUE;
}

static u8 GetNextRoomType(void)
{
    u8 sp[8];
    u8 i;
    u8 ret;
    u8 var;
    u8 count;
    u8 *allocated;
    u8 id;

    if (gSaveBlock2Ptr->frontier.field_E10_2 == PIKE_ROOM_BRAIN)
        return gSaveBlock2Ptr->frontier.field_E10_2;
    if (gSpecialVar_0x8007 == gSaveBlock2Ptr->frontier.field_E10_1)
    {
        if (gSaveBlock2Ptr->frontier.field_E10_2 == PIKE_ROOM_STATUS)
            TryInflictRandomStatus();
        return gSaveBlock2Ptr->frontier.field_E10_2;
    }

    for (i = 0; i < 8; i++)
        sp[i] = 0;

    count = 8;
    var = gUnknown_0861266C[gSaveBlock2Ptr->frontier.field_E10_2];
    for (i = 0; i < 8; i++)
    {
        if (gUnknown_0861266C[i] == var)
        {
            sp[i] = 1;
            count--;
        }
    }

    if (sp[7] != 1 && !AtLeastTwoAliveMons())
    {
        sp[7] = 1;
        count--;
    }
    if (sp[3] != 1 && !AtLeastOneHealthyMon())
    {
        sp[3] = 1;
        count--;
    }
    if (gSaveBlock2Ptr->frontier.field_E10_3)
    {
        if (sp[1] != 1)
        {
            sp[1] = 1;
            count--;
        }
        if (sp[4] != 1)
        {
            sp[4] = 1;
            count--;
        }
    }

    allocated = AllocZeroed(count);
    id = 0;
    for (i = 0; i < 8; i++)
    {
        if (sp[i] == 0)
            allocated[id++] = i;
    }

    ret = allocated[Random() % count];
    free(allocated);
    if (ret == PIKE_ROOM_STATUS)
        TryInflictRandomStatus();

    return ret;
}

static u16 sub_81A7B58(void)
{
    sUnknown_03001294 = Random() % 25;
    return gUnknown_0861231C[sUnknown_03001294].unk0;
}

static u8 sub_81A7B84(void)
{
    return sUnknown_0300128E;
}

bool32 TryGenerateBattlePikeWildMon(bool8 checkKeenEyeIntimidate)
{
    s32 i;
    s32 monLevel;
    u8 headerId = GetBattlePikeWildMonHeaderId();
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    const struct PikeWildMon *const *const wildMons = gUnknown_08612314[lvlMode];
    u32 abilityBit;
    s32 pikeMonId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL);
    pikeMonId = SpeciesToPikeMonId(pikeMonId);

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
    {
        monLevel = GetHighestLevelInPlayerParty();
        if (monLevel < 60)
        {
            monLevel = 60;
        }
        else
        {
            monLevel -= wildMons[headerId][pikeMonId].levelDelta;
            if (monLevel < 60)
                monLevel = 60;
        }
    }
    else
    {
        monLevel = 50 - wildMons[headerId][pikeMonId].levelDelta;
    }

    if (checkKeenEyeIntimidate == TRUE && !CanEncounterWildMon(monLevel))
        return FALSE;

    SetMonData(&gEnemyParty[0],
               MON_DATA_EXP,
               &gExperienceTables[gBaseStats[wildMons[headerId][pikeMonId].species].growthRate][monLevel]);

    if (gBaseStats[wildMons[headerId][pikeMonId].species].ability2)
        abilityBit = Random() % 2;
    else
        abilityBit = 0;
    SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &abilityBit);
    for (i = 0; i < 4; i++)
        SetMonMoveSlot(&gEnemyParty[0], wildMons[headerId][pikeMonId].moves[i], i);

    CalculateMonStats(&gEnemyParty[0]);
    return TRUE;
}

u8 GetBattlePikeWildMonHeaderId(void)
{
    u8 headerId;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];

    if (winStreak <= 280)
        headerId = 0;
    else if (winStreak <= 560)
        headerId = 1;
    else if (winStreak <= 840)
        headerId = 2;
    else
        headerId = 3;

    return headerId;
}

static void sub_81A7D54(u8 taskId)
{
    while (gUnknown_08612688[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 sub_81A7D8C(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[1];
        task->data[7] += task->data[4];
        if (task->data[7] > 16)
            task->data[7] = 16;
        BlendPalettes(0xFFFFFFFF, task->data[7], RGB(11, 11, 11));
    }

    if (task->data[7] >= 16)
    {
        task->data[0]++;
        task->data[6] = task->data[2];
    }
    return FALSE;
}

static bool8 sub_81A7DE8(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[2];
        task->data[7] -= task->data[5];
        if (task->data[7] < 0)
            task->data[7] = 0;
        BlendPalettes(0xFFFFFFFF, task->data[7], RGB(11, 11, 11));
    }

    if (task->data[7] == 0)
    {
        if (--task->data[3] == 0)
        {
            DestroyTask(FindTaskIdByFunc(sub_81A7D54));
        }
        else
        {
            task->data[6] = task->data[1];
            task->data[0] = 0;
        }
    }
    return FALSE;
}

static void sub_81A7E60(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4)
{
    u8 taskId = CreateTask(sub_81A7D54, 3);

    gTasks[taskId].data[1] = a0;
    gTasks[taskId].data[2] = a1;
    gTasks[taskId].data[3] = a2;
    gTasks[taskId].data[4] = a3;
    gTasks[taskId].data[5] = a4;
    gTasks[taskId].data[6] = a0;
}

static bool8 sub_81A7EC4(void)
{
    if (FindTaskIdByFunc(sub_81A7D54) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

static void sub_81A7EE4(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[0]++;
        sub_81A7E60(0, 0, 3, 2, 2);
    }
    else
    {
        if (sub_81A7EC4())
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
    }
}

static void TryHealMons(u8 healCount)
{
    u8 j, i, k;
    u8 indices[3];

    if (healCount == 0)
        return;

    for (i = 0; i < 3; i++)
        indices[i] = i;
    for (k = 0; k < 10; k++)
    {
        u8 temp;

        i = Random() % 3;
        j = Random() % 3;
        SWAP(indices[i], indices[j], temp);
    }

    for (i = 0; i < 3; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[indices[i]];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr < max)
        {
            canBeHealed = TRUE;
        }
        else if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) != 0)
        {
            canBeHealed = TRUE;
        }
        else
        {
            u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
            for (j = 0; j < 4; j++)
            {
                u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);
                max = CalculatePPWithBonus(move, ppBonuses, j);
                curr = GetMonData(mon, MON_DATA_PP1 + j);
                if (curr < max)
                {
                    canBeHealed = TRUE;
                    break;
                }
            }
        }

        if (canBeHealed == TRUE)
        {
            HealMon(&gPlayerParty[indices[i]]);
            if (--healCount == 0)
                break;
        }
    }
}

static void sub_81A8090(void)
{
    gSpecialVar_Result = InBattlePike();
}

bool8 InBattlePike(void)
{
    return (gMapHeader.mapLayoutId == 351 || gMapHeader.mapLayoutId == 352
            || gMapHeader.mapLayoutId == 358 || gMapHeader.mapLayoutId == 359);
}

static void sub_81A80DC(void)
{
    u8 i, count, id;
    u8 *allocated;

    gSpecialVar_Result = 0;
    if (sub_81A8590(1))
    {
        gSpecialVar_Result = 1;
        gSaveBlock2Ptr->frontier.field_E10_1 = Random() % 6;
        gSaveBlock2Ptr->frontier.field_E10_2 = PIKE_ROOM_BRAIN;
    }
    else
    {
        gSaveBlock2Ptr->frontier.field_E10_1 = Random() % 3;
        if (gSaveBlock2Ptr->frontier.field_E10_3)
            count = 6;
        else
            count = 8;

        allocated = AllocZeroed(count);
        for (i = 0, id = 0; i < count; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_E10_3)
            {
                if (i != PIKE_ROOM_HEAL_FULL && i != PIKE_ROOM_HEAL_PART)
                    allocated[id++] = i;
            }
            else
            {
                allocated[i] = i;
            }
        }
        gSaveBlock2Ptr->frontier.field_E10_2 = allocated[Random() % count];
        free(allocated);
        if (gSaveBlock2Ptr->frontier.field_E10_2 == PIKE_ROOM_STATUS && !AtLeastOneHealthyMon())
            gSaveBlock2Ptr->frontier.field_E10_2 = PIKE_ROOM_NPC;
        if (gSaveBlock2Ptr->frontier.field_E10_2 == PIKE_ROOM_DOUBLE_BATTLE && !AtLeastTwoAliveMons())
            gSaveBlock2Ptr->frontier.field_E10_2 = PIKE_ROOM_NPC;
    }
}

static void sub_81A825C(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E10_1;
}

static void sub_81A827C(void)
{
    gSpecialVar_Result = gUnknown_0861266C[gSaveBlock2Ptr->frontier.field_E10_2];
}

static void PrepareOneTrainer(bool8 difficult)
{
    s32 i;
    u8 lvlMode;
    u8 battleNum;
    u16 challengeNum;
    u16 trainerId;

    if (!difficult)
        battleNum = 1;
    else
        battleNum = 6;

    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;
    do
    {
        trainerId = sub_8162548(challengeNum, battleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1);

    gTrainerBattleOpponent_A = trainerId;
    gFacilityTrainers = gBattleFrontierTrainers;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 14)
        gSaveBlock2Ptr->frontier.field_CB4[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1] = gTrainerBattleOpponent_A;
}

static void PrepareTwoTrainers(void)
{
    s32 i;
    u16 trainerId;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;

    gFacilityTrainers = gBattleFrontierTrainers;
    do
    {
        trainerId = sub_8162548(challengeNum, 1);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1);

    gTrainerBattleOpponent_A = trainerId;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 14)
        gSaveBlock2Ptr->frontier.field_CB4[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1] = gTrainerBattleOpponent_A;

    do
    {
        trainerId = sub_8162548(challengeNum, 1);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_B = trainerId;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_B, 1);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 14)
        gSaveBlock2Ptr->frontier.field_CB4[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 2] = gTrainerBattleOpponent_B;
}

static void sub_81A84B4(void)
{
    u8 i;

    for (i = 0; i < 14; i++)
        gSaveBlock2Ptr->frontier.field_CB4[i] |= 0xFFFF;
}

static void sub_81A84EC(void)
{
    if (gSpecialVar_0x8005 == 0)
    {
        if (gTrainerBattleOpponent_A < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
    }
    else if (gSpecialVar_0x8005 == 1)
    {
        if (gTrainerBattleOpponent_B < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_B].speechBefore);
    }
}

static bool8 AtLeastTwoAliveMons(void)
{
    struct Pokemon *mon;
    u8 i, countDead;

    mon = &gPlayerParty[0];
    countDead = 0;
    for (i = 0; i < 3; i++, mon++)
    {
        if (GetMonData(mon, MON_DATA_HP) == 0)
            countDead++;
    }

    if (countDead >= 2)
        return FALSE;
    else
        return TRUE;
}

static u8 sub_81A8590(u8 arg0)
{
    u8 symbolsCount;

    u8 var = 5;
    u8 ret = 0;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 wins = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    wins += arg0;
    symbolsCount = GetPlayerSymbolCountForFacility(FRONTIER_FACILITY_PIKE);

    switch (symbolsCount)
    {
    case 0:
    case 1:
        if (wins == gUnknown_086125DC[var][symbolsCount] - gUnknown_086125DC[var][3])
            ret = symbolsCount + 1;
        break;
    case 2:
    default:
        if (wins == gUnknown_086125DC[var][0] - gUnknown_086125DC[var][3])
            ret = 3;
        else if (wins == gUnknown_086125DC[var][1] - gUnknown_086125DC[var][3]
                 || (wins > gUnknown_086125DC[var][1]
                     && (wins - gUnknown_086125DC[var][1] + gUnknown_086125DC[var][3]) % gUnknown_086125DC[var][2] == 0))
            ret = 4;
        break;
    }

    return ret;
}

static void sub_81A863C(void)
{
    gSpecialVar_Result = sub_81A8590(0);
}

static void sub_81A8658(void)
{
    u8 toHealCount = gUnknown_08612675[gSaveBlock2Ptr->frontier.field_E10_1][gSpecialVar_0x8007];

    TryHealMons(toHealCount);
    gSpecialVar_Result = toHealCount;
}

static void sub_81A869C(void)
{
    gSaveBlock2Ptr->frontier.field_E10_3 = gSpecialVar_0x8005;
}

static void sub_81A86C0(void)
{
    u8 i, j;

    gSpecialVar_Result = TRUE;
    for (i = 0; i < 3; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[i];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr >= max && pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0)
        {
            u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
            for (j = 0; j < 4; j++)
            {
                u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);
                max = CalculatePPWithBonus(move, ppBonuses, j);
                curr = GetMonData(mon, MON_DATA_PP1 + j);
                if (curr < max)
                {
                    canBeHealed = TRUE;
                    break;
                }
            }
        }
        else
        {
            canBeHealed = TRUE;
        }

        if (canBeHealed == TRUE)
        {
            gSpecialVar_Result = FALSE;
            break;
        }
    }
}

static void sub_81A8794(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        s32 heldItem = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                                  MON_DATA_HELD_ITEM);
        gSaveBlock2Ptr->frontier.field_E12[i] = heldItem;
    }
}

static void sub_81A87E8(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        SetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                   MON_DATA_HELD_ITEM,
                   &gSaveBlock2Ptr->frontier.field_E12[i]);
    }
}

static void sub_81A8830(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_08612690[lvlMode]))
        gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] = 0;

    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

static bool8 CanEncounterWildMon(u8 enemyMonLevel)
{
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3))
    {
        u8 monAbility = GetMonAbility(&gPlayerParty[0]);
        if (monAbility == ABILITY_KEEN_EYE || monAbility == ABILITY_INTIMIDATE)
        {
            u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
            if (playerMonLevel > 5 && enemyMonLevel <= playerMonLevel - 5 && Random() % 2 == 0)
                return FALSE;
        }
    }

    return TRUE;
}

static u8 SpeciesToPikeMonId(u16 species)
{
    u8 ret;

    if (species == SPECIES_SEVIPER)
        ret = 0;
    else if (species == SPECIES_MILOTIC)
        ret = 1;
    else
        ret = 2;

    return ret;
}

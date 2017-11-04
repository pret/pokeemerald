
// Includes
#include "global.h"
#include "malloc.h"
#include "task.h"
#include "species.h"
#include "pokemon.h"
#include "cable_club.h"
#include "link.h"
#include "tv.h"
#include "battle_tower.h"
#include "new_menu_helpers.h"
#include "window.h"
#include "mystery_event_script.h"
#include "secret_base.h"
#include "mauville_old_man.h"
#include "sound.h"
#include "songs.h"
#include "overworld.h"
#include "field_screen.h"
#include "fldeff_80F9BCC.h"
#include "script.h"
#include "event_data.h"
#include "strings.h"
#include "string_util.h"
#include "record_mixing.h"

// Static type declarations

struct PlayerRecords {
    /* 0x0000 */ struct SecretBaseRecord secretBases[20];
    /* 0x0c80 */ TVShow tvShows[25];
    /* 0x1004 */ PokeNews pokeNews[16];
    /* 0x1044 */ OldMan oldMan;
    /* 0x1084 */ struct EasyChatPair easyChatPair[5];
    /* 0x10ac */ u8 unk_10ac[0x78];
    /* 0x1124 */ union BattleTowerRecord battleTowerRecord;
    /* 0x1210 */ u16 unk_1210;
    /* 0x1214 */ LilycoveLady lilycoveLady;
    /* 0x1254 */ u8 unk_1254[0x88];
    /* 0x12dc */ u8 unk_12dc[0x168];
}; // 1444

// Static RAM declarations

IWRAM_DATA bool8 gUnknown_03001130;
IWRAM_DATA struct SecretBaseRecord *gUnknown_03001134;
IWRAM_DATA TVShow *gUnknown_03001138;
IWRAM_DATA PokeNews *gUnknown_0300113C;
IWRAM_DATA OldMan *gUnknown_03001140;
IWRAM_DATA struct EasyChatPair *gUnknown_03001144;
IWRAM_DATA struct DayCareMailRecordMixing *gUnknown_03001148;
IWRAM_DATA void *gUnknown_0300114C; // gSaveBlock2Ptr->field_64C
IWRAM_DATA LilycoveLady *gUnknown_03001150;
IWRAM_DATA void *gUnknown_03001154; // gSaveBlock2Ptr->field_0DC;
IWRAM_DATA void *gUnknown_03001158; // gSaveBlock2Ptr->field_64C
IWRAM_DATA u32 gUnknown_0300115C;
IWRAM_DATA u8 gUnknown_03001160[8];
IWRAM_DATA u32 gUnknown_03001168[3];

EWRAM_DATA struct DayCareMailRecordMixing gUnknown_02039F9C[2] = {};
EWRAM_DATA struct PlayerRecords *gUnknown_0203A014 = NULL;
EWRAM_DATA struct PlayerRecords *gUnknown_0203A018 = NULL;

// Static ROM declarations

static void sub_80E715C(u8 taskId);
static void sub_80E7324(u8 taskId);
static void sub_80E756C(u8 taskId);
static void sub_80E7630(u8 taskId);
static void sub_80E77D4(u8 taskId);
static void *sub_80E77FC(const u16 *asShort);
static void sub_80E7808(void *records, u16 *a1);
static u8 sub_80E7810(void);
static void *sub_80E7820(u8);
static void sub_80E78C4(OldMan *, size_t, u8);
static void sub_80E7948(union BattleTowerRecord *, size_t, u8);
void sub_80E7A14(LilycoveLady *, size_t, u8);
void sub_80E7B2C(TVShow *);
void sub_80E7B60(void *, size_t, u8, TVShow *);
void sub_80E7F68(void *, u8);
void sub_80E7FF8(u8 taskId);
void sub_80E8110(void *, void *);
void sub_80E8468(void *, size_t, u8);
void sub_80E89AC(void *, size_t, u8);
void sub_80E89F8(void *dest);
void sub_80E8A54(void *src);
void sub_80E8AC0(union BattleTowerRecord *);
void sub_80EAF80(struct SecretBaseRecord *, size_t, u8);
void sub_80F01E8(void *, size_t, u8);
void sub_80F0C7C(PokeNews *, size_t, u8);
void sub_812287C(struct EasyChatPair *, size_t, u8);
void TaskDummy4(union BattleTowerRecord *src);

// .rodata

extern const u8 gUnknown_0858CF8C[];
extern const u8 gUnknown_0858CF8E[][3];
extern const u8 gUnknown_0858CF94[][4];

// .text

void sub_80E6BE8(void)
{
    sub_80B37D4(sub_80E715C);
}

void sub_80E6BF8(void)
{
    gUnknown_03001134 = gSaveBlock1Ptr->secretBases;
    gUnknown_03001138 = gSaveBlock1Ptr->tvShows;
    gUnknown_0300113C = gSaveBlock1Ptr->pokeNews;
    gUnknown_03001140 = &gSaveBlock1Ptr->oldMan;
    gUnknown_03001144 = gSaveBlock1Ptr->easyChatPairs;
    gUnknown_03001148 = gUnknown_02039F9C;
    gUnknown_0300114C = gSaveBlock2Ptr->field_64C;
    gUnknown_03001150 = &gSaveBlock1Ptr->lilycoveLady;
    gUnknown_03001154 = gSaveBlock2Ptr->field_0DC;
    gUnknown_03001158 = gSaveBlock2Ptr->field_64C;
}

void sub_80E6CA0(struct PlayerRecords *dest)
{
    memcpy(dest->secretBases, gUnknown_03001134, sizeof(struct SecretBaseRecord) * 20);
    memcpy(dest->tvShows, gUnknown_03001138, sizeof(TVShow) * 25);
    sub_80F14F8(dest->tvShows);
    memcpy(dest->pokeNews, gUnknown_0300113C, sizeof(PokeNews) * 16);
    memcpy(&dest->oldMan, gUnknown_03001140, sizeof(OldMan));
    memcpy(dest->easyChatPair, gUnknown_03001144, sizeof(struct EasyChatPair) * 5);
    sub_80E89F8(dest->unk_10ac);
    sub_81659DC(gUnknown_0300114C, &dest->battleTowerRecord);
    if (GetMultiplayerId() == 0)
    {
        dest->battleTowerRecord.ruby_sapphire.unk_11c8 = sub_81539D4();
    }
}

void sub_80E6D54(struct PlayerRecords *dest)
{
    memcpy(dest->secretBases, gUnknown_03001134, sizeof(struct SecretBaseRecord) * 20);
    sub_80EB18C(dest->secretBases);
    memcpy(dest->tvShows, gUnknown_03001138, sizeof(TVShow) * 25);
    sub_80F1208(dest->tvShows);
    memcpy(dest->pokeNews, gUnknown_0300113C, sizeof(PokeNews) * 16);
    memcpy(&dest->oldMan, gUnknown_03001140, sizeof(OldMan));
    sub_8120B70(&dest->oldMan);
    memcpy(dest->easyChatPair, gUnknown_03001144, sizeof(struct EasyChatPair) * 5);
    sub_80E89F8(dest->unk_10ac);
    sub_80E8A54(dest->unk_10ac);
    sub_81659DC(gUnknown_0300114C, &dest->battleTowerRecord);
    TaskDummy4(&dest->battleTowerRecord);
    if (GetMultiplayerId() == 0)
    {
        dest->battleTowerRecord.ruby_sapphire.unk_11c8 = sub_81539D4();
    }
}

void sub_80E6E24(void)
{
    sub_80E9914();
    sub_80F0BB8();
    sub_80E6BF8();
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (sub_800A03C() == FALSE)
        {
            sub_80E6CA0(gUnknown_0203A018);
        }
        else
        {
            sub_80E6D54(gUnknown_0203A018);
        }
    }
    else
    {
        memcpy(gUnknown_0203A018->secretBases, gUnknown_03001134, sizeof(struct SecretBaseRecord) * 20);
        memcpy(gUnknown_0203A018->tvShows, gUnknown_03001138, sizeof(TVShow) * 25);
        memcpy(gUnknown_0203A018->pokeNews, gUnknown_0300113C, sizeof(PokeNews) * 16);
        memcpy(&gUnknown_0203A018->oldMan, gUnknown_03001140, sizeof(OldMan));
        memcpy(&gUnknown_0203A018->lilycoveLady, gUnknown_03001150, sizeof(LilycoveLady));
        memcpy(gUnknown_0203A018->easyChatPair, gUnknown_03001144, sizeof(struct EasyChatPair) * 5);
        sub_80E89F8(gUnknown_0203A018->unk_10ac);
        memcpy(&gUnknown_0203A018->battleTowerRecord, gUnknown_0300114C, 0xec);
        sub_80E8AC0(&gUnknown_0203A018->battleTowerRecord);
        if (GetMultiplayerId() == 0)
        {
            gUnknown_0203A018->unk_1210 = sub_81539D4();
        }
        sub_80E8110(gUnknown_0203A018->unk_1254, gUnknown_03001154);
        sub_80E8260(gUnknown_0203A018->unk_12dc);
    }
}

void sub_80E6F60(u32 a0)
{
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        // Ruby/Sapphire
        sub_80E7B2C(gUnknown_0203A014[0].tvShows);
        sub_80EAF80(gUnknown_0203A014[0].secretBases, 0x1230, a0);
        sub_80E7B60(gUnknown_0203A014[0].unk_10ac, 0x1230, a0, gUnknown_0203A014[0].tvShows);
        sub_80E7948(&gUnknown_0203A014[0].battleTowerRecord, 0x1230, a0);
        sub_80F01E8(gUnknown_0203A014[0].tvShows, 0x1230, a0);
        sub_80F0C7C(gUnknown_0203A014[0].pokeNews, 0x1230, a0);
        sub_80E78C4(&gUnknown_0203A014[0].oldMan, 0x1230, a0);
        sub_812287C(gUnknown_0203A014[0].easyChatPair, 0x1230, a0);
        sub_80E7F68(&gUnknown_0203A014[0].battleTowerRecord.ruby_sapphire.unk_11c8, a0);
    }
    else
    {
        // Emerald
        sub_80E7B2C(gUnknown_0203A014[0].tvShows);
        sub_80EAF80(gUnknown_0203A014[0].secretBases, 0x1444, a0);
        sub_80F01E8(gUnknown_0203A014[0].tvShows, 0x1444, a0);
        sub_80F0C7C(gUnknown_0203A014[0].pokeNews, 0x1444, a0);
        sub_80E78C4(&gUnknown_0203A014[0].oldMan, 0x1444, a0);
        sub_812287C(gUnknown_0203A014[0].easyChatPair, 0x1444, a0);
        sub_80E7B60(gUnknown_0203A014[0].unk_10ac, 0x1444, a0, gUnknown_0203A014[0].tvShows);
        sub_80E7948(&gUnknown_0203A014[0].battleTowerRecord, 0x1444, a0);
        sub_80E7F68(&gUnknown_0203A014[0].unk_1210, a0);
        sub_80E7A14(&gUnknown_0203A014[0].lilycoveLady, 0x1444, a0);
        sub_80E8468(gUnknown_0203A014[0].unk_1254, 0x1444, a0);
        sub_80E89AC(gUnknown_0203A014[0].unk_12dc, 0x1444, a0);
    }
}

void sub_80E70F4(const u8 *src)
{
    sub_81973C4(0, 0);
    PrintTextOnWindow(0, 1, src, 0, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

void sub_80E7128(u8 taskId)
{
    if (++ gTasks[taskId].data[0] == 50)
    {
        PlaySE(SE_W213);
        gTasks[taskId].data[0] = 0;
    }
}

static void sub_80E715C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[0])
    {
        case 0:
            gUnknown_0203A018 = malloc(sizeof(struct PlayerRecords));
            gUnknown_0203A014 = malloc(sizeof(struct PlayerRecords) * 4);
            sub_8009628(gSpecialVar_0x8005);
            VarSet(VAR_0x4000, 1);
            gUnknown_03001130 = FALSE;
            sub_80E6E24();
            sub_80FB00C();
            data[0] = 1;
            data[10] = CreateTask(sub_80E7324, 80);
            data[15] = CreateTask(sub_80E7128, 81);
            break;
        case 1:
            if (!gTasks[data[10]].isActive)
            {
                data[0] = 2;
                FlagSet(SYS_MIX_RECORD);
                sub_80FB074();
                DestroyTask(data[15]);
            }
            break;
        case 2:
            data[10] = CreateTask(sub_80E7FF8, 10);
            data[0] = 3;
            PlaySE(SE_W226);
            break;
        case 3:
            if (!gTasks[data[10]].isActive)
            {
                data[0] = 4;
                if (!gLinkVSyncDisabled)
                {
                    data[10] = sub_80B3050();
                }
                sub_80E70F4(gText_RecordMixingComplete);
                data[8] = 0;
            }
            break;
        case 4:
            if (++ data[8] > 60)
            {
                data[0] = 5;
            }
            break;
        case 5:
            if (!gTasks[data[10]].isActive)
            {
                free(gUnknown_0203A014);
                free(gUnknown_0203A018);
                sub_808729C();
                if (gLinkVSyncDisabled)
                {
                    CreateTask(sub_80AF2B4, 10);
                }
                sub_8197434(0, 1);
                DestroyTask(taskId);
                EnableBothScriptContexts();
            }
            break;
    }
}

static void sub_80E7324(u8 taskId)
{
    u8 r4;
    u8 taskId2;
    struct Task *task;

    task = &gTasks[taskId];
    switch (task->data[0])
    {
        case 0:
            sub_80E70F4(gText_MixingRecords);
            task->data[8] = 0x708;
            task->data[0] = 400;
            sub_8009FAC();
            break;
        case 100:
            if (++ task->data[12] > 20)
            {
                task->data[12] = 0;
                task->data[0] = 101;
            }
            break;
        case 101:
            r4 = sub_800ABAC();
            if (sub_800ABBC() == TRUE)
            {
                if (r4 == sub_800AA48())
                {
                    PlaySE(SE_PIN);
                    task->data[0] = 201;
                    task->data[12] = 0;
                }
            }
            else
            {
                PlaySE(SE_BOO);
                task->data[0] = 301;
            }
            break;
        case 201:
            if (sub_800AA48() == sub_800ABAC() && ++ task->data[12] > (sub_800ABAC() * 30))
            {
                sub_800A620();
                task->data[0] = 1;
            }
            break;
        case 301:
            if (sub_800AA48() == sub_800ABAC())
            {
                task->data[0] = 1;
            }
            break;
        case 400:
            if (++ task->data[12] > 20)
            {
                task->data[0] = 1;
                task->data[12] = 0;
            }
            break;
        case 1:
            if (gReceivedRemoteLinkPlayers != 0)
            {
                ConvertIntToDecimalStringN(gStringVar1, sub_80E7810(), STR_CONV_MODE_LEADING_ZEROS, 2);
                task->data[0] = 5;
            }
            break;
        case 2:
            task->data[6] = sub_800ABAC();
            task->data[0] = 0;
            task->data[5] = sub_80E7810();
            task->func = sub_80E756C;
            if (Link_AnyPartnersPlayingRubyOrSapphire())
            {
                sub_80E7808(gUnknown_0203A018, (u16 *)&task->data[2]);
                taskId2 = CreateTask(sub_80E7630, 80);
                task->data[10] = taskId2;
                gTasks[taskId2].data[0] = taskId;
                sub_80E7808(gUnknown_0203A014, (u16 *)&gTasks[taskId2].data[5]);
                gUnknown_0300115C = 0x1230;
            }
            else
            {
                sub_80E7808(gUnknown_0203A018, (u16 *)&task->data[2]);
                taskId2 = CreateTask(sub_80E7630, 80);
                task->data[10] = taskId2;
                gTasks[taskId2].data[0] = taskId;
                sub_80E7808(gUnknown_0203A014, (u16 *)&gTasks[taskId2].data[5]);
                gUnknown_0300115C = 0x1444;
            }
            break;
        case 5:
            if (++ task->data[10] > 60)
            {
                task->data[10] = 0;
                task->data[0] = 2;
            }
            break;
    }
}

static void sub_80E756C(u8 taskId)
{
    struct Task *task;
    void *dest;

    task = &gTasks[taskId];
    switch (task->data[0])
    {
        case 0:
            dest = sub_80E77FC(&task->data[2]) + task->data[4] * 200;
            memcpy(gBlockSendBuffer, dest, 200);
            task->data[0] ++;
            break;
        case 1:
            if (GetMultiplayerId() == 0)
            {
                sub_800A4D8(1);
            }
            task->data[0] ++;
            break;
        case 2:
            break;
        case 3:
            task->data[4] ++;
            if (task->data[4] == gUnknown_0300115C / 200 + 1)
            {
                task->data[0] ++;
            }
            else
            {
                task->data[0] = 0;
            }
            break;
        case 4:
            if (!gTasks[task->data[10]].isActive)
            {
                task->func = sub_80E77D4;
            }
            break;
    }
}

static void sub_80E7630(u8 taskId)
{
    struct Task *task;
    u8 status;
    u8 counter;
    u8 i;
    void *dest;
    void *src;

    task = &gTasks[taskId];
    status = GetBlockReceivedStatus();
    counter = 0;
    if (status == sub_800A9D8())
    {
        for (i = 0; i < GetLinkPlayerCount(); i ++)
        {
            if ((status >> i) & 0x01)
            {
                dest = sub_80E77FC((u16 *)&task->data[5]) + task->data[i + 1] * 200 + gUnknown_0300115C * i;
                src = sub_80E7820(i);
                if ((task->data[i + 1] + 1) * 200 > gUnknown_0300115C)
                {
                    memcpy(dest, src, gUnknown_0300115C - task->data[i + 1] * 200);
                }
                else
                {
                    memcpy(dest, src, 200);
                }
                ResetBlockReceivedFlag(i);
                task->data[i + 1] ++;
                if (task->data[i + 1] == gUnknown_0300115C / 200 + 1)
                {
                    counter ++;
                }
            }
        }
        gTasks[task->data[0]].data[0] ++;
    }
    if (counter == GetLinkPlayerCount())
    {
        DestroyTask(taskId);
    }
}

static void sub_80E776C(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    if (!gTasks[task->data[10]].isActive)
    {
        DestroyTask(taskId);
    }
}

static void sub_80E77A0(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->func = sub_80E776C;
    if (gUnknown_03001130 == TRUE)
    {
        sub_80E6F60(task->data[5]);
    }
}

static void sub_80E77D4(u8 taskId)
{
    gTasks[taskId].func = sub_80E77A0;
    gUnknown_03001130 = TRUE;
}


static void *sub_80E77FC(const u16 *asShort)
{
    return (void *)(asShort[0] | (asShort[1] << 16));
}

static void sub_80E7808(void *records, u16 *asShort)
{
    asShort[0] = (u32)records;
    asShort[1] = ((u32)records >> 16);
}

static u8 sub_80E7810(void)
{
    return GetMultiplayerId();
}

static void *sub_80E7820(u8 id)
{
    return gBlockRecvBuffer[id];
}

void sub_80E7830(u32 *data)
{
    u32 i;
    u32 linkTrainerId;

    switch ((u32)GetLinkPlayerCount())
    {
        case 2:
            for (i = 0; i < 2; i ++)
            {
                data[i] = gUnknown_0858CF8C[i];
            }
            break;
        case 3:
            linkTrainerId = GetLinkPlayerTrainerId(0) % 2;
            for (i = 0; i < 3; i ++)
            {
                data[i] = gUnknown_0858CF8E[linkTrainerId][i];
            }
            break;
        case 4:
            linkTrainerId = GetLinkPlayerTrainerId(0) % 9;
            for (i = 0; i < 4; i ++)
            {
                data[i] = gUnknown_0858CF94[linkTrainerId][i];
            }
            break;
    }
}

static void sub_80E78C4(OldMan *oldMan, size_t recordSize, u8 which)
{
    u8 version;
    u16 language;
    OldMan *dest;
    u32 mixIndices[4];

    sub_80E7830(mixIndices);
    dest = (OldMan *)((void *)oldMan + recordSize * mixIndices[which]);
    version = gLinkPlayers[mixIndices[which]].version;
    language = gLinkPlayers[mixIndices[which]].language;
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        sub_8120D34(dest, version, language);
    }
    else
    {
        sub_8120CD0(dest, version, language);
    }
    memcpy(gUnknown_03001140, (OldMan *)((void *)oldMan + recordSize * mixIndices[which]), sizeof(OldMan));
    sub_8120670();
}

static void sub_80E7948(union BattleTowerRecord *battleTowerRecord, size_t recordSize, u8 which)
{
    union BattleTowerRecord *r6;
    struct UnknownPokemonStruct *btPokemon;
    u32 mixIndices[4];
    s32 i;

    sub_80E7830(mixIndices);
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (sub_816587C((union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * mixIndices[which]), (union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * which)) == TRUE)
        {
            r6 = (union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * which);
            r6->emerald.language = gLinkPlayers[mixIndices[which]].language;
            sub_8164F70(r6);
        }
    }
    else
    {
        memcpy((union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * which), (union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * mixIndices[which]), sizeof(union BattleTowerRecord));
        r6 = (union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * which);
        for (i = 0; i < 4; i ++)
        {
            btPokemon = &r6->emerald.party[i];
            if (btPokemon->species != SPECIES_NONE && IsStringJapanese(btPokemon->nickname))
            {
                ConvertInternationalString(btPokemon->nickname, LANGUAGE_JAPANESE);
            }
        }
        sub_8164F70(r6);
    }
    sub_81628A0((union BattleTowerRecord *)((void *)battleTowerRecord + recordSize * which));
}


// Includes
#include "global.h"
#include "malloc.h"
#include "random.h"
#include "constants/items.h"
#include "text.h"
#include "item.h"
#include "task.h"
#include "constants/species.h"
#include "save.h"
#include "load_save.h"
#include "pokemon.h"
#include "cable_club.h"
#include "link.h"
#include "tv.h"
#include "battle_tower.h"
#include "window.h"
#include "mystery_event_script.h"
#include "secret_base.h"
#include "mauville_old_man.h"
#include "sound.h"
#include "constants/songs.h"
#include "menu.h"
#include "overworld.h"
#include "field_screen.h"
#include "fldeff_80F9BCC.h"
#include "script.h"
#include "event_data.h"
#include "lilycove_lady.h"
#include "strings.h"
#include "string_util.h"
#include "record_mixing.h"

// Static type declarations

struct PlayerRecordsRS {
    struct SecretBaseRecord secretBases[20];
    TVShow tvShows[25];
    PokeNews pokeNews[16];
    OldMan oldMan;
    struct EasyChatPair easyChatPairs[5];
    struct UnkStruct_80E7B60 dayCareMail;
    struct RSBattleTowerRecord battleTowerRecord;
    u16 filler11C8[0x32];
};

struct PlayerRecords {
    /* 0x0000 */ struct SecretBaseRecord secretBases[20];
    /* 0x0c80 */ TVShow tvShows[25];
    /* 0x1004 */ PokeNews pokeNews[16];
    /* 0x1044 */ OldMan oldMan;
    /* 0x1084 */ struct EasyChatPair easyChatPair[5];
    /* 0x10ac */ struct UnkStruct_80E7B60 dayCareMail;
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
IWRAM_DATA struct UnkStruct_80E7B60 *gUnknown_03001148;
IWRAM_DATA void *gUnknown_0300114C; // gSaveBlock2Ptr->field_64C
IWRAM_DATA LilycoveLady *gUnknown_03001150;
IWRAM_DATA void *gUnknown_03001154; // gSaveBlock2Ptr->field_0DC;
IWRAM_DATA void *gUnknown_03001158; // gSaveBlock2Ptr->field_64C
IWRAM_DATA u32 gUnknown_0300115C;
IWRAM_DATA u8 gUnknown_03001160;
IWRAM_DATA u32 filler_03001164;
IWRAM_DATA u32 gUnknown_03001168[3];

EWRAM_DATA struct UnkStruct_80E7B60 gUnknown_02039F9C = {};
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
static void sub_80E7A14(LilycoveLady *, size_t, u8);
static void sub_80E7B2C(const u8 *);
static void sub_80E7B60(struct UnkStruct_80E7B60 *, size_t, u8, TVShow *);
static void sub_80E7F68(u16 *item, u8 which);
static void sub_80E7FF8(u8 taskId);
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

extern const u8 gUnknown_0858CFB8[3][2];
extern const u8 gUnknown_0858CFBE[3][4];

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
    gUnknown_03001148 = &gUnknown_02039F9C;
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
    sub_80E89F8(&dest->dayCareMail);
    sub_81659DC(gUnknown_0300114C, &dest->battleTowerRecord);
    if (GetMultiplayerId() == 0)
    {
        dest->battleTowerRecord.ruby_sapphire.unk_11c8 = GetRecordMixingGift();
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
    sub_80E89F8(&dest->dayCareMail);
    sub_80E8A54(&dest->dayCareMail);
    sub_81659DC(gUnknown_0300114C, &dest->battleTowerRecord);
    TaskDummy4(&dest->battleTowerRecord);
    if (GetMultiplayerId() == 0)
    {
        dest->battleTowerRecord.ruby_sapphire.unk_11c8 = GetRecordMixingGift();
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
        sub_80E89F8(&gUnknown_0203A018->dayCareMail);
        memcpy(&gUnknown_0203A018->battleTowerRecord, gUnknown_0300114C, 0xec);
        sub_80E8AC0(&gUnknown_0203A018->battleTowerRecord);
        if (GetMultiplayerId() == 0)
        {
            gUnknown_0203A018->unk_1210 = GetRecordMixingGift();
        }
        sub_80E8110(gUnknown_0203A018->unk_1254, gUnknown_03001154);
        sub_80E8260(gUnknown_0203A018->unk_12dc);
    }
}

void sub_80E6F60(u32 which)
{
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        // Ruby/Sapphire
        sub_80E7B2C((void *)gUnknown_0203A014[0].tvShows);
        sub_80EAF80(gUnknown_0203A014[0].secretBases, sizeof(struct PlayerRecordsRS), which);
        sub_80E7B60(&gUnknown_0203A014[0].dayCareMail, sizeof(struct PlayerRecordsRS), which, gUnknown_0203A014[0].tvShows);
        sub_80E7948(&gUnknown_0203A014[0].battleTowerRecord, sizeof(struct PlayerRecordsRS), which);
        sub_80F01E8(gUnknown_0203A014[0].tvShows, sizeof(struct PlayerRecordsRS), which);
        sub_80F0C7C(gUnknown_0203A014[0].pokeNews, sizeof(struct PlayerRecordsRS), which);
        sub_80E78C4(&gUnknown_0203A014[0].oldMan, sizeof(struct PlayerRecordsRS), which);
        sub_812287C(gUnknown_0203A014[0].easyChatPair, sizeof(struct PlayerRecordsRS), which);
        sub_80E7F68(&gUnknown_0203A014[0].battleTowerRecord.ruby_sapphire.unk_11c8, which);
    }
    else
    {
        // Emerald
        sub_80E7B2C((void *)gUnknown_0203A014[0].tvShows);
        sub_80EAF80(gUnknown_0203A014[0].secretBases, sizeof(struct PlayerRecords), which);
        sub_80F01E8(gUnknown_0203A014[0].tvShows, sizeof(struct PlayerRecords), which);
        sub_80F0C7C(gUnknown_0203A014[0].pokeNews, sizeof(struct PlayerRecords), which);
        sub_80E78C4(&gUnknown_0203A014[0].oldMan, sizeof(struct PlayerRecords), which);
        sub_812287C(gUnknown_0203A014[0].easyChatPair, sizeof(struct PlayerRecords), which);
        sub_80E7B60(&gUnknown_0203A014[0].dayCareMail, sizeof(struct PlayerRecords), which, gUnknown_0203A014[0].tvShows);
        sub_80E7948(&gUnknown_0203A014[0].battleTowerRecord, sizeof(struct PlayerRecords), which);
        sub_80E7F68(&gUnknown_0203A014[0].unk_1210, which);
        sub_80E7A14(&gUnknown_0203A014[0].lilycoveLady, sizeof(struct PlayerRecords), which);
        sub_80E8468(gUnknown_0203A014[0].unk_1254, sizeof(struct PlayerRecords), which);
        sub_80E89AC(gUnknown_0203A014[0].unk_12dc, sizeof(struct PlayerRecords), which);
    }
}

void sub_80E70F4(const u8 *src)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
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
                FlagSet(FLAG_SYS_MIX_RECORD);
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
            r4 = GetLinkPlayerCount_2();
            if (IsLinkMaster() == TRUE)
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
            if (sub_800AA48() == GetLinkPlayerCount_2() && ++ task->data[12] > (GetLinkPlayerCount_2() * 30))
            {
                sub_800A620();
                task->data[0] = 1;
            }
            break;
        case 301:
            if (sub_800AA48() == GetLinkPlayerCount_2())
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
            task->data[6] = GetLinkPlayerCount_2();
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
                gUnknown_0300115C = sizeof(struct PlayerRecordsRS);
            }
            else
            {
                sub_80E7808(gUnknown_0203A018, (u16 *)&task->data[2]);
                taskId2 = CreateTask(sub_80E7630, 80);
                task->data[10] = taskId2;
                gTasks[taskId2].data[0] = taskId;
                sub_80E7808(gUnknown_0203A014, (u16 *)&gTasks[taskId2].data[5]);
                gUnknown_0300115C = sizeof(struct PlayerRecords);
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
    dest = (void *)oldMan + recordSize * mixIndices[which];
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
    memcpy(gUnknown_03001140, (void *)oldMan + recordSize * mixIndices[which], sizeof(OldMan));
    sub_8120670();
}

static void sub_80E7948(union BattleTowerRecord *battleTowerRecord, size_t recordSize, u8 which)
{
    union BattleTowerRecord *dest;
    struct UnknownPokemonStruct *btPokemon;
    u32 mixIndices[4];
    s32 i;

    sub_80E7830(mixIndices);
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (sub_816587C((void *)battleTowerRecord + recordSize * mixIndices[which], (void *)battleTowerRecord + recordSize * which) == TRUE)
        {
            dest = (void *)battleTowerRecord + recordSize * which;
            dest->emerald.language = gLinkPlayers[mixIndices[which]].language;
            sub_8164F70(dest);
        }
    }
    else
    {
        memcpy((void *)battleTowerRecord + recordSize * which, (void *)battleTowerRecord + recordSize * mixIndices[which], sizeof(union BattleTowerRecord));
        dest = (void *)battleTowerRecord + recordSize * which;
        for (i = 0; i < 4; i ++)
        {
            btPokemon = &dest->emerald.party[i];
            if (btPokemon->species != SPECIES_NONE && IsStringJapanese(btPokemon->nickname))
            {
                ConvertInternationalString(btPokemon->nickname, LANGUAGE_JAPANESE);
            }
        }
        sub_8164F70(dest);
    }
    sub_81628A0((void *)battleTowerRecord + recordSize * which);
}

static void sub_80E7A14(LilycoveLady *lilycoveLady, size_t recordSize, u8 which)
{
    LilycoveLady *dest;
    u32 mixIndices[4];

    sub_80E7830(mixIndices);
    memcpy((void *)lilycoveLady + recordSize * which, gUnknown_03001150, sizeof(LilycoveLady));
    if (GetLilycoveLadyId() == 0)
    {
        dest = malloc(sizeof(LilycoveLady));
        if (dest == NULL)
        {
            return;
        }
        memcpy(dest, gUnknown_03001150, sizeof(LilycoveLady));
    }
    else
    {
        dest = NULL;
    }
    memcpy(gUnknown_03001150, (void *)lilycoveLady + recordSize * mixIndices[which], sizeof(LilycoveLady));
    sub_818DA78();
    if (dest != NULL)
    {
        sub_818E570(dest);
        free(dest);
    }
}

static u8 sub_80E7A9C(struct DayCareMailRecordMixing *rmMail)
{
    return rmMail->mail.itemId;
}

static void sub_80E7AA4(struct UnkStruct_80E7B60 *src, size_t recordSize, u8 (*idxs)[2], u8 which0, u8 which1)
{
    struct DayCareMailRecordMixing buffer;
    struct UnkStruct_80E7B60 *_src1;
    struct UnkStruct_80E7B60 *_src2;

    _src1 = (void *)src + recordSize * idxs[which0][0];
    memcpy(&buffer, &_src1->unk_00[idxs[which0][1]], sizeof(struct DayCareMailRecordMixing));
    _src2 = (void *)src + recordSize * idxs[which1][0];
    memcpy(&_src1->unk_00[idxs[which0][1]], &_src2->unk_00[idxs[which1][1]], sizeof(struct DayCareMailRecordMixing));
    memcpy(&_src2->unk_00[idxs[which1][1]], &buffer, sizeof(struct DayCareMailRecordMixing));
}

static void sub_80E7B2C(const u8 *src)
{
    u8 sum;
    int i;

    sum = 0;
    for (i = 0; i < 256; i ++)
    {
        sum += src[i];
    }
    gUnknown_03001160 = sum;
}

static u8 sub_80E7B54(void)
{
    return gUnknown_03001160;
}

#ifdef NONMATCHING
static void sub_80E7B60(struct UnkStruct_80E7B60 *src, size_t recordSize, u8 which, TVShow *shows)
{
    // r9 = which
    u16 i;
    u16 j;
    u8 linkPlayerCount;
    u16 language;
    u16 otNameLanguage;
    u16 nicknameLanguage;
    u32 version;
    u8 dcMail1;
    u8 dcMail2;
    u8 r1_80e7b54;
    struct DayCareMailRecordMixing *recordMixingMail;
    struct UnkStruct_80E7B60 *_src;
    u8 sp04[4];
    u8 sp08[4];
    struct UnkStruct_80E7B60 *sp0c[4]; // -> sp+48
    u8 sp1c[4][2]; // [][0] -> sp+4c, [][1] -> sp+50
    u8 sp24[4][2];
    // sp+2c = src
    // sp+30 = recordSize
    u8 sp34;
    u16 oldSeed;
    bool32 anyRS; // sp+3c

    oldSeed = Random2();
    SeedRng2(gLinkPlayers[0].trainerId);
    linkPlayerCount = GetLinkPlayerCount();
    for (i = 0; i < 4; i ++)
    {
        sp04[i] = 0xFF;
        sp08[i] = 0;
        sp1c[i][0] = 0;
        sp1c[i][1] = 0;
    }
    anyRS = Link_AnyPartnersPlayingRubyOrSapphire();
    for (i = 0; i < GetLinkPlayerCount(); i ++) // r8 = i
    {
        // sp+54 = linkPlayerCount << 16
        // sp+44 = which * recordSize
        _src = (void *)src + i * recordSize; // r7
        language = gLinkPlayers[i].language; // r9
        version = (u8)gLinkPlayers[i].version; // sp+40
        for (j = 0; j < _src->unk_70; j ++)
        {
            // r10 = ~0x10
            recordMixingMail = &_src->unk_00[j];
            if (recordMixingMail->mail.itemId != ITEM_NONE)
            {
                if (anyRS)
                {
                    if (StringLength(recordMixingMail->OT_name) <= 5)
                    {
                        otNameLanguage = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        StripExtCtrlCodes(recordMixingMail->OT_name);
                        otNameLanguage = language;
                    }
                    if (recordMixingMail->monName[0] == EXT_CTRL_CODE_BEGIN && recordMixingMail->monName[1] == EXT_CTRL_CODE_JPN)
                    {
                        StripExtCtrlCodes(recordMixingMail->monName);
                        nicknameLanguage = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        nicknameLanguage = language;
                    }
                    if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
                    {
                        recordMixingMail->language_maybe = otNameLanguage;
                        recordMixingMail->unknown = nicknameLanguage;
                    }
                }
                else if (language == LANGUAGE_JAPANESE)
                {
                    if (IsStringJapanese(recordMixingMail->OT_name))
                    {
                        recordMixingMail->language_maybe = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        recordMixingMail->language_maybe = GAME_LANGUAGE;
                    }
                    if (IsStringJapanese(recordMixingMail->monName))
                    {
                        recordMixingMail->unknown = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        recordMixingMail->unknown = GAME_LANGUAGE;
                    }
                }
            }
        }
    }
    sp34 = 0;
    for (i = 0; i < linkPlayerCount; i ++)
    {
        _src = (void *)src + i * recordSize; // r7
        if (_src->unk_70 != 0)
        {
            for (j = 0; j < _src->unk_70; j ++)
            {
                if (_src->unk_74[j] == 0)
                {
                    sp1c[i][j] = 1;
                }
            }
        }
    }
    i = 0;
    for (j = 0; j < linkPlayerCount; j ++)
    {
        _src = (void *)src + j * recordSize;
        if (sp1c[j][0] == TRUE || sp1c[j][1] == TRUE)
        {
            sp34 ++;
        }
        if (sp1c[j][0] == TRUE && sp1c[j][1] == FALSE)
        {
            sp24[i][0] = j;
            sp24[i][1] = 0;
            i ++;
        }
        else if (sp1c[j][0] == FALSE && sp1c[j][1] == TRUE)
        {
            sp24[i][0] = j;
            sp24[i][1] = 0;
            i ++;
        }
        else if (sp1c[j][0] == TRUE && sp1c[j][1] == TRUE)
        {
            sp24[i][0] = j;
            dcMail1 = sub_80E7A9C(&_src->unk_00[0]);
            dcMail2 = sub_80E7A9C(&_src->unk_00[1]);
            if (!dcMail1 && dcMail2)
            {
                sp24[i][1] = 1;
            }
            else if ((dcMail1 && dcMail2) || (!dcMail1 && !dcMail2))
            {
                sp24[i][1] = Random2() % 2;
            }
            else
            {
                sp24[i][1] = 0;
            }
            i ++;
        }
    }
    for (i = 0; i < 4; i ++)
    {
        _src = &src[which * recordSize];
        sp0c[i] = _src;
    }
    r1_80e7b54 = sub_80E7B54() % 3;
    switch (sp34)
    {
        case 2:
            sub_80E7AA4(src, recordSize, sp24, 0, 1);
            break;
        case 3:
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFB8[r1_80e7b54][0], gUnknown_0858CFB8[r1_80e7b54][1]);
            break;
        case 4:
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFBE[r1_80e7b54][0], gUnknown_0858CFBE[r1_80e7b54][1]);
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFBE[r1_80e7b54][2], gUnknown_0858CFBE[r1_80e7b54][3]);
            break;
    }
    _src = (void *)src + which * recordSize;
    memcpy(&gSaveBlock1Ptr->daycare.mons[0].misc.mail, &_src->unk_00[0], sizeof(struct DayCareMailRecordMixing));
    memcpy(&gSaveBlock1Ptr->daycare.mons[1].misc.mail, &_src->unk_00[1], sizeof(struct DayCareMailRecordMixing));
    SeedRng(oldSeed);
}
#else
__attribute__((naked)) static void sub_80E7B60(struct UnkStruct_80E7B60 *src, size_t recordSize, u8 which, TVShow *shows)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tsub sp, 0x58\n"
                    "\tstr r0, [sp, 0x2C]\n"
                    "\tstr r1, [sp, 0x30]\n"
                    "\tlsls r2, 24\n"
                    "\tlsrs r2, 24\n"
                    "\tmov r9, r2\n"
                    "\tbl Random2\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tstr r0, [sp, 0x38]\n"
                    "\tldr r0, =gLinkPlayers\n"
                    "\tldrh r0, [r0, 0x4]\n"
                    "\tbl SeedRng2\n"
                    "\tbl GetLinkPlayerCount\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r4, r0, 24\n"
                    "\tmovs r0, 0\n"
                    "\tmov r8, r0\n"
                    "\tmov r1, sp\n"
                    "\tadds r1, 0x1C\n"
                    "\tstr r1, [sp, 0x4C]\n"
                    "\tmov r2, sp\n"
                    "\tadds r2, 0x1D\n"
                    "\tstr r2, [sp, 0x50]\n"
                    "\tmov r3, sp\n"
                    "\tadds r3, 0xC\n"
                    "\tstr r3, [sp, 0x48]\n"
                    "\tmovs r7, 0xFF\n"
                    "\tadd r3, sp, 0x8\n"
                    "\tmovs r2, 0\n"
                    "\tadds r6, r1, 0\n"
                    "\tldr r5, [sp, 0x50]\n"
                    "_080E7BB0:\n"
                    "\tmov r1, sp\n"
                    "\tadd r1, r8\n"
                    "\tadds r1, 0x4\n"
                    "\tldrb r0, [r1]\n"
                    "\torrs r0, r7\n"
                    "\tstrb r0, [r1]\n"
                    "\tmov r1, r8\n"
                    "\tadds r0, r3, r1\n"
                    "\tstrb r2, [r0]\n"
                    "\tlsls r1, 1\n"
                    "\tadds r0, r6, r1\n"
                    "\tstrb r2, [r0]\n"
                    "\tadds r1, r5, r1\n"
                    "\tstrb r2, [r1]\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r0, 0x3\n"
                    "\tbls _080E7BB0\n"
                    "\tbl Link_AnyPartnersPlayingRubyOrSapphire\n"
                    "\tstr r0, [sp, 0x3C]\n"
                    "\tmovs r2, 0\n"
                    "\tmov r8, r2\n"
                    "\tlsls r4, 16\n"
                    "\tstr r4, [sp, 0x54]\n"
                    "\tldr r0, [sp, 0x30]\n"
                    "\tmov r3, r9\n"
                    "\tmuls r3, r0\n"
                    "\tstr r3, [sp, 0x44]\n"
                    "\tb _080E7D04\n"
                    "\t.pool\n"
                    "_080E7BF8:\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r1\n"
                    "\tldr r2, [sp, 0x2C]\n"
                    "\tadds r7, r2, r0\n"
                    "\tldr r1, =gLinkPlayers\n"
                    "\tmov r3, r8\n"
                    "\tlsls r0, r3, 3\n"
                    "\tsubs r0, r3\n"
                    "\tlsls r0, 2\n"
                    "\tadds r0, r1\n"
                    "\tldrh r1, [r0, 0x1A]\n"
                    "\tmov r9, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tstr r0, [sp, 0x40]\n"
                    "\tmovs r6, 0\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcs _080E7CFA\n"
                    "\tmovs r2, 0x10\n"
                    "\tnegs r2, r2\n"
                    "\tmov r10, r2\n"
                    "_080E7C24:\n"
                    "\tlsls r0, r6, 3\n"
                    "\tsubs r0, r6\n"
                    "\tlsls r0, 3\n"
                    "\tadds r5, r7, r0\n"
                    "\tldrh r0, [r5, 0x20]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CEE\n"
                    "\tldr r3, [sp, 0x3C]\n"
                    "\tcmp r3, 0\n"
                    "\tbeq _080E7C9A\n"
                    "\tadds r4, r5, 0\n"
                    "\tadds r4, 0x24\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl StringLength\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x5\n"
                    "\tbhi _080E7C54\n"
                    "\tmovs r4, 0x1\n"
                    "\tb _080E7C5C\n"
                    "\t.pool\n"
                    "_080E7C54:\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl StripExtCtrlCodes\n"
                    "\tmov r4, r9\n"
                    "_080E7C5C:\n"
                    "\tldrh r1, [r5, 0x2C]\n"
                    "\tldr r0, =0x000015fc\n"
                    "\tcmp r1, r0\n"
                    "\tbne _080E7C74\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x2C\n"
                    "\tbl StripExtCtrlCodes\n"
                    "\tmovs r1, 0x1\n"
                    "\tb _080E7C76\n"
                    "\t.pool\n"
                    "_080E7C74:\n"
                    "\tmov r1, r9\n"
                    "_080E7C76:\n"
                    "\tldr r0, [sp, 0x40]\n"
                    "\tsubs r0, 0x1\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _080E7CEE\n"
                    "\tadds r2, r5, 0\n"
                    "\tadds r2, 0x37\n"
                    "\tmovs r0, 0xF\n"
                    "\tands r4, r0\n"
                    "\tldrb r0, [r2]\n"
                    "\tmov r3, r10\n"
                    "\tands r0, r3\n"
                    "\torrs r0, r4\n"
                    "\tlsls r1, 4\n"
                    "\tmovs r3, 0xF\n"
                    "\tands r0, r3\n"
                    "\torrs r0, r1\n"
                    "\tstrb r0, [r2]\n"
                    "\tb _080E7CEE\n"
                    "_080E7C9A:\n"
                    "\tmov r0, r9\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7CEE\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x24\n"
                    "\tbl IsStringJapanese\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CBA\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x37\n"
                    "\tldrb r1, [r0]\n"
                    "\tmov r2, r10\n"
                    "\tands r1, r2\n"
                    "\tmovs r2, 0x1\n"
                    "\tb _080E7CC6\n"
                    "_080E7CBA:\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x37\n"
                    "\tldrb r1, [r0]\n"
                    "\tmov r3, r10\n"
                    "\tands r1, r3\n"
                    "\tmovs r2, 0x2\n"
                    "_080E7CC6:\n"
                    "\torrs r1, r2\n"
                    "\tstrb r1, [r0]\n"
                    "\tadds r4, r0, 0\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x2C\n"
                    "\tbl IsStringJapanese\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CE2\n"
                    "\tldrb r0, [r4]\n"
                    "\tmovs r1, 0xF\n"
                    "\tands r1, r0\n"
                    "\tmovs r0, 0x10\n"
                    "\tb _080E7CEA\n"
                    "_080E7CE2:\n"
                    "\tldrb r0, [r4]\n"
                    "\tmovs r1, 0xF\n"
                    "\tands r1, r0\n"
                    "\tmovs r0, 0x20\n"
                    "_080E7CEA:\n"
                    "\torrs r1, r0\n"
                    "\tstrb r1, [r4]\n"
                    "_080E7CEE:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcc _080E7C24\n"
                    "_080E7CFA:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "_080E7D04:\n"
                    "\tbl GetLinkPlayerCount\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tcmp r8, r0\n"
                    "\tbcs _080E7D12\n"
                    "\tb _080E7BF8\n"
                    "_080E7D12:\n"
                    "\tmovs r0, 0\n"
                    "\tstr r0, [sp, 0x34]\n"
                    "\tmov r8, r0\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tlsrs r0, r1, 16\n"
                    "\tldr r2, [sp, 0x34]\n"
                    "\tcmp r2, r0\n"
                    "\tbcs _080E7D70\n"
                    "\tadds r5, r0, 0\n"
                    "_080E7D24:\n"
                    "\tldr r3, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r3\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tadds r7, r1, r0\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7D62\n"
                    "\tmovs r6, 0\n"
                    "\tcmp r6, r0\n"
                    "\tbcs _080E7D62\n"
                    "\tadds r3, r7, 0\n"
                    "\tadds r3, 0x74\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tmov r0, r8\n"
                    "\tlsls r1, r0, 1\n"
                    "\tmovs r4, 0x1\n"
                    "_080E7D46:\n"
                    "\tlsls r0, r6, 1\n"
                    "\tadds r0, r3, r0\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E7D56\n"
                    "\tadds r0, r6, r1\n"
                    "\tadds r0, r2, r0\n"
                    "\tstrb r4, [r0]\n"
                    "_080E7D56:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcc _080E7D46\n"
                    "_080E7D62:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r8, r5\n"
                    "\tbcc _080E7D24\n"
                    "_080E7D70:\n"
                    "\tmovs r6, 0\n"
                    "\tmov r8, r6\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E64\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tmov r10, r2\n"
                    "\tmovs r3, 0x25\n"
                    "\tadd r3, sp\n"
                    "\tmov r9, r3\n"
                    "_080E7D84:\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r1\n"
                    "\tldr r2, [sp, 0x2C]\n"
                    "\tadds r7, r2, r0\n"
                    "\tmov r3, r8\n"
                    "\tlsls r1, r3, 1\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbeq _080E7DA6\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7DB0\n"
                    "_080E7DA6:\n"
                    "\tldr r0, [sp, 0x34]\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tstr r0, [sp, 0x34]\n"
                    "_080E7DB0:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7DD4\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r2, [r0]\n"
                    "\tcmp r2, 0\n"
                    "\tbne _080E7DD4\n"
                    "_080E7DC4:\n"
                    "\tlsls r1, r6, 1\n"
                    "\tmov r3, r10\n"
                    "\tadds r0, r3, r1\n"
                    "\tmov r3, r8\n"
                    "\tstrb r3, [r0]\n"
                    "\tadd r1, r9\n"
                    "\tstrb r2, [r1]\n"
                    "\tb _080E7E4E\n"
                    "_080E7DD4:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E7DE8\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r2, [r0]\n"
                    "\tcmp r2, 0x1\n"
                    "\tbeq _080E7DC4\n"
                    "_080E7DE8:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7E54\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7E54\n"
                    "\tlsls r5, r6, 1\n"
                    "\tmov r1, r10\n"
                    "\tadds r0, r1, r5\n"
                    "\tmov r2, r8\n"
                    "\tstrb r2, [r0]\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl sub_80E7A9C\n"
                    "\tadds r4, r0, 0\n"
                    "\tlsls r4, 24\n"
                    "\tlsrs r4, 24\n"
                    "\tadds r0, r7, 0\n"
                    "\tadds r0, 0x38\n"
                    "\tbl sub_80E7A9C\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tcmp r4, 0\n"
                    "\tbne _080E7E30\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E34\n"
                    "\tmov r3, r9\n"
                    "\tadds r1, r3, r5\n"
                    "\tmovs r0, 0x1\n"
                    "\tstrb r0, [r1]\n"
                    "\tb _080E7E4E\n"
                    "_080E7E30:\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E48\n"
                    "_080E7E34:\n"
                    "\tbl Random2\n"
                    "\tmov r1, r9\n"
                    "\tadds r2, r1, r5\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmovs r1, 0x1\n"
                    "\tands r0, r1\n"
                    "\tstrb r0, [r2]\n"
                    "\tb _080E7E4E\n"
                    "_080E7E48:\n"
                    "\tmov r2, r9\n"
                    "\tadds r0, r2, r5\n"
                    "\tstrb r1, [r0]\n"
                    "_080E7E4E:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "_080E7E54:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r3, r0, 16\n"
                    "\tmov r8, r3\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tcmp r0, r1\n"
                    "\tbcc _080E7D84\n"
                    "_080E7E64:\n"
                    "\tmovs r2, 0\n"
                    "\tmov r8, r2\n"
                    "\tldr r3, [sp, 0x44]\n"
                    "\tlsls r0, r3, 4\n"
                    "\tsubs r0, r3\n"
                    "\tlsls r0, 3\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tadds r7, r1, r0\n"
                    "\tldr r1, [sp, 0x48]\n"
                    "_080E7E76:\n"
                    "\tmov r2, r8\n"
                    "\tlsls r0, r2, 2\n"
                    "\tadds r0, r1, r0\n"
                    "\tstr r7, [r0]\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r0, 0x3\n"
                    "\tbls _080E7E76\n"
                    "\tbl sub_80E7B54\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tmovs r1, 0x3\n"
                    "\tbl __umodsi3\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tldr r3, [sp, 0x34]\n"
                    "\tcmp r3, 0x3\n"
                    "\tbeq _080E7EC8\n"
                    "\tcmp r3, 0x3\n"
                    "\tbgt _080E7EAE\n"
                    "\tcmp r3, 0x2\n"
                    "\tbeq _080E7EB6\n"
                    "\tb _080E7F1C\n"
                    "_080E7EAE:\n"
                    "\tldr r0, [sp, 0x34]\n"
                    "\tcmp r0, 0x4\n"
                    "\tbeq _080E7EE8\n"
                    "\tb _080E7F1C\n"
                    "_080E7EB6:\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tmovs r0, 0x1\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmovs r3, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "\tb _080E7F1C\n"
                    "_080E7EC8:\n"
                    "\tldr r0, =gUnknown_0858CFB8\n"
                    "\tlsls r1, 1\n"
                    "\tadds r2, r1, r0\n"
                    "\tldrb r3, [r2]\n"
                    "\tadds r0, 0x1\n"
                    "\tadds r1, r0\n"
                    "\tldrb r0, [r1]\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tbl sub_80E7AA4\n"
                    "\tb _080E7F1C\n"
                    "\t.pool\n"
                    "_080E7EE8:\n"
                    "\tadd r6, sp, 0x24\n"
                    "\tldr r4, =gUnknown_0858CFBE\n"
                    "\tlsls r5, r1, 2\n"
                    "\tadds r0, r5, r4\n"
                    "\tldrb r3, [r0]\n"
                    "\tadds r0, r4, 0x1\n"
                    "\tadds r0, r5, r0\n"
                    "\tldrb r0, [r0]\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tadds r2, r6, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "\tadds r0, r4, 0x2\n"
                    "\tadds r0, r5, r0\n"
                    "\tldrb r3, [r0]\n"
                    "\tadds r4, 0x3\n"
                    "\tadds r5, r4\n"
                    "\tldrb r0, [r5]\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tadds r2, r6, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "_080E7F1C:\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tldr r2, [sp, 0x44]\n"
                    "\tadds r7, r1, r2\n"
                    "\tldr r4, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r4]\n"
                    "\tmovs r3, 0xC2\n"
                    "\tlsls r3, 6\n"
                    "\tadds r0, r3\n"
                    "\tadds r1, r7, 0\n"
                    "\tmovs r2, 0x38\n"
                    "\tbl memcpy\n"
                    "\tldr r0, [r4]\n"
                    "\tldr r1, =0x0000310c\n"
                    "\tadds r0, r1\n"
                    "\tadds r1, r7, 0\n"
                    "\tadds r1, 0x38\n"
                    "\tmovs r2, 0x38\n"
                    "\tbl memcpy\n"
                    "\tldr r0, [sp, 0x38]\n"
                    "\tbl SeedRng\n"
                    "\tadd sp, 0x58\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif // NONMATCHING

static void sub_80E7F68(u16 *item, u8 which)
{
    if (which != 0 && *item != ITEM_NONE && GetPocketByItemId(*item) == BAG_KEYITEMS)
    {
        if (!CheckBagHasItem(*item, 1) && !CheckPCHasItem(*item, 1) && AddBagItem(*item, 1))
        {
            VarSet(VAR_0x4001, *item);
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            if (*item == ITEM_EON_TICKET)
            {
                FlagSet(FLAG_SYS_HAS_EON_TICKET);
            }
        }
        else
        {
            VarSet(VAR_0x4001, ITEM_NONE);
        }
    }
}

static void sub_80E7FF8(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    switch (task->data[0])
    {
        case 0:
            task->data[0] ++;
            break;
        case 1:
            if (Link_AnyPartnersPlayingRubyOrSapphire())
            {
                task->data[0] ++;
            }
            else
            {
                task->data[0] = 6;
            }
            break;
        case 2:
            sub_8076D5C();
            sub_8153430();
            task->data[0] ++;
            break;
        case 3:
            if (sub_8153474())
            {
                sav2_gender2_inplace_and_xFE();
                task->data[0] = 4;
                task->data[1] = 0;
            }
            break;
        case 4:
            if (++ task->data[1] > 10)
            {
                sub_800AC34();
                task->data[0] ++;
            }
            break;
        case 5:
            if (gReceivedRemoteLinkPlayers == 0)
            {
                DestroyTask(taskId);
            }
            break;
        case 6:
            if (!sub_801048C(0))
            {
                CreateTask(sub_8153688, 5);
                task->data[0] ++;
            }
            break;
        case 7:
            if (!FuncIsActiveTask(sub_8153688))
            {
                if (gLinkVSyncDisabled)
                {
                    sub_801048C(1);
                    task->data[0] = 8;
                }
                else
                {
                    task->data[0] = 4;
                }
            }
            break;
        case 8:
            sub_800ADF8();
            task->data[0] ++;
            break;
        case 9:
            if (sub_800A520())
            {
                DestroyTask(taskId);
            }
            break;
    }
}

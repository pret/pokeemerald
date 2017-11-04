
// Includes
#include "global.h"
#include "task.h"
#include "cable_club.h"
#include "link.h"
#include "tv.h"
#include "battle_tower.h"
#include "mystery_event_script.h"
#include "secret_base.h"
#include "mauville_old_man.h"
#include "record_mixing.h"

// Static type declarations

struct RecordMixingData {
    struct SecretBaseRecord secretBases[20];
    TVShow tvShows[25];
    PokeNews pokeNews[16];
    OldMan oldMan;
    struct EasyChatPair easyChatPair[5];
    u8 unk_10ac[0x78];
    u8 unk_1124[0xa4];
    u16 unk_11c8;
    u8 unk_11ca[0x27a];
};

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
EWRAM_DATA struct {
    /*0x0000*/ u8 filler_0000[0x5110];
} *gUnknown_0203A014 = NULL;
EWRAM_DATA struct RecordMixingData *gUnknown_0203A018 = NULL;

// Static ROM declarations

void sub_80E715C(u8 taskId);
void sub_80E89F8(void *dest);
void sub_80E8A54(void *src);
void TaskDummy4(void *src);

// .rodata

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

void sub_80E6CA0(struct RecordMixingData *dest)
{
    memcpy(dest->secretBases, gUnknown_03001134, sizeof(struct SecretBaseRecord) * 20);
    memcpy(dest->tvShows, gUnknown_03001138, sizeof(TVShow) * 25);
    sub_80F14F8(dest->tvShows);
    memcpy(dest->pokeNews, gUnknown_0300113C, sizeof(PokeNews) * 16);
    memcpy(&dest->oldMan, gUnknown_03001140, sizeof(OldMan));
    memcpy(dest->easyChatPair, gUnknown_03001144, sizeof(struct EasyChatPair) * 5);
    sub_80E89F8(dest->unk_10ac);
    sub_81659DC(gUnknown_0300114C, dest->unk_1124);
    if (GetMultiplayerId() == 0)
    {
        dest->unk_11c8 = sub_81539D4();
    }
}

void sub_80E6D54(struct RecordMixingData *dest)
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
    sub_81659DC(gUnknown_0300114C, dest->unk_1124);
    TaskDummy4(dest->unk_1124);
    if (GetMultiplayerId() == 0)
    {
        dest->unk_11c8 = sub_81539D4();
    }
}

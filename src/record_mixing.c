
// Includes
#include "global.h"
#include "task.h"
#include "cable_club.h"
#include "record_mixing.h"

// Static type declarations

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
EWRAM_DATA struct {
    /*0x0000*/ u8 filler_0000[0x1444];
} *gUnknown_0203A018 = NULL;

// Static ROM declarations

void sub_80E715C(u8 taskId);

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

#include "global.h"
#include "alloc.h"
#include "link.h"
#include "task.h"
#include "main.h"
#include "constants/songs.h"
#include "sound.h"

struct DodrioBerryPickingSubstruct_004A
{
    /*0x00*/ u16 unk00;
    /*0x02*/ u8 filler02[10];
}; // size = 0x0C

struct DodrioBerryPickingSubstruct_31A0
{
    u8 unk_00[0x3C - 0x00];
}; // size = 0x3C

struct DodrioBerryPickingSubstruct_318C
{
    bool8 isShiny;
};

struct DodrioBerryPickingStruct
{
    /*0x0000*/ void (*savedCallback)(void);
    /*0x0004*/ u8 filler_0004[8];
    /*0x000C*/ u8 unk_000C;
    /*0x000D*/ u8 filler_000D[3];
    /*0x0010*/ u8 unk_0010;
    /*0x0011*/ u8 filler_0011[3];
    /*0x0014*/ u8 unk_0014;
    /*0x0015*/ u8 filler_0015[3];
    /*0x0018*/ u8 unk_0018;
    /*0x0019*/ u8 filler_0019[3];
    /*0x001C*/ u8 unk_001C;
    /*0x001D*/ u8 filler_001D[3];
    /*0x0020*/ u8 unk_0020;
    /*0x0021*/ u8 filler_0021[3];
    /*0x0024*/ u8 unk_0024;
    /*0x0025*/ u8 filler_0025[3];
    /*0x0028*/ u8 multiplayerId;
    /*0x0029*/ u8 filler_0029[7];
    /*0x0030*/ u8 unk_0030;
    /*0x0031*/ u8 filler_0031[3];
    /*0x0034*/ u8 unk_0034[5];
    /*0x0039*/ u8 filler_0039[3];
    /*0x003C*/ u8 unk_003C;
    /*0x003D*/ u8 filler_003D[3];
    /*0x0040*/ u8 unk_0040;
    /*0x0041*/ u8 filler_0041[3];
    /*0x0044*/ u8 unk_0044;
    /*0x0045*/ u8 filler_0045[3];
    /*0x0048*/ u8 unk_0048;
    // align 1
    /*0x004A*/ u16 unk_004A[5][6];
    /*0x0086*/ u8 filler_0086[18];
    /*0x0098*/ u8 unk_0098[4];
    /*0x009C*/ u8 filler_009C[12];
    /*0x00A8*/ u8 unk_00A8[5];
    /*0x00AD*/ u8 filler_00AD[3];
    /*0x00B0*/ u8 unk_00B0[5];
    /*0x00B5*/ u8 filler_00B5[0xC4 - 0xB5];
    /*0x00C4*/ u8 unk_00C4[11];
    /*0x00CF*/ u8 filler_00CF[1];
    /*0x00D0*/ u8 unk_00D0[11];
    /*0x00DB*/ u8 filler_00DB[1];
    /*0x00DC*/ u8 unk_00DC[11];
    /*0x00E7*/ u8 filler_0xE7[0xF4 - 0xE7];
    /*0x00F4*/ u8 unk_00F4[11][2];
    /*0x010A*/ u8 filler_010A[2];
    /*0x010C*/ u8 unk_010C[5];
    /*0x0111*/ u8 filler_0111[11];
    /*0x011C*/ u32 unk_011C;
    /*0x0120*/ u32 unk_0120;
    /*0x0124*/ u8 filler_0124[8];
    /*0x012C*/ u32 unk_012C;
    /*0x0130*/ u32 unk_0130[5];
    /*0x0144*/ u8 filler_0144[0x318C - 0x0144];
    /*0x318C*/ struct DodrioBerryPickingSubstruct_318C unk_318C[5];
    /*0x31A0*/ struct DodrioBerryPickingSubstruct_31A0 unk_31A0[5];
    /*0x32CC*/ struct DodrioBerryPickingSubstruct_31A0 unk_32CC;
    /*0x3308*/ u8 unk_3308[0x3330 - 0x3308];
}; // size = 0x3330

EWRAM_DATA struct DodrioBerryPickingStruct * gUnknown_02022C98 = NULL;
IWRAM_DATA bool32 gUnknown_03000DB0;

void sub_8024A1C(void);
void sub_8024A30(struct DodrioBerryPickingStruct *);
void sub_8024BC8(u8 taskId);
void sub_80261F8(struct DodrioBerryPickingSubstruct_318C *, struct Pokemon *);
void sub_80261CC(void);
void sub_8026B5C(u8, u8*, u8*);
void sub_80273F0(void);

void sub_802493C(u16 a0, void (*a1)(void))
{
    gUnknown_03000DB0 = FALSE;

    if (gReceivedRemoteLinkPlayers != 0 && (gUnknown_02022C98 = AllocZeroed(sizeof(*gUnknown_02022C98))) != NULL)
    {
        sub_8024A1C();
        sub_8024A30(gUnknown_02022C98);
        gUnknown_02022C98->savedCallback = a1;
        gUnknown_02022C98->multiplayerId = GetMultiplayerId();
        gUnknown_02022C98->unk_32CC = gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId];
        sub_80261F8(&gUnknown_02022C98->unk_318C[gUnknown_02022C98->multiplayerId], &gPlayerParty[a0]);
        CreateTask(sub_8024BC8, 1);
        SetMainCallback2(sub_80261CC);
        sub_80273F0();
        sub_8026B5C(gUnknown_02022C98->unk_0024, &gUnknown_02022C98->unk_0044, &gUnknown_02022C98->unk_0048);
        StopMapMusic();
        PlayNewMapMusic(MUS_RG_KINOMIKUI);
    }
    else
    {
        SetMainCallback2(a1);
        return;
    }
}

void sub_8024A1C(void)
{
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
}

void sub_8024A30(struct DodrioBerryPickingStruct * data)
{
    u8 i;

    data->unk_000C = 0;
    data->unk_0010 = 0;
    data->unk_0014 = 0;
    data->unk_0018 = 0;
    data->unk_001C = 0;
    data->unk_011C = 0;
    data->unk_0120 = 0;
    data->unk_0030 = 0;
    data->unk_0040 = 0;
    data->unk_003C = 0;
    data->unk_012C = 0;

    for (i = 0; i < 4; i++)
    {
        data->unk_0098[i] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        data->unk_00A8[i] = 0;
        data->unk_00B0[i] = 0;
        data->unk_004A[i][0] = 0;
        data->unk_004A[i][1] = 0;
        data->unk_004A[i][2] = 0;
        data->unk_004A[i][3] = 0;
        data->unk_004A[i][5] = 0;
        data->unk_010C[i] = 0;
        data->unk_0130[i] = 0;
    }

    for (i = 0; i < 11; i++)
    {
        data->unk_00D0[i] = 0;
        data->unk_00DC[i] = 0;
        data->unk_00C4[i] = 0;
        data->unk_00F4[i][0] = 0xFF;
        data->unk_00F4[i][1] = 0xFF;
    }

    data->unk_0020 = GetMultiplayerId() == 0 ? 1 : 0;
    data->unk_0024 = GetLinkPlayerCount();
    data->unk_0034[0] = GetMultiplayerId();
    for (i = 1; i < data->unk_0024; i++)
    {
        data->unk_0034[i] = data->unk_0034[i - 1] + 1;
        if (data->unk_0034[i] > data->unk_0024 - 1)
            data->unk_0034[i] %= data->unk_0024;
    }
}

#include "global.h"
#include "alloc.h"
#include "palette.h"
#include "window.h"
#include "bg.h"
#include "link.h"
#include "link_rfu.h"
#include "task.h"
#include "main.h"
#include "constants/songs.h"
#include "sound.h"
#include "pokemon_jump.h"

struct DodrioBerryPickingSubstruct_0160
{
    /*0x0000 : 0x0160*/ u8 filler_000[12];
    /*0x000C : 0x016C*/ u8 unk_00C;
    /*0x000D : 0x016D*/ u8 filler_00D[0x3000 - 0xd];
    /*0x3000 : 0x3160*/ u32 unk_3000;
    /*0x3004 : 0x3164*/ u8 filler_3004[16];
    /*0x3014 : 0x3174*/ u8 unk_3014;
    /*0x3015 : 0x3175*/ u8 filler_3015[0x318C - 0x3175];
}; // size = 0x302C

struct DodrioBerryPickingStruct_2022CF4
{
    u8 filler_00[0x40];
}; // size = 0x40

struct DodrioBerryPickingSubstruct_31A0
{
    u8 unk_00[0x10];
    u32 unk_10;
    u8 filler_14[0x18];
    u8 unk_2C;
    u8 filler_2D[3];
    u8 unk_30;
    u8 filler_31[3];
    u8 unk_34;
    u8 filler_35[7];
}; // size = 0x3C

struct DodrioBerryPickingSubstruct_318C
{
    bool8 isShiny;
};

struct DodrioBerryPickingStruct
{
    /*0x0000*/ void (*savedCallback)(void);
    /*0x0004*/ u8 unk_0004;
    /*0x0005*/ u8 filler_0005[3];
    /*0x0008*/ u8 unk_0008;
    /*0x0009*/ u8 filler_0009[3];
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
    /*0x0111*/ u8 filler_0111[3];
    /*0x0114*/ u16 unk_0114;
    // align 2
    /*0x0118*/ u32 unk_0118;
    /*0x011C*/ u32 unk_011C;
    /*0x0120*/ u32 unk_0120;
    /*0x0124*/ u8 unk_0124;
    /*0x0125*/ u8 filler_0125[3];
    /*0x0128*/ u8 unk_0128;
    // align 2
    /*0x012C*/ u32 unk_012C;
    /*0x0130*/ u32 unk_0130[5];
    /*0x0144*/ u8 filler_0144[0x1C];
    /*0x0160*/ struct DodrioBerryPickingSubstruct_0160 unk_0160;
    /*0x318C*/ struct DodrioBerryPickingSubstruct_318C unk_318C[5];
    /*0x31A0*/ struct DodrioBerryPickingSubstruct_31A0 unk_31A0[5];
    /*0x32CC*/ struct DodrioBerryPickingSubstruct_31A0 unk_32CC;
    /*0x3308*/ u8 unk_3308[0x3330 - 0x3308];
}; // size = 0x3330

EWRAM_DATA struct DodrioBerryPickingStruct * gUnknown_02022C98 = NULL;
EWRAM_DATA u16 * gUnknown_02022C9C[5] = {NULL};
EWRAM_DATA u16 * gUnknown_02022CB0[2] = {NULL};
EWRAM_DATA u16 * gUnknown_02022CB8[11] = {NULL};
EWRAM_DATA u16 * gUnknown_02022CE4[4] = {NULL};
EWRAM_DATA struct DodrioBerryPickingStruct_2022CF4 * gUnknown_02022CF4 = NULL;
EWRAM_DATA struct DodrioBerryPickingSubstruct_0160 * gUnknown_02022CF8 = NULL;

IWRAM_DATA bool32 gUnknown_03000DB0;

void sub_8024A1C(void);
void sub_8024A30(struct DodrioBerryPickingStruct *);
void sub_8024BC8(u8 taskId);
void sub_8024DBC(void);
void sub_8024E00(void);
void sub_8024E38(void);
void sub_8024F10(void);
void sub_8024F38(void);
void sub_8024FFC(void);
void sub_80250D4(void);
void sub_8025158(void);
void sub_8025198(void);
void sub_8025230(void);
void sub_8025324(void);
void sub_8025470(void);
void sub_8025644(void);
void sub_80256AC(void);
void sub_8025758(void);
void sub_802589C(u8 taskId);
void sub_8025910(u8 taskId);
void sub_8025D04(void);
void sub_8025D50(void);
void sub_8025E0C(void);
void sub_8025ED8(void);
void sub_8025F48(void);
void sub_8026044(void);
void sub_80261CC(void);
void sub_80261E4(void);
void sub_80261F8(struct DodrioBerryPickingSubstruct_318C *, struct Pokemon *);
void sub_802620C(TaskFunc, u8);
void sub_802621C(TaskFunc);
void sub_8026240(u8);
bool32 sub_8026264(void);
void sub_80262C0(void);
void sub_802671C(void);
void sub_8026AF4(void);
void sub_8026B28(void);
void sub_8026B5C(u8, u8*, u8*);
bool32 sub_8026C50(void);
bool32 sub_8026C90(void);
void sub_80272E8(void);
void sub_80272A4(void);
void sub_80273F0(void);
void sub_802749C(void);
u8 sub_8027518(u8);
void sub_8027554(void);
void sub_8027608(void);
u32 sub_8027748(void);
u32 sub_8028164(u32 unused, struct DodrioBerryPickingSubstruct_31A0 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32 *, u32 *);
u32 sub_8028318(u8, u8 *);
void sub_80283A8(void);
void sub_8028408(struct DodrioBerryPickingSubstruct_318C *, u8, u8, u8);
void sub_8028504(u8);
void sub_8028614(u8);
void sub_802868C(u8, u8);
void sub_8028734(void);
void sub_80287E4(void);
void sub_80289E8(u8);
void sub_80286E4(void);
bool32 sub_8028828(void);
void sub_8028A34(void);
void sub_8028A88(void);
void sub_8028B80(void);
void sub_8028D44(void);
void sub_8028DFC(void);
void sub_8028E4C(void);
void sub_8028E84(void);
void sub_8028EC8(u8);
void sub_8028FCC(void);
void sub_802903C(void);
void sub_8029274(struct DodrioBerryPickingSubstruct_0160 *);
void sub_80292E0(u8);
bool32 sub_802A770(void);
u8 sub_802A794(void);

extern void (*const gUnknown_082F7AC4[])(void);
extern void (*const gUnknown_082F7AF4[])(void);

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

void sub_8024BC8(u8 taskId)
{
    u8 r4, r5;

    switch (gUnknown_02022C98->unk_000C)
    {
        case 0:
            SetVBlankCallback(NULL);
            sub_802620C(sub_8025910, 4);
            gUnknown_02022C98->unk_000C++;
            break;
        case 1:
            if (!FuncIsActiveTask(sub_8025910))
            {
                sub_8029274(&gUnknown_02022C98->unk_0160);
                gUnknown_02022C98->unk_000C++;
            }
            break;
        case 2:
            if (!sub_802A770())
            {
                sub_8010434();
                gUnknown_02022C98->unk_000C++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished())
            {
                if (gReceivedRemoteLinkPlayers != 0)
                {
                    sub_800E0E8();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                }
                gUnknown_02022C98->unk_000C++;
            }
            break;
        case 4:
            r5 = gUnknown_02022C98->unk_0024;
            sub_80283A8();
            for (r4 = 0; r4 < r5; r4++)
            {
                sub_8028408(&gUnknown_02022C98->unk_318C[gUnknown_02022C98->unk_0034[r4]], r4, gUnknown_02022C98->unk_0034[r4], gUnknown_02022C98->unk_0024);
            }
            sub_802868C(0, gUnknown_02022C98->unk_0024);
            gUnknown_02022C98->unk_000C++;
            break;
        case 5:
            sub_8028A34();
            sub_8028A88();
            sub_8028D44();
            sub_8028734();
            gUnknown_02022C98->unk_000C++;
            break;
        case 6:
            BlendPalettes(0xFFFFFFFF, 0x10, 0x00);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
            SetVBlankCallback(sub_80261E4);
            gUnknown_02022C98->unk_000C++;
            break;
        case 7:
            UpdatePaletteFade();
            if (!gPaletteFade.active)
            {
                gUnknown_02022C98->unk_000C++;
            }
            break;
        default:
            DestroyTask(taskId);
            sub_802621C(sub_802589C);
            break;
    }
}

void sub_8024D4C(u8 taskId)
{
    sub_8025D04();
    gUnknown_082F7AC4[gUnknown_02022C98->unk_0018]();
    if (gUnknown_03000DB0 == FALSE)
    {
        sub_8026AF4();
    }
    sub_8025D50();
}

void sub_8024D84(u8 taskId)
{
    sub_8025E0C();
    gUnknown_082F7AF4[gUnknown_02022C98->unk_0018]();
    if (gUnknown_03000DB0 == FALSE)
    {
        sub_8026B28();
    }
    sub_8025ED8();
}

void sub_8024DBC(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            sub_8028504(1);
            sub_80292E0(1);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            if (!sub_802A770())
                sub_8026240(1);
            break;
    }
}

void sub_8024E00(void)
{
    if (gUnknown_02022C98->unk_0010 == 0)
    {
        sub_80262C0();
        gUnknown_02022C98->unk_0010++;
    }
    else
    {
        gUnknown_02022C98->unk_0118 = 1;
        sub_8026240(2);
    }
}

void sub_8024E38(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            sub_802EB24(7, 8, 120, 80, 0);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            sub_8010434();
            gUnknown_02022C98->unk_0010++;
            break;
        case 2:
            if (IsLinkTaskFinished())
            {
                gUnknown_02022C98->unk_0010++;
                gUnknown_02022C98->unk_0030 = 0;
            }
            break;
        case 3:
            if (!sub_802EB84())
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 4:
            if (++gUnknown_02022C98->unk_0030 > 5)
            {
                sub_8010434();
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 5:
            if (IsLinkTaskFinished())
            {
                sub_8026240(3);
            }
            break;
    }
}

void sub_8024F10(void)
{
    if (gUnknown_02022C98->unk_0010 == 0)
    {
        if (gUnknown_02022C98->unk_011C != 0)
        {
            sub_8026240(4);
        }
    }
}

void sub_8024F38(void)
{
    if (gUnknown_02022C98->unk_0010 == 0)
    {
        if (gUnknown_02022C98->unk_0040 < 10)
        {
            if (gUnknown_02022C98->unk_00A8[0] == 0)
            {
                if (JOY_NEW(DPAD_UP))
                {
                    if (gUnknown_02022C98->unk_31A0[0].unk_2C == 0)
                    {
                        gUnknown_02022C98->unk_31A0[0].unk_30 = 0;
                        gUnknown_02022C98->unk_31A0[0].unk_2C = sub_8027518(2);
                    }
                }
                else if (JOY_NEW(DPAD_RIGHT))
                {
                    if (gUnknown_02022C98->unk_31A0[0].unk_2C == 0)
                    {
                        gUnknown_02022C98->unk_31A0[0].unk_30 = 0;
                        gUnknown_02022C98->unk_31A0[0].unk_2C = sub_8027518(1);
                    }
                }
                else if (JOY_NEW(DPAD_LEFT))
                {
                    if (gUnknown_02022C98->unk_31A0[0].unk_2C == 0)
                    {
                        gUnknown_02022C98->unk_31A0[0].unk_30 = 0;
                        gUnknown_02022C98->unk_31A0[0].unk_2C = sub_8027518(3);
                    }
                }
                else
                {
                    gUnknown_02022C98->unk_31A0[0].unk_2C = sub_8027518(0);
                }
            }
        }
        else
        {
            sub_8026240(11);
        }
        sub_802671C();
        sub_8025F48();
    }
}

void sub_8024FFC(void)
{
    if (gUnknown_02022C98->unk_0040 < 10)
    {
        if (JOY_NEW(DPAD_UP))
        {
            if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_2C == 0)
            {
                gUnknown_02022C98->unk_32CC.unk_2C = 2;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_2C == 0)
            {
                gUnknown_02022C98->unk_32CC.unk_2C = 1;
            }
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_2C == 0)
            {
                gUnknown_02022C98->unk_32CC.unk_2C = 3;
            }
        }
        else
        {
            gUnknown_02022C98->unk_32CC.unk_2C = 0;
        }
    }
    else
    {
        sub_8026240(11);
    }
    sub_8026044();
}

void sub_80250D4(void)
{
    u8 i;

    sub_802671C();
    sub_8025F48();
    if (sub_8026C50() == 1)
    {
        sub_80272A4();
        sub_8026240(5);
    }
    else
    {
        gUnknown_02022C98->unk_012C = 1;
        for (i = 1; i < gUnknown_02022C98->unk_0024; i++)
        {
            if (gUnknown_02022C98->unk_0130[i] != 1)
            {
                gUnknown_02022C98->unk_012C = 0;
                break;
            }
        }
    }
}

void sub_8025158(void)
{
    sub_8026044();
    if (sub_8026C90() == 1)
        sub_8026240(5);
}

bool32 sub_8025170(void)
{
    u8 r4 = GetBlockReceivedStatus();
    u8 r0 = sub_800A9D8();
    if (r4 == r0)
    {
        ResetBlockReceivedFlags();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sub_8025198(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            if (SendBlock(0, gUnknown_02022C98->unk_004A, sizeof(gUnknown_02022C98->unk_004A)))
            {
                gUnknown_02022C98->unk_0008 = 0;
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished())
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            if (sub_8025170())
            {
                gUnknown_02022C98->unk_0008 = gUnknown_02022C98->unk_0024;
            }
            if (gUnknown_02022C98->unk_0008 >= gUnknown_02022C98->unk_0024)
            {
                gUnknown_02022C98->unk_0014++;
                gUnknown_02022C98->unk_0010++;
            }
            break;
        default:
            if (WaitFanfare(TRUE))
            {
                sub_8026240(6);
                FadeOutAndPlayNewMapMusic(MUS_RG_WIN_YASEI, 4);
            }
            break;
    }
}

void sub_8025230(void)
{
    u8 i;

    switch (gUnknown_02022C98->unk_0010) {
        case 0:
            if (SendBlock(0, gUnknown_02022C98->unk_004A[gUnknown_02022C98->unk_0014],
                          sizeof(gUnknown_02022C98->unk_004A))) {
                gUnknown_02022C98->unk_0008 = 0;
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished()) {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            if (sub_8025170()) {
                for (i = 0; i < gUnknown_02022C98->unk_0024; i++) {
                    memcpy(gUnknown_02022C98->unk_004A, gBlockRecvBuffer, sizeof(gUnknown_02022C98->unk_004A));
                    gUnknown_02022C98->unk_0008 = gUnknown_02022C98->unk_0024;
                }
            }
            if (gUnknown_02022C98->unk_0008 >= gUnknown_02022C98->unk_0024) {
                gUnknown_02022C98->unk_0014++;
                gUnknown_02022C98->unk_0010++;
            }
            break;
        default:
            if (WaitFanfare(TRUE)) {
                gUnknown_02022C98->unk_0114 = gUnknown_02022C98->unk_004A[gUnknown_02022C98->multiplayerId][5];
                sub_8026240(6);
                FadeOutAndPlayNewMapMusic(MUS_RG_WIN_YASEI, 4);
            }
            break;
    }
}

void sub_8025324(void)
{
    u8 sp00 = 1;
    u8 i;

    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            sub_802749C();
            sub_80289E8(1);
            sub_8028DFC();
            sub_8028EC8(1);
            sub_80292E0(2);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            if (!sub_802A770())
            {
                sub_80292E0(5);
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            sp00 = sub_802A794();
            if (SendBlock(0, &sp00, sizeof(sp00)))
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished())
            {
                gUnknown_02022C98->unk_0010++;
                gUnknown_02022C98->unk_0008 = 0;
            }
            break;
        case 4:
            if (sub_8025170())
            {
                for (i = 0; i < gUnknown_02022C98->unk_0024; i++)
                {
                    *(gUnknown_02022C98->unk_010C + i) = *(u8 *)gBlockRecvBuffer[i];
                    gUnknown_02022C98->unk_0008 = gUnknown_02022C98->unk_0024;
                }
            }
            if (gUnknown_02022C98->unk_0008 >= gUnknown_02022C98->unk_0024) {
                if (++gUnknown_02022C98->unk_0014 >= 120)
                {
                    sub_80292E0(6);
                    gUnknown_02022C98->unk_0010++;
                }
            }
            break;
        default:
            if (!sub_802A770())
            {
                sub_8026240(7);
            }
            break;
    }
}

void sub_8025470(void)
{
    u8 sp0;
    u8 i;

    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            if (sub_8027748() >= 3000)
            {
                sub_80292E0(4);
            }
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            if (!sub_802A770())
            {
                sub_80292E0(3);
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            sub_8028FCC();
            sub_80272E8();
            gUnknown_02022C98->unk_0010++;
            break;
        case 3:
            if ((sp0 = sub_802A794()) != 0)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 4:
            if (!sub_802A770())
            {
                sub_80292E0(5);
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 5:
            sp0 = sub_802A794();
            if (SendBlock(0, &sp0, sizeof(sp0)))
            {
                gUnknown_02022C98->unk_0008 = 0;
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 6:
            if (IsLinkTaskFinished())
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 7:
            if (sub_8025170())
            {
                for (i = 0; i < gUnknown_02022C98->unk_0024; i++)
                {
                    *(gUnknown_02022C98->unk_010C + i) = *(u8 *)gBlockRecvBuffer[i];
                    gUnknown_02022C98->unk_0008 = gUnknown_02022C98->unk_0024;
                }
            }
            if (gUnknown_02022C98->unk_0008 >= gUnknown_02022C98->unk_0024) {
                if (++gUnknown_02022C98->unk_0014 >= 120)
                {
                    sub_8027608();
                    sub_80292E0(6);
                    gUnknown_02022C98->unk_0010++;
                }
            }
            else
            {
                sub_8027554();
            }
            break;
        default:
            if (!sub_802A770())
            {
                for (i = 0; i < gUnknown_02022C98->unk_0024; i++)
                {
                    if (gUnknown_02022C98->unk_010C[i] == 2)
                    {
                        sub_8026240(8);
                        return;
                    }
                }
                sub_8026240(10);
            }
            break;
    }
}

void sub_8025644(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            sub_800AC34();
            sub_80292E0(7);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            if (!sub_802A770())
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            if (sub_802A794() == 5)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        default:
            if (gReceivedRemoteLinkPlayers == 0)
            {
                sub_8026240(9);
            }
            break;
    }
}

void sub_80256AC(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            UpdatePaletteFade();
            if (!gPaletteFade.active)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            sub_8028B80();
            sub_80287E4();
            sub_8028614(gUnknown_02022C98->unk_0024);
            sub_8028E84();
            gUnknown_03000DB0 = TRUE;
            sub_80292E0(8);
            gUnknown_02022C98->unk_0010++;
            break;
        default:
            if (!sub_802A770())
            {
                SetMainCallback2(gUnknown_02022C98->savedCallback);
                DestroyTask(gUnknown_02022C98->unk_0004);
                Free(gUnknown_02022C98);
                FreeAllWindowBuffers();
            }
            break;
    }
}

void sub_8025758(void)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            sub_80292E0(9);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
            gUnknown_02022C98->unk_0010++;
            break;
        case 1:
            UpdatePaletteFade();
            if (!gPaletteFade.active)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 2:
            ChangeBgX(0, 0, 0);
            ChangeBgY(0, 0, 0);
            ChangeBgX(1, 0, 0);
            ChangeBgY(1, 0, 0);
            ChangeBgX(2, 0, 0);
            ChangeBgY(2, 0, 0);
            ChangeBgX(3, 0, 0);
            ChangeBgY(3, 0, 0);
            gUnknown_02022C98->unk_0010++;
            break;
        case 3:
            StopMapMusic();
            gUnknown_02022C98->unk_0010++;
            break;
        case 4:
            PlayNewMapMusic(MUS_RG_KINOMIKUI);
            sub_8028E4C();
            gUnknown_02022C98->unk_0010++;
            break;
        case 5:
            BlendPalettes(0xFFFFFFFF, 16, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
            gUnknown_02022C98->unk_0010++;
            break;
        case 6:
            UpdatePaletteFade();
            if (!gPaletteFade.active)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        default:
            DestroyTask(gUnknown_02022C98->unk_0004);
            sub_802621C(sub_802589C);
            sub_802903C();
            sub_8024A30(gUnknown_02022C98);
            if (gReceivedRemoteLinkPlayers == 0)
            {
                gUnknown_02022C98->unk_0024 = 1;
            }
            sub_80273F0();
            sub_8028EC8(0);
            break;
    }
}

void sub_802589C(u8 taskId)
{
    switch (gUnknown_02022C98->unk_0010)
    {
        case 0:
            if (sub_8026264() == 1)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        case 1:
            sub_80286E4();
            gUnknown_02022C98->unk_0010++;
            break;
        case 2:
            if (sub_8028828() == 1)
            {
                gUnknown_02022C98->unk_0010++;
            }
            break;
        default:
            if (gUnknown_02022C98->unk_0020 != 0)
            {
                sub_802621C(sub_8024D4C);
            }
            else
            {
                sub_802621C(sub_8024D84);
            }
            DestroyTask(taskId);
            break;
    }
}

void sub_8025910(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 i;

    switch (data[0])
    {
        case 0:
            if (SendBlock(0, &gUnknown_02022C98->unk_318C[gUnknown_02022C98->multiplayerId].isShiny, sizeof(gUnknown_02022C98->unk_318C[gUnknown_02022C98->multiplayerId].isShiny)))
            {
                gUnknown_02022C98->unk_0008 = 0;
                data[0]++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished())
            {
                data[0]++;
            }
            break;
        case 2:
            if (sub_8025170())
            {
                for (i = 0; i < gUnknown_02022C98->unk_0024; i++)
                {
                    *(u8 *)&gUnknown_02022C98->unk_318C[i] = *(u8 *)gBlockRecvBuffer[i];
                    gUnknown_02022C98->unk_0008 = gUnknown_02022C98->unk_0024;
                }
            }
            if (gUnknown_02022C98->unk_0008 >= gUnknown_02022C98->unk_0024)
            {
                DestroyTask(taskId);
                sub_80292E0(6);
                gUnknown_02022C98->unk_0010++;
            }
            break;
    }
}

void sub_80259FC(void)
{
    u8 i;
    u8 r7 = gUnknown_02022C98->unk_0024;

    gUnknown_02022C98->unk_31A0[0].unk_10 = sub_8028164(0, &gUnknown_02022C98->unk_31A0[0], &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, &gUnknown_02022C98->unk_0040, &gUnknown_02022C98->unk_0120, &gUnknown_02022C98->unk_012C);
    gUnknown_02022C98->unk_0128 = 1;

    for (i = 1; i < r7; i++)
    {
        if (   gUnknown_02022C98->unk_00A8[i] == 0
            && sub_8028318(i, &gUnknown_02022C98->unk_31A0[i].unk_2C) == 0)
        {
            gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
            gUnknown_02022C98->unk_0128 = 0;
        }
    }
    if (++gUnknown_02022C98->unk_0124 >= 60)
    {
        if (gUnknown_02022C98->unk_0128 != 0)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk_0124 = 0;
        }
        else if (gUnknown_02022C98->unk_0124 > 70)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk_0124 = 0;
        }
    }

    for (i = 0; i < r7; i++)
    {
        if (   gUnknown_02022C98->unk_31A0[i].unk_2C != 0
            && gUnknown_02022C98->unk_00A8[i] == 0)
        {
            gUnknown_02022C98->unk_00A8[i] = 1;
        }
        switch (gUnknown_02022C98->unk_00A8[i])
        {
            case 0:
            default:
                break;
            case 1 ... 3:
                if (++gUnknown_02022C98->unk_00B0[i] >= 6)
                {
                    gUnknown_02022C98->unk_00B0[i] = 0;
                    gUnknown_02022C98->unk_00A8[i] = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_30 = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_34 = 0;
                }
                break;
            case 4:
                if (++gUnknown_02022C98->unk_00B0[i] >= 40)
                {
                    gUnknown_02022C98->unk_00B0[i] = 0;
                    gUnknown_02022C98->unk_00A8[i] = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_30 = 0;
                    gUnknown_02022C98->unk_31A0[i].unk_34 = 0;
                }
                break;
        }
    }
}

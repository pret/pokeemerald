#include "global.h"
#include "alloc.h"
#include "palette.h"
#include "window.h"
#include "bg.h"
#include "gpu_regs.h"
#include "random.h"
#include "link.h"
#include "link_rfu.h"
#include "task.h"
#include "main.h"
#include "constants/songs.h"
#include "sound.h"
#include "m4a.h"
#include "pokemon_jump.h"

struct DodrioBerryPickingSubstruct_0160
{
    /*0x0000 : 0x0160*/ u8 filler_000[12];
    /*0x000C : 0x016C*/ u8 unkC;
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

struct DodrioBerryPickingSubstruct_31A0_14
{
    u8 unk_0[11];
    u8 unk_B[11];
};

struct DodrioBerryPickingSubstruct_31A0
{
    u8 unk[0x10];
    u32 unk_10;
    struct DodrioBerryPickingSubstruct_31A0_14 unk_14;
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
    /*0x0004*/ u8 unk04;
    /*0x0005*/ u8 filler_0005[3];
    /*0x0008*/ u8 unk08;
    /*0x0009*/ u8 filler_0009[3];
    /*0x000C*/ u8 unk0C;
    /*0x000D*/ u8 filler_000D[3];
    /*0x0010*/ u8 unk10;
    /*0x0011*/ u8 filler_0011[3];
    /*0x0014*/ u8 unk14;
    /*0x0015*/ u8 filler_0015[3];
    /*0x0018*/ u8 unk18;
    /*0x0019*/ u8 filler_0019[3];
    /*0x001C*/ u8 unk1C;
    /*0x001D*/ u8 filler_001D[3];
    /*0x0020*/ u8 unk20;
    /*0x0021*/ u8 filler_0021[3];
    /*0x0024*/ u8 unk24;
    /*0x0025*/ u8 filler_0025[3];
    /*0x0028*/ u8 multiplayerId;
    /*0x0029*/ u8 filler_0029[7];
    /*0x0030*/ u8 unk30;
    /*0x0031*/ u8 filler_0031[3];
    /*0x0034*/ u8 unk34[5];
    /*0x0039*/ u8 filler_0039[3];
    /*0x003C*/ u8 unk3C;
    /*0x003D*/ u8 filler_003D[3];
    /*0x0040*/ u8 unk40;
    /*0x0041*/ u8 filler_0041[3];
    /*0x0044*/ u8 unk44;
    /*0x0045*/ u8 filler_0045[3];
    /*0x0048*/ u8 unk48;
    // align 1
    /*0x004A*/ u16 unk4A[5][6];
    /*0x0086*/ u16 unk86[5];
    /*0x0090*/ u8 unk90[5];
    /*0x0095*/ u8 filler_0095[3];
    /*0x0098*/ u8 unk98[4];
    /*0x009C*/ u8 unk9C[12];
    /*0x00A8*/ u8 unkA8[5];
    /*0x00AD*/ u8 filler_00AD[3];
    /*0x00B0*/ u8 unkB0[5];
    /*0x00B5*/ u8 filler_00B5[3];
    /*0x00B8*/ u8 unkB8[5];
    /*0x00BD*/ u8 filler_00BD[7];
    /*0x00C4*/ u8 unkC4[11];
    /*0x00CF*/ u8 filler_00CF[1];
    /*0x00D0*/ u8 unkD0[11];
    /*0x00DB*/ u8 filler_00DB[1];
    /*0x00DC*/ u8 unkDC[11];
    /*0x00E7*/ u8 filler_0xE7[1];
    /*0x00E8*/ u8 unkE8[5];
    /*0x00ED*/ u8 filler_00ED[7];
    /*0x00F4*/ u8 unkF4[11][2];
    /*0x010A*/ u8 filler_010A[2];
    /*0x010C*/ u8 unk10C[5];
    /*0x0111*/ u8 filler_0111[3];
    /*0x0114*/ u16 unk114;
    // align 2
    /*0x0118*/ u32 unk118;
    /*0x011C*/ u32 unk11C;
    /*0x0120*/ u32 unk120;
    /*0x0124*/ u8 unk124;
    /*0x0125*/ u8 filler_0125[3];
    /*0x0128*/ u8 unk128;
    // align 2
    /*0x012C*/ u32 unk12C;
    /*0x0130*/ u32 unk130[5];
    /*0x0144*/ u8 unk144;
    /*0x0145*/ u8 filler_0145[3];
    /*0x0148*/ u8 unk148[11];
    /*0x0153*/ u8 filler_0153[1];
    /*0x0154*/ u8 unk154;
    /*0x0155*/ u8 filler_0155[3];
    /*0x0158*/ u8 unk158[5];
    /*0x0160*/ struct DodrioBerryPickingSubstruct_0160 unk160;
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

static bool32 gUnknown_03000DB0;

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
bool32 sub_8026634(u8, u8, u8);
void sub_802671C(void);
void sub_8026AF4(void);
void sub_8026B28(void);
void sub_8026B5C(u8, u8*, u8*);
bool32 sub_8026BB8(void);
void sub_8026C28(void);
bool32 sub_8026C50(void);
bool32 sub_8026C90(void);
void sub_8026D1C(u8);
u8 sub_8026D8C(u8);
u8 sub_8026DB0(u8, u8);
void sub_8026F1C(u8, u8, u8);
void sub_8027234(u8);
void sub_80272A4(void);
void sub_80272E8(void);
void sub_80273F0(void);
void sub_802749C(void);
u8 sub_8027518(u8);
void sub_8027554(void);
void sub_8027608(void);
u32 sub_8027748(void);
void sub_8027DD0(u8);
u32 sub_8027E30(struct DodrioBerryPickingSubstruct_31A0 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8, u32, u32);
u32 sub_8028164(u32 unused, struct DodrioBerryPickingSubstruct_31A0 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32 *, u32 *);
void sub_80282EC(u8);
u32 sub_8028318(u8, u8 *);
void sub_8028350(u8);
bool32 sub_8028374(u8);
void sub_80283A8(void);
void sub_8028408(struct DodrioBerryPickingSubstruct_318C *, u8, u8, u8);
void sub_80284CC(u8);
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

extern const u8 gUnknown_082F7A88[][3];
extern const u8 gUnknown_082F7A94[];
extern const u8 gUnknown_082F7A9C[];
extern void (*const gUnknown_082F7AC4[])(void);
extern void (*const gUnknown_082F7AF4[])(void);

const u8 gUnknown_082F449C[5][5][11] =
{
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
	},
	{
		{0, 1, 2, 3, 4, 5, 6, 3, 8, 9, 0},
		{0, 1, 2, 5, 6, 3, 4, 5, 8, 9, 0},
	},
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 2, 9, 0},
		{0, 1, 4, 5, 6, 7, 2, 3, 4, 9, 0},
		{0, 1, 6, 7, 2, 3, 4, 5, 6, 9, 0},
	},
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 0},
		{0, 3, 4, 5, 6, 7, 8, 1, 2, 3, 0},
		{0, 5, 6, 7, 8, 1, 2, 3, 4, 5, 0},
		{0, 7, 8, 1, 2, 3, 4, 5, 6, 7, 0},
	},
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
		{2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
		{4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4},
		{6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6},
		{8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8},
	},
};

const u8 gUknnown_082F45AF[5][5][3] =
{
	{
		{4, 5, 6},
	},
	{
		{3, 4, 5},
		{5, 6, 3},
	},
	{
		{4, 5, 6},
		{6, 7, 2},
		{2, 3, 4},
	},
	{
		{3, 4, 5},
		{5, 6, 7},
		{7, 8, 1},
		{1, 2, 3},
	},
	{
		{4, 5, 6},
		{6, 7, 8},
		{8, 9, 0},
		{0, 1, 2},
		{2, 3, 4},
	},
};

const u8 gToFix[] =
{
	0x01, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x00, 0x01, 0x00, 0x01, 0x02, 0x01,
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x00, 0x01, 0x00, 0x01, 0x02, 0x01, 0x02,
	0x03, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04,
	0x00, 0x01, 0x00, 0x01, 0x02, 0x01, 0x02, 0x03,
	0x02, 0x03, 0x04, 0x03, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x09, 0x09, 0x09, 0x09, 0x01, 0x01, 0x01,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00,
	0x00, 0x01, 0x01, 0x00, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01,
	0x09, 0x09, 0x09, 0x03, 0x03, 0x00, 0x00, 0x01,
	0x01, 0x02, 0x02, 0x03, 0x09, 0x03, 0x03, 0x04,
	0x04, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03,
	0x05, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00,
	0x00, 0x00, 0x03, 0x05, 0x07, 0x00, 0x00, 0x02,
	0x04, 0x06, 0x08, 0x00, 0x01, 0x03, 0x05, 0x06,
	0x09
};

// code
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
        sub_8026B5C(gUnknown_02022C98->unk24, &gUnknown_02022C98->unk44, &gUnknown_02022C98->unk48);
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

    data->unk0C = 0;
    data->unk10 = 0;
    data->unk14 = 0;
    data->unk18 = 0;
    data->unk1C = 0;
    data->unk11C = 0;
    data->unk120 = 0;
    data->unk30 = 0;
    data->unk40 = 0;
    data->unk3C = 0;
    data->unk12C = 0;

    for (i = 0; i < 4; i++)
    {
        data->unk98[i] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        data->unkA8[i] = 0;
        data->unkB0[i] = 0;
        data->unk4A[i][0] = 0;
        data->unk4A[i][1] = 0;
        data->unk4A[i][2] = 0;
        data->unk4A[i][3] = 0;
        data->unk4A[i][5] = 0;
        data->unk10C[i] = 0;
        data->unk130[i] = 0;
    }

    for (i = 0; i < 11; i++)
    {
        data->unkD0[i] = 0;
        data->unkDC[i] = 0;
        data->unkC4[i] = 0;
        data->unkF4[i][0] = 0xFF;
        data->unkF4[i][1] = 0xFF;
    }

    data->unk20 = GetMultiplayerId() == 0 ? 1 : 0;
    data->unk24 = GetLinkPlayerCount();
    data->unk34[0] = GetMultiplayerId();
    for (i = 1; i < data->unk24; i++)
    {
        data->unk34[i] = data->unk34[i - 1] + 1;
        if (data->unk34[i] > data->unk24 - 1)
            data->unk34[i] %= data->unk24;
    }
}

void sub_8024BC8(u8 taskId)
{
    u8 r4, r5;

    switch (gUnknown_02022C98->unk0C)
    {
    case 0:
        SetVBlankCallback(NULL);
        sub_802620C(sub_8025910, 4);
        gUnknown_02022C98->unk0C++;
        break;
    case 1:
        if (!FuncIsActiveTask(sub_8025910))
        {
            sub_8029274(&gUnknown_02022C98->unk160);
            gUnknown_02022C98->unk0C++;
        }
        break;
    case 2:
        if (!sub_802A770())
        {
            sub_8010434();
            gUnknown_02022C98->unk0C++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
            gUnknown_02022C98->unk0C++;
        }
        break;
    case 4:
        r5 = gUnknown_02022C98->unk24;
        sub_80283A8();
        for (r4 = 0; r4 < r5; r4++)
        {
            sub_8028408(&gUnknown_02022C98->unk_318C[gUnknown_02022C98->unk34[r4]], r4, gUnknown_02022C98->unk34[r4], gUnknown_02022C98->unk24);
        }
        sub_802868C(0, gUnknown_02022C98->unk24);
        gUnknown_02022C98->unk0C++;
        break;
    case 5:
        sub_8028A34();
        sub_8028A88();
        sub_8028D44();
        sub_8028734();
        gUnknown_02022C98->unk0C++;
        break;
    case 6:
        BlendPalettes(0xFFFFFFFF, 0x10, 0x00);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        SetVBlankCallback(sub_80261E4);
        gUnknown_02022C98->unk0C++;
        break;
    case 7:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            gUnknown_02022C98->unk0C++;
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
    gUnknown_082F7AC4[gUnknown_02022C98->unk18]();
    if (gUnknown_03000DB0 == FALSE)
    {
        sub_8026AF4();
    }
    sub_8025D50();
}

void sub_8024D84(u8 taskId)
{
    sub_8025E0C();
    gUnknown_082F7AF4[gUnknown_02022C98->unk18]();
    if (gUnknown_03000DB0 == FALSE)
    {
        sub_8026B28();
    }
    sub_8025ED8();
}

void sub_8024DBC(void)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_8028504(1);
        sub_80292E0(1);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        if (!sub_802A770())
            sub_8026240(1);
        break;
    }
}

void sub_8024E00(void)
{
    if (gUnknown_02022C98->unk10 == 0)
    {
        sub_80262C0();
        gUnknown_02022C98->unk10++;
    }
    else
    {
        gUnknown_02022C98->unk118 = 1;
        sub_8026240(2);
    }
}

void sub_8024E38(void)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_802EB24(7, 8, 120, 80, 0);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        sub_8010434();
        gUnknown_02022C98->unk10++;
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            gUnknown_02022C98->unk10++;
            gUnknown_02022C98->unk30 = 0;
        }
        break;
    case 3:
        if (!sub_802EB84())
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 4:
        if (++gUnknown_02022C98->unk30 > 5)
        {
            sub_8010434();
            gUnknown_02022C98->unk10++;
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
    if (gUnknown_02022C98->unk10 == 0)
    {
        if (gUnknown_02022C98->unk11C != 0)
        {
            sub_8026240(4);
        }
    }
}

void sub_8024F38(void)
{
    if (gUnknown_02022C98->unk10 == 0)
    {
        if (gUnknown_02022C98->unk40 < 10)
        {
            if (gUnknown_02022C98->unkA8[0] == 0)
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
    if (gUnknown_02022C98->unk40 < 10)
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
        gUnknown_02022C98->unk12C = 1;
        for (i = 1; i < gUnknown_02022C98->unk24; i++)
        {
            if (gUnknown_02022C98->unk130[i] != 1)
            {
                gUnknown_02022C98->unk12C = 0;
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
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        if (SendBlock(0, gUnknown_02022C98->unk4A, sizeof(gUnknown_02022C98->unk4A)))
        {
            gUnknown_02022C98->unk08 = 0;
            gUnknown_02022C98->unk10++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        if (sub_8025170())
        {
            gUnknown_02022C98->unk08 = gUnknown_02022C98->unk24;
        }
        if (gUnknown_02022C98->unk08 >= gUnknown_02022C98->unk24)
        {
            gUnknown_02022C98->unk14++;
            gUnknown_02022C98->unk10++;
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

    switch (gUnknown_02022C98->unk10) {
    case 0:
        if (SendBlock(0, gUnknown_02022C98->unk4A[gUnknown_02022C98->unk14],
                      sizeof(gUnknown_02022C98->unk4A))) {
            gUnknown_02022C98->unk08 = 0;
            gUnknown_02022C98->unk10++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished()) {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        if (sub_8025170()) {
            for (i = 0; i < gUnknown_02022C98->unk24; i++) {
                memcpy(gUnknown_02022C98->unk4A, gBlockRecvBuffer, sizeof(gUnknown_02022C98->unk4A));
                gUnknown_02022C98->unk08 = gUnknown_02022C98->unk24;
            }
        }
        if (gUnknown_02022C98->unk08 >= gUnknown_02022C98->unk24) {
            gUnknown_02022C98->unk14++;
            gUnknown_02022C98->unk10++;
        }
        break;
    default:
        if (WaitFanfare(TRUE)) {
            gUnknown_02022C98->unk114 = gUnknown_02022C98->unk4A[gUnknown_02022C98->multiplayerId][5];
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

    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_802749C();
        sub_80289E8(1);
        sub_8028DFC();
        sub_8028EC8(1);
        sub_80292E0(2);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        if (!sub_802A770())
        {
            sub_80292E0(5);
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        sp00 = sub_802A794();
        if (SendBlock(0, &sp00, sizeof(sp00)))
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            gUnknown_02022C98->unk10++;
            gUnknown_02022C98->unk08 = 0;
        }
        break;
    case 4:
        if (sub_8025170())
        {
            for (i = 0; i < gUnknown_02022C98->unk24; i++)
            {
                *(gUnknown_02022C98->unk10C + i) = *(u8 *)gBlockRecvBuffer[i];
                gUnknown_02022C98->unk08 = gUnknown_02022C98->unk24;
            }
        }
        if (gUnknown_02022C98->unk08 >= gUnknown_02022C98->unk24) {
            if (++gUnknown_02022C98->unk14 >= 120)
            {
                sub_80292E0(6);
                gUnknown_02022C98->unk10++;
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

    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        if (sub_8027748() >= 3000)
        {
            sub_80292E0(4);
        }
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        if (!sub_802A770())
        {
            sub_80292E0(3);
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        sub_8028FCC();
        sub_80272E8();
        gUnknown_02022C98->unk10++;
        break;
    case 3:
        if ((sp0 = sub_802A794()) != 0)
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 4:
        if (!sub_802A770())
        {
            sub_80292E0(5);
            gUnknown_02022C98->unk10++;
        }
        break;
    case 5:
        sp0 = sub_802A794();
        if (SendBlock(0, &sp0, sizeof(sp0)))
        {
            gUnknown_02022C98->unk08 = 0;
            gUnknown_02022C98->unk10++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 7:
        if (sub_8025170())
        {
            for (i = 0; i < gUnknown_02022C98->unk24; i++)
            {
                *(gUnknown_02022C98->unk10C + i) = *(u8 *)gBlockRecvBuffer[i];
                gUnknown_02022C98->unk08 = gUnknown_02022C98->unk24;
            }
        }
        if (gUnknown_02022C98->unk08 >= gUnknown_02022C98->unk24) {
            if (++gUnknown_02022C98->unk14 >= 120)
            {
                sub_8027608();
                sub_80292E0(6);
                gUnknown_02022C98->unk10++;
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
            for (i = 0; i < gUnknown_02022C98->unk24; i++)
            {
                if (gUnknown_02022C98->unk10C[i] == 2)
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
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_800AC34();
        sub_80292E0(7);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        if (!sub_802A770())
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        if (sub_802A794() == 5)
        {
            gUnknown_02022C98->unk10++;
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
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 2:
        sub_8028B80();
        sub_80287E4();
        sub_8028614(gUnknown_02022C98->unk24);
        sub_8028E84();
        gUnknown_03000DB0 = TRUE;
        sub_80292E0(8);
        gUnknown_02022C98->unk10++;
        break;
    default:
        if (!sub_802A770())
        {
            SetMainCallback2(gUnknown_02022C98->savedCallback);
            DestroyTask(gUnknown_02022C98->unk04);
            Free(gUnknown_02022C98);
            FreeAllWindowBuffers();
        }
        break;
    }
}

void sub_8025758(void)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_80292E0(9);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            gUnknown_02022C98->unk10++;
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
        gUnknown_02022C98->unk10++;
        break;
    case 3:
        StopMapMusic();
        gUnknown_02022C98->unk10++;
        break;
    case 4:
        PlayNewMapMusic(MUS_RG_KINOMIKUI);
        sub_8028E4C();
        gUnknown_02022C98->unk10++;
        break;
    case 5:
        BlendPalettes(0xFFFFFFFF, 16, 0);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        gUnknown_02022C98->unk10++;
        break;
    case 6:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    default:
        DestroyTask(gUnknown_02022C98->unk04);
        sub_802621C(sub_802589C);
        sub_802903C();
        sub_8024A30(gUnknown_02022C98);
        if (gReceivedRemoteLinkPlayers == 0)
        {
            gUnknown_02022C98->unk24 = 1;
        }
        sub_80273F0();
        sub_8028EC8(0);
        break;
    }
}

void sub_802589C(u8 taskId)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        if (sub_8026264() == 1)
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 1:
        sub_80286E4();
        gUnknown_02022C98->unk10++;
        break;
    case 2:
        if (sub_8028828() == 1)
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    default:
        if (gUnknown_02022C98->unk20 != 0)
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
            gUnknown_02022C98->unk08 = 0;
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
            for (i = 0; i < gUnknown_02022C98->unk24; i++)
            {
                *(u8 *)&gUnknown_02022C98->unk_318C[i] = *(u8 *)gBlockRecvBuffer[i];
                gUnknown_02022C98->unk08 = gUnknown_02022C98->unk24;
            }
        }
        if (gUnknown_02022C98->unk08 >= gUnknown_02022C98->unk24)
        {
            DestroyTask(taskId);
            sub_80292E0(6);
            gUnknown_02022C98->unk10++;
        }
        break;
    }
}

void sub_80259FC(void)
{
    u8 i;
    u8 r7 = gUnknown_02022C98->unk24;

    gUnknown_02022C98->unk_31A0[0].unk_10 = sub_8028164(0, &gUnknown_02022C98->unk_31A0[0], &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
    gUnknown_02022C98->unk128 = 1;

    for (i = 1; i < r7; i++)
    {
        if (   gUnknown_02022C98->unkA8[i] == 0
            && sub_8028318(i, &gUnknown_02022C98->unk_31A0[i].unk_2C) == 0)
        {
            gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
            gUnknown_02022C98->unk128 = 0;
        }
    }
    if (++gUnknown_02022C98->unk124 >= 60)
    {
        if (gUnknown_02022C98->unk128 != 0)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk124 = 0;
        }
        else if (gUnknown_02022C98->unk124 > 70)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk124 = 0;
        }
    }

    for (i = 0; i < r7; i++)
    {
        if (   gUnknown_02022C98->unk_31A0[i].unk_2C != 0
            && gUnknown_02022C98->unkA8[i] == 0)
        {
            gUnknown_02022C98->unkA8[i] = 1;
        }
        switch (gUnknown_02022C98->unkA8[i])
        {
        case 0:
        default:
            break;
        case 1 ... 3:
            if (++gUnknown_02022C98->unkB0[i] >= 6)
            {
                gUnknown_02022C98->unkB0[i] = 0;
                gUnknown_02022C98->unkA8[i] = 0;
                gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
                gUnknown_02022C98->unk_31A0[i].unk_30 = 0;
                gUnknown_02022C98->unk_31A0[i].unk_34 = 0;
            }
            break;
        case 4:
            if (++gUnknown_02022C98->unkB0[i] >= 40)
            {
                gUnknown_02022C98->unkB0[i] = 0;
                gUnknown_02022C98->unkA8[i] = 0;
                gUnknown_02022C98->unk_31A0[i].unk_2C = 0;
                gUnknown_02022C98->unk_31A0[i].unk_30 = 0;
                gUnknown_02022C98->unk_31A0[i].unk_34 = 0;
            }
            break;
        }
    }
}

void sub_8025C0C(void)
{
    u8 i;
    u8 r6 = gUnknown_02022C98->unk24;

    gUnknown_02022C98->unk_31A0[0].unk_10 = sub_8028164(0, &gUnknown_02022C98->unk_31A0[0], &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
    gUnknown_02022C98->unk128 = 1;

    for (i = 1; i < r6; i++)
    {
        if (sub_8028374(i) != 0)
        {
            gUnknown_02022C98->unk130[i] = 1;
            gUnknown_02022C98->unk128 = 0;
        }
    }
    if (++gUnknown_02022C98->unk124 >= 60)
    {
        if (gUnknown_02022C98->unk128 != 0)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk124 = 0;
        }
        else if (gUnknown_02022C98->unk124 > 70)
        {
            sub_8011AC8();
            gUnknown_02022C98->unk124 = 0;
        }
    }
}

void sub_8025D04(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 3:
        if (sub_8026BB8() == TRUE)
        {
            sub_8026C28();
            gUnknown_02022C98->unk11C = 1;
        }
        break;
    case 4:
        sub_80259FC();
        break;
    case 11:
        sub_8025C0C();
        break;
    }
}

void sub_8025D50(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 4:
        sub_8027E30(&gUnknown_02022C98->unk_32CC, &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, gUnknown_02022C98->unk40, gUnknown_02022C98->unk120, gUnknown_02022C98->unk12C);
        break;
    case 11:
        sub_8027E30(&gUnknown_02022C98->unk_32CC, &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, gUnknown_02022C98->unk40, gUnknown_02022C98->unk120, gUnknown_02022C98->unk12C);
        break;
    }
}

void sub_8025E0C(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 4:
        sub_8028164(gUnknown_02022C98->multiplayerId, &gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId], &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
        break;
    case 11:
        sub_8028164(gUnknown_02022C98->multiplayerId, &gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId], &gUnknown_02022C98->unk_31A0[0].unk_2C, &gUnknown_02022C98->unk_31A0[1].unk_2C, &gUnknown_02022C98->unk_31A0[2].unk_2C, &gUnknown_02022C98->unk_31A0[3].unk_2C, &gUnknown_02022C98->unk_31A0[4].unk_2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
        break;
    }
}

void sub_8025ED8(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 3:
        sub_8027DD0(1);
        gUnknown_02022C98->unk11C = 1;
        break;
    case 4:
        if (gUnknown_02022C98->unk_32CC.unk_2C != 0)
        {
            sub_80282EC(gUnknown_02022C98->unk_32CC.unk_2C);
        }
        break;
    case 11:
        if (gUnknown_02022C98->unk120 == 0 && gUnknown_02022C98->unk12C == 0)
        {
            sub_8028350(1);
        }
        break;
    }
}

void sub_8025F48(void)
{
    if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_2C == 0)
    {
        if (!IsSEPlaying())
        {
            gUnknown_02022C98->unk144 = 0;
        }
    }
    else if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_30 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0)
        {
            m4aSongNumStop(SE_SEIKAI);
            PlaySE(SE_SEIKAI);
            gUnknown_02022C98->unk144 = 1;
        }
    }
    else if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_34 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0 && !IsSEPlaying())
        {
            PlaySE(SE_BOO);
            sub_80284CC(1);
            gUnknown_02022C98->unk144 = 1;
        }
    }

    if (gUnknown_02022C98->unk154 == 0 && gUnknown_02022C98->unk40 >= 10)
    {
        StopMapMusic();
        gUnknown_02022C98->unk154 = 1;
    }
    else if (gUnknown_02022C98->unk154 == 1)
    {
        PlayFanfareByFanfareNum(11); // MUS_ME_ZANNEN
        gUnknown_02022C98->unk154 = 2;
    }
}

void sub_8026044(void)
{
    u8 r8 = gUnknown_02022C98->unk44;
    u8 r7 = gUnknown_02022C98->unk48;
    u8 r4;
    if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_2C == 0)
    {
        if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_30 != 1 && gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_34 != 1)
        {
            gUnknown_02022C98->unk144 = 0;
        }
    }
    else if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_30 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0)
        {
            m4aSongNumStop(SE_SEIKAI);
            PlaySE(SE_SEIKAI);
            gUnknown_02022C98->unk144 = 1;
        }
    }
    else if (gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_34 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0 && !IsSEPlaying())
        {
            PlaySE(SE_BOO);
            sub_80284CC(1);
            gUnknown_02022C98->unk144 = 1;
        }
    }
    for (r4 = r8; r4 < r7; r4++)
    {
        struct DodrioBerryPickingSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId].unk_14;
        if (ptr->unk_B[r4] >= 10)
        {
            if (gUnknown_02022C98->unk148[r4] == 0)
            {
                PlaySE(SE_FUUSEN1 + ptr->unk_0[r4]);
                gUnknown_02022C98->unk148[r4] = 1;
            }
        }
        else
        {
            gUnknown_02022C98->unk148[r4] = 0;
        }
    }
    if (gUnknown_02022C98->unk154 == 0 && gUnknown_02022C98->unk40 >= 10)
    {
        StopMapMusic();
        gUnknown_02022C98->unk154 = 1;
    }
    else if (gUnknown_02022C98->unk154 == 1)
    {
        PlayFanfareByFanfareNum(11); // MUS_ME_ZANNEN
        gUnknown_02022C98->unk154 = 2;
    }
}

void sub_80261CC(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_80261E4(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void sub_80261F8(struct DodrioBerryPickingSubstruct_318C * a0, struct Pokemon * a1)
{
    a0->isShiny = IsMonShiny(a1);
}

void sub_802620C(TaskFunc func, u8 priority)
{
    CreateTask(func, priority);
}

void sub_802621C(TaskFunc func)
{
    gUnknown_02022C98->unk04 = CreateTask(func, 1);
    gUnknown_02022C98->unk10 = 0;
    gUnknown_02022C98->unk0C = 0;
    gUnknown_02022C98->unk14 = 0;
}

void sub_8026240(u8 a0)
{
    gUnknown_02022C98->unk1C = gUnknown_02022C98->unk18;
    gUnknown_02022C98->unk18 = a0;
    gUnknown_02022C98->unk10 = 0;
    gUnknown_02022C98->unk14 = 0;
}

bool32 sub_8026264(void)
{
    u8 r2 = gUnknown_02022C98->unk14 / 4;
    gUnknown_02022C98->unk14++;
    if (r2 != 0 && gUnknown_02022C98->unk14 % 4 == 0)
    {
        if (r2 < gUnknown_082F7A94[gUnknown_02022C98->unk24 - 1])
        {
            SetGpuReg(REG_OFFSET_BG1HOFS,  (r2 * 8));
            SetGpuReg(REG_OFFSET_BG2HOFS, -(r2 * 8));
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}

void sub_80262C0(void)
{
    u8 i;
    u8 start = gUnknown_02022C98->unk44;
    u8 finish = gUnknown_02022C98->unk48;

    for (i = start; i < finish; i++)
    {
        struct DodrioBerryPickingSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk_32CC.unk_14;
        ptr->unk_B[i] = (i % 2 == 0) ? 1 : 0;
        ptr->unk_0[i] = 0;
    }
}

#ifdef NONMATCHING
void sub_8026324(void)
{
    u8 sp0 = gUnknown_02022C98->unk44;
    u8 sp4 = gUnknown_02022C98->unk48;
    u8 sp8 = gUnknown_02022C98->unk24;
    u8 i, j, k;
    s32 r2;
    u8 r5;
    u8 r3;
    s32 r2_2;
    u8 r4;
    u8 r7, r7_2;

    if (gUnknown_02022C98->unk40 >= 10)
        return;

    for (i = 0; i < sp8; i++)
    {
        u8 *ptr = &gUnknown_02022C98->unk_31A0[i].unk_2C;
        if (*ptr != 0 && gUnknown_02022C98->unkA8[i] == 1)
        {
            for (j = sp0; j < sp4; j++)
            {
                r5 = gUnknown_082F449C[0][0][j];
                if (gUnknown_02022C98->unkF4[r5][0] == i)
                    break;
                if (gUnknown_02022C98->unkF4[r5][1] == i)
                    break;
                if (sub_8026634(i, *ptr, r5) == TRUE)
                {
                    for (k = 0; k < 2; k++)
                    {
                        if (gUnknown_02022C98->unkF4[r5][k] == 0xFF)
                        {
                            gUnknown_02022C98->unkF4[r5][k] = i;
                            gUnknown_02022C98->unkA8[i] = 2;
                            gUnknown_02022C98->unkC4[r5] = 1;
                            break;
                        }
                    }
                    break;
                }
                if (gUnknown_02022C98->unk_31A0[i].unk_34 == 1)
                    break;
            }
        }
    }

    for (j = sp0; j < sp4; j++)
    {
        i = 0xFF;
        r5 = gUnknown_082F449C[0][0][j];
        if (gUnknown_02022C98->unkC4[r5] == 1)
        {
            r3 = gUnknown_02022C98->unk90[sub_8026D8C(r5)] / 7;
            if (r3 < 2)
                r3 = 2;

            r2 = gUnknown_082F7A88[r3][gUnknown_02022C98->unk_31A0[0].unk_14.unk_0[r5]] - gUnknown_02022C98->unkD0[r5];
            if (r2 < 6)
                gUnknown_02022C98->unk9C[r5] += r2;

            if (++gUnknown_02022C98->unk9C[r5] >= 6)
            {
                gUnknown_02022C98->unk9C[r5] = 0;
                if (gUnknown_02022C98->unkF4[r5][0] != 0xFF && gUnknown_02022C98->unkF4[r5][1] == 0xFF)
                {
                    r4 = gUnknown_02022C98->unkF4[r5][0];
                }
                else if (gUnknown_02022C98->unkF4[r5][0] == 0xFF && gUnknown_02022C98->unkF4[r5][1] == 0xFF)
                {
                    continue;
                }
                else
                {
                    r7 = gUnknown_02022C98->unkF4[r5][0];
                    r7_2 = gUnknown_02022C98->unkF4[r5][1];
                    if ((Random() & 1))
                    {
                        r4 = r7_2;
                        i = r7;
                    }
                    else
                    {
                        r4 = r7;
                        i = r7_2;
                    }
                }
                gUnknown_02022C98->unk_32CC.unk_14.unk_B[r5] = 7;
                gUnknown_02022C98->unkC4[r5] = 2;
                gUnknown_02022C98->unkA8[r4] = 3;
                gUnknown_02022C98->unkB8[r5] = r4;
                gUnknown_02022C98->unk_31A0[r4].unk_30 = 1;
                gUnknown_02022C98->unk_31A0[i].unk_34 = 1;
                gUnknown_02022C98->unk86[r4]++;
                sub_8026F1C(0, r5, r4);
                sub_8027234(1);
                sub_8026D1C(r4);
                gUnknown_02022C98->unkE8[r5] = gUnknown_02022C98->unk_32CC.unk_14.unk_0[r5];
                gUnknown_02022C98->unk_32CC.unk_14.unk_0[r5] = 3;
                gUnknown_02022C98->unkF4[r5][0] = 0xFF;
                gUnknown_02022C98->unkF4[r5][1] = 0xFF;
            }
        }
    }
}
#else
NAKED
void sub_8026324(void)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r10\n"
                "\tmov r6, r9\n"
                "\tmov r5, r8\n"
                "\tpush {r5-r7}\n"
                "\tsub sp, 0x10\n"
                "\tldr r0, =gUnknown_02022C98\n"
                "\tldr r1, [r0]\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0x44\n"
                "\tldrb r0, [r0]\n"
                "\tstr r0, [sp]\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0x48\n"
                "\tldrb r0, [r0]\n"
                "\tstr r0, [sp, 0x4]\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0x24\n"
                "\tldrb r0, [r0]\n"
                "\tstr r0, [sp, 0x8]\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0x40\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0x9\n"
                "\tbls _08026358\n"
                "\tb _08026614\n"
                "_08026358:\n"
                "\tmovs r6, 0\n"
                "\tldr r0, [sp, 0x8]\n"
                "\tcmp r6, r0\n"
                "\tbcs _08026440\n"
                "_08026360:\n"
                "\tldr r3, =gUnknown_02022C98\n"
                "\tlsls r0, r6, 4\n"
                "\tsubs r1, r0, r6\n"
                "\tlsls r1, 2\n"
                "\tldr r2, [r3]\n"
                "\tadds r1, r2\n"
                "\tldr r4, =0x000031cc\n"
                "\tadds r4, r1\n"
                "\tmov r8, r4\n"
                "\tldrb r1, [r4]\n"
                "\tmov r9, r0\n"
                "\tadds r0, r6, 0x1\n"
                "\tstr r0, [sp, 0xC]\n"
                "\tcmp r1, 0\n"
                "\tbeq _08026434\n"
                "\tadds r0, r2, 0\n"
                "\tadds r0, 0xA8\n"
                "\tadds r0, r6\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0x1\n"
                "\tbne _08026434\n"
                "\tldr r1, [sp]\n"
                "\tmov r10, r1\n"
                "\tldr r2, [sp, 0x4]\n"
                "\tcmp r10, r2\n"
                "\tbcs _08026434\n"
                "\tadds r7, r3, 0\n"
                "_08026396:\n"
                "\tldr r0, =gUnknown_082F449C\n"
                "\tadd r0, r10\n"
                "\tldrb r5, [r0]\n"
                "\tldr r1, [r7]\n"
                "\tlsls r4, r5, 1\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0xF4\n"
                "\tadds r0, r4\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, r6\n"
                "\tbeq _08026434\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0xF5\n"
                "\tadds r0, r4\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, r6\n"
                "\tbeq _08026434\n"
                "\tmov r0, r8\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r6, 0\n"
                "\tadds r2, r5, 0\n"
                "\tbl sub_8026634\n"
                "\tcmp r0, 0x1\n"
                "\tbne _08026410\n"
                "\tmovs r2, 0\n"
                "\tldr r3, =gUnknown_02022C98\n"
                "\tmov r8, r4\n"
                "_080263CE:\n"
                "\tldr r0, [r3]\n"
                "\tmov r4, r8\n"
                "\tadds r1, r2, r4\n"
                "\tadds r0, 0xF4\n"
                "\tadds r1, r0, r1\n"
                "\tldrb r0, [r1]\n"
                "\tcmp r0, 0xFF\n"
                "\tbne _08026404\n"
                "\tstrb r6, [r1]\n"
                "\tldr r0, [r3]\n"
                "\tadds r0, 0xA8\n"
                "\tadds r0, r6\n"
                "\tmovs r1, 0x2\n"
                "\tstrb r1, [r0]\n"
                "\tldr r0, [r3]\n"
                "\tadds r0, 0xC4\n"
                "\tadds r0, r5\n"
                "\tmovs r1, 0x1\n"
                "\tstrb r1, [r0]\n"
                "\tb _08026434\n"
                "\t.pool\n"
                "_08026404:\n"
                "\tadds r0, r2, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r2, r0, 24\n"
                "\tcmp r2, 0x1\n"
                "\tbls _080263CE\n"
                "\tb _08026434\n"
                "_08026410:\n"
                "\tldr r0, [r7]\n"
                "\tmov r2, r9\n"
                "\tsubs r1, r2, r6\n"
                "\tlsls r1, 2\n"
                "\tadds r0, r1\n"
                "\tldr r4, =0x000031d4\n"
                "\tadds r0, r4\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0x1\n"
                "\tbeq _08026434\n"
                "\tmov r0, r10\n"
                "\tadds r0, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r0, 24\n"
                "\tmov r10, r0\n"
                "\tldr r0, [sp, 0x4]\n"
                "\tcmp r10, r0\n"
                "\tbcc _08026396\n"
                "_08026434:\n"
                "\tldr r1, [sp, 0xC]\n"
                "\tlsls r0, r1, 24\n"
                "\tlsrs r6, r0, 24\n"
                "\tldr r2, [sp, 0x8]\n"
                "\tcmp r6, r2\n"
                "\tbcc _08026360\n"
                "_08026440:\n"
                "\tldr r4, [sp]\n"
                "\tmov r10, r4\n"
                "\tldr r0, [sp, 0x4]\n"
                "\tcmp r10, r0\n"
                "\tbcc _0802644C\n"
                "\tb _08026614\n"
                "_0802644C:\n"
                "\tldr r1, =gUnknown_02022C98\n"
                "\tmov r9, r1\n"
                "_08026450:\n"
                "\tmovs r6, 0xFF\n"
                "\tldr r0, =gUnknown_082F449C\n"
                "\tadd r0, r10\n"
                "\tldrb r5, [r0]\n"
                "\tmov r2, r9\n"
                "\tldr r0, [r2]\n"
                "\tadds r0, 0xC4\n"
                "\tadds r0, r5\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0x1\n"
                "\tbeq _08026468\n"
                "\tb _08026602\n"
                "_08026468:\n"
                "\tadds r0, r5, 0\n"
                "\tbl sub_8026D8C\n"
                "\tmov r1, r9\n"
                "\tldr r4, [r1]\n"
                "\tlsls r0, 24\n"
                "\tlsrs r0, 24\n"
                "\tadds r1, r4, 0\n"
                "\tadds r1, 0x90\n"
                "\tadds r1, r0\n"
                "\tldrb r0, [r1]\n"
                "\tmovs r1, 0x7\n"
                "\tbl __udivsi3\n"
                "\tlsls r0, 24\n"
                "\tlsrs r3, r0, 24\n"
                "\tcmp r3, 0x1\n"
                "\tbls _0802648E\n"
                "\tmovs r3, 0x2\n"
                "_0802648E:\n"
                "\tldr r2, =gUnknown_082F7A88\n"
                "\tldr r0, =0x000031b4\n"
                "\tadds r1, r4, r0\n"
                "\tadds r1, r5\n"
                "\tlsls r0, r3, 1\n"
                "\tadds r0, r3\n"
                "\tldrb r1, [r1]\n"
                "\tadds r0, r1\n"
                "\tadds r0, r2\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r4, 0\n"
                "\tadds r0, 0xD0\n"
                "\tadds r0, r5\n"
                "\tldrb r0, [r0]\n"
                "\tsubs r2, r1, r0\n"
                "\tcmp r2, 0x5\n"
                "\tbgt _080264BC\n"
                "\tadds r1, r4, 0\n"
                "\tadds r1, 0x9C\n"
                "\tadds r1, r5\n"
                "\tldrb r0, [r1]\n"
                "\tadds r0, r2\n"
                "\tstrb r0, [r1]\n"
                "_080264BC:\n"
                "\tmov r2, r9\n"
                "\tldr r1, [r2]\n"
                "\tadds r1, 0x9C\n"
                "\tadds r1, r5\n"
                "\tldrb r0, [r1]\n"
                "\tadds r0, 0x1\n"
                "\tmovs r2, 0\n"
                "\tstrb r0, [r1]\n"
                "\tmovs r4, 0xFF\n"
                "\tands r0, r4\n"
                "\tcmp r0, 0x5\n"
                "\tbhi _080264D6\n"
                "\tb _08026602\n"
                "_080264D6:\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tadds r0, 0x9C\n"
                "\tadds r0, r5\n"
                "\tstrb r2, [r0]\n"
                "\tldr r3, [r1]\n"
                "\tlsls r1, r5, 1\n"
                "\tadds r0, r3, 0\n"
                "\tadds r0, 0xF4\n"
                "\tadds r2, r0, r1\n"
                "\tldrb r0, [r2]\n"
                "\tmov r8, r1\n"
                "\tcmp r0, 0xFF\n"
                "\tbne _08026518\n"
                "\tadds r0, r3, 0\n"
                "\tadds r0, 0xF5\n"
                "\tadd r0, r8\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0xFF\n"
                "\tbne _08026500\n"
                "\tb _08026602\n"
                "_08026500:\n"
                "\tb _08026528\n"
                "\t.pool\n"
                "_08026518:\n"
                "\tadds r0, r3, 0\n"
                "\tadds r0, 0xF5\n"
                "\tadd r0, r8\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0xFF\n"
                "\tbne _08026528\n"
                "\tldrb r4, [r2]\n"
                "\tb _0802654E\n"
                "_08026528:\n"
                "\tmov r2, r9\n"
                "\tldr r1, [r2]\n"
                "\tadds r0, r1, 0\n"
                "\tadds r0, 0xF4\n"
                "\tadd r0, r8\n"
                "\tldrb r7, [r0]\n"
                "\tadds r1, 0xF5\n"
                "\tadd r1, r8\n"
                "\tldrb r6, [r1]\n"
                "\tbl Random\n"
                "\tmovs r1, 0x1\n"
                "\tands r1, r0\n"
                "\tcmp r1, 0\n"
                "\tbne _0802654A\n"
                "\tadds r4, r7, 0\n"
                "\tb _0802654E\n"
                "_0802654A:\n"
                "\tadds r4, r6, 0\n"
                "\tadds r6, r7, 0\n"
                "_0802654E:\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tldr r2, =0x000032eb\n"
                "\tadds r0, r2\n"
                "\tadds r0, r5\n"
                "\tmovs r1, 0x7\n"
                "\tstrb r1, [r0]\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tadds r0, 0xC4\n"
                "\tadds r0, r5\n"
                "\tmovs r1, 0x2\n"
                "\tstrb r1, [r0]\n"
                "\tmov r2, r9\n"
                "\tldr r0, [r2]\n"
                "\tadds r0, 0xA8\n"
                "\tadds r0, r4\n"
                "\tmovs r1, 0x3\n"
                "\tstrb r1, [r0]\n"
                "\tldr r0, [r2]\n"
                "\tadds r0, 0xB8\n"
                "\tadds r0, r5\n"
                "\tstrb r4, [r0]\n"
                "\tldr r1, [r2]\n"
                "\tlsls r0, r4, 4\n"
                "\tsubs r0, r4\n"
                "\tlsls r0, 2\n"
                "\tadds r1, r0\n"
                "\tldr r2, =0x000031d0\n"
                "\tadds r1, r2\n"
                "\tmovs r0, 0x1\n"
                "\tstrb r0, [r1]\n"
                "\tmov r2, r9\n"
                "\tldr r1, [r2]\n"
                "\tlsls r0, r6, 4\n"
                "\tsubs r0, r6\n"
                "\tlsls r0, 2\n"
                "\tadds r1, r0\n"
                "\tldr r0, =0x000031d4\n"
                "\tadds r1, r0\n"
                "\tmovs r2, 0x1\n"
                "\tstrb r2, [r1]\n"
                "\tmov r0, r9\n"
                "\tldr r1, [r0]\n"
                "\tlsls r0, r4, 1\n"
                "\tadds r1, 0x86\n"
                "\tadds r1, r0\n"
                "\tldrh r0, [r1]\n"
                "\tadds r0, 0x1\n"
                "\tstrh r0, [r1]\n"
                "\tmovs r0, 0\n"
                "\tadds r1, r5, 0\n"
                "\tadds r2, r4, 0\n"
                "\tbl sub_8026F1C\n"
                "\tmovs r0, 0x1\n"
                "\tbl sub_8027234\n"
                "\tadds r0, r4, 0\n"
                "\tbl sub_8026D1C\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tadds r1, r0, 0\n"
                "\tadds r1, 0xE8\n"
                "\tadds r1, r5\n"
                "\tldr r2, =0x000032e0\n"
                "\tadds r0, r2\n"
                "\tadds r0, r5\n"
                "\tldrb r0, [r0]\n"
                "\tstrb r0, [r1]\n"
                "\tmov r4, r9\n"
                "\tldr r0, [r4]\n"
                "\tadds r0, r2\n"
                "\tadds r0, r5\n"
                "\tmovs r1, 0x3\n"
                "\tstrb r1, [r0]\n"
                "\tldr r1, [r4]\n"
                "\tadds r1, 0xF4\n"
                "\tadd r1, r8\n"
                "\tldrb r0, [r1]\n"
                "\tmovs r2, 0xFF\n"
                "\torrs r0, r2\n"
                "\tstrb r0, [r1]\n"
                "\tldr r1, [r4]\n"
                "\tadds r1, 0xF5\n"
                "\tadd r1, r8\n"
                "\tldrb r0, [r1]\n"
                "\torrs r0, r2\n"
                "\tstrb r0, [r1]\n"
                "_08026602:\n"
                "\tmov r0, r10\n"
                "\tadds r0, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r0, 24\n"
                "\tmov r10, r0\n"
                "\tldr r4, [sp, 0x4]\n"
                "\tcmp r10, r4\n"
                "\tbcs _08026614\n"
                "\tb _08026450\n"
                "_08026614:\n"
                "\tadd sp, 0x10\n"
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

bool32 sub_8026634(u8 a0, u8 a1, u8 a2)
{
    s32 r7 = 0;
    u8 r5 = gUnknown_02022C98->unk24 - 1;
    struct DodrioBerryPickingSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk_32CC.unk_14;

    switch (a1)
    {
    case 3:
    default:
        r7 = 0;
        break;
    case 2:
        r7 = 1;
        break;
    case 1:
        r7 = 2;
        break;
    }
    if (ptr->unk_B[a2] == 6 || ptr->unk_B[a2] == 7)
    {
        if (a2 == gUknnown_082F45AF[r5][a0][r7])
        {
            if (gUnknown_02022C98->unkC4[a2] == 1 || gUnknown_02022C98->unkC4[a2] == 2)
            {
                gUnknown_02022C98->unk_31A0[a0].unk_34 = 1;
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }
    }
    else
    {
        if (a2 == gUknnown_082F45AF[r5][a0][r7])
        {
            gUnknown_02022C98->unkA8[a0] = 4;
            gUnknown_02022C98->unk_31A0[a0].unk_34 = 1;
        }
    }
    return FALSE;
}

void sub_802671C(void)
{
    u8 r1 = gUnknown_02022C98->unk44;
    u8 r9 = gUnknown_02022C98->unk48;
    u8 r3 = 0;
    u8 r10 = 0;
    u8 i;
    u8 r2;
    struct DodrioBerryPickingStruct *ptr;

    gUnknown_02022C98->unk120 = 0;

    for (i = r1; i < r9 - 1; i++)
    {
        ptr = gUnknown_02022C98;

        if (gUnknown_02022C98->unkC4[i] == 0 || gUnknown_02022C98->unkC4[i] == 1)
        {
            gUnknown_02022C98->unk120 = 1;
            if (ptr->unk_32CC.unk_14.unk_B[i] >= 10)
            {
                ptr->unk_32CC.unk_14.unk_B[i] = 10;
                gUnknown_02022C98->unkC4[i] = 3;
                if (gUnknown_02022C98->unk148[i] == 0)
                {
                    gUnknown_02022C98->unk148[i] = 1;
                    PlaySE(SE_FUUSEN1 + ptr->unk_32CC.unk_14.unk_0[i]);
                }
                if (gUnknown_02022C98->unk40 < 10 || r10 == 1)
                {
                    r10 = 1;
                    gUnknown_02022C98->unk148[i] = 0;
                    if (gUnknown_02022C98->unk40 < 10)
                    {
                        gUnknown_02022C98->unk40++;
                    }
                    sub_8026F1C(3, i, 0);
                    sub_8027234(0);
                }
            }
            else
            {
                r3 = gUnknown_02022C98->unk90[sub_8026D8C(i)] / 7;
                if (r3 >= 2)
                {
                    r3 = 2;
                }
                r2 = gUnknown_082F7A88[r3][ptr->unk_32CC.unk_14.unk_0[i]];
                if (++gUnknown_02022C98->unkD0[i] >= r2)
                {
                    ptr->unk_32CC.unk_14.unk_B[i]++;
                    gUnknown_02022C98->unkD0[i] = 0;
                }
                sub_8026324();
            }
        }
        else if (gUnknown_02022C98->unkC4[i] == 2)
        {
            gUnknown_02022C98->unk120 = 1;
            if (++gUnknown_02022C98->unkDC[i] >= 20)
            {
                gUnknown_02022C98->unk_31A0[gUnknown_02022C98->unkB8[i]].unk_30 = 0;
                gUnknown_02022C98->unkDC[i] = 0;
                gUnknown_02022C98->unkD0[i] = 0;
                gUnknown_02022C98->unkC4[i] = 0;
                ptr->unk_32CC.unk_14.unk_B[i] = 1;
                ptr->unk_32CC.unk_14.unk_0[i] = sub_8026DB0(sub_8026D8C(i), i);
            }
        }
        else if (gUnknown_02022C98->unkC4[i] == 3)
        {
            if (++gUnknown_02022C98->unkDC[i] >= 20)
            {
                if (gUnknown_02022C98->unk40 < 10)
                {
                    gUnknown_02022C98->unkDC[i] = 0;
                    gUnknown_02022C98->unkD0[i] = 0;
                    gUnknown_02022C98->unkC4[i] = 0;
                    ptr->unk_32CC.unk_14.unk_B[i] = 1;
                    gUnknown_02022C98->unkE8[i] = ptr->unk_32CC.unk_14.unk_0[i];
                    ptr->unk_32CC.unk_14.unk_0[i] = sub_8026DB0(sub_8026D8C(i), i);
                }
            }
        }
    }
}

void sub_8028BF8(u8 arg0, u8 arg1);
void sub_8028CA4(u8 arg0, u8 arg1);
void sub_8028C7C(u8 arg0, u8 arg1);
void sub_80286B4(u8 arg0, u8 arg1);
void sub_80288D4(u8 arg0);
u8 sub_8027DFC(u32 arg0);

void sub_8026988(void)
{
    u8 i, first, count;

    first = gUnknown_02022C98->unk44;
    count = gUnknown_02022C98->unk48;
    for (i = first; i < count; i++)
    {
        struct DodrioBerryPickingSubstruct_31A0 *ptr = &gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId];
        u8 var = gUnknown_082F449C[gUnknown_02022C98->unk24 - 1][gUnknown_02022C98->multiplayerId][i];

        if (ptr->unk_14.unk_B[var] != 0)
            sub_8028BF8(i, 0);
        else
            sub_8028BF8(i, 1);

        if (ptr->unk_14.unk_B[var] > 9)
        {
            sub_8028CA4(i, ptr->unk_14.unk_0[var] + 3);
            sub_8028C7C(i, ptr->unk_14.unk_B[var] * 2 - 1);
        }
        else if (ptr->unk_14.unk_0[var] == 3)
        {
            ptr->unk_14.unk_B[var] = 7;
            sub_8028CA4(i, 6);
            sub_8028C7C(i, ptr->unk_14.unk_B[var] * 2 - 1);
        }
        else
        {
            sub_8028CA4(i, ptr->unk_14.unk_0[var]);
            sub_8028C7C(i, ptr->unk_14.unk_B[var] * 2);
        }
    }
}

void sub_8026A88(void)
{
    u8 i, count;

    count = gUnknown_02022C98->unk24;
    for (i = 0; i < count; i++)
    {
        struct DodrioBerryPickingSubstruct_31A0 *ptr = &gUnknown_02022C98->unk_31A0[i];
        sub_80286B4(i, ptr->unk_2C);
    }
}

void sub_8026AC8(void)
{
    u8 i, count;

    count = gUnknown_02022C98->unk24;
    for (i = 0; i < count; i++)
        sub_80286B4(i, 4);
}

void sub_8026AF4(void)
{
    sub_8026988();
    if (gUnknown_02022C98->unk40 > 9)
        sub_8026AC8();
    else
        sub_8026A88();

    sub_80288D4(gUnknown_02022C98->unk40);
}

// This function is literally the same as the one above...Why?
void sub_8026B28(void)
{
    sub_8026988();
    if (gUnknown_02022C98->unk40 > 9)
        sub_8026AC8();
    else
        sub_8026A88();

    sub_80288D4(gUnknown_02022C98->unk40);
}

void sub_8026B5C(u8 arg0, u8 *arg1, u8 *arg2)
{
    switch (arg0)
    {
    case 1:
        *arg1 = 4, *arg2 = 7;
        break;
    case 2:
        *arg1 = 3, *arg2 = 8;
        break;
    case 3:
        *arg1 = 2, *arg2 = 9;
        break;
    case 4:
        *arg1 = 1, *arg2 = 10;
        break;
    case 5:
        *arg1 = 0, *arg2 = 11;
        break;
    }
}

bool32 sub_8026BB8(void)
{
    u8 i, count;

    count = gUnknown_02022C98->unk24;
    for (i = 1; i < count; i++)
    {
        if (gUnknown_02022C98->unk158[i] == 0)
            gUnknown_02022C98->unk158[i] = sub_8027DFC(i);
    }

    // This loop won't ever run, the seemingly poitnless assingment below is to make the compiler
    // generate code for it.
    count = count;
    for (; i < count; i++)
    {
        if (gUnknown_02022C98->unk158[i] == 0)
            return FALSE;
    }

    return TRUE;
}

void sub_8026C28(void)
{
    u8 i;

    for (i = 0; i < 5; i++)
        gUnknown_02022C98->unk158[i] = 0;
}

bool32 sub_8026C50(void)
{
    if (gUnknown_02022C98->unk40 > 9 && gUnknown_02022C98->unk120 == 0)
    {
        gUnknown_02022C98->unk40 = 10;
        if (gUnknown_02022C98->unk12C != 0)
            return TRUE;
    }

    return FALSE;
}

bool32 sub_8026C90(void)
{
    u8 i, first, count;

    if (gUnknown_02022C98->unk40 > 9)
    {
        first = gUnknown_02022C98->unk44;
        count = gUnknown_02022C98->unk48;
        gUnknown_02022C98->unk40 = 10;
        if (gUnknown_02022C98->unk12C != 0)
        {
            for (i = first; i < count; i++)
            {
                struct DodrioBerryPickingSubstruct_31A0 *ptr = &gUnknown_02022C98->unk_31A0[gUnknown_02022C98->multiplayerId];
                u8 var = gUnknown_082F449C[gUnknown_02022C98->unk24 - 1][gUnknown_02022C98->multiplayerId][i];

                if (ptr->unk_14.unk_B[var] != 10)
                    return FALSE;
            }
            return TRUE;
        }
    }

    return FALSE;
}

void sub_8026D1C(u8 arg0)
{
    u8 var = gUnknown_082F7A9C[gUnknown_02022C98->unk90[arg0] % 7] + (gUnknown_02022C98->unk90[arg0] / 7) * 100;
    if (gUnknown_02022C98->unk86[arg0] >= var)
        gUnknown_02022C98->unk90[arg0]++;
}

/*
u8 sub_8026D8C(u8 arg0)
{
    return gUnknown_082F7BA4[0x1AC + (gUnknown_02022C98->unk24 - 1) * 11 + arg0];
}
*/

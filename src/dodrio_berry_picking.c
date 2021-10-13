#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "dodrio_berry_picking.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "m4a.h"
#include "main.h"
#include "palette.h"
#include "minigame_countdown.h"
#include "random.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/items.h"
#include "constants/songs.h"

struct DodrioSubstruct_0160
{
    /*0x0000 : 0x3000*/ u16 ALIGNED(4) tilemapBuffers[3][BG_SCREEN_SIZE];
    /*0x3000 : 0x3160*/ bool32 finished;
    /*0x3004 : 0x3164*/ u8 ALIGNED(4) unk3004;
    /*0x3008 : 0x3168*/ u8 ALIGNED(4) unk3008[10];
    /*0x3014 : 0x3174*/ u8 ALIGNED(4) state;
    /*0x3018 : 0x3178*/ u8 ALIGNED(4) unk3018;
    /*0x301C : 0x317C*/ u16 ALIGNED(4) unk301C;
    /*0x3020 : 0x3180*/ u8 ALIGNED(4) unk3020;
    /*0x3024 : 0x3184*/ u8 ALIGNED(4) unk3024;
    /*0x3024 : 0x3184*/ void (*unk3028)(void);
}; // size = 0x302C

struct DodrioStruct_2022CF4
{
    u8 filler_00[0xc];
    u8 unkC[10];
    s16 unk16[10];
    u16 unk2A[10];
    u16 unk3E;
}; // size = 0x40

struct DodrioSubstruct_31A0_14
{
    u8 unk0[11];
    u8 unkB[11];
};

struct DodrioSubstruct_31A0_2C
{
    u8 unk0;
    u8 ALIGNED(4) unk4;
    u8 ALIGNED(4) unk8;
};

struct DodrioSubstruct_31A0
{
    u8 name[0x10];
    u32 unk10;
    struct DodrioSubstruct_31A0_14 unk14;
    struct DodrioSubstruct_31A0_2C unk2C;
    u8 filler_35[4];
}; // size = 0x3C

struct DodrioSubstruct_318C
{
    bool8 isShiny;
};

struct DodrioSubstruct_3308
{
    u8 unk0;
    u32 unk4;
};

struct DodrioStruct
{
    /*0x0000*/ void (*savedCallback)(void);
    /*0x0004*/ u8 ALIGNED(4) unk04;
    /*0x0008*/ u8 ALIGNED(4) unk08;
    /*0x000C*/ u8 ALIGNED(4) unk0C;
    /*0x0010*/ u8 ALIGNED(4) unk10;
    /*0x0014*/ u8 ALIGNED(4) unk14;
    /*0x0018*/ u8 ALIGNED(4) unk18;
    /*0x001C*/ u8 ALIGNED(4) unk1C;
    /*0x0020*/ u8 ALIGNED(4) unk20;
    /*0x0024*/ u8 ALIGNED(4) unk24;
    /*0x0028*/ u8 ALIGNED(4) multiplayerId;
    /*0x0029*/ u8 filler_0029[7];
    /*0x0030*/ u8 ALIGNED(4) unk30;
    /*0x0034*/ u8 ALIGNED(4) unk34[5];
    /*0x003C*/ u8 ALIGNED(4) unk3C;
    /*0x0040*/ u8 ALIGNED(4) unk40;
    /*0x0044*/ u8 ALIGNED(4) unk44;
    /*0x0048*/ u8 ALIGNED(4) unk48;
    /*0x004A*/ u16 unk4A[5][6];
    /*0x0086*/ u16 unk86[5];
    /*0x0090*/ u8 ALIGNED(4) unk90[5];
    /*0x0098*/ u8 ALIGNED(4) unk98[4];
    /*0x009C*/ u8 ALIGNED(4) unk9C[11];
    /*0x00A8*/ u8 ALIGNED(4) unkA8[5];
    /*0x00B0*/ u8 ALIGNED(4) unkB0[5];
    /*0x00B8*/ u8 ALIGNED(4) unkB8[11];
    /*0x00C4*/ u8 ALIGNED(4) unkC4[11];
    /*0x00D0*/ u8 ALIGNED(4) unkD0[11];
    /*0x00DC*/ u8 ALIGNED(4) unkDC[11];
    /*0x00E8*/ u8 ALIGNED(4) unkE8[11];
    /*0x00F4*/ u8 ALIGNED(4) unkF4[11][2];
    /*0x010C*/ u8 ALIGNED(4) unk10C[5];
    /*0x0112*/ u16 unk112;
    /*0x0114*/ u16 unk114;
    /*0x0118*/ u32 unk118;
    /*0x011C*/ u32 unk11C;
    /*0x0120*/ u32 unk120;
    /*0x0124*/ u8 ALIGNED(4) unk124;
    /*0x0128*/ u8 ALIGNED(4) unk128;
    /*0x012C*/ u32 unk12C;
    /*0x0130*/ u32 unk130[5];
    /*0x0144*/ u8 ALIGNED(4) unk144;
    /*0x0148*/ u8 ALIGNED(4) unk148[11];
    /*0x0154*/ u8 ALIGNED(4) unk154;
    /*0x0158*/ u8 ALIGNED(4) unk158[5];
    /*0x0160*/ struct DodrioSubstruct_0160 unk160;
    /*0x318C*/ struct DodrioSubstruct_318C unk318C[5];
    /*0x31A0*/ struct DodrioSubstruct_31A0 unk31A0[5];
    /*0x32CC*/ struct DodrioSubstruct_31A0 unk32CC;
    /*0x3308*/ struct DodrioSubstruct_3308 unk3308[5];
}; // size = 0x3330

EWRAM_DATA static struct DodrioStruct * gUnknown_02022C98 = NULL;
EWRAM_DATA static u16 *gUnknown_02022C9C[5] = {NULL};
EWRAM_DATA static u16 *gUnknown_02022CB0[2] = {NULL};
EWRAM_DATA static u16 *gUnknown_02022CB8[11] = {NULL};
EWRAM_DATA static u16 *gUnknown_02022CE4[4] = {NULL};
EWRAM_DATA static struct DodrioStruct_2022CF4 *gUnknown_02022CF4 = NULL;
EWRAM_DATA static struct DodrioSubstruct_0160 *gUnknown_02022CF8 = NULL;

static bool32 gUnknown_03000DB0;

static void sub_8024A1C(void);
static void sub_8024A30(struct DodrioStruct *);
static void sub_8024BC8(u8 taskId);
static void sub_8024DBC(void);
static void sub_8024E00(void);
static void sub_8024E38(void);
static void sub_8024F10(void);
static void sub_8024F38(void);
static void sub_8024FFC(void);
static void sub_80250D4(void);
static void sub_8025158(void);
static void sub_8025198(void);
static void sub_8025230(void);
static void sub_8025324(void);
static void sub_8025470(void);
static void sub_8025644(void);
static void sub_80256AC(void);
static void sub_8025758(void);
static void sub_802589C(u8 taskId);
static void sub_8025910(u8 taskId);
static void sub_8025D04(void);
static void sub_8025D50(void);
static void sub_8025E0C(void);
static void sub_8025ED8(void);
static void sub_8025F48(void);
static void sub_8026044(void);
static void sub_80261CC(void);
static void sub_80261E4(void);
static void sub_80261F8(struct DodrioSubstruct_318C *, struct Pokemon *);
static void sub_802620C(TaskFunc, u8);
static void sub_802621C(TaskFunc);
static void sub_8026240(u8);
static bool32 sub_8026264(void);
static void sub_80262C0(void);
static bool32 sub_8026634(u8, u8, u8);
static void sub_802671C(void);
static void sub_8026AF4(void);
static void sub_8026B28(void);
static void sub_8026B5C(u8, u8*, u8*);
static bool32 sub_8026BB8(void);
static void sub_8026C28(void);
static bool32 sub_8026C50(void);
static bool32 sub_8026C90(void);
static void sub_8026D1C(u8);
static u8 sub_8026D8C(u8);
static u8 sub_8026DB0(u8, u8);
static void sub_8026F1C(u8, u8, u8);
static void sub_8027234(bool32 arg0);
static void sub_80272A4(void);
static void sub_80272E8(void);
static void sub_80273F0(void);
static void sub_802749C(void);
static u8 sub_8027518(u8);
static void sub_8027554(void);
static void sub_8027608(void);
static u32 sub_8027748(void);
static void sub_8027DD0(u32 arg0);
static void sub_8027E30(struct DodrioSubstruct_31A0 *arg0, struct DodrioSubstruct_31A0_2C *arg1, struct DodrioSubstruct_31A0_2C *arg2, struct DodrioSubstruct_31A0_2C *arg3, struct DodrioSubstruct_31A0_2C *arg4, struct DodrioSubstruct_31A0_2C *arg5, u8 arg6, u32 arg7, u32 arg8);
static u32 sub_8028164(u32 unused, struct DodrioSubstruct_31A0 *arg0, struct DodrioSubstruct_31A0_2C *arg1, struct DodrioSubstruct_31A0_2C *arg2, struct DodrioSubstruct_31A0_2C *arg3, struct DodrioSubstruct_31A0_2C *arg4, struct DodrioSubstruct_31A0_2C *arg5, u8 *arg6, u32 *arg7, u32 *arg8);
static void sub_80282EC(u8);
static u32 sub_8028318(u32 arg0, u8 *arg1);
static void sub_8028350(u32 arg0);
static u32 sub_8028374(u32 arg0);
static void sub_80283A8(void);
static void sub_8028408(struct DodrioSubstruct_318C *arg0, u8 arg1, u8 id, u8 arg3);
static void sub_80284CC(u8);
static void sub_8028504(u8);
static void sub_8028614(u8 count);
static void sub_802868C(bool8 invisible, u8 count);
static void sub_8028734(void);
static void sub_80287E4(void);
static void sub_80289E8(bool8 invisible);
static void sub_80286E4(void);
static bool32 sub_8028828(void);
static void sub_8028A34(void);
static void sub_8028A88(void);
static void sub_8028B80(void);
static void sub_8028D44(void);
static void sub_8028DFC(void);
static void sub_8028E4C(void);
static void sub_8028E84(void);
static void sub_8028EC8(bool8 invisible);
static void sub_8028FCC(void);
static void sub_802903C(void);
static void sub_8029274(struct DodrioSubstruct_0160 *PTR);
static void sub_80292E0(u8);
static bool32 sub_802A770(void);
static u8 sub_802A794(void);
static void sub_8028BF8(u8 id, bool8 invisible);
static void sub_8028C30(bool8 invisible);
static void sub_8028CA4(u16 id, u8 frameNum);
static void sub_8028C7C(u8 id, u8 y);
static void sub_80286B4(u8 id, u8 frameNum);
static u8 sub_8026E70(u8 arg0, u8 arg1);
static void sub_80288D4(u8 arg0);
static u32 sub_8027DFC(u32 arg0);
static u32 IncrementWithLimit(u32 arg0, u32 arg1);
static u32 Min(u32 arg0, u32 arg1);
static u32 sub_80276C0(u8 arg0);
static void Task_ShowDodrioBerryPickingRecords(u8 taskId);
static void sub_8029314(u8 taskId);
static void sub_8027BEC(u8 windowId, s32 width);
static void nullsub_15(struct Sprite *sprite);
static void sub_80284A8(struct Sprite *sprite);
static u32 sub_802853C(struct Sprite *sprite);
static u32 sub_80285AC(struct Sprite *sprite);
static s16 sub_8028F14(u8 arg0, u8 arg1);
static void sub_8028654(bool8 invisible, u8 id);
static void sub_8029338(void);
static bool32 sub_802A8E8(void);
static void sub_802A7A8(void);
static void sub_802A72C(void (*func)(void));
static void (*sub_802A75C(void))(void);
static void sub_8029338(void);
static void sub_8029440(void);
static void sub_802988C(void);
static void sub_802A010(void);
static void sub_802A380(void);
static void sub_802A454(void);
static void sub_802A534(void);
static void sub_802A588(void);
static void sub_802A6FC(void);
static void nullsub_16(void);

// const rom data
static const u8 gUnknown_082F449C[5][5][11] =
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

static const u8 gUknnown_082F45AF[5][5][3] =
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

static const u8 gUnknown_082F45FA[5][5][3] =
{
    {
        {1, 0, 1},
    },
    {
        {1, 0, 1},
        {0, 1, 0},
    },
    {
        {2, 0, 1},
        {0, 1, 2},
        {1, 2, 0},
    },
    {
        {3, 0, 1},
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 0},
    },
    {
        {4, 0, 1},
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 0},
    },
};

ALIGNED(4)
static const u8 gUnknown_082F4648[5][11] =
{
    {9, 9, 9, 9, 1, 1, 1, 9, 9, 9, 9},
    {9, 9, 9, 0, 0, 1, 1, 0, 9, 9, 9},
    {9, 9, 2, 2, 0, 0, 1, 1, 1, 9, 9},
    {9, 3, 3, 0, 0, 1, 1, 2, 2, 3, 9},
    {3, 3, 4, 4, 0, 0, 1, 1, 2, 2, 3},
};

static const u8 gUnknown_082F467F[5][5] =
{
    {5},
    {4, 6},
    {3, 5, 7},
    {2, 4, 6, 8},
    {1, 3, 5, 6, 9},
};

// Duplicate and unused gfx. Feel free to remove.
static const u32 sDuplicateGfx[] = INCBIN_U32("graphics/link_games/dodrioberry_bg1.gbapal",
                                     "graphics/link_games/dodrioberry_bg2.gbapal",
                                     "graphics/link_games/dodrioberry_pkmn.gbapal",
                                     "graphics/link_games/dodrioberry_shiny.gbapal",
                                     "graphics/link_games/dodrioberry_status.gbapal",
                                     "graphics/link_games/dodrioberry_berrysprites.gbapal",
                                     "graphics/link_games/dodrioberry_berrysprites.4bpp.lz",
                                     "graphics/link_games/dodrioberry_platform.gbapal",
                                     "graphics/link_games/dodrioberry_bg1.4bpp.lz",
                                     "graphics/link_games/dodrioberry_bg2.4bpp.lz",
                                     "graphics/link_games/dodrioberry_status.4bpp.lz",
                                     "graphics/link_games/dodrioberry_platform.4bpp.lz",
                                     "graphics/link_games/dodrioberry_pkmn.4bpp.lz",
                                     "graphics/link_games/dodrioberry_bg1.bin.lz",
                                     "graphics/link_games/dodrioberry_bg2right.bin.lz",
                                     "graphics/link_games/dodrioberry_bg2left.bin.lz");


static const u8 gUnknown_082F7A88[][3] =
{
    {40, 24, 13},
    {32, 19, 10},
    {22, 13, 7},
};

ALIGNED(4)
static const u8 gUnknown_082F7A94[] = {8, 5, 8, 11, 15};

ALIGNED(4)
static const u8 gUnknown_082F7A9C[] = {5, 10, 20, 30, 50, 70, 100};

ALIGNED(4)
static const u8 gUnknown_082F7AA4[][10] =
{
    {15, 16, 17, 18, 19, 19, 18, 17, 16, 15},
    {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34, 34, 33, 32, 31, 30},
};

static void (*const gUnknown_082F7AC4[])(void) =
{
    sub_8024DBC,
    sub_8024E00,
    sub_8024E38,
    sub_8024F10,
    sub_8024F38,
    sub_8025198,
    sub_8025324,
    sub_8025470,
    sub_8025644,
    sub_80256AC,
    sub_8025758,
    sub_80250D4
};

static void (*const gUnknown_082F7AF4[])(void) =
{
    sub_8024DBC,
    sub_8024E00,
    sub_8024E38,
    sub_8024F10,
    sub_8024FFC,
    sub_8025230,
    sub_8025324,
    sub_8025470,
    sub_8025644,
    sub_80256AC,
    sub_8025758,
    sub_8025158
};

// code
void StartDodrioBerryPicking(u16 a0, void (*callback)(void))
{
    gUnknown_03000DB0 = FALSE;

    if (gReceivedRemoteLinkPlayers != 0 && (gUnknown_02022C98 = AllocZeroed(sizeof(*gUnknown_02022C98))) != NULL)
    {
        sub_8024A1C();
        sub_8024A30(gUnknown_02022C98);
        gUnknown_02022C98->savedCallback = callback;
        gUnknown_02022C98->multiplayerId = GetMultiplayerId();
        gUnknown_02022C98->unk32CC = gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId];
        sub_80261F8(&gUnknown_02022C98->unk318C[gUnknown_02022C98->multiplayerId], &gPlayerParty[a0]);
        CreateTask(sub_8024BC8, 1);
        SetMainCallback2(sub_80261CC);
        sub_80273F0();
        sub_8026B5C(gUnknown_02022C98->unk24, &gUnknown_02022C98->unk44, &gUnknown_02022C98->unk48);
        StopMapMusic();
        PlayNewMapMusic(MUS_RG_BERRY_PICK);
    }
    else
    {
        SetMainCallback2(callback);
        return;
    }
}

static void sub_8024A1C(void)
{
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
}

static void sub_8024A30(struct DodrioStruct * data)
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

static void sub_8024BC8(u8 taskId)
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
            Rfu_SetLinkStandbyCallback();
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
            sub_8028408(&gUnknown_02022C98->unk318C[gUnknown_02022C98->unk34[r4]], r4, gUnknown_02022C98->unk34[r4], gUnknown_02022C98->unk24);
        }
        sub_802868C(FALSE, gUnknown_02022C98->unk24);
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

static void sub_8024D4C(u8 taskId)
{
    sub_8025D04();
    gUnknown_082F7AC4[gUnknown_02022C98->unk18]();
    if (!gUnknown_03000DB0)
    {
        sub_8026AF4();
    }
    sub_8025D50();
}

static void sub_8024D84(u8 taskId)
{
    sub_8025E0C();
    gUnknown_082F7AF4[gUnknown_02022C98->unk18]();
    if (!gUnknown_03000DB0)
    {
        sub_8026B28();
    }
    sub_8025ED8();
}

static void sub_8024DBC(void)
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

static void sub_8024E00(void)
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

static void sub_8024E38(void)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        StartMinigameCountdown(7, 8, 120, 80, 0);
        gUnknown_02022C98->unk10++;
        break;
    case 1:
        Rfu_SetLinkStandbyCallback();
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
        if (!IsMinigameCountdownRunning())
        {
            gUnknown_02022C98->unk10++;
        }
        break;
    case 4:
        if (++gUnknown_02022C98->unk30 > 5)
        {
            Rfu_SetLinkStandbyCallback();
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

static void sub_8024F10(void)
{
    if (gUnknown_02022C98->unk10 == 0)
    {
        if (gUnknown_02022C98->unk11C != 0)
        {
            sub_8026240(4);
        }
    }
}

static void sub_8024F38(void)
{
    if (gUnknown_02022C98->unk10 == 0)
    {
        if (gUnknown_02022C98->unk40 < 10)
        {
            if (gUnknown_02022C98->unkA8[0] == 0)
            {
                if (JOY_NEW(DPAD_UP))
                {
                    if (gUnknown_02022C98->unk31A0[0].unk2C.unk0 == 0)
                    {
                        gUnknown_02022C98->unk31A0[0].unk2C.unk4 = 0;
                        gUnknown_02022C98->unk31A0[0].unk2C.unk0 = sub_8027518(2);
                    }
                }
                else if (JOY_NEW(DPAD_RIGHT))
                {
                    if (gUnknown_02022C98->unk31A0[0].unk2C.unk0 == 0)
                    {
                        gUnknown_02022C98->unk31A0[0].unk2C.unk4 = 0;
                        gUnknown_02022C98->unk31A0[0].unk2C.unk0 = sub_8027518(1);
                    }
                }
                else if (JOY_NEW(DPAD_LEFT))
                {
                    if (gUnknown_02022C98->unk31A0[0].unk2C.unk0 == 0)
                    {
                        gUnknown_02022C98->unk31A0[0].unk2C.unk4 = 0;
                        gUnknown_02022C98->unk31A0[0].unk2C.unk0 = sub_8027518(3);
                    }
                }
                else
                {
                    gUnknown_02022C98->unk31A0[0].unk2C.unk0 = sub_8027518(0);
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

static void sub_8024FFC(void)
{
    if (gUnknown_02022C98->unk40 < 10)
    {
        if (JOY_NEW(DPAD_UP))
        {
            if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 == 0)
            {
                gUnknown_02022C98->unk32CC.unk2C.unk0 = 2;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 == 0)
            {
                gUnknown_02022C98->unk32CC.unk2C.unk0 = 1;
            }
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 == 0)
            {
                gUnknown_02022C98->unk32CC.unk2C.unk0 = 3;
            }
        }
        else
        {
            gUnknown_02022C98->unk32CC.unk2C.unk0 = 0;
        }
    }
    else
    {
        sub_8026240(11);
    }
    sub_8026044();
}

static void sub_80250D4(void)
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

static void sub_8025158(void)
{
    sub_8026044();
    if (sub_8026C90() == 1)
        sub_8026240(5);
}

static bool32 sub_8025170(void)
{
    u8 recvStatus = GetBlockReceivedStatus();
    u8 playerFlags = GetLinkPlayerCountAsBitFlags();
    if (recvStatus == playerFlags)
    {
        ResetBlockReceivedFlags();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void sub_8025198(void)
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
            FadeOutAndPlayNewMapMusic(MUS_RG_VICTORY_WILD, 4);
        }
        break;
    }
}

static void sub_8025230(void)
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
            FadeOutAndPlayNewMapMusic(MUS_RG_VICTORY_WILD, 4);
        }
        break;
    }
}

static void sub_8025324(void)
{
    u8 sp00 = 1;
    u8 i;

    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        sub_802749C();
        sub_80289E8(TRUE);
        sub_8028DFC();
        sub_8028EC8(TRUE);
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

static void sub_8025470(void)
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

static void sub_8025644(void)
{
    switch (gUnknown_02022C98->unk10)
    {
    case 0:
        SetCloseLinkCallback();
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

static void sub_80256AC(void)
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

static void sub_8025758(void)
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
        PlayNewMapMusic(MUS_RG_BERRY_PICK);
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
        sub_8028EC8(FALSE);
        break;
    }
}

static void sub_802589C(u8 taskId)
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
        if (sub_8028828() == TRUE)
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

static void sub_8025910(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 i;

    switch (data[0])
    {
    case 0:
        if (SendBlock(0, &gUnknown_02022C98->unk318C[gUnknown_02022C98->multiplayerId].isShiny, sizeof(gUnknown_02022C98->unk318C[gUnknown_02022C98->multiplayerId].isShiny)))
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
                *(u8 *)&gUnknown_02022C98->unk318C[i] = *(u8 *)gBlockRecvBuffer[i];
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

static void sub_80259FC(void)
{
    u8 i;
    u8 r7 = gUnknown_02022C98->unk24;

    gUnknown_02022C98->unk31A0[0].unk10 = sub_8028164(0, &gUnknown_02022C98->unk31A0[0], &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
    gUnknown_02022C98->unk128 = 1;

    for (i = 1; i < r7; i++)
    {
        if (   gUnknown_02022C98->unkA8[i] == 0
            && sub_8028318(i, &gUnknown_02022C98->unk31A0[i].unk2C.unk0) == 0)
        {
            gUnknown_02022C98->unk31A0[i].unk2C.unk0 = 0;
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
        if (   gUnknown_02022C98->unk31A0[i].unk2C.unk0 != 0
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
                gUnknown_02022C98->unk31A0[i].unk2C.unk0 = 0;
                gUnknown_02022C98->unk31A0[i].unk2C.unk4 = 0;
                gUnknown_02022C98->unk31A0[i].unk2C.unk8 = 0;
            }
            break;
        case 4:
            if (++gUnknown_02022C98->unkB0[i] >= 40)
            {
                gUnknown_02022C98->unkB0[i] = 0;
                gUnknown_02022C98->unkA8[i] = 0;
                gUnknown_02022C98->unk31A0[i].unk2C.unk0 = 0;
                gUnknown_02022C98->unk31A0[i].unk2C.unk4 = 0;
                gUnknown_02022C98->unk31A0[i].unk2C.unk8 = 0;
            }
            break;
        }
    }
}

static void sub_8025C0C(void)
{
    u8 i;
    u8 r6 = gUnknown_02022C98->unk24;

    gUnknown_02022C98->unk31A0[0].unk10 = sub_8028164(0, &gUnknown_02022C98->unk31A0[0], &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
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

static void sub_8025D04(void)
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

static void sub_8025D50(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 4:
        sub_8027E30(&gUnknown_02022C98->unk32CC, &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, gUnknown_02022C98->unk40, gUnknown_02022C98->unk120, gUnknown_02022C98->unk12C);
        break;
    case 11:
        sub_8027E30(&gUnknown_02022C98->unk32CC, &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, gUnknown_02022C98->unk40, gUnknown_02022C98->unk120, gUnknown_02022C98->unk12C);
        break;
    }
}

static void sub_8025E0C(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 4:
        sub_8028164(gUnknown_02022C98->multiplayerId, &gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId], &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
        break;
    case 11:
        sub_8028164(gUnknown_02022C98->multiplayerId, &gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId], &gUnknown_02022C98->unk31A0[0].unk2C, &gUnknown_02022C98->unk31A0[1].unk2C, &gUnknown_02022C98->unk31A0[2].unk2C, &gUnknown_02022C98->unk31A0[3].unk2C, &gUnknown_02022C98->unk31A0[4].unk2C, &gUnknown_02022C98->unk40, &gUnknown_02022C98->unk120, &gUnknown_02022C98->unk12C);
        break;
    }
}

static void sub_8025ED8(void)
{
    switch (gUnknown_02022C98->unk18)
    {
    case 3:
        sub_8027DD0(1);
        gUnknown_02022C98->unk11C = 1;
        break;
    case 4:
        if (gUnknown_02022C98->unk32CC.unk2C.unk0 != 0)
        {
            sub_80282EC(gUnknown_02022C98->unk32CC.unk2C.unk0);
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

static void sub_8025F48(void)
{
    if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 == 0)
    {
        if (!IsSEPlaying())
        {
            gUnknown_02022C98->unk144 = 0;
        }
    }
    else if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk4 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0)
        {
            m4aSongNumStop(SE_SUCCESS);
            PlaySE(SE_SUCCESS);
            gUnknown_02022C98->unk144 = 1;
        }
    }
    else if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk8 == 1)
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
        PlayFanfareByFanfareNum(11); // MUS_TOO_BAD
        gUnknown_02022C98->unk154 = 2;
    }
}

static void sub_8026044(void)
{
    u8 r8 = gUnknown_02022C98->unk44;
    u8 r7 = gUnknown_02022C98->unk48;
    u8 r4;
    if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 == 0)
    {
        if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk4 != 1 && gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk8 != 1)
        {
            gUnknown_02022C98->unk144 = 0;
        }
    }
    else if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk4 == 1)
    {
        if (gUnknown_02022C98->unk144 == 0)
        {
            m4aSongNumStop(SE_SUCCESS);
            PlaySE(SE_SUCCESS);
            gUnknown_02022C98->unk144 = 1;
        }
    }
    else if (gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk8 == 1)
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
        struct DodrioSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk14;
        if (ptr->unkB[r4] >= 10)
        {
            if (gUnknown_02022C98->unk148[r4] == 0)
            {
                PlaySE(SE_BALLOON_RED + ptr->unk0[r4]);
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
        PlayFanfareByFanfareNum(11); // MUS_TOO_BAD
        gUnknown_02022C98->unk154 = 2;
    }
}

static void sub_80261CC(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_80261E4(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_80261F8(struct DodrioSubstruct_318C * a0, struct Pokemon * a1)
{
    a0->isShiny = IsMonShiny(a1);
}

static void sub_802620C(TaskFunc func, u8 priority)
{
    CreateTask(func, priority);
}

static void sub_802621C(TaskFunc func)
{
    gUnknown_02022C98->unk04 = CreateTask(func, 1);
    gUnknown_02022C98->unk10 = 0;
    gUnknown_02022C98->unk0C = 0;
    gUnknown_02022C98->unk14 = 0;
}

static void sub_8026240(u8 a0)
{
    gUnknown_02022C98->unk1C = gUnknown_02022C98->unk18;
    gUnknown_02022C98->unk18 = a0;
    gUnknown_02022C98->unk10 = 0;
    gUnknown_02022C98->unk14 = 0;
}

static bool32 sub_8026264(void)
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

static void sub_80262C0(void)
{
    u8 i;
    u8 start = gUnknown_02022C98->unk44;
    u8 finish = gUnknown_02022C98->unk48;

    for (i = start; i < finish; i++)
    {
        struct DodrioSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk32CC.unk14;
        ptr->unkB[i] = (i % 2 == 0) ? 1 : 0;
        ptr->unk0[i] = 0;
    }
}

static void sub_8026324(void)
{
    u8 sp0 = gUnknown_02022C98->unk44;
    u8 sp4 = gUnknown_02022C98->unk48;
    u8 sp8 = gUnknown_02022C98->unk24;
    u8 i, j, k, r5;

    if (gUnknown_02022C98->unk40 >= 10)
        return;

    for (i = 0; i < sp8; i++)
    {
        u8 *ptr = &gUnknown_02022C98->unk31A0[i].unk2C.unk0;
        if (*ptr != 0 && gUnknown_02022C98->unkA8[i] == 1)
        {
            for (j = sp0; j < sp4; j++)
            {
                r5 = gUnknown_082F449C[0][0][j];
                if (gUnknown_02022C98->unkF4[r5][0] == i || gUnknown_02022C98->unkF4[r5][1] == i)
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
                if (gUnknown_02022C98->unk31A0[i].unk2C.unk8 == 1)
                    break;
            }
        }
    }

    for (j = sp0; j < sp4; j++)
    {
        u8 id = 0xFF;
        r5 = gUnknown_082F449C[0][0][j];
        if (gUnknown_02022C98->unkC4[r5] == 1)
        {
            s32 r2;
            u8 r4, r3 = gUnknown_02022C98->unk90[sub_8026D8C(r5)] / 7;
            if (r3 >= ARRAY_COUNT(gUnknown_082F7A88) - 1)
                r3 = ARRAY_COUNT(gUnknown_082F7A88) - 1;

            r2 = gUnknown_082F7A88[r3][gUnknown_02022C98->unk31A0[0].unk14.unk0[r5]] - gUnknown_02022C98->unkD0[r5];
            if (r2 < 6)
                gUnknown_02022C98->unk9C[r5] += r2;

            if (++gUnknown_02022C98->unk9C[r5] >= 6)
            {
                gUnknown_02022C98->unk9C[r5] = 0;
                if (gUnknown_02022C98->unkF4[r5][0] == 0xFF && gUnknown_02022C98->unkF4[r5][1] == 0xFF)
                {
                    continue;
                }
                else if (gUnknown_02022C98->unkF4[r5][0] != 0xFF && gUnknown_02022C98->unkF4[r5][1] == 0xFF)
                {
                    r4 = gUnknown_02022C98->unkF4[r5][0];
                }
                else
                {
                    u8 unk0 = gUnknown_02022C98->unkF4[r5][0];
                    i = gUnknown_02022C98->unkF4[r5][1]; // Have to re-use the variable to match.
                    if (!(Random() & 1))
                    {
                        r4 = unk0;
                        id = i;
                    }
                    else
                    {
                        r4 = i;
                        id = unk0;
                    }
                }
                gUnknown_02022C98->unk32CC.unk14.unkB[r5] = 7;
                gUnknown_02022C98->unkC4[r5] = 2;
                gUnknown_02022C98->unkA8[r4] = 3;
                gUnknown_02022C98->unkB8[r5] = r4;
                gUnknown_02022C98->unk31A0[r4].unk2C.unk4 = 1;
                gUnknown_02022C98->unk31A0[id].unk2C.unk8 = 1;
                gUnknown_02022C98->unk86[r4]++;
                sub_8026F1C(0, r5, r4);
                sub_8027234(TRUE);
                sub_8026D1C(r4);
                gUnknown_02022C98->unkE8[r5] = gUnknown_02022C98->unk32CC.unk14.unk0[r5];
                gUnknown_02022C98->unk32CC.unk14.unk0[r5] = 3;
                gUnknown_02022C98->unkF4[r5][0] = 0xFF;
                gUnknown_02022C98->unkF4[r5][1] = 0xFF;
            }
        }
    }
}

static bool32 sub_8026634(u8 a0, u8 a1, u8 a2)
{
    s32 r7 = 0;
    u8 r5 = gUnknown_02022C98->unk24 - 1;
    struct DodrioSubstruct_31A0_14 * ptr = &gUnknown_02022C98->unk32CC.unk14;

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
    if (ptr->unkB[a2] == 6 || ptr->unkB[a2] == 7)
    {
        if (a2 == gUknnown_082F45AF[r5][a0][r7])
        {
            if (gUnknown_02022C98->unkC4[a2] == 1 || gUnknown_02022C98->unkC4[a2] == 2)
            {
                gUnknown_02022C98->unk31A0[a0].unk2C.unk8 = 1;
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
            gUnknown_02022C98->unk31A0[a0].unk2C.unk8 = 1;
        }
    }
    return FALSE;
}

static void sub_802671C(void)
{
    u8 r1 = gUnknown_02022C98->unk44;
    u8 r9 = gUnknown_02022C98->unk48;
    u8 r3 = 0;
    u8 r10 = 0;
    u8 i;
    u8 r2;
    struct DodrioStruct *ptr;

    gUnknown_02022C98->unk120 = 0;

    for (i = r1; i < r9 - 1; i++)
    {
        ptr = gUnknown_02022C98;

        if (gUnknown_02022C98->unkC4[i] == 0 || gUnknown_02022C98->unkC4[i] == 1)
        {
            gUnknown_02022C98->unk120 = 1;
            if (ptr->unk32CC.unk14.unkB[i] >= 10)
            {
                ptr->unk32CC.unk14.unkB[i] = 10;
                gUnknown_02022C98->unkC4[i] = 3;
                if (gUnknown_02022C98->unk148[i] == 0)
                {
                    gUnknown_02022C98->unk148[i] = 1;
                    PlaySE(SE_BALLOON_RED + ptr->unk32CC.unk14.unk0[i]);
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
                    sub_8027234(FALSE);
                }
            }
            else
            {
                r3 = gUnknown_02022C98->unk90[sub_8026D8C(i)] / 7;
                if (r3 >= 2)
                {
                    r3 = 2;
                }
                r2 = gUnknown_082F7A88[r3][ptr->unk32CC.unk14.unk0[i]];
                if (++gUnknown_02022C98->unkD0[i] >= r2)
                {
                    ptr->unk32CC.unk14.unkB[i]++;
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
                gUnknown_02022C98->unk31A0[gUnknown_02022C98->unkB8[i]].unk2C.unk4 = 0;
                gUnknown_02022C98->unkDC[i] = 0;
                gUnknown_02022C98->unkD0[i] = 0;
                gUnknown_02022C98->unkC4[i] = 0;
                ptr->unk32CC.unk14.unkB[i] = 1;
                ptr->unk32CC.unk14.unk0[i] = sub_8026DB0(sub_8026D8C(i), i);
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
                    ptr->unk32CC.unk14.unkB[i] = 1;
                    gUnknown_02022C98->unkE8[i] = ptr->unk32CC.unk14.unk0[i];
                    ptr->unk32CC.unk14.unk0[i] = sub_8026DB0(sub_8026D8C(i), i);
                }
            }
        }
    }
}

static void sub_8026988(void)
{
    u8 i, first, count;

    first = gUnknown_02022C98->unk44;
    count = gUnknown_02022C98->unk48;
    for (i = first; i < count; i++)
    {
        struct DodrioSubstruct_31A0 *ptr = &gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId];
        u8 var = gUnknown_082F449C[gUnknown_02022C98->unk24 - 1][gUnknown_02022C98->multiplayerId][i];

        if (ptr->unk14.unkB[var] != 0)
            sub_8028BF8(i, FALSE);
        else
            sub_8028BF8(i, TRUE);

        if (ptr->unk14.unkB[var] > 9)
        {
            sub_8028CA4(i, ptr->unk14.unk0[var] + 3);
            sub_8028C7C(i, ptr->unk14.unkB[var] * 2 - 1);
        }
        else if (ptr->unk14.unk0[var] == 3)
        {
            ptr->unk14.unkB[var] = 7;
            sub_8028CA4(i, 6);
            sub_8028C7C(i, ptr->unk14.unkB[var] * 2 - 1);
        }
        else
        {
            sub_8028CA4(i, ptr->unk14.unk0[var]);
            sub_8028C7C(i, ptr->unk14.unkB[var] * 2);
        }
    }
}

static void sub_8026A88(void)
{
    u8 i, count;

    count = gUnknown_02022C98->unk24;
    for (i = 0; i < count; i++)
    {
        struct DodrioSubstruct_31A0 *ptr = &gUnknown_02022C98->unk31A0[i];
        sub_80286B4(i, ptr->unk2C.unk0);
    }
}

static void sub_8026AC8(void)
{
    u8 i, count;

    count = gUnknown_02022C98->unk24;
    for (i = 0; i < count; i++)
        sub_80286B4(i, 4);
}

static void sub_8026AF4(void)
{
    sub_8026988();
    if (gUnknown_02022C98->unk40 > 9)
        sub_8026AC8();
    else
        sub_8026A88();

    sub_80288D4(gUnknown_02022C98->unk40);
}

// This function is literally the same as the one above...Why?
static void sub_8026B28(void)
{
    sub_8026988();
    if (gUnknown_02022C98->unk40 > 9)
        sub_8026AC8();
    else
        sub_8026A88();

    sub_80288D4(gUnknown_02022C98->unk40);
}

static void sub_8026B5C(u8 arg0, u8 *arg1, u8 *arg2)
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

static bool32 sub_8026BB8(void)
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

static void sub_8026C28(void)
{
    u8 i;

    for (i = 0; i < 5; i++)
        gUnknown_02022C98->unk158[i] = 0;
}

static bool32 sub_8026C50(void)
{
    if (gUnknown_02022C98->unk40 > 9 && gUnknown_02022C98->unk120 == 0)
    {
        gUnknown_02022C98->unk40 = 10;
        if (gUnknown_02022C98->unk12C != 0)
            return TRUE;
    }

    return FALSE;
}

static bool32 sub_8026C90(void)
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
                struct DodrioSubstruct_31A0 *ptr = &gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId];
                u8 var = gUnknown_082F449C[gUnknown_02022C98->unk24 - 1][gUnknown_02022C98->multiplayerId][i];

                if (ptr->unk14.unkB[var] != 10)
                    return FALSE;
            }
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_8026D1C(u8 arg0)
{
    u8 var = gUnknown_082F7A9C[gUnknown_02022C98->unk90[arg0] % 7] + (gUnknown_02022C98->unk90[arg0] / 7) * 100;
    if (gUnknown_02022C98->unk86[arg0] >= var)
        gUnknown_02022C98->unk90[arg0]++;
}

static u8 sub_8026D8C(u8 arg0)
{
    return gUnknown_082F4648[gUnknown_02022C98->unk24 - 1][arg0];
}

static u8 sub_8026DB0(u8 arg0, u8 arg1)
{
    u8 i, var3;
    u8 count = gUnknown_02022C98->unk24 - 1;
    u8 var0 = gUnknown_082F45FA[count][arg0][0];
    u8 var1 = gUnknown_082F45FA[count][arg0][1];
    u8 var2 = gUnknown_082F45FA[count][arg0][2];

    for (i = 0; gUnknown_082F467F[count][i] != 0; i++)
    {
        if (arg1 == gUnknown_082F467F[count][i])
            return sub_8026E70(gUnknown_02022C98->unk90[var1], arg1);
    }

    // Gets the highest of the three.
    if (gUnknown_02022C98->unk90[var0] > gUnknown_02022C98->unk90[var1])
        var3 = gUnknown_02022C98->unk90[var0];
    else
        var3 = gUnknown_02022C98->unk90[var1];

    if (gUnknown_02022C98->unk90[var2] > var3)
        var3 = gUnknown_02022C98->unk90[var2];

    return sub_8026E70(var3, arg1);
}

static u8 sub_8026E70(u8 arg0, u8 arg1)
{
    u8 var = gUnknown_02022C98->unkE8[arg1];
    switch (arg0 % 7)
    {
    default: return 0;
    case 0:  return 0;
    case 1:  return 1;
    case 2:  return 2;
    case 3:
        if (var == 0)
            return 1;
        else
            return 0;
    case 4:
        if (var == 0)
            return 2;
        else
            return 0;
    case 5:
        if (var == 2)
            return 1;
        else
            return 2;
    case 6:
        if (var == 0)
            return 1;
        else if (var == 1)
            return 2;
        else
            return 0;
    }
}

static bool32 sub_8026EEC(u16 arg0[5][6])
{
    int sum, i;
    for (sum = 0, i = 0; i < GetLinkPlayerCount(); sum += arg0[i][3], i++)
        ;

    if (sum >= 11)
        return TRUE;
    else
        return FALSE;
}

static void sub_8026F1C(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var;
    u8 count = gUnknown_02022C98->unk24;
    switch (arg0)
    {
    case 0:
    case 1:
    case 2:
        var = gUnknown_02022C98->unk31A0[0].unk14.unk0[arg1];
        gUnknown_02022C98->unk4A[arg2][var] = IncrementWithLimit(gUnknown_02022C98->unk4A[arg2][var], 20000);
        break;
    case 3:
        if (sub_8026EEC(gUnknown_02022C98->unk4A))
            break;
        switch (count)
        {
        case 5:
            switch (arg1)
            {
            case 0:
                gUnknown_02022C98->unk4A[2][3]++;
                gUnknown_02022C98->unk4A[3][3]++;
                break;
            case 1:
                gUnknown_02022C98->unk4A[3][3]++;
                break;
            case 2:
                gUnknown_02022C98->unk4A[3][3]++;
                gUnknown_02022C98->unk4A[4][3]++;
                break;
            case 3:
                gUnknown_02022C98->unk4A[4][3]++;
                break;
            case 4:
                gUnknown_02022C98->unk4A[4][3]++;
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 5:
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 6:
                gUnknown_02022C98->unk4A[0][3]++;
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 7:
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 8:
                gUnknown_02022C98->unk4A[1][3]++;
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            case 9:
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            }
            break;
        case 4:
            switch (arg1)
            {
            case 1:
                gUnknown_02022C98->unk4A[2][3]++;
                gUnknown_02022C98->unk4A[3][3]++;
                break;
            case 2:
                gUnknown_02022C98->unk4A[3][3]++;
                break;
            case 3:
                gUnknown_02022C98->unk4A[3][3]++;
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 4:
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 5:
                gUnknown_02022C98->unk4A[0][3]++;
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 6:
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 7:
                gUnknown_02022C98->unk4A[1][3]++;
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            case 8:
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            }
            break;
        case 3:
            switch (arg1)
            {
            case 2:
                gUnknown_02022C98->unk4A[1][3]++;
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            case 3:
                gUnknown_02022C98->unk4A[2][3]++;
                break;
            case 4:
                gUnknown_02022C98->unk4A[2][3]++;
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 5:
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 6:
                gUnknown_02022C98->unk4A[0][3]++;
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 7:
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            }
            break;
        case 2:
            switch (arg1)
            {
            case 3:
                gUnknown_02022C98->unk4A[0][3]++;
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 4:
                gUnknown_02022C98->unk4A[0][3]++;
                break;
            case 5:
                gUnknown_02022C98->unk4A[0][3]++;
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            case 6:
                gUnknown_02022C98->unk4A[1][3]++;
                break;
            }
            break;
        }
        break;
    }
}

static void sub_8027234(bool32 arg0)
{
    if (gUnknown_02022C98->unk24 != 5)
        return;

    if (arg0 == TRUE)
    {
        if (++gUnknown_02022C98->unk112 > gUnknown_02022C98->unk114)
            gUnknown_02022C98->unk114 = gUnknown_02022C98->unk112;
        if (gUnknown_02022C98->unk112 > 9999)
            gUnknown_02022C98->unk112 = 9999;
    }
    else
    {
        if (gUnknown_02022C98->unk112 > gUnknown_02022C98->unk114)
            gUnknown_02022C98->unk114 = gUnknown_02022C98->unk112;
        gUnknown_02022C98->unk112 = 0;
    }
}

static void sub_80272A4(void)
{
    u8 i;
    for (i = 0; i < gUnknown_02022C98->unk24; i++)
        gUnknown_02022C98->unk4A[i][5] = gUnknown_02022C98->unk114;
}

static void sub_80272E8(void)
{
    u8 i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 11; j++)
            gUnknown_02022C98->unk31A0[i].unk14.unkB[j] = 0;
        gUnknown_02022C98->unk31A0[i].unk2C.unk0 = 0;
        gUnknown_02022C98->unk31A0[i].unk2C.unk4 = 0;
        gUnknown_02022C98->unk90[i] = 0;
        gUnknown_02022C98->unk86[i] = 0;
        gUnknown_02022C98->unk3308[i].unk0 = 0;
        gUnknown_02022C98->unk3308[i].unk4 = 0;
        gUnknown_02022C98->unk4A[i][0] = 0;
        gUnknown_02022C98->unk4A[i][1] = 0;
        gUnknown_02022C98->unk4A[i][2] = 0;
        gUnknown_02022C98->unk4A[i][3] = 0;
        gUnknown_02022C98->unk4A[i][4] = 0;
        gUnknown_02022C98->unk4A[i][5] = 0;
    }
    gUnknown_02022C98->unk154 = 0;
    gUnknown_02022C98->unk112 = 0;
    gUnknown_02022C98->unk40 = 0;
    sub_8026A88();
    sub_8026988();
}

static const s16 gUnknown_082F7B24[] = {10, 30, 50, 50};

static void sub_80273F0(void)
{
    u8 i, var = 0, var2 = 0;

    switch (gUnknown_02022C98->unk24)
    {
    case 4:  var = 1; break;
    case 5:  var = 2; break;
    }

    var2 = Random() % 10;
    for (i = 0; i < 5; i++)
        gUnknown_02022C98->unk4A[i][4] = gUnknown_082F7AA4[var][var2];
}

static u32 sub_802745C(u8 arg0)
{
    u32 sum = gUnknown_02022C98->unk4A[arg0][0]
            + gUnknown_02022C98->unk4A[arg0][1]
            + gUnknown_02022C98->unk4A[arg0][2];
    return min(sum, 9999);
}

static void sub_802749C(void)
{
    u32 berriesPicked = Min(sub_802745C(gUnknown_02022C98->multiplayerId), 9999);
    u32 score = Min(sub_80276C0(gUnknown_02022C98->multiplayerId), 999990);

    if (gSaveBlock2Ptr->berryPick.bestScore < score)
        gSaveBlock2Ptr->berryPick.bestScore = score;
    if (gSaveBlock2Ptr->berryPick.berriesPicked < berriesPicked)
        gSaveBlock2Ptr->berryPick.berriesPicked = berriesPicked;
    if (gSaveBlock2Ptr->berryPick.berriesPickedInRow < gUnknown_02022C98->unk114)
        gSaveBlock2Ptr->berryPick.berriesPickedInRow = gUnknown_02022C98->unk114;
}

static u8 sub_8027518(u8 arg0)
{
    u8 i, saved;

    saved = gUnknown_02022C98->unk98[3];
    for (i = 3; i != 0; i--)
        gUnknown_02022C98->unk98[i] = gUnknown_02022C98->unk98[i - 1];
    gUnknown_02022C98->unk98[0] = arg0;
    return saved;
}

static void sub_8027554(void)
{
    if (gUnknown_02022C98->unkB0[gUnknown_02022C98->multiplayerId] == 0)
    {
        if (JOY_NEW(DPAD_UP))
        {
            gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 = 2;
            gUnknown_02022C98->unkB0[gUnknown_02022C98->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 = 3;
            gUnknown_02022C98->unkB0[gUnknown_02022C98->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 = 1;
            gUnknown_02022C98->unkB0[gUnknown_02022C98->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else
        {
            gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 = 0;
        }
    }
    else
    {
        gUnknown_02022C98->unkB0[gUnknown_02022C98->multiplayerId]--;
    }
}

static void sub_8027608(void)
{
    gUnknown_02022C98->unk31A0[gUnknown_02022C98->multiplayerId].unk2C.unk0 = 0;
}

static u16 sub_802762C(void)
{
    return gUnknown_02022C98->unk4A[gUnknown_02022C98->multiplayerId][4] + FIRST_BERRY_INDEX;
}

static u8 sub_8027650(void)
{
    return gUnknown_02022C98->unk24;
}

static u8 *sub_8027660(u8 id)
{
    if (gReceivedRemoteLinkPlayers)
        return gLinkPlayers[id].name;
    else
        return gUnknown_02022C98->unk31A0[id].name;
}

static u16 sub_80276A0(u8 arg0, u8 arg1)
{
    return gUnknown_02022C98->unk4A[arg0][arg1];
}

static u32 sub_80276C0(u8 arg0)
{
    u8 i;
    u32 var, sum = 0;

    for (i = 0; i < 3; i++)
        sum += gUnknown_02022C98->unk4A[arg0][i] * gUnknown_082F7B24[i];

    var = gUnknown_02022C98->unk4A[arg0][3] * gUnknown_082F7B24[3];
    if (sum <= var)
        return 0;
    else
        return sum - var;
}

static u32 sub_8027748(void)
{
    u8 i, count = gUnknown_02022C98->unk24;
    u32 maxVar = sub_80276C0(0);

    for (i = 1; i < count; i++)
    {
        u32 var = sub_80276C0(i);
        if (var > maxVar)
            maxVar = var;
    }
    return Min(maxVar, 999990);
}

static u32 sub_802778C(u8 arg0)
{
    u8 i, count = gUnknown_02022C98->unk24;
    u16 maxVar = gUnknown_02022C98->unk4A[0][arg0];

    for (i = 0; i < count; i++)
    {
        u16 var = gUnknown_02022C98->unk4A[i][arg0];
        if (var > maxVar)
            maxVar = var;
    }
    return maxVar;
}

static u32 sub_80277D0(u8 arg0)
{
    u32 vals[5], temp;
    s16 r6 = TRUE;
    u8 i, count = gUnknown_02022C98->unk24;

    for (i = 0; i < count; i++)
        vals[i] = temp = sub_80276C0(i);

    while (r6)
    {
        r6 = FALSE;
        for (i = 0; i < count - 1; i++)
        {
            if (vals[i] < vals[i + 1])
            {
                SWAP(vals[i], vals[i + 1], temp);
                r6 = TRUE;
            }
        }
    }

    return vals[arg0];
}

static u32 sub_802784C(void)
{
    u8 i, r10 = 0, r8 = 0, r9 = 0, count = gUnknown_02022C98->unk24;

    // Function called two times for some reason.
    sub_8027748();
    if (sub_8027748() == 0)
    {
        for (i = 0; i < count; i++)
        {
            gUnknown_02022C98->unk3308[i].unk0 = 4;
            gUnknown_02022C98->unk3308[i].unk4 = 0;
        }
    }

    for (i = 0; i < count; i++)
        gUnknown_02022C98->unk3308[i].unk4 = Min(sub_80276C0(i), 999990);

    do
    {
        u32 r6 = sub_80277D0(r10);
        u8 r3 = r8;
        for (i = 0; i < count; i++)
        {
            if (r6 == gUnknown_02022C98->unk3308[i].unk4)
            {
                gUnknown_02022C98->unk3308[i].unk0 = r3;
                r8++;
                r9++;
            }
        }
        r10 = r8;
    } while (r9 < count);

    return 0;
}

static void sub_802793C(struct DodrioSubstruct_3308 *dst, u8 id)
{
    *dst = gUnknown_02022C98->unk3308[id];
}

// Unused function
static u8 sub_802795C(u8 arg0)
{
    u8 i, ret = 0, count = gUnknown_02022C98->unk24;
    u32 var, vars[5] = {0};

    for (i = 0; i < count; i++)
        vars[i] = sub_80276C0(i);

    var = vars[arg0];
    for (i = 0; i < 5; i++)
    {
        if (i != arg0 && var < vars[i])
            ret++;
    }

    return ret;
}

static u8 sub_80279C8(void)
{
    u8 multiplayerId = gUnknown_02022C98->multiplayerId;
    u16 itemId = sub_802762C();

    if (sub_80276C0(multiplayerId) != sub_8027748())
        return 3;
    if (!CheckBagHasSpace(itemId, 1))
        return 2;

    AddBagItem(itemId, 1);
    if (!CheckBagHasSpace(itemId, 1))
        return 1;
    return 0;
}

// Really? What next, u32 Add(u32 a)return a+1;?
static u32 IncrementWithLimit(u32 a, u32 max)
{
    if (a < max)
        return a + 1;
    else
        return max;
}

// Gamefreak pls, min(a, b) ((a) < (b) ? (a) : (b)) is a well-known macro
static u32 Min(u32 a, u32 b)
{
    if (a < b)
        return a;
    else
        return b;
}

static u8 sub_8027A48(u8 id)
{
    return gUnknown_02022C98->unk34[id];
}

void IsDodrioInParty(void)
{
    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_HAS_SPECIES)
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_DODRIO)
        {
            gSpecialVar_Result = TRUE;
            return;
        }
    }

    gSpecialVar_Result = FALSE;
}

void ShowDodrioBerryPickingRecords(void)
{
    u8 taskId = CreateTask(Task_ShowDodrioBerryPickingRecords, 0);
    Task_ShowDodrioBerryPickingRecords(taskId);
}

// Data related to printing saved results.
static const struct WindowTemplate gUnknown_082F7B2C =
{
    .bg = 0,
    .tilemapLeft = 5,
    .tilemapTop = 1,
    .width = 20,
    .height = 11,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const u8 *const gUnknown_082F7B34[3] = {gText_BerriesPicked, gText_BestScore, gText_BerriesInRowFivePlayers};
static const u8 gUnknown_082F7B40[] = {4, 7, 4};

ALIGNED(4)
static const u8 gUnknown_082F7B44[][2] = {{25}, {41}, {57}};
static const u8 gUnknown_082F7B4A[][2] = {{25}, {41}, {73}};

static void Task_ShowDodrioBerryPickingRecords(u8 taskId)
{
    struct WindowTemplate window;
    s32 i, width, widthCurr;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        window = gUnknown_082F7B2C;
        width = GetStringWidth(1, gText_BerryPickingRecords, 0);
        for (i = 0; i < ARRAY_COUNT(gUnknown_082F7B34); i++)
        {
            widthCurr = GetStringWidth(1, gUnknown_082F7B34[i], 0) + 50;
            if (widthCurr > width)
                width = widthCurr;
        }
        width = (width + 7) / 8;
        if (width & 1)
            width++;
        window.tilemapLeft = (30 - width) / 2;
        window.width = width;
        data[1] = AddWindow(&window);
        sub_8027BEC(data[1], width);
        CopyWindowToVram(data[1], 3);
        data[0]++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            data[0]++;
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            rbox_fill_rectangle(data[1]);
            CopyWindowToVram(data[1], 1);
            data[0]++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(data[1]);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
        break;
    }
}

static void sub_8027BEC(u8 windowId, s32 width)
{
    s32 i, x, numWidth;
    s32 results[3];
    results[0] = gSaveBlock2Ptr->berryPick.berriesPicked;
    results[1] = gSaveBlock2Ptr->berryPick.bestScore;
    results[2] = gSaveBlock2Ptr->berryPick.berriesPickedInRow;

    LoadUserWindowBorderGfx_(windowId, 0x21D, 0xD0);
    DrawTextBorderOuter(windowId, 0x21D, 0xD);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 1, gText_BerryPickingRecords, GetStringCenterAlignXOffset(1, gText_BerryPickingRecords, width * 8), 1, TEXT_SPEED_FF, NULL);
    for (i = 0; i < 3; i++)
    {
        ConvertIntToDecimalStringN(gStringVar1, results[i], STR_CONV_MODE_LEFT_ALIGN, gUnknown_082F7B40[i]);
        numWidth = GetStringWidth(1, gStringVar1, -1);
        AddTextPrinterParameterized(windowId, 1, gUnknown_082F7B34[i], 0, gUnknown_082F7B44[i][0], TEXT_SPEED_FF, NULL);
        x = (width * 8) - numWidth;
        AddTextPrinterParameterized(windowId, 1, gStringVar1, x, gUnknown_082F7B4A[i][0], TEXT_SPEED_FF, NULL);
    }
    PutWindowTilemap(windowId);
}

// Debug functions?
static const u16 gUnknown_082F7B50[][4] =
{
    {9999, 0, 90, 9999},
    {9999, 9999, 70, 9999},
    {9999, 0, 9999, 0},
    {9999, 9999, 60, 0},
    {9999, 9999, 9999, 0},
};

static const u8 sJPText_Vowels[] = _("あいうえおかき");
static const u8 sText_ABCDEFG[] = _("ABCDEFG");
static const u8 sText_0123456[] = _("0123456");

static const u8 *const sPlaceholderPlayerNames[] =
{
    sJPText_Vowels,
    sJPText_Vowels,
    sJPText_Vowels,
    sText_ABCDEFG,
    sText_0123456
};

static void sub_8027D20(void)
{
    gUnknown_02022C98->unk24 = GetLinkPlayerCount();
}

static void sub_8027D38(void)
{
    u8 i, playerId;

    for (playerId = gUnknown_02022C98->unk24; playerId < ARRAY_COUNT(sPlaceholderPlayerNames); playerId++)
        StringCopy(gLinkPlayers[playerId].name, sPlaceholderPlayerNames[playerId]);

    gUnknown_02022C98->unk24 = 5;
    for (i = 0; i < 4; i++)
    {
        for (playerId = 0; playerId < gUnknown_02022C98->unk24; playerId++)
            gUnknown_02022C98->unk4A[playerId][i] = gUnknown_082F7B50[playerId][i];
    }
}

struct UnkPacket1
{
    u8 id;
    u8 ALIGNED(4) unk4;
};

static void sub_8027DD0(u32 arg0)
{
    struct UnkPacket1 packet;
    packet.id = 1;
    packet.unk4 = arg0;
    Rfu_SendPacket(&packet);
}

static u32 sub_8027DFC(u32 arg0)
{
    struct UnkPacket1 *packet;

    if ((gRecvCmds[0][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return 0;

    packet = (void *)&gRecvCmds[arg0][1];
    if (packet->id == 1)
        return packet->unk4;

    return 0;
}

struct UnkPacket2
{
    u8 id;
    u8 unk1_0:4;
    u8 unk1_1:4;
    u16 unk2_0:4;
    u16 unk2_1:4;
    u16 unk3_0:4;
    u16 unk3_1:4;
    u16 unk4_0:4;
    u16 unk4_1:4;
    u16 unk5_0:4;
    u16 unk5_1:4;
    u16 unk6_0:2;
    u16 unk6_1:2;
    u16 unk6_2:2;
    u16 unk6_3:2;
    u16 unk7_0:2;
    u16 unk7_1:2;
    u16 unk7_2:2;
    u16 unk7_3:2;
    u8 unk8_0:2;
    u8 unk8_1:2;
    u8 unk8_2:2;
    u8 unk8_3:2;
    u8 unk9_0:2;
    u8 unk9_1:2;
    u8 unk9_2:2;
    u8 unk9_3:1;
    u8 unk9_4:1;
    u8 unkA_0:1;
    u8 unkA_1:1;
    u8 unkA_2:1;
    u8 unkA_3:5;
    u8 unkB_0:1;
    u8 unkB_1:1;
    u8 unkB_2:1;
    u8 unkB_3:1;
    u8 unkB_4:1;
    u8 unkB_5:1;
    u8 unkB_6:1;
};

static void sub_8027E30(struct DodrioSubstruct_31A0 *arg0, struct DodrioSubstruct_31A0_2C *arg1, struct DodrioSubstruct_31A0_2C *arg2, struct DodrioSubstruct_31A0_2C *arg3, struct DodrioSubstruct_31A0_2C *arg4, struct DodrioSubstruct_31A0_2C *arg5, u8 arg6, u32 arg7, u32 arg8)
{
    struct UnkPacket2 packet;
    struct DodrioSubstruct_31A0_14 *ptr = &arg0->unk14;

    packet.id = 2;
    packet.unk1_0 = ptr->unkB[0];
    packet.unk1_1 = ptr->unkB[1];
    packet.unk2_0 = ptr->unkB[2];
    packet.unk2_1 = ptr->unkB[3];
    packet.unk3_0 = ptr->unkB[4];
    packet.unk3_1 = ptr->unkB[5];
    packet.unk4_0 = ptr->unkB[6];
    packet.unk4_1 = ptr->unkB[7];
    packet.unk5_0 = ptr->unkB[8];
    packet.unk5_1 = ptr->unkB[9];

    packet.unk6_0 = ptr->unk0[0];
    packet.unk6_1 = ptr->unk0[1];
    packet.unk6_2 = ptr->unk0[2];
    packet.unk6_3 = ptr->unk0[3];
    packet.unk7_0 = ptr->unk0[4];
    packet.unk7_1 = ptr->unk0[5];
    packet.unk7_2 = ptr->unk0[6];
    packet.unk7_3 = ptr->unk0[7];
    packet.unk8_0 = ptr->unk0[8];
    packet.unk8_1 = ptr->unk0[9];

    packet.unk8_2 = arg1->unk0;
    packet.unk8_3 = arg2->unk0;
    packet.unk9_0 = arg3->unk0;
    packet.unk9_1 = arg4->unk0;
    packet.unk9_2 = arg5->unk0;

    packet.unk9_3 = arg1->unk4;
    packet.unk9_4 = arg2->unk4;
    packet.unkA_0 = arg3->unk4;
    packet.unkA_1 = arg4->unk4;
    packet.unkA_2 = arg5->unk4;

    packet.unkB_2 = arg1->unk8;
    packet.unkB_3 = arg2->unk8;
    packet.unkB_4 = arg3->unk8;
    packet.unkB_5 = arg4->unk8;
    packet.unkB_6 = arg5->unk8;

    packet.unkA_3 = arg6;
    packet.unkB_1 = arg7;
    packet.unkB_0 = arg8;
    Rfu_SendPacket(&packet);
}

static u32 sub_8028164(u32 unused, struct DodrioSubstruct_31A0 *arg0, struct DodrioSubstruct_31A0_2C *arg1, struct DodrioSubstruct_31A0_2C *arg2, struct DodrioSubstruct_31A0_2C *arg3, struct DodrioSubstruct_31A0_2C *arg4, struct DodrioSubstruct_31A0_2C *arg5, u8 *arg6, u32 *arg7, u32 *arg8)
{
    struct UnkPacket2 *packet;
    struct DodrioSubstruct_31A0_14 *ptr = &arg0->unk14;

    if ((gRecvCmds[0][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return 0;

    packet = (void *)&gRecvCmds[0][1];
    if (packet->id == 2)
    {
        ptr->unkB[0] = packet->unk1_0;
        ptr->unkB[1] = packet->unk1_1;
        ptr->unkB[2] = packet->unk2_0;
        ptr->unkB[3] = packet->unk2_1;
        ptr->unkB[4] = packet->unk3_0;
        ptr->unkB[5] = packet->unk3_1;
        ptr->unkB[6] = packet->unk4_0;
        ptr->unkB[7] = packet->unk4_1;
        ptr->unkB[8] = packet->unk5_0;
        ptr->unkB[9] = packet->unk5_1;
        ptr->unkB[10] = packet->unk1_0;

        ptr->unk0[0] = packet->unk6_0;
        ptr->unk0[1] = packet->unk6_1;
        ptr->unk0[2] = packet->unk6_2;
        ptr->unk0[3] = packet->unk6_3;
        ptr->unk0[4] = packet->unk7_0;
        ptr->unk0[5] = packet->unk7_1;
        ptr->unk0[6] = packet->unk7_2;
        ptr->unk0[7] = packet->unk7_3;
        ptr->unk0[8] = packet->unk8_0;
        ptr->unk0[9] = packet->unk8_1;
        ptr->unk0[10] = packet->unk6_0;

        arg1->unk0 = packet->unk8_2;
        arg1->unk4 = packet->unk9_3;
        arg1->unk8 = packet->unkB_2;

        arg2->unk0 = packet->unk8_3;
        arg2->unk4 = packet->unk9_4;
        arg2->unk8 = packet->unkB_3;

        arg3->unk0 = packet->unk9_0;
        arg3->unk4 = packet->unkA_0;
        arg3->unk8 = packet->unkB_4;

        arg4->unk0 = packet->unk9_1;
        arg4->unk4 = packet->unkA_1;
        arg4->unk8 = packet->unkB_5;

        arg5->unk0 = packet->unk9_2;
        arg5->unk4 = packet->unkA_2;
        arg5->unk8 = packet->unkB_6;

        *arg6 = packet->unkA_3;
        *arg7 = packet->unkB_1;
        *arg8 = packet->unkB_0;
        return 1;
    }

    return 0;
}

struct UnkPacket3
{
    u8 id;
    u8 ALIGNED(4) unk4;
};

static void sub_80282EC(u8 arg0)
{
    struct UnkPacket3 packet;
    packet.id = 3;
    packet.unk4 = arg0;
    Rfu_SendPacket(&packet);
}

static u32 sub_8028318(u32 arg0, u8 *arg1)
{
    struct UnkPacket3 *packet;

    if ((gRecvCmds[0][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return 0;

    packet = (void *)&gRecvCmds[arg0][1];
    if (packet->id == 3)
    {
        *arg1 = packet->unk4;
        return 1;
    }

    return 0;
}

struct UnkPacket4
{
    u8 id;
    u32 unk4;
};

static void sub_8028350(u32 arg0)
{
    struct UnkPacket4 packet;
    packet.id = 4;
    packet.unk4 = arg0;
    Rfu_SendPacket(&packet);
}

static u32 sub_8028374(u32 arg0)
{
    struct UnkPacket4 *packet;

    if ((gRecvCmds[0][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return 0;

    packet = (void *)&gRecvCmds[arg0][1];
    if (packet->id == 4)
        return packet->unk4;

    return 0;
}

// Large chunk of data
static const struct BgTemplate gUnknown_082F7BA4[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

// Unknown unreferenced data, feel free to remove.
static const u32 sUnused[] = {255, 0};

static const struct WindowTemplate gUnknown_082F7BBC[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 0x13,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 5,
        .width = 28,
        .height = 14,
        .paletteNum = 13,
        .baseBlock = 0x4B,
    }
};
static const struct WindowTemplate gUnknown_082F7BCC =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 7,
    .paletteNum = 13,
    .baseBlock = 0x4B,
};
static const struct WindowTemplate gUnknown_082F7BD4[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 0x13,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 7,
        .width = 6,
        .height = 4,
        .paletteNum = 13,
        .baseBlock = 0x4C,
    }
};
static const struct WindowTemplate gUnknown_082F7BE4 =
{
    .bg = 0,
    .tilemapLeft = 4,
    .tilemapTop = 6,
    .width = 22,
    .height = 5,
    .paletteNum = 13,
    .baseBlock = 0x13,
};
static const struct WindowTemplate gUnknown_082F7BEC =
{
    .bg = 0,
    .tilemapLeft = 5,
    .tilemapTop = 8,
    .width = 19,
    .height = 3,
    .paletteNum = 13,
    .baseBlock = 0x13,
};

// This is an unused copy of the tables from the top of the file. Feel free to remove.
static const u8 sDuplicateArray[] =
{
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 3, 8, 9, 0, 0, 1, 2, 5, 6, 3, 4, 5, 8, 9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 2, 9,
    0, 0, 1, 4, 5, 6, 7, 2, 3, 4, 9, 0, 0, 1, 6, 7, 2, 3, 4, 5, 6, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 0, 0, 3, 4, 5, 6, 7, 8, 1, 2, 3, 0, 0, 5, 6, 7, 8, 1, 2, 3, 4, 5, 0, 0, 7,
    8, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 4, 5, 6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 5, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 6, 7, 2, 2, 3, 4, 0, 0, 0, 0, 0, 0,
    3, 4, 5, 5, 6, 7, 7, 8, 1, 1, 2, 3, 0, 0, 0, 4, 5, 6, 6, 7, 8, 8, 9, 0, 0, 1, 2, 2, 3, 4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 1,
    2, 1, 2, 3, 2, 3, 0, 0, 0, 0, 4, 0, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 0, 0, 0, 0, 9, 9, 9, 9, 1, 1, 1, 9, 9, 9, 9, 9,
    9, 9, 0, 0, 1, 1, 0, 9, 9, 9, 9, 9, 2, 2, 0, 0, 1, 1, 1, 9, 9, 9, 3, 3, 0, 0, 1, 1, 2, 2, 3, 9, 3, 3, 4, 4, 0, 0, 1, 1,
    2, 2, 3, 5, 0, 0, 0, 0, 4, 6, 0, 0, 0, 3, 5, 7, 0, 0, 2, 4, 6, 8, 0, 1, 3, 5, 6, 9
};

static const u16 gDodrioBerryBgPal1[] = INCBIN_U16("graphics/link_games/dodrioberry_bg1.gbapal",
                                            "graphics/link_games/dodrioberry_bg2.gbapal");
static const u16 gDodrioBerryPkmnPal[] = INCBIN_U16("graphics/link_games/dodrioberry_pkmn.gbapal");
static const u16 gDodrioBerryShinyPal[] = INCBIN_U16("graphics/link_games/dodrioberry_shiny.gbapal");
static const u16 gDodrioBerryStatusPal[] = INCBIN_U16("graphics/link_games/dodrioberry_status.gbapal");
static const u16 gDodrioBerrySpritesPal[] = INCBIN_U16("graphics/link_games/dodrioberry_berrysprites.gbapal");
static const u32 gDodrioBerrySpritesGfx[] = INCBIN_U32("graphics/link_games/dodrioberry_berrysprites.4bpp.lz");
static const u16 gDodrioBerryPlatformPal[] = INCBIN_U16("graphics/link_games/dodrioberry_platform.gbapal");
static const u32 gDodrioBerryBgGfx1[] = INCBIN_U32("graphics/link_games/dodrioberry_bg1.4bpp.lz");
static const u32 gDodrioBerryBgGfx2[] = INCBIN_U32("graphics/link_games/dodrioberry_bg2.4bpp.lz");
static const u32 gDodrioBerryStatusGfx[] = INCBIN_U32("graphics/link_games/dodrioberry_status.4bpp.lz");
static const u32 gDodrioBerryPlatformGfx[] = INCBIN_U32("graphics/link_games/dodrioberry_platform.4bpp.lz");
static const u32 gDodrioBerryPkmnGfx[] = INCBIN_U32("graphics/link_games/dodrioberry_pkmn.4bpp.lz");
static const u32 gDodrioBerryBgTilemap1[] = INCBIN_U32("graphics/link_games/dodrioberry_bg1.bin.lz");
static const u32 gDodrioBerryBgTilemap2Right[] = INCBIN_U32("graphics/link_games/dodrioberry_bg2right.bin.lz");
static const u32 gDodrioBerryBgTilemap2Left[] = INCBIN_U32("graphics/link_games/dodrioberry_bg2left.bin.lz");

static const struct OamData sOamData_82FB1E0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_82FB1E8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_82FB1F0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_82FB1F8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_82FB200[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB208[] =
{
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB210[] =
{
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB218[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB220[] =
{
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_82FB228[] =
{
    sSpriteAnim_82FB200,
    sSpriteAnim_82FB208,
    sSpriteAnim_82FB210,
    sSpriteAnim_82FB218,
    sSpriteAnim_82FB220
};

static const union AnimCmd sSpriteAnim_82FB23C[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB244[] =
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB24C[] =
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_82FB254[] =
{
    sSpriteAnim_82FB23C,
    sSpriteAnim_82FB244,
    sSpriteAnim_82FB24C
};

static const union AnimCmd sSpriteAnim_82FB260[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB268[] =
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB270[] =
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB278[] =
{
    ANIMCMD_FRAME(12, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB280[] =
{
    ANIMCMD_FRAME(16, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB288[] =
{
    ANIMCMD_FRAME(20, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB290[] =
{
    ANIMCMD_FRAME(24, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB298[] =
{
    ANIMCMD_FRAME(28, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_82FB2A0[] =
{
    ANIMCMD_FRAME(32, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_82FB2A8[] =
{
    sSpriteAnim_82FB260,
    sSpriteAnim_82FB268,
    sSpriteAnim_82FB270,
    sSpriteAnim_82FB278,
    sSpriteAnim_82FB280,
    sSpriteAnim_82FB288,
    sSpriteAnim_82FB290,
    sSpriteAnim_82FB298,
    sSpriteAnim_82FB2A0
};

static const union AnimCmd sSpriteAnim_82FB2CC[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_82FB2D4[] =
{
    sSpriteAnim_82FB2CC
};

static void sub_80283A8(void)
{
    void *ptr = AllocZeroed(0x3000);
    struct SpritePalette pal1 = {gDodrioBerryPkmnPal, 0};
    struct SpritePalette pal2 = {gDodrioBerryShinyPal, 1};

    LZ77UnCompWram(gDodrioBerryPkmnGfx, ptr);
    // This check should be one line up.
    if (ptr != NULL)
    {
        struct SpriteSheet sheet = {ptr, 0x3000, 0};
        LoadSpriteSheet(&sheet);
        Free(ptr);
    }
    LoadSpritePalette(&pal1);
    LoadSpritePalette(&pal2);
}

static void sub_8028408(struct DodrioSubstruct_318C *arg0, u8 arg1, u8 id, u8 arg3)
{
    struct SpriteTemplate sprTemplate =
    {
        .tileTag = 0,
        .paletteTag = arg0->isShiny,
        .oam = &sOamData_82FB1E0,
        .anims = sSpriteAnimTable_82FB228,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80284A8,
    };

    gUnknown_02022C9C[id] = AllocZeroed(4);
    *gUnknown_02022C9C[id] = CreateSprite(&sprTemplate, sub_8028F14(arg1, arg3), 136, 3);
    sub_8028654(TRUE, id);
}

static void sub_80284A8(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        break;
    case 1:
        sub_802853C(sprite);
        break;
    case 2:
        sub_80285AC(sprite);
        break;
    }
}

static void sub_80284CC(u8 unused)
{
    struct Sprite *sprite = &gSprites[*gUnknown_02022C9C[GetMultiplayerId()]];
    sprite->data[0] = 1;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
}

static void sub_8028504(u8 unused)
{
    struct Sprite *sprite = &gSprites[*gUnknown_02022C9C[GetMultiplayerId()]];
    sprite->data[0] = 2;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
}

static u32 sub_802853C(struct Sprite *sprite)
{
    s8 var;
    u8 mod = (++sprite->data[1] / 2) % 4;

    if (sprite->data[1] >= 3)
    {
        switch (mod)
        {
        default:
            var = 1;
            break;
        case 1:
        case 2:
            var = -1;
            break;
        }

        sprite->pos1.x += var;
        if (++sprite->data[1] >= 40)
        {
            sprite->data[0] = 0;
            sprite->pos1.x = sub_8028F14(0, sub_8027650());
        }
    }

    return 0;
}

static u32 sub_80285AC(struct Sprite *sprite)
{
    u8 mod = (++sprite->data[1] / 13) % 4;

    if (sprite->data[1] % 13 == 0 && mod != 0)
        PlaySE(SE_M_CHARM);
    if (sprite->data[1] >= 104)
    {
        sprite->data[0] = 0;
        mod = 0;
    }
    sub_80286B4(GetMultiplayerId(), mod);
    return 0;
}

static void sub_8028614(u8 count)
{
    u8 i;
    for (i = 0; i < count; i++)
    {
        struct Sprite *sprite = &gSprites[*gUnknown_02022C9C[i]];
        if (sprite != NULL)
            DestroySpriteAndFreeResources(sprite);
        // Memory should be freed here but is not.
    }
}

static void sub_8028654(bool8 invisible, u8 id)
{
    gSprites[*gUnknown_02022C9C[id]].invisible = invisible;
}

static void sub_802868C(bool8 invisible, u8 count)
{
    u8 i;
    for (i = 0; i < count; i++)
        sub_8028654(invisible, i);
}

static void sub_80286B4(u8 id, u8 frameNum)
{
    StartSpriteAnim(&gSprites[*gUnknown_02022C9C[id]], frameNum);
}

static void nullsub_15(struct Sprite *sprite)
{

}

static void sub_80286E4(void)
{
    u8 i;
    for (i = 0; i < 10; i++)
    {
        struct Sprite *sprite = &gSprites[gUnknown_02022CF4->unk2A[i]];
        sprite->pos1.x = (i * 16) + 48;
        sprite->pos1.y = -8 - (i * 8);
        gUnknown_02022CF4->unkC[i] = 0;
    }
}

static void sub_8028734(void)
{
    u8 i;
    void *ptr = AllocZeroed(0x180);
    struct SpritePalette spPal = {gDodrioBerryStatusPal, 2};

    LZ77UnCompWram(gDodrioBerryStatusGfx, ptr);
    // This check should be one line up.
    if (ptr != NULL)
    {
        struct SpriteSheet spSheet = {ptr, 0x180, 1};
        struct SpriteTemplate spTemplate =
        {
            .tileTag = 1,
            .paletteTag = 2,
            .oam = &sOamData_82FB1E8,
            .anims = sSpriteAnimTable_82FB254,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = nullsub_15,
        };

        gUnknown_02022CF4 = AllocZeroed(sizeof(*gUnknown_02022CF4));
        LoadSpriteSheet(&spSheet);
        LoadSpritePalette(&spPal);
        for (i = 0; i < 10; i++)
            gUnknown_02022CF4->unk2A[i] = CreateSprite(&spTemplate, (i * 16) + 48, -8 - (i * 8), 0);
    }

    Free(ptr);
}

static void sub_80287E4(void)
{
    u8 i;
    for (i = 0; i < 10; i++)
    {
        struct Sprite *sprite = &gSprites[gUnknown_02022CF4->unk2A[i]];
        if (sprite != NULL)
            DestroySpriteAndFreeResources(sprite);
    }
    FREE_AND_SET_NULL(gUnknown_02022CF4);
}

static bool32 sub_8028828(void)
{
    u8 i;
    bool32 r3 = FALSE;
    for (i = 0; i < 10; i++)
    {
        struct Sprite *sprite = &gSprites[gUnknown_02022CF4->unk2A[i]];
        gUnknown_02022CF4->unk16[i] = 2;
        if (gUnknown_02022CF4->unkC[i] != 0 && sprite->pos1.y == 8)
            continue;
        r3 = TRUE;
        if (sprite->pos1.y == 8)
        {
            if (gUnknown_02022CF4->unkC[i] != 0)
                continue;
            gUnknown_02022CF4->unkC[i] = 1;
            gUnknown_02022CF4->unk16[i] = -16;
            PlaySE(SE_CLICK);
        }
        sprite->pos1.y += gUnknown_02022CF4->unk16[i];
    }

    if (r3)
        return FALSE;
    else
        return TRUE;
}

static void sub_80288D4(u8 arg0)
{
    u8 i;

    if (arg0 > 10)
    {
        for (i = 0; i < 10; i++)
            StartSpriteAnim(&gSprites[gUnknown_02022CF4->unk2A[i]], 1);
    }
    else
    {
        for (i = 0; i < 10 - arg0; i++)
        {
            if (arg0 > 6)
            {
                gUnknown_02022CF4->unk3E += arg0 - 6;
                if (gUnknown_02022CF4->unk3E > 30)
                    gUnknown_02022CF4->unk3E = 0;
                else if (gUnknown_02022CF4->unk3E > 10)
                    StartSpriteAnim(&gSprites[gUnknown_02022CF4->unk2A[i]], 2);
                else
                    StartSpriteAnim(&gSprites[gUnknown_02022CF4->unk2A[i]], 0);
            }
            else
            {
                StartSpriteAnim(&gSprites[gUnknown_02022CF4->unk2A[i]], 0);
            }
        }
        for (; i < 10; i++)
            StartSpriteAnim(&gSprites[gUnknown_02022CF4->unk2A[i]], 1);
    }
}

static void sub_80289E8(bool8 invisible)
{
    u8 i;
    for (i = 0; i < 10; i++)
        gSprites[gUnknown_02022CF4->unk2A[i]].invisible = invisible;
}

// Unknown unused data, feel free to remove.
static const u8 sUnused2[] = {0xD4, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0xFB, 0x0, 0x0};

static void sub_8028A34(void)
{
    void *ptr = AllocZeroed(0x480);
    struct SpritePalette sprPal = {gDodrioBerrySpritesPal, 3};

    LZ77UnCompWram(gDodrioBerrySpritesGfx, ptr);
    if (ptr != NULL)
    {
        struct SpriteSheet sprSheet = {ptr, 0x480, 2};
        LoadSpriteSheet(&sprSheet);
    }

    LoadSpritePalette(&sprPal);
    Free(ptr);
}

static const s16 gUnknown_082FB31C[] = {88, 128, 168, 208};

static void sub_8028A88(void)
{
    u8 i;
    s16 x;

    struct SpriteTemplate sprTemplate1 =
    {
        .tileTag = 2,
        .paletteTag = 3,
        .oam = &sOamData_82FB1F0,
        .anims = sSpriteAnimTable_82FB2A8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };
    struct SpriteTemplate sprTemplate2 =
    {
        .tileTag = 2,
        .paletteTag = 3,
        .oam = &sOamData_82FB1E8,
        .anims = sSpriteAnimTable_82FB2A8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    for (i = 0; i < 11; i++)
    {
        gUnknown_02022CB8[i] = AllocZeroed(4);
        x = i * 16;
        *gUnknown_02022CB8[i] = CreateSprite(&sprTemplate1, x + (i * 8), 8, 1);
        sub_8028BF8(i, TRUE);
    }
    for (i = 0; i < 4; i++)
    {
        gUnknown_02022CE4[i] = AllocZeroed(4);
        if (i == 3)
            *gUnknown_02022CE4[i] = CreateSprite(&sprTemplate2, gUnknown_082FB31C[i], 49, 0);
        else
            *gUnknown_02022CE4[i] = CreateSprite(&sprTemplate2, gUnknown_082FB31C[i], 52, 0);
        StartSpriteAnim(&gSprites[*gUnknown_02022CE4[i]], i);
    }

    sub_8028C30(TRUE);
}

static void sub_8028B80(void)
{
    struct Sprite *sprite;
    u8 i;

    for (i = 0; i < 11; i++)
    {
        sprite = &gSprites[*gUnknown_02022CB8[i]];
        if (sprite != NULL)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(gUnknown_02022CB8[i]);
    }
    for (i = 0; i < 4; i++)
    {
        sprite = &gSprites[*gUnknown_02022CE4[i]];
        if (sprite != NULL)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(gUnknown_02022CE4[i]);
    }
}

static void sub_8028BF8(u8 id, bool8 invisible)
{
    gSprites[*gUnknown_02022CB8[id]].invisible = invisible;
}

static void sub_8028C30(bool8 invisible)
{
    u8 i;
    for (i = 0; i < 4; i++)
        gSprites[*gUnknown_02022CE4[i]].invisible = invisible;
}

static void sub_8028C7C(u8 id, u8 y)
{
    gSprites[*gUnknown_02022CB8[id]].pos1.y = y * 8;
}

static void sub_8028CA4(u16 id, u8 frameNum)
{
    StartSpriteAnim(&gSprites[*gUnknown_02022CB8[id]], frameNum);
}

// Unused
static void sub_8028CD0(u8 spriteId)
{
    gSprites[spriteId].pos1.x = 20 * spriteId + 50;
    gSprites[spriteId].pos1.y = 50;
}

// Gamefreak made a mistake there and goes out of bounds for the data array as it holds 8 elements
// in turn overwriting sprite's subpriority and subsprites fields.
#if defined(NONMATCHING) || MODERN
    #define sKeepPosX data[1]
#else
    #define sKeepPosX data[10]
#endif // NONMATCHING

static void sub_8028CF4(struct Sprite *sprite)
{
    u8 i;
    static const u8 array[] = {30, 20};

    if (sprite->sKeepPosX != TRUE)
    {
        for (i = 0; i < 2; i++)
        {
            if (++gUnknown_02022CB0[i][1] > array[i])
            {
                sprite->pos1.x--;
                gUnknown_02022CB0[i][1] = 0;
            }
        }
    }
}

static const s16 gUnknown_082FB356[][2] = {{230, 55}, {30, 74}};

static void sub_8028D44(void)
{
    u8 i;
    void *ptr = AllocZeroed(0x400);
    struct SpritePalette sprPal = {gDodrioBerryPlatformPal, 6};

    LZ77UnCompWram(gDodrioBerryPlatformGfx, ptr);
    if (ptr != NULL)
    {
        struct SpriteSheet sprSheet = {ptr, 0x400, 5};
        struct SpriteTemplate sprTemplate =
        {
            .tileTag = 5,
            .paletteTag = 6,
            .oam = &sOamData_82FB1F8,
            .anims = sSpriteAnimTable_82FB2D4,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = sub_8028CF4,
        };

        LoadSpriteSheet(&sprSheet);
        LoadSpritePalette(&sprPal);
        for (i = 0; i < 2; i++)
        {
            gUnknown_02022CB0[i] = AllocZeroed(4);
            *gUnknown_02022CB0[i] = CreateSprite(&sprTemplate, gUnknown_082FB356[i][0], gUnknown_082FB356[i][1], 4);
        }
    }

    Free(ptr);
}

static void sub_8028DFC(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        struct Sprite *sprite = &gSprites[*gUnknown_02022CB0[i]];
        sprite->sKeepPosX = TRUE;
        sprite->pos1.x = gUnknown_082FB356[i][0];
        sprite->pos1.y = gUnknown_082FB356[i][1];
    }
}

static void sub_8028E4C(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        struct Sprite *sprite = &gSprites[*gUnknown_02022CB0[i]];
        sprite->sKeepPosX = FALSE;
    }
}

static void sub_8028E84(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        struct Sprite *sprite = &gSprites[*gUnknown_02022CB0[i]];
        if (sprite)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(gUnknown_02022CB0[i]);
    }
}

static void sub_8028EC8(bool8 invisible)
{
    u8 i;
    for (i = 0; i < 2; i++)
        gSprites[*gUnknown_02022CB0[i]].invisible = invisible;
}

#undef sKeepPosX

static s16 sub_8028F14(u8 arg0, u8 arg1)
{
    s16 x = 0;
    switch (arg1)
    {
    case 1:
        x = 15;
        break;
    case 2:
        switch (arg0)
        {
            case 0: x = 12; break;
            case 1: x = 18; break;
        }
        break;
    case 3:
        switch (arg0)
        {
            case 0: x = 15; break;
            case 1: x = 21; break;
            case 2: x =  9; break;
        }
        break;
    case 4:
        switch (arg0)
        {
            case 0: x = 12; break;
            case 1: x = 18; break;
            case 2: x = 24; break;
            case 3: x =  6; break;
        }
        break;
    case 5:
        switch (arg0)
        {
            case 0: x = 15; break;
            case 1: x = 21; break;
            case 2: x = 27; break;
            case 3: x =  3; break;
            case 4: x =  9; break;
        }
        break;
    }

    return x * 8;
}

static void sub_8028FCC(void)
{
    u8 i;
    for (i = 0; i < 11; i++)
    {
        sub_8028BF8(i, TRUE);
        sub_8028C7C(i, 1);
    }
    sub_80289E8(FALSE);
}

static void sub_8028FF8(u8 frameId)
{
    LoadBgTiles(0, GetWindowFrameTilesPal(frameId)->tiles, 0x120, 1);
    LoadPalette(GetWindowFrameTilesPal(frameId)->pal, 0xA0, 0x20);
}

static void sub_802902C(void)
{
    LoadUserWindowBorderGfx_(0, 0xA, 0xB0);
}

static void sub_802903C(void)
{
    gUnknown_02022CF8->finished = FALSE;
    gUnknown_02022CF8->state = 0;
    gUnknown_02022CF8->unk3018 = 0;
    gUnknown_02022CF8->unk3020 = 0;
    gUnknown_02022CF8->unk3024 = 0;
}

static void sub_8029074(const struct WindowTemplate *winTempl)
{
    u8 pal = 0xA;

    FillBgTilemapBufferRect(0, 1, winTempl->tilemapLeft - 1,                winTempl->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 2, winTempl->tilemapLeft,                    winTempl->tilemapTop - 1,                   winTempl->width, 1, pal);
    FillBgTilemapBufferRect(0, 3, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 4, winTempl->tilemapLeft - 1,                winTempl->tilemapTop, 1,                    winTempl->height, pal);
    FillBgTilemapBufferRect(0, 6, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop, 1,                    winTempl->height, pal);
    FillBgTilemapBufferRect(0, 7, winTempl->tilemapLeft - 1,                winTempl->tilemapTop + winTempl->height,    1, 1, pal);
    FillBgTilemapBufferRect(0, 8, winTempl->tilemapLeft,                    winTempl->tilemapTop + winTempl->height,    winTempl->width, 1, pal);
    FillBgTilemapBufferRect(0, 9, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop + winTempl->height,    1, 1, pal);
}

static void sub_8029174(const struct WindowTemplate *winTempl)
{
    u8 pal = 0xB;

    FillBgTilemapBufferRect(0, 10, winTempl->tilemapLeft - 1,                winTempl->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 11, winTempl->tilemapLeft,                    winTempl->tilemapTop - 1,                   winTempl->width, 1, pal);
    FillBgTilemapBufferRect(0, 12, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 13, winTempl->tilemapLeft - 1,                winTempl->tilemapTop, 1,                    winTempl->height, pal);
    FillBgTilemapBufferRect(0, 15, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop, 1,                    winTempl->height, pal);
    FillBgTilemapBufferRect(0, 16, winTempl->tilemapLeft - 1,                winTempl->tilemapTop + winTempl->height,    1, 1, pal);
    FillBgTilemapBufferRect(0, 17, winTempl->tilemapLeft,                    winTempl->tilemapTop + winTempl->height,    winTempl->width, 1, pal);
    FillBgTilemapBufferRect(0, 18, winTempl->tilemapLeft + winTempl->width,  winTempl->tilemapTop + winTempl->height,    1, 1, pal);
}

static void sub_8029274(struct DodrioSubstruct_0160 *ptr)
{
    gUnknown_02022CF8 = ptr;
    gUnknown_02022CF8->finished = FALSE;
    gUnknown_02022CF8->state = 0;
    gUnknown_02022CF8->unk3018 = 0;
    gUnknown_02022CF8->unk3020 = 0;
    gUnknown_02022CF8->unk3024 = 0;
    gUnknown_02022CF8->unk3004 = CreateTask(sub_8029314, 3);
    sub_802A72C(sub_8029338);
}

static void sub_80292D4(void)
{
    FreeAllWindowBuffers();
}

// Data used by functions below.
struct WinCoords
{
    u8 left;
    u8 top;
};

static const u8 sTextColorTable[][3] =
{
    {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
    {TEXT_COLOR_WHITE, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED},
    {TEXT_COLOR_WHITE, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_BLUE},
    {TEXT_COLOR_WHITE, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GREEN},
};

static const struct WinCoords gUnknown_082FB38C[] = {{12, 6}};
static const struct WinCoords gUnknown_082FB390[] = {{9, 10}, {15, 6}};
static const struct WinCoords gUnknown_082FB398[] = {{12, 6}, {18, 10}, {6, 10}};
static const struct WinCoords gUnknown_082FB3A4[] = {{9, 10}, {15, 6}, {21, 10}, {3, 6}};
static const struct WinCoords gUnknown_082FB3B4[] = {{12, 6}, {18, 10}, {23, 6}, {1, 6}, {6, 10}};

static const struct WinCoords *const gUnknown_082FB3C8[] =
{
    gUnknown_082FB38C,
    gUnknown_082FB390,
    gUnknown_082FB398,
    gUnknown_082FB3A4,
    gUnknown_082FB3B4,
};

static const u8 *const gUnknown_082FB3DC[] =
{
    gText_1Colon,
    gText_2Colon,
    gText_3Colon,
    gText_4Colon,
    gText_5Colon,
};

static const u16 gUnknown_082FB3F0[] = {92, 132, 172, 212};
static const u16 gUnknown_082FB3F8[] = {33, 49, 65, 81, 97};
static const u16 gUnknown_082FB402[] = {17, 33, 49, 65, 81};

struct
{
    u8 id;
    void (*func)(void);
} const gUnknown_082FB40C[] =
{
    {0, sub_8029338},
    {1, sub_8029440},
    {2, sub_802988C},
    {3, sub_802A010},
    {4, sub_802A380},
    {5, sub_802A454},
    {6, sub_802A534},
    {7, sub_802A588},
    {8, sub_802A6FC},
    {9, nullsub_16},
};

static void sub_80292E0(u8 arg0)
{
    u8 i;
    for (i = 0; i < 10; i++)
    {
        if (gUnknown_082FB40C[i].id == arg0)
            sub_802A72C(gUnknown_082FB40C[i].func);
    }
}

static void sub_8029314(u8 taskId)
{
    if (!gUnknown_02022CF8->finished)
        sub_802A75C()();
}

static void sub_8029338(void)
{
    switch (gUnknown_02022CF8->state)
    {
    case 0:
        sub_802A7A8();
        gUnknown_02022CF8->state++;
        break;
    case 1:
        if (sub_802A8E8() == TRUE)
            gUnknown_02022CF8->state++;
        break;
    case 2:
        CopyToBgTilemapBuffer(3, gDodrioBerryBgTilemap1, 0, 0);
        CopyToBgTilemapBuffer(1, gDodrioBerryBgTilemap2Left, 0, 0);
        CopyToBgTilemapBuffer(2, gDodrioBerryBgTilemap2Right, 0, 0);
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        gUnknown_02022CF8->state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        ShowBg(1);
        ShowBg(2);
        gUnknown_02022CF8->state++;
        break;
    case 4:
        sub_8028FF8(gSaveBlock2Ptr->optionsWindowFrameType);
        sub_802902C();
        gUnknown_02022CF8->state++;
        break;
    default:
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_8029440(void)
{
    u8 i, playersCount, id, colorsId, *name;
    u32 left;
    struct WindowTemplate window;
    const struct WinCoords *ptr;

    switch (gUnknown_02022CF8->state)
    {
    case 0:
        playersCount = sub_8027650();
        ptr = gUnknown_082FB3C8[playersCount - 1];
        window.bg = 0;
        window.width = 7;
        window.height = 2;
        window.paletteNum = 0xD;
        window.baseBlock = 0x13;
        for (i = 0; i < playersCount; ptr++, i++)
        {
            colorsId = 0;
            id = sub_8027A48(i);
            left = (56 - GetStringWidth(1, sub_8027660(id), -1)) / 2u;
            window.tilemapLeft = ptr->left;
            window.tilemapTop = ptr->top;
            gUnknown_02022CF8->unk3008[i] = AddWindow(&window);
            ClearWindowTilemap(gUnknown_02022CF8->unk3008[i]);
            FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[i], PIXEL_FILL(1));
            if (id == GetMultiplayerId())
                colorsId = 2;
            name = sub_8027660(id);
            AddTextPrinterParameterized3(gUnknown_02022CF8->unk3008[i], 1, left, 1, sTextColorTable[colorsId], -1, name);
            CopyWindowToVram(gUnknown_02022CF8->unk3008[i], 2);
            window.baseBlock += 0xE;
            sub_8029174(&window);
        }
        gUnknown_02022CF8->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            playersCount = sub_8027650();
            for (i = 0; i < playersCount; i++)
                PutWindowTilemap(gUnknown_02022CF8->unk3008[i]);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022CF8->state++;
        }
        break;
    default:
        if (++gUnknown_02022CF8->state > 180)
        {
            playersCount = sub_8027650();
            for (i = 0; i < playersCount; i++)
            {
                ClearWindowTilemap(gUnknown_02022CF8->unk3008[i]);
                RemoveWindow(gUnknown_02022CF8->unk3008[i]);
            }
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022CF8->finished = TRUE;
        }
        break;
    }
}

static void sub_80296A8(u8 playersCount_)
{
    u8 i, r8 = 0, r6 = 0;
    u8 playersCount = playersCount_; // Pointless variable, I know, but it's needed to match.
    u8 *name;
    u32 x, numWidth;
    u8 numString[32];
    u8 array[5] = {0, 1, 2, 3, 4};
    struct DodrioSubstruct_3308 temp, structArray[5];

    for (i = 0; i < playersCount; i++)
    {
        array[i] = i;
        sub_802793C(&temp, i);
        structArray[i] = temp;
    }

    if (sub_8027748() != 0)
    {
        do
        {
            for (i = 0; i < playersCount; i++)
            {
                if (structArray[i].unk0 == r8)
                {
                    array[r6] = i;
                    r6++;
                }
            }
            r8 = r6;
        } while (r6 < playersCount);
    }

    for (i = 0; i < playersCount; i++)
    {
        if (structArray[i].unk4 == 0)
            structArray[i].unk0 = playersCount - 1;
    }

    x = 216 - GetStringWidth(1, gText_SpacePoints, 0);
    for (i = 0; i < playersCount; i++)
    {
        u8 colorsId = 0;
        u8 id = array[i];
        u32 points = structArray[id].unk4;

        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gUnknown_082FB3DC[structArray[id].unk0], 8, gUnknown_082FB402[i], -1, NULL);
        if (id == GetMultiplayerId())
            colorsId = 2;
        name = sub_8027660(id);
        AddTextPrinterParameterized3(gUnknown_02022CF8->unk3008[1], 1, 28, gUnknown_082FB402[i], sTextColorTable[colorsId], -1, name);
        ConvertIntToDecimalStringN(numString, points, STR_CONV_MODE_LEFT_ALIGN, 7);
        numWidth = GetStringWidth(1, numString, -1);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, numString, x - numWidth, gUnknown_082FB402[i], -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_SpacePoints, x, gUnknown_082FB402[i], -1, NULL);
    }
}

static void sub_802988C(void)
{
    u8 i, j, itemGiveRet, playersCount = sub_8027650();
    u8 *name;
    u32 strWidth, x;

    switch (gUnknown_02022CF8->state)
    {
    case 0:
        sub_802784C();
        gUnknown_02022CF8->unk301C = 0;
        gUnknown_02022CF8->state++;
        break;
    case 1:
        gUnknown_02022CF8->unk3008[0] = AddWindow(&gUnknown_082F7BBC[0]);
        gUnknown_02022CF8->unk3008[1] = AddWindow(&gUnknown_082F7BBC[1]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        sub_8029174(&gUnknown_082F7BBC[0]);
        sub_8029174(&gUnknown_082F7BBC[1]);
        gUnknown_02022CF8->state++;
        break;
    case 2:
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[1], PIXEL_FILL(1));
        strWidth = GetStringWidth(1, gText_BerryPickingResults, -1);
        x = (224 - strWidth) / 2;
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_BerryPickingResults, x, 1, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_10P30P50P50P, 68, 17, -1, NULL);
        for (i = 0; i < playersCount; i++)
        {
            u8 colorsId = 0;
            if (i == GetMultiplayerId())
                colorsId = 2;

            name = sub_8027660(i);
            AddTextPrinterParameterized3(gUnknown_02022CF8->unk3008[1], 1, 0, gUnknown_082FB3F8[i], sTextColorTable[colorsId], -1, name);
            for (j = 0; j < 4; j++)
            {
                u32 width;
                u16 result1 = Min(sub_80276A0(i, j), 9999);
                u16 result2 = Min(sub_802778C(j), 9999);

                ConvertIntToDecimalStringN(gStringVar4, result1, STR_CONV_MODE_LEFT_ALIGN, 4);
                width = GetStringWidth(1, gStringVar4, -1);
                if (result2 == result1 && result2 != 0)
                    AddTextPrinterParameterized3(gUnknown_02022CF8->unk3008[1], 1, gUnknown_082FB3F0[j] - width, gUnknown_082FB3F8[i], sTextColorTable[1], -1, gStringVar4);
                else
                    AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gStringVar4, gUnknown_082FB3F0[j] - width, gUnknown_082FB3F8[i], -1, NULL);
            }
        }
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[1], 2);
        gUnknown_02022CF8->state++;
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
            PutWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        }
        CopyBgTilemapBufferToVram(0);
        sub_8028C30(FALSE);
        gUnknown_02022CF8->state++;
        break;
    case 4:
        if (++gUnknown_02022CF8->unk301C >= 30 && JOY_NEW(A_BUTTON))
        {
            gUnknown_02022CF8->unk301C = 0;
            PlaySE(SE_SELECT);
            sub_8028C30(TRUE);
            gUnknown_02022CF8->state++;
        }
        break;
    case 5:
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[1], PIXEL_FILL(1));
        strWidth = GetStringWidth(1, gText_AnnouncingRankings, -1);
        x = (224 - strWidth) / 2;
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_AnnouncingRankings, x, 1, -1, NULL);
        gUnknown_02022CF8->state++;
        break;
    case 6:
        sub_80296A8(playersCount);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[1], 2);
        gUnknown_02022CF8->state++;
        break;
    case 7:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
            PutWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        }
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->state++;
        break;
    case 8:
        if (++gUnknown_02022CF8->unk301C >= 30 && JOY_NEW(A_BUTTON))
        {
            gUnknown_02022CF8->unk301C = 0;
            PlaySE(SE_SELECT);
            if (sub_8027748() < 3000)
            {
                gUnknown_02022CF8->state = 127;
            }
            else
            {
                StopMapMusic();
                gUnknown_02022CF8->state++;
            }

            FillBgTilemapBufferRect_Palette0(0, 0, 0, 5, 30, 15);
            RemoveWindow(gUnknown_02022CF8->unk3008[1]);
            gUnknown_02022CF8->unk3008[1] = AddWindow(&gUnknown_082F7BCC);
            ClearWindowTilemap(gUnknown_02022CF8->unk3008[1]);
            sub_8029174(&gUnknown_082F7BCC);
        }
        break;
    case 9:
        PlayNewMapMusic(MUS_LEVEL_UP);
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[1], PIXEL_FILL(1));
        strWidth = GetStringWidth(1, gText_AnnouncingPrizes, -1);
        x = (224 - strWidth) / 2;
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_AnnouncingPrizes, x, 1, -1, NULL);
        DynamicPlaceholderTextUtil_Reset();
        CopyItemName(sub_802762C(), gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_FirstPlacePrize);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gStringVar4, 0, 1, -1, NULL);
        itemGiveRet = sub_80279C8();
        if (itemGiveRet != 0 && itemGiveRet != 3)
        {
            DynamicPlaceholderTextUtil_Reset();
            CopyItemName(sub_802762C(), gStringVar1);
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
            if (itemGiveRet == 2)
                DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_CantHoldAnyMore);
            else if (itemGiveRet == 1)
                DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_FilledStorageSpace);
            AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gStringVar4, 0, 41, -1, NULL);
        }
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[1], 2);
        gUnknown_02022CF8->state++;
        break;
    case 10:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
            PutWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        }
        CopyBgTilemapBufferToVram(0);
        FadeOutAndFadeInNewMapMusic(MUS_RG_VICTORY_WILD, 20, 10);
        gUnknown_02022CF8->state++;
        break;
    case 11:
        if (++gUnknown_02022CF8->unk301C >= 30 && JOY_NEW(A_BUTTON))
        {
            gUnknown_02022CF8->unk301C = 0;
            PlaySE(SE_SELECT);
            gUnknown_02022CF8->state++;
        }
        break;
    default:
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        RemoveWindow(gUnknown_02022CF8->unk3008[0]);
        RemoveWindow(gUnknown_02022CF8->unk3008[1]);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_802A010(void)
{
    u8 y;

    switch (gUnknown_02022CF8->state)
    {
    case 0:
        gUnknown_02022CF8->unk3008[0] = AddWindow(&gUnknown_082F7BD4[0]);
        gUnknown_02022CF8->unk3008[1] = AddWindow(&gUnknown_082F7BD4[1]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        sub_8029174(&gUnknown_082F7BD4[0]);
        sub_8029074(&gUnknown_082F7BD4[1]);
        gUnknown_02022CF8->state++;
        gUnknown_02022CF8->unk3020 = 0;
        gUnknown_02022CF8->unk3024 = 0;
        break;
    case 1:
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[1], PIXEL_FILL(1));
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_WantToPlayAgain, 0, 5, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_Yes, 8, 1, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_No, 8, 17, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_SelectorArrow2, 0, 1, -1, NULL);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[1], 2);
        gUnknown_02022CF8->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
            PutWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        }
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->state++;
        break;
    case 3:
        y = gUnknown_02022CF8->unk3020;
        if (y == 0)
            y = 1;
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[1], PIXEL_FILL(1));
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_Yes, 8, 1, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_No, 8, 17, -1, NULL);
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[1], 1, gText_SelectorArrow2, 0, ((y - 1) * 16) + 1, -1, NULL);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[1], 3);
        // Increment state only if A or B button have been pressed.
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gUnknown_02022CF8->unk3020 == 0)
                gUnknown_02022CF8->unk3020 = 1;
            gUnknown_02022CF8->state++;
        }
        else if (JOY_NEW(DPAD_UP | DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            switch (gUnknown_02022CF8->unk3020)
            {
            case 0:
                gUnknown_02022CF8->unk3020 = 2;
                break;
            case 1:
                gUnknown_02022CF8->unk3020 = 2;
                break;
            case 2:
                gUnknown_02022CF8->unk3020 = 1;
                break;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gUnknown_02022CF8->unk3020 = 2;
            gUnknown_02022CF8->state++;
        }
        break;
    default:
        gUnknown_02022CF8->unk3024 = gUnknown_02022CF8->unk3020;
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[1]);
        RemoveWindow(gUnknown_02022CF8->unk3008[0]);
        RemoveWindow(gUnknown_02022CF8->unk3008[1]);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_802A380(void)
{
    switch (gUnknown_02022CF8->state)
    {
    case 0:
        DrawDialogueFrame(0, FALSE);
        AddTextPrinterParameterized2(0, 1, gText_SavingDontTurnOffPower, 0, NULL, 2, 1, 3);
        gUnknown_02022CF8->state++;
        break;
    case 1:
        CopyWindowToVram(0, 3);
        gUnknown_02022CF8->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateTask(Task_LinkSave, 0);
            gUnknown_02022CF8->state++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(Task_LinkSave))
            gUnknown_02022CF8->state++;
        break;
    default:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_802A454(void)
{
    switch (gUnknown_02022CF8->state)
    {
    case 0:
        gUnknown_02022CF8->unk3008[0] = AddWindow(&gUnknown_082F7BEC);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        sub_8029174(&gUnknown_082F7BEC);
        gUnknown_02022CF8->state++;
        break;
    case 1:
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_CommunicationStandby3, 0, 5, -1, NULL);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        gUnknown_02022CF8->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->state++;
        break;
    default:
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_802A534(void)
{
    ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
    RemoveWindow(gUnknown_02022CF8->unk3008[0]);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
    gUnknown_02022CF8->finished = TRUE;
}

static void sub_802A588(void)
{
    switch (gUnknown_02022CF8->state)
    {
    case 0:
        gUnknown_02022CF8->unk3008[0] = AddWindow(&gUnknown_082F7BE4);
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        sub_8029174(&gUnknown_082F7BE4);
        gUnknown_02022CF8->state++;
        gUnknown_02022CF8->unk301C = 0;
        gUnknown_02022CF8->unk3020 = 0;
        gUnknown_02022CF8->unk3024 = 0;
        break;
    case 1:
        FillWindowPixelBuffer(gUnknown_02022CF8->unk3008[0], PIXEL_FILL(1));
        AddTextPrinterParameterized(gUnknown_02022CF8->unk3008[0], 1, gText_SomeoneDroppedOut, 0, 5, -1, NULL);
        CopyWindowToVram(gUnknown_02022CF8->unk3008[0], 2);
        gUnknown_02022CF8->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            PutWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->state++;
        break;
    case 3:
        if (++gUnknown_02022CF8->unk301C >= 120)
            gUnknown_02022CF8->state++;
        break;
    default:
        gUnknown_02022CF8->unk3024 = 5;
        ClearWindowTilemap(gUnknown_02022CF8->unk3008[0]);
        RemoveWindow(gUnknown_02022CF8->unk3008[0]);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022CF8->finished = TRUE;
        break;
    }
}

static void sub_802A6FC(void)
{
    DestroyTask(gUnknown_02022CF8->unk3004);
    gUnknown_02022CF8->finished = TRUE;
}

static void nullsub_16(void)
{

}

static void sub_802A72C(void (*func)(void))
{
    gUnknown_02022CF8->state = 0;
    gUnknown_02022CF8->finished = FALSE;
    gUnknown_02022CF8->unk3028 = func;
}

static void (*sub_802A75C(void))(void)
{
    return gUnknown_02022CF8->unk3028;
}

static bool32 sub_802A770(void)
{
    if (gUnknown_02022CF8->finished == TRUE)
        return FALSE;
    else
        return TRUE;
}

static u8 sub_802A794(void)
{
    return gUnknown_02022CF8->unk3024;
}

static void sub_802A7A8(void)
{
    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3,(void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_082F7BA4, ARRAY_COUNT(gUnknown_082F7BA4));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitStandardTextBoxWindows();
    InitTextBoxGfxAndPrinters();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetBgTilemapBuffer(3, gUnknown_02022CF8->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, gUnknown_02022CF8->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, gUnknown_02022CF8->tilemapBuffers[2]);
}

static bool32 sub_802A8E8(void)
{
    switch (gUnknown_02022CF8->unk3018)
    {
    case 0:
        LoadPalette(gDodrioBerryBgPal1, 0, sizeof(gDodrioBerryBgPal1));
        break;
    case 1:
        ResetTempTileDataBuffers();
        break;
    case 2:
        DecompressAndCopyTileDataToVram(3, gDodrioBerryBgGfx1, 0, 0, 0);
        break;
    case 3:
        DecompressAndCopyTileDataToVram(1, gDodrioBerryBgGfx2, 0, 0, 0);
        break;
    case 4:
        if (FreeTempTileDataBuffersIfPossible() == TRUE)
            return FALSE;
        break;
    case 5:
        LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
        break;
    default:
        gUnknown_02022CF8->unk3018 = 0;
        return TRUE;
    }

    gUnknown_02022CF8->unk3018++;
    return FALSE;
}

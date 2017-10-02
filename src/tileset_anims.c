
// Includes
#include "global.h"
#include "palette.h"
#include "blend_palette.h"
#include "battle.h"
#include "task.h"

// Static type declarations

// Static RAM declarations

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetCBCounter;
static u16 sPrimaryTilesetCBBufferSize;
static u16 sSecondaryTilesetCBCounter;
static u16 sSecondaryTilesetCBBufferSize;
static void (*sPrimaryTilesetCB)(u16);
static void (*sSecondaryTilesetCB)(u16);

// Static ROM declarations

static void cur_mapheader_run_tileset1_func(void);
static void cur_mapheader_run_tileset2_func(void);

// .rodata

extern const u16 *const gTilesetAnims_General0[];
extern const u16 *const gTilesetAnims_General1[];
extern const u16 *const gTilesetAnims_General2[];
extern const u16 *const gTilesetAnims_General3[];
extern const u16 *const gTilesetAnims_General4[];
extern const u16 *const gTilesetAnims_Lavaridge0[];
extern const u16 *const gTilesetAnims_Pacifidlog0[];
extern const u16 *const gTilesetAnims_Underwater0[];
extern const u16 *const gTilesetAnims_Pacifidlog1[];
extern u16 *const gTilesetAnims_MauvilleVDests0[];
extern u16 *const gTilesetAnims_MauvilleVDests1[];
extern const u16 *const gTilesetAnims_Mauville0a[];
extern const u16 *const gTilesetAnims_Mauville0b[];
extern const u16 *const gTilesetAnims_Mauville1a[];
extern const u16 *const gTilesetAnims_Mauville1b[];
extern  u16 *const gTilesetAnims_RustboroVDests0[];
extern const u16 *const gTilesetAnims_Rustboro0[];
extern const u16 *const gTilesetAnims_Rustboro1[];
extern const u16 *const gTilesetAnims_Lavaridge1_Cave0[];
extern  u16 *const gTilesetAnims_EverGrandeVDests0[];
extern const u16 *const gTilesetAnims_EverGrande0[];
extern const u16 *const gTilesetAnims_Dewford0[];
extern const u16 *const gTilesetAnims_BattleFrontierOutsideWest0[];
extern const u16 *const gTilesetAnims_BattleFrontierOutsideEast0[];
extern const u16 *const gTilesetAnims_Slateport0[];
extern const u16 *const gTilesetAnims_InsideBuilding0[];
extern const u16 *const gTilesetAnims_SootopolisGym0[];
extern const u16 *const gTilesetAnims_SootopolisGym1[];
extern const u16 *const gTilesetAnims_EliteFour1[];
extern const u16 *const gTilesetAnims_EliteFour0[];
extern const u16 *const gTilesetAnims_MauvilleGym0[];
extern const u16 *const gTilesetAnims_BikeShop0[];
extern const u16 *const gTilesetAnims_Sootopolis0[];
extern const u16 *const gTilesetAnims_BattlePyramid0[];
extern const u16 *const gTilesetAnims_BattlePyramid1[];

extern const u16 gUnknown_08D85640[];
extern const u16 gUnknown_08D85660[];
extern const u16 gUnknown_08D85680[];
extern const u16 gUnknown_08D856A0[];

static const u16 *const gTilesetAnims_BattleDomePals0[] = {
    gUnknown_08D85640,
    gUnknown_08D85660,
    gUnknown_08D85680,
    gUnknown_08D856A0,
};

// .text

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i ++)
    {
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);
    }
    sTilesetDMA3TransferBufferSize = 0;
}

void cur_mapheader_run_tileset_funcs_after_some_cpuset(void)
{
    ResetTilesetAnimBuffer();
    cur_mapheader_run_tileset1_func();
    cur_mapheader_run_tileset2_func();
}

void sub_80A0A2C(void)
{
    cur_mapheader_run_tileset2_func();
}

void sub_80A0A38(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetCBCounter >= sPrimaryTilesetCBBufferSize)
        sPrimaryTilesetCBCounter = 0;
    if (++sSecondaryTilesetCBCounter >= sSecondaryTilesetCBBufferSize)
        sSecondaryTilesetCBCounter = 0;
    if (sPrimaryTilesetCB)
        sPrimaryTilesetCB(sPrimaryTilesetCBCounter);
    if (sSecondaryTilesetCB)
        sSecondaryTilesetCB(sSecondaryTilesetCBCounter);
}

static void cur_mapheader_run_tileset1_func(void)
{
    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0;
    sPrimaryTilesetCB = NULL;
    if (gMapHeader.mapData->primaryTileset && gMapHeader.mapData->primaryTileset->callback)
        gMapHeader.mapData->primaryTileset->callback();
}

static void cur_mapheader_run_tileset2_func(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 0;
    sSecondaryTilesetCB = NULL;
    if (gMapHeader.mapData->secondaryTileset && gMapHeader.mapData->secondaryTileset->callback)
        gMapHeader.mapData->secondaryTileset->callback();
}

void TilesetCb_General(void)
{
    static void sub_80A0B70(u16);

    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0x100;
    sPrimaryTilesetCB = sub_80A0B70;
}

void TilesetCb_InsideBuilding(void)
{
    static void sub_80A0BB4(u16);

    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0x100;
    sPrimaryTilesetCB = sub_80A0BB4;
}

static void sub_80A0B70(u16 timer)
{
    static void sub_80A0BCC(u16);
    static void sub_80A0BF4(u16);
    static void sub_80A0C1C(u16);
    static void sub_80A0C44(u16);
    static void sub_80A12AC(u16);

    if ((timer & 0x0F) == 0)
        sub_80A0BCC(timer >> 4);
    if ((timer & 0x0F) == 1)
        sub_80A0BF4(timer >> 4);
    if ((timer & 0x0F) == 2)
        sub_80A0C1C(timer >> 4);
    if ((timer & 0x0F) == 3)
        sub_80A0C44(timer >> 4);
    if ((timer & 0x0F) == 4)
        sub_80A12AC(timer >> 4);
}

static void sub_80A0BB4(u16 timer)
{
    static void sub_80A1688(u16);

    if ((timer & 0x7) == 0)
        sub_80A1688(timer >> 3);
}

static void sub_80A0BCC(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_General0[idx], (u16 *)(BG_VRAM + 0x3F80), 0x80);
}

static void sub_80A0BF4(u16 timer)
{
    u8 idx;

    idx = timer % 8;
    AppendTilesetAnimToBuffer(gTilesetAnims_General1[idx], (u16 *)(BG_VRAM + 0x3600), 0x3C0);
}

static void sub_80A0C1C(u16 timer)
{
    u16 idx;

    idx = timer % 8;
    AppendTilesetAnimToBuffer(gTilesetAnims_General2[idx], (u16 *)(BG_VRAM + 0x3a00), 0x140);
}

static void sub_80A0C44(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_General3[idx], (u16 *)(BG_VRAM + 0x3e00), 0xc0);
}

void TilesetCb_Petalburg(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_Rustboro(void)
{
    static void sub_80A103C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A103C;
}

void TilesetCb_Dewford(void)
{
    static void sub_80A10B8(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10B8;
}

void TilesetCb_Slateport(void)
{
    static void sub_80A10D0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10D0;
}

void TilesetCb_Mauville(void)
{
    static void sub_80A10E8(u16);

    sSecondaryTilesetCBCounter = sPrimaryTilesetCBCounter;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10E8;
}

void TilesetCb_Lavaridge(void)
{
    static void sub_80A115C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A115C;
}

void TilesetCb_Fallarbor(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_Fortree(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_Lilycove(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_Mossdeep(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_EverGrande(void)
{
    static void sub_80A1188(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1188;
}

void TilesetCb_Pacifidlog(void)
{
    static void sub_80A11FC(u16);

    sSecondaryTilesetCBCounter = sPrimaryTilesetCBCounter;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A11FC;
}

void TilesetCb_Sootopolis(void)
{
    static void sub_80A122C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A122C;
}

void TilesetCb_BattleFrontierOutsideWest(void)
{
    static void sub_80A127C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A127C;
}

void TilesetCb_BattleFrontierOutsideEast(void)
{
    static void sub_80A1294(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1294;
}

void TilesetCb_Underwater(void)
{
    static void sub_80A1244(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 128;
    sSecondaryTilesetCB = sub_80A1244;
}

void TilesetCb_SootopolisGym(void)
{
    static void sub_80A15D8(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 240;
    sSecondaryTilesetCB = sub_80A15D8;
}

void TilesetCb_Cave(void)
{
    static void sub_80A1260(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1260;
}

void TilesetCb_EliteFour(void)
{
    static void sub_80A15F0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 128;
    sSecondaryTilesetCB = sub_80A15F0;
}

void TilesetCb_MauvilleGym(void)
{
    static void sub_80A15C0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A15C0;
}

void TilesetCb_BikeShop(void)
{
    static void sub_80A161C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A161C;
}

void TilesetCb_BattlePyramid(void)
{
    static void sub_80A1634(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1634;
}

void TilesetCb_BattleDome(void)
{
    static void sub_80A1658(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1658;
}

static void sub_80A103C(u16 timer)
{
    static void sub_80A1434(u16, u8);
    static void sub_80A1470(u16);

    if ((timer & 0x07) == 0)
    {
        sub_80A1434(timer >> 3, 0);
        sub_80A1470(timer >> 3);
    }
    if ((timer & 0x07) == 1)
        sub_80A1434(timer >> 3, 1);
    if ((timer & 0x07) == 2)
        sub_80A1434(timer >> 3, 2);
    if ((timer & 0x07) == 3)
        sub_80A1434(timer >> 3, 3);
    if ((timer & 0x07) == 4)
        sub_80A1434(timer >> 3, 4);
    if ((timer & 0x07) == 5)
        sub_80A1434(timer >> 3, 5);
    if ((timer & 0x07) == 6)
        sub_80A1434(timer >> 3, 6);
    if ((timer & 0x07) == 7)
        sub_80A1434(timer >> 3, 7);
}

static void sub_80A10B8(u16 timer)
{
    static void sub_80A1520(u16);

    if ((timer & 7) == 0)
        sub_80A1520(timer >> 3);
}

static void sub_80A10D0(u16 timer)
{
    static void sub_80A1598(u16);

    if ((timer & 15) == 0)
        sub_80A1598(timer >> 4);
}

static void sub_80A10E8(u16 timer)
{
    static void sub_80A1394(u16, u8);

    if ((timer & 0x07) == 0)
        sub_80A1394(timer >> 3, 0);
    if ((timer & 0x07) == 1)
        sub_80A1394(timer >> 3, 1);
    if ((timer & 0x07) == 2)
        sub_80A1394(timer >> 3, 2);
    if ((timer & 0x07) == 3)
        sub_80A1394(timer >> 3, 3);
    if ((timer & 0x07) == 4)
        sub_80A1394(timer >> 3, 4);
    if ((timer & 0x07) == 5)
        sub_80A1394(timer >> 3, 5);
    if ((timer & 0x07) == 6)
        sub_80A1394(timer >> 3, 6);
    if ((timer & 0x07) == 7)
        sub_80A1394(timer >> 3, 7);
}

static void sub_80A115C(u16 timer)
{
    static void sub_80A12D4(u8);
    static void sub_80A1498(u16);

    if ((timer & 0x0F) == 0)
        sub_80A12D4(timer >> 4);
    if ((timer & 0x0F) == 1)
        sub_80A1498(timer >> 4);
}

static void sub_80A1188(u16 timer)
{
    static void sub_80A14C0(u16, u8);

    if ((timer & 0x07) == 0)
        sub_80A14C0(timer >> 3, 0);
    if ((timer & 0x07) == 1)
        sub_80A14C0(timer >> 3, 1);
    if ((timer & 0x07) == 2)
        sub_80A14C0(timer >> 3, 2);
    if ((timer & 0x07) == 3)
        sub_80A14C0(timer >> 3, 3);
    if ((timer & 0x07) == 4)
        sub_80A14C0(timer >> 3, 4);
    if ((timer & 0x07) == 5)
        sub_80A14C0(timer >> 3, 5);
    if ((timer & 0x07) == 6)
        sub_80A14C0(timer >> 3, 6);
    if ((timer & 0x07) == 7)
        sub_80A14C0(timer >> 3, 7);
}

static void sub_80A11FC(u16 timer)
{
    static void sub_80A131C(u8);
    static void sub_80A136C(u8);

    if ((timer & 0x0F) == 0)
        sub_80A131C(timer >> 4);
    if ((timer & 0x0F) == 1)
        sub_80A136C(timer >> 4);
}

static void sub_80A122C(u16 timer)
{
    static void sub_80A1798(u16);

    if ((timer & 0x0F) == 0)
        sub_80A1798(timer >> 4);
}

static void sub_80A1244(u16 timer)
{
    static void sub_80A1344(u8);

    if ((timer & 0x0F) == 0)
        sub_80A1344(timer >> 4);
}

static void sub_80A1260(u16 timer)
{
    static void sub_80A14F8(u16);

    if ((timer & 0x0F) == 1)
        sub_80A14F8(timer >> 4);
}

static void sub_80A127C(u16 timer)
{
    static void sub_80A1548(u16);

    if ((timer & 0x07) == 0)
        sub_80A1548(timer >> 3);
}

static void sub_80A1294(u16 timer)
{
    static void sub_80A1570(u16);

    if ((timer & 0x07) == 0)
        sub_80A1570(timer >> 3);
}

static void sub_80A12AC(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_General4[idx], (u16 *)(BG_VRAM + 0x3c00), 0x140);
}

static void sub_80A12D4(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge0[idx], (u16 *)(BG_VRAM + 0x6400), 0x80);

    idx = (timer + 2) % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge0[idx], (u16 *)(BG_VRAM + 0x6480), 0x80);
}

static void sub_80A131C(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Pacifidlog0[idx], (u16 *)(BG_VRAM + 0x7a00), 0x3C0);
}

static void sub_80A1344(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Underwater0[idx], (u16 *)(BG_VRAM + 0x7e00), 0x80);
}

static void sub_80A136C(u8 timer)
{
    u8 idx;

    idx = timer % 8;
    AppendTilesetAnimToBuffer(gTilesetAnims_Pacifidlog1[idx], (u16 *)(BG_VRAM + 0x7e00), 0x100);
}

static void sub_80A1394(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    if (timer_div < 12) // almost certainly a typo
    {
        timer_div %= 12;
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville0a[timer_div], gTilesetAnims_MauvilleVDests0[timer_mod], 0x80);
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville0b[timer_div], gTilesetAnims_MauvilleVDests1[timer_mod], 0x80);
    }
    else
    {
        timer_div %= 4;
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville1a[timer_div], gTilesetAnims_MauvilleVDests0[timer_mod], 0x80);
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville1b[timer_div], gTilesetAnims_MauvilleVDests1[timer_mod], 0x80);
    }
}

static void sub_80A1434(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= 8;
    if (gTilesetAnims_Rustboro0[timer_div])
        AppendTilesetAnimToBuffer(gTilesetAnims_Rustboro0[timer_div], gTilesetAnims_RustboroVDests0[timer_mod], 0x80);
}

static void sub_80A1470(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    AppendTilesetAnimToBuffer(gTilesetAnims_Rustboro1[idx], (u16 *)(BG_VRAM + 0x7800), 0x80);
}

static void sub_80A1498(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge1_Cave0[idx], (u16 *)(BG_VRAM + 0x5400), 0x80);
}

static void sub_80A14C0(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= 8;

    AppendTilesetAnimToBuffer(gTilesetAnims_EverGrande0[timer_div], gTilesetAnims_EverGrandeVDests0[timer_mod], 0x80);
}

static void sub_80A14F8(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge1_Cave0[idx], (u16 *)(BG_VRAM + 0x7400), 0x80);
}

static void sub_80A1520(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford0[idx], (u16 *)(BG_VRAM + 0x5540), 0xC0);
}

static void sub_80A1548(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest0[idx], (u16 *)(BG_VRAM + 0x5b40), 0xC0);
}

static void sub_80A1570(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast0[idx], (u16 *)(BG_VRAM + 0x5b40), 0xC0);
}

static void sub_80A1598(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport0[idx], (u16 *)(BG_VRAM + 0x5c00), 0x80);
}

static void sub_80A15C0(u16 timer)
{
    static void sub_80A1748(u16);

    if ((timer & 1) == 0)
        sub_80A1748(timer >> 1);
}

static void sub_80A15D8(u16 timer)
{
    static void sub_80A16B0(u16);

    if ((timer & 7) == 0)
        sub_80A16B0(timer >> 3);
}

static void sub_80A15F0(u16 timer)
{
    static void sub_80A1720(u16);
    static void sub_80A16F8(u16);

    if ((timer & 0x3f) == 1)
        sub_80A1720(timer >> 6);
    if ((timer & 0x07) == 1)
        sub_80A16F8(timer >> 3);
}
static void sub_80A161C(u16 timer)
{
    static void sub_80A1770(u16);

    if ((timer & 3) == 0)
        sub_80A1770(timer >> 2);
}

static void sub_80A1634(u16 timer)
{
    static void sub_80A17C0(u16);
    static void sub_80A17EC(u16);

    if ((timer & 7) == 0)
    {
        sub_80A17C0(timer >> 3);
        sub_80A17EC(timer >> 3);
    }
}

static void sub_80A1658(u16 timer)
{
    static void sub_80A1818(u16);

    if ((timer & 3) == 0)
        sub_80A1818(timer >> 2);
}

static void sub_80A1670(u16 timer)
{
    static void sub_80A1884(u16);

    if ((timer & 3) == 0)
        sub_80A1884(timer >> 2);
}

static void sub_80A1688(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    AppendTilesetAnimToBuffer(gTilesetAnims_InsideBuilding0[idx], (u16 *)(BG_VRAM + 0x3e00), 0x80);
}

static void sub_80A16B0(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    AppendTilesetAnimToBuffer(gTilesetAnims_SootopolisGym0[idx], (u16 *)(BG_VRAM + 0x7e00), 0x180);
    AppendTilesetAnimToBuffer(gTilesetAnims_SootopolisGym1[idx], (u16 *)(BG_VRAM + 0x7a00), 0x280);
}

static void sub_80A16F8(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_EliteFour1[idx], (u16 *)(BG_VRAM + 0x7f00), 0x20);
}

static void sub_80A1720(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    AppendTilesetAnimToBuffer(gTilesetAnims_EliteFour0[idx], (u16 *)(BG_VRAM + 0x7c00), 0x80);
}

static void sub_80A1748(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    AppendTilesetAnimToBuffer(gTilesetAnims_MauvilleGym0[idx], (u16 *)(BG_VRAM + 0x5200), 0x200);
}

static void sub_80A1770(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    AppendTilesetAnimToBuffer(gTilesetAnims_BikeShop0[idx], (u16 *)(BG_VRAM + 0x7e00), 0x120);
}

static void sub_80A1798(u16 timer)
{
    u16 idx;

    idx = timer % 8;
    AppendTilesetAnimToBuffer(gTilesetAnims_Sootopolis0[idx], (u16 *)(BG_VRAM + 0x5e00), 0xc00);
}

static void sub_80A17C0(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid0[idx], (u16 *)(BG_VRAM + 0x52e0), 0x100);
}

static void sub_80A17EC(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid1[idx], (u16 *)(BG_VRAM + 0x50e0), 0x100);
}

static void sub_80A1818(u16 a1)
{
    CpuCopy16(gTilesetAnims_BattleDomePals0[a1 & 0x3], gPlttBufferUnfaded + 0x80, 32);
    BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if ((u8)FindTaskIdByFunc(sub_8149DFC) != 0xFF )
    {
        sSecondaryTilesetCB = sub_80A1670;
        sSecondaryTilesetCBBufferSize = 0x20;
    }
}

static void sub_80A1884(u16 a1)
{
    CpuCopy16(gTilesetAnims_BattleDomePals0[a1 & 0x3], gPlttBufferUnfaded + 0x80, 32);
    if ((u8)FindTaskIdByFunc(sub_8149DFC) == 0xFF )
    {
        BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetCBBufferSize)
            sSecondaryTilesetCB = NULL;
    }
}

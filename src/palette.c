#include "global.h"
#include "palette.h"
#include "task.h"

enum
{
    NORMAL_FADE,
    FAST_FADE,
    HARDWARE_FADE,
};

// These are structs for some unused palette system.
// The full functionality of this system is unknown.

struct PaletteStructTemplate
{
    u16 uid;
    u16 *src;
    u16 pst_field_8_0:1;
    u16 pst_field_8_1:9;
    u16 size:5;
    u16 pst_field_9_7:1;
    u8 pst_field_A;
    u8 srcCount:5;
    u8 pst_field_B_5:3;
    u8 pst_field_C;
};

struct PaletteStruct
{
    const struct PaletteStructTemplate *base;
    u32 ps_field_4_0:1;
    u16 ps_field_4_1:1;
    u32 baseDestOffset:9;
    u16 destOffset:10;
    u16 srcIndex:7;
    u8 ps_field_8;
    u8 ps_field_9;
};

extern void LZDecompressWram(const void *src, void *dest);
extern void SetGpuReg(u8 regOffset, u16 value);
extern void sub_8149DFC(u8 a1);
extern void sub_80A1670(u16 a1);
extern void sub_80A2D54(u8 a1);
extern void SetWordTaskArg(u8 taskId, u8 dataElem, u32 value);
extern void _call_via_r1(u32 a1, void *a2);

extern void BlendPalette(u16, u16, u8, u16);

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};
EWRAM_DATA u16 gPlttBufferUnfaded[0x200] = {0};
EWRAM_DATA u16 gPlttBufferFaded[0x200] = {0};
EWRAM_DATA struct PaletteStruct sPaletteStructs[0x10] = {0};
EWRAM_DATA struct PaletteFadeControl gPaletteFade = {0};
EWRAM_DATA u32 gFiller_2037FE0 = 0;
EWRAM_DATA u32 sPlttBufferTransferPending = 0;
EWRAM_DATA u8 gPaletteDecompressionBuffer[0x400] = {0};

extern const u16 *const gUnknown_08510764[];
extern const u16 *const gUnknown_08512574[];
extern const u16 *const gUnknown_08512E54[];
extern const u16 *const gUnknown_08513174[];
extern const u16 *const gUnknown_08513684[];
extern const u16 *const gUnknown_08513894[];
extern const u16 *const gUnknown_085143E4[];
extern const u16 *const gUnknown_085145F4[];
extern const u16 *const gUnknown_08514E04[];
extern u16 *const gUnknown_08515344[];
extern u16 *const gUnknown_08515364[];
extern const u16 *const gUnknown_08515384[];
extern const u16 *const gUnknown_085153B4[];
extern const u16 *const gUnknown_085153E4[];
extern const u16 *const gUnknown_085153F4[];
extern  u16 *const gUnknown_08515804[];
extern const u16 *const gUnknown_08515824[];
extern const u16 *const gUnknown_08515964[];
extern const u16 *const gUnknown_08515D8C[];
extern  u16 *const gUnknown_085161BC[];
extern const u16 *const gUnknown_085161DC[];
extern const u16 *const gUnknown_085164FC[];
extern const u16 *const gUnknown_0851680C[];
extern const u16 *const gUnknown_08516B1C[];
extern const u16 *const gUnknown_08516D2C[];
extern const u16 *const gUnknown_08516E3C[];
extern const u16 *const gUnknown_08517A44[];
extern const u16 *const gUnknown_08517A50[];
extern const u16 *const gUnknown_08517BFC[];
extern const u16 *const gUnknown_08517C0C[];
extern const u16 *const gUnknown_08518034[];
extern const u16 *const gUnknown_0851829C[];
extern const u16 *const gUnknown_085202C4[];
extern const u16 *const gUnknown_08524864[];
extern const u16 *const gUnknown_08524870[];

extern const u16 gUnknown_08D85640[];
extern const u16 gUnknown_08D85660[];
extern const u16 gUnknown_08D85680[];
extern const u16 gUnknown_08D856A0[];

static const u16 *const gUnknown_0852487C[] = {
    gUnknown_08D85640,
    gUnknown_08D85660,
    gUnknown_08D85680,
    gUnknown_08D856A0,
};

static const struct PaletteStructTemplate gDummyPaletteStructTemplate = {
    .uid = 0xFFFF,
    .pst_field_B_5 = 1
};
static const u8 gUnknown_0852489C[] = {
     0,  0,  0,  0,  0,
     5,  5,  5,  5,  5,
    11, 11, 11, 11, 11,
    16, 16, 16, 16, 16,
    21, 21, 21, 21, 21,
    27, 27, 27, 27, 27,
    31, 31
};

void cur_mapheader_run_tileset1_func(void);
void cur_mapheader_run_tileset2_func(void);
static void unused_sub_80A1CDC(struct PaletteStruct *, u32 *);
static void unused_sub_80A1E40(struct PaletteStruct *, u32 *);
static void unused_sub_80A1F00(struct PaletteStruct *);
static u8 GetPaletteNumByUid(u16);
static u8 UpdateNormalPaletteFade(void);
static void BeginFastPaletteFadeInternal(u8);
static u8 UpdateFastPaletteFade(void);
static u8 UpdateHardwarePaletteFade(void);
static void UpdateBlendRegisters(void);
static bool8 IsSoftwarePaletteFadeFinishing(void);

// tileset

IWRAM_DATA u8 sTilesetDMA3TransferBufferSize;
IWRAM_DATA u16 sPrimaryTilesetCBCounter;
IWRAM_DATA u16 sPrimaryTilesetCBBufferSize;
IWRAM_DATA u16 sSecondaryTilesetCBCounter;
IWRAM_DATA u16 sSecondaryTilesetCBBufferSize;
IWRAM_DATA void (*sPrimaryTilesetCB)(u16);
IWRAM_DATA void (*sSecondaryTilesetCB)(u16);

void sub_80A0954(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

void sub_80A0980(const u16 *a0, u16 *a1, u16 a2)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = a0;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = a1;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = a2;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void sub_80A09D0(void)
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
    sub_80A0954();
    cur_mapheader_run_tileset1_func();
    cur_mapheader_run_tileset2_func();
}

void sub_80A0A2C(void)
{
    cur_mapheader_run_tileset2_func();
}

void sub_80A0A38(void)
{
    sub_80A0954();
    if (++sPrimaryTilesetCBCounter >= sPrimaryTilesetCBBufferSize)
        sPrimaryTilesetCBCounter = 0;
    if (++sSecondaryTilesetCBCounter >= sSecondaryTilesetCBBufferSize)
        sSecondaryTilesetCBCounter = 0;
    if (sPrimaryTilesetCB)
        sPrimaryTilesetCB(sPrimaryTilesetCBCounter);
    if (sSecondaryTilesetCB)
        sSecondaryTilesetCB(sSecondaryTilesetCBCounter);
}

void cur_mapheader_run_tileset1_func(void)
{
    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0;
    sPrimaryTilesetCB = NULL;
    if (gMapHeader.mapData->primaryTileset && gMapHeader.mapData->primaryTileset->callback)
        gMapHeader.mapData->primaryTileset->callback();
}

void cur_mapheader_run_tileset2_func(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 0;
    sSecondaryTilesetCB = NULL;
    if (gMapHeader.mapData->secondaryTileset && gMapHeader.mapData->secondaryTileset->callback)
        gMapHeader.mapData->secondaryTileset->callback();
}

void TilesetCb_General(void)
{
    void sub_80A0B70(u16);

    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0x100;
    sPrimaryTilesetCB = sub_80A0B70;
}

void TilesetCb_InsideBuilding(void)
{
    void sub_80A0BB4(u16);

    sPrimaryTilesetCBCounter = 0;
    sPrimaryTilesetCBBufferSize = 0x100;
    sPrimaryTilesetCB = sub_80A0BB4;
}

void sub_80A0B70(u16 timer)
{
    void sub_80A0BCC(u16);
    void sub_80A0BF4(u16);
    void sub_80A0C1C(u16);
    void sub_80A0C44(u16);
    void sub_80A12AC(u16);

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

void sub_80A0BB4(u16 timer)
{
    void sub_80A1688(u16);
    if ((timer & 0x7) == 0)
        sub_80A1688(timer >> 3);
}

void sub_80A0BCC(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08510764[idx], (u16 *)(VRAM + 0x3F80), 0x80);
}

void sub_80A0BF4(u16 timer)
{
    u8 idx;

    idx = timer % 8;
    sub_80A0980(gUnknown_08512574[idx], (u16 *)(VRAM + 0x3600), 0x3C0);
}

void sub_80A0C1C(u16 timer)
{
    u16 idx;

    idx = timer % 8;
    sub_80A0980(gUnknown_08512E54[idx], (u16 *)(VRAM + 0x3a00), 0x140);
}

void sub_80A0C44(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08513174[idx], (u16 *)(VRAM + 0x3e00), 0xc0);
}

void TilesetCb_Petalburg(void)
{
    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = NULL;
}

void TilesetCb_Rustboro(void)
{
    void sub_80A103C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A103C;
}

void TilesetCb_Dewford(void)
{
    void sub_80A10B8(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10B8;
}

void TilesetCb_Slateport(void)
{
    void sub_80A10D0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10D0;
}

void TilesetCb_Mauville(void)
{
    void sub_80A10E8(u16);

    sSecondaryTilesetCBCounter = sPrimaryTilesetCBCounter;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A10E8;
}

void TilesetCb_Lavaridge(void)
{
    void sub_80A115C(u16);

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
    void sub_80A1188(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1188;
}

void TilesetCb_Pacifidlog(void)
{
    void sub_80A11FC(u16);

    sSecondaryTilesetCBCounter = sPrimaryTilesetCBCounter;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A11FC;
}

void TilesetCb_Sootopolis(void)
{
    void sub_80A122C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A122C;
}

void TilesetCb_BattleFrontierOutsideWest(void)
{
    void sub_80A127C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A127C;
}

void TilesetCb_BattleFrontierOutsideEast(void)
{
    void sub_80A1294(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1294;
}

void TilesetCb_Underwater(void)
{
    void sub_80A1244(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 128;
    sSecondaryTilesetCB = sub_80A1244;
}

void TilesetCb_SootopolisGym(void)
{
    void sub_80A15D8(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 240;
    sSecondaryTilesetCB = sub_80A15D8;
}

void TilesetCb_Cave(void)
{
    void sub_80A1260(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1260;
}

void TilesetCb_EliteFour(void)
{
    void sub_80A15F0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = 128;
    sSecondaryTilesetCB = sub_80A15F0;
}

void TilesetCb_MauvilleGym(void)
{
    void sub_80A15C0(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A15C0;
}

void TilesetCb_BikeShop(void)
{
    void sub_80A161C(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A161C;
}

void TilesetCb_BattlePyramid(void)
{
    void sub_80A1634(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1634;
}

void TilesetCb_BattleDome(void)
{
    void sub_80A1658(u16);

    sSecondaryTilesetCBCounter = 0;
    sSecondaryTilesetCBBufferSize = sPrimaryTilesetCBBufferSize;
    sSecondaryTilesetCB = sub_80A1658;
}

void sub_80A103C(u16 timer)
{
    void sub_80A1434(u16, u8);
    void sub_80A1470(u16);

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

void sub_80A10B8(u16 timer)
{
    void sub_80A1520(u16);

    if ((timer & 7) == 0)
        sub_80A1520(timer >> 3);
}

void sub_80A10D0(u16 timer)
{
    void sub_80A1598(u16);

    if ((timer & 15) == 0)
        sub_80A1598(timer >> 4);
}

void sub_80A10E8(u16 timer)
{
    void sub_80A1394(u16, u8);

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

void sub_80A115C(u16 timer)
{
    void sub_80A12D4(u8);
    void sub_80A1498(u16);

    if ((timer & 0x0F) == 0)
        sub_80A12D4(timer >> 4);
    if ((timer & 0x0F) == 1)
        sub_80A1498(timer >> 4);
}

void sub_80A1188(u16 timer)
{
    void sub_80A14C0(u16, u8);

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

void sub_80A11FC(u16 timer)
{
    void sub_80A131C(u8);
    void sub_80A136C(u8);

    if ((timer & 0x0F) == 0)
        sub_80A131C(timer >> 4);
    if ((timer & 0x0F) == 1)
        sub_80A136C(timer >> 4);
}

void sub_80A122C(u16 timer)
{
    void sub_80A1798(u16);

    if ((timer & 0x0F) == 0)
        sub_80A1798(timer >> 4);
}

void sub_80A1244(u16 timer)
{
    void sub_80A1344(u8);

    if ((timer & 0x0F) == 0)
        sub_80A1344(timer >> 4);
}

void sub_80A1260(u16 timer)
{
    void sub_80A14F8(u16);

    if ((timer & 0x0F) == 1)
        sub_80A14F8(timer >> 4);
}

void sub_80A127C(u16 timer)
{
    void sub_80A1548(u16);

    if ((timer & 0x07) == 0)
        sub_80A1548(timer >> 3);
}

void sub_80A1294(u16 timer)
{
    void sub_80A1570(u16);

    if ((timer & 0x07) == 0)
        sub_80A1570(timer >> 3);
}

void sub_80A12AC(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08513684[idx], (u16 *)(VRAM + 0x3c00), 0x140);
}

void sub_80A12D4(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08513894[idx], (u16 *)(VRAM + 0x6400), 0x80);

    idx = (timer + 2) % 4;
    sub_80A0980(gUnknown_08513894[idx], (u16 *)(VRAM + 0x6480), 0x80);
}

void sub_80A131C(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_085143E4[idx], (u16 *)(VRAM + 0x7a00), 0x3C0);
}

void sub_80A1344(u8 timer)
{
    u8 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_085145F4[idx], (u16 *)(VRAM + 0x7e00), 0x80);
}

void sub_80A136C(u8 timer)
{
    u8 idx;

    idx = timer % 8;
    sub_80A0980(gUnknown_08514E04[idx], (u16 *)(VRAM + 0x7e00), 0x100);
}

void sub_80A1394(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    if (timer_div < 12) // almost certainly a typo
    {
        timer_div %= 12;
        sub_80A0980(gUnknown_08515384[timer_div], gUnknown_08515344[timer_mod], 0x80);
        sub_80A0980(gUnknown_085153B4[timer_div], gUnknown_08515364[timer_mod], 0x80);
    }
    else
    {
        timer_div %= 4;
        sub_80A0980(gUnknown_085153E4[timer_div], gUnknown_08515344[timer_mod], 0x80);
        sub_80A0980(gUnknown_085153F4[timer_div], gUnknown_08515364[timer_mod], 0x80);
    }
}

void sub_80A1434(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= 8;
    if (gUnknown_08515824[timer_div])
        sub_80A0980(gUnknown_08515824[timer_div], gUnknown_08515804[timer_mod], 0x80);
}

void sub_80A1470(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    sub_80A0980(gUnknown_08515964[idx], (u16 *)(VRAM + 0x7800), 0x80);
}

void sub_80A1498(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08515D8C[idx], (u16 *)(VRAM + 0x5400), 0x80);
}

void sub_80A14C0(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= 8;

    sub_80A0980(gUnknown_085161DC[timer_div], gUnknown_085161BC[timer_mod], 0x80);
}

void sub_80A14F8(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08515D8C[idx], (u16 *)(VRAM + 0x7400), 0x80);
}

void sub_80A1520(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_085164FC[idx], (u16 *)(VRAM + 0x5540), 0xC0);
}

void sub_80A1548(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_0851680C[idx], (u16 *)(VRAM + 0x5b40), 0xC0);
}

void sub_80A1570(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08516B1C[idx], (u16 *)(VRAM + 0x5b40), 0xC0);
}

void sub_80A1598(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08516D2C[idx], (u16 *)(VRAM + 0x5c00), 0x80);
}

void sub_80A15C0(u16 timer)
{
    void sub_80A1748(u16);

    if ((timer & 1) == 0)
        sub_80A1748(timer >> 1);
}

void sub_80A15D8(u16 timer)
{
    void sub_80A16B0(u16);

    if ((timer & 7) == 0)
        sub_80A16B0(timer >> 3);
}

void sub_80A15F0(u16 timer)
{
    void sub_80A1720(u16);
    void sub_80A16F8(u16);

    if ((timer & 0x3f) == 1)
        sub_80A1720(timer >> 6);
    if ((timer & 0x07) == 1)
        sub_80A16F8(timer >> 3);
}
void sub_80A161C(u16 timer)
{
    void sub_80A1770(u16);

    if ((timer & 3) == 0)
        sub_80A1770(timer >> 2);
}

void sub_80A1634(u16 timer)
{
    void sub_80A17C0(u16);
    void sub_80A17EC(u16);

    if ((timer & 7) == 0)
    {
        sub_80A17C0(timer >> 3);
        sub_80A17EC(timer >> 3);
    }
}

void sub_80A1658(u16 timer)
{
    void sub_80A1818(u16);

    if ((timer & 3) == 0)
        sub_80A1818(timer >> 2);
}

void sub_80A1670(u16 timer)
{
    void sub_80A1884(u16);

    if ((timer & 3) == 0)
        sub_80A1884(timer >> 2);
}

void sub_80A1688(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    sub_80A0980(gUnknown_08516E3C[idx], (u16 *)(VRAM + 0x3e00), 0x80);
}

void sub_80A16B0(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    sub_80A0980(gUnknown_08517A44[idx], (u16 *)(VRAM + 0x7e00), 0x180);
    sub_80A0980(gUnknown_08517A50[idx], (u16 *)(VRAM + 0x7a00), 0x280);
}

void sub_80A16F8(u16 timer)
{
    u16 idx;

    idx = timer % 4;
    sub_80A0980(gUnknown_08517BFC[idx], (u16 *)(VRAM + 0x7f00), 0x20);
}

void sub_80A1720(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    sub_80A0980(gUnknown_08517C0C[idx], (u16 *)(VRAM + 0x7c00), 0x80);
}

void sub_80A1748(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    sub_80A0980(gUnknown_08518034[idx], (u16 *)(VRAM + 0x5200), 0x200);
}

void sub_80A1770(u16 timer)
{
    u16 idx;

    idx = timer % 2;
    sub_80A0980(gUnknown_0851829C[idx], (u16 *)(VRAM + 0x7e00), 0x120);
}

void sub_80A1798(u16 timer)
{
    u16 idx;

    idx = timer % 8;
    sub_80A0980(gUnknown_085202C4[idx], (u16 *)(VRAM + 0x5e00), 0xc00);
}

void sub_80A17C0(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    sub_80A0980(gUnknown_08524864[idx], (u16 *)(VRAM + 0x52e0), 0x100);
}

void sub_80A17EC(u16 timer)
{
    u16 idx;

    idx = timer % 3;
    sub_80A0980(gUnknown_08524870[idx], (u16 *)(VRAM + 0x50e0), 0x100);
}

// palette

void sub_80A1818(u16 a1)
{
    CpuCopy16(gUnknown_0852487C[a1 & 0x3], gPlttBufferUnfaded + 0x80, 32);
    BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if ((u8)FindTaskIdByFunc(sub_8149DFC) != 0xFF )
    {
        sSecondaryTilesetCB = sub_80A1670;
        sSecondaryTilesetCBBufferSize = 0x20;
    }
}

void sub_80A1884(u16 a1)
{
    CpuCopy16(gUnknown_0852487C[a1 & 0x3], gPlttBufferUnfaded + 0x80, 32);
    if ((u8)FindTaskIdByFunc(sub_8149DFC) == 0xFF )
    {
        BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetCBBufferSize)
            sSecondaryTilesetCB = NULL;
    }
}

void LoadCompressedPalette(const void *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferUnfaded + offset, size);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferFaded + offset, size);
}

void LoadPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void FillPalette(u16 value, u16 offset, u16 size)
{
    CpuFill16(value, gPlttBufferUnfaded + offset, size);
    CpuFill16(value, gPlttBufferFaded + offset, size);
}

void TransferPlttBuffer(void)
{
    if (!gPaletteFade.bufferTransferDisabled)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
    }
}

u8 UpdatePaletteFade(void)
{
    u8 result;
    u8 dummy = 0;

    if (sPlttBufferTransferPending)
        return -1;

    if (gPaletteFade.mode == NORMAL_FADE)
        result = UpdateNormalPaletteFade();
    else if (gPaletteFade.mode == FAST_FADE)
        result = UpdateFastPaletteFade();
    else
        result = UpdateHardwarePaletteFade();

    sPlttBufferTransferPending = gPaletteFade.multipurpose1 | dummy;

    return result;
}

void ResetPaletteFade(void)
{
    u8 i;

    for (i = 0; i < 16; i++)
        ResetPaletteStruct(i);

    ResetPaletteFadeControl();
}

void ReadPlttIntoBuffers(void)
{
    u16 i;
    u16 *pltt = (u16 *)PLTT;

    for (i = 0; i < PLTT_SIZE / 2; i++)
    {
        gPlttBufferUnfaded[i] = pltt[i];
        gPlttBufferFaded[i] = pltt[i];
    }
}

bool8 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor)
{
    u8 temp;
    register u32 _blendColor asm("r8") = blendColor;

    if (gPaletteFade.active)
    {
        return FALSE;
    }
    else
    {
        gPaletteFade.deltaY = 2;

        if (delay < 0)
        {
            gPaletteFade.deltaY += (delay * -1);
            delay = 0;
        }

        gPaletteFade_selectedPalettes = selectedPalettes;
        gPaletteFade.delayCounter = delay;
        gPaletteFade_delay = delay;
        gPaletteFade.y = startY;
        gPaletteFade.targetY = targetY;
        gPaletteFade.blendColor = _blendColor;
        gPaletteFade.active = 1;
        gPaletteFade.mode = NORMAL_FADE;

        if (startY < targetY)
            gPaletteFade.yDec = 0;
        else
            gPaletteFade.yDec = 1;

        UpdatePaletteFade();

        temp = gPaletteFade.bufferTransferDisabled;
        gPaletteFade.bufferTransferDisabled = 0;
        CpuCopy32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
        gPaletteFade.bufferTransferDisabled = temp;
        return TRUE;
    }
}

bool8 unref_sub_80A1C1C(u32 a1, u8 a2, u8 a3, u8 a4, u16 a5)
{
    ReadPlttIntoBuffers();
    return BeginNormalPaletteFade(a1, a2, a3, a4, a5);
}

void unref_sub_80A1C64(u8 a1, u32 *a2)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        struct PaletteStruct *palstruct = &sPaletteStructs[i];
        if (palstruct->ps_field_4_0)
        {
            if (palstruct->base->pst_field_8_0 == a1)
            {
                u8 val1 = palstruct->srcIndex;
                u8 val2 = palstruct->base->srcCount;
                if (val1 == val2)
                {
                    unused_sub_80A1F00(palstruct);
                    if (!palstruct->ps_field_4_0)
                        continue;
                }
                if (palstruct->ps_field_8 == 0)
                    unused_sub_80A1CDC(palstruct, a2);
                else
                    palstruct->ps_field_8--;

                unused_sub_80A1E40(palstruct, a2);
            }
        }
    }
}

static void unused_sub_80A1CDC(struct PaletteStruct *a1, u32 *a2)
{
    s32 srcIndex;
    s32 srcCount;
    u8 i = 0;
    u16 srcOffset = a1->srcIndex * a1->base->size;

    if (!a1->base->pst_field_8_0)
    {
        while (i < a1->base->size)
        {
            gPlttBufferUnfaded[a1->destOffset] = a1->base->src[srcOffset];
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }
    else
    {
        while (i < a1->base->size)
        {
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }

    a1->destOffset = a1->baseDestOffset;
    a1->ps_field_8 = a1->base->pst_field_A;
    a1->srcIndex++;

    srcIndex = a1->srcIndex;
    srcCount = a1->base->srcCount;

    if (srcIndex >= srcCount)
    {
        if (a1->ps_field_9)
            a1->ps_field_9--;
        a1->srcIndex = 0;
    }

    *a2 |= 1 << (a1->baseDestOffset >> 4);
}

static void unused_sub_80A1E40(struct PaletteStruct *a1, u32 *a2)
{
    if (gPaletteFade.active && ((1 << (a1->baseDestOffset >> 4)) & gPaletteFade_selectedPalettes))
    {
        if (!a1->base->pst_field_8_0)
        {
            if (gPaletteFade.delayCounter != gPaletteFade_delay)
            {
                BlendPalette(
                    a1->baseDestOffset,
                    a1->base->size,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            }
        }
        else
        {
            if (!gPaletteFade.delayCounter)
            {
                if (a1->ps_field_8 != a1->base->pst_field_A)
                {
                    u32 srcOffset = a1->srcIndex * a1->base->size;
                    u8 i;

                    for (i = 0; i < a1->base->size; i++)
                        gPlttBufferFaded[a1->baseDestOffset + i] = a1->base->src[srcOffset + i];
                }
            }
        }
    }
}

static void unused_sub_80A1F00(struct PaletteStruct *a1)
{
    if (!a1->ps_field_9)
    {
        s32 val = a1->base->pst_field_B_5;

        if (!val)
        {
            a1->srcIndex = 0;
            a1->ps_field_8 = a1->base->pst_field_A;
            a1->ps_field_9 = a1->base->pst_field_C;
            a1->destOffset = a1->baseDestOffset;
        }
        else
        {
            if (val < 0)
                return;
            if (val > 2)
                return;
            ResetPaletteStructByUid(a1->base->uid);
        }
    }
    else
    {
        a1->ps_field_9--;
    }
}

void ResetPaletteStructByUid(u16 a1)
{
    u8 paletteNum = GetPaletteNumByUid(a1);
    if (paletteNum != 16)
        ResetPaletteStruct(paletteNum);
}

void ResetPaletteStruct(u8 paletteNum)
{
    sPaletteStructs[paletteNum].base = &gDummyPaletteStructTemplate;
    sPaletteStructs[paletteNum].ps_field_4_0 = 0;
    sPaletteStructs[paletteNum].baseDestOffset = 0;
    sPaletteStructs[paletteNum].destOffset = 0;
    sPaletteStructs[paletteNum].srcIndex = 0;
    sPaletteStructs[paletteNum].ps_field_4_1 = 0;
    sPaletteStructs[paletteNum].ps_field_8 = 0;
    sPaletteStructs[paletteNum].ps_field_9 = 0;
}

void ResetPaletteFadeControl(void)
{
    gPaletteFade.multipurpose1 = 0;
    gPaletteFade.multipurpose2 = 0;
    gPaletteFade.delayCounter = 0;
    gPaletteFade.y = 0;
    gPaletteFade.targetY = 0;
    gPaletteFade.blendColor = 0;
    gPaletteFade.active = 0;
    gPaletteFade.multipurpose2 = 0; // assign same value twice
    gPaletteFade.yDec = 0;
    gPaletteFade.bufferTransferDisabled = 0;
    gPaletteFade.shouldResetBlendRegisters = 0;
    gPaletteFade.hardwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishingCounter = 0;
    gPaletteFade.objPaletteToggle = 0;
    gPaletteFade.deltaY = 2;
}

void unref_sub_80A2048(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 1;
}

void unref_sub_80A2074(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 0;
}

static u8 GetPaletteNumByUid(u16 uid)
{
    u8 i;

    for (i = 0; i < 16; i++)
        if (sPaletteStructs[i].base->uid == uid)
            return i;

    return 16;
}

static u8 UpdateNormalPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gPaletteFade.active)
        return 0;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gPaletteFade.active;
    }
    else
    {
        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.delayCounter < gPaletteFade_delay)
            {
                gPaletteFade.delayCounter++;
                return 2;
            }
            gPaletteFade.delayCounter = 0;
        }

        paletteOffset = 0;

        if (!gPaletteFade.objPaletteToggle)
        {
            selectedPalettes = gPaletteFade_selectedPalettes;
        }
        else
        {
            selectedPalettes = gPaletteFade_selectedPalettes >> 16;
            paletteOffset = 256;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gPaletteFade.objPaletteToggle ^= 1;

        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.y == gPaletteFade.targetY)
            {
                gPaletteFade_selectedPalettes = 0;
                gPaletteFade.softwareFadeFinishing = 1;
            }
            else
            {
                s8 val;

                if (!gPaletteFade.yDec)
                {
                    val = gPaletteFade.y;
                    val += gPaletteFade.deltaY;
                    if (val > gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
                else
                {
                    val = gPaletteFade.y;
                    val -= gPaletteFade.deltaY;
                    if (val < gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
            }
        }

        return gPaletteFade.active;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void BeginFastPaletteFade(u8 submode)
{
    gPaletteFade.deltaY = 2;
    BeginFastPaletteFadeInternal(submode);
}

static void BeginFastPaletteFadeInternal(u8 submode)
{
    gPaletteFade.y = 31;
    gPaletteFade_submode = submode & 0x3F;
    gPaletteFade.active = 1;
    gPaletteFade.mode = FAST_FADE;

    if (submode == FAST_FADE_IN_FROM_BLACK)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    if (submode == FAST_FADE_IN_FROM_WHITE)
        CpuFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u8 UpdateFastPaletteFade(void)
{
    u16 i;
    u16 paletteOffsetStart;
    u16 paletteOffsetEnd;
    s8 r0;
    s8 g0;
    s8 b0;
    s8 r;
    s8 g;
    s8 b;

    if (!gPaletteFade.active)
        return 0;

    if (IsSoftwarePaletteFadeFinishing())
        return gPaletteFade.active;

    if (gPaletteFade.objPaletteToggle)
    {
        paletteOffsetStart = 256;
        paletteOffsetEnd = 512;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = 256;
    }

    switch (gPaletteFade_submode)
    {
    case FAST_FADE_IN_FROM_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r - 2;
            g = faded->g - 2;
            b = faded->b - 2;

            if (r < r0)
                r = r0;
            if (g < g0)
                g = g0;
            if (b < b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_WHTIE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r + 2;
            g = data->g + 2;
            b = data->b + 2;

            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_IN_FROM_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
    }

    gPaletteFade.objPaletteToggle ^= 1;

    if (gPaletteFade.objPaletteToggle)
        return gPaletteFade.active;

    if (gPaletteFade.y - gPaletteFade.deltaY < 0)
        gPaletteFade.y = 0;
    else
        gPaletteFade.y -= gPaletteFade.deltaY;

    if (gPaletteFade.y == 0)
    {
        switch (gPaletteFade_submode)
        {
        case FAST_FADE_IN_FROM_WHITE:
        case FAST_FADE_IN_FROM_BLACK:
            CpuCopy32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_WHTIE:
            CpuFill32(0xFFFFFFFF, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_BLACK:
            CpuFill32(0x00000000, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gPaletteFade.mode = NORMAL_FADE;
        gPaletteFade.softwareFadeFinishing = 1;
    }

    return gPaletteFade.active;
}

void BeginHardwarePaletteFade(u8 blendCnt, u8 delay, u8 y, u8 targetY, u8 shouldResetBlendRegisters)
{
    gPaletteFade_blendCnt = blendCnt;
    gPaletteFade.delayCounter = delay;
    gPaletteFade_delay = delay;
    gPaletteFade.y = y;
    gPaletteFade.targetY = targetY;
    gPaletteFade.active = 1;
    gPaletteFade.mode = HARDWARE_FADE;
    gPaletteFade.shouldResetBlendRegisters = shouldResetBlendRegisters & 1;
    gPaletteFade.hardwareFadeFinishing = 0;

    if (y < targetY)
        gPaletteFade.yDec = 0;
    else
        gPaletteFade.yDec = 1;
}

static u8 UpdateHardwarePaletteFade(void)
{
    if (!gPaletteFade.active)
        return 0;

    if (gPaletteFade.delayCounter < gPaletteFade_delay)
    {
        gPaletteFade.delayCounter++;
        return 2;
    }

    gPaletteFade.delayCounter = 0;

    if (!gPaletteFade.yDec)
    {
        gPaletteFade.y++;
        if (gPaletteFade.y > gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y--;
        }
    }
    else
    {
        s32 y = gPaletteFade.y--;
        if (y - 1 < gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y++;
        }
    }

    if (gPaletteFade.hardwareFadeFinishing)
    {
        if (gPaletteFade.shouldResetBlendRegisters)
        {
            gPaletteFade_blendCnt = 0;
            gPaletteFade.y = 0;
        }
        gPaletteFade.shouldResetBlendRegisters = 0;
    }

    return gPaletteFade.active;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gPaletteFade_blendCnt);
    SetGpuReg(REG_OFFSET_BLDY, gPaletteFade.y);
    if (gPaletteFade.hardwareFadeFinishing)
    {
        gPaletteFade.hardwareFadeFinishing = 0;
        gPaletteFade.mode = 0;
        gPaletteFade_blendCnt = 0;
        gPaletteFade.y = 0;
        gPaletteFade.active = 0;
    }
}

static bool8 IsSoftwarePaletteFadeFinishing(void)
{
    if (gPaletteFade.softwareFadeFinishing)
    {
        if (gPaletteFade.softwareFadeFinishingCounter == 4)
        {
            gPaletteFade.active = 0;
            gPaletteFade.softwareFadeFinishing = 0;
            gPaletteFade.softwareFadeFinishingCounter = 0;
        }
        else
        {
            gPaletteFade.softwareFadeFinishingCounter++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void BlendPalettes(u32 selectedPalettes, u8 coeff, u16 color)
{
    u16 paletteOffset;

    for (paletteOffset = 0; selectedPalettes; paletteOffset += 16)
    {
        if (selectedPalettes & 1)
            BlendPalette(paletteOffset, 16, coeff, color);
        selectedPalettes >>= 1;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

void TintPalette_GrayScale(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        *palette++ = gray << 10 | gray << 5 | gray;
    }
    return;
}

void TintPalette_GrayScale2(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        if ((u32)gray > 0x1F)
            gray = 0x1F;
        
        gray = gUnknown_0852489C[gray];
        
        *palette++ = gray << 10 | gray << 5 | gray;
    }
    return;
}

#ifdef NONMATCHING
void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    s32 r;
    s32 g;
    s32 b;
    u32 gray;
    u32 sepia;
    s8 r2;
    s8 g2;
    s8 b2;
    
    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = (s32)(r >> 8);
        
        sepia = (gray * 0x133);
        
        r2 = (u16)sepia >> 8;
        
        g2 = gray;
        
        b2 = (gray * 15);
        
        if (r2 > 0x1F)
            r2 = 0x1F;
        
        *palette++ = b2 << 10 | g2 << 5 | r2;
    }
    return;
}
#else
__attribute__((naked))
void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    asm("push {r4-r7,lr}\n\
    add r5, r0, #0\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    cmp r1, #0\n\
    beq _080A2BA2\n\
    mov r7, #0x1F\n\
    add r6, r1, #0\n\
_080A2B50:\n\
    ldrh r0, [r5]\n\
    mov r1, #0x1F\n\
    and r1, r0\n\
    lsl r0, #16\n\
    lsr r2, r0, #21\n\
    and r2, r7\n\
    lsr r3, r0, #26\n\
    and r3, r7\n\
    mov r0, #0x4C\n\
    mul r1, r0\n\
    mov r0, #0x97\n\
    mul r0, r2\n\
    add r1, r0\n\
    lsl r0, r3, #3\n\
    sub r0, r3\n\
    lsl r0, #2\n\
    add r0, r3\n\
    add r1, r0\n\
    asr r1, #8\n\
    ldr r0, =0x00000133\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r2, r0, #24\n\
    lsl r0, r1, #24\n\
    lsr r4, r0, #24\n\
    lsl r0, r1, #4\n\
    sub r0, r1\n\
    lsl r0, #20\n\
    lsr r3, r0, #24\n\
    cmp r2, #0x1F\n\
    ble _080A2B90\n\
    mov r2, #0x1F\n\
_080A2B90:\n\
    lsl r0, r3, #10\n\
    lsl r1, r4, #5\n\
    orr r0, r1\n\
    orr r0, r2\n\
    strh r0, [r5]\n\
    add r5, #0x2\n\
    sub r6, #0x1\n\
    cmp r6, #0\n\
    bne _080A2B50\n\
_080A2BA2:\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

#ifdef NONMATCHING
void sub_80A2BAC(u16 *palette, u16 count, u16 a3, u16 a4, u16 a5)
{
    s32 r;
    s32 g;
    s32 b;
    s32 gray;
    u8 r2;
    u8 g2;
    u8 b2;

    int i;
    for (i = 0; i < count; i++)
    {
        r = *palette & 0x1F;
        g = (*palette >> 5) & 0x1F;
        b = (*palette >> 10) & 0x1F;
        
        r *= 0x4C;
        r += g * 0x97;
        r += b * 0x1D;
        
        gray = r >> 8;
        
        r2 = (u16)(gray * a3) >> 8;
        
        g2 = (u16)(gray * a4) >> 8;
        
        b2 = (u16)(gray * a5) >> 8;
        
        if (r2 > 0x1F)
            r2 = 0x1F;
        
        if (g2 > 0x1F)
            g2 = 0x1F;
        
        if (b2 > 0x1F)
            b2 = 0x1F;
        
        *palette++ = b2 << 10 | g2 << 5 | r2;
    }
    return;
}
#else
__attribute__((naked))
void sub_80A2BAC(u16 *palette, u16 count, u16 a3, u16 a4, u16 a5)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    add r5, r0, #0\n\
    ldr r0, [sp, #0x1C]\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    lsl r2, #16\n\
    lsr r2, #16\n\
    mov r9, r2\n\
    lsl r3, #16\n\
    lsr r3, #16\n\
    mov r8, r3\n\
    lsl r0, #16\n\
    lsr r0, #16\n\
    mov r12, r0\n\
    cmp r1, #0\n\
    beq _080A2C38\n\
    mov r7, #0x1F\n\
    add r6, r1, #0\n\
_080A2BD6:\n\
    ldrh r0, [r5]\n\
    mov r1, #0x1F\n\
    and r1, r0\n\
    lsl r0, #16\n\
    lsr r2, r0, #21\n\
    and r2, r7\n\
    lsr r3, r0, #26\n\
    and r3, r7\n\
    mov r0, #0x4C\n\
    mul r1, r0\n\
    mov r0, #0x97\n\
    mul r0, r2\n\
    add r1, r0\n\
    lsl r0, r3, #3\n\
    sub r0, r3\n\
    lsl r0, #2\n\
    add r0, r3\n\
    add r1, r0\n\
    asr r1, #8\n\
    mov r0, r9\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r4, r0, #24\n\
    mov r0, r8\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r2, r0, #24\n\
    mov r0, r12\n\
    mul r0, r1\n\
    lsl r0, #16\n\
    lsr r3, r0, #24\n\
    cmp r4, #0x1F\n\
    ble _080A2C1A\n\
    mov r4, #0x1F\n\
_080A2C1A:\n\
    cmp r2, #0x1F\n\
    ble _080A2C20\n\
    mov r2, #0x1F\n\
_080A2C20:\n\
    cmp r3, #0x1F\n\
    ble _080A2C26\n\
    mov r3, #0x1F\n\
_080A2C26:\n\
    lsl r0, r3, #10\n\
    lsl r1, r2, #5\n\
    orr r0, r1\n\
    orr r0, r4\n\
    strh r0, [r5]\n\
    add r5, #0x2\n\
    sub r6, #0x1\n\
    cmp r6, #0\n\
    bne _080A2BD6\n\
_080A2C38:\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0");
}
#endif

void sub_80A2C44(u32 a1, s8 a2, u8 a3, u8 a4, u16 a5, u8 a6, u8 a7)
{
    u8 taskId;

    taskId = CreateTask((void *)sub_80A2D54, a6);
    gTasks[taskId].data[0] = a3;
    gTasks[taskId].data[1] = a4;

    if (a2 >= 0)
    {
        gTasks[taskId].data[3] = a2;
        gTasks[taskId].data[2] = 1;
    }
    else
    {
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[2] = -a2 + 1;
    }

    if (a4 < a3)
        gTasks[taskId].data[2] *= -1;

    SetWordTaskArg(taskId, 5, a1);
    gTasks[taskId].data[7] = a5;
    gTasks[taskId].data[8] = a7;
    gTasks[taskId].func(taskId);
}

u32 sub_80A2CF8(u8 var)
{
    int i;

    for (i = 0; i < NUM_TASKS; i++) // check all the tasks.
        if ((gTasks[i].isActive == TRUE) && (gTasks[i].func == sub_80A2D54) && (gTasks[i].data[8] == var))
            return TRUE;

    return FALSE;
}

void sub_80A2D34(void)
{
    u8 taskId;

    while (1)
    {
        taskId = FindTaskIdByFunc(sub_80A2D54);
        if (taskId == 0xFF)
            break;
        DestroyTask(taskId);
    }
}

void sub_80A2D54(u8 taskId)
{
    u32 wordVar;
    s16 *data;
    u16 temp;

    data = gTasks[taskId].data;
    wordVar = GetWordTaskArg(taskId, 5);

    if (++data[4] > data[3])
    {
        data[4] = 0;
        BlendPalettes(wordVar, data[0], data[7]);
        temp = data[1];
        if (data[0] == (s16)temp)
        {
            DestroyTask(taskId);
        }
        else
        {
            data[0] += data[2];
            if (data[2] >= 0)
            {
                if (data[0] < (s16)temp)
                {
                    return;
                }
            }
            else if (data[0] > (s16)temp)
            {
                return;
            }
            data[0] = temp;
        }
    }
}

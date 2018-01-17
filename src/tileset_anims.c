
// Includes
#include "global.h"
#include "palette.h"
#include "blend_palette.h"
#include "battle_transition.h"
#include "task.h"
#include "battle_transition.h"

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


const u16 gUnknown_085105C4[] = INCBIN_U16("data/tilesets/primary/general/anim/0/1.4bpp");

const u16 gUnknown_08510644[] = INCBIN_U16("data/tilesets/primary/general/anim/0/0.4bpp");

const u16 gUnknown_085106C4[] = INCBIN_U16("data/tilesets/primary/general/anim/0/2.4bpp");

const u16 tileset_anims_space_0[16] = {};

const u16 *const gTilesetAnims_General0[] = {
    gUnknown_08510644,
    gUnknown_085105C4,
    gUnknown_08510644,
    gUnknown_085106C4
};

const u16 gUnknown_08510774[] = INCBIN_U16("data/tilesets/primary/general/anim/1/0.4bpp");

const u16 gUnknown_08510B34[] = INCBIN_U16("data/tilesets/primary/general/anim/1/1.4bpp");

const u16 gUnknown_08510EF4[] = INCBIN_U16("data/tilesets/primary/general/anim/1/2.4bpp");

const u16 gUnknown_085112B4[] = INCBIN_U16("data/tilesets/primary/general/anim/1/3.4bpp");

const u16 gUnknown_08511674[] = INCBIN_U16("data/tilesets/primary/general/anim/1/4.4bpp");

const u16 gUnknown_08511A34[] = INCBIN_U16("data/tilesets/primary/general/anim/1/5.4bpp");

const u16 gUnknown_08511DF4[] = INCBIN_U16("data/tilesets/primary/general/anim/1/6.4bpp");

const u16 gUnknown_085121B4[] = INCBIN_U16("data/tilesets/primary/general/anim/1/7.4bpp");

const u16 *const gTilesetAnims_General1[] = {
    gUnknown_08510774,
    gUnknown_08510B34,
    gUnknown_08510EF4,
    gUnknown_085112B4,
    gUnknown_08511674,
    gUnknown_08511A34,
    gUnknown_08511DF4,
    gUnknown_085121B4
};

const u16 gUnknown_08512594[] = INCBIN_U16("data/tilesets/primary/general/anim/2/0.4bpp");

const u16 gUnknown_085126D4[] = INCBIN_U16("data/tilesets/primary/general/anim/2/1.4bpp");

const u16 gUnknown_08512814[] = INCBIN_U16("data/tilesets/primary/general/anim/2/2.4bpp");

const u16 gUnknown_08512954[] = INCBIN_U16("data/tilesets/primary/general/anim/2/3.4bpp");

const u16 gUnknown_08512A94[] = INCBIN_U16("data/tilesets/primary/general/anim/2/4.4bpp");

const u16 gUnknown_08512BD4[] = INCBIN_U16("data/tilesets/primary/general/anim/2/5.4bpp");

const u16 gUnknown_08512D14[] = INCBIN_U16("data/tilesets/primary/general/anim/2/6.4bpp");

const u16 *const gTilesetAnims_General2[] = {
    gUnknown_08512594,
    gUnknown_085126D4,
    gUnknown_08512814,
    gUnknown_08512954,
    gUnknown_08512A94,
    gUnknown_08512BD4,
    gUnknown_08512D14,
    gUnknown_08512594
};

const u16 gUnknown_08512E74[] = INCBIN_U16("data/tilesets/primary/general/anim/3/0.4bpp");

const u16 gUnknown_08512F34[] = INCBIN_U16("data/tilesets/primary/general/anim/3/1.4bpp");

const u16 gUnknown_08512FF4[] = INCBIN_U16("data/tilesets/primary/general/anim/3/2.4bpp");

const u16 gUnknown_085130B4[] = INCBIN_U16("data/tilesets/primary/general/anim/3/3.4bpp");

const u16 *const gTilesetAnims_General3[] = {
    gUnknown_08512E74,
    gUnknown_08512F34,
    gUnknown_08512FF4,
    gUnknown_085130B4
};

const u16 gUnknown_08513184[] = INCBIN_U16("data/tilesets/primary/general/anim/4/0.4bpp");

const u16 gUnknown_085132C4[] = INCBIN_U16("data/tilesets/primary/general/anim/4/1.4bpp");

const u16 gUnknown_08513404[] = INCBIN_U16("data/tilesets/primary/general/anim/4/2.4bpp");

const u16 gUnknown_08513544[] = INCBIN_U16("data/tilesets/primary/general/anim/4/3.4bpp");

const u16 *const gTilesetAnims_General4[] = {
    gUnknown_08513184,
    gUnknown_085132C4,
    gUnknown_08513404,
    gUnknown_08513544
};

const u16 gUnknown_08513694[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/0.4bpp");

const u16 gUnknown_08513714[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/1.4bpp");

const u16 gUnknown_08513794[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/2.4bpp");

const u16 gUnknown_08513814[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/3.4bpp");

const u16 *const gTilesetAnims_Lavaridge0[] = {
    gUnknown_08513694,
    gUnknown_08513714,
    gUnknown_08513794,
    gUnknown_08513814
};

const u16 gUnknown_085138A4[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/0/0.4bpp");

const u16 gUnknown_08513C64[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/0/1.4bpp");

const u16 gUnknown_08514024[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/0/2.4bpp");

const u16 *const gTilesetAnims_Pacifidlog0[] = {
    gUnknown_085138A4,
    gUnknown_08513C64,
    gUnknown_08514024,
    gUnknown_08513C64
};

const u16 gUnknown_085143F4[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/0.4bpp");

const u16 gUnknown_08514474[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/1.4bpp");

const u16 gUnknown_085144F4[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/2.4bpp");

const u16 gUnknown_08514574[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/3.4bpp");

const u16 *const gTilesetAnims_Underwater0[] = {
    gUnknown_085143F4,
    gUnknown_08514474,
    gUnknown_085144F4,
    gUnknown_08514574
};

const u16 gUnknown_08514604[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/0.4bpp");

const u16 gUnknown_08514704[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/1.4bpp");

const u16 gUnknown_08514804[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/2.4bpp");

const u16 gUnknown_08514904[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/3.4bpp");

const u16 gUnknown_08514A04[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/4.4bpp");

const u16 gUnknown_08514B04[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/5.4bpp");

const u16 gUnknown_08514C04[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/6.4bpp");

const u16 gUnknown_08514D04[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/1/7.4bpp");

const u16 *const gTilesetAnims_Pacifidlog1[] = {
    gUnknown_08514604,
    gUnknown_08514704,
    gUnknown_08514804,
    gUnknown_08514904,
    gUnknown_08514A04,
    gUnknown_08514B04,
    gUnknown_08514C04,
    gUnknown_08514D04
};

const u16 gUnknown_08514E24[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/a/0.4bpp");

const u16 gUnknown_08514EA4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/a/1.4bpp");

const u16 gUnknown_08514F24[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/a/2.4bpp");

const u16 gUnknown_08514FA4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/a/3.4bpp");

const u16 gUnknown_08515024[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/1/a/1.4bpp");

const u16 gUnknown_085150A4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/b/0.4bpp");

const u16 gUnknown_08515124[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/b/1.4bpp");

const u16 gUnknown_085151A4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/b/2.4bpp");

const u16 gUnknown_08515224[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/0/b/3.4bpp");

const u16 gUnknown_085152A4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/1/b/1.4bpp");

const u16 tileset_anims_space_1[16] = {};

u16 *const gTilesetAnims_MauvilleVDests0[] = {
    (u16 *)(BG_VRAM + 0x4c00),
    (u16 *)(BG_VRAM + 0x4c80),
    (u16 *)(BG_VRAM + 0x4d00),
    (u16 *)(BG_VRAM + 0x4d80),
    (u16 *)(BG_VRAM + 0x4e00),
    (u16 *)(BG_VRAM + 0x4e80),
    (u16 *)(BG_VRAM + 0x4f00),
    (u16 *)(BG_VRAM + 0x4f80)
};

u16 *const gTilesetAnims_MauvilleVDests1[] = {
    (u16 *)(BG_VRAM + 0x5000),
    (u16 *)(BG_VRAM + 0x5080),
    (u16 *)(BG_VRAM + 0x5100),
    (u16 *)(BG_VRAM + 0x5180),
    (u16 *)(BG_VRAM + 0x5200),
    (u16 *)(BG_VRAM + 0x5280),
    (u16 *)(BG_VRAM + 0x5300),
    (u16 *)(BG_VRAM + 0x5380)
};

const u16 *const gTilesetAnims_Mauville0a[] = {
    gUnknown_08514E24,
    gUnknown_08514E24,
    gUnknown_08514EA4,
    gUnknown_08514F24,
    gUnknown_08514FA4,
    gUnknown_08514FA4,
    gUnknown_08514FA4,
    gUnknown_08514FA4,
    gUnknown_08514FA4,
    gUnknown_08514FA4,
    gUnknown_08514F24,
    gUnknown_08514EA4
};

const u16 *const gTilesetAnims_Mauville0b[] = {
    gUnknown_085150A4,
    gUnknown_085150A4,
    gUnknown_08515124,
    gUnknown_085151A4,
    gUnknown_08515224,
    gUnknown_08515224,
    gUnknown_08515224,
    gUnknown_08515224,
    gUnknown_08515224,
    gUnknown_08515224,
    gUnknown_085151A4,
    gUnknown_08515124
};

const u16 *const gTilesetAnims_Mauville1a[] = {
    gUnknown_08514E24,
    gUnknown_08514E24,
    gUnknown_08515024,
    gUnknown_08515024
};

const u16 *const gTilesetAnims_Mauville1b[] = {
    gUnknown_085150A4,
    gUnknown_085150A4,
    gUnknown_085152A4,
    gUnknown_085152A4
};

const u16 gUnknown_08515404[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/0.4bpp");

const u16 gUnknown_08515484[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/1.4bpp");

const u16 gUnknown_08515504[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/2.4bpp");

const u16 gUnknown_08515584[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/3.4bpp");

const u16 gUnknown_08515604[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/4.4bpp");

const u16 gUnknown_08515684[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/5.4bpp");

const u16 gUnknown_08515704[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/6.4bpp");

const u16 gUnknown_08515784[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/0/7.4bpp");

u16 *const gTilesetAnims_RustboroVDests0[] = {
    (u16 *)(BG_VRAM + 0x5000),
    (u16 *)(BG_VRAM + 0x5080),
    (u16 *)(BG_VRAM + 0x5100),
    (u16 *)(BG_VRAM + 0x5180),
    (u16 *)(BG_VRAM + 0x5200),
    (u16 *)(BG_VRAM + 0x5280),
    (u16 *)(BG_VRAM + 0x5300),
    (u16 *)(BG_VRAM + 0x5380)
};

const u16 *const gTilesetAnims_Rustboro0[] = {
    gUnknown_08515404,
    gUnknown_08515484,
    gUnknown_08515504,
    gUnknown_08515584,
    gUnknown_08515604,
    gUnknown_08515684,
    gUnknown_08515704,
    gUnknown_08515784
};

const u16 gUnknown_08515844[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/1/0.4bpp");

const u16 gUnknown_085158C4[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/1/1.4bpp");

const u16 tileset_anims_space_2[16] = {};

const u16 *const gTilesetAnims_Rustboro1[] = {
    gUnknown_08515844,
    gUnknown_085158C4
};

const u16 gUnknown_0851596C[] = INCBIN_U16("data/tilesets/secondary/cave/anim/0.4bpp");

const u16 gUnknown_085159EC[] = INCBIN_U16("data/tilesets/secondary/cave/anim/1.4bpp");

const u16 gUnknown_08515A6C[] = INCBIN_U16("data/tilesets/secondary/cave/anim/2.4bpp");

const u16 gUnknown_08515AEC[] = INCBIN_U16("data/tilesets/secondary/cave/anim/3.4bpp");

const u16 gUnknown_08515B6C[] = INCBIN_U16("data/tilesets/secondary/cave/anim/unused/0.4bpp");

const u16 gUnknown_08515BEC[] = INCBIN_U16("data/tilesets/secondary/cave/anim/unused/1.4bpp");

const u16 gUnknown_08515C6C[] = INCBIN_U16("data/tilesets/secondary/cave/anim/unused/2.4bpp");

const u16 gUnknown_08515CEC[] = INCBIN_U16("data/tilesets/secondary/cave/anim/unused/3.4bpp");

const u16 tileset_anims_space_3[16] = {};

const u16 *const gTilesetAnims_Lavaridge1_Cave0[] = {
    gUnknown_0851596C,
    gUnknown_085159EC,
    gUnknown_08515A6C,
    gUnknown_08515AEC
};

const u16 gUnknown_08515D9C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/0.4bpp");

const u16 gUnknown_08515E1C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/1.4bpp");

const u16 gUnknown_08515E9C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/2.4bpp");

const u16 gUnknown_08515F1C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/3.4bpp");

const u16 gUnknown_08515F9C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/4.4bpp");

const u16 gUnknown_0851601C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/5.4bpp");

const u16 gUnknown_0851609C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/6.4bpp");

const u16 gUnknown_0851611C[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/7.4bpp");

const u16 tileset_anims_space_4[16] = {};

u16 *const gTilesetAnims_EverGrandeVDests0[] = {
    (u16 *)(BG_VRAM + 0x5c00),
    (u16 *)(BG_VRAM + 0x5c80),
    (u16 *)(BG_VRAM + 0x5d00),
    (u16 *)(BG_VRAM + 0x5d80),
    (u16 *)(BG_VRAM + 0x5e00),
    (u16 *)(BG_VRAM + 0x5e80),
    (u16 *)(BG_VRAM + 0x5f00),
    (u16 *)(BG_VRAM + 0x5f80)
};

const u16 *const gTilesetAnims_EverGrande0[] = {
    gUnknown_08515D9C,
    gUnknown_08515E1C,
    gUnknown_08515E9C,
    gUnknown_08515F1C,
    gUnknown_08515F9C,
    gUnknown_0851601C,
    gUnknown_0851609C,
    gUnknown_0851611C
};

const u16 gUnknown_085161FC[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/0.4bpp");

const u16 gUnknown_085162BC[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/1.4bpp");

const u16 gUnknown_0851637C[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/2.4bpp");

const u16 gUnknown_0851643C[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/3.4bpp");

const u16 *const gTilesetAnims_Dewford0[] = {
    gUnknown_085161FC,
    gUnknown_085162BC,
    gUnknown_0851637C,
    gUnknown_0851643C
};

const u16 gUnknown_0851650C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/0.4bpp");

const u16 gUnknown_085165CC[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/1.4bpp");

const u16 gUnknown_0851668C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/2.4bpp");

const u16 gUnknown_0851674C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest0[] = {
    gUnknown_0851650C,
    gUnknown_085165CC,
    gUnknown_0851668C,
    gUnknown_0851674C
};

const u16 gUnknown_0851681C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/0.4bpp");

const u16 gUnknown_085168DC[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/1.4bpp");

const u16 gUnknown_0851699C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/2.4bpp");

const u16 gUnknown_08516A5C[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast0[] = {
    gUnknown_0851681C,
    gUnknown_085168DC,
    gUnknown_0851699C,
    gUnknown_08516A5C
};

const u16 gUnknown_08516B2C[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/0.4bpp");

const u16 gUnknown_08516BAC[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/1.4bpp");

const u16 gUnknown_08516C2C[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/2.4bpp");

const u16 gUnknown_08516CAC[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/3.4bpp");

const u16 *const gTilesetAnims_Slateport0[] = {
    gUnknown_08516B2C,
    gUnknown_08516BAC,
    gUnknown_08516C2C,
    gUnknown_08516CAC
};

const u16 gUnknown_08516D3C[] = INCBIN_U16("data/tilesets/primary/building/anim/0.4bpp");

const u16 gUnknown_08516DBC[] = INCBIN_U16("data/tilesets/primary/building/anim/1.4bpp");

const u16 *const gTilesetAnims_InsideBuilding0[] = {
    gUnknown_08516D3C,
    gUnknown_08516DBC
};

const u16 gUnknown_08516E44[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/0/0.4bpp");

const u16 gUnknown_08516FC4[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/0/1.4bpp");

const u16 gUnknown_08517144[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/0/2.4bpp");

const u16 gUnknown_085172C4[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/1/0.4bpp");

const u16 gUnknown_08517544[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/1/1.4bpp");

const u16 gUnknown_085177C4[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/1/2.4bpp");

const u16 *const gTilesetAnims_SootopolisGym0[] = {
    gUnknown_08516E44,
    gUnknown_08516FC4,
    gUnknown_08517144
};

const u16 *const gTilesetAnims_SootopolisGym1[] = {
    gUnknown_085172C4,
    gUnknown_08517544,
    gUnknown_085177C4
};

const u16 gUnknown_08517A5C[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/1/0.4bpp");

const u16 gUnknown_08517ADC[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/1/1.4bpp");

const u16 gUnknown_08517B5C[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/0/0.4bpp");

const u16 gUnknown_08517B7C[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/0/1.4bpp");

const u16 gUnknown_08517B9C[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/0/2.4bpp");

const u16 gUnknown_08517BBC[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/0/3.4bpp");

const u16 tileset_anims_space_5[16] = {};

const u16 *const gTilesetAnims_EliteFour1[] = {
    gUnknown_08517B5C,
    gUnknown_08517B7C,
    gUnknown_08517B9C,
    gUnknown_08517BBC
};

const u16 *const gTilesetAnims_EliteFour0[] = {
    gUnknown_08517A5C,
    gUnknown_08517ADC
};

const u16 gUnknown_08517C14[] = INCBIN_U16("data/tilesets/secondary/mauville_gym/anim/0.4bpp");

const u16 gUnknown_08517E14[] = INCBIN_U16("data/tilesets/secondary/mauville_gym/anim/1.4bpp");

const u16 tileset_anims_space_6[16] = {};

const u16 *const gTilesetAnims_MauvilleGym0[] = {
    gUnknown_08517C14,
    gUnknown_08517E14
};

const u16 gUnknown_0851803C[] = INCBIN_U16("data/tilesets/secondary/bike_shop/anim/0.4bpp");

const u16 gUnknown_0851815C[] = INCBIN_U16("data/tilesets/secondary/bike_shop/anim/1.4bpp");

const u16 tileset_anims_space_7[16] = {};

const u16 *const gTilesetAnims_BikeShop0[] = {
    gUnknown_0851803C,
    gUnknown_0851815C
};

const u16 gUnknown_085182A4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/0.4bpp");

const u16 gUnknown_08518EA4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/1.4bpp");

const u16 gUnknown_08519AA4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/2.4bpp");

const u16 gUnknown_0851A6A4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/3.4bpp");

const u16 gUnknown_0851B2A4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/4.4bpp");

const u16 gUnknown_0851BEA4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/5.4bpp");

const u16 gUnknown_0851CAA4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/6.4bpp");

const u16 gUnknown_0851D6A4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/7.4bpp");

const u16 tileset_anims_space_8[16] = {};

const u16 gUnknown_0851E2C4[] = INCBIN_U16("data/tilesets/secondary/unused_1/0.4bpp");

const u16 gUnknown_0851EAC4[] = INCBIN_U16("data/tilesets/secondary/unused_1/1.4bpp");

const u16 gUnknown_0851F2C4[] = INCBIN_U16("data/tilesets/secondary/unused_1/2.4bpp");

const u16 gUnknown_0851FAC4[] = INCBIN_U16("data/tilesets/secondary/unused_1/3.4bpp");

const u16 *const gTilesetAnims_Sootopolis0[] = {
    gUnknown_085182A4,
    gUnknown_08518EA4,
    gUnknown_08519AA4,
    gUnknown_0851A6A4,
    gUnknown_0851B2A4,
    gUnknown_0851BEA4,
    gUnknown_0851CAA4,
    gUnknown_0851D6A4
};

const u16 gUnknown_085202E4[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/0/0.4bpp");

const u16 gUnknown_085203E4[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/0/1.4bpp");

const u16 gUnknown_085204E4[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/0/2.4bpp");

const u16 tileset_anims_space_9[16] = {};

const u16 gUnknown_08520604[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/1/0.4bpp");

const u16 gUnknown_08520704[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/1/1.4bpp");

const u16 gUnknown_08520804[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/1/2.4bpp");

const u16 tileset_anims_space_10[7808] = {};

const u16 gUnknown_08524604[] = INCBIN_U16("data/tilesets/secondary/unused_2/0.4bpp");

const u16 tileset_anims_space_11[224] = {};

const u16 gUnknown_08524804[] = INCBIN_U16("data/tilesets/secondary/unused_2/1.4bpp");

const u16 *const gTilesetAnims_BattlePyramid0[] = {
    gUnknown_085202E4,
    gUnknown_085203E4,
    gUnknown_085204E4
};

const u16 *const gTilesetAnims_BattlePyramid1[] = {
    gUnknown_08520604,
    gUnknown_08520704,
    gUnknown_08520804
};

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
    if ((u8)FindTaskIdByFunc(TransitionPhase1_Task_RunFuncs) != 0xFF )
    {
        sSecondaryTilesetCB = sub_80A1670;
        sSecondaryTilesetCBBufferSize = 0x20;
    }
}

static void sub_80A1884(u16 a1)
{
    CpuCopy16(gTilesetAnims_BattleDomePals0[a1 & 0x3], gPlttBufferUnfaded + 0x80, 32);
    if ((u8)FindTaskIdByFunc(TransitionPhase1_Task_RunFuncs) == 0xFF )
    {
        BlendPalette(0x80, 0x10, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetCBBufferSize)
            sSecondaryTilesetCB = NULL;
    }
}

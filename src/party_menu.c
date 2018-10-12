#include "global.h"
#include "battle_main.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/species.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "window.h"

struct Unk_Rodata1 {
    void (*unk0)(u8, u8, u8, u8, u8, u8);
    u32 unk4[7];
};

struct Unk_203CEC4 {
    TaskFunc unk0;
    void *unk4;
    u32 unk8_0:1;
    u32 unk8_1:3;
    u32 unk8_2:7;
    u32 unk9_0:7;
    u32 unkA_0:14;
    u8 unkC[3];
    u8 fillerF[9];
    u16 unk18[0xB0];
    u8 filler[0xA0];
    s16 unk218[16];
};

struct Unk_203CEC8 {
    MainCallback unk0;
    u8 filler[4];
    u8 unk8_0:4;
    u8 unk8_1:2;
    u8 unk8_2:2;
    s8 unk9;
    u8 unkA;
    u8 unkB;
};

struct Unk_203CEDC {
    struct Unk_Rodata1 *unk0;
    u32 *unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
};

struct Unk_203CEE4 {
    u8 filler[0x800];
};

// BELOW TO BE PUT IN EWRAM

extern struct Unk_203CEC4 *gUnknown_0203CEC4;
extern struct Unk_203CEC8 gUnknown_0203CEC8;
extern struct Unk_203CEDC *gUnknown_0203CEDC;
extern u8 *gUnknown_0203CEE0;
extern struct Unk_203CEE4 *gUnknown_0203CEE4;

// ABOVE TO BE PUT IN EWRAM

// BELOW TO BE CONVERTED TO C

extern struct BgTemplate gUnknown_086156B8[];
extern struct Unk_Rodata1 gUnknown_086156C4[2];
// extern struct Unk_Rodata1 gUnknown_086156E4;
extern u32 gUnknown_08615704[][6][2];

// ABOVE TO BE CONVERTED TO C

void reset_brm(void);
void c2_811EBD0(void);
bool8 sub_81B020C(void);
void sub_81B209C(void);
void sub_81B04BC(void);
bool8 sub_81B0550(void);
bool8 sub_81B05C8(void);
void sub_81B239C(u8);
void sub_81B0740(u8);
void sub_81B5D30(void);
void sub_81B6040(void);
void sub_81B6160(void);
bool8 party_menu_add_per_mon_objects(void);
bool8 sub_81B0DA0(void);
void sub_81B0F28(void);
void sub_81B2428(u8);
void display_pokemon_menu_message(u32);
void sub_81B04F8(u8);
void sub_81B06F4(void);
void sub_81B06C0(u8);
void sub_81B0CEC(u8);
void sub_81B2748(struct Unk_203CEDC *, u8);
void sub_81B2720(u8);
void sub_81B0B60(u8);
void sub_81B0B08(u8);
void sub_81B0A9C(u8);
void sub_81B0B98(u8);
void sub_81B0BC4(u8);
bool8 sub_81B0BFC(u8);
void sub_81B0948(u8);
void sub_81B0FCC(u8, u8);
void sub_81B2A70(struct Pokemon *, struct Unk_203CEDC *, u8);
void sub_81B2AC8(struct Pokemon *, struct Unk_203CEDC *, u8);
void sub_81B2B8C(struct Pokemon *, struct Unk_203CEDC *, u8);
void sub_81B2CD4(struct Pokemon *, struct Unk_203CEDC *, u8);
void sub_81B2D74(struct Pokemon *, struct Unk_203CEDC *, u8);
void sub_81B2E28(struct Pokemon *, struct Unk_203CEDC *);

void sub_81B0038(u8 a, u8 b, u8 c, u8 d, u8 e, TaskFunc f, MainCallback g)
{
    u16 i;
    
    reset_brm();
    gUnknown_0203CEC4 = Alloc(sizeof(struct Unk_203CEC4));
    if (gUnknown_0203CEC4 == 0)
    {
        SetMainCallback2(g);
    }
    else
    {
        gUnknown_0203CEC8.unk8_0 = a;
        gUnknown_0203CEC8.unk0 = g;
        gUnknown_0203CEC8.unkB = c;
        gUnknown_0203CEC4->unkA_0 = e;
        gUnknown_0203CEC4->unk0 = f;
        gUnknown_0203CEC4->unk4 = NULL;
        gUnknown_0203CEC4->unk8_1 = 0;
        gUnknown_0203CEC4->unk8_2 = 0xFF;
        gUnknown_0203CEC4->unk9_0 = 0xFF;
        
        if (a == 4)
            gUnknown_0203CEC4->unk8_0 = TRUE;
        else
            gUnknown_0203CEC4->unk8_0 = FALSE;
        
        if (b != 0xFF)
            gUnknown_0203CEC8.unk8_1 = b;
        
        for (i = 0; i <= 15; i++)
            gUnknown_0203CEC4->unk218[i] = 0;
        for (i = 0; i < 3; i++)
            gUnknown_0203CEC4->unkC[i] |= 0xFF;
        
        if (d == 0)
            gUnknown_0203CEC8.unk9 = 0;
        else if (gUnknown_0203CEC8.unk9 > 5 || GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES) == SPECIES_NONE)
            gUnknown_0203CEC8.unk9 = 0; // wut why is this else if?
        
        gTextFlags.flag_2 = 0;
        CalculatePlayerPartyCount();
        SetMainCallback2(c2_811EBD0);
    }
}

void sub_81B01B0(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_81B01CC(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void c2_811EBD0(void)
{
    while (TRUE)
    {
        if (sub_81221EC() == TRUE || sub_81B020C() == TRUE || sub_81221AC() == TRUE)
            break;
    }
}

bool8 sub_81B020C(void)
{
    switch (gMain.state)
    {
        case 0:
            SetVBlankHBlankCallbacksToNull();
            ResetVramOamAndBgCntRegs();
            clear_scheduled_bg_copies_to_vram();
            gMain.state++;
            break;
        case 1:
            ScanlineEffect_Stop();
            gMain.state++;
            break;
        case 2:
            ResetPaletteFade();
            gPaletteFade.bufferTransferDisabled = TRUE;
            gMain.state++;
            break;
        case 3:
            ResetSpriteData();
            gMain.state++;
            break;
        case 4:
            FreeAllSpritePalettes();
            gMain.state++;
            break;
        case 5:
            if (!sub_81221AC())
                ResetTasks();
            gMain.state++;
            break;
        case 6:
            sub_81B209C();
            gMain.state++;
            break;
        case 7:
            if (!sub_81B0550())
            {
                sub_81B04BC();
                return TRUE;
            }
            else
            {
                gUnknown_0203CEC4->unk218[0] = 0;
                gMain.state++;
            }
            break;
        case 8:
            if (sub_81B05C8())
                gMain.state++;
            break;
        case 9:
            sub_81B239C(gUnknown_0203CEC8.unk8_1);
            gMain.state++;
            break;
        case 10:
            sub_81B0740(gUnknown_0203CEC8.unk8_1);
            gUnknown_0203CEC4->unk218[0] = 0;
            gMain.state++;
            break;
        case 11:
            sub_81B5D30();
            gMain.state++;
            break;
        case 12:
            sub_81B6040();
            gMain.state++;
            break;
        case 13:
            sub_81B6160();
            gMain.state++;
            break;
        case 14:
            LoadMonIconPalettes();
            gMain.state++;
            break;
        case 15:
            if (party_menu_add_per_mon_objects())
            {
                gUnknown_0203CEC4->unk218[0] = 0;
                gMain.state++;
            }
            break;
        case 16:
            if (sub_81B0DA0())
            {
                gUnknown_0203CEC4->unk218[0] = 0;
                gMain.state++;
            }
            break;
        case 17:
            sub_81B0F28();
            gMain.state++;
            break;
        case 18:
            sub_81B2428(gUnknown_0203CEC4->unk8_0);
            gMain.state++;
            break;
        case 19:
            gMain.state++;
            break;
        case 20:
            CreateTask(gUnknown_0203CEC4->unk0, 0);
            display_pokemon_menu_message(gUnknown_0203CEC4->unkA_0);
            gMain.state++;
            break;
        case 21:
            BlendPalettes(0xFFFFFFFF, 16, 0);
            gPaletteFade.bufferTransferDisabled = FALSE;
            gMain.state++;
            break;
        case 22:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        default:
            SetVBlankCallback(sub_81B01CC);
            SetMainCallback2(sub_81B01B0);
            return TRUE;
    }
    return FALSE;
}

void sub_81B04BC(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(sub_81B04F8, 0);
    SetVBlankCallback(sub_81B01CC);
    SetMainCallback2(sub_81B01B0);
}

void sub_81B04F8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gUnknown_0203CEC8.unk0);
        sub_81B06F4();
        DestroyTask(taskId);
    }
}

void reset_brm(void)
{
    gUnknown_0203CEC4 = NULL;
    gUnknown_0203CEE4 = NULL;
    gUnknown_0203CEDC = NULL;
    gUnknown_0203CEE0 = NULL;
}

bool8 sub_81B0550(void)
{
    gUnknown_0203CEE4 = Alloc(sizeof(struct Unk_203CEE4));
    if (gUnknown_0203CEE4 == NULL)
        return FALSE;
    memset(gUnknown_0203CEE4, 0, sizeof(struct Unk_203CEE4));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_086156B8, 3);
    SetBgTilemapBuffer(1, gUnknown_0203CEE4);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

bool8 sub_81B05C8(void)
{
    int sizeout;
    
    switch (gUnknown_0203CEC4->unk218[0])
    {
        case 0:
            gUnknown_0203CEE0 = malloc_and_decompress(gPartyMenuMisc_Gfx, &sizeout);
            LoadBgTiles(1, gUnknown_0203CEE0, sizeout, 0);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 1:
            if (!IsDma3ManagerBusyWithBgCopy())
            {
                LZDecompressWram(gPartyMenuMisc_Tilemap, gUnknown_0203CEE4);
                gUnknown_0203CEC4->unk218[0]++;
            }
            break;
        case 2:
            LoadCompressedPalette(gPartyMenuMisc_Pal, 0, 0x160);
            CpuCopy16(gPlttBufferUnfaded, gUnknown_0203CEC4->unk18, 0x160);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 3:
            sub_81B06C0(4);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 4:
            sub_81B06C0(5);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 5:
            sub_81B06C0(6);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 6:
            sub_81B06C0(7);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        case 7:
            sub_81B06C0(8);
            gUnknown_0203CEC4->unk218[0]++;
            break;
        default:
            return TRUE;
    }
    return FALSE;
}

void sub_81B06C0(u8 offset)
{
    offset *= 16;
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferUnfaded[offset], 32);
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferFaded[offset], 32);
}

void sub_81B06F4(void)
{
    if (gUnknown_0203CEC4)
        Free(gUnknown_0203CEC4);
    if (gUnknown_0203CEE4)
        Free(gUnknown_0203CEE4);
    if (gUnknown_0203CEE0)
        Free(gUnknown_0203CEE0);
    if (gUnknown_0203CEDC)
        Free(gUnknown_0203CEDC);
    FreeAllWindowBuffers();
}

void sub_81B0740(u8 a)
{
    u8 i;
    
    gUnknown_0203CEDC = Alloc(sizeof(struct Unk_203CEDC[6]));
    
    for (i = 0; i < 6; i++)
    {
        gUnknown_0203CEDC[i].unk0 = &gUnknown_086156C4[1];
        gUnknown_0203CEDC[i].unk4 = gUnknown_08615704[a][i];
        gUnknown_0203CEDC[i].unk8 = i;
        gUnknown_0203CEDC[i].unk9 |= 0xFF;
        gUnknown_0203CEDC[i].unkA |= 0xFF;
        gUnknown_0203CEDC[i].unkB |= 0xFF;
        gUnknown_0203CEDC[i].unkC |= 0xFF;
    }
    gUnknown_0203CEDC[0].unk0 = &gUnknown_086156C4[0];
    if (a == 3)
        gUnknown_0203CEDC[3].unk0 = &gUnknown_086156C4[0];
    else if (a)
        gUnknown_0203CEDC[1].unk0 = &gUnknown_086156C4[0];
}

void sub_81B07E0(u8 a)
{
    if (gUnknown_0203CEC8.unk8_0 == 5 && a > 2)
    {
        sub_81B0CEC(a);
        if (gUnknown_02022FF8[a - 3].species == SPECIES_NONE)
            sub_81B2748(&gUnknown_0203CEDC[a], 0x40);
        else
            sub_81B2748(&gUnknown_0203CEDC[a], 8);
        CopyWindowToVram(gUnknown_0203CEDC[a].unk8, 2);
        PutWindowTilemap(gUnknown_0203CEDC[a].unk8);
        schedule_bg_copy_tilemap_to_vram(2);
    }
    else
    {
        if (GetMonData(&gPlayerParty[a], MON_DATA_SPECIES) == SPECIES_NONE)
        {
            sub_81B2720(gUnknown_0203CEDC[a].unk8);
            sub_81B2748(&gUnknown_0203CEDC[a], 0x40);
            CopyWindowToVram(gUnknown_0203CEDC[a].unk8, 2);
        }
        else
        {
            if (gUnknown_0203CEC8.unk8_0 == 7)
                sub_81B0B60(a);
            else if (gUnknown_0203CEC8.unk8_0 == 2)
                sub_81B0B08(a);
            else if (gUnknown_0203CEC8.unk8_0 == 4)
                sub_81B0A9C(a);
            else if (gUnknown_0203CEC8.unk8_0 == 11)
                sub_81B0B98(a);
            else if (gUnknown_0203CEC8.unk8_0 == 12)
                sub_81B0BC4(a);
            else if (!sub_81B0BFC(a))
                sub_81B0948(a);
            
            if (gUnknown_0203CEC8.unk8_0 == 5)
                sub_81B0FCC(a, 0);
            else if (gUnknown_0203CEC8.unk9 == a)
                sub_81B0FCC(a, 1);
            else
                sub_81B0FCC(a, 0);
        }
        PutWindowTilemap(gUnknown_0203CEDC[a].unk8);
        schedule_bg_copy_tilemap_to_vram(0);
    }
}

void sub_81B0948(u8 a)
{
    if (GetMonData(&gPlayerParty[a], MON_DATA_IS_EGG))
    {
        gUnknown_0203CEDC[a].unk0->unk0(gUnknown_0203CEDC[a].unk8, 0, 0, 0, 0, 1);
        sub_81B2A70(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
    }
    else
    {
        gUnknown_0203CEDC[a].unk0->unk0(gUnknown_0203CEDC[a].unk8, 0, 0, 0, 0, 0);
        sub_81B2A70(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
        sub_81B2AC8(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
        sub_81B2B8C(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
        sub_81B2CD4(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
        sub_81B2D74(&gPlayerParty[a], &gUnknown_0203CEDC[a], 0);
        sub_81B2E28(&gPlayerParty[a], &gUnknown_0203CEDC[a]);
    }
}

#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_pike.h"
#include "bg.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "event_data.h"
#include "field_specials.h"
#include "fldeff_softboiled.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "item_use.h"
#include "main.h"
#include "mail.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "rom_8011DC0.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

struct Unk_Rodata1 {
    void (*unk0)(u8, u8, u8, u8, u8, u8);
    u8 unk4[24];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
};

struct Unk_203CEC4 {
    TaskFunc unk0;
    MainCallback unk4;
    u32 unk8_0:1;
    u32 unk8_1:3;
    u32 unk8_2:7;
    u32 unk9_0:7;
    u32 unkA_0:14;
    u8 unkC[3];
    u8 unkF[8];
    u8 unk17;
    u16 unk18[0xB0];
    u8 filler[0xA0];
    s16 unk218[16];
};

struct Unk_203CEDC {
    struct Unk_Rodata1 *unk0;
    u8 *unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
};

struct Unk_203CEE4 {
    u8 filler[0x800];
};

struct Unk_8615C08 {
    const u8 *textPtr;
    TaskFunc func;
};

// BELOW TO BE PUT IN EWRAM

extern struct Unk_203CEC4 *gUnknown_0203CEC4;
extern struct Struct203CEC8 gUnknown_0203CEC8;
extern struct Unk_203CEDC *gUnknown_0203CEDC;
extern u8 *gUnknown_0203CEE0;
extern struct Unk_203CEE4 *gUnknown_0203CEE4;
extern u8 gUnknown_0203CEE8;
extern u16 *gUnknown_0203CEF0;
extern u16 *gUnknown_0203CEF4;
extern u8 gSelectedOrderFromParty[];
extern u8 gUnknown_0203CF20; // summary screen?

// ABOVE TO BE PUT IN EWRAM

// BELOW TO BE CONVERTED TO C

extern u32 gUnknown_08615048[]; // tutor compatibility table
extern struct BgTemplate gUnknown_086156B8[];
extern struct Unk_Rodata1 gUnknown_086156C4[2];
// extern struct Unk_Rodata1 gUnknown_086156E4;
extern u8 gUnknown_08615704[][6][8];
extern u8 gUnknown_086157C4[];
extern u8 gUnknown_086157E0[];
extern const u8 gUnknown_086157FC[][3];
extern struct WindowTemplate gUnknown_08615810[];
extern struct WindowTemplate gUnknown_08615850[];
extern struct WindowTemplate gUnknown_086158D0[];
extern struct WindowTemplate gUnknown_08615890[];
extern struct WindowTemplate gUnknown_08615908;
extern struct WindowTemplate gUnknown_08615910;
extern struct WindowTemplate gUnknown_08615918;
extern struct WindowTemplate gUnknown_08615920;
extern struct WindowTemplate gUnknown_08615928;
extern struct WindowTemplate gUnknown_08615930;
extern struct WindowTemplate gUnknown_08615938;
extern struct WindowTemplate gUnknown_08615940;
extern struct WindowTemplate gUnknown_08615948;
extern struct WindowTemplate gUnknown_08615950;
extern struct WindowTemplate gUnknown_08615958;
extern struct WindowTemplate gUnknown_08615960;
extern struct WindowTemplate gUnknown_08615968;
extern struct WindowTemplate gUnknown_08615970;
extern u8 gUnknown_08615988[];
extern u8 gUnknown_086159CE[];
extern u8 gUnknown_08615A14[];
extern u8 gUnknown_08615A4A[];
extern u8 gUnknown_08615A80[];
extern u8 gUnknown_08615AB6[];
extern u8 gUnknown_08615AB8[];
extern u8 gUnknown_08615ABA[];
extern u8 gUnknown_08615ABD[];
extern u8 gUnknown_08615AC0[];
extern u8 gUnknown_08615AC3[];
extern u8 gUnknown_08615AC5[];
extern u8 gUnknown_08615AC7[];
extern u8 gUnknown_08615AC9[];
extern u8 gUnknown_08615ACB[];
extern u8 gUnknown_08615ACD[];
extern u8 gUnknown_08615AD0[];
extern u8 gUnknown_08615AD3[];
extern u8 gUnknown_08615AD6[];
extern u8 gUnknown_08615AD9[];
extern u8 gUnknown_08615ADC[];
extern u8 gUnknown_08615ADF[];
extern u8 gUnknown_08615AE2[];
extern u8 gUnknown_08615AE5[];
extern u8 gUnknown_08615AE8[];
extern u8 gUnknown_08615AEB[];
extern u8 gUnknown_08615AEE[];
extern u8 gUnknown_08615AF1[];
extern const u8 *gUnknown_08615AF4[];
extern const u8 *gUnknown_08615B60[];
extern struct Unk_8615C08 gUnknown_08615C08[];
extern u8 *gUnknown_08615D38[];
extern u8 gUnknown_08615D70[];
extern const u16 gUnknown_08615D7E[];

// ABOVE TO BE CONVERTED TO C

extern void (*gUnknown_03006328)(u8, TaskFunc);

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
void sub_81B2FA8(u8, struct Unk_203CEDC *, u8);
u8 sub_81B8830(void);
bool8 sub_81B85AC(struct Pokemon *);
bool8 sub_81B218C(u8);
void sub_81B0C94(u8, u16, u8);
u8 sub_81B22D8(struct Pokemon *, u16, u8);
void sub_81B2A3C(u8, const u8*, u8, u8*);
void sub_81B2B40(u8, struct Unk_203CEDC *);
void sub_81B2BF4(u8, u16, u8*, struct Unk_203CEDC *);
void sub_81B2D3C(u16, struct Unk_203CEDC *);
void sub_81B2DDC(u16, struct Unk_203CEDC *);
void sub_81B2E64(u16, u16, struct Unk_203CEDC *);
void party_menu_link_mon_icon_anim(u16, u32, struct Unk_203CEDC *, u8, u8);
void party_menu_link_mon_held_item_object(u16, u16, struct Unk_203CEDC *);
void party_menu_link_mon_pokeball_object(u16, struct Unk_203CEDC *);
void party_menu_link_mon_status_condition_object(u16, u8, struct Unk_203CEDC *);
void party_menu_held_item_object(struct Pokemon *, struct Unk_203CEDC *);
void party_menu_pokeball_object(struct Pokemon *, struct Unk_203CEDC *);
void party_menu_icon_anim(struct Pokemon *, struct Unk_203CEDC *, u8);
void party_menu_status_condition_object(struct Pokemon *, struct Unk_203CEDC *);
u8 sub_81B5F74(u8, u8);
void sub_81B120C(void);
u8 sub_81B5F34(u8, u8);
void sub_81B5B6C(u8, u8);
void sub_81B5F98(u8, u8);
u8 sub_81B10F8(u8, u8);
bool8 sub_81B118C(u8);
u8 sub_81B8F38(u8);
void c3_0811FAB4(u8);
void sub_81B9080(void);
void sub_81B4F88(void);
void sub_81B15D0(u8, s8*);
void sub_81B140C(u8, s8*);
u16 sub_81B1760(s8*);
s8* sub_81B13EC(void);
bool8 sub_81B15A4(u8*);
void sub_81B302C(u8*);
void sub_81B9140(void);
void sub_81B6794(u8);
void sub_81B7E4C(u8);
void sub_81B8474(u8);
void sub_81B7FAC(u8);
void sub_81B3938(u8);
void sub_81B21AC(u8, u8);
void sub_81B36FC(u8);
void sub_81B407C(u8);
void sub_81B2210(u8);
bool8 sub_81B1660(u8);
const u8* sub_81B88BC(void);
u8 sub_81B1B5C(const u8*, u8);
void sub_81B16D4(u8);
void sub_81B334C(void);
void sub_81B1708(u8);
bool8 sub_81B1BD4(void);
void sub_81B1C1C(u8);
void sub_81B8558(void);
void sub_81B17F8(s8*, s8);
void sub_81B1854(s8*, s8);
void sub_81B195C(s8*, s8);
s8 sub_81B1B00(s8, s8);
void sub_81B3300(const u8*);
void sub_81B1B8C(u8);
void sub_81B2CD4(struct Pokemon*, struct Unk_203CEDC*, u8);
void sub_81B2E28(struct Pokemon*, struct Unk_203CEDC*);
bool16 sub_81B2134(struct Pokemon*);
bool16 sub_81B2164(struct Pokemon*);
void sub_81B2248(u8);
void sub_81B227C(u8);
bool8 sub_81B2370(u16, u8);
u16 sub_81B2360(u8);
bool8 sub_81B314C(void);
void sub_81B3414(struct Pokemon*, u8);
u8 sub_81B8A2C(struct Pokemon*);
u8 sub_81B856C(s8);
void sub_81B469C(u8);
void sub_81B3730(u8);
void sub_81B3828(void);
void pokemon_change_order(void);
void sub_81B3894(void);
void sub_81B3CC0(u8);
void sub_81B3D48(u8);
void swap_pokemon_and_oams(void);
void sub_81B3E60(u8);

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
        
        gTextFlags.autoScroll = 0;
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

void sub_81B07E0(u8 slot)
{
    if (gUnknown_0203CEC8.unk8_0 == 5 && slot > 2)
    {
        sub_81B0CEC(slot);
        if (gUnknown_02022FF8[slot - 3].species == SPECIES_NONE)
            sub_81B2748(&gUnknown_0203CEDC[slot], 0x40);
        else
            sub_81B2748(&gUnknown_0203CEDC[slot], 8);
        CopyWindowToVram(gUnknown_0203CEDC[slot].unk8, 2);
        PutWindowTilemap(gUnknown_0203CEDC[slot].unk8);
        schedule_bg_copy_tilemap_to_vram(2);
    }
    else
    {
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) == SPECIES_NONE)
        {
            sub_81B2720(gUnknown_0203CEDC[slot].unk8);
            sub_81B2748(&gUnknown_0203CEDC[slot], 0x40);
            CopyWindowToVram(gUnknown_0203CEDC[slot].unk8, 2);
        }
        else
        {
            if (gUnknown_0203CEC8.unk8_0 == 7)
                sub_81B0B60(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 2)
                sub_81B0B08(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 4)
                sub_81B0A9C(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 11)
                sub_81B0B98(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 12)
                sub_81B0BC4(slot);
            else if (!sub_81B0BFC(slot))
                sub_81B0948(slot);
            
            if (gUnknown_0203CEC8.unk8_0 == 5)
                sub_81B0FCC(slot, 0);
            else if (gUnknown_0203CEC8.unk9 == slot)
                sub_81B0FCC(slot, 1);
            else
                sub_81B0FCC(slot, 0);
        }
        PutWindowTilemap(gUnknown_0203CEDC[slot].unk8);
        schedule_bg_copy_tilemap_to_vram(0);
    }
}

void sub_81B0948(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
    {
        gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].unk8, 0, 0, 0, 0, 1);
        sub_81B2A70(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
    }
    else
    {
        gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].unk8, 0, 0, 0, 0, 0);
        sub_81B2A70(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        sub_81B2AC8(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        sub_81B2B8C(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        sub_81B2CD4(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        sub_81B2D74(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        sub_81B2E28(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
    }
}

void sub_81B0A10(u8 slot, u8 b)
{
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    
    gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].unk8, 0, 0, 0, 0, 1);
    sub_81B2A70(currentPokemon, &gUnknown_0203CEDC[slot], 0);
    if (!GetMonData(currentPokemon, MON_DATA_IS_EGG))
    {
        sub_81B2AC8(currentPokemon, &gUnknown_0203CEDC[slot], 0);
        sub_81B2B8C(currentPokemon, &gUnknown_0203CEDC[slot], 0);
    }
    sub_81B2FA8(b, &gUnknown_0203CEDC[slot], 0);
}

void sub_81B0A9C(u8 slot)
{
    u8 i;
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    u8 *ptr = gSelectedOrderFromParty;
    
    if (!sub_81B85AC(currentPokemon))
    {
        sub_81B0A10(slot, 7);
        return;
    }
    else
    {
        i = 0;
        while (i < sub_81B8830())
        {
            if (ptr[i] != 0 && (ptr[i] - 1) == slot)
            {
                sub_81B0A10(slot, i + 2);
                return;
            }
            i++;
        }
        sub_81B0A10(slot, 1);
    }
}

void sub_81B0B08(u8 slot)
{
    switch (sub_80DAE0C(&gPlayerParty[slot]))
    {
        case 0:
        case 3:
        case 4:
            sub_81B0A10(slot, 7);
            break;
        case 1:
        case 2:
            sub_81B0A10(slot, 6);
            break;
    }
}

void sub_81B0B60(u8 slot)
{
    if (GetNumberOfRelearnableMoves(&gPlayerParty[slot]) == 0)
        sub_81B0A10(slot, 9);
    else
        sub_81B0A10(slot, 8);
}

void sub_81B0B98(u8 slot)
{
    if (sub_81B218C(slot) == TRUE)
        sub_81B0A10(slot, 6);
    else
        sub_81B0A10(slot, 7);
}

void sub_81B0BC4(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM))
        sub_81B0A10(slot, 11);
    else
        sub_81B0A10(slot, 12);
}

bool8 sub_81B0BFC(u8 slot)
{
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    u16 item = gSpecialVar_ItemId;
    
    if (gUnknown_0203CEC8.unkB == 12)
    {
        gSpecialVar_Result = FALSE;
        sub_81B0C94(slot, 0, gSpecialVar_0x8005);
    }
    else
    {
        if (gUnknown_0203CEC8.unkB != 3)
            return FALSE;
        
        switch (CheckIfItemIsTMHMOrEvolutionStone(item))
        {
            default:
                return FALSE;
            case 1:
                sub_81B0C94(slot, item, 0);
                break;
            case 2:
                if (!GetMonData(currentPokemon, MON_DATA_IS_EGG) && GetEvolutionTargetSpecies(currentPokemon, 3, item) != SPECIES_NONE)
                    return FALSE;
                sub_81B0A10(slot, 0);
                break;
        }
    }
    return TRUE;
}

void sub_81B0C94(u8 slot, u16 item, u8 c)
{
    switch (sub_81B22D8(&gPlayerParty[slot], item, c))
    {
        case 1:
        case 3:
            sub_81B0A10(slot, 9);
            break;
        case 2:
            sub_81B0A10(slot, 10);
            break;
        default:
            sub_81B0A10(slot, 8);
            break;
    }
}

void sub_81B0CEC(u8 slot)
{
    struct Unk_203CEDC *structPtr = &gUnknown_0203CEDC[slot];
    u8 actualSlot = slot - 3;
    
    if (gUnknown_02022FF8[actualSlot].species == SPECIES_NONE)
    {
        sub_81B2720(structPtr->unk8);
    }
    else
    {
        structPtr->unk0->unk0(structPtr->unk8, 0, 0, 0, 0, 0);
        StringCopy(gStringVar1, gUnknown_02022FF8[actualSlot].nickname);
        StringGetEnd10(gStringVar1);
        sub_81DB52C(gStringVar1);
        sub_81B2A3C(structPtr->unk8, gStringVar1, 0, structPtr->unk0->unk4);
        sub_81B2B40(gUnknown_02022FF8[actualSlot].level, structPtr);
        sub_81B2BF4(gUnknown_02022FF8[actualSlot].gender, gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].nickname, structPtr);
        sub_81B2D3C(gUnknown_02022FF8[actualSlot].hp, structPtr);
        sub_81B2DDC(gUnknown_02022FF8[actualSlot].maxhp, structPtr);
        sub_81B2E64(gUnknown_02022FF8[actualSlot].hp, gUnknown_02022FF8[actualSlot].maxhp, structPtr);
    }
}

bool8 sub_81B0DA0(void)
{
    sub_81B07E0(gUnknown_0203CEC4->unk218[0]);
    if (++gUnknown_0203CEC4->unk218[0] == 6)
        return TRUE;
    return FALSE;
}

u8* sub_81B0DD4(u16 a)
{
    return &gUnknown_0203CEE0[a << 5];
}

void party_menu_add_per_mon_objects_internal(u8 slot)
{
    u8 actualSlot;
    
    if (gUnknown_0203CEC8.unk8_0 == 5 && slot > 2)
    {
        u8 status;
        actualSlot = slot - 3;
        
        if (gUnknown_02022FF8[actualSlot].species != SPECIES_NONE)
        {
            party_menu_link_mon_icon_anim(gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].personality, &gUnknown_0203CEDC[slot], 0, 0);
            party_menu_link_mon_held_item_object(gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].heldItem, &gUnknown_0203CEDC[slot]);
            party_menu_link_mon_pokeball_object(gUnknown_02022FF8[actualSlot].species, &gUnknown_0203CEDC[slot]);
            if (gUnknown_02022FF8[actualSlot].hp == 0)
                status = AILMENT_FNT;
            else
                status = pokemon_ailments_get_primary(gUnknown_02022FF8[actualSlot].status);
            party_menu_link_mon_status_condition_object(gUnknown_02022FF8[actualSlot].species, status, &gUnknown_0203CEDC[slot]);
        }
    }
    else if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        party_menu_icon_anim(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], slot);
        party_menu_held_item_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        party_menu_pokeball_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        party_menu_status_condition_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
    }
}

bool8 party_menu_add_per_mon_objects(void)
{
    party_menu_add_per_mon_objects_internal(gUnknown_0203CEC4->unk218[0]);
    if (++gUnknown_0203CEC4->unk218[0] == 6)
        return TRUE;
    return FALSE;
}

void sub_81B0F28(void)
{
    if (gUnknown_0203CEC8.unk8_0 == 5)
    {
        FillBgTilemapBufferRect(1, 14, 23, 17, 7, 2, 1);
    }
    else
    {
        if (gUnknown_0203CEC4->unk8_0 != FALSE)
        {
            gUnknown_0203CEC4->unk8_2 = sub_81B5F74(0xBF, 0x88);
            sub_81B120C();
            gUnknown_0203CEC4->unk9_0 = sub_81B5F74(0xBF, 0x98);
        }
        else
        {
            gUnknown_0203CEC4->unk9_0 = sub_81B5F34(0xC6, 0x94);
        }
        sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
    }
}

void sub_81B0FCC(u8 slot, u8 b)
{
    u8 spriteId;
    
    switch (slot)
    {
        default:
            if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                sub_81B2748(&gUnknown_0203CEDC[slot], sub_81B10F8(slot, b));
                sub_81B5B6C(gUnknown_0203CEDC[slot].unk9, b);
                sub_81B5F98(gUnknown_0203CEDC[slot].unkB, b);
            }
            return;
        case 6:
            if (b == 0)
                sub_8199C30(1, 23, 16, 7, 2, 1);
            else
                sub_8199C30(1, 23, 16, 7, 2, 2);
            spriteId = gUnknown_0203CEC4->unk8_2;
            break;
        case 7:
            if (!gUnknown_0203CEC4->unk8_0)
            {
                if (b == 0)
                    sub_8199C30(1, 23, 17, 7, 2, 1);
                else
                    sub_8199C30(1, 23, 17, 7, 2, 2);
            }
            else if (b == 0)
            {
                sub_8199C30(1, 23, 18, 7, 2, 1);
            }
            else
            {
                sub_8199C30(1, 23, 18, 7, 2, 2);
            }
            spriteId = gUnknown_0203CEC4->unk9_0;
            break;
    }
    sub_81B5F98(spriteId, b);
    schedule_bg_copy_tilemap_to_vram(1);
}

u8 sub_81B10F8(u8 slot, u8 b)
{
    u8 returnVar = 0;
    if (b == 1)
        returnVar = 1;
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
        returnVar |= 2;
    if (sub_81B118C(slot) == TRUE)
        returnVar |= 8;
    if (gUnknown_0203CEC8.unkB == 9)
        returnVar |= 16;
    if (gUnknown_0203CEC8.unkB == 8)
    {
        if (slot == gUnknown_0203CEC8.unk9 || slot == gUnknown_0203CEC8.unkA)
            returnVar |= 4;
    }
    if (gUnknown_0203CEC8.unkB == 10 && slot == gUnknown_0203CEC8.unk9 )
        returnVar |= 32;
    
    return returnVar;
}

bool8 sub_81B118C(u8 slot)
{
    if (gUnknown_0203CEC8.unk8_1 == 2 && (slot == 1 || slot == 4 || slot == 5))
        return TRUE;
    
    if (slot < 3 && (gBattleTypeFlags & BATTLE_TYPE_ARENA) && gMain.inBattle && (gBattleStruct->arenaLostPlayerMons >> sub_81B8F38(slot) & 1))
        return TRUE;
    
    return FALSE;
}

void sub_81B120C(void)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_086157C4, 23, 16, 7, 2, 17);
    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_086157E0, 23, 18, 7, 2, 17);
    schedule_bg_copy_tilemap_to_vram(1);
}

bool8 sub_81B1250(void)
{
    if ((gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI)) == (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI) && gMain.inBattle)
        return TRUE;
    return FALSE;
}

void sub_81B1288(struct Pokemon *partySlot, struct Pokemon *pokemon)
{
    struct Pokemon *temp = Alloc(sizeof(struct Pokemon));
    
    *temp = *partySlot;
    *partySlot = *pokemon;
    *pokemon = *temp;
    
    Free(temp);
}

void sub_81B12C0(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = c3_0811FAB4;
}

void c3_0811FAB4(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEC8.unk8_0 == 1)
            sub_81B9080();
        
        if  (gUnknown_0203CEC4->unk4 != NULL)
            SetMainCallback2(gUnknown_0203CEC4->unk4);
        else
            SetMainCallback2(gUnknown_0203CEC8.unk0);
        
        ResetSpriteData();
        sub_81B06F4();
        DestroyTask(taskId);
    }
}

u8 GetCursorSelectionMonId(void)
{
    return gUnknown_0203CEC8.unk9;
}

u8 sub_81B1360(void)
{
    return gUnknown_0203CEC8.unk8_0;
}

void sub_81B1370(u8 taskId)
{
    if (!gPaletteFade.active && sub_81221EC() != TRUE)
    {
        s8 *ptr = sub_81B13EC();
        
        switch (sub_81B1760(ptr))
        {
            case 1:
                sub_81B140C(taskId, ptr);
                break;
            case 2:
                sub_81B15D0(taskId, ptr);
                break;
            case 8:
                if (gUnknown_0203CEC4->unk8_0)
                {
                    PlaySE(SE_SELECT);
                    sub_81B4F88();
                }
        }
    }
}

s8* sub_81B13EC(void)
{
    if (gUnknown_0203CEC8.unkB == 8 || gUnknown_0203CEC8.unkB == 10)
        return &gUnknown_0203CEC8.unkA;
    return &gUnknown_0203CEC8.unk9;
}

void sub_81B140C(u8 taskId, s8 *ptr)
{
    if (*ptr == 6)
    {
        gUnknown_0203CEC8.unk4(taskId);
    }
    else
    {
        switch (gUnknown_0203CEC8.unkB - 3)
        {
            case 7:
                if (sub_81B15A4((u8*)ptr))
                {
                    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                    sub_81615A8(taskId);
                }
                break;
            case 0:
                if (sub_81B15A4((u8*)ptr))
                {
                    if (gUnknown_0203CEC8.unk8_0 == 1)
                        gUnknown_0203CEC4->unk4 = sub_81B9140;
                    
                    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                    gUnknown_03006328(taskId, sub_81B6794);
                }
                break;
            case 9:
                if (sub_81B15A4((u8*)ptr))
                {
                    PlaySE(SE_SELECT);
                    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                    sub_81B7E4C(taskId);
                }
                break;
            case 4:
                if (sub_81B15A4((u8*)ptr))
                {
                    PlaySE(SE_SELECT);
                    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                    sub_81B8474(taskId);
                }
                break;
            case 2:
            case 3:
                if (sub_81B15A4((u8*)ptr))
                {
                    PlaySE(SE_SELECT);
                    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                    sub_81B7FAC(taskId);
                }
                break;
            case 5:
                PlaySE(SE_SELECT);
                sub_81B3938(taskId);
                break;
            case 8:
                PlaySE(SE_SELECT);
                sub_81B12C0(taskId);
                break;
            case 10:
                if (sub_81B15A4((u8*)ptr))
                {
                    sub_81B21AC(taskId, (u8)*ptr);
                }
                break;
            default:
            case 1:
            case 6:
                PlaySE(SE_SELECT);
                sub_81B36FC(taskId);
                break;
        }
    }
}

bool8 sub_81B15A4(u8 *slotPtr)
{
    if (GetMonData(&gPlayerParty[*slotPtr], MON_DATA_IS_EGG) == TRUE)
    {
        PlaySE(SE_HAZURE);
        return FALSE;
    }
    return TRUE;
}

void sub_81B15D0(u8 taskId, s8 *ptr)
{
    switch (gUnknown_0203CEC8.unkB)
    {
        case 1:
            PlaySE(SE_HAZURE);
            break;
        case 8:
        case 10:
            PlaySE(SE_SELECT);
            sub_81B407C(taskId);
            break;
        case 13:
            PlaySE(SE_SELECT);
            sub_81B2210(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            if (sub_81B1660(taskId) != TRUE)
            {
                if (!sub_81221AC())
                    gSpecialVar_0x8004 = 7;
                gUnknown_0203CEE8 = 0;
                *ptr = 7;
                sub_81B12C0(taskId);
            }
            break;
    }
}    

bool8 sub_81B1660(u8 taskId)
{
    const u8* stringPtr = NULL;
    
    if (gUnknown_0203CEC8.unk8_0 == 2)
        stringPtr = gText_CancelParticipation;
    else if (gUnknown_0203CEC8.unk8_0 == 4)
        stringPtr = sub_81B88BC();
    
    if (stringPtr == NULL)
        return FALSE;
    
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    StringExpandPlaceholders(gStringVar4, stringPtr);
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B16D4;
    return TRUE;
}

void sub_81B16D4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B1708;
    }
}

void sub_81B1708(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            gUnknown_0203CEE8 = 0;
            gUnknown_0203CEC8.unk9 = 7;
            sub_81B8558();
            sub_81B12C0(taskId);
            break;
        case -1:
            PlaySE(SE_SELECT);
        case 1:
            sub_81B1C1C(taskId);
            break;
    }
}

u16 sub_81B1760(s8 *ptr)
{
    s8 r1;
    
    switch (gMain.newAndRepeatedKeys)
    {
        case DPAD_UP:
            r1 = -1;
            break;
        case DPAD_DOWN:
            r1 = 1;
            break;
        case DPAD_LEFT:
            r1 = -2;
            break;
        case DPAD_RIGHT:
            r1 = 2;
            break;
        default:
            switch (sub_812210C())
            {
                case 1:
                    r1 = -1;
                    break;
                case 2:
                    r1 = 1;
                    break;
                default:
                    r1 = 0;
                    break;
            }
    }
    
    if (gMain.newKeys & START_BUTTON)
        return 8;
    
    if (r1)
    {
        sub_81B17F8(ptr, r1);
        return 0;
    }
    
    if ((gMain.newKeys & A_BUTTON) && *ptr == 7)
        return 2;
    
    return gMain.newKeys & (A_BUTTON | B_BUTTON);
}

#ifdef NONMATCHING
void sub_81B17F8(s8 *ptr, s8 b)
{
    s8 slot = *ptr;
    
    if (!gUnknown_0203CEC8.unk8_1)
        sub_81B1854(ptr, b);
    else
        sub_81B195C(ptr, b);
    
    if (*ptr != slot)
    {
        PlaySE(SE_SELECT);
        sub_81B0FCC(slot, 0);
        sub_81B0FCC(*ptr, 1);
    }
}
#else
NAKED
void sub_81B17F8(s8 *ptr, s8 b)
{
    asm_unified("push {r4,r5,lr}\n\
	adds r5, r0, 0\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	ldrb r4, [r5]\n\
	ldr r0, =gUnknown_0203CEC8\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 26\n\
	lsrs r0, 30\n\
	cmp r0, 0\n\
	bne _081B1820\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	adds r0, r5, 0\n\
	bl sub_81B1854\n\
	b _081B182A\n\
	.pool\n\
_081B1820:\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	adds r0, r5, 0\n\
	bl sub_81B195C\n\
_081B182A:\n\
	movs r1, 0\n\
	ldrsb r1, [r5, r1]\n\
	lsls r4, 24\n\
	asrs r0, r4, 24\n\
	cmp r1, r0\n\
	beq _081B184C\n\
	movs r0, 0x5\n\
	bl PlaySE\n\
	lsrs r0, r4, 24\n\
	movs r1, 0\n\
	bl sub_81B0FCC\n\
	ldrb r0, [r5]\n\
	movs r1, 0x1\n\
	bl sub_81B0FCC\n\
_081B184C:\n\
	pop {r4,r5}\n\
	pop {r0}\n\
	bx r0\n");
}
#endif

#ifdef NONMATCHING
void sub_81B1854(s8 *ptr, s8 b)
{
    u8 r0r2;
    
    switch (b)
    {
        case -1:
            r0r2 = *ptr;
            if (*ptr == 0)
            {
                *ptr = 7;
            }
            else if (*ptr == 6)
            {
                *ptr = gPlayerPartyCount - 1;
            }
            else if (*ptr == 7)
            {
                if (gUnknown_0203CEC4->unk8_0)
                    *ptr = 6;
                else
                    *ptr = gPlayerPartyCount - 1;
            }
            else
            {
                *ptr = r0r2 - 1;
            }
            break;
        case 1:
            r0r2 = *ptr;
            if (*ptr != 7)
            {
                if ((u32)*ptr == gPlayerPartyCount - 1)
                {
                    if (gUnknown_0203CEC4->unk8_0)
                        *ptr = 6;
                    else
                        *ptr = 7;
                }
                else
                {
                    *ptr = r0r2 + 1;
                }
            }
            else
            {
                *ptr = 0;
            }
            break;
        case 2:
            if (gPlayerPartyCount != 1 && *ptr == 0)
            {
                if (gUnknown_0203CEC4->unk8_1 == 0)
                    *ptr = 1;
                else
                    *ptr = gUnknown_0203CEC4->unk8_1;
            }
            break;
        case -2:
            if (*ptr != 0 && *ptr != 6 && *ptr != 7)
            {
                gUnknown_0203CEC4->unk8_1 = *ptr;
                *ptr = 0;
            }
            break;
    }
}
#else
NAKED
void sub_81B1854(s8 *ptr, s8 b)
{
    asm_unified("push {r4,lr}\n\
	adds r4, r0, 0\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	cmp r1, r0\n\
	beq _081B187A\n\
	cmp r1, r0\n\
	bgt _081B1870\n\
	subs r0, 0x1\n\
	cmp r1, r0\n\
	beq _081B1924\n\
	b _081B1952\n\
_081B1870:\n\
	cmp r1, 0x1\n\
	beq _081B18C0\n\
	cmp r1, 0x2\n\
	beq _081B18F8\n\
	b _081B1952\n\
_081B187A:\n\
	ldrb r0, [r4]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	cmp r1, 0\n\
	bne _081B1888\n\
	movs r0, 0x7\n\
	b _081B1950\n\
_081B1888:\n\
	cmp r1, 0x6\n\
	bne _081B1898\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B1898:\n\
	cmp r1, 0x7\n\
	bne _081B18BC\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B18B0\n\
	movs r0, 0x6\n\
	b _081B1950\n\
	.pool\n\
_081B18B0:\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B18BC:\n\
	subs r0, 0x1\n\
	b _081B1950\n\
_081B18C0:\n\
	ldrb r2, [r4]\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0x7\n\
	beq _081B194E\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	cmp r1, r0\n\
	bne _081B18F4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B18F0\n\
	movs r0, 0x6\n\
	b _081B1950\n\
	.pool\n\
_081B18F0:\n\
	movs r0, 0x7\n\
	b _081B1950\n\
_081B18F4:\n\
	adds r0, r2, 0x1\n\
	b _081B1950\n\
_081B18F8:\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x1\n\
	beq _081B1952\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1952\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r0, 29\n\
	cmp r0, 0\n\
	bne _081B1950\n\
	movs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B1924:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	beq _081B1952\n\
	cmp r0, 0x6\n\
	beq _081B1952\n\
	cmp r0, 0x7\n\
	beq _081B1952\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
_081B194E:\n\
	movs r0, 0\n\
_081B1950:\n\
	strb r0, [r4]\n\
_081B1952:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .pool\n");
}
#endif

#ifdef NONMATCHING
void sub_81B195C(s8 *ptr, s8 b)
{
    u8 unk;
    s8 unk2 = b;
    u8 unk3;
    
    switch (b)
    {
        case -1:
            unk = *ptr;
            if (*ptr == 0)
            {
                *ptr = 7;
            }
            else if (*ptr == 6)
            {
                *ptr = gPlayerPartyCount - 1;
            }
            else if (*ptr == 7)
            {
                if (gUnknown_0203CEC4->unk8_0)
                {
                    *ptr = 6;
                }
                else
                {
                    *ptr = unk - 1;
                    unk2 = sub_81B1B00(*ptr, unk2);
                    if (unk2 != -1)
                        *ptr = unk2;
                }
            }
            else
            {
                unk2 = sub_81B1B00(*ptr, unk2);
                if (unk2 != -1)
                    *ptr = unk2;
            }
            break;
        case 1:
            if (*ptr == 6)
            {
                *ptr = 7;
            }
            else if (*ptr == 7)
            {
                *ptr = 0;
            }
            else
            {
                unk2 = sub_81B1B00(*ptr, 1);
                if (unk2 == -1)
                {
                    if (gUnknown_0203CEC4->unk8_0)
                        *ptr = 6;
                    else
                        *ptr = 7;
                }
                else
                {
                    *ptr = unk2;
                }
            }
            break;
        case 2:
            if (*ptr == 0)
            {
                if (gUnknown_0203CEC4->unk8_1 == 3)
                {
                    if (GetMonData(&gPlayerParty[3], MON_DATA_SPECIES) != SPECIES_NONE)
                        *ptr = 3;
                }
                else if (GetMonData(&gPlayerParty[2], MON_DATA_SPECIES) != SPECIES_NONE)
                {
                    *ptr = 2;
                }
            }
            else if (*ptr == 1)
            {
                if (gUnknown_0203CEC4->unk8_1 == 5)
                {
                    if (GetMonData(&gPlayerParty[5], MON_DATA_SPECIES) != SPECIES_NONE)
                        *ptr = 5;
                }
                else if (GetMonData(&gPlayerParty[4], MON_DATA_SPECIES) != SPECIES_NONE)
                {
                    *ptr = 4;
                }
            }
            break;
        case -2:
            unk3 = *ptr - 2;
            if (unk3 <= 1)
            {
                gUnknown_0203CEC4->unk8_1 = *ptr;
                *ptr = 0;
            }
            else 
            {
                unk3 = *ptr - 4;
                if (unk3 <= 1)
                {
                    gUnknown_0203CEC4->unk8_1 = *ptr;
                    *ptr = 1;
                }
            }
            break;
    }
}
#else
NAKED
void sub_81B195C(s8 *ptr, s8 b)
{
    asm_unified("push {r4-r6,lr}\n\
	adds r4, r0, 0\n\
	lsls r1, 24\n\
	lsrs r2, r1, 24\n\
	asrs r5, r1, 24\n\
	movs r6, 0x1\n\
	negs r6, r6\n\
	cmp r5, r6\n\
	beq _081B1988\n\
	cmp r5, r6\n\
	bgt _081B197E\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	cmp r5, r0\n\
	bne _081B197C\n\
	b _081B1A9C\n\
_081B197C:\n\
	b _081B1AF4\n\
_081B197E:\n\
	cmp r5, 0x1\n\
	beq _081B19E4\n\
	cmp r5, 0x2\n\
	beq _081B1A24\n\
	b _081B1AF4\n\
_081B1988:\n\
	ldrb r1, [r4]\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1996\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B1996:\n\
	cmp r0, 0x6\n\
	bne _081B19A8\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1AF2\n\
	.pool\n\
_081B19A8:\n\
	cmp r0, 0x7\n\
	bne _081B19C4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B19C0\n\
	movs r0, 0x6\n\
	b _081B1AF2\n\
	.pool\n\
_081B19C0:\n\
	subs r0, r1, 0x1\n\
	strb r0, [r4]\n\
_081B19C4:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	lsls r1, r2, 24\n\
	asrs r1, 24\n\
	bl sub_81B1B00\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	asrs r0, 24\n\
	movs r1, 0x1\n\
	negs r1, r1\n\
	cmp r0, r1\n\
	bne _081B19E0\n\
	b _081B1AF4\n\
_081B19E0:\n\
	strb r2, [r4]\n\
	b _081B1AF4\n\
_081B19E4:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0x6\n\
	bne _081B19F0\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B19F0:\n\
	cmp r0, 0x7\n\
	bne _081B19F8\n\
	movs r0, 0\n\
	b _081B1AF2\n\
_081B19F8:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	movs r1, 0x1\n\
	bl sub_81B1B00\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, r6\n\
	bne _081B19E0\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B1A20\n\
	movs r0, 0x6\n\
	b _081B1AF2\n\
	.pool\n\
_081B1A20:\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B1A24:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1A5C\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r6, r0, 29\n\
	cmp r6, 0x3\n\
	bne _081B1A54\n\
	ldr r0, =gPlayerParty + 300\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	strb r6, [r4]\n\
	b _081B1AF4\n\
	.pool\n\
_081B1A54:\n\
	ldr r0, =gPlayerParty + 200\n\
	b _081B1A70\n\
	.pool\n\
_081B1A5C:\n\
	cmp r0, 0x1\n\
	bne _081B1AF4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r5, r0, 29\n\
	cmp r5, 0x5\n\
	bne _081B1A88\n\
	ldr r0, =gPlayerParty + 500\n\
_081B1A70:\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	strb r5, [r4]\n\
	b _081B1AF4\n\
	.pool\n\
_081B1A88:\n\
	ldr r0, =gPlayerParty + 400\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	movs r0, 0x4\n\
	b _081B1AF2\n\
	.pool\n\
_081B1A9C:\n\
	ldrb r1, [r4]\n\
	subs r0, r1, 0x2\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bhi _081B1ACC\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
	movs r0, 0\n\
	b _081B1AF2\n\
	.pool\n\
_081B1ACC:\n\
	subs r0, r1, 0x4\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bhi _081B1AF4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
	movs r0, 0x1\n\
_081B1AF2:\n\
	strb r0, [r4]\n\
_081B1AF4:\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

s8 sub_81B1B00(s8 a, s8 b)
{
    while (TRUE)
    {
        a += b;
        if ((u8)a >= 6)
            return -1;
        if (GetMonData(&gPlayerParty[a], MON_DATA_SPECIES) != SPECIES_NONE)
            return a;
    }
}

u8* GetMonNickname(struct Pokemon *mon, u8 *dest)
{
    GetMonData(mon, MON_DATA_NICKNAME, dest);
    return StringGetEnd10(dest);
}

u8 sub_81B1B5C(const u8* str, u8 b)
{
    u8 taskId;
    
    sub_81B3300(str);
    taskId = CreateTask(sub_81B1B8C, 1);
    gTasks[taskId].data[0] = b;
    return taskId;
}

void sub_81B1B8C(u8 taskId)
{
    if (RunTextPrintersRetIsActive(6) != TRUE)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            sub_8198070(6, 0);
            ClearWindowTilemap(6);
        }
        DestroyTask(taskId);
    }
}

bool8 sub_81B1BD4(void)
{
    return FuncIsActiveTask(sub_81B1B8C);
}

void sub_81B1BE8(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        display_pokemon_menu_message(0);
        gTasks[taskId].func = sub_81B1370;
    }
}

void sub_81B1C1C(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_8198070(6, 0);
        ClearWindowTilemap(6);
        if (sub_81221AC() == TRUE)
        {
            gTasks[taskId].func = sub_81B1BE8;
        }
        else
        {
            display_pokemon_menu_message(0);
            gTasks[taskId].func = sub_81B1370;
        }
    }
}

void sub_81B1C84(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_PkmnWasGivenItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1CD0(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_RecievedItemFromPkmn);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1D1C(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1D68(u16 item, u16 item2, u8 c)
{
    CopyItemName(item, gStringVar1);
    CopyItemName(item2, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchedPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1DB8(struct Pokemon *mon, u16 item)
{
    u8 itemBytes[2];
    
    if (ItemIsMail(item) == TRUE)
    {
        if (GiveMailToMon(mon, item) == 0xFF)
            return;
    }
    itemBytes[0] = item;
    itemBytes[1] = item >> 8;
    SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
}

u8 sub_81B1E00(struct Pokemon* mon)
{
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);
    
    if (item == ITEM_NONE)
        return 0;
    if (AddBagItem(item, 1) == FALSE)
        return 1;
    
    item = ITEM_NONE;
    SetMonData(mon, MON_DATA_HELD_ITEM, &item);
    return 2;
}

void pokemon_item_not_removed(void)
{
    StringExpandPlaceholders(gStringVar4, gText_BagFullCouldNotRemoveItem);
}

void sub_81B1E60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    data[0] += data[2];
    data[3]--;
    SetMonData(&gPlayerParty[data[4]], MON_DATA_HP, &data[0]);
    sub_81B2CD4(&gPlayerParty[data[4]], &gUnknown_0203CEDC[data[4]], 1);
    sub_81B2E28(&gPlayerParty[data[4]], &gUnknown_0203CEDC[data[4]]);
    if (data[3] == 0 || data[0] == 0 || data[0] == data[1])
    {
        if (data[0] > data[5])
            ConvertIntToDecimalStringN(gStringVar2, data[0] - data[5], 0, 3);
        SwitchTaskToFollowupFunc(taskId);
    }
}

void sub_81B1F18(u8 taskId, u8 slot, s8 c, s16 HPSomething, TaskFunc func)
{
    struct Pokemon *mon = &gPlayerParty[slot];
    s16 *data = gTasks[taskId].data;
    
    data[0] = GetMonData(mon, MON_DATA_HP);
    data[1] = GetMonData(mon, MON_DATA_MAX_HP);
    data[2] = c;
    data[3] = HPSomething;
    data[4] = slot;
    data[5] = data[0];
    SetTaskFuncWithFollowupFunc(taskId, sub_81B1E60, func);
}

void sub_81B1FA8(u8 taskId, u8 b, u32 hp)
{
    s16 *data = gTasks[taskId].data;
    
    switch (b) // only case 0 is used
    {
        case 0:
            data[0] = hp;
            data[5] = hp;
            break;
        case 1:
            data[1] = hp;
            break;
        case 2:
            data[2] = hp;
            break;
        case 3:
            data[3] = hp;
            break;
        case 4:
            data[4] = hp;
            break;
        case 5:
            SetTaskFuncWithFollowupFunc(taskId, sub_81B1E60, (TaskFunc)hp); // >casting hp as a taskfunc
            break;
    }
}

u8 pokemon_ailments_get_primary(u32 status)
{
    if (status & STATUS1_PSN_ANY)
        return AILMENT_PSN;
    if (status & STATUS1_PARALYSIS)
        return AILMENT_PRZ;
    if (status & STATUS1_SLEEP)
        return AILMENT_SLP;
    if (status & STATUS1_FREEZE)
        return AILMENT_FRZ;
    if (status & STATUS1_BURN)
        return AILMENT_BRN;
    return AILMENT_NONE;
}

u8 sub_81B205C(struct Pokemon *mon)
{
    u8 ailment;
    
    if (GetMonData(mon, MON_DATA_HP) == 0)
        return AILMENT_FNT;
    ailment = pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS));
    if (ailment != AILMENT_NONE)
        return ailment;
    if (CheckPartyPokerus(mon, 0))
        return AILMENT_PKRS;
    return AILMENT_NONE;
}

void sub_81B209C(void)
{
    u16 *ptr;
    
    if (gUnknown_0203CEC8.unk8_0 == 11)
    {
        u8 i;
        
        ptr = &gUnknown_0203CEC8.unkE;
        gUnknown_0203CEC8.unkE = 0;
        if (gSpecialVar_0x8005 == 0)
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += sub_81B2134(&gPlayerParty[i]) << i;
        }
        else
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += sub_81B2164(&gPlayerParty[i]) << i;
        }
    }
}

bool16 sub_81B2134(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && sub_802C908(GetMonData(mon, MON_DATA_SPECIES)) != FALSE)
        return TRUE;
    return FALSE;
}

// Dodrio Berry Picking select?

bool16 sub_81B2164(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_DODRIO)
        return TRUE;
    return FALSE;
}

bool8 sub_81B218C(u8 slot)
{
    if (!((gUnknown_0203CEC8.unkE >> slot) & 1))
        return FALSE;
    return TRUE;
}

void sub_81B21AC(u8 taskId, u8 slot)
{
    if (sub_81B218C(slot) == TRUE)
    {
        PlaySE(SE_SELECT);
        gSpecialVar_0x8004 = slot;
        sub_81B12C0(taskId);
    }
    else
    {
        PlaySE(SE_HAZURE);
        sub_81B1B5C(gText_PkmnCantParticipate, 0);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = sub_81B1C1C;
    }
}

void sub_81B2210(u8 taskId)
{
    sub_81B1B5C(gText_CancelParticipation, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B2248;
}

void sub_81B2248(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B227C;
    }
}

void sub_81B227C(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            gSpecialVar_0x8004 = 7;
            sub_81B12C0(taskId);
            break;
        case -1:
            PlaySE(SE_SELECT);
        case 1:
            gTasks[taskId].func = sub_81B1C1C;
            break;
    }
}

u8 sub_81B22D8(struct Pokemon *mon, u16 item, u8 c)
{
    u16 move;
    
    if (GetMonData(mon, MON_DATA_IS_EGG) != FALSE)
        return 3;
    if (item >= ITEM_TM01_FOCUS_PUNCH)
    {
        if (CanMonLearnTMHM(mon, item - 33) != FALSE)
            move = ItemIdToBattleMoveId(item);
        else
            return 1;
        do {} while (0); // :morphon:
    }
    else if (sub_81B2370(GetMonData(mon, MON_DATA_SPECIES), c) == FALSE)
    {
        return 1;
    }
    else
    {
        move = sub_81B2360(c);
    }
    
    if (pokemon_has_move(mon, move) == TRUE)
        return 2;
    return 0;
}

u16 sub_81B2360(u8 tutor)
{
    return gUnknown_0861500C[tutor];
}

bool8 sub_81B2370(u16 species, u8 tutor)
{
    if (gUnknown_08615048[species] & (1 << tutor))
        return TRUE;
    return FALSE;
}

void sub_81B239C(u8 a)
{
    u8 i;
    
    switch (a)
    {
        case 0:
            InitWindows(gUnknown_08615810);
            break;
        case 1:
            InitWindows(gUnknown_08615850);
            break;
        case 2:
            InitWindows(gUnknown_08615890);
            break;
        default:
            InitWindows(gUnknown_086158D0);
            break;
    }
    DeactivateAllTextPrinters();
    for (i = 0; i < 6; i++)
        FillWindowPixelBuffer(i, 0);
    LoadUserWindowBorderGfx(0, 0x4F, 0xD0);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
}

void sub_81B2428(bool8 a)
{
    u8 firstWindowId;
    u8 windowId;
    u8 offset;
    u8 mainOffset;
    
    if (gUnknown_0203CEC8.unk8_0 != 5)
    {
        if (a == TRUE)
        {
            firstWindowId = AddWindow(&gUnknown_08615918);
            FillWindowPixelBuffer(firstWindowId, 0);
            mainOffset = GetStringCenterAlignXOffset(0, gMenuText_Confirm, 48);
            AddTextPrinterParameterized4(firstWindowId, 0, mainOffset, 1, 0, 0, gUnknown_086157FC[0], -1, gMenuText_Confirm);
            PutWindowTilemap(firstWindowId);
            CopyWindowToVram(firstWindowId, 2);
            windowId = AddWindow(&gUnknown_08615910);
            offset = 0;
        }
        else
        {
            windowId = AddWindow(&gUnknown_08615908);
            offset = 3;
        }
        FillWindowPixelBuffer(windowId, 0);
        if (gUnknown_0203CEC8.unk8_0 != 10)
        {
            mainOffset = GetStringCenterAlignXOffset(0, gText_Cancel, 48);
            AddTextPrinterParameterized3(windowId, 0, mainOffset + offset, 1, gUnknown_086157FC[0], -1, gText_Cancel);
        }
        else
        {
            mainOffset = GetStringCenterAlignXOffset(0, gText_Cancel2, 48);
            AddTextPrinterParameterized3(windowId, 0, mainOffset + offset, 1, gUnknown_086157FC[0], -1, gText_Cancel2);
        }
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, 2);
        schedule_bg_copy_tilemap_to_vram(0);
    }
}

u16* sub_81B2564(u8 a)
{
    return &gUnknown_0203CEC4->unk18[a];
}

void sub_81B2578(u8 windowId, u8 *b, u8 c, u8 x, u8 y, u8 width, u8 height)
{
    u8 *pixels = AllocZeroed(height * width * 32);
    u8 i, j;
    
    if (pixels != NULL)
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
                CpuCopy16(sub_81B0DD4(b[x + j + ((y + i) * c)]), &pixels[(i * width + j) * 32], 32);
        }
        BlitBitmapToWindow(windowId, pixels, x * 8, y * 8, width * 8, height * 8);
        Free(pixels);
    }
}

void sub_81B2658(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
{
    if (width == 0 && height == 0)
    {
        width = 10;
        height = 7;
    }
    if (f == 0)
        sub_81B2578(windowId, gUnknown_08615988, 10, x, y, width, height);
    else
        sub_81B2578(windowId, gUnknown_086159CE, 10, x, y, width, height);
}

void sub_81B26BC(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
{
    if (width == 0 && height == 0)
    {
        width = 18;
        height = 3;
    }
    if (f == 0)
        sub_81B2578(windowId, gUnknown_08615A14, 18, x, y, width, height);
    else
        sub_81B2578(windowId, gUnknown_08615A4A, 18, x, y, width, height);
}

void sub_81B2720(u8 windowId)
{
    sub_81B2578(windowId, gUnknown_08615A80, 18, 0, 0, 18, 3);
}

void sub_81B2748(struct Unk_203CEDC *ptr, u8 bitfield)
{
    u8 palNum = GetWindowAttribute(ptr->unk8, WINDOW_PALETTE_NUM) * 16;
    
    if (0x40 & bitfield)
    {
        LoadPalette(sub_81B2564(gUnknown_08615AF1[0]), gUnknown_08615AC0[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AF1[1]), gUnknown_08615AC0[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AF1[2]), gUnknown_08615AC0[2] + palNum, 2);
    }
    else if (0x20 & bitfield)
    {
        if (1 & bitfield)
        {
            LoadPalette(sub_81B2564(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(sub_81B2564(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (0x10 & bitfield)
    {
        LoadPalette(sub_81B2564(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
    else if (4 & bitfield)
    {
        if (1 & bitfield)
        {
            LoadPalette(sub_81B2564(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(sub_81B2564(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (2 & bitfield)
    {
        if (1 & bitfield)
        {
            LoadPalette(sub_81B2564(gUnknown_08615ADC[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADC[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ADC[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(sub_81B2564(gUnknown_08615AD3[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD3[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD3[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE8[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE8[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE8[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (8 & bitfield)
    {
        if (1 & bitfield)
        {
            LoadPalette(sub_81B2564(gUnknown_08615AD9[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD9[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD9[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(sub_81B2564(gUnknown_08615AD0[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD0[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AD0[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE5[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE5[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AE5[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (1 & bitfield)
    {
        LoadPalette(sub_81B2564(gUnknown_08615AD6[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AD6[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AD6[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
    else
    {
        LoadPalette(sub_81B2564(gUnknown_08615ACD[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615ACD[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615ACD[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AE2[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AE2[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(sub_81B2564(gUnknown_08615AE2[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
}

void sub_81B2A3C(u8 windowId, const u8 *str, u8 color, u8 *ptr)
{
    AddTextPrinterParameterized3(windowId, 0, ptr[0], ptr[1], gUnknown_086157FC[color], 0, str);
}

void sub_81B2A70(struct Pokemon *mon, struct Unk_203CEDC *ptr, u8 c)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c == 1)
            ptr->unk0->unk0(ptr->unk8, ptr->unk0->unk4[0] >> 3, ptr->unk0->unk4[1] >> 3, ptr->unk0->unk4[2] >> 3, ptr->unk0->unk4[3] >> 3, 0);
        GetMonNickname(mon, nickname);
        sub_81B2A3C(ptr->unk8, nickname, 0, ptr->unk0->unk4);
    }
}

void sub_81B2AC8(struct Pokemon *mon, struct Unk_203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        u8 ailment = sub_81B205C(mon);
        if (ailment == AILMENT_NONE ||  ailment == AILMENT_PKRS)
        {
            if (c != 0)
                ptr->unk0->unk0(ptr->unk8, ptr->unk0->unk4[4] >> 3, (ptr->unk0->unk4[5] >> 3) + 1, ptr->unk0->unk4[6] >> 3, ptr->unk0->unk4[7] >> 3, 0);
            if (c != 2)
                sub_81B2B40(GetMonData(mon, MON_DATA_LEVEL), ptr);
        }
    }
}

void sub_81B2B40(u8 level, struct Unk_203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, level, 0, 3);
    StringCopy(gStringVar1, gText_LevelSymbol);
    StringAppend(gStringVar1, gStringVar2);
    sub_81B2A3C(ptr->unk8, gStringVar1, 0, &ptr->unk0->unk4[4]);
}

void sub_81B2B8C(struct Pokemon *mon, struct Unk_203CEDC *ptr, u8 c)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    
    if (c == 1)
        ptr->unk0->unk0(ptr->unk8, ptr->unk0->unk4[8] >> 3, (ptr->unk0->unk4[9] >> 3) + 1, ptr->unk0->unk4[10] >> 3, ptr->unk0->unk4[11] >> 3, 0);
    GetMonNickname(mon, nickname);
    sub_81B2BF4(GetMonGender(mon), GetMonData(mon, MON_DATA_SPECIES), nickname, ptr);
}

void sub_81B2BF4(u8 gender, u16 species, u8 *nickname, struct Unk_203CEDC *ptr)
{
    u8 palNum = GetWindowAttribute(ptr->unk8, WINDOW_PALETTE_NUM) * 16;
    
    if (species == SPECIES_NONE)
        return;
    if (species == SPECIES_NIDORAN_M || species == SPECIES_NIDORAN_F)
    {
        if (StringCompare(nickname, gSpeciesNames[species]) == 0)
            return;
    }
    switch (gender)
    {
        case MON_MALE:
            LoadPalette(sub_81B2564(gUnknown_08615AC3[0]), gUnknown_08615AB6[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AC3[1]), gUnknown_08615AB6[1] + palNum, 2);
            sub_81B2A3C(ptr->unk8, gText_MaleSymbol, 2, &ptr->unk0->unk4[8]);
            break;
        case MON_FEMALE:
            LoadPalette(sub_81B2564(gUnknown_08615AC5[0]), gUnknown_08615AB6[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AC5[1]), gUnknown_08615AB6[1] + palNum, 2);
            sub_81B2A3C(ptr->unk8, gText_FemaleSymbol, 2, &ptr->unk0->unk4[8]);
            break;
    }
}

void sub_81B2CD4(struct Pokemon *mon, struct Unk_203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->unk8, ptr->unk0->unk4[12] >> 3, (ptr->unk0->unk4[13] >> 3) + 1, ptr->unk0->unk4[14] >> 3, ptr->unk0->unk4[15] >> 3, 0);
        if (c != 2)
            sub_81B2D3C(GetMonData(mon, MON_DATA_HP), ptr);
    }
}

void sub_81B2D3C(u16 hp, struct Unk_203CEDC *ptr)
{
    u8 *strOut = ConvertIntToDecimalStringN(gStringVar1, hp, 1, 3);
    
    strOut[0] = CHAR_SLASH;
    strOut[1] = EOS;
    
    sub_81B2A3C(ptr->unk8, gStringVar1, 0, &ptr->unk0->unk4[12]);
}

void sub_81B2D74(struct Pokemon *mon, struct Unk_203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->unk8, (ptr->unk0->unk4[16] >> 3) + 1, (ptr->unk0->unk4[17] >> 3) + 1, ptr->unk0->unk4[18] >> 3, ptr->unk0->unk4[19] >> 3, 0);
        if (c != 2)
            sub_81B2DDC(GetMonData(mon, MON_DATA_MAX_HP), ptr);
    }
}

void sub_81B2DDC(u16 maxhp, struct Unk_203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, maxhp, 1, 3);
    StringCopy(gStringVar1, gText_Slash);
    StringAppend(gStringVar1, gStringVar2);
    sub_81B2A3C(ptr->unk8, gStringVar1, 0, &ptr->unk0->unk4[16]);
}

void sub_81B2E28(struct Pokemon *mon, struct Unk_203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        sub_81B2E64(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP), ptr);
}

void sub_81B2E64(u16 hp, u16 maxhp, struct Unk_203CEDC *ptr)
{
    u8 palNum = GetWindowAttribute(ptr->unk8, WINDOW_PALETTE_NUM) * 16;
    u8 hpFraction;
    
    switch (GetHPBarLevel(hp, maxhp))
    {
        case 3:
        case 4:
            LoadPalette(sub_81B2564(gUnknown_08615AC7[0]), gUnknown_08615AB8[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AC7[1]), gUnknown_08615AB8[1] + palNum, 2);
            break;
        case 2:
            LoadPalette(sub_81B2564(gUnknown_08615AC9[0]), gUnknown_08615AB8[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615AC9[1]), gUnknown_08615AB8[1] + palNum, 2);
            break;
        default:
            LoadPalette(sub_81B2564(gUnknown_08615ACB[0]), gUnknown_08615AB8[0] + palNum, 2);
            LoadPalette(sub_81B2564(gUnknown_08615ACB[1]), gUnknown_08615AB8[1] + palNum, 2);
            break;
    }
    
    hpFraction = GetScaledHPFraction(hp, maxhp, ptr->unk0->unk4[22]);
    FillWindowPixelRect(ptr->unk8, gUnknown_08615AB8[1], ptr->unk0->unk4[20], ptr->unk0->unk4[21], hpFraction, 1);
    FillWindowPixelRect(ptr->unk8, gUnknown_08615AB8[0], ptr->unk0->unk4[20], ptr->unk0->unk4[21] + 1, hpFraction, 2);
    if (hpFraction != ptr->unk0->unk4[22])
    {
        FillWindowPixelRect(ptr->unk8, 13, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21], ptr->unk0->unk4[22] - hpFraction, 1);
        FillWindowPixelRect(ptr->unk8, 2, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21] + 1, ptr->unk0->unk4[22] - hpFraction, 2);
    }
    CopyWindowToVram(ptr->unk8, 2);
}

#ifdef NONMATCHING
void sub_81B2FA8(u8 stringID, struct Unk_203CEDC *ptr, u8 c)
{
    if (c != 0)
    {
        int unk = ((ptr->unk0->unk1C & 7) + ptr->unk0->unk1E + 7) / 8;
        int unk2 = ((ptr->unk0->unk1D & 7) + ptr->unk0->unk1F + 7) / 8;
        ptr->unk0->unk0(ptr->unk8, ptr->unk0->unk1C >> 3, ptr->unk0->unk1D >> 3, unk, unk2, 1);
    }
    if (c != 2)
        AddTextPrinterParameterized3(ptr->unk8, 1, ptr->unk0->unk1C, ptr->unk0->unk1D, gUnknown_086157FC[0], 0, gUnknown_08615B60[stringID]);
}
#else
NAKED
void sub_81B2FA8(u8 stringID, struct Unk_203CEDC *ptr, u8 c)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0xC\n\
	adds r6, r1, 0\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	lsls r2, 24\n\
	lsrs r7, r2, 24\n\
	cmp r7, 0\n\
	beq _081B2FF2\n\
	ldr r5, [r6]\n\
	ldrb r1, [r5, 0x1C]\n\
	movs r4, 0x7\n\
	adds r0, r1, 0\n\
	ands r0, r4\n\
	ldrb r2, [r5, 0x1E]\n\
	adds r0, r2\n\
	adds r3, r0, 0x7\n\
	asrs r3, 3\n\
	ldrb r2, [r5, 0x1D]\n\
	adds r0, r2, 0\n\
	ands r0, r4\n\
	ldrb r4, [r5, 0x1F]\n\
	adds r0, r4\n\
	adds r4, r0, 0x7\n\
	ldrb r0, [r6, 0x8]\n\
	lsrs r1, 3\n\
	lsrs r2, 3\n\
	lsrs r4, 3\n\
	str r4, [sp]\n\
	movs r4, 0x1\n\
	str r4, [sp, 0x4]\n\
	ldr r4, [r5]\n\
	bl _call_via_r4\n\
_081B2FF2:\n\
	cmp r7, 0x2\n\
	beq _081B3018\n\
	ldrb r0, [r6, 0x8]\n\
	ldr r1, [r6]\n\
	ldrb r2, [r1, 0x1C]\n\
	ldrb r3, [r1, 0x1D]\n\
	ldr r1, =gUnknown_086157FC\n\
	str r1, [sp]\n\
	movs r1, 0\n\
	str r1, [sp, 0x4]\n\
	ldr r4, =gUnknown_08615B60\n\
	mov r5, r8\n\
	lsls r1, r5, 2\n\
	adds r1, r4\n\
	ldr r1, [r1]\n\
	str r1, [sp, 0x8]\n\
	movs r1, 0x1\n\
	bl AddTextPrinterParameterized3\n\
_081B3018:\n\
	add sp, 0xC\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void sub_81B302C(u8 *ptr)
{
    if (*ptr != 0xFF)
    {
        sub_8198070(*ptr, 0);
        RemoveWindow(*ptr);
        *ptr = 0xFF;
        schedule_bg_copy_tilemap_to_vram(2);
    }
}

void display_pokemon_menu_message(u32 stringID)
{
    u8 *windowPtr = &gUnknown_0203CEC4->unkC[1];
    
    if (*windowPtr != 0xFF)
        sub_81B302C(windowPtr);
    
    if (stringID != 0x7F)
    {
        switch (stringID - 21)
        {
            case 0:
                *windowPtr = AddWindow(&gUnknown_08615928);
                break;
            case 3:
                *windowPtr = AddWindow(&gUnknown_08615930);
                break;
            case 4:
                *windowPtr = AddWindow(&gUnknown_08615938);
                break;
            case 1:
            case 2:
                *windowPtr = AddWindow(&gUnknown_08615940);
                break;
            case 5:
                *windowPtr = AddWindow(&gUnknown_08615948);
                break;
            default:
                *windowPtr = AddWindow(&gUnknown_08615920);
                break;
        }
        if (stringID == 0)
        {
            if (gUnknown_0203CEC4->unk8_0 != FALSE)
                stringID = 2;
            else if (sub_81B314C() == FALSE)
                stringID = 1;
        }
        SetWindowBorderStyle(*windowPtr, 0, 0x4F, 0xD);
        StringExpandPlaceholders(gStringVar4, gUnknown_08615AF4[stringID]);
        AddTextPrinterParameterized(*windowPtr, 1, gStringVar4, 0, 1, 0, 0);
        schedule_bg_copy_tilemap_to_vram(2);
    }
}

bool8 sub_81B314C(void)
{
    struct Pokemon *party = gPlayerParty;
    u8 i;
    u8 j = 0;
    
    if (gUnknown_0203CEC8.unkB == 1)
        return TRUE;
    
    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0 || GetMonData(&party[i], MON_DATA_IS_EGG) != FALSE)
                j++;
        }
        if (j > 1)
            return TRUE;
    }
    return FALSE;
}

u8 sub_81B31B0(u8 a)
{
    struct WindowTemplate window;
    u8 cursorDimension;
    u8 fontAttribute;
    u8 i;
    
    switch (a)
    {
        case 0:
            SetWindowTemplateFields(&window, 2, 19, 19 - (gUnknown_0203CEC4->unk17 * 2), 10, gUnknown_0203CEC4->unk17 * 2, 14, 0x2E9);
            break;
        case 1:
            window = gUnknown_08615950;
            break;
        case 2:
            window = gUnknown_08615958;
            break;
        default:
            window = gUnknown_08615960;
            break;
    }
    
    gUnknown_0203CEC4->unkC[0] = AddWindow(&window);
    SetWindowBorderStyle(gUnknown_0203CEC4->unkC[0], 0, 0x4F, 13);
    if (a == 3)
        return gUnknown_0203CEC4->unkC[0];
    cursorDimension = GetMenuCursorDimensionByFont(1, 0);
    fontAttribute = GetFontAttribute(1, 2);
    
    for (i = 0; i < gUnknown_0203CEC4->unk17; i++)
    {
        u8 unk = (gUnknown_0203CEC4->unkF[i] > 18) ? 4 : 3;
        AddTextPrinterParameterized4(gUnknown_0203CEC4->unkC[0], 1, cursorDimension, (i * 16) + 1, fontAttribute, 0, gUnknown_086157FC[unk], 0, gUnknown_08615C08[gUnknown_0203CEC4->unkF[i]].textPtr);
    }
    
    InitMenuInUpperLeftCorner(gUnknown_0203CEC4->unkC[0], gUnknown_0203CEC4->unk17, 0, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    
    return gUnknown_0203CEC4->unkC[0];
}

void sub_81B3300(const u8 *text)
{
    SetWindowBorderStyle(6, 0, 0x4F, 13);
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(6, 1, text, GetPlayerTextSpeedDelay(), 0, 2, 1, 3);
}

void sub_81B334C(void)
{
    CreateYesNoMenu(&gUnknown_08615968, 0x4F, 13, 0);
}

u8 sub_81B3364(void)
{
    gUnknown_0203CEC4->unkC[0] = AddWindow(&gUnknown_08615970);
    SetWindowBorderStyle(gUnknown_0203CEC4->unkC[0], 0, 0x4F, 13);
    return gUnknown_0203CEC4->unkC[0];
}

void sub_81B3394(void)
{
    ClearWindowTilemap(gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
}

void sub_81B33B4(struct Pokemon *mons, u8 a, u8 b)
{
    u8 i;
    
    if (b == 0)
    {
        sub_81B3414(mons, a);
    }
    else
    {
        gUnknown_0203CEC4->unk17 = gUnknown_08615D70[b];
        for (i = 0; i < gUnknown_0203CEC4->unk17; i++)
            gUnknown_0203CEC4->unkF[i] = gUnknown_08615D38[b][i];
    }
}

void sub_81B3414(struct Pokemon *mons, u8 a)
{
    u8 i, j;
    
    gUnknown_0203CEC4->unk17 = 0;
    AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 0);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; gUnknown_08615D7E[j] != MOVE_SWORDS_DANCE; j++)
        {
            if (GetMonData(&mons[a], i + MON_DATA_MOVE1) == gUnknown_08615D7E[j])
            {
                AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, j + 19);
                break;
            }
        }
    }
    if (!InBattlePike())
    {
        if (GetMonData(&mons[1], MON_DATA_SPECIES) != SPECIES_NONE)
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 1);
        if (ItemIsMail(GetMonData(&mons[a], MON_DATA_HELD_ITEM)))
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 6);
        else
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 3);
    }
    AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 2);
}

u8 sub_81B353C(struct Pokemon *mon)
{
    u32 returnVar;
    
    switch (gUnknown_0203CEC8.unk8_0)
    {
        case 0:
            if (InMultiBattleRoom() == TRUE || GetMonData(mon, MON_DATA_IS_EGG) != FALSE)
                returnVar = 1;
            else
                returnVar = 0;
            break;
        case 1:
            returnVar = sub_81B8A2C(mon);
            break;
        case 4:
            switch (sub_81B856C(gUnknown_0203CEC8.unk9))
            {
                default:
                    returnVar = 7;
                    break;
                case 0:
                    returnVar = 4;
                    break;
                case 1:
                    returnVar = 5;
                    break;
            }
            break;
        case 6:
            returnVar = (GetMonData(mon, MON_DATA_IS_EGG) != FALSE) ? 7 : 6;
            break;
        case 8:
            returnVar = 10;
            break;
        case 9:
            returnVar = 11;
            break;
        case 10:
            returnVar = 12;
            break;
        case 12:
            returnVar = 13;
            break;
        default:
            returnVar = 0;
            break;
    }
    return returnVar;
}

bool8 sub_81B3608(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item;
    
    GetMonNickname(mon, gStringVar1);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (gUnknown_0203CEC8.unk8_0 != 12)
    {
        sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, sub_81B353C(mon));
        sub_81B31B0(0);
        display_pokemon_menu_message(21);
    }
    else
    {
        item = GetMonData(mon, MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
        {
            sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, sub_81B353C(mon));
            sub_81B31B0(1);
            CopyItemName(item, gStringVar2);
            display_pokemon_menu_message(26);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnNotHolding);
            sub_81B1B5C(gStringVar4, 1);
            schedule_bg_copy_tilemap_to_vram(2);
            gTasks[taskId].func = sub_81B469C;
            return FALSE;
        }
    }
    return TRUE;
}

void sub_81B36FC(u8 taskId)
{
    if (sub_81B3608(taskId) != FALSE)
    {
        gTasks[taskId].data[0] = 0xFF;
        gTasks[taskId].func = sub_81B3730;
    }
}

void sub_81B3730(u8 taskId)
{
    s16 *data;
    s8 input;
    
    if (gPaletteFade.active == FALSE && sub_81221EC() != TRUE)
    {
        data = gTasks[taskId].data;
        if (gUnknown_0203CEC4->unk17 <= 3)
            input = Menu_ProcessInputNoWrapAround_other();
        else
            input = ProcessMenuInput_other();
        data[0] = GetMenuCursorPos();
        if (input != -2)
        {
            if (input == -1)
            {
                PlaySE(SE_SELECT);
                sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
                gUnknown_08615C08[gUnknown_0203CEC4->unkF[gUnknown_0203CEC4->unk17 - 1]].func(taskId);
            }
            else
            {
                sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
                gUnknown_08615C08[gUnknown_0203CEC4->unkF[input]].func(taskId);
            }
        }
    }
}

void sub_81B37FC(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->unk4 = sub_81B3828;
    sub_81B12C0(taskId);
}

void sub_81B3828(void)
{
    if (gUnknown_0203CEC8.unk8_0 == 1)
    {
        pokemon_change_order();
        ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B3894);
    }
    else
    {
        ShowPokemonSummaryScreen(PSS_MODE_NORMAL, gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B3894);
    }
}

void sub_81B3894(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    gUnknown_0203CEC8.unk9 = gUnknown_0203CF20;
    sub_81B0038(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 21, sub_81B36FC, gUnknown_0203CEC8.unk0);
}

void brm_switch(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC8.unkB = 8;
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    display_pokemon_menu_message(3);
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
    gUnknown_0203CEC8.unkA = gUnknown_0203CEC8.unk9;
    gTasks[taskId].func = sub_81B1370;
}

void sub_81B3938(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowIds[2];
    
    if (gUnknown_0203CEC8.unkA == gUnknown_0203CEC8.unk9)
    {
        sub_81B407C(taskId);
    }
    else
    {
        windowIds[0] = gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unk8;
        data[0] = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_LEFT);
        data[1] = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_TOP);
        data[2] = GetWindowAttribute(windowIds[0], WINDOW_WIDTH);
        data[3] = GetWindowAttribute(windowIds[0], WINDOW_HEIGHT);
        data[8] = 0;
        if (data[2] == 10)
            data[10] = -1;
        else
            data[10] = 1;
        windowIds[1] = gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].unk8;
        data[4] = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_LEFT);
        data[5] = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_TOP);
        data[6] = GetWindowAttribute(windowIds[1], WINDOW_WIDTH);
        data[7] = GetWindowAttribute(windowIds[1], WINDOW_HEIGHT);
        data[9] = 0;
        if (data[6] == 10)
            data[11] = -1;
        else
            data[11] = 1;
        gUnknown_0203CEF0 = Alloc(data[2] * (data[3] << 1));
        gUnknown_0203CEF4 = Alloc(data[6] * (data[7] << 1));
        sub_8199CBC(0, gUnknown_0203CEF0, data[0], data[1], data[2], data[3]);
        sub_8199CBC(0, gUnknown_0203CEF4, data[4], data[5], data[6], data[7]);
        ClearWindowTilemap(windowIds[0]);
        ClearWindowTilemap(windowIds[1]);
        gUnknown_0203CEC8.unkB = 9;
        sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
        sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
        sub_81B3CC0(taskId);
        gTasks[taskId].func = sub_81B3D48;
    }
}

#ifdef NONMATCHING
bool8 sub_81B3AD8(s16 a, s16 b, u8 *c, u8 *d, u8 *e)
{
    
    if ((a + b) < 0 || a > 31)
    {
        return FALSE;
    }
    if (a < 0)
    {
        *c = -a;
        *d = 0;
        *e = a + b;
        return TRUE;
    }
    else
    {
        *c = 0;
        *d = a;
        if ((a + b) > 31)
            *e = 32 - a;
        else
            *e = b;
        return TRUE;
    }

}
#else
NAKED
bool8 sub_81B3AD8(s16 a, s16 b, u8 *c, u8 *d, u8 *e)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r2, 0\n\
	mov r12, r3\n\
	ldr r7, [sp, 0x18]\n\
	lsls r0, 16\n\
	lsrs r3, r0, 16\n\
	adds r5, r3, 0\n\
	lsls r1, 16\n\
	lsrs r2, r1, 16\n\
	mov r8, r2\n\
	lsls r0, r3, 16\n\
	asrs r1, r0, 16\n\
	lsls r0, r2, 16\n\
	asrs r0, 16\n\
	adds r4, r1, r0\n\
	cmp r4, 0\n\
	blt _081B3B02\n\
	cmp r1, 0x1F\n\
	ble _081B3B06\n\
_081B3B02:\n\
	movs r0, 0\n\
	b _081B3B34\n\
_081B3B06:\n\
	cmp r1, 0\n\
	bge _081B3B1A\n\
	negs r0, r1\n\
	strb r0, [r6]\n\
	movs r0, 0\n\
	mov r1, r12\n\
	strb r0, [r1]\n\
	adds r0, r2, r3\n\
	strb r0, [r7]\n\
	b _081B3B32\n\
_081B3B1A:\n\
	movs r0, 0\n\
	strb r0, [r6]\n\
	mov r0, r12\n\
	strb r5, [r0]\n\
	cmp r4, 0x1F\n\
	ble _081B3B2E\n\
	movs r0, 0x20\n\
	subs r0, r5\n\
	strb r0, [r7]\n\
	b _081B3B32\n\
_081B3B2E:\n\
	mov r1, r8\n\
	strb r1, [r7]\n\
_081B3B32:\n\
	movs r0, 0x1\n\
_081B3B34:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n");
}
#endif

void sub_81B3B40(const void *rectSrc, s16 a, s16 b, s16 c, s16 d, s16 e)
{
    u8 f, g, h;
    
    if (sub_81B3AD8(a, c, &f, &g, &h) != FALSE)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, g, b, h, d);
        if (sub_81B3AD8(a + e, c, &f, &g, &h) != FALSE)
            CopyRectToBgTilemapBufferRect(0, rectSrc, f, 0, c, d, g, b, h, d, 17, 0, 0);
    }
}

void sub_81B3C0C(struct Unk_203CEDC *ptr, s16 a)
{
    gSprites[ptr->unkB].pos2.x += a * 8;
    gSprites[ptr->unkA].pos2.x += a * 8;
    gSprites[ptr->unk9].pos2.x += a * 8;
    gSprites[ptr->unkC].pos2.x += a * 8;
}

void sub_81B3C60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (data[10] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], data[10]);
    if (data[11] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unkA], data[11]);
}

void sub_81B3CC0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (data[10] != 0)
        sub_81B3B40(gUnknown_0203CEF0, data[0] + data[8], data[1], data[2], data[3], data[10]);
    if (data[11] != 0)
        sub_81B3B40(gUnknown_0203CEF4, data[4] + data[9], data[5], data[6], data[7], data[11]);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_81B3D48(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 tilemapRelatedMaybe[2];
    
    sub_81B3CC0(taskId);
    sub_81B3C60(taskId);
    data[8] += data[10];
    data[9] += data[11];
    tilemapRelatedMaybe[0] = data[0] + data[8];
    tilemapRelatedMaybe[1] = data[4] + data[9];
    if (tilemapRelatedMaybe[0] > 33 && tilemapRelatedMaybe[1] > 33)
    {
        data[10] *= -1;
        data[11] *= -1;
        swap_pokemon_and_oams();
        sub_81B0948(gUnknown_0203CEC8.unk9);
        sub_81B0948(gUnknown_0203CEC8.unkA);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unk8);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].unk8);
        sub_8199CBC(0, gUnknown_0203CEF0, data[0], data[1], data[2], data[3]);
        sub_8199CBC(0, gUnknown_0203CEF4, data[4], data[5], data[6], data[7]);
        ClearWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unk8);
        ClearWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].unk8);
        gTasks[taskId].func = sub_81B3E60;
    }
}

void sub_81B3E60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    sub_81B3CC0(taskId);
    sub_81B3C60(taskId);
    if (data[10] == 0 && data[11] == 0)
    {
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unk8);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].unk8);
        schedule_bg_copy_tilemap_to_vram(0);
        Free(gUnknown_0203CEF0);
        Free(gUnknown_0203CEF4);
        sub_81B407C(taskId);
    }
    else
    {
        data[8] += data[10];
        data[9] += data[11];
        if (data[8] == 0)
            data[10] = 0;
        if (data[9] == 0)
            data[11] = 0;
    }
}

void oamt_swap_pos(u8 *spriteIdPtr1, u8 *spriteIdPtr2)
{
    u8 spriteIdBuffer = *spriteIdPtr1;
    u16 xBuffer1, yBuffer1, xBuffer2, yBuffer2;
    
    *spriteIdPtr1 = *spriteIdPtr2;
    *spriteIdPtr2 = spriteIdBuffer;
    xBuffer1 = gSprites[*spriteIdPtr1].pos1.x;
    yBuffer1 = gSprites[*spriteIdPtr1].pos1.y;
    xBuffer2 = gSprites[*spriteIdPtr1].pos2.x;
    yBuffer2 = gSprites[*spriteIdPtr1].pos2.y;
    gSprites[*spriteIdPtr1].pos1.x = gSprites[*spriteIdPtr2].pos1.x;
    gSprites[*spriteIdPtr1].pos1.y = gSprites[*spriteIdPtr2].pos1.y;
    gSprites[*spriteIdPtr1].pos2.x = gSprites[*spriteIdPtr2].pos2.x;
    gSprites[*spriteIdPtr1].pos2.y = gSprites[*spriteIdPtr2].pos2.y;
    gSprites[*spriteIdPtr2].pos1.x = xBuffer1;
    gSprites[*spriteIdPtr2].pos1.y = yBuffer1;
    gSprites[*spriteIdPtr2].pos2.x = xBuffer2;
    gSprites[*spriteIdPtr2].pos2.y = yBuffer2;  
}

void swap_pokemon_and_oams(void)
{
    struct Unk_203CEDC *structPtrs[2];
    struct Pokemon *mon1, *mon2;
    struct Pokemon *monBuffer;
    
    structPtrs[0] = &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9];
    structPtrs[1] = &gUnknown_0203CEDC[gUnknown_0203CEC8.unkA];
    mon1 = &gPlayerParty[gUnknown_0203CEC8.unk9];
    mon2 = &gPlayerParty[gUnknown_0203CEC8.unkA];
    monBuffer = Alloc(sizeof(struct Pokemon));
    *monBuffer = *mon1;
    *mon1 = *mon2;
    *mon2 = *monBuffer;
    Free(monBuffer);
    oamt_swap_pos(&structPtrs[0]->unkB, &structPtrs[1]->unkB);
    oamt_swap_pos(&structPtrs[0]->unkA, &structPtrs[1]->unkA);
    oamt_swap_pos(&structPtrs[0]->unk9, &structPtrs[1]->unk9);
    oamt_swap_pos(&structPtrs[0]->unkC, &structPtrs[1]->unkC);
}

void sub_81B407C(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    gUnknown_0203CEC8.unkB = 0;
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 0);
    gUnknown_0203CEC8.unk9 = gUnknown_0203CEC8.unkA;
    sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
    display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

void brm_cancel_1(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (gUnknown_0203CEC8.unk8_0 == 6)
        display_pokemon_menu_message(15);
    else
        display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

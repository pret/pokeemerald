#include "global.h"
#include "battle.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "contest.h"
#include "decompress.h"
#include "event_data.h"
#include "fldeff_softboiled.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"

struct Unk_Rodata1 {
    void (*unk0)(u8, u8, u8, u8, u8, u8);
    u32 unk4[7];
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
    u8 fillerF[9];
    u16 unk18[0xB0];
    u8 filler[0xA0];
    s16 unk218[16];
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
extern struct Struct203CEC8 gUnknown_0203CEC8;
extern struct Unk_203CEDC *gUnknown_0203CEDC;
extern u8 *gUnknown_0203CEE0;
extern struct Unk_203CEE4 *gUnknown_0203CEE4;
extern u8 gUnknown_0203CEE8;
extern u8 gUnknown_0203CEF8[];

// ABOVE TO BE PUT IN EWRAM

// BELOW TO BE CONVERTED TO C

extern struct BgTemplate gUnknown_086156B8[];
extern struct Unk_Rodata1 gUnknown_086156C4[2];
// extern struct Unk_Rodata1 gUnknown_086156E4;
extern u32 gUnknown_08615704[][6][2];
extern u8 gUnknown_086157C4[];
extern u8 gUnknown_086157E0[];

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
void sub_81B2A3C(u8, u8*, u8, u32*);
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
    u8 *ptr = gUnknown_0203CEF8;
    
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
    if (!GetNumberOfRelearnableMoves(&gPlayerParty[slot]))
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
    
    if (slot < 3 && (gBattleTypeFlags & BATTLE_TYPE_ARENA) && gMain.inBattle && (gBattleStruct->field_2A0 >> sub_81B8F38(slot) & 1))
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

#include "battle.h"
#include "decompress.h"
#include "global.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "palette.h"
#include "pokemon.h"
#include "songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "window.h"

extern struct unkSummaryStruct* gUnknown_0203CF1C;
extern struct BgTemplate gUnknown_0861CBB4;
extern u8 gUnknown_0203CF20;
extern struct MusicPlayerInfo gMPlay_BGM;
extern s8 gUnknown_0861CC1C[];

extern void sub_806F2AC(u8 a, u8 b);
void sub_81C488C(u8 a);
extern void do_scheduled_bg_tilemap_copies_to_vram(void);
extern u8 sub_81221EC();
extern u8 sub_81221AC();
extern void SetVBlankHBlankCallbacksToNull();
extern void sub_8121DA0();
extern void clear_scheduled_bg_copies_to_vram();
extern void remove_some_task();
extern void ResetBgsAndClearDma3BusyFlags(u32 leftoverFireRedLeafGreenVariable);
extern void ShowBg(u8 a);
extern void SetGpuReg(u8 regOffset, u16 value);
extern void schedule_bg_copy_tilemap_to_vram(u8 a);
extern void InitBgsFromTemplates(u8 bgMode, struct BgTemplate *templates, u8 numTemplates);
extern void SetBgTilemapBuffer(u8 bg, void *tilemap);
extern u8 gUnknown_08D9862C;
extern u8 gUnknown_08D98CC8;
extern u8 gUnknown_08D987FC;
extern u8 gUnknown_08D9898C;
extern u8 gUnknown_08D98B28;
extern u8 gUnknown_08D9853C;
extern u8 gUnknown_08D85620;
extern struct CompressedSpriteSheet gUnknown_0861CFBC;
extern struct CompressedSpriteSheet gUnknown_0861D074;
extern struct CompressedSpriteSheet gUnknown_0861D0F8;
extern struct CompressedSpritePalette gUnknown_0861D100;
extern struct CompressedSpritePalette gUnknown_0861D07C;
extern u8 gUnknown_08D97B84;
extern u8 gUnknown_08D97D0C;
extern void reset_temp_tile_data_buffers();
extern void decompress_and_copy_tile_data_to_vram(u8 a, void* tiledata, u8 b, u8 c, u8 d);
extern u8 free_temp_tile_data_buffers_if_possible();
extern void sub_8069004(struct BoxPokemon* a, void* b);

extern u32 ChangeBgX(u8 bg, u32 value, u8 op);

void sub_81BFAE4(void);
void sub_81BFE24();
u8 sub_81BFEB0();
void sub_81C2554();
void sub_81C1BA0();
void sub_81C0098(struct Pokemon* a);
u8 sub_81C00F0(struct Pokemon* a);
void sub_81C25E8();
void sub_81C286C();
void sub_81C2D9C(u8 a);
void sub_81C0348();
void sub_81C2AFC(u8 a);
void sub_81C4190();
void sub_81C42C8();
u8 sub_81C45F4(void* a, u16* b);
void sub_81C4984();
void sub_81C4A08();
void sub_81C4A88();
void sub_81C4280();
void sub_81C0510(u8 taskId);
void sub_81C171C(u8 taskId);
void sub_8121E10();
u8 sub_81B205C(struct Pokemon* a);
void sub_81C1DA4(u8 a, u8 b);
void sub_81C1EFC(u8 a, u8 b, u8 c);
void sub_81C240C(u16 a);
void sub_81C2194(void* a, u8 b, u8 c);
void sub_81C2074(u16 a, s16 b);
void sub_81C2524();
void sub_81C2228(struct Pokemon* poke);
void sub_81C0484(u8 taskId);
void sub_81C4898();
void sub_806F47C(u8 a);
u8 GetLRKeysState();
void sub_81C0604(u8 taskId, s8 a);
void sub_81C0A8C(u8 taskId, s8 a);
void sub_81C48F0();
void sub_81C0E48(u8 taskId);
void sub_81C0704(u8 taskId);
s8 sub_81C09B4(s8 a);
s8 sub_81C08F8(s8 a);
void sub_81C4204(u8 a, u8 b);
void sub_81C20F0(u8 taskId);
u8 sub_81C0A50(struct Pokemon* mon);
void sub_81C49E0();
void sub_81C0E24();

u8 sub_81BFB10();
u8 sub_81B1250();

union unkUnion{
    struct Pokemon mons[6];
    struct BoxPokemon boxMons[6];
};

u8 sub_80D214C(union unkUnion* a, u8 b, u8 c, u8 d);

struct pokeSummary{
    u16 species; // 0x0
    u16 species2; // 0x2
    u8 isEgg; // 0x4
    u8 level; // 0x5
    u8 ribbons; // 0x6
    u8 unk7; // 0x7
    u8 altability; // 0x8
    u8 metLocation; // 0x9
    u8 metLevel; // 0xA
    u8 metGame; // 0xB
    u32 pid; // 0xC
    u32 exp; // 0x10
    u16 moves[4]; // 0x14
    u8 pp[4]; // 0x1C
    u16 currentHP; // 0x20
    u16 maxHP; // 0x22
    u16 atk; // 0x24
    u16 def; // 0x26
    u16 spatk; // 0x28
    u16 spdef; // 0x2A
    u16 speed; // 0x2C
    u16 item; // 0x2E
    u16 friendship; // 0x30
    u8 OTGender; // 0x32
    u8 nature; // 0x33
    u8 ppBonuses; // 0x34
    u8 sanity; // 0x35
    u8 OTName[8]; // 0x36
    u8 unk3E[9]; // 0x3E
    u32 OTID; // 0x48
};

struct unkSummaryStruct{
    union unkUnion* unk0;
    void* unk4;
    void* unk8;
    struct Pokemon currentPoke;
    struct pokeSummary summary;
    u8 unkTilemap0[0x800];
    u8 unkTilemap0_1[0x800];
    u8 unkTilemap1[0x800];
    u8 unkTilemap1_1[0x800];
    u8 unkTilemap2[0x800];
    u8 unkTilemap2_1[0x800];
    u8 unkTilemap3[0x800];
    u8 unkTilemap3_1[0x800];
    u8 unk40BC;
    u8 unk40BD;
    u8 unk40BE;
    u8 unk40BF;
    u8 unk40C0;
    u8 unk40C1;
    u8 unk40C2;
    u8 unk40C3;
    u16 unk40C4;
    u8 unk40C6;
    u8 unk_filler3;
    u8 unk40C8;
    u8 unk_filler2[0xA];
    u8 unk40D3;
    u8 unk40D4;
    u8 unk_filler5[0x1A];
    u8 unk40EF;
    s16 unk40F0;
    u8 unk_filler4[6];
};

void sub_81BF8EC(u8 a, void* b, u8 c, u8 d, void* e)
{
    u8 byte;
    gUnknown_0203CF1C = AllocZeroed(0x40F8);
    gUnknown_0203CF1C->unk40BC = a;
    gUnknown_0203CF1C->unk0 = b;
    gUnknown_0203CF1C->unk40BE = c;
    gUnknown_0203CF1C->unk40BF = d;
    gUnknown_0203CF1C->unk4 = e;
    if (a == 2)
        gUnknown_0203CF1C->unk40BD = 1;
    else
        gUnknown_0203CF1C->unk40BD = 0;
    switch (a)
    {
        case 0:
        case 2:
            gUnknown_0203CF1C->unk40C1 = 0;
            gUnknown_0203CF1C->unk40C2 = 3;
            break;
        case 1:
            gUnknown_0203CF1C->unk40C1 = 0;
            gUnknown_0203CF1C->unk40C2 = 3;
            gUnknown_0203CF1C->unk40C8 = 1;
            break;
        case 3:
            gUnknown_0203CF1C->unk40C1 = 2;
            gUnknown_0203CF1C->unk40C2 = 3;
            gUnknown_0203CF1C->unk40C3 = 1;
            break;
    }
    byte = gUnknown_0203CF1C->unk40C1;
    gUnknown_0203CF1C->unk40C0 = byte;
    sub_81C488C(0xFF);
    if (gBattleSpritesGfx == 0)
        sub_806F2AC(0, 0);
    SetMainCallback2(sub_81BFAE4);
}

void sub_81BFA38(void* a, u8 b, u8 c, void* d, u16 e)
{
    sub_81BF8EC(3, a, b, c, d);
    gUnknown_0203CF1C->unk40C4 = e;
}

void sub_81BFA80(u8 a, void* b, u8 c, u8 d, void* e)
{
    sub_81BF8EC(a, b, c, d, e);
    gUnknown_0203CF1C->unk40EF = 1;
}

void sub_81BFAB4(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_81BFAD0(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_81BFAE4()
{
    while(1)
    {
        if (sub_81221EC() == 1 || sub_81BFB10() == 1 || sub_81221AC() == 1)
            break;
    }
}

u8 sub_81BFB10()
{
        switch (gMain.state)
        {
            case 0:
                SetVBlankHBlankCallbacksToNull();
                sub_8121DA0();
                clear_scheduled_bg_copies_to_vram();
                gMain.state++;
                break;
            case 1:
                remove_some_task();
                gMain.state++;
                break;
            case 2:
                ResetPaletteFade();
                gPaletteFade.bufferTransferDisabled = 1;
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
                sub_81BFE24();
                gUnknown_0203CF1C->unk40F0 = 0;
                gMain.state++;
                break;
            case 6:
                if (sub_81BFEB0() != 0)
                    gMain.state++;
                break;
            case 7:
                sub_81C2554();
                gMain.state++;
                break;
            case 8:
                sub_81C1BA0();
                gMain.state++;
                break;
            case 9:
                sub_81C0098(&gUnknown_0203CF1C->currentPoke);
                gUnknown_0203CF1C->unk40F0 = 0;
                gMain.state++;
                break;
            case 10:
                if(sub_81C00F0(&gUnknown_0203CF1C->currentPoke) != 0)
                    gMain.state++;
                break;
            case 11:
                sub_81C25E8();
                gMain.state++;
                break;
            case 12:
                sub_81C286C();
                gMain.state++;
                break;
            case 13:
                sub_81C2D9C(gUnknown_0203CF1C->unk40C0);
                gMain.state++;
                break;
            case 14:
                sub_81C0348();
                gMain.state++;
                break;
            case 15:
                sub_81C2AFC(gUnknown_0203CF1C->unk40C0);
                gMain.state++;
                break;
            case 16:
                sub_81C4190();
                sub_81C42C8();
                gUnknown_0203CF1C->unk40F0 = 0;
                gMain.state++;
                break;
            case 17:
                gUnknown_0203CF1C->unk40D3 = sub_81C45F4(&gUnknown_0203CF1C->currentPoke, &gUnknown_0203CF1C->unk40F0);
                if (gUnknown_0203CF1C->unk40D3 != 0xFF)
                {
                    gUnknown_0203CF1C->unk40F0 = 0;
                    gMain.state++;
                }
                break;
            case 18:
                sub_81C4984(&gUnknown_0203CF1C->currentPoke);
                gMain.state++;
                break;
            case 19:
                sub_81C4A08(&gUnknown_0203CF1C->currentPoke);
                gMain.state++;
                break;
            case 20:
                sub_81C4A88();
                gMain.state++;
                break;
            case 21:
                sub_81C4280();
                gMain.state++;
                break;
            case 22:
                if (gUnknown_0203CF1C->unk40BC != 3)
                    CreateTask(sub_81C0510, 0);
                else
                    CreateTask(sub_81C171C, 0);
                gMain.state++;
                break;
            case 23:
                BlendPalettes(-1, 16, 0);
                gMain.state++;
                break;
            case 24:
                BeginNormalPaletteFade(-1, 0, 16, 0, 0);
                gPaletteFade.bufferTransferDisabled = 0;
                gMain.state++;
                break;
            default:
                SetVBlankCallback(sub_81BFAD0);
                SetMainCallback2(sub_81BFAB4);
                return 1;
        }
        return 0;
}

void sub_81BFE24()
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, &gUnknown_0861CBB4, 4);
    SetBgTilemapBuffer(1, &gUnknown_0203CF1C->unkTilemap2);
    SetBgTilemapBuffer(2, &gUnknown_0203CF1C->unkTilemap1);
    SetBgTilemapBuffer(3, &gUnknown_0203CF1C->unkTilemap0);
    sub_8121E10();
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
    SetGpuReg(0, 0x1040);
    SetGpuReg(0x50, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

u8 sub_81BFEB0()
{
    switch (gUnknown_0203CF1C->unk40F0)
    {
        case 0:
            reset_temp_tile_data_buffers();
            decompress_and_copy_tile_data_to_vram(1, &gUnknown_08D97D0C, 0, 0, 0);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 1:
            if (free_temp_tile_data_buffers_if_possible() != 1)
            {
                LZDecompressWram(&gUnknown_08D9862C, gUnknown_0203CF1C->unkTilemap0);
                gUnknown_0203CF1C->unk40F0++;
            }
            break;
        case 2:
            LZDecompressWram(&gUnknown_08D98CC8, gUnknown_0203CF1C->unkTilemap0_1);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 3:
            LZDecompressWram(&gUnknown_08D987FC, gUnknown_0203CF1C->unkTilemap1_1);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 4:
            LZDecompressWram(&gUnknown_08D9898C, gUnknown_0203CF1C->unkTilemap2_1);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 5:
            LZDecompressWram(&gUnknown_08D98B28, gUnknown_0203CF1C->unkTilemap3_1);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 6:
            LoadCompressedPalette(&gUnknown_08D9853C, 0, 0x100);
            LoadPalette(&gUnknown_08D85620, 0x81, 0x1E);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 7:
            LoadCompressedObjectPic(&gUnknown_0861CFBC);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 8:
            LoadCompressedObjectPic(&gUnknown_0861D074);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 9:
            LoadCompressedObjectPic(&gUnknown_0861D0F8);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 10:
            LoadCompressedObjectPalette(&gUnknown_0861D100);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 11:
            LoadCompressedObjectPalette(&gUnknown_0861D07C);
            gUnknown_0203CF1C->unk40F0++;
            break;
        case 12:
            LoadCompressedPalette(&gUnknown_08D97B84, 0x1D0, 0x60);
            gUnknown_0203CF1C->unk40F0 = 0;
            return 1;
    }
    return 0;
}

void sub_81C0098(struct Pokemon* poke)
{
    if (gUnknown_0203CF1C->unk40BD == 0)
    {
        struct Pokemon *pokeMons = gUnknown_0203CF1C->unk0->mons;
        *poke = pokeMons[gUnknown_0203CF1C->unk40BE];
    }
    else
    {
        struct BoxPokemon *boxMons = gUnknown_0203CF1C->unk0->boxMons;
        sub_8069004(&boxMons[gUnknown_0203CF1C->unk40BE], poke);
    }
}

u8 sub_81C00F0(struct Pokemon* a)
{
    u32 i;
    struct pokeSummary* sum = &gUnknown_0203CF1C->summary;
    switch (gUnknown_0203CF1C->unk40F0)
    {
        
        case 0:
            sum->species = GetMonData(a, MON_DATA_SPECIES);
            sum->species2 = GetMonData(a, MON_DATA_SPECIES2);
            sum->exp = GetMonData(a, MON_DATA_EXP);
            sum->level = GetMonData(a, MON_DATA_LEVEL);
            sum->altability = GetMonData(a, MON_DATA_ALT_ABILITY);
            sum->item = GetMonData(a, MON_DATA_HELD_ITEM);
            sum->pid = GetMonData(a, MON_DATA_PERSONALITY);
            sum->sanity = GetMonData(a, MON_DATA_SANITY_BIT1);
            if (sum->sanity != 0)
                sum->isEgg = 1;
            else
                sum->isEgg = GetMonData(a, MON_DATA_IS_EGG);
            break;
        case 1:
            for (i = 0; i < 4; i++)
            {
                sum->moves[i] = GetMonData(a, MON_DATA_MOVE1+i);
                sum->pp[i] = GetMonData(a, MON_DATA_PP1+i);
            }
            sum->ppBonuses = GetMonData(a, MON_DATA_PP_BONUSES);
            break;
        case 2:
            if ((struct Pokemon*)gUnknown_0203CF1C->unk0 == gPlayerParty || gUnknown_0203CF1C->unk40BC == 2 || gUnknown_0203CF1C->unk40EF == 1)
            {
                sum->nature = GetNature(a);
                sum->currentHP = GetMonData(a, MON_DATA_HP);
                sum->maxHP = GetMonData(a, MON_DATA_MAX_HP);
                sum->atk = GetMonData(a, MON_DATA_ATK);
                sum->def = GetMonData(a, MON_DATA_DEF);
                sum->spatk = GetMonData(a, MON_DATA_SPATK);
                sum->spdef = GetMonData(a, MON_DATA_SPDEF);
                sum->speed = GetMonData(a, MON_DATA_SPD);
            }
            else
            {
                sum->nature = GetNature(a);
                sum->currentHP = GetMonData(a, MON_DATA_HP);
                sum->maxHP = GetMonData(a, MON_DATA_MAX_HP);
                sum->atk = GetMonData(a, MON_DATA_ATK2);
                sum->def = GetMonData(a, MON_DATA_DEF2);
                sum->spatk = GetMonData(a, MON_DATA_SPATK2);
                sum->spdef = GetMonData(a, MON_DATA_SPDEF2);
                sum->speed = GetMonData(a, MON_DATA_SPD2);
            }
            break;
        case 3:
            GetMonData(a, MON_DATA_OT_NAME, &sum->OTName);
            ConvertInternationalString((u8*)&sum->OTName, GetMonData(a, MON_DATA_LANGUAGE));
            sum->unk7 = sub_81B205C(a);
            sum->OTGender = GetMonData(a, MON_DATA_OT_GENDER);
            sum->OTID = GetMonData(a, MON_DATA_OT_ID);
            sum->metLocation = GetMonData(a, MON_DATA_MET_LOCATION);
            sum->metLevel = GetMonData(a, MON_DATA_MET_LEVEL);
            sum->metGame = GetMonData(a, MON_DATA_MET_GAME);
            sum->friendship = GetMonData(a, MON_DATA_FRIENDSHIP);
            break;
        default:
            sum->ribbons = GetMonData(a, MON_DATA_RIBBON_COUNT);
            return 1;
    }
    gUnknown_0203CF1C->unk40F0++;
    return 0;
}

void sub_81C0348()
{
    u8 a = gUnknown_0203CF1C->unk40C0 - 2; 
    if (a > 1)
    {
        sub_81C1DA4(0, 255);
        sub_81C1EFC(0, 255, 0);
    }
    else
    {
        sub_81C240C(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6]);
        sub_81C2194(&gUnknown_0203CF1C->unkTilemap2, 3, 0);
        sub_81C2194(&gUnknown_0203CF1C->unkTilemap3, 1, 0);
        SetBgTilemapBuffer(1, &gUnknown_0203CF1C->unkTilemap3);
        SetBgTilemapBuffer(2, &gUnknown_0203CF1C->unkTilemap2);
        ChangeBgX(2, 0x10000, 1);
        ClearWindowTilemap(0x13);
        ClearWindowTilemap(0xD);
    }
    if (gUnknown_0203CF1C->summary.unk7 == 0)
        sub_81C2074(0, 0xFF);
    else
    {
        u8 b = gUnknown_0203CF1C->unk40C0 - 2;
        if (b > 1)
            PutWindowTilemap(0xD);
    }
    sub_81C2524();
    sub_81C2228(&gUnknown_0203CF1C->currentPoke);
}

void sub_81C0434()
{
    FreeAllWindowBuffers();
    Free(gUnknown_0203CF1C);
}

void sub_81C044C(u8 taskId)
{
    BeginNormalPaletteFade(-1, 0, 0, 16, 0);
    gTasks[taskId].func = sub_81C0484;
}

void sub_81C0484(u8 taskId)
{
    if (sub_81221EC() != 1 && gPaletteFade.active == 0)
    {
        SetMainCallback2(gUnknown_0203CF1C->unk4);
        gUnknown_0203CF20 = gUnknown_0203CF1C->unk40BE;
        sub_81C4898();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        if (gBattleSpritesGfx == 0)
            sub_806F47C(0);
        sub_81C0434();
        DestroyTask(taskId);
    }
}

void sub_81C0510(u8 taskId)
{
    if (sub_81221EC() != 1 && gPaletteFade.active == 0)
    {
        if (gMain.newKeys & DPAD_UP)
            sub_81C0604(taskId, -1);
        else if (gMain.newKeys & DPAD_DOWN)
        {
            sub_81C0604(taskId, 1);
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysState() == 1)
            sub_81C0A8C(taskId, -1);
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysState() == 2)
            sub_81C0A8C(taskId, 1);
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C0 != 1)
            {
                if (gUnknown_0203CF1C->unk40C0 == 0)
                {
                    sub_81C48F0();
                    PlaySE(5);
                    sub_81C044C(taskId);
                }
                else
                {
                    PlaySE(5);
                    sub_81C0E48(taskId);
                }
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_81C48F0();
            PlaySE(5);
            sub_81C044C(taskId);
        }
    }
}

void sub_81C0604(u8 taskId, s8 a)
{
    s8 r4_2;

    if (gUnknown_0203CF1C->unk40C3 == 0)
    {
        if (gUnknown_0203CF1C->unk40BD == 1)
        {
            if (gUnknown_0203CF1C->unk40C0 != 0)
            {
                if (a == 1)
                    a = 0;
                else
                    a = 2;
            }
            else
            {
                if (a == 1)
                    a = 1;
                else
                    a = 3;
            }
            r4_2 = sub_80D214C(gUnknown_0203CF1C->unk0, gUnknown_0203CF1C->unk40BE, gUnknown_0203CF1C->unk40BF, a);
        }
        else if (sub_81B1250() == 1)
        {
            r4_2 = sub_81C09B4(a);
        }
        else
        {
            r4_2 = sub_81C08F8(a);
        }

        if (r4_2 != -1)
        {
            PlaySE(SE_SELECT);
            if (gUnknown_0203CF1C->summary.unk7 != 0)
            {
                sub_81C4204(2, 1);
                ClearWindowTilemap(0xD);
                schedule_bg_copy_tilemap_to_vram(0);
                sub_81C2074(0, 2);
            }
            gUnknown_0203CF1C->unk40BE = r4_2;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_81C0704;
        }
    }
}

void sub_81C0704(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        sub_81C4898();
        DestroySpriteAndFreeResources(&gSprites[gUnknown_0203CF1C->unk40D3]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[gUnknown_0203CF1C->unk40D4]);
        break;
    case 3:
        sub_81C0098(&gUnknown_0203CF1C->currentPoke);
        gUnknown_0203CF1C->unk40F0 = 0;
        break;
    case 4:
        if (sub_81C00F0(&gUnknown_0203CF1C->currentPoke) == 0)
            return;
        break;
    case 5:
        sub_81C49E0(&gUnknown_0203CF1C->currentPoke);
        break;
    case 6:
        sub_81C4A08(&gUnknown_0203CF1C->currentPoke);
        break;
    case 7:
        if (gUnknown_0203CF1C->summary.unk7)
            sub_81C2074(10, -2);
        sub_81C2228(&gUnknown_0203CF1C->currentPoke);
        data[1] = 0;
        break;
    case 8:
        gUnknown_0203CF1C->unk40D3 = sub_81C45F4(&gUnknown_0203CF1C->currentPoke, &data[1]);
        if (gUnknown_0203CF1C->unk40D3 == 0xFF)
            return;
        gSprites[gUnknown_0203CF1C->unk40D3].data2 = 1;
        sub_81C0E24();
        data[1] = 0;
        break;
    case 9:
        sub_81C4280();
        break;
    case 10:
        sub_81C25E8();
        break;
    case 11:
        sub_81C2D9C(gUnknown_0203CF1C->unk40C0);
        sub_81C2524();
        break;
    case 12:
        gSprites[gUnknown_0203CF1C->unk40D3].data2 = 0;
        break;
    default:
        if (sub_81221EC() == 0 && FuncIsActiveTask(sub_81C20F0) == 0)
        {
            data[0] = 0;
            gTasks[taskId].func = sub_81C0510;
        }
        return;
    }
    data[0]++;
}

#ifdef NONMATCHING
s8 sub_81C08F8(s8 a)
{
    union unkUnion* r7 = gUnknown_0203CF1C->unk0;
    if (gUnknown_0203CF1C->unk40C0 == 0)
    {
        if (a != -1 || gUnknown_0203CF1C->unk40BE != 0)
        {
            if (a != 1 || gUnknown_0203CF1C->unk40BE < gUnknown_0203CF1C->unk40BF)
            {
                return gUnknown_0203CF1C->unk40BE + a;
            }
        }
        return -1;
    }
    else
    {
        s8 r5r4 = gUnknown_0203CF1C->unk40BE;
        while(1)
        {
            r5r4 += a;
            if (r5r4 < 0 || r5r4 > gUnknown_0203CF1C->unk40BF)
                return -1;
            else if (GetMonData(&r7->mons[r5r4], MON_DATA_IS_EGG) == 0)
                return r5r4;
        }
    }
}
#else
__attribute__((naked))
s8 sub_81C08F8(s8 a)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	ldr r1, =gUnknown_0203CF1C\n\
	ldr r2, [r1]\n\
	ldr r7, [r2]\n\
	ldr r3, =0x000040c0\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	adds r5, r1, 0\n\
	cmp r0, 0\n\
	bne _081C0960\n\
	lsls r0, r4, 24\n\
	asrs r3, r0, 24\n\
	movs r1, 0x1\n\
	negs r1, r1\n\
	adds r6, r0, 0\n\
	cmp r3, r1\n\
	bne _081C0928\n\
	ldr r1, =0x000040be\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _081C0988\n\
_081C0928:\n\
	asrs r0, r6, 24\n\
	cmp r0, 0x1\n\
	bne _081C0940\n\
	ldr r0, [r5]\n\
	ldr r2, =0x000040be\n\
	adds r1, r0, r2\n\
	ldr r3, =0x000040bf\n\
	adds r0, r3\n\
	ldrb r1, [r1]\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	bcs _081C0988\n\
_081C0940:\n\
	ldr r0, [r5]\n\
	ldr r1, =0x000040be\n\
	adds r0, r1\n\
	ldrb r0, [r0]\n\
	adds r0, r4\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	b _081C09AE\n\
	.pool\n\
_081C0960:\n\
	ldr r3, =0x000040be\n\
	adds r0, r2, r3\n\
	ldrb r5, [r0]\n\
	lsls r6, r4, 24\n\
_081C0968:\n\
	lsls r0, r5, 24\n\
	asrs r0, 24\n\
	asrs r1, r6, 24\n\
	adds r0, r1\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	asrs r4, r0, 24\n\
	cmp r4, 0\n\
	blt _081C0988\n\
	ldr r0, =gUnknown_0203CF1C\n\
	ldr r0, [r0]\n\
	ldr r1, =0x000040bf\n\
	adds r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	ble _081C099C\n\
_081C0988:\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	b _081C09AE\n\
	.pool\n\
_081C099C:\n\
	movs r0, 0x64\n\
	muls r0, r4\n\
	adds r0, r7, r0\n\
	movs r1, 0x2D\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	bne _081C0968\n\
	adds r0, r4, 0\n\
_081C09AE:\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
	.syntax divided\n");
}
#endif

s8 sub_81C09B4(s8 a)
{
    union unkUnion* r8 = gUnknown_0203CF1C->unk0;
    s8 r5 = 0;
    u8 i = 0;
    if (gUnknown_0861CC1C[0] != gUnknown_0203CF1C->unk40BE)
    {
        while(1)
        {
            i += 1;
            if (i > 5)
                break;
            if (gUnknown_0861CC1C[i] == gUnknown_0203CF1C->unk40BE)
            {
                r5 = i;
                break;
            }
        }
    }
    while(1)
    {
        int b;
        s8* c = &gUnknown_0861CC1C[0];
        r5 += a;
        if ((u8)(r5) > 5)
        {
            return -1;
        }
        else
        {
            b = c[r5];
            if (sub_81C0A50(&r8->mons[c[r5]]) == 1)
                return b;
        }
    }
}

u8 sub_81C0A50(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == 0)
    {
        return 0;
    }
    else if (gUnknown_0203CF1C->unk40BE != 0 || GetMonData(mon, MON_DATA_IS_EGG) == 0)
        return 1;
    else
        return 0;
}
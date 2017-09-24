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
void sub_81C1DA4(u8 a, s16 b);
void sub_81C1EFC(u8 a, s16 b, u16 c);
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
void sub_81C2C38();
void sub_81C0B8C(u8 taskId);
void sub_81C0CC4(u8 taskId);
void sub_81C2DE4(u8 a);
void sub_81C424C();
void sub_81C0C68(u8 taskId);
void sub_81C0D44(u8 taskId);
void sub_81C22CC(struct Pokemon* mon);
void sub_81C0F44(u8 taskId);
void sub_81C3E9C(u16 a);
void sub_81C3F44();
void sub_81C44F0();
void sub_81C4AF8(u8 a);
void sub_81C1070(s16* a, s8 b, u8* c);
void sub_81C11F4(u8 a);
void sub_81C129C(u8 a);
u8 sub_81C1040();


void SetBgAttribute(u8 bg, u8 attributeId, u8 value);

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
    union
{
    struct
    {
        u16 unk40C4;
        u8 unk40C6;
        u8 unkfiller3;
    } fooFiller;
    u32 loadThis;
} unionThing;
    u8 unk40C8;
    u8 unk40C9;
    u8 unk_filler2[0x9];
    u8 unk40D3;
    u8 unk40D4;
    u8 unk40D5;
    u8 unk_filler5[0x19];
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
    gUnknown_0203CF1C->unionThing.fooFiller.unk40C4 = e;
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
        sub_81C240C(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unionThing.fooFiller.unk40C6]);
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

s8 sub_81C08F8(s8 a)
{
    struct Pokemon *mons = gUnknown_0203CF1C->unk0->mons;

    if (gUnknown_0203CF1C->unk40C0 == 0)
    {
        if (a == -1 && gUnknown_0203CF1C->unk40BE == 0)
            return -1;
        if (a == 1 && gUnknown_0203CF1C->unk40BE >= gUnknown_0203CF1C->unk40BF)
            return -1;
        return gUnknown_0203CF1C->unk40BE + a;
    }
    else
    {
        s8 index = gUnknown_0203CF1C->unk40BE;

        do
        {
            index += a;
            if (index < 0 || index > gUnknown_0203CF1C->unk40BF)
                return -1;
        } while (GetMonData(&mons[index], MON_DATA_IS_EGG) != 0);
        return index;
    }
}

s8 sub_81C09B4(s8 a)
{
    struct Pokemon *mons = gUnknown_0203CF1C->unk0->mons;
    s8 r5 = 0;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (gUnknown_0861CC1C[i] == gUnknown_0203CF1C->unk40BE)
        {
            r5 = i;
            break;
        }
    }

    while (1)
    {
        int b;
        s8* c = &gUnknown_0861CC1C[0];

        r5 += a;
        if (r5 < 0 || r5 >= 6)
            return -1;
        b = c[r5];
        if (sub_81C0A50(&mons[b]) == 1)
            return b;
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

void sub_81C0A8C(u8 taskId, s8 b)
{
    struct pokeSummary *summary = &gUnknown_0203CF1C->summary;
    s16 *data = gTasks[taskId].data;

    if (summary->isEgg)
        return;
    if (b == -1 && gUnknown_0203CF1C->unk40C0 == gUnknown_0203CF1C->unk40C1)
        return;
    if (b == 1 && gUnknown_0203CF1C->unk40C0 == gUnknown_0203CF1C->unk40C2)
        return;
    PlaySE(SE_SELECT);
    sub_81C2C38(gUnknown_0203CF1C->unk40C0);
    gUnknown_0203CF1C->unk40C0 += b;
    data[0] = 0;
    if (b == 1)
        SetTaskFuncWithFollowupFunc(taskId, sub_81C0B8C, gTasks[taskId].func);
    else
        SetTaskFuncWithFollowupFunc(taskId, sub_81C0CC4, gTasks[taskId].func);
    sub_81C2DE4(gUnknown_0203CF1C->unk40C0);
    sub_81C424C();
}

void sub_81C0B8C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (gUnknown_0203CF1C->unk40C9 == 0)
        {
            data[1] = 1;
            SetBgAttribute(1, 7, 1);
            SetBgAttribute(2, 7, 2);
            schedule_bg_copy_tilemap_to_vram(1);
        }
        else
        {
            data[1] = 2;
            SetBgAttribute(2, 7, 1);
            SetBgAttribute(1, 7, 2);
            schedule_bg_copy_tilemap_to_vram(2);
        }
        ChangeBgX(data[1], 0, 0);
        SetBgTilemapBuffer(data[1], (u8*)gUnknown_0203CF1C + ((gUnknown_0203CF1C->unk40C0 << 12) + 0xBC));
        ShowBg(1);
        ShowBg(2);
    }
    ChangeBgX(data[1], 0x2000, 1);
    data[0] += 32;
    if (data[0] > 0xFF)
    {
        gTasks[taskId].func = sub_81C0C68;
    }
}

void sub_81C0C68(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    gUnknown_0203CF1C->unk40C9 ^= 1;
    data[1] = 0;
    data[0] = 0;
    sub_81C1BA0();
    sub_81C2AFC(gUnknown_0203CF1C->unk40C0);
    sub_81C4280();
    sub_81C0E24();
    SwitchTaskToFollowupFunc(taskId);
}

void sub_81C0CC4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (gUnknown_0203CF1C->unk40C9 == 0)
            data[1] = 2;
        else
            data[1] = 1;
        ChangeBgX(data[1], 0x10000, 0);
    }
    ChangeBgX(data[1], 0x2000, 2);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = sub_81C0D44;
}

void sub_81C0D44(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (gUnknown_0203CF1C->unk40C9 == 0)
    {
        SetBgAttribute(1, 7, 1);
        SetBgAttribute(2, 7, 2);
        schedule_bg_copy_tilemap_to_vram(2);
    }
    else
    {
        SetBgAttribute(2, 7, 1);
        SetBgAttribute(1, 7, 2);
        schedule_bg_copy_tilemap_to_vram(1);
    }
    if (gUnknown_0203CF1C->unk40C0 > 1)
    {
        SetBgTilemapBuffer(data[1], (u8*)gUnknown_0203CF1C + ((gUnknown_0203CF1C->unk40C0 << 12) + 0xFFFFF0BC));
        ChangeBgX(data[1], 0x10000, 0);
    }
    ShowBg(1);
    ShowBg(2);
    gUnknown_0203CF1C->unk40C9 ^= 1;
    data[1] = 0;
    data[0] = 0;
    sub_81C1BA0();
    sub_81C2AFC(gUnknown_0203CF1C->unk40C0);
    sub_81C4280();
    sub_81C0E24();
    SwitchTaskToFollowupFunc(taskId);
}

void sub_81C0E24()
{
    if (gUnknown_0203CF1C->unk40C0 == 1)
        sub_81C22CC(&gUnknown_0203CF1C->currentPoke);
}

void sub_81C0E48(u8 taskId)
{
    u16 move;
    gUnknown_0203CF1C->unionThing.fooFiller.unk40C6 = 0;
    move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unionThing.fooFiller.unk40C6];
    ClearWindowTilemap(0x13);
    if (gSprites[gUnknown_0203CF1C->unk40D5].invisible == 0)
        ClearWindowTilemap(0xD);
    sub_81C1DA4(9, -3);
    sub_81C1EFC(9, -3, move);
    if (gUnknown_0203CF1C->unk40C8 == 0)
    {
        ClearWindowTilemap(5);
        PutWindowTilemap(6);
    }
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap2, 3, 0);
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap3, 1, 0);
    sub_81C3E9C(move);
    sub_81C3F44();
    sub_81C44F0();
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    sub_81C4AF8(8);
    gTasks[taskId].func = sub_81C0F44;
}

void sub_81C0F44(u8 taskId)
{
    u8 id = taskId;
    s16 *data = gTasks[taskId].data;
    if (sub_81221EC() != 1)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[0] = 4;
            sub_81C1070(data, -1, &gUnknown_0203CF1C->unionThing.fooFiller.unk40C6);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[0] = 4;
            sub_81C1070(data, 1, &gUnknown_0203CF1C->unionThing.fooFiller.unk40C6);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C8 == 1 || ((int)(gUnknown_0203CF1C->unionThing.loadThis & 0xFFFFFF) == 0x40000))
            {
                PlaySE(SE_SELECT);
                sub_81C11F4(taskId);
            }
            else if (sub_81C1040() == 1)
            {
                PlaySE(SE_SELECT);
                sub_81C129C(taskId);
            }
            else
                PlaySE(0x20);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_81C11F4(id);
        }
    }
}

u8 sub_81C1040()
{
    u8 i;
    for (i = 1; i <= 3; i++)
    {
        if (gUnknown_0203CF1C->summary.moves[i] != 0)
            return 1;
    }
    return 0;
}

/* void sub_81C1070(s16* a, s8 b, u8* c)
{
    s8 i;
    s8 d = c*;
    PlaySE(SE_SELECT);
    i = 0;
    while (i <= 3)
    {
        d += b
        if (d > a[0])
            d = 0;
        else if (d < 0)
            d = data[0];
        if (d == 4)
            break;
        
    }
} */
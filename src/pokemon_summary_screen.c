#include "battle.h"
#include "bg.h"
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
extern u8 gUnknown_08329D22[];
extern u8 gUnknown_0203CF21;
extern u16 gSpecialVar_0x8005;
extern struct unkStruct_61CC04 gUnknown_0861CC04;
extern struct unkStruct_61CC04 gUnknown_0861CC10;
extern struct unkStruct_61CC04 gUnknown_0861CBEC;
extern struct unkStruct_61CC04 gUnknown_0861CBF8;
extern u16 gUnknown_08DC3CD4[];

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
extern void sub_81C1E20(u8 taskId);

extern u32 ChangeBgX(u8 bg, u32 value, u8 op);

void sub_81BFAE4(void);
void sub_81BFE24();
u8 sub_81BFEB0();
void sub_81C2554();
void sub_81C1BA0();
void sub_81C0098(struct Pokemon* a);
bool8 sub_81C00F0(struct Pokemon* a);
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
void sub_81C1DA4(u16 a, s16 b);
void sub_81C1EFC(u16 a, s16 b, u16 c);
void sub_81C240C(u16 a);
void sub_81C2194(u16 *a, u16 b, u8 c);
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
bool8 sub_81C0A50(struct Pokemon* mon);
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
bool8 sub_81C1040();
void sub_81C4064();
void sub_81C4C60(u8 a);
void sub_81C12E4(u8 taskId);
void sub_81C4C84(u8 a);
void sub_81C13B0(u8 a, u8 b);
void sub_81C14BC(struct Pokemon *mon, u8 a, u8 b);
void sub_81C15EC(struct BoxPokemon *mon, u8 a, u8 b);
void sub_81C40A0(u8 a, u8 b);
void sub_81C4568(u8 a, u8 b);
void sub_81C174C(u8 taskId);
u8 sub_81C18A8();
void sub_81C18F4(u8 a);
u8 sub_81B6D14(u16 a);
void sub_81C1940(u8 taskId);
void sub_81C4154();
void sub_81C1F80(u8 taskId);

void SetBgAttribute(u8 bg, u8 attributeId, u8 value);

bool8 sub_81BFB10();
u8 sub_81B1250();

union unkUnion
{
    struct Pokemon mons[6];
    struct BoxPokemon boxMons[6];
};


u8 sub_80D214C(union unkUnion* a, u8 b, u8 c, u8 d);

struct pokeSummary
{
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

struct unkSummaryStruct
{
    /*0x00*/ union unkUnion *unk0;
    /*0x04*/ void *unk4;
    /*0x08*/ void *unk8;
    /*0x0C*/ struct Pokemon currentPoke;
    /*0x70*/ struct pokeSummary summary;
    u16 unkTilemap0[0x400];
    u16 unkTilemap0_1[0x400];
    u16 unkTilemap1[0x400];
    u16 unkTilemap1_1[0x400];
    u16 unkTilemap2[0x400];
    u16 unkTilemap2_1[0x400];
    u16 unkTilemap3[0x400];
    u16 unkTilemap3_1[0x400];
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
    u8 unk40C7;
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

void sub_81BF8EC(u8 a, void *b, u8 c, u8 d, void *e)
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

void sub_81BFA38(void *a, u8 b, u8 c, void *d, u16 e)
{
    sub_81BF8EC(3, a, b, c, d);
    gUnknown_0203CF1C->unk40C4 = e;
}

void sub_81BFA80(u8 a, void *b, u8 c, u8 d, void *e)
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
    while (1)
    {
        if (sub_81221EC() == 1 || sub_81BFB10() == TRUE || sub_81221AC() == 1)
            break;
    }
}

bool8 sub_81BFB10(void)
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
        if (sub_81C00F0(&gUnknown_0203CF1C->currentPoke) != 0)
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
        return TRUE;
    }
    return FALSE;
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

void sub_81C0098(struct Pokemon *poke)
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

bool8 sub_81C00F0(struct Pokemon *a)
{
    u32 i;
    struct pokeSummary *sum = &gUnknown_0203CF1C->summary;
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
        return TRUE;
    }
    gUnknown_0203CF1C->unk40F0++;
    return FALSE;
}

void sub_81C0348(void)
{
    if (gUnknown_0203CF1C->unk40C0 != 2 && gUnknown_0203CF1C->unk40C0 != 3)
    {
        sub_81C1DA4(0, 255);
        sub_81C1EFC(0, 255, 0);
    }
    else
    {
        sub_81C240C(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6]);
        sub_81C2194(&gUnknown_0203CF1C->unkTilemap2[0], 3, 0);
        sub_81C2194(&gUnknown_0203CF1C->unkTilemap3[0], 1, 0);
        SetBgTilemapBuffer(1, &gUnknown_0203CF1C->unkTilemap3);
        SetBgTilemapBuffer(2, &gUnknown_0203CF1C->unkTilemap2);
        ChangeBgX(2, 0x10000, 1);
        ClearWindowTilemap(0x13);
        ClearWindowTilemap(0xD);
    }
    if (gUnknown_0203CF1C->summary.unk7 == 0)
    {
        sub_81C2074(0, 0xFF);
    }
    else
    {
        if (gUnknown_0203CF1C->unk40C0 != 2 && gUnknown_0203CF1C->unk40C0 != 3)
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
    if (sub_81221EC() != 1 && !gPaletteFade.active)
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
    if (sub_81221EC() != 1 && !gPaletteFade.active)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            sub_81C0604(taskId, -1);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            sub_81C0604(taskId, 1);
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysState() == 1)
        {
            sub_81C0A8C(taskId, -1);
        }
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysState() == 2)
        {
            sub_81C0A8C(taskId, 1);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C0 != 1)
            {
                if (gUnknown_0203CF1C->unk40C0 == 0)
                {
                    sub_81C48F0();
                    PlaySE(SE_SELECT);
                    sub_81C044C(taskId);
                }
                else
                {
                    PlaySE(SE_SELECT);
                    sub_81C0E48(taskId);
                }
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_81C48F0();
            PlaySE(SE_SELECT);
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
        if (sub_81C00F0(&gUnknown_0203CF1C->currentPoke) == FALSE)
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
        if (sub_81C0A50(&mons[b]) == TRUE)
            return b;
    }
}

bool8 sub_81C0A50(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == 0)
        return FALSE;
    else if (gUnknown_0203CF1C->unk40BE != 0 || GetMonData(mon, MON_DATA_IS_EGG) == 0)
        return TRUE;
    else
        return FALSE;
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
        gTasks[taskId].func = sub_81C0C68;
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
    gUnknown_0203CF1C->unk40C6 = 0;
    move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6];
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
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap2[0], 3, 0);
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap3[0], 1, 0);
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
            sub_81C1070(data, -1, &gUnknown_0203CF1C->unk40C6);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[0] = 4;
            sub_81C1070(data, 1, &gUnknown_0203CF1C->unk40C6);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C8 == 1
             || (gUnknown_0203CF1C->unk40C4 == 0 && gUnknown_0203CF1C->unk40C6 == 4))
            {
                PlaySE(SE_SELECT);
                sub_81C11F4(taskId);
            }
            else if (sub_81C1040() == TRUE)
            {
                PlaySE(SE_SELECT);
                sub_81C129C(taskId);
            }
            else
            {
                PlaySE(SE_HAZURE);
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_81C11F4(id);
        }
    }
}

bool8 sub_81C1040(void)
{
    u8 i;
    for (i = 1; i < 4; i++)
    {
        if (gUnknown_0203CF1C->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

void sub_81C4D18();

void sub_81C1070(s16 *a, s8 b, u8 *c)
{
    s8 i;
    s8 moveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    moveIndex = *c;
    for (i = 0; i < 4; i++)
    {
        moveIndex += b;
        if (moveIndex > a[0])
            moveIndex = 0;
        else if (moveIndex < 0)
            moveIndex = a[0];
        if (moveIndex == 4)
        {
            move = gUnknown_0203CF1C->unk40C4;
            break;
        }
        move = gUnknown_0203CF1C->summary.moves[moveIndex];
        if (move != 0)
            break;
    }
    sub_81C240C(move);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    sub_81C3E9C(move);
    if ((*c == 4 && gUnknown_0203CF1C->unk40C4 == 0) || a[1] == 1)
    {
        ClearWindowTilemap(19);
        if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
            ClearWindowTilemap(13);
        schedule_bg_copy_tilemap_to_vram(0);
        sub_81C1DA4(9, -3);
        sub_81C1EFC(9, -3, move);
    }
    if (*c != 4 && moveIndex == 4 && gUnknown_0203CF1C->unk40C4 == 0)
    {
        ClearWindowTilemap(14);
        ClearWindowTilemap(15);
        schedule_bg_copy_tilemap_to_vram(0);
        sub_81C1DA4(0, 3);
        sub_81C1EFC(0, 3, 0);
    }
    *c = moveIndex;
    if (c == &gUnknown_0203CF1C->unk40C6)
        sub_81C4D18(8);
    else
        sub_81C4D18(18);
}

void sub_81C11F4(u8 taskId)
{
    sub_81C4C60(8);
    ClearWindowTilemap(6);
    PutWindowTilemap(5);
    sub_81C3E9C(0);
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap2[0], 3, 1);
    sub_81C2194(&gUnknown_0203CF1C->unkTilemap3[0], 1, 1);
    sub_81C4064();
    if (gUnknown_0203CF1C->unk40C6 != 4)
    {
        ClearWindowTilemap(14);
        ClearWindowTilemap(15);
        sub_81C1DA4(0, 3);
        sub_81C1EFC(0, 3, 0);
    }
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81C0510;
}

void sub_81C129C(u8 taskId)
{
    gUnknown_0203CF1C->unk40C7 = gUnknown_0203CF1C->unk40C6;
    sub_81C4C84(1);
    sub_81C4AF8(18);
    gTasks[taskId].func = sub_81C12E4;
}

void sub_81C12E4(u8 taskId)
{
    u8 a = taskId;
    s16* data = gTasks[taskId].data;
    if (sub_81221EC() != 1)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[0] = 3;
            sub_81C1070(&data[0], -1, &gUnknown_0203CF1C->unk40C7);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[0] = 3;
            sub_81C1070(&data[0], 1, &gUnknown_0203CF1C->unk40C7);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C6 == gUnknown_0203CF1C->unk40C7)
            {
                sub_81C13B0(taskId, 0);
            }
            else
                sub_81C13B0(taskId, 1);
        }
        else if (gMain.newKeys & B_BUTTON)
            sub_81C13B0(a, 0);
    }
}

void sub_81C13B0(u8 taskId, u8 b)
{
    u16 move;
    PlaySE(SE_SELECT);
    sub_81C4C84(0);
    sub_81C4C60(18);
    if (b == 1)
    {
        if (gUnknown_0203CF1C->unk40BD == 0)
        {
            struct Pokemon *why = gUnknown_0203CF1C->unk0->mons;
            sub_81C14BC(&why[gUnknown_0203CF1C->unk40BE], gUnknown_0203CF1C->unk40C6, gUnknown_0203CF1C->unk40C7);
        }
        else
        {
            struct BoxPokemon *why = gUnknown_0203CF1C->unk0->boxMons;
            sub_81C15EC(&why[gUnknown_0203CF1C->unk40BE], gUnknown_0203CF1C->unk40C6, gUnknown_0203CF1C->unk40C7);
        }
        sub_81C0098(&gUnknown_0203CF1C->currentPoke);
        sub_81C40A0(gUnknown_0203CF1C->unk40C6, gUnknown_0203CF1C->unk40C7);
        sub_81C4568(gUnknown_0203CF1C->unk40C6, gUnknown_0203CF1C->unk40C7);
        gUnknown_0203CF1C->unk40C6 = gUnknown_0203CF1C->unk40C7;
    }
    move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6];
    sub_81C3E9C(move);
    sub_81C240C(move);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81C0F44;
}


#ifdef NONMATCHING
void sub_81C14BC(struct Pokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    u16 localMoveTo;
    u16 localMoveFrom;
    u8 localPpTo;
    u8 localPpFrom;
    u8 localPpBonuses;
    u16* moveFromPtr;
    u16* moveToPtr;
    u8* ppFromPtr;
    u8* ppToPtr;
    u8* ppBonusesPtr;

    moveFromPtr = &gUnknown_0203CF1C->summary.moves[swappingFromId];
    localMoveFrom = *moveFromPtr;

    moveToPtr = &gUnknown_0203CF1C->summary.moves[swappingToId];
    localMoveTo = *moveToPtr;

    ppFromPtr = &gUnknown_0203CF1C->summary.pp[swappingFromId];
    localPpFrom = *ppFromPtr;

    ppToPtr = &gUnknown_0203CF1C->summary.pp[swappingToId];
    localPpTo = *ppToPtr;

    ppBonusesPtr = &gUnknown_0203CF1C->summary.ppBonuses;
    localPpBonuses = *ppBonusesPtr;

{
    u8 bitsFrom, bitsTo;

    bitsFrom = (localPpBonuses & gUnknown_08329D22[swappingFromId]) >> (swappingFromId << 1);
    bitsTo = (localPpBonuses & gUnknown_08329D22[swappingToId]) >> (swappingToId << 1);


    localPpBonuses &= ~(gUnknown_08329D22[swappingFromId]);
    localPpBonuses &= ~(gUnknown_08329D22[swappingToId]);

    localPpBonuses |= ((bitsFrom << (swappingToId << 1)) + (bitsTo << (swappingToId << 1)));
}

    SetMonData(mon, swappingFromId + MON_DATA_MOVE1, &localMoveTo);
    SetMonData(mon, swappingToId + MON_DATA_MOVE1, &localMoveFrom);

    SetMonData(mon, swappingFromId + MON_DATA_PP1, &localPpTo);
    SetMonData(mon, swappingToId + MON_DATA_PP1, &localPpFrom);

    SetMonData(mon, MON_DATA_PP_BONUSES, &localPpBonuses);

    *moveFromPtr = localMoveTo;
    *moveToPtr = localMoveFrom;

    *ppFromPtr = localPpTo;
    *ppToPtr = localPpFrom;

    *ppBonusesPtr = localPpBonuses;
}
#else
__attribute__((naked))
void sub_81C14BC(struct Pokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x28\n\
	adds r7, r0, 0\n\
	adds r4, r1, 0\n\
	adds r6, r2, 0\n\
	lsls r4, 24\n\
	lsrs r4, 24\n\
	lsls r6, 24\n\
	lsrs r6, 24\n\
	ldr r0, =gUnknown_0203CF1C\n\
	ldr r2, [r0]\n\
	lsls r0, r4, 1\n\
	mov r10, r0\n\
	adds r1, r2, 0\n\
	adds r1, 0x84\n\
	adds r0, r1, r0\n\
	str r0, [sp, 0x8]\n\
	ldrh r0, [r0]\n\
	mov r3, sp\n\
	adds r3, 0x2\n\
	str r3, [sp, 0x1C]\n\
	strh r0, [r3]\n\
	lsls r0, r6, 1\n\
	mov r9, r0\n\
	add r1, r9\n\
	str r1, [sp, 0xC]\n\
	ldrh r1, [r1]\n\
	mov r0, sp\n\
	strh r1, [r0]\n\
	adds r1, r2, 0\n\
	adds r1, 0x8C\n\
	adds r3, r1, r4\n\
	str r3, [sp, 0x10]\n\
	ldrb r0, [r3]\n\
	mov r3, sp\n\
	adds r3, 0x5\n\
	str r3, [sp, 0x24]\n\
	strb r0, [r3]\n\
	adds r1, r6\n\
	str r1, [sp, 0x14]\n\
	ldrb r0, [r1]\n\
	mov r1, sp\n\
	adds r1, 0x4\n\
	str r1, [sp, 0x20]\n\
	strb r0, [r1]\n\
	adds r2, 0xA4\n\
	str r2, [sp, 0x18]\n\
	ldrb r0, [r2]\n\
	mov r5, sp\n\
	adds r5, 0x6\n\
	strb r0, [r5]\n\
	ldr r1, =gUnknown_08329D22\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldrb r0, [r5]\n\
	adds r2, r0, 0\n\
	mov r3, r8\n\
	ands r2, r3\n\
	mov r3, r10\n\
	asrs r2, r3\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	adds r1, r6, r1\n\
	ldrb r1, [r1]\n\
	mov r12, r1\n\
	adds r1, r0, 0\n\
	mov r3, r12\n\
	ands r1, r3\n\
	mov r3, r9\n\
	asrs r1, r3\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r3, r8\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	ldrb r0, [r5]\n\
	mov r3, r12\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	mov r0, r9\n\
	lsls r2, r0\n\
	mov r3, r10\n\
	lsls r1, r3\n\
	adds r2, r1\n\
	ldrb r0, [r5]\n\
	orrs r0, r2\n\
	strb r0, [r5]\n\
	adds r1, r4, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	mov r2, sp\n\
	bl SetMonData\n\
	adds r1, r6, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	ldr r2, [sp, 0x1C]\n\
	bl SetMonData\n\
	adds r4, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r4, 0\n\
	ldr r2, [sp, 0x20]\n\
	bl SetMonData\n\
	adds r6, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r6, 0\n\
	ldr r2, [sp, 0x24]\n\
	bl SetMonData\n\
	adds r0, r7, 0\n\
	movs r1, 0x15\n\
	adds r2, r5, 0\n\
	bl SetMonData\n\
	mov r0, sp\n\
	ldrh r0, [r0]\n\
	ldr r1, [sp, 0x8]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x1C]\n\
	ldrh r0, [r3]\n\
	ldr r1, [sp, 0xC]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x20]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x10]\n\
	strb r0, [r1]\n\
	ldr r3, [sp, 0x24]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x14]\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	ldr r3, [sp, 0x18]\n\
	strb r0, [r3]\n\
	add sp, 0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
	.syntax divided\n");
}
#endif

#ifdef NONMATCHING
void sub_81C15EC(struct BoxPokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    u16 localMoveTo;
    u16 localMoveFrom;
    u8 localPpTo;
    u8 localPpFrom;
    u8 localPpBonuses;
    u16* moveFromPtr;
    u16* moveToPtr;
    u8* ppFromPtr;
    u8* ppToPtr;
    u8* ppBonusesPtr;

    moveFromPtr = &gUnknown_0203CF1C->summary.moves[swappingFromId];
    localMoveFrom = *moveFromPtr;

    moveToPtr = &gUnknown_0203CF1C->summary.moves[swappingToId];
    localMoveTo = *moveToPtr;

    ppFromPtr = &gUnknown_0203CF1C->summary.pp[swappingFromId];
    localPpFrom = *ppFromPtr;

    ppToPtr = &gUnknown_0203CF1C->summary.pp[swappingToId];
    localPpTo = *ppToPtr;

    ppBonusesPtr = &gUnknown_0203CF1C->summary.ppBonuses;
    localPpBonuses = *ppBonusesPtr;

{
    u8 bitsFrom, bitsTo;

    bitsFrom = (localPpBonuses & gUnknown_08329D22[swappingFromId]) >> (swappingFromId << 1);
    bitsTo = (localPpBonuses & gUnknown_08329D22[swappingToId]) >> (swappingToId << 1);


    localPpBonuses &= ~(gUnknown_08329D22[swappingFromId]);
    localPpBonuses &= ~(gUnknown_08329D22[swappingToId]);

    localPpBonuses |= ((bitsFrom << (swappingToId << 1)) + (bitsTo << (swappingToId << 1)));
}

    SetBoxMonData(mon, swappingFromId + MON_DATA_MOVE1, &localMoveTo);
    SetBoxMonData(mon, swappingToId + MON_DATA_MOVE1, &localMoveFrom);

    SetBoxMonData(mon, swappingFromId + MON_DATA_PP1, &localPpTo);
    SetBoxMonData(mon, swappingToId + MON_DATA_PP1, &localPpFrom);

    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &localPpBonuses);

    *moveFromPtr = localMoveTo;
    *moveToPtr = localMoveFrom;

    *ppFromPtr = localPpTo;
    *ppToPtr = localPpFrom;

    *ppBonusesPtr = localPpBonuses;
}
#else
__attribute__((naked))
void sub_81C15EC(struct BoxPokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x28\n\
	adds r7, r0, 0\n\
	adds r4, r1, 0\n\
	adds r6, r2, 0\n\
	lsls r4, 24\n\
	lsrs r4, 24\n\
	lsls r6, 24\n\
	lsrs r6, 24\n\
	ldr r0, =gUnknown_0203CF1C\n\
	ldr r2, [r0]\n\
	lsls r0, r4, 1\n\
	mov r10, r0\n\
	adds r1, r2, 0\n\
	adds r1, 0x84\n\
	adds r0, r1, r0\n\
	str r0, [sp, 0x8]\n\
	ldrh r0, [r0]\n\
	mov r3, sp\n\
	adds r3, 0x2\n\
	str r3, [sp, 0x1C]\n\
	strh r0, [r3]\n\
	lsls r0, r6, 1\n\
	mov r9, r0\n\
	add r1, r9\n\
	str r1, [sp, 0xC]\n\
	ldrh r1, [r1]\n\
	mov r0, sp\n\
	strh r1, [r0]\n\
	adds r1, r2, 0\n\
	adds r1, 0x8C\n\
	adds r3, r1, r4\n\
	str r3, [sp, 0x10]\n\
	ldrb r0, [r3]\n\
	mov r3, sp\n\
	adds r3, 0x5\n\
	str r3, [sp, 0x24]\n\
	strb r0, [r3]\n\
	adds r1, r6\n\
	str r1, [sp, 0x14]\n\
	ldrb r0, [r1]\n\
	mov r1, sp\n\
	adds r1, 0x4\n\
	str r1, [sp, 0x20]\n\
	strb r0, [r1]\n\
	adds r2, 0xA4\n\
	str r2, [sp, 0x18]\n\
	ldrb r0, [r2]\n\
	mov r5, sp\n\
	adds r5, 0x6\n\
	strb r0, [r5]\n\
	ldr r1, =gUnknown_08329D22\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldrb r0, [r5]\n\
	adds r2, r0, 0\n\
	mov r3, r8\n\
	ands r2, r3\n\
	mov r3, r10\n\
	asrs r2, r3\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	adds r1, r6, r1\n\
	ldrb r1, [r1]\n\
	mov r12, r1\n\
	adds r1, r0, 0\n\
	mov r3, r12\n\
	ands r1, r3\n\
	mov r3, r9\n\
	asrs r1, r3\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r3, r8\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	ldrb r0, [r5]\n\
	mov r3, r12\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	mov r0, r9\n\
	lsls r2, r0\n\
	mov r3, r10\n\
	lsls r1, r3\n\
	adds r2, r1\n\
	ldrb r0, [r5]\n\
	orrs r0, r2\n\
	strb r0, [r5]\n\
	adds r1, r4, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	mov r2, sp\n\
	bl SetBoxMonData\n\
	adds r1, r6, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	ldr r2, [sp, 0x1C]\n\
	bl SetBoxMonData\n\
	adds r4, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r4, 0\n\
	ldr r2, [sp, 0x20]\n\
	bl SetBoxMonData\n\
	adds r6, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r6, 0\n\
	ldr r2, [sp, 0x24]\n\
	bl SetBoxMonData\n\
	adds r0, r7, 0\n\
	movs r1, 0x15\n\
	adds r2, r5, 0\n\
	bl SetBoxMonData\n\
	mov r0, sp\n\
	ldrh r0, [r0]\n\
	ldr r1, [sp, 0x8]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x1C]\n\
	ldrh r0, [r3]\n\
	ldr r1, [sp, 0xC]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x20]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x10]\n\
	strb r0, [r1]\n\
	ldr r3, [sp, 0x24]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x14]\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	ldr r3, [sp, 0x18]\n\
	strb r0, [r3]\n\
	add sp, 0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided\n");
}
#endif

void sub_81C171C(u8 taskId)
{
    sub_81C44F0();
    sub_81C4AF8(8);
    gTasks[taskId].func = sub_81C174C;
}

void sub_81C174C(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (sub_81221EC() != 1)
    {
        if (gPaletteFade.active != 1)
        {
            if (gMain.newKeys & DPAD_UP)
            {
                data[0] = 4;
                sub_81C1070(data, -1, &gUnknown_0203CF1C->unk40C6);
            }
            else if (gMain.newKeys & DPAD_DOWN)
            {
                data[0] = 4;
                sub_81C1070(data, 1, &gUnknown_0203CF1C->unk40C6);
            }
            else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
            {
                sub_81C0A8C(taskId, -1);
            }
            else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
            {
                sub_81C0A8C(taskId, 1);
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                if (sub_81C18A8() == 1)
                {
                    sub_81C48F0();
                    PlaySE(SE_SELECT);
                    gUnknown_0203CF21 = gUnknown_0203CF1C->unk40C6;
                    gSpecialVar_0x8005 = gUnknown_0203CF21;
                    sub_81C044C(taskId);
                }
                else
                {
                    PlaySE(0x20);
                    sub_81C18F4(taskId);
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                u32 var1;
                sub_81C48F0();
                PlaySE(SE_SELECT);
                gUnknown_0203CF21 = 4;
                gSpecialVar_0x8005 = 4;
                sub_81C044C(taskId);
            }   
        }
    }
}

u8 sub_81C18A8()
{
    if (gUnknown_0203CF1C->unk40C6 == 4 || gUnknown_0203CF1C->unk40C4 == 0 || sub_81B6D14(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6]) != 1)
        return 1;
    else
        return 0;
}

void sub_81C18F4(u8 taskId)
{
    ClearWindowTilemap(14);
    ClearWindowTilemap(15);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_81C1DA4(0, 3);
    sub_81C1EFC(0, 3, 0);
    sub_81C4154();
    gTasks[taskId].func = sub_81C1940;
}

void sub_81C1940(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 move;
    if (FuncIsActiveTask(sub_81C1E20) != 1)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[1] = 1;
            data[0] = 4;
            sub_81C1070(&data[0], -1, &gUnknown_0203CF1C->unk40C6);
            data[1] = 0;
            gTasks[taskId].func = sub_81C174C;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[1] = 1;
            data[0] = 4;
            sub_81C1070(&data[0], 1, &gUnknown_0203CF1C->unk40C6);
            data[1] = 0;
            gTasks[taskId].func = sub_81C174C;
        }
        else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
        {
            if (gUnknown_0203CF1C->unk40C0 != 2)
            {
                
                ClearWindowTilemap(19);
                if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
                    ClearWindowTilemap(13);
                move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6];
                gTasks[taskId].func = sub_81C174C;
                sub_81C0A8C(taskId, -1);
                sub_81C1DA4(9, -2);
                sub_81C1EFC(9, -2, move);
            }
        }
        else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
        {
            if (gUnknown_0203CF1C->unk40C0 != 3)
            {
                ClearWindowTilemap(19);
                if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
                    ClearWindowTilemap(13);
                move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6];
                gTasks[taskId].func = sub_81C174C;
                sub_81C0A8C(taskId, 1);
                sub_81C1DA4(9, -2);
                sub_81C1EFC(9, -2, move);
            }
        }
        else if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            ClearWindowTilemap(19);
            if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
                ClearWindowTilemap(13);
            move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->unk40C6];
            sub_81C3E9C(move);
            schedule_bg_copy_tilemap_to_vram(0);
            sub_81C1DA4(9, -3);
            sub_81C1EFC(9, -3, move);
            gTasks[taskId].func = sub_81C174C;
        }
    }
}

u8 sub_81C1B94()
{
    return gUnknown_0203CF21;
}

void sub_81C1BA0()
{
    u16 *alloced = Alloc(32);
    u8 i;
    for (i = 0; i < 4; i++)
    {
        u8 j = i << 1;
        if (i < gUnknown_0203CF1C->unk40C1)
        {
            alloced[j+0] = 0x40;
            alloced[j+1] = 0x40;
            alloced[j+8] = 0x50;
            alloced[j+9] = 0x50;
        }
        else if (i > gUnknown_0203CF1C->unk40C2)
        {
            alloced[j+0] = 0x4A;
            alloced[j+1] = 0x4A;
            alloced[j+8] = 0x5A;
            alloced[j+9] = 0x5A;
        }
        else if (i < gUnknown_0203CF1C->unk40C0)
        {
            alloced[j+0] = 0x46;
            alloced[j+1] = 0x47;
            alloced[j+8] = 0x56;
            alloced[j+9] = 0x57;
        }
        else if (i == gUnknown_0203CF1C->unk40C0)
        {
            if (i != gUnknown_0203CF1C->unk40C2)
            {
                alloced[j+0] = 0x41;
                alloced[j+1] = 0x42;
                alloced[j+8] = 0x51;
                alloced[j+9] = 0x52;
            }
            else
            {
                alloced[j+0] = 0x4B;
                alloced[j+1] = 0x4C;
                alloced[j+8] = 0x5B;
                alloced[j+9] = 0x5C;
            }
        }
        else if (i != gUnknown_0203CF1C->unk40C2)
        {
            alloced[j+0] = 0x43;
            alloced[j+1] = 0x44;
            alloced[j+8] = 0x53;
            alloced[j+9] = 0x54;
        }
        else
        {
            alloced[j+0] = 0x48;
            alloced[j+1] = 0x49;
            alloced[j+8] = 0x58;
            alloced[j+9] = 0x59;
        }
    }
    CopyToBgTilemapBufferRect_ChangePalette(3, alloced, 11, 0, 8, 2, 16);
    schedule_bg_copy_tilemap_to_vram(3);
    Free(alloced);
}

struct unkStruct_61CC04
{
    u8 *ptr;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
};

#ifdef NONMATCHING
void sub_81C1CB0(struct unkStruct_61CC04 *a, u16 *b, u8 c, u8 d)
{
    u8 *alloced = Alloc(a->field_6 * (a->field_7 << 1));
    CpuFill16(a->field_4, alloced, a->field_7*a->field_6);
    if (a->field_6 != c)
    {
        if (!d)
        {
            for (d;d < a->field_7; d++)
            {
                CpuCopy16(&a->ptr + ((c + a->field_6*d)), alloced + ((a->field_6*d) << 1), (a->field_6 - c) * 2);
            }
        }
        else
        {
            for (d = 0;d < a->field_7; d++)
            {
                CpuCopy16(&a->ptr + (a->field_6*d), alloced + ((c + a->field_6*d) << 1), (a->field_6 - c) * 2);
            }
        }
    }
    d = 0;
    while (d < a->field_7)
    {
        CpuCopy16(alloced + ((a->field_6*d) << 1), b + ((((a->field_9 + d) << 5) + a->field_8) << 1), a->field_6 * 2);
        d++;
    }
    Free(alloced);
}
#else
__attribute__((naked))
void sub_81C1CB0(struct unkStruct_61CC04 *a, u16 *b, u8 c, u8 d)
{
    asm(".syntax unified\n\
        push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0x4\n\
	adds r4, r0, 0\n\
	mov r8, r1\n\
	lsls r2, 24\n\
	lsrs r6, r2, 24\n\
	lsls r3, 24\n\
	lsrs r5, r3, 24\n\
	ldrb r1, [r4, 0x6]\n\
	ldrb r0, [r4, 0x7]\n\
	lsls r0, 1\n\
	muls r0, r1\n\
	bl Alloc\n\
	adds r7, r0, 0\n\
	mov r1, sp\n\
	ldrh r0, [r4, 0x4]\n\
	strh r0, [r1]\n\
	ldrb r1, [r4, 0x7]\n\
	ldrb r0, [r4, 0x6]\n\
	adds r2, r1, 0\n\
	muls r2, r0\n\
	movs r0, 0x80\n\
	lsls r0, 17\n\
	orrs r2, r0\n\
	mov r0, sp\n\
	adds r1, r7, 0\n\
	bl CpuSet\n\
	ldrb r0, [r4, 0x6]\n\
	cmp r0, r6\n\
	beq _081C1D60\n\
	cmp r5, 0\n\
	bne _081C1D30\n\
	movs r5, 0\n\
	ldrb r0, [r4, 0x7]\n\
	cmp r5, r0\n\
	bcs _081C1D60\n\
_081C1D00:\n\
	ldrb r2, [r4, 0x6]\n\
	adds r1, r2, 0\n\
	muls r1, r5\n\
	adds r3, r6, r1\n\
	lsls r3, 1\n\
	ldr r0, [r4]\n\
	adds r0, r3\n\
	lsls r1, 1\n\
	adds r1, r7, r1\n\
	subs r2, r6\n\
	ldr r3, =0x001fffff\n\
	ands r2, r3\n\
	bl CpuSet\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	ldrb r3, [r4, 0x7]\n\
	cmp r5, r3\n\
	bcc _081C1D00\n\
	b _081C1D60\n\
	.pool\n\
_081C1D30:\n\
	movs r5, 0\n\
	ldrb r0, [r4, 0x7]\n\
	cmp r5, r0\n\
	bcs _081C1D60\n\
_081C1D38:\n\
	ldrb r2, [r4, 0x6]\n\
	adds r1, r2, 0\n\
	muls r1, r5\n\
	lsls r3, r1, 1\n\
	ldr r0, [r4]\n\
	adds r0, r3\n\
	adds r1, r6, r1\n\
	lsls r1, 1\n\
	adds r1, r7, r1\n\
	subs r2, r6\n\
	ldr r3, =0x001fffff\n\
	ands r2, r3\n\
	bl CpuSet\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	ldrb r3, [r4, 0x7]\n\
	cmp r5, r3\n\
	bcc _081C1D38\n\
_081C1D60:\n\
	movs r5, 0\n\
	b _081C1D8A\n\
	.pool\n\
_081C1D68:\n\
	ldrb r2, [r4, 0x6]\n\
	adds r0, r2, 0\n\
	muls r0, r5\n\
	lsls r0, 1\n\
	adds r0, r7, r0\n\
	ldrb r1, [r4, 0x9]\n\
	adds r1, r5\n\
	lsls r1, 5\n\
	ldrb r3, [r4, 0x8]\n\
	adds r1, r3\n\
	lsls r1, 1\n\
	add r1, r8\n\
	bl CpuSet\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
_081C1D8A:\n\
	ldrb r0, [r4, 0x7]\n\
	cmp r5, r0\n\
	bcc _081C1D68\n\
	adds r0, r7, 0\n\
	bl Free\n\
	add sp, 0x4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.syntax divided\n");
}
#endif

void sub_81C1DA4(u16 a, s16 b)
{
    if (b > gUnknown_0861CC04.field_6)
        b = gUnknown_0861CC04.field_6;
    if (b == 0 || b == gUnknown_0861CC04.field_6)
    {
        sub_81C1CB0(&gUnknown_0861CC04, &gUnknown_0203CF1C->unkTilemap2[0], b, 1);
    }
    else
    {
        u8 taskId = FindTaskIdByFunc(sub_81C1E20);
        if (taskId == 0xFF)
        {
            taskId = CreateTask(sub_81C1E20, 8);
        }
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }
}

void sub_81C1E20(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > gUnknown_0861CC04.field_6)
    {
        data[1] = gUnknown_0861CC04.field_6;
    }
    sub_81C1CB0(&gUnknown_0861CC04, &gUnknown_0203CF1C->unkTilemap2[0], data[1], 1);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CC04.field_6)
    {
        if (data[0] < 0)
        {
            if (gUnknown_0203CF1C->unk40C0 == 2)
                PutWindowTilemap(14);
            
        }
        else
        {
            if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
                PutWindowTilemap(13);
            PutWindowTilemap(19);
        }
        schedule_bg_copy_tilemap_to_vram(0);
        DestroyTask(taskId);
    }
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81C1EFC(u16 a, s16 b, u16 move)
{
    if (b > gUnknown_0861CC10.field_6)
        b = gUnknown_0861CC10.field_6;
    if (b == 0 || b == gUnknown_0861CC10.field_6)
        sub_81C1CB0(&gUnknown_0861CC10, &gUnknown_0203CF1C->unkTilemap3[0], b, 1);
    else
    {
        u8 taskId = FindTaskIdByFunc(sub_81C1F80);
        if (taskId == 0xFF)
            taskId = CreateTask(sub_81C1F80, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
        gTasks[taskId].data[2] = move;
    }
}

void sub_81C1F80(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > gUnknown_0861CC10.field_6)
    {
        data[1] = gUnknown_0861CC10.field_6;
    }
    sub_81C1CB0(&gUnknown_0861CC10, &gUnknown_0203CF1C->unkTilemap3[0], data[1], 1);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CC10.field_6)
    {
        if (data[0] < 0)
        {
            if (gUnknown_0203CF1C->unk40C0 == 3 && FuncIsActiveTask(sub_81C0B8C) == 0)
                PutWindowTilemap(15);
            sub_81C240C(data[2]);
        }
        else 
        {
            if (!gSprites[gUnknown_0203CF1C->unk40D5].invisible)
            {
                PutWindowTilemap(13);
            }
            PutWindowTilemap(19);
        }
        schedule_bg_copy_tilemap_to_vram(0);
        DestroyTask(taskId);
    }
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81C2074(u16 a, s16 b)
{
    if (b > gUnknown_0861CBEC.field_6)
        b = gUnknown_0861CBEC.field_6;
    if (b == 0 || b == gUnknown_0861CBEC.field_6)
    {
        sub_81C1CB0(&gUnknown_0861CBEC, &gUnknown_0203CF1C->unkTilemap0[0], b, 0);
        sub_81C1CB0(&gUnknown_0861CBF8, &gUnknown_0203CF1C->unkTilemap0[0], b, 0);
    }
    else
    {
        u8 taskId = CreateTask(sub_81C20F0, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }
}

void sub_81C20F0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
        data[1] = 0;
    else if (data[1] > gUnknown_0861CBEC.field_6)
        data[1] = gUnknown_0861CBEC.field_6;
    sub_81C1CB0(&gUnknown_0861CBEC, &gUnknown_0203CF1C->unkTilemap0[0], data[1], 0);
    sub_81C1CB0(&gUnknown_0861CBF8, &gUnknown_0203CF1C->unkTilemap0[0], data[1], 0);
    schedule_bg_copy_tilemap_to_vram(3);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CBEC.field_6)
    {
        if (data[0] < 0)
        {
            sub_81C4A88();
            PutWindowTilemap(13);
            schedule_bg_copy_tilemap_to_vram(0);
        }
        DestroyTask(taskId);
    }
}

/* void sub_81C2194(u16 *a, u16 b, u8 c)
{
    u16 i;
    int var;
    b *= 0x1000;
    var = 0x56A;

    if (c == 0)
    {
        for (i = 0; i < 20; i++)
        {
            a[(i + var) << 1] = gUnknown_08DC3CD4[i] + b;
            a[((i + var) << 1) + 0x40] = gUnknown_08DC3CD4[i] + b;
            a[((i + var) << 1) + 0x80] = gUnknown_08DC3CD4[i + 20] + b;
        }
    }
    else
    {
        for (i = 0; i < 20; i++)
        {
            a[(i + var)] = gUnknown_08DC3CD4[i + 20] + b;
            a[((i + var)) + 0x40] = gUnknown_08DC3CD4[i + 40] + b;
            a[((i + var)) + 0x80] = gUnknown_08DC3CD4[i + 40] + b;
        }
    }
} */
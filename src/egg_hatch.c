#include "global.h"
#include "pokemon.h"
#include "pokedex.h"
#include "items.h"
#include "script.h"
#include "decompress.h"
#include "task.h"
#include "palette.h"
#include "main.h"
#include "event_data.h"
#include "sound.h"
#include "songs.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"
#include "menu.h"
#include "trig.h"
#include "rng.h"
#include "malloc.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "bg.h"
#include "m4a.h"
#include "window.h"
#include "battle.h" // to get rid of later

struct EggHatchData
{
    u8 eggSpriteID;
    u8 pokeSpriteID;
    u8 CB2_state;
    u8 CB2_PalCounter;
    u8 eggPartyID;
    u8 unused_5;
    u8 unused_6;
    u8 eggShardVelocityID;
    u8 windowId;
    u8 unused_9;
    u8 unused_A;
    u16 species;
    struct TextColor textColor;
};

extern struct EggHatchData* gEggHatchData;

extern struct SpriteTemplate gUnknown_0202499C;
extern void (*gFieldCallback)(void);

extern const struct CompressedSpriteSheet gMonFrontPicTable[];
extern const struct BgTemplate gUnknown_0832C064[2];
extern const struct WindowTemplate gUnknown_0832C06C[2];
extern const u8 gUnknown_08C00000[];
extern const u8 gUnknown_08C00524[];
extern const u8 gUnknown_08C004E0[];
extern const struct SpriteSheet gUnknown_0832BFE4; // hatching egg
extern const struct SpriteSheet gUnknown_0832BFEC; // egg shell
extern const struct SpritePalette gUnknown_0832BFF4; // hatching egg
extern const u16 gUnknown_08DD7300[]; // palette, gameboy advance
extern const u32 gUnknown_08DD7360[]; // tileset gameboy advance
extern const u32 gUnknown_08331F60[]; // tilemap gameboy circle

extern u8* GetMonNick(struct Pokemon* mon, u8* dst);
extern u8* GetBoxMonNick(struct BoxPokemon* boxMon, u8* dst);
extern u8 sav1_map_get_name(void);
extern s8 sub_8198C58(void);
extern void sub_81DB5E8(u8* str1, u8* str2, u8);
extern void sub_806A068(u16, u8);
extern void fade_screen(u8, u8);
extern void overworld_free_bg_tilemaps(void);
extern void sub_80AF168(void);
extern void init_uns_table_pokemon_copy(void);
extern void sub_805F094(void);
extern void remove_some_task(void);
extern void reset_temp_tile_data_buffers(void);
extern void c2_exit_to_overworld_2_switch(void);
extern void play_some_sound(void);
extern void copy_decompressed_tile_data_to_vram_autofree(u8 bg_id, const void* src, u16 size, u16 offset, u8 mode);
extern void CreateYesNoMenu(const u8*, u16, u8, u8);
extern void DoNamingScreen(u8, const u8*, u16, u8, u32, MainCallback);
extern void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor* colors, s8 speed, u8 *str);

static void Task_EggHatch(u8 taskID);
static void CB2_EggHatch_0(void);
static void CB2_EggHatch_1(void);
static void SpriteCB_Egg_0(struct Sprite* sprite);
static void SpriteCB_Egg_1(struct Sprite* sprite);
static void SpriteCB_Egg_2(struct Sprite* sprite);
static void SpriteCB_Egg_3(struct Sprite* sprite);
static void SpriteCB_Egg_4(struct Sprite* sprite);
static void SpriteCB_Egg_5(struct Sprite* sprite);
static void SpriteCB_EggShard(struct Sprite* sprite);
static void EggHatchPrintMessage(u8 windowId, u8* string, u8 x, u8 y, u8 speed);
static void CreateRandomEggShardSprite(void);
static void CreateEggShardSprite(u8 x, u8 y, s16 data1, s16 data2, s16 data3, u8 spriteAnimIndex);

static void CreatedHatchedMon(struct Pokemon *egg, struct Pokemon *temp)
{
    u16 species;
    u32 personality, pokerus;
    u8 i, friendship, language, gameMet, markings, obedience;
    u16 moves[4];
    u32 ivs[6];


    species = GetMonData(egg, MON_DATA_SPECIES);

    for (i = 0; i < 4; i++)
    {
        moves[i] = GetMonData(egg, MON_DATA_MOVE1 + i);
    }

    personality = GetMonData(egg, MON_DATA_PERSONALITY);

    for (i = 0; i < 6; i++)
    {
        ivs[i] = GetMonData(egg, MON_DATA_HP_IV + i);
    }

    language = GetMonData(egg, MON_DATA_LANGUAGE);
    gameMet = GetMonData(egg, MON_DATA_MET_GAME);
    markings = GetMonData(egg, MON_DATA_MARKINGS);
    pokerus = GetMonData(egg, MON_DATA_POKERUS);
    obedience = GetMonData(egg, MON_DATA_OBEDIENCE);

    CreateMon(temp, species, 5, 32, TRUE, personality, 0, 0);

    for (i = 0; i < 4; i++)
    {
        SetMonData(temp, MON_DATA_MOVE1 + i,  &moves[i]);
    }

    for (i = 0; i < 6; i++)
    {
        SetMonData(temp, MON_DATA_HP_IV + i,  &ivs[i]);
    }

    language = GAME_LANGUAGE;
    SetMonData(temp, MON_DATA_LANGUAGE, &language);
    SetMonData(temp, MON_DATA_MET_GAME, &gameMet);
    SetMonData(temp, MON_DATA_MARKINGS, &markings);

    friendship = 120;
    SetMonData(temp, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(temp, MON_DATA_POKERUS, &pokerus);
    SetMonData(temp, MON_DATA_OBEDIENCE, &obedience);

    *egg = *temp;
}

static void AddHatchedMonToParty(u8 id)
{
    u8 isEgg = 0x46; // ?
    u16 pokeNum;
    u8 name[12];
    u16 ball;
    u16 caughtLvl;
    u8 mapNameID;
    struct Pokemon* mon = &gPlayerParty[id];

    CreatedHatchedMon(mon, &gEnemyParty[0]);
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);

    pokeNum = GetMonData(mon, MON_DATA_SPECIES);
    GetSpeciesName(name, pokeNum);
    SetMonData(mon, MON_DATA_NICKNAME, name);

    pokeNum = SpeciesToNationalPokedexNum(pokeNum);
    GetSetPokedexFlag(pokeNum, FLAG_SET_SEEN);
    GetSetPokedexFlag(pokeNum, FLAG_SET_CAUGHT);

    GetMonNick(mon, gStringVar1);

    ball = ITEM_POKE_BALL;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);

    caughtLvl = 0;
    SetMonData(mon, MON_DATA_MET_LEVEL, &caughtLvl);

    mapNameID = sav1_map_get_name();
    SetMonData(mon, MON_DATA_MET_LOCATION, &mapNameID);

    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void ScriptHatchMon(void)
{
    AddHatchedMonToParty(gSpecialVar_0x8004);
}

static bool8 sub_807158C(struct DaycareData* daycare, u8 daycareId)
{
    u8 nick[0x20];
    struct DaycareMon* daycareMon = &daycare->mons[daycareId];

    GetBoxMonNick(&daycareMon->mon, nick);
    if (daycareMon->mail.itemId != 0
        && (StringCompareWithoutExtCtrlCodes(nick, daycareMon->monName) != 0
            || StringCompareWithoutExtCtrlCodes(gSaveBlock2Ptr->playerName, daycareMon->OT_name) != 0))
    {
        StringCopy(gStringVar1, nick);
        sub_81DB5E8(gStringVar2, daycareMon->OT_name, daycareMon->language_maybe);
        sub_81DB5E8(gStringVar3, daycareMon->monName, daycareMon->unknown);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8071614(void)
{
    return sub_807158C(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

static u8 EggHatchCreateMonSprite(u8 a0, u8 switchID, u8 pokeID, u16* speciesLoc)
{
    u8 r5 = 0;
    u8 spriteID = 0;
    struct Pokemon* mon = NULL;

    if (a0 == 0)
    {
        mon = &gPlayerParty[pokeID];
        r5 = 1;
    }
    if (a0 == 1)
    {
        mon = &gPlayerParty[pokeID];
        r5 = 3;
    }
    switch (switchID)
    {
    case 0:
        {
            u16 species = GetMonData(mon, MON_DATA_SPECIES);
            u32 pid = GetMonData(mon, MON_DATA_PERSONALITY);
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species],
                                                      gBattleSpritesGfx->sprites[(a0 * 2) + 1],
                                                      species, pid);
            LoadCompressedObjectPalette(sub_806E794(mon));
            *speciesLoc = species;
        }
        break;
    case 1:
        sub_806A068(sub_806E794(mon)->tag, r5);
        spriteID = CreateSprite(&gUnknown_0202499C, 120, 75, 6);
        gSprites[spriteID].invisible = 1;
        gSprites[spriteID].callback = SpriteCallbackDummy;
        break;
    }
    return spriteID;
}

static void VBlankCB_EggHatch(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void EggHatch(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_EggHatch, 10);
    fade_screen(1, 0);
}

static void Task_EggHatch(u8 taskID)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_EggHatch_0);
        gFieldCallback = sub_80AF168;
        DestroyTask(taskID);
    }
}

static void CB2_EggHatch_0(void)
{
    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);

        gEggHatchData = Alloc(sizeof(struct EggHatchData));
        init_uns_table_pokemon_copy();
        gEggHatchData->eggPartyID = gSpecialVar_0x8004;
        gEggHatchData->eggShardVelocityID = 0;

        SetVBlankCallback(VBlankCB_EggHatch);
        gSpecialVar_0x8005 = GetCurrentMapMusic();

        reset_temp_tile_data_buffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_0832C064, 2);

        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);

        SetBgAttribute(1, BG_CTRL_ATTR_MOSAIC, 2);
        SetBgTilemapBuffer(1, Alloc(0x1000));
        SetBgTilemapBuffer(0, Alloc(0x2000));

        DeactivateAllTextPrinters();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        ResetSpriteData();
        ResetTasks();
        remove_some_task();
        m4aSoundVSyncOn();
        gMain.state++;
        break;
    case 1:
        InitWindows(gUnknown_0832C06C);
        gEggHatchData->windowId = 0;
        gMain.state++;
        break;
    case 2:
        copy_decompressed_tile_data_to_vram_autofree(0, gUnknown_08C00000, 0, 0, 0);
        CopyToBgTilemapBuffer(0, gUnknown_08C00524, 0, 0);
        LoadCompressedPalette(gUnknown_08C004E0, 0, 0x20);
        gMain.state++;
        break;
    case 3:
        LoadSpriteSheet(&gUnknown_0832BFE4);
        LoadSpriteSheet(&gUnknown_0832BFEC);
        LoadSpritePalette(&gUnknown_0832BFF4);
        gMain.state++;
        break;
    case 4:
        CopyBgTilemapBufferToVram(0);
        AddHatchedMonToParty(gEggHatchData->eggPartyID);
        gMain.state++;
        break;
    case 5:
        EggHatchCreateMonSprite(0, 0, gEggHatchData->eggPartyID, &gEggHatchData->species);
        gMain.state++;
        break;
    case 6:
        gEggHatchData->pokeSpriteID = EggHatchCreateMonSprite(0, 1, gEggHatchData->eggPartyID, &gEggHatchData->species);
        gMain.state++;
        break;
    case 7:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        LoadPalette(gUnknown_08DD7300, 0x10, 0xA0);
        LoadBgTiles(1, gUnknown_08DD7360, 0x1420, 0);
        CopyToBgTilemapBuffer(1, gUnknown_08331F60, 0x1000, 0);
        CopyBgTilemapBufferToVram(1);
        gMain.state++;
        break;
    case 8:
        SetMainCallback2(CB2_EggHatch_1);
        gEggHatchData->CB2_state = 0;
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void EggHatchSetMonNickname(void)
{
    SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar3);
    sub_805F094();
    Free(gEggHatchData);
    SetMainCallback2(c2_exit_to_overworld_2_switch);
}

static void Task_EggHatchPlayBGM(u8 taskID)
{
    if (gTasks[taskID].data[0] == 0)
    {
        StopMapMusic();
        play_some_sound();
    }
    if (gTasks[taskID].data[0] == 1)
        PlayBGM(376);
    if (gTasks[taskID].data[0] > 60)
    {
        PlayBGM(377);
        DestroyTask(taskID);
        // UB: task is destroyed, yet the value is incremented
    }
    gTasks[taskID].data[0]++;
}

extern const struct SpriteTemplate gUnknown_0832BFFC;
extern const u8 gUnknown_0832C07C[];
extern const u8 gOtherText_HatchedFromEgg[];
extern const u8 gOtherText_NickHatchPrompt[];

static void CB2_EggHatch_1(void)
{
    u16 species;
    u8 gender;
    u32 personality;

    switch (gEggHatchData->CB2_state)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        gEggHatchData->eggSpriteID = CreateSprite(&gUnknown_0832BFFC, 120, 75, 5);
        ShowBg(0);
        ShowBg(1);
        gEggHatchData->CB2_state++;
        CreateTask(Task_EggHatchPlayBGM, 5);
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            FillWindowPixelBuffer(gEggHatchData->windowId, 0);
            gEggHatchData->CB2_PalCounter = 0;
            gEggHatchData->CB2_state++;
        }
        break;
    case 2:
        if (++gEggHatchData->CB2_PalCounter > 30)
        {
            gEggHatchData->CB2_state++;
            gSprites[gEggHatchData->eggSpriteID].callback = SpriteCB_Egg_0;
        }
        break;
    case 3:
        if (gSprites[gEggHatchData->eggSpriteID].callback == SpriteCallbackDummy)
        {
            species = GetMonData(&gPlayerParty[gEggHatchData->eggPartyID], MON_DATA_SPECIES);
            DoMonFrontSpriteAnimation(&gSprites[gEggHatchData->pokeSpriteID], species, FALSE, 1);
            gEggHatchData->CB2_state++;
        }
        break;
    case 4:
        if (gSprites[gEggHatchData->pokeSpriteID].callback == SpriteCallbackDummy)
        {
            gEggHatchData->CB2_state++;
        }
        break;
    case 5:
        GetMonNick(&gPlayerParty[gEggHatchData->eggPartyID], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gOtherText_HatchedFromEgg);
        EggHatchPrintMessage(gEggHatchData->windowId, gStringVar4, 0, 3, 0xFF);
        PlayFanfare(371);
        gEggHatchData->CB2_state++;
        PutWindowTilemap(gEggHatchData->windowId);
        CopyWindowToVram(gEggHatchData->windowId, 3);
        break;
    case 6:
        if (IsFanfareTaskInactive())
            gEggHatchData->CB2_state++;
        break;
    case 7:
        if (IsFanfareTaskInactive())
            gEggHatchData->CB2_state++;
        break;
    case 8:
        GetMonNick(&gPlayerParty[gEggHatchData->eggPartyID], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gOtherText_NickHatchPrompt);
        EggHatchPrintMessage(gEggHatchData->windowId, gStringVar4, 0, 2, 1);
        gEggHatchData->CB2_state++;
        break;
    case 9:
        if (!IsTextPrinterActive(gEggHatchData->windowId))
        {
            sub_809882C(gEggHatchData->windowId, 0x140, 0xE0);
            CreateYesNoMenu(gUnknown_0832C07C, 0x140, 0xE, 0);
            gEggHatchData->CB2_state++;
        }
        break;
    case 10:
        switch (sub_8198C58())
        {
        case 0:
            GetMonNick(&gPlayerParty[gEggHatchData->eggPartyID], gStringVar3);
            species = GetMonData(&gPlayerParty[gEggHatchData->eggPartyID], MON_DATA_SPECIES);
            gender = GetMonGender(&gPlayerParty[gEggHatchData->eggPartyID]);
            personality = GetMonData(&gPlayerParty[gEggHatchData->eggPartyID], MON_DATA_PERSONALITY, 0);
            DoNamingScreen(3, gStringVar3, species, gender, personality, EggHatchSetMonNickname);
            break;
        case 1:
        case -1:
            gEggHatchData->CB2_state++;
        }
        break;
    case 11:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        gEggHatchData->CB2_state++;
        break;
    case 12:
        if (!gPaletteFade.active)
        {
            sub_805F094();
            RemoveWindow(gEggHatchData->windowId);
            UnsetBgTilemapBuffer(0);
            UnsetBgTilemapBuffer(1);
            Free(gEggHatchData);
            SetMainCallback2(c2_exit_to_overworld_2_switch);
        }
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SpriteCB_Egg_0(struct Sprite* sprite)
{
    if (++sprite->data0 > 20)
    {
        sprite->callback = SpriteCB_Egg_1;
        sprite->data0 = 0;
    }
    else
    {
        sprite->data1 = (sprite->data1 + 20) & 0xFF;
        sprite->pos2.x = Sin(sprite->data1, 1);
        if (sprite->data0 == 15)
        {
            PlaySE(SE_BOWA);
            StartSpriteAnim(sprite, 1);
            CreateRandomEggShardSprite();
        }
    }
}

static void SpriteCB_Egg_1(struct Sprite* sprite)
{
    if (++sprite->data2 > 30)
    {
        if (++sprite->data0 > 20)
        {
            sprite->callback = SpriteCB_Egg_2;
            sprite->data0 = 0;
            sprite->data2 = 0;
        }
        else
        {
            sprite->data1 = (sprite->data1 + 20) & 0xFF;
            sprite->pos2.x = Sin(sprite->data1, 2);
            if (sprite->data0 == 15)
            {
                PlaySE(SE_BOWA);
                StartSpriteAnim(sprite, 2);
            }
        }
    }
}

static void SpriteCB_Egg_2(struct Sprite* sprite)
{
    if (++sprite->data2 > 30)
    {
        if (++sprite->data0 > 38)
        {
            u16 species;

            sprite->callback = SpriteCB_Egg_3;
            sprite->data0 = 0;
            species = GetMonData(&gPlayerParty[gEggHatchData->eggPartyID], MON_DATA_SPECIES);
            gSprites[gEggHatchData->pokeSpriteID].pos2.x = 0;
            gSprites[gEggHatchData->pokeSpriteID].pos2.y = 0;
        }
        else
        {
            sprite->data1 = (sprite->data1 + 20) & 0xFF;
            sprite->pos2.x = Sin(sprite->data1, 2);
            if (sprite->data0 == 15)
            {
                PlaySE(SE_BOWA);
                StartSpriteAnim(sprite, 2);
                CreateRandomEggShardSprite();
                CreateRandomEggShardSprite();
            }
            if (sprite->data0 == 30)
                PlaySE(SE_BOWA);
        }
    }
}

static void SpriteCB_Egg_3(struct Sprite* sprite)
{
    if (++sprite->data0 > 50)
    {
        sprite->callback = SpriteCB_Egg_4;
        sprite->data0 = 0;
    }
}

static void SpriteCB_Egg_4(struct Sprite* sprite)
{
    s16 i;
    if (sprite->data0 == 0)
        BeginNormalPaletteFade(-1, -1, 0, 0x10, 0xFFFF);
    if (sprite->data0 < 4u)
    {
        for (i = 0; i <= 3; i++)
            CreateRandomEggShardSprite();
    }
    sprite->data0++;
    if (!gPaletteFade.active)
    {
        PlaySE(SE_TAMAGO);
        sprite->invisible = 1;
        sprite->callback = SpriteCB_Egg_5;
        sprite->data0 = 0;
    }
}

static void SpriteCB_Egg_5(struct Sprite* sprite)
{
    if (sprite->data0 == 0)
    {
        gSprites[gEggHatchData->pokeSpriteID].invisible = 0;
        StartSpriteAffineAnim(&gSprites[gEggHatchData->pokeSpriteID], 1);
    }
    if (sprite->data0 == 8)
        BeginNormalPaletteFade(-1, -1, 0x10, 0, 0xFFFF);
    if (sprite->data0 <= 9)
        gSprites[gEggHatchData->pokeSpriteID].pos1.y -= 1;
    if (sprite->data0 > 40)
        sprite->callback = SpriteCallbackDummy;
    sprite->data0++;
}

static void SpriteCB_EggShard(struct Sprite* sprite)
{
    sprite->data4 += sprite->data1;
    sprite->data5 += sprite->data2;

    sprite->pos2.x = sprite->data4 / 256;
    sprite->pos2.y = sprite->data5 / 256;

    sprite->data2 += sprite->data3;

    if (sprite->pos1.y + sprite->pos2.y > sprite->pos1.y + 20 && sprite->data2 > 0)
        DestroySprite(sprite);
}

extern const s16 sEggShardVelocities[][2];

static void CreateRandomEggShardSprite(void)
{
    u16 spriteAnimIndex;

    s16 velocity1 = sEggShardVelocities[gEggHatchData->eggShardVelocityID][0];
    s16 velocity2 = sEggShardVelocities[gEggHatchData->eggShardVelocityID][1];
    gEggHatchData->eggShardVelocityID++;
    spriteAnimIndex = Random() % 4;
    CreateEggShardSprite(120, 60, velocity1, velocity2, 100, spriteAnimIndex);
}

extern const struct SpriteTemplate gUnknown_0832C04C;

static void CreateEggShardSprite(u8 x, u8 y, s16 data1, s16 data2, s16 data3, u8 spriteAnimIndex)
{
    u8 spriteID = CreateSprite(&gUnknown_0832C04C, x, y, 4);
    gSprites[spriteID].data1 = data1;
    gSprites[spriteID].data2 = data2;
    gSprites[spriteID].data3 = data3;
    StartSpriteAnim(&gSprites[spriteID], spriteAnimIndex);
}

static void EggHatchPrintMessage(u8 windowId, u8* string, u8 x, u8 y, u8 speed)
{
    FillWindowPixelBuffer(windowId, 0xFF);
    gEggHatchData->textColor.fgColor = 0;
    gEggHatchData->textColor.bgColor = 5;
    gEggHatchData->textColor.shadowColor = 6;
    AddTextPrinterParametrized2(windowId, 1, x, y, 0, 0, &gEggHatchData->textColor, speed, string);
}

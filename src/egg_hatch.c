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
    u8 field_5;
    u8 field_6;
    u8 eggShardVelocityID;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u16 species;
    u8 field_E;
    u8 field_F;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
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
extern void sub_81DB5E8(u8* str1, u8* str2, u8);
extern void sub_806A068(u16, u8);
extern void fade_screen(u8, u8);
extern void overworld_free_bg_tilemaps(void);
extern void sub_80AF168(void);
extern void init_uns_table_pokemon_copy(void);
extern void remove_some_task(void);
extern void reset_temp_tile_data_buffers(void);
extern void copy_decompressed_tile_data_to_vram_autofree(u8 bg_id, const void* src, u16 size, u16 offset, u8 mode);

 void Task_EggHatch(u8 taskID);
 void CB2_EggHatch_0(void);
 void CB2_EggHatch_1(void);
 void SpriteCB_Egg_0(struct Sprite* sprite);
 void SpriteCB_Egg_1(struct Sprite* sprite);
 void SpriteCB_Egg_2(struct Sprite* sprite);
 void SpriteCB_Egg_3(struct Sprite* sprite);
 void SpriteCB_Egg_4(struct Sprite* sprite);
 void SpriteCB_Egg_5(struct Sprite* sprite);
 void SpriteCB_EggShard(struct Sprite* sprite);
 void EggHatchPrintMessage2(u8* src);
 void EggHatchPrintMessage1(u8* src);
 bool8 EggHatchUpdateWindowText(void);
 void CreateRandomEggShardSprite(void);
 void CreateEggShardSprite(u8 x, u8 y, s16 data1, s16 data2, s16 data3, u8 spriteAnimIndex);

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

void AddHatchedMonToParty(u8 id)
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

u8 EggHatchCreateMonSprite(u8 a0, u8 switchID, u8 pokeID, u16* speciesLoc)
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

void VBlankCB_EggHatch(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void EggHatch(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_EggHatch, 10);
    fade_screen(1, 0);
}

 void Task_EggHatch(u8 taskID)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_EggHatch_0);
        gFieldCallback = sub_80AF168;
        DestroyTask(taskID);
    }
}

 void CB2_EggHatch_0(void)
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
        gEggHatchData->field_8 = 0;
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

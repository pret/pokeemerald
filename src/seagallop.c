#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/seagallop.h"
#include "constants/songs.h"

#define TILESTAG_FERRY 3000
#define TILESTAG_WAKE  4000

#define PALTAG_FERRY_WAKE 3000

static EWRAM_DATA void *sBg3TilemapBuffer = NULL;

static void CB2_SetUpSeagallopScene(void);
static void VBlankCB_SeaGallop(void);
static void MainCB2_SeaGallop(void);
static void Task_Seagallop_0(u8 taskId);
static void Task_Seagallop_1(u8 taskId);
static void Task_Seagallop_2(u8 taskId);
static void Task_Seagallop_3(void);
static void ResetGPU(void);
static void ResetAllAssets(void);
static void SetDispcnt(void);
static void ResetBGPos(void);
static void LoadFerrySpriteResources(void);
static void FreeFerrySpriteResources(void);
static void CreateFerrySprite(void);
static void SpriteCB_Ferry(struct Sprite *sprite);
static void CreateWakeSprite(s16 x);
static void SpriteCB_Wake(struct Sprite *sprite);
static bool8 GetDirectionOfTravel(void);

static const u16 sWaterTiles[] = INCGFX_U16("graphics/seagallop/water.png", ".4bpp");
static const u16 sWaterPal[] = INCGFX_U16("graphics/seagallop/water.png", ".gbapal");
static const u16 sWaterTilemap_WB[] = INCBIN_U16("graphics/seagallop/wb_tilemap.bin");
static const u16 sWaterTilemap_EB[] = INCBIN_U16("graphics/seagallop/eb_tilemap.bin");
static const u16 sFerrySpriteTiles[] = INCGFX_U16("graphics/seagallop/ferry_sprite.png", ".4bpp");
static const u16 sFerryAndWakePal[] = INCGFX_U16("graphics/seagallop/ferry_and_wake.pal", ".gbapal");
static const u16 sWakeSpriteTiles[] = INCGFX_U16("graphics/seagallop/wake.png", ".4bpp");

static const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const s8 sSeag[][4] = {
    [SEAGALLOP_VERMILION_CITY]  = {MAP_GROUP(MAP_VERMILION_CITY), MAP_NUM(MAP_VERMILION_CITY),      0x17, 0x20},
    [SEAGALLOP_ONE_ISLAND]      = {MAP_GROUP(MAP_ONE_ISLAND_HARBOR), MAP_NUM(MAP_ONE_ISLAND_HARBOR),   0x08, 0x05},
    [SEAGALLOP_TWO_ISLAND]      = {MAP_GROUP(MAP_TWO_ISLAND_HARBOR), MAP_NUM(MAP_TWO_ISLAND_HARBOR),   0x08, 0x05},
    [SEAGALLOP_THREE_ISLAND]    = {MAP_GROUP(MAP_THREE_ISLAND_HARBOR), MAP_NUM(MAP_THREE_ISLAND_HARBOR), 0x08, 0x05},
    [SEAGALLOP_FOUR_ISLAND]     = {MAP_GROUP(MAP_FOUR_ISLAND_HARBOR), MAP_NUM(MAP_FOUR_ISLAND_HARBOR),  0x08, 0x05},
    [SEAGALLOP_FIVE_ISLAND]     = {MAP_GROUP(MAP_FIVE_ISLAND_HARBOR), MAP_NUM(MAP_FIVE_ISLAND_HARBOR),  0x08, 0x05},
    [SEAGALLOP_SIX_ISLAND]      = {MAP_GROUP(MAP_SIX_ISLAND_HARBOR), MAP_NUM(MAP_SIX_ISLAND_HARBOR),   0x08, 0x05},
    [SEAGALLOP_SEVEN_ISLAND]    = {MAP_GROUP(MAP_SEVEN_ISLAND_HARBOR), MAP_NUM(MAP_SEVEN_ISLAND_HARBOR), 0x08, 0x05},
    [SEAGALLOP_CINNABAR_ISLAND] = {MAP_GROUP(MAP_CINNABAR_ISLAND), MAP_NUM(MAP_CINNABAR_ISLAND),     0x15, 0x07},
    [SEAGALLOP_NAVEL_ROCK]      = {MAP_GROUP(MAP_NAVEL_ROCK_HARBOR_FRLG), MAP_NUM(MAP_NAVEL_ROCK_HARBOR_FRLG),   0x08, 0x05},
    [SEAGALLOP_BIRTH_ISLAND]    = {MAP_GROUP(MAP_BIRTH_ISLAND_HARBOR_FRLG), MAP_NUM(MAP_BIRTH_ISLAND_HARBOR_FRLG), 0x08, 0x05}
};

// Bitpacked array.  In the commented section, right-most bit is the
// flag for traveling from (row port) to Vermilion City, and so on.
// Flags follow these enums:

enum TravelDirections
{
    DIRN_WESTBOUND = 0,
    DIRN_EASTBOUND = 1
};

static const u16 sTravelDirectionMatrix[] = {
    [SEAGALLOP_VERMILION_CITY]  = 0x6fe, // 11011111110
    [SEAGALLOP_ONE_ISLAND]      = 0x6fc, // 11011111100
    [SEAGALLOP_TWO_ISLAND]      = 0x6f8, // 11011111000
    [SEAGALLOP_THREE_ISLAND]    = 0x6f0, // 11011110000
    [SEAGALLOP_FOUR_ISLAND]     = 0x6e0, // 11011100000
    [SEAGALLOP_FIVE_ISLAND]     = 0x4c0, // 10011000000
    [SEAGALLOP_SIX_ISLAND]      = 0x400, // 10000000000
    [SEAGALLOP_SEVEN_ISLAND]    = 0x440, // 10001000000
    [SEAGALLOP_CINNABAR_ISLAND] = 0x7ff, // 11111111111
    [SEAGALLOP_NAVEL_ROCK]      = 0x6e0, // 11011100000
    [SEAGALLOP_BIRTH_ISLAND]    = 0x000  // 00000000000
};

static const union AnimCmd sSpriteAnims_Ferry_WB[] = {
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnims_Ferry_EB[] = {
    ANIMCMD_FRAME(0, 10, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Ferry[] = {
    sSpriteAnims_Ferry_WB,
    sSpriteAnims_Ferry_EB
};

static const struct OamData sOamData_Ferry = {
    .size = 3
};

static const struct SpriteTemplate sFerrySpriteTemplate = {
    TILESTAG_FERRY,
    PALTAG_FERRY_WAKE,
    &sOamData_Ferry,
    sSpriteAnimTable_Ferry,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCB_Ferry
};

static const struct SpriteSheet sFerryAndWakeSpriteSheets[] = {
    {(const void *)sWakeSpriteTiles,  sizeof(sWakeSpriteTiles),  TILESTAG_WAKE},
    {(const void *)sFerrySpriteTiles, sizeof(sFerrySpriteTiles), TILESTAG_FERRY},
    {}
};

static const struct SpritePalette sFerryAndWakeSpritePalettes[] = {
    {sFerryAndWakePal, PALTAG_FERRY_WAKE},
    {}
};

static const union AnimCmd sSpriteAnims_Wake_WB[] = {
    ANIMCMD_FRAME(0x00, 0x14),
    ANIMCMD_FRAME(0x10, 0x14),
    ANIMCMD_FRAME(0x20, 0x0f),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnims_Wake_EB[] = {
    ANIMCMD_FRAME(0x00, 0x14, .hFlip = TRUE),
    ANIMCMD_FRAME(0x10, 0x14, .hFlip = TRUE),
    ANIMCMD_FRAME(0x20, 0x0f, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_Wake[] = {
    sSpriteAnims_Wake_WB,
    sSpriteAnims_Wake_EB
};

static const struct OamData sOamData_Wake = {
    .size = 2
};

static const struct SpriteTemplate sWakeSpriteTemplate = {
    TILESTAG_WAKE,
    PALTAG_FERRY_WAKE,
    &sOamData_Wake,
    sSpriteAnimTable_Wake,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCB_Wake
};

void DoSeagallopFerryScene(void)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_SetUpSeagallopScene);
}

static void CB2_SetUpSeagallopScene(void)
{
    void ** ptr;
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL); // redundant since the setup routine already did this
        ResetGPU();
        gMain.state++;
        break;
    case 1:
        ResetAllAssets();
        gMain.state++;
        break;
    case 2:
        ptr = &sBg3TilemapBuffer;
        *ptr = AllocZeroed(0x800);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBGTemplates, NELEMS(sBGTemplates));
        SetBgTilemapBuffer(3, *ptr);
        ResetBGPos();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(3, sWaterTiles, sizeof(sWaterTiles), 0);
        if (GetDirectionOfTravel() == DIRN_EASTBOUND)
            CopyToBgTilemapBufferRect(3, sWaterTilemap_EB, 0, 0, 32, 32);
        else
            CopyToBgTilemapBufferRect(3, sWaterTilemap_WB, 0, 0, 32, 32);
        LoadPalette(sWaterPal, BG_PLTT_ID(4), sizeof(sWaterPal));
        LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy() != DIRN_EASTBOUND)
        {
            ShowBg(0);
            ShowBg(3);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
        }
        break;
    case 5:
        LoadFerrySpriteResources();
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetDispcnt();
        SetVBlankCallback(VBlankCB_SeaGallop);
        PlaySE(SE_SHIP);
        CreateFerrySprite();
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0x00);
        SetGpuReg(REG_OFFSET_WIN0H, 0x00F0);
        SetGpuReg(REG_OFFSET_WIN0V, 0x1888);
        CreateTask(Task_Seagallop_0, 8);
        SetMainCallback2(MainCB2_SeaGallop);
        gMain.state = 0;
        break;
    }
}

static void VBlankCB_SeaGallop(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_SeaGallop(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_Seagallop_0(u8 taskId)
{
    gTasks[taskId].func = Task_Seagallop_1;
}

static void ScrollBG(void)
{
    if (GetDirectionOfTravel() == DIRN_EASTBOUND)
    {
        ChangeBgX(3, 0x600, 1);
    }
    else
    {
        ChangeBgX(3, 0x600, 2);
    }
}

static void Task_Seagallop_1(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    ScrollBG();
    if (++task->data[1] == 140)
    {
        Overworld_FadeOutMapMusic();
        WarpFadeOutScreen();
        task->func = Task_Seagallop_2;
    }
}

static void Task_Seagallop_2(u8 taskId)
{
    ScrollBG();
    if (BGMusicStopped() && !gPaletteFade.active)
    {
        Task_Seagallop_3();
        DestroyTask(taskId);
    }
}

static void Task_Seagallop_3(void)
{
    const s8 * warpInfo;

    if (gSpecialVar_0x8006 >= NELEMS(sSeag))
        gSpecialVar_0x8006 = 0;

    warpInfo = sSeag[gSpecialVar_0x8006];
    SetWarpDestination(warpInfo[0], warpInfo[1], -1, warpInfo[2], warpInfo[3]);
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    gFieldCallback = FieldCB_DefaultWarpExit;
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    ResetInitialPlayerAvatarState();
    FreeFerrySpriteResources();
    Free(sBg3TilemapBuffer);
    FreeAllWindowBuffers();
}

static void ResetGPU(void)
{
    void *dest = (void *) VRAM;
    DmaClearLarge16(3, dest, VRAM_SIZE, 0x1000);

    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void ResetAllAssets(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetAllPicSprites();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void SetDispcnt(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
}

static void ResetBGPos(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static void LoadFerrySpriteResources(void)
{
    LoadSpriteSheets(sFerryAndWakeSpriteSheets);
    LoadSpritePalettes(sFerryAndWakeSpritePalettes);
}

static void FreeFerrySpriteResources(void)
{
    FreeSpriteTilesByTag(TILESTAG_FERRY);
    FreeSpriteTilesByTag(TILESTAG_WAKE);
    FreeSpritePaletteByTag(PALTAG_FERRY_WAKE);
}

static void CreateFerrySprite(void)
{
    u8 spriteId = CreateSprite(&sFerrySpriteTemplate, 0, 92, 0);
    gSprites[spriteId].data[0] = 48;
    if (GetDirectionOfTravel() == DIRN_EASTBOUND)
    {
        StartSpriteAnim(&gSprites[spriteId], 1);
    }
    else
    {
        gSprites[spriteId].x = 240;
        gSprites[spriteId].data[0] *= -1;
    }
}

static void SpriteCB_Ferry(struct Sprite *sprite)
{
    sprite->data[1] += sprite->data[0];
    sprite->x2 = sprite->data[1] >> 4;
    if (sprite->data[2] % 5 == 0)
    {
        CreateWakeSprite(sprite->x + sprite->x2);
    }
    sprite->data[2]++;
    if ((u16)(300 + sprite->x2) > 600)
    {
        DestroySprite(sprite);
    }
}

static void CreateWakeSprite(s16 x)
{
    u8 spriteId = CreateSpriteUnchecked(&sWakeSpriteTemplate, x, 92, 8);
    if (spriteId != MAX_SPRITES)
    {
        if (GetDirectionOfTravel() == DIRN_EASTBOUND)
        {
            StartSpriteAnim(&gSprites[spriteId], 1);
        }
    }
}

static void SpriteCB_Wake(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        DestroySprite(sprite);
    }
}

static bool8 GetDirectionOfTravel(void)
{
    if (gSpecialVar_0x8004 >= NELEMS(sTravelDirectionMatrix))
    {
        return DIRN_EASTBOUND;
    }
    return (sTravelDirectionMatrix[gSpecialVar_0x8004] >> gSpecialVar_0x8006) & 1;
}

// For "All aboard SEAGALLOP HI-SPEED ##" text
u8 GetSeagallopNumber(void)
{
    u16 originId, destId;

    originId = gSpecialVar_0x8004;
    destId = gSpecialVar_0x8006;

    if (originId == SEAGALLOP_CINNABAR_ISLAND || destId == SEAGALLOP_CINNABAR_ISLAND)
        return 1;

    if (originId == SEAGALLOP_VERMILION_CITY || destId == SEAGALLOP_VERMILION_CITY)
        return 7;

    if (originId == SEAGALLOP_NAVEL_ROCK || destId == SEAGALLOP_NAVEL_ROCK)
        return 10;

    if (originId == SEAGALLOP_BIRTH_ISLAND || destId == SEAGALLOP_BIRTH_ISLAND)
        return 12;

    if ((originId == SEAGALLOP_ONE_ISLAND 
      || originId == SEAGALLOP_TWO_ISLAND 
      || originId == SEAGALLOP_THREE_ISLAND) 
      && (destId == SEAGALLOP_ONE_ISLAND 
       || destId == SEAGALLOP_TWO_ISLAND 
       || destId == SEAGALLOP_THREE_ISLAND))
        return 2;

    if ((originId == SEAGALLOP_FOUR_ISLAND 
      || originId == SEAGALLOP_FIVE_ISLAND) 
      && (destId == SEAGALLOP_FOUR_ISLAND 
       || destId == SEAGALLOP_FIVE_ISLAND))
        return 3;

    if ((originId == SEAGALLOP_SIX_ISLAND 
      || originId == SEAGALLOP_SEVEN_ISLAND) 
      && (destId == SEAGALLOP_SIX_ISLAND 
       || destId == SEAGALLOP_SEVEN_ISLAND))
        return 5;

    return 6;
}

bool8 IsPlayerLeftOfVermilionSailor(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_VERMILION_CITY) 
       && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_VERMILION_CITY) 
       && gSaveBlock1Ptr->pos.x < 24)
        return TRUE;

    return FALSE;
}

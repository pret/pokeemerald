#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "landmark.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokenav.h"
#include "region_map.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/region_map_sections.h"

#define NUM_CITY_MAPS 22

struct Pokenav5Struct
{
    u8 filler0[0xC];
    bool32 zoomDisabled;
    u32 (*callback)(struct Pokenav5Struct *);
};

struct Pokenav5Struct_2
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopTaskId;
    u16 infoWindowId;
    struct Sprite *cityZoomTextSprites[3];
    u8 tilemapBuffer[0x800];
    u8 cityZoomPics[NUM_CITY_MAPS][200];
};

struct CityMapEntry
{
    u16 mapSecId;
    u16 index;
    const u32 *tilemap;
};

static u32 HandleRegionMapInput(struct Pokenav5Struct *);
static u32 HandleRegionMapInputZoomDisabled(struct Pokenav5Struct *);
static u32 GetExitRegionMapMenuId(struct Pokenav5Struct *);
static u32 LoopedTask_OpenRegionMap(s32);
static u32 LoopedTask_DecompressCityMaps(s32);
static bool32 GetCurrentLoopedTaskActive(void);
static void FreeCityZoomViewGfx(void);
static void LoadCityZoomViewGfx(void);
static void DecompressCityMaps(void);
static bool32 IsDecompressCityMapsActive(void);
static void LoadPokenavRegionMapGfx(struct Pokenav5Struct_2 *);
static bool32 TryFreeTempTileDataBuffers(void);
static void UpdateMapSecInfoWindow(struct Pokenav5Struct_2 *);
static bool32 IsDma3ManagerBusyWithBgCopy_(struct Pokenav5Struct_2 *);
static void ChangeBgYForZoom(bool32);
static bool32 IsChangeBgYForZoomActive(void);
static void CreateCityZoomTextSprites(void);
static void DrawCityMap(struct Pokenav5Struct_2 *, int, int);
static void PrintLandmarkNames(struct Pokenav5Struct_2 *, int, int);
static void SetCityZoomTextInvisibility(bool32);
static void Task_ChangeBgYForZoom(u8 taskId);
static void UpdateCityZoomTextPosition(void);
static void SpriteCB_CityZoomText(struct Sprite *sprite);
static u32 LoopedTask_UpdateInfoAfterCursorMove(s32);
static u32 LoopedTask_RegionMapZoomOut(s32);
static u32 LoopedTask_RegionMapZoomIn(s32);
static u32 LoopedTask_ExitRegionMap(s32);

extern const u16 gRegionMapCityZoomTiles_Pal[];
extern const u32 gRegionMapCityZoomText_Gfx[];

static const u16 sMapSecInfoWindow_Pal[] = INCBIN_U16("graphics/pokenav/region_map_info_window.gbapal");
static const u32 sRegionMapCityZoomTiles_Gfx[] = INCBIN_U32("graphics/pokenav/zoom_tiles.4bpp.lz");

#include "data/region_map/city_map_tilemaps.h"

static const struct BgTemplate sRegionMapBgTemplates[3] = 
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x00,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const LoopedTask sRegionMapLoopTaskFuncs[] = 
{
    [POKENAV_MAP_FUNC_NONE]         = NULL,
    [POKENAV_MAP_FUNC_CURSOR_MOVED] = LoopedTask_UpdateInfoAfterCursorMove,
    [POKENAV_MAP_FUNC_ZOOM_OUT]     = LoopedTask_RegionMapZoomOut,
    [POKENAV_MAP_FUNC_ZOOM_IN]      = LoopedTask_RegionMapZoomIn,
    [POKENAV_MAP_FUNC_EXIT]         = LoopedTask_ExitRegionMap
};

static const struct CompressedSpriteSheet sCityZoomTextSpriteSheet[1] = 
{
    {gRegionMapCityZoomText_Gfx, 0x800, 6}
};

static const struct SpritePalette sCityZoomTilesSpritePalette[] = 
{
    {gRegionMapCityZoomTiles_Pal, 11},
    {}
};

static const struct WindowTemplate sMapSecInfoWindowTemplate = 
{
    .bg = 1,
    .tilemapLeft = 17,
    .tilemapTop = 4,
    .width = 12,
    .height = 13,
    .paletteNum = 1,
    .baseBlock = 0x4C
};

#include "data/region_map/city_map_entries.h"

const struct OamData sCityZoomTextSprite_OamData = 
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sCityZoomTextSpriteTemplate =
{
    .tileTag = 6,
    .paletteTag = 11,
    .oam = &sCityZoomTextSprite_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CityZoomText,
};

u32 PokenavCallback_Init_RegionMap(void)
{
    struct Pokenav5Struct *state = AllocSubstruct(3, sizeof(struct Pokenav5Struct));
    if (!state)
        return FALSE;

    if (!AllocSubstruct(16, sizeof(struct RegionMap)))
        return FALSE;

    state->zoomDisabled = IsEventIslandMapSecId(gMapHeader.regionMapSectionId);
    if (!state->zoomDisabled)
        state->callback = HandleRegionMapInput;
    else
        state->callback = HandleRegionMapInputZoomDisabled;

    return TRUE;
}

void FreeRegionMapSubstruct1(void)
{
    gSaveBlock2Ptr->regionMapZoom = IsRegionMapZoomed();
    FreePokenavSubstruct(16);
    FreePokenavSubstruct(3);
}

u32 GetRegionMapCallback(void)
{
    struct Pokenav5Struct *state = GetSubstructPtr(3);
    return state->callback(state);
}

static u32 HandleRegionMapInput(struct Pokenav5Struct *state)
{
    switch (DoRegionMapInputCallback())
    {
    case MAP_INPUT_MOVE_END:
        return POKENAV_MAP_FUNC_CURSOR_MOVED;
    case MAP_INPUT_A_BUTTON:
        if (!IsRegionMapZoomed())
            return POKENAV_MAP_FUNC_ZOOM_IN;
        return POKENAV_MAP_FUNC_ZOOM_OUT;
    case MAP_INPUT_B_BUTTON:
        state->callback = GetExitRegionMapMenuId;
        return POKENAV_MAP_FUNC_EXIT;
    }

    return POKENAV_MAP_FUNC_NONE;
}

static u32 HandleRegionMapInputZoomDisabled(struct Pokenav5Struct *state)
{
    if (gMain.newKeys & B_BUTTON)
    {
        state->callback = GetExitRegionMapMenuId;
        return POKENAV_MAP_FUNC_EXIT;
    }

    return POKENAV_MAP_FUNC_NONE;
}

static u32 GetExitRegionMapMenuId(struct Pokenav5Struct *state)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MAP;
}

bool32 GetZoomDisabled(void)
{
    struct Pokenav5Struct *state = GetSubstructPtr(3);
    return state->zoomDisabled;
}

bool32 OpenPokenavRegionMap(void)
{
    struct Pokenav5Struct_2 *state = AllocSubstruct(4, sizeof(struct Pokenav5Struct_2));
    if (!state)
        return FALSE;

    state->loopTaskId = CreateLoopedTask(LoopedTask_OpenRegionMap, 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
    return TRUE;
}

void CreateRegionMapLoopedTask(s32 index)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    state->loopTaskId = CreateLoopedTask(sRegionMapLoopTaskFuncs[index], 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsRegionMapLoopedTaskActive(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    return state->isTaskActiveCB();
}

void FreeRegionMapSubstruct2(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    FreeRegionMapIconResources();
    FreeCityZoomViewGfx();
    RemoveWindow(state->infoWindowId);
    FreePokenavSubstruct(16);
    FreePokenavSubstruct(4);
    SetPokenavVBlankCallback();
    SetBgMode(0);
}

static void VBlankCB_RegionMap(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    UpdateRegionMapVideoRegs();
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    return IsLoopedTaskActive(state->loopTaskId);
}

static bool8 ShouldOpenRegionMapZoomed(void)
{
    if (GetZoomDisabled())
        return FALSE;

    return gSaveBlock2Ptr->regionMapZoom == TRUE;
}

static u32 LoopedTask_OpenRegionMap(s32 taskState)
{
    int menuGfxId;
    struct RegionMap *regionMap;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    switch (taskState)
    {
    case 0:
        SetVBlankCallback_(NULL);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        SetBgMode(1);
        InitBgTemplates(sRegionMapBgTemplates, ARRAY_COUNT(sRegionMapBgTemplates) - 1);
        regionMap = GetSubstructPtr(16);
        InitRegionMapData(regionMap, &sRegionMapBgTemplates[1], ShouldOpenRegionMapZoomed());
        LoadCityZoomViewGfx();
        return LT_INC_AND_PAUSE;
    case 1:
        if (LoadRegionMapGfx())
            return LT_PAUSE;

        if (!GetZoomDisabled())
        {
            CreateRegionMapPlayerIcon(4, 9);
            CreateRegionMapCursor(5, 10);
            TrySetPlayerIconBlink();
        }
        else
        {
            sub_8123030(RGB_BLACK, 6);
        }
        return LT_INC_AND_PAUSE;
    case 2:
        DecompressCityMaps();
        return LT_INC_AND_CONTINUE;
    case 3:
        if (IsDecompressCityMapsActive())
            return LT_PAUSE;

        LoadPokenavRegionMapGfx(state);
        return LT_INC_AND_CONTINUE;
    case 4:
        if (TryFreeTempTileDataBuffers())
            return LT_PAUSE;

        UpdateMapSecInfoWindow(state);
        sub_81C7B40();
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;

        ShowBg(1);
        ShowBg(2);
        SetVBlankCallback_(VBlankCB_RegionMap);
        return LT_INC_AND_PAUSE;
    case 6:
        if (!ShouldOpenRegionMapZoomed())
            menuGfxId = POKENAV_GFX_MAP_MENU_ZOOMED_OUT;
        else
            menuGfxId = POKENAV_GFX_MAP_MENU_ZOOMED_IN;

        LoadLeftHeaderGfxForIndex(menuGfxId);
        sub_81C7FA0(menuGfxId, 1, 1);
        PokenavFadeScreen(1);
        return LT_INC_AND_PAUSE;
    case 7:
        if (IsPaletteFadeActive() || sub_81C8010())
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    default:
        return LT_FINISH;
    }
}

static u32 LoopedTask_UpdateInfoAfterCursorMove(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    switch (taskState)
    {
    case 0:
        UpdateMapSecInfoWindow(state);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_RegionMapZoomOut(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        ChangeBgYForZoom(FALSE);
        SetRegionMapDataForZoom();
        return LT_INC_AND_PAUSE;
    case 1:
        if (UpdateRegionMapZoom() || IsChangeBgYForZoomActive())
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MAP_ZOOMED_OUT);
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForHelpBar())
            return LT_PAUSE;

        sub_81C7E14(POKENAV_GFX_MAP_MENU_ZOOMED_OUT);
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_RegionMapZoomIn(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        UpdateMapSecInfoWindow(state);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;

        ChangeBgYForZoom(TRUE);
        SetRegionMapDataForZoom();
        return LT_INC_AND_PAUSE;
    case 2:
        if (UpdateRegionMapZoom() || IsChangeBgYForZoomActive())
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MAP_ZOOMED_IN);
        return LT_INC_AND_PAUSE;
    case 3:
        if (WaitForHelpBar())
            return LT_PAUSE;

        sub_81C7E14(POKENAV_GFX_MAP_MENU_ZOOMED_IN);
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_ExitRegionMap(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;

        sub_81C7FDC();
        sub_81C78A0();
        return LT_INC_AND_PAUSE;
    case 2:
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;

        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_PAUSE;
    }

    return LT_FINISH;
}

static void LoadCityZoomViewGfx(void)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sCityZoomTextSpriteSheet); i++)
        LoadCompressedSpriteSheet(&sCityZoomTextSpriteSheet[i]);

    Pokenav_AllocAndLoadPalettes(sCityZoomTilesSpritePalette);
    CreateCityZoomTextSprites();
}

static void FreeCityZoomViewGfx(void)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    FreeSpriteTilesByTag(6);
    FreeSpritePaletteByTag(11);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        DestroySprite(state->cityZoomTextSprites[i]);
}

static void LoadPokenavRegionMapGfx(struct Pokenav5Struct_2 *state)
{
    sub_8199DF0(1, PIXEL_FILL(0), 0x40, 1);
    sub_8199DF0(1, PIXEL_FILL(1), 0x41, 1);
    CpuFill16(0x1040, state->tilemapBuffer, 0x800);
    SetBgTilemapBuffer(1, state->tilemapBuffer);
    state->infoWindowId = AddWindow(&sMapSecInfoWindowTemplate);
    LoadUserWindowBorderGfx_(state->infoWindowId, 0x42, 0x40);
    DrawTextBorderOuter(state->infoWindowId, 0x42, 4);
    decompress_and_copy_tile_data_to_vram(1, sRegionMapCityZoomTiles_Gfx, 0, 0, 0);
    FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->infoWindowId);
    CopyWindowToVram(state->infoWindowId, 3);
    CopyPaletteIntoBufferUnfaded(sMapSecInfoWindow_Pal, 0x10, 0x20);
    CopyPaletteIntoBufferUnfaded(gRegionMapCityZoomTiles_Pal, 0x30, 0x20);
    if (!IsRegionMapZoomed())
        ChangeBgY(1, -0x6000, 0);
    else
        ChangeBgY(1, 0, 0);

    ChangeBgX(1, 0, 0);
}

static bool32 TryFreeTempTileDataBuffers(void)
{
    return free_temp_tile_data_buffers_if_possible();
}

static void UpdateMapSecInfoWindow(struct Pokenav5Struct_2 *state)
{
    struct RegionMap *regionMap = GetSubstructPtr(16);
    switch (regionMap->mapSecType)
    {
    case MAPSECTYPE_CITY_CANFLY:
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowRectTilemap(state->infoWindowId, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->infoWindowId, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        DrawCityMap(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->infoWindowId, 3);
        SetCityZoomTextInvisibility(FALSE);
        break;
    case MAPSECTYPE_CITY_CANTFLY:
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowRectTilemap(state->infoWindowId, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->infoWindowId, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        FillBgTilemapBufferRect(1, 0x1041, 17, 6, 12, 11, 17);
        CopyWindowToVram(state->infoWindowId, 3);
        SetCityZoomTextInvisibility(TRUE);
        break;
    case MAPSECTYPE_ROUTE:
    case MAPSECTYPE_BATTLE_FRONTIER:
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowTilemap(state->infoWindowId);
        AddTextPrinterParameterized(state->infoWindowId, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        PrintLandmarkNames(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->infoWindowId, 3);
        SetCityZoomTextInvisibility(TRUE);
        break;
    case MAPSECTYPE_NONE:
        FillBgTilemapBufferRect(1, 0x1041, 17, 4, 12, 13, 17);
        CopyBgTilemapBufferToVram(1);
        SetCityZoomTextInvisibility(TRUE);
        break;
    }
}

static bool32 IsDma3ManagerBusyWithBgCopy_(struct Pokenav5Struct_2 *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

#define tZoomIn data[0]

static void ChangeBgYForZoom(bool32 zoomIn)
{
    u8 taskId = CreateTask(Task_ChangeBgYForZoom, 3);
    gTasks[taskId].tZoomIn = zoomIn;
}

static bool32 IsChangeBgYForZoomActive(void)
{
    return FuncIsActiveTask(Task_ChangeBgYForZoom);
}

static void Task_ChangeBgYForZoom(u8 taskId)
{
    if (gTasks[taskId].tZoomIn)
    {
        if (ChangeBgY(1, 0x480, 1) >= 0)
        {
            ChangeBgY(1, 0, 0);
            DestroyTask(taskId);
        }
        
        UpdateCityZoomTextPosition();
    }
    else
    {
        if (ChangeBgY(1, 0x480, 2) <= -0x6000)
        {
            ChangeBgY(1, -0x6000, 0);
            DestroyTask(taskId);
        }

        UpdateCityZoomTextPosition();
    }
}

#undef tZoomIn

static void DecompressCityMaps(void)
{
    CreateLoopedTask(LoopedTask_DecompressCityMaps, 1);
}

static bool32 IsDecompressCityMapsActive(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_DecompressCityMaps);
}

static u32 LoopedTask_DecompressCityMaps(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    if (taskState < NUM_CITY_MAPS)
    {
        LZ77UnCompWram(sPokenavCityMaps[taskState].tilemap, state->cityZoomPics[taskState]);
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static void DrawCityMap(struct Pokenav5Struct_2 *state, int mapSecId, int pos)
{
    int i;
    for (i = 0; i < NUM_CITY_MAPS && (sPokenavCityMaps[i].mapSecId != mapSecId || sPokenavCityMaps[i].index != pos); i++)
        ;

    if (i == NUM_CITY_MAPS)
        return;

    FillBgTilemapBufferRect_Palette0(1, 0x1041, 17, 6, 12, 11);
    CopyToBgTilemapBufferRect(1, state->cityZoomPics[i], 18, 6, 10, 10);
}

static void PrintLandmarkNames(struct Pokenav5Struct_2 *state, int mapSecId, int pos)
{
    int i = 0;
    while (1)
    {
        const u8 *landmarkName = GetLandmarkName(mapSecId, pos, i);
        if (!landmarkName)
            break;

        StringCopyPadded(gStringVar1, landmarkName, CHAR_SPACE, 12);
        AddTextPrinterParameterized(state->infoWindowId, 7, gStringVar1, 0, i * 16 + 17, TEXT_SPEED_FF, NULL);
        i++;
    }
}

static void CreateCityZoomTextSprites(void)
{
    int i;
    int y;
    struct Sprite *sprite;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);

    // When not zoomed in the text is still created but its pushed off screen
    if (!IsRegionMapZoomed())
        y = 228;
    else
        y = 132;

    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
    {
        u8 spriteId = CreateSprite(&sCityZoomTextSpriteTemplate, 152 + i * 32, y, 8);
        sprite = &gSprites[spriteId];
        sprite->data[0] = 0;
        sprite->data[1] = i * 4;
        sprite->data[2] = sprite->oam.tileNum;
        sprite->data[3] = 150;
        sprite->data[4] = i * 4;
        sprite->oam.tileNum += i * 4;
        state->cityZoomTextSprites[i] = sprite;
    }
}

// Slide and cycle through the text key showing what the features on the zoomed city map are
static void SpriteCB_CityZoomText(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->data[3]--;
        return;
    }

    if (++sprite->data[0] > 11)
        sprite->data[0] = 0;

    if (++sprite->data[1] > 60)
        sprite->data[1] = 0;

    sprite->oam.tileNum = sprite->data[2] + sprite->data[1];
    if (sprite->data[5] < 4)
    {
        if (sprite->data[0] == 0)
        {
            sprite->data[5]++;
            sprite->data[3] = 120;
        }
    }
    else
    {
        if (sprite->data[1] == sprite->data[4])
        {
            sprite->data[5] = 0;
            sprite->data[0] = 0;
            sprite->data[3] = 120;
        }
    }
}

static void UpdateCityZoomTextPosition(void)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    int y = 132 - (GetBgY(1) >> 8);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        state->cityZoomTextSprites[i]->pos1.y = y;
}

static void SetCityZoomTextInvisibility(bool32 invisible)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        state->cityZoomTextSprites[i]->invisible = invisible;
}

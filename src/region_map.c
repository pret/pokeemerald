#include "global.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "party_menu.h"
#include "trig.h"
#include "constants/maps.h"
#include "overworld.h"
#include "event_data.h"
#include "secret_base.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "text_window.h"
#include "constants/songs.h"
#include "m4a.h"
#include "field_effect.h"
#include "field_specials.h"
#include "fldeff.h"
#include "region_map.h"
#include "constants/region_map_sections.h"
#include "heal_location.h"
#include "constants/field_specials.h"
#include "constants/heal_locations.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/weather.h"

/*
 *  This file handles region maps generally, and the map used when selecting a fly destination.
 *  Specific features of other region map uses are handled elsewhere
 *
 *  For the region map in the pokenav, see pokenav_region_map.c
 *  For the region map in the pokedex, see pokdex_area_screen.c/pokedex_area_region_map.c
 *  For the region map that can be viewed on the wall of pokemon centers, see field_region_map.c
 *
 */

#define MAP_WIDTH 28
#define MAP_HEIGHT 15
#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)

#define FLYDESTICON_RED_OUTLINE 6

// Static type declarations

struct MultiNameFlyDest
{
    const u8 *const *name;
    u16 mapSecId;
    u16 flag;
};

// Static RAM declarations

static EWRAM_DATA struct RegionMap *gRegionMap = NULL;

static EWRAM_DATA struct {
    void (*callback)(void);
    u16 state;
    u16 mapSecId;
    struct RegionMap regionMap;
    u8 tileBuffer[0x1c0];
    u8 nameBuffer[0x26]; // never read
    bool8 choseFlyLocation;
} *sFlyMap = NULL;

static bool32 gUnknown_03001180;

// Static ROM declarations

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
static u16 GetMapSecIdAt(u16 x, u16 y);
static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y);
static void InitMapBasedOnPlayerLocation(void);
static void RegionMap_InitializeStateBasedOnSSTidalLocation(void);
static u8 GetMapsecType(u16 mapSecId);
static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId);
static u16 GetTerraOrMarineCaveMapSecId(void);
static void GetMarineCaveCoords(u16 *x, u16 *y);
static bool32 IsPlayerInAquaHideout(u8 mapSecId);
static void GetPositionOfCursorWithinMapSec(void);
static bool8 RegionMap_IsMapSecIdInNextRow(u16 y);
static void SpriteCB_CursorMapFull(struct Sprite *sprite);
static void FreeRegionMapCursorSprite(void);
static void HideRegionMapPlayerIcon(void);
static void UnhideRegionMapPlayerIcon(void);
static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite);
static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite);
static void SpriteCB_PlayerIcon(struct Sprite *sprite);
static void VBlankCB_FlyMap(void);
static void CB2_FlyMap(void);
static void SetFlyMapCallback(void callback(void));
static void DrawFlyDestTextWindow(void);
static void LoadFlyDestIcons(void);
static void CreateFlyDestIcons(void);
static void TryCreateRedOutlineFlyDestIcons(void);
static void SpriteCB_FlyDestIcon(struct Sprite *sprite);
static void CB_FadeInFlyMap(void);
static void CB_HandleFlyMapInput(void);
static void CB_ExitFlyMap(void);

// .rodata

static const u16 sRegionMapCursorPal[] = INCBIN_U16("graphics/pokenav/cursor.gbapal");
static const u32 sRegionMapCursorSmallGfxLZ[] = INCBIN_U32("graphics/pokenav/cursor_small.4bpp.lz");
static const u32 sRegionMapCursorLargeGfxLZ[] = INCBIN_U32("graphics/pokenav/cursor_large.4bpp.lz");
static const u16 sRegionMapBg_Pal[] = INCBIN_U16("graphics/pokenav/region_map.gbapal");
static const u32 sRegionMapBg_GfxLZ[] = INCBIN_U32("graphics/pokenav/region_map.8bpp.lz");
static const u32 sRegionMapBg_TilemapLZ[] = INCBIN_U32("graphics/pokenav/region_map_map.bin.lz");
static const u16 sRegionMapPlayerIcon_BrendanPal[] = INCBIN_U16("graphics/pokenav/brendan_icon.gbapal");
static const u8 sRegionMapPlayerIcon_BrendanGfx[] = INCBIN_U8("graphics/pokenav/brendan_icon.4bpp");
static const u16 sRegionMapPlayerIcon_MayPal[] = INCBIN_U16("graphics/pokenav/may_icon.gbapal");
static const u8 sRegionMapPlayerIcon_MayGfx[] = INCBIN_U8("graphics/pokenav/may_icon.4bpp");

static const u8 sRegionMap_MapSectionLayout[] = INCBIN_U8("graphics/pokenav/region_map_section_layout.bin");

#include "data/region_map/region_map_entries.h"

static const u16 sRegionMap_SpecialPlaceLocations[][2] =
{
    {MAPSEC_UNDERWATER_105,             MAPSEC_ROUTE_105},
    {MAPSEC_UNDERWATER_124,             MAPSEC_ROUTE_124},
    #ifdef BUGFIX
    {MAPSEC_UNDERWATER_125,             MAPSEC_ROUTE_125},
    #else
    {MAPSEC_UNDERWATER_125,             MAPSEC_ROUTE_129}, // BUG: Map will incorrectly display the name of Route 129 when diving on Route 125 (for Marine Cave only)
    #endif
    {MAPSEC_UNDERWATER_126,             MAPSEC_ROUTE_126},
    {MAPSEC_UNDERWATER_127,             MAPSEC_ROUTE_127},
    {MAPSEC_UNDERWATER_128,             MAPSEC_ROUTE_128},
    {MAPSEC_UNDERWATER_129,             MAPSEC_ROUTE_129},
    {MAPSEC_UNDERWATER_SOOTOPOLIS,      MAPSEC_SOOTOPOLIS_CITY},
    {MAPSEC_UNDERWATER_SEAFLOOR_CAVERN, MAPSEC_ROUTE_128},
    {MAPSEC_AQUA_HIDEOUT,               MAPSEC_LILYCOVE_CITY},
    {MAPSEC_AQUA_HIDEOUT_OLD,           MAPSEC_LILYCOVE_CITY},
    {MAPSEC_MAGMA_HIDEOUT,              MAPSEC_ROUTE_112},
    {MAPSEC_UNDERWATER_SEALED_CHAMBER,  MAPSEC_ROUTE_134},
    {MAPSEC_PETALBURG_WOODS,            MAPSEC_ROUTE_104},
    {MAPSEC_JAGGED_PASS,                MAPSEC_ROUTE_112},
    {MAPSEC_MT_PYRE,                    MAPSEC_ROUTE_122},
    {MAPSEC_SKY_PILLAR,                 MAPSEC_ROUTE_131},
    {MAPSEC_MIRAGE_TOWER,               MAPSEC_ROUTE_111},
    {MAPSEC_TRAINER_HILL,               MAPSEC_ROUTE_111},
    {MAPSEC_DESERT_UNDERPASS,           MAPSEC_ROUTE_114},
    {MAPSEC_ALTERING_CAVE,              MAPSEC_ROUTE_103},
    {MAPSEC_ARTISAN_CAVE,               MAPSEC_ROUTE_103},
    {MAPSEC_ABANDONED_SHIP,             MAPSEC_ROUTE_108},
    {MAPSEC_NONE,                       MAPSEC_NONE}
};

static const u16 sMarineCaveMapSecIds[] =
{
    MAPSEC_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE
};

static const u16 sTerraOrMarineCaveMapSecIds[ABNORMAL_WEATHER_LOCATIONS] =
{
    [ABNORMAL_WEATHER_ROUTE_114_NORTH - 1] = MAPSEC_ROUTE_114,
    [ABNORMAL_WEATHER_ROUTE_114_SOUTH - 1] = MAPSEC_ROUTE_114,
    [ABNORMAL_WEATHER_ROUTE_115_WEST  - 1] = MAPSEC_ROUTE_115,
    [ABNORMAL_WEATHER_ROUTE_115_EAST  - 1] = MAPSEC_ROUTE_115,
    [ABNORMAL_WEATHER_ROUTE_116_NORTH - 1] = MAPSEC_ROUTE_116,
    [ABNORMAL_WEATHER_ROUTE_116_SOUTH - 1] = MAPSEC_ROUTE_116,
    [ABNORMAL_WEATHER_ROUTE_118_EAST  - 1] = MAPSEC_ROUTE_118,
    [ABNORMAL_WEATHER_ROUTE_118_WEST  - 1] = MAPSEC_ROUTE_118,
    [ABNORMAL_WEATHER_ROUTE_105_NORTH - 1] = MAPSEC_ROUTE_105,
    [ABNORMAL_WEATHER_ROUTE_105_SOUTH - 1] = MAPSEC_ROUTE_105,
    [ABNORMAL_WEATHER_ROUTE_125_WEST  - 1] = MAPSEC_ROUTE_125,
    [ABNORMAL_WEATHER_ROUTE_125_EAST  - 1] = MAPSEC_ROUTE_125,
    [ABNORMAL_WEATHER_ROUTE_127_NORTH - 1] = MAPSEC_ROUTE_127,
    [ABNORMAL_WEATHER_ROUTE_127_SOUTH - 1] = MAPSEC_ROUTE_127,
    [ABNORMAL_WEATHER_ROUTE_129_WEST  - 1] = MAPSEC_ROUTE_129,
    [ABNORMAL_WEATHER_ROUTE_129_EAST  - 1] = MAPSEC_ROUTE_129
};

#define MARINE_CAVE_COORD(location)(ABNORMAL_WEATHER_##location - MARINE_CAVE_LOCATIONS_START)

static const struct UCoords16 sMarineCaveLocationCoords[MARINE_CAVE_LOCATIONS] =
{
    [MARINE_CAVE_COORD(ROUTE_105_NORTH)] = {0, 10},
    [MARINE_CAVE_COORD(ROUTE_105_SOUTH)] = {0, 12},
    [MARINE_CAVE_COORD(ROUTE_125_WEST)]  = {24, 3},
    [MARINE_CAVE_COORD(ROUTE_125_EAST)]  = {25, 4},
    [MARINE_CAVE_COORD(ROUTE_127_NORTH)] = {25, 6},
    [MARINE_CAVE_COORD(ROUTE_127_SOUTH)] = {25, 7},
    [MARINE_CAVE_COORD(ROUTE_129_WEST)]  = {24, 10},
    [MARINE_CAVE_COORD(ROUTE_129_EAST)]  = {24, 10}
};

static const u8 sMapSecAquaHideoutOld[] =
{
    MAPSEC_AQUA_HIDEOUT_OLD
};

static const struct OamData sRegionMapCursorOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1
};

static const union AnimCmd sRegionMapCursorAnim1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sRegionMapCursorAnim2[] =
{
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sRegionMapCursorAnimTable[] =
{
    sRegionMapCursorAnim1,
    sRegionMapCursorAnim2
};

static const struct SpritePalette sRegionMapCursorSpritePalette =
{
    .data = sRegionMapCursorPal,
    .tag = 0
};

static const struct SpriteTemplate sRegionMapCursorSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sRegionMapCursorOam,
    .anims = sRegionMapCursorAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CursorMapFull
};

static const struct OamData sRegionMapPlayerIconOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const union AnimCmd sRegionMapPlayerIconAnim1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sRegionMapPlayerIconAnimTable[] =
{
    sRegionMapPlayerIconAnim1
};

// Event islands that don't appear on map. (Southern Island does)
static const u8 sMapSecIdsOffMap[] =
{
    MAPSEC_BIRTH_ISLAND,
    MAPSEC_FARAWAY_ISLAND,
    MAPSEC_NAVEL_ROCK
};

static const u16 sRegionMapFramePal[] = INCBIN_U16("graphics/pokenav/map_frame.gbapal");

static const u32 sRegionMapFrameGfxLZ[] = INCBIN_U32("graphics/pokenav/map_frame.4bpp.lz");

static const u32 sRegionMapFrameTilemapLZ[] = INCBIN_U32("graphics/pokenav/map_frame.bin.lz");

static const u16 sFlyTargetIcons_Pal[] = INCBIN_U16("graphics/pokenav/fly_target_icons.gbapal");

static const u32 sFlyTargetIcons_Gfx[] = INCBIN_U32("graphics/pokenav/fly_target_icons.4bpp.lz");

static const u8 sMapHealLocations[][3] =
{
    {MAP_GROUP(LITTLEROOT_TOWN), MAP_NUM(LITTLEROOT_TOWN), HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F},
    {MAP_GROUP(OLDALE_TOWN), MAP_NUM(OLDALE_TOWN), HEAL_LOCATION_OLDALE_TOWN},
    {MAP_GROUP(DEWFORD_TOWN), MAP_NUM(DEWFORD_TOWN), HEAL_LOCATION_DEWFORD_TOWN},
    {MAP_GROUP(LAVARIDGE_TOWN), MAP_NUM(LAVARIDGE_TOWN), HEAL_LOCATION_LAVARIDGE_TOWN},
    {MAP_GROUP(FALLARBOR_TOWN), MAP_NUM(FALLARBOR_TOWN), HEAL_LOCATION_FALLARBOR_TOWN},
    {MAP_GROUP(VERDANTURF_TOWN), MAP_NUM(VERDANTURF_TOWN), HEAL_LOCATION_VERDANTURF_TOWN},
    {MAP_GROUP(PACIFIDLOG_TOWN), MAP_NUM(PACIFIDLOG_TOWN), HEAL_LOCATION_PACIFIDLOG_TOWN},
    {MAP_GROUP(PETALBURG_CITY), MAP_NUM(PETALBURG_CITY), HEAL_LOCATION_PETALBURG_CITY},
    {MAP_GROUP(SLATEPORT_CITY), MAP_NUM(SLATEPORT_CITY), HEAL_LOCATION_SLATEPORT_CITY},
    {MAP_GROUP(MAUVILLE_CITY), MAP_NUM(MAUVILLE_CITY), HEAL_LOCATION_MAUVILLE_CITY},
    {MAP_GROUP(RUSTBORO_CITY), MAP_NUM(RUSTBORO_CITY), HEAL_LOCATION_RUSTBORO_CITY},
    {MAP_GROUP(FORTREE_CITY), MAP_NUM(FORTREE_CITY), HEAL_LOCATION_FORTREE_CITY},
    {MAP_GROUP(LILYCOVE_CITY), MAP_NUM(LILYCOVE_CITY), HEAL_LOCATION_LILYCOVE_CITY},
    {MAP_GROUP(MOSSDEEP_CITY), MAP_NUM(MOSSDEEP_CITY), HEAL_LOCATION_MOSSDEEP_CITY},
    {MAP_GROUP(SOOTOPOLIS_CITY), MAP_NUM(SOOTOPOLIS_CITY), HEAL_LOCATION_SOOTOPOLIS_CITY},
    {MAP_GROUP(EVER_GRANDE_CITY), MAP_NUM(EVER_GRANDE_CITY), HEAL_LOCATION_EVER_GRANDE_CITY},
    {MAP_GROUP(ROUTE101), MAP_NUM(ROUTE101), 0},
    {MAP_GROUP(ROUTE102), MAP_NUM(ROUTE102), 0},
    {MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103), 0},
    {MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104), 0},
    {MAP_GROUP(ROUTE105), MAP_NUM(ROUTE105), 0},
    {MAP_GROUP(ROUTE106), MAP_NUM(ROUTE106), 0},
    {MAP_GROUP(ROUTE107), MAP_NUM(ROUTE107), 0},
    {MAP_GROUP(ROUTE108), MAP_NUM(ROUTE108), 0},
    {MAP_GROUP(ROUTE109), MAP_NUM(ROUTE109), 0},
    {MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110), 0},
    {MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111), 0},
    {MAP_GROUP(ROUTE112), MAP_NUM(ROUTE112), 0},
    {MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113), 0},
    {MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114), 0},
    {MAP_GROUP(ROUTE115), MAP_NUM(ROUTE115), 0},
    {MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116), 0},
    {MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117), 0},
    {MAP_GROUP(ROUTE118), MAP_NUM(ROUTE118), 0},
    {MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119), 0},
    {MAP_GROUP(ROUTE120), MAP_NUM(ROUTE120), 0},
    {MAP_GROUP(ROUTE121), MAP_NUM(ROUTE121), 0},
    {MAP_GROUP(ROUTE122), MAP_NUM(ROUTE122), 0},
    {MAP_GROUP(ROUTE123), MAP_NUM(ROUTE123), 0},
    {MAP_GROUP(ROUTE124), MAP_NUM(ROUTE124), 0},
    {MAP_GROUP(ROUTE125), MAP_NUM(ROUTE125), 0},
    {MAP_GROUP(ROUTE126), MAP_NUM(ROUTE126), 0},
    {MAP_GROUP(ROUTE127), MAP_NUM(ROUTE127), 0},
    {MAP_GROUP(ROUTE128), MAP_NUM(ROUTE128), 0},
    {MAP_GROUP(ROUTE129), MAP_NUM(ROUTE129), 0},
    {MAP_GROUP(ROUTE130), MAP_NUM(ROUTE130), 0},
    {MAP_GROUP(ROUTE131), MAP_NUM(ROUTE131), 0},
    {MAP_GROUP(ROUTE132), MAP_NUM(ROUTE132), 0},
    {MAP_GROUP(ROUTE133), MAP_NUM(ROUTE133), 0},
    {MAP_GROUP(ROUTE134), MAP_NUM(ROUTE134), 0}
};

static const u8 *const sEverGrandeCityNames[] =
{
    gText_PokemonLeague,
    gText_PokemonCenter
};

static const struct MultiNameFlyDest sMultiNameFlyDestinations[] =
{
    {
        .name = sEverGrandeCityNames,
        .mapSecId = MAPSEC_EVER_GRANDE_CITY,
        .flag = FLAG_LANDMARK_POKEMON_LEAGUE
    }
};

static const struct BgTemplate sFlyMapBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2
    }
};

static const struct WindowTemplate sFlyMapWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 17,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x01
    },
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 15,
        .width = 12,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x19
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 18,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x49
    },
    DUMMY_WIN_TEMPLATE
};

static const struct SpritePalette sFlyTargetIconsSpritePalette =
{
    .data = sFlyTargetIcons_Pal,
    .tag = 2
};

static const u16 sRedOutlineFlyDestinations[][2] =
{
    {
        FLAG_LANDMARK_BATTLE_FRONTIER,
        MAPSEC_BATTLE_FRONTIER
    },
    {
        -1,
        MAPSEC_NONE
    }
};

static const struct OamData sFlyDestIcon_OamData =
{
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 2
};

static const union AnimCmd sFlyDestIcon_Anim_8x8CanFly[] =
{
    ANIMCMD_FRAME( 0, 5),
    ANIMCMD_END
};

static const union AnimCmd sFlyDestIcon_Anim_16x8CanFly[] =
{
    ANIMCMD_FRAME( 1, 5),
    ANIMCMD_END
};

static const union AnimCmd sFlyDestIcon_Anim_8x16CanFly[] =
{
    ANIMCMD_FRAME( 3, 5),
    ANIMCMD_END
};

static const union AnimCmd sFlyDestIcon_Anim_8x8CantFly[] =
{
    ANIMCMD_FRAME( 5, 5),
    ANIMCMD_END
};

static const union AnimCmd sFlyDestIcon_Anim_16x8CantFly[] =
{
    ANIMCMD_FRAME( 6, 5),
    ANIMCMD_END
};

static const union AnimCmd sFlyDestIcon_Anim_8x16CantFly[] =
{
    ANIMCMD_FRAME( 8, 5),
    ANIMCMD_END
};

// Only used by Battle Frontier
static const union AnimCmd sFlyDestIcon_Anim_RedOutline[] =
{
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sFlyDestIcon_Anims[] =
{
    [SPRITE_SHAPE(8x8)]       = sFlyDestIcon_Anim_8x8CanFly,
    [SPRITE_SHAPE(16x8)]      = sFlyDestIcon_Anim_16x8CanFly,
    [SPRITE_SHAPE(8x16)]      = sFlyDestIcon_Anim_8x16CanFly,
    [SPRITE_SHAPE(8x8)  + 3]  = sFlyDestIcon_Anim_8x8CantFly,
    [SPRITE_SHAPE(16x8) + 3]  = sFlyDestIcon_Anim_16x8CantFly,
    [SPRITE_SHAPE(8x16) + 3]  = sFlyDestIcon_Anim_8x16CantFly,
    [FLYDESTICON_RED_OUTLINE] = sFlyDestIcon_Anim_RedOutline
};

static const struct SpriteTemplate sFlyDestIconSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 2,
    .oam = &sFlyDestIcon_OamData,
    .anims = sFlyDestIcon_Anims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// .text

void InitRegionMap(struct RegionMap *regionMap, bool8 zoomed)
{
    InitRegionMapData(regionMap, NULL, zoomed);
    while (LoadRegionMapGfx());
}

void InitRegionMapData(struct RegionMap *regionMap, const struct BgTemplate *template, bool8 zoomed)
{
    gRegionMap = regionMap;
    gRegionMap->initStep = 0;
    gRegionMap->zoomed = zoomed;
    gRegionMap->inputCallback = zoomed == TRUE ? ProcessRegionMapInput_Zoomed : ProcessRegionMapInput_Full;
    if (template != NULL)
    {
        gRegionMap->bgNum = template->bg;
        gRegionMap->charBaseIdx = template->charBaseIndex;
        gRegionMap->mapBaseIdx = template->mapBaseIndex;
        gRegionMap->bgManaged = TRUE;
    }
    else
    {
        gRegionMap->bgNum = 2;
        gRegionMap->charBaseIdx = 2;
        gRegionMap->mapBaseIdx = 28;
        gRegionMap->bgManaged = FALSE;
    }
}

void ShowRegionMapForPokedexAreaScreen(struct RegionMap *regionMap)
{
    gRegionMap = regionMap;
    InitMapBasedOnPlayerLocation();
    gRegionMap->playerIconSpritePosX = gRegionMap->cursorPosX;
    gRegionMap->playerIconSpritePosY = gRegionMap->cursorPosY;
}

bool8 LoadRegionMapGfx(void)
{
    switch (gRegionMap->initStep)
    {
    case 0:
        if (gRegionMap->bgManaged)
            DecompressAndCopyTileDataToVram(gRegionMap->bgNum, sRegionMapBg_GfxLZ, 0, 0, 0);
        else
            LZ77UnCompVram(sRegionMapBg_GfxLZ, (u16 *)BG_CHAR_ADDR(2));
        break;
    case 1:
        if (gRegionMap->bgManaged)
        {
            if (!FreeTempTileDataBuffersIfPossible())
                DecompressAndCopyTileDataToVram(gRegionMap->bgNum, sRegionMapBg_TilemapLZ, 0, 0, 1);
        }
        else
        {
            LZ77UnCompVram(sRegionMapBg_TilemapLZ, (u16 *)BG_SCREEN_ADDR(28));
        }
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
            LoadPalette(sRegionMapBg_Pal, 0x70, 0x60);
        break;
    case 3:
        LZ77UnCompWram(sRegionMapCursorSmallGfxLZ, gRegionMap->cursorSmallImage);
        break;
    case 4:
        LZ77UnCompWram(sRegionMapCursorLargeGfxLZ, gRegionMap->cursorLargeImage);
        break;
    case 5:
        InitMapBasedOnPlayerLocation();
        gRegionMap->playerIconSpritePosX = gRegionMap->cursorPosX;
        gRegionMap->playerIconSpritePosY = gRegionMap->cursorPosY;
        gRegionMap->mapSecId = CorrectSpecialMapSecId_Internal(gRegionMap->mapSecId);
        gRegionMap->mapSecType = GetMapsecType(gRegionMap->mapSecId);
        GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, MAP_NAME_LENGTH);
        break;
    case 6:
        if (gRegionMap->zoomed == FALSE)
        {
            CalcZoomScrollParams(0, 0, 0, 0, 0x100, 0x100, 0);
        }
        else
        {
            gRegionMap->scrollX = gRegionMap->cursorPosX * 8 - 0x34;
            gRegionMap->scrollY = gRegionMap->cursorPosY * 8 - 0x44;
            gRegionMap->zoomedCursorPosX = gRegionMap->cursorPosX;
            gRegionMap->zoomedCursorPosY = gRegionMap->cursorPosY;
            CalcZoomScrollParams(gRegionMap->scrollX, gRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
        }
        break;
    case 7:
        GetPositionOfCursorWithinMapSec();
        UpdateRegionMapVideoRegs();
        gRegionMap->cursorSprite = NULL;
        gRegionMap->playerIconSprite = NULL;
        gRegionMap->cursorMovementFrameCounter = 0;
        gRegionMap->blinkPlayerIcon = FALSE;
        if (gRegionMap->bgManaged)
        {
            SetBgAttribute(gRegionMap->bgNum, BG_ATTR_SCREENSIZE, 2);
            SetBgAttribute(gRegionMap->bgNum, BG_ATTR_CHARBASEINDEX, gRegionMap->charBaseIdx);
            SetBgAttribute(gRegionMap->bgNum, BG_ATTR_MAPBASEINDEX, gRegionMap->mapBaseIdx);
            SetBgAttribute(gRegionMap->bgNum, BG_ATTR_WRAPAROUND, 1);
            SetBgAttribute(gRegionMap->bgNum, BG_ATTR_PALETTEMODE, 1);
        }
        gRegionMap->initStep++;
        return FALSE;
    default:
        return FALSE;
    }
    gRegionMap->initStep++;
    return TRUE;
}

void sub_8123030(u16 color, u32 coeff)
{
    BlendPalettes(0x380, coeff, color);
    CpuCopy16(gPlttBufferFaded + 0x70, gPlttBufferUnfaded + 0x70, 0x60);
}

void FreeRegionMapIconResources(void)
{
    if (gRegionMap->cursorSprite != NULL)
    {
        DestroySprite(gRegionMap->cursorSprite);
        FreeSpriteTilesByTag(gRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(gRegionMap->cursorPaletteTag);
    }
    if (gRegionMap->playerIconSprite != NULL)
    {
        DestroySprite(gRegionMap->playerIconSprite);
        FreeSpriteTilesByTag(gRegionMap->playerIconTileTag);
        FreeSpritePaletteByTag(gRegionMap->playerIconPaletteTag);
    }
}

u8 DoRegionMapInputCallback(void)
{
    return gRegionMap->inputCallback();
}

static u8 ProcessRegionMapInput_Full(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    gRegionMap->cursorDeltaX = 0;
    gRegionMap->cursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && gRegionMap->cursorPosY > MAPCURSOR_Y_MIN)
    {
        gRegionMap->cursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && gRegionMap->cursorPosY < MAPCURSOR_Y_MAX)
    {
        gRegionMap->cursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && gRegionMap->cursorPosX > MAPCURSOR_X_MIN)
    {
        gRegionMap->cursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && gRegionMap->cursorPosX < MAPCURSOR_X_MAX)
    {
        gRegionMap->cursorDeltaX = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        gRegionMap->cursorMovementFrameCounter = 4;
        gRegionMap->inputCallback = MoveRegionMapCursor_Full;
    }
    return input;
}

static u8 MoveRegionMapCursor_Full(void)
{
    u16 mapSecId;

    if (gRegionMap->cursorMovementFrameCounter != 0)
        return MAP_INPUT_MOVE_CONT;

    if (gRegionMap->cursorDeltaX > 0)
    {
        gRegionMap->cursorPosX++;
    }
    if (gRegionMap->cursorDeltaX < 0)
    {
        gRegionMap->cursorPosX--;
    }
    if (gRegionMap->cursorDeltaY > 0)
    {
        gRegionMap->cursorPosY++;
    }
    if (gRegionMap->cursorDeltaY < 0)
    {
        gRegionMap->cursorPosY--;
    }

    mapSecId = GetMapSecIdAt(gRegionMap->cursorPosX, gRegionMap->cursorPosY);
    gRegionMap->mapSecType = GetMapsecType(mapSecId);
    if (mapSecId != gRegionMap->mapSecId)
    {
        gRegionMap->mapSecId = mapSecId;
        GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, MAP_NAME_LENGTH);
    }
    GetPositionOfCursorWithinMapSec();
    gRegionMap->inputCallback = ProcessRegionMapInput_Full;
    return MAP_INPUT_MOVE_END;
}

static u8 ProcessRegionMapInput_Zoomed(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    gRegionMap->zoomedCursorDeltaX = 0;
    gRegionMap->zoomedCursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && gRegionMap->scrollY > -0x34)
    {
        gRegionMap->zoomedCursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && gRegionMap->scrollY < 0x3c)
    {
        gRegionMap->zoomedCursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && gRegionMap->scrollX > -0x2c)
    {
        gRegionMap->zoomedCursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && gRegionMap->scrollX < 0xac)
    {
        gRegionMap->zoomedCursorDeltaX = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        gRegionMap->inputCallback = MoveRegionMapCursor_Zoomed;
        gRegionMap->zoomedCursorMovementFrameCounter = 0;
    }
    return input;
}

static u8 MoveRegionMapCursor_Zoomed(void)
{
    u16 x;
    u16 y;
    u16 mapSecId;

    gRegionMap->scrollY += gRegionMap->zoomedCursorDeltaY;
    gRegionMap->scrollX += gRegionMap->zoomedCursorDeltaX;
    RegionMap_SetBG2XAndBG2Y(gRegionMap->scrollX, gRegionMap->scrollY);
    gRegionMap->zoomedCursorMovementFrameCounter++;
    if (gRegionMap->zoomedCursorMovementFrameCounter == 8)
    {
        x = (gRegionMap->scrollX + 0x2c) / 8 + 1;
        y = (gRegionMap->scrollY + 0x34) / 8 + 2;
        if (x != gRegionMap->zoomedCursorPosX || y != gRegionMap->zoomedCursorPosY)
        {
            gRegionMap->zoomedCursorPosX = x;
            gRegionMap->zoomedCursorPosY = y;
            mapSecId = GetMapSecIdAt(x, y);
            gRegionMap->mapSecType = GetMapsecType(mapSecId);
            if (mapSecId != gRegionMap->mapSecId)
            {
                gRegionMap->mapSecId = mapSecId;
                GetMapName(gRegionMap->mapSecName, gRegionMap->mapSecId, MAP_NAME_LENGTH);
            }
            GetPositionOfCursorWithinMapSec();
        }
        gRegionMap->zoomedCursorMovementFrameCounter = 0;
        gRegionMap->inputCallback = ProcessRegionMapInput_Zoomed;
        return MAP_INPUT_MOVE_END;
    }
    return MAP_INPUT_MOVE_CONT;
}

void SetRegionMapDataForZoom(void)
{
    if (gRegionMap->zoomed == FALSE)
    {
        gRegionMap->scrollY = 0;
        gRegionMap->scrollX = 0;
        gRegionMap->unk_040 = 0;
        gRegionMap->unk_03c = 0;
        gRegionMap->unk_060 = gRegionMap->cursorPosX * 8 - 0x34;
        gRegionMap->unk_062 = gRegionMap->cursorPosY * 8 - 0x44;
        gRegionMap->unk_044 = (gRegionMap->unk_060 << 8) / 16;
        gRegionMap->unk_048 = (gRegionMap->unk_062 << 8) / 16;
        gRegionMap->zoomedCursorPosX = gRegionMap->cursorPosX;
        gRegionMap->zoomedCursorPosY = gRegionMap->cursorPosY;
        gRegionMap->unk_04c = 0x10000;
        gRegionMap->unk_050 = -0x800;
    }
    else
    {
        gRegionMap->unk_03c = gRegionMap->scrollX * 0x100;
        gRegionMap->unk_040 = gRegionMap->scrollY * 0x100;
        gRegionMap->unk_060 = 0;
        gRegionMap->unk_062 = 0;
        gRegionMap->unk_044 = -(gRegionMap->unk_03c / 16);
        gRegionMap->unk_048 = -(gRegionMap->unk_040 / 16);
        gRegionMap->cursorPosX = gRegionMap->zoomedCursorPosX;
        gRegionMap->cursorPosY = gRegionMap->zoomedCursorPosY;
        gRegionMap->unk_04c = 0x8000;
        gRegionMap->unk_050 = 0x800;
    }
    gRegionMap->unk_06e = 0;
    FreeRegionMapCursorSprite();
    HideRegionMapPlayerIcon();
}

bool8 UpdateRegionMapZoom(void)
{
    bool8 retVal;

    if (gRegionMap->unk_06e >= 16)
    {
        return FALSE;
    }
    gRegionMap->unk_06e++;
    if (gRegionMap->unk_06e == 16)
    {
        gRegionMap->unk_044 = 0;
        gRegionMap->unk_048 = 0;
        gRegionMap->scrollX = gRegionMap->unk_060;
        gRegionMap->scrollY = gRegionMap->unk_062;
        gRegionMap->unk_04c = (gRegionMap->zoomed == FALSE) ? (128 << 8) : (256 << 8);
        gRegionMap->zoomed = !gRegionMap->zoomed;
        gRegionMap->inputCallback = (gRegionMap->zoomed == FALSE) ? ProcessRegionMapInput_Full : ProcessRegionMapInput_Zoomed;
        CreateRegionMapCursor(gRegionMap->cursorTileTag, gRegionMap->cursorPaletteTag);
        UnhideRegionMapPlayerIcon();
        retVal = FALSE;
    }
    else
    {
        gRegionMap->unk_03c += gRegionMap->unk_044;
        gRegionMap->unk_040 += gRegionMap->unk_048;
        gRegionMap->scrollX = gRegionMap->unk_03c >> 8;
        gRegionMap->scrollY = gRegionMap->unk_040 >> 8;
        gRegionMap->unk_04c += gRegionMap->unk_050;
        if ((gRegionMap->unk_044 < 0 && gRegionMap->scrollX < gRegionMap->unk_060) || (gRegionMap->unk_044 > 0 && gRegionMap->scrollX > gRegionMap->unk_060))
        {
            gRegionMap->scrollX = gRegionMap->unk_060;
            gRegionMap->unk_044 = 0;
        }
        if ((gRegionMap->unk_048 < 0 && gRegionMap->scrollY < gRegionMap->unk_062) || (gRegionMap->unk_048 > 0 && gRegionMap->scrollY > gRegionMap->unk_062))
        {
            gRegionMap->scrollY = gRegionMap->unk_062;
            gRegionMap->unk_048 = 0;
        }
        if (gRegionMap->zoomed == FALSE)
        {
            if (gRegionMap->unk_04c < (128 << 8))
            {
                gRegionMap->unk_04c = (128 << 8);
                gRegionMap->unk_050 = 0;
            }
        }
        else
        {
            if (gRegionMap->unk_04c > (256 << 8))
            {
                gRegionMap->unk_04c = (256 << 8);
                gRegionMap->unk_050 = 0;
            }
        }
        retVal = TRUE;
    }
    CalcZoomScrollParams(gRegionMap->scrollX, gRegionMap->scrollY, 0x38, 0x48, gRegionMap->unk_04c >> 8, gRegionMap->unk_04c >> 8, 0);
    return retVal;
}

static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
{
    s32 var1;
    s32 var2;
    s32 var3;
    s32 var4;

    gRegionMap->bg2pa = e * gSineTable[rotation + 64] >> 8;
    gRegionMap->bg2pc = e * -gSineTable[rotation] >> 8;
    gRegionMap->bg2pb = f * gSineTable[rotation] >> 8;
    gRegionMap->bg2pd = f * gSineTable[rotation + 64] >> 8;

    var1 = (scrollX << 8) + (c << 8);
    var2 = d * gRegionMap->bg2pb + gRegionMap->bg2pa * c;
    gRegionMap->bg2x = var1 - var2;

    var3 = (scrollY << 8) + (d << 8);
    var4 = gRegionMap->bg2pd * d + gRegionMap->bg2pc * c;
    gRegionMap->bg2y = var3 - var4;

    gRegionMap->needUpdateVideoRegs = TRUE;
}

static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y)
{
    gRegionMap->bg2x = (x << 8) + 0x1c00;
    gRegionMap->bg2y = (y << 8) + 0x2400;
    gRegionMap->needUpdateVideoRegs = TRUE;
}

void UpdateRegionMapVideoRegs(void)
{
    if (gRegionMap->needUpdateVideoRegs)
    {
        SetGpuReg(REG_OFFSET_BG2PA, gRegionMap->bg2pa);
        SetGpuReg(REG_OFFSET_BG2PB, gRegionMap->bg2pb);
        SetGpuReg(REG_OFFSET_BG2PC, gRegionMap->bg2pc);
        SetGpuReg(REG_OFFSET_BG2PD, gRegionMap->bg2pd);
        SetGpuReg(REG_OFFSET_BG2X_L, gRegionMap->bg2x);
        SetGpuReg(REG_OFFSET_BG2X_H, gRegionMap->bg2x >> 16);
        SetGpuReg(REG_OFFSET_BG2Y_L, gRegionMap->bg2y);
        SetGpuReg(REG_OFFSET_BG2Y_H, gRegionMap->bg2y >> 16);
        gRegionMap->needUpdateVideoRegs = FALSE;
    }
}

void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y)
{
    CalcZoomScrollParams(x, y, 0x38, 0x48, 0x100, 0x100, 0);
    UpdateRegionMapVideoRegs();
    if (gRegionMap->playerIconSprite != NULL)
    {
        gRegionMap->playerIconSprite->pos2.x = -x;
        gRegionMap->playerIconSprite->pos2.y = -y;
    }
}

static u16 GetMapSecIdAt(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;
    return sRegionMap_MapSectionLayout[x + y * MAP_WIDTH];
}

static void InitMapBasedOnPlayerLocation(void)
{
    const struct MapHeader *mapHeader;
    u16 mapWidth;
    u16 mapHeight;
    u16 x;
    u16 y;
    u16 dimensionScale;
    u16 xOnMap;
    struct WarpData *warp;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SS_TIDAL_CORRIDOR)
        && (gSaveBlock1Ptr->location.mapNum == MAP_NUM(SS_TIDAL_CORRIDOR)
            || gSaveBlock1Ptr->location.mapNum == MAP_NUM(SS_TIDAL_LOWER_DECK)
            || gSaveBlock1Ptr->location.mapNum == MAP_NUM(SS_TIDAL_ROOMS)))
    {
        RegionMap_InitializeStateBasedOnSSTidalLocation();
        return;
    }

    switch (GetMapTypeByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
    default:
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_UNDERWATER:
    case MAP_TYPE_OCEAN_ROUTE:
        gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        gRegionMap->playerIsInCave = FALSE;
        mapWidth = gMapHeader.mapLayout->width;
        mapHeight = gMapHeader.mapLayout->height;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        if (gRegionMap->mapSecId == MAPSEC_UNDERWATER_SEAFLOOR_CAVERN || gRegionMap->mapSecId == MAPSEC_UNDERWATER_MARINE_CAVE)
            gRegionMap->playerIsInCave = TRUE;
        break;
    case MAP_TYPE_UNDERGROUND:
    case MAP_TYPE_UNKNOWN:
        if (gMapHeader.flags & MAP_ALLOW_ESCAPING)
        {
            mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
            gRegionMap->mapSecId = mapHeader->regionMapSectionId;
            gRegionMap->playerIsInCave = TRUE;
            mapWidth = mapHeader->mapLayout->width;
            mapHeight = mapHeader->mapLayout->height;
            x = gSaveBlock1Ptr->escapeWarp.x;
            y = gSaveBlock1Ptr->escapeWarp.y;
        }
        else
        {
            gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            gRegionMap->playerIsInCave = TRUE;
            mapWidth = 1;
            mapHeight = 1;
            x = 1;
            y = 1;
        }
        break;
    case MAP_TYPE_SECRET_BASE:
        mapHeader = Overworld_GetMapHeaderByGroupAndId((u16)gSaveBlock1Ptr->dynamicWarp.mapGroup, (u16)gSaveBlock1Ptr->dynamicWarp.mapNum);
        gRegionMap->mapSecId = mapHeader->regionMapSectionId;
        gRegionMap->playerIsInCave = TRUE;
        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->dynamicWarp.x;
        y = gSaveBlock1Ptr->dynamicWarp.y;
        break;
    case MAP_TYPE_INDOOR:
        gRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        if (gRegionMap->mapSecId != MAPSEC_DYNAMIC)
        {
            warp = &gSaveBlock1Ptr->escapeWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
        }
        else
        {
            warp = &gSaveBlock1Ptr->dynamicWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
            gRegionMap->mapSecId = mapHeader->regionMapSectionId;
        }

        if (IsPlayerInAquaHideout(gRegionMap->mapSecId))
            gRegionMap->playerIsInCave = TRUE;
        else
            gRegionMap->playerIsInCave = FALSE;

        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = warp->x;
        y = warp->y;
        break;
    }

    xOnMap = x;

    dimensionScale = mapWidth / gRegionMapEntries[gRegionMap->mapSecId].width;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    x /= dimensionScale;
    if (x >= gRegionMapEntries[gRegionMap->mapSecId].width)
    {
        x = gRegionMapEntries[gRegionMap->mapSecId].width - 1;
    }

    dimensionScale = mapHeight / gRegionMapEntries[gRegionMap->mapSecId].height;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    y /= dimensionScale;
    if (y >= gRegionMapEntries[gRegionMap->mapSecId].height)
    {
        y = gRegionMapEntries[gRegionMap->mapSecId].height - 1;
    }

    switch (gRegionMap->mapSecId)
    {
    case MAPSEC_ROUTE_114:
        if (y != 0)
            x = 0;
        break;
    case MAPSEC_ROUTE_126:
    case MAPSEC_UNDERWATER_126:
        x = 0;
        if (gSaveBlock1Ptr->pos.x > 32)
            x++;
        if (gSaveBlock1Ptr->pos.x > 51)
            x++;

        y = 0;
        if (gSaveBlock1Ptr->pos.y > 37)
            y++;
        if (gSaveBlock1Ptr->pos.y > 56)
            y++;
        break;
    case MAPSEC_ROUTE_121:
        x = 0;
        if (xOnMap > 14)
            x++;
        if (xOnMap > 28)
            x++;
        if (xOnMap > 54)
            x++;
        break;
    case MAPSEC_UNDERWATER_MARINE_CAVE:
        GetMarineCaveCoords(&gRegionMap->cursorPosX, &gRegionMap->cursorPosY);
        return;
    }
    gRegionMap->cursorPosX = gRegionMapEntries[gRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    gRegionMap->cursorPosY = gRegionMapEntries[gRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static void RegionMap_InitializeStateBasedOnSSTidalLocation(void)
{
    u16 y;
    u16 x;
    u8 mapGroup;
    u8 mapNum;
    u16 dimensionScale;
    s16 xOnMap;
    s16 yOnMap;
    const struct MapHeader *mapHeader;

    y = 0;
    x = 0;
    switch (GetSSTidalLocation(&mapGroup, &mapNum, &xOnMap, &yOnMap))
    {
    case SS_TIDAL_LOCATION_SLATEPORT:
        gRegionMap->mapSecId = MAPSEC_SLATEPORT_CITY;
        break;
    case SS_TIDAL_LOCATION_LILYCOVE:
        gRegionMap->mapSecId = MAPSEC_LILYCOVE_CITY;
        break;
    case SS_TIDAL_LOCATION_ROUTE124:
        gRegionMap->mapSecId = MAPSEC_ROUTE_124;
        break;
    case SS_TIDAL_LOCATION_ROUTE131:
        gRegionMap->mapSecId = MAPSEC_ROUTE_131;
        break;
    default:
    case SS_TIDAL_LOCATION_CURRENTS:
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);

        gRegionMap->mapSecId = mapHeader->regionMapSectionId;
        dimensionScale = mapHeader->mapLayout->width / gRegionMapEntries[gRegionMap->mapSecId].width;
        if (dimensionScale == 0)
            dimensionScale = 1;
        x = xOnMap / dimensionScale;
        if (x >= gRegionMapEntries[gRegionMap->mapSecId].width)
            x = gRegionMapEntries[gRegionMap->mapSecId].width - 1;

        dimensionScale = mapHeader->mapLayout->height / gRegionMapEntries[gRegionMap->mapSecId].height;
        if (dimensionScale == 0)
            dimensionScale = 1;
        y = yOnMap / dimensionScale;
        if (y >= gRegionMapEntries[gRegionMap->mapSecId].height)
            y = gRegionMapEntries[gRegionMap->mapSecId].height - 1;
        break;
    }
    gRegionMap->playerIsInCave = FALSE;
    gRegionMap->cursorPosX = gRegionMapEntries[gRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    gRegionMap->cursorPosY = gRegionMapEntries[gRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static u8 GetMapsecType(u16 mapSecId)
{
    switch (mapSecId)
    {
    case MAPSEC_NONE:
        return MAPSECTYPE_NONE;
    case MAPSEC_LITTLEROOT_TOWN:
        return FlagGet(FLAG_VISITED_LITTLEROOT_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_OLDALE_TOWN:
        return FlagGet(FLAG_VISITED_OLDALE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_DEWFORD_TOWN:
        return FlagGet(FLAG_VISITED_DEWFORD_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_LAVARIDGE_TOWN:
        return FlagGet(FLAG_VISITED_LAVARIDGE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FALLARBOR_TOWN:
        return FlagGet(FLAG_VISITED_FALLARBOR_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_VERDANTURF_TOWN:
        return FlagGet(FLAG_VISITED_VERDANTURF_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_PACIFIDLOG_TOWN:
        return FlagGet(FLAG_VISITED_PACIFIDLOG_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_PETALBURG_CITY:
        return FlagGet(FLAG_VISITED_PETALBURG_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SLATEPORT_CITY:
        return FlagGet(FLAG_VISITED_SLATEPORT_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_MAUVILLE_CITY:
        return FlagGet(FLAG_VISITED_MAUVILLE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_RUSTBORO_CITY:
        return FlagGet(FLAG_VISITED_RUSTBORO_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FORTREE_CITY:
        return FlagGet(FLAG_VISITED_FORTREE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_LILYCOVE_CITY:
        return FlagGet(FLAG_VISITED_LILYCOVE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_MOSSDEEP_CITY:
        return FlagGet(FLAG_VISITED_MOSSDEEP_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SOOTOPOLIS_CITY:
        return FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_EVER_GRANDE_CITY:
        return FlagGet(FLAG_VISITED_EVER_GRANDE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_BATTLE_FRONTIER:
        return FlagGet(FLAG_LANDMARK_BATTLE_FRONTIER) ? MAPSECTYPE_BATTLE_FRONTIER : MAPSECTYPE_NONE;
    case MAPSEC_SOUTHERN_ISLAND:
        return FlagGet(FLAG_LANDMARK_SOUTHERN_ISLAND) ? MAPSECTYPE_ROUTE : MAPSECTYPE_NONE;
    default:
        return MAPSECTYPE_ROUTE;
    }
}

u16 GetRegionMapSecIdAt(u16 x, u16 y)
{
    return GetMapSecIdAt(x, y);
}

static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMarineCaveMapSecIds); i++)
    {
        if (sMarineCaveMapSecIds[i] == mapSecId)
        {
            return GetTerraOrMarineCaveMapSecId();
        }
    }
    for (i = 0; sRegionMap_SpecialPlaceLocations[i][0] != MAPSEC_NONE; i++)
    {
        if (sRegionMap_SpecialPlaceLocations[i][0] == mapSecId)
        {
            return sRegionMap_SpecialPlaceLocations[i][1];
        }
    }
    return mapSecId;
}

static u16 GetTerraOrMarineCaveMapSecId(void)
{
    s16 idx;

    idx = VarGet(VAR_ABNORMAL_WEATHER_LOCATION) - 1;

    if (idx < 0 || idx > ABNORMAL_WEATHER_LOCATIONS - 1)
        idx = 0;

    return sTerraOrMarineCaveMapSecIds[idx];
}

static void GetMarineCaveCoords(u16 *x, u16 *y)
{
    u16 idx;

    idx = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);
    if (idx < MARINE_CAVE_LOCATIONS_START || idx > ABNORMAL_WEATHER_LOCATIONS)
    {
        idx = MARINE_CAVE_LOCATIONS_START;
    }
    idx -= MARINE_CAVE_LOCATIONS_START;

    *x = sMarineCaveLocationCoords[idx].x + MAPCURSOR_X_MIN;
    *y = sMarineCaveLocationCoords[idx].y + MAPCURSOR_Y_MIN;
}

// Probably meant to be an "IsPlayerInIndoorDungeon" function, but in practice it only has the one mapsec
// Additionally, because the mapsec doesnt exist in Emerald, this function always returns FALSE
static bool32 IsPlayerInAquaHideout(u8 mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMapSecAquaHideoutOld); i++)
    {
        if (sMapSecAquaHideoutOld[i] == mapSecId)
            return TRUE;
    }
    return FALSE;
}

u16 CorrectSpecialMapSecId(u16 mapSecId)
{
    return CorrectSpecialMapSecId_Internal(mapSecId);
}

static void GetPositionOfCursorWithinMapSec(void)
{
    u16 x;
    u16 y;
    u16 posWithinMapSec;

    if (gRegionMap->mapSecId == MAPSEC_NONE)
    {
        gRegionMap->posWithinMapSec = 0;
        return;
    }
    if (!gRegionMap->zoomed)
    {
        x = gRegionMap->cursorPosX;
        y = gRegionMap->cursorPosY;
    }
    else
    {
        x = gRegionMap->zoomedCursorPosX;
        y = gRegionMap->zoomedCursorPosY;
    }
    posWithinMapSec = 0;
    while (1)
    {
        if (x <= MAPCURSOR_X_MIN)
        {
            if (RegionMap_IsMapSecIdInNextRow(y))
            {
                y--;
                x = MAPCURSOR_X_MAX + 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            x--;
            if (GetMapSecIdAt(x, y) == gRegionMap->mapSecId)
            {
                posWithinMapSec++;
            }
        }
    }
    gRegionMap->posWithinMapSec = posWithinMapSec;
}

static bool8 RegionMap_IsMapSecIdInNextRow(u16 y)
{
    u16 x;

    if (y-- == 0)
    {
        return FALSE;
    }
    for (x = MAPCURSOR_X_MIN; x <= MAPCURSOR_X_MAX; x++)
    {
        if (GetMapSecIdAt(x, y) == gRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void SpriteCB_CursorMapFull(struct Sprite *sprite)
{
    if (gRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->pos1.x += 2 * gRegionMap->cursorDeltaX;
        sprite->pos1.y += 2 * gRegionMap->cursorDeltaY;
        gRegionMap->cursorMovementFrameCounter--;
    }
}

static void SpriteCB_CursorMapZoomed(struct Sprite *sprite)
{

}

void CreateRegionMapCursor(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteTemplate template;
    struct SpritePalette palette;
    struct SpriteSheet sheet;

    palette = sRegionMapCursorSpritePalette;
    template = sRegionMapCursorSpriteTemplate;
    sheet.tag = tileTag;
    template.tileTag = tileTag;
    gRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    gRegionMap->cursorPaletteTag = paletteTag;
    if (!gRegionMap->zoomed)
    {
        sheet.data = gRegionMap->cursorSmallImage;
        sheet.size = sizeof(gRegionMap->cursorSmallImage);
        template.callback = SpriteCB_CursorMapFull;
    }
    else
    {
        sheet.data = gRegionMap->cursorLargeImage;
        sheet.size = sizeof(gRegionMap->cursorLargeImage);
        template.callback = SpriteCB_CursorMapZoomed;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0x38, 0x48, 0);
    if (spriteId != MAX_SPRITES)
    {
        gRegionMap->cursorSprite = &gSprites[spriteId];
        if (gRegionMap->zoomed == TRUE)
        {
            gRegionMap->cursorSprite->oam.size = SPRITE_SIZE(32x32);
            gRegionMap->cursorSprite->pos1.x -= 8;
            gRegionMap->cursorSprite->pos1.y -= 8;
            StartSpriteAnim(gRegionMap->cursorSprite, 1);
        }
        else
        {
            gRegionMap->cursorSprite->oam.size = SPRITE_SIZE(16x16);
            gRegionMap->cursorSprite->pos1.x = 8 * gRegionMap->cursorPosX + 4;
            gRegionMap->cursorSprite->pos1.y = 8 * gRegionMap->cursorPosY + 4;
        }
        gRegionMap->cursorSprite->data[1] = 2;
        gRegionMap->cursorSprite->data[2] = (IndexOfSpritePaletteTag(paletteTag) << 4) + 0x101;
        gRegionMap->cursorSprite->data[3] = TRUE;
    }
}

static void FreeRegionMapCursorSprite(void)
{
    if (gRegionMap->cursorSprite != NULL)
    {
        DestroySprite(gRegionMap->cursorSprite);
        FreeSpriteTilesByTag(gRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(gRegionMap->cursorPaletteTag);
    }
}

// Unused
static void SetUnkCursorSpriteData(void)
{
    gRegionMap->cursorSprite->data[3] = TRUE;
}

// Unused
static void ClearUnkCursorSpriteData(void)
{
    gRegionMap->cursorSprite->data[3] = FALSE;
}

void CreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteSheet sheet = {sRegionMapPlayerIcon_BrendanGfx, 0x80, tileTag};
    struct SpritePalette palette = {sRegionMapPlayerIcon_BrendanPal, paletteTag};
    struct SpriteTemplate template = {tileTag, paletteTag, &sRegionMapPlayerIconOam, sRegionMapPlayerIconAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy};

    if (IsEventIslandMapSecId(gMapHeader.regionMapSectionId))
    {
        gRegionMap->playerIconSprite = NULL;
        return;
    }
    if (gSaveBlock2Ptr->playerGender == FEMALE)
    {
        sheet.data = sRegionMapPlayerIcon_MayGfx;
        palette.data = sRegionMapPlayerIcon_MayPal;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0, 0, 1);
    gRegionMap->playerIconSprite = &gSprites[spriteId];
    if (!gRegionMap->zoomed)
    {
        gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 8 + 4;
        gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 8 + 4;
        gRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
    }
    else
    {
        gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 16 - 0x30;
        gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 16 - 0x42;
        gRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
    }
}

static void HideRegionMapPlayerIcon(void)
{
    if (gRegionMap->playerIconSprite != NULL)
    {
        gRegionMap->playerIconSprite->invisible = TRUE;
        gRegionMap->playerIconSprite->callback = SpriteCallbackDummy;
    }
}

static void UnhideRegionMapPlayerIcon(void)
{
    if (gRegionMap->playerIconSprite != NULL)
    {
        if (gRegionMap->zoomed == TRUE)
        {
            gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 16 - 0x30;
            gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 16 - 0x42;
            gRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
            gRegionMap->playerIconSprite->invisible = FALSE;
        }
        else
        {
            gRegionMap->playerIconSprite->pos1.x = gRegionMap->playerIconSpritePosX * 8 + 4;
            gRegionMap->playerIconSprite->pos1.y = gRegionMap->playerIconSpritePosY * 8 + 4;
            gRegionMap->playerIconSprite->pos2.x = 0;
            gRegionMap->playerIconSprite->pos2.y = 0;
            gRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
            gRegionMap->playerIconSprite->invisible = FALSE;
        }
    }
}

static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite)
{
    sprite->pos2.x = -2 * gRegionMap->scrollX;
    sprite->pos2.y = -2 * gRegionMap->scrollY;
    sprite->data[0] = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    sprite->data[1] = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
    if (sprite->data[0] < -8 || sprite->data[0] > 0xa8 || sprite->data[1] < -8 || sprite->data[1] > 0xf8)
    {
        sprite->data[2] = FALSE;
    }
    else
    {
        sprite->data[2] = TRUE;
    }
    if (sprite->data[2] == TRUE)
    {
        SpriteCB_PlayerIcon(sprite);
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite)
{
    SpriteCB_PlayerIcon(sprite);
}

static void SpriteCB_PlayerIcon(struct Sprite *sprite)
{
    if (gRegionMap->blinkPlayerIcon)
    {
        if (++sprite->data[7] > 16)
        {
            sprite->data[7] = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void TrySetPlayerIconBlink(void)
{
    if (gRegionMap->playerIsInCave)
        gRegionMap->blinkPlayerIcon = TRUE;
}

u8 *GetMapName(u8 *dest, u16 regionMapId, u16 padLength)
{
    u8 *str;
    u16 i;

    if (regionMapId == MAPSEC_SECRET_BASE)
    {
        str = GetSecretBaseMapName(dest);
    }
    else if (regionMapId < MAPSEC_NONE)
    {
        str = StringCopy(dest, gRegionMapEntries[regionMapId].name);
    }
    else
    {
        if (padLength == 0)
        {
            padLength = 18;
        }
        return StringFill(dest, CHAR_SPACE, padLength);
    }
    if (padLength != 0)
    {
        for (i = str - dest; i < padLength; i++)
        {
            *str++ = CHAR_SPACE;
        }
        *str = EOS;
    }
    return str;
}

// TODO: probably needs a better name
u8 *GetMapNameGeneric(u8 *dest, u16 mapSecId)
{
    switch (mapSecId)
    {
    case MAPSEC_DYNAMIC:
        return StringCopy(dest, gText_Ferry);
    case MAPSEC_SECRET_BASE:
        return StringCopy(dest, gText_SecretBase);
    default:
        return GetMapName(dest, mapSecId, 0);
    }
}

u8 *GetMapNameHandleAquaHideout(u8 *dest, u16 mapSecId)
{
    if (mapSecId == MAPSEC_AQUA_HIDEOUT_OLD)
        return StringCopy(dest, gText_Hideout);
    else
        return GetMapNameGeneric(dest, mapSecId);
}

static void GetMapSecDimensions(u16 mapSecId, u16 *x, u16 *y, u16 *width, u16 *height)
{
    *x = gRegionMapEntries[mapSecId].x;
    *y = gRegionMapEntries[mapSecId].y;
    *width = gRegionMapEntries[mapSecId].width;
    *height = gRegionMapEntries[mapSecId].height;
}

bool8 IsRegionMapZoomed(void)
{
    return gRegionMap->zoomed;
}

bool32 IsEventIslandMapSecId(u8 mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMapSecIdsOffMap); i++)
    {
        if (mapSecId == sMapSecIdsOffMap[i])
            return TRUE;
    }
    return FALSE;
}

void CB2_OpenFlyMap(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        sFlyMap = malloc(sizeof(*sFlyMap));
        if (sFlyMap == NULL)
        {
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        else
        {
            ResetPaletteFade();
            ResetSpriteData();
            FreeSpriteTileRanges();
            FreeAllSpritePalettes();
            gMain.state++;
        }
        break;
    case 1:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sFlyMapBgTemplates, ARRAY_COUNT(sFlyMapBgTemplates));
        gMain.state++;
        break;
    case 2:
        InitWindows(sFlyMapWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 3:
        LoadUserWindowBorderGfx(0, 0x65, 0xd0);
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 4:
        InitRegionMap(&sFlyMap->regionMap, FALSE);
        CreateRegionMapCursor(0, 0);
        CreateRegionMapPlayerIcon(1, 1);
        sFlyMap->mapSecId = sFlyMap->regionMap.mapSecId;
        StringFill(sFlyMap->nameBuffer, CHAR_SPACE, MAP_NAME_LENGTH);
        gUnknown_03001180 = TRUE;
        DrawFlyDestTextWindow();
        gMain.state++;
        break;
    case 5:
        LZ77UnCompVram(sRegionMapFrameGfxLZ, (u16 *)BG_CHAR_ADDR(3));
        gMain.state++;
        break;
    case 6:
        LZ77UnCompVram(sRegionMapFrameTilemapLZ, (u16 *)BG_SCREEN_ADDR(30));
        gMain.state++;
        break;
    case 7:
        LoadPalette(sRegionMapFramePal, 0x10, 0x20);
        PutWindowTilemap(2);
        FillWindowPixelBuffer(2, PIXEL_FILL(0));
        AddTextPrinterParameterized(2, 1, gText_FlyToWhere, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(0);
        gMain.state++;
        break;
    case 8:
        LoadFlyDestIcons();
        gMain.state++;
        break;
    case 9:
        BlendPalettes(-1, 16, 0);
        SetVBlankCallback(VBlankCB_FlyMap);
        gMain.state++;
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        SetFlyMapCallback(CB_FadeInFlyMap);
        SetMainCallback2(CB2_FlyMap);
        gMain.state++;
        break;
    }
}

static void VBlankCB_FlyMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_FlyMap(void)
{
    sFlyMap->callback();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
}

static void SetFlyMapCallback(void callback(void))
{
    sFlyMap->callback = callback;
    sFlyMap->state = 0;
}

static void DrawFlyDestTextWindow(void)
{
    u16 i;
    bool32 namePrinted;
    const u8 *name;

    if (sFlyMap->regionMap.mapSecType > MAPSECTYPE_NONE && sFlyMap->regionMap.mapSecType <= MAPSECTYPE_BATTLE_FRONTIER)
    {
        namePrinted = FALSE;
        for (i = 0; i < ARRAY_COUNT(sMultiNameFlyDestinations); i++)
        {
            if (sFlyMap->regionMap.mapSecId == sMultiNameFlyDestinations[i].mapSecId)
            {
                if (FlagGet(sMultiNameFlyDestinations[i].flag))
                {
                    StringLength(sMultiNameFlyDestinations[i].name[sFlyMap->regionMap.posWithinMapSec]);
                    namePrinted = TRUE;
                    ClearStdWindowAndFrameToTransparent(0, FALSE);
                    DrawStdFrameWithCustomTileAndPalette(1, FALSE, 101, 13);
                    AddTextPrinterParameterized(1, 1, sFlyMap->regionMap.mapSecName, 0, 1, 0, NULL);
                    name = sMultiNameFlyDestinations[i].name[sFlyMap->regionMap.posWithinMapSec];
                    AddTextPrinterParameterized(1, 1, name, GetStringRightAlignXOffset(1, name, 96), 17, 0, NULL);
                    ScheduleBgCopyTilemapToVram(0);
                    gUnknown_03001180 = TRUE;
                }
                break;
            }
        }
        if (!namePrinted)
        {
            if (gUnknown_03001180 == TRUE)
            {
                ClearStdWindowAndFrameToTransparent(1, FALSE);
                DrawStdFrameWithCustomTileAndPalette(0, FALSE, 101, 13);
            }
            else
            {
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
            }
            AddTextPrinterParameterized(0, 1, sFlyMap->regionMap.mapSecName, 0, 1, 0, NULL);
            ScheduleBgCopyTilemapToVram(0);
            gUnknown_03001180 = FALSE;
        }
    }
    else
    {
        if (gUnknown_03001180 == TRUE)
        {
            ClearStdWindowAndFrameToTransparent(1, FALSE);
            DrawStdFrameWithCustomTileAndPalette(0, FALSE, 101, 13);
        }
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        CopyWindowToVram(0, 2);
        ScheduleBgCopyTilemapToVram(0);
        gUnknown_03001180 = FALSE;
    }
}


static void LoadFlyDestIcons(void)
{
    struct SpriteSheet sheet;

    LZ77UnCompWram(sFlyTargetIcons_Gfx, sFlyMap->tileBuffer);
    sheet.data = sFlyMap->tileBuffer;
    sheet.size = sizeof(sFlyMap->tileBuffer);
    sheet.tag = 2;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sFlyTargetIconsSpritePalette);
    CreateFlyDestIcons();
    TryCreateRedOutlineFlyDestIcons();
}

// Sprite data for SpriteCB_FlyDestIcon
#define sIconMapSec   data[0]
#define sFlickerTimer data[1]

static void CreateFlyDestIcons(void)
{
    u16 canFlyFlag;
    u16 mapSecId;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 shape;
    u8 spriteId;

    canFlyFlag = FLAG_VISITED_LITTLEROOT_TOWN;
    for (mapSecId = MAPSEC_LITTLEROOT_TOWN; mapSecId <= MAPSEC_EVER_GRANDE_CITY; mapSecId++)
    {
        GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
        x = (x + MAPCURSOR_X_MIN) * 8 + 4;
        y = (y + MAPCURSOR_Y_MIN) * 8 + 4;

        if (width == 2)
            shape = SPRITE_SHAPE(16x8);
        else if (height == 2)
            shape = SPRITE_SHAPE(8x16);
        else
            shape = SPRITE_SHAPE(8x8);

        spriteId = CreateSprite(&sFlyDestIconSpriteTemplate, x, y, 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.shape = shape;

            if (FlagGet(canFlyFlag))
                gSprites[spriteId].callback = SpriteCB_FlyDestIcon;
            else
                shape += 3;

            StartSpriteAnim(&gSprites[spriteId], shape);
            gSprites[spriteId].sIconMapSec = mapSecId;
        }
        canFlyFlag++;
    }
}

// Draw a red outline box on the mapsec if its corresponding flag has been set
// Only used for Battle Frontier, but set up to handle more
static void TryCreateRedOutlineFlyDestIcons(void)
{
    u16 i;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 mapSecId;
    u8 spriteId;

    for (i = 0; sRedOutlineFlyDestinations[i][1] != MAPSEC_NONE; i++)
    {
        if (FlagGet(sRedOutlineFlyDestinations[i][0]))
        {
            mapSecId = sRedOutlineFlyDestinations[i][1];
            GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
            x = (x + MAPCURSOR_X_MIN) * 8;
            y = (y + MAPCURSOR_Y_MIN) * 8;
            spriteId = CreateSprite(&sFlyDestIconSpriteTemplate, x, y, 10);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
                gSprites[spriteId].callback = SpriteCB_FlyDestIcon;
                StartSpriteAnim(&gSprites[spriteId], FLYDESTICON_RED_OUTLINE);
                gSprites[spriteId].sIconMapSec = mapSecId;
            }
        }
    }
}

// Flickers fly destination icon color (by hiding the fly icon sprite) if the cursor is currently on it
static void SpriteCB_FlyDestIcon(struct Sprite *sprite)
{
    if (sFlyMap->regionMap.mapSecId == sprite->sIconMapSec)
    {
        if (++sprite->sFlickerTimer > 16)
        {
            sprite->sFlickerTimer = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->sFlickerTimer = 16;
        sprite->invisible = FALSE;
    }
}

#undef sIconMapSec
#undef sFlickerTimer

static void CB_FadeInFlyMap(void)
{
    switch (sFlyMap->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        sFlyMap->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            SetFlyMapCallback(CB_HandleFlyMapInput);
        }
        break;
    }
}

static void CB_HandleFlyMapInput(void)
{
    if (sFlyMap->state == 0)
    {
        switch (DoRegionMapInputCallback())
        {
        case MAP_INPUT_NONE:
        case MAP_INPUT_MOVE_START:
        case MAP_INPUT_MOVE_CONT:
            break;
        case MAP_INPUT_MOVE_END:
            DrawFlyDestTextWindow();
            break;
        case MAP_INPUT_A_BUTTON:
            if (sFlyMap->regionMap.mapSecType == MAPSECTYPE_CITY_CANFLY || sFlyMap->regionMap.mapSecType == MAPSECTYPE_BATTLE_FRONTIER)
            {
                m4aSongNumStart(SE_SELECT);
                sFlyMap->choseFlyLocation = TRUE;
                SetFlyMapCallback(CB_ExitFlyMap);
            }
            break;
        case MAP_INPUT_B_BUTTON:
            m4aSongNumStart(SE_SELECT);
            sFlyMap->choseFlyLocation = FALSE;
            SetFlyMapCallback(CB_ExitFlyMap);
            break;
        }
    }
}

static void CB_ExitFlyMap(void)
{
    switch (sFlyMap->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sFlyMap->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            FreeRegionMapIconResources();
            if (sFlyMap->choseFlyLocation)
            {
                switch (sFlyMap->regionMap.mapSecId)
                {
                case MAPSEC_SOUTHERN_ISLAND:
                    SetWarpDestinationToHealLocation(HEAL_LOCATION_SOUTHERN_ISLAND_EXTERIOR);
                    break;
                case MAPSEC_BATTLE_FRONTIER:
                    SetWarpDestinationToHealLocation(HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST);
                    break;
                case MAPSEC_LITTLEROOT_TOWN:
                    SetWarpDestinationToHealLocation(gSaveBlock2Ptr->playerGender == MALE ? HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE : HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE);
                    break;
                case MAPSEC_EVER_GRANDE_CITY:
                    SetWarpDestinationToHealLocation(FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) && sFlyMap->regionMap.posWithinMapSec == 0 ? HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE : HEAL_LOCATION_EVER_GRANDE_CITY);
                    break;
                default:
                    if (sMapHealLocations[sFlyMap->regionMap.mapSecId][2] != 0)
                        SetWarpDestinationToHealLocation(sMapHealLocations[sFlyMap->regionMap.mapSecId][2]);
                    else
                        SetWarpDestinationToMapWarp(sMapHealLocations[sFlyMap->regionMap.mapSecId][0], sMapHealLocations[sFlyMap->regionMap.mapSecId][1], -1);
                    break;
                }
                ReturnToFieldFromFlyMapSelect();
            }
            else
            {
                SetMainCallback2(CB2_ReturnToPartyMenuFromFlyMap);
            }
            if (sFlyMap != NULL)
            {
                free(sFlyMap);
                sFlyMap = NULL;
            }
            FreeAllWindowBuffers();
        }
        break;
    }
}

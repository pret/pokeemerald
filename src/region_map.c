#include "global.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "party_menu.h"
#include "trig.h"
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
#include "regions.h"
#include "region_map.h"
#include "decompress.h"
#include "constants/region_map_sections.h"
#include "heal_location.h"
#include "constants/field_specials.h"
#include "constants/heal_locations.h"
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

enum {
    TAG_CURSOR,
    TAG_PLAYER_ICON,
    TAG_FLY_ICON,
};

// Window IDs for the fly map
enum {
    WIN_MAPSEC_NAME,
    WIN_MAPSEC_NAME_TALL, // For fly destinations with subtitles (just Ever Grande)
    WIN_FLY_TO_WHERE,
};

struct MultiNameFlyDest
{
    const u8 *const *name;
    mapsec_u16_t mapSecId;
    u16 flag;
};

static EWRAM_DATA struct RegionMap *sRegionMap = NULL;

static EWRAM_DATA struct {
    void (*callback)(void);
    u16 state;
    mapsec_u16_t mapSecId;
    struct RegionMap regionMap;
    u8 tileBuffer[0x1c0];
    u8 nameBuffer[0x26]; // never read
    bool8 choseFlyLocation;
} *sFlyMap = NULL;

static bool32 sDrawFlyDestTextWindow;

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
static mapsec_u16_t GetMapSecIdAt(u16 x, u16 y);
static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y);
static void InitMapBasedOnPlayerLocation(void);
static void RegionMap_InitializeStateBasedOnSSTidalLocation(void);
static u8 GetMapsecType(mapsec_u16_t mapSecId);
static mapsec_u16_t CorrectSpecialMapSecId_Internal(mapsec_u16_t mapSecId);
static mapsec_u16_t GetTerraOrMarineCaveMapSecId(void);
static void GetMarineCaveCoords(u16 *x, u16 *y);
static bool32 IsPlayerInAquaHideout(mapsec_u8_t mapSecId);
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

static const u16 sRegionMapCursorPal[] = INCGFX_U16("graphics/pokenav/region_map/cursor.pal", ".gbapal");
static const u32 sRegionMapCursorSmallGfxLZ[] = INCGFX_U32("graphics/pokenav/region_map/cursor_small.png", ".4bpp.smol");
static const u32 sRegionMapCursorLargeGfxLZ[] = INCGFX_U32("graphics/pokenav/region_map/cursor_large.png", ".4bpp.smol");
static const u16 sRegionMapBg_Pal[] = INCGFX_U16("graphics/pokenav/region_map/map.pal", ".gbapal");
static const u32 sRegionMapBg_GfxLZ[] = INCGFX_U32("graphics/pokenav/region_map/map.png", ".8bpp.smol", "-num_tiles 233 -Wnum_tiles");
static const u32 sRegionMapBg_TilemapLZ[] = INCGFX_U32("graphics/pokenav/region_map/map.bin", ".smolTM");
static const u16 sRegionMapPlayerIcon_BrendanPal[] = INCGFX_U16("graphics/pokenav/region_map/brendan_icon.png", ".gbapal");
static const u8 sRegionMapPlayerIcon_BrendanGfx[] = INCGFX_U8("graphics/pokenav/region_map/brendan_icon.png", ".4bpp");
static const u16 sRegionMapPlayerIcon_MayPal[] = INCGFX_U16("graphics/pokenav/region_map/may_icon.png", ".gbapal");
static const u8 sRegionMapPlayerIcon_MayGfx[] = INCGFX_U8("graphics/pokenav/region_map/may_icon.png", ".4bpp");
static const u16 sRegionMapPlayerIcon_RedPal[] = INCGFX_U16("graphics/pokenav/region_map/red_icon.pal", ".gbapal");
static const u8 sRegionMapPlayerIcon_RedGfx[] = INCGFX_U8("graphics/pokenav/region_map/red_icon.png", ".4bpp");
static const u16 sRegionMapPlayerIcon_LeafPal[] = INCGFX_U16("graphics/pokenav/region_map/leaf_icon.pal", ".gbapal");
static const u8 sRegionMapPlayerIcon_LeafGfx[] = INCGFX_U8("graphics/pokenav/region_map/leaf_icon.png", ".4bpp");

#include "data/region_map/region_map_layout.h"
#include "data/region_map/region_map_layout_kanto.h"
#include "data/region_map/region_map_layout_sevii123.h"
#include "data/region_map/region_map_layout_sevii45.h"
#include "data/region_map/region_map_layout_sevii67.h"
#include "data/region_map/region_map_entries.h"

static const mapsec_u16_t sRegionMap_SpecialPlaceLocations[][2] =
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

static const mapsec_u16_t sMarineCaveMapSecIds[] =
{
    MAPSEC_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE
};

static const mapsec_u16_t sTerraOrMarineCaveMapSecIds[ABNORMAL_WEATHER_LOCATIONS] =
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

#define MARINE_CAVE_COORD(location) (ABNORMAL_WEATHER_##location - MARINE_CAVE_LOCATIONS_START)

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

static const mapsec_u8_t sMapSecAquaHideoutOld[] =
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
    .tag = TAG_CURSOR
};

static const struct SpriteTemplate sRegionMapCursorSpriteTemplate =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sRegionMapCursorOam,
    .anims = sRegionMapCursorAnimTable,
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
static const mapsec_u8_t sMapSecIdsOffMap[] =
{
    MAPSEC_BIRTH_ISLAND,
    MAPSEC_FARAWAY_ISLAND,
    MAPSEC_NAVEL_ROCK
};

static const u16 sRegionMapFramePal[] = INCGFX_U16("graphics/pokenav/region_map/frame.png", ".gbapal");
static const u32 sRegionMapFrameGfxLZ[] = INCGFX_U32("graphics/pokenav/region_map/frame.png", ".4bpp.smol");
static const u32 sRegionMapFrameTilemapLZ[] = INCGFX_U32("graphics/pokenav/region_map/frame.bin", ".smolTM");
static const u16 sFlyTargetIcons_Pal[] = INCGFX_U16("graphics/pokenav/region_map/fly_target_icons.png", ".gbapal");
static const u32 sFlyTargetIcons_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/fly_target_icons.png", ".4bpp.smol");

static const u16 ALIGNED(4) sPokedexAreaMap_Pal[] = INCGFX_U16("graphics/pokedex/region_map.pal", ".gbapal");
static const u32 sPokedexAreaMap_Gfx[] = INCGFX_U32("graphics/pokedex/region_map.png", ".8bpp.smol", "-num_tiles 232 -Wnum_tiles");
static const u32 sPokedexAreaMap_Tilemap[] = INCGFX_U32("graphics/pokedex/region_map.bin", ".smolTM");

static const u16 ALIGNED(4) sPokedexAreaMapKanto_Pal[] = INCGFX_U16("graphics/pokedex/region_map_kanto.pal", ".gbapal");
static const u32 sPokedexAreaMapKanto_Gfx[] = INCGFX_U32("graphics/pokedex/region_map_kanto.png", ".8bpp.smol");
static const u32 sPokedexAreaMapKanto_Tilemap[] = INCGFX_U32("graphics/pokedex/region_map_kanto.bin", ".smolTM");
static const u16 ALIGNED(4) sRegionMapKanto_Pal[] = INCGFX_U16("graphics/pokenav/region_map/map_kanto.pal", ".gbapal");
static const u32 sRegionMapKanto_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/map_kanto.png", ".8bpp.smol");
static const u32 sRegionMapKanto_Tilemap[] = INCGFX_U32("graphics/pokenav/region_map/map_kanto.bin", ".smolTM");

static const u16 ALIGNED(4) sPokedexAreaMapSevii123_Pal[] = INCGFX_U16("graphics/pokedex/region_map_sevii123.pal", ".gbapal");
static const u32 sPokedexAreaMapSevii123_Gfx[] = INCGFX_U32("graphics/pokedex/region_map_sevii123.png", ".8bpp.smol");
static const u32 sPokedexAreaMapSevii123_Tilemap[] = INCGFX_U32("graphics/pokedex/region_map_sevii123.bin", ".smolTM");
static const u16 ALIGNED(4) sRegionMapSevii123_Pal[] = INCGFX_U16("graphics/pokenav/region_map/map_sevii_123.pal", ".gbapal");
static const u32 sRegionMapSevii123_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_123.png", ".8bpp.smol");
static const u32 sRegionMapSevii123_Tilemap[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_123.bin", ".smolTM");

static const u16 ALIGNED(4) sPokedexAreaMapSevii45_Pal[] = INCGFX_U16("graphics/pokedex/region_map_sevii45.pal", ".gbapal");
static const u32 sPokedexAreaMapSevii45_Gfx[] = INCGFX_U32("graphics/pokedex/region_map_sevii45.png", ".8bpp.smol");
static const u32 sPokedexAreaMapSevii45_Tilemap[] = INCGFX_U32("graphics/pokedex/region_map_sevii45.bin", ".smolTM");
static const u16 ALIGNED(4) sRegionMapSevii45_Pal[] = INCGFX_U16("graphics/pokenav/region_map/map_sevii_45.pal", ".gbapal");
static const u32 sRegionMapSevii45_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_45.png", ".8bpp.smol");
static const u32 sRegionMapSevii45_Tilemap[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_45.bin", ".smolTM");

static const u16 ALIGNED(4) sPokedexAreaMapSevii67_Pal[] = INCGFX_U16("graphics/pokedex/region_map_sevii67.pal", ".gbapal");
static const u32 sPokedexAreaMapSevii67_Gfx[] = INCGFX_U32("graphics/pokedex/region_map_sevii67.png", ".8bpp.smol");
static const u32 sPokedexAreaMapSevii67_Tilemap[] = INCGFX_U32("graphics/pokedex/region_map_sevii67.bin", ".smolTM");
static const u16 ALIGNED(4) sRegionMapSevii67_Pal[] = INCGFX_U16("graphics/pokenav/region_map/map_sevii_67.pal", ".gbapal");
static const u32 sRegionMapSevii67_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_67.png", ".8bpp.smol");
static const u32 sRegionMapSevii67_Tilemap[] = INCGFX_U32("graphics/pokenav/region_map/map_sevii_67.bin", ".smolTM");

const struct RegionMapInfo gRegionMapInfos[] =
{
    [REGION_MAP_HOENN]    =
    {
        .dexMapPalette = sPokedexAreaMap_Pal,
        .dexMapGfx = sPokedexAreaMap_Gfx,
        .dexMapTilemap = sPokedexAreaMap_Tilemap,
        .dexMapPaletteSize = sizeof(sPokedexAreaMap_Pal),
        .regionMapPalette = sRegionMapBg_Pal,
        .regionMapGfx = sRegionMapBg_GfxLZ,
        .regionMapTilemap = sRegionMapBg_TilemapLZ,
    },
    [REGION_MAP_KANTO]    =
    {
        .dexMapPalette = sPokedexAreaMapKanto_Pal,
        .dexMapGfx = sPokedexAreaMapKanto_Gfx,
        .dexMapTilemap = sPokedexAreaMapKanto_Tilemap,
        .dexMapPaletteSize = sizeof(sPokedexAreaMapKanto_Pal),
        .regionMapPalette = sRegionMapKanto_Pal,
        .regionMapGfx = sRegionMapKanto_Gfx,
        .regionMapTilemap = sRegionMapKanto_Tilemap,
    },
    [REGION_MAP_SEVII123] =
    {
        .dexMapPalette = sPokedexAreaMapSevii123_Pal,
        .dexMapGfx = sPokedexAreaMapSevii123_Gfx,
        .dexMapTilemap = sPokedexAreaMapSevii123_Tilemap,
        .dexMapPaletteSize = sizeof(sPokedexAreaMapSevii123_Pal),
        .regionMapPalette = sRegionMapSevii123_Pal,
        .regionMapGfx = sRegionMapSevii123_Gfx,
        .regionMapTilemap = sRegionMapSevii123_Tilemap,
    },
    [REGION_MAP_SEVII45]  =
    {
        .dexMapPalette = sPokedexAreaMapSevii45_Pal,
        .dexMapGfx = sPokedexAreaMapSevii45_Gfx,
        .dexMapTilemap = sPokedexAreaMapSevii45_Tilemap,
        .dexMapPaletteSize = sizeof(sPokedexAreaMapSevii45_Pal),
        .regionMapPalette = sRegionMapSevii45_Pal,
        .regionMapGfx = sRegionMapSevii45_Gfx,
        .regionMapTilemap = sRegionMapSevii45_Tilemap,
    },
    [REGION_MAP_SEVII67]  =
    {
        .dexMapPalette = sPokedexAreaMapSevii67_Pal,
        .dexMapGfx = sPokedexAreaMapSevii67_Gfx,
        .dexMapTilemap = sPokedexAreaMapSevii67_Tilemap,
        .dexMapPaletteSize = sizeof(sPokedexAreaMapSevii67_Pal),
        .regionMapPalette = sRegionMapSevii67_Pal,
        .regionMapGfx = sRegionMapSevii67_Gfx,
        .regionMapTilemap = sRegionMapSevii67_Tilemap,
    },
};

static const u8 sMapHealLocations[][3] =
{
    [MAPSEC_LITTLEROOT_TOWN] = {MAP_GROUP(MAP_LITTLEROOT_TOWN), MAP_NUM(MAP_LITTLEROOT_TOWN), HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F},
    [MAPSEC_OLDALE_TOWN] = {MAP_GROUP(MAP_OLDALE_TOWN), MAP_NUM(MAP_OLDALE_TOWN), HEAL_LOCATION_OLDALE_TOWN},
    [MAPSEC_DEWFORD_TOWN] = {MAP_GROUP(MAP_DEWFORD_TOWN), MAP_NUM(MAP_DEWFORD_TOWN), HEAL_LOCATION_DEWFORD_TOWN},
    [MAPSEC_LAVARIDGE_TOWN] = {MAP_GROUP(MAP_LAVARIDGE_TOWN), MAP_NUM(MAP_LAVARIDGE_TOWN), HEAL_LOCATION_LAVARIDGE_TOWN},
    [MAPSEC_FALLARBOR_TOWN] = {MAP_GROUP(MAP_FALLARBOR_TOWN), MAP_NUM(MAP_FALLARBOR_TOWN), HEAL_LOCATION_FALLARBOR_TOWN},
    [MAPSEC_VERDANTURF_TOWN] = {MAP_GROUP(MAP_VERDANTURF_TOWN), MAP_NUM(MAP_VERDANTURF_TOWN), HEAL_LOCATION_VERDANTURF_TOWN},
    [MAPSEC_PACIFIDLOG_TOWN] = {MAP_GROUP(MAP_PACIFIDLOG_TOWN), MAP_NUM(MAP_PACIFIDLOG_TOWN), HEAL_LOCATION_PACIFIDLOG_TOWN},
    [MAPSEC_PETALBURG_CITY] = {MAP_GROUP(MAP_PETALBURG_CITY), MAP_NUM(MAP_PETALBURG_CITY), HEAL_LOCATION_PETALBURG_CITY},
    [MAPSEC_SLATEPORT_CITY] = {MAP_GROUP(MAP_SLATEPORT_CITY), MAP_NUM(MAP_SLATEPORT_CITY), HEAL_LOCATION_SLATEPORT_CITY},
    [MAPSEC_MAUVILLE_CITY] = {MAP_GROUP(MAP_MAUVILLE_CITY), MAP_NUM(MAP_MAUVILLE_CITY), HEAL_LOCATION_MAUVILLE_CITY},
    [MAPSEC_RUSTBORO_CITY] = {MAP_GROUP(MAP_RUSTBORO_CITY), MAP_NUM(MAP_RUSTBORO_CITY), HEAL_LOCATION_RUSTBORO_CITY},
    [MAPSEC_FORTREE_CITY] = {MAP_GROUP(MAP_FORTREE_CITY), MAP_NUM(MAP_FORTREE_CITY), HEAL_LOCATION_FORTREE_CITY},
    [MAPSEC_LILYCOVE_CITY] = {MAP_GROUP(MAP_LILYCOVE_CITY), MAP_NUM(MAP_LILYCOVE_CITY), HEAL_LOCATION_LILYCOVE_CITY},
    [MAPSEC_MOSSDEEP_CITY] = {MAP_GROUP(MAP_MOSSDEEP_CITY), MAP_NUM(MAP_MOSSDEEP_CITY), HEAL_LOCATION_MOSSDEEP_CITY},
    [MAPSEC_SOOTOPOLIS_CITY] = {MAP_GROUP(MAP_SOOTOPOLIS_CITY), MAP_NUM(MAP_SOOTOPOLIS_CITY), HEAL_LOCATION_SOOTOPOLIS_CITY},
    [MAPSEC_EVER_GRANDE_CITY] = {MAP_GROUP(MAP_EVER_GRANDE_CITY), MAP_NUM(MAP_EVER_GRANDE_CITY), HEAL_LOCATION_EVER_GRANDE_CITY},
    [MAPSEC_ROUTE_101] = {MAP_GROUP(MAP_ROUTE101), MAP_NUM(MAP_ROUTE101), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_102] = {MAP_GROUP(MAP_ROUTE102), MAP_NUM(MAP_ROUTE102), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_103] = {MAP_GROUP(MAP_ROUTE103), MAP_NUM(MAP_ROUTE103), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_104] = {MAP_GROUP(MAP_ROUTE104), MAP_NUM(MAP_ROUTE104), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_105] = {MAP_GROUP(MAP_ROUTE105), MAP_NUM(MAP_ROUTE105), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_106] = {MAP_GROUP(MAP_ROUTE106), MAP_NUM(MAP_ROUTE106), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_107] = {MAP_GROUP(MAP_ROUTE107), MAP_NUM(MAP_ROUTE107), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_108] = {MAP_GROUP(MAP_ROUTE108), MAP_NUM(MAP_ROUTE108), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_109] = {MAP_GROUP(MAP_ROUTE109), MAP_NUM(MAP_ROUTE109), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_110] = {MAP_GROUP(MAP_ROUTE110), MAP_NUM(MAP_ROUTE110), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_111] = {MAP_GROUP(MAP_ROUTE111), MAP_NUM(MAP_ROUTE111), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_112] = {MAP_GROUP(MAP_ROUTE112), MAP_NUM(MAP_ROUTE112), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_113] = {MAP_GROUP(MAP_ROUTE113), MAP_NUM(MAP_ROUTE113), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_114] = {MAP_GROUP(MAP_ROUTE114), MAP_NUM(MAP_ROUTE114), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_115] = {MAP_GROUP(MAP_ROUTE115), MAP_NUM(MAP_ROUTE115), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_116] = {MAP_GROUP(MAP_ROUTE116), MAP_NUM(MAP_ROUTE116), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_117] = {MAP_GROUP(MAP_ROUTE117), MAP_NUM(MAP_ROUTE117), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_118] = {MAP_GROUP(MAP_ROUTE118), MAP_NUM(MAP_ROUTE118), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_119] = {MAP_GROUP(MAP_ROUTE119), MAP_NUM(MAP_ROUTE119), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_120] = {MAP_GROUP(MAP_ROUTE120), MAP_NUM(MAP_ROUTE120), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_121] = {MAP_GROUP(MAP_ROUTE121), MAP_NUM(MAP_ROUTE121), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_122] = {MAP_GROUP(MAP_ROUTE122), MAP_NUM(MAP_ROUTE122), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_123] = {MAP_GROUP(MAP_ROUTE123), MAP_NUM(MAP_ROUTE123), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_124] = {MAP_GROUP(MAP_ROUTE124), MAP_NUM(MAP_ROUTE124), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_125] = {MAP_GROUP(MAP_ROUTE125), MAP_NUM(MAP_ROUTE125), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_126] = {MAP_GROUP(MAP_ROUTE126), MAP_NUM(MAP_ROUTE126), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_127] = {MAP_GROUP(MAP_ROUTE127), MAP_NUM(MAP_ROUTE127), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_128] = {MAP_GROUP(MAP_ROUTE128), MAP_NUM(MAP_ROUTE128), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_129] = {MAP_GROUP(MAP_ROUTE129), MAP_NUM(MAP_ROUTE129), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_130] = {MAP_GROUP(MAP_ROUTE130), MAP_NUM(MAP_ROUTE130), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_131] = {MAP_GROUP(MAP_ROUTE131), MAP_NUM(MAP_ROUTE131), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_132] = {MAP_GROUP(MAP_ROUTE132), MAP_NUM(MAP_ROUTE132), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_133] = {MAP_GROUP(MAP_ROUTE133), MAP_NUM(MAP_ROUTE133), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_134] = {MAP_GROUP(MAP_ROUTE134), MAP_NUM(MAP_ROUTE134), HEAL_LOCATION_NONE},
    [MAPSEC_PALLET_TOWN] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_PALLET_TOWN},
    [MAPSEC_VIRIDIAN_CITY] = {MAP_GROUP(MAP_VIRIDIAN_CITY), MAP_NUM(MAP_VIRIDIAN_CITY), HEAL_LOCATION_VIRIDIAN_CITY},
    [MAPSEC_PEWTER_CITY] = {MAP_GROUP(MAP_PEWTER_CITY), MAP_NUM(MAP_PEWTER_CITY), HEAL_LOCATION_PEWTER_CITY},
    [MAPSEC_CERULEAN_CITY] = {MAP_GROUP(MAP_CERULEAN_CITY), MAP_NUM(MAP_CERULEAN_CITY), HEAL_LOCATION_CERULEAN_CITY},
    [MAPSEC_LAVENDER_TOWN] = {MAP_GROUP(MAP_LAVENDER_TOWN), MAP_NUM(MAP_LAVENDER_TOWN), HEAL_LOCATION_LAVENDER_TOWN},
    [MAPSEC_VERMILION_CITY] = {MAP_GROUP(MAP_VERMILION_CITY), MAP_NUM(MAP_VERMILION_CITY), HEAL_LOCATION_VERMILION_CITY},
    [MAPSEC_CELADON_CITY] = {MAP_GROUP(MAP_CELADON_CITY), MAP_NUM(MAP_CELADON_CITY), HEAL_LOCATION_CELADON_CITY},
    [MAPSEC_FUCHSIA_CITY] = {MAP_GROUP(MAP_FUCHSIA_CITY), MAP_NUM(MAP_FUCHSIA_CITY), HEAL_LOCATION_FUCHSIA_CITY},
    [MAPSEC_CINNABAR_ISLAND] = {MAP_GROUP(MAP_CINNABAR_ISLAND), MAP_NUM(MAP_CINNABAR_ISLAND), HEAL_LOCATION_CINNABAR_ISLAND},
    [MAPSEC_INDIGO_PLATEAU] = {MAP_GROUP(MAP_INDIGO_PLATEAU_EXTERIOR), MAP_NUM(MAP_INDIGO_PLATEAU_EXTERIOR), HEAL_LOCATION_INDIGO_PLATEAU},
    [MAPSEC_SAFFRON_CITY] = {MAP_GROUP(MAP_SAFFRON_CITY), MAP_NUM(MAP_SAFFRON_CITY), HEAL_LOCATION_SAFFRON_CITY},
    [MAPSEC_ROUTE_4_POKECENTER] = {MAP_GROUP(MAP_ROUTE4), MAP_NUM(MAP_ROUTE4), HEAL_LOCATION_ROUTE4},
    [MAPSEC_ROUTE_10_POKECENTER] = {MAP_GROUP(MAP_ROUTE10), MAP_NUM(MAP_ROUTE10), HEAL_LOCATION_ROUTE10},
    [MAPSEC_ROUTE_1] = {MAP_GROUP(MAP_ROUTE1), MAP_NUM(MAP_ROUTE1), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_2] = {MAP_GROUP(MAP_ROUTE2), MAP_NUM(MAP_ROUTE2), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_3] = {MAP_GROUP(MAP_ROUTE3), MAP_NUM(MAP_ROUTE3), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_4] = {MAP_GROUP(MAP_ROUTE4), MAP_NUM(MAP_ROUTE4), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_5] = {MAP_GROUP(MAP_ROUTE5), MAP_NUM(MAP_ROUTE5), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_6] = {MAP_GROUP(MAP_ROUTE6), MAP_NUM(MAP_ROUTE6), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_7] = {MAP_GROUP(MAP_ROUTE7), MAP_NUM(MAP_ROUTE7), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_8] = {MAP_GROUP(MAP_ROUTE8), MAP_NUM(MAP_ROUTE8), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_9] = {MAP_GROUP(MAP_ROUTE9), MAP_NUM(MAP_ROUTE9), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_10] = {MAP_GROUP(MAP_ROUTE10), MAP_NUM(MAP_ROUTE10), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_11] = {MAP_GROUP(MAP_ROUTE11), MAP_NUM(MAP_ROUTE11), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_12] = {MAP_GROUP(MAP_ROUTE12), MAP_NUM(MAP_ROUTE12), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_13] = {MAP_GROUP(MAP_ROUTE13), MAP_NUM(MAP_ROUTE13), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_14] = {MAP_GROUP(MAP_ROUTE14), MAP_NUM(MAP_ROUTE14), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_15] = {MAP_GROUP(MAP_ROUTE15), MAP_NUM(MAP_ROUTE15), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_16] = {MAP_GROUP(MAP_ROUTE16), MAP_NUM(MAP_ROUTE16), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_17] = {MAP_GROUP(MAP_ROUTE17), MAP_NUM(MAP_ROUTE17), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_18] = {MAP_GROUP(MAP_ROUTE18), MAP_NUM(MAP_ROUTE18), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_19] = {MAP_GROUP(MAP_ROUTE19), MAP_NUM(MAP_ROUTE19), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_20] = {MAP_GROUP(MAP_ROUTE20), MAP_NUM(MAP_ROUTE20), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_21] = {MAP_GROUP(MAP_ROUTE21_NORTH), MAP_NUM(MAP_ROUTE21_NORTH), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_22] = {MAP_GROUP(MAP_ROUTE22), MAP_NUM(MAP_ROUTE22), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_23] = {MAP_GROUP(MAP_ROUTE23), MAP_NUM(MAP_ROUTE23), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_24] = {MAP_GROUP(MAP_ROUTE24), MAP_NUM(MAP_ROUTE24), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_25] = {MAP_GROUP(MAP_ROUTE25), MAP_NUM(MAP_ROUTE25), HEAL_LOCATION_NONE},
    [MAPSEC_VIRIDIAN_FOREST] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_MT_MOON] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_S_S_ANNE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_UNDERGROUND_PATH] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_UNDERGROUND_PATH_2] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_DIGLETTS_CAVE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_KANTO_VICTORY_ROAD] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ROCKET_HIDEOUT] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_SILPH_CO] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_POKEMON_MANSION] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_KANTO_SAFARI_ZONE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_POKEMON_LEAGUE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ROCK_TUNNEL] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_SEAFOAM_ISLANDS] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_POKEMON_TOWER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_CERULEAN_CAVE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_POWER_PLANT] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ONE_ISLAND] = {MAP_GROUP(MAP_ONE_ISLAND), MAP_NUM(MAP_ONE_ISLAND), HEAL_LOCATION_ONE_ISLAND},
    [MAPSEC_TWO_ISLAND] = {MAP_GROUP(MAP_TWO_ISLAND), MAP_NUM(MAP_TWO_ISLAND), HEAL_LOCATION_TWO_ISLAND},
    [MAPSEC_THREE_ISLAND] = {MAP_GROUP(MAP_THREE_ISLAND), MAP_NUM(MAP_THREE_ISLAND), HEAL_LOCATION_THREE_ISLAND},
    [MAPSEC_FOUR_ISLAND] = {MAP_GROUP(MAP_FOUR_ISLAND), MAP_NUM(MAP_FOUR_ISLAND), HEAL_LOCATION_FOUR_ISLAND},
    [MAPSEC_FIVE_ISLAND] = {MAP_GROUP(MAP_FIVE_ISLAND), MAP_NUM(MAP_FIVE_ISLAND), HEAL_LOCATION_FIVE_ISLAND},
    [MAPSEC_SEVEN_ISLAND] = {MAP_GROUP(MAP_SEVEN_ISLAND), MAP_NUM(MAP_SEVEN_ISLAND), HEAL_LOCATION_SEVEN_ISLAND},
    [MAPSEC_SIX_ISLAND] = {MAP_GROUP(MAP_SIX_ISLAND), MAP_NUM(MAP_SIX_ISLAND), HEAL_LOCATION_SIX_ISLAND},
    [MAPSEC_KINDLE_ROAD] = {MAP_GROUP(MAP_ONE_ISLAND_KINDLE_ROAD), MAP_NUM(MAP_ONE_ISLAND_KINDLE_ROAD), HEAL_LOCATION_NONE},
    [MAPSEC_TREASURE_BEACH] = {MAP_GROUP(MAP_ONE_ISLAND_TREASURE_BEACH), MAP_NUM(MAP_ONE_ISLAND_TREASURE_BEACH), HEAL_LOCATION_NONE},
    [MAPSEC_CAPE_BRINK] = {MAP_GROUP(MAP_TWO_ISLAND_CAPE_BRINK), MAP_NUM(MAP_TWO_ISLAND_CAPE_BRINK), HEAL_LOCATION_NONE},
    [MAPSEC_BOND_BRIDGE] = {MAP_GROUP(MAP_THREE_ISLAND_BOND_BRIDGE), MAP_NUM(MAP_THREE_ISLAND_BOND_BRIDGE), HEAL_LOCATION_NONE},
    [MAPSEC_THREE_ISLE_PORT] = {MAP_GROUP(MAP_THREE_ISLAND_PORT), MAP_NUM(MAP_THREE_ISLAND_PORT), HEAL_LOCATION_NONE},
    [MAPSEC_RESORT_GORGEOUS] = {MAP_GROUP(MAP_FIVE_ISLAND_RESORT_GORGEOUS), MAP_NUM(MAP_FIVE_ISLAND_RESORT_GORGEOUS), HEAL_LOCATION_NONE},
    [MAPSEC_WATER_LABYRINTH] = {MAP_GROUP(MAP_FIVE_ISLAND_WATER_LABYRINTH), MAP_NUM(MAP_FIVE_ISLAND_WATER_LABYRINTH), HEAL_LOCATION_NONE},
    [MAPSEC_FIVE_ISLE_MEADOW] = {MAP_GROUP(MAP_FIVE_ISLAND_MEADOW), MAP_NUM(MAP_FIVE_ISLAND_MEADOW), HEAL_LOCATION_NONE},
    [MAPSEC_MEMORIAL_PILLAR] = {MAP_GROUP(MAP_FIVE_ISLAND_MEMORIAL_PILLAR), MAP_NUM(MAP_FIVE_ISLAND_MEMORIAL_PILLAR), HEAL_LOCATION_NONE},
    [MAPSEC_OUTCAST_ISLAND] = {MAP_GROUP(MAP_SIX_ISLAND_OUTCAST_ISLAND), MAP_NUM(MAP_SIX_ISLAND_OUTCAST_ISLAND), HEAL_LOCATION_NONE},
    [MAPSEC_GREEN_PATH] = {MAP_GROUP(MAP_SIX_ISLAND_GREEN_PATH), MAP_NUM(MAP_SIX_ISLAND_GREEN_PATH), HEAL_LOCATION_NONE},
    [MAPSEC_WATER_PATH] = {MAP_GROUP(MAP_SIX_ISLAND_WATER_PATH), MAP_NUM(MAP_SIX_ISLAND_WATER_PATH), HEAL_LOCATION_NONE},
    [MAPSEC_RUIN_VALLEY] = {MAP_GROUP(MAP_SIX_ISLAND_RUIN_VALLEY), MAP_NUM(MAP_SIX_ISLAND_RUIN_VALLEY), HEAL_LOCATION_NONE},
    [MAPSEC_TRAINER_TOWER] = {MAP_GROUP(MAP_SEVEN_ISLAND_TRAINER_TOWER), MAP_NUM(MAP_SEVEN_ISLAND_TRAINER_TOWER), HEAL_LOCATION_NONE},
    [MAPSEC_CANYON_ENTRANCE] = {MAP_GROUP(MAP_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE), MAP_NUM(MAP_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE), HEAL_LOCATION_NONE},
    [MAPSEC_SEVAULT_CANYON] = {MAP_GROUP(MAP_SEVEN_ISLAND_SEVAULT_CANYON), MAP_NUM(MAP_SEVEN_ISLAND_SEVAULT_CANYON), HEAL_LOCATION_NONE},
    [MAPSEC_TANOBY_RUINS] = {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS), HEAL_LOCATION_NONE},
    [MAPSEC_SEVII_ISLE_22] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_SEVII_ISLE_23] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_SEVII_ISLE_24] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_NAVEL_ROCK_FRLG] = {MAP_GROUP(MAP_NAVEL_ROCK_EXTERIOR_FRLG), MAP_NUM(MAP_NAVEL_ROCK_EXTERIOR_FRLG), HEAL_LOCATION_NONE},
    [MAPSEC_MT_EMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_BERRY_FOREST] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ICEFALL_CAVE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ROCKET_WAREHOUSE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_TRAINER_TOWER_2] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_DOTTED_HOLE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_LOST_CAVE] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_PATTERN_BUSH] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_ALTERING_CAVE_FRLG] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_TANOBY_CHAMBERS] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_THREE_ISLE_PATH] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_TANOBY_KEY] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_BIRTH_ISLAND_FRLG] = {MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR_FRLG), MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR_FRLG), HEAL_LOCATION_NONE},
    [MAPSEC_MONEAN_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_LIPTOO_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_WEEPTH_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_DILFORD_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_SCUFIB_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_RIXY_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_VIAPOIS_CHAMBER] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
    [MAPSEC_EMBER_SPA] = {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), HEAL_LOCATION_NONE},
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
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 17,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x01
    },
    [WIN_MAPSEC_NAME_TALL] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 15,
        .width = 12,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x19
    },
    [WIN_FLY_TO_WHERE] = {
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
    .tag = TAG_FLY_ICON
};

static const mapsec_u16_t sRedOutlineFlyDestinations[][2] =
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
    .tileTag = TAG_FLY_ICON,
    .paletteTag = TAG_FLY_ICON,
    .oam = &sFlyDestIcon_OamData,
    .anims = sFlyDestIcon_Anims,
};

void InitRegionMap(struct RegionMap *regionMap, bool8 zoomed)
{
    InitRegionMapData(regionMap, NULL, zoomed);
    while (LoadRegionMapGfx());
}

void InitRegionMapData(struct RegionMap *regionMap, const struct BgTemplate *template, bool8 zoomed)
{
    sRegionMap = regionMap;
    sRegionMap->initStep = 0;
    sRegionMap->zoomed = zoomed;
    sRegionMap->inputCallback = zoomed == TRUE ? ProcessRegionMapInput_Zoomed : ProcessRegionMapInput_Full;
    if (template != NULL)
    {
        sRegionMap->bgNum = template->bg;
        sRegionMap->charBaseIdx = template->charBaseIndex;
        sRegionMap->mapBaseIdx = template->mapBaseIndex;
        sRegionMap->bgManaged = TRUE;
    }
    else
    {
        sRegionMap->bgNum = 2;
        sRegionMap->charBaseIdx = 2;
        sRegionMap->mapBaseIdx = 28;
        sRegionMap->bgManaged = FALSE;
    }
}

void ShowRegionMapForPokedexAreaScreen(struct RegionMap *regionMap)
{
    sRegionMap = regionMap;
    InitMapBasedOnPlayerLocation();
    sRegionMap->playerIconSpritePosX = sRegionMap->cursorPosX;
    sRegionMap->playerIconSpritePosY = sRegionMap->cursorPosY;
}

bool8 LoadRegionMapGfx(void)
{
    enum RegionMapType regionMapType;
    switch (sRegionMap->initStep)
    {
    case 0:
        regionMapType = GetRegionMapType(gMapHeader.regionMapSectionId);
        if (sRegionMap->bgManaged)
            DecompressAndCopyTileDataToVram(sRegionMap->bgNum, gRegionMapInfos[regionMapType].regionMapGfx, 0, 0, 0);
        else
            DecompressDataWithHeaderVram(gRegionMapInfos[regionMapType].regionMapGfx, (u16 *)BG_CHAR_ADDR(2));
        break;
    case 1:
        regionMapType = GetRegionMapType(gMapHeader.regionMapSectionId);
        if (sRegionMap->bgManaged)
        {
            if (!FreeTempTileDataBuffersIfPossible())
                DecompressAndCopyTileDataToVram(sRegionMap->bgNum, gRegionMapInfos[regionMapType].regionMapTilemap, 0, 0, 1);
        }
        else
        {
            DecompressDataWithHeaderVram(gRegionMapInfos[regionMapType].regionMapTilemap, (u16 *)BG_SCREEN_ADDR(28));
        }
        break;
    case 2:
        regionMapType = GetRegionMapType(gMapHeader.regionMapSectionId);
        if (!FreeTempTileDataBuffersIfPossible())
            LoadPalette(gRegionMapInfos[regionMapType].regionMapPalette, BG_PLTT_ID(7), 3 * PLTT_SIZE_4BPP);
        break;
    case 3:
        DecompressDataWithHeaderWram(sRegionMapCursorSmallGfxLZ, sRegionMap->cursorSmallImage);
        break;
    case 4:
        DecompressDataWithHeaderWram(sRegionMapCursorLargeGfxLZ, sRegionMap->cursorLargeImage);
        break;
    case 5:
        InitMapBasedOnPlayerLocation();
        sRegionMap->playerIconSpritePosX = sRegionMap->cursorPosX;
        sRegionMap->playerIconSpritePosY = sRegionMap->cursorPosY;
        sRegionMap->mapSecId = CorrectSpecialMapSecId_Internal(sRegionMap->mapSecId);
        sRegionMap->mapSecType = GetMapsecType(sRegionMap->mapSecId);
        GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
        break;
    case 6:
        if (sRegionMap->zoomed == FALSE)
        {
            CalcZoomScrollParams(0, 0, 0, 0, 0x100, 0x100, 0);
        }
        else
        {
            sRegionMap->scrollX = sRegionMap->cursorPosX * 8 - 0x34;
            sRegionMap->scrollY = sRegionMap->cursorPosY * 8 - 0x44;
            sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
            sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
            CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
        }
        break;
    case 7:
        GetPositionOfCursorWithinMapSec();
        UpdateRegionMapVideoRegs();
        sRegionMap->cursorSprite = NULL;
        sRegionMap->playerIconSprite = NULL;
        sRegionMap->cursorMovementFrameCounter = 0;
        sRegionMap->blinkPlayerIcon = FALSE;
        if (sRegionMap->bgManaged)
        {
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_SCREENSIZE, 2);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_CHARBASEINDEX, sRegionMap->charBaseIdx);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_MAPBASEINDEX, sRegionMap->mapBaseIdx);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_WRAPAROUND, 1);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_PALETTEMODE, 1);
        }
        sRegionMap->initStep++;
        return FALSE;
    default:
        return FALSE;
    }
    sRegionMap->initStep++;
    return TRUE;
}

void BlendRegionMap(u16 color, u32 coeff)
{
    BlendPalettes(0x380, coeff, color);
    CpuCopy16(&gPlttBufferFaded[BG_PLTT_ID(7)], &gPlttBufferUnfaded[BG_PLTT_ID(7)], 3 * PLTT_SIZE_4BPP);
}

void FreeRegionMapIconResources(void)
{
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
    if (sRegionMap->playerIconSprite != NULL)
    {
        DestroySprite(sRegionMap->playerIconSprite);
        FreeSpriteTilesByTag(sRegionMap->playerIconTileTag);
        FreeSpritePaletteByTag(sRegionMap->playerIconPaletteTag);
    }
}

u8 DoRegionMapInputCallback(void)
{
    return sRegionMap->inputCallback();
}

static u8 ProcessRegionMapInput_Full(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->cursorDeltaX = 0;
    sRegionMap->cursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && sRegionMap->cursorPosY > MAPCURSOR_Y_MIN)
    {
        sRegionMap->cursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && sRegionMap->cursorPosY < MAPCURSOR_Y_MAX)
    {
        sRegionMap->cursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && sRegionMap->cursorPosX > MAPCURSOR_X_MIN)
    {
        sRegionMap->cursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && sRegionMap->cursorPosX < MAPCURSOR_X_MAX)
    {
        sRegionMap->cursorDeltaX = +1;
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
    else if (JOY_NEW(R_BUTTON))
    {
        input = MAP_INPUT_R_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sRegionMap->cursorMovementFrameCounter = 4;
        sRegionMap->inputCallback = MoveRegionMapCursor_Full;
    }
    return input;
}

static u8 MoveRegionMapCursor_Full(void)
{
    mapsec_u16_t mapSecId;

    if (sRegionMap->cursorMovementFrameCounter != 0)
        return MAP_INPUT_MOVE_CONT;

    if (sRegionMap->cursorDeltaX > 0)
    {
        sRegionMap->cursorPosX++;
    }
    if (sRegionMap->cursorDeltaX < 0)
    {
        sRegionMap->cursorPosX--;
    }
    if (sRegionMap->cursorDeltaY > 0)
    {
        sRegionMap->cursorPosY++;
    }
    if (sRegionMap->cursorDeltaY < 0)
    {
        sRegionMap->cursorPosY--;
    }

    mapSecId = GetMapSecIdAt(sRegionMap->cursorPosX, sRegionMap->cursorPosY);
    sRegionMap->mapSecType = GetMapsecType(mapSecId);
    if (mapSecId != sRegionMap->mapSecId)
    {
        sRegionMap->mapSecId = mapSecId;
        GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
    }
    GetPositionOfCursorWithinMapSec();
    sRegionMap->inputCallback = ProcessRegionMapInput_Full;
    return MAP_INPUT_MOVE_END;
}

static u8 ProcessRegionMapInput_Zoomed(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->zoomedCursorDeltaX = 0;
    sRegionMap->zoomedCursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && sRegionMap->scrollY > -0x34)
    {
        sRegionMap->zoomedCursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && sRegionMap->scrollY < 0x3c)
    {
        sRegionMap->zoomedCursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && sRegionMap->scrollX > -0x2c)
    {
        sRegionMap->zoomedCursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && sRegionMap->scrollX < 0xac)
    {
        sRegionMap->zoomedCursorDeltaX = +1;
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
    else if (JOY_NEW(R_BUTTON))
    {
        input = MAP_INPUT_R_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sRegionMap->inputCallback = MoveRegionMapCursor_Zoomed;
        sRegionMap->zoomedCursorMovementFrameCounter = 0;
    }
    return input;
}

static u8 MoveRegionMapCursor_Zoomed(void)
{
    u16 x;
    u16 y;
    mapsec_u16_t mapSecId;

    sRegionMap->scrollY += sRegionMap->zoomedCursorDeltaY;
    sRegionMap->scrollX += sRegionMap->zoomedCursorDeltaX;
    RegionMap_SetBG2XAndBG2Y(sRegionMap->scrollX, sRegionMap->scrollY);
    sRegionMap->zoomedCursorMovementFrameCounter++;
    if (sRegionMap->zoomedCursorMovementFrameCounter == 8)
    {
        x = (sRegionMap->scrollX + 0x2c) / 8 + 1;
        y = (sRegionMap->scrollY + 0x34) / 8 + 2;
        if (x != sRegionMap->zoomedCursorPosX || y != sRegionMap->zoomedCursorPosY)
        {
            sRegionMap->zoomedCursorPosX = x;
            sRegionMap->zoomedCursorPosY = y;
            mapSecId = GetMapSecIdAt(x, y);
            sRegionMap->mapSecType = GetMapsecType(mapSecId);
            if (mapSecId != sRegionMap->mapSecId)
            {
                sRegionMap->mapSecId = mapSecId;
                GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
            }
            GetPositionOfCursorWithinMapSec();
        }
        sRegionMap->zoomedCursorMovementFrameCounter = 0;
        sRegionMap->inputCallback = ProcessRegionMapInput_Zoomed;
        return MAP_INPUT_MOVE_END;
    }
    return MAP_INPUT_MOVE_CONT;
}

void SetRegionMapDataForZoom(void)
{
    if (sRegionMap->zoomed == FALSE)
    {
        sRegionMap->scrollY = 0;
        sRegionMap->scrollX = 0;
        sRegionMap->unk_040 = 0;
        sRegionMap->unk_03c = 0;
        sRegionMap->unk_060 = sRegionMap->cursorPosX * 8 - 0x34;
        sRegionMap->unk_062 = sRegionMap->cursorPosY * 8 - 0x44;
        sRegionMap->unk_044 = (sRegionMap->unk_060 << 8) / 16;
        sRegionMap->unk_048 = (sRegionMap->unk_062 << 8) / 16;
        sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
        sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
        sRegionMap->unk_04c = 0x10000;
        sRegionMap->unk_050 = -0x800;
    }
    else
    {
        sRegionMap->unk_03c = sRegionMap->scrollX * 0x100;
        sRegionMap->unk_040 = sRegionMap->scrollY * 0x100;
        sRegionMap->unk_060 = 0;
        sRegionMap->unk_062 = 0;
        sRegionMap->unk_044 = -(sRegionMap->unk_03c / 16);
        sRegionMap->unk_048 = -(sRegionMap->unk_040 / 16);
        sRegionMap->cursorPosX = sRegionMap->zoomedCursorPosX;
        sRegionMap->cursorPosY = sRegionMap->zoomedCursorPosY;
        sRegionMap->unk_04c = 0x8000;
        sRegionMap->unk_050 = 0x800;
    }
    sRegionMap->unk_06e = 0;
    FreeRegionMapCursorSprite();
    HideRegionMapPlayerIcon();
}

bool8 UpdateRegionMapZoom(void)
{
    bool8 retVal;

    if (sRegionMap->unk_06e >= 16)
    {
        return FALSE;
    }
    sRegionMap->unk_06e++;
    if (sRegionMap->unk_06e == 16)
    {
        sRegionMap->unk_044 = 0;
        sRegionMap->unk_048 = 0;
        sRegionMap->scrollX = sRegionMap->unk_060;
        sRegionMap->scrollY = sRegionMap->unk_062;
        sRegionMap->unk_04c = (sRegionMap->zoomed == FALSE) ? (128 << 8) : (256 << 8);
        sRegionMap->zoomed = !sRegionMap->zoomed;
        sRegionMap->inputCallback = (sRegionMap->zoomed == FALSE) ? ProcessRegionMapInput_Full : ProcessRegionMapInput_Zoomed;
        CreateRegionMapCursor(sRegionMap->cursorTileTag, sRegionMap->cursorPaletteTag);
        UnhideRegionMapPlayerIcon();
        retVal = FALSE;
    }
    else
    {
        sRegionMap->unk_03c += sRegionMap->unk_044;
        sRegionMap->unk_040 += sRegionMap->unk_048;
        sRegionMap->scrollX = sRegionMap->unk_03c >> 8;
        sRegionMap->scrollY = sRegionMap->unk_040 >> 8;
        sRegionMap->unk_04c += sRegionMap->unk_050;
        if ((sRegionMap->unk_044 < 0 && sRegionMap->scrollX < sRegionMap->unk_060) || (sRegionMap->unk_044 > 0 && sRegionMap->scrollX > sRegionMap->unk_060))
        {
            sRegionMap->scrollX = sRegionMap->unk_060;
            sRegionMap->unk_044 = 0;
        }
        if ((sRegionMap->unk_048 < 0 && sRegionMap->scrollY < sRegionMap->unk_062) || (sRegionMap->unk_048 > 0 && sRegionMap->scrollY > sRegionMap->unk_062))
        {
            sRegionMap->scrollY = sRegionMap->unk_062;
            sRegionMap->unk_048 = 0;
        }
        if (sRegionMap->zoomed == FALSE)
        {
            if (sRegionMap->unk_04c < (128 << 8))
            {
                sRegionMap->unk_04c = (128 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        else
        {
            if (sRegionMap->unk_04c > (256 << 8))
            {
                sRegionMap->unk_04c = (256 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        retVal = TRUE;
    }
    CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, sRegionMap->unk_04c >> 8, sRegionMap->unk_04c >> 8, 0);
    return retVal;
}

static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
{
    s32 var1;
    s32 var2;
    s32 var3;
    s32 var4;

    sRegionMap->bg2pa = e * gSineTable[rotation + 64] >> 8;
    sRegionMap->bg2pc = e * -gSineTable[rotation] >> 8;
    sRegionMap->bg2pb = f * gSineTable[rotation] >> 8;
    sRegionMap->bg2pd = f * gSineTable[rotation + 64] >> 8;

    var1 = (scrollX << 8) + (c << 8);
    var2 = d * sRegionMap->bg2pb + sRegionMap->bg2pa * c;
    sRegionMap->bg2x = var1 - var2;

    var3 = (scrollY << 8) + (d << 8);
    var4 = sRegionMap->bg2pd * d + sRegionMap->bg2pc * c;
    sRegionMap->bg2y = var3 - var4;

    sRegionMap->needUpdateVideoRegs = TRUE;
}

static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y)
{
    sRegionMap->bg2x = (x << 8) + 0x1c00;
    sRegionMap->bg2y = (y << 8) + 0x2400;
    sRegionMap->needUpdateVideoRegs = TRUE;
}

void UpdateRegionMapVideoRegs(void)
{
    if (sRegionMap->needUpdateVideoRegs)
    {
        SetGpuReg(REG_OFFSET_BG2PA, sRegionMap->bg2pa);
        SetGpuReg(REG_OFFSET_BG2PB, sRegionMap->bg2pb);
        SetGpuReg(REG_OFFSET_BG2PC, sRegionMap->bg2pc);
        SetGpuReg(REG_OFFSET_BG2PD, sRegionMap->bg2pd);
        SetGpuReg(REG_OFFSET_BG2X_L, sRegionMap->bg2x);
        SetGpuReg(REG_OFFSET_BG2X_H, sRegionMap->bg2x >> 16);
        SetGpuReg(REG_OFFSET_BG2Y_L, sRegionMap->bg2y);
        SetGpuReg(REG_OFFSET_BG2Y_H, sRegionMap->bg2y >> 16);
        sRegionMap->needUpdateVideoRegs = FALSE;
    }
}

void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y)
{
    CalcZoomScrollParams(x, y, 0x38, 0x48, 0x100, 0x100, 0);
    UpdateRegionMapVideoRegs();
    if (sRegionMap->playerIconSprite != NULL)
    {
        sRegionMap->playerIconSprite->x2 = -x;
        sRegionMap->playerIconSprite->y2 = -y;
    }
}

enum RegionMapType GetRegionMapType(u32 mapSecId)
{
    switch (GetRegionForSectionId(mapSecId))
    {
    case REGION_KANTO:
        switch (GetKantoSubregion(mapSecId))
        {
        case KANTO_SUBREGION_SEVII123:
            return REGION_MAP_SEVII123;
        case KANTO_SUBREGION_SEVII45:
            return REGION_MAP_SEVII45;
        case KANTO_SUBREGION_SEVII67:
            return REGION_MAP_SEVII67;
        case KANTO_SUBREGION_KANTO:
        default:
            return REGION_MAP_KANTO;
        }
    case REGION_HOENN:
    default:
        return REGION_MAP_HOENN;
    }
}

static mapsec_u16_t GetMapSecIdAt(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;

    switch (GetCurrentRegion())
    {
    case REGION_KANTO:
        switch (GetKantoSubregion(gMapHeader.regionMapSectionId))
        {
        case KANTO_SUBREGION_SEVII123:
                return sRegionMapSections_Sevii123[y][x];
        case KANTO_SUBREGION_SEVII45:
                return sRegionMapSections_Sevii45[y][x];
        case KANTO_SUBREGION_SEVII67:
                return sRegionMapSections_Sevii67[y][x];
        case KANTO_SUBREGION_KANTO:
        default:
                return sRegionMapSections_Kanto[y][x];
        }
    case REGION_HOENN:
    default:
            return sRegionMap_MapSectionLayout[y][x];
    }
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

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_SS_TIDAL_CORRIDOR)
        && (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SS_TIDAL_CORRIDOR)
            || gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SS_TIDAL_LOWER_DECK)
            || gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SS_TIDAL_ROOMS)))
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
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        sRegionMap->playerIsInCave = FALSE;
        mapWidth = gMapHeader.mapLayout->width;
        mapHeight = gMapHeader.mapLayout->height;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        if (sRegionMap->mapSecId == MAPSEC_UNDERWATER_SEAFLOOR_CAVERN || sRegionMap->mapSecId == MAPSEC_UNDERWATER_MARINE_CAVE)
            sRegionMap->playerIsInCave = TRUE;
        break;
    case MAP_TYPE_UNDERGROUND:
    case MAP_TYPE_UNKNOWN:
        if (gMapHeader.allowEscaping)
        {
            mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = mapHeader->mapLayout->width;
            mapHeight = mapHeader->mapLayout->height;
            x = gSaveBlock1Ptr->escapeWarp.x;
            y = gSaveBlock1Ptr->escapeWarp.y;
        }
        else
        {
            sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = 1;
            mapHeight = 1;
            x = 1;
            y = 1;
        }
        break;
    case MAP_TYPE_SECRET_BASE:
        mapHeader = Overworld_GetMapHeaderByGroupAndId((u16)gSaveBlock1Ptr->dynamicWarp.mapGroup, (u16)gSaveBlock1Ptr->dynamicWarp.mapNum);
        sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        sRegionMap->playerIsInCave = TRUE;
        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->dynamicWarp.x;
        y = gSaveBlock1Ptr->dynamicWarp.y;
        break;
    case MAP_TYPE_INDOOR:
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        if (sRegionMap->mapSecId != MAPSEC_DYNAMIC)
        {
            warp = &gSaveBlock1Ptr->escapeWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
        }
        else
        {
            warp = &gSaveBlock1Ptr->dynamicWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        }

        if (IsPlayerInAquaHideout(sRegionMap->mapSecId))
            sRegionMap->playerIsInCave = TRUE;
        else
            sRegionMap->playerIsInCave = FALSE;

        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = warp->x;
        y = warp->y;
        break;
    }

    xOnMap = x;

    dimensionScale = mapWidth / gRegionMapEntries[sRegionMap->mapSecId].width;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    x /= dimensionScale;
    if (x >= gRegionMapEntries[sRegionMap->mapSecId].width)
    {
        x = gRegionMapEntries[sRegionMap->mapSecId].width - 1;
    }

    dimensionScale = mapHeight / gRegionMapEntries[sRegionMap->mapSecId].height;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    y /= dimensionScale;
    if (y >= gRegionMapEntries[sRegionMap->mapSecId].height)
    {
        y = gRegionMapEntries[sRegionMap->mapSecId].height - 1;
    }

    switch (sRegionMap->mapSecId)
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
        GetMarineCaveCoords(&sRegionMap->cursorPosX, &sRegionMap->cursorPosY);
        return;
    }
    sRegionMap->cursorPosX = gRegionMapEntries[sRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    sRegionMap->cursorPosY = gRegionMapEntries[sRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static void RegionMap_InitializeStateBasedOnSSTidalLocation(void)
{
    u16 y;
    u16 x;
    s8 mapGroup;
    s8 mapNum;
    u16 dimensionScale;
    s16 xOnMap;
    s16 yOnMap;
    const struct MapHeader *mapHeader;

    y = 0;
    x = 0;
    switch (GetSSTidalLocation(&mapGroup, &mapNum, &xOnMap, &yOnMap))
    {
    case SS_TIDAL_LOCATION_SLATEPORT:
        sRegionMap->mapSecId = MAPSEC_SLATEPORT_CITY;
        break;
    case SS_TIDAL_LOCATION_LILYCOVE:
        sRegionMap->mapSecId = MAPSEC_LILYCOVE_CITY;
        break;
    case SS_TIDAL_LOCATION_ROUTE124:
        sRegionMap->mapSecId = MAPSEC_ROUTE_124;
        break;
    case SS_TIDAL_LOCATION_ROUTE131:
        sRegionMap->mapSecId = MAPSEC_ROUTE_131;
        break;
    default:
    case SS_TIDAL_LOCATION_CURRENTS:
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);

        sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        dimensionScale = mapHeader->mapLayout->width / gRegionMapEntries[sRegionMap->mapSecId].width;
        if (dimensionScale == 0)
            dimensionScale = 1;
        x = xOnMap / dimensionScale;
        if (x >= gRegionMapEntries[sRegionMap->mapSecId].width)
            x = gRegionMapEntries[sRegionMap->mapSecId].width - 1;

        dimensionScale = mapHeader->mapLayout->height / gRegionMapEntries[sRegionMap->mapSecId].height;
        if (dimensionScale == 0)
            dimensionScale = 1;
        y = yOnMap / dimensionScale;
        if (y >= gRegionMapEntries[sRegionMap->mapSecId].height)
            y = gRegionMapEntries[sRegionMap->mapSecId].height - 1;
        break;
    }
    sRegionMap->playerIsInCave = FALSE;
    sRegionMap->cursorPosX = gRegionMapEntries[sRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    sRegionMap->cursorPosY = gRegionMapEntries[sRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static u8 GetMapsecType(mapsec_u16_t mapSecId)
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
    case MAPSEC_PALLET_TOWN:
        return FlagGet(FLAG_WORLD_MAP_PALLET_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_VIRIDIAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_VIRIDIAN_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_PEWTER_CITY:
        return FlagGet(FLAG_WORLD_MAP_PEWTER_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_CERULEAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_CERULEAN_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_LAVENDER_TOWN:
        return FlagGet(FLAG_WORLD_MAP_LAVENDER_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_VERMILION_CITY:
        return FlagGet(FLAG_WORLD_MAP_VERMILION_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_CELADON_CITY:
        return FlagGet(FLAG_WORLD_MAP_CELADON_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FUCHSIA_CITY:
        return FlagGet(FLAG_WORLD_MAP_FUCHSIA_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_CINNABAR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_CINNABAR_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_INDIGO_PLATEAU:
        return FlagGet(FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SAFFRON_CITY:
        return FlagGet(FLAG_WORLD_MAP_SAFFRON_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_ONE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_ONE_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_TWO_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_TWO_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_THREE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_THREE_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FOUR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FOUR_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FIVE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FIVE_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SEVEN_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SEVEN_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SIX_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_ROUTE_4_POKECENTER:
        return FlagGet(FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_ROUTE_10_POKECENTER:
        return FlagGet(FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    default:
        return MAPSECTYPE_ROUTE;
    }
}

mapsec_u16_t GetRegionMapSecIdAt(u16 x, u16 y)
{
    return GetMapSecIdAt(x, y);
}

static mapsec_u16_t CorrectSpecialMapSecId_Internal(mapsec_u16_t mapSecId)
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

static mapsec_u16_t GetTerraOrMarineCaveMapSecId(void)
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
static bool32 IsPlayerInAquaHideout(mapsec_u8_t mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMapSecAquaHideoutOld); i++)
    {
        if (sMapSecAquaHideoutOld[i] == mapSecId)
            return TRUE;
    }
    return FALSE;
}

mapsec_u16_t CorrectSpecialMapSecId(mapsec_u16_t mapSecId)
{
    return CorrectSpecialMapSecId_Internal(mapSecId);
}

static void GetPositionOfCursorWithinMapSec(void)
{
    u16 x;
    u16 y;
    u16 posWithinMapSec;

    if (sRegionMap->mapSecId == MAPSEC_NONE)
    {
        sRegionMap->posWithinMapSec = 0;
        return;
    }
    if (!sRegionMap->zoomed)
    {
        x = sRegionMap->cursorPosX;
        y = sRegionMap->cursorPosY;
    }
    else
    {
        x = sRegionMap->zoomedCursorPosX;
        y = sRegionMap->zoomedCursorPosY;
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
            if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
            {
                posWithinMapSec++;
            }
        }
    }
    sRegionMap->posWithinMapSec = posWithinMapSec;
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
        if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void SpriteCB_CursorMapFull(struct Sprite *sprite)
{
    if (sRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->x += 2 * sRegionMap->cursorDeltaX;
        sprite->y += 2 * sRegionMap->cursorDeltaY;
        sRegionMap->cursorMovementFrameCounter--;
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
    sRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    sRegionMap->cursorPaletteTag = paletteTag;
    if (!sRegionMap->zoomed)
    {
        sheet.data = sRegionMap->cursorSmallImage;
        sheet.size = sizeof(sRegionMap->cursorSmallImage);
        template.callback = SpriteCB_CursorMapFull;
    }
    else
    {
        sheet.data = sRegionMap->cursorLargeImage;
        sheet.size = sizeof(sRegionMap->cursorLargeImage);
        template.callback = SpriteCB_CursorMapZoomed;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSpriteUnchecked(&template, 56, 72, 0);
    if (spriteId != MAX_SPRITES)
    {
        sRegionMap->cursorSprite = &gSprites[spriteId];
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->cursorSprite->oam.size = SPRITE_SIZE(32x32);
            sRegionMap->cursorSprite->x -= 8;
            sRegionMap->cursorSprite->y -= 8;
            StartSpriteAnim(sRegionMap->cursorSprite, 1);
        }
        else
        {
            sRegionMap->cursorSprite->oam.size = SPRITE_SIZE(16x16);
            sRegionMap->cursorSprite->x = 8 * sRegionMap->cursorPosX + 4;
            sRegionMap->cursorSprite->y = 8 * sRegionMap->cursorPosY + 4;
        }
        sRegionMap->cursorSprite->data[1] = 2;
        sRegionMap->cursorSprite->data[2] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(paletteTag)) + 1;
        sRegionMap->cursorSprite->data[3] = TRUE;
    }
}

static void FreeRegionMapCursorSprite(void)
{
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
}

static void UNUSED SetUnkCursorSpriteData(void)
{
    sRegionMap->cursorSprite->data[3] = TRUE;
}

static void UNUSED ClearUnkCursorSpriteData(void)
{
    sRegionMap->cursorSprite->data[3] = FALSE;
}

void CreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteSheet sheet = {sRegionMapPlayerIcon_BrendanGfx, 0x80, tileTag};
    struct SpritePalette palette = {sRegionMapPlayerIcon_BrendanPal, paletteTag};
    struct SpriteTemplate template = {tileTag, paletteTag, &sRegionMapPlayerIconOam, sRegionMapPlayerIconAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy};

    if (IsEventIslandMapSecId(gMapHeader.regionMapSectionId))
    {
        sRegionMap->playerIconSprite = NULL;
        return;
    }
    if (IS_FRLG && gSaveBlock2Ptr->playerGender == FEMALE)
    {
        sheet.data = sRegionMapPlayerIcon_LeafGfx;
        palette.data = sRegionMapPlayerIcon_LeafPal;
    }
    else if (gSaveBlock2Ptr->playerGender == FEMALE)
    {
        sheet.data = sRegionMapPlayerIcon_MayGfx;
        palette.data = sRegionMapPlayerIcon_MayPal;
    }
    else if (IS_FRLG)
    {
        sheet.data = sRegionMapPlayerIcon_RedGfx;
        palette.data = sRegionMapPlayerIcon_RedPal;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0, 0, 1);
    sRegionMap->playerIconSprite = &gSprites[spriteId];
    if (!sRegionMap->zoomed)
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
    }
    else
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
    }
}

static void HideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        sRegionMap->playerIconSprite->invisible = TRUE;
        sRegionMap->playerIconSprite->callback = SpriteCallbackDummy;
    }
}

static void UnhideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
        else
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
            sRegionMap->playerIconSprite->x2 = 0;
            sRegionMap->playerIconSprite->y2 = 0;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
    }
}

#define sY       data[0]
#define sX       data[1]
#define sVisible data[2]
#define sTimer   data[7]

static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite)
{
    sprite->x2 = -2 * sRegionMap->scrollX;
    sprite->y2 = -2 * sRegionMap->scrollY;
    sprite->sY = sprite->y + sprite->y2 + sprite->centerToCornerVecY;
    sprite->sX = sprite->x + sprite->x2 + sprite->centerToCornerVecX;
    if (sprite->sY < -8 || sprite->sY > DISPLAY_HEIGHT + 8 || sprite->sX < -8 || sprite->sX > DISPLAY_WIDTH + 8)
        sprite->sVisible = FALSE;
    else
        sprite->sVisible = TRUE;

    if (sprite->sVisible == TRUE)
        SpriteCB_PlayerIcon(sprite);
    else
        sprite->invisible = TRUE;
}

static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite)
{
    SpriteCB_PlayerIcon(sprite);
}

static void SpriteCB_PlayerIcon(struct Sprite *sprite)
{
    if (sRegionMap->blinkPlayerIcon)
    {
        if (++sprite->sTimer > 16)
        {
            sprite->sTimer = 0;
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
    if (sRegionMap->playerIsInCave)
        sRegionMap->blinkPlayerIcon = TRUE;
}

#undef sY
#undef sX
#undef sVisible
#undef sTimer

u8 *GetMapName(u8 *dest, mapsec_u16_t regionMapId, u16 padLength)
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
u8 *GetMapNameGeneric(u8 *dest, mapsec_u16_t mapSecId)
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

u8 *GetMapNameHandleAquaHideout(u8 *dest, mapsec_u16_t mapSecId)
{
    if (mapSecId == MAPSEC_AQUA_HIDEOUT_OLD)
        return StringCopy(dest, gText_Hideout);
    else
        return GetMapNameGeneric(dest, mapSecId);
}

static void GetMapSecDimensions(mapsec_u16_t mapSecId, u16 *x, u16 *y, u16 *width, u16 *height)
{
    *x = gRegionMapEntries[mapSecId].x;
    *y = gRegionMapEntries[mapSecId].y;
    *width = gRegionMapEntries[mapSecId].width;
    *height = gRegionMapEntries[mapSecId].height;
}

bool8 IsRegionMapZoomed(void)
{
    return sRegionMap->zoomed;
}

bool32 IsEventIslandMapSecId(mapsec_u8_t mapSecId)
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
        sFlyMap = Alloc(sizeof(*sFlyMap));
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
        LoadUserWindowBorderGfx(0, 0x65, BG_PLTT_ID(13));
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 4:
        InitRegionMap(&sFlyMap->regionMap, FALSE);
        CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
        CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
        sFlyMap->mapSecId = sFlyMap->regionMap.mapSecId;
        StringFill(sFlyMap->nameBuffer, CHAR_SPACE, MAP_NAME_LENGTH);
        sDrawFlyDestTextWindow = TRUE;
        DrawFlyDestTextWindow();
        gMain.state++;
        break;
    case 5:
        DecompressDataWithHeaderVram(sRegionMapFrameGfxLZ, (u16 *)BG_CHAR_ADDR(3));
        gMain.state++;
        break;
    case 6:
        DecompressDataWithHeaderVram(sRegionMapFrameTilemapLZ, (u16 *)BG_SCREEN_ADDR(30));
        gMain.state++;
        break;
    case 7:
        LoadPalette(sRegionMapFramePal, BG_PLTT_ID(1), sizeof(sRegionMapFramePal));
        PutWindowTilemap(WIN_FLY_TO_WHERE);
        FillWindowPixelBuffer(WIN_FLY_TO_WHERE, PIXEL_FILL(0));
        AddTextPrinterParameterized(WIN_FLY_TO_WHERE, FONT_NORMAL, gText_FlyToWhere, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(0);
        gMain.state++;
        break;
    case 8:
        LoadFlyDestIcons();
        gMain.state++;
        break;
    case 9:
        BlendPalettes(PALETTES_ALL, 16, 0);
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

    if (sFlyMap->regionMap.mapSecType > MAPSECTYPE_NONE && sFlyMap->regionMap.mapSecType < NUM_MAPSEC_TYPES)
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
                    ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME, FALSE);
                    DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME_TALL, FALSE, 101, 13);
                    AddTextPrinterParameterized(WIN_MAPSEC_NAME_TALL, FONT_NORMAL, sFlyMap->regionMap.mapSecName, 0, 1, 0, NULL);
                    name = sMultiNameFlyDestinations[i].name[sFlyMap->regionMap.posWithinMapSec];
                    AddTextPrinterParameterized(WIN_MAPSEC_NAME_TALL, FONT_NORMAL, name, GetStringRightAlignXOffset(FONT_NORMAL, name, 96), 17, 0, NULL);
                    ScheduleBgCopyTilemapToVram(0);
                    sDrawFlyDestTextWindow = TRUE;
                }
                break;
            }
        }
        if (!namePrinted)
        {
            if (sDrawFlyDestTextWindow == TRUE)
            {
                ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME_TALL, FALSE);
                DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 101, 13);
            }
            else
            {
                // Window is already drawn, just empty it
                FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
            }
            AddTextPrinterParameterized(WIN_MAPSEC_NAME, FONT_NORMAL, sFlyMap->regionMap.mapSecName, 0, 1, 0, NULL);
            ScheduleBgCopyTilemapToVram(0);
            sDrawFlyDestTextWindow = FALSE;
        }
    }
    else
    {
        // Selection is on MAPSECTYPE_NONE, draw empty fly destination text window
        if (sDrawFlyDestTextWindow == TRUE)
        {
            ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME_TALL, FALSE);
            DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 101, 13);
        }
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        sDrawFlyDestTextWindow = FALSE;
    }
}


static void LoadFlyDestIcons(void)
{
    struct SpriteSheet sheet;

    DecompressDataWithHeaderWram(sFlyTargetIcons_Gfx, sFlyMap->tileBuffer);
    sheet.data = sFlyMap->tileBuffer;
    sheet.size = sizeof(sFlyMap->tileBuffer);
    sheet.tag = TAG_FLY_ICON;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sFlyTargetIconsSpritePalette);
    CreateFlyDestIcons();
    TryCreateRedOutlineFlyDestIcons();
}

struct FlyLocation
{
    enum RegionMapType regionMapType;
    u16 flag;
    u16 mapsec;
};

static const struct FlyLocation sFlyLocations[] =
{
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_LITTLEROOT_TOWN,
        .flag = FLAG_VISITED_LITTLEROOT_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_OLDALE_TOWN,
        .flag = FLAG_VISITED_OLDALE_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_DEWFORD_TOWN,
        .flag = FLAG_VISITED_DEWFORD_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_LAVARIDGE_TOWN,
        .flag = FLAG_VISITED_LAVARIDGE_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_FALLARBOR_TOWN,
        .flag = FLAG_VISITED_FALLARBOR_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_VERDANTURF_TOWN,
        .flag = FLAG_VISITED_VERDANTURF_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_PACIFIDLOG_TOWN,
        .flag = FLAG_VISITED_PACIFIDLOG_TOWN,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_PETALBURG_CITY,
        .flag = FLAG_VISITED_PETALBURG_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_SLATEPORT_CITY,
        .flag = FLAG_VISITED_SLATEPORT_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_MAUVILLE_CITY,
        .flag = FLAG_VISITED_MAUVILLE_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_RUSTBORO_CITY,
        .flag = FLAG_VISITED_RUSTBORO_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_FORTREE_CITY,
        .flag = FLAG_VISITED_FORTREE_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_LILYCOVE_CITY,
        .flag = FLAG_VISITED_LILYCOVE_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_MOSSDEEP_CITY,
        .flag = FLAG_VISITED_MOSSDEEP_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_SOOTOPOLIS_CITY,
        .flag = FLAG_VISITED_SOOTOPOLIS_CITY,
    },
    {
        .regionMapType = REGION_MAP_HOENN,
        .mapsec = MAPSEC_EVER_GRANDE_CITY,
        .flag = FLAG_VISITED_EVER_GRANDE_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_PALLET_TOWN,
        .flag = FLAG_WORLD_MAP_PALLET_TOWN,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_VIRIDIAN_CITY,
        .flag = FLAG_WORLD_MAP_VIRIDIAN_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_PEWTER_CITY,
        .flag = FLAG_WORLD_MAP_PEWTER_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_CERULEAN_CITY,
        .flag = FLAG_WORLD_MAP_CERULEAN_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_LAVENDER_TOWN,
        .flag = FLAG_WORLD_MAP_LAVENDER_TOWN,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_VERMILION_CITY,
        .flag = FLAG_WORLD_MAP_VERMILION_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_CELADON_CITY,
        .flag = FLAG_WORLD_MAP_CELADON_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_FUCHSIA_CITY,
        .flag = FLAG_WORLD_MAP_FUCHSIA_CITY,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_CINNABAR_ISLAND,
        .flag = FLAG_WORLD_MAP_CINNABAR_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_INDIGO_PLATEAU,
        .flag = FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_SAFFRON_CITY,
        .flag = FLAG_WORLD_MAP_SAFFRON_CITY,
    },
    {
        .regionMapType = REGION_MAP_SEVII123,
        .mapsec = MAPSEC_ONE_ISLAND,
        .flag = FLAG_WORLD_MAP_ONE_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII123,
        .mapsec = MAPSEC_TWO_ISLAND,
        .flag = FLAG_WORLD_MAP_TWO_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII123,
        .mapsec = MAPSEC_THREE_ISLAND,
        .flag = FLAG_WORLD_MAP_THREE_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII45,
        .mapsec = MAPSEC_FOUR_ISLAND,
        .flag = FLAG_WORLD_MAP_FOUR_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII45,
        .mapsec = MAPSEC_FIVE_ISLAND,
        .flag = FLAG_WORLD_MAP_FIVE_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII67,
        .mapsec = MAPSEC_SEVEN_ISLAND,
        .flag = FLAG_WORLD_MAP_SEVEN_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_SEVII67,
        .mapsec = MAPSEC_SIX_ISLAND,
        .flag = FLAG_WORLD_MAP_SIX_ISLAND,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_ROUTE_4_POKECENTER,
        .flag = FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F,
    },
    {
        .regionMapType = REGION_MAP_KANTO,
        .mapsec = MAPSEC_ROUTE_10_POKECENTER,
        .flag = FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F,
    },
};


// Sprite data for SpriteCB_FlyDestIcon
#define sIconMapSec   data[0]
#define sFlickerTimer data[1]

static void CreateFlyDestIcons(void)
{
    enum RegionMapType regionMapType = GetRegionMapType(gMapHeader.regionMapSectionId);
    u32 i;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 shape;
    u8 spriteId;

    for (i = 0; i < ARRAY_COUNT(sFlyLocations); i++)
    {
        if (sFlyLocations[i].regionMapType != regionMapType)
            continue;

        GetMapSecDimensions(sFlyLocations[i].mapsec, &x, &y, &width, &height);
        x = (x + MAPCURSOR_X_MIN) * 8 + 4;
        y = (y + MAPCURSOR_Y_MIN) * 8 + 4;

        if (width == 2)
            shape = SPRITE_SHAPE(16x8);
        else if (height == 2)
            shape = SPRITE_SHAPE(8x16);
        else
            shape = SPRITE_SHAPE(8x8);

        spriteId = CreateSpriteUnchecked(&sFlyDestIconSpriteTemplate, x, y, 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.shape = shape;

            if (FlagGet(sFlyLocations[i].flag))
                gSprites[spriteId].callback = SpriteCB_FlyDestIcon;
            else
                shape += 3;

            StartSpriteAnim(&gSprites[spriteId], shape);
            gSprites[spriteId].sIconMapSec = sFlyLocations[i].mapsec;
        }
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
    mapsec_u16_t mapSecId;
    u8 spriteId;

    for (i = 0; sRedOutlineFlyDestinations[i][1] != MAPSEC_NONE; i++)
    {
        if (FlagGet(sRedOutlineFlyDestinations[i][0]))
        {
            mapSecId = sRedOutlineFlyDestinations[i][1];
            GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
            x = (x + MAPCURSOR_X_MIN) * 8;
            y = (y + MAPCURSOR_Y_MIN) * 8;
            spriteId = CreateSpriteUnchecked(&sFlyDestIconSpriteTemplate, x, y, 10);
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
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
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
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sFlyMap->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            FreeRegionMapIconResources();
            if (sFlyMap->choseFlyLocation)
            {
                struct RegionMap* tempRegionMap = &sFlyMap->regionMap;

                SetFlyDestination(tempRegionMap);
                ReturnToFieldFromFlyMapSelect();
            }
            else
            {
                SetMainCallback2(CB2_ReturnToPartyMenuFromFlyMap);
            }
            TRY_FREE_AND_SET_NULL(sFlyMap);
            FreeAllWindowBuffers();
        }
        break;
    }
}

u32 FilterFlyDestination(struct RegionMap* regionMap)
{
    switch (regionMap->mapSecId)
    {
    case MAPSEC_SOUTHERN_ISLAND:
        return HEAL_LOCATION_SOUTHERN_ISLAND_EXTERIOR;
    case MAPSEC_BATTLE_FRONTIER:
        return HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST;
    case MAPSEC_LITTLEROOT_TOWN:
        return (gSaveBlock2Ptr->playerGender == MALE ? HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE : HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE);
    case MAPSEC_EVER_GRANDE_CITY:
        return (FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) && regionMap->posWithinMapSec == 0 ? HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE : HEAL_LOCATION_EVER_GRANDE_CITY);
    default:
        if (sMapHealLocations[regionMap->mapSecId][2] != HEAL_LOCATION_NONE)
            return sMapHealLocations[regionMap->mapSecId][2];
        else
            return WARP_ID_NONE;
    }
}

void SetFlyDestination(struct RegionMap* regionMap)
{
    u32 flyDestination = FilterFlyDestination(regionMap);

    if (flyDestination != WARP_ID_NONE)
        SetWarpDestinationToHealLocation(flyDestination);
    else
        SetWarpDestinationToMapWarp(sMapHealLocations[regionMap->mapSecId][0], sMapHealLocations[regionMap->mapSecId][1], WARP_ID_NONE);
}

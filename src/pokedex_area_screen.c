#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex_area_screen.h"
#include "region_map.h"
#include "roamer.h"
#include "sound.h"
#include "string_util.h"
#include "trig.h"
#include "pokedex_area_region_map.h"
#include "wild_encounter.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define AREA_SCREEN_WIDTH 32
#define AREA_SCREEN_HEIGHT 20

#define GLOW_TILE_FULL          0xFFFF
#define GLOW_TILE_LEFT          (1 << 0)
#define GLOW_TILE_RIGHT         (1 << 1)
#define GLOW_TILE_TOP           (1 << 2)
#define GLOW_TILE_BOTTOM        (1 << 3)
#define GLOW_TILE_BOTTOM_RIGHT  (1 << 4)
#define GLOW_TILE_TOP_RIGHT     (1 << 5)
#define GLOW_TILE_BOTTOM_LEFT   (1 << 6)
#define GLOW_TILE_TOP_LEFT      (1 << 7)

struct PokeDexAreaScreenMapIdentity
{
    u8 mapGroup;
    u8 mapNum;
    u16 regionMapSectionId;
};

struct PokeDexAreaScreen
{
    /*0x000*/ void (*callback)(void); // unused
    /*0x004*/ MainCallback prev; // unused
    /*0x008*/ MainCallback next; // unused
    /*0x00C*/ u16 state; // unused
    /*0x00E*/ u16 species;
    /*0x010*/ struct PokeDexAreaScreenMapIdentity overworldAreasWithMons[0x40];
    /*0x110*/ u16 numOverworldAreas;
    /*0x112*/ u16 numSpecialAreas;
    /*0x114*/ u16 drawAreaGlowState;
    /*0x116*/ u16 areaGlowTilemap[0x280];
    /*0x616*/ u16 areaShadeOrMarkerFrameCounter;
    /*0x618*/ u16 areaShadeFrameCounter;
    /*0x61A*/ u16 areaShadeBldArgLo;
    /*0x61C*/ u16 areaShadeBldArgHi;
    /*0x61E*/ u8 whichMarkersFlashing;
    /*0x61F*/ u8 specialMarkerCycleCounter;
    /*0x620*/ u16 specialAreaRegionMapSectionIds[0x20];
    /*0x660*/ struct Sprite *areaMarkerSprites[0x20];
    /*0x6E0*/ u16 numAreaMarkerSprites;
    /*0x6E2*/ u16 unk6E2;
    /*0x6E4*/ u16 unk6E4;
    /*0x6E8*/ u8 *screenSwitchState;
    /*0x6EC*/ struct RegionMap regionMap;
    /*0xF70*/ u8 charBuffer[0x40];
    /*0xFB0*/ struct Sprite * areaUnknownSprites[3];
    /*0xFBC*/ u8 areaUnknownGraphicsBuffer[0x600];
};

static EWRAM_DATA struct PokeDexAreaScreen *sPokedexAreaScreen = NULL;

static void FindMapsWithMon(u16);
static void BuildAreaGlowTilemap(void);
static void SetAreaHasMon(u16, u16);
static void SetSpecialMapHasMon(u16, u16);
static u16 GetRegionMapSectionId(u8, u8);
static bool8 MapHasMon(const struct WildPokemonHeader *, u16);
static bool8 MonListHasMon(const struct WildPokemonInfo *, u16, u16);
static void DoAreaGlow(void);
static void Task_ShowPokedexAreaScreen(u8);
static void CreateAreaMarkerSprites(void);
static void LoadAreaUnknownGraphics(void);
static void CreateAreaUnknownSprites(void);
static void Task_HandlePokedexAreaScreenInput(u8);
static void sub_813D6B4(void);
static void DestroyAreaMarkerSprites(void);

static const u32 sAreaGlow_Pal[] = INCBIN_U32("graphics/pokedex/area_glow.gbapal");
static const u32 sAreaGlow_Gfx[] = INCBIN_U32("graphics/pokedex/area_glow.4bpp.lz");

static const u16 sSpeciesHiddenFromAreaScreen[] = { SPECIES_WYNAUT };

static const u16 sMovingRegionMapSections[3] =
{
    MAPSEC_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE,
    MAPSEC_TERRA_CAVE
};

static const u16 sFeebasData[][3] =
{
    {SPECIES_FEEBAS, MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119)},
    {NUM_SPECIES}
};

static const u16 sLandmarkData[][2] =
{
    {MAPSEC_SKY_PILLAR,       FLAG_LANDMARK_SKY_PILLAR},
    {MAPSEC_SEAFLOOR_CAVERN,  FLAG_LANDMARK_SEAFLOOR_CAVERN},
    {MAPSEC_ALTERING_CAVE,    FLAG_LANDMARK_ALTERING_CAVE},
    {MAPSEC_MIRAGE_TOWER,     FLAG_LANDMARK_MIRAGE_TOWER},
    {MAPSEC_DESERT_UNDERPASS, FLAG_LANDMARK_DESERT_UNDERPASS},
    {MAPSEC_ARTISAN_CAVE,     FLAG_LANDMARK_ARTISAN_CAVE},
    {MAPSEC_NONE}
};

// Only some parts of this array are acutally used, because corner flags that overlap
// with edge flags are cancelled out before lookup. For example, GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_RIGHT
// will never be read.
//
// The rest of the bytes seem to be old data from before the cancellation was implemented.
// Most of them line up as you would expect ([BOTTOM_RIGHT | RIGHT] has the same value as [RIGHT]).
//
// Any unreachable entries are simply listed in order, without the fancy "[FLAGS] = 0xXX" notation.
static const u8 sAreaGlowTilemapMapping[] = {
    [0] = 0x00,
    [GLOW_TILE_LEFT] = 0x01,
    [GLOW_TILE_RIGHT] = 0x02,
    [GLOW_TILE_RIGHT | GLOW_TILE_LEFT] = 0x03,
    [GLOW_TILE_TOP] = 0x04,
    [GLOW_TILE_TOP | GLOW_TILE_LEFT] = 0x05,
    [GLOW_TILE_TOP | GLOW_TILE_RIGHT] = 0x06,
    [GLOW_TILE_TOP | GLOW_TILE_RIGHT | GLOW_TILE_LEFT] = 0x07,
    [GLOW_TILE_BOTTOM] = 0x08,
    [GLOW_TILE_BOTTOM | GLOW_TILE_LEFT] = 0x09,
    [GLOW_TILE_BOTTOM | GLOW_TILE_RIGHT] = 0x0a,
    [GLOW_TILE_BOTTOM | GLOW_TILE_RIGHT | GLOW_TILE_LEFT] = 0x0b,
    [GLOW_TILE_BOTTOM | GLOW_TILE_TOP] = 0x0c,
    [GLOW_TILE_BOTTOM | GLOW_TILE_TOP | GLOW_TILE_LEFT] = 0x0d,
    [GLOW_TILE_BOTTOM | GLOW_TILE_TOP | GLOW_TILE_RIGHT] = 0x0e,
    [GLOW_TILE_BOTTOM | GLOW_TILE_TOP | GLOW_TILE_RIGHT | GLOW_TILE_LEFT] = 0x0f,
    [GLOW_TILE_BOTTOM_RIGHT] = 0x11,
    [GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_LEFT] = 0x20,
    0x02, 0x03,
    [GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_TOP] = 0x27,
    [GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_TOP | GLOW_TILE_LEFT] = 0x2d,
    0x06, 0x07, 0x08, 0x09, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_RIGHT] = 0x12,
    [GLOW_TILE_TOP_RIGHT | GLOW_TILE_LEFT] = 0x21,
    0x02, 0x03, 0x04, 0x05, 0x06,
    0x07,
    [GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM] = 0x2a,
    [GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM | GLOW_TILE_LEFT] = 0x2e,
    0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
    0x0f,
    [GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM_RIGHT] = 0x13,
    [GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_LEFT] = 0x22,
    0x02, 0x03, 0x27, 0x2d, 0x06,
    0x07, 0x2a, 0x2e, 0x0a, 0x0b,
    0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_BOTTOM_LEFT] = 0x14,
    0x01,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_RIGHT] = 0x23,
    0x03,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP] = 0x26,
    0x05,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP | GLOW_TILE_RIGHT] = 0x2c,
    0x07, 0x08, 0x09, 0x0a, 0x0b,
    0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_BOTTOM_RIGHT] = 0x15,
    0x20, 0x23, 0x03,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_TOP] = 0x28,
    0x2d, 0x2c, 0x07, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
    0x0f,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP_RIGHT] = 0x16,
    0x21, 0x23, 0x03, 0x26, 0x05,
    0x2c, 0x07, 0x2a, 0x2e, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM_RIGHT] = 0x17,
    0x22, 0x23, 0x03, 0x28, 0x2d,
    0x2c, 0x07, 0x2a, 0x2e, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT] = 0x18,
    0x01,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_RIGHT] = 0x24,
    0x03, 0x04, 0x05, 0x06, 0x07,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM] = 0x29,
    0x09,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM | GLOW_TILE_RIGHT] = 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_RIGHT] = 0x19,
    0x20, 0x24, 0x03, 0x27, 0x2d,
    0x06, 0x07, 0x29, 0x09, 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_TOP_RIGHT] = 0x1a,
    0x21, 0x24, 0x03, 0x04, 0x05,
    0x06, 0x07,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM] = 0x2b,
    0x2e, 0x2f, 0x0b, 0x0c, 0x0d,
    0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM_RIGHT] = 0x1b,
    0x22, 0x24, 0x03, 0x27, 0x2d,
    0x06, 0x07, 0x2b, 0x2e, 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_LEFT] = 0x1c,
    0x01,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_RIGHT] = 0x25,
    0x03, 0x26, 0x05, 0x2c, 0x07,
    0x29, 0x09, 0x2f, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_BOTTOM_RIGHT] = 0x1d,
    0x20, 0x25, 0x03, 0x28, 0x2d,
    0x2c, 0x07, 0x29, 0x09, 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP_RIGHT] = 0x1e,
    0x21, 0x25, 0x03, 0x26, 0x05,
    0x2c, 0x07, 0x2b, 0x2e, 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    [GLOW_TILE_TOP_LEFT | GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP_RIGHT | GLOW_TILE_BOTTOM_RIGHT] = 0x1f,
    0x22, 0x25, 0x03, 0x28, 0x2d,
    0x2c, 0x07, 0x2b, 0x2e, 0x2f,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
};

static const struct PokedexAreaMapTemplate sPokedexAreaMapTemplate =
{
    .bg = 3,
    .offset = 0,
    .mode = 0,
    .unk = 2,
};

static const u8 sAreaMarkerTiles[];
static const struct SpriteSheet sAreaMarkerSpriteSheet =
{
    sAreaMarkerTiles, 0x80, 2
};

static const u16 sAreaMarkerPalette[];
static const struct SpritePalette sAreaMarkerSpritePalette =
{
    sAreaMarkerPalette, 2
};

static const struct OamData sAreaMarkerOamData =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1
};

static const struct SpriteTemplate sAreaMarkerSpriteTemplate =
{
    2,
    2,
    &sAreaMarkerOamData,
    gDummySpriteAnimTable,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const u16 sAreaMarkerPalette[] = INCBIN_U16("graphics/pokedex/area_marker.gbapal");
static const u8 sAreaMarkerTiles[] = INCBIN_U8("graphics/pokedex/area_marker.4bpp");

static const struct SpritePalette sAreaUnknownSpritePalette =
{
    gPokedexAreaScreenAreaUnknown_Pal, 3
};

static const struct OamData sAreaUnknownOamData =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1
};

static const struct SpriteTemplate sAreaUnknownSpriteTemplate =
{
    3,
    3,
    &sAreaUnknownOamData,
    gDummySpriteAnimTable,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static void ResetDrawAreaGlowState(void)
{
    sPokedexAreaScreen->drawAreaGlowState = 0;
}

static bool8 DrawAreaGlow(void)
{
    switch (sPokedexAreaScreen->drawAreaGlowState)
    {
    case 0:
        FindMapsWithMon(sPokedexAreaScreen->species);
        break;
    case 1:
        BuildAreaGlowTilemap();
        break;
    case 2:
        DecompressAndCopyTileDataToVram(2, sAreaGlow_Gfx, 0, 0, 0);
        LoadBgTilemap(2, sPokedexAreaScreen->areaGlowTilemap, 0x500, 0);
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            CpuCopy32(sAreaGlow_Pal, gPlttBufferUnfaded + 0xA0, 0x20);
            sPokedexAreaScreen->drawAreaGlowState++;
        }
        return TRUE;
    case 4:
        ChangeBgY(2, -0x800, 0);
        break;
    default:
        return FALSE;
    }

    sPokedexAreaScreen->drawAreaGlowState++;
    return TRUE;
}

static void FindMapsWithMon(u16 species)
{
    u16 i;
    struct Roamer *roamer;

    sPokedexAreaScreen->unk6E2 = 0;
    sPokedexAreaScreen->unk6E4 = VarGet(VAR_ALTERING_CAVE_WILD_SET);
    if (sPokedexAreaScreen->unk6E4 > 8)
        sPokedexAreaScreen->unk6E4 = 0;

    roamer = &gSaveBlock1Ptr->roamer;
    if (species != roamer->species)
    {
        sPokedexAreaScreen->numOverworldAreas = 0;
        sPokedexAreaScreen->numSpecialAreas = 0;
        for (i = 0; i < ARRAY_COUNT(sSpeciesHiddenFromAreaScreen); i++)
        {
            if (sSpeciesHiddenFromAreaScreen[i] == species)
                return;
        }

        for (i = 0; sFeebasData[i][0] != NUM_SPECIES; i++)
        {
            if (species == sFeebasData[i][0])
            {
                switch (sFeebasData[i][1])
                {
                    case MAP_GROUP_OVERWORLD_MONS:
                        SetAreaHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                        break;
                    case MAP_GROUP_SPECIAL_MONS_1:
                    case MAP_GROUP_SPECIAL_MONS_2:
                        SetSpecialMapHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                        break;
                }
            }
        }

        for (i = 0; gWildMonHeaders[i].mapGroup != 0xFF; i++)
        {
            if (MapHasMon(&gWildMonHeaders[i], species))
            {
                switch (gWildMonHeaders[i].mapGroup)
                {
                    case MAP_GROUP_OVERWORLD_MONS:
                        SetAreaHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                        break;
                    case MAP_GROUP_SPECIAL_MONS_1:
                    case MAP_GROUP_SPECIAL_MONS_2:
                        SetSpecialMapHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                        break;
                }
            }
        }
    }
    else
    {
        sPokedexAreaScreen->numSpecialAreas = 0;
        if (roamer->active)
        {
            GetRoamerLocation(&sPokedexAreaScreen->overworldAreasWithMons[0].mapGroup, &sPokedexAreaScreen->overworldAreasWithMons[0].mapNum);
            sPokedexAreaScreen->overworldAreasWithMons[0].regionMapSectionId = Overworld_GetMapHeaderByGroupAndId(sPokedexAreaScreen->overworldAreasWithMons[0].mapGroup, sPokedexAreaScreen->overworldAreasWithMons[0].mapNum)->regionMapSectionId;
            sPokedexAreaScreen->numOverworldAreas = 1;
        }
        else
        {
            sPokedexAreaScreen->numOverworldAreas = 0;
        }
    }
}

static void SetAreaHasMon(u16 mapGroup, u16 mapNum)
{
    if (sPokedexAreaScreen->numOverworldAreas < 0x40)
    {
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].mapGroup = mapGroup;
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].mapNum = mapNum;
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].regionMapSectionId = CorrectSpecialMapSecId(Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId);
        sPokedexAreaScreen->numOverworldAreas++;
    }
}

static void SetSpecialMapHasMon(u16 mapGroup, u16 mapNum)
{
    int i;

    if (sPokedexAreaScreen->numSpecialAreas < 0x20)
    {
        u16 regionMapSectionId = GetRegionMapSectionId(mapGroup, mapNum);
        if (regionMapSectionId < MAPSEC_NONE)
        {
            for (i = 0; i < ARRAY_COUNT(sMovingRegionMapSections); i++)
            {
                if (regionMapSectionId == sMovingRegionMapSections[i])
                    return;
            }

            for (i = 0; sLandmarkData[i][0] != MAPSEC_NONE; i++)
            {
                if (regionMapSectionId == sLandmarkData[i][0] && !FlagGet(sLandmarkData[i][1]))
                    return;
            }

            for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
            {
                if (sPokedexAreaScreen->specialAreaRegionMapSectionIds[i] == regionMapSectionId)
                    break;
            }

            if (i == sPokedexAreaScreen->numSpecialAreas)
            {
                sPokedexAreaScreen->specialAreaRegionMapSectionIds[i] = regionMapSectionId;
                sPokedexAreaScreen->numSpecialAreas++;
            }
        }
    }
}

static u16 GetRegionMapSectionId(u8 mapGroup, u8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}

static bool8 MapHasMon(const struct WildPokemonHeader *info, u16 species)
{
    if (GetRegionMapSectionId(info->mapGroup, info->mapNum) == MAPSEC_ALTERING_CAVE)
    {
        sPokedexAreaScreen->unk6E2++;
        if (sPokedexAreaScreen->unk6E2 != sPokedexAreaScreen->unk6E4 + 1)
            return FALSE;
    }

    if (MonListHasMon(info->landMonsInfo, species, 12))
        return TRUE;
    if (MonListHasMon(info->waterMonsInfo, species, 5))
        return TRUE;
    if (MonListHasMon(info->fishingMonsInfo, species, 12))
        return TRUE;
    if (MonListHasMon(info->rockSmashMonsInfo, species, 5))
        return TRUE;
    return FALSE;
}

static bool8 MonListHasMon(const struct WildPokemonInfo *info, u16 species, u16 size)
{
    u16 i;
    if (info != NULL)
    {
        for (i = 0; i < size; i++)
        {
            if (info->wildPokemon[i].species == species)
                return TRUE;
        }
    }
    return FALSE;
}

static void BuildAreaGlowTilemap(void)
{
    u16 i, y, x, j;
    u16 val;

    for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaGlowTilemap); i++)
        sPokedexAreaScreen->areaGlowTilemap[i] = 0;

    for (i = 0; i < sPokedexAreaScreen->numOverworldAreas; i++)
    {
        j = 0;
        for (y = 0; y < AREA_SCREEN_HEIGHT; y++)
        {
            for (x = 0; x < AREA_SCREEN_WIDTH; x++)
            {
                if (GetRegionMapSecIdAt(x, y) == sPokedexAreaScreen->overworldAreasWithMons[i].regionMapSectionId)
                    sPokedexAreaScreen->areaGlowTilemap[j] = GLOW_TILE_FULL;

                j++;
            }
        }
    }

    j = 0;
    for (y = 0; y < AREA_SCREEN_HEIGHT; y++)
    {
        for (x = 0; x < AREA_SCREEN_WIDTH; x++)
        {
            if (sPokedexAreaScreen->areaGlowTilemap[j] == GLOW_TILE_FULL)
            {
                // The "tile != GLOW_TILE_FULL" check is pointless in all of these conditionals,
                // since there's no harm in OR'ing 0xFFFF with anything else.

                // Edges
                if (x != 0 && sPokedexAreaScreen->areaGlowTilemap[j - 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - 1] |= GLOW_TILE_RIGHT;
                if (x != AREA_SCREEN_WIDTH - 1 && sPokedexAreaScreen->areaGlowTilemap[j + 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + 1] |= GLOW_TILE_LEFT;
                if (y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH] |= GLOW_TILE_BOTTOM;
                if (y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH] |= GLOW_TILE_TOP;
                
                // Diagonals
                if (x != 0 && y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH - 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH - 1] |= GLOW_TILE_BOTTOM_RIGHT;
                if (x != AREA_SCREEN_WIDTH - 1 && y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH + 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH + 1] |= GLOW_TILE_BOTTOM_LEFT;
                if (x != 0 && y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH - 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH - 1] |= GLOW_TILE_TOP_RIGHT;
                if (x != AREA_SCREEN_WIDTH - 1 && y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH + 1] != GLOW_TILE_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH + 1] |= GLOW_TILE_TOP_LEFT;
            }

            j++;
        }
    }

    for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaGlowTilemap); i++)
    {
        if (sPokedexAreaScreen->areaGlowTilemap[i] == GLOW_TILE_FULL)
        {
            sPokedexAreaScreen->areaGlowTilemap[i] = 0x10;
            sPokedexAreaScreen->areaGlowTilemap[i] |= 0xA000;
        }
        else if (sPokedexAreaScreen->areaGlowTilemap[i])
        {
            // Get rid of overlapping flags
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_TILE_RIGHT)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_TILE_BOTTOM_RIGHT | GLOW_TILE_TOP_RIGHT);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_TILE_LEFT)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_TOP_LEFT);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_TILE_BOTTOM)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_TILE_BOTTOM_LEFT | GLOW_TILE_BOTTOM_RIGHT);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_TILE_TOP)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_TILE_TOP_LEFT | GLOW_TILE_TOP_RIGHT);

            sPokedexAreaScreen->areaGlowTilemap[i] = sAreaGlowTilemapMapping[sPokedexAreaScreen->areaGlowTilemap[i]];
            sPokedexAreaScreen->areaGlowTilemap[i] |= 0xA000;
        }
    }
}

static void StartAreaGlow(void)
{
    if (sPokedexAreaScreen->numSpecialAreas && sPokedexAreaScreen->numOverworldAreas == 0)
        sPokedexAreaScreen->whichMarkersFlashing = 1;
    else
        sPokedexAreaScreen->whichMarkersFlashing = 0;

    sPokedexAreaScreen->areaShadeOrMarkerFrameCounter = 0;
    sPokedexAreaScreen->areaShadeFrameCounter = 0;
    sPokedexAreaScreen->areaShadeBldArgLo = 0;
    sPokedexAreaScreen->areaShadeBldArgHi = 0x40;
    sPokedexAreaScreen->specialMarkerCycleCounter = 1;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    DoAreaGlow();
}

static void DoAreaGlow(void)
{
    u16 x, y;
    u16 i;

    if (sPokedexAreaScreen->whichMarkersFlashing == 0)
    {
        if (sPokedexAreaScreen->areaShadeOrMarkerFrameCounter == 0)
        {
            sPokedexAreaScreen->areaShadeFrameCounter++;
            if (sPokedexAreaScreen->areaShadeFrameCounter & 1)
                sPokedexAreaScreen->areaShadeBldArgLo = (sPokedexAreaScreen->areaShadeBldArgLo + 4) & 0x7f;
            else
                sPokedexAreaScreen->areaShadeBldArgHi = (sPokedexAreaScreen->areaShadeBldArgHi + 4) & 0x7f;

            x = gSineTable[sPokedexAreaScreen->areaShadeBldArgLo] >> 4;
            y = gSineTable[sPokedexAreaScreen->areaShadeBldArgHi] >> 4;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(x, y));
            sPokedexAreaScreen->areaShadeOrMarkerFrameCounter = 0;
            if (sPokedexAreaScreen->areaShadeFrameCounter == 0x40)
            {
                sPokedexAreaScreen->areaShadeFrameCounter = 0;
                if (sPokedexAreaScreen->numSpecialAreas != 0)
                    sPokedexAreaScreen->whichMarkersFlashing = 1;
            }
        }
        else
            sPokedexAreaScreen->areaShadeOrMarkerFrameCounter--;
    }
    else
    {
        sPokedexAreaScreen->areaShadeOrMarkerFrameCounter++;
        if (sPokedexAreaScreen->areaShadeOrMarkerFrameCounter > 12)
        {
            sPokedexAreaScreen->areaShadeOrMarkerFrameCounter = 0;
            sPokedexAreaScreen->specialMarkerCycleCounter++;
            for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
                sPokedexAreaScreen->areaMarkerSprites[i]->invisible = sPokedexAreaScreen->specialMarkerCycleCounter & 1;

            if (sPokedexAreaScreen->specialMarkerCycleCounter > 4)
            {
                sPokedexAreaScreen->specialMarkerCycleCounter = 1;
                if (sPokedexAreaScreen->numOverworldAreas != 0)
                    sPokedexAreaScreen->whichMarkersFlashing = 0;
            }
        }
    }
}

#define tState data[0]

void ShowPokedexAreaScreen(u16 species, u8 *screenSwitchState)
{
    u8 taskId;

    sPokedexAreaScreen = AllocZeroed(sizeof(*sPokedexAreaScreen));
    sPokedexAreaScreen->species = species;
    sPokedexAreaScreen->screenSwitchState = screenSwitchState;
    screenSwitchState[0] = 0;
    taskId = CreateTask(Task_ShowPokedexAreaScreen, 0);
    gTasks[taskId].tState = 0;
}

static void Task_ShowPokedexAreaScreen(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
        case 0:
            ResetSpriteData();
            FreeAllSpritePalettes();
            HideBg(3);
            HideBg(2);
            HideBg(0);
            break;
        case 1:
            SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 3);
            LoadPokedexAreaMapGfx(&sPokedexAreaMapTemplate);
            StringFill(sPokedexAreaScreen->charBuffer, CHAR_SPACE, 16);
            break;
        case 2:
            if (sub_81C4E90() == TRUE)
                return;
            PokedexAreaMapChangeBgY(-8);
            break;
        case 3:
            ResetDrawAreaGlowState();
            break;
        case 4:
            if (DrawAreaGlow())
                return;
            break;
        case 5:
            ShowRegionMapForPokedexAreaScreen(&sPokedexAreaScreen->regionMap);
            CreateRegionMapPlayerIcon(1, 1);
            PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(0, -8);
            break;
        case 6:
            CreateAreaMarkerSprites();
            break;
        case 7:
            LoadAreaUnknownGraphics();
            break;
        case 8:
            CreateAreaUnknownSprites();
            break;
        case 9:
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 16, 0, RGB(0, 0, 0));
            break;
        case 10:
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_ALL);
            StartAreaGlow();
            ShowBg(2);
            ShowBg(3);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
            break;
        case 11:
            gTasks[taskId].func = Task_HandlePokedexAreaScreenInput;
            gTasks[taskId].tState = 0;
            return;
    }

    gTasks[taskId].tState++;
}

static void Task_HandlePokedexAreaScreenInput(u8 taskId)
{
    DoAreaGlow();
    switch (gTasks[taskId].tState)
    {
    default:
        gTasks[taskId].tState = 0;
        // fall through
    case 0:
        if (gPaletteFade.active)
            return;
        break;
    case 1:
        if (JOY_NEW(B_BUTTON))
        {
            gTasks[taskId].data[1] = 1;
            PlaySE(SE_PC_OFF);
        }
        else if (JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            gTasks[taskId].data[1] = 2;
            PlaySE(SE_DEX_PAGE);
        }
        else
            return;
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 16, RGB_BLACK);
        break;
    case 3:
        if (gPaletteFade.active)
            return;
        DestroyAreaMarkerSprites();
        sPokedexAreaScreen->screenSwitchState[0] = gTasks[taskId].data[1];
        sub_813D6B4();
        DestroyTask(taskId);
        FreePokedexAreaMapBgNum();
        FREE_AND_SET_NULL(sPokedexAreaScreen);
        return;
    }

    gTasks[taskId].tState++;
}

static void sub_813D6B4(void)
{
    SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 0);
    SetBgAttribute(3, BG_ATTR_PALETTEMODE, 0);
}

static void CreateAreaMarkerSprites(void)
{
    u8 spriteId;
    static s16 x;
    static s16 y;
    static s16 i;
    static s16 mapSecId;
    static s16 numSprites;

    LoadSpriteSheet(&sAreaMarkerSpriteSheet);
    LoadSpritePalette(&sAreaMarkerSpritePalette);
    numSprites = 0;
    for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
    {
        mapSecId = sPokedexAreaScreen->specialAreaRegionMapSectionIds[i];
        x = 8 * (gRegionMapEntries[mapSecId].x + 1) + 4;
        y = 8 * (gRegionMapEntries[mapSecId].y) + 28;
        x += 4 * (gRegionMapEntries[mapSecId].width - 1);
        y += 4 * (gRegionMapEntries[mapSecId].height - 1);
        spriteId = CreateSprite(&sAreaMarkerSpriteTemplate, x, y, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].invisible = TRUE;
            sPokedexAreaScreen->areaMarkerSprites[numSprites++] = &gSprites[spriteId];
        }
    }

    sPokedexAreaScreen->numAreaMarkerSprites = numSprites;
}

static void DestroyAreaMarkerSprites(void)
{
    u16 i;
    FreeSpriteTilesByTag(2);
    FreeSpritePaletteByTag(2);
    for (i = 0; i < sPokedexAreaScreen->numAreaMarkerSprites; i++)
        DestroySprite(sPokedexAreaScreen->areaMarkerSprites[i]);

    FreeSpriteTilesByTag(3);
    FreeSpritePaletteByTag(3);
    for (i = 0; i < 3; i++)
    {
        if (sPokedexAreaScreen->areaUnknownSprites[i])
            DestroySprite(sPokedexAreaScreen->areaUnknownSprites[i]);
    }
}

static void LoadAreaUnknownGraphics(void)
{
    struct SpriteSheet spriteSheet = {
        .data = sPokedexAreaScreen->areaUnknownGraphicsBuffer,
        .size = 0x600,
        .tag = 3,
    };
    LZ77UnCompWram(gPokedexAreaScreenAreaUnknown_Gfx, sPokedexAreaScreen->areaUnknownGraphicsBuffer);
    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&sAreaUnknownSpritePalette);
}

static void CreateAreaUnknownSprites(void)
{
    u16 i;
    u8 spriteId;

    if (sPokedexAreaScreen->numOverworldAreas || sPokedexAreaScreen->numSpecialAreas)
    {
        for (i = 0; i < 3; i++)
            sPokedexAreaScreen->areaUnknownSprites[i] = NULL;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            spriteId = CreateSprite(&sAreaUnknownSpriteTemplate, i * 32 + 0xa0, 0x8c, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.tileNum += i * 16;
                sPokedexAreaScreen->areaUnknownSprites[i] = gSprites + spriteId;
            }
            else
            {
                sPokedexAreaScreen->areaUnknownSprites[i] = NULL;
            }
        }
    }
}

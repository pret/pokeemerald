#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_area_region_map.h"
#include "regions.h"
#include "region_map.h"

#define POKEDEX_AREA_MAP_BG 3

void LoadPokedexAreaMapGfx(void)
{
    enum RegionMapType regionMapType = GetRegionMapType(gMapHeader.regionMapSectionId);

    SetBgAttribute(POKEDEX_AREA_MAP_BG, BG_ATTR_METRIC, 0);
    DecompressAndCopyTileDataToVram(POKEDEX_AREA_MAP_BG, gRegionMapInfos[regionMapType].dexMapGfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(POKEDEX_AREA_MAP_BG, gRegionMapInfos[regionMapType].dexMapTilemap, 0, 0, 1);

    ChangeBgX(POKEDEX_AREA_MAP_BG, 0, BG_COORD_SET);
    ChangeBgY(POKEDEX_AREA_MAP_BG, 0, BG_COORD_SET);
    SetBgAttribute(POKEDEX_AREA_MAP_BG, BG_ATTR_PALETTEMODE, 1);
    CpuCopy32(gRegionMapInfos[regionMapType].dexMapPalette, &gPlttBufferUnfaded[BG_PLTT_ID(7)], gRegionMapInfos[regionMapType].dexMapPaletteSize);
}

bool32 TryShowPokedexAreaMap(void)
{
    if (!FreeTempTileDataBuffersIfPossible())
    {
        ShowBg(POKEDEX_AREA_MAP_BG);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void PokedexAreaMapChangeBgY(u32 move)
{
    ChangeBgY(POKEDEX_AREA_MAP_BG, move * 0x100, BG_COORD_SET);
}

#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_area_region_map.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

static const u16 sPokedexAreaMap_Pal[] = INCBIN_U16("graphics/pokedex/region_map.gbapal");
static const u32 sPokedexAreaMap_Gfx[] = INCBIN_U32("graphics/pokedex/region_map.8bpp.lz");
static const u32 sPokedexAreaMap_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map.bin.lz");
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_affine.8bpp.lz");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_affine.bin.lz");

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *template)
{
    u8 mode;
    void * tilemap;
    sPokedexAreaMapBgNum = Alloc(sizeof(sPokedexAreaMapBgNum));
    mode = template->mode;

    if (mode == 0)
    {
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 0);
        DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMap_Gfx, 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMap_Tilemap, 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 32, 32, FALSE); // template->offset is always 0, so this does nothing.
    }
    else
    {
        // This is never reached, only a mode of 0 is given
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 2);
        SetBgAttribute(template->bg, BG_ATTR_TYPE, BG_TYPE_AFFINE); // This does nothing. BG_ATTR_TYPE can't be set with this function
        DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Gfx, 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Tilemap, 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 64, 64, TRUE); // template->offset is always 0, so this does nothing.
    }

    ChangeBgX(template->bg, 0, BG_COORD_SET);
    ChangeBgY(template->bg, 0, BG_COORD_SET);
    SetBgAttribute(template->bg, BG_ATTR_PALETTEMODE, 1);
    CpuCopy32(sPokedexAreaMap_Pal, &gPlttBufferUnfaded[0x70], sizeof(sPokedexAreaMap_Pal));
    *sPokedexAreaMapBgNum = template->bg;
}

bool32 TryShowPokedexAreaMap(void)
{
    if (!FreeTempTileDataBuffersIfPossible())
    {
        ShowBg(*sPokedexAreaMapBgNum);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void FreePokedexAreaMapBgNum(void)
{
    TRY_FREE_AND_SET_NULL(sPokedexAreaMapBgNum);
}

void PokedexAreaMapChangeBgY(u32 move)
{
    ChangeBgY(*sPokedexAreaMapBgNum, move * 0x100, BG_COORD_SET);
}

#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_area_region_map.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

static const u16 sPokedexAreaMap_Pal[] = INCBIN_U16("graphics/interface/region_map.gbapal");
static const u32 sPokedexAreaMap_Gfx[] = INCBIN_U32("graphics/interface/region_map.8bpp.lz");
static const u32 sPokedexAreaMap_Tilemap[] = INCBIN_U32("graphics/interface/region_map.bin.lz");
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/interface/region_map_affine.8bpp.lz");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/interface/region_map_affine.bin.lz");

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *template)
{
    u8 mode;
    sPokedexAreaMapBgNum = Alloc(4);
    mode = template->mode;

    if (mode == 0)
    {
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 0);
        decompress_and_copy_tile_data_to_vram(template->bg, sPokedexAreaMap_Gfx, 0, template->offset, 0);
        sub_8199D3C(decompress_and_copy_tile_data_to_vram(template->bg, sPokedexAreaMap_Tilemap, 0, 0, 1), template->offset, 32, 32, FALSE);
    }
    else
    {
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 2);
        SetBgAttribute(template->bg, BG_ATTR_TYPE, 1);
        decompress_and_copy_tile_data_to_vram(template->bg, sPokedexAreaMapAffine_Gfx, 0, template->offset, 0);
        sub_8199D3C(decompress_and_copy_tile_data_to_vram(template->bg, sPokedexAreaMapAffine_Tilemap, 0, 0, 1), template->offset, 64, 64, TRUE);
    }

    ChangeBgX(template->bg, 0, 0);
    ChangeBgY(template->bg, 0, 0);
    SetBgAttribute(template->bg, BG_ATTR_PALETTEMODE, 1);
    CpuCopy32(sPokedexAreaMap_Pal, &gPlttBufferUnfaded[0x70], 0x60);
    *sPokedexAreaMapBgNum = template->bg;
}

bool32 sub_81C4E90(void)
{
    if (!free_temp_tile_data_buffers_if_possible())
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
    if (sPokedexAreaMapBgNum != NULL)
        FREE_AND_SET_NULL(sPokedexAreaMapBgNum);
}

void PokedexAreaMapChangeBgY(u32 a0)
{
    ChangeBgY(*sPokedexAreaMapBgNum, a0 * 0x100, 0);
}

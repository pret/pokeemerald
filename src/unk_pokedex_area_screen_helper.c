#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"

EWRAM_DATA u8 *gUnknown_0203CF28 = NULL;

static const u16 gUnknown_0861D140[] = INCBIN_U16("graphics/interface/region_map.gbapal");
static const u32 gUnknown_0861D1A0[] = INCBIN_U32("graphics/interface/region_map.8bpp.lz");
static const u32 gUnknown_0861DEF4[] = INCBIN_U32("graphics/interface/region_map.bin.lz");
static const u32 gUnknown_0861E208[] = INCBIN_U32("graphics/interface/region_map_affine.8bpp.lz");
static const u32 gUnknown_0861EF64[] = INCBIN_U32("graphics/interface/region_map_affine.bin.lz");

struct UnkStruct_1C4D70
{
    u32 bg:2;
    u32 unk2:8;
    u32 unk10:2;
    u32 unk12:20;
};

void sub_81C4D70(struct UnkStruct_1C4D70 *template)
{
    u8 unk;
    gUnknown_0203CF28 = Alloc(4);
    unk = template->unk10;

    if (unk == 0)
    {
        SetBgAttribute(template->bg, BG_CTRL_ATTR_WRAPAROUND, 0);
        decompress_and_copy_tile_data_to_vram(template->bg, gUnknown_0861D1A0, 0, template->unk2, unk);
        sub_8199D3C(decompress_and_copy_tile_data_to_vram(template->bg, gUnknown_0861DEF4, 0, 0, 1), template->unk2, 32, 32, unk);
    }
    else
    {
        SetBgAttribute(template->bg, BG_CTRL_ATTR_WRAPAROUND, 2);
        SetBgAttribute(template->bg, 9, 1);
        decompress_and_copy_tile_data_to_vram(template->bg, gUnknown_0861E208, 0, template->unk2, 0);
        sub_8199D3C(decompress_and_copy_tile_data_to_vram(template->bg, gUnknown_0861EF64, 0, 0, 1), template->unk2, 64, 64, 1);
    }

    ChangeBgX(template->bg, 0, 0);
    ChangeBgY(template->bg, 0, 0);
    SetBgAttribute(template->bg, BG_CTRL_ATTR_SCREENSIZE, 1);
    CpuCopy32(gUnknown_0861D140, &gPlttBufferUnfaded[0x70], 0x60);
    *gUnknown_0203CF28 = template->bg;
}

bool32 sub_81C4E90(void)
{
    if (!free_temp_tile_data_buffers_if_possible())
    {
        ShowBg(*gUnknown_0203CF28);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void sub_81C4EB4(void)
{
    if (gUnknown_0203CF28 != NULL)
    {
        FREE_AND_SET_NULL(gUnknown_0203CF28);
    }
}

void sub_81C4ED0(u32 a0)
{
    ChangeBgY(*gUnknown_0203CF28, a0 * 0x100, 0);
}

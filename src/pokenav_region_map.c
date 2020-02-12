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
#include "constants/songs.h"

struct Pokenav5Struct
{
    u8 filler0[0xC];
    bool32 unkC;
    u32 (*unk10)(struct Pokenav5Struct *);
};

struct Pokenav5Struct_2
{
    bool32 (*unk0)(void);
    u32 unk4;
    u16 unk8;
    struct Sprite *cityFeatureTextSprites[3];
    u8 unk18[0x800];
    u8 cityZoomPics[22][0xC8];
};

struct CityMapEntry
{
    u16 mapSecId;
    u16 index;
    const u32 *tilemap;
};

static u32 sub_81CC568(struct Pokenav5Struct *);
static u32 sub_81CC5B4(struct Pokenav5Struct *);
static u32 sub_81CC5DC(struct Pokenav5Struct *);
static u32 sub_81CC6F4(s32);
static u32 sub_81CCD34(s32);
static bool32 sub_81CC6BC(void);
static void sub_81CC9EC(void);
static void sub_81CC9C0(void);
static void sub_81CCD10(void);
static bool32 sub_81CCD24(void);
static void sub_81CCA1C(struct Pokenav5Struct_2 *);
static bool32 sub_81CCAFC(void);
static void sub_81CCB0C(struct Pokenav5Struct_2 *);
static bool32 sub_81CCC4C(struct Pokenav5Struct_2 *);
static void sub_81CCC5C(int);
static bool32 sub_81CCC88(void);
static void sub_81CCE58(void);
static void sub_81CCD70(struct Pokenav5Struct_2 *, int, int);
static void sub_81CCDE8(struct Pokenav5Struct_2 *, int, int);
static void sub_81CCFA4(int);
static void sub_81CCC9C(u8 taskId);
static void sub_81CCF78(void);
void sub_81CCEF4(struct Sprite *sprite);
u32 sub_81CC848(s32);
u32 sub_81CC878(s32);
u32 sub_81CC8D8(s32);
u32 sub_81CC95C(s32);

extern const u16 gHoennMapZoomIcons_Pal[];
extern const struct SpriteTemplate gUnknown_086231D0;
extern const u32 gHoennMapZoomIcons_Gfx[];

const u16 gUnknown_08622868[] = INCBIN_U16("graphics/pokenav/8622868.gbapal");
const u32 gUnknown_08622888[] = INCBIN_U32("graphics/pokenav/zoom_tiles.4bpp.lz");

#include "data/region_map/city_map_tilemaps.h"


const struct BgTemplate gUnknown_086230D8[3] = 
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

const LoopedTask gUnknown_086230E4[] = 
{
    NULL,
    sub_81CC848,
    sub_81CC878,
    sub_81CC8D8,
    sub_81CC95C
};

const struct CompressedSpriteSheet gUnknown_086230F8[1] = 
{
    {gHoennMapZoomIcons_Gfx, 0x800, 6}
};

const struct SpritePalette gUnknown_08623100[] = 
{
    {gHoennMapZoomIcons_Pal, 11},
    {}
};

const struct WindowTemplate gUnknown_08623110 = 
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

const struct OamData gUnknown_086231C8 = 
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

const struct SpriteTemplate gUnknown_086231D0 =
{
    .tileTag = 6,
    .paletteTag = 11,
    .oam = &gUnknown_086231C8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81CCEF4,
};

u32 PokenavCallback_Init_6(void)
{
    struct Pokenav5Struct *state = AllocSubstruct(3, sizeof(struct Pokenav5Struct));
    if (!state)
        return FALSE;

    if (!AllocSubstruct(16, sizeof(struct RegionMap)))
        return FALSE;

    state->unkC = sub_8124668(gMapHeader.regionMapSectionId);
    if (!state->unkC)
        state->unk10 = sub_81CC568;
    else
        state->unk10 = sub_81CC5B4;

    return TRUE;
}

void sub_81CC524(void)
{
    gSaveBlock2Ptr->regionMapZoom = sub_8124658();
    FreePokenavSubstruct(16);
    FreePokenavSubstruct(3);
}

u32 sub_81CC554(void)
{
    struct Pokenav5Struct *state = GetSubstructPtr(3);
    return state->unk10(state);
}

static u32 sub_81CC568(struct Pokenav5Struct *state)
{
    switch (sub_81230AC())
    {
    case 3:
        return 1;
    case 4:
        if (!sub_8124658())
            return 3;
        return 2;
    case 5:
        state->unk10 = sub_81CC5DC;
        return 4;
    }

    return 0;
}

static u32 sub_81CC5B4(struct Pokenav5Struct *state)
{
    if (gMain.newKeys & B_BUTTON)
    {
        state->unk10 = sub_81CC5DC;
        return 4;
    }

    return 0;
}

static u32 sub_81CC5DC(struct Pokenav5Struct *state)
{
    return POKENAV_MENU_1;
}

bool32 sub_81CC5E4(void)
{
    struct Pokenav5Struct *state = GetSubstructPtr(3);
    return state->unkC;
}

bool32 sub_81CC5F4(void)
{
    struct Pokenav5Struct_2 *state = AllocSubstruct(4, sizeof(struct Pokenav5Struct_2));
    if (!state)
        return FALSE;

    state->unk4 = CreateLoopedTask(sub_81CC6F4, 1);
    state->unk0 = sub_81CC6BC;
    return TRUE;
}

void sub_81CC62C(s32 index)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    state->unk4 = CreateLoopedTask(gUnknown_086230E4[index], 1);
    state->unk0 = sub_81CC6BC;
}

u32 sub_81CC65C(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    return state->unk0();
}

void sub_81CC670(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    FreeRegionMapIconResources();
    sub_81CC9EC();
    RemoveWindow(state->unk8);
    FreePokenavSubstruct(16);
    FreePokenavSubstruct(4);
    SetPokenavVBlankCallback();
    SetBgMode(0);
}

static void sub_81CC6A4(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    UpdateRegionMapVideoRegs();
}

static bool32 sub_81CC6BC(void)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    return IsLoopedTaskActive(state->unk4);
}

static bool8 sub_81CC6D0(void)
{
    if (sub_81CC5E4())
        return FALSE;

    return gSaveBlock2Ptr->regionMapZoom == 1;
}

static u32 sub_81CC6F4(s32 taskState)
{
    int var0;
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
        InitBgTemplates(gUnknown_086230D8, ARRAY_COUNT(gUnknown_086230D8) - 1);
        regionMap = GetSubstructPtr(16);
        sub_8122CF8(regionMap, &gUnknown_086230D8[1], sub_81CC6D0());
        sub_81CC9C0();
        return 0;
    case 1:
        if (sub_8122DB0())
            return 2;

        if (!sub_81CC5E4())
        {
            CreateRegionMapPlayerIcon(4, 9);
            CreateRegionMapCursor(5, 10);
            sub_812454C();
        }
        else
        {
            sub_8123030(0, 6);
        }
        return 0;
    case 2:
        sub_81CCD10();
        return 1;
    case 3:
        if (sub_81CCD24())
            return 2;

        sub_81CCA1C(state);
        return 1;
    case 4:
        if (sub_81CCAFC())
            return 2;

        sub_81CCB0C(state);
        sub_81C7B40();
        return 0;
    case 5:
        if (sub_81CCC4C(state))
            return 2;

        ShowBg(1);
        ShowBg(2);
        SetVBlankCallback_(sub_81CC6A4);
        return 0;
    case 6:
        if (!sub_81CC6D0())
            var0 = 4;
        else
            var0 = 5;

        LoadLeftHeaderGfxForIndex(var0);
        sub_81C7FA0(var0, 1, 1);
        sub_81C7AC0(1);
        return 0;
    case 7:
        if (IsPaletteFadeActive() || sub_81C8010())
            return 2;
        return 1;
    default:
        return 4;
    }
}

u32 sub_81CC848(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    switch (taskState)
    {
    case 0:
        sub_81CCB0C(state);
        return 0;
    case 1:
        if (sub_81CCC4C(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CC878(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CCC5C(0);
        sub_8123418();
        return 0;
    case 1:
        if (sub_8123514() || sub_81CCC88())
            return 2;

        PrintHelpBarText(HELPBAR_MAP_ZOOMED_OUT);
        return 0;
    case 2:
        if (WaitForHelpBar())
            return 2;

        sub_81C7E14(4);
        break;
    }

    return 4;
}

u32 sub_81CC8D8(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CCB0C(state);
        return 0;
    case 1:
        if (sub_81CCC4C(state))
            return 2;

        sub_81CCC5C(1);
        sub_8123418();
        return 0;
    case 2:
        if (sub_8123514() || sub_81CCC88())
            return 2;

        PrintHelpBarText(HELPBAR_MAP_ZOOMED_IN);
        return 0;
    case 3:
        if (WaitForHelpBar())
            return 2;

        sub_81C7E14(5);
        break;
    }

    return 4;
}

u32 sub_81CC95C(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81C7AC0(0);
        return 0;
    case 1:
        if (IsPaletteFadeActive())
            return 2;

        sub_81C7FDC();
        sub_81C78A0();
        return 0;
    case 2:
        if (MainMenuLoopedTaskIsBusy())
            return 2;

        HideBg(1);
        HideBg(2);
        HideBg(3);
        return 0;
    }

    return 4;
}

static void sub_81CC9C0(void)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(gUnknown_086230F8); i++)
        LoadCompressedSpriteSheet(&gUnknown_086230F8[i]);

    Pokenav_AllocAndLoadPalettes(gUnknown_08623100);
    sub_81CCE58();
}

static void sub_81CC9EC(void)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    FreeSpriteTilesByTag(6);
    FreeSpritePaletteByTag(11);
    for (i = 0; i < 3; i++)
        DestroySprite(state->cityFeatureTextSprites[i]);
}

static void sub_81CCA1C(struct Pokenav5Struct_2 *state)
{
    sub_8199DF0(1, PIXEL_FILL(0), 0x40, 1);
    sub_8199DF0(1, PIXEL_FILL(1), 0x41, 1);
    CpuFill16(0x1040, state->unk18, 0x800);
    SetBgTilemapBuffer(1, state->unk18);
    state->unk8 = AddWindow(&gUnknown_08623110);
    LoadUserWindowBorderGfx_(state->unk8, 0x42, 0x40);
    DrawTextBorderOuter(state->unk8, 0x42, 4);
    decompress_and_copy_tile_data_to_vram(1, gUnknown_08622888, 0, 0, 0);
    FillWindowPixelBuffer(state->unk8, PIXEL_FILL(1));
    PutWindowTilemap(state->unk8);
    CopyWindowToVram(state->unk8, 3);
    CopyPaletteIntoBufferUnfaded(gUnknown_08622868, 0x10, 0x20);
    CopyPaletteIntoBufferUnfaded(gHoennMapZoomIcons_Pal, 0x30, 0x20);
    if (!sub_8124658())
        ChangeBgY(1, -0x6000, 0);
    else
        ChangeBgY(1, 0, 0);

    ChangeBgX(1, 0, 0);
}

static bool32 sub_81CCAFC(void)
{
    return free_temp_tile_data_buffers_if_possible();
}

static void sub_81CCB0C(struct Pokenav5Struct_2 *state)
{
    struct RegionMap *regionMap = GetSubstructPtr(16);
    switch (regionMap->iconDrawType)
    {
    case MAPSECTYPE_CITY_CANFLY:
        FillWindowPixelBuffer(state->unk8, PIXEL_FILL(1));
        PutWindowRectTilemap(state->unk8, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->unk8, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        sub_81CCD70(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->unk8, 3);
        sub_81CCFA4(0);
        break;
    case MAPSECTYPE_CITY_CANTFLY:
        FillWindowPixelBuffer(state->unk8, PIXEL_FILL(1));
        PutWindowRectTilemap(state->unk8, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->unk8, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        FillBgTilemapBufferRect(1, 0x1041, 17, 6, 12, 11, 17);
        CopyWindowToVram(state->unk8, 3);
        sub_81CCFA4(1);
        break;
    case MAPSECTYPE_PLAIN:
    case MAPSECTYPE_BATTLE_FRONTIER:
        FillWindowPixelBuffer(state->unk8, PIXEL_FILL(1));
        PutWindowTilemap(state->unk8);
        AddTextPrinterParameterized(state->unk8, 7, regionMap->mapSecName, 0, 1, TEXT_SPEED_FF, NULL);
        sub_81CCDE8(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->unk8, 3);
        sub_81CCFA4(1);
        break;
    case MAPSECTYPE_NONE:
        FillBgTilemapBufferRect(1, 0x1041, 17, 4, 12, 13, 17);
        CopyBgTilemapBufferToVram(1);
        sub_81CCFA4(1);
        break;
    }
}

static bool32 sub_81CCC4C(struct Pokenav5Struct_2 *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CCC5C(int arg0)
{
    u8 taskId = CreateTask(sub_81CCC9C, 3);
    gTasks[taskId].data[0] = arg0;
}

static bool32 sub_81CCC88(void)
{
    return FuncIsActiveTask(sub_81CCC9C);
}

static void sub_81CCC9C(u8 taskId)
{
    if (gTasks[taskId].data[0])
    {
        if (ChangeBgY(1, 0x480, 1) >= 0)
        {
            ChangeBgY(1, 0, 0);
            DestroyTask(taskId);
        }
        
        sub_81CCF78();
    }
    else
    {
        if (ChangeBgY(1, 0x480, 2) <= -0x6000)
        {
            ChangeBgY(1, -0x6000, 0);
            DestroyTask(taskId);
        }

        sub_81CCF78();
    }
}

static void sub_81CCD10(void)
{
    CreateLoopedTask(sub_81CCD34, 1);
}

static bool32 sub_81CCD24(void)
{
    return FuncIsActiveLoopedTask(sub_81CCD34);
}

static u32 sub_81CCD34(s32 taskState)
{
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    if (taskState < (int)ARRAY_COUNT(gPokenavCityMaps))
    {
        LZ77UnCompWram(gPokenavCityMaps[taskState].tilemap, state->cityZoomPics[taskState]);
        return 1;
    }

    return 4;
}

static void sub_81CCD70(struct Pokenav5Struct_2 *state, int mapSecId, int pos)
{
    int i;
    for (i = 0; i < (int)ARRAY_COUNT(gPokenavCityMaps) && (gPokenavCityMaps[i].mapSecId != mapSecId || gPokenavCityMaps[i].index != pos); i++)
        ;

    if (i == ARRAY_COUNT(gPokenavCityMaps))
        return;

    FillBgTilemapBufferRect_Palette0(1, 0x1041, 17, 6, 12, 11);
    CopyToBgTilemapBufferRect(1, state->cityZoomPics[i], 18, 6, 10, 10);
}

static void sub_81CCDE8(struct Pokenav5Struct_2 *state, int mapSecId, int pos)
{
    int i = 0;
    while (1)
    {
        const u8 *landmarkName = GetLandmarkName(mapSecId, pos, i);
        if (!landmarkName)
            break;

        StringCopyPadded(gStringVar1, landmarkName, CHAR_SPACE, 12);
        AddTextPrinterParameterized(state->unk8, 7, gStringVar1, 0, i * 16 + 17, TEXT_SPEED_FF, NULL);
        i++;
    }
}

static void sub_81CCE58(void)
{
    int i;
    int y;
    struct Sprite *sprite;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);

    if (!sub_8124658())
        y = 228;
    else
        y = 132;

    for (i = 0; i < 3; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_086231D0, 152 + i * 32, y, 8);
        sprite = &gSprites[spriteId];
        sprite->data[0] = 0;
        sprite->data[1] = i * 4;
        sprite->data[2] = sprite->oam.tileNum;
        sprite->data[3] = 150;
        sprite->data[4] = i * 4;
        sprite->oam.tileNum += i * 4;
        state->cityFeatureTextSprites[i] = sprite;
    }
}

void sub_81CCEF4(struct Sprite *sprite)
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

static void sub_81CCF78(void)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    int y = 132 - (GetBgY(1) >> 8);
    for (i = 0; i < 3; i++)
        state->cityFeatureTextSprites[i]->pos1.y = y;
}

static void sub_81CCFA4(int invisible)
{
    int i;
    struct Pokenav5Struct_2 *state = GetSubstructPtr(4);
    for (i = 0; i < 3; i++)
        state->cityFeatureTextSprites[i]->invisible = invisible;
}

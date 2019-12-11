#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "malloc.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"

struct CableCar
{
    u8 taskId;
    u8 state;
    u8 weather;
    u16 unk4;
    u16 timer;
    u8 bg0HorizontalOffset;
    u8 bg0VerticalOffset;
    u8 fillerA[0x2];
    u8 bg1HorizontalOffset;
    u8 bg1VerticalOffset;
    u8 fillerE[0x6];
    u8 bg3HorizontalOffset;
    u8 bg3VerticalOffset;
    u8 filler16[0x2];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u16 unk22[9][12];
    u8 fillerFA[0x2];
    /*0x00FC*/ u16 bgTilemapBuffers[4][0x800];
    /*0x40FC*/ u16 *mtChimneyTilemap;
    /*0x4100*/ u16 *treeTilemap;
    /*0x4104*/ u16 *mountainTilemap;
    /*0x4108*/ const u16 *pylonHookTilemapEntries;
    /*0x410C*/ u8 *pylonStemTilemap;
};

static EWRAM_DATA struct CableCar *sCableCar = NULL;
EWRAM_DATA u8 gUnknown_0203ABB0 = 0;
EWRAM_DATA u8 gUnknown_0203ABB1 = 0;
EWRAM_DATA u8 gUnknown_0203ABB2 = 0;
EWRAM_DATA u8 gUnknown_0203ABB3 = 0;
EWRAM_DATA u8 gUnknown_0203ABB4 = 0;
EWRAM_DATA u8 gUnknown_0203ABB5 = 0;

static void CableCarMainCallback_Setup(void);
static void sub_8150B6C(u8);
static void LoadCableCarSprites(void);
static void sub_81514C8(u8);
static void sub_81503E4(u8);
static void sub_8150550(u8);
static void sub_8150664(u8);
static void CableCarVblankCallback(void);
static void CableCarMainCallback_Run(void);
static void sub_815115C(void);
static void sub_81511B8(void);
static void sub_8150868(struct Sprite *);
static void nullsub_58(struct Sprite *);
static void sub_8151214(void);
static void sub_8151388(void);

const struct BgTemplate gCableCarBgTemplates[4] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

const u8 gCableCarMtChimneyTilemap[] = INCBIN_U8("graphics/misc/cable_car_mt_chimney_map.bin.lz");
const u8 gCableCarTreeTilemap[] = INCBIN_U8("graphics/misc/cable_car_tree_map.bin.lz");
const u8 gCableCarMountainTilemap[] = INCBIN_U8("graphics/misc/cable_car_mountain_map.bin.lz");

const u16 gCableCarPylonHookTilemapEntries[] = {
    0x3000,
    0x3001,
    0x3002,
    0x3003,
    0x3004,
    0x3005,
    0x3006,
    0x3007,
    0x3008,
    0x3009,
};

const u8 gCableCarPylonStemTilemap[] = INCBIN_U8("graphics/misc/cable_car_pylon_stem_map.bin.lz");

const struct CompressedSpriteSheet gUnknown_085CDB54[] = {
    { gCableCar_Gfx,     0x800, 1 },
    { gCableCarDoor_Gfx,  0x40, 2 },
    { gCableCarCord_Gfx,  0x80, 3 },
    { },
};

const struct SpritePalette gUnknown_085CDB74[] = {
    { gCableCar_Pal, 1 },
    { }
};

const struct OamData gOamData_85CDB84 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gOamData_85CDB8C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gOamData_85CDB94 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct SpriteTemplate gSpriteTemplate_85CDB9C[] =
{
    {
        .tileTag = 1,
        .paletteTag = 1,
        .oam = &gOamData_85CDB84,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8150868,
    },
    {
        .tileTag = 2,
        .paletteTag = 1,
        .oam = &gOamData_85CDB8C,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8150868,
    },
};

const struct SpriteTemplate gSpriteTemplate_85CDBCC = {
    .tileTag = 3,
    .paletteTag = 1,
    .oam = &gOamData_85CDB94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_58,
};

static void CableCarTask1(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CableCarMainCallback_Setup);
        DestroyTask(taskId);
    }
}

void CableCar(void)
{
    ScriptContext2_Enable();
    CreateTask(CableCarTask1, 1);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
}

static void CableCarMainCallback_Setup(void)
{
    u16 imebak;
    u8 i = 0;
    u32 sizeOut = 0;

    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        sub_8150B6C(0);
        ScanlineEffect_Stop();
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
        sCableCar = AllocZeroed(sizeof(*sCableCar));
        gMain.state++;
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        reset_temp_tile_data_buffers();
        StartWeather();
        for (i = 0; i < 20; i++)
            gWeatherPtr->sprites.s2.ashSprites[i] = NULL;

        InitMapMusic();
        ResetMapMusic();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gCableCarBgTemplates, ARRAY_COUNT(gCableCarBgTemplates));
        SetBgTilemapBuffer(0, sCableCar->bgTilemapBuffers[0]);
        SetBgTilemapBuffer(1, sCableCar->bgTilemapBuffers[1]);
        SetBgTilemapBuffer(2, sCableCar->bgTilemapBuffers[2]);
        SetBgTilemapBuffer(3, sCableCar->bgTilemapBuffers[3]);
        gSpriteCoordOffsetX = gSpriteCoordOffsetY = 0;
        gMain.state++;
        break;
    case 2:
        for (i = 0; i < 3; i++)
            LoadCompressedSpriteSheet(&gUnknown_085CDB54[i]);

        LoadSpritePalettes(gUnknown_085CDB74);
        sCableCar->mtChimneyTilemap = malloc_and_decompress(gCableCarMtChimneyTilemap, &sizeOut);
        sCableCar->treeTilemap = malloc_and_decompress(gCableCarTreeTilemap, &sizeOut);
        sCableCar->mountainTilemap = malloc_and_decompress(gCableCarMountainTilemap, &sizeOut);
        sCableCar->pylonStemTilemap = malloc_and_decompress(gCableCarPylonStemTilemap, &sizeOut);
        sCableCar->pylonHookTilemapEntries = gCableCarPylonHookTilemapEntries;
        decompress_and_copy_tile_data_to_vram(0, gUnknown_08DBA5B8, 0, 0, 0);
        gMain.state++;
        break;
    case 3:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            LoadPalette(gUnknown_08DBA518, 0, 0x80);
            gMain.state++;
        }
        break;
    case 4:
        LoadCableCarSprites();
        RunTasks();
        gMain.state++;
        break;
    case 5:
        if (sCableCar->weather == WEATHER_VOLCANIC_ASH)
        {
            gMain.state++;
        }
        else if (gWeatherPtr->sprites.s2.ashSprites[0])
        {
            for (i = 0; i < 20; i++)
            {
                if (gWeatherPtr->sprites.s2.ashSprites[i])
                    gWeatherPtr->sprites.s2.ashSprites[i]->oam.priority = 0;
            }

            gMain.state++;
        }
        break;
    case 6:
        CopyToBgTilemapBufferRect_ChangePalette(1, sCableCar->treeTilemap, 0, 17, 32, 15, 17);
        CopyToBgTilemapBufferRect_ChangePalette(2, sCableCar->mountainTilemap, 0, 0, 30, 20, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonHookTilemapEntries, 0, 0, 5, 2, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonStemTilemap, 0, 2, 2, 20, 17);
        gMain.state++;
        break;
    case 7:
        sub_81514C8(gSpecialVar_0x8004);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +  0x48,  0, 14, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +  0x6C, 12, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +  0x90, 24, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +   0x0,  0, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +  0x24,  0, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +   0x0, 12, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +  0x24, 12, 23, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap +   0x0, 24, 23, 12, 3, 17);
        gMain.state++;
        break;
    case 8:
        BeginNormalPaletteFade(0xFFFFFFFF, 3, 16, 0, RGB(0, 0, 0));
        FadeInNewBGM(MUS_ROPEWAY, 1);
        sub_8150B6C(1);
        gMain.state++;
        break;
    case 9:
        imebak = REG_IME;
        REG_IME = 0;
        REG_IE |= INTR_FLAG_VBLANK;
        REG_IME = imebak;
        SetVBlankCallback(CableCarVblankCallback);
        SetMainCallback2(CableCarMainCallback_Run);
        CreateTask(sub_81503E4, 0);
        if (gSpecialVar_0x8004 == 0)
            sCableCar->taskId = CreateTask(sub_8150550, 1);
        else
            sCableCar->taskId = CreateTask(sub_8150664, 1);
        break;
    }
}

static void CableCarMainCallback_Run(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    MapMusicMain();
}

static void CleanupCableCar(void)
{
    u8 i = 0;

    HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
    sub_8150B6C(0);
    gSpriteCoordOffsetX = 0;
    SetCurrentAndNextWeatherNoDelay(WEATHER_NONE);
    for (i = 0; i < 20; i++)
        gWeatherPtr->sprites.s2.ashSprites[i] = NULL;

    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    UnsetBgTilemapBuffer(0);
    UnsetBgTilemapBuffer(1);
    UnsetBgTilemapBuffer(2);
    UnsetBgTilemapBuffer(3);
    ResetBgsAndClearDma3BusyFlags(0);
    sCableCar->pylonHookTilemapEntries = NULL;
    FREE_AND_SET_NULL(sCableCar->pylonStemTilemap);
    FREE_AND_SET_NULL(sCableCar->mountainTilemap);
    FREE_AND_SET_NULL(sCableCar->treeTilemap);
    FREE_AND_SET_NULL(sCableCar->mtChimneyTilemap);
    FREE_AND_SET_NULL(sCableCar);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
    WarpIntoMap();
    gFieldCallback = NULL;
    SetMainCallback2(CB2_LoadMap);
}

static void sub_81503E4(u8 taskId)
{
    u8 i = 0;

    sCableCar->timer++;
    switch (sCableCar->state)
    {
    case 0:
        if (sCableCar->timer == sCableCar->unk4)
        {
            SetNextWeather(sCableCar->weather);
            sCableCar->state = 1;
        }
        break;
    case 1:
        switch (sCableCar->weather)
        {
        case WEATHER_VOLCANIC_ASH:
            if (gWeatherPtr->sprites.s2.ashSprites[0] != NULL && gWeatherPtr->sprites.s2.ashSprites[0]->oam.priority != 0)
            {
                for (; i < NUM_ASH_SPRITES; i++)
                {
                    if (gWeatherPtr->sprites.s2.ashSprites[i])
                        gWeatherPtr->sprites.s2.ashSprites[i]->oam.priority = 0;
                }

                sCableCar->state = 2;
            }
            break;
        case WEATHER_SUNNY:
            if (gWeatherPtr->currWeather == WEATHER_SUNNY)
            {
                sCableCar->state = 2;
            }
            else if (sCableCar->timer >= sCableCar->unk4 + 8)
            {
                for (; i < NUM_ASH_SPRITES; i++)
                {
                    if (gWeatherPtr->sprites.s2.ashSprites[i])
                        gWeatherPtr->sprites.s2.ashSprites[i]->invisible ^= 1;
                }
            }
            break;
        }
        break;
    case 2:
        if (sCableCar->timer == 570)
        {
            sCableCar->state = 3;
            BeginNormalPaletteFade(0xFFFFFFFF, 3, 0, 16, RGB(0, 0, 0));
            FadeOutBGM(4);
        }
        break;
    case 3:
        if (!gPaletteFade.active)
            sCableCar->state = 0xFF;
        break;
    case 0xFF:
        SetVBlankCallback(NULL);
        DestroyTask(taskId);
        DestroyTask(sCableCar->taskId);
        SetMainCallback2(CleanupCableCar);
        break;
    }
}

static void sub_8150550(u8 taskId)
{
    if (sCableCar->state != 0xFF)
    {
        sCableCar->bg3HorizontalOffset--;
        if ((sCableCar->timer % 2) == 0)
            sCableCar->bg3VerticalOffset--;

        if ((sCableCar->timer % 8) == 0)
        {
            sCableCar->bg1HorizontalOffset--;
            sCableCar->bg1VerticalOffset--;
        }

        switch (sCableCar->bg3HorizontalOffset)
        {
        case 175:
            FillBgTilemapBufferRect(3, 0, 0, 22, 2, 10, 17);
            break;
        case 40:
            FillBgTilemapBufferRect(3, 0, 3, 0, 2, 2, 17);
            break;
        case 32:
            FillBgTilemapBufferRect(3, 0, 2, 0, 1, 2, 17);
            break;
        case 16:
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonHookTilemapEntries, 0, 0, 5,  2, 17);
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonStemTilemap, 0, 2, 2, 30, 17);
            sCableCar->bg3VerticalOffset = 64;
            break;
        }
    }

    sub_815115C();
    gSpriteCoordOffsetX = (gSpriteCoordOffsetX + 1) % 128;
}

static void sub_8150664(u8 taskId)
{
    if (sCableCar->state != 0xFF)
    {
        sCableCar->bg3HorizontalOffset++;
        if ((sCableCar->timer % 2) == 0)
            sCableCar->bg3VerticalOffset++;

        if ((sCableCar->timer % 8) == 0)
        {
            sCableCar->bg1HorizontalOffset++;
            sCableCar->bg1VerticalOffset++;
        }

        switch (sCableCar->bg3HorizontalOffset)
        {
        case 176:
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonStemTilemap, 0, 2, 2, 30, 17);
            break;
        case 16:
            FillBgTilemapBufferRect(3, 0, 2,  0, 3,  2, 17);
            FillBgTilemapBufferRect(3, 0, 0, 22, 2, 10, 17);
            sCableCar->bg3VerticalOffset = 192;
            break;
        case 32:
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[2], 2, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[3], 3, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[7], 2, 1, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[8], 3, 1, 1, 1, 17);
            break;
        case 40:
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[4], 4, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonHookTilemapEntries[9], 4, 1, 1, 1, 17);
            break;
        }
    }

    sub_81511B8();
    if (sCableCar->timer < sCableCar->unk4)
        gSpriteCoordOffsetX = (gSpriteCoordOffsetX + 247) % 248;
    else
        gWeatherPtr->ashBaseSpritesX = (gWeatherPtr->ashBaseSpritesX + 247) % 248;
}

static void CableCarVblankCallback(void)
{
    CopyBgTilemapBufferToVram(0);
    CopyBgTilemapBufferToVram(3);
    SetGpuReg(REG_OFFSET_BG3HOFS, sCableCar->bg3HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG3VOFS, sCableCar->bg3VerticalOffset);
    SetGpuReg(REG_OFFSET_BG1HOFS, sCableCar->bg1HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG1VOFS, sCableCar->bg1VerticalOffset);
    SetGpuReg(REG_OFFSET_BG0HOFS, sCableCar->bg0HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG0VOFS, sCableCar->bg0VerticalOffset);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void nullsub_58(struct Sprite *sprite)
{
}

static void sub_8150868(struct Sprite *sprite)
{
    if (sCableCar->state != 0xFF)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sprite->pos1.x = sprite->data[0] - (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->pos1.y = sprite->data[1] - (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
        else
        {
            sprite->pos1.x = sprite->data[0] + (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->pos1.y = sprite->data[1] + (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
    }
}

void sub_8150948(struct Sprite *sprite)
{
    if (sCableCar->state != 255)
    {
        if (!gSpecialVar_0x8004)
        {
            sprite->pos1.x = sprite->data[0] - (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->pos1.y = sprite->data[1] - (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
        else
        {
            sprite->pos1.x = sprite->data[0] + (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->pos1.y = sprite->data[1] + (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }

        switch (sprite->data[2])
        {
        case 0:
            sprite->pos2.y = 17;
            if (sprite->data[3] ++ > 9)
            {
                sprite->data[3] = 0;
                sprite->data[2] ++;
            }
            break;
        default:
            sprite->pos2.y = 16;
            if (sprite->data[3] ++ > 9)
            {
                sprite->data[3] = 0;
                sprite->data[2] = 0;
            }
            break;
        }
    }
}

static void sub_8150A68(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->pos1.x += 2 * sprite->centerToCornerVecX;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    }

    if (++sprite->data[0] >= sprite->data[2])
    {
        switch (sprite->data[1])
        {
        case 0:
            sprite->pos1.x++;
            if ((sprite->data[0] % 4) == 0)
                sprite->pos1.y++;
            break;
        case 1:
            if ((sprite->data[0] % 2) != 0)
            {
                sprite->pos1.x++;
                if ((sprite->pos1.x % 4) == 0)
                    sprite->pos1.y++;
            }
            break;
        }

        if (sprite->pos1.y > 160)
            DestroySprite(sprite);
    }
}

static void sub_8150AF4(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;

    if (++sprite->data[0] >= sprite->data[2])
    {
        switch (sprite->data[1])
        {
        case 0:
            sprite->pos1.x--;
            if ((sprite->data[0] % 4) == 0)
                sprite->pos1.y--;
            break;
        case 1:
            if ((sprite->data[0] % 2) != 0)
            {
                sprite->pos1.x--;
                if ((sprite->pos1.x % 4) == 0)
                    sprite->pos1.y--;
            }
            break;
        }

        if (sprite->pos1.y < 80)
            DestroySprite(sprite);
    }
}

static void sub_8150B6C(bool8 which)
{
    switch (which)
    {
    case FALSE:
    default:
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        break;
    case TRUE:
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        if (gSpecialVar_0x8004 == 0)
        {
            sCableCar->bg3HorizontalOffset = 176;
            sCableCar->bg3VerticalOffset = 16;
            sCableCar->bg1HorizontalOffset = 0;
            sCableCar->bg1VerticalOffset = 80;
            sCableCar->bg0VerticalOffset = 0;
            sCableCar->bg0VerticalOffset = 0;
        }
        else
        {
            sCableCar->bg3HorizontalOffset = 96;
            sCableCar->bg3VerticalOffset = 232;
            sCableCar->bg1HorizontalOffset = 0;
            sCableCar->bg1VerticalOffset = 4;
            sCableCar->bg0VerticalOffset = 0;
            sCableCar->bg0VerticalOffset = 0;
        }

        SetGpuReg(REG_OFFSET_BG3HOFS, sCableCar->bg3HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG3VOFS, sCableCar->bg3VerticalOffset);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, sCableCar->bg1HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG1VOFS, sCableCar->bg1VerticalOffset);
        SetGpuReg(REG_OFFSET_BG0HOFS, sCableCar->bg0HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG0VOFS, sCableCar->bg0VerticalOffset);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        break;
    }
}

static void LoadCableCarSprites(void)
{
    u8 spriteId;
    u8 i;

    u8 playerGraphicsIds[2] = {
        EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL,
        EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
    };
    u16 rval = Random();
    u8 hikerGraphicsIds[4] = {
        EVENT_OBJ_GFX_HIKER,
        EVENT_OBJ_GFX_CAMPER,
        EVENT_OBJ_GFX_PICNICKER,
        EVENT_OBJ_GFX_ZIGZAGOON_1
    };
    s16 hikerCoords[2][2] = {
        {   0,  80 },
        { 240, 146 }
    };
    u8 hikerMovementDelayTable[4] = {
        0,
        60,
        120,
        170
    };
    void (*callbacks[2])(struct Sprite *) = {
        sub_8150A68,
        sub_8150AF4
    };

    switch (gSpecialVar_0x8004)
    {
        case 0:
        default:
            spriteId = AddPseudoEventObject(playerGraphicsIds[gSaveBlock2Ptr->playerGender], sub_8150948, 200, 73, 102);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.priority = 2;
                gSprites[spriteId].pos2.x = 8;
                gSprites[spriteId].pos2.y = 16;
                gSprites[spriteId].data[0] = 0xc8;
                gSprites[spriteId].data[1] = 0x49;
            }
            spriteId = CreateSprite(&gSpriteTemplate_85CDB9C[0], 176, 43, 0x67);
            gSprites[spriteId].pos2.x = gSprites[spriteId].pos2.y = 32;
            gSprites[spriteId].data[0] = 176;
            gSprites[spriteId].data[1] = 43;
            spriteId = CreateSprite(&gSpriteTemplate_85CDB9C[1], 200, 99, 0x65);
            gSprites[spriteId].pos2.x = 8;
            gSprites[spriteId].pos2.y = 4;
            gSprites[spriteId].data[0] = 200;
            gSprites[spriteId].data[1] = 99;
            sCableCar->weather = WEATHER_VOLCANIC_ASH;
            sCableCar->unk4 = 0x15e;
            SetCurrentAndNextWeatherNoDelay(WEATHER_SUNNY);
            break;
        case 1:
            CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->mtChimneyTilemap + 0x24, 24, 26, 12, 3, 17);
            spriteId = AddPseudoEventObject(playerGraphicsIds[gSaveBlock2Ptr->playerGender], sub_8150948, 128, 39, 102);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.priority = 2;
                gSprites[spriteId].pos2.x = 8;
                gSprites[spriteId].pos2.y = 16;
                gSprites[spriteId].data[0] = 0x80;
                gSprites[spriteId].data[1] = 0x27;
            }
            spriteId = CreateSprite(&gSpriteTemplate_85CDB9C[0], 104, 9, 0x67);
            gSprites[spriteId].pos2.x = gSprites[spriteId].pos2.y = 0x20;
            gSprites[spriteId].data[0] = 104;
            gSprites[spriteId].data[1] = 9;
            spriteId = CreateSprite(&gSpriteTemplate_85CDB9C[1], 128, 65, 0x65);
            gSprites[spriteId].pos2.x = 8;
            gSprites[spriteId].pos2.y = 4;
            gSprites[spriteId].data[0] = 0x80;
            gSprites[spriteId].data[1] = 0x41;
            sCableCar->weather = WEATHER_SUNNY;
            sCableCar->unk4 = 0x109;
            SetCurrentAndNextWeatherNoDelay(WEATHER_VOLCANIC_ASH);
            break;
    }
    for (i = 0; i < 9; i++)
    {
        spriteId = CreateSprite(&gSpriteTemplate_85CDBCC, 16 * i + 96, 8 * i - 8, 0x68);
        gSprites[spriteId].pos2.x = 8;
        gSprites[spriteId].pos2.y = 8;
    }
    if ((rval % 64) == 0)
    {
        spriteId = AddPseudoEventObject(hikerGraphicsIds[rval % 3], callbacks[gSpecialVar_0x8004], hikerCoords[gSpecialVar_0x8004][0], hikerCoords[gSpecialVar_0x8004][1], 0x6a);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].pos2.x = -gSprites[spriteId].centerToCornerVecX;
            gSprites[spriteId].pos2.y = -gSprites[spriteId].centerToCornerVecY;
            if (gSpecialVar_0x8004 == 0)
            {
                if (rval % 2)
                {
                    StartSpriteAnim(&gSprites[spriteId], 6);
                    gSprites[spriteId].data[1] = 1;
                    gSprites[spriteId].pos1.y += 2;
                }
                else
                {
                    StartSpriteAnim(&gSprites[spriteId], 7);
                    gSprites[spriteId].data[1] = 0;
                }
            }
            else
            {
                if (rval % 2)
                {
                    StartSpriteAnim(&gSprites[spriteId], 7);
                    gSprites[spriteId].data[1] = 1;
                    gSprites[spriteId].pos1.y += 2;
                }
                else
                {
                    StartSpriteAnim(&gSprites[spriteId], 6);
                    gSprites[spriteId].data[1] = 0;
                }
            }
            gSprites[spriteId].data[2] = hikerMovementDelayTable[rval % 4];
        }
    }
}

void sub_8151088(void)
{
    u8 i;
    u8 j;
    u8 k;
    u8 offset;

    for (i = 0, k = 0, offset = 0x24 * (sCableCar->unk1B + 2); i < 3; i++)
    {
        for (j = 0; j < 12; j++)
        {
            sCableCar->unk22[i][j] = sCableCar->mtChimneyTilemap[offset++];
            sCableCar->unk22[i + 3][j] = sCableCar->mtChimneyTilemap[k];
            sCableCar->unk22[i + 6][j] = (sCableCar->mtChimneyTilemap + 0x24)[k];
            k++;
        }
    }

    sCableCar->unk1B = (sCableCar->unk1B + 1) % 3;
}

static void sub_815115C(void)
{
    sCableCar->unk1C = (sCableCar->unk1C + 1) % 0x60;
    sCableCar->bg0HorizontalOffset = sCableCar->unk1F - sCableCar->unk1D;
    sCableCar->bg0VerticalOffset = sCableCar->unk20 - sCableCar->unk1E;
    sCableCar->unk1D++;
    if ((sCableCar->unk1D % 4) == 0)
        sCableCar->unk1E++;

    if (sCableCar->unk1D > 16)
        sub_8151214();
}

static void sub_81511B8(void)
{
    sCableCar->unk1C = (sCableCar->unk1C + 1) % 0x60;
    sCableCar->bg0HorizontalOffset = sCableCar->unk1F + sCableCar->unk1D;
    sCableCar->bg0VerticalOffset = sCableCar->unk20 + sCableCar->unk1E;
    sCableCar->unk1D++;
    if ((sCableCar->unk1D % 4) == 0)
        sCableCar->unk1E++;

    if (sCableCar->unk1D > 16)
        sub_8151388();
}

static void sub_8151214(void)
{
    u8 i = 0;

    sCableCar->unk1D = sCableCar->unk1E = 0;
    sCableCar->unk1F = sCableCar->bg0HorizontalOffset;
    sCableCar->unk20 = sCableCar->bg0VerticalOffset;
    sCableCar->unk19 = (sCableCar->unk19 + 30) % 32;
    sCableCar->unk18 -= 2;
    gUnknown_0203ABB2 = (sCableCar->unk1A + 23) % 32;
    for (i = 0; i < 9; i++)
    {
        gUnknown_0203ABB0 = sCableCar->unk19;
        gUnknown_0203ABB1 = (gUnknown_0203ABB2 + i) % 32;
        FillBgTilemapBufferRect(0, sCableCar->unk22[i][sCableCar->unk18], gUnknown_0203ABB0, gUnknown_0203ABB1, 1, 1, 17);
        gUnknown_0203ABB0 = (gUnknown_0203ABB0 + 1) % 32;
        FillBgTilemapBufferRect(0, sCableCar->unk22[i][sCableCar->unk18 + 1], gUnknown_0203ABB0, gUnknown_0203ABB1, 1, 1, 17);
    }

    gUnknown_0203ABB0 = (sCableCar->unk19 + 30) % 32;
    FillBgTilemapBufferRect(0, 0, gUnknown_0203ABB0, 0, 2, 32, 17);
    if (sCableCar->unk18 == 0)
    {
        sCableCar->unk1A = (sCableCar->unk1A + 29) % 32;
        sCableCar->unk18 = 12;
        sub_8151088();
        gUnknown_0203ABB0 = (sCableCar->unk1A + 1) % 32;
        FillBgTilemapBufferRect(0, 0, 0, gUnknown_0203ABB0, 32, 9, 17);
    }
}

static void sub_8151388(void)
{
    u8 i = 0;

    sCableCar->unk1D = sCableCar->unk1E = 0;
    sCableCar->unk1F = sCableCar->bg0HorizontalOffset;
    sCableCar->unk20 = sCableCar->bg0VerticalOffset;
    sCableCar->unk19 = (sCableCar->unk19 + 2) % 32;
    sCableCar->unk18 += 2;
    gUnknown_0203ABB5 = sCableCar->unk1A;
    for (i = 0; i < 9; i++)
    {
        gUnknown_0203ABB3 = sCableCar->unk19;
        gUnknown_0203ABB4 = (gUnknown_0203ABB5 + i) % 32;
        FillBgTilemapBufferRect(0, sCableCar->unk22[i][sCableCar->unk18], gUnknown_0203ABB3, gUnknown_0203ABB4, 1, 1, 17);
        gUnknown_0203ABB3 = (gUnknown_0203ABB3 + 1) % 32;
        FillBgTilemapBufferRect(0, sCableCar->unk22[i][sCableCar->unk18 + 1], gUnknown_0203ABB3, gUnknown_0203ABB4, 1, 1, 17);
    }

    gUnknown_0203ABB4 = (sCableCar->unk1A + 23) % 32;
    FillBgTilemapBufferRect(0, 0, sCableCar->unk19, gUnknown_0203ABB4, 2, 9, 17);
    if (sCableCar->unk18 == 10)
    {
        sCableCar->unk1A = (sCableCar->unk1A + 3) % 32;
        sCableCar->unk18 = 0xfe;
        sub_8151088();
    }
}

static void sub_81514C8(u8 arg0)
{
    switch (arg0)
    {
        case 0:
        default:
            sCableCar->unk1B = 2;
            sCableCar->unk19 = 0;
            sCableCar->unk1A = 20;
            sCableCar->unk18 = 12;
            sub_8151088();
            sub_8151214();
            break;
        case 1:
            sCableCar->unk1B = 2;
            sCableCar->unk19 = 28;
            sCableCar->unk1A = 20;
            sCableCar->unk18 = 4;
            sub_8151088();
            sub_8151388();
            break;
    }

    sCableCar->unk1C = 0;
}


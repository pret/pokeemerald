#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "menu.h"
#include "random.h"
#include "roulette_util.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

struct MirageTowerPulseBlend {
    u8 taskId;
    struct PulseBlend pulseBlend;
};

struct MetatileCoords
{
    u8 x;
    u8 y;
    u16 metatileId;
};

struct BgRegOffsets
{
    u16 bgHOFS;
    u16 bgVOFS;
};

struct Struct203CF10
{
    u8 *buffer;
    u8 currIndex;
};

struct DynamicSpriteFrameImage
{
    u8 *data;
    u16 size;
};

struct Struct203CF0C
{
    u8 *frameImageTiles;
    struct DynamicSpriteFrameImage *frameImage;
    u8 spriteId;
    u16 *unkC;
    u16 unk10;
};

#define MIRAGE_TOWER_GFX_LENGTH (sizeof(sBlankTile_Gfx) + sizeof(sMirageTower_Gfx))
#define ROOT_FOSSIL_GFX_LENGTH sizeof(sRootFossil_Gfx)
#define ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH 0x100

// extern data
extern const struct SpriteSheet gMirageTowerCeilingCrumbleSpriteSheets[];
extern const s16 sCeilingCrumblePositions[][3];

// static functions
static void PlayerDescendMirageTower(u8 taskId);
static void DoScreenShake(u8 taskId);
static void IncrementCeilingCrumbleFinishedCount(void);
static void WaitCeilingCrumble(u8 taskId);
static void FinishCeilingCrumbleTask(u8 taskId);
static void CreateCeilingCrumbleSprites(void);
static void MoveCeilingCrumbleSprite(struct Sprite* sprite);
static void DoMirageTowerDisintegration(u8 taskId);
static void InitMirageTowerShake(u8 taskId);
static void DoFossilFallAndSink(u8 taskId);
static void sub_81BF248(struct Sprite *);
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e);

// rodata
static const u8 sBlankTile_Gfx[32] = {0};
static const u8 sMirageTower_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower.4bpp");
static const u16 sMirageTowerTilemap[] = INCBIN_U16("graphics/misc/mirage_tower.bin");
static const u16 sRootFossil_Pal[] = INCBIN_U16("graphics/misc/fossil.gbapal");
static const u8 sRootFossil_Gfx[] = INCBIN_U8("graphics/misc/fossil.4bpp");
static const u8 sMirageTowerCrumbles_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower_crumbles.4bpp");
static const u16 sMirageTowerCrumbles_Palette[] = INCBIN_U16("graphics/misc/mirage_tower_crumbles.gbapal");

const s16 sCeilingCrumblePositions[][3] =
{
    {  0,  10,  65},
    { 17,   3,  50},
    {-12,   0,  75},
    { 10,  15,  90},
    {  7,   8,  65},
    {-18,   5,  75},
    { 22, -10,  55},
    {-24,  -4,  65},
};

const struct SpriteSheet gMirageTowerCeilingCrumbleSpriteSheets[] =
{
    {sMirageTowerCrumbles_Gfx, 0x0080, 4000},
    {NULL}
};

static const struct MetatileCoords sInvisibleMirageTowerMetatiles[] =
{
    {18, 53, METATILE_ID(Mauville, DeepSand_Center)},
    {19, 53, METATILE_ID(Mauville, DeepSand_Center)},
    {20, 53, METATILE_ID(Mauville, DeepSand_Center)},
    {18, 54, METATILE_ID(Mauville, DeepSand_Center)},
    {19, 54, METATILE_ID(Mauville, DeepSand_Center)},
    {20, 54, METATILE_ID(Mauville, DeepSand_Center)},
    {18, 55, METATILE_ID(Mauville, DeepSand_Center)},
    {19, 55, METATILE_ID(Mauville, DeepSand_Center)},
    {20, 55, METATILE_ID(Mauville, DeepSand_Center)},
    {18, 56, METATILE_ID(Mauville, DeepSand_Center)},
    {19, 56, METATILE_ID(Mauville, DeepSand_Center)},
    {20, 56, METATILE_ID(Mauville, DeepSand_Center)},
    {18, 57, METATILE_ID(Mauville, DeepSand_BottomMid)},
    {19, 57, METATILE_ID(Mauville, DeepSand_BottomMid)},
    {20, 57, METATILE_ID(Mauville, DeepSand_BottomMid)},
    {18, 58, METATILE_ID(General, SandPit_Center)},
    {19, 58, METATILE_ID(General, SandPit_Center)},
    {20, 58, METATILE_ID(General, SandPit_Center)},
};

static const union AnimCmd gSpriteAnim_8617DEC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const struct OamData gOamData_8617DF4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 3,
    .affineParam = 0,
};

static const union AnimCmd *const gSpriteAnimTable_8617DFC[] =
{
    gSpriteAnim_8617DEC,
};

static const struct SpriteTemplate gUnknown_08617E00 =
{
    0xFFFF, 0xFFFF, &gOamData_8617DF4, gSpriteAnimTable_8617DFC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
};

const struct PulseBlendSettings gMirageTowerPulseBlendSettings = {
    .blendColor = RGB(27, 25, 16),
    .paletteOffset = 0x61,
    .numColors = 15,
    .delay = 5,
    .numFadeCycles = -1,
    .maxBlendCoeff = 11,
    .fadeType = 1,
    .restorePaletteOnUnload = FALSE,
    .unk7_7 = 1,
};

static const union AnimCmd sCeilingCrumble2AnimCmd[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sCeilingCrumble2AnimCmds[] =
{
    sCeilingCrumble2AnimCmd,
};

static const struct OamData sCeilingCrumble2OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sCeilingCrumbleSpriteTemplate2 = {
    .tileTag = 4000,
    .paletteTag = 0xFFFF,
    .oam = &sCeilingCrumble2OamData,
    .anims = sCeilingCrumble2AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = MoveCeilingCrumbleSprite
};

static const union AnimCmd sCeilingCrumble1AnimCmd[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sCeilingCrumble1AnimCmds[] =
{
    sCeilingCrumble1AnimCmd,
};

static const struct OamData sCeilingCrumble1OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sCeilingCrumbleSpriteTemplate1 = {
    .tileTag = 4000,
    .paletteTag = 0xFFFF,
    .oam = &sCeilingCrumble1OamData,
    .anims = sCeilingCrumble1AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = MoveCeilingCrumbleSprite
};

EWRAM_DATA static u8* sMirageTowerGfxBuffer = NULL;
EWRAM_DATA static u8* sMirageTowerTilemapBuffer = NULL;
EWRAM_DATA static struct Struct203CF0C *sUnknown_0203CF0C = NULL;
EWRAM_DATA static struct Struct203CF10 *sUnknown_0203CF10 = NULL;
EWRAM_DATA static struct BgRegOffsets *sBgShakeOffsets = NULL;
EWRAM_DATA struct MirageTowerPulseBlend *sMirageTowerPulseBlend = NULL;

static u16 gUnknown_030012A8[8];

bool8 IsMirageTowerVisible(void)
{
    if (!(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE111) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE111)))
        return FALSE;
    return FlagGet(FLAG_MIRAGE_TOWER_VISIBLE);
}

static void UpdateMirageTowerPulseBlend(u8 taskId)
{
    UpdatePulseBlend(&sMirageTowerPulseBlend->pulseBlend);
}

void ClearMirageTowerPulseBlend(void)
{
    sMirageTowerPulseBlend = NULL;
}

void TryStartMirageTowerPulseBlendEffect(void)
{
    if (sMirageTowerPulseBlend)
    {
        sMirageTowerPulseBlend = NULL;
        return;
    }

    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(ROUTE111)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(ROUTE111)
     || !FlagGet(FLAG_MIRAGE_TOWER_VISIBLE))
        return;

    sMirageTowerPulseBlend = AllocZeroed(sizeof(*sMirageTowerPulseBlend));
    InitPulseBlend(&sMirageTowerPulseBlend->pulseBlend);
    InitPulseBlendPaletteSettings(&sMirageTowerPulseBlend->pulseBlend, &gMirageTowerPulseBlendSettings);
    MarkUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    sMirageTowerPulseBlend->taskId = CreateTask(UpdateMirageTowerPulseBlend, 0xFF);
}

void ClearMirageTowerPulseBlendEffect(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(ROUTE111)
     || gSaveBlock1Ptr->location.mapNum   != MAP_NUM(ROUTE111)
     || !FlagGet(FLAG_MIRAGE_TOWER_VISIBLE)
     || sMirageTowerPulseBlend == NULL)
        return;

    if (FuncIsActiveTask(UpdateMirageTowerPulseBlend))
        DestroyTask(sMirageTowerPulseBlend->taskId);

    UnmarkUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    UnloadUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    FREE_AND_SET_NULL(sMirageTowerPulseBlend);
}

void SetMirageTowerVisibility(void)
{
    u16 rand;
    bool8 visible;

    if (VarGet(VAR_MIRAGE_TOWER_STATE))
    {
        FlagClear(FLAG_MIRAGE_TOWER_VISIBLE);
        return;
    }

    rand = Random();
    visible = rand & 1;
    if (FlagGet(FLAG_FORCE_MIRAGE_TOWER_VISIBLE) == TRUE)
        visible = TRUE;

    if (visible)
    {
        FlagSet(FLAG_MIRAGE_TOWER_VISIBLE);
        TryStartMirageTowerPulseBlendEffect();
        return;
    }

    FlagClear(FLAG_MIRAGE_TOWER_VISIBLE);
}

void StartPlayerDescendMirageTower(void)
{
    CreateTask(PlayerDescendMirageTower, 8);
}

static void PlayerDescendMirageTower(u8 taskId)
{
    u8 eventObjectId;
    struct EventObject *fakePlayerEventObject;
    struct EventObject *playerEventObject;

    TryGetEventObjectIdByLocalIdAndMap(45, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectId);
    fakePlayerEventObject = &gEventObjects[eventObjectId];
    gSprites[fakePlayerEventObject->spriteId].pos2.y += 4;
    playerEventObject = &gEventObjects[gPlayerAvatar.eventObjectId];
    if ((gSprites[fakePlayerEventObject->spriteId].pos1.y + gSprites[fakePlayerEventObject->spriteId].pos2.y) >=
        (gSprites[playerEventObject->spriteId].pos1.y + gSprites[playerEventObject->spriteId].pos2.y))
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

static void StartScreenShake(u8 yShakeOffset, u8 xShakeOffset, u8 numShakes, u8 shakeDelay)
{
    u8 taskId = CreateTask(DoScreenShake, 9);
    gTasks[taskId].data[0] = xShakeOffset;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = numShakes;
    gTasks[taskId].data[3] = shakeDelay;
    gTasks[taskId].data[4] = yShakeOffset;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_W070);
}

static void DoScreenShake(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    data[1]++;
    if (data[1] % data[3] == 0)
    {
        data[1] = 0;
        data[2]--;
        data[0] = -data[0];
        data[4] = -data[4];
        SetCameraPanning(data[0], data[4]);
        if (data[2] == 0)
        {
            IncrementCeilingCrumbleFinishedCount();
            DestroyTask(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void IncrementCeilingCrumbleFinishedCount(void)
{
    u8 taskId = FindTaskIdByFunc(WaitCeilingCrumble);
    if (taskId != 0xFF)
        gTasks[taskId].data[0]++;
}

void DoMirageTowerCeilingCrumble(void)
{
    LoadSpriteSheets(gMirageTowerCeilingCrumbleSpriteSheets);
    CreateCeilingCrumbleSprites();
    CreateTask(WaitCeilingCrumble, 8);
    StartScreenShake(2, 1, 16, 3);
}

static void WaitCeilingCrumble(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    data[1]++;
    // Either wait 1000 frames, or until all 16 crumble sprites and the one screen-shake task are completed.
    if (data[1] == 1000 || data[0] == 17)
        gTasks[taskId].func = FinishCeilingCrumbleTask;
}

static void FinishCeilingCrumbleTask(u8 taskId)
{
    FreeSpriteTilesByTag(4000);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void CreateCeilingCrumbleSprites(void)
{
    u8 i;
    u8 spriteId;

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sCeilingCrumbleSpriteTemplate1, sCeilingCrumblePositions[i][0] + 120, sCeilingCrumblePositions[i][1], 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
    }
    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sCeilingCrumbleSpriteTemplate2, sCeilingCrumblePositions[i][0] + 115, sCeilingCrumblePositions[i][1] - 3, 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
    }
}

static void MoveCeilingCrumbleSprite(struct Sprite* sprite)
{
    sprite->data[1] += 2;
    sprite->pos2.y = sprite->data[1] / 2;
    if(((sprite->pos1.y) + (sprite->pos2.y)) >  sCeilingCrumblePositions[sprite->data[0]][2])
    {
        DestroySprite(sprite);
        IncrementCeilingCrumbleFinishedCount();
    }
}

static void SetInvisibleMirageTowerMetatiles(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sInvisibleMirageTowerMetatiles); i++)
        MapGridSetMetatileIdAt(sInvisibleMirageTowerMetatiles[i].x + 7, sInvisibleMirageTowerMetatiles[i].y + 7, sInvisibleMirageTowerMetatiles[i].metatileId);
    DrawWholeMapView();
}

void StartMirageTowerDisintegration(void)
{
    CreateTask(DoMirageTowerDisintegration, 9);
}

void StartMirageTowerShake(void)
{
    CreateTask(InitMirageTowerShake, 9);
}

void StartMirageTowerFossilFallAndSink(void)
{
    CreateTask(DoFossilFallAndSink, 9);
}

static void SetBgShakeOffsets(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, sBgShakeOffsets->bgHOFS);
    SetGpuReg(REG_OFFSET_BG0VOFS, sBgShakeOffsets->bgVOFS);
}

static void UpdateBgShake(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        sBgShakeOffsets->bgHOFS = -sBgShakeOffsets->bgHOFS;
        gTasks[taskId].data[0] = 2;
        SetBgShakeOffsets();
    }
    else
    {
        gTasks[taskId].data[0]--;
    }
}

static void InitMirageTowerShake(u8 taskId)
{
    u8 zero;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_ATTR_PRIORITY, 2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        sMirageTowerGfxBuffer = (u8 *)AllocZeroed(MIRAGE_TOWER_GFX_LENGTH);
        sMirageTowerTilemapBuffer = (u8 *)AllocZeroed(BG_SCREEN_SIZE);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CpuSet(sBlankTile_Gfx, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH / 2);
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetBgTilemapBuffer(0, sMirageTowerTilemapBuffer);
        CopyToBgTilemapBufferRect_ChangePalette(0, &sMirageTowerTilemap, 12, 29, 6, 12, 17);
        CopyBgTilemapBufferToVram(0);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        ShowBg(0);
        gTasks[taskId].data[0]++;
        break;
    case 5:
        SetInvisibleMirageTowerMetatiles();
        gTasks[taskId].data[0]++;
        break;
    case 6:
        sBgShakeOffsets = Alloc(sizeof(*sBgShakeOffsets));
        zero = 0;
        sBgShakeOffsets->bgHOFS = 2;
        sBgShakeOffsets->bgVOFS = zero;
        CreateTask(UpdateBgShake, 10);
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
}

#define OUTER_BUFFER_LENGTH 0x60
#define INNER_BUFFER_LENGTH 0x30
static void DoMirageTowerDisintegration(u8 taskId)
{
    u8 bgShakeTaskId, j;
    u16 i;
    u8 index;

    switch (gTasks[taskId].data[0])
    {
    case 1:
        sUnknown_0203CF10 = AllocZeroed(OUTER_BUFFER_LENGTH * sizeof(struct Struct203CF10));
        break;
    case 3:
        if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
        {
            if (gTasks[taskId].data[1] > 1)
            {
                index = gTasks[taskId].data[3];
                sUnknown_0203CF10[index].buffer = Alloc(INNER_BUFFER_LENGTH);
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                    sUnknown_0203CF10[index].buffer[i] = i;
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                {
                    u16 rand1, rand2, temp;

                    rand1 = Random() % 0x30;
                    rand2 = Random() % 0x30;
                    SWAP(sUnknown_0203CF10[index].buffer[rand2], sUnknown_0203CF10[index].buffer[rand1], temp);
                }
                if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
                    gTasks[taskId].data[3]++;
                gTasks[taskId].data[1] = 0;
            }
            gTasks[taskId].data[1]++;
        }
        index = gTasks[taskId].data[3];
        for (i = (u8)(gTasks[taskId].data[2]); i < index; i++)
        {
            for (j = 0; j < 1; j++)
            {
                sub_81BF2B8(sMirageTowerGfxBuffer,
                            ((((OUTER_BUFFER_LENGTH - 1) - i) * INNER_BUFFER_LENGTH) + sUnknown_0203CF10[i].buffer[(sUnknown_0203CF10[i].currIndex)++]),
                            0, INNER_BUFFER_LENGTH, 1);
            }
            if (sUnknown_0203CF10[i].currIndex > (INNER_BUFFER_LENGTH - 1))
            {
                FREE_AND_SET_NULL(sUnknown_0203CF10[i].buffer);
                gTasks[taskId].data[2]++;
                if ((i % 2) == 1)
                    sBgShakeOffsets->bgVOFS--;
            }
        }
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        if (sUnknown_0203CF10[OUTER_BUFFER_LENGTH - 1].currIndex > (INNER_BUFFER_LENGTH - 1))
            break;
        return;
    case 4:
        UnsetBgTilemapBuffer(0);
        bgShakeTaskId = FindTaskIdByFunc(UpdateBgShake);
        if (bgShakeTaskId != 0xFF)
            DestroyTask(bgShakeTaskId);
        sBgShakeOffsets->bgVOFS = sBgShakeOffsets->bgHOFS = 0;
        SetBgShakeOffsets();
        break;
    case 5:
        FREE_AND_SET_NULL(sBgShakeOffsets);
        FREE_AND_SET_NULL(sUnknown_0203CF10);
        FREE_AND_SET_NULL(sMirageTowerGfxBuffer);
        FREE_AND_SET_NULL(sMirageTowerTilemapBuffer);
        break;
    case 6:
        SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2));
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0));
        SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
        InitStandardTextBoxWindows();
        break;
    case 7:
        ShowBg(0);
        break;
    case 8:
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
    gTasks[taskId].data[0]++;
}

static void DoFossilFallAndSink(u8 taskId)
{
    u16 i;
    u8 *buffer;

    switch (gTasks[taskId].data[0])
    {
    case 1:
        sUnknown_0203CF0C = AllocZeroed(sizeof(*sUnknown_0203CF0C));
        sUnknown_0203CF0C->frameImageTiles = AllocZeroed(ROOT_FOSSIL_GFX_LENGTH);
        sUnknown_0203CF0C->frameImage = AllocZeroed(sizeof(*sUnknown_0203CF0C->frameImage));
        sUnknown_0203CF0C->unkC = AllocZeroed(ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16));
        sUnknown_0203CF0C->unk10 = 0;
        break;
    case 2:
        buffer = sUnknown_0203CF0C->frameImageTiles;
        for (i = 0; i < ROOT_FOSSIL_GFX_LENGTH; i++, buffer++)
            *buffer = sRootFossil_Gfx[i];
        break;
    case 3:
        sUnknown_0203CF0C->frameImage->data = sUnknown_0203CF0C->frameImageTiles;
        sUnknown_0203CF0C->frameImage->size = ROOT_FOSSIL_GFX_LENGTH;
        break;
    case 4:
        {
            struct SpriteTemplate fossilTemplate;

            fossilTemplate = gUnknown_08617E00;
            fossilTemplate.images = (struct SpriteFrameImage *)(sUnknown_0203CF0C->frameImage);
            sUnknown_0203CF0C->spriteId = CreateSprite(&fossilTemplate, 128, -16, 1);
            gSprites[sUnknown_0203CF0C->spriteId].centerToCornerVecX = 0;
            gSprites[sUnknown_0203CF0C->spriteId].data[0] = gSprites[sUnknown_0203CF0C->spriteId].pos1.x;
            gSprites[sUnknown_0203CF0C->spriteId].data[1] = 1;
        }
    case 5:
        for (i = 0; i < ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH; i++)
            sUnknown_0203CF0C->unkC[i] = i;
        break;
    case 6:
        for (i = 0; i < (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16)); i++)
        {
            u16 rand1, rand2, temp;

            rand1 = Random() % 0x100;
            rand2 = Random() % 0x100;
            SWAP(sUnknown_0203CF0C->unkC[rand2], sUnknown_0203CF0C->unkC[rand1], temp);
        }
        gSprites[sUnknown_0203CF0C->spriteId].callback = sub_81BF248;
        break;
    case 7:
        if (gSprites[sUnknown_0203CF0C->spriteId].callback != SpriteCallbackDummy)
            return;
        DestroySprite(&gSprites[sUnknown_0203CF0C->spriteId]);
        FREE_AND_SET_NULL(sUnknown_0203CF0C->unkC);;
        FREE_AND_SET_NULL(sUnknown_0203CF0C->frameImage);
        FREE_AND_SET_NULL(sUnknown_0203CF0C->frameImageTiles);
        FREE_AND_SET_NULL(sUnknown_0203CF0C);
        break;
    case 8:
        EnableBothScriptContexts();
        break;
    }

    gTasks[taskId].data[0]++;
}

static void sub_81BF248(struct Sprite *sprite)
{
    if (sUnknown_0203CF0C->unk10 >= (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else if (sprite->pos1.y >= 96)
    {
        u8 i;
        for (i = 0; i < 2; i++)
            sub_81BF2B8(sUnknown_0203CF0C->frameImageTiles, sUnknown_0203CF0C->unkC[sUnknown_0203CF0C->unk10++], 0, 16, 0);

        StartSpriteAnim(sprite, 0);
    }
    else
    {
        sprite->pos1.y++;
    }
}

#ifdef NONMATCHING
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e)
{
    u8 r5, r4, r0, r2;
    u16 var;

    r4 = r5 = b / d;
    gUnknown_030012A8[0] = r4;

    r0 = r2 = b % d;
    gUnknown_030012A8[1] = r2;

    r4 &= 7;
    r2 &= 7;
    gUnknown_030012A8[2] = r4;
    gUnknown_030012A8[3] = r2;

    r0 /= 8;
    r5 /= 8;
    gUnknown_030012A8[4] = r0;
    gUnknown_030012A8[5] = r5;

    var = ((d / 8) * (r5 * 64)) + (r0 * 64);
    gUnknown_030012A8[6] = var;

    var += (r4 * 8) + r2;
    gUnknown_030012A8[7] = var;

    // This part is non-matching. 99% sure it IS functionally equivalent, though.
    b = (b & 1) ^ 1;
    c = (c << ((b) << 2)) | (15 << ((b ^ 1) << 2));

    a[(var / 2) + (e * 32)] &= c;
}

#else
NAKED
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x8\n\
    str r0, [sp]\n\
    mov r10, r1\n\
    adds r6, r2, 0\n\
    mov r8, r3\n\
    ldr r0, [sp, 0x28]\n\
    mov r9, r0\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    mov r10, r1\n\
    lsls r6, 24\n\
    lsrs r6, 24\n\
    mov r0, r8\n\
    lsls r0, 24\n\
    mov r8, r0\n\
    lsrs r7, r0, 24\n\
    mov r1, r9\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r9, r1\n\
    mov r0, r10\n\
    adds r1, r7, 0\n\
    bl __divsi3\n\
    adds r5, r0, 0\n\
    lsls r5, 24\n\
    lsrs r4, r5, 24\n\
    ldr r3, =gUnknown_030012A8\n\
    strh r4, [r3]\n\
    mov r0, r10\n\
    adds r1, r7, 0\n\
    str r3, [sp, 0x4]\n\
    bl __modsi3\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    ldr r3, [sp, 0x4]\n\
    strh r2, [r3, 0x2]\n\
    movs r1, 0x7\n\
    ands r4, r1\n\
    ands r2, r1\n\
    strh r4, [r3, 0x4]\n\
    strh r2, [r3, 0x6]\n\
    lsrs r0, 27\n\
    lsrs r5, 27\n\
    strh r0, [r3, 0x8]\n\
    strh r5, [r3, 0xA]\n\
    mov r1, r8\n\
    lsrs r1, 27\n\
    lsls r1, 6\n\
    mov r8, r1\n\
    mov r1, r8\n\
    muls r1, r5\n\
    lsls r0, 6\n\
    adds r1, r0\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    strh r1, [r3, 0xC]\n\
    lsls r4, 3\n\
    adds r4, r2\n\
    adds r1, r4\n\
    lsls r4, r1, 16\n\
    lsrs r4, 17\n\
    strh r1, [r3, 0xE]\n\
    movs r1, 0x1\n\
    mov r0, r10\n\
    ands r1, r0\n\
    movs r2, 0x1\n\
    eors r1, r2\n\
    lsls r0, r1, 2\n\
    lsls r6, r0\n\
    eors r1, r2\n\
    lsls r1, 2\n\
    movs r0, 0xF\n\
    lsls r0, r1\n\
    orrs r6, r0\n\
    lsls r6, 24\n\
    lsrs r6, 24\n\
    mov r1, r9\n\
    lsls r1, 5\n\
    mov r9, r1\n\
    add r9, r4\n\
    ldr r1, [sp]\n\
    add r1, r9\n\
    ldrb r0, [r1]\n\
    ands r6, r0\n\
    strb r6, [r1]\n\
    add sp, 0x8\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
                ");
}
#endif // NONMATCHING

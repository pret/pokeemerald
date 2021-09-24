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
#include "palette_util.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

struct MirageTowerPulseBlend
{
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

struct FallAnim_Tower
{
    u8 *disintegrateRand;
    u8 disintegrateIdx;
};

struct FallAnim_Fossil
{
    u8 *frameImageTiles;
    struct SpriteFrameImage *frameImage;
    u8 spriteId;
    u16 *disintegrateRand;
    u16 disintegrateIdx;
};

#define TAG_CEILING_CRUMBLE 4000

#define MIRAGE_TOWER_GFX_LENGTH (sizeof(sBlankTile_Gfx) + sizeof(sMirageTower_Gfx))
#define FOSSIL_DISINTEGRATE_LENGTH 0x100

static const struct SpriteSheet sCeilingCrumbleSpriteSheets[];
static const s16 sCeilingCrumblePositions[][3];

static void PlayerDescendMirageTower(u8);
static void DoScreenShake(u8);
static void IncrementCeilingCrumbleFinishedCount(void);
static void WaitCeilingCrumble(u8);
static void FinishCeilingCrumbleTask(u8);
static void CreateCeilingCrumbleSprites(void);
static void SpriteCB_CeilingCrumble(struct Sprite*);
static void DoMirageTowerDisintegration(u8);
static void InitMirageTowerShake(u8);
static void Task_FossilFallAndSink(u8);
static void SpriteCB_FallingFossil(struct Sprite *);
static void UpdateDisintegrationEffect(u8*, u16, u8, u8, u8);

static const u8 sBlankTile_Gfx[32] = {0};
static const u8 sMirageTower_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower.4bpp");
static const u16 sMirageTowerTilemap[] = INCBIN_U16("graphics/misc/mirage_tower.bin");
static const u16 sFossil_Pal[] = INCBIN_U16("graphics/object_events/pics/misc/fossil.gbapal"); // Unused
static const u8 sFossil_Gfx[] = INCBIN_U8("graphics/object_events/pics/misc/fossil.4bpp"); // Duplicate of gObjectEventPic_Fossil
static const u8 sMirageTowerCrumbles_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower_crumbles.4bpp");
static const u16 sMirageTowerCrumbles_Palette[] = INCBIN_U16("graphics/misc/mirage_tower_crumbles.gbapal");

static const s16 sCeilingCrumblePositions[][3] =
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

static const struct SpriteSheet sCeilingCrumbleSpriteSheets[] =
{
    {sMirageTowerCrumbles_Gfx, 0x80, TAG_CEILING_CRUMBLE},
    {}
};

static const struct MetatileCoords sInvisibleMirageTowerMetatiles[] =
{
    {18, 53, METATILE_Mauville_DeepSand_Center},
    {19, 53, METATILE_Mauville_DeepSand_Center},
    {20, 53, METATILE_Mauville_DeepSand_Center},
    {18, 54, METATILE_Mauville_DeepSand_Center},
    {19, 54, METATILE_Mauville_DeepSand_Center},
    {20, 54, METATILE_Mauville_DeepSand_Center},
    {18, 55, METATILE_Mauville_DeepSand_Center},
    {19, 55, METATILE_Mauville_DeepSand_Center},
    {20, 55, METATILE_Mauville_DeepSand_Center},
    {18, 56, METATILE_Mauville_DeepSand_Center},
    {19, 56, METATILE_Mauville_DeepSand_Center},
    {20, 56, METATILE_Mauville_DeepSand_Center},
    {18, 57, METATILE_Mauville_DeepSand_BottomMid},
    {19, 57, METATILE_Mauville_DeepSand_BottomMid},
    {20, 57, METATILE_Mauville_DeepSand_BottomMid},
    {18, 58, METATILE_General_SandPit_Center},
    {19, 58, METATILE_General_SandPit_Center},
    {20, 58, METATILE_General_SandPit_Center},
};

static const union AnimCmd sAnim_FallingFossil[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const struct OamData sOamData_FallingFossil =
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

static const union AnimCmd *const sAnims_FallingFossil[] =
{
    sAnim_FallingFossil,
};

static const struct SpriteTemplate sSpriteTemplate_FallingFossil =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0xFFFF,
    .oam = &sOamData_FallingFossil,
    .anims = sAnims_FallingFossil,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
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

static const union AnimCmd sAnim_CeilingCrumbleSmall[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_CeilingCrumbleSmall[] =
{
    sAnim_CeilingCrumbleSmall,
};

static const struct OamData sOamData_CeilingCrumbleSmall =
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

static const struct SpriteTemplate sSpriteTemplate_CeilingCrumbleSmall = {
    .tileTag = TAG_CEILING_CRUMBLE,
    .paletteTag = 0xFFFF,
    .oam = &sOamData_CeilingCrumbleSmall,
    .anims = sAnims_CeilingCrumbleSmall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CeilingCrumble
};

static const union AnimCmd sAnim_CeilingCrumbleLarge[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_CeilingCrumbleLarge[] =
{
    sAnim_CeilingCrumbleLarge,
};

static const struct OamData sOamData_CeilingCrumbleLarge =
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

static const struct SpriteTemplate sSpriteTemplate_CeilingCrumbleLarge = {
    .tileTag = TAG_CEILING_CRUMBLE,
    .paletteTag = 0xFFFF,
    .oam = &sOamData_CeilingCrumbleLarge,
    .anims = sAnims_CeilingCrumbleLarge,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CeilingCrumble
};

EWRAM_DATA static u8* sMirageTowerGfxBuffer = NULL;
EWRAM_DATA static u8* sMirageTowerTilemapBuffer = NULL;
EWRAM_DATA static struct FallAnim_Fossil *sFallingFossil = NULL;
EWRAM_DATA static struct FallAnim_Tower *sFallingTower = NULL;
EWRAM_DATA static struct BgRegOffsets *sBgShakeOffsets = NULL;
EWRAM_DATA static struct MirageTowerPulseBlend *sMirageTowerPulseBlend = NULL;

// Holds data about the disintegration effect for Mirage Tower / the unchosen fossil.
// Never read, presumably for debugging
static u16 sDebug_DisintegrationData[8];

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
        // Mirage Tower event has already been completed, hide it
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

// As the tower disintegrates, a duplicate object event of the player
// is created at the top of the tower and moved down to show the player falling
static void PlayerDescendMirageTower(u8 taskId)
{
    u8 objectEventId;
    struct ObjectEvent *fallingPlayer;
    struct ObjectEvent *player;

    TryGetObjectEventIdByLocalIdAndMap(LOCALID_ROUTE111_PLAYER_FALLING, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    fallingPlayer = &gObjectEvents[objectEventId];
    gSprites[fallingPlayer->spriteId].y2 += 4;
    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    if ((gSprites[fallingPlayer->spriteId].y + gSprites[fallingPlayer->spriteId].y2) >=
        (gSprites[player->spriteId].y + gSprites[player->spriteId].y2))
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

#define tXShakeOffset data[0]
#define tTimer        data[1]
#define tNumShakes    data[2]
#define tShakeDelay   data[3]
#define tYShakeOffset data[4]

static void StartScreenShake(u8 yShakeOffset, u8 xShakeOffset, u8 numShakes, u8 shakeDelay)
{
    u8 taskId = CreateTask(DoScreenShake, 9);
    gTasks[taskId].tXShakeOffset = xShakeOffset;
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tNumShakes = numShakes;
    gTasks[taskId].tShakeDelay = shakeDelay;
    gTasks[taskId].tYShakeOffset = yShakeOffset;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_M_STRENGTH);
}

static void DoScreenShake(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    tTimer++;
    if (tTimer % tShakeDelay == 0)
    {
        tTimer = 0;
        tNumShakes--;
        tXShakeOffset = -tXShakeOffset;
        tYShakeOffset = -tYShakeOffset;
        SetCameraPanning(tXShakeOffset, tYShakeOffset);
        if (tNumShakes == 0)
        {
            IncrementCeilingCrumbleFinishedCount();
            DestroyTask(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

#undef tXShakeOffset
#undef tTimer
#undef tNumShakes
#undef tShakeDelay
#undef tYShakeOffset

static void IncrementCeilingCrumbleFinishedCount(void)
{
    u8 taskId = FindTaskIdByFunc(WaitCeilingCrumble);
    if (taskId != TASK_NONE)
        gTasks[taskId].data[0]++;
}

void DoMirageTowerCeilingCrumble(void)
{
    LoadSpriteSheets(sCeilingCrumbleSpriteSheets);
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
    FreeSpriteTilesByTag(TAG_CEILING_CRUMBLE);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void CreateCeilingCrumbleSprites(void)
{
    u8 i;
    u8 spriteId;

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_CeilingCrumbleLarge, sCeilingCrumblePositions[i][0] + 120, sCeilingCrumblePositions[i][1], 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
    }
    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_CeilingCrumbleSmall, sCeilingCrumblePositions[i][0] + 115, sCeilingCrumblePositions[i][1] - 3, 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
    }
}

static void SpriteCB_CeilingCrumble(struct Sprite* sprite)
{
    sprite->data[1] += 2;
    sprite->y2 = sprite->data[1] / 2;
    if(((sprite->y) + (sprite->y2)) >  sCeilingCrumblePositions[sprite->data[0]][2])
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
    CreateTask(Task_FossilFallAndSink, 9);
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

#define tState data[0]

static void InitMirageTowerShake(u8 taskId)
{
    u8 zero;

    switch (gTasks[taskId].tState)
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_ATTR_PRIORITY, 2);
        gTasks[taskId].tState++;
        break;
    case 1:
        sMirageTowerGfxBuffer = (u8 *)AllocZeroed(MIRAGE_TOWER_GFX_LENGTH);
        sMirageTowerTilemapBuffer = (u8 *)AllocZeroed(BG_SCREEN_SIZE);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        gTasks[taskId].tState++;
        break;
    case 2:
        CpuSet(sBlankTile_Gfx, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH / 2);
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        gTasks[taskId].tState++;
        break;
    case 3:
        SetBgTilemapBuffer(0, sMirageTowerTilemapBuffer);
        CopyToBgTilemapBufferRect_ChangePalette(0, &sMirageTowerTilemap, 12, 29, 6, 12, 17);
        CopyBgTilemapBufferToVram(0);
        gTasks[taskId].tState++;
        break;
    case 4:
        ShowBg(0);
        gTasks[taskId].tState++;
        break;
    case 5:
        SetInvisibleMirageTowerMetatiles();
        gTasks[taskId].tState++;
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

    switch (gTasks[taskId].tState)
    {
    case 1:
        sFallingTower = AllocZeroed(OUTER_BUFFER_LENGTH * sizeof(struct FallAnim_Tower));
        break;
    case 3:
        if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
        {
            if (gTasks[taskId].data[1] > 1)
            {
                // Initialize disintegration pattern
                index = gTasks[taskId].data[3];
                sFallingTower[index].disintegrateRand = Alloc(INNER_BUFFER_LENGTH);
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                    sFallingTower[index].disintegrateRand[i] = i;

                // Randomize disintegration pattern
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                {
                    u16 rand1, rand2, temp;
                    rand1 = Random() % INNER_BUFFER_LENGTH;
                    rand2 = Random() % INNER_BUFFER_LENGTH;
                    SWAP(sFallingTower[index].disintegrateRand[rand2], sFallingTower[index].disintegrateRand[rand1], temp);
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
                UpdateDisintegrationEffect(sMirageTowerGfxBuffer,
                            (OUTER_BUFFER_LENGTH - 1 - i) * INNER_BUFFER_LENGTH + sFallingTower[i].disintegrateRand[sFallingTower[i].disintegrateIdx++],
                            0, INNER_BUFFER_LENGTH, 1);
            }
            if (sFallingTower[i].disintegrateIdx > (INNER_BUFFER_LENGTH - 1))
            {
                FREE_AND_SET_NULL(sFallingTower[i].disintegrateRand);
                gTasks[taskId].data[2]++;
                if ((i % 2) == 1)
                    sBgShakeOffsets->bgVOFS--;
            }
        }
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        if (sFallingTower[OUTER_BUFFER_LENGTH - 1].disintegrateIdx > INNER_BUFFER_LENGTH - 1)
            break;
        return;
    case 4:
        UnsetBgTilemapBuffer(0);
        bgShakeTaskId = FindTaskIdByFunc(UpdateBgShake);
        if (bgShakeTaskId != TASK_NONE)
            DestroyTask(bgShakeTaskId);
        sBgShakeOffsets->bgVOFS = sBgShakeOffsets->bgHOFS = 0;
        SetBgShakeOffsets();
        break;
    case 5:
        FREE_AND_SET_NULL(sBgShakeOffsets);
        FREE_AND_SET_NULL(sFallingTower);
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
    gTasks[taskId].tState++;
}

static void Task_FossilFallAndSink(u8 taskId)
{
    u16 i;
    u8 *buffer;

    switch (gTasks[taskId].tState)
    {
    case 1:
        sFallingFossil = AllocZeroed(sizeof(*sFallingFossil));
        sFallingFossil->frameImageTiles = AllocZeroed(sizeof(sFossil_Gfx));
        sFallingFossil->frameImage = AllocZeroed(sizeof(*sFallingFossil->frameImage));
        sFallingFossil->disintegrateRand = AllocZeroed(FOSSIL_DISINTEGRATE_LENGTH * sizeof(u16));
        sFallingFossil->disintegrateIdx = 0;
        break;
    case 2:
        buffer = sFallingFossil->frameImageTiles;
        for (i = 0; i < sizeof(sFossil_Gfx); i++, buffer++)
            *buffer = sFossil_Gfx[i];
        break;
    case 3:
        sFallingFossil->frameImage->data = sFallingFossil->frameImageTiles;
        sFallingFossil->frameImage->size = sizeof(sFossil_Gfx);
        break;
    case 4:
        {
            struct SpriteTemplate fossilTemplate = sSpriteTemplate_FallingFossil;
            fossilTemplate.images = sFallingFossil->frameImage;
            sFallingFossil->spriteId = CreateSprite(&fossilTemplate, 128, -16, 1);
            gSprites[sFallingFossil->spriteId].centerToCornerVecX = 0;
            gSprites[sFallingFossil->spriteId].data[0] = gSprites[sFallingFossil->spriteId].x;
            gSprites[sFallingFossil->spriteId].data[1] = 1;
        }
    case 5:
        // Initialize disintegration pattern
        for (i = 0; i < FOSSIL_DISINTEGRATE_LENGTH; i++)
            sFallingFossil->disintegrateRand[i] = i;
        break;
    case 6:
        // Randomize disintegration pattern
        for (i = 0; i < FOSSIL_DISINTEGRATE_LENGTH * sizeof(u16); i++)
        {
            u16 rand1, rand2, temp;
            rand1 = Random() % FOSSIL_DISINTEGRATE_LENGTH;
            rand2 = Random() % FOSSIL_DISINTEGRATE_LENGTH;
            SWAP(sFallingFossil->disintegrateRand[rand2], sFallingFossil->disintegrateRand[rand1], temp);
        }
        gSprites[sFallingFossil->spriteId].callback = SpriteCB_FallingFossil;
        break;
    case 7:
        // Wait for fossil to finish falling / disintegrating
        if (gSprites[sFallingFossil->spriteId].callback != SpriteCallbackDummy)
            return;
        DestroySprite(&gSprites[sFallingFossil->spriteId]);
        FREE_AND_SET_NULL(sFallingFossil->disintegrateRand);;
        FREE_AND_SET_NULL(sFallingFossil->frameImage);
        FREE_AND_SET_NULL(sFallingFossil->frameImageTiles);
        FREE_AND_SET_NULL(sFallingFossil);
        break;
    case 8:
        EnableBothScriptContexts();
        break;
    }
    gTasks[taskId].tState++;
}

static void SpriteCB_FallingFossil(struct Sprite *sprite)
{
    if (sFallingFossil->disintegrateIdx >= FOSSIL_DISINTEGRATE_LENGTH)
    {
        // End animation
        sprite->callback = SpriteCallbackDummy;
    }
    else if (sprite->y >= 96)
    {
        // Fossil has reached the ground, update disintegration animation
        u8 i;
        for (i = 0; i < 2; i++)
            UpdateDisintegrationEffect(sFallingFossil->frameImageTiles, sFallingFossil->disintegrateRand[sFallingFossil->disintegrateIdx++], 0, 16, 0);

        StartSpriteAnim(sprite, 0);
    }
    else
    {
        // Fossil is still falling
        sprite->y++;
    }
}

static void UpdateDisintegrationEffect(u8* tiles, u16 randId, u8 c, u8 size, u8 offset)
{
    u8 heightTiles, height, widthTiles, width;
    u16 var, baseOffset;
    u8 col, row;
    u8 flag, tileMask;

    height = randId / size;
    sDebug_DisintegrationData[0] = height;

    width = randId % size;
    sDebug_DisintegrationData[1] = width;

    row = height & 7;
    col = width & 7;
    sDebug_DisintegrationData[2] = height & 7;
    sDebug_DisintegrationData[3] = width & 7;

    widthTiles = width / 8;
    heightTiles = height / 8;
    sDebug_DisintegrationData[4] = width / 8;
    sDebug_DisintegrationData[5] = height / 8;

    var = (size / 8) * (heightTiles * 64) + (widthTiles * 64);
    sDebug_DisintegrationData[6] = var;

    baseOffset = var + ((row * 8) + col);
    baseOffset /= 2;
    sDebug_DisintegrationData[7] = var + ((row * 8) + col);

    flag = ((randId % 2) ^ 1);
    tileMask = (c << (flag << 2)) | 15 << (((flag ^ 1) << 2));
    tiles[baseOffset + (offset * 32)] &= tileMask;
}

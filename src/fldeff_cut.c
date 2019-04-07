#include "global.h"
#include "event_obj_lock.h"
#include "event_object_movement.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "alloc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

extern struct MapPosition gPlayerFacingPosition;

extern const u8 EventScript_FldEffCut[];
extern const u8 FarawayIsland_Interior_EventScript_267EDB[];

extern const u8 gFieldEffectPic_CutGrass[];
extern const u16 gFieldEffectObjectPalette6[];

// tileset 0 as first
#define METATILE_ID_GRASS 0x1
#define METATILE_ID_POKE_GRASS 0xD

#define METATILE_ID_POKE_GRASS_TREE_UP 0x25
#define METATILE_ID_GRASS_TREE_UP 0xE

#define METATILE_ID_POKE_GRASS_TREE_LEFT 0x1C6
#define METATILE_ID_POKE_GRASS_TREE_RIGHT 0x1C7

#define METATILE_ID_GRASS_TREE_LEFT 0x1CE
#define METATILE_ID_GRASS_TREE_RIGHT 0x1CF

#define METATILE_ID_POKE_LONG_GRASS 0x15

// tileset 6 as second
#define METATILE_ID_POKE_STEP_LAVA_GRASS 0x206
#define METATILE_ID_POKE_LAVA_GRASS 0x207
#define METATILE_ID_LAVA_FIELD 0x271

// tileset 7 as second
#define METATILE_ID_POKE_ASH_GRASS 0x20A
#define METATILE_ID_POKE_STEP_ASH_GRASS 0x212
#define METATILE_ID_ASH 0x218

// tileset 8 as second
#define METATILE_ID_POKE_LONG_GRASS_START 0x208

#define METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS 0x279
#define METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS 0x27A
#define METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS 0x27B

#define METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS 0x281
#define METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS 0x282
#define METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS 0x283

// cut 'square' defines
#define CUT_NORMAL_SIDE 3
#define CUT_NORMAL_AREA CUT_NORMAL_SIDE * CUT_NORMAL_SIDE

#define CUT_HYPER_SIDE 5
#define CUT_HYPER_AREA CUT_HYPER_SIDE * CUT_HYPER_SIDE

#define CUT_SPRITE_ARRAY_COUNT 8

struct HyperCutterUnk
{
    s8 x;
    s8 y;
    u8 unk2[2];
};

// this file's functions
static void FieldCallback_CutTree(void);
static void FieldCallback_CutGrass(void);
static void StartCutTreeFieldEffect(void);
static void StartCutGrassFieldEffect(void);
static void SetCutGrassMetatile(s16, s16);
static void SetCutGrassMetatiles(s16, s16);
static void CutGrassSpriteCallback1(struct Sprite *);
static void CutGrassSpriteCallback2(struct Sprite *);
static void CutGrassSpriteCallbackEnd(struct Sprite *);
static void HandleLongGrassOnHyper(u8, s16, s16);

// IWRAM variables
static IWRAM_DATA u8 sCutSquareSide;
static IWRAM_DATA u8 sTileCountFromPlayer_X;
static IWRAM_DATA u8 sTileCountFromPlayer_Y;
static IWRAM_DATA u32 sUnused;
static IWRAM_DATA bool8 sHyperCutTiles[CUT_HYPER_AREA];

// EWRAM variables
static EWRAM_DATA u8 *sCutGrassSpriteArrayPtr = NULL;

// const rom data
static const struct HyperCutterUnk sHyperCutStruct[] =
{
    {-2, -2, {1}},
    {-1, -2, {1}},
    {0, -2, {2}},
    {1, -2, {3}},
    {2, -2, {3}},
    {-2, -1, {1}},
    {2, -1, {3}},
    {-2, 0, {4}},
    {2, 0, {6}},
    {-2, 1, {7}},
    {2, 1, {9}},
    {-2, 2, {7}},
    {-1, 2, {7}},
    {0, 2, {8}},
    {1, 2, {9}},
    {2, 2, {9}},
};

static const struct OamData sOamData_CutGrass =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 1,
    .priority = 1,
    .paletteNum = 1,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_CutGrass[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_CutGrass[] =
{
    sSpriteAnim_CutGrass,
};

static const struct SpriteFrameImage sSpriteImageTable_CutGrass[] =
{
    {gFieldEffectPic_CutGrass, 0x20},
};

const struct SpritePalette gFieldEffectObjectPaletteInfo6 = {gFieldEffectObjectPalette6, 0x1000};

static const struct SpriteTemplate sSpriteTemplate_CutGrass =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1000,
    .oam = &sOamData_CutGrass,
    .anims = sSpriteAnimTable_CutGrass,
    .images = sSpriteImageTable_CutGrass,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CutGrassSpriteCallback1,
};

// code
bool8 SetUpFieldMove_Cut(void)
{
    s16 x, y;
    u8 i, j;
    u8 tileBehavior;
    u8 userAbility;
    bool8 cutTiles[CUT_NORMAL_AREA];
    bool8 ret;

    if (CheckObjectGraphicsInFrontOfPlayer(EVENT_OBJ_GFX_CUTTABLE_TREE) == TRUE)
    {
        // Standing in front of cuttable tree.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_CutTree;
        return TRUE;
    }
    else
    {
        PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
        userAbility = GetMonAbility(&gPlayerParty[GetCursorSelectionMonId()]);
        if (userAbility == ABILITY_HYPER_CUTTER)
        {
            sCutSquareSide = CUT_HYPER_SIDE;
            sTileCountFromPlayer_X = 2;
            sTileCountFromPlayer_Y = 2;
        }
        else
        {
            sCutSquareSide = CUT_NORMAL_SIDE;
            sTileCountFromPlayer_X = 1;
            sTileCountFromPlayer_Y = 1;
        }

        for (i = 0; i < CUT_NORMAL_AREA; i++)
            cutTiles[i] = FALSE;
        for (i = 0; i < CUT_HYPER_AREA; i++)
            sHyperCutTiles[i] = FALSE;

        ret = FALSE;

        for (i = 0; i < CUT_NORMAL_SIDE; i++)
        {
            y = i - 1 + gPlayerFacingPosition.y;
            for (j = 0; j < CUT_NORMAL_SIDE; j++)
            {
                x = j - 1 + gPlayerFacingPosition.x;
                if (MapGridGetZCoordAt(x, y) == gPlayerFacingPosition.height)
                {
                    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                    if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                    || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                    {
                        // Standing in front of grass.
                        sHyperCutTiles[6 + (i * 5) + j] = TRUE;
                        ret = TRUE;
                    }
                    if (MapGridIsImpassableAt(x, y) == TRUE)
                    {
                        cutTiles[i * 3 + j] = FALSE;
                    }
                    else
                    {
                        cutTiles[i * 3 + j] = TRUE;
                        if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                            sHyperCutTiles[6 + (i * 5) + j] = TRUE;
                    }
                }
                else
                {
                    cutTiles[i * 3 + j] = FALSE;
                }
            }
        }

        if (userAbility != ABILITY_HYPER_CUTTER)
        {
            if (ret == TRUE)
            {
                gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                gPostMenuFieldCallback = FieldCallback_CutGrass;
            }
        }
        else
        {
            bool8 tileCuttable;
            for (i = 0; i < 16; i++)
            {
                x = gPlayerFacingPosition.x + sHyperCutStruct[i].x;
                y = gPlayerFacingPosition.y + sHyperCutStruct[i].y;
                tileCuttable = TRUE;

                j = 0;
                do
                {
                    if (sHyperCutStruct[i].unk2[j] == 0)
                        break;
                    if (cutTiles[(u8)(sHyperCutStruct[i].unk2[j] - 1)] == FALSE)
                    {
                        tileCuttable = FALSE;
                        break;
                    }
                } while (++j <= 1);

                if (tileCuttable == TRUE)
                {
                    if (MapGridGetZCoordAt(x, y) == gPlayerFacingPosition.height)
                    {
                        u8 tileArrayId = ((sHyperCutStruct[i].y * 5) + 12) + (sHyperCutStruct[i].x);
                        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                        if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                        || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                        {
                            gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                            gPostMenuFieldCallback = FieldCallback_CutGrass;
                            sHyperCutTiles[tileArrayId] = TRUE;
                            ret = TRUE;
                        }
                        else
                        {
                            if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                                sHyperCutTiles[tileArrayId] = TRUE;
                        }
                    }
                }
            }

            if (ret == TRUE)
            {
                gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                gPostMenuFieldCallback = FieldCallback_CutGrass;
            }
        }

        return ret;
    }
}

static void FieldCallback_CutGrass(void)
{
    FieldEffectStart(FLDEFF_USE_CUT_ON_GRASS);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_UseCutOnGrass(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartCutGrassFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartCutGrassFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void FieldCallback_CutTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_FldEffCut);
}

bool8 FldEff_UseCutOnTree(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartCutTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartCutTreeFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void StartCutGrassFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_GRASS);
    FieldEffectStart(FLDEFF_CUT_GRASS);
}

bool8 FldEff_CutGrass(void)
{
    s16 x, y;
    u8 i = 0;

    PlaySE(SE_W015);
    PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    for (i = 0; i < CUT_HYPER_AREA; i++)
    {
        if (sHyperCutTiles[i] == TRUE)
        {
            s8 xAdd = (i % 5) - 2;
            s8 yAdd = (i / 5) - 2;

            x = xAdd + gPlayerFacingPosition.x;
            y = yAdd + gPlayerFacingPosition.y;

            SetCutGrassMetatile(x, y);
            sub_808E75C(x, y);
        }
    }

    SetCutGrassMetatiles(gPlayerFacingPosition.x - sTileCountFromPlayer_X, gPlayerFacingPosition.y - (1 + sTileCountFromPlayer_Y));
    DrawWholeMapView();
    sCutGrassSpriteArrayPtr = AllocZeroed(CUT_SPRITE_ARRAY_COUNT);

    // populate sprite ID array
    for (i = 0; i < CUT_SPRITE_ARRAY_COUNT; i++)
    {
        sCutGrassSpriteArrayPtr[i] = CreateSprite(&sSpriteTemplate_CutGrass,
        gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y + 20, 0);
        gSprites[sCutGrassSpriteArrayPtr[i]].data[2] = 32 * i;
    }

    return FALSE;
}

// set map grid metatile depending on x, y
static void SetCutGrassMetatile(s16 x, s16 y)
{
    s32 metatileId = MapGridGetMetatileIdAt(x, y);

    switch (metatileId)
    {
    case METATILE_ID_POKE_LONG_GRASS_START:
    case METATILE_ID_POKE_LONG_GRASS:
    case METATILE_ID_POKE_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS);
        break;
    case METATILE_ID_POKE_GRASS_TREE_LEFT:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS_TREE_LEFT);
        break;
    case METATILE_ID_POKE_GRASS_TREE_RIGHT:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS_TREE_RIGHT);
        break;
    case METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS);
        break;
    case METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS);
        break;
    case METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS);
        break;
    case METATILE_ID_POKE_STEP_LAVA_GRASS:
    case METATILE_ID_POKE_LAVA_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_LAVA_FIELD);
        break;
    case METATILE_ID_POKE_STEP_ASH_GRASS:
    case METATILE_ID_POKE_ASH_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_ASH);
        break;
    case METATILE_ID_POKE_GRASS_TREE_UP:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS_TREE_UP);
        break;
    }
}

enum
{
    LONG_GRASS_NONE,
    LONG_GRASS_FIELD,
    LONG_GRASS_BASE_LEFT,
    LONG_GRASS_BASE_CENTER,
    LONG_GRASS_BASE_RIGHT
};

static u8 GetLongGrassCaseAt(s16 x, s16 y)
{
    u16 metatileId = MapGridGetMetatileIdAt(x, y);

    if (metatileId == METATILE_ID_GRASS)
        return LONG_GRASS_FIELD;
    else if (metatileId == METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS)
        return LONG_GRASS_BASE_LEFT;
    else if (metatileId == METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS)
        return LONG_GRASS_BASE_CENTER;
    else if (metatileId == METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS)
        return LONG_GRASS_BASE_RIGHT;
    else
        return LONG_GRASS_NONE;
}

static void SetCutGrassMetatiles(s16 x, s16 y)
{
    s16 i;
    s16 lowerY = y + sCutSquareSide;

    for (i = 0; i < sCutSquareSide; i++)
    {
        s16 currentX = x + i;
        if (MapGridGetMetatileIdAt(currentX, y) == METATILE_ID_POKE_LONG_GRASS)
        {
            switch (GetLongGrassCaseAt(currentX, y + 1))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_POKE_LONG_GRASS_START);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS);
                break;
            }
        }
        if (MapGridGetMetatileIdAt(currentX, lowerY) == METATILE_ID_GRASS)
        {
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_POKE_LONG_GRASS_START)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS);
        }
    }

    if (sCutSquareSide == CUT_HYPER_SIDE)
    {
        HandleLongGrassOnHyper(0, x, y);
        HandleLongGrassOnHyper(1, x, y);
    }
}

static void HandleLongGrassOnHyper(u8 caseId, s16 x, s16 y)
{
    s16 newX;
    bool8 arr[3];

    if (caseId == 0)
    {
        arr[0] = sHyperCutTiles[5];
        arr[1] = sHyperCutTiles[10];
        arr[2] = sHyperCutTiles[15];
        newX = x;
    }
    else if (caseId == 1)
    {
        arr[0] = sHyperCutTiles[9];
        arr[1] = sHyperCutTiles[14];
        arr[2] = sHyperCutTiles[19];
        newX = x + 4;
    }
    else // invalid case
    {
        return;
    }

    if (arr[0] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_POKE_LONG_GRASS_START)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS);
    }
    if (arr[1] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 2) == METATILE_ID_POKE_LONG_GRASS)
        {
            switch (GetLongGrassCaseAt(newX, y + 3))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_POKE_LONG_GRASS_START);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS);
                break;
            }
        }

        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_POKE_LONG_GRASS_START)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS);
    }
    if (arr[2] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_POKE_LONG_GRASS)
        {
            switch (GetLongGrassCaseAt(newX, y + 4))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_POKE_LONG_GRASS_START);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS);
                break;
            }
        }
    }
}

static void CutGrassSpriteCallback1(struct Sprite *sprite)
{
    sprite->data[0] = 8;
    sprite->data[1] = 0;
    sprite->data[3] = 0;
    sprite->callback = CutGrassSpriteCallback2;
}

static void CutGrassSpriteCallback2(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[2], sprite->data[0]);
    sprite->pos2.y = Cos(sprite->data[2], sprite->data[0]);

    sprite->data[2] = (sprite->data[2] + 8) & 0xFF;
    sprite->data[0] += 1 + (sprite->data[3] >> 2); // right shift by 2 is dividing by 4
    sprite->data[3]++;

    if (sprite->data[1] != 28)
        sprite->data[1]++;
    else
        sprite->callback = CutGrassSpriteCallbackEnd; // done rotating the grass, execute clean up function
}

static void CutGrassSpriteCallbackEnd(struct Sprite *sprite)
{
    u8 i;

    for (i = 1; i < CUT_SPRITE_ARRAY_COUNT; i++)
        DestroySprite(&gSprites[sCutGrassSpriteArrayPtr[i]]);

    FieldEffectStop(&gSprites[sCutGrassSpriteArrayPtr[0]], FLDEFF_CUT_GRASS);
    FREE_AND_SET_NULL(sCutGrassSpriteArrayPtr);
    ScriptUnfreezeEventObjects();
    ScriptContext2_Disable();

    if (IsMewPlayingHideAndSeek() == TRUE)
        ScriptContext1_SetupScript(FarawayIsland_Interior_EventScript_267EDB);
}

void FixLongGrassMetatilesWindowTop(s16 x, s16 y)
{
    u8 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsLongGrass_Duplicate(metatileBehavior))
    {
        switch (GetLongGrassCaseAt(x, y + 1))
        {
        case LONG_GRASS_FIELD:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_POKE_LONG_GRASS_START);
            break;
        case LONG_GRASS_BASE_LEFT:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS);
            break;
        case LONG_GRASS_BASE_CENTER:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS);
            break;
        case LONG_GRASS_BASE_RIGHT:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS);
            break;
        }
    }
}

void FixLongGrassMetatilesWindowBottom(s16 x, s16 y)
{
    if (MapGridGetMetatileIdAt(x, y) == METATILE_ID_GRASS)
    {
        u8 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y + 1);
        if (MetatileBehavior_IsLongGrassSouthEdge(metatileBehavior))
        {
            s32 metatileId = MapGridGetMetatileIdAt(x, y + 1);
            switch (metatileId)
            {
            case METATILE_ID_POKE_LONG_GRASS_START:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_GRASS);
                break;
            case METATILE_ID_SECRET_BASE_LEFT_POKE_LONG_GRASS:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_LEFT_LONG_GRASS);
                break;
            case METATILE_ID_SECRET_BASE_CENTER_POKE_LONG_GRASS:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_CENTER_LONG_GRASS);
                break;
            case METATILE_ID_SECRET_BASE_RIGHT_POKE_LONG_GRASS:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_ID_SECRET_BASE_RIGHT_LONG_GRASS);
                break;
            }
        }
    }
}

static void StartCutTreeFieldEffect(void)
{
    PlaySE(SE_W015);
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_TREE);
    EnableBothScriptContexts();
}

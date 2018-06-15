#include "global.h"
#include "field_camera.h"
#include "field_effect.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "event_obj_lock.h"
#include "metatile_behavior.h"
#include "party_menu.h"
#include "overworld.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "malloc.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/abilities.h"

// tileset 0 as first
#define METATILE_ID_GRASS 0x1
#define METATILE_ID_POKE_GRASS 0xD

#define METATILE_ID_POKE_GRASS_TREE_UP 0x25
#define METATILE_ID_GRASS_TREE_UP 0xE

#define METATILE_ID_POKE_GRASS_TREE_LEFT 0x1C6
#define METATILE_ID_POKE_GRASS_TREE_RIGHT 0x1C7

#define METATILE_ID_GRASS_TREE_LEFT 0x1CE
#define METATILE_ID_GRASS_TREE_RIGHT 0x1CF

#define METATILE_ID_POKE_TALL_GRASS 0x15

// tileset 6 as second
#define METATILE_ID_POKE_STEP_LAVA_GRASS 0x206
#define METATILE_ID_POKE_LAVA_GRASS 0x207
#define METATILE_ID_LAVA_FIELD 0x271

// tileset 7 as second
#define METATILE_ID_POKE_ASH_GRASS 0x20A
#define METATILE_ID_POKE_STEP_ASH_GRASS 0x212
#define METATILE_ID_ASH 0x218

// tileset 8 as second
#define METATILE_ID_POKE_TALL_GRASS_START 0x208

#define METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS 0x279
#define METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS 0x27A
#define METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS 0x27B

#define METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS 0x281
#define METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS 0x282
#define METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS 0x283

extern bool8 SetLastTalkedObjectInFrontOfPlayer(u8);
extern u8 oei_task_add(void);

extern struct MapPosition gPlayerFacingPosition;
extern u8 *gCutGrassSpriteArrayPtr;

extern const u8 Route103_EventScript_290705[];
extern const u8 gFieldEffectPic_CutGrass[];
extern const u16 gFieldEffectObjectPalette6[];

#define CUT_NORMAL_SIDE 3
#define CUT_NORMAL_AREA CUT_NORMAL_SIDE * CUT_NORMAL_SIDE
/* P - player
   X - cut area

    XXX
    XPX
    XXX
*/

#define CUT_HYPER_SIDE 5
#define CUT_HYPER_AREA CUT_HYPER_SIDE * CUT_HYPER_SIDE
/* P - player
   X - cut area

    XXXXX
    XXXXX
    XXPXX
    XXXXX
    XXXXX
*/

IWRAM_DATA u8 gUnknown_03001100;
IWRAM_DATA u8 gUnknown_03001101;
IWRAM_DATA u8 gUnknown_03001102;
IWRAM_DATA u32 fldeff_cut_unused_03001104;
IWRAM_DATA bool8 gUnknown_03001108[CUT_HYPER_AREA];

struct HyperCutterUnk
{
    s8 x;
    s8 y;
    u8 unk2[2];
};

const struct HyperCutterUnk gUnknown_0857C608[] =
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

const struct OamData gOamData_CutGrass =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 1,
    .priority = 1,
    .paletteNum = 1,
    .affineParam = 0,
};

const union AnimCmd gSpriteAnim_CutGrass[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gSpriteAnimTable_CutGrass[] =
{
    gSpriteAnim_CutGrass,
};

const struct SpriteFrameImage gSpriteImageTable_CutGrass[] =
{
    {gFieldEffectPic_CutGrass, 0x20},
};

const struct SpritePalette gFieldEffectObjectPaletteInfo6 = {gFieldEffectObjectPalette6, 0x1000};

void FieldCallback_CutTree(void);
void FieldCallback_CutGrass(void);
void StartCutTreeFieldEffect(void);
void StartCutGrassFieldEffect(void);
void SetCutGrassMetatile(s16, s16);
void SetCutGrassMetatiles(s16, s16);
void CutGrassSpriteCallback1(struct Sprite *);
void CutGrassSpriteCallback2(struct Sprite *);
void CutGrassSpriteCallbackEnd(struct Sprite *);
void HandleTallGrassOnHyper(u8, s16, s16);

const struct SpriteTemplate gSpriteTemplate_CutGrass =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1000,
    .oam = &gOamData_CutGrass,
    .anims = gSpriteAnimTable_CutGrass,
    .images = gSpriteImageTable_CutGrass,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CutGrassSpriteCallback1,
};

bool8 SetUpFieldMove_Cut(void)
{
    s16 x, y;
    u8 i, j;
    u8 tileBehavior;
    u8 userAbility;
    bool8 array[CUT_NORMAL_AREA];
    bool8 ret;

    if (SetLastTalkedObjectInFrontOfPlayer(EVENT_OBJ_GFX_CUTTABLE_TREE) == TRUE)
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
            gUnknown_03001100 = 5;
            gUnknown_03001101 = 2;
            gUnknown_03001102 = 2;
        }
        else
        {
            gUnknown_03001100 = 3;
            gUnknown_03001101 = 1;
            gUnknown_03001102 = 1;
        }

        for (i = 0; i < CUT_NORMAL_AREA; i++)
            array[i] = FALSE;
        for (i = 0; i < CUT_HYPER_AREA; i++)
            gUnknown_03001108[i] = FALSE;

        ret = FALSE;

        for (i = 0; i < 3; i++)
        {
            y = i - 1 + gPlayerFacingPosition.y;
            for (j = 0; j < 3; j++)
            {
                x = j - 1 + gPlayerFacingPosition.x;
                if (MapGridGetZCoordAt(x, y) == gPlayerFacingPosition.height)
                {
                    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                    if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                    || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                    {
                        // Standing in front of grass.
                        gUnknown_03001108[6 + (i * 5) + j] = TRUE;
                        ret = TRUE;
                    }
                    if (MapGridIsImpassableAt(x, y) == TRUE)
                    {
                        array[i * 3 + j] = FALSE;
                    }
                    else
                    {
                        array[i * 3 + j] = TRUE;
                        if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                            gUnknown_03001108[6 + (i * 5) + j] = TRUE;
                    }
                }
                else
                {
                    array[i * 3 + j] = FALSE;
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
            bool8 r7;
            for (i = 0; i < 16; i++)
            {
                x = gPlayerFacingPosition.x + gUnknown_0857C608[i].x;
                y = gPlayerFacingPosition.y + gUnknown_0857C608[i].y;
                r7 = TRUE;

                j = 0;
                while (1)
                {
                    if (gUnknown_0857C608[i].unk2[j] == 0)
                        break;
                    if (array[(u8)(gUnknown_0857C608[i].unk2[j] - 1)] == FALSE)
                    {
                        r7 = FALSE;
                        break;
                    }
                    if (++j >= 2)
                        break;
                }

                if (r7 == TRUE)
                {
                    if (MapGridGetZCoordAt(x, y) == gPlayerFacingPosition.height)
                    {
                        u8 r6 = ((gUnknown_0857C608[i].y * 5) + 12) + (gUnknown_0857C608[i].x);
                        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                        if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                        || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                        {
                            gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                            gPostMenuFieldCallback = FieldCallback_CutGrass;
                            gUnknown_03001108[r6] = r7;
                            ret = TRUE;
                        }
                        else
                        {
                            if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                                gUnknown_03001108[r6] = TRUE;
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

void FieldCallback_CutGrass(void)
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

void FieldCallback_CutTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(Route103_EventScript_290705);
}

bool8 FldEff_UseCutOnTree(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartCutTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartCutTreeFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

void StartCutGrassFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_GRASS);
    FieldEffectStart(FLDEFF_CUT_GRASS);
}

bool8 FldEff_CutGrass(void)
{
    s16 x, y;
    u8 tileBehavior;
    u8 i;

    for (i = 0, PlaySE(SE_W015), PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y); i < 25; i++)
    {
        if (gUnknown_03001108[i] == TRUE)
        {
            s8 xAdd = (i % 5) - 2;
            s8 yAdd = (i / 5) - 2;

            x = xAdd + gPlayerFacingPosition.x;
            y = yAdd + gPlayerFacingPosition.y;

            SetCutGrassMetatile(x, y);
            sub_808E75C(x, y);
        }
    }

    SetCutGrassMetatiles(gPlayerFacingPosition.x - gUnknown_03001101, gPlayerFacingPosition.y + (~gUnknown_03001102));
    DrawWholeMapView();
    gCutGrassSpriteArrayPtr = AllocZeroed(8);

    // populate sprite ID array
    for (i = 0; i < 8; i++)
    {
        gCutGrassSpriteArrayPtr[i] = CreateSprite(&gSpriteTemplate_CutGrass,
        gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y + 20, 0);
        gSprites[gCutGrassSpriteArrayPtr[i]].data[2] = 32 * i;
    }

    return FALSE;
}

// set map grid metatile depending on x, y
void SetCutGrassMetatile(s16 x, s16 y)
{
    s32 metatileId = MapGridGetMetatileIdAt(x, y);

    switch (metatileId)
    {
    case METATILE_ID_POKE_TALL_GRASS_START:
    case METATILE_ID_POKE_TALL_GRASS:
    case METATILE_ID_POKE_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS);
        break;
    case METATILE_ID_POKE_GRASS_TREE_LEFT:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS_TREE_LEFT);
        break;
    case METATILE_ID_POKE_GRASS_TREE_RIGHT:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_GRASS_TREE_RIGHT);
        break;
    case METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS);
        break;
    case METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS);
        break;
    case METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS:
        MapGridSetMetatileIdAt(x, y, METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS);
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
    TALL_GRASS_NONE,
    TALL_GRASS_FIELD,
    TALL_GRASS_BASE_LEFT,
    TALL_GRASS_BASE_CENTER,
    TALL_GRASS_BASE_RIGHT
};

u8 GetTallGrassCaseAt(s16 x, s16 y)
{
    u16 metatileId = MapGridGetMetatileIdAt(x, y);

    if (metatileId == METATILE_ID_GRASS)
        return TALL_GRASS_FIELD;
    else if (metatileId == METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS)
        return TALL_GRASS_BASE_LEFT;
    else if (metatileId == METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS)
        return TALL_GRASS_BASE_CENTER;
    else if (metatileId == METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS)
        return TALL_GRASS_BASE_RIGHT;
    else
        return TALL_GRASS_NONE;
}

void SetCutGrassMetatiles(s16 x, s16 y)
{
    s16 i;
    s16 lowerY = y + gUnknown_03001100;

    for (i = 0; i < gUnknown_03001100; i++)
    {
        s16 currentX = x + i;
        if (MapGridGetMetatileIdAt(currentX, y) == METATILE_ID_POKE_TALL_GRASS)
        {
            switch (GetTallGrassCaseAt(currentX, y + 1))
            {
            case TALL_GRASS_FIELD:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_POKE_TALL_GRASS_START);
                break;
            case TALL_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS);
                break;
            }
        }
        if (MapGridGetMetatileIdAt(currentX, lowerY) == METATILE_ID_GRASS)
        {
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_POKE_TALL_GRASS_START)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS);
        }
    }

    if (gUnknown_03001100 == CUT_HYPER_SIDE)
    {
        HandleTallGrassOnHyper(0, x, y);
        HandleTallGrassOnHyper(1, x, y);
    }
}

void HandleTallGrassOnHyper(u8 caseId, s16 x, s16 y)
{
    s16 newX;
    bool8 arr[3];

    if (caseId == 0)
    {
        arr[0] = gUnknown_03001108[5];
        arr[1] = gUnknown_03001108[10];
        arr[2] = gUnknown_03001108[15];
        newX = x;
    }
    else if (caseId == 1)
    {
        arr[0] = gUnknown_03001108[9];
        arr[1] = gUnknown_03001108[14];
        arr[2] = gUnknown_03001108[19];
        newX = x + 4;
    }
    else // invalid case
    {
        return;
    }

    if (arr[0] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_POKE_TALL_GRASS_START)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS);
    }
    if (arr[1] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 2) == METATILE_ID_POKE_TALL_GRASS)
        {
            switch (GetTallGrassCaseAt(newX, y + 3))
            {
            case TALL_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_POKE_TALL_GRASS_START);
                break;
            case TALL_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS);
                break;
            }
        }

        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_POKE_TALL_GRASS_START)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_LEFT_TALL_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_CENTER_TALL_GRASS);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_RIGHT_TALL_GRASS);
    }
    if (arr[2] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_ID_POKE_TALL_GRASS)
        {
            switch (GetTallGrassCaseAt(newX, y + 4))
            {
            case TALL_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_POKE_TALL_GRASS_START);
                break;
            case TALL_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_LEFT_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_CENTER_POKE_TALL_GRASS);
                break;
            case TALL_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_ID_SECRET_BASE_RIGHT_POKE_TALL_GRASS);
                break;
            }
        }
    }
}

void CutGrassSpriteCallback1(struct Sprite *sprite)
{
    sprite->data[0] = 8;
    sprite->data[1] = 0;
    sprite->data[3] = 0;
    sprite->callback = CutGrassSpriteCallback2;
}

void CutGrassSpriteCallback2(struct Sprite *sprite)
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

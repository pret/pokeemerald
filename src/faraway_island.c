#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"
#include "constants/vars.h"

static u8 sub_81D4890(u8);
static bool8 sub_81D4C14(struct EventObject*, u8);
static u8 sub_81D4C9C(struct EventObject*, u8);
static u8 sub_81D4C58(struct EventObject*, u8);
static u8 sub_81D4CE0(struct EventObject*, u8);
static u8 sub_81D4D24(u8);
static bool8 sub_81D4834(s16, s16);

extern u8 gUnknown_0203CF50;
extern s16 gUnknown_030012F8;
extern s16 gUnknown_030012FA;
extern u8 gUnknown_030012FC[4];

extern const struct SpritePalette gFieldEffectObjectPaletteInfo1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const s16 sFarawayIslandRockCoords[4][2] =
{
    {21, 16},
    {25, 16},
    {16, 17},
    {20, 20},
};

static u8 sub_81D4258(void)
{
    u8 eventObjectId;
    TryGetEventObjectIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectId);
    return eventObjectId;
}

u32 sub_81D427C(void)
{
    u8 i;
    int skip;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    gUnknown_030012F8 = gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x - mew->currentCoords.x;
    gUnknown_030012FA = gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y - mew->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(gUnknown_030012FC); i++)
        gUnknown_030012FC[i] = DIR_NONE;

    if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x == gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x
     && gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y == gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y)
    {
        return DIR_NONE;
    }

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 8 == 0)
        mew->invisible = 0;
    else
        mew->invisible = 1;

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 9 == 0)
        return DIR_NONE;

    for (i = 0; i < ARRAY_COUNT(sFarawayIslandRockCoords); i++)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x == sFarawayIslandRockCoords[i][0])
        {
            skip = 0;
            if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y < sFarawayIslandRockCoords[i][1])
            {
                if (mew->currentCoords.y <= sFarawayIslandRockCoords[i][1])
                    skip = 1;
            }
            else
            {
                if (mew->currentCoords.y >= sFarawayIslandRockCoords[i][1])
                    skip = 1;
            }

            if (!skip)
            {
                if (gUnknown_030012F8 > 0)
                {
                    if (mew->currentCoords.x + 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                    {
                        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
                else if (gUnknown_030012F8 < 0)
                {
                    if (mew->currentCoords.x - 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                    {
                        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                }

                if (mew->currentCoords.x == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x)
                {
                    if (gUnknown_030012FA > 0)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                    else
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
            }
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y == sFarawayIslandRockCoords[i][1])
        {
            skip = 0;
            if (gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.x < sFarawayIslandRockCoords[i][0])
            {
                if (mew->currentCoords.x <= sFarawayIslandRockCoords[i][0])
                    skip = 1;
            }
            else
            {
                if (mew->currentCoords.x >= sFarawayIslandRockCoords[i][0])
                    skip = 1;
            }

            if (!skip)
            {
                if (gUnknown_030012FA > 0)
                {
                    if (mew->currentCoords.y + 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
                else if (gUnknown_030012FA < 0)
                {
                    if (mew->currentCoords.y - 1 == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                    {
                        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                }

                if (mew->currentCoords.y == gEventObjects[gPlayerAvatar.eventObjectId].previousCoords.y)
                {
                    if (gUnknown_030012F8 > 0)
                    {
                        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                    else
                    {
                        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
            }
        }
    }

    if (sub_81D4C14(mew, 0))
    {
        if (sub_81D4C58(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_NORTH;
    }

    if (sub_81D4C9C(mew, 0))
    {
        if (sub_81D4C58(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_SOUTH;
    }

    if (sub_81D4C58(mew, 0))
    {
        if (sub_81D4C14(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_EAST;
    }

    if (sub_81D4CE0(mew, 0))
    {
        if (sub_81D4C14(mew, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(mew, 1))
            return sub_81D4D24(2);
        else
            return DIR_WEST;
    }

    if (gUnknown_030012FA == 0)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y > mew->currentCoords.y)
        {
            if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
                return DIR_NORTH;
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y < mew->currentCoords.y)
        {
            if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
                return DIR_SOUTH;
        }

        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
            return DIR_NORTH;

        if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
            return DIR_SOUTH;
    }

    if (gUnknown_030012F8 == 0)
    {
        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x > mew->currentCoords.x)
        {
            if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
                return DIR_WEST;
        }

        if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x < mew->currentCoords.x)
        {
            if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
                return DIR_EAST;
        }

        if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
            return DIR_EAST;

        if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
            return DIR_WEST;
    }

    return sub_81D4890(DIR_NONE);
}

static bool8 sub_81D4834(s16 x, s16 y)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x == x
     && gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y == y)
    {
        return FALSE;
    }

    return MetatileBehavior_IsPokeGrass(MapGridGetMetatileBehaviorAt(x, y));
}

static u8 sub_81D4890(u8 ignoredDir)
{
    u8 i;
    u8 count = 0;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    for (i = 0; i < ARRAY_COUNT(gUnknown_030012FC); i++)
        gUnknown_030012FC[i] = DIR_NONE;

    if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1) == TRUE && ignoredDir != DIR_NORTH)
    {
        gUnknown_030012FC[count] = DIR_NORTH;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_EAST)
    {
        gUnknown_030012FC[count] = DIR_EAST;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1) == TRUE && ignoredDir != DIR_SOUTH)
    {
        gUnknown_030012FC[count] = DIR_SOUTH;
        count++;
    }

    if (sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_WEST)
    {
        gUnknown_030012FC[count] = DIR_WEST;
        count++;
    }

    if (count > 1)
        return gUnknown_030012FC[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % count];
    else
        return gUnknown_030012FC[0];
}

void UpdateFarawayIslandStepCounter(void)
{
    u16 steps = VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        steps++;
        if (steps >= 9999)
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0);
        else
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, steps);
    }
}

bool8 EventObjectIsFarawayIslandMew(struct EventObject *eventObject)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (eventObject->graphicsId == EVENT_OBJ_GFX_MEW)
            return TRUE;
    }

    return FALSE;
}

bool8 IsMewPlayingHideAndSeek(void)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (FlagGet(FLAG_CAUGHT_MEW) != TRUE && FlagGet(FLAG_HIDE_MEW) != TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 sub_81D4A58(struct EventObject *eventObject)
{
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) != 0xFFFF
     && VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 4 == 0)
        return TRUE;

    return FALSE;
}

void sub_81D4A90(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct EventObject *mew = &gEventObjects[sub_81D4258()];

    mew->invisible = 0;
    if (gSpecialVar_0x8004 == 1)
    {
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[mew->spriteId].subpriority = 1;
    }
    else
    {
        VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0xFFFF);
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        if (gSpecialVar_Facing != DIR_NORTH)
            gSprites[mew->spriteId].subpriority = 1;

        LoadSpritePalette(&gFieldEffectObjectPaletteInfo1);
        UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(gFieldEffectObjectPaletteInfo1.tag));

        x = mew->currentCoords.x;
        y = mew->currentCoords.y;
        sub_80930E0(&x, &y, 8, 8);
        gUnknown_0203CF50 = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[15], x, y, gSprites[mew->spriteId].subpriority - 1);
        if (gUnknown_0203CF50 != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[gUnknown_0203CF50];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_81D4BEC(void)
{
    if (gUnknown_0203CF50 != MAX_SPRITES)
        DestroySprite(&gSprites[gUnknown_0203CF50]);
}

static bool8 sub_81D4C14(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012FA > 0 && sub_81D4834(mew->currentCoords.x, mew->currentCoords.y - 1))
    {
        gUnknown_030012FC[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C58(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012F8 < 0 && sub_81D4834(mew->currentCoords.x + 1, mew->currentCoords.y))
    {
        gUnknown_030012FC[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C9C(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012FA < 0 && sub_81D4834(mew->currentCoords.x, mew->currentCoords.y + 1))
    {
        gUnknown_030012FC[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4CE0(struct EventObject *mew, u8 index)
{
    if (gUnknown_030012F8 > 0 && sub_81D4834(mew->currentCoords.x - 1, mew->currentCoords.y))
    {
        gUnknown_030012FC[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4D24(u8 mod)
{
    return gUnknown_030012FC[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % mod];
}

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
static bool8 sub_81D4C14(struct ObjectEvent*, u8);
static u8 sub_81D4C9C(struct ObjectEvent*, u8);
static u8 sub_81D4C58(struct ObjectEvent*, u8);
static u8 sub_81D4CE0(struct ObjectEvent*, u8);
static u8 sub_81D4D24(u8);
static bool8 CanMewWalkToCoords(s16, s16);

static EWRAM_DATA u8 sUnknown_0203CF50 = 0;

static s16 sPlayerToMewDeltaX;
static s16 sPlayerToMewDeltaY;
static u8 sMewDirectionCandidates[4];

extern const struct SpritePalette gFieldEffectObjectPaletteInfo1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const s16 sFarawayIslandRockCoords[4][2] =
{
    {21, 16},
    {25, 16},
    {16, 17},
    {20, 20},
};

static u8 GetMewObjectEventId(void)
{
    u8 objectEventId;
    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    return objectEventId;
}

u32 GetMewMoveDirection(void)
{
    u8 i;
    int skip;
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

    sPlayerToMewDeltaX = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x - mew->currentCoords.x;
    sPlayerToMewDeltaY = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y - mew->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(sMewDirectionCandidates); i++)
        sMewDirectionCandidates[i] = DIR_NONE;

    if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x
     && gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y)
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
        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == sFarawayIslandRockCoords[i][0])
        {
            skip = 0;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y < sFarawayIslandRockCoords[i][1])
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
                if (sPlayerToMewDeltaX > 0)
                {
                    if (mew->currentCoords.x + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
                else if (sPlayerToMewDeltaX < 0)
                {
                    if (mew->currentCoords.x - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                }

                if (mew->currentCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                {
                    if (sPlayerToMewDeltaY > 0)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                    else
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
            }
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == sFarawayIslandRockCoords[i][1])
        {
            skip = 0;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x < sFarawayIslandRockCoords[i][0])
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
                if (sPlayerToMewDeltaY > 0)
                {
                    if (mew->currentCoords.y + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
                else if (sPlayerToMewDeltaY < 0)
                {
                    if (mew->currentCoords.y - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                }

                if (mew->currentCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                {
                    if (sPlayerToMewDeltaX > 0)
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                    else
                    {
                        if (CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
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

    if (sPlayerToMewDeltaY == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y > mew->currentCoords.y)
        {
            if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                return DIR_NORTH;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y < mew->currentCoords.y)
        {
            if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                return DIR_SOUTH;
        }

        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
            return DIR_NORTH;

        if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
            return DIR_SOUTH;
    }

    if (sPlayerToMewDeltaX == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x > mew->currentCoords.x)
        {
            if (CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                return DIR_WEST;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x < mew->currentCoords.x)
        {
            if (CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
                return DIR_EAST;
        }

        if (CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
            return DIR_EAST;

        if (CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
            return DIR_WEST;
    }

    return sub_81D4890(DIR_NONE);
}

static bool8 CanMewWalkToCoords(s16 x, s16 y)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x == x
     && gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y == y)
    {
        return FALSE;
    }

    return MetatileBehavior_IsPokeGrass(MapGridGetMetatileBehaviorAt(x, y));
}

static u8 sub_81D4890(u8 ignoredDir)
{
    u8 i;
    u8 count = 0;
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

    for (i = 0; i < ARRAY_COUNT(sMewDirectionCandidates); i++)
        sMewDirectionCandidates[i] = DIR_NONE;

    if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1) == TRUE && ignoredDir != DIR_NORTH)
    {
        sMewDirectionCandidates[count] = DIR_NORTH;
        count++;
    }

    if (CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_EAST)
    {
        sMewDirectionCandidates[count] = DIR_EAST;
        count++;
    }

    if (CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1) == TRUE && ignoredDir != DIR_SOUTH)
    {
        sMewDirectionCandidates[count] = DIR_SOUTH;
        count++;
    }

    if (CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_WEST)
    {
        sMewDirectionCandidates[count] = DIR_WEST;
        count++;
    }

    if (count > 1)
        return sMewDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % count];
    else
        return sMewDirectionCandidates[0];
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

bool8 ObjectEventIsFarawayIslandMew(struct ObjectEvent *objectEvent)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (objectEvent->graphicsId == OBJ_EVENT_GFX_MEW)
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

bool8 sub_81D4A58(struct ObjectEvent *objectEvent)
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
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

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
        sUnknown_0203CF50 = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[15], x, y, gSprites[mew->spriteId].subpriority - 1);
        if (sUnknown_0203CF50 != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sUnknown_0203CF50];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_81D4BEC(void)
{
    if (sUnknown_0203CF50 != MAX_SPRITES)
        DestroySprite(&gSprites[sUnknown_0203CF50]);
}

static bool8 sub_81D4C14(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaY > 0 && CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
    {
        sMewDirectionCandidates[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C58(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaX < 0 && CanMewWalkToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
    {
        sMewDirectionCandidates[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C9C(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaY < 0 && CanMewWalkToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
    {
        sMewDirectionCandidates[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4CE0(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaX > 0 && CanMewWalkToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
    {
        sMewDirectionCandidates[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4D24(u8 mod)
{
    return sMewDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % mod];
}

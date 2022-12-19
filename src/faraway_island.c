#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"

static u8 GetValidMewMoveDirection(u8);
static bool8 ShouldMewMoveNorth(struct ObjectEvent *, u8);
static bool8 ShouldMewMoveSouth(struct ObjectEvent *, u8);
static bool8 ShouldMewMoveEast(struct ObjectEvent *, u8);
static bool8 ShouldMewMoveWest(struct ObjectEvent *, u8);
static u8 GetRandomMewDirectionCandidate(u8);
static bool8 CanMewMoveToCoords(s16, s16);

static EWRAM_DATA u8 sGrassSpriteId = 0;

static s16 sPlayerToMewDeltaX;
static s16 sPlayerToMewDeltaY;
static u8 sMewDirectionCandidates[4];

extern const struct SpritePalette gSpritePalette_GeneralFieldEffect1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const s16 sFarawayIslandRockCoords[4][2] =
{
    {14 + MAP_OFFSET,  9 + MAP_OFFSET},
    {18 + MAP_OFFSET,  9 + MAP_OFFSET},
    { 9 + MAP_OFFSET, 10 + MAP_OFFSET},
    {13 + MAP_OFFSET, 13 + MAP_OFFSET},
};

static u8 GetMewObjectEventId(void)
{
    u8 objectEventId;
    TryGetObjectEventIdByLocalIdAndMap(LOCALID_FARAWAY_ISLAND_MEW, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    return objectEventId;
}

// When the player enters Faraway Island interior it begins a "hide and seek" minigame where Mew disappears into the grass
// This function returns the direction Mew will take a step, and is run every time the player takes a step
u32 GetMewMoveDirection(void)
{
    u8 i;
    int mewSafeFromTrap;
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

    sPlayerToMewDeltaX = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x - mew->currentCoords.x;
    sPlayerToMewDeltaY = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y - mew->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(sMewDirectionCandidates); i++)
        sMewDirectionCandidates[i] = DIR_NONE;

    // Player hasn't moved (just facing new direction), don't move
    if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x
     && gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y)
    {
        return DIR_NONE;
    }

    // Mew is invisible except for every 8th step
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 8 == 0)
        mew->invisible = FALSE;
    else
        mew->invisible = TRUE;

    // Mew will stay in place for 1 step after its visible
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 9 == 0)
        return DIR_NONE;

    // Below loop is for Mew to try to avoid getting trapped between the player and a rock
    for (i = 0; i < ARRAY_COUNT(sFarawayIslandRockCoords); i++)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == sFarawayIslandRockCoords[i][0])
        {
            mewSafeFromTrap = FALSE;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y < sFarawayIslandRockCoords[i][1])
            {
                if (mew->currentCoords.y <= sFarawayIslandRockCoords[i][1])
                    mewSafeFromTrap = TRUE;
            }
            else
            {
                if (mew->currentCoords.y >= sFarawayIslandRockCoords[i][1])
                    mewSafeFromTrap = TRUE;
            }

            if (!mewSafeFromTrap)
            {
                if (sPlayerToMewDeltaX > 0)
                {
                    if (mew->currentCoords.x + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
                else if (sPlayerToMewDeltaX < 0)
                {
                    if (mew->currentCoords.x - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                }

                if (mew->currentCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                {
                    if (sPlayerToMewDeltaY > 0)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                    else
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
            }
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == sFarawayIslandRockCoords[i][1])
        {
            mewSafeFromTrap = FALSE;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x < sFarawayIslandRockCoords[i][0])
            {
                if (mew->currentCoords.x <= sFarawayIslandRockCoords[i][0])
                    mewSafeFromTrap = TRUE;
            }
            else
            {
                if (mew->currentCoords.x >= sFarawayIslandRockCoords[i][0])
                    mewSafeFromTrap = TRUE;
            }

            if (!mewSafeFromTrap)
            {
                if (sPlayerToMewDeltaY > 0)
                {
                    if (mew->currentCoords.y + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
                else if (sPlayerToMewDeltaY < 0)
                {
                    if (mew->currentCoords.y - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                }

                if (mew->currentCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                {
                    if (sPlayerToMewDeltaX > 0)
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                            return DIR_WEST;
                    }
                    else
                    {
                        if (CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
                            return DIR_EAST;
                    }
                }
            }
        }
    }

    // Check if Mew can move in any direction without getting closer to the player
    // If so load into sMewDirectionCandidates
    // If Mew can move in two of the checked directions, choose one randomly
    if (ShouldMewMoveNorth(mew, 0))
    {
        if (ShouldMewMoveEast(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveWest(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else
            return DIR_NORTH;
    }

    if (ShouldMewMoveSouth(mew, 0))
    {
        if (ShouldMewMoveEast(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveWest(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else
            return DIR_SOUTH;
    }

    if (ShouldMewMoveEast(mew, 0))
    {
        if (ShouldMewMoveNorth(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveSouth(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else
            return DIR_EAST;
    }

    if (ShouldMewMoveWest(mew, 0))
    {
        if (ShouldMewMoveNorth(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveSouth(mew, 1))
            return GetRandomMewDirectionCandidate(2);
        else
            return DIR_WEST;
    }

    // If this point is reached, Mew cannot move without getting closer to the player

    // Avoid player on same Y, try move North/South
    if (sPlayerToMewDeltaY == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y > mew->currentCoords.y)
        {
            if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
                return DIR_NORTH;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y < mew->currentCoords.y)
        {
            if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
                return DIR_SOUTH;
        }

        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
            return DIR_NORTH;

        if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
            return DIR_SOUTH;
    }

    // Avoid player on same X, try move West/East
    if (sPlayerToMewDeltaX == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x > mew->currentCoords.x)
        {
            if (CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
                return DIR_WEST;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x < mew->currentCoords.x)
        {
            if (CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
                return DIR_EAST;
        }

        if (CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
            return DIR_EAST;

        if (CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
            return DIR_WEST;
    }

    // Can't avoid player on axis, move any valid direction
    return GetValidMewMoveDirection(DIR_NONE);
}

// Mew can move to any Tall/Long Grass metatile the player isn't currently on
static bool8 CanMewMoveToCoords(s16 x, s16 y)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x == x
     && gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y == y)
    {
        return FALSE;
    }

    return MetatileBehavior_IsPokeGrass(MapGridGetMetatileBehaviorAt(x, y));
}

// Last ditch effort to move, clear move candidates and try all directions again
static u8 GetValidMewMoveDirection(u8 ignoredDir)
{
    u8 i;
    u8 count = 0;
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

    for (i = 0; i < ARRAY_COUNT(sMewDirectionCandidates); i++)
        sMewDirectionCandidates[i] = DIR_NONE;

    if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1) == TRUE && ignoredDir != DIR_NORTH)
    {
        sMewDirectionCandidates[count] = DIR_NORTH;
        count++;
    }

    if (CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_EAST)
    {
        sMewDirectionCandidates[count] = DIR_EAST;
        count++;
    }

    if (CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1) == TRUE && ignoredDir != DIR_SOUTH)
    {
        sMewDirectionCandidates[count] = DIR_SOUTH;
        count++;
    }

    if (CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y) == TRUE && ignoredDir != DIR_WEST)
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

// Every 4th step Mew will shake the grass it steps into
// Otherwise its movement leaves grass undisturbed
bool8 ShouldMewShakeGrass(struct ObjectEvent *objectEvent)
{
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) != 0xFFFF
     && VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 4 == 0)
        return TRUE;

    return FALSE;
}

void SetMewAboveGrass(void)
{
    s16 x;
    s16 y;
    struct ObjectEvent *mew = &gObjectEvents[GetMewObjectEventId()];

    mew->invisible = FALSE;
    if (gSpecialVar_0x8004 == 1)
    {
        // For after battle where Mew should still be present (e.g. if ran from battle)
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[mew->spriteId].subpriority = 1;
    }
    else
    {
        // Mew emerging from grass when found
        // Also do field effect for grass shaking as it emerges
        VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0xFFFF);
        mew->fixedPriority = 1;
        gSprites[mew->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        if (gSpecialVar_Facing != DIR_NORTH)
            gSprites[mew->spriteId].subpriority = 1;

        LoadSpritePalette(&gSpritePalette_GeneralFieldEffect1);
        UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(gSpritePalette_GeneralFieldEffect1.tag));

        x = mew->currentCoords.x;
        y = mew->currentCoords.y;
        SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
        sGrassSpriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_LONG_GRASS], x, y, gSprites[mew->spriteId].subpriority - 1);
        if (sGrassSpriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sGrassSpriteId];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void DestroyMewEmergingGrassSprite(void)
{
    if (sGrassSpriteId != MAX_SPRITES)
        DestroySprite(&gSprites[sGrassSpriteId]);
}

static bool8 ShouldMewMoveNorth(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaY > 0 && CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y - 1))
    {
        sMewDirectionCandidates[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveEast(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaX < 0 && CanMewMoveToCoords(mew->currentCoords.x + 1, mew->currentCoords.y))
    {
        sMewDirectionCandidates[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveSouth(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaY < 0 && CanMewMoveToCoords(mew->currentCoords.x, mew->currentCoords.y + 1))
    {
        sMewDirectionCandidates[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveWest(struct ObjectEvent *mew, u8 index)
{
    if (sPlayerToMewDeltaX > 0 && CanMewMoveToCoords(mew->currentCoords.x - 1, mew->currentCoords.y))
    {
        sMewDirectionCandidates[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 GetRandomMewDirectionCandidate(u8 numDirections)
{
    return sMewDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % numDirections];
}

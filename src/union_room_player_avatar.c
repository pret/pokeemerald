#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "script.h"
#include "task.h"
#include "union_room.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

#define UR_SPRITE_START_ID (MAX_SPRITES - MAX_UNION_ROOM_PLAYERS)
#define UR_PLAYER_SPRITE_ID(playerIdx, facingDir)(5 * playerIdx + facingDir)

static EWRAM_DATA struct UnionRoomObject * sUnionObjWork = NULL;
static EWRAM_DATA u32 sUnionObjRefreshTimer = 0;

static u8 CreateTask_AnimateUnionRoomPlayers(void);
static u32 IsUnionRoomPlayerInvisible(u32, u32);
static void SetUnionRoomObjectFacingDirection(s32, s32, u8);

static const u8 sUnionRoomObjGfxIds[GENDER_COUNT][MAX_UNION_ROOM_PLAYERS + 2] = {
    [MALE] = {
        OBJ_EVENT_GFX_MAN_3, 
        OBJ_EVENT_GFX_BLACK_BELT, 
        OBJ_EVENT_GFX_CAMPER, 
        OBJ_EVENT_GFX_YOUNGSTER, 
        OBJ_EVENT_GFX_PSYCHIC_M, 
        OBJ_EVENT_GFX_BUG_CATCHER, 
        OBJ_EVENT_GFX_MAN_4, 
        OBJ_EVENT_GFX_MAN_5
    },
    [FEMALE] = {
        OBJ_EVENT_GFX_WOMAN_5, 
        OBJ_EVENT_GFX_HEX_MANIAC, 
        OBJ_EVENT_GFX_PICNICKER, 
        OBJ_EVENT_GFX_LASS, 
        OBJ_EVENT_GFX_LASS, 
        OBJ_EVENT_GFX_GIRL_3, 
        OBJ_EVENT_GFX_WOMAN_2, 
        OBJ_EVENT_GFX_BEAUTY
    }
};

static const s16 sUnionRoomPlayerCoords[MAX_UNION_ROOM_PLAYERS][2] = {
    { 4,  6},
    {13,  8},
    {10,  6},
    { 1,  8},
    {13,  4},
    { 7,  4},
    { 1,  4},
    { 7,  8}
};

static const s8 sFacingDirectionOffsets[][2] = {
    [DIR_NONE]  = { 0,  0},
    [DIR_SOUTH] = { 1,  0},
    [DIR_NORTH] = { 0, -1},
    [DIR_WEST]  = {-1,  0},
    [DIR_EAST]  = { 0,  1}
};

static const u8 sOppositeFacingDirection[] = {
    [DIR_NONE]  = DIR_NONE,
    [DIR_SOUTH] = DIR_NORTH,
    [DIR_NORTH] = DIR_SOUTH,
    [DIR_WEST]  = DIR_EAST,
    [DIR_EAST]  = DIR_WEST
};

static const u8 sNextFacingDirection[] = {
    [DIR_NONE]  = DIR_SOUTH,
    [DIR_SOUTH] = DIR_WEST,
    [DIR_NORTH] = DIR_SOUTH,
    [DIR_WEST]  = DIR_EAST,
    [DIR_EAST]  = DIR_NORTH
};

// Local id 1 is the Nurse/Attendant, 2-9 are link players
static const u8 sUnionRoomLocalIds[] = { 9, 8, 7, 2, 6, 5, 4, 3 };

static const u16 sUnknown[] = {
    0x2BF, 
    0x2C0, 
    0x2C1, 
    0x2C2, 
    0x2C3, 
    0x2C4, 
    0x2C5, 
    0x2C6
};

static const u8 sMovement_UnionPlayerExit[2] = {
    MOVEMENT_ACTION_FLY_UP,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovement_UnionPlayerEnter[2] = {
    MOVEMENT_ACTION_FLY_DOWN,
    MOVEMENT_ACTION_STEP_END
};

static bool32 IsPlayerStandingStill(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
        return TRUE;
    else
        return FALSE;
}

static u8 GetUnionRoomPlayerGraphicsId(u32 gender, u32 id)
{
    return sUnionRoomObjGfxIds[gender][id % MAX_UNION_ROOM_PLAYERS];
}

static void GetUnionRoomPlayerFacingCoords(u32 playerIdx, u32 direction, s32 * x, s32 * y)
{
    *x = sUnionRoomPlayerCoords[playerIdx][0] + sFacingDirectionOffsets[direction][0] + 7;
    *y = sUnionRoomPlayerCoords[playerIdx][1] + sFacingDirectionOffsets[direction][1] + 7;
}

static bool32 IsUnionRoomPlayerFacingTileAt(u32 playerIdx, u32 direction, s32 x, s32 y)
{
    if ((sUnionRoomPlayerCoords[playerIdx][0] + sFacingDirectionOffsets[direction][0] + 7 == x)
    &&  (sUnionRoomPlayerCoords[playerIdx][1] + sFacingDirectionOffsets[direction][1] + 7 == y))
        return TRUE;
    else
        return FALSE;
}

static bool32 IsUnionRoomPlayerHidden(u32 player_idx)
{
    return FlagGet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

static void HideUnionRoomPlayer(u32 player_idx)
{
    FlagSet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

static void ShowUnionRoomPlayer(u32 player_idx)
{
    FlagClear(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

static void SetUnionRoomPlayerGfx(u32 playerIdx, u32 gfxId)
{
    VarSet(VAR_OBJ_GFX_ID_0 + playerIdx, gfxId);
}

static void CreateUnionRoomPlayerObjectEvent(u32 playerIdx)
{
    TrySpawnObjectEvent(sUnionRoomLocalIds[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

static void RemoveUnionRoomPlayerObjectEvent(u32 playerIdx)
{
    RemoveObjectEventByLocalIdAndMap(sUnionRoomLocalIds[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

static bool32 SetUnionRoomPlayerEnterExitMovement(u32 playerIdx, const u8 * movement)
{
    u8 objectId;
    struct ObjectEvent * object;
    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
    {
        return FALSE;
    }
    object = &gObjectEvents[objectId];
    if (ObjectEventIsMovementOverridden(object))
    {
        return FALSE;
    }
    if (ObjectEventSetHeldMovement(object, *movement))
    {
        return FALSE;
    }
    return TRUE;
}

static bool32 TryReleaseUnionRoomPlayerObjectEvent(u32 playerIdx)
{
    u8 objectId;
    struct ObjectEvent * object;
    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
    {
        return TRUE;
    }
    object = &gObjectEvents[objectId];
    if (!ObjectEventClearHeldMovementIfFinished(object))
    {
        return FALSE;
    }
    if (!ScriptContext2_IsEnabled())
    {
        UnfreezeObjectEvent(object);
    }
    else
    {
        FreezeObjectEvent(object);
    }
    return TRUE;
}

u8 InitUnionRoomPlayerObjects(struct UnionRoomObject * players)
{
    s32 i;

    sUnionObjRefreshTimer = 0;
    sUnionObjWork = players;
    for (i = 0; i < MAX_UNION_ROOM_PLAYERS; i++)
    {
        players[i].state = 0;
        players[i].gfxId = 0;
        players[i].animState = 0;
        players[i].schedAnim = UNION_ROOM_SPAWN_NONE;
    }
    return CreateTask_AnimateUnionRoomPlayers();
}

static bool32 AnimateUnionRoomPlayerDespawn(s8 * state, u32 playerIdx, struct UnionRoomObject * ptr)
{
    switch (*state)
    {
    case 0:
        if (SetUnionRoomPlayerEnterExitMovement(playerIdx, sMovement_UnionPlayerExit) == TRUE)
        {
            HideUnionRoomPlayer(playerIdx);
            (*state)++;
        }
        break;
    case 1:
        if (TryReleaseUnionRoomPlayerObjectEvent(playerIdx))
        {
            RemoveUnionRoomPlayerObjectEvent(playerIdx);
            HideUnionRoomPlayer(playerIdx);
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 AnimateUnionRoomPlayerSpawn(s8 * state, u32 playerIdx, struct UnionRoomObject * ptr)
{
    s16 x, y;

    switch (*state)
    {
    case 0:
        if (!IsPlayerStandingStill())
        {
            break;
        }
        PlayerGetDestCoords(&x, &y);
        if (IsUnionRoomPlayerFacingTileAt(playerIdx, 0, x, y) == TRUE)
        {
            break;
        }
        player_get_pos_including_state_based_drift(&x, &y);
        if (IsUnionRoomPlayerFacingTileAt(playerIdx, 0, x, y) == TRUE)
        {
            break;
        }
        SetUnionRoomPlayerGfx(playerIdx, ptr->gfxId);
        CreateUnionRoomPlayerObjectEvent(playerIdx);
        ShowUnionRoomPlayer(playerIdx);
        (*state)++;
        // fallthrough
    case 3: // incorrect?
        if (SetUnionRoomPlayerEnterExitMovement(playerIdx, sMovement_UnionPlayerEnter) == TRUE)
        {
            (*state)++;
        }
        break;
    case 2:
        if (TryReleaseUnionRoomPlayerObjectEvent(playerIdx))
        {
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 SpawnGroupLeader(u32 playerIdx, u32 gender, u32 id)
{
    struct UnionRoomObject * ptr = &sUnionObjWork[playerIdx];
    ptr->schedAnim = UNION_ROOM_SPAWN_IN;
    ptr->gfxId = GetUnionRoomPlayerGraphicsId(gender, id);

    if (ptr->state == 0)
        return TRUE;
    else
        return FALSE;
}

static bool32 DespawnGroupLeader(u32 playerIdx)
{
    struct UnionRoomObject * ptr = &sUnionObjWork[playerIdx];
    ptr->schedAnim = UNION_ROOM_SPAWN_OUT;

    if (ptr->state == 1)
        return TRUE;
    else
        return FALSE;
}

static void AnimateUnionRoomPlayer(u32 playerIdx, struct UnionRoomObject * ptr)
{
    switch (ptr->state)
    {
    case 0:
        if (ptr->schedAnim == UNION_ROOM_SPAWN_IN)
        {
            ptr->state = 2;
            ptr->animState = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 2:
        if (!IsUnionRoomPlayerInvisible(playerIdx, 0) && ptr->schedAnim == UNION_ROOM_SPAWN_OUT)
        {
            ptr->state = 0;
            ptr->animState = 0;
            RemoveUnionRoomPlayerObjectEvent(playerIdx);
            HideUnionRoomPlayer(playerIdx);
        }
        else if (AnimateUnionRoomPlayerSpawn(&ptr->animState, playerIdx, ptr) == TRUE)
        {
            ptr->state = 1;
        }
        break;
    case 1:
        if (ptr->schedAnim == UNION_ROOM_SPAWN_OUT)
        {
            ptr->state = 3;
            ptr->animState = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 3:
        if (AnimateUnionRoomPlayerDespawn(&ptr->animState, playerIdx, ptr) == 1)
        {
            ptr->state = 0;
        }
        break;
    }
    ptr->schedAnim = UNION_ROOM_SPAWN_NONE;
}

static void Task_AnimateUnionRoomPlayers(u8 taskId)
{
    s32 i;
    for (i = 0; i < MAX_UNION_ROOM_PLAYERS; i++)
        AnimateUnionRoomPlayer(i, &sUnionObjWork[i]);
}

static u8 CreateTask_AnimateUnionRoomPlayers(void)
{
    if (FuncIsActiveTask(Task_AnimateUnionRoomPlayers) == TRUE)
        return NUM_TASKS;
    else
        return CreateTask(Task_AnimateUnionRoomPlayers, 5);
}

static void DestroyTask_AnimateUnionRoomPlayers(void)
{
    u8 taskId = FindTaskIdByFunc(Task_AnimateUnionRoomPlayers);
    if (taskId < NUM_TASKS)
    {
        DestroyTask(taskId);
    }
}

void DestroyUnionRoomPlayerObjects(void)
{
    s32 i;
    for (i = 0; i < MAX_UNION_ROOM_PLAYERS; i++)
    {
        if (!IsUnionRoomPlayerHidden(i))
        {
            RemoveUnionRoomPlayerObjectEvent(i);
            HideUnionRoomPlayer(i);
        }
    }
    sUnionObjWork = NULL;
    DestroyTask_AnimateUnionRoomPlayers();
}

void CreateGroupMemberSpritesInvisible(u8 * spriteIds, s32 playerIdx)
{
    s32 direction;

    for (direction = DIR_NONE; direction <= DIR_EAST; direction++)
    {
        s32 id = UR_PLAYER_SPRITE_ID(playerIdx, direction);
        spriteIds[id] = CreateObjectSprite(OBJ_EVENT_GFX_MAN_4, 
                                           id - UR_SPRITE_START_ID, 
                                           sUnionRoomPlayerCoords[playerIdx][0] + sFacingDirectionOffsets[direction][0], 
                                           sUnionRoomPlayerCoords[playerIdx][1] + sFacingDirectionOffsets[direction][1], 
                                           3, 1);
        SetObjectEventSpriteInvisibility(id - UR_SPRITE_START_ID, TRUE);
    }
}

void DestroyGroupMemberSprites(u8 * spriteIds)
{
    s32 i;
    for (i = 0; i < UR_PLAYER_SPRITE_ID(MAX_UNION_ROOM_PLAYERS, 0); i++)
        DestroySprite(&gSprites[spriteIds[i]]);
}

void SetTilesAroundUnionRoomPlayersPassable(void)
{
    s32 i, direction, x, y;
    for (i = 0; i < MAX_UNION_ROOM_PLAYERS; i++)
    {
        for (direction = DIR_NONE; direction <= DIR_EAST; direction++)
        {
            GetUnionRoomPlayerFacingCoords(i, direction, &x, &y);
            MapGridSetMetatileImpassabilityAt(x, y, FALSE);
        }
    }
}

static u8 GetNewFacingDirectionForUnionRoomPlayer(u32 direction, u32 playerIdx, struct GFtgtGname * gname)
{
    if (direction != DIR_NONE)
        return sNextFacingDirection[direction];
    else if (gname->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
        return DIR_SOUTH;
    else
        return DIR_EAST;
}

static bool32 IsUnionRoomPlayerInvisible(u32 playerIdx, u32 direction)
{
    return IsObjectEventSpriteInvisible(UR_PLAYER_SPRITE_ID(playerIdx, direction) - UR_SPRITE_START_ID);
}

static void SpawnGroupMember(u32 playerIdx, u32 direction, u8 graphicsId, struct GFtgtGname * gname)
{
    s32 x, y;
    s32 id = UR_PLAYER_SPRITE_ID(playerIdx, direction);
    if (IsUnionRoomPlayerInvisible(playerIdx, direction) == TRUE)
    {
        SetObjectEventSpriteInvisibility(id - UR_SPRITE_START_ID, FALSE);
        SetObjectEventSpriteAnim(id - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_IN);
    }
    SetObjectEventSpriteGraphics(id - UR_SPRITE_START_ID, graphicsId);
    SetUnionRoomObjectFacingDirection(direction, playerIdx, GetNewFacingDirectionForUnionRoomPlayer(direction, playerIdx, gname));
    GetUnionRoomPlayerFacingCoords(playerIdx, direction, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, TRUE);
}

static void DespawnGroupMember(u32 playerIdx, u32 direction)
{
    s32 x, y;
    SetObjectEventSpriteAnim(UR_PLAYER_SPRITE_ID(playerIdx, direction) - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_OUT);
    GetUnionRoomPlayerFacingCoords(playerIdx, direction, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, FALSE);
}

static void AssembleGroup(u32 playerIdx, struct GFtgtGname * gname)
{
    s16 x, y, x2, y2;
    s32 i;

    PlayerGetDestCoords(&x, &y);
    player_get_pos_including_state_based_drift(&x2, &y2);
    if (IsObjectEventSpriteInvisible(UR_PLAYER_SPRITE_ID(playerIdx, 0) - UR_SPRITE_START_ID) == TRUE)
    {
        if (IsUnionRoomPlayerFacingTileAt(playerIdx, 0, x, y) == TRUE || IsUnionRoomPlayerFacingTileAt(playerIdx, 0, x2, y2) == TRUE)
        {
            return;
        }
        SpawnGroupMember(playerIdx, 0, GetUnionRoomPlayerGraphicsId(gname->playerGender, gname->unk_00.playerTrainerId[0]), gname);
    }
    for (i = 1; i < 5; i++)
    {
        if (gname->child_sprite_gender[i - 1] == 0)
        {
            DespawnGroupMember(playerIdx, i);
        }
        else if (IsUnionRoomPlayerFacingTileAt(playerIdx, i, x, y) == FALSE && IsUnionRoomPlayerFacingTileAt(playerIdx, i, x2, y2) == FALSE)
        {
            SpawnGroupMember(playerIdx, i, GetUnionRoomPlayerGraphicsId((gname->child_sprite_gender[i - 1] >> 3) & 1, gname->child_sprite_gender[i - 1] & 7), gname);
        }
    }
}

static void SpawnGroupLeaderAndMembers(u32 playerIdx, struct GFtgtGname * gname)
{
    u32 i;
    switch (gname->activity)
    {
    case ACTIVITY_NONE | IN_UNION_ROOM:
    case ACTIVITY_PLYRTALK | IN_UNION_ROOM:
        SpawnGroupLeader(playerIdx, gname->playerGender, gname->unk_00.playerTrainerId[0]);
        for (i = 0; i < 5; i++)
        {
            DespawnGroupMember(playerIdx, i);
        }
        break;
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_TRADE | IN_UNION_ROOM:
    case ACTIVITY_CHAT | IN_UNION_ROOM:
    case ACTIVITY_CARD | IN_UNION_ROOM:
    case ACTIVITY_ACCEPT | IN_UNION_ROOM:
    case ACTIVITY_DECLINE | IN_UNION_ROOM:
    case ACTIVITY_NPCTALK | IN_UNION_ROOM:
        DespawnGroupLeader(playerIdx);
        AssembleGroup(playerIdx, gname);
        break;
    }
}

static void DespawnGroupLeaderAndMembers(u32 r5, struct GFtgtGname *gname)
{
    s32 i;
    DespawnGroupLeader(r5);
    for (i = 0; i < 5; i++)
    {
        DespawnGroupMember(r5, i);
    }
}

static void UpdateUnionRoomPlayerSprites(struct WirelessLink_URoom *uroom)
{
    s32 i;
    struct UnkStruct_x20 * r4;
    sUnionObjRefreshTimer = 0;
    for (i = 0, r4 = uroom->field_0->arr; i < MAX_UNION_ROOM_PLAYERS; i++)
    {
        if (r4[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
        {
            SpawnGroupLeaderAndMembers(i, &r4[i].gname_uname.gname);
        }
        else if (r4[i].groupScheduledAnim == UNION_ROOM_SPAWN_OUT)
        {
            DespawnGroupLeaderAndMembers(i, &r4[i].gname_uname.gname);
        }
    }
}

void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    sUnionObjRefreshTimer = 300;
}

void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    if (++sUnionObjRefreshTimer > 300)
    {
        UpdateUnionRoomPlayerSprites(uroom);
    }
}

bool32 TryInteractWithUnionRoomMember(struct UnkStruct_Main0 *main0, s16 *directionPtr, s16 *playerIdxPtr, u8 *spriteIds)
{
    s16 x, y;
    s32 i, direction;
    struct UnkStruct_x20 * r4;
    if (!IsPlayerStandingStill())
    {
        return FALSE;
    }
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    for (i = 0, r4 = main0->arr; i < MAX_UNION_ROOM_PLAYERS; i++)
    {
        for (direction = DIR_NONE; direction <= DIR_EAST; direction++)
        {
            s32 id = UR_PLAYER_SPRITE_ID(i, direction);
            if (x != sUnionRoomPlayerCoords[i][0] + sFacingDirectionOffsets[direction][0] + 7)
            {
                continue;
            }
            if (y != sUnionRoomPlayerCoords[i][1] + sFacingDirectionOffsets[direction][1] + 7)
            {
                continue;
            }
            if (IsObjectEventSpriteInvisible(id - UR_SPRITE_START_ID))
            {
                continue;
            }
            if (IsObjectEventSpriteAnimating(id - UR_SPRITE_START_ID))
            {
                continue;
            }
            if (r4[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
            {
                continue;
            }
            // Face player
            SetUnionRoomObjectFacingDirection(direction, i, sOppositeFacingDirection[GetPlayerFacingDirection()]);
            *directionPtr = direction;
            *playerIdxPtr = i;
            return TRUE;
        }
    }
    return FALSE;
}

static void SetUnionRoomObjectFacingDirection(s32 currDirection, s32 playerIdx, u8 newDirection)
{
    TurnObjectEventSprite(5 * playerIdx - UR_SPRITE_START_ID + currDirection, newDirection);
    // should be line below, but order is swapped here
    // TurnObjectEventSprite(UR_PLAYER_SPRITE_ID(playerIdx, currDirection) - UR_SPRITE_START_ID, newDirection);
}

void UpdateUnionRoomMemberFacing(u32 currDirection, u32 playerIdx, struct UnkStruct_Main0 *main0)
{
    return SetUnionRoomObjectFacingDirection(currDirection, playerIdx, GetNewFacingDirectionForUnionRoomPlayer(currDirection, playerIdx, &main0->arr[playerIdx].gname_uname.gname));
}

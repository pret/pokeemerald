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

#define UR_SPRITE_START_ID (MAX_SPRITES - MAX_UNION_ROOM_LEADERS)

// Each parent player can lead a group of up to MAX_RFU_PLAYERS (including themselves).
// Multiply the leader's id by MAX_RFU_PLAYERS and add the member's id (0 if the leader) to
// get the sprite index of that player.
#define UR_PLAYER_SPRITE_ID(leaderId, memberId)(MAX_RFU_PLAYERS * leaderId + memberId)

static EWRAM_DATA struct UnionRoomObject * sUnionObjWork = NULL;
static EWRAM_DATA u32 sUnionObjRefreshTimer = 0;

static u8 CreateTask_AnimateUnionRoomPlayers(void);
static u32 IsUnionRoomPlayerInvisible(u32, u32);
static void SetUnionRoomObjectFacingDirection(s32, s32, u8);

// + 2 is just to match, those elements are empty and never read
// Graphics ids should correspond with the classes in gUnionRoomFacilityClasses
static const u8 sUnionRoomObjGfxIds[GENDER_COUNT][NUM_UNION_ROOM_CLASSES + 2] = {
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

static const s16 sUnionRoomPlayerCoords[MAX_UNION_ROOM_LEADERS][2] = {
    { 4,  6},
    {13,  8},
    {10,  6},
    { 1,  8},
    {13,  4},
    { 7,  4},
    { 1,  4},
    { 7,  8}
};

// If there's a group of players interacting in the Union Room, the group
// leader will be at one of the positions above and each member in the group
// will be at one of the offsets from that position below. The leader will
// be at the first offset (0,0), as they're at the center.
static const s8 sUnionRoomGroupOffsets[MAX_RFU_PLAYERS][2] = {
    { 0,  0}, // Center
    { 1,  0}, // Left
    { 0, -1}, // Top
    {-1,  0}, // Right
    { 0,  1}  // Bottom
};

static const u8 sOppositeFacingDirection[] = {
    [DIR_NONE]  = DIR_NONE,
    [DIR_SOUTH] = DIR_NORTH,
    [DIR_NORTH] = DIR_SOUTH,
    [DIR_WEST]  = DIR_EAST,
    [DIR_EAST]  = DIR_WEST
};

// Compare to sUnionRoomGroupOffsets, the direction each group member
// needs to be facing in order to face the group leader in the center.
static const u8 sMemberFacingDirections[MAX_RFU_PLAYERS] = {
    DIR_SOUTH, // Leader, but never read
    DIR_WEST,
    DIR_SOUTH,
    DIR_EAST,
    DIR_NORTH
};

static const u8 sUnionRoomLocalIds[] = {
    LOCALID_UNION_ROOM_PLAYER_1,
    LOCALID_UNION_ROOM_PLAYER_2,
    LOCALID_UNION_ROOM_PLAYER_3,
    LOCALID_UNION_ROOM_PLAYER_4,
    LOCALID_UNION_ROOM_PLAYER_5,
    LOCALID_UNION_ROOM_PLAYER_6,
    LOCALID_UNION_ROOM_PLAYER_7,
    LOCALID_UNION_ROOM_PLAYER_8
};

// Unused
static const u16 sHidePlayerFlags[] = {
    FLAG_HIDE_UNION_ROOM_PLAYER_1,
    FLAG_HIDE_UNION_ROOM_PLAYER_2,
    FLAG_HIDE_UNION_ROOM_PLAYER_3,
    FLAG_HIDE_UNION_ROOM_PLAYER_4,
    FLAG_HIDE_UNION_ROOM_PLAYER_5,
    FLAG_HIDE_UNION_ROOM_PLAYER_6,
    FLAG_HIDE_UNION_ROOM_PLAYER_7,
    FLAG_HIDE_UNION_ROOM_PLAYER_8
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

// Gender and trainer id are used to determine which sprite a player appears as
static u8 GetUnionRoomPlayerGraphicsId(u32 gender, u32 id)
{
    return sUnionRoomObjGfxIds[gender][id % NUM_UNION_ROOM_CLASSES];
}

static void GetUnionRoomPlayerCoords(u32 leaderId, u32 memberId, s32 * x, s32 * y)
{
    *x = sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0] + MAP_OFFSET;
    *y = sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1] + MAP_OFFSET;
}

static bool32 IsUnionRoomPlayerAt(u32 leaderId, u32 memberId, s32 x, s32 y)
{
    if ((sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0] + MAP_OFFSET == x)
    &&  (sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1] + MAP_OFFSET == y))
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

static void SetUnionRoomPlayerGfx(u32 leaderId, u32 gfxId)
{
    VarSet(VAR_OBJ_GFX_ID_0 + leaderId, gfxId);
}

static void CreateUnionRoomPlayerObjectEvent(u32 leaderId)
{
    TrySpawnObjectEvent(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

static void RemoveUnionRoomPlayerObjectEvent(u32 leaderId)
{
    RemoveObjectEventByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

static bool32 SetUnionRoomPlayerEnterExitMovement(u32 leaderId, const u8 *movement)
{
    u8 objectId;
    struct ObjectEvent * object;
    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
        return FALSE;
    object = &gObjectEvents[objectId];
    if (ObjectEventIsMovementOverridden(object))
        return FALSE;
    if (ObjectEventSetHeldMovement(object, *movement))
        return FALSE;
    return TRUE;
}

static bool32 TryReleaseUnionRoomPlayerObjectEvent(u32 leaderId)
{
    u8 objectId;
    struct ObjectEvent * object;
    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
        return TRUE;

    object = &gObjectEvents[objectId];
    if (!ObjectEventClearHeldMovementIfFinished(object))
        return FALSE;

    if (!ArePlayerFieldControlsLocked())
        UnfreezeObjectEvent(object);
    else
        FreezeObjectEvent(object);
    return TRUE;
}

u8 InitUnionRoomPlayerObjects(struct UnionRoomObject * players)
{
    s32 i;

    sUnionObjRefreshTimer = 0;
    sUnionObjWork = players;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        players[i].state = 0;
        players[i].gfxId = 0;
        players[i].animState = 0;
        players[i].schedAnim = UNION_ROOM_SPAWN_NONE;
    }
    return CreateTask_AnimateUnionRoomPlayers();
}

static bool32 AnimateUnionRoomPlayerDespawn(s8 * state, u32 leaderId, struct UnionRoomObject * object)
{
    switch (*state)
    {
    case 0:
        if (SetUnionRoomPlayerEnterExitMovement(leaderId, sMovement_UnionPlayerExit) == TRUE)
        {
            HideUnionRoomPlayer(leaderId);
            (*state)++;
        }
        break;
    case 1:
        if (TryReleaseUnionRoomPlayerObjectEvent(leaderId))
        {
            RemoveUnionRoomPlayerObjectEvent(leaderId);
            HideUnionRoomPlayer(leaderId);
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 AnimateUnionRoomPlayerSpawn(s8 * state, u32 leaderId, struct UnionRoomObject * object)
{
    s16 x, y;

    switch (*state)
    {
    case 0:
        if (!IsPlayerStandingStill())
            break;
        PlayerGetDestCoords(&x, &y);
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE)
            break;
        player_get_pos_including_state_based_drift(&x, &y);
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE)
            break;
        SetUnionRoomPlayerGfx(leaderId, object->gfxId);
        CreateUnionRoomPlayerObjectEvent(leaderId);
        ShowUnionRoomPlayer(leaderId);
        (*state)++;
        // fallthrough
    case 3: // incorrect?
        if (SetUnionRoomPlayerEnterExitMovement(leaderId, sMovement_UnionPlayerEnter) == TRUE)
            (*state)++;
        break;
    case 2:
        if (TryReleaseUnionRoomPlayerObjectEvent(leaderId))
        {
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 SpawnGroupLeader(u32 leaderId, u32 gender, u32 id)
{
    struct UnionRoomObject * object = &sUnionObjWork[leaderId];
    object->schedAnim = UNION_ROOM_SPAWN_IN;
    object->gfxId = GetUnionRoomPlayerGraphicsId(gender, id);

    if (object->state == 0)
        return TRUE;
    else
        return FALSE;
}

static bool32 DespawnGroupLeader(u32 leaderId)
{
    struct UnionRoomObject * object = &sUnionObjWork[leaderId];
    object->schedAnim = UNION_ROOM_SPAWN_OUT;

    if (object->state == 1)
        return TRUE;
    else
        return FALSE;
}

static void AnimateUnionRoomPlayer(u32 leaderId, struct UnionRoomObject * object)
{
    switch (object->state)
    {
    case 0:
        if (object->schedAnim == UNION_ROOM_SPAWN_IN)
        {
            object->state = 2;
            object->animState = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 2:
        if (!IsUnionRoomPlayerInvisible(leaderId, 0) && object->schedAnim == UNION_ROOM_SPAWN_OUT)
        {
            object->state = 0;
            object->animState = 0;
            RemoveUnionRoomPlayerObjectEvent(leaderId);
            HideUnionRoomPlayer(leaderId);
        }
        else if (AnimateUnionRoomPlayerSpawn(&object->animState, leaderId, object) == TRUE)
        {
            object->state = 1;
        }
        break;
    case 1:
        if (object->schedAnim != UNION_ROOM_SPAWN_OUT)
            break;
        object->state = 3;
        object->animState = 0;
        // fallthrough
    case 3:
        if (AnimateUnionRoomPlayerDespawn(&object->animState, leaderId, object) == 1)
            object->state = 0;
        break;
    }
    object->schedAnim = UNION_ROOM_SPAWN_NONE;
}

static void Task_AnimateUnionRoomPlayers(u8 taskId)
{
    s32 i;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
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
        DestroyTask(taskId);
}

void DestroyUnionRoomPlayerObjects(void)
{
    s32 i;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
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

void CreateUnionRoomPlayerSprites(u8 *spriteIds, s32 leaderId)
{
    s32 memberId;
    for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
    {
        s32 id = UR_PLAYER_SPRITE_ID(leaderId, memberId);
        spriteIds[id] = CreateVirtualObject(OBJ_EVENT_GFX_MAN_4,
                                           id - UR_SPRITE_START_ID,
                                           sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0],
                                           sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1],
                                           3, 1);
        SetVirtualObjectInvisibility(id - UR_SPRITE_START_ID, TRUE);
    }
}

void DestroyUnionRoomPlayerSprites(u8 *spriteIds)
{
    s32 i;
    for (i = 0; i < NUM_UNION_ROOM_SPRITES; i++)
        DestroySprite(&gSprites[spriteIds[i]]);
}

// Clear the impassable metatiles around the group leaders that get set
// to prevent the player from walking through the group member sprites.
void SetTilesAroundUnionRoomPlayersPassable(void)
{
    s32 i, memberId, x, y;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
        {
            GetUnionRoomPlayerCoords(i, memberId, &x, &y);
            MapGridSetMetatileImpassabilityAt(x, y, FALSE);
        }
    }
}

static u8 GetNewFacingDirectionForUnionRoomPlayer(u32 memberId, u32 leaderId, struct RfuGameData * gameData)
{
    if (memberId) // If not leader
        return sMemberFacingDirections[memberId];
    else if (gameData->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
        return DIR_SOUTH;
    else
        return DIR_EAST;
}

static bool32 IsUnionRoomPlayerInvisible(u32 leaderId, u32 memberId)
{
    return IsVirtualObjectInvisible(UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID);
}

static void SpawnGroupMember(u32 leaderId, u32 memberId, u8 graphicsId, struct RfuGameData * gameData)
{
    s32 x, y;
    s32 id = UR_PLAYER_SPRITE_ID(leaderId, memberId);
    if (IsUnionRoomPlayerInvisible(leaderId, memberId) == TRUE)
    {
        SetVirtualObjectInvisibility(id - UR_SPRITE_START_ID, FALSE);
        SetVirtualObjectSpriteAnim(id - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_IN);
    }
    SetVirtualObjectGraphics(id - UR_SPRITE_START_ID, graphicsId);
    SetUnionRoomObjectFacingDirection(memberId, leaderId, GetNewFacingDirectionForUnionRoomPlayer(memberId, leaderId, gameData));
    GetUnionRoomPlayerCoords(leaderId, memberId, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, TRUE);
}

static void DespawnGroupMember(u32 leaderId, u32 memberId)
{
    s32 x, y;
    SetVirtualObjectSpriteAnim(UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_OUT);
    GetUnionRoomPlayerCoords(leaderId, memberId, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, FALSE);
}

static void AssembleGroup(u32 leaderId, struct RfuGameData * gameData)
{
    s16 x, y, x2, y2;
    s32 i;

    PlayerGetDestCoords(&x, &y);
    player_get_pos_including_state_based_drift(&x2, &y2);
    if (IsVirtualObjectInvisible(UR_PLAYER_SPRITE_ID(leaderId, 0) - UR_SPRITE_START_ID) == TRUE)
    {
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE || IsUnionRoomPlayerAt(leaderId, 0, x2, y2) == TRUE)
            return;
        SpawnGroupMember(leaderId, 0, GetUnionRoomPlayerGraphicsId(gameData->playerGender, gameData->compatibility.playerTrainerId[0]), gameData);
    }
    for (i = 1; i < MAX_RFU_PLAYERS; i++)
    {
        if (gameData->partnerInfo[i - 1] == 0)
        {
            DespawnGroupMember(leaderId, i);
        }
        else if (IsUnionRoomPlayerAt(leaderId, i, x, y) == FALSE && IsUnionRoomPlayerAt(leaderId, i, x2, y2) == FALSE)
        {
            SpawnGroupMember(leaderId, i, GetUnionRoomPlayerGraphicsId((gameData->partnerInfo[i - 1] >> PINFO_GENDER_SHIFT) & 1,
                                                                        gameData->partnerInfo[i - 1] & PINFO_TID_MASK),
                                                                        gameData);
        }
    }
}

static void SpawnGroupLeaderAndMembers(u32 leaderId, struct RfuGameData * gameData)
{
    u32 i;
    switch (gameData->activity)
    {
    case ACTIVITY_NONE | IN_UNION_ROOM:
    case ACTIVITY_PLYRTALK | IN_UNION_ROOM:
        SpawnGroupLeader(leaderId, gameData->playerGender, gameData->compatibility.playerTrainerId[0]);
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            DespawnGroupMember(leaderId, i);
        break;
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_TRADE | IN_UNION_ROOM:
    case ACTIVITY_CHAT | IN_UNION_ROOM:
    case ACTIVITY_CARD | IN_UNION_ROOM:
    case ACTIVITY_ACCEPT | IN_UNION_ROOM:
    case ACTIVITY_DECLINE | IN_UNION_ROOM:
    case ACTIVITY_NPCTALK | IN_UNION_ROOM:
        DespawnGroupLeader(leaderId);
        AssembleGroup(leaderId, gameData);
        break;
    }
}

static void DespawnGroupLeaderAndMembers(u32 leaderId, struct RfuGameData *gameData)
{
    s32 i;
    DespawnGroupLeader(leaderId);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        DespawnGroupMember(leaderId, i);
}

static void UpdateUnionRoomPlayerSprites(struct WirelessLink_URoom *uroom)
{
    s32 i;
    struct RfuPlayer * leaders;
    sUnionObjRefreshTimer = 0;
    for (i = 0, leaders = uroom->playerList->players; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        if (leaders[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
            SpawnGroupLeaderAndMembers(i, &leaders[i].rfu.data);
        else if (leaders[i].groupScheduledAnim == UNION_ROOM_SPAWN_OUT)
            DespawnGroupLeaderAndMembers(i, &leaders[i].rfu.data);
    }
}

void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    sUnionObjRefreshTimer = 300;
}

void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    if (++sUnionObjRefreshTimer > 300)
        UpdateUnionRoomPlayerSprites(uroom);
}

bool32 TryInteractWithUnionRoomMember(struct RfuPlayerList *list, s16 *memberIdPtr, s16 *leaderIdPtr, u8 *spriteIds)
{
    s16 x, y;
    s32 i, memberId;
    struct RfuPlayer * leaders;
    if (!IsPlayerStandingStill())
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    for (i = 0, leaders = list->players; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
        {
            s32 id = UR_PLAYER_SPRITE_ID(i, memberId);

            // Is the player in front of a group member position?
            if (x != sUnionRoomPlayerCoords[i][0] + sUnionRoomGroupOffsets[memberId][0] + 7)
                continue;
            if (y != sUnionRoomPlayerCoords[i][1] + sUnionRoomGroupOffsets[memberId][1] + 7)
                continue;

            // Has a group member spawned at this position?
            if (IsVirtualObjectInvisible(id - UR_SPRITE_START_ID))
                continue;
            if (IsVirtualObjectAnimating(id - UR_SPRITE_START_ID))
                continue;
            if (leaders[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
                continue;

            // Interaction attempt successful, face player
            SetUnionRoomObjectFacingDirection(memberId, i, sOppositeFacingDirection[GetPlayerFacingDirection()]);
            *memberIdPtr = memberId;
            *leaderIdPtr = i;
            return TRUE;
        }
    }
    return FALSE;
}

static void SetUnionRoomObjectFacingDirection(s32 memberId, s32 leaderId, u8 newDirection)
{
    TurnVirtualObject(MAX_RFU_PLAYERS * leaderId - UR_SPRITE_START_ID + memberId, newDirection);
    // should be line below, but order is swapped here
    // TurnVirtualObject(UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID, newDirection);
}

void UpdateUnionRoomMemberFacing(u32 memberId, u32 leaderId, struct RfuPlayerList *list)
{
    return SetUnionRoomObjectFacingDirection(memberId, leaderId, GetNewFacingDirectionForUnionRoomPlayer(memberId, leaderId, &list->players[leaderId].rfu.data));
}

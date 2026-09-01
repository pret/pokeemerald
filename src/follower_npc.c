#include "global.h"
#include "follower_npc.h"
#include "follower_npc_alternate_sprites.h"
#include "battle.h"
#include "battle_partner.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_door.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "item.h"
#include "load_save.h"
#include "map_name_popup.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "script_movement.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "task.h"
#include "trig.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/frontier_util.h"
#include "constants/map_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"

/*
 * Known Issues:
 *     -follower gets messed up if you go into a map with a maximum number of event objects
 *         -inherits incorrect palette, may get directionally confused
 */

// Task data
#define tState          data[0]
#define tDoorX          data[2]
#define tDoorY          data[3]

static void SetFollowerNPCScriptPointer(const u8 *script);
static void PlayerLogCoordinates(struct ObjectEvent *player);
static void TurnNPCIntoFollower(u32 localId, u32 followerFlags, u32 setScript, const u8 *script);
static u32 GetFollowerNPCSprite(void);
static bool32 FollowerNPCHasRunningFrames(void);
static bool32 IsStateMovement(u32 state);
static enum Direction GetNewPlayerMovementDirection(u32 state);
static bool32 IsPlayerForcedOntoSameTile(u8 metatileBehavior, enum Direction direction);
static u32 GetPlayerFaceToDoorDirection(struct ObjectEvent *player, struct ObjectEvent *follower);
static u32 ReturnFollowerNPCDelayedState(enum Direction direction);
static void TryUpdateFollowerNPCSpriteUnderwater(void);
static void SetSurfJump(void);
static void SetUpSurfBlobFieldEffect(struct ObjectEvent *npc);
static void SetSurfDismount(void);
static void Task_BindSurfBlobToFollowerNPC(u8 taskId);
static void Task_FinishSurfDismount(u8 taskId);
static void Task_ReallowPlayerMovement(u8 taskId);
static void Task_FollowerNPCHandleEscalator(u8 taskId);
static void Task_FollowerNPCHandleEscalatorFinish(u8 taskId);
static void CalculateFollowerNPCEscalatorTrajectoryUp(struct Task *task);
static void CalculateFollowerNPCEscalatorTrajectoryDown(struct Task *task);

void SetFollowerNPCData(enum FollowerNPCDataTypes type, u32 value)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    switch (type)
    {
    case FNPC_DATA_IN_PROGRESS:
        gSaveBlock3Ptr->NPCfollower.inProgress = value;
        break;
    case FNPC_DATA_WARP_END:
        gSaveBlock3Ptr->NPCfollower.warpEnd = value;
        break;
    case FNPC_DATA_SURF_BLOB:
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = value;
        break;
    case FNPC_DATA_COME_OUT_DOOR:
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = value;
        break;
    case FNPC_DATA_FORCED_MOVEMENT:
        gSaveBlock3Ptr->NPCfollower.forcedMovement = value;
        break;
    case FNPC_DATA_OBJ_ID:
        gSaveBlock3Ptr->NPCfollower.objId = value;
        break;
    case FNPC_DATA_CURRENT_SPRITE:
        gSaveBlock3Ptr->NPCfollower.currentSprite = value;
        break;
    case FNPC_DATA_DELAYED_STATE:
        gSaveBlock3Ptr->NPCfollower.delayedState = value;
        break;
    case FNPC_DATA_EVENT_FLAG:
        gSaveBlock3Ptr->NPCfollower.flag = value;
        break;
    case FNPC_DATA_GFX_ID:
        gSaveBlock3Ptr->NPCfollower.graphicsId = value;
        break;
    case FNPC_DATA_FOLLOWER_FLAGS:
        gSaveBlock3Ptr->NPCfollower.flags = value;
        break;
    case FNPC_DATA_BATTLE_PARTNER:
        gSaveBlock3Ptr->NPCfollower.battlePartner = value;
        break;
    }
#endif
}

static void SetFollowerNPCScriptPointer(const u8 *script)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    gSaveBlock3Ptr->NPCfollower.script = script;
#endif
}

static void PlayerLogCoordinates(struct ObjectEvent *player)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    gSaveBlock3Ptr->NPCfollower.log.x = player->currentCoords.x;
    gSaveBlock3Ptr->NPCfollower.log.y = player->currentCoords.y;
#endif
}

const u8 *GetFollowerNPCScriptPointer(void)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    if (PlayerHasFollowerNPC())
        return gSaveBlock3Ptr->NPCfollower.script;

#endif
    return NULL;
}

u32 GetFollowerNPCData(enum FollowerNPCDataTypes type)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    switch (type)
    {
    case FNPC_DATA_IN_PROGRESS:
        return gSaveBlock3Ptr->NPCfollower.inProgress;
    case FNPC_DATA_WARP_END:
        return gSaveBlock3Ptr->NPCfollower.warpEnd;
    case FNPC_DATA_SURF_BLOB:
        return gSaveBlock3Ptr->NPCfollower.createSurfBlob;
    case FNPC_DATA_COME_OUT_DOOR:
        return gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs;
    case FNPC_DATA_FORCED_MOVEMENT:
        return gSaveBlock3Ptr->NPCfollower.forcedMovement;
    case FNPC_DATA_OBJ_ID:
        return gSaveBlock3Ptr->NPCfollower.objId;
    case FNPC_DATA_CURRENT_SPRITE:
        return gSaveBlock3Ptr->NPCfollower.currentSprite;
    case FNPC_DATA_DELAYED_STATE:
        return gSaveBlock3Ptr->NPCfollower.delayedState;
    case FNPC_DATA_EVENT_FLAG:
        return gSaveBlock3Ptr->NPCfollower.flag;
    case FNPC_DATA_GFX_ID:
        return gSaveBlock3Ptr->NPCfollower.graphicsId;
    case FNPC_DATA_FOLLOWER_FLAGS:
        return gSaveBlock3Ptr->NPCfollower.flags;
    case FNPC_DATA_BATTLE_PARTNER:
        return gSaveBlock3Ptr->NPCfollower.battlePartner;
    }
#endif
    return 0;
}

void ClearFollowerNPCData(void)
{
#if FNPC_ENABLE_NPC_FOLLOWERS
    memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
#endif
}

static void TurnNPCIntoFollower(u32 localId, u32 followerFlags, u32 setScript, const u8 *scriptPtr)
{
    struct ObjectEventTemplate npc;
    struct ObjectEvent *follower;
    u32 eventObjId = GetObjectEventIdByLocalId(localId);
    u32 npcX = gObjectEvents[eventObjId].currentCoords.x;
    u32 npcY = gObjectEvents[eventObjId].currentCoords.y;
    const u8 *script;
    u32 flag;
    u16 facingDirection = gObjectEvents[eventObjId].facingDirection;

    flag = GetObjectEventFlagIdByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    // If the object does not have an event flag, don't create follower.
    if (flag == 0)
        return;

    if (setScript == TRUE)
        // Set the custom script.
        script = scriptPtr;
    else
        // Use the object's original script.
        script = GetObjectEventScriptPointerByObjectEventId(eventObjId);

    RemoveObjectEvent(&gObjectEvents[eventObjId]);
    FlagSet(flag);

    npc = *GetObjectEventTemplateByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    npc.movementType = 0;
    npc.script = script;
    npc.localId = OBJ_EVENT_ID_NPC_FOLLOWER;
    SetFollowerNPCData(FNPC_DATA_OBJ_ID, TrySpawnObjectEventTemplate(&npc, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, npcX, npcY));
    follower = &gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)];
    MoveObjectEventToMapCoords(follower, npcX, npcY);
    ObjectEventTurn(follower, facingDirection);
    follower->movementType = MOVEMENT_TYPE_NONE;
    gSprites[follower->spriteId].callback = MovementType_None;

    SetFollowerNPCData(FNPC_DATA_IN_PROGRESS, TRUE);
    SetFollowerNPCData(FNPC_DATA_GFX_ID, follower->graphicsId);
    SetFollowerNPCScriptPointer(script);
    SetFollowerNPCData(FNPC_DATA_EVENT_FLAG, flag);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
    SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);
    if (FollowerNPCHasRunningFrames())
        followerFlags |= FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES;

    SetFollowerNPCData(FNPC_DATA_FOLLOWER_FLAGS, followerFlags);

    // If the player is biking and the follower flags prohibit biking, force the player to dismount the bike.
    if (!CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_BIKE)
    &&  TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE))
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);

    // Set the follower sprite to match the player state.
    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ON_FOOT))
        FollowerNPC_HandleSprite();
}

static u32 GetFollowerNPCSprite(void)
{
    u32 i;

    switch (GetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE))
    {
    case FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
            if (gFollowerNPCAlternateSprites[i].normalId == GetFollowerNPCData(FNPC_DATA_GFX_ID))
                return gFollowerNPCAlternateSprites[i].machBikeId;
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
            if (gFollowerNPCAlternateSprites[i].normalId == GetFollowerNPCData(FNPC_DATA_GFX_ID))
                return gFollowerNPCAlternateSprites[i].acroBikeId;
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_SURF:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
            if (gFollowerNPCAlternateSprites[i].normalId == GetFollowerNPCData(FNPC_DATA_GFX_ID))
                return gFollowerNPCAlternateSprites[i].surfId;
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
            if (gFollowerNPCAlternateSprites[i].normalId == GetFollowerNPCData(FNPC_DATA_GFX_ID))
                return gFollowerNPCAlternateSprites[i].underwaterId;
        break;
    }

    return GetFollowerNPCData(FNPC_DATA_GFX_ID);
}

static bool32 FollowerNPCHasRunningFrames(void)
{
    for (u32 i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
    {
        if (gFollowerNPCAlternateSprites[i].normalId == GetFollowerNPCData(FNPC_DATA_GFX_ID)
         && gFollowerNPCAlternateSprites[i].hasRunningFrames == TRUE)
            return TRUE;
    }

    return FALSE;
}

static bool32 IsStateMovement(u32 state)
{
    switch (state)
    {
    case MOVEMENT_ACTION_FACE_DOWN:
    case MOVEMENT_ACTION_FACE_UP:
    case MOVEMENT_ACTION_FACE_LEFT:
    case MOVEMENT_ACTION_FACE_RIGHT:
    case MOVEMENT_ACTION_DELAY_1:
    case MOVEMENT_ACTION_DELAY_2:
    case MOVEMENT_ACTION_DELAY_4:
    case MOVEMENT_ACTION_DELAY_8:
    case MOVEMENT_ACTION_DELAY_16:
    case MOVEMENT_ACTION_FACE_PLAYER:
    case MOVEMENT_ACTION_FACE_AWAY_PLAYER:
    case MOVEMENT_ACTION_LOCK_FACING_DIRECTION:
    case MOVEMENT_ACTION_UNLOCK_FACING_DIRECTION:
    case MOVEMENT_ACTION_SET_INVISIBLE:
    case MOVEMENT_ACTION_SET_VISIBLE:
    case MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK:
    case MOVEMENT_ACTION_EMOTE_QUESTION_MARK:
    case MOVEMENT_ACTION_EMOTE_HEART:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_UP:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT:
        return FALSE;
    }

    return TRUE;
}

// Because we want the NPC follower's movements to happen simultaneously with the player's,
// we need to set the follower's movement before the player object's movementDirection parameter gets set.
// This function allows us to determine the player's new movement direction before it gets set.
static enum Direction GetNewPlayerMovementDirection(u32 state)
{
    switch (state)
    {
    case MOVEMENT_ACTION_WALK_SLOW_DOWN:
    case MOVEMENT_ACTION_WALK_NORMAL_DOWN:
    case MOVEMENT_ACTION_WALK_FAST_DOWN:
    case MOVEMENT_ACTION_WALK_FASTER_DOWN:
    case MOVEMENT_ACTION_PLAYER_RUN_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN:
    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN:
    case MOVEMENT_ACTION_JUMP_DOWN:
        return DIR_SOUTH;
    case MOVEMENT_ACTION_WALK_SLOW_UP:
    case MOVEMENT_ACTION_WALK_NORMAL_UP:
    case MOVEMENT_ACTION_WALK_FAST_UP:
    case MOVEMENT_ACTION_WALK_FASTER_UP:
    case MOVEMENT_ACTION_PLAYER_RUN_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_UP:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_UP:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_UP:
    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_UP:
    case MOVEMENT_ACTION_JUMP_UP:
        return DIR_NORTH;
    case MOVEMENT_ACTION_WALK_SLOW_LEFT:
    case MOVEMENT_ACTION_WALK_NORMAL_LEFT:
    case MOVEMENT_ACTION_WALK_FAST_LEFT:
    case MOVEMENT_ACTION_WALK_FASTER_LEFT:
    case MOVEMENT_ACTION_PLAYER_RUN_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_LEFT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_LEFT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_LEFT:
    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_LEFT:
    case MOVEMENT_ACTION_JUMP_LEFT:
        return DIR_WEST;
    case MOVEMENT_ACTION_WALK_SLOW_RIGHT:
    case MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
    case MOVEMENT_ACTION_WALK_FAST_RIGHT:
    case MOVEMENT_ACTION_WALK_FASTER_RIGHT:
    case MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT:
    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT:
    case MOVEMENT_ACTION_JUMP_RIGHT:
        return DIR_EAST;
    default:
        return DIR_NONE;
    }
}

static bool32 IsPlayerForcedOntoSameTile(u8 metatileBehavior, enum Direction direction)
{
    enum Direction oppositeDirection = DIR_NONE;

    switch (metatileBehavior)
    {
    case MB_WALK_EAST:
    case MB_SLIDE_EAST:
    case MB_EASTWARD_CURRENT:
        oppositeDirection = DIR_WEST;
        break;
    case MB_WALK_WEST:
    case MB_SLIDE_WEST:
    case MB_WESTWARD_CURRENT:
        oppositeDirection = DIR_EAST;
        break;
    case MB_WALK_NORTH:
    case MB_SLIDE_NORTH:
    case MB_NORTHWARD_CURRENT:
        oppositeDirection = DIR_SOUTH;
        break;
    case MB_WALK_SOUTH:
    case MB_SLIDE_SOUTH:
    case MB_SOUTHWARD_CURRENT:
    case MB_MUDDY_SLOPE:
    case MB_WATERFALL:
        oppositeDirection = DIR_NORTH;
        break;
    default:
        return FALSE;
    }

    if (oppositeDirection == direction)
        return TRUE;

    return FALSE;
}

void GetXYCoordsPlayerMovementDest(enum Direction direction, s16 *x, s16 *y)
{
    *x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    *y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    MoveCoords(direction, x, y);
}

static u32 GetPlayerFaceToDoorDirection(struct ObjectEvent *player, struct ObjectEvent *follower)
{
    s32 delta_x = player->currentCoords.x - follower->currentCoords.x;

    if (delta_x < 0)
        return DIR_EAST;
    else if (delta_x > 0)
        return DIR_WEST;

    return DIR_NORTH;
}

static u32 ReturnFollowerNPCDelayedState(enum Direction direction)
{
    u32 newState = GetFollowerNPCData(FNPC_DATA_DELAYED_STATE);
    SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, 0);

    return newState + direction;
}

static void TryUpdateFollowerNPCSpriteUnderwater(void)
{
    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER);

        follower = &gObjectEvents[GetFollowerNPCObjectId()];
        follower->fieldEffectSpriteId = StartUnderwaterSurfBlobBobbing(follower->spriteId);
    }
}

static void SetSurfJump(void)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    enum Direction direction;
    u32 jumpState;

    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction.
    direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
    jumpState = GetJumpMovementAction(direction);
    SetUpSurfBlobFieldEffect(follower);

    // Adjust surf head spawn location infront of follower.
    switch (direction)
    {
    case DIR_SOUTH:
        gFieldEffectArguments[1]++; // effect_y
        break;
    case DIR_NORTH:
        gFieldEffectArguments[1]--;
        break;
    case DIR_WEST:
        gFieldEffectArguments[0]--; // effect_x
        break;
    default: // DIR_EAST
        gFieldEffectArguments[0]++;
    };

    // Execute, store sprite ID in fieldEffectSpriteId and bind surf blob.
    follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    CreateTask(Task_BindSurfBlobToFollowerNPC, 0x1);
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_SURF);

    follower = &gObjectEvents[GetFollowerNPCObjectId()];
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void SetUpSurfBlobFieldEffect(struct ObjectEvent *npc)
{
    // Set up gFieldEffectArguments for execution.
    gFieldEffectArguments[0] = npc->currentCoords.x;                 // effect_x
    gFieldEffectArguments[1] = npc->currentCoords.y;                 // effect_y
    gFieldEffectArguments[2] = GetFollowerNPCData(FNPC_DATA_OBJ_ID); // objId
}

#define tSpriteId       data[0]

static void SetSurfDismount(void)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    enum Direction direction;
    u32 jumpState;
    u32 task;

    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction
    direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
    jumpState = GetJumpMovementAction(direction);

    // Unbind and destroy Surf Blob
    task = CreateTask(Task_FinishSurfDismount, 1);
    gTasks[task].tSpriteId = follower->fieldEffectSpriteId;
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 2);
    follower->fieldEffectSpriteId = 0;
    FollowerNPC_HandleSprite();

    follower = &gObjectEvents[GetFollowerNPCObjectId()];
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void Task_BindSurfBlobToFollowerNPC(u8 taskId)
{
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCObjectId()];
    // Wait for the jump animation.
    bool32 animStatus = ObjectEventClearHeldMovementIfFinished(npc);
    if (!animStatus)
        return;

    // Bind the blob to the follower.
    SetSurfBlob_BobState(npc->fieldEffectSpriteId, 0x1);
    UnfreezeObjectEvents();
    DestroyTask(taskId);
    gPlayerAvatar.preventStep = FALSE;
    return;
}

static void Task_FinishSurfDismount(u8 taskId)
{
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCObjectId()];
    // Wait for the animation to finish.
    bool32 animStatus = ObjectEventClearHeldMovementIfFinished(npc);

    if (!animStatus)
    {
        // Temporarily stop running.
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH) && ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gPlayerAvatar.objectEventId]))
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);

        return;
    }

    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    DestroySprite(&gSprites[gTasks[taskId].tSpriteId]);
    UnfreezeObjectEvents();
    DestroyTask(taskId);
    gPlayerAvatar.preventStep = FALSE;
}

#undef tSpriteId

static void Task_ReallowPlayerMovement(u8 taskId)
{
    bool32 animStatus = ObjectEventClearHeldMovementIfFinished(&gObjectEvents[GetFollowerNPCObjectId()]);
    if (!animStatus)
    {
        // Temporarily stop running.
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH)
        && ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gPlayerAvatar.objectEventId]))
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);

        return;
    }

    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(taskId);
}

// Task data.
#define tDoorTask           data[1]

void Task_FollowerNPCOutOfDoor(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->tDoorX;
    s16 *y = &task->tDoorY;

    // The player faces follower as they exit the door.
    if (FNPC_FACE_NPC_FOLLOWER_ON_DOOR_EXIT == TRUE && ObjectEventClearHeldMovementIfFinished(player))
        ObjectEventTurn(player, GetPlayerFaceToDoorDirection(player, follower));

    switch (task->tState)
    {
    case OPEN_DOOR:
        FreezeObjectEvents();
        task->tDoorTask = FieldAnimateDoorOpen(follower->currentCoords.x, follower->currentCoords.y);
        // Only play SE for animated doors.
        if (task->tDoorTask != -1)
            PlaySE(GetDoorSoundEffect(*x, *y));
        task->tState = NPC_WALK_OUT;
        break;
    case NPC_WALK_OUT:
        // If the door isn't still opening.
        if (task->tDoorTask < 0 || gTasks[task->tDoorTask].isActive != TRUE)
        {
            follower->invisible = FALSE;
            // If the follower should be surfing.
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            {
                SetUpSurfBlobFieldEffect(follower);
                follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
                SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
            }
            ObjectEventTurn(follower, DIR_SOUTH);
            follower->singleMovementActive = FALSE;
            follower->heldMovementActive = FALSE;
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN);
            task->tState = CLOSE_DOOR;
        }
        break;
    case CLOSE_DOOR:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            task->tDoorTask = FieldAnimateDoorClose(*x, *y);
            task->tState = UNFREEZE_OBJECTS;
        }
        break;
    case UNFREEZE_OBJECTS:
        // Wait for door to close.
        if (task->tDoorTask < 0 || gTasks[task->tDoorTask].isActive != TRUE)
        {
            UnfreezeObjectEvents();
            task->tState = REALLOW_MOVEMENT;
        }
        break;
    case REALLOW_MOVEMENT:
    {
        struct MapPosition position;
        enum Direction playerDirection;

        FollowerNPC_HandleSprite();
        SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);
        gPlayerAvatar.preventStep = FALSE;

        playerDirection = GetPlayerFacingDirection();
        GetPlayerPosition(&position);
        if (TryStartStepBasedScript(&position, player->currentMetatileBehavior, playerDirection) == TRUE)
        {
            LockPlayerFieldControls();
            HideMapNamePopUpWindow();
        }
        DestroyTask(taskId);
        break;
    }
    }
}

#undef tDoorTask

static void Task_FollowerNPCHandleEscalator(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    ObjectEventClearHeldMovementIfActive(follower);
    ObjectEventSetHeldMovement(follower, DetermineFollowerNPCState(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN, DetermineFollowerNPCDirection(player, follower)));
    DestroyTask(taskId);
}

#define tCounter                data[1]
#define tMetatileBehavior       data[2]
#define tTimer                  data[7]

static void Task_FollowerNPCHandleEscalatorFinish(u8 taskId)
{
    s16 x, y;
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[follower->spriteId];
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case MOVE_TO_PLAYER_POS:
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        PlayerGetDestCoords(&x, &y);
        task->tMetatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        task->tTimer = 0;
        task->tState = WAIT_FOR_PLAYER_MOVE;
        break;
    case WAIT_FOR_PLAYER_MOVE:
        // Wait half a second before revealing the follower.
        if (task->tTimer++ < 32)
            break;

        task->tState = SHOW_FOLLOWER_DOWN;
        task->tCounter = 16;
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_NONE);
        gPlayerAvatar.preventStep = TRUE;
        ObjectEventClearHeldMovementIfActive(follower);
        ObjectEventSetHeldMovement(follower, GetFaceDirectionMovementAction(DIR_EAST));
        if (task->tMetatileBehavior == 0x6b)
            task->tState = SHOW_FOLLOWER_UP;

        break;
    case SHOW_FOLLOWER_DOWN:
        follower->invisible = FALSE;
        CalculateFollowerNPCEscalatorTrajectoryDown(task);
        task->tState = MOVE_FOLLOWER_DOWN;
        break;
    case MOVE_FOLLOWER_DOWN:
        CalculateFollowerNPCEscalatorTrajectoryDown(task);
        task->tMetatileBehavior++;
        if (task->tMetatileBehavior & 1)
            task->tCounter--;

        if (task->tCounter == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->tState = MOVEMENT_FINISH;
        }
        break;
    case SHOW_FOLLOWER_UP:
        follower->invisible = FALSE;
        CalculateFollowerNPCEscalatorTrajectoryUp(task);
        task->tState = MOVE_FOLLOWER_UP;
        break;
    case MOVE_FOLLOWER_UP:
        CalculateFollowerNPCEscalatorTrajectoryUp(task);
        task->tMetatileBehavior++;
        if (task->tMetatileBehavior & 1)
            task->tCounter--;

        if (task->tCounter == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->tState = MOVEMENT_FINISH;
        }
        break;
    case MOVEMENT_FINISH:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            gPlayerAvatar.preventStep = FALSE;
            DestroyTask(taskId);
        }
    }
}

#undef tMetatileBehavior
#undef tTimer

static void CalculateFollowerNPCEscalatorTrajectoryUp(struct Task *task)
{
    struct Sprite *sprite = &gSprites[gObjectEvents[GetFollowerNPCObjectId()].spriteId];

    sprite->x2 = Cos(0x7c, task->tCounter);
    sprite->y2 = Sin(0x76, task->tCounter);
}

static void CalculateFollowerNPCEscalatorTrajectoryDown(struct Task *task)
{
    struct Sprite *sprite = &gSprites[gObjectEvents[GetFollowerNPCObjectId()].spriteId];

    sprite->x2 = Cos(0x84, task->tCounter);
    sprite->y2 = Sin(0x94, task->tCounter);
}

#undef tCounter

void CreateFollowerNPC(u32 gfx, u32 followerFlags, const u8 *scriptPtr)
{
    if (PlayerHasFollowerNPC())
        return;

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent *follower;
    struct ObjectEventTemplate npc =
    {
        .localId = OBJ_EVENT_ID_NPC_FOLLOWER,
        .graphicsId = gfx,
        .x = player->currentCoords.x,
        .y = player->currentCoords.y,
        .elevation = PlayerGetElevation(),
        .script = scriptPtr
    };

    SetFollowerNPCData(FNPC_DATA_OBJ_ID, TrySpawnObjectEventTemplate(&npc, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, player->currentCoords.x, player->currentCoords.y));
    follower = &gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)];
    follower->movementType = MOVEMENT_TYPE_NONE;
    gSprites[follower->spriteId].callback = MovementType_None;

    SetFollowerNPCData(FNPC_DATA_IN_PROGRESS, TRUE);
    SetFollowerNPCData(FNPC_DATA_GFX_ID, follower->graphicsId);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
    SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);
    SetFollowerNPCScriptPointer(scriptPtr);
    if (FollowerNPCHasRunningFrames())
        followerFlags |= FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES;

    SetFollowerNPCData(FNPC_DATA_FOLLOWER_FLAGS, followerFlags);

    // If the player is biking and the follower flags prohibit biking, force the player to dismount the bike.
    if (!CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_BIKE)
    &&  TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE))
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);

    // Set the follower sprite to match the player state.
    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ON_FOOT))
        FollowerNPC_HandleSprite();

    HideNPCFollower();
    SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
}

void DestroyFollowerNPC(void)
{
    if (!PlayerHasFollowerNPC())
        return;

    RemoveObjectEvent(&gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)]);
    ClearFollowerNPCData();
    UpdateFollowingPokemon();
}

#define RETURN_STATE(state, dir) return newState == MOVEMENT_INVALID ? state + (dir - 1) : ReturnFollowerNPCDelayedState(dir - 1);
u32 DetermineFollowerNPCState(struct ObjectEvent *follower, u32 state, enum Direction direction)
{
    u32 newState = MOVEMENT_INVALID;
    enum Collision collision = COLLISION_NONE;
    s16 followerX = follower->currentCoords.x;
    s16 followerY = follower->currentCoords.y;
    u32 currentBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);
    u32 nextBehavior;
    u32 noSpecialAnimFrames = (GetFollowerNPCSprite() == GetFollowerNPCData(FNPC_DATA_GFX_ID));
    u32 delayedState = GetFollowerNPCData(FNPC_DATA_DELAYED_STATE);
    s16 playerDestX, playerDestY;
    enum Direction playerMoveDirection = GetNewPlayerMovementDirection(state);
    u32 newPlayerMB;

    MoveCoords(direction, &followerX, &followerY);
    nextBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);
    follower->facingDirectionLocked = FALSE;

    // Follower won't do delayed movement until player does a movement.
    if (!IsStateMovement(state) && delayedState)
        return MOVEMENT_ACTION_NONE;

    // Follower won't move if player is forced back onto the same tile.
    if (GetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT) == FNPC_FORCED_STAY)
        return MOVEMENT_ACTION_NONE;

    GetXYCoordsPlayerMovementDest(playerMoveDirection, &playerDestX, &playerDestY);
    newPlayerMB = MapGridGetMetatileBehaviorAt(playerDestX, playerDestY);

    if (IsPlayerForcedOntoSameTile(newPlayerMB, playerMoveDirection)
     && !(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE && playerMoveDirection == DIR_NORTH && newPlayerMB == MB_MUDDY_SLOPE && GetPlayerSpeed() >= PLAYER_SPEED_FAST))
    {
        SetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT, FNPC_FORCED_STAY);
        SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, 0);
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
            ObjectEventSetHeldMovement(follower, GetFaceDirectionAnimNum(follower->facingDirection));

        return MOVEMENT_INVALID;
    }

    if (IsStateMovement(state) && delayedState)
    {
        // Lock face direction for Acro side jump.
        if (delayedState == MOVEMENT_ACTION_JUMP_DOWN && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
            follower->facingDirectionLocked = TRUE;

        newState = delayedState + (direction -1);
    }

    // Clear ice tile stuff.
    follower->disableAnim = FALSE;

    // Clear overwrite movement.
    follower->directionOverwrite = DIR_NONE;

    // Sideways stairs checks.
    collision = GetSidewaysStairsCollision(follower, direction, currentBehavior, nextBehavior, collision);
    switch (collision)
    {
    case COLLISION_SIDEWAYS_STAIRS_TO_LEFT:
        follower->directionOverwrite = GetLeftSideStairsDirection(direction);
        break;
    case COLLISION_SIDEWAYS_STAIRS_TO_RIGHT:
        follower->directionOverwrite = GetRightSideStairsDirection(direction);
        break;
    default:
        break;
    }

    switch (state)
    {
    case MOVEMENT_ACTION_WALK_SLOW_DOWN ... MOVEMENT_ACTION_WALK_SLOW_RIGHT:
        // Slow walk.
        RETURN_STATE(MOVEMENT_ACTION_WALK_SLOW_DOWN, direction);

    case MOVEMENT_ACTION_WALK_NORMAL_DOWN ... MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        // Normal walk.
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_2_DOWN ... MOVEMENT_ACTION_JUMP_2_RIGHT:
        // Ledge jump.
        if (delayedState == MOVEMENT_ACTION_JUMP_2_DOWN)
            return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1));

        if (delayedState == MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN)
            return (MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN + (direction - 1));

        SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, MOVEMENT_ACTION_JUMP_2_DOWN);
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FAST_DOWN ... MOVEMENT_ACTION_WALK_FAST_RIGHT:
        // Handle ice tile (some walking animation).
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;

        // Handle surfing.
        if (GetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE) == FOLLOWER_NPC_SPRITE_INDEX_SURF && GetFollowerNPCSprite() == GetFollowerNPCData(FNPC_DATA_GFX_ID))
            RETURN_STATE(MOVEMENT_ACTION_SURF_STILL_DOWN, direction);

        if (MetatileBehavior_IsMuddySlope(follower->currentMetatileBehavior))
            follower->facingDirectionLocked = TRUE;

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FASTER_DOWN ... MOVEMENT_ACTION_WALK_FASTER_RIGHT:
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;

        RETURN_STATE(MOVEMENT_ACTION_WALK_FASTER_DOWN, direction);

    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN ... MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN, direction);

    // Acro bike.
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_JUMP_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
        // Ledge jump.
        if (noSpecialAnimFrames)
        {
            if (delayedState == MOVEMENT_ACTION_JUMP_2_DOWN)
                return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1));

            SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, MOVEMENT_ACTION_JUMP_2_DOWN);
        }
        else
        {
            if (delayedState == MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN)
                return (MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN + (direction - 1));

            if (delayedState == MOVEMENT_ACTION_JUMP_2_DOWN)
                return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1));

            SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN);
        }

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN, direction);

    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN, direction);

    // Sliding.
    case MOVEMENT_ACTION_SLIDE_DOWN ... MOVEMENT_ACTION_SLIDE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_SLIDE_DOWN, direction);

    case MOVEMENT_ACTION_PLAYER_RUN_DOWN ... MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
        // Running frames.
        if (CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES))
            RETURN_STATE(MOVEMENT_ACTION_PLAYER_RUN_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_SPECIAL_DOWN ... MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT:
        SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, MOVEMENT_ACTION_JUMP_SPECIAL_DOWN);
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_DOWN ... MOVEMENT_ACTION_JUMP_RIGHT:
        // Acro side hop.
        if (delayedState == MOVEMENT_ACTION_JUMP_DOWN)
        {
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
                follower->facingDirectionLocked = TRUE;

            return newState;
        }
        else
        {
            SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, MOVEMENT_ACTION_JUMP_DOWN);
            RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);
        }

    // Run slow.
    case MOVEMENT_ACTION_RUN_DOWN_SLOW ... MOVEMENT_ACTION_RUN_RIGHT_SLOW:
        if (CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES))
            RETURN_STATE(MOVEMENT_ACTION_RUN_DOWN_SLOW, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    // Slow stairs.
    case MOVEMENT_ACTION_WALK_SLOW_STAIRS_DOWN ... MOVEMENT_ACTION_WALK_SLOW_STAIRS_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_WALK_SLOW_STAIRS_DOWN, direction);

    default:
        return MOVEMENT_INVALID;
    }

    return newState;
}

/*
 * Reload the entire event object.
 * It would usually be enough just to change the sprite Id, but if the original
 * sprite and the new sprite have different palettes, the palette would need to
 * be reloaded.
 */
void SetFollowerNPCSprite(u32 spriteIndex)
{
    u32 oldSpriteId;
    u32 newSpriteId;
    u32 newGraphicsId;
    struct ObjectEventTemplate clone;
    struct ObjectEvent backupFollower;
    struct ObjectEvent *follower;

    if (!PlayerHasFollowerNPC())
        return;

    if (GetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE) == spriteIndex)
        return;

    // Save the sprite.
    follower = &gObjectEvents[GetFollowerNPCObjectId()];
    SetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE, spriteIndex);
    oldSpriteId = follower->spriteId;
    newGraphicsId = GetFollowerNPCSprite();
    clone = *GetObjectEventTemplateByLocalIdAndMap(OBJ_EVENT_ID_NPC_FOLLOWER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);

    backupFollower = *follower;
    backupFollower.graphicsId = newGraphicsId;
    DestroySprite(&gSprites[oldSpriteId]);
    RemoveObjectEvent(&gObjectEvents[GetFollowerNPCObjectId()]);

    clone.graphicsId = newGraphicsId;
    clone.movementType = 0;
    clone.localId = OBJ_EVENT_ID_NPC_FOLLOWER;
    SetFollowerNPCData(FNPC_DATA_OBJ_ID, TrySpawnObjectEventTemplate(&clone, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, clone.x, clone.y));
    if (GetFollowerNPCData(FNPC_DATA_OBJ_ID) != OBJECT_EVENTS_COUNT)
    {
        follower = &gObjectEvents[GetFollowerNPCObjectId()];
        newSpriteId = follower->spriteId;
        *follower = backupFollower;
        follower->spriteId = newSpriteId;
        MoveObjectEventToMapCoords(follower, follower->currentCoords.x, follower->currentCoords.y);
        ObjectEventTurn(follower, follower->facingDirection);
    }
    else
    {
        ClearFollowerNPCData();
    }
}

static void ChooseFirstThreeEligibleMons(void)
{
    u32 i;
    u32 count = 0;

    ClearSelectedPartyOrder();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP) != 0
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG) == FALSE
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            gSelectedOrderFromParty[count] = (i + 1);
            count++;
        }

        if (count == 3)
            break;
    }
}

bool32 PlayerHasFollowerNPC(void)
{
    return GetFollowerNPCData(FNPC_DATA_IN_PROGRESS);
}

void NPCFollow(struct ObjectEvent *npc, u32 state, bool32 ignoreScriptActive)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    enum Direction dir;
    u32 newState;
    u32 taskId;

    // Only when the player moves.
    if (player != npc)
        return;
    // Only if a follower exists.
    else if (!PlayerHasFollowerNPC())
        return;
    // Don't follow during a script.
    else if (ArePlayerFieldControlsLocked() && !ignoreScriptActive)
        return;

    // If the follower's object has been removed, create a new one and set it to reappear.
    if (!follower->active)
    {
        CreateFollowerNPCAvatar();
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
    }

    // Restore post warp behavior after setobjectxy.
    if (GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) == FNPC_DOOR_NO_POS_SET)
        SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);

    // Follower changes to normal sprite after getting off surf blob.
    if (GetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE) == FOLLOWER_NPC_SPRITE_INDEX_SURF && !CheckFollowerNPCFlag(PLAYER_AVATAR_FLAG_SURFING) && follower->fieldEffectSpriteId == 0)
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
    }

    // Check if the state would cause hidden follower to reappear.
    if (IsStateMovement(state) && GetFollowerNPCData(FNPC_DATA_WARP_END) == FNPC_WARP_REAPPEAR)
    {
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_NONE);

        if (GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) == FNPC_DOOR_NEEDS_TO_EXIT)
        {
            gPlayerAvatar.preventStep = TRUE;
            taskId = CreateTask(Task_FollowerNPCOutOfDoor, 1);
            gTasks[taskId].tState = 0;
            gTasks[taskId].tDoorX = follower->currentCoords.x;
            gTasks[taskId].tDoorY = follower->currentCoords.y;
            TryUpdateFollowerNPCSpriteUnderwater();
            ObjectEventClearHeldMovementIfFinished(follower);
            return;
        }

        follower->invisible = FALSE;
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        // The follower should be facing the same direction as the player when it comes out of hiding.
        ObjectEventTurn(follower, player->facingDirection);

        // Recreate the surf blob if needed.
        if (GetFollowerNPCData(FNPC_DATA_SURF_BLOB) == FNPC_SURF_BLOB_RECREATE)
        {
            SetUpSurfBlobFieldEffect(follower);
            follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
            SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
        }
        else
        {
            TryUpdateFollowerNPCSpriteUnderwater();
        }
    }

    dir = DetermineFollowerNPCDirection(player, follower);

    if (dir == DIR_NONE)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    newState = DetermineFollowerNPCState(follower, state, dir);
    if (newState == MOVEMENT_INVALID)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    // Follower gets on surf blob.
    if (GetFollowerNPCData(FNPC_DATA_SURF_BLOB) == FNPC_SURF_BLOB_NEW && IsStateMovement(state))
    {
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_RECREATE);
        gPlayerAvatar.preventStep = TRUE;
        SetSurfJump();
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }
    // Follower gets off surf blob.
    else if (GetFollowerNPCData(FNPC_DATA_SURF_BLOB) == FNPC_SURF_BLOB_DESTROY)
    {
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
        gPlayerAvatar.preventStep = TRUE;
        SetSurfDismount();
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    ObjectEventClearHeldMovementIfActive(follower);
    ObjectEventSetHeldMovement(follower, newState);
    PlayerLogCoordinates(player);

    switch (newState)
    {
    case MOVEMENT_ACTION_JUMP_2_DOWN ... MOVEMENT_ACTION_JUMP_2_RIGHT:
    case MOVEMENT_ACTION_JUMP_DOWN ... MOVEMENT_ACTION_JUMP_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
        // Synchronize movements on stairs and ledges.
        CreateTask(Task_ReallowPlayerMovement, 1);
        gPlayerAvatar.preventStep = TRUE;
    }

    ObjectEventClearHeldMovementIfFinished(follower);
}

void CreateFollowerNPCAvatar(void)
{
    if (!PlayerHasFollowerNPC())
        return;

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEventTemplate clone =
    {
        .localId = OBJ_EVENT_ID_NPC_FOLLOWER,
        .graphicsId = GetFollowerNPCSprite(),
        .x = player->currentCoords.x - 7,
        .y = player->currentCoords.y - 7,
        .elevation = player->currentElevation,
        .script = GetFollowerNPCScriptPointer(),
        .movementType = MOVEMENT_TYPE_FACE_DOWN
    };

    switch (GetPlayerFacingDirection())
    {
    case DIR_NORTH:
        clone.movementType = MOVEMENT_TYPE_FACE_UP;
        break;
    case DIR_WEST:
        clone.movementType = MOVEMENT_TYPE_FACE_LEFT;
        break;
    case DIR_EAST:
        clone.movementType = MOVEMENT_TYPE_FACE_RIGHT;
        break;
    default:
        break;
    }

    // Create NPC and store ID.
    SetFollowerNPCData(FNPC_DATA_OBJ_ID, TrySpawnObjectEventTemplate(&clone, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, clone.x, clone.y));
    if (GetFollowerNPCData(FNPC_DATA_OBJ_ID) == OBJECT_EVENTS_COUNT)
    {
        ClearFollowerNPCData();
        return;
    }

    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);

    gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)].invisible = TRUE;
}

void FollowerNPC_HandleSprite(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE) && CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_BIKE))
    {
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
            SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE);
        else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE)
            SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE);
    }
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    }
}

enum Direction DetermineFollowerNPCDirection(struct ObjectEvent *player, struct ObjectEvent *follower)
{
    if (player->currentCoords.x == follower->currentCoords.x
     && player->currentCoords.y == follower->currentCoords.y)
        return DIR_NONE;
        
    return DetermineObjectEventDirectionFromObject(player, follower);
}

u32 GetFollowerNPCObjectId(void)
{
    if (PlayerHasFollowerNPC())
        return GetFollowerNPCData(FNPC_DATA_OBJ_ID);

    return 0;
}

bool32 CheckFollowerNPCFlag(u32 flag)
{
    if (!PlayerHasFollowerNPC())
        return TRUE;

    if (GetFollowerNPCData(FNPC_DATA_FOLLOWER_FLAGS) & flag)
        return TRUE;

    return FALSE;
}

bool32 FollowerNPC_IsCollisionExempt(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!PlayerHasFollowerNPC())
        return FALSE;

    if (obstacle == follower && collider == player)
        return TRUE;

    return FALSE;
}

void HideNPCFollower(void)
{
    if (!PlayerHasFollowerNPC() || gObjectEvents[GetFollowerNPCObjectId()].invisible)
        return;

    if (GetFollowerNPCData(FNPC_DATA_SURF_BLOB) == FNPC_SURF_BLOB_RECREATE || GetFollowerNPCData(FNPC_DATA_SURF_BLOB) == FNPC_SURF_BLOB_DESTROY)
    {
        SetSurfBlob_BobState(gObjectEvents[GetFollowerNPCObjectId()].fieldEffectSpriteId, 2);
        DestroySprite(&gSprites[gObjectEvents[GetFollowerNPCObjectId()].fieldEffectSpriteId]);
        gObjectEvents[GetFollowerNPCObjectId()].fieldEffectSpriteId = 0;
    }

    SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);

    gObjectEvents[GetFollowerNPCObjectId()].invisible = TRUE;
}

void FollowerNPC_WarpSetEnd(void)
{
    struct ObjectEvent *player;
    struct ObjectEvent *follower;

    if (!PlayerHasFollowerNPC())
        return;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    follower = &gObjectEvents[GetFollowerNPCObjectId()];

    PlayerLogCoordinates(player);

    // Skip setting position if setobjectxy was used during ON_WARP_INTO_MAP_TABLE.
    if (GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) == FNPC_DOOR_NO_POS_SET)
    {
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_NONE);
        SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);
    }
    else
    {
        u32 toY = GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) == FNPC_DOOR_NEEDS_TO_EXIT ? (player->currentCoords.y - 1) : player->currentCoords.y;
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, toY);
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
    }

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
    }
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_SURF);
        SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_RECREATE);
    }

    follower->facingDirection = player->facingDirection;
    follower->movementDirection = player->movementDirection;
}

bool32 FollowerNPCCanBike(void)
{
    if (!PlayerHasFollowerNPC())
        return TRUE;
    else if (CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_BIKE))
        return TRUE;
    else
        return FALSE;
}

void FollowerNPC_HandleBike(void)
{
    // Wait until after get off surf blob to start biking.
    if (GetFollowerNPCData(FNPC_DATA_CURRENT_SPRITE) == FOLLOWER_NPC_SPRITE_INDEX_SURF)
        return;

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE && FollowerNPCCanBike() && GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) != FNPC_DOOR_NEEDS_TO_EXIT) //Coming out door
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE);
    }
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE && FollowerNPCCanBike() && GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR) != FNPC_DOOR_NEEDS_TO_EXIT) //Coming out door
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE);
    }
    else
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
        // Disable saved Acro side jump.
        if (GetFollowerNPCData(FNPC_DATA_DELAYED_STATE) == MOVEMENT_ACTION_JUMP_DOWN)
            SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, 0);
    }
}

void FollowerNPC_FollowerToWater(void)
{
    if (!PlayerHasFollowerNPC())
        return;

    // Prepare for making the follower do the jump and spawn the surf blob right in front of the follower's location.
    NPCFollow(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_JUMP_DOWN, TRUE);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NEW);
}

void FollowerNPC_BindToSurfBlobOnReloadScreen(void)
{
    struct ObjectEvent *follower;

    if (!PlayerHasFollowerNPC())
        return;

    follower = &gObjectEvents[GetFollowerNPCObjectId()];
    TryUpdateFollowerNPCSpriteUnderwater();

    if (follower->invisible || (GetFollowerNPCData(FNPC_DATA_SURF_BLOB) != FNPC_SURF_BLOB_RECREATE && GetFollowerNPCData(FNPC_DATA_SURF_BLOB) != FNPC_SURF_BLOB_DESTROY))
        return;

    // Spawn the surf blob under the follower.
    SetUpSurfBlobFieldEffect(follower);
    follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
}

void PrepareFollowerNPCDismountSurf(void)
{
    if (!PlayerHasFollowerNPC())
        return;

    NPCFollow(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_WALK_NORMAL_DOWN, TRUE);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_DESTROY);
}

void SetFollowerNPCSurfSpriteAfterDive(void)
{
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_SURF);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_RECREATE);
}

bool32 FollowerNPCComingThroughDoor(void)
{
    if (!PlayerHasFollowerNPC())
        return FALSE;

    if (GetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR))
        return TRUE;

    return FALSE;
}

void FollowerNPC_SetIndicatorToComeOutDoor(void)
{
    if (PlayerHasFollowerNPC())
        SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NEEDS_TO_EXIT);
}

void EscalatorMoveFollowerNPC(u32 movementType)
{
    u8 taskId;

    if (!PlayerHasFollowerNPC())
        return;

    taskId = CreateTask(Task_FollowerNPCHandleEscalator, 1);
    gTasks[taskId].data[1] = movementType;
}

void EscalatorMoveFollowerNPCFinish(void)
{
    if (!PlayerHasFollowerNPC())
        return;

    CreateTask(Task_FollowerNPCHandleEscalatorFinish, 1);
}

void FollowerNPCWalkIntoPlayerForLeaveMap(void)
{
    u32 followerObjId = GetFollowerNPCObjectId();
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];

    if (followerObjId == OBJECT_EVENTS_COUNT)
        return;

    follower->singleMovementActive = FALSE;
    follower->heldMovementActive = FALSE;
    switch (DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], &gObjectEvents[followerObjId]))
    {
    case DIR_NORTH:
        ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_UP);
        break;
    case DIR_SOUTH:
        ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN);
        break;
    case DIR_EAST:
        ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_RIGHT);
        break;
    case DIR_WEST:
        ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_LEFT);
        break;
    default:
        break;
    }
}

void FollowerNPCHideForLeaveMap(struct ObjectEvent *follower)
{
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    follower->invisible = TRUE;
    SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
    SetFollowerNPCData(FNPC_DATA_COME_OUT_DOOR, FNPC_DOOR_NONE);
    SetFollowerNPCData(FNPC_DATA_SURF_BLOB, FNPC_SURF_BLOB_NONE);
    SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, 0);
}

void FollowerNPCReappearAfterLeaveMap(struct ObjectEvent *follower, struct ObjectEvent *player)
{
    if (PlayerHasFollowerNPC())
    {
        follower->invisible = FALSE;
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        ObjectEventTurn(follower, DIR_SOUTH);
        follower->singleMovementActive = FALSE;
        follower->heldMovementActive = FALSE;

        // Follower only steps onto a tile without collision.
        if (GetCollisionAtCoords(player, player->currentCoords.x, player->currentCoords.y + 1, DIR_SOUTH) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN);
        else if (GetCollisionAtCoords(player, player->currentCoords.x + 1, player->currentCoords.y, DIR_EAST) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_RIGHT);
        else if (GetCollisionAtCoords(player, player->currentCoords.x - 1, player->currentCoords.y, DIR_WEST) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_LEFT);
        else
            HideNPCFollower();
    }
}

void FollowerNPCFaceAfterLeaveMap(void)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)];

    if (follower->invisible)
        return;

    ObjectEventTurn(follower, DetermineFollowerNPCDirection(player, follower));
    SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_NONE);
}

bool32 FollowerNPCIsBattlePartner(void)
{
    if (PlayerHasFollowerNPC() && GetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER))
        return TRUE;

    return FALSE;
}

bool32 IsNPCFollowerWildBattle(void)
{
    if (FollowerNPCIsBattlePartner() && FNPC_FLAG_PARTNER_WILD_BATTLES != 0
     && (FNPC_FLAG_PARTNER_WILD_BATTLES == FNPC_ALWAYS || FlagGet(FNPC_FLAG_PARTNER_WILD_BATTLES)))
        return TRUE;

    return FALSE;
}

void PrepareForFollowerNPCBattle(void)
{
    // Load the partner party if the NPC follower should participate.
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && FollowerNPCIsBattlePartner())
    {
        if (!AreMultiPartiesFullTeams())
        {
            SavePlayerParty();
            ChooseFirstThreeEligibleMons();
            ReducePlayerPartyToSelectedMons();
            VarSet(VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA);
            VarSet(VAR_0x8005, FRONTIER_DATA_SELECTED_MON_ORDER);
            CallFrontierUtilFunc();
        }
        gPartnerTrainerId = TRAINER_PARTNER(GetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER));
        FillPartnerParty(gPartnerTrainerId);
    }
}

void RestorePartyAfterFollowerNPCBattle(void)
{
    if (!AreMultiPartiesFullTeams())
    {
        VarSet(VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY);
        CallFrontierUtilFunc();
        LoadPlayerParty();
    }
}

void FollowerNPC_TryRemoveFollowerOnWhiteOut(void)
{
    if (PlayerHasFollowerNPC())
    {
        if (CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CLEAR_ON_WHITE_OUT))
            ClearFollowerNPCData();
        else
            FollowerNPC_WarpSetEnd();
    }
}

#undef tDoorX
#undef tDoorY

// Task data
#define NPC_INTO_PLAYER         0
#define ENABLE_PLAYER_STEP      1

void Task_MoveNPCFollowerAfterForcedMovement(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCObjectId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // If follower moved during player's forced momvements.
    if (GetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT) == FNPC_FORCED_FOLLOW)
    {
        // The NPC will take an extra step and be on the same tile as the player.
        if (gTasks[taskId].tState == NPC_INTO_PLAYER && ObjectEventClearHeldMovementIfFinished(player) != 0 && ObjectEventClearHeldMovementIfFinished(follower) != 0)
        {
            if (follower->currentMetatileBehavior == MB_MUDDY_SLOPE)
                follower->facingDirectionLocked = TRUE;

            ObjectEventSetHeldMovement(follower, GetWalkFastMovementAction(DetermineFollowerNPCDirection(player, follower)));
            gTasks[taskId].tState = ENABLE_PLAYER_STEP;
            return;
        }
        // Hide the NPC until the player takes a step. Reallow player input.
        else if (gTasks[taskId].tState == ENABLE_PLAYER_STEP && ObjectEventClearHeldMovementIfFinished(follower) != 0)
        {
            follower->facingDirectionLocked = FALSE;
            HideNPCFollower();
            SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
            SetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT, FNPC_FORCED_NONE);
            gPlayerAvatar.preventStep = FALSE;
            DestroyTask(taskId);
        }
    }
    // If player was forced back onto the same tile.
    else if (GetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT) == FNPC_FORCED_STAY)
    {
        if (ObjectEventClearHeldMovementIfFinished(player) != 0)
        {
            SetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT, FNPC_FORCED_NONE);
            SetFollowerNPCData(FNPC_DATA_DELAYED_STATE, 0);
            gPlayerAvatar.preventStep = FALSE;
            DestroyTask(taskId);
        }
    }
}

#undef tState
#undef NPC_INTO_PLAYER
#undef ENABLE_PLAYER_STEP

void Task_HideNPCFollowerAfterMovementFinish(u8 taskId)
{
    struct ObjectEvent *npcFollower = &gObjectEvents[GetFollowerNPCObjectId()];

    if (ObjectEventClearHeldMovementIfFinished(npcFollower) != 0)
    {
        HideNPCFollower();
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(taskId);
    }
}

// Script commands.
void ScriptSetFollowerNPC(struct ScriptContext *ctx)
{
    u32 localId = ScriptReadByte(ctx);
    u32 flags = ScriptReadHalfword(ctx);
    u32 setScript = ScriptReadByte(ctx);
    u32 battlePartner = ScriptReadHalfword(ctx);
    const u8 *script = (const u8 *)ScriptReadWord(ctx);

    if (PlayerHasFollowerNPC())
        return;

    SetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER, battlePartner);
    TurnNPCIntoFollower(localId, flags, setScript, script);
}

void ScriptCreateFollowerNPC(struct ScriptContext *ctx)
{
    u32 gfx = ScriptReadHalfword(ctx);
    u32 flags = ScriptReadHalfword(ctx);
    const u8 *script = (const u8 *)ScriptReadWord(ctx);
    u32 battlePartner = ScriptReadHalfword(ctx);

    if (!FNPC_ENABLE_NPC_FOLLOWERS || PlayerHasFollowerNPC())
        return;

    SetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER, battlePartner);
    CreateFollowerNPC(gfx, flags, script);
}

void ScriptDestroyFollowerNPC(struct ScriptContext *ctx)
{
    DestroyFollowerNPC();
}

void ScriptFaceFollowerNPC(struct ScriptContext *ctx)
{
    if (!FNPC_ENABLE_NPC_FOLLOWERS || !PlayerHasFollowerNPC())
        return;

    struct ObjectEvent *player, *follower;
    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    follower = &gObjectEvents[GetFollowerNPCData(FNPC_DATA_OBJ_ID)];
    ObjectEventsTurnToEachOther(player, follower);
}

static const u8 *const FollowerNPCHideMovementsSpeedTable[][4] =
{
    [DIR_SOUTH] = {Common_Movement_WalkDownSlow, Common_Movement_WalkDown, Common_Movement_WalkDownFast, Common_Movement_WalkDownFaster},
    [DIR_NORTH] = {Common_Movement_WalkUpSlow, Common_Movement_WalkUp, Common_Movement_WalkUpFast, Common_Movement_WalkUpFaster},
    [DIR_WEST] = {Common_Movement_WalkLeftSlow, Common_Movement_WalkLeft, Common_Movement_WalkLeftFast, Common_Movement_WalkLeftFaster},
    [DIR_EAST] = {Common_Movement_WalkRightSlow, Common_Movement_WalkRight, Common_Movement_WalkRightFast, Common_Movement_WalkRightFaster}
};

void ScriptHideNPCFollower(struct ScriptContext *ctx)
{
    if (!FNPC_ENABLE_NPC_FOLLOWERS || !PlayerHasFollowerNPC())
        return;

    u32 walkSpeed = ScriptReadByte(ctx);
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCObjectId()];

    if (npc->invisible == FALSE)
    {
        enum Direction direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], npc);

        if (walkSpeed > 3)
            walkSpeed = 3;

        ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_NPC_FOLLOWER, npc->mapGroup, npc->mapNum, FollowerNPCHideMovementsSpeedTable[direction][walkSpeed]);
        SetFollowerNPCData(FNPC_DATA_WARP_END, FNPC_WARP_REAPPEAR);
    }
}

void ScriptCheckFollowerNPC(struct ScriptContext *ctx)
{
    gSpecialVar_Result = PlayerHasFollowerNPC();
}

void ScriptUpdateFollowingMon(struct ScriptContext *ctx)
{
    UpdateFollowingPokemon();
}

void ScriptChangeFollowerNPCBattlePartner(struct ScriptContext *ctx)
{
    if (!FNPC_ENABLE_NPC_FOLLOWERS || !PlayerHasFollowerNPC())
        return;

    u32 newBattlePartner = ScriptReadHalfword(ctx);

    SetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER, newBattlePartner);
}

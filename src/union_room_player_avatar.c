#include "global.h"
#include "constants/flags.h"
#include "constants/event_object_movement_constants.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "script.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "union_room.h"
#include "task.h"

EWRAM_DATA struct UnkStruct_8019BA8 * gUnknown_02022C64 = NULL;
EWRAM_DATA u32 gUnknown_02022C68 = 0;

u8 sub_8019DF4(void);
bool32 sub_8019F8C(u32 playerIdx, u32 arg1);
void sub_801A3B0(u32 arg0, u32 arg1, u8 arg2);

ALIGNED(4) const u8 gUnknown_082F072C[][10] = {
    {0x21, 0x2c, 0x1f, 0x23, 0x25, 0x24, 0x41, 0x42},
    {0x22, 0x28, 0x20, 0x2f, 0x2f, 0x0e, 0x14, 0x2d}
};

const s16 gUnknown_082F0740[][2] = {
    {0x4, 0x6},
    {0xd, 0x8},
    {0xa, 0x6},
    {0x1, 0x8},
    {0xd, 0x4},
    {0x7, 0x4},
    {0x1, 0x4},
    {0x7, 0x8}
};

const s8 gUnknown_082F0760[][2] = {
    { 0,  0},
    { 1,  0},
    { 0, -1},
    {-1,  0},
    { 0,  1}
};

const u8 gUnknown_082F076A[] = {
    0x00, 0x02, 0x01, 0x04, 0x03
};

const u8 gUnknown_082F076F[] = {
    0x01, 0x03, 0x01, 0x04, 0x02
};

const u8 gUnknown_082F0774[] = {
    0x09, 0x08, 0x07, 0x02, 0x06, 0x05, 0x04, 0x03,
    0xbf, 0x02, 0xc0, 0x02, 0xc1, 0x02, 0xc2, 0x02,
    0xc3, 0x02, 0xc4, 0x02, 0xc5, 0x02, 0xc6, 0x02
};

const u8 gUnknown_082F078C[2] = {
    MOVEMENT_ACTION_FLY_UP,
    MOVEMENT_ACTION_STEP_END
};

const u8 gUnknown_082F078E[2] = {
    MOVEMENT_ACTION_FLY_DOWN,
    MOVEMENT_ACTION_STEP_END
};

bool32 is_walking_or_running(void)
{
    if (gPlayerAvatar.tileTransitionState == 2 || gPlayerAvatar.tileTransitionState == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

u8 sub_8019978(u32 a0, u32 a1)
{
    return gUnknown_082F072C[a0][a1 % 8];
}

void sub_8019990(u32 a0, u32 a1, s32 * a2, s32 * a3)
{
    *a2 = gUnknown_082F0740[a0][0] + gUnknown_082F0760[a1][0] + 7;
    *a3 = gUnknown_082F0740[a0][1] + gUnknown_082F0760[a1][1] + 7;
}

bool32 sub_80199E0(u32 a0, u32 a1, s32 a2, s32 a3)
{
    if (gUnknown_082F0740[a0][0] + gUnknown_082F0760[a1][0] + 7 != a2)
    {
        return FALSE;
    }
    else if (gUnknown_082F0740[a0][1] + gUnknown_082F0760[a1][1] + 7 != a3)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool32 IsUnionRoomPlayerHidden(u32 player_idx)
{
    return FlagGet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void HideUnionRoomPlayer(u32 player_idx)
{
    FlagSet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void ShowUnionRoomPlayer(u32 player_idx)
{
    FlagClear(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void SetUnionRoomPlayerGfx(u32 playerIdx, u32 gfxId)
{
    VarSet(VAR_OBJ_GFX_ID_0 + playerIdx, gfxId);
}

void CreateUnionRoomPlayerEventObject(u32 playerIdx)
{
    show_sprite(gUnknown_082F0774[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

void RemoveUnionRoomPlayerEventObject(u32 playerIdx)
{
    RemoveEventObjectByLocalIdAndMap(gUnknown_082F0774[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool32 SetUnionRoomPlayerEnterExitMovement(u32 playerIdx, const u8 * movement)
{
    u8 objectId;
    struct EventObject * object;
    if (TryGetEventObjectIdByLocalIdAndMap(gUnknown_082F0774[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
    {
        return FALSE;
    }
    object = &gEventObjects[objectId];
    if (EventObjectIsMovementOverridden(object))
    {
        return FALSE;
    }
    if (EventObjectSetHeldMovement(object, *movement))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 sub_8019B3C(u32 playerIdx)
{
    u8 objectId;
    struct EventObject * object;
    if (TryGetEventObjectIdByLocalIdAndMap(gUnknown_082F0774[playerIdx], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
    {
        return TRUE;
    }
    object = &gEventObjects[objectId];
    if (!EventObjectClearHeldMovementIfFinished(object))
    {
        return FALSE;
    }
    if (!ScriptContext2_IsEnabled())
    {
        UnfreezeEventObject(object);
    }
    else
    {
        FreezeEventObject(object);
    }
    return TRUE;
}

u8 sub_8019BA8(struct UnkStruct_8019BA8 * ptr)
{
    s32 i;

    gUnknown_02022C68 = 0;
    gUnknown_02022C64 = ptr;
    for (i = 0; i < 8; i++)
    {
        ptr[i].field_0 = 0;
        ptr[i].field_1 = 0;
        ptr[i].field_2 = 0;
        ptr[i].field_3 = 0;
    }
    return sub_8019DF4();
}

bool32 sub_8019BDC(s8 * a0, u32 playerIdx, struct UnkStruct_8019BA8 * ptr)
{
    switch (*a0)
    {
    case 0:
        if (SetUnionRoomPlayerEnterExitMovement(playerIdx, gUnknown_082F078C) == TRUE)
        {
            HideUnionRoomPlayer(playerIdx);
            (*a0)++;
        }
        break;
    case 1:
        if (sub_8019B3C(playerIdx))
        {
            RemoveUnionRoomPlayerEventObject(playerIdx);
            HideUnionRoomPlayer(playerIdx);
            *a0 = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool32 sub_8019C38(s8 * a0, u32 playerIdx, struct UnkStruct_8019BA8 * ptr)
{
    s16 x, y;

    switch (*a0)
    {
    case 0:
        if (!is_walking_or_running())
        {
            break;
        }
        PlayerGetDestCoords(&x, &y);
        if (sub_80199E0(playerIdx, 0, x, y) == 1)
        {
            break;
        }
        player_get_pos_including_state_based_drift(&x, &y);
        if (sub_80199E0(playerIdx, 0, x, y) == 1)
        {
            break;
        }
        SetUnionRoomPlayerGfx(playerIdx, ptr->field_1);
        CreateUnionRoomPlayerEventObject(playerIdx);
        ShowUnionRoomPlayer(playerIdx);
        (*a0)++;
        // fallthrough
    case 3: // incorrect?
        if (SetUnionRoomPlayerEnterExitMovement(playerIdx, gUnknown_082F078E) == 1)
        {
            (*a0)++;
        }
        break;
    case 2:
        if (sub_8019B3C(playerIdx))
        {
            *a0 = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool32 sub_8019CF0(u32 playerIdx, u32 a1, u32 a2)
{
    struct UnkStruct_8019BA8 * ptr = &gUnknown_02022C64[playerIdx];
    ptr->field_3 = 1;
    ptr->field_1 = sub_8019978(a1, a2);
    if (ptr->field_0 == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool32 sub_8019D20(u32 playerIdx)
{
    struct UnkStruct_8019BA8 * ptr = &gUnknown_02022C64[playerIdx];
    ptr->field_3 = 2;
    if (ptr->field_0 == 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sub_8019D44(u32 playerIdx, struct UnkStruct_8019BA8 * ptr)
{
    switch (ptr->field_0)
    {
    case 0:
        if (ptr->field_3 == 1)
        {
            ptr->field_0 = 2;
            ptr->field_2 = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 2:
        if (!sub_8019F8C(playerIdx, 0) && ptr->field_3 == 2)
        {
            ptr->field_0 = 0;
            ptr->field_2 = 0;
            RemoveUnionRoomPlayerEventObject(playerIdx);
            HideUnionRoomPlayer(playerIdx);
        }
        else if (sub_8019C38(&ptr->field_2, playerIdx, ptr) == 1)
        {
            ptr->field_0 = 1;
        }
        break;
    case 1:
        if (ptr->field_3 == 2)
        {
            ptr->field_0 = 3;
            ptr->field_2 = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 3:
        if (sub_8019BDC(&ptr->field_2, playerIdx, ptr) == 1)
        {
            ptr->field_0 = 0;
        }
        break;
    }
    ptr->field_3 = 0;
}

void sub_8019DD0(u8 taskId)
{
    s32 i;
    for (i = 0; i < 8; i++)
    {
        sub_8019D44(i, &gUnknown_02022C64[i]);
    }
}

u8 sub_8019DF4(void)
{
    if (FuncIsActiveTask(sub_8019DD0) == 1)
    {
        return NUM_TASKS;
    }
    else
    {
        return CreateTask(sub_8019DD0, 5);
    }
}

void sub_8019E20(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8019DD0);
    if (taskId < NUM_TASKS)
    {
        DestroyTask(taskId);
    }
}

void sub_8019E3C(void)
{
    s32 i;
    for (i = 0; i < 8; i++)
    {
        if (!IsUnionRoomPlayerHidden(i))
        {
            RemoveUnionRoomPlayerEventObject(i);
            HideUnionRoomPlayer(i);
        }
    }
    gUnknown_02022C64 = NULL;
    sub_8019E20();
}

void sub_8019E70(u8 * sp8, s32 r9)
{
    s32 r7;

    for (r7 = 0; r7 < 5; r7++)
    {
        s32 r5 = 5 * r9 + r7;
        sp8[r5] = sprite_new(0x41, r5 - 0x38, gUnknown_082F0740[r9][0] + gUnknown_082F0760[r7][0], gUnknown_082F0740[r9][1] + gUnknown_082F0760[r7][1], 3, 1);
        sub_8097C44(r5 - 0x38, TRUE);
    }
}

void sub_8019F04(u8 * r5)
{
    s32 i;
    for (i = 0; i < 40; i++)
    {
        DestroySprite(&gSprites[r5[i]]);
    }
}

void sub_8019F2C(void)
{
    s32 i, j, x, y;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sub_8019990(i, j, &x, &y);
            sub_8088B94(x, y, 0);
        }
    }
}

u8 sub_8019F64(u32 r1, u32 unused, struct UnkLinkRfuStruct_02022B14 * r2)
{
    if (r1 != 0)
    {
        return gUnknown_082F076F[r1];
    }
    else if (r2->unk_0a_0 == 0x45)
    {
        return 1;
    }
    else
    {
        return 4;
    }
}

u32 sub_8019F8C(u32 a0, u32 a1)
{
    return sub_8097C8C(5 * a0 + a1 - 0x38);
}

void sub_8019FA4(u32 r5, u32 r6, u8 r8, struct UnkLinkRfuStruct_02022B14 * r9)
{
    s32 x, y;
    s32 r7 = 5 * r5 + r6;
    if (sub_8019F8C(r5, r6) == 1)
    {
        sub_8097C44(r7 - 0x38, FALSE);
        sub_8097CC4(r7 - 0x38, 1);
    }
    sub_8097BB4(r7 - 0x38, r8);
    sub_801A3B0(r6, r5, sub_8019F64(r6, r5, r9));
    sub_8019990(r5, r6, &x, &y);
    sub_8088B94(x, y, 1);
}

void sub_801A02C(u32 a0, u32 a1)
{
    s32 x, y;
    sub_8097CC4(5 * a0 + a1 - 0x38, 2);
    sub_8019990(a0, a1, &x, &y);
    sub_8088B94(x, y, 0);
}

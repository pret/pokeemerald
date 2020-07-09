#ifndef GUARD_UNION_ROOM_PLAYER_AVATAR_H
#define GUARD_UNION_ROOM_PLAYER_AVATAR_H

u8 InitUnionRoomPlayerObjects(struct UnionRoomObject *players);
void DestroyUnionRoomPlayerObjects(void);
void CreateGroupMemberSpritesInvisible(u8 *spriteIds, s32 playerIdx);
void DestroyGroupMemberSprites(u8 *spriteIds);
void SetTilesAroundUnionRoomPlayersPassable(void);
void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
bool32 TryInteractWithUnionRoomMember(struct UnkStruct_Main0 *main0, s16 *directionPtr, s16 *playerIdxPtr, u8 *spriteIds);
void UpdateUnionRoomMemberFacing(u32 currDirection, u32 playerIdx, struct UnkStruct_Main0 *main0);

#endif //GUARD_UNION_ROOM_PLAYER_AVATAR_H

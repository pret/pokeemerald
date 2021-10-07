#ifndef GUARD_UNION_ROOM_PLAYER_AVATAR_H
#define GUARD_UNION_ROOM_PLAYER_AVATAR_H

u8 InitUnionRoomPlayerObjects(struct UnionRoomObject *players);
void DestroyUnionRoomPlayerObjects(void);
void CreateUnionRoomPlayerSprites(u8 *spriteIds, s32 leaderId);
void DestroyUnionRoomPlayerSprites(u8 *spriteIds);
void SetTilesAroundUnionRoomPlayersPassable(void);
void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
bool32 TryInteractWithUnionRoomMember(struct RfuPlayerList *list, s16 *memberIdPtr, s16 *leaderIdPtr, u8 *spriteIds);
void UpdateUnionRoomMemberFacing(u32 memberId, u32 leaderId, struct RfuPlayerList *list);

#endif //GUARD_UNION_ROOM_PLAYER_AVATAR_H

#ifndef GUARD_FOLLOW_ME_H
#define GUARD_FOLLOW_ME_H

#include "constants/follow_me.h"

#define DEFAULT_FOLLOWER_LOCAL_ID 0xFE

#define MOVEMENT_INVALID 0xFE

enum FollowerSpriteTypes
{
    FOLLOWER_SPRITE_INDEX_NORMAL,
    FOLLOWER_SPRITE_INDEX_MACH_BIKE,
    FOLLOWER_SPRITE_INDEX_ACRO_BIKE,
    FOLLOWER_SPRITE_INDEX_SURF,
    FOLLOWER_SPRITE_INDEX_UNDERWATER,
};

// Exported Functions
void SetUpFollowerSprite(u8 localId, u16 flags);
void DestroyFollower(void);
void PlayerFaceFollowerSprite(void);
void CheckPlayerHasFollower(void);
bool8 FollowerComingThroughDoor(void);

u8 GetFollowerObjectId(void);
u8 GetFollowerLocalId(void);
const u8* GetFollowerScriptPointer(void);
void HideFollower(void);
void TryFreezeFollowerAnim(struct ObjectEvent* npc);
void IsFollowerStoppingRockClimb(void);
void FollowMe_SetIndicatorToComeOutDoor(void);
void FollowMe_SetIndicatorToRecreateSurfBlob(void);
void FollowMe_TryRemoveFollowerOnWhiteOut(void);
void FollowMe(struct ObjectEvent* npc, u8 state, bool8 ignoreScriptActive);
void FollowMe_Ledges(struct ObjectEvent* npc, struct Sprite* obj, u16* ledgeFramesTbl);
bool8 FollowMe_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void FollowMe_FollowerToWater(void);
void FollowMe_BindToSurbBlobOnReloadScreen(void);
void PrepareFollowerDismountSurf(void);
void StairsMoveFollower(void);
void FollowMe_HandleBike(void);
void FollowMe_HandleSprite(void);
void FollowMe_WarpSetEnd(void);
void CreateFollowerAvatar(void);
void EscalatorMoveFollower(u8 movementType);
void EscalatorMoveFollowerFinish(void);
bool8 FollowerCanBike(void);
bool8 CheckFollowerFlag(u16 flag);
void FollowerPositionFix(u8 offset);
void SetFollowerSprite(u8 spriteIndex);
bool8 PlayerHasFollower(void);

// moved from field_screen_effect.c
void Task_DoDoorWarp(u8 taskId);
bool8 IsPlayerOnFoot(void);

#endif //GUARD_FOLLOW_ME_H 

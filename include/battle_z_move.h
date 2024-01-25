#ifndef GUARD_BATTLE_Z_MOVE_H
#define GUARD_BATTLE_Z_MOVE_H

#include "constants/z_move_effects.h"

#define MOVE_Z_STATUS   0xFFFF

struct SignatureZMove
{
    u16 species;
    u16 item;
    u16 move;
    u16 zmove;
};

bool8 IsZMove(u16 move);
void QueueZMove(u8 battler, u16 baseMove);
bool32 IsViableZMove(u8 battler, u16 move);
bool32 TryChangeZIndicator(u8 battler, u8 moveIndex);
void CreateZMoveTriggerSprite(u8, bool8);
void HideZMoveTriggerSprite(void);
bool32 IsZMoveTriggerSpriteActive(void);
void DestroyZMoveTriggerSprite(void);
bool32 MoveSelectionDisplayZMove(u16 zmove, u32 battler);
const u8 *GetZMoveName(u16 move);
void SetZEffect(void);
bool32 IsZMoveUsable(u8 battler, u16 moveIndex);
void GetUsableZMoves(u8 battler, u16 *moves);
u16 GetZMovePower(u16 move);

#endif // GUARD_BATTLE_Z_MOVE_H

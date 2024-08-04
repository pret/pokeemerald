#ifndef GUARD_BATTLE_Z_MOVE_H
#define GUARD_BATTLE_Z_MOVE_H

#include "constants/battle_z_move_effects.h"

#define MOVE_Z_STATUS   0xFFFF

struct SignatureZMove
{
    u16 species;
    u16 item;
    u16 move;
    u16 zmove;
};

bool32 IsZMove(u32 move);
bool32 CanUseZMove(u32 battler);
u32 GetUsableZMove(u32 battler, u32 move);
void ActivateZMove(u32 battler);
bool32 IsViableZMove(u32 battler, u32 move);
bool32 TryChangeZTrigger(u32 battler, u32 moveIndex);
u32 GetTypeBasedZMove(u32 move);
u32 GetSignatureZMove(u32 move, u32 species, u32 item);
bool32 MoveSelectionDisplayZMove(u16 zmove, u32 battler);
void SetZEffect(void);
void AssignUsableZMoves(u32 battler, u16 *moves);
u32 GetZMovePower(u32 move);

#endif // GUARD_BATTLE_Z_MOVE_H
